/* question */
/* In a party of N people, each person will shake her/his hand with */
/* other person only once. On total how many hand-shakes wourld happen? */

#include <iostream>

int n_shake_hands(int n) {
  if (n == 2) return 1;            // two people shake hands once.(base case)
  return n_shake_hands(n-1) + n-1; // num of n-1 people shake hands + n th person's.
  // n_C_2 n*(n-1)/2
}

int main() {
  int n; std::cin >> n;
  std::cout << n << " people shake hands " << n_shake_hands(n) << " times." << std::endl;
  return 0;
}
