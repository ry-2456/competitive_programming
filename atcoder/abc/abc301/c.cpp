#include <bits/stdc++.h>

int main () {
  std::string atcoder = "atcoder";
  std::string s, t; std::cin >> s >> t;
 
  std::set<char> char_set;
  std::map<char, int> s_char_cnt;
  std::map<char, int> t_char_cnt;

  for (int i = 0; i < (int)s.size(); ++i) {
    char_set.insert(s[i]);
    char_set.insert(t[i]);
    s_char_cnt[s[i]] += 1;
    t_char_cnt[t[i]] += 1;
  }

  bool can_coincide = true;
  for (const char& c : char_set) {
    if (c == '@') continue;

    int diff = std::abs(s_char_cnt[c] - t_char_cnt[c]);
    if (diff == 0) continue;

    if (atcoder.find(c) == std::string::npos)
      can_coincide =false;
    if (s_char_cnt[c] > t_char_cnt[c] 
        && !(t_char_cnt['@'] >= diff)) {
      can_coincide = false;
      t_char_cnt['@'] -= diff;
    }
    if (t_char_cnt[c] > s_char_cnt[c]  
        && !(s_char_cnt['@'] >= diff)) {
      can_coincide = false;
      s_char_cnt['@'] -= diff;
    }
  }

  if (can_coincide) std::cout << "Yes" << std::endl;
  else              std::cout << "No" << std::endl;

  return 0;
}

