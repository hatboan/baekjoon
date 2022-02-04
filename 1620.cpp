#include <iostream>
#include <string>
#include <map>
using namespace std;

#define max 100001
string name[max];
long pock_hash[max];
string quest;
long n,m,l;
map <string,int> idxs;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(l=1;l<=n;l++){
        cin>>name[l];
        idxs[name[l]]=l;
    }
    while(m--){
        cin>>quest;
        long isnum=(long)quest[0];
        if(isnum>47&&isnum<58){
            long num=stoll(quest);
            cout<<name[num]<<"\n";
        }
        else{
            cout<<idxs[quest]<<"\n";
        }
    }
}
