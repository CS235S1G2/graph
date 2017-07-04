#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <set>
#include "vertex.h"
#include "pair.h"

class VertexInfo;
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
	Graph(const Graph & rhs) throw (const char *)
	{
		this->numVertices = rhs.numVertices;
	}

	~Graph()
	{
		numVertices = 0;
	}

	Graph & operator = (const Graph & rhs)
	{
		this->numVertices = rhs.numVertices;
		this->v = rhs.v;
		return *this;
	}

	// std container interfaces
	int size() { return numVertices; }
	void clear() { numVertices = 0; }

	// map specific interfaces
	bool isEdge() {}
	Pair<Vertex,Vertex> findEdges(Vertex & vertex) {}
	std::vector<Vertex> findPath(Vertex & start, Vertex & end) {} // returns the shortest path between "start" and "end"
	void add(Vertex & one, Vertex & two) {} // two vertices representing new edge
	void add(Vertex & one, std::set<Vertex> & two) {} // two vertices and a set of vertices
	
private:
	int numVertices;
	class VertexInfo //stores the vertex name and the adjacent vertices
	{
	public:
		Vertex data;
		std::list <int> adjacencyList;
	};
	std::vector <VertexInfo> v;
};
#endif // Graph_h
