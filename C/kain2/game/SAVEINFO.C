#include "THISDUST.H"
#include "SAVEINFO.H"

// SavedBasic * @0x800D59D0, len = 0x00000004
bufferSavedIntroArray64 = null;
// _GlobalSaveTracker * @0x800CF8A8, len = 0x00000004
GlobalSave = 00000000;
// long @0x800CF8AC, len = 0x00000004
numbufferedIntros = 0x0;
// long[10] @0x800CF8B4, len = 0x00000028
SaveArraySize =
    {
        0x0,
        0x28,
        0x10,
        0x8,
        0x342,
        0x4,
        0x78,
        0x20,
        0xc,
        0xa};
// SavedInfoTracker @0x800D59C0, len = 0x00000010
savedInfoTracker =
    {
        // char * @0x800D59C0, len = 0x00000004
        .MemoryCardBuffer = null,
        // char * @0x800D59C4, len = 0x00000004
        .InfoStart = null,
        // char * @0x800D59C8, len = 0x00000004
        .InfoEnd = null,
        // char * @0x800D59CC, len = 0x00000004
        .EndOfMemory = null};
// int @0x800CF8B0, len = 0x00000004
the_header_size = 0x0;
// decompiled code
// original method signature:
// void /*$ra*/ SAVE_GetInstanceRotation(struct _Instance *instance /*$s0*/, struct _SmallRotation *vector /*$s1*/)
// line 103, offset 0x800b5560
/* begin block 1 */
// Start line: 104
// Start offset: 0x800B5560
// Variables:
// 		struct evPositionData *rotation; // $v1
/* end block 1 */
// End offset: 0x800B55D4
// End Line: 121

/* begin block 2 */
// Start line: 191
/* end block 2 */
// End Line: 192

/* begin block 3 */
// Start line: 206
/* end block 3 */
// End Line: 207

void SAVE_GetInstanceRotation(_Instance *instance, _SmallRotation *vector)

{
  short *psVar1;

  psVar1 = (short *)INSTANCE_Query(instance, 7);
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

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_ClearMemory(struct GameTracker *gameTracker /*$a0*/)
// line 124, offset 0x800b55e8
/* begin block 1 */
// Start line: 125
// Start offset: 0x800B55E8
// Variables:
// 		char *buffer; // $v0
/* end block 1 */
// End offset: 0x800B55E8
// End Line: 125

/* begin block 2 */
// Start line: 233
/* end block 2 */
// End Line: 234

void SAVE_ClearMemory(GameTracker *gameTracker)

{
  _GlobalSaveTracker *p_Var1;

  savedInfoTracker.InfoStart = savedInfoTracker.MemoryCardBuffer + the_header_size;
  savedInfoTracker.EndOfMemory = savedInfoTracker.MemoryCardBuffer + 0x6000;
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart;
  memset(savedInfoTracker.InfoStart, 0, 0x6000 - the_header_size);
  numbufferedIntros = 0;
  memset(&bufferSavedIntroArray64, 0, 0x100);
  p_Var1 = (_GlobalSaveTracker *)SAVE_GetSavedBlock(6, 0);
  GlobalSave = p_Var1;
  p_Var1->CurrentBirthID = 0x2000;
  p_Var1->humanOpinionOfRaziel = 0;
  SAVE_GetSavedBlock(4, 0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_Init(struct GameTracker *gt /*$s0*/)
// line 148, offset 0x800b5668
/* begin block 1 */
// Start line: 149
// Start offset: 0x800B5668
// Variables:
// 		void *buffer; // $s1

/* begin block 1.1 */
// Start line: 158
// Start offset: 0x800B5698
/* end block 1.1 */
// End offset: 0x800B5698
// End Line: 160
/* end block 1 */
// End offset: 0x800B56CC
// End Line: 169

/* begin block 2 */
// Start line: 302
/* end block 2 */
// End Line: 303

void SAVE_Init(GameTracker *gt)

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
    the_header_size = memcard_initialize(&gMemcard, gt, 3, buffer, 0x6000);
  }
  savedInfoTracker.MemoryCardBuffer = buffer;
  SAVE_ClearMemory(gt);
  return;
}

// decompiled code
// original method signature:
// void * /*$ra*/ SAVE_GetSavedBlock(long saveType /*$s3*/, long extraSize /*$s0*/)
// line 189, offset 0x800b56ec
/* begin block 1 */
// Start line: 190
// Start offset: 0x800B56EC
// Variables:
// 		struct SavedBasic *savedInfo; // $s2
// 		long sizeOfSave; // $s0
// 		long done; // $s1
/* end block 1 */
// End offset: 0x800B57E8
// End Line: 232

/* begin block 2 */
// Start line: 386
/* end block 2 */
// End Line: 387

void *SAVE_GetSavedBlock(long saveType, long extraSize)

{
  bool bVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;

  pcVar5 = (char *)0x0;
  if (9 < saveType)
  {
    DEBUG_FatalError(s_illegal_save_type__d_800cf8dc);
  }
  iVar4 = (SaveArraySize[saveType] + extraSize + 3 >> 2) * 4;
  bVar1 = false;
  if (0x3fc < iVar4)
  {
    DEBUG_FatalError(s_save__d_is_too_big___type__d__800cf8f4);
  }
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
        DEBUG_FatalError(s_ran_out_of_saved_memory__needed___800cf914);
      }
    }
  } while (!bVar1);
  return pcVar5;
}

// decompiled code
// original method signature:
// long /*$ra*/ SAVE_PurgeAMemoryBlock()
// line 237, offset 0x800b5808
/* begin block 1 */
// Start line: 238
// Start offset: 0x800B5808
// Variables:
// 		struct SavedBasic *curSave; // $a0
// 		long result; // $a1
/* end block 1 */
// End offset: 0x800B5898
// End Line: 259

/* begin block 2 */
// Start line: 488
/* end block 2 */
// End Line: 489

/* WARNING: Unknown calling convention yet parameter storage is locked */

long SAVE_PurgeAMemoryBlock(void)

{
  SavedBasic *savedBlock;

  savedBlock = (SavedBasic *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      if (((savedBlock->savedID == '\x01') && ((*(uint *)(savedBlock + 0x12) & 0x100) != 0)) ||
          ((savedBlock->savedID == '\a' && ((*(uint *)(savedBlock + 8) & 0x100) != 0))))
      {
        SAVE_DeleteBlock(savedBlock);
        return 1;
      }
      savedBlock = savedBlock + (uint)savedBlock->shiftedSaveSize * 2;
    } while (savedBlock < savedInfoTracker.InfoEnd);
  }
  return 0;
}

// decompiled code
// original method signature:
// long /*$ra*/ SAVE_SaveableInstance(struct _Instance *instance /*$a0*/)
// line 265, offset 0x800b58a8
/* begin block 1 */
// Start line: 267
// Start offset: 0x800B58A8
// Variables:
// 		long result; // $a1
/* end block 1 */
// End offset: 0x800B599C
// End Line: 320

/* begin block 2 */
// Start line: 551
/* end block 2 */
// End Line: 552

/* begin block 3 */
// Start line: 552
/* end block 3 */
// End Line: 553

/* begin block 4 */
// Start line: 554
/* end block 4 */
// End Line: 555

long SAVE_SaveableInstance(_Instance *instance)

{
  Object *pOVar1;
  uint uVar2;

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
          uVar2 = (uint)((instance->flags2 & 8U) != 0);
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
  if ((((uVar2 == 1) && (instance->currentStreamUnitID == instance->birthStreamUnitID)) &&
       (instance->introUniqueID < 0x2000)) &&
      (instance->intro != (Intro *)0x0))
  {
    uVar2 = 2;
  }
  return uVar2;
}

// decompiled code
// original method signature:
// struct _SavedIntro * /*$ra*/ SAVE_UpdateSavedIntro(struct _Instance *instance /*$s1*/, struct Level *level /*$a1*/, struct _SavedIntro *savedIntro /*$s0*/, struct evControlSaveDataData *extraData /*$s2*/)
// line 471, offset 0x800b59a4
/* begin block 1 */
// Start line: 472
// Start offset: 0x800B59A4
// Variables:
// 		struct _Position *levelOffset; // $t1

/* begin block 1.1 */
// Start line: 483
// Start offset: 0x800B59D4
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $a2
// 		short _z0; // $v1
// 		short _x1; // $a3
// 		short _y1; // $t0
// 		short _z1; // $t1
// 		struct _Position *_v; // $v0
// 		struct _Position *_v0; // $v1
/* end block 1.1 */
// End offset: 0x800B59D4
// End Line: 483
/* end block 1 */
// End offset: 0x800B5A94
// End Line: 510

/* begin block 2 */
// Start line: 942
/* end block 2 */
// End Line: 943

_SavedIntro *
SAVE_UpdateSavedIntro(_Instance *instance, Level *level, _SavedIntro *savedIntro, evControlSaveDataData *extraData)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  BSPTree *pBVar5;
  undefined4 uVar6;

  pBVar5 = level->terrain->BSPTreeArray;
  if (savedIntro != (_SavedIntro *)0x0)
  {
    uVar6 = *(undefined4 *)(instance->introName + 4);
    *(undefined4 *)savedIntro->name = *(undefined4 *)instance->introName;
    *(undefined4 *)(savedIntro->name + 4) = uVar6;
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
    savedIntro->attachedUniqueID = *(ushort *)&instance->attachedID;
    if (extraData != (evControlSaveDataData *)0x0)
    {
      memcpy(savedIntro + 1, extraData->data, extraData->length);
    }
  }
  return savedIntro;
}

// decompiled code
// original method signature:
// struct _SavedIntroWithIntro * /*$ra*/ SAVE_UpdateSavedIntroWithIntro(struct _Instance *instance /*$s1*/, struct Level *level /*$a1*/, struct _SavedIntroWithIntro *savedIntro /*$s0*/, struct evControlSaveDataData *extraData /*$s2*/)
// line 513, offset 0x800b5ab0
/* begin block 1 */
// Start line: 514
// Start offset: 0x800B5AB0
// Variables:
// 		struct _Position *levelOffset; // $t1

/* begin block 1.1 */
// Start line: 525
// Start offset: 0x800B5AF0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $a2
// 		short _z0; // $v1
// 		short _x1; // $a3
// 		short _y1; // $t0
// 		short _z1; // $t1
// 		struct _Position *_v; // $v0
// 		struct _Position *_v0; // $v1
/* end block 1.1 */
// End offset: 0x800B5AF0
// End Line: 525
/* end block 1 */
// End offset: 0x800B5BCC
// End Line: 553

/* begin block 2 */
// Start line: 916
/* end block 2 */
// End Line: 917

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
    savedIntro->attachedUniqueID = *(ushort *)&instance->attachedID;
    if (extraData != (evControlSaveDataData *)0x0)
    {
      memcpy(savedIntro + 1, extraData->data, extraData->length);
    }
  }
  return savedIntro;
}

// decompiled code
// original method signature:
// struct SavedBasic * /*$ra*/ SAVE_GetSavedEvent(long areaID /*$a0*/, long eventNumber /*$a1*/)
// line 556, offset 0x800b5be8
/* begin block 1 */
// Start line: 558
// Start offset: 0x800B5BE8
// Variables:
// 		struct SavedBasic *curSave; // $v1
/* end block 1 */
// End offset: 0x800B5C88
// End Line: 577

/* begin block 2 */
// Start line: 1022
/* end block 2 */
// End Line: 1023

/* begin block 3 */
// Start line: 1023
/* end block 3 */
// End Line: 1024

/* begin block 4 */
// Start line: 1025
/* end block 4 */
// End Line: 1026

SavedBasic *SAVE_GetSavedEvent(long areaID, long eventNumber)

{
  uchar uVar1;
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
          ((uint)pSVar2[2].savedID == eventNumber))
      {
        return pSVar2;
      }
      pSVar2 = pSVar2 + (uint)pSVar2->shiftedSaveSize * 2;
    } while (pSVar2 < savedInfoTracker.InfoEnd);
  }
  return (SavedBasic *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_DeleteSavedEvent(long areaID /*$a0*/, long eventNumber /*$a1*/)
// line 579, offset 0x800b5c90
/* begin block 1 */
// Start line: 580
// Start offset: 0x800B5C90
// Variables:
// 		struct SavedBasic *savedEvent; // $v0
/* end block 1 */
// End offset: 0x800B5CB0
// End Line: 589

/* begin block 2 */
// Start line: 1068
/* end block 2 */
// End Line: 1069

void SAVE_DeleteSavedEvent(long areaID, long eventNumber)

{
  SavedBasic *savedBlock;

  savedBlock = SAVE_GetSavedEvent(areaID, eventNumber);
  if (savedBlock != (SavedBasic *)0x0)
  {
    SAVE_DeleteBlock(savedBlock);
  }
  return;
}

// decompiled code
// original method signature:
// struct SavedBasic * /*$ra*/ SAVE_GetSavedNextEvent(long areaID /*$a0*/, struct SavedBasic *curSave /*$a1*/)
// line 591, offset 0x800b5cc0
/* begin block 1 */
// Start line: 1092
/* end block 1 */
// End Line: 1093

/* begin block 2 */
// Start line: 1093
/* end block 2 */
// End Line: 1094

SavedBasic *SAVE_GetSavedNextEvent(long areaID, SavedBasic *curSave)

{
  SavedBasic *pSVar1;

  pSVar1 = (SavedBasic *)savedInfoTracker.InfoStart;
  if (curSave != (SavedBasic *)0x0)
  {
    pSVar1 = curSave + (uint)curSave->shiftedSaveSize * 2;
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
    pSVar1 = pSVar1 + (uint)pSVar1->shiftedSaveSize * 2;
  }
  return pSVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_BufferIntro(struct SavedBasic *savedIntro /*$a0*/)
// line 619, offset 0x800b5d64
/* begin block 1 */
// Start line: 621
// Start offset: 0x800B5D64
// Variables:
// 		long i; // $a1
/* end block 1 */
// End offset: 0x800B5DDC
// End Line: 655

/* begin block 2 */
// Start line: 1148
/* end block 2 */
// End Line: 1149

/* begin block 3 */
// Start line: 1149
/* end block 3 */
// End Line: 1150

/* begin block 4 */
// Start line: 1151
/* end block 4 */
// End Line: 1152

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

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_IntroduceBufferIntros()
// line 657, offset 0x800b5de4
/* begin block 1 */
// Start line: 658
// Start offset: 0x800B5DE4
// Variables:
// 		long i; // $s2
// 		struct _StreamUnit *streamUnit; // $v0

/* begin block 1.1 */
// Start line: 664
// Start offset: 0x800B5E10
// Variables:
// 		int deleted; // stack offset -24

/* begin block 1.1.1 */
// Start line: 670
// Start offset: 0x800B5E38
/* end block 1.1.1 */
// End offset: 0x800B5E60
// End Line: 686

/* begin block 1.1.2 */
// Start line: 692
// Start offset: 0x800B5E60
/* end block 1.1.2 */
// End offset: 0x800B5E98
// End Line: 711
/* end block 1.1 */
// End offset: 0x800B5E98
// End Line: 713
/* end block 1 */
// End offset: 0x800B5EA8
// End Line: 714

/* begin block 2 */
// Start line: 1232
/* end block 2 */
// End Line: 1233

/* begin block 3 */
// Start line: 1236
/* end block 3 */
// End Line: 1237

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_IntroduceBufferIntros(void)

{
  _StreamUnit *streamUnit;
  _Instance *p_Var1;
  _SavedIntro *savedIntro;
  int iVar2;
  int aiStack24[2];

  iVar2 = 0;
  if (numbufferedIntros != 0)
  {
    do
    {
      if (0x3f < iVar2)
      {
        return;
      }
      savedIntro = (_SavedIntro *)(&bufferSavedIntroArray64)[iVar2];
      if (savedIntro != (_SavedIntro *)0x0)
      {
        if (savedIntro->savedID == '\x01')
        {
          streamUnit = STREAM_GetStreamUnitWithID((int)savedIntro->streamUnitID);
          if (streamUnit != (_StreamUnit *)0x0)
          {
            p_Var1 = INSTANCE_IntroduceSavedInstance(savedIntro, streamUnit, aiStack24);
          LAB_800b5e80:
            if (p_Var1 == (_Instance *)0x0)
              goto LAB_800b5e98;
          }
        }
        else
        {
          streamUnit = STREAM_GetStreamUnitWithID((int)*(short *)(savedIntro->name + 2));
          if (streamUnit != (_StreamUnit *)0x0)
          {
            p_Var1 = INSTANCE_IntroduceSavedInstanceWithIntro((_SavedIntroWithIntro *)savedIntro, streamUnit, aiStack24);
            goto LAB_800b5e80;
          }
        }
        *(_SavedIntro **)(&bufferSavedIntroArray64 + iVar2) = (_SavedIntro *)0x0;
        numbufferedIntros = numbufferedIntros + -1;
      }
    LAB_800b5e98:
      iVar2 = iVar2 + 1;
    } while (numbufferedIntros != 0);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_IntroForStreamID(struct _StreamUnit *streamUnit /*$s2*/)
// line 716, offset 0x800b5ec0
/* begin block 1 */
// Start line: 717
// Start offset: 0x800B5EC0
// Variables:
// 		struct SavedBasic *saveIntro; // $s0
// 		long streamID; // $s1
// 		int deleted; // stack offset -24
/* end block 1 */
// End offset: 0x800B5F84
// End Line: 741

/* begin block 2 */
// Start line: 1410
/* end block 2 */
// End Line: 1411

void SAVE_IntroForStreamID(_StreamUnit *streamUnit)

{
  _SavedIntro *savedIntro;
  int iVar1;
  int local_18[2];

  iVar1 = streamUnit->StreamUnitID;
  savedIntro = (_SavedIntro *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    do
    {
      local_18[0] = 0;
      if ((savedIntro->savedID == '\x01') && ((int)savedIntro->streamUnitID == iVar1))
      {
        INSTANCE_IntroduceSavedInstance(savedIntro, streamUnit, local_18);
      }
      else
      {
        if ((savedIntro->savedID == '\a') && ((int)*(short *)(savedIntro->name + 2) == iVar1))
        {
          INSTANCE_IntroduceSavedInstanceWithIntro((_SavedIntroWithIntro *)savedIntro, streamUnit, local_18);
        }
      }
      if (local_18[0] == 0)
      {
        savedIntro = (_SavedIntro *)(&savedIntro->savedID + (uint)savedIntro->shiftedSaveSize * 4);
      }
    } while (savedIntro < savedInfoTracker.InfoEnd);
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ SAVE_HasSavedIntro(struct Intro *intro /*$a0*/, long currentStreamID /*$a1*/)
// line 743, offset 0x800b5f9c
/* begin block 1 */
// Start line: 745
// Start offset: 0x800B5F9C
// Variables:
// 		long result; // $a3
// 		struct _SavedIntro *saveIntro; // $a1
/* end block 1 */
// End offset: 0x800B6024
// End Line: 767

/* begin block 2 */
// Start line: 1472
/* end block 2 */
// End Line: 1473

/* begin block 3 */
// Start line: 1473
/* end block 3 */
// End Line: 1474

/* begin block 4 */
// Start line: 1476
/* end block 4 */
// End Line: 1477

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
      pcVar1 = pcVar1 + (uint)(byte)pcVar1[1] * 4;
    } while (pcVar1 < savedInfoTracker.InfoEnd);
  }
  return 0;
}

// decompiled code
// original method signature:
// struct SavedLevel * /*$ra*/ SAVE_HasSavedLevel(long areaID /*$a0*/)
// line 795, offset 0x800b602c
/* begin block 1 */
// Start line: 797
// Start offset: 0x800B602C
// Variables:
// 		struct SavedLevel *savedLevel; // $v1
/* end block 1 */
// End offset: 0x800B6080
// End Line: 812

/* begin block 2 */
// Start line: 1581
/* end block 2 */
// End Line: 1582

/* begin block 3 */
// Start line: 1582
/* end block 3 */
// End Line: 1583

/* begin block 4 */
// Start line: 1584
/* end block 4 */
// End Line: 1585

SavedLevel *SAVE_HasSavedLevel(long areaID)

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
      pSVar1 = (SavedLevel *)(&pSVar1->savedID + (uint)pSVar1->shiftedSaveSize * 4);
    } while (pSVar1 < savedInfoTracker.InfoEnd);
  }
  return (SavedLevel *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_UpdateLevelWithSave(struct _StreamUnit *streamUnit /*$s0*/)
// line 814, offset 0x800b6090
/* begin block 1 */
// Start line: 815
// Start offset: 0x800B6090
// Variables:
// 		long i; // $t2
// 		struct ActualSavedLevel *savedLevel; // $t3
// 		struct _Terrain *terrain; // $t4
// 		struct BSPTree *bspTree; // $v1
// 		long Zoffset; // $s1
/* end block 1 */
// End offset: 0x800B61C8
// End Line: 858

/* begin block 2 */
// Start line: 1619
/* end block 2 */
// End Line: 1620

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
  ushort uVar9;
  SavedLevel *pSVar10;
  int iVar11;
  _Terrain *p_Var12;

  sVar2 = (streamUnit->level->terrain->BSPTreeArray->globalOffset).z;
  pSVar7 = SAVE_HasSavedLevel(streamUnit->StreamUnitID);
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
        pBVar8 = p_Var12->BSPTreeArray + (uint) * (byte *)((int)&pSVar10[1].numberBSPTreesSaved + 1);
        sVar3 = pSVar10[1].waterZ;
        *(undefined4 *)&pBVar8->localOffset = *(undefined4 *)(pSVar10 + 1);
        (pBVar8->localOffset).z = sVar3;
        sVar3 = (pBVar8->globalOffset).x;
        sVar4 = (pBVar8->localOffset).x;
        sVar5 = (pBVar8->localOffset).y;
        sVar6 = (pBVar8->localOffset).z;
        uVar9 = (ushort)(((int)((uint)(ushort)pBVar8->flags << 0x10) >> 0x18) << 8);
        pBVar8->flags = uVar9;
        bVar1 = *(byte *)&pSVar10[1].numberBSPTreesSaved;
        (pBVar8->globalOffset).x = sVar3 + sVar4;
        (pBVar8->globalOffset).y = (pBVar8->globalOffset).y + sVar5;
        (pBVar8->globalOffset).z = (pBVar8->globalOffset).z + sVar6;
        pBVar8->flags = uVar9 | (ushort)bVar1;
        pSVar10 = pSVar10 + 1;
      } while (iVar11 < (int)pSVar7->numberBSPTreesSaved);
    }
    iVar11 = (int)pSVar7->waterZ;
    if ((iVar11 == -0x7fff) || (iVar11 == 0x7fff))
    {
      streamUnit->level->waterZLevel = (int)pSVar7->waterZ;
    }
    else
    {
      streamUnit->level->waterZLevel = iVar11 + (int)sVar2;
    }
    p_Var12->UnitChangeFlags = p_Var12->UnitChangeFlags | 3;
  }
  return;
}

// decompiled code
// original method signature:
// struct SavedLevel * /*$ra*/ SAVE_CreatedSavedLevel(long areaID /*$s3*/, struct Level *level /*$s2*/)
// line 860, offset 0x800b61dc
/* begin block 1 */
// Start line: 861
// Start offset: 0x800B61DC
// Variables:
// 		struct SavedLevel *savedLevel; // $s0
// 		struct ActualSavedLevel *slevel; // $a0
// 		long doSave; // $a1
// 		long i; // $a1
// 		struct BSPTree *bspTree; // $v1
// 		long Zoffset; // $s4

/* begin block 1.1 */
// Start line: 881
// Start offset: 0x800B623C
// Variables:
// 		long numBSPTrees; // $s1

/* begin block 1.1.1 */
// Start line: 886
// Start offset: 0x800B6258
/* end block 1.1.1 */
// End offset: 0x800B6350
// End Line: 931
/* end block 1.1 */
// End offset: 0x800B6350
// End Line: 932
/* end block 1 */
// End offset: 0x800B6374
// End Line: 943

/* begin block 2 */
// Start line: 1738
/* end block 2 */
// End Line: 1739

SavedLevel *SAVE_CreatedSavedLevel(long areaID, Level *level)

{
  short sVar1;
  ushort uVar2;
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
        ((savedBlock = SAVE_HasSavedLevel(areaID), savedBlock != (SavedLevel *)0x0 ||
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
          if (1 < (ushort)(*(short *)(iVar5 + 0x1a) + 1U))
          {
            *(undefined *)((int)&pSVar6[1].numberBSPTreesSaved + 1) = (char)iVar8;
            sVar1 = *(short *)(iVar5 + 0x18);
            *(undefined4 *)(pSVar6 + 1) = *(undefined4 *)(iVar5 + 0x14);
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
    savedBlock = SAVE_HasSavedLevel(areaID);
    if (savedBlock != (SavedLevel *)0x0)
    {
      SAVE_DeleteBlock((SavedBasic *)savedBlock);
    }
  }
  return savedBlock;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_DeleteBlock(struct SavedBasic *savedBlock /*$a0*/)
// line 947, offset 0x800b6398
/* begin block 1 */
// Start line: 948
// Start offset: 0x800B6398
// Variables:
// 		long size; // $s0
// 		char *nextBlock; // $a1

/* begin block 1.1 */
// Start line: 960
// Start offset: 0x800B63C0
// Variables:
// 		int i; // $a3
/* end block 1.1 */
// End offset: 0x800B63FC
// End Line: 978
/* end block 1 */
// End offset: 0x800B63FC
// End Line: 980

/* begin block 2 */
// Start line: 1932
/* end block 2 */
// End Line: 1933

void SAVE_DeleteBlock(SavedBasic *savedBlock)

{
  uint uVar1;
  SavedBasic *pSVar2;
  SavedBasic **ppSVar3;
  int iVar4;

  uVar1 = (uint)savedBlock->shiftedSaveSize;
  if (numbufferedIntros != 0)
  {
    iVar4 = 0;
    ppSVar3 = &bufferSavedIntroArray64;
    do
    {
      pSVar2 = *ppSVar3;
      if (pSVar2 == savedBlock)
      {
        *ppSVar3 = (SavedBasic *)0x0;
      }
      else
      {
        if (savedBlock < pSVar2)
        {
          *ppSVar3 = pSVar2 + uVar1 * 0x7ffffffe;
        }
      }
      iVar4 = iVar4 + 1;
      ppSVar3 = ppSVar3 + 1;
    } while (iVar4 < 0x40);
  }
  memmove(savedBlock, savedBlock + uVar1 * 2,
          (size_t)(savedInfoTracker.InfoEnd + -(int)(savedBlock + uVar1 * 2)));
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoEnd + uVar1 * -4;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_Instance(struct _Instance *instance /*$s1*/, struct Level *level /*$s3*/)
// line 991, offset 0x800b6424
/* begin block 1 */
// Start line: 992
// Start offset: 0x800B6424
// Variables:
// 		struct _SavedIntro *savedIntro; // $v0
// 		struct evControlSaveDataData *extraData; // $s0
// 		long extraSize; // $s2
// 		long saveType; // $v1

/* begin block 1.1 */
// Start line: 1003
// Start offset: 0x800B646C
// Variables:
// 		struct SavedIntroSmall *savedSmallIntro; // $a0

/* begin block 1.1.1 */
// Start line: 1010
// Start offset: 0x800B648C
/* end block 1.1.1 */
// End offset: 0x800B64A4
// End Line: 1016
/* end block 1.1 */
// End offset: 0x800B64A4
// End Line: 1016

/* begin block 1.2 */
// Start line: 1048
// Start offset: 0x800B6524
// Variables:
// 		struct _SavedIntroWithIntro *savedIntroWithIntro; // $v0
/* end block 1.2 */
// End offset: 0x800B6558
// End Line: 1062

/* begin block 1.3 */
// Start line: 1069
// Start offset: 0x800B6578
// Variables:
// 		struct SavedIntroSpline *savedIntroSpline; // $s0

/* begin block 1.3.1 */
// Start line: 1076
// Start offset: 0x800B6598
// Variables:
// 		struct MultiSpline *multi; // $a1
/* end block 1.3.1 */
// End offset: 0x800B663C
// End Line: 1096
/* end block 1.3 */
// End offset: 0x800B663C
// End Line: 1097
/* end block 1 */
// End offset: 0x800B663C
// End Line: 1102

/* begin block 2 */
// Start line: 2041
/* end block 2 */
// End Line: 2042

void SAVE_Instance(_Instance *instance, Level *level)

{
  long lVar1;
  size_t *psVar2;
  void *pvVar3;
  _SavedIntro *savedIntro;
  evControlSaveDataData *extraData;
  _SavedIntroWithIntro *savedIntro_00;
  undefined *puVar4;
  MultiSpline *spline;
  ushort uVar5;
  long extraSize;

  extraSize = 0;
  lVar1 = SAVE_SaveableInstance(instance);
  if (lVar1 != 0)
  {
    if ((instance->flags2 & 4U) == 0)
    {
      if (lVar1 == 1)
      {
        SAVE_DeleteInstance(instance);
        extraData = (evControlSaveDataData *)INSTANCE_Query(instance, 0x18);
        if (extraData != (evControlSaveDataData *)0x0)
        {
          extraSize = extraData->length;
        }
        savedIntro = (_SavedIntro *)SAVE_GetSavedBlock(1, extraSize);
        if (savedIntro != (_SavedIntro *)0x0)
        {
          SAVE_UpdateSavedIntro(instance, level, savedIntro, extraData);
        }
      }
      else
      {
        if (lVar1 == 2)
        {
          SAVE_DeleteInstance(instance);
          extraData = (evControlSaveDataData *)INSTANCE_Query(instance, 0x18);
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
            SAVE_DeleteInstance(instance);
            puVar4 = (undefined *)SAVE_GetSavedBlock(8, 0);
            if ((puVar4 != (undefined *)0x0) &&
                (spline = SCRIPT_GetMultiSpline(instance, (ulong *)0x0, (ulong *)0x0),
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
              lVar1 = INSTANCE_GetSplineFrameNumber(instance, spline);
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
      SAVE_DeleteInstance(instance);
      psVar2 = (size_t *)INSTANCE_Query(instance, 0x18);
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

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_DeleteInstance(struct _Instance *instance /*$a2*/)
// line 1104, offset 0x800b6658
/* begin block 1 */
// Start line: 1105
// Start offset: 0x800B6658
// Variables:
// 		struct SavedBasic *saveIntro; // $a0
/* end block 1 */
// End offset: 0x800B6718
// End Line: 1132

/* begin block 2 */
// Start line: 2270
/* end block 2 */
// End Line: 2271

void SAVE_DeleteInstance(_Instance *instance)

{
  uchar uVar1;
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
      savedBlock = savedBlock + (uint)savedBlock->shiftedSaveSize * 2;
    } while (savedBlock < savedInfoTracker.InfoEnd);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_SetDeadDeadBit(int uniqueID /*$a0*/, long set /*$a1*/)
// line 1134, offset 0x800b6728
/* begin block 1 */
// Start line: 1136
// Start offset: 0x800B6728
// Variables:
// 		struct _SavedIntro *saveIntro; // $a2
// 		struct SavedDeadDeadBits *deadDeadBits; // $v1

/* begin block 1.1 */
// Start line: 1155
// Start offset: 0x800B6784
// Variables:
// 		int deadByte; // $a2
// 		int deadBit; // $a0
/* end block 1.1 */
// End offset: 0x800B67E4
// End Line: 1177
/* end block 1 */
// End offset: 0x800B67E4
// End Line: 1180

/* begin block 2 */
// Start line: 2336
/* end block 2 */
// End Line: 2337

/* begin block 3 */
// Start line: 2337
/* end block 3 */
// End Line: 2338

/* begin block 4 */
// Start line: 2340
/* end block 4 */
// End Line: 2341

void SAVE_SetDeadDeadBit(int uniqueID, long set)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;

  if (uniqueID < 0x2000)
  {
    pcVar3 = (char *)0x0;
    pcVar4 = savedInfoTracker.InfoStart;
    if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
    {
      do
      {
        pcVar3 = pcVar4;
        if (*pcVar3 == '\x04')
          break;
        pcVar4 = pcVar3 + (uint)(byte)pcVar3[1] * 4;
        pcVar3 = (char *)0x0;
      } while (pcVar4 < savedInfoTracker.InfoEnd);
    }
    if (pcVar3 != (char *)0x0)
    {
      iVar2 = uniqueID;
      if (uniqueID < 0)
      {
        iVar2 = uniqueID + 7;
      }
      iVar2 = iVar2 >> 3;
      if (iVar2 < 0x340)
      {
        bVar1 = (byte)(1 << (uniqueID & 7U));
        if (set == 1)
        {
          (pcVar3 + iVar2)[2] = (pcVar3 + iVar2)[2] | bVar1;
          return;
        }
        (pcVar3 + iVar2)[2] = (pcVar3 + iVar2)[2] & ~bVar1;
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_RestoreGlobalSavePointer()
// line 1182, offset 0x800b67ec
/* begin block 1 */
// Start line: 1184
// Start offset: 0x800B67EC
// Variables:
// 		struct _SavedIntro *saveIntro; // $v1
/* end block 1 */
// End offset: 0x800B683C
// End Line: 1199

/* begin block 2 */
// Start line: 2449
/* end block 2 */
// End Line: 2450

/* begin block 3 */
// Start line: 2450
/* end block 3 */
// End Line: 2451

/* begin block 4 */
// Start line: 2453
/* end block 4 */
// End Line: 2454

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGlobalSavePointer(void)

{
  _GlobalSaveTracker *p_Var1;

  GlobalSave = (_GlobalSaveTracker *)0x0;
  p_Var1 = (_GlobalSaveTracker *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd)
  {
    while (GlobalSave = p_Var1, *(char *)&p_Var1->savedID != '\x06')
    {
      p_Var1 = (_GlobalSaveTracker *)(&p_Var1->savedID + (uint) * (byte *)((int)&p_Var1->savedID + 1) * 2);
      if (savedInfoTracker.InfoEnd <= p_Var1)
      {
        GlobalSave = (_GlobalSaveTracker *)0x0;
        return;
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ SAVE_IsUniqueIDDeadDead(long uniqueID /*$a0*/)
// line 1201, offset 0x800b6844
/* begin block 1 */
// Start line: 1203
// Start offset: 0x800B6844
// Variables:
// 		struct _SavedIntro *saveIntro; // $v1
// 		struct SavedDeadDeadBits *deadDeadBits; // $a2
// 		long result; // $a3

/* begin block 1.1 */
// Start line: 1224
// Start offset: 0x800B68AC
// Variables:
// 		int deadByte; // $a1
// 		int deadBit; // $v1
/* end block 1.1 */
// End offset: 0x800B68E8
// End Line: 1238
/* end block 1 */
// End offset: 0x800B68E8
// End Line: 1240

/* begin block 2 */
// Start line: 2489
/* end block 2 */
// End Line: 2490

/* begin block 3 */
// Start line: 2490
/* end block 3 */
// End Line: 2491

/* begin block 4 */
// Start line: 2491
/* end block 4 */
// End Line: 2492

long SAVE_IsUniqueIDDeadDead(long uniqueID)

{
  long lVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;

  uVar5 = 0;
  if (uniqueID < 0x2000)
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
        pcVar2 = pcVar2 + (uint)(byte)pcVar2[1] * 4;
        pcVar4 = (char *)0x0;
      } while (pcVar2 < savedInfoTracker.InfoEnd);
    }
    if (pcVar4 != (char *)0x0)
    {
      lVar1 = uniqueID;
      if (uniqueID < 0)
      {
        lVar1 = uniqueID + 7;
      }
      uVar3 = 1 << (uniqueID & 7U);
      if (lVar1 >> 3 < 0x340)
      {
        uVar5 = (uint)(((uint)(byte)pcVar4[(lVar1 >> 3) + 2] & uVar3) == uVar3);
      }
    }
  }
  return uVar5;
}

// decompiled code
// original method signature:
// long /*$ra*/ SAVE_IsIntroDeadDead(struct Intro *intro /*$a0*/)
// line 1243, offset 0x800b68f0
/* begin block 1 */
// Start line: 2573
/* end block 1 */
// End Line: 2574

long SAVE_IsIntroDeadDead(Intro *intro)

{
  long lVar1;

  lVar1 = SAVE_IsUniqueIDDeadDead(intro->UniqueID);
  return lVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_DoInstanceDeadDead(struct _Instance *instance /*$s0*/)
// line 1249, offset 0x800b6914
/* begin block 1 */
// Start line: 2585
/* end block 1 */
// End Line: 2586

void SAVE_DoInstanceDeadDead(_Instance *instance)

{
  SAVE_DeleteInstance(instance);
  SAVE_SetDeadDeadBit(instance->introUniqueID, 1);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_MarkDeadDead(struct _Instance *instance /*$a0*/)
// line 1259, offset 0x800b6944
/* begin block 1 */
// Start line: 2605
/* end block 1 */
// End Line: 2606

/* begin block 2 */
// Start line: 2606
/* end block 2 */
// End Line: 2607

void SAVE_MarkDeadDead(_Instance *instance)

{
  instance->flags = instance->flags | 0x800000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_UndestroyInstance(struct _Instance *instance /*$a0*/)
// line 1264, offset 0x800b6958
/* begin block 1 */
// Start line: 2615
/* end block 1 */
// End Line: 2616

void SAVE_UndestroyInstance(_Instance *instance)

{
  SAVE_SetDeadDeadBit(instance->introUniqueID, 0);
  return;
}

// decompiled code
// original method signature:
// struct SavedIntroSmall * /*$ra*/ SAVE_GetSavedSmallIntro(struct _Instance *instance /*$a0*/)
// line 1269, offset 0x800b697c
/* begin block 1 */
// Start line: 1271
// Start offset: 0x800B697C
// Variables:
// 		struct SavedBasic *curSave; // $a1
/* end block 1 */
// End offset: 0x800B69D8
// End Line: 1289

/* begin block 2 */
// Start line: 2625
/* end block 2 */
// End Line: 2626

/* begin block 3 */
// Start line: 2626
/* end block 3 */
// End Line: 2627

/* begin block 4 */
// Start line: 2630
/* end block 4 */
// End Line: 2631

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
      pSVar1 = pSVar1 + (uint)pSVar1->shiftedSaveSize;
    } while (pSVar1 < savedInfoTracker.InfoEnd);
  }
  return (SavedIntroSmall *)0x0;
}

// decompiled code
// original method signature:
// struct SavedIntroSpline * /*$ra*/ SAVE_GetIntroSpline(struct _Instance *instance /*$a0*/)
// line 1291, offset 0x800b69e8
/* begin block 1 */
// Start line: 1293
// Start offset: 0x800B69E8
// Variables:
// 		struct SavedBasic *curSave; // $a1
/* end block 1 */
// End offset: 0x800B6A44
// End Line: 1310

/* begin block 2 */
// Start line: 2669
/* end block 2 */
// End Line: 2670

/* begin block 3 */
// Start line: 2670
/* end block 3 */
// End Line: 2671

/* begin block 4 */
// Start line: 2673
/* end block 4 */
// End Line: 2674

SavedIntroSpline *SAVE_GetIntroSpline(_Instance *instance)

{
  byte *pbVar1;
  uchar *puVar2;
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
      pSVar3 = (SavedIntroSpline *)(puVar2 + (uint)*pbVar1 * 4);
    } while ((SavedIntroSpline *)(puVar2 + (uint)*pbVar1 * 4) < savedInfoTracker.InfoEnd);
  }
  return (SavedIntroSpline *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_UpdateGlobalSaveTracker()
// line 1313, offset 0x800b6a54
/* begin block 1 */
// Start line: 2713
/* end block 1 */
// End Line: 2714

/* begin block 2 */
// Start line: 2714
/* end block 2 */
// End Line: 2715

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_UpdateGlobalSaveTracker(void)

{
  _GlobalSaveTracker *p_Var1;
  ulong uVar2;
  ulong uVar3;
  undefined4 uVar4;
  ushort uVar5;
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
  *(undefined4 *)&(p_Var1->sound).gSfxOn = uVar4;
  GlobalSave->saveVersion = 0x5524;
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

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_RestoreGlobalSaveTracker()
// line 1326, offset 0x800b6ae8
/* begin block 1 */
// Start line: 2740
/* end block 1 */
// End Line: 2741

/* begin block 2 */
// Start line: 2742
/* end block 2 */
// End Line: 2743

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGlobalSaveTracker(void)

{
  if (GlobalSave->saveVersion == 0x5524)
  {
    gameTrackerX.currentTime = GlobalSave->currentTime;
    gameTrackerX.sound.gMasterVol = (GlobalSave->sound).gMasterVol;
    gameTrackerX.sound.gMusicVol = (GlobalSave->sound).gMusicVol;
    gameTrackerX.sound.gSfxVol = (GlobalSave->sound).gSfxVol;
    gameTrackerX.sound.gVoiceVol = (GlobalSave->sound).gVoiceVol;
    gameTrackerX.sound._16_4_ = *(undefined4 *)&(GlobalSave->sound).gSfxOn;
    SOUND_SetSfxVolume(gameTrackerX.sound.gSfxVol);
    SOUND_SetMusicVolume(gameTrackerX.sound.gMusicVol);
    SOUND_SetVoiceVolume(gameTrackerX.sound.gVoiceVol);
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

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_SaveEverythingInMemory()
// line 1354, offset 0x800b6bb8
/* begin block 1 */
// Start line: 1355
// Start offset: 0x800B6BB8
// Variables:
// 		struct _Instance *instance; // $s0
// 		long i; // $s1

/* begin block 1.1 */
// Start line: 1363
// Start offset: 0x800B6BE0
// Variables:
// 		struct _Instance *next; // $s1
// 		struct Level *level; // $v0
/* end block 1.1 */
// End offset: 0x800B6C00
// End Line: 1372
/* end block 1 */
// End offset: 0x800B6C54
// End Line: 1388

/* begin block 2 */
// Start line: 2798
/* end block 2 */
// End Line: 2799

/* begin block 3 */
// Start line: 2804
/* end block 3 */
// End Line: 2805

/* WARNING: Unknown calling convention yet parameter storage is locked */

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
    level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    if (level != (Level *)0x0)
    {
      SAVE_Instance(instance, level);
    }
  }
  iVar3 = 0;
  pSVar1 = &StreamTracker;
  do
  {
    if (pSVar1->StreamList[0].used == 2)
    {
      EVENT_SaveEventsFromLevel(pSVar1->StreamList[0].StreamUnitID, pSVar1->StreamList[0].level);
      SAVE_CreatedSavedLevel(pSVar1->StreamList[0].StreamUnitID, pSVar1->StreamList[0].level);
    }
    iVar3 = iVar3 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar3 < 0x10);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_SaveGame()
// line 1391, offset 0x800b6c6c
/* begin block 1 */
// Start line: 2900
/* end block 1 */
// End Line: 2901

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_SaveGame(void)

{
  int iVar1;

  do
  {
    iVar1 = STREAM_PollLoadQueue();
  } while (iVar1 != 0);
  SAVE_SaveEverythingInMemory();
  SAVE_UpdateGlobalSaveTracker();
  GlobalSave->sizeUsedInBlock = (short)savedInfoTracker.InfoEnd - (short)savedInfoTracker.InfoStart;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SAVE_RestoreGame()
// line 1406, offset 0x800b6cb8
/* begin block 1 */
// Start line: 2930
/* end block 1 */
// End Line: 2931

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGame(void)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
  SAVE_RestoreGlobalSavePointer();
  SAVE_RestoreGlobalSaveTracker();
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart + (int)GlobalSave->sizeUsedInBlock;
  GAMELOOP_RequestLevelChange(s_under_800cf954, 1, &gameTrackerX);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ SAVE_SizeOfFreeSpace()
// line 1500, offset 0x800b6d1c
/* begin block 1 */
// Start line: 3000
/* end block 1 */
// End Line: 3001

/* begin block 2 */
// Start line: 3035
/* end block 2 */
// End Line: 3036

/* WARNING: Unknown calling convention yet parameter storage is locked */

long SAVE_SizeOfFreeSpace(void)

{
  return (long)(savedInfoTracker.EndOfMemory + -(int)savedInfoTracker.InfoEnd);
}
