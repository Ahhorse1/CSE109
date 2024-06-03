// problem 10986
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++ ) {
        int n, m, S, T;

        cin >> n >> m >> S >> T;
        
        vector<vector<pair<int,int>>> adjacency_list (n);

        for (int j = 0; j < m; j++ ){
            int server1, server2, latency;
            cin >> server1 >> server2 >> latency;

            adjacency_list[server1].push_back(pair<int,int>(latency, server2));
            adjacency_list[server2].push_back(pair<int,int>(latency, server1));
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> shortest_path (n, INT_MAX);
        vector<bool> visited (n, false);

        pq.push({0, S});
        shortest_path[S] = 0;


        while (!pq.empty()) {
            pair<int,int> edge = pq.top();
            pq.pop();
            int node = edge.second;
            if (visited[node])
                continue;
            visited[node] = true;
            for (const auto &edge: adjacency_list[node]) {
                int weight = edge.first;
                int neighbor = edge.second;
                if (shortest_path[neighbor] > shortest_path[node] + weight) {
                    shortest_path[neighbor] = shortest_path[node] + weight;
                    pq.push({shortest_path[neighbor], neighbor});
                }
            }
        }

        cout << "Case #" << i+1 << ": ";
        
        if (shortest_path[T] != -1)
            cout << shortest_path[T] << endl;
        else
            cout << "unreachable" << endl;
    }
    return 0;
}