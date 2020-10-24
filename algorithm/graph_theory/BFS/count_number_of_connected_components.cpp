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

  int n_connected_components = 0;

  for (int s = 0; s < N; ++s) {
    if (dist[s] != -1) continue;

    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
      int v = q.front();
      q.pop();

      for (int v_next : G[v]) {
        if (dist[v_next] != -1) continue;

        dist[v_next] = dist[v] + 1;
        q.push(v_next);
      }
    }

    ++n_connected_components;
  }

  std::cout << "n_connected_components : " << n_connected_components << std::endl;
  
  return 0;
}
