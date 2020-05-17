#ifndef MONLIB_H
#define MONLIB_H


extern void MON_TurnOffWeaponSpheres(struct _Instance *instance); // 0x8007F5D8

extern void MON_TurnOnWeaponSpheres(struct _Instance *instance); // 0x8007F6D0

extern void MON_TurnOnWeaponSphere(struct _Instance *instance, int segment); // 0x8007F788

extern void MON_TurnOffBodySpheres(struct _Instance *instance); // 0x8007F890

extern void MON_TurnOnBodySpheres(struct _Instance *instance); // 0x8007F938

extern void MON_TurnOffAllSpheres(struct _Instance *instance); // 0x8007F9EC

extern void MON_TurnOnAllSpheres(struct _Instance *instance); // 0x8007FA18

extern void MON_SwitchState(struct _Instance *instance, enum MonsterState state); // 0x8007FA44

extern void MON_SwitchStateDoEntry(struct _Instance *instance, enum MonsterState state); // 0x8007FB40

extern int MON_TransNodeAnimation(struct _Instance *instance); // 0x8007FBA8

extern struct _MonsterAnim * MON_GetAnim(struct _Instance *instance, char *animList, int index); // 0x8007FBD0

extern void MON_PlayAnimID(struct _Instance *instance, int index, int mode); // 0x8007FC04

extern void MON_PlayAnimFromList(struct _Instance *instance, char *animList, int animtype, int mode); // 0x8007FDBC

extern int MON_AnimIDPlaying(struct _Instance *instance, int index); // 0x8007FDE4

extern void MON_PlayAnimIDIfNotPlaying(struct _Instance *instance, int index, int mode); // 0x8007FE08

extern int MON_AnimPlayingFromList(struct _Instance *instance, char *animList, int animtype); // 0x8007FE58

extern void MON_PlayAnimFromListIfNotPlaying(struct _Instance *instance, char *animList, int animtype, int mode); // 0x8007FE80

extern void MON_PlayAnim(struct _Instance *instance, enum MonsterAnim animtype, int mode); // 0x8007FED8

extern int MON_AnimPlaying(struct _Instance *instance, enum MonsterAnim animtype); // 0x8007FF0C

extern void MON_PlayAnimIfNotPlaying(struct _Instance *instance, enum MonsterAnim animtype, int mode); // 0x8007FF40

extern long MON_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x8007FF74

extern void MON_AnimInit(struct _Instance *instance); // 0x80080024

extern short MON_FacingOffset(struct _Instance *instance, struct _Instance *target); // 0x8008019C

extern int MON_CheckConditions(struct _Instance *instance, struct _MonsterIR *mir, char *probArray); // 0x800801D8

extern int MON_ShouldIAttackInstance(struct _Instance *instance, struct _Instance *ei); // 0x800802B0

extern int MON_ShouldIAttack(struct _Instance *instance, struct _MonsterIR *enemy, struct _MonsterAttackAttributes *attack); // 0x800803D4

extern struct _MonsterAttackAttributes * MON_ChooseAttack(struct _Instance *instance, struct _MonsterIR *enemy); // 0x8008057C

extern int MON_ShouldIEvade(struct _Instance *instance); // 0x800806DC

extern int MON_ChooseLeftOrRight(struct _Instance *instance, struct _MonsterIR *enemy); // 0x80080788

extern int MON_ChooseEvadeMove(struct _Instance *instance); // 0x8008082C

extern int MON_ChooseCombatMove(struct _Instance *instance, int reason); // 0x80080888

extern void MON_PlayRandomIdle(struct _Instance *instance, int mode); // 0x80080CD0

extern void MON_PlayCombatIdle(struct _Instance *instance, int mode); // 0x80080E74

extern void MON_GetRandomPoint(struct _Position *out, struct _Position *in, short r); // 0x80080EB4

extern int MON_GetRandomDestinationInWorld(struct _Instance *instance, struct _Position *in, short r); // 0x80080F60

extern void MON_MoveForward(struct _Instance *instance); // 0x80081148

extern int MON_TurnToPosition(struct _Instance *instance, struct _Position *position, short turnspeed); // 0x80081198

extern void MON_MoveToPosition(struct _Instance *instance, struct _Position *position, short turnSpeed); // 0x80081208

extern int MON_OnGround(struct _Instance *instance); // 0x8008124C

extern void MON_ApplyPhysics(struct _Instance *instance); // 0x8008133C

extern void MON_ChangeBehavior(struct _Instance *instance, int behavior); // 0x80081360

extern void MON_CheckEnvironment(struct _Instance *instance); // 0x800813E8

extern void MON_CheckTerrainAndRespond(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface); // 0x80081824

extern unsigned long MON_CheckTerrain(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface); // 0x800818A8

extern int MON_CheckPointSuitability(struct _Instance *instance, struct _Position *origin, struct _Position *destination); // 0x80081968

extern unsigned long MON_GetTime(struct _Instance *instance); // 0x80081A40

extern void MON_BirthSoul(struct _Instance *instance, int link); // 0x80081A94

extern void MON_ProcessIntro(struct _Instance *instance); // 0x80081BF8

extern void MON_SetDefaults(struct _Instance *instance); // 0x80082124

extern void MON_GetPlanSlot(struct _MonsterVars *mv); // 0x80082324

extern int MON_DefaultPlanMovement(struct _Instance *instance, int anim, long distance); // 0x80082368

extern void MON_DropAllObjects(struct _Instance *instance); // 0x80082608

extern void MON_EnableHeadMove(struct _Instance *instance); // 0x80082678

extern void MON_DisableHeadMove(struct _Instance *instance); // 0x80082720

extern void MON_LookInDirection(struct _Instance *instance, short tx, short tz); // 0x800827AC

extern void MON_LookAtPos(struct _Instance *instance, struct _Position *position); // 0x80082920

extern void MON_ProcessLookAt(struct _Instance *instance); // 0x800829FC

extern int MON_TakeDamage(struct _Instance *instance, int damage, int type); // 0x80082AF0

extern void MON_SetUpSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData); // 0x80082B9C

extern void MON_GetSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData); // 0x80082D08

extern void MON_KillMonster(struct _Instance *instance); // 0x80082F40

extern int MON_ShouldIAmbushEnemy(struct _Instance *instance); // 0x80083118

extern int MON_ShouldIFireAtTarget(struct _Instance *instance, struct _MonsterIR *target); // 0x80083284

extern int MON_ShouldIFlee(struct _Instance *instance); // 0x80083374

extern void MON_RelocateCoords(struct _Instance *instance, struct _SVector *offset); // 0x80083474

extern int MON_ValidUnit(struct _Instance *instance, unsigned long unitId); // 0x80083500

extern int MON_ValidPosition(struct _Instance *instance); // 0x8008354C

extern void MON_SphereWorldPos(struct MATRIX *mat, struct _HSphere *sphere, struct _Position *ret); // 0x800835A4

extern struct _HPrim * MON_FindSphereForTerrain(struct _Instance *instance); // 0x80083614

extern struct Intro * MON_FindNearestImpalingIntro(int unitID, struct _Position *position); // 0x800836A0

extern struct Intro * MON_TestForTerrainImpale(struct _Instance *instance, struct _Terrain *terrain); // 0x800837D0

extern void MON_MoveInstanceToImpalePoint(struct _Instance *instance); // 0x800838CC

extern int MON_ReachableIntro(struct _Instance *instance, struct _Position *pos, struct _Position *introPos, struct _Rotation *introRot, int checkOrientation); // 0x800839B0

extern int MON_SetVelocityTowardsImpalingObject(struct _Instance *instance, int checkOrientation); // 0x80083D78

extern void MON_TurnOffSphereCollisions(struct _Instance *instance); // 0x80083EEC

extern void MON_TurnOnSphereCollisions(struct _Instance *instance); // 0x80083F48

extern void MON_ProcessSpecialFade(struct _Instance *instance); // 0x80083FA4

extern void MON_StartSpecialFade(struct _Instance *instance, int fadeLevel, int fadeTime); // 0x800841E0

extern void MON_UnlinkFromRaziel(struct _Instance *instance); // 0x80084248

extern void MON_BurnInAir(struct _Instance *instance, int currentState); // 0x800842E8

extern void MON_BirthMana(struct _Instance *instance); // 0x800843A4

extern void MON_SoulSucked(struct _Instance *instance); // 0x8008445C

extern int MON_SetUpKnockBack(struct _Instance *instance, struct _Instance *enemy, struct evMonsterHitData *data); // 0x800844D4

extern void MON_DoDrainEffects(struct _Instance *instance, struct _Instance *ei); // 0x800845D8

extern void MON_SetFXHitData(struct _Instance *instance, struct evFXHitData *data, int type, int amount); // 0x80084864

extern void MON_LaunchMonster(struct _Instance *instance, int zDirection, int power, int loft); // 0x800848F0


#endif
