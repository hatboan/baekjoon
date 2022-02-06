#include <iostream>
#include <queue>
using namespace std;

#define max 1002
int n,m,stv,cona,conb;
int v[max];
int e[max][max];
int visit[max];


void dfs(int curv){
    if(curv==stv)
        cout<<curv;
    else
        cout<<" "<<curv;
    visit[curv]=1;
    for(int i=1;i<=n;i++){
        if(e[curv][i]==1&&visit[i]==0)
            dfs(i);
    }
}

void bfs(int curv){
    queue <int> q;
    q.push(curv);
    visit[curv]=0;
    cout<<curv;

    while(!q.empty()){
        int nextv=q.front();
        q.pop();

        for(int i=1;i<=n;i++){
            if(e[nextv][i]==1&&visit[i]==1){
                q.push(i);
                visit[i]=0;
                cout<<" "<<i;
            }
        }
    }
}

int main(){
    cin>>n>>m>>stv;
    for(int i=0;i<m;i++){
        cin>>cona>>conb;
        e[cona][conb]=1;
        e[conb][cona]=1;
    }

    dfs(stv);
    cout<<"\n";

    bfs(stv);
    cout<<"\n";
}
