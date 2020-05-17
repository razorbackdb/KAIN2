#ifndef HEALTH_H
#define HEALTH_H


extern void InitHealthSystem(); // 0x800A44A0

extern void GainHealth(int data); // 0x800A4540

extern void LoseHealth(int amount); // 0x800A45CC

extern void DrainHealth(int amount); // 0x800A46C8

extern void BumpUpHealth(); // 0x800A47E4

extern int GetMaxHealth(); // 0x800A4810

extern void ProcessHealth(struct _Instance *instance); // 0x800A4860

extern int HealthCheckForLowHealth(); // 0x800A4D0C

extern void DrainMana(int amount); // 0x800A4D78

extern void SetMana(int amount); // 0x800A4DBC

extern void HealthInstantDeath(struct _Instance *instance); // 0x800A4DE4

extern void RAZIEL_DebugHealthSetScale(long healthScale); // 0x800A4E64

extern void RAZIEL_DebugManaSetMax(long manaScale); // 0x800A4EBC

extern void RAZIEL_DebugHealthFillUp(); // 0x800A4ED0

extern void RAZIEL_DebugManaFillUp(); // 0x800A4F30

extern void razPlayUnderworldSounds(struct _Instance *instance); // 0x800A4F50


#endif
