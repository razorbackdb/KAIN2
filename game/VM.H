#ifndef VM_H
#define VM_H


extern void VM_Tick(long time); // 0x8004FE84

extern void VM_UpdateMorph(struct Level *level, int initFlg); // 0x8004FEA4

extern void VM_VMObjectSetTable(struct Level *level, struct _VMObject *vmobject, int table); // 0x8005027C


#endif
