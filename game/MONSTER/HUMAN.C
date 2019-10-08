#include "THISDUST.H"
#include "HUMAN.H"

void HUMAN_WaitForWeapon(_Instance *instance, GameTracker *gameTracker)

{
  TDRFuncPtr_MONTABLE_GetInitFunc pTVar1;

  pTVar1 = MONTABLE_GetInitFunc(instance);
  (*pTVar1)(instance);
  if (instance->LinkChild != (_Instance *)0x0)
  {
    instance->processFunc = MonsterProcess;
    instance->flags = instance->flags & 0xfffff7ff;
    instance->flags2 = instance->flags2 & 0xdfffff7f;
  }
  return;
}

_Instance *HUMAN_CreateWeapon(_Instance *instance, int weaponid, int segment)

{
  _Instance *Inst;
  int Data;

  if (((Object *)(&objectAccess)[weaponid].object == (Object *)0x0) ||
      (Inst = INSTANCE_BirthObject(instance, (Object *)(&objectAccess)[weaponid].object, 0),
       Inst == (_Instance *)0x0))
  {
    Inst = (_Instance *)0x0;
    instance->processFunc = HUMAN_WaitForWeapon;
    instance->flags = instance->flags | 0x800;
    instance->flags2 = instance->flags2 | 0x20000080;
  }
  else
  {
    Data = SetObjectBreakOffData(0, 0, 0, instance, segment);
    INSTANCE_Query(Inst, 0x800002, Data);
    Inst->flags2 = Inst->flags2 | 0x20000;
  }
  return Inst;
}

void HUMAN_Init(_Instance *instance)

{
  short sVar1;
  u_int *puVar2;
  void *pvVar3;
  u_int *puVar4;

  pvVar3 = instance->data;
  puVar4 = (u_int *)instance->extraData;
  if ((*(u_int *)((int)pvVar3 + 0x10) & 0x2000) == 0)
  {
    sVar1 = GlobalSave->humanOpinionOfRaziel;
    puVar2 = *(u_int **)(puVar4[0x59] + 0xc);
    if (sVar1 < 1)
    {
      puVar2[3] = puVar2[3] & 0xfffffffe;
      puVar2[1] = puVar2[1] & 0xfffffffe;
      if (sVar1 < 0)
      {
        *puVar2 = *puVar2 | 1;
      }
    }
    else
    {
      *puVar2 = *puVar2 & 0xfffffffe;
      puVar2[3] = puVar2[3] | 1;
      puVar2[1] = puVar2[1] | 1;
    }
    if ((*(u_int *)((int)pvVar3 + 0x10) & 0x8000) != 0)
    {
      if (((*(char *)((int)puVar4 + 0x15a) == '\x01') && (instance->object->oflags == 0x72676c76)) && (*(int *)&instance->object->id == 0x5f5f5f61))
      {
        G2Anim_EnableSegment(&instance->anim, 4);
        G2Anim_EnableSegment(&instance->anim, 9);
      }
      G2Anim_EnableSegment(&instance->anim, 0x1d);
      G2Anim_EnableSegment(&instance->anim, 0x17);
    }
  }
  MON_SetDefaults(instance);
  *(undefined2 *)(puVar4 + 0x51) = 0x4000;
  *puVar4 = *puVar4 | 0x2000;
  return;
}

void MON_CleanUp(_Instance *instance)

{
  HUMAN_CleanUp(instance);
  return;
}

u_long HUMAN_Query(_Instance *instance, u_long query)

{
  u_long uVar1;
  u_int uVar2;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  uVar1 = 0;
  if (instance->data != (void *)0x0)
  {
    if (query == 0)
    {
      uVar2 = *puVar3;
      uVar1 = 0x40000000;
      if (((((uVar2 & 0x200) == 0) && (uVar1 = 0x12000000, instance->currentMainState != 0x1e)) &&
           (uVar1 = (u_int)((uVar2 & 0x100) != 0) << 0x1d, (uVar2 & 0x200000) == 0)) &&
          ((*(short *)(puVar3 + 0x50) < 0x1001 || ((puVar3[1] & 3) != 0))))
      {
        uVar1 = uVar1 | 0x8000000;
      }
    }
    else
    {
      if (query == 0x25)
      {
        uVar1 = 0;
        if ((*(u_int *)((int)instance->data + 0x10) & 0x8000) == 0)
        {
          uVar1 = **(u_int **)(puVar3[0x59] + 0xc) & 1;
        }
      }
      else
      {
        uVar1 = MonsterQuery(instance, query);
      }
    }
  }
  return uVar1;
}

void HUMAN_DeadEntry(_Instance *instance)

{
  int iVar1;
  u_long uVar2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  iVar1 = (int)*(short *)((int)pvVar3 + 0x144);
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 3;
  }
  *(undefined2 *)((int)pvVar3 + 0x144) = (short)(iVar1 >> 2);
  if (0x1000 < iVar1 >> 2)
  {
    *(undefined2 *)((int)pvVar3 + 0x144) = 0x1000;
  }
  MON_DeadEntry(instance);
  uVar2 = MON_GetAnim(instance);
  *(u_long *)((int)pvVar3 + 0x10c) = uVar2;
  MON_BirthEntry(instance);
  return;
}

void HUMAN_Dead(_Instance *instance)

{
  u_short uVar1;
  u_long uVar2;
  __Event *p_Var3;
  u_int *puVar4;

  puVar4 = (u_int *)instance->extraData;
  uVar2 = MON_GetAnim(instance);
  uVar1 = *(u_short *)(puVar4 + 0x43);
  instance->fadeValue = (short)(uVar2 - uVar1);
  if (*(char *)(puVar4 + 0x55) == '\x06')
  {
    MON_Dead(instance);
  }
  else
  {
    if (0xfff < (int)((uVar2 - uVar1) * 0x10000) >> 0x10)
    {
      MON_KillMonster(instance);
    }
    if (((*puVar4 & 0x400000) != 0) && (uVar2 = MON_GetAnim(instance), puVar4[0x46] < uVar2))
    {
      *puVar4 = *puVar4 & 0xffbfffff;
    }
    if ((*puVar4 & 2) == 0)
    {
      MON_ApplyPhysics(instance);
    }
    do
    {
      p_Var3 = PurgeMessageQueue((__MessageQueue *)(puVar4 + 2));
    } while (p_Var3 != (__Event *)0x0);
  }
  return;
}

void MON_StunnedEntry(_Instance *instance)

{
  u_long uVar1;
  u_char local_10;
  u_char local_c;
  void *pvVar2;
  u_char local_8;
  u_char in_stack_fffffffc;

  pvVar2 = instance->extraData;
  if ((*(u_int *)((int)pvVar2 + 4) & 0x10) == 0)
  {
    MON_Stunned(instance);
  }
  else
  {
    uVar1 = MON_GetAnim(instance);
    *(undefined **)((int)pvVar2 + 0x114) = &DAT_0000ea60 + uVar1;
    MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(local_8, CONCAT44(local_c, local_10))),
                 0x1e);
  }
  return;
}

void HUMAN_Stunned(_Instance *instance)

{
  u_long uVar1;
  u_char unaff_s0;
  void *pvVar2;
  u_char unaff_s1;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  pvVar2 = instance->extraData;
  if ((*(u_int *)((int)pvVar2 + 4) & 0x10) == 0)
  {
    HUMAN_StunnedEntry(instance);
  }
  else
  {
    if ((instance->flags2 & 0x10U) != 0)
    {
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 5);
    }
    uVar1 = MON_GetAnim(instance);
    if (*(u_int *)((int)pvVar2 + 0x114) < uVar1)
    {
      *(undefined2 *)((int)pvVar2 + 0x144) = 0x4000;
      *(u_int *)((int)pvVar2 + 4) = *(u_int *)((int)pvVar2 + 4) & 0xffffffef;
    }
    MON_DefaultMessageHandler(instance);
  }
  return;
}

void HUMAN_EmbraceEntry(_Instance *instance)

{
  int iVar1;
  u_char unaff_s0;
  u_char unaff_s1;
  void *pvVar2;
  u_char unaff_retaddr;
  u_char in_stack_fffffffc;

  pvVar2 = instance->extraData;
  MON_PlayAnim(instance, (MonsterAnim)CONCAT412(in_stack_fffffffc, CONCAT48(unaff_retaddr, CONCAT44(unaff_s1, unaff_s0))), 0x25);
  MON_TurnOnBodySpheres(instance);
  iVar1 = (int)*(short *)((int)pvVar2 + 0x144);
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  *(int *)((int)pvVar2 + 0x114) = iVar1 >> 0xc;
  return;
}

void HUMAN_Embrace(_Instance *instance)

{
  bool bVar1;
  __Event *message;
  u_int Data;
  void *pvVar2;
  u_char local_20;
  u_char in_stack_ffffffe4;

  bVar1 = false;
  pvVar2 = instance->extraData;
  MON_MoveToPosition(instance, &(gameTrackerX.playerInstance)->position, 0x1000);
  while (message = PurgeMessageQueue((__MessageQueue *)((int)pvVar2 + 8)), message != (__Event *)0x0)
  {
    if (message->ID == 0x1000014)
    {
      bVar1 = true;
    }
    else
    {
      MON_PupateMessageHandler(instance, message);
    }
  }
  5000;
  INSTANCE_Query(gameTrackerX.playerInstance, 0x1000016, Data);
  if ((int)*(short *)((int)pvVar2 + 0x144) < (int)Data)
  {
    *(undefined2 *)((int)pvVar2 + 0x144) = 0;
  }
  else
  {
    *(short *)((int)pvVar2 + 0x144) = *(short *)((int)pvVar2 + 0x144) - (short)Data;
  }
  GAMEPAD_HandleDualShock

                    (u_int)(*(int *)((int)pvVar2 + 0x114) << 0xc),0xf000);
  if (*(short *)((int)pvVar2 + 0x144) == 0)
  {
    *(undefined2 *)((int)pvVar2 + 0x150) = 0;
    MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffe4, local_20));
    INSTANCE_Query(gameTrackerX.playerInstance, 0x1000006, (int)instance);
    *(undefined2 *)((int)pvVar2 + 0x144) = 0;
    SOUND_Play3dSound(&instance->position, 8, -0x1c2, 0x50, 0xdac);
  }
  else
  {
    if (bVar1)
    {
      *(u_int *)((int)pvVar2 + 4) = *(u_int *)((int)pvVar2 + 4) | 0x10;
      MON_SwitchState(instance, (MonsterState)CONCAT44(in_stack_ffffffe4, local_20));
    }
    else
    {
      if (instance->currentMainState == 0x1b)
      {
        return;
      }
      INSTANCE_Query(gameTrackerX.playerInstance, 0x1000006, (int)instance);
    }
    MON_TurnOnWeaponSphere(instance);
  }
  return;
}

void HUMAN_IdleEntry(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_IdleEntry(instance);
  *(u_int *)((int)pvVar1 + 4) = *(u_int *)((int)pvVar1 + 4) & 0xfffffff8;
  return;
}

void HUMAN_Idle(_Instance *instance)

{
  u_int uVar1;
  u_int uVar2;
  char *animList;
  int animtype;
  void *pvVar3;
  int mode;
  u_int *puVar4;

  puVar4 = (u_int *)instance->extraData;
  pvVar3 = instance->data;
  uVar1 = puVar4[0x33];
  if ((((*puVar4 & 4) != 0) || (uVar1 == 0)) || ((*(u_short *)(uVar1 + 0x16) & 4) == 0))
  {
  LAB_8007cd70:
    MON_IdleQueueHandler(instance);
    return;
  }
  uVar2 = puVar4[1];
  if ((uVar2 & 2) == 0)
  {
    if ((uVar2 & 1) == 0)
    {
      if ((uVar2 & 4) != 0)
      {
        if ((instance->flags2 & 0x10U) != 0)
        {
          puVar4[1] = uVar2 & 0xfffffffb;
          MON_PlayRandomIdle(instance, 2);
        }
        goto LAB_8007cd60;
      }
      if (1999 < *(short *)(uVar1 + 0x14))
        goto LAB_8007cd70;
      animtype = 0;
      puVar4[1] = uVar2 | 2;
      animList = *(char **)((int)pvVar3 + 8);
      mode = 2;
    }
    else
    {
      if (*(short *)(uVar1 + 0x14) < 2000)
        goto LAB_8007cd60;
      animtype = 1;
      puVar4[1] = uVar2 & 0xfffffffe | 4;
      animList = *(char **)((int)pvVar3 + 8);
      mode = 1;
    }
    MON_PlayAnimFromListIfNotPlaying(instance, animList, animtype, mode);
  }
  else
  {
    MON_MoveToPosition(instance, (_Position *)(*(int *)(uVar1 + 4) + 0x5c),
                       *(short *)(puVar4[0x59] + 0x1c));
    if ((instance->flags2 & 2U) != 0)
    {
      puVar4[1] = puVar4[1] & 0xfffffffd | 1;
    }
  }
LAB_8007cd60:
  MON_DefaultMessageHandler(instance);
  return;
}

void HUMAN_Flee(_Instance *instance)

{
  u_char unaff_s0;
  u_int *puVar1;
  u_char unaff_s1;
  u_int uVar2;

  puVar1 = (u_int *)instance->extraData;
  uVar2 = puVar1[0x31];
  if ((uVar2 == 0) || (0x27f < *(short *)(uVar2 + 0x14)))
  {
    if ((puVar1[1] & 8) == 0)
    {
      MON_Flee(instance);
    }
    else
    {
      MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
    }
  }
  else
  {
    if ((puVar1[1] & 8) == 0)
    {
      MON_PlayAnimFromListIfNotPlaying(instance, *(char **)((int)instance->data + 8), 2, 2);
      puVar1[1] = puVar1[1] | 8;
    }
    MON_MoveToPosition(instance, (_Position *)(*(int *)(uVar2 + 4) + 0x5c),
                       *(short *)(puVar1[0x59] + 0x1c));
    MON_DefaultMessageHandler(instance);
  }
  if (((puVar1[1] & 8) != 0) && ((*puVar1 & 1) != 0))
  {
    puVar1[1] = puVar1[1] & 0xfffffff7;
  }
  return;
}

void HUMAN_GetAngry(void)

{
  u_long uVar1;
  _MonsterIR *p_Var2;
  u_int *puVar3;
  _Instance *Inst;

  Inst = (gameTrackerX.instanceList)->first;
  while (Inst != (_Instance *)0x0)
  {
    uVar1 = INSTANCE_Post(Inst, 1);
    if ((uVar1 & 0xc000) != 0)
    {
      puVar3 = *(u_int **)(*(int *)((int)Inst->extraData + 0x164) + 0xc);
      puVar3[3] = puVar3[3] & 0xfffffffe;
      puVar3[1] = puVar3[1] & 0xfffffffe;
      *puVar3 = *puVar3 | 1;
      p_Var2 = MONSENSE_See(Inst, gameTrackerX.playerInstance);
      if (p_Var2 != (_MonsterIR *)0x0)
      {
        p_Var2->mirFlags = p_Var2->mirFlags & 0xfff9;
      }
    }
    Inst = Inst->next;
  }
  return;
}
