template<class QueueType>
class Queue{
private:
    QueueType * element;   //队列元素空间
    int front;
    int rear;
    int MaxSpaceSize;
public:
    Queue(int MaxQueueSize=20);
    ~Queue(){delete []element;}
    bool IsEmpty(){return rear==front;};
    bool IsFull(){return (front==(rear+1)%(MaxSpaceSize+1)?1:0);};
    bool GetFront(QueueType &result);
    bool GetRear(QueueType &result);
    int  GetFrontAddress(){return front;};
    int  GetRearAddress(){return rear;};
    int  GetMaxSpaceSize(){return MaxSpaceSize;};
    
    bool GetElement(int k,QueueType& result);
    bool EnQueue(QueueType &newvalue);  //进队，从rear所指的位置后面添加
    bool DeQueue(QueueType &result);    //出队，从front指针所指的后面一个位置取出数据
};
template<class QueueType>
Queue<QueueType>::
Queue(int MaxQueueSize){
    MaxSpaceSize=MaxQueueSize;
    element=new QueueType[MaxSpaceSize+1];
    front=0;
    rear=0;
}
template<class QueueType>
bool Queue<QueueType>::
GetFront(QueueType &result){
    //获取队头元素值，取出front指针后面一个位置的队列元素
    if(IsEmpty()) return false;
    result=element[(front+1)%(MaxSpaceSize+1)];
    return true;
}
template<class QueueType>
bool Queue<QueueType>::
GetRear(QueueType &result){
    //获取队尾元素的值，取出rear指针指向队列元素的值
    if(IsEmpty()) return false;
    result=element[rear];
    return true;
}
template<class QueueType>
bool Queue<QueueType>::
EnQueue(QueueType &newvalue){
    //newvalue存储到rear指针的下一个位置
    if(IsFull()) return false;
    rear=(rear+1)%(MaxSpaceSize+1);    //rear指针移动到下一个位置
    element[rear]=newvalue;
    return true;
}
template<class QueueType>
bool Queue<QueueType>::
DeQueue(QueueType &result){
    if(IsEmpty()) return false;
    front=(front+1)%(MaxSpaceSize+1);  //front指针移动到下一个位置
    result=element[front];             //result为刚刚出队的元素值
    return true;
}
template<class QueueType>
bool Queue<QueueType>::
GetElement(int k,QueueType& result)
{
    result=element[k];
    return true;
}
