#include <iostream>

using namespace std;

int main(){
    int n,k,l,trial;
    int arr[1010];
    int sorted[1010];
    scanf("%d %d",&n,&k);
    trial=n-k+1;
    for(l=1;l<=n;l++){
        arr[l]=l;
    }
    printf("<");
    if(trial>0){
        while(trial--){
            printf("%d, ",arr[k]);
            for(l=1;l<=n;l++)
                sorted[l]=arr[(k+l)==n?n:(k+l)%n];
            n--;
            for(l=1;l<=n;l++)
                arr[l]=sorted[l];
        }
        for(l=1;l<k-1;l++)
            printf("%d, ",arr[l]);
        printf("%d>",arr[k-1]);
    }
    else if(trial==-1)
        printf("1>\n");
}
