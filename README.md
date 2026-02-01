# push_swap
*This project has been created as part of the 42 curriculum by ralamair.*
## Description
Push_swap is a project centered around a highly efficient sorting algorithm. The primary goal is to sort a random list of integers using two stacks (stack a and stack b) and a restricted set of stack operations. The challenge lies in performing the sort using the minimum number of operations possible. This project is written primarily in C and utilizes a Makefile for automated building.



## Instructions
### Compilation
To compile the project, navigate to the root directory and use the provided Makefile. Run the following command in your terminal:
```bash
make
```
This will compile the source files and generate the push_swap executable.
### Execution
Once compiled, you can run the program by passing a list of integers as arguments. For example:
```bash
./push_swap 4 67 3 1 15
```
The program will output the sequence of instructions (such as sa, pb, ra, etc.) required to sort the numbers.

## Resources

- https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
- https://push-swap42-visualizer.vercel.app/
-  https://www.geeksforgeeks.org/dsa/radix-sort/

### AI usage
- Algorithm Design: Researching and comparing different sorting approaches suitable for the push_swap constraints
- Eror Handling: Assistance with input validation and edge case management
- Documentation: Help structuring and explaining complex concepts clearly
- Debugging: Identifying logical errors in stack operation implementations