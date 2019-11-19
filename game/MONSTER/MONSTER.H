#ifndef MONSTER_H
#define MONSTER_H


extern void MON_DoCombatTimers(struct _Instance *instance); // 0x80085CD8

extern void MON_ChangeHumanOpinion(struct _Instance *instance); // 0x80085EC0

extern void MON_CutOut_Monster(struct _Instance *instance, int fade_amount, int startseg, int endseg); // 0x80085F8C

extern void MON_DeadEntry(struct _Instance *instance); // 0x800861D0

extern void MON_Dead(struct _Instance *instance); // 0x800862AC

extern void MON_MissileHitEntry(struct _Instance *instance); // 0x80086808

extern void MON_MissileHit(struct _Instance *instance); // 0x800868C4

extern void MON_BirthEntry(struct _Instance *instance); // 0x800869A4

extern void MON_Birth(struct _Instance *instance); // 0x800869AC

extern void MON_ParryEntry(struct _Instance *instance); // 0x800869CC

extern void MON_Parry(struct _Instance *instance); // 0x80086A1C

extern void MON_LandOnFeetEntry(struct _Instance *instance); // 0x80086A60

extern void MON_LandOnFeet(struct _Instance *instance); // 0x80086B08

extern void MON_LandInWaterEntry(struct _Instance *instance); // 0x80086BD4

extern void MON_LandInWater(struct _Instance *instance); // 0x80086BE8

extern void MON_BreakHoldEntry(struct _Instance *instance); // 0x80086C08

extern void MON_BreakHold(struct _Instance *instance); // 0x80086C74

extern void MON_ImpactEntry(struct _Instance *instance); // 0x80086CB8

extern void MON_Impact(struct _Instance *instance); // 0x80086D5C

extern void MON_FallEntry(struct _Instance *instance); // 0x80086DA0

extern void MON_Fall(struct _Instance *instance); // 0x80086E48

extern void MON_ThrownEntry(struct _Instance *instance); // 0x80086F00

extern void MON_Thrown(struct _Instance *instance); // 0x80086F8C

extern void MON_ImpaleDeathEntry(struct _Instance *instance); // 0x8008714C

extern void MON_ImpaleDeath(struct _Instance *instance); // 0x800871D4

extern void MON_TerrainImpaleDeathEntry(struct _Instance *instance); // 0x80087364

extern void MON_TerrainImpaleDeath(struct _Instance *instance); // 0x800874C0

extern void MON_SurprisedEntry(struct _Instance *instance); // 0x800876A8

extern void MON_Surprised(struct _Instance *instance); // 0x80087708

extern void MON_StunnedEntry(struct _Instance *instance); // 0x800877CC

extern void MON_Stunned(struct _Instance *instance); // 0x8008796C

extern void MON_GrabbedEntry(struct _Instance *instance); // 0x80087A5C

extern void MON_Grabbed(struct _Instance *instance); // 0x80087B4C

extern void MON_HitEntry(struct _Instance *instance); // 0x80087D9C

extern void MON_Hit(struct _Instance *instance); // 0x80087E30

extern void MON_AttackEntry(struct _Instance *instance); // 0x80087EE0

extern void MON_Attack(struct _Instance *instance); // 0x80087F54

extern void MON_CombatEntry(struct _Instance *instance); // 0x80088118

extern void MON_Combat(struct _Instance *instance); // 0x80088144

extern void MON_ProjectileEntry(struct _Instance *instance); // 0x80088450

extern void MON_Projectile(struct _Instance *instance); // 0x800884A8

extern void MON_IdleEntry(struct _Instance *instance); // 0x800885EC

extern void MON_Idle(struct _Instance *instance); // 0x800886A4

extern void MON_FleeEntry(struct _Instance *instance); // 0x800888C4

extern void MON_Flee(struct _Instance *instance); // 0x80088918

extern void MON_PursueEntry(struct _Instance *instance); // 0x80088A28

extern void MON_Pursue(struct _Instance *instance); // 0x80088AB8

extern void MON_WanderEntry(struct _Instance *instance); // 0x80088DD4

extern void MON_Wander(struct _Instance *instance); // 0x80088E7C

extern void MON_HideEntry(struct _Instance *instance); // 0x800890F4

extern void MON_Hide(struct _Instance *instance); // 0x80089114

extern void MON_SurpriseAttackEntry(struct _Instance *instance); // 0x80089290

extern void MON_SurpriseAttack(struct _Instance *instance); // 0x80089324

extern void MON_EnvironmentDamageEntry(struct _Instance *instance); // 0x80089344

extern void MON_EnvironmentDamage(struct _Instance *instance); // 0x8008934C

extern void MON_MonsterGlow(struct _Instance *instance, long color, int glowtime, int glowin, int glowfade); // 0x80089354

extern void MON_GeneralDeathEntry(struct _Instance *instance); // 0x800894E0

extern void MON_GeneralDeath(struct _Instance *instance); // 0x800896BC

extern void MON_NoticeEntry(struct _Instance *instance); // 0x800897EC

extern void MON_Notice(struct _Instance *instance); // 0x800898A4

extern void MON_PupateEntry(struct _Instance *instance); // 0x80089944

extern void MON_Pupate(struct _Instance *instance); // 0x800899BC

extern void MON_EmbraceEntry(struct _Instance *instance); // 0x80089D04

extern void MON_Embrace(struct _Instance *instance); // 0x80089D28

extern int MONSTER_CalcDamageIntensity(int hp, int maxHp); // 0x80089E10

extern void MONSTER_ProcessClosestVerts(struct _Instance *instance, struct _SVector *location, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb, void *cb_data); // 0x80089E28

extern void ProcessBloodyMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x80089FF0

extern void MONSTER_InitVertexColors(struct _Instance *instance, struct _Model *model); // 0x8008A0E4

extern int MONSTER_StartVertexBlood(struct _Instance *instance, struct _SVector *location, int amount); // 0x8008A14C

extern void MONSTER_VertexBlood(struct _Instance *instance, int vert, int amount); // 0x8008A2D4

extern void ProcessBurntMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008A490

extern int MONSTER_StartVertexBurnt(struct _Instance *instance, struct _SVector *location, struct burntTuneType *burntTune); // 0x8008A53C

extern void MONSTER_VertexBurnt(struct _Instance *instance, struct burntTuneType *burntTune); // 0x8008A6BC

extern void MON_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008A768

extern void MON_DefaultInit(struct _Instance *instance); // 0x8008ABCC

extern void MON_CleanUp(struct _Instance *instance); // 0x8008ADDC


typedef void (*TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb)();




#endif
