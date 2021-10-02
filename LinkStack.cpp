/************************************************
   ��Ӧ�̲�3.2.3�ڣ���ջ��LinkStack��ʹ�÷���
*************************************************/
#include <iostream>
using namespace std;

template <typename DataType>
struct Node
{
    DataType data;               //������
    Node<DataType>* next;       //ָ����
};

template <typename DataType>
class LinkStack
{
public:
    LinkStack();                     //���캯������ʼ��һ������ջ
    ~LinkStack();                    //�����������ͷ���ջ�����Ĵ洢�ռ�
    void Push(DataType x);            //��ջ��������Ԫ��x��ջ
    DataType Pop();                 //��ջ��������ջ��Ԫ�س�ջ
    DataType GetTop();              //ȡջ��Ԫ�أ�����ɾ����
    int Empty();                    //�пղ������ж���ջ�Ƿ�Ϊ��ջ
private:
    Node<DataType>* top;                       //ջ��ָ�뼴��ջ��ͷָ��
};

template <typename DataType>
LinkStack<DataType> ::LinkStack()
{
    top = new Node<DataType>;              //����ͷ���
    top->next = nullptr;                      //ͷ����ָ�����ÿ�
}

template <typename DataType>
LinkStack<DataType> :: ~LinkStack()
{
    Node<DataType>* q = nullptr;
    while (top != nullptr)        //�ͷ���ջ��ÿһ�����Ĵ洢�ռ�
    {
        q = top;                 //�ݴ汻�ͷŽ��
        top = top->next;         // topָ���ͷŽ�����һ�����
        delete q;
    }
}

template <typename DataType>
DataType LinkStack<DataType> ::GetTop()
{
    if (top == nullptr)
        throw "�����쳣";
    else
        return top->data;
}


template <typename DataType>
void LinkStack<DataType> ::Push(DataType x)
{
    Node<DataType>* s = nullptr;
    s = new Node<DataType>; s->data = x;         //������s������Ϊx
    s->next = top; top = s;                       //�����s����ջ��
}

template <typename DataType>
DataType LinkStack<DataType> ::Pop()
{
    Node<DataType>* p = nullptr;
    DataType x;
    if (top == nullptr) throw "����";
    x = top->data; p = top;                //�ݴ�ջ��Ԫ��
    top = top->next;                     //��ջ�����ժ��
    delete p;
    return x;
}

template <typename DataType>
int LinkStack<DataType> ::Empty()
{
    if (top == nullptr)
        throw "�����쳣";
    else
        return 0;
}

int main()
{
    int x;
    LinkStack<int> S{ };                                        //������ջ����S
    cout << "��15��10ִ����ջ������";
    S.Push(15); S.Push(10);
    cout << "��ǰջ��Ԫ��Ϊ��" << S.GetTop() << endl;          //���ջ��Ԫ��10
    try
    {
        x = S.Pop();
        cout << "ִ��һ�γ�ջ������ɾ��Ԫ�أ�" << x << endl;    //�����ջԪ��10
    }
    catch (char* str) {
        cout << str << endl;
    }
    try
    {
        cout << "�����������Ԫ�أ�";
        cin >> x;
        S.Push(x);
    }
    catch (char* str) {
        cout << str << endl;
    }
    if (S.Empty() == 1) cout << "ջΪ��" << endl;
    else cout << "ջ�ǿ�" << endl;                    //ջ��2��Ԫ�أ����ջ�ǿ�
    return 0;
}






