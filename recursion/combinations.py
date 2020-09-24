def print_combinations(string: str):
  _print_combinations(string, 0, [])


# O(2^n)
def _print_combinations(string: str, start: int, output: list):
  for i in range(start, len(string)):
    output.append(string[i])
    print(''.join(output))
    if (i < len(string)):
      _print_combinations(string, i + 1, output)
    output.pop()


print_combinations('abcde')

# a
# ab
# abc
# abcd
# abcde
# abce
# abd
# abde
# abe
# ac
# acd
# acde
# ace
# ad
# ade
# ae
# b
# bc
# bcd
# bcde
# bce
# bd
# bde
# be
# c
# cd
# cde
# ce
# d
# de
# e
