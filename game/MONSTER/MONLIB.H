#ifndef MONLIB_H
#define MONLIB_H

extern void MON_TurnOffWeaponSpheres(struct _Instance *instance);

extern void MON_TurnOnWeaponSpheres(struct _Instance *instance);

extern void MON_TurnOnWeaponSphere(struct _Instance *instance, int segment);

extern void MON_TurnOffBodySpheres(struct _Instance *instance);

extern void MON_TurnOnBodySpheres(struct _Instance *instance);

extern void MON_TurnOffAllSpheres(struct _Instance *instance);

extern void MON_TurnOnAllSpheres(struct _Instance *instance);

extern void MON_SwitchState(struct _Instance *instance, enum MonsterState state);

extern void MON_SwitchStateDoEntry(struct _Instance *instance, enum MonsterState state);

extern int MON_TransNodeAnimation(struct _Instance *instance);

extern struct _MonsterAnim *MON_GetAnim(struct _Instance *instance, char *animList, int index);

extern void MON_PlayAnimID(struct _Instance *instance, int index, int mode);

extern void MON_PlayAnimFromList(struct _Instance *instance, char *animList, int animtype, int mode);

extern int MON_AnimIDPlaying(struct _Instance *instance, int index);

extern void MON_PlayAnimIDIfNotPlaying(struct _Instance *instance, int index, int mode);

extern int MON_AnimPlayingFromList(struct _Instance *instance, char *animList, int animtype);

extern void MON_PlayAnimFromListIfNotPlaying(struct _Instance *instance, char *animList, int animtype, int mode);

extern void MON_PlayAnim(struct _Instance *instance, enum MonsterAnim animtype, int mode);

extern int MON_AnimPlaying(struct _Instance *instance, enum MonsterAnim animtype);

extern void MON_PlayAnimIfNotPlaying(struct _Instance *instance, enum MonsterAnim animtype, int mode);

extern long MON_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data);

extern void MON_AnimInit(struct _Instance *instance);

extern short MON_FacingOffset(struct _Instance *instance, struct _Instance *target);

extern int MON_CheckConditions(struct _Instance *instance, struct _MonsterIR *mir, char *probArray);

extern int MON_ShouldIAttack(struct _Instance *instance, struct _MonsterIR *enemy, struct _MonsterAttackAttributes *attack);

extern struct _MonsterAttackAttributes *MON_ChooseAttack(struct _Instance *instance, struct _MonsterIR *enemy);

extern int MON_ShouldIEvade(struct _Instance *instance);

extern int MON_ChooseLeftOrRight(struct _Instance *instance, struct _MonsterIR *enemy);

extern int MON_ChooseEvadeMove(struct _Instance *instance);

extern int MON_ChooseCombatMove(struct _Instance *instance, int reason);

extern void MON_PlayRandomIdle(struct _Instance *instance, int mode);

extern void MON_PlayCombatIdle(struct _Instance *instance, int mode);

extern void MON_GetRandomPoint(struct _Position *out, struct _Position *in, short r);

extern int MON_GetRandomGroundPoint(struct _Instance *instance, struct _Position *out, struct _Position *in, short r0, int r1, int theta0, int theta1, int h);

extern int MON_GetRandomDestinationInWorld(struct _Instance *instance, struct _Position *in, short r);

extern void MON_MoveForward(struct _Instance *instance);

extern int MON_TurnToPosition(struct _Instance *instance, struct _Position *position, short turnspeed);

extern void MON_MoveToPosition(struct _Instance *instance, struct _Position *position, short turnSpeed);

extern int MON_OnGround(struct _Instance *instance);

extern void MON_ApplyPhysics(struct _Instance *instance);

extern void MON_ChangeBehavior(struct _Instance *instance, int behavior);

extern void MON_CheckEnvironment(struct _Instance *instance);

extern void MON_CheckTerrainAndRespond(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface);

extern unsigned long MON_CheckTerrain(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface);

extern int MON_CheckPointSuitability(struct _Instance *instance, struct _Position *origin, struct _Position *destination);

extern unsigned long MON_GetTime(struct _Instance *instance);

extern void MON_BirthSoul(struct _Instance *instance, int link);

extern void MON_ProcessIntro(struct _Instance *instance);

extern void MON_SetDefaults(struct _Instance *instance);

extern void MON_GetPlanSlot(struct _MonsterVars *mv);

extern int MON_DefaultPlanMovement(struct _Instance *instance, int anim, long distance);

extern void MON_DropAllObjects(struct _Instance *instance);

extern void MON_EnableHeadMove(struct _Instance *instance);

extern void MON_DisableHeadMove(struct _Instance *instance);

extern void MON_LookInDirection(struct _Instance *instance, short tx, short tz);

extern void MON_LookAtPos(struct _Instance *instance, struct _Position *position);

extern void MON_ProcessLookAt(struct _Instance *instance);

extern int MON_TakeDamage(struct _Instance *instance, int damage, int type);

extern void MON_SetUpSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData);

extern void MON_GetSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData);

extern void MON_KillMonster(struct _Instance *instance);

extern int MON_ShouldIAmbushEnemy(struct _Instance *instance);

extern int MON_ShouldIFireAtTarget(struct _Instance *instance, struct _MonsterIR *target);

extern int MON_ShouldIFlee(struct _Instance *instance);

extern void MON_RelocateCoords(struct _Instance *instance, struct _SVector *offset);

extern int MON_ValidUnit(struct _Instance *instance, unsigned long unitId);

extern int MON_ValidPosition(struct _Instance *instance);

extern void MON_SphereWorldPos(struct MATRIX *mat, struct _HSphere *sphere, struct _Position *ret);

extern struct _HPrim *MON_FindSphereForTerrain(struct _Instance *instance);

extern struct Intro *MON_FindNearestImpalingIntro(int unitID, struct _Position *position);

extern struct Intro *MON_TestForTerrainImpale(struct _Instance *instance, struct _Terrain *terrain);

extern void MON_MoveInstanceToImpalePoint(struct _Instance *instance);

extern int MON_ReachableIntro(struct _Instance *instance, struct _Position *pos, struct _Position *introPos, struct _Rotation *introRot, int checkOrientation);

extern int MON_SetVelocityTowardsImpalingObject(struct _Instance *instance, int checkOrientation);

extern void MON_TurnOffSphereCollisions(struct _Instance *instance);

extern void MON_TurnOnSphereCollisions(struct _Instance *instance);

extern void MON_ProcessSpecialFade(struct _Instance *instance);

extern void MON_StartSpecialFade(struct _Instance *instance, int fadeLevel, int fadeTime);

extern void MON_UnlinkFromRaziel(struct _Instance *instance);

extern void MON_BurnInAir(struct _Instance *instance, int currentState);

extern void MON_BirthMana(struct _Instance *instance);

extern void MON_SoulSucked(struct _Instance *instance);

extern int MON_SetUpKnockBack(struct _Instance *instance, struct _Instance *enemy, struct evMonsterHitData *data);

extern void MON_DoDrainEffects(struct _Instance *instance, struct _Instance *ei);

#endif
