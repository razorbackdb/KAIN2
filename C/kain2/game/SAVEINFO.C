#include "THISDUST.H"
#include "SAVEINFO.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_GetInstanceRotation(struct _Instance *instance /*$s0*/, struct _SmallRotation *vector /*$s1*/)
 // line 103, offset 0x800b51f8
	/* begin block 1 */
		// Start line: 104
		// Start offset: 0x800B51F8
		// Variables:
	// 		struct evPositionData *rotation; // $v1
	/* end block 1 */
	// End offset: 0x800B526C
	// End Line: 121

	/* begin block 2 */
		// Start line: 191
	/* end block 2 */
	// End Line: 192

	/* begin block 3 */
		// Start line: 206
	/* end block 3 */
	// End Line: 207

void SAVE_GetInstanceRotation(_Instance *instance,_SmallRotation *vector)

{
  short *psVar1;
  
  psVar1 = (short *)INSTANCE_Query(instance,7);
  if (psVar1 == (short *)0x0) {
    vector->x = (instance->rotation).x;
    vector->y = (instance->rotation).y;
    vector->z = (instance->rotation).z;
  }
  else {
    vector->x = *psVar1;
    vector->y = psVar1[1];
    vector->z = psVar1[2];
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_ClearMemory(struct GameTracker *gameTracker /*$a0*/)
 // line 124, offset 0x800b5280
	/* begin block 1 */
		// Start line: 125
		// Start offset: 0x800B5280
		// Variables:
	// 		char *buffer; // $v0
	/* end block 1 */
	// End offset: 0x800B5280
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
  memset(savedInfoTracker.InfoStart,0,0x6000 - the_header_size);
  numbufferedIntros = 0;
  memset(&bufferSavedIntroArray64,0,0x100);
  p_Var1 = (_GlobalSaveTracker *)SAVE_GetSavedBlock(6,0);
  GlobalSave = p_Var1;
  p_Var1->CurrentBirthID = 0x2000;
  p_Var1->humanOpinionOfRaziel = 0;
  SAVE_GetSavedBlock(4,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_Init(struct GameTracker *gt /*$s0*/)
 // line 148, offset 0x800b5300
	/* begin block 1 */
		// Start line: 149
		// Start offset: 0x800B5300
		// Variables:
	// 		void *buffer; // $s1

		/* begin block 1.1 */
			// Start line: 158
			// Start offset: 0x800B5330
		/* end block 1.1 */
		// End offset: 0x800B5330
		// End Line: 160
	/* end block 1 */
	// End offset: 0x800B5364
	// End Line: 169

	/* begin block 2 */
		// Start line: 302
	/* end block 2 */
	// End Line: 303

void SAVE_Init(GameTracker *gt)

{
  char *buffer;
  
  buffer = MEMPACK_Malloc(0x6000,'\x12');
  if (DoMainMenu == 0) {
    gt->memcard = (memcard_t *)0x0;
  }
  else {
    gt->memcard = &gMemcard;
    the_header_size = memcard_initialize(&gMemcard,gt,3,buffer,0x6000);
  }
  savedInfoTracker.MemoryCardBuffer = buffer;
  SAVE_ClearMemory(gt);
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ SAVE_GetSavedBlock(long saveType /*$s3*/, long extraSize /*$s0*/)
 // line 189, offset 0x800b5384
	/* begin block 1 */
		// Start line: 190
		// Start offset: 0x800B5384
		// Variables:
	// 		struct SavedBasic *savedInfo; // $s2
	// 		long sizeOfSave; // $s0
	// 		long done; // $s1
	/* end block 1 */
	// End offset: 0x800B5480
	// End Line: 232

	/* begin block 2 */
		// Start line: 386
	/* end block 2 */
	// End Line: 387

void * SAVE_GetSavedBlock(long saveType,long extraSize)

{
  bool bVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  
  pcVar5 = (char *)0x0;
  if (9 < saveType) {
    DEBUG_FatalError("illegal save type %d\n");
  }
  iVar4 = ((&SaveArraySize)[saveType] + extraSize + 3 >> 2) * 4;
  bVar1 = false;
  if (0x3fc < iVar4) {
    DEBUG_FatalError("save %d is too big! (type %d)\n");
  }
  do {
    pcVar2 = savedInfoTracker.InfoEnd;
    if (savedInfoTracker.InfoEnd + iVar4 < savedInfoTracker.EndOfMemory) {
      *savedInfoTracker.InfoEnd = (char)saveType;
      pcVar2[1] = (char)(iVar4 >> 2);
      savedInfoTracker.InfoEnd = savedInfoTracker.InfoEnd + iVar4;
      bVar1 = true;
      pcVar5 = pcVar2;
    }
    else {
      lVar3 = SAVE_PurgeAMemoryBlock();
      if (lVar3 == 0) {
        bVar1 = true;
        DEBUG_FatalError("ran out of saved memory. needed %d, used %d.\nincrease from %d\n");
      }
    }
  } while (!bVar1);
  return pcVar5;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_PurgeAMemoryBlock()
 // line 237, offset 0x800b54a0
	/* begin block 1 */
		// Start line: 238
		// Start offset: 0x800B54A0
		// Variables:
	// 		struct SavedBasic *curSave; // $a0
	// 		long result; // $a1
	/* end block 1 */
	// End offset: 0x800B5530
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
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if (((savedBlock->savedID == '\x01') && ((*(uint *)(savedBlock + 0x12) & 0x100) != 0)) ||
         ((savedBlock->savedID == '\a' && ((*(uint *)(savedBlock + 8) & 0x100) != 0)))) {
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
 // line 265, offset 0x800b5540
	/* begin block 1 */
		// Start line: 267
		// Start offset: 0x800B5540
		// Variables:
	// 		long result; // $a1
	/* end block 1 */
	// End offset: 0x800B5624
	// End Line: 319

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
    if (((pOVar1->oflags2 & 0x80000U) == 0) && (instance != gameTrackerX.playerInstance)) {
      if ((pOVar1->oflags2 & 0x40000U) == 0) {
        if ((instance->flags & 0x100000U) == 0) {
          uVar2 = 3;
        }
      }
      else {
        uVar2 = 1;
        if ((pOVar1->oflags & 1U) != 0) {
          uVar2 = (uint)((instance->flags2 & 8U) != 0);
        }
      }
    }
    else {
      uVar2 = 1;
    }
  }
  if ((instance->object->oflags2 & 0x100000U) != 0) {
    uVar2 = 0;
  }
  if (((uVar2 == 1) && (instance->currentStreamUnitID == instance->birthStreamUnitID)) &&
     (instance->introUniqueID < 0x2000)) {
    uVar2 = 2;
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// struct _SavedIntro * /*$ra*/ SAVE_UpdateSavedIntro(struct _Instance *instance /*$s1*/, struct Level *level /*$a1*/, struct _SavedIntro *savedIntro /*$s0*/, struct evControlSaveDataData *extraData /*$s2*/)
 // line 470, offset 0x800b562c
	/* begin block 1 */
		// Start line: 471
		// Start offset: 0x800B562C
		// Variables:
	// 		struct _Position *levelOffset; // $t1

		/* begin block 1.1 */
			// Start line: 482
			// Start offset: 0x800B565C
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
		// End offset: 0x800B565C
		// End Line: 482
	/* end block 1 */
	// End offset: 0x800B571C
	// End Line: 509

	/* begin block 2 */
		// Start line: 940
	/* end block 2 */
	// End Line: 941

_SavedIntro *
SAVE_UpdateSavedIntro
          (_Instance *instance,Level *level,_SavedIntro *savedIntro,evControlSaveDataData *extraData
          )

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  BSPTree *pBVar5;
  undefined4 uVar6;
  
  pBVar5 = level->terrain->BSPTreeArray;
  if (savedIntro != (_SavedIntro *)0x0) {
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
    SAVE_GetInstanceRotation(instance,&savedIntro->smallRotation);
    savedIntro->flags = instance->flags;
    savedIntro->flags2 = instance->flags2;
    savedIntro->specturalLightGroup = instance->spectralLightGroup;
    savedIntro->lightGroup = instance->lightGroup;
    savedIntro->attachedUniqueID = *(ushort *)&instance->attachedID;
    if (extraData != (evControlSaveDataData *)0x0) {
      memcpy(savedIntro + 1,extraData->data,extraData->length);
    }
  }
  return savedIntro;
}



// decompiled code
// original method signature: 
// struct _SavedIntroWithIntro * /*$ra*/ SAVE_UpdateSavedIntroWithIntro(struct _Instance *instance /*$s1*/, struct Level *level /*$a1*/, struct _SavedIntroWithIntro *savedIntro /*$s0*/, struct evControlSaveDataData *extraData /*$s2*/)
 // line 512, offset 0x800b5738
	/* begin block 1 */
		// Start line: 513
		// Start offset: 0x800B5738
		// Variables:
	// 		struct _Position *levelOffset; // $t1

		/* begin block 1.1 */
			// Start line: 524
			// Start offset: 0x800B5778
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
		// End offset: 0x800B5778
		// End Line: 524
	/* end block 1 */
	// End offset: 0x800B5854
	// End Line: 552

	/* begin block 2 */
		// Start line: 914
	/* end block 2 */
	// End Line: 915

_SavedIntroWithIntro *
SAVE_UpdateSavedIntroWithIntro
          (_Instance *instance,Level *level,_SavedIntroWithIntro *savedIntro,
          evControlSaveDataData *extraData)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  BSPTree *pBVar5;
  
  pBVar5 = level->terrain->BSPTreeArray;
  if ((savedIntro != (_SavedIntroWithIntro *)0x0) && (instance->intro != (Intro *)0x0)) {
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
    SAVE_GetInstanceRotation(instance,&savedIntro->smallRotation);
    savedIntro->flags = instance->flags;
    savedIntro->flags2 = instance->flags2;
    savedIntro->specturalLightGroup = instance->spectralLightGroup;
    savedIntro->lightGroup = instance->lightGroup;
    savedIntro->attachedUniqueID = *(ushort *)&instance->attachedID;
    if (extraData != (evControlSaveDataData *)0x0) {
      memcpy(savedIntro + 1,extraData->data,extraData->length);
    }
  }
  return savedIntro;
}



// decompiled code
// original method signature: 
// struct SavedBasic * /*$ra*/ SAVE_GetSavedEvent(long areaID /*$a0*/, long eventNumber /*$a1*/)
 // line 555, offset 0x800b5870
	/* begin block 1 */
		// Start line: 557
		// Start offset: 0x800B5870
		// Variables:
	// 		struct SavedBasic *curSave; // $v1
	/* end block 1 */
	// End offset: 0x800B5910
	// End Line: 576

	/* begin block 2 */
		// Start line: 1020
	/* end block 2 */
	// End Line: 1021

	/* begin block 3 */
		// Start line: 1021
	/* end block 3 */
	// End Line: 1022

	/* begin block 4 */
		// Start line: 1023
	/* end block 4 */
	// End Line: 1024

SavedBasic * SAVE_GetSavedEvent(long areaID,long eventNumber)

{
  uchar uVar1;
  SavedBasic *pSVar2;
  
  pSVar2 = (SavedBasic *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      uVar1 = pSVar2->savedID;
      if (uVar1 == '\x02') {
        if (((int)(short)pSVar2[1] == areaID) && ((int)(short)pSVar2[2] == eventNumber)) {
          return pSVar2;
        }
        uVar1 = pSVar2->savedID;
      }
      if (((uVar1 == '\t') && ((int)(short)pSVar2[1] == areaID)) &&
         ((uint)pSVar2[2].savedID == eventNumber)) {
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
 // line 578, offset 0x800b5918
	/* begin block 1 */
		// Start line: 579
		// Start offset: 0x800B5918
		// Variables:
	// 		struct SavedBasic *savedEvent; // $v0
	/* end block 1 */
	// End offset: 0x800B5938
	// End Line: 588

	/* begin block 2 */
		// Start line: 1066
	/* end block 2 */
	// End Line: 1067

void SAVE_DeleteSavedEvent(long areaID,long eventNumber)

{
  SavedBasic *savedBlock;
  
  savedBlock = SAVE_GetSavedEvent(areaID,eventNumber);
  if (savedBlock != (SavedBasic *)0x0) {
    SAVE_DeleteBlock(savedBlock);
  }
  return;
}



// decompiled code
// original method signature: 
// struct SavedBasic * /*$ra*/ SAVE_GetSavedNextEvent(long areaID /*$a0*/, struct SavedBasic *curSave /*$a1*/)
 // line 590, offset 0x800b5948
	/* begin block 1 */
		// Start line: 1090
	/* end block 1 */
	// End Line: 1091

	/* begin block 2 */
		// Start line: 1091
	/* end block 2 */
	// End Line: 1092

SavedBasic * SAVE_GetSavedNextEvent(long areaID,SavedBasic *curSave)

{
  SavedBasic *pSVar1;
  
  pSVar1 = (SavedBasic *)savedInfoTracker.InfoStart;
  if (curSave != (SavedBasic *)0x0) {
    pSVar1 = curSave + (uint)curSave->shiftedSaveSize * 2;
  }
  while( true ) {
    if (savedInfoTracker.InfoEnd <= pSVar1) {
      return (SavedBasic *)0x0;
    }
    if (((pSVar1->savedID == '\x02') && ((int)(short)pSVar1[1] == areaID)) ||
       ((pSVar1->savedID == '\t' && ((int)(short)pSVar1[1] == areaID)))) break;
    pSVar1 = pSVar1 + (uint)pSVar1->shiftedSaveSize * 2;
  }
  return pSVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_BufferIntro(struct SavedBasic *savedIntro /*$a0*/)
 // line 618, offset 0x800b59ec
	/* begin block 1 */
		// Start line: 620
		// Start offset: 0x800B59EC
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800B5A64
	// End Line: 654

	/* begin block 2 */
		// Start line: 1146
	/* end block 2 */
	// End Line: 1147

	/* begin block 3 */
		// Start line: 1147
	/* end block 3 */
	// End Line: 1148

	/* begin block 4 */
		// Start line: 1149
	/* end block 4 */
	// End Line: 1150

void SAVE_BufferIntro(SavedBasic *savedIntro)

{
  SavedBasic **ppSVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (numbufferedIntros < 0x40) {
    ppSVar1 = &bufferSavedIntroArray64;
    do {
      if (*ppSVar1 == savedIntro) break;
      iVar2 = iVar2 + 1;
      ppSVar1 = ppSVar1 + 1;
    } while (iVar2 < 0x40);
    iVar3 = 0;
    if (iVar2 == 0x40) {
      ppSVar1 = &bufferSavedIntroArray64;
      numbufferedIntros = numbufferedIntros + 1;
      do {
        iVar3 = iVar3 + 1;
        if (*ppSVar1 == (SavedBasic *)0x0) {
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
 // line 656, offset 0x800b5a6c
	/* begin block 1 */
		// Start line: 657
		// Start offset: 0x800B5A6C
		// Variables:
	// 		long i; // $s2
	// 		struct _StreamUnit *streamUnit; // $v0

		/* begin block 1.1 */
			// Start line: 663
			// Start offset: 0x800B5A98
			// Variables:
		// 		int deleted; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 669
				// Start offset: 0x800B5AC0
			/* end block 1.1.1 */
			// End offset: 0x800B5AE8
			// End Line: 685

			/* begin block 1.1.2 */
				// Start line: 691
				// Start offset: 0x800B5AE8
			/* end block 1.1.2 */
			// End offset: 0x800B5B20
			// End Line: 710
		/* end block 1.1 */
		// End offset: 0x800B5B20
		// End Line: 712
	/* end block 1 */
	// End offset: 0x800B5B30
	// End Line: 713

	/* begin block 2 */
		// Start line: 1230
	/* end block 2 */
	// End Line: 1231

	/* begin block 3 */
		// Start line: 1234
	/* end block 3 */
	// End Line: 1235

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_IntroduceBufferIntros(void)

{
  _StreamUnit *streamUnit;
  _Instance *p_Var1;
  _SavedIntro *savedIntro;
  int iVar2;
  int aiStack24 [2];
  
  iVar2 = 0;
  if (numbufferedIntros != 0) {
    do {
      if (0x3f < iVar2) {
        return;
      }
      savedIntro = (_SavedIntro *)(&bufferSavedIntroArray64)[iVar2];
      if (savedIntro != (_SavedIntro *)0x0) {
        if (savedIntro->savedID == '\x01') {
          streamUnit = STREAM_GetStreamUnitWithID((int)savedIntro->streamUnitID);
          if (streamUnit != (_StreamUnit *)0x0) {
            p_Var1 = INSTANCE_IntroduceSavedInstance(savedIntro,streamUnit,aiStack24);
LAB_800b5b08:
            if (p_Var1 == (_Instance *)0x0) goto LAB_800b5b20;
          }
        }
        else {
          streamUnit = STREAM_GetStreamUnitWithID((int)*(short *)(savedIntro->name + 2));
          if (streamUnit != (_StreamUnit *)0x0) {
            p_Var1 = INSTANCE_IntroduceSavedInstanceWithIntro
                               ((_SavedIntroWithIntro *)savedIntro,streamUnit,aiStack24);
            goto LAB_800b5b08;
          }
        }
        *(_SavedIntro **)(&bufferSavedIntroArray64 + iVar2) = (_SavedIntro *)0x0;
        numbufferedIntros = numbufferedIntros + -1;
      }
LAB_800b5b20:
      iVar2 = iVar2 + 1;
    } while (numbufferedIntros != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_IntroForStreamID(struct _StreamUnit *streamUnit /*$s2*/)
 // line 715, offset 0x800b5b48
	/* begin block 1 */
		// Start line: 716
		// Start offset: 0x800B5B48
		// Variables:
	// 		struct SavedBasic *saveIntro; // $s0
	// 		long streamID; // $s1
	// 		int deleted; // stack offset -24
	/* end block 1 */
	// End offset: 0x800B5C0C
	// End Line: 740

	/* begin block 2 */
		// Start line: 1408
	/* end block 2 */
	// End Line: 1409

void SAVE_IntroForStreamID(_StreamUnit *streamUnit)

{
  _SavedIntro *savedIntro;
  int iVar1;
  int local_18 [2];
  
  iVar1 = streamUnit->StreamUnitID;
  savedIntro = (_SavedIntro *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      local_18[0] = 0;
      if ((savedIntro->savedID == '\x01') && ((int)savedIntro->streamUnitID == iVar1)) {
        INSTANCE_IntroduceSavedInstance(savedIntro,streamUnit,local_18);
      }
      else {
        if ((savedIntro->savedID == '\a') && ((int)*(short *)(savedIntro->name + 2) == iVar1)) {
          INSTANCE_IntroduceSavedInstanceWithIntro
                    ((_SavedIntroWithIntro *)savedIntro,streamUnit,local_18);
        }
      }
      if (local_18[0] == 0) {
        savedIntro = (_SavedIntro *)(&savedIntro->savedID + (uint)savedIntro->shiftedSaveSize * 4);
      }
    } while (savedIntro < savedInfoTracker.InfoEnd);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_HasSavedIntro(struct Intro *intro /*$a0*/, long currentStreamID /*$a1*/)
 // line 742, offset 0x800b5c24
	/* begin block 1 */
		// Start line: 744
		// Start offset: 0x800B5C24
		// Variables:
	// 		long result; // $a3
	// 		struct _SavedIntro *saveIntro; // $a1
	/* end block 1 */
	// End offset: 0x800B5CAC
	// End Line: 766

	/* begin block 2 */
		// Start line: 1470
	/* end block 2 */
	// End Line: 1471

	/* begin block 3 */
		// Start line: 1471
	/* end block 3 */
	// End Line: 1472

	/* begin block 4 */
		// Start line: 1474
	/* end block 4 */
	// End Line: 1475

long SAVE_HasSavedIntro(Intro *intro,long currentStreamID)

{
  char *pcVar1;
  
  pcVar1 = savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if (((*pcVar1 == '\x01') && ((int)*(short *)(pcVar1 + 0xc) == intro->UniqueID)) ||
         ((*pcVar1 == '\a' && ((int)*(short *)(pcVar1 + 8) == intro->UniqueID)))) {
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
 // line 794, offset 0x800b5cb4
	/* begin block 1 */
		// Start line: 796
		// Start offset: 0x800B5CB4
		// Variables:
	// 		struct SavedLevel *savedLevel; // $v1
	/* end block 1 */
	// End offset: 0x800B5D08
	// End Line: 811

	/* begin block 2 */
		// Start line: 1579
	/* end block 2 */
	// End Line: 1580

	/* begin block 3 */
		// Start line: 1580
	/* end block 3 */
	// End Line: 1581

	/* begin block 4 */
		// Start line: 1582
	/* end block 4 */
	// End Line: 1583

SavedLevel * SAVE_HasSavedLevel(long areaID)

{
  SavedLevel *pSVar1;
  
  pSVar1 = (SavedLevel *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((pSVar1->savedID == '\x03') && ((int)pSVar1->areaID == areaID)) {
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
 // line 813, offset 0x800b5d18
	/* begin block 1 */
		// Start line: 814
		// Start offset: 0x800B5D18
		// Variables:
	// 		long i; // $t2
	// 		struct ActualSavedLevel *savedLevel; // $t3
	// 		struct _Terrain *terrain; // $t4
	// 		struct BSPTree *bspTree; // $v1
	// 		long Zoffset; // $s1
	/* end block 1 */
	// End offset: 0x800B5E50
	// End Line: 857

	/* begin block 2 */
		// Start line: 1617
	/* end block 2 */
	// End Line: 1618

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
  if (pSVar7 != (SavedLevel *)0x0) {
    p_Var12 = streamUnit->level->terrain;
    iVar11 = 0;
    pSVar10 = pSVar7;
    if (0 < pSVar7->numberBSPTreesSaved) {
      do {
        iVar11 = iVar11 + 1;
        pBVar8 = p_Var12->BSPTreeArray + *(byte *)((int)&pSVar10[1].numberBSPTreesSaved + 1);
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
        pBVar8->flags = uVar9 | bVar1;
        pSVar10 = pSVar10 + 1;
      } while (iVar11 < pSVar7->numberBSPTreesSaved);
    }
    iVar11 = (int)pSVar7->waterZ;
    if ((iVar11 == -0x7fff) || (iVar11 == 0x7fff)) {
      streamUnit->level->waterZLevel = (int)pSVar7->waterZ;
    }
    else {
      streamUnit->level->waterZLevel = iVar11 + sVar2;
    }
    p_Var12->UnitChangeFlags = p_Var12->UnitChangeFlags | 3;
  }
  return;
}



// decompiled code
// original method signature: 
// struct SavedLevel * /*$ra*/ SAVE_CreatedSavedLevel(long areaID /*$s3*/, struct Level *level /*$s2*/)
 // line 859, offset 0x800b5e64
	/* begin block 1 */
		// Start line: 860
		// Start offset: 0x800B5E64
		// Variables:
	// 		struct SavedLevel *savedLevel; // $s0
	// 		struct ActualSavedLevel *slevel; // $a0
	// 		long doSave; // $a1
	// 		long i; // $a1
	// 		struct BSPTree *bspTree; // $v1
	// 		long Zoffset; // $s4

		/* begin block 1.1 */
			// Start line: 880
			// Start offset: 0x800B5EC4
			// Variables:
		// 		long numBSPTrees; // $s1

			/* begin block 1.1.1 */
				// Start line: 885
				// Start offset: 0x800B5EE0
			/* end block 1.1.1 */
			// End offset: 0x800B5FD8
			// End Line: 930
		/* end block 1.1 */
		// End offset: 0x800B5FD8
		// End Line: 931
	/* end block 1 */
	// End offset: 0x800B5FFC
	// End Line: 942

	/* begin block 2 */
		// Start line: 1736
	/* end block 2 */
	// End Line: 1737

SavedLevel * SAVE_CreatedSavedLevel(long areaID,Level *level)

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
  if (((uVar2 & 1) != 0) || ((uVar2 & 2) != 0)) {
    bVar3 = true;
  }
  if (bVar3) {
    iVar8 = level->terrain->numBSPTrees + -2;
    savedBlock = (SavedLevel *)0x0;
    if ((0 < iVar8) &&
       ((savedBlock = SAVE_HasSavedLevel(areaID), savedBlock != (SavedLevel *)0x0 ||
        (savedBlock = (SavedLevel *)SAVE_GetSavedBlock(3,iVar8 * 8), savedBlock != (SavedLevel *)0x0
        )))) {
      savedBlock->areaID = (short)areaID;
      if ((level->waterZLevel == -0x7fff) || (level->waterZLevel == 0x7fff)) {
        savedBlock->waterZ = *(short *)&level->waterZLevel;
      }
      else {
        savedBlock->waterZ = *(short *)&level->waterZLevel - sVar1;
      }
      savedBlock->numberBSPTreesSaved = (short)iVar8;
      p_Var4 = level->terrain;
      iVar8 = 0;
      if (0 < p_Var4->numBSPTrees) {
        iVar7 = 0;
        pSVar6 = savedBlock;
        do {
          iVar5 = (int)&p_Var4->BSPTreeArray->bspRoot + iVar7;
          if (1 < (ushort)(*(short *)(iVar5 + 0x1a) + 1U)) {
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
  else {
    savedBlock = SAVE_HasSavedLevel(areaID);
    if (savedBlock != (SavedLevel *)0x0) {
      SAVE_DeleteBlock((SavedBasic *)savedBlock);
    }
  }
  return savedBlock;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DeleteBlock(struct SavedBasic *savedBlock /*$a0*/)
 // line 946, offset 0x800b6020
	/* begin block 1 */
		// Start line: 947
		// Start offset: 0x800B6020
		// Variables:
	// 		long size; // $s0
	// 		char *nextBlock; // $a1

		/* begin block 1.1 */
			// Start line: 959
			// Start offset: 0x800B6048
			// Variables:
		// 		int i; // $a3
		/* end block 1.1 */
		// End offset: 0x800B6084
		// End Line: 977
	/* end block 1 */
	// End offset: 0x800B6084
	// End Line: 979

	/* begin block 2 */
		// Start line: 1930
	/* end block 2 */
	// End Line: 1931

void SAVE_DeleteBlock(SavedBasic *savedBlock)

{
  uint uVar1;
  SavedBasic *pSVar2;
  SavedBasic **ppSVar3;
  int iVar4;
  
  uVar1 = (uint)savedBlock->shiftedSaveSize;
  if (numbufferedIntros != 0) {
    iVar4 = 0;
    ppSVar3 = &bufferSavedIntroArray64;
    do {
      pSVar2 = *ppSVar3;
      if (pSVar2 == savedBlock) {
        *ppSVar3 = (SavedBasic *)0x0;
      }
      else {
        if (savedBlock < pSVar2) {
          *ppSVar3 = pSVar2 + uVar1 * 0x7ffffffe;
        }
      }
      iVar4 = iVar4 + 1;
      ppSVar3 = ppSVar3 + 1;
    } while (iVar4 < 0x40);
  }
  memmove(savedBlock,savedBlock + uVar1 * 2,
          (size_t)(savedInfoTracker.InfoEnd + -(int)(savedBlock + uVar1 * 2)));
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoEnd + uVar1 * -4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_Instance(struct _Instance *instance /*$s1*/, struct Level *level /*$s3*/)
 // line 990, offset 0x800b60ac
	/* begin block 1 */
		// Start line: 991
		// Start offset: 0x800B60AC
		// Variables:
	// 		struct _SavedIntro *savedIntro; // $v0
	// 		struct evControlSaveDataData *extraData; // $s0
	// 		long extraSize; // $s2
	// 		long saveType; // $v1

		/* begin block 1.1 */
			// Start line: 1002
			// Start offset: 0x800B60F4
			// Variables:
		// 		struct SavedIntroSmall *savedSmallIntro; // $a0

			/* begin block 1.1.1 */
				// Start line: 1009
				// Start offset: 0x800B6114
			/* end block 1.1.1 */
			// End offset: 0x800B612C
			// End Line: 1015
		/* end block 1.1 */
		// End offset: 0x800B612C
		// End Line: 1015

		/* begin block 1.2 */
			// Start line: 1047
			// Start offset: 0x800B61AC
			// Variables:
		// 		struct _SavedIntroWithIntro *savedIntroWithIntro; // $v0
		/* end block 1.2 */
		// End offset: 0x800B61E0
		// End Line: 1061

		/* begin block 1.3 */
			// Start line: 1068
			// Start offset: 0x800B6200
			// Variables:
		// 		struct SavedIntroSpline *savedIntroSpline; // $s0

			/* begin block 1.3.1 */
				// Start line: 1075
				// Start offset: 0x800B6220
				// Variables:
			// 		struct MultiSpline *multi; // $a1
			/* end block 1.3.1 */
			// End offset: 0x800B62C4
			// End Line: 1095
		/* end block 1.3 */
		// End offset: 0x800B62C4
		// End Line: 1096
	/* end block 1 */
	// End offset: 0x800B62C4
	// End Line: 1101

	/* begin block 2 */
		// Start line: 2039
	/* end block 2 */
	// End Line: 2040

void SAVE_Instance(_Instance *instance,Level *level)

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
  if (lVar1 != 0) {
    if ((instance->flags2 & 4U) == 0) {
      if (lVar1 == 1) {
        SAVE_DeleteInstance(instance);
        extraData = (evControlSaveDataData *)INSTANCE_Query(instance,0x18);
        if (extraData != (evControlSaveDataData *)0x0) {
          extraSize = extraData->length;
        }
        savedIntro = (_SavedIntro *)SAVE_GetSavedBlock(1,extraSize);
        if (savedIntro != (_SavedIntro *)0x0) {
          SAVE_UpdateSavedIntro(instance,level,savedIntro,extraData);
        }
      }
      else {
        if (lVar1 == 2) {
          SAVE_DeleteInstance(instance);
          extraData = (evControlSaveDataData *)INSTANCE_Query(instance,0x18);
          if (extraData != (evControlSaveDataData *)0x0) {
            extraSize = extraData->length;
          }
          savedIntro_00 = (_SavedIntroWithIntro *)SAVE_GetSavedBlock(7,extraSize);
          if (savedIntro_00 != (_SavedIntroWithIntro *)0x0) {
            SAVE_UpdateSavedIntroWithIntro(instance,level,savedIntro_00,extraData);
          }
        }
        else {
          if (lVar1 == 3) {
            SAVE_DeleteInstance(instance);
            puVar4 = (undefined *)SAVE_GetSavedBlock(8,0);
            if ((puVar4 != (undefined *)0x0) &&
               (spline = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0),
               spline != (MultiSpline *)0x0)) {
              uVar5 = instance->splineFlags & 0xfe7f;
              instance->splineFlags = uVar5;
              if ((instance->flags & 0x1000000U) != 0) {
                instance->splineFlags = uVar5 | 0x80;
              }
              if ((instance->flags & 0x2000000U) != 0) {
                instance->splineFlags = instance->splineFlags | 0x100;
              }
              *puVar4 = 8;
              *(undefined2 *)(puVar4 + 2) = *(undefined2 *)&instance->introUniqueID;
              *(short *)(puVar4 + 4) = instance->splineFlags;
              lVar1 = INSTANCE_GetSplineFrameNumber(instance,spline);
              *(short *)(puVar4 + 6) = (short)lVar1;
              *(short *)(puVar4 + 8) = instance->clipBeg;
              *(short *)(puVar4 + 10) = instance->clipEnd;
            }
          }
        }
      }
    }
    else {
      SAVE_DeleteInstance(instance);
      psVar2 = (size_t *)INSTANCE_Query(instance,0x18);
      if ((psVar2 != (size_t *)0x0) &&
         (pvVar3 = SAVE_GetSavedBlock(5,*psVar2), pvVar3 != (void *)0x0)) {
        *(undefined2 *)((int)pvVar3 + 2) = *(undefined2 *)&instance->introUniqueID;
        memcpy((void *)((int)pvVar3 + 4),(void *)psVar2[1],*psVar2);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DeleteInstance(struct _Instance *instance /*$a2*/)
 // line 1103, offset 0x800b62e0
	/* begin block 1 */
		// Start line: 1104
		// Start offset: 0x800B62E0
		// Variables:
	// 		struct SavedBasic *saveIntro; // $a0
	/* end block 1 */
	// End offset: 0x800B63A0
	// End Line: 1131

	/* begin block 2 */
		// Start line: 2268
	/* end block 2 */
	// End Line: 2269

void SAVE_DeleteInstance(_Instance *instance)

{
  uchar uVar1;
  SavedBasic *savedBlock;
  
  savedBlock = (SavedBasic *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      uVar1 = savedBlock->savedID;
      if (((((uVar1 == '\x01') && ((int)(short)savedBlock[6] == instance->introUniqueID)) ||
           ((uVar1 == '\a' && ((int)(short)savedBlock[4] == instance->introUniqueID)))) ||
          ((uVar1 == '\x05' && ((int)(short)savedBlock[1] == instance->introUniqueID)))) ||
         ((uVar1 == '\b' && ((int)(short)savedBlock[1] == instance->introUniqueID)))) {
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
 // line 1133, offset 0x800b63b0
	/* begin block 1 */
		// Start line: 1135
		// Start offset: 0x800B63B0
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $a2
	// 		struct SavedDeadDeadBits *deadDeadBits; // $v1

		/* begin block 1.1 */
			// Start line: 1154
			// Start offset: 0x800B640C
			// Variables:
		// 		int deadByte; // $a2
		// 		int deadBit; // $a0
		/* end block 1.1 */
		// End offset: 0x800B646C
		// End Line: 1176
	/* end block 1 */
	// End offset: 0x800B646C
	// End Line: 1179

	/* begin block 2 */
		// Start line: 2334
	/* end block 2 */
	// End Line: 2335

	/* begin block 3 */
		// Start line: 2335
	/* end block 3 */
	// End Line: 2336

	/* begin block 4 */
		// Start line: 2338
	/* end block 4 */
	// End Line: 2339

void SAVE_SetDeadDeadBit(int uniqueID,long set)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (uniqueID < 0x2000) {
    pcVar3 = (char *)0x0;
    pcVar4 = savedInfoTracker.InfoStart;
    if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
      do {
        pcVar3 = pcVar4;
        if (*pcVar3 == '\x04') break;
        pcVar4 = pcVar3 + (uint)(byte)pcVar3[1] * 4;
        pcVar3 = (char *)0x0;
      } while (pcVar4 < savedInfoTracker.InfoEnd);
    }
    if (pcVar3 != (char *)0x0) {
      iVar2 = uniqueID;
      if (uniqueID < 0) {
        iVar2 = uniqueID + 7;
      }
      iVar2 = iVar2 >> 3;
      if (iVar2 < 0x340) {
        bVar1 = (byte)(1 << (uniqueID & 7U));
        if (set == 1) {
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
 // line 1181, offset 0x800b6474
	/* begin block 1 */
		// Start line: 1183
		// Start offset: 0x800B6474
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $v1
	/* end block 1 */
	// End offset: 0x800B64C4
	// End Line: 1198

	/* begin block 2 */
		// Start line: 2447
	/* end block 2 */
	// End Line: 2448

	/* begin block 3 */
		// Start line: 2448
	/* end block 3 */
	// End Line: 2449

	/* begin block 4 */
		// Start line: 2451
	/* end block 4 */
	// End Line: 2452

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGlobalSavePointer(void)

{
  _GlobalSaveTracker *p_Var1;
  
  GlobalSave = (_GlobalSaveTracker *)0x0;
  p_Var1 = (_GlobalSaveTracker *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    while (GlobalSave = p_Var1, *(char *)&p_Var1->savedID != '\x06') {
      p_Var1 = (_GlobalSaveTracker *)
               (&p_Var1->savedID + (uint)*(byte *)((int)&p_Var1->savedID + 1) * 2);
      if (savedInfoTracker.InfoEnd <= p_Var1) {
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
 // line 1200, offset 0x800b64cc
	/* begin block 1 */
		// Start line: 1202
		// Start offset: 0x800B64CC
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $v1
	// 		struct SavedDeadDeadBits *deadDeadBits; // $a2
	// 		long result; // $a3

		/* begin block 1.1 */
			// Start line: 1223
			// Start offset: 0x800B6534
			// Variables:
		// 		int deadByte; // $a1
		// 		int deadBit; // $v1
		/* end block 1.1 */
		// End offset: 0x800B6570
		// End Line: 1237
	/* end block 1 */
	// End offset: 0x800B6570
	// End Line: 1239

	/* begin block 2 */
		// Start line: 2487
	/* end block 2 */
	// End Line: 2488

	/* begin block 3 */
		// Start line: 2488
	/* end block 3 */
	// End Line: 2489

	/* begin block 4 */
		// Start line: 2489
	/* end block 4 */
	// End Line: 2490

long SAVE_IsUniqueIDDeadDead(long uniqueID)

{
  long lVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (uniqueID < 0x2000) {
    pcVar2 = savedInfoTracker.InfoStart;
    pcVar4 = (char *)0x0;
    if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
      do {
        pcVar4 = pcVar2;
        if (*pcVar2 == '\x04') break;
        pcVar2 = pcVar2 + (uint)(byte)pcVar2[1] * 4;
        pcVar4 = (char *)0x0;
      } while (pcVar2 < savedInfoTracker.InfoEnd);
    }
    if (pcVar4 != (char *)0x0) {
      lVar1 = uniqueID;
      if (uniqueID < 0) {
        lVar1 = uniqueID + 7;
      }
      uVar3 = 1 << (uniqueID & 7U);
      if (lVar1 >> 3 < 0x340) {
        uVar5 = (uint)(((byte)pcVar4[(lVar1 >> 3) + 2] & uVar3) == uVar3);
      }
    }
  }
  return uVar5;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_IsIntroDeadDead(struct Intro *intro /*$a0*/)
 // line 1242, offset 0x800b6578
	/* begin block 1 */
		// Start line: 2571
	/* end block 1 */
	// End Line: 2572

long SAVE_IsIntroDeadDead(Intro *intro)

{
  long lVar1;
  
  lVar1 = SAVE_IsUniqueIDDeadDead(intro->UniqueID);
  return lVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DoInstanceDeadDead(struct _Instance *instance /*$s0*/)
 // line 1248, offset 0x800b659c
	/* begin block 1 */
		// Start line: 2583
	/* end block 1 */
	// End Line: 2584

void SAVE_DoInstanceDeadDead(_Instance *instance)

{
  SAVE_DeleteInstance(instance);
  SAVE_SetDeadDeadBit(instance->introUniqueID,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_MarkDeadDead(struct _Instance *instance /*$a0*/)
 // line 1258, offset 0x800b65cc
	/* begin block 1 */
		// Start line: 2603
	/* end block 1 */
	// End Line: 2604

	/* begin block 2 */
		// Start line: 2604
	/* end block 2 */
	// End Line: 2605

void SAVE_MarkDeadDead(_Instance *instance)

{
  instance->flags = instance->flags | 0x800000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_UndestroyInstance(struct _Instance *instance /*$a0*/)
 // line 1263, offset 0x800b65e0
	/* begin block 1 */
		// Start line: 2613
	/* end block 1 */
	// End Line: 2614

void SAVE_UndestroyInstance(_Instance *instance)

{
  SAVE_SetDeadDeadBit(instance->introUniqueID,0);
  return;
}



// decompiled code
// original method signature: 
// struct SavedIntroSmall * /*$ra*/ SAVE_GetSavedSmallIntro(struct _Instance *instance /*$a0*/)
 // line 1268, offset 0x800b6604
	/* begin block 1 */
		// Start line: 1270
		// Start offset: 0x800B6604
		// Variables:
	// 		struct SavedBasic *curSave; // $a1
	/* end block 1 */
	// End offset: 0x800B6660
	// End Line: 1288

	/* begin block 2 */
		// Start line: 2623
	/* end block 2 */
	// End Line: 2624

	/* begin block 3 */
		// Start line: 2624
	/* end block 3 */
	// End Line: 2625

	/* begin block 4 */
		// Start line: 2628
	/* end block 4 */
	// End Line: 2629

SavedIntroSmall * SAVE_GetSavedSmallIntro(_Instance *instance)

{
  SavedIntroSmall *pSVar1;
  
  pSVar1 = (SavedIntroSmall *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((pSVar1->savedID == '\x05') && ((int)pSVar1->introUniqueID == instance->introUniqueID)) {
        return pSVar1;
      }
      pSVar1 = pSVar1 + pSVar1->shiftedSaveSize;
    } while (pSVar1 < savedInfoTracker.InfoEnd);
  }
  return (SavedIntroSmall *)0x0;
}



// decompiled code
// original method signature: 
// struct SavedIntroSpline * /*$ra*/ SAVE_GetIntroSpline(struct _Instance *instance /*$a0*/)
 // line 1290, offset 0x800b6670
	/* begin block 1 */
		// Start line: 1292
		// Start offset: 0x800B6670
		// Variables:
	// 		struct SavedBasic *curSave; // $a1
	/* end block 1 */
	// End offset: 0x800B66CC
	// End Line: 1309

	/* begin block 2 */
		// Start line: 2667
	/* end block 2 */
	// End Line: 2668

	/* begin block 3 */
		// Start line: 2668
	/* end block 3 */
	// End Line: 2669

	/* begin block 4 */
		// Start line: 2671
	/* end block 4 */
	// End Line: 2672

SavedIntroSpline * SAVE_GetIntroSpline(_Instance *instance)

{
  byte *pbVar1;
  uchar *puVar2;
  SavedIntroSpline *pSVar3;
  
  pSVar3 = (SavedIntroSpline *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((pSVar3->savedID == '\b') && ((int)pSVar3->introUniqueID == instance->introUniqueID)) {
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
 // line 1312, offset 0x800b66dc
	/* begin block 1 */
		// Start line: 2711
	/* end block 1 */
	// End Line: 2712

	/* begin block 2 */
		// Start line: 2712
	/* end block 2 */
	// End Line: 2713

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
  GlobalSave->saveVersion = 0x5521;
  iVar6 = GAMEPAD_DualShockEnabled();
  if (iVar6 == 0) {
    uVar5 = GlobalSave->flags & 0xfffd;
  }
  else {
    uVar5 = GlobalSave->flags | 2;
  }
  GlobalSave->flags = uVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_RestoreGlobalSaveTracker()
 // line 1325, offset 0x800b6770
	/* begin block 1 */
		// Start line: 2738
	/* end block 1 */
	// End Line: 2739

	/* begin block 2 */
		// Start line: 2740
	/* end block 2 */
	// End Line: 2741

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGlobalSaveTracker(void)

{
  if (GlobalSave->saveVersion == 0x5521) {
    gameTrackerX.currentTime = GlobalSave->currentTime;
    gameTrackerX.sound.gMasterVol = (GlobalSave->sound).gMasterVol;
    gameTrackerX.sound.gMusicVol = (GlobalSave->sound).gMusicVol;
    gameTrackerX.sound.gSfxVol = (GlobalSave->sound).gSfxVol;
    gameTrackerX.sound.gVoiceVol = (GlobalSave->sound).gVoiceVol;
    gameTrackerX.sound._16_4_ = *(undefined4 *)&(GlobalSave->sound).gSfxOn;
    SOUND_SetSfxVolume(gameTrackerX.sound.gSfxVol);
    SOUND_SetMusicVolume(gameTrackerX.sound.gMusicVol);
    SOUND_SetVoiceVolume(gameTrackerX.sound.gVoiceVol);
    if ((GlobalSave->flags & 2U) == 0) {
      GAMEPAD_DisableDualShock();
    }
    else {
      GAMEPAD_EnableDualShock();
    }
  }
  else {
    DEBUG_FatalError("error: old save game\n");
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_SaveEverythingInMemory()
 // line 1353, offset 0x800b6840
	/* begin block 1 */
		// Start line: 1354
		// Start offset: 0x800B6840
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		long i; // $s1

		/* begin block 1.1 */
			// Start line: 1362
			// Start offset: 0x800B6868
			// Variables:
		// 		struct _Instance *next; // $s1
		// 		struct Level *level; // $v0
		/* end block 1.1 */
		// End offset: 0x800B6888
		// End Line: 1371
	/* end block 1 */
	// End offset: 0x800B68DC
	// End Line: 1387

	/* begin block 2 */
		// Start line: 2796
	/* end block 2 */
	// End Line: 2797

	/* begin block 3 */
		// Start line: 2802
	/* end block 3 */
	// End Line: 2803

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_SaveEverythingInMemory(void)

{
  _Instance *instance;
  Level *level;
  STracker *pSVar1;
  _Instance *p_Var2;
  int iVar3;
  
  p_Var2 = (gameTrackerX.instanceList)->first;
  while (instance = p_Var2, instance != (_Instance *)0x0) {
    p_Var2 = instance->next;
    level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    if (level != (Level *)0x0) {
      SAVE_Instance(instance,level);
    }
  }
  iVar3 = 0;
  pSVar1 = &StreamTracker;
  do {
    if (pSVar1->StreamList[0].used == 2) {
      EVENT_SaveEventsFromLevel(pSVar1->StreamList[0].StreamUnitID,pSVar1->StreamList[0].level);
      SAVE_CreatedSavedLevel(pSVar1->StreamList[0].StreamUnitID,pSVar1->StreamList[0].level);
    }
    iVar3 = iVar3 + 1;
    pSVar1 = (STracker *)(pSVar1->StreamList + 1);
  } while (iVar3 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_SaveGame()
 // line 1390, offset 0x800b68f4
	/* begin block 1 */
		// Start line: 2898
	/* end block 1 */
	// End Line: 2899

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_SaveGame(void)

{
  int iVar1;
  
  do {
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
 // line 1405, offset 0x800b6940
	/* begin block 1 */
		// Start line: 2928
	/* end block 1 */
	// End Line: 2929

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGame(void)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
  SAVE_RestoreGlobalSavePointer();
  SAVE_RestoreGlobalSaveTracker();
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart + GlobalSave->sizeUsedInBlock;
  GAMELOOP_RequestLevelChange("under",1,&gameTrackerX);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DebugSaveGame()
 // line 1421, offset 0x800b69a4
	/* begin block 1 */
		// Start line: 2963
	/* end block 1 */
	// End Line: 2964

	/* begin block 2 */
		// Start line: 2991
	/* end block 2 */
	// End Line: 2992

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_DebugSaveGame(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_LoadSaveGame()
 // line 1489, offset 0x800b69ac
	/* begin block 1 */
		// Start line: 2978
	/* end block 1 */
	// End Line: 2979

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_LoadSaveGame(void)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
  GAMELOOP_RequestLevelChange("under",1,&gameTrackerX);
  gameTrackerX.gameMode = 0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_SizeOfFreeSpace()
 // line 1499, offset 0x800b69e8
	/* begin block 1 */
		// Start line: 3085
	/* end block 1 */
	// End Line: 3086

	/* begin block 2 */
		// Start line: 3086
	/* end block 2 */
	// End Line: 3087

/* WARNING: Unknown calling convention yet parameter storage is locked */

long SAVE_SizeOfFreeSpace(void)

{
  return (long)(savedInfoTracker.EndOfMemory + -(int)savedInfoTracker.InfoEnd);
}





