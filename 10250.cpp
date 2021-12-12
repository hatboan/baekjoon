#include <iostream>
using namespace std;

int main(){
    int t,h,w,n,i;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>h>>w>>n;
        if(n%h==0)
            cout<<h<<(n/h<=9?"0":"")<<n/h<<"\n";
        else
            cout<<n%h<<(n/h+1<=9?"0":"")<<n/h+1<<"\n";
    }
    return 0;
}
