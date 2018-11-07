#include <type_traits>
#include <iostream>
#include <cmath>
#include <iostream>
#include "optional.h"

using namespace std;

class TT {
public:
  TT(int k) : k_(k) {

  }
  
  TT(const TT&) = delete;

  int k_;
};

int main(int argc, char* argv) {
  optional<double> db;
  db = 5.4;

  

  cout << typeid(db).name() << endl;

  cout << typeid(optional<TT>).name() << endl;

  cout << db.value() << std::endl;

  

  getchar();
}