#pragma once
class Graph
{
public:
	Graph(int size) :n(size), m(0) {}
	virtual int vertexSize() { return n; }
	virtual int edgeSize() { return m; }
	virtual void addEdge(int fromV, int toV) = 0;
protected:
	int n;
	int m;

};

