#include <iostream>
using namespace std;
int sorted[1000000];

void merge(int arr[],int left,int mid,int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;

    while(i<=mid && j<=right){
        if(arr[i]<arr[j])
            sorted[k++]=arr[i++];
        else
            sorted[k++]=arr[j++];
    }

    if(i>mid){
        for(l=j;l<=right;l++)
            sorted[k++]=arr[l];
    }
    else{
        for(l=i;l<=mid;l++)
            sorted[k++]=arr[l];
    }

    for(l=left;l<=right;l++)
        arr[l]=sorted[l];
}

void merge_sort(int arr[],int left,int right){
    int mid=(left+right)/2;

    if(left<right){
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int n,i;
    int list[1000000];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>list[i];
    merge_sort(list,0,n-1);
    for(i=0;i<n;i++)
        cout<<list[i]<<"\n";
    return 0;
}
