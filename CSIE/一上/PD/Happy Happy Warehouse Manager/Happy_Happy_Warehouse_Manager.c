#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *good_types[] = {
        "Juice",
        "Wine",
        "Laptop"
};

void *produce(void *top_of_stack, const char *good_type, size_t count);
void *consume(void *top_of_stack, size_t count);
void list_remain(void *top_of_stack);

int main(){
    char record[64], *job, *good;
    size_t count;
    void *top_of_stack = NULL;

    while(fgets(record, 64, stdin)){
        job = strtok(record, " ");
        if(!strcmp(job, "Produce")){
            good = strtok(NULL, " ");
            count = atol(strtok(NULL, " "));

            for(int i = 0; i < 3; i++){
                if(!strcmp(good, good_types[i])){
                    top_of_stack = produce(top_of_stack, good_types[i], count);
                    break;
                }
            }
        }
        else if(!strcmp(job, "Consume")){
            count = atol(strtok(NULL, " "));
            top_of_stack = consume(top_of_stack, count);
        }
    }

    list_remain(top_of_stack);

    return 0;
}
// Your code goes here
typedef struct node{
    char* name;
    int val;
    struct node * next;
}node;
void *produce(void *top_of_stack, const char *good_type, size_t count)
{
    node *top=top_of_stack;
    if(top==NULL)
    {
        node *newptr=malloc(sizeof(node));
        newptr->name=good_type;
        newptr->val=(int)count;
        newptr->next=top;
        top=newptr;
    }
    else if(strcmp(top->name,good_type)==0)
    {
        top->val+=(int)count;
    }
    else
    {
        node *newptr=malloc(sizeof(node));
        newptr->name=good_type;
        newptr->val=(int)count;
        newptr->next=top;
        top=newptr;
    }
    return top;
}
void *consume(void *top_of_stack, size_t count)
{
    node *top=top_of_stack;
    if(top->val>(int)count)
    {
        top->val-=(int)count;
    }
    else if(top->val==(int)count)
    {
        node *temp=top;
        top=top->next;
        free(temp);
    }
    else
    {
        int c=(int)count;
        while(c>0)
        {
            node *temp=top;
            int tempc=c;
            c-=temp->val;
            temp->val=temp->val-tempc;
            if(temp->val<=0)
            {
                top=top->next;
                free(temp);
            }
        }
    }
    return top;
}
void list_remain(void *top_of_stack)
{
    node *top=top_of_stack;
    if(top==NULL){
        printf("Empty\n");
    }
    else
    {
        node *temp=top;
        while(temp!=NULL)
        {
            printf("%s x %d\n",temp->name,temp->val);
            temp=temp->next;
        }
    }
}