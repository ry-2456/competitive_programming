#include <bits/stdc++.h>

using Graph = std::vector<std::vector<int>>;

int main() {
  int N, M; std::cin >> N >> M;

  Graph G(N);
  std::vector<int> outdeg(N, 0);
  for (int i = 0; i < M; ++i) {
    int a, b;
    std::cin >> a >> b;
    G[b].push_back(a); // 辺を逆向きに
    ++outdeg[a];
  }

  // sinkをqueueに追加
  std::queue<int> q;
  for (int i = 0; i < N; ++i)
    if (outdeg[i] == 0) q.push(i);

  std::vector<int> order;
  while (!q.empty()) {
    // sinkをグラフから削除
    int v = q.front();
    q.pop();
    order.push_back(v);

    // sink vへ伸びている頂点を探索
    for (int v_adj : G[v]) {
      // edge(v_adj, v)を削除
      --outdeg[v_adj];

      // それによってv_adjが新たにsinkになったらqueueに追加
      if (outdeg[v_adj] == 0) q.push(v_adj);
    }
  }
  
  // 順番をひっくり返す
  std::reverse(order.begin(), order.end());
  for (int v : order) std::cout << v << std::endl;
  return 0;
}
