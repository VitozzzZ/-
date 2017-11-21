#include "main.hpp"
#include<iostream>
using namespace std;

struct MAP{
    int AreaIndex;
    char AreaName[20];
    int ColorIndex;
};
class StackType{
public:
    int AreaIndex;
    int ColorIndex;
};
void MapColor(int r[8][8],int n,Stack<StackType>&S){
    int MaxStackSize=20;
    Stack<StackType>Skeep(MaxStackSize);
    StackType x,temp;
    bool flag;
    
    int currentArea=1;
    int currentColor=1;
    x.AreaIndex=currentArea;
    x.ColorIndex=currentColor;
    S.Push(x);
    currentArea++;
    while(currentArea<=n){
        flag=true;   //flag为真表示与堆栈中已染色的区域比较时未发现重色
        while(!S.IsEmpty()&&flag){
            S.Pop(x);
            Skeep.Push(x);
            if(x.ColorIndex==currentColor&&r[currentColor][x.AreaIndex])
                flag=false;
        }
        if(flag){
            //与已染色区域比较，无一同色
            //将当前区域号及使用的颜色进栈，并准备下一个区域号，从颜色1开始尝试
            x.AreaIndex=currentArea;
            x.ColorIndex=currentColor;
            while(!Skeep.IsEmpty()){
                Skeep.Pop(temp);
                S.Push(temp);
            }
            S.Push(x);
            cout<<"【进栈】"<<endl;
            currentColor=1;
            currentArea++;
        }
        else{
            currentColor++;
            while(!Skeep.IsEmpty()){
                Skeep.Pop(temp);
                S.Push(temp);
            }
            while(currentColor>4){
                S.Pop(x);
                cout<<"【出栈】"<<endl;
                currentColor=x.ColorIndex+1;
                currentArea=x.AreaIndex;
            }
            flag=true;
        }
    }
}
