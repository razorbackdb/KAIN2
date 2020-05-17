#include "THISDUST.H"
#include "SLUAGH.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SLUAGH_Query(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 48, offset 0x8008d208
	/* begin block 1 */
		// Start line: 49
		// Start offset: 0x8008D208
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		struct _MonsterAttributes *ma; // $a2
	// 		unsigned long ret; // $v0
	/* end block 1 */
	// End offset: 0x8008D28C
	// End Line: 79

	/* begin block 2 */
		// Start line: 96
	/* end block 2 */
	// End Line: 97

ulong SLUAGH_Query(_Instance *instance,ulong query)

{
  ulong uVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  if (query == 0) {
    if ((*(uint *)((int)pvVar2 + 4) & 1) == 0) {
      uVar1 = ((uint)*(byte *)((int)pvVar2 + 1) & 1) << 0x1d;
    }
    else {
      uVar1 = 0x4000000;
    }
  }
  else {
    if (query == 1) {
      if ((*(uint *)((int)pvVar2 + 4) & 1) == 0) {
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
// void /*$ra*/ SLUAGH_DamageEffect(struct _Instance *instance /*$s2*/, struct evFXHitData *data /*$s1*/)
 // line 84, offset 0x8008d29c
	/* begin block 1 */
		// Start line: 85
		// Start offset: 0x8008D29C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 92
			// Start offset: 0x8008D2D8
			// Variables:
		// 		struct _SVector accel; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x8008D2D8
		// End Line: 92

		/* begin block 1.2 */
			// Start line: 100
			// Start offset: 0x8008D334
			// Variables:
		// 		struct _FXGlowEffect *fx; // $s1

			/* begin block 1.2.1 */
				// Start line: 104
				// Start offset: 0x8008D344
				// Variables:
			// 		long color; // stack offset -24

				/* begin block 1.2.1.1 */
					// Start line: 108
					// Start offset: 0x8008D370
					// Variables:
				// 		struct _ColorType current; // stack offset -40
				// 		struct _ColorType target; // stack offset -32
				/* end block 1.2.1.1 */
				// End offset: 0x8008D41C
				// End Line: 127
			/* end block 1.2.1 */
			// End offset: 0x8008D41C
			// End Line: 128
		/* end block 1.2 */
		// End offset: 0x8008D478
		// End Line: 138
	/* end block 1 */
	// End offset: 0x8008D478
	// End Line: 139

	/* begin block 2 */
		// Start line: 168
	/* end block 2 */
	// End Line: 169

/* WARNING: Could not reconcile some variable overlaps */

void SLUAGH_DamageEffect(_Instance *instance,evFXHitData *data)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 local_28;
  undefined *local_24;
  undefined4 local_20;
  uint local_18;
  
  puVar4 = (uint *)instance->extraData;
  if (data == (evFXHitData *)0x0) {
    uVar5 = puVar4[0x37];
    if (uVar5 != 0) {
      iVar3 = (int)*(short *)(puVar4 + 0x51);
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
    if (((puVar4[1] & 1) != 0) && (*(short *)(puVar4 + 0x51) != 0)) {
      *puVar4 = *puVar4 & 0xffdfffff;
      *(undefined *)((int)puVar4 + 0x15a) = *(undefined *)(puVar4 + 0x57);
      puVar4[1] = puVar4[1] & 0xfffffffe;
      MON_StartSpecialFade(instance,0,0x14);
    }
  }
  else {
    if ((puVar4[1] & 1) == 0) {
      local_28 = 0;
      local_24 = &DAT_0000fffe;
      FX_Blood((_SVector *)data,&data->velocity,(_SVector *)&local_28,(int)data->amount,0x308000,8);
      FX_MakeHitFX((_SVector *)data);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_Init(struct _Instance *instance /*$s2*/)
 // line 145, offset 0x8008d490
	/* begin block 1 */
		// Start line: 146
		// Start offset: 0x8008D490
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s1
	// 		long color; // stack offset -24
	/* end block 1 */
	// End offset: 0x8008D4C4
	// End Line: 149

	/* begin block 2 */
		// Start line: 298
	/* end block 2 */
	// End Line: 299

void SLUAGH_Init(_Instance *instance)

{
  _FXGlowEffect *p_Var1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  long local_18 [2];
  
  puVar3 = (uint *)instance->extraData;
  iVar2 = (int)*(short *)(puVar3 + 0x51);
  pvVar4 = instance->data;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_18[0] = FX_GetHealthColor(iVar2 >> 0xc);
  p_Var1 = FX_DoInstanceOneSegmentGlow
                     (instance,(uint)*(byte *)((int)pvVar4 + 0x19),local_18,1,0x4b0,0x68,0x70);
  *(_FXGlowEffect **)(puVar3 + 0x37) = p_Var1;
  MON_DefaultInit(instance);
  *(undefined2 *)(puVar3 + 0x52) = 0x2000;
  puVar3[1] = puVar3[1] & 0xfffffffe;
  *puVar3 = *puVar3 | 0x2002000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_DeathEntry(struct _Instance *instance /*$s1*/)
 // line 170, offset 0x8008d54c
	/* begin block 1 */
		// Start line: 171
		// Start offset: 0x8008D54C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008D5DC
	// End Line: 192

	/* begin block 2 */
		// Start line: 365
	/* end block 2 */
	// End Line: 366

void SLUAGH_DeathEntry(_Instance *instance)

{
  int iVar1;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  puVar2 = (uint *)instance->extraData;
  FX_StopGlowEffect((_FXGlowEffect *)puVar2[0x37],0);
  puVar2[0x37] = 0;
  if (puVar2[0x31] != 0) {
    iVar1 = MON_SetUpKnockBack(instance,*(_Instance **)(puVar2[0x31] + 4),
                               (evMonsterHitData *)puVar2[0x30]);
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
                 (uint)(iVar1 == 0));
  }
  *(undefined *)((int)puVar2 + 0x15a) = 9;
  if ((puVar2[1] & 1) == 0) {
    MON_BirthMana(instance);
    puVar2[1] = puVar2[1] | 1;
  }
  *puVar2 = *puVar2 | 0x200000;
  MON_StartSpecialFade(instance,0x800,0x14);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_Death(struct _Instance *instance /*$s0*/)
 // line 195, offset 0x8008d610
	/* begin block 1 */
		// Start line: 196
		// Start offset: 0x8008D610

		/* begin block 1.1 */
			// Start line: 202
			// Start offset: 0x8008D650
			// Variables:
		// 		struct _MonsterVars *mv; // $v0
		/* end block 1.1 */
		// End offset: 0x8008D680
		// End Line: 207
	/* end block 1 */
	// End offset: 0x8008D680
	// End Line: 209

	/* begin block 2 */
		// Start line: 417
	/* end block 2 */
	// End Line: 418

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void SLUAGH_Death(_Instance *instance)

{
  undefined4 local_8;
  undefined4 local_4;
  undefined8 uStackX0;
  
  if ((instance->flags2 & 0x10U) != 0) {
    MON_PlayAnim(instance,(MonsterAnim)CONCAT88(uStackX0,CONCAT44(local_4,local_8)),0x18);
  }
  if ((instance->flags2 & 2U) != 0) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_4,local_8));
  }
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SLUAGH_AttackEntry(struct _Instance *instance /*$a0*/)
 // line 217, offset 0x8008d698
	/* begin block 1 */
		// Start line: 218
		// Start offset: 0x8008D698
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008D6EC
	// End Line: 229

	/* begin block 2 */
		// Start line: 461
	/* end block 2 */
	// End Line: 462

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
// void /*$ra*/ SLUAGH_Attack(struct _Instance *instance /*$s2*/)
 // line 231, offset 0x8008d6fc
	/* begin block 1 */
		// Start line: 232
		// Start offset: 0x8008D6FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 237
			// Start offset: 0x8008D730
			// Variables:
		// 		struct __Event *mess; // $a1

			/* begin block 1.1.1 */
				// Start line: 253
				// Start offset: 0x8008D79C
				// Variables:
			// 		struct _MonsterAttributes *ma; // $s0
			// 		long color; // stack offset -24
			/* end block 1.1.1 */
			// End offset: 0x8008D7EC
			// End Line: 259
		/* end block 1.1 */
		// End offset: 0x8008D83C
		// End Line: 272
	/* end block 1 */
	// End offset: 0x8008D878
	// End Line: 278

	/* begin block 2 */
		// Start line: 489
	/* end block 2 */
	// End Line: 490

/* WARNING: Type propagation algorithm not settling */

void SLUAGH_Attack(_Instance *instance)

{
  __Event *message;
  _FXGlowEffect *p_Var1;
  int Data;
  void *pvVar2;
  void *pvVar3;
  undefined4 local_28;
  undefined4 local_24;
  long local_18 [2];
  
  pvVar3 = instance->extraData;
  if ((*(uint *)((int)pvVar3 + 4) & 4) == 0) {
    MON_Attack(instance);
    return;
  }
  if ((instance->flags2 & 0x10U) == 0) goto LAB_8008d74c;
  do {
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_24,local_28));
LAB_8008d74c:
    do {
      while( true ) {
        message = DeMessageQueue((__MessageQueue *)((int)pvVar3 + 8));
        if (message == (__Event *)0x0) {
          if ((instance->currentMainState == 6) && (*(int *)((int)pvVar3 + 0xc4) != 0)) {
            Data = SetMonsterSoulSuckData
                             (instance,(int)(instance->position).x,(int)(instance->position).y,
                              (int)(instance->position).z);
            INSTANCE_Post(*(_Instance **)(*(int *)((int)pvVar3 + 0xc4) + 4),0x1000009,Data);
            return;
          }
          *(uint *)((int)pvVar3 + 4) = *(uint *)((int)pvVar3 + 4) & 0xfffffffb;
          return;
        }
        if (message->ID == 0x1000009) break;
        MON_DefaultMessageHandler(instance,message);
      }
    } while (*(_Instance **)&((_Instance *)message->Data)->node == gameTrackerX.playerInstance);
    if (*(int *)((int)pvVar3 + 0xdc) == 0) {
      Data = (int)*(short *)((int)pvVar3 + 0x144);
      pvVar2 = instance->data;
      if (Data < 0) {
        Data = Data + 0xfff;
      }
      local_18[0] = FX_GetHealthColor(Data >> 0xc);
      local_28 = 0x4b0;
      local_24 = 0x68;
      p_Var1 = FX_DoInstanceOneSegmentGlow
                         (instance,(uint)*(byte *)((int)pvVar2 + 0x19),local_18,1,0x4b0,0x68,0x70);
      *(_FXGlowEffect **)((int)pvVar3 + 0xdc) = p_Var1;
    }
  } while( true );
}





