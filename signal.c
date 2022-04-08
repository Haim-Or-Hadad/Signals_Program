/**
 * @file signal.c
 * @author Haim Or Hadad and Ilan Gold 
 * @brief 
 * @version final version
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int sig_num)
{
    switch (sig_num)
    {
        case SIGCHLD:
            printf("SIGCHLD\n");
            raise(SIGUSR1);
            sleep(1);
            break;
        case SIGUSR1:
            printf("SIGUSR1\n");
            sleep(1);
            printf("Let's try to divide by 0\n");
            int j =0 ;
            printf("******99/0=******\n");
            int zero = 99/j;
            break;
        case SIGFPE:
            printf("can't divide by zero\n");
            printf("*********************\n");
            sleep(1);
            char *c = "Hello";
            printf("c[10] = xxxxxx");
            c[10] = 'i';
            break;
        case SIGSEGV:
            printf("SIGEGV\n");
            printf("size of array is 3\n");
            printf("*********************\n");
            alarm(2);
            sleep(2);
            break;
        case SIGALRM:
            printf("SIGALARM\n");
            printf("*********************\n");
            sleep(1);
            printf("Let's try to write in assembly 0\n");
            asm("ud2"); 
            break;
        case SIGILL:
            printf("SIGILL\n");
            printf("Undefined Instruction\n");

            exit(0);
    }
}

int main(){
    signal(SIGCHLD, signal_handler);
    signal(SIGUSR1, signal_handler);
    signal(SIGFPE, signal_handler);
    signal(SIGSEGV, signal_handler);
    signal(SIGALRM, signal_handler);
    signal(SIGILL, signal_handler);

    if(!(fork())){
        exit(1);
    }
    
    wait(0);
}