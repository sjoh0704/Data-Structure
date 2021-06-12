#pragma once
#include"amGraph.h"
class uAMGraph:public amGraph
{
public:
	uAMGraph(int size, int initialValue = 0):amGraph(size){}
	virtual void addEdge(int fromV, int toV);
};
void
uAMGraph::addEdge(int fromV, int toV) {
	assert(0 <= fromV && fromV < n && 0 <= toV && toV < n);
	if (!edgeMember(fromV, toV)) {
		m++;
		am[fromV][toV] = 1;
		am[toV][fromV] = 1;
	}
}

