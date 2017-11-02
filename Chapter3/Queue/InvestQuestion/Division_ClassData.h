//1-------应用数据元素结构定义
	class PROJECT			//数据元素类型的定义
	{//项目信息以此结构元素存放为线性表 
		public:
		int	ProjectNumber;
		char	name[8];
		char	place[20];
		int	set;
	};

	class	ElementType		//实例数据元素结构
	{//划分集合时使用队列的元素结构 
		public:
		int	ProjectNumber;
	};


//1-------end应用数据元素结构定义结束
