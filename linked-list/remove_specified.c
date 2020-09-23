#include <stdio.h>
#include <stdbool.h>

#define ASCII 128

// remove chars_to_remove from pp_char
static void remove_specified(char **pp_char, char *chars_to_remove) {
  bool to_remove[ASCII] = {false};
  for (char *c = chars_to_remove; *c != '\0'; c++) {
    to_remove[*c] = true;
  }

  int dst = 0;
  for (char *p_char = *pp_char; *p_char != '\0'; p_char++) {
    if (!to_remove[*p_char]) {
      (*pp_char)[dst++] = *p_char;
    }
  }
  (*pp_char)[dst] = '\0';
}

int main(void)
{
  char str[] = "Battle of the Vowels: Hawaii vs. Grozny";
  char *string = &str[0];
  remove_specified(&string, "aeiou");
  printf("%s\n", string);
  return 0;
}
