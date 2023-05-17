#include "BST.hpp"
#include "Pacient.hpp"
using namespace std;

int main()
{
  BST<Pacient> test;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    Pacient x;
    cin >> x;
    test.insert(x);
  }
  string y;
  cin >> y;
  pair<bool,Pacient> par = test.find(y);
  cout << par.first << " " << par.second << endl;
}
