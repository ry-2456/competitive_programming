#include <iostream>
#include <vector>

std::vector<std::pair<long long, long long> > prime_factorize(long long N) {
  std::vector<std::pair<long long, long long> > res;
  for (long long d = 2; d * d <= N; ++d) {
    if (N % d != 0) continue;

    // 素因数の指数を求める
    long long ext = 0;
    while (N % d == 0) {
      ++ext;
      N /= d;
    }
    res.push_back(std::make_pair(d, ext));
  }   

  // 最後に残った数について
  if (N != 1) res.push_back(std::make_pair(N, 1));

  return res;
}


int main() {
  long long n; std::cin >> n;
  std::vector<std::pair<long long, long long> > res = prime_factorize(n);
  for (auto p : res) {
    std::cout << p.first << " " << p.second << std::endl;
  }

  return 0;
}
