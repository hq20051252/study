#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int check_pid(int argc, const char *argv[])
{
    pid_t pid;
    pid=vfork();
    if (pid==0) {
        printf("Process ID is %d;\n",pid);
        exit(0);
    }
    printf("process Id is %d;\n",pid);
    exit(0);
}

/*This pices of code is used to test vfork in the case it modify the
 * global data of parent process.
 */
int check_modify_vfork(int* global)
{
    pid_t pid;
    int tmp=*global;
    pid=vfork();
    if(pid==0){
        /*edit parent data*/
        *global=2;
        printf("I'm the child process %d.",pid);
        printf("%d has been changed to %d .\n",tmp,*global);
        exit(0);
    }
    printf("I'm the parent process %d.%d has been changed to %d.\n",pid,tmp,*global);
    exit(0);

}
/*fork type*/
int check_modify_fork(int* global)
{
    pid_t pid;
    int local=1;
    int tmp=*global;
    pid=fork();
    if(pid==0){
        /*edit parent data*/
        local++;
        *global=2;
        printf("I'm the child process %d,%d has been changed to %d .\n",pid,tmp,*global);
        printf("I'm the child process %d,%d has been changed to %d .\n",pid,tmp,local);
        exit(0);
    }
    printf("I'm the parent process %d.%d has been changed to %d.\n",pid,tmp,*global);
    printf("I'm the parent process %d.%d has been changed to %d.\n",pid,tmp,local);
    exit(0);

}

int main(int argc, const char *argv[])
{
    int global=1;
    check_modify_fork(&global);
    return 0;
}
