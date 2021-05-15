#include <bits/stdc++.h>

bool is_ok(const std::string& memory, const std::string& pin) {
  // oの条件をチェック
  for (int i = 0; i < 10; ++i) {
    if (memory[i] != 'o') continue;
    int i_char = i + '0';
    bool contain = false;
    for (int j = 0; j < 4; ++j)
      if (i_char == pin[j])
        contain = true;
    if (!contain) return false;
  } 

  // xの条件をチェック
  int not_contain_num = 0;
  for (const char c : memory)
    if (c == 'x')
      ++not_contain_num;
  if (not_contain_num == 10) return false;

  for (int i = 0; i < 10; ++i) {
    if (memory[i] != 'x') continue;
    int i_char = i + '0';
    for (int j = 0; j < 4; ++j)
      if (i_char == pin[j])
        return false;
  } 

  return true;
}

int main() {
  std::string memory; std::cin >> memory;
  int cnt = 0;
  for (char p1 = '0'; p1 <= '9'; ++p1)
    for (char p2 = '0'; p2 <= '9'; ++p2)
      for (char p3 = '0'; p3 <= '9'; ++p3)
        for (char p4 = '0'; p4 <= '9'; ++p4) {
          std::string pin;
          pin += p1;
          pin += p2;
          pin += p3;
          pin += p4;
          if (is_ok(memory, pin))
            ++cnt;
        }
  std::cout << cnt << std::endl;
  return 0;
}
