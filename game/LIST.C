#include "THISDUST.H"
#include "LIST.H"

void LIST_GetFunc(NodeType *list, NodeType *node)

{
  node->prev = list;
  node->next = list->next;
  if (list->next != (NodeType *)0x0)
  {
    list->next->prev = node;
  }
  list->next = node;
  return;
}

void LIST_DeleteFunc(NodeType *node)

{
  if (node->prev == (NodeType *)0x0)
  {
    if (node->next != (NodeType *)0x0)
    {
      node->next->prev = (NodeType *)0x0;
      goto LAB_8004fdd8;
    }
  }
  else
  {
    if (node->next != (NodeType *)0x0)
    {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      goto LAB_8004fdd8;
    }
  }
  if (node->prev != (NodeType *)0x0)
  {
    node->prev->next = (NodeType *)0x0;
  }
LAB_8004fdd8:
  node->next = (NodeType *)0x0;
  node->prev = (NodeType *)0x0;
  return;
}

NodeType *LIST_InsertFunc(NodeType *list)

{
  NodeType *pNVar1;
  NodeType *node;

  node = list->next;
  pNVar1 = (NodeType *)0x0;
  if (node != (NodeType *)0x0)
  {
    LIST_DeleteFunc(node);
    pNVar1 = node;
  }
  return pNVar1;
}

void LIST_Concatenate(NodeType *target, NodeType *source)

{
  NodeType *node;

  node = source->next;
  while (node != (NodeType *)0x0)
  {
    node = source->next;
    LIST_DeleteFunc(node);
    LIST_GetFunc(target, node);
    node = source->next;
  }
  return;
}
