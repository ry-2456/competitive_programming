#include <bits/stdc++.h>

bool is_prime_number(long long N) {
  if (N == 1) return false;
  for (long long i = 2; i*i <= N; ++i)
    if (N%i == 0) return false;
  return true;
}

int main() {
  long long N; std::cin >> N;
  if (is_prime_number(N))
    std::cout << N << " is prime number" << std::endl;
  else
    std::cout << N << " is not prime number" << std::endl;

  return 0;
}
