#include <iostream>
using namespace std;

int fac(int num){
    if(num==1||num==0)
        return 1;
    else
        return num*fac(num-1);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d\n",fac(n)/(fac(k)*fac(n-k)));
    return 0;
}
