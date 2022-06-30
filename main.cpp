#include <bits/stdc++.h>
#include <fstream>

#include "solutions.h"
using namespace std;

void test_output() {
  ifstream your_output("output.txt"), expected_output("expected.txt");
  string your_output_str, expected_outputr_str;
  your_output.open("output.txt");
  expected_output.open("expected.txt");

  if (your_output) {
    ostringstream ss;
    ss << your_output.rdbuf();
    your_output_str = ss.str();
  }
  if (expected_output) {
    ostringstream ss;
    ss << expected_output.rdbuf();
    expected_outputr_str = ss.str();
  }

  if (your_output_str == expected_outputr_str) {
    cout << "All tests passed ✅" << endl;
  } else {
    cout << "Some tests failed ❌" << endl;
  }
}

int main() {
  int stdout_fd = dup(1);
  close(1);
  // add your created function below

  // don't touch anything beyond this line
  fflush(stdout);
  dup2(stdout_fd, 1);
  test_output();
}
