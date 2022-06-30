#include <bits/stdc++.h>
using namespace std;

void add_to_header(string filename) {
  ofstream solutions_header;
  solutions_header.open("solutions.h", ios_base::app);

  if (solutions_header) {
    solutions_header << "void " << filename << "();" << endl;
  }
}

void copy_from_template(string filename) {
  string function_name = "solutions/" + filename + ".cpp";

  ifstream solutions_template("templates/solution.cpp");
  ofstream created_file;
  created_file.open("solutions/" + filename + ".cpp", ios_base::out);

  if (created_file && solutions_template) {
    ostringstream template_str;
    template_str << solutions_template.rdbuf();
    created_file << template_str.str() << endl;
    // add the function declaration
    created_file << "void " << filename << "() {" << endl;
    created_file << "\tfreopen(\"output.txt\", \"w+\", stdout);" << endl;
    created_file << "}" << endl;
    add_to_header(filename);
  }
}

int main(int argc, char **argv) {
  fstream file;
  string filename = "solutions/";
  filename += argv[1];
  filename += ".cpp";
  file.open(filename, ios::out);

  if (!file) {
    cout << "Sorry, couldn't create requested file";
    return 0;
  }
  copy_from_template(argv[1]);
  cout << "File has been created successfully at solutions/" << argv[1]
       << ".cpp" << endl;
  return 0;
}
