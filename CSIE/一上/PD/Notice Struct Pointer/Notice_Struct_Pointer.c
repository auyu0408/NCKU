#include <stdio.h>

struct Node{
    int num;
};
void mul(struct Node* node_a ,struct Node node_b, long long int* ans){
    *ans=(node_a->num)*(node_b.num);
}
int main(void){
    struct Node node_a, node_b;
    long long int ans = 1;

    scanf("%d", &node_a.num);
    scanf("%d", &node_b.num);
    mul(&node_a, node_b, &ans);
    printf("%lld", ans);
    return 0;
}