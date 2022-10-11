#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

pid_t pid;

void do_child(void){
    printf("I am child and my PID is %d\n",pid);
}

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