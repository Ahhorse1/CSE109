// problem 154 recyling - online judge
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=90
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int counts[5][5] = {0};
    int zeroes[5][5] = {0};
    string line;
    map<char, int> coding = {
        {'r', 0},{'o', 1}, {'y', 2}, {'g', 3}, {'b', 4}, 
        {'P', 0},{'G', 1}, {'A', 2}, {'S', 3}, {'N', 4}
    };

    vector<vector<pair<int,int>>> cities; 

    cin >> line;

    while (line[0] != '#') {
        if (line[0] != 'e') {
            vector<pair<int,int>> city;
            for (int i = 0; i < line.length(); i = i + 4){
                int color = coding[line[i]];
                int type = coding[line[i+2]];
                counts[color][type] += 1;
                city.push_back(pair<int,int>(color,type));
            }
            cities.push_back(city);
        }
        else {            
            int maxPairs = 0;
            int modelCity = 0;
            int count = 1;
            for(const auto& city: cities){
                int sum = 0;
                for(const auto& pairing:city){
                    sum += counts[pairing.first][pairing.second];
                }
                if (sum > maxPairs) {
                    maxPairs = sum;
                    modelCity = count;
                }
                count++;
            }
            cout << modelCity << endl;

            cities.clear();

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    counts[i][j] = 0;
                }
            }
        }
        cin >> line;
    }
    return 0;
}

/*
Test Cases
r/P,o/G,y/S,g/A,b/N
r/G,o/P,y/S,g/A,b/N
r/P,y/S,o/G,g/N,b/A
r/P,o/S,y/A,g/G,b/N
e
r/G,o/P,y/S,g/A,b/N
r/P,y/S,o/G,g/N,b/A
r/P,o/S,y/A,g/G,b/N
r/P,o/G,y/S,g/A,b/N
ecclesiastical
#
*/