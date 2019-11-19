#include "THISDUST.H"
#include "VWRAITH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_MoveVertical(struct _Instance *instance /*$a0*/, long targetZ /*$a1*/, int velocity /*$a2*/)
 // line 88, offset 0x8008cd60
	/* begin block 1 */
		// Start line: 176
	/* end block 1 */
	// End Line: 177

	/* begin block 2 */
		// Start line: 177
	/* end block 2 */
	// End Line: 178

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
// void /*$ra*/ VWRAITH_Init(struct _Instance *instance /*$s2*/)
 // line 107, offset 0x8008cdb8
	/* begin block 1 */
		// Start line: 108
		// Start offset: 0x8008CDB8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s1
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8008CDEC
	// End Line: 111

	/* begin block 2 */
		// Start line: 214
	/* end block 2 */
	// End Line: 215

void VWRAITH_Init(_Instance *instance)

{
  _FXGlowEffect *p_Var1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  long local_18 [2];
  
  puVar3 = (uint *)instance->extraData;
  iVar2 = (int)*(short *)(puVar3 + 0x50);
  pvVar4 = instance->data;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_18[0] = FX_GetHealthColor(iVar2 >> 0xc);
  p_Var1 = FX_DoInstanceOneSegmentGlow
                     (instance,(uint)*(byte *)((int)pvVar4 + 0x19),local_18,1,0x4b0,
                      (int)**(short **)((int)pvVar4 + 4),(int)**(short **)((int)pvVar4 + 4));
  *(_FXGlowEffect **)(puVar3 + 0x37) = p_Var1;
  MON_DefaultInit(instance);
  *(undefined2 *)(puVar3 + 0x51) = 0x3000;
  puVar3[1] = puVar3[1] & 0xfffffffe;
  *puVar3 = *puVar3 | 0x10002800;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VWRAITH_ShouldISwoop(struct _Instance *instance /*$a0*/)
 // line 127, offset 0x8008ce80
	/* begin block 1 */
		// Start line: 129
		// Start offset: 0x8008CE80
		// Variables:
	// 		struct _MonsterAttributes *ma; // $a3
	// 		struct _MonsterVars *mv; // $v1
	/* end block 1 */
	// End offset: 0x8008CEDC
	// End Line: 132

	/* begin block 2 */
		// Start line: 269
	/* end block 2 */
	// End Line: 270

	/* begin block 3 */
		// Start line: 270
	/* end block 3 */
	// End Line: 271

	/* begin block 4 */
		// Start line: 271
	/* end block 4 */
	// End Line: 272

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
 // line 140, offset 0x8008cee4
	/* begin block 1 */
		// Start line: 141
		// Start offset: 0x8008CEE4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 155
			// Start offset: 0x8008CF40
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		/* end block 1.1 */
		// End offset: 0x8008CF68
		// End Line: 160
	/* end block 1 */
	// End offset: 0x8008CF68
	// End Line: 161

	/* begin block 2 */
		// Start line: 298
	/* end block 2 */
	// End Line: 299

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
    *(undefined2 *)((int)pvVar2 + 0x126) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Pursue(struct _Instance *instance /*$s2*/)
 // line 163, offset 0x8008cf7c
	/* begin block 1 */
		// Start line: 164
		// Start offset: 0x8008CF7C
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s1
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 184
			// Start offset: 0x8008D01C
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s1
		// 		struct _MonsterAttackAttributes *attack; // $s3
		/* end block 1.1 */
		// End offset: 0x8008D10C
		// End Line: 207
	/* end block 1 */
	// End offset: 0x8008D130
	// End Line: 214

	/* begin block 2 */
		// Start line: 344
	/* end block 2 */
	// End Line: 345

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
      iVar2 = *(int *)((int)pvVar5 + 0x3c);
      MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar4 + 0xc4) + 4) + 0x5c),
                         *(short *)(*(int *)((int)pvVar4 + 0x164) + 0x20));
      if (*(short *)(*(int *)((int)pvVar4 + 0xc4) + 0x14) <
          *(short *)(*(int *)((int)pvVar5 + 4) + 10)) {
        *(int *)((int)pvVar4 + 0xb8) = iVar2 + (int)cVar1 * 0x20;
        *(undefined *)((int)pvVar4 + 0x15b) = 0;
        *(undefined2 *)((int)pvVar4 + 0x126) = 0;
        *(uint *)((int)pvVar4 + 4) = *(uint *)((int)pvVar4 + 4) & 0xfffffffd;
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
      }
      else {
        if ((instance->flags2 & 0x10U) != 0) {
          p_Var3 = MON_GetAnim(instance,*(char **)((int)pvVar5 + 8),
                               (int)*(char *)(*(int *)((int)pvVar5 + 4) + 0xf));
          *(ushort *)((int)pvVar4 + 0x126) = p_Var3->velocity;
          MON_PlayAnimFromList
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
    MON_DefaultQueueHandler(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_CombatEntry(struct _Instance *instance /*$a0*/)
 // line 219, offset 0x8008d14c
	/* begin block 1 */
		// Start line: 468
	/* end block 1 */
	// End Line: 469

void VWRAITH_CombatEntry(_Instance *instance)

{
  MON_CombatEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VWRAITH_Combat(struct _Instance *instance /*$s1*/)
 // line 224, offset 0x8008d16c
	/* begin block 1 */
		// Start line: 225
		// Start offset: 0x8008D16C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 232
			// Start offset: 0x8008D19C
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v0
		// 		long targetZ; // $s0
		/* end block 1.1 */
		// End offset: 0x8008D1E0
		// End Line: 238
	/* end block 1 */
	// End offset: 0x8008D1E0
	// End Line: 239

	/* begin block 2 */
		// Start line: 478
	/* end block 2 */
	// End Line: 479

void VWRAITH_Combat(_Instance *instance)

{
  int targetZ;
  undefined4 local_10;
  void *pvVar1;
  undefined4 local_c;
  
  pvVar1 = instance->extraData;
  MON_Combat(instance);
  targetZ = *(int *)((int)pvVar1 + 0xc4);
  if (targetZ != 0) {
    targetZ = (int)*(short *)(*(int *)(targetZ + 4) + 0x60);
    VWRAITH_MoveVertical(instance,targetZ,(int)*(short *)(*(int *)((int)instance->data + 4) + 8));
    if ((instance->currentMainState == 6) && ((int)(instance->position).z != targetZ)) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
  }
  return;
}





