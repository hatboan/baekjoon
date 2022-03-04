#include <iostream>
#include <queue>
using namespace std;

#define max 1001

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n,total_hour=0;
    priority_queue <int> peoples;
    cin >>n;

    for(int i=0;i<n;i++){
        int inputs;
        cin>>inputs;
        peoples.push(inputs);
    }

    for(int i=1;i<=n;i++){
        total_hour+=peoples.top()*i;
        peoples.pop();
    }

    cout<<total_hour<<"\n";
}
