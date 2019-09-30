#include "THISDUST.H"
#include "HUMAN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_WaitForWeapon(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 87, offset 0x8007c378
	/* begin block 1 */
		// Start line: 174
	/* end block 1 */
	// End Line: 175

void HUMAN_WaitForWeapon(_Instance *instance,GameTracker *gameTracker)

{
  TDRFuncPtr_MONTABLE_GetInitFunc pTVar1;
  
  pTVar1 = MONTABLE_GetInitFunc(instance);
  (*pTVar1)(instance);
  if (instance->LinkChild != (_Instance *)0x0) {
    instance->processFunc = MonsterProcess;
    instance->flags = instance->flags & 0xfffff7ff;
    instance->flags2 = instance->flags2 & 0xdfffff7f;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ HUMAN_CreateWeapon(struct _Instance *instance /*$s1*/, int weaponid /*$a1*/, int segment /*$s2*/)
 // line 105, offset 0x8007c3e8
	/* begin block 1 */
		// Start line: 106
		// Start offset: 0x8007C3E8
		// Variables:
	// 		struct Object *weapon; // $a1

		/* begin block 1.1 */
			// Start line: 111
			// Start offset: 0x8007C420
			// Variables:
		// 		struct _Instance *iweapon; // $s0
		/* end block 1.1 */
		// End offset: 0x8007C474
		// End Line: 136
	/* end block 1 */
	// End offset: 0x8007C4A4
	// End Line: 145

	/* begin block 2 */
		// Start line: 218
	/* end block 2 */
	// End Line: 219

_Instance * HUMAN_CreateWeapon(_Instance *instance,int weaponid,int segment)

{
  _Instance *Inst;
  int Data;
  
  if (((Object *)(&objectAccess)[weaponid].object != (Object *)0x0) &&
     (Inst = INSTANCE_BirthObject(instance,(Object *)(&objectAccess)[weaponid].object,0),
     Inst != (_Instance *)0x0)) {
    Data = SetObjectData(0,0,0,instance,segment);
                    /* WARNING: Subroutine does not return */
    INSTANCE_Post(Inst,0x800002,Data);
  }
  instance->processFunc = HUMAN_WaitForWeapon;
  instance->flags = instance->flags | 0x800;
  instance->flags2 = instance->flags2 | 0x20000080;
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Init(struct _Instance *instance /*$s2*/)
 // line 150, offset 0x8007c4bc
	/* begin block 1 */
		// Start line: 151
		// Start offset: 0x8007C4BC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttributes *ma; // $a3

		/* begin block 1.1 */
			// Start line: 157
			// Start offset: 0x8007C4F0
			// Variables:
		// 		int opinion; // $a2
		// 		struct _MonsterAllegiances *allegiances; // $a1
		/* end block 1.1 */
		// End offset: 0x8007C5EC
		// End Line: 191
	/* end block 1 */
	// End offset: 0x8007C5EC
	// End Line: 193

	/* begin block 2 */
		// Start line: 320
	/* end block 2 */
	// End Line: 321

void HUMAN_Init(_Instance *instance)

{
  short sVar1;
  uint *puVar2;
  void *pvVar3;
  void *pvVar4;
  
  pvVar3 = instance->data;
  pvVar4 = instance->extraData;
  if ((*(uint *)((int)pvVar3 + 0x10) & 0x2000) == 0) {
    sVar1 = GlobalSave->humanOpinionOfRaziel;
    puVar2 = *(uint **)(*(int *)((int)pvVar4 + 0x164) + 0xc);
    if (sVar1 < 1) {
      puVar2[3] = puVar2[3] & 0xfffffffe;
      puVar2[1] = puVar2[1] & 0xfffffffe;
      if (sVar1 < 0) {
        *puVar2 = *puVar2 | 1;
      }
    }
    else {
      *puVar2 = *puVar2 & 0xfffffffe;
      puVar2[3] = puVar2[3] | 1;
      puVar2[1] = puVar2[1] | 1;
    }
    if ((*(uint *)((int)pvVar3 + 0x10) & 0x8000) != 0) {
      if (((*(char *)((int)pvVar4 + 0x15a) == '\x01') && (instance->object->oflags == DAT_800d0848))
         && (*(int *)&instance->object->id == DAT_800d084c)) {
        G2Anim_DisableSegment(&instance->anim,4);
        G2Anim_DisableSegment(&instance->anim,9);
      }
      G2Anim_DisableSegment(&instance->anim,0x1d);
      G2Anim_DisableSegment(&instance->anim,0x17);
    }
  }
                    /* WARNING: Subroutine does not return */
  MON_DefaultInit(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_CleanUp(struct _Instance *instance /*$a0*/)
 // line 204, offset 0x8007c620
	/* begin block 1 */
		// Start line: 438
	/* end block 1 */
	// End Line: 439

void HUMAN_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ HUMAN_Query(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 212, offset 0x8007c640
	/* begin block 1 */
		// Start line: 213
		// Start offset: 0x8007C640
		// Variables:
	// 		struct _MonsterVars *mv; // $a3
	// 		struct _MonsterAttributes *ma; // $v1
	// 		unsigned long ret; // $a1
	/* end block 1 */
	// End offset: 0x8007C720
	// End Line: 266

	/* begin block 2 */
		// Start line: 454
	/* end block 2 */
	// End Line: 455

ulong HUMAN_Query(_Instance *instance,ulong query)

{
  ulong uVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  uVar1 = 0;
  if (instance->data != (void *)0x0) {
    if (query == 0) {
      uVar2 = *puVar3;
      uVar1 = 0x40000000;
      if (((((uVar2 & 0x200) == 0) && (uVar1 = 0x12000000, instance->currentMainState != 0x1e)) &&
          (uVar1 = (uint)((uVar2 & 0x100) != 0) << 0x1d, (uVar2 & 0x200000) == 0)) &&
         ((*(short *)(puVar3 + 0x50) < 0x1001 || ((puVar3[1] & 3) != 0)))) {
        uVar1 = uVar1 | 0x8000000;
      }
    }
    else {
      if (query == 0x25) {
        uVar1 = 0;
        if ((*(uint *)((int)instance->data + 0x10) & 0x8000) == 0) {
          uVar1 = **(uint **)(puVar3[0x59] + 0xc) & 1;
        }
      }
      else {
        uVar1 = MonsterQuery(instance,query);
      }
    }
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_DeadEntry(struct _Instance *instance /*$s1*/)
 // line 271, offset 0x8007c730
	/* begin block 1 */
		// Start line: 272
		// Start offset: 0x8007C730
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007C778
	// End Line: 279

	/* begin block 2 */
		// Start line: 573
	/* end block 2 */
	// End Line: 574

void HUMAN_DeadEntry(_Instance *instance)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  iVar1 = (int)*(short *)((int)pvVar2 + 0x144);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 3;
  }
  *(undefined2 *)((int)pvVar2 + 0x144) = (short)(iVar1 >> 2);
  if (0x1000 < iVar1 >> 2) {
    *(undefined2 *)((int)pvVar2 + 0x144) = 0x1000;
  }
  MON_DeadEntry(instance);
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Dead(struct _Instance *instance /*$s1*/)
 // line 292, offset 0x8007c7a8
	/* begin block 1 */
		// Start line: 293
		// Start offset: 0x8007C7A8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007C87C
	// End Line: 321

	/* begin block 2 */
		// Start line: 615
	/* end block 2 */
	// End Line: 616

void HUMAN_Dead(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_StunnedEntry(struct _Instance *instance /*$s0*/)
 // line 326, offset 0x8007c890
	/* begin block 1 */
		// Start line: 327
		// Start offset: 0x8007C890
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8007C8F4
	// End Line: 338

	/* begin block 2 */
		// Start line: 683
	/* end block 2 */
	// End Line: 684

void HUMAN_StunnedEntry(_Instance *instance)

{
  if ((*(uint *)((int)instance->extraData + 4) & 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  MON_StunnedEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Stunned(struct _Instance *instance /*$s1*/)
 // line 340, offset 0x8007c908
	/* begin block 1 */
		// Start line: 341
		// Start offset: 0x8007C908
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007C99C
	// End Line: 359

	/* begin block 2 */
		// Start line: 711
	/* end block 2 */
	// End Line: 712

void HUMAN_Stunned(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  if ((*(uint *)((int)instance->extraData + 4) & 0x10) == 0) {
    MON_Stunned(instance);
    return;
  }
  if ((instance->flags2 & 0x10U) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,
                                    CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),5);
  }
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_EmbraceEntry(struct _Instance *instance /*$s0*/)
 // line 364, offset 0x8007c9b0
	/* begin block 1 */
		// Start line: 365
		// Start offset: 0x8007C9B0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8007C9F0
	// End Line: 372

	/* begin block 2 */
		// Start line: 759
	/* end block 2 */
	// End Line: 760

void HUMAN_EmbraceEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x25);
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Embrace(struct _Instance *instance /*$s2*/)
 // line 375, offset 0x8007ca0c
	/* begin block 1 */
		// Start line: 376
		// Start offset: 0x8007CA0C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $a1
	// 		int letgo; // $s3
	// 		int juice; // $s0
	/* end block 1 */
	// End offset: 0x8007CBB8
	// End Line: 431

	/* begin block 2 */
		// Start line: 784
	/* end block 2 */
	// End Line: 785

void HUMAN_Embrace(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_TurnToPosition(instance,&(gameTrackerX.playerInstance)->position,0x1000);
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_IdleEntry(struct _Instance *instance /*$a0*/)
 // line 436, offset 0x8007cbd4
	/* begin block 1 */
		// Start line: 437
		// Start offset: 0x8007CBD4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007CBD4
	// End Line: 437

	/* begin block 2 */
		// Start line: 924
	/* end block 2 */
	// End Line: 925

void HUMAN_IdleEntry(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_IdleEntry(instance);
  *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffff8;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Idle(struct _Instance *instance /*$s1*/)
 // line 445, offset 0x8007cc1c
	/* begin block 1 */
		// Start line: 446
		// Start offset: 0x8007CC1C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $a3
	// 		struct _MonsterIR *ally; // $v1
	/* end block 1 */
	// End offset: 0x8007CD78
	// End Line: 495

	/* begin block 2 */
		// Start line: 942
	/* end block 2 */
	// End Line: 943

void HUMAN_Idle(_Instance *instance)

{
  uint uVar1;
  uint uVar2;
  char *animList;
  int animtype;
  void *pvVar3;
  int mode;
  uint *puVar4;
  
  puVar4 = (uint *)instance->extraData;
  pvVar3 = instance->data;
  uVar1 = puVar4[0x33];
  if ((((*puVar4 & 4) != 0) || (uVar1 == 0)) || ((*(ushort *)(uVar1 + 0x16) & 4) == 0)) {
HUMAN_WaitForWeapon:
    MON_Idle(instance);
    return;
  }
  uVar2 = puVar4[1];
  if ((uVar2 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar1 + 4) + 0x5c),
                       *(short *)(puVar4[0x59] + 0x1c));
  }
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 4) != 0) {
      if ((instance->flags2 & 0x10U) != 0) {
        puVar4[1] = uVar2 & 0xfffffffb;
        MON_PlayRandomIdle(instance,2);
      }
      goto LAB_8007cd60;
    }
    if (1999 < *(short *)(uVar1 + 0x14)) goto HUMAN_WaitForWeapon;
    animtype = 0;
    puVar4[1] = uVar2 | 2;
    animList = *(char **)((int)pvVar3 + 8);
    mode = 2;
  }
  else {
    if (*(short *)(uVar1 + 0x14) < 2000) {
LAB_8007cd60:
                    /* WARNING: Subroutine does not return */
      MON_DefaultQueueHandler(instance);
    }
    animtype = 1;
    puVar4[1] = uVar2 & 0xfffffffe | 4;
    animList = *(char **)((int)pvVar3 + 8);
    mode = 1;
  }
                    /* WARNING: Subroutine does not return */
  MON_PlayAnimFromList(instance,animList,animtype,mode);
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Flee(struct _Instance *instance /*$s1*/)
 // line 500, offset 0x8007cd8c
	/* begin block 1 */
		// Start line: 501
		// Start offset: 0x8007CD8C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s2

		/* begin block 1.1 */
			// Start line: 509
			// Start offset: 0x8007CDE4
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		/* end block 1.1 */
		// End offset: 0x8007CE08
		// End Line: 512
	/* end block 1 */
	// End offset: 0x8007CE8C
	// End Line: 530

	/* begin block 2 */
		// Start line: 1057
	/* end block 2 */
	// End Line: 1058

void HUMAN_Flee(_Instance *instance)

{
  undefined4 unaff_s0;
  uint *puVar1;
  undefined4 unaff_s1;
  uint uVar2;
  
  puVar1 = (uint *)instance->extraData;
  uVar2 = puVar1[0x31];
  if ((uVar2 != 0) && (*(short *)(uVar2 + 0x14) < 0x280)) {
    if ((puVar1[1] & 8) == 0) {
                    /* WARNING: Subroutine does not return */
      MON_PlayAnimFromList(instance,*(char **)((int)instance->data + 8),2,2);
    }
                    /* WARNING: Subroutine does not return */
    MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar2 + 4) + 0x5c),
                       *(short *)(puVar1[0x59] + 0x1c));
  }
  if ((puVar1[1] & 8) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  MON_Flee(instance);
  if (((puVar1[1] & 8) != 0) && ((*puVar1 & 1) != 0)) {
    puVar1[1] = puVar1[1] & 0xfffffff7;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_GetAngry()
 // line 535, offset 0x8007cea4
	/* begin block 1 */
		// Start line: 536
		// Start offset: 0x8007CEA4
		// Variables:
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 543
			// Start offset: 0x8007CEE0
			// Variables:
		// 		struct _MonsterVars *mv; // $v0
		// 		struct _MonsterAllegiances *allegiances; // $a0
		// 		struct _MonsterIR *mir; // $v1
		/* end block 1.1 */
		// End offset: 0x8007CF48
		// End Line: 558
	/* end block 1 */
	// End offset: 0x8007CF58
	// End Line: 560

	/* begin block 2 */
		// Start line: 1127
	/* end block 2 */
	// End Line: 1128

	/* begin block 3 */
		// Start line: 1130
	/* end block 3 */
	// End Line: 1131

void HUMAN_GetAngry(void)

{
  if ((gameTrackerX.instanceList)->first != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query((gameTrackerX.instanceList)->first,1);
  }
  return;
}





