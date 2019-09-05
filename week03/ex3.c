#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

void print_list();
void insert_node(Node* after);
void delete_node(Node* del); 

Node* head; // first node, which is counted in the list
int size;

int main(){
    //read ex3_example.txt to see an example
    return 0;
}

void print_list(){
    printf("print_list(): ");
    Node* temp = head;
    while (temp->next != NULL){
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("%d\n", temp->value);
}

void insert_node(Node* after){
    Node* next = after->next; //it's ok if next == NULL
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = 0;
    after->next = new;
    new->next = next;
    size++;
}

void delete_node(Node* del){
    Node* temp = head;
    if (temp == del){
        Node* next = temp->next;
        free(temp);
        head = next;
        return;
    }
    while(temp->next != del) {
        temp = temp->next;
    }
    temp->next = del->next;
    free(del);
    size--;
}




    