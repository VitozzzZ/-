#define STUDENT ElementType
struct student{
    char number[10];
    char name[8];
    char sex[3];
    int age;
    char place[20];
}

template<class ElememtType>
class ChainNode{
public:
    ElememtType data;
    ChainNode<ElememtType> *link;
};
