#include <bits/stdc++.h>

using Graph = std::vector<std::vector<int>>;

int main() {
  int N, M; std::cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b; 
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a); // 無向グラフを想定
  }

  std::vector<int> dist(N, -1); // 全頂点を未訪問に初期化(状態と始点からの距離を管理)
  std::queue<int> q;

  // 初期条件 (頂点0をスタートノードとする)
  dist[0] = 0;  
  q.push(0);

  while (!q.empty()) {
    // 探索対象の頂点をキューから取り出す
    int v = q.front();
    q.pop();

    // vの隣接していて，未訪問の頂点を調べる
    for (int v_next : G[v]) {
      if (dist[v_next] != -1) continue;
      
      dist[v_next] = dist[v] + 1;
      q.push(v_next);
    }
  }

  std::cout << "v : dist" << std::endl;
  for (int v = 0; v < N; ++v)
    std::cout << v << " : " << dist[v] << std::endl;

  return 0;
}
