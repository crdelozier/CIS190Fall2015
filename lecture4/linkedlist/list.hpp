#pragma once

#include <iostream>

typedef struct node_t{
  struct node_t *_next;
  int _data;
} node;

typedef struct list_t{
  struct node_t *_first;
} list;

void list_init(list *l);
unsigned int list_length(list *l);
void list_insert(list *l, int value);
void list_print(list *l);
