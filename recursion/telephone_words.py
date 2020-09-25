PHONE_KEYS = [
  '000',
  '111',
  'ABC',
  'DEF',
  'GHI',
  'JKL',
  'MNO',
  'PRS',
  'TUV',
  'WXY',
]


def print_phone_letter_combinations(phone_num: str):
  digits = [int(n) for n in phone_num]
  _print_phone_letter_combinations(digits, 0, [])


# O(3^n)
def _print_phone_letter_combinations(digits: list, idx: int, output: list):
  if idx == len(digits):
    print(''.join(output))
  else:
    for letter_idx in range(len(PHONE_KEYS[0])):
      letter = PHONE_KEYS[digits[idx]][letter_idx]
      output.append(letter)
      _print_phone_letter_combinations(digits, idx + 1, output)
      output.pop()
      if digits[idx] == 1 or digits[idx] == 0:
        return

# print_phone_letter_combinations('0000000')
# print_phone_letter_combinations('1111111')
# print_phone_letter_combinations('4971927')
print_phone_letter_combinations('222')

# AAA
# AAB
# AAC
# ABA
# ABB
# ABC
# ACA
# ACB
# ACC
# BAA
# BAB
# BAC
# BBA
# BBB
# BBC
# BCA
# BCB
# BCC
# CAA
# CAB
# CAC
# CBA
# CBB
# CBC
# CCA
# CCB
# CCC
