//4--------划分子集类Division定义
template<class PROJECT>
class Division
{
	public:
		Division(int MaxListSize = 20);
		~Division(){delete [] element;};

	void DisplayProjects(PROJECT *Projects,int ProjectCount,int setindex );
	void DivisionRun (int r[10][10], PROJECT *Projects, int ProjectCount );

	private:
		PROJECT *	element;		
		int			length;			
		int			MaxSpaceSize;	
};


template<class PROJECT>
Division<PROJECT>::
Division(int MaxListSize )
{//构造函数。定义用于存储项目信息的顺序存储线性表空间
 //MaxSpaceSize大小为项目数、申请元素空间element、定义长度初值length
	MaxSpaceSize=MaxListSize;
	element=new PROJECT[MaxSpaceSize];
	length =0;
}

template<class PROJECT>
void Division<PROJECT>::
DisplayProjects(PROJECT *Projects,int ProjectCount,int setindex )
{//PROJECT *Projects项目实例数据,
 //int ProjectCount项目数，
 //int setindex子集编号（取值：1…n）
	int	i;
	element=Projects;
	length=ProjectCount;
	cout<<endl;
	cout<<"                 "
		<<"=================项目划分结果"
		<<"（第"<<setindex<<"次划分）"
		<<"如下================"<<"   setindex="<<setindex<<endl;

	cout<<"   项目编号→      ";
	for( i=1;i<=length;i++)
		cout<<i<<"      ";
	cout<<"ProjectNumber"<<endl;
	
	cout<<"   项目名称→    ";
	for(i=1;i<=length;i++)
		cout<<element[i].name<<"  ";
	cout<<"  name"<<endl;
	
	cout<<"   项目地址→    ";
	for(i=1;i<=length;i++)
		cout<<element[i].place<<"  ";
	cout<<"  place"<<endl;
	
	cout<<"   项目子集→      ";
	for(i=1;i<=length;i++)
		cout<<element[i].set<<"      ";
	cout<<"set"<<endl;
	
	cout<<"                 "
		<<"=============================================================="<<endl<<endl;
}


template<class PROJECT>
void Division<PROJECT>::
DivisionRun (int  r[10][10], PROJECT *Projects, int ProjectCount )
{// n个项目划分不冲突的子集，冲突关系在r数组中表示
 //PROJECT *Projects项目实例数据,
 //int ProjectCount项目数
	int 	rearkeep;	//队尾保持指针变量，用于判断划分一个子集时队列元素全部出队
	int	current;		//项目编号变量
	int	setindex ;	//子集编号变量
	int	MaxQueueSize=ProjectCount+1;	//定义队列大小值
	int	i;			
	ElementType	x;

	Queue<ElementType> Q(MaxQueueSize);	//创建一个队列实例Q
	QueueDisplay<ElementType>	AppQDispaly;

	for ( i=1; i<=ProjectCount;i++)
	{//项目编号进队，初始化队列:项目一的项目编号为1，项目二的项目编号为2，...
		x.ProjectNumber=Projects[i].ProjectNumber;
		Q.EnQueue(x);
	}

	setindex = 0;						//子集编号初值0，以后+1
	AppQDispaly.DisplayQueue(setindex,Q);//显示初始化后队列的队列数据,实参是子集编号setindex的值

	setindex ++;						//子集编号从1开始编号
	while ( ! Q.IsEmpty())
	{
		rearkeep = Q.GetRearAddress();					//保留当前队尾指针rear
		Q.DeQueue( x );										//出队进入当前子集的第一个项目编号
		current=x.ProjectNumber;
		Projects[current].set = setindex;				//第一个进入新子集的项目改变子集状态值
		while ( !(Q.GetFrontAddress() == rearkeep))	//当前队列中的所有项目尝试进入当前子集
		{
			Q.DeQueue( x );									//出队下一个项目编号
			current=x.ProjectNumber;
			for ( i=1;i<=ProjectCount;i++)	//current项目与已进入当前子集的所有项目比较是否发生冲突
				if  ( setindex == Projects[i].set && r[current][i] )
				{ //current项目与已进入当前子集的i号项目发生冲突
					x.ProjectNumber=current;
					Q.EnQueue(x); 								//current项目重新进队
					break;										//终止比较冲突
				}
			if (i>ProjectCount)	//for()循环正常退出（没有冲突）后，循环变量i大于循环终值ProjectCount
				Projects[current].set = setindex; 		//current进入当前子集
		}

		DisplayProjects( Projects,ProjectCount,setindex);	//显示项目划分过程中变化信息
		AppQDispaly.DisplayQueue(setindex,Q);//显示队列的队列数据

		setindex ++;				//子集编号加1，准备划分下一个子集
		}
}
//4---------end划分子集类Division定义
