#ifndef MBMISS_H
#define MBMISS_H


extern void WCBEGG_Message(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8008F0E8

extern int WCBEGG_ShouldIgniteEgg(struct _Instance *egg, struct _walbossAttributes *wa); // 0x8008F18C

extern void WCBEGG_Process(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F284

extern void WCBEGG_ExplodeProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F478

extern void WCBEGG_SplitProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F5B8

extern void WCBEGG_CommonPostProcess(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F6B4

extern void WCBEGG_CommonPostProcess2(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F744

extern void WCBEGG_ExplodeCollide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F7B8

extern void WCBEGG_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008F93C

extern long WALBOSC_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance); // 0x8008F9C4

extern void WALBOSC_Collide(struct _Instance *instance, struct GameTracker *gameTracker); // 0x8008FA44

extern void WALBOSC_Message(struct _Instance *instance, unsigned long message, unsigned long data); // 0x8008FB04


#endif
