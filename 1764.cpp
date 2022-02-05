#include <iostream>
#include <string>
#include <map>
using namespace std;

#define max 500001
int n,m;
map <string,int> unheard;
string unhs[max];
string ordered[max];

void merge(string arr[],int left,int mid,int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;

    while(i<=mid&&j<=right){
        if(arr[i].compare(arr[j])<0)
            ordered[k++]=arr[i++];
        else
            ordered[k++]=arr[j++];
    }
    if(i>mid){
        for(l=j;l<=right;l++)
            ordered[k++]=arr[l];
    }
    else{
        for(l=i;l<=mid;l++)
            ordered[k++]=arr[l];
    }

    for(l=left;l<=right;l++)
        arr[l]=ordered[l];
}


void mergesort(string arr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int size=0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string curh;
        cin>>curh;
        unheard[curh]=1;
    }
    for(int i=0;i<m;i++){
        string curs;
        cin>>curs;
        if(unheard[curs]==1)
            unhs[size++]=curs;
    }

    mergesort(unhs,0,size-1);
    cout<<size<<"\n";
    for(int i=0;i<size;i++)
        cout<<unhs[i]<<"\n";
    
}
