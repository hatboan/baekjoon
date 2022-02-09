#include <iostream>
#include <queue>
using namespace std;

#define max 101
int n,m;
int relat[max][max];

int bfs(int start){
    queue <int> q;
    int dist[max]={0,};
    int visit[max]={0,};
    int sum=0;
    q.push(start);
    dist[start]=0;
    visit[start]=1;

    while(!q.empty()){
        int next=q.front();
        q.pop();

        for(int i=1;i<=n;i++){
            if(relat[next][i]==1&&visit[i]==0){
                q.push(i);
                dist[i]=dist[next]+1;
                visit[i]=1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        sum+=dist[i];
    }
    return sum;
}

int main(){
    int small=max+1;
    int small_index=0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int f1,f2;
        cin>>f1>>f2;
        relat[f1][f2]=1;
        relat[f2][f1]=1;
    }

    for(int i=1;i<=n;i++){
        int bacon=bfs(i);
        if(small>bacon){
            small=bacon;
            small_index=i;
        }
    }

    cout<<small_index<<"\n";
}
