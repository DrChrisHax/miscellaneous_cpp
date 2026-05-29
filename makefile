# ----- Project -----
TARGET := app
TEST_TARGET := test_runner
CXX := g++
#CXX := clang++
WARN := -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion #-Werror
STD := -std=c++26
DEP := -MMD -MP
INCLUDES := -Iapp -Itests -Icore -ICore/os -Icore/os/$(PLATFORM) -Icore/templates

# ----- File Extensions -----
CXX_EXT := cpp

# ----- makefile Config -----
MAKEFLAGS += --no-print-directory

# ----- Platform -----
UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	PLATFORM := windows
else ifeq ($(UNAME_S),Linux)
	PLATFORM := linux
else ifeq ($(UNAME_S),Darwin)
	PLATFORM := macos
else
	$(error Unsupported OS: $(UNAME_S))
endif

# ----- Build Mode (debug | release) -----
BUILD ?= debug
ifeq ($(BUILD),release)
    OPT    := -O2
    DEFS   := -DNDEBUG
    BUILD_SUFFIX := release
else
    OPT    := -O0 -g
    DEFS   :=
    BUILD_SUFFIX := debug
endif

# ----- Directories -----
OBJDIR := obj/$(BUILD_SUFFIX)
BINDIR := bin/$(BUILD_SUFFIX)
TESTDIR := tests
TEST_OBJDIR := $(TESTDIR)/obj/$(BUILD_SUFFIX)
TEST_BINDIR := $(TESTDIR)/bin/$(BUILD_SUFFIX)

# ----- Source & Dependencies -----
CORE_SRCS := $(wildcard core/*.$(CXX_EXT)) $(wildcard core/os/$(PLATFORM)/*.$(CXX_EXT)) 
APP_SRCS := $(wildcard app/*.$(CXX_EXT))
TEST_SRCS := $(wildcard $(TESTDIR)/*.$(CXX_EXT))

CORE_OBJS := $(patsubst %.$(CXX_EXT),$(OBJDIR)/%.o,$(CORE_SRCS))
APP_OBJS := $(patsubst %.$(CXX_EXT),$(OBJDIR)/%.o,$(APP_SRCS))
TEST_OBJS := $(patsubst $(TESTDIR)/%.$(CXX_EXT),$(TEST_OBJDIR)/%.o,$(TEST_SRCS))

CORE_DEPS := $(CORE_OBJS:.o=.d) 
APP_DEPS := $(APP_OBJS:.o=.d)
TEST_DEPS := $(TEST_OBJS:.o=.d)

# ----- Flags -----
CXXFLAGS := $(STD) $(WARN) $(OPT) $(DEP) $(INCLUDES)
LDFLAGS := 

# ----- Object Rules -----
$(OBJDIR)/%.o: %.$(CXX_EXT)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
$(TEST_OBJDIR)/%.o: $(TESTDIR)/%.$(CXX_EXT)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# ----- Link Rules -----
$(BINDIR)/$(TARGET): $(APP_OBJS) $(CORE_OBJS)
	@mkdir -p $(BINDIR)
	@$(CXX) $(APP_OBJS) $(CORE_OBJS) -o $@ $(LDFLAGS)
$(TEST_BINDIR)/$(TEST_TARGET): $(TEST_OBJS) $(CORE_OBJS)
	@mkdir -p $(TEST_BINDIR)
	@$(CXX) $(TEST_OBJS) $(CORE_OBJS) -o $@ $(LDFLAGS)

# ----- Commands -----
.PHONY: all core app release run test build-tests clean clean-test clean-all help

all:
	@$(MAKE) app

core: $(CORE_OBJS)
	@echo "[makefile] Core up to date (platform=$(PLATFORM))"

app: $(BINDIR)/$(TARGET)
	@echo "[makefile] app up to date"

release:
	@$(MAKE) BUILD=release app

run:
	@$(MAKE) app
	@echo "[makefile] Running ./$(BINDIR)/$(TARGET)"
	@./$(BINDIR)/$(TARGET)

test: $(TEST_BINDIR)/$(TEST_TARGET)
	@echo "[makefile] Running tests..."
	@./$(TEST_BINDIR)/$(TEST_TARGET)

build-tests: $(TEST_BINDIR)/$(TEST_TARGET)
	@echo "[makefile] Tests built successfully -> $(TEST_BINDIR)/$(TEST_TARGET)"

clean:
	@echo "[makefile] Removing obj/ and bin/"
	@rm -rf $(OBJDIR) $(BINDIR)
	
clean-test:
	@echo "[makefile] Removing tests/obj/ and tests/bin/"
	@rm -rf $(TEST_OBJDIR) $(TEST_BINDIR)

clean-all:
	@$(MAKE) clean
	@$(MAKE) clean-test
	@echo "[makefile] Removing log files"
	@rm -f *.log

help:
	@echo "Usage: make <target> [BUILD=debug|release]"
	@echo
	@echo "Targets:"
	@echo "  app           Build app (debug by default)    -> bin/debug/app"
	@echo "  release       Build app in release mode       -> bin/release/app"
	@echo "  run           Build (debug) and run           -> bin/debug/app"
	@echo "  core          Build core objects only"
	@echo "  build-tests   Build test runner (no run)      -> tests/bin/<mode>/test_runner"
	@echo "  test          Build and run tests"
	@echo "  clean         Remove obj/ and bin/"
	@echo "  clean-test    Remove tests/obj/ and tests/bin/"
	@echo "  clean-all     Remove all build artifacts and .log files"
	@echo "  help          Show this dialog"
	@echo
	@echo "Examples:"
	@echo "  make run                   # debug build + run"
	@echo "  make release               # optimized release build"
	@echo "  make test BUILD=release    # run tests in release mode"

# ----- Include dependencies if present -----
-include $(CORE_DEPS) $(APP_DEPS) $(TEST_DEPS)