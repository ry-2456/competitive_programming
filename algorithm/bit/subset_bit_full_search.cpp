#include <bits/stdc++.h>

// 参照記事
// https://qiita.com/hareku/items/3d08511eab56a481c7db#bit%E5%85%A8%E6%8E%A2%E7%B4%A2%E3%81%AE%E3%82%B3%E3%83%BC%E3%83%89%E8%A7%A3%E8%AA%AC

int main() {
  int n = 3;

  // {0, 1, 2, ..., n-1}の部分集合の全探索
  for (int bit = 0; bit < (1<<n); ++bit) {

    std::vector<int> subset;
    for (int i = 0; i < n; ++i)
      if (bit & (1<<i))
        subset.push_back(i);

    std::cout << bit << ": " << "{ ";
    for (int i = 0; i < (signed)subset.size(); ++i) {
      std::cout << subset[i];
      if (i != (signed)subset.size()-1)
        std::cout << ", ";
    }
    std::cout << " }" << std::endl;
  }

  return 0;
}
