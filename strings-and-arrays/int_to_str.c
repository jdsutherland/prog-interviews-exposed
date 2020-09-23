#include <assert.h>
#include <string.h>

enum { MAX_DIGITS = 10 };

static void reverse_str(char str[], int start, int end) {
  char tmp;
  for (; end > start; start++, end--) {
    tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
  }
}

static void int_to_str(char dst[], int num) {
  if (num == 0) {
    dst[0] = '0';
    dst[1] = '\0';
    return;
  }

  int sign = (num < 0) ? -1 : 1;
  int i = 0;
  for (int acc = num * sign; acc > 0; i++) {
    dst[i] = (acc % 10) + '0';
    acc /= 10;
  }
  if (sign == -1) {
    dst[i] = '-';
    dst[i+1] = '\0';
  } else {
    dst[i] = '\0';
  }

  reverse_str(dst, 0, strlen(dst)-1);
}

int main() {
  char buf[MAX_DIGITS];

  int_to_str(buf, 0);
  assert(strcmp(buf, "0") == 0);

  int_to_str(buf, -137);
  assert(strcmp(buf, "-137") == 0);

  int_to_str(buf, 137);
  assert(strcmp(buf, "137") == 0);
}
