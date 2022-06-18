##MONTY

## Description

It is a interpreter for Monty ByteCodes files.

***

## Usage

1. Clone the repository:
```console
https://github.com/Aishatt/monty.git
```

2. Enter at directory
```console
cd monty
```

3. Compile:
```console
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

4. Execute:
```console
./monty file.m
//The file contains the bytcode instructions for example
cat -e 000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```

## Functions

The functions used are:

|Name | Description | Return| File
|:--: | :-- | :--| :--|
|_f_add | adds the top two elements of the stack | No Return | add.c|
| addnode | add node to the head stack | No Return | addnode.c|
| f_div | divides the top two elements of the stack. | No Return | div.c|
| execute | executes the opcode | No Return | execute.c|
| free_stack | frees a doubly linked list | No Return | free_stack.c|
| main | monty code interpreter | 0 on success | main.c| 

### Authors
Adebayo Aishat
