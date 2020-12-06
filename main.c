#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    srand(time (NULL));
    int f, f2, status, r, r2, p; 
    //(rand() % (max - min + 1)) + min 
    r = (rand() % 9) +2;
    r2 = (rand() % 9) +2;

    printf("pre-fork child: %d\tparent: %d\n", getpid(), getppid()); 

    f = fork();
    if(f){
        //second child process to be forked
        f2 = fork();
        if(f2 == 0){
            printf("Another child! %d\n", getpid());
            sleep(r2);
            printf("Child 2 finished sleeping\n");
            return r2; 
        } 
        //parent waits for any child
        p = wait(&status);
        printf("I'm the parent! My child who woke up first is %d and slept for %d secs\n", p, WEXITSTATUS(status)); 
        printf("Parent is done\n");
    }
    else{
        printf("I'm the child! %d\n", getpid());
        sleep(r); 
        printf("Child 1 finished sleeping\n");
        return r; 
    }
     
    
    return 0; 
}
