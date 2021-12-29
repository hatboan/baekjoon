#include <iostream>
using namespace std;
int now=0;

void z(int x,int y,int tar_x,int tar_y,int divided){
  if(divided==2){
    if(x==tar_x&&y==tar_y)
      printf("%d\n",now++);
    else
      now++;
    if(x==tar_x-1&&y==tar_y)
      printf("%d\n",now++);
    else
      now++;
    if(x==tar_x&&y==tar_y-1)
      printf("%d\n",now++);
    else
      now++;
    if(x==tar_x-1&&y==tar_y-1)
      printf("%d\n",now++);
    else
      now++;
  }
  else{
    int newdiv=divided/2;
    z(x,y,tar_x,tar_y,newdiv);
    z(x+newdiv,y,tar_x,tar_y,newdiv);
    z(x,y+newdiv,tar_x,tar_y,newdiv);
    z(x+newdiv,y+newdiv,tar_x,tar_y,newdiv);
  }
}

int main(){
  int n,r,c,l,k;
  scanf("%d %d %d",&n,&r,&c);
  z(0,0,c,r,2<<n);
}
