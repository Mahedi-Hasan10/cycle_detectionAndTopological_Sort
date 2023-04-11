/*
     Author : Mahedi-Hasan10
     Date : 05-04-2023
     Topic: Topological Sort
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> adj_list[N];
int visited[N];
stack<int> st;

void dfs(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }

    st.push(node);
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}