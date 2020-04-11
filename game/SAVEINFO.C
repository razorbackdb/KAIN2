
#include "SAVEINFO.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_GetInstanceRotation(struct _Instance *instance /*$s0*/, struct _SmallRotation *vector /*$s1*/)
 // line 104, offset 0x800b3ea8
	/* begin block 1 */
		// Start line: 105
		// Start offset: 0x800B3EA8
		// Variables:
	// 		struct evPositionData *rotation; // $v1
	/* end block 1 */
	// End offset: 0x800B3F1C
	// End Line: 122

	/* begin block 2 */
		// Start line: 192
	/* end block 2 */
	// End Line: 193

	/* begin block 3 */
		// Start line: 193
	/* end block 3 */
	// End Line: 194

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 125, offset 0x800b3f30
	/* begin block 1 */
		// Start line: 126
		// Start offset: 0x800B3F30
		// Variables:
	// 		char *buffer; // $v0
	/* end block 1 */
	// End offset: 0x800B3F30
	// End Line: 126

	/* begin block 2 */
		// Start line: 234
	/* end block 2 */
	// End Line: 235

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_ClearMemory(GameTracker *gameTracker)

{
  savedInfoTracker.InfoStart = savedInfoTracker.MemoryCardBuffer + the_header_size;
  savedInfoTracker.EndOfMemory = savedInfoTracker.MemoryCardBuffer + 0x6000;
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart;
  memset();
  numbufferedIntros = 0;
  memset();
  GlobalSave = (_GlobalSaveTracker *)SAVE_GetSavedBlock(6,0);
  GlobalSave->CurrentBirthID = 0x2000;
  GlobalSave->humanOpinionOfRaziel = -1;
  SAVE_GetSavedBlock(4,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_Init(struct GameTracker *gt /*$s0*/)
 // line 149, offset 0x800b3fb8
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x800B3FB8
		// Variables:
	// 		void *buffer; // $s1

		/* begin block 1.1 */
			// Start line: 159
			// Start offset: 0x800B3FE8
		/* end block 1.1 */
		// End offset: 0x800B3FE8
		// End Line: 161
	/* end block 1 */
	// End offset: 0x800B401C
	// End Line: 170

	/* begin block 2 */
		// Start line: 304
	/* end block 2 */
	// End Line: 305

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_Init(GameTracker *gt)

{
  char *buffer;
  
  buffer = MEMPACK_Malloc(0x6000,'\x12');
  if (DoMainMenu == 0) {
    gt->memcard = (memcard_t *)0x0;
  }
  else {
    gt->memcard = (memcard_t *)&gMemcard;
    the_header_size = memcard_initialize((memcard_t *)&gMemcard,gt,3,buffer,0x6000);
  }
  savedInfoTracker.MemoryCardBuffer = buffer;
  SAVE_ClearMemory(gt);
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ SAVE_GetSavedBlock(long saveType /*$s4*/, long extraSize /*$a1*/)
 // line 190, offset 0x800b403c
	/* begin block 1 */
		// Start line: 191
		// Start offset: 0x800B403C
		// Variables:
	// 		struct SavedBasic *savedInfo; // $s1
	// 		long sizeOfSave; // $s0
	// 		long done; // $s2
	/* end block 1 */
	// End offset: 0x800B4100
	// End Line: 231

	/* begin block 2 */
		// Start line: 388
	/* end block 2 */
	// End Line: 389

/* File: C:\kain2\game\SAVEINFO.C */

void * SAVE_GetSavedBlock(long saveType,long extraSize)

{
  bool bVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  
  pcVar5 = (char *)0x0;
  bVar1 = false;
  iVar4 = (SaveArraySize[saveType] + extraSize + 3 >> 2) * 4;
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
        FONT_Print(s_Ran_out_of_saved_memory__Needed___800d0bd0);
      }
    }
  } while (!bVar1);
  return pcVar5;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_PurgeAMemoryBlock()
 // line 236, offset 0x800b4120
	/* begin block 1 */
		// Start line: 237
		// Start offset: 0x800B4120
		// Variables:
	// 		struct SavedBasic *curSave; // $a0
	// 		long result; // $a1
	/* end block 1 */
	// End offset: 0x800B41B0
	// End Line: 258

	/* begin block 2 */
		// Start line: 491
	/* end block 2 */
	// End Line: 492

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 264, offset 0x800b41c0
	/* begin block 1 */
		// Start line: 266
		// Start offset: 0x800B41C0
		// Variables:
	// 		long result; // $a1
	/* end block 1 */
	// End offset: 0x800B42A4
	// End Line: 318

	/* begin block 2 */
		// Start line: 554
	/* end block 2 */
	// End Line: 555

	/* begin block 3 */
		// Start line: 555
	/* end block 3 */
	// End Line: 556

	/* begin block 4 */
		// Start line: 557
	/* end block 4 */
	// End Line: 558

/* File: C:\kain2\game\SAVEINFO.C */

long SAVE_SaveableInstance(_Instance *instance)

{
  Object *pOVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (((instance->flags2 & 0x20000U) == 0) && (pOVar1 = instance->object, pOVar1 != (Object *)0x0))
  {
    if (((pOVar1->oflags2 & 0x80000U) == 0) && (instance != DAT_800d20f8)) {
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
 // line 464, offset 0x800b42ac
	/* begin block 1 */
		// Start line: 465
		// Start offset: 0x800B42AC
		// Variables:
	// 		struct _Position *levelOffset; // $t1

		/* begin block 1.1 */
			// Start line: 476
			// Start offset: 0x800B42DC
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
		// End offset: 0x800B42DC
		// End Line: 476
	/* end block 1 */
	// End offset: 0x800B439C
	// End Line: 503

	/* begin block 2 */
		// Start line: 924
	/* end block 2 */
	// End Line: 925

/* File: C:\kain2\game\SAVEINFO.C */

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
      memcpy();
    }
  }
  return savedIntro;
}



// decompiled code
// original method signature: 
// struct _SavedIntroWithIntro * /*$ra*/ SAVE_UpdateSavedIntroWithIntro(struct _Instance *instance /*$s1*/, struct Level *level /*$a1*/, struct _SavedIntroWithIntro *savedIntro /*$s0*/, struct evControlSaveDataData *extraData /*$s2*/)
 // line 506, offset 0x800b43b8
	/* begin block 1 */
		// Start line: 507
		// Start offset: 0x800B43B8
		// Variables:
	// 		struct _Position *levelOffset; // $t1

		/* begin block 1.1 */
			// Start line: 518
			// Start offset: 0x800B43F8
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
		// End offset: 0x800B43F8
		// End Line: 518
	/* end block 1 */
	// End offset: 0x800B44D4
	// End Line: 546

	/* begin block 2 */
		// Start line: 912
	/* end block 2 */
	// End Line: 913

/* File: C:\kain2\game\SAVEINFO.C */

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
      memcpy();
    }
  }
  return savedIntro;
}



// decompiled code
// original method signature: 
// struct SavedBasic * /*$ra*/ SAVE_GetSavedEvent(long areaID /*$a0*/, long eventNumber /*$a1*/)
 // line 549, offset 0x800b44f0
	/* begin block 1 */
		// Start line: 551
		// Start offset: 0x800B44F0
		// Variables:
	// 		struct SavedBasic *curSave; // $v1
	/* end block 1 */
	// End offset: 0x800B4590
	// End Line: 570

	/* begin block 2 */
		// Start line: 1018
	/* end block 2 */
	// End Line: 1019

	/* begin block 3 */
		// Start line: 1019
	/* end block 3 */
	// End Line: 1020

	/* begin block 4 */
		// Start line: 1021
	/* end block 4 */
	// End Line: 1022

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 572, offset 0x800b4598
	/* begin block 1 */
		// Start line: 573
		// Start offset: 0x800B4598
		// Variables:
	// 		struct SavedBasic *savedEvent; // $v0
	/* end block 1 */
	// End offset: 0x800B45B8
	// End Line: 582

	/* begin block 2 */
		// Start line: 1064
	/* end block 2 */
	// End Line: 1065

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 584, offset 0x800b45c8
	/* begin block 1 */
		// Start line: 1088
	/* end block 1 */
	// End Line: 1089

	/* begin block 2 */
		// Start line: 1089
	/* end block 2 */
	// End Line: 1090

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 612, offset 0x800b466c
	/* begin block 1 */
		// Start line: 614
		// Start offset: 0x800B466C
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800B46EC
	// End Line: 647

	/* begin block 2 */
		// Start line: 1144
	/* end block 2 */
	// End Line: 1145

	/* begin block 3 */
		// Start line: 1145
	/* end block 3 */
	// End Line: 1146

	/* begin block 4 */
		// Start line: 1147
	/* end block 4 */
	// End Line: 1148

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_BufferIntro(SavedBasic *savedIntro)

{
  SavedBasic **ppSVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (numbufferedIntros < 0x40) {
    ppSVar1 = bufferSavedIntroArray;
    do {
      if (*ppSVar1 == (SavedBasic *)savedIntro) break;
      iVar2 = iVar2 + 1;
      ppSVar1 = ppSVar1 + 1;
    } while (iVar2 < 0x40);
    iVar3 = 0;
    if (iVar2 == 0x40) {
      ppSVar1 = bufferSavedIntroArray;
      numbufferedIntros = numbufferedIntros + 1;
      do {
        iVar3 = iVar3 + 1;
        if (*ppSVar1 == (SavedBasic *)0x0) {
          *(SavedBasic **)ppSVar1 = savedIntro;
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
 // line 649, offset 0x800b46f4
	/* begin block 1 */
		// Start line: 650
		// Start offset: 0x800B46F4
		// Variables:
	// 		long i; // $s2
	// 		struct _StreamUnit *streamUnit; // $v0

		/* begin block 1.1 */
			// Start line: 663
			// Start offset: 0x800B4748
		/* end block 1.1 */
		// End offset: 0x800B476C
		// End Line: 679

		/* begin block 1.2 */
			// Start line: 685
			// Start offset: 0x800B476C
		/* end block 1.2 */
		// End offset: 0x800B47A0
		// End Line: 704
	/* end block 1 */
	// End offset: 0x800B47B0
	// End Line: 709

	/* begin block 2 */
		// Start line: 1226
	/* end block 2 */
	// End Line: 1227

	/* begin block 3 */
		// Start line: 1230
	/* end block 3 */
	// End Line: 1231

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_IntroduceBufferIntros(void)

{
  _StreamUnit *streamUnit;
  _Instance *p_Var1;
  int iVar2;
  _SavedIntro *savedIntro;
  int iVar3;
  
  if (numbufferedIntros < 0x40) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      savedIntro = *(_SavedIntro **)((int)bufferSavedIntroArray + iVar2);
      if (savedIntro != (_SavedIntro *)0x0) {
        if (savedIntro->savedID == '\x01') {
          streamUnit = STREAM_GetStreamUnitWithID((int)savedIntro->streamUnitID);
          if (streamUnit != (_StreamUnit *)0x0) {
            p_Var1 = INSTANCE_IntroduceSavedInstance(savedIntro,streamUnit);
LAB_800b4788:
            if (p_Var1 == (_Instance *)0x0) goto LAB_800b47a0;
          }
        }
        else {
          streamUnit = STREAM_GetStreamUnitWithID((int)*(short *)(savedIntro->name + 2));
          if (streamUnit != (_StreamUnit *)0x0) {
            p_Var1 = INSTANCE_IntroduceSavedInstanceWithIntro
                               ((_SavedIntroWithIntro *)savedIntro,streamUnit);
            goto LAB_800b4788;
          }
        }
        *(_SavedIntro **)((int)bufferSavedIntroArray + iVar2) = (_SavedIntro *)0x0;
        numbufferedIntros = numbufferedIntros + -1;
      }
LAB_800b47a0:
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 4;
    } while (iVar3 < 0x40);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_IntroForStreamID(struct _StreamUnit *streamUnit /*$s2*/)
 // line 711, offset 0x800b47c8
	/* begin block 1 */
		// Start line: 712
		// Start offset: 0x800B47C8
		// Variables:
	// 		struct SavedBasic *saveIntro; // $s0
	// 		long streamID; // $s1
	/* end block 1 */
	// End offset: 0x800B4870
	// End Line: 739

	/* begin block 2 */
		// Start line: 1402
	/* end block 2 */
	// End Line: 1403

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_IntroForStreamID(_StreamUnit *streamUnit)

{
  _SavedIntro *savedIntro;
  int iVar1;
  
  iVar1 = streamUnit->StreamUnitID;
  savedIntro = (_SavedIntro *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((savedIntro->savedID == '\x01') && ((int)savedIntro->streamUnitID == iVar1)) {
        INSTANCE_IntroduceSavedInstance(savedIntro,streamUnit);
      }
      else {
        if ((savedIntro->savedID == '\a') && ((int)*(short *)(savedIntro->name + 2) == iVar1)) {
          INSTANCE_IntroduceSavedInstanceWithIntro((_SavedIntroWithIntro *)savedIntro,streamUnit);
        }
      }
      savedIntro = (_SavedIntro *)(&savedIntro->savedID + (uint)savedIntro->shiftedSaveSize * 4);
    } while (savedIntro < savedInfoTracker.InfoEnd);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_HasSavedIntro(struct Intro *intro /*$a0*/, long currentStreamID /*$a1*/)
 // line 741, offset 0x800b488c
	/* begin block 1 */
		// Start line: 743
		// Start offset: 0x800B488C
		// Variables:
	// 		long result; // $a3
	// 		struct _SavedIntro *saveIntro; // $a1
	/* end block 1 */
	// End offset: 0x800B4914
	// End Line: 765

	/* begin block 2 */
		// Start line: 1471
	/* end block 2 */
	// End Line: 1472

	/* begin block 3 */
		// Start line: 1472
	/* end block 3 */
	// End Line: 1473

	/* begin block 4 */
		// Start line: 1475
	/* end block 4 */
	// End Line: 1476

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 793, offset 0x800b491c
	/* begin block 1 */
		// Start line: 795
		// Start offset: 0x800B491C
		// Variables:
	// 		struct SavedLevel *savedLevel; // $v1
	/* end block 1 */
	// End offset: 0x800B4970
	// End Line: 810

	/* begin block 2 */
		// Start line: 1580
	/* end block 2 */
	// End Line: 1581

	/* begin block 3 */
		// Start line: 1581
	/* end block 3 */
	// End Line: 1582

	/* begin block 4 */
		// Start line: 1583
	/* end block 4 */
	// End Line: 1584

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 812, offset 0x800b4980
	/* begin block 1 */
		// Start line: 813
		// Start offset: 0x800B4980
		// Variables:
	// 		long i; // $t2
	// 		struct ActualSavedLevel *savedLevel; // $t3
	// 		struct _Terrain *terrain; // $t4
	// 		struct BSPTree *bspTree; // $v1
	// 		long Zoffset; // $s1
	/* end block 1 */
	// End offset: 0x800B4AB8
	// End Line: 856

	/* begin block 2 */
		// Start line: 1618
	/* end block 2 */
	// End Line: 1619

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 858, offset 0x800b4acc
	/* begin block 1 */
		// Start line: 859
		// Start offset: 0x800B4ACC
		// Variables:
	// 		struct SavedLevel *savedLevel; // $s0
	// 		struct ActualSavedLevel *slevel; // $a0
	// 		long doSave; // $a1
	// 		long i; // $a1
	// 		struct BSPTree *bspTree; // $v1
	// 		long Zoffset; // $s4

		/* begin block 1.1 */
			// Start line: 879
			// Start offset: 0x800B4B2C
			// Variables:
		// 		long numBSPTrees; // $s1

			/* begin block 1.1.1 */
				// Start line: 884
				// Start offset: 0x800B4B48
			/* end block 1.1.1 */
			// End offset: 0x800B4C40
			// End Line: 929
		/* end block 1.1 */
		// End offset: 0x800B4C40
		// End Line: 930
	/* end block 1 */
	// End offset: 0x800B4C64
	// End Line: 941

	/* begin block 2 */
		// Start line: 1737
	/* end block 2 */
	// End Line: 1738

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 945, offset 0x800b4c88
	/* begin block 1 */
		// Start line: 946
		// Start offset: 0x800B4C88
		// Variables:
	// 		long size; // $s0
	// 		char *nextBlock; // $a1

		/* begin block 1.1 */
			// Start line: 956
			// Start offset: 0x800B4CB0
			// Variables:
		// 		int i; // $a3
		/* end block 1.1 */
		// End offset: 0x800B4CF8
		// End Line: 976
	/* end block 1 */
	// End offset: 0x800B4CF8
	// End Line: 978

	/* begin block 2 */
		// Start line: 1931
	/* end block 2 */
	// End Line: 1932

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_DeleteBlock(SavedBasic *savedBlock)

{
  long lVar1;
  uint uVar2;
  SavedBasic *pSVar3;
  SavedBasic **ppSVar4;
  int iVar5;
  
  lVar1 = numbufferedIntros;
  uVar2 = (uint)savedBlock->shiftedSaveSize;
  if ((numbufferedIntros != 0) && (iVar5 = 0, 0 < numbufferedIntros)) {
    ppSVar4 = bufferSavedIntroArray;
    do {
      pSVar3 = *ppSVar4;
      if (pSVar3 == (SavedBasic *)savedBlock) {
        *ppSVar4 = (SavedBasic *)0x0;
      }
      else {
        if (savedBlock < pSVar3) {
          *ppSVar4 = pSVar3 + uVar2 * 0x3fffffff;
        }
      }
      iVar5 = iVar5 + 1;
      ppSVar4 = ppSVar4 + 1;
    } while (iVar5 < lVar1);
  }
  memmove((uchar *)savedBlock,(uchar *)(savedBlock + uVar2 * 2),
          (int)(savedInfoTracker.InfoEnd + -(int)(savedBlock + uVar2 * 2)));
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoEnd + uVar2 * -4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_Instance(struct _Instance *instance /*$s1*/, struct Level *level /*$s3*/)
 // line 989, offset 0x800b4d20
	/* begin block 1 */
		// Start line: 990
		// Start offset: 0x800B4D20
		// Variables:
	// 		struct _SavedIntro *savedIntro; // $v0
	// 		struct evControlSaveDataData *extraData; // $s0
	// 		long extraSize; // $s2
	// 		long saveType; // $v1

		/* begin block 1.1 */
			// Start line: 1001
			// Start offset: 0x800B4D68
			// Variables:
		// 		struct SavedIntroSmall *savedSmallIntro; // $a0

			/* begin block 1.1.1 */
				// Start line: 1008
				// Start offset: 0x800B4D88
			/* end block 1.1.1 */
			// End offset: 0x800B4DA0
			// End Line: 1014
		/* end block 1.1 */
		// End offset: 0x800B4DA0
		// End Line: 1014

		/* begin block 1.2 */
			// Start line: 1046
			// Start offset: 0x800B4E20
			// Variables:
		// 		struct _SavedIntroWithIntro *savedIntroWithIntro; // $v0
		/* end block 1.2 */
		// End offset: 0x800B4E54
		// End Line: 1060

		/* begin block 1.3 */
			// Start line: 1067
			// Start offset: 0x800B4E74
			// Variables:
		// 		struct SavedIntroSpline *savedIntroSpline; // $s0

			/* begin block 1.3.1 */
				// Start line: 1074
				// Start offset: 0x800B4E94
				// Variables:
			// 		struct MultiSpline *multi; // $a1
			/* end block 1.3.1 */
			// End offset: 0x800B4F38
			// End Line: 1094
		/* end block 1.3 */
		// End offset: 0x800B4F38
		// End Line: 1095
	/* end block 1 */
	// End offset: 0x800B4F38
	// End Line: 1100

	/* begin block 2 */
		// Start line: 2040
	/* end block 2 */
	// End Line: 2041

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_Instance(_Instance *instance,Level *level)

{
  long lVar1;
  long *plVar2;
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
      plVar2 = (long *)INSTANCE_Query(instance,0x18);
      if ((plVar2 != (long *)0x0) && (pvVar3 = SAVE_GetSavedBlock(5,*plVar2), pvVar3 != (void *)0x0)
         ) {
        *(undefined2 *)((int)pvVar3 + 2) = *(undefined2 *)&instance->introUniqueID;
        memcpy();
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DeleteInstance(struct _Instance *instance /*$a2*/)
 // line 1102, offset 0x800b4f54
	/* begin block 1 */
		// Start line: 1103
		// Start offset: 0x800B4F54
		// Variables:
	// 		struct SavedBasic *saveIntro; // $a0
	/* end block 1 */
	// End offset: 0x800B5014
	// End Line: 1130

	/* begin block 2 */
		// Start line: 2269
	/* end block 2 */
	// End Line: 2270

/* File: C:\kain2\game\SAVEINFO.C */

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
// void /*$ra*/ SAVE_SetDeadDeadBit(struct _Instance *instance /*$a0*/, long set /*$a1*/)
 // line 1132, offset 0x800b5024
	/* begin block 1 */
		// Start line: 1134
		// Start offset: 0x800B5024
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $a2
	// 		struct SavedDeadDeadBits *deadDeadBits; // $v1

		/* begin block 1.1 */
			// Start line: 1153
			// Start offset: 0x800B5088
			// Variables:
		// 		int deadByte; // $a2
		// 		int deadBit; // $a0
		/* end block 1.1 */
		// End offset: 0x800B50F0
		// End Line: 1175
	/* end block 1 */
	// End offset: 0x800B50F0
	// End Line: 1178

	/* begin block 2 */
		// Start line: 2335
	/* end block 2 */
	// End Line: 2336

	/* begin block 3 */
		// Start line: 2336
	/* end block 3 */
	// End Line: 2337

	/* begin block 4 */
		// Start line: 2339
	/* end block 4 */
	// End Line: 2340

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_SetDeadDeadBit(_Instance *instance,long set)

{
  byte bVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  if (instance->introUniqueID < 0x2000) {
    pcVar3 = (char *)0x0;
    pcVar5 = savedInfoTracker.InfoStart;
    if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
      do {
        pcVar3 = pcVar5;
        if (*pcVar3 == '\x04') break;
        pcVar5 = pcVar3 + (uint)(byte)pcVar3[1] * 4;
        pcVar3 = (char *)0x0;
      } while (pcVar5 < savedInfoTracker.InfoEnd);
    }
    if (pcVar3 != (char *)0x0) {
      uVar2 = instance->introUniqueID;
      uVar4 = uVar2;
      if ((int)uVar2 < 0) {
        uVar4 = uVar2 + 7;
      }
      iVar6 = (int)uVar4 >> 3;
      if (iVar6 < 0x340) {
        bVar1 = (byte)(1 << (uVar2 & 7));
        if (set == 1) {
          (pcVar3 + iVar6)[2] = (pcVar3 + iVar6)[2] | bVar1;
          return;
        }
        (pcVar3 + iVar6)[2] = (pcVar3 + iVar6)[2] & ~bVar1;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_RestoreGlobalSavePointer()
 // line 1180, offset 0x800b50f8
	/* begin block 1 */
		// Start line: 1182
		// Start offset: 0x800B50F8
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $v1
	/* end block 1 */
	// End offset: 0x800B5148
	// End Line: 1197

	/* begin block 2 */
		// Start line: 2448
	/* end block 2 */
	// End Line: 2449

	/* begin block 3 */
		// Start line: 2449
	/* end block 3 */
	// End Line: 2450

	/* begin block 4 */
		// Start line: 2452
	/* end block 4 */
	// End Line: 2453

/* File: C:\kain2\game\SAVEINFO.C */

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
// long /*$ra*/ SAVE_IsIntroDeadDead(struct Intro *intro /*$a0*/)
 // line 1199, offset 0x800b5150
	/* begin block 1 */
		// Start line: 1201
		// Start offset: 0x800B5150
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $v1
	// 		struct SavedDeadDeadBits *deadDeadBits; // $a2
	// 		long result; // $a3

		/* begin block 1.1 */
			// Start line: 1222
			// Start offset: 0x800B51C0
			// Variables:
		// 		int deadByte; // $a0
		// 		int deadBit; // $v1
		/* end block 1.1 */
		// End offset: 0x800B5204
		// End Line: 1236
	/* end block 1 */
	// End offset: 0x800B5204
	// End Line: 1238

	/* begin block 2 */
		// Start line: 2488
	/* end block 2 */
	// End Line: 2489

	/* begin block 3 */
		// Start line: 2489
	/* end block 3 */
	// End Line: 2490

	/* begin block 4 */
		// Start line: 2490
	/* end block 4 */
	// End Line: 2491

/* File: C:\kain2\game\SAVEINFO.C */

long SAVE_IsIntroDeadDead(Intro *intro)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (intro->UniqueID < 0x2000) {
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
      uVar1 = intro->UniqueID;
      uVar3 = uVar1;
      if ((int)uVar1 < 0) {
        uVar3 = uVar1 + 7;
      }
      uVar1 = 1 << (uVar1 & 7);
      if ((int)uVar3 >> 3 < 0x340) {
        uVar5 = (uint)(((byte)pcVar4[((int)uVar3 >> 3) + 2] & uVar1) == uVar1);
      }
    }
  }
  return uVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DoInstanceDeadDead(struct _Instance *instance /*$s0*/)
 // line 1242, offset 0x800b520c
	/* begin block 1 */
		// Start line: 2574
	/* end block 1 */
	// End Line: 2575

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_DoInstanceDeadDead(_Instance *instance)

{
  SAVE_DeleteInstance(instance);
  SAVE_SetDeadDeadBit(instance,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_MarkDeadDead(struct _Instance *instance /*$a0*/)
 // line 1252, offset 0x800b523c
	/* begin block 1 */
		// Start line: 2594
	/* end block 1 */
	// End Line: 2595

	/* begin block 2 */
		// Start line: 2595
	/* end block 2 */
	// End Line: 2596

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_MarkDeadDead(_Instance *instance)

{
  instance->flags = instance->flags | 0x800000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_UndestroyInstance(struct _Instance *instance /*$a0*/)
 // line 1257, offset 0x800b5250
	/* begin block 1 */
		// Start line: 2604
	/* end block 1 */
	// End Line: 2605

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_UndestroyInstance(_Instance *instance)

{
  SAVE_SetDeadDeadBit(instance,0);
  return;
}



// decompiled code
// original method signature: 
// struct SavedIntroSmall * /*$ra*/ SAVE_GetSavedSmallIntro(struct _Instance *instance /*$a0*/)
 // line 1262, offset 0x800b5270
	/* begin block 1 */
		// Start line: 1264
		// Start offset: 0x800B5270
		// Variables:
	// 		struct SavedBasic *curSave; // $a1
	/* end block 1 */
	// End offset: 0x800B52CC
	// End Line: 1282

	/* begin block 2 */
		// Start line: 2614
	/* end block 2 */
	// End Line: 2615

	/* begin block 3 */
		// Start line: 2615
	/* end block 3 */
	// End Line: 2616

	/* begin block 4 */
		// Start line: 2619
	/* end block 4 */
	// End Line: 2620

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 1284, offset 0x800b52dc
	/* begin block 1 */
		// Start line: 1286
		// Start offset: 0x800B52DC
		// Variables:
	// 		struct SavedBasic *curSave; // $a1
	/* end block 1 */
	// End offset: 0x800B5338
	// End Line: 1303

	/* begin block 2 */
		// Start line: 2658
	/* end block 2 */
	// End Line: 2659

	/* begin block 3 */
		// Start line: 2659
	/* end block 3 */
	// End Line: 2660

	/* begin block 4 */
		// Start line: 2662
	/* end block 4 */
	// End Line: 2663

/* File: C:\kain2\game\SAVEINFO.C */

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
 // line 1306, offset 0x800b5348
	/* begin block 1 */
		// Start line: 2702
	/* end block 1 */
	// End Line: 2703

	/* begin block 2 */
		// Start line: 2703
	/* end block 2 */
	// End Line: 2704

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_UpdateGlobalSaveTracker(void)

{
  _GlobalSaveTracker *p_Var1;
  ulong uVar2;
  ulong uVar3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  
  p_Var1 = GlobalSave;
  GlobalSave->currentTime = DAT_800d2300;
  uVar3 = DAT_800d2288;
  uVar2 = DAT_800d2284;
  (p_Var1->sound).gMasterVol = DAT_800d2280;
  (p_Var1->sound).gMusicVol = uVar2;
  (p_Var1->sound).gSfxVol = uVar3;
  uVar4 = _DAT_800d2290;
  (p_Var1->sound).gVoiceVol = _DAT_800d228c;
  *(undefined4 *)&(p_Var1->sound).gSfxOn = uVar4;
  GlobalSave->saveVersion = 0x5514;
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
 // line 1319, offset 0x800b53e0
	/* begin block 1 */
		// Start line: 2729
	/* end block 1 */
	// End Line: 2730

	/* begin block 2 */
		// Start line: 2730
	/* end block 2 */
	// End Line: 2731

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_RestoreGlobalSaveTracker(void)

{
  if (GlobalSave->saveVersion == 0x5514) {
    DAT_800d2300 = GlobalSave->currentTime;
    DAT_800d2280 = (GlobalSave->sound).gMasterVol;
    DAT_800d2284 = (GlobalSave->sound).gMusicVol;
    DAT_800d2288 = (GlobalSave->sound).gSfxVol;
    _DAT_800d228c = (GlobalSave->sound).gVoiceVol;
    _DAT_800d2290 = *(undefined4 *)&(GlobalSave->sound).gSfxOn;
    SOUND_SetSfxVolume(DAT_800d2288);
    SOUND_SetMusicVolume(DAT_800d2284);
    SOUND_SetVoiceVolume(_DAT_800d228c);
    if ((GlobalSave->flags & 2U) == 0) {
      GAMEPAD_DisableDualShock();
    }
    else {
      GAMEPAD_EnableDualShock();
    }
  }
  else {
    SAVE_ClearMemory((GameTracker *)&gameTrackerX);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_SaveEverythingInMemory()
 // line 1344, offset 0x800b54b8
	/* begin block 1 */
		// Start line: 1345
		// Start offset: 0x800B54B8
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		long i; // $s1

		/* begin block 1.1 */
			// Start line: 1353
			// Start offset: 0x800B54E0
			// Variables:
		// 		struct _Instance *next; // $s1
		// 		struct Level *level; // $v0
		/* end block 1.1 */
		// End offset: 0x800B5500
		// End Line: 1362
	/* end block 1 */
	// End offset: 0x800B5558
	// End Line: 1378

	/* begin block 2 */
		// Start line: 2780
	/* end block 2 */
	// End Line: 2781

	/* begin block 3 */
		// Start line: 2786
	/* end block 3 */
	// End Line: 2787

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_SaveEverythingInMemory(void)

{
  _Instance *instance;
  Level *level;
  long *plVar1;
  _Instance *p_Var2;
  int iVar3;
  
  p_Var2 = *(_Instance **)(DAT_800d2100 + 4);
  while (instance = p_Var2, instance != (_Instance *)0x0) {
    p_Var2 = instance->next;
    level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    if (level != (Level *)0x0) {
      SAVE_Instance(instance,level);
    }
  }
  iVar3 = 0;
  plVar1 = &StreamTracker;
  do {
    if (*(short *)(plVar1 + 1) == 2) {
      EVENT_SaveEventsFromLevel(*plVar1,(Level *)plVar1[2]);
      SAVE_CreatedSavedLevel(*plVar1,(Level *)plVar1[2]);
    }
    iVar3 = iVar3 + 1;
    plVar1 = plVar1 + 0x10;
  } while (iVar3 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_SaveGame()
 // line 1381, offset 0x800b5570
	/* begin block 1 */
		// Start line: 2882
	/* end block 1 */
	// End Line: 2883

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_SaveGame(void)

{
  SAVE_SaveEverythingInMemory();
  SAVE_UpdateGlobalSaveTracker();
  GlobalSave->sizeUsedInBlock = (short)savedInfoTracker.InfoEnd - (short)savedInfoTracker.InfoStart;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_RestoreGame()
 // line 1389, offset 0x800b55ac
	/* begin block 1 */
		// Start line: 2898
	/* end block 1 */
	// End Line: 2899

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_RestoreGame(void)

{
  DAT_800d2210 = DAT_800d2210 | 0x200000;
  SAVE_RestoreGlobalSavePointer();
  SAVE_RestoreGlobalSaveTracker();
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart + GlobalSave->sizeUsedInBlock;
  GAMELOOP_RequestLevelChange(s_under_800d0c10,1,(GameTracker *)&gameTrackerX);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DebugSaveGame()
 // line 1405, offset 0x800b5614
	/* begin block 1 */
		// Start line: 2933
	/* end block 1 */
	// End Line: 2934

	/* begin block 2 */
		// Start line: 2961
	/* end block 2 */
	// End Line: 2962

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_DebugSaveGame(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_LoadSaveGame()
 // line 1473, offset 0x800b561c
	/* begin block 1 */
		// Start line: 2941
	/* end block 1 */
	// End Line: 2942

/* File: C:\kain2\game\SAVEINFO.C */

void SAVE_LoadSaveGame(void)

{
  DAT_800d2210 = DAT_800d2210 | 0x200000;
  GAMELOOP_RequestLevelChange(s_under_800d0c10,1,(GameTracker *)&gameTrackerX);
  DAT_800d223e = 0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_SizeOfFreeSpace()
 // line 1483, offset 0x800b565c
	/* begin block 1 */
		// Start line: 3055
	/* end block 1 */
	// End Line: 3056

	/* begin block 2 */
		// Start line: 3056
	/* end block 2 */
	// End Line: 3057

/* File: C:\kain2\game\SAVEINFO.C */

long SAVE_SizeOfFreeSpace(void)

{
  return (long)(savedInfoTracker.EndOfMemory + -(int)savedInfoTracker.InfoEnd);
}





