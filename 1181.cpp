#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    char cha[20001][50];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>cha[i];
    }
    for (int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(strlen(cha[min])>strlen(cha[j]))
                min=j;
            else{
                if(strlen(cha[min])==strlen(cha[j])){
                    int checker=0;//if min is preorder:1, if j is preorder:2
                    for(int k=0;k<(int)strlen(cha[j]);k++){
                        if((int)cha[min][k]==(int)cha[j][k]){}
                        if((int)cha[min][k]<(int)cha[j][k]){
                            checker=1;
                            break;
                        }
                        if((int)cha[min][k]==(int)cha[j][k]){
                            checker=2;
                            break;
                        }                  
                    }
                    min=(checker==2)?j:min;
                }
            }
        }
        strcpy(cha[20000],cha[min]);
        strcpy(cha[min],cha[i]);
        strcpy(cha[i],cha[20000]);
    }
    for (int i=0;i<n;i++){
        cout<<cha[i]<<endl;
    }
}
