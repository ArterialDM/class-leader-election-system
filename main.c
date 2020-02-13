//  main.c
//  班干选举系统
//  Created by 王栋铭 on 2018/5/21.
//  Copyright © 2018年 王栋铭. All rights reserved.

#include <stdio.h>

void showEveryone(char A[100][20],int count[100],int n);
int maxPeople(int count[100],int n);
int findMax(int count[100],int n);

int main() {
  
    int i,a;
    int n;         //候选人 
    int number;     //选举总人数 
    char A[100][20];              //最多存100人
    int count[100];
    
    printf("请输入候选人总人数\n");
    scanf("%d",&n);
    if (n>100) {
        printf("超过最大人数，请重新打开程序");
        return 0;
    }
    printf("请逐个输入候选人\n");
    for (i=0; i<n; i++) {
        scanf("%s",A[i]);
    }                                   //记录完毕，数组下标为那个人的编号
    printf("记录完毕\n");
    showEveryone(A,count,n);  
    printf("设置要参加选举的人数\n");
    scanf("%d",&number);
    for (i=0; i<number; i++) {
        showEveryone(A,count,n);
        printf("请输入这一票要投给的人，在下一行输入此人的序号\n");
        scanf("%d",&a);
        if (a>n) {
            printf("非法输入，请重新打开程序");
            return 0;
        }  
        count[a-1]=count[a-1]+1;   
    }  
    printf("投票结束\n"); 
    if ((a=maxPeople(count,n))>=0) {                        //输出获选人的姓名和得票数     
        printf("获选人为： %s\n",A[a]);
        printf("得票：  %d\n",count[a]);
    }
    else{
        printf("最高票为多人，请重新打开程序重新选举\n");
        return 0;
    } 
    printf("总的选票数为:  %d\n",number);
    printf("有效票数为:  %d\n",count[a]);
    printf("无效票数为:  %d\n",number-count[a]);
    showEveryone(A, count, n);
    printf("以下为得票排名\n");
    for (int i=0; i<n; i++) {    
        a=findMax(count,n);
        printf("%d:  %s   得票:  %d\n",i+1,A[a],count[a]);
        count[a]=-1;             //对已经返回的序号做记号
   } 
    return 0;
}

void showEveryone(char A[100][20],int count[100],int n){             //打印所有候选人
    for (int i=0; i<n; i++) { 
        printf("%d:  %s   得票:  %d\n",i+1,A[i],count[i]);
    }
}

int maxPeople(int count[100],int n){                   //返回序号
    
    int j=0;
    int max=0;
    
    for (int i=0; i<n; i++) {
        if (count[i]>max) {
            max=count[i];
            j=i;
        }
    }                                    //找出最高票，记录序号
    for (int i=0; i<100; i++) {
        if (max==count[i]&&i!=j) {
            return -1;                  //如果最高票有两个就返回-1
        }
    }
    return j;  
}

int findMax(int count[100],int n){

    int j=0;
    int max=-1;
    
    for (int i=0; i<n; i++) {
        if (count[i]>max) {
            max=count[i];
            j=i;
        }
    }
    return j;  
}
