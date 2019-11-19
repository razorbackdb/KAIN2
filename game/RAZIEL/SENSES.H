#ifndef SENSES_H
#define SENSES_H


extern int SetEngagedInstance(struct __Player *player, struct evCollideInstanceStatsData *Ptr, unsigned long Attribute); // 0x8009FEE0

extern void UpdateEngagementList(struct evCollideInstanceStatsData *Ptr, struct __Player *player); // 0x8009FF78

extern long UpdateAutoFaceAngle(struct _Instance *player, struct _Instance *instance); // 0x800A0F1C


#endif
