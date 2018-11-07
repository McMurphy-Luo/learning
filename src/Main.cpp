#include <type_traits>
#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class A {
public:
  A() {

  }

  
  template<
    typename std::enable_if<std::is_copy_assignable<T>::value && std::is_copy_constructible<T>::value, int>::type = 0
  >
  
  A(const A& another) {
    cout << "fucker" << endl;
  }
};

int main(int argc, char* argv) {
  cout
    << "double_t copy assignable: " << std::is_copy_assignable<double_t>::value << endl
    << "double_t copy constructable" << std::is_copy_constructible<double_t>::value << endl;

  A<double_t> nihao;
  A<double_t> another = nihao;

  cout << "good" << endl;

  getchar();
}