#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        multiset <int> ms;
        int k,n;
        cin>>k;
        string di;

        while(k--){
            cin>>di>>n;
            if(di=="I"){
                ms.insert(n);
            }
            else{
                if(!ms.empty()){
                    if(n==1){
                        auto iter=ms.end();
                        iter--;
                        ms.erase(iter);
                    }
                    else
                        ms.erase(ms.begin());
                }
            }
        }


        if(ms.empty())
            cout<<"EMPTY"<<"\n";
        else{
            auto end_iter=ms.end();
            end_iter--;
            cout<<*end_iter<<" "<<*ms.begin()<<"\n";
        }
    }
}
