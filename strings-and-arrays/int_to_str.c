#include <assert.h>
#include <string.h>

const int MAX_DIGITS = 10;

static void reverse_str(char str[], int start, int end) {
  char tmp;
  for (; end > start; start++, end--) {
    tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
  }
}

static char *int_to_str(int num) {
  if (num == 0) return "0";

  static char buf[MAX_DIGITS];
  int sign = (num < 0) ? -1 : 1;
  int i = 0;
  for (int acc = num * sign; acc > 0; i++) {
    buf[i] = (acc % 10) + '0';
    acc /= 10;
  }
  if (sign == -1) {
    buf[i] = '-';
    buf[i+1] = '\0';
  } else {
    buf[i] = '\0';
  }

  reverse_str(buf, 0, strlen(buf)-1);
  return buf;
}

int main() {
  char *zero = int_to_str(0);
  assert(strcmp(zero, "0") == 0);

  char *neg = int_to_str(-137);
  assert(strcmp(neg, "-137") == 0);

  char *pos = int_to_str(137);
  assert(strcmp(pos, "137") == 0);
}
