#include "gtest/gtest.h"
#include "../include/factorial.h"

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

int main(int argc, char **argv) {
  /* Parses the command line for googletest flags, and removes all recognized flags.
   * You must call this function before calling RUN_ALL_TESTS(), or the flags won't be properly
   * initialized.*/
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}