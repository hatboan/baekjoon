#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int r;
        char s[21];
        cin>>r>>s;
        int sLen=strlen(s);
        for(int j=0;j<sLen;j++){
            for(int k=0;k<r;k++){
                cout<<s[j];
            }
        }
        cout<<endl;
    }
}
