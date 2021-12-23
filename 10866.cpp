#include <iostream>
#include <string>
using namespace std;

int main(){ //큐 문제 풀이를 조금 변경해서 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int arr[10000];
    int size=0;
    cin>>n;
    while(n--){
        string opr;
        cin>>opr;
        if(opr=="push_front"){
            int x;
            cin>>x;
            for(int i=size;i>0;i--)
                arr[i]=arr[i-1];
            arr[0]=x;
            size++;
        }
        else if(opr=="push_back"){
            int x;
            cin>>x;
            arr[size++]=x;
        }
        else if(opr=="pop_front"){
            if(size==0)
                cout<<-1<<"\n";
            else{
                cout<<arr[0]<<"\n";
                for(int i=0;i<size-1;i++)
                    arr[i]=arr[i+1];
                size--;
            }
        }
        else if(opr=="pop_back"){
            if(size==0)
                cout<<-1<<"\n";
            else{
                cout<<arr[--size]<<"\n";
            }
        }
        else if(opr=="size")
            cout<<size<<"\n";
        if(opr=="empty"){
            if(size==0)
                cout<<1<<"\n";
            
            else
                cout<<0<<"\n";
            
        }
        else if(opr=="front"){
            if(size==0)
                cout<<-1<<"\n";
            else
                cout<<arr[0]<<"\n";
        }
        else if(opr=="back"){
            if(size==0)
                cout<<-1<<"\n";
            else
                cout<<arr[size-1]<<"\n";           
        }
    }

}
