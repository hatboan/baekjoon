#include <iostream>
using namespace std;
double sorted[100000];

void merge(double arr[100000],int left,int mid,int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;

    while(i<=mid && j<=right){
        if(arr[i]<=arr[j])
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

void merge_sort(double arr[100000],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int binary_search(double sortedArr[100000],int len,double item){
    int left=0;
    int right=len-1;
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if (sortedArr[mid]==item)
            return 1;
        else if(sortedArr[mid]>item)
            right=mid-1;
        else 
            left=mid+1;  
    }
    return 0;
}

int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    double list[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    merge_sort(list,0,n-1);

    int m;
    double itemlist[100000];
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>itemlist[i];
        int itempointer=binary_search(list,n,itemlist[i]);
        cout<<itempointer<<"\n";
    }   
}
