//3-------应用队列输出函数模板类的定义

template<class ElementType>
class QueueDisplay
{
	public:
	void DisplayQueue(int setindex,Queue<ElementType> &AppQueue);
};


template<class ElementType>
void QueueDisplay<ElementType>::
DisplayQueue(int setindex,Queue<ElementType> &AppQueue)
{// 逐个地输出队列中的数据元素
   int MaxSpaceSize,front,rear;
   ElementType	 result;
	int	k;
	
   MaxSpaceSize=AppQueue.GetMaxSpaceSize();
   front=AppQueue.GetFrontAddress();
   rear=AppQueue.GetRearAddress();
   
	cout<<"                 "
		 <<"-----------------输出队列中的所有元素"
		 <<"（第"<<setindex<<"次划分）"
		 <<"----------------"<<endl;
	cout<<"   队列地址→     ";
	for(k=0;k<=MaxSpaceSize;k++)
		cout<<" "<<k<<"    ";
	cout<<endl;

	cout<<"                "
		<<"┏━━┳━━┳━━┳━━┳━━┳━━┳━━┳━━┳━━┳━━┳━━┓"<<endl;

	cout<<"   项目编号→   ┃";
	for(k=0;k<=MaxSpaceSize;k++)
	{
		AppQueue.GetElement(k,result);
		if (rear>=front)
			if(k<=front)
				cout<<" - "<<" ┃";
			else
				if (k>front && k<=rear)
					cout<<" "<<result.ProjectNumber<<"  ┃";
				else
					cout<<" - "<<" ┃";
		else
			if (k<=rear)
					cout<<" "<<result.ProjectNumber<<"  ┃"; 
			else
				if (k>rear && k<=front)
					cout<<" - "<<" ┃";
				else
					cout<<" "<<result.ProjectNumber<<"  ┃"; 
	}
	cout<<endl;
	cout<<"                "
		<<"┗━━┻━━┻━━┻━━┻━━┻━━┻━━┻━━┻━━┻━━┻━━┛"<<endl;

	if (rear>=front)
		k=rear-front;
	else
		k=rear-front+MaxSpaceSize;

	cout<<"                  "
		<<"队头指针front="<<front<<"  "
		<<"队尾指针rear="<<rear<<"  "
		<<"队列中元素个数="<<k<<"  "
		<<"队列空间="<<MaxSpaceSize
		<<endl;   
	cout<<"                 "
		<<"------------------------------------------------------------------"<<endl;
}
//3-------end 应用队列输出函数模板类的定义
