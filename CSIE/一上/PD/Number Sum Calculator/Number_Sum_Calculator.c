#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

int addition(char str[])
{
    int sum=0;
    char *temp;
    temp=strtok(str,"+");
    while (temp!=NULL)
    {
        sum+=atoi(temp);
        temp=strtok(NULL,"+");
    }
    return sum;
}
int main() {
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}
/*strtok:把字串分割成小字串
 呼叫函式會修改原字串內容（將切割符改為'\0'），
 故待切割字串不可為無法修改的字串字面常數(string literal)。
 單次呼叫只能完成一次切割、而不是直接提供切割完畢的字串數組。
 關於切割符字串（更確切的說、切割符集合），
 其內任一字符（而不是整體）都是切割符，而且在每次呼叫函式時都可以依據需求採用相同/不同的字串。
 參數str在呼叫一次之後必須設為空 NULL
 */