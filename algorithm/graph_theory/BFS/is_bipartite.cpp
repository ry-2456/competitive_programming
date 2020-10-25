#include <bits/stdc++.h>

using Graph = std::vector<std::vector<int>>;

int main() {
  int N, M; std::cin >> N >> M; 

  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b; 
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  std::vector<int> dist(N, -1);
  std::queue<int> q;

  bool is_bipartite = true;
  for (int s = 0; s < N; ++s) {
    if (dist[s] != -1) continue;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int v_adj : G[v]) {
        if (dist[v_adj] == -1) {
          dist[v_adj] = dist[v] + 1;
          q.push(v_adj);
        } else {
          if (dist[v_adj] == dist[v]) 
            is_bipartite = false;
        }
      }
    }
  }

  if (is_bipartite) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
