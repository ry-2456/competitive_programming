#include <bits/stdc++.h>

int main() {
  int N; std::cin >> N;
  std::vector<int> a(N);
  for (int i = 0; i < N; ++i) std::cin >> a[i];

  // 累積和
  std::vector<int> s(N+1, 0);
  for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];
  
  int left, right; // sum[left, right)を求める
  std::cin >> left >> right;
  std::cout << s[right]-s[left] << std::endl; 

  return 0;
}
