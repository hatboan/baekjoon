#include <iostream>
using namespace std;
int checked[1000001];

int func(int x){
    if(x==1)
        return 0;
    else if(checked[x]==-1){
        int div3=x;
        int div2=x;
        int min1=func(x-1);
        if(x%3==0)
            div3=func(x/3);
        if(x%2==0)
            div2=func(x/2);
        checked[x]=((div3<div2?div3:div2)<min1?(div3<div2?div3:div2):min1)+1;
    }
    return checked[x];
}

int main(){
    int n,l;
    cin>>n;
    for(l=0;l<1000001;l++)
        checked[l]=-1;
    cout<<func(n)<<"\n";
}
