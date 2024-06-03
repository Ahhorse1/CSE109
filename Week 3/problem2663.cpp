// problem 2663
// http://poj.org/problem?id=2663
#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n;
    int ways[31][8];

    ways[0][7] = 1;

    for (int i = 1; i < 31; i++) {
        ways[i][0] += ways[i-1][7];

        ways[i][1] += ways[i-1][6];

        // ways[i][2] += ways[i-1][5];

        ways[i][3] += ways[i-1][7];
        ways[i][3] += ways[i-1][4];

        ways[i][4] += ways[i-1][3];

        // ways[i][5] += ways[i-1][2];

        ways[i][6] = ways[i-1][0];
        ways[i][6] += ways[i-1][1];

        ways[i][7] += ways[i-1][6];
        ways[i][7] += ways[i-1][3];
        ways[i][7] += ways[i-1][0];
    }

    cin >> n; 
    while (n != -1) {
        cout << ways[n][7];
        cin >> n;
    }
    return 0;
}