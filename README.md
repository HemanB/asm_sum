# Facile Assembly: Sum

## Objectives

- Write some assembly code.
- Take a closer look at how facileASM programs are composed and executed. 

## Overview

In this lab, you will work with the facileASM assembly language once more.   The assignment is to write a simple facileASM program named `sum.fac` from scratch using a text editor.   You do not need to modify any other source files.

The `sum.fac` program does some simple arithmetic: it sums batches of numbers on the input, and outputs the sum for each batch.   

Section 3 of the facile document describes the facileASM instructions.   The other `.fac` files in the lab directory provide some examples to look at.
You should review the README for the `disassembler` lab, which covers how to build facile and view and run facileASM programs.    

## Instructions

Your program processes non-negative integers on the input in order and sums them, until it sees a 0. If the input is exhausted, the program should write the sum to return value and halt, otherwise, the program resets the sum to 0 and continue processing the next batch of integers.

To expand on that, the input to your `sum.fac` program is a sequence of batches of integers.   Each batch is a sequence of integers in consecutive locations of the `input` segment.   The value 0 indicates the end of a batch.   The program loads values from the input segment in sequence starting at offset 0.   When it encounters a 0 terminator value, it outputs the sum of the integers in the current batch.   It then continues with the next batch, if any.    There may be any number of batches, each terminated by 0.

The output is a sequence of sums, one for each input batch.   Output a batch sum by storing the sum value to the next unused location of the `output` segment.   Note that the output index corresponds to the batch number.  

For example, if the input is:

```
1
2
3
0
2
3
4
0
```

The program should output the sum 6 in `output[0]` and 9 in `output[1]`.

To run it, build facile and use the `-x` option, as described in the README for the disassembler lab.   Build facile by running: 
    
```bash 
make
```

It builds a single executable binary program, called facile.   You can run it by typing `./facile` to your command shell.

```
./facile
Usage: ./facile [-x or -d] <program file> (provide input on stdin)
```

You use the `-x` (execute) option to run facile programs.

```
./facile -x sum.fac
Don't leave me hanging!  Type inputs and then ctrl-d.
```

You can type the inputs by hand, or you can take the inputs from a file as described in the README for disassebler.

### Testing and Submission

You know the drill!   Fork, clone, test, add, commit, push, and submit as for previous labs.

See the disassembler README for details.   Please push and submit only `sum.fac` and `statement.txt`.
