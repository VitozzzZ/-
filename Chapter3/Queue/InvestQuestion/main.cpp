//子集划分division

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "Division_ClassData.h"
#include "Division_QueueClass.h"
#include "Division_QueueClassDisplay.h"
#include "Division_Class.h"


//5------主程序
int main()
{
	PROJECT	Projects[10];	
	int		i,ProjectCount=9;

	char	name[][8]	={"","项目1","项目2","项目3","项目4","项目5","项目6","项目7","项目8","项目9"};
	char	place[][8]	={"","WWWW1","WWWW2","WWWW3","WWWW4","WWWW5","WWWW6","WWWW7","WWWW8","WWWW9"};

	int		ProjectRelation[10][10]={	
										{0,0,0,0,0,0,0,0,0,0},	//0行，0列不用
										{0,0,1,0,0,0,0,0,0,0},
										{0,1,0,0,0,1,1,0,1,1},
										{0,0,0,0,0,0,1,1,0,0},
										{0,0,0,0,0,1,0,0,0,1},
										{0,0,1,0,1,0,1,1,0,1},
										{0,0,1,1,0,1,0,1,0,0},
										{0,0,0,1,0,1,1,0,0,0},
										{0,0,1,0,0,0,0,0,0,0},
										{0,0,1,0,1,1,0,0,0,0}	};
	cout<<endl<<endl;
	cout<<"                 "<<"   1  2  3  4  5  6  7  8  9"<<endl;
	cout<<"                 "<<"1 [0  1  0  0  0  0  0  0  0]"<<endl;
	cout<<"                 "<<"2 [1  0  0  0  1  1  0  1  1]"<<endl;
	cout<<"                 "<<"3 [0  0  0  0  0  1  1  0  0]"<<endl;
	cout<<"                 "<<"4 [0  0  0  0  1  0  0  0  1]"<<endl;
	cout<<"                 "<<"5 [0  1  0  1  0  1  1  0  1]"<<endl;
	cout<<"                 "<<"6 [0  1  1  0  1  0  1  0  0]"<<endl;
	cout<<"                 "<<"7 [0  0  1  0  1  1  0  0  0]"<<endl;
	cout<<"                 "<<"8 [0  1  0  0  0  0  0  0  0]"<<endl;
	cout<<"                 "<<"9 [0  1  0  1  1  0  0  0  0]"<<endl;
	cout<<"                 "<<"      ProjectRelation[][]"<<endl;

	
	for( i=1;i<=ProjectCount;i++)	
	{//项目信息实例化
		strcpy(Projects[i].name,name[i]);
		strcpy(Projects[i].place,place[i]);
		Projects[i].ProjectNumber=i;
		Projects[i].set=0;				//划分子集状态set值初始化为0
	}

	Division<PROJECT> AppDivision(ProjectCount);				//创建划分子集类实例AppDivision

	AppDivision.DisplayProjects(Projects,ProjectCount,0);	//显示项目信息初值
	
	AppDivision.DivisionRun(ProjectRelation, Projects, ProjectCount );//划分子集

	return 0;
}
//5------end主程序
