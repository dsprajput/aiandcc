#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v){
    for(int i=0; i<v; i++){
        for(auto x:adj[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

void dfsRec(vector<int> adj[], int s, bool visited[]){
    visited[s]=true;
    cout<<s<<" ";
    for(int u: adj[s]){
        if(visited[u]==false){
            dfsRec(adj, u, visited);
        }
    }
}

void dfs(vector<int> adj[], int v, int s){
    bool visited[v];
    for(int i=0; i<v; i++){
        visited[i]=false;
    }
    dfsRec(adj, s, visited);
}

void bfs(vector<int> adj[], int v, int s){
    bool visited[v+1];
    for(int i=0; i<v; i++){
        visited[i]=false;
    }
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int x:adj[u]){
            if(visited[x]==false){
                visited[x]=true;
                q.push(x);
            }
        }
    }
    
}

int main(){
    int v=4;
    vector<int> adj[v];
    addedge(adj, 0, 1);
    addedge(adj, 0, 2);
    addedge(adj, 1, 2);
    addedge(adj, 1, 3);
    printGraph(adj, v);
    bfs(adj, 4, 3);
    cout<<"\n";
    dfs(adj, 4, 2);
    cout<<"\n";
    return 0;
}