# NQueens

Vince Moreno, 5 May 2024



Description
The NQueens folder contains the implementation of the NQueens problem
and an executable "nqueens" to run it. The subfolder "Helper" contains a
java helper file "PrintSolutionHelper" to show a board for a given set of 
solutions. The Tests folder contains input and output files to test the 
code on. NQueens.cpp has no recursion and functions strictly on a stack 
based solution.



Files
Code Files: Makefile, NQueens.cpp
Input/Output Files: simple-input.txt, simple-output.txt
Extra files: README

The folder Helper contains PrintSolutionHelper.java

The Tests folder contains input and output .txt files.
Input Files: more-input.txt, simple-input.txt, test-5-input.txt
Output Files: more-output.txt, simple-output.txt, test-5-output.txt



Usage
In main folder:
  1. Run "make", to get executable "nqueens"
  2. Run "./nqueens <INPUT FILE> <OUTPUT FILE>"

In Helper folder:
  1. Run "javac PrintSolutionHelper.java", to get executable "PrintSolutionHelper"
  2. Run "./PrintSolutionHelper <INPUT FILE>"

Run nqueens to get a solution and use that solution as the input for
PrintSolutionHelper.



Input/Output

The input file should have a list of numbers in each line of the form:
<size of board n> <A list of queen positions in the order " <column> <row> ">

The solution is printed to the <OUTPUT FILE> provided as an argument



NQueens.cpp
The way NQueens finds a solution for arguments given in the input file is by
finding all possible solutions for the given board of length n, and finding a 
solution that contains the starting queen positions given by the input file. 

The solutions is found through backtracking. This is usually done through recursion
but in this program, it is done by keeping a stack of the board states every time
it checks for a possible solution. If there is no solution for the current board,
it is discarded and the algorithm attempts to find a new solution for the previous 
board state. If the stack contains n board states, that means the whole baord has 
been filled with queens that do not attack each other and it is appended to a list
of boards that are possible solutions to the given case.

After finding all solutions, the program then looks through the solutions to find one
that contains the starting queen positions given as an argument in the input file.
If no solution containing the queen positions exist, the answer printed to the output file
for that specific case is "No solution". Otherwise if there is a solution, it will print
a list of numbers of the form "<column> <row> " to the output file.
