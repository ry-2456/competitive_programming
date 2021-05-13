#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void dfs(const Graph& g, std::vector<int>& seen, int v) {
  /* vをseenにし同時に訪問済みにする(隣接ノードを訪問)
   * base caseは各頂点の隣接頂点がすべて訪問済みになった時
   */
  std::cout << v << std::endl;
  seen[v] = true; // 訪問済みにする

  // vの隣接頂点について
  for (const int& v_next : g[v]) {
    if (seen[v_next]) continue;  // 探索済みならskip
    dfs(g, seen, v_next);        // 再帰的に探索
  }
}

int main() {
  int n, m; std::cin >> n >> m; // n:vertex m:edge
  Graph g(n);
  for (int i = 0; i < m; ++i) {
    int a, b; std::cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  // start from vertex 0.
  std::vector<int> seen(n, false);
  dfs(g, seen, 0);
  return 0;
}
