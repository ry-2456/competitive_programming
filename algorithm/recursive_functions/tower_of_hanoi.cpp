#include <iostream>

int tower_of_hanoi(int n) {
  if (n == 2) return 3;
  return 2*tower_of_hanoi(n-1) + 1;
}

int main() {
  int n; std::cin >> n;
  std::cout << "moving " << n << " disks takes " << tower_of_hanoi(n) << " steps." << std::endl; 
  return 0;
}
