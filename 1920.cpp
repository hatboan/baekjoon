#include <iostream>
using namespace std;

void merge(double arr[],)

int main(){
    double n;
    double a[100001];
    double m;
    double mlist[100001];
    double checker[100001]={0};
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>mlist[i];
        for(int j=0;j<n;j++){
            if(mlist[i]==a[j]){
                checker[i]=1;
                break;
            }
        }
    }
    for(int i=0;i<m;i++)
        cout<<checker[i]<<endl;

}
