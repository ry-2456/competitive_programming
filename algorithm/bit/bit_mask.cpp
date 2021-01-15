#include <iostream>
#include <bitset>

const unsigned int BIT_FLAG_DAMAGE = (1 << 0);   // HPが満タンでないか
const unsigned int BIT_FLAG_DOKU = (1 << 1);     // 毒状態になっているか
const unsigned int BIT_FLAG_MAHI = (1 << 2);     // 麻痺状態になっているか
const unsigned int BIT_FLAG_SENTOFUNO = (1 << 3); // 戦闘不能状態になっているか

// attckして単にダメージを受ける
const unsigned int MASK_ATTACK = BIT_FLAG_DAMAGE;

// punchしてダメージを受けて,麻痺する
const unsigned int MASK_PUNCH = BIT_FLAG_DAMAGE | BIT_FLAG_MAHI;

// defeatして相手のHPをにする
const unsigned int MASK_DEFEAT = BIT_FLAG_DAMAGE | BIT_FLAG_SENTOFUNO;

// 毒と麻痺を回復させる : ~MASK_DOKU_MAHIをかけることで回復
const unsigned int MASK_DOKU_MAHI = BIT_FLAG_DOKU | BIT_FLAG_MAHI;

int main() {
  // start: 0000, 初期状態
  unsigned int status = 0; 
  std::cout << "start: " << std::bitset<4>(status) << std::endl;

  // attacked: 0001になる
  status |= MASK_ATTACK;
  std::cout << "attacked: " << std::bitset<4>(status) << std::endl;

  // punched: 0101になる, HPは満タンではないので, BIT_FLAG_DAMAGEの部分は変化な  し
  std::cout << "punched: " << std::bitset<4>(status) << std::endl;

  // 毒または麻痺かどうかを判定する
  if (status & MASK_DOKU_MAHI)
    std::cout << "You are doku or mahi." << std::endl;

  // kaihuku: 0001にする, HPは回復しない, 麻痺は回復する
  status &= ~MASK_DOKU_MAHI;
  std::cout << "kaihuku: " << std::bitset<4>(status) << std::endl;

  // defeat: 1001にする, 戦闘不能にする
  status |= MASK_DEFEAT;
  std::cout << "defeated: " << std::bitset<4>(status) << std::endl;

  // kaihuku: 1001のまま, 戦闘不能状態は回復しない 
  status &= ~MASK_DOKU_MAHI;
  std::cout << "sentofuno no mama: " << std::bitset<4>(status) << std::endl;

  return 0;
}
