#include "myQueue.h"

int main()
{
	MyQueue qHead;

	//初始化
	initQueue(&qHead);

	cout << "入队:";
	enQueue(&qHead, 1);
	enQueue(&qHead, 2);
	enQueue(&qHead, 3);
	enQueue(&qHead, 4);
	enQueue(&qHead, 5);
	printQueueData(&qHead);

	cout << "出队:";
	delQueue(&qHead);
	printQueueData(&qHead);

	getQueueFrontData(&qHead);

	getQueueRearData(&qHead);
	system("pause");
	return 0;
}