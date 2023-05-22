#include <bits/stdc++.h>


bool match(
    std::vector<std::vector<char>>& a, 
    std::vector<std::vector<char>>& b, 
    int i_start, 
    int j_start);

int main() {
  int h, w; std::cin >> h >> w;
  std::vector<std::vector<char>> a(h, std::vector<char>(w));
  std::vector<std::vector<char>> b(h, std::vector<char>(w));

  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      std::cin >> a[i][j]; 
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      std::cin >> b[i][j]; 

  // v shift, h shift
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (match(a, b, i, j)) {
        std::cout << "Yes" << std::endl;
        return 0;
      }
  std::cout << "No" << std::endl;
  return 0;
}

bool match(
    std::vector<std::vector<char>>& a, 
    std::vector<std::vector<char>>& b, 
    int i_offset, 
    int j_offset) {
  int n_row = a.size();
  int n_col = a[0].size();
  for (int i = 0; i < n_row; ++i)
    for (int j = 0; j < n_col; ++j)
      if (a[(i+i_offset)%n_row][(j+j_offset)%n_col] != b[i][j])
        return false;
  return true;
}
