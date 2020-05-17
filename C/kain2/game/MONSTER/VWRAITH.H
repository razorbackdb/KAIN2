#ifndef VWRAITH_H
#define VWRAITH_H


extern void VWRAITH_MoveVertical(struct _Instance *instance, long targetZ, int velocity); // 0x8008EA34

extern void VWRAITH_Init(struct _Instance *instance); // 0x8008EA8C

extern int VWRAITH_ShouldISwoop(struct _Instance *instance); // 0x8008EB40

extern void VWRAITH_PursueEntry(struct _Instance *instance); // 0x8008EBC4

extern void VWRAITH_Pursue(struct _Instance *instance); // 0x8008EC5C

extern void VWRAITH_VerticalMove(struct _Instance *instance); // 0x8008EE2C

extern void VWRAITH_CombatEntry(struct _Instance *instance); // 0x8008EEB0

extern void VWRAITH_Combat(struct _Instance *instance); // 0x8008EED0

extern void VWRAITH_EmbraceEntry(struct _Instance *instance); // 0x8008EEFC

extern void VWRAITH_Embrace(struct _Instance *instance); // 0x8008EF1C


#endif
