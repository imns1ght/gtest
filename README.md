# GTest Example

## Introduction

An example of using [GTest](https://github.com/google/googletest) with a simple factorial function. 

Initially, it was just my notes.

## Compiling

Assuming you have installed [CMake](https://cmake.org), [GTest](https://github.com/google/googletest) and Git, we can follow these steps:

1. Download the project and moves into the root directory
    ```
    git clone https://github.com/imns1ght/gtest && cd gtest/
    ``` 

2. Create a new directory in which the compilation output will be stored (including the executable).
    ```
    mkdir build
    ``` 

3. Moves into the directory created in the step above.
    ```
    cd build
    ```

4. Create the Makefile based on the script found in `CMakeLists.txt`, one level up.
    ```
    cmake -G "Unix Makefiles" .. .
    ```

5. Start the compiling process
    ```
    cmake --build .
    ```

6. Copies the library to the `lib` directory.
    ```
    make install
    ```  

7. Create a symlink (shortcut) from the `run_tests`. Anyway, it's optional.
    ```
    cd .. && ln -sf build/run_tests .
    ```

Finally, we have an executable inside the `build` directory that tests the library functions.
Also, we will have a library `libgtest.a` in which the functions are compiled.

## Usage

Just run as usual (assuming `$` is the terminal prompt):

```
./run_tests
```

# Creating tests

This section is basically "copy and paste" from this [doc](https://github.com/google/googletest/blob/master/googletest/docs/primer.md).

## Basic Concepts 

* ASSERT_*: generate fatal failures when they fail, and abort the current function. 
* EXPECT_*: generate nonfatal failures, which don't abort the current function.

### Basic Assertions

These assertions do basic true/false condition testing.

Fatal assertion            | Nonfatal assertion         | Verifies
-------------------------- | -------------------------- | --------------------
`ASSERT_TRUE(condition);`  | `EXPECT_TRUE(condition);`  | `condition` is true
`ASSERT_FALSE(condition);` | `EXPECT_FALSE(condition);` | `condition` is false

### Binary Comparison

This section describes assertions that compare two values.

Fatal assertion          | Nonfatal assertion       | Verifies
------------------------ | ------------------------ | --------------
`ASSERT_EQ(val1, val2);` | `EXPECT_EQ(val1, val2);` | `val1 == val2`
`ASSERT_NE(val1, val2);` | `EXPECT_NE(val1, val2);` | `val1 != val2`
`ASSERT_LT(val1, val2);` | `EXPECT_LT(val1, val2);` | `val1 < val2`
`ASSERT_LE(val1, val2);` | `EXPECT_LE(val1, val2);` | `val1 <= val2`
`ASSERT_GT(val1, val2);` | `EXPECT_GT(val1, val2);` | `val1 > val2`
`ASSERT_GE(val1, val2);` | `EXPECT_GE(val1, val2);` | `val1 >= val2`

### String Comparison

The assertions in this group compare two **C strings**. If you want to compare
two `string` objects, use `EXPECT_EQ`, `EXPECT_NE`, and etc instead.

| Fatal assertion                 | Nonfatal assertion              | Verifies                                                 |
| ------------------------------- | ------------------------------- | -------------------------------------------------------- |
| `ASSERT_STREQ(str1, str2);`     | `EXPECT_STREQ(str1, str2);`     | the two C strings have the same content                  |
| `ASSERT_STRNE(str1, str2);`     | `EXPECT_STRNE(str1, str2);`     | the two C strings have different contents                |
| `ASSERT_STRCASEEQ(str1, str2);` | `EXPECT_STRCASEEQ(str1, str2);` | the two C strings have the same content, ignoring case   |
| `ASSERT_STRCASENE(str1, str2);` | `EXPECT_STRCASENE(str1, str2);` | the two C strings have different contents, ignoring case |

### Basic structure of TEST()

1.  Use the `TEST()` macro to define and name a test function, These are
    ordinary C++ functions that don't return a value.
1.  In this function, along with any valid C++ statements you want to include,
    use the various googletest assertions to check values.
1.  The test's result is determined by the assertions; if any assertion in the
    test fails (either fatally or non-fatally), or if the test crashes, the
    entire test fails. Otherwise, it succeeds.

```c++
TEST(TestSuiteName, TestName) {
  ... test body ...
}
```

* The *first* argument is the name of the test case
* The *second* argument is the test's name within the test case. 
* Both names must be valid C++ identifiers, and they should not contain underscore (`_`). 

## Example

#### Function we want to test

```c++
int Factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; ++i) {
                result *= i;
        }

        return result;
}
```

#### Test case

```c++
// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(Factorial(0), 1);
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(Factorial(1), 1);
  EXPECT_EQ(Factorial(2), 2);
  EXPECT_EQ(Factorial(3), 6);
  EXPECT_EQ(Factorial(8), 40320);
}
```

#### Call tests
```c++
#include "../include/<files>"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
  /* Parses the command line for googletest flags, and removes all recognized flags.
   * You must call this function before calling RUN_ALL_TESTS(), or the flags won't be properly
   * initialized.*/
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
```

## References and Acknowledgment
* https://github.com/google/googletest
* https://github.com/google/googletest/blob/master/googletest/docs/primer.md
* [Professor Selan R. dos Santos](https://www.dimap.ufrn.br/~selan/)
