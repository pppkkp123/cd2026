#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    char ch;
    int count;
    struct Node *next;
} Node;


Node* find_or_create(Node **head, char c) {
    Node *curr = *head;
    // 遍歷尋找是否已存在
    while (curr != NULL) {
        if (curr->ch == c) return curr;
        curr = curr->next;
    }
    // 若不存在，建立新節點 (插入到開頭)
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = c;
    newNode->count = 0;
    newNode->next = *head;
    *head = newNode;
    return newNode;
}

int main() {
    FILE *fp;
    char c;
    Node *head = NULL;

    
    fp = fopen(__FILE__, "r");

    
    while ((c = fgetc(fp)) != EOF) {
        Node *node = find_or_create(&head, c);
        node->count++;
    }

    fclose(fp);

    

    Node *curr = head;
    while (curr != NULL) {
        printf("字元 '%c' : %d 次\n", curr->ch,  curr->count);
        Node *temp = curr;
        curr = curr->next;
        free(temp); // 釋放記憶體
    }

    return 0;
}
