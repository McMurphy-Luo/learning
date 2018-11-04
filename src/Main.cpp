#include <type_traits>
#include <iostream>

using namespace std;

class B {
public:
  B(int v)
    :k(v) {

  }

  B(const B& another) = delete;

  B& operator=(const B& another) = delete;

  int k;
};

class A {
public:

  template<
    typename T,
    typename std::enable_if<(std::is_copy_assignable<T>::value && std::is_copy_constructible<T>::value)>::type* = 0
  >
    void TTT(const T& haha) {
    cout << "A::TTT from copy_assignable and copy_constructable" << endl;
  }

  
  void BBB() {

  }
  
  template<
    typename T,
    typename std::enable_if<(std::is_copy_constructible<T>::value && !std::is_copy_assignable<T>::value)>::type* = 0
  >
  void TTT(const T& haha) {
    cout << "A::TTT from copy_constructable" << endl;
  }
  

  
  template<
    typename T,
    typename std::enable_if<(std::is_copy_assignable<T>::value && !std::is_copy_constructible<T>::value)>::type* = 0
  >
  void TTT(const T& haha) {
    cout << "A::TTT from copy_assignable " << endl;
  }
};

int main(int argc, char* argv) {

  cout << "is double copy assignable " << is_copy_assignable<double>::value << endl;

  A a_instance;

  a_instance.TTT<B>(B(123));

  cout << "hello world" << endl;

  getchar();
}