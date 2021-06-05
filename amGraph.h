#pragma once
#include"Graph.h"
#include<assert.h>
class amGraph: public Graph
{
public:
	amGraph(int size);
	virtual bool edgeMember(int fromV, int toV);
protected:
	int** am;
};

amGraph::amGraph(int size):Graph(size){
	am = new int* [n];
	assert(am);
	for (int i = 0; i < n; i++) {
		am[i] = new int[n];
		assert(am[i]);
		for (int j = 0; j < n; j++)
			am[i][j] = 0;
	}
}
bool amGraph::edgeMember(int fromV, int toV) {
	assert(0 <= fromV && fromV < n && 0 <= toV && toV < n);
	return bool(am[fromV][toV] != 0);
}

