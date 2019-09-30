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

void WCBEGG_Message(_Instance *instance,ulong message,ulong data)

{
  if (message == 0x800002) {
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
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
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(egg,3);
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
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = instance->collideInfo;
  pvVar2 = instance->extraData;
  if (((*(char *)((int)pvVar1 + 7) == '\x01') &&
      (*(char *)(*(int *)((int)pvVar1 + 0xc) + 4) == '\b')) &&
     (*(_Instance **)((int)pvVar1 + 0x14) != (_Instance *)0x0)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)((int)pvVar1 + 0x14),1);
  }
  CollidePhysicalObject(instance,gameTracker);
  *(undefined2 *)((int)pvVar2 + 0x3e) = 0;
  *(undefined2 *)((int)pvVar2 + 0x3c) = 0;
  *(undefined2 *)((int)pvVar2 + 0x3a) = 0;
  *(ushort *)((int)pvVar2 + 0x36) = *(ushort *)((int)pvVar2 + 0x36) & 0xfffe;
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
                    /* WARNING: Subroutine does not return */
    TurnOffCollisionPhysOb(instance,7);
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
                    /* WARNING: Subroutine does not return */
    COLLIDE_SegmentCollisionOff(instance,1);
  }
  INSTANCE_DefaultAnimCallback(anim,sectionID,message,messageDataA,messageDataB,instance);
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
  if (*(char *)(*(int *)((int)instance->collideInfo + 0xc) + 4) == '\b') {
                    /* WARNING: Subroutine does not return */
    COLLIDE_SegmentCollisionOff(instance,1);
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

void WALBOSC_Message(_Instance *instance,ulong message,ulong data)

{
  if ((message == 0x1000017) && (data == 0)) {
                    /* WARNING: Subroutine does not return */
    COLLIDE_SegmentCollisionOff(instance,1);
  }
  return;
}





