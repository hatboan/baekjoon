#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int bit[21];
    int m;
    cin>>m;

    for(int i=0;i<21;i++)
        bit[i]=0;

    while(m--){
        string cmd;
        int num;
        cin>>cmd;
        if(cmd=="all"){
            for(int i=1;i<21;i++)
                bit[i]=1;
        }
        else if(cmd=="empty"){
            for(int i=1;i<21;i++)
                bit[i]=0;
        }
        else{
            cin>>num;
            if(cmd=="add")
                bit[num]=1;
            else if(cmd=="remove")
                bit[num]=0;
            else if(cmd=="check")
                cout<<bit[num]<<"\n";
            else if(cmd=="toggle"){
                bit[num]=(bit[num]==1)?0:1;
            }
        }
    }
}
