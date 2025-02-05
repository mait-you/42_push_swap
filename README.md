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

## Algorithm Strategy
The implementation uses different approaches depending on the input size:
- For sets of ≤5 elements: Uses a specialized small-set sorting algorithm
- For sets of ≤10 elements: Employs a hybrid approach with selective pushing and reverse sorting
- For larger sets: 

## Implementation Details

### Sorting Small Sets (≤5 elements)
The algorithm employs a three-tiered approach for sorting up to 5 elements:

1. **Five Elements (`ft_sort_five`):**
   - Identifies and pushes the smallest number to stack B
   - call `ft_sort_four` on remaining elements

2. **Four Elements (`ft_sort_four`):**
   - Identifies and pushes the smallest number to stack B
   - Recursively calls `ft_sort_three` on remaining elements

3. **Three Elements (`ft_sort_three`):**
   ```c
   int ft_sort_three(t_stack *stack_a)
   {
       if (stack_a->top->num > stack_a->top->next->num
           && stack_a->top->num > stack_a->top->next->next->num)
           ft_ra(stack_a, PRINT);
       else if (stack_a->top->next->num > stack_a->top->num
           && stack_a->top->next->num > stack_a->top->next->next->num)
           ft_rra(stack_a, PRINT);
       if (stack_a->top->num > stack_a->top->next->num)
           ft_sa(stack_a, PRINT);
       return (1);
   }
   ```
   - Identifies the largest number and moves it to the bottom
   - final comparison and swap of the top two elements if needed

After sorting, the algorithm pushes back the smaller numbers from stack B to stack A in the correct order.

### Sorting Medium Sets (≤10 elements)
For sets up to 10 elements, the algorithm:

1. **Initial Distribution:**
   - Pushes numbers to stack B that are not in the top 5 values of stack A

2. **Dual Stack Sorting:**
   1. Applies [Sorting Small Sets](#sorting-small-sets-(≤5-elements)) sorting algorithm to stack A
   2. Uses a reverse sorting algorithm for stack B:

      1- **Five Elements (`ft_r_sort_five`):**
   	- Identifies and pushes the biggest number to stack B
   	- call `ft_sort_four` on remaining elements

	2. **Four Elements (`ft_r_sort_four`):**
   	- Identifies and pushes the biggest number to stack B
  	 - Recursively calls `ft_sort_three` on remaining elements

	3. **Three Elements (`ft_r_sort_three`):**
	```c
	int ft_r_sort_three(t_stack *stack_b)
	{
	if (stack_b->top->num < stack_b->top->next->num
 	     && stack_b->top->num < stack_b->top->next->next->num)
		ft_rb(stack_b, PRINT);
	else if (stack_b->top->next->num < stack_b->top->num
	     && stack_b->top->next->num < stack_b->top->next->next->num)
		ft_rrb(stack_b, PRINT);
	if (stack_b->top->num < stack_b->top->next->num)
	     ft_sb(stack_b, PRINT);
	return (1);
	}
	```
 	- Identifies the smalle number and moves it to the bottom
	- final comparison and swap of the top two elements if needed

   After sorting, the algorithm pushes back the biggest numbers from stack B to stack A in the correct order.

3. **Final Merge:**
   - Merges the sorted elements from stack B back into stack A



## Contributing
Feel free to submit issues and enhancement requests. All contributions are welcome!



