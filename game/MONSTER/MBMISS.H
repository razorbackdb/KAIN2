#ifndef MBMISS_H
#define MBMISS_H


extern void WCBEGG_Process(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008D370

extern void WCBEGG_ExplodeProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008D4E4

extern void WCBEGG_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008D544

extern long WALBOSC_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance); // 0x8008D67C

extern void WALBOSC_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008D700

extern void WALBOSC_Message(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8008D7C0


#endif
