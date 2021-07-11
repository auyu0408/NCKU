#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 64
#define NAME_LENGTH 10

struct timestamp {
    int hour, minute;
};

struct message_info {
    struct timestamp time;
    char name[NAME_LENGTH];
    char message[MESSAGE_LENGTH];
};

int cmp(const void *a, const void *b);
void sort_message(struct message_info *m, int *total);

int main(void) {
    struct message_info m[100];
    int total;
    scanf("%d", &total);
    for(int i = 0; i < total; i++)
        scanf("%d:%d %s %[^\n]", &m[i].time.hour, &m[i].time.minute, m[i].name, m[i].message);
    sort_message(m, &total);
    for(int i = 0; i < total; i++)
        printf("%02d:%02d %s %s\n", m[i].time.hour, m[i].time.minute, m[i].name, m[i].message);
    return 0;
}
// Your code goes here
int cmp(const void *a, const void *b)
{
    struct message_info *A=(struct message_info *)a;
    struct message_info *B=(struct message_info *)b;
    if(A->time.hour!=B->time.hour)
        return (A->time.hour)-(B->time.hour);
    else
        return (A->time.minute)-(B->time.minute);
}
void sort_message(struct message_info *m, int *total)
{
    qsort((void *)m,*total,sizeof(struct message_info),cmp);
}