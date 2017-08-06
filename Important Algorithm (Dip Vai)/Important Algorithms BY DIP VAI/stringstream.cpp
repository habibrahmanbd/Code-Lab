// using stringstream constructors.
#include <iostream>
#include <sstream>
using namespace std;

int main () {

  string val;
  stringstream ss (stringstream::in | stringstream::out);

  ss << "120 ab 377 6 5 2000";

  while(ss>>val)
  {
    //ss >> val;
    cout << val << endl;
  }

  return 0;
}
