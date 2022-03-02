#include <iostream>
using namespace std;

#define max 100001
int st[max];
int et[max];
int sort_st[max];
int sort_et[max];

void merge(int left,int mid,int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;

    while(i<=mid&&j<=right){
        if(et[i]<et[j]){
            sort_et[k]=et[i];
            sort_st[k++]=st[i++];
        }
        else if(et[i]>et[j]){
            sort_st[k]=st[j];
            sort_et[k++]=et[j++];
        }
        else{
            if(st[i]<st[j]){
                sort_st[k]=st[i];
                sort_et[k++]=et[i++];
            }
            else{
                sort_st[k]=st[j];
                sort_et[k++]=et[j++];
            }
        }
    }

    if(i>mid){
        for(l=j;l<=right;l++){
            sort_st[k]=st[l];
            sort_et[k++]=et[l];
        }
    }
    else{
        for(l=i;l<=mid;l++){
            sort_st[k]=st[l];
            sort_et[k++]=et[l];
        }
    }

    for(l=left;l<=right;l++){
        st[l]=sort_st[l];
        et[l]=sort_et[l];
    }
}

void merge_sort(int left,int right){
    int mid=(left+right)/2;
    if(left<right){
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        merge(left,mid,right);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>st[i]>>et[i];
    }

    merge_sort(0,n-1);

    int last_over=et[0];
    int cnt=1;

    for(int i=1;i<n;i++){
        if(st[i]>=last_over){
            last_over=et[i];
            cnt++;
        }
    }

    cout<<cnt<<"\n";
}
