#include <iostream>
using namespace std;

#define max 1002
unsigned long long  fac_stor[max];

unsigned long long fac(unsigned long long fn){
    if(fn==1||fn<=0)
        return 1;
    
    else{
        if(fac_stor[fn]!=0)
            return fac_stor[fn];
        else{
            fac_stor[fn]=fac(fn-1)*fn;
            return fac_stor[fn];
            }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    unsigned long long count=0;

    for(int i=0;i<=n/2;i++){
        unsigned long long plus=fac(n-i);
        plus=plus/fac(n-2*i);
        plus=plus/fac(i);
        count+=plus;
    }

    cout<<count%10007<<"\n";
}
