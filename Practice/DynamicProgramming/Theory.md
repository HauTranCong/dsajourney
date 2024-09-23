# Dynamoc Programming
Dynamic Programming (DP) is an optimization technique used in computer science and mathematics
to solve complex problems by breaking them down into simpler overlapping subproblems. 
The key idea is to store the results of these subproblems to avoid redundant computations, 
thus significantly improving efficiency.

## Key Concepts in Dynamic Programming
1. Optimal Substructure: 
A problem exhibits optimal substructure if an optimal solution to the problem 
can be composed of optimal solutions to its subproblems. 
This means that solving the larger problem involves 
solving multiple smaller instances of the same problem.

2. Overlapping Subproblems: 
In contrast to divide-and-conquer strategies, where subproblems are independent, 
dynamic programming involves problems that recur multiple times. 
By solving and storing the results of these recurring subproblems, DP avoids redundant calculations.

3. Memoization: 
This technique involves storing the results of expensive function calls and 
reusing them when the same inputs occur again. This top-down approach starts with the main problem 
and recursively solves each subproblem, storing results along the way.

4. Tabulation: The bottom-up approach to DP involves solving all possible subproblems first and
then combining them to solve the overall problem. This typically uses a table (often an array) to store
the solutions to subproblems, building up solutions iteratively.

## Steps to Solve a Problem Using DP
1. Define the Subproblems: Identify the smaller subproblems that make up the main problem.
2. Recurrence Relation: Establish a relationship between the larger problem and its subproblems.
3. Memoization or Tabulation: Decide whether to solve the problem using a top-down (memoization)
or bottom-up (tabulation) approach.
4. Initialization: For tabulation, initialize the base case in the table.
5. Solve Iteratively: Fill in the table or recursively solve the subproblems.