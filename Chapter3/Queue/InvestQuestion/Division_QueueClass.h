//2-------顺序存储队列结构模板类 Queue的定义

template<class ElementType>
class Queue
 {
   public:
		Queue(int MaxQueueSize = 20);
		~Queue() {delete [] element;}
		bool IsEmpty()  {return front == rear;}
		bool IsFull()   {return (front == (rear+1)%(MaxSpaceSize+1) ? 1 : 0);}
		bool GetFront(ElementType& result) ;				//获取队头元素的值
		bool GetRear(ElementType& result) ;					//获取队尾元素的值
		bool EnQueue(ElementType& newvalue);				//进队
		bool DeQueue(ElementType& result);					//出队

		int  GetFrontAddress(){return front;};				//获取队头元素的地址
		int  GetRearAddress(){return rear;};				//获取队尾元素的地址
		int  GetMaxSpaceSize(){return MaxSpaceSize;};	//获取队列空间大小 
		
		bool	GetElement(int k,ElementType& result);

//		void DisplayQueueSpace(int setindex);				//显示输出队列空间内容

   private:
		ElementType *	element;		
		int				front;			
		int				rear;			
		int				MaxSpaceSize;	
};

template<class ElementType>
Queue<ElementType>::
Queue(int MaxQueueSize)
{// 创建循环队列空间
   MaxSpaceSize = MaxQueueSize ;
   element = new ElementType[MaxSpaceSize+ 1];
   front = 0;
   rear	 = 0;
}

template<class ElementType>
bool Queue<ElementType>::
GetFront(ElementType& result) 
{//获取队头元素的值
	if (IsEmpty()) return false; 
	result=element[(front+1)%(MaxSpaceSize+ 1)];
	return true;
}

template<class ElementType>
bool Queue<ElementType>::
GetRear(ElementType& result) 
{//获取队尾元素的值 
	if (IsEmpty()) return false; 
	result=element[rear];
	return true;
}

template<class ElementType>
bool Queue<ElementType>::
EnQueue( ElementType& newvalue)
{// 
	if (IsFull()) return false; 
	rear = (rear + 1) % (MaxSpaceSize+ 1);
	element[rear] = newvalue;
	return true;
}

template<class ElementType>
bool Queue<ElementType>::
DeQueue(ElementType& result)
{// 
	if (IsEmpty()) return false; 
	front = (front + 1) % (MaxSpaceSize+ 1);
	result = element[front];
	return true;
}

template<class ElementType>
bool Queue<ElementType>::
GetElement(int k,ElementType& result)
{
	result=element[k];
	return true;
}
//2-------end顺序存储队列结构模板类 Queue的定义
