#define HEADSTUDENT HeadType
#define STUDENT ElementType  //实例数据元素句柄化
#define age key              //实例数据元素句柄化
#define name key1            //实例数据元素句柄化
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
