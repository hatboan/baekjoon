#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int sortedAge[100010];
string sortedName[100010];

void merge(int agelist[],string namelist[],int left,int mid,int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    while(i<=mid&&j<=right){
        if(agelist[i]<=agelist[j]){
            sortedName[k]=namelist[i];
            sortedAge[k++]=agelist[i++];
        }
        else {
            sortedName[k]=namelist[j];
            sortedAge[k++]=agelist[j++];
        }
    }
    if(i>mid){
        for(l=j;l<=right;l++){
            sortedName[k]=namelist[l];
            sortedAge[k++]=agelist[l];
        }
    }
    else{
        for(l=i;l<=mid;l++){
            sortedName[k]=namelist[l];
            sortedAge[k++]=agelist[l];
        }        
    }
    for(l=left;l<=right;l++){
        namelist[l]=sortedName[l];
        agelist[l]=sortedAge[l];
    }
}

void merge_sort(int agelist[],string namelist[],int left,int right){
   if(left<right){
        int mid=(left+right)/2;
        merge_sort(agelist,namelist,left,mid);
        merge_sort(agelist,namelist,mid+1,right);
        merge(agelist,namelist,left,mid,right);
    }
}

int main(){
    int n;
    string name_list[100010];
    int age_list[100010];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>age_list[i]>>name_list[i];
    }
    merge_sort(age_list,name_list,0,n-1);
    for(int j=0;j<n;j++){
        cout<<age_list[j]<<" "<<name_list[j]<<"\n";
    }
    return 0;
}
