/* bfs出も実装してみよう */
#include <bits/stdc++.h>

void dfs(std::string num_s, const long long& limit, int& cnt);
bool contain(std::string& num_s);

void dfs(std::string num_s, const long long& limit, int& cnt) {
  if (num_s.size() == 0) 
    ;
  else if (std::stol(num_s) <= limit) {
    if (contain(num_s)) ++cnt;
  }
  else {
    return; // num > limit (base case)
  }
  dfs(num_s + '3', limit, cnt);
  dfs(num_s + '5', limit, cnt);
  dfs(num_s + '7', limit, cnt);
}

bool contain(std::string& num_s) {
  bool contain_3 = false;
  bool contain_5 = false;
  bool contain_7 = false;
  for (char d : num_s) {
    if (d == '3') contain_3 = true;
    if (d == '5') contain_5 = true;
    if (d == '7') contain_7 = true;
  }
  if (!contain_3) return false;
  if (!contain_5) return false;
  if (!contain_7) return false;
  return true;
}

int main() {
  std::string limit_s; std::cin >> limit_s; 
  int limit_i = std::stoi(limit_s);
  int cnt = 0;

  dfs(std::string(""), limit_i, cnt);
  std::cout << cnt << std::endl;

  return 0;
}
