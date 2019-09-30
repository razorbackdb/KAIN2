#ifndef VWRAITH_H
#define VWRAITH_H


extern void VWRAITH_MoveVertical(struct _Instance *instance, long targetZ, int velocity); // 0x8008E568

extern void VWRAITH_Init(struct _Instance *instance); // 0x8008E5C0

extern int VWRAITH_ShouldISwoop(struct _Instance *instance); // 0x8008E674

extern void VWRAITH_PursueEntry(struct _Instance *instance); // 0x8008E6D8

extern void VWRAITH_Pursue(struct _Instance *instance); // 0x8008E770

extern void VWRAITH_VerticalMove(struct _Instance *instance); // 0x8008E940

extern void VWRAITH_CombatEntry(struct _Instance *instance); // 0x8008E9C4

extern void VWRAITH_Combat(struct _Instance *instance); // 0x8008E9E4

extern void VWRAITH_EmbraceEntry(struct _Instance *instance); // 0x8008EA10

extern void VWRAITH_Embrace(struct _Instance *instance); // 0x8008EA30


#endif
