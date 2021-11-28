#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    int n;
    char incha[25001][60];
    char outcha[25001][60];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>cha[i];
    }
    for (int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(strlen(cha[min])>strlen(cha[j]))
                min=j;
            else if(strlen(cha[min])==strlen(cha[j])){
                if(strcmp(cha[min],cha[j])==0){
                    min=j;
                }
                else{
                    string strmin(cha[min]);
                    string strj(cha[j]);
                    if(strmin.compare(strj)>0){
                        min=j;
                    }
                }
            }
        }
        strcpy(cha[20000],cha[min]);
        strcpy(cha[min],cha[i]);
        strcpy(cha[i],cha[20000]);
    }
    for(int i=0;i<n-1;i++){
        if(strcmp(cha[i],cha[i+1])==0){
            for(int j=i;j<n-1;j++)
                strcpy(cha[j],cha[j+1]);
            n--;
        }
    }
    for (int i=0;i<n;i++){
        cout<<cha[i]<<endl;
    }
    return 0;
}
