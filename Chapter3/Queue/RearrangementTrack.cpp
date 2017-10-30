#include "Header.h"
#include <iostream>
using namespace std;

class ElementType{
public:
    int CarriageNumber;
};
bool Hold(Queue<ElementType>QueueHold[],
          int CarriageQuantity,int HoldQueueQuantity,
          int &MinHold,int MinQueue,int &NowOut,int &current){
    //为车厢current寻找最优缓冲轨道，如果没有，则返回false，否则返回true
    int BestCushion=-1;  //最优缓冲队列编号，为-1表示还未找到最优缓冲铁轨
    int BestLast=-1;     //BestLast保存BestCushion中最后一节车厢的编号
    ElementType temp;    //进队出队车厢的编号变量
    for(int i=0;i<HoldQueueQuantity;i++){
        //扫描所有缓冲铁轨，寻找最佳缓冲铁轨存放编号current的车厢
        if(!QueueHold[i].IsEmpty()){
            //缓冲铁轨i不空，寻找最佳缓冲铁轨存放编号current的车厢
            QueueHold[i].GetRear(temp);  //取得当前i号缓冲铁轨中最后一节车厢编号
            if(current>temp.CarriageNumber&&temp.CarriageNumber>BestLast){
                //比较队尾车厢编号较大且小于current的车厢
                BestLast=temp.CarriageNumber;
                BestCushion=i;
            }
        }
        else
            //current无法进入已使用的缓冲队列，进入未使用的缓冲铁轨i
            if(BestCushion==-1) BestCushion=i;
    }
    if(BestCushion==-1){
        //扫描所有缓冲铁轨，无可用的缓冲铁轨，无法调度，失败
        cout<<"wrong!!!缓冲铁轨不足，无法调度，失败!"<<endl;
        return false;
    }
    temp.CarriageNumber=current;
    QueueHold[BestCushion].EnQueue(temp);  //current进入BestCushion队列中
    cout<<"从入轨将"<<current<<"号车厢移到最优缓冲铁轨"<<BestCushion<<endl;
    if(current<MinHold){
        MinHold=current;
        MinQueue=BestCushion;
    }
    return true;
}

void Output(Queue<ElementType> *QueueHold,
            Queue<ElementType> &QueueIn,
            Queue<ElementType> &QueueOut,
            int CarriageQuantity,int HoldQueueQuantity,
            int &MinHold,int MinQueue,int &Nowout){
    //从MinQueue中输出最小车厢MinHold，并寻找新的最小的MinHold和MinQueue
    int current;
    ElementType temp;
    QueueHold[MinQueue].DeQueue(temp);
    cout<<"从"<<MinQueue<<"号缓冲铁轨输出"<<MinHold<<"号车厢到出轨"<<endl;
    MinHold=CarriageQuantity+1;
    for(int i=0;i<HoldQueueQuantity;i++){
        //比较所有所有缓冲队列中队头元素，寻找新的MinHold和MinQueue
        QueueHold[i].GetFront(temp);
        current=temp.CarriageNumber;
        if(!QueueHold[i].IsEmpty()&&current<MinHold){
            MinHold=current;
            MinQueue=i;
        }
    }
}

bool RearrangementTrack(int CarriageNumber[],
                        int CarriageQuantity,
                        int HoldQueueQuantity){
    //车厢初始排列为CarriageNumber[1:n],如果重排成功返回true，否则返回false
    int MaxQueueSize=20;
    ElementType result;
    Queue<ElementType>QueueIn(MaxQueueSize);
    for(int i=1;i<=CarriageQuantity;i++){
        //对入轨上的队列QueueIn进行初始化，数据来自于CarriageNumber[]
        result.CarriageNumber=CarriageNumber[i];
    }
    Queue<ElementType>QueueOut(MaxQueueSize);
    Queue<ElementType> *QueueHold=new Queue<ElementType>[HoldQueueQuantity];
    int Nowout=1;
    int MinHold=CarriageQuantity+1;
    int MinQueue=0;
    for(int i=1;i<CarriageQuantity;i++){
        //重排车厢
        QueueIn.DeQueue(result);
        if(result.CarriageNumber==Nowout){
            //当前入轨出队的车厢可直接到出轨，直接输出
            cout<<"从入轨输出"<<result.CarriageNumber<<"号车厢到出轨"<<endl;
            QueueOut.EnQueue(result);
            if(Nowout!=CarriageQuantity)
                Nowout++;
            while(MinHold==Nowout){
                //从缓冲铁轨输出MinHold
                result.CarriageNumber=MinHold;
                QueueOut.EnQueue(result);
                Output(QueueHold, QueueIn, QueueOut, CarriageQuantity, HoldQueueQuantity, MinHold, MinQueue, Nowout);
                if(Nowout!=CarriageQuantity)
                    Nowout++;
            }
        }
        else{
            //将result.CarriageNumber送入某个缓冲铁轨
            if(!Hold(QueueHold,CarriageQuantity,HoldQueueQuantity,MinHold,MinQueue,Nowout,result.CarriageNumber))
               return false;
        }
    }
    return true;
}
