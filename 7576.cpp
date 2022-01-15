#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
int smaller=0;
int box[MAX][MAX];
int visit[MAX][MAX][100];
int dist[MAX][MAX];
int biggest=0;
int m,n;

void bfs(int cur_x,int cur_y){
    queue<int> qx;
    queue<int> qy;
    qx.push(cur_x);
    qy.push(cur_y);
    int smaller_cur=smaller++;
    visit[cur_x][cur_y][smaller_cur]=1;
    dist[cur_x][cur_y]=0;

    
    while(!qx.empty()){
        cur_x=qx.front();
        cur_y=qy.front();
        qx.pop();
        qy.pop();

        int plus_x[4]={1,-1,0,0};
        int plus_y[4]={0,0,1,-1};

        for(int i=0;i<4;i++){
            int new_x=cur_x+plus_x[i];
            int new_y=cur_y+plus_y[i];
            if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n){
                if(visit[new_x][new_y][smaller_cur]==0&&box[new_x][new_y]==0){
                    qx.push(new_x);
                    qy.push(new_y);
                    visit[new_x][new_y][smaller_cur]=1;
                    if(dist[new_x][new_y]!=0)
                        dist[new_x][new_y]=dist[new_x][new_y]<dist[cur_x][cur_y]+1?dist[new_x][new_y]:dist[cur_x][cur_y]+1;
                    else dist[new_x][new_y]=dist[cur_x][cur_y]+1;
                }
            }
        }    
     
    }
}

int main(){
    int checker=0;
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            scanf("%d",&box[j][i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[j][i]==1){
                bfs(j,i);
            }
        }
    }



    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            biggest=biggest>dist[j][i]?biggest:dist[j][i];
            if(box[j][i]!=1&&box[j][i]!=-1&&dist[j][i]==0)
                checker=1;
        }
    }

    if(checker==1)
        printf("-1\n");
    else{
        printf("%d\n",biggest);
    }     
}
