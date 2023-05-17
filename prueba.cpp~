#include "BST.hpp"
#include <iostream>
using namespace std;

int main()
{
  BST<int> test;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    test.insert(x);
  }
  int y;
  cin >> y;
  pair<bool,int> par = test.find(y);
  cout << par.first << " " << par.second << endl;

}
