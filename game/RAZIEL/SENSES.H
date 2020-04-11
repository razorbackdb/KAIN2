#ifndef SENSES_H
#define SENSES_H


extern int SetEngagedInstance(struct __Player *player, struct evCollideInstanceStatsData *Ptr, unsigned long Attribute); // 0x800A2638

extern void UpdateEngagementList(struct evCollideInstanceStatsData *Ptr, struct __Player *player); // 0x800A26D0

extern long UpdateAutoFaceAngle(struct _Instance *player, struct _Instance *instance); // 0x800A36F0


#endif
