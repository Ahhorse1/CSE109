// problem 628 online judge
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=569
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generate_passwords(const vector<string> &current, const vector<string> &dictionary, int isNum) {
    vector<string> new_passwords;
    if (current.empty()) {
        if (isNum) {
            for(int i = 0; i < 10; i++ ) {
                new_passwords.push_back(to_string(i));
            }
        }
        else {
            for(const auto& word: dictionary) {
                new_passwords.push_back(word);
            }
        }
        return new_passwords;
    }
    if (isNum) {
        for(const auto &password: current){
            for (int i = 0; i < 10; i++) {
                new_passwords.push_back(password + to_string(i));
            }
        }
    }
    else {
        for (const auto &password: current) {
            for(const auto &word: dictionary) {
                new_passwords.push_back(password + word);
            }
        }
    }
    return new_passwords;
}

int main() {
    int numWords;

    while(cin >> numWords) {
        vector<string> dictionary;

        for (int i = 0; i < numWords; i++ ) {
            string word;
            cin >> word;
            dictionary.push_back(word);
        }

        int rules;
        cin >> rules;
        for (int i = 0; i < rules; i++) {
            string rule;
            cin >> rule;
            vector<string> current_passwords;
            for (int j = 0; j < rule.length(); j++) {
                if (rule[j] == '#') {
                    current_passwords = generate_passwords(current_passwords, dictionary, 0);
                }
                else {
                    current_passwords = generate_passwords(current_passwords, dictionary, 1);
                }
            }

            cout << "--" << endl;
            for(auto j : current_passwords){
                cout << j << endl;
            }
        }

    }

    return 0;
} 