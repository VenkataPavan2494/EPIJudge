from test_framework import generic_test


# Method using in-built function
#def parity(x):
#    # TODO - you fill in here.
#    if (bin(x).count('1') % 2 == 0):
#      return 0
## By default return 1
#    return 1

# Using bitwise operations: Not optimal
#def parity(x):
#  count = 0
#  while(x):
#    if(x & 0x1):
#      count = count + 1
#    x >>= 1
#
#  if count % 2 == 0:
#    return 0
#  else:
#    return 1

# Using bit wise operations - Optimized solution
def parity(x):
  parity = 0
  # The following loop iterates as many times as the number of 1's in the input number.
  while(x):
    parity ^= 1
    x &= (x - 1) # Drop the bits set in the lsb
  return parity

if __name__ == '__main__':
    exit(generic_test.generic_test_main("parity.py", 'parity.tsv', parity))
