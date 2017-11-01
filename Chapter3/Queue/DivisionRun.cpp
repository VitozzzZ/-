#include "Header.h"

struct PROJECT{
    int ProjectNumber;  //项目编号
    char name[8];       //项目名称
    char place[20];     //项目地址
    int set;            //划分后所属子集编号
};

class QueueType{
public:
    int ProjectNumber;
};
template<class PROJECT>
class Division{
public:
    Division(int MaxListSize=20);
    ~Division(){delete []element;};
    void DivisionRun(int r[10][10],PROJECT*Projects,int ProjectCount);
private:
    PROJECT * element;
    int length;
    int MaxSpaceSize;
};
template<class PROJECT>
Division<PROJECT>::
Division(int MaxListSize){
    MaxSpaceSize=MaxListSize;
    element=new PROJECT[MaxSpaceSize];
    length =0;
}
template<class PROJECT>
void Division<PROJECT>::
DivisionRun(int r[10][10],PROJECT*Projects,int ProjectCount){
    int rearkeep;   //队尾保持指针变量，用于判断分一个子集时队列元素是否全部出队
    int current;    //项目编号变量
    int setindex;   //子集编号变量
    int MaxQueueSize=ProjectCount+1;
    int i;
    QueueType x;
    Queue<QueueType>Q(MaxQueueSize); //创建一个队列实例Q
    for(i=1;i<=ProjectCount;i++){
        //项目编号进队，初始化队列
        x.ProjectNumber=Projects[i].ProjectNumber;
        Q.EnQueue(x);
    }
    setindex=0;
    setindex++;
    while(!Q.IsEmpty()){
        rearkeep=Q.GetRearAddress();
        Q.DeQueue(x);
        current=x.ProjectNumber;
        for(i=1;i<=ProjectCount;i++)
            if(setindex==Projects[i].set&&r[current][i]){
                //current项目与已经进入当前子集的第i号项目发生冲突
                x.ProjectNumber=current;
                Q.EnQueue(x);   //current项目重新进队
                break;
            }
        if(i>ProjectCount)
            Projects[current].set=setindex;
    }
    setindex++;
}

