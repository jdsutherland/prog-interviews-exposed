// Find bug: supposed to remove the head element from a singly linked list
void removeHead(ListElement *head) {
  ListElement *tmp = head->next;
  free(head);
  head = tmp;
}
