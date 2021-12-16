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

int lower_bound(int arr[],int target,int size){
    int mid,start,end;
    start=0;
    end=size-1;
    while(start<end){
        mid=(start+end)/2;
        if(arr[mid]>=target)
            end=mid;
        else start=mid+1;
    }
    return end;
}

int main(){
    int n,m,l;
    int cardlist[500001];
    int checklist[500001];
    scanf("%d",&n);
    for(l=0;l<n;l++)
        scanf("%d",&cardlist[l]);
    merge_sort(cardlist,0,n-1);
    scanf("%d",&m);
    for(l=0;l<m;l++)
        scanf("%d",&checklist[l]);
    for(l=0;l<m;l++){
        int checker=lower_bound(cardlist,checklist[l],n);
        int cnt=0;
        if(cardlist[checker]!=checklist[l]){
            if(l==0)
                printf("%d",0);
            else
                printf(" %d",0);
        }
        else{
            while(cardlist[checker++]==checklist[l])
                cnt++;
            if(l==0) printf("%d",cnt);
            else printf(" %d",cnt);
        }
    }
    printf("\n");
    return 0;   
}
