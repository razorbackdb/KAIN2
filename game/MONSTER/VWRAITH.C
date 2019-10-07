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
  u_int uVar3;
  int iVar4;
  
  iVar4 = (int)(instance->position).z;
  uVar3 = (u_int)(ushort)(instance->position).z;
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
  _FXGlowEffect *p_Var1;
  int iVar2;
  u_int *puVar3;
  long local_18 [2];
  
  puVar3 = (u_int *)instance->extraData;
  iVar2 = (int)*(short *)(puVar3 + 0x50);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_18[0] = FX_GetHealthColor(iVar2 >> 0xc);
  p_Var1 = FX_DoInstanceManySegmentGlow(instance,0x15,0x17,local_18,1,0x4b0,0x9c);
  *(_FXGlowEffect **)(puVar3 + 0x37) = p_Var1;
  MON_SetDefaults(instance);
  *(undefined2 *)(puVar3 + 0x51) = 0x3000;
  puVar3[1] = puVar3[1] & 0xfffffffe;
  *puVar3 = *puVar3 | 0x10002800;
  return;
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
  u_int uVar1;
  u_int uVar2;
  
  uVar2 = 0;
  if ((((*(u_int *)instance->extraData & 4) == 0) &&
      (uVar1 = *(u_int *)(instance->extraData + 0x31), uVar1 != 0)) &&
     (*(short *)(*(int *)(uVar1 + 4) + 0x60) <= (instance->position).z)) {
    uVar2 = (u_int)(*(short *)(*(int *)((int)instance->data + 4) + 0xc) < *(short *)(uVar1 + 0x14));
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

void MON_PupateEntry(_Instance *instance)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  iVar1 = VWRAITH_ShouldISwoop(instance);
  if (iVar1 != 0) {
    *(u_int *)((int)pvVar2 + 4) = *(u_int *)((int)pvVar2 + 4) | 2;
  }
  if ((*(u_int *)((int)pvVar2 + 4) & 2) == 0) {
    MON_HideEntry(instance);
  }
  else {
    MON_PlayAnimFromListIfNotPlaying
              (instance,*(char **)((int)instance->data + 8),
               (int)*(char *)(*(int *)((int)instance->data + 4) + 0xe),1);
    *(u_char *)((int)pvVar2 + 0x108) = 4;
    *(undefined2 *)((int)pvVar2 + 0x126) = 0;
  }
  return;
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

void VWRAITH_PursueEntry(_Instance *instance)

{
  char cVar1;
  int iVar2;
  _MonsterAnim *p_Var3;
  u_char local_18;
  void *pvVar4;
  u_char local_14;
  void *pvVar5;
  
  pvVar4 = instance->extraData;
  pvVar5 = instance->data;
  if ((*(u_int *)((int)pvVar4 + 4) & 2) == 0) {
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
      *(u_int *)((int)pvVar4 + 4) = *(u_int *)((int)pvVar4 + 4) & 0xfffffffd;
    }
    else {
      cVar1 = *(char *)(*(int *)((int)pvVar5 + 4) + 0x10);
      iVar2 = *(int *)((int)pvVar5 + 0x38);
      MON_MoveToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x5c),
                         *(short *)(*(int *)((int)pvVar4 + 0x164) + 0x20));
      if (*(short *)(*(int *)((int)pvVar4 + 0xc4) + 0x14) <
          *(short *)(*(int *)((int)pvVar5 + 4) + 10)) {
        *(int *)((int)pvVar4 + 0xb8) = iVar2 + (int)cVar1 * 0x20;
        *(undefined *)((int)pvVar4 + 0x15b) = 0;
        *(undefined2 *)((int)pvVar4 + 0x126) = 0;
        *(u_int *)((int)pvVar4 + 4) = *(u_int *)((int)pvVar4 + 4) & 0xfffffffd;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
      }
      else {
        if ((instance->flags2 & 0x10U) != 0) {
          p_Var3 = MON_GetTime(instance,*(char **)((int)pvVar5 + 8),
                               (int)*(char *)(*(int *)((int)pvVar5 + 4) + 0xf));
          *(ushort *)((int)pvVar4 + 0x126) = p_Var3->velocity;
          MON_PlayAnimFromListIfNotPlaying
                    (instance,*(char **)((int)pvVar5 + 8),
                     (int)*(char *)(*(int *)((int)pvVar5 + 4) + 0xf),2);
        }
      }
      VWRAITH_MoveVertical
                (instance,(int)*(short *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x60) +
                          (int)*(short *)(*(int *)((int)pvVar5 + 4) + 2),
                 (int)*(short *)(*(int *)((int)pvVar5 + 4) + 4));
      if (*(short *)((int)pvVar4 + 0x126) != 0) {
        MON_MoveForward(instance);
      }
    }
    MON_DefaultMessageHandler(instance);
  }
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
  u_char local_10;
  u_char local_c;
  
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

void MON_CombatEntry(_Instance *instance)

{
  wombat(instance);
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

void VWRAITH_Embrace(_Instance *instance)

{
  MON_Embrace(instance);
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

void VWRAITH_EmbraceEntry(_Instance *instance)

{
  MON_EmbraceEntry(instance);
  VWRAITH_VerticalMove(instance);
  return;
}





