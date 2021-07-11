#include <stdio.h>
#include <stdlib.h>

typedef struct meow* meowp;
typedef struct meow{
    int data;
    meowp next;
}meow;
meowp CAT=NULL;
meowp TAIL=NULL;
void setmeow(int cat)
{
    meowp catptr=(meowp)malloc(sizeof(meow));
    catptr->data=cat;
    catptr->next=NULL;
    if(CAT==NULL)
        CAT=TAIL=catptr;
    else
    {
        TAIL->next=catptr;
        TAIL=TAIL->next;
    }
    return;
}
void takemeow(int times)
{

    for(int i=0;i<times;i++)
    {
        meowp nowc=CAT;
        printf("%d ",nowc->data);
        CAT=CAT->next;
        TAIL->next=CAT;
        TAIL=TAIL->next;
        CAT=CAT->next;
        free(nowc);
    }
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        setmeow(i);
    takemeow(m);
    return 0;
}
