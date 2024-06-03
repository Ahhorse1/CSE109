// problem 11631
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2678
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> &set_reps, int x) {
    while (x != set_reps[x])
        x = set_reps[x];
    return x;
}

void join(vector<int> &set_reps, vector<int> &set_sizes, int x, int y) {
    x = find(set_reps, x);
    y = find(set_reps, y);
    if (set_sizes[x] < set_sizes[y])
        swap(x, y);
    set_sizes[x] += set_sizes[y];
    set_reps[y] = x;
}

int main() {
    int m, n;

    cin >> m >> n;
    while (m + n != 0) {
        int money = 0;
        int totalMoney = 0;
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            totalMoney += z;
            edges.push_back(pair<int,pair<int,int>>(z, pair<int,int>(x,y)));
        }

        sort(edges.begin(), edges.end());

        vector<int> set_reps (m, 0);
        vector<int> set_sizes (m, 0);

        for(int i = 0; i < m; i++) {
            set_reps[i] = i;
            set_sizes[i] = 1;
        }

        for (int i = 0; i < edges.size(); i++) {
            int x, y;
            x = edges[i].second.first;
            y = edges[i].second.second;
            if (find(set_reps, x) != find(set_reps, y)) {
                money += edges[i].first;
                // cout << "Adding Edge " << x << " " << y << " cost: " << money << endl;
                join(set_reps, set_sizes, x, y);
            }

            if (set_sizes[find(set_reps, 0)] == m) {
                break;
            }
        }
        // cout << totalMoney << endl;
        // cout << money << endl;
        cout << totalMoney - money << endl;
        
        cin >> m >> n;
    }
    return 0;
}