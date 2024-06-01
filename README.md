# Biggest Square In Map

The objective of this project is to find the largest possible square on a board while avoiding obstacles. The program allows two methods of obtaining the board: reading from a file or generating one based on given parameters.

## File Input Constraints

- The file must be passed as an argument to the program.
- The file must adhere to the following constraints:
- The first line contains the number of lines on the board.
- Only '.' (representing an empty place) and 'o' (representing an obstacle) characters are allowed.
- All lines (except the first one) must be of the same length.
- The file must contain at least one line.
- Each line is terminated by '\n'.

## Output

The program prints the board, with some '.' replaced by 'x' to represent the largest square found. If there are multiple solutions, it chooses the highest square. If there are still multiple solutions, it chooses the square to the left.

## How to run

### Classic Execution (Using File Input)

```
$ make
$ ./setting_up example_file | cat -e
.....xxxxxxx................$
....oxxxxxxx................$
.....xxxxxxxo...............$
.....xxxxxxx................$
....oxxxxxxx................$
.....xxxxxxx...o............$
.....xxxxxxx................$
......o...............o.....$
..o.......o.................$
```
### Generating Your Own Board

Alternatively, the program can generate a board based on given parameters:
- Width and height of the board.
- A pattern that will be repeated line by line along the board.
```
$ make
$ ./setting_up 6 "..o.." | cat -e
..oxx.$
.o.xx.$
o....o$
....o.$
...o..$
..o...$
```

## Grade

I received a score of 100% on this project.

## Authors
Thank you for checking out this project! If you have any questions or would like to collaborate, feel free to contact me.

[Nicolas Dumetz](mailto:nicolasdumetzpro@gmail.com)
