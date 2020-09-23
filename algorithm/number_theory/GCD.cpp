#include <iostream>

template<typename T> T GCD(T a, T b) {
  if (b == 0) return a;
  return GCD(b, a%b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  int gcd = GCD(a, b);
  std::cout << "gcd(" << a << ", " << b << ") = " << gcd << std::endl; 

  return 0;
}
