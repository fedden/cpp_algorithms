#include "graph.h"


void AdjacencyListGraph::add_vertices(std::vector<Vertex> vertices) {
  const std::size_t n_vertices = vertices.size();

}


void AdjacencyMatrixGraph::add_vertices(std::vector<Vector> vertices) {
  // Setup the matrix first.
  const std::size_t n_vertices = vertices.size();
  adjacency_matrix = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices, 0));
}
