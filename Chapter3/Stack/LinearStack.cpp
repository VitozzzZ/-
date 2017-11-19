template <class StackType>
class Stack{
public:
    Stack(int MaxStackSize=20);
    ~Stack(){delete [] element;};
    int GetTopAddress(){return top;};
    bool IsEmpty(){return top==-1;};
    bool IsFull(){return top>=MaxSpaceSize-1;};
    bool GetTop(StackType &result);
    bool Push(StackType &newvalue);
    bool Pop(StackType &result);
private:
    int top;
    int MaxSpaceSize;
    StackType * element;
};
template<class StackType>
Stack<StackType>::
Stack(int MaxStackSize){
    MaxSpaceSize=MaxStackSize;
    element=new StackType[MaxSpaceSize];
    top=-1;
}
template<class StackType>
bool Stack<StackType>::
GetTop(StackType &result){
    if(IsEmpty()) return false;
    result=element[top];
    return true;
}
template<class StackType>
bool Stack<StackType>::
Push(StackType &newvalue){
    if(IsFull()) return false;
    element[++top]=newvalue;
    return true;
}
template<class StackType>
bool Stack<StackType>::
Pop(StackType &result){
    if(IsEmpty()) return false;
    element[top--]=result;
    return true;
}

