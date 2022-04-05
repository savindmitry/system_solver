//
// Created by Savin Dmitry on 24.02.2022.
//

#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/*double Determinant(vector<vector<double>> matrix) {
  if (matrix.size() != matrix.back().size()) {
    throw logic_error("determinant not exists for non-square matrix");
  }
  for (int i = 0; i < matrix.size(); ++i) {

  }
}*/

class Solver {
 public:
  Solver();

  void Parse(istream& is);

  vector<double> Solve();

  void ToTriangle(const int& index);

  void Reversed(const int& index);

 private:
  vector<vector<double>> matrix;
};

#endif //SOLVER_H
