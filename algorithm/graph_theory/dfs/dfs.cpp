#include <bits/stdc++.h>

int main() {
  int n, m; std::cin >> n >> m; // n:=頂点数, m:=辺の数 
  int s, t; std::cin >> s >> t; // s:=start, t:=goal
  --s, --t;

  // グラフ作成
  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int a, b; std::cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  std::string ans; std::cin >> ans;   

  // 検出済み頂点格納用
  std::stack<int> stk;
  std::vector<bool> seen(n, false);
  // 始点
  stk.push(s);
  seen[s] = true;
  while (!stk.empty()) {
    int v = stk.top(); 
    stk.pop();
    for (int v_next : g[v]) {
      // 検知済み
      if (seen[v_next]) continue;
      stk.push(v_next);
      seen[v_next] = true;
    }
  }


  if (seen[t]) std::cout << "Yes" << std::endl;
  else         std::cout << "No" << std::endl;
  std::cout << "ans: " << ans << std::endl;

  return 0;
}
