#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include "vertex.h"
#include "pair.h"

template <class T>
class Graph
{
public:
	// constructors, destructors, assignment
	// No default constructor
	Graph(int numVertices) throw (const char *) :numVertices(0)
	{

		if (numVertices <= 0)
			return;
		else
		{

		}
	
	}
	Graph(const Graph <T> & rhs) throw (const char *)
	{
		this->numVertices = rhs.numVertices;
	}

	~Graph()
	{
		
	}

	Graph <K, V> & operator = (const Graph <T> & rhs)
	{
		this->numVertices = rhs.numVertices;
		this->v = rhs.v;
		return *this;
	}

	// std container interfaces
	int size() { return bst.size(); }
	void clear() { bst.clear(); }

	// map specific interfaces
	bool isEdge() {}
	Pair findEdges(Vertex & vertex) {}
	std::vector findPath(Vertex & start, Vertex & end) {} // returns the shortest path between "start" and "end"
	void add(Vertex & one, Vertex & two) {} // two vertices representing new edge
	void add(Vertex & one, Set & two) {} // two vertices and a set of vertices
	
private:
	int numVertices;
	class VertexInfo //stores the vertex name and the adjacent vertices
	{
	public:
		T data;
		std::list <int> adjacencyList;
	};
	std::vector <VertexInfo> v;
};
#endif // Graph_h
