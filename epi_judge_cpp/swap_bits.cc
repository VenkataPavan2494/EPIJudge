#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {
  // TODO - you fill in here.
  // Store the input number.
  long long ret_num = x;

  // We have to swap only:
  // 1. when the positions passed are diffenret.
  // 2. when the values at the positions are different.
  if ((i != j) && (((x >> i) & 0x1) != ((x >> j) & 0x1))) {
    // Prepare a mask containing 1's at the postions mentioned.
    long long bit_mask = (((static_cast<long long>(0x1)) << i) |
                           ((static_cast<long long>(0x1)) << j));
    ret_num = x ^ bit_mask;
  }

  return ret_num;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
