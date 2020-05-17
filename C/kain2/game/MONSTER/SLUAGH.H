#ifndef SLUAGH_H
#define SLUAGH_H


extern unsigned long SLUAGH_Query(struct _Instance *instance, unsigned long query); // 0x8008D208

extern void SLUAGH_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008D29C

extern void SLUAGH_Init(struct _Instance *instance); // 0x8008D490

extern void SLUAGH_DeathEntry(struct _Instance *instance); // 0x8008D54C

extern void SLUAGH_Death(struct _Instance *instance); // 0x8008D610

extern void SLUAGH_AttackEntry(struct _Instance *instance); // 0x8008D698

extern void SLUAGH_Attack(struct _Instance *instance); // 0x8008D6FC


#endif
