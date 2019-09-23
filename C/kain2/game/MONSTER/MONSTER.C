#include "THISDUST.H"
#include "MONSTER.H"

// burntTuneType @0x800CF674, len = 0x00000008
burntTest =
    {
        // int @0x800CF674, len = 0x00000004
        .burntDist = 0x12c,
        // int @0x800CF678, len = 0x00000004
        .fadeDelta = 0x2};
// decompiled code
// original method signature:
// void /*$ra*/ MON_DoCombatTimers(struct _Instance *instance /*$s2*/)
// line 101, offset 0x800871fc
/* begin block 1 */
// Start line: 102
// Start offset: 0x800871FC
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		unsigned long curtime; // $s1

/* begin block 1.1 */
// Start line: 117
// Start offset: 0x80087280
// Variables:
// 		struct _MonsterCombatAttributes *combat; // $v0
/* end block 1.1 */
// End offset: 0x800872F0
// End Line: 126
/* end block 1 */
// End offset: 0x800873CC
// End Line: 142

/* begin block 2 */
// Start line: 202
/* end block 2 */
// End Line: 203

void MON_DoCombatTimers(_Instance *instance)

{
  ulong uVar1;
  int amount;
  uint uVar2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  uVar1 = MON_GetTime(instance);
  uVar2 = *puVar3;
  if ((uVar2 & 0x10) == 0)
  {
    if (((uVar2 & 0x2000) == 0) && (*(short *)(puVar3 + 0x4c) < *(short *)((int)puVar3 + 0x132)))
    {
      amount = (uint) * (ushort *)(puVar3 + 0x4c) +
               ((int)*(short *)(*(int *)(puVar3[0x55] + 8) + 4) * gameTrackerX.timeMult >> 0xc);
      *(short *)(puVar3 + 0x4c) = (short)amount;
      if ((int)*(short *)((int)puVar3 + 0x132) < amount * 0x10000 >> 0x10)
      {
        *(undefined2 *)(puVar3 + 0x4c) = *(undefined2 *)((int)puVar3 + 0x132);
      }
      amount = MONSTER_CalcDamageIntensity((int)*(short *)(puVar3 + 0x4c), (int)*(short *)((int)puVar3 + 0x132));
      MONSTER_VertexBlood(instance, (int)*(short *)(puVar3 + 0x4e), amount);
    }
  }
  else
  {
    if (puVar3[0x3e] < uVar1)
    {
      *puVar3 = uVar2 & 0xff7fffef;
    }
  }
  if (((*puVar3 & 0x100) != 0) && (puVar3[0x3f] < uVar1))
  {
    *puVar3 = *puVar3 & 0xfffffeff;
  }
  if (uVar1 % 1000 < (uVar1 - gameTrackerX.lastLoopTime) % 1000)
  {
    amount = rand();
    *(char *)((int)puVar3 + 0x151) = (char)amount + (char)(amount / 100) * -100;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ChangeHumanOpinion(struct _Instance *instance /*$a0*/)
// line 147, offset 0x800873e4
/* begin block 1 */
// Start line: 148
// Start offset: 0x800873E4
// Variables:
// 		int good; // $v0

/* begin block 1.1 */
// Start line: 172
// Start offset: 0x80087404
// Variables:
// 		int opinion; // $s0
/* end block 1.1 */
// End offset: 0x8008747C
// End Line: 188
/* end block 1 */
// End offset: 0x8008747C
// End Line: 189

/* begin block 2 */
// Start line: 298
/* end block 2 */
// End Line: 299

void MON_ChangeHumanOpinion(_Instance *instance)

{
  ulong uVar1;
  int iVar2;

  uVar1 = INSTANCE_Query(instance, 1);
  if ((uVar1 & 0xc000) != 0)
  {
    iVar2 = (int)GlobalSave->humanOpinionOfRaziel + -5;
    if (-0x29 < (int)GlobalSave->humanOpinionOfRaziel)
    {
      iVar2 = -0x28;
    }
    if (iVar2 < -0x7fff)
    {
      iVar2 = -0x7fff;
    }
    else
    {
      if (0x7fff < iVar2)
      {
        iVar2 = 0x7fff;
      }
    }
    if ((iVar2 < 1) && (0 < GlobalSave->humanOpinionOfRaziel))
    {
      HUMAN_GetAngry();
    }
    GlobalSave->humanOpinionOfRaziel = (short)iVar2;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_CutOut_Monster(struct _Instance *instance /*$s2*/, int fade_amount /*$t4*/, int startseg /*$a2*/, int endseg /*$a3*/)
// line 192, offset 0x8008748c
/* begin block 1 */
// Start line: 193
// Start offset: 0x8008748C
// Variables:
// 		struct _SVector point; // stack offset -56
// 		struct _SVector normal; // stack offset -48
// 		struct _SVector p1; // stack offset -40
// 		struct _SVector p2; // stack offset -32
// 		int tmp; // $t0
// 		struct MATRIX *mat; // $a0

/* begin block 1.1 */
// Start line: 221
// Start offset: 0x800875D0
// Variables:
// 		long color; // stack offset -24

/* begin block 1.1.1 */
// Start line: 221
// Start offset: 0x800875D0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a1
// 		short _x1; // $a2
// 		short _y1; // $a3
// 		short _z1; // $t0
// 		struct _SVector *_v; // $a0
/* end block 1.1.1 */
// End offset: 0x800875D0
// End Line: 221
/* end block 1.1 */
// End offset: 0x80087678
// End Line: 233
/* end block 1 */
// End offset: 0x800876C8
// End Line: 238

/* begin block 2 */
// Start line: 389
/* end block 2 */
// End Line: 390

void MON_CutOut_Monster(_Instance *instance, int fade_amount, int startseg, int endseg)

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
  undefined *local_18[2];

  if (instance->matrix != (MATRIX *)0x0)
  {
    pMVar3 = instance->matrix + startseg;
    pMVar4 = instance->matrix + endseg;
    iVar1 = (int)*(short *)pMVar3->t - (int)*(short *)pMVar4->t;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 7;
    }
    iVar2 = (int)*(short *)(pMVar3->t + 1) - (int)*(short *)(pMVar4->t + 1);
    local_20 = (short)(iVar1 >> 3);
    local_28 = *(short *)pMVar3->t + local_20;
    local_20 = *(short *)pMVar4->t - local_20;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 7;
    }
    iVar1 = (int)*(short *)(pMVar3->t + 2) - (int)*(short *)(pMVar4->t + 2);
    local_1e = (short)(iVar2 >> 3);
    local_26 = *(short *)(pMVar3->t + 1) + local_1e;
    local_1e = *(short *)(pMVar4->t + 1) - local_1e;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 7;
    }
    local_1c = (short)(iVar1 >> 3);
    local_24 = *(short *)(pMVar3->t + 2) + local_1c;
    local_1c = *(short *)(pMVar4->t + 2) - local_1c;
    LoadAverageShort12((uint *)&local_20, (uint *)&local_28, fade_amount, 0x1000 - fade_amount,
                       (uint *)&local_38);
    if (((instance->halvePlane).flags & 8U) == 0)
    {
      local_18[0] = (undefined *)0x0;
      local_30.x = local_20 - local_28;
      local_30.y = local_1e - local_26;
      local_30.z = local_1c - local_24;
      CAMERA_Normalize(&local_30);
      local_18[0] = &DAT_000080ff;
      FX_DoInstancePowerRing(instance, (long)&DAT_00002ee0, (long *)local_18, 0, 2);
      FX_DoInstancePowerRing(instance, (long)&DAT_00002ee0, (long *)local_18, 0, 1);
      (instance->halvePlane).flags = 8;
      (instance->halvePlane).a = local_30.x;
      (instance->halvePlane).b = local_30.y;
      (instance->halvePlane).c = local_30.z;
    }
    (instance->halvePlane).d =
        -((int)(instance->halvePlane).a * (int)local_38 +
              (int)(instance->halvePlane).b * (int)local_36 +
              (int)(instance->halvePlane).c * (int)local_34 >>
          0xc);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_DeadEntry(struct _Instance *instance /*$s1*/)
// line 249, offset 0x800876e0
/* begin block 1 */
// Start line: 250
// Start offset: 0x800876E0
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x800877BC
// End Line: 278

/* begin block 2 */
// Start line: 524
/* end block 2 */
// End Line: 525

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
      (uVar1 = INSTANCE_Query(*(_Instance **)(puVar2[0x31] + 4), 1), (uVar1 & 1) != 0))
  {
    MON_ChangeHumanOpinion(instance);
  }
  if (*(char *)((int)puVar2 + 0x145) == -1)
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
                 0x18);
  }
  *puVar2 = *puVar2 | 0x200;
  instance->flags2 = instance->flags2 & 0xfffdff3f;
  puVar2[0x3e] = 0;
  if (*(short *)(puVar2 + 0x4d) == 0)
  {
    uVar1 = MON_GetTime(instance);
    puVar2[0x3e] = uVar1;
  }
  else
  {
    if (puVar2[0x36] == 0)
    {
      MON_BirthSoul(instance, 1);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Dead(struct _Instance *instance /*$s2*/)
// line 280, offset 0x800877d0
/* begin block 1 */
// Start line: 281
// Start offset: 0x800877D0
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct _Instance *soul; // $s5
// 		struct __Event *message; // $v0
// 		int reanimate; // $s6

/* begin block 1.1 */
// Start line: 304
// Start offset: 0x8008787C
// Variables:
// 		struct _MonsterAttributes *ma; // $s0
// 		int fade_amount; // $a1
/* end block 1.1 */
// End offset: 0x800878B0
// End Line: 316

/* begin block 1.2 */
// Start line: 336
// Start offset: 0x80087930
// Variables:
// 		struct _Model *model; // $s0
// 		int i; // $s0
// 		struct CVECTOR *ptr; // $v0
/* end block 1.2 */
// End offset: 0x80087980
// End Line: 344

/* begin block 1.3 */
// Start line: 347
// Start offset: 0x800879A8
// Variables:
// 		struct _Instance *imp; // $s0
// 		struct _Instance *closest; // $s3

/* begin block 1.3.1 */
// Start line: 351
// Start offset: 0x800879C8
// Variables:
// 		long closestdist; // $s4

/* begin block 1.3.1.1 */
// Start line: 360
// Start offset: 0x80087A3C
// Variables:
// 		long dist; // $v1
/* end block 1.3.1.1 */
// End offset: 0x80087A7C
// End Line: 367
/* end block 1.3.1 */
// End offset: 0x80087A8C
// End Line: 370
/* end block 1.3 */
// End offset: 0x80087B18
// End Line: 383

/* begin block 1.4 */
// Start line: 402
// Start offset: 0x80087B98
// Variables:
// 		struct SVECTOR New; // stack offset -96
// 		struct SVECTOR Old; // stack offset -88
// 		struct _PCollideInfo pcinfo; // stack offset -80
/* end block 1.4 */
// End offset: 0x80087C20
// End Line: 421

/* begin block 1.5 */
// Start line: 448
// Start offset: 0x80087D20
// Variables:
// 		struct _MonsterAttributes *ma; // $a0
/* end block 1.5 */
// End offset: 0x80087E30
// End Line: 482
/* end block 1 */
// End offset: 0x80087EDC
// End Line: 522

/* begin block 2 */
// Start line: 587
/* end block 2 */
// End Line: 588

void MON_Dead(_Instance *instance)

{
  bool bVar1;
  CVECTOR *pCVar2;
  int Message;
  long lVar3;
  ulong uVar4;
  int Data;
  __Event *p_Var5;
  undefined *puVar6;
  uint introUniqueID;
  void *pvVar7;
  _Model *p_Var8;
  _Instance *instance_00;
  uint *puVar9;
  _Instance *instance_01;
  _Instance *instance_02;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 in_stack_ffffff9c;
  SVECTOR local_60;
  SVECTOR local_58;
  _PCollideInfo _Stack80;

  puVar9 = (uint *)instance->extraData;
  instance_02 = (_Instance *)0x0;
  introUniqueID = puVar9[0x36];
  bVar1 = false;
  if (introUniqueID == 0)
  {
    if ((*puVar9 & 0x200) == 0)
    {
      if ((instance->flags2 & 0x10U) != 0)
      {
        MON_PlayCombatIdle(instance, 2);
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_6c, local_70));
      }
    }
    else
    {
      pvVar7 = instance->data;
      uVar4 = MON_GetTime(instance);
      if ((int)(uVar4 - puVar9[0x3e]) < 0x1000)
      {
        MON_CutOut_Monster(instance, uVar4 - puVar9[0x3e], (uint) * (byte *)((int)pvVar7 + 0x19),
                           (uint) * (byte *)((int)pvVar7 + 0x21));
      }
      else
      {
        MON_KillMonster(instance);
      }
    }
  }
  else
  {
    if (introUniqueID != 0x7fffffff)
    {
      instance_02 = INSTANCE_Find(introUniqueID);
    }
    if (instance_02 == (_Instance *)0x0)
    {
      MON_BirthSoul(instance, 1);
    }
    else
    {
      if (*(int *)((int)instance_02->extraData + 0xd8) == 0)
      {
        *(long *)((int)instance_02->extraData + 0xd8) = instance->introUniqueID;
      }
    }
  }
  if (*(char *)(puVar9 + 0x51) == '\x06')
  {
    MON_KillMonster(instance);
  }
  else
  {
    if (((byte)(*(char *)(puVar9 + 0x51) - 1U) < 3) && (instance->perVertexColor == (CVECTOR *)0x0))
    {
      p_Var8 = instance->object->modelList[(int)instance->currentModel];
      pCVar2 = (CVECTOR *)MEMPACK_Malloc(p_Var8->numVertices << 2, '!');
      instance->perVertexColor = pCVar2;
      Data = p_Var8->numVertices;
      while (Data != 0)
      {
        *pCVar2 = (CVECTOR)0x101010;
        Data = Data + -1;
        pCVar2 = pCVar2 + 1;
      }
    }
    else
    {
      if ((*(char *)(puVar9 + 0x51) == '\0') && (puVar9[0x34] == 0))
      {
        instance->flags2 = instance->flags2 | 0x80;
        instance_01 = (_Instance *)0x0;
        if (puVar9[0x35] == 0)
        {
          instance_00 = (gameTrackerX.instanceList)->first;
          Data = 1000;
          while (instance_00 != (_Instance *)0x0)
          {
            if (((((instance != instance_00) && (instance_00->object != (Object *)0x0)) &&
                  ((instance_00->object->oflags2 & 0x40000U) != 0)) &&
                 (instance_00->LinkParent == (_Instance *)0x0)) &&
                (((Message = CheckPhysObFamily(instance_00, 0), Message != 0 ||
                                                                    (Message = CheckPhysObFamily(instance_00, 3), Message != 0)) &&
                  (lVar3 = MATH3D_LengthXYZ((int)(instance_00->position).x -
                                                (int)(instance->position).x,
                                            (int)(instance_00->position).y -
                                                (int)(instance->position).y,
                                            (int)(instance_00->position).z -
                                                (int)(instance->position).z),
                   lVar3 < Data))))
            {
              instance_01 = instance_00;
              Data = lVar3;
            }
            instance_00 = instance_00->next;
          }
        }
        else
        {
          instance_01 = INSTANCE_Find(puVar9[0x35]);
        }
        if (instance_01 != (_Instance *)0x0)
        {
          Data = CheckPhysObFamily(instance_01, 3);
          if (Data == 0)
          {
            local_70 = 3;
            Data = SetObjectData(0, 0, 0, instance, 3);
            Message = 0x800002;
          }
          else
          {
            local_70 = 0;
            local_6c = 0;
            local_68 = 1;
            Data = SetObjectBreakOffData(instance, 3, 0, 0, 0, 0, 1);
            Message = 0x800023;
          }
          INSTANCE_Post(instance_01, Message, Data);
          introUniqueID = instance_01->introUniqueID;
          *(_Instance **)(puVar9 + 0x34) = instance_01;
          puVar9[0x35] = introUniqueID;
          instance->flags2 = instance->flags2 & 0xffffff7f;
        }
      }
      else
      {
        if (*(char *)(puVar9 + 0x51) == '\x03')
        {
          if ((puVar9[0x37] != 0) && (uVar4 = MON_GetTime(instance), puVar9[0x42] < uVar4))
          {
            SndEndLoop(puVar9[0x37]);
            puVar9[0x37] = 0;
          }
          if ((*puVar9 & 0x400) == 0)
          {
            local_60.vx = (instance->position).x;
            local_60.vy = (instance->position).y;
            local_60.vz = (instance->position).z;
            _Stack80.newPoint = &local_60;
            _Stack80.oldPoint = &local_58;
            gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x8000;
            local_58.vz = (instance->position).z + 0x200;
            local_58.vx = local_60.vx;
            local_58.vy = local_60.vy;
            PHYSICS_CheckLineInWorld(instance, &_Stack80);
            gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffff7fff;
            if (instance->waterFace == (_TFace *)0x0)
            {
              bVar1 = true;
              *(undefined *)(puVar9 + 0x51) = 7;
            }
          }
          instance->waterFace = (_TFace *)0x0;
        }
      }
    }
  }
  if (((*puVar9 & 0x400000) != 0) && (uVar4 = MON_GetTime(instance), puVar9[0x42] < uVar4))
  {
    *puVar9 = *puVar9 & 0xffbfffff;
    FX_StopAllGlowEffects(instance, 0x40);
  }
  if ((*puVar9 & 0x400) != 0)
  {
    Data = MON_OnGround(instance);
    if (Data == 0)
    {
      introUniqueID = *puVar9 & 0xfffffffd;
    }
    else
    {
      introUniqueID = *puVar9 | 2;
    }
    *puVar9 = introUniqueID;
  }
  if ((*puVar9 & 2) == 0)
  {
    MON_ApplyPhysics(instance);
  }
  while (p_Var5 = DeMessageQueue((__MessageQueue *)(puVar9 + 2)), p_Var5 != (__Event *)0x0)
  {
    puVar6 = (undefined *)p_Var5->ID;
    if (puVar6 == (undefined *)0x100000d)
    {
      pvVar7 = instance->data;
      if ((p_Var5->Data != 0) && ('\x02' < *(char *)((int)pvVar7 + 0x28)))
      {
        *(undefined *)((int)puVar9 + 0x14a) = 2;
        *puVar9 = *puVar9 | 0x10000000;
        puVar9[0x55] = *(uint *)(*(int *)((int)pvVar7 + 0x30) + 8);
      }
      *(undefined *)(puVar9 + 0x51) = 0;
      puVar9[0x36] = 0;
      *puVar9 = *puVar9 & 0xffdfdd7f;
      puVar9[1] = puVar9[1] & 0xb8080000;
      MON_TurnOnAllSpheres(instance);
      MON_TurnOffWeaponSpheres(instance);
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_ffffff9c, CONCAT48(local_68, CONCAT44(local_6c, local_70))), 0x17);
      if (instance->perVertexColor != (CVECTOR *)0x0)
      {
        MEMPACK_Free((char *)instance->perVertexColor);
        instance->perVertexColor = (CVECTOR *)0x0;
      }
      if ((instance->object->oflags & 0x200U) != 0)
      {
        instance->flags2 = instance->flags2 | 0x40;
      }
      if ((*puVar9 & 0x1000000) != 0)
      {
        instance->flags2 = instance->flags2 | 0x20000;
      }
    }
    else
    {
      if ((int)puVar6 < 0x100000e)
      {
        if (puVar6 == (undefined *)0x100000b)
        {
          instance->xAccl = 0;
          instance->yAccl = 0;
          instance->zAccl = -0x10;
        }
      }
      else
      {
        if (puVar6 == &DAT_0100001b)
        {
          puVar9[0x35] = 0;
          bVar1 = true;
        }
      }
    }
  }
  if (!bVar1)
  {
    return;
  }
  if (puVar9[0x3e] != 0)
  {
    return;
  }
  instance_01 = instance;
  if ((instance_02 != (_Instance *)0x0) &&
      (instance_01 = instance_02, (instance_02->flags2 & 0x8000000U) != 0))
  {
    MON_KillMonster(instance_02);
    uVar4 = INSTANCE_Query(instance_02, 1);
    instance_01 = instance;
    if ((uVar4 & 0x1000) != 0)
    {
      Data = 1;
      instance_01 = instance;
      goto LAB_80087ed4;
    }
  }
  Data = 0;
LAB_80087ed4:
  INSTANCE_Post(instance_01, 0x100000d, Data);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_MissileHitEntry(struct _Instance *instance /*$s0*/)
// line 527, offset 0x80087f04
/* begin block 1 */
// Start line: 528
// Start offset: 0x80087F04
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x80087F04
// End Line: 528

/* begin block 2 */
// Start line: 1142
/* end block 2 */
// End Line: 1143

void MON_MissileHitEntry(_Instance *instance)

{
  int Data;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  uint *puVar1;
  undefined4 local_18;
  undefined4 in_stack_ffffffec;

  puVar1 = (uint *)instance->extraData;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->xVel = 0;
  instance->yVel = 0;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_s1, CONCAT48(unaff_s0, CONCAT44(in_stack_ffffffec, local_18))),
               0x19);
  *puVar1 = *puVar1 & 0xffffffef | 0x200000;
  MON_TurnOffAllSpheres(instance);
  *(undefined *)(puVar1 + 0x51) = 0;
  MON_DropAllObjects(instance);
  puVar1[0x35] = *(uint *)(puVar1[0x34] + 0x3c);
  Data = SetObjectData(0, 0, 0, instance, 3);
  INSTANCE_Post((_Instance *)puVar1[0x34], 0x800002, Data);
  SOUND_Play3dSound(&instance->position, 0x27, -100, 100, (int)&DAT_00003e80);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_MissileHit(struct _Instance *instance /*$s1*/)
// line 551, offset 0x80087fd0
/* begin block 1 */
// Start line: 552
// Start offset: 0x80087FD0
// Variables:
// 		struct _MonsterVars *mv; // $s3
// 		struct _MonsterAttributes *ma; // $s0
// 		int thisFrame; // $s2
// 		int lastFrame; // $a0
/* end block 1 */
// End offset: 0x80088094
// End Line: 574

/* begin block 2 */
// Start line: 1208
/* end block 2 */
// End Line: 1209

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
  iVar1 = G2EmulationInstanceQueryFrame(instance, 0);
  iVar2 = G2EmulationInstanceQueryLastFrame(instance, 0);
  if ((iVar2 < (int)(uint) * (byte *)((int)pvVar4 + 0x26)) &&
      ((int)(uint) * (byte *)((int)pvVar4 + 0x26) <= iVar1))
  {
    FX_Blood_Impale(instance, (ushort) * (byte *)((int)pvVar4 + 0x25), instance,
                    (ushort) * (byte *)((int)pvVar4 + 0x25));
  }
  else
  {
    if ((iVar2 < (int)(uint) * (byte *)((int)pvVar4 + 0x27)) &&
        ((int)(uint) * (byte *)((int)pvVar4 + 0x27) <= iVar1))
    {
      FX_BloodCone(instance, (ushort) * (byte *)((int)pvVar4 + 0x25), 0x50);
    }
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  }
  do
  {
    p_Var3 = DeMessageQueue((__MessageQueue *)((int)pvVar5 + 8));
  } while (p_Var3 != (__Event *)0x0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_BirthEntry(struct _Instance *instance /*$a0*/)
// line 579, offset 0x800880b0
/* begin block 1 */
// Start line: 1266
/* end block 1 */
// End Line: 1267

/* begin block 2 */
// Start line: 1267
/* end block 2 */
// End Line: 1268

void MON_BirthEntry(_Instance *instance)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Birth(struct _Instance *instance /*$a0*/)
// line 583, offset 0x800880b8
/* begin block 1 */
// Start line: 1274
/* end block 1 */
// End Line: 1275

void MON_Birth(_Instance *instance)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_fffffffc, unaff_retaddr));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ParryEntry(struct _Instance *instance /*$s1*/)
// line 591, offset 0x800880d8
/* begin block 1 */
// Start line: 592
// Start offset: 0x800880D8
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x800880D8
// End Line: 592

/* begin block 2 */
// Start line: 1290
/* end block 2 */
// End Line: 1291

void MON_ParryEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  pvVar1 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 9);
  MON_TurnToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c),
                     0x1000);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Parry(struct _Instance *instance /*$s0*/)
// line 615, offset 0x80088128
/* begin block 1 */
// Start line: 1354
/* end block 1 */
// End Line: 1355

void MON_Parry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;

  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_retaddr, unaff_s0));
  }
  MON_DefaultQueueHandler(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_LandOnFeetEntry(struct _Instance *instance /*$s0*/)
// line 628, offset 0x8008816c
/* begin block 1 */
// Start line: 629
// Start offset: 0x8008816C
// Variables:
// 		struct _MonsterVars *mv; // $v0

/* begin block 1.1 */
// Start line: 646
// Start offset: 0x800881E0
// Variables:
// 		int damage; // $a1
/* end block 1.1 */
// End offset: 0x80088204
// End Line: 656
/* end block 1 */
// End offset: 0x80088204
// End Line: 657

/* begin block 2 */
// Start line: 1380
/* end block 2 */
// End Line: 1381

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void MON_LandOnFeetEntry(_Instance *instance)

{
  int iVar1;
  int damage;
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  undefined8 uStackX0;

  if (*(char *)((int)instance->extraData + 0x145) == '\v')
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT88(uStackX0, CONCAT44(unaff_retaddr, unaff_s0)), 0x15);
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = -0x10;
  }
  else
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT88(uStackX0, CONCAT44(unaff_retaddr, unaff_s0)), 0x12);
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = 0;
  }
  iVar1 = instance->zVel;
  if (iVar1 < -0x65)
  {
    damage = 0x1000;
    if ((iVar1 < -0xf6) && (damage = 0x3000, -0x15e < iVar1))
    {
      damage = 0x2000;
    }
    MON_TakeDamage(instance, damage, 0x40000);
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
// line 661, offset 0x80088230
/* begin block 1 */
// Start line: 662
// Start offset: 0x80088230
// Variables:
// 		struct _MonsterVars *mv; // $s0

/* begin block 1.1 */
// Start line: 680
// Start offset: 0x80088298
// Variables:
// 		int state; // $a1
/* end block 1.1 */
// End offset: 0x80088348
// End Line: 711
/* end block 1 */
// End offset: 0x800883A8
// End Line: 725

/* begin block 2 */
// Start line: 1447
/* end block 2 */
// End Line: 1448

void MON_LandOnFeet(_Instance *instance)

{
  undefined4 local_10;
  uint *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;

  puVar1 = (uint *)instance->extraData;
  MON_DefaultQueueHandler(instance);
  if ((instance->currentMainState == 0x10) &&
      ((*(short *)(puVar1 + 0x50) == 0x20 || (*(short *)(puVar1 + 0x50) == 0x40))))
  {
    MON_BurnInAir(instance, 0xf);
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_AnimPlaying(instance, (MonsterAnim)
                                  CONCAT412(in_stack_fffffffc,
                                            CONCAT48(local_8, CONCAT44(local_c, local_10))));
    if ((instance->flags2 & 0x8000000U) == 0)
    {
      if (((*puVar1 & 0x2000) == 0) || (*(short *)(puVar1 + 0x4c) != 0))
      {
        if (((*puVar1 & 0x400000) == 0) &&
            ((*(short *)(puVar1 + 0x4c) == 0 && (*(short *)(puVar1 + 0x50) != 0))))
        {
          *puVar1 = *puVar1 & 0xfffffeff;
        }
      }
      else
      {
        *(undefined2 *)(puVar1 + 0x50) = 0x4000;
      }
    }
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  if ((*puVar1 & 0x400) == 0)
  {
    if ((*puVar1 & 2) == 0)
    {
      MON_ApplyPhysics(instance);
    }
  }
  else
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  if (instance->currentMainState != 0xf)
  {
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = 0;
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_LandInWaterEntry(struct _Instance *instance /*$a0*/)
// line 730, offset 0x800883bc
/* begin block 1 */
// Start line: 1585
/* end block 1 */
// End Line: 1586

/* begin block 2 */
// Start line: 1586
/* end block 2 */
// End Line: 1587

void MON_LandInWaterEntry(_Instance *instance)

{
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_LandInWater(struct _Instance *instance /*$a0*/)
// line 735, offset 0x800883d0
/* begin block 1 */
// Start line: 1595
/* end block 1 */
// End Line: 1596

void MON_LandInWater(_Instance *instance)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_fffffffc, unaff_retaddr));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_BreakHoldEntry(struct _Instance *instance /*$s1*/)
// line 743, offset 0x800883f0
/* begin block 1 */
// Start line: 744
// Start offset: 0x800883F0
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x80088448
// End Line: 753

/* begin block 2 */
// Start line: 1611
/* end block 2 */
// End Line: 1612

void MON_BreakHoldEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  pvVar1 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0xf);
  *(undefined4 *)((int)pvVar1 + 0xf4) = 0x100000;
  if ((instance->object->oflags & 0x200U) != 0)
  {
    instance->flags2 = instance->flags2 | 0x40;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_BreakHold(struct _Instance *instance /*$s1*/)
// line 755, offset 0x8008845c
/* begin block 1 */
// Start line: 756
// Start offset: 0x8008845C

/* begin block 1.1 */
// Start line: 763
// Start offset: 0x8008849C
// Variables:
// 		struct _MonsterVars *mv; // $s3
// 		struct __Event *message; // $a1

/* begin block 1.1.1 */
// Start line: 773
// Start offset: 0x80088524
// Variables:
// 		struct evMonsterThrownData *data; // $s0
/* end block 1.1.1 */
// End offset: 0x80088524
// End Line: 773

/* begin block 1.1.2 */
// Start line: 780
// Start offset: 0x8008854C
// Variables:
// 		struct evMonsterHitTerrainData *data; // $v0
/* end block 1.1.2 */
// End offset: 0x80088568
// End Line: 782
/* end block 1.1 */
// End offset: 0x800885F4
// End Line: 808
/* end block 1 */
// End offset: 0x8008861C
// End Line: 814

/* begin block 2 */
// Start line: 1638
/* end block 2 */
// End Line: 1639

void MON_BreakHold(_Instance *instance)

{
  __Event *message;
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  void *pvVar2;

  if ((instance->flags2 & 0x10U) == 0)
  {
    pvVar2 = instance->extraData;
    (instance->rotation).z = *(short *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x78) + 0x800;
    while (message = DeMessageQueue((__MessageQueue *)((int)pvVar2 + 8)), message != (__Event *)0x0)
    {
      iVar1 = message->ID;
      if (iVar1 == 0x1000003)
      {
        iVar1 = message->Data;
        INSTANCE_UnlinkFromParent(instance);
        MON_LaunchMonster(instance, (int)*(short *)(iVar1 + 8), (int)*(short *)(iVar1 + 0xc), 0x32);
      }
      else
      {
        if (iVar1 < 0x1000004)
        {
          if (iVar1 != 0x1000002)
          {
          LAB_80088578:
            MON_DefaultMessageHandler(instance, message);
          }
        }
        else
        {
          if (iVar1 == 0x1000007)
          {
            if ((*(ushort *)(message->Data + 0xe) & 0x2000) != 0)
            {
              MON_UnlinkFromRaziel(instance);
            }
          }
          else
          {
            if (iVar1 != 0x100000b)
              goto LAB_80088578;
          }
        }
      }
    }
    if (instance->LinkParent == (_Instance *)0x0)
    {
      if ((instance->currentMainState == 0xe) && (*(short *)((int)pvVar2 + 0x110) != 0))
      {
        MON_TurnOnBodySpheres(instance);
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
        (instance->rotation).z = ((gameTrackerX.playerInstance)->rotation).z + 0x800;
      }
      (instance->rotation).x = 0;
      (instance->rotation).y = 0;
    }
    else
    {
      *(undefined2 *)((int)pvVar2 + 0x110) = 1;
    }
  }
  else
  {
    MON_UnlinkFromRaziel(instance);
  }
  if ((instance->LinkParent != (_Instance *)0x0) && (instance->currentMainState != 0xe))
  {
    MON_UnlinkFromRaziel(instance);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ImpactEntry(struct _Instance *instance /*$s0*/)
// line 819, offset 0x80088638
/* begin block 1 */
// Start line: 820
// Start offset: 0x80088638
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct _MonsterCombatAttributes *combat; // $s2
// 		struct evFXHitData data; // stack offset -40
/* end block 1 */
// End offset: 0x800886F4
// End Line: 842

/* begin block 2 */
// Start line: 1768
/* end block 2 */
// End Line: 1769

void MON_ImpactEntry(_Instance *instance)

{
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar1;
  ulong uVar2;
  uint *puVar3;
  int iVar4;
  MonsterAnim animtype;

  puVar3 = (uint *)instance->extraData;
  iVar4 = *(int *)(puVar3[0x55] + 8);
  MON_PlayAnim(instance, animtype, 0x11);
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  puVar3[0x3d] = 0x100000;
  MON_TakeDamage(instance, 0x3000, 0x100);
  MON_SetFXHitData(instance, (evFXHitData *)&stack0xffffffd8, 0x40000, 0);
  pTVar1 = MONTABLE_GetDamageEffectFunc(instance);
  (*pTVar1)(instance, &stack0xffffffd8);
  if (*(short *)(puVar3 + 0x4c) == 0)
  {
    uVar2 = MON_GetTime(instance);
    puVar3[0x3e] = uVar2 + (int)*(short *)(iVar4 + 2);
    *puVar3 = *puVar3 | 0x800010;
  }
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Impact(struct _Instance *instance /*$s0*/)
// line 845, offset 0x8008871c
/* begin block 1 */
// Start line: 846
// Start offset: 0x8008871C
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x80088788
// End Line: 866

/* begin block 2 */
// Start line: 1830
/* end block 2 */
// End Line: 1831

void MON_Impact(_Instance *instance)

{
  short sVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;

  pvVar2 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  }
  MON_DefaultQueueHandler(instance);
  if ((instance->currentMainState == 0x10) &&
      ((sVar1 = *(short *)((int)pvVar2 + 0x140), sVar1 == 0x20 || (sVar1 == 0x40))))
  {
    MON_BurnInAir(instance, 0xc);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_FallEntry(struct _Instance *instance /*$s0*/)
// line 871, offset 0x8008879c
/* begin block 1 */
// Start line: 872
// Start offset: 0x8008879C
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x80088820
// End Line: 893

/* begin block 2 */
// Start line: 1884
/* end block 2 */
// End Line: 1885

void MON_FallEntry(_Instance *instance)

{
  char cVar1;
  ulong uVar2;
  int mode;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar3;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;

  pvVar3 = instance->extraData;
  cVar1 = *(char *)((int)pvVar3 + 0x145);
  if (cVar1 == '\x0e')
  {
    mode = 0x14;
  }
  else
  {
    if ((((cVar1 == '\x01') || (cVar1 == '\x13')) || (cVar1 == '\r')) || (cVar1 == '\x05'))
    {
      PhysicsSetVelFromRot(instance, &instance->rotation, 0x28);
      instance->zVel = 0x28;
    }
    mode = 0x13;
  }
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
               mode);
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = -0x10;
  *(undefined4 *)((int)pvVar3 + 0xf4) = 0x100000;
  uVar2 = MON_GetTime(instance);
  *(int *)((int)pvVar3 + 0x100) = uVar2 + 2000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Fall(struct _Instance *instance /*$s1*/)
// line 901, offset 0x8008885c
/* begin block 1 */
// Start line: 902
// Start offset: 0x8008885C
// Variables:
// 		struct _MonsterVars *mv; // $s3
// 		struct __Event *message; // $a1
// 		int state; // $s2

/* begin block 1.1 */
// Start line: 929
// Start offset: 0x80088910
// Variables:
// 		int x; // $s0
// 		int y; // $v0
/* end block 1.1 */
// End offset: 0x80088944
// End Line: 934
/* end block 1 */
// End offset: 0x800889BC
// End Line: 963

/* begin block 2 */
// Start line: 1944
/* end block 2 */
// End Line: 1945

void MON_Fall(_Instance *instance)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  __Event *message;
  undefined4 local_18;
  undefined4 local_14;
  int iVar4;
  uint *puVar5;

  puVar5 = (uint *)instance->extraData;
  iVar4 = 4;
  if ((*puVar5 & 2) == 0)
  {
    if ((*puVar5 & 0x400) == 0)
    {
      MON_ApplyPhysics(instance);
    }
    else
    {
      iVar4 = 0x12;
    }
  }
  else
  {
    iVar4 = 0xf;
  }
  if (iVar4 != 4)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  }
  uVar1 = MON_GetTime(instance);
  if (((puVar5[0x40] < uVar1) && (*(int *)&instance->position == *(int *)&instance->oldPos)) &&
      ((instance->position).z == (instance->oldPos).z))
  {
    iVar2 = rand();
    iVar3 = rand();
    (instance->position).x = (instance->position).x + (((ushort)iVar2 & 0x7f) - 0x3f);
    (instance->position).y = (instance->position).y + (((ushort)iVar3 & 0x7f) - 0x3f);
  }
  while (message = DeMessageQueue((__MessageQueue *)(puVar5 + 2)), message != (__Event *)0x0)
  {
    if (message->ID != 0x1000007)
    {
      MON_DefaultMessageHandler(instance, message);
    }
  }
  if (((instance->currentMainState == 0x10) && (iVar4 == 4)) &&
      ((*(short *)(puVar5 + 0x50) == 0x20 || (*(short *)(puVar5 + 0x50) == 0x40))))
  {
    MON_BurnInAir(instance, 4);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ThrownEntry(struct _Instance *instance /*$s0*/)
// line 968, offset 0x800889d8
/* begin block 1 */
// Start line: 969
// Start offset: 0x800889D8
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x80088A40
// End Line: 985

/* begin block 2 */
// Start line: 2081
/* end block 2 */
// End Line: 2082

void MON_ThrownEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  uint *puVar1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  puVar1 = (uint *)instance->extraData;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = -8;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x10);
  puVar1[0x3d] = 0x100000;
  if ((instance->object->oflags & 0x200U) != 0)
  {
    instance->flags2 = instance->flags2 | 0x40;
  }
  instance->checkMask = instance->checkMask | 0x20;
  *puVar1 = *puVar1 & 0xfffffffd;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Thrown(struct _Instance *instance /*$s0*/)
// line 989, offset 0x80088a74
/* begin block 1 */
// Start line: 990
// Start offset: 0x80088A74
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct Intro *impaler; // $v0

/* begin block 1.1 */
// Start line: 996
// Start offset: 0x80088AA4
/* end block 1.1 */
// End offset: 0x80088AE4
// End Line: 1006

/* begin block 1.2 */
// Start line: 1012
// Start offset: 0x80088B00
// Variables:
// 		struct __Event *message; // $a1

/* begin block 1.2.1 */
// Start line: 1024
// Start offset: 0x80088B40
// Variables:
// 		struct evMonsterHitTerrainData *data; // $v0
/* end block 1.2.1 */
// End offset: 0x80088B40
// End Line: 1024
/* end block 1.2 */
// End offset: 0x80088BB8
// End Line: 1049
/* end block 1 */
// End offset: 0x80088BB8
// End Line: 1050

/* begin block 2 */
// Start line: 2126
/* end block 2 */
// End Line: 2127

void MON_Thrown(_Instance *instance)

{
  Level *pLVar1;
  Intro *pIVar2;
  __Event *message;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar4;

  puVar4 = (uint *)instance->extraData;
  if ((*puVar4 & 2) == 0)
  {
    MON_ApplyPhysics(instance);
    while (message = DeMessageQueue((__MessageQueue *)(puVar4 + 2)), message != (__Event *)0x0)
    {
      if (message->ID == 0x1000007)
      {
        iVar3 = ratan2((int)*(short *)(message->Data + 6), (int)*(short *)(message->Data + 4));
        (instance->rotation).z = (short)iVar3 + 0x400;
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
      }
      else
      {
        if (message->ID != 0x1000008)
        {
          MON_DefaultMessageHandler(instance, message);
        }
      }
    }
    if ((instance->currentMainState == 0x10) &&
        ((*(short *)(puVar4 + 0x50) == 0x20 || (*(short *)(puVar4 + 0x50) == 0x40))))
    {
      MON_BurnInAir(instance, 0xb);
    }
  }
  else
  {
    pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    pIVar2 = MON_TestForTerrainImpale(instance, pLVar1->terrain);
    if (pIVar2 == (Intro *)0x0)
    {
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = 0;
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
    else
    {
      INSTANCE_Post(instance, 0x100001c, pIVar2->UniqueID);
      MON_DefaultQueueHandler(instance);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ImpaleDeathEntry(struct _Instance *instance /*$s0*/)
// line 1055, offset 0x80088bcc
/* begin block 1 */
// Start line: 1056
// Start offset: 0x80088BCC
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x80088BCC
// End Line: 1056

/* begin block 2 */
// Start line: 2262
/* end block 2 */
// End Line: 2263

void MON_ImpaleDeathEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  uint *puVar2;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  puVar2 = (uint *)instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0xd);
  *puVar2 = *puVar2 & 0xffffffef | 0x200000;
  MON_TurnOffAllSpheres(instance);
  uVar1 = MON_GetTime(instance);
  *(undefined **)(puVar2 + 0x40) = &DAT_00007530 + uVar1;
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
// line 1073, offset 0x80088c4c
/* begin block 1 */
// Start line: 1074
// Start offset: 0x80088C4C
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterAttributes *ma; // $s2
// 		struct __Event *message; // $v0

/* begin block 1.1 */
// Start line: 1081
// Start offset: 0x80088C80
// Variables:
// 		int thisFrame; // $s3
// 		int lastFrame; // $a0
/* end block 1.1 */
// End offset: 0x80088CF4
// End Line: 1092
/* end block 1 */
// End offset: 0x80088E38
// End Line: 1127

/* begin block 2 */
// Start line: 2310
/* end block 2 */
// End Line: 2311

void MON_ImpaleDeath(_Instance *instance)

{
  int Data;
  int iVar1;
  ulong uVar2;
  __Event *p_Var3;
  undefined4 local_18;
  uint *puVar4;
  undefined4 local_14;
  void *pvVar5;
  undefined4 local_20;
  undefined4 uVar6;
  undefined4 in_stack_ffffffe4;

  puVar4 = (uint *)instance->extraData;
  pvVar5 = instance->data;
  Data = MON_AnimPlaying(instance, (MonsterAnim)
                                       CONCAT412(local_14, CONCAT48(local_18, CONCAT44(in_stack_ffffffe4,
                                                                                       local_20))));
  if (Data != 0)
  {
    Data = G2EmulationInstanceQueryFrame(instance, 0);
    iVar1 = G2EmulationInstanceQueryLastFrame(instance, 0);
    if ((iVar1 < (int)(uint) * (byte *)((int)pvVar5 + 0x26)) &&
        ((int)(uint) * (byte *)((int)pvVar5 + 0x26) <= Data))
    {
      FX_Blood_Impale(instance, (ushort) * (byte *)((int)pvVar5 + 0x25), instance,
                      (ushort) * (byte *)((int)pvVar5 + 0x25));
    }
    else
    {
      if ((iVar1 < (int)(uint) * (byte *)((int)pvVar5 + 0x27)) &&
          ((int)(uint) * (byte *)((int)pvVar5 + 0x27) <= Data))
      {
        FX_BloodCone(instance, (ushort) * (byte *)((int)pvVar5 + 0x25), 0x50);
      }
    }
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    Data = MON_AnimPlaying(instance, (MonsterAnim)
                                         CONCAT412(local_14, CONCAT48(local_18, CONCAT44(in_stack_ffffffe4,
                                                                                         local_20))));
    if ((Data == 0) ||
        (*(char *)(*(int *)puVar4[0x55] + 0xd) == *(char *)(*(int *)puVar4[0x55] + 0x16)))
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffe4, local_20));
    }
    else
    {
      uVar2 = MON_GetTime(instance);
      puVar4[0x40] = uVar2 + 1000;
    }
  }
  uVar2 = MON_GetTime(instance);
  if (puVar4[0x40] < uVar2)
  {
    *puVar4 = *puVar4 & 0xffdfffff;
    MON_TurnOnBodySpheres(instance);
    MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffe4, local_20));
  }
  while (p_Var3 = DeMessageQueue((__MessageQueue *)(puVar4 + 2)), p_Var3 != (__Event *)0x0)
  {
    if (p_Var3->ID == 0x100000a)
    {
      uVar2 = MON_GetTime(instance);
      *(undefined **)(puVar4 + 0x40) = &DAT_00007530 + uVar2;
      puVar4[0x35] = *(uint *)(puVar4[0x34] + 0x3c);
      uVar6 = 3;
      Data = SetObjectData(0, 0, 0, instance, 3);
      INSTANCE_Post((_Instance *)puVar4[0x34], 0x800002, Data);
      INSTANCE_Post((_Instance *)puVar4[0x34], 0x200003, 7);
      *(undefined *)(puVar4 + 0x51) = 0;
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_14, CONCAT48(local_18, CONCAT44(in_stack_ffffffe4, uVar6))), 0x16);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TerrainImpaleDeathEntry(struct _Instance *instance /*$s1*/)
// line 1132, offset 0x80088e54
/* begin block 1 */
// Start line: 1133
// Start offset: 0x80088E54
// Variables:
// 		struct _MonsterVars *mv; // $s2
// 		struct _MonsterAttributes *ma; // $s0
// 		struct Intro *impaler; // $s0
/* end block 1 */
// End offset: 0x80088F8C
// End Line: 1173

/* begin block 2 */
// Start line: 2434
/* end block 2 */
// End Line: 2435

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
  FX_BloodCone(instance, (ushort) * (byte *)((int)pvVar3 + 0x25), 0x50);
  *puVar4 = *puVar4 | 0x800;
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  if ((int)puVar4[100] < 0)
  {
    pIVar1 = MON_FindNearestImpalingIntro(instance->currentStreamUnitID, &instance->position);
    puVar4[100] = pIVar1->UniqueID;
    MON_MoveInstanceToImpalePoint(instance);
  }
  else
  {
    pIVar1 = INSTANCE_FindIntro(instance->currentStreamUnitID, puVar4[100]);
  }
  if ((pIVar1 == (Intro *)0x0) ||
      (pIVar1->flags = pIVar1->flags & 0xffff7fff, pIVar1 == (Intro *)0x0))
  {
  LAB_80088f7c:
    mode = 0x1f;
  }
  else
  {
    uVar2 = (uint)(ushort)(pIVar1->rotation).x & 0xfff;
    if (uVar2 < 0x801)
    {
      if (0x2a9 < uVar2)
      {
        mode = 0x1f;
        goto LAB_80088f84;
      }
    }
    else
    {
      mode = uVar2 - 0x1000;
      if (mode < 0)
      {
        mode = -mode;
      }
      if (0x2a9 < mode)
        goto LAB_80088f7c;
    }
    mode = 0x20;
  }
LAB_80088f84:
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10))), mode);
  *(undefined *)(puVar4 + 0x51) = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TerrainImpaleDeath(struct _Instance *instance /*$s3*/)
// line 1176, offset 0x80088fa8
/* begin block 1 */
// Start line: 1177
// Start offset: 0x80088FA8
// Variables:
// 		struct _MonsterVars *mv; // $s2
// 		struct Intro *impaler; // $v1

/* begin block 1.1 */
// Start line: 1201
// Start offset: 0x80089090
/* end block 1.1 */
// End offset: 0x800890A0
// End Line: 1205

/* begin block 1.2 */
// Start line: 1212
// Start offset: 0x800890B0
// Variables:
// 		struct _MonsterAttributes *ma; // $s1
// 		int fade_amount; // $s0
/* end block 1.2 */
// End offset: 0x80089118
// End Line: 1230
/* end block 1 */
// End offset: 0x80089174
// End Line: 1242

/* begin block 2 */
// Start line: 2525
/* end block 2 */
// End Line: 2526

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
  if ((*puVar7 & 0x200) == 0)
  {
    MON_MoveInstanceToImpalePoint(instance);
    if ((instance->flags2 & 0x10U) != 0)
    {
      if ((puVar7[0x31] != 0) &&
          (uVar1 = INSTANCE_Query(*(_Instance **)(puVar7[0x31] + 4), 1), (uVar1 & 1) != 0))
      {
        MON_ChangeHumanOpinion(instance);
      }
      *puVar7 = *puVar7 | 0x200;
      instance->flags2 = instance->flags2 & 0xffffffbf;
      if ((puVar7[0x36] == 0) && (*(short *)(puVar7 + 0x4d) != 0))
      {
        MON_BirthSoul(instance, 1);
      }
    }
  }
  else
  {
    if (puVar7[0x36] == 0)
    {
      pvVar6 = instance->data;
      uVar1 = MON_GetTime(instance);
      uVar5 = puVar7[0x3e];
      MON_CutOut_Monster(instance, uVar1 - uVar5, (uint) * (byte *)((int)pvVar6 + 0x19),
                         (uint) * (byte *)((int)pvVar6 + 0x21));
      if (0xfff < (int)(uVar1 - uVar5))
      {
        pIVar3 = INSTANCE_FindIntro(instance->currentStreamUnitID, puVar7[100]);
        if (pIVar3 != (Intro *)0x0)
        {
          pIVar3->flags = pIVar3->flags | 0x8000;
        }
        MON_KillMonster(instance);
      }
    }
    else
    {
      p_Var2 = INSTANCE_Find(puVar7[0x36]);
      if (p_Var2 == (_Instance *)0x0)
      {
        MON_BirthSoul(instance, 1);
      }
    }
    if (((*puVar7 & 0x400000) != 0) && (uVar1 = MON_GetTime(instance), puVar7[0x42] < uVar1))
    {
      *puVar7 = *puVar7 & 0xffbfffff;
      FX_StopAllGlowEffects(instance, 0x40);
    }
    do
    {
      p_Var4 = DeMessageQueue((__MessageQueue *)(puVar7 + 2));
    } while (p_Var4 != (__Event *)0x0);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SurprisedEntry(struct _Instance *instance /*$s0*/)
// line 1247, offset 0x80089190
/* begin block 1 */
// Start line: 1248
// Start offset: 0x80089190
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x80089190
// End Line: 1248

/* begin block 2 */
// Start line: 2671
/* end block 2 */
// End Line: 2672

void MON_SurprisedEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  pvVar2 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1a);
  uVar1 = MON_GetTime(instance);
  *(int *)((int)pvVar2 + 0x100) =
      uVar1 + (int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x154) + 8) + 6);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Surprised(struct _Instance *instance /*$s1*/)
// line 1258, offset 0x800891f0
/* begin block 1 */
// Start line: 1259
// Start offset: 0x800891F0
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x80089298
// End Line: 1279

/* begin block 2 */
// Start line: 2693
/* end block 2 */
// End Line: 2694

void MON_Surprised(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  void *pvVar2;
  undefined4 local_c;

  pvVar2 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_PlayCombatIdle(instance, 2);
  }
  uVar1 = MON_GetTime(instance);
  if (*(uint *)((int)pvVar2 + 0x100) < uVar1)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  if (*(int *)((int)pvVar2 + 0xc4) != 0)
  {
    *(int *)((int)pvVar2 + 0x10c) = *(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c;
    MON_TurnToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c),
                       *(short *)(*(int *)((int)pvVar2 + 0x154) + 0x1c));
  }
  MON_DefaultQueueHandler(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_StunnedEntry(struct _Instance *instance /*$s1*/)
// line 1285, offset 0x800892b4
/* begin block 1 */
// Start line: 1286
// Start offset: 0x800892B4
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterCombatAttributes *combat; // $s2
/* end block 1 */
// End offset: 0x80089434
// End Line: 1328

/* begin block 2 */
// Start line: 2749
/* end block 2 */
// End Line: 2750

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
  psVar4 = *(short **)(puVar3[0x55] + 8);
  if ((*puVar3 & 0x40) == 0)
  {
    if ((*puVar3 & 0x100) != 0)
      goto LAB_800893b8;
    sVar1 = *(short *)(puVar3 + 0x50);
    if ((sVar1 == 0x40) || (sVar1 == 0x2000))
    {
      mode = 0x2c;
    }
    else
    {
      if (sVar1 == 0x10)
      {
        mode = 0x1b;
      }
      else
      {
        if (sVar1 == 0x200)
        {
          mode = 0x2b;
        }
        else
        {
          mode = 5;
        }
      }
    }
  }
  else
  {
    *(ushort *)(puVar3[0x31] + 0x18) = *(ushort *)(puVar3[0x31] + 0x18) | 0x400;
    *puVar3 = *puVar3 | 0x810000;
    mode = MON_SetUpKnockBack(instance, *(_Instance **)(puVar3[0x31] + 4),
                              (evMonsterHitData *)puVar3[0x30]);
    if (mode == 0)
    {
      mode = 1;
    }
    else
    {
      mode = 0;
    }
  }
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10))), mode);
LAB_800893b8:
  *puVar3 = *puVar3 | 0x10110;
  uVar2 = MON_GetTime(instance);
  puVar3[0x3e] = uVar2 + (int)psVar4[1];
  if ((*(short *)(puVar3 + 0x50) == 0x40) && (*(char *)(puVar3[0x55] + 0x38) != '\0'))
  {
    uVar2 = MON_GetTime(instance);
    mode = (int)*psVar4 << 1;
  }
  else
  {
    uVar2 = MON_GetTime(instance);
    mode = (int)*psVar4;
  }
  puVar3[0x3f] = uVar2 + mode;
  puVar3[0x3d] = 0x8000;
  instance->checkMask = instance->checkMask | 0x20;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Stunned(struct _Instance *instance /*$s0*/)
// line 1332, offset 0x80089464
/* begin block 1 */
// Start line: 1333
// Start offset: 0x80089464
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x80089560
// End Line: 1363

/* begin block 2 */
// Start line: 2862
/* end block 2 */
// End Line: 2863

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
  if ((instance->flags2 & 0x10U) != 0)
  {
    if ((*puVar3 & 0x100) == 0)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
    else
    {
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))), 5);
    }
  }
  uVar1 = MON_GetTime(instance);
  if (puVar3[0x40] < uVar1)
  {
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
  }
  if (((*puVar3 & 0x100) == 0) &&
      (iVar2 = MON_AnimPlaying(instance, (MonsterAnim)
                                             CONCAT412(in_stack_fffffffc,
                                                       CONCAT48(local_8, CONCAT44(local_c, local_10)))),
       iVar2 == 0))
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
                 0xc);
  }
  MON_DefaultQueueHandler(instance);
  PHYSICS_StopIfCloseToTarget(instance, 0, 0, 0);
  PhysicsMove(instance, &instance->position, gameTrackerX.timeMult);
  if (instance->currentMainState != 9)
  {
    instance->checkMask = instance->checkMask & 0xffffffdf;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_GrabbedEntry(struct _Instance *instance /*$s0*/)
// line 1368, offset 0x80089574
/* begin block 1 */
// Start line: 1369
// Start offset: 0x80089574
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x800895CC
// End Line: 1385

/* begin block 2 */
// Start line: 2935
/* end block 2 */
// End Line: 2936

void MON_GrabbedEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  pvVar2 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 4);
  instance->flags2 = instance->flags2 & 0xffffffbf;
  uVar1 = MON_GetTime(instance);
  *(int *)((int)pvVar2 + 0x100) =
      uVar1 + (int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x154) + 8) + 8);
  INSTANCE_LinkToParent(instance, gameTrackerX.playerInstance, 0x31);
  (instance->rotation).z = *(short *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x78) + 0x800;
  *(undefined2 *)((int)pvVar2 + 0x110) = 0;
  instance->checkMask = instance->checkMask | 0x20;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Grabbed(struct _Instance *instance /*$s1*/)
// line 1398, offset 0x80089658
/* begin block 1 */
// Start line: 1399
// Start offset: 0x80089658
// Variables:
// 		struct _MonsterVars *mv; // $s2
// 		struct __Event *message; // $a1
// 		int time; // $v1

/* begin block 1.1 */
// Start line: 1424
// Start offset: 0x80089754
// Variables:
// 		struct evMonsterThrownData *data; // $s0
/* end block 1.1 */
// End offset: 0x80089754
// End Line: 1424

/* begin block 1.2 */
// Start line: 1431
// Start offset: 0x8008977C
// Variables:
// 		struct evMonsterHitTerrainData *data; // $v0
/* end block 1.2 */
// End offset: 0x80089798
// End Line: 1433
/* end block 1 */
// End offset: 0x80089854
// End Line: 1466

/* begin block 2 */
// Start line: 3000
/* end block 2 */
// End Line: 3001

void MON_Grabbed(_Instance *instance)

{
  ulong uVar1;
  __Event *message;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 unaff_s2;
  void *pvVar3;
  undefined4 unaff_s3;

  pvVar3 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_s3, CONCAT48(unaff_s2, CONCAT44(local_14, local_18))), 0xe);
  }
  uVar1 = MON_GetTime(instance);
  if (((int)(*(int *)((int)pvVar3 + 0x100) - uVar1) < 1) &&
      (uVar1 = INSTANCE_Query(*(_Instance **)(*(int *)((int)pvVar3 + 0xc4) + 4), 10), uVar1 != 0x20000))
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  }
  (instance->rotation).z = *(short *)(*(int *)(*(int *)((int)pvVar3 + 0xc4) + 4) + 0x78) + 0x800;
LAB_800896f4:
  do
  {
    while (true)
    {
      while (true)
      {
        message = DeMessageQueue((__MessageQueue *)((int)pvVar3 + 8));
        if (message == (__Event *)0x0)
        {
          if (instance->LinkParent == (_Instance *)0x0)
          {
            if ((instance->currentMainState == 10) && (*(short *)((int)pvVar3 + 0x110) != 0))
            {
              MON_TurnOnBodySpheres(instance);
              MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
              (instance->rotation).z = ((gameTrackerX.playerInstance)->rotation).z + 0x800;
            }
            (instance->rotation).x = 0;
            (instance->rotation).y = 0;
          }
          else
          {
            *(undefined2 *)((int)pvVar3 + 0x110) = 1;
          }
          if (((instance->LinkParent != (_Instance *)0x0) && (instance->currentMainState != 10)) &&
              (instance->currentMainState != 0xe))
          {
            MON_UnlinkFromRaziel(instance);
          }
          return;
        }
        iVar2 = message->ID;
        if (iVar2 != 0x1000003)
          break;
        iVar2 = message->Data;
        INSTANCE_UnlinkFromParent(instance);
        MON_LaunchMonster(instance, (int)*(short *)(iVar2 + 8), (int)*(short *)(iVar2 + 0xc), 0x32);
      }
      if (iVar2 < 0x1000004)
        break;
      if (iVar2 != 0x1000007)
        goto code_r0x80089740;
      if ((*(ushort *)(message->Data + 0xe) & 0x2000) != 0)
      {
        MON_UnlinkFromRaziel(instance);
      }
    }
  } while (iVar2 == 0x1000002);
  goto LAB_800897a8;
code_r0x80089740:
  if (iVar2 != 0x100000b)
  {
  LAB_800897a8:
    MON_DefaultMessageHandler(instance, message);
  }
  goto LAB_800896f4;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_HitEntry(struct _Instance *instance /*$s1*/)
// line 1471, offset 0x80089870
/* begin block 1 */
// Start line: 1472
// Start offset: 0x80089870
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterIR *enemy; // $a0
/* end block 1 */
// End offset: 0x800898DC
// End Line: 1486

/* begin block 2 */
// Start line: 3154
/* end block 2 */
// End Line: 3155

void MON_HitEntry(_Instance *instance)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  undefined4 local_10;
  uint *puVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;

  puVar4 = (uint *)instance->extraData;
  uVar3 = puVar4[0x31];
  *(ushort *)(uVar3 + 0x18) = *(ushort *)(uVar3 + 0x18) | 0x400;
  *puVar4 = *puVar4 | 0x10000;
  iVar1 = MON_SetUpKnockBack(instance, *(_Instance **)(uVar3 + 4), (evMonsterHitData *)puVar4[0x30]);
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
               (uint)(iVar1 == 0));
  puVar4[0x3d] = 0x8000;
  instance->checkMask = instance->checkMask | 0x20;
  uVar2 = MON_GetTime(instance);
  *(undefined **)(puVar4 + 0x41) = &DAT_000026ac + uVar2;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Hit(struct _Instance *instance /*$s0*/)
// line 1494, offset 0x80089914
/* begin block 1 */
// Start line: 1495
// Start offset: 0x80089914
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x800899E8
// End Line: 1519

/* begin block 2 */
// Start line: 3207
/* end block 2 */
// End Line: 3208

void MON_Hit(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar2;

  pvVar2 = instance->extraData;
  uVar1 = MON_GetTime(instance);
  if (*(uint *)((int)pvVar2 + 0x100) < uVar1)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
  }
  else
  {
    if ((instance->flags2 & 0x10U) != 0)
    {
      MON_PlayCombatIdle(instance, 2);
    }
  }
  MON_DefaultQueueHandler(instance);
  PHYSICS_StopIfCloseToTarget(instance, 0, 0, 0);
  PhysicsMove(instance, &instance->position, gameTrackerX.timeMult);
  if (instance->currentMainState != 8)
  {
    instance->checkMask = instance->checkMask & 0xffffffdf;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_AttackEntry(struct _Instance *instance /*$s0*/)
// line 1524, offset 0x800899fc
/* begin block 1 */
// Start line: 1525
// Start offset: 0x800899FC
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct _MonsterAttackAttributes *attack; // $s2
/* end block 1 */
// End offset: 0x800899FC
// End Line: 1525

/* begin block 2 */
// Start line: 3267
/* end block 2 */
// End Line: 3268

void MON_AttackEntry(_Instance *instance)

{
  ulong uVar1;
  void *pvVar2;
  int iVar3;

  pvVar2 = instance->extraData;
  iVar3 = *(int *)((int)pvVar2 + 0xb8);
  *(undefined4 *)((int)pvVar2 + 0xf4) = 0x200000;
  MON_PlayAnimFromList(instance, (char *)(iVar3 + 0x1b), 0, 1);
  uVar1 = MON_GetTime(instance);
  *(int *)((int)pvVar2 + 0x100) = uVar1 + (int)*(char *)(iVar3 + 0xd) * 0x21;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Attack(struct _Instance *instance /*$s2*/)
// line 1540, offset 0x80089a70
/* begin block 1 */
// Start line: 1541
// Start offset: 0x80089A70
// Variables:
// 		struct _MonsterVars *mv; // $s3
// 		struct _MonsterIR *enemy; // $s4
// 		struct _MonsterAttackAttributes *attack; // $s0
// 		struct _MonsterAnim *anim; // $s1
/* end block 1 */
// End offset: 0x80089C28
// End Line: 1584

/* begin block 2 */
// Start line: 3299
/* end block 2 */
// End Line: 3300

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
  p_Var2 = MON_GetAnim(instance, (char *)(uVar5 + 0x1b), (int)*(char *)((int)puVar6 + 0x14b));
  if ((p_Var2->velocity != 0) && (iVar3 = MON_TransNodeAnimation(instance), iVar3 == 0))
  {
    *(ushort *)(puVar6 + 0x44) = p_Var2->velocity;
    MON_MoveForward(instance);
  }
  iVar3 = MON_AnimPlayingFromList(instance, (char *)(uVar5 + 0x1b), (int)*(char *)(uVar5 + 10));
  if ((iVar3 == 0) ||
      (iVar3 = G2EmulationInstanceQueryPassedFrame(instance, 0, (int)*(char *)(uVar5 + 9)), iVar3 == 0))
  {
    iVar3 = MON_AnimPlayingFromList(instance, (char *)(uVar5 + 0x1b), (int)*(char *)(uVar5 + 0xc));
    if ((iVar3 != 0) &&
        ((iVar3 = G2EmulationInstanceQueryPassedFrame(instance, 0, (int)*(char *)(uVar5 + 0xb)),
          iVar3 != 0 && ((*puVar6 & 0x4000) != 0))))
    {
      MON_TurnOffWeaponSpheres(instance);
      *(ushort *)(uVar7 + 0x18) = *(ushort *)(uVar7 + 0x18) | 0x200;
    }
  }
  else
  {
    MON_TurnOnWeaponSphere(instance, (int)*(char *)(uVar5 + 8));
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    instance->flags2 = instance->flags2 & 0xffffffef;
    cVar1 = *(char *)((int)puVar6 + 0x14b) + '\x01';
    *(char *)((int)puVar6 + 0x14b) = cVar1;
    if ((int)cVar1 < (int)*(char *)(uVar5 + 0xe))
    {
      MON_PlayAnimFromList(instance, (char *)(uVar5 + 0x1b), (int)cVar1, 1);
    }
    else
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
  }
  if ((uVar7 != 0) &&
      ((uVar4 = MON_GetTime(instance), uVar4 < puVar6[0x40] ||
                                           (uVar4 = INSTANCE_Query(*(_Instance **)(uVar7 + 4), 10), (uVar4 & 0x2000000) == 0))))
  {
    MON_TurnToPosition(instance, (_Position *)(*(int *)(uVar7 + 4) + 0x5c),
                       *(short *)(puVar6[0x55] + 0x1c));
  }
  MON_DefaultQueueHandler(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_CombatEntry(struct _Instance *instance /*$a0*/)
// line 1590, offset 0x80089c50
/* begin block 1 */
// Start line: 1592
// Start offset: 0x80089C50
// Variables:
// 		struct _MonsterVars *mv; // $a0
/* end block 1 */
// End offset: 0x80089C50
// End Line: 1597

/* begin block 2 */
// Start line: 3401
/* end block 2 */
// End Line: 3402

/* begin block 3 */
// Start line: 3402
/* end block 3 */
// End Line: 3403

/* begin block 4 */
// Start line: 3407
/* end block 4 */
// End Line: 3408

void MON_CombatEntry(_Instance *instance)

{
  uint *puVar1;

  puVar1 = (uint *)instance->extraData;
  puVar1[0x3d] = 0x2000000;
  *puVar1 = *puVar1 & 0xfffbffff | 0x10000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Combat(struct _Instance *instance /*$s1*/)
// line 1603, offset 0x80089c7c
/* begin block 1 */
// Start line: 1604
// Start offset: 0x80089C7C
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterIR *enemy; // $s3

/* begin block 1.1 */
// Start line: 1622
// Start offset: 0x80089D2C
// Variables:
// 		struct _MonsterCombatAttributes *combat; // $s2

/* begin block 1.1.1 */
// Start line: 1632
// Start offset: 0x80089D7C
// Variables:
// 		int reason; // $a1

/* begin block 1.1.1.1 */
// Start line: 1647
// Start offset: 0x80089DCC
// Variables:
// 		int anim; // $v0
/* end block 1.1.1.1 */
// End offset: 0x80089DDC
// End Line: 1651

/* begin block 1.1.1.2 */
// Start line: 1662
// Start offset: 0x80089E38
/* end block 1.1.1.2 */
// End offset: 0x80089E54
// End Line: 1665

/* begin block 1.1.1.3 */
// Start line: 1676
// Start offset: 0x80089EA4
// Variables:
// 		int anim; // $v0
/* end block 1.1.1.3 */
// End offset: 0x80089EDC
// End Line: 1687
/* end block 1.1.1 */
// End offset: 0x80089EDC
// End Line: 1691

/* begin block 1.1.2 */
// Start line: 1695
// Start offset: 0x80089EFC
// Variables:
// 		int state; // $a1
/* end block 1.1.2 */
// End offset: 0x80089F40
// End Line: 1706
/* end block 1.1 */
// End offset: 0x80089F40
// End Line: 1707
/* end block 1 */
// End offset: 0x80089F40
// End Line: 1709

/* begin block 2 */
// Start line: 3434
/* end block 2 */
// End Line: 3435

void MON_Combat(_Instance *instance)

{
  int reason;
  ulong uVar1;
  _MonsterAttackAttributes *attack;
  undefined4 local_18;
  uint *puVar2;
  undefined4 local_14;
  undefined4 local_10;
  int iVar3;
  undefined4 local_c;
  _MonsterIR *enemy;

  puVar2 = (uint *)instance->extraData;
  enemy = (_MonsterIR *)puVar2[0x31];
  if ((((enemy != (_MonsterIR *)0x0) && ((*puVar2 & 4) == 0)) &&
       (((*puVar2 & 0x10000000) == 0 || ((enemy->mirFlags & 0x1000) == 0)))) &&
      ((reason = MON_ValidPosition(instance), reason != 0 ||
                                                  (uVar1 = MON_GetTime(instance), uVar1 < puVar2[0x41]))))
  {
    iVar3 = *(int *)(puVar2[0x55] + 8);
    *(_Position **)(puVar2 + 0x43) = &enemy->instance->position;
    reason = MON_ShouldIFlee(instance);
    if ((reason == 0) &&
        ((enemy->distance < *(short *)(iVar3 + 10) || (*(char *)((int)puVar2 + 0x146) == '\n'))))
    {
      if (((*puVar2 & 0x20000) != 0) && ((instance->flags2 & 0x12U) != 0))
      {
        *puVar2 = *puVar2 & 0xbffdffff;
      }
      reason = MON_ShouldIEvade(instance);
      if (reason == 0)
      {
        if ((*puVar2 & 0x40000000) == 0)
        {
          if (*(char *)((int)puVar2 + 0x146) == '\n')
          {
            reason = MON_ShouldIFireAtTarget(instance, enemy);
          }
          else
          {
            attack = MON_ChooseAttack(instance, enemy);
            reason = MON_ShouldIAttack(instance, enemy, attack);
          }
          if (reason == 1)
          {
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
          }
          else
          {
            if (reason == 2)
            {
              MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
            }
            else
            {
              if ((*puVar2 & 0x20000) == 0)
              {
                reason = MON_ChooseCombatMove(instance, reason);
                if (reason == 0)
                {
                  MON_PlayCombatIdle(instance, 2);
                }
                else
                {
                  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14, local_18))), reason);
                  *puVar2 = *puVar2 | 0x20000;
                }
              }
            }
          }
        }
      }
      else
      {
        reason = MON_ChooseEvadeMove(instance);
        if (reason != 0)
        {
          MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14, local_18))),
                       reason);
          *puVar2 = *puVar2 | 0x40020000;
        }
      }
      MON_TurnToPosition(instance, &enemy->instance->position, *(short *)(puVar2[0x55] + 0x1c));
      goto LAB_80089f40;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
LAB_80089f40:
  MON_IdleQueueHandler(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ProjectileEntry(struct _Instance *instance /*$a0*/)
// line 1715, offset 0x80089f64
/* begin block 1 */
// Start line: 1716
// Start offset: 0x80089F64
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterAttributes *ma; // $v1
// 		struct _MonsterMissile *missileDef; // $a1
/* end block 1 */
// End offset: 0x80089F64
// End Line: 1716

/* begin block 2 */
// Start line: 3661
/* end block 2 */
// End Line: 3662

void MON_ProjectileEntry(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_PlayAnimFromList(instance, (char *)(*(int *)((int)instance->data + 0x3c) + (int)*(char *)(*(int *)(*(int *)((int)pvVar1 + 0x154) + 8) + 0x1e) * 0x10 + 0xe), 0, 1);
  *(undefined *)((int)pvVar1 + 0x14b) = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Projectile(struct _Instance *instance /*$s2*/)
// line 1727, offset 0x80089fbc
/* begin block 1 */
// Start line: 1728
// Start offset: 0x80089FBC
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct _MonsterAttributes *ma; // $v1
// 		struct _MonsterMissile *missileDef; // $s0
/* end block 1 */
// End offset: 0x8008A0E0
// End Line: 1757

/* begin block 2 */
// Start line: 3686
/* end block 2 */
// End Line: 3687

void MON_Projectile(_Instance *instance)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_s0;
  _MonsterMissile *missiledef;
  undefined4 unaff_s1;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  missiledef = (_MonsterMissile *)(*(int *)((int)instance->data + 0x3c) +
                                   (int)*(char *)(*(int *)(puVar3[0x55] + 8) + 0x1e) * 0x10);
  if (puVar3[0x31] != 0)
  {
    if ((instance->flags2 & 0x10U) == 0)
    {
      iVar2 = MON_AnimPlayingFromList(instance, missiledef->animList, (uint)missiledef->anim);
      if (((iVar2 != 0) &&
           (iVar2 = G2EmulationInstanceQueryPassedFrame(instance, 0, (uint)missiledef->frame),
            iVar2 != 0)) &&
          (MISSILE_FireAtInstance(instance, missiledef, *(_Instance **)(puVar3[0x31] + 4)),
           missiledef->reload != '\0'))
      {
        *puVar3 = *puVar3 & 0xffffffdf;
      }
      MON_TurnToPosition(instance, (_Position *)(*(int *)(puVar3[0x31] + 4) + 0x5c),
                         *(short *)(puVar3[0x55] + 0x1c));
      goto LAB_8008a0e0;
    }
    cVar1 = *(char *)((int)puVar3 + 0x14b) + '\x01';
    *(char *)((int)puVar3 + 0x14b) = cVar1;
    if ((int)cVar1 < (int)(uint)missiledef->numAnims)
    {
      MON_PlayAnimFromList(instance, missiledef->animList, (int)cVar1, 1);
      goto LAB_8008a0e0;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
LAB_8008a0e0:
  MON_DefaultQueueHandler(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_IdleEntry(struct _Instance *instance /*$a1*/)
// line 1766, offset 0x8008a100
/* begin block 1 */
// Start line: 1767
// Start offset: 0x8008A100
// Variables:
// 		struct _MonsterVars *mv; // $s0

/* begin block 1.1 */
// Start line: 1777
// Start offset: 0x8008A140
// Variables:
// 		struct _MonsterAttributes *ma; // $v1
/* end block 1.1 */
// End offset: 0x8008A160
// End Line: 1782
/* end block 1 */
// End offset: 0x8008A1A8
// End Line: 1792

/* begin block 2 */
// Start line: 3767
/* end block 2 */
// End Line: 3768

void MON_IdleEntry(_Instance *instance)

{
  uint uVar1;
  uint *puVar2;

  puVar2 = (uint *)instance->extraData;
  uVar1 = *puVar2;
  *puVar2 = uVar1 & 0xfffbefff;
  puVar2[0x3d] = 1;
  if ((uVar1 & 4) == 0)
  {
    if (((instance->anim).section[0].flags & 1) == 0)
    {
      G2Anim_SetLooping(&instance->anim);
      *puVar2 = *puVar2 | 0x4000000;
    }
  }
  else
  {
    if (puVar2[0x31] == 0)
    {
      MON_PlayAnimID(instance, (int)**(char **)((int)instance->data + 0x44), 2);
    }
    else
    {
      MON_PlayCombatIdle(instance, 2);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Idle(struct _Instance *instance /*$s3*/)
// line 1794, offset 0x8008a1b8
/* begin block 1 */
// Start line: 1795
// Start offset: 0x8008A1B8
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		int combatIdle; // $s4

/* begin block 1.1 */
// Start line: 1801
// Start offset: 0x8008A1F4
// Variables:
// 		int state; // $s1
// 		struct _MonsterIR *enemy; // $s2
/* end block 1.1 */
// End offset: 0x8008A304
// End Line: 1831
/* end block 1 */
// End offset: 0x8008A3CC
// End Line: 1848

/* begin block 2 */
// Start line: 3832
/* end block 2 */
// End Line: 3833

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
  if ((*puVar3 & 4) == 0)
  {
    uVar5 = puVar3[0x31];
    iVar4 = -1;
    iVar2 = MON_ValidPosition(instance);
    if (iVar2 == 0)
    {
      iVar4 = 1;
    }
    else
    {
      if (uVar5 == 0)
      {
        if (((uint) * (byte *)((int)puVar3 + 0x146) - 2 < 2) && ((instance->flags2 & 2U) != 0))
        {
          iVar4 = 5;
        }
      }
      else
      {
        bVar1 = true;
        iVar2 = MON_ShouldIFlee(instance);
        if (iVar2 == 0)
        {
          if ((*(ushort *)(uVar5 + 0x16) & 0x100) == 0)
          {
            if (((*(char *)((int)puVar3 + 0x146) == '\a') &&
                 (*(short *)(puVar3 + 0x4a) < *(short *)(uVar5 + 0x14))) ||
                (iVar2 = MON_ValidUnit(instance, *(ulong *)(*(int *)(uVar5 + 4) + 0x38)), iVar2 == 0))
            {
              MON_TurnToPosition(instance, (_Position *)(*(int *)(uVar5 + 4) + 0x5c),
                                 *(short *)(puVar3[0x55] + 0x1c));
            }
            else
            {
              iVar4 = 0xd;
            }
          }
          else
          {
            iVar4 = 0x19;
          }
        }
        else
        {
          iVar4 = 0x13;
        }
        puVar3[0x43] = *(int *)(uVar5 + 4) + 0x5c;
      }
    }
    if (iVar4 != -1)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
  }
  else
  {
    if (((puVar3[1] & 0x10000000) != 0) &&
        (AngleMoveToward(&(instance->rotation).z, *(short *)((int)puVar3 + 0x116),
                         (short)((int)*(short *)(puVar3[0x55] + 0x1c) * gameTrackerX.timeMult * 0x10 >> 0x10)),
         (instance->rotation).z == *(short *)((int)puVar3 + 0x116)))
    {
      puVar3[1] = puVar3[1] & 0xefffffff;
    }
  }
  if (((*puVar3 & 4) == 0) && (((*puVar3 & 0x4000000) == 0 || ((instance->flags2 & 2U) != 0))))
  {
    if (bVar1)
    {
      MON_PlayCombatIdle(instance, 2);
    }
    else
    {
      MON_PlayRandomIdle(instance, 2);
    }
  }
  MON_IdleQueueHandler(instance);
  return;
}

// autogenerated function stub:
// void /*$ra*/ MON_FleeEntry(struct _Instance *instance /*$a0*/)
void MON_FleeEntry(struct _Instance *instance)
{                          // line 1854, offset 0x8008a3f4
                           /* begin block 1 */
                           // Start line: 1855
                           // Start offset: 0x8008A3F4
                           // Variables:
  struct _MonsterVars *mv; // $a1
                           /* end block 1 */
                           // End offset: 0x8008A3F4
                           // End Line: 1855

  /* begin block 2 */
  // Start line: 3952
  /* end block 2 */
  // End Line: 3953
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Flee(struct _Instance *instance /*$s1*/)
// line 1869, offset 0x8008a448
/* begin block 1 */
// Start line: 1870
// Start offset: 0x8008A448
// Variables:
// 		struct _MonsterVars *mv; // $s0

/* begin block 1.1 */
// Start line: 1896
// Start offset: 0x8008A530
/* end block 1.1 */
// End offset: 0x8008A578
// End Line: 1903
/* end block 1 */
// End offset: 0x8008A578
// End Line: 1904

/* begin block 2 */
// Start line: 3993
/* end block 2 */
// End Line: 3994

void MON_Flee(_Instance *instance)

{
  short angle;
  ulong uVar1;
  int iVar2;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;

  puVar3 = (uint *)instance->extraData;
  if (puVar3[0x31] == 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    *(undefined *)((int)puVar3 + 0x146) = *(undefined *)((int)puVar3 + 0x147);
    return;
  }
  if (((((*puVar3 & 0x2000000) == 0) || (puVar3[0x33] == 0)) ||
       (*(short *)(puVar3[0x31] + 0x14) <= *(short *)(puVar3[0x33] + 0x14))) ||
      (uVar1 = INSTANCE_Query(instance, 1), (uVar1 & 4) != 0))
  {
    if (*(short *)(puVar3[0x55] + 0x1a) < *(short *)(puVar3[0x31] + 0x14))
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
      return;
    }
    iVar2 = MON_ValidPosition(instance);
    if (iVar2 != 0)
    {
      angle = MATH3D_AngleFromPosToPos((_Position *)(*(int *)(puVar3[0x31] + 4) + 0x5c), &instance->position);
      angle = MONSENSE_GetClosestFreeDirection(instance, angle, 1000);
      AngleMoveToward(&(instance->rotation).z, angle, *(short *)(puVar3[0x55] + 0x22));
      MON_DefaultQueueHandler(instance);
      return;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PursueEntry(struct _Instance *instance /*$s1*/)
// line 1909, offset 0x8008a58c
/* begin block 1 */
// Start line: 1910
// Start offset: 0x8008A58C
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8008A5EC
// End Line: 1925

/* begin block 2 */
// Start line: 4073
/* end block 2 */
// End Line: 4074

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
  if ((uVar1 & 4) == 0)
  {
    MON_GetPlanSlot(mv);
    MON_PlayCombatIdle(instance, 2);
  }
  else
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 3);
  }
  mv->mode = 4;
  mv->mvFlags = mv->mvFlags & 0xfffdffff;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Pursue(struct _Instance *instance /*$s3*/)
// line 1930, offset 0x8008a61c
/* begin block 1 */
// Start line: 1931
// Start offset: 0x8008A61C
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		int anim; // $a1
// 		int planresult; // $v1
// 		long range; // $s6
// 		struct _MonsterIR *target; // $s4
// 		int pursueType; // $s2

/* begin block 1.1 */
// Start line: 1954
// Start offset: 0x8008A674

/* begin block 1.1.1 */
// Start line: 1960
// Start offset: 0x8008A6A4
/* end block 1.1.1 */
// End offset: 0x8008A6E0
// End Line: 1966

/* begin block 1.1.2 */
// Start line: 1998
// Start offset: 0x8008A794
// Variables:
// 		struct _MonsterCombatAttributes *combat; // $a2

/* begin block 1.1.2.1 */
// Start line: 2002
// Start offset: 0x8008A7B0
// Variables:
// 		struct _MonsterIR *ally; // $a1
/* end block 1.1.2.1 */
// End offset: 0x8008A7E0
// End Line: 2023

/* begin block 1.1.2.2 */
// Start line: 2060
// Start offset: 0x8008A888
/* end block 1.1.2.2 */
// End offset: 0x8008A8E0
// End Line: 2068
/* end block 1.1.2 */
// End offset: 0x8008A8E0
// End Line: 2070

/* begin block 1.1.3 */
// Start line: 2082
// Start offset: 0x8008A90C
// Variables:
// 		int state; // $s5
/* end block 1.1.3 */
// End offset: 0x8008A9F8
// End Line: 2153
/* end block 1.1 */
// End offset: 0x8008AA2C
// End Line: 2170
/* end block 1 */
// End offset: 0x8008AA2C
// End Line: 2171

/* begin block 2 */
// Start line: 4119
/* end block 2 */
// End Line: 4120

void MON_Pursue(_Instance *instance)

{
  short sVar1;
  int anim;
  long lVar2;
  _MonsterAnim *p_Var3;
  Intro *pIVar4;
  _MonsterCombatAttributes *p_Var5;
  undefined4 local_20;
  undefined4 local_1c;
  _MonsterVars *mv;
  uint uVar6;
  _MonsterIR *target;
  int iVar7;
  long distance;

  distance = 0;
  mv = (_MonsterVars *)instance->extraData;
  target = (_MonsterIR *)0x0;
  uVar6 = 0;
  mv->lookAtPos = (_Position *)0x0;
  if ((mv->mvFlags & 4) != 0)
  {
    MON_GroundMoveQueueHandler(instance);
    return;
  }
  anim = MON_ValidPosition(instance);
  if (anim == 0)
  {
    sVar1 = (mv->lastValidPos).z;
    *(undefined4 *)&mv->destination = *(undefined4 *)&mv->lastValidPos;
    (mv->destination).z = sVar1;
  LAB_8008a728:
    uVar6 = 1;
    mv->lookAtPos = &mv->destination;
  }
  else
  {
    if (((mv->behaviorState == '\a') && (pIVar4 = instance->intro, pIVar4 != (Intro *)0x0)) &&
        (lVar2 = MATH3D_LengthXYZ((int)(instance->position).x - (int)(pIVar4->position).x,
                                  (int)(instance->position).y - (int)(pIVar4->position).y,
                                  (int)(instance->position).z - (int)(pIVar4->position).z),
         (int)mv->guardRange < lVar2))
    {
      sVar1 = (instance->intro->position).z;
      *(undefined4 *)&mv->destination = *(undefined4 *)&instance->intro->position;
      (mv->destination).z = sVar1;
      goto LAB_8008a728;
    }
  }
  if (uVar6 != 1)
  {
    if (mv->enemy == (_MonsterIR *)0x0)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
      uVar6 = 0;
    }
    else
    {
      if (((mv->mvFlags & 0x10000000) == 0) || ((mv->enemy->mirFlags & 0x1000) == 0))
      {
        p_Var5 = mv->subAttr->combatAttributes;
        uVar6 = 2;
        if (((mv->mvFlags & 0x2000000) == 0) ||
            ((target = mv->ally, target == (_MonsterIR *)0x0 || ((target->mirFlags & 0x200) != 0))))
        {
          target = mv->enemy;
          distance = (int)p_Var5->combatRange + -200;
        }
        else
        {
          distance = (long)p_Var5->allyRange;
          uVar6 = 3;
        }
        if (target == (_MonsterIR *)0x0)
        {
          MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
        }
        else
        {
          anim = MON_ShouldIFireAtTarget(instance, target);
          if (anim == 0)
          {
            sVar1 = (target->instance->position).z;
            *(undefined4 *)&mv->destination = *(undefined4 *)&target->instance->position;
            (mv->destination).z = sVar1;
            mv->lookAtPos = &mv->destination;
            anim = MON_ValidUnit(instance, target->instance->currentStreamUnitID);
            if ((anim == 0) ||
                (((mv->behaviorState == '\a' && (pIVar4 = instance->intro, pIVar4 != (Intro *)0x0)) && (lVar2 = MATH3D_LengthXYZ((int)(mv->destination).x - (int)(pIVar4->position).x,
                                                                                                                                 (int)(mv->destination).y - (int)(pIVar4->position).y,
                                                                                                                                 (int)(mv->destination).z - (int)(pIVar4->position).z),
                                                                                                        (int)mv->guardRange < lVar2))))
            {
              MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
              MON_PlayCombatIdle(instance, 2);
              uVar6 = 0;
            }
          }
          else
          {
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
            uVar6 = 0;
          }
        }
      }
      else
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
        uVar6 = 0;
      }
    }
  }
  if (uVar6 == 0)
  {
    MON_DefaultQueueHandler(instance);
    return;
  }
  anim = MON_CheckPointSuitability(instance, &instance->position, &mv->destination);
  iVar7 = -1;
  if (anim == 0)
  {
    MON_GetPlanSlot(mv);
    MON_DefaultQueueHandler(instance);
    if (uVar6 != 1)
    {
      return;
    }
    mv->validUnits[0] = 0;
    return;
  }
  sVar1 = target->distance;
  p_Var3 = MON_GetAnim(instance, mv->subAttr->animList, 2);
  anim = 3;
  if ((int)sVar1 < (int)(distance + (uint)p_Var3->distance))
  {
    anim = 2;
  }
  if (distance < 0)
  {
    distance = 0;
  }
  anim = MON_DefaultPlanMovement(instance, anim, distance);
  switch (anim)
  {
  default:
    goto LAB_8008a9f0;
  case 2:
    if (uVar6 == 1)
    {
      mv->validUnits[0] = 0;
    }
    break;
  case 3:
  switchD_8008a980_caseD_3:
    iVar7 = 2;
    goto LAB_8008a9f0;
  case 4:
    if (uVar6 == 2)
    {
      iVar7 = 0xd;
      goto LAB_8008a9f0;
    }
    if (uVar6 < 3)
    {
      if (uVar6 != 1)
        goto LAB_8008a9f0;
      goto switchD_8008a980_caseD_3;
    }
    if (uVar6 != 3)
      goto LAB_8008a9f0;
  }
  MON_GetPlanSlot(mv);
LAB_8008a9f0:
  if (iVar7 != -1)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_WanderEntry(struct _Instance *instance /*$s1*/)
// line 2176, offset 0x8008aa54
/* begin block 1 */
// Start line: 2177
// Start offset: 0x8008AA54
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8008AAC4
// End Line: 2193

/* begin block 2 */
// Start line: 4625
/* end block 2 */
// End Line: 4626

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
  if ((uVar1 & 4) == 0)
  {
    MON_GetPlanSlot(mv);
    iVar2 = MON_AnimPlaying(instance, (MonsterAnim)
                                          CONCAT412(in_stack_fffffffc,
                                                    CONCAT48(local_8, CONCAT44(local_c, local_10))));
    if (iVar2 == 0)
    {
      MON_PlayRandomIdle(instance, 2);
    }
  }
  else
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
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
// line 2199, offset 0x8008aafc
/* begin block 1 */
// Start line: 2200
// Start offset: 0x8008AAFC
// Variables:
// 		struct _MonsterVars *mv; // $s1

/* begin block 1.1 */
// Start line: 2205
// Start offset: 0x8008AB34
/* end block 1.1 */
// End offset: 0x8008AB88
// End Line: 2210

/* begin block 1.2 */
// Start line: 2220
// Start offset: 0x8008ABD8
// Variables:
// 		int markerID; // $s0
/* end block 1.2 */
// End offset: 0x8008AC20
// End Line: 2224

/* begin block 1.3 */
// Start line: 2232
// Start offset: 0x8008AC34
// Variables:
// 		struct _Position *target; // $a1
// 		short range; // $a2
/* end block 1.3 */
// End offset: 0x8008AC78
// End Line: 2246

/* begin block 1.4 */
// Start line: 2252
// Start offset: 0x8008AC88
// Variables:
// 		int planresult; // $v1
// 		int state; // $a1
/* end block 1.4 */
// End offset: 0x8008AD18
// End Line: 2289
/* end block 1 */
// End offset: 0x8008AD58
// End Line: 2297

/* begin block 2 */
// Start line: 4673
/* end block 2 */
// End Line: 4674

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
  if ((*puVar7 & 4) == 0)
  {
    if ((*puVar7 & 0x40000) != 0)
    {
      iVar5 = MON_DefaultPlanMovement(instance, 2, 100);
      iVar6 = -1;
      switch (iVar5)
      {
      case 2:
      case 3:
        iVar6 = 2;
        break;
      case 4:
        iVar6 = 0x14;
        if (*(char *)((int)puVar7 + 0x146) != '\x04')
        {
          uVar4 = rand();
          iVar6 = 2;
          if ((uVar4 & 3) == 0)
          {
            uVar2 = MON_GetTime(instance);
            puVar7[0x40] = uVar2 + 1000;
            iVar6 = 5;
          }
        }
      }
      if (iVar6 != -1)
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
      }
      goto LAB_8008ad18;
    }
    uVar2 = MON_GetTime(instance);
    if (puVar7[0x40] < uVar2)
      goto LAB_8008ab7c;
    if (*(char *)((int)puVar7 + 0x146) == '\x03')
    {
      psVar3 = (short *)puVar7[99];
      if (psVar3 != (short *)0x0)
      {
        r = *psVar3;
        *(short **)(puVar7 + 99) = psVar3 + 1;
        streamUnit = STREAM_GetStreamUnitWithID(instance->currentStreamUnitID);
        PLANAPI_FindNodePositionInUnit(streamUnit, (_Position *)((int)puVar7 + 0x112), (int)r, 0);
        if (*(short *)puVar7[99] == 0)
        {
          *(uint **)(puVar7 + 99) = puVar7 + 0x5d;
        }
        *puVar7 = *puVar7 | 0x40000;
      }
    }
    else
    {
      r = *(short *)(puVar7 + 0x48);
      in = (_Position *)0x0;
      if (puVar7[0x32] == 0)
      {
        if (instance->intro != (Intro *)0x0)
        {
          in = &instance->intro->position;
        }
      }
      else
      {
        r = 800;
        in = (_Position *)(*(int *)(puVar7[0x32] + 4) + 0x5c);
      }
      MON_GetRandomDestinationInWorld(instance, in, r);
    }
  }
  else
  {
    MON_TurnToPosition(instance, (_Position *)((int)puVar7 + 0x112), *(short *)(puVar7[0x55] + 0x1e));
    lVar1 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)((int)puVar7 + 0x112),
                             (int)(instance->position).y - (int)*(short *)(puVar7 + 0x45),
                             (int)(instance->position).z - (int)*(short *)((int)puVar7 + 0x116));
    if (lVar1 < 300)
    {
    LAB_8008ab7c:
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
  }
  MON_GroundMoveQueueHandler(instance);
LAB_8008ad18:
  if (puVar7[0x31] != 0)
  {
    iVar5 = MON_ShouldIFlee(instance);
    if (iVar5 != 0)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
    puVar7[0x43] = *(int *)(puVar7[0x31] + 4) + 0x5c;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_HideEntry(struct _Instance *instance /*$a0*/)
// line 2302, offset 0x8008ad74
/* begin block 1 */
// Start line: 4882
/* end block 1 */
// End Line: 4883

void MON_HideEntry(_Instance *instance)

{
  MON_PlayRandomIdle(instance, 1);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Hide(struct _Instance *instance /*$s1*/)
// line 2308, offset 0x8008ad94
/* begin block 1 */
// Start line: 2309
// Start offset: 0x8008AD94
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterIR *enemy; // $s2
/* end block 1 */
// End offset: 0x8008AEF0
// End Line: 2357

/* begin block 2 */
// Start line: 4894
/* end block 2 */
// End Line: 4895

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
  if (((*puVar2 & 4) != 0) || (uVar3 == 0))
    goto LAB_8008aeb0;
  bVar1 = *(byte *)((int)puVar2 + 0x146);
  if (bVar1 == 8)
  {
    if (((*puVar2 & 0x40000000) != 0) || (mode = MON_ShouldIAmbushEnemy(instance), mode == 0))
      goto LAB_8008aeb0;
    if (*(char *)((int)puVar2 + 0x143) != '\0')
    {
      if (*(char *)((int)puVar2 + 0x143) == '\x01')
      {
        mode = 0x28;
      }
      else
      {
        mode = 0x29;
      }
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10))), mode);
      *puVar2 = *puVar2 | 0x40000000;
      goto LAB_8008aeb0;
    }
    MON_TurnToPosition(instance, (_Position *)(*(int *)(uVar3 + 4) + 0x5c), 0x1000);
  }
  else
  {
    if ((bVar1 < 9) && (bVar1 == 4))
    {
      MON_ChangeBehavior(instance, (uint) * (byte *)(puVar2 + 0x52));
      goto LAB_8008aeb0;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
LAB_8008aeb0:
  if ((instance->flags2 & 0x10U) != 0)
  {
    if ((*puVar2 & 0x40000000) == 0)
    {
      MON_PlayRandomIdle(instance, 1);
    }
    else
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
  }
  MON_DefaultQueueHandler(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SurpriseAttackEntry(struct _Instance *instance /*$a0*/)
// line 2363, offset 0x8008af10
/* begin block 1 */
// Start line: 2364
// Start offset: 0x8008AF10
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterCombatAttributes *combatAttr; // $v0
// 		struct _MonsterAttributes *ma; // $v1
/* end block 1 */
// End offset: 0x8008AF94
// End Line: 2390

/* begin block 2 */
// Start line: 5006
/* end block 2 */
// End Line: 5007

void MON_SurpriseAttackEntry(_Instance *instance)

{
  char cVar1;
  int iVar2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  cVar1 = *(char *)(*(int *)(*(int *)((int)pvVar3 + 0x154) + 8) + 0x1f);
  iVar2 = *(int *)((int)instance->data + 0x38);
  *(undefined *)((int)pvVar3 + 0x14b) = 0;
  iVar2 = iVar2 + (int)cVar1 * 0x20;
  *(int *)((int)pvVar3 + 0xb8) = iVar2;
  MON_PlayAnimFromList(instance, (char *)(iVar2 + 0x1b), 0, 1);
  if (*(char *)((int)pvVar3 + 0x146) == '\b')
  {
    if (*(char *)((int)pvVar3 + 0x149) == -1)
    {
      *(undefined *)((int)pvVar3 + 0x146) = *(undefined *)((int)pvVar3 + 0x147);
    }
    else
    {
      *(undefined *)((int)pvVar3 + 0x146) = *(undefined *)((int)pvVar3 + 0x149);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SurpriseAttack(struct _Instance *instance /*$a0*/)
// line 2392, offset 0x8008afa4
/* begin block 1 */
// Start line: 5075
/* end block 1 */
// End Line: 5076

void MON_SurpriseAttack(_Instance *instance)

{
  MON_Attack(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_EnvironmentDamageEntry(struct _Instance *instance /*$a0*/)
// line 2400, offset 0x8008afc4
/* begin block 1 */
// Start line: 5091
/* end block 1 */
// End Line: 5092

/* begin block 2 */
// Start line: 5092
/* end block 2 */
// End Line: 5093

void MON_EnvironmentDamageEntry(_Instance *instance)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_EnvironmentDamage(struct _Instance *instance /*$a0*/)
// line 2404, offset 0x8008afcc
/* begin block 1 */
// Start line: 5099
/* end block 1 */
// End Line: 5100

/* begin block 2 */
// Start line: 5100
/* end block 2 */
// End Line: 5101

void MON_EnvironmentDamage(_Instance *instance)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_MonsterGlow(struct _Instance *instance /*$fp*/, long color /*stack 4*/, int glowtime /*$s5*/, int glowin /*$s6*/, int glowfade /*stack 16*/)
// line 2408, offset 0x8008afd4
/* begin block 1 */
// Start line: 2409
// Start offset: 0x8008AFD4
// Variables:
// 		struct _FXGlowEffect *glow; // $v0
// 		struct _MonsterAttributes *ma; // $s4
/* end block 1 */
// End offset: 0x8008B03C
// End Line: 2417

/* begin block 2 */
// Start line: 5107
/* end block 2 */
// End Line: 5108

void MON_MonsterGlow(_Instance *instance, long color, int glowtime, int glowin, int glowfade)

{
  _FXGlowEffect *p_Var1;
  short sVar2;
  short sVar3;
  void *pvVar4;
  short sVar5;
  long local_res4[3];

  sVar3 = (short)glowin;
  sVar2 = (short)glowtime;
  sVar5 = (short)glowfade;
  pvVar4 = instance->data;
  if (0 < glowtime)
  {
    sVar2 = sVar2 * 0x21;
  }
  if (0 < glowfade)
  {
    sVar5 = sVar5 * 0x21;
  }
  if (0 < glowin)
  {
    sVar3 = sVar3 * 0x21;
  }
  local_res4[0] = color;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, (uint) * (byte *)((int)pvVar4 + 0x1d),
                                       (uint) * (byte *)((int)pvVar4 + 0x20), local_res4, 1, 0x400, 0xa0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, (uint) * (byte *)((int)pvVar4 + 0x1d),
                                       (uint) * (byte *)((int)pvVar4 + 0x21), local_res4, 1, 0x400, 0xa0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, (uint) * (byte *)((int)pvVar4 + 0x1b),
                                       (uint) * (byte *)((int)pvVar4 + 0x23), local_res4, 1, 0x400, 0x80);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, (uint) * (byte *)((int)pvVar4 + 0x1c),
                                       (uint) * (byte *)((int)pvVar4 + 0x24), local_res4, 1, 0x400, 0x80);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(instance, (uint) * (byte *)((int)pvVar4 + 0x19),
                                       (uint) * (byte *)((int)pvVar4 + 0x1d), local_res4, 1, 0x400, 0xc0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_GeneralDeathEntry(struct _Instance *instance /*$s1*/)
// line 2436, offset 0x8008b160
/* begin block 1 */
// Start line: 2437
// Start offset: 0x8008B160
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterAttributes *ma; // $s2
/* end block 1 */
// End offset: 0x8008B37C
// End Line: 2511

/* begin block 2 */
// Start line: 5171
/* end block 2 */
// End Line: 5172

void MON_GeneralDeathEntry(_Instance *instance)

{
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  int mode;
  undefined4 local_10;
  uint *puVar4;
  undefined4 local_c;
  void *pvVar5;
  undefined4 local_18;
  undefined *puVar6;
  undefined4 in_stack_ffffffec;

  puVar4 = (uint *)instance->extraData;
  pvVar5 = instance->data;
  if (instance->LinkParent != (_Instance *)0x0)
  {
    MON_UnlinkFromRaziel(instance);
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = -0x10;
  }
  instance->flags2 = instance->flags2 | 0x80;
  uVar1 = *(ushort *)(puVar4 + 0x50);
  *puVar4 = *puVar4 & 0xffffffef | 0x202000;
  if (uVar1 == 0x20)
  {
    *(undefined *)(puVar4 + 0x51) = 1;
  LAB_8008b270:
    if ((*(uint *)((int)pvVar5 + 0x10) & 8) == 0)
    {
      mode = 0x1b;
    }
    else
    {
      mode = 0x24;
    }
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))), mode);
    if (*(short *)(puVar4 + 0x50) == 0x40)
    {
      *(undefined *)(puVar4 + 0x51) = 2;
    }
    uVar2 = MON_GetTime(instance);
    puVar4[0x40] = uVar2 + 2000;
    *puVar4 = *puVar4 | 0x400000;
    uVar2 = MON_GetTime(instance);
    *(undefined **)(puVar4 + 0x42) = &DAT_00002710 + uVar2;
    MON_MonsterGlow(instance, (long)&DAT_00004960, -1, 0, 0);
    instance->xAccl = 0;
  }
  else
  {
    if (uVar1 < 0x21)
    {
      if (uVar1 == 0x10)
      {
        puVar6 = &DAT_00002710;
        uVar2 = SOUND_Play3dSound(&instance->position, 0x23, 600, 0x50, (int)&DAT_00002710);
        puVar4[0x37] = uVar2;
        MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, puVar6))), 0x1b);
        *(undefined *)(puVar4 + 0x51) = 3;
        uVar2 = MON_GetTime(instance);
        puVar4[0x40] = uVar2 + 3000;
        uVar2 = MON_GetTime(instance);
        *(undefined **)(puVar4 + 0x42) = &DAT_00002ee0 + uVar2;
      }
      else
      {
      LAB_8008b320:
        if (puVar4[0x31] == 0)
        {
          mode = 0x24;
        }
        else
        {
          iVar3 = MON_SetUpKnockBack(instance, *(_Instance **)(puVar4[0x31] + 4),
                                     (evMonsterHitData *)puVar4[0x30]);
          mode = 0;
          if (iVar3 == 0)
          {
            mode = 1;
          }
        }
        MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))), mode);
        puVar4[0x40] = 0;
        *(undefined *)(puVar4 + 0x51) = 7;
        MON_TurnOffAllSpheres(instance);
      }
    }
    else
    {
      if (uVar1 == 0x40)
        goto LAB_8008b270;
      if (uVar1 != 0x400)
        goto LAB_8008b320;
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))), 0x24);
      *(undefined *)(puVar4 + 0x51) = 6;
      puVar4[0x40] = 0;
    }
    instance->xAccl = 0;
  }
  instance->yAccl = 0;
  instance->xVel = 0;
  instance->yVel = 0;
  MON_DropAllObjects(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_GeneralDeath(struct _Instance *instance /*$s1*/)
// line 2524, offset 0x8008b3ac
/* begin block 1 */
// Start line: 2525
// Start offset: 0x8008B3AC
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct __Event *message; // $v0
// 		int dead; // $s2
/* end block 1 */
// End offset: 0x8008B508
// End Line: 2578

/* begin block 2 */
// Start line: 5359
/* end block 2 */
// End Line: 5360

void MON_GeneralDeath(_Instance *instance)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  __Event *p_Var5;
  undefined4 local_18;
  uint *puVar6;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;

  puVar6 = (uint *)instance->extraData;
  bVar1 = false;
  if ((((instance->flags2 & 0x10U) == 0) ||
       (iVar2 = MON_AnimPlaying(instance, (MonsterAnim)
                                              CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14,
                                                                                             local_18)))),
        iVar2 == 0)) &&
      (*(char *)(puVar6 + 0x51) != '\x06'))
  {
    if (((instance->flags2 & 0x12U) != 0) && (uVar3 = MON_GetTime(instance), puVar6[0x40] < uVar3))
    {
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14, local_18))), 0x24);
      MON_TurnOffAllSpheres(instance);
    }
  }
  else
  {
    bVar1 = true;
  }
  if (bVar1)
  {
    *puVar6 = *puVar6 & 0xffffffef;
    G2Anim_SetNoLooping(&instance->anim);
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  }
  if ((*puVar6 & 0x400) != 0)
  {
    iVar2 = MON_OnGround(instance);
    if (iVar2 == 0)
    {
      uVar4 = *puVar6 & 0xfffffffd;
    }
    else
    {
      uVar4 = *puVar6 | 2;
    }
    *puVar6 = uVar4;
  }
  if ((*puVar6 & 2) == 0)
  {
    MON_ApplyPhysics(instance);
  }
  while (p_Var5 = DeMessageQueue((__MessageQueue *)(puVar6 + 2)), p_Var5 != (__Event *)0x0)
  {
    if (p_Var5->ID == 0x100000b)
    {
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = -0x10;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_NoticeEntry(struct _Instance *instance /*$s1*/)
// line 2583, offset 0x8008b524
/* begin block 1 */
// Start line: 2584
// Start offset: 0x8008B524
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8008B5C8
// End Line: 2596

/* begin block 2 */
// Start line: 5481
/* end block 2 */
// End Line: 5482

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
      (*(int *)(*(int *)(*(int *)((int)pvVar1 + 0x154) + 0xc) + 4) != 0))
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x2a);
    sender = *(_Instance **)(*(int *)((int)pvVar1 + 0xc4) + 4);
    Data = SetMonsterAlarmData(sender, &sender->position, 2);
    INSTANCE_Broadcast(instance, *(long *)(*(int *)(*(int *)((int)pvVar1 + 0x154) + 0xc) + 4),
                       0x1000011, Data);
  }
  else
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1d);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Notice(struct _Instance *instance /*$s1*/)
// line 2598, offset 0x8008b5dc
/* begin block 1 */
// Start line: 2599
// Start offset: 0x8008B5DC
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8008B660
// End Line: 2616

/* begin block 2 */
// Start line: 5511
/* end block 2 */
// End Line: 5512

void MON_Notice(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;

  pvVar1 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  }
  if (*(int *)((int)pvVar1 + 0xc4) != 0)
  {
    *(int *)((int)pvVar1 + 0x10c) = *(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c;
    MON_TurnToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c),
                       *(short *)(*(int *)((int)pvVar1 + 0x154) + 0x1c));
  }
  MON_DefaultQueueHandler(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PupateEntry(struct _Instance *instance /*$a0*/)
// line 2622, offset 0x8008b67c
/* begin block 1 */
// Start line: 2623
// Start offset: 0x8008B67C
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x8008B67C
// End Line: 2623

/* begin block 2 */
// Start line: 5561
/* end block 2 */
// End Line: 5562

void MON_PupateEntry(_Instance *instance)

{
  ulong uVar1;
  uint uVar2;
  void *pvVar3;

  instance->flags = instance->flags | 0x800;
  pvVar3 = instance->extraData;
  instance->flags2 = instance->flags2 | 0x20000000;
  uVar1 = MON_GetTime(instance);
  uVar2 = rand();
  *(int *)((int)pvVar3 + 0x108) = uVar1 + (uVar2 & 0xfff) + 2000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Pupate(struct _Instance *instance /*$s2*/)
// line 2632, offset 0x8008b6dc
/* begin block 1 */
// Start line: 2633
// Start offset: 0x8008B6DC
// Variables:
// 		struct _MonsterVars *mv; // $s3

/* begin block 1.1 */
// Start line: 2639
// Start offset: 0x8008B71C
// Variables:
// 		struct _MonsterAttributes *ma; // $s0
// 		static unsigned char pupateObjects[4]; // offset 0x0
// 		struct Object *cocoonOb; // $s6
// 		struct _Instance *cocoon; // $s1
// 		struct _Instance *closest; // $s4
// 		long closestDist; // $s5
// 		int burst; // $s7

/* begin block 1.1.1 */
// Start line: 2657
// Start offset: 0x8008B79C
// Variables:
// 		long dist; // $v1
/* end block 1.1.1 */
// End offset: 0x8008B89C
// End Line: 2675
/* end block 1.1 */
// End offset: 0x8008B988
// End Line: 2712
/* end block 1 */
// End offset: 0x8008B9F0
// End Line: 2728

/* begin block 2 */
// Start line: 5586
/* end block 2 */
// End Line: 5587

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
  if ((instance->flags & 0x800U) == 0)
  {
    MON_DefaultQueueHandler(instance);
    if (puVar8[0x31] != 0)
    {
      MON_TurnToPosition(instance, (_Position *)(*(int *)(puVar8[0x31] + 4) + 0x5c),
                         *(short *)(puVar8[0x55] + 0x1c));
    }
    if ((instance->flags2 & 0x10U) != 0)
    {
      MON_ChangeBehavior(instance, (uint) * (byte *)(puVar8 + 0x52));
    }
  }
  else
  {
    Inst = (_Instance *)0x0;
    _uVar9 = 99999;
    uVar9 = 0x869f;
    pvVar7 = instance->data;
    bVar2 = false;
    MON_PupateQueueHandler(instance);
    Data = (int)*(char *)((int)pvVar7 + 0x17);
    if (Data != -1)
    {
      instance_00 = (gameTrackerX.instanceList)->first;
      pOVar10 = (Object *)(&objectAccess)[(uint)(byte)(&DAT_800ca9ec)[Data]].object;
      while (instance_00 != (_Instance *)0x0)
      {
        if ((instance_00->object == pOVar10) && ((instance_00->flags & 0x20U) == 0))
        {
          pIVar6 = instance->intro;
          lVar3 = MATH3D_LengthXYZ((int)(instance_00->position).x - (int)(pIVar6->position).x,
                                   (int)(instance_00->position).y - (int)(pIVar6->position).y,
                                   (int)(instance_00->position).z - (int)(pIVar6->position).z);
          if (lVar3 < (int)*(short *)(puVar8 + 0x48))
          {
            lVar3 = MATH3D_LengthXYZ((int)(instance_00->position).x -
                                         (int)((gameTrackerX.playerInstance)->position).x,
                                     (int)(instance_00->position).y -
                                         (int)((gameTrackerX.playerInstance)->position).y,
                                     (int)(instance_00->position).z -
                                         (int)((gameTrackerX.playerInstance)->position).z);
            if (lVar3 < _uVar9)
            {
              Inst = instance_00;
              _uVar9 = lVar3;
            }
            uVar4 = MON_GetTime(instance);
            if ((puVar8[0x42] < uVar4) && (uVar5 = rand(), (uVar5 & 0xf) == 0))
            {
              local_30 = 1;
              Data = SetAnimationInstanceSwitchData(instance_00, 0, 0, 0, 1);
              INSTANCE_Post(instance_00, 0x8000008, Data);
              uVar4 = MON_GetTime(instance);
              uVar5 = rand();
              puVar8[0x42] = uVar4 + (uVar5 & 0xfff) + 2000;
            }
          }
        }
        uVar9 = (undefined2)_uVar9;
        instance_00 = instance_00->next;
      }
      if (Inst != (_Instance *)0x0)
      {
        sVar1 = (Inst->position).z;
        *(undefined4 *)&instance->position = *(undefined4 *)&Inst->position;
        (instance->position).z = sVar1;
        uVar5 = puVar8[0x31];
        if ((uVar5 != 0) && (*(_Instance **)(uVar5 + 4) == gameTrackerX.playerInstance))
        {
          *(undefined2 *)(uVar5 + 0x14) = uVar9;
        }
      }
    }
    if (instance->currentMainState == 0x1a)
    {
      if ((Inst == (_Instance *)0x0) && (pOVar10 != (Object *)0x0))
      {
        *(undefined2 *)((int)puVar8 + 0x136) = 0;
        MON_KillMonster(instance);
      }
      else
      {
        _uVar9 = MON_ShouldIAmbushEnemy(instance);
        if (_uVar9 != 0)
        {
          MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_24, CONCAT48(local_28, CONCAT44(in_stack_ffffffd4, local_30))), 0x1c);
          bVar2 = true;
        }
      }
    }
    else
    {
      bVar2 = true;
    }
    if (bVar2)
    {
      instance->flags = instance->flags & 0xfffff7ff;
      instance->flags2 = instance->flags2 & 0xdfffffff;
      *puVar8 = *puVar8 & 0xffffff7f;
      if (Inst != (_Instance *)0x0)
      {
        INSTANCE_Post(Inst, (int)&DAT_00040002, 5);
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_EmbraceEntry(struct _Instance *instance /*$s0*/)
// line 2733, offset 0x8008ba1c
/* begin block 1 */
// Start line: 2734
// Start offset: 0x8008BA1C
// Variables:
// 		struct _MonsterVars *mv; // $s1
/* end block 1 */
// End offset: 0x8008BA1C
// End Line: 2734

/* begin block 2 */
// Start line: 5823
/* end block 2 */
// End Line: 5824

void MON_EmbraceEntry(_Instance *instance)

{
  ulong uVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar2;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  pvVar2 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1e);
  uVar1 = MON_GetTime(instance);
  *(int *)((int)pvVar2 + 0x100) =
      uVar1 + (int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x154) + 8) + 0x1a);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Embrace(struct _Instance *instance /*$s3*/)
// line 2742, offset 0x8008ba7c
/* begin block 1 */
// Start line: 2743
// Start offset: 0x8008BA7C
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterIR *enemy; // $s1

/* begin block 1.1 */
// Start line: 2758
// Start offset: 0x8008BB24
// Variables:
// 		struct _Instance *ei; // $s2
/* end block 1.1 */
// End offset: 0x8008BB78
// End Line: 2762
/* end block 1 */
// End offset: 0x8008BBE0
// End Line: 2773

/* begin block 2 */
// Start line: 5844
/* end block 2 */
// End Line: 5845

void MON_Embrace(_Instance *instance)

{
  ulong uVar1;
  int iVar2;
  undefined4 local_18;
  uint *puVar3;
  undefined4 local_14;
  uint uVar4;
  _Instance *ei;

  puVar3 = (uint *)instance->extraData;
  uVar4 = puVar3[0x31];
  if ((((uVar4 == 0) || (*(short *)(*(int *)(puVar3[0x55] + 8) + 0x18) < *(short *)(uVar4 + 0x14))) || ((*(uint *)(uVar4 + 0x14) & 0x10200000) != 0x10200000)) ||
      (((*puVar3 & 4) != 0 || (uVar1 = MON_GetTime(instance), puVar3[0x40] < uVar1))))
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  }
  else
  {
    ei = *(_Instance **)(uVar4 + 4);
    MON_DoDrainEffects(instance, ei);
    INSTANCE_Post(ei, (int)&PTR_00040006, (int)*(short *)(*(int *)(puVar3[0x55] + 8) + 0x16) << 8);
    iVar2 = (int)*(short *)(*(int *)(puVar3[0x55] + 8) + 0x16);
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 7;
    }
    INSTANCE_Post(instance, 0x1000016, iVar2 >> 3);
    MON_TurnToPosition(instance, &ei->position, *(short *)(puVar3[0x55] + 0x1c));
  }
  MON_DefaultQueueHandler(instance);
  if ((uVar4 != 0) && (instance->currentMainState != 0x1b))
  {
    *(ushort *)(uVar4 + 0x16) = *(ushort *)(uVar4 + 0x16) & 0xefff;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PetrifiedEntry(struct _Instance *instance /*$a0*/)
// line 2857, offset 0x8008bbfc
/* begin block 1 */
// Start line: 2858
// Start offset: 0x8008BBFC
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8008BBFC
// End Line: 2858

/* begin block 2 */
// Start line: 5714
/* end block 2 */
// End Line: 5715

void MON_PetrifiedEntry(_Instance *instance)

{
  ulong uVar1;
  uint *puVar2;

  puVar2 = (uint *)instance->extraData;
  uVar1 = MON_GetTime(instance);
  *(undefined **)(puVar2 + 0x40) = &DAT_00001b58 + uVar1;
  *puVar2 = *puVar2 | 0x80;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_Petrified(struct _Instance *instance /*$s1*/)
// line 2865, offset 0x8008bc38
/* begin block 1 */
// Start line: 2866
// Start offset: 0x8008BC38
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct __Event *message; // $v0
// 		int time; // $v1
/* end block 1 */
// End offset: 0x8008BD20
// End Line: 2889

/* begin block 2 */
// Start line: 6006
/* end block 2 */
// End Line: 6007

void MON_Petrified(_Instance *instance)

{
  ulong uVar1;
  __Event *p_Var2;
  uint uVar3;
  undefined4 local_20;
  uint *puVar4;
  undefined4 local_1c;

  puVar4 = (uint *)instance->extraData;
  uVar1 = MON_GetTime(instance);
  uVar3 = puVar4[0x40];
  if (uVar3 < uVar1)
  {
    *puVar4 = *puVar4 & 0xffffff7f;
    instance->petrifyValue = 0;
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
  }
  else
  {
    if (uVar3 - 1000 < uVar1)
    {
      instance->petrifyValue = ((short)uVar3 - (short)uVar1) * 4;
    }
  }
  while (p_Var2 = DeMessageQueue((__MessageQueue *)(puVar4 + 2)), p_Var2 != (__Event *)0x0)
  {
    if ((p_Var2->ID == 0x100001f) || ((p_Var2->ID == 0x1000023 && (p_Var2->Data == 0x1000))))
    {
      *(undefined2 *)(puVar4 + 0x50) = 0x400;
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MONSTER_CalcDamageIntensity(int hp /*$a0*/, int maxHp /*$a1*/)
// line 2897, offset 0x8008bd44
/* begin block 1 */
// Start line: 6074
/* end block 1 */
// End Line: 6075

/* begin block 2 */
// Start line: 6075
/* end block 2 */
// End Line: 6076

int MONSTER_CalcDamageIntensity(int hp, int maxHp)

{
  return ((maxHp - hp) * 0x100) / maxHp;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSTER_ProcessClosestVerts(struct _Instance *instance /*$fp*/, struct _SVector *location /*stack 4*/, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb /*stack 8*/, void *cb_data /*stack 12*/)
// line 2907, offset 0x8008bd5c
/* begin block 1 */
// Start line: 2908
// Start offset: 0x8008BD5C
// Variables:
// 		int i; // $s2
// 		struct _Model *model; // $s7
// 		struct _MVertex *vertexList; // $s4
// 		struct _Vector locVec; // stack offset -96
// 		long flag; // stack offset -48

/* begin block 1.1 */
// Start line: 2925
// Start offset: 0x8008BDE0
// Variables:
// 		struct _MVertex *firstVertex; // $s0
// 		struct _MVertex *lastVertex; // $s5
// 		struct _MVertex *modelVertex; // $s0
// 		struct MATRIX inverse; // stack offset -80
// 		int tmp; // $a3
// 		int dist; // $a0
/* end block 1.1 */
// End offset: 0x8008BEDC
// End Line: 2958
/* end block 1 */
// End offset: 0x8008BEF4
// End Line: 2960

/* begin block 2 */
// Start line: 6094
/* end block 2 */
// End Line: 6095

void MONSTER_ProcessClosestVerts(_Instance *instance, _SVector *location,
                                 TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb, void *cb_data)

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
  undefined auStack48[8];

  p_Var9 = instance->object->modelList[(int)instance->currentModel];
  iVar6 = 1;
  p_Var8 = p_Var9->vertexList;
  if (1 < p_Var9->numSegments)
  {
    psVar7 = &p_Var9->segmentList[1].firstVertex;
    do
    {
      sVar1 = psVar7[1];
      if ((int)sVar1 != -1)
      {
        p_Var4 = p_Var8 + (int)*psVar7;
        PIPE3D_InvertTransform(&MStack80, instance->matrix + iVar6);
        SetRotMatrix((undefined4 *)&MStack80);
        SetTransMatrix((int)&MStack80);
        RotTrans(location, &local_60, auStack48);
        if (p_Var4 <= p_Var8 + (int)sVar1)
        {
          psVar5 = &(p_Var4->vertex).z;
          do
          {
            iVar2 = (int)(p_Var4->vertex).x - local_60;
            if (iVar2 < 0)
            {
              iVar2 = -iVar2;
            }
            iVar3 = (int)psVar5[-1] - local_5c;
            if (iVar3 < 0)
            {
              iVar3 = -iVar3;
            }
            if (iVar3 < iVar2)
            {
              iVar3 = iVar2;
            }
            iVar2 = (int)*psVar5 - local_58;
            if (iVar2 < 0)
            {
              iVar2 = -iVar2;
            }
            if (iVar2 < iVar3)
            {
              iVar2 = iVar3;
            }
            (*processVert_cb)(instance, (int)((int)p_Var4 - (int)p_Var8) >> 3, iVar6, iVar2, cb_data);
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
// line 2967, offset 0x8008bf24
/* begin block 1 */
// Start line: 2968
// Start offset: 0x8008BF24
// Variables:
// 		struct _MonsterVars *mv; // $t0

/* begin block 1.1 */
// Start line: 2988
// Start offset: 0x8008BF54
// Variables:
// 		long scl; // $a2
// 		struct CVECTOR *cv; // $a0
/* end block 1.1 */
// End offset: 0x8008C028
// End Line: 3014
/* end block 1 */
// End offset: 0x8008C028
// End Line: 3015

/* begin block 2 */
// Start line: 6288
/* end block 2 */
// End Line: 6289

void ProcessBloodyMess(_Instance *instance, int vertidx, int segidx, int dist, void *cb_data)

{
  byte bVar1;
  CVECTOR *pCVar2;
  int iVar3;
  void *pvVar4;

  pvVar4 = instance->extraData;
  if (dist < *(int *)((int)cb_data + 4))
  {
    *(int *)cb_data = vertidx;
    *(int *)((int)cb_data + 4) = dist;
    *(int *)((int)cb_data + 8) = segidx;
  }
  if (dist < 100)
  {
    iVar3 = ((100 - dist) * *(int *)((int)cb_data + 0x10) * 2) / 100;
    pCVar2 = instance->perVertexColor + vertidx;
    if (0x100 < iVar3)
    {
      iVar3 = 0x100;
    }
    pCVar2->r = ~(byte)((0xff - (uint) * (byte *)(*(int *)((int)pvVar4 + 0x154) + 0x3f)) * iVar3 >> 8);
    pCVar2->g = ~(byte)((0xff - (uint) * (byte *)(*(int *)((int)pvVar4 + 0x154) + 0x40)) * iVar3 >> 8);
    bVar1 = *(byte *)(*(int *)((int)pvVar4 + 0x154) + 0x41);
    pCVar2->cd = '\x01';
    pCVar2->b = ~(byte)((0xff - (uint)bVar1) * iVar3 >> 8);
    *(undefined4 *)((int)cb_data + 0xc) = 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSTER_InitVertexColors(struct _Instance *instance /*$s1*/, struct _Model *model /*$s0*/)
// line 3017, offset 0x8008c030
/* begin block 1 */
// Start line: 3018
// Start offset: 0x8008C030
// Variables:
// 		int i; // $s0
// 		struct CVECTOR *ptr; // $v0
/* end block 1 */
// End offset: 0x8008C084
// End Line: 3027

/* begin block 2 */
// Start line: 6403
/* end block 2 */
// End Line: 6404

void MONSTER_InitVertexColors(_Instance *instance, _Model *model)

{
  CVECTOR *pCVar1;
  int iVar2;

  pCVar1 = (CVECTOR *)MEMPACK_Malloc(model->numVertices << 2, '!');
  instance->perVertexColor = pCVar1;
  iVar2 = model->numVertices;
  while (iVar2 != 0)
  {
    *pCVar1 = (CVECTOR)0xffffff;
    iVar2 = iVar2 + -1;
    pCVar1 = pCVar1 + 1;
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MONSTER_StartVertexBlood(struct _Instance *instance /*$s2*/, struct _SVector *location /*$s0*/, int amount /*$s4*/)
// line 3029, offset 0x8008c098
/* begin block 1 */
// Start line: 3030
// Start offset: 0x8008C098
// Variables:
// 		struct _Model *model; // $s1
// 		struct bloodyMessType bmt; // stack offset -88

/* begin block 1.1 */
// Start line: 3041
// Start offset: 0x8008C0FC
// Variables:
// 		struct _SVector localloc; // stack offset -64

/* begin block 1.1.1 */
// Start line: 3052
// Start offset: 0x8008C16C
// Variables:
// 		struct _MVertex *vertexList; // $s1
// 		struct _Vector locVec; // stack offset -56
// 		long flag; // stack offset -40
// 		struct MATRIX *segMatrix; // $s0
/* end block 1.1.1 */
// End offset: 0x8008C16C
// End Line: 3052
/* end block 1.1 */
// End offset: 0x8008C1FC
// End Line: 3075
/* end block 1 */
// End offset: 0x8008C1FC
// End Line: 3079

/* begin block 2 */
// Start line: 6428
/* end block 2 */
// End Line: 6429

int MONSTER_StartVertexBlood(_Instance *instance, _SVector *location, int amount)

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
  undefined local_38[8];
  ushort local_30;
  undefined auStack40[8];

  model = instance->object->modelList[(int)instance->currentModel];
  if ((instance->perVertexColor == (CVECTOR *)0x0) &&
      (MONSTER_InitVertexColors(instance, model), instance->perVertexColor == (CVECTOR *)0x0))
  {
    return -1;
  }
  local_40 = *(undefined4 *)location;
  local_3c = *(uint *)&location->z;
  local_58 = -1;
  local_54 = 0x10000;
  local_50 = -1;
  local_4c = 0;
  local_48 = amount;
  MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBloodyMess, &local_58);
  if (local_54 < 0x33)
  {
    FX_MakeHitFX((_SVector *)&local_40);
  }
  else
  {
    p_Var2 = model->vertexList;
    pMVar1 = instance->matrix + local_50;
    SetRotMatrix((undefined4 *)pMVar1);
    SetTransMatrix((int)pMVar1);
    RotTrans(p_Var2 + local_58, local_38, auStack40);
    local_4c = 1;
    local_54 = 0;
    local_3c = local_3c & 0xffff0000 | (uint)local_30;
    FX_MakeHitFX((_SVector *)&local_40);
    MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBloodyMess, &local_58);
  }
  return local_58;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSTER_VertexBlood(struct _Instance *instance /*$s0*/, int vert /*$a1*/, int amount /*$a2*/)
// line 3081, offset 0x8008c220
/* begin block 1 */
// Start line: 3082
// Start offset: 0x8008C220
// Variables:
// 		int i; // $v1
// 		struct _Model *model; // $t0

/* begin block 1.1 */
// Start line: 3088
// Start offset: 0x8008C254
// Variables:
// 		struct CVECTOR *c; // $a3

/* begin block 1.1.1 */
// Start line: 3097
// Start offset: 0x8008C26C
// Variables:
// 		struct _MonsterVars *mv; // $v1
// 		int current; // $a1
// 		int wanted; // $a0
// 		int col; // $a0
/* end block 1.1.1 */
// End offset: 0x8008C3DC
// End Line: 3155
/* end block 1.1 */
// End offset: 0x8008C3DC
// End Line: 3156
/* end block 1 */
// End offset: 0x8008C3DC
// End Line: 3157

/* begin block 2 */
// Start line: 6563
/* end block 2 */
// End Line: 6564

void MONSTER_VertexBlood(_Instance *instance, int vert, int amount)

{
  void *pvVar1;
  int iVar2;
  CVECTOR *address;
  uint uVar3;
  uint uVar4;
  uchar *puVar5;
  CVECTOR *pCVar6;

  address = instance->perVertexColor;
  if (address == (CVECTOR *)0x0)
  {
    return;
  }
  pCVar6 = address + vert;
  if (amount == 0)
  {
    MEMPACK_Free((char *)address);
    instance->perVertexColor = (CVECTOR *)0x0;
    return;
  }
  uVar4 = (uint)pCVar6->g;
  pvVar1 = instance->extraData;
  if ((uint)pCVar6->r < uVar4)
  {
    if ((uint)pCVar6->r < (uint)pCVar6->b)
    {
      uVar4 = (uint)pCVar6->r;
      uVar3 = (uint) * (byte *)(*(int *)((int)pvVar1 + 0x154) + 0x3f);
      goto LAB_8008c2e4;
    }
  }
  else
  {
    if (uVar4 < (uint)pCVar6->b)
    {
      uVar3 = (uint) * (byte *)(*(int *)((int)pvVar1 + 0x154) + 0x40);
      goto LAB_8008c2e4;
    }
  }
  uVar4 = (uint)pCVar6->b;
  uVar3 = (uint) * (byte *)(*(int *)((int)pvVar1 + 0x154) + 0x41);
LAB_8008c2e4:
  if ((pCVar6->cd == '\x01') && ((int)uVar4<(int)((0x100 - amount) * (0xff - uVar3))>> 8))
  {
    iVar2 = instance->object->modelList[(int)instance->currentModel]->numVertices;
    address = instance->perVertexColor;
    if (iVar2 != 0)
    {
      puVar5 = &address->cd;
      do
      {
        if (*puVar5 == '\x01')
        {
          uVar4 = (uint)address->r + 8;
          if (uVar4 < 0x100)
          {
            address->r = (uchar)uVar4;
          }
          else
          {
            address->r = -1;
          }
          if ((uint)puVar5[-2] + 8 < 0x100)
          {
            puVar5[-2] = (uchar)((uint)puVar5[-2] + 8);
          }
          else
          {
            puVar5[-2] = -1;
          }
          if ((uint)puVar5[-1] + 8 < 0x100)
          {
            puVar5[-1] = (uchar)((uint)puVar5[-1] + 8);
          }
          else
          {
            puVar5[-1] = -1;
          }
          if (((uint)*address & 0xffffff) == 0xffffff)
          {
            *puVar5 = '\0';
          }
        }
        iVar2 = iVar2 + -1;
        puVar5 = puVar5 + 4;
        address = address + 1;
      } while (iVar2 != 0);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessBurntMess(struct _Instance *instance /*$a0*/, int vertidx /*$a1*/, int segidx /*$a2*/, int dist /*$a3*/, void *cb_data /*stack 16*/)
// line 3164, offset 0x8008c3ec
/* begin block 1 */
// Start line: 3165
// Start offset: 0x8008C3EC
// Variables:
// 		short scl; // $a2
// 		struct burntTuneType *burntTune; // $t0
/* end block 1 */
// End offset: 0x8008C450
// End Line: 3185

/* begin block 2 */
// Start line: 6758
/* end block 2 */
// End Line: 6759

void ProcessBurntMess(_Instance *instance, int vertidx, int segidx, int dist, void *cb_data)

{
  uchar uVar1;

  if (dist < *(int *)((int)cb_data + 4))
  {
    *(int *)cb_data = vertidx;
    *(int *)((int)cb_data + 4) = dist;
    *(int *)((int)cb_data + 8) = segidx;
  }
  if ((**(int **)((int)cb_data + 0xc) <= dist) ||
      (_uVar1 = ((dist << 0xc) / **(int **)((int)cb_data + 0xc) << 0x10) >> 0x14,
       uVar1 = (uchar)_uVar1, 0xfe < _uVar1))
  {
    uVar1 = -2;
  }
  instance->perVertexColor[vertidx].r = uVar1;
  instance->perVertexColor[vertidx].g = uVar1;
  instance->perVertexColor[vertidx].b = uVar1;
  instance->perVertexColor[vertidx].cd = '\x01';
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MONSTER_StartVertexBurnt(struct _Instance *instance /*$s2*/, struct _SVector *location /*$s4*/, struct burntTuneType *burntTune /*$s0*/)
// line 3195, offset 0x8008c498
/* begin block 1 */
// Start line: 3196
// Start offset: 0x8008C498
// Variables:
// 		struct _Model *model; // $s1
// 		struct burntMessType bmt; // stack offset -80

/* begin block 1.1 */
// Start line: 3206
// Start offset: 0x8008C4FC
// Variables:
// 		struct _SVector localloc; // stack offset -64

/* begin block 1.1.1 */
// Start line: 3216
// Start offset: 0x8008C56C
// Variables:
// 		struct _MVertex *vertexList; // $s1
// 		struct _Vector locVec; // stack offset -56
// 		long flag; // stack offset -40
// 		struct MATRIX *segMatrix; // $s0
/* end block 1.1.1 */
// End offset: 0x8008C56C
// End Line: 3216
/* end block 1.1 */
// End offset: 0x8008C5F4
// End Line: 3237
/* end block 1 */
// End offset: 0x8008C5F4
// End Line: 3240

/* begin block 2 */
// Start line: 6822
/* end block 2 */
// End Line: 6823

int MONSTER_StartVertexBurnt(_Instance *instance, _SVector *location, burntTuneType *burntTune)

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
  undefined local_38[8];
  ushort local_30;
  undefined auStack40[8];

  model = instance->object->modelList[(int)instance->currentModel];
  if ((instance->perVertexColor == (CVECTOR *)0x0) &&
      (MONSTER_InitVertexColors(instance, model), instance->perVertexColor == (CVECTOR *)0x0))
  {
    return -1;
  }
  local_40 = *(undefined4 *)location;
  local_3c = *(uint *)&location->z;
  local_50 = -1;
  local_4c = 0x10000;
  local_48 = -1;
  local_44 = burntTune;
  MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBurntMess, &local_50);
  if (burntTune->burntDist >> 1 < local_4c)
  {
    p_Var2 = model->vertexList;
    pMVar1 = instance->matrix + local_48;
    SetRotMatrix((undefined4 *)pMVar1);
    SetTransMatrix((int)pMVar1);
    RotTrans(p_Var2 + local_50, local_38, auStack40);
    local_4c = 0;
    local_3c = local_3c & 0xffff0000 | (uint)local_30;
    FX_MakeHitFX((_SVector *)&local_40);
    MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBurntMess, &local_50);
  }
  else
  {
    FX_MakeHitFX((_SVector *)&local_40);
  }
  return local_50;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSTER_VertexBurnt(struct _Instance *instance /*$a0*/, struct burntTuneType *burntTune /*$a1*/)
// line 3242, offset 0x8008c618
/* begin block 1 */
// Start line: 3244
// Start offset: 0x8008C618
// Variables:
// 		int i; // $a3
// 		int fade; // $a2
// 		struct _Model *model; // $t0

/* begin block 1.1 */
// Start line: 3253
// Start offset: 0x8008C650
// Variables:
// 		struct CVECTOR *c; // $v1
/* end block 1.1 */
// End offset: 0x8008C6A4
// End Line: 3262
/* end block 1 */
// End offset: 0x8008C6BC
// End Line: 3265

/* begin block 2 */
// Start line: 6940
/* end block 2 */
// End Line: 6941

/* begin block 3 */
// Start line: 6941
/* end block 3 */
// End Line: 6942

/* begin block 4 */
// Start line: 6942
/* end block 4 */
// End Line: 6943

void MONSTER_VertexBurnt(_Instance *instance, burntTuneType *burntTune)

{
  char cVar1;
  CVECTOR *pCVar2;
  int iVar3;
  int iVar4;
  _Model *p_Var5;

  p_Var5 = instance->object->modelList[(int)instance->currentModel];
  iVar3 = burntTune->fadeDelta;
  if ((instance->perVertexColor != (CVECTOR *)0x0) && (iVar4 = 0, 0 < p_Var5->numVertices))
  {
    do
    {
      pCVar2 = instance->perVertexColor + iVar4;
      cVar1 = (char)iVar3;
      if (iVar3 <= (int)(uint)pCVar2->r)
      {
        pCVar2->r = pCVar2->r - cVar1;
      }
      if (iVar3 <= (int)(uint)pCVar2->g)
      {
        pCVar2->g = pCVar2->g - cVar1;
      }
      if (iVar3 <= (int)(uint)pCVar2->b)
      {
        pCVar2->b = pCVar2->b - cVar1;
      }
      pCVar2->cd = '\0';
      iVar4 = iVar4 + 1;
    } while (iVar4 < p_Var5->numVertices);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_DamageEffect(struct _Instance *instance /*$s2*/, struct evFXHitData *data /*$s0*/)
// line 3272, offset 0x8008c6c4
/* begin block 1 */
// Start line: 3273
// Start offset: 0x8008C6C4
// Variables:
// 		struct _SVector accel; // stack offset -104
// 		struct _MonsterVars *mv; // $s4

/* begin block 1.1 */
// Start line: 3289
// Start offset: 0x8008C720
// Variables:
// 		struct _MonsterAttributes *ma; // $s3

/* begin block 1.1.1 */
// Start line: 3293
// Start offset: 0x8008C740
// Variables:
// 		struct MATRIX *mat; // $s1
// 		struct _SVector location; // stack offset -96
// 		struct _SVector vel; // stack offset -88
// 		struct _SVector accel; // stack offset -80
/* end block 1.1.1 */
// End offset: 0x8008C81C
// End Line: 3308

/* begin block 1.1.2 */
// Start line: 3312
// Start offset: 0x8008C834
// Variables:
// 		struct MATRIX *mat; // $s0
// 		struct _SVector location; // stack offset -72
// 		struct _SVector vel; // stack offset -64
/* end block 1.1.2 */
// End offset: 0x8008C894
// End Line: 3321

/* begin block 1.1.3 */
// Start line: 3325
// Start offset: 0x8008C8A8
// Variables:
// 		struct Object *flame; // $v0

/* begin block 1.1.3.1 */
// Start line: 3332
// Start offset: 0x8008C8B8
// Variables:
// 		struct _Model *model; // $s0
/* end block 1.1.3.1 */
// End offset: 0x8008C910
// End Line: 3338
/* end block 1.1.3 */
// End offset: 0x8008C91C
// End Line: 3340

/* begin block 1.1.4 */
// Start line: 3345
// Start offset: 0x8008C95C
// Variables:
// 		struct MATRIX *mat; // $s0
// 		struct _SVector location; // stack offset -56
// 		struct _SVector vel; // stack offset -48
// 		struct _SVector accel; // stack offset -40
// 		int n; // $s1
// 		int cnt; // $s4
/* end block 1.1.4 */
// End offset: 0x8008CA5C
// End Line: 3364
/* end block 1.1 */
// End offset: 0x8008CA5C
// End Line: 3365
/* end block 1 */
// End offset: 0x8008CB04
// End Line: 3387

/* begin block 2 */
// Start line: 7012
/* end block 2 */
// End Line: 7013

/* WARNING: Type propagation algorithm not settling */

void MON_DamageEffect(_Instance *instance, evFXHitData *data)

{
  int amount;
  ulong uVar1;
  int lifetime;
  uint uVar2;
  evFXHitData *location;
  _Model *model;
  MATRIX *pMVar3;
  void *pvVar4;
  uint *puVar5;
  int iVar6;
  undefined4 local_68;
  undefined *local_64;
  _SVector local_60;
  _SVector local_58;
  undefined4 local_50;
  undefined4 local_4c;
  _SVector local_48;
  _SVector _Stack64;
  _SVector local_38;
  _SVector local_30;
  _SVector local_28;

  local_68 = DAT_800cf67c;
  local_64 = PTR_DAT_800cf680;
  puVar5 = (uint *)instance->extraData;
  if (data == (evFXHitData *)0x0)
  {
    pvVar4 = instance->data;
    if ((*puVar5 & 0x10000200) == 0x10000000)
    {
      amount = rand();
      local_50 = DAT_800cf684;
      local_4c = DAT_800cf688;
      pMVar3 = instance->matrix +
               amount % instance->object->modelList[(int)instance->currentModel]->numSegments;
      amount = rand();
      local_58.x = 4 - ((ushort)amount & 7);
      amount = rand();
      local_58.y = 4 - ((ushort)amount & 7);
      local_58.z = 0;
      local_60.x = *(short *)pMVar3->t;
      local_60.y = *(short *)(pMVar3->t + 1);
      local_60.z = *(short *)(pMVar3->t + 2);
      FX_Dot(&local_60, &local_58, (_SVector *)&local_50, 0, 0xff2828, 0x18, 0x10, 2);
    }
    if ((*puVar5 & 0x800010) == 0x800010)
    {
      pMVar3 = instance->matrix + (uint) * (byte *)((int)pvVar4 + 0x18);
      memset(&_Stack64, 0, 8);
      local_48.x = *(short *)pMVar3->t;
      local_48.y = *(short *)(pMVar3->t + 1);
      local_48.z = *(short *)(pMVar3->t + 2);
      FX_Blood(&local_48, &_Stack64, (_SVector *)&local_68, 4, (long)&DAT_001800d0, 8);
    }
    if ((*puVar5 & 0x400000) != 0)
    {
      if (ObjectAccess_800c87cc.object != (void *)0x0)
      {
        model = (_Model *)(*(_Model **)((int)ObjectAccess_800c87cc.object + 0xc))->numVertices;
        FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar4 + 0x1b));
        FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar4 + 0x1c));
        FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar4 + 0x1d));
        FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar4 + 0x1e));
        FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar4 + 0x1f));
      }
      MONSTER_VertexBurnt(instance, &burntTest);
    }
    if (*(char *)(puVar5 + 0x51) != '\x03')
    {
      return;
    }
    if ((*(uint *)((int)pvVar4 + 0x10) & 2) == 0)
    {
      return;
    }
    uVar1 = MON_GetTime(instance);
    if (puVar5[0x42] <= uVar1)
    {
      return;
    }
    MONSTER_VertexBurnt(instance, &burntTest);
    local_30.y = 0;
    local_30.x = 0;
    local_30.z = 0xc;
    local_28.y = 0;
    local_28.x = 0;
    local_28.z = 0;
    iVar6 = instance->object->modelList[(int)instance->currentModel]->numSegments;
    amount = 1;
    if (iVar6 < 2)
    {
      return;
    }
    do
    {
      pMVar3 = instance->matrix + amount;
      lifetime = rand();
      local_38.x = *(short *)pMVar3->t + ((ushort)lifetime & 3);
      lifetime = rand();
      local_38.y = *(short *)(pMVar3->t + 1) + ((ushort)lifetime & 3);
      lifetime = rand();
      local_38.z = *(short *)(pMVar3->t + 2) + ((ushort)lifetime & 3);
      uVar2 = rand();
      if ((uVar2 & 0x1f) == 0)
      {
        lifetime = 0x20;
      }
      else
      {
        lifetime = 2;
      }
      FX_Dot(&local_38, &local_30, &local_28, -0x100, 0x808080, 0x50, lifetime, 0);
      amount = amount + 1;
    } while (amount < iVar6);
    return;
  }
  if (data->type == 0x20)
  {
    location = data;
    if (data->amount == 0)
      goto LAB_8008ca94;
  }
  else
  {
    if (data->type != 0x10)
    {
      amount = MONSTER_CalcDamageIntensity((int)*(short *)(puVar5 + 0x4c), (int)*(short *)((int)puVar5 + 0x132));
      amount = MONSTER_StartVertexBlood(instance, (_SVector *)data, amount);
      *(short *)(puVar5 + 0x4e) = (short)amount;
      goto LAB_8008cad4;
    }
  LAB_8008ca94:
    location = (evFXHitData *)&instance->position;
  }
  MONSTER_StartVertexBurnt(instance, (_SVector *)location, &burntTest);
LAB_8008cad4:
  if ((int)data->amount != 0)
  {
    FX_Blood((_SVector *)data, &data->velocity, (_SVector *)&local_68, (int)data->amount,
             (long)&DAT_001800d0, 8);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_DefaultInit(struct _Instance *instance /*$s2*/)
// line 3392, offset 0x8008cb28
/* begin block 1 */
// Start line: 3393
// Start offset: 0x8008CB28
// Variables:
// 		struct _MonsterAttributes *ma; // $s1
// 		struct _MonsterVars *mv; // $s3
// 		struct _HModel *hModel; // $v0
// 		struct _HPrim *hprim; // $v0
// 		int i; // $a0
// 		int state; // $a1

/* begin block 1.1 */
// Start line: 3440
// Start offset: 0x8008CC84
// Variables:
// 		struct Level *level; // $s0
/* end block 1.1 */
// End offset: 0x8008CCEC
// End Line: 3448
/* end block 1 */
// End offset: 0x8008CD50
// End Line: 3466

/* begin block 2 */
// Start line: 7299
/* end block 2 */
// End Line: 7300

void MON_DefaultInit(_Instance *instance)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  _HModel *p_Var5;
  Level *pLVar6;
  long lVar7;
  byte *pbVar8;
  undefined4 local_18;
  undefined4 local_14;
  void *pvVar9;
  uint *puVar10;

  puVar10 = (uint *)instance->extraData;
  pvVar9 = instance->data;
  if ((*puVar10 & 0x1000000) != 0)
  {
    MONAPI_CheckGenerator(instance);
  }
  iVar3 = MON_OnGround(instance);
  if (iVar3 == 0)
  {
    uVar4 = *puVar10 & 0xfffffffd;
  }
  else
  {
    uVar4 = *puVar10 | 2;
  }
  *puVar10 = uVar4;
  if (instance->hModelList != (_HModel *)0x0)
  {
    p_Var5 = instance->hModelList + (int)instance->currentModel;
    iVar3 = p_Var5->numHPrims;
    if (iVar3 != 0)
    {
      pbVar8 = &p_Var5->hPrimList->withFlags;
      do
      {
        if (pbVar8[2] != 1)
        {
          *pbVar8 = *pbVar8 & 0xa5;
        }
        iVar3 = iVar3 + -1;
        pbVar8 = pbVar8 + 8;
      } while (iVar3 != 0);
    }
  }
  if (*(byte *)((int)pvVar9 + 0x1a) != 0)
  {
    G2Anim_AttachControllerToSeg(&instance->anim, (uint) * (byte *)((int)pvVar9 + 0x1a), 0xe);
    G2Anim_DisableController(&instance->anim, (uint) * (byte *)((int)pvVar9 + 0x1a), 0xe);
  }
  bVar1 = *(byte *)((int)pvVar9 + 0x22);
  if ((bVar1 != 0) && ((uint)bVar1 != (uint) * (byte *)((int)pvVar9 + 0x1a)))
  {
    G2Anim_AttachControllerToSeg(&instance->anim, (uint)bVar1, 0xe);
    G2Anim_DisableController(&instance->anim, (uint) * (byte *)((int)pvVar9 + 0x22), 0xe);
  }
  if ((instance->object->oflags & 0x80000U) == 0)
  {
    pLVar6 = STREAM_GetLevelWithID((theCamera.focusInstance)->currentStreamUnitID);
    lVar7 = MATH3D_LengthXYZ((int)(instance->position).x - (int)theCamera.core.position.x,
                             (int)(instance->position).y - (int)theCamera.core.position.y,
                             (int)(instance->position).z - (int)theCamera.core.position.z);
    if (lVar7 < (int)(uint)pLVar6->fogNear)
    {
      instance->fadeValue = 0x1000;
      MON_StartSpecialFade(instance, 0, 0x14);
    }
  }
  if (((((instance->flags & 2U) == 0) && (cVar2 = *(char *)((int)puVar10 + 0x146), cVar2 != '\x04')) && (cVar2 != '\x10')) && (cVar2 == '\r'))
  {
    *(undefined2 *)(puVar10 + 0x50) = 0;
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_CleanUp(struct _Instance *instance /*$s2*/)
// line 3472, offset 0x8008cd74
/* begin block 1 */
// Start line: 3473
// Start offset: 0x8008CD74
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterAttributes *ma; // $s1
/* end block 1 */
// End offset: 0x8008CE70
// End Line: 3515

/* begin block 2 */
// Start line: 7473
/* end block 2 */
// End Line: 7474

void MON_CleanUp(_Instance *instance)

{
  byte bVar1;
  ulong uVar2;
  void *pvVar3;
  void *pvVar4;

  pvVar3 = instance->extraData;
  pvVar4 = instance->data;
  MON_DropAllObjects(instance);
  if (instance->LinkParent != (_Instance *)0x0)
  {
    MON_UnlinkFromRaziel(instance);
  }
  if ((*(char *)((int)pvVar3 + 0x144) == '\x03') && (*(ulong *)((int)pvVar3 + 0xdc) != 0))
  {
    SndEndLoop(*(ulong *)((int)pvVar3 + 0xdc));
    *(undefined4 *)((int)pvVar3 + 0xdc) = 0;
  }
  if ((int)*(char *)((int)pvVar3 + 0x152) != -1)
  {
    ENMYPLAN_ReleasePlanningWorkspace((int)*(char *)((int)pvVar3 + 0x152));
  }
  if (*(byte *)((int)pvVar4 + 0x1a) != 0)
  {
    G2Anim_DetachControllerFromSeg(&instance->anim, (uint) * (byte *)((int)pvVar4 + 0x1a), 0xe);
  }
  bVar1 = *(byte *)((int)pvVar4 + 0x22);
  if ((bVar1 != 0) && ((uint)bVar1 != (uint) * (byte *)((int)pvVar4 + 0x1a)))
  {
    G2Anim_DetachControllerFromSeg(&instance->anim, (uint)bVar1, 0xe);
  }
  uVar2 = INSTANCE_Query(instance, 1);
  if ((uVar2 & 0xc000) != 0)
  {
    GlobalSave->humanOpinionOfRaziel = GlobalSave->humanOpinionOfRaziel + 1;
  }
  return;
}
