#include "THISDUST.H"
#include "HUMAN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_WaitForWeapon(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 92, offset 0x8007cd70
	/* begin block 1 */
		// Start line: 184
	/* end block 1 */
	// End Line: 185

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
 // line 110, offset 0x8007cde0
	/* begin block 1 */
		// Start line: 111
		// Start offset: 0x8007CDE0
		// Variables:
	// 		struct Object *weapon; // $a1

		/* begin block 1.1 */
			// Start line: 116
			// Start offset: 0x8007CE18
			// Variables:
		// 		struct _Instance *iweapon; // $s0
		/* end block 1.1 */
		// End offset: 0x8007CE6C
		// End Line: 141
	/* end block 1 */
	// End offset: 0x8007CE9C
	// End Line: 150

	/* begin block 2 */
		// Start line: 228
	/* end block 2 */
	// End Line: 229

_Instance * HUMAN_CreateWeapon(_Instance *instance,int weaponid,int segment)

{
  _Instance *Inst;
  int Data;
  
  if (((Object *)(&objectAccess)[weaponid].object == (Object *)0x0) ||
     (Inst = INSTANCE_BirthObject(instance,(Object *)(&objectAccess)[weaponid].object,0),
     Inst == (_Instance *)0x0)) {
    Inst = (_Instance *)0x0;
    instance->processFunc = HUMAN_WaitForWeapon;
    instance->flags = instance->flags | 0x800;
    instance->flags2 = instance->flags2 | 0x20000080;
  }
  else {
    Data = SetObjectData(0,0,0,instance,segment);
    INSTANCE_Post(Inst,0x800002,Data);
    Inst->flags2 = Inst->flags2 | 0x20000;
  }
  return Inst;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Init(struct _Instance *instance /*$s1*/)
 // line 155, offset 0x8007ceb4
	/* begin block 1 */
		// Start line: 156
		// Start offset: 0x8007CEB4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $v0

		/* begin block 1.1 */
			// Start line: 162
			// Start offset: 0x8007CEE4
			// Variables:
		// 		int opinion; // $v0
		// 		struct _MonsterAllegiances *allegiances; // $a1
		/* end block 1.1 */
		// End offset: 0x8007CF50
		// End Line: 180
	/* end block 1 */
	// End offset: 0x8007CF7C
	// End Line: 188

	/* begin block 2 */
		// Start line: 330
	/* end block 2 */
	// End Line: 331

void HUMAN_Init(_Instance *instance)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  if ((*(uint *)((int)instance->data + 0x10) & 0x2000) == 0) {
    puVar2 = *(uint **)(puVar3[0x5a] + 0xc);
    if (GlobalSave->humanOpinionOfRaziel < 1) {
      puVar2[3] = puVar2[3] & 0xfffffffe;
      *puVar2 = *puVar2 | 1;
      puVar2[1] = puVar2[1] & 0xfffffffe;
    }
    else {
      *puVar2 = *puVar2 & 0xfffffffe;
      puVar2[3] = puVar2[3] | 1;
      puVar2[1] = puVar2[1] | 1;
    }
  }
  iVar1 = strcmpi(instance->object->name,"vlgrb___");
  if (iVar1 == 0) {
    puVar3[1] = puVar3[1] | 0x20;
  }
  MON_DefaultInit(instance);
  *(undefined2 *)(puVar3 + 0x52) = 0x4000;
  *puVar3 = *puVar3 | 0x2000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_CleanUp(struct _Instance *instance /*$a0*/)
 // line 199, offset 0x8007cfac
	/* begin block 1 */
		// Start line: 431
	/* end block 1 */
	// End Line: 432

void HUMAN_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ HUMAN_Query(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 207, offset 0x8007cfcc
	/* begin block 1 */
		// Start line: 208
		// Start offset: 0x8007CFCC
		// Variables:
	// 		struct _MonsterVars *mv; // $a3
	// 		struct _MonsterAttributes *ma; // $v1
	// 		unsigned long ret; // $a1
	/* end block 1 */
	// End offset: 0x8007D0AC
	// End Line: 261

	/* begin block 2 */
		// Start line: 447
	/* end block 2 */
	// End Line: 448

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
         ((*(short *)(puVar3 + 0x51) < 0x1001 || ((puVar3[1] & 3) != 0)))) {
        uVar1 = uVar1 | 0x8000000;
      }
    }
    else {
      if (query == 0x25) {
        uVar1 = 0;
        if ((*(uint *)((int)instance->data + 0x10) & 0x8000) == 0) {
          uVar1 = **(uint **)(puVar3[0x5a] + 0xc) & 1;
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
 // line 266, offset 0x8007d0bc
	/* begin block 1 */
		// Start line: 267
		// Start offset: 0x8007D0BC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007D104
	// End Line: 274

	/* begin block 2 */
		// Start line: 566
	/* end block 2 */
	// End Line: 567

void HUMAN_DeadEntry(_Instance *instance)

{
  int iVar1;
  ulong uVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  iVar1 = (int)*(short *)((int)pvVar3 + 0x148);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 3;
  }
  *(undefined2 *)((int)pvVar3 + 0x148) = (short)(iVar1 >> 2);
  if (0x1000 < iVar1 >> 2) {
    *(undefined2 *)((int)pvVar3 + 0x148) = 0x1000;
  }
  MON_DeadEntry(instance);
  uVar2 = MON_GetTime(instance);
  *(ulong *)((int)pvVar3 + 0x10c) = uVar2;
  MON_BirthMana(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Dead(struct _Instance *instance /*$s1*/)
 // line 287, offset 0x8007d134
	/* begin block 1 */
		// Start line: 288
		// Start offset: 0x8007D134
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007D208
	// End Line: 316

	/* begin block 2 */
		// Start line: 608
	/* end block 2 */
	// End Line: 609

void HUMAN_Dead(_Instance *instance)

{
  ushort uVar1;
  ulong uVar2;
  __Event *p_Var3;
  uint *puVar4;
  
  puVar4 = (uint *)instance->extraData;
  uVar2 = MON_GetTime(instance);
  uVar1 = *(ushort *)(puVar4 + 0x43);
  instance->fadeValue = (short)(uVar2 - uVar1);
  if (*(char *)(puVar4 + 0x56) == '\x06') {
    MON_Dead(instance);
  }
  else {
    if (0xfff < (int)((uVar2 - uVar1) * 0x10000) >> 0x10) {
      MON_KillMonster(instance);
    }
    if (((*puVar4 & 0x400000) != 0) && (uVar2 = MON_GetTime(instance), puVar4[0x47] < uVar2)) {
      *puVar4 = *puVar4 & 0xffbfffff;
    }
    if ((*puVar4 & 2) == 0) {
      MON_ApplyPhysics(instance);
    }
    do {
      p_Var3 = DeMessageQueue((__MessageQueue *)(puVar4 + 2));
    } while (p_Var3 != (__Event *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_StunnedEntry(struct _Instance *instance /*$s0*/)
 // line 321, offset 0x8007d21c
	/* begin block 1 */
		// Start line: 322
		// Start offset: 0x8007D21C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8007D280
	// End Line: 333

	/* begin block 2 */
		// Start line: 676
	/* end block 2 */
	// End Line: 677

void HUMAN_StunnedEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar2;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  pvVar2 = instance->extraData;
  if ((*(uint *)((int)pvVar2 + 4) & 0x10) == 0) {
    MON_StunnedEntry(instance);
  }
  else {
    uVar1 = MON_GetTime(instance);
    *(undefined **)((int)pvVar2 + 0x114) = &DAT_0000ea60 + uVar1;
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
                 0x1e);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Stunned(struct _Instance *instance /*$s1*/)
 // line 335, offset 0x8007d294
	/* begin block 1 */
		// Start line: 336
		// Start offset: 0x8007D294
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007D328
	// End Line: 354

	/* begin block 2 */
		// Start line: 704
	/* end block 2 */
	// End Line: 705

void HUMAN_Stunned(_Instance *instance)

{
  ulong uVar1;
  undefined4 unaff_s0;
  void *pvVar2;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  pvVar2 = instance->extraData;
  if ((*(uint *)((int)pvVar2 + 4) & 0x10) == 0) {
    MON_Stunned(instance);
  }
  else {
    if ((instance->flags2 & 0x10U) != 0) {
      MON_PlayAnim(instance,(MonsterAnim)
                            CONCAT412(in_stack_fffffffc,
                                      CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),5);
    }
    uVar1 = MON_GetTime(instance);
    if (*(uint *)((int)pvVar2 + 0x114) < uVar1) {
      *(undefined2 *)((int)pvVar2 + 0x148) = 0x4000;
      *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) & 0xffffffef;
    }
    MON_DefaultQueueHandler(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_EmbraceEntry(struct _Instance *instance /*$s0*/)
 // line 359, offset 0x8007d33c
	/* begin block 1 */
		// Start line: 360
		// Start offset: 0x8007D33C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8007D37C
	// End Line: 367

	/* begin block 2 */
		// Start line: 752
	/* end block 2 */
	// End Line: 753

void HUMAN_EmbraceEntry(_Instance *instance)

{
  int iVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  pvVar2 = instance->extraData;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x25);
  MON_TurnOffBodySpheres(instance);
  iVar1 = (int)*(short *)((int)pvVar2 + 0x148);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  *(int *)((int)pvVar2 + 0x114) = iVar1 >> 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Embrace(struct _Instance *instance /*$s2*/)
 // line 370, offset 0x8007d398
	/* begin block 1 */
		// Start line: 371
		// Start offset: 0x8007D398
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $a1
	// 		int letgo; // $s3
	// 		int juice; // $s0
	/* end block 1 */
	// End offset: 0x8007D544
	// End Line: 426

	/* begin block 2 */
		// Start line: 777
	/* end block 2 */
	// End Line: 778

void HUMAN_Embrace(_Instance *instance)

{
  bool bVar1;
  __Event *message;
  uint Data;
  void *pvVar2;
  undefined4 local_20;
  undefined4 in_stack_ffffffe4;
  
  bVar1 = false;
  pvVar2 = instance->extraData;
  MON_TurnToPosition(instance,&(gameTrackerX.playerInstance)->position,0x1000);
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar2 + 8)), message != (__Event *)0x0) {
    if (message->ID == 0x1000014) {
      bVar1 = true;
    }
    else {
      MON_DefaultMessageHandler(instance,message);
    }
  }
  Data = (*(int *)((int)pvVar2 + 0x114) * gameTrackerX.timeMult * 0x21) / 5000;
  INSTANCE_Post(gameTrackerX.playerInstance,0x1000016,Data);
  if ((int)*(short *)((int)pvVar2 + 0x148) < (int)Data) {
    *(undefined2 *)((int)pvVar2 + 0x148) = 0;
  }
  else {
    *(short *)((int)pvVar2 + 0x148) = *(short *)((int)pvVar2 + 0x148) - (short)Data;
  }
  GAMEPAD_Shock1(0x80 - (uint)((int)*(short *)((int)pvVar2 + 0x148) << 7) /
                        (uint)(*(int *)((int)pvVar2 + 0x114) << 0xc),0xf000);
  if (*(short *)((int)pvVar2 + 0x148) == 0) {
    *(undefined2 *)((int)pvVar2 + 0x154) = 0;
    MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffe4,local_20));
    INSTANCE_Post(gameTrackerX.playerInstance,0x1000006,(int)instance);
    *(undefined2 *)((int)pvVar2 + 0x148) = 0;
    SOUND_Play3dSound(&instance->position,8,-0x1c2,0x50,0xdac);
  }
  else {
    if (bVar1) {
      *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) | 0x10;
      MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffe4,local_20));
    }
    else {
      if (instance->currentMainState == 0x1b) {
        return;
      }
      INSTANCE_Post(gameTrackerX.playerInstance,0x1000006,(int)instance);
    }
    MON_TurnOnBodySpheres(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_IdleEntry(struct _Instance *instance /*$a0*/)
 // line 431, offset 0x8007d560
	/* begin block 1 */
		// Start line: 432
		// Start offset: 0x8007D560
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007D560
	// End Line: 432

	/* begin block 2 */
		// Start line: 917
	/* end block 2 */
	// End Line: 918

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
 // line 440, offset 0x8007d5a8
	/* begin block 1 */
		// Start line: 441
		// Start offset: 0x8007D5A8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $a3
	// 		struct _MonsterIR *ally; // $v1
	// 		struct _MonsterIR *enemy; // $a0
	/* end block 1 */
	// End offset: 0x8007D74C
	// End Line: 491

	/* begin block 2 */
		// Start line: 935
	/* end block 2 */
	// End Line: 936

void HUMAN_Idle(_Instance *instance)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *animList;
  int animtype;
  void *pvVar4;
  int mode;
  uint *puVar5;
  
  puVar5 = (uint *)instance->extraData;
  pvVar4 = instance->data;
  uVar1 = puVar5[0x33];
  uVar2 = puVar5[0x31];
  if ((((*puVar5 & 4) != 0) || (uVar1 == 0)) || ((*(ushort *)(uVar1 + 0x16) & 4) == 0)) {
LAB_8007d744:
    MON_Idle(instance);
    return;
  }
  uVar3 = puVar5[1];
  if ((uVar3 & 2) == 0) {
    if ((uVar3 & 1) == 0) {
      if ((uVar3 & 4) != 0) {
        if ((instance->flags2 & 0x10U) != 0) {
          puVar5[1] = uVar3 & 0xfffffffb;
          MON_PlayRandomIdle(instance,2);
        }
        goto LAB_8007d734;
      }
      if ((1999 < *(short *)(uVar1 + 0x14)) || ((uVar2 != 0 && (*(short *)(uVar2 + 0x14) < 2000))))
      goto LAB_8007d744;
      animtype = 0;
      puVar5[1] = uVar3 | 2;
      animList = *(char **)((int)pvVar4 + 8);
      mode = 2;
    }
    else {
      if ((*(short *)(uVar1 + 0x14) < 2000) && ((uVar2 == 0 || (1999 < *(short *)(uVar2 + 0x14)))))
      goto LAB_8007d734;
      animtype = 1;
      puVar5[1] = uVar3 & 0xfffffffe | 4;
      animList = *(char **)((int)pvVar4 + 8);
      mode = 1;
    }
    MON_PlayAnimFromList(instance,animList,animtype,mode);
  }
  else {
    MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar1 + 4) + 0x5c),
                       *(short *)(puVar5[0x5a] + 0x1c));
    if ((instance->flags2 & 2U) != 0) {
      puVar5[1] = puVar5[1] & 0xfffffffd | 1;
    }
  }
LAB_8007d734:
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Flee(struct _Instance *instance /*$s1*/)
 // line 496, offset 0x8007d760
	/* begin block 1 */
		// Start line: 497
		// Start offset: 0x8007D760
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s2

		/* begin block 1.1 */
			// Start line: 505
			// Start offset: 0x8007D7B8
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		/* end block 1.1 */
		// End offset: 0x8007D81C
		// End Line: 517
	/* end block 1 */
	// End offset: 0x8007D8A0
	// End Line: 535

	/* begin block 2 */
		// Start line: 1053
	/* end block 2 */
	// End Line: 1054

void HUMAN_Flee(_Instance *instance)

{
  uint uVar1;
  int sfxToneID;
  int pitch;
  int maxVolume;
  uint *puVar2;
  uint uVar3;
  undefined4 local_18;
  undefined4 in_stack_ffffffec;
  
  puVar2 = (uint *)instance->extraData;
  uVar3 = puVar2[0x31];
  if ((uVar3 == 0) || (0x27f < *(short *)(uVar3 + 0x14))) {
    if ((puVar2[1] & 8) == 0) {
      MON_Flee(instance);
    }
    else {
      MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffec,local_18));
    }
  }
  else {
    if ((puVar2[1] & 8) == 0) {
      MON_PlayAnimFromList(instance,*(char **)((int)instance->data + 8),2,2);
      uVar1 = puVar2[1];
      puVar2[1] = uVar1 | 8;
      if ((uVar1 & 0x20) == 0) {
        sfxToneID = 0x1ca;
        pitch = -100;
        maxVolume = 0x5c;
      }
      else {
        sfxToneID = 0x1cb;
        pitch = 0;
        maxVolume = 0x58;
      }
      SOUND_Play3dSound(&instance->position,sfxToneID,pitch,maxVolume,0xdac);
    }
    MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar3 + 4) + 0x5c),
                       *(short *)(puVar2[0x5a] + 0x1c));
    MON_DefaultQueueHandler(instance);
  }
  if (((puVar2[1] & 8) != 0) && ((*puVar2 & 1) != 0)) {
    puVar2[1] = puVar2[1] & 0xfffffff7;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_GetAngry()
 // line 540, offset 0x8007d8b8
	/* begin block 1 */
		// Start line: 541
		// Start offset: 0x8007D8B8
		// Variables:
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 548
			// Start offset: 0x8007D8F4
			// Variables:
		// 		struct _MonsterVars *mv; // $v0
		// 		struct _MonsterAllegiances *allegiances; // $a0
		// 		struct _MonsterIR *mir; // $v1
		/* end block 1.1 */
		// End offset: 0x8007D95C
		// End Line: 563
	/* end block 1 */
	// End offset: 0x8007D96C
	// End Line: 565

	/* begin block 2 */
		// Start line: 1141
	/* end block 2 */
	// End Line: 1142

	/* begin block 3 */
		// Start line: 1144
	/* end block 3 */
	// End Line: 1145

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUMAN_GetAngry(void)

{
  ulong uVar1;
  _MonsterIR *p_Var2;
  uint *puVar3;
  _Instance *Inst;
  
  Inst = (gameTrackerX.instanceList)->first;
  while (Inst != (_Instance *)0x0) {
    uVar1 = INSTANCE_Query(Inst,1);
    if ((uVar1 & 0xc000) != 0) {
      puVar3 = *(uint **)(*(int *)((int)Inst->extraData + 0x168) + 0xc);
      puVar3[3] = puVar3[3] & 0xfffffffe;
      puVar3[1] = puVar3[1] & 0xfffffffe;
      *puVar3 = *puVar3 | 1;
      p_Var2 = MONSENSE_SetEnemy(Inst,gameTrackerX.playerInstance);
      if (p_Var2 != (_MonsterIR *)0x0) {
        p_Var2->mirFlags = p_Var2->mirFlags & 0xfff9;
      }
    }
    Inst = Inst->next;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ HUMAN_TypeOfHuman(struct _Instance *instance /*$s0*/)
 // line 567, offset 0x8007d980
	/* begin block 1 */
		// Start line: 568
		// Start offset: 0x8007D980
		// Variables:
	// 		int type; // $v1
	// 		struct _MonsterVars *mv; // $a0
	/* end block 1 */
	// End offset: 0x8007D9DC
	// End Line: 580

	/* begin block 2 */
		// Start line: 1219
	/* end block 2 */
	// End Line: 1220

int HUMAN_TypeOfHuman(_Instance *instance)

{
  ulong uVar1;
  int iVar2;
  
  uVar1 = INSTANCE_Query(instance,1);
  iVar2 = 1;
  if (((((uVar1 & 0x4000) == 0) && (iVar2 = 4, (uVar1 & 0x2000) == 0)) &&
      (iVar2 = 0, (uVar1 & 0x8000) != 0)) &&
     (iVar2 = 3, (*(uint *)((int)instance->extraData + 4) & 0x20) == 0)) {
    iVar2 = 2;
  }
  return iVar2;
}





