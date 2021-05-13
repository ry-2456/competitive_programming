#include <iostream>
#include <vector>

using Graph = std::vector<std::vector<int>>;

void dfs(const Graph& g, std::vector<int>& seen, int v) {
  /* v$B$r(Bseen$B$K$7F1;~$KK,Ld:Q$_$K$9$k(B($BNY@\%N!<%I$rK,Ld(B)
   * base case$B$O3FD:E@$NNY@\D:E@$,$9$Y$FK,Ld:Q$_$K$J$C$?;~(B
   */
  std::cout << v << std::endl;
  seen[v] = true; // $BK,Ld:Q$_$K$9$k(B

  // v$B$NNY@\D:E@$K$D$$$F(B
  for (const int& v_next : g[v]) {
    if (seen[v_next]) continue;  // $BC5:w:Q$_$J$i(Bskip
    dfs(g, seen, v_next);        // $B:F5"E*$KC5:w(B
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
