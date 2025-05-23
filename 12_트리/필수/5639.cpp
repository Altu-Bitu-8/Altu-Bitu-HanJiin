#include <iostream>
#include <map>
#include <vector>

using namespace std;

void postOrder(vector<int> &nodes, int start, int end){
    if (start > end){
      return;
    }
    int root = nodes[start];

    int i = start + 1;
    while(i <= end && nodes[i] < root){
      i++;
    }

    // 왼쪽 서브트리
    postOrder(nodes, start + 1, i - 1);
    // 오른쪽 서브트리
    postOrder(nodes, i, end);
    cout << root << "\n";
}

int main(){
  vector<int> nodes;
  int num;
  while(cin >> num){
    nodes.push_back(num);
  }
  int start = 0;
  int end = nodes.size() - 1;

  postOrder(nodes, start, end);
}