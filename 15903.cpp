#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long int n,m,next,first,second,sum=0;
    priority_queue <long long int,vector<long long int>,greater<long long int>> card;
    cin>>n>>m;

    while(n--){
        cin>>next;
        card.push(next);
    }

    while(m--){
        first=card.top();
        card.pop();
        second=card.top();
        card.pop();
        card.push(first+second);
        card.push(first+second);
    }

    while(!card.empty()){
        sum+=card.top();
        card.pop();
    }

    cout<<sum<<"\n";

    return 0;

}
