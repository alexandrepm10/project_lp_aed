//
// Created by Alexandre Marques 31202 on 13/12/2018.
//

#ifndef PROJECT_AED_LP_WORDS_H
#define PROJECT_AED_LP_WORDS_H
#define NW 3

typedef struct QueueWords{
	char *q[NW];
	int tail, head, N;
}QUEUEWORDS;


void clientQueues();
void initQueues(QUEUEWORDS *q);
void enqueue(QUEUEWORDS *q, char *item);
char dequeue(QUEUEWORDS  *q);

#endif //PROJECT_AED_LP_WORDS_H
