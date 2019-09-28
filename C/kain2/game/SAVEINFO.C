#include "THISDUST.H"
#include "SAVEINFO.H"


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

void SAVE_GetInstanceRotation(_Instance *instance,_SmallRotation *vector)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(instance,7);
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
  UW_angleInc._8_4_ = (void *)(UW_angleInc._4_4_ + the_header_size);
  UW_angleInc._16_4_ = UW_angleInc._4_4_ + 0x6000;
                    /* WARNING: Subroutine does not return */
  UW_angleInc._12_4_ = UW_angleInc._8_4_;
  memset(UW_angleInc._8_4_,0,0x6000 - the_header_size);
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
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x6000,'\x12');
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

void * SAVE_GetSavedBlock(long saveType,long extraSize)

{
  bool bVar1;
  undefined *puVar2;
  long lVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = (undefined *)0x0;
  if (9 < saveType) {
                    /* WARNING: Subroutine does not return */
    DEBUG_FatalError(s_illegal_save_type__d_800cf8dc);
  }
  iVar4 = (SaveArraySize[saveType] + extraSize + 3 >> 2) * 4;
  bVar1 = false;
  if (0x3fc < iVar4) {
                    /* WARNING: Subroutine does not return */
    DEBUG_FatalError(s_save__d_is_too_big___type__d__800cf8f4);
  }
  do {
    puVar2 = UW_angleInc._12_4_;
    if (UW_angleInc._12_4_ + iVar4 < UW_angleInc._16_4_) {
      *UW_angleInc._12_4_ = (char)saveType;
      puVar2[1] = (char)(iVar4 >> 2);
      UW_angleInc._12_4_ = UW_angleInc._12_4_ + iVar4;
      bVar1 = true;
      puVar5 = puVar2;
    }
    else {
      lVar3 = SAVE_PurgeAMemoryBlock();
      if (lVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        DEBUG_FatalError(s_ran_out_of_saved_memory__needed___800cf914);
      }
    }
  } while (!bVar1);
  return puVar5;
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
  int *piVar1;
  int *piVar2;
  menu_t *menu;
  
  menu = UW_angleInc._8_4_;
  if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
    do {
      if (((*(char *)&menu->nmenus == '\x01') && ((menu->stack[0].format.width & 0x100U) != 0)) ||
         ((*(char *)&menu->nmenus == '\a' && ((menu->stack[0].index & 0x100U) != 0)))) {
        menu_initialize(menu,(void *)0x0);
        return 1;
      }
      piVar1 = &menu->nmenus;
      piVar2 = &menu->nmenus;
      menu = (menu_t *)(piVar2 + *(byte *)((int)piVar1 + 1));
    } while ((menu_t *)(piVar2 + *(byte *)((int)piVar1 + 1)) < UW_angleInc._12_4_);
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

void VOICEXA_CdSyncCallback(uchar status,uchar *result)

{
  return;
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

undefined *
SAVE_UpdateSavedIntro(_Instance *param_1,int *param_2,undefined *param_3,size_t *param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = *(int *)(*param_2 + 0x48);
  if (param_3 != (undefined *)0x0) {
    uVar6 = *(undefined4 *)(param_1->introName + 4);
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)param_1->introName;
    *(undefined4 *)(param_3 + 8) = uVar6;
    *param_3 = 1;
    *(undefined2 *)(param_3 + 0xc) = *(undefined2 *)&param_1->introUniqueID;
    *(undefined2 *)(param_3 + 0xe) = *(undefined2 *)&param_1->currentStreamUnitID;
    *(undefined2 *)(param_3 + 0x10) = *(undefined2 *)&param_1->birthStreamUnitID;
    sVar1 = (param_1->position).y;
    sVar2 = (param_1->position).z;
    sVar3 = *(short *)(iVar5 + 0xe);
    sVar4 = *(short *)(iVar5 + 0x10);
    *(short *)(param_3 + 0x1a) = (param_1->position).x - *(short *)(iVar5 + 0xc);
    *(short *)(param_3 + 0x1c) = sVar1 - sVar3;
    *(short *)(param_3 + 0x1e) = sVar2 - sVar4;
    SAVE_GetInstanceRotation(param_1,(_SmallRotation *)(param_3 + 0x14));
    *(long *)(param_3 + 0x20) = param_1->flags;
    *(long *)(param_3 + 0x24) = param_1->flags2;
    param_3[3] = param_1->spectralLightGroup;
    param_3[2] = param_1->lightGroup;
    *(undefined2 *)(param_3 + 0x12) = *(undefined2 *)&param_1->attachedID;
    if (param_4 != (size_t *)0x0) {
      memcpy(param_3 + 0x28,(void *)param_4[1],*param_4);
    }
  }
  return param_3;
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

undefined *
SAVE_UpdateSavedIntroWithIntro(_Instance *param_1,int *param_2,undefined *param_3,size_t *param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  
  iVar5 = *(int *)(*param_2 + 0x48);
  if ((param_3 != (undefined *)0x0) && (param_1->intro != (Intro *)0x0)) {
    *param_3 = 7;
    *(short *)(param_3 + 4) = (short)((int)((int)param_1->intro - param_2[0x1f]) * 0x286bca1b >> 2);
    *(undefined2 *)(param_3 + 8) = *(undefined2 *)&param_1->introUniqueID;
    *(undefined2 *)(param_3 + 6) = *(undefined2 *)&param_1->birthStreamUnitID;
    sVar1 = (param_1->position).y;
    sVar2 = (param_1->position).z;
    sVar3 = *(short *)(iVar5 + 0xe);
    sVar4 = *(short *)(iVar5 + 0x10);
    *(short *)(param_3 + 0x1a) = (param_1->position).x - *(short *)(iVar5 + 0xc);
    *(short *)(param_3 + 0x1c) = sVar1 - sVar3;
    *(short *)(param_3 + 0x1e) = sVar2 - sVar4;
    SAVE_GetInstanceRotation(param_1,(_SmallRotation *)(param_3 + 0x14));
    *(long *)(param_3 + 0xc) = param_1->flags;
    *(long *)(param_3 + 0x10) = param_1->flags2;
    param_3[0xb] = param_1->spectralLightGroup;
    param_3[10] = param_1->lightGroup;
    *(undefined2 *)(param_3 + 2) = *(undefined2 *)&param_1->attachedID;
    if (param_4 != (size_t *)0x0) {
      memcpy(param_3 + 0x20,(void *)param_4[1],*param_4);
    }
  }
  return param_3;
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

SavedBasic * SAVE_GetSavedEvent(long areaID,long eventNumber)

{
  uchar uVar1;
  SavedBasic *pSVar2;
  
  pSVar2 = UW_angleInc._8_4_;
  if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
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
    } while (pSVar2 < UW_angleInc._12_4_);
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

void SAVE_DeleteSavedEvent(long areaID,long eventNumber)

{
  menu_t *menu;
  
  menu = (menu_t *)SAVE_GetSavedEvent(areaID,eventNumber);
  if (menu != (menu_t *)0x0) {
    menu_initialize(menu,(void *)eventNumber);
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

SavedBasic * SAVE_GetSavedNextEvent(long areaID,SavedBasic *curSave)

{
  SavedBasic *pSVar1;
  
  pSVar1 = UW_angleInc._8_4_;
  if (curSave != (SavedBasic *)0x0) {
    pSVar1 = curSave + (uint)curSave->shiftedSaveSize * 2;
  }
  while( true ) {
    if (UW_angleInc._12_4_ <= pSVar1) {
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

void SAVE_BufferIntro(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (iGpffff9df8 < 0x40) {
    piVar1 = (int *)&gp0xffffff1c;
    do {
      if (*piVar1 == param_1) break;
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 < 0x40);
    iVar3 = 0;
    if (iVar2 == 0x40) {
      piVar1 = (int *)&gp0xffffff1c;
      iGpffff9df8 = iGpffff9df8 + 1;
      do {
        iVar3 = iVar3 + 1;
        if (*piVar1 == 0) {
          *piVar1 = param_1;
          return;
        }
        piVar1 = piVar1 + 1;
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
  int aiStack24 [2];
  
  iVar2 = 0;
  if (numbufferedIntros != 0) {
    do {
      if (0x3f < iVar2) {
        return;
      }
      savedIntro = (_SavedIntro *)(&UW_angleInc.area)[iVar2];
      if (savedIntro != (_SavedIntro *)0x0) {
        if (savedIntro->savedID == '\x01') {
          streamUnit = STREAM_GetStreamUnitWithID((int)savedIntro->streamUnitID);
          if (streamUnit != (_StreamUnit *)0x0) {
            p_Var1 = INSTANCE_IntroduceSavedInstance(savedIntro,streamUnit,aiStack24);
LAB_800b5e80:
            if (p_Var1 == (_Instance *)0x0) goto LAB_800b5e98;
          }
        }
        else {
          streamUnit = STREAM_GetStreamUnitWithID((int)*(short *)(savedIntro->name + 2));
          if (streamUnit != (_StreamUnit *)0x0) {
            p_Var1 = INSTANCE_IntroduceSavedInstanceWithIntro
                               ((_SavedIntroWithIntro *)savedIntro,streamUnit,aiStack24);
            goto LAB_800b5e80;
          }
        }
        *(_SavedIntro **)(&UW_angleInc.area + iVar2) = (_SavedIntro *)0x0;
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
  int local_18 [2];
  
  iVar1 = streamUnit->StreamUnitID;
  savedIntro = UW_angleInc._8_4_;
  if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
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
    } while (savedIntro < UW_angleInc._12_4_);
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

long SAVE_HasSavedIntro(Intro *intro,long currentStreamID)

{
  char *pcVar1;
  
  pcVar1 = UW_angleInc._8_4_;
  if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
    do {
      if (((*pcVar1 == '\x01') && ((int)*(short *)(pcVar1 + 0xc) == intro->UniqueID)) ||
         ((*pcVar1 == '\a' && ((int)*(short *)(pcVar1 + 8) == intro->UniqueID)))) {
        return 1;
      }
      pcVar1 = pcVar1 + (uint)(byte)pcVar1[1] * 4;
    } while (pcVar1 < UW_angleInc._12_4_);
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

SavedLevel * SAVE_HasSavedLevel(long areaID)

{
  SavedLevel *pSVar1;
  
  pSVar1 = UW_angleInc._8_4_;
  if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
    do {
      if ((pSVar1->savedID == '\x03') && ((int)pSVar1->areaID == areaID)) {
        return pSVar1;
      }
      pSVar1 = (SavedLevel *)(&pSVar1->savedID + (uint)pSVar1->shiftedSaveSize * 4);
    } while (pSVar1 < UW_angleInc._12_4_);
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

SavedLevel * SAVE_CreatedSavedLevel(long areaID,Level *level)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  menu_t *menu;
  BSPTree *pBVar4;
  SavedLevel *pSVar5;
  menu_t *instance;
  undefined *opaque;
  int iVar6;
  
  uVar2 = level->terrain->UnitChangeFlags;
  sVar1 = (level->terrain->BSPTreeArray->globalOffset).z;
  opaque = (undefined *)0x0;
  if (((uVar2 & 1) != 0) || ((uVar2 & 2) != 0)) {
    opaque = &UNK_00000001;
  }
  if (opaque == (undefined *)0x0) {
    menu = (menu_t *)SAVE_HasSavedLevel(areaID);
    if (menu != (menu_t *)0x0) {
      menu_initialize(menu,opaque);
    }
  }
  else {
    iVar6 = level->terrain->numBSPTrees + -2;
    menu = (menu_t *)0x0;
    if (0 < iVar6) {
      menu = (menu_t *)SAVE_HasSavedLevel(areaID);
      if (menu == (menu_t *)0x0) {
                    /* WARNING: Subroutine does not return */
        SAVE_GetSavedBlock(3,iVar6 * 8);
      }
      *(undefined2 *)((int)&menu->nmenus + 2) = (short)areaID;
      if ((level->waterZLevel == -0x7fff) || (level->waterZLevel == 0x7fff)) {
        *(short *)&menu->nitems = *(short *)&level->waterZLevel;
      }
      else {
        *(short *)&menu->nitems = *(short *)&level->waterZLevel - sVar1;
      }
      *(short *)((int)&menu->nitems + 2) = (short)iVar6;
      if (0 < level->terrain->numBSPTrees) {
        pBVar4 = level->terrain->BSPTreeArray;
        instance = menu;
        if (1 < (ushort)(pBVar4->ID + 1U)) {
          *(undefined *)((int)&menu->stack[0].fn + 3) = 0;
          sVar1 = (pBVar4->localOffset).z;
          menu->nbytes = *(int *)&pBVar4->localOffset;
          *(short *)&menu->stack[0].fn = sVar1;
          *(undefined *)((int)&menu->stack[0].fn + 2) = *(undefined *)&pBVar4->flags;
          instance = (menu_t *)&menu->nbytes;
        }
        bVar3 = 1 < level->terrain->numBSPTrees;
        pSVar5 = (SavedLevel *)(uint)bVar3;
        if (bVar3) {
          SAVE_DeleteInstance((_Instance *)instance);
          return pSVar5;
        }
      }
    }
  }
  return (SavedLevel *)menu;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void menu_initialize(menu_t *menu,void *opaque)

{
  uint uVar1;
  menu_t *pmVar2;
  char *pcVar3;
  int iVar4;
  
  uVar1 = (uint)*(byte *)((int)&menu->nmenus + 1);
  if (GameCheat_800d00a8._12_4_ != 0) {
    iVar4 = 0;
    pcVar3 = &CHAR____800d61d8;
    do {
      pmVar2 = *(menu_t **)pcVar3;
      if (pmVar2 == menu) {
        *(menu_t **)pcVar3 = (menu_t *)0x0;
      }
      else {
        if (menu < pmVar2) {
          *(menu_t **)pcVar3 = (menu_t *)((int)pmVar2 + uVar1 * -4);
        }
      }
      iVar4 = iVar4 + 1;
      pcVar3 = (char *)((menu_t **)pcVar3 + 1);
    } while (iVar4 < 0x40);
  }
  memmove(menu,&menu->nmenus + uVar1,_CHAR____800d61d0 - (int)(&menu->nmenus + uVar1));
  _CHAR____800d61d0 = _CHAR____800d61d0 + uVar1 * -4;
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

void SAVE_Instance(_Instance *instance,Level *level)

{
  int in_v0;
  
  VOICEXA_CdSyncCallback((uchar)instance,(uchar *)level);
  if (in_v0 != 0) {
    if ((instance->flags2 & 4U) != 0) {
      SAVE_DeleteInstance(instance);
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(instance,0x18);
    }
    if (in_v0 == 1) {
      SAVE_DeleteInstance(instance);
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(instance,0x18);
    }
    if (in_v0 == 2) {
      SAVE_DeleteInstance(instance);
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(instance,0x18);
    }
    if (in_v0 == 3) {
      SAVE_DeleteInstance(instance);
                    /* WARNING: Subroutine does not return */
      SAVE_GetSavedBlock(8,0);
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
  byte bVar1;
  menu_t *menu;
  
  menu = UW_angleInc._8_4_;
  if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
    do {
      bVar1 = *(byte *)&menu->nmenus;
      if (((((bVar1 == 1) && ((int)*(short *)&menu->stack[0].fn == instance->introUniqueID)) ||
           ((bVar1 == 7 && ((int)*(short *)&menu->nbytes == instance->introUniqueID)))) ||
          ((bVar1 == 5 && ((int)*(short *)((int)&menu->nmenus + 2) == instance->introUniqueID)))) ||
         ((bVar1 == 8 && ((int)*(short *)((int)&menu->nmenus + 2) == instance->introUniqueID)))) {
        menu_initialize(menu,(void *)(uint)bVar1);
        return;
      }
      menu = (menu_t *)(&menu->nmenus + *(byte *)((int)&menu->nmenus + 1));
    } while (menu < UW_angleInc._12_4_);
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

void SAVE_SetDeadDeadBit(int uniqueID,long set)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (uniqueID < 0x2000) {
    pcVar3 = (char *)0x0;
    pcVar4 = UW_angleInc._8_4_;
    if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
      do {
        pcVar3 = pcVar4;
        if (*pcVar3 == '\x04') break;
        pcVar4 = pcVar3 + (uint)(byte)pcVar3[1] * 4;
        pcVar3 = (char *)0x0;
      } while (pcVar4 < UW_angleInc._12_4_);
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
  p_Var1 = UW_angleInc._8_4_;
  if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
    while (GlobalSave = p_Var1, *(char *)&p_Var1->savedID != '\x06') {
      p_Var1 = (_GlobalSaveTracker *)
               (&p_Var1->savedID + (uint)*(byte *)((int)&p_Var1->savedID + 1) * 2);
      if (UW_angleInc._12_4_ <= p_Var1) {
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
  if (uniqueID < 0x2000) {
    pcVar2 = UW_angleInc._8_4_;
    pcVar4 = (char *)0x0;
    if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
      do {
        pcVar4 = pcVar2;
        if (*pcVar2 == '\x04') break;
        pcVar2 = pcVar2 + (uint)(byte)pcVar2[1] * 4;
        pcVar4 = (char *)0x0;
      } while (pcVar2 < UW_angleInc._12_4_);
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
  SAVE_SetDeadDeadBit(instance->introUniqueID,1);
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
  SAVE_SetDeadDeadBit(instance->introUniqueID,0);
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

SavedIntroSmall * SAVE_GetSavedSmallIntro(_Instance *instance)

{
  SavedIntroSmall *pSVar1;
  
  pSVar1 = UW_angleInc._8_4_;
  if (UW_angleInc._8_4_ < UW_angleInc._12_4_) {
    do {
      if ((pSVar1->savedID == '\x05') && ((int)pSVar1->introUniqueID == instance->introUniqueID)) {
        return pSVar1;
      }
      pSVar1 = pSVar1 + pSVar1->shiftedSaveSize;
    } while (pSVar1 < UW_angleInc._12_4_);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long SAVE_SizeOfFreeSpace(void)

{
  int in_a0;
  char *pcVar1;
  
  pcVar1 = _CHAR____800d74a8;
  if (_CHAR____800d74a8 < _CHAR____800d74ac) {
    do {
      if ((*pcVar1 == '\b') && ((int)*(short *)(pcVar1 + 2) == *(int *)(in_a0 + 0x3c))) {
        return (long)pcVar1;
      }
      pcVar1 = pcVar1 + (uint)(byte)pcVar1[1] * 4;
    } while (pcVar1 < _CHAR____800d74ac);
  }
  return 0;
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
  _CameraKey *p_Var3;
  undefined4 uVar4;
  ushort uVar5;
  int iVar6;
  
  p_Var1 = GlobalSave;
  GlobalSave->currentTime = theCamera.focusDistanceList[1][1];
  p_Var3 = theCamera.cameraKey;
  uVar2 = theCamera._452_4_;
  (p_Var1->sound).gMasterVol = theCamera.collisionTargetFocusRotation._4_4_;
  (p_Var1->sound).gMusicVol = uVar2;
  *(_CameraKey **)&(p_Var1->sound).gSfxVol = p_Var3;
  uVar4 = theCamera.focusSphere._4_4_;
  (p_Var1->sound).gVoiceVol = theCamera.focusSphere.position._0_4_;
  *(undefined4 *)&(p_Var1->sound).gSfxOn = uVar4;
  GlobalSave->saveVersion = 0x5524;
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
  if (GlobalSave->saveVersion == 0x5524) {
    theCamera.focusDistanceList[1][1] = GlobalSave->currentTime;
    theCamera.collisionTargetFocusRotation._4_4_ = (GlobalSave->sound).gMasterVol;
    theCamera._452_4_ = (GlobalSave->sound).gMusicVol;
    theCamera.cameraKey = (_CameraKey *)(GlobalSave->sound).gSfxVol;
    theCamera.focusSphere.position._0_4_ = (GlobalSave->sound).gVoiceVol;
    theCamera.focusSphere._4_4_ = *(undefined4 *)&(GlobalSave->sound).gSfxOn;
    SOUND_SetSfxVolume((int)theCamera.cameraKey);
    SOUND_SetMusicVolume(theCamera._452_4_);
    SOUND_SetVoiceVolume(theCamera.focusSphere.position._0_4_);
    if ((GlobalSave->flags & 2U) == 0) {
      GAMEPAD_DisableDualShock();
    }
    else {
      GAMEPAD_EnableDualShock();
    }
  }
  else {
    SAVE_ClearMemory((GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
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
  FontChar *pFVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4) != 0) {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(*(long *)(*(int *)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4) + 0x38));
  }
  pFVar1 = fontTracker.font_buffer + 0x5c;
  do {
    if (*(short *)&pFVar1->c == 2) {
      EVENT_SaveEventsFromLevel(*(long *)pFVar1,*(Level **)&pFVar1[1].y);
      SAVE_CreatedSavedLevel(*(long *)pFVar1,*(Level **)&pFVar1[1].y);
    }
    iVar2 = iVar2 + 1;
    pFVar1 = (FontChar *)&pFVar1[10].c;
  } while (iVar2 < 0x10);
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
  
  do {
    iVar1 = STREAM_PollLoadQueue();
  } while (iVar1 != 0);
  SAVE_SaveEverythingInMemory();
  SAVE_UpdateGlobalSaveTracker();
  GlobalSave->sizeUsedInBlock = UW_angleInc.x - UW_angleInc.newX;
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
  theCamera.positionAccl._4_4_ = theCamera.positionAccl._4_4_ | 0x200000;
  SAVE_RestoreGlobalSavePointer();
  SAVE_RestoreGlobalSaveTracker();
  UW_angleInc._12_4_ = UW_angleInc._8_4_ + GlobalSave->sizeUsedInBlock;
  GAMELOOP_RequestLevelChange
            (s_under_800cf954,1,(GameTracker *)(theCamera.core.vvNormalWorVecMat[0].m + 4));
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

int SAVE_SizeOfFreeSpace(void)

{
  return iGpffffff18 - iGpffffff14;
}





