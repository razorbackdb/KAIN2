#include "THISDUST.H"
#include "SKINNER.H"


// decompiled code
// original method signature: 
// int /*$ra*/ SKINNER_BurrowInEntry(struct _Instance *instance /*$s1*/)
 // line 52, offset 0x8008c6f4
	/* begin block 1 */
		// Start line: 53
		// Start offset: 0x8008C6F4
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *ma; // $s3
	// 		int rv; // $a1

		/* begin block 1.1 */
			// Start line: 60
			// Start offset: 0x8008C764
			// Variables:
		// 		struct Level *level; // $s0
		/* end block 1.1 */
		// End offset: 0x8008C7BC
		// End Line: 69
	/* end block 1 */
	// End offset: 0x8008C7BC
	// End Line: 71

	/* begin block 2 */
		// Start line: 104
	/* end block 2 */
	// End Line: 105

int SKINNER_BurrowInEntry(_Instance *instance)

{
  ushort uVar1;
  
  if (((instance->tface != (_TFace *)0x0) && (uVar1 = instance->tface->textoff, uVar1 != 0xffff)) &&
     ((*(ushort *)(*(int *)(*(int *)instance->tfaceLevel + 0x34) + (uint)uVar1 + 10) & 0x100) != 0))
  {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SKINNER_BurrowIn(struct _Instance *instance /*$s0*/)
 // line 74, offset 0x8008c7dc
	/* begin block 1 */
		// Start line: 75
		// Start offset: 0x8008C7DC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		int rv; // $v1
	/* end block 1 */
	// End offset: 0x8008C838
	// End Line: 92

	/* begin block 2 */
		// Start line: 157
	/* end block 2 */
	// End Line: 158

int SKINNER_BurrowIn(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0) {
    FX_StopInstanceBurrow(instance);
    *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffffe | 4;
                    /* WARNING: Subroutine does not return */
    instance->flags = instance->flags | 0x800;
    MON_TurnOffWeaponSpheres(instance);
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SKINNER_GetBurrowDest(struct _Instance *instance /*$s0*/, struct _Position *enemyPos /*$a2*/)
 // line 95, offset 0x8008c850
	/* begin block 1 */
		// Start line: 96
		// Start offset: 0x8008C850
		// Variables:
	// 		struct _TFace *oldTFace; // $s2
	// 		int oldbspTree; // $s3
	// 		int rv; // $s1
	// 		struct _Position target; // stack offset -32

		/* begin block 1.1 */
			// Start line: 106
			// Start offset: 0x8008C8F4
			// Variables:
		// 		int Depth; // $v1

			/* begin block 1.1.1 */
				// Start line: 112
				// Start offset: 0x8008C920
				// Variables:
			// 		struct _MonsterVars *mv; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8008C940
			// End Line: 115
		/* end block 1.1 */
		// End offset: 0x8008C940
		// End Line: 116
	/* end block 1 */
	// End offset: 0x8008C940
	// End Line: 120

	/* begin block 2 */
		// Start line: 204
	/* end block 2 */
	// End Line: 205

int SKINNER_GetBurrowDest(_Instance *instance,_Position *enemyPos)

{
  ushort uVar1;
  int iVar2;
  _TFace *p_Var3;
  long lVar4;
  _Position local_20;
  
  p_Var3 = instance->tface;
  lVar4 = instance->bspTree;
  iVar2 = MON_GetRandomGroundPoint(instance,&local_20,enemyPos,0x80,0xcc,0,0x1000,0x2aa);
  if (((iVar2 != 0) && (uVar1 = instance->tface->textoff, uVar1 != 0xffff)) &&
     ((*(ushort *)(*(int *)(*(int *)instance->tfaceLevel + 0x34) + (uint)uVar1 + 10) & 0x100) != 0))
  {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  instance->tface = p_Var3;
  instance->bspTree = lVar4;
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_CalcBurrowingMove(struct _Instance *instance /*$s0*/, struct _Position *enemyPos /*$s2*/)
 // line 123, offset 0x8008c968
	/* begin block 1 */
		// Start line: 124
		// Start offset: 0x8008C968
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _Position *destination; // $a1
	/* end block 1 */
	// End offset: 0x8008C968
	// End Line: 124

	/* begin block 2 */
		// Start line: 269
	/* end block 2 */
	// End Line: 270

void SKINNER_CalcBurrowingMove(_Instance *instance,_Position *enemyPos)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_PupateEntry(struct _Instance *instance /*$s0*/)
 // line 140, offset 0x8008ca3c
	/* begin block 1 */
		// Start line: 141
		// Start offset: 0x8008CA3C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008CA3C
	// End Line: 141

	/* begin block 2 */
		// Start line: 316
	/* end block 2 */
	// End Line: 317

void SKINNER_PupateEntry(_Instance *instance)

{
  MON_PupateEntry(instance);
                    /* WARNING: Subroutine does not return */
  MON_TurnOffBodySpheres(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_Pupate(struct _Instance *instance /*$s0*/)
 // line 149, offset 0x8008ca88
	/* begin block 1 */
		// Start line: 334
	/* end block 1 */
	// End Line: 335

void SKINNER_Pupate(_Instance *instance)

{
  undefined4 local_8;
  undefined4 local_4;
  
  MON_Pupate(instance);
  if ((instance->flags & 0x800U) == 0) {
    MON_OnGround(instance);
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_4,local_8));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_PursueEntry(struct _Instance *instance /*$a0*/)
 // line 162, offset 0x8008cad4
	/* begin block 1 */
		// Start line: 360
	/* end block 1 */
	// End Line: 361

void SKINNER_PursueEntry(_Instance *instance)

{
  MON_PursueEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_Pursue(struct _Instance *instance /*$s1*/)
 // line 168, offset 0x8008caf4
	/* begin block 1 */
		// Start line: 169
		// Start offset: 0x8008CAF4
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct _MonsterIR *enemy; // $s0

		/* begin block 1.1 */
			// Start line: 182
			// Start offset: 0x8008CB4C
			// Variables:
		// 		int burrow; // $s2
		/* end block 1.1 */
		// End offset: 0x8008CBA0
		// End Line: 190

		/* begin block 1.2 */
			// Start line: 203
			// Start offset: 0x8008CBE4

			/* begin block 1.2.1 */
				// Start line: 212
				// Start offset: 0x8008CC00
				// Variables:
			// 		int burrow; // $s2
			/* end block 1.2.1 */
			// End offset: 0x8008CC50
			// End Line: 226
		/* end block 1.2 */
		// End offset: 0x8008CC50
		// End Line: 227
	/* end block 1 */
	// End offset: 0x8008CC60
	// End Line: 232

	/* begin block 2 */
		// Start line: 372
	/* end block 2 */
	// End Line: 373

void SKINNER_Pursue(_Instance *instance)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  pvVar4 = instance->extraData;
  iVar2 = *(int *)((int)pvVar4 + 0xc4);
  if (iVar2 == 0) {
    MON_Pursue(instance);
    return;
  }
  uVar1 = *(uint *)((int)pvVar4 + 4);
  if ((uVar1 & 7) == 0) {
    iVar3 = 0;
    if ((((*(char *)((int)pvVar4 + 0x15a) != '\0') && (0x800 < *(short *)(iVar2 + 0x14))) &&
        (*(short *)(iVar2 + 0x14) < 0x2800)) &&
       (iVar2 = SKINNER_GetBurrowDest(instance,(_Position *)(*(int *)(iVar2 + 4) + 0x5c)),
       iVar2 != 0)) {
      iVar3 = SKINNER_BurrowInEntry(instance);
    }
    if (iVar3 == 0) {
      MON_Pursue(instance);
    }
  }
  else {
    if ((uVar1 & 1) == 0) {
      if ((uVar1 & 4) != 0) {
                    /* WARNING: Subroutine does not return */
        MON_GetTime(instance);
      }
    }
    else {
      iVar3 = SKINNER_BurrowIn(instance);
      if (iVar3 != 0) {
        SKINNER_CalcBurrowingMove(instance,(_Position *)(*(int *)(iVar2 + 4) + 0x5c));
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)pvVar4 + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_HideEntry(struct _Instance *instance /*$a0*/)
 // line 237, offset 0x8008cc7c
	/* begin block 1 */
		// Start line: 238
		// Start offset: 0x8008CC7C
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x8008CCB4
	// End Line: 248

	/* begin block 2 */
		// Start line: 511
	/* end block 2 */
	// End Line: 512

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
 // line 250, offset 0x8008ccc4
	/* begin block 1 */
		// Start line: 251
		// Start offset: 0x8008CCC4
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 268
			// Start offset: 0x8008CD6C
			// Variables:
		// 		struct _MonsterIR *enemy; // $s0
		/* end block 1.1 */
		// End offset: 0x8008CD9C
		// End Line: 275
	/* end block 1 */
	// End offset: 0x8008CDB8
	// End Line: 285

	/* begin block 2 */
		// Start line: 537
	/* end block 2 */
	// End Line: 538

void SKINNER_Hide(_Instance *instance)

{
  int iVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  if (*(char *)((int)pvVar2 + 0x15a) == '\0') {
    MON_Hide(instance);
    return;
  }
  if ((*(uint *)((int)pvVar2 + 4) & 1) == 0) {
    if ((*(uint *)((int)pvVar2 + 4) & 4) == 0) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
    }
    iVar1 = MONSENSE_DetectPlayer(instance);
    if (iVar1 != 0) {
      if (*(char *)((int)pvVar2 + 0x156) == '\x04') {
        MON_ChangeBehavior(instance,(uint)*(byte *)((int)pvVar2 + 0x158));
      }
      else {
        if (*(char *)((int)pvVar2 + 0x156) == '\b') {
                    /* WARNING: Subroutine does not return */
          MON_TurnToPosition(instance,(_Position *)
                                      (*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c),
                             *(short *)(*(int *)((int)pvVar2 + 0x164) + 0x1c));
        }
      }
    }
  }
  else {
    SKINNER_BurrowIn(instance);
  }
                    /* WARNING: Subroutine does not return */
  MON_DefaultQueueHandler(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_SurpriseAttackEntry(struct _Instance *instance /*$s0*/)
 // line 290, offset 0x8008cdd0
	/* begin block 1 */
		// Start line: 291
		// Start offset: 0x8008CDD0
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	/* end block 1 */
	// End offset: 0x8008CE4C
	// End Line: 307

	/* begin block 2 */
		// Start line: 617
	/* end block 2 */
	// End Line: 618

void SKINNER_SurpriseAttackEntry(_Instance *instance)

{
  uint uVar1;
  
  uVar1 = *(uint *)((int)instance->extraData + 4);
  if ((uVar1 & 7) == 0) {
    MON_SurpriseAttackEntry(instance);
    return;
  }
  *(uint *)((int)instance->extraData + 4) = uVar1 & 0xfffffffb | 2;
  instance->flags = instance->flags & 0xfffff7ff;
  if (instance->tface != (_TFace *)0x0) {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
                    /* WARNING: Subroutine does not return */
  GAMEPAD_Shock1(0x40,0x1e000);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SKINNER_SurpriseAttack(struct _Instance *instance /*$s1*/)
 // line 310, offset 0x8008ce64
	/* begin block 1 */
		// Start line: 311
		// Start offset: 0x8008CE64
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008CECC
	// End Line: 325

	/* begin block 2 */
		// Start line: 659
	/* end block 2 */
	// End Line: 660

void SKINNER_SurpriseAttack(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_SurpriseAttack(instance);
  if (instance->currentMainState != 0x15) {
    *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffff8;
    FX_StopInstanceBurrow(instance);
                    /* WARNING: Subroutine does not return */
    MON_TurnOnBodySpheres(instance);
  }
  return;
}





