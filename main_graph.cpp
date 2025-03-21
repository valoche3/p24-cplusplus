#include "graph.h"
#include <stack>
#include <queue>

//ajouter une arête au graphe
void Graph::addEdge(const std::string& from, const std::string& to, double weight) {
    adjList[from].push_back(std::make_pair(to, weight));
}

//afficher les arêtes du graphe
void Graph::display() const {
    for (const auto& pair : adjList) {
        std::cout << pair.first << ": ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor.first << " (" << neighbor.second << ") ";
        }
        std::cout << std::endl;
    }
}

//parcours en profondeur récursif
void Graph::depthFirstSearchRecursive(const std::string& start) const {
    std::unordered_map<std::string, bool> visited;
    dfsRecursiveHelper(start, visited);
}

//fonction auxiliaire pour le DFS récursif
void Graph::dfsRecursiveHelper(const std::string& node, std::unordered_map<std::string, bool>& visited) const {
    visited[node] = true;
    std::cout << node << " ";

    for (const auto& neighbor : adjList.at(node)) {
        if (!visited[neighbor.first]) {
            std::cout << "-> (" << neighbor.first << " : " << neighbor.second << ") ";
            dfsRecursiveHelper(neighbor.first, visited);
        }
    }
}

//parcours en profondeur itératif
void Graph::depthFirstSearchIterative(const std::string& start) const {
    std::unordered_map<std::string, bool> visited;
    std::stack<std::string> stack;
    stack.push(start);

    while (!stack.empty()) {
        std::string node = stack.top();
        stack.pop();

        if (visited[node]) continue;

        visited[node] = true;
        std::cout << node << " ";

        for (const auto& neighbor : adjList.at(node)) {
            if (!visited[neighbor.first]) {
                stack.push(neighbor.first);
                std::cout << "-> (" << neighbor.first << " : " << neighbor.second << ") ";
            }
        }
    }
}

//parcours en largeur
void Graph::breadthFirstSearch(const std::string& start) const {
    std::unordered_map<std::string, bool> visited;
    std::queue<std::string> q;
    q.push(start);

    while (!q.empty()) {
        std::string node = q.front();
        q.pop();

        if (visited[node]) continue;

        visited[node] = true;
        std::cout << node << " ";

        for (const auto& neighbor : adjList.at(node)) {
            if (!visited[neighbor.first]) {
                q.push(neighbor.first);
                std::cout << "-> (" << neighbor.first << " : " << neighbor.second << ") ";
            }
        }
    }
}

int main() {
    Graph g;

    //ajouter des arêtes avec des poids
    g.addEdge("A", "B", 1.5);
    g.addEdge("A", "C", 2.5);
    g.addEdge("B", "D", 3.0);
    g.addEdge("C", "D", 4.5);
    g.addEdge("D", "E", 5.5);

    //afficher la structure du graphe
    std::cout << "Graph Structure:" << std::endl;
    g.display();
    std::cout << std::endl;

    //parcours en profondeur récursif
    std::cout << "Depth First Search Recursive from A:" << std::endl;
    g.depthFirstSearchRecursive("A");
    std::cout << std::endl;

    //parcours en profondeur itératif
    std::cout << "Depth First Search Iterative from A:" << std::endl;
    g.depthFirstSearchIterative("A");
    std::cout << std::endl;

    //parcours en largeur
    std::cout << "Breadth First Search from A:" << std::endl;
    g.breadthFirstSearch("A");
    std::cout << std::endl;

    return 0;
}
