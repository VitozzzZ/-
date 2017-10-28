#include <stdio.h>
template<class ElementType>
class SimulastionChainNode{
public:
    ElementType data;
    int link;
};

template<class ElementType>
class SimulationChainSpace;  //声明

template<class ElementType>
class SimulationChainList{
    //定义基于模拟链表空间的简单链表类
public:
    SimulationChainList(){first=-1;};
    ~SimulationChainList(){DestroySimulationChainList();};
    int LengthSimulationChainList() const;
    void DestroySimulationChainList();
    int GetFirstPtrSimulationChainList(){return first;};   //获取模拟链表表头结点指针first
    int GetAvailablePtrSimulationChainSpace(){return SimSpace.availableptr;}; //获取可用空间链表表头结点指针availableptr
    bool GetElementSimulationChainList(int k,ElementType &result);  //查找第k个元素，存放在result中
    bool SearchElementSimulationChainList(int SearchKey,ElementType &result); //查找关键字为SearchKey的元素存放在result中
    bool InsertElementSimulationChainList(int k,ElementType &newvalue); //插入值为newvalue的数据元素到第k个元素后面
    bool DeleteElementSimulationChainList(int k,ElementType &result); //删除第k个元素，其值存放到result中带回
private:
    int first;
    static SimulationChainSpace<ElementType> SimSpace;   //对象的继承；第二次修改SimSpace时第一次修改的内容也在
    
};
template<class ElementType>
void SimulationChainList<ElementType>::
DestroySimulationChainList(){
    //删除简单链表的所有结点
    int current;
    while(first!=-1){
        current=SimSpace.node[first].link;
        SimSpace.DeleteNodeSimulationChainSpace(first);
        first=current;
    }
}
template<class ElementType>
int SimulationChainList<ElementType>::
LengthSimulationChainList()const{
    //求模拟链表的长度
    int current=first;
    int len=0;
    while(current!=0){
        current=SimSpace.node[current].link;
        len++;
    }
    return len;
}
template<class ElementType>
bool SimulationChainList<ElementType>::
InsertElementSimulationChainList(int k, ElementType &newvalue){
    //插入值为newvalue的数据元素到第k个元素后面
    if(k<0||GetAvailablePtrSimulationChainSpace()==-1)
        return false;
    int current=first;
    for(int index=1;index<k&&current!=-1;index++)
        current=SimSpace.node[current].link;
    if(k>0&&current==-1)
        return false;
    int q=SimSpace.NewNodeSimulationChainSpace();
    SimSpace.node[q].data=newvalue;
    if(k){
        //插入在第k个结点之后
        SimSpace.node[q].link=SimSpace.node[current].link;
        SimSpace.node[current].link=q;
    }
    else{
        //作为首元素插入
        SimSpace.node[q].link=first;
        first=q;
    }
    return true;
}
template<class ElementType>
bool SimulationChainList<ElementType>::
DeleteElementSimulationChainList(int k, ElementType &result){
    //删除第k个元素，其值存放到result中带回
    if(k<1||first==-1)
        return false;
    int current=first;
    if(k==1)
        first=SimSpace.node[first].link;
    else{
        //用q指向第k个结点的直接前驱
        int q=first;
        for(int i=0;i<k-1;i++)
            q=SimSpace.node[q].link;
        if(q==-1||SimSpace.node[q].link==-1)
            return false;
        current=SimSpace.node[q].link;
        SimSpace.node[q].link=SimSpace.node[current].link;
    }
    result=SimSpace.node[current].data;
    SimSpace.DeleteNodeSimulationChainSpace(current);
    return true;
}



template<class ElementType>
class SimulationChainSpace{
    //定义顺序存储结构模拟链表空间类SimulationChainSpace
    friend SimulationChainList<ElementType>;
public:
    SimulationChainSpace(int MaxSpaceSize=25);
    ~SimulationChainSpace(){delete []node;};
    int NewNodeSimulationChainSpace();            //模拟链表分配结点空间，相当于C++的new运算
    void DeleteNodeSimulationChainSpace(int &i);  //模拟链表释放结点空间，相当于C++的delete运算
private:
    SimulastionChainNode<ElementType> * node;  //指向数组(存储池)的指针
    int MaxSpaceSize;                          //存储池大小
    int availableptr;                          //指向存储池链表的第一个结点
};
template<class ElementType>
SimulationChainSpace<ElementType>::
SimulationChainSpace(int SimSpaceSize){
    MaxSpaceSize=SimSpaceSize;
    node=new SimulastionChainNode<ElementType>[MaxSpaceSize];
    availableptr=0;
    for(int i=0;i<MaxSpaceSize-1;i++)
        node[i]->link=i+1;               //i下标的空间链接到下一个空间
    node[MaxSpaceSize-1]->link=-1;       //最后一个空间的链接为-1
}
template<class ElementType>
int SimulationChainSpace<ElementType>::
NewNodeSimulationChainSpace(){
    //申请一个结点空间
    if(availableptr==-1)
        return -1;
    int i=availableptr;              //分配第一个结点空间
    availableptr=node[i]->link;       //availableptr指向下一个可用结点空间
    return i;
}
template <class ElementType>
void SimulationChainSpace<ElementType>::
DeleteNodeSimulationChainSpace(int &i){
    //删除下标为i元素的结点空间：将被删结点作为一个可用结点插入到可用结点链表availaptr中，作为第一个结点
    node[i]->link=availableptr;
    availableptr=i;
    i=-1;    //i置为不可用值
}
