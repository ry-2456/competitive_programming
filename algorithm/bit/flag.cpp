#include <iostream>
#include <bitset>

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000

int main() {
  // {1, 3, 5}にフラグがたったbit
  unsigned int bit = BIT_FLAG_1 | BIT_FLAG_3 | BIT_FLAG_5;
  std::cout << "{1, 3, 5} = " << std::bitset<8>(bit) << std::endl;
  
  // bitの3番目のflagが立っているか
  if (bit & BIT_FLAG_3)
    std::cout << "3 is in     " << std::bitset<8>(bit) << std::endl;
  // bitの0番目のflagが立っていない
  if (!(bit & BIT_FLAG_0))
    std::cout << "0 is not in " << std::bitset<8>(bit) << std::endl;

  // 0番目のflagを立てる
  bit |= BIT_FLAG_0;
  std::cout << "set 0s flag " << std::bitset<8>(bit) << std::endl;
  // 7番目のflagを立てる
  bit |= BIT_FLAG_7;
  std::cout << "set 7s flag " << std::bitset<8>(bit) << std::endl;
  
  // 1番目のflagを消す
  bit &= ~BIT_FLAG_1;
  std::cout << "del 1s flag " << std::bitset<8>(bit) << std::endl;
  // 5番目のflagを消す
  bit &= ~BIT_FLAG_5;
  std::cout << "del 5s flag " << std::bitset<8>(bit) << std::endl;
  
  return 0;
}
