# Monty Interpreter

## Introduction
Monty is a scripting language whose files are compiled into its own set of bytecodes (like Python). It relies on an unique stack, manipulated with a set of instructions given by a file containing said bytecodes. This project is an interpreter of those bytecodes.

While they usually end in ".m", it can accept any kind of file so long it can read a valid opcode.

## Properties of the Monty files
- Only one instruction (and arguments) per line. Anything else is ignored
- There can be any number of space before or after the opcode and its argument
- There can be blank lines in the file. These do nothing

## Compiling of the program
    gcc *.c -o monty
- GCC version: 4.8.4
- Made in: Ubuntu 14.06 (Trusty Thar)

### Usage
    monty file

## Available commands
- ´´´push <int>´´´: Pushes an integer to the stack
- ´´´pall´´´: Prints the contents of the stack, from top to bottom

## Author
Jaime Andrés Gálvez Villamarin (jaimeagalvezv@gmail.com)
