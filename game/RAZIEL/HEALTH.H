#ifndef HEALTH_H
#define HEALTH_H


extern void InitHealthSystem(); // 0x800A0F5C

extern void GainHealth(int data); // 0x800A0FF0

extern void LoseHealth(int amount); // 0x800A107C

extern void DrainHealth(int amount); // 0x800A1130

extern void BumpUpHealth(); // 0x800A11A8

extern int GetMaxHealth(); // 0x800A1208

extern void ProcessHealth(struct _Instance *instance); // 0x800A1258

extern int HealthCheckForLowHealth(); // 0x800A15A0

extern void DrainMana(int amount); // 0x800A160C

extern void SetMana(int amount); // 0x800A1650

extern void HealthInstantDeath(struct _Instance *instance); // 0x800A1678

extern void RAZIEL_DebugHealthSetScale(long healthScale); // 0x800A16BC

extern void RAZIEL_DebugHealthFillUp(); // 0x800A1714


#endif
