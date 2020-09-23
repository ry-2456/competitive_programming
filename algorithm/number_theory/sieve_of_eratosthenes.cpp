#include <iostream>
#include <vector>
#include <stdio.h>

std::vector<int> sieve_of_eratosthenes(const int N) {
  std::vector<bool> is_prime(N+1, true);  // is_prime[i] := whether i is priem number or not 
  is_prime[0] = is_prime[1] = false; // 0 and 1 is not priem number

  for (int i = 2; i*i <= N; ++i) {
    // skip not prime nubmer
    if (!is_prime[i]) continue;

    // set false to not prime number
    for (int j = i*i; j <= N; j += i) {
      is_prime[j] = false; 
    }
  } 

  std::vector<int> prime_num;
  for (int i = 2; i <= N; ++i) {
    if (is_prime[i])
      prime_num.push_back(i);
  }

  return prime_num;
}

int main() {
  int n; std::cin >> n;

  std::vector<int> prime_num = sieve_of_eratosthenes(n);

  for (int i = 0; i < (int)prime_num.size(); ++i) {
    if (i % 20 == 0) std::cout << std::endl;
    printf("%6d", prime_num[i]);
  }

  return 0;
}
