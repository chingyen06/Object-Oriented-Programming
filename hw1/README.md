## Assignment 1

### Due: 2025/09/29 (Mon.) 23:59

### Purpose of This Assignment

In this assignment, you should learn to complete the following things:

1. Practicing searching the information from the document on website.
2. Writing the test cases.

You have to write test cases for the member functions of std::string listed below, and you don't need to write any other code. You can refer the std::string document in cplusplus.com.

Link for the std::string document: https://cplusplus.com/reference/string/string/?kw=string

Please implement the tests for the following member functions:

1. string::length
2. string::empty
3. string::clear
4. string::insert
5. string::copy
6. string::compare
7. string::swap
8. string::find (For this function, you have to write at least two test cases for different scenarios.)

Please write all test cases in the `ut_string.cpp` file.

**Please download the files in the `sample_code` folder and follow the repository structure to put the files in your repository.**

### Repository Structure
```
.
├── .gitignore (provided by TA)
├── CMakeLists.txt (provided by TA)
└── tests
    └── ut_string.cpp
```

### Commands to Execute the Program

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./unit_tests
```

### Score

1. string::length (12%)
2. string::empty (12%)
3. string::clear (12%)
4. string::insert (12%)
5. string::copy (12%)
6. string::compare (12%)
7. string::swap (12%)
8. string::find(16%) 

- Total: 100%

### Notes

1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. The `_TA` project in Jenkins will not be used in this assignment.
