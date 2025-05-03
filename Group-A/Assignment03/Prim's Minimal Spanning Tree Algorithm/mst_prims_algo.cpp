#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertexCount;
    map<string, int> cityToIndex;
    map<int, string> indexToCity;
    vector<vector<pair<int, int>>> adj;

    Graph(){
        //Accept Vertex Count
        vertexCount = 6;
        
        //Accept City names
        vector<string> cities = {"X", "Y", "Z", "W", "V", "U"};

        //Accept "from-to-weight" from the user
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

        //Resize adj according to the vertex count
        adj.resize(vertexCount);

        //Create cityToIndex and indexToCity mappings
        for(int i=0; i<vertexCount; i++){
            indexToCity[i] = cities[i];
            cityToIndex[cities[i]] = i;
        }

        //Create the adjacency list
        for(auto &[u, v, w] : edges){
            int from = cityToIndex[u];
            int to = cityToIndex[v];

            adj[from].push_back({to, w});
            adj[to].push_back({from, w});
        }
    }

    void PrimMST(){
        //Priority queue to store the weights in ascending order
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        //inMST vector to store which nodes are already visited
        vector<bool> inMST(vertexCount, false);

        //parent vector to store the parent nodes of the MST
        vector<int> parent(vertexCount, -1);

        //key vector to store the minimum weight from the current node
        vector<int> key(vertexCount, INT_MAX);

        //Push weight and starting vertex
        pq.push({0, 0});
        inMST[0] = true;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;
            
            //Explore all adjacent neghbours using the adjacency list 'adj'
            for(auto &[v, weight] : adj[u]){
                //If the neighbour node is not yet visited and its weight is less than the 'key' weight then push in the key and update the parent and key values
                if(!inMST[v] && weight < key[v]){
                    pq.push({weight, v});
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }
        
        //Print the MST with its total weight
        int total_weight=0;
        cout<<"Minimum Spanning Tree: \nFrom - To - Weight\n";
        for(int i=1; i<vertexCount; i++){
            cout<<indexToCity[parent[i]]<<"  -  "<<indexToCity[i]<<"  -  "<<key[i]<<endl;
            total_weight += key[i];
        }
        cout<<"Total Weight: "<<total_weight;
    }
};

int main(){
    Graph g1;
    g1.PrimMST();
    return 0;
}

