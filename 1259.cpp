#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char c[6];
    cin>>c;
    while(strcmp(c,"0")!=0){
        int len=(int)strlen(c);
        int checker=0;
        for(int i=0;i<=len/2;i++){
            if(c[i]!=c[len-1-i])
                checker=1;
        }
        cout<<(checker==0?"yes":"no")<<endl;
        cin>>c;
    }
}
