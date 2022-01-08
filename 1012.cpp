#include <iostream>
using namespace std;

#define MAX 2500
int land [50][50];
int visit[MAX]={0,};
int M,N,K;

void dfs(int v){
    visit[v]=1;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    for(int i=0;i<4;i++){
        int nx=v%M+x[i];
        int ny=v/M+y[i];
        if(nx>=0&&nx<M&&ny>=0&&ny<N){
            if(land[nx][ny]==1&&visit[ny*M+nx]==0){
                dfs(ny*M+nx);
            }
        }
    }
}

int main(){
    int t,l;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d %d %d",&M,&N,&K);
        while(K--){
            int cab_x,cab_y;
            scanf("%d %d",&cab_x,&cab_y);
            land[cab_x][cab_y]=1;
        }
        for(l=0;l<M*N;l++){
            if(visit[l]==0&&land[l%M][l/M]==1){
                dfs(l);
                cnt++;
            }
        }
        for(l=0;l<MAX;l++){
            land[l%M][l/M]=0;
            visit[l]=0;
        } 
        printf("%d\n",cnt);
    }
}
