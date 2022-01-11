#include <iostream>
#include <queue>
using namespace std;
#define MAX 100002
int visit[MAX];
int dist[MAX];
int n,k;

void bfs(int v){
    queue<int> q;
    q.push(v);
    visit[v]=1;
    dist[v]=0;

    
    while(!q.empty()){
        v=q.front();
        q.pop();
            
        if(v==k){
            return;
        }
        if(v*2<MAX&&visit[v*2]==0){
            q.push(v*2);
            visit[v*2]=1;
            dist[v*2]=dist[v]+1;
        }
        if(v+1<MAX&&visit[v+1]==0){
            q.push(v+1);
            visit[v+1]=1;
            dist[v+1]=dist[v]+1;

        }
        if(v-1>=0&&visit[v-1]==0){
            q.push(v-1);
            visit[v-1]=1;
            dist[v-1]=dist[v]+1;
        }        
    }
}

int main(){
    scanf("%d %d",&n,&k);
    bfs(n);
    printf("%d\n",dist[k]);
}
