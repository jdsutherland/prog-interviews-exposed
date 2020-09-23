#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define ASCII_NUM 48

// can assume given input: [\d-]
static int parse_int(char str[]) {
  int sign = 1;
  if (str[0] == '-') {
    sign = -1;
    str = &str[1];
  }

  int result = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    int power = (len-1) - i;
    result += pow(10, power) * (str[i] - ASCII_NUM); 
  }
  return result * sign;
}

int main() {
  int sanity = parse_int("0");
  assert(sanity == 0);

  int empty = parse_int("");
  assert(empty == 0);

  int neg = parse_int("-137");
  assert(neg == -137);

  int pos = parse_int("137");
  assert(pos == 137);

}
