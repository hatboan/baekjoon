#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char sorted[30000][60];

void merge(char arr[30000][60],int left, int mid, int right){
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    
    while(i<=mid && j<=right){
        if(strlen(arr[i])<strlen(arr[j]))
            strcpy(sorted[k++],arr[i++]);
        else if(strlen(arr[i])>strlen(arr[j]))
            strcpy(sorted[k++],arr[j++]);
        else{
            string stri(arr[i]);
            string strj(arr[j]);
            if(stri.compare(strj)<0)
                strcpy(sorted[k++],arr[i++]);
            else
                strcpy(sorted[k++],arr[j++]);
        }
    }

    if(i>mid){
        for(l=j;l<=right;l++)
            strcpy(sorted[k++],arr[l]);
    }

    else{
        for(l=i;l<=mid;l++)
            strcpy(sorted[k++],arr[l]);
    }

    for(l=left;l<=right;l++)
        strcpy(arr[l],sorted[l]);
}

void mergesort(char arr[30000][60],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int n;
    char cha[30000][60];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cha[i];
    }
    mergesort(cha,0,n-1);

	for(int i=0; i < n-1; i++){ 
		if(strcmp(cha[i],cha[i+1])==0){
			for(int j=i; j < n-1; j++)
				strcpy(cha[j],cha[j+1]);
			n--;
			i--;
		}
	}

    if(strcmp(cha[0],cha[1])==0&&n!=1){
        for(int j=1; j < n-1; j++)
			strcpy(cha[j],cha[j+1]);
        n--;
    }

    for(int i=0;i<n;i++)
        cout<<cha[i]<<endl;

    return 0;
}
