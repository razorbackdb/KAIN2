#include "THISDUST.H"
#include "MBMISS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Message(struct _Instance *instance /*$s1*/, unsigned long message /*$s2*/, unsigned long data /*$s3*/)
 // line 126, offset 0x8008efa8
	/* begin block 1 */
		// Start line: 127
		// Start offset: 0x8008EFA8

		/* begin block 1.1 */
			// Start line: 132
			// Start offset: 0x8008EFEC
			// Variables:
		// 		struct PhysObData *pod; // $s0
		/* end block 1.1 */
		// End offset: 0x8008F020
		// End Line: 137
	/* end block 1 */
	// End offset: 0x8008F030
	// End Line: 142

	/* begin block 2 */
		// Start line: 252
	/* end block 2 */
	// End Line: 253

void WCBEGG_Message(_Instance *instance,ulong message,ulong data)

{
  if (message == 0x800002) {
    if (instance->processFunc == WCBEGG_Process) {
                    /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
  }
  else {
    PhysicalObjectPost(instance,message,data);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ WCBEGG_ShouldIgniteEgg(struct _Instance *egg /*$s1*/, struct _walbossAttributes *wa /*$s2*/)
 // line 144, offset 0x8008f04c
	/* begin block 1 */
		// Start line: 145
		// Start offset: 0x8008F04C
		// Variables:
	// 		struct _InstanceList *instanceList; // $s0
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x8008F12C
	// End Line: 176

	/* begin block 2 */
		// Start line: 290
	/* end block 2 */
	// End Line: 291

int WCBEGG_ShouldIgniteEgg(_Instance *egg,_walbossAttributes *wa)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(egg,3);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Process(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$s6*/)
 // line 178, offset 0x8008f144
	/* begin block 1 */
		// Start line: 179
		// Start offset: 0x8008F144
		// Variables:
	// 		struct PhysObData *data; // $s5
	// 		int time; // $s2
	// 		int lastTime; // $s4
	// 		int timeBetween; // $s0
	// 		int birthTime; // $a0
	// 		struct Object *walboss; // $v0
	// 		struct _walbossAttributes *wa; // $s3
	/* end block 1 */
	// End offset: 0x8008F310
	// End Line: 239

	/* begin block 2 */
		// Start line: 371
	/* end block 2 */
	// End Line: 372

void WCBEGG_Process(_Instance *instance,GameTracker *gameTracker)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_ExplodeProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s3*/)
 // line 241, offset 0x8008f338
	/* begin block 1 */
		// Start line: 242
		// Start offset: 0x8008F338
		// Variables:
	// 		struct PhysObData *data; // $s1
	// 		int currentTime; // $s2
	// 		int time; // $v0
	// 		struct Object *walboss; // $v1
	// 		struct _walbossAttributes *wa; // $v1
	/* end block 1 */
	// End offset: 0x8008F45C
	// End Line: 289

	/* begin block 2 */
		// Start line: 506
	/* end block 2 */
	// End Line: 507

void WCBEGG_ExplodeProcess(_Instance *instance,GameTracker *gameTracker)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_SplitProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s3*/)
 // line 291, offset 0x8008f478
	/* begin block 1 */
		// Start line: 292
		// Start offset: 0x8008F478
		// Variables:
	// 		struct PhysObData *data; // $s1
	// 		int currentTime; // $s2
	// 		int time; // $v0
	// 		struct Object *walboss; // $v1
	// 		struct _walbossAttributes *wa; // $v1
	/* end block 1 */
	// End offset: 0x8008F558
	// End Line: 333

	/* begin block 2 */
		// Start line: 610
	/* end block 2 */
	// End Line: 611

_G2Bool_Enum G2Anim_IsSegmentEnabled(_G2Anim_Type *anim,int segmentID)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime((_Instance *)anim);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_CommonPostProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s2*/)
 // line 335, offset 0x8008f574
	/* begin block 1 */
		// Start line: 336
		// Start offset: 0x8008F574
		// Variables:
	// 		struct PhysObData *data; // $s1
	/* end block 1 */
	// End offset: 0x8008F574
	// End Line: 336

	/* begin block 2 */
		// Start line: 702
	/* end block 2 */
	// End Line: 703

void WCBEGG_CommonPostProcess(_Instance *param_1)

{
  int Data;
  
  Data = SetActionPlayHostAnimationData(p_Gpffffb524,param_1,6,0,0,2);
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(p_Gpffffb524,(int)&DAT_00040003,Data);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_CommonPostProcess2(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$s2*/)
 // line 348, offset 0x8008f604
	/* begin block 1 */
		// Start line: 349
		// Start offset: 0x8008F604
		// Variables:
	// 		struct PhysObData *data; // $s0
	// 		int time; // $v1
	/* end block 1 */
	// End offset: 0x8008F660
	// End Line: 366

	/* begin block 2 */
		// Start line: 732
	/* end block 2 */
	// End Line: 733

void WCBEGG_CommonPostProcess2(_Instance *param_1)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(param_1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_ExplodeCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s4*/)
 // line 368, offset 0x8008f678
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x8008F678
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $a0
	// 		struct _HSphere *s1; // $v1
	// 		struct _Instance *inst1; // $s0
	// 		struct PhysObData *data; // $s1
	/* end block 1 */
	// End offset: 0x8008F7DC
	// End Line: 425

	/* begin block 2 */
		// Start line: 772
	/* end block 2 */
	// End Line: 773

void WCBEGG_ExplodeCollide(_Instance *instance,GameTracker *gameTracker)

{
  _Instance *instance_00;
  
  instance_00 = (_Instance *)instance->collideInfo;
  if (*(char *)((int)&(instance_00->node).next + 3) != '\x01') {
    WCBEGG_ExplodeCollide(instance_00,gameTracker);
    return;
  }
  if (*(char *)&(instance_00->prev->node).next != '\b') {
    WCBEGG_ExplodeCollide(instance_00,gameTracker);
    return;
  }
  if ((_Instance *)instance_00->flags == (_Instance *)0x0) {
    WCBEGG_ExplodeCollide((_Instance *)0x0,gameTracker);
    return;
  }
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query((_Instance *)instance_00->flags,1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ WCBEGG_Collide(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s1*/)
 // line 427, offset 0x8008f7fc
	/* begin block 1 */
		// Start line: 428
		// Start offset: 0x8008F7FC
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $a0

		/* begin block 1.1 */
			// Start line: 433
			// Start offset: 0x8008F828
			// Variables:
		// 		struct _Instance *inst1; // $v0
		/* end block 1.1 */
		// End offset: 0x8008F84C
		// End Line: 439
	/* end block 1 */
	// End offset: 0x8008F870
	// End Line: 445

	/* begin block 2 */
		// Start line: 908
	/* end block 2 */
	// End Line: 909

void WCBEGG_Collide(_Instance *instance,GameTracker *gameTracker)

{
  if (*(char *)((int)instance->collideInfo + 7) == '\x01') {
                    /* WARNING: Subroutine does not return */
    strcmpi(*(char **)(*(int *)(*(int *)((int)instance->collideInfo + 0x14) + 0x1c) + 0x24),
            s_walboss__800cf740);
  }
  TurnOffCollisionPhysOb(instance,7);
  instance->collideFunc = WCBEGG_ExplodeCollide;
  CollidePhysicalObject(instance,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ WALBOSC_AnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s1*/, long messageDataB /*stack 16*/, struct _Instance *instance /*stack 20*/)
 // line 450, offset 0x8008f884
	/* begin block 1 */
		// Start line: 955
	/* end block 1 */
	// End Line: 956

long WALBOSC_AnimCallback
               (_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,long messageDataA,
               long messageDataB,_Instance *instance)

{
  if (message == G2ANIM_MSG_DONE) {
                    /* WARNING: Subroutine does not return */
    COLLIDE_SegmentCollisionOff(instance,1);
  }
  INSTANCE_DefaultAnimCallback(anim,sectionID,message,messageDataA,messageDataB,instance);
  return messageDataA;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WALBOSC_Collide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 471, offset 0x8008f904
	/* begin block 1 */
		// Start line: 472
		// Start offset: 0x8008F904
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s0
	// 		struct _HSphere *s1; // $v0
	// 		struct _Instance *inst1; // $s3

		/* begin block 1.1 */
			// Start line: 480
			// Start offset: 0x8008F940
			// Variables:
		// 		struct PhysObWeaponProperties *Prop; // $s1
		/* end block 1.1 */
		// End offset: 0x8008F9A8
		// End Line: 495
	/* end block 1 */
	// End offset: 0x8008F9A8
	// End Line: 496

	/* begin block 2 */
		// Start line: 1000
	/* end block 2 */
	// End Line: 1001

void WALBOSC_Collide(_Instance *instance,GameTracker *gameTracker)

{
  if (*(char *)(*(int *)((int)instance->collideInfo + 0xc) + 4) == '\b') {
                    /* WARNING: Subroutine does not return */
    COLLIDE_SegmentCollisionOff(instance,1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WALBOSC_Message(struct _Instance *instance /*$s0*/, unsigned long message /*$a1*/, unsigned long data /*$a2*/)
 // line 498, offset 0x8008f9c4
	/* begin block 1 */
		// Start line: 1056
	/* end block 1 */
	// End Line: 1057

long WALBOSC_AnimCallback
               (_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,long messageDataA,
               long messageDataB,_Instance *instance)

{
  if ((sectionID == 0x1000017) && (message == 0)) {
                    /* WARNING: Subroutine does not return */
    COLLIDE_SegmentCollisionOff((_Instance *)anim,1);
  }
  return 0x1000017;
}





