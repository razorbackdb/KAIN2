#include "THISDUST.H"
#include "SAVEINFO.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_ClearMemory(struct GameTracker *gameTracker /*$a0*/)
 // line 177, offset 0x800afbc4
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x800AFBC4
		// Variables:
	// 		char *buffer; // $v0
	/* end block 1 */
	// End offset: 0x800AFBC4
	// End Line: 178

	/* begin block 2 */
		// Start line: 338
	/* end block 2 */
	// End Line: 339

	/* begin block 3 */
		// Start line: 339
	/* end block 3 */
	// End Line: 340

void SAVE_ClearMemory(GameTracker *gameTracker)

{
  savedInfoTracker.InfoStart = savedInfoTracker.MemoryCardBuffer + the_header_size;
  savedInfoTracker.EndOfMemory = savedInfoTracker.MemoryCardBuffer + 0x4000;
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart;
  memset(savedInfoTracker.InfoStart,0,0x4000 - the_header_size);
  numbufferedIntros = 0;
  memset(&bufferSavedIntroArray64,0,0x100);
  GlobalSave = (_GlobalSaveTracker *)SAVE_GetSavedBlock(6,0);
  SAVE_GetSavedBlock(4,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_Init(struct GameTracker *gt /*$s0*/)
 // line 198, offset 0x800afc3c
	/* begin block 1 */
		// Start line: 199
		// Start offset: 0x800AFC3C
		// Variables:
	// 		void *buffer; // $s1

		/* begin block 1.1 */
			// Start line: 206
			// Start offset: 0x800AFC6C
			// Variables:
		// 		struct memcard_t *memcard; // $v0
		/* end block 1.1 */
		// End offset: 0x800AFC6C
		// End Line: 206
	/* end block 1 */
	// End offset: 0x800AFCB0
	// End Line: 218

	/* begin block 2 */
		// Start line: 398
	/* end block 2 */
	// End Line: 399

void SAVE_Init(GameTracker *gt)

{
  char *buffer;
  ulong allocSize;
  memcard_t *memcard;
  
  buffer = MEMPACK_Malloc(0x4000,'\x12');
  if (DoMainMenu == 0) {
    gt->memcard = (memcard_t *)0x0;
  }
  else {
    allocSize = memcard_data_size();
    memcard = (memcard_t *)MEMPACK_Malloc(allocSize,'+');
    gt->memcard = memcard;
    the_header_size = memcard_initialize(memcard,gt,2,buffer,0x4000);
  }
  savedInfoTracker.MemoryCardBuffer = buffer;
  SAVE_ClearMemory(gt);
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ SAVE_GetSavedBlock(long saveType /*$a0*/, long extraSize /*$a1*/)
 // line 235, offset 0x800afcd0
	/* begin block 1 */
		// Start line: 236
		// Start offset: 0x800AFCD0
		// Variables:
	// 		struct SavedBasic *savedInfo; // $s1
	// 		long sizeOfSave; // $s0
	/* end block 1 */
	// End offset: 0x800AFD78
	// End Line: 261

	/* begin block 2 */
		// Start line: 474
	/* end block 2 */
	// End Line: 475

void * SAVE_GetSavedBlock(long saveType,long extraSize)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = savedInfoTracker.InfoEnd;
  iVar2 = ((&SaveArraySize)[saveType] + extraSize + 3 >> 2) * 4;
  if (savedInfoTracker.InfoEnd + iVar2 < savedInfoTracker.EndOfMemory) {
    *(short *)savedInfoTracker.InfoEnd = (short)saveType;
    *(short *)(pcVar1 + 2) = (short)iVar2;
    savedInfoTracker.InfoEnd = savedInfoTracker.InfoEnd + iVar2;
  }
  else {
    GXFilePrint(
               "Ran out of saved memory. Trying to save size=%d, already saved size=%d.\nIncrease from %d\n"
               );
    FONT_Print("Ran out of saved memory. Needed %d, used %d.\nIncrease from %d\n");
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_SaveableInstance(struct _Instance *instance /*$a0*/)
 // line 267, offset 0x800afd90
	/* begin block 1 */
		// Start line: 269
		// Start offset: 0x800AFD90
		// Variables:
	// 		long result; // $a2
	/* end block 1 */
	// End offset: 0x800AFE20
	// End Line: 301

	/* begin block 2 */
		// Start line: 548
	/* end block 2 */
	// End Line: 549

	/* begin block 3 */
		// Start line: 549
	/* end block 3 */
	// End Line: 550

	/* begin block 4 */
		// Start line: 551
	/* end block 4 */
	// End Line: 552

long SAVE_SaveableInstance(_Instance *instance)

{
  Object *pOVar1;
  uint uVar2;
  
  if ((instance->flags2 & 0x20000U) != 0) {
    return 0;
  }
  pOVar1 = instance->object;
  if (pOVar1 == (Object *)0x0) {
    return 0;
  }
  uVar2 = pOVar1->oflags2;
  if (((uVar2 & 0x80000) == 0) && (instance != gameTrackerX.playerInstance)) {
    if ((uVar2 & 0x40000) != 0) {
      if ((pOVar1->oflags & 1U) != 0) {
        return 1;
      }
      instance->flags2 = instance->flags2 | 4;
      return 1;
    }
    if (((instance->flags & 0x100000U) != 0) && ((uVar2 & 0x100000) == 0)) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// struct _SavedIntro * /*$ra*/ SAVE_GetSavedIntro(struct _Instance *instance /*$a0*/)
 // line 321, offset 0x800afe28
	/* begin block 1 */
		// Start line: 323
		// Start offset: 0x800AFE28
		// Variables:
	// 		struct SavedBasic *curSave; // $a1
	/* end block 1 */
	// End offset: 0x800AFE80
	// End Line: 340

	/* begin block 2 */
		// Start line: 657
	/* end block 2 */
	// End Line: 658

	/* begin block 3 */
		// Start line: 658
	/* end block 3 */
	// End Line: 659

	/* begin block 4 */
		// Start line: 661
	/* end block 4 */
	// End Line: 662

_SavedIntro * SAVE_GetSavedIntro(_Instance *instance)

{
  short *psVar1;
  uchar *puVar2;
  _SavedIntro *p_Var3;
  
  p_Var3 = (_SavedIntro *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((*(short *)p_Var3 == 1) && ((int)p_Var3->birthUnitID == instance->introUniqueID)) {
        return p_Var3;
      }
      psVar1 = (short *)&p_Var3->lightGroup;
      puVar2 = &p_Var3->savedID;
      p_Var3 = (_SavedIntro *)(puVar2 + *psVar1);
    } while ((_SavedIntro *)(puVar2 + *psVar1) < savedInfoTracker.InfoEnd);
  }
  return (_SavedIntro *)0x0;
}



// decompiled code
// original method signature: 
// struct _SavedIntro * /*$ra*/ SAVE_UpdateSavedIntro(struct _Instance *instance /*$s1*/, struct Level *level /*$a1*/, struct _SavedIntro *savedIntro /*$s0*/, struct evControlSaveDataData *extraData /*$s4*/)
 // line 342, offset 0x800afe90
	/* begin block 1 */
		// Start line: 343
		// Start offset: 0x800AFE90
		// Variables:
	// 		struct _Position *levelOffset; // $s2

		/* begin block 1.1 */
			// Start line: 354
			// Start offset: 0x800AFEC8
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $a0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _Position *_v; // $v0
		// 		struct _Position *_v0; // $v1
		/* end block 1.1 */
		// End offset: 0x800AFEC8
		// End Line: 354

		/* begin block 1.2 */
			// Start line: 376
			// Start offset: 0x800AFFC0
			// Variables:
		// 		struct MultiSpline *multi; // $a1
		/* end block 1.2 */
		// End offset: 0x800B0000
		// End Line: 385
	/* end block 1 */
	// End offset: 0x800B003C
	// End Line: 400

	/* begin block 2 */
		// Start line: 699
	/* end block 2 */
	// End Line: 700

_SavedIntro *
SAVE_UpdateSavedIntro
          (_Instance *instance,Level *level,_SavedIntro *savedIntro,evControlSaveDataData *extraData
          )

{
  uchar uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  undefined2 uVar6;
  MultiSpline *spline;
  long lVar7;
  undefined4 uVar8;
  _MultiSignal *p_Var9;
  
  p_Var9 = level->terrain->signals;
  if (savedIntro == (_SavedIntro *)0x0) {
    GXFilePrint("No saved Intro for instance %s.\n");
  }
  else {
    strcpy(savedIntro->name,instance->introName);
    *(undefined2 *)savedIntro = 1;
    savedIntro->birthUnitID = *(short *)&instance->introUniqueID;
    savedIntro->attachedUniqueID = *(ushort *)&instance->currentStreamUnitID;
    (savedIntro->smallRotation).x = *(short *)&instance->birthStreamUnitID;
    sVar2 = (instance->position).y;
    sVar3 = (instance->position).z;
    sVar4 = *(short *)(p_Var9->signalList[0].data + 2);
    sVar5 = *(short *)(p_Var9->signalList[0].data + 4);
    *(short *)&savedIntro->flags = (instance->position).x - *(short *)p_Var9->signalList[0].data;
    *(short *)((int)&savedIntro->flags + 2) = sVar2 - sVar4;
    *(short *)&savedIntro->flags2 = sVar3 - sVar5;
    uVar8 = *(undefined4 *)&(instance->rotation).z;
    *(undefined4 *)&(savedIntro->smallRotation).z = *(undefined4 *)&instance->rotation;
    *(undefined4 *)&(savedIntro->position).y = uVar8;
    (savedIntro->position).z = (ushort)instance->lightGroup;
    *(long *)(savedIntro + 1) = instance->flags;
    *(long *)savedIntro[1].name = instance->flags2;
    *(uchar *)((int)&(savedIntro->smallRotation).y + 1) = instance->spectralLightGroup;
    uVar1 = instance->lightGroup;
    *(undefined2 *)(savedIntro[1].name + 4) = 0;
    *(uchar *)&(savedIntro->smallRotation).y = uVar1;
    uVar6 = *(undefined2 *)&instance->attachedID;
    savedIntro[1].introUniqueID = 0;
    savedIntro[1].streamUnitID = -1;
    *(undefined2 *)(savedIntro[1].name + 6) = uVar6;
    savedIntro[1].birthUnitID = -1;
    savedIntro[1].attachedUniqueID = 0xffff;
    if (((instance->flags & 0x100000U) == 0) &&
       (spline = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0),
       spline != (MultiSpline *)0x0)) {
      savedIntro[1].introUniqueID = instance->splineFlags;
      lVar7 = INSTANCE_GetSplineFrameNumber(instance,spline);
      savedIntro[1].streamUnitID = (short)lVar7;
      savedIntro[1].birthUnitID = instance->clipBeg;
      savedIntro[1].attachedUniqueID = instance->clipEnd;
    }
    if (extraData != (evControlSaveDataData *)0x0) {
      sVar2 = *(short *)&extraData->length;
      *(short *)(savedIntro[1].name + 4) = sVar2;
      memcpy(&savedIntro[1].smallRotation,extraData->data,(int)sVar2);
    }
  }
  return savedIntro;
}



// decompiled code
// original method signature: 
// struct SavedEvent * /*$ra*/ SAVE_GetSavedEvent(long areaID /*$a0*/, long eventNumber /*$a1*/)
 // line 403, offset 0x800b0060
	/* begin block 1 */
		// Start line: 405
		// Start offset: 0x800B0060
		// Variables:
	// 		struct SavedBasic *curSave; // $v1
	/* end block 1 */
	// End offset: 0x800B00C0
	// End Line: 423

	/* begin block 2 */
		// Start line: 840
	/* end block 2 */
	// End Line: 841

	/* begin block 3 */
		// Start line: 841
	/* end block 3 */
	// End Line: 842

	/* begin block 4 */
		// Start line: 844
	/* end block 4 */
	// End Line: 845

SavedEvent * SAVE_GetSavedEvent(long areaID,long eventNumber)

{
  SavedEvent *pSVar1;
  
  pSVar1 = (SavedEvent *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if (((*(short *)pSVar1 == 2) && (*(int *)&pSVar1->eventNumber == areaID)) &&
         ((int)pSVar1->eventVariables[1] == eventNumber)) {
        return pSVar1;
      }
      pSVar1 = (SavedEvent *)(&pSVar1->savedID + pSVar1->areaID);
    } while (pSVar1 < savedInfoTracker.InfoEnd);
  }
  return (SavedEvent *)0x0;
}



// decompiled code
// original method signature: 
// struct SavedEvent * /*$ra*/ SAVE_GetSavedNextEvent(long areaID /*$a0*/, struct SavedBasic *curSave /*$a1*/)
 // line 425, offset 0x800b00d0
	/* begin block 1 */
		// Start line: 427
		// Start offset: 0x800B00D0
	/* end block 1 */
	// End offset: 0x800B0144
	// End Line: 451

	/* begin block 2 */
		// Start line: 884
	/* end block 2 */
	// End Line: 885

	/* begin block 3 */
		// Start line: 885
	/* end block 3 */
	// End Line: 886

	/* begin block 4 */
		// Start line: 887
	/* end block 4 */
	// End Line: 888

SavedEvent * SAVE_GetSavedNextEvent(long areaID,SavedBasic *curSave)

{
  SavedEvent *pSVar1;
  
  pSVar1 = (SavedEvent *)savedInfoTracker.InfoStart;
  if (curSave != (SavedBasic *)0x0) {
    pSVar1 = (SavedEvent *)(&curSave->savedID + (short)curSave[1]);
  }
  while( true ) {
    if (savedInfoTracker.InfoEnd <= pSVar1) {
      return (SavedEvent *)0x0;
    }
    if ((*(short *)pSVar1 == 2) && (*(int *)&pSVar1->eventNumber == areaID)) break;
    pSVar1 = (SavedEvent *)(&pSVar1->savedID + pSVar1->areaID);
  }
  return pSVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_BufferIntro(struct _SavedIntro *savedIntro /*$a0*/)
 // line 455, offset 0x800b014c
	/* begin block 1 */
		// Start line: 456
		// Start offset: 0x800B014C
		// Variables:
	// 		long i; // $a1
	/* end block 1 */
	// End offset: 0x800B01F0
	// End Line: 490

	/* begin block 2 */
		// Start line: 954
	/* end block 2 */
	// End Line: 955

	/* begin block 3 */
		// Start line: 957
	/* end block 3 */
	// End Line: 958

void SAVE_BufferIntro(_SavedIntro *savedIntro)

{
  _SavedIntro **pp_Var1;
  int iVar2;
  
  if (numbufferedIntros < 0x40) {
    iVar2 = 0;
    pp_Var1 = &bufferSavedIntroArray64;
    do {
      if (*pp_Var1 == savedIntro) break;
      iVar2 = iVar2 + 1;
      pp_Var1 = pp_Var1 + 1;
    } while (iVar2 < 0x40);
    if (iVar2 == 0x40) {
      iVar2 = 0;
      pp_Var1 = &bufferSavedIntroArray64;
      numbufferedIntros = numbufferedIntros + 1;
      do {
        iVar2 = iVar2 + 1;
        if (*pp_Var1 == (_SavedIntro *)0x0) {
          *pp_Var1 = savedIntro;
          return;
        }
        pp_Var1 = pp_Var1 + 1;
      } while (iVar2 < 0x40);
    }
  }
  else {
    GXFilePrint("Ran out of buffered intros. Increase MAX_BUFFERED_INTROS = %d\n");
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_IntroduceBufferIntros()
 // line 492, offset 0x800b0200
	/* begin block 1 */
		// Start line: 493
		// Start offset: 0x800B0200
		// Variables:
	// 		long i; // $s1
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x800B0280
	// End Line: 522

	/* begin block 2 */
		// Start line: 1042
	/* end block 2 */
	// End Line: 1043

	/* begin block 3 */
		// Start line: 1046
	/* end block 3 */
	// End Line: 1047

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_IntroduceBufferIntros(void)

{
  Level *level;
  _Instance *p_Var1;
  _SavedIntro **pp_Var2;
  int iVar3;
  
  if (numbufferedIntros < 0x40) {
    iVar3 = 0;
    pp_Var2 = &bufferSavedIntroArray64;
    do {
      if ((*pp_Var2 != (_SavedIntro *)0x0) &&
         ((level = STREAM_GetLevelWithID((int)(short)(*pp_Var2)->attachedUniqueID),
          level == (Level *)0x0 ||
          (p_Var1 = INSTANCE_IntroduceSavedInstance(*pp_Var2,level), p_Var1 != (_Instance *)0x0))))
      {
        *pp_Var2 = (_SavedIntro *)0x0;
        numbufferedIntros = numbufferedIntros + -1;
      }
      iVar3 = iVar3 + 1;
      pp_Var2 = pp_Var2 + 1;
    } while (iVar3 < 0x40);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_IntroForStreamID(long streamID /*$s2*/, struct Level *level /*$s3*/)
 // line 524, offset 0x800b0294
	/* begin block 1 */
		// Start line: 525
		// Start offset: 0x800B0294
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $s0
	/* end block 1 */
	// End offset: 0x800B0308
	// End Line: 539

	/* begin block 2 */
		// Start line: 1126
	/* end block 2 */
	// End Line: 1127

void SAVE_IntroForStreamID(long streamID,Level *level)

{
  short *psVar1;
  uchar *puVar2;
  _SavedIntro *savedIntro;
  
  savedIntro = (_SavedIntro *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((*(short *)savedIntro == 1) && ((int)(short)savedIntro->attachedUniqueID == streamID)) {
        INSTANCE_IntroduceSavedInstance(savedIntro,level);
      }
      psVar1 = (short *)&savedIntro->lightGroup;
      puVar2 = &savedIntro->savedID;
      savedIntro = (_SavedIntro *)(puVar2 + *psVar1);
    } while ((_SavedIntro *)(puVar2 + *psVar1) < savedInfoTracker.InfoEnd);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_HasSavedIntro(struct Intro *intro /*$a0*/, long currentStreamID /*$a1*/)
 // line 541, offset 0x800b0324
	/* begin block 1 */
		// Start line: 543
		// Start offset: 0x800B0324
		// Variables:
	// 		long result; // $a2
	// 		struct _SavedIntro *saveIntro; // $a1
	/* end block 1 */
	// End offset: 0x800B0388
	// End Line: 559

	/* begin block 2 */
		// Start line: 1165
	/* end block 2 */
	// End Line: 1166

	/* begin block 3 */
		// Start line: 1166
	/* end block 3 */
	// End Line: 1167

	/* begin block 4 */
		// Start line: 1169
	/* end block 4 */
	// End Line: 1170

long SAVE_HasSavedIntro(Intro *intro,long currentStreamID)

{
  short *psVar1;
  
  psVar1 = (short *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((*psVar1 == 1) && ((int)psVar1[8] == intro->UniqueID)) {
        return 1;
      }
      psVar1 = (short *)((int)psVar1 + (int)psVar1[1]);
    } while (psVar1 < savedInfoTracker.InfoEnd);
  }
  return 0;
}



// decompiled code
// original method signature: 
// struct SavedLevel * /*$ra*/ SAVE_HasSavedLevel(long areaID /*$a0*/)
 // line 562, offset 0x800b0390
	/* begin block 1 */
		// Start line: 564
		// Start offset: 0x800B0390
		// Variables:
	// 		struct SavedLevel *savedLevel; // $v1
	/* end block 1 */
	// End offset: 0x800B03E0
	// End Line: 579

	/* begin block 2 */
		// Start line: 1211
	/* end block 2 */
	// End Line: 1212

	/* begin block 3 */
		// Start line: 1212
	/* end block 3 */
	// End Line: 1213

	/* begin block 4 */
		// Start line: 1214
	/* end block 4 */
	// End Line: 1215

SavedLevel * SAVE_HasSavedLevel(long areaID)

{
  SavedLevel *pSVar1;
  
  pSVar1 = (SavedLevel *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((*(short *)pSVar1 == 3) && (*(int *)&pSVar1->waterZ == areaID)) {
        return pSVar1;
      }
      pSVar1 = (SavedLevel *)(&pSVar1->savedID + pSVar1->areaID);
    } while (pSVar1 < savedInfoTracker.InfoEnd);
  }
  return (SavedLevel *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_UpdateLevelWithSave(struct _StreamUnit *streamUnit /*$s1*/)
 // line 581, offset 0x800b03f0
	/* begin block 1 */
		// Start line: 582
		// Start offset: 0x800B03F0
		// Variables:
	// 		long i; // $t0
	// 		struct ActualSavedLevel *savedLevel; // $s0
	// 		struct _Terrain *terrain; // $t1
	// 		struct BSPTree *bspTree; // $v1
	// 		long Zoffset; // $s2
	/* end block 1 */
	// End offset: 0x800B051C
	// End Line: 625

	/* begin block 2 */
		// Start line: 1249
	/* end block 2 */
	// End Line: 1250

void SAVE_UpdateLevelWithSave(_StreamUnit *streamUnit)

{
  short sVar1;
  short sVar2;
  SavedLevel *pSVar3;
  short *psVar4;
  SavedLevel *pSVar5;
  int iVar6;
  _Terrain *p_Var7;
  
  sVar1 = *(short *)(streamUnit->level->terrain->signals->signalList[0].data + 4);
  pSVar3 = SAVE_HasSavedLevel(streamUnit->StreamUnitID);
  if (pSVar3 != (SavedLevel *)0x0) {
    printf("%s has save Level.\n");
    p_Var7 = streamUnit->level->terrain;
    iVar6 = 0;
    if (0 < (int)p_Var7->morphNormalIdx) {
      psVar4 = (short *)(p_Var7->signals->signalList[0].data + 4);
      pSVar5 = pSVar3;
      do {
        sVar2 = *(short *)(pSVar5 + 2);
        *(undefined4 *)(psVar4 + 2) = *(undefined4 *)&pSVar5[1].waterZ;
        psVar4[4] = sVar2;
        sVar2 = pSVar5[2].areaID;
        pSVar5 = pSVar5 + 1;
        psVar4[-2] = psVar4[-2] + psVar4[2];
        iVar6 = iVar6 + 1;
        psVar4[1] = sVar2;
        psVar4[-1] = psVar4[-1] + psVar4[3];
        *psVar4 = *psVar4 + psVar4[4];
        psVar4 = psVar4 + 0x12;
      } while (iVar6 < (int)p_Var7->morphNormalIdx);
    }
    iVar6 = (int)*(short *)(pSVar3 + 1);
    if ((iVar6 == -0x7fff) || (iVar6 == 0x7fff)) {
      streamUnit->level->waterZLevel = (int)*(short *)(pSVar3 + 1);
    }
    else {
      streamUnit->level->waterZLevel = iVar6 + sVar1;
    }
    p_Var7->UnitChangeFlags = p_Var7->UnitChangeFlags | 3;
  }
  return;
}



// decompiled code
// original method signature: 
// struct SavedLevel * /*$ra*/ SAVE_CreatedSavedLevel(long areaID /*$s2*/, struct Level *level /*$s1*/)
 // line 627, offset 0x800b0534
	/* begin block 1 */
		// Start line: 628
		// Start offset: 0x800B0534
		// Variables:
	// 		struct SavedLevel *savedLevel; // $s0
	// 		struct ActualSavedLevel *slevel; // $a2
	// 		long doSave; // $a1
	// 		long i; // $a1
	// 		struct BSPTree *bspTree; // $v0
	// 		long Zoffset; // $s3
	/* end block 1 */
	// End offset: 0x800B06B4
	// End Line: 697

	/* begin block 2 */
		// Start line: 1366
	/* end block 2 */
	// End Line: 1367

SavedLevel * SAVE_CreatedSavedLevel(long areaID,Level *level)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  bool bVar4;
  SavedLevel *savedBlock;
  int iVar5;
  SavedLevel *pSVar6;
  _Terrain *p_Var7;
  int iVar8;
  int iVar9;
  
  uVar3 = level->terrain->UnitChangeFlags;
  sVar1 = *(short *)(level->terrain->signals->signalList[0].data + 4);
  bVar4 = false;
  if (((uVar3 & 1) != 0) || ((uVar3 & 2) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    savedBlock = SAVE_HasSavedLevel(areaID);
    if ((savedBlock == (SavedLevel *)0x0) &&
       (savedBlock = (SavedLevel *)SAVE_GetSavedBlock(3,(int)level->terrain->morphNormalIdx << 3),
       savedBlock == (SavedLevel *)0x0)) {
      FONT_Print("Ran out of save Space. Can not save anymore.\n");
    }
    else {
      *(long *)&savedBlock->waterZ = areaID;
      if ((level->waterZLevel == -0x7fff) || (level->waterZLevel == 0x7fff)) {
        *(undefined2 *)(savedBlock + 1) = *(undefined2 *)&level->waterZLevel;
      }
      else {
        *(short *)(savedBlock + 1) = *(short *)&level->waterZLevel - sVar1;
      }
      savedBlock[1].areaID = *(short *)&level->terrain->morphNormalIdx;
      p_Var7 = level->terrain;
      iVar8 = 0;
      if (0 < (int)p_Var7->morphNormalIdx) {
        iVar9 = 0;
        pSVar6 = savedBlock;
        do {
          iVar5 = (int)&p_Var7->signals->numSignals + iVar9;
          uVar2 = *(undefined2 *)(iVar5 + 0x18);
          *(undefined4 *)&pSVar6[1].waterZ = *(undefined4 *)(iVar5 + 0x14);
          *(undefined2 *)(pSVar6 + 2) = uVar2;
          iVar8 = iVar8 + 1;
          pSVar6[2].areaID = *(short *)(iVar5 + 0x12);
          p_Var7 = level->terrain;
          iVar9 = iVar9 + 0x24;
          pSVar6 = pSVar6 + 1;
        } while (iVar8 < (int)p_Var7->morphNormalIdx);
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
// void /*$ra*/ SAVE_DeleteBlock(struct SavedBasic *savedBlock /*$s0*/)
 // line 701, offset 0x800b06d4
	/* begin block 1 */
		// Start line: 702
		// Start offset: 0x800B06D4
		// Variables:
	// 		long size; // $s2
	// 		char *nextBlock; // $s1
	/* end block 1 */
	// End offset: 0x800B070C
	// End Line: 714

	/* begin block 2 */
		// Start line: 1533
	/* end block 2 */
	// End Line: 1534

void SAVE_DeleteBlock(SavedBasic *savedBlock)

{
  SavedBasic SVar1;
  
  SVar1 = savedBlock[1];
  if (numbufferedIntros != 0) {
    GXFilePrint(
               "Delete a saved block and there are buffered intros. Could be a prob. Tell Carl to handle\n"
               );
  }
  memmove(savedBlock,&savedBlock->savedID + (int)(short)SVar1,
          (size_t)(savedInfoTracker.InfoEnd + -(int)(&savedBlock->savedID + (int)(short)SVar1)));
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoEnd + -(int)(short)SVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_Instance(struct _Instance *instance /*$s2*/, struct Level *level /*$s4*/)
 // line 721, offset 0x800b0744
	/* begin block 1 */
		// Start line: 722
		// Start offset: 0x800B0744
		// Variables:
	// 		struct _SavedIntro *savedIntro; // $s0
	// 		struct evControlSaveDataData *extraData; // $s1
	// 		long extraSize; // $s3

		/* begin block 1.1 */
			// Start line: 732
			// Start offset: 0x800B078C
			// Variables:
		// 		struct SavedIntroSmall *savedSmallIntro; // $a0

			/* begin block 1.1.1 */
				// Start line: 746
				// Start offset: 0x800B07C8
			/* end block 1.1.1 */
			// End offset: 0x800B07C8
			// End Line: 748
		/* end block 1.1 */
		// End offset: 0x800B07C8
		// End Line: 748
	/* end block 1 */
	// End offset: 0x800B0890
	// End Line: 795

	/* begin block 2 */
		// Start line: 1575
	/* end block 2 */
	// End Line: 1576

void SAVE_Instance(_Instance *instance,Level *level)

{
  long lVar1;
  SavedIntroSmall *savedBlock;
  size_t *psVar2;
  void *pvVar3;
  _SavedIntro *savedIntro;
  evControlSaveDataData *extraData;
  int extraSize;
  
  extraSize = 0;
  lVar1 = SAVE_SaveableInstance(instance);
  if (lVar1 != 0) {
    if ((instance->flags2 & 4U) == 0) {
      savedIntro = SAVE_GetSavedIntro(instance);
      extraData = (evControlSaveDataData *)INSTANCE_Query(instance,0x18);
      if (extraData != (evControlSaveDataData *)0x0) {
        extraSize = extraData->length;
      }
      if (savedIntro != (_SavedIntro *)0x0) {
        if ((int)*(short *)(savedIntro[1].name + 4) == extraSize) {
          SAVE_UpdateSavedIntro(instance,level,savedIntro,extraData);
        }
        else {
          SAVE_DeleteBlock((SavedBasic *)savedIntro);
          savedIntro = (_SavedIntro *)0x0;
        }
        if (savedIntro != (_SavedIntro *)0x0) {
          return;
        }
      }
      savedIntro = (_SavedIntro *)SAVE_GetSavedBlock(1,extraSize);
      if (savedIntro != (_SavedIntro *)0x0) {
        SAVE_UpdateSavedIntro(instance,level,savedIntro,extraData);
      }
    }
    else {
      SAVE_DeleteInstance(instance);
      savedBlock = SAVE_GetSavedSmallIntro(instance);
      if (savedBlock != (SavedIntroSmall *)0x0) {
        SAVE_DeleteBlock((SavedBasic *)savedBlock);
      }
      psVar2 = (size_t *)INSTANCE_Query(instance,0x18);
      if (psVar2 != (size_t *)0x0) {
        pvVar3 = SAVE_GetSavedBlock(5,*psVar2);
        *(undefined2 *)((int)pvVar3 + 4) = *(undefined2 *)&instance->introUniqueID;
        *(undefined2 *)((int)pvVar3 + 6) = *(undefined2 *)psVar2;
        memcpy((void *)((int)pvVar3 + 8),(void *)psVar2[1],*psVar2);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DeleteInstance(struct _Instance *instance /*$a2*/)
 // line 797, offset 0x800b08b0
	/* begin block 1 */
		// Start line: 798
		// Start offset: 0x800B08B0
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $a0
	/* end block 1 */
	// End offset: 0x800B091C
	// End Line: 814

	/* begin block 2 */
		// Start line: 1732
	/* end block 2 */
	// End Line: 1733

void SAVE_DeleteInstance(_Instance *instance)

{
  SavedBasic *pSVar1;
  uchar *puVar2;
  SavedBasic *savedBlock;
  
  savedBlock = (SavedBasic *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((*savedBlock == (SavedBasic)0x1) && ((int)(short)savedBlock[8] == instance->introUniqueID)
         ) {
        SAVE_DeleteBlock(savedBlock);
        return;
      }
      pSVar1 = savedBlock + 1;
      puVar2 = &savedBlock->savedID;
      savedBlock = (SavedBasic *)(puVar2 + (short)*pSVar1);
    } while ((SavedBasic *)(puVar2 + (short)*pSVar1) < savedInfoTracker.InfoEnd);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_SetDeadDeadBit(struct _Instance *instance /*$a0*/, long set /*$a1*/)
 // line 816, offset 0x800b092c
	/* begin block 1 */
		// Start line: 817
		// Start offset: 0x800B092C
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $a3
	// 		struct SavedDeadDeadBits *deadDeadBits; // $v1

		/* begin block 1.1 */
			// Start line: 837
			// Start offset: 0x800B0994
			// Variables:
		// 		int deadByte; // $a3
		// 		int deadBit; // $a0
		/* end block 1.1 */
		// End offset: 0x800B0A10
		// End Line: 859
	/* end block 1 */
	// End offset: 0x800B0A10
	// End Line: 862

	/* begin block 2 */
		// Start line: 1775
	/* end block 2 */
	// End Line: 1776

void SAVE_SetDeadDeadBit(_Instance *instance,long set)

{
  byte bVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  
  if (instance->introUniqueID < 0x2000) {
    psVar3 = (short *)0x0;
    psVar5 = (short *)savedInfoTracker.InfoStart;
    if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
      do {
        psVar3 = psVar5;
        if (*psVar3 == 4) break;
        psVar5 = (short *)((int)psVar3 + (int)psVar3[1]);
        psVar3 = (short *)0x0;
      } while (psVar5 < savedInfoTracker.InfoEnd);
    }
    if (psVar3 != (short *)0x0) {
      uVar4 = instance->introUniqueID;
      uVar2 = uVar4;
      if ((int)uVar4 < 0) {
        uVar2 = uVar4 + 7;
      }
      iVar6 = (int)uVar2 >> 3;
      if (iVar6 < 0x400) {
        bVar1 = (byte)(1 << (uVar4 & 7));
        if (set == 1) {
          *(byte *)((int)psVar3 + iVar6 + 4) = *(byte *)((int)psVar3 + iVar6 + 4) | bVar1;
        }
        else {
          *(byte *)((int)psVar3 + iVar6 + 4) = *(byte *)((int)psVar3 + iVar6 + 4) & ~bVar1;
        }
      }
      else {
        GXFilePrint("Ran out of dead bits, size = %d, uniqueID = %d\n");
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_RestoreGlobalSavePointer()
 // line 864, offset 0x800b0a20
	/* begin block 1 */
		// Start line: 866
		// Start offset: 0x800B0A20
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $v1
	/* end block 1 */
	// End offset: 0x800B0A6C
	// End Line: 881

	/* begin block 2 */
		// Start line: 1888
	/* end block 2 */
	// End Line: 1889

	/* begin block 3 */
		// Start line: 1889
	/* end block 3 */
	// End Line: 1890

	/* begin block 4 */
		// Start line: 1892
	/* end block 4 */
	// End Line: 1893

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGlobalSavePointer(void)

{
  _GlobalSaveTracker *p_Var1;
  
  GlobalSave = (_GlobalSaveTracker *)0x0;
  p_Var1 = (_GlobalSaveTracker *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    while (GlobalSave = p_Var1, p_Var1->savedID != 6) {
      p_Var1 = (_GlobalSaveTracker *)((int)&p_Var1->savedID + (int)p_Var1->saveSize);
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
 // line 883, offset 0x800b0a74
	/* begin block 1 */
		// Start line: 884
		// Start offset: 0x800B0A74
		// Variables:
	// 		struct _SavedIntro *saveIntro; // $v1
	// 		struct SavedDeadDeadBits *deadDeadBits; // $a3
	// 		long result; // $s0

		/* begin block 1.1 */
			// Start line: 906
			// Start offset: 0x800B0AE4
			// Variables:
		// 		int deadByte; // $a0
		// 		int deadBit; // $v1
		/* end block 1.1 */
		// End offset: 0x800B0B44
		// End Line: 920
	/* end block 1 */
	// End offset: 0x800B0B44
	// End Line: 922

	/* begin block 2 */
		// Start line: 1928
	/* end block 2 */
	// End Line: 1929

long SAVE_IsIntroDeadDead(Intro *intro)

{
  uint uVar1;
  short *psVar2;
  uint uVar3;
  short *psVar4;
  
  uVar1 = 0;
  if (intro->UniqueID < 0x2000) {
    psVar2 = (short *)savedInfoTracker.InfoStart;
    psVar4 = (short *)0x0;
    if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
      do {
        psVar4 = psVar2;
        if (*psVar2 == 4) break;
        psVar2 = (short *)((int)psVar2 + (int)psVar2[1]);
        psVar4 = (short *)0x0;
      } while (psVar2 < savedInfoTracker.InfoEnd);
    }
    uVar1 = 0;
    if (psVar4 != (short *)0x0) {
      uVar3 = intro->UniqueID;
      uVar1 = uVar3;
      if ((int)uVar3 < 0) {
        uVar1 = uVar3 + 7;
      }
      uVar3 = 1 << (uVar3 & 7);
      if ((int)uVar1 >> 3 < 0x400) {
        uVar1 = (uint)((*(byte *)((int)psVar4 + ((int)uVar1 >> 3) + 4) & uVar3) == uVar3);
      }
      else {
        GXFilePrint("Ran out of dead bits, size = %d, uniqueID = %d\n");
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DoInstanceDeadDead(struct _Instance *instance /*$s0*/)
 // line 926, offset 0x800b0b58
	/* begin block 1 */
		// Start line: 2031
	/* end block 1 */
	// End Line: 2032

void SAVE_DoInstanceDeadDead(_Instance *instance)

{
  SAVE_DeleteInstance(instance);
  SAVE_SetDeadDeadBit(instance,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_MarkDeadDead(struct _Instance *instance /*$a0*/)
 // line 936, offset 0x800b0b88
	/* begin block 1 */
		// Start line: 2051
	/* end block 1 */
	// End Line: 2052

	/* begin block 2 */
		// Start line: 2052
	/* end block 2 */
	// End Line: 2053

void SAVE_MarkDeadDead(_Instance *instance)

{
  instance->flags = instance->flags | 0x800000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_UndestroyInstance(struct _Instance *instance /*$a0*/)
 // line 941, offset 0x800b0b9c
	/* begin block 1 */
		// Start line: 2061
	/* end block 1 */
	// End Line: 2062

void SAVE_UndestroyInstance(_Instance *instance)

{
  SAVE_SetDeadDeadBit(instance,0);
  return;
}



// decompiled code
// original method signature: 
// struct SavedIntroSmall * /*$ra*/ SAVE_GetSavedSmallIntro(struct _Instance *instance /*$a1*/)
 // line 946, offset 0x800b0bbc
	/* begin block 1 */
		// Start line: 947
		// Start offset: 0x800B0BBC
		// Variables:
	// 		struct SavedBasic *curSave; // $s0
	/* end block 1 */
	// End offset: 0x800B0C3C
	// End Line: 967

	/* begin block 2 */
		// Start line: 2071
	/* end block 2 */
	// End Line: 2072

SavedIntroSmall * SAVE_GetSavedSmallIntro(_Instance *instance)

{
  short *psVar1;
  uchar *puVar2;
  SavedIntroSmall *pSVar3;
  
  pSVar3 = (SavedIntroSmall *)savedInfoTracker.InfoStart;
  if (savedInfoTracker.InfoStart < savedInfoTracker.InfoEnd) {
    do {
      if ((*(short *)pSVar3 == 5) && ((int)*(short *)(pSVar3 + 1) == instance->introUniqueID)) {
        printf("restore small intro for instance %s%ld\n");
        return pSVar3;
      }
      psVar1 = &pSVar3->introUniqueID;
      puVar2 = &pSVar3->savedID;
      pSVar3 = (SavedIntroSmall *)(puVar2 + *psVar1);
    } while ((SavedIntroSmall *)(puVar2 + *psVar1) < savedInfoTracker.InfoEnd);
  }
  return (SavedIntroSmall *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_UpdateGlobalSaveTracker()
 // line 970, offset 0x800b0c4c
	/* begin block 1 */
		// Start line: 2126
	/* end block 1 */
	// End Line: 2127

	/* begin block 2 */
		// Start line: 2127
	/* end block 2 */
	// End Line: 2128

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_UpdateGlobalSaveTracker(void)

{
  _GlobalSaveTracker *p_Var1;
  ulong uVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  p_Var1 = GlobalSave;
  GlobalSave->currentTime = gameTrackerX.globalTimeMult;
  uVar3 = gameTrackerX.sound.gSfxVol;
  uVar2 = gameTrackerX.sound.gMusicVol;
  (p_Var1->sound).gMasterVol = gameTrackerX.sound.gMasterVol;
  (p_Var1->sound).gMusicVol = uVar2;
  (p_Var1->sound).gSfxVol = uVar3;
  uVar4 = gameTrackerX.sound._16_4_;
  (p_Var1->sound).gVoiceVol = gameTrackerX.sound.gVoiceVol;
  *(undefined4 *)&(p_Var1->sound).gSfxOn = uVar4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_RestoreGlobalSaveTracker()
 // line 977, offset 0x800b0c94
	/* begin block 1 */
		// Start line: 2140
	/* end block 1 */
	// End Line: 2141

	/* begin block 2 */
		// Start line: 2141
	/* end block 2 */
	// End Line: 2142

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGlobalSaveTracker(void)

{
  gameTrackerX.sound.gMasterVol = (GlobalSave->sound).gMasterVol;
  gameTrackerX.sound.gMusicVol = (GlobalSave->sound).gMusicVol;
  gameTrackerX.sound.gSfxVol = (GlobalSave->sound).gSfxVol;
  gameTrackerX.sound.gVoiceVol = (GlobalSave->sound).gVoiceVol;
  gameTrackerX.sound._16_4_ = *(undefined4 *)&(GlobalSave->sound).gSfxOn;
  gameTrackerX.globalTimeMult = GlobalSave->currentTime;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_SaveEverythingInMemory()
 // line 985, offset 0x800b0ce0
	/* begin block 1 */
		// Start line: 986
		// Start offset: 0x800B0CE0
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		long i; // $s1

		/* begin block 1.1 */
			// Start line: 994
			// Start offset: 0x800B0D08
			// Variables:
		// 		struct _Instance *next; // $s1
		// 		struct Level *level; // $v0
		/* end block 1.1 */
		// End offset: 0x800B0D28
		// End Line: 1003
	/* end block 1 */
	// End offset: 0x800B0D80
	// End Line: 1019

	/* begin block 2 */
		// Start line: 2156
	/* end block 2 */
	// End Line: 2157

	/* begin block 3 */
		// Start line: 2162
	/* end block 3 */
	// End Line: 2163

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
 // line 1022, offset 0x800b0d98
	/* begin block 1 */
		// Start line: 2258
	/* end block 1 */
	// End Line: 2259

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_SaveGame(void)

{
  SAVE_SaveEverythingInMemory();
  SAVE_UpdateGlobalSaveTracker();
  *(char **)&GlobalSave->sizeUsedInBlock =
       savedInfoTracker.InfoEnd + -(int)savedInfoTracker.InfoStart;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_RestoreGame()
 // line 1030, offset 0x800b0dd4
	/* begin block 1 */
		// Start line: 2274
	/* end block 1 */
	// End Line: 2275

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_RestoreGame(void)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
  SAVE_RestoreGlobalSavePointer();
  SAVE_RestoreGlobalSaveTracker();
  savedInfoTracker.InfoEnd = savedInfoTracker.InfoStart + *(int *)&GlobalSave->sizeUsedInBlock;
  GAMELOOP_RequestLevelChange("under",1,&gameTrackerX);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_DebugSaveGame()
 // line 1050, offset 0x800b0e38
	/* begin block 1 */
		// Start line: 2323
	/* end block 1 */
	// End Line: 2324

	/* begin block 2 */
		// Start line: 2353
	/* end block 2 */
	// End Line: 2354

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_DebugSaveGame(void)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SAVE_LoadSaveGame()
 // line 1121, offset 0x800b0e40
	/* begin block 1 */
		// Start line: 2237
	/* end block 1 */
	// End Line: 2238

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SAVE_LoadSaveGame(void)

{
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
  GXFilePrint("Requesting level change for under1.\n");
  GAMELOOP_RequestLevelChange("under",1,&gameTrackerX);
  gameTrackerX.gameMode = 0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SAVE_SizeOfFreeSpace()
 // line 1131, offset 0x800b0e8c
	/* begin block 1 */
		// Start line: 2447
	/* end block 1 */
	// End Line: 2448

	/* begin block 2 */
		// Start line: 2448
	/* end block 2 */
	// End Line: 2449

/* WARNING: Unknown calling convention yet parameter storage is locked */

long SAVE_SizeOfFreeSpace(void)

{
  return (long)(savedInfoTracker.EndOfMemory + -(int)savedInfoTracker.InfoEnd);
}





