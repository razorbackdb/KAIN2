#ifndef MBMISS_H
#define MBMISS_H


extern void WCBEGG_Message(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8008EBFC

extern int WCBEGG_ShouldIgniteEgg(struct _Instance *egg, struct _walbossAttributes *wa); // 0x8008EC8C

extern void WCBEGG_Process(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008ED6C

extern void WCBEGG_ExplodeProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008EF30

extern void WCBEGG_ExplodeCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008EFE0

extern void WCBEGG_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F118

extern long WALBOSC_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance); // 0x8008F178

extern void WALBOSC_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F1FC

extern void WALBOSC_Message(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8008F2BC


#endif
