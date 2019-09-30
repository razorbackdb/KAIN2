#include "THISDUST.H"
#include "VWRAITH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_MoveVertical(struct _Instance *instance /*$a0*/, long targetZ /*$a1*/, int velocity /*$a2*/)
 // line 89, offset 0x8008e568
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
 // line 108, offset 0x8008e5c0
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x8008E5C0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8008E5F0
	// End Line: 111

	/* begin block 2 */
		// Start line: 216
	/* end block 2 */
	// End Line: 217

void VWRAITH_Init(_Instance *instance)

{
  int iVar1;
  long local_18 [2];
  
  iVar1 = (int)*(short *)((int)instance->extraData + 0x140);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  local_18[0] = FX_GetHealthColor(iVar1 >> 0xc);
                    /* WARNING: Subroutine does not return */
  FX_DoInstanceTwoSegmentGlow(instance,0x15,0x17,local_18,1,0x4b0,0x9c);
}



// decompiled code
// original method signature: 
// int /*$ra*/ VWRAITH_ShouldISwoop(struct _Instance *instance /*$a0*/)
 // line 131, offset 0x8008e674
	/* begin block 1 */
		// Start line: 133
		// Start offset: 0x8008E674
		// Variables:
	// 		struct _MonsterAttributes *ma; // $a3
	// 		struct _MonsterVars *mv; // $v1
	/* end block 1 */
	// End offset: 0x8008E6D0
	// End Line: 136

	/* begin block 2 */
		// Start line: 281
	/* end block 2 */
	// End Line: 282

	/* begin block 3 */
		// Start line: 282
	/* end block 3 */
	// End Line: 283

	/* begin block 4 */
		// Start line: 283
	/* end block 4 */
	// End Line: 284

int VWRAITH_ShouldISwoop(_Instance *instance)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((((*(uint *)instance->extraData & 4) == 0) &&
      (uVar1 = *(uint *)(instance->extraData + 0x31), uVar1 != 0)) &&
     (*(short *)(*(int *)(uVar1 + 4) + 0x60) <= (instance->position).z)) {
    uVar2 = (uint)(*(short *)(*(int *)((int)instance->data + 4) + 0xc) < *(short *)(uVar1 + 0x14));
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_PursueEntry(struct _Instance *instance /*$s1*/)
 // line 144, offset 0x8008e6d8
	/* begin block 1 */
		// Start line: 145
		// Start offset: 0x8008E6D8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 159
			// Start offset: 0x8008E734
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E75C
		// End Line: 164
	/* end block 1 */
	// End offset: 0x8008E75C
	// End Line: 165

	/* begin block 2 */
		// Start line: 310
	/* end block 2 */
	// End Line: 311

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
 // line 167, offset 0x8008e770
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x8008E770
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s1
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 188
			// Start offset: 0x8008E810
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s1
		// 		struct _MonsterAttackAttributes *attack; // $s3
		/* end block 1.1 */
		// End offset: 0x8008E900
		// End Line: 211
	/* end block 1 */
	// End offset: 0x8008E924
	// End Line: 218

	/* begin block 2 */
		// Start line: 356
	/* end block 2 */
	// End Line: 357

void VWRAITH_Pursue(_Instance *instance)

{
  int iVar1;
  undefined4 local_18;
  void *pvVar2;
  undefined4 local_14;
  void *pvVar3;
  
  pvVar2 = instance->extraData;
  pvVar3 = instance->data;
  if ((*(uint *)((int)pvVar2 + 4) & 2) != 0) {
    if (*(int *)((int)pvVar2 + 0xc4) != 0) {
                    /* WARNING: Subroutine does not return */
      MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c),
                         *(short *)(*(int *)((int)pvVar2 + 0x164) + 0x20));
    }
    *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) & 0xfffffffd;
                    /* WARNING: Subroutine does not return */
    MON_DefaultQueueHandler(instance);
  }
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
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_VerticalMove(struct _Instance *instance /*$s0*/)
 // line 223, offset 0x8008e940
	/* begin block 1 */
		// Start line: 224
		// Start offset: 0x8008E940
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 229
			// Start offset: 0x8008E96C
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		// 		long targetZ; // $s1
		/* end block 1.1 */
		// End offset: 0x8008E9B0
		// End Line: 235
	/* end block 1 */
	// End offset: 0x8008E9B0
	// End Line: 236

	/* begin block 2 */
		// Start line: 480
	/* end block 2 */
	// End Line: 481

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
 // line 241, offset 0x8008e9c4
	/* begin block 1 */
		// Start line: 517
	/* end block 1 */
	// End Line: 518

void VWRAITH_CombatEntry(_Instance *instance)

{
  MON_CombatEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Combat(struct _Instance *instance /*$s0*/)
 // line 246, offset 0x8008e9e4
	/* begin block 1 */
		// Start line: 527
	/* end block 1 */
	// End Line: 528

void VWRAITH_Combat(_Instance *instance)

{
  MON_Combat(instance);
  VWRAITH_VerticalMove(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_EmbraceEntry(struct _Instance *instance /*$a0*/)
 // line 256, offset 0x8008ea10
	/* begin block 1 */
		// Start line: 547
	/* end block 1 */
	// End Line: 548

void VWRAITH_EmbraceEntry(_Instance *instance)

{
  MON_EmbraceEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Embrace(struct _Instance *instance /*$s0*/)
 // line 261, offset 0x8008ea30
	/* begin block 1 */
		// Start line: 557
	/* end block 1 */
	// End Line: 558

void VWRAITH_Embrace(_Instance *instance)

{
  MON_Embrace(instance);
  VWRAITH_VerticalMove(instance);
  return;
}





