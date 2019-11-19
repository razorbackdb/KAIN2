#ifndef VWRAITH_H
#define VWRAITH_H


extern void VWRAITH_MoveVertical(struct _Instance *instance, long targetZ, int velocity); // 0x8008CD60

extern void VWRAITH_Init(struct _Instance *instance); // 0x8008CDB8

extern int VWRAITH_ShouldISwoop(struct _Instance *instance); // 0x8008CE80

extern void VWRAITH_PursueEntry(struct _Instance *instance); // 0x8008CEE4

extern void VWRAITH_Pursue(struct _Instance *instance); // 0x8008CF7C

extern void VWRAITH_CombatEntry(struct _Instance *instance); // 0x8008D14C

extern void VWRAITH_Combat(struct _Instance *instance); // 0x8008D16C


#endif
