// Find bug: supposed to remove the head element from a singly linked list
void removeHead(ListElement *head) {
  free(head);
  head = head->next;
}
