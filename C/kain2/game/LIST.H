#ifndef LIST_H
#define LIST_H


extern void LIST_InsertFunc(struct NodeType *list, struct NodeType *node); // 0x8004FB54

extern void LIST_DeleteFunc(struct NodeType *node); // 0x8004FB80

extern struct NodeType * LIST_GetFunc(struct NodeType *list); // 0x8004FBEC


#endif
