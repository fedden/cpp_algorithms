#include "graph.h"


void Graph::add_edge(const Edge &edge) { 
  adjacency_map[edge.from][edge.to] = edge.weight;
  if (graph_type == GraphType::Undirected) {
    // Add link for reverse direction.
    adjacency_map[edge.to][edge.from] = edge.weight;
  } else {
    // Add empty map here so we know the "to" node.id is present.
    adjacency_map[edge.to] = {};
  }
}

inline bool Graph::contains(const Node &node) const {
  // Whether the graph is directed or undirected, it should contain this node.id 
  // if it's been added.
  return bool(adjacency_map.count(node));
}

std::vector<Node> Graph::get_nodes() const {
  std::vector<Node> nodes;
  nodes.reserve(adjacency_map.size());
  for (auto it = adjacency_map.begin(); it != adjacency_map.end(); ++it) {
    nodes.push_back(it->first);
  }
  return nodes;
}

std::vector<Edge> Graph::get_edges() const {
  
}

std::vector<Neighbour> Graph::get_neighbours(const Node& node) const {
  
}
