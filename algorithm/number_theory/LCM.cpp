#include <iostream>

// template<class T> T GCD(T a, T b) {
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a%b);
}

// template<class T> LCM(T a, T b) {
long long LCM(long long a, long long b) { 
  return a * b / GCD(a, b);
}

int main() {
  int a, b; std::cin >> a >> b;
  std::cout << "gcd(" << a << ", " << b << ") = " << GCD(a, b) << std::endl;
  std::cout << "lcm(" << a << ", " << b << ") = " << LCM(a, b) << std::endl;

  return 0;
}
