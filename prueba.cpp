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
    int q;
    cin >> q;
    Pacient p("papa");
    Pacient p1("papa",51,"pierna",3);
    test.setValue(p, p1);
string y = "papa";
  pair<bool,Pacient> par = test.find(y);
  cout << par.first << " " << par.second << endl;
}
