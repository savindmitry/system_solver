//
// Created by Savin Dmitry on 24.02.2022.
//

#include "solver.h"

Solver::Solver() = default;

void Solver::Parse(istream& is) {
  // for square matrix, size of matrix
  size_t size;
  size_t i = 0;

  do {
    // getting the line of extended matrix
    string line;
    getline(is, line);
    stringstream ss(line);

    // making a line of matrix from input
    vector<double> string;
    while(ss) {
      int number;
      ss >> number;
      string.push_back(number);
      ss.ignore(1);
    }

    matrix.push_back(string);

    size = string.size() - 1;
    ++i;
  } while (i != size);
}

vector<double> Solver::Solve() {
  // make zeros under the element with index [i][i]
  for (int i = 0; i < matrix.size(); ++i) {
    ToTriangle(i);
  }

  // make zeros above the element with index [i][i]
  for (int i = matrix.size() - 1; i >= 0; --i) {
    Reversed(i);
  }

  // forming an answer from the last elements of each line
  vector<double> answer;
  for (const auto& line : matrix) {
    answer.push_back(line.back());
  }
  return answer;
}

void Solver::ToTriangle(const int& index) {

  // find a line, where [index] element is non-zero
  auto it = find_if(matrix.begin() + index, matrix.end(), [=] (const auto& line) { return line[index] != 0; });

  if (it != matrix.end()) {
    swap(matrix[index], *it);
  } else {
    throw logic_error("system isn't consistent");
  }

  double n = matrix[index][index];
  for (auto& e : matrix[index]) {
    e /= n;
  }

  // subtract this line from all next ones
  for (int i = index + 1; i < matrix.size(); ++i) {

    // save a coefficient between [index] and [i] lines
    double coefficient = matrix[i][index];

    for (int j = index; j < matrix.size() + 1; ++j) {
      matrix[i][j] -= matrix[index][j] * coefficient;
    }
  }
}

void Solver::Reversed(const int& index) {

  // making zeros on [index] pos in every line
  for (int i = index - 1; i >= 0; --i) {

    // save coefficient multiply to
    double n = matrix[i][index];
    matrix[i].back() -= matrix[index].back() * n;
    matrix[i][index] -= matrix[index][index] * n;
  }
}
