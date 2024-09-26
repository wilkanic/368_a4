#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/////////////////////////////////////////////////////////
//Initializing Node Functions//
struct Node {
    int data;          
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* insertAtBeginning(struct Node* head, int value)
{
    struct Node* new_node = newNode(value);
    new_node->next = head;
    head = new_node;
    return head;
}

struct Node* deleteVal(struct Node* head, int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found!\n", value);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

void List_destroy(struct Node * h)
{
 while (h != NULL)
 {
 struct Node * p = h -> next;
 free (h);
 h = p;
 }
}
/////////////////////////////////////////////////////////

int main(){

    char full_string[10];
    int window;
    char action[10];
    
    char open[] = "open";
    char close[] = "close";
    char switches[] = "switch";

    struct Node * head = NULL;

    do{
        fgets(full_string, sizeof(full_string), stdin);

        sscanf(full_string, "%s %d", action, &window);

        if ((strcmp(action, open) == 0)){
            head = insertAtBeginning(head, window);

        } else if ((strcmp(action, close) == 0)){
            head = deleteVal(head, window);

        } else if ((strcmp(action, switches) == 0)){
            head = deleteVal(head, window);
            head = insertAtBeginning(head, window);

        } else {
            printf("failed\n");
        }
        if (head != NULL) {
            printf("%d\n", head->data);
        }
    }
    while (head != NULL);

    List_destroy(head);
    return 0;
}