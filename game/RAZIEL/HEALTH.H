#ifndef HEALTH_H
#define HEALTH_H


extern void InitHealthSystem(); // 0x800A3730

extern void GainHealth(int data); // 0x800A37D0

extern void LoseHealth(int amount); // 0x800A385C

extern void DrainHealth(int amount); // 0x800A3934

extern void BumpUpHealth(); // 0x800A3A18

extern int GetMaxHealth(); // 0x800A3A44

extern void ProcessHealth(struct _Instance *instance); // 0x800A3A94

extern int HealthCheckForLowHealth(); // 0x800A3F4C

extern void DrainMana(int amount); // 0x800A3FB8

extern void SetMana(int amount); // 0x800A3FFC

extern void HealthInstantDeath(struct _Instance *instance); // 0x800A4024

extern void RAZIEL_DebugHealthSetScale(long healthScale); // 0x800A40A4

extern void RAZIEL_DebugHealthFillUp(); // 0x800A40FC

extern void RAZIEL_DebugManaFillUp(); // 0x800A415C

extern void razPlayUnderworldSounds(struct _Instance *instance); // 0x800A417C


#endif
