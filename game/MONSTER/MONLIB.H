#ifndef MONLIB_H
#define MONLIB_H


extern void MON_TurnOffWeaponSpheres(struct _Instance *instance); // 0x8007F2DC

extern void MON_TurnOnWeaponSpheres(struct _Instance *instance); // 0x8007F3D4

extern void MON_TurnOnWeaponSphere(struct _Instance *instance, int segment); // 0x8007F48C

extern void MON_TurnOffBodySpheres(struct _Instance *instance); // 0x8007F594

extern void MON_TurnOnBodySpheres(struct _Instance *instance); // 0x8007F63C

extern void MON_TurnOffAllSpheres(struct _Instance *instance); // 0x8007F6F0

extern void MON_TurnOnAllSpheres(struct _Instance *instance); // 0x8007F71C

extern void MON_SwitchState(struct _Instance *instance, enum MonsterState state); // 0x8007F748

extern void MON_SwitchStateDoEntry(struct _Instance *instance, enum MonsterState state); // 0x8007F844

extern int MON_TransNodeAnimation(struct _Instance *instance); // 0x8007F8AC

extern struct _MonsterAnim * MON_GetAnim(struct _Instance *instance, char *animList, int index); // 0x8007F8D4

extern void MON_PlayAnimID(struct _Instance *instance, int index, int mode); // 0x8007F908

extern void MON_PlayAnimFromList(struct _Instance *instance, char *animList, int animtype, int mode); // 0x8007FAC0

extern int MON_AnimIDPlaying(struct _Instance *instance, int index); // 0x8007FAE8

extern void MON_PlayAnimIDIfNotPlaying(struct _Instance *instance, int index, int mode); // 0x8007FB0C

extern int MON_AnimPlayingFromList(struct _Instance *instance, char *animList, int animtype); // 0x8007FB5C

extern void MON_PlayAnimFromListIfNotPlaying(struct _Instance *instance, char *animList, int animtype, int mode); // 0x8007FB84

extern void MON_PlayAnim(struct _Instance *instance, enum MonsterAnim animtype, int mode); // 0x8007FBDC

extern int MON_AnimPlaying(struct _Instance *instance, enum MonsterAnim animtype); // 0x8007FC10

extern void MON_PlayAnimIfNotPlaying(struct _Instance *instance, enum MonsterAnim animtype, int mode); // 0x8007FC44

extern long MON_AnimCallback(struct _G2Anim_Type *anim, int sectionID, enum _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data); // 0x8007FC78

extern void MON_AnimInit(struct _Instance *instance); // 0x8007FD28

extern short MON_FacingOffset(struct _Instance *instance, struct _Instance *target); // 0x8007FEA0

extern int MON_CheckConditions(struct _Instance *instance, struct _MonsterIR *mir, char *probArray); // 0x8007FEDC

extern int MON_ShouldIAttack(struct _Instance *instance, struct _MonsterIR *enemy, struct _MonsterAttackAttributes *attack); // 0x8007FFB4

extern struct _MonsterAttackAttributes * MON_ChooseAttack(struct _Instance *instance, struct _MonsterIR *enemy); // 0x800801B0

extern int MON_ShouldIEvade(struct _Instance *instance); // 0x80080310

extern int MON_ChooseLeftOrRight(struct _Instance *instance, struct _MonsterIR *enemy); // 0x800803BC

extern int MON_ChooseEvadeMove(struct _Instance *instance); // 0x80080460

extern int MON_ChooseCombatMove(struct _Instance *instance, int reason); // 0x800804BC

extern void MON_PlayRandomIdle(struct _Instance *instance, int mode); // 0x800807B4

extern void MON_PlayCombatIdle(struct _Instance *instance, int mode); // 0x80080958

extern void MON_GetRandomPoint(struct _Position *out, struct _Position *in, short r); // 0x80080998

extern int MON_GetRandomGroundPoint(struct _Instance *instance, struct _Position *out, struct _Position *in, short r0, int r1, int theta0, int theta1, int h); // 0x80080A44

extern int MON_GetRandomDestinationInWorld(struct _Instance *instance, struct _Position *in, short r); // 0x80080C60

extern void MON_MoveForward(struct _Instance *instance); // 0x80080E48

extern int MON_TurnToPosition(struct _Instance *instance, struct _Position *position, short turnspeed); // 0x80080E98

extern void MON_MoveToPosition(struct _Instance *instance, struct _Position *position, short turnSpeed); // 0x80080F08

extern int MON_OnGround(struct _Instance *instance); // 0x80080F4C

extern void MON_ApplyPhysics(struct _Instance *instance); // 0x80081058

extern void MON_ChangeBehavior(struct _Instance *instance, int behavior); // 0x8008107C

extern void MON_CheckEnvironment(struct _Instance *instance); // 0x80081104

extern void MON_CheckTerrainAndRespond(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface); // 0x80081500

extern unsigned long MON_CheckTerrain(struct _Instance *instance, struct BSPTree *bsp, struct _TFace *tface); // 0x80081584

extern int MON_CheckPointSuitability(struct _Instance *instance, struct _Position *origin, struct _Position *destination); // 0x80081644

extern unsigned long MON_GetTime(struct _Instance *instance); // 0x8008171C

extern void MON_BirthSoul(struct _Instance *instance, int link); // 0x80081770

extern void MON_ProcessIntro(struct _Instance *instance); // 0x800818C8

extern void MON_SetDefaults(struct _Instance *instance); // 0x80081DE0

extern void MON_GetPlanSlot(struct _MonsterVars *mv); // 0x80081FE0

extern int MON_DefaultPlanMovement(struct _Instance *instance, int anim, long distance); // 0x80082024

extern void MON_DropAllObjects(struct _Instance *instance); // 0x800822EC

extern void MON_EnableHeadMove(struct _Instance *instance); // 0x8008235C

extern void MON_DisableHeadMove(struct _Instance *instance); // 0x80082404

extern void MON_LookInDirection(struct _Instance *instance, short tx, short tz); // 0x80082490

extern void MON_LookAtPos(struct _Instance *instance, struct _Position *position); // 0x80082604

extern void MON_ProcessLookAt(struct _Instance *instance); // 0x800826E0

extern int MON_TakeDamage(struct _Instance *instance, int damage, int type); // 0x800827D4

extern void MON_SetUpSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData); // 0x8008287C

extern void MON_GetSaveInfo(struct _Instance *instance, struct _MonsterSaveInfo *saveData); // 0x800829B8

extern void MON_KillMonster(struct _Instance *instance); // 0x80082B78

extern int MON_ShouldIAmbushEnemy(struct _Instance *instance); // 0x80082C74

extern int MON_ShouldIFireAtTarget(struct _Instance *instance, struct _MonsterIR *target); // 0x80082DE0

extern int MON_ShouldIFlee(struct _Instance *instance); // 0x80082ED0

extern void MON_RelocateCoords(struct _Instance *instance, struct _SVector *offset); // 0x80082FBC

extern int MON_ValidUnit(struct _Instance *instance, unsigned long unitId); // 0x80083018

extern int MON_ValidPosition(struct _Instance *instance); // 0x80083064

extern void MON_SphereWorldPos(struct MATRIX *mat, struct _HSphere *sphere, struct _Position *ret); // 0x800830BC

extern struct _HPrim * MON_FindSphereForTerrain(struct _Instance *instance); // 0x8008312C

extern struct Intro * MON_FindNearestImpalingIntro(int unitID, struct _Position *position); // 0x800831B8

extern struct Intro * MON_TestForTerrainImpale(struct _Instance *instance, struct _Terrain *terrain); // 0x800832E8

extern void MON_MoveInstanceToImpalePoint(struct _Instance *instance); // 0x800833E4

extern int MON_ReachableIntro(struct _Instance *instance, struct _Position *pos, struct _Position *introPos, struct _Rotation *introRot, int checkOrientation); // 0x800834C8

extern int MON_SetVelocityTowardsImpalingObject(struct _Instance *instance, int checkOrientation); // 0x80083890

extern void MON_TurnOffSphereCollisions(struct _Instance *instance); // 0x80083A04

extern void MON_TurnOnSphereCollisions(struct _Instance *instance); // 0x80083A60

extern void MON_ProcessSpecialFade(struct _Instance *instance); // 0x80083ABC

extern void MON_StartSpecialFade(struct _Instance *instance, int fadeLevel, int fadeTime); // 0x80083CF8

extern void MON_UnlinkFromRaziel(struct _Instance *instance); // 0x80083D60

extern void MON_BurnInAir(struct _Instance *instance, int currentState); // 0x80083E18

extern void MON_BirthMana(struct _Instance *instance); // 0x80083EC4

extern void MON_SoulSucked(struct _Instance *instance); // 0x80083F7C

extern int MON_SetUpKnockBack(struct _Instance *instance, struct _Instance *enemy, struct evMonsterHitData *data); // 0x80083FF4

extern void MON_DoDrainEffects(struct _Instance *instance, struct _Instance *ei); // 0x800840F8


#endif
