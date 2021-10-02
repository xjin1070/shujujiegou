/*************************************************
    ��Ӧ�̲�2.4.2��, ��������LinkList��ʹ�÷���
**************************************************/
#include <iostream>                  //�������������
using namespace std;

template <typename DataType>
struct Node
{
    DataType data;               //������
    Node<DataType>* next;       //ָ����
};

template <typename DataType>
class LinkList
{
public:
    LinkList();                      //�޲ι��캯��������ֻ��ͷ���Ŀ�����
    LinkList(DataType a[], int n);       //�вι��캯����������n��Ԫ�صĵ�����
    ~LinkList();                     //��������
    int Length();                     //������ĳ���
    int Empety();
    DataType Get(int i);               //��λ���ҡ����ҵ�i������Ԫ��ֵ
    int Locate(DataType x);            //��ֵ���ҡ�����ֵΪx��Ԫ�����
    void Insert(int i, DataType x);       //�����������i��λ�ò���ֵΪx�Ľ��
    DataType Delete(int i);            //ɾ��������ɾ����i�����
    void PrintList();                  //������������������������Ԫ��
private:
    Node<DataType>* first;           //�������ͷָ��
};

template <typename DataType>
LinkList<DataType> ::LinkList()
{
    first = new Node<DataType>;              //����ͷ���
    first->next = nullptr;                      //ͷ����ָ�����ÿ�
}

template <class DataType>
LinkList<DataType> :: ~LinkList()
{
    Node<DataType>* q = NULL;
    while (first != NULL)        //�ͷŵ������ÿһ�����Ĵ洢�ռ�
    {
        q = first;                 //�ݴ汻�ͷŽ��
        first = first->next;         // firstָ���ͷŽ�����һ�����
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
    Node<DataType>* p = first->next;                //����ָ��p��ʼ��
    while (p != nullptr)
    {
        cout << p->data << "\t";
        p = p->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
    }
}

template <typename DataType>
int LinkList<DataType> ::Length()
{
    Node<DataType>* p = first->next;   //����ָ��p��ʼ��Ϊ��ʼ�ӵ�
    int count = 0;                    //�ۼ���count��ʼ��
    while (p != nullptr)
    {
        p = p->next;
        count++;
    }
    return count;              //ע��count�ĳ�ʼ���ͷ���ֵ֮��Ĺ�ϵ
}

template <typename DataType>
DataType LinkList<DataType> ::Get(int i)
{
    Node<DataType>* p = first->next;    //����ָ��p��ʼ��
    int count = 1;                     //�ۼ���count��ʼ��
    while (p != nullptr && count < i)
    {
        p = p->next;                   //����ָ��p����
        count++;
    }
    if (p == nullptr) throw "λ��";
    else return p->data;
}

template <typename DataType>
int LinkList<DataType> ::Locate(DataType x)
{
    Node<DataType>* p = first->next;   //����ָ��p��ʼ��
    int count = 1;                     //�ۼ���count��ʼ��
    while (p != nullptr)
    {
        if (p->data == x) return count;     //���ҳɹ��������������������
        p = p->next;
        count++;
    }
    return 0;                        //�˳�ѭ����������ʧ��
}

template <typename DataType>
void LinkList<DataType> ::Insert(int i, DataType x)
{
    Node<DataType>* p = first, * s = nullptr;        //����ָ��p��ʼ��
    int count = 0;
    while (p != nullptr && count < i - 1)            //���ҵ�i �C 1�����
    {
        p = p->next;                              //����ָ��p����
        count++;
    }
    if (p == nullptr) throw "λ��";        //û���ҵ���i �C 1�����
    else {
        s = new Node<DataType>; s->data = x;      //������s��������Ϊx
        s->next = p->next; p->next = s;     //�����s���뵽���p֮��
    }
}

// ͷ�巨���� 
//template <typename DataType>  
//LinkList<DataType> :: LinkList(DataType a[ ], int n)
//{
//	first = new Node<DataType>; first->next = nullptr;     //��ʼ��һ��������
//	for (int i = 0; i < n; i++)
//	{ 
//		Node<DataType> *s;
//		s = new Node<DataType>; s->data = a[i];    
// 		s->next = first->next; first->next = s;    //�����s���뵽ͷ���֮��
//	}
//}

template <typename DataType>
LinkList<DataType> ::LinkList(DataType a[], int n)
{
    first = new Node<DataType>;                    //����ͷ���
    Node<DataType>* r = first, * s = nullptr;           //βָ���ʼ��
    for (int i = 0; i < n; i++)
    {
        s = new Node<DataType>; s->data = a[i];
        r->next = s; r = s;                 //�����s���뵽�ն˽��֮��
    }
    r->next = nullptr;        //����������ϣ����ն˽���ָ�����ÿ�
}

template <typename DataType>
DataType LinkList<DataType> ::Delete(int i)
{
    DataType x;
    Node<DataType>* p = first, * q = nullptr;        //����ָ��pָ��ͷ���
    int count = 0;
    while (p != nullptr && count < i - 1)           //���ҵ�i-1�����
    {
        p = p->next;
        count++;
    }
    if (p == nullptr || p->next == nullptr)  //���p�����ڻ�p�ĺ�̽�㲻����
        throw "λ��";
    else {
        q = p->next; x = q->data;         //�ݴ汻ɾ���
        p->next = q->next;              //ժ��
        delete q;
        return x;
    }
}

int main()
{
    int r[5] = { 1, 2, 3, 4, 5 }, i, x;
    LinkList<int> L{ r, 5 };
    cout << "��ǰ���Ա������Ϊ��";
    L.PrintList();                         //�����ǰ����1 2 3 4 5
    cout << endl;
    try
    {
        L.Insert(2, 8);                         //�ڵ�2��λ�ò���ֵΪ8�Ľ��
        cout << "ִ�в������������Ϊ��";
        L.PrintList();                         //������������1 8 2 3 4 5
        cout << endl;
    }
    catch (char* str) {
        cout << str << endl;
    }

    cout << "��ǰ������ĳ���Ϊ��" << L.Length() << endl;      //�����������6
    cout << "��������ҵ�Ԫ��ֵ��";
    cin >> x;
    i = L.Locate(x);
    if (1 <= i) cout << "Ԫ��" << x << "��Ԫ��λ��Ϊ��" << i << endl;
    else cout << "��������û��Ԫ��" << x << endl;
    try
    {
        cout << "������Ҫɾ���ڼ���Ԫ�أ�";
        cin >> i;
        x = L.Delete(i);                                 //ɾ����i��Ԫ��
        cout << "ɾ����Ԫ��ֵ��" << x << "ִ��ɾ������������Ϊ��";
        L.PrintList();                                 //���ɾ��������
    }
    catch (char* str) {
        cout << str << endl;
    }
    return 0;
}
