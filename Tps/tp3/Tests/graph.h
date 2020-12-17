#include <iostream>
#include <vector>

using namespace std;

template <class N, class E> class Edge;
template <class N> class NodeAlreadyExists;
template <class N> class NodeDoesNotExist;
template <class N> class EdgeAlreadyExists;
template <class N> class EdgeDoesNotExist;



template <class N, class E>
class Node {
public:
    N info;
        vector< Edge<N,E> > edges;
    explicit Node(N inf) : info(inf) {}
};

template <class N, class E>
class Edge {
public:
    E value;
    Node<N,E> *destination;
    Edge(Node<N,E> *dest, E val) {
        value = val;
        destination = dest;
    }
};

template <class N, class E>
class Graph {
    vector< Node<N,E> *> nodes;
public:

    Graph() {
        nodes.clear();
    }

    ~Graph() = default;

    Graph & addNode(const N &inf) {
        for (size_t i = 0; i < nodes.size(); i++)
            if (nodes[i]->info == inf)
                throw NodeAlreadyExists<N>(inf);
        auto *n1 = new Node<N, E>(inf);
        nodes.push_back(n1);
        return *this;
    }
    Graph & addEdge(const N &begin, const N &end, const E &val) {
        bool check = false;
        for (auto node : nodes) {
            if (node->info == begin) {
                for (auto edge : node->edges) {
                    if (edge.destination->info == end)
                        throw EdgeAlreadyExists<N>(begin, end);
                }
                auto *n1 = new Node<N, E>(end);
                auto *e1 = new Edge<N, E>(n1, val);
                node->edges.push_back(*e1);
                check = true;
            }
        }
        if (!check)
            throw NodeDoesNotExist<N>(begin);
        return *this;
    }

    Graph & removeEdge(const N &begin, const N &end) {
        for (size_t i = 0; i < nodes.size(); i++) {
            if (nodes[i]->info == begin) {
                for (size_t j = 0; j < nodes[i]->edges.size(); i++) {
                    if (nodes[i]->edges[j].destination->info == end) {
                        nodes[i]->edges.erase(nodes[i]->edges.begin()+j);
                        return *this;
                    }
                }
                throw EdgeDoesNotExist<N>(begin,end);
            }
        }
        throw NodeDoesNotExist<N>(begin);
    }

    E & edgeValue(const N &begin, const N &end) { // ver pq é q não dá da outra forma
        for (size_t i = 0; i < nodes.size(); i++) {
            if (nodes[i]->info == begin) {
                for (size_t j = 0; j < nodes[i]->edges.size(); i++) {
                    if (nodes[i]->edges[j].destination->info == end) {
                        return (nodes[i]->edges[j].value);
                    }
                }
                throw EdgeDoesNotExist<N>(begin,end);
            }
        }
        throw NodeDoesNotExist<N>(begin);
    }

    /*E & edgeValue(const N &begin, const N &end) {
        for (auto node: nodes) {
            if (node->info == begin) {
                for (auto edge: node->edges) {
                    if (edge.destination->info == end)
                        return edge.value;
                }
            }
            throw EdgeDoesNotExist<N>(begin,end);
        }
        throw NodeDoesNotExist<N>(begin);
    }*/

    unsigned numEdges() const {
        int sum_edges = 0;
        for (size_t i = 0; i < nodes.size(); i++)
            sum_edges += nodes[i]->edges.size();
        return sum_edges;
    }

    unsigned numNodes() const {return nodes.size();};

    void print(std::ostream &os) const {
        for (size_t i = 0; i < nodes.size(); i++) {
            os << "( " << nodes[i]->info;
            for (size_t j = 0; j < nodes[i]->edges.size(); j++) {
                os << "[ " <<nodes[i]->edges[j].destination->info << " " << nodes[i]->edges[j].value << "] ";
            }
            os << ") ";
       }
    }

    //friend std::ostream & operator<<(std::ostream &out, const Graph<N,E> &g);
};

template <class N, class E>
std::ostream & operator<<(std::ostream &out, const Graph<N,E> &g) {
    g.print(out);
    return out;
}


// exception NodeAlreadyExists
template <class N>
class NodeAlreadyExists
{
public:
    N info;
    explicit NodeAlreadyExists(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NodeAlreadyExists<N> &no)
{ out << "Node already exists: " << no.info; return out; }


// exception NodeDoesNotExist
template <class N>
class NodeDoesNotExist {
public:
    N info;

    explicit NodeDoesNotExist(N inf) {
        info = inf;
    }
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NodeDoesNotExist<N> &no)
{ out << "Node does not exist: " << no.info; return out; }

// exception EdgeAlreadyExist
template<class N>
class EdgeAlreadyExists {
public:
    N info1, info2;
    EdgeAlreadyExists(N inf1, N inf2) {
        info1 = inf1;
        info2 = inf2;
    };

};

template<class N>
std::ostream & operator<<(std::ostream &out, const EdgeAlreadyExists<N> &no)
{ out << "Edge already exists: " << no.info1 << " , " << no.info2; return out; }

template<class N>
class EdgeDoesNotExist {
public:
    N info1, info2;
    EdgeDoesNotExist(N inf1, N inf2) {
        info1 = inf1;
        info2 = inf2;
    };

};

template<class N>
std::ostream & operator<<(std::ostream &out, const EdgeDoesNotExist<N> &no)
{ out << "Edge does not exist: " << no.info1 << " , " << no.info2; return out; }

