#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int note[8];
    cin>>note[0];
    int asc_flag=0;
    int dsc_flag=0;
    for(int i=1;i<8;i++){
        cin>>note[i];
        if(note[i-1]<note[i]){
            asc_flag=1;
        }
        else{
            dsc_flag=1;
        }
        if(asc_flag==1&&dsc_flag==1){
            cout<<"mixed"<<endl;
            asc_flag=0;
            dsc_flag=0;
            break;
        }
    }
    if(asc_flag==1)
        cout<<"ascending"<<endl;
    if(dsc_flag==1)
        cout<<"descending"<<endl;
}
