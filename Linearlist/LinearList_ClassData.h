//顺序存储线性表存储结构模板类头文件linearlist_Class.h如下
template<class ElementType>
class Linearlist{
    //定义顺序存储结构线性表存储结构模板类，线性表数据存放于element[0..length-1]
public:
    Linearlist(int MaxListSize=10);    //构造函数
    ~Linearlist(){delete []element;}   //析构函数
    int LengthLinearList(){return length;}  //求顺序存储线性表的长度
    bool GetElementAddressLinearList(){return element;}  //返回element空间的首地址
    bool GetElementLinearList(int k,ElementType &result);//查找第k个元素，存入result中
    int SearchElementLinearList(char * searchkey);  //查找值为searchkey（字符类型）的元素，返回元素下标
    int SearchElementLinearList(int searchkey);     //查找值为searchkey（数值型）的元素，返回元素下标
    bool InsertElementLinearList(int k,ElementType &newvalue); //插入值为newvalue元素到第k个线性元素之后
    bool DeleteElementLinearList(int k);            //删除线性表中第k个元素
    void DisplayElementLinearList(ElementType result); //显示输出数据元素的值
    void DisplayElementLinearList(Linearlist<ElementType>&AppList); //显示输出线性表中所有数据元素的值
    
private:
    ElementType *element;
    int length;
    int MaxSpaceSize;
};

template<class ElementType>
Linearlist<ElementType>::
Linearlist(int MaxListSize){
    //构造函数，定义线性表空间大小MaxListSize，申请元素空间element，定义长度初值length
    MaxSpaceSize=MaxListSize;
    element=new ElementType[MaxSpaceSize];
    length=8;
}

template<class ElementType>
bool Linearlist<ElementType>::
GetElementLinearList(int k,ElementType &result){  //查找第k个元素，存入result中
    if(k<1||k>length) return false;
    result=element[k-1];
    return true;
}

template<class ElementType>
int Linearlist<ElementType>::
SearchElementLinearList(char *searchkey){    //查找值为searchkey（字符类型）的元素，返回元素下标
    for(int i=0;i<length;i++){
        if(!strcmp(element[i].place,searchkey))  //s1=s2 strcmp()返回值为0
            return i;
    }
    return -1;
}

template<class ElementType>
int Linearlist<ElementType>::
SearchElementLinearList(int searchkey){     //查找值为searchkey（数值型）的元素，返回元素下标
    for(int i=0;i<length;i++){
        if(element[i].key==searchkey)
            return i;
    }
    return -1;
}

template<class ElementType>
bool Linearlist<ElementType>::
InsertElementLinearList(int k, ElementType &newvalue){    //插入值为newvalue元素到第k个线性元素之后
    if(k<1||k>length||length==MaxSpaceSize)
        return false;
    for(int i=length-1;i>=k;i--)
        element[i+1]=element[i];    //插入点后的元素往后移动一格
    element[k]=newvalue;
    length++;
    return true;
}

template<class ElementType>
bool Linearlist<ElementType>::
DeleteElementLinearList(int k){
    if(k<1||k>length)
        return false;
    for(int i=k;i<length;i++)
        element[i-1]=element[i];
    length--;
    return true;
}

//3----主程序应用函数的定义
template<class ElementType>
void Linearlist<ElementType>::
DisplayElementLinearList(ElementType result){  //输出线性表中第k个数据元素
    cout<<result.number<<"     ";
    cout<<result.name<<"     ";
    cout<<result.sex<<"     ";
    cout<<result.age<<"     ";
    cout<<result.place<<"     ";
}


template<class ElementType>
void Linearlist<ElementType>::
DisplayElementLinearList(Linearlist<ElementType> &AppList){
    ElementType result;
    cout<<"      number  name  sex  age  place"<<endl;
    cout<<"      ------  ----  ---  ---  -----"<<endl;
    for(int i=1;i<=AppList.LengthLinearList();i++){
        cout<<element[i];
        AppList.GetElementLinearList(i, result);
        cout<<"ELEMENT-"<<i<<":";
        DisplayElementLinearList(result);
        
    }
}
