#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

#define max 100001

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,count=0,cp; //current point 
    priority_queue <pair <unsigned int,unsigned int>,vector<pair<unsigned int,unsigned int>>,greater<pair<unsigned int,unsigned int>>> timetable; //start time

    cin>>n;

    for(int i=0;i<n;i++){
        unsigned int cst,cet; //current
        cin>>cet>>cst;
        timetable.push({cst,cet});
    }

    for(int i=0;i<n;i++){
        cout<<timetable.top().first<<timetable.top().second<<endl;
        timetable.pop();
    }
}
