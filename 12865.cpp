#include <iostream>
using namespace std;

int main(){
    int total_num,total_weight;
    cin>>total_num>>total_weight;
    bag[total_num][total_weight];
    for (int i=0;i<total_num;i++){
        for(int j=0;j<total_weight;j++){
            int cur_weight,cur_value;
            cin>>cur_weight>>cur_value;
            if(cur_weight>total_weight){
                bag[i][j]=bag[i][j-1];
            }
        }
    }
}

//not done yet

