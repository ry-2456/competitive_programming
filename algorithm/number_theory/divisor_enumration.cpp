#include <bits/stdc++.h>

std::vector<long long> enum_divisors (long long N) {
  std::vector<long long> d;
  for (long long i = 1; i * i <= N; ++i) {
    if (N%i == 0) {
      d.push_back(i); 
      if (N/i != i) 
        d.push_back(N/i);
    }
  }
  std::sort(d.begin(), d.end());
  return d;
}

int main() {
  long long N; std::cin >> N;
  std::vector<long long> d = enum_divisors(N);
  for (int i = 0; i < (int)d.size(); ++i)
    std::cout << d[i] << std::endl;
  return 0;
}
