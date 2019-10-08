#include "THISDUST.H"
#include "INSTANCE.H"

void INSTANCE_DefaultInit(_Instance *instance)

{
  u_int uVar1;

  if ((gameTrackerX.streamFlags & 0x2000000U) == 0)
  {
    uVar1 = instance->flags2;
    instance->flags2 = uVar1 | 1;
    if ((uVar1 & 0x20000000) == 0)
    {
      instance->flags = instance->flags & 0xfffbffff;
      instance->flags2 = instance->flags2 | 0x20000000;
    }
    else
    {
      instance->flags = instance->flags | 0x40000;
    }
    if ((instance->object->animList != (_G2AnimKeylist_Type **)0x0) &&
        ((instance->object->oflags2 & 0x40000000U) == 0))
    {
      G2Anim_Init(&instance->anim);
    }
  }
  return;
}

void INSTANCE_DeactivatedProcess(_Instance *instance)

{
  u_int uVar1;
  u_int uVar2;

  uVar1 = instance->flags2;
  uVar2 = uVar1 & 0xfffffffe;
  instance->flags2 = uVar2;
  if ((instance->flags & 0x40000U) == 0)
  {
    uVar2 = uVar1 & 0xdffffffe;
  }
  else
  {
    instance->flags = instance->flags & 0xfffbffff;
    uVar2 = uVar2 | 0x20000000;
  }
  instance->flags2 = uVar2;
  if ((instance->object->animList != (_G2AnimKeylist_Type **)0x0) &&
      ((instance->object->oflags2 & 0x40000000U) == 0))
  {
    G2Anim_Restore(&instance->anim);
  }
  return;
}

void INSTANCE_ForceActive(_Instance *instance)

{
  if ((instance->flags2 & 1U) != 0)
  {
    INSTANCE_DeactivatedProcess(instance);
  }
  return;
}

void INSTANCE_DeactivateFarInstances(_Instance *instance, GameTracker *gameTracker)

{
  return;
}

void INSTANCE_Reactivate(GameTracker *gameTracker)

{
  u_long uVar1;
  u_int uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  _Instance *Inst;
  int iVar6;

  iVar5 = gameTracker->instanceList->numInstances;
  Inst = gameTracker->instanceList->first;
  iVar6 = (iVar5 >> 3) + 1;
  if (iVar5 <= DAT_800cf588)
  {
    DAT_800cf588 = 0;
  }
  iVar3 = DAT_800cf588;
  DAT_800cf588 = DAT_800cf588 + iVar6;
  if (iVar5 <= DAT_800cf588)
  {
    DAT_800cf588 = 0;
  }
  while (iVar3 != 0)
  {
    Inst = Inst->next;
    iVar3 = iVar3 + -1;
  }
  do
  {
    if ((Inst == (_Instance *)0x0) || (iVar6 == 0))
    {
      return;
    }
    if (((((Inst->flags2 & 0x80U) == 0) && ((Inst->object->oflags & 0x10000U) == 0)) &&
         (uVar1 = INSTANCE_Post(Inst, 0x23), uVar1 == 0)) &&
        ((Inst->LinkParent == (_Instance *)0x0 && (Inst->matrix != (MATRIX *)0x0))))
    {
      DAT_1f800000 = (Inst->position).x - theCamera.core.position.x;
      iVar5 = (u_int)(u_short)(Inst->position).y - (u_int)(u_short)theCamera.core.position.y;
      DAT_1f800002 = (undefined2)iVar5;
      iVar5 = iVar5 * 0x10000 >> 0x10;
      iVar4 = (u_int)(u_short)(Inst->position).z - (u_int)(u_short)theCamera.core.position.z;
      iVar3 = iVar4 * 0x10000 >> 0x10;
      DAT_1f800004 = (undefined2)iVar4;
      iVar5 = (int)DAT_1f800000 * (int)DAT_1f800000 + iVar5 * iVar5 + iVar3 * iVar3;
      if ((Inst->flags & 0x200U) == 0)
      {
        if ((Inst->flags2 & 0x80000U) == 0)
        {
          iVar3 = (int)Inst->object->removeDist;
          iVar3 = iVar3 * iVar3;
        }
        else
        {
          iVar3 = gameTracker->defRemoveDist * gameTracker->defRemoveDist;
        }
        uVar2 = Inst->flags2 & 1;
        if (iVar5 <= iVar3)
          goto LAB_80032038;
      }
      else
      {
        iVar3 = (int)Inst->object->vvRemoveDist;
        if (iVar5 <= iVar3 * iVar3)
        {
          uVar2 = Inst->flags2 & 1;
          goto LAB_80032038;
        }
        uVar2 = Inst->flags2 & 1;
      }
      if (uVar2 == 0)
      {
        INSTANCE_DefaultInit(Inst);
      }
    }
    else
    {
      uVar2 = Inst->flags2 & 1;
    LAB_80032038:
      if (uVar2 != 0)
      {
        INSTANCE_DeactivatedProcess(Inst);
      }
    }
    Inst = Inst->next;
    iVar6 = iVar6 + -1;
  } while (true);
}

void INSTANCE_InitInstanceList(_InstanceList *list, _InstancePool *pool)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  pool->numFreeInstances = 0x3c;
  iVar4 = 1;
  iVar6 = 8;
  iVar5 = 0x538;
  plVar3 = &pool->instance[0].light_color;
  do
  {
    iVar2 = (int)&pool->nextInstanceID + iVar6;
    iVar6 = iVar6 + 0x298;
    iVar1 = (int)&pool->nextInstanceID + iVar5;
    iVar5 = iVar5 + 0x298;
    plVar3[4] = iVar1;
    plVar3[5] = iVar2;
    iVar4 = iVar4 + 1;
    plVar3 = plVar3 + 0xa6;
  } while (iVar4 < 0x3b);
  iVar4 = 0;
  pool->instance[0].next = pool->instance + 1;
  pool->instance[0].prev = (_Instance *)0x0;
  pool->instance[0x3b].prev = (_Instance *)(&DAT_00009678 + (int)pool);
  pool->instance[0x3b].next = (_Instance *)0x0;
  pool->first_free = pool->instance;
  list->pool = pool;
  list->numInstances = 0;
  list->first = (_Instance *)0x0;
  do
  {
    list->group[0].next = (NodeType *)0x0;
    list->group[0].prev = (NodeType *)0x0;
    iVar4 = iVar4 + 1;
    list = (_InstanceList *)&list->pool;
  } while (iVar4 < 0x20);
  pool->nextInstanceID = 1;
  return;
}

_Instance *INSTANCE_CleanUpInstanceList(_InstanceList *list)

{
  int iVar1;
  _Instance *p_Var2;
  _InstancePool *p_Var3;
  _Instance *p_Var4;

  iVar1 = list->pool->numFreeInstances;
  if (iVar1 != 0)
  {
    list->pool->numFreeInstances = iVar1 + -1;
    p_Var4 = list->pool->first_free;
    list->pool->first_free = p_Var4->next;
    p_Var2 = list->first;
    list->first = p_Var4;
    p_Var4->next = p_Var2;
    if (p_Var2 != (_Instance *)0x0)
    {
      p_Var2->prev = p_Var4;
    }
    p_Var4->prev = (_Instance *)0x0;
    p_Var3 = list->pool;
    iVar1 = p_Var3->nextInstanceID;
    p_Var4->instanceID = iVar1;
    p_Var3->nextInstanceID = iVar1 + 1;
    list->numInstances = list->numInstances + 1;
    return p_Var4;
  }
  return (_Instance *)0x0;
}

long INSTANCE_KillInstance(_Instance *instance)

{
  int iVar1;
  u_int uVar2;
  u_int uVar3;

  uVar2 = instance->object->oflags;
  uVar3 = 0;
  if ((uVar2 & 0x80) != 0)
  {
    uVar3 = (u_int)((instance->flags & 0x8000U) == 0);
  }
  if (((uVar2 & 0x20) != 0) && ((instance->flags & 0x2000U) == 0))
  {
    uVar3 = uVar3 | 2;
  }
  if (((instance->object->oflags & 0x40U) != 0) && ((instance->flags & 0x4000U) == 0))
  {
    uVar3 = uVar3 | 4;
  }
  if (((instance->object->oflags & 0x10U) != 0) && ((instance->flags & 0x1000U) == 0))
  {
    uVar3 = uVar3 | 0x10;
  }
  if ((instance->object->oflags & 1U) == 0)
  {
    iVar1 = strcmpi(instance->object->name, "raziel__");
    if (iVar1 != 0)
    {
      uVar3 = uVar3 & 0xfffffffc;
    }
  }
  else
  {
    uVar3 = uVar3 | 8;
  }
  return uVar3;
}

void INSTANCE_IntroduceInstance(_InstanceList *list, _Instance *instance)

{
  long lVar1;

  lVar1 = INSTANCE_KillInstance(instance);
  LIST_GetFunc(list->group + lVar1, (NodeType *)instance);
  return;
}

void INSTANCE_ReallyRemoveInstance(_InstanceList *list, _Instance *instance, long reset)

{
  _Instance *p_Var1;
  GameTracker *pGVar2;
  Intro *pIVar3;
  int iVar4;

  EVENT_RemoveInstanceFromInstanceList(instance);
  if ((instance->flags & 0x800000U) != 0)
  {
    SAVE_DoInstanceDeadDead(instance);
  }
  if ((instance->flags & 2U) == 0)
  {
    pIVar3 = instance->intro;
    if (pIVar3 != (Intro *)0x0)
    {
      pIVar3->flags = pIVar3->flags & ~reset;
      instance->intro->instance = (_Instance *)0x0;
    }
  }
  if (instance->prev == (_Instance *)0x0)
  {
    list->first = instance->next;
  }
  else
  {
    instance->prev->next = instance->next;
  }
  if (instance->next != (_Instance *)0x0)
  {
    instance->next->prev = instance->prev;
  }
  instance->instanceID = 0;
  list->numInstances = list->numInstances + -1;
  list->pool->numFreeInstances = list->pool->numFreeInstances + 1;
  p_Var1 = list->pool->first_free;
  list->pool->first_free = instance;
  instance->prev = (_Instance *)0x0;
  instance->next = p_Var1;
  if (p_Var1 != (_Instance *)0x0)
  {
    p_Var1->prev = instance;
  }
  LIST_DeleteFunc((NodeType *)instance);
  FX_EndInstanceEffects(instance);
  if ((instance->flags & 0x10000U) != 0)
  {
    instance->flags = instance->flags | 0x20000;
    OBTABLE_InstanceInit(instance);
  }
  if ((instance->object->animList != (_G2AnimKeylist_Type **)0x0) &&
      ((instance->object->oflags2 & 0x40000000U) == 0))
  {
    G2Anim_Init(&instance->anim);
  }
  if (instance->shadow0 != (void *)0x0)
  {
    *(u_char *)((int)instance->shadow0 + 0x10) = 0;
  }
  if (instance->shadow1 != (void *)0x0)
  {
    *(u_char *)((int)instance->shadow1 + 0x10) = 0;
  }
  if ((instance->object->oflags2 & 4U) != 0)
  {
    SOUND_StopInstanceSound(instance->object->soundData, instance->soundInstanceTbl);
  }
  if (instance->LinkParent != (_Instance *)0x0)
  {
    INSTANCE_UnlinkFromParent(instance);
  }
  if (instance->LinkChild != (_Instance *)0x0)
  {
    INSTANCE_UnlinkChildren(instance);
  }
  if (instance->hModelList != (_HModel *)0x0)
  {
    MEMPACK_Init((char *)instance->hModelList);
  }
  if (instance->perVertexColor != (CVECTOR *)0x0)
  {
    MEMPACK_Init((char *)instance->perVertexColor);
    instance->perVertexColor = (CVECTOR *)0x0;
  }
  iVar4 = 0;
  pGVar2 = &gameTrackerX;
  do
  {
    iVar4 = iVar4 + 1;
    if ((pGVar2->gameData).asmData.lightInstances[0].lightInstance == instance)
    {
      (pGVar2->gameData).asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
      return;
    }
    pGVar2 = (GameTracker *)&(pGVar2->gameData).asmData.lightInstances[0].g;
  } while (iVar4 < 1);
  return;
}

void COLLIDE_InstanceListTerrain(_InstanceList *list, long reset)

{
  _Instance **pp_Var1;
  _Instance *instance;
  u_int uVar2;
  _Instance *p_Var3;

  p_Var3 = list->first;
  if (p_Var3 != (_Instance *)0x0)
  {
    do
    {
      uVar2 = p_Var3->flags;
      pp_Var1 = &p_Var3->next;
      if ((uVar2 & 0x400) == 0)
      {
        if ((uVar2 & 0x20) != 0)
        {
          p_Var3->flags = uVar2 | 0x20;
        }
      }
      else
      {
        if ((uVar2 & 0x20) != 0)
        {
          p_Var3->flags = uVar2 & 0xffffffdf;
        }
      }
      p_Var3 = *pp_Var1;
    } while (*pp_Var1 != (_Instance *)0x0);
    p_Var3 = list->first;
  }
  while (instance = p_Var3, instance != (_Instance *)0x0)
  {
    p_Var3 = instance->next;
    if ((instance->flags & 0x20U) != 0)
    {
      INSTANCE_ReallyRemoveInstance(list, instance, reset);
    }
  }
  return;
}

long INSTANCE_GetIntroCommand(Intro *intro, short streamUnitID)

{
  long *plVar1;
  long lVar2;
  _Instance *p_Var3;
  long lVar4;

  p_Var3 = (gameTrackerX.instanceList)->first;
  lVar4 = 0;
  if (p_Var3 != (_Instance *)0x0)
  {
    do
    {
      plVar1 = &p_Var3->introUniqueID;
      p_Var3 = p_Var3->next;
      if (intro->UniqueID == *plVar1)
      {
        lVar4 = 1;
        intro->flags = intro->flags | 8;
        break;
      }
    } while (p_Var3 != (_Instance *)0x0);
  }
  if ((lVar4 == 0) &&
      ((lVar2 = SAVE_HasSavedIntro(intro, (int)streamUnitID), lVar2 != 0 ||
                                                                  (lVar2 = SAVE_IsIntroDeadDead(intro), lVar2 != 0))))
  {
    intro->flags = intro->flags | 8;
    lVar4 = 1;
  }
  return lVar4;
}

INICommand *INSTANCE_GetIntroCommand(INICommand *command, int cmd)

{
  if (command != (INICommand *)0x0)
  {
    while (command->command != 0)
    {
      if ((int)command->command == cmd)
      {
        return command;
      }
      command = command + (int)command->numParameters + 1;
    }
  }
  return (INICommand *)0x0;
}

INICommand *INSTANCE_FindWithID(_Instance *instance, int cmd)

{
  INICommand *pIVar1;

  pIVar1 = INSTANCE_GetIntroCommand((INICommand *)instance->introData, cmd);
  return pIVar1;
}

void MON_ProcessIntro(_Instance *instance)

{
  short sVar1;
  short sVar2;
  short *psVar3;

  psVar3 = (short *)instance->introData;
  if ((psVar3 != (short *)0x0) && ((instance->flags & 2U) == 0))
  {
    sVar1 = *psVar3;
    sVar2 = *psVar3;
    while (sVar1 != 0)
    {
      if (sVar2 == 0x12)
      {
        instance->currentModel = psVar3[2];
      }
      psVar3 = psVar3 + (int)psVar3[1] * 2 + 2;
      sVar1 = *psVar3;
      sVar2 = *psVar3;
    }
  }
  return;
}

void INSTANCE_InitEffects(_Instance *instance, Object *object)

{
  int iVar1;
  int iVar2;

  if ((((object->oflags2 & 0x100U) == 0) && (object->numberOfEffects != 0)) &&
      (iVar2 = 0, 0 < object->numberOfEffects))
  {
    iVar1 = 0;
    do
    {
      FX_StartInstanceEffect(instance, (ObjectEffect *)(&object->effectList->effectNumber + iVar1), 1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (iVar2 < object->numberOfEffects);
  }
  return;
}

_Instance *INSTANCE_InsertInstanceGroup(Intro *intro, short streamUnitID)

{
  byte bVar1;
  short frameNum;
  long lVar2;
  INICommand *pIVar3;
  _ObjectTracker *objectTracker;
  _Instance *instance;
  MultiSpline *pMVar4;
  SavedIntroSpline *pSVar5;
  SavedIntroSmall *pSVar6;
  int Data;
  u_int uVar7;
  Spline *pSVar8;
  RSpline *pRVar9;
  u_char uVar10;
  INICommand introUniqueID;
  _Instance *instance_00;
  Object *object;

  instance_00 = (_Instance *)0x0;
  lVar2 = INSTANCE_GetIntroCommand(intro, streamUnitID);
  if (lVar2 != 0)
  {
    return (_Instance *)0x0;
  }
  introUniqueID = (INICommand)0x0;
  pIVar3 = INSTANCE_GetIntroCommand((INICommand *)intro->data, 0x1a);
  if (pIVar3 != (INICommand *)0x0)
  {
    introUniqueID = pIVar3[1];
  }
  objectTracker = STREAM_GetObjectTracker((char *)intro);
  if (objectTracker == (_ObjectTracker *)0x0)
  {
    return (_Instance *)0x0;
  }
  object = objectTracker->object;
  lVar2 = MEMPACK_ReportMemory((char *)object);
  if (lVar2 == 0)
  {
    return (_Instance *)0x0;
  }
  if ((introUniqueID != (INICommand)0x0) &&
      (instance_00 = INSTANCE_Deactivate((long)introUniqueID), instance_00 == (_Instance *)0x0))
  {
    return (_Instance *)0x0;
  }
  if (((object->oflags2 & 0x10000000U) != 0) &&
      (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) != 0))
  {
    return (_Instance *)0x0;
  }
  instance = INSTANCE_CleanUpInstanceList(gameTrackerX.instanceList);
  if (instance == (_Instance *)0x0)
  {
    return (_Instance *)0x0;
  }
  intro->flags = intro->flags | 8;
  objectTracker->numInUse = objectTracker->numInUse + 1;
  INSTANCE_DefaultAnimCallback(instance, object, 0);
  strcmp(instance->introName, (char *)intro);
  instance->introUniqueID = intro->UniqueID;
  lVar2 = intro->intronum;
  instance->birthStreamUnitID = (int)streamUnitID;
  instance->currentStreamUnitID = (int)streamUnitID;
  instance->introNum = lVar2;
  intro->instance = instance;
  instance->intro = intro;
  instance->introData = intro->data;
  frameNum = (intro->position).z;
  *(u_char *)&instance->position = *(u_char *)&intro->position;
  (instance->position).z = frameNum;
  if ((gameTrackerX.gameData.asmData.MorphType == 1) &&
      ((*(int *)&intro->spectralPosition != 0 || ((intro->spectralPosition).z != 0))))
  {
    (instance->position).x = (intro->position).x + (intro->spectralPosition).x;
    (instance->position).y = (intro->position).y + (intro->spectralPosition).y;
    (instance->position).z = (intro->position).z + (intro->spectralPosition).z;
  }
  frameNum = (instance->position).z;
  *(u_char *)&instance->initialPos = *(u_char *)&instance->position;
  (instance->initialPos).z = frameNum;
  frameNum = (intro->position).z;
  *(u_char *)&instance->oldPos = *(u_char *)&intro->position;
  (instance->oldPos).z = frameNum;
  *(INICommand *)&instance->attachedID = introUniqueID;
  LIGHT_GetAmbient((_ColorType *)&instance->light_color, instance);
  uVar10 = *(u_char *)&(intro->rotation).z;
  *(u_char *)&instance->rotation = *(u_char *)&intro->rotation;
  *(u_char *)&(instance->rotation).z = uVar10;
  if ((instance->object->oflags & 0x100U) != 0)
  {
    INSTANCE_BuildStaticShadow(instance);
  }
  (instance->scale).x = 0x1000;
  (instance->scale).y = 0x1000;
  (instance->scale).z = 0x1000;
  if ((intro->flags & 0x2000U) != 0)
  {
    instance->flags = instance->flags | 0x400;
  }
  if ((intro->flags & 0x10000U) != 0)
  {
    instance->flags2 = instance->flags2 | 0x20000;
  }
  if (instance_00 != (_Instance *)0x0)
  {
    INSTANCE_ForceActive(instance_00);
    instance_00->flags2 = instance_00->flags2 | 0x80;
  }
  if ((object->oflags2 & 0x80U) != 0)
  {
    instance->flags = instance->flags | 0x800;
  }
  if (((intro->flags & 0x800U) != 0) && (object->id == -1))
  {
    frameNum = SCRIPTCountFramesInSpline(instance);
    SCRIPT_InstanceSplineProcess(instance, frameNum, (SplineDef *)0x0, (SplineDef *)0x0, (SplineDef *)0x0);
    instance->flags = instance->flags ^ 0x1000000U | 0x100000;
  }
  instance->lightGroup = *(u_char *)&(intro->rotation).pad;
  instance->spectralLightGroup = *(u_char *)&intro->specturalLightGroup;
  INSTANCE_IntroduceInstance(gameTrackerX.instanceList, instance);
  OBTABLE_GetInstanceCollideFunc(instance);
  OBTABLE_GetInstanceProcessFunc(instance);
  OBTABLE_GetInstanceMessageFunc(instance);
  OBTABLE_GetInstanceQueryFunc(instance);
  OBTABLE_GetInstanceAdditionalCollideFunc(instance);
  if ((intro->flags & 0x10U) == 0)
  {
    OBTABLE_InstanceInit(instance);
  }
  MORPH_SetupInstanceListFlags(&gameTrackerX, instance);
  if ((intro->flags & 0x80U) != 0)
  {
    uVar7 = instance->flags2;
    instance->flags = instance->flags | 0x800;
    instance->flags2 = uVar7 | 0x20000000;
    if ((object->oflags2 & 0x80000U) != 0)
    {
      instance->flags2 = uVar7 | 0x30000000;
    }
  }
  pMVar4 = SCRIPT_GetMultiSpline(instance, (u_long *)0x0, (u_long *)0x0);
  if (pMVar4 == (MultiSpline *)0x0)
  {
    instance->flags = instance->flags & 0xfdffffffU | 0x100000;
  }
  else
  {
    pMVar4 = SCRIPT_GetMultiSpline(instance, (u_long *)0x0, (u_long *)0x0);
    pSVar5 = SAVE_GetIntroSpline(instance);
    if (pSVar5 != (SavedIntroSpline *)0x0)
    {
      SCRIPT_InstanceSplineProcess(instance, pSVar5->splineKeyFrame, (SplineDef *)0x0, (SplineDef *)0x0, (SplineDef *)0x0);
      frameNum = (instance->position).z;
      *(u_char *)&instance->oldPos = *(u_char *)&instance->position;
      (instance->oldPos).z = frameNum;
      instance->splineFlags = pSVar5->splineFlags;
      instance->clipBeg = pSVar5->splineClipBeg;
      instance->clipEnd = pSVar5->splineClipEnd;
      if ((instance->splineFlags & 0x80U) != 0)
      {
        instance->flags = instance->flags | 0x1000000;
      }
      if ((instance->splineFlags & 0x100U) != 0)
      {
        instance->flags = instance->flags | 0x2000000;
      }
      if ((pSVar5->splineFlags & 0x10U) == 0)
      {
        if ((instance->splineFlags & 0x20U) == 0)
        {
          if ((instance->splineFlags & 0x40U) == 0)
            goto LAB_80032f08;
          pSVar8 = pMVar4->positional;
          if (pSVar8 != (Spline *)0x0)
          {
            pSVar8->flags = pSVar8->flags | 4;
          }
          pRVar9 = pMVar4->rotational;
          if (pRVar9 != (RSpline *)0x0)
          {
            pRVar9->flags = pRVar9->flags | 4;
          }
          pSVar8 = pMVar4->scaling;
          if (pSVar8 != (Spline *)0x0)
          {
            pSVar8->flags = pSVar8->flags | 4;
          }
          pSVar8 = pMVar4->color;
          if (pSVar8 == (Spline *)0x0)
            goto LAB_80032f08;
          bVar1 = pSVar8->flags | 4;
        }
        else
        {
          pSVar8 = pMVar4->positional;
          if (pSVar8 != (Spline *)0x0)
          {
            pSVar8->flags = pSVar8->flags | 2;
          }
          pRVar9 = pMVar4->rotational;
          if (pRVar9 != (RSpline *)0x0)
          {
            pRVar9->flags = pRVar9->flags | 2;
          }
          pSVar8 = pMVar4->scaling;
          if (pSVar8 != (Spline *)0x0)
          {
            pSVar8->flags = pSVar8->flags | 2;
          }
          pSVar8 = pMVar4->color;
          if (pSVar8 == (Spline *)0x0)
            goto LAB_80032f08;
          bVar1 = pSVar8->flags | 2;
        }
      }
      else
      {
        pSVar8 = pMVar4->positional;
        if (pSVar8 != (Spline *)0x0)
        {
          pSVar8->flags = pSVar8->flags | 1;
        }
        pRVar9 = pMVar4->rotational;
        if (pRVar9 != (RSpline *)0x0)
        {
          pRVar9->flags = pRVar9->flags | 1;
        }
        pSVar8 = pMVar4->scaling;
        if (pSVar8 != (Spline *)0x0)
        {
          pSVar8->flags = pSVar8->flags | 1;
        }
        pSVar8 = pMVar4->color;
        if (pSVar8 == (Spline *)0x0)
          goto LAB_80032f08;
        bVar1 = pSVar8->flags | 1;
      }
      pSVar8->flags = bVar1;
    }
  }
LAB_80032f08:
  EVENT_AddInstanceToInstanceList(instance);
  MON_ProcessIntro(instance);
  INSTANCE_InitEffects(instance, object);
  pSVar6 = SAVE_GetSavedSmallIntro(instance);
  if (pSVar6 != (SavedIntroSmall *)0x0)
  {
    Data = SetControlSaveDataData((u_int)pSVar6->shiftedSaveSize * 4 + -4, pSVar6 + 1);
    INSTANCE_Query(instance, (int)&DAT_00100007, Data);
  }
  return instance;
}

void INSTANCE_AdditionalCollideFunctions(_InstanceList *instanceList)

{
  _Instance *p_Var1;

  p_Var1 = instanceList->first;
  while (p_Var1 != (_Instance *)0x0)
  {
    if ((((gameTrackerX.gameMode != 6) || ((p_Var1->object->oflags & 0x20000U) != 0)) &&
         (((gameTrackerX.streamFlags & 0x100000U) == 0 || ((p_Var1->object->oflags & 0x40000U) != 0)))) &&
        ((p_Var1->additionalCollideFunc != (_func_3 *)0x0 &&
          ((p_Var1->flags2 & 0x24000000U) == 0))))
    {
      gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
      if ((p_Var1->object != (Object *)0x0) &&
          (((p_Var1->object->oflags2 & 0x2000000U) != 0 &&
            (gameTrackerX.timeMult = gameTrackerX.materialTimeMult, (p_Var1->flags2 & 0x8000000U) != 0))))
      {
        gameTrackerX.timeMult = gameTrackerX.spectralTimeMult;
      }
      (*p_Var1->additionalCollideFunc)(p_Var1, &gameTrackerX);
    }
    p_Var1 = p_Var1->next;
  }
  gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
  return;
}

long SplineGetFrameNumber(_Instance *instance, MultiSpline *spline)

{
  SplineDef *splineDef;
  int iVar1;

  splineDef = SCRIPT_GetPosSplineDef(instance, spline, 0, 0);
  iVar1 = EVENT_GetSplineFrameNumber(instance, splineDef);
  return iVar1;
}

void INSTANCE_ProcessFunctions(_InstanceList *instanceList)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  bool bVar5;
  short frameNum;
  u_long uVar6;
  MultiSpline *multi;
  long lVar7;
  long lVar8;
  long lVar9;
  Spline *pSVar10;
  int iVar11;
  _Instance *Inst;
  u_int hidden;
  int iVar12;
  u_short uVar13;

  if ((gameTrackerX.debugFlags & 0x8000010U) == 0)
  {
    Inst = instanceList->first;
    while (Inst != (_Instance *)0x0)
    {
      gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
      if (((Inst->object != (Object *)0x0) && ((Inst->object->oflags2 & 0x2000000U) != 0)) &&
          (gameTrackerX.timeMult = gameTrackerX.materialTimeMult, (Inst->flags2 & 0x8000000U) != 0))
      {
        gameTrackerX.timeMult = gameTrackerX.spectralTimeMult;
      }
      if ((Inst->object->oflags2 & 4U) != 0)
      {
        hidden = Inst->flags & 0x800;
        uVar6 = INSTANCE_Post(Inst, 2);
        if (((uVar6 & 0x20) != 0) && (uVar6 = INSTANCE_Post(Inst, 3), (uVar6 & 0x10000) == 0))
        {
          hidden = 1;
        }
        SOUND_StartInstanceSound(Inst->object->soundData, Inst->soundInstanceTbl, &Inst->position,
                                 Inst->object->oflags2 & 0x2000000, Inst->flags2 & 0x8000000, hidden, &Inst->flags2);
      }
      if ((((Inst->intro == (Intro *)0x0) || ((Inst->intro->flags & 0x100U) == 0)) &&
           ((gameTrackerX.gameMode != 6 || ((Inst->object->oflags & 0x20000U) != 0)))) &&
          ((((gameTrackerX.streamFlags & 0x100000U) == 0 || ((Inst->object->oflags & 0x40000U) != 0)) && ((Inst->flags2 & 0x10000000U) == 0))))
      {
        frameNum = (Inst->position).y;
        sVar1 = (Inst->position).z;
        sVar2 = (Inst->rotation).x;
        sVar3 = (Inst->rotation).y;
        hidden = Inst->flags;
        sVar4 = (Inst->rotation).z;
        (Inst->oldPos).x = (Inst->position).x;
        (Inst->oldPos).y = frameNum;
        (Inst->oldPos).z = sVar1;
        (Inst->oldRotation).x = sVar2;
        (Inst->oldRotation).y = sVar3;
        (Inst->oldRotation).z = sVar4;
        if ((((hidden & 0x100000) == 0) &&
             (multi = SCRIPT_GetMultiSpline(Inst, (u_long *)0x0, (u_long *)0x0),
              multi != (MultiSpline *)0x0)) &&
            (hidden = Inst->flags, (hidden & 0x2000000) != 0))
        {
          uVar13 = 1;
          if ((hidden & 0x1000000) != 0)
          {
            uVar13 = 0xffff;
          }
          if ((Inst->object->oflags & 0x10000000U) != 0)
          {
            Inst->flags = hidden | 0x400;
            frameNum = SplineMultiIsWhere(multi);
            if (frameNum != 0)
            {
              if ((int)((u_int)uVar13 << 0x10) < 1)
              {
                Inst->intro->flags = Inst->intro->flags & 0xfffff7ff;
              }
              else
              {
                Inst->intro->flags = Inst->intro->flags | 0x800;
              }
            }
          }
          lVar7 = SplineGetFrameNumber(Inst, multi);
          lVar8 = SCRIPT_InstanceSplineSet(Inst, &multi->curPositional, &multi->curRotational, &multi->curScaling,
                                           (int)(short)uVar13);
          if (Inst->splineFlags == 0)
          {
            if ((gameTrackerX.debugFlags2 & 0x400000U) != 0)
            {
              SplineGetFrameNumber(Inst, multi);
              FONT_Print("Spline %s%d prevFrame=%d, frame=%d\n");
            }
          }
          else
          {
            lVar9 = SplineGetFrameNumber(Inst, multi);
            frameNum = SCRIPTCountFramesInSpline(Inst);
            iVar12 = (int)frameNum;
            if ((Inst->splineFlags & 1U) != 0)
            {
              if ((gameTrackerX.debugFlags2 & 0x400000U) != 0)
              {
                printf(
                    "Spline %s%ld playto %d preveFram=%ld frame=%ld endOfSpline=%ld, maxFrames=%ld\n");
              }
              if ((int)(short)uVar13 < 1)
              {
                iVar11 = (int)Inst->targetFrame;
                if (lVar9 <= iVar11)
                {
                  if (iVar11 <= lVar7)
                    goto LAB_800334d8;
                  if (lVar7 < lVar9)
                  {
                    bVar5 = lVar7 + iVar12 < iVar11;
                    goto LAB_800334d0;
                  }
                }
              }
              else
              {
                if (iVar12 < lVar7)
                {
                  lVar7 = iVar12;
                }
                iVar11 = (int)Inst->targetFrame;
                if ((lVar9 < iVar11) || (iVar11 < lVar7))
                {
                  if ((lVar9 < lVar7) && (lVar9 >= iVar11))
                  {
                    bVar5 = iVar11 + iVar12 < lVar7;
                  LAB_800334d0:
                    if (!bVar5)
                      goto LAB_800334d8;
                  }
                }
                else
                {
                LAB_800334d8:
                  Inst->flags = Inst->flags & 0xfdffffff;
                  SCRIPT_InstanceSplineProcess(Inst, Inst->targetFrame, (SplineDef *)0x0, (SplineDef *)0x0,
                                               (SplineDef *)0x0);
                  lVar8 = 0;
                  Inst->splineFlags = Inst->splineFlags & 0xfffe;
                }
              }
            }
            if ((Inst->splineFlags & 2U) != 0)
            {
              if ((gameTrackerX.debugFlags2 & 0x400000U) != 0)
              {
                FONT_Print("Spline %s%d : clip(%d,%d) prevFrame=%d, frame=%d\n");
              }
              if (uVar13 == 1)
              {
                if (((lVar7 <= Inst->clipEnd) && (Inst->clipEnd <= lVar9)) ||
                    (lVar9 < Inst->clipBeg))
                {
                  if ((*(u_int *)&multi->positional->numkeys & 0x6000000) == 0)
                  {
                    frameNum = Inst->clipEnd;
                  LAB_80033640:
                    lVar8 = 1;
                  }
                  else
                  {
                    frameNum = Inst->clipBeg;
                  }
                LAB_80033644:
                  SCRIPT_InstanceSplineProcess(Inst, frameNum, (SplineDef *)0x0, (SplineDef *)0x0, (SplineDef *)0x0);
                }
              }
              else
              {
                if (((Inst->clipBeg <= lVar7) && (lVar9 <= Inst->clipBeg)) ||
                    (Inst->clipEnd < lVar9))
                {
                  if ((*(u_int *)&multi->positional->numkeys & 0x6000000) == 0)
                  {
                    frameNum = Inst->clipBeg;
                    goto LAB_80033640;
                  }
                  frameNum = Inst->clipEnd;
                  goto LAB_80033644;
                }
              }
            }
          }
          if (0 < lVar8)
          {
            if ((Inst->object->oflags & 0x10000000U) != 0)
            {
              Inst->flags = Inst->flags & 0xfdfffbffU | 0x100000;
            }
            hidden = Inst->object->oflags;
            if ((hidden & 0x2000) != 0)
            {
              Inst->flags = Inst->flags | 0x100000;
              INSTANCE_NewInstance(Inst);
              goto LAB_8003388c;
            }
            if ((hidden & 0x1000) == 0)
            {
              if ((hidden & 0x1000000) != 0)
              {
                Inst->flags = Inst->flags & 0xfdffffff;
              }
            }
            else
            {
              Inst->flags = Inst->flags & 0xfdffffff;
              if ((Inst->object->oflags & 0x800000U) != 0)
              {
                SCRIPT_InstanceSplineInit(Inst);
              }
            }
            pSVar10 = multi->positional;
            if (((pSVar10 != (Spline *)0x0) ||
                 (pSVar10 = (Spline *)multi->rotational, pSVar10 != (Spline *)0x0)) &&
                (((pSVar10->flags & 4) == 0 && ((Inst->object->oflags & 0x800000U) == 0))))
            {
              Inst->flags = Inst->flags ^ 0x1000000;
            }
            if ((((Inst->object->oflags & 0x200000U) != 0) && ((int *)Inst->introData != (int *)0x0)) && (iVar12 = *(int *)Inst->introData, iVar12 != 0))
            {
              SIGNAL_HandleFogNear(Inst, (Signal *)(iVar12 + 8), 0);
            }
          }
        }
        if (Inst->processFunc != (_func_1 *)0x0)
        {
          if ((Inst->flags2 & 1U) == 0)
          {
            (*Inst->processFunc)(Inst, &gameTrackerX);
          }
          else
          {
            INSTANCE_DeactivateFarInstances(Inst, &gameTrackerX);
          }
        }
        iVar12 = (int)(Inst->position).z - (int)(Inst->oldPos).z;
        if (0x8000 < iVar12)
        {
          INSTANCE_PlainDeath(Inst);
        }
        if (iVar12 < -0x8000)
        {
          INSTANCE_PlainDeath(Inst);
        }
      }
    LAB_8003388c:
      Inst = Inst->next;
    }
  }
  gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
  return;
}

_Instance *INSTANCE_BirthObject(_Instance *parent, Object *object, int modelNum)

{
  short sVar1;
  _GlobalSaveTracker *p_Var2;
  _Instance *instance;
  size_t sVar3;
  MultiSpline *pMVar4;
  int iVar5;
  u_char uVar6;
  int iVar7;

  if ((object == (Object *)0x0) ||
      (instance = INSTANCE_CleanUpInstanceList(gameTrackerX.instanceList),
       instance == (_Instance *)0x0))
  {
    instance = (_Instance *)0x0;
  }
  else
  {
    INSTANCE_DefaultAnimCallback(instance, object, modelNum);
    sVar1 = (parent->position).z;
    *(u_char *)&instance->position = *(u_char *)&parent->position;
    (instance->position).z = sVar1;
    sVar1 = (instance->position).z;
    *(u_char *)&instance->initialPos = *(u_char *)&instance->position;
    (instance->initialPos).z = sVar1;
    sVar1 = (parent->position).z;
    *(u_char *)&instance->oldPos = *(u_char *)&parent->position;
    (instance->oldPos).z = sVar1;
    uVar6 = *(u_char *)&(parent->rotation).z;
    *(u_char *)&instance->rotation = *(u_char *)&parent->rotation;
    *(u_char *)&(instance->rotation).z = uVar6;
    uVar6 = *(u_char *)&(parent->scale).z;
    *(u_char *)&instance->scale = *(u_char *)&parent->scale;
    *(u_char *)&(instance->scale).z = uVar6;
    instance->lightGroup = parent->lightGroup;
    instance->spectralLightGroup = parent->spectralLightGroup;
    p_Var2 = GlobalSave;
    instance->currentStreamUnitID = parent->currentStreamUnitID;
    instance->birthStreamUnitID = parent->birthStreamUnitID;
    sVar1 = p_Var2->CurrentBirthID;
    iVar7 = 0;
    p_Var2->CurrentBirthID = sVar1 + 1;
    instance->introUniqueID = (int)sVar1;
    strcmp(instance->introName, object->name);
    do
    {
      sVar3 = strlen(instance->introName);
      iVar5 = (int)&(instance->node).prev + iVar7;
      if ((int)sVar3 <= iVar7)
        goto LAB_80033a2c;
      iVar7 = iVar7 + 1;
    } while (*(char *)(iVar5 + 0x158) != '_');
    *(undefined *)(iVar5 + 0x158) = 0;
  LAB_80033a2c:
    instance->parent = parent;
    instance->intro = parent->intro;
    instance->introData = parent->introData;
    LIGHT_GetAmbient((_ColorType *)&instance->light_color, instance);
    if ((instance->object->oflags & 0x100U) != 0)
    {
      INSTANCE_BuildStaticShadow(instance);
    }
    pMVar4 = SCRIPT_GetMultiSpline(instance, (u_long *)0x0, (u_long *)0x0);
    if (pMVar4 == (MultiSpline *)0x0)
    {
      instance->flags = instance->flags | 0x100000;
    }
    if ((parent->flags2 & 0x8000000U) != 0)
    {
      instance->flags2 = instance->flags2 | 0x8000000;
    }
    INSTANCE_IntroduceInstance(gameTrackerX.instanceList, instance);
    OBTABLE_GetInstanceCollideFunc(instance);
    OBTABLE_GetInstanceProcessFunc(instance);
    OBTABLE_GetInstanceMessageFunc(instance);
    OBTABLE_GetInstanceQueryFunc(instance);
    OBTABLE_GetInstanceAdditionalCollideFunc(instance);
    instance->flags = instance->flags | 2;
    OBTABLE_InstanceInit(instance);
    EVENT_AddInstanceToInstanceList(instance);
    INSTANCE_InitEffects(instance, object);
  }
  return instance;
}

void INSTANCE_BuildStaticShadow(_Instance *instance)

{
  return;
}

void INSTANCE_DefaultAnimCallback(_Instance *instance, Object *object, int modelNum)

{
  void *pvVar1;
  _G2AnimKeylist_Type *keylist;
  _HFace **pp_Var2;
  _HSphere **pp_Var3;
  _HBox **pp_Var4;
  _HInfo *p_Var5;
  _Segment *p_Var6;
  int iVar7;
  _HPrim *p_Var8;
  undefined uVar9;
  int iVar10;
  _HFace *p_Var11;
  _HSphere *p_Var12;
  _HBox *p_Var13;
  int iVar14;
  int *piVar15;
  _Model **pp_Var16;
  _G2Anim_Type *anim;
  int iVar17;
  _Model *p_Var18;
  _HModel *p_Var19;

  memset(&instance->flags, 0, 0x284);
  instance->object = object;
  pvVar1 = object->data;
  instance->currentModel = (short)modelNum;
  instance->cachedTFace = -1;
  instance->data = pvVar1;
  if ((object->animList != (_G2AnimKeylist_Type **)0x0) && ((object->oflags2 & 0x40000000U) == 0))
  {
    anim = &instance->anim;
    _G2Anim_InitializeChannel_AdaptiveDelta(anim, object->modelList[modelNum]);
    keylist = G2Instance_GetKeylist(instance, 0);
    G2Anim_GetKeylist(anim, keylist, 0);
    MON_AnimCallback(anim, INSTANCE_DefaultAnimCallback, instance);
  }
  if ((object->oflags & 0x4000000U) != 0)
  {
    instance->flags2 = instance->flags2 | 4;
  }
  if ((object->oflags & 0x200U) != 0)
  {
    instance->flags2 = instance->flags2 | 0x40;
  }
  if ((object->oflags & 8U) != 0)
  {
    instance->flags2 = instance->flags2 | 0x8000000;
  }
  if ((object->oflags & 0x1000800U) == 0)
  {
    instance->flags = instance->flags | 0x2000000;
  }
  if ((object->oflags & 0x20000000U) != 0)
  {
    instance->flags2 = instance->flags2 | 0x20;
  }
  iVar17 = (int)object->numModels;
  pp_Var16 = object->modelList;
  iVar7 = 0;
  iVar14 = iVar17;
  while (iVar14 != 0)
  {
    iVar10 = (*pp_Var16)->numSegments;
    p_Var6 = (*pp_Var16)->segmentList;
    while (iVar10 != 0)
    {
      p_Var5 = p_Var6->hInfo;
      if (p_Var5 != (_HInfo *)0x0)
      {
        iVar7 = iVar7 + p_Var5->numHFaces + p_Var5->numHSpheres + p_Var5->numHBoxes;
      }
      iVar10 = iVar10 + -1;
      p_Var6 = p_Var6 + 1;
    }
    iVar14 = iVar14 + -1;
    pp_Var16 = pp_Var16 + 1;
  }
  if (iVar7 == 0)
  {
    instance->hModelList = (_HModel *)0x0;
    instance->flags2 = instance->flags2 | 0x40000;
  }
  else
  {
    p_Var19 = (_HModel *)MEMPACK_Malloc((instance->object->numModels + iVar7) * 8, '\x0e');
    instance->hModelList = p_Var19;
    pp_Var16 = object->modelList;
    p_Var8 = (_HPrim *)(p_Var19 + iVar17);
    if (iVar17 != 0)
    {
      piVar15 = &p_Var19->numHPrims;
      do
      {
        p_Var18 = *pp_Var16;
        *piVar15 = 0;
        p_Var19->hPrimList = p_Var8;
        p_Var6 = p_Var18->segmentList;
        iVar14 = 0;
        if (0 < p_Var18->numSegments)
        {
          do
          {
            p_Var5 = p_Var6->hInfo;
            if (p_Var5 != (_HInfo *)0x0)
            {
              p_Var11 = p_Var5->hfaceList;
              p_Var12 = p_Var5->hsphereList;
              p_Var13 = p_Var5->hboxList;
              *piVar15 = *piVar15 + p_Var5->numHFaces + p_Var5->numHSpheres + p_Var5->numHBoxes;
              iVar7 = p_Var5->numHFaces;
              pp_Var2 = (_HFace **)&p_Var8->data;
              uVar9 = (undefined)iVar14;
              while (iVar7 != 0)
              {
                p_Var8->hpFlags = 'M';
                *(undefined *)((int)pp_Var2 + -3) = 0x24;
                *(undefined *)((int)pp_Var2 + -2) = 2;
                *(undefined *)((int)pp_Var2 + -1) = uVar9;
                *pp_Var2 = p_Var11;
                pp_Var2 = pp_Var2 + 2;
                p_Var8 = p_Var8 + 1;
                iVar7 = iVar7 + -1;
                p_Var11 = p_Var11 + 1;
              }
              iVar7 = p_Var5->numHSpheres;
              pp_Var3 = (_HSphere **)&p_Var8->data;
              while (iVar7 != 0)
              {
                ';
                    *(undefined *)((int)pp_Var3 + -3) = 0x76;
                *(undefined *)((int)pp_Var3 + -2) = 1;
                *(undefined *)((int)pp_Var3 + -1) = uVar9;
                *pp_Var3 = p_Var12;
                pp_Var3 = pp_Var3 + 2;
                p_Var8 = p_Var8 + 1;
                iVar7 = iVar7 + -1;
                p_Var12 = p_Var12 + 1;
              }
              iVar7 = p_Var5->numHBoxes;
              pp_Var4 = (_HBox **)&p_Var8->data;
              while (iVar7 != 0)
              {
                p_Var8->hpFlags = '\x1d';
                *(undefined *)((int)pp_Var4 + -3) = 0x24;
                *(undefined *)((int)pp_Var4 + -2) = 5;
                *(undefined *)((int)pp_Var4 + -1) = uVar9;
                *pp_Var4 = p_Var13;
                pp_Var4 = pp_Var4 + 2;
                p_Var8 = p_Var8 + 1;
                iVar7 = iVar7 + -1;
                p_Var13 = p_Var13 + 1;
              }
            }
            iVar14 = iVar14 + 1;
            p_Var6 = p_Var6 + 1;
          } while (iVar14 < p_Var18->numSegments);
        }
        iVar17 = iVar17 + -1;
        pp_Var16 = pp_Var16 + 1;
        piVar15 = piVar15 + 2;
        p_Var19 = p_Var19 + 1;
      } while (iVar17 != 0);
    }
  }
  if (instance->maxCheckDistance == 0)
  {
    instance->maxCheckDistance = 12000;
  }
  return;
}

void INSTANCE_PlainDeath(_Instance *instance)

{
  u_int uVar1;
  _Instance *p_Var2;
  Object *pOVar3;

  pOVar3 = instance->object;
  instance->flags = instance->flags & 0xfffffbff;
  if ((pOVar3->oflags2 & 4U) != 0)
  {
    uVar1 = instance->flags2;
    instance->flags2 = uVar1 | 0x1000;
    SOUND_StartInstanceSound(pOVar3->soundData, instance->soundInstanceTbl, &instance->position,
                             pOVar3->oflags2 & 0x2000000, uVar1 & 0x8000000, 0, &instance->flags2);
    SOUND_StartInstanceSound(instance->object->soundData, instance->soundInstanceTbl, &instance->position,
                             instance->object->oflags2 & 0x2000000, instance->flags2 & 0x8000000, 0,
                             &instance->flags2);
  }
  p_Var2 = INSTANCE_Deactivate(instance->attachedID);
  if (p_Var2 != (_Instance *)0x0)
  {
    p_Var2->flags2 = p_Var2->flags2 & 0xffffff7f;
  }
  SAVE_MarkDeadDead(instance);
  instance->flags = instance->flags | 0x20;
  return;
}

void INSTANCE_NewInstance(_Instance *instance)

{
  if ((instance->flags & 0x20U) == 0)
  {
    INSTANCE_PlainDeath(instance);
  }
  return;
}

u_long INSTANCE_Post(_Instance *Inst, int Query)

{
  u_long uVar1;

  if (Inst->queryFunc == (_func_4 *)0x0)
  {
    uVar1 = 0;
  }
  else
  {
    uVar1 = (*Inst->queryFunc)();
  }
  return uVar1;
}

void INSTANCE_Query(_Instance *Inst, int Message, int Data)

{
  _func_5 *p_Var1;

  p_Var1 = Inst->messageFunc;
  if (p_Var1 != (_func_5 *)0x0)
  {
    INSTANCE_ForceActive(Inst);
    (*p_Var1)(Inst, Message, Data);
  }
  return;
}

void INSTANCE_Broadcast(_Instance *sender, long whatAmIMask, int Message, int Data)

{
  u_long uVar1;
  int iVar2;
  _Instance *Inst;
  int plane;

  Inst = (gameTrackerX.instanceList)->first;
  plane = (int)gameTrackerX.gameData.asmData.MorphType;
  while (Inst != (_Instance *)0x0)
  {
    if (((Inst != sender) && (uVar1 = INSTANCE_Post(Inst, 1), (uVar1 & whatAmIMask) != 0)) &&
        (iVar2 = INSTANCE_Introduced(Inst, plane), iVar2 != 0))
    {
      INSTANCE_Query(Inst, Message, Data);
    }
    Inst = Inst->next;
  }
  return;
}

int INSTANCE_Introduced(_Instance *instance, int plane)

{
  if (instance->object == (Object *)0x0)
  {
    return 0;
  }
  if ((instance->object->oflags2 & 0x2000000U) != 0)
  {
    if ((instance->flags2 & 0x8000000U) == 0)
    {
      if (plane != 0)
      {
        return 0;
      }
      return 1;
    }
    if (plane == 0)
    {
      return 0;
    }
  }
  return 1;
}

long INSTANCE_FindIntroCommand(long uniqueID)

{
  long *plVar1;
  _Instance *p_Var2;

  p_Var2 = (gameTrackerX.instanceList)->first;
  do
  {
    if (p_Var2 == (_Instance *)0x0)
    {
      return 0;
    }
    plVar1 = &p_Var2->introUniqueID;
    p_Var2 = p_Var2->next;
  } while (*plVar1 != uniqueID);
  return 1;
}

_Instance *INSTANCE_FindWithName(long areaID, char *instanceName, _Instance *startInstance)

{
  int iVar1;
  _Instance *p_Var2;
  _Instance *p_Var3;

  p_Var3 = (gameTrackerX.instanceList)->first;
  if (startInstance != (_Instance *)0x0)
  {
    p_Var3 = startInstance->next;
  }
  if (areaID == 0)
  {
    do
    {
      p_Var2 = p_Var3;
      if (p_Var2 == (_Instance *)0x0)
      {
        return (_Instance *)0x0;
      }
      p_Var3 = p_Var2->next;
      iVar1 = strcpy(p_Var2->introName, instanceName);
    } while (iVar1 != 0);
  }
  else
  {
    do
    {
      p_Var2 = p_Var3;
      if (p_Var2 == (_Instance *)0x0)
      {
        return (_Instance *)0x0;
      }
      p_Var3 = p_Var2->next;
    } while ((p_Var2->birthStreamUnitID != areaID) ||
             (iVar1 = strcpy(p_Var2->introName, instanceName), iVar1 != 0));
  }
  return p_Var2;
}

Intro *INSTANCE_FindIntro(long areaID, long introUniqueID)

{
  Level *pLVar1;
  Intro *pIVar2;
  int iVar3;

  pLVar1 = STREAM_GetWaterZLevel(areaID);
  if (pLVar1 != (Level *)0x0)
  {
    iVar3 = 0;
    if (0 < pLVar1->numIntros)
    {
      pIVar2 = pLVar1->introList;
      do
      {
        if (introUniqueID == pIVar2->UniqueID)
        {
          return pIVar2;
        }
        iVar3 = iVar3 + 1;
        pIVar2 = pIVar2 + 1;
      } while (iVar3 < pLVar1->numIntros);
    }
  }
  return (Intro *)0x0;
}

_Instance *INSTANCE_Deactivate(long introUniqueID)

{
  _Instance *p_Var1;

  p_Var1 = (gameTrackerX.instanceList)->first;
  while ((p_Var1 != (_Instance *)0x0 && (p_Var1->introUniqueID != introUniqueID)))
  {
    p_Var1 = p_Var1->next;
  }
  return p_Var1;
}

_Instance *INSTANCE_InstanceGroupNumber(_SavedIntro *savedIntro, _StreamUnit *streamUnit)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  BSPTree *pBVar5;
  long lVar6;
  _ObjectTracker *objectTracker;
  _Instance *instance;
  Level *pLVar7;
  u_int uVar8;
  Intro *pIVar9;
  Object *pOVar10;
  int Data;
  Intro *pIVar11;
  Intro *pIVar12;
  _Instance *instance_00;
  Object *object;
  u_char local_38;
  u_char local_34;
  undefined local_30;

  instance_00 = (_Instance *)0x0;
  pBVar5 = streamUnit->level->terrain->BSPTreeArray;
  lVar6 = INSTANCE_FindIntroCommand((int)savedIntro->introUniqueID);
  instance = (_Instance *)0x0;
  if (lVar6 == 0)
  {
    local_38 = *(u_char *)savedIntro->name;
    local_34 = *(u_char *)(savedIntro->name + 4);
    local_30 = 0;
    LOAD_SetSearchDirectory((int)savedIntro->birthUnitID);
    objectTracker = STREAM_GetObjectTracker((char *)&local_38);
    LOAD_SetSearchDirectory(0);
    instance = (_Instance *)0x0;
    if (objectTracker != (_ObjectTracker *)0x0)
    {
      object = objectTracker->object;
      lVar6 = MEMPACK_ReportMemory((char *)object);
      if ((lVar6 == 0) ||
          ((savedIntro->attachedUniqueID != 0 &&
            (instance_00 = INSTANCE_Deactivate((u_int)savedIntro->attachedUniqueID),
             instance_00 == (_Instance *)0x0))))
      {
        SAVE_BufferIntro((SavedBasic *)savedIntro);
        instance = (_Instance *)0x0;
      }
      else
      {
        if (((object->oflags2 & 0x10000000U) != 0) &&
            (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) != 0))
        {
          return (_Instance *)0x0;
        }
        instance = INSTANCE_CleanUpInstanceList(gameTrackerX.instanceList);
        if (instance != (_Instance *)0x0)
        {
          objectTracker->numInUse = objectTracker->numInUse + 1;
          INSTANCE_DefaultAnimCallback(instance, object, 0);
          strcmp(instance->introName, (char *)&local_38);
          instance->introUniqueID = (int)savedIntro->introUniqueID;
          instance->currentStreamUnitID = (int)savedIntro->streamUnitID;
          instance->birthStreamUnitID = (int)savedIntro->birthUnitID;
          LIGHT_GetAmbient((_ColorType *)&instance->light_color, instance);
          pIVar11 = (Intro *)0x0;
          pLVar7 = STREAM_GetWaterZLevel(instance->birthStreamUnitID);
          pIVar12 = pIVar11;
          if (pLVar7 != (Level *)0x0)
          {
            Data = pLVar7->terrain->numIntros;
            pIVar9 = pLVar7->terrain->introList;
            if (Data != 0)
            {
              do
              {
                Data = Data + -1;
                pIVar12 = pIVar9;
                if (pIVar9->UniqueID == instance->introUniqueID)
                  break;
                pIVar9 = pIVar9 + 1;
                pIVar12 = pIVar11;
              } while (Data != 0);
            }
          }
          if (pIVar12 == (Intro *)0x0)
          {
            instance->intro = (Intro *)0x0;
            instance->introData = (void *)0x0;
          }
          else
          {
            instance->intro = pIVar12;
            instance->introData = pIVar12->data;
          }
          sVar1 = (savedIntro->position).y;
          sVar2 = (savedIntro->position).z;
          sVar3 = (pBVar5->globalOffset).y;
          sVar4 = (pBVar5->globalOffset).z;
          (instance->position).x = (savedIntro->position).x + (pBVar5->globalOffset).x;
          (instance->position).y = sVar1 + sVar3;
          (instance->position).z = sVar2 + sVar4;
          sVar1 = (instance->position).z;
          *(u_char *)&instance->initialPos = *(u_char *)&instance->position;
          (instance->initialPos).z = sVar1;
          sVar1 = (instance->position).z;
          *(u_char *)&instance->oldPos = *(u_char *)&instance->position;
          (instance->oldPos).z = sVar1;
          pOVar10 = instance->object;
          (instance->rotation).x = (savedIntro->smallRotation).x;
          (instance->rotation).y = (savedIntro->smallRotation).y;
          (instance->rotation).z = (savedIntro->smallRotation).z;
          if ((pOVar10->oflags & 0x100U) != 0)
          {
            INSTANCE_BuildStaticShadow(instance);
          }
          (instance->scale).x = 0x1000;
          (instance->scale).y = 0x1000;
          (instance->scale).z = 0x1000;
          instance->lightGroup = savedIntro->lightGroup;
          instance->spectralLightGroup = savedIntro->specturalLightGroup;
          INSTANCE_IntroduceInstance(gameTrackerX.instanceList, instance);
          OBTABLE_GetInstanceCollideFunc(instance);
          OBTABLE_GetInstanceProcessFunc(instance);
          OBTABLE_GetInstanceMessageFunc(instance);
          OBTABLE_GetInstanceQueryFunc(instance);
          OBTABLE_GetInstanceAdditionalCollideFunc(instance);
          OBTABLE_InstanceInit(instance);
          instance->flags = savedIntro->flags;
          instance->flags2 = savedIntro->flags2 & 0xfffffffe;
          if (instance_00 != (_Instance *)0x0)
          {
            INSTANCE_ForceActive(instance_00);
            instance_00->flags2 = instance_00->flags2 | 0x80;
          }
          if ((instance->flags & 0x40000U) == 0)
          {
            uVar8 = instance->flags2 & 0xdfffffff;
          }
          else
          {
            uVar8 = instance->flags2 | 0x20000000;
          }
          instance->flags2 = uVar8;
          instance->flags = instance->flags & 0xfdfbffffU | 0x100000;
          MORPH_SetupInstanceListFlags(&gameTrackerX, instance);
          if (instance->intro != (Intro *)0x0)
          {
            MON_ProcessIntro(instance);
          }
          uVar8 = (u_int)savedIntro->shiftedSaveSize * 4;
          if (0x28 < uVar8)
          {
            Data = SetControlSaveDataData(uVar8 - 0x28, savedIntro + 1);
            INSTANCE_Query(instance, (int)&DAT_00100007, Data);
          }
          EVENT_AddInstanceToInstanceList(instance);
          INSTANCE_InitEffects(instance, object);
        }
      }
    }
  }
  return instance;
}

_Instance *
INSTANCE_IntroduceSavedInstanceWithIntro(_SavedIntroWithIntro *savedIntro, _StreamUnit *streamUnit)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  long lVar5;
  _ObjectTracker *objectTracker;
  _Instance *instance;
  MultiSpline *pMVar6;
  int Data;
  BSPTree *pBVar7;
  Object *pOVar8;
  u_int uVar9;
  u_int uVar10;
  Intro *name;
  _Instance *instance_00;
  Object *object;

  instance_00 = (_Instance *)0x0;
  pBVar7 = streamUnit->level->terrain->BSPTreeArray;
  name = streamUnit->level->introList + savedIntro->introOffset;
  lVar5 = INSTANCE_FindIntroCommand(name->UniqueID);
  instance = (_Instance *)0x0;
  if (lVar5 == 0)
  {
    LOAD_SetSearchDirectory(streamUnit->StreamUnitID);
    objectTracker = STREAM_GetObjectTracker((char *)name);
    LOAD_SetSearchDirectory(0);
    instance = (_Instance *)0x0;
    if (objectTracker != (_ObjectTracker *)0x0)
    {
      object = objectTracker->object;
      lVar5 = MEMPACK_ReportMemory((char *)object);
      if ((lVar5 == 0) ||
          ((savedIntro->attachedUniqueID != 0 &&
            ((instance_00 = INSTANCE_Deactivate((u_int)savedIntro->attachedUniqueID),
              instance_00 == (_Instance *)0x0 || (instance_00->matrix == (MATRIX *)0x0))))))
      {
        SAVE_BufferIntro((SavedBasic *)savedIntro);
        instance = (_Instance *)0x0;
      }
      else
      {
        if (((object->oflags2 & 0x10000000U) != 0) &&
            (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) != 0))
        {
          return (_Instance *)0x0;
        }
        instance = INSTANCE_CleanUpInstanceList(gameTrackerX.instanceList);
        if (instance != (_Instance *)0x0)
        {
          objectTracker->numInUse = objectTracker->numInUse + 1;
          INSTANCE_DefaultAnimCallback(instance, object, 0);
          strcmp(instance->introName, (char *)name);
          instance->introUniqueID = name->UniqueID;
          instance->introNum = name->intronum;
          instance->birthStreamUnitID = streamUnit->StreamUnitID;
          instance->currentStreamUnitID = streamUnit->StreamUnitID;
          instance->attachedID = (u_int)savedIntro->attachedUniqueID;
          LIGHT_GetAmbient((_ColorType *)&instance->light_color, instance);
          name->instance = instance;
          STREAM_GetWaterZLevel(instance->birthStreamUnitID);
          instance->intro = name;
          instance->introData = name->data;
          sVar1 = (savedIntro->position).y;
          sVar2 = (savedIntro->position).z;
          sVar3 = (pBVar7->globalOffset).y;
          sVar4 = (pBVar7->globalOffset).z;
          (instance->position).x = (savedIntro->position).x + (pBVar7->globalOffset).x;
          (instance->position).y = sVar1 + sVar3;
          (instance->position).z = sVar2 + sVar4;
          sVar1 = (instance->position).z;
          *(u_char *)&instance->initialPos = *(u_char *)&instance->position;
          (instance->initialPos).z = sVar1;
          sVar1 = (instance->position).z;
          *(u_char *)&instance->oldPos = *(u_char *)&instance->position;
          (instance->oldPos).z = sVar1;
          pOVar8 = instance->object;
          (instance->rotation).x = (savedIntro->smallRotation).x;
          (instance->rotation).y = (savedIntro->smallRotation).y;
          (instance->rotation).z = (savedIntro->smallRotation).z;
          if ((pOVar8->oflags & 0x100U) != 0)
          {
            INSTANCE_BuildStaticShadow(instance);
          }
          (instance->scale).x = 0x1000;
          (instance->scale).y = 0x1000;
          (instance->scale).z = 0x1000;
          instance->lightGroup = savedIntro->lightGroup;
          instance->spectralLightGroup = savedIntro->specturalLightGroup;
          INSTANCE_IntroduceInstance(gameTrackerX.instanceList, instance);
          OBTABLE_GetInstanceCollideFunc(instance);
          OBTABLE_GetInstanceProcessFunc(instance);
          OBTABLE_GetInstanceMessageFunc(instance);
          OBTABLE_GetInstanceQueryFunc(instance);
          OBTABLE_GetInstanceAdditionalCollideFunc(instance);
          OBTABLE_InstanceInit(instance);
          instance->flags = savedIntro->flags;
          instance->flags2 = savedIntro->flags2;
          if (instance_00 != (_Instance *)0x0)
          {
            INSTANCE_ForceActive(instance_00);
            instance_00->flags2 = instance_00->flags2 | 0x80;
          }
          uVar9 = instance->flags2;
          uVar10 = uVar9 & 0xfffffffe;
          instance->flags2 = uVar10;
          if ((instance->flags & 0x40000U) == 0)
          {
            uVar10 = uVar9 & 0xdffffffe;
          }
          else
          {
            uVar10 = uVar10 | 0x20000000;
          }
          instance->flags2 = uVar10;
          instance->flags = instance->flags & 0xfffbffff;
          pMVar6 = SCRIPT_GetMultiSpline(instance, (u_long *)0x0, (u_long *)0x0);
          if (pMVar6 == (MultiSpline *)0x0)
          {
            instance->flags = instance->flags & 0xfdffffffU | 0x100000;
          }
          MORPH_SetupInstanceListFlags(&gameTrackerX, instance);
          if (instance->intro != (Intro *)0x0)
          {
            MON_ProcessIntro(instance);
          }
          uVar10 = (u_int)savedIntro->shiftedSaveSize * 4;
          if (0x20 < uVar10)
          {
            Data = SetControlSaveDataData(uVar10 - 0x20, savedIntro + 1);
            INSTANCE_Query(instance, (int)&DAT_00100007, Data);
          }
          EVENT_AddInstanceToInstanceList(instance);
          INSTANCE_InitEffects(instance, object);
        }
      }
    }
  }
  return instance;
}

void INSTANCE_SpatialRelationships(_InstanceList *instanceList)

{
  u_char *puVar1;
  u_long uVar2;
  int iVar3;
  MATRIX *pMVar4;
  _Instance *Inst;
  _Instance *Inst_00;
  u_int uVar5;
  MATRIX MStack80;
  evCollideInstanceStatsData eStack48;

  Inst_00 = instanceList->first;
  while (Inst_00 != (_Instance *)0x0)
  {
    if ((Inst_00->flags2 & 0x10000401U) == 0x400)
    {
      uVar5 = Inst_00->checkMask;
      puVar1 = (u_char *)INSTANCE_Post(Inst_00, 0xd);
      INSTANCE_Query(Inst_00, 0x200000, 0);
      if (puVar1 != (u_char *)0x0)
      {
        TransposeMatrix(puVar1, (u_char *)&MStack80);
        Inst = instanceList->first;
        while (Inst != (_Instance *)0x0)
        {
          if ((((Inst != Inst_00) && ((Inst->flags2 & 0x10000000U) == 0)) &&
               ((Inst->flags & 0x20U) == 0)) &&
              (uVar2 = INSTANCE_Post(Inst, 1), (uVar2 & uVar5) != 0))
          {
            pMVar4 = (MATRIX *)INSTANCE_Post(Inst, 0xe);
            if (((pMVar4 != (MATRIX *)0x0) || (pMVar4 = Inst->matrix, pMVar4 != (MATRIX *)0x0)) &&
                (iVar3 = INSTANCE_SetStatsData(Inst_00, Inst, (_Vector *)pMVar4->t, &eStack48, &MStack80), iVar3 != 0))
            {
              INSTANCE_Query(Inst_00, 0x200001, (int)&eStack48);
            }
          }
          Inst = Inst->next;
        }
      }
    }
    Inst_00 = Inst_00->next;
  }
  return;
}

int INSTANCE_SetStatsData(_Instance *instance, _Instance *checkee, _Vector *checkPoint,
                          evCollideInstanceStatsData *data, MATRIX *mat)

{
  bool bVar1;
  u_int uVar2;
  long lVar3;

  uVar2 = MATH3D_LengthXY((int)(instance->position).x - checkPoint->x,
                          (int)(instance->position).y - checkPoint->y,
                          (int)(instance->position).z - checkPoint->z);
  bVar1 = uVar2 < instance->maxCheckDistance;
  if (bVar1)
  {
    DAT_1f800000 = *(short *)&checkPoint->x - (instance->position).x;
    DAT_1f800002 = *(short *)&checkPoint->y - (instance->position).y;
    DAT_1f800004 = *(short *)&checkPoint->z - (instance->position).z;
    ApplyMatrix(mat, 0x1f800000, &data->relativePosition);
    data->instance = checkee;
    data->distance = uVar2;
    data->zDelta = (int)DAT_1f800004;
    lVar3 = MATH3D_LengthXYZ((int)DAT_1f800000, (int)DAT_1f800002);
    data->xyDistance = lVar3;
  }
  return (u_int)bVar1;
}

void INSTANCE_LinkToParent(_Instance *instance, _Instance *parent, int node)

{
  short sVar1;

  instance->LinkSibling = parent->LinkChild;
  parent->LinkChild = instance;
  sVar1 = (instance->scale).x;
  instance->LinkParent = parent;
  instance->ParentLinkNode = node;
 (int)(parent->scale).x);
 (int)(parent->scale).y);
 (int)(parent->scale).z);
 INSTANCE_UpdateFamilyStreamUnitID(parent);
 INSTANCE_Query(parent, (int)&DAT_00100012, (int)instance);
 instance->flags2 = instance->flags2 | 8;
 return;
}

void INSTANCE_UnlinkFromParent(_Instance *instance)

{
  short sVar1;
  _Instance *p_Var2;
  _Instance *p_Var3;
  _Instance *Inst;
  int iVar4;
  _G2EulerAngles_Type local_18;

  Inst = instance->LinkParent;
  if (Inst != (_Instance *)0x0)
  {
    p_Var2 = Inst->LinkChild;
    if (p_Var2 == instance)
    {
      Inst->LinkChild = instance->LinkSibling;
    }
    else
    {
      p_Var3 = p_Var2->LinkSibling;
      while (p_Var3 != instance)
      {
        p_Var2 = p_Var2->LinkSibling;
        p_Var3 = p_Var2->LinkSibling;
      }
      p_Var2->LinkSibling = instance->LinkSibling;
    }
    sVar1 = (instance->scale).x;
    instance->LinkSibling = (_Instance *)0x0;
    instance->LinkParent = (_Instance *)0x0;
    iVar4 = (int)sVar1 * (int)(Inst->scale).x;
    if (iVar4 < 0)
    {
      iVar4 = iVar4 + 0xfff;
    }
    (instance->scale).x = (short)(iVar4 >> 0xc);
    iVar4 = (int)(instance->scale).y * (int)(Inst->scale).y;
    if (iVar4 < 0)
    {
      iVar4 = iVar4 + 0xfff;
    }
    (instance->scale).y = (short)(iVar4 >> 0xc);
    iVar4 = (int)(instance->scale).z * (int)(Inst->scale).z;
    if (iVar4 < 0)
    {
      iVar4 = iVar4 + 0xfff;
    }
    (instance->scale).z = (short)(iVar4 >> 0xc);
    if (Inst->matrix != (MATRIX *)0x0)
    {
      G2EulerAngles_FromMatrix(&local_18, (_G2Matrix_Type *)(Inst->matrix + instance->ParentLinkNode), 0x15);
      (instance->rotation).x = local_18.x;
      (instance->rotation).y = local_18.y;
      (instance->rotation).z = local_18.z;
    }
    INSTANCE_Query(Inst, (int)&DAT_00100013, (int)instance);
  }
  return;
}

void INSTANCE_UnlinkChildren(_Instance *instance)

{
  _Instance *Data;
  _Instance *p_Var1;

  Data = instance->LinkChild;
  while (Data != (_Instance *)0x0)
  {
    p_Var1 = Data->LinkSibling;
    INSTANCE_Query(instance, (int)&DAT_00100013, (int)Data);
    Data->LinkParent = (_Instance *)0x0;
    Data->LinkSibling = (_Instance *)0x0;
    Data = p_Var1;
  }
  instance->LinkChild = (_Instance *)0x0;
  return;
}

void INSTANCE_UpdateFamilyStreamUnitID(_Instance *instance)

{
  _Instance *instance_00;

  instance_00 = instance->LinkChild;
  while (instance_00 != (_Instance *)0x0)
  {
    instance_00->currentStreamUnitID = instance->currentStreamUnitID;
    INSTANCE_UpdateFamilyStreamUnitID(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}

_Instance *INSTANCE_GetChildLinkedToSegment(_Instance *instance, int segment)

{
  _Instance *p_Var1;

  p_Var1 = instance->LinkChild;
  while ((p_Var1 != (_Instance *)0x0 && (p_Var1->ParentLinkNode != segment)))
  {
    p_Var1 = p_Var1->LinkSibling;
  }
  return p_Var1;
}

int INSTANCE_InPlane(_Instance *instance1, _Instance *instance2)

{
  _Instance *p_Var1;

  p_Var1 = instance1->LinkParent;
  while (p_Var1 != (_Instance *)0x0)
  {
    instance1 = instance1->LinkParent;
    p_Var1 = instance1->LinkParent;
  }
  while (instance2->LinkParent != (_Instance *)0x0)
  {
    instance2 = instance2->LinkParent;
  }
  return (u_int)(instance1 == instance2);
}

int INSTANCE_GetFadeValue(_Instance *instance)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int iVar4;

  iVar3 = (int)instance->fadeValue;
  if (gameTrackerX.gameData.asmData.MorphTime != 1000)
  {
    iVar3 = 0x1000 - iVar3;
    lVar2 = MEMPACK_ReportMemory((char *)instance->object);
    if ((lVar2 != 0) &&
        (((instance->object->oflags2 & 0x2000000U) != 0 ||
          ((instance->LinkParent != (_Instance *)0x0 &&
            ((instance->LinkParent->object->oflags2 & 0x2000000U) != 0))))))
    {
      sVar1 = gameTrackerX.material_fadeValue;
      if ((instance->flags2 & 0x8000000U) != 0)
      {
        sVar1 = gameTrackerX.spectral_fadeValue;
      }
      iVar4 = sVar1 * iVar3;
      iVar3 = iVar4 >> 0xc;
      if (iVar4 < 0)
      {
        iVar3 = iVar4 + 0xfff >> 0xc;
      }
    }
    iVar3 = 0x1000 - iVar3;
  }
  return iVar3;
}

u_long INSTANCE_DefaultAnimCallback(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message, long messageDataA,
                                    long messageDataB, _Instance *instance)

{
  if (message == G2ANIM_MSG_PLAYEFFECT)
  {
    if (messageDataA == 0)
    {
      if (messageDataB != 0)
      {
        SOUND_Play3dSound(&instance->position, (int)*(short *)messageDataB,
                          (int)*(short *)(messageDataB + 4), (int)*(short *)(messageDataB + 2),
                          (int)*(short *)(messageDataB + 6));
      }
    }
    else
    {
      if (messageDataA == 1)
      {
        FX_StartInstanceEffect(instance, (ObjectEffect *)messageDataB, 0);
      }
    }
  }
  return messageDataA;
}
