/* fiber.c  */
/* POSIX fiber interface: getcontext(), setcontext() */

#include <signal.h>
#include <stdio.h>
#include <ucontext.h>
#include <unistd.h>
#include <stdlib.h>

#define STACKSZ (10)    /* TODO:find a proper value.*/

ucontext_t ucontext_1, ucontext_2;

int current =0;

/* fiber produce */
void produce() 
{
    current++;
    setcontext(&ucontext_2);
}

/* fiber consume */
void consume()
{
    printf("current value is %d\n", current);
    {// avoid to infinite loop
        if(current>3) exit(0);
    }
    setcontext(&ucontext_1);
}

int main(int argc, char const *argv[])
{
    char func_stack1[STACKSZ];
    char func_stack2[STACKSZ];

    /* create ucontext_1 */
    getcontext(&ucontext_1);
    ucontext_1.uc_link = NULL;
    ucontext_1.uc_stack.ss_sp = func_stack1;
    ucontext_1.uc_stack.ss_size = sizeof(func_stack1);
    makecontext(&ucontext_1,(void (*) (void)) produce, 0);
    
    printf("sizeof(func_stack1) %ld \n", sizeof(func_stack1));

    /* create ucontext_2 */
    getcontext(&ucontext_2);
    ucontext_2.uc_link = NULL;
    ucontext_2.uc_stack.ss_sp = func_stack2;
    ucontext_2.uc_stack.ss_size = sizeof(func_stack2);
    makecontext(&ucontext_2,(void (*) (void)) consume, 0);

    /* switch to ucontext_1 */
    setcontext(&ucontext_1);
    
    return 0;
}

/* run code.
~/temp$ gcc fiber.c
~/temp$ ./a.out 
sizeof(func_stack1) 10 
current value is 1
current value is 2
current value is 3
current value is 4
*/