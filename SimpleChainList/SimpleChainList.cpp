#include <cstring>
#include "SimpleChainList.hpp"

//-----数据元素结构定义
template <class ElementType>
class SimpleChainNode{
    //简单链表数据元素节点结构类定义
public:
    ElementType data;
    SimpleChainNode<ElementType> * link;
};
template <class Headtype>
class SimpleHeadNode{
    //简单链表表头数据元素节点结构类定义
public:
    HeadType Hdata;
    SimpleChainNode<class ElementType> * first;
};

//-----SimpleChainList定义
template <class HeadType,class ElementType>
class SimpleChainList{
    //线性表链式存储结构—————简单链表模板类SimpleChainList的定义
public:
    SimpleChainList();
    ~SimpleChainList();
    int LengthSimpleChainList()const;  //求简单链表长度
    void PutValueSimpleHeadNode(HeadType &headValue){
        //用已知值headValue给表头节点Hdata赋值
        HeadPtr->Hdata=headValue;
    }
    SimpleHeadNode<HeadType> * GetHeadPtrSimpleChainList(){
        return HeadPtr;           //返回链表表头的指针HeadPtr
    }
    SimpleChainNode<ElementType> * GetFirstPtrSimpleChainList(){
        return HeadPtr->first;    //获取简单链表中第一个结点指针first
    }
    //*******查找函数
    bool GetElementSimpleChainList(int k,ElementType &result);  //查找第k个元素，存入result中
    bool GetElementSimpleChainList(SimpleChainNode<ElementType>*current,ElementType &result); //多态
    SimpleChainNode<ElementType> * SearchElementSimpleChainList(int searchkey);
    SimpleChainNode<ElementType> * SearchElementSimpleChainList(char * searchkey);
    //*******插入和删除函数
    bool InsertElementSimpleChainList(int k,ElementType &newvalue);//插入值为newvalue的元素到第k个元素后
    bool InsertElementFrontSimpleChainList(ElementType &newvalue,SimpleChainNode<ElementType>* InsertPtr);
    //插入值为newvalue的元素到简单链表中InsertPtr指针所指的元素之前
    bool DeleteElementSimpleChainList(int k);  //删除简单链表中第k个数据元素
    bool DeleteElementSimpleChainList(SimpleChainNode<ElementType>* DeletePtr);//删除简单链表中DeletePtr指针指向的元素
    //*******应用函数
    void DestroyElementSimpleChainList();  //删除简单链表中所有的数据结点并释放结点空间，保留表头结点
    void DesplaySimpleChainList(SimpleChainList<HeadType,ElementType>&AppList); //输出简单链表所有元素的值
    void DisplayElementSimpleChainList(ElementType result);   //输出result的值
private:
    SimpleHeadNode<HeadType> * HeadPtr;
};

template <class HeadType,class ElementType>
SimpleChainList<HeadType,ElementType>::
SimpleChainList(){
    //构造函数，定义链表空间MaxSize，申请元素空间Element，定义链表长度初值length
    HeadPtr=new SimpleHeadNode<ElementType>;
    HeadPtr->first=NULL;
}
template <class HeadType,class ElementType>
SimpleChainList<HeadType,ElementType>::
~SimpleChainList(){
    //析构函数，删除链表中所有数据结点及表头结点，并释放结点空间
    SimpleChainNode<ElementType> * current;
    current=HeadPtr->first;
    while(current){
        current=current->link;
        delete HeadPtr->first;
        HeadPtr->first=current;
    }
    delete HeadPtr;
}
template <class HeadType,class ElementType>
int SimpleChainList<HeadType,ElementType>::
LengthSimpleChainList()const{
    SimpleChainNode<ElementType> * current=HeadPtr->first;
    int len=0;
    while(current){
        len++;
        current=current->link;
    }
    return len;
}
template <class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
GetElementSimpleChainList(int k, ElementType &result){
    //将简单链表第k个元素值取至result中带回
    if(k<1)
        return false;
    SimpleChainNode<ElementType> *current=HeadPtr->first;
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
template <class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
GetElementSimpleChainList(SimpleChainNode<ElementType> *current, ElementType &result){
    if(!current)
        return false;
    result=current->data;
    return true;
}
template <class HeadType,class ElementType>
SimpleChainNode<ElementType> * SimpleChainList<HeadType,ElementType>::
SearchElementSimpleChainList(int searchkey){
    //在简单链表中查找关键字为searckey（年龄）的元素，如果找到返回元素所在地址，找不到返回NULL
    SimpleChainNode<ElementType> *current=HeadPtr->first;
    while(current&&current->data.key!=searchkey){
        current=current->link;
    }
    if(current)
        return current;
    else
        return NULL;
}
template <class HeadType,class ElementType>
SimpleChainNode<ElementType> * SimpleChainList<HeadType,ElementType>::
SearchElementSimpleChainList(char *searchkey){
    SimpleChainNode<ElementType> *current=HeadPtr->first;
    while(current&&!strcmp(current->data.key1,searchkey)){
        current=current->link;
    }
    if(current)
        return current;
    else
        return NULL;
}
template <class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
InsertElementSimpleChainList(int k, ElementType &newvalue){
    //在简单链表的第k个数据元素之后插入新元素，值为newvalue 先查找curren，再插入
    if(k<0)
        return false;
    int index=1;
    SimpleChainNode<ElementType> * current=HeadPtr->first;
    while(index<k&&current){
        index++;
        current=current->link;
    }
    if(k>0&&!current)
        return false;
    SimpleChainNode<ElementType> * q=new SimpleChainNode<ElementType>;
    q->data=newvalue;
    if(k){
        //插在current之后
        q->link=current->link;
        current->link=q;
    }
    else{
        //作为第一个元素结点插入
        q->link=HeadPtr->first;
        HeadPtr->first=q;
    }
    return true;
}
template <class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
InsertElementFrontSimpleChainList(ElementType &newvalue, SimpleChainNode<ElementType> *InsertPtr){
    //在简单链表InsertPtr之前插入元素
    if(!InsertPtr)
        return false;
    SimpleChainNode<ElementType> * current=HeadPtr->first;
    if(InsertPtr!=HeadPtr->first){
        while(current&&current->link!=InsertPtr){
            current=current->link;  //跳出循环时current指向的数据结点为InsertPtr指向数据结点的直接前驱
        }
        if(!current)
            return false;
    }
    SimpleChainNode<ElementType> * q=new SimpleChainNode<ElementType>;
    q->data=newvalue;
    if(InsertPtr==HeadPtr->first){
        //作为第一个元素结点插入
        q->link=HeadPtr->first;
        HeadPtr->first=q;
    }
    else{
        q->link=current->link;
        current->link=q;
    }
    return true;
}
template <class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
DeleteElementSimpleChainList(int k){
    //删除第k个数据元素
    if(k<1||!HeadPtr->first){
        return false;
    }
    SimpleChainNode<ElementType> * current=HeadPtr->first;
    if(k==1){
        //删除第一个元素
        HeadPtr->first=current->link;
    }
    else{
        SimpleChainNode<ElementType> * q=HeadPtr->first;
        for(int index=1;index<k-1&&q;index++){
            q=q->link; //q指向k-1个结点
        }
        if(!q||!q->link)
            return false;
        current=q->link; //current指向第k个结点
        q->link=current->link;
    }
    delete current;
    return true;
}
template <class HeadType,class ElementType>
bool SimpleChainList<HeadType,ElementType>::
DeleteElementSimpleChainList(SimpleChainNode<ElementType> *DeletePtr){
    //删除链表中DeletePtr所指向的元素
    if(!HeadPtr->first)
        return false;
    if(DeletePtr==HeadPtr->first){
        //DeletePtr指向第一个元素结点
        HeadPtr->first=DeletePtr->link;
    }
    else{
        //找出指向DeletePtr前面的元素结点的指针q
        SimpleChainNode<ElementType> * q=HeadPtr->first;
        while(q->link!=DeletePtr&&q){
            q=q->link;
        }
        if(!q)
            return false;
        q->link=DeletePtr->link;
        delete DeletePtr;
    }
    return true;
}
