#include "THISDUST.H"
#include "VWRAITH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_MoveVertical(struct _Instance *instance /*$a0*/, long targetZ /*$a1*/, int velocity /*$a2*/)
 // line 89, offset 0x8008ea34
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
 // line 108, offset 0x8008ea8c
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x8008EA8C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8008EABC
	// End Line: 111

	/* begin block 2 */
		// Start line: 216
	/* end block 2 */
	// End Line: 217

void VWRAITH_Init(_Instance *instance)

{
  _FXGlowEffect *p_Var1;
  int iVar2;
  uint *puVar3;
  long local_18 [2];
  
  puVar3 = (uint *)instance->extraData;
  iVar2 = (int)*(short *)(puVar3 + 0x51);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_18[0] = FX_GetHealthColor(iVar2 >> 0xc);
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance,0x15,0x17,local_18,1,0x4b0,0x9c);
  *(_FXGlowEffect **)(puVar3 + 0x37) = p_Var1;
  MON_DefaultInit(instance);
  *(undefined2 *)(puVar3 + 0x52) = 0x3000;
  puVar3[1] = puVar3[1] & 0xfffffffe;
  *puVar3 = *puVar3 | 0x10002800;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VWRAITH_ShouldISwoop(struct _Instance *instance /*$a0*/)
 // line 131, offset 0x8008eb40
	/* begin block 1 */
		// Start line: 132
		// Start offset: 0x8008EB40
		// Variables:
	// 		struct _MonsterAttributes *ma; // $a3
	// 		struct _MonsterVars *mv; // $v1

		/* begin block 1.1 */
			// Start line: 138
			// Start offset: 0x8008EB74
			// Variables:
		// 		struct _Instance *ei; // $a1
		/* end block 1.1 */
		// End offset: 0x8008EBB4
		// End Line: 143
	/* end block 1 */
	// End offset: 0x8008EBB4
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
 // line 151, offset 0x8008ebc4
	/* begin block 1 */
		// Start line: 152
		// Start offset: 0x8008EBC4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 166
			// Start offset: 0x8008EC20
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		/* end block 1.1 */
		// End offset: 0x8008EC48
		// End Line: 171
	/* end block 1 */
	// End offset: 0x8008EC48
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
  }
  else {
    MON_PlayAnimFromList
              (instance,*(char **)((int)instance->data + 8),
               (int)*(char *)(*(int *)((int)instance->data + 4) + 0xe),1);
    *(undefined4 *)((int)pvVar2 + 0x108) = 4;
    *(undefined2 *)((int)pvVar2 + 0x12a) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Pursue(struct _Instance *instance /*$s2*/)
 // line 174, offset 0x8008ec5c
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x8008EC5C
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s1
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 195
			// Start offset: 0x8008ECFC
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s1
		// 		struct _MonsterAttackAttributes *attack; // $s3
		/* end block 1.1 */
		// End offset: 0x8008EDEC
		// End Line: 218
	/* end block 1 */
	// End offset: 0x8008EE10
	// End Line: 225

	/* begin block 2 */
		// Start line: 370
	/* end block 2 */
	// End Line: 371

void VWRAITH_Pursue(_Instance *instance)

{
  char cVar1;
  int iVar2;
  _MonsterAnim *p_Var3;
  undefined4 local_18;
  void *pvVar4;
  undefined4 local_14;
  void *pvVar5;
  
  pvVar4 = instance->extraData;
  pvVar5 = instance->data;
  if ((*(uint *)((int)pvVar4 + 4) & 2) == 0) {
    iVar2 = VWRAITH_ShouldISwoop(instance);
    if (iVar2 == 0) {
      if (*(int *)((int)pvVar4 + 0xc4) != 0) {
        VWRAITH_MoveVertical
                  (instance,(int)*(short *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x60),
                   (int)*(short *)(*(int *)((int)pvVar5 + 4) + 6));
      }
      MON_Pursue(instance);
    }
    else {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
  }
  else {
    if (*(int *)((int)pvVar4 + 0xc4) == 0) {
      *(uint *)((int)pvVar4 + 4) = *(uint *)((int)pvVar4 + 4) & 0xfffffffd;
    }
    else {
      cVar1 = *(char *)(*(int *)((int)pvVar5 + 4) + 0x10);
      iVar2 = *(int *)((int)pvVar5 + 0x38);
      MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x5c),
                         *(short *)(*(int *)((int)pvVar4 + 0x168) + 0x20));
      if (*(short *)(*(int *)((int)pvVar4 + 0xc4) + 0x14) <
          *(short *)(*(int *)((int)pvVar5 + 4) + 10)) {
        *(int *)((int)pvVar4 + 0xb8) = iVar2 + (int)cVar1 * 0x20;
        *(undefined *)((int)pvVar4 + 0x15f) = 0;
        *(undefined2 *)((int)pvVar4 + 0x12a) = 0;
        *(uint *)((int)pvVar4 + 4) = *(uint *)((int)pvVar4 + 4) & 0xfffffffd;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
      }
      else {
        if ((instance->flags2 & 0x10U) != 0) {
          p_Var3 = MON_GetAnim(instance,*(char **)((int)pvVar5 + 8),
                               (int)*(char *)(*(int *)((int)pvVar5 + 4) + 0xf));
          *(ushort *)((int)pvVar4 + 0x12a) = p_Var3->velocity;
          MON_PlayAnimFromList
                    (instance,*(char **)((int)pvVar5 + 8),
                     (int)*(char *)(*(int *)((int)pvVar5 + 4) + 0xf),2);
        }
      }
      VWRAITH_MoveVertical
                (instance,(int)*(short *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x60) +
                          (int)*(short *)(*(int *)((int)pvVar5 + 4) + 2),
                 (int)*(short *)(*(int *)((int)pvVar5 + 4) + 4));
      if (*(short *)((int)pvVar4 + 0x12a) != 0) {
        MON_MoveForward(instance);
      }
    }
    MON_DefaultQueueHandler(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_VerticalMove(struct _Instance *instance /*$s0*/)
 // line 230, offset 0x8008ee2c
	/* begin block 1 */
		// Start line: 231
		// Start offset: 0x8008EE2C
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 236
			// Start offset: 0x8008EE58
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		// 		long targetZ; // $s1
		/* end block 1.1 */
		// End offset: 0x8008EE9C
		// End Line: 242
	/* end block 1 */
	// End offset: 0x8008EE9C
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
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_CombatEntry(struct _Instance *instance /*$a0*/)
 // line 248, offset 0x8008eeb0
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
 // line 253, offset 0x8008eed0
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
 // line 263, offset 0x8008eefc
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
 // line 268, offset 0x8008ef1c
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





