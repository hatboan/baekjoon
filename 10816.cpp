#include <iostream>
using namespace std;
int sorted[500001];

void merge(int arr[],int left,int mid,int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            sorted[k++]=arr[i++];
        }
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
    if(left<right){
        int mid=(left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int n,m,l;
    int cardlist[500001];
    int checklist[500001];
    cin>>n;
    for(l=0;l<n;l++)
        cin>>cardlist[l];
    merge_sort(cardlist,0,n-1);
    cin>>m;
    for(l=0;l<m;l++)
        cin>>checklist[l];
    for(l=0;l<m;l++){
        int start=0;
        int end=n-1;
        int find=0;
        int cnt=0;
        int checker=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(cardlist[mid]<checklist[l])
                start=mid+1;
            else if(cardlist[mid]>checklist[l])
                end=mid-1;
            else{
                checker=mid;
                find=1;
                break;
                }
        }
        if(find==0)
            checklist[l]=0;
        else{
            while(1){
                if(cardlist[checker-1]==checklist[l])
                    checker--;
                else
                    break;
            }
            while(1){
                cnt++;
                if(cardlist[checker+1]==checklist[l])
                    checker++;
                else
                    break;
            }
            checklist[l]=cnt;
        }
    }
    return 0;   
}
