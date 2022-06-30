#include "solutions.h"
#include <bits/stdc++.h>
using namespace std;

void test_output() {
  ifstream your_output("output.txt");
  ifstream expected_output("expected.txt");
  string your_output_str, expected_outputr_str;
  your_output.open("output.txt");
  expected_output.open("expected.txt");

  ostringstream ss;
  ss << your_output.rdbuf();
  your_output_str = ss.str();

  ostringstream es;
  es << expected_output.rdbuf();
  expected_outputr_str = es.str();

  bool flag = true;
  for (int i = 0; i < expected_outputr_str.length() - 1; i++) {
    if (your_output_str[i] != expected_outputr_str[i]) {
      flag = false;
      break;
    }
  }

  if (flag) {
    cout << "All tests passed ✅" << endl;
  } else {
    cout << "Some tests failed ❌" << endl;
  }

  your_output.close();
  expected_output.close();
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
