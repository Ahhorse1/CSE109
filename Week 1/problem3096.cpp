#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    string str;
    vector<vector<bool>> pairs (26, vector<bool> (26, false));
    vector<vector<bool>> reset (26, vector<bool> (26, false));
    bool isSuprising = true;

    getline(cin, str);

    while (str != "*") {   
        for(int i = 1; i < str.length(); i++) {
            pairs = reset;

            for(int j = 0; j < str.length()-i; j++) {
                if (pairs[str[j]%26][str[j+i]%26]) {
                    isSuprising = false;
                    break;
                }
                else {
                    pairs[str[j]%26][str[j+i]%26] = 1;
                }
            }
            if (!isSuprising)
                break;
        }
        
        if (isSuprising)
            cout << str << " is surprising." << endl;
        else 
            cout << str << " is NOT surprising." << endl;
        
        isSuprising = true;
        getline(cin, str);
    }

    return 0;
}