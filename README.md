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
I use my own tester :
1. for 100 number:
<div align="center">  
  <img width="704" alt="Screen Shot 2025-02-01 at 3 43 48 PM" src="https://github.com/user-attachments/assets/2c2a0dcc-a6c2-46c3-9bc1-bf5991c88b9e" />
</div>

3. for 500 number:
<div align="center">
  <img width="707" alt="Screen Shot 2025-02-01 at 3 21 53 PM" src="https://github.com/user-attachments/assets/5139d561-ede7-43b6-a3a6-00c8a32a2e24" />
</div>

# Push_Swap Algorithm

## Overview
This project implements various sorting algorithms optimized for stack operations. The algorithm selection adapts based on the input size to ensure optimal performance and minimal operations.

## Sorting Five

if size of stack a is '<= 5':
- I searched for the smalle number in stack a and i pushed to stack b 
