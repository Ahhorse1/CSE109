#include <iostream>
#include <list>

using namespace std;

int main() {
    int N, k, m;

    cin >> N >> k >> m;
    while (N + k + m != 0) {
        list<int> people;
        for (int i = 1; i <= N; i++) {
            people.push_back(i);
        }
        auto counter = people.begin();
        auto clock = people.end()--;
        while (!people.empty()) {
            if (people.size() == 1) {
                cout << "  " << *people.begin();
                break;
            }
            for(int i = 1; i < k; i++){
                counter++;
            }
            for(int i = 1; i < m; i++){
                clock--;
            }
            if (clock == counter){
                cout << " " << *clock;  
                people.erase(counter++);
                people.erase(clock--);
            }
            else {
                cout << "  " << *counter << "  " << *clock;
                people.erase(counter++);
                people.erase(clock--);
            }

            if (!people.empty()) {
                cout << ",";
            }

        }
        cin >> N >> k >> m;
    }
    return 0;
}