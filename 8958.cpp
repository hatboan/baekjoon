#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int trial;
    cin>>trial;
    for(int i=0;i<trial;i++){
        string s;
        double score[80];
        double scoreSum=0;
        cin>>s;
        int slen=s.length();
        if(s[0]=='O'){
            score[0]=1;
        }
        else{
            if(s[0]=='X')
                score[0]=0;
        }
        scoreSum+=score[0];
        for(int j=1;j<slen;j++){
            if(s[j]=='O')
                score[j]=score[j-1]+1;
            else{
                score[j]=0;
            }
            scoreSum+=score[j];
        }
        cout<<scoreSum<<endl;   
    }
}
