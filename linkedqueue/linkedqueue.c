#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

LinkedQueue* createLinkedQueue() {
	LinkedQueue *pReturn = NULL;
	int i = 0;

	pReturn = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedQueue));
	}
	else
	{
		printf("오류, 메모리할당, createLinkedQueue()\n");
	}
	return pReturn;
}

int enqueueLQ(LinkedQueue* pQueue, QueueNode element) {
	int ret = FALSE;
	QueueNode *pNode = NULL;

	if (pQueue != NULL) {
		pNode = (QueueNode*)malloc(sizeof(QueueNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLink = NULL;

			if (pQueue->currentCount == 0) {
				pQueue->pFront = pNode;
				pQueue->pRear = pNode;
			}
			else
			{
				pQueue->pRear->pLink = pNode;
				pQueue->pRear = pNode;
			}
			pQueue->currentCount++;
			ret = TRUE;
		}
		else
		{
			printf("오류, 메모리 할당, enqueue()\n");
		}
	}
	return ret;
}

QueueNode* dequeueLQ(LinkedQueue* pQueue) {
	QueueNode* pReturn = NULL;
	if (pQueue != NULL) {
		if (pQueue->currentCount != 0) {
			pReturn = pQueue->pFront;
			pQueue->pFront = pQueue->pFront->pLink;
			pReturn->pLink = NULL;

			pQueue->currentCount--;
			if (pQueue->currentCount == 0) {
				pQueue->pRear = NULL;
			}

		}
	}

	return pReturn;
}

QueueNode* peekLQ(LinkedQueue* pQueue) {
	QueueNode* pReturn = NULL;
	if (pQueue != NULL) {
		if (pQueue->currentCount != 0) {
			pReturn = pQueue->pFront;
		}
	}
	return pReturn;
}

void dleleteLinkedQueue(LinkedQueue* pQueue) {
	QueueNode *pNode = NULL;
	QueueNode *pDelNode = NULL;

	if (pQueue != NULL) {
		pNode = pQueue->pFront;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		free(pQueue);
	}
}

int isLinkedQueueEmpty(LinkedQueue* pQueue) {
	int ret = FALSE;

	if (pQueue != NULL) {
		if (pQueue->currentCount ==0) {
			ret = TRUE;
		}
	}
	return ret;
}