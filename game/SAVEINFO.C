#include "THISDUST.H"
#include "SAVEINFO.H"

void SAVE_GetInstanceRotation(_Instance *instance, _SmallRotation *vector)

{
  short *psVar1;

  psVar1 = (short *)INSTANCE_Post(instance, 7);
  if (psVar1 == (short *)0x0)
  {
    vector->x = (instance->rotation).x;
    vector->y = (instance->rotation).y;
    vector->z = (instance->rotation).z;
  }
  else
  {
    vector->x = *psVar1;
    vector->y = psVar1[1];
    vector->z = psVar1[2];
  }
  return;
}

void SAVE_ClearMemory(GameTracker *gameTracker)

{
  savedInfoTracker.InfoStart = savedInfoTracker.MemoryCardBuffer + the_header_size;
  savedInfoTracker.EndOfMemory = savedInfoTracker.MemoryCardBuffer + 0x6000;
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart;
  memset(savedInfoTracker.InfoStart, 0, 0x6000 - the_header_size);
  numbufferedIntros = 0;
  memset(&bufferSavedIntroArray64, 0, 0x100);
  GlobalSave = (_GlobalSaveTracker *)SAVE_GetSavedBlock(6, 0);
  GlobalSave->CurrentBirthID = 0x2000;
  GlobalSave->humanOpinionOfRaziel = -1;
  SAVE_GetSavedBlock(4, 0);
  return;
}

void HUD_Init(GameTracker *gt)

{
  char *buffer;

  buffer = MEMPACK_Malloc(0x6000, '\x12');
  if (DoMainMenu == 0)
  {
    gt->memcard = (memcard_t *)0x0;
  }
  else
  {
    gt->memcard = &gMemcard;
    the_header_size = memcard_item(&gMemcard, gt, 3, buffer, 0x6000);
  }
  savedInfoTracker.MemoryCardBuffer = buffer;
  SAVE_ClearMemory(gt);
  return;
}

void *SAVE_GetSavedBlock(long saveType, long extraSize)

{
  bool bVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;

  pcVar5 = (char *)0x0;
  bVar1 = false;
  iVar4 = ((&SaveArraySize)[saveType] + extraSize + 3 >> 2) * 4;
  do
  {
    pcVar2 = savedInfoTracker.InfoEnd;
    if (savedInfoTracker.InfoEnd + iVar4 < savedInfoTracker.EndOfMemory)
    {
      *savedInfoTracker.InfoEnd = (char)saveType;
      pcVar2[1] = (char)(iVar4 >> 2);
      savedInfoTracker.InfoEnd = savedInfoTracker.InfoEnd + iVar4;
      bVar1 = true;
      pcVar5 = pcVar2;
    }
    else
    {
      lVar3 = SAVE_PurgeAMemoryBlock();
      if (lVar3 == 0)
      {
        bVar1 = true;
        FONT_Print("Ran out of saved memory. Needed %d, used %d.\nIncrease from %d\n");
      }
    }
  } while (!bVar1);
  return pcVar5;
}

long SAVE_PurgeAMemoryBlock(void)

{
  SavedBasic *savedBlock;

  savedBlock = (SavedBasic *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      if (((savedBlock->savedID == '\x01') && ((*(u_int *)(savedBlock + 0x12) & 0x100) != 0)) ||
          ((savedBlock->savedID == '\a' && ((*(u_int *)(savedBlock + 8) & 0x100) != 0))))
      {
        SAVE_DeleteBlock(savedBlock);
        return 1;
      }
      savedBlock = savedBlock + (u_int)savedBlock->shiftedSaveSize * 2;
    } while (savedBlock < savedInfoTracker.InfoEnd);
  }
  return 0;
}

long SAVE_SaveableInstance(_Instance *instance)

{
  Object *pOVar1;
  u_int uVar2;

  uVar2 = 0;
  if (((instance->flags2 & 0x20000U) == 0) && (pOVar1 = instance->object, pOVar1 != (Object *)0x0))
  {
    if (((pOVar1->oflags2 & 0x80000U) == 0) && (instance != gameTrackerX.playerInstance))
    {
      if ((pOVar1->oflags2 & 0x40000U) == 0)
      {
        if ((instance->flags & 0x100000U) == 0)
        {
          uVar2 = 3;
        }
      }
      else
      {
        uVar2 = 1;
        if ((pOVar1->oflags & 1U) != 0)
        {
          uVar2 = (u_int)((instance->flags2 & 8U) != 0);
        }
      }
    }
    else
    {
      uVar2 = 1;
    }
  }
  if ((instance->object->oflags2 & 0x100000U) != 0)
  {
    uVar2 = 0;
  }
  if (((uVar2 == 1) && (instance->currentStreamUnitID == instance->birthStreamUnitID)) &&
      (instance->introUniqueID < 0x2000))
  {
    uVar2 = 2;
  }
  return uVar2;
}

_SavedIntro *
SAVE_UpdateLevelWithSave(_Instance *instance, Level *level, _SavedIntro *savedIntro, evControlSaveDataData *extraData)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  BSPTree *pBVar5;
  u_char uVar6;

  pBVar5 = level->terrain->BSPTreeArray;
  if (savedIntro != (_SavedIntro *)0x0)
  {
    uVar6 = *(u_char *)(instance->introName + 4);
    *(u_char *)savedIntro->name = *(u_char *)instance->introName;
    *(u_char *)(savedIntro->name + 4) = uVar6;
    savedIntro->savedID = '\x01';
    savedIntro->introUniqueID = *(short *)&instance->introUniqueID;
    savedIntro->streamUnitID = *(short *)&instance->currentStreamUnitID;
    savedIntro->birthUnitID = *(short *)&instance->birthStreamUnitID;
    sVar1 = (instance->position).y;
    sVar2 = (instance->position).z;
    sVar3 = (pBVar5->globalOffset).y;
    sVar4 = (pBVar5->globalOffset).z;
    (savedIntro->position).x = (instance->position).x - (pBVar5->globalOffset).x;
    (savedIntro->position).y = sVar1 - sVar3;
    (savedIntro->position).z = sVar2 - sVar4;
    SAVE_GetInstanceRotation(instance, &savedIntro->smallRotation);
    savedIntro->flags = instance->flags;
    savedIntro->flags2 = instance->flags2;
    savedIntro->specturalLightGroup = instance->spectralLightGroup;
    savedIntro->lightGroup = instance->lightGroup;
    savedIntro->attachedUniqueID = *(u_short *)&instance->attachedID;
    if (extraData != (evControlSaveDataData *)0x0)
    {
      memcpy(savedIntro + 1, extraData->data, extraData->length);
    }
  }
  return savedIntro;
}

_SavedIntroWithIntro *
SAVE_UpdateSavedIntroWithIntro(_Instance *instance, Level *level, _SavedIntroWithIntro *savedIntro,
                               evControlSaveDataData *extraData)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  BSPTree *pBVar5;

  pBVar5 = level->terrain->BSPTreeArray;
  if ((savedIntro != (_SavedIntroWithIntro *)0x0) && (instance->intro != (Intro *)0x0))
  {
    savedIntro->savedID = '\a';
    savedIntro->introOffset =
        (short)((int)((int)instance->intro - (int)level->introList) * 0x286bca1b >> 2);
    savedIntro->introUniqueID = *(short *)&instance->introUniqueID;
    savedIntro->birthUnitID = *(short *)&instance->birthStreamUnitID;
    sVar1 = (instance->position).y;
    sVar2 = (instance->position).z;
    sVar3 = (pBVar5->globalOffset).y;
    sVar4 = (pBVar5->globalOffset).z;
    (savedIntro->position).x = (instance->position).x - (pBVar5->globalOffset).x;
    (savedIntro->position).y = sVar1 - sVar3;
    (savedIntro->position).z = sVar2 - sVar4;
    SAVE_GetInstanceRotation(instance, &savedIntro->smallRotation);
    savedIntro->flags = instance->flags;
    savedIntro->flags2 = instance->flags2;
    savedIntro->specturalLightGroup = instance->spectralLightGroup;
    savedIntro->lightGroup = instance->lightGroup;
    savedIntro->attachedUniqueID = *(u_short *)&instance->attachedID;
    if (extraData != (evControlSaveDataData *)0x0)
    {
      memcpy(savedIntro + 1, extraData->data, extraData->length);
    }
  }
  return savedIntro;
}

SavedBasic *SAVE_GetSavedNextEvent(long areaID, long eventNumber)

{
  u_char uVar1;
  SavedBasic *pSVar2;

  pSVar2 = (SavedBasic *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      uVar1 = pSVar2->savedID;
      if (uVar1 == '\x02')
      {
        if (((int)(short)pSVar2[1] == areaID) && ((int)(short)pSVar2[2] == eventNumber))
        {
          return pSVar2;
        }
        uVar1 = pSVar2->savedID;
      }
      if (((uVar1 == '\t') && ((int)(short)pSVar2[1] == areaID)) &&
          ((u_int)pSVar2[2].savedID == eventNumber))
      {
        return pSVar2;
      }
      pSVar2 = pSVar2 + (u_int)pSVar2->shiftedSaveSize * 2;
    } while (pSVar2 < savedInfoTracker.InfoEnd);
  }
  return (SavedBasic *)0x0;
}

void SAVE_DeleteSavedEvent(long areaID, long eventNumber)

{
  SavedBasic *savedBlock;

  savedBlock = SAVE_GetSavedNextEvent(areaID, eventNumber);
  if (savedBlock != (SavedBasic *)0x0)
  {
    SAVE_DeleteBlock(savedBlock);
  }
  return;
}

SavedBasic *SAVE_GetSavedEvent(long areaID, SavedBasic *curSave)

{
  SavedBasic *pSVar1;

  pSVar1 = (SavedBasic *)savedInfoTracker.InfoStart;
  if (curSave != (SavedBasic *)0x0)
  {
    pSVar1 = curSave + (u_int)curSave->shiftedSaveSize * 2;
  }
  while (true)
  {
    if (savedInfoTracker.InfoEnd <= pSVar1)
    {
      return (SavedBasic *)0x0;
    }
    if (((pSVar1->savedID == '\x02') && ((int)(short)pSVar1[1] == areaID)) ||
        ((pSVar1->savedID == '\t' && ((int)(short)pSVar1[1] == areaID))))
      break;
    pSVar1 = pSVar1 + (u_int)pSVar1->shiftedSaveSize * 2;
  }
  return pSVar1;
}

void SAVE_BufferIntro(SavedBasic *savedIntro)

{
  SavedBasic **ppSVar1;
  int iVar2;
  int iVar3;

  iVar2 = 0;
  if (numbufferedIntros < 0x40)
  {
    ppSVar1 = &bufferSavedIntroArray64;
    do
    {
      if (*ppSVar1 == savedIntro)
        break;
      iVar2 = iVar2 + 1;
      ppSVar1 = ppSVar1 + 1;
    } while (iVar2 < 0x40);
    iVar3 = 0;
    if (iVar2 == 0x40)
    {
      ppSVar1 = &bufferSavedIntroArray64;
      numbufferedIntros = numbufferedIntros + 1;
      do
      {
        iVar3 = iVar3 + 1;
        if (*ppSVar1 == (SavedBasic *)0x0)
        {
          *ppSVar1 = savedIntro;
          return;
        }
        ppSVar1 = ppSVar1 + 1;
      } while (iVar3 < 0x40);
    }
  }
  return;
}

void SAVE_IntroduceBufferIntros(void)

{
  _StreamUnit *streamUnit;
  _Instance *p_Var1;
  int iVar2;
  _SavedIntro *savedIntro;
  int iVar3;

  if (numbufferedIntros < 0x40)
  {
    iVar3 = 0;
    iVar2 = 0;
    do
    {
      savedIntro = *(_SavedIntro **)((int)&bufferSavedIntroArray64 + iVar2);
      if (savedIntro != (_SavedIntro *)0x0)
      {
        if (savedIntro->savedID == '\x01')
        {
          streamUnit = STREAM_GetStreamUnitWithID((int)savedIntro->streamUnitID);
          if (streamUnit != (_StreamUnit *)0x0)
          {
            p_Var1 = INSTANCE_InstanceGroupNumber(savedIntro, streamUnit);
          LAB_800b4788:
            if (p_Var1 == (_Instance *)0x0)
              goto LAB_800b47a0;
          }
        }
        else
        {
          streamUnit = STREAM_GetStreamUnitWithID((int)*(short *)(savedIntro->name + 2));
          if (streamUnit != (_StreamUnit *)0x0)
          {
            p_Var1 = INSTANCE_IntroduceSavedInstanceWithIntro((_SavedIntroWithIntro *)savedIntro, streamUnit);
            goto LAB_800b4788;
          }
        }
        *(_SavedIntro **)((int)&bufferSavedIntroArray64 + iVar2) = (_SavedIntro *)0x0;
        numbufferedIntros = numbufferedIntros + -1;
      }
    LAB_800b47a0:
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 4;
    } while (iVar3 < 0x40);
  }
  return;
}

void SAVE_IntroForStreamID(_StreamUnit *streamUnit)

{
  _SavedIntro *savedIntro;
  int iVar1;

  iVar1 = streamUnit->StreamUnitID;
  savedIntro = (_SavedIntro *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      if ((savedIntro->savedID == '\x01') && ((int)savedIntro->streamUnitID == iVar1))
      {
        INSTANCE_InstanceGroupNumber(savedIntro, streamUnit);
      }
      else
      {
        if ((savedIntro->savedID == '\a') && ((int)*(short *)(savedIntro->name + 2) == iVar1))
        {
          INSTANCE_IntroduceSavedInstanceWithIntro((_SavedIntroWithIntro *)savedIntro, streamUnit);
        }
      }
      savedIntro = (_SavedIntro *)(&savedIntro->savedID + (u_int)savedIntro->shiftedSaveSize * 4);
    } while (savedIntro < savedInfoTracker.InfoEnd);
  }
  return;
}

long SAVE_HasSavedIntro(Intro *intro, long currentStreamID)

{
  char *pcVar1;

  pcVar1 = savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      if (((*pcVar1 == '\x01') && ((int)*(short *)(pcVar1 + 0xc) == intro->UniqueID)) ||
          ((*pcVar1 == '\a' && ((int)*(short *)(pcVar1 + 8) == intro->UniqueID))))
      {
        return 1;
      }
      pcVar1 = pcVar1 + (u_int)(byte)pcVar1[1] * 4;
    } while (pcVar1 < savedInfoTracker.InfoEnd);
  }
  return 0;
}

SavedLevel *SAVE_UpdateSavedIntro(long areaID)

{
  SavedLevel *pSVar1;

  pSVar1 = (SavedLevel *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      if ((pSVar1->savedID == '\x03') && ((int)pSVar1->areaID == areaID))
      {
        return pSVar1;
      }
      pSVar1 = (SavedLevel *)(&pSVar1->savedID + (u_int)pSVar1->shiftedSaveSize * 4);
    } while (pSVar1 < savedInfoTracker.InfoEnd);
  }
  return (SavedLevel *)0x0;
}

void SAVE_UpdateLevelWithSave(_StreamUnit *streamUnit)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  SavedLevel *pSVar7;
  BSPTree *pBVar8;
  u_short uVar9;
  SavedLevel *pSVar10;
  int iVar11;
  _Terrain *p_Var12;

  sVar2 = (streamUnit->level->terrain->BSPTreeArray->globalOffset).z;
  pSVar7 = SAVE_UpdateSavedIntro(streamUnit->StreamUnitID);
  if (pSVar7 != (SavedLevel *)0x0)
  {
    p_Var12 = streamUnit->level->terrain;
    iVar11 = 0;
    pSVar10 = pSVar7;
    if (0 < pSVar7->numberBSPTreesSaved)
    {
      do
      {
        iVar11 = iVar11 + 1;
        pBVar8 = p_Var12->BSPTreeArray + *(byte *)((int)&pSVar10[1].numberBSPTreesSaved + 1);
        sVar3 = pSVar10[1].waterZ;
        *(u_char *)&pBVar8->localOffset = *(u_char *)(pSVar10 + 1);
        (pBVar8->localOffset).z = sVar3;
        sVar3 = (pBVar8->globalOffset).x;
        sVar4 = (pBVar8->localOffset).x;
        sVar5 = (pBVar8->localOffset).y;
        sVar6 = (pBVar8->localOffset).z;
        uVar9 = (u_short)(((int)((u_int)(u_short)pBVar8->flags << 0x10) >> 0x18) << 8);
        pBVar8->flags = uVar9;
        bVar1 = *(byte *)&pSVar10[1].numberBSPTreesSaved;
        (pBVar8->globalOffset).x = sVar3 + sVar4;
        (pBVar8->globalOffset).y = (pBVar8->globalOffset).y + sVar5;
        (pBVar8->globalOffset).z = (pBVar8->globalOffset).z + sVar6;
        pBVar8->flags = uVar9 | bVar1;
        pSVar10 = pSVar10 + 1;
      } while (iVar11 < pSVar7->numberBSPTreesSaved);
    }
    iVar11 = (int)pSVar7->waterZ;
    if ((iVar11 == -0x7fff) || (iVar11 == 0x7fff))
    {
      streamUnit->level->waterZLevel = (int)pSVar7->waterZ;
    }
    else
    {
      streamUnit->level->waterZLevel = iVar11 + sVar2;
    }
    p_Var12->UnitChangeFlags = p_Var12->UnitChangeFlags | 3;
  }
  return;
}

SavedLevel *SAVE_HasSavedLevel(long areaID, Level *level)

{
  short sVar1;
  u_short uVar2;
  bool bVar3;
  SavedLevel *savedBlock;
  _Terrain *p_Var4;
  int iVar5;
  SavedLevel *pSVar6;
  int iVar7;
  int iVar8;

  uVar2 = level->terrain->UnitChangeFlags;
  sVar1 = (level->terrain->BSPTreeArray->globalOffset).z;
  bVar3 = false;
  if (((uVar2 & 1) != 0) || ((uVar2 & 2) != 0))
  {
    bVar3 = true;
  }
  if (bVar3)
  {
    iVar8 = level->terrain->numBSPTrees + -2;
    savedBlock = (SavedLevel *)0x0;
    if ((0 < iVar8) &&
        ((savedBlock = SAVE_UpdateSavedIntro(areaID), savedBlock != (SavedLevel *)0x0 ||
                                                          (savedBlock = (SavedLevel *)SAVE_GetSavedBlock(3, iVar8 * 8), savedBlock != (SavedLevel *)0x0))))
    {
      savedBlock->areaID = (short)areaID;
      if ((level->waterZLevel == -0x7fff) || (level->waterZLevel == 0x7fff))
      {
        savedBlock->waterZ = *(short *)&level->waterZLevel;
      }
      else
      {
        savedBlock->waterZ = *(short *)&level->waterZLevel - sVar1;
      }
      savedBlock->numberBSPTreesSaved = (short)iVar8;
      p_Var4 = level->terrain;
      iVar8 = 0;
      if (0 < p_Var4->numBSPTrees)
      {
        iVar7 = 0;
        pSVar6 = savedBlock;
        do
        {
          iVar5 = (int)&p_Var4->BSPTreeArray->bspRoot + iVar7;
          if (1 < (u_short)(*(short *)(iVar5 + 0x1a) + 1U))
          {
            *(undefined *)((int)&pSVar6[1].numberBSPTreesSaved + 1) = (char)iVar8;
            sVar1 = *(short *)(iVar5 + 0x18);
            *(u_char *)(pSVar6 + 1) = *(u_char *)(iVar5 + 0x14);
            pSVar6[1].waterZ = sVar1;
            *(undefined *)&pSVar6[1].numberBSPTreesSaved = *(undefined *)(iVar5 + 0x12);
            pSVar6 = pSVar6 + 1;
          }
          p_Var4 = level->terrain;
          iVar8 = iVar8 + 1;
          iVar7 = iVar7 + 0x24;
        } while (iVar8 < p_Var4->numBSPTrees);
      }
    }
  }
  else
  {
    savedBlock = SAVE_UpdateSavedIntro(areaID);
    if (savedBlock != (SavedLevel *)0x0)
    {
      SAVE_DeleteBlock((SavedBasic *)savedBlock);
    }
  }
  return savedBlock;
}

void SAVE_DeleteBlock(SavedBasic *savedBlock)

{
  long lVar1;
  u_int uVar2;
  SavedBasic *pSVar3;
  SavedBasic **ppSVar4;
  int iVar5;

  lVar1 = numbufferedIntros;
  uVar2 = (u_int)savedBlock->shiftedSaveSize;
  if ((numbufferedIntros != 0) && (iVar5 = 0, 0 < numbufferedIntros))
  {
    ppSVar4 = &bufferSavedIntroArray64;
    do
    {
      pSVar3 = *ppSVar4;
      if (pSVar3 == savedBlock)
      {
        *ppSVar4 = (SavedBasic *)0x0;
      }
      else
      {
        if (savedBlock < pSVar3)
        {
          *ppSVar4 = pSVar3 + uVar2 * 0x7ffffffe;
        }
      }
      iVar5 = iVar5 + 1;
      ppSVar4 = ppSVar4 + 1;
    } while (iVar5 < lVar1);
  }
  memmove(savedBlock, savedBlock + uVar2 * 2,
          (size_t)(savedInfoTracker.InfoEnd + -(int)(savedBlock + uVar2 * 2)));
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoEnd + uVar2 * -4;
  return;
}

void COLLIDE_InstanceTerrain(_Instance *instance, Level *level)

{
  long lVar1;
  size_t *psVar2;
  void *pvVar3;
  _SavedIntro *savedIntro;
  evControlSaveDataData *extraData;
  _SavedIntroWithIntro *savedIntro_00;
  undefined *puVar4;
  MultiSpline *spline;
  u_short uVar5;
  long extraSize;

  extraSize = 0;
  lVar1 = SAVE_SaveableInstance(instance);
  if (lVar1 != 0)
  {
    if ((instance->flags2 & 4U) == 0)
    {
      if (lVar1 == 1)
      {
        SAVE_Instance(instance);
        extraData = (evControlSaveDataData *)INSTANCE_Post(instance, 0x18);
        if (extraData != (evControlSaveDataData *)0x0)
        {
          extraSize = extraData->length;
        }
        savedIntro = (_SavedIntro *)SAVE_GetSavedBlock(1, extraSize);
        if (savedIntro != (_SavedIntro *)0x0)
        {
          SAVE_UpdateLevelWithSave(instance, level, savedIntro, extraData);
        }
      }
      else
      {
        if (lVar1 == 2)
        {
          SAVE_Instance(instance);
          extraData = (evControlSaveDataData *)INSTANCE_Post(instance, 0x18);
          if (extraData != (evControlSaveDataData *)0x0)
          {
            extraSize = extraData->length;
          }
          savedIntro_00 = (_SavedIntroWithIntro *)SAVE_GetSavedBlock(7, extraSize);
          if (savedIntro_00 != (_SavedIntroWithIntro *)0x0)
          {
            SAVE_UpdateSavedIntroWithIntro(instance, level, savedIntro_00, extraData);
          }
        }
        else
        {
          if (lVar1 == 3)
          {
            SAVE_Instance(instance);
            puVar4 = (undefined *)SAVE_GetSavedBlock(8, 0);
            if ((puVar4 != (undefined *)0x0) &&
                (spline = SCRIPT_GetMultiSpline(instance, (u_long *)0x0, (u_long *)0x0),
                 spline != (MultiSpline *)0x0))
            {
              uVar5 = instance->splineFlags & 0xfe7f;
              instance->splineFlags = uVar5;
              if ((instance->flags & 0x1000000U) != 0)
              {
                instance->splineFlags = uVar5 | 0x80;
              }
              if ((instance->flags & 0x2000000U) != 0)
              {
                instance->splineFlags = instance->splineFlags | 0x100;
              }
              *puVar4 = 8;
              *(undefined2 *)(puVar4 + 2) = *(undefined2 *)&instance->introUniqueID;
              *(short *)(puVar4 + 4) = instance->splineFlags;
              lVar1 = SplineGetFrameNumber(instance, spline);
              *(short *)(puVar4 + 6) = (short)lVar1;
              *(short *)(puVar4 + 8) = instance->clipBeg;
              *(short *)(puVar4 + 10) = instance->clipEnd;
            }
          }
        }
      }
    }
    else
    {
      SAVE_Instance(instance);
      psVar2 = (size_t *)INSTANCE_Post(instance, 0x18);
      if ((psVar2 != (size_t *)0x0) &&
          (pvVar3 = SAVE_GetSavedBlock(5, *psVar2), pvVar3 != (void *)0x0))
      {
        *(undefined2 *)((int)pvVar3 + 2) = *(undefined2 *)&instance->introUniqueID;
        memcpy((void *)((int)pvVar3 + 4), (void *)psVar2[1], *psVar2);
      }
    }
  }
  return;
}

void SAVE_Instance(_Instance *instance)

{
  u_char uVar1;
  SavedBasic *savedBlock;

  savedBlock = (SavedBasic *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      uVar1 = savedBlock->savedID;
      if (((((uVar1 == '\x01') && ((int)(short)savedBlock[6] == instance->introUniqueID)) ||
            ((uVar1 == '\a' && ((int)(short)savedBlock[4] == instance->introUniqueID)))) ||
           ((uVar1 == '\x05' && ((int)(short)savedBlock[1] == instance->introUniqueID)))) ||
          ((uVar1 == '\b' && ((int)(short)savedBlock[1] == instance->introUniqueID))))
      {
        SAVE_DeleteBlock(savedBlock);
        return;
      }
      savedBlock = savedBlock + (u_int)savedBlock->shiftedSaveSize * 2;
    } while (savedBlock < savedInfoTracker.InfoEnd);
  }
  return;
}

void SAVE_SetDeadDeadBit(_Instance *instance, long set)

{
  byte bVar1;
  u_int uVar2;
  char *pcVar3;
  u_int uVar4;
  char *pcVar5;
  int iVar6;

  if (instance->introUniqueID < 0x2000)
  {
    pcVar3 = (char *)0x0;
    pcVar5 = savedInfoTracker.InfoStart;
    if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
    {
      do
      {
        pcVar3 = pcVar5;
        if (*pcVar3 == '\x04')
          break;
        pcVar5 = pcVar3 + (u_int)(byte)pcVar3[1] * 4;
        pcVar3 = (char *)0x0;
      } while (pcVar5 < savedInfoTracker.InfoEnd);
    }
    if (pcVar3 != (char *)0x0)
    {
      uVar2 = instance->introUniqueID;
      uVar4 = uVar2;
      if ((int)uVar2 < 0)
      {
        uVar4 = uVar2 + 7;
      }
      iVar6 = (int)uVar4 >> 3;
      if (iVar6 < 0x340)
      {
        bVar1 = (byte)(1 << (uVar2 & 7));
        if (set == 1)
        {
          (pcVar3 + iVar6)[2] = (pcVar3 + iVar6)[2] | bVar1;
          return;
        }
        (pcVar3 + iVar6)[2] = (pcVar3 + iVar6)[2] & ~bVar1;
      }
    }
  }
  return;
}

void SAVE_RestoreGlobalSavePointer(void)

{
  _GlobalSaveTracker *p_Var1;

  GlobalSave = (_GlobalSaveTracker *)0x0;
  p_Var1 = (_GlobalSaveTracker *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    while (GlobalSave = p_Var1, *(char *)&p_Var1->savedID != '\x06')
    {
      p_Var1 = (_GlobalSaveTracker *)(&p_Var1->savedID + (u_int) * (byte *)((int)&p_Var1->savedID + 1) * 2);
      if (savedInfoTracker.InfoEnd <= p_Var1)
      {
        GlobalSave = (_GlobalSaveTracker *)0x0;
        return;
      }
    }
  }
  return;
}

long SAVE_IsIntroDeadDead(Intro *intro)

{
  u_int uVar1;
  char *pcVar2;
  u_int uVar3;
  char *pcVar4;
  u_int uVar5;

  uVar5 = 0;
  if (intro->UniqueID < 0x2000)
  {
    pcVar2 = savedInfoTracker.InfoStart;
    pcVar4 = (char *)0x0;
    if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
    {
      do
      {
        pcVar4 = pcVar2;
        if (*pcVar2 == '\x04')
          break;
        pcVar2 = pcVar2 + (u_int)(byte)pcVar2[1] * 4;
        pcVar4 = (char *)0x0;
      } while (pcVar2 < savedInfoTracker.InfoEnd);
    }
    if (pcVar4 != (char *)0x0)
    {
      uVar1 = intro->UniqueID;
      uVar3 = uVar1;
      if ((int)uVar1 < 0)
      {
        uVar3 = uVar1 + 7;
      }
      uVar1 = 1 << (uVar1 & 7);
      if ((int)uVar3 >> 3 < 0x340)
      {
        uVar5 = (u_int)(((byte)pcVar4[((int)uVar3 >> 3) + 2] & uVar1) == uVar1);
      }
    }
  }
  return uVar5;
}

void SAVE_DoInstanceDeadDead(_Instance *instance)

{
  SAVE_Instance(instance);
  SAVE_SetDeadDeadBit(instance, 1);
  return;
}

void SAVE_MarkDeadDead(_Instance *instance)

{
  instance->flags = instance->flags | 0x800000;
  return;
}

void SAVE_Init(_Instance *instance)

{
  SAVE_SetDeadDeadBit(instance, 0);
  return;
}

SavedIntroSmall *SAVE_GetSavedSmallIntro(_Instance *instance)

{
  SavedIntroSmall *pSVar1;

  pSVar1 = (SavedIntroSmall *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      if ((pSVar1->savedID == '\x05') && ((int)pSVar1->introUniqueID == instance->introUniqueID))
      {
        return pSVar1;
      }
      pSVar1 = pSVar1 + pSVar1->shiftedSaveSize;
    } while (pSVar1 < savedInfoTracker.InfoEnd);
  }
  return (SavedIntroSmall *)0x0;
}

SavedIntroSpline *SAVE_GetIntroSpline(_Instance *instance)

{
  byte *pbVar1;
  u_char *puVar2;
  SavedIntroSpline *pSVar3;

  pSVar3 = (SavedIntroSpline *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      if ((pSVar3->savedID == '\b') && ((int)pSVar3->introUniqueID == instance->introUniqueID))
      {
        return pSVar3;
      }
      pbVar1 = &pSVar3->shiftedSaveSize;
      puVar2 = &pSVar3->savedID;
      pSVar3 = (SavedIntroSpline *)(puVar2 + (u_int)*pbVar1 * 4);
    } while ((SavedIntroSpline *)(puVar2 + (u_int)*pbVar1 * 4) < savedInfoTracker.InfoEnd);
  }
  return (SavedIntroSpline *)0x0;
}

void SAVE_UpdateGlobalSaveTracker(void)

{
  _GlobalSaveTracker *p_Var1;
  u_long uVar2;
  u_long uVar3;
  u_char uVar4;
  u_short uVar5;
  int iVar6;

  p_Var1 = GlobalSave;
  GlobalSave->currentTime = gameTrackerX.currentTime;
  uVar3 = gameTrackerX.sound.gSfxVol;
  uVar2 = gameTrackerX.sound.gMusicVol;
  (p_Var1->sound).gMasterVol = gameTrackerX.sound.gMasterVol;
  (p_Var1->sound).gMusicVol = uVar2;
  (p_Var1->sound).gSfxVol = uVar3;
  uVar4 = gameTrackerX.sound._16_4_;
  (p_Var1->sound).gVoiceVol = gameTrackerX.sound.gVoiceVol;
  *(u_char *)&(p_Var1->sound).gSfxOn = uVar4;
  GlobalSave->saveVersion = 0x5514;
  iVar6 = GAMEPAD_DualShockEnabled();
  if (iVar6 == 0)
  {
    uVar5 = GlobalSave->flags & 0xfffd;
  }
  else
  {
    uVar5 = GlobalSave->flags | 2;
  }
  GlobalSave->flags = uVar5;
  return;
}

void SAVE_UpdateGlobalSaveTracker(void)

{
  if (GlobalSave->saveVersion == 0x5514)
  {
    gameTrackerX.currentTime = GlobalSave->currentTime;
    gameTrackerX.sound.gMasterVol = (GlobalSave->sound).gMasterVol;
    gameTrackerX.sound.gMusicVol = (GlobalSave->sound).gMusicVol;
    gameTrackerX.sound.gSfxVol = (GlobalSave->sound).gSfxVol;
    gameTrackerX.sound.gVoiceVol = (GlobalSave->sound).gVoiceVol;
    gameTrackerX.sound._16_4_ = *(u_char *)&(GlobalSave->sound).gSfxOn;
    SOUND_SetInstanceSoundVolume(gameTrackerX.sound.gSfxVol);
    SOUND_SetSfxVolume(gameTrackerX.sound.gMusicVol);
    SpuSetVoiceVolume(gameTrackerX.sound.gVoiceVol);
    if ((GlobalSave->flags & 2U) == 0)
    {
      GAMEPAD_DisableDualShock();
    }
    else
    {
      GAMEPAD_EnableDualShock();
    }
  }
  else
  {
    SAVE_ClearMemory(&gameTrackerX);
  }
  return;
}

void SAVE_SaveEverythingInMemory(void)

{
  _Instance *instance;
  Level *level;
  STracker *pSVar1;
  _Instance *p_Var2;
  int iVar3;

  p_Var2 = (gameTrackerX.instanceList)->first;
  while (instance = p_Var2, instance != (_Instance *)0x0)
  {
    p_Var2 = instance->next;
    level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
    if (level != (Level *)0x0)
    {
      COLLIDE_InstanceTerrain(instance, level);
    }
  }
  iVar3 = 0;
  pSVar1 = &StreamTracker;
  do
  {
    if (pSVar1->StreamList[0].used == 2)
    {
      EVENT_SaveEventsFromLevel(pSVar1->StreamList[0].StreamUnitID, pSVar1->StreamList[0].level);
      SAVE_HasSavedLevel(pSVar1->StreamList[0].StreamUnitID, pSVar1->StreamList[0].level);
    }
    iVar3 = iVar3 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar3 < 0x10);
  return;
}

void SAVE_SaveGame(void)

{
  SAVE_SaveEverythingInMemory();
  SAVE_UpdateGlobalSaveTracker();
  GlobalSave->sizeUsedInBlock = (short)savedInfoTracker.InfoEnd - (short)savedInfoTracker.InfoStart;
  return;
}

void SAVE_RestoreGlobalSaveTracker(void)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
  SAVE_RestoreGlobalSavePointer();
  SAVE_UpdateGlobalSaveTracker();
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart + GlobalSave->sizeUsedInBlock;
  GAMELOOP_RequestLevelChange("under", 1, &gameTrackerX);
  return;
}

void SAVE_DebugSaveGame(void)

{
  return;
}

void SAVE_LoadSaveGame(void)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
  GAMELOOP_RequestLevelChange("under", 1, &gameTrackerX);
  gameTrackerX.gameMode = 0;
  return;
}

long SAVE_SizeOfFreeSpace(void)

{
  return (long)(savedInfoTracker.EndOfMemory + -(int)savedInfoTracker.InfoEnd);
}
