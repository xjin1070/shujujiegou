#pragma once
const int MaxSize = 100; //100只是示例性的数据，根据实际问题具体定义
template<typename DataType> //定义模板类SeqList
class SeqList
{
public:
	SeqList(); //无参构造函数，建立空的顺序表
	SeqList(DataType a[], int n); //有参构造函数，建立长度为n的顺序表
	~SeqList(); //析构函数
	int Length(); //求线性表的长度
	int Empety();
	DataType Get(int i); //按位查找，查找第i个元素的值
	int Locate(DataType x); //按值查找，查找值为x的元素序号
	void Insert(int i, DataType x); //插入操作，在第i个位置插入值为x的元素
	DataType Delete(int i); //删除操作，删除第i个元素
	void PrintList(); //遍历操作，按序号依次输出各元素
private:
	DataType data[MaxSize]; //存放数据元素的数组
	int length; //线性表的长度
};
