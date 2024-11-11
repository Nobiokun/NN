#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src,dest,weight;
};

bool BellmanFord(vector<Edge>& edges, int V, int E, int src, vector<int>& dist)
{
    dist[src] = 0;
    
    for(int i=1; i<V; i++)
    {
        for(int j=0; j<E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            
            if(dist[u] != INT_MAX && dist[u]+w < dist[v])
            {
                dist[v] = dist[u]+w;
            }
        }
    }
        
    for(int i=0; i<E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if(dist[u] != INT_MAX && dist[u]+w < dist[v])
        {
            cout<<"The graph contains negative cycle.";
            return false;
        }
    }
    return true;
}


int main()
{
    int V,E,src;
    cout<<"Enter number of Vertices: ";
    cin>>V;
    
    cout<<"Enter number of Edges: ";
    cin>>E;
    
    vector<Edge> edges(E) ;
    cout<<"Enter edges (source destination weight:";
    
    for(int i=0; i<E; i++)
    {
        cin>> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    
    cout<<"Enter source vertex: ";
    cin>>src;
    
    vector<int> dist(V+1,INT_MAX);
    
    if(BellmanFord(edges, V, E, src, dist))
    {
        for(int i=1; i<=V; i++)
        {
            cout<<i<<"\t\t"<<dist[i]<<endl;
        }
    }
    return 0;

}



