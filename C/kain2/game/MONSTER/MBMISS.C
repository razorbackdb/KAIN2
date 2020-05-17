#include "THISDUST.H"
#include "MBMISS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Message(struct _Instance *instance /*$s1*/, unsigned long message /*$s2*/, unsigned long data /*$s3*/)
 // line 126, offset 0x8008f0e8
	/* begin block 1 */
		// Start line: 127
		// Start offset: 0x8008F0E8

		/* begin block 1.1 */
			// Start line: 132
			// Start offset: 0x8008F12C
			// Variables:
		// 		struct PhysObData *pod; // $s0
		/* end block 1.1 */
		// End offset: 0x8008F160
		// End Line: 137
	/* end block 1 */
	// End offset: 0x8008F170
	// End Line: 142

	/* begin block 2 */
		// Start line: 252
	/* end block 2 */
	// End Line: 253

void WCBEGG_Message(_Instance *instance,ulong message,ulong data)

{
  ulong uVar1;
  void *pvVar2;
  
  if (message == 0x800002) {
    if (instance->processFunc != WCBEGG_Process) {
      return;
    }
    pvVar2 = instance->extraData;
    uVar1 = MON_GetTime(instance);
    *(ulong *)((int)pvVar2 + 0x28) = uVar1;
    G2EmulationInstanceSwitchAnimationAlpha(instance,0,1,0,0,2,0);
  }
  PhysicalObjectPost(instance,message,data);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ WCBEGG_ShouldIgniteEgg(struct _Instance *egg /*$s1*/, struct _walbossAttributes *wa /*$s2*/)
 // line 144, offset 0x8008f18c
	/* begin block 1 */
		// Start line: 145
		// Start offset: 0x8008F18C
		// Variables:
	// 		struct _InstanceList *instanceList; // $s0
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8008F26C
	// End Line: 176

	/* begin block 2 */
		// Start line: 290
	/* end block 2 */
	// End Line: 291

int WCBEGG_ShouldIgniteEgg(_Instance *egg,_walbossAttributes *wa)

{
  _InstanceList *p_Var1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  _Instance *Inst;
  
  p_Var1 = gameTrackerX.instanceList;
  uVar2 = INSTANCE_Query(egg,3);
  if ((uVar2 & 0x10000) == 0) {
    Inst = p_Var1->first;
    while (Inst != (_Instance *)0x0) {
      uVar2 = INSTANCE_Query(Inst,1);
      if (((uVar2 & 0x20) != 0) &&
         (lVar3 = MATH3D_LengthXYZ((int)(Inst->position).x - (int)(egg->position).x,
                                   (int)(Inst->position).y - (int)(egg->position).y,
                                   (int)(Inst->position).z - (int)(egg->position).z),
         lVar3 < wa->eggIgniteDist)) {
        uVar2 = INSTANCE_Query(Inst,3);
        if ((uVar2 & 0x10000) != 0) {
          return 1;
        }
        iVar4 = strcmpi(Inst->object->name,"walfire_");
        if (iVar4 == 0) {
          return 1;
        }
      }
      Inst = Inst->next;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Process(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$s6*/)
 // line 178, offset 0x8008f284
	/* begin block 1 */
		// Start line: 179
		// Start offset: 0x8008F284
		// Variables:
	// 		struct PhysObData *data; // $s5
	// 		int time; // $s2
	// 		int lastTime; // $s4
	// 		int timeBetween; // $s0
	// 		int birthTime; // $a0
	// 		struct Object *walboss; // $v0
	// 		struct _walbossAttributes *wa; // $s3
	/* end block 1 */
	// End offset: 0x8008F450
	// End Line: 239

	/* begin block 2 */
		// Start line: 371
	/* end block 2 */
	// End Line: 372

void WCBEGG_Process(_Instance *instance,GameTracker *gameTracker)

{
  ulong uVar1;
  Object *pOVar2;
  code *pcVar3;
  int iVar4;
  _walbossAttributes *wa;
  int iVar5;
  void *pvVar6;
  
  pvVar6 = instance->extraData;
  uVar1 = MON_GetTime(instance);
  iVar5 = uVar1 - gameTrackerX.lastLoopTime;
  if ((instance->collideFunc == WCBEGG_Collide) &&
     (instance->LinkParent == gameTrackerX.playerInstance)) {
    instance->collideFunc = WCBEGG_ExplodeCollide;
  }
  pOVar2 = OBTABLE_FindObject("walboss_");
  if (pOVar2 == (Object *)0x0) {
    INSTANCE_UnlinkFromParent(instance);
    INSTANCE_KillInstance(instance);
  }
  else {
    wa = *(_walbossAttributes **)((int)pOVar2->data + 4);
    iVar4 = *(int *)((int)pvVar6 + 0x28) + (int)wa->timeToEggThrob * 0x21;
    if ((iVar5 < iVar4) && (iVar4 <= (int)uVar1)) {
      G2EmulationInstanceSwitchAnimationAlpha(instance,0,2,0,0,2,0);
    }
    iVar4 = iVar4 + (int)wa->timeToEggExplode * 0x21;
    if ((iVar5 < iVar4) && (iVar4 <= (int)uVar1)) {
      uVar1 = INSTANCE_Query(instance,3);
      if ((uVar1 & 0x10000) == 0) {
        G2EmulationInstanceSwitchAnimationAlpha(instance,0,3,0,0,1,0);
        pcVar3 = WCBEGG_SplitProcess;
      }
      else {
        G2EmulationInstanceSwitchAnimationAlpha(instance,0,4,0,0,1,0);
        pcVar3 = WCBEGG_ExplodeProcess;
      }
      instance->processFunc = pcVar3;
      uVar1 = MON_GetTime(instance);
      *(ulong *)((int)pvVar6 + 0x28) = uVar1;
    }
    iVar5 = WCBEGG_ShouldIgniteEgg(instance,wa);
    if (iVar5 != 0) {
      INSTANCE_Post(instance,0x800029,1);
    }
    ProcessPhysicalObject(instance,gameTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_ExplodeProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s3*/)
 // line 241, offset 0x8008f478
	/* begin block 1 */
		// Start line: 242
		// Start offset: 0x8008F478
		// Variables:
	// 		struct PhysObData *data; // $s1
	// 		int currentTime; // $s2
	// 		int time; // $v0
	// 		struct Object *walboss; // $v1
	// 		struct _walbossAttributes *wa; // $v1
	/* end block 1 */
	// End offset: 0x8008F59C
	// End Line: 289

	/* begin block 2 */
		// Start line: 506
	/* end block 2 */
	// End Line: 507

void WCBEGG_ExplodeProcess(_Instance *instance,GameTracker *gameTracker)

{
  ulong uVar1;
  Object *pOVar2;
  code *pcVar3;
  uint *puVar4;
  
  puVar4 = (uint *)instance->extraData;
  uVar1 = MON_GetTime(instance);
  if ((instance->collideFunc == WCBEGG_Collide) &&
     (instance->LinkParent == gameTrackerX.playerInstance)) {
    instance->collideFunc = WCBEGG_ExplodeCollide;
  }
  pOVar2 = OBTABLE_FindObject("walboss_");
  if (pOVar2 == (Object *)0x0) {
    INSTANCE_UnlinkFromParent(instance);
    INSTANCE_KillInstance(instance);
  }
  else {
    if ((int)(puVar4[10] + 0x14a) <= (int)uVar1) {
      if (gameTrackerX.playerInstance == instance->LinkParent) {
        INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00040005,
                      (int)*(short *)(*(int *)((int)pOVar2->data + 4) + 0x12) * 0x21);
        INSTANCE_UnlinkFromParent(instance);
        *puVar4 = *puVar4 & 0xffffbfff | 0x1001;
        pcVar3 = WCBEGG_CommonPostProcess;
      }
      else {
        pcVar3 = WCBEGG_CommonPostProcess2;
      }
      instance->processFunc = pcVar3;
      INSTANCE_Post(instance,0x800029,0);
    }
    ProcessPhysicalObject(instance,gameTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_SplitProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s3*/)
 // line 291, offset 0x8008f5b8
	/* begin block 1 */
		// Start line: 292
		// Start offset: 0x8008F5B8
		// Variables:
	// 		struct PhysObData *data; // $s1
	// 		int currentTime; // $s2
	// 		int time; // $v0
	// 		struct Object *walboss; // $v1
	// 		struct _walbossAttributes *wa; // $v1
	/* end block 1 */
	// End offset: 0x8008F698
	// End Line: 333

	/* begin block 2 */
		// Start line: 610
	/* end block 2 */
	// End Line: 611

void WCBEGG_SplitProcess(_Instance *instance,GameTracker *gameTracker)

{
  ulong uVar1;
  Object *pOVar2;
  code *pcVar3;
  uint *puVar4;
  
  puVar4 = (uint *)instance->extraData;
  uVar1 = MON_GetTime(instance);
  pOVar2 = OBTABLE_FindObject("walboss_");
  if (pOVar2 == (Object *)0x0) {
    INSTANCE_UnlinkFromParent(instance);
    INSTANCE_KillInstance(instance);
  }
  else {
    if ((int)(puVar4[10] + 0xc6) <= (int)uVar1) {
      if (gameTrackerX.playerInstance == instance->LinkParent) {
        INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00040005,
                      (int)*(short *)(*(int *)((int)pOVar2->data + 4) + 0x12) * 0x21);
        INSTANCE_UnlinkFromParent(instance);
        *puVar4 = *puVar4 & 0xffffbfff | 0x1001;
        pcVar3 = WCBEGG_CommonPostProcess;
      }
      else {
        pcVar3 = WCBEGG_CommonPostProcess2;
      }
      instance->processFunc = pcVar3;
    }
    ProcessPhysicalObject(instance,gameTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_CommonPostProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s2*/)
 // line 335, offset 0x8008f6b4
	/* begin block 1 */
		// Start line: 336
		// Start offset: 0x8008F6B4
		// Variables:
	// 		struct PhysObData *data; // $s1
	/* end block 1 */
	// End offset: 0x8008F6B4
	// End Line: 336

	/* begin block 2 */
		// Start line: 702
	/* end block 2 */
	// End Line: 703

void WCBEGG_CommonPostProcess(_Instance *instance,GameTracker *gameTracker)

{
  int Data;
  ulong uVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  Data = SetActionPlayHostAnimationData(gameTrackerX.playerInstance,instance,6,0,0,2);
  INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00040003,Data);
  instance->processFunc = WCBEGG_CommonPostProcess2;
  uVar1 = MON_GetTime(instance);
  *(ulong *)((int)pvVar2 + 0x28) = uVar1;
  ProcessPhysicalObject(instance,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_CommonPostProcess2(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$s2*/)
 // line 348, offset 0x8008f744
	/* begin block 1 */
		// Start line: 349
		// Start offset: 0x8008F744
		// Variables:
	// 		struct PhysObData *data; // $s0
	// 		int time; // $v1
	/* end block 1 */
	// End offset: 0x8008F7A0
	// End Line: 366

	/* begin block 2 */
		// Start line: 732
	/* end block 2 */
	// End Line: 733

void WCBEGG_CommonPostProcess2(_Instance *instance,GameTracker *gameTracker)

{
  ulong uVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  uVar1 = MON_GetTime(instance);
  if ((int)uVar1 < *(int *)((int)pvVar2 + 0x28) + 0xf78) {
    ProcessPhysicalObject(instance,gameTracker);
  }
  else {
    INSTANCE_UnlinkFromParent(instance);
    INSTANCE_KillInstance(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_ExplodeCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s4*/)
 // line 368, offset 0x8008f7b8
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x8008F7B8
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $a0
	// 		struct _HSphere *s1; // $v1
	// 		struct _Instance *inst1; // $s0
	// 		struct PhysObData *data; // $s1
	/* end block 1 */
	// End offset: 0x8008F91C
	// End Line: 425

	/* begin block 2 */
		// Start line: 772
	/* end block 2 */
	// End Line: 773

void WCBEGG_ExplodeCollide(_Instance *instance,GameTracker *gameTracker)

{
  byte bVar1;
  undefined *puVar2;
  code *pcVar3;
  ulong uVar4;
  void *pvVar5;
  _Instance *Inst;
  uint *puVar6;
  
  pvVar5 = instance->collideInfo;
  puVar6 = (uint *)instance->extraData;
  bVar1 = *(byte *)((int)pvVar5 + 7);
  if ((((bVar1 == 1) && (*(char *)(*(int *)((int)pvVar5 + 0xc) + 4) == '\b')) &&
      (Inst = *(_Instance **)((int)pvVar5 + 0x14), Inst != (_Instance *)0x0)) &&
     (puVar2 = (undefined *)INSTANCE_Query(Inst,1), puVar2 == &UNK_00010102)) {
    if (instance->LinkParent == (_Instance *)0x0) {
      if ((*puVar6 & 0x10000) == 0) {
        G2EmulationInstanceSwitchAnimationAlpha(instance,0,3,0,0,(uint)bVar1,0);
        pcVar3 = WCBEGG_SplitProcess;
      }
      else {
        INSTANCE_Post(Inst,0x1000017,2);
        G2EmulationInstanceSwitchAnimationAlpha(instance,0,4,0,0,(uint)bVar1,0);
        pcVar3 = WCBEGG_ExplodeProcess;
      }
      instance->processFunc = pcVar3;
      *puVar6 = *puVar6 & 0xffffbfff | 0x1001;
      instance->zVel = 0;
      instance->yVel = 0;
      instance->xVel = 0;
      uVar4 = MON_GetTime(instance);
      puVar6[10] = uVar4;
    }
    TurnOffCollisionPhysOb(instance,7);
  }
  else {
    CollidePhysicalObject(instance,gameTracker);
    *(undefined2 *)((int)puVar6 + 0x3e) = 0;
    *(undefined2 *)(puVar6 + 0xf) = 0;
    *(undefined2 *)((int)puVar6 + 0x3a) = 0;
    *(ushort *)((int)puVar6 + 0x36) = *(ushort *)((int)puVar6 + 0x36) & 0xfffe;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Collide(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s1*/)
 // line 427, offset 0x8008f93c
	/* begin block 1 */
		// Start line: 428
		// Start offset: 0x8008F93C
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $a0

		/* begin block 1.1 */
			// Start line: 433
			// Start offset: 0x8008F968
			// Variables:
		// 		struct _Instance *inst1; // $v0
		/* end block 1.1 */
		// End offset: 0x8008F98C
		// End Line: 439
	/* end block 1 */
	// End offset: 0x8008F9B0
	// End Line: 445

	/* begin block 2 */
		// Start line: 908
	/* end block 2 */
	// End Line: 909

void WCBEGG_Collide(_Instance *instance,GameTracker *gameTracker)

{
  int iVar1;
  
  if ((*(char *)((int)instance->collideInfo + 7) != '\x01') ||
     (iVar1 = strcmpi(*(char **)(*(int *)(*(int *)((int)instance->collideInfo + 0x14) + 0x1c) + 0x24
                                ),"walboss_"), iVar1 != 0)) {
    TurnOffCollisionPhysOb(instance,7);
    instance->collideFunc = WCBEGG_ExplodeCollide;
  }
  CollidePhysicalObject(instance,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WALBOSC_AnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s1*/, long messageDataB /*stack 16*/, struct _Instance *instance /*stack 20*/)
 // line 450, offset 0x8008f9c4
	/* begin block 1 */
		// Start line: 955
	/* end block 1 */
	// End Line: 956

long WALBOSC_AnimCallback
               (_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,long messageDataA,
               long messageDataB,_Instance *instance)

{
  uint uVar1;
  
  if (message == G2ANIM_MSG_DONE) {
    COLLIDE_SegmentCollisionOff(instance,1);
    instance->flags = instance->flags | 0x800;
    uVar1 = instance->flags2;
    (instance->halvePlane).flags = 0;
    instance->flags2 = uVar1 | 0x20000000;
  }
  else {
    INSTANCE_DefaultAnimCallback(anim,sectionID,message,messageDataA,messageDataB,instance);
  }
  return messageDataA;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WALBOSC_Collide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 471, offset 0x8008fa44
	/* begin block 1 */
		// Start line: 472
		// Start offset: 0x8008FA44
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s0
	// 		struct _HSphere *s1; // $v0
	// 		struct _Instance *inst1; // $s3

		/* begin block 1.1 */
			// Start line: 480
			// Start offset: 0x8008FA80
			// Variables:
		// 		struct PhysObWeaponProperties *Prop; // $s1
		/* end block 1.1 */
		// End offset: 0x8008FAE8
		// End Line: 495
	/* end block 1 */
	// End offset: 0x8008FAE8
	// End Line: 496

	/* begin block 2 */
		// Start line: 1000
	/* end block 2 */
	// End Line: 1001

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
 // line 498, offset 0x8008fb04
	/* begin block 1 */
		// Start line: 1056
	/* end block 1 */
	// End Line: 1057

void WALBOSC_Message(_Instance *instance,ulong message,ulong data)

{
  if ((message == 0x1000017) && (data == 0)) {
    COLLIDE_SegmentCollisionOff(instance,1);
    instance->flags2 = instance->flags2 | 0x20000000;
  }
  return;
}





