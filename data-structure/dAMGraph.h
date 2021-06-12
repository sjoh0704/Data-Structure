#pragma once
#include "amGraph.h"
class dAMGraph:public amGraph 
{
public:
	dAMGraph(int size, int initialValue = 0) :
		amGraph(size) {}
	virtual void addEdge(int fromV, int toV);
};

void
dAMGraph::addEdge(int fromV, int toV) {
	assert(0 <= fromV && fromV < n && 0 <= toV && toV < n);
	if (!edgeMember(fromV, toV)) {
		am[fromV][toV] = 1;
		m++;
	}
}

