#ifndef SENSES_H
#define SENSES_H

extern int SetEngagedInstance(struct __Player *player, struct evCollideInstanceStatsData *Ptr, unsigned long Attribute);

extern void UpdateEngagementList(struct evCollideInstanceStatsData *Ptr, struct __Player *player);

extern long UpdateAutoFaceAngle(struct _Instance *player, struct _Instance *instance);

#endif
