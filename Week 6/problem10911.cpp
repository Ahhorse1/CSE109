// problem 10911
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1852
#include <iostream>
#include <vector>
#include <limits>
#include <float.h>
#include <math.h>

using namespace std;
vector<pair<int,int>> houses;
vector<vector<float>> distances (16, vector<float>(16,0));
vector<float> dp;

float recursion(int place) {
    if (place == dp.size()-1) {
        return 0;
    }
    else if (dp[place] != -1){
        return dp[place];
    }

    float current = FLT_MAX;
    for(int i = 0; i < houses.size(); i++) {
        if (!(1 & (place >> i))) {
            for(int j = i + 1; j < houses.size(); j++) {
                if (!(1 & (place >> j))) {
                    current = min(current, distances[i][j] + recursion(place | (1 << i) | (1 << j)));
                }
            }
        }
    }
    
    return dp[place] = current;
}

float distance(pair<int,int> p1, pair<int,int> p2) {
    return sqrt(pow((p1.first - p2.first),2) + pow((p1.second - p2.second),2));
}

int main() {
    int N;
    int count = 1;

    cin >> N;
    while (N) {
        houses.clear();
        dp.clear();

        int totalHouses = 2 * N;
        dp = vector<float> ((1 << totalHouses), -1);

        for(int i = 0; i < totalHouses; i++) {
            pair<int,int> house;
            string name;

            cin >> name >> house.first >> house.second;
            houses.push_back(house);
        }

        for(int i = 0; i < totalHouses; i++) {
            for(int j = i + 1; j < totalHouses; j++) {
                float dis = distance(houses[i],houses[j]);
                distances[i][j] = dis;
                distances[j][i] = dis;
            }
        }
        
        float minDistance = recursion(0);

        printf("Case %d: %.2f\n", count, minDistance);

        cin >> N;
        count++;
    }
    return 0;
}