#ifndef MONSTER_H
#define MONSTER_H

extern void MON_DoCombatTimers(struct _Instance *instance);

extern void MON_ChangeHumanOpinion(struct _Instance *instance);

extern void MON_CutOut_Monster(struct _Instance *instance, int fade_amount, int startseg, int endseg);

extern void MON_DeadEntry(struct _Instance *instance);

extern void MON_Dead(struct _Instance *instance);

extern void MON_MissileHitEntry(struct _Instance *instance);

extern void MON_MissileHit(struct _Instance *instance);

extern void MON_BirthEntry(struct _Instance *instance);

extern void MON_Birth(struct _Instance *instance);

extern void MON_ParryEntry(struct _Instance *instance);

extern void MON_Parry(struct _Instance *instance);

extern void MON_LandOnFeetEntry(struct _Instance *instance);

extern void MON_LandOnFeet(struct _Instance *instance);

extern void MON_LandInWaterEntry(struct _Instance *instance);

extern void MON_LandInWater(struct _Instance *instance);

extern void MON_BreakHoldEntry(struct _Instance *instance);

extern void MON_BreakHold(struct _Instance *instance);

extern void MON_ImpactEntry(struct _Instance *instance);

extern void MON_Impact(struct _Instance *instance);

extern void MON_FallEntry(struct _Instance *instance);

extern void MON_Fall(struct _Instance *instance);

extern void MON_ThrownEntry(struct _Instance *instance);

extern void MON_Thrown(struct _Instance *instance);

extern void MON_ImpaleDeathEntry(struct _Instance *instance);

extern void MON_ImpaleDeath(struct _Instance *instance);

extern void MON_TerrainImpaleDeathEntry(struct _Instance *instance);

extern void MON_TerrainImpaleDeath(struct _Instance *instance);

extern void MON_SurprisedEntry(struct _Instance *instance);

extern void MON_Surprised(struct _Instance *instance);

extern void MON_StunnedEntry(struct _Instance *instance);

extern void MON_Stunned(struct _Instance *instance);

extern void MON_GrabbedEntry(struct _Instance *instance);

extern void MON_Grabbed(struct _Instance *instance);

extern void MON_HitEntry(struct _Instance *instance);

extern void MON_Hit(struct _Instance *instance);

extern void MON_AttackEntry(struct _Instance *instance);

extern void MON_Attack(struct _Instance *instance);

extern void MON_CombatEntry(struct _Instance *instance);

extern void MON_Combat(struct _Instance *instance);

extern void MON_ProjectileEntry(struct _Instance *instance);

extern void MON_Projectile(struct _Instance *instance);

extern void MON_IdleEntry(struct _Instance *instance);

extern void MON_Idle(struct _Instance *instance);

extern void MON_FleeEntry(struct _Instance *instance);

extern void MON_Flee(struct _Instance *instance);

extern void MON_PursueEntry(struct _Instance *instance);

extern void MON_Pursue(struct _Instance *instance);

extern void MON_WanderEntry(struct _Instance *instance);

extern void MON_Wander(struct _Instance *instance);

extern void MON_HideEntry(struct _Instance *instance);

extern void MON_Hide(struct _Instance *instance);

extern void MON_SurpriseAttackEntry(struct _Instance *instance);

extern void MON_SurpriseAttack(struct _Instance *instance);

extern void MON_EnvironmentDamageEntry(struct _Instance *instance);

extern void MON_EnvironmentDamage(struct _Instance *instance);

extern void MON_MonsterGlow(struct _Instance *instance, long color, int glowtime, int glowin, int glowfade);

extern void MON_GeneralDeathEntry(struct _Instance *instance);

extern void MON_GeneralDeath(struct _Instance *instance);

extern void MON_NoticeEntry(struct _Instance *instance);

extern void MON_Notice(struct _Instance *instance);

extern void MON_PupateEntry(struct _Instance *instance);

extern void MON_Pupate(struct _Instance *instance);

extern void MON_EmbraceEntry(struct _Instance *instance);

extern void MON_Embrace(struct _Instance *instance);

extern void MON_PetrifiedEntry(struct _Instance *instance);

extern void MON_Petrified(struct _Instance *instance);

extern int MONSTER_CalcDamageIntensity(int hp, int maxHp);

extern void MONSTER_ProcessClosestVerts(struct _Instance *instance, struct _SVector *location, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb, void *cb_data);

extern void ProcessBloodyMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data);

extern void MONSTER_InitVertexColors(struct _Instance *instance, struct _Model *model);

extern int MONSTER_StartVertexBlood(struct _Instance *instance, struct _SVector *location, int amount);

extern void MONSTER_VertexBlood(struct _Instance *instance, int vert, int amount);

extern void ProcessBurntMess(struct _Instance *instance, int vertidx, int segidx, int dist, void *cb_data);

extern int MONSTER_StartVertexBurnt(struct _Instance *instance, struct _SVector *location, struct burntTuneType *burntTune);

extern void MONSTER_VertexBurnt(struct _Instance *instance, struct burntTuneType *burntTune);

extern void MON_DamageEffect(struct _Instance *instance, struct evFXHitData *data);

extern void MON_DefaultInit(struct _Instance *instance);

extern void MON_CleanUp(struct _Instance *instance);

typedef void (*TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb)();

#endif
