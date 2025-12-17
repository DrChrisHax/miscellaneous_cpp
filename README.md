# C++ Project Template

## Overview

This is a simple C++23 project template. It uses a Makefile to compile and clean up objects & binaries. The project is strucutred to follow the app/core framework. Application specific code goes in the app directory, reusable or general code goes in the core directory, and any platform-spcific code goes in core/os/<platform>. A simple test suite is also included so that test cases for different code modules can be easily written and executed. 

## Getting Started
### Prerequisites
- C++23 compatible compiler
- Make

### Building the project
```
make 
make run # Builds and runs the app
make help # Outputs all available make commands in the makefile
```


## Tests
### Writing Tests
1. Create a cpp file for the module you want to test in tests/
2. Add your test code to the newly created file
3. Declare the function in tests/tests.h
4. Add Run(TestFunction); in tests/test_runner.cpp

See the sample tests included for reference.

### Running Tests
```
make test # Build and run all tests
make build-test # Build the tests without running them
```

## Authors
 - Chris Manlove


