#include "THISDUST.H"
#include "MONSTER.H"

void MON_DoCombatTimers(_Instance *instance)

{
  u_long uVar1;
  int amount;
  u_int uVar2;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  uVar1 = MON_GetAnim(instance);
  uVar2 = *puVar3;
  if ((uVar2 & 0x10) == 0)
  {
    if (((uVar2 & 0x2000) == 0) && (*(short *)(puVar3 + 0x50) < *(short *)((int)puVar3 + 0x142)))
    {
      amount = (u_int) * (u_short *)(puVar3 + 0x50) +
               ((int)*(short *)(*(int *)(puVar3[0x59] + 8) + 4) * gameTrackerX.timeMult >> 0xc);
      *(short *)(puVar3 + 0x50) = (short)amount;
      if ((int)*(short *)((int)puVar3 + 0x142) < amount * 0x10000 >> 0x10)
      {
        *(undefined2 *)(puVar3 + 0x50) = *(undefined2 *)((int)puVar3 + 0x142);
      }
      amount = MONSTER_CalcDamageIntensity((int)*(short *)(puVar3 + 0x50), (int)*(short *)((int)puVar3 + 0x142));
      MONSTER_InitVertexColors(instance, (int)*(short *)(puVar3 + 0x52), amount);
    }
  }
  else
  {
    if (puVar3[0x43] < uVar1)
    {
      *puVar3 = uVar2 & 0xff7fffef;
    }
  }
  if (((*puVar3 & 0x100) != 0) && (puVar3[0x44] < uVar1))
  {
    *puVar3 = *puVar3 & 0xfffffeff;
  }
  if (uVar1 % 1000 < (uVar1 - gameTrackerX.lastLoopTime) % 1000)
  {
    amount = rand();
 100) * -100;
  }
  return;
}

void MON_ChangeHumanOpinion(_Instance *instance)

{
  bool bVar1;
  u_long uVar2;
  int iVar3;

  iVar3 = (int)GlobalSave->humanOpinionOfRaziel;
  uVar2 = INSTANCE_Post(instance, 1);
  bVar1 = -2 < iVar3;
  if (((uVar2 & 0xc000) != 0) && (iVar3 = iVar3 + -5, bVar1))
  {
    iVar3 = -1;
  }
  if (iVar3 < -0x7fff)
  {
    iVar3 = -0x7fff;
  }
  else
  {
    if (0x7fff < iVar3)
    {
      iVar3 = 0x7fff;
    }
  }
  if ((iVar3 < 0) && (-1 < GlobalSave->humanOpinionOfRaziel))
  {
    HUMAN_GetAngry();
  }
  GlobalSave->humanOpinionOfRaziel = (short)iVar3;
  return;
}

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
  LoadAverageShort12((u_int *)&local_20, (u_int *)&local_28, fade_amount, 0x1000 - fade_amount,
                     (u_int *)&local_38);
  if (((instance->halvePlane).flags & 8U) == 0)
  {
    local_18[0] = (undefined *)0x0;
    local_30.x = local_20 - local_28;
    local_30.y = local_1e - local_26;
    local_30.z = local_1c - local_24;
    PHYSOB_Normalize(&local_30);
    FX_DoInstancePowerRing(instance, (long)&DAT_00002ee0, (long *)local_18, 0, 2);
    local_18[0] = &DAT_000080ff;
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
  return;
}

void MON_DeadEntry(_Instance *instance)

{
  u_long uVar1;
  u_char local_10;
  u_int *puVar2;
  u_char local_c;
  u_char local_8;
  u_char in_stack_fffffffc;

  puVar2 = (u_int *)instance->extraData;
  MON_TurnOffWeaponSpheres(instance);
  if ((puVar2[0x31] != 0) &&
      (uVar1 = INSTANCE_Post(*(_Instance **)(puVar2[0x31] + 4), 1), (uVar1 & 1) != 0))
  {
    MON_ChangeHumanOpinion(instance);
  }
  if (*(char *)((int)puVar2 + 0x155) == -1)
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
                 0x18);
  }
  *puVar2 = *puVar2 | 0x200;
  instance->flags2 = instance->flags2 & 0xffffff3f;
  if ((puVar2[0x36] == 0) && (*(short *)(puVar2 + 0x51) != 0))
  {
    MON_BirthMana(instance, 1);
  }
  else
  {
    uVar1 = MON_GetAnim(instance);
    puVar2[0x43] = uVar1;
  }
  return;
}

void MON_Dead(_Instance *instance)

{
  char cVar1;
  bool bVar2;
  CVECTOR *pCVar3;
  int Message;
  long lVar4;
  u_long uVar5;
  int Data;
  __Event *p_Var6;
  undefined *puVar7;
  u_int introUniqueID;
  void *pvVar8;
  _Model *p_Var9;
  _Instance *instance_00;
  u_int *puVar10;
  _Instance *instance_01;
  _Instance *instance_02;
  u_char local_70;
  u_char local_6c;
  u_char local_68;
  u_char in_stack_ffffff9c;
  SVECTOR local_60;
  SVECTOR local_58;
  _PCollideInfo _Stack80;

  puVar10 = (u_int *)instance->extraData;
  instance_02 = (_Instance *)0x0;
  introUniqueID = puVar10[0x36];
  bVar2 = false;
  if (introUniqueID == 0)
  {
    if ((*puVar10 & 0x200) == 0)
    {
      if ((instance->flags2 & 0x10U) != 0)
      {
        MON_PlayCombatIdle(instance, 2);
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_6c, local_70));
      }
    }
    else
    {
      pvVar8 = instance->data;
      uVar5 = MON_GetAnim(instance);
      if ((int)(uVar5 - puVar10[0x43]) < 0x1000)
      {
        MON_CutOut_Monster(instance, uVar5 - puVar10[0x43], (u_int) * (byte *)((int)pvVar8 + 0x19),
                           (u_int) * (byte *)((int)pvVar8 + 0x21));
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
      instance_02 = INSTANCE_Deactivate(introUniqueID);
    }
    if (instance_02 == (_Instance *)0x0)
    {
      MON_BirthMana(instance, 1);
    }
    else
    {
      if (*(int *)((int)instance_02->extraData + 0xd8) == 0)
      {
        *(long *)((int)instance_02->extraData + 0xd8) = instance->introUniqueID;
      }
    }
  }
  cVar1 = *(char *)(puVar10 + 0x55);
  if ((cVar1 == '\x06') || (cVar1 == '\x04'))
  {
    MON_KillMonster(instance);
  }
  else
  {
    if (((byte)(cVar1 - 1U) < 3) && (instance->perVertexColor == (CVECTOR *)0x0))
    {
      p_Var9 = instance->object->modelList[instance->currentModel];
      pCVar3 = (CVECTOR *)MEMPACK_Malloc(p_Var9->numVertices << 2, '!');
      instance->perVertexColor = pCVar3;
      Data = p_Var9->numVertices;
      while (Data != 0)
      {
        *pCVar3 = (CVECTOR)0x101010;
        Data = Data + -1;
        pCVar3 = pCVar3 + 1;
      }
    }
    else
    {
      if ((*(char *)(puVar10 + 0x55) == '\0') && (puVar10[0x34] == 0))
      {
        instance->flags2 = instance->flags2 | 0x80;
        instance_01 = (_Instance *)0x0;
        if (puVar10[0x35] == 0)
        {
          instance_00 = (gameTrackerX.instanceList)->first;
          Data = 1000;
          while (instance_00 != (_Instance *)0x0)
          {
            if (((((instance != instance_00) && (instance_00->object != (Object *)0x0)) &&
                  ((instance_00->object->oflags2 & 0x40000U) != 0)) &&
                 (instance_00->LinkParent == (_Instance *)0x0)) &&
                (((Message = CheckPhysObAbility(instance_00, 0), Message != 0 ||
                                                                     (Message = CheckPhysObAbility(instance_00, 3), Message != 0)) &&
                  (lVar4 = MATH3D_LengthXY((int)(instance_00->position).x -
                                               (int)(instance->position).x,
                                           (int)(instance_00->position).y -
                                               (int)(instance->position).y,
                                           (int)(instance_00->position).z -
                                               (int)(instance->position).z),
                   lVar4 < Data))))
            {
              instance_01 = instance_00;
              Data = lVar4;
            }
            instance_00 = instance_00->next;
          }
        }
        else
        {
          instance_01 = INSTANCE_Deactivate(puVar10[0x35]);
        }
        if (instance_01 != (_Instance *)0x0)
        {
          G2Anim_DisableSegment(&instance->anim, (u_int) * (byte *)((int)instance->data + 0x25));
          Data = CheckPhysObAbility(instance_01, 3);
          if (Data == 0)
          {
            local_70 = 3;
            Data = SetObjectBreakOffData(0, 0, 0, instance, 3);
            Message = 0x800002;
          }
          else
          {
            local_70 = 0;
            local_6c = 0;
            local_68 = 1;
            Data = SetObjectThrowData(instance, 3, 0, 0, 0, 0, 1);
            Message = 0x800023;
          }
          INSTANCE_Query(instance_01, Message, Data);
          introUniqueID = instance_01->introUniqueID;
          *(_Instance **)(puVar10 + 0x34) = instance_01;
          puVar10[0x35] = introUniqueID;
          instance->flags2 = instance->flags2 & 0xffffff7f;
        }
      }
      else
      {
        if ((*(char *)(puVar10 + 0x55) == '\x03') && ((*puVar10 & 0x400) == 0))
        {
          local_60.vx = (instance->position).x;
          local_60.vy = (instance->position).y;
          local_60.vz = (instance->position).z;
          _Stack80.newPoint = &local_60;
          _Stack80.oldPoint = &local_58;
          local_58.vz = (instance->position).z + 0x200;
          local_58.vx = local_60.vx;
          local_58.vy = local_60.vy;
          PHYSICS_CheckLineInWorld(instance, &_Stack80);
          if (instance->waterFace == (_TFace *)0x0)
          {
            bVar2 = true;
            *(undefined *)(puVar10 + 0x55) = 7;
          }
        }
      }
    }
  }
  if (((*puVar10 & 0x400000) != 0) && (uVar5 = MON_GetAnim(instance), puVar10[0x46] < uVar5))
  {
    *puVar10 = *puVar10 & 0xffbfffff;
    FX_UpdateGlowEffect(instance, 0x40);
  }
  MON_ApplyPhysics(instance);
  Data = MON_OnGround(instance);
  if (Data != 0)
  {
    *puVar10 = *puVar10 | 2;
  }
  while (p_Var6 = PurgeMessageQueue((__MessageQueue *)(puVar10 + 2)), p_Var6 != (__Event *)0x0)
  {
    puVar7 = (undefined *)p_Var6->ID;
    if (puVar7 == (undefined *)0x100000d)
    {
      pvVar8 = instance->data;
      if ((p_Var6->Data != 0) && ('\x02' < *(char *)((int)pvVar8 + 0x28)))
      {
        *(undefined *)((int)puVar10 + 0x15a) = 2;
        *puVar10 = *puVar10 | 0x10000000;
        puVar10[0x59] = *(u_int *)(*(int *)((int)pvVar8 + 0x30) + 8);
      }
      *(undefined *)(puVar10 + 0x55) = 0;
      puVar10[0x36] = 0;
      *puVar10 = *puVar10 & 0xffdfdd7f;
      puVar10[1] = puVar10[1] & 0xb8080000;
      MON_TurnOffBodySpheres(instance);
      MON_TurnOnWeaponSpheres(instance);
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_ffffff9c, CONCAT48(local_68, CONCAT44(local_6c, local_70))), 0x17);
      if (instance->perVertexColor != (CVECTOR *)0x0)
      {
        MEMPACK_Init((char *)instance->perVertexColor);
        instance->perVertexColor = (CVECTOR *)0x0;
      }
      if ((instance->object->oflags & 0x200U) != 0)
      {
        instance->flags2 = instance->flags2 | 0x40;
      }
    }
    else
    {
      if ((int)puVar7 < 0x100000e)
      {
        if (puVar7 == (undefined *)0x100000b)
        {
          instance->xAccl = 0;
          instance->yAccl = 0;
          instance->zAccl = -0x10;
        }
      }
      else
      {
        if (puVar7 == &DAT_0100001b)
        {
          puVar10[0x35] = 0;
          bVar2 = true;
        }
      }
    }
  }
  if (!bVar2)
  {
    return;
  }
  if (instance_02 == (_Instance *)0x0)
  {
    return;
  }
  if ((instance_02->flags2 & 0x8000000U) != 0)
  {
    MON_KillMonster(instance_02);
    uVar5 = INSTANCE_Post(instance_02, 1);
    instance_02 = instance;
    if ((uVar5 & 0x1000) != 0)
    {
      Data = 1;
      goto LAB_800879d4;
    }
  }
  Data = 0;
LAB_800879d4:
  INSTANCE_Query(instance_02, 0x100000d, Data);
  return;
}

void MON_MissileHitEntry(_Instance *instance)

{
  int Data;
  u_char unaff_s0;
  u_char unaff_s1;
  u_int *puVar1;
  void *pvVar2;
  u_char local_18;
  u_char in_stack_ffffffec;

  pvVar2 = instance->data;
  puVar1 = (u_int *)instance->extraData;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->xVel = 0;
  instance->yVel = 0;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_s1, CONCAT48(unaff_s0, CONCAT44(in_stack_ffffffec, local_18))),
               0x19);
  *puVar1 = *puVar1 & 0xffffffef | 0x200000;
  MON_TurnOffWeaponSpheres(instance);
  *(undefined *)(puVar1 + 0x55) = 0;
  MON_DropAllObjects(instance);
  G2Anim_DisableSegment(&instance->anim, (u_int) * (byte *)((int)pvVar2 + 0x25));
  puVar1[0x35] = *(u_int *)(puVar1[0x34] + 0x3c);
  Data = SetObjectBreakOffData(0, 0, 0, instance, 3);
  INSTANCE_Query((_Instance *)puVar1[0x34], 0x800002, Data);
  SOUND_Play3dSound(&instance->position, 0x27, -100, 100, (int)&DAT_00003e80);
  return;
}

void MON_MissileHit(_Instance *instance)

{
  int iVar1;
  int iVar2;
  __Event *p_Var3;
  u_char local_18;
  void *pvVar4;
  u_char local_14;
  void *pvVar5;

  pvVar5 = instance->extraData;
  pvVar4 = instance->data;
  iVar1 = G2EmulationInstanceQueryAnimation(instance, 0);
  iVar2 = G2EmulationInstanceQueryLastFrame(instance, 0);
  if ((iVar2 < (int)(u_int) * (byte *)((int)pvVar4 + 0x26)) &&
      ((int)(u_int) * (byte *)((int)pvVar4 + 0x26) <= iVar1))
  {
    FX_Blood_Impale(instance, (u_short) * (byte *)((int)pvVar4 + 0x25), instance,
                    (u_short) * (byte *)((int)pvVar4 + 0x25));
  }
  else
  {
    if ((iVar2 < (int)(u_int) * (byte *)((int)pvVar4 + 0x27)) &&
        ((int)(u_int) * (byte *)((int)pvVar4 + 0x27) <= iVar1))
    {
      FX_Blood(instance, (u_short) * (byte *)((int)pvVar4 + 0x25), 0x50);
    }
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  }
  do
  {
    p_Var3 = PurgeMessageQueue((__MessageQueue *)((int)pvVar5 + 8));
  } while (p_Var3 != (__Event *)0x0);
  return;
}

void MON_BirthSoul(_Instance *instance)

{
  return;
}

void MON_Birth(_Instance *instance)

{
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_fffffffc, unaff_retaddr));
  return;
}

void MON_ParryEntry(_Instance *instance)

{
  u_char unaff_s0;
  void *pvVar1;
  u_char unaff_s1;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  pvVar1 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 9);
  MON_MoveToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c),
                     0x1000);
  return;
}

void MON_Parry(_Instance *instance)

{
  u_char unaff_s0;
  u_char unaff_retaddr;

  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_retaddr, unaff_s0));
  }
  MON_DefaultMessageHandler(instance);
  return;
}

void MON_LandOnFeetEntry(_Instance *instance)

{
  int mode;
  int damage;
  u_char unaff_s0;
  u_char unaff_retaddr;
  undefined8 uStackX0;

  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  mode = 0x12;
  if (*(char *)((int)instance->extraData + 0x155) == '\v')
  {
    mode = 0x15;
  }
  MON_PlayAnim(instance, (MonsterAnim)CONCAT88(uStackX0, CONCAT44(unaff_retaddr, unaff_s0)), mode);
  mode = instance->zVel;
  if (mode < -0x65)
  {
    damage = 0x1000;
    if ((mode < -0xf6) && (damage = 0x3000, -0x15e < mode))
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

void MON_LandOnFeet(_Instance *instance)

{
  u_char local_10;
  u_int *puVar1;
  u_char local_c;
  u_char local_8;
  u_char in_stack_fffffffc;

  puVar1 = (u_int *)instance->extraData;
  MON_DefaultMessageHandler(instance);
  if ((instance->currentMainState == 0x10) &&
      ((*(short *)(puVar1 + 0x54) == 0x20 || (*(short *)(puVar1 + 0x54) == 0x40))))
  {
    MON_BurnInAir(instance, 0xf);
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_AnimPlaying(instance, (MonsterAnim)
                                  CONCAT412(in_stack_fffffffc,
                                            CONCAT48(local_8, CONCAT44(local_c, local_10))));
    if (((*puVar1 & 0x2000) == 0) || (*(short *)(puVar1 + 0x50) != 0))
    {
      if (((*puVar1 & 0x400000) == 0) && (*(short *)(puVar1 + 0x50) == 0))
      {
        *puVar1 = *puVar1 & 0xfffffeff;
      }
    }
    else
    {
      *(undefined2 *)(puVar1 + 0x54) = 0x4000;
    }
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  return;
}

void MON_LandOnFeetEntry(_Instance *instance)

{
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}

void MON_LandInWaterEntry(_Instance *instance)

{
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_fffffffc, unaff_retaddr));
  return;
}

void MON_BreakHoldEntry(_Instance *instance)

{
  u_char unaff_s0;
  void *pvVar1;
  u_char unaff_s1;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  pvVar1 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0xf);
  *(u_char *)((int)pvVar1 + 0x108) = 0x100000;
  if ((instance->object->oflags & 0x200U) != 0)
  {
    instance->flags2 = instance->flags2 | 0x40;
  }
  return;
}

void MON_BreakHold(_Instance *instance)

{
  if ((instance->flags2 & 0x10U) == 0)
  {
    MON_DefaultMessageHandler(instance);
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

void MON_ImpactEntry(_Instance *instance)

{
  short sVar1;
  u_long uVar2;
  u_char unaff_s0;
  u_char unaff_s1;
  u_int *puVar3;
  u_char unaff_s2;
  int iVar4;
  u_char unaff_retaddr;

  puVar3 = (u_int *)instance->extraData;
  iVar4 = *(int *)(puVar3[0x59] + 8);
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_retaddr, CONCAT48(unaff_s2, CONCAT44(unaff_s1, unaff_s0))), 0x11);
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  uVar2 = MON_GetAnim(instance);
  sVar1 = *(short *)(iVar4 + 2);
  puVar3[0x42] = 0x100000;
  puVar3[0x43] = uVar2 + (int)sVar1;
  *puVar3 = *puVar3 | 0x10;
  MON_TakeDamage(instance, 0x1000, 0x40000);
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}

void MON_ImpactEntry(_Instance *instance)

{
  short sVar1;
  u_char unaff_s0;
  u_char unaff_s1;
  void *pvVar2;

  pvVar2 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  }
  MON_DefaultMessageHandler(instance);
  if ((instance->currentMainState == 0x10) &&
      ((sVar1 = *(short *)((int)pvVar2 + 0x150), sVar1 == 0x20 || (sVar1 == 0x40))))
  {
    MON_BurnInAir(instance, 0xc);
  }
  return;
}

void MON_Fall(_Instance *instance)

{
  char cVar1;
  int mode;
  u_char local_10;
  u_char local_c;
  void *pvVar2;
  u_char local_8;
  u_char in_stack_fffffffc;

  pvVar2 = instance->extraData;
  cVar1 = *(char *)((int)pvVar2 + 0x155);
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
  *(u_char *)((int)pvVar2 + 0x108) = 0x100000;
  return;
}

void MON_Fall(_Instance *instance)

{
  __Event *message;
  u_char unaff_s0;
  u_char unaff_s1;
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  if ((*puVar1 & 2) == 0)
  {
    if ((*puVar1 & 0x400) == 0)
    {
      MON_ApplyPhysics(instance);
    }
    else
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
    }
  }
  else
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  }
  while (message = PurgeMessageQueue((__MessageQueue *)(puVar1 + 2)), message != (__Event *)0x0)
  {
    if (message->ID != 0x1000007)
    {
      MON_PupateMessageHandler(instance, message);
    }
  }
  if ((instance->currentMainState == 0x10) &&
      ((*(short *)(puVar1 + 0x54) == 0x20 || (*(short *)(puVar1 + 0x54) == 0x40))))
  {
    MON_BurnInAir(instance, 4);
  }
  return;
}

void MON_ThrownEntry(_Instance *instance)

{
  u_char unaff_s0;
  u_char unaff_s1;
  u_int *puVar1;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  puVar1 = (u_int *)instance->extraData;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = -8;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x10);
  puVar1[0x42] = 0x100000;
  if ((instance->object->oflags & 0x200U) != 0)
  {
    instance->flags2 = instance->flags2 | 0x40;
  }
  instance->checkMask = instance->checkMask | 0x20;
  *puVar1 = *puVar1 & 0xfffffffd;
  return;
}

void MON_Thrown(_Instance *instance)

{
  Level *pLVar1;
  Intro *pIVar2;
  __Event *message;
  int iVar3;
  u_char local_10;
  u_char local_c;
  u_int *puVar4;

  puVar4 = (u_int *)instance->extraData;
  if ((*puVar4 & 2) == 0)
  {
    MON_ApplyPhysics(instance);
    while (message = PurgeMessageQueue((__MessageQueue *)(puVar4 + 2)), message != (__Event *)0x0)
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
          MON_PupateMessageHandler(instance, message);
        }
      }
    }
    if ((instance->currentMainState == 0x10) &&
        ((*(short *)(puVar4 + 0x54) == 0x20 || (*(short *)(puVar4 + 0x54) == 0x40))))
    {
      MON_BurnInAir(instance, 0xb);
    }
  }
  else
  {
    pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
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
      INSTANCE_Query(instance, 0x100001c, pIVar2->UniqueID);
      MON_DefaultMessageHandler(instance);
    }
  }
  return;
}

void MON_ImpaleDeathEntry(_Instance *instance)

{
  u_long uVar1;
  u_char unaff_s0;
  u_char unaff_s1;
  u_int *puVar2;
  u_char unaff_s2;
  void *pvVar3;
  u_char unaff_retaddr;

  puVar2 = (u_int *)instance->extraData;
  pvVar3 = instance->data;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_retaddr, CONCAT48(unaff_s2, CONCAT44(unaff_s1, unaff_s0))), 0xd);
  *puVar2 = *puVar2 & 0xffffffef | 0x200000;
  MON_TurnOffWeaponSpheres(instance);
  G2Anim_DisableSegment(&instance->anim, (u_int) * (byte *)((int)pvVar3 + 0x25));
  uVar1 = MON_GetAnim(instance);
  *(undefined **)(puVar2 + 0x45) = &DAT_00007530 + uVar1;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->xVel = 0;
  instance->yVel = 0;
  MON_DropAllObjects(instance);
  return;
}

void MON_ImpaleDeath(_Instance *instance)

{
  int Data;
  int iVar1;
  u_long uVar2;
  __Event *p_Var3;
  u_char local_18;
  u_int *puVar4;
  u_char local_14;
  void *pvVar5;
  u_char local_20;
  u_char uVar6;
  u_char in_stack_ffffffe4;

  puVar4 = (u_int *)instance->extraData;
  pvVar5 = instance->data;
  Data = MON_AnimPlaying(instance, (MonsterAnim)
                                       CONCAT412(local_14, CONCAT48(local_18, CONCAT44(in_stack_ffffffe4,
                                                                                       local_20))));
  if (Data != 0)
  {
    Data = G2EmulationInstanceQueryAnimation(instance, 0);
    iVar1 = G2EmulationInstanceQueryLastFrame(instance, 0);
    if ((iVar1 < (int)(u_int) * (byte *)((int)pvVar5 + 0x26)) &&
        ((int)(u_int) * (byte *)((int)pvVar5 + 0x26) <= Data))
    {
      FX_Blood_Impale(instance, (u_short) * (byte *)((int)pvVar5 + 0x25), instance,
                      (u_short) * (byte *)((int)pvVar5 + 0x25));
    }
    else
    {
      if ((iVar1 < (int)(u_int) * (byte *)((int)pvVar5 + 0x27)) &&
          ((int)(u_int) * (byte *)((int)pvVar5 + 0x27) <= Data))
      {
        FX_Blood(instance, (u_short) * (byte *)((int)pvVar5 + 0x25), 0x50);
      }
    }
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    Data = MON_AnimPlaying(instance, (MonsterAnim)
                                         CONCAT412(local_14, CONCAT48(local_18, CONCAT44(in_stack_ffffffe4,
                                                                                         local_20))));
    if ((Data == 0) ||
        (*(char *)(*(int *)puVar4[0x59] + 0xd) == *(char *)(*(int *)puVar4[0x59] + 0x16)))
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffe4, local_20));
    }
    else
    {
      uVar2 = MON_GetAnim(instance);
      puVar4[0x45] = uVar2 + 1000;
    }
  }
  uVar2 = MON_GetAnim(instance);
  if (puVar4[0x45] < uVar2)
  {
    *puVar4 = *puVar4 & 0xffdfffff;
    MON_TurnOnWeaponSphere(instance);
    MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffe4, local_20));
  }
  while (p_Var3 = PurgeMessageQueue((__MessageQueue *)(puVar4 + 2)), p_Var3 != (__Event *)0x0)
  {
    if (p_Var3->ID == 0x100000a)
    {
      uVar2 = MON_GetAnim(instance);
      *(undefined **)(puVar4 + 0x45) = &DAT_00007530 + uVar2;
      puVar4[0x35] = *(u_int *)(puVar4[0x34] + 0x3c);
      uVar6 = 3;
      Data = SetObjectBreakOffData(0, 0, 0, instance, 3);
      INSTANCE_Query((_Instance *)puVar4[0x34], 0x800002, Data);
      INSTANCE_Query((_Instance *)puVar4[0x34], 0x200003, 7);
      *(undefined *)(puVar4 + 0x55) = 0;
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_14, CONCAT48(local_18, CONCAT44(in_stack_ffffffe4, uVar6))), 0x16);
    }
  }
  return;
}

void MON_Impact(_Instance *instance)

{
  Intro *pIVar1;
  u_int uVar2;
  int mode;
  u_char local_10;
  void *pvVar3;
  u_char local_c;
  u_char local_8;
  u_int *puVar4;
  u_char local_4;

  puVar4 = (u_int *)instance->extraData;
  pvVar3 = instance->data;
  *puVar4 = *puVar4 & 0xffffffef | 0x200000;
  MON_TurnOffWeaponSpheres(instance);
  MON_DropAllObjects(instance);
  G2Anim_DisableSegment(&instance->anim, (u_int) * (byte *)((int)pvVar3 + 0x25));
  FX_Blood(instance, (u_short) * (byte *)((int)pvVar3 + 0x25), 0x50);
  *puVar4 = *puVar4 | 0x800;
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  if ((int)puVar4[0x68] < 0)
  {
    pIVar1 = MON_FindNearestImpalingIntro(instance->currentStreamUnitID, &instance->position);
    puVar4[0x68] = pIVar1->UniqueID;
    MON_MoveInstanceToImpalePoint(instance);
  }
  else
  {
    pIVar1 = INSTANCE_FindIntro(instance->currentStreamUnitID, puVar4[0x68]);
  }
  if ((pIVar1 == (Intro *)0x0) ||
      (pIVar1->flags = pIVar1->flags & 0xffff7fff, pIVar1 == (Intro *)0x0))
  {
  LAB_800887d0:
    mode = 0x1f;
  }
  else
  {
    uVar2 = (u_int)(u_short)(pIVar1->rotation).x & 0xfff;
    if (uVar2 < 0x801)
    {
      if (0x2a9 < uVar2)
      {
        mode = 0x1f;
        goto LAB_800887d8;
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
        goto LAB_800887d0;
    }
    mode = 0x20;
  }
LAB_800887d8:
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10))), mode);
  *(undefined *)(puVar4 + 0x55) = 0;
  return;
}

void MON_TerrainImpaleDeathEntry(_Instance *instance)

{
  u_long uVar1;
  _Instance *p_Var2;
  Intro *pIVar3;
  __Event *p_Var4;
  u_int uVar5;
  void *pvVar6;
  u_int *puVar7;

  puVar7 = (u_int *)instance->extraData;
  if ((*puVar7 & 0x200) == 0)
  {
    MON_MoveInstanceToImpalePoint(instance);
    if ((instance->flags2 & 0x10U) != 0)
    {
      if ((puVar7[0x31] != 0) &&
          (uVar1 = INSTANCE_Post(*(_Instance **)(puVar7[0x31] + 4), 1), (uVar1 & 1) != 0))
      {
        MON_ChangeHumanOpinion(instance);
      }
      *puVar7 = *puVar7 | 0x200;
      instance->flags2 = instance->flags2 & 0xffffffbf;
      if ((puVar7[0x36] == 0) && (*(short *)(puVar7 + 0x51) != 0))
      {
        MON_BirthMana(instance, 1);
      }
    }
  }
  else
  {
    if (puVar7[0x36] == 0)
    {
      pvVar6 = instance->data;
      uVar1 = MON_GetAnim(instance);
      uVar5 = puVar7[0x43];
      MON_CutOut_Monster(instance, uVar1 - uVar5, (u_int) * (byte *)((int)pvVar6 + 0x19),
                         (u_int) * (byte *)((int)pvVar6 + 0x21));
      if (0xfff < (int)(uVar1 - uVar5))
      {
        pIVar3 = INSTANCE_FindIntro(instance->currentStreamUnitID, puVar7[0x68]);
        if (pIVar3 != (Intro *)0x0)
        {
          pIVar3->flags = pIVar3->flags | 0x8000;
        }
        MON_KillMonster(instance);
      }
    }
    else
    {
      p_Var2 = INSTANCE_Deactivate(puVar7[0x36]);
      if (p_Var2 == (_Instance *)0x0)
      {
        MON_MoveInstanceToImpalePoint(instance);
        MON_BirthMana(instance, 1);
      }
    }
    if (((*puVar7 & 0x400000) != 0) && (uVar1 = MON_GetAnim(instance), puVar7[0x46] < uVar1))
    {
      *puVar7 = *puVar7 & 0xffbfffff;
      FX_UpdateGlowEffect(instance, 0x40);
    }
    do
    {
      p_Var4 = PurgeMessageQueue((__MessageQueue *)(puVar7 + 2));
    } while (p_Var4 != (__Event *)0x0);
  }
  return;
}

void MON_Surprised(_Instance *instance)

{
  u_long uVar1;
  u_char unaff_s0;
  u_char unaff_s1;
  void *pvVar2;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  pvVar2 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1a);
  uVar1 = MON_GetAnim(instance);
  *(int *)((int)pvVar2 + 0x114) =
      uVar1 + (int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x164) + 8) + 6);
  return;
}

void MON_SurprisedEntry(_Instance *instance)

{
  u_long uVar1;
  u_char local_10;
  void *pvVar2;
  u_char local_c;

  pvVar2 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_PlayCombatIdle(instance, 2);
  }
  uVar1 = MON_GetAnim(instance);
  if (*(u_int *)((int)pvVar2 + 0x114) < uVar1)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  if (*(int *)((int)pvVar2 + 0xc4) != 0)
  {
    *(int *)((int)pvVar2 + 0x11c) = *(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c;
    MON_MoveToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x5c),
                       *(short *)(*(int *)((int)pvVar2 + 0x164) + 0x1c));
  }
  MON_DefaultMessageHandler(instance);
  return;
}

void MON_Stunned(_Instance *instance)

{
  short sVar1;
  int mode;
  u_long uVar2;
  u_char local_10;
  u_int *puVar3;
  u_char local_c;
  u_char local_8;
  short *psVar4;
  u_char local_4;

  puVar3 = (u_int *)instance->extraData;
  psVar4 = *(short **)(puVar3[0x59] + 8);
  if ((*puVar3 & 0x40) == 0)
  {
    if ((*puVar3 & 0x100) != 0)
      goto LAB_80088c18;
    sVar1 = *(short *)(puVar3 + 0x54);
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
        mode = 5;
      }
    }
  }
  else
  {
    *(u_short *)(puVar3[0x31] + 0x18) = *(u_short *)(puVar3[0x31] + 0x18) | 0x400;
    *(u_short *)(puVar3[0x31] + 0x16) = *(u_short *)(puVar3[0x31] + 0x16) & 0xefff;
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
LAB_80088c18:
  *puVar3 = *puVar3 | 0x10110;
  uVar2 = MON_GetAnim(instance);
  puVar3[0x43] = uVar2 + (int)psVar4[1];
  if ((*(short *)(puVar3 + 0x54) == 0x40) && (*(char *)(puVar3[0x59] + 0x38) != '\0'))
  {
    uVar2 = MON_GetAnim(instance);
    mode = (int)*psVar4 << 1;
  }
  else
  {
    uVar2 = MON_GetAnim(instance);
    mode = (int)*psVar4;
  }
  puVar3[0x44] = uVar2 + mode;
  puVar3[0x42] = 0x8000;
  instance->checkMask = instance->checkMask | 0x20;
  return;
}

void HUMAN_StunnedEntry(_Instance *instance)

{
  u_long uVar1;
  int iVar2;
  u_char local_10;
  u_char local_c;
  u_int *puVar3;
  u_char local_8;
  u_char in_stack_fffffffc;

  puVar3 = (u_int *)instance->extraData;
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
  uVar1 = MON_GetAnim(instance);
  if (puVar3[0x45] < uVar1)
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
  MON_DefaultMessageHandler(instance);
  PHYSICS_StopIfCloseToTarget(instance, 0, 0, 0);
  PhysicsDefaultLinkedMoveResponse(instance, &instance->position, gameTrackerX.timeMult);
  if (instance->currentMainState != 9)
  {
    instance->checkMask = instance->checkMask & 0xffffffdf;
  }
  return;
}

void MON_GrabbedEntry(_Instance *instance)

{
  u_long uVar1;
  u_char unaff_s0;
  u_char unaff_s1;
  void *pvVar2;
  u_char unaff_s2;
  void *pvVar3;
  u_char unaff_retaddr;

  pvVar2 = instance->extraData;
  pvVar3 = instance->data;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_retaddr, CONCAT48(unaff_s2, CONCAT44(unaff_s1, unaff_s0))), 4);
  instance->flags2 = instance->flags2 & 0xffffffbf;
  uVar1 = MON_GetAnim(instance);
  *(int *)((int)pvVar2 + 0x114) =
      uVar1 + (int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x164) + 8) + 8);
  G2Anim_DisableSegment(&instance->anim, (u_int) * (byte *)((int)pvVar3 + 0x25));
  INSTANCE_LinkToParent(instance, gameTrackerX.playerInstance, 0x31);
  (instance->rotation).z = *(short *)(*(int *)(*(int *)((int)pvVar2 + 0xc4) + 4) + 0x78) + 0x800;
  *(undefined2 *)((int)pvVar2 + 0x126) = 0;
  instance->checkMask = instance->checkMask | 0x20;
  return;
}

void MON_Grabbed(_Instance *instance)

{
  short sVar1;
  u_long uVar2;
  __Event *message;
  int iVar3;
  u_char local_18;
  int *piVar4;
  u_char local_14;
  u_char unaff_s2;
  void *pvVar5;
  u_char unaff_s3;
  void *pvVar6;

  pvVar5 = instance->extraData;
  pvVar6 = instance->data;
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(unaff_s3, CONCAT48(unaff_s2, CONCAT44(local_14, local_18))), 0xe);
  }
  uVar2 = MON_GetAnim(instance);
  iVar3 = *(int *)((int)pvVar5 + 0x114) - uVar2;
  if (iVar3 < 1)
  {
    uVar2 = INSTANCE_Post(*(_Instance **)(*(int *)((int)pvVar5 + 0xc4) + 4), 10);
    if (uVar2 != 0x20000)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
  }
  else
  {
    GAMEPAD_HandleDualShock

                      (int)*(short *)(*(int *)(*(int *)((int)pvVar5 + 0x164) + 8) + 8),0xf000);
  }
  (instance->rotation).z = *(short *)(*(int *)(*(int *)((int)pvVar5 + 0xc4) + 4) + 0x78) + 0x800;
LAB_80088fa8:
  do
  {
    while (true)
    {
      message = PurgeMessageQueue((__MessageQueue *)((int)pvVar5 + 8));
      if (message == (__Event *)0x0)
      {
        if (instance->LinkParent == (_Instance *)0x0)
        {
          if ((instance->currentMainState == 10) && (*(short *)((int)pvVar5 + 0x126) != 0))
          {
            G2Anim_EnableSegment(&instance->anim, (u_int) * (byte *)((int)pvVar6 + 0x25));
            MON_TurnOnWeaponSphere(instance);
            MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
            (instance->rotation).z = ((gameTrackerX.playerInstance)->rotation).z + 0x800;
          }
          (instance->rotation).x = 0;
          (instance->rotation).y = 0;
        }
        else
        {
          *(undefined2 *)((int)pvVar5 + 0x126) = 1;
        }
        if (((instance->LinkParent != (_Instance *)0x0) && (instance->currentMainState != 10)) &&
            (instance->currentMainState != 0xe))
        {
          MON_UnlinkFromRaziel(instance);
        }
        return;
      }
      iVar3 = message->ID;
      if (iVar3 != 0x1000003)
        break;
      piVar4 = (int *)message->Data;
      INSTANCE_UnlinkFromParent(instance);
      (instance->rotation).x = *(short *)(piVar4 + 1);
      (instance->rotation).y = *(short *)((int)piVar4 + 6);
      sVar1 = *(short *)(piVar4 + 2);
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = -8;
      (instance->rotation).z = sVar1 + 0x800;
      iVar3 = MON_SetVelocityTowardsImpalingObject(instance, (u_int)(*piVar4 != 0));
      if (iVar3 == 0)
      {
        PhysicsSetVelFromZRot(instance, *(short *)(piVar4 + 2), (int)*(short *)(piVar4 + 3));
        instance->zVel = 0x32;
      }
      G2Anim_EnableSegment(&instance->anim, (u_int) * (byte *)((int)pvVar6 + 0x25));
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
      GAMEPAD_HandleDualShock(0, 0);
    }
    if (0x1000003 < iVar3)
      goto LAB_80088fe8;
  } while (iVar3 == 0x1000002);
  goto LAB_80089098;
LAB_80088fe8:
  if (iVar3 != 0x100000b)
  {
  LAB_80089098:
    MON_PupateMessageHandler(instance, message);
  }
  goto LAB_80088fa8;
}

void MON_HitEntry(_Instance *instance)

{
  int iVar1;
  u_int uVar2;
  u_char local_10;
  u_int *puVar3;
  u_char local_c;
  u_char local_8;
  u_char in_stack_fffffffc;

  puVar3 = (u_int *)instance->extraData;
  uVar2 = puVar3[0x31];
  *(u_short *)(uVar2 + 0x16) = *(u_short *)(uVar2 + 0x16) & 0xefff;
  *(u_short *)(uVar2 + 0x18) = *(u_short *)(uVar2 + 0x18) | 0x400;
  *puVar3 = *puVar3 | 0x10000;
  iVar1 = MON_SetUpKnockBack(instance, *(_Instance **)(uVar2 + 4), (evMonsterHitData *)puVar3[0x30]);
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
               (u_int)(iVar1 == 0));
  puVar3[0x42] = 0x8000;
  instance->checkMask = instance->checkMask | 0x20;
  return;
}

void MON_HitEntry(_Instance *instance)

{
  u_long uVar1;
  u_char local_10;
  u_char local_c;
  void *pvVar2;

  pvVar2 = instance->extraData;
  uVar1 = MON_GetAnim(instance);
  if (*(u_int *)((int)pvVar2 + 0x114) < uVar1)
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
  MON_DefaultMessageHandler(instance);
  PHYSICS_StopIfCloseToTarget(instance, 0, 0, 0);
  PhysicsDefaultLinkedMoveResponse(instance, &instance->position, gameTrackerX.timeMult);
  if (instance->currentMainState != 8)
  {
    instance->checkMask = instance->checkMask & 0xffffffdf;
  }
  return;
}

void MON_Attack(_Instance *instance)

{
  u_long uVar1;
  void *pvVar2;
  int iVar3;

  pvVar2 = instance->extraData;
  iVar3 = *(int *)((int)pvVar2 + 0xb8);
  *(u_char *)((int)pvVar2 + 0x108) = 0x200000;
  MON_PlayAnimFromListIfNotPlaying(instance, (char *)(iVar3 + 0x1b), 0, 1);
  uVar1 = MON_GetAnim(instance);
  *(int *)((int)pvVar2 + 0x114) = uVar1 + (int)*(char *)(iVar3 + 0xd) * 0x21;
  return;
}

void MON_ChooseAttack(_Instance *instance)

{
  char cVar1;
  _MonsterAnim *p_Var2;
  int iVar3;
  u_long uVar4;
  u_char local_18;
  u_int uVar5;
  u_char local_14;
  u_int *puVar6;
  u_int uVar7;

  puVar6 = (u_int *)instance->extraData;
  uVar5 = puVar6[0x2e];
  uVar7 = puVar6[0x31];
  p_Var2 = MON_GetTime(instance, (char *)(uVar5 + 0x1b), (int)*(char *)((int)puVar6 + 0x15b));
  if ((p_Var2->velocity != 0) && (iVar3 = MON_TransNodeAnimation(instance), iVar3 == 0))
  {
    *(u_short *)((int)puVar6 + 0x126) = p_Var2->velocity;
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
      MON_TurnOnWeaponSpheres(instance);
      *(u_short *)(uVar7 + 0x18) = *(u_short *)(uVar7 + 0x18) | 0x200;
    }
  }
  else
  {
    MON_TurnOffAllSpheres(instance, (int)*(char *)(uVar5 + 8));
  }
  if ((instance->flags2 & 0x10U) != 0)
  {
    instance->flags2 = instance->flags2 & 0xffffffef;
    cVar1 = *(char *)((int)puVar6 + 0x15b) + '\x01';
    *(char *)((int)puVar6 + 0x15b) = cVar1;
    if ((int)cVar1 < (int)*(char *)(uVar5 + 0xe))
    {
      MON_PlayAnimFromListIfNotPlaying(instance, (char *)(uVar5 + 0x1b), (int)cVar1, 1);
    }
    else
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
  }
  if ((uVar7 != 0) &&
      ((uVar4 = MON_GetAnim(instance), uVar4 < puVar6[0x45] ||
                                           (uVar4 = INSTANCE_Post(*(_Instance **)(uVar7 + 4), 10), (uVar4 & 0x2000000) == 0))))
  {
    MON_MoveToPosition(instance, (_Position *)(*(int *)(uVar7 + 4) + 0x5c),
                       *(short *)(puVar6[0x59] + 0x1c));
  }
  MON_DefaultMessageHandler(instance);
  return;
}

void MON_CombatEntry(_Instance *instance)

{
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  puVar1[0x42] = 0x2000000;
  *puVar1 = *puVar1 & 0xfffbffff | 0x10000;
  return;
}

void wombat(_Instance *instance)

{
  int reason;
  _MonsterAttackAttributes *attack;
  u_char local_18;
  u_int *puVar1;
  u_char local_14;
  u_char local_10;
  int iVar2;
  u_char local_c;
  _MonsterIR *enemy;

  puVar1 = (u_int *)instance->extraData;
  enemy = (_MonsterIR *)puVar1[0x31];
  if ((((enemy != (_MonsterIR *)0x0) && ((*puVar1 & 4) == 0)) &&
       (((*puVar1 & 0x10000000) == 0 || ((enemy->mirFlags & 0x1000) == 0)))) &&
      (reason = MON_ValidPosition(instance), reason != 0))
  {
    iVar2 = *(int *)(puVar1[0x59] + 8);
    *(_Position **)(puVar1 + 0x47) = &enemy->instance->position;
    reason = MON_ShouldIEvade(instance);
    if ((reason == 0) &&
        ((enemy->distance < *(short *)(iVar2 + 10) || (*(char *)((int)puVar1 + 0x156) == '\n'))))
    {
      if (((*puVar1 & 0x20000) != 0) && ((instance->flags2 & 0x12U) != 0))
      {
        *puVar1 = *puVar1 & 0xbffdffff;
      }
      reason = MON_ShouldIFlee(instance);
      if (reason == 0)
      {
        if ((*puVar1 & 0x40000000) == 0)
        {
          if (*(char *)((int)puVar1 + 0x156) == '\n')
          {
            reason = MON_ShouldIAttack(instance, enemy);
          }
          else
          {
            attack = MON_Attack(instance, enemy);
            reason = MON_ShouldIAttackInstance(instance, enemy, attack);
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
              if ((*puVar1 & 0x20000) == 0)
              {
                reason = MON_ChooseCombatMove(instance, reason);
                if (reason == 0)
                {
                  MON_PlayCombatIdle(instance, 2);
                }
                else
                {
                  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14, local_18))), reason);
                  *puVar1 = *puVar1 | 0x20000;
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
          *puVar1 = *puVar1 | 0x40020000;
        }
      }
      MON_MoveToPosition(instance, &enemy->instance->position, *(short *)(puVar1[0x59] + 0x1c));
      goto LAB_80089820;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
LAB_80089820:
  MON_Idle(instance);
  return;
}

void MON_ProjectileEntry(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_PlayAnimFromListIfNotPlaying(instance, (char *)(*(int *)((int)instance->data + 0x3c) + (int)*(char *)(*(int *)(*(int *)((int)pvVar1 + 0x164) + 8) + 0x1a) * 0x10 + 0xe), 0, 1);
  *(undefined *)((int)pvVar1 + 0x15b) = 0;
  return;
}

void MON_ProjectileEntry(_Instance *instance)

{
  char cVar1;
  int iVar2;
  u_char unaff_s0;
  _MonsterMissile *missiledef;
  u_char unaff_s1;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  missiledef = (_MonsterMissile *)(*(int *)((int)instance->data + 0x3c) +
                                   (int)*(char *)(*(int *)(puVar3[0x59] + 8) + 0x1a) * 0x10);
  if (puVar3[0x31] != 0)
  {
    if ((instance->flags2 & 0x10U) == 0)
    {
      iVar2 = MON_AnimPlayingFromList(instance, missiledef->animList, (u_int)missiledef->anim);
      if (((iVar2 != 0) &&
           (iVar2 = G2EmulationInstanceQueryPassedFrame(instance, 0, (u_int)missiledef->frame),
            iVar2 != 0)) &&
          (MISSILE_Birth(instance, missiledef, *(_Instance **)(puVar3[0x31] + 4)),
           missiledef->reload != '\0'))
      {
        *puVar3 = *puVar3 & 0xffffffdf;
      }
      MON_MoveToPosition(instance, (_Position *)(*(int *)(puVar3[0x31] + 4) + 0x5c),
                         *(short *)(puVar3[0x59] + 0x1c));
      goto LAB_800899c0;
    }
    cVar1 = *(char *)((int)puVar3 + 0x15b) + '\x01';
    *(char *)((int)puVar3 + 0x15b) = cVar1;
    if ((int)cVar1 < (int)(u_int)missiledef->numAnims)
    {
      MON_PlayAnimFromListIfNotPlaying(instance, missiledef->animList, (int)cVar1, 1);
      goto LAB_800899c0;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
LAB_800899c0:
  MON_DefaultMessageHandler(instance);
  return;
}

void MON_IdleEntry(_Instance *instance)

{
  u_int uVar1;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  uVar1 = *puVar2;
  *puVar2 = uVar1 & 0xfffbefff;
  puVar2[0x42] = 1;
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

void MON_IdleQueueHandler(_Instance *instance)

{
  bool bVar1;
  int iVar2;
  u_char local_18;
  u_int *puVar3;
  u_char local_14;
  int iVar4;
  u_int uVar5;

  puVar3 = (u_int *)instance->extraData;
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
        if (((u_int) * (byte *)((int)puVar3 + 0x156) - 2 < 2) && ((instance->flags2 & 2U) != 0))
        {
          iVar4 = 5;
        }
      }
      else
      {
        bVar1 = true;
        iVar2 = MON_ShouldIEvade(instance);
        if (iVar2 == 0)
        {
          if ((*(u_short *)(uVar5 + 0x16) & 0x100) == 0)
          {
            if ((*(char *)((int)puVar3 + 0x156) == '\a') &&
                (*(short *)(puVar3 + 0x4e) < *(short *)(uVar5 + 0x14)))
            {
              MON_MoveToPosition(instance, (_Position *)(*(int *)(uVar5 + 4) + 0x5c),
                                 *(short *)(puVar3[0x59] + 0x1c));
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
        puVar3[0x47] = *(int *)(uVar5 + 4) + 0x5c;
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
        (AngleMoveToward(&(instance->rotation).z, *(short *)(puVar3 + 0x49),
                         (short)((int)*(short *)(puVar3[0x59] + 0x1c) * gameTrackerX.timeMult * 0x10 >> 0x10)),
         (instance->rotation).z == *(short *)(puVar3 + 0x49)))
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
  MON_Idle(instance);
  return;
}

void MON_FleeEntry(struct _Instance *instance)
{

  struct _MonsterVars *mv;
}

void MON_Flee(_Instance *instance)

{
  short angle;
  int iVar1;
  u_char local_10;
  u_int *puVar2;
  u_char local_c;

  puVar2 = (u_int *)instance->extraData;
  if (puVar2[0x31] == 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    *(undefined *)((int)puVar2 + 0x156) = *(undefined *)((int)puVar2 + 0x157);
    return;
  }
  if ((((*puVar2 & 0x2000000) == 0) || (puVar2[0x33] == 0)) ||
      (*(short *)(puVar2[0x31] + 0x14) <= *(short *)(puVar2[0x33] + 0x14)))
  {
    if (*(short *)(puVar2[0x59] + 0x1a) < *(short *)(puVar2[0x31] + 0x14))
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
      return;
    }
    iVar1 = MON_ValidPosition(instance);
    if (iVar1 != 0)
    {
      angle = MATH3D_AngleFromPosToPos((_Position *)(*(int *)(puVar2[0x31] + 4) + 0x5c), &instance->position);
      angle = MONSENSE_GetDistanceInDirection(instance, angle, 1000);
      AngleMoveToward(&(instance->rotation).z, angle, *(short *)(puVar2[0x59] + 0x22));
      MON_DefaultMessageHandler(instance);
      return;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  return;
}

void MON_HideEntry(_Instance *instance)

{
  u_int uVar1;
  u_char unaff_s0;
  _MonsterVars *mv;
  u_char unaff_s1;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

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
  u_char local_20;
  u_char local_1c;
  _MonsterVars *mv;
  long distance;
  int iVar7;

  mv = (_MonsterVars *)instance->extraData;
  if ((mv->mvFlags & 4) != 0)
  {
    SOUL_QueueHandler(instance);
    return;
  }
  if ((mv->enemy == (_MonsterIR *)0x0) ||
      (((mv->mvFlags & 0x10000000) != 0 && ((mv->enemy->mirFlags & 0x1000) != 0))))
    goto LAB_8008a1b8;
  p_Var6 = mv->subAttr->combatAttributes;
  if (((mv->mvFlags & 0x2000000) == 0) ||
      ((target = mv->ally, target == (_MonsterIR *)0x0 || ((target->mirFlags & 0x200) != 0))))
  {
    target = mv->enemy;
    distance = (int)p_Var6->combatRange + -200;
  }
  else
  {
    distance = (long)p_Var6->allyRange;
  }
  if ((target == (_MonsterIR *)0x0) || (anim = MON_ShouldIAttack(instance, target), anim != 0))
    goto LAB_8008a1b8;
  bVar2 = false;
  sVar1 = (target->instance->position).z;
  *(u_char *)&mv->destination = *(u_char *)&target->instance->position;
  (mv->destination).z = sVar1;
  mv->lookAtPos = &mv->destination;
  anim = MON_ValidPosition(instance);
  if (anim == 0)
  {
    pIVar3 = instance->intro;
    if (pIVar3 == (Intro *)0x0)
    {
      sVar1 = (mv->lastValidPos).z;
      *(u_char *)&mv->destination = *(u_char *)&mv->lastValidPos;
      (mv->destination).z = sVar1;
    }
    else
    {
      sVar1 = (pIVar3->position).z;
      *(u_char *)&mv->destination = *(u_char *)&pIVar3->position;
      (mv->destination).z = sVar1;
    }
  LAB_8008a0d8:
    bVar2 = true;
    distance = 100;
  }
  else
  {
    if (((mv->behaviorState == '\a') && (pIVar3 = instance->intro, pIVar3 != (Intro *)0x0)) &&
        (lVar4 = MATH3D_LengthXY((int)(mv->destination).x - (int)(pIVar3->position).x,
                                 (int)(mv->destination).y - (int)(pIVar3->position).y,
                                 (int)(mv->destination).z - (int)(pIVar3->position).z),
         mv->guardRange < lVar4))
    {
      sVar1 = (instance->intro->position).z;
      *(u_char *)&mv->destination = *(u_char *)&instance->intro->position;
      (mv->destination).z = sVar1;
      goto LAB_8008a0d8;
    }
  }
  anim = MON_CheckPointSuitability(instance, &instance->position, &mv->destination);
  iVar7 = -1;
  if (anim == 0)
    goto LAB_8008a1b8;
  sVar1 = target->distance;
  p_Var5 = MON_GetTime(instance, mv->subAttr->animList, 2);
  anim = 3;
  if ((int)sVar1 < (int)(distance + (u_int)p_Var5->distance))
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
  case 2:
  case 3:
  switchD_8008a164_caseD_2:
    iVar7 = 2;
    break;
  case 4:
    if ((target->mirFlags & 2) == 0)
    {
      iVar7 = 0xd;
      if (bVar2)
        goto switchD_8008a164_caseD_2;
    }
    else
    {
      MON_GetPlanSlot(mv);
    }
  }
  if (iVar7 == -1)
  {
    return;
  }
LAB_8008a1b8:
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
  return;
}

void MON_WanderEntry(_Instance *instance)

{
  u_int uVar1;
  int iVar2;
  u_long uVar3;
  u_char local_10;
  _MonsterVars *mv;
  u_char local_c;
  u_char local_8;
  u_char in_stack_fffffffc;

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
  uVar3 = MON_GetAnim(instance);
  mv->generalTimer = uVar3 + 1000;
  return;
}

void MON_Wander(_Instance *instance)

{
  long lVar1;
  u_long uVar2;
  short *psVar3;
  _StreamUnit *streamUnit;
  u_int uVar4;
  int iVar5;
  _Position *in;
  int iVar6;
  short r;
  u_char local_18;
  u_char local_14;
  u_int *puVar7;

  puVar7 = (u_int *)instance->extraData;
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
        if (*(char *)((int)puVar7 + 0x156) != '\x04')
        {
          uVar4 = rand();
          iVar6 = 2;
          if ((uVar4 & 3) == 0)
          {
            uVar2 = MON_GetAnim(instance);
            puVar7[0x45] = uVar2 + 1000;
            iVar6 = 5;
          }
        }
      }
      if (iVar6 != -1)
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
      }
      goto LAB_8008a4ac;
    }
    uVar2 = MON_GetAnim(instance);
    if (puVar7[0x45] < uVar2)
      goto LAB_8008a310;
    if (*(char *)((int)puVar7 + 0x156) == '\x03')
    {
      psVar3 = (short *)puVar7[0x67];
      if (psVar3 != (short *)0x0)
      {
        r = *psVar3;
        *(short **)(puVar7 + 0x67) = psVar3 + 1;
        streamUnit = STREAM_GetStreamUnitWithID(instance->currentStreamUnitID);
        PLANAPI_FindClosestNodePositionInUnit(streamUnit, (_Position *)(puVar7 + 0x48), (int)r, 0);
        if (*(short *)puVar7[0x67] == 0)
        {
          *(u_int **)(puVar7 + 0x67) = puVar7 + 0x61;
        }
        *puVar7 = *puVar7 | 0x40000;
      }
    }
    else
    {
      r = *(short *)((int)puVar7 + 0x136);
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
    MON_MoveToPosition(instance, (_Position *)(puVar7 + 0x48), *(short *)(puVar7[0x59] + 0x1e));
    lVar1 = MATH3D_LengthXY((int)(instance->position).x - (int)*(short *)(puVar7 + 0x48),
                            (int)(instance->position).y - (int)*(short *)((int)puVar7 + 0x122),
                            (int)(instance->position).z - (int)*(short *)(puVar7 + 0x49));
    if (lVar1 < 300)
    {
    LAB_8008a310:
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
  }
  SOUL_QueueHandler(instance);
LAB_8008a4ac:
  if (puVar7[0x31] != 0)
  {
    iVar5 = MON_ShouldIEvade(instance);
    if (iVar5 != 0)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
    }
    puVar7[0x47] = *(int *)(puVar7[0x31] + 4) + 0x5c;
  }
  return;
}

void MON_Hit(_Instance *instance)

{
  MON_PlayRandomIdle(instance, 1);
  return;
}

void MON_Hide(_Instance *instance)

{
  byte bVar1;
  int mode;
  u_char local_10;
  u_int *puVar2;
  u_char local_c;
  u_char local_8;
  u_int uVar3;
  u_char local_4;

  puVar2 = (u_int *)instance->extraData;
  uVar3 = puVar2[0x31];
  if (((*puVar2 & 4) != 0) || (uVar3 == 0))
    goto LAB_8008a644;
  bVar1 = *(byte *)((int)puVar2 + 0x156);
  if (bVar1 == 8)
  {
    if (((*puVar2 & 0x40000000) != 0) || (mode = MON_ShouldIAmbushEnemy(instance), mode == 0))
      goto LAB_8008a644;
    if (*(char *)((int)puVar2 + 0x153) != '\0')
    {
      if (*(char *)((int)puVar2 + 0x153) == '\x01')
      {
        mode = 0x28;
      }
      else
      {
        mode = 0x29;
      }
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10))), mode);
      *puVar2 = *puVar2 | 0x40000000;
      goto LAB_8008a644;
    }
    MON_MoveToPosition(instance, (_Position *)(*(int *)(uVar3 + 4) + 0x5c), 0x1000);
  }
  else
  {
    if ((bVar1 < 9) && (bVar1 == 4))
    {
      MON_ChangeBehavior(instance, (u_int) * (byte *)(puVar2 + 0x56));
      goto LAB_8008a644;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
LAB_8008a644:
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
  MON_DefaultMessageHandler(instance);
  return;
}

void MON_AttackEntry(_Instance *instance)

{
  char cVar1;
  int iVar2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  cVar1 = *(char *)(*(int *)(*(int *)((int)pvVar3 + 0x164) + 8) + 0x1b);
  iVar2 = *(int *)((int)instance->data + 0x38);
  *(undefined *)((int)pvVar3 + 0x15b) = 0;
  iVar2 = iVar2 + (int)cVar1 * 0x20;
  *(int *)((int)pvVar3 + 0xb8) = iVar2;
  MON_PlayAnimFromListIfNotPlaying(instance, (char *)(iVar2 + 0x1b), 0, 1);
  if (*(char *)((int)pvVar3 + 0x156) == '\b')
  {
    if (*(char *)((int)pvVar3 + 0x159) == -1)
    {
      *(undefined *)((int)pvVar3 + 0x156) = *(undefined *)((int)pvVar3 + 0x157);
    }
    else
    {
      *(undefined *)((int)pvVar3 + 0x156) = *(undefined *)((int)pvVar3 + 0x159);
    }
  }
  return;
}

void MON_SurpriseAttack(_Instance *instance)

{
  MON_ChooseAttack(instance);
  return;
}

void MON_EnvironmentDamage(_Instance *instance)

{
  return;
}

void MON_EnvironmentDamageEntry(_Instance *instance)

{
  return;
}

void MON_LaunchMonster(_Instance *instance, long color, int glowtime, int glowin, int glowfade)

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
  p_Var1 = FX_DoInstanceManySegmentGlow(instance, (u_int) * (byte *)((int)pvVar4 + 0x1d),
                                        (u_int) * (byte *)((int)pvVar4 + 0x20), local_res4, 1, 0x400, 0xa0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceManySegmentGlow(instance, (u_int) * (byte *)((int)pvVar4 + 0x1d),
                                        (u_int) * (byte *)((int)pvVar4 + 0x21), local_res4, 1, 0x400, 0xa0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceManySegmentGlow(instance, (u_int) * (byte *)((int)pvVar4 + 0x1b),
                                        (u_int) * (byte *)((int)pvVar4 + 0x23), local_res4, 1, 0x400, 0x80);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceManySegmentGlow(instance, (u_int) * (byte *)((int)pvVar4 + 0x1c),
                                        (u_int) * (byte *)((int)pvVar4 + 0x24), local_res4, 1, 0x400, 0x80);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  p_Var1 = FX_DoInstanceManySegmentGlow(instance, (u_int) * (byte *)((int)pvVar4 + 0x19),
                                        (u_int) * (byte *)((int)pvVar4 + 0x1d), local_res4, 1, 0x400, 0xc0);
  p_Var1->lifeTime = sVar2;
  p_Var1->fadein_time = sVar3;
  p_Var1->fadeout_time = sVar5;
  return;
}

void MON_GeneralDeathEntry(_Instance *instance)

{
  u_short uVar1;
  u_long uVar2;
  int iVar3;
  int mode;
  u_char local_10;
  u_int *puVar4;
  u_char local_c;
  void *pvVar5;
  u_char local_18;
  u_char in_stack_ffffffec;

  puVar4 = (u_int *)instance->extraData;
  pvVar5 = instance->data;
  if (instance->LinkParent != (_Instance *)0x0)
  {
    MON_UnlinkFromRaziel(instance);
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = -0x10;
  }
  instance->flags2 = instance->flags2 | 0x80;
  uVar1 = *(u_short *)(puVar4 + 0x54);
  *puVar4 = *puVar4 & 0xffffffef | 0x202000;
  if (uVar1 == 0x40)
  {
  LAB_8008a9ec:
    if ((*(u_int *)((int)pvVar5 + 0x10) & 8) == 0)
    {
      mode = 0x1b;
    }
    else
    {
      mode = 0x24;
    }
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))), mode);
    if (*(short *)(puVar4 + 0x54) == 0x40)
    {
      *(undefined *)(puVar4 + 0x55) = 2;
    }
    uVar2 = MON_GetAnim(instance);
    puVar4[0x45] = uVar2 + 2000;
    *puVar4 = *puVar4 | 0x400000;
    uVar2 = MON_GetAnim(instance);
    *(undefined **)(puVar4 + 0x46) = &DAT_00002710 + uVar2;
    MON_LaunchMonster(instance, (long)&DAT_00004960, -1, 0, 0);
    instance->xAccl = 0;
  }
  else
  {
    if (uVar1 < 0x41)
    {
      if (uVar1 == 0x10)
      {
        MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))), 0x1b);
        *(undefined *)(puVar4 + 0x55) = 3;
        uVar2 = MON_GetAnim(instance);
        puVar4[0x45] = uVar2 + 3000;
        uVar2 = MON_GetAnim(instance);
        *(undefined **)(puVar4 + 0x46) = &DAT_00002ee0 + uVar2;
      }
      else
      {
        if (uVar1 == 0x20)
        {
          *(undefined *)(puVar4 + 0x55) = 1;
          goto LAB_8008a9ec;
        }
      LAB_8008aab8:
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
        puVar4[0x45] = 0;
        *(undefined *)(puVar4 + 0x55) = 7;
        MON_TurnOffWeaponSpheres(instance);
      }
    }
    else
    {
      if (uVar1 == 0x200)
      {
        MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(in_stack_ffffffec, local_18))), 0x2b);
        *(undefined *)(puVar4 + 0x55) = 4;
        uVar2 = MON_GetAnim(instance);
        puVar4[0x45] = uVar2 + 1000;
      }
      else
      {
        if (uVar1 != 0x400)
          goto LAB_8008aab8;
        *(undefined *)(puVar4 + 0x55) = 6;
        puVar4[0x45] = 0;
      }
    }
    instance->xAccl = 0;
  }
  instance->yAccl = 0;
  instance->xVel = 0;
  instance->yVel = 0;
  MON_DropAllObjects(instance);
  return;
}

void MON_GeneralDeath(_Instance *instance)

{
  bool bVar1;
  int iVar2;
  u_long uVar3;
  __Event *p_Var4;
  u_char local_10;
  u_int *puVar5;
  u_char local_c;
  u_char local_8;
  u_char local_4;

  puVar5 = (u_int *)instance->extraData;
  bVar1 = false;
  if ((((instance->flags2 & 0x10U) == 0) ||
       (iVar2 = MON_AnimPlaying(instance, (MonsterAnim)
                                              CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10)))),
        iVar2 == 0)) &&
      (*(char *)(puVar5 + 0x55) != '\x06'))
  {
    if (((instance->flags2 & 0x12U) == 0) || (uVar3 = MON_GetAnim(instance), uVar3 <= puVar5[0x45]))
      goto LAB_8008abec;
    if (*(char *)(puVar5 + 0x55) != '\x04')
    {
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_4, CONCAT48(local_8, CONCAT44(local_c, local_10))), 0x24);
      MON_TurnOffWeaponSpheres(instance);
      goto LAB_8008abec;
    }
  }
  bVar1 = true;
LAB_8008abec:
  if (bVar1)
  {
    *puVar5 = *puVar5 & 0xffffffef;
    G2Anim_SetLooping(&instance->anim);
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  MON_ApplyPhysics(instance);
  iVar2 = MON_OnGround(instance);
  if (iVar2 != 0)
  {
    *puVar5 = *puVar5 | 2;
  }
  do
  {
    p_Var4 = PurgeMessageQueue((__MessageQueue *)(puVar5 + 2));
  } while (p_Var4 != (__Event *)0x0);
  return;
}

void MON_NoticeEntry(_Instance *instance)

{
  int Data;
  _Instance *sender;
  u_char unaff_s0;
  void *pvVar1;
  u_char unaff_s1;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  pvVar1 = instance->extraData;
  if ((*(int *)((int)pvVar1 + 4) < 0) &&
      (*(int *)(*(int *)(*(int *)((int)pvVar1 + 0x164) + 0xc) + 4) != 0))
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x2a);
    sender = *(_Instance **)(*(int *)((int)pvVar1 + 0xc4) + 4);
    Data = SetMonsterAlarmData(sender, &sender->position, 2);
    INSTANCE_Broadcast(instance, *(long *)(*(int *)(*(int *)((int)pvVar1 + 0x164) + 0xc) + 4),
                       0x1000011, Data);
  }
  else
  {
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1d);
  }
  return;
}

void MON_Notice(_Instance *instance)

{
  u_char unaff_s0;
  void *pvVar1;
  u_char unaff_s1;

  pvVar1 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  }
  if (*(int *)((int)pvVar1 + 0xc4) != 0)
  {
    *(int *)((int)pvVar1 + 0x11c) = *(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c;
    MON_MoveToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c),
                       *(short *)(*(int *)((int)pvVar1 + 0x164) + 0x1c));
  }
  MON_DefaultMessageHandler(instance);
  return;
}

void MON_PursueEntry(_Instance *instance)

{
  u_long uVar1;
  u_int uVar2;
  void *pvVar3;

  instance->flags = instance->flags | 0x800;
  pvVar3 = instance->extraData;
  instance->flags2 = instance->flags2 | 0x20000000;
  uVar1 = MON_GetAnim(instance);
  uVar2 = rand();
  *(int *)((int)pvVar3 + 0x118) = uVar1 + (uVar2 & 0xfff) + 2000;
  return;
}

void MON_Pupate(_Instance *instance)

{
  short sVar1;
  bool bVar2;
  long lVar3;
  u_long uVar4;
  u_int uVar5;
  Intro *pIVar6;
  int Data;
  u_char local_28;
  void *pvVar7;
  u_char local_24;
  _Instance *instance_00;
  u_int *puVar8;
  _Instance *Inst;
  undefined2 uVar9;
  Object *pOVar10;
  u_char local_30;
  u_char in_stack_ffffffd4;

  puVar8 = (u_int *)instance->extraData;
  pOVar10 = (Object *)0x0;
  if ((instance->flags & 0x800U) == 0)
  {
    MON_DefaultMessageHandler(instance);
    if (puVar8[0x31] != 0)
    {
      MON_MoveToPosition(instance, (_Position *)(*(int *)(puVar8[0x31] + 4) + 0x5c),
                         *(short *)(puVar8[0x59] + 0x1c));
    }
    if ((instance->flags2 & 0x10U) != 0)
    {
      MON_ChangeBehavior(instance, (u_int) * (byte *)(puVar8 + 0x56));
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
      pOVar10 = (Object *)(&objectAccess)[(byte)(&DAT_800cb1b8)[Data]].object;
      while (instance_00 != (_Instance *)0x0)
      {
        if ((instance_00->object == pOVar10) && ((instance_00->flags & 0x20U) == 0))
        {
          pIVar6 = instance->intro;
          lVar3 = MATH3D_LengthXY((int)(instance_00->position).x - (int)(pIVar6->position).x,
                                  (int)(instance_00->position).y - (int)(pIVar6->position).y,
                                  (int)(instance_00->position).z - (int)(pIVar6->position).z);
          if (lVar3 < *(short *)((int)puVar8 + 0x136))
          {
            lVar3 = MATH3D_LengthXY((int)(instance_00->position).x -
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
            uVar4 = MON_GetAnim(instance);
            if ((puVar8[0x46] < uVar4) && (uVar5 = rand(), (uVar5 & 0xf) == 0))
            {
              local_30 = 1;
              Data = SetAnimationInstanceSwitchData(instance_00, 0, 0, 0, 1);
              INSTANCE_Query(instance_00, 0x8000008, Data);
              uVar4 = MON_GetAnim(instance);
              uVar5 = rand();
              puVar8[0x46] = uVar4 + (uVar5 & 0xfff) + 2000;
            }
          }
        }
        uVar9 = (undefined2)_uVar9;
        instance_00 = instance_00->next;
      }
      if (Inst != (_Instance *)0x0)
      {
        sVar1 = (Inst->position).z;
        *(u_char *)&instance->position = *(u_char *)&Inst->position;
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
        *(undefined2 *)((int)puVar8 + 0x146) = 0;
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
        INSTANCE_Query(Inst, 0x40002, 5);
      }
    }
  }
  return;
}

void MON_Embrace(_Instance *instance)

{
  u_long uVar1;
  u_char unaff_s0;
  u_char unaff_s1;
  void *pvVar2;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  pvVar2 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x1e);
  uVar1 = MON_GetAnim(instance);
  *(int *)((int)pvVar2 + 0x114) =
      uVar1 + (int)*(short *)(*(int *)(*(int *)((int)pvVar2 + 0x164) + 8) + 0x16);
  return;
}

void MON_EmbraceEntry(_Instance *instance)

{
  u_long uVar1;
  u_char local_10;
  u_int uVar2;
  _Instance *ei;
  u_char local_c;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  uVar2 = puVar3[0x31];
  if (uVar2 != 0)
  {
    if ((((*(short *)(uVar2 + 0x14) <= *(short *)(*(int *)(puVar3[0x59] + 8) + 0x14)) &&
          ((*(u_int *)(uVar2 + 0x14) & 0x10200000) == 0x10200000)) &&
         ((*puVar3 & 4) == 0)) &&
        (uVar1 = MON_GetAnim(instance), uVar1 <= puVar3[0x45]))
    {
      ei = *(_Instance **)(uVar2 + 4);
      MON_DoDrainEffects(instance, ei);
      INSTANCE_Query(ei, 0x40006, (int)*(short *)(*(int *)(puVar3[0x59] + 8) + 0x12) << 8);
      INSTANCE_Query(instance, 0x1000016,
                     0x1e);
      MON_MoveToPosition(instance, &ei->position, *(short *)(puVar3[0x59] + 0x1c));
      goto LAB_8008b308;
    }
    *(u_short *)(uVar2 + 0x16) = *(u_short *)(uVar2 + 0x16) & 0xefff;
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
LAB_8008b308:
  MON_DefaultMessageHandler(instance);
  return;
}

void MON_PetrifiedEntry(_Instance *instance)

{
  u_long uVar1;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  uVar1 = MON_GetAnim(instance);
  *(undefined **)(puVar2 + 0x45) = &DAT_00001388 + uVar1;
  *puVar2 = *puVar2 | 0x80;
  return;
}

void MON_Petrified(_Instance *instance)

{
  u_long uVar1;
  __Event *p_Var2;
  u_char local_20;
  u_int *puVar3;
  u_char local_1c;

  puVar3 = (u_int *)instance->extraData;
  uVar1 = MON_GetAnim(instance);
  if (puVar3[0x45] < uVar1)
  {
    *puVar3 = *puVar3 & 0xffffff7f;
    instance->petrifyValue = 0;
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
  }
  while (p_Var2 = PurgeMessageQueue((__MessageQueue *)(puVar3 + 2)), p_Var2 != (__Event *)0x0)
  {
    if ((p_Var2->ID == 0x100001f) || ((p_Var2->ID == 0x1000023 && (p_Var2->Data == 0x1000))))
    {
      *(undefined2 *)(puVar3 + 0x54) = 0x400;
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_1c, local_20));
    }
  }
  return;
}

int MONSTER_CalcDamageIntensity(int hp, int maxHp)

{
  maxHp;
}

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

  p_Var9 = instance->object->modelList[instance->currentModel];
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
        p_Var4 = p_Var8 + *psVar7;
        PIPE3D_InstanceListTransformAndDraw(&MStack80, instance->matrix + iVar6);
        SetRotMatrix((u_char *)&MStack80);
        TransMatrix((int)&MStack80);
        RotTrans(location, &local_60, auStack48);
        if (p_Var4 <= p_Var8 + (int)sVar1)
        {
          psVar5 = &(p_Var4->vertex).z;
          do
          {
            iVar2 = (p_Var4->vertex).x - local_60;
            if (iVar2 < 0)
            {
              iVar2 = -iVar2;
            }
            iVar3 = psVar5[-1] - local_5c;
            if (iVar3 < 0)
            {
              iVar3 = -iVar3;
            }
            if (iVar3 < iVar2)
            {
              iVar3 = iVar2;
            }
            iVar2 = *psVar5 - local_58;
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
    100;
    pCVar2 = instance->perVertexColor + vertidx;
    if (0x100 < iVar3)
    {
      iVar3 = 0x100;
    }
    pCVar2->r = ~(byte)((0xff - (u_int) * (byte *)(*(int *)((int)pvVar4 + 0x164) + 0x3f)) * iVar3 >> 8);
    pCVar2->g = ~(byte)((0xff - (u_int) * (byte *)(*(int *)((int)pvVar4 + 0x164) + 0x40)) * iVar3 >> 8);
    bVar1 = *(byte *)(*(int *)((int)pvVar4 + 0x164) + 0x41);
    pCVar2->cd = '\x01';
    pCVar2->b = ~(byte)((0xff - (u_int)bVar1) * iVar3 >> 8);
    *(u_char *)((int)cb_data + 0xc) = 1;
  }
  return;
}

void MONSTER_VertexBlood(_Instance *instance, _Model *model)

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

int MONSTER_VertexBurnt(_Instance *instance, _SVector *location, int amount)

{
  MATRIX *pMVar1;
  _Model *model;
  _MVertex *p_Var2;
  int local_58;
  int local_54;
  int local_50;
  u_char local_4c;
  int local_48;
  u_char local_40;
  u_int local_3c;
  undefined local_38[8];
  u_short local_30;
  undefined auStack40[8];

  model = instance->object->modelList[instance->currentModel];
  if ((instance->perVertexColor == (CVECTOR *)0x0) &&
      (MONSTER_VertexBlood(instance, model), instance->perVertexColor == (CVECTOR *)0x0))
  {
    return -1;
  }
  local_40 = *(u_char *)location;
  local_3c = *(u_int *)&location->z;
  local_58 = -1;
  local_54 = 0x10000;
  local_50 = -1;
  local_4c = 0;
  local_48 = amount;
  MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBloodyMess, &local_58);
  if (local_54 < 0x33)
  {
    FX_MakeSpark((_SVector *)&local_40);
  }
  else
  {
    p_Var2 = model->vertexList;
    pMVar1 = instance->matrix + local_50;
    SetRotMatrix((u_char *)pMVar1);
    TransMatrix((int)pMVar1);
    RotTrans(p_Var2 + local_58, local_38, auStack40);
    local_4c = 1;
    local_54 = 0;
    local_3c = local_3c & 0xffff0000 | (u_int)local_30;
    FX_MakeSpark((_SVector *)&local_40);
    MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBloodyMess, &local_58);
  }
  return local_58;
}

void MONSTER_InitVertexColors(_Instance *instance, int vert, int amount)

{
  void *pvVar1;
  int iVar2;
  CVECTOR *address;
  u_int uVar3;
  u_int uVar4;
  u_char *puVar5;
  CVECTOR *pCVar6;

  address = instance->perVertexColor;
  if (address == (CVECTOR *)0x0)
  {
    return;
  }
  pCVar6 = address + vert;
  if (amount == 0)
  {
    MEMPACK_Init((char *)address);
    instance->perVertexColor = (CVECTOR *)0x0;
    return;
  }
  uVar4 = (u_int)pCVar6->g;
  pvVar1 = instance->extraData;
  if ((u_int)pCVar6->r < uVar4)
  {
    if ((u_int)pCVar6->r < (u_int)pCVar6->b)
    {
      uVar4 = (u_int)pCVar6->r;
      uVar3 = (u_int) * (byte *)(*(int *)((int)pvVar1 + 0x164) + 0x3f);
      goto LAB_8008b9f0;
    }
  }
  else
  {
    if (uVar4 < pCVar6->b)
    {
      uVar3 = (u_int) * (byte *)(*(int *)((int)pvVar1 + 0x164) + 0x40);
      goto LAB_8008b9f0;
    }
  }
  uVar4 = (u_int)pCVar6->b;
  uVar3 = (u_int) * (byte *)(*(int *)((int)pvVar1 + 0x164) + 0x41);
LAB_8008b9f0:
  if ((pCVar6->cd == '\x01') && ((int)uVar4<(int)((0x100 - amount) * (0xff - uVar3))>> 8))
  {
    iVar2 = instance->object->modelList[instance->currentModel]->numVertices;
    address = instance->perVertexColor;
    if (iVar2 != 0)
    {
      puVar5 = &address->cd;
      do
      {
        if (*puVar5 == '\x01')
        {
          uVar4 = (u_int)address->r + 8;
          if (uVar4 < 0x100)
          {
            address->r = (u_char)uVar4;
          }
          else
          {
            address->r = -1;
          }
          if ((u_int)puVar5[-2] + 8 < 0x100)
          {
            puVar5[-2] = (u_char)((u_int)puVar5[-2] + 8);
          }
          else
          {
            puVar5[-2] = -1;
          }
          if ((u_int)puVar5[-1] + 8 < 0x100)
          {
            puVar5[-1] = (u_char)((u_int)puVar5[-1] + 8);
          }
          else
          {
            puVar5[-1] = -1;
          }
          if (((u_int)*address & 0xffffff) == 0xffffff)
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

void ProcessBurntMess(_Instance *instance, int vertidx, int segidx, int dist, void *cb_data)

{
  u_char uVar1;

  if (dist < *(int *)((int)cb_data + 4))
  {
    *(int *)cb_data = vertidx;
    *(int *)((int)cb_data + 4) = dist;
    *(int *)((int)cb_data + 8) = segidx;
  }
  if ((**(int **)((int)cb_data + 0xc) <= dist) ||
      **(int **)((int)cb_data + 0xc) << 0x10) >> 0x14,
     uVar1 = (u_char)_uVar1, 0xfe < _uVar1))
    {
      uVar1 = -2;
    }
  instance->perVertexColor[vertidx].r = uVar1;
  instance->perVertexColor[vertidx].g = uVar1;
  instance->perVertexColor[vertidx].b = uVar1;
  instance->perVertexColor[vertidx].cd = '\x01';
  return;
}

int MONSTER_StartVertexBurnt(_Instance *instance, _SVector *location, burntTuneType *burntTune)

{
  MATRIX *pMVar1;
  _Model *model;
  _MVertex *p_Var2;
  int local_50;
  int local_4c;
  int local_48;
  burntTuneType *local_44;
  u_char local_40;
  u_int local_3c;
  undefined local_38[8];
  u_short local_30;
  undefined auStack40[8];

  model = instance->object->modelList[instance->currentModel];
  if ((instance->perVertexColor == (CVECTOR *)0x0) &&
      (MONSTER_VertexBlood(instance, model), instance->perVertexColor == (CVECTOR *)0x0))
  {
    return -1;
  }
  local_40 = *(u_char *)location;
  local_3c = *(u_int *)&location->z;
  local_50 = -1;
  local_4c = 0x10000;
  local_48 = -1;
  local_44 = burntTune;
  MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBurntMess, &local_50);
  if (burntTune->burntDist >> 1 < local_4c)
  {
    p_Var2 = model->vertexList;
    pMVar1 = instance->matrix + local_48;
    SetRotMatrix((u_char *)pMVar1);
    TransMatrix((int)pMVar1);
    RotTrans(p_Var2 + local_50, local_38, auStack40);
    local_4c = 0;
    local_3c = local_3c & 0xffff0000 | (u_int)local_30;
    FX_MakeSpark((_SVector *)&local_40);
    MONSTER_ProcessClosestVerts(instance, (_SVector *)&local_40, ProcessBurntMess, &local_50);
  }
  else
  {
    FX_MakeSpark((_SVector *)&local_40);
  }
  return local_50;
}

void MONSTER_StartVertexBlood(_Instance *instance, burntTuneType *burntTune)

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
      if (iVar3 <= (int)(u_int)pCVar2->r)
      {
        pCVar2->r = pCVar2->r - cVar1;
      }
      if (iVar3 <= (int)(u_int)pCVar2->g)
      {
        pCVar2->g = pCVar2->g - cVar1;
      }
      if (iVar3 <= (int)(u_int)pCVar2->b)
      {
        pCVar2->b = pCVar2->b - cVar1;
      }
      pCVar2->cd = '\0';
      iVar4 = iVar4 + 1;
    } while (iVar4 < p_Var5->numVertices);
  }
  return;
}

void SLUAGH_DamageEffect(_Instance *instance, evFXHitData *data)

{
  int amount;
  u_long uVar1;
  _G2Bool_Enum _Var2;
  int lifetime;
  u_int uVar3;
  evFXHitData *location;
  MATRIX *pMVar4;
  void *pvVar5;
  u_int *puVar6;
  int iVar7;
  u_char local_68;
  undefined *local_64;
  _SVector local_60;
  _SVector local_58;
  u_char local_50;
  u_char local_4c;
  _SVector local_48;
  _SVector _Stack64;
  _SVector local_38;
  _SVector local_30;
  _SVector local_28;

  local_68 = 0;
  local_64 = &DAT_0000fffe;
  puVar6 = (u_int *)instance->extraData;
  if (data == (evFXHitData *)0x0)
  {
    pvVar5 = instance->data;
    if ((*puVar6 & 0x10000200) == 0x10000000)
    {
      amount = rand();
      local_50 = 0;
      local_4c = 1;
      pMVar4 = instance->matrix +
               amount % instance->object->modelList[instance->currentModel]->numSegments;
      amount = rand();
      local_58.x = 4 - ((u_short)amount & 7);
      amount = rand();
      local_58.y = 4 - ((u_short)amount & 7);
      local_58.z = 0;
      local_60.x = *(short *)pMVar4->t;
      local_60.y = *(short *)(pMVar4->t + 1);
      local_60.z = *(short *)(pMVar4->t + 2);
      FX_Die(&local_60, &local_58, (_SVector *)&local_50, 0, 0xff2828, 0x18, 0x10, 2);
    }
    if ((*puVar6 & 0x800010) == 0x800010)
    {
      pMVar4 = instance->matrix + *(byte *)((int)pvVar5 + 0x18);
      memset(&_Stack64, 0, 8);
      local_48.x = *(short *)pMVar4->t;
      local_48.y = *(short *)(pMVar4->t + 1);
      local_48.z = *(short *)(pMVar4->t + 2);
      FX_BloodCone(&local_48, &_Stack64, (_SVector *)&local_68, 4, (long)&DAT_00180080, 8);
    }
    if ((*puVar6 & 0x400000) != 0)
    {
      MONSTER_StartVertexBlood(instance, &burntTest);
    }
    if (*(char *)(puVar6 + 0x55) != '\x03')
    {
      return;
    }
    if ((*(u_int *)((int)pvVar5 + 0x10) & 2) == 0)
    {
      return;
    }
    uVar1 = MON_GetAnim(instance);
    if (puVar6[0x46] <= uVar1)
    {
      return;
    }
    MONSTER_StartVertexBlood(instance, &burntTest);
    local_30.y = 0;
    local_30.x = 0;
    local_30.z = 0xc;
    local_28.y = 0;
    local_28.x = 0;
    local_28.z = 0;
    iVar7 = instance->object->modelList[instance->currentModel]->numSegments;
    amount = 1;
    if (iVar7 < 2)
    {
      return;
    }
    do
    {
      _Var2 = G2Anim_IsSegmentEnabled(&instance->anim, amount);
      if (_Var2 != G2FALSE)
      {
        pMVar4 = instance->matrix + amount;
        lifetime = rand();
        local_38.x = *(short *)pMVar4->t + ((u_short)lifetime & 3);
        lifetime = rand();
        local_38.y = *(short *)(pMVar4->t + 1) + ((u_short)lifetime & 3);
        lifetime = rand();
        local_38.z = *(short *)(pMVar4->t + 2) + ((u_short)lifetime & 3);
        uVar3 = rand();
        if ((uVar3 & 0x1f) == 0)
        {
          lifetime = 0x20;
        }
        else
        {
          lifetime = 2;
        }
        FX_Die(&local_38, &local_30, &local_28, -0x100, 0x808080, 0x50, lifetime, 0);
      }
      amount = amount + 1;
    } while (amount < iVar7);
    return;
  }
  if (data->type == 0x20)
  {
    location = data;
    if (data->amount == 0)
      goto LAB_8008c1b8;
  }
  else
  {
    if (data->type != 0x10)
    {
      amount = MONSTER_CalcDamageIntensity((int)*(short *)(puVar6 + 0x50), (int)*(short *)((int)puVar6 + 0x142));
      amount = MONSTER_VertexBurnt(instance, (_SVector *)data, amount);
      *(short *)(puVar6 + 0x52) = (short)amount;
      goto LAB_8008c1fc;
    }
  LAB_8008c1b8:
    location = (evFXHitData *)&instance->position;
  }
  MONSTER_StartVertexBurnt(instance, (_SVector *)location, &burntTest);
LAB_8008c1fc:
  if ((int)data->amount != 0)
  {
    FX_BloodCone((_SVector *)data, &data->velocity, (_SVector *)&local_68, (int)data->amount,
                 (long)&DAT_00180080, 8);
  }
  return;
}

void MON_SetDefaults(_Instance *instance)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  u_int uVar4;
  _HModel *p_Var5;
  byte *pbVar6;
  u_char local_18;
  u_char local_14;
  void *pvVar7;
  u_int *puVar8;

  puVar8 = (u_int *)instance->extraData;
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
    G2Anim_AttachControllerToSeg(&instance->anim, (u_int) * (byte *)((int)pvVar7 + 0x1a), 0xe);
    _G2Anim_FindController(&instance->anim, (u_int) * (byte *)((int)pvVar7 + 0x1a), 0xe);
  }
  bVar1 = *(byte *)((int)pvVar7 + 0x22);
  if ((bVar1 != 0) && ((u_int)bVar1 != (u_int) * (byte *)((int)pvVar7 + 0x1a)))
  {
    G2Anim_AttachControllerToSeg(&instance->anim, (u_int)bVar1, 0xe);
    _G2Anim_FindController(&instance->anim, (u_int) * (byte *)((int)pvVar7 + 0x22), 0xe);
  }
  if (*(byte *)((int)pvVar7 + 0x25) != 0)
  {
    G2Anim_EnableSegment(&instance->anim, (u_int) * (byte *)((int)pvVar7 + 0x25));
  }
  if ((instance->object->oflags & 0x80000U) == 0)
  {
    instance->fadeValue = 0x1000;
    MON_StartSpecialFade(instance, 0, 0x14);
  }
  if (((((instance->flags & 2U) == 0) && (cVar2 = *(char *)((int)puVar8 + 0x156), cVar2 != '\x04')) && (cVar2 != '\x10')) && (cVar2 == '\r'))
  {
    *(undefined2 *)(puVar8 + 0x54) = 0;
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
  return;
}

void HUMAN_CleanUp(_Instance *instance)

{
  byte bVar1;
  u_long uVar2;
  int slotID;
  void *pvVar3;
  void *pvVar4;

  pvVar3 = instance->extraData;
  pvVar4 = instance->data;
  MON_DropAllObjects(instance);
  slotID = (int)*(char *)((int)pvVar3 + 0x162);
  if (slotID != -1)
  {
    ENMYPLAN_GetInitializedPlanningWorkspaceFinal(slotID);
  }
  if (*(byte *)((int)pvVar4 + 0x1a) != 0)
  {
    razAttachControllers(&instance->anim, (u_int) * (byte *)((int)pvVar4 + 0x1a), 0xe);
  }
  bVar1 = *(byte *)((int)pvVar4 + 0x22);
  if ((bVar1 != 0) && ((u_int)bVar1 != (u_int) * (byte *)((int)pvVar4 + 0x1a)))
  {
    razAttachControllers(&instance->anim, (u_int)bVar1, 0xe);
  }
  uVar2 = INSTANCE_Post(instance, 1);
  if ((uVar2 & 0xc000) != 0)
  {
    GlobalSave->humanOpinionOfRaziel = GlobalSave->humanOpinionOfRaziel + 1;
  }
  return;
}
