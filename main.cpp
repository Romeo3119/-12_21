#include "myQueue.h"

int main()
{
	MyQueue qHead;

	//��ʼ��
	initQueue(&qHead);

	cout << "���:";
	enQueue(&qHead, 1);
	enQueue(&qHead, 2);
	enQueue(&qHead, 3);
	enQueue(&qHead, 4);
	enQueue(&qHead, 5);
	printQueueData(&qHead);

	cout << "����:";
	delQueue(&qHead);
	printQueueData(&qHead);

	getQueueFrontData(&qHead);

	getQueueRearData(&qHead);
	system("pause");
	return 0;
}