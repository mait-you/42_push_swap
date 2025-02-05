# Push Swap

## Description
Push Swap is a coding challenge that requires sorting a list of numbers using two stacks with a limited set of predefined operations. The goal is to develop an algorithm that sorts the numbers with the minimum number of operations possible.

## Operations
The project allows the following stack manipulation operations:

<div align="center">

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Swap the first two elements of both stacks simultaneously |
| `pa` | Move the top element from stack B to stack A |
| `pb` | Move the top element from stack A to stack B |
| `ra` | Rotate stack A up (first element becomes the last) |
| `rb` | Rotate stack B up (first element becomes the last) |
| `rr` | Rotate both stacks up simultaneously |
| `rra` | Rotate stack A down (last element becomes the first) |
| `rrb` | Rotate stack B down (last element becomes the first) |
| `rrr` | Rotate both stacks down simultaneously |

</div>

## Push Swap Algorithm

This project implements various sorting algorithms optimized for stack operations. The algorithm selection adapts based on the input size to ensure optimal performance and minimal operations.

### Small Sets (≤5 elements)
A specialized sorting approach is used for small sets:

1. **Five Elements (`ft_sort_five`):**
   - Identify and push the smallest number to stack B
   - Call `ft_sort_four` on remaining elements

2. **Four Elements (`ft_sort_four`):**
   - Identify and push the smallest number to stack B
   - Call `ft_sort_three` on remaining elements

3. **Three Elements (`ft_sort_three`):**
   - Handles sorting for three elements using specific rotation and swap operations
   - Moves the largest number to the bottom
   - final comparison and swap of top elements

### Medium Sets (≤10 elements)
For sets up to 10 elements:

1. **Initial Distribution:**
   - Push numbers to stack B that are not in the top 5 values of stack A

2. **Dual Stack Sorting:**
   - Sort stack A using the small set algorithm
   - Use a reverse sorting algorithm for stack B
   - Merge sorted elements back into stack A

## Performance Results

### 100 Numbers
<div align="center">  
  <img width="500" alt="Screen Shot 2025-02-01 at 3 43 48 PM" src="https://github.com/user-attachments/assets/2c2a0dcc-a6c2-46c3-9bc1-bf5991c88b9e" />
</div>

### 500 Numbers
<div align="center">
  <img width="500" alt="Screen Shot 2025-02-01 at 3 21 53 PM" src="https://github.com/user-attachments/assets/5139d561-ede7-43b6-a3a6-00c8a32a2e24" />
</div>


## Contributing
Contributions are welcome! Please feel free to submit issues or enhancement requests.
