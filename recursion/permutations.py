# O(n!) -- technically O(n! * n) because of #join
def print_permutations(chars: list, start: int = 0):
    if start == len(chars):
        print(''.join(chars))
    else:
        for idx_from_start in range(start, len(chars)):
            chars[start], chars[idx_from_start] = chars[idx_from_start], chars[start]
            print_permutations(chars, start + 1)
            chars[start], chars[idx_from_start] = chars[idx_from_start], chars[start]


print_permutations(list('abcd'))

# abcd
# abdc
# acbd
# acdb
# adcb
# adbc
# bacd
# badc
# bcad
# bcda
# bdca
# bdac
# cbad
# cbda
# cabd
# cadb
# cdab
# cdba
# dbca
# dbac
# dcba
# dcab
# dacb
# dabc
