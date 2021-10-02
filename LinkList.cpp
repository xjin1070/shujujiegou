/*************************************************
    对应教材2.4.2节, 单链表类LinkList的使用范例
**************************************************/
#include <iostream>                  //引入输入输出流
using namespace std;

template <typename DataType>
struct Node
{
    DataType data;               //数据域
    Node<DataType>* next;       //指针域
};

template <typename DataType>
class LinkList
{
public:
    LinkList();                      //无参构造函数，建立只有头结点的空链表
    LinkList(DataType a[], int n);       //有参构造函数，建立有n个元素的单链表
    ~LinkList();                     //析构函数
    int Length();                     //求单链表的长度
    int Empety();
    DataType Get(int i);               //按位查找。查找第i个结点的元素值
    int Locate(DataType x);            //按值查找。查找值为x的元素序号
    void Insert(int i, DataType x);       //插入操作，第i个位置插入值为x的结点
    DataType Delete(int i);            //删除操作，删除第i个结点
    void PrintList();                  //遍历操作，按序号依次输出各元素
private:
    Node<DataType>* first;           //单链表的头指针
};

template <typename DataType>
LinkList<DataType> ::LinkList()
{
    first = new Node<DataType>;              //生成头结点
    first->next = nullptr;                      //头结点的指针域置空
}

template <class DataType>
LinkList<DataType> :: ~LinkList()
{
    Node<DataType>* q = NULL;
    while (first != NULL)        //释放单链表的每一个结点的存储空间
    {
        q = first;                 //暂存被释放结点
        first = first->next;         // first指向被释放结点的下一个结点
        delete q;
    }
}

template <typename DataType>
int LinkList<DataType> ::Empety()
{
    if (first->next == nullptr)
        return 1;
    else
        return 0;
}

template <typename DataType>
void LinkList<DataType> ::PrintList()
{
    Node<DataType>* p = first->next;                //工作指针p初始化
    while (p != nullptr)
    {
        cout << p->data << "\t";
        p = p->next;                 //工作指针p后移，注意不能写作p++
    }
}

template <typename DataType>
int LinkList<DataType> ::Length()
{
    Node<DataType>* p = first->next;   //工作指针p初始化为开始接点
    int count = 0;                    //累加器count初始化
    while (p != nullptr)
    {
        p = p->next;
        count++;
    }
    return count;              //注意count的初始化和返回值之间的关系
}

template <typename DataType>
DataType LinkList<DataType> ::Get(int i)
{
    Node<DataType>* p = first->next;    //工作指针p初始化
    int count = 1;                     //累加器count初始化
    while (p != nullptr && count < i)
    {
        p = p->next;                   //工作指针p后移
        count++;
    }
    if (p == nullptr) throw "位置";
    else return p->data;
}

template <typename DataType>
int LinkList<DataType> ::Locate(DataType x)
{
    Node<DataType>* p = first->next;   //工作指针p初始化
    int count = 1;                     //累加器count初始化
    while (p != nullptr)
    {
        if (p->data == x) return count;     //查找成功，结束函数并返回序号
        p = p->next;
        count++;
    }
    return 0;                        //退出循环表明查找失败
}

template <typename DataType>
void LinkList<DataType> ::Insert(int i, DataType x)
{
    Node<DataType>* p = first, * s = nullptr;        //工作指针p初始化
    int count = 0;
    while (p != nullptr && count < i - 1)            //查找第i – 1个结点
    {
        p = p->next;                              //工作指针p后移
        count++;
    }
    if (p == nullptr) throw "位置";        //没有找到第i – 1个结点
    else {
        s = new Node<DataType>; s->data = x;      //申请结点s，数据域为x
        s->next = p->next; p->next = s;     //将结点s插入到结点p之后
    }
}

// 头插法构造 
//template <typename DataType>  
//LinkList<DataType> :: LinkList(DataType a[ ], int n)
//{
//	first = new Node<DataType>; first->next = nullptr;     //初始化一个空链表
//	for (int i = 0; i < n; i++)
//	{ 
//		Node<DataType> *s;
//		s = new Node<DataType>; s->data = a[i];    
// 		s->next = first->next; first->next = s;    //将结点s插入到头结点之后
//	}
//}

template <typename DataType>
LinkList<DataType> ::LinkList(DataType a[], int n)
{
    first = new Node<DataType>;                    //生成头结点
    Node<DataType>* r = first, * s = nullptr;           //尾指针初始化
    for (int i = 0; i < n; i++)
    {
        s = new Node<DataType>; s->data = a[i];
        r->next = s; r = s;                 //将结点s插入到终端结点之后
    }
    r->next = nullptr;        //单链表建立完毕，将终端结点的指针域置空
}

template <typename DataType>
DataType LinkList<DataType> ::Delete(int i)
{
    DataType x;
    Node<DataType>* p = first, * q = nullptr;        //工作指针p指向头结点
    int count = 0;
    while (p != nullptr && count < i - 1)           //查找第i-1个结点
    {
        p = p->next;
        count++;
    }
    if (p == nullptr || p->next == nullptr)  //结点p不存在或p的后继结点不存在
        throw "位置";
    else {
        q = p->next; x = q->data;         //暂存被删结点
        p->next = q->next;              //摘链
        delete q;
        return x;
    }
}

int main()
{
    int r[5] = { 1, 2, 3, 4, 5 }, i, x;
    LinkList<int> L{ r, 5 };
    cout << "当前线性表的数据为：";
    L.PrintList();                         //输出当前链表1 2 3 4 5
    cout << endl;
    try
    {
        L.Insert(2, 8);                         //在第2个位置插入值为8的结点
        cout << "执行插入操作后数据为：";
        L.PrintList();                         //输出插入后链表1 8 2 3 4 5
        cout << endl;
    }
    catch (char* str) {
        cout << str << endl;
    }

    cout << "当前单链表的长度为：" << L.Length() << endl;      //输出单链表长度6
    cout << "请输入查找的元素值：";
    cin >> x;
    i = L.Locate(x);
    if (1 <= i) cout << "元素" << x << "的元素位置为：" << i << endl;
    else cout << "单链表中没有元素" << x << endl;
    try
    {
        cout << "请输入要删除第几个元素：";
        cin >> i;
        x = L.Delete(i);                                 //删除第i个元素
        cout << "删除的元素值是" << x << "执行删除操作后数据为：";
        L.PrintList();                                 //输出删除后链表
    }
    catch (char* str) {
        cout << str << endl;
    }
    return 0;
}
