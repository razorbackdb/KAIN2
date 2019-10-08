#include "THISDUST.H"
#include "MONLIB.H"

void MON_TurnOnWeaponSpheres(_Instance *instance)

{
  _HPrim *p_Var1;
  _Instance *instance_00;
  int *piVar2;
  int iVar3;
  u_int *puVar4;

  instance_00 = instance->LinkChild;
  puVar4 = (u_int *)instance->extraData;
  while (instance_00 != (_Instance *)0x0)
  {
    TurnOnCollisionPhysOb(instance_00, 3);
    instance_00 = instance_00->LinkSibling;
  }
  if ((*puVar4 & 0x4000) != 0)
  {
    iVar3 = instance->hModelList[instance->currentModel].numHPrims;
    p_Var1 = instance->hModelList[instance->currentModel].hPrimList;
    if (iVar3 != 0)
    {
      piVar2 = &p_Var1->data;
      do
      {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\t'))
        {
          p_Var1->hpFlags = p_Var1->hpFlags & 0xfe;
        }
        iVar3 = iVar3 + -1;
        piVar2 = piVar2 + 2;
        p_Var1 = p_Var1 + 1;
      } while (iVar3 != 0);
    }
    *puVar4 = *puVar4 & 0xffffbfff;
  }
  return;
}

void MON_TurnOnWeaponSpheres(_Instance *instance)

{
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  u_int *puVar5;

  puVar5 = (u_int *)instance->extraData;
  if (((*puVar5 & 0x4000) == 0) && (instance->hModelList != (_HModel *)0x0))
  {
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0)
    {
      piVar2 = &p_Var3->data;
      do
      {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\t'))
        {
          p_Var3->hpFlags = p_Var3->hpFlags | 1;
          break;
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 2;
        p_Var3 = p_Var3 + 1;
      } while (iVar4 != 0);
    }
    *puVar5 = *puVar5 | 0x4000;
  }
  return;
}

void MON_TurnOffAllSpheres(_Instance *instance, int segment)

{
  _Instance *instance_00;
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  u_int *puVar5;

  puVar5 = (u_int *)instance->extraData;
  if (instance->LinkChild == (_Instance *)0x0)
  {
    if ((*puVar5 & 0x4000) != 0)
    {
      return;
    }
    if (instance->hModelList == (_HModel *)0x0)
    {
      return;
    }
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0)
    {
      piVar2 = &p_Var3->data;
      do
      {
        if ((((u_int) * (byte *)((int)piVar2 + -1) == segment) &&
             (*(char *)((int)piVar2 + -2) == '\x01')) &&
            (*(char *)(*piVar2 + 4) == '\t'))
        {
          p_Var3->hpFlags = p_Var3->hpFlags | 1;
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 2;
        p_Var3 = p_Var3 + 1;
      } while (iVar4 != 0);
    }
  }
  else
  {
    instance_00 = INSTANCE_GetChildLinkedToSegment(instance, segment);
    if (instance_00 == (_Instance *)0x0)
    {
      return;
    }
    TurnOffCollisionPhysOb(instance_00, 3);
  }
  *puVar5 = *puVar5 | 0x4000;
  return;
}

void MON_TurnOnBodySpheres(_Instance *instance)

{
  _HPrim *p_Var1;
  int *piVar2;
  int iVar3;
  u_int *puVar4;

  puVar4 = (u_int *)instance->extraData;
  if ((*puVar4 & 0x8000) != 0)
  {
    iVar3 = instance->hModelList[instance->currentModel].numHPrims;
    p_Var1 = instance->hModelList[instance->currentModel].hPrimList;
    if (iVar3 != 0)
    {
      piVar2 = &p_Var1->data;
      do
      {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\b'))
        {
          p_Var1->hpFlags = p_Var1->hpFlags & 0xfe;
        }
        iVar3 = iVar3 + -1;
        piVar2 = piVar2 + 2;
        p_Var1 = p_Var1 + 1;
      } while (iVar3 != 0);
    }
    *puVar4 = *puVar4 & 0xffff7fff;
  }
  return;
}

void MON_TurnOnWeaponSphere(_Instance *instance)

{
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  u_int *puVar5;

  puVar5 = (u_int *)instance->extraData;
  if (((*puVar5 & 0x8000) == 0) && (instance->hModelList != (_HModel *)0x0))
  {
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0)
    {
      piVar2 = &p_Var3->data;
      do
      {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\b'))
        {
          p_Var3->hpFlags = p_Var3->hpFlags | 1;
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 2;
        p_Var3 = p_Var3 + 1;
      } while (iVar4 != 0);
    }
    *puVar5 = *puVar5 | 0x8000;
  }
  return;
}

void MON_TurnOffWeaponSpheres(_Instance *instance)

{
  MON_TurnOnWeaponSpheres(instance);
  MON_TurnOnBodySpheres(instance);
  return;
}

void MON_TurnOffBodySpheres(_Instance *instance)

{
  MON_TurnOnWeaponSpheres(instance);
  MON_TurnOnWeaponSphere(instance);
  return;
}

void MON_SwitchState(_Instance *instance, MonsterState state)

{
  int in_a1;
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  if ((*puVar1 & 0x4000) != 0)
  {
    MON_TurnOnWeaponSpheres(instance);
  }
  if ((*puVar1 & 1) == 0)
  {
    *(undefined *)((int)puVar1 + 0x155) = *(undefined *)&instance->currentMainState;
  }
  if ((((in_a1 == 0x10) || (in_a1 == 0x17)) || (in_a1 == 7)) || ((in_a1 == 10 || (in_a1 == 3))))
  {
    EnMessageQueueData((__MessageQueue *)(puVar1 + 2));
  }
  instance->currentMainState = in_a1;
  *puVar1 = *puVar1 & 0xbbfdefff | 1;
  if ((int)*(char *)((int)puVar1 + 0x162) != -1)
  {
    ENMYPLAN_GetInitializedPlanningWorkspaceFinal((int)*(char *)((int)puVar1 + 0x162));
    *(undefined *)((int)puVar1 + 0x162) = 0xff;
  }
  return;
}

void MON_SwitchStateDoEntry(_Instance *instance, MonsterState state)

{
  _MonsterState *p_Var1;
  u_char unaff_s0;
  u_int *puVar2;
  u_char unaff_s1;

  puVar2 = (u_int *)instance->extraData;
  MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
  if (puVar2 != (u_int *)0x0)
  {
    p_Var1 = MON_DamageEffect(instance, instance->currentMainState);
    (*p_Var1->entryFunction)(instance);
    *puVar2 = *puVar2 & 0xfffffffe;
  }
  return;
}

int MON_TransNodeAnimation(_Instance *instance)

{
  _G2Bool_Enum _Var1;

  _Var1 = G2Anim_SegmentHasActiveChannels(&instance->anim, 0, 0x700);
  return _Var1;
}

_MonsterAnim *MON_GetTime(_Instance *instance, char *animList, int index)

{
  if ((int)animList[index] != -1)
  {
    return (_MonsterAnim *)(*(int *)((int)instance->data + 0x40) + (int)animList[index] * 0x10);
  }
  return (_MonsterAnim *)0x0;
}

void MON_PlayAnimID(_Instance *instance, int index, int mode)

{
  byte bVar1;
  byte bVar2;
  u_int uVar3;
  int NewAnim;
  int CurrentSection;
  u_int uVar4;
  u_int *puVar5;
  int iVar6;

  uVar4 = *(int *)((int)instance->data + 0x40) + index * 0x10;
  iVar6 = (int)*(char *)(uVar4 + 0xc);
  puVar5 = (u_int *)instance->extraData;
  if ((iVar6 < 0) || (instance->object->numAnims <= iVar6))
  {
    iVar6 = 0;
  }
  MON_AnimCallback(&instance->anim, INSTANCE_DefaultAnimCallback, instance);
  uVar3 = puVar5[0x2f];
  if ((uVar3 == 0) || (bVar1 = *(byte *)(uVar3 + 8), bVar1 == 0))
  {
    bVar1 = *(byte *)(uVar4 + 6);
    bVar2 = *(byte *)(uVar4 + 9);
  }
  else
  {
    bVar2 = *(byte *)(uVar3 + 10);
  }
  CurrentSection = 0;
  uVar3 = uVar4;
  if (*(char *)(puVar5[0x59] + 0x2a) != '\0')
  {
    do
    {
      NewAnim = (int)*(char *)(uVar3 + 0xc);
      if ((int)*(char *)(uVar3 + 0xc) == -1)
      {
        NewAnim = iVar6;
      }
      G2EmulationSwitchAnimationCharacter(instance, CurrentSection, NewAnim, (u_int) * (byte *)(uVar4 + 7), (u_int)bVar1, mode,
                                          (u_int)bVar2);
      G2EmulationSetAnimation(instance, CurrentSection, (u_int) * (u_short *)(uVar4 + 4));
      CurrentSection = CurrentSection + 1;
      uVar3 = uVar4 + CurrentSection;
    } while (CurrentSection < (int)(u_int) * (byte *)(puVar5[0x59] + 0x2a));
  }
  puVar5[0x2f] = uVar4;
  *puVar5 = *puVar5 | 0x4000000;
  (instance->anim).section[*(byte *)(uVar4 + 0xb)].callback = StopCallback;
  *(_Instance **)&(instance->anim).section[*(byte *)(uVar4 + 0xb)].callbackData = instance;
  return;
}

void MON_PlayAnimFromListIfNotPlaying(_Instance *instance, char *animList, int animtype, int mode)

{
  MON_PlayAnimID(instance, (int)animList[animtype], mode);
  return;
}

int MON_PlayAnimIDIfNotPlaying(_Instance *instance, int index)

{
  return (u_int)(*(int *)((int)instance->extraData + 0xbc) ==
                 *(int *)((int)instance->data + 0x40) + index * 0x10);
}

void MON_PlayAnimIfNotPlaying(_Instance *instance, int index, int mode)

{
  int iVar1;

  iVar1 = MON_PlayAnimIDIfNotPlaying(instance, index);
  if (iVar1 == 0)
  {
    MON_PlayAnimID(instance, index, mode);
  }
  return;
}

int MON_AnimPlayingFromList(_Instance *instance, char *animList, int animtype)

{
  int iVar1;

  iVar1 = MON_PlayAnimIDIfNotPlaying(instance, (int)animList[animtype]);
  return iVar1;
}

void MON_AnimPlayingFromList(_Instance *instance, char *animList, int animtype, int mode)

{
  char cVar1;
  int iVar2;

  cVar1 = animList[animtype];
  iVar2 = MON_PlayAnimIDIfNotPlaying(instance, (int)cVar1);
  if (iVar2 == 0)
  {
    MON_PlayAnimID(instance, (int)cVar1, mode);
  }
  return;
}

void MON_PlayAnim(_Instance *instance, MonsterAnim animtype, int mode)

{
  int in_a2;

  MON_PlayAnimFromListIfNotPlaying(instance, **(char ***)((int)instance->extraData + 0x164), mode, in_a2);
  return;
}

int MON_AnimPlaying(_Instance *instance, MonsterAnim animtype)

{
  int iVar1;
  int in_a1;

  iVar1 = MON_AnimPlayingFromList(instance, **(char ***)((int)instance->extraData + 0x164), in_a1);
  return iVar1;
}

void MON_PlayAnimFromList(_Instance *instance, MonsterAnim animtype, int mode)

{
  int in_a2;

  MON_AnimPlayingFromList(instance, **(char ***)((int)instance->extraData + 0x164), mode, in_a2);
  return;
}

long StopCallback(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message, long messageDataA, long messageDataB, void *data)

{
  if (message == G2ANIM_MSG_LOOPPOINT)
  {
    *(u_int *)((int)data + 0x18) = *(u_int *)((int)data + 0x18) | 2;
  }
  else
  {
    if (message < G2ANIM_MSG_SECTION_INTERPDONE)
    {
      if (message == G2ANIM_MSG_DONE)
      {
        *(u_int *)((int)data + 0x18) = *(u_int *)((int)data + 0x18) | 0x10;
        **(u_int **)((int)data + 0x168) = **(u_int **)((int)data + 0x168) & 0xfbffffff;
        return messageDataA;
      }
    }
    else
    {
      if (message == G2ANIM_MSG_SEGCTRLR_INTERPDONE)
      {
        return messageDataA;
      }
    }
    INSTANCE_DefaultAnimCallback(anim, sectionID, message, messageDataA, messageDataB, (_Instance *)data);
  }
  return messageDataA;
}

void MON_AnimIDPlaying(_Instance *instance)

{
  byte bVar1;
  byte bVar2;
  int CurrentSection;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  pvVar3 = instance->extraData;
  iVar6 = 0;
  bVar1 = *(byte *)(*(int *)((int)pvVar3 + 0x164) + 0x2a);
  CurrentSection = 0;
  *(u_char *)((int)pvVar3 + 0xbc) = 0;
  G2EmulationInit(instance, (u_short)bVar1);
  iVar5 = 0x94;
  if (bVar1 != 0)
  {
    iVar4 = 0x1e8;
    do
    {
      bVar2 = *(byte *)(*(int *)((int)pvVar3 + 0x164) + CurrentSection + 0x2b);
      if (bVar2 == 0)
      {
        G2EmulationInstanceToInstanceSwitchAnimation(instance, CurrentSection, (short)iVar6,
                                                     (short)(((u_int) * (u_short *)&instance->object->modelList[instance->currentModel]->numSegments - 1) * 0x10000 >> 0x10));
      }
      else
      {
        G2EmulationInstanceToInstanceSwitchAnimation(instance, CurrentSection, (short)iVar6, (u_short)bVar2);
        iVar6 = (u_int) * (byte *)(*(int *)((int)pvVar3 + 0x164) + CurrentSection + 0x2b) + 1;
      }
      _G2AnimSection_InterpStateToQuat((_G2AnimSection_Type *)((int)&(instance->node).prev + iVar4),
                                       (_G2AnimInterpInfo_Type *)((int)pvVar3 + iVar5));
      G2EmulationInstanceToInstanceSwitchAnimationCharacter(instance, CurrentSection, 0, 0, 0);
      G2EmulationInstanceInitSection(instance, CurrentSection, 2);
      iVar5 = iVar5 + 0xc;
      CurrentSection = CurrentSection + 1;
      iVar4 = iVar4 + 0x30;
    } while (CurrentSection < (int)(u_int)bVar1);
  }
  G2EmulationInstanceQueryFrame(instance, 0, StopCallback, instance);
  MON_PlayRandomIdle(instance, 2);
  return;
}

short MON_FacingOffset(_Instance *instance, _Instance *target)

{
  u_short uVar1;

  uVar1 = MATH3D_AngleFromPosToPos(&target->position, &instance->position);
  return (short)(((u_int)uVar1 - (u_int)(u_short)(target->rotation).z) * 0x10000 >> 0x10);
}

int MON_CheckConditions(_Instance *instance, _MonsterIR *mir, char *probArray)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u_int uVar4;

  iVar2 = 100;
  iVar3 = 100;
  uVar4 = 1;
  do
  {
    if ((mir->mirConditions & uVar4) != 0)
    {
      iVar1 = (int)*probArray;
      if (iVar1 < 0)
      {
        100;
      }
      else
      {
        100;
      }
    }
    uVar4 = uVar4 << 1;
    probArray = probArray + 1;
  } while ((int)uVar4 < 0x1000);
 100);
}

int MON_ShouldIAttackInstance(_Instance *instance, _MonsterIR *enemy, _MonsterAttackAttributes *attack)

{
  short angle;
  _Instance *p_Var1;
  u_long uVar2;
  int iVar3;
  int iVar4;
  _Instance *Inst;
  void *pvVar5;

  Inst = enemy->instance;
  pvVar5 = instance->extraData;
  if (Inst == gameTrackerX.playerInstance)
  {
    p_Var1 = (_Instance *)INSTANCE_Post(Inst, 0x22);
    uVar2 = INSTANCE_Post(Inst, 10);
    if ((uVar2 & 0x20010000) == 0)
    {
      if (((p_Var1 != (_Instance *)0x0) && (p_Var1 != instance)) && ((uVar2 & 0x2000000) != 0))
      {
        return 0;
      }
      uVar2 = INSTANCE_Post(Inst, 0x2e);
      if (uVar2 == 0)
        goto LAB_80080058;
    }
    iVar3 = 0;
  }
  else
  {
  LAB_80080058:
    iVar3 = 0;
    if (attack != (_MonsterAttackAttributes *)0x0)
    {
      if ((Inst == gameTrackerX.playerInstance) &&
          (iVar3 = MON_CheckConditions(instance, enemy, attack->attackProbability), iVar3 == 0))
      {
        return 0;
      }
      iVar4 = (int)attack->attackRange - (int)enemy->distance;
      if ((enemy->mirFlags & 8) == 0)
      {
        if (iVar4 < -0x96)
        {
          iVar3 = 5;
        }
        else
        {
          if (iVar4 < 0x97)
          {
            iVar3 = (int)(enemy->relativePosition).y;
            if (iVar3 < 1)
            {
              iVar4 = (int)(enemy->relativePosition).x;
              if (iVar4 < 0)
              {
                iVar4 = -iVar4;
              }
              if (iVar4 <= -iVar3)
              {
                if ((enemy->mirFlags & 0x20) == 0)
                {
                  return 3;
                }
                iVar3 = *(int *)((int)pvVar5 + 0xcc);
                if ((iVar3 != 0) &&
                    (uVar2 = INSTANCE_Post(*(_Instance **)(iVar3 + 4), 10), (uVar2 & 0x200000) != 0))
                {
                  return 7;
                }
                angle = MATH3D_AngleFromPosToPos(&instance->position, &Inst->position);
                iVar3 = MONSENSE_GetClosestFreeDirection(instance, angle);
                if (enemy->distance < iVar3)
                {
                  enemy->mirConditions = 0;
                  return 1;
                }
                return 0;
              }
            }
            iVar3 = 6;
          }
          else
          {
            iVar3 = 4;
          }
        }
      }
      else
      {
        if (iVar4 < 0)
        {
          iVar4 = -iVar4;
        }
        iVar3 = 5;
        if (iVar4 < 1000)
        {
          iVar3 = 1;
        }
      }
    }
  }
  return iVar3;
}

_MonsterAttackAttributes *MON_Attack(_Instance *instance, _MonsterIR *enemy)

{
  int iVar1;
  int iVar2;
  int iVar3;
  MATRIX *pMVar4;
  _MonsterAttackAttributes *p_Var5;
  int iVar6;
  char *pcVar7;
  u_int *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  _MonsterAttackAttributes *p_Var12;

  p_Var12 = (_MonsterAttackAttributes *)0x0;
  iVar9 = 0x100;
  puVar8 = (u_int *)instance->extraData;
  iVar11 = 99999;
  if (((*puVar8 & 4) == 0) && ((enemy->mirFlags & 8) == 0))
  {
    pMVar4 = enemy->instance->matrix;
    iVar10 = (int)enemy->distance;
    if (pMVar4 != (MATRIX *)0x0)
    {
      if (enemy->instance == gameTrackerX.playerInstance)
      {
        iVar9 = pMVar4[0xe].t[2] - (int)(instance->position).z;
      }
      else
      {
        iVar9 = pMVar4[1].t[2] - (int)(instance->position).z;
      }
    }
  }
  else
  {
    iVar10 = 0;
  }
  iVar6 = (int)*(char *)(*(int *)(puVar8[0x59] + 8) + 0x19);
  pcVar7 = (char *)(*(int *)(puVar8[0x59] + 8) + 0x28);
  if (iVar6 != 0)
  {
    do
    {
      p_Var5 = (_MonsterAttackAttributes *)(*(int *)((int)instance->data + 0x38) + (int)*pcVar7 * 0x20);
      iVar2 = iVar9 - p_Var5->attackHeight;
      if (iVar2 < 0)
      {
        iVar2 = -iVar2;
      }
      if ((iVar2 < 100) || ((enemy->mirFlags & 8) != 0))
      {
        iVar2 = (int)p_Var5->attackRange * (int)*(short *)(puVar8[0x59] + 0x14);
        if (iVar2 < 0)
        {
          iVar2 = iVar2 + 0xfff;
        }
        iVar3 = (iVar2 >> 0xc) - iVar10;
        iVar2 = iVar3;
        if (iVar3 < 0)
        {
          iVar2 = -iVar3;
        }
        iVar1 = iVar11;
        if (iVar11 < 0)
        {
          iVar1 = -iVar11;
        }
        if (iVar2 < iVar1)
        {
          iVar11 = iVar3;
          p_Var12 = p_Var5;
        }
      }
      iVar6 = iVar6 + -1;
      pcVar7 = pcVar7 + 1;
    } while (iVar6 != 0);
  }
  *(_MonsterAttackAttributes **)(puVar8 + 0x2e) = p_Var12;
  *(undefined *)((int)puVar8 + 0x15b) = 0;
  return p_Var12;
}

int MON_ShouldIFlee(_Instance *instance)

{
  short sVar1;
  int iVar2;
  u_int *puVar3;
  _MonsterIR *mir;
  int iVar4;

  puVar3 = (u_int *)instance->extraData;
  iVar4 = 0;
  if ((*puVar3 & 0x40000000) == 0)
  {
    mir = (_MonsterIR *)puVar3[0x31];
    sVar1 = MON_FacingOffset(instance, mir->instance);
    if ((u_short)(sVar1 + 0x2a9U) < 0x553)
    {
      iVar2 = MON_CheckConditions(instance, mir, (char *)(*(int *)(puVar3[0x59] + 8) + 0x1c));
      iVar4 = 0;
      if (iVar2 != 0)
      {
        iVar4 = 1;
        *(undefined2 *)(puVar3[0x31] + 0x18) = 0;
      }
    }
  }
  return iVar4;
}

int MON_ChooseLeftOrRight(_Instance *instance, _MonsterIR *enemy)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  sVar1 = MON_FacingOffset(instance, enemy->instance);
  iVar2 = -1;
  if (-0x41 < sVar1)
  {
    if (sVar1 < 0x41)
    {
      iVar3 = MONSENSE_GetClosestFreeDirection(instance, (short)(((u_int)(u_short)(instance->rotation).z + 0x400) * 0x10000 >> 0x10));
      iVar4 = MONSENSE_GetClosestFreeDirection(instance, (short)(((u_int)(u_short)(instance->rotation).z - 0x400) * 0x10000 >> 0x10));
      if (iVar3 == iVar4)
      {
        iVar2 = 0;
      }
      else
      {
        iVar2 = 1;
        if (iVar4 <= iVar3)
        {
          iVar2 = -1;
        }
      }
    }
    else
    {
      iVar2 = 1;
    }
  }
  return iVar2;
}

int MON_ChooseEvadeMove(_Instance *instance)

{
  int iVar1;
  u_int uVar2;
  int iVar3;

  iVar1 = MON_ChooseLeftOrRight(instance, *(_MonsterIR **)((int)instance->extraData + 0xc4));
  if (iVar1 == 0)
  {
    uVar2 = rand();
    iVar1 = -1;
    if ((uVar2 & 1) != 0)
    {
      iVar1 = 1;
    }
  }
  iVar3 = 0x29;
  if (iVar1 < 0)
  {
    iVar3 = 0x28;
  }
  return iVar3;
}

int MON_ChooseCombatMove(_Instance *instance, int reason)

{
  short angle;
  u_short uVar1;
  int Data;
  u_int xOffset;
  u_int yOffset;
  _MonsterIR *enemy;
  char cVar2;
  u_int uVar3;
  void *pvVar4;
  int *piVar5;

  pvVar4 = instance->extraData;
  enemy = *(_MonsterIR **)((int)pvVar4 + 0xc4);
  Data = *(int *)((int)pvVar4 + 0xcc);
  piVar5 = *(int **)((int)pvVar4 + 0x164);
  if ((Data == 0) || (699 < *(short *)(Data + 0x14)))
  {
    if (reason == 4)
    {
    LAB_80080568:
      cVar2 = '\a';
    }
    else
    {
      cVar2 = '\x06';
      if (reason != 5)
      {
        Data = (int)(enemy->relativePosition).y;
        if (Data < 0)
        {
          Data = -Data;
        }
        if (Data < *(short *)(piVar5[2] + 0x10))
        {
          if ((enemy->relativePosition).y < 0)
            goto LAB_80080568;
        }
        else
        {
          angle = MON_FacingOffset(instance, enemy->instance);
          if ((u_short)(angle + 0x2a9U) < 0x553)
          {
            Data = MON_ChooseLeftOrRight(instance, enemy);
            cVar2 = '\b';
            if ((-1 < Data) && (cVar2 = '\t', Data < 1))
            {
              uVar3 = rand();
              if ((uVar3 & 3) == 0)
              {
                cVar2 = '\b';
                uVar3 = rand();
                if ((uVar3 & 1) != 0)
                {
                  cVar2 = '\t';
                }
              }
              else
              {
                cVar2 = *(char *)((int)pvVar4 + 0x160);
              }
            }
          }
          else
          {
            cVar2 = '\0';
          }
          if (cVar2 == '\0')
          {
            return 0;
          }
        }
      }
    }
  }
  else
  {
    cVar2 = '\b';
    if (0 < *(short *)(Data + 0xc))
    {
      cVar2 = '\t';
    }
  }
  if (cVar2 == '\0')
  {
    return 0;
  }
  angle = (instance->rotation).z;
  if (cVar2 == '\b')
  {
    angle = angle + 0x400;
  }
  else
  {
    if (cVar2 < '\t')
    {
      if (cVar2 == '\a')
      {
        angle = angle + 0x800;
      }
    }
    else
    {
      if (cVar2 == '\t')
      {
        angle = angle + -0x400;
      }
    }
  }
  MONSENSE_AdjustRadarFromObjects(instance);
  angle = MONSENSE_GetDistanceInDirection(instance, angle, 0x2ee);
  uVar1 = (angle - (instance->rotation).z) + 0x200U & 0xfff;
  uVar3 = 6;
  if (((0x3ff < uVar1) && (uVar3 = 8, 0x7ff < uVar1)) && (uVar3 = 9, uVar1 < 0xc00))
  {
    uVar3 = 7;
  }
  Data = *(int *)((int)instance->data + 0x40) + (int)*(char *)(*piVar5 + uVar3) * 0x10;
  if (uVar3 == 8)
  {
    yOffset = 0;
    xOffset = (u_int) * (u_short *)(Data + 2);
  }
  else
  {
    if (uVar3 < 9)
    {
      xOffset = 0;
      if (uVar3 == 7)
      {
        yOffset = (u_int) * (u_short *)(Data + 2);
        goto LAB_80080758;
      }
    }
    else
    {
      yOffset = 0;
      if (uVar3 == 9)
      {
        xOffset = -(u_int) * (u_short *)(Data + 2);
        goto LAB_80080758;
      }
    }
    xOffset = 0;
    yOffset = -(u_int) * (u_short *)(Data + 2);
  }
LAB_80080758:
  Data = SetPhysics(xOffset, yOffset, 200, 0x800, 400);
  Data = PhysicsCheckBlockers(instance, Data, 4);
  if (Data == 0)
  {
    if (uVar3 - 8 < 2)
    {
      *(undefined *)((int)pvVar4 + 0x160) = (char)uVar3;
    }
  }
  else
  {
    uVar3 = 0;
  }
  return uVar3;
}

void MON_PlayRandomIdle(_Instance *instance, int mode)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  char *pcVar6;
  void *pvVar7;
  u_int *puVar8;

  puVar8 = (u_int *)instance->extraData;
  pvVar7 = instance->data;
  iVar2 = rand();
  pcVar6 = (char *)0x0;
  iVar2 = iVar2 % 100;
  if ((*puVar8 & 4) == 0)
  {
    iVar3 = -1;
    if (*(int *)(puVar8[0x59] + 0x10) != 0)
    {
      iVar3 = (int)*(char *)(*(int *)(puVar8[0x59] + 0x10) + (u_int) * (byte *)((int)puVar8 + 0x156));
    }
    if (iVar3 == -1)
    {
      puVar5 = *(undefined **)((int)pvVar7 + 0x48);
    }
    else
    {
      puVar5 = (undefined *)(*(int *)((int)pvVar7 + 0x48) + iVar3 * 8);
    }
    if (*(char *)((int)puVar8 + 0x156) != '\0')
    {
      iVar3 = (int)(char)puVar5[2];
      pcVar4 = puVar5 + 3;
      while ((iVar3 != 0 && (-1 < (int)*pcVar4)))
      {
        pcVar6 = (char *)(*(int *)((int)pvVar7 + 0x44) + (int)*pcVar4 * 4);
        iVar3 = iVar3 + -1;
        if (iVar2 < pcVar6[2])
          break;
        iVar2 = iVar2 - pcVar6[2];
        pcVar4 = pcVar4 + 1;
      }
      goto LAB_80080914;
    }
    cVar1 = puVar5[(u_int) * (byte *)(puVar8 + 0x57) + 3];
  }
  else
  {
    puVar5 = *(undefined **)((int)pvVar7 + 0x48);
    cVar1 = puVar5[3];
  }
  pcVar6 = (char *)(*(int *)((int)pvVar7 + 0x44) + (int)cVar1 * 4);
LAB_80080914:
  if (pcVar6 != (char *)0x0)
  {
    MON_PlayAnimIfNotPlaying(instance, (int)*pcVar6, mode);
    *(undefined *)((int)puVar8 + 0x15d) = *puVar5;
  }
  return;
}

void MON_PlayCombatIdle(struct _Instance *instance, int mode)
{

  int anim;
}

void MON_GetRandomGroundPoint(_Position *out, _Position *in, short r)

{
  int iVar1;
  u_int uVar2;
  int iVar3;

  iVar1 = rand();
  uVar2 = rand();
  iVar3 = rcos(uVar2);
  out->x = in->x + (short)((iVar1 % (int)r) * iVar3 >> 0xc);
  iVar3 = rsin(uVar2);
  out->y = in->y + (short)((iVar1 % (int)r) * iVar3 >> 0xc);
  out->z = in->z;
  return;
}

int MON_GetRandomPoint(_Instance *instance, _Position *out, _Position *in, short r0, int r1, int theta0,
                       int theta1, int h)

{
  _Instance *level;
  int iVar1;
  u_int uVar2;
  int iVar3;
  SVECTOR local_68;
  SVECTOR local_60;
  _PCollideInfo _Stack88;

  level = (_Instance *)STREAM_GetWaterZLevel(instance->currentStreamUnitID);
  iVar1 = rand();
  iVar1 = iVar1 * ((int)(short)r1 - (int)r0);
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0x7fff;
  }
  iVar3 = (int)r0 + (iVar1 >> 0xf);
  iVar1 = rand();
  iVar1 = iVar1 * ((int)(short)theta1 - (int)(short)theta0);
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0x7fff;
  }
  uVar2 = (int)(short)theta0 + (iVar1 >> 0xf);
  iVar1 = rcos(uVar2);
  local_68.vx = in->x + (short)(iVar3 * iVar1 >> 0xc);
  local_60.vx = local_68.vx;
  iVar1 = rsin(uVar2);
  local_68.vy = in->y + (short)(iVar3 * iVar1 >> 0xc);
  local_60.vz = (short)(((h << 0x10) >> 0x10) - ((h << 0x10) >> 0x1f) >> 1);
  local_68.vz = in->z + local_60.vz;
  _Stack88.collideType = 1;
  _Stack88.oldPoint = &local_68;
  _Stack88.newPoint = &local_60;
  _Stack88.instance = (_Instance *)0x0;
  _Stack88.inst = (_Instance *)0x0;
  local_60.vz = in->z - local_60.vz;
  local_60.vy = local_68.vy;
  COLLIDE_PointAndTerrain(&_Stack88, (Level *)level);
  iVar1 = 0;
  if ((((_Stack88.collideType & 1) != 0) && (iVar1 = 0, _Stack88.prim != (_TFace *)0x0)) &&
      (iVar1 = 0, level == _Stack88.inst))
  {
    if (instance != (_Instance *)0x0)
    {
      instance->oldTFace = instance->tface;
      *(_Instance **)&instance->tfaceLevel = level;
      instance->tface = _Stack88.prim;
      instance->bspTree = (int)_Stack88.segment;
    }
    out->x = local_60.vx;
    out->y = local_60.vy;
    out->z = local_60.vz;
    iVar1 = 1;
  }
  return iVar1;
}

int MON_GetRandomDestinationInWorld(_Instance *instance, _Position *in, short r)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  u_int *puVar5;
  u_char local_30;
  short local_2c;
  _Position local_28[2];

  if (instance->matrix == (MATRIX *)0x0)
  {
    return 0;
  }
  puVar5 = (u_int *)instance->extraData;
  bVar1 = false;
  if ((u_int) * (byte *)((int)puVar5 + 0x156) - 9 < 2)
  {
    bVar1 = puVar5[0x31] != 0;
  }
  if (in != (_Position *)0x0)
  {
    if (!bVar1)
      goto LAB_80080d20;
    iVar2 = *(int *)(puVar5[0x31] + 4);
    lVar3 = MATH3D_LengthXY((int)in->x - (int)*(short *)(iVar2 + 0x5c),
                            (int)in->y - (int)*(short *)(iVar2 + 0x5e),
                            (int)in->z - (int)*(short *)(iVar2 + 0x60));
    if (*(short *)(puVar5[0x59] + 0x1a) <= lVar3)
      goto LAB_80080d20;
  }
  in = &instance->position;
LAB_80080d20:
  local_28[0].x = *(short *)instance->matrix[1].t;
  local_28[0].y = *(short *)(instance->matrix[1].t + 1);
  local_28[0].z = *(short *)(instance->matrix[1].t + 2);
  MON_GetRandomGroundPoint((_Position *)&local_30, in, r);
  local_2c = local_2c + (local_28[0].z - (instance->position).z);
  iVar2 = MON_CheckPointSuitability(instance, local_28, (_Position *)&local_30);
  if (iVar2 != 0)
  {
    if (bVar1)
    {
      iVar4 = *(int *)(puVar5[0x31] + 4);
      lVar3 = MATH3D_LengthXY((int)(short)local_30 - (int)*(short *)(iVar4 + 0x5c),
                              (int)local_30._2_2_ - (int)*(short *)(iVar4 + 0x5e),
                              (int)local_2c - (int)*(short *)(iVar4 + 0x60));
      if (lVar3 < *(short *)(puVar5[0x59] + 0x1a))
      {
        iVar2 = 0;
      }
    }
    if (iVar2 != 0)
    {
      *puVar5 = *puVar5 | 0x40000;
      puVar5[0x48] = local_30;
      *(short *)(puVar5 + 0x49) = local_2c;
    }
  }
  return iVar2;
}

void MON_MoveForward(_Instance *instance)

{
  PhysicsSetVelFromRot(instance, &instance->rotation, (int)*(short *)((int)instance->extraData + 0x126));
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  PhysicsDefaultLinkedMoveResponse(instance, &instance->position, gameTrackerX.timeMult);
  return;
}

int MON_MoveToPosition(_Instance *instance, _Position *position, short turnspeed)

{
  short destination;

  destination = MATH3D_AngleFromPosToPos(&instance->position, position);
  AngleMoveToward(&(instance->rotation).z, destination,
                  (short)((int)turnspeed * gameTrackerX.timeMult * 0x10 >> 0x10));
  return (u_int)((instance->rotation).z == destination);
}

void MON_TurnToPosition(_Instance *instance, _Position *position, short turnSpeed)

{
  int iVar1;

  MON_MoveToPosition(instance, position, turnSpeed);
  iVar1 = MON_TransNodeAnimation(instance);
  if (iVar1 == 0)
  {
    MON_MoveForward(instance);
  }
  return;
}

int MON_OnGround(_Instance *instance)

{
  long lVar1;
  int iVar2;
  int iVar3;
  u_int *puVar4;
  short local_20;
  short local_1e;
  undefined2 local_16;

  puVar4 = (u_int *)instance->extraData;
  lVar1 = MATH3D_LengthXYZ((int)(instance->oldPos).x - (int)(instance->position).x,
                           (int)(instance->oldPos).y - (int)(instance->position).y);
  local_1e = (short)lVar1;
  iVar3 = (u_int)(u_short)(instance->oldPos).z - (u_int)(u_short)(instance->position).z;
  local_20 = (short)iVar3;
  iVar2 = 400;
  if ((*puVar4 & 2) != 0)
  {
    iVar2 = 100;
  }
  if (iVar3 * 0x10000 >> 0x10 < iVar2)
  {
    local_20 = (short)iVar2;
  }
  iVar2 = (int)local_20;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 3;
  }
  if ((int)local_1e<iVar2>> 2)
  {
    local_1e = (short)(iVar2 >> 2);
  }
  local_20 = local_20 + *(short *)(puVar4[0x59] + 0x4e);
  local_16 = 0xc80;
  local_1e = local_1e + *(short *)(puVar4[0x59] + 0x50);
  iVar2 = PhysicsCheckGravity(instance, (int)&local_20, (u_short)((*puVar4 & 0x800) == 0) << 2);
  return iVar2;
}

void MON_ApplyPhysics(_Instance *instance)

{
  PhysicsDefaultLinkedMoveResponse(instance, &instance->position, gameTrackerX.timeMult);
  return;
}

void MON_ChangeBehavior(_Instance *instance, int behavior)

{
  u_char unaff_s0;
  u_char unaff_s1;
  void *pvVar1;

  if (behavior != -1)
  {
    pvVar1 = instance->extraData;
    switch (behavior)
    {
    case 2:
      break;
    case 4:
    case 8:
      break;
    case 9:
    }
    MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
    *(undefined *)((int)pvVar1 + 0x156) = (char)behavior;
  }
  return;
}

void MON_CheckEnvironment(_Instance *instance)

{
  short sVar1;
  bool bVar2;
  int Data;
  u_int uVar3;
  u_int dropOffset;
  u_int *puVar4;
  _SVector local_28;
  _Position local_20;

  puVar4 = (u_int *)instance->extraData;
  local_28.z = 0;
  local_28.y = 0;
  local_28.x = 0;
  if ((*(u_int *)((int)instance->data + 0x10) & 4) == 0)
  {
    Data = SetPhysicsDropOffData(0, &local_28, 0x100, 0xa0, 0x40);
    uVar3 = PhysicsCheckSwim(instance, Data, 1);
    uVar3 = uVar3 & 0x20;
  }
  else
  {
    uVar3 = 0x20;
  }
  instance->tface = (_TFace *)0x0;
  instance->tfaceLevel = (void *)0x0;
  if (uVar3 == 0)
  {
    if ((*puVar4 & 0x400) == 0)
    {
      *puVar4 = *puVar4 & 0xffbfffff | 0x400;
      instance->maxXVel = 0x14;
      instance->maxYVel = 0x14;
      instance->maxZVel = 0x14;
      instance->xVel = 0;
      instance->yVel = 0;
      SOUND_Play3dSound(&instance->position, 1, -200, 0x78, (int)&DAT_00002710);
      instance->flags2 = instance->flags2 & 0xffffffbf;
    }
    if ((*(u_short *)((int)puVar4 + 0x14e) & 0x10) != 0)
    {
      INSTANCE_Query(instance, 0x100000c, 0x10);
    }
  }
  else
  {
    bVar2 = false;
    if ((*puVar4 & 0x400) != 0)
    {
      *puVar4 = *puVar4 & 0xfffffbff;
      instance->maxXVel = 400;
      instance->maxYVel = 400;
      instance->maxZVel = 400;
      if ((instance->object->oflags & 0x200U) != 0)
      {
        instance->flags2 = instance->flags2 | 0x40;
      }
    }
    if (instance->LinkParent == (_Instance *)0x0)
    {
      uVar3 = MON_OnGround(instance);
      if (uVar3 == 0)
      {
        uVar3 = *puVar4;
        if (((uVar3 & 2) != 0) && (*puVar4 = uVar3 & 0xfffffffd, (uVar3 & 0x800) == 0))
        {
          Data = 0x140;
          if ((uVar3 & 0x10000) == 0)
          {
            Data = (int)*(short *)(puVar4[0x59] + 0x16);
          }
          Data = SetPhysicsEdgeData(&instance->position, Data, 0x40);
          uVar3 = PhysicsCheckLOS(instance, Data, 1);
          if (((uVar3 & *(u_short *)((int)puVar4 + 0x14e)) != 0) || (uVar3 == 0))
          {
            bVar2 = true;
          }
        }
      }
      else
      {
        if ((*puVar4 & 2) == 0)
        {
          *puVar4 = *puVar4 | 2;
        }
        if ((*puVar4 & 0x1000) != 0)
        {
          dropOffset = (u_int) * (u_short *)puVar4[0x2f] * 8;
          local_20.y = *(u_short *)puVar4[0x2f] * -8;
          if (dropOffset < 100)
          {
            dropOffset = 100;
            local_20.y = -100;
          }
          local_20.x = 0;
 2);
 if ((*puVar4 & 0x10000) == 0)
 {
   dropOffset = SEXT24(*(short *)(puVar4[0x59] + 0x16));
 }
 Data = SetPhysicsEdgeData(&local_20, dropOffset, 0x60);
 dropOffset = PhysicsCheckLOS(instance, Data, 1);
 if (((dropOffset & *(u_short *)((int)puVar4 + 0x14e)) != 0) || (dropOffset == 0))
 {
   INSTANCE_Query(instance, 0x4010080, 0);
 }
        }
        if ((uVar3 & 0x100000) != 0)
        {
          bVar2 = true;
        }
      }
      if (bVar2)
      {
        Data = SetPhysicsEdgeData(&instance->oldPos, 100, 0x40);
        uVar3 = PhysicsCheckLOS(instance, Data, 1);
        if ((uVar3 != 0) && ((uVar3 & *(u_short *)((int)puVar4 + 0x14e)) == 0))
        {
          sVar1 = (instance->oldPos).z;
          *(u_char *)&instance->position = *(u_char *)&instance->oldPos;
          (instance->position).z = sVar1;
          *puVar4 = *puVar4 | 2;
        }
      }
      if (((*puVar4 & 0x802) == 0) && (puVar4[0x42] != 0x100000))
      {
        INSTANCE_Query(instance, 0x100000b, 0);
      }
    }
    if ((int *)instance->tfaceLevel != (int *)0x0)
    {
      MON_CheckTerrain(instance, (BSPTree *)(*(int *)(*(int *)instance->tfaceLevel + 0x48) + instance->bspTree * 0x24), instance->tface);
    }
  }
  return;
}

void MON_CheckTerrain(_Instance *instance, BSPTree *bsp, _TFace *tface)

{
  u_long uVar1;

  uVar1 = MON_CheckTerrainAndRespond(instance, bsp, tface);
  if ((uVar1 & 0x10) != 0)
  {
    INSTANCE_Query(instance, 0x100000c, 0x10);
  }
  if ((uVar1 & 0x20) != 0)
  {
    INSTANCE_Query(instance, 0x100000c, 0x20);
  }
  if ((uVar1 & 0x40) != 0)
  {
    INSTANCE_Query(instance, 0x100000c, 0x40);
  }
  return;
}

u_long MON_CheckTerrainAndRespond(_Instance *instance, BSPTree *bsp, _TFace *tface)

{
  Level *pLVar1;
  u_long uVar2;

  uVar2 = 0;
  if (tface != (_TFace *)0x0)
  {
    pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
    if (((bsp->flags & 8U) == 0) && (((pLVar1->unitFlags & 2U) != 0 || ((bsp->flags & 0x50U) != 0))))
    {
      uVar2 = 0x40;
    }
    if (((bsp->flags & 0x80U) != 0) || (instance->waterFace != (_TFace *)0x0))
    {
      uVar2 = uVar2 | 0x10;
    }
    if ((bsp->flags & 0x20U) != 0)
    {
      uVar2 = uVar2 | 0x20;
    }
  }
  return uVar2;
}

int MON_CheckPointSuitability(_Instance *instance, _Position *origin, _Position *destination)

{
  int Data;
  u_int uVar1;
  u_long uVar2;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  Data = SetPhysicsEdgeData(destination, (int)*(short *)(puVar3[0x59] + 0x16), 0x40);
  uVar1 = PhysicsCheckLOS(instance, Data, 1);
  if (uVar1 == 1)
  {
    uVar2 = MON_CheckTerrainAndRespond(instance, *(BSPTree **)(Data + 0xc), *(_TFace **)(Data + 0x10));
    uVar1 = uVar2 | 1;
    destination->z = *(short *)(Data + 4);
  }
  Data = 0;
  if (((uVar1 & *(u_short *)((int)puVar3 + 0x14e)) == 0) &&
      (((*puVar3 & 0x800) != 0 || (Data = 0, uVar1 != 0))))
  {
    Data = 1;
  }
  return Data;
}

u_long MON_GetAnim(_Instance *instance)

{
  if ((instance->object->oflags & 0x80000U) != 0)
  {
    return gameTrackerX.currentTime;
  }
  if ((instance->flags2 & 0x8000000U) == 0)
  {
    return gameTrackerX.currentMaterialTime;
  }
  return gameTrackerX.currentSpectralTime;
}

void MON_BirthMana(_Instance *instance, int link)

{
  _Instance *p_Var1;
  int introUniqueID;
  void *pvVar2;

  pvVar2 = instance->extraData;
  if (*(short *)((int)pvVar2 + 0x144) != 0)
  {
    introUniqueID = *(int *)((int)pvVar2 + 0xd8);
    if ((introUniqueID != 0) && (introUniqueID < 0x2000))
    {
      p_Var1 = INSTANCE_Deactivate(introUniqueID);
      if (p_Var1 == (_Instance *)0x0)
      {
        instance->flags2 = instance->flags2 | 0x80;
      }
      else
      {
        instance->flags2 = instance->flags2 & 0xffffff7f;
        *(long *)((int)pvVar2 + 0xd8) = p_Var1->introUniqueID;
        *(long *)((int)p_Var1->extraData + 0xd8) = instance->introUniqueID;
      }
    }
  }
  return;
}

void INSTANCE_ProcessIntro(_Instance *instance)

{
  undefined uVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  short *psVar5;
  int iVar6;
  u_int *puVar7;
  short *psVar8;
  int iVar9;
  u_int *puVar10;
  u_int uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;

  iVar12 = -1;
  iVar14 = -1;
  iVar15 = -1;
  iVar16 = 0;
  iVar17 = 0;
  iVar9 = 0;
  bVar4 = false;
  puVar10 = (u_int *)instance->extraData;
  uVar1 = *(undefined *)((int)instance->data + 0x16);
  *(undefined2 *)(puVar10 + 0x4f) = 0x800;
  *(undefined2 *)((int)puVar10 + 0x13e) = 0x400;
  iVar13 = -1;
  *(undefined *)((int)puVar10 + 0x15a) = uVar1;
  puVar10[1] = puVar10[1] | 0x80000000;
  psVar8 = (short *)instance->introData;
  uVar11 = 0;
  if ((psVar8 != (short *)0x0) && ((instance->flags & 2U) == 0))
  {
    sVar2 = *psVar8;
    sVar3 = *psVar8;
    while (sVar2 != 0)
    {
      if (sVar3 == 0xc)
      {
        *(undefined *)((int)puVar10 + 0x152) = *(undefined *)(psVar8 + 2);
      }
      else
      {
        if (sVar3 < 0xd)
        {
          if (sVar3 == 6)
          {
            *(undefined *)((int)puVar10 + 0x15a) = *(undefined *)(psVar8 + 2);
          }
          else
          {
            if (sVar3 < 7)
            {
              if (sVar3 == 3)
              {
                bVar4 = true;
              }
              else
              {
                if (sVar3 < 4)
                {
                  if (sVar3 == 1)
                  {
                    iVar12 = *(int *)(psVar8 + 2);
                  }
                  else
                  {
                    if (sVar3 == 2)
                    {
                      iVar14 = *(int *)(psVar8 + 2);
                    }
                  }
                }
                else
                {
                  if (sVar3 == 4)
                  {
                    iVar17 = *(int *)(psVar8 + 2);
                  }
                  else
                  {
                    if (sVar3 == 5)
                    {
                      iVar16 = *(int *)(psVar8 + 2);
                    }
                  }
                }
              }
            }
            else
            {
              if (sVar3 == 9)
              {
                instance->flags2 = instance->flags2 | 0x20000;
                uVar11 = uVar11 | 0x1000000;
                *(short *)((int)puVar10 + 0x146) = psVar8[2];
              }
              else
              {
                if (sVar3 < 10)
                {
                  if (sVar3 == 7)
                  {
                    uVar11 = uVar11 | 0x100000;
                  }
                  else
                  {
                    if (sVar3 == 8)
                    {
                      iVar13 = *(int *)(psVar8 + 2);
                    }
                  }
                }
                else
                {
                  if (sVar3 == 10)
                  {
                    iVar6 = (int)psVar8[1];
                    puVar7 = puVar10 + 0x61;
                    psVar5 = psVar8;
                    while (iVar6 != 0)
                    {
                      psVar5 = psVar5 + 2;
                      iVar6 = iVar6 + -1;
                      *(short *)puVar7 = *psVar5;
                      puVar7 = (u_int *)((int)puVar7 + 2);
                    }
                    *(short *)puVar7 = 0;
                    *(u_int **)(puVar10 + 0x67) = puVar10 + 0x61;
                  }
                  else
                  {
                    if (sVar3 == 0xb)
                    {
                      *(undefined *)(puVar10 + 0x57) = *(undefined *)(psVar8 + 2);
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          if (sVar3 == 0x14)
          {
            iVar15 = *(int *)(psVar8 + 2);
          }
          else
          {
            if (sVar3 < 0x15)
            {
              if (sVar3 == 0xf)
              {
                puVar10[0x36] = *(u_int *)(psVar8 + 2);
              }
              else
              {
                if (sVar3 < 0x10)
                {
                  if (sVar3 == 0xd)
                  {
                    *(short *)(puVar10 + 0x4d) = psVar8[2];
                  }
                  else
                  {
                    puVar7 = puVar10 + 0x5c;
                    if (sVar3 == 0xe)
                    {
                      iVar6 = 0;
                      psVar5 = psVar8;
                      if (0 < psVar8[1])
                      {
                        do
                        {
                          iVar6 = iVar6 + 1;
                          *(short *)puVar7 = psVar5[2];
                          puVar7 = (u_int *)((int)puVar7 + 2);
                          psVar5 = psVar5 + 2;
                        } while (iVar6 < psVar8[1]);
                      }
                      *(short *)puVar7 = 0;
                    }
                  }
                }
                else
                {
                  if (sVar3 == 0x10)
                  {
                    *(undefined *)(puVar10 + 0x55) = *(undefined *)(psVar8 + 2);
                    if (puVar10[0x36] == 0)
                    {
                      puVar10[0x36] = 0x7fffffff;
                    }
                  }
                  else
                  {
                    if (sVar3 == 0x11)
                    {
                      puVar10[1] = puVar10[1] & 0x7fffffff;
                    }
                  }
                }
              }
            }
            else
            {
              if (sVar3 == 0x18)
              {
                *(short *)((int)puVar10 + 0x13e) =
                    (short)((u_longlong)((longlong)(*(int *)(psVar8 + 2) * 0x1000) * 0xb60b60b7) >>
                            0x28) -
                    (short)(*(int *)(psVar8 + 2) * 0x1000 >> 0x1f);
              }
              else
              {
                if (sVar3 < 0x19)
                {
                  if (sVar3 == 0x16)
                  {
                    iVar9 = *(int *)(psVar8 + 2);
                  }
                  else
                  {
                    if (sVar3 == 0x17)
                    {
                      *(short *)(puVar10 + 0x4f) =
                          (short)((u_longlong)((longlong)(*(int *)(psVar8 + 2) * 0x1000) * 0xb60b60b7) >> 0x28) - (short)(*(int *)(psVar8 + 2) * 0x1000 >> 0x1f);
                    }
                  }
                }
                else
                {
                  if (sVar3 == 0x19)
                  {
                    *(undefined *)((int)puVar10 + 0x153) = *(undefined *)(psVar8 + 2);
                  }
                }
              }
            }
          }
        }
      }
      psVar8 = psVar8 + (int)psVar8[1] * 2 + 2;
      sVar2 = *psVar8;
      sVar3 = *psVar8;
    }
  }
  MON_DefaultQueueHandler(instance);
  *puVar10 = *puVar10 ^ uVar11;
  if (iVar12 != -1)
  {
    *(undefined *)((int)puVar10 + 0x157) = (char)iVar12;
    *(undefined *)((int)puVar10 + 0x156) = (char)iVar12;
  }
  if (iVar14 != -1)
  {
    *(char *)(puVar10 + 0x56) = (char)iVar14;
  }
  if (iVar15 != -1)
  {
    *(undefined *)((int)puVar10 + 0x159) = (char)iVar15;
  }
  if (iVar13 != -1)
  {
    *(short *)(puVar10 + 0x50) = (short)(iVar13 << 8);
  }
  if (bVar4)
  {
    uVar11 = instance->flags2;
    if ((uVar11 & 0x8000000) == 0)
    {
      uVar11 = uVar11 | 0x8000000;
    }
    else
    {
      uVar11 = uVar11 & 0xf7ffffff;
    }
    instance->flags2 = uVar11;
  }
  if (iVar16 != 0)
  {
    *(short *)(puVar10 + 0x4e) = (short)iVar16;
  }
  if (iVar17 != 0)
  {
    *(undefined2 *)((int)puVar10 + 0x136) = (short)iVar17;
  }
  if (iVar9 != 0)
  {
    *(undefined2 *)((int)puVar10 + 0x13a) = (short)iVar9;
  }
  if (((*(char *)(puVar10 + 0x56) == '\b') && (*(char *)((int)puVar10 + 0x157) != '\x04')) &&
      (*(char *)((int)puVar10 + 0x157) != '\x10'))
  {
    *(undefined *)((int)puVar10 + 0x157) = 4;
    *(undefined *)((int)puVar10 + 0x156) = 4;
  }
  return;
}

void MON_DefaultQueueHandler(_Instance *instance)

{
  short sVar1;
  undefined2 uVar2;
  u_int *puVar3;
  u_int uVar4;
  void *pvVar5;

  puVar3 = (u_int *)instance->extraData;
  pvVar5 = instance->data;
  if ((int)*(char *)((int)pvVar5 + 0x28) <= (int)(u_int) * (byte *)((int)puVar3 + 0x15a))
  {
    *(char *)((int)puVar3 + 0x15a) = *(char *)((int)pvVar5 + 0x28) + -1;
  }
  uVar4 = *(u_int *)((u_int) * (byte *)((int)puVar3 + 0x15a) * 4 + *(int *)((int)pvVar5 + 0x30));
  puVar3[0x59] = uVar4;
  instance->currentModel = (u_short) * (byte *)(uVar4 + 0x26);
  sVar1 = *(short *)(uVar4 + 0x14);
  (instance->scale).z = sVar1;
  (instance->scale).y = sVar1;
  (instance->scale).x = sVar1;
  *(undefined *)((int)puVar3 + 0x156) = *(undefined *)(uVar4 + 0x34);
  *(undefined *)((int)puVar3 + 0x157) = *(undefined *)(uVar4 + 0x34);
  *(undefined *)(puVar3 + 0x56) = *(undefined *)(uVar4 + 0x35);
  *(undefined2 *)((int)puVar3 + 0x136) = *(undefined2 *)(uVar4 + 0x30);
  *(undefined2 *)(puVar3 + 0x4e) = *(undefined2 *)(uVar4 + 0x32);
  uVar2 = *(undefined2 *)(uVar4 + 0x18);
  *(undefined2 *)(puVar3 + 0x51) = 0x1000;
  *(undefined *)((int)puVar3 + 0x15d) = 3;
  *(undefined *)(puVar3 + 0x58) = 8;
  *(undefined2 *)((int)puVar3 + 0x13a) = uVar2;
  if ((*(int *)(uVar4 + 8) != 0) &&
      (*(short *)(puVar3 + 0x50) = (short)((int)*(char *)(*(int *)(uVar4 + 8) + 0x18) << 8),
       *(char *)(*(int *)(uVar4 + 8) + 0x1a) != -1))
  {
    *puVar3 = *puVar3 | 0x20;
  }
  if ((*(char *)((int)puVar3 + 0x15a) == '\x02') && ((*(u_int *)((int)pvVar5 + 0x10) & 2) != 0))
  {
    *puVar3 = *puVar3 | 0x10000000;
  }
  if (*(char *)(uVar4 + 0x37) != '\0')
  {
    instance->flags2 = instance->flags2 | 0x8000000;
  }
  *(undefined2 *)((int)puVar3 + 0x14e) = 0x100;
  if (*(char *)(uVar4 + 0x3a) != '\0')
  {
    *(undefined2 *)((int)puVar3 + 0x14e) = 0x110;
  }
  if (*(char *)(uVar4 + 0x39) != '\0')
  {
    *(u_short *)((int)puVar3 + 0x14e) = *(u_short *)((int)puVar3 + 0x14e) | 0x20;
  }
  if (*(char *)(uVar4 + 0x38) != '\0')
  {
    *(u_short *)((int)puVar3 + 0x14e) = *(u_short *)((int)puVar3 + 0x14e) | 0x40;
  }
  if (*(char *)(uVar4 + 0x3c) != '\0')
  {
    *(u_short *)((int)puVar3 + 0x14e) = *(u_short *)((int)puVar3 + 0x14e) | 0x200;
  }
  if (*(char *)(uVar4 + 0x3b) != '\0')
  {
    *(u_short *)((int)puVar3 + 0x14e) = *(u_short *)((int)puVar3 + 0x14e) | 0x80;
  }
  return;
}

void MON_GetPlanSlot(_MonsterVars *mv)

{
  int iVar1;

  if ((int)mv->pathSlotID != -1)
  {
    ENMYPLAN_GetInitializedPlanningWorkspaceFinal((int)mv->pathSlotID);
  }
  iVar1 = ENMYPLAN_ReleasePlanningWorkspace();
  mv->pathSlotID = (char)iVar1;
  return;
}

int MON_DefaultPlanMovement(_Instance *instance, int anim, long distance)

{
  short turnSpeed;
  _MonsterAnim *p_Var1;
  long lVar2;
  int iVar3;
  u_int *puVar4;
  u_char local_30;
  u_char uVar5;
  undefined in_stack_ffffffd4[12];

  puVar4 = (u_int *)instance->extraData;
  p_Var1 = MON_GetTime(instance, *(char **)puVar4[0x59], anim);
  lVar2 = MATH3D_LengthXY((int)(instance->position).x - (int)*(short *)(puVar4 + 0x48),
                          (int)(instance->position).y - (int)*(short *)((int)puVar4 + 0x122),
                          (int)(instance->position).z - (int)*(short *)(puVar4 + 0x49));
  if (*(char *)((int)puVar4 + 0x162) == -1)
  {
    return 3;
  }
  if (((*puVar4 & 0x20000) == 0) &&
      (iVar3 = MON_AnimPlaying(instance, (MonsterAnim)CONCAT124(in_stack_ffffffd4, local_30)),
       iVar3 != 0))
  {
    *puVar4 = *puVar4 | 0x20000;
  }
  iVar3 = SOUL_QueueHandler(instance);
  if ((*puVar4 & 1) != 0)
  {
    return 6;
  }
  if (iVar3 != 0)
  {
    if ((*puVar4 & 0x20000) != 0)
    {
      return 3;
    }
    iVar3 = MON_MoveToPosition(instance, (_Position *)(puVar4 + 0x48), *(short *)(puVar4[0x59] + 0x1c));
    if (iVar3 == 0)
    {
      return 0;
    }
    return 3;
  }
  if (lVar2 < distance)
  {
    return 4;
  }
  uVar5 = 0x1f;
  iVar3 = ENMYPLAN_MoveToTargetFinal(instance, (_Position *)&stack0xffffffd8, (int)*(char *)((int)puVar4 + 0x162),
                                     (_Position *)(puVar4 + 0x48), 0x1f);
  if (iVar3 == 3)
  {
    return 2;
  }
  if (iVar3 == 0)
  {
    iVar3 = 1;
    MON_MoveToPosition(instance, (_Position *)(puVar4 + 0x48), *(short *)(puVar4[0x59] + 0x1c));
  }
  else
  {
    turnSpeed = ENMYPLAN_Replan((int)*(char *)((int)puVar4 + 0x162));
    iVar3 = MON_ValidUnit(instance, (int)turnSpeed);
    if (iVar3 == 0)
    {
      iVar3 = 2;
    }
    else
    {
      if ((*puVar4 & 0x20000) == 0)
      {
        *puVar4 = *puVar4 | 0x20000;
      }
      else
      {
        iVar3 = 0;
        if ((instance->flags2 & 2U) == 0)
          goto LAB_800821e4;
      }
      MON_PlayAnimFromList(instance, (MonsterAnim)CONCAT124(in_stack_ffffffd4, uVar5), anim);
      iVar3 = 0;
    }
  }
LAB_800821e4:
  if ((*puVar4 & 0x20000) != 0)
  {
    if (anim == 2)
    {
      turnSpeed = *(short *)(puVar4[0x59] + 0x1e);
    }
    else
    {
      if (anim == 3)
      {
        turnSpeed = *(short *)(puVar4[0x59] + 0x20);
      }
      else
      {
        turnSpeed = *(short *)(puVar4[0x59] + 0x1c);
      }
    }
 (int)turnSpeed)
 {
   turnSpeed = (short)((int)turnSpeed << 1);
 }
 MON_TurnToPosition(instance, (_Position *)&stack0xffffffd8, turnSpeed);
  }
  return iVar3;
}

void MON_DropAllObjects(_Instance *instance)

{
  _Instance *Inst;
  int Data;
  _Instance *p_Var1;

  Inst = instance->LinkChild;
  while (Inst != (_Instance *)0x0)
  {
    p_Var1 = Inst->LinkSibling;
    if (Inst->ParentLinkNode == 3)
    {
      Data = 2;
    }
    else
    {
      Data = 1;
    }
    INSTANCE_Query(Inst, 0x800008, Data);
    Inst = p_Var1;
  }
  return;
}

void MON_DisableHeadMove(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  void *pvVar2;
  _G2Anim_Type *anim;

  pvVar2 = instance->data;
  anim = &instance->anim;
  if ((*(byte *)((int)pvVar2 + 0x1a) != 0) &&
      (_Var1 = G2Anim_DetachControllerFromSeg(anim, (u_int) * (byte *)((int)pvVar2 + 0x1a), 0xe),
       _Var1 == G2FALSE))
  {
    _G2Anim_ApplyControllersToStoredFrame(anim, (u_int) * (byte *)((int)pvVar2 + 0x1a), 0xe, 1);
    G2Anim_DisableController(anim, (u_int) * (byte *)((int)pvVar2 + 0x1a), 0xe);
    if ((u_int) * (byte *)((int)pvVar2 + 0x22) != (u_int) * (byte *)((int)pvVar2 + 0x1a))
    {
      _G2Anim_ApplyControllersToStoredFrame(anim, (u_int) * (byte *)((int)pvVar2 + 0x22), 0xe, 1);
      G2Anim_DisableController(anim, (u_int) * (byte *)((int)pvVar2 + 0x22), 0xe);
    }
  }
  return;
}

void MON_EnableHeadMove(_Instance *instance)

{
  byte bVar1;
  _G2Bool_Enum _Var2;
  void *pvVar3;
  _G2Anim_Type *anim;

  pvVar3 = instance->data;
  anim = &instance->anim;
  if ((*(byte *)((int)pvVar3 + 0x1a) != 0) &&
      (_Var2 = G2Anim_DetachControllerFromSeg(anim, (u_int) * (byte *)((int)pvVar3 + 0x1a), 0xe),
       _Var2 != G2FALSE))
  {
    _G2Anim_FindController(anim, (u_int) * (byte *)((int)pvVar3 + 0x1a), 0xe);
    bVar1 = *(byte *)((int)pvVar3 + 0x22);
    if ((bVar1 != 0) && ((u_int)bVar1 != (u_int) * (byte *)((int)pvVar3 + 0x1a)))
    {
      _G2Anim_FindController(anim, (u_int)bVar1, 0xe);
    }
  }
  return;
}

void MON_LookInDirection(_Instance *instance, short tx, short tz)

{
  byte bVar1;
  void *pvVar2;
  _G2SVector3_Type local_20;

  pvVar2 = instance->data;
  if (*(char *)((int)pvVar2 + 0x1a) != '\0')
  {
    if (*(char *)((int)pvVar2 + 0x22) == *(char *)((int)pvVar2 + 0x1a))
    {
      bVar1 = *(byte *)((int)pvVar2 + 0x1a);
      local_20.x = tx;
      local_20.z = tz;
    }
    else
    {
      local_20.y = 0;
 100);
 100);
 G2Anim_GetControllerCurrentInterpVector(&instance->anim, (u_int) * (byte *)((int)pvVar2 + 0x1a), 0xe, &local_20);
 if (*(char *)((int)pvVar2 + 0x22) == '\0')
 {
   return;
 }
 100);
 100);
 bVar1 = *(byte *)((int)pvVar2 + 0x22);
    }
    local_20.y = 0;
    G2Anim_GetControllerCurrentInterpVector(&instance->anim, (u_int)bVar1, 0xe, &local_20);
  }
  return;
}

void MON_LookAtPos(_Instance *instance, _Position *position)

{
  bool bVar1;
  short destination;
  short sVar2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  destination = MATH3D_AngleFromPosToPos(&instance->position, position);
  destination = CAMERA_AngleDifference((instance->rotation).z, destination);
  if (destination < 0x31d)
  {
    if (destination < -0x31c)
    {
      destination = -0x31c;
    }
  }
  else
  {
    destination = 0x31c;
  }
  sVar2 = *(short *)((int)pvVar3 + 0x14c) + -0x111;
  if (destination < *(short *)((int)pvVar3 + 0x14c))
  {
    *(short *)((int)pvVar3 + 0x14c) = sVar2;
    bVar1 = sVar2 < destination;
  }
  else
  {
    sVar2 = *(short *)((int)pvVar3 + 0x14c) + 0x111;
    if (destination <= *(short *)((int)pvVar3 + 0x14c))
      goto LAB_800826b8;
    *(short *)((int)pvVar3 + 0x14c) = sVar2;
    bVar1 = destination < sVar2;
  }
  if (bVar1)
  {
    *(short *)((int)pvVar3 + 0x14c) = destination;
  }
LAB_800826b8:
  *(undefined2 *)((int)pvVar3 + 0x14a) = 0;
  MON_LookInDirection(instance, 0, *(short *)((int)pvVar3 + 0x14c));
  return;
}

void MON_ProcessLookAt(_Instance *instance)

{
  int *piVar1;

  piVar1 = (int *)instance->extraData;
  if (piVar1[0x42] != 0x80000)
  {
    if (*piVar1 < 0)
    {
      MON_DisableHeadMove(instance);
      MON_LookAtPos(instance, (_Position *)((int)piVar1 + 0x12e));
    }
    else
    {
      if (piVar1[0x47] == 0)
      {
        if ((*(short *)((int)piVar1 + 0x14a) == 0) && (*(short *)(piVar1 + 0x53) == 0))
        {
          MON_EnableHeadMove(instance);
        }
        else
        {
          AngleMoveToward((short *)((int)piVar1 + 0x14a), 0, 100);
          AngleMoveToward((short *)(piVar1 + 0x53), 0, 100);
          MON_LookInDirection(instance, *(short *)((int)piVar1 + 0x14a), *(short *)(piVar1 + 0x53));
        }
      }
      else
      {
        MON_DisableHeadMove(instance);
        MON_LookAtPos(instance, (_Position *)piVar1[0x47]);
        piVar1[0x47] = 0;
      }
    }
  }
  return;
}

int MON_TakeDamage(_Instance *instance, int damage, int type)

{
  int iVar1;
  int iVar2;
  u_long uVar3;
  void *pvVar4;

  pvVar4 = instance->extraData;
  iVar1 = *(int *)(*(int *)((int)pvVar4 + 0x164) + 8);
  if (iVar1 == 0)
  {
    iVar2 = 0;
  }
  else
  {
    iVar2 = 0;
    if (*(char *)(iVar1 + 0x18) != '\0')
    {
      uVar3 = INSTANCE_Post(instance, 1);
      if ((type != 0x40000) || (iVar2 = 0, (uVar3 & 8) != 0))
      {
        damage = (u_int) * (u_short *)((int)pvVar4 + 0x140) - damage;
        *(undefined2 *)((int)pvVar4 + 0x140) = (short)damage;
        iVar2 = 0;
        if (damage * 0x10000 < 1)
        {
          *(undefined2 *)((int)pvVar4 + 0x140) = 0;
          iVar2 = 1;
        }
      }
    }
  }
  return iVar2;
}

void MON_SetUpSaveInfo(_Instance *instance, _MonsterSaveInfo *saveData)

{
  u_int uVar1;
  u_int uVar2;
  u_int uVar3;
  u_int uVar4;
  u_int *puVar5;
  void *pvVar6;

  puVar5 = (u_int *)instance->extraData;
  pvVar6 = instance->data;
  saveData->mvFlags = *puVar5 & 0xffbbfffb;
  saveData->auxFlags = puVar5[1] & 0xf7ffffff;
  uVar1 = saveData->age;
  uVar2 = (u_int) * (byte *)((int)puVar5 + 0x15a) & 7;
  saveData->age = uVar1 & 0xfffffff8 | uVar2;
  uVar3 = (instance->currentMainState & 0x3fU) << 3;
  saveData->age = uVar1 & 0xfffffe00 | uVar2 | uVar3;
  uVar4 = ((u_int) * (byte *)((int)puVar5 + 0x156) & 0x1f) << 9;
  saveData->age = uVar1 & 0xffffc000 | uVar2 | uVar3 | uVar4;
  saveData->age =
      uVar1 & 0xff8fc000 | uVar2 | uVar3 | uVar4 | ((u_int) * (byte *)(puVar5 + 0x55) & 7) << 0x14;
  if ((instance->currentMainState == 0x17) && (*(char *)(puVar5 + 0x55) == '\0'))
  {
    saveData->soulJuice = *(short *)(puVar5 + 0x35);
  }
  else
  {
    saveData->soulJuice = *(short *)(puVar5 + 0x51);
  }
  saveData->soulID = *(short *)(puVar5 + 0x36);
  if (puVar5[0x2f] == 0)
  {
    uVar2 = saveData->age;
    uVar1 = SEXT14(*(char *)((int)pvVar6 + 0x2c));
  }
  else
  {
    uVar2 = saveData->age;
    uVar1 = (int)(puVar5[0x2f] - *(int *)((int)pvVar6 + 0x40)) >> 4;
  }
  saveData->age = uVar2 & 0xfff03fff | (uVar1 & 0x3f) << 0xe;
  return;
}

void MON_GetSaveInfo(_Instance *instance, _MonsterSaveInfo *saveData)

{
  short sVar1;
  u_int index;
  u_char local_18;
  u_int *puVar2;
  u_char local_14;
  u_char local_10;
  u_char local_c;
  void *pvVar3;

  puVar2 = (u_int *)instance->extraData;
  pvVar3 = instance->data;
  if ((saveData->mvFlags & 0x8000U) == 0)
  {
    MON_TurnOnBodySpheres(instance);
  }
  else
  {
    MON_TurnOnWeaponSphere(instance);
  }
  *puVar2 = saveData->mvFlags | *puVar2 & 0xc000;
  puVar2[1] = saveData->auxFlags | puVar2[1] & 0x8000000;
  *(byte *)((int)puVar2 + 0x15a) = (byte)saveData->age & 7;
  *(byte *)((int)puVar2 + 0x156) = (byte)(saveData->age >> 9) & 0x1f;
  *(byte *)(puVar2 + 0x55) = (byte)(saveData->age >> 0x14) & 7;
  puVar2[0x36] = (int)saveData->soulID;
  *(short *)(puVar2 + 0x51) = saveData->soulJuice;
  switch (saveData->age >> 3 & 0x3f)
  {
  case 6:
  case 8:
  case 9:
  case 0x15:
  case 0x1c:
    index = 0xd;
    break;
  default:
    index = saveData->age >> 3 & 0x3f;
    break;
  case 0x10:
  case 0x17:
    if (*(char *)(puVar2 + 0x55) == '\0')
    {
      sVar1 = *(short *)(puVar2 + 0x51);
      *(undefined2 *)(puVar2 + 0x51) = 0x1000;
      puVar2[0x35] = (int)sVar1;
      instance->flags2 = instance->flags2 | 0x80;
    }
    index = 0x17;
  }
  instance->currentMainState = index;
  index = saveData->age >> 0xe & 0x3f;
  if ((int)index < (int)*(char *)((int)pvVar3 + 0x2c))
  {
    if (instance->currentMainState == 0x17)
    {
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14, local_18))), 0x18);
    }
    else
    {
      MON_PlayAnimID(instance, index, 1);
    }
  }
  return;
}

void MON_KillMonster(_Instance *instance)

{
  u_int *puVar1;

  puVar1 = (u_int *)instance->extraData;
  MON_DropAllObjects(instance);
  if ((*(char *)(puVar1 + 0x55) == '\x04') || (*(char *)(puVar1 + 0x55) == '\x06'))
  {
    _FX_BuildNonSegmentedSplinters(instance, (SVECTOR *)0x0, (SVECTOR *)0x0, (SVECTOR *)0x0,
                                   *(FXSplinter **)((int)instance->data + 0x4c), gFXT,
                                   (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                                   (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0, 8);
  }
  if (((*puVar1 & 0x1000000) == 0) ||
      ((instance->intro != (Intro *)0x0 && ((instance->intro->flags & 0x400U) != 0))))
  {
    SAVE_MarkDeadDead(instance);
  }
  else
  {
    if (*(short *)((int)puVar1 + 0x146) != 0)
    {
      MONAPI_AddToGenerator(instance);
    }
    SAVE_Instance(instance);
  }
  instance->flags = instance->flags | 0x20;
  return;
}

int MON_ShouldIAmbushEnemy(_Instance *instance)

{
  _StreamUnit *streamUnit;
  int iVar1;
  long lVar2;
  u_int uVar3;
  void *pvVar4;
  _Instance *p_Var5;
  int iVar6;
  _Position local_20;

  pvVar4 = instance->extraData;
  iVar6 = *(int *)((int)pvVar4 + 0xc4);
  if (((instance->currentStreamUnitID == instance->birthStreamUnitID) &&
       (*(char *)((int)pvVar4 + 0x152) != '\0')) &&
      (*(int *)((int)pvVar4 + 0x13c) == 0x4000800))
  {
    p_Var5 = gameTrackerX.playerInstance;
    if (iVar6 != 0)
    {
      p_Var5 = *(_Instance **)(iVar6 + 4);
    }
    streamUnit = STREAM_GetStreamUnitWithID(instance->birthStreamUnitID);
    iVar1 = PLANAPI_FindClosestNodePositionInUnit(streamUnit, &local_20, (int)*(char *)((int)pvVar4 + 0x152), 4);
    if ((iVar1 != 0) &&
        (lVar2 = MATH3D_LengthXY((int)(p_Var5->position).x - (int)local_20.x,
                                 (int)(p_Var5->position).y - (int)local_20.y,
                                 (int)(p_Var5->position).z - (int)local_20.z),
         lVar2 < *(short *)((int)pvVar4 + 0x13a)))
    {
      return 1;
    }
  }
  if (iVar6 == 0)
  {
    uVar3 = 0;
  }
  else
  {
    if ((instance->currentMainState != 0x1a) || (uVar3 = 0, (*(u_short *)(iVar6 + 0x16) & 0x40) != 0))
    {
      if (*(int *)((int)pvVar4 + 0x13c) == 0x4000800)
      {
        uVar3 = (u_int)(*(short *)(iVar6 + 0x14) < *(short *)((int)pvVar4 + 0x13a));
      }
      else
      {
        uVar3 = 0;
        if (*(short *)(iVar6 + 0x14) < *(short *)((int)pvVar4 + 0x13a))
        {
          uVar3 = MATH3D_ConeDetect((_SVector *)(iVar6 + 0xc), (int)*(short *)((int)pvVar4 + 0x13c),
                                    (int)*(short *)((int)pvVar4 + 0x13e));
        }
      }
    }
  }
  return uVar3;
}

int MON_ShouldIAttack(_Instance *instance, _MonsterIR *target)

{
  int *piVar1;
  int iVar2;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  if (((((*puVar3 & 0x20) != 0) && ((target->mirFlags & 0x20) != 0)) &&
       (iVar2 = *(int *)((int)instance->data + 0x3c) +
                (int)*(char *)(*(int *)(puVar3[0x59] + 8) + 0x1a) * 0x10,
        *(char *)((int)puVar3 + 0x161) < *(char *)(iVar2 + 0xc))) &&
      ((int)target->distance < (int)(u_int) * (u_short *)(iVar2 + 2)))
  {
    piVar1 = (int *)puVar3[0x24];
    while (true)
    {
      if (piVar1 == (int *)0x0)
      {
        return 2;
      }
      if ((((int)*(short *)(piVar1 + 5) < (int)target->distance) &&
           (0 < *(short *)((int)piVar1 + 0xe))) &&
          (*(short *)(piVar1 + 3) < 200))
        break;
      piVar1 = (int *)*piVar1;
    }
    return 0;
  }
  return 0;
}

int MON_ShouldIEvade(_Instance *instance)

{
  int iVar1;
  u_int uVar2;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  uVar2 = puVar3[0x31];
  if (uVar2 == 0)
  {
    return 0;
  }
  if ((*(u_short *)(uVar2 + 0x16) & 8) != 0)
  {
    return 0;
  }
  if (*(short *)(puVar3[0x59] + 0x1a) <= *(short *)(uVar2 + 0x14))
  {
    return 0;
  }
  iVar1 = MON_ValidPosition(instance);
  if (iVar1 != 0)
  {
    if ((*(char *)((int)puVar3 + 0x156) == '\t') ||
        (((*puVar3 & 0x2000000) != 0 &&
          ((puVar3[0x33] == 0 || ((*(u_short *)(puVar3[0x33] + 0x16) & 0x200) == 0))))))
    {
      return 1;
    }
    if ((*puVar3 & 0x2000) == 0)
    {
      return 0;
    }
    if (*(short *)(puVar3 + 0x50) == 0)
    {
      return 1;
    }
  }
  return 0;
}

void MON_RelocateCoords(_Instance *instance, _SVector *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  void *pvVar4;

  pvVar4 = instance->extraData;
  sVar1 = offset->x;
  sVar2 = offset->y;
  sVar3 = offset->z;
  *(short *)((int)pvVar4 + 0x120) = *(short *)((int)pvVar4 + 0x120) + sVar1;
  *(short *)((int)pvVar4 + 0x122) = *(short *)((int)pvVar4 + 0x122) + sVar2;
  *(short *)((int)pvVar4 + 0x124) = *(short *)((int)pvVar4 + 0x124) + sVar3;
  *(short *)((int)pvVar4 + 0x128) = *(short *)((int)pvVar4 + 0x128) + sVar1;
  *(short *)((int)pvVar4 + 0x12a) = *(short *)((int)pvVar4 + 0x12a) + sVar2;
  *(short *)((int)pvVar4 + 300) = *(short *)((int)pvVar4 + 300) + sVar3;
  return;
}

int MON_ValidUnit(_Instance *instance, u_long unitId)

{
  u_short uVar1;
  u_short *puVar2;

  puVar2 = (u_short *)((int)instance->extraData + 0x170);
  if (*(short *)((int)instance->extraData + 0x170) != 0)
  {
    while (uVar1 = *puVar2, puVar2 = puVar2 + 1, (unitId & 0xffff) != (u_int)uVar1)
    {
      if (*puVar2 == 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

int MON_ValidPosition(_Instance *instance)

{
  short sVar1;
  int iVar2;
  void *pvVar3;

  iVar2 = MON_ValidUnit(instance, instance->currentStreamUnitID);
  if (iVar2 != 0)
  {
    pvVar3 = instance->extraData;
    sVar1 = (instance->position).z;
    *(u_char *)((int)pvVar3 + 0x128) = *(u_char *)&instance->position;
    *(short *)((int)pvVar3 + 300) = sVar1;
  }
  return (u_int)(iVar2 != 0);
}

void MON_SphereWorldPos(MATRIX *mat, _HSphere *sphere, _Position *ret)

{
  ApplyMatrix(mat, &sphere->position);
  ret->x = ret->x + *(short *)mat->t;
  ret->y = ret->y + *(short *)(mat->t + 1);
  ret->z = ret->z + *(short *)(mat->t + 2);
  return;
}

_HPrim *MON_FindSphereForTerrain(_Instance *instance)

{
  u_short uVar1;
  _HModel *p_Var2;
  _HPrim *p_Var3;
  int iVar4;
  u_short uVar5;
  _HPrim *p_Var6;

  p_Var6 = (_HPrim *)0x0;
  uVar5 = 0;
  if (instance->hModelList != (_HModel *)0x0)
  {
    p_Var2 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var2->numHPrims;
    p_Var3 = p_Var2->hPrimList;
    while (iVar4 != 0)
    {
      if (((undefined **)(*(u_int *)p_Var3 & 0xff0200) == &PTR_00010200) &&
          (uVar1 = *(u_short *)(p_Var3->data + 0xe), uVar5 < uVar1))
      {
        p_Var6 = p_Var3;
        uVar5 = uVar1;
      }
      iVar4 = iVar4 + -1;
      p_Var3 = p_Var3 + 1;
    }
  }
  return p_Var6;
}

Intro *MON_FindNearestImpalingIntro(int unitID, _Position *position)

{
  Intro *pIVar1;
  int iVar2;
  Level *pLVar3;
  int iVar4;
  long lVar5;
  Intro *pIVar6;
  int iVar7;
  Intro *pIVar8;

  pLVar3 = STREAM_GetWaterZLevel(unitID);
  pIVar8 = (Intro *)0x0;
  if ((pLVar3 != (Level *)0x0) && (0 < pLVar3->numIntros))
  {
    pIVar1 = pLVar3->introList;
    iVar2 = pLVar3->numIntros;
    do
    {
      iVar7 = iVar2;
      pIVar6 = pIVar1;
      if ((pIVar6->flags & 0x8000U) != 0)
      {
        iVar4 = MATH3D_LengthXY((int)(pIVar6->position).x - (int)position->x,
                                (int)(pIVar6->position).y - (int)position->y,
                                (int)(pIVar6->position).z - (int)position->z);
        pIVar8 = pIVar6;
        break;
      }
      pIVar1 = pIVar6 + 1;
      iVar2 = iVar7 + -1;
      iVar4 = 0x7fffffff;
    } while (0 < iVar7 + -1);
    while (pIVar1 = pIVar6, iVar7 = iVar7 + -1, 0 < iVar7)
    {
      pIVar6 = pIVar1 + 1;
      if (((pIVar1[1].flags & 0x8000U) != 0) &&
          (lVar5 = MATH3D_LengthXY((int)pIVar1[1].position.x - (int)position->x,
                                   (int)pIVar1[1].position.y - (int)position->y,
                                   (int)pIVar1[1].position.z - (int)position->z),
           lVar5 < iVar4))
      {
        pIVar8 = pIVar6;
        iVar4 = lVar5;
      }
    }
  }
  return pIVar8;
}

Intro *MON_TestForTerrainImpale(_Instance *instance, _Terrain *terrain)

{
  u_short uVar1;
  _HPrim *p_Var2;
  long lVar3;
  short *psVar4;
  Intro *pIVar5;
  int iVar6;
  _Position local_20;

  if (*(int *)((int)instance->extraData + 0x108) == 0x100000)
  {
    p_Var2 = MON_FindSphereForTerrain(instance);
    if (p_Var2 != (_HPrim *)0x0)
    {
      uVar1 = ((_HSphere *)p_Var2->data)->radius;
      MON_SphereWorldPos(instance->matrix + p_Var2->segment, (_HSphere *)p_Var2->data, &local_20);
      iVar6 = terrain->numIntros;
      pIVar5 = terrain->introList;
      psVar4 = &(pIVar5->position).z;
      while (iVar6 != 0)
      {
        if (((*(u_int *)(psVar4 + 4) & 0x8000) != 0) &&
            (lVar3 = MATH3D_LengthXY((int)local_20.x - (int)psVar4[-2],
                                     (int)local_20.y - (int)psVar4[-1], (int)local_20.z - (int)*psVar4),
             lVar3 < (int)((u_int)uVar1 * 3)))
        {
          return pIVar5;
        }
        iVar6 = iVar6 + -1;
        psVar4 = psVar4 + 0x26;
        pIVar5 = pIVar5 + 1;
      }
    }
  }
  return (Intro *)0x0;
}

void MON_MoveInstanceToImpalePoint(_Instance *instance)

{
  short sVar1;
  short sVar2;
  Intro *pIVar3;
  SVECTOR local_10;

  if ((instance->matrix != (MATRIX *)0x0) &&
      (pIVar3 = INSTANCE_FindIntro(instance->currentStreamUnitID,
                                   *(long *)((int)instance->extraData + 0x1a0)),
       pIVar3 != (Intro *)0x0))
  {
    local_10.vx = (pIVar3->position).x - *(short *)instance->matrix[3].t;
    local_10.vy = (pIVar3->position).y - *(short *)(instance->matrix[3].t + 1);
    local_10.vz = (pIVar3->position).z - *(short *)(instance->matrix[3].t + 2);
    (instance->position).x = (instance->position).x + local_10.vx;
    (instance->position).y = (instance->position).y + local_10.vy;
    (instance->position).z = (instance->position).z + local_10.vz;
    sVar1 = (pIVar3->rotation).y;
    sVar2 = (pIVar3->rotation).z;
    (instance->rotation).x = (pIVar3->rotation).x;
    (instance->rotation).y = sVar1;
    (instance->rotation).z = sVar2;
    COLLIDE_MoveAllTransforms(instance, &local_10);
  }
  return;
}

int MON_ReachableIntro(_Instance *instance, _Position *pos, _Position *introPos, _Rotation *introRot,
                       int checkOrientation)

{
  bool bVar1;
  short angle;
  int square;
  int iVar2;
  int iVar3;
  int square_00;
  u_int uVar4;
  long lVar5;
  u_int uVar6;
  long lVar7;
  void *pvVar8;
  short sVar9;

  square = (int)pos->x - (int)introPos->x;
  iVar2 = (int)pos->y - (int)introPos->y;
  iVar3 = (int)pos->z - (int)introPos->z;
  pvVar8 = instance->extraData;
  square_00 = (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x44);
  angle = 0;
  sVar9 = 0;
  lVar7 = 0;
  square = square * square + iVar2 * iVar2 + iVar3 * iVar3;
  bVar1 = false;
  if ((square < square_00 * square_00) &&
      (iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x42), iVar2 * iVar2 < square))
  {
    angle = MATH3D_AngleFromPosToPos(pos, introPos);
    if (checkOrientation != 0)
    {
      uVar6 = ((int)(instance->rotation).z + 0x800U & 0xfff) - (int)angle & 0xfff;
      iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x46);
      if (uVar6 < 0x801)
      {
        if ((int)uVar6 < iVar2)
        {
          checkOrientation = 0;
        }
      }
      else
      {
        iVar3 = uVar6 - 0x1000;
        if (iVar3 < 0)
        {
          iVar3 = -iVar3;
        }
        if (iVar3 < iVar2)
        {
          checkOrientation = 0;
        }
      }
      if (checkOrientation != 0)
        goto LAB_80083764;
    }
    if (introRot != (_Rotation *)0x0)
    {
      uVar6 = (int)introRot->x + 0x400U & 0xfff;
      uVar4 = uVar6 - 0x1000;
      if ((0x800 < uVar6) && (uVar6 = uVar4, (int)uVar4 < 0))
      {
        uVar6 = -uVar4;
      }
      if (0x7f < (int)uVar6)
      {
        uVar6 = (int)angle + 0x800U & 0xfff;
        sVar9 = (short)uVar6;
        uVar6 = (int)introRot->z - uVar6 & 0xfff;
        if ((0x800 < uVar6) && (uVar6 = uVar6 - 0x1000, (int)uVar6 < 0))
        {
          uVar6 = -uVar6;
        }
        if ((int)uVar6 < (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x46))
        {
          uVar6 = (u_int)(u_short)introRot->x & 0xfff;
          if (0x800 < uVar6)
          {
            uVar6 = uVar6 - 0x1000;
          }
          bVar1 = true;
          if ((int)uVar6 < 1)
          {
            iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x4a);
            lVar7 = iVar2 - (int)((iVar2 - *(short *)(*(int *)((int)pvVar8 + 0x164) + 0x48)) *
 0x380;
          }
          else
          {
            lVar7 = (long)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x4a);
          }
        }
        goto LAB_80083764;
      }
    }
    bVar1 = true;
    lVar7 = (long)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x48);
  }
LAB_80083764:
  if (bVar1)
  {
    iVar2 = (int)introPos->z - (int)pos->z;
    iVar3 = instance->zAccl;
    if (iVar2 != 0)
    {
      (iVar2 * 2);
      if (square_00 < 0)
      {
        square_00 = -square_00;
      }
      if (square_00 < lVar7 * lVar7)
      {
        lVar7 = MATH3D_FastSqrt0(square_00);
      }
    }
    lVar5 = MATH3D_FastSqrt0(square);
    (lVar7 << 1);
    square = iVar2;
    if (iVar2 < 0)
    {
      square = -iVar2;
    }
    if (square < *(short *)(*(int *)((int)pvVar8 + 0x164) + 0x4c))
    {
      (instance->rotation).z = sVar9;
      PhysicsSetVelFromZRot(instance, angle, lVar7 + 1);
      instance->zVel = iVar2;
      return 1;
    }
  }
  return 0;
}

int MON_SetVelocityTowardsImpalingObject(_Instance *instance, int checkOrientation)

{
  Level *pLVar1;
  _HPrim *p_Var2;
  int iVar3;
  u_long uVar4;
  _Rotation *introRot;
  _Instance *Inst;
  Intro *pIVar5;
  int iVar6;
  _Position _Stack32;

  pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
  if ((*(u_int *)((int)instance->data + 0x10) & 8) == 0)
  {
    p_Var2 = MON_FindSphereForTerrain(instance);
    if (p_Var2 != (_HPrim *)0x0)
    {
      MON_SphereWorldPos(instance->matrix + p_Var2->segment, (_HSphere *)p_Var2->data, &_Stack32);
      iVar6 = pLVar1->terrain->numIntros;
      pIVar5 = pLVar1->terrain->introList;
      introRot = &pIVar5->rotation;
      while (iVar6 != 0)
      {
        if (((*(u_int *)&introRot[2].z & 0x8000) != 0) &&
            (iVar3 = MON_ReachableIntro(instance, &_Stack32, &pIVar5->position, introRot,
                                        checkOrientation),
             iVar3 != 0))
        {
          return 1;
        }
        iVar6 = iVar6 + -1;
        introRot = (_Rotation *)&introRot[9].z;
        pIVar5 = pIVar5 + 1;
      }
      Inst = (gameTrackerX.instanceList)->first;
      while (Inst != (_Instance *)0x0)
      {
        uVar4 = INSTANCE_Post(Inst, 1);
        if (((((uVar4 & 0x20) != 0) && (*(short *)((int)Inst->data + 2) == 3)) &&
             ((*(u_short *)((int)Inst->data + 8) & 0x58) != 0)) &&
            (iVar6 = MON_ReachableIntro(instance, &_Stack32, &Inst->position, (_Rotation *)0x0,
                                        checkOrientation),
             iVar6 != 0))
        {
          return 1;
        }
        Inst = Inst->next;
      }
    }
  }
  return 0;
}

void MON_TurnOffSphereCollisions(_Instance *instance)

{
  _HPrim *p_Var1;
  byte *pbVar2;
  int iVar3;

  iVar3 = instance->hModelList[instance->currentModel].numHPrims;
  if ((iVar3 != 0) &&
      (p_Var1 = instance->hModelList[instance->currentModel].hPrimList, pbVar2 = &p_Var1->withFlags,
       (p_Var1->withFlags & 0x20) != 0))
  {
    do
    {
      iVar3 = iVar3 + -1;
      *pbVar2 = *pbVar2 & 0xdf;
      pbVar2 = pbVar2 + 8;
    } while (iVar3 != 0);
  }
  return;
}

void MON_TurnOnAllSpheres(_Instance *instance)

{
  _HPrim *p_Var1;
  byte *pbVar2;
  int iVar3;

  iVar3 = instance->hModelList[instance->currentModel].numHPrims;
  if ((iVar3 != 0) &&
      (p_Var1 = instance->hModelList[instance->currentModel].hPrimList, pbVar2 = &p_Var1->withFlags,
       (p_Var1->withFlags & 0x20) == 0))
  {
    do
    {
      iVar3 = iVar3 + -1;
      *pbVar2 = *pbVar2 | 0x20;
      pbVar2 = pbVar2 + 8;
    } while (iVar3 != 0);
  }
  return;
}

void MON_ProcessSpecialFade(_Instance *instance)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  _Instance *p_Var4;
  void *pvVar5;
  int iVar6;
  short sVar7;
  int iVar8;

  pvVar5 = instance->extraData;
  if ((instance->object->oflags & 0x80000U) == 0)
  {
    if ((*(u_int *)((int)pvVar5 + 4) & 0x8000000) != 0)
    {
      iVar3 = (int)*(short *)((int)pvVar5 + 0x1a6) * gameTrackerX.timeMult;
      sVar2 = *(short *)((int)pvVar5 + 0x1a4);
      if (iVar3 < 0)
      {
        iVar3 = iVar3 + 0xfff;
      }
      iVar3 = (int)instance->fadeValue + (iVar3 >> 0xc);
      if ((int)*(short *)((int)pvVar5 + 0x1a6) < 1)
      {
        bVar1 = iVar3 < sVar2;
      }
      else
      {
        bVar1 = sVar2 < iVar3;
      }
      sVar7 = (short)iVar3;
      if (bVar1)
      {
        *(u_int *)((int)pvVar5 + 4) = *(u_int *)((int)pvVar5 + 4) & 0xf7ffffff;
        sVar7 = sVar2;
      }
      instance->fadeValue = sVar7;
    }
  }
  else
  {
    if ((instance->currentMainState != 0x17) && (instance->currentMainState != 0x10))
    {
      if ((gameTrackerX.gameData.asmData._8_4_ == 1000) ||
          ((gameTrackerX.gameData.asmData.MorphType == 1 &&
            (gameTrackerX.gameData.asmData.MorphTime != 1000))))
      {
        iVar3 = (int)*(short *)((int)pvVar5 + 0x1a4);
        iVar8 = 0x1000 - iVar3;
      }
      else
      {
        iVar8 = (int)*(short *)((int)pvVar5 + 0x1a4);
        iVar3 = 0x1000 - iVar8;
      }
      iVar6 = (int)gameTrackerX.gameData.asmData.MorphTime;
      if (iVar6 < 0x14d)
      {
        iVar6 = (0x1000 - iVar8) * iVar6;
        sVar2 = (short)iVar8 +
                ((short)((u_longlong)((longlong)iVar6 * 0xc4ce07b1) >> 0x28) - (short)(iVar6 >> 0x1f));
      }
      else
      {
        if (iVar6 < 0x29b)
        {
          sVar2 = 0x1000;
        }
        else
        {
          iVar3 = (iVar3 + -0x1000) * (iVar6 + -0x29a);
          sVar2 = ((short)((u_longlong)((longlong)iVar3 * 0xc4ce07b1) >> 0x28) -
                   (short)(iVar3 >> 0x1f)) +
                  0x1000;
        }
      }
      instance->fadeValue = sVar2;
      if (instance->fadeValue < 0)
      {
        instance->fadeValue = 0;
      }
      else
      {
        if (0x1000 < instance->fadeValue)
        {
          instance->fadeValue = 0x1000;
        }
      }
      if (instance->fadeValue == 0x1000)
      {
        MON_TurnOffSphereCollisions(instance);
        instance->flags = instance->flags | 0x800;
      }
      else
      {
        MON_TurnOnAllSpheres(instance);
        instance->flags = instance->flags & 0xfffff7ff;
      }
    }
  }
  p_Var4 = instance->LinkChild;
  while (p_Var4 != (_Instance *)0x0)
  {
    p_Var4->fadeValue = instance->fadeValue;
    p_Var4 = p_Var4->LinkSibling;
  }
  return;
}

void MON_StartSpecialFade(_Instance *instance, int fadeLevel, int fadeTime)

{
  void *pvVar1;
  u_int uVar2;

  pvVar1 = instance->extraData;
  *(undefined2 *)((int)pvVar1 + 0x1a4) = (short)fadeLevel;
  *(u_int *)((int)pvVar1 + 4) = *(u_int *)((int)pvVar1 + 4) | 0x8000000;
  fadeLevel = fadeLevel - instance->fadeValue;
  if (fadeTime < 1)
  {
    fadeTime = 1;
  }
  fadeTime;
  *(undefined2 *)((int)pvVar1 + 0x1a6) = (short)uVar2;
  if ((uVar2 & 0xffff) == 0)
  {
    if (fadeLevel < 0)
    {
      *(undefined2 *)((int)pvVar1 + 0x1a6) = 0xffff;
      return;
    }
    *(undefined2 *)((int)pvVar1 + 0x1a6) = 1;
  }
  return;
}

void MON_UnlinkFromRaziel(_Instance *instance)

{
  short *psVar1;
  u_char local_10;
  u_char local_c;
  _Instance *Inst;
  void *pvVar2;

  pvVar2 = instance->data;
  Inst = *(_Instance **)(*(int *)((int)instance->extraData + 0xc4) + 4);
  INSTANCE_UnlinkFromParent(instance);
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
  psVar1 = (short *)INSTANCE_Post(Inst, 7);
  if (psVar1 != (short *)0x0)
  {
    (instance->rotation).x = *psVar1;
    (instance->rotation).y = psVar1[1];
    (instance->rotation).z = psVar1[2] + 0x800;
  }
  INSTANCE_Query(Inst, 0x1000006, (int)instance);
  G2Anim_EnableSegment(&instance->anim, (u_int) * (byte *)((int)pvVar2 + 0x25));
  return;
}

void MON_BurnInAir(_Instance *instance, int currentState)

{
  u_long uVar1;
  int Data;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  if ((*puVar2 & 0x400000) == 0)
  {
    *puVar2 = *puVar2 | 0x400000;
    uVar1 = MON_GetAnim(instance);
    *(undefined **)(puVar2 + 0x46) = &DAT_00002710 + uVar1;
    MON_LaunchMonster(instance, (long)&DAT_00004960, -1, 0, 0);
    Data = SetFXHitData((_Instance *)0x0, 0, 0, 0x20);
    INSTANCE_Query(instance, 0x400000, Data);
  }
  instance->currentMainState = currentState;
  *puVar2 = *puVar2 & 0xfffffffe;
  return;
}

void MON_BirthEntry(_Instance *instance)

{
  int iVar1;
  MATRIX *pMVar2;

  if ((instance->matrix != (MATRIX *)0x0) && (*(char *)((int)instance->extraData + 0x161) < '\x0f'))
  {
    iVar1 = rand();
    pMVar2 = instance->matrix;
    PHYSOB_BirthProjectile(instance, pMVar2[1].t[0], pMVar2[1].t[1], pMVar2[1].t[2], (u_int)(iVar1 % 100 < 0x50) ^ 1,
                           10);
  }
  return;
}

void MON_SoulSucked(_Instance *instance)

{
  u_long uVar1;
  u_int *puVar2;

  puVar2 = (u_int *)instance->extraData;
  if ((*puVar2 & 0x200) != 0)
  {
    if ((*(u_int *)((int)instance->data + 0x10) & 8) == 0)
    {
      uVar1 = MON_GetAnim(instance);
      puVar2[0x43] = uVar1;
    }
    puVar2[0x36] = 0;
    MON_BirthEntry(instance);
  }
  return;
}

int MON_SetUpKnockBack(_Instance *instance, _Instance *enemy, evMonsterHitData *data)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  long a;
  long v;
  u_long uVar4;
  void *pvVar5;

  sVar3 = data->knockBackDistance;
  sVar1 = data->knockBackDuration;
  pvVar5 = instance->extraData;
  a = PHYSICS_FindVFromAAndD((int)sVar3, (int)sVar1);
  v = PHYSICS_FindAFromDAndT(a, (int)sVar3);
  sVar3 = MATH3D_AngleFromPosToPos(&instance->position, &enemy->position);
  bVar2 = 0x7ff < (((instance->rotation).z - sVar3) + 0x400U & 0xfff);
  if (bVar2)
  {
    PHYSICS_SetVAndAFromRot(instance, &instance->rotation, v, -a);
  }
  else
  {
    MON_MoveToPosition(instance, &enemy->position, 0x1000);
    PHYSICS_SetVAndAFromRot(instance, &instance->rotation, -v, a);
  }
  uVar4 = MON_GetAnim(instance);
  *(int *)((int)pvVar5 + 0x114) = uVar4 + (int)sVar1 * 0x21;
  return (u_int)!bVar2;
}

void MON_DoDrainEffects(_Instance *instance, _Instance *ei)

{
  int iVar1;
  MATRIX *pMVar2;
  void *pvVar3;
  void *pvVar4;
  _SVector local_38;
  _SVector local_30;
  _SVector local_28;
  _SVector _Stack32;

  pvVar4 = instance->data;
  pvVar3 = instance->extraData;
  memset(&_Stack32, 0, 8);
  if (ei == gameTrackerX.playerInstance)
  {
    iVar1 = rand();
    pMVar2 = ei->matrix;
    iVar1 = (iVar1 % (ei->object->modelList[ei->currentModel]->numSegments + -0x10)) * 0x20 + 0x1c0;
  }
  else
  {
    iVar1 = rand();
    pMVar2 = ei->matrix;
    iVar1 = iVar1 % ei->object->modelList[ei->currentModel]->numSegments << 5;
  }
  iVar1 = (int)pMVar2->m + iVar1;
  local_38.x = *(short *)(iVar1 + 0x14);
  local_38.y = *(short *)(iVar1 + 0x18);
  local_38.z = *(short *)(iVar1 + 0x1c);
  pMVar2 = instance->matrix + *(byte *)((int)pvVar4 + 0x19);
  iVar1 = pMVar2->t[0] - (int)local_38.x;
 6 + (iVar1 >> 0x1f) >> 3) - (short)(iVar1 >> 0x1f);
 iVar1 = pMVar2->t[1] - (int)local_38.y;
 6 + (iVar1 >> 0x1f) >> 3) - (short)(iVar1 >> 0x1f);
 iVar1 = pMVar2->t[2] - (int)local_38.z;
 6 + (iVar1 >> 0x1f) >> 3) - (short)(iVar1 >> 0x1f);
 local_30.x = *(short *)pMVar2->t;
 local_30.y = *(short *)(pMVar2->t + 1);
 local_30.z = *(short *)(pMVar2->t + 2);
 FX_Die(&local_38, &local_28, &_Stack32, 0, 0xff6060, 0x18, 0x14, 0);
 if (ei == gameTrackerX.playerInstance)
 {
   pMVar2 = ei->matrix;
   local_38.x = *(short *)pMVar2[0xe].t;
   local_38.y = *(short *)(pMVar2[0xe].t + 1);
   local_38.z = *(short *)(pMVar2[0xe].t + 2);
   *(u_int *)((int)pvVar3 + 0x118) =
       *(int *)((int)pvVar3 + 0x118) + (gameTrackerX.timeMult * 0x50 >> 0xc) & 0xfff;
   FX_CreateLightning(theCamera.core.wcTransform, gameTrackerX.drawOT, (MATRIX *)0x0,
                      *(short *)((int)pvVar3 + 0x118), &local_30, &local_38, 0, 0x60, 0x18, 0x50, 1,
                      0xd06060, 0xff6400);
 }
 return;
}
