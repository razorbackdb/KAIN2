#ifndef MBMISS_H
#define MBMISS_H

extern void WCBEGG_Message(struct _Instance *instance, unsigned long message, unsigned long data);

extern int WCBEGG_ShouldIgniteEgg(struct _Instance *egg, struct _walbossAttributes *wa);

extern void WCBEGG_Process(struct _Instance *instance, struct GameTracker *gameTracker);

extern void WCBEGG_ExplodeProcess(struct _Instance *instance, struct GameTracker *gameTracker);

extern void WCBEGG_ExplodeCollide(struct _Instance *instance, struct GameTracker *gameTracker);

extern void WCBEGG_Collide(struct _Instance *instance, struct GameTracker *gameTracker);

extern long WALBOSC_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, struct _Instance *instance);

extern void WALBOSC_Collide(struct _Instance *instance, struct GameTracker *gameTracker);

extern void WALBOSC_Message(struct _Instance *instance, unsigned long message, unsigned long data);

#endif
