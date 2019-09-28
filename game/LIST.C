#include "THISDUST.H"
#include "LIST.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LIST_InsertFunc(struct NodeType *list /*$a0*/, struct NodeType *node /*$a1*/)
 // line 46, offset 0x8004f568
	/* begin block 1 */
		// Start line: 92
	/* end block 1 */
	// End Line: 93

	/* begin block 2 */
		// Start line: 93
	/* end block 2 */
	// End Line: 94

void LIST_InsertFunc(NodeType *list,NodeType *node)

{
  node->prev = list;
  node->next = list->next;
  if (list->next != (NodeType *)0x0) {
    list->next->prev = node;
  }
  list->next = node;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LIST_DeleteFunc(struct NodeType *node /*$a0*/)
 // line 57, offset 0x8004f594
	/* begin block 1 */
		// Start line: 114
	/* end block 1 */
	// End Line: 115

	/* begin block 2 */
		// Start line: 115
	/* end block 2 */
	// End Line: 116

void LIST_DeleteFunc(NodeType *node)

{
  if (node->prev == (NodeType *)0x0) {
    if (node->next != (NodeType *)0x0) {
      node->next->prev = (NodeType *)0x0;
      goto LAB_8004f5f4;
    }
  }
  else {
    if (node->next != (NodeType *)0x0) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      goto LAB_8004f5f4;
    }
  }
  if (node->prev != (NodeType *)0x0) {
    node->prev->next = (NodeType *)0x0;
  }
LAB_8004f5f4:
  node->next = (NodeType *)0x0;
  node->prev = (NodeType *)0x0;
  return;
}



// decompiled code
// original method signature: 
// struct NodeType * /*$ra*/ LIST_GetFunc(struct NodeType *list /*$a0*/)
 // line 76, offset 0x8004f600
	/* begin block 1 */
		// Start line: 77
		// Start offset: 0x8004F600
	/* end block 1 */
	// End offset: 0x8004F628
	// End Line: 86

	/* begin block 2 */
		// Start line: 152
	/* end block 2 */
	// End Line: 153

NodeType * LIST_GetFunc(NodeType *list)

{
  NodeType *pNVar1;
  NodeType *node;
  
  node = list->next;
  pNVar1 = (NodeType *)0x0;
  if (node != (NodeType *)0x0) {
    LIST_DeleteFunc(node);
    pNVar1 = node;
  }
  return pNVar1;
}





