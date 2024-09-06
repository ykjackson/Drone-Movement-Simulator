Here we implemented a **Drone Movement Simulator** where the drone begins at the origin point **(0, 0, 0)** and executes a series of movement commands in a 3D coordinate space. The drone is controlled by a program consisting of instructions to move along the X, Y, or Z axes, either positively or negatively. Additionally, the program can have repeating subprograms wrapped in parentheses, with a multiplier preceding them.

The goal of the simulator is to:

Calculate the **final position** of the drone after executing the program.

Calculate the **total distance** traveled by the drone during execution.

## Problem Specifications:

+X, -X, +Y, -Y, +Z, -Z: These commands move the drone in the respective directions by one unit.
m(P): This command repeats the enclosed subprogram P exactly m times.

I used STACK data structure here as it's an ideal data structure for this problem due to the nested nature of the instructions. The instructions can involve subprograms wrapped inside parentheses, which resemble a recursive structure. By using a stack, we can:

**Track the coordinates** dynamically as the drone executes its moves.

**Handle nested loops** and multipliers efficiently by pushing and popping values off the stack.

**Defer execution** of nested subprograms until their respective repetitions (multipliers) are fully evaluated.

## Time Complexity:

The solution runs in **O(n)** time, where n is the length of the input string. This time complexity is achieved as follows:

**Single Pass Parsing:** The input string is processed character by character in a single pass. Each character is either a command, a digit, or part of a subprogram, all of which are processed in constant time.

**Stack Operations:** The stack operations (push and pop) for each command take constant time, i.e., O(1). Thus, we maintain linear time complexity.

**No Backtracking:** Thanks to the stack, we avoid the need for backtracking or multiple scans of the input string, ensuring that we only go through the string once.
