#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include<stdio.h>
#include <stdlib.h>
#include "functions.c"
#define MAX 100


void addEdge(int v, int w);

void topologicalSortUtil(int v, int visited[], int stack[], int *stackSize) ;

void topologicalSort();

void readValues() ;

#endif
