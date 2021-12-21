#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    int size=0;
    int arr[100000];
    cin >>n;
    while(n--){
        string opr;
        int num;
        cin>>opr;
        if(opr=="push"){
            cin>>num;
            arr[size++]=num;
        }
        else if(opr=="pop"){
            if(size==0)
                printf("%d\n",-1);
            else{
                printf("%d\n",arr[--size]);
            }
        }
        else if(opr=="size"){
            printf("%d\n",size);
        }
        else if(opr=="empty"){
            if(size==0)
                printf("%d\n",1);
            else
                printf("%d\n",0);
        }
        else{
            if(size==0)
                printf("%d\n",-1);
            else
                printf("%d\n",arr[size-1]);
        }
    }
}
