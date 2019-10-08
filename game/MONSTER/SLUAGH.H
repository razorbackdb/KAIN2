#ifndef SLUAGH_H
#define SLUAGH_H

extern unsigned long SLUAGH_Query(struct _Instance *instance, unsigned long query);

extern void SLUAGH_DamageEffect(struct _Instance *instance, struct evFXHitData *data);

extern void SLUAGH_Init(struct _Instance *instance);

extern void SLUAGH_DeathEntry(struct _Instance *instance);

extern void SLUAGH_Death(struct _Instance *instance);

extern void SLUAGH_AttackEntry(struct _Instance *instance);

extern void SLUAGH_Attack(struct _Instance *instance);

#endif
