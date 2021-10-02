/***********************************************
对应教材2.3.3节，顺表类SeqList的使用范例
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
		throw "参数非法";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}

template<typename DataType>
void SeqList<DataType>::PrintList()
{
	for (int i = 0; i < length; i++)
		cout << data[i]; //依次输出线性表的元素值
}

template<typename DataType>
int SeqList<DataType>::Locate(DataType x)
{
	for (int i = 0; i < length; i++)
		if (data[i] == x) return i + 1; //返回其序号i+1
	return 0; //退出循环，说明查找失败
}

template<typename DataType>
DataType SeqList<DataType>::Get(int i)
{
	if (i < 1 && i > length)
		throw "查找位置非法";
	else
		return data[i - 1];
}

template<typename DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if (length == 0)
		throw "下溢";
	if (i < 1 || i > length)
		throw "位置";
	int x = data[i - 1]; //取出位置i的元素
	for (int j = i; j < length; j++)
		data[j - 1] = data[j]; //此处j已经是元素所在的数组下标
	length--;
	return x;
}

template<typename DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
	if (length >= MaxSize)
		throw "上溢";
	if (i < 1 || i > length + 1)
		throw "位置";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1]; //第j个元素存在数组下标为j-1处
	data[i - 1] = x;
	length++;
}

int main()
{
	int r[5] = { 1, 2, 3, 4, 5 }, i, x;
	SeqList<int> L{ r, 5 }; //建立具有5个元素的顺序表
	cout << "当前线性表的数据为：";
	L.PrintList(); //输出当前线性表1 2 3 4 5
	try
	{
		L.Insert(2, 8); //在第2个位置插入值为8的元素
		cout << endl << "执行插入操作后数据为：";
		L.PrintList(); //输出插入后的线性表1 8 2 3 4 5
		cout << endl;
	}
	catch (char* str) {
		cout << str << "插入操作错误！" << endl;
	}

	cout << "当前线性表的长度为：" << L.Length(); //输出线性表的长度6
	cout << endl;
	cout << "请输入查找的元素值：";
	cin >> x;
	i = L.Locate(x);
	if (0 == i) cout << "查找失败" << endl;
	else cout << "元素" << x << "的位置为：" << i << endl;
	try
	{
		cout << "请输入查找第几个元素值：";
		cin >> i;
		cout << "第" << i << "个元素值是" << L.Get(i) << endl;
	}
	catch (char* str) {
		cout << "线性表中没有该元素" << endl;
	}
	try
	{
		cout << "请输入要删除第几个元素：";
		cin >> i;
		x = L.Delete(i); //删除第i个元素
		cout << "删除的元素是" << x << "，删除后数据为：";
		L.PrintList(); //输出删除后的线性表
	}
	catch (char* str) {
		cout << "删除错误！" << endl;
	}

	return 0;
}
