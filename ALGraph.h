#pragma once
#include"Graph.h"
#include"ListIter.h"
typedef List<int> intList;
typedef ListIter<int> intListIter;
class ALGraph:public Graph
{
public:
	ALGraph(int size) :Graph(size) {
		vertexList = new intList[n];
		assert(vertexList);
	}
	friend class NeighborIter;
protected:
	intList* vertexList;
	
};


class NeighborIter :public intListIter {
public:
	NeighborIter(const ALGraph& G, int startVertex) :
		intListIter(G.vertexList[startVertex], G.n)
	{
		assert(startVertex < G.n);
	}
};



