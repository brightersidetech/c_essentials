/*********************************************************
* This example demonstrates how child processes can be 
* created from parent processes using the fork() function.
* As can be demonstrated, the parent withas a pid different 
* from zero produces a new child process with pid of zero
* 
* since the child process is a copy of th parent process
* and is run automatically after creation, we should see
* the outputs of both functions

**********************************************************/


#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

pid_t pid;
/** function to call for child process */
void do_child(void){
    printf("I am child and my PID is %d\n",pid);
}

/* function to call for parent process */
void do_parent(void){
    printf("I am parent and my PID is %d\n",pid);
}

void main(void){
    pid = fork();
    switch(pid){
        case -1: printf("fork function failed \n"); break;
        case 0: do_child(); break;
        default: do_parent();  break;
    }

    exit(0);
}