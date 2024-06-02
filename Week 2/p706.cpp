// problem 706
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=647
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int length;
    int prints;

    cin >> length >> prints;

    while (length + prints != 0) {
        int rows = 2 * length + 3;
        int cols = length + 2;
        bool isFirst = true;
        vector<string> each_line(rows, "");
        while (true) {
            if (!isFirst) {
                for (int i = 0; i < each_line.size(); i++) {
                    each_line[i] = " " + each_line[i];
                } 
            }
            else {
                isFirst = false;
            }
            int num = prints % 10;
            prints = prints / 10;
            switch (num) {
                case 1:
                    for (int i = 0; i < rows; i++) {
                        if (i == 0 || i == rows-1 || i == rows/2) {
                            each_line[i] = string(cols, ' ') + each_line[i];
                        }
                        else {
                            each_line[i] = string(cols-1, ' ') + "|" + each_line[i];
                        }
                    }
                    break;
                    
                case 2:
                    each_line[0] = " " + string(length, '-') + " " + each_line[0];                    
                    each_line[rows/2] = " " + string(length, '-') + " " + each_line[rows/2];
                    each_line[rows-1] = " " + string(length, '-') + " " + each_line[rows-1];
                    for (int i = 1; i < rows/2; i++) {
                        each_line[i] = string(cols-1, ' ') + "|" + each_line[i];
                    }
                    for (int i = rows/2+1; i < rows-1; i++) {
                        each_line[i] = "|" + string(cols-1, ' ') + each_line[i];
                    }
                    break;
                    
                case 3:
                    for (int i = 0; i < rows; i++) {
                        if (i == 0 || i == rows-1 || i == rows/2) {
                            each_line[i] = " " + string(length, '-') + " " + each_line[i];
                        }
                        else {
                            each_line[i] = string(cols-1, ' ') + "|" + each_line[i];
                        }
                    }
                    break;
                    
                case 4:
                    each_line[0] = string(cols, ' ') + each_line[0];
                    each_line[rows-1] = string(cols, ' ') + each_line[rows-1];
                    each_line[rows/2] = " " + string(length, '-') + " " + each_line[rows/2];
                    for (int i = 1; i < rows/2; i++) {
                        each_line[i] = "|" + string(cols-2, ' ') + "|" + each_line[i];
                    }
                    for (int i = rows/2+1; i < rows-1; i++) {
                        each_line[i] = string(cols-1, ' ') + "|" + each_line[i];
                    }
                    break;
                
                case 5:
                    each_line[0] = " " + string(length, '-') + " " + each_line[0];                    
                    each_line[rows/2] = " " + string(length, '-') + " " + each_line[rows/2];
                    each_line[rows-1] = " " + string(length, '-') + " " + each_line[rows-1];
                    for (int i = 1; i < rows/2; i++) {
                        each_line[i] = "|" + string(cols-1, ' ') + each_line[i];
                    }
                    for (int i = rows/2+1; i < rows-1; i++) {
                        each_line[i] = string(cols-1, ' ') + "|" + each_line[i];
                    }
                    break;
                    
                case 6:
                    each_line[0] = " " + string(length, '-') + " " + each_line[0];                    
                    each_line[rows/2] = " " + string(length, '-') + " " + each_line[rows/2];
                    each_line[rows-1] = " " + string(length, '-') + " " + each_line[rows-1];
                    for (int i = 1; i < rows/2; i++) {
                        each_line[i] = "|" + string(cols-1, ' ') + each_line[i];
                    }
                    for (int i = rows/2+1; i < rows-1; i++) {
                        each_line[i] = "|" + string(cols-2, ' ') + "|" + each_line[i];
                    }
                    break;
                    
                case 7:
                    for (int i = 0; i < rows; i++) {
                        if (i == 0) {
                            each_line[i] = " " + string(length, '-') + " " + each_line[i];
                        }
                        else if (i == rows-1 || i == rows/2) {
                            each_line[i] = string(cols, ' ') + each_line[i];
                        }
                        else {
                            each_line[i] = string(cols-1, ' ') + "|" + each_line[i];
                        }
                    }
                    break;
                    
                case 8:
                    for (int i = 0; i < rows; i++) {
                        if (i == 0 || i == rows-1 || i == rows/2) {
                            each_line[i] = " " + string(length, '-') + " " + each_line[i];
                        }
                        else {
                            each_line[i] = "|" + string(cols-2, ' ') + "|" + each_line[i];
                        }
                    }
                    break;
                    
                case 9:
                    for (int i = 0; i < rows; i++) {
                        if (i == 0 || i == rows-1 || i == rows/2) {
                            each_line[i] = " " + string(length, '-') + " " + each_line[i];
                        }
                        else if (i < rows/2) {
                            each_line[i] = "|" + string(cols-2, ' ') + "|" + each_line[i];
                        }
                        else {
                            each_line[i] = string(cols-1, ' ') + "|" + each_line[i];
                        }
                    }
                    break;
                
                case 0:
                    for (int i = 0; i < rows; i++) {
                        if (i == 0 || i == rows-1) {
                            each_line[i] = " " + string(length, '-') + " " + each_line[i];
                        }
                        else if (i == rows/2) {
                            each_line[i] = string(cols, ' ') + each_line[i];  
                        } 
                        else {
                            each_line[i] = "|" + string(cols-2, ' ') + "|" + each_line[i];
                        }
                    }
                    break;
            }
            if (prints == 0){
                break;
            }
        }

        for (auto const &itr : each_line) {
            cout << itr << endl;
        }
        cout << endl;
        cin >> length >> prints;
    }
}