#define HEADSTUDENT HeadType
#define STUDENT ElementType
class HEADSTUDENT{
public:
    char nameclass[20];
    int number;
    char place[20];
};
class STUDENT{
public:
    char number[8];
    char name[8];
    char sex[3];
    int age;
    char place[20];
};

template<class ElementType>
class DoubleChainNode{
public:
    ElementType data;
    DoubleChainNode<ElementType> *prelink;
    DoubleChainNode<ElementType> *nextlink;
};
template <class HeadType>
class DoubleHeadNode{
public:
    HeadType Hdata;
    DoubleChainNode<ElementType> * first;
};
template<class HeadType,class ElementType>
class DoubleChainList{
private:
    DoubleHeadNode<HeadType> *HeadPtr;
public:
    DoubleChainList();
    ~DoubleChainList();
    int LengthDoubleChainList() const;
    void PutValueDoubleHeadNode(HeadType &HeadValue){
        HeadPtr->Hdata=HeadValue;           //使用值HeadValue给表头结点Hdata域赋值
    }
    DoubleHeadNode<HeadType> * GetHeadPtrDoubleChainList(){
        return *HeadPtr;
    }
    DoubleChainNode<ElementType> * GetFirstPtrDoubleChainList(){
        return HeadPtr->first;
    }
    //******查找函数
    bool GetElementDoubleChainList(int k,ElementType &result); //查找第k个元素并存放在result中
    bool GetElementDoubleChainList(DoubleChainNode<ElementType> *current,ElementType &rseult); //查找current指针指向元素
    DoubleChainNode<ElementType> * SearchElementDoubleChainList(int searchkey);
    //******插入函数
    bool InsertElementDoubleChainList(int k,ElementType & newvalue);   //插入值为newvalue的函数到第k个数据元素后
    //******删除函数
    bool DeleteElementDoubleChainList(int k); //删除双向链表中第k个元素
    void DestroyElementsDoubleChainList();    //删除双向链表中所有数据结点，并释放结点空间，保留表头结点
};
template <class HeadType,class ElementType>
DoubleChainList<HeadType,ElementType>::
DoubleChainList(){
    //构造函数，定义链表空间MaxSize，申请元素空间Element，定义链表长度初值length
    HeadPtr=new DoubleHeadNode<ElementType>;
    HeadPtr->first=nullptr;
}
template <class HeadType,class ElementType>
DoubleChainList<HeadType,ElementType>::
~DoubleChainList(){
    //析构函数，删除链表中所有数据结点及表头结点，并释放结点空间
    DoubleChainNode<ElementType>*current=HeadPtr->first;
    while(current){
        current=current->link;
        delete HeadPtr->first;
        HeadPtr->first=current;
    }
    delete HeadPtr;
}
template<class HeadType,class ElementType>
int DoubleChainList<HeadType,ElementType>::
LengthDoubleChainList()const{
    DoubleChainNode<ElementType> * current=HeadPtr->first;
    int len=0;
    while(current){
        len++;
        current=current->link;
    }
    return len;
}
template<class HeadType,class ElementType>
bool DoubleChainList<HeadType,ElementType>::
GetElementDoubleChainList(int k,ElementType &result){
    if(k<1)
        return false;
    DoubleChainNode<ElementType> *current=HeadPtr->first;
    int index=1;
    while(index<k&&current){
        current=current->link;
        index++;
    }
    if(current){
        result=current->data;
        return true;
    }
    return false;
}
template<class HeadType,class ElementType>
bool DoubleChainList<HeadType,ElementType>::
GetElementDoubleChainList(DoubleChainNode<ElementType> *current,ElementType &result){
    if(!current)
        return false;
    result=current->data;
    return true;
}
template<class HeadType,class ElementType>
DoubleChainNode<ElementType> * DoubleChainList<HeadType,ElementType>::
SearchElementDoubleChainList(int searchkey){
    DoubleChainNode<ElementType> *current=HeadPtr->first;
    while(current&&current->data.key!=searchkey){
        current=current->link;
    }
    if(current)
        return current;
    else
        return nullptr;
}

template<class HeadType,class ElementType>
bool DoubleChainList<HeadType,ElementType>::
InsertElementDoubleChainList(int k, ElementType &newvalue){
    //插入函数
    if(k<0)
        return false;
    int index=1;
    DoubleChainNode<ElementType> *current=HeadPtr->first;
    while(index<k&&current){
        index++;
        current=current->nextlink;
    }
    if(k>0&&!current)
        return false;
    DoubleChainNode<ElementType> *q=new DoubleChainNode<ElementType>;
    q->data=newvalue;
    if(k){
        //插入在current之后，current指向的是中间的结点或者最后的结点
        DoubleChainNode<ElementType> *p=current->nextlink;//current的下一个元素结点q
        q->nextlink=current->nextlink;
        q->prelink=current;
        if(p){
            p->prelink=q;
        }
        current->nextlink=q;
    }
    else{
        //作为第一个元素结点插入
        q->nextlink=HeadPtr->first;
        q->prelink=nullptr;
        DoubleChainNode<ElementType> *p=HeadPtr->first;
        if(p){
            p->prelink=q;
        }
        HeadPtr->first=q;
    }
    return true;
}
template<class HeadType,class ElementType>
bool DoubleChainList<HeadType,ElementType>::
DeleteElementDoubleChainList(int k){
    if(k<1||!HeadPtr->first)
        return false;
    DoubleChainNode<ElementType> *p;
    DoubleChainNode<ElementType> *current=HeadPtr->first;
    if(k==1){
        p=current->nextlink;
        if(p){
            p->prelink=nullptr;
        }
        HeadPtr->first=p;
    }
    else{
        DoubleChainNode<ElementType> *q=HeadPtr->first;
        for(int i=0;i<k&&q;i++){
            q=q->nextlink;  //q指向k-1个结点
        }
        if(!q){
            return false;
        }
        current=q;
        q=current->prelink;
        p=current->nextlink;
        q->nextlink=p;
        if(p)
            p->prelink=q;
    }
    delete current;
    return true;
}
template <class HeadType,class ElementType>
void DoubleChainList<HeadType,ElementType>::
DestroyElementsDoubleChainList(){
    DoubleChainNode<ElementType>*current=HeadPtr->first;
    while(current){
        current=current->link;
        delete HeadPtr->first;
        HeadPtr->first=current;
    }
    delete HeadPtr;
}
