#include "THISDUST.H"
#include "STREAM.H"

void STREAM_FillOutFileNames(char *baseAreaName, char *dramName, char *vramName, char *sfxName)

{
  char *pcVar1;
  char acStack40[16];

  strcmp(acStack40, baseAreaName);
  pcVar1 = strpbrk(acStack40, "0123456789");
  if (pcVar1 != (char *)0x0)
  {
    *pcVar1 = '\0';
  }
  if (dramName != (char *)0x0)
  {
    sprintf(dramName, "\\kain2\\area\\%s\\bin\\%s.drm");
  }
  if (vramName != (char *)0x0)
  {
    sprintf(vramName, "\\kain2\\area\\%s\\bin\\%s.crm");
  }
  if (sfxName != (char *)0x0)
  {
    sprintf(sfxName, "\\kain2\\area\\%s\\bin\\%s.snf");
  }
  return;
}

void STREAM_AbortAreaLoad(char *baseAreaName)

{
  char acStack88[80];

  STREAM_FillOutFileNames(baseAreaName, (char *)0x0, acStack88, (char *)0x0);
  LOAD_AbortFileLoad(acStack88, VRAM_LoadReturn);
  return;
}

void STREAM_InitLoader(void)

{
  int iVar1;
  int iVar2;

  iVar2 = 0xf;
  iVar1 = -0x7ff2d234;
  do
  {
    *(undefined2 *)(iVar1 + 4) = 0;
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + -0x40;
  } while (-1 < iVar2);
  return;
}

int OBTABLE_FindObject(char *name)

{
  int iVar1;
  int iVar2;
  _ObjectTracker *s1;

  iVar2 = 0;
  s1 = gameTrackerX.GlobalObjects;
  while ((s1->objectStatus == 0 || (iVar1 = strcpy((char *)s1, name), iVar1 != 0)))
  {
    iVar2 = iVar2 + 1;
    s1 = s1 + 1;
    if (0x2f < iVar2)
    {
      return -1;
    }
  }
  return iVar2;
}

_ObjectTracker *FindObjectName(Object *object)

{
  Object **ppOVar1;
  _ObjectTracker *p_Var2;
  int iVar3;

  iVar3 = 0;
  ppOVar1 = &(gameTrackerX.GlobalObjects)->object;
  p_Var2 = gameTrackerX.GlobalObjects;
  while ((*(short *)(ppOVar1 + 1) == 0 || (*ppOVar1 != object)))
  {
    iVar3 = iVar3 + 1;
    ppOVar1 = ppOVar1 + 9;
    p_Var2 = p_Var2 + 1;
    if (0x2f < iVar3)
    {
      return (_ObjectTracker *)0x0;
    }
  }
  return p_Var2;
}

_StreamUnit *FindStreamUnitFromLevel(Level *level)

{
  STracker *pSVar1;
  int iVar2;

  iVar2 = 0;
  pSVar1 = &StreamTracker;
  while ((*(short *)pSVar1->StreamList != 2 || (*(Level **)pSVar1->StreamList != level)))
  {
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
    if (0xf < iVar2)
    {
      return (_StreamUnit *)0x0;
    }
  }
  return (_StreamUnit *)pSVar1;
}

void STREAM_DumpLoadingObjects(void *loadData, void *data, void *data2)

{
  long lVar1;
  int iVar2;
  char acStack80[64];

  GetRCnt(0xf2000000);
  if ((((*(u_int *)loadData & 0x8000000) != 0) && (*(int **)((int)loadData + 0x3c) != (int *)0x0)) &&
      (*(int *)((int)loadData + 0x40) != 0))
  {
    RELMOD_InitModulePointers(*(int *)((int)loadData + 0x40), *(int **)((int)loadData + 0x3c));
  }
  STREAM_PackVRAMObject((_ObjectTracker *)data);
  OBTABLE_InitAnimPointers((_ObjectTracker *)data);
  OBTABLE_InitObjectWithID((Object *)loadData);
  if ((*(u_int *)((int)loadData + 0x2c) & 0x800000) != 0)
  {
    sprintf(acStack80, "\\kain2\\sfx\\object\\%s\\%s.snf");
    *(undefined2 *)((int)loadData + 6) = 0;
    lVar1 = LOAD_DoesFileExist(acStack80);
    if (lVar1 != 0)
    {
      iVar2 = aadLoadDynamicSoundBankReturn2((char *)data, 0, 0);
      *(undefined2 *)((int)loadData + 6) = (short)iVar2;
    }
  }
  *(undefined2 *)((int)data + 0x14) = 2;
  return;
}

void STREAM_DumpUnit(_ObjectTracker *dumpee)

{
  _Instance *instance;
  _Instance *p_Var1;
  Object *object;

  object = dumpee->object;
  if ((_BlockVramEntry *)dumpee->vramBlock != (_BlockVramEntry *)0x0)
  {
    VRAM_ClearVramBlock((_BlockVramEntry *)dumpee->vramBlock);
  }
  OBTABLE_RemoveObjectEntry(object);
  if (((object->oflags2 & 0x800000U) != 0) && ((int)object->sfxFileHandle != 0))
  {
    aadFreeDynamicSfx((int)object->sfxFileHandle);
  }
  p_Var1 = (gameTrackerX.instanceList)->first;
  while (instance = p_Var1, instance != (_Instance *)0x0)
  {
    p_Var1 = instance->next;
    if (object == instance->object)
    {
      INSTANCE_ReallyRemoveInstance(gameTrackerX.instanceList, instance, 0);
    }
  }
  MEMPACK_Init((char *)object);
  dumpee->object = (Object *)0x0;
  return;
}

int STREAM_InList(char *name, char **nameList)

{
  char *pcVar1;
  int iVar2;

  pcVar1 = *nameList;
  while (true)
  {
    if (pcVar1 == (char *)0x0)
    {
      return 0;
    }
    iVar2 = strcpy(name, *nameList);
    nameList = nameList + 1;
    if (iVar2 == 0)
      break;
    pcVar1 = *nameList;
  }
  return 1;
}

int STREAM_IsSpecialMonster(char *name)

{
  int iVar1;

  iVar1 = STREAM_InList(name, &PTR_s_wallcr_800cb098);
  return iVar1;
}

void STREAM_DumpSomeMonsters(void)

{
  int iVar1;
  _ObjectTracker *dumpee;
  Object **ppOVar2;
  int iVar3;

  iVar3 = 0;
  ppOVar2 = &(gameTrackerX.GlobalObjects)->object;
  dumpee = gameTrackerX.GlobalObjects;
  do
  {
    if (((*(short *)(ppOVar2 + 1) == 2) && (*ppOVar2 != (Object *)0x0)) &&
        (iVar1 = STREAM_IsSpecialMonster((char *)dumpee), iVar1 != 0))
    {
      printf("NO INTRODUCE MONSTER FLAG: Dumping monster %s\n");
      STREAM_DumpUnit(dumpee);
    }
    iVar3 = iVar3 + 1;
    ppOVar2 = ppOVar2 + 9;
    dumpee = dumpee + 1;
  } while (iVar3 < 0x30);
  return;
}

void STREAM_DumpMonster(void)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x4000000;
  STREAM_DumpSomeMonsters();
  return;
}

void STREAM_NoMonsters(void)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xfbffffff;
  return;
}

int STREAM_YesMonsters(char *name)

{
  int iVar1;

  iVar1 = STREAM_InList(name, &PTR_s_skinner_800cb0b0);
  return iVar1;
}

int InsertGlobalObject(char *name, GameTracker *gameTracker)

{
  int iVar1;
  int iVar2;
  _ObjectTracker *otr;
  char acStack152[64];
  char acStack88[64];

  if (((gameTrackerX.gameFlags & 0x4000000U) != 0) &&
      (iVar1 = STREAM_IsSpecialMonster(name), iVar1 != 0))
  {
    return -1;
  }
  if (((gameTracker->debugFlags2 & 0x8000U) != 0) && (iVar1 = STREAM_YesMonsters(name), iVar1 != 0))
  {
    return -1;
  }
  otr = gameTracker->GlobalObjects;
  iVar1 = 0;
  do
  {
    if ((otr->objectStatus != 0) && (iVar2 = strcpy((char *)otr, name), iVar2 == 0))
      break;
    iVar1 = iVar1 + 1;
    otr = otr + 1;
  } while (iVar1 < 0x30);
  if (iVar1 == 0x30)
  {
    otr = gameTracker->GlobalObjects;
    iVar1 = 0;
    do
    {
      if (otr->objectStatus == 0)
        break;
      iVar1 = iVar1 + 1;
      otr = otr + 1;
    } while (iVar1 < 0x30);
    if (iVar1 == 0x30)
    {
      otr = gameTracker->GlobalObjects;
      iVar1 = 0;
      do
      {
        iVar2 = STREAM_DumpNonResidentObjects(otr);
        if (iVar2 != 0)
          break;
        iVar1 = iVar1 + 1;
        otr = otr + 1;
      } while (iVar1 < 0x30);
      if (iVar1 == 0x30)
      {
        DEBUG_FatalError("The Object tracker is full MAX_OBJECTS=%d.\n");
        iVar1 = -1;
      }
    }
    sprintf(acStack152, "\\kain2\\object\\%s\\%s.drm");
    sprintf(acStack88, "\\kain2\\object\\%s\\%s.crm");
    strcmp((char *)otr, name);
    otr->objectStatus = 1;
    LOAD_NonBlockingBufferedLoad(acStack152, STREAM_DumpLoadingObjects, otr, (void *)0x0, &otr->object, 1);
    otr->numInUse = 0;
    otr->numObjectsUsing = '\0';
  }
  return iVar1;
}

_ObjectTracker *STREAM_GetObjectTracker(char *name)

{
  int iVar1;
  _ObjectTracker *p_Var2;

  iVar1 = InsertGlobalObject(name, &gameTrackerX);
  if (iVar1 == -1)
  {
    p_Var2 = (_ObjectTracker *)0x0;
  }
  else
  {
    p_Var2 = gameTrackerX.GlobalObjects + iVar1;
  }
  return p_Var2;
}

void LoadLevelObjects(Level *level, GameTracker *gameTracker)

{
  char cVar1;
  int iVar2;
  char *name;
  int iVar3;
  int iVar4;

  name = (char *)level->objectNameList;
  cVar1 = *name;
  while (cVar1 != -1)
  {
    InsertGlobalObject(name, gameTracker);
    name = name + 0x10;
    cVar1 = *name;
  }
  iVar4 = 0;
  if (0 < level->numIntros)
  {
    iVar3 = 0;
    do
    {
      iVar2 = OBTABLE_FindObject(level->introList->name + iVar3);
      if (iVar2 == -1)
      {
        name = level->introList->name + iVar3;
        *(u_int *)(name + 0x2c) = *(u_int *)(name + 0x2c) | 0x4000;
      }
      else
      {
        name = level->introList->name + iVar3;
        *(u_int *)(name + 0x2c) = *(u_int *)(name + 0x2c) & 0xffffbfff;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x4c;
    } while (iVar4 < level->numIntros);
  }
  return;
}

long STREAM_IsAnInstanceUsingObject(Object *object)

{
  Object **ppOVar1;
  _Instance *p_Var2;

  p_Var2 = (gameTrackerX.instanceList)->first;
  do
  {
    if (p_Var2 == (_Instance *)0x0)
    {
      return 0;
    }
    ppOVar1 = &p_Var2->object;
    p_Var2 = p_Var2->next;
  } while (*ppOVar1 != object);
  return 1;
}

void STREAM_StreamLoadLevelAbort(void *loadData, void *data, void *data2)

{
  if (loadData != (void *)0x0)
  {
    MEMPACK_Init((char *)loadData);
  }
  *(undefined2 *)((int)data + 0x14) = 0;
  return;
}

void STREAM_LoadObjectReturn(_ObjectTracker *objectTracker)

{
  Object *object;
  char acStack80[64];

  object = objectTracker->object;
  if (objectTracker->objectStatus == 1)
  {
    sprintf(acStack80, "\\kain2\\object\\%s\\%s.drm");
    LOAD_AbortFileLoad(acStack80, STREAM_StreamLoadLevelAbort);
  }
  else
  {
    if (object != (Object *)0x0)
    {
      if ((object->oflags & 0x2000000U) == 0)
      {
        if ((_BlockVramEntry *)objectTracker->vramBlock != (_BlockVramEntry *)0x0)
        {
          VRAM_ClearVramBlock((_BlockVramEntry *)objectTracker->vramBlock);
        }
        if (((object->oflags2 & 0x800000U) != 0) && ((int)object->sfxFileHandle != 0))
        {
          aadFreeDynamicSfx((int)object->sfxFileHandle);
        }
        OBTABLE_RemoveObjectEntry(object);
        MEMPACK_Init((char *)object);
        objectTracker->objectStatus = 0;
      }
      if (object != (Object *)0x0)
      {
        return;
      }
    }
    objectTracker->objectStatus = 0;
  }
  return;
}

int STREAM_IsObjectInAnyUnit(_ObjectTracker *tracker)

{
  char cVar1;
  int iVar2;
  char *s2;
  int iVar3;

  iVar3 = 0;
  iVar2 = 0;
  do
  {
    if ((*(short *)((int)&StreamTracker.StreamList[0].used + iVar2) == 2) &&
        (iVar2 = *(int *)((int)&StreamTracker.StreamList[0].level + iVar2), iVar2 != 0))
    {
      s2 = *(char **)(iVar2 + 0x8c);
      cVar1 = *s2;
      while (cVar1 != -1)
      {
        iVar2 = strcpy((char *)tracker, s2);
        s2 = s2 + 0x10;
        if (iVar2 == 0)
        {
          return 1;
        }
        cVar1 = *s2;
      }
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar3 * 0x40;
  } while (iVar3 < 0x10);
  return 0;
}

void STREAM_RemoveAllObjectsNotInUse(GameTracker *gameTracker)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  _ObjectTracker *p_Var5;
  _ObjectTracker *p_Var6;
  int iVar7;
  int iVar8;
  short *psVar9;
  char *pcVar10;
  _ObjectTracker *tracker;
  _ObjectTracker *tracker_00;
  Object *object;
  int iVar11;

  iVar11 = 0;
  tracker = gameTracker->GlobalObjects;
  psVar9 = &tracker->objectStatus;
  tracker_00 = tracker;
  do
  {
    if ((((*psVar9 == 2) && (object = *(Object **)(psVar9 + -2), (object->oflags & 0x2000000U) == 0)) && (iVar3 = STREAM_IsObjectInAnyUnit(tracker_00), iVar3 == 0)) &&
        (lVar4 = STREAM_IsAnInstanceUsingObject(object), lVar4 == 0))
    {
      *psVar9 = 3;
    }
    iVar11 = iVar11 + 1;
    psVar9 = psVar9 + 0x12;
    tracker_00 = tracker_00 + 1;
  } while (iVar11 < 0x30);
  do
  {
    bVar2 = true;
    iVar11 = 0;
    psVar9 = &tracker->objectStatus;
    tracker_00 = tracker;
    do
    {
      if (*psVar9 == 3)
      {
        iVar3 = 0;
        p_Var5 = tracker_00;
        if (0 < (int)*(char *)(psVar9 + 4))
        {
          do
          {
            if (tracker[p_Var5->objectsUsing[0]].objectStatus != 3)
            {
              *psVar9 = 2;
              bVar2 = false;
              break;
            }
            iVar3 = iVar3 + 1;
            p_Var5 = (_ObjectTracker *)(tracker_00->name + iVar3);
          } while (iVar3 < (int)*(char *)(psVar9 + 4));
        }
      }
      iVar11 = iVar11 + 1;
      psVar9 = psVar9 + 0x12;
      tracker_00 = tracker_00 + 1;
    } while (iVar11 < 0x30);
  } while (!bVar2);
  iVar11 = 0;
  tracker_00 = tracker;
  do
  {
    if (tracker_00->objectStatus == 3)
    {
      iVar3 = 0;
      pcVar10 = &tracker->numObjectsUsing;
      p_Var5 = tracker;
      do
      {
        if ((u_int) * (u_short *)(pcVar10 + -8) - 1 < 2)
        {
          cVar1 = *pcVar10;
          iVar7 = 0;
          p_Var6 = p_Var5;
          if ('\0' < *pcVar10)
          {
            do
            {
              if ((int)p_Var6->objectsUsing[0] == iVar11)
              {
                *pcVar10 = cVar1 + -1;
                if (iVar7 < (char)(cVar1 + -1))
                {
                  do
                  {
                    iVar8 = iVar7 + 1;
                    p_Var5->objectsUsing[iVar7] = p_Var5->objectsUsing[iVar7 + 1];
                    iVar7 = iVar8;
                  } while (iVar8 < *pcVar10);
                }
                break;
              }
              iVar7 = iVar7 + 1;
              cVar1 = *pcVar10;
              p_Var6 = (_ObjectTracker *)(p_Var5->name + iVar7);
            } while (iVar7 < *pcVar10);
          }
        }
        iVar3 = iVar3 + 1;
        pcVar10 = pcVar10 + 0x24;
        p_Var5 = p_Var5 + 1;
      } while (iVar3 < 0x30);
      STREAM_LoadObjectReturn(tracker_00);
    }
    iVar11 = iVar11 + 1;
    tracker_00 = tracker_00 + 1;
    if (0x2f < iVar11)
    {
      iVar11 = 0;
      pcVar10 = &tracker->numObjectsUsing;
      do
      {
        if (((*(short *)(pcVar10 + -8) == 1) &&
             (iVar3 = STREAM_IsObjectInAnyUnit(tracker), iVar3 == 0)) &&
            (*pcVar10 == '\0'))
        {
          STREAM_LoadObjectReturn(tracker);
        }
        iVar11 = iVar11 + 1;
        pcVar10 = pcVar10 + 0x24;
        tracker = tracker + 1;
      } while (iVar11 < 0x30);
      return;
    }
  } while (true);
}

void RemoveAllObjects(GameTracker *gameTracker)

{
  _ObjectTracker *objectTracker;
  int iVar1;

  iVar1 = 0;
  objectTracker = gameTracker->GlobalObjects;
  do
  {
    if (objectTracker->objectStatus != 0)
    {
      STREAM_LoadObjectReturn(objectTracker);
    }
    iVar1 = iVar1 + 1;
    objectTracker = objectTracker + 1;
  } while (iVar1 < 0x30);
  return;
}

Level *STREAM_GetWaterZLevel(long id)

{
  STracker *pSVar1;
  int iVar2;

  iVar2 = 0;
  pSVar1 = &StreamTracker;
  while ((pSVar1->StreamList[0].used != 2 || (pSVar1->StreamList[0].StreamUnitID != id)))
  {
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
    if (0xf < iVar2)
    {
      return (Level *)0x0;
    }
  }
  return pSVar1->StreamList[0].level;
}

_StreamUnit *STREAM_GetStreamUnitWithID(long id)

{
  STracker *pSVar1;
  int iVar2;

  iVar2 = 0;
  pSVar1 = &StreamTracker;
  while ((*(short *)pSVar1->StreamList != 2 || (pSVar1->StreamList[0].StreamUnitID != id)))
  {
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
    if (0xf < iVar2)
    {
      return (_StreamUnit *)0x0;
    }
  }
  return (_StreamUnit *)pSVar1;
}

void STREAM_CalculateWaterLevel(Level *level)

{
  int iVar1;
  _TVertex *p_Var2;
  u_short *puVar3;
  _TFace *p_Var4;
  int iVar5;
  int iVar6;
  int iVar7;
  _Terrain *p_Var8;

  if (level->waterZLevel == 0)
  {
    if ((level->unitFlags & 1U) != 0)
    {
      level->waterZLevel = 0x7fff;
      return;
    }
    p_Var8 = level->terrain;
    iVar5 = p_Var8->numFaces;
    p_Var4 = p_Var8->faceList;
    iVar7 = -0x7fff;
    if (0 < iVar5)
    {
      puVar3 = &(p_Var4->face).v2;
      iVar6 = -0x7fff;
      do
      {
        iVar7 = iVar6;
        if ((*(byte *)(puVar3 + 1) & 8) != 0)
        {
          p_Var2 = p_Var8->vertexList;
          iVar1 = (int)p_Var2[(p_Var4->face).v0].vertex.z;
          if ((((iVar1 == (int)p_Var2[puVar3[-1]].vertex.z) &&
                (iVar1 == (int)p_Var2[*puVar3].vertex.z)) &&
               (iVar7 = iVar1, iVar6 != -0x7fff)) &&
              (iVar7 = iVar6, iVar6 != iVar1))
            break;
        }
        iVar5 = iVar5 + -1;
        puVar3 = puVar3 + 6;
        p_Var4 = p_Var4 + 1;
        iVar6 = iVar7;
      } while (0 < iVar5);
    }
    if (iVar7 == -0x7fff)
    {
      level->waterZLevel = -0x7fff;
      return;
    }
    level->waterZLevel = iVar7 + (level->terrain->BSPTreeArray->globalOffset).z;
  }
  return;
}

int STREAM_IsMonster(void)

{
  return (u_int)(gameTrackerX.gameData.asmData.MorphTime != 1000);
}

long STREAM_GetLevelWithID(Level *level, _Instance *instance)

{
  if ((instance->flags2 & 0x8000000U) == 0)
  {
    if (((instance->object->oflags2 & 0x2000000U) == 0) &&
        (gameTrackerX.gameData.asmData.MorphTime != 1000))
    {
      return -0x7fff;
    }
  }
  else
  {
    if ((instance->object->oflags2 & 0x2000000U) != 0)
    {
      return -0x7fff;
    }
    if (gameTrackerX.gameData.asmData.MorphTime == 1000)
    {
      return -0x7fff;
    }
  }
  return level->waterZLevel;
}

void STREAM_SetMainFog(_StreamUnit *streamUnit)

{
  Level *pLVar1;

  pLVar1 = streamUnit->level;
  if (gameTrackerX.gameData.asmData.MorphType == 0)
  {
    streamUnit->UnitFogNear = pLVar1->holdFogNear;
    streamUnit->UnitFogFar = pLVar1->holdFogFar;
  }
  else
  {
    streamUnit->UnitFogNear = pLVar1->spectralFogNear;
    streamUnit->UnitFogFar = pLVar1->spectralFogFar;
  }
  streamUnit->TargetFogNear = streamUnit->UnitFogNear;
  streamUnit->TargetFogFar = streamUnit->UnitFogFar;
  return;
}

void STREAM_GetStreamUnitWithID(_StreamUnit *streamUnit, short fogNear, short fogFar)

{
  _StreamUnit *p_Var1;
  short sVar2;
  short sVar3;

  p_Var1 = FindStreamUnitFromLevel(gameTrackerX.level);
  sVar3 = p_Var1->UnitFogFar;
  if (fogFar < p_Var1->UnitFogFar)
  {
    sVar3 = fogFar;
  }
  streamUnit->TargetFogFar = sVar3;
  streamUnit->UnitFogFar = sVar3;
  sVar2 = (short)((int)sVar3 + -2000);
  if ((int)fogNear < (int)sVar3 + -2000)
  {
    sVar2 = fogNear;
  }
  streamUnit->TargetFogNear = sVar2;
  streamUnit->UnitFogNear = sVar2;
  return;
}

void STREAM_ConnectStream(_StreamUnit *streamUnit)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  long lVar4;
  Level *pLVar5;
  int *piVar6;
  int iVar7;
  STracker **ppSVar8;
  _StreamUnit **pp_Var9;
  int iVar10;
  int iVar11;
  int *__src;
  STracker *pSVar12;
  Level **ppLVar13;
  int iVar14;
  char acStack72[16];
  _SVector local_38;
  STracker *local_30;
  int local_2c;

  WARPGATE_UpdateAddToArray(streamUnit);
  if (gameTrackerX.StreamUnitID != streamUnit->StreamUnitID)
  {
    iVar11 = 0;
    local_30 = (STracker *)STREAM_GetStreamUnitWithID(gameTrackerX.StreamUnitID);
    piVar6 = (int *)streamUnit->level->terrain->StreamUnits;
    iVar14 = *piVar6;
    __src = piVar6 + 1;
    if (0 < iVar14)
    {
      ppSVar8 = (STracker **)(piVar6 + 0xb);
      do
      {
        strcmp(acStack72, (char *)__src);
        pcVar2 = strchr(acStack72, 0x2c);
        iVar10 = 0;
        if (pcVar2 != (char *)0x0)
        {
          *pcVar2 = '\0';
          iVar10 = atoi(pcVar2 + 1);
        }
        pSVar12 = (STracker *)STREAM_GetStreamUnitWithID((long)ppSVar8[-5]);
        iVar3 = strcpy(acStack72, "warpgate");
        if ((iVar3 == 0) && (lVar4 = WARPGATE_IsUnitWarpRoom((_StreamUnit *)local_30), lVar4 != 0))
        {
          pSVar12 = local_30;
        }
        *ppSVar8 = pSVar12;
        if ((pSVar12 != (STracker *)0x0) && (pSVar12 == local_30))
        {
          piVar6 = (int *)(*(Level **)local_30->StreamList)->terrain->StreamUnits;
          iVar7 = 0;
          iVar3 = *piVar6;
          piVar6 = piVar6 + 1;
          if (0 < iVar3)
          {
            do
            {
              iVar7 = iVar7 + 1;
              if (iVar10 == piVar6[4])
              {
                local_38.x = *(short *)(piVar6 + 6) - *(short *)(ppSVar8 + -4);
                local_38.y = *(short *)((int)piVar6 + 0x1a) - *(short *)((int)ppSVar8 + -0xe);
                local_38.z = *(short *)(piVar6 + 7) - *(short *)(ppSVar8 + -3);
                CAMERA_Restore(streamUnit->level, &local_38);
                break;
              }
              piVar6 = piVar6 + 0x17;
            } while (iVar7 < iVar3);
          }
        }
        iVar11 = iVar11 + 1;
        ppSVar8 = ppSVar8 + 0x17;
        __src = __src + 0x17;
      } while (iVar11 < iVar14);
    }
    pSVar12 = &StreamTracker;
    local_2c = 0;
    ppLVar13 = &StreamTracker.StreamList[0].level;
    do
    {
      if ((*(short *)(ppLVar13 + -1) == 2) && (pSVar12 != (STracker *)streamUnit))
      {
        piVar6 = (int *)(*ppLVar13)->terrain->StreamUnits;
        iVar11 = 0;
        iVar14 = *piVar6;
        __src = piVar6 + 1;
        if (0 < iVar14)
        {
          pp_Var9 = (_StreamUnit **)(piVar6 + 0xb);
          do
          {
            bVar1 = false;
            strcmp(acStack72, (char *)__src);
            pcVar2 = strchr(acStack72, 0x2c);
            iVar10 = 0;
            if (pcVar2 != (char *)0x0)
            {
              *pcVar2 = '\0';
              iVar10 = atoi(pcVar2 + 1);
            }
            if (pp_Var9[-5] == (_StreamUnit *)streamUnit->StreamUnitID)
            {
              *pp_Var9 = streamUnit;
            LAB_80059f9c:
              bVar1 = true;
            }
            else
            {
              iVar3 = strcpy(acStack72, "warpgate");
              if ((iVar3 == 0) && (lVar4 = WARPGATE_IsUnitWarpRoom(streamUnit), lVar4 != 0))
              {
                *pp_Var9 = streamUnit;
                goto LAB_80059f9c;
              }
            }
            if ((bVar1) && (pSVar12 == local_30))
            {
              piVar6 = (int *)streamUnit->level->terrain->StreamUnits;
              iVar7 = 0;
              iVar3 = *piVar6;
              piVar6 = piVar6 + 1;
              if (0 < iVar3)
              {
                do
                {
                  iVar7 = iVar7 + 1;
                  if (iVar10 == piVar6[4])
                  {
                    local_38.x = *(short *)(pp_Var9 + -4) - *(short *)(piVar6 + 6);
                    local_38.y = *(short *)((int)pp_Var9 + -0xe) - *(short *)((int)piVar6 + 0x1a);
                    local_38.z = *(short *)(pp_Var9 + -3) - *(short *)(piVar6 + 7);
                    CAMERA_Restore(streamUnit->level, &local_38);
                    break;
                  }
                  piVar6 = piVar6 + 0x17;
                } while (iVar7 < iVar3);
              }
            }
            iVar11 = iVar11 + 1;
            pp_Var9 = pp_Var9 + 0x17;
            __src = __src + 0x17;
          } while (iVar11 < iVar14);
        }
      }
      ppLVar13 = ppLVar13 + 0x10;
      pSVar12 = (STracker *)(pSVar12->StreamList + 1);
      local_2c = local_2c + 1;
    } while (local_2c < 0x10);
    pLVar5 = streamUnit->level;
    iVar11 = 0;
    if (0 < pLVar5->numIntros)
    {
      iVar14 = 0;
      do
      {
        iVar10 = strcpy(pLVar5->introList->name + iVar14, "raziel");
        iVar11 = iVar11 + 1;
        if (iVar10 == 0)
        {
          pcVar2 = streamUnit->level->introList->name + iVar14;
          *(u_int *)(pcVar2 + 0x2c) = *(u_int *)(pcVar2 + 0x2c) | 8;
          return;
        }
        pLVar5 = streamUnit->level;
        iVar14 = iVar14 + 0x4c;
      } while (iVar11 < pLVar5->numIntros);
    }
  }
  return;
}

void STREAM_StreamLoadObjectAbort(void *loadData, void *data, void *data2)

{
  if (loadData != (void *)0x0)
  {
    MEMPACK_Init((char *)loadData);
  }
  *(u_char *)((int)data2 + 8) = 0;
  *(undefined2 *)((int)data2 + 4) = 0;
  return;
}

void STREAM_FinishLoad(_StreamUnit *streamUnit)

{
  long lVar1;
  int iVar2;
  _MultiSignal *p_Var3;
  Level *level;
  char acStack96[80];

  STREAM_FillOutFileNames(streamUnit->baseAreaName, (char *)0x0, (char *)0x0, acStack96);
  level = streamUnit->level;
  level->morphLastStep = -1;
  streamUnit->sfxFileHandle = 0;
  lVar1 = LOAD_DoesFileExist(acStack96);
  if (lVar1 != 0)
  {
    iVar2 = aadLoadDynamicSoundBankReturn2(streamUnit->baseAreaName, streamUnit->StreamUnitID, 1);
    streamUnit->sfxFileHandle = (short)iVar2;
  }
  LoadLevelObjects(level, &gameTrackerX);
  streamUnit->FogColor = *(long *)&level->backColorR;
  level->fogFar = streamUnit->TargetFogFar;
  level->fogNear = streamUnit->TargetFogNear;
  LIGHT_CalcDQPTable(level);
  STREAM_CalculateWaterLevel(level);
  if (gameTrackerX.gameData.asmData.MorphType == 1)
  {
    MORPH_UpdateTextures(level);
  }
  STREAM_ConnectStream(streamUnit);
  streamUnit->used = 2;
  EVENT_LoadEventsForLevel(streamUnit->StreamUnitID, level);
  PLANAPI_InitPlanMkrList(streamUnit);
  p_Var3 = level->startUnitLoadedSignal;
  if (p_Var3 != (_MultiSignal *)0x0)
  {
    p_Var3->flags = p_Var3->flags | 1;
    SIGNAL_HandleFogNear(gameTrackerX.playerInstance, level->startUnitLoadedSignal->signalList, 0);
    EVENT_AddSignalToReset(level->startUnitLoadedSignal);
  }
  SAVE_IntroForStreamID(streamUnit);
  SAVE_UpdateLevelWithSave(streamUnit);
  EVENT_AddStreamToInstanceList(streamUnit);
  WARPGATE_FixUnit(streamUnit);
  return;
}

void STREAM_LoadLevelReturn(void *loadData, void *data, void *data2)

{
  GetRCnt(0xf2000000);
  *(u_char *)data2 = *(u_char *)((int)loadData + 0xf8);
  gameTrackerX.StreamUnitID = *(long *)((int)loadData + 0xf8);
  gameTrackerX.level = (Level *)loadData;
  STREAM_SetMainFog((_StreamUnit *)data2);
  STREAM_FinishLoad((_StreamUnit *)data2);
  return;
}

void STREAM_StreamLoadLevelReturn(void *loadData, void *data, void *data2)

{
  short fogNear;
  short fogFar;

  GetRCnt(0xf2000000);
  *(u_char *)data2 = *(u_char *)((int)loadData + 0xf8);
  if (*(short *)((int)data2 + 4) == 3)
  {
    *(undefined2 *)((int)data2 + 4) = 0;
    MEMPACK_Init(*(char **)((int)data2 + 8));
    *(u_char *)((int)data2 + 8) = 0;
  }
  else
  {
    if (gameTrackerX.gameData.asmData.MorphType == 0)
    {
      fogNear = *(short *)((int)loadData + 0xa6);
      fogFar = *(short *)((int)loadData + 0xa4);
    }
    else
    {
      fogNear = *(short *)((int)loadData + 0x4a);
      fogFar = *(short *)((int)loadData + 0x48);
    }
    STREAM_GetStreamUnitWithID((_StreamUnit *)data2, fogNear, fogFar);
    STREAM_FinishLoad((_StreamUnit *)data2);
    if ((gameTrackerX.playerInstance != (_Instance *)0x0) &&
        (*(int *)((int)loadData + 0xf8) == (gameTrackerX.playerInstance)->currentStreamUnitID))
    {
      strcmp(gameTrackerX.baseAreaName, *(char **)((int)loadData + 0x98));
      STREAM_SetMainFog((_StreamUnit *)data2);
      gameTrackerX.StreamUnitID = *(long *)((int)loadData + 0xf8);
      gameTrackerX.level = (Level *)loadData;
    }
  }
  return;
}

void STREAM_UpdateLevelPointer(Level *oldLevel, Level *newLevel, long sizeOfLevel)

{
  Intro *pIVar1;
  void *pvVar2;
  _TFace *p_Var3;
  _Terrain *p_Var4;
  MultiSpline *pMVar5;
  STracker *pSVar6;
  Level *pLVar7;
  _Instance *p_Var8;
  Camera *pCVar9;
  int iVar10;
  Level *pLVar11;
  Level *pLVar12;

  pLVar12 = (Level *)((int)newLevel - (int)oldLevel);
  iVar10 = 0;
  pSVar6 = &StreamTracker;
  while ((pSVar6->StreamList[0].used != 2 || (pSVar6->StreamList[0].level != oldLevel)))
  {
    iVar10 = iVar10 + 1;
    pSVar6 = (STracker *)(pSVar6->StreamList + 1);
    if (0xf < iVar10)
    {
    LAB_8005a3f8:
      if (gameTrackerX.level == oldLevel)
      {
        gameTrackerX.level = newLevel;
      }
      p_Var8 = (gameTrackerX.instanceList)->first;
      if (p_Var8 != (_Instance *)0x0)
      {
        pLVar11 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
        do
        {
          pLVar7 = (Level *)p_Var8->intro;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            pIVar1 = (Intro *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              pIVar1 = (Intro *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->intro = pIVar1;
          }
          pLVar7 = (Level *)p_Var8->introData;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            pvVar2 = (void *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              pvVar2 = (void *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->introData = pvVar2;
          }
          pLVar7 = (Level *)p_Var8->tface;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            p_Var3 = (_TFace *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              p_Var3 = (_TFace *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->tface = p_Var3;
          }
          pLVar7 = (Level *)p_Var8->waterFace;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            p_Var3 = (_TFace *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              p_Var3 = (_TFace *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->waterFace = p_Var3;
          }
          pLVar7 = (Level *)p_Var8->waterFaceTerrain;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            p_Var4 = (_Terrain *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              p_Var4 = (_Terrain *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->waterFaceTerrain = p_Var4;
          }
          pLVar7 = (Level *)p_Var8->oldTFace;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            p_Var3 = (_TFace *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              p_Var3 = (_TFace *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->oldTFace = p_Var3;
          }
          pLVar7 = (Level *)p_Var8->tfaceLevel;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            pvVar2 = (void *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              pvVar2 = (void *)((int)pLVar7 + (int)pLVar12);
            }
            p_Var8->tfaceLevel = pvVar2;
          }
          p_Var8 = p_Var8->next;
        } while (p_Var8 != (_Instance *)0x0);
      }
      pMVar5 = theCamera.data.Cinematic.posSpline;
      if (((oldLevel <= theCamera.data.Cinematic.posSpline) &&
           (theCamera.data.Cinematic.posSpline <=
            (MultiSpline *)((int)&oldLevel->terrain + sizeOfLevel))) &&
          (pMVar5 = (MultiSpline *)0x0, theCamera.data.Cinematic.posSpline != (MultiSpline *)0x0))
      {
        pMVar5 = (MultiSpline *)((int)theCamera.data.Cinematic.posSpline + (int)pLVar12);
      }
      theCamera.data.Cinematic.posSpline = pMVar5;
      pMVar5 = theCamera.data.Cinematic.targetSpline;
      if (((oldLevel <= theCamera.data.Cinematic.targetSpline) &&
           (theCamera.data.Cinematic.targetSpline <=
            (MultiSpline *)((int)&oldLevel->terrain + sizeOfLevel))) &&
          (pMVar5 = (MultiSpline *)0x0, theCamera.data.Cinematic.targetSpline != (MultiSpline *)0x0))
      {
        pMVar5 = (MultiSpline *)((int)theCamera.data.Cinematic.targetSpline + (int)pLVar12);
      }
      theCamera.data.Cinematic.targetSpline = pMVar5;
      iVar10 = 0;
      if (-1 < theCamera.stack)
      {
        pLVar11 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
        pCVar9 = &theCamera;
        do
        {
          pLVar7 = (Level *)pCVar9->savedCinematic[0].posSpline;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            pMVar5 = (MultiSpline *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              pMVar5 = (MultiSpline *)((int)pLVar7 + (int)pLVar12);
            }
            pCVar9->savedCinematic[0].posSpline = pMVar5;
          }
          pLVar7 = (Level *)pCVar9->savedCinematic[0].targetSpline;
          if ((oldLevel <= pLVar7) && (pLVar7 <= pLVar11))
          {
            pMVar5 = (MultiSpline *)0x0;
            if (pLVar7 != (Level *)0x0)
            {
              pMVar5 = (MultiSpline *)((int)pLVar7 + (int)pLVar12);
            }
            pCVar9->savedCinematic[0].targetSpline = pMVar5;
          }
          iVar10 = iVar10 + 1;
          pCVar9 = (Camera *)&(pCVar9->core).wcTransform2;
        } while (iVar10 <= theCamera.stack);
      }
      EVENT_UpdateResetSignalArrayAndWaterMovement(oldLevel, newLevel, sizeOfLevel);
      return;
    }
  }
  pSVar6->StreamList[0].level = newLevel;
  goto LAB_8005a3f8;
}

_StreamUnit *STREAM_WhichUnitPointerIsIn(void *pointer)

{
  u_long uVar1;
  Level *address;
  STracker *pSVar2;
  int iVar3;

  iVar3 = 0;
  pSVar2 = &StreamTracker;
  do
  {
    if ((*(short *)pSVar2->StreamList == 2) &&
        (address = *(Level **)pSVar2->StreamList, address != (Level *)0x0))
    {
      uVar1 = MEMPACK_Size((char *)address);
      if ((address <= pointer) && (pointer <= (void *)((int)&address->terrain + uVar1)))
      {
        return (_StreamUnit *)pSVar2;
      }
    }
    iVar3 = iVar3 + 1;
    pSVar2 = (STracker *)(pSVar2->StreamList + 1);
    if (0xf < iVar3)
    {
      return (_StreamUnit *)0x0;
    }
  } while (true);
}

void STREAM_UpdateObjectPointer(Object *oldObject, Object *newObject, long sizeOfObject)

{
  _ObjectTracker *p_Var1;
  _ObjectTracker *p_Var2;
  Object *pOVar3;
  int iVar4;
  void *pvVar5;
  _HModel *p_Var6;
  int iVar7;
  Object *pOVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  Object *pOVar12;
  int iVar13;
  _Instance *instance;
  Object *offset;

  offset = (Object *)((int)newObject - (int)oldObject);
  p_Var1 = FindObjectName(oldObject);
  iVar13 = 0;
  if (p_Var1 != (_ObjectTracker *)0x0)
  {
    p_Var1->object = newObject;
    if ('\0' < p_Var1->numObjectsUsing)
    {
      p_Var2 = p_Var1;
      do
      {
        pOVar12 = gameTrackerX.GlobalObjects[p_Var2->objectsUsing[0]].object;
        if ((pOVar12 != (Object *)0x0) && (iVar10 = 0, 0 < pOVar12->numAnims))
        {
          do
          {
            pOVar8 = (Object *)pOVar12->animList[iVar10];
            if ((oldObject <= pOVar8) &&
                (pOVar8 <= (Object *)((int)&oldObject->oflags + sizeOfObject)))
            {
              pOVar3 = (Object *)0x0;
              if (pOVar8 != (Object *)0x0)
              {
                pOVar3 = (Object *)((int)pOVar8 + (int)offset);
              }
              *(Object **)(pOVar12->animList + iVar10) = pOVar3;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < pOVar12->numAnims);
        }
        iVar13 = iVar13 + 1;
        p_Var2 = (_ObjectTracker *)(p_Var1->name + iVar13);
      } while (iVar13 < p_Var1->numObjectsUsing);
    }
    OBTABLE_ChangeObjectAccessPointers(oldObject, newObject);
    if ((((newObject->oflags & 0x8000000U) != 0) && (newObject->relocList != (u_long *)0x0)) &&
        (newObject->relocModule != (void *)0x0))
    {
      RELMOD_RelocModulePointers((int)newObject->relocModule, (int)offset, (int *)newObject->relocList);
    }
    instance = (gameTrackerX.instanceList)->first;
    while (instance != (_Instance *)0x0)
    {
      if (instance->object == oldObject)
      {
        instance->object = newObject;
        if ((instance->hModelList != (_HModel *)0x0) && (iVar13 = 0, 0 < newObject->numModels))
        {
          iVar10 = 0;
          do
          {
            p_Var6 = instance->hModelList;
            iVar11 = 0;
            if (0 < *(int *)((int)&p_Var6->numHPrims + iVar10))
            {
              do
              {
                iVar4 = iVar11 * 8 + *(int *)((int)&p_Var6->hPrimList + iVar10);
                iVar9 = *(int *)(iVar4 + 4);
                iVar7 = 0;
                if (iVar9 != 0)
                {
                  iVar7 = (int)&offset->oflags + iVar9;
                }
                *(int *)(iVar4 + 4) = iVar7;
                p_Var6 = instance->hModelList;
                iVar11 = iVar11 + 1;
              } while (iVar11 < p_Var6[iVar13].numHPrims);
            }
            iVar13 = iVar13 + 1;
            iVar10 = iVar10 + 8;
          } while (iVar13 < instance->object->numModels);
        }
        STREAM_RelocateInstance(instance, (long)offset);
      }
      pOVar12 = (Object *)instance->data;
      if ((oldObject <= pOVar12) && (pOVar12 <= (Object *)((int)&oldObject->oflags + sizeOfObject)))
      {
        pvVar5 = (void *)0x0;
        if (pOVar12 != (Object *)0x0)
        {
          pvVar5 = (void *)((int)pOVar12 + (int)offset);
        }
        instance->data = pvVar5;
      }
      instance = instance->next;
    }
  }
  OBTABLE_RelocateObjectTune(newObject, (long)offset);
  if ((newObject->oflags2 & 0x20000000U) != 0)
  {
    RelocateSpotLights(oldObject, newObject, sizeOfObject);
  }
  return;
}

void STREAM_UpdateInstanceCollisionInfo(_HModel *oldHModel, _HModel *newHModel)

{
  _Instance *p_Var1;

  p_Var1 = (gameTrackerX.instanceList)->first;
  while (p_Var1 != (_Instance *)0x0)
  {
    if (p_Var1->hModelList == oldHModel)
    {
      p_Var1->hModelList = newHModel;
    }
    p_Var1 = p_Var1->next;
  }
  return;
}

void STREAM_LoadMainVram(GameTracker *gameTracker, char *baseAreaName, _StreamUnit *streamUnit)

{
  short sVar1;
  u_char *retData;
  Level *pLVar2;
  char acStack176[80];
  char acStack96[80];

  pLVar2 = streamUnit->level;
  STREAM_FillOutFileNames(gameTracker->baseAreaName, acStack176, acStack96, (char *)0x0);
  retData = (u_char *)MEMPACK_Malloc((int)(pLVar2->vramSize).w * 2 + 0x14, '#');
  *(u_char **)(retData + 4) = retData + 5;
  *retData = 0;
  *(short *)(retData + 1) = (pLVar2->vramSize).x + 0x200;
  *(short *)((int)retData + 6) = (pLVar2->vramSize).y;
  *(short *)(retData + 2) = (pLVar2->vramSize).w;
  sVar1 = (pLVar2->vramSize).h;
  M_TrackClutUpdate = 0;
  *(undefined2 *)(retData + 3) = 0;
  *(undefined2 *)((int)retData + 0xe) = 0;
  *(short *)((int)retData + 10) = sVar1;
  LOAD_NonBlockingBinaryLoad(acStack96, VRAM_TransferBufferToVram, retData, streamUnit);
  return;
}

void STREAM_MoveIntoNewStreamUnit(void)

{
  (gameTrackerX.playerInstance)->currentStreamUnitID = gameTrackerX.moveRazielToStreamID;
  INSTANCE_UpdateFamilyStreamUnitID(gameTrackerX.playerInstance);
  GAMELOOP_LevelLoadAndInit(gameTrackerX.S_baseAreaName, &gameTrackerX, (int)gameTrackerX.toSignal,
                            (int)gameTrackerX.fromSignal);
  gameTrackerX.SwitchToNewStreamUnit = 0;
  if (gameTrackerX.SwitchToNewWarpIndex != -1)
  {
    SndPlayVolPan(0x184, 0x7f, 0x40, 0);
    CurrentWarpNumber = (long)gameTrackerX.SwitchToNewWarpIndex;
  }
  return;
}

_StreamUnit *
LoadLevels(GameTracker *gameTracker, char *baseAreaName, StreamUnitPortal *streamPortal, int loadnext)

{
  int iVar1;
  int iVar2;
  _StreamUnit *streamUnit;
  short fogNear;
  code *retFunc;
  short fogFar;
  int iVar3;
  long lVar4;
  char acStack112[80];

  lVar4 = -1;
  if (streamPortal != (StreamUnitPortal *)0x0)
  {
    lVar4 = streamPortal->streamID;
  }
  iVar3 = 0;
  iVar1 = 0;
  while (true)
  {
    streamUnit = (_StreamUnit *)((int)&StreamTracker.StreamList[0].StreamUnitID + iVar1);
    if ((*(short *)((int)&StreamTracker.StreamList[0].used + iVar1) != 0) &&
        (iVar2 = strcpy(StreamTracker.StreamList[0].baseAreaName + iVar1, baseAreaName), iVar2 == 0))
      break;
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 0x40;
    if (0xf < iVar3)
    {
    LAB_8005ac60:
      if (iVar3 == 0x10)
      {
        iVar3 = 0;
        iVar1 = 0;
        do
        {
          streamUnit = (_StreamUnit *)((int)&StreamTracker.StreamList[0].StreamUnitID + iVar1);
          iVar3 = iVar3 + 1;
          if (*(short *)((int)&StreamTracker.StreamList[0].used + iVar1) == 0)
          {
            STREAM_FillOutFileNames(baseAreaName, acStack112, (char *)0x0, (char *)0x0);
            *(undefined2 *)((int)&StreamTracker.StreamList[0].used + iVar1) = 1;
            strcmp(StreamTracker.StreamList[0].baseAreaName + iVar1, baseAreaName);
            streamUnit->StreamUnitID = lVar4;
            *(u_char *)((int)&StreamTracker.StreamList[0].FrameCount + iVar1) = 0;
            *(undefined2 *)((int)&StreamTracker.StreamList[0].flags + iVar1) = 0;
            if (streamPortal == (StreamUnitPortal *)0x0)
            {
              strcmp(gameTracker->baseAreaName, baseAreaName);
              retFunc = STREAM_LoadLevelReturn;
              gameTracker->StreamUnitID = streamUnit->StreamUnitID;
            }
            else
            {
              retFunc = STREAM_StreamLoadLevelReturn;
              streamPortal->toStreamUnit = (_StreamUnit *)0x0;
            }
            LOAD_NonBlockingBufferedLoad(acStack112, retFunc, (void *)0x0, streamUnit,
                                         (void **)((int)&StreamTracker.StreamList[0].level + iVar1), 2);
            return streamUnit;
          }
          iVar1 = iVar3 * 0x40;
        } while (iVar3 < 0x10);
      }
      return streamUnit;
    }
  }
  fogNear = *(short *)((int)&StreamTracker.StreamList[0].used + iVar1);
  if (fogNear == 3)
  {
    *(undefined2 *)((int)&StreamTracker.StreamList[0].used + iVar1) = 1;
  }
  else
  {
    if (fogNear != 1)
    {
      *(u_char *)((int)&StreamTracker.StreamList[0].FrameCount + iVar1) = 0;
      if (streamPortal == (StreamUnitPortal *)0x0)
      {
        strcmp(gameTracker->baseAreaName, baseAreaName);
        STREAM_SetMainFog(streamUnit);
        gameTracker->StreamUnitID = streamUnit->StreamUnitID;
        gameTracker->level = *(Level **)((int)&StreamTracker.StreamList[0].level + iVar1);
      }
      else
      {
        iVar1 = *(int *)((int)&StreamTracker.StreamList[0].level + iVar1);
        STREAM_ConnectStream(streamUnit);
        if (gameTrackerX.gameData.asmData.MorphType == 0)
        {
          fogNear = *(short *)(iVar1 + 0xa6);
          fogFar = *(short *)(iVar1 + 0xa4);
        }
        else
        {
          fogNear = *(short *)(iVar1 + 0x4a);
          fogFar = *(short *)(iVar1 + 0x48);
        }
        STREAM_GetStreamUnitWithID(streamUnit, fogNear, fogFar);
      }
    }
  }
  goto LAB_8005ac60;
}

void RemoveIntroducedLights(Level *level)

{
  NodeType *node;
  int iVar1;
  int iVar2;

  LIGHT_Restore(gameTrackerX.lightInfo);
  (gameTrackerX.lightInfo)->numSavedColors = 0;
  iVar1 = 0;
  if (0 < level->numSpotLights)
  {
    iVar2 = 0;
    do
    {
      node = (NodeType *)((int)&(level->spotLightList->node).prev + iVar2);
      if ((*(byte *)((int)&node[1].prev + 3) & 0x10) != 0)
      {
        LIST_DeleteFunc(node);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x28;
    } while (iVar1 < level->numSpotLights);
  }
  iVar1 = 0;
  if (0 < level->numPointLights)
  {
    iVar2 = 0;
    do
    {
      node = (NodeType *)((int)&(level->pointLightList->node).prev + iVar2);
      if ((*(byte *)((int)&node[1].prev + 3) & 0x10) != 0)
      {
        LIST_DeleteFunc(node);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 < level->numPointLights);
  }
  return;
}

void STREAM_RemoveInstancesWithIDInInstanceList(_InstanceList *list, long id, Level *level)

{
  _Instance *instance;
  _Instance *p_Var1;

  p_Var1 = list->first;
  while (instance = p_Var1, instance != (_Instance *)0x0)
  {
    p_Var1 = instance->next;
    if (instance->currentStreamUnitID == id)
    {
      COLLIDE_InstanceTerrain(instance, level);
      INSTANCE_ReallyRemoveInstance(list, instance, 0);
    }
    else
    {
      if (instance->birthStreamUnitID == id)
      {
        COLLIDE_InstanceTerrain(instance, level);
        instance->intro = (Intro *)0x0;
      }
    }
  }
  return;
}

void STREAM_MarkUnitNeeded(long streamID)

{
  STracker *pSVar1;
  int iVar2;

  iVar2 = 0;
  pSVar1 = &StreamTracker;
  while ((pSVar1->StreamList[0].used == 0 || (streamID != pSVar1->StreamList[0].StreamUnitID)))
  {
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
    if (0xf < iVar2)
    {
      return;
    }
  }
  pSVar1->StreamList[0].FrameCount = gameTrackerX.displayFrameCount;
  return;
}

void STREAM_DumpObject(_StreamUnit *streamUnit, long doSave)

{
  int *piVar1;
  long lVar2;
  _StreamUnit **pp_Var3;
  Level *pLVar4;
  int iVar5;
  int iVar6;
  u_char **ppuVar7;
  STracker *pSVar8;
  int iVar9;
  char acStack104[80];

  iVar9 = 0;
  pSVar8 = &StreamTracker;
  do
  {
    if (pSVar8->StreamList[0].used == 2)
    {
      piVar1 = (int *)(pSVar8->StreamList[0].level)->terrain->StreamUnits;
      iVar6 = *piVar1;
      iVar5 = 0;
      if (0 < iVar6)
      {
        pp_Var3 = (_StreamUnit **)(piVar1 + 0xb);
        do
        {
          if (*pp_Var3 == streamUnit)
          {
            *pp_Var3 = (_StreamUnit *)0x0;
          }
          iVar5 = iVar5 + 1;
          pp_Var3 = pp_Var3 + 0x17;
        } while (iVar5 < iVar6);
      }
    }
    iVar9 = iVar9 + 1;
    pSVar8 = (STracker *)(pSVar8->StreamList + 1);
  } while (iVar9 < 0x10);
  if ((streamUnit->used == 1) || (streamUnit->used == 3))
  {
    STREAM_FillOutFileNames(streamUnit->baseAreaName, acStack104, (char *)0x0, (char *)0x0);
    LOAD_AbortFileLoad(acStack104, STREAM_StreamLoadObjectAbort);
    streamUnit->used = 0;
  }
  else
  {
    lVar2 = WARPGATE_IsUnitWarpRoom(streamUnit);
    if (lVar2 != 0)
    {
      WARPGATE_RemoveFromArray(streamUnit);
    }
    STREAM_RemoveInstancesWithIDInInstanceList(streamUnit);
    pLVar4 = streamUnit->level;
    iVar9 = 0;
    if (0 < pLVar4->NumberOfSFXMarkers)
    {
      iVar5 = 0;
      do
      {
        ppuVar7 = (u_char **)((int)&pLVar4->SFXMarkerList->soundData + iVar5);
        SOUND_StopInstanceSound(*ppuVar7, (SoundInstance *)(ppuVar7 + 2));
        pLVar4 = streamUnit->level;
        iVar9 = iVar9 + 1;
        iVar5 = iVar5 + 0x24;
      } while (iVar9 < pLVar4->NumberOfSFXMarkers);
    }
    if ((int)streamUnit->sfxFileHandle != 0)
    {
      aadFreeDynamicSfx((int)streamUnit->sfxFileHandle);
    }
    RemoveIntroducedLights(streamUnit->level);
    PLANPOOL_DeleteNodeFromPool(streamUnit->StreamUnitID);
    STREAM_RemoveInstancesWithIDInInstanceList(gameTrackerX.instanceList, streamUnit->StreamUnitID, streamUnit->level);
    if (doSave != 0)
    {
      EVENT_SaveEventsFromLevel(streamUnit->StreamUnitID, streamUnit->level);
      SAVE_HasSavedLevel(streamUnit->StreamUnitID, streamUnit->level);
    }
    MEMPACK_Init((char *)streamUnit->level);
    streamUnit->level = (Level *)0x0;
    streamUnit->used = 0;
  }
  return;
}

void STREAM_DumpAllUnitsNotNeeded(GameTracker *gameTracker)

{
  STracker *streamUnit;
  int iVar1;

  iVar1 = 0;
  streamUnit = &StreamTracker;
  do
  {
    if ((*(short *)streamUnit->StreamList != 0) &&
        (*(u_long *)streamUnit->StreamList != gameTracker->displayFrameCount))
    {
      STREAM_DumpObject((_StreamUnit *)streamUnit, 1);
    }
    iVar1 = iVar1 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar1 < 0x10);
  return;
}

void STREAM_DumpAllLevels(long IDNoRemove, int DoSave)

{
  STracker *streamUnit;
  int iVar1;

  iVar1 = 0;
  streamUnit = &StreamTracker;
  do
  {
    if ((*(short *)streamUnit->StreamList != 0) &&
        (streamUnit->StreamList[0].StreamUnitID != IDNoRemove))
    {
      STREAM_DumpObject((_StreamUnit *)streamUnit, DoSave);
    }
    iVar1 = iVar1 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar1 < 0x10);
  return;
}

void STREAM_LoadCurrentWarpRoom(StreamUnitPortal *streamPortal, _StreamUnit *mainStreamUnit)

{
  long lVar1;
  int iVar2;
  _StreamUnit *p_Var3;

  iVar2 = strcpy(mainStreamUnit->level->worldName, (char *)(&WarpRoomArray + CurrentWarpNumber));
  if (iVar2 == 0)
  {
    WarpGateLoadInfo.loading = '\x03';
    WarpGateLoadInfo.curTime = WarpGateLoadInfo.maxTime;
  }
  p_Var3 = LoadLevels(&gameTrackerX, (char *)(&WarpRoomArray + CurrentWarpNumber), streamPortal, 0);
  lVar1 = CurrentWarpNumber;
  (&WarpRoomArray)[CurrentWarpNumber].streamUnit = p_Var3;
  if (p_Var3 != (_StreamUnit *)0x0)
  {
    streamPortal->toStreamUnit = p_Var3;
    ((&WarpRoomArray)[lVar1].streamUnit)->flags = ((&WarpRoomArray)[lVar1].streamUnit)->flags | 1;
  }
  return;
}

void WARPGATE_RelocateLoadedWarpRooms(_StreamUnit *mainUnit, StreamUnitPortal *streamPortal)

{
  STracker *pSVar1;
  char *baseAreaName;
  int iVar2;

  iVar2 = 0;
  baseAreaName = StreamTracker.StreamList[0].baseAreaName;
  pSVar1 = &StreamTracker;
  do
  {
    if ((pSVar1 != (STracker *)mainUnit) && ((*(u_short *)pSVar1->StreamList & 1) != 0))
    {
      LoadLevels(&gameTrackerX, baseAreaName, streamPortal, 0);
    }
    baseAreaName = baseAreaName + 0x40;
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar2 < 0x10);
  return;
}

long WARPGATE_GetWarpRoomIndex(char *name)

{
  int iVar1;
  int iVar2;
  WarpRoom *s1;

  iVar2 = 0;
  s1 = &WarpRoomArray;
  do
  {
    iVar1 = strcpy((char *)s1, name);
    if (iVar1 == 0)
    {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    s1 = s1 + 1;
  } while (iVar2 < 0xe);
  return -1;
}

void WARPGATE_UpdateAddToArray(_StreamUnit *streamUnit)

{
  long lVar1;

  lVar1 = WARPGATE_GetWarpRoomIndex(streamUnit->baseAreaName);
  if (lVar1 != -1)
  {
    (&WarpRoomArray)[lVar1].streamUnit = streamUnit;
  }
  return;
}

void WARPGATE_RemoveFromArray(_StreamUnit *streamUnit)

{
  long lVar1;

  lVar1 = WARPGATE_GetWarpRoomIndex(streamUnit->baseAreaName);
  if (lVar1 == -1)
  {
    CurrentWarpNumber = 0;
  }
  return;
}

void WARPGATE_IsWarpgateInUse(void)

{
  CurrentWarpNumber = 0;
  WarpGateLoadInfo.warpgate_in_use = 0;
  WarpGateLoadInfo.loading = '\0';
  WarpGateLoadInfo.blocked = '\0';
  WarpGateLoadInfo.fadeValue = 0x1000;
  WarpGateLoadInfo.curTime = 0;
  WarpGateLoadInfo.maxTime = 0xf000;
  WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
  return;
}

void WARPGATE_EndUsingWarpgate(void)

{
  if (WarpGateLoadInfo.warpgate_in_use == 0)
  {
    SndPlayVolPan(0x16f, 0x7f, 0x40, 0);
  }
  WarpGateLoadInfo.warpgate_in_use = 1;
  return;
}

void WARPGATE_IsWarpgateUsable(void)

{
  if (WarpGateLoadInfo.warpgate_in_use == 1)
  {
    SndPlayVolPan(0x182, 0x7f, 0x40, 0);
  }
  WarpGateLoadInfo.warpgate_in_use = 0;
  return;
}

int WARPGATE_IsWarpgateInUse(void)

{
  return WarpGateLoadInfo.warpgate_in_use;
}

int WARPGATE_IsWarpgateActive(void)

{
  return (u_int)(WarpGateLoadInfo.loading != '\0');
}

int WARPGATE_IsWarpgateSpectral(void)

{
  return (u_int)(WarpGateLoadInfo._4_2_ == 4);
}

int WARPGATE_StartUsingWarpgate(void)

{
  int iVar1;

  iVar1 = strcpy((char *)(&WarpRoomArray + CurrentWarpNumber), "under3");
  return (u_int)(iVar1 == 0);
}

void WARPGATE_Init(_StreamUnit *streamUnit)

{
  int iVar1;
  short *psVar2;
  Level *pLVar3;

  pLVar3 = streamUnit->level;
  streamUnit->flags = streamUnit->flags | 1;
  if ((pLVar3->PuzzleInstances != (EventPointers *)0x0) &&
      (iVar1 = 0, 0 < pLVar3->PuzzleInstances->numPuzzles))
  {
    do
    {
      psVar2 = (short *)pLVar3->PuzzleInstances->eventInstances[iVar1];
      if (*psVar2 == 1)
      {
        if ((gameTrackerX.streamFlags & 0x400000U) != 0)
        {
          psVar2[3] = 1;
        }
        if (*(short *)(pLVar3->PuzzleInstances->eventInstances[iVar1] + 6) != 1)
        {
          return;
        }
        streamUnit->flags = streamUnit->flags | 8;
        return;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < pLVar3->PuzzleInstances->numPuzzles);
  }
  return;
}

long WARPGATE_IsUnitWarpRoom(_StreamUnit *streamUnit)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  int iVar4;

  iVar2 = 0;
  piVar1 = (int *)streamUnit->level->terrain->StreamUnits;
  lVar3 = 0;
  iVar4 = *piVar1;
  piVar1 = piVar1 + 1;
  if (0 < iVar4)
  {
    do
    {
      if ((*(u_short *)((int)piVar1 + 0x1e) & 1) != 0)
      {
        lVar3 = 1;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0x17;
    } while (iVar2 < iVar4);
  }
  return lVar3;
}

void WARPGATE_FixUnit(_StreamUnit *streamUnit)

{
  long lVar1;

  lVar1 = WARPGATE_IsUnitWarpRoom(streamUnit);
  if (lVar1 != 0)
  {
    WARPGATE_Init(streamUnit);
  }
  return;
}

void STREAM_MarkWarpUnitsNeeded(void)

{
  STracker *pSVar1;
  int iVar2;

  iVar2 = 0;
  pSVar1 = &StreamTracker;
  do
  {
    if ((pSVar1->StreamList[0].flags & 1U) != 0)
    {
      pSVar1->StreamList[0].FrameCount = gameTrackerX.displayFrameCount;
    }
    iVar2 = iVar2 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar2 < 0x10);
  return;
}

long WARPGATE_IncrementIndex(void)

{
  int iVar1;

  if (WarpGateLoadInfo.loading == '\x04')
  {
    SndPlayVolPan(0x183, 0x7f, 0x40, 0);
    WarpGateLoadInfo.loading = '\x01';
    WarpGateLoadInfo.curTime = 0;
    (WarpGateLoadInfo.warpFaceInstance)->fadeValue = 0x1000;
    WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
    (&WarpRoomArray)[CurrentWarpNumber].streamUnit = (_StreamUnit *)0x0;
    CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
    iVar1 = strcpy(gameTrackerX.baseAreaName, (char *)(&WarpRoomArray + CurrentWarpNumber));
    if (iVar1 == 0)
    {
      CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
    }
    hud_warp_arrow_flash = -0x2000;
  }
  return 1;
}

void WARPGATE_CalcWarpFade(int timeInc)

{
  int iVar1;

  (WarpGateLoadInfo.warpFaceInstance)->fadeValue = WarpGateLoadInfo.fadeValue;
  WarpGateLoadInfo.maxTime;
  WarpGateLoadInfo.fadeValue = (short)iVar1;
  if (0x1000 < iVar1 * 0x10000 >> 0x10)
  {
    WarpGateLoadInfo.fadeValue = 0x1000;
  }
  if (WarpGateLoadInfo.fadeValue < 0)
  {
    WarpGateLoadInfo.fadeValue = 0;
  }
  WarpGateLoadInfo.curTime = WarpGateLoadInfo.curTime + timeInc;
  return;
}

long WARPGATE_DecrementIndex(void)

{
  int iVar1;

  if (WarpGateLoadInfo.loading == '\x04')
  {
    SndPlayVolPan(0x183, 0x7f, 0x40, 0);
    WarpGateLoadInfo.loading = '\x01';
    WarpGateLoadInfo.curTime = 0;
    (WarpGateLoadInfo.warpFaceInstance)->fadeValue = 0x1000;
    iVar1 = CurrentWarpNumber + -1;
    WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
    (&WarpRoomArray)[CurrentWarpNumber].streamUnit = (_StreamUnit *)0x0;
    CurrentWarpNumber = iVar1;
    if (iVar1 < 0)
    {
      CurrentWarpNumber = 0xd;
    }
    iVar1 = strcpy(gameTrackerX.baseAreaName, (char *)(&WarpRoomArray + CurrentWarpNumber));
    if ((iVar1 == 0) && (CurrentWarpNumber = CurrentWarpNumber + -1, CurrentWarpNumber < 0))
    {
      CurrentWarpNumber = 0xd;
    }
    hud_warp_arrow_flash = 0x2000;
  }
  return 1;
}

void PreloadAllConnectedUnits(GameTracker *gameTracker, _StreamUnit *streamUnit, _SVector *offset)

{
  char *pcVar1;
  int iVar2;
  int *__src;
  StreamUnitPortal *streamPortal;
  int iVar3;
  u_short *puVar4;
  int iVar5;
  char acStack48[16];

  gameTracker->displayFrameCount = gameTracker->displayFrameCount + 1;
  __src = (int *)streamUnit->level->terrain->StreamUnits;
  iVar3 = 0;
  iVar5 = *__src;
  __src = __src + 1;
  if (0 < iVar5)
  {
    do
    {
      strcmp(acStack48, (char *)__src);
      pcVar1 = strchr(acStack48, 0x2c);
      if (pcVar1 != (char *)0x0)
      {
        *pcVar1 = '\0';
      }
      iVar2 = strcpy(acStack48, "warpgate");
      if (iVar2 == 0)
      {
        STREAM_MarkWarpUnitsNeeded();
      }
      else
      {
        STREAM_MarkUnitNeeded(__src[5]);
      }
      iVar3 = iVar3 + 1;
      __src = __src + 0x17;
    } while (iVar3 < iVar5);
  }
  iVar3 = 0;
  STREAM_MarkUnitNeeded(streamUnit->StreamUnitID);
  STREAM_DumpAllUnitsNotNeeded(gameTracker);
  STREAM_RemoveAllObjectsNotInUse(gameTracker);
  EVENT_RelocateInstanceList(streamUnit->level, offset);
  MEMPACK_DoGarbageCollection();
  __src = (int *)streamUnit->level->terrain->StreamUnits;
  iVar5 = *__src;
  streamPortal = (StreamUnitPortal *)(__src + 1);
  if (0 < iVar5)
  {
    puVar4 = (u_short *)((int)__src + 0x22);
    do
    {
      strcmp(acStack48, (char *)streamPortal);
      pcVar1 = strchr(acStack48, 0x2c);
      if (pcVar1 != (char *)0x0)
      {
        *pcVar1 = '\0';
        iVar2 = strcpy(acStack48, "warpgate");
        if (iVar2 == 0)
        {
          *(u_char *)(puVar4 + 5) = 0;
          *puVar4 = *puVar4 | 1;
          WARPGATE_RelocateLoadedWarpRooms(streamUnit, streamPortal);
        }
        else
        {
          LoadLevels(gameTracker, acStack48, streamPortal, 1);
        }
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 0x2e;
      streamPortal = streamPortal + 1;
    } while (iVar3 < iVar5);
  }
  return;
}

void CAMERA_Restore(Level *level, _SVector *offset)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  _Terrain *p_Var5;
  int iVar6;

  RelocateTerrain(level->terrain, offset);
  RelocateVMObjects(level->vmobjectList, level->numVMObjects, offset);
  FX_Relocate(level->spotLightList, level->numSpotLights, offset);
  FX_RelocateFXPointers(level->pointLightList, level->numPointLights, offset);
  RelocateBGObjects(level->bgObjectList, level->numBGObjects, offset);
  RelocateLevel((_CameraKey *)level->cameraList, level->numCameras, offset);
  RelocateSavedCameras(&theCamera, level, offset);
  level->deathZ = level->deathZ + (int)offset->z;
  RelocatePlanMarkers(level->PlanMarkerList, level->NumberOfPlanMarkers, offset);
  RelocateCameras(level->SFXMarkerList, level->NumberOfSFXMarkers, offset);
  iVar4 = level->waterZLevel;
  if ((iVar4 != -0x7fff) && (iVar4 != 0x7fff))
  {
    level->waterZLevel = iVar4 + offset->z;
  }
  p_Var5 = level->terrain;
  iVar4 = 0;
  if (0 < p_Var5->numBSPTrees)
  {
    iVar6 = 0;
    do
    {
      sVar1 = offset->y;
      sVar2 = offset->z;
      iVar3 = (int)&p_Var5->BSPTreeArray->bspRoot + iVar6;
      *(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + offset->x;
      *(short *)(iVar3 + 0xe) = *(short *)(iVar3 + 0xe) + sVar1;
      *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + sVar2;
      p_Var5 = level->terrain;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 0x24;
    } while (iVar4 < p_Var5->numBSPTrees);
  }
  return;
}

void RelocateLevel(_CameraKey *cameraList, long numCameras, _SVector *offset)

{
  int iVar1;

  iVar1 = 0;
  if (0 < numCameras)
  {
    do
    {
      cameraList->x = cameraList->x + offset->x;
      cameraList->y = cameraList->y + offset->y;
      cameraList->z = cameraList->z + offset->z;
      cameraList->tx = cameraList->tx + offset->x;
      cameraList->ty = cameraList->ty + offset->y;
      iVar1 = iVar1 + 1;
      cameraList->tz = cameraList->tz + offset->z;
      cameraList = cameraList + 1;
    } while (iVar1 < numCameras);
  }
  return;
}

void RelocateSavedCameras(Camera *camera, Level *level, _SVector *offset)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  Camera *pCVar4;
  Camera *pCVar5;
  int iVar6;
  int iVar7;

  iVar7 = 0;
  if (-1 < camera->stack)
  {
    iVar6 = 0x2a0;
    pCVar4 = camera;
    pCVar5 = camera;
    do
    {
      if ((pCVar4->savedMode[0] == 5) &&
          (psVar3 = (short *)((int)&(camera->core).position.x + iVar6),
           pCVar5->savedCinematic[0].level == level))
      {
        sVar1 = offset->y;
        sVar2 = offset->z;
        *psVar3 = *psVar3 + offset->x;
        psVar3[1] = psVar3[1] + sVar1;
        psVar3[2] = psVar3[2] + sVar2;
        sVar1 = offset->y;
        sVar2 = offset->z;
        psVar3[3] = psVar3[3] + offset->x;
        psVar3[4] = psVar3[4] + sVar1;
        psVar3[5] = psVar3[5] + sVar2;
        sVar1 = offset->y;
        sVar2 = offset->z;
        psVar3[9] = psVar3[9] + offset->x;
        psVar3[10] = psVar3[10] + sVar1;
        psVar3[0xb] = psVar3[0xb] + sVar2;
        sVar1 = offset->y;
        sVar2 = offset->z;
        psVar3[0xc] = psVar3[0xc] + offset->x;
        psVar3[0xd] = psVar3[0xd] + sVar1;
        psVar3[0xe] = psVar3[0xe] + sVar2;
      }
      iVar6 = iVar6 + 0x70;
      pCVar5 = (Camera *)&(pCVar5->core).wcTransform2;
      iVar7 = iVar7 + 1;
      pCVar4 = (Camera *)&(pCVar4->core).position.z;
    } while (iVar7 <= camera->stack);
  }
  return;
}

void EVENT_RelocateInstanceList(Level *level, _SVector *offset)

{
  CAMERA_Restore(level, offset);
  RelocateLevelWithInstances(&gameTrackerX, offset, gameTrackerX.StreamUnitID);
  RelocatePlanPool((PlanningNode *)gameTrackerX.planningPool, offset);
  return;
}

void RelocateTerrain(_Terrain *terrain, _SVector *offset)

{
  char *pcVar1;
  MultiSpline *multi;
  int iVar2;
  int iVar3;

  iVar3 = 0;
  if (0 < terrain->numIntros)
  {
    iVar2 = 0;
    do
    {
      pcVar1 = terrain->introList->name + iVar2;
      *(short *)(pcVar1 + 0x20) = *(short *)(pcVar1 + 0x20) + offset->x;
      pcVar1 = terrain->introList->name + iVar2;
      *(short *)(pcVar1 + 0x22) = *(short *)(pcVar1 + 0x22) + offset->y;
      pcVar1 = terrain->introList->name + iVar2;
      *(short *)(pcVar1 + 0x24) = *(short *)(pcVar1 + 0x24) + offset->z;
      multi = *(MultiSpline **)((int)&terrain->introList->multiSpline + iVar2);
      if (multi != (MultiSpline *)0x0)
      {
        STREAM_AdjustMultiSpline(multi, offset);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x4c;
    } while (iVar3 < terrain->numIntros);
  }
  RelocateStreamPortals((StreamUnitPortal *)(terrain->StreamUnits + 1), *(int *)terrain->StreamUnits, offset);
  return;
}

void RelocateVMObjects(_VMObject *vobjectlist, long numvmobjs, _SVector *offset)

{
  int iVar1;

  iVar1 = 0;
  if (0 < numvmobjs)
  {
    do
    {
      (vobjectlist->position).x = (vobjectlist->position).x + offset->x;
      (vobjectlist->position).y = (vobjectlist->position).y + offset->y;
      iVar1 = iVar1 + 1;
      (vobjectlist->position).z = (vobjectlist->position).z + offset->z;
      vobjectlist = vobjectlist + 1;
    } while (iVar1 < numvmobjs);
  }
  return;
}

void FX_Relocate(SpotLight *spotLightList, long numSpotLights, _SVector *offset)

{
  int iVar1;

  iVar1 = 0;
  if (0 < numSpotLights)
  {
    do
    {
      (spotLightList->position).x = (spotLightList->position).x + offset->x;
      (spotLightList->position).y = (spotLightList->position).y + offset->y;
      (spotLightList->position).z = (spotLightList->position).z + offset->z;
      (spotLightList->centroid).x = (spotLightList->centroid).x + offset->x;
      (spotLightList->centroid).y = (spotLightList->centroid).y + offset->y;
      iVar1 = iVar1 + 1;
      (spotLightList->centroid).z = (spotLightList->centroid).z + offset->z;
      spotLightList = spotLightList + 1;
    } while (iVar1 < numSpotLights);
  }
  return;
}

void FX_RelocateFXPointers(PointLight *PLightList, long numPLights, _SVector *offset)

{
  int iVar1;

  iVar1 = 0;
  if (0 < numPLights)
  {
    do
    {
      (PLightList->position).x = (PLightList->position).x + offset->x;
      (PLightList->position).y = (PLightList->position).y + offset->y;
      iVar1 = iVar1 + 1;
      (PLightList->position).z = (PLightList->position).z + offset->z;
      PLightList = PLightList + 1;
    } while (iVar1 < numPLights);
  }
  return;
}

void RelocateBGObjects(_BGObject *BGObjList, long numBGObjs, _SVector *offset)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;

  iVar5 = 0;
  if (0 < numBGObjs)
  {
    do
    {
      iVar4 = 0;
      if (0 < BGObjList->numVertices)
      {
        iVar3 = 0;
        do
        {
          psVar1 = (short *)((int)&BGObjList->vertexList->x + iVar3);
          *psVar1 = *psVar1 + offset->x;
          iVar2 = (int)&BGObjList->vertexList->x + iVar3;
          *(short *)(iVar2 + 2) = *(short *)(iVar2 + 2) + offset->y;
          iVar3 = (int)&BGObjList->vertexList->x + iVar3;
          *(short *)(iVar3 + 4) = *(short *)(iVar3 + 4) + offset->z;
          iVar4 = iVar4 + 1;
          iVar3 = iVar4 * 8;
        } while (iVar4 < BGObjList->numVertices);
      }
      iVar5 = iVar5 + 1;
      BGObjList = BGObjList + 1;
    } while (iVar5 < numBGObjs);
  }
  return;
}

void RelocatePlanPool(PlanningNode *planPool, _SVector *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short *psVar6;

  sVar1 = offset->x;
  sVar2 = offset->y;
  sVar3 = offset->z;
  iVar5 = PLANAPI_NumNodesInPool(planPool);
  psVar6 = &(planPool->pos).z;
  iVar4 = poolManagementData;
  while (poolManagementData = iVar4, iVar5 != 0)
  {
    iVar5 = iVar5 + -1;
    (planPool->pos).x = (planPool->pos).x + sVar1;
    planPool = planPool + 1;
    psVar6[-1] = psVar6[-1] + sVar2;
    *psVar6 = *psVar6 + sVar3;
    psVar6 = psVar6 + 0xe;
    iVar4 = poolManagementData;
  }
  *(short *)(iVar4 + 2) = *(short *)(iVar4 + 2) + sVar1;
  *(short *)(iVar4 + 6) = *(short *)(iVar4 + 6) + sVar3;
  *(short *)(iVar4 + 4) = *(short *)(iVar4 + 4) + sVar2;
  return;
}

void RelocatePlanMarkers(_PlanMkr *planMkrList, int numPlanMkrs, _SVector *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short *psVar4;

  sVar1 = offset->x;
  sVar2 = offset->y;
  sVar3 = offset->z;
  if (numPlanMkrs != 0)
  {
    psVar4 = &(planMkrList->pos).z;
    do
    {
      numPlanMkrs = numPlanMkrs + -1;
      (planMkrList->pos).x = (planMkrList->pos).x + sVar1;
      planMkrList = planMkrList + 1;
      psVar4[-1] = psVar4[-1] + sVar2;
      *psVar4 = *psVar4 + sVar3;
      psVar4 = psVar4 + 4;
    } while (numPlanMkrs != 0);
  }
  return;
}

void RelocateCameras(_SFXMkr *sfxMkrList, int numSFXMkrs, _SVector *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short *psVar4;

  sVar1 = offset->x;
  sVar2 = offset->y;
  sVar3 = offset->z;
  psVar4 = &(sfxMkrList->pos).z;
  if (numSFXMkrs != 0)
  {
    do
    {
      numSFXMkrs = numSFXMkrs + -1;
      psVar4[-2] = psVar4[-2] + sVar1;
      *psVar4 = *psVar4 + sVar3;
      psVar4[-1] = psVar4[-1] + sVar2;
      psVar4 = psVar4 + 0x12;
    } while (numSFXMkrs != 0);
  }
  return;
}

void STREAM_AdjustMultiSpline(MultiSpline *multi, _SVector *offset)

{
  Spline *pSVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  pSVar1 = multi->positional;
  if ((pSVar1 != (Spline *)0x0) && (iVar4 = 0, 0 < pSVar1->numkeys))
  {
    iVar3 = 0;
    do
    {
      iVar2 = (int)&pSVar1->key->count + iVar3;
      *(short *)(iVar2 + 2) = *(short *)(iVar2 + 2) + offset->x;
      iVar2 = (int)&multi->positional->key->count + iVar3;
      *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + offset->y;
      iVar3 = (int)&multi->positional->key->count + iVar3;
      *(short *)(iVar3 + 6) = *(short *)(iVar3 + 6) + offset->z;
      pSVar1 = multi->positional;
      iVar4 = iVar4 + 1;
      iVar3 = iVar4 * 0x20;
    } while (iVar4 < pSVar1->numkeys);
  }
  return;
}

void RelocateInstances(GameTracker *gameTracker, _Instance *instance, _SVector *offset)

{
  STREAM_OffsetInstancePosition(gameTracker, instance, offset, 1);
  INSTANCE_Query(instance, (int)&DAT_00100008, (int)offset);
  return;
}

void STREAM_OffsetInstancePosition(GameTracker *gameTracker, _Instance *instance, _SVector *offset, int streamSignalFlag)

{
  (instance->position).x = (instance->position).x + offset->x;
  (instance->position).y = (instance->position).y + offset->y;
  (instance->position).z = (instance->position).z + offset->z;
  (instance->oldPos).x = (instance->oldPos).x + offset->x;
  (instance->oldPos).y = (instance->oldPos).y + offset->y;
  (instance->oldPos).z = (instance->oldPos).z + offset->z;
  (instance->shadowPosition).x = (instance->shadowPosition).x + offset->x;
  (instance->shadowPosition).y = (instance->shadowPosition).y + offset->y;
  (instance->shadowPosition).z = (instance->shadowPosition).z + offset->z;
  COLLIDE_MoveAllTransforms(instance, (SVECTOR *)offset);
  COLLIDE_UpdateAllTransforms(instance, (_Position *)offset);
  if (instance == theCamera.focusInstance)
  {
    CAMERA_Relocate(&theCamera, offset, streamSignalFlag);
  }
  return;
}

void STREAM_SetInstancePosition(GameTracker *gameTracker, _Instance *instance, evPositionData *data)

{
  _SVector local_10;

  local_10.x = data->x - (instance->position).x;
  local_10.y = data->y - (instance->position).y;
  local_10.z = data->z - (instance->position).z;
  STREAM_OffsetInstancePosition(gameTracker, instance, &local_10, 0);
  return;
}

void RelocateLevelWithInstances(GameTracker *gameTracker, _SVector *offset, long StreamUnitID)

{
  _Instance *instance;

  instance = gameTracker->instanceList->first;
  while (instance != (_Instance *)0x0)
  {
    RelocateInstances(gameTracker, instance, offset);
    instance = instance->next;
  }
  CAMERA_Relocate(offset);
  return;
}

void RelocateStreamPortals(StreamUnitPortal *StreamUnitList, int NumStreamUnits, _SVector *offset)

{
  StreamUnitPortal *pSVar1;
  int iVar2;
  int iVar3;

  iVar3 = 0;
  if (0 < NumStreamUnits)
  {
    do
    {
      StreamUnitList->maxx = StreamUnitList->maxx + offset->x;
      StreamUnitList->maxy = StreamUnitList->maxy + offset->y;
      StreamUnitList->maxz = StreamUnitList->maxz + offset->z;
      StreamUnitList->minx = StreamUnitList->minx + offset->x;
      iVar2 = 0;
      StreamUnitList->miny = StreamUnitList->miny + offset->y;
      StreamUnitList->minz = StreamUnitList->minz + offset->z;
      pSVar1 = StreamUnitList;
      do
      {
        pSVar1->t1[0].x = pSVar1->t1[0].x + offset->x;
        pSVar1->t1[0].y = pSVar1->t1[0].y + offset->y;
        iVar2 = iVar2 + 1;
        pSVar1->t1[0].z = pSVar1->t1[0].z + offset->z;
        pSVar1 = (StreamUnitPortal *)(pSVar1->tolevelname + 8);
      } while (iVar2 < 3);
      iVar2 = 0;
      pSVar1 = StreamUnitList;
      do
      {
        pSVar1->t2[0].x = pSVar1->t2[0].x + offset->x;
        pSVar1->t2[0].y = pSVar1->t2[0].y + offset->y;
        iVar2 = iVar2 + 1;
        pSVar1->t2[0].z = pSVar1->t2[0].z + offset->z;
        pSVar1 = (StreamUnitPortal *)(pSVar1->tolevelname + 8);
      } while (iVar2 < 3);
      iVar3 = iVar3 + 1;
      StreamUnitList = StreamUnitList + 1;
    } while (iVar3 < NumStreamUnits);
  }
  return;
}

void STREAM_PackVRAMObject(_ObjectTracker *objectTracker)

{
  undefined2 uVar1;
  long lVar2;
  u_char *retData;
  void *pvVar3;
  char acStack80[64];

  if (((objectTracker->object->vramSize).x == -1) ||
      (lVar2 = VRAM_GetObjectVramSpace(&objectTracker->object->vramSize, objectTracker), lVar2 == 0))
  {
    objectTracker->vramBlock = (void *)0x0;
  }
  else
  {
    pvVar3 = objectTracker->vramBlock;
    if (pvVar3 != (void *)0x0)
    {
      AdjustVramCoordsObject(0x200, 0, (int)*(short *)((int)pvVar3 + 0xc), (int)*(short *)((int)pvVar3 + 0xe),
                             objectTracker->object);
    }
    sprintf(acStack80, "\\kain2\\object\\%s\\%s.crm");
    retData = (u_char *)MEMPACK_Malloc((int)*(short *)((int)pvVar3 + 0x10) * 2 + 0x14, '#');
    *(u_char **)(retData + 4) = retData + 5;
    *retData = 0;
    *(undefined2 *)(retData + 1) = *(undefined2 *)((int)pvVar3 + 0xc);
    *(undefined2 *)((int)retData + 6) = *(undefined2 *)((int)pvVar3 + 0xe);
    *(undefined2 *)(retData + 2) = *(undefined2 *)((int)pvVar3 + 0x10);
    uVar1 = *(undefined2 *)((int)pvVar3 + 0x12);
    *(undefined2 *)(retData + 3) = 0;
    *(undefined2 *)((int)retData + 0xe) = 0;
    *(undefined2 *)((int)retData + 10) = uVar1;
    LOAD_NonBlockingBinaryLoad(acStack80, VRAM_TransferBufferToVram, retData, (void *)0x0);
  }
  return;
}

void MORPH_SetupInstanceListFlags(GameTracker *gameTracker, _Instance *instance)

{
  long lVar1;
  u_int uVar2;

  if ((instance->object->oflags & 0x80000U) != 0)
  {
    return;
  }
  if ((gameTracker->gameData).asmData.MorphType == 0)
  {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) == 0)
    {
      uVar2 = uVar2 & 0xebffffff;
      goto LAB_8005c8fc;
    }
  }
  else
  {
    uVar2 = instance->flags2;
    if ((uVar2 & 0x8000000) != 0)
    {
      uVar2 = uVar2 & 0xebffffff;
      goto LAB_8005c8fc;
    }
  }
  instance->flags2 = uVar2 | 0x10000000;
  lVar1 = MEMPACK_ReportMemory((char *)instance->object);
  if (lVar1 == 0)
  {
    return;
  }
  if ((instance->object->oflags2 & 0x2000000U) == 0)
  {
    if (instance->LinkParent == (_Instance *)0x0)
    {
      return;
    }
    if ((instance->LinkParent->object->oflags2 & 0x2000000U) == 0)
    {
      return;
    }
  }
  uVar2 = instance->flags2 | 0x4000000;
LAB_8005c8fc:
  instance->flags2 = uVar2;
  return;
}

void MORPH_InMorphInstanceListFlags(GameTracker *gameTracker)

{
  _Instance *instance;

  instance = gameTracker->instanceList->first;
  while (instance != (_Instance *)0x0)
  {
    MORPH_SetupInstanceListFlags(gameTracker, instance);
    instance = instance->next;
  }
  return;
}

void MORPH_SetupInstanceFlags(GameTracker *gameTracker)

{
  _Instance *p_Var1;

  p_Var1 = gameTracker->instanceList->first;
  while (p_Var1 != (_Instance *)0x0)
  {
    if ((p_Var1->flags2 & 0x4000000U) != 0)
    {
      p_Var1->flags2 = p_Var1->flags2 & 0xefffffff;
    }
    p_Var1->flags2 = p_Var1->flags2 & 0xfbffffff;
    p_Var1 = p_Var1->next;
  }
  return;
}

void MORPH_InMorphDoFadeValues(GameTracker *gameTracker)

{
  short sVar1;

 1000);
 if ((gameTracker->gameData).asmData.MorphType == 0)
 {
   gameTracker->spectral_fadeValue = sVar1;
   gameTracker->material_fadeValue = 0x1000 - sVar1;
   return;
 }
 gameTracker->spectral_fadeValue = 0x1000 - sVar1;
 gameTracker->material_fadeValue = sVar1;
 return;
}

void MORPH_UpdateTimeMult(void)

{
  int iVar1;
  u_int uVar2;

  uVar2 = (u_int)(u_short)gameTrackerX.gameData.asmData.MorphTime;
  if (gameTrackerX.gameData.asmData.MorphTime != 1000)
  {
    iVar1 = uVar2 - 0x2ee;
    if (gameTrackerX.gameData.asmData.MorphType == 0)
    {
      if (0xfa < gameTrackerX.gameData.asmData.MorphTime)
      {
        uVar2 = 0xfa;
      }
      iVar1 = 0xfa - uVar2;
    }
    else
    {
      if (iVar1 * 0x10000 < 0)
      {
        iVar1 = 0;
      }
    }
    gameTrackerX.materialTimeMult =
 0xfa) * 0x10000 >> 0x10) *
              0x10) >> 0x10;
    if (gameTrackerX.materialTimeMult == 0)
    {
      gameTrackerX.materialTimeMult = 1;
    }
    uVar2 = (u_int)(u_short)gameTrackerX.gameData.asmData.MorphTime;
    if (gameTrackerX.gameData.asmData.MorphType == 0)
    {
      iVar1 = uVar2 - 0x2ee;
      if (iVar1 * 0x10000 < 0)
      {
        iVar1 = 0;
      }
    }
    else
    {
      if (0xfa < gameTrackerX.gameData.asmData.MorphTime)
      {
        uVar2 = 0xfa;
      }
      iVar1 = 0xfa - uVar2;
    }
    gameTrackerX.spectralTimeMult =
 0xfa) * 0x10000 >> 0x10) *
              0x10) >> 0x10;
    if (gameTrackerX.spectralTimeMult == 0)
    {
      gameTrackerX.spectralTimeMult = 1;
    }
    return;
  }
  if (gameTrackerX.gameData.asmData.MorphType == 0)
  {
    gameTrackerX.spectralTimeMult = 0;
    gameTrackerX.materialTimeMult = gameTrackerX.globalTimeMult;
    return;
  }
  gameTrackerX.spectralTimeMult = gameTrackerX.globalTimeMult;
  gameTrackerX.materialTimeMult = 0;
  return;
}

void MORPH_UpdateTextures(Level *BaseLevel)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  u_short uVar4;
  short sVar5;
  _Terrain *p_Var6;
  _TVertex *p_Var7;
  u_int *puVar8;
  int iVar9;
  byte *pbVar10;
  u_char *puVar11;
  u_int uVar12;
  u_short *puVar13;
  _MorphColor *p_Var14;
  SpotLight *pSVar15;
  u_char *puVar16;
  Intro *pIVar17;
  u_short *puVar18;
  long lVar19;
  int iVar20;
  u_int uVar21;
  int iVar22;
  short *psVar23;
  _TVertex *p_Var24;
  PointLight *pPVar25;
  _MorphVertex *p_Var26;
  long lVar27;
  u_char uVar28;
  u_char uVar29;
  _Instance *instance;
  u_int local_20;
  u_int local_1c;
  u_int local_18;
  u_int local_14;
  u_char local_10;

  p_Var6 = BaseLevel->terrain;
  puVar18 = (u_short *)p_Var6->morphNormalIdx;
  iVar22 = p_Var6->numFaces;
  if (0 < iVar22)
  {
    puVar13 = &p_Var6->faceList->normal;
    do
    {
      uVar4 = *puVar13;
      iVar22 = iVar22 + -1;
      *puVar13 = *puVar18;
      *puVar18 = uVar4;
      puVar18 = puVar18 + 1;
      puVar13 = puVar13 + 6;
    } while (0 < iVar22);
    p_Var6 = BaseLevel->terrain;
  }
  p_Var26 = p_Var6->MorphDiffList;
  if (p_Var26 != (_MorphVertex *)0x0)
  {
    sVar3 = p_Var26->vindex;
    sVar5 = p_Var26->vindex;
    psVar23 = &p_Var26->vindex;
    while (-1 < sVar3)
    {
      p_Var7 = BaseLevel->terrain->vertexList + sVar5;
      (p_Var7->vertex).x = psVar23[1] + p_Var26->x;
      (p_Var7->vertex).y = psVar23[2] + psVar23[-2];
      psVar1 = psVar23 + 3;
      psVar2 = psVar23 + -1;
      psVar23 = psVar23 + 7;
      (p_Var7->vertex).z = *psVar1 + *psVar2;
      sVar3 = *psVar23;
      sVar5 = *psVar23;
      p_Var26 = p_Var26 + 1;
    }
  }
  p_Var6 = BaseLevel->terrain;
  p_Var14 = p_Var6->MorphColorList;
  if (p_Var14 != (_MorphColor *)0x0)
  {
    p_Var7 = p_Var6->vertexList;
    p_Var24 = p_Var7 + p_Var6->numVertices;
    pbVar10 = &p_Var7->b0;
    while (p_Var7 < p_Var24)
    {
      pbVar10[-2] = (byte)(((u_int) * (byte *)&p_Var14->morphColor15 & 0x1f) << 3);
      p_Var7 = p_Var7 + 1;
      pbVar10[-1] = (byte)((u_short)p_Var14->morphColor15 >> 2) & 0xf8;
      puVar18 = (u_short *)&p_Var14->morphColor15;
      p_Var14 = p_Var14 + 1;
      *pbVar10 = (byte)(*puVar18 >> 7) & 0xf8;
      pbVar10 = pbVar10 + 0xc;
    }
  }
  RemoveIntroducedLights(BaseLevel);
  lVar19 = BaseLevel->numSpotSpecturalLights;
  pSVar15 = BaseLevel->spotSpecturalLightList;
  p_Var6 = BaseLevel->terrain;
  BaseLevel->numSpotSpecturalLights = BaseLevel->numSpotLights;
  lVar27 = BaseLevel->numPointLights;
  BaseLevel->spotSpecturalLightList = BaseLevel->spotLightList;
  pPVar25 = BaseLevel->pointLightList;
  BaseLevel->numSpotLights = lVar19;
  BaseLevel->spotLightList = pSVar15;
  BaseLevel->numPointLights = BaseLevel->numPointSpecturalLights;
  BaseLevel->pointLightList = BaseLevel->pointSpecturalLightList;
  BaseLevel->numPointSpecturalLights = lVar27;
  BaseLevel->pointSpecturalLightList = pPVar25;
  iVar22 = 0;
  if (0 < p_Var6->numBSPTrees)
  {
    iVar20 = 0;
    do
    {
      puVar8 = (u_int *)((int)&p_Var6->BSPTreeArray->bspRoot + iVar20);
      puVar16 = (u_char *)*puVar8;
      puVar11 = puVar16 + 7;
      if (puVar16 < (u_char *)puVar8[1])
      {
        do
        {
          uVar28 = *puVar16;
          local_1c = puVar16[1];
          uVar29 = puVar11[1];
          *puVar16 = *puVar11;
          puVar16[1] = uVar29;
          *puVar11 = uVar28;
          puVar11[1] = local_1c;
          puVar16 = puVar16 + 0xb;
          puVar11 = puVar11 + 0xb;
        } while (puVar16 < *(u_char **)((int)&p_Var6->BSPTreeArray->startLeaves + iVar20));
      }
      iVar9 = (int)&p_Var6->BSPTreeArray->bspRoot + iVar20;
      puVar16 = *(u_char **)(iVar9 + 4);
      if (puVar16 < *(u_char **)(iVar9 + 8))
      {
        puVar11 = puVar16 + 7;
        do
        {
          uVar28 = *puVar16;
          local_1c = puVar16[1];
          uVar29 = puVar11[4];
          *puVar16 = puVar11[3];
          puVar16[1] = uVar29;
          puVar11[3] = uVar28;
          puVar11[4] = local_1c;
          uVar28 = puVar11[-3];
          local_14 = puVar11[-2];
          local_10 = puVar11[-1];
          puVar11[-3] = *puVar11;
          puVar11[-2] = puVar11[1];
          puVar11[-1] = puVar11[2];
          *puVar11 = uVar28;
          puVar11[1] = local_14;
          puVar11[2] = local_10;
          puVar16 = puVar16 + 0xc;
          puVar11 = puVar11 + 0xc;
        } while (puVar16 < *(u_char **)((int)&p_Var6->BSPTreeArray->endLeaves + iVar20));
      }
      iVar22 = iVar22 + 1;
      iVar20 = iVar20 + 0x24;
    } while (iVar22 < p_Var6->numBSPTrees);
  }
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0)
  {
    pIVar17 = instance->intro;
    if ((pIVar17 != (Intro *)0x0) &&
        (((*(int *)&pIVar17->spectralPosition != 0 || ((pIVar17->spectralPosition).z != 0)) &&
          ((instance->flags2 & 8U) == 0))))
    {
      local_18 = *(u_int *)&instance->position;
      uVar12 = (u_int)(u_short)(instance->position).z;
      local_14 = local_14 & 0xffff0000 | uVar12;
      (instance->position).x = (pIVar17->position).x + (pIVar17->spectralPosition).x;
      (instance->position).y = (pIVar17->position).y + (pIVar17->spectralPosition).y;
      (instance->position).z = (pIVar17->position).z + (pIVar17->spectralPosition).z;
      uVar21 = (u_int)(u_short)(instance->position).x - (local_18 & 0xffff);
      iVar22 = (u_int)(u_short)(instance->position).y - (local_18 >> 0x10);
      local_20 = uVar21 & 0xffff | iVar22 * 0x10000;
      uVar12 = (u_short)(instance->position).z - uVar12;
      local_1c = local_1c & 0xffff0000 | uVar12 & 0xffff;
      if (((int)(uVar21 * 0x10000) >> 0x10) + (iVar22 * 0x10000 >> 0x10) +
              ((int)(uVar12 * 0x10000) >> 0x10) !=
          0)
      {
        COLLIDE_MoveAllTransforms(instance, (SVECTOR *)&local_20);
      }
    }
    instance = instance->next;
  }
  return;
}

void MORPH_BringBackNormals(Level *BaseLevel)

{
  short *psVar1;
  short sVar2;
  u_short uVar3;
  short sVar4;
  _Terrain *p_Var5;
  _TVertex *p_Var6;
  u_int *puVar7;
  int iVar8;
  u_char *puVar9;
  Intro *pIVar10;
  u_int uVar11;
  u_short *puVar12;
  _MorphVertex *p_Var13;
  byte *pbVar14;
  SpotLight *pSVar15;
  u_char *puVar16;
  u_short *puVar17;
  long lVar18;
  int iVar19;
  u_int uVar20;
  int iVar21;
  short *psVar22;
  _TVertex *p_Var23;
  PointLight *pPVar24;
  long lVar25;
  u_char uVar26;
  u_char uVar27;
  _Instance *instance;
  u_int local_20;
  u_int local_1c;
  u_int local_18;
  u_int local_14;
  u_char local_10;

  p_Var5 = BaseLevel->terrain;
  puVar17 = (u_short *)p_Var5->morphNormalIdx;
  iVar21 = p_Var5->numFaces;
  puVar12 = &p_Var5->faceList->normal;
  if (0 < iVar21)
  {
    do
    {
      uVar3 = *puVar12;
      iVar21 = iVar21 + -1;
      *puVar12 = *puVar17;
      *puVar17 = uVar3;
      puVar17 = puVar17 + 1;
      puVar12 = puVar12 + 6;
    } while (0 < iVar21);
    p_Var5 = BaseLevel->terrain;
  }
  p_Var13 = p_Var5->MorphDiffList;
  if (p_Var13 != (_MorphVertex *)0x0)
  {
    sVar2 = p_Var13->vindex;
    sVar4 = p_Var13->vindex;
    psVar22 = &p_Var13->vindex;
    while (-1 < sVar2)
    {
      p_Var6 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var6->vertex).x = psVar22[1];
      (p_Var6->vertex).y = psVar22[2];
      psVar1 = psVar22 + 3;
      psVar22 = psVar22 + 7;
      (p_Var6->vertex).z = *psVar1;
      sVar2 = *psVar22;
      sVar4 = *psVar22;
    }
  }
  p_Var5 = BaseLevel->terrain;
  if (p_Var5->MorphColorList != (_MorphColor *)0x0)
  {
    p_Var6 = p_Var5->vertexList;
    p_Var23 = p_Var6 + p_Var5->numVertices;
    pbVar14 = &p_Var6->b0;
    while (p_Var6 < p_Var23)
    {
      p_Var6 = p_Var6 + 1;
      pbVar14[-2] = (byte)(((u_int)pbVar14[-4] & 0x1f) << 3);
      pbVar14[-1] = (byte)(*(u_short *)(pbVar14 + -4) >> 2) & 0xf8;
      *pbVar14 = (byte)(*(u_short *)(pbVar14 + -4) >> 7) & 0xf8;
      pbVar14 = pbVar14 + 0xc;
    }
  }
  RemoveIntroducedLights(BaseLevel);
  lVar18 = BaseLevel->numSpotSpecturalLights;
  pSVar15 = BaseLevel->spotSpecturalLightList;
  p_Var5 = BaseLevel->terrain;
  BaseLevel->numSpotSpecturalLights = BaseLevel->numSpotLights;
  lVar25 = BaseLevel->numPointLights;
  BaseLevel->spotSpecturalLightList = BaseLevel->spotLightList;
  pPVar24 = BaseLevel->pointLightList;
  BaseLevel->numSpotLights = lVar18;
  BaseLevel->spotLightList = pSVar15;
  BaseLevel->numPointLights = BaseLevel->numPointSpecturalLights;
  BaseLevel->pointLightList = BaseLevel->pointSpecturalLightList;
  BaseLevel->numPointSpecturalLights = lVar25;
  BaseLevel->pointSpecturalLightList = pPVar24;
  iVar21 = 0;
  if (0 < p_Var5->numBSPTrees)
  {
    iVar19 = 0;
    do
    {
      puVar7 = (u_int *)((int)&p_Var5->BSPTreeArray->bspRoot + iVar19);
      puVar16 = (u_char *)*puVar7;
      puVar9 = puVar16 + 7;
      if (puVar16 < (u_char *)puVar7[1])
      {
        do
        {
          uVar26 = *puVar16;
          local_1c = puVar16[1];
          uVar27 = puVar9[1];
          *puVar16 = *puVar9;
          puVar16[1] = uVar27;
          *puVar9 = uVar26;
          puVar9[1] = local_1c;
          puVar16 = puVar16 + 0xb;
          puVar9 = puVar9 + 0xb;
        } while (puVar16 < *(u_char **)((int)&p_Var5->BSPTreeArray->startLeaves + iVar19));
      }
      iVar8 = (int)&p_Var5->BSPTreeArray->bspRoot + iVar19;
      puVar16 = *(u_char **)(iVar8 + 4);
      if (puVar16 < *(u_char **)(iVar8 + 8))
      {
        puVar9 = puVar16 + 7;
        do
        {
          uVar26 = *puVar16;
          local_1c = puVar16[1];
          uVar27 = puVar9[4];
          *puVar16 = puVar9[3];
          puVar16[1] = uVar27;
          puVar9[3] = uVar26;
          puVar9[4] = local_1c;
          uVar26 = puVar9[-3];
          local_14 = puVar9[-2];
          local_10 = puVar9[-1];
          puVar9[-3] = *puVar9;
          puVar9[-2] = puVar9[1];
          puVar9[-1] = puVar9[2];
          *puVar9 = uVar26;
          puVar9[1] = local_14;
          puVar9[2] = local_10;
          puVar16 = puVar16 + 0xc;
          puVar9 = puVar9 + 0xc;
        } while (puVar16 < *(u_char **)((int)&p_Var5->BSPTreeArray->endLeaves + iVar19));
      }
      iVar21 = iVar21 + 1;
      iVar19 = iVar19 + 0x24;
    } while (iVar21 < p_Var5->numBSPTrees);
  }
  instance = (gameTrackerX.instanceList)->first;
  while (instance != (_Instance *)0x0)
  {
    pIVar10 = instance->intro;
    if ((pIVar10 != (Intro *)0x0) &&
        (((*(int *)&pIVar10->spectralPosition != 0 || ((pIVar10->spectralPosition).z != 0)) &&
          ((instance->flags2 & 8U) == 0))))
    {
      local_18 = *(u_int *)&instance->position;
      uVar11 = (u_int)(u_short)(instance->position).z;
      local_14 = local_14 & 0xffff0000 | uVar11;
      (instance->position).x = (pIVar10->position).x;
      (instance->position).y = (pIVar10->position).y;
      (instance->position).z = (pIVar10->position).z;
      uVar20 = (u_int)(u_short)(instance->position).x - (local_18 & 0xffff);
      iVar21 = (u_int)(u_short)(instance->position).y - (local_18 >> 0x10);
      local_20 = uVar20 & 0xffff | iVar21 * 0x10000;
      uVar11 = (u_short)(instance->position).z - uVar11;
      local_1c = local_1c & 0xffff0000 | uVar11 & 0xffff;
      if (((int)(uVar20 * 0x10000) >> 0x10) + (iVar21 * 0x10000 >> 0x10) +
              ((int)(uVar11 * 0x10000) >> 0x10) !=
          0)
      {
        COLLIDE_MoveAllTransforms(instance, (SVECTOR *)&local_20);
      }
    }
    instance = instance->next;
  }
  return;
}

void MORPH_AddOffsets(Level *BaseLevel, int time)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  short sVar4;
  u_short uVar5;
  u_short *puVar6;
  int iVar7;
  _TVertex *p_Var8;
  int iVar9;
  Intro *pIVar10;
  int iVar11;
  _Terrain *p_Var12;
  u_int uVar13;
  short *psVar14;
  int iVar15;
  u_int uVar16;
  _MorphVertex *p_Var17;
  u_char *puVar18;
  _MorphColor *p_Var19;
  _TVertex *p_Var20;
  _Instance *instance;
  SVECTOR local_20;
  u_int local_18;
  u_short local_14;

  instance = (gameTrackerX.instanceList)->first;
  if (time < 0x1f5)
  {
    time = time * 2;
    2000000;
  }
  else
  {
    iVar7 = (1000 - time) * 2;
    2000000;
  }
  p_Var17 = BaseLevel->terrain->MorphDiffList;
  1000;
  if ((p_Var17 != (_MorphVertex *)0x0) && (sVar4 = p_Var17->vindex, -1 < p_Var17->vindex))
  {
    psVar14 = &p_Var17->vindex;
    do
    {
      p_Var8 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var8->vertex).x = psVar14[1] + (short)(p_Var17->x * iVar7 >> 0xc);
      (p_Var8->vertex).y = psVar14[2] + (short)(psVar14[-2] * iVar7 >> 0xc);
      psVar1 = psVar14 + -1;
      psVar2 = psVar14 + 3;
      psVar14 = psVar14 + 7;
      (p_Var8->vertex).z = *psVar2 + (short)(*psVar1 * iVar7 >> 0xc);
      sVar4 = *psVar14;
      p_Var17 = p_Var17 + 1;
    } while (-1 < *psVar14);
  }
  while (instance != (_Instance *)0x0)
  {
    pIVar10 = instance->intro;
    if ((pIVar10 != (Intro *)0x0) &&
        (((*(int *)&pIVar10->spectralPosition != 0 || ((pIVar10->spectralPosition).z != 0)) &&
          ((instance->flags2 & 8U) == 0))))
    {
      sVar4 = (pIVar10->spectralPosition).y;
      sVar3 = (pIVar10->spectralPosition).z;
      local_18 = *(u_int *)&instance->position;
      local_14 = (instance->position).z;
      (instance->position).x =
          (pIVar10->position).x + (short)((pIVar10->spectralPosition).x * iVar7 >> 0xc);
      (instance->position).y = (pIVar10->position).y + (short)(sVar4 * iVar7 >> 0xc);
      (instance->position).z = (pIVar10->position).z + (short)(sVar3 * iVar7 >> 0xc);
      iVar15 = (u_int)(u_short)(instance->position).x - (local_18 & 0xffff);
      local_20.vx = (short)iVar15;
      iVar11 = (u_int)(u_short)(instance->position).y - (local_18 >> 0x10);
      local_20.vy = (short)iVar11;
      iVar9 = (u_int)(u_short)(instance->position).z - (u_int)local_14;
      local_20.vz = (short)iVar9;
      if ((iVar15 * 0x10000 >> 0x10) + (iVar11 * 0x10000 >> 0x10) + (iVar9 * 0x10000 >> 0x10) != 0)
      {
        COLLIDE_MoveAllTransforms(instance, &local_20);
      }
    }
    instance = instance->next;
  }
  p_Var12 = BaseLevel->terrain;
  p_Var19 = p_Var12->MorphColorList;
  if (p_Var19 != (_MorphColor *)0x0)
  {
    p_Var8 = p_Var12->vertexList;
    p_Var20 = p_Var8 + p_Var12->numVertices;
    if (p_Var8 < p_Var20)
    {
      puVar18 = &p_Var8->b0;
      do
      {
        uVar5 = *(u_short *)(puVar18 + -4);
        puVar6 = (u_short *)&p_Var19->morphColor15;
        uVar16 = (u_int)(uVar5 >> 2) & 0xf8;
        iVar9 = (u_int)*puVar6 << 0x10;
        uVar13 = (u_int)(uVar5 >> 7) & 0xf8;
        p_Var8 = p_Var8 + 1;
        p_Var19 = p_Var19 + 1;
        puVar18[-2] = (char)((u_int)uVar5 & 0x1f) * '\b' +
                      (char)((int)((((u_int)*puVar6 & 0x1f) * 8 + ((u_int)uVar5 & 0x1f) * -8) * iVar7) >> 0xc);
        puVar18[-1] = (char)uVar16 +
                      (char)((int)(((iVar9 >> 0x12 & 0xf8U) - uVar16) * iVar7) >> 0xc);
        *puVar18 = (char)uVar13 + (char)((int)(((iVar9 >> 0x17 & 0xf8U) - uVar13) * iVar7) >> 0xc);
        puVar18 = puVar18 + 0xc;
      } while (p_Var8 < p_Var20);
    }
  }
  return;
}

void MORPH_SubtractOffsets(Level *BaseLevel, int time)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  short sVar4;
  u_short uVar5;
  u_short *puVar6;
  int iVar7;
  _TVertex *p_Var8;
  int iVar9;
  _Terrain *p_Var10;
  Intro *pIVar11;
  int iVar12;
  u_int uVar13;
  short *psVar14;
  int iVar15;
  u_int uVar16;
  _MorphVertex *p_Var17;
  u_char *puVar18;
  _MorphColor *p_Var19;
  _TVertex *p_Var20;
  _Instance *instance;
  SVECTOR local_20;
  u_int local_18;
  u_short local_14;

  instance = (gameTrackerX.instanceList)->first;
  if (time < 0x1f5)
  {
    time = time * 2;
    2000000;
  }
  else
  {
    iVar7 = (1000 - time) * 2;
    2000000;
  }
  p_Var17 = BaseLevel->terrain->MorphDiffList;
  1000;
  if ((p_Var17 != (_MorphVertex *)0x0) && (sVar4 = p_Var17->vindex, -1 < p_Var17->vindex))
  {
    psVar14 = &p_Var17->vindex;
    do
    {
      p_Var8 = BaseLevel->terrain->vertexList + sVar4;
      (p_Var8->vertex).x = psVar14[1] + (short)(p_Var17->x * iVar7 >> 0xc);
      (p_Var8->vertex).y = psVar14[2] + (short)(psVar14[-2] * iVar7 >> 0xc);
      psVar1 = psVar14 + -1;
      psVar2 = psVar14 + 3;
      psVar14 = psVar14 + 7;
      (p_Var8->vertex).z = *psVar2 + (short)(*psVar1 * iVar7 >> 0xc);
      sVar4 = *psVar14;
      p_Var17 = p_Var17 + 1;
    } while (-1 < *psVar14);
  }
  while (instance != (_Instance *)0x0)
  {
    pIVar11 = instance->intro;
    if ((pIVar11 != (Intro *)0x0) &&
        (((*(int *)&pIVar11->spectralPosition != 0 || ((pIVar11->spectralPosition).z != 0)) &&
          ((instance->flags2 & 8U) == 0))))
    {
      sVar4 = (pIVar11->spectralPosition).y;
      sVar3 = (pIVar11->spectralPosition).z;
      local_18 = *(u_int *)&instance->position;
      local_14 = (instance->position).z;
      (instance->position).x =
          (pIVar11->position).x + (short)((pIVar11->spectralPosition).x * iVar7 >> 0xc);
      (instance->position).y = (pIVar11->position).y + (short)(sVar4 * iVar7 >> 0xc);
      (instance->position).z = (pIVar11->position).z + (short)(sVar3 * iVar7 >> 0xc);
      iVar15 = (u_int)(u_short)(instance->position).x - (local_18 & 0xffff);
      local_20.vx = (short)iVar15;
      iVar12 = (u_int)(u_short)(instance->position).y - (local_18 >> 0x10);
      local_20.vy = (short)iVar12;
      iVar9 = (u_int)(u_short)(instance->position).z - (u_int)local_14;
      local_20.vz = (short)iVar9;
      if ((iVar15 * 0x10000 >> 0x10) + (iVar12 * 0x10000 >> 0x10) + (iVar9 * 0x10000 >> 0x10) != 0)
      {
        COLLIDE_MoveAllTransforms(instance, &local_20);
      }
    }
    instance = instance->next;
  }
  p_Var10 = BaseLevel->terrain;
  p_Var19 = p_Var10->MorphColorList;
  if (p_Var19 != (_MorphColor *)0x0)
  {
    p_Var8 = p_Var10->vertexList;
    p_Var20 = p_Var8 + p_Var10->numVertices;
    if (p_Var8 < p_Var20)
    {
      puVar18 = &p_Var8->b0;
      do
      {
        uVar5 = *(u_short *)(puVar18 + -4);
        puVar6 = (u_short *)&p_Var19->morphColor15;
        uVar16 = (u_int)(uVar5 >> 2) & 0xf8;
        iVar9 = (u_int)*puVar6 << 0x10;
        uVar13 = (u_int)(uVar5 >> 7) & 0xf8;
        p_Var8 = p_Var8 + 1;
        p_Var19 = p_Var19 + 1;
        puVar18[-2] = (char)((u_int)uVar5 & 0x1f) * '\b' +
                      (char)((int)((((u_int)*puVar6 & 0x1f) * 8 + ((u_int)uVar5 & 0x1f) * -8) * iVar7) >> 0xc);
        puVar18[-1] = (char)uVar16 +
                      (char)((int)(((iVar9 >> 0x12 & 0xf8U) - uVar16) * iVar7) >> 0xc);
        *puVar18 = (char)uVar13 + (char)((int)(((iVar9 >> 0x17 & 0xf8U) - uVar13) * iVar7) >> 0xc);
        puVar18 = puVar18 + 0xc;
      } while (p_Var8 < p_Var20);
    }
  }
  return;
}

void MORPH_GetComponentsForTrackingPoint(_TFace *face, Level *level)

{
  int iVar1;
  int iVar2;
  BSPTree *pBVar3;
  int iVar4;
  _TVertex *p_Var5;
  int iVar6;
  _TVertex **pp_Var7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  _TVertex *local_20[4];
  short local_10;
  short local_e;
  short local_c;
  int local_8[2];

  MORPH_SavedLevel = level;
  MORPH_SavedFace = face;
  if ((face != (_TFace *)0x0) && (iVar11 = 0, level != (Level *)0x0))
  {
    psVar12 = &MORPH_Component;
    p_Var5 = level->terrain->vertexList;
    local_20[0] = p_Var5 + (face->face).v0;
    iVar10 = 0;
    local_20[1] = p_Var5 + (face->face).v1;
    local_20[2] = p_Var5 + (face->face).v2;
    pBVar3 = level->terrain->BSPTreeArray + (gameTrackerX.playerInstance)->bspTree;
    local_10 = ((gameTrackerX.playerInstance)->position).x - (pBVar3->globalOffset).x;
    local_e = ((gameTrackerX.playerInstance)->position).y - (pBVar3->globalOffset).y;
    local_c = ((gameTrackerX.playerInstance)->position).z - (pBVar3->globalOffset).z;
    do
    {
      iVar8 = 0;
      iVar9 = 0;
      iVar6 = 0;
      pp_Var7 = local_20;
      do
      {
        iVar4 = iVar6 + 1;
        if (2 < iVar4)
        {
          iVar4 = 0;
        }
        if ((iVar11 != 1) || (iVar6 != (int)MORPH_Track))
        {
          iVar1 = iVar4 * 4;
          if (((*(short *)((int)*pp_Var7 + 2) <= local_e) &&
               (iVar1 = iVar4 << 2, local_e <= (local_20[iVar4]->vertex).y)) ||
              ((*(short *)(*(int *)((int)local_20 + iVar1) + 2) <= local_e &&
                (local_e <= *(short *)((int)*pp_Var7 + 2)))))
          {
            iVar1 = (int)(local_20[iVar4]->vertex).y - (int)*(short *)((int)*pp_Var7 + 2);
            iVar4 = iVar1;
            if (iVar1 < 0)
            {
              iVar4 = -iVar1;
            }
            iVar2 = iVar8;
            if (iVar8 < 0)
            {
              iVar2 = -iVar8;
            }
            if (iVar2 < iVar4)
            {
              iVar8 = iVar1;
              iVar9 = iVar6;
            }
          }
        }
        iVar6 = iVar6 + 1;
        pp_Var7 = (_TVertex **)((int *)pp_Var7 + 1);
      } while (iVar6 < 3);
      *(undefined2 *)((int)&MORPH_Track + iVar10) = (short)iVar9;
      iVar6 = iVar9 + 1;
      if (2 < iVar6)
      {
        iVar6 = 0;
      }
      if (iVar8 == 0)
      {
        *(undefined2 *)((int)&MORPH_Component + iVar10) = 0;
      }
      else
      {
        *(undefined2 *)((int)&MORPH_Component + iVar10) =
 iVar8);
      }
      iVar9 = (int)(local_20[iVar9]->vertex).x;
      iVar8 = (int)*psVar12 * ((local_20[iVar6]->vertex).x - iVar9);
      if (iVar8 < 0)
      {
        iVar8 = iVar8 + 0xfff;
      }
      local_8[iVar11] = iVar9 + (iVar8 >> 0xc);
      psVar12 = psVar12 + 1;
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + 2;
    } while (iVar11 < 2);
    if (local_8[0] == local_8[1])
    {
      SHORT_800d2a04 = 0;
    }
    else
    {
 (local_8[1] - local_8[0]));
    }
  }
  return;
}

void MORPH_AveragePoint(_SVector *start, _SVector *end, int interp, _SVector *out)

{
  _SVector *p_Var1;
  undefined *puVar2;

  if (interp < 0)
  {
    puVar2 = &DAT_0000132a + interp;
    interp = -interp;
    p_Var1 = end;
  }
  else
  {
    puVar2 = (undefined *)(0x1000 - interp);
    p_Var1 = start;
    start = end;
  }
  LoadAverageShort12((u_int *)p_Var1, (u_int *)start, puVar2, interp, (u_int *)out);
  return;
}

void MORPH_UpdateTrackingPoint(_TFace *face, Level *level)

{
  short sVar1;
  short sVar2;
  _Instance *p_Var3;
  BSPTree *pBVar4;
  _TVertex *p_Var5;
  int iVar6;
  _TVertex *local_38[4];
  _SVector _Stack40;
  _SVector _Stack32;
  _SVector local_18;

  if ((face != (_TFace *)0x0) && (level != (Level *)0x0))
  {
    p_Var5 = level->terrain->vertexList;
    local_38[0] = p_Var5 + (face->face).v0;
    local_38[1] = p_Var5 + (face->face).v1;
    iVar6 = (int)MORPH_Track + 1;
    local_38[2] = p_Var5 + (face->face).v2;
    if (2 < iVar6)
    {
      iVar6 = 0;
    }
    MORPH_AveragePoint((_SVector *)local_38[(int)MORPH_Track], (_SVector *)local_38[iVar6],
                       (int)MORPH_Component, &_Stack40);
    iVar6 = (int)SHORT_800d2a0a + 1;
    if (2 < iVar6)
    {
      iVar6 = 0;
    }
    MORPH_AveragePoint((_SVector *)local_38[(int)SHORT_800d2a0a], (_SVector *)local_38[iVar6],
                       (int)SHORT_800d2a02, &_Stack32);
    MORPH_AveragePoint(&_Stack40, &_Stack32, (int)SHORT_800d2a04, &local_18);
    p_Var3 = gameTrackerX.playerInstance;
    pBVar4 = level->terrain->BSPTreeArray + (gameTrackerX.playerInstance)->bspTree;
    sVar1 = (pBVar4->globalOffset).y;
    sVar2 = (pBVar4->globalOffset).z;
    ((gameTrackerX.playerInstance)->position).x = local_18.x + (pBVar4->globalOffset).x;
    (p_Var3->position).y = local_18.y + sVar1;
    (p_Var3->position).z = local_18.z + sVar2;
    (gameTrackerX.playerInstance)->cachedTFace = -1;
  }
  return;
}

void MORPH_ToggleMorph(void)

{
  _MultiSignal *mSignal;
  Level *pLVar1;
  Level **ppLVar2;
  int iVar3;

  razPlaneShift((u_int)(gameTrackerX.gameData.asmData.MorphType == 0));
  INSTANCE_Broadcast((_Instance *)0x0, 10, 0x1000020, (int)gameTrackerX.gameData.asmData.MorphType);
  iVar3 = 0x10;
  MORPH_GetComponentsForTrackingPoint((gameTrackerX.playerInstance)->tface, (Level *)(gameTrackerX.playerInstance)->tfaceLevel);
  MORPH_UpdateTrackingPoint((gameTrackerX.playerInstance)->tface, (Level *)(gameTrackerX.playerInstance)->tfaceLevel);
  gameTrackerX.gameData.asmData.MorphTime = 0;
  ppLVar2 = &StreamTracker.StreamList[0].level;
  SOUND_Play3dSound(&(gameTrackerX.playerInstance)->position, 0x1a, -0x15e, 0x7f, 0x7fff);
  do
  {
    if (*(short *)(ppLVar2 + -1) == 2)
    {
      pLVar1 = *ppLVar2;
      if (gameTrackerX.gameData.asmData.MorphType == 1)
      {
        mSignal = pLVar1->materialSignal;
        if (mSignal != (_MultiSignal *)0x0)
        {
          mSignal->flags = mSignal->flags | 1;
          SIGNAL_HandleFogNear(gameTrackerX.playerInstance, pLVar1->materialSignal->signalList, 0);
          mSignal = pLVar1->materialSignal;
        LAB_8005e2d0:
          EVENT_AddSignalToReset(mSignal);
        }
      }
      else
      {
        mSignal = pLVar1->spectralSignal;
        if (mSignal != (_MultiSignal *)0x0)
        {
          mSignal->flags = mSignal->flags | 1;
          SIGNAL_HandleFogNear(gameTrackerX.playerInstance, pLVar1->spectralSignal->signalList, 0);
          mSignal = pLVar1->spectralSignal;
          goto LAB_8005e2d0;
        }
      }
    }
    iVar3 = iVar3 + -1;
    ppLVar2 = ppLVar2 + 0x10;
    if (iVar3 < 1)
    {
      return;
    }
  } while (true);
}

void MORPH_DoStep(_StreamUnit *streamUnit, char *baseAreaName)

{
  bool bVar1;
  int time;
  Level *level;

  GAMEPAD_HandleDualShock(0x40, 0xf000);
  level = streamUnit->level;
  if (level->terrain->MorphDiffList != (_MorphVertex *)0x0)
  {
    VRAM_UpdateMorphPalettes(level, 0);
    time = (int)gameTrackerX.gameData.asmData.MorphTime;
    if (time == 1000)
    {
      bVar1 = gameTrackerX.gameData.asmData.MorphType == 0;
      gameTrackerX.gameData.asmData.MorphType = gameTrackerX.gameData.asmData.MorphType ^ 1;
      if (bVar1)
      {
        MORPH_UpdateTextures(level);
      }
      else
      {
        MORPH_BringBackNormals(level);
      }
      gameTrackerX.gameData.asmData.MorphType = gameTrackerX.gameData.asmData.MorphType ^ 1;
      level->morphLastStep = -1;
    }
    else
    {
      if (gameTrackerX.gameData.asmData.MorphType == 0)
      {
        MORPH_AddOffsets(level, time);
      }
      else
      {
        MORPH_SubtractOffsets(level, time);
      }
    }
  }
  return;
}

void MORPH_SetFog(_StreamUnit *streamUnit, int mainUnitFlag)

{
  short sVar1;
  int iVar2;
  Level *pLVar3;
  int iVar4;

  1000;
  pLVar3 = streamUnit->level;
  if (gameTrackerX.gameData.asmData.MorphType == 0)
  {
    iVar2 = 0x1000 - iVar2;
  }
  iVar4 = ((u_int)pLVar3->holdFogNear - (u_int)pLVar3->spectralFogNear) * iVar2;
  if (iVar4 < 0)
  {
    iVar4 = iVar4 + 0xfff;
  }
  iVar2 = ((u_int)pLVar3->holdFogFar - (u_int)pLVar3->spectralFogFar) * iVar2;
  iVar4 = (iVar4 >> 0xc) + (u_int)pLVar3->spectralFogNear;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  iVar2 = (iVar2 >> 0xc) + (u_int)pLVar3->spectralFogFar;
  if (mainUnitFlag == 0)
  {
    STREAM_GetStreamUnitWithID(streamUnit, (short)((u_int)(iVar4 * 0x10000) >> 0x10),
                               (short)((u_int)(iVar2 * 0x10000) >> 0x10));
  }
  else
  {
    sVar1 = (short)iVar4;
    streamUnit->UnitFogNear = sVar1;
    streamUnit->TargetFogNear = sVar1;
    sVar1 = (short)iVar2;
    streamUnit->UnitFogFar = sVar1;
    streamUnit->TargetFogFar = sVar1;
  }
  return;
}

void MORPH_UpdateNormals(void)

{
  int time;

  1000;
  if (gameTrackerX.gameData.asmData.MorphType == 1)
  {
    time = 0x1000 - time;
  }
  MORPH_ChangeAreaPalettes(time);
  return;
}

void MORPH_Continue(void)

{
  u_long uVar1;
  _TFace *face;
  Level *level;
  STracker *streamUnit;
  char *baseAreaName;
  int iVar2;

  if (gameTrackerX.gameData.asmData.MorphTime == 0)
  {
    MORPH_SetupInstanceFlags(&gameTrackerX);
  }
  iVar2 = 0;
  baseAreaName = StreamTracker.StreamList[0].baseAreaName;
  streamUnit = &StreamTracker;
  gameTrackerX.gameData.asmData.MorphTime = gameTrackerX.gameData.asmData.MorphTime + 0x14;
  MORPH_InMorphDoFadeValues(&gameTrackerX);
  do
  {
    if (*(short *)streamUnit->StreamList == 2)
    {
      MORPH_DoStep((_StreamUnit *)streamUnit, baseAreaName);
      MORPH_SetFog((_StreamUnit *)streamUnit, 0);
    }
    baseAreaName = baseAreaName + 0x40;
    iVar2 = iVar2 + 1;
    streamUnit = (STracker *)(streamUnit->StreamList + 1);
  } while (iVar2 < 0x10);
  uVar1 = INSTANCE_Post(gameTrackerX.playerInstance, 10);
  face = (gameTrackerX.playerInstance)->tface;
  if ((face != (_TFace *)0x0) && (-1 < (int)uVar1))
  {
    level = MORPH_SavedLevel;
    if (MORPH_SavedFace != face)
    {
      MORPH_GetComponentsForTrackingPoint(face, (Level *)(gameTrackerX.playerInstance)->tfaceLevel);
      face = (gameTrackerX.playerInstance)->tface;
      level = (Level *)(gameTrackerX.playerInstance)->tfaceLevel;
    }
    MORPH_UpdateTrackingPoint(face, level);
  }
  MORPH_UpdateNormals();
  if (gameTrackerX.gameData.asmData.MorphTime == 1000)
  {
    gameTrackerX.gameData.asmData.MorphType = gameTrackerX.gameData.asmData.MorphType ^ 1;
    if (gameTrackerX.gameData.asmData.MorphType == 0)
    {
      (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 & 0xf7ffffff;
    }
    else
    {
      (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 | 0x8000000;
    }
    MORPH_InMorphInstanceListFlags(&gameTrackerX);
  }
  return;
}

void STREAM_MORPH_Relocate(void)

{
  MORPH_SavedLevel = (Level *)0x0;
  MORPH_SavedFace = (_TFace *)0x0;
  return;
}

int AddVertex(VECTOR *v0, RECT *rect)

{
  u_char in_zero;
  u_char in_at;
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  u_char uVar5;
  u_char uVar6;
  u_char uVar7;
  u_char local_8;
  u_int local_4;

  iVar2 = v0->vx;
  if (iVar2 < 0)
  {
    iVar1 = -0x8000;
  LAB_8005e6c8:
    v0->vx = iVar2 + iVar1;
  }
  else
  {
    iVar1 = 0x8000;
    if (0 < iVar2)
      goto LAB_8005e6c8;
  }
  iVar1 = v0->vy;
  iVar2 = -0x8000;
  if ((iVar1 < 0) || (iVar2 = 0x8000, 0 < iVar1))
  {
    v0->vy = iVar1 + iVar2;
  }
  iVar1 = v0->vz;
  iVar2 = -0x8000;
  if (-1 < iVar1)
  {
    if (iVar1 < 1)
      goto LAB_8005e714;
    iVar2 = 0x8000;
  }
  v0->vz = iVar1 + iVar2;
LAB_8005e714:
  local_8 = CONCAT22(*(undefined2 *)((int)&v0->vy + 2), *(undefined2 *)((int)&v0->vx + 2));
  local_4 = local_4 & 0xffff0000 | (u_int) * (u_short *)((int)&v0->vz + 2);
  setCopReg(2, in_zero, local_8);
  setCopReg(2, in_at, local_4);
  copFunction(2, 0x480012);
  uVar5 = getCopReg(2, 0x4800);
  uVar6 = getCopReg(2, 0x5000);
  uVar7 = getCopReg(2, 0x5800);
  iVar1 = (int)(short)uVar7;
  iVar2 = -1;
  if (0 < iVar1)
  {
    iVar1 + 0x100;
    iVar1 + 0x78;
    sVar4 = (short)iVar2;
    if (rect->x < iVar2)
    {
      sVar4 = rect->x;
    }
    rect->x = sVar4;
    sVar4 = (short)iVar2;
    if (iVar2 < rect->w)
    {
      sVar4 = rect->w;
    }
    rect->w = sVar4;
    sVar4 = (short)iVar3;
    if (rect->y < iVar3)
    {
      sVar4 = rect->y;
    }
    rect->y = sVar4;
    sVar4 = (short)iVar3;
    if (iVar3 < rect->h)
    {
      sVar4 = rect->h;
    }
    rect->h = sVar4;
    iVar2 = iVar1;
  }
  return iVar2;
}

int GetPlaneDist(int k, int j, int i, VECTOR *v)

{
  return ((v->vx >> 0xc) + (int)theCamera.core.position.x * -0x10) *
             (int)theCamera.core.vvNormalWorVecMat[k].m[j * 3] +
         ((v->vy >> 0xc) + (int)theCamera.core.position.y * -0x10) *
             (int)theCamera.core.vvNormalWorVecMat[k].m[j * 3 + 1] +
         ((v->vz >> 0xc) + (int)theCamera.core.position.z * -0x10) *
             (int)theCamera.core.vvNormalWorVecMat[k].m[j * 3 + 2];
}

void CalcVert(VECTOR *v, VECTOR *v1, VECTOR *v2, int dist1, int dist2, int k, int j)

{
  (dist1 - dist2 >> 0xc);
  v->vx = (v2->vx - v1->vx >> 0xc) * dist2 + v2->vx;
  v->vy = (v2->vy - v1->vy >> 0xc) * dist2 + v2->vy;
  v->vz = (v2->vz - v1->vz >> 0xc) * dist2 + v2->vz;
  return;
}

int AddClippedTri(SVECTOR *iv, RECT *cliprect, int *minz)

{
  short *psVar1;
  bool bVar2;
  int dist1;
  int dist2;
  VECTOR *v1;
  long lVar3;
  long lVar4;
  VECTOR *v;
  long lVar5;
  VECTOR *v_00;
  int iVar6;
  int iVar7;
  int i;
  int iVar8;
  VECTOR local_240[16];
  VECTOR aVStack320[16];
  int local_40;
  u_int local_3c;
  int local_38;
  VECTOR *local_34;
  VECTOR *local_30;

  v = local_240;
  local_30 = aVStack320;
  iVar7 = 0;
  *minz = 0xffff;
  local_34 = v;
  do
  {
    v->vx = (int)iv->vx << 0x10;
    iVar7 = iVar7 + 1;
    v->vy = (int)iv->vy << 0x10;
    psVar1 = &iv->vz;
    iv = iv + 1;
    v->vz = (int)*psVar1 << 0x10;
    v = v + 1;
  } while (iVar7 < 3);
  i = 0;
  bVar2 = true;
  iVar7 = 3;
  do
  {
    local_40 = i;
    if (!bVar2)
    {
      local_40 = i + -3;
    }
    local_3c = (u_int)!bVar2;
    dist1 = GetPlaneDist(local_3c, local_40, i, local_34);
    iVar8 = 1;
    iVar6 = 0;
    local_38 = 0;
    v = local_30;
    v1 = local_34;
    if (0 < iVar7)
    {
      do
      {
        if (iVar7 <= iVar8)
        {
          iVar8 = 0;
        }
        v_00 = local_34 + iVar8;
        dist2 = GetPlaneDist(local_3c, local_40, i, v_00);
        if (dist1 < 1)
        {
          if (0 < dist2)
          {
            CalcVert(v, v1, v_00, dist1, dist2, local_3c, local_40);
            v = v + 1;
            goto LAB_8005eb1c;
          }
        }
        else
        {
          if (dist2 < 1)
          {
            lVar4 = v1->vy;
            lVar5 = v1->vz;
            lVar3 = v1->pad;
            v->vx = v1->vx;
            v->vy = lVar4;
            v->vz = lVar5;
            v->pad = lVar3;
            iVar6 = iVar6 + 1;
            CalcVert(v + 1, v_00, v1, dist2, dist1, local_3c, local_40);
            v = v + 2;
          }
          else
          {
            lVar4 = v1->vy;
            lVar5 = v1->vz;
            lVar3 = v1->pad;
            v->vx = v1->vx;
            v->vy = lVar4;
            v->vz = lVar5;
            v->pad = lVar3;
            v = v + 1;
          }
        LAB_8005eb1c:
          iVar6 = iVar6 + 1;
        }
        iVar8 = iVar8 + 1;
        local_38 = local_38 + 1;
        v1 = v1 + 1;
        dist1 = dist2;
      } while (local_38 < iVar7);
    }
    v1 = local_30;
    v = local_34;
    local_34 = local_30;
    local_30 = v;
    if (iVar6 < 3)
    {
      return (u_int)(iVar6 != 0);
    }
    i = i + 1;
    bVar2 = i < 3;
    iVar7 = iVar6;
    if (4 < i)
    {
      iVar7 = 0;
      if (0 < iVar6)
      {
        do
        {
          i = AddVertex(v1, cliprect);
          if (i < *minz)
          {
            *minz = i;
          }
          iVar7 = iVar7 + 1;
          v1 = v1 + 1;
        } while (iVar7 < iVar6);
      }
      return 1;
    }
  } while (true);
}

int STREAM_GetClipRect(StreamUnitPortal *portal, RECT *rect)

{
  short sVar1;
  int iVar2;
  u_int uVar3;
  u_int uVar4;
  u_int uVar5;
  int iVar6;
  int iVar7;
  MATRIX *pMVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int local_40;
  int local_3c;
  int local_38;
  long local_34;
  u_int local_30;
  int local_2c;

  local_2c = 0;
  sVar9 = portal->t1[0].z;
  iVar17 = (int)sVar9;
  iVar11 = (int)portal->t1[1].z;
  local_30 = 0;
  if (iVar17 == iVar11)
  {
    local_30 = (u_int)(sVar9 == portal->t1[2].z);
  }
  iVar10 = (int)portal->t1[0].y;
  iVar15 = iVar10 - portal->t1[1].y;
  iVar13 = iVar17 - portal->t1[2].z;
  iVar11 = iVar17 - iVar11;
  iVar6 = iVar10 - portal->t1[2].y;
  iVar7 = (int)portal->t1[0].x;
  iVar12 = iVar7 - portal->t1[2].x;
  iVar2 = iVar7 - portal->t1[1].x;
  iVar19 = iVar15 * iVar13 - iVar6 * iVar11 >> 0xc;
  iVar13 = iVar12 * iVar11 - iVar2 * iVar13 >> 0xc;
  local_38 = iVar2 * iVar6 - iVar12 * iVar15 >> 0xc;
  iVar2 = (iVar7 - theCamera.core.position.x) * iVar19 +
          (iVar10 - theCamera.core.position.y) * iVar13 +
          (iVar17 - theCamera.core.position.z) * local_38;
  iVar11 = -iVar2;
  local_34 = MATH3D_FastSqrt(iVar19 * iVar19 + iVar13 * iVar13 + local_38 * local_38);
  iVar17 = iVar11;
  if (0 < iVar2)
  {
    iVar17 = iVar2;
  }
  if (iVar17 < local_34)
  {
    iVar7 = (int)portal->t2[0].y;
    iVar10 = (int)portal->t2[0].z;
    iVar16 = iVar7 - portal->t2[1].y;
    iVar14 = iVar10 - portal->t2[2].z;
    iVar12 = iVar10 - portal->t2[1].z;
    iVar2 = iVar7 - portal->t2[2].y;
    iVar6 = (int)portal->t2[0].x;
    iVar15 = iVar6 - portal->t2[2].x;
    iVar17 = iVar6 - portal->t2[1].x;
    iVar18 = iVar16 * iVar14 - iVar2 * iVar12 >> 0xc;
    iVar12 = iVar15 * iVar12 - iVar17 * iVar14 >> 0xc;
    iVar2 = iVar17 * iVar2 - iVar15 * iVar16 >> 0xc;
    iVar17 = -((iVar6 - theCamera.core.position.x) * iVar18 +
               (iVar7 - theCamera.core.position.y) * iVar12 +
               (iVar10 - theCamera.core.position.z) * iVar2);
    MATH3D_FastSqrt(iVar18 * iVar18 + iVar12 * iVar12 + iVar2 * iVar2);
    if (iVar11 < iVar17)
    {
      iVar13 = iVar12;
      iVar19 = iVar18;
      iVar11 = iVar17;
      local_38 = iVar2;
    }
  }
  iVar17 = memcmp((byte *)portal, (byte *)"warpgate", 8);
  if (iVar17 != 0)
  {
    iVar17 = iVar11;
    if (iVar11 < 0)
    {
      iVar17 = -iVar11;
    }
    if (((iVar17 < local_34) &&
         (pMVar8 = (theCamera.focusInstance)->matrix,
          (pMVar8[1].t[0] - (int)theCamera.core.position.x) * iVar19 +
                  (pMVar8[1].t[1] - (int)theCamera.core.position.y) * iVar13 +
                  (pMVar8[1].t[2] - (int)theCamera.core.position.z) * local_38 <
              0)) &&
        (local_30 == 0))
    {
      local_2c = 1;
    }
  }
  if ((-0x401 < iVar11) || (uVar3 = 0, local_2c != 0))
  {
    rect->w = rect->w + rect->x;
    rect->h = rect->h + rect->y;
    setCopControlWord(2, 0, *(u_char *)(theCamera.core.wcTransform)->m);
    setCopControlWord(2, 0x800, *(u_char *)((theCamera.core.wcTransform)->m + 2));
    setCopControlWord(2, 0x1000, *(u_char *)((theCamera.core.wcTransform)->m + 4));
    setCopControlWord(2, 0x1800, *(u_char *)((theCamera.core.wcTransform)->m + 6));
    setCopControlWord(2, 0x2000, *(u_char *)((theCamera.core.wcTransform)->m + 8));
    setCopControlWord(2, 0x2800, (theCamera.core.wcTransform)->t[0]);
    setCopControlWord(2, 0x3000, (theCamera.core.wcTransform)->t[1]);
    setCopControlWord(2, 0x3800, (theCamera.core.wcTransform)->t[2]);
    uVar4 = AddClippedTri((SVECTOR *)portal->t1, rect, &local_40);
    uVar5 = AddClippedTri((SVECTOR *)portal->t2, rect, &local_3c);
    uVar3 = 0;
    if ((uVar4 | uVar5) == 0)
    {
      rect->w = rect->w - rect->x;
      rect->h = rect->h - rect->y;
    }
    else
    {
      if (local_3c < local_40)
      {
        local_40 = local_3c;
      }
      if ((local_2c == 0) || (uVar3 = 1, 0x3f < local_40))
      {
        if (rect->x < 0)
        {
          rect->x = 0;
        }
        if (rect->y < 0)
        {
          rect->y = 0;
        }
        if (0x200 < rect->w)
        {
          rect->w = 0x200;
        }
        if (0xf0 < rect->h)
        {
          rect->h = 0xf0;
        }
        sVar9 = rect->h - rect->y;
        rect->w = rect->w - rect->x;
        rect->h = sVar9;
        if (local_30 != 0)
        {
          if (iVar11 < 0)
          {
            iVar11 = -iVar11;
          }
          if (iVar11 < local_34)
          {
            if (local_38 < 1)
            {
              sVar1 = rect->y;
              rect->y = 0;
              sVar1 = sVar1 + sVar9;
            }
            else
            {
              sVar1 = 0xf0 - rect->y;
            }
            rect->h = sVar1;
          }
        }
        if (rect->w < 1)
        {
          uVar3 = 0;
        }
        else
        {
          uVar3 = (u_int)(0 < rect->h);
        }
      }
      else
      {
        rect->w = 0x200;
        rect->x = 0;
        rect->y = 0;
        rect->h = 0xf0;
      }
    }
  }
  return uVar3;
}

long GetFogColor(StreamUnitPortal *portal, _StreamUnit *mainStreamUnit, Level *mainLevel)

{
  u_char in_zero;
  u_char in_at;
  u_int uVar1;
  byte *pbVar2;
  Level *pLVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u_int local_28;
  int local_24;
  int local_20;
  int local_1c;
  u_int local_18;
  u_int local_14;

  local_18 = mainStreamUnit->FogColor;
  pLVar3 = portal->toStreamUnit->level;
  if ((int)gameTrackerX.gameData.asmData.MorphTime == 1000)
  {
    if (gameTrackerX.gameData.asmData.MorphType == 1)
    {
      local_28 = *(u_int *)&pLVar3->specturalColorR;
    }
    else
    {
      local_28 = *(u_int *)&pLVar3->backColorR;
    }
  }
  else
  {
    1000;
    pbVar2 = &pLVar3->specturalColorR;
    if (gameTrackerX.gameData.asmData.MorphType == 1)
    {
      iVar5 = 0x1000 - iVar5;
    }
    pLVar3 = (Level *)&pLVar3->backColorR;
    LoadAverageCol(pbVar2, (byte *)pLVar3, iVar5, 0x1000 - iVar5, (undefined *)&local_28);
    local_28 = local_28 & 0xffffff;
  }
  setCopReg(2, in_zero, *(u_char *)portal->t1);
  setCopReg(2, in_at, *(u_char *)&portal->t1[0].z);
  setCopReg(2, portal->t1 + 2, *(u_char *)(portal->t1 + 1));
  setCopReg(2, portal->t1 + 1, *(u_char *)&portal->t1[1].z);
  setCopReg(2, portal->t1, *(u_char *)(portal->t1 + 2));
  setCopReg(2, pLVar3, *(u_char *)&portal->t1[2].z);
  copFunction(2, 0x280030);
  iVar5 = getCopReg(2, 0x11);
  iVar6 = getCopReg(2, 0x12);
  iVar4 = getCopReg(2, 0x13);
  if (iVar6 < iVar5)
  {
    iVar6 = iVar4;
    if (iVar4 < iVar5)
    {
      iVar6 = iVar5;
    }
  }
  else
  {
    if (iVar6 <= iVar4)
      goto LAB_8005f314;
  }
  iVar4 = iVar6;
LAB_8005f314:
  setCopReg(2, in_zero, *(u_char *)portal->t2);
  setCopReg(2, in_at, *(u_char *)&portal->t2[0].z);
  setCopReg(2, portal->t2 + 2, *(u_char *)(portal->t2 + 1));
  setCopReg(2, portal->t2 + 1, *(u_char *)&portal->t2[1].z);
  setCopReg(2, portal->t2, *(u_char *)(portal->t2 + 2));
  setCopReg(2, iVar4, *(u_char *)&portal->t2[2].z);
  copFunction(2, 0x280030);
  local_24 = getCopReg(2, 0x11);
  local_20 = getCopReg(2, 0x12);
  local_1c = getCopReg(2, 0x13);
  iVar5 = local_20;
  if (local_20 < local_24)
  {
    iVar5 = local_24;
  }
  iVar6 = local_1c;
  if (local_1c < iVar5)
  {
    iVar6 = iVar5;
  }
  if (iVar4 < iVar6)
  {
    iVar4 = iVar6;
  }
  uVar1 = (u_int)mainLevel->fogFar;
  if ((int)(iVar4 + 0x80U) < (int)(u_int)mainLevel->fogFar)
  {
    uVar1 = iVar4 + 0x80U;
  }
  s_zval = (int)uVar1 >> 2;
  if (local_18 == local_28)
  {
    local_28 = local_28 & 0xfff8f8f8;
    if (local_28 != 0)
    {
      local_28 = local_28 | 0x40404;
    }
  }
  else
  {
    iVar5 = uVar1 - (u_int)mainLevel->fogNear;
    if (-1 < iVar5)
    {
      (int)((u_int)mainLevel->fogFar - (u_int)mainLevel->fogNear) >> 4;
      iVar5 = iVar6;
      if (iVar6 < 0)
      {
        iVar5 = 0;
      }
      if (0x1000 < iVar6)
      {
        iVar5 = 0x1000;
      }
      LoadAverageCol((byte *)&local_18, (byte *)&local_28, iVar5, 0x1000 - iVar5, (undefined *)&local_14);
      if ((0xffa < iVar5) && (local_14 = local_14 & 0xfff8f8f8, local_14 != 0))
      {
        local_14 = local_14 | 0x40404;
      }
      local_28 = local_14 & 0xffffff;
    }
  }
  return local_28;
}

void DrawFogRectangle(RECT *cliprect, _PrimPool *primPool, int otzpos, u_long **drawot, long color)

{
  short sVar1;
  short sVar2;
  u_long *puVar3;

  puVar3 = (gameTrackerX.primPool)->nextPrim;
  if (puVar3 + 9 < (gameTrackerX.primPool)->lastPrim)
  {
    (gameTrackerX.primPool)->nextPrim = puVar3 + 9;
    *(short *)(puVar3 + 2) = cliprect->x;
    *(short *)((int)puVar3 + 10) = cliprect->y;
    *(short *)(puVar3 + 4) = cliprect->x + cliprect->w;
    *(short *)((int)puVar3 + 0x12) = cliprect->y;
    *(short *)(puVar3 + 6) = cliprect->x;
    *(short *)((int)puVar3 + 0x1a) = cliprect->y + cliprect->h;
    *(short *)(puVar3 + 8) = cliprect->x + cliprect->w;
    sVar1 = cliprect->y;
    sVar2 = cliprect->h;
    *(undefined *)((int)puVar3 + 3) = 8;
    puVar3[1] = color;
    puVar3[3] = color;
    puVar3[5] = color;
    puVar3[7] = color;
    *(undefined *)((int)puVar3 + 7) = 0x38;
    *(short *)((int)puVar3 + 0x22) = sVar1 + sVar2;
    *puVar3 = (u_int)drawot[otzpos] & 0xffffff | 0x8000000;
    drawot[otzpos] = (u_long *)((u_int)puVar3 & 0xffffff);
  }
  return;
}

void STREAM_RenderWarpGate(u_long **curOT, StreamUnitPortal *curStreamPortal, _StreamUnit *toStreamUnit,
                           _StreamUnit *mainStreamUnit, RECT *cliprect)

{
  long color;

  color = MEMPACK_ReportMemory((char *)toStreamUnit->level);
  if (color != 0)
  {
    RENDER_currentStreamUnitID = *(short *)&toStreamUnit->StreamUnitID;
    color = GetFogColor(curStreamPortal, mainStreamUnit, mainStreamUnit->level);
    DrawFogRectangle(cliprect, gameTrackerX.primPool, 0xbff, curOT, color);
    PushMatrix();
    StreamRenderLevel(toStreamUnit, mainStreamUnit->level, curOT, color);
    MulMatrix0();
  }
  return;
}

BSPTree *STREAM_GetBspTree(_StreamUnit *streamUnit, long bspNumber)

{
  _Terrain *p_Var1;
  int iVar2;
  BSPTree *pBVar3;
  int iVar4;

  p_Var1 = streamUnit->level->terrain;
  iVar2 = p_Var1->numBSPTrees;
  if ((iVar2 != 0) && (iVar4 = 0, 0 < iVar2))
  {
    pBVar3 = p_Var1->BSPTreeArray;
    do
    {
      iVar4 = iVar4 + 1;
      if ((int)pBVar3->ID == bspNumber)
      {
        return pBVar3;
      }
      pBVar3 = pBVar3 + 1;
    } while (iVar4 < iVar2);
  }
  return (BSPTree *)0x0;
}

void WARPGATE_BlockWarpGateEntrance(_StreamUnit *streamUnit, long collideOn)

{
  BSPTree *pBVar1;

  pBVar1 = STREAM_GetBspTree(streamUnit, 7);
  if (pBVar1 != (BSPTree *)0x0)
  {
    if (collideOn == 0)
    {
      pBVar1->flags = pBVar1->flags & 0xfffd;
      WarpGateLoadInfo.blocked = '\x01';
    }
    else
    {
      pBVar1->flags = pBVar1->flags | 2;
      WarpGateLoadInfo.blocked = '\0';
    }
  }
  return;
}

void WARPGATE_DrawWarpGateRim(_StreamUnit *streamUnit, long drawOn)

{
  u_short uVar1;
  u_short uVar2;
  BSPTree *pBVar3;

  pBVar3 = STREAM_GetBspTree(streamUnit, 3);
  if (pBVar3 != (BSPTree *)0x0)
  {
    uVar1 = pBVar3->flags;
    uVar2 = uVar1 & 0xfffd;
    pBVar3->flags = uVar2;
    if (drawOn == 0)
    {
      uVar2 = uVar2 | 1;
    }
    else
    {
      uVar2 = uVar1 & 0xfffc;
    }
    pBVar3->flags = uVar2;
  }
  return;
}

void WARPGATE_HideAllCloudCovers(void)

{
  return;
}

_Instance *WARPGATE_UnHideCloudCoverInUnit(long streamUnitID)

{
  return (_Instance *)0x0;
}

void STREAM_RenderAdjacantUnit(u_long **mainOT, StreamUnitPortal *curStreamPortal, _StreamUnit *mainStreamUnit,
                               RECT *cliprect)

{
  int iVar1;
  _StreamUnit *streamUnit;

  WARPGATE_DrawWarpGateRim(mainStreamUnit, 1);
  streamUnit = curStreamPortal->toStreamUnit;
  if (WarpGateLoadInfo.loading == '\x01')
  {
    if (WarpGateLoadInfo.maxTime < WarpGateLoadInfo.curTime)
    {
      if (streamUnit != (_StreamUnit *)0x0)
      {
        STREAM_DumpObject(streamUnit, 1);
      }
      WarpGateLoadInfo.loading = '\x02';
      STREAM_LoadCurrentWarpRoom(curStreamPortal, mainStreamUnit);
      (WarpGateLoadInfo.warpFaceInstance)->fadeValue = 0;
      return;
    }
    if (WarpGateLoadInfo.warpFaceInstance == (_Instance *)0x0)
    {
      WARPGATE_HideAllCloudCovers();
      WarpGateLoadInfo.warpFaceInstance =
          WARPGATE_UnHideCloudCoverInUnit(mainStreamUnit->StreamUnitID);
      WarpGateLoadInfo.fadeValue = 0x1000;
    }
    WARPGATE_CalcWarpFade(gameTrackerX.timeMult);
  }
  else
  {
    if (WarpGateLoadInfo.loading == '\x02')
    {
      WarpGateLoadInfo.fadeValue = 0;
      if ((streamUnit != (_StreamUnit *)0x0) && (streamUnit->used == 2))
      {
        WarpGateLoadInfo.loading = '\x03';
        WarpGateLoadInfo.curTime = WarpGateLoadInfo.maxTime;
      }
    }
    else
    {
      if (WarpGateLoadInfo.loading == '\x03')
      {
        if (WarpGateLoadInfo.curTime < 0)
        {
          WARPGATE_HideAllCloudCovers();
          iVar1 = WARPGATE_IsWarpgateInUse();
          if ((iVar1 == 0) &&
              (iVar1 = strcpy(gameTrackerX.baseAreaName, (char *)(&WarpRoomArray + CurrentWarpNumber)), iVar1 == 0))
          {
            WarpGateLoadInfo.loading = '\0';
            CurrentWarpNumber = 0;
          }
          else
          {
            WarpGateLoadInfo.loading = '\x04';
          }
        }
        else
        {
          WARPGATE_CalcWarpFade(-gameTrackerX.timeMult);
        }
      }
    }
  }
  if (WarpGateLoadInfo.loading == '\0')
  {
    iVar1 = WARPGATE_IsWarpgateInUse();
    if (iVar1 == 0)
    {
      WARPGATE_BlockWarpGateEntrance(mainStreamUnit, 1);
    }
    else
    {
      iVar1 = strcpy(mainStreamUnit->level->worldName, (char *)(&WarpRoomArray + CurrentWarpNumber));
      if (iVar1 == 0)
      {
        CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
      }
      WarpGateLoadInfo.loading = '\x01';
      WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
      WarpGateLoadInfo.curTime = 0;
    }
  }
  else
  {
    if ((streamUnit != (_StreamUnit *)0x0) && (streamUnit->used == 2))
    {
      WARPGATE_RenderWarpUnit(mainOT, curStreamPortal, mainStreamUnit, cliprect);
    }
    if ((WarpGateLoadInfo.loading == '\x04') && (iVar1 = WARPGATE_IsWarpgateInUse(), iVar1 == 0))
    {
      WarpGateLoadInfo.loading = '\x01';
      WarpGateLoadInfo.curTime = 0;
      WarpGateLoadInfo.warpFaceInstance = (_Instance *)0x0;
      (&WarpRoomArray)[CurrentWarpNumber].streamUnit = (_StreamUnit *)0x0;
      while (iVar1 = strcpy(gameTrackerX.baseAreaName, (char *)(&WarpRoomArray + CurrentWarpNumber)),
             iVar1 != 0)
      {
        CurrentWarpNumber = (CurrentWarpNumber + 1) % 0xe;
      }
    }
  }
  return;
}

void WARPGATE_RenderWarpUnit(u_long **mainOT, StreamUnitPortal *curStreamPortal, _StreamUnit *mainStreamUnit,
                             RECT *cliprect)

{
  int iVar1;
  long color;
  u_long *puVar2;
  _StreamUnit *streamUnit;
  u_long **drawot;
  u_char local_30;
  u_char local_2c;

  streamUnit = curStreamPortal->toStreamUnit;
  if ((gameTrackerX.debugFlags2 & 0x1000000U) != 0)
  {
    FONT_Print("Looking at warp unit =%s\n");
  }
  WARPGATE_BlockWarpGateEntrance(mainStreamUnit, (u_int)((streamUnit->flags & 8U) != 0));
  WARPGATE_DrawWarpGateRim(streamUnit, 1);
  color = MEMPACK_ReportMemory((char *)streamUnit->level);
  if ((color != 0) &&
      (drawot = (u_long **)(gameTrackerX.primPool)->nextPrim,
       drawot < (gameTrackerX.primPool)->lastPrim + -0xc00))
  {
    *(u_long ***)&(gameTrackerX.primPool)->nextPrim = drawot + 0xc00;
    ClearOTagR(drawot, 0xc00);
    RENDER_currentStreamUnitID = *(short *)&streamUnit->StreamUnitID;
    curStreamPortal->toStreamUnit = streamUnit;
    color = GetFogColor(curStreamPortal, mainStreamUnit, mainStreamUnit->level);
    DrawFogRectangle(cliprect, gameTrackerX.primPool, 0xbff, drawot, color);
    PushMatrix();
    StreamRenderLevel(streamUnit, mainStreamUnit->level, drawot, color);
    MulMatrix0();
    puVar2 = (gameTrackerX.primPool)->nextPrim;
    (gameTrackerX.primPool)->nextPrim = puVar2 + 3;
    local_2c = *(u_char *)&cliprect->w;
    local_30._0_2_ = (short)*(u_char *)cliprect;
    local_30 = CONCAT22((short)((u_int) * (u_char *)cliprect >> 0x10) +
                            (&draw)[gameTrackerX.drawPage].ofs[1],
                        (short)local_30 + (&draw)[gameTrackerX.drawPage].ofs[0]);
    SetDrawStp((int)puVar2, (u_short *)&local_30);
    *puVar2 = (u_int)drawot[0xbfe] & 0xffffff | 0x2000000;
    drawot[0xbfe] = (u_long *)((u_int)puVar2 & 0xffffff);
    if ((streamUnit->flags & 8U) == 0)
    {
      DRAW_TranslucentQuad(cliprect->x, cliprect->y,
                           (short)(((u_int)(u_short)cliprect->x + (u_int)(u_short)cliprect->w) * 0x10000 >> 0x10),
                           cliprect->y, (int)cliprect->x,
                           (int)(((u_int)(u_short)cliprect->y + (u_int)(u_short)cliprect->h) * 0x10000) >> 0x10,
                           (int)(((u_int)(u_short)cliprect->x + (u_int)(u_short)cliprect->w) * 0x10000) >> 0x10,
                           (int)(((u_int)(u_short)cliprect->y + (u_int)(u_short)cliprect->h) * 0x10000) >> 0x10,
                           0x32, 0x32, 0x32, 1, gameTrackerX.primPool, drawot + 1);
      DRAW_TranslucentQuad(cliprect->x, cliprect->y,
                           (short)(((u_int)(u_short)cliprect->x + (u_int)(u_short)cliprect->w) * 0x10000 >> 0x10),
                           cliprect->y, (int)cliprect->x,
                           (int)(((u_int)(u_short)cliprect->y + (u_int)(u_short)cliprect->h) * 0x10000) >> 0x10,
                           (int)(((u_int)(u_short)cliprect->x + (u_int)(u_short)cliprect->w) * 0x10000) >> 0x10,
                           (int)(((u_int)(u_short)cliprect->y + (u_int)(u_short)cliprect->h) * 0x10000) >> 0x10,
                           0x32, 0x32, 0x32, 2, gameTrackerX.primPool, drawot + 1);
    }
    puVar2 = (gameTrackerX.primPool)->nextPrim;
    (gameTrackerX.primPool)->nextPrim = puVar2 + 3;
    local_30 = *(u_char *)(&draw)[gameTrackerX.drawPage].ofs;
    local_2c = 0xf00200;
    SetDrawStp((int)puVar2, (u_short *)&local_30);
    *puVar2 = (u_int)drawot[1] & 0xffffff | 0x2000000;
    iVar1 = s_zval;
    drawot[1] = (u_long *)((u_int)puVar2 & 0xffffff);
    puVar2 = mainOT[iVar1];
    mainOT[iVar1] = drawot[0xbff];
    *drawot = puVar2;
  }
  return;
}

void STREAM_TryAndDumpANonResidentObject(void)

{
  _Instance *instance;
  _StreamUnit *p_Var1;
  _ObjectTracker *tracker;
  int iVar2;
  Object *object;
  _Instance *p_Var3;

  p_Var3 = (gameTrackerX.instanceList)->first;
  while (instance = p_Var3, instance != (_Instance *)0x0)
  {
    object = instance->object;
    p_Var3 = instance->next;
    if (((object->oflags & 0x2000000U) == 0) &&
        (p_Var1 = STREAM_GetStreamUnitWithID(instance->birthStreamUnitID),
         p_Var1 == (_StreamUnit *)0x0))
    {
      tracker = FindObjectName(object);
      iVar2 = STREAM_IsObjectInAnyUnit(tracker);
      if (iVar2 == 0)
      {
        INSTANCE_ReallyRemoveInstance(gameTrackerX.instanceList, instance, 0);
      }
    }
  }
  STREAM_RemoveAllObjectsNotInUse(&gameTrackerX);
  return;
}

int STREAM_DumpNonResidentObjects(_ObjectTracker *otr)

{
  _Instance **pp_Var1;
  _Instance *instance;
  u_int uVar2;
  int iVar3;
  _Instance *p_Var4;

  uVar2 = 0;
  if ((otr->objectStatus == 2) && (uVar2 = 0, (otr->object->oflags & 0x2000000U) == 0))
  {
    iVar3 = STREAM_IsObjectInAnyUnit(otr);
    uVar2 = 0;
    if (iVar3 == 0)
    {
      p_Var4 = (gameTrackerX.instanceList)->first;
      if (p_Var4 != (_Instance *)0x0)
      {
        do
        {
          pp_Var1 = &p_Var4->next;
          if (p_Var4->object == otr->object)
          {
            if (p_Var4->LinkParent != (_Instance *)0x0)
            {
              return 0;
            }
            if (p_Var4->LinkChild != (_Instance *)0x0)
            {
              return 0;
            }
            if (p_Var4->LinkSibling != (_Instance *)0x0)
            {
              return 0;
            }
          }
          p_Var4 = *pp_Var1;
        } while (*pp_Var1 != (_Instance *)0x0);
        p_Var4 = (gameTrackerX.instanceList)->first;
      }
      while (instance = p_Var4, instance != (_Instance *)0x0)
      {
        p_Var4 = instance->next;
        if (instance->object == otr->object)
        {
          SAVE_Instance(instance);
          INSTANCE_ReallyRemoveInstance(gameTrackerX.instanceList, instance, 0);
        }
      }
      STREAM_RemoveAllObjectsNotInUse(&gameTrackerX);
      uVar2 = (u_int)(otr->objectStatus == 0);
    }
  }
  return uVar2;
}
