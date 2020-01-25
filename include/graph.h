#include <string>
#include <map>
#include <vector>

struct Node {
  std::string id;

  // Needed so we can use the Node class directly in the std::map
  bool operator<(const Node &node_other) {
    return id < node_other.id;
  }
};

struct Edge {
  Node from;
  Node to;
  double weight = 1;
};

struct Neighbour {
  Node node;
  double weight = 1;
};

enum GraphType {
  Undirected,
  Directed
};

/**
 * Uses a pair of hash tables to get the best of both worlds with
 * respect to adjacency matrices and adjacency lists; it can still
 * handle the sparsity that adjacency lists support and also O(1)
 * lookup times that adjacency matrices provide.
 */
class Graph {
  GraphType graph_type;
  std::map<Node, std::map<Node, double>> adjacency_map;
public:
  void add_edge(const Edge &edge);
  inline bool contains(const Node &node) const;
  std::vector<Node> get_nodes() const;
  std::vector<Edge> get_edges() const;
  std::vector<Neighbour> get_neighbours(const Node& node) const;
  Graph(GraphType graph_type) : graph_type(graph_type){};
  ~Graph(){};
};
