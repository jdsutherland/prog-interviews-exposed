#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

// Valid utf-8 may contain only following bit patterns:
// ----------------------------------------------------
// 0xxxxxxx
// 110xxxxx 10xxxxxx
// 1110xxxx 10xxxxxx 10xxxxxx
// 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

// 10xxxxxx
bool is_trailing(unsigned char b) {
  return (b & 0xC0) == 0x80;
}

// 0xxxxxxx
bool is_leading1(unsigned char b) {
  return (b & 0x80) == 0;
}

// 110xxxxx
bool is_leading2(unsigned char b) {
  return (b & 0xE0) == 0xC0;
}

// 1110xxxx
bool is_leading3(unsigned char b) {
  return (b & 0xF0) == 0xE0;
}

// 1111xxxx
bool is_leading4(unsigned char b) {
  return (b & 0xF8) == 0xF0;
}

bool valid_utf8(const unsigned char *buf, size_t len) {
  int expected_trailing_bytes = 0;
  for (size_t i = 0; i < len; i++) {
    unsigned char b = buf[i];
    if (is_trailing(b)) {
      if (expected_trailing_bytes-- > 0) continue;
      return false;
    } else if (expected_trailing_bytes > 0) {
      return false;
    }

    if (is_leading1(b)) {
      expected_trailing_bytes = 0;
    } else if (is_leading2(b)) {
      expected_trailing_bytes = 1;
    } else if (is_leading3(b)) {
      expected_trailing_bytes = 2;
    } else if (is_leading4(b)) {
      expected_trailing_bytes = 3;
    } else {
      return false;
    }
  }
  return expected_trailing_bytes == 0;
}


int main() {
  const unsigned char valid[] = { 0x46 };
  assert(valid_utf8(valid, sizeof(valid)));

  const unsigned char bad_incomplete_string[] = { 0xF0, 0x80, 0x80 };
  assert(!valid_utf8(bad_incomplete_string, sizeof(bad_incomplete_string)));

  const unsigned char bad_missing_trailing_bytes[] = { 0xE0, 0x80, 0x00 };
  assert(!valid_utf8(bad_missing_trailing_bytes, sizeof(bad_missing_trailing_bytes)));
}
