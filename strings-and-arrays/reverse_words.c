#include <stdio.h>
#include <string.h>

static void reverse_str(char str[], int start, int end) {
  char tmp;
  for (; end > start; start++, end--) {
    tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
  }
}

static void reverse_words(char words[]) {
  int len = strlen(words);
  reverse_str(words, 0, len - 1);
  int start, end;
  for (start = 0, end = 0; end < len; end++) {
    if (words[end] != ' ') {
      start = end;
      // scan to next non-word
      for (; end < len && words[end] != ' '; end++);
      // backup to end of word
      end--;
      reverse_str(words, start, end);
    }
  }
}

int main() {
  char str[] = "Do or do not, there is no try.";
  reverse_words(str);
  printf("%s\n", str);
}
