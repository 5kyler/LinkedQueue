#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void displayLinkedQueue(LinkedQueue *pQueue) {
	QueueNode *pNode = NULL;
	int i = 0;
	if (pQueue != NULL) {
		printf("현재노드 개수: %d\n", pQueue->currentCount);
		
		pNode = pQueue->pFront;			//pnode를 pfront에서부터 하나씩 증가시키는 코드
		while (pNode != NULL) {
			printf("[%d]-[%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}

int enqueueLQChar(LinkedQueue* pQueue, char data) {
	QueueNode node = { 0, };
	node.data = data;
	return enqueueLQ(pQueue, node);
}

int main(int argc, char *argv[]) {
	LinkedQueue *pQueue = NULL;
	QueueNode *pNode = NULL;
	char value = 0;

	pQueue = createLinkedQueue();
	if (pQueue != NULL) {
		enqueueLQChar(pQueue, 'X');
		enqueueLQChar(pQueue, 'Y');
		enqueueLQChar(pQueue, 'Z');
		enqueueLQChar(pQueue, 'W');

		displayLinkedQueue(pQueue);

		if (pNode != NULL) {
			printf("dequeue Value-[%c]\n", pNode->data);
			free(pNode);
		}

		pNode = dequeueLQ(pQueue);
		if (pNode != NULL) {
			printf("dequeue value-[%c]\n", pNode->data);
			free(pNode);
		}
		
		displayLinkedQueue(pQueue);

		pNode = peekLQ(pQueue);
		if (pNode != NULL) {
			printf("peek value-[%c]\n", pNode->data);
		}
		displayLinkedQueue(pQueue);

	}
}