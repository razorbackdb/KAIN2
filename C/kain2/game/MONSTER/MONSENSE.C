#include "THISDUST.H"
#include "MONSENSE.H"

// int @0x800CF634, len = 0x00000004
gNumMaterialMonsters = 0x0;
// int @0x800CF62C, len = 0x00000004
gNumMonsters = 0x0;
// int @0x800CF630, len = 0x00000004
gNumSpectralMonsters = 0x0;
// int @0x800D49C8, len = 0x00000004
lastSenseFrame = null;
// _MonsterVars * @0x800D4900, len = 0x00000004
monsterSenseArray40 = null;
// char @0x800D49A0, len = 0x00000001
monsterSensed = 0x00;
// RadarInfo @0x800CF638, len = 0x00000006
radarDir =
    {
        // short @0x800CF638, len = 0x00000002
        .angle = 0x0,
        // short @0x800CF63A, len = 0x00000002
        .x = 0x0,
        // short @0x800CF63C, len = 0x00000002
        .y = -0x500};
// uchar @0x800CF668, len = 0x00000001
radarDirIndex = 0x00;
// decompiled code
// original method signature:
// struct _MonsterIR * /*$ra*/ MONSENSE_FindIR(struct _MonsterVars *mv /*$a0*/, struct _Instance *instance /*$a1*/)
// line 64, offset 0x80085aa4
/* begin block 1 */
// Start line: 66
// Start offset: 0x80085AA4
// Variables:
// 		struct _MonsterIR *mir; // $v1
/* end block 1 */
// End offset: 0x80085AD4
// End Line: 72

/* begin block 2 */
// Start line: 114
/* end block 2 */
// End Line: 115

/* begin block 3 */
// Start line: 128
/* end block 3 */
// End Line: 129

/* begin block 4 */
// Start line: 115
/* end block 4 */
// End Line: 116

/* begin block 5 */
// Start line: 117
/* end block 5 */
// End Line: 118

_MonsterIR *MONSENSE_FindIR(_MonsterVars *mv, _Instance *instance)

{
  _MonsterIR *p_Var1;

  p_Var1 = mv->monsterIRList;
  while ((p_Var1 != (_MonsterIR *)0x0 && (p_Var1->instance != instance)))
  {
    p_Var1 = p_Var1->next;
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// int /*$ra*/ MONSENSE_See(struct _Instance *instance /*$s2*/, struct evCollideInstanceStatsData *data /*$s1*/)
// line 97, offset 0x80085adc
/* begin block 1 */
// Start line: 98
// Start offset: 0x80085ADC
// Variables:
// 		struct _MonsterVars *mv; // $v0
// 		struct _MonsterSenses *senses; // $s0

/* begin block 1.1 */
// Start line: 104
// Start offset: 0x80085B20
// Variables:
// 		int arc; // $a1
// 		int elevation; // $a2

/* begin block 1.1.1 */
// Start line: 114
// Start offset: 0x80085B70
// Variables:
// 		struct _Instance *target; // $s0

/* begin block 1.1.1.1 */
// Start line: 118
// Start offset: 0x80085B88
// Variables:
// 		struct evPhysicsLOSData losData; // stack offset -40

/* begin block 1.1.1.1.1 */
// Start line: 122
// Start offset: 0x80085B98
// Variables:
// 		struct MATRIX *mat; // $v0
/* end block 1.1.1.1.1 */
// End offset: 0x80085B98
// End Line: 122

/* begin block 1.1.1.1.2 */
// Start line: 128
// Start offset: 0x80085BD4
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $a1
// 		struct _Position *_v0; // $v0
// 		struct _Position *_v1; // $v0
/* end block 1.1.1.1.2 */
// End offset: 0x80085BF0
// End Line: 128

/* begin block 1.1.1.1.3 */
// Start line: 132
// Start offset: 0x80085C00
// Variables:
// 		struct MATRIX *mat; // $v1
/* end block 1.1.1.1.3 */
// End offset: 0x80085C00
// End Line: 132

/* begin block 1.1.1.1.4 */
// Start line: 138
// Start offset: 0x80085C24
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $a1
// 		struct _Position *_v0; // $v0
// 		struct _Position *_v1; // $v0
/* end block 1.1.1.1.4 */
// End offset: 0x80085C44
// End Line: 138
/* end block 1.1.1.1 */
// End offset: 0x80085C5C
// End Line: 141
/* end block 1.1.1 */
// End offset: 0x80085C5C
// End Line: 144
/* end block 1.1 */
// End offset: 0x80085C5C
// End Line: 145
/* end block 1 */
// End offset: 0x80085C60
// End Line: 148

/* begin block 2 */
// Start line: 194
/* end block 2 */
// End Line: 195

int MONSENSE_See(_Instance *instance, evCollideInstanceStatsData *data)

{
  short sVar1;
  int arc;
  ulong uVar2;
  MATRIX *pMVar3;
  int elevation;
  short *psVar4;
  _Instance *Inst;
  short local_28;
  short local_26;
  short local_24;
  short local_20;
  short local_1e;
  short local_1c;

  psVar4 = *(short **)(*(int *)((int)instance->extraData + 0x154) + 4);
  arc = 0;
  if (data->distance < (uint)(int)psVar4[1])
  {
    sVar1 = MATH3D_FastAtan2(500, data->distance);
    elevation = (int)sVar1;
    arc = elevation;
    if (elevation < (int)*psVar4)
    {
      arc = (int)*psVar4;
    }
    if (elevation < (int)psVar4[2])
    {
      elevation = (int)psVar4[2];
    }
    arc = MATH3D_ConeDetect(&data->relativePosition, arc, elevation);
    if (arc == 0)
    {
      arc = 0;
    }
    else
    {
      Inst = data->instance;
      uVar2 = INSTANCE_Query(Inst, 1);
      arc = 1;
      if ((uVar2 & 1) != 0)
      {
        if (instance->matrix == (MATRIX *)0x0)
        {
          local_20 = (instance->position).x;
          local_1e = (instance->position).y;
          local_1c = (instance->position).z;
        }
        else
        {
          pMVar3 = instance->matrix + (uint) * (byte *)((int)instance->data + 0x19);
          local_20 = *(short *)pMVar3->t;
          local_1e = *(short *)(pMVar3->t + 1);
          local_1c = *(short *)(pMVar3->t + 2);
        }
        pMVar3 = Inst->matrix;
        if (pMVar3 == (MATRIX *)0x0)
        {
          local_28 = (Inst->position).x;
          local_26 = (Inst->position).y;
          local_24 = (Inst->position).z;
        }
        else
        {
          local_28 = *(short *)pMVar3[1].t;
          local_26 = *(short *)(pMVar3[1].t + 1);
          local_24 = *(short *)(pMVar3[1].t + 2);
        }
        arc = PhysicsCheckLOS(instance, (int)&local_28, 4);
      }
    }
  }
  return arc;
}

// decompiled code
// original method signature:
// int /*$ra*/ MONSENSE_Hear(struct _Instance *instance /*$a0*/, struct evCollideInstanceStatsData *data /*$s1*/)
// line 153, offset 0x80085c78
/* begin block 1 */
// Start line: 154
// Start offset: 0x80085C78
// Variables:
// 		struct _MonsterVars *mv; // $v0
// 		struct _MonsterSenses *senses; // $s0
// 		long mode; // $a0
/* end block 1 */
// End offset: 0x80085CF4
// End Line: 171

/* begin block 2 */
// Start line: 270
/* end block 2 */
// End Line: 271

int MONSENSE_Hear(_Instance *instance, evCollideInstanceStatsData *data)

{
  ulong uVar1;
  int iVar2;
  int iVar3;

  iVar3 = *(int *)(*(int *)((int)instance->extraData + 0x154) + 4);
  uVar1 = INSTANCE_Query(data->instance, 10);
  if ((((uVar1 & 0x10b0143) == 0) || (iVar2 = 0, (uVar1 & 0x200000) != 0)) &&
      (iVar2 = 0, data->distance < (uint)(int)*(short *)(iVar3 + 8)))
  {
    iVar2 = MATH3D_ConeDetect(&data->relativePosition, (int)*(short *)(iVar3 + 6),
                              (int)*(short *)(iVar3 + 10));
  }
  return iVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ MONSENSE_Smell(struct _Instance *instance /*$a0*/, struct evCollideInstanceStatsData *data /*$a1*/)
// line 176, offset 0x80085d08
/* begin block 1 */
// Start line: 178
// Start offset: 0x80085D08
// Variables:
// 		struct _MonsterVars *mv; // $v0
/* end block 1 */
// End offset: 0x80085D08
// End Line: 178

/* begin block 2 */
// Start line: 319
/* end block 2 */
// End Line: 320

/* begin block 3 */
// Start line: 320
/* end block 3 */
// End Line: 321

int MONSENSE_Smell(_Instance *instance, evCollideInstanceStatsData *data)

{
  return (uint)(data->distance <
                (uint) * (ushort *)(*(int *)(*(int *)((int)instance->extraData + 0x154) + 4) + 0xc));
}

// decompiled code
// original method signature:
// struct _MonsterIR * /*$ra*/ MONSENSE_FirstSense(struct _Instance *instance /*$s2*/, struct _Instance *sensed /*$s4*/)
// line 186, offset 0x80085d30
/* begin block 1 */
// Start line: 187
// Start offset: 0x80085D30
// Variables:
// 		struct _MonsterIR *mir; // $s0
// 		struct _MonsterVars *mv; // $s1

/* begin block 1.1 */
// Start line: 194
// Start offset: 0x80085D6C
// Variables:
// 		long whatAmI; // $s2
// 		struct _MonsterAllegiances *allegiances; // $s3
/* end block 1.1 */
// End offset: 0x80085EB0
// End Line: 224
/* end block 1 */
// End offset: 0x80085EB0
// End Line: 226

/* begin block 2 */
// Start line: 339
/* end block 2 */
// End Line: 340

_MonsterIR *MONSENSE_FirstSense(_Instance *instance, _Instance *sensed)

{
  ushort uVar1;
  _MonsterIR *p_Var2;
  ulong uVar3;
  ulong uVar4;
  _MonsterVars *mv;
  _MonsterAllegiances *p_Var5;

  mv = (_MonsterVars *)instance->extraData;
  p_Var2 = MONSENSE_GetMonsterIR(mv);
  if (p_Var2 != (_MonsterIR *)0x0)
  {
    uVar3 = INSTANCE_Query(sensed, 1);
    p_Var5 = mv->subAttr->allegiances;
    p_Var2->mirFlags = 0x100;
    p_Var2->instance = sensed;
    p_Var2->handle = sensed->instanceID;
    uVar4 = MON_GetTime(instance);
    p_Var2->forgetTimer = uVar4 + (int)mv->subAttr->forgetTime * 1000;
    p_Var2->next = mv->monsterIRList;
    mv->monsterIRList = p_Var2;
    p_Var2->mirConditions = 0;
    if (((uVar3 & p_Var5->enemies) != 0) &&
        (uVar4 = INSTANCE_Query(sensed, 0), (uVar4 & 0x44000000) == 0))
    {
      p_Var2->mirFlags = p_Var2->mirFlags | 1;
    }
    if ((uVar3 & p_Var5->allies) != 0)
    {
      uVar1 = p_Var2->mirFlags;
      p_Var2->mirFlags = uVar1 | 2;
      if (((uVar3 & 10) != 0) && ((*(uint *)sensed->extraData & 0x100000) != 0))
      {
        p_Var2->mirFlags = uVar1 | 0x12;
      }
    }
    if ((uVar3 & p_Var5->food) != 0)
    {
      p_Var2->mirFlags = p_Var2->mirFlags | 9;
    }
    if ((uVar3 & p_Var5->gods) != 0)
    {
      p_Var2->mirFlags = p_Var2->mirFlags | 4;
    }
  }
  return p_Var2;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_SetupMIR(struct _Instance *instance /*$s3*/, struct evCollideInstanceStatsData *data /*$s1*/, int flags /*$s2*/)
// line 233, offset 0x80085ed4
/* begin block 1 */
// Start line: 234
// Start offset: 0x80085ED4
// Variables:
// 		struct _MonsterIR *mir; // $s0
// 		struct _MonsterVars *mv; // $s4

/* begin block 1.1 */
// Start line: 253
// Start offset: 0x80085F78
// Variables:
// 		long mode; // $s1

/* begin block 1.1.1 */
// Start line: 256
// Start offset: 0x80085F78
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $a1
// 		struct _SVector *_v0; // $v0
// 		struct _SVector *_v1; // $v0
/* end block 1.1.1 */
// End offset: 0x80085F78
// End Line: 256

/* begin block 1.1.2 */
// Start line: 301
// Start offset: 0x80086120
// Variables:
// 		int run; // $s2
// 		int distance; // $a0

/* begin block 1.1.2.1 */
// Start line: 312
// Start offset: 0x8008615C
/* end block 1.1.2.1 */
// End offset: 0x800861BC
// End Line: 319
/* end block 1.1.2 */
// End offset: 0x800861BC
// End Line: 336
/* end block 1.1 */
// End offset: 0x800862E0
// End Line: 367
/* end block 1 */
// End offset: 0x800862E0
// End Line: 368

/* begin block 2 */
// Start line: 447
/* end block 2 */
// End Line: 448

void MONSENSE_SetupMIR(_Instance *instance, evCollideInstanceStatsData *data, int flags)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  _MonsterIR *p_Var5;
  _MonsterCombatAttributes *p_Var6;
  ulong uVar7;
  ushort uVar8;
  _MonsterVars *mv;

  mv = (_MonsterVars *)instance->extraData;
  p_Var5 = MONSENSE_FindIR(mv, data->instance);
  if (p_Var5 == (_MonsterIR *)0x0)
  {
    if (flags != 0)
    {
      p_Var5 = MONSENSE_FirstSense(instance, data->instance);
    }
  }
  else
  {
    if (flags != 0)
    {
      uVar7 = MON_GetTime(instance);
      p_Var5->forgetTimer = uVar7 + (int)mv->subAttr->forgetTime * 1000;
    }
  }
  if (p_Var5 == (_MonsterIR *)0x0)
  {
    return;
  }
  p_Var5->mirFlags = p_Var5->mirFlags | (ushort)flags;
  p_Var5->distance = *(short *)&data->distance;
  sVar3 = (data->relativePosition).y;
  sVar1 = (data->relativePosition).z;
  (p_Var5->relativePosition).x = (data->relativePosition).x;
  (p_Var5->relativePosition).y = sVar3;
  (p_Var5->relativePosition).z = sVar1;
  p_Var6 = mv->subAttr->combatAttributes;
  if ((p_Var6 == (_MonsterCombatAttributes *)0x0) || (p_Var6->combatRange <= p_Var5->distance))
  {
    uVar4 = p_Var5->mirConditions & 0xfff7;
  }
  else
  {
    uVar4 = p_Var5->mirConditions | 8;
  }
  p_Var5->mirConditions = uVar4;
  sVar3 = MATH3D_AngleFromPosToPos(&p_Var5->instance->position, &instance->position);
  if (((sVar3 - (p_Var5->instance->rotation).z) + 0x400U & 0xfff) < 0x801)
  {
    uVar4 = p_Var5->mirConditions & 0xfffd;
  }
  else
  {
    uVar4 = p_Var5->mirConditions | 2;
  }
  p_Var5->mirConditions = uVar4;
  uVar7 = INSTANCE_Query(p_Var5->instance, 10);
  if ((uVar7 & 0x208000) == 0x208000)
  {
    uVar7 = uVar7 & 0xffdfffff;
  }
  if ((uVar7 & 4) == 0)
  {
    uVar4 = p_Var5->mirConditions & 0xfffe;
  }
  else
  {
    uVar4 = p_Var5->mirConditions | 1;
  }
  p_Var5->mirConditions = uVar4;
  uVar4 = p_Var5->mirFlags;
  if ((uVar4 & 0x400) == 0)
  {
    if ((uVar7 & 0x200000) != 0)
    {
      p_Var6 = mv->subAttr->combatAttributes;
      if (p_Var6 != (_MonsterCombatAttributes *)0x0)
      {
        if ((uVar7 & 4) == 0)
        {
          sVar3 = p_Var6->enemyAttackRange;
        }
        else
        {
          sVar3 = p_Var6->enemyRunAttackRange;
        }
        p_Var5->mirConditions = p_Var5->mirConditions & 0xff1b;
        p_Var5->mirFlags = p_Var5->mirFlags | 0x400;
        if ((p_Var5->distance < sVar3) &&
            (sVar3 = MATH3D_AngleFromPosToPos(&p_Var5->instance->position, &instance->position),
             ((sVar3 - (p_Var5->instance->rotation).z) + 0x200U & 0xfff) < 0x800))
        {
          if ((uVar7 & 4) != 0)
          {
            p_Var5->mirConditions = p_Var5->mirConditions | 0x20;
          }
          p_Var5->mirConditions = p_Var5->mirConditions | 0x800;
        }
      }
    }
  }
  else
  {
    if ((uVar7 & 0x200000) != 0)
      goto LAB_800861c8;
    uVar2 = p_Var5->mirConditions;
    p_Var5->mirFlags = uVar4 & 0xfbff;
    uVar8 = uVar2 & 0xf7df;
    p_Var5->mirConditions = uVar8;
    if (((uVar4 & 1) != 0) && ((uVar2 & 0x400) == 0))
    {
      p_Var5->mirConditions = uVar8 | 4;
    }
  }
  uVar4 = p_Var5->mirFlags;
LAB_800861c8:
  if ((uVar4 & 0x800) == 0)
  {
    if (uVar7 == 1)
    {
      p_Var5->mirFlags = uVar4 | 0x800;
      uVar7 = MON_GetTime(instance);
      *(undefined **)&p_Var5->idleTime = &DAT_00001356 + uVar7;
    }
  }
  else
  {
    if (uVar7 == 1)
    {
      if (((p_Var5->mirConditions & 0x10) == 0) &&
          (uVar7 = MON_GetTime(instance), p_Var5->idleTime < uVar7))
      {
        p_Var5->mirConditions = p_Var5->mirConditions | 0x10;
      }
    }
    else
    {
      p_Var5->mirFlags = uVar4 & 0xf7ff;
      p_Var5->mirConditions = p_Var5->mirConditions & 0xffef;
    }
  }
  uVar4 = p_Var5->mirFlags;
  if ((uVar4 & 0x200) == 0)
  {
    if ((uVar4 & 2) == 0)
    {
      return;
    }
    uVar4 = uVar4 | 0x200;
    if (mv->subAttr->combatAttributes->allyRange <= p_Var5->distance)
    {
      return;
    }
  }
  else
  {
    if (((int)p_Var5->distance <= (int)mv->subAttr->combatAttributes->allyRange + 300) &&
        (uVar7 = INSTANCE_Query(p_Var5->instance, 0), (uVar7 & 0x44000000) == 0))
    {
      return;
    }
    uVar4 = p_Var5->mirFlags & 0xfdff;
  }
  p_Var5->mirFlags = uVar4;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_SenseInstance(struct _Instance *instance /*$s3*/, struct evCollideInstanceStatsData *data /*$s2*/)
// line 374, offset 0x80086300
/* begin block 1 */
// Start line: 375
// Start offset: 0x80086300
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		long flags; // $s0
// 		unsigned long whatAmI; // $s4

/* begin block 1.1 */
// Start line: 387
// Start offset: 0x80086358
// Variables:
// 		struct PhysObProperties *prop; // $s0

/* begin block 1.1.1 */
// Start line: 390
// Start offset: 0x80086378
/* end block 1.1.1 */
// End offset: 0x80086418
// End Line: 401
/* end block 1.1 */
// End offset: 0x80086418
// End Line: 401
/* end block 1 */
// End offset: 0x800864D4
// End Line: 419

/* begin block 2 */
// Start line: 735
/* end block 2 */
// End Line: 736

void MONSENSE_SenseInstance(_Instance *instance, evCollideInstanceStatsData *data)

{
  ulong uVar1;
  int iVar2;
  uint flags;
  void *pvVar3;
  uint *puVar4;

  flags = 0;
  puVar4 = (uint *)instance->extraData;
  uVar1 = INSTANCE_Query(data->instance, 1);
  if ((*puVar4 & 0x200) == 0)
  {
    if ((uVar1 & 0x20) == 0)
    {
      if (*(char *)((int)puVar4 + 0x14e) != '\0')
      {
        iVar2 = MONSENSE_Smell(instance, data);
        if (iVar2 != 0)
        {
          flags = 0x80;
        }
        iVar2 = MONSENSE_See(instance, data);
        if (iVar2 != 0)
        {
          flags = flags | 0x20;
        }
        iVar2 = MONSENSE_Hear(instance, data);
        if (iVar2 != 0)
        {
          flags = flags | 0x40;
        }
        if (((uVar1 & *(uint *)(*(int *)(puVar4[0x55] + 0xc) + 4)) != 0) &&
            (data->distance < (uint) * (ushort *)(*(int *)(puVar4[0x55] + 4) + 0x10)))
        {
          flags = flags | 2;
        }
        MONSENSE_SetupMIR(instance, data, flags);
      }
    }
    else
    {
      pvVar3 = data->instance->data;
      if ((((*(short *)((int)pvVar3 + 2) == 3) &&
            (data->xyDistance < (int)(uint)(*(ushort *)((int)pvVar3 + 0x1e) >> 1))) &&
           (data->zDelta < (int)*(short *)((int)pvVar3 + 0x22))) &&
          ((int)*(short *)((int)pvVar3 + 0x20) < data->zDelta))
      {
        if ((*(ushort *)((int)pvVar3 + 8) & 0x40) != 0)
        {
          INSTANCE_Post(instance, 0x100000c, 0x20);
        }
        if ((*(ushort *)((int)pvVar3 + 8) & 8) != 0)
        {
          INSTANCE_Post(instance, 0x100000c, 0x40);
        }
        if ((*(ushort *)((int)pvVar3 + 8) & 0x10) != 0)
        {
          INSTANCE_Post(instance, 0x100000c, 0x10);
        }
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_StartMonsterIRList(struct _Instance *instance /*$s5*/)
// line 424, offset 0x800864f4
/* begin block 1 */
// Start line: 425
// Start offset: 0x800864F4
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct _MonsterIR *mir; // $s0
// 		struct _MonsterIR *newlist; // $s2
// 		int enemyOnList; // $s4

/* begin block 1.1 */
// Start line: 435
// Start offset: 0x80086540
// Variables:
// 		struct _MonsterIR *next; // $s3
/* end block 1.1 */
// End offset: 0x800865C8
// End Line: 463
/* end block 1 */
// End offset: 0x800865E4
// End Line: 471

/* begin block 2 */
// Start line: 839
/* end block 2 */
// End Line: 840

void MONSENSE_StartMonsterIRList(_Instance *instance)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ulong uVar4;
  void *pvVar5;
  undefined4 *puVar6;

  pvVar5 = instance->extraData;
  bVar1 = false;
  if (*(char *)((int)pvVar5 + 0x14e) != '\0')
  {
    puVar2 = (undefined4 *)0;
    puVar6 = *(undefined4 **)((int)pvVar5 + 0x90);
    while (puVar3 = puVar6, puVar3 != (undefined4 *)0x0)
    {
      puVar6 = (undefined4 *)*puVar3;
      if ((puVar3[2] == *(int *)(puVar3[1] + 0x10)) &&
          (((*(ushort *)((int)puVar3 + 0x16) & 0xe0) != 0 ||
            (uVar4 = MON_GetTime(instance), uVar4 <= (uint)puVar3[7]))))
      {
        *(undefined4 **)puVar3 = puVar2;
        *(ushort *)((int)puVar3 + 0x16) = *(ushort *)((int)puVar3 + 0x16) & 0xff1f;
        puVar2 = puVar3;
        if (*(undefined4 **)((int)pvVar5 + 0xc4) == puVar3)
        {
          bVar1 = true;
          puVar2 = puVar3;
        }
      }
      else
      {
        *puVar3 = *(undefined4 *)((int)pvVar5 + 0x158);
        *(undefined4 **)((int)pvVar5 + 0x158) = puVar3;
      }
    }
    if (!bVar1)
    {
      *(undefined4 *)((int)pvVar5 + 0xc4) = 0;
    }
    *(undefined4 **)((int)pvVar5 + 0x90) = puVar2;
  }
  return;
}

// decompiled code
// original method signature:
// struct _MonsterIR * /*$ra*/ MONSENSE_GetMonsterIR(struct _MonsterVars *mv /*$a0*/)
// line 476, offset 0x80086608
/* begin block 1 */
// Start line: 478
// Start offset: 0x80086608
// Variables:
// 		struct _MonsterIR *mir; // $v1
/* end block 1 */
// End offset: 0x80086628
// End Line: 488

/* begin block 2 */
// Start line: 975
/* end block 2 */
// End Line: 976

/* begin block 3 */
// Start line: 976
/* end block 3 */
// End Line: 977

/* begin block 4 */
// Start line: 978
/* end block 4 */
// End Line: 979

_MonsterIR *MONSENSE_GetMonsterIR(_MonsterVars *mv)

{
  _MonsterIR *p_Var1;

  p_Var1 = mv->freeIRs;
  if (p_Var1 == (_MonsterIR *)0x0)
  {
    p_Var1 = (_MonsterIR *)0x0;
  }
  else
  {
    mv->freeIRs = p_Var1->next;
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_InitIRList(struct _MonsterVars *mv /*$a0*/, struct _MonsterIR *list /*$a1*/, int num /*$a2*/)
// line 494, offset 0x80086630
/* begin block 1 */
// Start line: 496
// Start offset: 0x80086630
// Variables:
// 		int i; // $a2
/* end block 1 */
// End offset: 0x80086650
// End Line: 505

/* begin block 2 */
// Start line: 1011
/* end block 2 */
// End Line: 1012

/* begin block 3 */
// Start line: 1012
/* end block 3 */
// End Line: 1013

/* begin block 4 */
// Start line: 1016
/* end block 4 */
// End Line: 1017

void MONSENSE_InitIRList(_MonsterVars *mv, _MonsterIR *list, int num)

{
  num = num + -1;
  mv->freeIRs = list;
  while (num != 0)
  {
    list->next = list + 1;
    num = num + -1;
    list = list + 1;
  }
  list->next = (_MonsterIR *)0x0;
  mv->monsterIRList = (_MonsterIR *)0x0;
  return;
}

// decompiled code
// original method signature:
// struct _MonsterIR * /*$ra*/ MONSENSE_SetEnemy(struct _Instance *instance /*$s1*/, struct _Instance *newenemy /*$s2*/)
// line 512, offset 0x8008665c
/* begin block 1 */
// Start line: 513
// Start offset: 0x8008665C
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterIR *mir; // $a2

/* begin block 1.1 */
// Start line: 532
// Start offset: 0x800866D0
// Variables:
// 		long angle; // $v0
/* end block 1.1 */
// End offset: 0x8008672C
// End Line: 538
/* end block 1 */
// End offset: 0x80086760
// End Line: 548

/* begin block 2 */
// Start line: 1049
/* end block 2 */
// End Line: 1050

_MonsterIR *MONSENSE_SetEnemy(_Instance *instance, _Instance *newenemy)

{
  short sVar1;
  _MonsterIR *p_Var2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  _MonsterVars *mv;

  mv = (_MonsterVars *)instance->extraData;
  p_Var2 = MONSENSE_FindIR(mv, newenemy);
  if (p_Var2 == (_MonsterIR *)0x0)
  {
    p_Var2 = MONSENSE_FirstSense(instance, newenemy);
    if (p_Var2 == (_MonsterIR *)0x0)
    {
      p_Var2 = mv->monsterIRList;
      mv->monsterIRList = p_Var2->next;
      p_Var2->next = mv->freeIRs;
      mv->freeIRs = p_Var2;
      p_Var2 = MONSENSE_FirstSense(instance, newenemy);
      if (p_Var2 == (_MonsterIR *)0x0)
        goto LAB_8008673c;
    }
    uVar5 = (uint)(ushort)(instance->rotation).z & 0xfff;
    if (0x800 < uVar5)
    {
      uVar5 = uVar5 - 0x1000;
    }
    uVar4 = (uint)(ushort)(newenemy->rotation).z & 0xfff;
    iVar3 = uVar5 - uVar4;
    if (0x800 < uVar4)
    {
      iVar3 = (uVar5 + 0x1000) - uVar4;
    }
    if (iVar3 < 0)
    {
      iVar3 = -iVar3;
    }
    sVar1 = 100;
    if (0x3ff < iVar3)
    {
      sVar1 = -100;
    }
    (p_Var2->relativePosition).y = sVar1;
  }
  p_Var2->mirFlags = p_Var2->mirFlags | 1;
LAB_8008673c:
  if ((mv->enemy == (_MonsterIR *)0x0) || (newenemy == gameTrackerX.playerInstance))
  {
    mv->enemy = p_Var2;
  }
  return p_Var2;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_ProcessIRList(struct _Instance *instance /*$s7*/)
// line 554, offset 0x8008677c
/* begin block 1 */
// Start line: 555
// Start offset: 0x8008677C
// Variables:
// 		struct _MonsterVars *mv; // $s4
// 		struct _MonsterIR *mir; // $s0
// 		struct _MonsterIR *closestEnemy; // $s1
// 		struct _MonsterIR *closestLeader; // $s2
// 		struct _MonsterIR *closestAlly; // $s3
// 		struct _MonsterIR *player; // $s6
// 		struct _MonsterCombatAttributes *combatAttr; // $s5
/* end block 1 */
// End offset: 0x80086968
// End Line: 612

/* begin block 2 */
// Start line: 1138
/* end block 2 */
// End Line: 1139

void MONSENSE_ProcessIRList(_Instance *instance)

{
  ulong uVar1;
  int Message;
  int *Data;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;

  piVar2 = (int *)0x0;
  piVar3 = (int *)0x0;
  piVar4 = (int *)0x0;
  pvVar5 = instance->extraData;
  Data = *(int **)((int)pvVar5 + 0x90);
  iVar6 = *(int *)(*(int *)((int)pvVar5 + 0x154) + 8);
  piVar7 = (int *)0x0;
  while (Data != (int *)0x0)
  {
    if (((_Instance *)Data[1])->instanceID == Data[2])
    {
      if ((*(ushort *)((int)Data + 0x16) & 1) != 0)
      {
        uVar1 = INSTANCE_Query((_Instance *)Data[1], 1);
        if ((uVar1 & 1) != 0)
        {
          piVar7 = Data;
        }
        if ((piVar2 == (int *)0x0) || (*(short *)(Data + 5) < *(short *)((int)piVar2 + 0x14)))
        {
          piVar2 = Data;
        }
        if ((*(ushort *)((int)Data + 0x16) & 0x100) != 0)
        {
          if ((iVar6 == 0) || (*(short *)(iVar6 + 0xc) <= *(short *)(Data + 5)))
          {
            Message = 0x1000012;
          }
          else
          {
            Message = 0x100000e;
          }
          INSTANCE_Post(instance, Message, (int)Data);
        }
      }
      if (((*(ushort *)((int)Data + 0x16) & 0x10) != 0) &&
          ((piVar3 == (int *)0x0 || (*(short *)(Data + 5) < *(short *)((int)piVar3 + 0x14)))))
      {
        piVar3 = Data;
      }
      if ((((*(ushort *)((int)Data + 0x16) & 2) != 0) &&
           (uVar1 = INSTANCE_Query((_Instance *)Data[1], 1), (uVar1 & 4) == 0)) &&
          ((piVar4 == (int *)0x0 || (*(short *)(Data + 5) < *(short *)((int)piVar4 + 0x14)))))
      {
        piVar4 = Data;
      }
      *(ushort *)((int)Data + 0x16) = *(ushort *)((int)Data + 0x16) & 0xfeff;
    }
    Data = (int *)*Data;
  }
  if ((piVar7 == (int *)0x0) ||
      (((iVar6 != 0 && (*(char *)(iVar6 + 0x1c) != '\0')) && (*(short *)((int)pvVar5 + 0x130) == 0))))
  {
    *(int **)((int)pvVar5 + 0xc4) = piVar2;
  }
  else
  {
    *(int **)((int)pvVar5 + 0xc4) = piVar7;
  }
  *(int **)((int)pvVar5 + 200) = piVar3;
  *(int **)((int)pvVar5 + 0xcc) = piVar4;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_SetupSenses(struct _Instance *instance /*$s2*/)
// line 630, offset 0x8008699c
/* begin block 1 */
// Start line: 631
// Start offset: 0x8008699C
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct _MonsterAllegiances *allegiances; // $s0
// 		int num; // $v0
/* end block 1 */
// End offset: 0x80086AF0
// End Line: 697

/* begin block 2 */
// Start line: 1260
/* end block 2 */
// End Line: 1261

void MONSENSE_SetupSenses(_Instance *instance)

{
  int iVar1;
  _MonsterAllegiances *p_Var2;
  _MonsterVars *mv;

  mv = (_MonsterVars *)instance->extraData;
  p_Var2 = mv->subAttr->allegiances;
  MONSENSE_InitIRList(mv, (_MonsterIR *)(mv + 1), 5);
  instance->flags2 = instance->flags2 | 0x400;
  if (p_Var2 != (_MonsterAllegiances *)0x0)
  {
    instance->checkMask = p_Var2->enemies | p_Var2->allies | p_Var2->food | p_Var2->gods;
  }
  instance->maxCheckDistance = 12000;
  iVar1 = gNumMonsters;
  instance->checkMask = instance->checkMask | 0xb;
  mv->enemy = (_MonsterIR *)0x0;
  mv->leader = (_MonsterIR *)0x0;
  (&monsterSenseArray40)[iVar1] = mv;
  mv->senseIndex = (char)gNumMonsters;
  if (gNumMonsters == 0)
  {
    lastSenseFrame = -1;
  }
  gNumMonsters = gNumMonsters + 1;
  if ((*(uint *)((int)instance->data + 0x10) & 0x1804) == 0)
  {
    iVar1 = gNumMaterialMonsters + 1;
    gNumMaterialMonsters = iVar1;
  }
  else
  {
    iVar1 = gNumSpectralMonsters + 1;
    gNumSpectralMonsters = iVar1;
  }
  if (((6 < iVar1) && (instance->parent == (_Instance *)0x0)) &&
      (instance->currentStreamUnitID != instance->birthStreamUnitID))
  {
    instance->flags = instance->flags | 0x20;
    instance->flags2 = instance->flags2 | 0x20000;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_RemoveSenses(struct _Instance *instance /*$a0*/)
// line 702, offset 0x80086b08
/* begin block 1 */
// Start line: 704
// Start offset: 0x80086B08
// Variables:
// 		struct _MonsterVars *mv; // $a0
// 		int i; // $a1
/* end block 1 */
// End offset: 0x80086BA0
// End Line: 723

/* begin block 2 */
// Start line: 1541
/* end block 2 */
// End Line: 1542

/* begin block 3 */
// Start line: 1542
/* end block 3 */
// End Line: 1543

/* begin block 4 */
// Start line: 1547
/* end block 4 */
// End Line: 1548

void MONSENSE_RemoveSenses(_Instance *instance)

{
  int iVar1;
  int iVar2;

  gNumMonsters = gNumMonsters + -1;
  if ((*(uint *)((int)instance->data + 0x10) & 0x1804) == 0)
  {
    gNumMaterialMonsters = gNumMaterialMonsters + -1;
  }
  else
  {
    gNumSpectralMonsters = gNumSpectralMonsters + -1;
  }
  iVar2 = (int)*(char *)((int)instance->extraData + 0x14f);
  if (iVar2 < gNumMonsters)
  {
    do
    {
      iVar1 = iVar2 + 1;
      (&monsterSenseArray40)[iVar2] = (&monsterSenseArray40)[iVar1];
      (&monsterSenseArray40)[iVar1]->senseIndex = (char)iVar2;
      iVar2 = iVar1;
    } while (iVar1 < gNumMonsters);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_Radar(struct _Instance *instance /*$s0*/)
// line 847, offset 0x80086ba8
/* begin block 1 */
// Start line: 848
// Start offset: 0x80086BA8
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct SVECTOR newPos; // stack offset -96
// 		struct SVECTOR oldPos; // stack offset -88
// 		struct _PCollideInfo pCollideInfo; // stack offset -80
// 		int index; // $s3
/* end block 1 */
// End offset: 0x80086DC0
// End Line: 919

/* begin block 2 */
// Start line: 1840
/* end block 2 */
// End Line: 1841

void MONSENSE_Radar(_Instance *instance)

{
  undefined2 uVar1;
  ushort uVar2;
  long lVar3;
  void *pvVar4;
  uint uVar5;
  SVECTOR local_60;
  SVECTOR local_58;
  _PCollideInfo local_50;

  pvVar4 = instance->extraData;
  uVar5 = (uint)(&radarDirIndex)[(uint) * (ushort *)((int)pvVar4 + 0xe2)];
  local_60.vx = (instance->position).x + (&radarDir)[uVar5].x;
  local_60.vy = (instance->position).y + (&radarDir)[uVar5].y;
  local_60.vz = (instance->position).z + 100;
  local_58.vx = (instance->position).x;
  local_58.vy = (instance->position).y;
  local_50.newPoint = &local_60;
  local_50.oldPoint = &local_58;
  local_50.collideType = 0x13f;
  local_58.vz = (instance->position).z + 100;
  PHYSICS_CheckLineInWorldMask(instance, &local_50);
  if (local_50.type == 0)
  {
    local_58.vx = (instance->position).x + (&radarDir)[uVar5].x;
    local_58.vy = (instance->position).y + (&radarDir)[uVar5].y;
    local_58.vz = (instance->position).z + -0x100;
    local_60.vx = (instance->position).x;
    local_60.vy = (instance->position).y;
    local_60.vz = (instance->position).z + -0x100;
    PHYSICS_CheckLineInWorld(instance, &local_50);
    if (local_50.type != 0)
      goto LAB_80086d10;
    *(ushort *)((int)pvVar4 + 0xe0) =
        *(ushort *)((int)pvVar4 + 0xe0) | (ushort)(1 << (uVar5 & 0x1f));
    uVar1 = 0x500;
  }
  else
  {
  LAB_80086d10:
    *(ushort *)((int)pvVar4 + 0xe0) =
        *(ushort *)((int)pvVar4 + 0xe0) & ~(ushort)(1 << (uVar5 & 0x1f));
    if ((local_50.type == 3) &&
        ((*(ushort *)((int)((local_50.inst)->node).prev[9].prev + (int)local_50.segment * 0x24 + 0x12) & 2) !=
         0))
    {
      *(undefined2 *)((int)pvVar4 + uVar5 * 2 + 0xe4) = 0;
      goto LAB_80086d9c;
    }
    lVar3 = MATH3D_LengthXY((int)local_60.vx - (int)(instance->position).x,
                            (int)local_60.vy - (int)(instance->position).y);
    uVar1 = (undefined2)lVar3;
  }
  *(undefined2 *)((int)pvVar4 + uVar5 * 2 + 0xe4) = uVar1;
LAB_80086d9c:
  uVar2 = *(short *)((int)pvVar4 + 0xe2) + 1;
  *(ushort *)((int)pvVar4 + 0xe2) = uVar2;
  if (7 < uVar2)
  {
    *(undefined2 *)((int)pvVar4 + 0xe2) = 0;
  }
  return;
}

// decompiled code
// original method signature:
// short /*$ra*/ MONSENSE_GetClosestFreeDirection(struct _Instance *instance /*$a0*/, short angle /*$t1*/, long range /*$a2*/)
// line 924, offset 0x80086de4
/* begin block 1 */
// Start line: 925
// Start offset: 0x80086DE4
// Variables:
// 		struct _MonsterVars *mv; // $t0
// 		int bit; // $a1
// 		int search; // $a0
/* end block 1 */
// End offset: 0x80086EE0
// End Line: 958

/* begin block 2 */
// Start line: 2013
/* end block 2 */
// End Line: 2014

/* WARNING: Removing unreachable block (ram,0x80086e04) */

short MONSENSE_GetClosestFreeDirection(_Instance *instance, short angle, long range)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;

  pvVar5 = instance->extraData;
  uVar3 = (int)((int)angle + 0x100U & 0xfff) >> 9;
  iVar2 = 1;
  if ((*(short *)((int)pvVar5 + uVar3 * 2 + 0xe4) == 0) &&
      (uVar4 = uVar3 + 4 & 7, range < (int)*(short *)((int)pvVar5 + uVar4 * 2 + 0xe4)))
  {
    return (&radarDir)[uVar4].angle;
  }
  sVar1 = *(short *)((int)pvVar5 + uVar3 * 2 + 0xe4);
  while (true)
  {
    if (range <= (int)sVar1)
    {
      return angle;
    }
    if (iVar2 < 1)
    {
      uVar3 = uVar3 + iVar2 * 2;
      iVar2 = 1 - iVar2;
    }
    else
    {
      uVar3 = (uVar3 - 1) + iVar2 * 2;
      iVar2 = -iVar2;
    }
    uVar3 = uVar3 & 7;
    if (3 < iVar2)
      break;
    sVar1 = *(short *)((int)pvVar5 + uVar3 * 2 + 0xe4);
    angle = (&radarDir)[uVar3].angle;
  }
  return angle;
}

// decompiled code
// original method signature:
// int /*$ra*/ MONSENSE_GetDistanceInDirection(struct _Instance *instance /*$a0*/, short angle /*$a1*/)
// line 963, offset 0x80086ee8
/* begin block 1 */
// Start line: 965
// Start offset: 0x80086EE8
// Variables:
// 		struct _MonsterVars *mv; // $v1
// 		int bit; // $v0
/* end block 1 */
// End offset: 0x80086F08
// End Line: 966

/* begin block 2 */
// Start line: 2096
/* end block 2 */
// End Line: 2097

/* begin block 3 */
// Start line: 2097
/* end block 3 */
// End Line: 2098

/* begin block 4 */
// Start line: 2098
/* end block 4 */
// End Line: 2099

/* WARNING: Removing unreachable block (ram,0x80086f04) */

int MONSENSE_GetDistanceInDirection(_Instance *instance, short angle)

{
  return (int)*(short *)((int)instance->extraData +
                         ((int)((int)angle + 0x100U & 0xfff) >> 9) * 2 + 0xe4);
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_DoSenses(struct _Instance *instance /*$s1*/)
// line 974, offset 0x80086f20
/* begin block 1 */
// Start line: 975
// Start offset: 0x80086F20
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		static int doneThisFrame; // offset 0x44
/* end block 1 */
// End offset: 0x80087004
// End Line: 1005

/* begin block 2 */
// Start line: 2119
/* end block 2 */
// End Line: 2120

void MONSENSE_DoSenses(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MONSENSE_ProcessIRList(instance);
  if (lastSenseFrame < (int)gameTrackerX.frameCount)
  {
    if (lastSenseFrame < (int)(gameTrackerX.frameCount - 1))
    {
      memset(&monsterSensed, 0, 0x28);
      lastSenseFrame = gameTrackerX.frameCount - 1;
    }
    DAT_800cf670 = 0;
  }
  if ((DAT_800cf670 == 0) && ((&monsterSensed)[(int)*(char *)((int)pvVar1 + 0x14f)] == '\0'))
  {
    lastSenseFrame = gameTrackerX.frameCount;
    (&monsterSensed)[(int)*(char *)((int)pvVar1 + 0x14f)] = '\x01';
    DAT_800cf670 = 1;
    *(undefined *)((int)pvVar1 + 0x14e) = 1;
    if ((*(uint *)((int)pvVar1 + 4) & 0x20000000) == 0)
    {
      MONSENSE_Radar(instance);
    }
  }
  else
  {
    *(undefined *)((int)pvVar1 + 0x14e) = 0;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MONSENSE_AdjustRadarFromObjects(struct _Instance *instance /*$s3*/)
// line 1010, offset 0x80087018
/* begin block 1 */
// Start line: 1011
// Start offset: 0x80087018
// Variables:
// 		struct _MonsterVars *mv; // $s4
// 		struct _Instance *physob; // $s2

/* begin block 1.1 */
// Start line: 1019
// Start offset: 0x80087068
// Variables:
// 		struct PhysObProperties *prop; // $s1

/* begin block 1.1.1 */
// Start line: 1022
// Start offset: 0x80087080

/* begin block 1.1.1.1 */
// Start line: 1028
// Start offset: 0x800870BC
// Variables:
// 		long dist; // $s0

/* begin block 1.1.1.1.1 */
// Start line: 1033
// Start offset: 0x800870F0
// Variables:
// 		int i; // $v1
// 		int min; // $a1
// 		int max; // $a2
// 		int ang; // $s0
/* end block 1.1.1.1.1 */
// End offset: 0x800871CC
// End Line: 1060
/* end block 1.1.1.1 */
// End offset: 0x800871CC
// End Line: 1061
/* end block 1.1.1 */
// End offset: 0x800871CC
// End Line: 1063
/* end block 1.1 */
// End offset: 0x800871CC
// End Line: 1064
/* end block 1 */
// End offset: 0x800871DC
// End Line: 1066

/* begin block 2 */
// Start line: 2191
/* end block 2 */
// End Line: 2192

/* begin block 3 */
// Start line: 2195
/* end block 3 */
// End Line: 2196

/* WARNING: Removing unreachable block (ram,0x8008712c) */
/* WARNING: Removing unreachable block (ram,0x80087144) */

void MONSENSE_AdjustRadarFromObjects(_Instance *instance)

{
  short sVar1;
  short sVar2;
  int iVar3;
  long x;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  _Instance *p_Var7;
  void *pvVar8;

  p_Var7 = (gameTrackerX.instanceList)->first;
  pvVar8 = instance->extraData;
  while (p_Var7 != (_Instance *)0x0)
  {
    if ((((p_Var7->object->oflags2 & 0x40000U) != 0) &&
         (pvVar6 = p_Var7->data, *(short *)((int)pvVar6 + 2) == 3)) &&
        ((*(ushort *)((int)pvVar6 + 8) & 0x40) != 0))
    {
      iVar3 = (int)(p_Var7->position).z - (int)(instance->position).z;
      if (iVar3 < 0)
      {
        iVar3 = -iVar3;
      }
      if ((iVar3 < 400) &&
          (x = MATH3D_LengthXY((int)(p_Var7->position).x - (int)(instance->position).x,
                               (int)(p_Var7->position).y - (int)(instance->position).y),
           x < (int)((uint) * (ushort *)((int)pvVar6 + 0x1e) + 0x500)))
      {
        sVar1 = MATH3D_AngleFromPosToPos(&instance->position, &p_Var7->position);
        sVar2 = MATH3D_FastAtan2((uint) * (ushort *)((int)pvVar6 + 0x1e), x);
        uVar5 = (int)((int)sVar1 + (int)sVar2 + 0x100U & 0xfff) >> 9;
        uVar4 = (int)(((int)sVar1 - (int)sVar2) + 0x100U & 0xfff) >> 9;
        if (uVar4 < uVar5)
        {
          if (uVar4 <= uVar5)
          {
            pvVar6 = (void *)(uVar4 * 2 + (int)pvVar8);
            do
            {
              *(undefined2 *)((int)pvVar6 + 0xe4) = 0;
              uVar4 = uVar4 + 1;
              pvVar6 = (void *)((int)pvVar6 + 2);
            } while ((int)uVar4 <= (int)uVar5);
          }
        }
        else
        {
          iVar3 = 0;
          pvVar6 = pvVar8;
          do
          {
            *(undefined2 *)((int)pvVar6 + 0xe4) = 0;
            iVar3 = iVar3 + 1;
            pvVar6 = (void *)((int)pvVar6 + 2);
          } while (iVar3 <= (int)uVar5);
          if (uVar4 < 8)
          {
            pvVar6 = (void *)(uVar4 * 2 + (int)pvVar8);
            do
            {
              *(undefined2 *)((int)pvVar6 + 0xe4) = 0;
              uVar4 = uVar4 + 1;
              pvVar6 = (void *)((int)pvVar6 + 2);
            } while ((int)uVar4 < 8);
          }
        }
      }
    }
    p_Var7 = p_Var7->next;
  }
  return;
}
