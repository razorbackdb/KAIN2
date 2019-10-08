#include "THISDUST.H"
#include "SOUL.H"

void MON_GroundMoveQueueHandler(_Instance *instance)

{
  __Event *message;
  u_char local_18;
  u_char local_14;
  void *pvVar1;

  pvVar1 = instance->extraData;
  while (message = PurgeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0)
  {
    if (message->ID == 0x100000d)
    {
      if (instance->currentMainState != 0x17)
      {
        MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
      }
    }
    else
    {
      MON_PupateMessageHandler(instance, message);
    }
  }
  return;
}

void SOUL_Physics(_Instance *instance, long time)

{
  void *pvVar1;
  int iVar2;

  pvVar1 = instance->extraData;
  iVar2 = -4;
  if ((*(u_short *)((int)pvVar1 + 0x126) & 0x1f) < 0x10)
  {
    iVar2 = 4;
  }
  instance->zAccl = instance->zAccl + iVar2;
  *(short *)((int)pvVar1 + 0x126) = *(short *)((int)pvVar1 + 0x126) + 1;
  PhysicsDefaultLinkedMoveResponse(instance, &instance->position, time);
  return;
}

void SOUL_Flee(_Instance *instance)

{
  short sVar1;
  u_long uVar2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  uVar2 = MON_GetAnim(instance);
  if ((gameTrackerX.gameFlags & 0x80U) == 0)
  {
    if (*(u_int *)((int)pvVar3 + 0x10c) < uVar2)
    {
      sVar1 = instance->fadeValue;
      if (sVar1 == 0)
      {
        MON_StartSpecialFade(instance, 0x1000, 100);
        sVar1 = instance->fadeValue;
      }
      if (0xfff < sVar1)
      {
        instance->flags2 = instance->flags2 | 0x8000000;
        MORPH_SetupInstanceListFlags(&gameTrackerX, instance);
        instance->fadeValue = 0;
      }
    }
  }
  else
  {
    *(undefined **)((int)pvVar3 + 0x10c) = &DAT_00001964 + uVar2;
  }
  return;
}

void SOUL_MoveToDest(_Instance *instance, long maxAccel, long time)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  instance->xAccl =
      ((int)*(short *)((int)pvVar1 + 0x120) - (int)(instance->position).x) - instance->xVel;
  instance->yAccl =
      ((int)*(short *)((int)pvVar1 + 0x122) - (int)(instance->position).y) - instance->yVel;
  instance->zAccl =
      ((int)*(short *)((int)pvVar1 + 0x124) - (int)(instance->position).z) - instance->zVel;
  if (instance->xAccl < -maxAccel)
  {
    instance->xAccl = -maxAccel;
  }
  else
  {
    if (maxAccel < instance->xAccl)
    {
      instance->xAccl = maxAccel;
    }
  }
  if (instance->yAccl < -maxAccel)
  {
    instance->yAccl = -maxAccel;
  }
  else
  {
    if (maxAccel < instance->yAccl)
    {
      instance->yAccl = maxAccel;
    }
  }
  if (instance->zAccl < -maxAccel)
  {
    instance->zAccl = -maxAccel;
  }
  else
  {
    if (maxAccel < instance->zAccl)
    {
      instance->zAccl = maxAccel;
    }
  }
  SOUL_Physics(instance, time);
  return;
}

void SOUND_Init(_Instance *instance)

{
  u_long uVar1;
  u_char local_10;
  u_char local_c;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  MON_SetDefaults(instance);
  *puVar2 = *puVar2 | 0x200880;
  instance->maxXVel = 600;
  instance->maxYVel = 600;
  instance->maxZVel = 600;
  instance->flags2 = instance->flags2 | 0x20000;
  *(undefined2 *)((int)puVar2 + 0x126) = 0;
  uVar1 = MON_GetAnim(instance);
  *(undefined **)(puVar2 + 0x43) = &DAT_00001964 + uVar1;
  if (instance->parent != (_Instance *)0x0)
  {
    puVar2[0x36] = instance->parent->introUniqueID;
  }
  if ((instance->flags & 2U) == 0)
  {
    instance->flags2 = instance->flags2 | 0x8000000;
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  return;
}

void SOUL_CleanUp(_Instance *instance)

{
  HUMAN_CleanUp(instance);
  return;
}

void SOUL_BirthEntry(_Instance *instance)

{
  short sVar1;
  u_long uVar2;
  void *pvVar3;

  sVar1 = (instance->position).z;
  pvVar3 = instance->extraData;
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
  instance->maxZVel = 0x11;
  instance->zAccl = 0;
  instance->zVel = 0;
  (instance->position).z = sVar1 + 0x78;
  uVar2 = MON_GetAnim(instance);
  *(int *)((int)pvVar3 + 0x114) = uVar2 + 0x5dc;
  return;
}

void SOUL_Birth(_Instance *instance)

{
  u_long uVar1;
  u_char local_10;
  void *pvVar2;
  u_char local_c;

  instance->zAccl = 0;
  pvVar2 = instance->extraData;
  SOUL_Physics(instance, gameTrackerX.timeMult);
  uVar1 = MON_GetAnim(instance);
  if (*(u_int *)((int)pvVar2 + 0x114) < uVar1)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  }
  MON_GroundMoveQueueHandler(instance);
  return;
}

void SOUL_SoulSuckEntry(_Instance *instance)

{
  instance->maxXVel = 600;
  instance->maxYVel = 600;
  instance->maxZVel = 0x11;
  instance->flags = instance->flags & 0xfffff7ff;
  return;
}

long SOUL_CalcAccel(long delta, long vel, long magnitude)

{
  int iVar1;

  if (delta < 1)
  {
    if (0 < vel)
    {
      iVar1 = delta << 4;
      goto LAB_8008d9b0;
    }
  }
  else
  {
    if (vel < 0)
    {
      iVar1 = delta << 4;
      goto LAB_8008d9b0;
    }
  }
  iVar1 = delta * 5;
LAB_8008d9b0:
  magnitude;
}

void SOUL_SoulSuck(_Instance *instance)

{
  short sVar1;
  short sVar2;
  __Event *message;
  long magnitude;
  long lVar3;
  _MonsterAnim *p_Var4;
  int Data;
  int iVar5;
  _Instance *p_Var6;
  u_int *puVar7;
  _Instance *Inst;
  _Instance *instance_00;
  u_char local_38;
  u_char in_stack_ffffffcc;
  undefined2 local_30;
  short local_2e;
  short local_2c;
  undefined2 in_stack_ffffffd6;

  Inst = (_Instance *)0x0;
  instance_00 = (_Instance *)0x0;
  puVar7 = (u_int *)instance->extraData;
LAB_8008da0c:
  while (true)
  {
    message = PurgeMessageQueue((__MessageQueue *)(puVar7 + 2));
    if (message == (__Event *)0x0)
    {
      if ((*puVar7 & 0x800) == 0)
      {
        PhysicsDefaultLinkedMoveResponse(instance, &instance->position, gameTrackerX.timeMult);
      }
      else
      {
        SOUL_Physics(instance, gameTrackerX.timeMult);
      }
      if ((instance_00 == (_Instance *)0x0) || (instance_00 != Inst))
      {
        if (Inst == (_Instance *)0x0)
        {
          if ((instance->flags2 & 0x20000000U) != 0)
          {
            instance->flags2 = instance->flags2 & 0xdfffffff;
          }
          MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffcc, local_38));
        }
      }
      else
      {
        Data = SetMonsterHitData(instance, 0, 0, 0);
        INSTANCE_Query(Inst, 0x1000009, Data);
        INSTANCE_Query(Inst, 0x1000016, (int)*(short *)(puVar7 + 0x51));
        SOUND_Play3dSound(&instance->position, 8, -0x1c2, 0x50, 0xdac);
        if (Inst == gameTrackerX.playerInstance)
        {
          GAMEPAD_HandleDualShock(0x80, (int)&DAT_00005000);
        }
        if (puVar7[0x36] != 0)
        {
          instance_00 = INSTANCE_Deactivate(puVar7[0x36]);
          if (instance_00 != (_Instance *)0x0)
          {
            MON_SoulSucked(instance_00);
          }
          SAVE_Instance(instance);
        }
        MON_KillMonster(instance);
      }
      return;
    }
    Data = message->ID;
    if (Data != 0x1000009)
      break;
    p_Var6 = (_Instance *)message->Data;
    *(undefined2 *)(puVar7 + 0x48) = *(undefined2 *)((int)&p_Var6->node + 4);
    *(undefined2 *)((int)puVar7 + 0x122) = *(undefined2 *)((int)&p_Var6->node + 6);
    if ((*puVar7 & 0x800) == 0)
    {
      *(short *)(puVar7 + 0x49) = (instance->position).z;
    }
    else
    {
      *(undefined2 *)(puVar7 + 0x49) = *(undefined2 *)&p_Var6->next;
    }
    magnitude = MATH3D_DistanceBetweenPositions((_Position *)(puVar7 + 0x48), &instance->position);
    if (magnitude < 7000)
    {
      Inst = *(_Instance **)&p_Var6->node;
      MONSENSE_See(instance, Inst);
      if ((*(char *)(*(int *)puVar7[0x59] + 0x2d) == -1) || (0x500 < magnitude))
      {
        lVar3 = SOUL_CalcAccel((int)*(short *)(puVar7 + 0x48) - (int)(instance->position).x,
                               instance->xVel, magnitude);
        instance->xAccl = lVar3;
        lVar3 = SOUL_CalcAccel((int)*(short *)((int)puVar7 + 0x122) - (int)(instance->position).y,
                               instance->yVel, magnitude);
        instance->yAccl = lVar3;
        magnitude = SOUL_CalcAccel((int)*(short *)(puVar7 + 0x49) - (int)(instance->position).z,
                                   instance->zVel, magnitude);
        instance->zAccl = magnitude;
        instance->maxXVel = 600;
        instance->maxYVel = 600;
        instance->maxZVel = 0x11;
      }
      else
      {
        Data = (int)(instance->position).z - (int)*(short *)(puVar7 + 0x49);
        if (Data < 0)
        {
          Data = -Data;
        }
        if (Data < 200)
        {
          Data = MON_AnimPlaying(instance, (MonsterAnim)
                                               CONCAT214(in_stack_ffffffd6,
                                                         CONCAT212(local_2c, CONCAT210(local_2e, CONCAT28(
                                                                                                     local_30, CONCAT44(in_stack_ffffffcc, local_38))))));
          if ((Data == 0) && (0x32 < magnitude))
          {
            MON_PlayAnim(instance, (MonsterAnim)CONCAT214(in_stack_ffffffd6, CONCAT212(local_2c, CONCAT210(local_2e, CONCAT28(local_30, CONCAT44(in_stack_ffffffcc, local_38))))), 0x2d);
            instance->flags2 = instance->flags2 | 0x20000000;
          }
          p_Var4 = MON_GetTime(instance, *(char **)puVar7[0x59], 0x2d);
          sVar1 = G2AnimKeylist_GetDuration(instance->object->animList[p_Var4->index[0]]);
          sVar2 = G2Anim_GetElapsedTime(&instance->anim);
          3000;
          if (0 < Data)
          {
            iVar5 = (u_int) * (u_short *)(puVar7 + 0x48) - (u_int)(u_short)(instance->position).x;
            local_30 = (undefined2)iVar5;
            local_2e = *(short *)((int)puVar7 + 0x122) - (instance->position).y;
            local_2c = *(short *)(puVar7 + 0x49) - (instance->position).z;
 Data);
 Data);
 Data);
          }
          if ((*puVar7 & 0x4000000) == 0)
          {
            instance_00 = Inst;
          }
          instance->zAccl = 0;
          instance->yAccl = 0;
          instance->xAccl = 0;
          sVar1 = MON_FacingOffset(Inst, instance);
          (instance->rotation).z = (instance->rotation).z + sVar1;
          *puVar7 = *puVar7 & 0xfffff7ff;
        }
      }
    }
    else
    {
      instance->zAccl = 0;
      instance->yAccl = 0;
      instance->xAccl = 0;
    }
  }
  if (0x1000009 < Data)
    goto LAB_8008da4c;
  if ((Data == 0x1000008) &&
      ((p_Var4 = MON_GetTime(instance, *(char **)puVar7[0x59], 0x2d), p_Var4 == (_MonsterAnim *)0x0 ||
                                                                          ((*puVar7 & 0x4000000) == 0))))
  {
    instance_00 = *(_Instance **)&((_Instance *)message->Data)->node;
  }
  goto LAB_8008dd8c;
LAB_8008da4c:
  if (Data != 0x100000b)
  {
  LAB_8008dd8c:
    MON_PupateMessageHandler(instance, message);
  }
  goto LAB_8008da0c;
}

void MON_WanderEntry(_Instance *instance)

{
  _Position *in;
  short r;
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  instance->maxXVel = 10;
  instance->maxYVel = 10;
  instance->maxZVel = 0x11;
  if ((*puVar1 & 0x40000) == 0)
  {
    in = &instance->intro->position;
    if (instance->intro == (Intro *)0x0)
    {
      r = *(short *)((int)puVar1 + 0x136);
      in = &instance->position;
    }
    else
    {
      r = *(short *)((int)puVar1 + 0x136);
    }
    MON_GetRandomDestinationInWorld(instance, in, r);
  }
  return;
}

void SOUL_WanderEntry(_Instance *instance)

{
  long lVar1;
  u_char local_10;
  u_char local_c;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  if ((*puVar2 & 0x40000) == 0)
  {
    if (instance->intro == (Intro *)0x0)
    {
      MON_GetRandomDestinationInWorld(instance, &instance->position, *(short *)((int)puVar2 + 0x136));
      instance->zAccl = 0;
    }
    else
    {
      MON_GetRandomDestinationInWorld(instance, &instance->intro->position, *(short *)((int)puVar2 + 0x136));
      instance->zAccl = 0;
    }
  }
  else
  {
    lVar1 = MATH3D_LengthXYZ((int)*(short *)(puVar2 + 0x48) - (int)(instance->position).x,
                             (int)*(short *)((int)puVar2 + 0x122) - (int)(instance->position).y);
    if (lVar1 < 100)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
      instance->zAccl = 0;
    }
    else
    {
      instance->xAccl =
          ((int)*(short *)(puVar2 + 0x48) - (int)(instance->position).x) - instance->xVel;
      instance->yAccl =
          ((int)*(short *)((int)puVar2 + 0x122) - (int)(instance->position).y) - instance->yVel;
      lVar1 = -2;
      if ((instance->xAccl < -2) || (lVar1 = 2, 2 < instance->xAccl))
      {
        instance->xAccl = lVar1;
      }
      lVar1 = -2;
      if ((instance->yAccl < -2) || (lVar1 = 2, 2 < instance->yAccl))
      {
        instance->yAccl = lVar1;
      }
      instance->zAccl = 0;
    }
  }
  SOUL_Physics(instance, gameTrackerX.timeMult);
  if ((*puVar2 & 4) == 0)
  {
    if ((instance->flags2 & 0x8000000U) == 0)
    {
      SOUL_Flee(instance);
    }
    if (puVar2[0x31] != 0)
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
  }
  MON_GroundMoveQueueHandler(instance);
  return;
}

void MON_FleeEntry(_Instance *instance)

{
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
  instance->maxZVel = 0x11;
  MON_FallEntry(instance);
  return;
}

void SOUL_Fade(_Instance *instance)

{
  short angle;
  int iVar1;
  int iVar2;
  long lVar3;
  u_char unaff_s0;
  u_char unaff_s1;

  iVar1 = *(int *)((int)instance->extraData + 0xc4);
  if (iVar1 == 0)
  {
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  }
  else
  {
    angle = MATH3D_AngleFromPosToPos((_Position *)(*(int *)(iVar1 + 4) + 0x5c), &instance->position);
    angle = MONSENSE_GetDistanceInDirection(instance, angle, 500);
    iVar1 = rsin((int)angle);
    iVar1 = iVar1 * 2000;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0xfff;
    }
    iVar2 = rcos((int)angle);
    iVar2 = iVar2 * -2000;
    if (iVar2 < 0)
    {
      iVar2 = iVar2 + 0xfff;
    }
    instance->xAccl = (iVar1 >> 0xc) - instance->xVel;
    instance->yAccl = (iVar2 >> 0xc) - instance->yVel;
    lVar3 = -2;
    if ((instance->xAccl < -2) || (lVar3 = 2, 2 < instance->xAccl))
    {
      instance->xAccl = lVar3;
    }
    lVar3 = -2;
    if ((instance->yAccl < -2) || (lVar3 = 2, 2 < instance->yAccl))
    {
      instance->yAccl = lVar3;
    }
    instance->zAccl = 0;
  }
  SOUL_Physics(instance, gameTrackerX.timeMult);
  MON_GroundMoveQueueHandler(instance);
  if ((instance->flags2 & 0x8000000U) == 0)
  {
    SOUL_Flee(instance);
  }
  return;
}

void SOUL_FleeEntry(_Instance *instance)

{
  u_long uVar1;
  int iVar2;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
  instance->maxZVel = 0x11;
  uVar1 = MON_GetAnim(instance);
  iVar2 = rand();
  *puVar3 = *puVar3 & 0xfffbffff;
  puVar3[0x45] = uVar1 + iVar2 % 3000 + 3000;
  return;
}

void SOUL_Init(_Instance *instance)

{
  u_long uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u_char local_10;
  u_char local_c;
  u_int *puVar5;

  iVar2 = instance->xVel;
  puVar5 = (u_int *)instance->extraData;
  iVar4 = 3;
  if ((-4 < iVar2) && (iVar4 = -3, iVar2 < 4))
  {
    iVar4 = -iVar2;
  }
  iVar3 = instance->yVel;
  iVar2 = 3;
  if ((-4 < iVar3) && (iVar2 = -3, iVar3 < 4))
  {
    iVar2 = -iVar3;
  }
  instance->xAccl = iVar4;
  instance->yAccl = iVar2;
  instance->zAccl = 0;
  SOUL_Physics(instance, gameTrackerX.timeMult);
  if ((*puVar5 & 4) == 0)
  {
    if ((puVar5[0x31] != 0) || (uVar1 = MON_GetAnim(instance), puVar5[0x45] < uVar1))
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
    }
    if ((instance->flags2 & 0x8000000U) == 0)
    {
      SOUL_Flee(instance);
    }
  }
  MON_GroundMoveQueueHandler(instance);
  return;
}

void SOUL_ReanimateEntry(_Instance *instance)

{
  _Instance *p_Var1;
  void *pvVar2;

  pvVar2 = instance->extraData;
  p_Var1 = INSTANCE_Deactivate(*(long *)((int)pvVar2 + 0xd8));
  *(short *)((int)pvVar2 + 0x120) = (p_Var1->position).x;
  *(short *)((int)pvVar2 + 0x122) = (p_Var1->position).y;
  *(short *)((int)pvVar2 + 0x124) = (p_Var1->position).z + 0xa0;
  MON_TurnOnBodySpheres(instance);
  return;
}

void SOUL_Reanimate(_Instance *instance)

{
  long lVar1;
  _Instance *Inst;
  __Event *p_Var2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  SOUL_MoveToDest(instance, 0x10, gameTrackerX.timeMult);
  lVar1 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)((int)pvVar3 + 0x120),
                           (int)(instance->position).y - (int)*(short *)((int)pvVar3 + 0x122));
  if (lVar1 < 0xfa)
  {
    if (*(int *)((int)pvVar3 + 0xd8) != 0)
    {
      Inst = INSTANCE_Deactivate(*(int *)((int)pvVar3 + 0xd8));
      if (Inst != (_Instance *)0x0)
      {
        INSTANCE_Query(Inst, 0x100000d, 0);
      }
      SAVE_Instance(instance);
    }
    MON_KillMonster(instance);
  }
  else
  {
    do
    {
      p_Var2 = PurgeMessageQueue((__MessageQueue *)((int)pvVar3 + 8));
    } while (p_Var2 != (__Event *)0x0);
  }
  return;
}

void SOUL_Effect(_Instance *instance, evFXHitData *data)

{
  return;
}
