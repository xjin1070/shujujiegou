/************************************************
   ��Ӧ�̲�3.3.3��,��������LinkQueue��ʹ�÷���
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
class LinkQueue
{
public:
	LinkQueue();               //���캯������ʼ��һ���յ�������
	~LinkQueue();              //�����������ͷ������и����Ĵ洢�ռ�
	void EnQueue(DataType x);    //��Ӳ�������Ԫ��x���
	DataType DeQueue();        //���Ӳ���������ͷԪ�س���
	DataType GetQueue();        //ȡ�����еĶ�ͷԪ��
	int Empty();                //�ж��������Ƿ�Ϊ��
private:
	Node<DataType>* front, * rear;       //��ͷ�Ͷ�βָ�룬�ֱ�ָ��ͷ�����ն˽��
};

template <typename DataType>
LinkQueue<DataType> ::LinkQueue()
{
	Node<DataType>* s = nullptr;
	s = new Node<DataType>; s->next = nullptr;              //����ͷ���s
	front = rear = s;                //����ͷָ��Ͷ�βָ�붼ָ��ͷ���s
}

template <typename DataType>
LinkQueue<DataType> :: ~LinkQueue()
{
	Node<DataType>* q = nullptr;
	while (front != nullptr)        //�ͷŵ������ÿһ�����Ĵ洢�ռ�
	{
		q = front;                 //�ݴ汻�ͷŽ��
		front = front->next;         // frontָ���ͷŽ�����һ�����
		delete q;
	}
}

template <typename DataType>
void LinkQueue<DataType> ::EnQueue(DataType x)
{
	Node<DataType>* s = nullptr;
	s = new Node<DataType>;                 //������s
	s->data = x; s->next = nullptr;
	rear->next = s; rear = s;                   //�����s���뵽��β
}

template <typename DataType>
DataType LinkQueue<DataType> ::DeQueue()
{
	DataType x;
	Node<DataType>* p = nullptr;
	if (rear == front) throw "����";
	p = front->next; x = p->data;           //�ݴ��ͷԪ��
	front->next = p->next;                //����ͷԪ�����ڽ��ժ��
	if (p->next == nullptr) rear = front;      //�жϳ���ǰ���г����Ƿ�Ϊ1
	delete p;
	return x;
}

template <typename DataType>
DataType LinkQueue<DataType> ::GetQueue()
{
	if (front == rear)
		throw "�����쳣";
	else
		return front->next->data;
}

template <typename DataType>
int LinkQueue<DataType> ::Empty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}

int main()
{
	int x;
	LinkQueue<int> Q{ };                                      //����������Q
	cout << "��5��8ִ����Ӳ�����";
	Q.EnQueue(5); Q.EnQueue(8);
	cout << "��ǰ��ͷԪ��Ϊ��" << Q.GetQueue() << endl;        //�����ͷԪ��5

	try
	{
		x = Q.DeQueue();
		cout << "ִ��һ�γ��Ӳ���������Ԫ���ǣ�" << x << endl;   //�������Ԫ��5
	}
	catch (char* str) {
		cout << str << endl;
	}

	try
	{
		cout << "���������Ԫ�أ�";
		cin >> x;
		Q.EnQueue(x);
	}
	catch (char* str) {
		cout << str << endl;
	}

	if (Q.Empty() == 1) cout << "����Ϊ��" << endl;
	else cout << "���зǿ�" << endl;              //������2��Ԫ�أ�������зǿ�
	return 0;
}

