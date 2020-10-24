#include <bits/stdc++.h>

using Graph = std::vector<std::vector<int>>;

// 頂点sからtにたどり着けるか
int main() {
  int N, M; std::cin >> N >> M; 
  int s, t; std::cin >> s >> t; // pathが存在することを確認したい頂点s, t

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }


  std::vector<int> dist(N, -1);
  std::queue<int> q;

  dist[s] = 0;
  q.push(s);

  while (!q.empty()) {
    int v = q.front(); 
    q.pop();

    for (int v_next : G[v]) {
      if (dist[v_next] != -1) continue;
      dist[v_next] = dist[v] + 1;
      q.push(v_next);
    }
  }
  
  bool ans = false;
  if (dist[t] != -1) ans = true;

  if (ans) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
