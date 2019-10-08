#ifndef VM_H
#define VM_H

extern void VM_Tick(long time);

extern void VM_UpdateMorph(struct Level *level, int initFlg);

extern void VM_VMObjectSetTable(struct Level *level, struct _VMObject *vmobject, int table);

#endif
