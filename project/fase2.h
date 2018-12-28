//
// Created by alexa on 22/11/2018.
//

#ifndef PROJECT_AED_LP_FASE2_H
#define PROJECT_AED_LP_FASE2_H

//#define NL 5
//#define NW 5
#include "malloc.h"
#include "stdlib.h"
#include "matrix.h"

typedef struct Point {
	char letter;
	int x;
	int y;
} POINT;

typedef struct Coord {
	struct Point N;
	struct Point NE;
	struct Point E;
	struct Point SE;
	struct Point S;
	struct Point SW;
	struct Point W;
	struct Point NW;
} COORD;

void fase2();


#endif //PROJECT_AED_LP_FASE2_H
