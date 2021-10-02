/***********************************************
��Ӧ�̲�2.3.3�ڣ�˳����SeqList��ʹ�÷���
************************************************/
#include "SeqList.h"
#include<iostream>
using namespace std;



template<typename DataType>
SeqList<DataType> :: ~SeqList()
{

}

template<typename DataType>
SeqList<DataType>::SeqList()
{
	length = 0;
}

template<typename DataType>
int SeqList<DataType>::Empety()
{
	if (length == 0)
		return 1;
	else
		return 0;
}

template<typename DataType>
int SeqList<DataType>::Length()
{
	return length;
}

template<typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
	if (n > MaxSize)
		throw "�����Ƿ�";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}

template<typename DataType>
void SeqList<DataType>::PrintList()
{
	for (int i = 0; i < length; i++)
		cout << data[i]; //����������Ա��Ԫ��ֵ
}

template<typename DataType>
int SeqList<DataType>::Locate(DataType x)
{
	for (int i = 0; i < length; i++)
		if (data[i] == x) return i + 1; //���������i+1
	return 0; //�˳�ѭ����˵������ʧ��
}

template<typename DataType>
DataType SeqList<DataType>::Get(int i)
{
	if (i < 1 && i > length)
		throw "����λ�÷Ƿ�";
	else
		return data[i - 1];
}

template<typename DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if (length == 0)
		throw "����";
	if (i < 1 || i > length)
		throw "λ��";
	int x = data[i - 1]; //ȡ��λ��i��Ԫ��
	for (int j = i; j < length; j++)
		data[j - 1] = data[j]; //�˴�j�Ѿ���Ԫ�����ڵ������±�
	length--;
	return x;
}

template<typename DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
	if (length >= MaxSize)
		throw "����";
	if (i < 1 || i > length + 1)
		throw "λ��";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1]; //��j��Ԫ�ش��������±�Ϊj-1��
	data[i - 1] = x;
	length++;
}

int main()
{
	int r[5] = { 1, 2, 3, 4, 5 }, i, x;
	SeqList<int> L{ r, 5 }; //��������5��Ԫ�ص�˳���
	cout << "��ǰ���Ա������Ϊ��";
	L.PrintList(); //�����ǰ���Ա�1 2 3 4 5
	try
	{
		L.Insert(2, 8); //�ڵ�2��λ�ò���ֵΪ8��Ԫ��
		cout << endl << "ִ�в������������Ϊ��";
		L.PrintList(); //������������Ա�1 8 2 3 4 5
		cout << endl;
	}
	catch (char* str) {
		cout << str << "�����������" << endl;
	}

	cout << "��ǰ���Ա�ĳ���Ϊ��" << L.Length(); //������Ա�ĳ���6
	cout << endl;
	cout << "��������ҵ�Ԫ��ֵ��";
	cin >> x;
	i = L.Locate(x);
	if (0 == i) cout << "����ʧ��" << endl;
	else cout << "Ԫ��" << x << "��λ��Ϊ��" << i << endl;
	try
	{
		cout << "��������ҵڼ���Ԫ��ֵ��";
		cin >> i;
		cout << "��" << i << "��Ԫ��ֵ��" << L.Get(i) << endl;
	}
	catch (char* str) {
		cout << "���Ա���û�и�Ԫ��" << endl;
	}
	try
	{
		cout << "������Ҫɾ���ڼ���Ԫ�أ�";
		cin >> i;
		x = L.Delete(i); //ɾ����i��Ԫ��
		cout << "ɾ����Ԫ����" << x << "��ɾ��������Ϊ��";
		L.PrintList(); //���ɾ��������Ա�
	}
	catch (char* str) {
		cout << "ɾ������" << endl;
	}

	return 0;
}
