#include <iostream>
using namespace std;

int main(){
    int total_num,total_weight;
    cin>>total_num>>total_weight;
    int bag[total_num][total_weight];
    for (int i=0;i<total_num;i++){
        for(int j=0;j<total_weight;j++){
            int cur_weight,cur_value;
            cin>>cur_weight>>cur_value;
            if(cur_weight>total_weight){
                if(j!=0)
                    bag[i][j]=bag[i][j-1];
                else
                    bag[i][j]=0;
            }
            else if(i!=0){
                if(bag[i-1][j]>bag[i][j-cur_weight]+cur_value)
                    bag[i][j]=bag[i-1][j];
                else
                    bag[i][j]=bag[i][j-cur_weight]+cur_value;
            }
            else
                bag[i][j]=bag[i][j-cur_weight]+cur_value;
        }
    }
    int max=0;
    for (int i=0;i<total_num;i++){
        for(int j=0;j<total_weight;j++){
            if(max<bag[i][j])
                max=bag[i][j];
        }
    }
    cout<<max<<endl;
}


