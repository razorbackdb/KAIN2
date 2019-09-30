#ifndef MONSTER_H
#define MONSTER_H


extern void MON_DoCombatTimers(struct _Instance *instance); // 0x80086DCC

extern void MON_ChangeHumanOpinion(struct _Instance *instance); // 0x80086FB4

extern void MON_CutOut_Monster(struct _Instance *instance, int fade_amount, int startseg, int endseg); // 0x80087050

extern void MON_DeadEntry(struct _Instance *instance); // 0x80087294

extern void MON_Dead(struct _Instance *instance); // 0x80087378

extern void MON_MissileHitEntry(struct _Instance *instance); // 0x80087A04

extern void MON_MissileHit(struct _Instance *instance); // 0x80087AE8

extern void MON_BirthEntry(struct _Instance *instance); // 0x80087BC8

extern void MON_Birth(struct _Instance *instance); // 0x80087BD0

extern void MON_ParryEntry(struct _Instance *instance); // 0x80087BF0

extern void MON_Parry(struct _Instance *instance); // 0x80087C40

extern void MON_LandOnFeetEntry(struct _Instance *instance); // 0x80087C84

extern void MON_LandOnFeet(struct _Instance *instance); // 0x80087D2C

extern void MON_LandInWaterEntry(struct _Instance *instance); // 0x80087E34

extern void MON_LandInWater(struct _Instance *instance); // 0x80087E48

extern void MON_BreakHoldEntry(struct _Instance *instance); // 0x80087E68

extern void MON_BreakHold(struct _Instance *instance); // 0x80087ED4

extern void MON_ImpactEntry(struct _Instance *instance); // 0x80087F48

extern void MON_Impact(struct _Instance *instance); // 0x80087FEC

extern void MON_FallEntry(struct _Instance *instance); // 0x8008806C

extern void MON_Fall(struct _Instance *instance); // 0x8008811C

extern void MON_ThrownEntry(struct _Instance *instance); // 0x80088208

extern void MON_Thrown(struct _Instance *instance); // 0x800882A4

extern void MON_ImpaleDeathEntry(struct _Instance *instance); // 0x800883FC

extern void MON_ImpaleDeath(struct _Instance *instance); // 0x80088494

extern void MON_TerrainImpaleDeathEntry(struct _Instance *instance); // 0x8008869C

extern void MON_TerrainImpaleDeath(struct _Instance *instance); // 0x800887FC

extern void MON_SurprisedEntry(struct _Instance *instance); // 0x800889F0

extern void MON_Surprised(struct _Instance *instance); // 0x80088A50

extern void MON_StunnedEntry(struct _Instance *instance); // 0x80088B14

extern void MON_Stunned(struct _Instance *instance); // 0x80088CC4

extern void MON_GrabbedEntry(struct _Instance *instance); // 0x80088DD4

extern void MON_Grabbed(struct _Instance *instance); // 0x80088ED0

extern void MON_HitEntry(struct _Instance *instance); // 0x8008916C

extern void MON_Hit(struct _Instance *instance); // 0x80089210

extern void MON_AttackEntry(struct _Instance *instance); // 0x800892F8

extern void MON_Attack(struct _Instance *instance); // 0x8008936C

extern void MON_CombatEntry(struct _Instance *instance); // 0x8008954C

extern void MON_Combat(struct _Instance *instance); // 0x80089578

extern void MON_ProjectileEntry(struct _Instance *instance); // 0x80089844

extern void MON_Projectile(struct _Instance *instance); // 0x8008989C

extern void MON_IdleEntry(struct _Instance *instance); // 0x800899E0

extern void MON_Idle(struct _Instance *instance); // 0x80089A98

extern void MON_FleeEntry(struct _Instance *instance); // 0x80089CB8

extern void MON_Flee(struct _Instance *instance); // 0x80089D0C

extern void MON_PursueEntry(struct _Instance *instance); // 0x80089E3C

extern void MON_Pursue(struct _Instance *instance); // 0x80089ECC

extern void MON_WanderEntry(struct _Instance *instance); // 0x8008A1E8

extern void MON_Wander(struct _Instance *instance); // 0x8008A290

extern void MON_HideEntry(struct _Instance *instance); // 0x8008A508

extern void MON_Hide(struct _Instance *instance); // 0x8008A528

extern void MON_SurpriseAttackEntry(struct _Instance *instance); // 0x8008A6A4

extern void MON_SurpriseAttack(struct _Instance *instance); // 0x8008A738

extern void MON_EnvironmentDamageEntry(struct _Instance *instance); // 0x8008A758

extern void MON_EnvironmentDamage(struct _Instance *instance); // 0x8008A760

extern void MON_MonsterGlow(struct _Instance *instance, long color, int glowtime, int glowin, int glowfade); // 0x8008A768

extern void MON_GeneralDeathEntry(struct _Instance *instance); // 0x8008A8F4

extern void MON_GeneralDeath(struct _Instance *instance); // 0x8008AB44

extern void MON_NoticeEntry(struct _Instance *instance); // 0x8008AC64

extern void MON_Notice(struct _Instance *instance); // 0x8008AD1C

extern void MON_PupateEntry(struct _Instance *instance); // 0x8008ADBC

extern void MON_Pupate(struct _Instance *instance); // 0x8008AE1C

extern void MON_EmbraceEntry(struct _Instance *instance); // 0x8008B15C

extern void MON_Embrace(struct _Instance *instance); // 0x8008B1BC

extern void MON_PetrifiedEntry(struct _Instance *instance); // 0x8008B328

extern void MON_Petrified(struct _Instance *instance); // 0x8008B364

extern int MONSTER_CalcDamageIntensity(int hp, int maxHp); // 0x8008B450

extern void MONSTER_ProcessClosestVerts(struct _Instance *instance, struct _SVector *location, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb, void *cb_data); // 0x8008B468

extern void ProcessBloodyMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008B630

extern void MONSTER_InitVertexColors(struct _Instance *instance, struct _Model *model); // 0x8008B73C

extern int MONSTER_StartVertexBlood(struct _Instance *instance, struct _SVector *location, int amount); // 0x8008B7A4

extern void MONSTER_VertexBlood(struct _Instance *instance, int vert, int amount); // 0x8008B92C

extern void ProcessBurntMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008BAF8

extern int MONSTER_StartVertexBurnt(struct _Instance *instance, struct _SVector *location, struct burntTuneType *burntTune); // 0x8008BBA4

extern void MONSTER_VertexBurnt(struct _Instance *instance, struct burntTuneType *burntTune); // 0x8008BD24

extern void MON_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008BDD0

extern void MON_DefaultInit(struct _Instance *instance); // 0x8008C250

extern void MON_CleanUp(struct _Instance *instance); // 0x8008C460


typedef void (*TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb)();




#endif
