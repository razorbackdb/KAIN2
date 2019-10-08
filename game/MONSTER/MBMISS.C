#include "THISDUST.H"
#include "MBMISS.H"

void WCBEGG_Message(_Instance *instance, u_long message, u_long data)

{
  u_long uVar1;
  void *pvVar2;

  if (message == 0x800002)
  {
    pvVar2 = instance->extraData;
    uVar1 = MON_GetAnim(instance);
    *(u_long *)((int)pvVar2 + 0x28) = uVar1;
    G2EmulationSwitchAnimationCharacter(instance, 0, 1, 0, 0, 2, 0);
  }
  CollidePhysicalObject(instance, message, data);
  return;
}

int WCBEGG_ShouldIgniteEgg(_Instance *egg, _walbossAttributes *wa)

{
  _InstanceList *p_Var1;
  u_long uVar2;
  long lVar3;
  int iVar4;
  _Instance *Inst;

  p_Var1 = gameTrackerX.instanceList;
  uVar2 = INSTANCE_Post(egg, 3);
  if ((uVar2 & 0x10000) == 0)
  {
    Inst = p_Var1->first;
    while (Inst != (_Instance *)0x0)
    {
      uVar2 = INSTANCE_Post(Inst, 1);
      if ((((uVar2 & 0x20) != 0) &&
           (lVar3 = MATH3D_LengthXY((int)(Inst->position).x - (int)(egg->position).x,
                                    (int)(Inst->position).y - (int)(egg->position).y,
                                    (int)(Inst->position).z - (int)(egg->position).z),
            lVar3 < wa->eggIgniteDist)) &&
          (iVar4 = strcpy(Inst->object->name, "walfire_"), iVar4 == 0))
      {
        return 1;
      }
      Inst = Inst->next;
    }
  }
  return 0;
}

void WCBEGG_ExplodeProcess(_Instance *instance, GameTracker *gameTracker)

{
  u_long uVar1;
  Object *pOVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  _walbossAttributes *wa;

  pvVar3 = instance->extraData;
  uVar1 = MON_GetAnim(instance);
  iVar5 = uVar1 - gameTrackerX.lastLoopTime;
  pOVar2 = OBTABLE_RelocateObjectTune("walboss_");
  if (pOVar2 != (Object *)0x0)
  {
    wa = *(_walbossAttributes **)((int)pOVar2->data + 4);
    iVar4 = *(int *)((int)pvVar3 + 0x28) + (int)wa->timeToEggThrob * 0x21;
    if ((iVar5 < iVar4) && (iVar4 <= (int)uVar1))
    {
      G2EmulationSwitchAnimationCharacter(instance, 0, 2, 0, 0, 2, 0);
    }
    iVar4 = iVar4 + (int)wa->timeToEggExplode * 0x21;
    if ((iVar5 < iVar4) && (iVar4 <= (int)uVar1))
    {
      G2EmulationSwitchAnimationCharacter(instance, 0, 3, 0, 0, 1, 0);
    }
    if ((iVar5 < iVar4 + 0x35a) && (iVar4 + 0x35a <= (int)uVar1))
    {
      if (gameTrackerX.playerInstance == instance->LinkParent)
      {
        INSTANCE_Query(gameTrackerX.playerInstance, 0x40005, (int)wa->razielStunTime * 0x21);
      }
      G2EmulationSwitchAnimationCharacter(instance, 0, 5, 0, 0, 1, 0);
    }
    if ((int)uVar1 < iVar4 + 0xef4)
    {
      iVar5 = WCBEGG_ShouldIgniteEgg(instance, wa);
      if (iVar5 != 0)
      {
        INSTANCE_Query(instance, 0x800029, 1);
      }
      PhysicalObjectQuery(instance, gameTracker);
      return;
    }
  }
  INSTANCE_NewInstance(instance);
  return;
}

void WCBEGG_Process(_Instance *instance, GameTracker *gameTracker)

{
  u_long uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;

  pvVar3 = instance->extraData;
  uVar1 = MON_GetAnim(instance);
  iVar2 = *(int *)((int)pvVar3 + 0x28);
  iVar4 = iVar2 + 0x14a;
  if (((int)(uVar1 - gameTrackerX.lastLoopTime) < iVar4) && (iVar4 <= (int)uVar1))
  {
    G2EmulationSwitchAnimationCharacter(instance, 0, 5, 0, 0, 1, 0);
  }
  if ((int)uVar1 < iVar2 + 0xce4)
  {
    G2EmulationSwitchAnimation(instance);
  }
  else
  {
    INSTANCE_NewInstance(instance);
  }
  return;
}

void WCBEGG_ExplodeCollide(_Instance *instance, GameTracker *gameTracker)

{
  byte bVar1;
  u_long uVar2;
  void *pvVar3;
  _Instance *Inst;
  u_int *puVar4;

  pvVar3 = instance->collideInfo;
  puVar4 = (u_int *)instance->extraData;
  bVar1 = *(byte *)((int)pvVar3 + 7);
  if ((((bVar1 == 1) && (*(char *)(*(int *)((int)pvVar3 + 0xc) + 4) == '\b')) &&
       (Inst = *(_Instance **)((int)pvVar3 + 0x14), Inst != (_Instance *)0x0)) &&
      (uVar2 = INSTANCE_Post(Inst, 1), uVar2 == 0x10102))
  {
    if (((*puVar4 & 0x10000) != 0) && (instance->LinkParent == (_Instance *)0x0))
    {
      INSTANCE_Query(Inst, 0x1000017, 2);
      G2EmulationSwitchAnimationCharacter(instance, 0, 4, 0, 0, (u_int)bVar1, 0);
      instance->processFunc = WCBEGG_Process;
      uVar2 = MON_GetAnim(instance);
      puVar4[10] = uVar2;
    }
    TurnOnCollisionPhysOb(instance, 7);
  }
  else
  {
    InitPhysicalObject(instance, gameTracker);
    *(undefined2 *)((int)puVar4 + 0x3e) = 0;
    *(undefined2 *)(puVar4 + 0xf) = 0;
    *(undefined2 *)((int)puVar4 + 0x3a) = 0;
    *(u_short *)((int)puVar4 + 0x36) = *(u_short *)((int)puVar4 + 0x36) & 0xfffe;
  }
  return;
}

void WCBEGG_Collide(_Instance *instance, GameTracker *gameTracker)

{
  if (*(char *)((int)instance->collideInfo + 7) == '\x03')
  {
    TurnOnCollisionPhysOb(instance, 7);
    instance->collideFunc = WCBEGG_ExplodeCollide;
  }
  InitPhysicalObject(instance, gameTracker);
  return;
}

long WALBOSC_AnimCallback(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message, long messageDataA,
                          long messageDataB, _Instance *instance)

{
  if (message == G2ANIM_MSG_DONE)
  {
    COLLIDE_SegmentCollisionOn(instance, 1);
    FX_StopInstanceBurrow(instance);
    instance->flags = instance->flags | 0x800;
    instance->flags2 = instance->flags2 | 0x20000000;
  }
  else
  {
    INSTANCE_DefaultAnimCallback(anim, sectionID, message, messageDataA, messageDataB, instance);
  }
  return messageDataA;
}

void WALBOSC_Collide(_Instance *instance, GameTracker *gameTracker)

{
  int Data;
  void *pvVar1;
  void *pvVar2;
  _Instance *Inst;

  pvVar1 = instance->collideInfo;
  Inst = *(_Instance **)((int)pvVar1 + 0x14);
  if (*(char *)(*(int *)((int)pvVar1 + 0xc) + 4) == '\b')
  {
    pvVar2 = instance->data;
    COLLIDE_SegmentCollisionOn(instance, 1);
    Data = *(int *)((int)pvVar2 + 8);
    if (Data < 0)
    {
      Data = Data + 0x7f;
    }
    Data = SetFXHitData(instance, (u_int) * (byte *)((int)pvVar1 + 5), Data >> 7, 0x100);
    INSTANCE_Query(Inst, 0x400000, Data);
    Data = SetMonsterImpaleData(instance, (_Instance *)0x0, *(int *)((int)pvVar2 + 8),
                                (int)*(short *)((int)pvVar2 + 0x10), (int)*(char *)((int)pvVar2 + 0x12));
    INSTANCE_Query(Inst, 0x1000000, Data);
  }
  return;
}

void WALBOSC_Message(_Instance *instance, u_long message, u_long data)

{
  if ((message == 0x1000017) && (data == 0))
  {
    COLLIDE_SegmentCollisionOn(instance, 1);
    instance->flags2 = instance->flags2 | 0x20000000;
  }
  return;
}
