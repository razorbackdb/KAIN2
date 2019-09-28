#include "THISDUST.H"
#include "MONSTER.H"

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
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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

void MON_ChangeHumanOpinion(_Instance *param_1)

{
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(param_1, 1);
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

void MON_CutOut_Monster(int param_1, int param_2, int param_3, int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sStack56;
  short sStack54;
  short sStack52;
  _SVector _Stack48;
  short local_28;
  short local_26;
  short local_24;
  short local_20;
  short local_1e;
  short local_1c;
  undefined4 uStack24;

  if (*(int *)(param_1 + 0x40) != 0)
  {
    iVar3 = *(int *)(param_1 + 0x40) + param_3 * 0x20;
    iVar4 = *(int *)(param_1 + 0x40) + param_4 * 0x20;
    iVar1 = (int)*(short *)(iVar3 + 0x14) - (int)*(short *)(iVar4 + 0x14);
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 7;
    }
    iVar2 = (int)*(short *)(iVar3 + 0x18) - (int)*(short *)(iVar4 + 0x18);
    local_20 = (short)(iVar1 >> 3);
    local_28 = *(short *)(iVar3 + 0x14) + local_20;
    local_20 = *(short *)(iVar4 + 0x14) - local_20;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 7;
    }
    iVar1 = (int)*(short *)(iVar3 + 0x1c) - (int)*(short *)(iVar4 + 0x1c);
    local_1e = (short)(iVar2 >> 3);
    local_26 = *(short *)(iVar3 + 0x18) + local_1e;
    local_1e = *(short *)(iVar4 + 0x18) - local_1e;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 7;
    }
    local_1c = (short)(iVar1 >> 3);
    local_24 = *(short *)(iVar3 + 0x1c) + local_1c;
    local_1c = *(short *)(iVar4 + 0x1c) - local_1c;
    LoadAverageShort12((uint *)&local_20, (uint *)&local_28, param_2, 0x1000 - param_2,
                       (uint *)&sStack56);
    if ((*(ushort *)(param_1 + 0x11e) & 8) == 0)
    {
      uStack24 = 0;
      _Stack48.x = local_20 - local_28;
      _Stack48.y = local_1e - local_26;
      _Stack48.z = local_1c - local_24;
      /* WARNING: Subroutine does not return */
      CAMERA_Normalize(&_Stack48);
    }
    *(int *)(param_1 + 0x120) =
        -((int)*(short *)(param_1 + 0x118) * (int)sStack56 +
              (int)*(short *)(param_1 + 0x11a) * (int)sStack54 +
              (int)*(short *)(param_1 + 0x11c) * (int)sStack52 >>
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
  undefined4 local_10;
  uint *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;

  puVar1 = (uint *)instance->extraData;
  MON_TurnOffAllSpheres(instance);
  if (puVar1[0x31] != 0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)(puVar1[0x31] + 4), 1);
  }
  if (*(char *)((int)puVar1 + 0x145) == -1)
  {
    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
                 0x18);
  }
  *puVar1 = *puVar1 | 0x200;
  instance->flags2 = instance->flags2 & 0xfffdff3f;
  puVar1[0x3e] = 0;
  if (*(short *)(puVar1 + 0x4d) != 0)
  {
    if (puVar1[0x36] == 0)
    {
      MON_BirthSoul(instance, 1);
    }
    return;
  }
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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

void MON_Dead(_Instance *param_1)

{
  bool bVar1;
  int Data;
  __Event *p_Var2;
  undefined *puVar3;
  uint introUniqueID;
  void *pvVar4;
  int Message;
  _Instance *instance;
  uint *puVar5;
  _Instance *instance_00;
  _Instance *instance_01;
  undefined4 in_stack_ffffff90;
  undefined4 in_stack_ffffff94;
  undefined4 in_stack_ffffff98;
  undefined4 in_stack_ffffff9c;
  SVECTOR SStack96;
  SVECTOR SStack88;
  _PCollideInfo _Stack80;

  puVar5 = (uint *)param_1->extraData;
  instance_01 = (_Instance *)0x0;
  introUniqueID = puVar5[0x36];
  bVar1 = false;
  if (introUniqueID == 0)
  {
    if ((*puVar5 & 0x200) != 0)
    {
      /* WARNING: Subroutine does not return */
      MON_GetTime(param_1);
    }
    if ((param_1->flags2 & 0x10U) != 0)
    {
      MON_PlayCombatIdle(param_1, 2);
      /* WARNING: Subroutine does not return */
      MON_SwitchState(param_1, (MonsterState)CONCAT44(in_stack_ffffff94, in_stack_ffffff90));
    }
  }
  else
  {
    if (introUniqueID != 0x7fffffff)
    {
      instance_01 = INSTANCE_Find(introUniqueID);
    }
    if (instance_01 == (_Instance *)0x0)
    {
      MON_BirthSoul(param_1, 1);
    }
    else
    {
      if (*(int *)((int)instance_01->extraData + 0xd8) == 0)
      {
        *(long *)((int)instance_01->extraData + 0xd8) = param_1->introUniqueID;
      }
    }
  }
  if (*(char *)(puVar5 + 0x51) == '\x06')
  {
    MON_KillMonster(param_1);
  }
  else
  {
    if (((byte)(*(char *)(puVar5 + 0x51) - 1U) < 3) && (param_1->perVertexColor == (CVECTOR *)0x0))
    {
      /* WARNING: Subroutine does not return */
      MEMPACK_Malloc(param_1->object->modelList[param_1->currentModel]->numVertices << 2, '!');
    }
    if ((*(char *)(puVar5 + 0x51) == '\0') && (puVar5[0x34] == 0))
    {
      param_1->flags2 = param_1->flags2 | 0x80;
      instance_00 = (_Instance *)0x0;
      if (puVar5[0x35] == 0)
      {
        instance = *(_Instance **)(iGpffffb52c + 4);
        while (instance != (_Instance *)0x0)
        {
          if (((((param_1 != instance) && (instance->object != (Object *)0x0)) &&
                ((instance->object->oflags2 & 0x40000U) != 0)) &&
               (instance->LinkParent == (_Instance *)0x0)) &&
              ((Data = CheckPhysObFamily(instance, 0), Data != 0 ||
                                                           (Data = CheckPhysObFamily(instance, 3), Data != 0))))
          {
            /* WARNING: Subroutine does not return */
            MATH3D_LengthXYZ((int)(instance->position).x - (int)(param_1->position).x,
                             (int)(instance->position).y - (int)(param_1->position).y,
                             (int)(instance->position).z - (int)(param_1->position).z);
          }
          instance = instance->next;
        }
      }
      else
      {
        instance_00 = INSTANCE_Find(puVar5[0x35]);
      }
      if (instance_00 != (_Instance *)0x0)
      {
        Data = CheckPhysObFamily(instance_00, 3);
        if (Data == 0)
        {
          Data = SetObjectData(0, 0, 0, param_1, 3);
          Message = 0x800002;
        }
        else
        {
          Data = SetObjectBreakOffData(param_1, 3, 0, 0, 0, 0, 1);
          Message = 0x800023;
        }
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(instance_00, Message, Data);
      }
    }
    else
    {
      if (*(char *)(puVar5 + 0x51) == '\x03')
      {
        if (puVar5[0x37] != 0)
        {
          /* WARNING: Subroutine does not return */
          MON_GetTime(param_1);
        }
        if ((*puVar5 & 0x400) == 0)
        {
          SStack96.vx = (param_1->position).x;
          SStack96.vy = (param_1->position).y;
          SStack96.vz = (param_1->position).z;
          _Stack80.newPoint = &SStack96;
          _Stack80.oldPoint = &SStack88;
          uGpffffb638 = uGpffffb638 | 0x8000;
          SStack88.vz = (param_1->position).z + 0x200;
          SStack88.vx = SStack96.vx;
          SStack88.vy = SStack96.vy;
          PHYSICS_CheckLineInWorld(param_1, &_Stack80);
          uGpffffb638 = uGpffffb638 & 0xffff7fff;
          if (param_1->waterFace == (_TFace *)0x0)
          {
            bVar1 = true;
            *(undefined *)(puVar5 + 0x51) = 7;
          }
        }
        param_1->waterFace = (_TFace *)0x0;
      }
    }
  }
  if ((*puVar5 & 0x400000) != 0)
  {
    /* WARNING: Subroutine does not return */
    MON_GetTime(param_1);
  }
  if ((*puVar5 & 0x400) != 0)
  {
    Data = MON_OnGround(param_1);
    if (Data == 0)
    {
      introUniqueID = *puVar5 & 0xfffffffd;
    }
    else
    {
      introUniqueID = *puVar5 | 2;
    }
    *puVar5 = introUniqueID;
  }
  if ((*puVar5 & 2) == 0)
  {
    MON_MoveForward(param_1);
  }
  while (p_Var2 = DeMessageQueue((__MessageQueue *)(puVar5 + 2)), p_Var2 != (__Event *)0x0)
  {
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == (undefined *)0x100000d)
    {
      pvVar4 = param_1->data;
      if ((p_Var2->Data != 0) && ('\x02' < *(char *)((int)pvVar4 + 0x28)))
      {
        *(undefined *)((int)puVar5 + 0x14a) = 2;
        *puVar5 = *puVar5 | 0x10000000;
        puVar5[0x55] = *(uint *)(*(int *)((int)pvVar4 + 0x30) + 8);
      }
      *(undefined *)(puVar5 + 0x51) = 0;
      puVar5[0x36] = 0;
      *puVar5 = *puVar5 & 0xffdfdd7f;
      puVar5[1] = puVar5[1] & 0xb8080000;
      MON_TurnOnAllSpheres(param_1);
      MON_TurnOffWeaponSpheres(param_1);
      /* WARNING: Subroutine does not return */
      MON_PlayAnim(param_1, (MonsterAnim)CONCAT412(in_stack_ffffff9c, CONCAT48(in_stack_ffffff98, CONCAT44(in_stack_ffffff94, in_stack_ffffff90))), 0x17);
    }
    if ((int)puVar3 < 0x100000e)
    {
      if (puVar3 == (undefined *)0x100000b)
      {
        param_1->xAccl = 0;
        param_1->yAccl = 0;
        param_1->zAccl = -0x10;
      }
    }
    else
    {
      if (puVar3 == &DAT_0100001b)
      {
        puVar5[0x35] = 0;
        bVar1 = true;
      }
    }
  }
  if ((bVar1) && (puVar5[0x3e] == 0))
  {
    if ((instance_01 != (_Instance *)0x0) &&
        (param_1 = instance_01, (instance_01->flags2 & 0x8000000U) != 0))
    {
      MON_KillMonster(instance_01);
      /* WARNING: Subroutine does not return */
      INSTANCE_Query(instance_01, 1);
    }
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(param_1, 0x100000d, 0);
  }
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
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined8 in_stack_ffffffe8;

  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->xVel = 0;
  /* WARNING: Subroutine does not return */
  instance->yVel = 0;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_s1, CONCAT48(unaff_s0, in_stack_ffffffe8)), 0x19);
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
    /* WARNING: Subroutine does not return */
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

  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_fffffffc, unaff_retaddr));
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
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 9);
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
    /* WARNING: Subroutine does not return */
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
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  undefined8 uStackX0;

  if (*(char *)((int)instance->extraData + 0x145) == '\v')
  {
    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance, (MonsterAnim)CONCAT88(uStackX0, CONCAT44(unaff_retaddr, unaff_s0)), 0x15);
  }
  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT88(uStackX0, CONCAT44(unaff_retaddr, unaff_s0)), 0x12);
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
        if ((((*puVar1 & 0x400000) == 0) && (*(short *)(puVar1 + 0x4c) == 0)) &&
            (*(short *)(puVar1 + 0x50) != 0))
        {
          *puVar1 = *puVar1 & 0xfffffeff;
        }
      }
      else
      {
        *(undefined2 *)(puVar1 + 0x50) = 0x4000;
      }
    }
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  if ((*puVar1 & 0x400) != 0)
  {
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  if ((*puVar1 & 2) == 0)
  {
    MON_MoveForward(instance);
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

  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_fffffffc, unaff_retaddr));
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
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0xf);
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
  __Event *p_Var1;
  int iVar2;
  _Instance *instance_00;
  undefined4 local_18;
  undefined4 local_14;
  void *pvVar3;

  if ((instance->flags2 & 0x10U) == 0)
  {
    pvVar3 = instance->extraData;
    (instance->rotation).z = *(short *)(*(int *)(*(int *)((int)pvVar3 + 0xc4) + 4) + 0x78) + 0x800;
    while (true)
    {
      instance_00 = (_Instance *)((int)pvVar3 + 8);
      p_Var1 = DeMessageQueue((__MessageQueue *)instance_00);
      if (p_Var1 == (__Event *)0x0)
        break;
      iVar2 = p_Var1->ID;
      if (iVar2 == 0x1000003)
      {
        iVar2 = p_Var1->Data;
        INSTANCE_UnlinkFromParent(instance);
        MON_LaunchMonster(instance, (int)*(short *)(iVar2 + 8), (int)*(short *)(iVar2 + 0xc), 0x32);
      }
      else
      {
        if (iVar2 < 0x1000004)
        {
          if (iVar2 != 0x1000002)
          {
            MON_LandInWaterEntry(instance_00);
            return;
          }
        }
        else
        {
          if (iVar2 == 0x1000007)
          {
            if ((*(ushort *)(p_Var1->Data + 0xe) & 0x2000) != 0)
            {
              MON_UnlinkFromRaziel(instance);
            }
          }
          else
          {
            if (iVar2 != 0x100000b)
            {
              MON_LandInWaterEntry(instance_00);
              return;
            }
          }
        }
      }
    }
    if (instance->LinkParent == (_Instance *)0x0)
    {
      if ((instance->currentMainState == 0xe) && (*(short *)((int)pvVar3 + 0x110) != 0))
      {
        MON_TurnOnBodySpheres(instance);
        /* WARNING: Subroutine does not return */
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
      }
      (instance->rotation).x = 0;
      (instance->rotation).y = 0;
    }
    else
    {
      *(undefined2 *)((int)pvVar3 + 0x110) = 1;
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
  MonsterAnim in_stack_ffffffd8;

  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, in_stack_ffffffd8, 0x11);
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
    /* WARNING: Subroutine does not return */
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
  int mode;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;

  cVar1 = *(char *)((int)instance->extraData + 0x145);
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
  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
               mode);
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
  undefined4 local_18;
  undefined4 local_14;
  int iVar1;

  iVar1 = 4;
  if ((*(uint *)instance->extraData & 2) == 0)
  {
    if ((*(uint *)instance->extraData & 0x400) == 0)
    {
      MON_MoveForward(instance);
    }
    else
    {
      iVar1 = 0x12;
    }
  }
  else
  {
    iVar1 = 0xf;
  }
  if (iVar1 != 4)
  {
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  }
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  instance->xAccl = 0;
  instance->yAccl = 0;
  /* WARNING: Subroutine does not return */
  instance->zAccl = -8;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x10);
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
  __Event *message;
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar2;

  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 2) != 0)
  {
    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  MON_MoveForward(instance);
  while (true)
  {
    message = DeMessageQueue((__MessageQueue *)(puVar2 + 2));
    if (message == (__Event *)0x0)
    {
      if ((instance->currentMainState == 0x10) &&
          ((*(short *)(puVar2 + 0x50) == 0x20 || (*(short *)(puVar2 + 0x50) == 0x40))))
      {
        MON_BurnInAir(instance, 0xb);
      }
      return;
    }
    if (message->ID == 0x1000007)
      break;
    if (message->ID != 0x1000008)
    {
      MON_DefaultMessageHandler(instance, message);
    }
  }
  iVar1 = ratan2((int)*(short *)(message->Data + 6), (int)*(short *)(message->Data + 4));
  /* WARNING: Subroutine does not return */
  (instance->rotation).z = (short)iVar1 + 0x400;
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
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
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0xd);
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
  int iVar1;
  int iVar2;
  undefined4 local_18;
  void *pvVar3;
  undefined4 local_14;
  void *pvVar4;
  MonsterState in_stack_ffffffe0;

  pvVar3 = instance->extraData;
  pvVar4 = instance->data;
  iVar1 = MON_AnimPlaying(instance, (MonsterAnim)
                                        CONCAT412(local_14, CONCAT48(local_18, in_stack_ffffffe0)));
  if (iVar1 != 0)
  {
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
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    iVar1 = MON_AnimPlaying(instance, (MonsterAnim)
                                          CONCAT412(local_14, CONCAT48(local_18, in_stack_ffffffe0)));
    if ((iVar1 != 0) &&
        (iVar1 = **(int **)((int)pvVar3 + 0x154), *(char *)(iVar1 + 0xd) != *(char *)(iVar1 + 0x16)))
    {
      /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, in_stack_ffffffe0);
  }
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10))), mode);
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
  _Instance *p_Var1;
  __Event *p_Var2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  if ((*puVar3 & 0x200) == 0)
  {
    MON_MoveInstanceToImpalePoint(instance);
    if ((instance->flags2 & 0x10U) != 0)
    {
      if (puVar3[0x31] != 0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Query(*(_Instance **)(puVar3[0x31] + 4), 1);
      }
      *puVar3 = *puVar3 | 0x200;
      instance->flags2 = instance->flags2 & 0xffffffbf;
      if ((puVar3[0x36] == 0) && (*(short *)(puVar3 + 0x4d) != 0))
      {
        MON_BirthSoul(instance, 1);
      }
    }
  }
  else
  {
    if (puVar3[0x36] == 0)
    {
      /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
    p_Var1 = INSTANCE_Find(puVar3[0x36]);
    if (p_Var1 == (_Instance *)0x0)
    {
      MON_BirthSoul(instance, 1);
    }
    if ((*puVar3 & 0x400000) != 0)
    {
      /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
    do
    {
      p_Var2 = DeMessageQueue((__MessageQueue *)(puVar3 + 2));
    } while (p_Var2 != (__Event *)0x0);
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
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1a);
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
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_PlayCombatIdle(instance, 2);
  }
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  undefined4 unaff_s0;
  uint *puVar2;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_retaddr;

  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x40) == 0)
  {
    if ((*puVar2 & 0x100) != 0)
    {
      /* WARNING: Subroutine does not return */
      *puVar2 = *puVar2 | 0x10110;
      MON_GetTime(instance);
    }
    sVar1 = *(short *)(puVar2 + 0x50);
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
          MON_Surprised(instance);
          return;
        }
        mode = 5;
      }
    }
    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_retaddr, CONCAT48(unaff_s2, CONCAT44(unaff_s1, unaff_s0))),
                 mode);
  }
  *(ushort *)(puVar2[0x31] + 0x18) = *(ushort *)(puVar2[0x31] + 0x18) | 0x400;
  *puVar2 = *puVar2 | 0x810000;
  mode = MON_SetUpKnockBack(instance, *(_Instance **)(puVar2[0x31] + 4),
                            (evMonsterHitData *)puVar2[0x30]);
  if (mode != 0)
  {
    MON_Surprised(instance);
    return;
  }
  MON_Surprised(instance);
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
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  if ((instance->flags2 & 0x10U) == 0)
  {
    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  if ((*(uint *)instance->extraData & 0x100) == 0)
  {
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  }
  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 5);
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
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 4);
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
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_s3;

  if ((instance->flags2 & 0x10U) != 0)
  {
    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_s3, CONCAT48(unaff_s2, CONCAT44(unaff_s1, unaff_s0))), 0xe);
  }
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  uint uVar2;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;

  puVar3 = (uint *)instance->extraData;
  uVar2 = puVar3[0x31];
  *(ushort *)(uVar2 + 0x18) = *(ushort *)(uVar2 + 0x18) | 0x400;
  *puVar3 = *puVar3 | 0x10000;
  iVar1 = MON_SetUpKnockBack(instance, *(_Instance **)(uVar2 + 4), (evMonsterHitData *)puVar3[0x30]);
  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
               (uint)(iVar1 == 0));
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
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  void *pvVar1;

  pvVar1 = instance->extraData;
  *(undefined4 *)((int)pvVar1 + 0xf4) = 0x200000;
  MON_PlayAnimFromList(instance, (char *)(*(int *)((int)pvVar1 + 0xb8) + 0x1b), 0, 1);
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  undefined4 local_18;
  uint uVar4;
  undefined4 local_14;
  uint *puVar5;
  uint uVar6;

  puVar5 = (uint *)instance->extraData;
  uVar4 = puVar5[0x2e];
  uVar6 = puVar5[0x31];
  p_Var2 = MON_GetAnim(instance, (char *)(uVar4 + 0x1b), (int)*(char *)((int)puVar5 + 0x14b));
  if ((p_Var2->velocity != 0) && (iVar3 = MON_TransNodeAnimation(instance), iVar3 == 0))
  {
    *(ushort *)(puVar5 + 0x44) = p_Var2->velocity;
    MON_MoveForward(instance);
  }
  iVar3 = MON_AnimPlayingFromList(instance, (char *)(uVar4 + 0x1b), (int)*(char *)(uVar4 + 10));
  if ((iVar3 == 0) ||
      (iVar3 = G2EmulationInstanceQueryPassedFrame(instance, 0, (int)*(char *)(uVar4 + 9)), iVar3 == 0))
  {
    iVar3 = MON_AnimPlayingFromList(instance, (char *)(uVar4 + 0x1b), (int)*(char *)(uVar4 + 0xc));
    if ((iVar3 != 0) &&
        ((iVar3 = G2EmulationInstanceQueryPassedFrame(instance, 0, (int)*(char *)(uVar4 + 0xb)),
          iVar3 != 0 && ((*puVar5 & 0x4000) != 0))))
    {
      MON_TurnOffWeaponSpheres(instance);
      *(ushort *)(uVar6 + 0x18) = *(ushort *)(uVar6 + 0x18) | 0x200;
    }
  }
  else
  {
    MON_TurnOnWeaponSphere(instance, (int)*(char *)(uVar4 + 8));
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    instance->flags2 = instance->flags2 & 0xffffffef;
    cVar1 = *(char *)((int)puVar5 + 0x14b) + '\x01';
    *(char *)((int)puVar5 + 0x14b) = cVar1;
    if ((int)*(char *)(uVar4 + 0xe) <= (int)cVar1)
    {
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
    MON_PlayAnimFromList(instance, (char *)(uVar4 + 0x1b), (int)cVar1, 1);
  }
  if (uVar6 != 0)
  {
    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
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
  _MonsterAttackAttributes *attack;
  undefined4 local_18;
  uint *puVar1;
  undefined4 local_14;
  undefined4 local_10;
  int iVar2;
  undefined4 local_c;
  _MonsterIR *enemy;

  puVar1 = (uint *)instance->extraData;
  enemy = (_MonsterIR *)puVar1[0x31];
  if (((enemy != (_MonsterIR *)0x0) && ((*puVar1 & 4) == 0)) &&
      (((*puVar1 & 0x10000000) == 0 || ((enemy->mirFlags & 0x1000) == 0))))
  {
    reason = MON_ValidPosition(instance);
    if (reason == 0)
    {
      /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
    iVar2 = *(int *)(puVar1[0x55] + 8);
    *(_Position **)(puVar1 + 0x43) = &enemy->instance->position;
    reason = MON_ShouldIFlee(instance);
    if ((reason == 0) &&
        ((enemy->distance < *(short *)(iVar2 + 10) || (*(char *)((int)puVar1 + 0x146) == '\n'))))
    {
      if (((*puVar1 & 0x20000) != 0) && ((instance->flags2 & 0x12U) != 0))
      {
        *puVar1 = *puVar1 & 0xbffdffff;
      }
      reason = MON_ShouldIEvade(instance);
      if (reason == 0)
      {
        if ((*puVar1 & 0x40000000) == 0)
        {
          if (*(char *)((int)puVar1 + 0x146) == '\n')
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
            /* WARNING: Subroutine does not return */
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
          }
          if (reason == 2)
          {
            /* WARNING: Subroutine does not return */
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
          }
          if ((*puVar1 & 0x20000) == 0)
          {
            reason = MON_ChooseCombatMove(instance, reason);
            if (reason != 0)
            {
              /* WARNING: Subroutine does not return */
              MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14, local_18))), reason);
            }
            MON_PlayCombatIdle(instance, 2);
          }
        }
      }
      else
      {
        reason = MON_ChooseEvadeMove(instance);
        if (reason != 0)
        {
          /* WARNING: Subroutine does not return */
          MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14, local_18))),
                       reason);
        }
      }
      MON_TurnToPosition(instance, &enemy->instance->position, *(short *)(puVar1[0x55] + 0x1c));
      MON_IdleQueueHandler(instance);
      return;
    }
  }
  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
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
  if (puVar3[0x31] == 0)
  {
  LAB_8008a050:
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  }
  if ((instance->flags2 & 0x10U) == 0)
  {
    iVar2 = MON_AnimPlayingFromList(instance, missiledef->animList, (uint)missiledef->anim);
    if (((iVar2 != 0) &&
         (iVar2 = G2EmulationInstanceQueryPassedFrame(instance, 0, (uint)missiledef->frame), iVar2 != 0)) &&
        (MISSILE_FireAtInstance(instance, missiledef, *(_Instance **)(puVar3[0x31] + 4)),
         missiledef->reload != '\0'))
    {
      *puVar3 = *puVar3 & 0xffffffdf;
    }
    MON_TurnToPosition(instance, (_Position *)(*(int *)(puVar3[0x31] + 4) + 0x5c),
                       *(short *)(puVar3[0x55] + 0x1c));
  }
  else
  {
    cVar1 = *(char *)((int)puVar3 + 0x14b) + '\x01';
    *(char *)((int)puVar3 + 0x14b) = cVar1;
    if ((int)(uint)missiledef->numAnims <= (int)cVar1)
      goto LAB_8008a050;
    MON_PlayAnimFromList(instance, missiledef->animList, (int)cVar1, 1);
  }
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
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
  }
  else
  {
    if (((puVar3[1] & 0x10000000) != 0) &&
        (AngleMoveToward(&(instance->rotation).z, *(short *)((int)puVar3 + 0x116),
                         (short)((uint)(*(short *)(puVar3[0x55] + 0x1c) * DAT_800d11ec * 0x10) >>
                                 0x10)),
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
  int iVar1;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;

  puVar2 = (uint *)instance->extraData;
  if (puVar2[0x31] == 0)
  {
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  if ((((*puVar2 & 0x2000000) != 0) && (puVar2[0x33] != 0)) &&
      (*(short *)(puVar2[0x33] + 0x14) < *(short *)(puVar2[0x31] + 0x14)))
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(instance, 1);
  }
  if (*(short *)(puVar2[0x55] + 0x1a) < *(short *)(puVar2[0x31] + 0x14))
  {
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  iVar1 = MON_ValidPosition(instance);
  if (iVar1 == 0)
  {
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  angle = MATH3D_AngleFromPosToPos((_Position *)(*(int *)(puVar2[0x31] + 4) + 0x5c), &instance->position);
  angle = MONSENSE_GetClosestFreeDirection(instance, angle, 1000);
  AngleMoveToward(&(instance->rotation).z, angle, *(short *)(puVar2[0x55] + 0x22));
  MON_DefaultQueueHandler(instance);
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
  if ((uVar1 & 4) != 0)
  {
    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 3);
  }
  MON_GetPlanSlot(mv);
  MON_PlayCombatIdle(instance, 2);
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
  _MonsterAnim *p_Var2;
  Intro *pIVar3;
  _MonsterCombatAttributes *p_Var4;
  undefined4 local_20;
  undefined4 local_1c;
  _MonsterVars *mv;
  uint uVar5;
  _MonsterIR *target;
  int iVar6;
  long distance;

  distance = 0;
  mv = (_MonsterVars *)instance->extraData;
  target = (_MonsterIR *)0x0;
  uVar5 = 0;
  mv->lookAtPos = (_Position *)0x0;
  if ((mv->mvFlags & 4) != 0)
  {
    MON_GroundMoveQueueHandler(instance);
    return;
  }
  anim = MON_ValidPosition(instance);
  if (anim == 0)
  {
    uVar5 = 1;
    sVar1 = (mv->lastValidPos).z;
    *(undefined4 *)&mv->destination = *(undefined4 *)&mv->lastValidPos;
    (mv->destination).z = sVar1;
    mv->lookAtPos = &mv->destination;
  }
  else
  {
    if ((mv->behaviorState == '\a') && (pIVar3 = instance->intro, pIVar3 != (Intro *)0x0))
    {
      /* WARNING: Subroutine does not return */
      MATH3D_LengthXYZ((int)(instance->position).x - (int)(pIVar3->position).x,
                       (int)(instance->position).y - (int)(pIVar3->position).y,
                       (int)(instance->position).z - (int)(pIVar3->position).z);
    }
  }
  if (uVar5 != 1)
  {
    if (mv->enemy == (_MonsterIR *)0x0)
    {
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
    }
    if (((mv->mvFlags & 0x10000000) != 0) && ((mv->enemy->mirFlags & 0x1000) != 0))
    {
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
    }
    p_Var4 = mv->subAttr->combatAttributes;
    uVar5 = 2;
    if ((((mv->mvFlags & 0x2000000) == 0) || (target = mv->ally, target == (_MonsterIR *)0x0)) ||
        ((target->mirFlags & 0x200) != 0))
    {
      target = mv->enemy;
      distance = (int)p_Var4->combatRange + -200;
    }
    else
    {
      distance = (long)p_Var4->allyRange;
      uVar5 = 3;
    }
    if (target == (_MonsterIR *)0x0)
    {
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
    }
    anim = MON_ShouldIFireAtTarget(instance, target);
    if (anim != 0)
    {
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
    }
    sVar1 = (target->instance->position).z;
    *(undefined4 *)&mv->destination = *(undefined4 *)&target->instance->position;
    (mv->destination).z = sVar1;
    mv->lookAtPos = &mv->destination;
    anim = MON_ValidUnit(instance, target->instance->currentStreamUnitID);
    if (anim == 0)
    {
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
    }
    if ((mv->behaviorState == '\a') && (pIVar3 = instance->intro, pIVar3 != (Intro *)0x0))
    {
      /* WARNING: Subroutine does not return */
      MATH3D_LengthXYZ((int)(mv->destination).x - (int)(pIVar3->position).x,
                       (int)(mv->destination).y - (int)(pIVar3->position).y,
                       (int)(mv->destination).z - (int)(pIVar3->position).z);
    }
  }
  if (uVar5 == 0)
  {
    MON_DefaultQueueHandler(instance);
    return;
  }
  anim = MON_CheckPointSuitability(instance, &instance->position, &mv->destination);
  iVar6 = -1;
  if (anim == 0)
  {
    MON_GetPlanSlot(mv);
    MON_DefaultQueueHandler(instance);
    if (uVar5 != 1)
    {
      return;
    }
    mv->validUnits[0] = 0;
    return;
  }
  sVar1 = target->distance;
  p_Var2 = MON_GetAnim(instance, mv->subAttr->animList, 2);
  anim = 3;
  if ((int)sVar1 < (int)(distance + (uint)p_Var2->distance))
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
    if (uVar5 == 1)
    {
      mv->validUnits[0] = 0;
    }
    break;
  case 3:
  switchD_8008a980_caseD_3:
    iVar6 = 2;
    goto LAB_8008a9f0;
  case 4:
    if (uVar5 == 2)
    {
      iVar6 = 0xd;
      goto LAB_8008a9f0;
    }
    if (uVar5 < 3)
    {
      if (uVar5 != 1)
        goto LAB_8008a9f0;
      goto switchD_8008a980_caseD_3;
    }
    if (uVar5 != 3)
      goto LAB_8008a9f0;
  }
  MON_GetPlanSlot(mv);
LAB_8008a9f0:
  if (iVar6 == -1)
  {
    return;
  }
  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
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
  undefined4 local_10;
  _MonsterVars *mv;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;

  mv = (_MonsterVars *)instance->extraData;
  uVar1 = mv->mvFlags;
  mv->mvFlags = uVar1 | 0x11000;
  if ((uVar1 & 4) != 0)
  {
    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
                 2);
  }
  MON_GetPlanSlot(mv);
  iVar2 = MON_AnimPlaying(instance, (MonsterAnim)
                                        CONCAT412(in_stack_fffffffc,
                                                  CONCAT48(local_8, CONCAT44(local_c, local_10))));
  if (iVar2 == 0)
  {
    MON_PlayRandomIdle(instance, 2);
  }
  mv->mvFlags = mv->mvFlags & 0xfffdffff;
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  if ((*puVar3 & 4) != 0)
  {
    MON_TurnToPosition(instance, (_Position *)((int)puVar3 + 0x112), *(short *)(puVar3[0x55] + 0x1e));
    /* WARNING: Subroutine does not return */
    MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)((int)puVar3 + 0x112),
                     (int)(instance->position).y - (int)*(short *)(puVar3 + 0x45),
                     (int)(instance->position).z - (int)*(short *)((int)puVar3 + 0x116));
  }
  if ((*puVar3 & 0x40000) == 0)
  {
    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  iVar1 = MON_DefaultPlanMovement(instance, 2, 100);
  iVar2 = -1;
  switch (iVar1)
  {
  case 2:
  case 3:
    iVar2 = 2;
    break;
  case 4:
    iVar2 = 0x14;
    if (*(char *)((int)puVar3 + 0x146) != '\x04')
    {
      /* WARNING: Subroutine does not return */
      rand();
    }
  }
  if (iVar2 != -1)
  {
    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  }
  if (puVar3[0x31] != 0)
  {
    iVar1 = MON_ShouldIFlee(instance);
    if (iVar1 != 0)
    {
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
    puVar3[0x43] = *(int *)(puVar3[0x31] + 4) + 0x5c;
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
  if (((*puVar2 & 4) == 0) && (uVar3 != 0))
  {
    bVar1 = *(byte *)((int)puVar2 + 0x146);
    if (bVar1 == 8)
    {
      if (((*puVar2 & 0x40000000) == 0) && (mode = MON_ShouldIAmbushEnemy(instance), mode != 0))
      {
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
          /* WARNING: Subroutine does not return */
          MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10))), mode);
        }
        MON_TurnToPosition(instance, (_Position *)(*(int *)(uVar3 + 4) + 0x5c), 0x1000);
        goto LAB_8008aea8;
      }
    }
    else
    {
      if ((8 < bVar1) || (bVar1 != 4))
      {
      LAB_8008aea8:
        /* WARNING: Subroutine does not return */
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
      }
      MON_ChangeBehavior(instance, (uint) * (byte *)(puVar2 + 0x52));
    }
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    if ((*puVar2 & 0x40000000) != 0)
    {
      /* WARNING: Subroutine does not return */
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
    MON_PlayRandomIdle(instance, 1);
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

void MON_MonsterGlow(_Instance *param_1, long param_2, int param_3, int param_4, int param_5)

{
  _FXGlowEffect *p_Var1;
  short sVar2;
  short sVar3;
  void *pvVar4;
  short sVar5;
  long local_res4[3];

  sVar3 = (short)param_4;
  sVar2 = (short)param_3;
  sVar5 = (short)param_5;
  pvVar4 = param_1->data;
  if (0 < param_3)
  {
    sVar2 = sVar2 * 0x21;
  }
  if (0 < param_5)
  {
    sVar5 = sVar5 * 0x21;
  }
  if (0 < param_4)
  {
    sVar3 = sVar3 * 0x21;
  }
  local_res4[0] = param_2;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(param_1, (uint) * (byte *)((int)pvVar4 + 0x1d),
                                       (uint) * (byte *)((int)pvVar4 + 0x20), local_res4, 1, 0x400, 0xa0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(param_1, (uint) * (byte *)((int)pvVar4 + 0x1d),
                                       (uint) * (byte *)((int)pvVar4 + 0x21), local_res4, 1, 0x400, 0xa0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(param_1, (uint) * (byte *)((int)pvVar4 + 0x1b),
                                       (uint) * (byte *)((int)pvVar4 + 0x23), local_res4, 1, 0x400, 0x80);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(param_1, (uint) * (byte *)((int)pvVar4 + 0x1c),
                                       (uint) * (byte *)((int)pvVar4 + 0x24), local_res4, 1, 0x400, 0x80);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceTwoSegmentGlow(param_1, (uint) * (byte *)((int)pvVar4 + 0x19),
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

void MON_SurpriseAttack(_Instance *instance)

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
    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))), mode);
  }
  if (uVar1 < 0x21)
  {
    if (uVar1 == 0x10)
    {
      puVar6 = &DAT_00002710;
      uVar2 = SOUND_Play3dSound(&instance->position, 0x23, 600, 0x50, (int)&DAT_00002710);
      /* WARNING: Subroutine does not return */
      puVar4[0x37] = uVar2;
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, puVar6))), 0x1b);
    }
  }
  else
  {
    if (uVar1 == 0x40)
      goto LAB_8008b270;
    if (uVar1 == 0x400)
    {
      /* WARNING: Subroutine does not return */
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))), 0x24);
    }
  }
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
  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))),
               mode);
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
  uint uVar3;
  __Event *p_Var4;
  undefined4 local_18;
  uint *puVar5;
  undefined4 local_14;
  undefined4 unaff_s2;
  undefined4 unaff_s3;

  puVar5 = (uint *)instance->extraData;
  bVar1 = false;
  if ((((instance->flags2 & 0x10U) == 0) ||
       (iVar2 = MON_AnimPlaying(instance, (MonsterAnim)
                                              CONCAT412(unaff_s3, CONCAT48(unaff_s2, CONCAT44(local_14,
                                                                                              local_18)))),
        iVar2 == 0)) &&
      (*(char *)(puVar5 + 0x51) != '\x06'))
  {
    if ((instance->flags2 & 0x12U) != 0)
    {
      /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
  }
  else
  {
    bVar1 = true;
  }
  if (!bVar1)
  {
    if ((*puVar5 & 0x400) != 0)
    {
      iVar2 = MON_OnGround(instance);
      if (iVar2 == 0)
      {
        uVar3 = *puVar5 & 0xfffffffd;
      }
      else
      {
        uVar3 = *puVar5 | 2;
      }
      *puVar5 = uVar3;
    }
    if ((*puVar5 & 2) == 0)
    {
      MON_MoveForward(instance);
    }
    while (p_Var4 = DeMessageQueue((__MessageQueue *)(puVar5 + 2)), p_Var4 != (__Event *)0x0)
    {
      if (p_Var4->ID == 0x100000b)
      {
        instance->xAccl = 0;
        instance->yAccl = 0;
        instance->zAccl = -0x10;
      }
    }
    return;
  }
  *puVar5 = *puVar5 & 0xffffffef;
  G2Anim_SetNoLooping(&instance->anim);
  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
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
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  if ((*(int *)((int)instance->extraData + 4) < 0) &&
      (*(int *)(*(int *)(*(int *)((int)instance->extraData + 0x154) + 0xc) + 4) != 0))
  {
    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x2a);
  }
  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1d);
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
    /* WARNING: Subroutine does not return */
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
  instance->flags = instance->flags | 0x800;
  /* WARNING: Subroutine does not return */
  instance->flags2 = instance->flags2 | 0x20000000;
  MON_GetTime(instance);
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

/* WARNING: Removing unreachable block (ram,0x8008b8b4) */
/* WARNING: Removing unreachable block (ram,0x8008b8dc) */
/* WARNING: Removing unreachable block (ram,0x8008b8f0) */
/* WARNING: Removing unreachable block (ram,0x8008b988) */

void MON_Pupate(_Instance *instance)

{
  bool bVar1;
  Intro *pIVar2;
  int iVar3;
  undefined4 local_28;
  void *pvVar4;
  undefined4 local_24;
  int iVar5;
  uint *puVar6;
  DEBUG_LINE_TYPE DVar7;
  undefined8 in_stack_ffffffd0;

  puVar6 = (uint *)instance->extraData;
  DVar7 = DEBUG_LINE_TYPE_BIT;
  if ((instance->flags & 0x800U) == 0)
  {
    MON_DefaultQueueHandler(instance);
    if (puVar6[0x31] != 0)
    {
      MON_TurnToPosition(instance, (_Position *)(*(int *)(puVar6[0x31] + 4) + 0x5c),
                         *(short *)(puVar6[0x55] + 0x1c));
    }
    if ((instance->flags2 & 0x10U) != 0)
    {
      MON_ChangeBehavior(instance, (uint) * (byte *)(puVar6 + 0x52));
    }
  }
  else
  {
    pvVar4 = instance->data;
    bVar1 = false;
    MON_PupateQueueHandler(instance);
    iVar3 = (int)*(char *)((int)pvVar4 + 0x17);
    if (iVar3 != -1)
    {
      iVar5 = *(int *)(DAT_800d0fe0 + 4);
      DVar7 = (&DebugMenuLine_800c8780.type)[(uint) * (byte *)((int)&_Normal_800ca9ec.x + iVar3) * 2];
      while (iVar5 != 0)
      {
        if ((*(DEBUG_LINE_TYPE *)(iVar5 + 0x1c) == DVar7) && ((*(uint *)(iVar5 + 0x14) & 0x20) == 0))
        {
          pIVar2 = instance->intro;
          /* WARNING: Subroutine does not return */
          MATH3D_LengthXYZ((int)*(short *)(iVar5 + 0x5c) - (int)(pIVar2->position).x,
                           (int)*(short *)(iVar5 + 0x5e) - (int)(pIVar2->position).y,
                           (int)*(short *)(iVar5 + 0x60) - (int)(pIVar2->position).z);
        }
        iVar5 = *(int *)(iVar5 + 8);
      }
    }
    if (instance->currentMainState == 0x1a)
    {
      if (DVar7 == DEBUG_LINE_TYPE_BIT)
      {
        iVar3 = MON_ShouldIAmbushEnemy(instance);
        if (iVar3 != 0)
        {
          /* WARNING: Subroutine does not return */
          MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_24, CONCAT48(local_28, in_stack_ffffffd0)), 0x1c);
        }
      }
      else
      {
        *(undefined2 *)((int)puVar6 + 0x136) = 0;
        MON_KillMonster(instance);
      }
    }
    else
    {
      bVar1 = true;
    }
    if (bVar1)
    {
      instance->flags = instance->flags & 0xfffff7ff;
      instance->flags2 = instance->flags2 & 0xdfffffff;
      *puVar6 = *puVar6 & 0xffffff7f;
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
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;

  /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1e);
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
  undefined4 unaff_s0;
  uint *puVar1;
  undefined4 unaff_s1;
  uint uVar2;

  puVar1 = (uint *)instance->extraData;
  uVar2 = puVar1[0x31];
  if ((((uVar2 != 0) && (*(short *)(uVar2 + 0x14) <= *(short *)(*(int *)(puVar1[0x55] + 8) + 0x18))) && ((*(uint *)(uVar2 + 0x14) & 0x10200000) == 0x10200000)) && ((*puVar1 & 4) == 0))
  {
    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
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
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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

void MON_Embrace(_Instance *instance)

{
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
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
  int iVar1;
  short *psVar2;
  _Model *p_Var3;
  MATRIX MStack80;

  p_Var3 = instance->object->modelList[instance->currentModel];
  iVar1 = 1;
  if (1 < p_Var3->numSegments)
  {
    psVar2 = &p_Var3->segmentList[1].firstVertex;
    do
    {
      if (psVar2[1] != -1)
      {
        PIPE3D_InvertTransform(&MStack80, instance->matrix + iVar1);
        SetRotMatrix((undefined4 *)&MStack80);
        /* WARNING: Subroutine does not return */
        SetTransMatrix((int)&MStack80);
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0xc;
    } while (iVar1 < p_Var3->numSegments);
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
  /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(model->numVertices << 2, '!');
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
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;

  if ((instance->perVertexColor == (CVECTOR *)0x0) &&
      (MONSTER_InitVertexColors(instance, instance->object->modelList[instance->currentModel]),
       instance->perVertexColor == (CVECTOR *)0x0))
  {
    return -1;
  }
  local_40 = *(undefined4 *)location;
  local_3c = *(undefined4 *)&location->z;
  local_58 = -1;
  local_54 = 0x10000;
  local_50 = -1;
  local_4c = 0;
  local_48 = amount;
  MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBloodyMess, &local_58);
  if (local_54 < 0x33)
  {
    FX_MakeHitFX((_SVector *)&local_40);
    return local_58;
  }
  pMVar1 = instance->matrix + local_50;
  SetRotMatrix((undefined4 *)pMVar1);
  /* WARNING: Subroutine does not return */
  SetTransMatrix((int)pMVar1);
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

void MONSTER_VertexBlood(int param_1, int param_2, int param_3)

{
  int iVar1;
  char *address;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint *puVar5;

  address = *(char **)(param_1 + 0x264);
  if (address == (char *)0x0)
  {
    return;
  }
  pbVar4 = (byte *)(address + param_2 * 4);
  if (param_3 == 0)
  {
    /* WARNING: Subroutine does not return */
    MEMPACK_Free(address);
  }
  uVar3 = (uint)pbVar4[1];
  iVar1 = *(int *)(param_1 + 0x14c);
  if ((uint)*pbVar4 < uVar3)
  {
    if ((uint)*pbVar4 < (uint)pbVar4[2])
    {
      uVar3 = (uint)*pbVar4;
      uVar2 = (uint) * (byte *)(*(int *)(iVar1 + 0x154) + 0x3f);
      goto LAB_8008c2e4;
    }
  }
  else
  {
    if (uVar3 < pbVar4[2])
    {
      uVar2 = (uint) * (byte *)(*(int *)(iVar1 + 0x154) + 0x40);
      goto LAB_8008c2e4;
    }
  }
  uVar3 = (uint)pbVar4[2];
  uVar2 = (uint) * (byte *)(*(int *)(iVar1 + 0x154) + 0x41);
LAB_8008c2e4:
  if ((pbVar4[3] == 1) && ((int)uVar3<(int)((0x100 - param_3) * (0xff - uVar2))>> 8))
  {
    iVar1 = **(int **)((int)*(short *)(param_1 + 0x10a) * 4 +
                       *(int *)(*(int *)(param_1 + 0x1c) + 0xc));
    puVar5 = *(uint **)(param_1 + 0x264);
    if (iVar1 != 0)
    {
      pbVar4 = (byte *)((int)puVar5 + 3);
      do
      {
        if (*pbVar4 == 1)
        {
          if ((uint) * (byte *)puVar5 + 8 < 0x100)
          {
            *(byte *)puVar5 = (byte)((uint) * (byte *)puVar5 + 8);
          }
          else
          {
            *(byte *)puVar5 = 0xff;
          }
          if ((uint)pbVar4[-2] + 8 < 0x100)
          {
            pbVar4[-2] = (byte)((uint)pbVar4[-2] + 8);
          }
          else
          {
            pbVar4[-2] = 0xff;
          }
          if ((uint)pbVar4[-1] + 8 < 0x100)
          {
            pbVar4[-1] = (byte)((uint)pbVar4[-1] + 8);
          }
          else
          {
            pbVar4[-1] = 0xff;
          }
          if ((*puVar5 & 0xffffff) == 0xffffff)
          {
            *pbVar4 = 0;
          }
        }
        iVar1 = iVar1 + -1;
        pbVar4 = pbVar4 + 4;
        puVar5 = puVar5 + 1;
      } while (iVar1 != 0);
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
  int local_50;
  int local_4c;
  int local_48;
  burntTuneType *local_44;
  undefined4 local_40;
  undefined4 local_3c;

  if ((instance->perVertexColor == (CVECTOR *)0x0) &&
      (MONSTER_InitVertexColors(instance, instance->object->modelList[instance->currentModel]),
       instance->perVertexColor == (CVECTOR *)0x0))
  {
    return -1;
  }
  local_40 = *(undefined4 *)location;
  local_3c = *(undefined4 *)&location->z;
  local_50 = -1;
  local_4c = 0x10000;
  local_48 = -1;
  local_44 = burntTune;
  MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBurntMess, &local_50);
  if (local_4c <= burntTune->burntDist >> 1)
  {
    FX_MakeHitFX((_SVector *)&local_40);
    return local_50;
  }
  pMVar1 = instance->matrix + local_48;
  SetRotMatrix((undefined4 *)pMVar1);
  /* WARNING: Subroutine does not return */
  SetTransMatrix((int)pMVar1);
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

  p_Var5 = instance->object->modelList[instance->currentModel];
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
  evFXHitData *location;
  _Model *model;
  void *pvVar1;
  uint *puVar2;
  undefined4 local_68;
  undefined *local_64;
  undefined auStack64[32];

  local_68 = DAT_800cf67c;
  local_64 = PTR_DAT_800cf680;
  puVar2 = (uint *)instance->extraData;
  if (data == (evFXHitData *)0x0)
  {
    pvVar1 = instance->data;
    if ((*puVar2 & 0x10000200) == 0x10000000)
    {
      /* WARNING: Subroutine does not return */
      rand();
    }
    if ((*puVar2 & 0x800010) != 0x800010)
    {
      if ((*puVar2 & 0x400000) != 0)
      {
        if (DebugMenuLine_800c87c8.upper != 0)
        {
          model = (_Model *)(*(_Model **)(DebugMenuLine_800c87c8.upper + 0xc))->numVertices;
          FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar1 + 0x1b));
          FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar1 + 0x1c));
          FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar1 + 0x1d));
          FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar1 + 0x1e));
          FX_MakeSpark(instance, model, (uint) * (byte *)((int)pvVar1 + 0x1f));
        }
        MONSTER_VertexBurnt(instance, &burntTest);
      }
      if (*(char *)(puVar2 + 0x51) != '\x03')
      {
        return;
      }
      if ((*(uint *)((int)pvVar1 + 0x10) & 2) == 0)
      {
        return;
      }
      /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
    /* WARNING: Subroutine does not return */
    memset(auStack64, 0, 8);
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
      amount = MONSTER_CalcDamageIntensity((int)*(short *)(puVar2 + 0x4c), (int)*(short *)((int)puVar2 + 0x132));
      amount = MONSTER_StartVertexBlood(instance, (_SVector *)data, amount);
      *(short *)(puVar2 + 0x4e) = (short)amount;
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
  byte *pbVar6;
  undefined4 local_18;
  undefined4 local_14;
  void *pvVar7;
  uint *puVar8;

  puVar8 = (uint *)instance->extraData;
  pvVar7 = instance->data;
  if ((*puVar8 & 0x1000000) != 0)
  {
    MONAPI_CheckGenerator(instance);
  }
  iVar3 = MON_OnGround(instance);
  if (iVar3 == 0)
  {
    uVar4 = *puVar8 & 0xfffffffd;
  }
  else
  {
    uVar4 = *puVar8 | 2;
  }
  *puVar8 = uVar4;
  if (instance->hModelList != (_HModel *)0x0)
  {
    p_Var5 = instance->hModelList + instance->currentModel;
    iVar3 = p_Var5->numHPrims;
    if (iVar3 != 0)
    {
      pbVar6 = &p_Var5->hPrimList->withFlags;
      do
      {
        if (pbVar6[2] != 1)
        {
          *pbVar6 = *pbVar6 & 0xa5;
        }
        iVar3 = iVar3 + -1;
        pbVar6 = pbVar6 + 8;
      } while (iVar3 != 0);
    }
  }
  if (*(byte *)((int)pvVar7 + 0x1a) != 0)
  {
    G2Anim_AttachControllerToSeg(&instance->anim, (uint) * (byte *)((int)pvVar7 + 0x1a), 0xe);
    G2Anim_DisableController(&instance->anim, (uint) * (byte *)((int)pvVar7 + 0x1a), 0xe);
  }
  bVar1 = *(byte *)((int)pvVar7 + 0x22);
  if ((bVar1 != 0) && ((uint)bVar1 != (uint) * (byte *)((int)pvVar7 + 0x1a)))
  {
    G2Anim_AttachControllerToSeg(&instance->anim, (uint)bVar1, 0xe);
    G2Anim_DisableController(&instance->anim, (uint) * (byte *)((int)pvVar7 + 0x22), 0xe);
  }
  if ((instance->object->oflags & 0x80000U) == 0)
  {
    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(*(long *)(DAT_800cff98 + 0x38));
  }
  if (((((instance->flags & 2U) == 0) && (cVar2 = *(char *)((int)puVar8 + 0x146), cVar2 != '\x04')) && (cVar2 != '\x10')) && (cVar2 == '\r'))
  {
    *(undefined2 *)(puVar8 + 0x50) = 0;
  }
  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
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
  void *pvVar2;
  void *pvVar3;

  pvVar2 = instance->extraData;
  pvVar3 = instance->data;
  MON_DropAllObjects(instance);
  if (instance->LinkParent != (_Instance *)0x0)
  {
    MON_UnlinkFromRaziel(instance);
  }
  if ((*(char *)((int)pvVar2 + 0x144) == '\x03') && (*(ulong *)((int)pvVar2 + 0xdc) != 0))
  {
    /* WARNING: Subroutine does not return */
    SndEndLoop(*(ulong *)((int)pvVar2 + 0xdc));
  }
  if ((int)*(char *)((int)pvVar2 + 0x152) != -1)
  {
    ENMYPLAN_ReleasePlanningWorkspace((int)*(char *)((int)pvVar2 + 0x152));
  }
  if (*(byte *)((int)pvVar3 + 0x1a) != 0)
  {
    G2Anim_DetachControllerFromSeg(&instance->anim, (uint) * (byte *)((int)pvVar3 + 0x1a), 0xe);
  }
  bVar1 = *(byte *)((int)pvVar3 + 0x22);
  if ((bVar1 != 0) && ((uint)bVar1 != (uint) * (byte *)((int)pvVar3 + 0x1a)))
  {
    G2Anim_DetachControllerFromSeg(&instance->anim, (uint)bVar1, 0xe);
  }
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(instance, 1);
}
