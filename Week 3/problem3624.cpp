// problem 3624
// http://poj.org/problem?id=3624
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int N, M;
    vector<int> weights;
    vector<int> desirabilities;
    int weight, desirability;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> weight >> desirability;
        weights.push_back(weight);
        desirabilities.push_back(desirability);
    }

    vector<int> dp (M + 1);

    for (int i = 0; i < N; i++) {
        for (int j = M; j >= weights[i]; j--) {
            dp[j] = max(dp[j], desirabilities[i] + dp[j-weights[i]]);
        }
    }
    
    cout << dp[M] << endl;
    
    // for (int i = 0; i <= M; i++) {
    //     cout << dp[i] << " ";
    // }

    return 0;
}