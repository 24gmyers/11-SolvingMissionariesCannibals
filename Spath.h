#include <bits/stdc++.h>

using namespace std;
 

template <typename T>
class Spath{
    public:
        Spath(){};
        bool BFS(vector<T> adj[], T src, T dest, T v, T pred[], T dist[]){
            list<T> queue;
            bool visited[v];
            for (int i = 0; i < v; i++){
                visited[i] = false;
                dist[i] = INT_MAX;
                pred[i] = -1;
            }
            visited[src] = true;
            dist[src] = 0;
            queue.push_back(src);
            while (!queue.empty()) {
                T u = queue.front();
                queue.pop_front();
                for (int i = 0; i < adj[u].size(); i++) {
                    if (visited[adj[u][i]] == false) {
                        visited[adj[u][i]] = true;
                        dist[adj[u][i]] = dist[u] + 1;
                        pred[adj[u][i]] = u;
                        queue.push_back(adj[u][i]);
                        if (adj[u][i] == dest)
                            return true;
                    }
                }
            }
            return false;
        }
        vector<T> printShortestDistance(vector<int> adj[], T s, T dest, int v){
            T pred[v], dist[v];
            if (BFS(adj, s, dest, v, pred, dist) == false) {
                return;
            }
            vector<T> path;
            T crawl = dest;
            path.push_back(crawl);
            while (pred[crawl] != -1) {
                path.push_back(pred[crawl]);
                crawl = pred[crawl];
            }
            return path;
        }
    private:
        //nothing
};