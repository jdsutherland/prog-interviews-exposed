#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct element {
  struct element *next;
  void *data;
} Element;

Element *head, *tail;

bool create_stack(Element **stack) {
  *stack = NULL;
  return true;
}

// Remove ele from list.
bool delete(Element *ele) {
  if (!ele) return false;

  if (ele == head) {
    head = ele->next;
    free(ele);
    // special case of deleting list of length 1
    if (!head) tail = NULL;
    return true;
  }

  for (Element *walk = head; walk; walk = walk->next) {
    if (walk->next == ele) {
      if (ele == tail) {
        walk->next = NULL;
        tail = walk;
      } else {
        walk->next = walk->next->next;
      }
      free(ele);
      return true;
    }
  }
  return false;
}

// Inserts after ele. If ele is NULL, inserts at front.
bool insertAfter(Element *elem, int data) {
  return false;
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
  /* int *popped = malloc(sizeof(void *)); */
  Element *stack;
  create_stack(&stack);

  push(&stack, (void *)1);
  assert(stack->data == (void *)1);
  /* push(&stack, (void *)2); */
  /* assert(stack->data == (void *)2); */
  /* push(&stack, (void *)3); */
  /* assert(stack->data == (void *)3); */

  head = stack;
  tail = stack;
  print_stack(&head);
  delete(head);
  printf("\n");
  print_stack(&head);

  assert(!tail);
  /* printf("\n"); */
  /* printf("%d\n", (int)tail->data); */

  /* pop(&stack, (void *)popped); */
  /* assert(*popped == 3); */
  /* pop(&stack, (void *)popped); */
  /* assert(*popped == 2); */
  /* pop(&stack, (void *)popped); */
  /* assert(*popped == 1); */
  /* print_stack(&stack); */

  /* free(popped); */
  /* delete_stack(&stack); */
}
