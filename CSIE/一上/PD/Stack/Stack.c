#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element {                        // elements of the stack
    int data;
    struct element *next;   // point to the next element in the stack
};

struct head {
    int size;                               // record the size of the stack
    struct element *next;   // point to the first element (at bottom) in the stack if there is any
    struct element *top;    // point to the top of the stack
};

void print_stack(struct head *stack_p);
void push(struct head *stack_p, int data)
{
    struct element* nptr=malloc(sizeof(struct element));
    nptr->data=data;
    nptr->next=NULL;
    if(stack_p->top==NULL) stack_p->next=nptr;
    else
    {
        struct element *tptr;
        for(tptr=stack_p->next;tptr!=stack_p->top;tptr=tptr->next);
        tptr->next=nptr;
    }
    stack_p->top=nptr;
    stack_p->size+=1;
}// put an element to the top of the stack
struct element *pop(struct head *stack_p)
{
    struct element *temp=stack_p->top;
    if(stack_p->top==stack_p->next)
    {
        stack_p->top=stack_p->next=NULL;
        stack_p->size=0;
    }
    else {
        struct element *tptr,*prev;
        for(tptr=stack_p->next,prev=NULL;tptr!=stack_p->top;prev=tptr,tptr=tptr->next);
        stack_p->top=prev;
        prev->next=NULL;
        stack_p->size-=1;
    }
    return temp;
}// remove an element from the top of the stack

int main(void) {
    // stack declaration
    struct head stack_head;
    stack_head.size = 0;
    stack_head.next = NULL;
    stack_head.top = NULL;

    // read instructions
    int num, data;
    char command[5];
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%4s", command);
        if (strcmp(command, "push") == 0) {     // push command, call push()
            scanf("%d", &data);
            push(&stack_head, data);
        }
        else if (strcmp(command, "pop") == 0) { // pop command, call pop()
            struct element *e = pop(&stack_head);
            free(e);
        }
    }
    print_stack(&stack_head);
    return 0;
}

void print_stack(struct head *stack_p) {
    printf("%d\n", stack_p->size);
    for (struct element *ptr = stack_p->next; ptr!= NULL; ptr = ptr->next)
        printf("%d ", ptr->data);
}