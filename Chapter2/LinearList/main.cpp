/******
 顺序存储结构线性表的3个部分
 AppData_LinearLiat.h
 linearlist_Class.h
 LinearList.cpp
 ******/

//主程序LinearList.cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "AppData_LinearList.h"
#include "LinearList_ClassData.h"
int main(){
    int MaxListSize=20;
    
    int i,k,choice;
    ElementType newvalue,result;
    char number[][8]={"","10001","10002","10003","10005","10005","10006","10007","10008"};
    char name[][8]={"","学1","学2","学3","学4","学5","学6","学7","学8"};
    char sex[][8]={"","男","男","女","男","男","女","女","男"};
    char place[][8]={"wwww1","wwww2","wwww3","wwww4","wwww5","wwww6","wwww7","wwww8"};
    int age[]={0,101,102,103,104,105,106,107,108};
    Linearlist<ElementType>Applist(MaxListSize);
    for(i=8;i>0;i--){
        strcpy(newvalue.number,number[i]);
        strcpy(newvalue.sex,sex[i]);
        strcpy(newvalue.name,name[i]);
        newvalue.age=age[i];
        strcpy(newvalue.place,place[i]);
        Applist.InsertElementLinearList(0, newvalue);//在顺序线性表的最前面插入数据元素
    }
    
    //假设一个新数据元素值newvalue
    strcpy(newvalue.number, "99999");
    strcpy(newvalue.name,"天使");
    strcpy(newvalue.sex, "中");
    newvalue.age=999;
    strcpy(newvalue.place, "天堂");
    while(true){
        cout<<"   顺序存储线性表顺序存储的运算"<<endl;
        cout<<"************************************"<<endl;
        cout<<"   0----退出"<<endl;
        cout<<"   1----输出顺序存储线性表中的所有元素"<<endl;
        cout<<"   2----在顺序存储线性表中查找第k个元素"<<endl;
        cout<<"   3----查找关键字searchkey(住址)的元素"<<endl;
        cout<<"   4----插入新元素到第k个元素后面"<<endl;
        cout<<"   5----在顺序存储线性表中删除第k个元素"<<endl;
        cout<<"************************************"<<endl;
        cout<<"请选择处理功能:";
        cin>>choice;
        system("cls");
        //---------输出线性表中的所有数据元素
        cout<<endl<<"此操作前顺序存储线性表状态"<<endl<<endl;
        Applist.DisplayElementLinearList(Applist);
        switch(choice){
            case 0:
            {
                system("cls");
                return 0;
            }
            case 1:
            {
                cout<<"输出顺序存储线性表中的所有数据元素"<<endl<<endl;
                Applist.DisplayElementLinearList(Applist);
                break;
            }
            case 2:
            {
                cout<<"***在顺序存储线性表中查找第k个元素"<<endl<<endl;
                cout<<"查找第几个元素？";cin>>k;
                cout<<"*****查找结果如下:"<<endl;
                if(Applist.GetElementLinearList(k, result)){
                    cout<<"ELEMENT-"<<k<<":";
                    Applist.DisplayElementLinearList(result);
                }
                else{
                    cout<<"ERROR！k值得范围不对无此元素"<<endl<<endl;
                }
                break;
            }
            case 3:
            {
                cout<<"查找关键字为searckey的元素"<<endl<<endl;
                char searchykey[8];
                cout<<"输出查找关键字searchkey(住址)的值";
                cin>>searchykey;
                k=Applist.SearchElementLinearList(searchykey);
                if(k!=-1){
                    Applist.GetElementLinearList(k+1, result);
                    cout<<"ELEMENT-"<<k+1<<":";
                    Applist.DisplayElementLinearList(result);
                }
                else
                    cout<<"ERROR! 无此关键字的元素"<<endl<<endl;
                break;
            }
            case 4:
            {
                cout<<"线性表中插入新元素到第k个元素后面"<<endl<<endl;
                cout<<"插到第几个元素后面?";cin>>k;
                cout<<"输入要插入元素的各值:"<<endl;
                cout<<"    学号："<<newvalue.number<<"    ";
                cout<<"    姓名："<<newvalue.name<<"    ";
                cout<<"    性别："<<newvalue.sex<<"    ";
                cout<<"    年龄："<<newvalue.age<<"    ";
                cout<<"    住址："<<newvalue.place<<"    ";
                if(Applist.InsertElementLinearList(k, newvalue)){
                    cout<<"插入元素到第"<<k<<"个元素后的线性表结果"<<endl;
                    Applist.DisplayElementLinearList(Applist);
                }
                else
                    cout<<"ERROR!找不到插入点,k值范围不对或空间不足！"<<endl<<endl;
                break;
            }
            case 5:
            {
                cout<<"***在线性表中删除第k个元素***"<<endl<<endl;
                cout<<"删除第几个元素？";
                cin>>k;
                if(Applist.DeleteElementLinearList(k)){
                    cout<<"删除元素后的顺序存储线性表的结果："<<endl;
                    Applist.DisplayElementLinearList(Applist);
                }
                else
                    cout<<"ERROR!找不到要删除的节点，k值范围不对!"<<endl<<endl;
                break;
            }
        }
        cout<<"顺序存储线性表长度:"<<Applist.LengthLinearList()<<endl;
        system("pause");
        system("cls");
    }
    return 0;
}
