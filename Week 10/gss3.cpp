// GSS3
// https://www.spoj.com/problems/GSS3/
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

struct Node {
    int left;
    int right;
    int sum;
};

vector<int> numbers;
vector<Node> segmentTree;

int getSum(int node_index, int left, int right) {
    Node &node = segmentTree[node_index];
    
    printf("Node:%d [%d,%d]\n",node_index, node.left, node.right);
    if (left > node.right || right < node.left) {
        printf("Outside Interval\n");
        return 0;
    }
    else if (left <= node.left && right >= node.right) {
        printf("Inside Interval\n");
        return node.sum;
    }
    
    int left_val = getSum(2*node_index+1, left, right);
    int right_val = getSum(2*node_index+2, left, right);
    printf("Node:%d [%d,%d] Left:%d Right%d\n", node_index, node.left, node.right, left_val, right_val);
    return left_val + right_val;
}

void update(int node_index, int index, int val) {
    Node &node = segmentTree[node_index];
    if (node.left == index && node.right == index) {
        node.sum = val;
        return;
    }
    else if (index < node.left || index > node.right) {
        return;
    }
    int left_node = 2 * node_index + 1;
    int right_node = 2 * node_index + 2;
    update(left_node, index, val);
    update(right_node, index, val);

    node.sum = segmentTree[left_node].sum + segmentTree[right_node].sum;
}

void buildTree(int index, int left, int right) {
    Node node;
    node.left = left;
    node.right = right;
    if (right == left) {
        node.sum = numbers[left];
    }
    else {
        int midpoint = left + (right-left)/2;
        int left_node = 2 * index + 1;
        int right_node = 2 * index + 2;
        buildTree(left_node,left,midpoint);
        buildTree(right_node,midpoint+1,right);
        node.sum = segmentTree[left_node].sum + segmentTree[right_node].sum;
    }
    // printf("Index:%d [%d,%d] Node Sum:%d\n", index, left, right, node.sum);
    segmentTree[index] = node;
}

int main() {
    int N, M;
    int a, x, y;

    cin >> N;

    int arraySize = pow(2, ceil(log2(N))); 
    int treeSize = 2 * arraySize - 1;

    numbers.resize(arraySize, 0);

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers[i] = num;
    }
 
    segmentTree.resize(treeSize);  

    buildTree(0, 0, arraySize-1);

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> a >> x >> y;
        if (a) {
            cout << getSum(0, x-1, y-1) << endl;
        }
        else {
            update(0, x-1, y);
        }
    }  
       
    return 0;
}