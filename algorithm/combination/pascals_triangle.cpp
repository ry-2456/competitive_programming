#include <bits/stdc++.h>
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
// 1 6 15 20 15 6 1

int main() {
  // pascal_triangle[i][j] = i_C_j
  // pascal_triangle[i][j] = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j]
  long long pascal_triangle[60][60]; 
  pascal_triangle[0][0] = 1;         
  
  for (int i = 1; i < 60; ++i) 
    for (int j = 0; j < i+1; ++j)
      if (j == 0 || j == i) 
        pascal_triangle[i][j] = 1;
      else                  
        pascal_triangle[i][j] = pascal_triangle[i-1][j-1] + pascal_triangle[i-1][j]; 

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < i+1; ++j) {
      std::cout << pascal_triangle[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
