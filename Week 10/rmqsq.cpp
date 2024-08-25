// Range Minimum Query
// https://www.spoj.com/problems/RMQSQ/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;


struct Node{
    int min_value;
    int left;
    int right;
};

vector<int> numbers;
vector<Node> segmentTree;

int minOfInterval(int node_index, int left, int right) {
    Node &node = segmentTree[node_index];
    
    if (left > node.right || right < node.left) {
        return INT_MAX;
    }
    else if (left <= node.left && right >= node.right) {
        return node.min_value;
    }
    
    int leftVal = minOfInterval(2*node_index+1, left, right);
    int rightVal = minOfInterval(2*node_index+2, left, right);

    return min(leftVal, rightVal);
}

void buildTree(int index, int left, int right) {
    Node node;
    node.left = left;
    node.right = right;
    if (right == left) {
        node.min_value = numbers[left];
    }
    else {
        int midpoint = left + (right-left)/2;
        buildTree(2*index+1,left,midpoint);
        buildTree(2*index+2,midpoint+1,right);
        node.min_value = min(segmentTree[2*index+1].min_value,segmentTree[2*index+2].min_value);
    }
    segmentTree[index] = node;
}

int main () {
    int N, M;
    int left, right;

    cin >> N;

    int arraySize = pow(2, ceil(log2(N))); 
    int treeSize = 2 * arraySize - 1;

    numbers.resize(arraySize, INT_MAX);

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers[i] = num;
    }
 
    segmentTree.resize(treeSize);  

    buildTree(0, 0, arraySize-1);

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> left >> right;
        cout << minOfInterval(0, left, right) << endl;
    }  
       
    return 0;
}