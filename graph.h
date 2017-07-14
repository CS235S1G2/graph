

#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "list.h"
#include "set.h"
#include "vector.h"
#include <iostream>
using namespace std;

class Graph
{
   public:
      Graph(int numVertices) throw (const char *)
      {
         this->numVertices = numVertices;
         int size = numVertices * numVertices;
         // try
         try
         {  
            adjMatrix = new bool[size];
            
            // initialize to false
            for (int i = 0; i < size; i++)
               adjMatrix[i] = false;
         }
         catch(std::bad_alloc)
         {
            throw "ERROR: Unable to allocate memory for the graph";
         }
      }
      
      Graph(const Graph & rhs) throw (const char *);
      ~Graph()
      {
         clear();
      }
      Graph & operator = (const Graph & rhs) throw (const char *);
      
      int size() const { return numVertices; }
      void clear()
      {
         delete [] adjMatrix;
         adjMatrix = NULL;
         numVertices = 0;   
      }

	  Vertex begin() { 
		  SetIterator<Vertex>it = data.begin();
		  cout << "BEGIN" << (*it);
		  return (*it); }
	  Vertex end() {
		  SetIterator<Vertex>it = data.end();
		  cout << "END" << (*it);
		  return (*it);
	  }

      void add(const Vertex & v1, const Vertex & v2);
      void add(const Vertex & v1, const Set <Vertex> & set);
      
      bool isEdge(const Vertex & v1, const Vertex & v2) const;
      
      Set <Vertex> findEdges(const Vertex & v1) const;
      
      Vector <Vertex> findPath(const Vertex & v1, const Vertex & v2) const;
   
   private:
      bool * adjMatrix;
      Set <Vertex> data;
      int numVertices;
   
};


#endif // GRAPH_H