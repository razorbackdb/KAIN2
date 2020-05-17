#ifndef MONSTER_H
#define MONSTER_H


extern void MON_DoCombatTimers(struct _Instance *instance); // 0x800873B8

extern void MON_ChangeHumanOpinion(struct _Instance *instance); // 0x800875A0

extern void MON_CutOut_Monster(struct _Instance *instance, int fade_amount, int startseg, int endseg); // 0x80087648

extern void MON_DeadEntry(struct _Instance *instance); // 0x8008789C

extern void MON_Dead(struct _Instance *instance); // 0x8008798C

extern void MON_MissileHitEntry(struct _Instance *instance); // 0x800880C0

extern void MON_MissileHit(struct _Instance *instance); // 0x8008818C

extern void MON_BirthEntry(struct _Instance *instance); // 0x8008826C

extern void MON_Birth(struct _Instance *instance); // 0x80088274

extern void MON_ParryEntry(struct _Instance *instance); // 0x80088294

extern void MON_Parry(struct _Instance *instance); // 0x800882E4

extern void MON_LandOnFeetEntry(struct _Instance *instance); // 0x80088328

extern void MON_LandOnFeet(struct _Instance *instance); // 0x800883EC

extern void MON_LandInWaterEntry(struct _Instance *instance); // 0x80088578

extern void MON_LandInWater(struct _Instance *instance); // 0x8008858C

extern void MON_BreakHoldEntry(struct _Instance *instance); // 0x800885AC

extern void MON_BreakHold(struct _Instance *instance); // 0x80088618

extern void MON_ImpactEntry(struct _Instance *instance); // 0x800887F4

extern void MON_Impact(struct _Instance *instance); // 0x800888D8

extern void MON_FallEntry(struct _Instance *instance); // 0x80088958

extern void MON_Fall(struct _Instance *instance); // 0x80088A18

extern void MON_ThrownEntry(struct _Instance *instance); // 0x80088B94

extern void MON_Thrown(struct _Instance *instance); // 0x80088C30

extern void MON_ImpaleDeathEntry(struct _Instance *instance); // 0x80088D88

extern void MON_ImpaleDeath(struct _Instance *instance); // 0x80088E08

extern void MON_TerrainImpaleDeathEntry(struct _Instance *instance); // 0x80089010

extern void MON_TerrainImpaleDeath(struct _Instance *instance); // 0x80089164

extern void MON_SurprisedEntry(struct _Instance *instance); // 0x8008934C

extern void MON_Surprised(struct _Instance *instance); // 0x800893AC

extern void MON_StunnedEntry(struct _Instance *instance); // 0x80089470

extern void MON_Stunned(struct _Instance *instance); // 0x80089620

extern void MON_GrabbedEntry(struct _Instance *instance); // 0x80089730

extern void MON_Grabbed(struct _Instance *instance); // 0x80089814

extern void MON_HitEntry(struct _Instance *instance); // 0x80089A2C

extern void MON_Hit(struct _Instance *instance); // 0x80089AD0

extern void MON_AttackEntry(struct _Instance *instance); // 0x80089BB8

extern void MON_Attack(struct _Instance *instance); // 0x80089C2C

extern void MON_CombatEntry(struct _Instance *instance); // 0x80089E0C

extern void MON_Combat(struct _Instance *instance); // 0x80089E38

extern void MON_ProjectileEntry(struct _Instance *instance); // 0x8008A120

extern void MON_Projectile(struct _Instance *instance); // 0x8008A178

extern void MON_IdleEntry(struct _Instance *instance); // 0x8008A2BC

extern void MON_Idle(struct _Instance *instance); // 0x8008A374

extern void MON_FleeEntry(struct _Instance *instance); // 0x8008A5B0

extern void MON_Flee(struct _Instance *instance); // 0x8008A604

extern void MON_PursueEntry(struct _Instance *instance); // 0x8008A748

extern void MON_Pursue(struct _Instance *instance); // 0x8008A7D8

extern void MON_WanderEntry(struct _Instance *instance); // 0x8008AC10

extern void MON_Wander(struct _Instance *instance); // 0x8008ACB8

extern void MON_HideEntry(struct _Instance *instance); // 0x8008AF30

extern void MON_Hide(struct _Instance *instance); // 0x8008AF50

extern void MON_SurpriseAttackEntry(struct _Instance *instance); // 0x8008B0CC

extern void MON_SurpriseAttack(struct _Instance *instance); // 0x8008B160

extern void MON_EnvironmentDamageEntry(struct _Instance *instance); // 0x8008B180

extern void MON_EnvironmentDamage(struct _Instance *instance); // 0x8008B188

extern void MON_MonsterGlow(struct _Instance *instance, long color, int glowtime, int glowin, int glowfade); // 0x8008B190

extern void MON_GeneralDeathEntry(struct _Instance *instance); // 0x8008B31C

extern void MON_GeneralDeath(struct _Instance *instance); // 0x8008B568

extern void MON_NoticeEntry(struct _Instance *instance); // 0x8008B6E0

extern void MON_Notice(struct _Instance *instance); // 0x8008B798

extern void MON_PupateEntry(struct _Instance *instance); // 0x8008B838

extern void MON_Pupate(struct _Instance *instance); // 0x8008B898

extern void MON_EmbraceEntry(struct _Instance *instance); // 0x8008BBD8

extern void MON_Embrace(struct _Instance *instance); // 0x8008BC38

extern void MON_PetrifiedEntry(struct _Instance *instance); // 0x8008BDB8

extern void MON_Petrified(struct _Instance *instance); // 0x8008BDF4

extern int MONSTER_CalcDamageIntensity(int hp, int maxHp); // 0x8008BF00

extern void MONSTER_ProcessClosestVerts(struct _Instance *instance, struct _SVector *location, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb, void *cb_data); // 0x8008BF18

extern void ProcessBloodyMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008C0E0

extern void MONSTER_InitVertexColors(struct _Instance *instance, struct _Model *model); // 0x8008C1EC

extern int MONSTER_StartVertexBlood(struct _Instance *instance, struct _SVector *location, int amount); // 0x8008C254

extern void MONSTER_VertexBlood(struct _Instance *instance, int vert, int amount); // 0x8008C3DC

extern void ProcessBurntMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data); // 0x8008C5A8

extern int MONSTER_StartVertexBurnt(struct _Instance *instance, struct _SVector *location, struct burntTuneType *burntTune); // 0x8008C654

extern void MONSTER_VertexBurnt(struct _Instance *instance, struct burntTuneType *burntTune); // 0x8008C7D4

extern void MON_DamageEffect(struct _Instance *instance, struct evFXHitData *data); // 0x8008C880

extern void MON_DefaultInit(struct _Instance *instance); // 0x8008CCE4

extern void MON_CleanUp(struct _Instance *instance); // 0x8008CF30


typedef void (*TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb)();




#endif
