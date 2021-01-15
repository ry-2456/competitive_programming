// ABC168 C 
#include <bits/stdc++.h>

int main() {
  int n, m, x; std::cin >> n >> m >> x;
  std::vector<int> c(n);
  std::vector<std::vector<int> > a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
    for (int j = 0; j < m; ++j)
      std::cin >> a[i][j];
  }
  
  // bit全探索
  int cost_min = 1e9;
  for (int bit = 0; bit < (1 << n); ++bit) {
    int cost = 0;
    std::vector<int> level_of_understanding(m, 0);
    for (int book = 0; book < n; ++book) {
      if (bit & (1 << book)) {
        cost += c[book];        
        for (int j = 0; j < m; ++j)
          level_of_understanding[j] += a[book][j];
      }
    }
        
    bool meet_criteria = true;
    for (int j = 0; j < m; ++j)
      if (level_of_understanding[j] < x)
        meet_criteria = false;
    
    if (meet_criteria)
      cost_min = std::min(cost, cost_min);
  }
  if (cost_min == 1e9)
    std::cout << -1 << std::endl;
  else
    std::cout << cost_min << std::endl;

  return 0;
}
