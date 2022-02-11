#include <iostream>
#include <map>
#include <string>
using namespace std;

#define max 32

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        map <string,int> category;
        string cloth[max];
        int n,cnt=0;
        int cases=1;
        cin>>n;
        while(n--){
            string clo,cat;
            cin>>clo>>cat;
            if(category[cat]!=0)
                category[cat]++;
            else{
                cloth[cnt++]=cat;
                category[cat]=2;
            }
        }
        for(int i=0;i<cnt;i++)
            cases=cases*category[cloth[i]];
        cout<<cases-1<<"\n";
    }
}

