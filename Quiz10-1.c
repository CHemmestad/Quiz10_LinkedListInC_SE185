#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Node {
    int num;
    struct Node* next;
} Node;

Node* newNode();
int checkEven(int num);
void addNode(Node* pos, int num);
void freeList(Node* head);
void printList(Node* pos);

int main() {
    FILE *fptr;
    fptr = fopen("numbers.txt", "w+");

    Node* head = newNode();
    Node* evenNums = head;
    Node* pos = head;

    int number;

    fprintf(fptr, "12 7 3 0 28 74 37 299");

    rewind(fptr);

    while(!feof(fptr)) {
        fscanf(fptr, "%d", &number);
        if(checkEven(number)) {
            addNode(pos, number);
            pos = pos->next;
        }
    }
    printList(evenNums);

    freeList(head);
    fclose(fptr);

    return 0;
}

int checkEven(int num) {
    if(num%2 == 0) {
        //printf("%d is even\n", num);
        return 1;
    }
    //printf("%d is odd\n", num);
    return 0;
}

void addNode(Node* pos, int num) {
    //printf("Adding node\n");
    //printf("Current pos is %p\n", pos);
    pos->num = num;
    pos->next = newNode();
    //printf("Next pos is %p\n", pos->next);
}

Node* newNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->num = 0;
    node->next = NULL;
    return node;
}

void freeList(Node* head) {
    Node* temp = newNode();
    while(head->next) {
        temp = head->next;
        free(head);
        head = temp;
    }
    free(temp);
}

// void printList(Node* head) {
//     Node* temp = head;
//     while(temp->next) {
//         printf("%d ", temp->num);
//         temp = temp->next;
//     }
//     printf("\n");
// }

void printList(Node* pos) {
    Node* temp = pos;
    if(!temp->next) {
        printf("\n");
    } else if(temp->next) {
        printf("%d ", temp->num);
        printList(temp->next);
    }
}


