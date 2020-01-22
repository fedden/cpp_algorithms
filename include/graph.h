#include "vertex.h"
#include <vector>

/**
 * Abstract graph class.
 */
class Graph {

public:
  void add_vertices(std::vector<Vertex> vertices) = 0;
  Graph(){};
  ~Graph(){};
}

/**
 * Graph class that makes use of an adjacency list to represent the vertices.
 */
class AdjacencyListGraph : public Graph {

public:
  AdjacencyListGraph();

  void add_vertices(std::vector<Vertex> vertices);

private:
  std::vector<std::vector<int>> adjacency_list;
};

/**
 * Graph class that makes use of an adjacency matrix to represent the vertices.
 */
class AdjacencyMatrixGraph : public Graph {

public:
  AdjacencyMatrixGraph();

  void add_vertices(std::vector<Vertex> vertices);

private:
  std::vector<std::vector<int>> adjacency_matrix;
};
