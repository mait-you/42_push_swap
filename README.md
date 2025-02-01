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

## Sorting Strategies

### Three Elements Sort
For exactly three elements, we use a conditional-based approach that guarantees sorting in at most two operations.

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

#### How It Works

The algorithm follows a two-step approach:

1. **Position the Largest Number**
   - If the largest number is at the top: Rotate down (`ra`)
   - If the largest number is in the middle: Reverse rotate (`rra`)
   - If the largest number is at the bottom: Do nothing

2. **Fix Remaining Pair**
   - After positioning the largest number, check if the remaining two numbers need swapping
   - If top number is greater than the one below it: Swap (`sa`)

#### Operation Breakdown

The algorithm uses these stack operations:
- `ra`: Rotate stack A up (first element becomes last)
- `rra`: Rotate stack A down (last element becomes first)
- `sa`: Swap the first two elements of stack A

#### Performance

- **Maximum Operations**: 2
- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

#### Example Cases

Given initial stack state → Final state (operations used):
1. `[3,2,1]` → `[1,2,3]` (`ra`, `sa`)
2. `[2,3,1]` → `[1,2,3]` (`rra`)
3. `[2,1,3]` → `[1,2,3]` (`sa`)

## Contributing
Feel free to submit issues and enhancement requests!

