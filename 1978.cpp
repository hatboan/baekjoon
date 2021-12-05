#include <iostream>
using namespace std;

int main(){
    int n,i,j,sum=0;
    int arr[100];
    cin >>n;
    for (i=0;i<n;i++)
        cin>>arr[i];
    for (i=0;i<n;i++){
        int checker=0;
        if(arr[i]!=1){
            for(j=2;j<arr[i];j++){
                if(arr[i]%j==0)
                    checker=1;
            }
            if(checker==0)
                sum++;
        }
    }
    cout<<sum<<"\n";
}
