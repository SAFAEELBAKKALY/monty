# 0x19. C - Stacks, Queues - LIFO, FIFO

## Resources

**Read or watch**

* [Google](https://www.google.com/search?q=stack+and+queue&sca_esv=559344913&sxsrf=AB5stBjRaFATovzpgFSO4O_o0EhT1ZzDuw%3A1692783335428&source=hp&ei=59LlZLrcF4WtkdUPyOa66AI&iflsig=AD69kcEAAAAAZOXg9xTSrIrTMds7dPDrEyEwPy1QP9iz&ved=0ahUKEwj664yrvfKAAxWFVqQEHUizDi0Q4dUDCAg&uact=5&oq=stack+and+queue&gs_lp=Egdnd3Mtd2l6Ig9zdGFjayBhbmQgcXVldWUyBxAjGIoFGCcyBRAAGIAEMgUQABiABDIFEAAYgAQyBRAAGIAEMgUQABiABDIFEAAYgAQyBRAAGIAEMgUQABiABDIFEAAYgARIoARQAFgAcAB4AJABAJgBzAGgAcwBqgEDMi0xuAEDyAEAiAYB&sclient=gws-wiz)
* [How do I use extern to share variables between source files in C?](https://intranet.alxswe.com/rltoken/0KVWTdE8xXy__jUfBfakCw)
* [Stacks and Queues in C](https://intranet.alxswe.com/rltoken/udmomL4F4mF630D2Z-ltqg)
* [Stack operations](https://intranet.alxswe.com/rltoken/fj_-SJXW-pWxgAnstsARoQ)
* [Queue operations](https://intranet.alxswe.com/rltoken/6Y_GVoIH_rV45xd7w0a9FA)

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone,
**without the help of Google**:
### General

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

## Requirements
### General

* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
* All your files should end with a new line
* A `README.md` file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the C standard library
* The prototypes of all your functions should be included in your header file called `monty.h`
* Don’t forget to push your header file
* All your header files should be include guarded
* You are expected to do the tasks in the order shown in the project

## More Info
### Data structures

Please use the following data structures for this project. Don’t forget to include them in your header file.
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
### Compilation & Output
* Your code will be compiled this way:
`$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
* Any output must be printed on `stdout`
* Any error message must be printed on `stderr`
	* [Here is a link to a GitHub repository](https://intranet.alxswe.com/rltoken/NUGvCZqs609VjEHeutkICw) that could help you making sure your errors are printed on `stderr`

### Tests

We strongly encourage you to work all together on a set of tests

### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

**Monty byte code files**

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

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
julien@ubuntu:~/monty
