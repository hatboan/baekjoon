#include <iostream>
using namespace std;

int main(){
    int first,second,gcd=1,lcm,smaller;
    cin >>first>>second;
    smaller=(first<second?first:second);
    for(int i=1;i<=smaller;i++){
        if(first%i==0 && second%i==0)
            gcd=(i>gcd?i:gcd);
    }
    lcm=(first*second)/gcd;
    cout<<gcd<<"\n"<<lcm<<endl;
}
