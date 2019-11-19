#ifndef LIST_H
#define LIST_H


extern void LIST_InsertFunc(struct NodeType *list, struct NodeType *node); // 0x8005091C

extern void LIST_DeleteFunc(struct NodeType *node); // 0x80050948

extern struct NodeType * LIST_GetFunc(struct NodeType *list); // 0x800509B4

extern void LIST_Concatenate(struct NodeType *target, struct NodeType *source); // 0x800509EC


#endif
