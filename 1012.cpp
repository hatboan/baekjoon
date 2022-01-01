#include <iostream>
#include <vector>
using namespace std;
bool visited[52][52];
int graph[51][51];

void dfs(int x,int y){
    visited[x][y]=true;
    printf("x:%d y:%d\n",x,y);
    if(graph[x-1][y]==1&&visited[x-1][y]==false)
        dfs(x-1,y);
    if(graph[x][y+1]==1&&visited[x][y+1]==false)
        dfs(x,y+1);   
    if(graph[x+1][y]==1&&visited[x+1][y]==false)
        dfs(x+1,y);
    if(graph[x][y-1]==1&&visited[x][y-1]==false)
        dfs(x,y-1);    
}

int main(){
    int t,m,n,k,x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&m,&n,&k);
        while(k--){
            scanf("%d %d",&x,&y);
            graph[x+1][y+1]=1;
        }
        dfs(1,1);
    }
}
