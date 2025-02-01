
# Push Swap

## Description
The Push Swap project is a coding challenge where the goal is to sort a list of numbers using two stacks and a limited set of operations. The program must find the shortest way to sort the numbers.

## Operations
The available operations for this project are:
- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `ss`: `sa` and `sb` at the same time.
- `pa`: Take the first element from stack B and move it to the top of stack A.
- `pb`: Take the first element from stack A and move it to the top of stack B.
- `ra`: Rotate stack A up. The first element becomes the last one.
- `rb`: Rotate stack B up. The first element becomes the last one.
- `rr`: `ra` and `rb` at the same time.
- `rra`: Rotate stack A down. The last element becomes the first one.
- `rrb`: Rotate stack B down. The last element becomes the first one.
- `rrr`: `rra` and `rrb` at the same time.

# Performance
- I use my own tester :
- 

# Push_Swap Algorithm

## Overview of Sorting Approach
The implementation uses different sorting strategies based on the input size, with specialized functions for handling 3, 4, 5, and up to 10 numbers. 


