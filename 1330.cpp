#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin>> a>>b;
    if(a==b)
        cout<<"=="<<endl;
    else
        cout<<(a>b?">":"<")<<endl;
    return 0;
}
