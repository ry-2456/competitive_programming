#include <iostream>

long long extgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long gcd = extgcd(b, a%b, x, y);
  int pre_x = x;
  int pre_y = y;
  x = pre_y;
  y = pre_x - (a/b) * pre_y;
  return gcd;
}

int main() {
  int mod = 19;
  for (int i = 1; i < mod; ++i) {
    long long x, y;
    long long a = i, b = mod;
    int gcd = extgcd(a, b, x, y);
    int inv = x;
    if (inv < 0) inv += mod;
    std::cout << "inverse of " << a << " : " << inv << std::endl;
    std::cout << a <<  " x " << inv << " % " << b 
              << " = " << (a*inv)%b << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
