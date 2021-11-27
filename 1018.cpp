#include <iostream>
using namespace std;

int main(){
    char board[50][50];
    int counter[50][50];
    int height,weight;
    cin>>height>>weight;
    int min=height*weight;
    for(int i=0;i<height;i++){
        cin>>board[i];
    }
    for(int j=0;j<height-7;j++){
        for(int k=0;k<weight-7;k++){
            int bcounter=0;
            int wcounter=0;
            for(int m=0;m<4;m++){
                for(int n=0;n<4;n++){
                    if(board[j+2*m][k+2*n]=='B'){
                        wcounter++;
                    }else{bcounter++;}
                }                
            }
            for(int m=0;m<4;m++){
                for(int n=0;n<4;n++){
                    if(board[j+2*m+1][k+2*n]=='W'){
                        wcounter++;
                    }else{bcounter++;}
                }
            }
            for(int m=0;m<4;m++){
                for(int n=0;n<4;n++){
                    if(board[j+2*m][k+2*n+1]=='W'){
                        wcounter++;
                    }else{bcounter++;}
                }
            }
            for(int l=0;l<4;l++){
                for(int r=0;r<4;r++){
                    if(board[j+2*l+1][k+2*r+1]=='B'){
                            wcounter++;
                    }else{bcounter++;}
                }
            }
            counter[j][k]=wcounter<bcounter?wcounter:bcounter;
            if(min>counter[j][k])
                min=counter[j][k];
        }
    }
    cout<<min<<endl;
}
