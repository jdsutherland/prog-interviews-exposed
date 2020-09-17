#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct element {
  struct element *next;
  void *data;
} Element;

bool create_stack(Element **stack) {
  *stack = NULL;
  return true;
}

// Inserts new node at end of the list.
bool push(Element **stack, void *data) {
  Element *ele = malloc(sizeof(Element));
  if (!ele) return false;

  ele->data = data;
  ele->next = *stack;
  *stack = ele;
  return true;
}

bool pop(Element **stack, void **data) {
  Element *ele;
  if (!(ele = *stack)) return false;

  *data = ele->data;
  *stack = ele->next;
  free(ele);
  return true;
}

bool delete_stack(Element **stack) {
  if (!stack) return false;

  Element *next;
  for (next = (*stack)->next; *stack; *stack = next) free(*stack);
  return true;
}

void print_stack(Element **stack) {
  for (; *stack; stack = &(*stack)->next) {
    printf("%d\n", (int)(*stack)->data);
  }
}

int main() {
  int *popped = malloc(sizeof(void *));
  Element *stack;
  create_stack(&stack);

  push(&stack, (void *)1);
  assert(stack->data == (void *)1);
  push(&stack, (void *)2);
  assert(stack->data == (void *)2);
  push(&stack, (void *)3);
  assert(stack->data == (void *)3);
  print_stack(&stack);

  pop(&stack, (void *)popped);
  assert(*popped == 3);
  pop(&stack, (void *)popped);
  assert(*popped == 2);
  pop(&stack, (void *)popped);
  assert(*popped == 1);
  print_stack(&stack);

  free(popped);
  delete_stack(&stack);
}
