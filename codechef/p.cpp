// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <bits/stdc++.h>
using namespace std;

// utility function to form edge between two vertices
// source and dest
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex

int printShortestDistance(vector<int> adj[], int s,
                          int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];

    if (BFS(adj, s, dest, v, pred, dist) == false)
    {
        return INT_MAX;
    }

    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1)
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // // distance from source is in distance array
    // cout << "Shortest path length is : "
    //      << dist[dest];

    // // printing path from source to destination
    // cout << "\nPath is::\n";
    // for (int i = path.size() - 1; i >= 0; i--)
    //     cout << path[i] << " ";
    return dist[dest];
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // no. of vertices
        int n, m, k;
        cin >> n >> m >> k;

        // array of vectors is used to store the graph
        // in the form of an adjacency list
        vector<int> adj[n];

        for (int i = 0; i < m; ++i)
        {
            int v, u;
            cin >> u >> v;
            add_edge(adj, u - 1, v - 1);
        }

        map<int, int> special;
        for (int i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            special[temp] = 1;
        }

        // Creating graph given in the above diagram.
        // add_edge function takes adjacency list, source
        // and destination vertex as argument and forms
        // an edge between them.

        int q;
        cin >> q;

        while (q--)
        {
            int u;
            cin >> u;

            if (special.find(u) == special.end())
            {
                int mini = INT_MAX;
                for (auto x : special)
                {
                    mini = min(mini, printShortestDistance(adj, u - 1, x.first - 1, n));
                }
                cout << ((mini >= INT_MAX) ? -1 : mini) << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}