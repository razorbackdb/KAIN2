#include "THISDUST.H"
#include "MBMISS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Message(struct _Instance *instance /*$s1*/, unsigned long message /*$s2*/, unsigned long data /*$s3*/)
 // line 116, offset 0x8008ebfc
	/* begin block 1 */
		// Start line: 117
		// Start offset: 0x8008EBFC

		/* begin block 1.1 */
			// Start line: 120
			// Start offset: 0x8008EC2C
			// Variables:
		// 		struct PhysObData *pod; // $s0
		/* end block 1.1 */
		// End offset: 0x8008EC60
		// End Line: 125
	/* end block 1 */
	// End offset: 0x8008EC60
	// End Line: 127

	/* begin block 2 */
		// Start line: 232
	/* end block 2 */
	// End Line: 233

void WCBEGG_Message(_Instance *instance,u_long message,u_long data)

{
  u_long uVar1;
  void *pvVar2;
  
  if (message == 0x800002) {
    pvVar2 = instance->extraData;
    uVar1 = MON_GetTime(instance);
    *(u_long *)((int)pvVar2 + 0x28) = uVar1;
    G2EmulationInstanceSwitchAnimationAlpha(instance,0,1,0,0,2,0);
  }
  PhysicalObjectPost(instance,message,data);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ WCBEGG_ShouldIgniteEgg(struct _Instance *egg /*$s1*/, struct _walbossAttributes *wa /*$s2*/)
 // line 130, offset 0x8008ec8c
	/* begin block 1 */
		// Start line: 131
		// Start offset: 0x8008EC8C
		// Variables:
	// 		struct _InstanceList *instanceList; // $s0
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8008ED54
	// End Line: 157

	/* begin block 2 */
		// Start line: 262
	/* end block 2 */
	// End Line: 263

int WCBEGG_ShouldIgniteEgg(_Instance *egg,_walbossAttributes *wa)

{
  _InstanceList *p_Var1;
  u_long uVar2;
  long lVar3;
  int iVar4;
  _Instance *Inst;
  
  p_Var1 = gameTrackerX.instanceList;
  uVar2 = INSTANCE_Query(egg,3);
  if ((uVar2 & 0x10000) == 0) {
    Inst = p_Var1->first;
    while (Inst != (_Instance *)0x0) {
      uVar2 = INSTANCE_Query(Inst,1);
      if ((((uVar2 & 0x20) != 0) &&
          (lVar3 = MATH3D_LengthXYZ((int)(Inst->position).x - (int)(egg->position).x,
                                    (int)(Inst->position).y - (int)(egg->position).y,
                                    (int)(Inst->position).z - (int)(egg->position).z),
          lVar3 < wa->eggIgniteDist)) &&
         (iVar4 = strcmpi(Inst->object->name,"walfire_"), iVar4 == 0)) {
        return 1;
      }
      Inst = Inst->next;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Process(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$s5*/)
 // line 159, offset 0x8008ed6c
	/* begin block 1 */
		// Start line: 160
		// Start offset: 0x8008ED6C
		// Variables:
	// 		struct PhysObData *data; // $s0
	// 		int time; // $s3
	// 		int lastTime; // $s2
	// 		int timeBetween; // $s0
	// 		int birthTime; // $a0
	// 		struct Object *walboss; // $v0
	// 		struct _walbossAttributes *wa; // $s4
	/* end block 1 */
	// End offset: 0x8008EF0C
	// End Line: 226

	/* begin block 2 */
		// Start line: 328
	/* end block 2 */
	// End Line: 329

void WCBEGG_Process(_Instance *instance,GameTracker *gameTracker)

{
  u_long uVar1;
  Object *pOVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  _walbossAttributes *wa;
  
  pvVar3 = instance->extraData;
  uVar1 = MON_GetTime(instance);
  iVar5 = uVar1 - gameTrackerX.lastLoopTime;
  pOVar2 = OBTABLE_FindObject("walboss_");
  if (pOVar2 != (Object *)0x0) {
    wa = *(_walbossAttributes **)((int)pOVar2->data + 4);
    iVar4 = *(int *)((int)pvVar3 + 0x28) + (int)wa->timeToEggThrob * 0x21;
    if ((iVar5 < iVar4) && (iVar4 <= (int)uVar1)) {
      G2EmulationInstanceSwitchAnimationAlpha(instance,0,2,0,0,2,0);
    }
    iVar4 = iVar4 + (int)wa->timeToEggExplode * 0x21;
    if ((iVar5 < iVar4) && (iVar4 <= (int)uVar1)) {
      G2EmulationInstanceSwitchAnimationAlpha(instance,0,3,0,0,1,0);
    }
    if ((iVar5 < iVar4 + 0x35a) && (iVar4 + 0x35a <= (int)uVar1)) {
      if (gameTrackerX.playerInstance == instance->LinkParent) {
        INSTANCE_Post(gameTrackerX.playerInstance,0x40005,(int)wa->razielStunTime * 0x21);
      }
      G2EmulationInstanceSwitchAnimationAlpha(instance,0,5,0,0,1,0);
    }
    if ((int)uVar1 < iVar4 + 0xef4) {
      iVar5 = WCBEGG_ShouldIgniteEgg(instance,wa);
      if (iVar5 != 0) {
        INSTANCE_Post(instance,0x800029,1);
      }
      ProcessPhysicalObject(instance,gameTracker);
      return;
    }
  }
  INSTANCE_KillInstance(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_ExplodeProcess(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 228, offset 0x8008ef30
	/* begin block 1 */
		// Start line: 229
		// Start offset: 0x8008EF30
		// Variables:
	// 		struct PhysObData *data; // $s0
	// 		int time; // $s1
	// 		int lastTime; // $v1
	// 		int birthTime; // $v1
	// 		int timeBetween; // $s0
	/* end block 1 */
	// End offset: 0x8008EFC8
	// End Line: 254

	/* begin block 2 */
		// Start line: 474
	/* end block 2 */
	// End Line: 475

void WCBEGG_ExplodeProcess(_Instance *instance,GameTracker *gameTracker)

{
  u_long uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  
  pvVar3 = instance->extraData;
  uVar1 = MON_GetTime(instance);
  iVar2 = *(int *)((int)pvVar3 + 0x28);
  iVar4 = iVar2 + 0x14a;
  if (((int)(uVar1 - gameTrackerX.lastLoopTime) < iVar4) && (iVar4 <= (int)uVar1)) {
    G2EmulationInstanceSwitchAnimationAlpha(instance,0,5,0,0,1,0);
  }
  if ((int)uVar1 < iVar2 + 0xce4) {
    G2EmulationInstancePlayAnimation(instance);
  }
  else {
    INSTANCE_KillInstance(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_ExplodeCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s4*/)
 // line 256, offset 0x8008efe0
	/* begin block 1 */
		// Start line: 257
		// Start offset: 0x8008EFE0
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $a0
	// 		struct _HSphere *s1; // $v1
	// 		struct _Instance *inst1; // $s0
	// 		struct PhysObData *data; // $s1
	/* end block 1 */
	// End offset: 0x8008F0F8
	// End Line: 298

	/* begin block 2 */
		// Start line: 533
	/* end block 2 */
	// End Line: 534

void WCBEGG_ExplodeCollide(_Instance *instance,GameTracker *gameTracker)

{
  byte bVar1;
  u_long uVar2;
  void *pvVar3;
  _Instance *Inst;
  u_int *puVar4;
  
  pvVar3 = instance->collideInfo;
  puVar4 = (u_int *)instance->extraData;
  bVar1 = *(byte *)((int)pvVar3 + 7);
  if ((((bVar1 == 1) && (*(char *)(*(int *)((int)pvVar3 + 0xc) + 4) == '\b')) &&
      (Inst = *(_Instance **)((int)pvVar3 + 0x14), Inst != (_Instance *)0x0)) &&
     (uVar2 = INSTANCE_Query(Inst,1), uVar2 == 0x10102)) {
    if (((*puVar4 & 0x10000) != 0) && (instance->LinkParent == (_Instance *)0x0)) {
      INSTANCE_Post(Inst,0x1000017,2);
      G2EmulationInstanceSwitchAnimationAlpha(instance,0,4,0,0,(u_int)bVar1,0);
      instance->processFunc = WCBEGG_ExplodeProcess;
      uVar2 = MON_GetTime(instance);
      puVar4[10] = uVar2;
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
// void /*$ra*/ WCBEGG_Collide(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s1*/)
 // line 300, offset 0x8008f118
	/* begin block 1 */
		// Start line: 301
		// Start offset: 0x8008F118
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $v0
	/* end block 1 */
	// End offset: 0x8008F158
	// End Line: 313

	/* begin block 2 */
		// Start line: 636
	/* end block 2 */
	// End Line: 637

void WCBEGG_Collide(_Instance *instance,GameTracker *gameTracker)

{
  if (*(char *)((int)instance->collideInfo + 7) == '\x03') {
    TurnOffCollisionPhysOb(instance,7);
    instance->collideFunc = WCBEGG_ExplodeCollide;
  }
  CollidePhysicalObject(instance,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WALBOSC_AnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s1*/, long messageDataB /*stack 16*/, struct _Instance *instance /*stack 20*/)
 // line 319, offset 0x8008f178
	/* begin block 1 */
		// Start line: 675
	/* end block 1 */
	// End Line: 676

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
 // line 340, offset 0x8008f1fc
	/* begin block 1 */
		// Start line: 341
		// Start offset: 0x8008F1FC
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s0
	// 		struct _HSphere *s1; // $v0
	// 		struct _Instance *inst1; // $s3

		/* begin block 1.1 */
			// Start line: 349
			// Start offset: 0x8008F238
			// Variables:
		// 		struct PhysObWeaponProperties *Prop; // $s1
		/* end block 1.1 */
		// End offset: 0x8008F2A0
		// End Line: 364
	/* end block 1 */
	// End offset: 0x8008F2A0
	// End Line: 365

	/* begin block 2 */
		// Start line: 717
	/* end block 2 */
	// End Line: 718

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
    Data = SetFXHitData(instance,(u_int)*(byte *)((int)pvVar1 + 5),Data >> 7,0x100);
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
 // line 367, offset 0x8008f2bc
	/* begin block 1 */
		// Start line: 773
	/* end block 1 */
	// End Line: 774

void WALBOSC_Message(_Instance *instance,u_long message,u_long data)

{
  if ((message == 0x1000017) && (data == 0)) {
    COLLIDE_SegmentCollisionOff(instance,1);
    instance->flags2 = instance->flags2 | 0x20000000;
  }
  return;
}





