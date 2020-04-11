#include "THISDUST.H"
#include "LIST.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LIST_InsertFunc(struct NodeType *list /*$a0*/, struct NodeType *node /*$a1*/)
 // line 46, offset 0x8004fd4c
	/* begin block 1 */
		// Start line: 92
	/* end block 1 */
	// End Line: 93

	/* begin block 2 */
		// Start line: 93
	/* end block 2 */
	// End Line: 94

/* File: C:\kain2\game\LIST.C */

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
 // line 57, offset 0x8004fd78
	/* begin block 1 */
		// Start line: 114
	/* end block 1 */
	// End Line: 115

	/* begin block 2 */
		// Start line: 115
	/* end block 2 */
	// End Line: 116

/* File: C:\kain2\game\LIST.C */

void LIST_DeleteFunc(NodeType *node)

{
  if (node->prev == (NodeType *)0x0) {
    if (node->next != (NodeType *)0x0) {
      node->next->prev = (NodeType *)0x0;
      goto LAB_8004fdd8;
    }
  }
  else {
    if (node->next != (NodeType *)0x0) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      goto LAB_8004fdd8;
    }
  }
  if (node->prev != (NodeType *)0x0) {
    node->prev->next = (NodeType *)0x0;
  }
LAB_8004fdd8:
  node->next = (NodeType *)0x0;
  node->prev = (NodeType *)0x0;
  return;
}



// decompiled code
// original method signature: 
// struct NodeType * /*$ra*/ LIST_GetFunc(struct NodeType *list /*$a0*/)
 // line 76, offset 0x8004fde4
	/* begin block 1 */
		// Start line: 77
		// Start offset: 0x8004FDE4
	/* end block 1 */
	// End offset: 0x8004FE0C
	// End Line: 86

	/* begin block 2 */
		// Start line: 152
	/* end block 2 */
	// End Line: 153

/* File: C:\kain2\game\LIST.C */

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



// decompiled code
// original method signature: 
// void /*$ra*/ LIST_Concatenate(struct NodeType *target /*$s2*/, struct NodeType *source /*$s1*/)
 // line 147, offset 0x8004fe1c
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x8004FE1C
		// Variables:
	// 		struct NodeType *next; // $s0
	/* end block 1 */
	// End offset: 0x8004FE6C
	// End Line: 156

	/* begin block 2 */
		// Start line: 290
	/* end block 2 */
	// End Line: 291

/* File: C:\kain2\game\LIST.C */

void LIST_Concatenate(NodeType *target,NodeType *source)

{
  NodeType *node;
  
  node = source->next;
  while (node != (NodeType *)0x0) {
    node = source->next;
    LIST_DeleteFunc(node);
    LIST_InsertFunc(target,node);
    node = source->next;
  }
  return;
}





