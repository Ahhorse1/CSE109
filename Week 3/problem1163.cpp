// problem 1163
// http://poj.org/problem?id=1163
#include <iostream>

using namespace std;

int main() {
    int lines;
    int numbers[100][100] = {};
    int sums[100][100] = {};
    int max_sum = 0;

    cin >> lines;
    for (int i = 1; i <= lines; i++) {
        for(int j = 0; j < i; j++) {
            int num;
            cin >> num;
            numbers[i-1][j] = num;
        }
    }

    sums[0][0] = numbers[0][0];

    for (int i = 1; i < lines; i++) {
        sums[i][0] = sums[i-1][0] + numbers[i][0];
        sums[i][i] = sums[i-1][i-1] + numbers[i][i]; 
        for (int j = 1; j < i; j++) {
            if (sums[i-1][j] > sums[i-1][j-1]) {
                sums[i][j] = sums[i-1][j] + numbers[i][j];
            }
            else {
                sums[i][j] = sums[i-1][j-1] + numbers[i][j];
            }
        }
    }
    
    // for (int i = 0; i < lines; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << sums[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < lines; i++) {
        if (sums[lines-1][i] > max_sum) {
            max_sum = sums[lines-1][i];
        }
    }
    cout << max_sum << endl;
    
    return 0;
}