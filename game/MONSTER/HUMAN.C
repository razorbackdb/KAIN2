#include "THISDUST.H"
#include "HUMAN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_WaitForWeapon(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 80, offset 0x8007bb98
	/* begin block 1 */
		// Start line: 160
	/* end block 1 */
	// End Line: 161

void HUMAN_WaitForWeapon(_Instance *instance,GameTracker *gameTracker)

{
  TDRFuncPtr_MONTABLE_GetInitFunc pTVar1;
  
  pTVar1 = MONTABLE_GetInitFunc(instance);
  (*pTVar1)(instance);
  if (instance->LinkChild != (_Instance *)0x0) {
    instance->processFunc = MonsterProcess;
    instance->flags = instance->flags & 0xfffff7ff;
    instance->flags2 = instance->flags2 & 0xdfffffff;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ HUMAN_CreateWeapon(struct _Instance *instance /*$s1*/, int weaponid /*$a1*/, int segment /*$s3*/)
 // line 95, offset 0x8007bc00
	/* begin block 1 */
		// Start line: 96
		// Start offset: 0x8007BC00
		// Variables:
	// 		struct Object *weapon; // $s2

		/* begin block 1.1 */
			// Start line: 101
			// Start offset: 0x8007BC3C
			// Variables:
		// 		struct _Instance *iweapon; // $s0

			/* begin block 1.1.1 */
				// Start line: 107
				// Start offset: 0x8007BC74
			/* end block 1.1.1 */
			// End offset: 0x8007BCA8
			// End Line: 113
		/* end block 1.1 */
		// End offset: 0x8007BD34
		// End Line: 132
	/* end block 1 */
	// End offset: 0x8007BD38
	// End Line: 139

	/* begin block 2 */
		// Start line: 196
	/* end block 2 */
	// End Line: 197

_Instance * HUMAN_CreateWeapon(_Instance *instance,int weaponid,int segment)

{
  long lVar1;
  int Data;
  _Instance *Inst;
  Object *object;
  
  object = (Object *)(&objectAccess)[weaponid].object;
  if (object == (Object *)0x0) {
LAB_8007bd34:
    Inst = (_Instance *)0x0;
  }
  else {
    Inst = (gameTrackerX.instanceList)->first;
    if (Inst == (_Instance *)0x0) {
LAB_8007bcc0:
      Inst = INSTANCE_BirthObject(instance,object,0);
      if (Inst == (_Instance *)0x0) {
        instance->processFunc = HUMAN_WaitForWeapon;
        instance->flags = instance->flags | 0x800;
        instance->flags2 = instance->flags2 | 0x20000000;
        goto LAB_8007bd34;
      }
    }
    else {
      do {
        if (((Inst->object == object) && (Inst->LinkParent == (_Instance *)0x0)) &&
           (lVar1 = MATH3D_LengthXYZ((int)(Inst->position).x - (int)(instance->position).x,
                                     (int)(Inst->position).y - (int)(instance->position).y,
                                     (int)(Inst->position).z - (int)(instance->position).z),
           lVar1 < 0x280)) break;
        Inst = Inst->next;
      } while (Inst != (_Instance *)0x0);
      if (Inst == (_Instance *)0x0) goto LAB_8007bcc0;
    }
    Data = SetObjectData(0,0,0,instance,segment);
    INSTANCE_Post(Inst,0x800002,Data);
  }
  return Inst;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Init(struct _Instance *instance /*$s2*/)
 // line 144, offset 0x8007bd54
	/* begin block 1 */
		// Start line: 145
		// Start offset: 0x8007BD54
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttributes *ma; // $a3

		/* begin block 1.1 */
			// Start line: 151
			// Start offset: 0x8007BD88
			// Variables:
		// 		int opinion; // $a2
		// 		struct _MonsterAllegiances *allegiances; // $a1
		/* end block 1.1 */
		// End offset: 0x8007BE94
		// End Line: 185
	/* end block 1 */
	// End offset: 0x8007BE94
	// End Line: 187

	/* begin block 2 */
		// Start line: 308
	/* end block 2 */
	// End Line: 309

void HUMAN_Init(_Instance *instance)

{
  short sVar1;
  uint *puVar2;
  void *pvVar3;
  uint *puVar4;
  
  pvVar3 = instance->data;
  puVar4 = (uint *)instance->extraData;
  if ((*(uint *)((int)pvVar3 + 0x10) & 0x2000) == 0) {
    sVar1 = GlobalSave->humanOpinionOfRaziel;
    puVar2 = *(uint **)(puVar4[0x59] + 0xc);
    if (sVar1 < 1) {
      puVar2[3] = puVar2[3] & 0xfffffffe;
      puVar2[1] = puVar2[1] & 0xfffffffe;
      if (sVar1 < -3) {
        *puVar2 = *puVar2 | 1;
      }
    }
    else {
      *puVar2 = *puVar2 & 0xfffffffe;
      if (3 < sVar1) {
        puVar2[3] = puVar2[3] | 1;
        puVar2[1] = puVar2[1] | 1;
      }
    }
    if ((*(uint *)((int)pvVar3 + 0x10) & 0x8000) != 0) {
      if (((*(char *)((int)puVar4 + 0x15a) == '\x01') && (instance->object->oflags == 0x72676c76))
         && (*(int *)&instance->object->id == 0x5f5f5f61)) {
        G2Anim_DisableSegment(&instance->anim,4);
        G2Anim_DisableSegment(&instance->anim,9);
      }
      G2Anim_DisableSegment(&instance->anim,0x1d);
      G2Anim_DisableSegment(&instance->anim,0x17);
    }
  }
  MON_DefaultInit(instance);
  *(undefined2 *)(puVar4 + 0x51) = 0x2000;
  *puVar4 = *puVar4 | 0x2000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_CleanUp(struct _Instance *instance /*$a0*/)
 // line 197, offset 0x8007bec8
	/* begin block 1 */
		// Start line: 424
	/* end block 1 */
	// End Line: 425

void HUMAN_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ HUMAN_Query(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 205, offset 0x8007bee8
	/* begin block 1 */
		// Start line: 206
		// Start offset: 0x8007BEE8
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	// 		struct _MonsterAttributes *ma; // $v1
	// 		unsigned long ret; // $a1
	/* end block 1 */
	// End offset: 0x8007BFF4
	// End Line: 251

	/* begin block 2 */
		// Start line: 440
	/* end block 2 */
	// End Line: 441

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
      if (((uVar2 & 0x200) == 0) &&
         (uVar1 = (uint)((uVar2 & 0x100) != 0) << 0x1d, (uVar2 & 0x200000) == 0)) {
        if (*(short *)(puVar3 + 0x50) < 0x1001) {
          uVar1 = uVar1 | 0x98000000;
        }
        else {
          if ((((uVar2 & 0x10) != 0) || (puVar3[0x31] == 0)) || (instance->currentMainState == 0x18)
             ) {
            uVar1 = uVar1 | 0x10000000;
          }
          if ((puVar3[1] & 2) != 0) {
            uVar1 = uVar1 | 0x8000000;
          }
        }
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
// void /*$ra*/ HUMAN_DeadEntry(struct _Instance *instance /*$s0*/)
 // line 256, offset 0x8007c004
	/* begin block 1 */
		// Start line: 257
		// Start offset: 0x8007C004
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8007C004
	// End Line: 257

	/* begin block 2 */
		// Start line: 543
	/* end block 2 */
	// End Line: 544

void HUMAN_DeadEntry(_Instance *instance)

{
  ulong uVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  MON_DeadEntry(instance);
  uVar1 = MON_GetTime(instance);
  *(ulong *)((int)pvVar2 + 0x10c) = uVar1;
  MON_BirthMana(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Dead(struct _Instance *instance /*$s1*/)
 // line 273, offset 0x8007c04c
	/* begin block 1 */
		// Start line: 274
		// Start offset: 0x8007C04C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007C104
	// End Line: 295

	/* begin block 2 */
		// Start line: 577
	/* end block 2 */
	// End Line: 578

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
  if (0xfff < (int)((uVar2 - uVar1) * 0x10000) >> 0x10) {
    MON_KillMonster(instance);
  }
  if (((*puVar4 & 0x400000) != 0) && (uVar2 = MON_GetTime(instance), puVar4[0x46] < uVar2)) {
    *puVar4 = *puVar4 & 0xffbfffff;
  }
  if ((*puVar4 & 2) == 0) {
    MON_ApplyPhysics(instance);
  }
  do {
    p_Var3 = DeMessageQueue((__MessageQueue *)(puVar4 + 2));
  } while (p_Var3 != (__Event *)0x0);
  return;
}



// autogenerated function stub: 
// void /*$ra*/ HUMAN_StunnedEntry(struct _Instance *instance /*$a0*/)
void HUMAN_StunnedEntry(struct _Instance *instance)
{ // line 300, offset 0x8007c118
	/* begin block 1 */
		// Start line: 301
		// Start offset: 0x8007C118
		// Variables:
			struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x8007C150
	// End Line: 310

	/* begin block 2 */
		// Start line: 631
	/* end block 2 */
	// End Line: 632

}


// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Stunned(struct _Instance *instance /*$s0*/)
 // line 312, offset 0x8007c160
	/* begin block 1 */
		// Start line: 313
		// Start offset: 0x8007C160
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x8007C1BC
	// End Line: 325

	/* begin block 2 */
		// Start line: 655
	/* end block 2 */
	// End Line: 656

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void HUMAN_Stunned(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  undefined8 uStackX0;
  
  if (*(short *)((int)instance->extraData + 0x144) == 0x2000) {
    MON_Stunned(instance);
  }
  else {
    if ((instance->flags2 & 0x10U) != 0) {
      MON_PlayAnim(instance,(MonsterAnim)CONCAT88(uStackX0,CONCAT44(unaff_retaddr,unaff_s0)),5);
    }
    MON_DefaultQueueHandler(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_EmbraceEntry(struct _Instance *instance /*$s0*/)
 // line 330, offset 0x8007c1cc
	/* begin block 1 */
		// Start line: 331
		// Start offset: 0x8007C1CC
	/* end block 1 */
	// End offset: 0x8007C1CC
	// End Line: 331

	/* begin block 2 */
		// Start line: 691
	/* end block 2 */
	// End Line: 692

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void HUMAN_EmbraceEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  undefined8 uStackX0;
  
  MON_PlayAnim(instance,(MonsterAnim)CONCAT88(uStackX0,CONCAT44(unaff_retaddr,unaff_s0)),0x25);
  MON_TurnOffBodySpheres(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Embrace(struct _Instance *instance /*$s2*/)
 // line 340, offset 0x8007c200
	/* begin block 1 */
		// Start line: 341
		// Start offset: 0x8007C200
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $a1
	// 		int letgo; // $s3
	// 		int juice; // $s0
	/* end block 1 */
	// End offset: 0x8007C350
	// End Line: 392

	/* begin block 2 */
		// Start line: 714
	/* end block 2 */
	// End Line: 715

void HUMAN_Embrace(_Instance *instance)

{
  bool bVar1;
  __Event *message;
  undefined4 local_18;
  uint Data;
  undefined4 local_14;
  void *pvVar2;
  
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
  Data = (gameTrackerX.idleTime * 0x5a) / 3000;
  INSTANCE_Post(gameTrackerX.playerInstance,0x1000016,Data);
  if ((int)*(short *)((int)pvVar2 + 0x144) < (int)Data) {
    *(undefined2 *)((int)pvVar2 + 0x144) = 0;
  }
  else {
    *(short *)((int)pvVar2 + 0x144) = *(short *)((int)pvVar2 + 0x144) - (short)Data;
  }
  if (*(short *)((int)pvVar2 + 0x144) == 0) {
    *(undefined2 *)((int)pvVar2 + 0x150) = 0;
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    INSTANCE_Post(gameTrackerX.playerInstance,0x1000006,(int)instance);
    *(undefined2 *)((int)pvVar2 + 0x144) = 0;
  }
  else {
    if (bVar1) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
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
 // line 397, offset 0x8007c36c
	/* begin block 1 */
		// Start line: 398
		// Start offset: 0x8007C36C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007C36C
	// End Line: 398

	/* begin block 2 */
		// Start line: 845
	/* end block 2 */
	// End Line: 846

void HUMAN_IdleEntry(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_IdleEntry(instance);
  *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffff9;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Idle(struct _Instance *instance /*$s0*/)
 // line 405, offset 0x8007c3ac
	/* begin block 1 */
		// Start line: 406
		// Start offset: 0x8007C3AC
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	// 		struct _MonsterAttributes *ma; // $a2
	/* end block 1 */
	// End offset: 0x8007C474
	// End Line: 440

	/* begin block 2 */
		// Start line: 861
	/* end block 2 */
	// End Line: 862

void HUMAN_Idle(_Instance *instance)

{
  uint uVar1;
  uint *puVar2;
  void *pvVar3;
  
  puVar2 = (uint *)instance->extraData;
  pvVar3 = instance->data;
  if ((((*puVar2 & 4) == 0) && (puVar2[0x33] != 0)) && ((*(ushort *)(puVar2[0x33] + 0x16) & 4) != 0)
     ) {
    uVar1 = puVar2[1];
    if ((uVar1 & 2) == 0) {
      if ((uVar1 & 4) == 0) {
        puVar2[1] = uVar1 | 2;
        MON_PlayAnimFromList(instance,*(char **)((int)pvVar3 + 8),0,2);
      }
      else {
        if ((instance->flags2 & 0x10U) != 0) {
          puVar2[1] = uVar1 & 0xfffffffb;
          MON_PlayRandomIdle(instance,2);
        }
      }
    }
    MON_DefaultQueueHandler(instance);
  }
  else {
    MON_Idle(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUMAN_Flee(struct _Instance *instance /*$s1*/)
 // line 445, offset 0x8007c484
	/* begin block 1 */
		// Start line: 446
		// Start offset: 0x8007C484
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s2

		/* begin block 1.1 */
			// Start line: 454
			// Start offset: 0x8007C4DC
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		/* end block 1.1 */
		// End offset: 0x8007C500
		// End Line: 457
	/* end block 1 */
	// End offset: 0x8007C584
	// End Line: 475

	/* begin block 2 */
		// Start line: 944
	/* end block 2 */
	// End Line: 945

void HUMAN_Flee(_Instance *instance)

{
  undefined4 unaff_s0;
  uint *puVar1;
  undefined4 unaff_s1;
  uint uVar2;
  
  puVar1 = (uint *)instance->extraData;
  uVar2 = puVar1[0x31];
  if ((uVar2 == 0) || (0x27f < *(short *)(uVar2 + 0x14))) {
    if ((puVar1[1] & 8) == 0) {
      MON_Flee(instance);
    }
    else {
      MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
    }
  }
  else {
    if ((puVar1[1] & 8) == 0) {
      MON_PlayAnimFromList(instance,*(char **)((int)instance->data + 8),2,2);
      puVar1[1] = puVar1[1] | 8;
    }
    MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar2 + 4) + 0x5c),
                       *(short *)(puVar1[0x59] + 0x1c));
    MON_DefaultQueueHandler(instance);
  }
  if (((puVar1[1] & 8) != 0) && ((*puVar1 & 1) != 0)) {
    puVar1[1] = puVar1[1] & 0xfffffff7;
  }
  return;
}





