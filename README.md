# class-leader-election-system

## 前言
### 这是我读大学做的第一个课程设计
C语言大作业  
班干部选举系统  
完成于
### 2018.5.22

## 目录
* [前言](#前言)
* [开发环境](#开发环境)
* [实现功能](#实现功能)
    * [基本功能](#基本功能)
    * [扩展功能](#扩展功能)
    * [未实现功能](#未实现功能)
* [代码详情](#代码详情)
    * [打印所有候选人以及其得票数的函数](#打印所有候选人以及其得票数的函数)
    * [返回得票最多的人的序号](#返回得票最多的人的序号)
    * [获得最高票者](#获得最高票者)
* [总结](#总结)
    * [不足](#不足)
    * [收获](#收获)
    * [结语](#结语)
* [软件截图](#软件截图)

## 开发环境

* os：MacOS Sierra 10.12.6  
- IDE：Xcode  
* c语言标准：C99

## 实现功能

### 基本功能

* 设置候选人的总个数
- 记录各候选人的名字（为每个候选人自动生成一个编号）
* 显示候选人的编号和名称
- 设置要选举的人数
* 输入选票信息，若选票中候选人的个数大于要选举的人数，则作为无效票
- 统计总的选票数，有效票数，无效票数，每个候选人的得票数
* 输出获选人的姓名和得票数

### 扩展功能

* 对候选人的得票数进行排序输出

### 未实现功能

* 把选票信息、统计信息存入到不同文件中
- 把文件中的信息导入到程序中

## 代码详情

### 打印所有候选人以及其得票数的函数

    void showEveryone(char A[100][20],int count[100],int n){
      for (int i=0; i<n; i++) {
        printf("%d:  %s   得票:  %d\n",i+1,A[i],count[i]);
      }
    }
    
### 返回得票最多的人的序号

    int maxPeople(int count[100],int n){                    
      int j=0;
      int max=0;   
      for (int i=0; i<n; i++) {
        if (count[i]>max) {
          max=count[i];
          j=i;
        }
      }                                              //找出最高票，记录序号
      for (int i=0; i<100; i++) {
        if (max==count[i]&&i!=j) {
          return -1;                                 //如果最高票有两个就返回-1
        }
      }
      return j; 
    }
    
### 获得最高票者
 
     if ((a=maxPeople(count,n))>=0) {                 //输出获选人的姓名和得票数
       printf("获选人为： %s\n",A[a]);
       printf("得票：  %d\n",count[a]);
     }
     else{
       printf("最高票为多人，请重新打开程序重新选举\n");
       return 0;
     }

## 总结

### 不足

* 不会操作文件

### 收获

* 对C语言运用更加熟练了

### 结语

### 这份简简单单的C语言作业可能是我梦的起点
 
当时大一是用pages写的文档  
现在时间是
### 2020.2.13  
### 大三的超长寒假  
我把这份代码和说明书从电脑的文件夹里找出来,用github的README语法重新写一遍，记录可能将成为漫长代码生涯或者说是追梦历程的一个起点。
 
 ## 软件截图
