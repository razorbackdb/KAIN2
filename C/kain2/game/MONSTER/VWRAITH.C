#include "THISDUST.H"
#include "VWRAITH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_MoveVertical(struct _Instance *instance /*$a0*/, long targetZ /*$a1*/, int velocity /*$a2*/)
 // line 89, offset 0x8008e8f4
	/* begin block 1 */
		// Start line: 178
	/* end block 1 */
	// End Line: 179

	/* begin block 2 */
		// Start line: 179
	/* end block 2 */
	// End Line: 180

void VWRAITH_MoveVertical(_Instance *instance,long targetZ,int velocity)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (int)(instance->position).z;
  uVar3 = (uint)(ushort)(instance->position).z;
  iVar2 = uVar3 + velocity;
  if (iVar4 < targetZ) {
    (instance->position).z = (short)iVar2;
    bVar1 = targetZ < iVar2 * 0x10000 >> 0x10;
  }
  else {
    velocity = uVar3 - velocity;
    if (iVar4 <= targetZ) {
      return;
    }
    (instance->position).z = (short)velocity;
    bVar1 = velocity * 0x10000 >> 0x10 < targetZ;
  }
  if (bVar1) {
    (instance->position).z = (short)targetZ;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Init(struct _Instance *instance /*$s1*/)
 // line 108, offset 0x8008e94c
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x8008E94C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8008E97C
	// End Line: 111

	/* begin block 2 */
		// Start line: 216
	/* end block 2 */
	// End Line: 217

void VWRAITH_Init(_Instance *instance)

{
  _FXGlowEffect *p_Var1;
  int iVar2;
  void *pvVar3;
  long local_18 [2];
  
  pvVar3 = instance->extraData;
  iVar2 = (int)*(short *)((int)pvVar3 + 0x130);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_18[0] = FX_GetHealthColor(iVar2 >> 0xc);
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance,0x15,0x17,local_18,1,0x4b0,0x9c);
                    /* WARNING: Subroutine does not return */
  *(_FXGlowEffect **)((int)pvVar3 + 0xdc) = p_Var1;
  MON_DefaultInit(instance);
}



// decompiled code
// original method signature: 
// int /*$ra*/ VWRAITH_ShouldISwoop(struct _Instance *instance /*$a0*/)
 // line 131, offset 0x8008ea00
	/* begin block 1 */
		// Start line: 132
		// Start offset: 0x8008EA00
		// Variables:
	// 		struct _MonsterAttributes *ma; // $a3
	// 		struct _MonsterVars *mv; // $v1

		/* begin block 1.1 */
			// Start line: 138
			// Start offset: 0x8008EA34
			// Variables:
		// 		struct _Instance *ei; // $a1
		/* end block 1.1 */
		// End offset: 0x8008EA74
		// End Line: 143
	/* end block 1 */
	// End offset: 0x8008EA74
	// End Line: 146

	/* begin block 2 */
		// Start line: 281
	/* end block 2 */
	// End Line: 282

int VWRAITH_ShouldISwoop(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (((*(uint *)instance->extraData & 4) == 0) &&
     (uVar2 = *(uint *)(instance->extraData + 0x31), uVar2 != 0)) {
    iVar1 = 0;
    if ((((*(_Instance **)(uVar2 + 4))->position).z <= (instance->position).z) &&
       (iVar1 = 0, *(short *)(*(int *)((int)instance->data + 4) + 0xc) < *(short *)(uVar2 + 0x14)))
    {
      iVar1 = MON_ShouldIAttackInstance(instance,*(_Instance **)(uVar2 + 4));
    }
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_PursueEntry(struct _Instance *instance /*$s1*/)
 // line 151, offset 0x8008ea84
	/* begin block 1 */
		// Start line: 152
		// Start offset: 0x8008EA84
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 166
			// Start offset: 0x8008EAE0
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		/* end block 1.1 */
		// End offset: 0x8008EB08
		// End Line: 171
	/* end block 1 */
	// End offset: 0x8008EB08
	// End Line: 172

	/* begin block 2 */
		// Start line: 324
	/* end block 2 */
	// End Line: 325

void VWRAITH_PursueEntry(_Instance *instance)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  iVar1 = VWRAITH_ShouldISwoop(instance);
  if (iVar1 != 0) {
    *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) | 2;
  }
  if ((*(uint *)((int)pvVar2 + 4) & 2) == 0) {
    MON_PursueEntry(instance);
    return;
  }
                    /* WARNING: Subroutine does not return */
  MON_PlayAnimFromList
            (instance,*(char **)((int)instance->data + 8),
             (int)*(char *)(*(int *)((int)instance->data + 4) + 0xe),1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Pursue(struct _Instance *instance /*$s2*/)
 // line 174, offset 0x8008eb1c
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x8008EB1C
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s1
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 195
			// Start offset: 0x8008EBBC
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s1
		// 		struct _MonsterAttackAttributes *attack; // $s3
		/* end block 1.1 */
		// End offset: 0x8008ECAC
		// End Line: 218
	/* end block 1 */
	// End offset: 0x8008ECD0
	// End Line: 225

	/* begin block 2 */
		// Start line: 370
	/* end block 2 */
	// End Line: 371

void VWRAITH_Pursue(_Instance *instance)

{
  int iVar1;
  undefined4 local_18;
  void *pvVar2;
  undefined4 local_14;
  void *pvVar3;
  
  pvVar2 = instance->extraData;
  pvVar3 = instance->data;
  if ((*(uint *)((int)pvVar2 + 4) & 2) == 0) {
    iVar1 = VWRAITH_ShouldISwoop(instance);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
    if (*(int *)((int)pvVar2 + 0xc4) != 0) {
      VWRAITH_MoveVertical
                (instance,(int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x60),
                 (int)*(short *)(*(int *)((int)pvVar3 + 4) + 6));
    }
    MON_Pursue(instance);
  }
  else {
    if (*(int *)((int)pvVar2 + 0xc4) != 0) {
                    /* WARNING: Subroutine does not return */
      MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c),
                         *(short *)(*(int *)((int)pvVar2 + 0x154) + 0x20));
    }
    *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) & 0xfffffffd;
    MON_DefaultQueueHandler(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_VerticalMove(struct _Instance *instance /*$s0*/)
 // line 230, offset 0x8008ecec
	/* begin block 1 */
		// Start line: 231
		// Start offset: 0x8008ECEC
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 236
			// Start offset: 0x8008ED18
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		// 		long targetZ; // $s1
		/* end block 1.1 */
		// End offset: 0x8008ED5C
		// End Line: 242
	/* end block 1 */
	// End offset: 0x8008ED5C
	// End Line: 243

	/* begin block 2 */
		// Start line: 494
	/* end block 2 */
	// End Line: 495

void VWRAITH_VerticalMove(_Instance *instance)

{
  int targetZ;
  undefined4 local_10;
  undefined4 local_c;
  
  targetZ = *(int *)((int)instance->extraData + 0xc4);
  if (targetZ != 0) {
    targetZ = (int)*(short *)(*(int *)(targetZ + 4) + 0x60);
    VWRAITH_MoveVertical(instance,targetZ,(int)*(short *)(*(int *)((int)instance->data + 4) + 8));
    if ((instance->currentMainState == 6) && ((int)(instance->position).z != targetZ)) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_CombatEntry(struct _Instance *instance /*$a0*/)
 // line 248, offset 0x8008ed70
	/* begin block 1 */
		// Start line: 531
	/* end block 1 */
	// End Line: 532

void VWRAITH_CombatEntry(_Instance *instance)

{
  MON_CombatEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Combat(struct _Instance *instance /*$s0*/)
 // line 253, offset 0x8008ed90
	/* begin block 1 */
		// Start line: 541
	/* end block 1 */
	// End Line: 542

void VWRAITH_Combat(_Instance *instance)

{
  MON_Combat(instance);
  VWRAITH_VerticalMove(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_EmbraceEntry(struct _Instance *instance /*$a0*/)
 // line 263, offset 0x8008edbc
	/* begin block 1 */
		// Start line: 561
	/* end block 1 */
	// End Line: 562

void VWRAITH_EmbraceEntry(_Instance *instance)

{
  MON_EmbraceEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Embrace(struct _Instance *instance /*$s0*/)
 // line 268, offset 0x8008eddc
	/* begin block 1 */
		// Start line: 571
	/* end block 1 */
	// End Line: 572

void VWRAITH_Embrace(_Instance *instance)

{
  MON_Embrace(instance);
  VWRAITH_VerticalMove(instance);
  return;
}





