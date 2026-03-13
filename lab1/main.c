#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    char ch;
    int count;
    struct Node *next;
} Node;


Node* create(Node **head, char c) {
    Node *curr = *head;
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = c;
    newNode->count = 0;
    newNode->next = *head;
    *head = newNode;
    return newNode;
}

struct Node* ReverseList(Node* head){
    struct Node *prev=NULL;
    struct Node *curr=head;
    struct Node *next=NULL;
    
    while(curr!= NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main() {
    FILE *fp;
    char c;
    Node *head = NULL;

    
    fp = fopen(__FILE__, "r");

    
    while ((c = fgetc(fp)) != EOF) {
        Node *node = create(&head, c);
        node->count++;
    }

    fclose(fp);

    

    
    head=ReverseList(head);
    Node *curr = head;
    while (curr != NULL) {
        if(curr->ch!= ' ')
        printf("'%c' ", curr->ch);
        Node *temp = curr;
        curr = curr->next;
        free(temp); 
    }

    return 0;
}
