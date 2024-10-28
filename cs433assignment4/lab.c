#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *fun1();
void *fun2();
int shared = 1; // shared variable

int main(){

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("final value of shared is %d\n", shared); // prints last updated value of shared variable


    return 0;
}

void *fun1(){
    int x;
    x = shared;
    printf("thread1 reads the value of shared variables as %d\n", x);
    x++;
    printf("local updation of thread1: %d\n", x);
    sleep(1);
    shared = x;
    printf("value of shared variable updated by thread1: %d\n", shared);
}

void *fun2(){
    int y;
    y = shared;
    printf("thread2 reads the value of shared variables as %d\n", y);
    y--;
    printf("local updation of thread1: %d\n", x);
    sleep(1);
    shared = y;
    printf("value of shared variable updated by thread2: %d\n", shared);
}