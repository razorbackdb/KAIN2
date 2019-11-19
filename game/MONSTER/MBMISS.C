#include "THISDUST.H"
#include "MBMISS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Process(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$s5*/)
 // line 114, offset 0x8008d370
	/* begin block 1 */
		// Start line: 115
		// Start offset: 0x8008D370
		// Variables:
	// 		struct PhysObData *data; // $s0
	// 		int time; // $s2
	// 		int lastTime; // $s4
	// 		int timeBetween; // $s0
	// 		int birthTime; // $a0
	// 		struct Object *walboss; // $v0
	// 		struct _walbossAttributes *wa; // $s3
	/* end block 1 */
	// End offset: 0x8008D4C0
	// End Line: 168

	/* begin block 2 */
		// Start line: 228
	/* end block 2 */
	// End Line: 229

void WCBEGG_Process(_Instance *instance,GameTracker *gameTracker)

{
  ulong uVar1;
  Object *pOVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  pvVar3 = instance->extraData;
  uVar1 = MON_GetTime(instance);
  iVar6 = uVar1 - gameTrackerX.totalTime;
  pOVar2 = OBTABLE_FindObject("walboss_");
  if (pOVar2 == (Object *)0x0) {
    INSTANCE_KillInstance(instance);
  }
  else {
    iVar5 = *(int *)((int)pOVar2->data + 4);
    iVar4 = *(int *)((int)pvVar3 + 0x28) + (int)*(short *)(iVar5 + 0xe) * 0x21;
    if ((iVar6 < iVar4) && (iVar4 <= (int)uVar1)) {
      G2EmulationInstanceSwitchAnimationAlpha(instance,0,2,0,0,2,0);
    }
    iVar4 = iVar4 + (int)*(short *)(iVar5 + 0x10) * 0x21;
    if ((iVar6 < iVar4) && (iVar4 <= (int)uVar1)) {
      G2EmulationInstanceSwitchAnimationAlpha(instance,0,3,0,0,1,0);
    }
    if ((int)uVar1 < iVar4 + 0x339) {
      ProcessPhysicalObject(instance,gameTracker);
    }
    else {
      INSTANCE_KillInstance(instance);
      if (gameTrackerX.playerInstance == instance->LinkParent) {
        INSTANCE_Post(gameTrackerX.playerInstance,0x40005,(int)*(short *)(iVar5 + 0x12) * 0x21);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_ExplodeProcess(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 170, offset 0x8008d4e4
	/* begin block 1 */
		// Start line: 171
		// Start offset: 0x8008D4E4
		// Variables:
	// 		struct PhysObData *data; // $s0
	/* end block 1 */
	// End offset: 0x8008D530
	// End Line: 184

	/* begin block 2 */
		// Start line: 348
	/* end block 2 */
	// End Line: 349

void WCBEGG_ExplodeProcess(_Instance *instance,GameTracker *gameTracker)

{
  ulong uVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  uVar1 = MON_GetTime(instance);
  if (uVar1 < *(uint *)((int)pvVar2 + 0x44)) {
    G2EmulationInstancePlayAnimation(instance);
  }
  else {
    INSTANCE_KillInstance(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Collide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s4*/)
 // line 186, offset 0x8008d544
	/* begin block 1 */
		// Start line: 187
		// Start offset: 0x8008D544
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $a0
	// 		struct _HSphere *s1; // $v1
	// 		struct _Instance *inst1; // $s0
	// 		struct PhysObData *data; // $s1
	/* end block 1 */
	// End offset: 0x8008D65C
	// End Line: 233

	/* begin block 2 */
		// Start line: 380
	/* end block 2 */
	// End Line: 381

void WCBEGG_Collide(_Instance *instance,GameTracker *gameTracker)

{
  byte bVar1;
  ulong uVar2;
  void *pvVar3;
  _Instance *Inst;
  uint *puVar4;
  
  pvVar3 = instance->collideInfo;
  puVar4 = (uint *)instance->extraData;
  bVar1 = *(byte *)((int)pvVar3 + 7);
  if ((((bVar1 == 1) && (*(char *)(*(int *)((int)pvVar3 + 0xc) + 4) == '\b')) &&
      (Inst = *(_Instance **)((int)pvVar3 + 0x14), Inst != (_Instance *)0x0)) &&
     (uVar2 = INSTANCE_Query(Inst,1), uVar2 == 0x10102)) {
    if ((*puVar4 & 0x10000) == 0) {
      INSTANCE_KillInstance(instance);
    }
    else {
      INSTANCE_Post(Inst,0x1000017,2);
      G2EmulationInstanceSwitchAnimationAlpha(instance,0,4,0,0,(uint)bVar1,0);
      instance->processFunc = WCBEGG_ExplodeProcess;
      uVar2 = MON_GetTime(instance);
      puVar4[0x11] = uVar2 + 0x14a;
    }
    TurnOffCollisionPhysOb(instance,7);
  }
  else {
    CollidePhysicalObject(instance,gameTracker);
    *(undefined2 *)((int)puVar4 + 0x3e) = 0;
    *(undefined2 *)(puVar4 + 0xf) = 0;
    *(undefined2 *)((int)puVar4 + 0x3a) = 0;
    *(ushort *)((int)puVar4 + 0x36) = *(ushort *)((int)puVar4 + 0x36) & 0xfffe;
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WALBOSC_AnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s1*/, long messageDataB /*stack 16*/, struct _Instance *instance /*stack 20*/)
 // line 238, offset 0x8008d67c
	/* begin block 1 */
		// Start line: 499
	/* end block 1 */
	// End Line: 500

long WALBOSC_AnimCallback
               (_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,long messageDataA,
               long messageDataB,_Instance *instance)

{
  if (message == G2ANIM_MSG_DONE) {
    COLLIDE_SegmentCollisionOff(instance,1);
    FX_StopInstanceBurrow(instance);
    instance->flags = instance->flags | 0x800;
    instance->flags2 = instance->flags2 | 0x20000000;
  }
  else {
    INSTANCE_DefaultAnimCallback(anim,sectionID,message,messageDataA,messageDataB,instance);
  }
  return messageDataA;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WALBOSC_Collide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 259, offset 0x8008d700
	/* begin block 1 */
		// Start line: 260
		// Start offset: 0x8008D700
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s0
	// 		struct _HSphere *s1; // $v0
	// 		struct _Instance *inst1; // $s3

		/* begin block 1.1 */
			// Start line: 268
			// Start offset: 0x8008D73C
			// Variables:
		// 		struct PhysObWeaponProperties *Prop; // $s1
		/* end block 1.1 */
		// End offset: 0x8008D7A4
		// End Line: 283
	/* end block 1 */
	// End offset: 0x8008D7A4
	// End Line: 284

	/* begin block 2 */
		// Start line: 541
	/* end block 2 */
	// End Line: 542

void WALBOSC_Collide(_Instance *instance,GameTracker *gameTracker)

{
  int Data;
  void *pvVar1;
  void *pvVar2;
  _Instance *Inst;
  
  pvVar1 = instance->collideInfo;
  Inst = *(_Instance **)((int)pvVar1 + 0x14);
  if (*(char *)(*(int *)((int)pvVar1 + 0xc) + 4) == '\b') {
    pvVar2 = instance->data;
    COLLIDE_SegmentCollisionOff(instance,1);
    Data = *(int *)((int)pvVar2 + 8);
    if (Data < 0) {
      Data = Data + 0x7f;
    }
    Data = SetFXHitData(instance,(uint)*(byte *)((int)pvVar1 + 5),Data >> 7,0x100);
    INSTANCE_Post(Inst,0x400000,Data);
    Data = SetMonsterHitData(instance,(_Instance *)0x0,*(int *)((int)pvVar2 + 8),
                             (int)*(short *)((int)pvVar2 + 0x10),(int)*(char *)((int)pvVar2 + 0x12))
    ;
    INSTANCE_Post(Inst,0x1000000,Data);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WALBOSC_Message(struct _Instance *instance /*$s0*/, unsigned long message /*$a1*/, unsigned long data /*$a2*/)
 // line 286, offset 0x8008d7c0
	/* begin block 1 */
		// Start line: 597
	/* end block 1 */
	// End Line: 598

void WALBOSC_Message(_Instance *instance,ulong message,ulong data)

{
  if ((message == 0x1000017) && (data == 0)) {
    COLLIDE_SegmentCollisionOff(instance,1);
    instance->flags2 = instance->flags2 | 0x20000000;
  }
  return;
}





