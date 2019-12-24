#include<iostream>

using namespace std;
typedef int QElemType;

typedef struct MyQueue{
	QElemType data;
	struct MyQueue* front;
	struct MyQueue* rear;
	struct MyQueue* _next;
} MyQueue;

//构造一个空队列
void initQueue(MyQueue* qHead)
{
	qHead->_next = nullptr;
	qHead->front = nullptr;
	qHead->rear = nullptr;
	cout << "队列初始化完成!" << endl;
}

//申请新节点
MyQueue* buyNewNode()
{
	MyQueue* newNode = new MyQueue();
	return newNode;
}
//入队操作
void enQueue(MyQueue* qHead, QElemType data)
{
	//若队列还没有其他元素
	if (qHead->_next == nullptr)
	{
		MyQueue* newNode = buyNewNode();
		newNode->data = data;
		qHead->_next = newNode;
		newNode->_next = nullptr;
		qHead->front = newNode;
		qHead->rear = newNode;
		return;
	}
	//若有其他元素
	//即尾插
	MyQueue* qCur = qHead;
	while (qCur->_next != nullptr)
	{
		qCur = qCur->_next;
	}
	MyQueue* newNode = buyNewNode();
	newNode->data = data;
	qCur->_next = newNode;
	newNode->_next = nullptr;
	qHead->rear = newNode;
}


//出队
void delQueue(MyQueue* qHead)
{
	if (qHead->_next == nullptr)
	{
		cout << "队列为空，出队失败!" << endl;
		return;
	}
	//头删
	MyQueue* qFirst = qHead->_next;
	qHead->_next = qFirst->_next;
	delete qFirst;
	qFirst = nullptr;
	qHead->front = qHead->_next;
}

//获取队首元素
void getQueueFrontData(MyQueue* qHead)
{
	if (qHead->_next == nullptr)
	{
		cout << "队列为空，获取失败!" << endl;
	}
	QElemType frontData = qHead->front->data;
	cout << "队首元素: " << frontData << endl;
}

//获取队尾元素
void getQueueRearData(MyQueue* qHead)
{
	if (qHead->_next == nullptr)
	{
		cout << "队列为空，获取失败!" << endl;
	}
	QElemType rearData = qHead->rear->data;
	cout << "队尾元素: " << rearData << endl;
}
//打印队列元素
void printQueueData(MyQueue* qHead)
{
	if (qHead->_next == nullptr)
	{
		cout << "队列为空!" << endl;
		return;
	}
	MyQueue* qCur = qHead->_next;
	while (qCur != nullptr)
	{
		cout << qCur->data << " ";
		qCur = qCur->_next;
	}
	cout << endl;
}