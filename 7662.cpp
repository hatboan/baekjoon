#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    
    while(t--){
        long long int k;
        priority_queue <int> big;
        priority_queue <int,vector<int>,greater<int>> small;
        cin>>k;
        while(k--){
            string di;
            int n;
            cin>>di>>n;
            if(di=="I"){
                big.push(n);
                small.push(n);
            }
            else{
                if(!big.empty()){
                    if(n==1){
                        big.pop();
                        priority_queue <int> nbig=big;
                        priority_queue <int,vector<int>,greater<int>> nsmall;
                        while(!nbig.empty()){
                            nsmall.push(nbig.top());
                            nbig.pop();
                        }
                        small=nsmall;
                    }
                    else{
                        small.pop();
                        priority_queue <int> nbig;
                        priority_queue <int,vector<int>,greater<int>> nsmall=small;
                        while(!nsmall.empty()){
                            nbig.push(nsmall.top());
                            nsmall.pop();
                        }
                        big=nbig;                        
                    }
                }
            }
        }
    
        if(big.empty())
            cout<<"EMPTY\n";
        else
            cout<<big.top()<<" "<<small.top()<<"\n";
    }
}
