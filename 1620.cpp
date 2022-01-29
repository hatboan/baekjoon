#include <iostream>
#include <string>
using namespace std;

#define max 100001
string name[max];
string quest;
long n,m,l;

int main(){
    cin>>n>>m;
    for(l=1;l<=n;l++)
        cin>>name[l];
    while(m--){
        cin>>quest;
        long isnum=(long)quest[0];
        if(isnum>47&&isnum<58){
            long long num=stoll(quest);
            cout<<name[num]<<"\n";
        }
        else{
            for(l=1;l<=n;l++){
                if(quest==name[l]){
                    cout<<l<<"\n";
                    break;
                }
            }
        }
    }
}
