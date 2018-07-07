#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  // TODO - you fill in here.
  // Partity of a given number is said to be 1 if the number of 1's in the
  // equivalent binary representation is odd. Otherwise zero.

  // Brute force method 1.
  //  Extract each bit of the given number and count the same.

  short parity = 0; // Assuming the initial parity is 0
#if 0
  # Method 1
  while(x) {
    parity ^= (x & 0x1);
    x >>= 1;
  }

  # Method 2
  // Another method: The following loop iterates as many times as the number
  //  of the 1's in the given number
  while(x) {
    parity ^= 1;
    x &= (x -1); // This drops the lowest bit set, making sure the loop iterates
                 // as many times as the number of 1's in the number.
  }
#endif
  x ^= (x >> 32);
  x ^= (x >> 16);
  x ^= (x >>  8);
  x ^= (x >>  4);
  x ^= (x >>  2);
  x ^= (x >>  1);

  std::cerr << " >> x = " << x << std::endl;

  parity = x & 0x1;

  return parity;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
