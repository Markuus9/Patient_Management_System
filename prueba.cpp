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
  string name;
  while (cin >> name) {
    int edat, gravetat;
    string motiu;
    cin >> edat >> motiu >> gravetat;
    Pacient p(name, edat, motiu, gravetat);
    Pacient e(name);
    test.setValue(name, p);
    cout << test.find(name).second;
  }
}
