#ifndef HEALTH_H
#define HEALTH_H

extern void InitHealthSystem();

extern void GainHealth(int data);

extern void LoseHealth(int amount);

extern void DrainHealth(int amount);

extern void BumpUpHealth();

extern int GetMaxHealth();

extern void ProcessHealth(struct _Instance *instance);

extern int HealthCheckForLowHealth();

extern void DrainMana(int amount);

extern void SetMana(int amount);

extern void HealthInstantDeath(struct _Instance *instance);

extern void RAZIEL_DebugHealthSetScale(long healthScale);

extern void RAZIEL_DebugHealthFillUp();

extern void RAZIEL_DebugManaFillUp();

extern void razPlayUnderworldSounds(struct _Instance *instance);

#endif
