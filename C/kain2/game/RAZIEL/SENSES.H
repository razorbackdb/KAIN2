#ifndef SENSES_H
#define SENSES_H


extern int SetEngagedInstance(struct __Player *player, struct evCollideInstanceStatsData *Ptr, unsigned long Attribute); // 0x800A32C4

extern void UpdateEngagementList(struct evCollideInstanceStatsData *Ptr, struct __Player *player); // 0x800A335C

extern long UpdateAutoFaceAngle(struct _Instance *player, struct _Instance *instance); // 0x800A4460


#endif
