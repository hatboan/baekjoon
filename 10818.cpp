#include <iostream>
#include <cstring>
using namespace std;

int main(){
    long int n;
    long int arr[1000000];
    long int max,min=0;
    cin >>n;
    cin>>arr[0];
    max=arr[0];
    min=arr[0];
    for(long int i=1;i<n;i++){
        cin>>arr[i];
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    cout<<min<<" "<<max<<endl;
}
