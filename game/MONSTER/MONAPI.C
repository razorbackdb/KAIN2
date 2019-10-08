#include "THISDUST.H"
#include "MONAPI.H"

void MonsterProcess(_Instance *instance, GameTracker *gameTracker)

{
  _MonsterState *p_Var1;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar2;
  u_int *puVar3;

  puVar3 = (u_int *)instance->extraData;
  if (((puVar3 != (u_int *)0x0) && (instance->data != (void *)0x0)) && ((*puVar3 & 0x80000) == 0))
  {
    MONSENSE_DoSenses(instance);
    MON_DoCombatTimers(instance);
    p_Var1 = MON_DamageEffect(instance, instance->currentMainState);
    instance->flags2 = instance->flags2 & 0xffffffed;
    if ((*puVar3 & 0x80) == 0)
    {
      G2EmulationSwitchAnimation(instance);
    }
    (*p_Var1->stateFunction)(instance);
    if ((*puVar3 & 1) != 0)
    {
      p_Var1 = MON_DamageEffect(instance, instance->currentMainState);
      (*p_Var1->entryFunction)(instance);
    }
    *puVar3 = *puVar3 & 0xffffffbe;
    if ((instance->flags & 0x200U) != 0)
    {
      pTVar2 = MONTABLE_GetStateFuncs(instance);
      (*pTVar2)(instance, 0);
    }
    MON_ProcessLookAt(instance);
    MON_ProcessSpecialFade(instance);
  }
  return;
}

void MonsterInit(_Instance *instance, GameTracker *gameTracker)

{
  short sVar1;
  TDRFuncPtr_MONTABLE_GetCleanUpFunc pTVar2;
  _G2AnimKeylist_Type *keylist;
  TDRFuncPtr_MONTABLE_GetInitFunc pTVar3;
  _MonsterState *p_Var4;
  u_int *__s;
  int *piVar5;

  piVar5 = (int *)instance->data;
  if ((instance->flags & 0x20000U) == 0)
  {
    if ((piVar5 != (int *)0x0) && (*piVar5 == -0x531fff9c))
    {
      __s = (u_int *)MEMPACK_Malloc(0x25c, '\x17');
      *(u_int **)&instance->extraData = __s;
      if (instance->instanceID == 0)
      {
        if (__s == (u_int *)0x0)
        {
          return;
        }
        goto LAB_8007dc30;
      }
      if (__s != (u_int *)0x0)
      {
        memset(__s, 0, 0x25c);
        EnMessageQueue((__MessageQueue *)(__s + 2));
        instance->currentMainState = -1;
        *(char *)((int)__s + 0x162) = -1;
        sVar1 = (instance->position).z;
        __s[0x4a] = *(u_int *)&instance->position;
        *(short *)(__s + 0x4b) = sVar1;
        __s[0x68] = 0xffffffff;
        __s[0x42] = 0;
        instance->flags = instance->flags | 0x10040;
        if ((piVar5[4] & 0x10000U) == 0)
        {
          instance->flags2 = instance->flags2 | 0x100;
        }
        instance->maxXVel = 400;
        instance->maxYVel = 400;
        instance->maxZVel = 400;
        instance->xVel = 0;
        instance->yVel = 0;
        instance->zVel = 0;
        MONTABLE_SetQueryFunc(instance);
        MONTABLE_SetMessageFunc(instance);
        INSTANCE_ProcessIntro(instance);
        *(undefined2 *)((int)__s + 0x142) = *(undefined2 *)(__s + 0x50);
        MON_TurnOffBodySpheres(instance);
        MON_TurnOnWeaponSpheres(instance);
        MONSENSE_SetupSenses(instance);
        MON_AnimIDPlaying(instance);
        pTVar3 = MONTABLE_GetInitFunc(instance);
        (*pTVar3)(instance);
        if ((*__s & 1) == 0)
        {
          return;
        }
        p_Var4 = MON_DamageEffect(instance, instance->currentMainState);
        *__s = *__s & 0xfffffffe;
        (*p_Var4->entryFunction)(instance);
        return;
      }
    }
    instance->data = (void *)0x0;
    keylist = G2Instance_GetKeylist(instance, 0);
    G2Anim_GetKeylist(&instance->anim, keylist, 0);
  }
  else
  {
    __s = (u_int *)instance->extraData;
    pTVar2 = MONTABLE_GetDamageEffectFunc(instance);
    (*pTVar2)(instance);
    MONSENSE_RemoveSenses(instance);
  LAB_8007dc30:
    MEMPACK_Init((char *)__s);
  }
  return;
}

void SendHitObject(_Instance *instance, _Instance *hit, int type)

{
  _Instance **Data;
  void *pvVar1;
  int iVar2;
  void *pvVar3;

  pvVar3 = instance->extraData;
  iVar2 = *(int *)((int)pvVar3 + 8);
  do
  {
    pvVar1 = (void *)((int)pvVar3 + iVar2 * 8);
    if ((*(int *)((int)pvVar1 + 0x10) == 0x1000008) &&
        (*(_Instance **)&(*(_Instance **)((int)pvVar1 + 0x14))->node == hit))
      break;
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x10)
    {
      iVar2 = 0;
    }
  } while (iVar2 != *(int *)((int)pvVar3 + 0xc));
  if (iVar2 == *(int *)((int)pvVar3 + 0xc))
  {
    Data = (_Instance **)CIRC_Alloc(8);
    *Data = hit;
    *(int *)(Data + 1) = type;
    INSTANCE_Query(instance, 0x1000008, (int)Data);
  }
  return;
}

void MonsterCollide(_Instance *instance, GameTracker *gameTracker)

{
  bool bVar1;
  undefined2 uVar2;
  u_long uVar3;
  Intro *pIVar4;
  long lVar5;
  _CollideInfo *p_Var6;
  void **Data;
  int Data_00;
  void *pvVar7;
  void *pvVar8;
  int Data_01;
  BSPTree *bsp;
  void *pvVar9;
  _CollideInfo *collideInfo;
  u_int uVar10;
  _Terrain *p_Var11;
  _Instance *Inst;
  u_int *puVar12;
  void *local_50[4];
  _Instance *local_40;
  _Instance *local_3c;

  collideInfo = (_CollideInfo *)instance->collideInfo;
  puVar12 = (u_int *)instance->extraData;
  if (instance->data == (void *)0x0)
  {
    return;
  }
  if (collideInfo->type0 != '\x01')
  {
    return;
  }
  if (*(char *)((int)collideInfo->prim0 + 4) == '\t')
  {
    uVar10 = puVar12[0x2e];
    if (uVar10 == 0)
    {
      return;
    }
    if (collideInfo->type1 != '\x01')
    {
      return;
    }
    if (*(char *)((int)collideInfo->prim1 + 4) != '\b')
    {
      return;
    }
    Data_01 = (int)*(char *)(uVar10 + 7);
    Inst = (_Instance *)collideInfo->inst1;
    if ((*puVar12 & 0x20000000) != 0)
    {
      Data_01 = Data_01 << 1;
    }
    MON_TurnOnWeaponSpheres(instance);
    Data_01 = Data_01 * 0x100;
    Data_00 = Data_01;
    if (Data_01 < 0)
    {
      Data_00 = Data_01 + 0x7f;
    }
    Data_00 = SetFXHitData(instance, (u_int)(byte)collideInfo->segment, Data_00 >> 7, 0x100);
    INSTANCE_Query(Inst, 0x400000, Data_00);
    Data_01 = SetMonsterImpaleData(instance, (_Instance *)0x0, Data_01, (int)*(short *)(uVar10 + 4),
                                   (int)*(char *)(uVar10 + 6));
    INSTANCE_Query(Inst, 0x1000000, Data_01);
    uVar10 = puVar12[0x31];
    if (Inst != *(_Instance **)(uVar10 + 4))
    {
      return;
    }
    if ((*puVar12 & 0x10000000) != 0)
    {
      *(u_short *)(uVar10 + 0x16) = *(u_short *)(uVar10 + 0x16) | 0x1000;
    }
    *(u_short *)(puVar12[0x31] + 0x18) = *(u_short *)(puVar12[0x31] + 0x18) | 0x100;
    return;
  }
  bVar1 = true;
  switch (collideInfo->type1)
  {
  case '\x01':
    pvVar9 = collideInfo->prim1;
    SendHitObject(instance, (_Instance *)collideInfo->inst1, 1);
    if (*(char *)((int)pvVar9 + 4) != '\t')
    {
      if ((*(int *)&instance->position == *(int *)&instance->oldPos) &&
          ((instance->position).z == (instance->oldPos).z))
      {
        bVar1 = false;
      }
      break;
    }
    goto LAB_8007e314;
  case '\x02':
    SendHitObject(instance, (_Instance *)collideInfo->inst1, 2);
    break;
  case '\x03':
    bsp = (BSPTree *)collideInfo->inst1;
    if (((bsp->flags & 0xe0U) != 0) && ((instance->checkMask & 0x20) != 0))
    {
      MON_CheckTerrain(instance, bsp, (_TFace *)collideInfo->prim1);
    }
    if ((bsp->flags & 0x102U) == 0)
    {
      Data = (void **)CIRC_Alloc(0x10);
      pvVar9 = collideInfo->prim1;
      p_Var11 = (_Terrain *)collideInfo->level;
      if (*(short *)((int)pvVar9 + 10) == -1)
      {
        uVar2 = 0;
      }
      else
      {
        uVar2 = *(undefined2 *)((int)&(*(_Terrain **)p_Var11)->StartTextureList->attr +
                                (u_int) * (u_short *)((int)pvVar9 + 10));
      }
      *(undefined2 *)(Data + 3) = uVar2;
      *Data = pvVar9;
      uVar3 = INSTANCE_Post(instance, 1);
      if ((((uVar3 & 4) == 0) || (*(u_short *)((int)pvVar9 + 10) == 0xffff)) ||
          ((*(u_short *)((int)&(*(_Terrain **)p_Var11)->StartTextureList->attr +
                         (u_int) * (u_short *)((int)pvVar9 + 10)) &
            0x1000) == 0))
      {
        pIVar4 = MON_TestForTerrainImpale(instance, *(_Terrain **)p_Var11);
        if (pIVar4 == (Intro *)0x0)
        {
          lVar5 = COLLIDE_FindCollisionFaceNormal(collideInfo, (_Normal *)(Data + 1));
          if (lVar5 != 0)
          {
            (collideInfo->offset).x = (collideInfo->offset).x + (*(short *)(Data + 1) >> 10);
            (collideInfo->offset).y = (collideInfo->offset).y + (*(short *)((int)Data + 6) >> 10);
            INSTANCE_Query(instance, 0x1000007, (int)Data);
          }
        }
        else
        {
          INSTANCE_Query(instance, 0x100001c, pIVar4->UniqueID);
          (collideInfo->offset).x = 0;
          (collideInfo->offset).y = 0;
        }
        *puVar12 = *puVar12 | 8;
        Data = (void **)local_50;
        if (instance->LinkParent != (_Instance *)0x0)
        {
          p_Var6 = collideInfo;
          do
          {
            pvVar9 = *(void **)&p_Var6->flags;
            pvVar7 = p_Var6->prim0;
            pvVar8 = p_Var6->prim1;
            *Data = p_Var6->level;
            Data[1] = pvVar9;
            Data[2] = pvVar7;
            Data[3] = pvVar8;
            p_Var6 = (_CollideInfo *)&p_Var6->inst0;
            Data = Data + 4;
          } while (p_Var6 != collideInfo + 1);
          if (local_40 == instance)
          {
            local_40 = instance->LinkParent;
          }
          if (local_3c == instance)
          {
            local_3c = instance->LinkParent;
          }
          Data_01 = SetCollideInfoData((_CollideInfo *)local_50);
          INSTANCE_Query(instance->LinkParent, 0x200004, Data_01);
        }
        break;
      }
    }
  LAB_8007e314:
    bVar1 = false;
    break;
  case '\x05':
    if (((collideInfo->offset).z < -0x32) &&
        ((*(u_int *)((int)instance->data + 0x10) & 0x10004) == 0))
    {
      INSTANCE_Query(instance, 0x40017, 6);
    }
    SendHitObject(instance, (_Instance *)collideInfo->inst1, 5);
  }
  if (bVar1)
  {
    (instance->position).x = (instance->position).x + (collideInfo->offset).x;
    (instance->position).y = (instance->position).y + (collideInfo->offset).y;
    (instance->position).z = (instance->position).z + (collideInfo->offset).z;
    COLLIDE_MoveAllTransforms(instance, (SVECTOR *)&collideInfo->offset);
  }
  return;
}

void INSTANCE_AdditionalCollideFunctions(_Instance *instance, GameTracker *gameTracker)

{
  if (instance->data != (void *)0x0)
  {
    MON_CheckEnvironment(instance);
  }
  return;
}

u_long MonsterQuery(_Instance *instance, u_long query)

{
  MATRIX *pMVar1;
  _MonsterSaveInfo *saveData;
  u_int uVar2;
  u_int *puVar3;
  void *pvVar4;

  pvVar4 = instance->data;
  puVar3 = (u_int *)instance->extraData;
  pMVar1 = (MATRIX *)0x0;
  if (pvVar4 != (void *)0x0)
  {
    switch (query)
    {
    case 0:
      uVar2 = *puVar3;
      pMVar1 = (MATRIX *)0x40000000;
      if ((uVar2 & 0x200) == 0)
      {
        pMVar1 = (MATRIX *)0x12000000;
        if (instance->currentMainState != 0x1e)
        {
          pMVar1 = (MATRIX *)0x0;
          if ((uVar2 & 0x200000) == 0)
          {
            if ((((uVar2 & 0x10) != 0) || (puVar3[0x31] == 0)) ||
                (instance->currentMainState == 0x18))
            {
              if (*(char *)(puVar3[0x59] + 0x29) == '\0')
              {
                pMVar1 = (MATRIX *)0x10000000;
              }
              else
              {
                pMVar1 = (MATRIX *)0x90000000;
              }
            }
          }
          else
          {
            pMVar1 = (MATRIX *)0x4000000;
          }
          if ((*puVar3 & 0x100) != 0)
          {
            pMVar1 = (MATRIX *)((u_int)pMVar1 | 0x20000000);
          }
        }
      }
      break;
    case 1:
      pMVar1 = *(MATRIX **)((int)pvVar4 + 0x10);
      break;
    case 2:
      pMVar1 = (MATRIX *)(u_int) * (byte *)(puVar3[0x59] + 0x27);
      break;
    default:
      pMVar1 = (MATRIX *)GenericQuery(instance, query);
      break;
    case 9:
      pMVar1 = (MATRIX *)&DAT_00000020;
      if ((*puVar3 & 0x400) != 0)
      {
        pMVar1 = (MATRIX *)&DAT_00000010;
      }
      break;
    case 10:
      pMVar1 = (MATRIX *)puVar3[0x42];
      break;
    case 0xc:
      if (instance->matrix == (MATRIX *)0x0)
      {
        pMVar1 = (MATRIX *)0x0;
      }
      else
      {
        pMVar1 = instance->matrix + *(byte *)((int)pvVar4 + 0x19);
      }
      break;
    case 0xd:
      pMVar1 = (MATRIX *)0x0;
      if (instance->matrix != (MATRIX *)0x0)
      {
        pMVar1 = instance->matrix + 1;
      }
      break;
    case 0xf:
      pMVar1 = (MATRIX *)(u_int) * (byte *)((int)pvVar4 + 0x1a);
      break;
    case 0x18:
      saveData = (_MonsterSaveInfo *)CIRC_Alloc(0x10);
      MON_SetUpSaveInfo(instance, saveData);
      pMVar1 = (MATRIX *)SetControlSaveDataData(0x10, saveData);
      break;
    case 0x19:
      pMVar1 = (MATRIX *)(int)*(short *)(puVar3 + 0x51);
      break;
    case 0x21:
      pMVar1 = (MATRIX *)(*puVar3 >> 0x1d & 1);
      break;
    case 0x23:
      pMVar1 = (MATRIX *)PeekMessageQueue((__MessageQueue *)(puVar3 + 2));
      break;
    case 0x25:
      pMVar1 = (MATRIX *)&UNK_00000001;
      break;
    case 0x26:
      pMVar1 = (MATRIX *)SetShadowSegmentData(2);
      pMVar1->m[1] = (u_short) * (byte *)((int)pvVar4 + 0x20);
      *(u_short *)((int)pMVar1->m + 6) = (u_short) * (byte *)((int)pvVar4 + 0x21);
    }
  }
  return (u_long)pMVar1;
}

void MonsterMessage(_Instance *instance, u_long message, u_long data)

{
  u_int uVar1;
  int iVar2;
  u_char local_18;
  u_int *puVar3;
  u_char local_14;

  puVar3 = (u_int *)instance->extraData;
  if (puVar3 != (u_int *)0x0)
  {
    if ((undefined *)message == &DAT_00100007)
    {
      MON_GetSaveInfo(instance, *(_MonsterSaveInfo **)(data + 4));
    }
    else
    {
      if ((message == 0x1000020) && (uVar1 = puVar3[0x31], uVar1 != 0))
      {
        *(u_short *)(uVar1 + 0x16) = *(u_short *)(uVar1 + 0x16) & 0xefff;
      }
    }
    if ((instance->flags2 & 0x4000000U) == 0)
    {
      if (message == 0x40013)
      {
        if (data == 0)
        {
          *puVar3 = *puVar3 & 0xfff7ffff;
        }
        else
        {
          *puVar3 = *puVar3 | 0x80000;
        }
      }
      else
      {
        if (message < 0x40014)
        {
          if (message == 0x4000b)
          {
            (instance->rotation).x = *(short *)data;
            (instance->rotation).y = *(short *)(data + 2);
            (instance->rotation).z = *(short *)(data + 4);
            return;
          }
          if (message < 0x4000c)
          {
            if (message == 0x4000a)
            {
              STREAM_SetInstancePosition(&gameTrackerX, instance, (evPositionData *)data);
              return;
            }
          }
          else
          {
            if (message == 0x4000e)
            {
              if (data == 0)
              {
                uVar1 = *puVar3 & 0xfffffffb;
              }
              else
              {
                uVar1 = *puVar3 | 4;
              }
              *puVar3 = uVar1;
              iVar2 = instance->currentMainState;
              if (((iVar2 != 1) && (iVar2 != 5)) && (iVar2 != 0x13))
              {
                return;
              }
              MON_SwitchStateDoEntry(instance, (MonsterState)CONCAT44(local_14, local_18));
              return;
            }
          }
        }
        else
        {
          if (message == 0x200000)
          {
            MONSENSE_StartMonsterIRList(instance);
            return;
          }
          if (message < 0x200001)
          {
            if ((undefined *)message == &DAT_00100008)
            {
              MON_RelocateCoords(instance, (_SVector *)data);
              return;
            }
          }
          else
          {
            if (message == 0x200001)
            {
              MONSENSE_FirstSense(instance, (evCollideInstanceStatsData *)data);
              return;
            }
          }
        }
        DeMessageQueue((__MessageQueue *)(puVar3 + 2), message, data);
      }
    }
  }
  return;
}

void AnimDistanceAndVel(Object *object, _MonsterAnim *mAnim)

{
  short intervalEnd;
  u_short uVar1;
  _G2Bool_Enum _Var2;
  long lVar3;
  _G2AnimKeylist_Type *keylist;
  _G2Anim_Type _Stack216;
  _G2SVector3_Type local_20;

  keylist = object->animList[mAnim->index[0]];
  _G2Anim_InitializeChannel_AdaptiveDelta(&_Stack216, *object->modelList);
  _Stack216.section[0].firstSeg = '\0';
  _Stack216.section[0].segCount = *(u_char *)&(*object->modelList)->numSegments;
  _Stack216.section[0].callback = (_func_8 *)0x0;
  _Stack216.section[0].callbackData = (void *)0x0;
  _G2AnimSection_InterpStateToQuat(_Stack216.section, (_G2AnimInterpInfo_Type *)0x0);
  G2AnimSection_InterpToKeylistAtTime(_Stack216.section, keylist, (int)mAnim->index[0], 0);
  _Var2 = G2Anim_SegmentHasActiveChannels(&_Stack216, 0, 0x700);
  if (_Var2 != G2FALSE)
  {
    intervalEnd = G2AnimKeylist_GetDuration(keylist);
    G2AnimSection_UpdateOverInterval(&_Stack216, 0, intervalEnd, &local_20);
    lVar3 = MATH3D_FastSqrt0((int)local_20.x * (int)local_20.x + (int)local_20.y * (int)local_20.y +
                             (int)local_20.z * (int)local_20.z);
    uVar1 = G2AnimKeylist_GetDuration(keylist);
    mAnim->distance = (u_short)lVar3;
    mAnim->velocity =
 ((int)((u_int)uVar1 << 0x10) >> 4));
  }
  G2Anim_Init(&_Stack216);
  return;
}

void TranslateAnimList(Object *object, _MonsterAnim *animList, int numAnims)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  _G2AnimKeylist_Type *keylist;

  if ((animList != (_MonsterAnim *)0x0) && (iVar5 = 0, 0 < numAnims))
  {
    pbVar4 = &animList->startFrame;
    do
    {
      keylist = object->animList[(int)(char)pbVar4[5]];
      if ((int)(char)pbVar4[5] != -1)
      {
        AnimDistanceAndVel(object, animList);
        bVar1 = *pbVar4;
        sVar2 = G2AnimKeylist_GetDuration(keylist);
 100) * 0x10000 >> 0x10 <= (int)(u_int)bVar1)
 {
   iVar3 = G2AnimKeylist_GetKeyframeCount(keylist);
   *pbVar4 = (char)iVar3 - 1;
 }
      }
      iVar5 = iVar5 + 1;
      pbVar4 = pbVar4 + 0x10;
      animList = animList + 1;
    } while (iVar5 < numAnims);
  }
  return;
}

void MonsterTranslateAnim(Object *object)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int *piVar7;

  piVar7 = (int *)object->data;
  if ((object->oflags2 & 0x10000000U) == 0)
  {
    if ((object->oflags & 0x8000000U) == 0)
    {
      MONTABLE_SetupTablePointer(object);
    }
    else
    {
      if ((object->relocModule == (void *)0x0) ||
          (*(char **)((int)object->relocModule + 0x18) != "May 25 1999"))
      {
        object->data = (void *)0x0;
        return;
      }
    }
    if ((piVar7 != (int *)0x0) && (*piVar7 == -0x531fff9c))
    {
      TranslateAnimList(object, (_MonsterAnim *)piVar7[0x10], (int)*(char *)(piVar7 + 0xb));
      iVar6 = 0;
      if ('\0' < *(char *)((int)piVar7 + 0x2a))
      {
        do
        {
          iVar3 = piVar7[0xe] + iVar6 * 0x20;
          if ((*(char *)(iVar3 + 0xe) <= *(char *)(iVar3 + 10)) ||
              (*(char *)(iVar3 + 0xe) <= *(char *)(iVar3 + 0xc)))
          {
            object->data = (void *)0x0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(char *)((int)piVar7 + 0x2a));
      }
      iVar6 = 0;
      if ('\0' < *(char *)((int)piVar7 + 0x29))
      {
        do
        {
          iVar3 = *(int *)(iVar6 * 4 + piVar7[0xd]);
          if (*(short *)(iVar3 + 10) == 0)
          {
            iVar4 = 0;
            sVar5 = 0;
            if (0 < (int)*(char *)(iVar3 + 0x19))
            {
              iVar2 = iVar3;
              sVar5 = 0;
              do
              {
                sVar1 = *(short *)(piVar7[0xe] + (int)*(char *)(iVar2 + 0x28) * 0x20);
                if (sVar5 < sVar1)
                {
                  sVar5 = sVar1;
                }
                iVar4 = iVar4 + 1;
                iVar2 = iVar3 + iVar4;
              } while (iVar4 < (int)*(char *)(iVar3 + 0x19));
            }
            *(short *)(iVar3 + 10) = sVar5 + 200;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(char *)((int)piVar7 + 0x29));
      }
    }
  }
  return;
}

void MonsterRelocateTune(Object *object, long offset)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int **ppiVar5;
  int iVar6;
  int **ppiVar7;

  piVar2 = (int *)object->data;
  if ((piVar2 != (int *)0x0) && (*piVar2 == -0x531fff9c))
  {
    iVar3 = 0;
    if (piVar2[1] != 0)
    {
      iVar3 = piVar2[1] + offset;
    }
    iVar4 = 0;
    piVar2[1] = iVar3;
    if (piVar2[2] != 0)
    {
      iVar4 = piVar2[2] + offset;
    }
    iVar3 = 0;
    piVar2[2] = iVar4;
    if (piVar2[3] != 0)
    {
      iVar3 = piVar2[3] + offset;
    }
    iVar4 = 0;
    piVar2[3] = iVar3;
    if (piVar2[0xc] != 0)
    {
      iVar4 = piVar2[0xc] + offset;
    }
    iVar3 = 0;
    piVar2[0xc] = iVar4;
    if (piVar2[0xd] != 0)
    {
      iVar3 = piVar2[0xd] + offset;
    }
    iVar4 = 0;
    piVar2[0xd] = iVar3;
    if (piVar2[0xe] != 0)
    {
      iVar4 = piVar2[0xe] + offset;
    }
    iVar3 = 0;
    piVar2[0xe] = iVar4;
    if (piVar2[0xf] != 0)
    {
      iVar3 = piVar2[0xf] + offset;
    }
    iVar4 = 0;
    piVar2[0xf] = iVar3;
    if (piVar2[0x10] != 0)
    {
      iVar4 = piVar2[0x10] + offset;
    }
    iVar3 = 0;
    piVar2[0x10] = iVar4;
    if (piVar2[0x11] != 0)
    {
      iVar3 = piVar2[0x11] + offset;
    }
    iVar4 = 0;
    piVar2[0x11] = iVar3;
    if (piVar2[0x12] != 0)
    {
      iVar4 = piVar2[0x12] + offset;
    }
    iVar3 = 0;
    piVar2[0x12] = iVar4;
    if (piVar2[0x13] != 0)
    {
      iVar3 = piVar2[0x13] + offset;
    }
    ppiVar7 = (int **)piVar2[0xc];
    iVar4 = 0;
    piVar2[0x13] = iVar3;
    if ('\0' < *(char *)(piVar2 + 10))
    {
      do
      {
        piVar1 = (int *)0x0;
        if (*ppiVar7 != (int *)0x0)
        {
          piVar1 = (int *)((int)*ppiVar7 + offset);
        }
        iVar3 = 0;
        *ppiVar7 = piVar1;
        ppiVar5 = (int **)piVar2[0xc];
        if (0 < iVar4)
        {
          do
          {
            if (*ppiVar5 == piVar1)
              break;
            iVar3 = iVar3 + 1;
            ppiVar5 = ppiVar5 + 1;
          } while (iVar3 < iVar4);
        }
        if (iVar3 == iVar4)
        {
          iVar3 = 0;
          if (*piVar1 != 0)
          {
            iVar3 = *piVar1 + offset;
          }
          iVar6 = 0;
          *piVar1 = iVar3;
          if (piVar1[1] != 0)
          {
            iVar6 = piVar1[1] + offset;
          }
          iVar3 = 0;
          piVar1[1] = iVar6;
          if (piVar1[2] != 0)
          {
            iVar3 = piVar1[2] + offset;
          }
          iVar6 = 0;
          piVar1[2] = iVar3;
          if (piVar1[3] != 0)
          {
            iVar6 = piVar1[3] + offset;
          }
          iVar3 = 0;
          piVar1[3] = iVar6;
          if (piVar1[4] != 0)
          {
            iVar3 = piVar1[4] + offset;
          }
          piVar1[4] = iVar3;
        }
        iVar4 = iVar4 + 1;
        ppiVar7 = ppiVar7 + 1;
      } while (iVar4 < *(char *)(piVar2 + 10));
    }
    iVar3 = (int)*(char *)((int)piVar2 + 0x29);
    piVar2 = (int *)piVar2[0xd];
    while (iVar3 != 0)
    {
      iVar4 = 0;
      if (*piVar2 != 0)
      {
        iVar4 = *piVar2 + offset;
      }
      *piVar2 = iVar4;
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + 1;
    }
  }
  return;
}

void MonsterRelocateInstanceObject(_Instance *instance, long offset)

{
  void *pvVar1;
  _func_4 *p_Var2;
  _func_5 *p_Var3;
  _func_2 *p_Var4;
  _func_2 *p_Var5;
  int iVar6;
  int iVar7;

  pvVar1 = instance->extraData;
  if (pvVar1 != (void *)0x0)
  {
    iVar6 = 0;
    if (*(int *)((int)pvVar1 + 0x164) != 0)
    {
      iVar6 = *(int *)((int)pvVar1 + 0x164) + offset;
    }
    iVar7 = 0;
    *(int *)((int)pvVar1 + 0x164) = iVar6;
    if (*(int *)((int)pvVar1 + 0xb8) != 0)
    {
      iVar7 = *(int *)((int)pvVar1 + 0xb8) + offset;
    }
    iVar6 = 0;
    *(int *)((int)pvVar1 + 0xb8) = iVar7;
    if (*(int *)((int)pvVar1 + 0xbc) != 0)
    {
      iVar6 = *(int *)((int)pvVar1 + 0xbc) + offset;
    }
    *(int *)((int)pvVar1 + 0xbc) = iVar6;
    if ((instance->object->oflags & 0x8000000U) != 0)
    {
      if (*(int *)((int)instance->object->relocModule + 0xc) != 0)
      {
        p_Var2 = (_func_4 *)0x0;
        if (instance->queryFunc != (_func_4 *)0x0)
        {
          p_Var2 = instance->queryFunc + offset;
        }
        instance->queryFunc = p_Var2;
      }
      if (*(int *)((int)instance->object->relocModule + 0x10) != 0)
      {
        p_Var3 = (_func_5 *)0x0;
        if (instance->messageFunc != (_func_5 *)0x0)
        {
          p_Var3 = instance->messageFunc + offset;
        }
        instance->messageFunc = p_Var3;
      }
      p_Var5 = instance->collideFunc;
      if (p_Var5 != MonsterCollide)
      {
        p_Var4 = (_func_2 *)0x0;
        if (p_Var5 != (_func_2 *)0x0)
        {
          p_Var4 = p_Var5 + offset;
        }
        instance->collideFunc = p_Var4;
      }
    }
  }
  return;
}

void MONAPI_TurnHead(_Instance *instance, short *rotx, short *rotz, GameTracker *gameTracker)

{
  short sVar1;

  sVar1 = -0x300;
  if ((*rotx < -0x300) || (sVar1 = 0x200, 0x200 < *rotx))
  {
    *rotx = sVar1;
  }
  if (*rotz < 0x401)
  {
    sVar1 = -0x400;
    if (-0x401 < *rotz)
      goto LAB_8007efc0;
  }
  else
  {
    sVar1 = 0x400;
  }
  *rotz = sVar1;
LAB_8007efc0:
  MON_LookInDirection(instance, -*rotx, *rotz);
  return;
}

void MONAPI_SetLookAround(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_DisableHeadMove(instance);
  *(u_char *)((int)pvVar1 + 0x108) = 0x80000;
  return;
}

void MONAPI_ResetLookAround(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_EnableHeadMove(instance);
  *(u_char *)((int)pvVar1 + 0x108) = 1;
  return;
}

long MONAPI_OkToLookAround(_Instance *instance)

{
  return (u_int)(instance->currentMainState == 2);
}

void MONAPI_DeleteRegen(_MONAPI_Regenerator *regen)

{
  GlobalSave->numRegens = GlobalSave->numRegens + -1;
  memcpy(regen, regen + 1,
         ((int)GlobalSave->numRegens - ((int)regen + (-0x10 - (int)GlobalSave) >> 3)) * 8);
  return;
}

void MONAPI_ProcessGenerator(void)

{
  Level *pLVar1;
  u_long uVar2;
  u_int *puVar3;
  Intro *intro;
  int iVar4;
  short *psVar5;
  _MONAPI_Regenerator *regen;
  int iVar6;

  iVar6 = 0;
  regen = GlobalSave->regenEntries;
  if ('\0' < GlobalSave->numRegens)
  {
    psVar5 = &GlobalSave->regenEntries[0].streamUnitID;
    do
    {
      uVar2 = gameTrackerX.currentMaterialTime;
      if (gameTrackerX.gameData.asmData.MorphType != 0)
      {
        uVar2 = gameTrackerX.currentSpectralTime;
      }
      if (regen->regenTime < uVar2)
      {
        pLVar1 = STREAM_GetWaterZLevel((int)*psVar5);
        if (pLVar1 == (Level *)0x0)
        {
        LAB_8007f180:
          MONAPI_DeleteRegen(regen);
        }
        else
        {
          iVar4 = pLVar1->numIntros;
          intro = pLVar1->introList;
          puVar3 = (u_int *)&intro->flags;
          while (iVar4 != 0)
          {
            iVar4 = iVar4 + -1;
            if (puVar3[-6] == (int)psVar5[-1])
            {
              if ((*puVar3 & 0x400) != 0)
                goto LAB_8007f180;
              INSTANCE_InsertInstanceGroup(intro, *psVar5);
              break;
            }
            puVar3 = puVar3 + 0x13;
            intro = intro + 1;
          }
        }
      }
      else
      {
        iVar6 = iVar6 + 1;
        psVar5 = psVar5 + 4;
        regen = regen + 1;
      }
    } while (iVar6 < GlobalSave->numRegens);
  }
  return;
}

void MONAPI_AddToGenerator(_Instance *instance)

{
  u_long uVar1;
  _MONAPI_Regenerator *p_Var2;
  void *pvVar3;

  if ((int)GlobalSave->numRegens < 9)
  {
    pvVar3 = instance->extraData;
    p_Var2 = GlobalSave->regenEntries + (int)GlobalSave->numRegens;
    GlobalSave->numRegens = GlobalSave->numRegens + '\x01';
    uVar1 = MON_GetAnim(instance);
    p_Var2->regenTime = uVar1 + (int)*(short *)((int)pvVar3 + 0x146) * 1000;
    p_Var2->introUniqueID = *(short *)&instance->introUniqueID;
    p_Var2->streamUnitID = *(short *)&instance->birthStreamUnitID;
  }
  return;
}

void MONAPI_CheckGenerator(_Instance *instance)

{
  _MONAPI_Regenerator *regen;
  int iVar1;

  regen = GlobalSave->regenEntries;
  iVar1 = 0;
  if ('\0' < GlobalSave->numRegens)
  {
    do
    {
      iVar1 = iVar1 + 1;
      if ((int)regen->introUniqueID == instance->introUniqueID)
      {
        MONAPI_DeleteRegen(regen);
        return;
      }
      regen = regen + 1;
    } while (iVar1 < GlobalSave->numRegens);
  }
  return;
}
