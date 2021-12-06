#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string checker(){
    int counter=0;
    char list[51];
    cin>>list;
    for(int i=0;i<(int)strlen(list);i++){
        if(list[i]=='(')
            counter++;
        else if(list[i]==')'){
            counter--;
            if(counter<0){
                return "NO";
            }
        }
    }
    return (counter==0?"YES":"NO");
}
int main(){
    int t;
    cin >>t;
    while(t--){
        cout<<checker()<<"\n";
    }
}
