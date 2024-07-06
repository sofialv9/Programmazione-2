#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>


template <typename T>
class Graph;

template <typename T>
class GNode {
public:
    GNode(T data) : data(data) {}

    void addEdge(GNode<T>* node) { edges.push_back(node); }

    T getData() const { return data; }

    std::string toString() const {
        std::stringstream ss;
        ss << data;
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const GNode& g) {
        os << g.toString();
        return os;
    }

private:
    T data;
    std::vector<GNode<T>*> edges;

    friend class Graph<T>;
};

template <typename T>
class Graph {
public:
    ~Graph() {
        for(auto node : nodes) {
            delete node;
        }
    }

    void addEdge(T src, T dest) {
        GNode<T>* srcNode = this->BFSSearch(src);
        GNode<T>* destNode = this->BFSSearch(dest);

        if(not srcNode) {
            srcNode = new GNode<T>(src);
            nodes.push_back(srcNode);
        }
        if(not destNode) {
            destNode = new GNode<T>(dest);
            nodes.push_back(destNode);
        }

        srcNode->addEdge(destNode);
    }

    GNode<T>* BFSSearch(T key) const {
        if(this->nodes.empty()) return nullptr;

        std::unordered_map<GNode<T>*, bool> visited;
        std::queue<GNode<T>*> nextNodes;

        nextNodes.push(nodes[0]);
        visited[nodes[0]] = true;

        while (not nextNodes.empty()) {
            GNode<T>* node = this->getBSFNext(nextNodes, visited);
            if(node and node->getData() == key) return node;
        }

        return nullptr;
    }

    std::string BFStoString() const {
        std::stringstream ss;
        ss << "Graph: " << std::endl;
        this->loadSStream(ss);

        return ss.str();
    }

private:
    std::vector<GNode<T>*> nodes;

    GNode<T>* getBSFNext(std::queue<GNode<T>*>& nextNodes, std::unordered_map<GNode<T>*, bool>& visited) const {
        if (nextNodes.empty()) return nullptr;

        GNode<T>* removed = nextNodes.front();
        nextNodes.pop();

        for (const auto& neighbor : removed->edges) {
            if (not visited[neighbor]) {
                visited[neighbor] = true;
                nextNodes.push(neighbor);
            }
        }

        return removed;
    }

    void loadSStream(std::stringstream& ss) const {
        if(this->nodes.empty()) ss << "Empty graph";
        else {
            std::unordered_map<GNode<T>*, bool> visited;
            std::queue<GNode<T>*> nextNodes;

            nextNodes.push(this->nodes[0]);
            visited[this->nodes[0]] = true;

            while(not nextNodes.empty()) {
                GNode<T>* node = getBSFNext(nextNodes, visited);
                if(node) ss << *node << std::endl;
            }
        }
    }
};

#define MAX_NODES 40

int main() {
    try {
        Graph<int> g;

        g.addEdge(1, 2);
        g.addEdge(2, 1);

        GNode<int>* result = g.BFSSearch(1);

        if (result) std::cout << "Found node with data: " << result->getData() << std::endl;
        else std::cout << "Node not found" << std::endl;

        std::cout << g.BFStoString() << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
