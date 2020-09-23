#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ASCII 128

// remove chars_to_remove from str
static void remove_specified(char str[], char *chars_to_remove) {
  bool to_remove[ASCII] = {false};
  for (char *c = chars_to_remove; *c != '\0'; c++) {
    to_remove[*c] = true;
  }

  int dst = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (!to_remove[str[i]]) {
      str[dst++] = str[i];
    }
  }
  str[dst] = '\0';
}

int main(void)
{
  char str[] = "Battle of the Vowels: Hawaii vs. Grozny";
  remove_specified(str, "aeiou");
  printf("%s\n", str);
  return 0;
}
