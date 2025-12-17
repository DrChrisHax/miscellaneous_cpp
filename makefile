# ----- Project -----
TARGET := app
TEST_TARGET := test_runner
CXX := g++
WARN := -Wall -Wextra -Werror
STD := -std=c++23
OPT := -O2
DEP := -MMD -MP
INCLUDES := -Iapp -Itests -Icore -Icore/os/$(PLATFORM) -Icore/templates

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

# ----- Directories -----
OBJDIR := obj
BINDIR := bin
TESTDIR := tests
TEST_OBJDIR := $(TESTDIR)/obj
TEST_BINDIR := $(TESTDIR)/bin

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

# ----- Object Directory -----
$(OBJDIR)/%.o: %.$(CXX_EXT)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# ----- Test Object Directory -----
$(TEST_OBJDIR)/%.o: $(TESTDIR)/%.$(CXX_EXT)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# ----- Executable Directory -----
$(BINDIR)/$(TARGET): $(APP_OBJS) $(CORE_OBJS)
	@mkdir -p $(BINDIR)
	@$(CXX) $(APP_OBJS) $(CORE_OBJS) -o $@ $(LDFLAGS)

# ----- Test Executable -----
$(TEST_BINDIR)/$(TEST_TARGET): $(TEST_OBJS) $(CORE_OBJS)
	@mkdir -p $(TEST_BINDIR)
	@$(CXX) $(TEST_OBJS) $(CORE_OBJS) -o $@ $(LDFLAGS)

# ----- Commands -----
.PHONY: all core app test build-tests clean clean-test clean-all run help

all:
	@$(MAKE) app

core: $(CORE_OBJS)
	@echo "[makefile] Core up to date (platform=$(PLATFORM))"

app: $(BINDIR)/$(TARGET)
	@echo "[makefile] app up to date"

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

test: $(TEST_BINDIR)/$(TEST_TARGET)
	@echo "[makefile] Running tests..."
	@./$(TEST_BINDIR)/$(TEST_TARGET)

build-tests: $(TEST_BINDIR)/$(TEST_TARGET)
	@echo "[makefile] Tests built successfully -> $(TEST_BINDIR)/$(TEST_TARGET)"

run:
	@$(MAKE) core
	@$(MAKE) app
	@echo "[makefile] Running ./$(BINDIR)/$(TARGET)"
	./$(BINDIR)/$(TARGET)

help:
	@echo "Usage: make <target>"
	@echo
	@echo "Targets:"
	@echo "  core        Build core objects incrementally (platform=$(PLATFORM))"
	@echo "  app         Build and link the app binary -> $(BINDIR)/$(TARGET)"
	@echo "  build-tests Build test executable without running -> $(TEST_BINDIR)/$(TEST_TARGET)"
	@echo "  test        Build and run all tests -> $(TEST_BINDIR)/$(TEST_TARGET)"
	@echo "  run         Build (incremental) and run ./$(BINDIR)/$(TARGET)"
	@echo "  clean       Remove $(OBJDIR) and $(BINDIR)"
	@echo "  clean-test  Remove $(TEST_OBJDIR) and $(TEST_BINDIR)"
	@echo "  clean-all   Remove $(OBJDIR), $(BINDIR), $(TEST_OBJDIR), $(TEST_BINDIR) and .log files"
	@echo "  help        Show this dialog"

# ----- Include dependencies if present -----
-include $(CORE_DEPS) $(APP_DEPS) $(TEST_DEPS)