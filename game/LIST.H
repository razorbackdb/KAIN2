#ifndef LIST_H
#define LIST_H

extern void LIST_InsertFunc(struct NodeType *list, struct NodeType *node);

extern void LIST_DeleteFunc(struct NodeType *node);

extern struct NodeType *LIST_GetFunc(struct NodeType *list);

extern void LIST_Concatenate(struct NodeType *target, struct NodeType *source);

#endif
