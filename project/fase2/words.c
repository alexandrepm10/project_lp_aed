//
// Created by Alexandre Marques 31202 on 13/12/2018.
//

#include <stdio.h>
#include <mem.h>
#include "words.h"

void clientQueues(){
	QUEUEWORDS q;
	initQueues(&q);
	enqueue(&q, "ola");
	enqueue(&q, "tudo");
	enqueue(&q, "bem");
	while(q.N>0){
		printf("%s\t",dequeue(&q));
	}

}

void initQueues(QUEUEWORDS *q){
	q->head=0;
	q->tail=0;
	q->N=0;
}

void enqueue(QUEUEWORDS *q, char *item){
	if(q->N>NW)
		return;
	q->q[q->tail]=item;
	q->tail=(q->tail+1)%NW;
	q->N++;
}

char dequeue(QUEUEWORDS *q){
	char item;
	strcpy(&item,q->q[q->head]);
	q->head=(q->head+1)%NW;
	q->N--;
	return item;
}