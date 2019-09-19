#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// extern int g;
// int g = 0;

// void* my_th_f1(){
//     int l = 0;
//     static int s;
//     l++; l++;
//     s++; s++;
//     g++; g++;
//     printf("1st thread: s = %d, l = %d, g = %d\n", s, l, g);
// }

// void* my_th_f2(){
//     int l = 0;
//     static int s;
//     s = 0;
//     l++; l++;
//     s++; s++;
//     g++; g++;
//     printf("2nd thread: s = %d, l = %d, g = %d\n", s, l, g);
// }

// void* my_th_f3(){
//     int l = 0;
//     static int s;
//     s = 0;
//     l++; l++;
//     s++; s++;
//     g++; g++;
//     printf("3rd thread: s = %d, l = %d, g = %d\n", s, l, g);
// }

// void some_f(){
//     pthread_t id1, id2, id3;
//     pthread_create(&id1, NULL, my_th_f1, NULL);
//     // pthread_join(id1, NULL);
//     pthread_create(&id2, NULL, my_th_f1, NULL);
//     pthread_create(&id3, NULL, my_th_f1, NULL);

//     pthread_join(id1, NULL);
//     pthread_join(id2, NULL);
//     pthread_join(id3, NULL);
// }

struct Stack
{
    int top;
    unsigned int capacity;
    int* array;
};

struct Stack *stack;

struct Stack* create_stack(unsigned capacity){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(sizeof(int)*capacity);
    for (int i = 0; i<capacity; i++){
        stack->array[i] = 0;
    }
    return stack;
}

void free_stack(){
    free(stack);
}

int is_full(){
    if (stack->top == stack->capacity - 1){
        return 1;
    }
    return 0;
}

int is_empty(){
    if (stack->top == -1){
        return 1;
    }
    return 0;
}

void push(int item){
    // if (is_full()){
    //     printf("Stack if full, dont push\n");
    //     exit(1);
    // }
    stack->array[++(stack->top)] = item;
}

int pop(){
    // if (is_empty()){
    //     printf("Stack if empty, dont pop\n");
    //     exit(1);
    // }
    return stack->array[stack->top--];
}

pthread_mutex_t lock;

void* produce_cookie(void* i){
    if (is_empty()){
        printf("sleeping, top: %d\n", stack->top);
        sleep(2);
    }
    pthread_mutex_lock(&lock); {
    int* p = (int*) i;
    push(*p);
    printf("produce cookie %d\n", *p);
    }
    pthread_mutex_unlock(&lock);
}

void* take_top_cookie(){
    pthread_mutex_lock(&lock); {
    int x = pop();
    printf("take top cookie %d\n", x);
    }
    pthread_mutex_unlock(&lock);
}

void cookie_thing(){
    pthread_t producer;
    pthread_t consumer;
    void* arg;
    int a;
    arg = &a;

    a = 5;
    pthread_create(&producer, NULL, produce_cookie, arg);
    pthread_join(producer, NULL);
    a = 1043;
    pthread_create(&producer, NULL, produce_cookie, arg);
    pthread_join(producer, NULL);

    pthread_create(&consumer, NULL, take_top_cookie, NULL);
    pthread_join(consumer, NULL);
    pthread_create(&consumer, NULL, take_top_cookie, NULL);
    pthread_join(consumer, NULL);

    a = 303;
    pthread_create(&producer, NULL, produce_cookie, arg);
    pthread_join(producer, NULL);
    a = 90;
    pthread_create(&producer, NULL, produce_cookie, arg);
    pthread_join(producer, NULL);

    pthread_create(&consumer, NULL, take_top_cookie, NULL);
    pthread_join(consumer, NULL);
    pthread_create(&consumer, NULL, take_top_cookie, NULL);

    pthread_mutex_destroy(&lock);
    printf("stop cookie things\n");
}

// void* function(void* arg){
//     int* ptr = (int*) arg;
//     int x, y;
//     x = *ptr;
//     ptr++;
//     y = *ptr;
//     int* ret = malloc(sizeof(int));
//     *ret = x+y;
//     return ret;
// }

int main(){
    stack = create_stack(10);
    cookie_thing();
    // pthread_t id;
    // int* arg = (int*) malloc(sizeof(int)*2);
    // arg[0] = 10;
    // arg[1] = 407;
    // pthread_create(&id, NULL, function, arg);
    printf("done\n");
    return 0;
}