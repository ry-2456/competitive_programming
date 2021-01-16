// ABC 147 C
#include <bits/stdc++.h>
#include <bitset>

bool do_contradict(int& bit, std::vector<std::vector<std::pair<int, int>>>& testimony) {
  // bitが証言と矛盾するかどうか
  int n = testimony.size();
  for (int man_i = 0; man_i < n; ++man_i) {
    if (!(bit & (1<<man_i))) continue; // 不親切な人の証言はskip
    
    // 正直者man_iの証言とbitが矛盾しないかをチェック
    for (std::pair<int, int>& t : testimony[man_i]) {
      int w = t.first;                   // wについて
      bool is_honest = (bool)t.second; // honestかどうか
      
      if (is_honest && !(bit&(1<<w))) return true;
      if (!is_honest && (bit&(1<<w))) return true;
    }
  }
  return false;
}

int main() {
  // read data
  int n; std::cin >> n;
  std::vector<std::vector<std::pair<int, int>>> testimony;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    std::vector<std::pair<int, int>> t(a[i]);
    for (int j = 0; j < a[i]; ++j) {
      std::cin >> t[j].first >> t[j].second;
      --t[j].first; // make 0-index
    }
    testimony.push_back(t);
  }

  // bit全探索
  int ans = 0; // 正直者の最大数
  for (int bit = 0; bit < (1<<n); ++bit) {
    if (do_contradict(bit, testimony)) continue;
    int count = 0; 
    for (int i = 0; i < n; ++i)
      if (bit&(1<<i)) ++count;
    ans = std::max(ans, count);
  }
  std::cout << ans << std::endl;

  return 0;
}
