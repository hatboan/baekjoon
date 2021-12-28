#include <iostream>
using namespace std;
int zero_arr[41];
int one_arr[41];
int fibonacci_arr[41];

int fibonacci(int n) {
    if (n == 0) {
        zero_arr[n]=1;
        one_arr[n]=0;
        return 0;
    } else if (n == 1) {
        zero_arr[n]=0;
        one_arr[n]=1;
        return 1;
    } else {
        if(zero_arr[n]==-1){
            fibonacci_arr[n]=fibonacci(n-1)+fibonacci(n-2);
            zero_arr[n]=zero_arr[n-1]+zero_arr[n-2]; //이 부분을 위의 fibonacci 연산 뒤로 바꾸니 통과할 수 있었음
            one_arr[n]=one_arr[n-1]+one_arr[n-2];
        }
        return fibonacci_arr[n];
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<41;i++){
            one_arr[i]=-1;
            zero_arr[i]=-1;
        }
        int n;
        scanf("%d",&n);
        fibonacci(n);
        printf("%d %d\n",zero_arr[n],one_arr[n]);
    }
}
