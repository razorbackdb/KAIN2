#include "THISDUST.H"
#include "SKINNER.H"


// decompiled code
// original method signature: 
// int /*$ra*/ SKINNER_BurrowInEntry(struct _Instance *instance /*$s1*/)
 // line 51, offset 0x8008b040
	/* begin block 1 */
		// Start line: 52
		// Start offset: 0x8008B040
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s2
	// 		int rv; // $a1

		/* begin block 1.1 */
			// Start line: 59
			// Start offset: 0x8008B0AC
			// Variables:
		// 		struct Level *level; // $s0
		/* end block 1.1 */
		// End offset: 0x8008B0F8
		// End Line: 67
	/* end block 1 */
	// End offset: 0x8008B0F8
	// End Line: 69

	/* begin block 2 */
		// Start line: 102
	/* end block 2 */
	// End Line: 103

int SKINNER_BurrowInEntry(_Instance *instance)

{
  ushort uVar1;
  Level *level;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  
  pvVar3 = instance->extraData;
  pvVar4 = instance->data;
  iVar2 = 0;
  if (((instance->tface != (_TFace *)0x0) && (uVar1 = instance->tface->textoff, uVar1 != 0xffff)) &&
     ((*(ushort *)(*(int *)(*(int *)instance->tfaceLevel + 0x34) + (uint)uVar1 + 10) & 0x100) != 0))
  {
    level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    *(uint *)((int)pvVar3 + 4) = *(uint *)((int)pvVar3 + 4) | 1;
    MON_TurnOffBodySpheres(instance);
    MON_PlayAnimFromList(instance,*(char **)((int)pvVar4 + 8),0,1);
    FX_StartInstanceBurrow(instance,level,instance->tface);
    iVar2 = 1;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SKINNER_BurrowIn(struct _Instance *instance /*$s0*/)
 // line 72, offset 0x8008b114
	/* begin block 1 */
		// Start line: 73
		// Start offset: 0x8008B114
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		int rv; // $v1
	/* end block 1 */
	// End offset: 0x8008B18C
	// End Line: 90

	/* begin block 2 */
		// Start line: 151
	/* end block 2 */
	// End Line: 152

int SKINNER_BurrowIn(_Instance *instance)

{
  bool bVar1;
  Level *level;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  bVar1 = (instance->flags2 & 0x10U) != 0;
  if (bVar1) {
    FX_StopInstanceBurrow(instance);
    *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) & 0xfffffffe | 4;
    instance->flags = instance->flags | 0x800;
    MON_TurnOffWeaponSpheres(instance);
    level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    FX_StartInstanceBurrow(instance,level,instance->tface);
  }
  return (uint)bVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SKINNER_GetBurrowDest(struct _Instance *instance /*$s0*/, struct _Position *enemyPos /*$a2*/)
 // line 93, offset 0x8008b1a4
	/* begin block 1 */
		// Start line: 94
		// Start offset: 0x8008B1A4
		// Variables:
	// 		struct _TFace *oldTFace; // $s2
	// 		int oldbspTree; // $s3
	// 		int rv; // $s1
	// 		struct _Position target; // stack offset -32

		/* begin block 1.1 */
			// Start line: 104
			// Start offset: 0x8008B248
			// Variables:
		// 		int Depth; // $v1

			/* begin block 1.1.1 */
				// Start line: 110
				// Start offset: 0x8008B274
				// Variables:
			// 		struct _MonsterVars *mv; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8008B294
			// End Line: 113
		/* end block 1.1 */
		// End offset: 0x8008B294
		// End Line: 114
	/* end block 1 */
	// End offset: 0x8008B294
	// End Line: 118

	/* begin block 2 */
		// Start line: 198
	/* end block 2 */
	// End Line: 199

int SKINNER_GetBurrowDest(_Instance *instance,_Position *enemyPos)

{
  ushort uVar1;
  int iVar2;
  Level *level;
  long lVar3;
  void *pvVar4;
  int iVar5;
  _TFace *p_Var6;
  long lVar7;
  undefined4 local_20;
  short local_1c;
  
  iVar5 = 0;
  p_Var6 = instance->tface;
  lVar7 = instance->bspTree;
  iVar2 = MON_GetRandomGroundPoint
                    (instance,(_Position *)&local_20,enemyPos,0x80,0xcc,0,0x1000,0x2aa);
  if (iVar2 != 0) {
    uVar1 = instance->tface->textoff;
    iVar5 = 0;
    if ((uVar1 != 0xffff) &&
       (iVar5 = 0,
       (*(ushort *)(*(int *)(*(int *)instance->tfaceLevel + 0x34) + (uint)uVar1 + 10) & 0x100) != 0)
       ) {
      level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
      lVar3 = STREAM_GetWaterZLevel(level,instance);
      iVar5 = 0;
      if (0 < local_1c - lVar3) {
        pvVar4 = instance->extraData;
        iVar5 = 1;
        *(undefined4 *)((int)pvVar4 + 0x120) = local_20;
        *(short *)((int)pvVar4 + 0x124) = local_1c;
      }
    }
  }
  instance->tface = p_Var6;
  instance->bspTree = lVar7;
  return iVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_CalcBurrowingMove(struct _Instance *instance /*$s0*/, struct _Position *enemyPos /*$s2*/)
 // line 121, offset 0x8008b2bc
	/* begin block 1 */
		// Start line: 122
		// Start offset: 0x8008B2BC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _Position *destination; // $a1
	/* end block 1 */
	// End offset: 0x8008B2BC
	// End Line: 122

	/* begin block 2 */
		// Start line: 263
	/* end block 2 */
	// End Line: 264

void SKINNER_CalcBurrowingMove(_Instance *instance,_Position *enemyPos)

{
  short sVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  
  pvVar5 = instance->extraData;
  uVar2 = MON_GetTime(instance);
  iVar4 = (int)*(short *)((int)pvVar5 + 0x120) - (int)(instance->position).x;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  iVar3 = (int)*(short *)((int)pvVar5 + 0x122) - (int)(instance->position).y;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  *(int *)((int)pvVar5 + 0x114) = uVar2 + ((iVar4 + iVar3) * 1000) / 0xa00;
  sVar1 = *(short *)((int)pvVar5 + 0x124);
  *(undefined4 *)&instance->position = *(undefined4 *)((int)pvVar5 + 0x120);
  (instance->position).z = sVar1;
  MON_TurnToPosition(instance,enemyPos,0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_PursueEntry(struct _Instance *instance /*$a0*/)
 // line 138, offset 0x8008b390
	/* begin block 1 */
		// Start line: 310
	/* end block 1 */
	// End Line: 311

void SKINNER_PursueEntry(_Instance *instance)

{
  MON_PursueEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_Pursue(struct _Instance *instance /*$s1*/)
 // line 143, offset 0x8008b3b0
	/* begin block 1 */
		// Start line: 144
		// Start offset: 0x8008B3B0
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct _MonsterIR *enemy; // $s0

		/* begin block 1.1 */
			// Start line: 157
			// Start offset: 0x8008B408
			// Variables:
		// 		int burrow; // $s2
		/* end block 1.1 */
		// End offset: 0x8008B45C
		// End Line: 165

		/* begin block 1.2 */
			// Start line: 178
			// Start offset: 0x8008B4A0

			/* begin block 1.2.1 */
				// Start line: 187
				// Start offset: 0x8008B4BC
				// Variables:
			// 		int burrow; // $s2
			/* end block 1.2.1 */
			// End offset: 0x8008B50C
			// End Line: 202
		/* end block 1.2 */
		// End offset: 0x8008B50C
		// End Line: 203
	/* end block 1 */
	// End offset: 0x8008B51C
	// End Line: 208

	/* begin block 2 */
		// Start line: 320
	/* end block 2 */
	// End Line: 321

void SKINNER_Pursue(_Instance *instance)

{
  bool bVar1;
  ulong uVar2;
  __Event *p_Var3;
  uint uVar4;
  undefined4 local_18;
  int iVar5;
  undefined4 local_14;
  int iVar6;
  void *pvVar7;
  
  pvVar7 = instance->extraData;
  iVar5 = *(int *)((int)pvVar7 + 0xc4);
  if (iVar5 == 0) {
    MON_Pursue(instance);
  }
  else {
    uVar4 = *(uint *)((int)pvVar7 + 4);
    if ((uVar4 & 7) == 0) {
      iVar6 = 0;
      if ((((*(char *)((int)pvVar7 + 0x15a) != '\0') && (0x800 < *(short *)(iVar5 + 0x14))) &&
          (*(short *)(iVar5 + 0x14) < 0x2800)) &&
         (iVar5 = SKINNER_GetBurrowDest(instance,(_Position *)(*(int *)(iVar5 + 4) + 0x5c)),
         iVar5 != 0)) {
        iVar6 = SKINNER_BurrowInEntry(instance);
      }
      if (iVar6 == 0) {
        MON_Pursue(instance);
      }
    }
    else {
      if ((uVar4 & 1) == 0) {
        if (((uVar4 & 4) != 0) &&
           (uVar2 = MON_GetTime(instance), *(uint *)((int)pvVar7 + 0x114) < uVar2)) {
          bVar1 = false;
          if (((uint)*(ushort *)(iVar5 + 0x14) - 0xcd < 0x2733) &&
             (iVar6 = SKINNER_GetBurrowDest(instance,(_Position *)(*(int *)(iVar5 + 4) + 0x5c)),
             iVar6 != 0)) {
            bVar1 = true;
            SKINNER_CalcBurrowingMove(instance,(_Position *)(*(int *)(iVar5 + 4) + 0x5c));
          }
          if (!bVar1) {
            MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
          }
        }
      }
      else {
        iVar6 = SKINNER_BurrowIn(instance);
        if (iVar6 != 0) {
          SKINNER_CalcBurrowingMove(instance,(_Position *)(*(int *)(iVar5 + 4) + 0x5c));
        }
      }
    }
    do {
      p_Var3 = DeMessageQueue((__MessageQueue *)((int)pvVar7 + 8));
    } while (p_Var3 != (__Event *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_HideEntry(struct _Instance *instance /*$a0*/)
 // line 213, offset 0x8008b538
	/* begin block 1 */
		// Start line: 214
		// Start offset: 0x8008B538
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x8008B570
	// End Line: 224

	/* begin block 2 */
		// Start line: 461
	/* end block 2 */
	// End Line: 462

void SKINNER_HideEntry(_Instance *instance)

{
  if (*(char *)((int)instance->extraData + 0x15a) == '\0') {
    MON_HideEntry(instance);
  }
  else {
    SKINNER_BurrowInEntry(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_Hide(struct _Instance *instance /*$s2*/)
 // line 226, offset 0x8008b580
	/* begin block 1 */
		// Start line: 227
		// Start offset: 0x8008B580
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 244
			// Start offset: 0x8008B628
			// Variables:
		// 		struct _MonsterIR *enemy; // $s0
		/* end block 1.1 */
		// End offset: 0x8008B658
		// End Line: 252
	/* end block 1 */
	// End offset: 0x8008B674
	// End Line: 262

	/* begin block 2 */
		// Start line: 487
	/* end block 2 */
	// End Line: 488

void SKINNER_Hide(_Instance *instance)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  if (*(char *)((int)pvVar2 + 0x15a) == '\0') {
    MON_Hide(instance);
    return;
  }
  if ((*(uint *)((int)pvVar2 + 4) & 1) != 0) {
    SKINNER_BurrowIn(instance);
    goto LAB_8008b66c;
  }
  if ((*(uint *)((int)pvVar2 + 4) & 4) != 0) {
    iVar1 = MONSENSE_DetectPlayer(instance);
    if (iVar1 == 0) goto LAB_8008b66c;
    if (*(char *)((int)pvVar2 + 0x156) == '\x04') {
      MON_ChangeBehavior(instance,(uint)*(byte *)((int)pvVar2 + 0x158));
      goto LAB_8008b66c;
    }
    if ((*(char *)((int)pvVar2 + 0x156) != '\b') ||
       (iVar1 = *(int *)((int)pvVar2 + 0xc4),
       MON_TurnToPosition(instance,(_Position *)(*(int *)(iVar1 + 4) + 0x5c),
                          *(short *)(*(int *)((int)pvVar2 + 0x164) + 0x1c)),
       *(short *)((int)pvVar2 + 0x13a) <= *(short *)(iVar1 + 0x14))) goto LAB_8008b66c;
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
LAB_8008b66c:
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_SurpriseAttackEntry(struct _Instance *instance /*$s0*/)
 // line 267, offset 0x8008b68c
	/* begin block 1 */
		// Start line: 268
		// Start offset: 0x8008B68C
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	/* end block 1 */
	// End offset: 0x8008B6FC
	// End Line: 283

	/* begin block 2 */
		// Start line: 569
	/* end block 2 */
	// End Line: 570

void SKINNER_SurpriseAttackEntry(_Instance *instance)

{
  Level *level;
  uint uVar1;
  
  uVar1 = *(uint *)((int)instance->extraData + 4);
  if ((uVar1 & 7) != 0) {
    *(uint *)((int)instance->extraData + 4) = uVar1 & 0xfffffffb | 2;
    instance->flags = instance->flags & 0xfffff7ff;
    level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    FX_StartInstanceBurrow(instance,level,instance->tface);
    GAMEPAD_Shock1(0x40,0x1e000);
  }
  MON_SurpriseAttackEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_SurpriseAttack(struct _Instance *instance /*$s0*/)
 // line 286, offset 0x8008b714
	/* begin block 1 */
		// Start line: 287
		// Start offset: 0x8008B714
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008B76C
	// End Line: 299

	/* begin block 2 */
		// Start line: 610
	/* end block 2 */
	// End Line: 611

void SKINNER_SurpriseAttack(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_SurpriseAttack(instance);
  if (instance->currentMainState != 0x15) {
    *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffff8;
    FX_StopInstanceBurrow(instance);
    MON_TurnOnBodySpheres(instance);
  }
  return;
}





