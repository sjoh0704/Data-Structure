#pragma once
#include "ALGraph.h"
class DALGraph: public ALGraph
{
public:
	DALGraph(int size) :ALGraph(size) {};
	virtual void addEdge(int fromV, int toV);
};
void 
DALGraph::addEdge(int fromV, int toV) {
	assert(0 <= fromV && 0 < n && 0 <= toV && toV < n);
	vertexList[fromV].insert(toV);
	m++;
}

