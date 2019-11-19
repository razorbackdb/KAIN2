#include "THISDUST.H"
#include "MONSTER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MON_DoCombatTimers(struct _Instance *instance /*$s2*/)
 // line 87, offset 0x80085cd8
	/* begin block 1 */
		// Start line: 88
		// Start offset: 0x80085CD8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		unsigned long curtime; // $s1

		/* begin block 1.1 */
			// Start line: 103
			// Start offset: 0x80085D5C
			// Variables:
		// 		struct _MonsterCombatAttributes *combat; // $v0
		/* end block 1.1 */
		// End offset: 0x80085DCC
		// End Line: 112
	/* end block 1 */
	// End offset: 0x80085EA8
	// End Line: 128

	/* begin block 2 */
		// Start line: 174
	/* end block 2 */
	// End Line: 175

void MON_DoCombatTimers(_Instance *instance)

{
  ulong uVar1;
  int amount;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  uVar1 = MON_GetTime(instance);
  uVar2 = *puVar3;
  if ((uVar2 & 0x10) == 0) {
    if (((uVar2 & 0x2000) == 0) && (*(short *)(puVar3 + 0x50) < *(short *)((int)puVar3 + 0x142))) {
      amount = (uint)*(ushort *)(puVar3 + 0x50) +
               ((int)*(short *)(*(int *)(puVar3[0x59] + 8) + 4) * gameTrackerX.idleTime >> 0xc);
      *(short *)(puVar3 + 0x50) = (short)amount;
      if ((int)*(short *)((int)puVar3 + 0x142) < amount * 0x10000 >> 0x10) {
        *(undefined2 *)(puVar3 + 0x50) = *(undefined2 *)((int)puVar3 + 0x142);
      }
      amount = MONSTER_CalcDamageIntensity
                         ((int)*(short *)(puVar3 + 0x50),(int)*(short *)((int)puVar3 + 0x142));
      MONSTER_VertexBlood(instance,(int)*(short *)(puVar3 + 0x52),amount);
    }
  }
  else {
    if (puVar3[0x43] < uVar1) {
      *puVar3 = uVar2 & 0xff7fffef;
    }
  }
  if (((*puVar3 & 0x100) != 0) && (puVar3[0x44] < uVar1)) {
    *puVar3 = *puVar3 & 0xfffffeff;
  }
  if (uVar1 % 1000 < (uVar1 - gameTrackerX.totalTime) % 1000) {
    amount = rand();
    *(char *)((int)puVar3 + 0x161) = (char)amount + (char)(amount / 100) * -100;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ChangeHumanOpinion(struct _Instance *instance /*$s2*/)
 // line 133, offset 0x80085ec0
	/* begin block 1 */
		// Start line: 134
		// Start offset: 0x80085EC0
		// Variables:
	// 		struct _MonsterIR *human; // $s1
	// 		int opinion; // $s0
	// 		int good; // $s3
	/* end block 1 */
	// End offset: 0x80085F64
	// End Line: 163

	/* begin block 2 */
		// Start line: 270
	/* end block 2 */
	// End Line: 271

void MON_ChangeHumanOpinion(_Instance *instance)

{
  _MonsterIR *p_Var1;
  ulong uVar2;
  short sVar3;
  int iVar4;
  
  p_Var1 = MONSENSE_FindHumanIR((_MonsterVars *)instance->extraData);
  iVar4 = (int)GlobalSave->humanOpinionOfRaziel;
  uVar2 = INSTANCE_Query(instance,1);
  if ((p_Var1 != (_MonsterIR *)0x0) &&
     (p_Var1 = MONSENSE_FindIR((_MonsterVars *)p_Var1->instance->extraData,instance),
     p_Var1 != (_MonsterIR *)0x0)) {
    if ((uVar2 & 0xc000) == 0) {
      if (iVar4 < 0x7fff) {
        iVar4 = iVar4 + 1;
      }
    }
    else {
      if (-0x7fff < iVar4) {
        iVar4 = iVar4 + -1;
      }
    }
  }
  sVar3 = (short)iVar4;
  if (((uVar2 & 0xc000) != 0) && (-0x7fff < iVar4)) {
    sVar3 = sVar3 + -1;
  }
  GlobalSave->humanOpinionOfRaziel = sVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CutOut_Monster(struct _Instance *instance /*$s2*/, int fade_amount /*$t4*/, int startseg /*$a2*/, int endseg /*$a3*/)
 // line 167, offset 0x80085f8c
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x80085F8C
		// Variables:
	// 		struct _SVector point; // stack offset -56
	// 		struct _SVector normal; // stack offset -48
	// 		struct _SVector p1; // stack offset -40
	// 		struct _SVector p2; // stack offset -32
	// 		int tmp; // $t0
	// 		struct MATRIX *mat; // $a0

		/* begin block 1.1 */
			// Start line: 194
			// Start offset: 0x800860C0
			// Variables:
		// 		long color; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 194
				// Start offset: 0x800860C0
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a1
			// 		short _x1; // $a2
			// 		short _y1; // $a3
			// 		short _z1; // $t0
			// 		struct _SVector *_v; // $a0
			/* end block 1.1.1 */
			// End offset: 0x800860C0
			// End Line: 194
		/* end block 1.1 */
		// End offset: 0x80086168
		// End Line: 205
	/* end block 1 */
	// End offset: 0x80086168
	// End Line: 207

	/* begin block 2 */
		// Start line: 339
	/* end block 2 */
	// End Line: 340

void MON_CutOut_Monster(_Instance *instance,int fade_amount,int startseg,int endseg)

{
  int iVar1;
  int iVar2;
  MATRIX *pMVar3;
  MATRIX *pMVar4;
  short local_38;
  short local_36;
  short local_34;
  _SVector local_30;
  short local_28;
  short local_26;
  short local_24;
  short local_20;
  short local_1e;
  short local_1c;
  long local_18 [2];
  
  pMVar3 = instance->matrix + startseg;
  pMVar4 = instance->matrix + endseg;
  iVar1 = (int)*(short *)pMVar3->t - (int)*(short *)pMVar4->t;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 7;
  }
  iVar2 = (int)*(short *)(pMVar3->t + 1) - (int)*(short *)(pMVar4->t + 1);
  local_20 = (short)(iVar1 >> 3);
  local_28 = *(short *)pMVar3->t + local_20;
  local_20 = *(short *)pMVar4->t - local_20;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 7;
  }
  iVar1 = (int)*(short *)(pMVar3->t + 2) - (int)*(short *)(pMVar4->t + 2);
  local_1e = (short)(iVar2 >> 3);
  local_26 = *(short *)(pMVar3->t + 1) + local_1e;
  local_1e = *(short *)(pMVar4->t + 1) - local_1e;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 7;
  }
  local_1c = (short)(iVar1 >> 3);
  local_24 = *(short *)(pMVar3->t + 2) + local_1c;
  local_1c = *(short *)(pMVar4->t + 2) - local_1c;
  LoadAverageShort12((uint *)&local_20,(uint *)&local_28,fade_amount,0x1000 - fade_amount,
                     (uint *)&local_38);
  if (((instance->halvePlane).flags & 8U) == 0) {
    local_18[0] = 0;
    local_30.x = local_20 - local_28;
    local_30.y = local_1e - local_26;
    local_30.z = local_1c - local_24;
    CAMERA_Normalize(&local_30);
    FX_DoInstancePowerRing(instance,2000,local_18,0,2);
    local_18[0] = 0x80ff;
    FX_DoInstancePowerRing(instance,2000,local_18,0,1);
    (instance->halvePlane).flags = 8;
    (instance->halvePlane).a = local_30.x;
    (instance->halvePlane).b = local_30.y;
    (instance->halvePlane).c = local_30.z;
  }
  (instance->halvePlane).d =
       -((int)(instance->halvePlane).a * (int)local_38 +
         (int)(instance->halvePlane).b * (int)local_36 +
         (int)(instance->halvePlane).c * (int)local_34 >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DeadEntry(struct _Instance *instance /*$s1*/)
 // line 221, offset 0x800861d0
	/* begin block 1 */
		// Start line: 222
		// Start offset: 0x800861D0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80086298
	// End Line: 245

	/* begin block 2 */
		// Start line: 480
	/* end block 2 */
	// End Line: 481

void MON_DeadEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  puVar2 = (uint *)instance->extraData;
  MON_TurnOffAllSpheres(instance);
  if ((puVar2[0x31] != 0) &&
     (uVar1 = INSTANCE_Query(*(_Instance **)(puVar2[0x31] + 4),1), (uVar1 & 1) != 0)) {
    MON_ChangeHumanOpinion(instance);
  }
  if (*(char *)((int)puVar2 + 0x155) == -1) {
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
                 0x24);
  }
  *puVar2 = *puVar2 | 0x200;
  instance->flags2 = instance->flags2 & 0xffffffbf;
  if ((puVar2[0x36] == 0) && (*(short *)(puVar2 + 0x51) != 0)) {
    MON_BirthSoul(instance,1);
  }
  else {
    uVar1 = MON_GetTime(instance);
    puVar2[0x43] = uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Dead(struct _Instance *instance /*$s2*/)
 // line 247, offset 0x800862ac
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x800862AC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _Instance *soul; // $s5
	// 		struct __Event *message; // $v0
	// 		int reanimate; // $s6

		/* begin block 1.1 */
			// Start line: 266
			// Start offset: 0x80086324
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s0
		// 		int fade_amount; // $a1
		/* end block 1.1 */
		// End offset: 0x80086358
		// End Line: 278

		/* begin block 1.2 */
			// Start line: 294
			// Start offset: 0x800863D8
			// Variables:
		// 		struct _Model *model; // $s0
		// 		int i; // $s0
		// 		struct CVECTOR *ptr; // $v0
		/* end block 1.2 */
		// End offset: 0x80086428
		// End Line: 302

		/* begin block 1.3 */
			// Start line: 305
			// Start offset: 0x80086450
			// Variables:
		// 		struct _Instance *imp; // $s0
		// 		struct _Instance *closest; // $s4
		// 		long closestdist; // $s3

			/* begin block 1.3.1 */
				// Start line: 313
				// Start offset: 0x800864A4
				// Variables:
			// 		long dist; // $v1
			/* end block 1.3.1 */
			// End offset: 0x800864E4
			// End Line: 320

			/* begin block 1.3.2 */
				// Start line: 325
				// Start offset: 0x800864FC
				// Variables:
			// 		struct _MonsterAttributes *ma; // $v0
			/* end block 1.3.2 */
			// End offset: 0x800864FC
			// End Line: 325
		/* end block 1.3 */
		// End offset: 0x80086558
		// End Line: 333

		/* begin block 1.4 */
			// Start line: 358
			// Start offset: 0x80086660
			// Variables:
		// 		struct _MonsterAttributes *ma; // $a0
		/* end block 1.4 */
		// End offset: 0x8008674C
		// End Line: 390
	/* end block 1 */
	// End offset: 0x800867E0
	// End Line: 423

	/* begin block 2 */
		// Start line: 532
	/* end block 2 */
	// End Line: 533

void MON_Dead(_Instance *instance)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  ulong uVar4;
  int Data;
  __Event *p_Var5;
  undefined *puVar6;
  void *pvVar7;
  undefined4 local_20;
  _Model *p_Var8;
  _Instance *p_Var9;
  undefined4 local_1c;
  uint *puVar10;
  _Instance *Inst;
  _Instance *instance_00;
  undefined4 local_28;
  undefined4 in_stack_ffffffdc;
  
  puVar10 = (uint *)instance->extraData;
  instance_00 = (_Instance *)0x0;
  bVar2 = false;
  if (puVar10[0x36] == 0) {
    if ((*puVar10 & 0x200) == 0) {
      if ((instance->flags2 & 0x10U) != 0) {
        MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffdc,local_28));
      }
    }
    else {
      pvVar7 = instance->data;
      uVar4 = MON_GetTime(instance);
      if ((int)(uVar4 - puVar10[0x43]) < 0x1000) {
        MON_CutOut_Monster(instance,uVar4 - puVar10[0x43],(uint)*(byte *)((int)pvVar7 + 0x19),
                           (uint)*(byte *)((int)pvVar7 + 0x21));
      }
      else {
        MON_KillMonster(instance);
      }
    }
  }
  else {
    instance_00 = INSTANCE_Find(puVar10[0x36]);
    if (instance_00 == (_Instance *)0x0) {
      MON_BirthSoul(instance,1);
    }
  }
  cVar1 = *(char *)(puVar10 + 0x55);
  if ((cVar1 == '\x06') || (cVar1 == '\x04')) {
    MON_KillMonster(instance);
  }
  else {
    if (((byte)(cVar1 - 1U) < 3) && (instance[1].next == (_Instance *)0x0)) {
      p_Var8 = instance->object->modelList[instance->currentModel];
      Inst = (_Instance *)MEMPACK_Malloc(p_Var8->numVertices << 2,'!');
      instance[1].next = Inst;
      Data = p_Var8->numVertices;
      while (Data != 0) {
        (Inst->node).prev = (NodeType *)0x101010;
        Data = Data + -1;
        Inst = (_Instance *)&(Inst->node).next;
      }
    }
    else {
      if ((*(char *)(puVar10 + 0x55) == '\0') && (Inst = (_Instance *)0x0, puVar10[0x34] == 0)) {
        p_Var9 = (gameTrackerX.instanceList)->first;
        Data = 1000;
        while (p_Var9 != (_Instance *)0x0) {
          if ((((instance != p_Var9) && (p_Var9->object != (Object *)0x0)) &&
              ((p_Var9->object->oflags2 & 0x40000U) != 0)) &&
             ((p_Var9->LinkParent == (_Instance *)0x0 &&
              (lVar3 = MATH3D_LengthXYZ((int)(p_Var9->position).x - (int)(instance->position).x,
                                        (int)(p_Var9->position).y - (int)(instance->position).y,
                                        (int)(p_Var9->position).z - (int)(instance->position).z),
              lVar3 < Data)))) {
            Data = lVar3;
            Inst = p_Var9;
          }
          p_Var9 = p_Var9->next;
        }
        if (Inst == (_Instance *)0x0) {
          instance->flags2 = instance->flags2 | 0x80;
        }
        else {
          G2Anim_EnableSegment(&instance->anim,(uint)*(byte *)((int)instance->data + 0x25));
          local_28 = 3;
          Data = SetObjectData(0,0,0,instance,3);
          INSTANCE_Post(Inst,0x800002,Data);
          *(_Instance **)(puVar10 + 0x34) = Inst;
          instance->flags2 = instance->flags2 & 0xffffff7f;
        }
      }
      else {
        if ((*(char *)(puVar10 + 0x55) == '\x03') && ((*puVar10 & 0x400) == 0)) {
          bVar2 = true;
          *(undefined *)(puVar10 + 0x55) = 7;
        }
      }
    }
  }
  if (((*puVar10 & 0x400000) != 0) && (uVar4 = MON_GetTime(instance), puVar10[0x46] < uVar4)) {
    *puVar10 = *puVar10 & 0xffbfffff;
    FX_StopAllGlowEffects(instance,0x40);
  }
  MON_ApplyPhysics(instance);
  Data = MON_OnGround(instance);
  if (Data != 0) {
    *puVar10 = *puVar10 | 2;
  }
  while (p_Var5 = DeMessageQueue((__MessageQueue *)(puVar10 + 2)), p_Var5 != (__Event *)0x0) {
    puVar6 = (undefined *)p_Var5->ID;
    if (puVar6 == (undefined *)0x100000d) {
      pvVar7 = instance->data;
      if ((p_Var5->Data != 0) && ('\x02' < *(char *)((int)pvVar7 + 0x2b))) {
        *(undefined *)((int)puVar10 + 0x15a) = 2;
        *puVar10 = *puVar10 | 0x10000000;
        puVar10[0x59] = *(uint *)(*(int *)((int)pvVar7 + 0x34) + 8);
      }
      *(undefined *)(puVar10 + 0x55) = 0;
      puVar10[0x36] = 0;
      *puVar10 = *puVar10 & 0xffdfdd7f;
      puVar10[1] = puVar10[1] & 0xb8080000;
      MON_TurnOnAllSpheres(instance);
      MON_TurnOffWeaponSpheres(instance);
      MON_PlayAnim(instance,(MonsterAnim)
                            CONCAT412(local_1c,CONCAT48(local_20,CONCAT44(in_stack_ffffffdc,local_28
                                                                         ))),0x17);
      if (instance[1].next != (_Instance *)0x0) {
        MEMPACK_Free((char *)instance[1].next);
        instance[1].next = (_Instance *)0x0;
      }
      if ((instance->object->oflags & 0x200U) != 0) {
        instance->flags2 = instance->flags2 | 0x40;
      }
    }
    else {
      if ((int)puVar6 < 0x100000e) {
        if (puVar6 == (undefined *)0x100000b) {
          instance->xAccl = 0;
          instance->yAccl = 0;
          instance->zAccl = -0x10;
        }
      }
      else {
        if (puVar6 == &DAT_0100001b) {
          bVar2 = true;
        }
      }
    }
  }
  if (!bVar2) {
    return;
  }
  if (instance_00 == (_Instance *)0x0) {
    return;
  }
  if ((instance_00->flags2 & 0x8000000U) != 0) {
    MON_KillMonster(instance_00);
    uVar4 = INSTANCE_Query(instance_00,1);
    instance_00 = instance;
    if ((uVar4 & 0x1000) != 0) {
      Data = 1;
      goto LAB_800867d8;
    }
  }
  Data = 0;
LAB_800867d8:
  INSTANCE_Post(instance_00,0x100000d,Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MissileHitEntry(struct _Instance *instance /*$s0*/)
 // line 428, offset 0x80086808
	/* begin block 1 */
		// Start line: 429
		// Start offset: 0x80086808
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s2
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80086808
	// End Line: 429

	/* begin block 2 */
		// Start line: 933
	/* end block 2 */
	// End Line: 934

void MON_MissileHitEntry(_Instance *instance)

{
  int Data;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  uint *puVar1;
  void *pvVar2;
  undefined4 local_18;
  undefined4 in_stack_ffffffec;
  
  pvVar2 = instance->data;
  puVar1 = (uint *)instance->extraData;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->xVel = 0;
  instance->yVel = 0;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(unaff_s1,CONCAT48(unaff_s0,CONCAT44(in_stack_ffffffec,local_18))),
               0x19);
  *puVar1 = *puVar1 & 0xffffffef | 0x200000;
  MON_TurnOffAllSpheres(instance);
  *(undefined *)(puVar1 + 0x55) = 0;
  MON_DropAllObjects(instance);
  G2Anim_EnableSegment(&instance->anim,(uint)*(byte *)((int)pvVar2 + 0x25));
  Data = SetObjectData(0,0,0,instance,3);
  INSTANCE_Post((_Instance *)puVar1[0x34],0x800002,Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MissileHit(struct _Instance *instance /*$s1*/)
 // line 452, offset 0x800868c4
	/* begin block 1 */
		// Start line: 453
		// Start offset: 0x800868C4
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct _MonsterAttributes *ma; // $s0
	// 		int thisFrame; // $s2
	// 		int lastFrame; // $a0
	/* end block 1 */
	// End offset: 0x80086988
	// End Line: 475

	/* begin block 2 */
		// Start line: 997
	/* end block 2 */
	// End Line: 998

void MON_MissileHit(_Instance *instance)

{
  int iVar1;
  int iVar2;
  __Event *p_Var3;
  undefined4 local_18;
  void *pvVar4;
  undefined4 local_14;
  void *pvVar5;
  
  pvVar5 = instance->extraData;
  pvVar4 = instance->data;
  iVar1 = G2EmulationInstanceQueryFrame(instance,0);
  iVar2 = G2EmulationInstanceQueryLastFrame(instance,0);
  if ((iVar2 < (int)(uint)*(byte *)((int)pvVar4 + 0x26)) &&
     ((int)(uint)*(byte *)((int)pvVar4 + 0x26) <= iVar1)) {
    FX_Blood_Impale(instance,(ushort)*(byte *)((int)pvVar4 + 0x25),instance,
                    (ushort)*(byte *)((int)pvVar4 + 0x25));
  }
  else {
    if ((iVar2 < (int)(uint)*(byte *)((int)pvVar4 + 0x27)) &&
       ((int)(uint)*(byte *)((int)pvVar4 + 0x27) <= iVar1)) {
      FX_BloodCone(instance,(ushort)*(byte *)((int)pvVar4 + 0x25),0x50);
    }
  }
  if ((instance->flags2 & 0x10U) != 0) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
  }
  do {
    p_Var3 = DeMessageQueue((__MessageQueue *)((int)pvVar5 + 8));
  } while (p_Var3 != (__Event *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BirthEntry(struct _Instance *instance /*$a0*/)
 // line 480, offset 0x800869a4
	/* begin block 1 */
		// Start line: 1055
	/* end block 1 */
	// End Line: 1056

	/* begin block 2 */
		// Start line: 1056
	/* end block 2 */
	// End Line: 1057

void MON_BirthEntry(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Birth(struct _Instance *instance /*$a0*/)
 // line 484, offset 0x800869ac
	/* begin block 1 */
		// Start line: 1063
	/* end block 1 */
	// End Line: 1064

void MON_Birth(_Instance *instance)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_fffffffc,unaff_retaddr));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ParryEntry(struct _Instance *instance /*$s1*/)
 // line 492, offset 0x800869cc
	/* begin block 1 */
		// Start line: 493
		// Start offset: 0x800869CC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x800869CC
	// End Line: 493

	/* begin block 2 */
		// Start line: 1079
	/* end block 2 */
	// End Line: 1080

void MON_ParryEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  pvVar1 = instance->extraData;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),8);
  MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c),
                     0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Parry(struct _Instance *instance /*$s0*/)
 // line 516, offset 0x80086a1c
	/* begin block 1 */
		// Start line: 1143
	/* end block 1 */
	// End Line: 1144

void MON_Parry(_Instance *instance)

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
// void /*$ra*/ MON_LandOnFeetEntry(struct _Instance *instance /*$s0*/)
 // line 529, offset 0x80086a60
	/* begin block 1 */
		// Start line: 530
		// Start offset: 0x80086A60
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 544
			// Start offset: 0x80086AB8
			// Variables:
		// 		int damage; // $a1
		/* end block 1.1 */
		// End offset: 0x80086ADC
		// End Line: 554
	/* end block 1 */
	// End offset: 0x80086ADC
	// End Line: 555

	/* begin block 2 */
		// Start line: 1169
	/* end block 2 */
	// End Line: 1170

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void MON_LandOnFeetEntry(_Instance *instance)

{
  int mode;
  int damage;
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  undefined8 uStackX0;
  
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  mode = 0x12;
  if (*(char *)((int)instance->extraData + 0x155) == '\v') {
    mode = 0x15;
  }
  MON_PlayAnim(instance,(MonsterAnim)CONCAT88(uStackX0,CONCAT44(unaff_retaddr,unaff_s0)),mode);
  mode = instance->zVel;
  if (mode < -0x65) {
    damage = 0x1000;
    if ((mode < -0xf6) && (damage = 0x3000, -0x15e < mode)) {
      damage = 0x2000;
    }
    MON_TakeDamage(instance,damage,0x40000);
  }
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LandOnFeet(struct _Instance *instance /*$s1*/)
 // line 559, offset 0x80086b08
	/* begin block 1 */
		// Start line: 560
		// Start offset: 0x80086B08
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 565
			// Start offset: 0x80086B30
			// Variables:
		// 		int state; // $a1
		/* end block 1.1 */
		// End offset: 0x80086BB8
		// End Line: 590
	/* end block 1 */
	// End offset: 0x80086BB8
	// End Line: 592

	/* begin block 2 */
		// Start line: 1230
	/* end block 2 */
	// End Line: 1231

void MON_LandOnFeet(_Instance *instance)

{
  undefined4 local_10;
  uint *puVar1;
  undefined4 local_c;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  puVar1 = (uint *)instance->extraData;
  if ((instance->flags2 & 0x10U) != 0) {
    MON_AnimPlaying(instance,(MonsterAnim)
                             CONCAT412(in_stack_fffffffc,
                                       CONCAT48(unaff_retaddr,CONCAT44(local_c,local_10))));
    if (((*puVar1 & 0x2000) == 0) || (*(short *)(puVar1 + 0x50) != 0)) {
      if (((*puVar1 & 0x400000) == 0) && (*(short *)(puVar1 + 0x50) == 0)) {
        *puVar1 = *puVar1 & 0xfffffeff;
      }
    }
    else {
      *(undefined2 *)(puVar1 + 0x54) = 0x4000;
    }
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LandInWaterEntry(struct _Instance *instance /*$a0*/)
 // line 598, offset 0x80086bd4
	/* begin block 1 */
		// Start line: 1310
	/* end block 1 */
	// End Line: 1311

	/* begin block 2 */
		// Start line: 1311
	/* end block 2 */
	// End Line: 1312

void MON_LandInWaterEntry(_Instance *instance)

{
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LandInWater(struct _Instance *instance /*$a0*/)
 // line 603, offset 0x80086be8
	/* begin block 1 */
		// Start line: 1320
	/* end block 1 */
	// End Line: 1321

void MON_LandInWater(_Instance *instance)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_fffffffc,unaff_retaddr));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BreakHoldEntry(struct _Instance *instance /*$s1*/)
 // line 611, offset 0x80086c08
	/* begin block 1 */
		// Start line: 612
		// Start offset: 0x80086C08
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80086C60
	// End Line: 621

	/* begin block 2 */
		// Start line: 1336
	/* end block 2 */
	// End Line: 1337

void MON_BreakHoldEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  pvVar1 = instance->extraData;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0xf);
  *(undefined4 *)((int)pvVar1 + 0x108) = 0x100000;
  if ((instance->object->oflags & 0x200U) != 0) {
    instance->flags2 = instance->flags2 | 0x40;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BreakHold(struct _Instance *instance /*$a0*/)
 // line 623, offset 0x80086c74
	/* begin block 1 */
		// Start line: 1363
	/* end block 1 */
	// End Line: 1364

void MON_BreakHold(_Instance *instance)

{
  if ((instance->flags2 & 0x10U) == 0) {
    MON_DefaultQueueHandler(instance);
  }
  else {
    MON_UnlinkFromRaziel(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ImpactEntry(struct _Instance *instance /*$s0*/)
 // line 634, offset 0x80086cb8
	/* begin block 1 */
		// Start line: 635
		// Start offset: 0x80086CB8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterCombatAttributes *combat; // $s2
	/* end block 1 */
	// End offset: 0x80086CB8
	// End Line: 635

	/* begin block 2 */
		// Start line: 1385
	/* end block 2 */
	// End Line: 1386

void MON_ImpactEntry(_Instance *instance)

{
  short sVar1;
  ulong uVar2;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  uint *puVar3;
  undefined4 unaff_s2;
  int iVar4;
  undefined4 unaff_retaddr;
  
  puVar3 = (uint *)instance->extraData;
  iVar4 = *(int *)(puVar3[0x59] + 8);
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(unaff_retaddr,CONCAT48(unaff_s2,CONCAT44(unaff_s1,unaff_s0))),0x11
              );
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  uVar2 = MON_GetTime(instance);
  sVar1 = *(short *)(iVar4 + 2);
  puVar3[0x42] = 0x100000;
  puVar3[0x43] = uVar2 + (int)sVar1;
  *puVar3 = *puVar3 | 0x10;
  MON_TakeDamage(instance,0x1000,0x40000);
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Impact(struct _Instance *instance /*$s0*/)
 // line 653, offset 0x80086d5c
	/* begin block 1 */
		// Start line: 1433
	/* end block 1 */
	// End Line: 1434

void MON_Impact(_Instance *instance)

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
// void /*$ra*/ MON_FallEntry(struct _Instance *instance /*$s0*/)
 // line 666, offset 0x80086da0
	/* begin block 1 */
		// Start line: 667
		// Start offset: 0x80086DA0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80086E1C
	// End Line: 687

	/* begin block 2 */
		// Start line: 1459
	/* end block 2 */
	// End Line: 1460

void MON_FallEntry(_Instance *instance)

{
  char cVar1;
  int mode;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar2;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  pvVar2 = instance->extraData;
  cVar1 = *(char *)((int)pvVar2 + 0x155);
  if (cVar1 == '\x0e') {
    mode = 0x14;
  }
  else {
    if (((cVar1 == '\x01') || (cVar1 == '\x13')) || (cVar1 == '\r')) {
      PhysicsSetVelFromRot(instance,&instance->rotation,0x28);
      instance->zVel = 0x28;
    }
    mode = 0x13;
  }
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
               mode);
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = -0x10;
  *(undefined4 *)((int)pvVar2 + 0x108) = 0x100000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Fall(struct _Instance *instance /*$s1*/)
 // line 694, offset 0x80086e48
	/* begin block 1 */
		// Start line: 695
		// Start offset: 0x80086E48
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct __Event *message; // $a1
	/* end block 1 */
	// End offset: 0x80086EE8
	// End Line: 727

	/* begin block 2 */
		// Start line: 1515
	/* end block 2 */
	// End Line: 1516

void MON_Fall(_Instance *instance)

{
  __Event *message;
  uint uVar1;
  undefined4 unaff_s0;
  uint *puVar2;
  undefined4 unaff_s1;
  
  puVar2 = (uint *)instance->extraData;
  uVar1 = *puVar2;
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 0x400) == 0) {
      MON_ApplyPhysics(instance);
    }
    else {
      MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
    }
  }
  else {
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  while (message = DeMessageQueue((__MessageQueue *)(puVar2 + 2)), message != (__Event *)0x0) {
    if (message->ID != 0x1000007) {
      MON_DefaultMessageHandler(instance,message);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ThrownEntry(struct _Instance *instance /*$s1*/)
 // line 732, offset 0x80086f00
	/* begin block 1 */
		// Start line: 733
		// Start offset: 0x80086F00
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80086F68
	// End Line: 749

	/* begin block 2 */
		// Start line: 1591
	/* end block 2 */
	// End Line: 1592

void MON_ThrownEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  pvVar1 = instance->extraData;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = -8;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x10);
  *(undefined4 *)((int)pvVar1 + 0x108) = 0x100000;
  if ((instance->object->oflags & 0x200U) != 0) {
    instance->flags2 = instance->flags2 | 0x40;
  }
  instance->checkMask = instance->checkMask | 0x20;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Thrown(struct _Instance *instance /*$s0*/)
 // line 752, offset 0x80086f8c
	/* begin block 1 */
		// Start line: 753
		// Start offset: 0x80086F8C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct Intro *impaler; // $v0

		/* begin block 1.1 */
			// Start line: 759
			// Start offset: 0x80086FBC
		/* end block 1.1 */
		// End offset: 0x80086FFC
		// End Line: 769

		/* begin block 1.2 */
			// Start line: 775
			// Start offset: 0x80087018
			// Variables:
		// 		struct __Event *message; // $a1

			/* begin block 1.2.1 */
				// Start line: 787
				// Start offset: 0x80087058
				// Variables:
			// 		struct evMonsterHitTerrainData *data; // $v0
			/* end block 1.2.1 */
			// End offset: 0x80087058
			// End Line: 787
		/* end block 1.2 */
		// End offset: 0x80087138
		// End Line: 817
	/* end block 1 */
	// End offset: 0x80087138
	// End Line: 818

	/* begin block 2 */
		// Start line: 1634
	/* end block 2 */
	// End Line: 1635

void MON_Thrown(_Instance *instance)

{
  Level *pLVar1;
  Intro *pIVar2;
  __Event *message;
  int Data;
  ulong uVar3;
  uint *puVar4;
  undefined4 local_18;
  undefined4 in_stack_ffffffec;
  
  puVar4 = (uint *)instance->extraData;
  if ((*puVar4 & 2) == 0) {
    MON_ApplyPhysics(instance);
    while (message = DeMessageQueue((__MessageQueue *)(puVar4 + 2)), message != (__Event *)0x0) {
      if (message->ID == 0x1000007) {
        Data = ratan2((int)((short *)message->Data)[1],(int)*(short *)message->Data);
        (instance->rotation).z = (short)Data + 0x400;
        MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffec,local_18));
      }
      else {
        if (message->ID != 0x1000008) {
          MON_DefaultMessageHandler(instance,message);
        }
      }
    }
    if ((instance->currentMainState == 0x10) &&
       ((*(short *)(puVar4 + 0x54) == 0x20 || (*(short *)(puVar4 + 0x54) == 0x40)))) {
      *puVar4 = *puVar4 | 0x400000;
      uVar3 = MON_GetTime(instance);
      puVar4[0x46] = uVar3 + 10000;
      MON_MonsterGlow(instance,0x4960,-1,0,0);
      Data = SetFXHitData((_Instance *)0x0,0,0,0x20);
      INSTANCE_Post(instance,0x400000,Data);
      instance->currentMainState = 0xb;
      *puVar4 = *puVar4 & 0xfffffffe;
    }
  }
  else {
    pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    pIVar2 = MON_TestForTerrainImpale(instance,pLVar1->terrain);
    if (pIVar2 == (Intro *)0x0) {
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = 0;
      MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffec,local_18));
    }
    else {
      INSTANCE_Post(instance,0x100001c,pIVar2->UniqueID);
      MON_DefaultQueueHandler(instance);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ImpaleDeathEntry(struct _Instance *instance /*$s0*/)
 // line 823, offset 0x8008714c
	/* begin block 1 */
		// Start line: 824
		// Start offset: 0x8008714C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttributes *ma; // $s2
	/* end block 1 */
	// End offset: 0x8008714C
	// End Line: 824

	/* begin block 2 */
		// Start line: 1782
	/* end block 2 */
	// End Line: 1783

void MON_ImpaleDeathEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  uint *puVar1;
  undefined4 unaff_s2;
  void *pvVar2;
  undefined4 unaff_retaddr;
  
  puVar1 = (uint *)instance->extraData;
  pvVar2 = instance->data;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(unaff_retaddr,CONCAT48(unaff_s2,CONCAT44(unaff_s1,unaff_s0))),0xd)
  ;
  *puVar1 = *puVar1 & 0xffffffef | 0x200000;
  MON_TurnOffAllSpheres(instance);
  G2Anim_EnableSegment(&instance->anim,(uint)*(byte *)((int)pvVar2 + 0x25));
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->xVel = 0;
  instance->yVel = 0;
  MON_DropAllObjects(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ImpaleDeath(struct _Instance *instance /*$s1*/)
 // line 842, offset 0x800871d4
	/* begin block 1 */
		// Start line: 843
		// Start offset: 0x800871D4
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *ma; // $s0
	// 		struct __Event *message; // $v0

		/* begin block 1.1 */
			// Start line: 850
			// Start offset: 0x80087208
			// Variables:
		// 		int thisFrame; // $s3
		// 		int lastFrame; // $a0
		/* end block 1.1 */
		// End offset: 0x8008727C
		// End Line: 861
	/* end block 1 */
	// End offset: 0x80087348
	// End Line: 885

	/* begin block 2 */
		// Start line: 1831
	/* end block 2 */
	// End Line: 1832

void MON_ImpaleDeath(_Instance *instance)

{
  int Data;
  int iVar1;
  __Event *p_Var2;
  undefined4 local_18;
  void *pvVar3;
  undefined4 local_14;
  void *pvVar4;
  undefined4 local_20;
  undefined4 uVar5;
  undefined4 in_stack_ffffffe4;
  
  pvVar4 = instance->extraData;
  pvVar3 = instance->data;
  Data = MON_AnimPlaying(instance,(MonsterAnim)
                                  CONCAT412(local_14,CONCAT48(local_18,CONCAT44(in_stack_ffffffe4,
                                                                                local_20))));
  if (Data != 0) {
    Data = G2EmulationInstanceQueryFrame(instance,0);
    iVar1 = G2EmulationInstanceQueryLastFrame(instance,0);
    if ((iVar1 < (int)(uint)*(byte *)((int)pvVar3 + 0x26)) &&
       ((int)(uint)*(byte *)((int)pvVar3 + 0x26) <= Data)) {
      FX_Blood_Impale(instance,(ushort)*(byte *)((int)pvVar3 + 0x25),instance,
                      (ushort)*(byte *)((int)pvVar3 + 0x25));
    }
    else {
      if ((iVar1 < (int)(uint)*(byte *)((int)pvVar3 + 0x27)) &&
         ((int)(uint)*(byte *)((int)pvVar3 + 0x27) <= Data)) {
        FX_BloodCone(instance,(ushort)*(byte *)((int)pvVar3 + 0x25),0x50);
      }
    }
  }
  if (((instance->flags2 & 0x10U) != 0) &&
     ((Data = MON_AnimPlaying(instance,(MonsterAnim)
                                       CONCAT412(local_14,CONCAT48(local_18,CONCAT44(
                                                  in_stack_ffffffe4,local_20)))), Data == 0 ||
      (*(char *)(**(int **)((int)pvVar4 + 0x164) + 0xd) ==
       *(char *)(**(int **)((int)pvVar4 + 0x164) + 0x16))))) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffe4,local_20));
  }
  while (p_Var2 = DeMessageQueue((__MessageQueue *)((int)pvVar4 + 8)), p_Var2 != (__Event *)0x0) {
    if (p_Var2->ID == 0x100000a) {
      uVar5 = 3;
      Data = SetObjectData(0,0,0,instance,3);
      INSTANCE_Post(*(_Instance **)((int)pvVar4 + 0xd0),0x800002,Data);
      INSTANCE_Post(*(_Instance **)((int)pvVar4 + 0xd0),0x200003,7);
      *(undefined *)((int)pvVar4 + 0x154) = 0;
      MON_PlayAnim(instance,(MonsterAnim)
                            CONCAT412(local_14,CONCAT48(local_18,CONCAT44(in_stack_ffffffe4,uVar5)))
                   ,0x16);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_TerrainImpaleDeathEntry(struct _Instance *instance /*$s1*/)
 // line 890, offset 0x80087364
	/* begin block 1 */
		// Start line: 891
		// Start offset: 0x80087364
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *ma; // $s0
	// 		struct Intro *impaler; // $s0
	/* end block 1 */
	// End offset: 0x800874A4
	// End Line: 931

	/* begin block 2 */
		// Start line: 1929
	/* end block 2 */
	// End Line: 1930

void MON_TerrainImpaleDeathEntry(_Instance *instance)

{
  Intro *pIVar1;
  uint uVar2;
  int mode;
  undefined4 local_10;
  void *pvVar3;
  undefined4 local_c;
  undefined4 local_8;
  uint *puVar4;
  undefined4 local_4;
  
  puVar4 = (uint *)instance->extraData;
  pvVar3 = instance->data;
  *puVar4 = *puVar4 & 0xffffffef | 0x200000;
  MON_TurnOffAllSpheres(instance);
  MON_DropAllObjects(instance);
  G2Anim_EnableSegment(&instance->anim,(uint)*(byte *)((int)pvVar3 + 0x25));
  FX_BloodCone(instance,(ushort)*(byte *)((int)pvVar3 + 0x25),0x50);
  *puVar4 = *puVar4 | 0x800;
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  if ((int)puVar4[0x68] < 0) {
    pIVar1 = MON_FindNearestImpalingIntro(instance->currentStreamUnitID,&instance->position);
    puVar4[0x68] = pIVar1->UniqueID;
    MON_MoveInstanceToImpalePoint(instance);
  }
  else {
    pIVar1 = INSTANCE_FindIntro(instance->currentStreamUnitID,puVar4[0x68]);
  }
  if (pIVar1 == (Intro *)0x0) {
LAB_80087498:
    mode = 0x1f;
  }
  else {
    uVar2 = (uint)(ushort)(pIVar1->rotation).x & 0xfff;
    pIVar1->flags = pIVar1->flags & 0xffff7fff;
    if (uVar2 < 0x801) {
      if (uVar2 < 0x2ab) {
        mode = 0x1f;
        goto LAB_8008749c;
      }
    }
    else {
      mode = uVar2 - 0x1000;
      if (mode < 0) {
        mode = -mode;
      }
      if (mode < 0x2ab) goto LAB_80087498;
    }
    mode = 0x20;
  }
LAB_8008749c:
  MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_4,CONCAT48(local_8,CONCAT44(local_c,local_10)))
               ,mode);
  *(undefined *)(puVar4 + 0x55) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_TerrainImpaleDeath(struct _Instance *instance /*$s3*/)
 // line 934, offset 0x800874c0
	/* begin block 1 */
		// Start line: 935
		// Start offset: 0x800874C0
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct Intro *impaler; // $v1

		/* begin block 1.1 */
			// Start line: 959
			// Start offset: 0x800875A8
		/* end block 1.1 */
		// End offset: 0x800875B8
		// End Line: 962

		/* begin block 1.2 */
			// Start line: 969
			// Start offset: 0x800875C8
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s1
		// 		int fade_amount; // $s0
		/* end block 1.2 */
		// End offset: 0x80087630
		// End Line: 987
	/* end block 1 */
	// End offset: 0x8008768C
	// End Line: 999

	/* begin block 2 */
		// Start line: 2026
	/* end block 2 */
	// End Line: 2027

void MON_TerrainImpaleDeath(_Instance *instance)

{
  ulong uVar1;
  _Instance *p_Var2;
  Intro *pIVar3;
  __Event *p_Var4;
  uint uVar5;
  void *pvVar6;
  uint *puVar7;
  
  puVar7 = (uint *)instance->extraData;
  if ((*puVar7 & 0x200) == 0) {
    MON_MoveInstanceToImpalePoint(instance);
    if ((instance->flags2 & 0x10U) != 0) {
      if ((puVar7[0x31] != 0) &&
         (uVar1 = INSTANCE_Query(*(_Instance **)(puVar7[0x31] + 4),1), (uVar1 & 1) != 0)) {
        MON_ChangeHumanOpinion(instance);
      }
      *puVar7 = *puVar7 | 0x200;
      instance->flags2 = instance->flags2 & 0xffffffbf;
      if ((puVar7[0x36] == 0) && (*(short *)(puVar7 + 0x51) != 0)) {
        MON_BirthSoul(instance,1);
      }
    }
  }
  else {
    if (puVar7[0x36] == 0) {
      pvVar6 = instance->data;
      uVar1 = MON_GetTime(instance);
      uVar5 = puVar7[0x43];
      MON_CutOut_Monster(instance,uVar1 - uVar5,(uint)*(byte *)((int)pvVar6 + 0x19),
                         (uint)*(byte *)((int)pvVar6 + 0x21));
      if (0xfff < (int)(uVar1 - uVar5)) {
        pIVar3 = INSTANCE_FindIntro(instance->currentStreamUnitID,puVar7[0x68]);
        if (pIVar3 != (Intro *)0x0) {
          pIVar3->flags = pIVar3->flags | 0x8000;
        }
        MON_KillMonster(instance);
      }
    }
    else {
      p_Var2 = INSTANCE_Find(puVar7[0x36]);
      if (p_Var2 == (_Instance *)0x0) {
        MON_BirthSoul(instance,1);
      }
    }
    if (((*puVar7 & 0x400000) != 0) && (uVar1 = MON_GetTime(instance), puVar7[0x46] < uVar1)) {
      *puVar7 = *puVar7 & 0xffbfffff;
      FX_StopAllGlowEffects(instance,0x40);
    }
    do {
      p_Var4 = DeMessageQueue((__MessageQueue *)(puVar7 + 2));
    } while (p_Var4 != (__Event *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SurprisedEntry(struct _Instance *instance /*$s0*/)
 // line 1004, offset 0x800876a8
	/* begin block 1 */
		// Start line: 1005
		// Start offset: 0x800876A8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x800876A8
	// End Line: 1005

	/* begin block 2 */
		// Start line: 2170
	/* end block 2 */
	// End Line: 2171

void MON_SurprisedEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  pvVar2 = instance->extraData;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x1a);
  uVar1 = MON_GetTime(instance);
  *(int *)((int)pvVar2 + 0x114) =
       uVar1 + (int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x164) + 8) + 6);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Surprised(struct _Instance *instance /*$s1*/)
 // line 1015, offset 0x80087708
	/* begin block 1 */
		// Start line: 1016
		// Start offset: 0x80087708
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x800877B0
	// End Line: 1036

	/* begin block 2 */
		// Start line: 2192
	/* end block 2 */
	// End Line: 2193

void MON_Surprised(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  void *pvVar2;
  undefined4 local_c;
  
  pvVar2 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0) {
    MON_PlayCombatIdle(instance,2);
  }
  uVar1 = MON_GetTime(instance);
  if (*(uint *)((int)pvVar2 + 0x114) < uVar1) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
  if (*(int *)((int)pvVar2 + 0xc4) != 0) {
    *(int *)((int)pvVar2 + 0x11c) = *(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c;
    MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c),
                       *(short *)(*(int *)((int)pvVar2 + 0x164) + 0x1c));
  }
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_StunnedEntry(struct _Instance *instance /*$s1*/)
 // line 1042, offset 0x800877cc
	/* begin block 1 */
		// Start line: 1043
		// Start offset: 0x800877CC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterCombatAttributes *combat; // $s2
	/* end block 1 */
	// End offset: 0x8008794C
	// End Line: 1084

	/* begin block 2 */
		// Start line: 2248
	/* end block 2 */
	// End Line: 2249

void MON_StunnedEntry(_Instance *instance)

{
  short sVar1;
  int mode;
  ulong uVar2;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  short *psVar4;
  undefined4 local_4;
  
  puVar3 = (uint *)instance->extraData;
  psVar4 = *(short **)(puVar3[0x59] + 8);
  if ((*puVar3 & 0x40) == 0) {
    if ((*puVar3 & 0x100) != 0) goto LAB_800878d0;
    sVar1 = *(short *)(puVar3 + 0x54);
    if ((sVar1 == 0x40) || (sVar1 == 0x2000)) {
      mode = 0x2c;
    }
    else {
      if (sVar1 == 0x10) {
        mode = 0x1b;
      }
      else {
        mode = 5;
      }
    }
  }
  else {
    *(ushort *)(puVar3[0x31] + 0x18) = *(ushort *)(puVar3[0x31] + 0x18) | 0x400;
    *(ushort *)(puVar3[0x31] + 0x16) = *(ushort *)(puVar3[0x31] + 0x16) & 0xefff;
    *puVar3 = *puVar3 | 0x810000;
    mode = MON_SetUpKnockBack(instance,*(_Instance **)(puVar3[0x31] + 4),
                              (evMonsterHitData *)puVar3[0x30]);
    if (mode == 0) {
      mode = 1;
    }
    else {
      mode = 0;
    }
  }
  MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_4,CONCAT48(local_8,CONCAT44(local_c,local_10)))
               ,mode);
LAB_800878d0:
  *puVar3 = *puVar3 | 0x10110;
  uVar2 = MON_GetTime(instance);
  puVar3[0x43] = uVar2 + (int)psVar4[1];
  if ((*(short *)(puVar3 + 0x54) == 0x40) && (*(char *)(puVar3[0x59] + 0x38) != '\0')) {
    uVar2 = MON_GetTime(instance);
    mode = (int)*psVar4 << 1;
  }
  else {
    uVar2 = MON_GetTime(instance);
    mode = (int)*psVar4;
  }
  puVar3[0x44] = uVar2 + mode;
  puVar3[0x42] = 0x8000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Stunned(struct _Instance *instance /*$s0*/)
 // line 1087, offset 0x8008796c
	/* begin block 1 */
		// Start line: 1088
		// Start offset: 0x8008796C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80087A1C
	// End Line: 1108

	/* begin block 2 */
		// Start line: 2357
	/* end block 2 */
	// End Line: 2358

void MON_Stunned(_Instance *instance)

{
  ulong uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar3;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  puVar3 = (uint *)instance->extraData;
  if ((instance->flags2 & 0x10U) != 0) {
    if ((*puVar3 & 0x100) == 0) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
    else {
      MON_PlayAnim(instance,(MonsterAnim)
                            CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))
                                     ),5);
    }
  }
  uVar1 = MON_GetTime(instance);
  if (puVar3[0x45] < uVar1) {
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
  }
  if (((*puVar3 & 0x100) == 0) &&
     (iVar2 = MON_AnimPlaying(instance,(MonsterAnim)
                                       CONCAT412(in_stack_fffffffc,
                                                 CONCAT48(local_8,CONCAT44(local_c,local_10)))),
     iVar2 == 0)) {
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
                 0xc);
  }
  MON_DefaultQueueHandler(instance);
  PHYSICS_StopIfCloseToTarget(instance,0,0,0);
  PhysicsMove(instance,&instance->position,gameTrackerX.idleTime);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GrabbedEntry(struct _Instance *instance /*$s0*/)
 // line 1118, offset 0x80087a5c
	/* begin block 1 */
		// Start line: 1119
		// Start offset: 0x80087A5C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttributes *ma; // $s2
	/* end block 1 */
	// End offset: 0x80087AB8
	// End Line: 1136

	/* begin block 2 */
		// Start line: 2420
	/* end block 2 */
	// End Line: 2421

void MON_GrabbedEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;
  undefined4 unaff_s2;
  void *pvVar3;
  undefined4 unaff_retaddr;
  
  pvVar2 = instance->extraData;
  pvVar3 = instance->data;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(unaff_retaddr,CONCAT48(unaff_s2,CONCAT44(unaff_s1,unaff_s0))),4);
  instance->flags2 = instance->flags2 & 0xffffffbf;
  uVar1 = MON_GetTime(instance);
  *(int *)((int)pvVar2 + 0x114) =
       uVar1 + (int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x164) + 8) + 8);
  G2Anim_EnableSegment(&instance->anim,(uint)*(byte *)((int)pvVar3 + 0x25));
  INSTANCE_LinkToParent(instance,*(_Instance **)(*(int *)((int)pvVar2 + 0xc4) + 4),0x31);
  (instance->rotation).z = *(short *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x78) + 0x800;
  *(undefined2 *)((int)pvVar2 + 0x126) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Grabbed(struct _Instance *instance /*$s1*/)
 // line 1148, offset 0x80087b4c
	/* begin block 1 */
		// Start line: 1149
		// Start offset: 0x80087B4C
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *ma; // $s3
	// 		struct __Event *message; // $a1
	// 		int time; // $v1

		/* begin block 1.1 */
			// Start line: 1163
			// Start offset: 0x80087BA4
		/* end block 1.1 */
		// End offset: 0x80087BA4
		// End Line: 1163

		/* begin block 1.2 */
			// Start line: 1179
			// Start offset: 0x80087C78
			// Variables:
		// 		struct evMonsterThrownData *data; // $s0
		/* end block 1.2 */
		// End offset: 0x80087CE8
		// End Line: 1198
	/* end block 1 */
	// End offset: 0x80087D80
	// End Line: 1220

	/* begin block 2 */
		// Start line: 2482
	/* end block 2 */
	// End Line: 2483

void MON_Grabbed(_Instance *instance)

{
  short sVar1;
  ulong uVar2;
  __Event *message;
  int iVar3;
  undefined4 local_18;
  int *piVar4;
  undefined4 local_14;
  undefined4 unaff_s2;
  void *pvVar5;
  undefined4 unaff_s3;
  void *pvVar6;
  
  pvVar5 = instance->extraData;
  pvVar6 = instance->data;
  if ((instance->flags2 & 0x10U) != 0) {
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(unaff_s3,CONCAT48(unaff_s2,CONCAT44(local_14,local_18))),0xe);
  }
  uVar2 = MON_GetTime(instance);
  iVar3 = *(int *)((int)pvVar5 + 0x114) - uVar2;
  if (iVar3 < 1) {
    uVar2 = INSTANCE_Query(*(_Instance **)(*(int *)((int)pvVar5 + 0xc4) + 4),10);
    if (uVar2 != 0x20000) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
  }
  else {
    GAMEPAD_Shock1(0x80 - (iVar3 * 0x80) /
                          (int)*(short *)(*(int *)(*(int *)((int)pvVar5 + 0x164) + 8) + 8),0xf000);
  }
  (instance->rotation).z = *(short *)(*(int *)(*(int *)((int)pvVar5 + 0xc4) + 4) + 0x78) + 0x800;
LAB_80087c24:
  do {
    while( true ) {
      message = DeMessageQueue((__MessageQueue *)((int)pvVar5 + 8));
      if (message == (__Event *)0x0) {
        if (((instance->LinkParent == (_Instance *)0x0) && (instance->currentMainState == 10)) &&
           (*(short *)((int)pvVar5 + 0x126) != 0)) {
          G2Anim_DisableSegment(&instance->anim,(uint)*(byte *)((int)pvVar6 + 0x25));
          MON_TurnOnBodySpheres(instance);
          MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
        }
        else {
          *(undefined2 *)((int)pvVar5 + 0x126) = 1;
        }
        return;
      }
      iVar3 = message->ID;
      if (iVar3 != 0x1000003) break;
      piVar4 = (int *)message->Data;
      INSTANCE_UnlinkFromParent(instance);
      (instance->rotation).x = *(short *)(piVar4 + 1);
      (instance->rotation).y = *(short *)((int)piVar4 + 6);
      sVar1 = *(short *)(piVar4 + 2);
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = -8;
      (instance->rotation).z = sVar1 + 0x800;
      iVar3 = MON_SetVelocityTowardsImpalingObject(instance,(uint)(*piVar4 != 0));
      if (iVar3 == 0) {
        PhysicsSetVelFromZRot(instance,*(short *)(piVar4 + 2),(int)*(short *)(piVar4 + 3));
        instance->zVel = 0x32;
      }
      G2Anim_DisableSegment(&instance->anim,(uint)*(byte *)((int)pvVar6 + 0x25));
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
      GAMEPAD_Shock1(0,0);
    }
    if (0x1000003 < iVar3) goto LAB_80087c64;
  } while (iVar3 == 0x1000002);
  goto LAB_80087d14;
LAB_80087c64:
  if (iVar3 != 0x100000b) {
LAB_80087d14:
    MON_DefaultMessageHandler(instance,message);
  }
  goto LAB_80087c24;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_HitEntry(struct _Instance *instance /*$s1*/)
 // line 1225, offset 0x80087d9c
	/* begin block 1 */
		// Start line: 1226
		// Start offset: 0x80087D9C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $a0
	/* end block 1 */
	// End offset: 0x80087E14
	// End Line: 1241

	/* begin block 2 */
		// Start line: 2647
	/* end block 2 */
	// End Line: 2648

void MON_HitEntry(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  puVar3 = (uint *)instance->extraData;
  uVar2 = puVar3[0x31];
  *(ushort *)(uVar2 + 0x16) = *(ushort *)(uVar2 + 0x16) & 0xefff;
  *(ushort *)(uVar2 + 0x18) = *(ushort *)(uVar2 + 0x18) | 0x400;
  *puVar3 = *puVar3 | 0x10000;
  iVar1 = MON_SetUpKnockBack(instance,*(_Instance **)(uVar2 + 4),(evMonsterHitData *)puVar3[0x30]);
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
               (uint)(iVar1 == 0));
  puVar3[0x42] = 0x8000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Hit(struct _Instance *instance /*$s0*/)
 // line 1244, offset 0x80087e30
	/* begin block 1 */
		// Start line: 1245
		// Start offset: 0x80087E30
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80087EA0
	// End Line: 1257

	/* begin block 2 */
		// Start line: 2690
	/* end block 2 */
	// End Line: 2691

void MON_Hit(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  uVar1 = MON_GetTime(instance);
  if (*(uint *)((int)pvVar2 + 0x114) < uVar1) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
  }
  MON_DefaultQueueHandler(instance);
  PHYSICS_StopIfCloseToTarget(instance,0,0,0);
  PhysicsMove(instance,&instance->position,gameTrackerX.idleTime);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_AttackEntry(struct _Instance *instance /*$s0*/)
 // line 1267, offset 0x80087ee0
	/* begin block 1 */
		// Start line: 1268
		// Start offset: 0x80087EE0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttackAttributes *attack; // $s2
	/* end block 1 */
	// End offset: 0x80087EE0
	// End Line: 1268

	/* begin block 2 */
		// Start line: 2736
	/* end block 2 */
	// End Line: 2737

void MON_AttackEntry(_Instance *instance)

{
  ulong uVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = instance->extraData;
  iVar3 = *(int *)((int)pvVar2 + 0xb8);
  *(undefined4 *)((int)pvVar2 + 0x108) = 0x200000;
  MON_PlayAnimFromList(instance,(char *)(iVar3 + 0x1b),0,1);
  uVar1 = MON_GetTime(instance);
  *(int *)((int)pvVar2 + 0x114) = uVar1 + (int)*(char *)(iVar3 + 0xd) * 0x21;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Attack(struct _Instance *instance /*$s2*/)
 // line 1283, offset 0x80087f54
	/* begin block 1 */
		// Start line: 1284
		// Start offset: 0x80087F54
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct _MonsterIR *enemy; // $s4
	// 		struct _MonsterAttackAttributes *attack; // $s0
	// 		struct _MonsterAnim *anim; // $s1
	/* end block 1 */
	// End offset: 0x800880F0
	// End Line: 1327

	/* begin block 2 */
		// Start line: 2768
	/* end block 2 */
	// End Line: 2769

void MON_Attack(_Instance *instance)

{
  char cVar1;
  _MonsterAnim *p_Var2;
  int iVar3;
  ulong uVar4;
  undefined4 local_18;
  uint uVar5;
  undefined4 local_14;
  uint *puVar6;
  uint uVar7;
  
  puVar6 = (uint *)instance->extraData;
  uVar5 = puVar6[0x2e];
  uVar7 = puVar6[0x31];
  p_Var2 = MON_GetAnim(instance,(char *)(uVar5 + 0x1b),(int)*(char *)((int)puVar6 + 0x15b));
  if ((p_Var2->velocity != 0) && (iVar3 = MON_TransNodeAnimation(instance), iVar3 == 0)) {
    *(ushort *)((int)puVar6 + 0x126) = p_Var2->velocity;
    MON_MoveForward(instance);
  }
  iVar3 = MON_AnimPlayingFromList(instance,(char *)(uVar5 + 0x1b),(int)*(char *)(uVar5 + 10));
  if ((iVar3 == 0) ||
     (iVar3 = G2EmulationInstanceQueryPassedFrame(instance,0,(int)*(char *)(uVar5 + 9)), iVar3 == 0)
     ) {
    iVar3 = MON_AnimPlayingFromList(instance,(char *)(uVar5 + 0x1b),(int)*(char *)(uVar5 + 0xc));
    if ((iVar3 != 0) &&
       ((iVar3 = G2EmulationInstanceQueryPassedFrame(instance,0,(int)*(char *)(uVar5 + 0xb)),
        iVar3 != 0 && ((*puVar6 & 0x4000) != 0)))) {
      MON_TurnOffWeaponSpheres(instance);
      *(ushort *)(uVar7 + 0x18) = *(ushort *)(uVar7 + 0x18) | 0x200;
    }
  }
  else {
    MON_TurnOnWeaponSphere(instance,(int)*(char *)(uVar5 + 8));
  }
  if ((instance->flags2 & 0x10U) != 0) {
    instance->flags2 = instance->flags2 & 0xffffffef;
    cVar1 = *(char *)((int)puVar6 + 0x15b) + '\x01';
    *(char *)((int)puVar6 + 0x15b) = cVar1;
    if ((int)cVar1 < (int)*(char *)(uVar5 + 0xe)) {
      MON_PlayAnimFromList(instance,(char *)(uVar5 + 0x1b),(int)cVar1,1);
    }
    else {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
  }
  if ((uVar7 != 0) && (uVar4 = MON_GetTime(instance), uVar4 < puVar6[0x45])) {
    MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar7 + 4) + 0x5c),
                       *(short *)(puVar6[0x59] + 0x1c));
  }
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CombatEntry(struct _Instance *instance /*$a0*/)
 // line 1333, offset 0x80088118
	/* begin block 1 */
		// Start line: 1335
		// Start offset: 0x80088118
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	/* end block 1 */
	// End offset: 0x80088118
	// End Line: 1340

	/* begin block 2 */
		// Start line: 2870
	/* end block 2 */
	// End Line: 2871

	/* begin block 3 */
		// Start line: 2871
	/* end block 3 */
	// End Line: 2872

	/* begin block 4 */
		// Start line: 2876
	/* end block 4 */
	// End Line: 2877

void MON_CombatEntry(_Instance *instance)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  puVar1[0x42] = 0x2000000;
  *puVar1 = *puVar1 & 0xfffbffff | 0x10000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Combat(struct _Instance *instance /*$s1*/)
 // line 1346, offset 0x80088144
	/* begin block 1 */
		// Start line: 1347
		// Start offset: 0x80088144
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s3

		/* begin block 1.1 */
			// Start line: 1377
			// Start offset: 0x80088218
			// Variables:
		// 		struct _MonsterCombatAttributes *combat; // $s2

			/* begin block 1.1.1 */
				// Start line: 1387
				// Start offset: 0x80088268
				// Variables:
			// 		int reason; // $a1

				/* begin block 1.1.1.1 */
					// Start line: 1402
					// Start offset: 0x800882B8
					// Variables:
				// 		int anim; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x800882C8
				// End Line: 1406

				/* begin block 1.1.1.2 */
					// Start line: 1417
					// Start offset: 0x80088324
				/* end block 1.1.1.2 */
				// End offset: 0x80088340
				// End Line: 1420

				/* begin block 1.1.1.3 */
					// Start line: 1431
					// Start offset: 0x80088390
					// Variables:
				// 		int anim; // $v0
				/* end block 1.1.1.3 */
				// End offset: 0x800883C8
				// End Line: 1442
			/* end block 1.1.1 */
			// End offset: 0x800883C8
			// End Line: 1446

			/* begin block 1.1.2 */
				// Start line: 1450
				// Start offset: 0x800883E8
				// Variables:
			// 		int state; // $a1
			/* end block 1.1.2 */
			// End offset: 0x8008842C
			// End Line: 1461
		/* end block 1.1 */
		// End offset: 0x8008842C
		// End Line: 1462
	/* end block 1 */
	// End offset: 0x80088434
	// End Line: 1466

	/* begin block 2 */
		// Start line: 2903
	/* end block 2 */
	// End Line: 2904

void MON_Combat(_Instance *instance)

{
  ulong uVar1;
  int reason;
  _MonsterAttackAttributes *attack;
  uint uVar2;
  undefined4 local_18;
  uint *puVar3;
  undefined4 local_14;
  undefined4 local_10;
  int iVar4;
  undefined4 local_c;
  _MonsterIR *enemy;
  
  puVar3 = (uint *)instance->extraData;
  uVar2 = *puVar3;
  enemy = (_MonsterIR *)puVar3[0x31];
  if ((uVar2 & 0x80) != 0) {
    uVar1 = MON_GetTime(instance);
    if (puVar3[0x45] < uVar1) {
      *puVar3 = *puVar3 & 0xffffff7f;
      instance->petrifyValue = 0;
    }
    MON_DefaultQueueHandler(instance);
    return;
  }
  if ((((enemy != (_MonsterIR *)0x0) && ((uVar2 & 4) == 0)) &&
      (((uVar2 & 0x10000000) == 0 || ((enemy->mirFlags & 0x1000) == 0)))) &&
     (reason = MON_ValidPosition(instance), reason != 0)) {
    iVar4 = *(int *)(puVar3[0x59] + 8);
    *(_Position **)(puVar3 + 0x47) = &enemy->instance->position;
    reason = MON_ShouldIFlee(instance);
    if ((reason == 0) &&
       ((enemy->distance < *(short *)(iVar4 + 10) || (*(char *)((int)puVar3 + 0x156) == '\n')))) {
      if (((*puVar3 & 0x20000) != 0) && ((instance->flags2 & 0x12U) != 0)) {
        *puVar3 = *puVar3 & 0xbffdffff;
      }
      reason = MON_ShouldIEvade(instance);
      if (reason == 0) {
        if ((*puVar3 & 0x40000000) == 0) {
          if (*(char *)((int)puVar3 + 0x156) == '\n') {
            reason = MON_ShouldIFireAtTarget(instance,enemy);
          }
          else {
            attack = MON_ChooseAttack(instance,enemy);
            reason = MON_ShouldIAttack(instance,enemy,attack);
          }
          if (reason == 1) {
            MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
          }
          else {
            if (reason == 2) {
              MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
            }
            else {
              if ((*puVar3 & 0x20000) == 0) {
                reason = MON_ChooseCombatMove(instance,reason);
                if (reason == 0) {
                  MON_PlayCombatIdle(instance,2);
                }
                else {
                  MON_PlayAnim(instance,(MonsterAnim)
                                        CONCAT412(local_c,CONCAT48(local_10,CONCAT44(local_14,
                                                  local_18))),reason);
                  *puVar3 = *puVar3 | 0x20000;
                }
              }
            }
          }
        }
      }
      else {
        reason = MON_ChooseEvadeMove(instance);
        if (reason != 0) {
          MON_PlayAnim(instance,(MonsterAnim)
                                CONCAT412(local_c,CONCAT48(local_10,CONCAT44(local_14,local_18))),
                       reason);
          *puVar3 = *puVar3 | 0x40020000;
        }
      }
      MON_TurnToPosition(instance,&enemy->instance->position,*(short *)(puVar3[0x59] + 0x1c));
      goto LAB_8008842c;
    }
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
LAB_8008842c:
  MON_IdleQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ProjectileEntry(struct _Instance *instance /*$a0*/)
 // line 1471, offset 0x80088450
	/* begin block 1 */
		// Start line: 1472
		// Start offset: 0x80088450
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $v1
	// 		struct _MonsterMissile *missileDef; // $a1
	/* end block 1 */
	// End offset: 0x80088450
	// End Line: 1472

	/* begin block 2 */
		// Start line: 3158
	/* end block 2 */
	// End Line: 3159

void MON_ProjectileEntry(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_PlayAnimFromList
            (instance,(char *)(*(int *)((int)instance->data + 0x40) +
                               (int)*(char *)(*(int *)(*(int *)((int)pvVar1 + 0x164) + 8) + 0x18) *
                               0x10 + 0xe),0,1);
  *(undefined *)((int)pvVar1 + 0x15b) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Projectile(struct _Instance *instance /*$s2*/)
 // line 1483, offset 0x800884a8
	/* begin block 1 */
		// Start line: 1484
		// Start offset: 0x800884A8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttributes *ma; // $v1
	// 		struct _MonsterMissile *missileDef; // $s0
	/* end block 1 */
	// End offset: 0x800885CC
	// End Line: 1513

	/* begin block 2 */
		// Start line: 3183
	/* end block 2 */
	// End Line: 3184

void MON_Projectile(_Instance *instance)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_s0;
  _MonsterMissile *missiledef;
  undefined4 unaff_s1;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  missiledef = (_MonsterMissile *)
               (*(int *)((int)instance->data + 0x40) +
               (int)*(char *)(*(int *)(puVar3[0x59] + 8) + 0x18) * 0x10);
  if (puVar3[0x31] != 0) {
    if ((instance->flags2 & 0x10U) == 0) {
      iVar2 = MON_AnimPlayingFromList(instance,missiledef->animList,(uint)missiledef->anim);
      if (((iVar2 != 0) &&
          (iVar2 = G2EmulationInstanceQueryPassedFrame(instance,0,(uint)missiledef->frame),
          iVar2 != 0)) &&
         (MISSILE_FireAtInstance(instance,missiledef,*(_Instance **)(puVar3[0x31] + 4)),
         missiledef->reload != '\0')) {
        *puVar3 = *puVar3 & 0xffffffdf;
      }
      MON_TurnToPosition(instance,(_Position *)(*(int *)(puVar3[0x31] + 4) + 0x5c),
                         *(short *)(puVar3[0x59] + 0x1c));
      goto LAB_800885cc;
    }
    cVar1 = *(char *)((int)puVar3 + 0x15b) + '\x01';
    *(char *)((int)puVar3 + 0x15b) = cVar1;
    if ((int)cVar1 < (int)(uint)missiledef->numAnims) {
      MON_PlayAnimFromList(instance,missiledef->animList,(int)cVar1,1);
      goto LAB_800885cc;
    }
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
LAB_800885cc:
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_IdleEntry(struct _Instance *instance /*$a1*/)
 // line 1522, offset 0x800885ec
	/* begin block 1 */
		// Start line: 1523
		// Start offset: 0x800885EC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 1533
			// Start offset: 0x8008862C
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v1
		/* end block 1.1 */
		// End offset: 0x8008864C
		// End Line: 1538
	/* end block 1 */
	// End offset: 0x80088694
	// End Line: 1548

	/* begin block 2 */
		// Start line: 3264
	/* end block 2 */
	// End Line: 3265

void MON_IdleEntry(_Instance *instance)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  uVar1 = *puVar2;
  *puVar2 = uVar1 & 0xfffbefff;
  puVar2[0x42] = 1;
  if ((uVar1 & 4) == 0) {
    if (((instance->anim).section[0].flags & 1) == 0) {
      G2Anim_SetLooping(&instance->anim);
      *puVar2 = *puVar2 | 0x4000000;
    }
  }
  else {
    if (puVar2[0x31] == 0) {
      MON_PlayAnimID(instance,(int)**(char **)((int)instance->data + 0x48),2);
    }
    else {
      MON_PlayCombatIdle(instance,2);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Idle(struct _Instance *instance /*$s3*/)
 // line 1550, offset 0x800886a4
	/* begin block 1 */
		// Start line: 1551
		// Start offset: 0x800886A4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		int combatIdle; // $s4

		/* begin block 1.1 */
			// Start line: 1557
			// Start offset: 0x800886E0
			// Variables:
		// 		int state; // $s1
		// 		struct _MonsterIR *enemy; // $s2
		/* end block 1.1 */
		// End offset: 0x800887D4
		// End Line: 1586
	/* end block 1 */
	// End offset: 0x8008889C
	// End Line: 1603

	/* begin block 2 */
		// Start line: 3329
	/* end block 2 */
	// End Line: 3330

void MON_Idle(_Instance *instance)

{
  bool bVar1;
  int iVar2;
  undefined4 local_18;
  uint *puVar3;
  undefined4 local_14;
  int iVar4;
  uint uVar5;
  
  puVar3 = (uint *)instance->extraData;
  bVar1 = false;
  if ((*puVar3 & 4) == 0) {
    uVar5 = puVar3[0x31];
    iVar4 = -1;
    iVar2 = MON_ValidPosition(instance);
    if (iVar2 == 0) {
      iVar4 = 1;
    }
    else {
      if (uVar5 == 0) {
        if (((uint)*(byte *)((int)puVar3 + 0x156) - 2 < 2) && ((instance->flags2 & 2U) != 0)) {
          iVar4 = 5;
        }
      }
      else {
        bVar1 = true;
        iVar2 = MON_ShouldIFlee(instance);
        if (iVar2 == 0) {
          if ((*(ushort *)(uVar5 + 0x16) & 0x100) == 0) {
            if ((*(char *)((int)puVar3 + 0x156) == '\a') &&
               (*(short *)(puVar3 + 0x4e) < *(short *)(uVar5 + 0x14))) {
              MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar5 + 4) + 0x5c),
                                 *(short *)(puVar3[0x59] + 0x1c));
            }
            else {
              iVar4 = 0xd;
            }
          }
          else {
            iVar4 = 0x19;
          }
        }
        else {
          iVar4 = 0x13;
        }
        puVar3[0x47] = *(int *)(uVar5 + 4) + 0x5c;
      }
    }
    if (iVar4 != -1) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
  }
  else {
    if (((puVar3[1] & 0x10000000) != 0) &&
       (AngleMoveToward(&(instance->rotation).z,*(short *)(puVar3 + 0x49),
                        (short)((int)*(short *)(puVar3[0x59] + 0x1c) * gameTrackerX.idleTime * 0x10
                               >> 0x10)), (instance->rotation).z == *(short *)(puVar3 + 0x49))) {
      puVar3[1] = puVar3[1] & 0xefffffff;
    }
  }
  if (((*puVar3 & 4) == 0) && (((*puVar3 & 0x4000000) == 0 || ((instance->flags2 & 2U) != 0)))) {
    if (bVar1) {
      MON_PlayCombatIdle(instance,2);
    }
    else {
      MON_PlayRandomIdle(instance,2);
    }
  }
  MON_IdleQueueHandler(instance);
  return;
}



// autogenerated function stub: 
// void /*$ra*/ MON_FleeEntry(struct _Instance *instance /*$a0*/)
void MON_FleeEntry(struct _Instance *instance)
{ // line 1609, offset 0x800888c4
	/* begin block 1 */
		// Start line: 1610
		// Start offset: 0x800888C4
		// Variables:
			struct _MonsterVars *mv; // $a1
	/* end block 1 */
	// End offset: 0x800888C4
	// End Line: 1610

	/* begin block 2 */
		// Start line: 3447
	/* end block 2 */
	// End Line: 3448

}


// decompiled code
// original method signature: 
// void /*$ra*/ MON_Flee(struct _Instance *instance /*$s1*/)
 // line 1624, offset 0x80088918
	/* begin block 1 */
		// Start line: 1625
		// Start offset: 0x80088918
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 1653
			// Start offset: 0x800889CC
		/* end block 1.1 */
		// End offset: 0x80088A14
		// End Line: 1660
	/* end block 1 */
	// End offset: 0x80088A14
	// End Line: 1661

	/* begin block 2 */
		// Start line: 3488
	/* end block 2 */
	// End Line: 3489

void MON_Flee(_Instance *instance)

{
  short angle;
  int iVar1;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;
  
  puVar2 = (uint *)instance->extraData;
  if (puVar2[0x31] == 0) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    *(undefined *)((int)puVar2 + 0x156) = *(undefined *)((int)puVar2 + 0x157);
  }
  else {
    if (*(short *)(puVar2[0x59] + 0x1a) < *(short *)(puVar2[0x31] + 0x14)) {
      if (((*puVar2 & 0x2000000) == 0) || (puVar2[0x33] == 0)) {
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
        return;
      }
    }
    else {
      iVar1 = MON_ValidPosition(instance);
      if (iVar1 != 0) {
        angle = MATH3D_AngleFromPosToPos
                          ((_Position *)(*(int *)(puVar2[0x31] + 4) + 0x5c),&instance->position);
        angle = MONSENSE_GetClosestFreeDirection(instance,angle,1000);
        AngleMoveToward(&(instance->rotation).z,angle,*(short *)(puVar2[0x59] + 0x22));
        MON_DefaultQueueHandler(instance);
        return;
      }
    }
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PursueEntry(struct _Instance *instance /*$s1*/)
 // line 1666, offset 0x80088a28
	/* begin block 1 */
		// Start line: 1667
		// Start offset: 0x80088A28
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80088A88
	// End Line: 1682

	/* begin block 2 */
		// Start line: 3572
	/* end block 2 */
	// End Line: 3573

void MON_PursueEntry(_Instance *instance)

{
  uint uVar1;
  undefined4 unaff_s0;
  _MonsterVars *mv;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  mv = (_MonsterVars *)instance->extraData;
  uVar1 = mv->mvFlags;
  mv->mvFlags = uVar1 & 0xfffeffff | 0x1000;
  if ((uVar1 & 4) == 0) {
    MON_GetPlanSlot(mv);
    MON_PlayCombatIdle(instance,2);
  }
  else {
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,
                                    CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),3);
  }
  mv->mode = 4;
  mv->mvFlags = mv->mvFlags & 0xfffdffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Pursue(struct _Instance *instance /*$s5*/)
 // line 1687, offset 0x80088ab8
	/* begin block 1 */
		// Start line: 1688
		// Start offset: 0x80088AB8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 1707
			// Start offset: 0x80088B44
			// Variables:
		// 		int anim; // $a1
		// 		int planresult; // $v1
		// 		long range; // $s2
		// 		struct _MonsterIR *target; // $s3
		// 		struct _MonsterCombatAttributes *combat; // $a2

			/* begin block 1.1.1 */
				// Start line: 1715
				// Start offset: 0x80088B60
				// Variables:
			// 		struct _MonsterIR *ally; // $a1
			/* end block 1.1.1 */
			// End offset: 0x80088B90
			// End Line: 1734

			/* begin block 1.1.2 */
				// Start line: 1757
				// Start offset: 0x80088BBC
				// Variables:
			// 		int backtobase; // $s6

				/* begin block 1.1.2.1 */
					// Start line: 1772
					// Start offset: 0x80088C64
				/* end block 1.1.2.1 */
				// End offset: 0x80088CC4
				// End Line: 1782

				/* begin block 1.1.2.2 */
					// Start line: 1786
					// Start offset: 0x80088CDC
					// Variables:
				// 		int state; // $s4
				/* end block 1.1.2.2 */
				// End offset: 0x80088D94
				// End Line: 1851
			/* end block 1.1.2 */
			// End offset: 0x80088DAC
			// End Line: 1859
		/* end block 1.1 */
		// End offset: 0x80088DAC
		// End Line: 1860
	/* end block 1 */
	// End offset: 0x80088DAC
	// End Line: 1861

	/* begin block 2 */
		// Start line: 3618
	/* end block 2 */
	// End Line: 3619

void MON_Pursue(_Instance *instance)

{
  short sVar1;
  bool bVar2;
  int anim;
  Intro *pIVar3;
  long lVar4;
  _MonsterAnim *p_Var5;
  _MonsterIR *target;
  _MonsterCombatAttributes *p_Var6;
  undefined4 local_20;
  undefined4 local_1c;
  _MonsterVars *mv;
  long distance;
  int iVar7;
  
  mv = (_MonsterVars *)instance->extraData;
  if ((mv->mvFlags & 4) != 0) {
    MON_GroundMoveQueueHandler(instance);
    return;
  }
  if ((mv->enemy == (_MonsterIR *)0x0) ||
     (((mv->mvFlags & 0x10000000) != 0 && ((mv->enemy->mirFlags & 0x1000) != 0))))
  goto LAB_80088da4;
  p_Var6 = mv->subAttr->combatAttributes;
  if (((mv->mvFlags & 0x2000000) == 0) ||
     ((target = mv->ally, target == (_MonsterIR *)0x0 || ((target->mirFlags & 0x200) != 0)))) {
    target = mv->enemy;
    distance = (int)p_Var6->combatRange + -200;
  }
  else {
    distance = (long)p_Var6->allyRange;
  }
  if ((target == (_MonsterIR *)0x0) || (anim = MON_ShouldIFireAtTarget(instance,target), anim != 0))
  goto LAB_80088da4;
  bVar2 = false;
  sVar1 = (target->instance->position).z;
  *(undefined4 *)&mv->destination = *(undefined4 *)&target->instance->position;
  (mv->destination).z = sVar1;
  mv->lookAtPos = &mv->destination;
  anim = MON_ValidPosition(instance);
  if (anim == 0) {
    pIVar3 = instance->intro;
    if (pIVar3 == (Intro *)0x0) {
      sVar1 = (mv->lastValidPos).z;
      *(undefined4 *)&mv->destination = *(undefined4 *)&mv->lastValidPos;
      (mv->destination).z = sVar1;
    }
    else {
      sVar1 = (pIVar3->position).z;
      *(undefined4 *)&mv->destination = *(undefined4 *)&pIVar3->position;
      (mv->destination).z = sVar1;
    }
LAB_80088cc4:
    bVar2 = true;
    distance = 100;
  }
  else {
    if (((mv->behaviorState == '\a') && (pIVar3 = instance->intro, pIVar3 != (Intro *)0x0)) &&
       (lVar4 = MATH3D_LengthXYZ((int)(mv->destination).x - (int)(pIVar3->position).x,
                                 (int)(mv->destination).y - (int)(pIVar3->position).y,
                                 (int)(mv->destination).z - (int)(pIVar3->position).z),
       mv->guardRange < lVar4)) {
      sVar1 = (instance->intro->position).z;
      *(undefined4 *)&mv->destination = *(undefined4 *)&instance->intro->position;
      (mv->destination).z = sVar1;
      goto LAB_80088cc4;
    }
  }
  anim = MON_CheckPointSuitability(instance,&instance->position,&mv->destination);
  iVar7 = -1;
  if (anim == 0) goto LAB_80088da4;
  sVar1 = target->distance;
  p_Var5 = MON_GetAnim(instance,mv->subAttr->animList,2);
  anim = 3;
  if ((int)sVar1 < (int)(distance + (uint)p_Var5->distance)) {
    anim = 2;
  }
  if (distance < 0) {
    distance = 0;
  }
  anim = MON_DefaultPlanMovement(instance,anim,distance);
  switch(anim) {
  case 2:
  case 3:
switchD_80088d50_caseD_2:
    iVar7 = 2;
    break;
  case 4:
    if ((target->mirFlags & 2) == 0) {
      iVar7 = 0xd;
      if (bVar2) goto switchD_80088d50_caseD_2;
    }
    else {
      MON_GetPlanSlot(mv);
    }
  }
  if (iVar7 == -1) {
    return;
  }
LAB_80088da4:
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_1c,local_20));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_WanderEntry(struct _Instance *instance /*$s1*/)
 // line 1866, offset 0x80088dd4
	/* begin block 1 */
		// Start line: 1867
		// Start offset: 0x80088DD4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80088E44
	// End Line: 1883

	/* begin block 2 */
		// Start line: 3984
	/* end block 2 */
	// End Line: 3985

void MON_WanderEntry(_Instance *instance)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined4 local_10;
  _MonsterVars *mv;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  mv = (_MonsterVars *)instance->extraData;
  uVar1 = mv->mvFlags;
  mv->mvFlags = uVar1 | 0x11000;
  if ((uVar1 & 4) == 0) {
    MON_GetPlanSlot(mv);
    iVar2 = MON_AnimPlaying(instance,(MonsterAnim)
                                     CONCAT412(in_stack_fffffffc,
                                               CONCAT48(local_8,CONCAT44(local_c,local_10))));
    if (iVar2 == 0) {
      MON_PlayRandomIdle(instance,2);
    }
  }
  else {
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
                 2);
  }
  mv->mvFlags = mv->mvFlags & 0xfffdffff;
  uVar3 = MON_GetTime(instance);
  mv->generalTimer = uVar3 + 1000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Wander(struct _Instance *instance /*$s2*/)
 // line 1889, offset 0x80088e7c
	/* begin block 1 */
		// Start line: 1890
		// Start offset: 0x80088E7C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 1895
			// Start offset: 0x80088EB4
		/* end block 1.1 */
		// End offset: 0x80088F08
		// End Line: 1900

		/* begin block 1.2 */
			// Start line: 1910
			// Start offset: 0x80088F58
			// Variables:
		// 		int markerID; // $s0
		/* end block 1.2 */
		// End offset: 0x80088FA0
		// End Line: 1914

		/* begin block 1.3 */
			// Start line: 1922
			// Start offset: 0x80088FB4
			// Variables:
		// 		struct _Position *target; // $a1
		// 		short range; // $a2
		/* end block 1.3 */
		// End offset: 0x80088FF8
		// End Line: 1936

		/* begin block 1.4 */
			// Start line: 1942
			// Start offset: 0x80089008
			// Variables:
		// 		int planresult; // $v1
		// 		int state; // $a1
		/* end block 1.4 */
		// End offset: 0x80089098
		// End Line: 1979
	/* end block 1 */
	// End offset: 0x800890D8
	// End Line: 1987

	/* begin block 2 */
		// Start line: 4032
	/* end block 2 */
	// End Line: 4033

void MON_Wander(_Instance *instance)

{
  long lVar1;
  ulong uVar2;
  short *psVar3;
  _StreamUnit *streamUnit;
  uint uVar4;
  int iVar5;
  _Position *in;
  int iVar6;
  short r;
  undefined4 local_18;
  undefined4 local_14;
  uint *puVar7;
  
  puVar7 = (uint *)instance->extraData;
  if ((*puVar7 & 4) == 0) {
    if ((*puVar7 & 0x40000) != 0) {
      iVar5 = MON_DefaultPlanMovement(instance,2,100);
      iVar6 = -1;
      switch(iVar5) {
      case 2:
      case 3:
        iVar6 = 2;
        break;
      case 4:
        iVar6 = 0x14;
        if (*(char *)((int)puVar7 + 0x156) != '\x04') {
          uVar4 = rand();
          iVar6 = 2;
          if ((uVar4 & 3) == 0) {
            uVar2 = MON_GetTime(instance);
            puVar7[0x45] = uVar2 + 1000;
            iVar6 = 5;
          }
        }
      }
      if (iVar6 != -1) {
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
      }
      goto LAB_80089098;
    }
    uVar2 = MON_GetTime(instance);
    if (puVar7[0x45] < uVar2) goto LAB_80088efc;
    if (*(char *)((int)puVar7 + 0x156) == '\x03') {
      psVar3 = (short *)puVar7[0x67];
      if (psVar3 != (short *)0x0) {
        r = *psVar3;
        *(short **)(puVar7 + 0x67) = psVar3 + 1;
        streamUnit = STREAM_GetStreamUnitWithID(instance->currentStreamUnitID);
        PLANAPI_FindNodePositionInUnit(streamUnit,(_Position *)(puVar7 + 0x48),(int)r,0);
        if (*(short *)puVar7[0x67] == 0) {
          *(uint **)(puVar7 + 0x67) = puVar7 + 0x61;
        }
        *puVar7 = *puVar7 | 0x40000;
      }
    }
    else {
      r = *(short *)((int)puVar7 + 0x136);
      in = (_Position *)0x0;
      if (puVar7[0x32] == 0) {
        if (instance->intro != (Intro *)0x0) {
          in = &instance->intro->position;
        }
      }
      else {
        r = 800;
        in = (_Position *)(*(int *)(puVar7[0x32] + 4) + 0x5c);
      }
      MON_GetRandomDestinationInWorld(instance,in,r);
    }
  }
  else {
    MON_TurnToPosition(instance,(_Position *)(puVar7 + 0x48),*(short *)(puVar7[0x59] + 0x1e));
    lVar1 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)(puVar7 + 0x48),
                             (int)(instance->position).y - (int)*(short *)((int)puVar7 + 0x122),
                             (int)(instance->position).z - (int)*(short *)(puVar7 + 0x49));
    if (lVar1 < 300) {
LAB_80088efc:
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
  }
  MON_GroundMoveQueueHandler(instance);
LAB_80089098:
  if (puVar7[0x31] != 0) {
    iVar5 = MON_ShouldIFlee(instance);
    if (iVar5 != 0) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
    puVar7[0x47] = *(int *)(puVar7[0x31] + 4) + 0x5c;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_HideEntry(struct _Instance *instance /*$a0*/)
 // line 1992, offset 0x800890f4
	/* begin block 1 */
		// Start line: 4241
	/* end block 1 */
	// End Line: 4242

void MON_HideEntry(_Instance *instance)

{
  MON_PlayRandomIdle(instance,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Hide(struct _Instance *instance /*$s1*/)
 // line 1998, offset 0x80089114
	/* begin block 1 */
		// Start line: 1999
		// Start offset: 0x80089114
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s2
	/* end block 1 */
	// End offset: 0x80089270
	// End Line: 2047

	/* begin block 2 */
		// Start line: 4253
	/* end block 2 */
	// End Line: 4254

void MON_Hide(_Instance *instance)

{
  byte bVar1;
  int mode;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;
  undefined4 local_8;
  uint uVar3;
  undefined4 local_4;
  
  puVar2 = (uint *)instance->extraData;
  uVar3 = puVar2[0x31];
  if (((*puVar2 & 4) != 0) || (uVar3 == 0)) goto LAB_80089230;
  bVar1 = *(byte *)((int)puVar2 + 0x156);
  if (bVar1 == 8) {
    if (((*puVar2 & 0x40000000) != 0) || (mode = MON_ShouldIAmbushEnemy(instance), mode == 0))
    goto LAB_80089230;
    if (*(char *)((int)puVar2 + 0x153) != '\0') {
      if (*(char *)((int)puVar2 + 0x153) == '\x01') {
        mode = 0x28;
      }
      else {
        mode = 0x29;
      }
      MON_PlayAnim(instance,(MonsterAnim)
                            CONCAT412(local_4,CONCAT48(local_8,CONCAT44(local_c,local_10))),mode);
      *puVar2 = *puVar2 | 0x40000000;
      goto LAB_80089230;
    }
    MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar3 + 4) + 0x5c),0x1000);
  }
  else {
    if ((bVar1 < 9) && (bVar1 == 4)) {
      MON_ChangeBehavior(instance,(uint)*(byte *)(puVar2 + 0x56));
      goto LAB_80089230;
    }
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
LAB_80089230:
  if ((instance->flags2 & 0x10U) != 0) {
    if ((*puVar2 & 0x40000000) == 0) {
      MON_PlayRandomIdle(instance,1);
    }
    else {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
  }
  MON_IdleQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SurpriseAttackEntry(struct _Instance *instance /*$a0*/)
 // line 2053, offset 0x80089290
	/* begin block 1 */
		// Start line: 2054
		// Start offset: 0x80089290
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterCombatAttributes *combatAttr; // $v0
	// 		struct _MonsterAttributes *ma; // $v1
	/* end block 1 */
	// End offset: 0x80089314
	// End Line: 2080

	/* begin block 2 */
		// Start line: 4365
	/* end block 2 */
	// End Line: 4366

void MON_SurpriseAttackEntry(_Instance *instance)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  cVar1 = *(char *)(*(int *)(*(int *)((int)pvVar3 + 0x164) + 8) + 0x19);
  iVar2 = *(int *)((int)instance->data + 0x3c);
  *(undefined *)((int)pvVar3 + 0x15b) = 0;
  iVar2 = iVar2 + (int)cVar1 * 0x20;
  *(int *)((int)pvVar3 + 0xb8) = iVar2;
  MON_PlayAnimFromList(instance,(char *)(iVar2 + 0x1b),0,1);
  if (*(char *)((int)pvVar3 + 0x156) == '\b') {
    if (*(char *)((int)pvVar3 + 0x159) == -1) {
      *(undefined *)((int)pvVar3 + 0x156) = *(undefined *)((int)pvVar3 + 0x157);
    }
    else {
      *(undefined *)((int)pvVar3 + 0x156) = *(undefined *)((int)pvVar3 + 0x159);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SurpriseAttack(struct _Instance *instance /*$a0*/)
 // line 2082, offset 0x80089324
	/* begin block 1 */
		// Start line: 4434
	/* end block 1 */
	// End Line: 4435

void MON_SurpriseAttack(_Instance *instance)

{
  MON_Attack(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_EnvironmentDamageEntry(struct _Instance *instance /*$a0*/)
 // line 2090, offset 0x80089344
	/* begin block 1 */
		// Start line: 4450
	/* end block 1 */
	// End Line: 4451

	/* begin block 2 */
		// Start line: 4451
	/* end block 2 */
	// End Line: 4452

void MON_EnvironmentDamageEntry(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_EnvironmentDamage(struct _Instance *instance /*$a0*/)
 // line 2094, offset 0x8008934c
	/* begin block 1 */
		// Start line: 4458
	/* end block 1 */
	// End Line: 4459

	/* begin block 2 */
		// Start line: 4459
	/* end block 2 */
	// End Line: 4460

void MON_EnvironmentDamage(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MonsterGlow(struct _Instance *instance /*$fp*/, long color /*stack 4*/, int glowtime /*$s5*/, int glowin /*$s6*/, int glowfade /*stack 16*/)
 // line 2098, offset 0x80089354
	/* begin block 1 */
		// Start line: 2099
		// Start offset: 0x80089354
		// Variables:
	// 		struct _FXGlowEffect *glow; // $v0
	// 		struct _MonsterAttributes *ma; // $s4
	/* end block 1 */
	// End offset: 0x800893BC
	// End Line: 2107

	/* begin block 2 */
		// Start line: 4466
	/* end block 2 */
	// End Line: 4467

void MON_MonsterGlow(_Instance *instance,long color,int glowtime,int glowin,int glowfade)

{
  _FXGlowEffect *p_Var1;
  short sVar2;
  short sVar3;
  void *pvVar4;
  short sVar5;
  long local_res4 [3];
  
  sVar3 = (short)glowin;
  sVar2 = (short)glowtime;
  sVar5 = (short)glowfade;
  pvVar4 = instance->data;
  if (0 < glowtime) {
    sVar2 = sVar2 * 0x21;
  }
  if (0 < glowfade) {
    sVar5 = sVar5 * 0x21;
  }
  if (0 < glowin) {
    sVar3 = sVar3 * 0x21;
  }
  local_res4[0] = color;
  p_Var1 = FX_DoInstanceTwoSegmentGlow
                     (instance,(uint)*(byte *)((int)pvVar4 + 0x1d),
                      (uint)*(byte *)((int)pvVar4 + 0x20),local_res4,1,0x400,0xa0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow
                     (instance,(uint)*(byte *)((int)pvVar4 + 0x1d),
                      (uint)*(byte *)((int)pvVar4 + 0x21),local_res4,1,0x400,0xa0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow
                     (instance,(uint)*(byte *)((int)pvVar4 + 0x1b),
                      (uint)*(byte *)((int)pvVar4 + 0x23),local_res4,1,0x400,0x80);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow
                     (instance,(uint)*(byte *)((int)pvVar4 + 0x1c),
                      (uint)*(byte *)((int)pvVar4 + 0x24),local_res4,1,0x400,0x80);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow
                     (instance,(uint)*(byte *)((int)pvVar4 + 0x19),
                      (uint)*(byte *)((int)pvVar4 + 0x1d),local_res4,1,0x400,0xc0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GeneralDeathEntry(struct _Instance *instance /*$s1*/)
 // line 2126, offset 0x800894e0
	/* begin block 1 */
		// Start line: 2127
		// Start offset: 0x800894E0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80089698
	// End Line: 2190

	/* begin block 2 */
		// Start line: 4530
	/* end block 2 */
	// End Line: 4531

void MON_GeneralDeathEntry(_Instance *instance)

{
  ushort uVar1;
  ulong uVar2;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;
  undefined4 local_18;
  undefined4 in_stack_ffffffec;
  
  puVar3 = (uint *)instance->extraData;
  if (instance->LinkParent != (_Instance *)0x0) {
    MON_UnlinkFromRaziel(instance);
  }
  instance->xAccl = 0;
  instance->yAccl = 0;
  if ((*puVar3 & 2) != 0) {
    instance->xVel = 0;
    instance->yVel = 0;
  }
  uVar1 = *(ushort *)(puVar3 + 0x54);
  *puVar3 = *puVar3 & 0xffffffef | 0x202000;
  if (uVar1 == 0x40) {
LAB_800895d8:
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(local_c,CONCAT48(local_10,CONCAT44(in_stack_ffffffec,local_18)))
                 ,0x1b);
    if (*(short *)(puVar3 + 0x54) == 0x40) {
      *(undefined *)(puVar3 + 0x55) = 2;
    }
    uVar2 = MON_GetTime(instance);
    puVar3[0x45] = uVar2 + 3000;
    *puVar3 = *puVar3 | 0x400000;
    uVar2 = MON_GetTime(instance);
    puVar3[0x46] = uVar2 + 10000;
    MON_MonsterGlow(instance,0x4960,-1,0,0);
  }
  else {
    if (uVar1 < 0x41) {
      if (uVar1 == 0x10) {
        MON_PlayAnim(instance,(MonsterAnim)
                              CONCAT412(local_c,CONCAT48(local_10,CONCAT44(in_stack_ffffffec,
                                                                           local_18))),0x1b);
        *(undefined *)(puVar3 + 0x55) = 3;
        uVar2 = MON_GetTime(instance);
        puVar3[0x45] = uVar2 + 3000;
        uVar2 = MON_GetTime(instance);
        puVar3[0x46] = uVar2 + 12000;
        goto LAB_80089698;
      }
      if (uVar1 == 0x20) {
        *(undefined *)(puVar3 + 0x55) = 1;
        goto LAB_800895d8;
      }
      *(undefined *)(puVar3 + 0x55) = 7;
    }
    else {
      if (uVar1 == 0x200) {
        MON_PlayAnim(instance,(MonsterAnim)
                              CONCAT412(local_c,CONCAT48(local_10,CONCAT44(in_stack_ffffffec,
                                                                           local_18))),0x2b);
        *(undefined *)(puVar3 + 0x55) = 4;
        uVar2 = MON_GetTime(instance);
        puVar3[0x45] = uVar2 + 1000;
        goto LAB_80089698;
      }
      if (uVar1 == 0x400) {
        *(undefined *)(puVar3 + 0x55) = 6;
        puVar3[0x45] = 0;
        goto LAB_80089698;
      }
      *(undefined *)(puVar3 + 0x55) = 7;
    }
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(local_c,CONCAT48(local_10,CONCAT44(in_stack_ffffffec,local_18)))
                 ,0x24);
  }
LAB_80089698:
  MON_TurnOffAllSpheres(instance);
  MON_DropAllObjects(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GeneralDeath(struct _Instance *instance /*$s1*/)
 // line 2194, offset 0x800896bc
	/* begin block 1 */
		// Start line: 2195
		// Start offset: 0x800896BC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		int dead; // $s2
	/* end block 1 */
	// End offset: 0x800897D4
	// End Line: 2231

	/* begin block 2 */
		// Start line: 4677
	/* end block 2 */
	// End Line: 4678

void MON_GeneralDeath(_Instance *instance)

{
  byte bVar1;
  bool bVar2;
  ulong uVar3;
  int iVar4;
  __Event *p_Var5;
  undefined4 local_10;
  uint *puVar6;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar6 = (uint *)instance->extraData;
  bVar2 = false;
  if (((instance->flags2 & 2U) != 0) && (uVar3 = MON_GetTime(instance), puVar6[0x45] < uVar3)) {
    bVar1 = *(byte *)(puVar6 + 0x55);
    if (((uint)bVar1 - 1 < 2) || ((bVar1 == 5 || (bVar1 == 3)))) {
      MON_PlayAnim(instance,(MonsterAnim)
                            CONCAT412(local_4,CONCAT48(local_8,CONCAT44(local_c,local_10))),0x24);
    }
    else {
      bVar2 = true;
    }
  }
  if ((instance->flags2 & 0x10U) != 0) {
    bVar2 = true;
  }
  if ((bVar2) || (*(char *)(puVar6 + 0x55) == '\x06')) {
    *puVar6 = *puVar6 & 0xffffffef;
    G2Anim_SetNoLooping(&instance->anim);
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
  MON_ApplyPhysics(instance);
  iVar4 = MON_OnGround(instance);
  if (iVar4 != 0) {
    *puVar6 = *puVar6 | 2;
  }
  do {
    p_Var5 = DeMessageQueue((__MessageQueue *)(puVar6 + 2));
  } while (p_Var5 != (__Event *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_NoticeEntry(struct _Instance *instance /*$s1*/)
 // line 2236, offset 0x800897ec
	/* begin block 1 */
		// Start line: 2237
		// Start offset: 0x800897EC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80089890
	// End Line: 2249

	/* begin block 2 */
		// Start line: 4765
	/* end block 2 */
	// End Line: 4766

void MON_NoticeEntry(_Instance *instance)

{
  int Data;
  _Instance *sender;
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  pvVar1 = instance->extraData;
  if ((*(int *)((int)pvVar1 + 4) < 0) &&
     (*(int *)(*(int *)(*(int *)((int)pvVar1 + 0x164) + 0xc) + 4) != 0)) {
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,
                                    CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x2a);
    sender = *(_Instance **)(*(int *)((int)pvVar1 + 0xc4) + 4);
    Data = SetMonsterAlarmData(sender,&sender->position,2);
    INSTANCE_Broadcast(instance,*(long *)(*(int *)(*(int *)((int)pvVar1 + 0x164) + 0xc) + 4),
                       0x1000011,Data);
  }
  else {
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,
                                    CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x1d);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Notice(struct _Instance *instance /*$s1*/)
 // line 2251, offset 0x800898a4
	/* begin block 1 */
		// Start line: 2252
		// Start offset: 0x800898A4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80089928
	// End Line: 2269

	/* begin block 2 */
		// Start line: 4795
	/* end block 2 */
	// End Line: 4796

void MON_Notice(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;
  
  pvVar1 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  if (*(int *)((int)pvVar1 + 0xc4) != 0) {
    *(int *)((int)pvVar1 + 0x11c) = *(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c;
    MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c),
                       *(short *)(*(int *)((int)pvVar1 + 0x164) + 0x1c));
  }
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PupateEntry(struct _Instance *instance /*$a0*/)
 // line 2275, offset 0x80089944
	/* begin block 1 */
		// Start line: 2276
		// Start offset: 0x80089944
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80089944
	// End Line: 2276

	/* begin block 2 */
		// Start line: 4845
	/* end block 2 */
	// End Line: 4846

void MON_PupateEntry(_Instance *instance)

{
  ulong uVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  *puVar3 = *puVar3 | 0x80;
  instance->flags = instance->flags | 0x800;
  instance->flags2 = instance->flags2 | 0x20000000;
  uVar1 = MON_GetTime(instance);
  uVar2 = rand();
  puVar3[0x46] = uVar1 + (uVar2 & 0xfff) + 2000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Pupate(struct _Instance *instance /*$s2*/)
 // line 2285, offset 0x800899bc
	/* begin block 1 */
		// Start line: 2286
		// Start offset: 0x800899BC
		// Variables:
	// 		struct _MonsterVars *mv; // $s3

		/* begin block 1.1 */
			// Start line: 2291
			// Start offset: 0x80089A04
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s0
		// 		static unsigned char pupateObjects[4]; // offset 0x0
		// 		struct Object *cocoonOb; // $s6
		// 		struct _Instance *cocoon; // $s1
		// 		struct _Instance *closest; // $s4
		// 		long closestDist; // $s5
		// 		int burst; // $s7

			/* begin block 1.1.1 */
				// Start line: 2309
				// Start offset: 0x80089A84
				// Variables:
			// 		long dist; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80089B84
			// End Line: 2327
		/* end block 1.1 */
		// End offset: 0x80089C70
		// End Line: 2362
	/* end block 1 */
	// End offset: 0x80089CD8
	// End Line: 2377

	/* begin block 2 */
		// Start line: 4865
	/* end block 2 */
	// End Line: 4866

void MON_Pupate(_Instance *instance)

{
  short sVar1;
  bool bVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  Intro *pIVar6;
  int Data;
  undefined4 local_28;
  void *pvVar7;
  undefined4 local_24;
  _Instance *instance_00;
  uint *puVar8;
  _Instance *Inst;
  undefined2 uVar9;
  Object *pOVar10;
  undefined4 local_30;
  undefined4 in_stack_ffffffd4;
  
  puVar8 = (uint *)instance->extraData;
  pOVar10 = (Object *)0x0;
  if ((*puVar8 & 0x80) == 0) {
    MON_DefaultQueueHandler(instance);
    if (puVar8[0x31] != 0) {
      MON_TurnToPosition(instance,(_Position *)(*(int *)(puVar8[0x31] + 4) + 0x5c),
                         *(short *)(puVar8[0x59] + 0x1c));
    }
    if ((instance->flags2 & 0x10U) != 0) {
      MON_ChangeBehavior(instance,(uint)*(byte *)(puVar8 + 0x56));
    }
  }
  else {
    Inst = (_Instance *)0x0;
    _uVar9 = 99999;
    uVar9 = 0x869f;
    pvVar7 = instance->data;
    bVar2 = false;
    MON_PupateQueueHandler(instance);
    Data = (int)*(char *)((int)pvVar7 + 0x17);
    if (Data != -1) {
      instance_00 = (gameTrackerX.instanceList)->first;
      pOVar10 = (Object *)(&objectAccess)[(byte)(&DAT_800c5a70)[Data]].object;
      while (instance_00 != (_Instance *)0x0) {
        if ((instance_00->object == pOVar10) && ((instance_00->flags & 0x20U) == 0)) {
          pIVar6 = instance->intro;
          lVar3 = MATH3D_LengthXYZ((int)(instance_00->position).x - (int)(pIVar6->position).x,
                                   (int)(instance_00->position).y - (int)(pIVar6->position).y,
                                   (int)(instance_00->position).z - (int)(pIVar6->position).z);
          if (lVar3 < *(short *)((int)puVar8 + 0x136)) {
            lVar3 = MATH3D_LengthXYZ((int)(instance_00->position).x -
                                     (int)((gameTrackerX.playerInstance)->position).x,
                                     (int)(instance_00->position).y -
                                     (int)((gameTrackerX.playerInstance)->position).y,
                                     (int)(instance_00->position).z -
                                     (int)((gameTrackerX.playerInstance)->position).z);
            if (lVar3 < _uVar9) {
              Inst = instance_00;
              _uVar9 = lVar3;
            }
            uVar4 = MON_GetTime(instance);
            if ((puVar8[0x46] < uVar4) && (uVar5 = rand(), (uVar5 & 0xf) == 0)) {
              local_30 = 1;
              Data = SetAnimationInstanceSwitchData(instance_00,0,0,0,1);
              INSTANCE_Post(instance_00,0x8000008,Data);
              uVar4 = MON_GetTime(instance);
              uVar5 = rand();
              puVar8[0x46] = uVar4 + (uVar5 & 0xfff) + 2000;
            }
          }
        }
        uVar9 = (undefined2)_uVar9;
        instance_00 = instance_00->next;
      }
      if (Inst != (_Instance *)0x0) {
        sVar1 = (Inst->position).z;
        *(undefined4 *)&instance->position = *(undefined4 *)&Inst->position;
        (instance->position).z = sVar1;
        uVar5 = puVar8[0x31];
        if ((uVar5 != 0) && (*(_Instance **)(uVar5 + 4) == gameTrackerX.playerInstance)) {
          *(undefined2 *)(uVar5 + 0x14) = uVar9;
        }
      }
    }
    if (instance->currentMainState == 0x1a) {
      if ((Inst == (_Instance *)0x0) && (pOVar10 != (Object *)0x0)) {
        *(undefined2 *)((int)puVar8 + 0x146) = 0;
        MON_KillMonster(instance);
      }
      else {
        _uVar9 = MON_ShouldIAmbushEnemy(instance);
        if (_uVar9 != 0) {
          MON_PlayAnim(instance,(MonsterAnim)
                                CONCAT412(local_24,CONCAT48(local_28,CONCAT44(in_stack_ffffffd4,
                                                                              local_30))),0x1c);
          bVar2 = true;
        }
      }
    }
    else {
      bVar2 = true;
    }
    if (bVar2) {
      instance->flags = instance->flags & 0xfffff7ff;
      instance->flags2 = instance->flags2 & 0xdfffffff;
      *puVar8 = *puVar8 & 0xffffff7f;
      if (Inst != (_Instance *)0x0) {
        INSTANCE_Post(Inst,0x40002,5);
      }
    }
  }
  return;
}



// autogenerated function stub: 
// void /*$ra*/ MON_EmbraceEntry(struct _Instance *instance /*$a0*/)
void MON_EmbraceEntry(struct _Instance *instance)
{ // line 2382, offset 0x80089d04
	/* begin block 1 */
		// Start line: 5091
	/* end block 1 */
	// End Line: 5092

}


// decompiled code
// original method signature: 
// void /*$ra*/ MON_Embrace(struct _Instance *instance /*$s2*/)
 // line 2389, offset 0x80089d28
	/* begin block 1 */
		// Start line: 2390
		// Start offset: 0x80089D28
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterIR *enemy; // $a0

		/* begin block 1.1 */
			// Start line: 2402
			// Start offset: 0x80089D9C
			// Variables:
		// 		struct _Instance *ei; // $s0
		/* end block 1.1 */
		// End offset: 0x80089D9C
		// End Line: 2402
	/* end block 1 */
	// End offset: 0x80089DF0
	// End Line: 2414

	/* begin block 2 */
		// Start line: 5108
	/* end block 2 */
	// End Line: 5109

void MON_Embrace(_Instance *instance)

{
  int iVar1;
  undefined4 unaff_s0;
  _Instance *ei;
  undefined4 unaff_s1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  iVar1 = *(int *)((int)pvVar2 + 0xc4);
  if (((iVar1 == 0) ||
      (*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x164) + 8) + 0x14) < *(short *)(iVar1 + 0x14)))
     || ((*(ushort *)(iVar1 + 0x16) & 0x1000) == 0)) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  else {
    ei = *(_Instance **)(iVar1 + 4);
    MON_DoDrainEffects(instance,ei);
    INSTANCE_Post(ei,0x40006,(int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x164) + 8) + 0x12));
    MON_TurnToPosition(instance,&ei->position,*(short *)(*(int *)((int)pvVar2 + 0x164) + 0x1c));
  }
  MON_DefaultQueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSTER_CalcDamageIntensity(int hp /*$a0*/, int maxHp /*$a1*/)
 // line 2504, offset 0x80089e10
	/* begin block 1 */
		// Start line: 4999
	/* end block 1 */
	// End Line: 5000

	/* begin block 2 */
		// Start line: 5249
	/* end block 2 */
	// End Line: 5250

int MONSTER_CalcDamageIntensity(int hp,int maxHp)

{
  return ((maxHp - hp) * 0x100) / maxHp;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSTER_ProcessClosestVerts(struct _Instance *instance /*$fp*/, struct _SVector *location /*stack 4*/, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb /*stack 8*/, void *cb_data /*stack 12*/)
 // line 2514, offset 0x80089e28
	/* begin block 1 */
		// Start line: 2515
		// Start offset: 0x80089E28
		// Variables:
	// 		int i; // $s2
	// 		struct _Model *model; // $s7
	// 		struct _MVertex *vertexList; // $s4
	// 		struct _Vector locVec; // stack offset -96
	// 		long flag; // stack offset -48

		/* begin block 1.1 */
			// Start line: 2532
			// Start offset: 0x80089EAC
			// Variables:
		// 		struct _MVertex *firstVertex; // $s0
		// 		struct _MVertex *lastVertex; // $s5
		// 		struct _MVertex *modelVertex; // $s0
		// 		struct MATRIX inverse; // stack offset -80
		// 		int tmp; // $a3
		// 		int dist; // $a0
		/* end block 1.1 */
		// End offset: 0x80089FA8
		// End Line: 2565
	/* end block 1 */
	// End offset: 0x80089FC0
	// End Line: 2567

	/* begin block 2 */
		// Start line: 5268
	/* end block 2 */
	// End Line: 5269

void MONSTER_ProcessClosestVerts
               (_Instance *instance,_SVector *location,
               TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb,void *cb_data)

{
  short sVar1;
  int iVar2;
  int iVar3;
  _MVertex *p_Var4;
  short *psVar5;
  int iVar6;
  short *psVar7;
  _MVertex *p_Var8;
  _Model *p_Var9;
  int local_60;
  int local_5c;
  int local_58;
  MATRIX MStack80;
  undefined auStack48 [8];
  
  p_Var9 = instance->object->modelList[instance->currentModel];
  iVar6 = 1;
  p_Var8 = p_Var9->vertexList;
  if (1 < p_Var9->numSegments) {
    psVar7 = &p_Var9->segmentList[1].firstVertex;
    do {
      sVar1 = psVar7[1];
      if ((int)sVar1 != -1) {
        p_Var4 = p_Var8 + *psVar7;
        PIPE3D_InvertTransform(&MStack80,(MATRIX *)(instance->matrix + iVar6));
        SetRotMatrix((undefined4 *)&MStack80);
        SetTransMatrix((int)&MStack80);
        RotTrans(location,&local_60,auStack48);
        if (p_Var4 <= p_Var8 + (int)sVar1) {
          psVar5 = &(p_Var4->vertex).z;
          do {
            iVar2 = (p_Var4->vertex).x - local_60;
            if (iVar2 < 0) {
              iVar2 = -iVar2;
            }
            iVar3 = psVar5[-1] - local_5c;
            if (iVar3 < 0) {
              iVar3 = -iVar3;
            }
            if (iVar3 < iVar2) {
              iVar3 = iVar2;
            }
            iVar2 = *psVar5 - local_58;
            if (iVar2 < 0) {
              iVar2 = -iVar2;
            }
            if (iVar2 < iVar3) {
              iVar2 = iVar3;
            }
            (*processVert_cb)(instance,(int)((int)p_Var4 - (int)p_Var8) >> 3,iVar6,iVar2,cb_data);
            p_Var4 = p_Var4 + 1;
            psVar5 = psVar5 + 4;
          } while (p_Var4 <= p_Var8 + (int)sVar1);
        }
      }
      iVar6 = iVar6 + 1;
      psVar7 = psVar7 + 0xc;
    } while (iVar6 < p_Var9->numSegments);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessBloodyMess(struct _Instance *instance /*$a0*/, int vertidx /*$a1*/, int segidx /*$a2*/, int dist /*$a3*/, void *cb_data /*stack 16*/)
 // line 2574, offset 0x80089ff0
	/* begin block 1 */
		// Start line: 2575
		// Start offset: 0x80089FF0
		// Variables:
	// 		struct _MonsterAttributes *ma; // $t0

		/* begin block 1.1 */
			// Start line: 2587
			// Start offset: 0x8008A020
			// Variables:
		// 		long scl; // $a2
		// 		struct CVECTOR *cv; // $a0
		/* end block 1.1 */
		// End offset: 0x8008A0DC
		// End Line: 2600
	/* end block 1 */
	// End offset: 0x8008A0DC
	// End Line: 2601

	/* begin block 2 */
		// Start line: 5462
	/* end block 2 */
	// End Line: 5463

void ProcessBloodyMess(_Instance *instance,int vertidx,int segidx,int dist,void *cb_data)

{
  byte bVar1;
  NodeType **ppNVar2;
  int iVar3;
  void *pvVar4;
  
  pvVar4 = instance->data;
  if (dist < *(int *)((int)cb_data + 4)) {
    *(int *)cb_data = vertidx;
    *(int *)((int)cb_data + 4) = dist;
    *(int *)((int)cb_data + 8) = segidx;
  }
  if (dist < 100) {
    iVar3 = ((100 - dist) * *(int *)((int)cb_data + 0x10) * 2) / 100;
    ppNVar2 = &((instance[1].next)->node).prev + vertidx;
    if (0x100 < iVar3) {
      iVar3 = 0x100;
    }
    *(byte *)ppNVar2 = ~(byte)((0xff - (uint)*(byte *)((int)pvVar4 + 0x28)) * iVar3 >> 8);
    *(byte *)((int)ppNVar2 + 1) = ~(byte)((0xff - (uint)*(byte *)((int)pvVar4 + 0x29)) * iVar3 >> 8)
    ;
    bVar1 = *(byte *)((int)pvVar4 + 0x2a);
    *(byte *)((int)ppNVar2 + 3) = 1;
    *(byte *)((int)ppNVar2 + 2) = ~(byte)((0xff - (uint)bVar1) * iVar3 >> 8);
    *(undefined4 *)((int)cb_data + 0xc) = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSTER_InitVertexColors(struct _Instance *instance /*$s1*/, struct _Model *model /*$s0*/)
 // line 2603, offset 0x8008a0e4
	/* begin block 1 */
		// Start line: 2604
		// Start offset: 0x8008A0E4
		// Variables:
	// 		int i; // $s0
	// 		struct CVECTOR *ptr; // $v0
	/* end block 1 */
	// End offset: 0x8008A138
	// End Line: 2613

	/* begin block 2 */
		// Start line: 5527
	/* end block 2 */
	// End Line: 5528

void MONSTER_InitVertexColors(_Instance *instance,_Model *model)

{
  _Instance *p_Var1;
  int iVar2;
  
  p_Var1 = (_Instance *)MEMPACK_Malloc(model->numVertices << 2,'!');
  instance[1].next = p_Var1;
  iVar2 = model->numVertices;
  while (iVar2 != 0) {
    (p_Var1->node).prev = (NodeType *)0xffffff;
    iVar2 = iVar2 + -1;
    p_Var1 = (_Instance *)&(p_Var1->node).next;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSTER_StartVertexBlood(struct _Instance *instance /*$s2*/, struct _SVector *location /*$s0*/, int amount /*$s4*/)
 // line 2615, offset 0x8008a14c
	/* begin block 1 */
		// Start line: 2616
		// Start offset: 0x8008A14C
		// Variables:
	// 		struct _Model *model; // $s1
	// 		struct bloodyMessType bmt; // stack offset -88

		/* begin block 1.1 */
			// Start line: 2627
			// Start offset: 0x8008A1B0
			// Variables:
		// 		struct _SVector localloc; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 2638
				// Start offset: 0x8008A220
				// Variables:
			// 		struct _MVertex *vertexList; // $s1
			// 		struct _Vector locVec; // stack offset -56
			// 		long flag; // stack offset -40
			// 		struct MATRIX *segMatrix; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8008A220
			// End Line: 2638
		/* end block 1.1 */
		// End offset: 0x8008A2B0
		// End Line: 2661
	/* end block 1 */
	// End offset: 0x8008A2B0
	// End Line: 2665

	/* begin block 2 */
		// Start line: 5552
	/* end block 2 */
	// End Line: 5553

int MONSTER_StartVertexBlood(_Instance *instance,_SVector *location,int amount)

{
  MATRIX *pMVar1;
  _Model *model;
  _MVertex *p_Var2;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_40;
  uint local_3c;
  undefined local_38 [8];
  ushort local_30;
  undefined auStack40 [8];
  
  model = instance->object->modelList[instance->currentModel];
  if ((instance[1].next == (_Instance *)0x0) &&
     (MONSTER_InitVertexColors(instance,model), instance[1].next == (_Instance *)0x0)) {
    return -1;
  }
  local_40 = *(undefined4 *)location;
  local_3c = *(uint *)&location->z;
  local_58 = -1;
  local_54 = 0x10000;
  local_50 = -1;
  local_4c = 0;
  local_48 = amount;
  MONSTER_ProcessClosestVerts(instance,(_SVector *)&local_40,ProcessBloodyMess,&local_58);
  if (local_54 < 0x33) {
    FX_MakeHitFX((_SVector *)&local_40);
  }
  else {
    p_Var2 = model->vertexList;
    pMVar1 = instance->matrix + local_50;
    SetRotMatrix((undefined4 *)pMVar1);
    SetTransMatrix((int)pMVar1);
    RotTrans(p_Var2 + local_58,local_38,auStack40);
    local_4c = 1;
    local_54 = 0;
    local_3c = local_3c & 0xffff0000 | (uint)local_30;
    FX_MakeHitFX((_SVector *)&local_40);
    MONSTER_ProcessClosestVerts(instance,(_SVector *)&local_40,ProcessBloodyMess,&local_58);
  }
  return local_58;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSTER_VertexBlood(struct _Instance *instance /*$s0*/, int vert /*$a1*/, int amount /*$a2*/)
 // line 2667, offset 0x8008a2d4
	/* begin block 1 */
		// Start line: 2668
		// Start offset: 0x8008A2D4
		// Variables:
	// 		int i; // $v1
	// 		struct _Model *model; // $t0

		/* begin block 1.1 */
			// Start line: 2674
			// Start offset: 0x8008A308
			// Variables:
		// 		struct CVECTOR *c; // $a3

			/* begin block 1.1.1 */
				// Start line: 2683
				// Start offset: 0x8008A320
				// Variables:
			// 		struct _MonsterAttributes *ma; // $v1
			// 		int current; // $a1
			// 		int wanted; // $a0
			// 		int col; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8008A480
			// End Line: 2741
		/* end block 1.1 */
		// End offset: 0x8008A480
		// End Line: 2742
	/* end block 1 */
	// End offset: 0x8008A480
	// End Line: 2743

	/* begin block 2 */
		// Start line: 5687
	/* end block 2 */
	// End Line: 5688

void MONSTER_VertexBlood(_Instance *instance,int vert,int amount)

{
  void *pvVar1;
  int iVar2;
  _Instance *address;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  NodeType **ppNVar6;
  
  address = instance[1].next;
  if (address == (_Instance *)0x0) {
    return;
  }
  ppNVar6 = &(address->node).prev + vert;
  if (amount == 0) {
    MEMPACK_Free((char *)address);
    instance[1].next = (_Instance *)0x0;
    return;
  }
  uVar4 = (uint)*(byte *)((int)ppNVar6 + 1);
  pvVar1 = instance->data;
  if ((uint)*(byte *)ppNVar6 < uVar4) {
    if ((uint)*(byte *)ppNVar6 < (uint)*(byte *)((int)ppNVar6 + 2)) {
      uVar4 = (uint)*(byte *)ppNVar6;
      uVar3 = (uint)*(byte *)((int)pvVar1 + 0x28);
      goto LAB_8008a388;
    }
  }
  else {
    if (uVar4 < *(byte *)((int)ppNVar6 + 2)) {
      uVar3 = (uint)*(byte *)((int)pvVar1 + 0x29);
      goto LAB_8008a388;
    }
  }
  uVar4 = (uint)*(byte *)((int)ppNVar6 + 2);
  uVar3 = (uint)*(byte *)((int)pvVar1 + 0x2a);
LAB_8008a388:
  if ((*(byte *)((int)ppNVar6 + 3) == 1) &&
     ((int)uVar4 < (int)((0x100 - amount) * (0xff - uVar3)) >> 8)) {
    iVar2 = instance->object->modelList[instance->currentModel]->numVertices;
    address = instance[1].next;
    if (iVar2 != 0) {
      pcVar5 = (char *)((int)&(address->node).prev + 3);
      do {
        if (*pcVar5 == '\x01') {
          uVar4 = (uint)*(byte *)&(address->node).prev + 8;
          if (uVar4 < 0x100) {
            *(char *)&(address->node).prev = (char)uVar4;
          }
          else {
            *(undefined *)&(address->node).prev = 0xff;
          }
          if ((uint)(byte)pcVar5[-2] + 8 < 0x100) {
            pcVar5[-2] = (char)((uint)(byte)pcVar5[-2] + 8);
          }
          else {
            pcVar5[-2] = -1;
          }
          if ((uint)(byte)pcVar5[-1] + 8 < 0x100) {
            pcVar5[-1] = (char)((uint)(byte)pcVar5[-1] + 8);
          }
          else {
            pcVar5[-1] = -1;
          }
          if (((uint)(address->node).prev & 0xffffff) == 0xffffff) {
            *pcVar5 = '\0';
          }
        }
        iVar2 = iVar2 + -1;
        pcVar5 = pcVar5 + 4;
        address = (_Instance *)&(address->node).next;
      } while (iVar2 != 0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessBurntMess(struct _Instance *instance /*$a0*/, int vertidx /*$a1*/, int segidx /*$a2*/, int dist /*$a3*/, void *cb_data /*stack 16*/)
 // line 2750, offset 0x8008a490
	/* begin block 1 */
		// Start line: 2751
		// Start offset: 0x8008A490
		// Variables:
	// 		short scl; // $a2
	// 		struct burntTuneType *burntTune; // $t0
	/* end block 1 */
	// End offset: 0x8008A4F4
	// End Line: 2771

	/* begin block 2 */
		// Start line: 5880
	/* end block 2 */
	// End Line: 5881

void ProcessBurntMess(_Instance *instance,int vertidx,int segidx,int dist,void *cb_data)

{
  undefined uVar1;
  
  if (dist < *(int *)((int)cb_data + 4)) {
    *(int *)cb_data = vertidx;
    *(int *)((int)cb_data + 4) = dist;
    *(int *)((int)cb_data + 8) = segidx;
  }
  if ((**(int **)((int)cb_data + 0xc) <= dist) ||
     (_uVar1 = ((dist << 0xc) / **(int **)((int)cb_data + 0xc) << 0x10) >> 0x14,
     uVar1 = (undefined)_uVar1, 0xfe < _uVar1)) {
    uVar1 = 0xfe;
  }
  _uVar1 = vertidx * 4;
  *(undefined *)(&((instance[1].next)->node).prev + vertidx) = uVar1;
  *(undefined *)((int)&((instance[1].next)->node).prev + _uVar1 + 1) = uVar1;
  *(undefined *)((int)&((instance[1].next)->node).prev + _uVar1 + 2) = uVar1;
  *(undefined *)((int)&((instance[1].next)->node).prev + _uVar1 + 3) = 1;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSTER_StartVertexBurnt(struct _Instance *instance /*$s2*/, struct _SVector *location /*$s4*/, struct burntTuneType *burntTune /*$s0*/)
 // line 2781, offset 0x8008a53c
	/* begin block 1 */
		// Start line: 2782
		// Start offset: 0x8008A53C
		// Variables:
	// 		struct _Model *model; // $s1
	// 		struct burntMessType bmt; // stack offset -80

		/* begin block 1.1 */
			// Start line: 2792
			// Start offset: 0x8008A5A0
			// Variables:
		// 		struct _SVector localloc; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 2802
				// Start offset: 0x8008A610
				// Variables:
			// 		struct _MVertex *vertexList; // $s1
			// 		struct _Vector locVec; // stack offset -56
			// 		long flag; // stack offset -40
			// 		struct MATRIX *segMatrix; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8008A610
			// End Line: 2802
		/* end block 1.1 */
		// End offset: 0x8008A698
		// End Line: 2823
	/* end block 1 */
	// End offset: 0x8008A698
	// End Line: 2826

	/* begin block 2 */
		// Start line: 5944
	/* end block 2 */
	// End Line: 5945

int MONSTER_StartVertexBurnt(_Instance *instance,_SVector *location,burntTuneType *burntTune)

{
  MATRIX *pMVar1;
  _Model *model;
  _MVertex *p_Var2;
  int local_50;
  int local_4c;
  int local_48;
  burntTuneType *local_44;
  undefined4 local_40;
  uint local_3c;
  undefined local_38 [8];
  ushort local_30;
  undefined auStack40 [8];
  
  model = instance->object->modelList[instance->currentModel];
  if ((instance[1].next == (_Instance *)0x0) &&
     (MONSTER_InitVertexColors(instance,model), instance[1].next == (_Instance *)0x0)) {
    return -1;
  }
  local_40 = *(undefined4 *)location;
  local_3c = *(uint *)&location->z;
  local_50 = -1;
  local_4c = 0x10000;
  local_48 = -1;
  local_44 = burntTune;
  MONSTER_ProcessClosestVerts(instance,(_SVector *)&local_40,ProcessBurntMess,&local_50);
  if (burntTune->burntDist >> 1 < local_4c) {
    p_Var2 = model->vertexList;
    pMVar1 = instance->matrix + local_48;
    SetRotMatrix((undefined4 *)pMVar1);
    SetTransMatrix((int)pMVar1);
    RotTrans(p_Var2 + local_50,local_38,auStack40);
    local_4c = 0;
    local_3c = local_3c & 0xffff0000 | (uint)local_30;
    FX_MakeHitFX((_SVector *)&local_40);
    MONSTER_ProcessClosestVerts(instance,(_SVector *)&local_40,ProcessBurntMess,&local_50);
  }
  else {
    FX_MakeHitFX((_SVector *)&local_40);
  }
  return local_50;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSTER_VertexBurnt(struct _Instance *instance /*$a0*/, struct burntTuneType *burntTune /*$a1*/)
 // line 2828, offset 0x8008a6bc
	/* begin block 1 */
		// Start line: 2830
		// Start offset: 0x8008A6BC
		// Variables:
	// 		int i; // $a3
	// 		int fade; // $a2
	// 		struct _Model *model; // $t0

		/* begin block 1.1 */
			// Start line: 2839
			// Start offset: 0x8008A6F4
			// Variables:
		// 		struct CVECTOR *c; // $v1
		/* end block 1.1 */
		// End offset: 0x8008A748
		// End Line: 2848
	/* end block 1 */
	// End offset: 0x8008A760
	// End Line: 2851

	/* begin block 2 */
		// Start line: 6062
	/* end block 2 */
	// End Line: 6063

	/* begin block 3 */
		// Start line: 6063
	/* end block 3 */
	// End Line: 6064

	/* begin block 4 */
		// Start line: 6064
	/* end block 4 */
	// End Line: 6065

void MONSTER_VertexBurnt(_Instance *instance,burntTuneType *burntTune)

{
  char cVar1;
  NodeType **ppNVar2;
  int iVar3;
  int iVar4;
  _Model *p_Var5;
  
  p_Var5 = instance->object->modelList[instance->currentModel];
  iVar3 = burntTune->fadeDelta;
  if ((instance[1].next != (_Instance *)0x0) && (iVar4 = 0, 0 < p_Var5->numVertices)) {
    do {
      ppNVar2 = &((instance[1].next)->node).prev + iVar4;
      cVar1 = (char)iVar3;
      if (iVar3 <= (int)(uint)*(byte *)ppNVar2) {
        *(byte *)ppNVar2 = *(byte *)ppNVar2 - cVar1;
      }
      if (iVar3 <= (int)(uint)*(byte *)((int)ppNVar2 + 1)) {
        *(byte *)((int)ppNVar2 + 1) = *(byte *)((int)ppNVar2 + 1) - cVar1;
      }
      if (iVar3 <= (int)(uint)*(byte *)((int)ppNVar2 + 2)) {
        *(byte *)((int)ppNVar2 + 2) = *(byte *)((int)ppNVar2 + 2) - cVar1;
      }
      *(byte *)((int)ppNVar2 + 3) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < p_Var5->numVertices);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DamageEffect(struct _Instance *instance /*$s2*/, struct evFXHitData *data /*$s0*/)
 // line 2858, offset 0x8008a768
	/* begin block 1 */
		// Start line: 2859
		// Start offset: 0x8008A768
		// Variables:
	// 		struct _SVector accel; // stack offset -104
	// 		struct _MonsterVars *mv; // $s4

		/* begin block 1.1 */
			// Start line: 2866
			// Start offset: 0x8008A7C4
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s3

			/* begin block 1.1.1 */
				// Start line: 2870
				// Start offset: 0x8008A7E4
				// Variables:
			// 		struct MATRIX *mat; // $s0
			// 		struct _SVector location; // stack offset -96
			// 		struct _SVector vel; // stack offset -88
			// 		struct _SVector accel; // stack offset -80
			/* end block 1.1.1 */
			// End offset: 0x8008A8A0
			// End Line: 2880

			/* begin block 1.1.2 */
				// Start line: 2884
				// Start offset: 0x8008A8B8
				// Variables:
			// 		struct MATRIX *mat; // $s0
			// 		struct _SVector location; // stack offset -72
			// 		struct _SVector vel; // stack offset -64
			/* end block 1.1.2 */
			// End offset: 0x8008A918
			// End Line: 2893

			/* begin block 1.1.3 */
				// Start line: 2897
				// Start offset: 0x8008A92C
				// Variables:
			// 		struct Object *flame; // $v0

				/* begin block 1.1.3.1 */
					// Start line: 2904
					// Start offset: 0x8008A93C
					// Variables:
				// 		struct _Model *model; // $s0
				/* end block 1.1.3.1 */
				// End offset: 0x8008A994
				// End Line: 2910
			/* end block 1.1.3 */
			// End offset: 0x8008A9A4
			// End Line: 2912

			/* begin block 1.1.4 */
				// Start line: 2916
				// Start offset: 0x8008A9E8
				// Variables:
			// 		struct MATRIX *mat; // $s0
			// 		struct _SVector location; // stack offset -56
			// 		struct _SVector vel; // stack offset -48
			// 		struct _SVector accel; // stack offset -40
			// 		int n; // $s1
			// 		int cnt; // $s4
			/* end block 1.1.4 */
			// End offset: 0x8008AAFC
			// End Line: 2938
		/* end block 1.1 */
		// End offset: 0x8008AAFC
		// End Line: 2939
	/* end block 1 */
	// End offset: 0x8008ABA8
	// End Line: 2961

	/* begin block 2 */
		// Start line: 6134
	/* end block 2 */
	// End Line: 6135

/* WARNING: Removing unreachable block (ram,0x8008a93c) */

void MON_DamageEffect(_Instance *instance,evFXHitData *data)

{
  int amount;
  ulong uVar1;
  _G2Bool_Enum _Var2;
  int lifetime;
  uint uVar3;
  evFXHitData *location;
  MATRIX *pMVar4;
  void *pvVar5;
  uint *puVar6;
  int iVar7;
  undefined4 local_68;
  undefined4 local_64;
  _SVector local_60;
  _SVector _Stack88;
  undefined4 local_50;
  undefined4 local_4c;
  _SVector local_48;
  _SVector _Stack64;
  _SVector local_38;
  _SVector local_30;
  _SVector local_28;
  
  local_68 = 0;
  local_64 = 0xfffe;
  puVar6 = (uint *)instance->extraData;
  if (data == (evFXHitData *)0x0) {
    pvVar5 = instance->data;
    if ((*puVar6 & 0x10000200) == 0x10000000) {
      amount = rand();
      pMVar4 = instance->matrix +
               amount % instance->object->modelList[instance->currentModel]->numSegments;
      memset(&_Stack88,0,8);
      local_50 = 0;
      local_4c = 2;
      local_60.x = *(short *)pMVar4->t;
      local_60.y = *(short *)(pMVar4->t + 1);
      local_60.z = *(short *)(pMVar4->t + 2);
      FX_Blood(&local_60,&_Stack88,(_SVector *)&local_50,1,0xff2800,8);
    }
    if ((*puVar6 & 0x800010) == 0x800010) {
      pMVar4 = instance->matrix + *(byte *)((int)pvVar5 + 0x18);
      memset(&_Stack64,0,8);
      local_48.x = *(short *)pMVar4->t;
      local_48.y = *(short *)(pMVar4->t + 1);
      local_48.z = *(short *)(pMVar4->t + 2);
      FX_Blood(&local_48,&_Stack64,(_SVector *)&local_68,4,0x180080,8);
    }
    if ((*puVar6 & 0x400000) != 0) {
      MONSTER_VertexBurnt(instance,&burntTest);
    }
    if ((*puVar6 & 0x400) == 0) {
      return;
    }
    if ((*(uint *)((int)pvVar5 + 0x10) & 2) == 0) {
      return;
    }
    uVar1 = MON_GetTime(instance);
    if (puVar6[0x46] <= uVar1) {
      return;
    }
    MONSTER_VertexBurnt(instance,&burntTest);
    local_30.y = 0;
    local_30.x = 0;
    local_30.z = 0xc;
    local_28.y = 0;
    local_28.x = 0;
    local_28.z = 0;
    iVar7 = instance->object->modelList[instance->currentModel]->numSegments;
    amount = 1;
    if (iVar7 < 2) {
      return;
    }
    do {
      _Var2 = G2Anim_IsSegmentEnabled(&instance->anim,amount);
      if (_Var2 != G2FALSE) {
        pMVar4 = instance->matrix + amount;
        lifetime = rand();
        local_38.x = *(short *)pMVar4->t + ((ushort)lifetime & 3);
        lifetime = rand();
        local_38.y = *(short *)(pMVar4->t + 1) + ((ushort)lifetime & 3);
        lifetime = rand();
        local_38.z = *(short *)(pMVar4->t + 2) + ((ushort)lifetime & 3);
        uVar3 = rand();
        if ((uVar3 & 0x1f) == 0) {
          lifetime = 0x20;
        }
        else {
          lifetime = 2;
        }
        FX_Dot(&local_38,&local_30,&local_28,-0x100,0x808080,0x50,lifetime,0);
      }
      amount = amount + 1;
    } while (amount < iVar7);
    return;
  }
  if (data->type == 0x20) {
    location = data;
    if (data->amount == 0) goto LAB_8008ab34;
  }
  else {
    if (data->type != 0x10) {
      amount = MONSTER_CalcDamageIntensity
                         ((int)*(short *)(puVar6 + 0x50),(int)*(short *)((int)puVar6 + 0x142));
      amount = MONSTER_StartVertexBlood(instance,(_SVector *)data,amount);
      *(short *)(puVar6 + 0x52) = (short)amount;
      goto LAB_8008ab78;
    }
LAB_8008ab34:
    location = (evFXHitData *)&instance->position;
  }
  MONSTER_StartVertexBurnt(instance,(_SVector *)location,&burntTest);
LAB_8008ab78:
  if ((int)data->amount != 0) {
    FX_Blood((_SVector *)data,&data->velocity,(_SVector *)&local_68,(int)data->amount,0x180080,8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DefaultInit(struct _Instance *instance /*$s3*/)
 // line 2966, offset 0x8008abcc
	/* begin block 1 */
		// Start line: 2967
		// Start offset: 0x8008ABCC
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s1
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _HModel *hModel; // $v0
	// 		struct _HPrim *hprim; // $v0
	// 		int i; // $a0
	// 		int state; // $a1
	/* end block 1 */
	// End offset: 0x8008ADB8
	// End Line: 3037

	/* begin block 2 */
		// Start line: 6397
	/* end block 2 */
	// End Line: 6398

void MON_DefaultInit(_Instance *instance)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  _HModel *p_Var5;
  byte *pbVar6;
  undefined4 local_18;
  undefined4 local_14;
  void *pvVar7;
  uint *puVar8;
  
  puVar8 = (uint *)instance->extraData;
  pvVar7 = instance->data;
  if ((*puVar8 & 0x1000000) != 0) {
    MONAPI_CheckGenerator(instance);
  }
  iVar3 = MON_OnGround(instance);
  if (iVar3 == 0) {
    uVar4 = *puVar8 & 0xfffffffd;
  }
  else {
    uVar4 = *puVar8 | 2;
  }
  *puVar8 = uVar4;
  if (instance->hModelList != (_HModel *)0x0) {
    p_Var5 = instance->hModelList + instance->currentModel;
    iVar3 = p_Var5->numHPrims;
    if (iVar3 != 0) {
      pbVar6 = &p_Var5->hPrimList->withFlags;
      do {
        if (pbVar6[2] != 1) {
          *pbVar6 = *pbVar6 & 0xa5;
        }
        iVar3 = iVar3 + -1;
        pbVar6 = pbVar6 + 8;
      } while (iVar3 != 0);
    }
  }
  if (*(byte *)((int)pvVar7 + 0x1a) != 0) {
    G2Anim_AttachControllerToSeg(&instance->anim,(uint)*(byte *)((int)pvVar7 + 0x1a),0xe);
    G2Anim_DisableController(&instance->anim,(uint)*(byte *)((int)pvVar7 + 0x1a),0xe);
  }
  bVar1 = *(byte *)((int)pvVar7 + 0x22);
  if ((bVar1 != 0) && ((uint)bVar1 != (uint)*(byte *)((int)pvVar7 + 0x1a))) {
    G2Anim_AttachControllerToSeg(&instance->anim,(uint)bVar1,0xe);
    G2Anim_DisableController(&instance->anim,(uint)*(byte *)((int)pvVar7 + 0x22),0xe);
  }
  if (*(byte *)((int)pvVar7 + 0x25) != 0) {
    G2Anim_DisableSegment(&instance->anim,(uint)*(byte *)((int)pvVar7 + 0x25));
  }
  if ((instance->object->oflags & 0x80000U) == 0) {
    instance->fadeValue = 0x1000;
    MON_StartSpecialFade(instance,0,0x14);
  }
  if (((((instance->flags & 2U) == 0) && (cVar2 = *(char *)((int)puVar8 + 0x156), cVar2 != '\x04'))
      && (cVar2 != '\x10')) && (cVar2 == '\r')) {
    *(undefined2 *)(puVar8 + 0x54) = 0;
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CleanUp(struct _Instance *instance /*$s2*/)
 // line 3043, offset 0x8008addc
	/* begin block 1 */
		// Start line: 3044
		// Start offset: 0x8008ADDC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s1
	/* end block 1 */
	// End offset: 0x8008AE64
	// End Line: 3072

	/* begin block 2 */
		// Start line: 6565
	/* end block 2 */
	// End Line: 6566

void MON_CleanUp(_Instance *instance)

{
  byte bVar1;
  int slotID;
  void *pvVar2;
  void *pvVar3;
  
  pvVar2 = instance->extraData;
  pvVar3 = instance->data;
  MON_DropAllObjects(instance);
  slotID = (int)*(char *)((int)pvVar2 + 0x162);
  if (slotID != -1) {
    ENMYPLAN_ReleasePlanningWorkspace(slotID);
  }
  if (*(byte *)((int)pvVar3 + 0x1a) != 0) {
    G2Anim_DetachControllerFromSeg(&instance->anim,(uint)*(byte *)((int)pvVar3 + 0x1a),0xe);
  }
  bVar1 = *(byte *)((int)pvVar3 + 0x22);
  if ((bVar1 != 0) && ((uint)bVar1 != (uint)*(byte *)((int)pvVar3 + 0x1a))) {
    G2Anim_DetachControllerFromSeg(&instance->anim,(uint)bVar1,0xe);
  }
  return;
}





