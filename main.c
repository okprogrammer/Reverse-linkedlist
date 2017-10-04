#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;/*defining head pointer globally which is containing the address of struct node*/
void insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));/*creating a node*/
    struct Node* temp2 = head;
    temp->data = x; /* assingning data in the temp pointer*/
    if(head == NULL)
    {
        temp->next = head;
        head = temp;
        return;
    }
    while(temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
        temp->next = temp2->next;
        temp2->next = temp;
}

    void print()/*printing the linkelist*/
    {
        struct Node* temp = head;
        printf("print the list!\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
void reverse()
{
    struct Node *current,*prev, *next;
    current = head;
    prev = NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next=prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int main()
{
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    reverse();
    print();
    return 0;
}
