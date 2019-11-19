#ifndef SLUAGH_H
#define SLUAGH_H


extern unsigned long SLUAGH_Query(struct _Instance *instance, unsigned long query); // 0x8008B780

extern void SLUAGH_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008B80C

extern void SLUAGH_Init(struct _Instance *instance); // 0x8008B9F0

extern void SLUAGH_DeathEntry(struct _Instance *instance); // 0x8008BAA8

extern void SLUAGH_Death(struct _Instance *instance); // 0x8008BB44

extern void SLUAGH_AttackEntry(struct _Instance *instance); // 0x8008BBA8

extern void SLUAGH_Attack(struct _Instance *instance); // 0x8008BC0C


#endif
