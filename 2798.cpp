#include <iostream>
using namespace std;

int main(){
    int n,m,i,j,k;
    int winningsum=0;
    int cardlist[100];
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>cardlist[i];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=j+1;k<n;k++){
                int currentsum=cardlist[i]+cardlist[j]+cardlist[k];
                if(currentsum>winningsum&&currentsum<=m)
                    winningsum=currentsum;
            }
        }
    }
    cout<<winningsum<<"\n";
}
