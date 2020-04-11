#ifndef LIST_H
#define LIST_H


extern void LIST_InsertFunc(struct NodeType *list, struct NodeType *node); // 0x8004FD4C

extern void LIST_DeleteFunc(struct NodeType *node); // 0x8004FD78

extern struct NodeType * LIST_GetFunc(struct NodeType *list); // 0x8004FDE4

extern void LIST_Concatenate(struct NodeType *target, struct NodeType *source); // 0x8004FE1C


#endif
