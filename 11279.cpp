#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue <int> pq;
    int n;
    cin>>n;

    while(n--){
        int input;
        cin>>input;
        if(input==0){
            if(pq.empty())
                cout<<0<<"\n";
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else
            pq.push(input);
    }
}
