
#include "graph.h"
#include "vertex.h"
#include "list.h"
#include "set.h"
#include "vector.h"

Graph :: Graph(const Graph & rhs) throw (const char *)
{   
   try 
   {
      *this = rhs;
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate memory for the graph";
   }
}

Graph & Graph :: operator = (const Graph & rhs) throw (const char *)
{
   numVertices = rhs.numVertices;
   int size = numVertices * numVertices;
   data = rhs.data;
   try
   {
      adjMatrix = new bool[size];
      for (int i = 0; i < size; i++)
         adjMatrix[i] = rhs.adjMatrix[i];
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: Unable to allocate memory for the graph";
   }
   return *this;
}


void Graph :: add(const Vertex & v1, const Vertex & v2)
{
   // insert into the data set
   data.insert(v1);
   data.insert(v2);
   
   // add the edge: width * row + col
   adjMatrix[v1.index() * numVertices + v2.index()] = true;
}

void Graph :: add(const Vertex & v1, const Set <Vertex> & set)
{
   data.insert(v1);
   
   SetConstIterator <Vertex> it;   
   for (it = set.cbegin(); it != set.cend(); ++it)
   {
      data.insert(*it);
      int col = (*it).index();
      adjMatrix[v1.index() * numVertices + col] = true;
   }
}

bool Graph :: isEdge(const Vertex & v1, const Vertex & v2) const
{
   return adjMatrix[v1.index() * numVertices + v2.index()];
}

Set <Vertex> Graph :: findEdges(const Vertex & v1) const
{
   Set <Vertex> rSet;
   // iterate through data set
   SetConstIterator <Vertex> it;   
   for (it = data.cbegin(); it != data.cend(); ++it)
   {
      if (isEdge(v1, *it))
         rSet.insert(*it);
   }
   
   return rSet;
}

Vector <Vertex> Graph :: findPath(const Vertex & v1, const Vertex & v2) const
{
   Vector <Vertex> shortestDist;
   findEdges(data.begin); 
}
