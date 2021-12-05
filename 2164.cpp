#include <iostream>
using namespace std;

int main(){
    int n=0,i=0;
    int arr[9000000];
    cin>>n;
    for(i=1;i<=n;i++){
        arr[i]=i;
    }
    int starter=1;
    while(starter<n){
        starter++;
        if(starter==n)
            break;
        arr[n+1]=arr[starter++];
        n++;
    }
    cout<<arr[n]<<"\n";
    return 0;
}
