/*
Author: Logan Kronforst
Date:   09/15/2025

Description: 

This program contains solutions to the excercise problems at the end of Chapter 7, 
Introduction to Recursion, from the textbook Programming Abtractions in C++, by
Eric S. Roberts. The solutions are entirely my own. Each problem solution comes
complete with its own unit testing suite, using the google test framework. The
google test framework is fetched through the CMakeLists.txt, and linked to the main 
executable file, so everything lives in main.cpp. This is a lean testing framework,
that doesn't use bezel. 
*/

#include <iostream>
#include <iostream>
#include <gtest/gtest.h>



/*
2.  Unlike many programming languages, C++ does not include a predifined 
    operator that raises a number to a power. As a partial remedy for this
    deficiency, write a recursive implementation of a function

                int raiseToPower(int n, int k)
   
    that calculates n^k. The recursive insight that you need to solve this problem is
    the mathematical property that 
               ___  
              | 
              |  1               if k is 0
        n^k = | 
              |  n * n ^ (k - 1) otherwise
              |___ 
*/             
int raiseToPower(int n, int k){
    if (k == 0) return 1; 
    return n * raiseToPower(n, k - 1); 
}


/*
1.  Spherical objects, such as cannonballs, can be stacked to form a pyramid with
    one cannonball at the top, sitting on top of a square composed of four 
    cannonballs, sitting on top of a square composed of nine cannonballs, and so 
    forth. Write a recursive function `cannonball` that takes as its argument the 
    height of the pyramid and returns the number of cannonballs it contains. Your
    function must operate recursively and must not use any iterative constructs,
    such as `while` or `for`. 
*/
int cannonBall(int k){
    if (k <= 1) return k; 
    return k * k + cannonBall(k - 1);
}

/* --- cannonBall Testing --- */
TEST(CannonBallTest, BaseCases) {
    EXPECT_EQ(cannonBall(0), 0);  // 0 blocks
    EXPECT_EQ(cannonBall(1), 1);  // 1 block
}

TEST(CannonBallTest, smallInputs){
    EXPECT_EQ(cannonBall(2), 5);
    EXPECT_EQ(cannonBall(3), 14);
    EXPECT_EQ(cannonBall(4), 30);
}

/* --- raiseToPower Testing --- */
TEST(raiseToPower, BaseCase){
    EXPECT_EQ(raiseToPower(1, 0), 1);
    EXPECT_EQ(raiseToPower(0, 1), 0);
}

TEST(raiseToPower, smallInputs){
    EXPECT_EQ(raiseToPower(3, 2), 9);
    EXPECT_EQ(raiseToPower(4, 2), 16);
    EXPECT_EQ(raiseToPower(10, 2), 100); 
    EXPECT_EQ(raiseToPower(8, 4), 4096);  
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}