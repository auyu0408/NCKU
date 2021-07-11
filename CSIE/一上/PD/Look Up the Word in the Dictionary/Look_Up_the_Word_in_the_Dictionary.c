#include<stdio.h>
#include<string.h>
#define N 10

typedef struct dict_t_struct {
    char word[10];
    int page;
} dict_t;
int search(dict_t arr[], char target[]){
    for(int i=0;i<N;i++)
        if (strcmp(arr[i].word,target)==0)
            return arr[i].page;
    return 0;
}
int main() {
    dict_t dictionary[N];
    char targetWord[10];

    for(int i=0; i<N; i++)
        scanf("%s %d\n", dictionary[i].word, &dictionary[i].page);

    scanf("%s", targetWord);
    int targetPage = search(dictionary, targetWord);
    printf("%d", targetPage);
    return 0;
}