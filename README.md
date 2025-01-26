
# Push Swap

## Description
The Push Swap project is a coding challenge where the goal is to sort a list of numbers using two stacks and a limited set of operations. The program must find the shortest way to sort the numbers.

## Getting Started
### Prerequisites
To run this project, you'll need:
- C compiler (e.g., GCC or Clang)
- Make build system

### Installation
1. Clone the repository:
  ```
  git clone https://github.com/your-username/push-swap.git
  ```

2. Navigate to the project directory:
  ```
  cd push-swap
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
