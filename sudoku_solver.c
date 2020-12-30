#include <stdio.h>
int ban[9][9]={{0,5,0,2,9,0,0,6,0,},
               {0,0,0,3,0,0,0,4,0,},
               {0,0,0,0,0,4,0,0,7,},
               {5,2,0,0,0,0,1,0,4,},
               {0,0,0,0,7,2,0,0,0,},
               {0,3,0,0,0,0,0,0,5,},
               {2,0,0,0,0,6,0,9,0,},
               {7,0,0,0,0,0,5,0,0,},
               {6,1,0,0,0,0,2,0,0,}};
int a[10]={};

void hyouji(){
  int i,y;
  for(i=0;i<9;i++){
    printf("\n");
    for(y=0;y<9;y++)
      printf("%d",ban[i][y]);
    }
    printf("\n");
}

int replace(int at){
	if(6<=at)at=6;
	else if(3<=at)at=3;
	else at=0;
	return at;
}

void judge(int t,int y){
  if(t==9){hyouji();return;}
  int i=0,ct=0,a[10]={},k[5]={},o,h,w,j;

  while(i<9){a[ban[t][i]]=ban[t][i];a[ban[i][y]]=ban[i][y]; ++i;}

  w=replace(t);
  j=replace(y);


  for(o=w;o<w+3;o++){
    for(h=j;h<j+3;h++)
      a[ban[o][h]]=ban[o][h];
  }

 i=1;while(i<10){if(a[i++]==0){ct=ct+1;k[ct]=i-1;}};

if(ban[t][y]==0 && ct==0)return;
if(ban[t][y]!=0)ct=0;

switch(ct){
   case 0:
    if(y==8){judge(t+1,0);}
    else judge(t,y+1);
   break;
   default:
    i=1;while(i<=ct){ban[t][y]=k[i++];if(y==8)judge(t+1,0);else judge(t,y+1);ban[t][y]=0;}
   break;
}

}

int main(void){
    judge(0,0);
    return 0;
}
