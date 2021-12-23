#include <iostream>
using namespace std;
int sorted_x[100000];
int sorted_y[100000];

void merge(int arr_x[],int arr_y[],int left,int mid,int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;

    while(i<=mid && j<=right){
        if(arr_x[i]<arr_x[j]){
            sorted_x[k]=arr_x[i];
            sorted_y[k++]=arr_y[i++];
        }
        else if(arr_x[i]>arr_x[j]){
            sorted_x[k]=arr_x[j];
            sorted_y[k++]=arr_y[j++];
        }
        else{
            if(arr_y[i]<arr_y[j]){
                sorted_x[k]=arr_x[i];
                sorted_y[k++]=arr_y[i++];
            }
            else {
                sorted_x[k]=arr_x[j];
                sorted_y[k++]=arr_y[j++];
            }
        }
    }

    if(i>mid){
        for(l=j;l<=right;l++){
            sorted_x[k]=arr_x[l];
            sorted_y[k++]=arr_y[l];
        }
    }
    else{
        for(l=i;l<=mid;l++){
            sorted_x[k]=arr_x[l];
            sorted_y[k++]=arr_y[l];
        }
    }

    for(l=left;l<=right;l++){
        arr_x[l]=sorted_x[l];
        arr_y[l]=sorted_y[l];
    }

}

void merge_sort(int arr_x[],int arr_y[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        merge_sort(arr_x,arr_y,left,mid);
        merge_sort(arr_x,arr_y,mid+1,right);
        merge(arr_x,arr_y,left,mid,right);
    }
}

int main(){
    int n,l;
    int arr_x[100000];
    int arr_y[100000];
    scanf("%d",&n);
    for(l=0;l<n;l++){
        scanf("%d %d",&arr_x[l],&arr_y[l]);
    }
    merge_sort(arr_x,arr_y,0,n-1);
    for(l=0;l<n;l++)
        printf("%d %d\n",arr_x[l],arr_y[l]);
}
