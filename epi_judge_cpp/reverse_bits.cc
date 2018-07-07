#include "test_framework/generic_test.h"
unsigned long long ReverseBits(unsigned long long x) {
  // TODO - you fill in here.
  unsigned int lsb = 0;
  unsigned int msb = (8 * sizeof(unsigned long long)) - 1;

  // Number to be returned.
  auto ret_num = x;

  while(lsb < msb) {
    // We need to toggle only when they are different.
    if(((ret_num >> lsb) & 0x1) != ((ret_num >> msb) & 0x1)) {

      // Form a bit mask to swap.
      unsigned long long bit_mask = ((static_cast<unsigned long long>(0x1) << lsb) |
                                (static_cast<unsigned long long>(0x1) << msb));

      // Number to be returned.
      ret_num ^= bit_mask;
    }

    lsb++;
    msb--;
  }

  return ret_num;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
