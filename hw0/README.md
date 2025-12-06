# OOP

#### Fall, 2025

#### Prof Y C Cheng

#### Dept of Computer Science and Information Engineering

#### Taipei Tech

### Important Links

* [Gitlab](http://140.124.181.100): http://140.124.181.100

* [Jenkins](http://140.124.181.97:8080): http://140.124.181.97:8080

## Assignment 0

### Due: 2025/09/19 23:59

### Purpose of this assignment

In this assignment, you should complete the development environment setting and setup GitLab project for hand in the assignment. In addition, you need to complete and hand in a helloworld project to make sure your setting is completed.

### Environment and repository setup

**Follow the following steps to setup your environment**

- [Environment Setup](./setup_tutorial/computer_environment_setting.md)
- [GitLab Setup](./setup_tutorial/gitlab_setup.md)
- [Steps for hand in assignments](./setup_tutorial/hand_in_assignment_steps.md)
- [Jenkins setup](./setup_tutorial/jenkins_setup.md)

### Upload same code to your assignment

In this assignment, you need to download the [sample code](./sample_code/) and copy all the contents to your own repository. There is a function `std::string sayHello(std::string)`in **src/hello.h** file. 

- Check with the sample code:
  
  - Generate makefiles with cmake:
    ```shell
    $ mkdir build
    $ cd build
    $ cmake ..
    ```

    Output:
    ```
    -- The CXX compiler identification is AppleClang 14.0.0.14000029
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Check for working CXX compiler: /usr/bin/c++ - skipped
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- The C compiler identification is AppleClang 14.0.0.14000029
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Check for working C compiler: /usr/bin/cc - skipped
    -- Detecting C compile features
    -- Detecting C compile features - done
    -- Performing Test CMAKE_HAVE_LIBC_PTHREAD
    -- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
    -- Found Threads: TRUE
    -- Configuring done (20.5s)
    -- Generating done (0.1s)
    -- Build files have been written to: <path/to/your/directory>/sample_code/build
    ```

  - Compile:
    ```
    $ make
    ```

    Output:
    ```
    [  7%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
    [ 14%] Linking CXX static library ../../../lib/libgtest.a
    [ 14%] Built target gtest
    [ 21%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
    [ 28%] Linking CXX static library ../../../lib/libgmock.a
    [ 28%] Built target gmock
    [ 35%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
    [ 42%] Linking CXX static library ../../../lib/libgmock_main.a
    [ 42%] Built target gmock_main
    [ 50%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
    [ 57%] Linking CXX static library ../../../lib/libgtest_main.a
    [ 57%] Built target gtest_main
    [ 64%] Building CXX object src/CMakeFiles/sample_lib.dir/hello.cpp.o
    [ 71%] Linking CXX static library libsample_lib.a
    [ 71%] Built target sample_lib
    [ 78%] Building CXX object src/CMakeFiles/main.dir/main.cpp.o
    [ 85%] Linking CXX executable main
    [ 85%] Built target main
    [ 92%] Building CXX object test/CMakeFiles/unit_tests.dir/ut_main.cpp.o
    [100%] Linking CXX executable unit_tests
    [100%] Built target unit_tests
    ```


  - Execute the programs:
    ```
    $ ./src/main
    ```

    Output:
    ```
    hello, world
    ```

  - Execute the unit tests:
    ```
    $ ./test/unit_tests
    ```

    Output:
    ```
    [==========] Running 1 test from 1 test suite.
    [----------] Global test environment set-up.
    [----------] 1 test from HelloTest
    [ RUN      ] HelloTest.SayHello
    [       OK ] HelloTest.SayHello (0 ms)
    [----------] 1 test from HelloTest (0 ms total)

    [----------] Global test environment tear-down
    [==========] 1 test from 1 test suite ran. (0 ms total)
    [  PASSED  ] 1 test.
    ```


### Structure
```
.
├── CMakeLists.txt
├── src
│   ├── CMakeLists.txt
│   ├── hello.h
│   └── main.cpp
└── test
    ├── CMakeLists.txt
    ├── ut_hello.h
    └── ut_main.cpp
```

**score:**
- Upload sample code successfully & Jenkins run successfully (100%)

***Note:***
- This repository will be used for this homework.
