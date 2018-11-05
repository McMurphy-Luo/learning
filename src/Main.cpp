#include <type_traits>
#include <iostream>

using namespace std;

template<int = 5>
class C {

};

class B {
public:
  B(int v)
    :k(v) {

  }

//  B(const B& another) = delete;

  B& operator=(const B& another) = delete;

  int k;
};

class A {
public:

  /*
  template<
    typename T,
    typename = std::enable_if_t<std::is_copy_assignable<T>::value && std::is_copy_constructible<T>::value>
  >
  void TTT(const T& haha) {
    cout << "A::TTT from copy_assignable and copy_constructable" << endl;
  }

  
  void BBB() {

  }
  
  template<
    typename T,
    typename = std::enable_if_t<std::is_copy_constructible<T>::value && !std::is_copy_assignable<T>::value>
  >
  void TTT(const T& haha) {
    cout << "A::TTT from copy_constructable" << endl;
  }
  

  
  template<
    typename T,
    typename = std::enable_if_t<std::is_copy_assignable<T>::value && !std::is_copy_constructible<T>::value>
  >
  void TTT(const T& haha) {
    cout << "A::TTT from copy_assignable " << endl;
  }
  */
};

int main(int argc, char* argv) {

  C<> good_man;

  cout << "hello world" << endl;
  getchar();
}