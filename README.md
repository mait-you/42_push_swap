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
for '<= 5' size: i use 3 functions
- **in *ft_sort_five* function**: i searched for the smalle number in stack a and i pushed to stack b, then i call *ft_sort_four*.
- **in *ft_sort_four* function**: i searched for the smalle number in stack a and i pushed to stack b, then i call *ft_sort_three*.
- **in *ft_sort_three* function**: i use same conditions to searched about the biggest number and move it to bottom, then i check the top two.
```c
int	ft_sort_three(t_stack *stack_a)
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
and in end i push back the tow smalles number to stack a.

## Sorting Ten

i push to stack b only the numbers the is not top five numbers in stack a, then i use **Sorting Five algorithm** to sort the nembers of stack a and **Reverse Sorting Five algorithm** to sort  the numbers of stack b in reverse.
- **in *ft_r_sort_five* function**: i searched for the biggest number in stack a and i pushed to stack b, then i call *ft_r_sort_four*.
- **in *ft_r_sort_four* function**: i searched for the biggest number in stack a and i pushed to stack b, then i call *ft_r_sort_three*.
- **in *ft_r_sort_three* function**: i use same conditions to searched about the smalle number and move it to bottom, then i check the top two.
```c
int	ft_r_sort_three(t_stack *stack_b)
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
and in end i push back the numbers of stack b number to stack a.

