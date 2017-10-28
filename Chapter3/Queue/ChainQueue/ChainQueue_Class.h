//front始终指向队列队头结点，rear始终指向队列队尾结点，
//一般不存在队满问题除非存储空间全部耗尽,front rear全为空时链表为空

template<class ElementType>
class ChainQueue{
private:
    ChainNode<ElementType> *front;
    ChainNode<ElementType> *rear;
public:
    ChainQueue(){front=NULL;rear=NULL;};
    ~ChainQueue();
    bool IsEmpty(){return front==NULL;};
    bool GetFront(ElementType &result);
    bool GetRear(ElementType &result);
    bool EnQueue(ElementType &newvalue);
    bool DeQueue(ElementType &result);
};
template<class ElementType>
ChainQueue<ElementType>::
~ChainQueue(){
    ChainNode<ElementType> *nextptr;
    while(front){
        nextptr=front->link;
        delete front;
        front=nextptr;
    }
}

template<class ElementType>
bool ChainQueue<ElementType>::
GetFront(ElementType &result){
    //获取队列队头元素值
    if(IsEmpty()) return false;
    result=front->data;
    return true;
}
template<class ElementType>
bool ChainQueue<ElementType>::
GetRear(ElementType &result){
    //获取队列队尾元素值
    if(IsEmpty()) return false;
    result=rear->data;
    return true;
}
template<class ElementType>
bool ChainQueue<ElementType>::
EnQueue(ElementType &newvalue){
    //将一个新元素值newvalue的结点插入作为链表最后一个结点
    ChainNode<ElementType> *p=new ChainNode<ElementType>;
    p->data=newvalue;
    p->link=NULL;
    if(front)
        rear->link=p;  //队列非空时链在队尾结点后
    else
        front=p;       //否则指向进队结点
    rear=p;
    return true;
}
template<class ElementType>
bool ChainQueue<ElementType>::
DeQueue(ElementType &result){
    if(IsEmpty()) return false;
    result=front->data;
    ChainNode<ElementType> *p=front;
    front=front->link;
    delete p;
    return true;
}
