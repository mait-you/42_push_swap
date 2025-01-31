
# Push Swap

## Description
The Push Swap project is a coding challenge where the goal is to sort a list of numbers using two stacks and a limited set of operations. The program must find the shortest way to sort the numbers.

### Installation
1. Clone the repository:
  ```
  git clone https://github.com/mait-you/push_swap.git
  ```

2. Navigate to the project directory:
  ```
  cd push_swap
  ```

3. Compile the program:
  ```
  make
  ```

### Usage
To run the program, use the following command:
```
./push_swap [numbers]
```
Replace `[numbers]` with a list of integers you want to sort, e.g., `./push_swap 3 1 2 4 5`.

The program will output a series of instructions to sort the numbers using the available operations.

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

# Push_Swap Algorithm

## Overview of Sorting Approach
The implementation uses different sorting strategies based on the input size, with specialized functions for handling 3, 4, 5, and up to 10 numbers. The main sorting functions are organized as follows:

### Core Sorting Functions
```c
// Forward sorting (Stack A to B)
ft_sort_three()      // Handles 3 numbers
ft_sort_four()       // Handles 4 numbers
ft_sort_five()       // Handles 5 numbers
sort_five_or_less()  // Generic handler for ≤5 numbers

// Reverse sorting (Stack B to A)
ft_r_sort_three()    // Reverse sorts 3 numbers
ft_r_sort_four()     // Reverse sorts 4 numbers
ft_r_sort_five()     // Reverse sorts 5 numbers
r_sort_five_or_less()// Generic reverse handler for ≤5 numbers

// Special case handler
sort_ten()           // Handles up to 10 numbers
```

## Sort Ten Algorithm Breakdown
The `sort_ten()` function implements a hybrid approach:


<details>
    <summary>
        <p></p>
    </summary>
    ```c
    int	sort_ten(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 5)
	{
		ft_memset(stack_a->top_five, 0, sizeof(t_top_five));
		ft_get_top_5_nod(stack_a);
		if (!ft_is_top_5(stack_a, stack_a->top))
			ft_pb(stack_a, stack_b, PRINT);
		else
			ft_ra(stack_a, PRINT);
	}
	sort_five_or_less(stack_a, stack_b);
	r_sort_five_or_less(stack_b, stack_a);
	while (stack_b->size > 0)
		ft_pa(stack_b, stack_a, PRINT);
	return (0);
}
    ```
</details>



1. **we get the middle node** :
  - i mean if we have like {2, 6, 7, 1, 9, 4, 3} we should get '4' why ? 4, becouse if we sort {2, 6, 7, 1, 9, 4, 3} we get {1, 2, 3, 4, 6, 7, 9} and '4' is middle, and actual we don't sort the list to get middle node, we use a differnt algo
<div align="center">
  <img width="1533" alt="Screen Shot 2025-01-31 at 10 35 32 AM" src="https://github.com/user-attachments/assets/d2e36e49-58a5-4933-8498-4001a62d28f6" />
</div>
  - but actual we take onle the middle node that is top or done of 25% of stack a

  
<img width"856" alt="Screen Shot 2025-01-31 at 10 05 02 AM" src="https://github.com/user-attachments/assets/4545107a-cf5e-4fd5-8530-8fabfd6e5284" />

