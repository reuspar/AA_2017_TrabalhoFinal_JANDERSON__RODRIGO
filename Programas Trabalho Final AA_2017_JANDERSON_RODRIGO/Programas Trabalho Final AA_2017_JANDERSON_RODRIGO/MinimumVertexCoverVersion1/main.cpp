// Program to print Vertex Cover of a given undirected graph
#include<iostream>
#include <string>
#include <list>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
// This class represents a undirected graph using adjacency list
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;  // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void printVertexCover();  // prints vertex cover
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected
}

// The function to print vertex cover
void Graph::printVertexCover()
{
    // Initialize all vertices as not visited.
    bool visited[V];
    int cont= 0;
    for (int i=0; i<V; i++)
        visited[i] = false;

    list<int>::iterator i;

    // Consider all edges one by one
    for (int u=0; u<V; u++)
    {
        // An edge is only picked when both visited[u] and visited[v]
        // are false
        if (visited[u] == false)
        {
            // Go through all adjacents of u and pick the first not
            // yet visited vertex (We are basically picking an edge
            // (u, v) from remaining edges.
            for (i= adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                     // Add the vertices (u, v) to the result set.
                     // We make the vertex u and v visited so that
                     // all edges from/to them would be ignored
                     visited[v] = true;
                     visited[u]  = true;
                     break;
                }
            }
        }
    }

    // Print the vertex cover
    for (int i=0; i<V; i++) {
        if (visited[i]) {
            cout << i << " ";
            cont++;
        }
    }
    cout <<"\n A quantidade de vertices minimos "<< cont << " \n";
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(1600);

    string word1;
    int a1, a2, b=0, cont=0 ;
    int num;
    ifstream ifs("C:\\Users\\rodri\\Desktop\\Testes_Data\\data1534-1.txt");
    while(ifs >> word1 >> a1 >> a2 ) {
             g.addEdge(a1,a2);
             cont++;
             if(a1>b){
                 b=a1;
             }
    }
        /*
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(3, 4);
        g.addEdge(4, 5);
        g.addEdge(5, 6);
        */
    cout << "\nA quantidade de vértices: "<< (b + 1) << "  A quantidade de arestas:  "<< cont<<"\n";

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

        g.printVertexCover();

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "\nA duracao em microsegundos:    "<< duration;

    return 0;
}