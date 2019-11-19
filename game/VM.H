#ifndef VM_H
#define VM_H


extern void VM_Tick(long time); // 0x80050A54

extern void VM_UpdateMorph(struct Level *level, int initFlg); // 0x80050A74

extern void VM_VMOUpdateTimeOfDay(struct Level *level, struct _VMObject *vmobject, int startTimeIdx, int ratio); // 0x80050E4C

extern void VM_UpdateTimeOfDay(struct Level *level, int startTimeIdx, int ratio); // 0x8005125C

extern void VM_VMObjectSetTable(struct Level *level, struct _VMObject *vmobject, int table); // 0x800512D0


#endif
