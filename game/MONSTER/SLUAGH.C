#include "THISDUST.H"
#include "SLUAGH.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SLUAGH_Query(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 47, offset 0x8008b780
	/* begin block 1 */
		// Start line: 48
		// Start offset: 0x8008B780
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		struct _MonsterAttributes *ma; // $a2
	// 		unsigned long ret; // $v0
	/* end block 1 */
	// End offset: 0x8008B7FC
	// End Line: 78

	/* begin block 2 */
		// Start line: 94
	/* end block 2 */
	// End Line: 95

ulong SLUAGH_Query(_Instance *instance,ulong query)

{
  ulong uVar1;
  uint uVar2;
  
  if (query == 0) {
    uVar2 = *(uint *)instance->extraData;
    if ((uVar2 & 0x200) == 0) {
      uVar1 = (uint)((uVar2 & 0x100) != 0) << 0x1d;
    }
    else {
      uVar1 = 0x40000000;
    }
  }
  else {
    if (query == 1) {
      if ((*(uint *)(instance->extraData + 1) & 1) == 0) {
        uVar1 = *(ulong *)((int)instance->data + 0x10);
      }
      else {
        uVar1 = *(uint *)((int)instance->data + 0x10) | 4;
      }
    }
    else {
      uVar1 = MonsterQuery(instance,query);
    }
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_DamageEffect(struct _Instance *instance /*$s2*/, struct evFXHitData *data /*$s0*/)
 // line 83, offset 0x8008b80c
	/* begin block 1 */
		// Start line: 84
		// Start offset: 0x8008B80C

		/* begin block 1.1 */
			// Start line: 87
			// Start offset: 0x8008B82C
			// Variables:
		// 		struct _SVector accel; // stack offset -48
		/* end block 1.1 */
		// End offset: 0x8008B82C
		// End Line: 87

		/* begin block 1.2 */
			// Start line: 93
			// Start offset: 0x8008B88C
			// Variables:
		// 		struct _MonsterVars *mv; // $s0
		// 		struct _FXGlowEffect *fx; // $s1

			/* begin block 1.2.1 */
				// Start line: 99
				// Start offset: 0x8008B8A4
				// Variables:
			// 		long color; // stack offset -24

				/* begin block 1.2.1.1 */
					// Start line: 103
					// Start offset: 0x8008B8D0
					// Variables:
				// 		struct _ColorType current; // stack offset -40
				// 		struct _ColorType target; // stack offset -32
				/* end block 1.2.1.1 */
				// End offset: 0x8008B97C
				// End Line: 122
			/* end block 1.2.1 */
			// End offset: 0x8008B97C
			// End Line: 123
		/* end block 1.2 */
		// End offset: 0x8008B9D8
		// End Line: 133
	/* end block 1 */
	// End offset: 0x8008B9D8
	// End Line: 134

	/* begin block 2 */
		// Start line: 166
	/* end block 2 */
	// End Line: 167

/* WARNING: Could not reconcile some variable overlaps */

void SLUAGH_DamageEffect(_Instance *instance,evFXHitData *data)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  uint local_18;
  
  if (data == (evFXHitData *)0x0) {
    puVar4 = (uint *)instance->extraData;
    uVar5 = puVar4[0x37];
    if (uVar5 != 0) {
      iVar3 = (int)*(short *)(puVar4 + 0x50);
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0xfff;
      }
      local_18 = FX_GetHealthColor(iVar3 >> 0xc);
      if (*(uint *)(uVar5 + 0x18) != local_18) {
        local_28 = *(uint *)(uVar5 + 0x18);
        bVar1 = (char)local_28 - 4;
        if (((local_18 & 0xff) < (local_28 & 0xff)) ||
           (bVar1 = (char)local_28 + 4, (local_28 & 0xff) < (local_18 & 0xff))) {
          local_28 = local_28 & 0xffffff00 | (uint)bVar1;
        }
        local_20._1_1_ = (byte)(local_18 >> 8);
        cVar2 = local_28._1_1_ - 4;
        if ((local_20._1_1_ < local_28._1_1_) ||
           (cVar2 = local_28._1_1_ + 4, local_28._1_1_ < local_20._1_1_)) {
          local_28._0_2_ = CONCAT11(cVar2,(char)local_28);
          local_28 = local_28 & 0xffff0000 | (uint)(ushort)local_28;
        }
        local_20._2_1_ = (byte)(local_18 >> 0x10);
        cVar2 = local_28._2_1_ - 4;
        if ((local_20._2_1_ < local_28._2_1_) ||
           (cVar2 = local_28._2_1_ + 4, local_28._2_1_ < local_20._2_1_)) {
          local_28._0_3_ = CONCAT12(cVar2,(ushort)local_28);
          local_28 = local_28 & 0xff000000 | (uint)(uint3)local_28;
        }
        *(uint *)(uVar5 + 0x18) = local_28;
        local_20 = local_18;
      }
    }
    if (((puVar4[1] & 1) != 0) && (*(short *)(puVar4 + 0x50) != 0)) {
      *puVar4 = *puVar4 & 0xffdfffff;
      *(undefined *)((int)puVar4 + 0x156) = *(undefined *)(puVar4 + 0x56);
      puVar4[1] = puVar4[1] & 0xfffffffe;
      MON_StartSpecialFade(instance,0,0x14);
    }
  }
  else {
    local_30 = 0;
    local_2c = 0xfffe;
    FX_Blood((_SVector *)data,&data->velocity,(_SVector *)&local_30,(int)data->amount,0x308000,8);
    FX_MakeHitFX((_SVector *)data);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_Init(struct _Instance *instance /*$s1*/)
 // line 140, offset 0x8008b9f0
	/* begin block 1 */
		// Start line: 141
		// Start offset: 0x8008B9F0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s2
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8008BA24
	// End Line: 144

	/* begin block 2 */
		// Start line: 288
	/* end block 2 */
	// End Line: 289

void SLUAGH_Init(_Instance *instance)

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
                     (instance,(uint)*(byte *)((int)pvVar4 + 0x19),local_18,1,0x4b0,0x96,0x96);
  *(_FXGlowEffect **)(puVar3 + 0x37) = p_Var1;
  MON_DefaultInit(instance);
  *(undefined2 *)(puVar3 + 0x51) = 0x2000;
  puVar3[1] = puVar3[1] & 0xfffffffe;
  *puVar3 = *puVar3 | 0x2002000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_DeathEntry(struct _Instance *instance /*$s1*/)
 // line 162, offset 0x8008baa8
	/* begin block 1 */
		// Start line: 163
		// Start offset: 0x8008BAA8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008BB10
	// End Line: 177

	/* begin block 2 */
		// Start line: 349
	/* end block 2 */
	// End Line: 350

void SLUAGH_DeathEntry(_Instance *instance)

{
  undefined4 local_10;
  uint *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  puVar1 = (uint *)instance->extraData;
  FX_StopGlowEffect((_FXGlowEffect *)puVar1[0x37],0);
  puVar1[0x37] = 0;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
               0x18);
  *(undefined *)((int)puVar1 + 0x156) = 9;
  if ((puVar1[1] & 1) == 0) {
    MON_BirthMana(instance);
    puVar1[1] = puVar1[1] | 1;
  }
  *puVar1 = *puVar1 | 0x200000;
  MON_StartSpecialFade(instance,0x800,0x14);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_Death(struct _Instance *instance /*$s0*/)
 // line 180, offset 0x8008bb44
	/* begin block 1 */
		// Start line: 181
		// Start offset: 0x8008BB44

		/* begin block 1.1 */
			// Start line: 184
			// Start offset: 0x8008BB68
			// Variables:
		// 		struct _MonsterVars *mv; // $v0
		/* end block 1.1 */
		// End offset: 0x8008BB90
		// End Line: 189
	/* end block 1 */
	// End offset: 0x8008BB90
	// End Line: 191

	/* begin block 2 */
		// Start line: 387
	/* end block 2 */
	// End Line: 388

void SLUAGH_Death(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  
  if ((instance->flags2 & 0x10U) != 0) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_retaddr,unaff_s0));
  }
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_AttackEntry(struct _Instance *instance /*$a0*/)
 // line 199, offset 0x8008bba8
	/* begin block 1 */
		// Start line: 200
		// Start offset: 0x8008BBA8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008BBFC
	// End Line: 211

	/* begin block 2 */
		// Start line: 425
	/* end block 2 */
	// End Line: 426

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void SLUAGH_AttackEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_retaddr;
  undefined8 uStackX0;
  
  pvVar1 = instance->extraData;
  if ((*(ushort *)(*(int *)((int)pvVar1 + 0xc4) + 0x16) & 8) == 0) {
    MON_AttackEntry(instance);
  }
  else {
    MON_PlayAnim(instance,(MonsterAnim)CONCAT88(uStackX0,CONCAT44(unaff_retaddr,unaff_s0)),0x1e);
    *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) | 4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_Attack(struct _Instance *instance /*$s0*/)
 // line 213, offset 0x8008bc0c
	/* begin block 1 */
		// Start line: 214
		// Start offset: 0x8008BC0C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 219
			// Start offset: 0x8008BC40
			// Variables:
		// 		struct __Event *mess; // $a1
		/* end block 1.1 */
		// End offset: 0x8008BCF8
		// End Line: 241
	/* end block 1 */
	// End offset: 0x8008BD34
	// End Line: 247

	/* begin block 2 */
		// Start line: 453
	/* end block 2 */
	// End Line: 454

/* WARNING: Type propagation algorithm not settling */

void SLUAGH_Attack(_Instance *instance)

{
  __Event *message;
  int Data;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  if ((*(uint *)((int)pvVar1 + 4) & 4) == 0) {
    MON_Attack(instance);
  }
  else {
    if ((instance->flags2 & 0x10U) != 0) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
    while (message = DeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0)
    {
      if (message->ID == 0x1000009) {
        if (*(_Instance **)&((_Instance *)message->Data)->node != gameTrackerX.playerInstance) {
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
        }
      }
      else {
        MON_DefaultMessageHandler(instance,message);
      }
    }
    if ((instance->currentMainState == 6) && (*(int *)((int)pvVar1 + 0xc4) != 0)) {
      Data = SetMonsterSoulSuckData
                       (instance,(int)(instance->position).x,(int)(instance->position).y,
                        (int)(instance->position).z);
      INSTANCE_Post(*(_Instance **)(*(int *)((int)pvVar1 + 0xc4) + 4),0x1000009,Data);
    }
    else {
      *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffffb;
    }
  }
  return;
}





