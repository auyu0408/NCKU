#include <stdio.h>
#include <stdbool.h>
#define n 5
bool visit(char(*)[n], int(*)[n], int, int);
int main(void) {
    char maze[n][n];
    int route[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            route[i][j]=0;
            scanf("%c", &maze[i][j]);
            getchar();
        }
    }
    if (visit(maze, route, 0, 0)) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                printf("%d ", route[i][j]);
            printf("\n");
        }
    } else {
        printf("Can't find the exit!");
    }
    return 0;
}
int check[n][n]={0};//多做一個check的陣列，避免一直重複檢查變成無窮迴圈
bool visit(char maze[][n], int route[][n], int originX, int originY) {
    if(originX>=n||originY>=n||originX<0||originY<0) return false;
    check[originX][originY]=1;//檢查邊界要在check前面，因為check的大小和迷宮一樣，附帶一提check[0][5]=check[1][0]，所以如果沒有先檢查邊界，會導致有些明明沒被檢查到的被誤認為有檢查了
    if(maze[originX][originY]=='w') return false;
    if(originX==4&&originY==4)
    {
        route[originX][originY]=1;
        return true;
    }
    bool a,b,c,d;//把方向用矩陣表達，dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}，這樣可以使用for迴圈表達下列式子
    if(check[originX][originY-1]==0)
        a=visit(maze, route, originX, originY-1);
    else a=false;
    if(check[originX-1][originY]==0)
        b=visit(maze, route, originX-1, originY);
    else b=false;
    if(check[originX][originY+1]==0)
        c=visit(maze, route, originX, originY+1);
    else c=false;
    if(check[originX+1][originY]==0)
        d=visit(maze, route, originX+1, originY);
    else d=false;
    if(a||b||c||d)
    {
        route[originX][originY]=1;
        return true;
    }
    else return false;
}
/*int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int check[n][n]={0};
bool visit(char maze[][n],int route[][n], int X,int Y)
{
    route[X][Y]=1,check[X][Y]=1;
    if(X==4&&Y==4)
        return 1;
    for(int i=0,dx,dy;i<4;i++ )
    {
         dx=X+dir[i][0],dy=Y+dir[i][1];

         if(dx>=0&&dx<n&&dy>=0&&dy<n)
             if(maze[dx][dy]=='r'&&!check[dx][dy]&&visit(maze,route,dx,dy))
                 return 1;//因為這些事情是每次都要做的，不如一起判斷
    }
    route[X][Y]=0;
    return 0;
}*/
