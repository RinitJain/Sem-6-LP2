#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertexCount;
    map<string, int> cityToIndex;
    map<int, string> indexToCity;
    vector<vector<pair<int, int>>> adj;

    Graph(){
        vertexCount = 6;

        vector<string> cities = {"X", "Y", "Z", "W", "V", "U"};

        vector<tuple<string, string, int>> edges = {
            {"X", "Y", 4},
            {"X", "Z", 3},
            {"Y", "Z", 1},
            {"Y", "W", 2},
            {"Z", "W", 4},
            {"Z", "V", 5},
            {"W", "V", 7},
            {"V", "U", 3},
            {"W", "U", 8}
        };

        adj.resize(vertexCount);

        for(int i=0; i<vertexCount; i++){
            cityToIndex[cities[i]] = i;
            indexToCity[i] = cities[i];
        }

        for(auto &[u, v, w] : edges){
            int from = cityToIndex[u];
            int to = cityToIndex[v];

            adj[from].push_back({to, w});
            adj[to].push_back({from, w});
        }
    }

    void dijkstras(string source){
        vector<int>dist(vertexCount, INT_MAX);
        
        int src = cityToIndex[source];

        dist[src] = 0;

        priority_queue<pair<int , int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            //Explore all neighbours
            for(auto &[v, weight] : adj[u]){
                if(dist[v] > weight + dist[u]){
                    dist[v] = weight + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }

        // Print shortest paths
        cout << "Shortest paths from city " << source << ":\n";
        for (int i = 0; i < vertexCount; i++) {
            cout << source << " -> " << indexToCity[i] << " = ";
            if (dist[i] == INT_MAX)
                cout << "Unreachable\n";
            else
                cout << dist[i] << endl;
        }
    }
};

int main(){
    Graph g1;
    g1.dijkstras("X");
    return 0;
}