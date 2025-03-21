#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class Graph {
private:
    //structure 
    std::unordered_map<std::string, std::vector<std::pair<std::string, double> > > adjList;

public:
    //ajouter une arête du sommet 'from' au sommet 'to' avec un poids 'weight'
    void addEdge(const std::string& from, const std::string& to, double weight);

    //afficher la structure du graphe
    void display() const;

    //parcours en profondeur récursif
    void depthFirstSearchRecursive(const std::string& start) const;

    //parcours en profondeur itératif
    void depthFirstSearchIterative(const std::string& start) const;

    //parcours en largeur
    void breadthFirstSearch(const std::string& start) const;

private:
    //fonction de parcours récursif
    void dfsRecursiveHelper(const std::string& node, std::unordered_map<std::string, bool>& visited) const;
};


