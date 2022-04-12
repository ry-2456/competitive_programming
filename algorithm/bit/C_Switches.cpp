#include <bits/stdc++.h>
// abc128

int main() {
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> s(m);
  for (int i = 0; i < m; ++i) {
    int k; std::cin >> k;
    s[i].resize(k);
    for (int j = 0; j < k; ++j) {
      std::cin >> s[i][j];
      --s[i][j];
    }
  }
  
  std::vector<int> p(m);
  for (int i = 0; i < m; ++i) std::cin >> p[i];

  int ans = 0;
  // switchのon,offを切り替える
  for (int bit = 0; bit < (1<<n); ++bit) {
    // それぞれの電球について
    bool all_light_on = true;
    for (int i = 0; i < m; ++i) {
      // onになっているswitchの数をカウント
      int cnt = 0;
      for (const int& s_ : s[i])
        if (bit & (1<<s_)) ++cnt;

      if (cnt%2 != p[i])
        all_light_on = false;
    }

    if (all_light_on) ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}
