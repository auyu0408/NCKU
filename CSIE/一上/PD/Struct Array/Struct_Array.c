#include <stdio.h>
#define SIZE 5

struct Node{
    int a;
};
void mul(struct Node* node_array , long long int *ans){
    for(int i=0;i<SIZE;i++)
    {
        *ans*=node_array[i].a;
    }
}
int main(void){
    struct Node node_array[SIZE];
    for(int i=0; i<SIZE; i++){
        scanf("%d", &node_array[i].a);
    }
    long long int ans = 1;
    mul(node_array, &ans);
    printf("%lld", ans);
    return 0;
}