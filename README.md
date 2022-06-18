# 0x19. C - Stacks, Queues - LIFO, FIFO
**About:** In this project, we created a simple interpreter for Monty ByteCodes. The interpreter reads a bytecode file and executes the bytecode commands.
### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. 

### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument: [examples](#Examples)

## Objectives:
* To know what LIFO and FIFO mean
* To know what a stack is, and when to use it
* To know what a queue is, and when to use it
* To know the common implementations of stacks and queues
* To know the most common use cases of stacks and queues
* To know the proper way to use global variables

### Resource:
* [Difference between Stack and Queue Data Structures](https://www.geeksforgeeks.org/difference-between-stack-and-queue-data-structures/) || 

## General Requirements
* Allowed editors: **vi**, **vim**, **emacs**
* All files is compiled on **Ubuntu 20.04 LTS using gcc**, using the options **-Wall -Werror -Wextra -pedantic -std=gnu89**
* All files ends with a new line
* There is **README.md** file at the root of the **alx-low_level_programming**
* Maximum of one global variable is allowed
* No more than 5 functions per file
* The C standard library is allowed
* The prototypes of all the functions were included in the header file called monty.h
* All the header files are include guarded

## Instruction given:
* To use the following data structures for this project, and to also include them in the header file.
```
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```
```
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## List of files/Descriptions:
| S/N   |   Files      		|      Description     |
|:-----:|--------------------:|--------------------|
|  1.   |                      |              |
|  2.   |		|			|
|  3.   |		|		|
|  4.   |		|			|
|  5.   |		|		|

## Compilation & Output
* These codes were compiled using: ```gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty```
* Any output must be printed on ```stdout```
* Any error message must be printed on ```stderr```

## Examples
```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
* Some examples of using monty and its console output.

|                        Example #1                      |                    Example #2                   |                      Example #3                           |
|:-------------------------------------------------------|:------------------------------------------------|:----------------------------------------------------------|
| ~/monty$ `cat -e bytecodes/00.m` <br> push 1$ <br> push 2$ <br> push 3$ <br> pall$ <br> ~/monty$ `./monty bytecodes/00.m` <br> 3 <br> 2 <br> 1  | ~/monty$ `cat bytecodes/07.m`  <br> push 1 <br> push 2 <br> push 3 <br> pall <br> pop <br> pall <br> pop <br> pall <br> pop <br> pall <br>  ~/monty$ `./monty bytecodes/07.m`  <br> 3 <br> 2 <br> 1 <br> 2 <br> 1 <br> 1 | ~/monty$ `cat bytecodes/09.m` <br> push 1 <br> push 2 <br> push 3 <br> pall <br> swap <br> pall <br> ~/monty$ `./monty bytecodes/09.m` <br> 3 <br> 2 <br> 1 <br> 2 <br> 3 <br> 1 |

## Authors/Collaborators
[Okpara Onyedikachi](https://github.com/Dikachis/monty/) || [Duff Iniobong](https://github.com/Duffigoogle/monty/)
