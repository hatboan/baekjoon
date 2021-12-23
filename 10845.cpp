#include <iostream>
#include <string>
using namespace std;

int main(){
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
        if(opr=="push"){
            int x;
            cin>>x;
            arr[size++]=x;
        }
        else if(opr=="pop"){
            if(size==0)
                cout<<-1<<"\n";
            else{
                cout<<arr[0]<<"\n";
                for(int i=0;i<size-1;i++)
                    arr[i]=arr[i+1];
                size--;
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
