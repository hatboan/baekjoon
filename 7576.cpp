#include <iostream>
#include <queue>
using namespace std;

#define max 1001
queue <pair<int,int>> q;
int land[max][max]={0,};
int dist[max][max]={0,};
int m,n;

void bfs(){
    int visit[max][max]={0,};

    int px[4]={1,-1,0,0};
    int py[4]={0,0,1,-1};

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        visit[cx][cy]=1;
        q.pop();
        for(int a=0;a<4;a++){
            int nx=cx+px[a];
            int ny=cy+py[a];
            if(nx>=0&&nx<m&&ny>=0&&ny<n){
                if(visit[nx][ny]==0&&land[nx][ny]==0){
                    visit[nx][ny]=1;
                    q.push(make_pair(nx,ny));
                    dist[nx][ny]=dist[cx][cy]+1;
                }
            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int biggest=0;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>land[j][i];
            if(land[j][i]==1){
                dist[j][i]=0;
                q.push(make_pair(j,i));
            }
        }
    }

    bfs();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            biggest=biggest>dist[j][i]?biggest:dist[j][i];
            if(dist[j][i]==0&&land[j][i]!=1&&land[j][i]!=-1){
                cout<<-1<<"\n";
                return 0;
            }

        }
    }

    cout<<biggest<<"\n";
}
