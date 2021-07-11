#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node{
    char name;
    int style,rank,suit;
}node;
typedef struct card{
    int num[13];
    int face[4];
    int check[13][4];
    node * score;
}card;

void get(card *,char);
void getscore(card *);
int score_cmp(const void *, const void *);

int main()
{
    card member[4];
    node ans[4];
    for(int i=0;i<4;i++)
    {
        member[i].score=&ans[i];
    }
    get(&member[0],'A');
    get(&member[1],'B');
    get(&member[2],'C');
    get(&member[3],'D');
    qsort((void *)ans,4,sizeof(node),score_cmp);
    for(int i=0;i<4;i++)
    {
        printf("%c ",ans[i].name);
    }
    return 0;
}
void get(card * x,char n)
{
    int temp,rtemp,stemp;
    memset(x->num, 0, sizeof(int)*13);
    memset(x->face, 0, sizeof(int)*4);
    memset(x->check, 0, sizeof(int)*52);
    for(int i=0;i<5;i++)
    {
        do{
            temp=getchar();
        }while (temp==' '||temp=='\n');
        switch (temp) {
            case '2': rtemp=0; break;
            case '3': rtemp=1; break;
            case '4': rtemp=2; break;
            case '5': rtemp=3; break;
            case '6': rtemp=4; break;
            case '7': rtemp=5; break;
            case '8': rtemp=6; break;
            case '9': rtemp=7; break;
            case 't': rtemp=8; break;
            case 'j': rtemp=9; break;
            case 'q': rtemp=10; break;
            case 'k': rtemp=11; break;
            case 'a': rtemp=12; break;
            default: break;
        }
        temp=getchar();
        switch (temp) {
            case 'c': stemp=0; break;
            case 'd': stemp=1; break;
            case 'h': stemp=2; break;
            case 's': stemp=3; break;
            default: break;
        }
        x->check[rtemp][stemp]=1;
        x->num[rtemp]++;//把num跟face綁在一起操作，然後以num做排序，這樣就少了check
        x->face[stemp]++;
    }
    getscore(x);
    x->score->name=n;
}
void getscore( card* test) {
    {
        int straight = 0, flush = 0;
        for (int i = 0; i < 4; i++) {//flush
            if (test->face[i] == 5) {
                test->score->suit = i;
                flush = 1;
                for (int j=12;j>= 0;j--) {
                    if (test->num[j]>= 1)
                    {
                        test->score->rank = j;
                        break;
                    }
                }
            }
        }
        int r=0, sequence=0;//straight
        while (test->num[r] == 0) r++;
        for (; r < 13 && test->num[r]>0; r++) {
            sequence++;
        }
        if (sequence == 5) {
            straight = 1;
            test->score->rank = r - 1;
            for (int i = 3; i >= 0; i--) {
                if (test->check[r - 1][i] == 1) {
                    test->score->suit = i;
                    break;
                }
        }
        }
        if (straight && flush) {
            test->score->style = 9;//straight&flush
            return;
        }
        if (straight) {//straight
            test->score->style = 5;//straight
            return;
        }
        if (flush) {//flush
            test->score->style = 6;//flush
            return;
        }
    }
    {
        int three = 0, pair = 0;
        for (int i=0; i<13; i++) {
            if (test->num[i] == 4) {//4 of a kind
                test->score->style = 8;
                test->score->rank = i;
                test->score->suit=0;
                return;
            }
            if (test->num[i] == 3) {
                test->score->rank = i;
                three = 1;
            }
            if (test->num[i] == 2) {
                pair++;
            }
        }
        if (three == 1 && pair == 1) {//full house
            test->score->style = 7;
            return;
        }
        if (three == 1) {//3 of a kind
            test->score->style = 4;
            return;
        }
        if (pair>0) {//2 pair
            if(pair==2) test->score->style=3;
            else test->score->style=2;
            int r;
            for (int i = 12; i >= 0; i--) {
                if(test->num[i]==2)
                {
                    test->score->rank=r=i;
                    break;
                }
            }
            for (int i=3;i>=0;i--) {
                if(test->check[r][i]==1){
                    test->score->suit=i;
                    break;
                }
            }
            return;
        }
    }
    {
        int r=0;//high card
        for(int i=12;i>=0;i--)
        {
            if (test->num[i] == 1) {
                test->score->rank = r = i;
                break;
            }
        }
        for(int j=3;j>=0;j--)
        {
            if(test->check[r][j]==1)
            {
                test->score->style=1;
                test->score->suit=j;
                return;
            }
        }
        }
}
int score_cmp(const void *a,const void *b)
{
    node *A=(node *)a;
    node *B=(node *)b;
    if((A->style)!=(B->style)) return (B->style)-(A->style);
    else if ((A->rank)!=(B->rank)) return (B->rank)-(A->rank);
    else return (B->suit)-(A->suit);
}