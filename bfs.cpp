#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;                       // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int vertices) : V(vertices)
    {
        adjList.resize(V);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void BFS(int startVertex)
    {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        queue<int> q;                   // Create a queue for BFS

        visited[startVertex] = true; // Mark the current node as visited and enqueue it
        q.push(startVertex);

        while (!q.empty())
        {
            startVertex = q.front(); // Dequeue a vertex from queue and print it
            cout << startVertex << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex.
            // If an adjacent has not been visited, then mark it visited and enqueue it
            for (int i = 0; i < adjList[startVertex].size(); ++i)
            {
                int adjVertex = adjList[startVertex][i];
                if (!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }
    }
};

int main()
{
    int V = 6; // Number of vertices
    Graph graph(V);
    int x,y;
    // Adding edges to the graph
    // for (size_t i = 0; i < V; i++)
    // {
    //     cin>>x>>y;
    //     graph.addEdge(x,y);
    // }
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    int startVertex = 0; // Starting vertex for BFS

    cout << "Vertices reachable from vertex " << startVertex << " using BFS: ";
    clock_t start,end;
    start=clock();
    graph.BFS(startVertex);
    cout << endl;
    end=clock();
    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    cout<<"\ntime spent: "<<time_spent;
    return 0;
}
