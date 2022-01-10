#include <iostream>
using namespace std;

#define MAX 1001
int mat[MAX][MAX];
int visit[MAX];
int n,connect;

void dfs(int v){
    visit[v]=1;

    for(int i=1;i<=n;i++){
        if(visit[i]==0&&mat[v][i]==1)
            dfs(i);
    }
}

int main(){
    int l,cnt=0;
    scanf("%d %d",&n,&connect);
    while(connect--){
        int a,b;
        scanf("%d %d",&a,&b);
        mat[a][b]=mat[b][a]=1;
    }
    for(l=1;l<=n;l++){
        if(visit[l]==0){
            dfs(l);
            cnt++;
        }
    }
    printf("%d\n",cnt);
}
