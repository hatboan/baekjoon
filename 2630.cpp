#include <iostream>
using namespace std;

#define max 128
int paper[max][max];
int n;
int w_cnt=0;
int b_cnt=0;

void cut(int w,int x,int y){
    if(w==1){
        if(paper[x][y]==1)
            b_cnt++;
        else
            w_cnt++;
        
        return;
    }
    int comp=paper[x][y];
    int checker=0;
    for(int i=y;i<y+w;i++){
        for(int j=x;j<x+w;j++){
            if(paper[j][i]!=comp){
                checker=1;
                break;
            }
        }
        if(checker==1)
            break;
    }
    if(checker==0){
        if(comp==1)
            b_cnt++;
        else
            w_cnt++;
  
        return;
    }
    cut(w/2,x,y);
    cut(w/2,x+w/2,y);
    cut(w/2,x,y+w/2);
    cut(w/2,x+w/2,y+w/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>paper[j][i];
    }
    cut(n,0,0);
    cout<<w_cnt<<"\n"<<b_cnt<<"\n";
}
