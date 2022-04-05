#include <iostream>
#include <fstream>
#include <vector>
#include "solver.h"

using namespace std;

int main() {
  ifstream file("matrix");
  Solver g;
  g.Parse(file);
  vector<double> ans;
  ans = g.Solve();
  for (const auto& it : ans) {
    cout << it << ' ';
  }
  return 0;
}
