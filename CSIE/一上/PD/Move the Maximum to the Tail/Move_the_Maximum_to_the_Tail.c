#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail();

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val);
    return 0;
}
// Your code goes here
void MoveToTail()
{
    struct node* temp=head;
    struct node* max=head;
    while(temp!=NULL)
    {
        if(temp->val>max->val)
            max=temp;
        temp=temp->next;
    }
    temp=head;
    if(temp==max)
    {
        tail->next=max;
        head=temp->next;
        max->next=NULL;
    }
    else
    {
        while(temp->next!=max)
        {
            temp=temp->next;
        }
        tail->next=max;
        temp->next=max->next;
        max->next=NULL;
    }
}