#ifndef MONLIB_H
#define MONLIB_H


extern void MON_TurnOffWeaponSpheres(struct _Instance *instance); // 0x8007E848

extern void MON_TurnOnWeaponSpheres(struct _Instance *instance); // 0x8007E940

extern void MON_TurnOnWeaponSphere(struct _Instance *instance, int segment); // 0x8007E9F8

extern void MON_TurnOffBodySpheres(struct _Instance *instance); // 0x8007EB00

extern void MON_TurnOnBodySpheres(struct _Instance *instance); // 0x8007EBA8

extern void MON_TurnOffAllSpheres(struct _Instance *instance); // 0x8007EC5C

extern void MON_TurnOnAllSpheres(struct _Instance *instance); // 0x8007EC88

extern void MON_SwitchState(struct _Instance *instance, enum MonsterState state); // 0x8007ECB4

extern void MON_SwitchStateDoEntry(struct _Instance *instance, enum MonsterState state); // 0x8007ED78

extern int MON_TransNodeAnimation(struct _Instance *instance); // 0x8007EDE0

extern struct _MonsterAnim * MON_GetAnim(struct _Instance *instance, char *animList, int index); // 0x8007EE08

extern void MON_PlayAnimID(struct _Instance *instance, int index, int mode); // 0x8007EE3C

extern void MON_PlayAnimFromList(struct _Instance *instance, char *animList, int animtype, int mode); // 0x8007EFDC

extern int MON_AnimIDPlaying(struct _Instance *instance, int index); // 0x8007F004

extern void MON_PlayAnimIDIfNotPlaying(struct _Instance *instance, int index, int mode); // 0x8007F028

extern int MON_AnimPlayingFromList(struct _Instance *instance, char *animList, int animtype); // 0x8007F078

extern void MON_PlayAnimFromListIfNotPlaying(struct _Instance *instance, char *animList, int animtype, int mode); // 0x8007F0A0

extern void MON_PlayAnim(struct _Instance *instance, enum MonsterAnim animtype, int mode); // 0x8007F0F8

extern int MON_AnimPlaying(struct _Instance *instance, enum MonsterAnim animtype); // 0x8007F12C

extern void MON_PlayAnimIfNotPlaying(struct _Instance *instance, enum MonsterAnim animtype, int mode); // 0x8007F160

extern long MON_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x8007F194

extern void MON_AnimInit(struct _Instance *instance); // 0x8007F244

extern short MON_FacingOffset(struct _Instance *instance, struct _Instance *target); // 0x8007F3B0

extern int MON_CheckConditions(struct _Instance *instance, struct _MonsterIR *mir, char *probArray); // 0x8007F3EC

extern int MON_ShouldIAttack(struct _Instance *instance, struct _MonsterIR *enemy, struct _MonsterAttackAttributes *attack); // 0x8007F4C4

extern struct _MonsterAttackAttributes * MON_ChooseAttack(struct _Instance *instance, struct _MonsterIR *enemy); // 0x8007F650

extern int MON_ShouldIEvade(struct _Instance *instance); // 0x8007F7B0

extern int MON_ChooseLeftOrRight(struct _Instance *instance, struct _MonsterIR *enemy); // 0x8007F85C

extern int MON_ChooseEvadeMove(struct _Instance *instance); // 0x8007F900

extern int MON_ChooseCombatMove(struct _Instance *instance, int reason); // 0x8007FA90

extern void MON_PlayRandomIdle(struct _Instance *instance, int mode); // 0x8007FD60

extern void MON_PlayCombatIdle(struct _Instance *instance, int mode); // 0x8007FEFC

extern void MON_GetRandomPoint(struct _Position *out, struct _Position *in, short r); // 0x8007FF3C

extern int MON_GetRandomGroundPoint(struct _Instance *instance, struct _Position *out, struct _Position *in, short r0, int r1, int theta0, int theta1, int h); // 0x8007FFE8

extern int MON_GetRandomDestinationInWorld(struct _Instance *instance, struct _Position *in, short r); // 0x8008020C

extern void MON_MoveForward(struct _Instance *instance); // 0x800803F4

extern int MON_TurnToPosition(struct _Instance *instance, struct _Position *position, short turnspeed); // 0x80080444

extern void MON_MoveToPosition(struct _Instance *instance, struct _Position *position, short turnSpeed); // 0x800804B4

extern int MON_OnGround(struct _Instance *instance); // 0x800804F8

extern void MON_ApplyPhysics(struct _Instance *instance); // 0x80080604

extern void MON_ChangeBehavior(struct _Instance *instance, int behavior); // 0x80080628

extern void MON_CheckEnvironment(struct _Instance *instance); // 0x800806B0

extern void MON_CheckTerrainAndRespond(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface); // 0x80080A78

extern unsigned long MON_CheckTerrain(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface); // 0x80080AFC

extern int MON_CheckPointSuitability(struct _Instance *instance, struct _Position *origin, struct _Position *destination); // 0x80080BBC

extern unsigned long MON_GetTime(struct _Instance *instance); // 0x80080C94

extern void MON_BirthSoul(struct _Instance *instance, int link); // 0x80080CE8

extern void MON_ProcessIntro(struct _Instance *instance); // 0x80080E08

extern void MON_SetDefaults(struct _Instance *instance); // 0x800812DC

extern void MON_GetPlanSlot(struct _MonsterVars *mv); // 0x800814DC

extern int MON_DefaultPlanMovement(struct _Instance *instance, int anim, long distance); // 0x80081520

extern void MON_DropAllObjects(struct _Instance *instance); // 0x800817E8

extern void MON_EnableHeadMove(struct _Instance *instance); // 0x80081830

extern void MON_DisableHeadMove(struct _Instance *instance); // 0x800818D8

extern void MON_LookInDirection(struct _Instance *instance, short tx, short tz); // 0x80081964

extern void MON_LookAtPos(struct _Instance *instance, struct _Position *position); // 0x80081AD8

extern void MON_ProcessLookAt(struct _Instance *instance); // 0x80081BB4

extern int MON_TakeDamage(struct _Instance *instance, int damage, int type); // 0x80081CA8

extern void MON_SetUpSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData); // 0x80081D50

extern void MON_GetSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData); // 0x80081E68

extern void MON_KillMonster(struct _Instance *instance); // 0x80081FC0

extern int MON_ShouldIAmbushEnemy(struct _Instance *instance); // 0x800820B8

extern int MON_ShouldIFireAtTarget(struct _Instance *instance, struct _MonsterIR *target); // 0x8008220C

extern int MON_ShouldIFlee(struct _Instance *instance); // 0x800822FC

extern void MON_RelocateCoords(struct _Instance *instance, struct _SVector *offset); // 0x800823E8

extern int MON_ValidUnit(struct _Instance *instance, unsigned long unitId); // 0x80082444

extern int MON_ValidPosition(struct _Instance *instance); // 0x80082490

extern void MON_SphereWorldPos(struct MATRIX *mat, struct _HSphere *sphere, struct _Position *ret); // 0x800824E8

extern struct _HPrim * MON_FindSphereForTerrain(struct _Instance *instance); // 0x80082558

extern struct Intro * MON_FindNearestImpalingIntro(int unitID, struct _Position *position); // 0x800825E4

extern struct Intro * MON_TestForTerrainImpale(struct _Instance *instance, struct _Terrain *terrain); // 0x80082714

extern void MON_MoveInstanceToImpalePoint(struct _Instance *instance); // 0x80082810

extern int MON_ReachableIntro(struct _Instance *instance, struct _Position *pos, struct _Position *introPos, struct _Rotation *introRot, int checkOrientation); // 0x80082910

extern int MON_SetVelocityTowardsImpalingObject(struct _Instance *instance, int checkOrientation); // 0x80082CD8

extern void MON_TurnOffSphereCollisions(struct _Instance *instance); // 0x80082E34

extern void MON_TurnOnSphereCollisions(struct _Instance *instance); // 0x80082E90

extern void MON_ProcessSpecialFade(struct _Instance *instance); // 0x80082EEC

extern void MON_StartSpecialFade(struct _Instance *instance, int fadeLevel, int fadeTime); // 0x80083110

extern void MON_UnlinkFromRaziel(struct _Instance *instance); // 0x80083178

extern void MON_BirthMana(struct _Instance *instance); // 0x80083230

extern void MON_SoulSucked(struct _Instance *instance); // 0x800832E8

extern int MON_SetUpKnockBack(struct _Instance *instance, struct _Instance *enemy, struct evMonsterHitData *data); // 0x80083368

extern void MON_DoDrainEffects(struct _Instance *instance, struct _Instance *ei); // 0x8008346C


#endif
