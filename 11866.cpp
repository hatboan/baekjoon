#include <iostream>

using namespace std;

int main(){
    int n,k,l,trial;
    int arr[1010];
    int sorted[1010];
    scanf("%d %d",&n,&k);
    trial=n-1;
    for(l=1;l<=n;l++){
        arr[l]=l;
    }
    printf("<");
    if(trial>0){
        while(trial--){
            printf("%d, ",arr[k%n==0?n:k%n]);
            for(l=1;l<=n;l++)
                sorted[l]=arr[(k+l)%n==0?k%n+l:(k+l)%n];
            n--;
            for(l=1;l<=n;l++)
                arr[l]=sorted[l];
        }
        printf("%d>",arr[k%n==0?n:k%n]);
    }
    else if(n==1)
        printf("1>");
}
