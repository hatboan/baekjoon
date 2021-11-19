#include <iostream>
using namespace std;

int main(){
    int n[9];
    for (int i=0;i<9;i++){
        cin>>n[i];
    }
    int max=0;
    int max_n=0;
    for(int j=0;j<9;j++){
        max=(max>n[j])?max:n[j];
        max_n=(max>n[j])?max_n:j;
    }
    cout<<max<<endl<<max_n+1<<endl;
}
