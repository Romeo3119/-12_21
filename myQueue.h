#include<iostream>

using namespace std;
typedef int QElemType;

typedef struct MyQueue{
	QElemType data;
	struct MyQueue* front;
	struct MyQueue* rear;
	struct MyQueue* _next;
} MyQueue;

//����һ���ն���
void initQueue(MyQueue* qHead)
{
	qHead->_next = nullptr;
	qHead->front = nullptr;
	qHead->rear = nullptr;
	cout << "���г�ʼ�����!" << endl;
}

//�����½ڵ�
MyQueue* buyNewNode()
{
	MyQueue* newNode = new MyQueue();
	return newNode;
}
//��Ӳ���
void enQueue(MyQueue* qHead, QElemType data)
{
	//�����л�û������Ԫ��
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
	//��������Ԫ��
	//��β��
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


//����
void delQueue(MyQueue* qHead)
{
	if (qHead->_next == nullptr)
	{
		cout << "����Ϊ�գ�����ʧ��!" << endl;
		return;
	}
	//ͷɾ
	MyQueue* qFirst = qHead->_next;
	qHead->_next = qFirst->_next;
	delete qFirst;
	qFirst = nullptr;
	qHead->front = qHead->_next;
}

//��ȡ����Ԫ��
void getQueueFrontData(MyQueue* qHead)
{
	if (qHead->_next == nullptr)
	{
		cout << "����Ϊ�գ���ȡʧ��!" << endl;
	}
	QElemType frontData = qHead->front->data;
	cout << "����Ԫ��: " << frontData << endl;
}

//��ȡ��βԪ��
void getQueueRearData(MyQueue* qHead)
{
	if (qHead->_next == nullptr)
	{
		cout << "����Ϊ�գ���ȡʧ��!" << endl;
	}
	QElemType rearData = qHead->rear->data;
	cout << "��βԪ��: " << rearData << endl;
}
//��ӡ����Ԫ��
void printQueueData(MyQueue* qHead)
{
	if (qHead->_next == nullptr)
	{
		cout << "����Ϊ��!" << endl;
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