#include <bits/stdc++.h>

int main() {
  int r, c; std::cin >> r >> c;
  std::vector<std::vector<char>> m(r, std::vector<char>(c));

  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      std::cin >> m[i][j];

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (m[i][j] == '.') continue;
      if ('0' <= m[i][j] && m[i][j] <= '9') continue;
      // マンハッタン距離がd以下の位置に
      // powerがd以上のbombがあればm[i][j]はemptyになる
      for (int k = 0; k < r; ++k) {
        for (int l = 0; l < c; ++l) {
          if (!('0' <= m[k][l] && m[k][l] <= '9')) continue;
          int d = std::abs(i-k) + std::abs(j-l); 
          if (d <= (int)(m[k][l]-'0')) 
            m[i][j] = '.';
        }
      } 
    }
  }

  // output
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if ('0' <= m[i][j] && m[i][j] <= '9') 
        std::cout << '.';
      else 
        std::cout << m[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}
