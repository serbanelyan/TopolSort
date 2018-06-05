#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int V, E, **adj;

int main()
{
	readValues();
	topologicalSort();

	return 0;
}

