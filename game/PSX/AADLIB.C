#include "THISDUST.H"
#include "AADLIB.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetMemorySize(struct AadInitAttr *attributes /*$a0*/)
 // line 39, offset 0x80051d1c
	/* begin block 1 */
		// Start line: 78
	/* end block 1 */
	// End Line: 79

	/* begin block 2 */
		// Start line: 79
	/* end block 2 */
	// End Line: 80

ulong aadGetMemorySize(AadInitAttr *attributes)

{
  return (ulong)(&DAT_00001c88 + attributes->numSlots * 0x5d0);
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadInit(struct AadInitAttr *attributes /*$s1*/, unsigned char *memoryPtr /*$s0*/)
 // line 45, offset 0x80051d40
	/* begin block 1 */
		// Start line: 46
		// Start offset: 0x80051D40
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $v1
	// 		unsigned long size; // $v0
	// 		int slotNumber; // $a2
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80051FD8
	// End Line: 182

	/* begin block 2 */
		// Start line: 90
	/* end block 2 */
	// End Line: 91

int aadInit(AadInitAttr *attributes,uchar *memoryPtr)

{
  byte bVar1;
  AadMemoryStruct *pAVar2;
  AadMemoryStruct *pAVar3;
  ulong __n;
  undefined *puVar4;
  _func_36 *p_Var5;
  _func_36 *p_Var6;
  _func_36 *p_Var7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  aadGp = GetGp();
  EnterCriticalSection();
  __n = aadGetMemorySize(attributes);
  aadMem = (AadMemoryStruct *)memoryPtr;
  if (memoryPtr == (uchar *)0x0) {
    puVar4 = &DAT_00001009;
  }
  else {
    memset(memoryPtr,0,__n);
    pAVar2 = aadMem;
    puVar4 = &DAT_00001008;
    if ((attributes->nonBlockLoadProc != (_func_32 *)0x0) &&
       (puVar4 = &DAT_00001008, attributes->nonBlockBufferedLoadProc != (_func_33 *)0x0)) {
      if (attributes->memoryMallocProc == (_func_34 *)0x0) {
        puVar4 = &DAT_00001008;
      }
      else {
        *(_func_32 **)&aadMem->nonBlockLoadProc = attributes->nonBlockLoadProc;
        *(_func_33 **)&pAVar2->nonBlockBufferedLoadProc = attributes->nonBlockBufferedLoadProc;
        *(_func_34 **)&pAVar2->memoryMallocProc = attributes->memoryMallocProc;
        *(_func_35 **)&pAVar2->memoryFreeProc = attributes->memoryFreeProc;
        memset(pAVar2->sfxToneMasterList,0xff,0x200);
        memset(aadMem->sfxWaveMasterList,0xff,0x200);
        pAVar2 = aadMem;
        aadMem->sramDescriptorTbl[0].prevIndex = -1;
        pAVar3 = aadMem;
        pAVar2->nextSramDescIndex = 1;
        pAVar2->sramDescriptorTbl[0].waveID = 0x8000;
        pAVar2->sramDescriptorTbl[0].address = 0x202;
        pAVar2->firstSramBlockDescIndex = 0;
        pAVar2->sramDescriptorTbl[0].size = 0x91d8;
        pAVar3->sramDescriptorTbl[0].nextIndex = -1;
        aadPurgeLoadQueue();
        SpuInit();
        SpuSetCommonMasterVolume(0,0);
        iVar10 = 0;
        if (0 < attributes->numSlots) {
          puVar4 = &DAT_00001c88;
          do {
            iVar8 = 0;
            p_Var6 = (_func_36 *)((int)&aadMem->updateCounter + (int)puVar4);
            aadMem->sequenceSlots[iVar10] = p_Var6;
            p_Var6[0x53f] = SUB41(iVar10,0);
            p_Var6[0x53e] = (_func_36)0xff;
            p_Var6[0x551] = SUB41(iVar10 << 4,0);
            p_Var6[0x552] = (_func_36)0x7f;
            p_Var6[0x553] = (_func_36)0x3f;
            *(int **)(p_Var6 + 0x554) = &aadMem->musicMasterVol;
            p_Var7 = p_Var6;
            do {
              p_Var5 = p_Var6 + iVar8;
              p_Var5[0x590] = (_func_36)0xff;
              p_Var5[0x5a0] = (_func_36)0x7f;
              p_Var5[0x5b0] = (_func_36)0x3f;
              *(undefined2 *)(p_Var7 + 0x570) = 0x2000;
              iVar8 = iVar8 + 1;
              p_Var7 = p_Var7 + 2;
            } while (iVar8 < 0x10);
            *(_func_36 **)(p_Var6 + 0x538) = p_Var6;
            p_Var6[0x53c] = SUB41(iVar10,0);
            iVar10 = iVar10 + 1;
            puVar4 = puVar4 + 0x5d0;
          } while (iVar10 < attributes->numSlots);
        }
        pAVar2 = aadMem;
        uVar9 = 0;
        (aadMem->sfxSlot).handleCounter = 0x3039;
        (pAVar2->sfxSlot).sfxVolume = '\x7f';
        pAVar2 = aadMem;
        iVar10 = 0;
        aadMem->numSlots = (uint)*(byte *)&attributes->numSlots;
        bVar1 = *(byte *)&attributes->updateMode;
        pAVar2->sfxMasterVol = 0x7f;
        pAVar2->musicMasterVol = 0x7f;
        pAVar2->endSequenceCallback = (_func_49 *)0x0;
        pAVar2->controller11Callback = (_func_48 *)0x0;
        pAVar2->updateMode = (uint)bVar1;
        do {
          iVar8 = (int)&aadMem->updateCounter + iVar10;
          *(undefined *)(iVar8 + 0x1e4) = 0xff;
          pAVar2 = aadMem;
          *(int *)(iVar8 + 0x1dc) = 1 << (uVar9 & 0x1f);
          (&pAVar2->synthVoice[0].voiceNum)[iVar10] = (uchar)uVar9;
          pAVar2 = aadMem;
          uVar9 = uVar9 + 1;
          iVar10 = iVar10 + 0x1c;
        } while ((int)uVar9 < 0x18);
        iVar10 = aadMem->updateMode;
        aadMem->voiceKeyOffRequest = 0;
        pAVar2->voiceKeyOnRequest = 0;
        pAVar2->voiceReverbRequest = 0;
        if (iVar10 < 4) {
          aadInstallUpdateFunc(aadSlotUpdateWrapper,(uint)(&aadHblanksPerUpdate)[iVar10]);
        }
        aadMem->flags = 0;
        ExitCriticalSection();
        puVar4 = (undefined *)0x0;
      }
    }
  }
  return (int)puVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr /*$s0*/, int hblanksPerUpdate /*$s1*/)
 // line 185, offset 0x80051fec
	/* begin block 1 */
		// Start line: 493
	/* end block 1 */
	// End Line: 494

void aadInstallUpdateFunc
               (TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr,int hblanksPerUpdate)

{
  EnterCriticalSection();
  __hblankEvent = OpenEvent();
  EnableEvent();
  SetRCnt(0xf2000001,(short)hblanksPerUpdate,0x1000);
  StartRCnt(0xf2000001);
  ExitCriticalSection();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInitVolume()
 // line 198, offset 0x80052068
	/* begin block 1 */
		// Start line: 519
	/* end block 1 */
	// End Line: 520

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadInitVolume(void)

{
  aadMem->masterVolume = 0;
  SpuSetCommonCDMix(0);
  SpuSetCommonMasterVolume(0,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetMasterVolume(int volume /*$a0*/)
 // line 209, offset 0x8005209c
	/* begin block 1 */
		// Start line: 545
	/* end block 1 */
	// End Line: 546

void aadSetMasterVolume(int volume)

{
  int iVar1;
  
  iVar1 = (int)(short)volume;
  aadMem->masterVolume = iVar1;
  SpuSetCommonMasterVolume(iVar1,iVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStartMasterVolumeFade(int targetVolume /*$a0*/, int volumeStep /*$a1*/, TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback /*$a2*/)
 // line 218, offset 0x800520cc
	/* begin block 1 */
		// Start line: 566
	/* end block 1 */
	// End Line: 567

	/* begin block 2 */
		// Start line: 568
	/* end block 2 */
	// End Line: 569

void aadStartMasterVolumeFade
               (int targetVolume,int volumeStep,
               TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback)

{
  AadMemoryStruct *pAVar1;
  
  pAVar1 = aadMem;
  (aadMem->masterVolFader).volumeStep = volumeStep;
  (pAVar1->masterVolFader).targetVolume = targetVolume;
  *(TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback *)
   &(pAVar1->masterVolFader).fadeCompleteCallback = fadeCompleteCallback;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetSfxMasterVolume(int volume /*$a0*/)
 // line 228, offset 0x800520e4
	/* begin block 1 */
		// Start line: 586
	/* end block 1 */
	// End Line: 587

	/* begin block 2 */
		// Start line: 588
	/* end block 2 */
	// End Line: 589

void aadSetSfxMasterVolume(int volume)

{
  aadMem->sfxMasterVol = volume & 0xff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetMusicMasterVolume(int volume /*$a0*/)
 // line 236, offset 0x800520f4
	/* begin block 1 */
		// Start line: 237
		// Start offset: 0x800520F4
		// Variables:
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x80052148
	// End Line: 246

	/* begin block 2 */
		// Start line: 602
	/* end block 2 */
	// End Line: 603

	/* begin block 3 */
		// Start line: 606
	/* end block 3 */
	// End Line: 607

void aadSetMusicMasterVolume(int volume)

{
  int *piVar1;
  _AadSequenceSlot **pp_Var2;
  int iVar3;
  
  piVar1 = &aadMem->numSlots;
  iVar3 = 0;
  aadMem->musicMasterVol = volume;
  if (0 < *piVar1) {
    do {
      pp_Var2 = (_AadSequenceSlot **)(aadMem->sequenceSlots + iVar3);
      iVar3 = iVar3 + 1;
      aadUpdateSlotVolPan(*pp_Var2);
    } while (iVar3 < aadMem->numSlots);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStartMusicMasterVolFade(int targetVolume /*$a0*/, int volumeStep /*$a1*/, TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback /*$a2*/)
 // line 248, offset 0x80052158
	/* begin block 1 */
		// Start line: 631
	/* end block 1 */
	// End Line: 632

	/* begin block 2 */
		// Start line: 633
	/* end block 2 */
	// End Line: 634

void aadStartMusicMasterVolFade
               (int targetVolume,int volumeStep,
               TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback)

{
  AadMemoryStruct *pAVar1;
  
  pAVar1 = aadMem;
  (aadMem->musicMasterVolFader).volumeStep = volumeStep;
  (pAVar1->musicMasterVolFader).targetVolume = targetVolume;
  *(TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback *)
   &(pAVar1->musicMasterVolFader).fadeCompleteCallback = fadeCompleteCallback;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadShutdown()
 // line 284, offset 0x80052170
	/* begin block 1 */
		// Start line: 564
	/* end block 1 */
	// End Line: 565

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadShutdown(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint in_a2;
  
  EnterCriticalSection();
  StopRCnt(0xf2000001);
  DisableEvent();
  CloseEvent();
  aadMem->flags = aadMem->flags | 2;
  ExitCriticalSection();
  uVar2 = 0xffffff;
  SpuSetKey(0,0xffffff);
  uVar1 = aadGetReverbMode();
  SpuClearReverbWorkArea(uVar1,uVar2,in_a2);
  SpuQuit();
  aadMem = (AadMemoryStruct *)0x0;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ aadSlotUpdateWrapper()
 // line 320, offset 0x800521f8
	/* begin block 1 */
		// Start line: 321
		// Start offset: 0x800521F8
		// Variables:
	// 		unsigned long curGp; // $s0
	/* end block 1 */
	// End offset: 0x800521F8
	// End Line: 321

	/* begin block 2 */
		// Start line: 743
	/* end block 2 */
	// End Line: 744

/* WARNING: Unknown calling convention yet parameter storage is locked */

long aadSlotUpdateWrapper(void)

{
  GetGp();
  SetGp();
  aadSlotUpdate();
  SetGp();
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSlotUpdate()
 // line 337, offset 0x8005223c
	/* begin block 1 */
		// Start line: 338
		// Start offset: 0x8005223C
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s1
	// 		struct AadSeqEvent *seqEventPtr; // $a1
	// 		int slotNumber; // $fp
	// 		int i; // $a3
	// 		int fadeComplete; // $v1
	// 		int track; // $s4
	// 		int newVol; // $s0

		/* begin block 1.1 */
			// Start line: 353
			// Start offset: 0x80052284
			// Variables:
		// 		unsigned long vmask; // $a2
		/* end block 1.1 */
		// End offset: 0x800522FC
		// End Line: 368
	/* end block 1 */
	// End offset: 0x80052738
	// End Line: 557

	/* begin block 2 */
		// Start line: 778
	/* end block 2 */
	// End Line: 779

	/* begin block 3 */
		// Start line: 787
	/* end block 3 */
	// End Line: 788

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadSlotUpdate(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  AadSfxSlot *pAVar5;
  AadMemoryStruct *pAVar6;
  ulong uVar7;
  int track;
  int iVar8;
  uchar uVar9;
  _func_12 *p_Var10;
  uint uVar11;
  AadSeqEvent *event;
  uint uVar12;
  int iVar13;
  _AadSequenceSlot *p_Var14;
  _AadSequenceSlot *slot;
  _AadSequenceSlot *p_Var15;
  
  if (aadMem != (AadMemoryStruct *)0x0) {
    if ((aadMem->flags & 2U) == 0) {
      SpuGetAllKeysStatus(aadMem->voiceStatus);
      pAVar6 = aadMem;
      iVar13 = 0;
      uVar12 = 1;
      do {
        cVar1 = pAVar6->voiceStatus[iVar13];
        if (cVar1 == '\x03') {
          uVar7 = pAVar6->voiceKeyOffRequest | uVar12;
LAB_800522e8:
          pAVar6->voiceKeyOffRequest = uVar7;
        }
        else {
          if (((pAVar6->voiceKeyOffRequest & uVar12) != 0) && ((cVar1 == '\0' || (cVar1 == '\x02')))
             ) {
            uVar7 = pAVar6->voiceKeyOffRequest & ~uVar12;
            goto LAB_800522e8;
          }
        }
        iVar13 = iVar13 + 1;
        uVar12 = uVar12 << 1;
      } while (iVar13 < 0x18);
      if (((aadMem->flags & 4U) == 0) && (iVar13 = 0, 0 < aadMem->numSlots)) {
        track = 0;
        do {
          slot = *(_AadSequenceSlot **)((int)aadMem->sequenceSlots + track);
          if (((slot->status & 1) != 0) && ((slot->slotFlags & 1) == 0)) {
            (slot->tempo).currentTick =
                 (slot->tempo).currentTick + (uint)(slot->tempo).ticksPerUpdate;
            uVar11 = (slot->tempo).tickTimeFixed;
            uVar12 = (slot->tempo).currentError + (slot->tempo).errorPerUpdate;
            (slot->tempo).currentError = uVar12;
            if (uVar11 <= uVar12) {
              (slot->tempo).currentError = uVar12 - uVar11;
              (slot->tempo).currentTick = (slot->tempo).currentTick + 1;
            }
            track = 0;
            p_Var14 = slot;
            p_Var15 = slot;
            do {
              if (p_Var15->sequencePosition[0] == (_func_9 *)0x0) break;
              bVar2 = p_Var14->eventsInQueue[0];
              while ((bVar2 < 3 && (iVar8 = aadQueueNextEvent(slot,track), iVar8 == 0))) {
                bVar2 = p_Var14->eventsInQueue[0];
              }
              p_Var14 = (_AadSequenceSlot *)((int)&(p_Var14->tempo).currentTick + 1);
              track = track + 1;
              p_Var15 = (_AadSequenceSlot *)&(p_Var15->tempo).currentError;
            } while (track < 0x10);
            track = 0;
            iVar8 = 0;
            p_Var14 = slot;
            p_Var15 = slot;
            do {
              if (p_Var14->sequencePosition[0] == (_func_9 *)0x0) break;
              uVar9 = p_Var15->eventsInQueue[0];
              while (uVar9 != '\0') {
                event = (AadSeqEvent *)
                        ((int)&slot->eventQueue[(uint)p_Var15->eventOut[0] * 0x10].deltaTime + iVar8
                        );
                uVar12 = event->deltaTime + p_Var14->lastEventExecutedTime[0];
                if ((slot->tempo).currentTick < uVar12) break;
                p_Var14->lastEventExecutedTime[0] = uVar12;
                uVar9 = p_Var15->eventOut[0] + '\x01';
                p_Var15->eventOut[0] = uVar9;
                p_Var15->eventsInQueue[0] = p_Var15->eventsInQueue[0] + -1;
                if (uVar9 == '\x04') {
                  p_Var15->eventOut[0] = '\0';
                }
                aadExecuteEvent(event,slot);
                uVar9 = p_Var15->eventsInQueue[0];
              }
              p_Var14 = (_AadSequenceSlot *)&(p_Var14->tempo).currentError;
              iVar8 = iVar8 + 0xc;
              track = track + 1;
              p_Var15 = (_AadSequenceSlot *)((int)&(p_Var15->tempo).currentTick + 1);
            } while (track < 0x10);
          }
          iVar13 = iVar13 + 1;
          track = iVar13 * 4;
        } while (iVar13 < aadMem->numSlots);
      }
      uVar3 = (aadMem->sfxSlot).commandsInQueue;
      while (uVar3 != 0) {
        aadExecuteSfxCommand((aadMem->sfxSlot).commandQueue + (aadMem->sfxSlot).commandOut);
        pAVar6 = aadMem;
        pAVar5 = &aadMem->sfxSlot;
        uVar9 = (aadMem->sfxSlot).commandOut + '\x01';
        (aadMem->sfxSlot).commandOut = uVar9;
        (pAVar6->sfxSlot).commandsInQueue = pAVar5->commandsInQueue - 1;
        if (uVar9 == ' ') {
          (aadMem->sfxSlot).commandOut = '\0';
        }
        uVar3 = (aadMem->sfxSlot).commandsInQueue;
      }
      uVar12 = aadMem->voiceKeyOffRequest & ~aadMem->voiceKeyOnRequest;
      aadMem->voiceKeyOffRequest = uVar12;
      if (uVar12 != 0) {
        SpuSetKey(0,uVar12);
      }
      SpuSetReverbVoice(1,aadMem->voiceReverbRequest);
      SpuSetReverbVoice(0,~aadMem->voiceReverbRequest);
      if (aadMem->voiceKeyOnRequest != 0) {
        SpuSetKey(1,aadMem->voiceKeyOnRequest);
        aadMem->voiceKeyOnRequest = 0;
      }
    }
    iVar13 = (aadMem->masterVolFader).volumeStep;
    bVar4 = false;
    if (iVar13 != 0) {
      track = aadMem->masterVolume + iVar13;
      if (iVar13 < 0) {
        bVar4 = track < (aadMem->masterVolFader).targetVolume;
      }
      else {
        if ((aadMem->masterVolFader).targetVolume < track) {
          bVar4 = true;
        }
      }
      if (bVar4) {
        track = (aadMem->masterVolFader).targetVolume;
        p_Var10 = (aadMem->masterVolFader).fadeCompleteCallback;
        (aadMem->masterVolFader).volumeStep = 0;
        if (p_Var10 != (_func_12 *)0x0) {
          (*p_Var10)();
        }
      }
      aadSetMasterVolume(track);
    }
    iVar13 = (aadMem->musicMasterVolFader).volumeStep;
    if ((iVar13 != 0) && (bVar4 = false, (aadMem->updateCounter & 1) == 0)) {
      track = aadMem->musicMasterVol + iVar13;
      if (iVar13 < 0) {
        bVar4 = track <= (aadMem->musicMasterVolFader).targetVolume;
      }
      else {
        if ((aadMem->musicMasterVolFader).targetVolume <= track) {
          bVar4 = true;
        }
      }
      if (bVar4) {
        track = (aadMem->musicMasterVolFader).targetVolume;
        p_Var10 = (aadMem->musicMasterVolFader).fadeCompleteCallback;
        (aadMem->musicMasterVolFader).volumeStep = 0;
        if (p_Var10 != (_func_12 *)0x0) {
          (*p_Var10)();
        }
      }
      aadSetMusicMasterVolume(track);
    }
    aadMem->updateCounter = aadMem->updateCounter + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadCreateFourCharID(char a /*$a0*/, char b /*$a1*/, char c /*$a2*/, char d /*$a3*/)
 // line 601, offset 0x80052768
	/* begin block 1 */
		// Start line: 1400
	/* end block 1 */
	// End Line: 1401

	/* begin block 2 */
		// Start line: 1401
	/* end block 2 */
	// End Line: 1402

ulong aadCreateFourCharID(char a,char b,char c,char d)

{
  return CONCAT13(a,CONCAT12(b,CONCAT11(c,d)));
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadLoadDynamicSoundBank(char *sndFileName /*$s3*/, char *smpFileName /*$s4*/, int dynamicBankIndex /*$s2*/, int loadOption /*$s5*/, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc /*stack 16*/)
 // line 609, offset 0x80052790
	/* begin block 1 */
		// Start line: 610
		// Start offset: 0x80052790
		// Variables:
	// 		int i; // $a0
	// 		struct AadDynamicBankLoadInfo *info; // $s1
	/* end block 1 */
	// End offset: 0x800528C4
	// End Line: 664

	/* begin block 2 */
		// Start line: 1416
	/* end block 2 */
	// End Line: 1417

int aadLoadDynamicSoundBank
              (char *sndFileName,char *smpFileName,int dynamicBankIndex,int loadOption,
              TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc)

{
  AadMemoryStruct *pAVar1;
  undefined *puVar2;
  AadMemoryStruct *pAVar3;
  int iVar4;
  AadDynamicBankLoadInfo *__dest;
  
  pAVar1 = aadMem;
  iVar4 = 0;
  __dest = &aadMem->dynamicBankLoadInfo;
  pAVar3 = aadMem;
  do {
    iVar4 = iVar4 + 1;
    if (pAVar3->dynamicBankStatus[0] == 1) {
      return (int)&DAT_00001006;
    }
    pAVar3 = (AadMemoryStruct *)&pAVar3->numSlots;
  } while (iVar4 < 2);
  if (dynamicBankIndex < 2) {
    if (((&aadMem->updateCounter + dynamicBankIndex)[0x140] == 2) &&
       ((&aadMem->updateCounter + dynamicBankIndex)[0x142] != 0)) {
      aadFreeDynamicSoundBank(dynamicBankIndex);
    }
    aadMem->dynamicBankStatus[dynamicBankIndex] = 1;
    strncpy((char *)__dest,sndFileName,0x1f);
    strncpy((pAVar1->dynamicBankLoadInfo).smpFileName,smpFileName,0x1f);
    (pAVar1->dynamicBankLoadInfo).dynamicBankIndex = dynamicBankIndex;
    (pAVar1->dynamicBankLoadInfo).loadOption = loadOption;
    (pAVar1->dynamicBankLoadInfo).flags = 0;
    *(TDRFuncPtr_aadLoadDynamicSoundBank4retProc *)&(pAVar1->dynamicBankLoadInfo).userCallbackProc =
         retProc;
    (*aadMem->nonBlockLoadProc)
              (sndFileName,aadLoadDynamicSoundBankReturn,__dest,0,
               aadMem->dynamicSoundBankData + dynamicBankIndex,4);
    puVar2 = (undefined *)0x0;
  }
  else {
    puVar2 = &DAT_00001005;
  }
  return (int)puVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSoundBankReturn(void *loadedDataPtr /*$a0*/, void *data /*$s3*/, void *data2 /*$a2*/)
 // line 669, offset 0x800528e8
	/* begin block 1 */
		// Start line: 670
		// Start offset: 0x800528E8
		// Variables:
	// 		int dynamicBankIndex; // $s1
	// 		int error; // $s0
	/* end block 1 */
	// End offset: 0x8005299C
	// End Line: 737

	/* begin block 2 */
		// Start line: 1581
	/* end block 2 */
	// End Line: 1582

void aadLoadDynamicSoundBankReturn(void *loadedDataPtr,void *data,void *data2)

{
  ulong *puVar1;
  AadMemoryStruct *pAVar2;
  uint uVar3;
  uint dynamicBankIndex;
  
  dynamicBankIndex = *(uint *)((int)data + 0x40);
  uVar3 = aadOpenDynamicSoundBank((uchar *)loadedDataPtr,dynamicBankIndex);
  pAVar2 = aadMem;
  if (uVar3 == 0) {
    (*aadMem->nonBlockBufferedLoadProc)((int)data + 0x20,aadLoadDynamicSoundBankReturn2,data,0);
  }
  else {
    puVar1 = &aadMem->updateCounter;
    (puVar1 + dynamicBankIndex)[0x140] = uVar3 & 0xff | 0x80;
    if ((puVar1 + dynamicBankIndex)[0x142] != 0) {
      (*pAVar2->memoryFreeProc)();
      aadMem->dynamicSoundBankData[dynamicBankIndex] = (_func_43 *)0x0;
    }
    if (*(code **)((int)data + 0x48) != (code *)0x0) {
      (**(code **)((int)data + 0x48))(dynamicBankIndex & 0xffff,uVar3);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSoundBankReturn2(void *loadedDataPtr /*$a0*/, long loadedDataSize /*$s2*/, short status /*$s5*/, void *data1 /*$a3*/, void *data2 /*stack 16*/)
 // line 747, offset 0x800529b8
	/* begin block 1 */
		// Start line: 748
		// Start offset: 0x800529B8
		// Variables:
	// 		unsigned char *dataPtr; // $s1
	// 		struct AadDynamicBankLoadInfo *info; // $s0
	// 		int dynamicBankIndex; // $s3
	// 		int error; // $v0

		/* begin block 1.1 */
			// Start line: 831
			// Start offset: 0x80052B2C
			// Variables:
		// 		int i; // $a2
		/* end block 1.1 */
		// End offset: 0x80052BC0
		// End Line: 845
	/* end block 1 */
	// End offset: 0x80052BC0
	// End Line: 847

	/* begin block 2 */
		// Start line: 1739
	/* end block 2 */
	// End Line: 1740

void aadLoadDynamicSoundBankReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  AadMemoryStruct *pAVar1;
  ulong uVar2;
  int iVar3;
  ulong *puVar4;
  uint uVar5;
  code *pcVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  
  uVar5 = (uint)(ushort)status << 0x10;
  iVar9 = (int)uVar5 >> 0x10;
  uVar8 = *(uint *)((int)data1 + 0x40);
  if (iVar9 < 0x100) {
    if ((*(uint *)((int)data1 + 0x54) & 1) == 0) {
      puVar7 = (undefined4 *)((int)loadedDataPtr + 4);
      *(uint *)((int)data1 + 0x54) = *(uint *)((int)data1 + 0x54) | 1;
      loadedDataPtr = (void *)((int)loadedDataPtr + 8);
      loadedDataSize = loadedDataSize - 8;
      *(undefined4 *)((int)data1 + 0x4c) = *puVar7;
      if ((*(int *)((int)data1 + 0x44) == 0) || (*(int *)((int)data1 + 0x44) != 1)) {
        *(undefined4 *)((int)data1 + 0x50) = 0x49ed0;
      }
      else {
        uVar2 = aadGetReverbSize();
        *(int *)((int)data1 + 0x50) = (0x80000 - *(int *)((int)data1 + 0x4c)) - uVar2;
      }
      aadMem->dynamicSoundBankSramData[uVar8] = *(ulong *)((int)data1 + 0x50);
    }
    aadWaitForSramTransferComplete();
    SpuSetTransferStartAddr(*(uint *)((int)data1 + 0x50));
    SpuWrite((word *)loadedDataPtr,loadedDataSize,uVar5);
    *(int *)((int)data1 + 0x50) = *(int *)((int)data1 + 0x50) + loadedDataSize;
    if (status != 1) {
      return;
    }
    iVar9 = 0;
    if (0 < *(int *)(aadMem->dynamicSoundBankHdr[uVar8] + 0x14)) {
      puVar4 = &aadMem->updateCounter + uVar8;
      iVar3 = 0;
      do {
        *(int *)(puVar4[0x13a] + iVar3) = *(int *)(puVar4[0x13a] + iVar3) + puVar4[0x144];
        iVar9 = iVar9 + 1;
        iVar3 = iVar9 * 4;
      } while (iVar9 < *(int *)(puVar4[0x134] + 0x14));
    }
    aadMem->dynamicBankStatus[uVar8] = 2;
    pcVar6 = *(code **)((int)data1 + 0x48);
    uVar8 = uVar8 & 0xffff;
    if (pcVar6 == (code *)0x0) {
      return;
    }
    iVar9 = 0;
  }
  else {
    if ((*(uint *)((int)data1 + 0x54) & 2) != 0) {
      return;
    }
    *(uint *)((int)data1 + 0x54) = *(uint *)((int)data1 + 0x54) | 2;
    pAVar1 = aadMem;
    puVar4 = &aadMem->updateCounter;
    (puVar4 + uVar8)[0x140] = uVar5 >> 0x18 | 0x80;
    if ((puVar4 + uVar8)[0x142] != 0) {
      (*pAVar1->memoryFreeProc)();
      aadMem->dynamicSoundBankData[uVar8] = (_func_43 *)0x0;
    }
    pcVar6 = *(code **)((int)data1 + 0x48);
    if (pcVar6 == (code *)0x0) {
      return;
    }
  }
  (*pcVar6)(uVar8,iVar9);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadFreeDynamicSoundBank(int dynamicBankIndex /*$a0*/)
 // line 865, offset 0x80052be4
	/* begin block 1 */
		// Start line: 2007
	/* end block 1 */
	// End Line: 2008

int aadFreeDynamicSoundBank(int dynamicBankIndex)

{
  AadMemoryStruct *pAVar1;
  undefined *puVar2;
  ulong *puVar3;
  
  pAVar1 = aadMem;
  if (dynamicBankIndex < 2) {
    puVar3 = &aadMem->updateCounter + dynamicBankIndex;
    puVar2 = &DAT_00001007;
    if ((puVar3[0x140] == 2) && (puVar2 = &DAT_00001007, puVar3[0x142] != 0)) {
      puVar3[0x140] = 0;
      (*pAVar1->memoryFreeProc)(puVar3[0x142]);
      puVar2 = (undefined *)0x0;
      aadMem->dynamicSoundBankData[dynamicBankIndex] = (_func_43 *)0x0;
    }
  }
  else {
    puVar2 = &DAT_00001005;
  }
  return (int)puVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadOpenDynamicSoundBank(unsigned char *soundBank /*$a0*/, int dynamicBankIndex /*$s1*/)
 // line 895, offset 0x80052c60
	/* begin block 1 */
		// Start line: 896
		// Start offset: 0x80052C60
		// Variables:
	// 		struct AadSoundBankHdr *soundBankHdr; // $s0
	// 		struct AadProgramAtr *programAtr; // $v0
	// 		struct AadToneAtr *toneAtr; // $v0
	// 		unsigned long *waveAddr; // $v0
	// 		unsigned long *sequenceOffsetTbl; // $a0
	// 		unsigned long *sequenceLabelOffsetTbl; // $a1
	// 		unsigned char *sequenceBase; // $a3
	// 		int i; // $t2
	/* end block 1 */
	// End offset: 0x80052D6C
	// End Line: 944

	/* begin block 2 */
		// Start line: 2074
	/* end block 2 */
	// End Line: 2075

int aadOpenDynamicSoundBank(uchar *soundBank,int dynamicBankIndex)

{
  undefined *puVar1;
  ulong uVar2;
  uchar *puVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (dynamicBankIndex < 2) {
    uVar2 = aadCreateFourCharID('a','S','N','D');
    puVar1 = &DAT_00001001;
    if ((*(ulong *)soundBank == uVar2) && (puVar1 = &DAT_00001002, *(int *)(soundBank + 8) == 0x106)
       ) {
      iVar12 = 0;
      iVar5 = *(int *)(soundBank + 0xc);
      iVar9 = *(int *)(soundBank + 0x10);
      iVar10 = *(int *)(soundBank + 0x14);
      iVar6 = *(int *)(soundBank + 0x18);
      iVar11 = *(int *)(soundBank + 0x1c);
      puVar4 = &aadMem->updateCounter + dynamicBankIndex;
      puVar3 = soundBank + *(int *)(soundBank + 4);
      *(uchar **)(puVar4 + 0x136) = puVar3;
      puVar3 = puVar3 + iVar5 * 8;
      *(uchar **)(puVar4 + 0x138) = puVar3;
      piVar8 = (int *)(puVar3 + iVar9 * 0x10 + iVar10 * 4);
      piVar7 = piVar8 + iVar6;
      *(uchar **)(puVar4 + 0x134) = soundBank;
      *(uchar **)(puVar4 + 0x13a) = puVar3 + iVar9 * 0x10;
      *(int **)(puVar4 + 0x13c) = piVar8;
      *(int **)(puVar4 + 0x13e) = piVar7;
      if (0 < *(int *)(soundBank + 0x18)) {
        do {
          *(int *)(puVar4[0x13c] + iVar12 * 4) = (int)piVar7 + *piVar8 + iVar11 * 4;
          iVar12 = iVar12 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar12 < *(int *)(soundBank + 0x18));
      }
      puVar1 = (undefined *)0x0;
    }
  }
  else {
    puVar1 = &DAT_00001005;
  }
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadLoadDynamicSfx(char *fileName /*$a3*/, long directoryID /*$a1*/, long flags /*$a2*/)
 // line 961, offset 0x80052d80
	/* begin block 1 */
		// Start line: 962
		// Start offset: 0x80052D80
		// Variables:
	// 		struct AadDynamicLoadRequest *loadReq; // $s0
	/* end block 1 */
	// End offset: 0x80052E24
	// End Line: 985

	/* begin block 2 */
		// Start line: 2278
	/* end block 2 */
	// End Line: 2279

int aadLoadDynamicSfx(char *fileName,long directoryID,long flags)

{
  int *piVar1;
  AadMemoryStruct *pAVar2;
  int iVar3;
  uint uVar4;
  AadDynamicLoadRequest *pAVar5;
  
  pAVar2 = aadMem;
  iVar3 = 0;
  if (aadMem->numLoadReqsQueued < 0x10) {
    pAVar5 = aadMem->loadRequestQueue + aadMem->nextLoadReqIn;
    pAVar5->type = 0;
    uVar4 = pAVar2->nextFileHandle;
    pAVar5->handle = uVar4 & 0x3fff | 0x4000;
    pAVar2->nextFileHandle = uVar4 + 1;
    pAVar5->directoryID = directoryID;
    pAVar5->flags = flags;
    strncpy(pAVar5->fileName,fileName,0xb);
    pAVar2 = aadMem;
    piVar1 = &aadMem->numLoadReqsQueued;
    aadMem->nextLoadReqIn = aadMem->nextLoadReqIn + 1U & 0xf;
    pAVar2->numLoadReqsQueued = *piVar1 + 1;
    iVar3 = pAVar5->handle;
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadFreeDynamicSfx(int handle /*$a0*/)
 // line 990, offset 0x80052e34
	/* begin block 1 */
		// Start line: 992
		// Start offset: 0x80052E34
		// Variables:
	// 		struct AadDynamicLoadRequest *loadReq; // $v0
	/* end block 1 */
	// End offset: 0x80052E9C
	// End Line: 1006

	/* begin block 2 */
		// Start line: 2362
	/* end block 2 */
	// End Line: 2363

	/* begin block 3 */
		// Start line: 2363
	/* end block 3 */
	// End Line: 2364

	/* begin block 4 */
		// Start line: 2367
	/* end block 4 */
	// End Line: 2368

int aadFreeDynamicSfx(int handle)

{
  AadDynamicLoadRequest *pAVar1;
  AadMemoryStruct *pAVar2;
  int iVar3;
  
  pAVar2 = aadMem;
  if (aadMem->numLoadReqsQueued < 0x10) {
    iVar3 = aadMem->nextLoadReqIn;
    pAVar1 = aadMem->loadRequestQueue;
    pAVar1[iVar3].type = 1;
    pAVar1[iVar3].handle = handle;
    pAVar2->nextLoadReqIn = pAVar2->nextLoadReqIn + 1U & 0xf;
    pAVar2->numLoadReqsQueued = pAVar2->numLoadReqsQueued + 1;
    return 0;
  }
  return (int)&DAT_0000100f;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadRelocateMusicMemoryBegin()
 // line 1049, offset 0x80052ea4
	/* begin block 1 */
		// Start line: 2492
	/* end block 1 */
	// End Line: 2493

	/* begin block 2 */
		// Start line: 2494
	/* end block 2 */
	// End Line: 2495

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadRelocateMusicMemoryBegin(void)

{
  aadMem->flags = aadMem->flags | 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadRelocateMusicMemoryEnd(void *oldAddress /*$v1*/, int offset /*$a1*/)
 // line 1057, offset 0x80052ec0
	/* begin block 1 */
		// Start line: 1058
		// Start offset: 0x80052EC0
		// Variables:
	// 		int bank; // $t6

		/* begin block 1.1 */
			// Start line: 1066
			// Start offset: 0x80052EE0
			// Variables:
		// 		int slotNumber; // $t4
		// 		int i; // $a2
		// 		struct AadSoundBankHdr *bankHdr; // $a0

			/* begin block 1.1.1 */
				// Start line: 1085
				// Start offset: 0x80052F88
				// Variables:
			// 		struct _AadSequenceSlot *slot; // $t2

				/* begin block 1.1.1.1 */
					// Start line: 1088
					// Start offset: 0x80052FB0
					// Variables:
				// 		int track; // $t0
				/* end block 1.1.1.1 */
				// End offset: 0x80053024
				// End Line: 1104
			/* end block 1.1.1 */
			// End offset: 0x80053024
			// End Line: 1105
		/* end block 1.1 */
		// End offset: 0x80053040
		// End Line: 1108
	/* end block 1 */
	// End offset: 0x80053050
	// End Line: 1111

	/* begin block 2 */
		// Start line: 2508
	/* end block 2 */
	// End Line: 2509

void aadRelocateMusicMemoryEnd(void *oldAddress,int offset)

{
  AadMemoryStruct *pAVar1;
  _func_37 *p_Var2;
  int iVar3;
  int iVar4;
  int iVar5;
  AadMemoryStruct *pAVar6;
  _func_36 *p_Var7;
  int iVar8;
  _func_36 *p_Var9;
  int iVar10;
  int iVar11;
  
  pAVar1 = aadMem;
  iVar11 = 0;
  pAVar6 = aadMem;
  while ((_func_43 *)oldAddress != pAVar6->dynamicSoundBankData[0]) {
    iVar11 = iVar11 + 1;
    pAVar6 = (AadMemoryStruct *)&pAVar6->numSlots;
    if (1 < iVar11) goto LAB_80053050;
  }
  pAVar6->dynamicSoundBankData[0] = (_func_43 *)((int)oldAddress + offset);
  pAVar6->dynamicProgramAtr[0] = pAVar6->dynamicProgramAtr[0] + offset;
  pAVar6->dynamicToneAtr[0] = pAVar6->dynamicToneAtr[0] + offset;
  p_Var2 = pAVar6->dynamicSoundBankHdr[0] + offset;
  pAVar6->dynamicSoundBankHdr[0] = p_Var2;
  pAVar6->dynamicWaveAddr[0] = pAVar6->dynamicWaveAddr[0] + offset;
  pAVar6->dynamicSequenceAddressTbl[0] =
       (_func_41 **)((int)pAVar6->dynamicSequenceAddressTbl[0] + offset);
  iVar4 = 0;
  if (0 < *(int *)(p_Var2 + 0x18)) {
    do {
      pAVar6->dynamicSequenceAddressTbl[0][iVar4] =
           pAVar6->dynamicSequenceAddressTbl[0][iVar4] + offset;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(p_Var2 + 0x18));
  }
  pAVar6->dynamicSequenceLabelOffsetTbl[0] = pAVar6->dynamicSequenceLabelOffsetTbl[0] + offset;
  iVar4 = 0;
  pAVar6 = pAVar1;
  if (0 < pAVar1->numSlots) {
    do {
      p_Var9 = pAVar6->sequenceSlots[0];
      if ((p_Var9[0x53e] != (_func_36)0xff) && (*(int *)(p_Var9 + 0x55c) == iVar11)) {
        iVar8 = 0;
        iVar10 = 0;
        p_Var7 = p_Var9;
        do {
          if (*(int *)(p_Var7 + 0x348) != 0) {
            *(int *)(p_Var7 + 0x348) = *(int *)(p_Var7 + 0x348) + offset;
            iVar5 = 0;
            iVar3 = iVar10;
            if ((p_Var9 + iVar8)[0x4e8] != (_func_36)0x0) {
              do {
                *(int *)(p_Var9 + iVar3 + 1000) = *(int *)(p_Var9 + iVar3 + 1000) + offset;
                iVar5 = iVar5 + 1;
                iVar3 = iVar3 + 0x40;
              } while (iVar5 < (int)(uint)(byte)(p_Var9 + iVar8)[0x4e8]);
            }
          }
          iVar10 = iVar10 + 4;
          iVar8 = iVar8 + 1;
          p_Var7 = p_Var7 + 4;
        } while (iVar8 < 0x10);
      }
      iVar4 = iVar4 + 1;
      pAVar6 = (AadMemoryStruct *)&pAVar6->numSlots;
    } while (iVar4 < pAVar1->numSlots);
  }
LAB_80053050:
  aadMem->flags = aadMem->flags & 0xfffffffd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadRelocateSfxMemory(void *oldAddress /*$a0*/, int offset /*$a1*/)
 // line 1123, offset 0x8005306c
	/* begin block 1 */
		// Start line: 1125
		// Start offset: 0x8005306C
		// Variables:
	// 		struct _AadDynSfxFileHdr *snfFile; // $v1
	/* end block 1 */
	// End offset: 0x800530CC
	// End Line: 1162

	/* begin block 2 */
		// Start line: 2727
	/* end block 2 */
	// End Line: 2728

	/* begin block 3 */
		// Start line: 2728
	/* end block 3 */
	// End Line: 2729

	/* begin block 4 */
		// Start line: 2733
	/* end block 4 */
	// End Line: 2734

void aadRelocateSfxMemory(void *oldAddress,int offset)

{
  _AadDynSfxFileHdr *p_Var1;
  
  p_Var1 = aadMem->firstDynSfxFile;
  if ((_AadDynSfxFileHdr *)oldAddress == p_Var1) {
    p_Var1 = (_AadDynSfxFileHdr *)((int)&p_Var1->snfID + offset);
    aadMem->firstDynSfxFile = p_Var1;
  }
  while (p_Var1 != (_AadDynSfxFileHdr *)0x0) {
    if ((_AadDynSfxFileHdr *)oldAddress == p_Var1->prevDynSfxFile) {
      p_Var1->prevDynSfxFile = (_AadDynSfxFileHdr *)((int)oldAddress + offset);
    }
    if ((_AadDynSfxFileHdr *)oldAddress == p_Var1->nextDynSfxFile) {
      p_Var1->nextDynSfxFile = (_AadDynSfxFileHdr *)((int)oldAddress + offset);
    }
    p_Var1 = p_Var1->nextDynSfxFile;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetNumLoadsQueued()
 // line 1165, offset 0x800530d4
	/* begin block 1 */
		// Start line: 2811
	/* end block 1 */
	// End Line: 2812

	/* begin block 2 */
		// Start line: 2813
	/* end block 2 */
	// End Line: 2814

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetNumLoadsQueued(void)

{
  return aadMem->numLoadReqsQueued;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPurgeLoadQueue()
 // line 1173, offset 0x800530e8
	/* begin block 1 */
		// Start line: 2827
	/* end block 1 */
	// End Line: 2828

	/* begin block 2 */
		// Start line: 2829
	/* end block 2 */
	// End Line: 2830

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadPurgeLoadQueue(void)

{
  AadMemoryStruct *pAVar1;
  
  pAVar1 = aadMem;
  aadMem->nextLoadReqIn = 0;
  pAVar1->nextLoadReqOut = 0;
  pAVar1->numLoadReqsQueued = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadProcessLoadQueue()
 // line 1186, offset 0x80053100
	/* begin block 1 */
		// Start line: 1187
		// Start offset: 0x80053100
		// Variables:
	// 		struct AadDynamicSfxLoadInfo *info; // $s0
	// 		int i; // $a0
	// 		char *p; // $v0

		/* begin block 1.1 */
			// Start line: 1212
			// Start offset: 0x80053178
			// Variables:
		// 		struct AadDynamicLoadRequest *loadReq; // $s2

			/* begin block 1.1.1 */
				// Start line: 1223
				// Start offset: 0x800531C8
				// Variables:
			// 		char areaName[12]; // stack offset -32

				/* begin block 1.1.1.1 */
					// Start line: 1244
					// Start offset: 0x80053208
				/* end block 1.1.1.1 */
				// End offset: 0x80053208
				// End Line: 1244

				/* begin block 1.1.1.2 */
					// Start line: 1249
					// Start offset: 0x80053234
				/* end block 1.1.1.2 */
				// End offset: 0x80053264
				// End Line: 1251
			/* end block 1.1.1 */
			// End offset: 0x800532F4
			// End Line: 1271

			/* begin block 1.1.2 */
				// Start line: 1276
				// Start offset: 0x80053300
				// Variables:
			// 		int i; // $s2
			// 		struct _AadDynSfxFileHdr *snfFile; // $s1
			// 		unsigned short *sfxIDListPtr; // $v1
			/* end block 1.1.2 */
			// End offset: 0x800533D8
			// End Line: 1308
		/* end block 1.1 */
		// End offset: 0x800533D8
		// End Line: 1309
	/* end block 1 */
	// End offset: 0x80053454
	// End Line: 1329

	/* begin block 2 */
		// Start line: 2853
	/* end block 2 */
	// End Line: 2854

	/* begin block 3 */
		// Start line: 2865
	/* end block 3 */
	// End Line: 2866

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadProcessLoadQueue(void)

{
  int *piVar1;
  ulong *puVar2;
  AadMemoryStruct *pAVar3;
  char *fmt;
  long lVar4;
  AadMemoryStruct *pAVar5;
  int id;
  AadDynamicSfxLoadInfo *string;
  _AadDynSfxFileHdr *p_Var6;
  _AadDynSfxFileHdr *p_Var7;
  AadDynamicLoadRequest *pAVar8;
  char acStack32 [16];
  
  pAVar3 = aadMem;
  string = &aadMem->dynamicSfxLoadInfo;
  id = 0;
  pAVar5 = aadMem;
  if (((aadMem->dynamicSfxLoadInfo).flags & 1U) == 0) {
    do {
      id = id + 1;
      if (pAVar5->dynamicBankStatus[0] == 1) {
        return;
      }
      pAVar5 = (AadMemoryStruct *)&pAVar5->numSlots;
    } while (id < 2);
    if ((aadMem->numLoadReqsQueued == 0) || ((aadMem->sramDefragInfo).status != 0)) {
      if (gSramCheckRequest == 0) {
        if (((gDfragRequest != 0) && ((aadMem->sramDefragInfo).status == 0)) &&
           (musicLoadInProgress == 0)) {
          (aadMem->sramDefragInfo).status = 1;
          gDfragRequest = 0;
        }
      }
      else {
        gDfragRequest = aadCheckSramFragmented();
        gSramCheckRequest = 0;
      }
    }
    else {
      id = aadMem->nextLoadReqOut;
      piVar1 = &aadMem->numLoadReqsQueued;
      aadMem->nextLoadReqOut = id + 1U & 0xf;
      pAVar8 = pAVar3->loadRequestQueue + id;
      pAVar3->numLoadReqsQueued = *piVar1 + -1;
      if (pAVar8->type == 0) {
        strcpy(acStack32,pAVar8->fileName);
        fmt = strpbrk(acStack32,"0123456789");
        if (fmt != (char *)0x0) {
          *fmt = '\0';
        }
        if ((pAVar8->flags & 1U) == 0) {
          sprintf((char *)string,"\\kain2\\sfx\\object\\%s\\%s.snf");
          fmt = "\\kain2\\sfx\\object\\%s\\%s.smf";
        }
        else {
          sprintf((char *)string,"\\kain2\\area\\%s\\bin\\%s.snf");
          fmt = "\\kain2\\area\\%s\\bin\\%s.smf";
        }
        sprintf((pAVar3->dynamicSfxLoadInfo).smfFileName,fmt);
        (pAVar3->dynamicSfxLoadInfo).fileHandle = pAVar8->handle;
        (pAVar3->dynamicSfxLoadInfo).directoryID = pAVar8->directoryID;
        lVar4 = pAVar8->flags;
        id = (pAVar3->dynamicSfxLoadInfo).directoryID;
        gSramFullAlarm = 0;
        (pAVar3->dynamicSfxLoadInfo).flags = 1;
        (pAVar3->dynamicSfxLoadInfo).snfFile = (_AadDynSfxFileHdr *)0x0;
        (pAVar3->dynamicSfxLoadInfo).error = 0;
        (pAVar3->dynamicSfxLoadInfo).totalSramUsed = 0;
        (pAVar3->dynamicSfxLoadInfo).loadFlags = lVar4;
        if (id != 0) {
          LOAD_SetSearchDirectory(id);
        }
        (*aadMem->nonBlockLoadProc)
                  (string,aadLoadDynamicSfxReturn,string,0,&(pAVar3->dynamicSfxLoadInfo).snfFile,
                   0x2f);
        if ((pAVar3->dynamicSfxLoadInfo).directoryID != 0) {
          LOAD_SetSearchDirectory(0);
        }
        gSramCheckRequest = 1;
      }
      else {
        if (pAVar8->type == 1) {
          p_Var7 = pAVar3->firstDynSfxFile;
          if (p_Var7 != (_AadDynSfxFileHdr *)0x0) {
LAB_80053310:
            if ((uint)p_Var7->handle != pAVar8->handle) goto LAB_800533c8;
            id = 0;
            p_Var6 = p_Var7 + 1;
            if (p_Var7->numSfxInFile != 0) {
              do {
                puVar2 = &p_Var6->snfID;
                p_Var6 = (_AadDynSfxFileHdr *)((int)&p_Var6->snfID + 2);
                aadFreeSingleDynSfx((uint)*(ushort *)puVar2);
                id = id + 1;
              } while (id < (int)(uint)p_Var7->numSfxInFile);
            }
            if (p_Var7->prevDynSfxFile == (_AadDynSfxFileHdr *)0x0) {
              aadMem->firstDynSfxFile = p_Var7->nextDynSfxFile;
            }
            else {
              p_Var7->prevDynSfxFile->nextDynSfxFile = p_Var7->nextDynSfxFile;
            }
            if (p_Var7->nextDynSfxFile != (_AadDynSfxFileHdr *)0x0) {
              p_Var7->nextDynSfxFile->prevDynSfxFile = p_Var7->prevDynSfxFile;
            }
            (*aadMem->memoryFreeProc)(p_Var7);
            gSramFullAlarm = 0;
          }
LAB_800533d8:
          gSramCheckRequest = 1;
        }
      }
    }
    aadProcessSramDefrag();
  }
  return;
LAB_800533c8:
  p_Var7 = p_Var7->nextDynSfxFile;
  if (p_Var7 == (_AadDynSfxFileHdr *)0x0) goto LAB_800533d8;
  goto LAB_80053310;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info /*$s0*/, int error /*$a1*/)
 // line 1332, offset 0x8005346c
	/* begin block 1 */
		// Start line: 3179
	/* end block 1 */
	// End Line: 3180

void aadLoadDynamicSfxAbort(AadDynamicSfxLoadInfo *info,int error)

{
  _AadDynSfxFileHdr *p_Var1;
  
  if (info->snfFile != (_AadDynSfxFileHdr *)0x0) {
    if ((info->flags & 2U) != 0) {
      p_Var1 = info->snfFile->prevDynSfxFile;
      if (p_Var1 == (_AadDynSfxFileHdr *)0x0) {
        aadMem->firstDynSfxFile = (_AadDynSfxFileHdr *)0x0;
      }
      else {
        p_Var1->nextDynSfxFile = (_AadDynSfxFileHdr *)0x0;
      }
    }
    (*aadMem->memoryFreeProc)(info->snfFile);
  }
  info->flags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo *info /*$a0*/)
 // line 1358, offset 0x800534f0
	/* begin block 1 */
		// Start line: 3231
	/* end block 1 */
	// End Line: 3232

	/* begin block 2 */
		// Start line: 3233
	/* end block 2 */
	// End Line: 3234

void aadLoadDynamicSfxDone(AadDynamicSfxLoadInfo *info)

{
  info->flags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxReturn(void *loadedDataPtr /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 1373, offset 0x800534f8
	/* begin block 1 */
		// Start line: 1374
		// Start offset: 0x800534F8
		// Variables:
	// 		struct _AadDynSfxFileHdr *p; // $v1
	// 		struct AadDynamicSfxLoadInfo *info; // $s0
	/* end block 1 */
	// End offset: 0x8005365C
	// End Line: 1461

	/* begin block 2 */
		// Start line: 3261
	/* end block 2 */
	// End Line: 3262

void aadLoadDynamicSfxReturn(void *loadedDataPtr,void *data,void *data2)

{
  AadMemoryStruct *pAVar1;
  ulong uVar2;
  _AadDynSfxFileHdr *p_Var3;
  _AadDynSfxFileHdr *p_Var4;
  ulong *puVar5;
  
  puVar5 = *(ulong **)((int)data + 0x78);
  if ((puVar5 == (ulong *)0x0) || (puVar5 != (ulong *)loadedDataPtr)) {
    aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data,(int)&DAT_0000100e);
  }
  else {
    uVar2 = aadCreateFourCharID('a','S','N','F');
    pAVar1 = aadMem;
    if ((*puVar5 == uVar2) && (*(short *)(*(int *)((int)data + 0x78) + 4) == 0x100)) {
      *(undefined2 *)(*(int *)((int)data + 0x78) + 8) = *(undefined2 *)((int)data + 0x50);
      p_Var4 = pAVar1->firstDynSfxFile;
      if (p_Var4 == (_AadDynSfxFileHdr *)0x0) {
        pAVar1->firstDynSfxFile = *(_AadDynSfxFileHdr **)((int)data + 0x78);
        *(undefined4 *)(*(int *)((int)data + 0x78) + 0xc) = 0;
      }
      else {
        p_Var3 = p_Var4->nextDynSfxFile;
        while (p_Var3 != (_AadDynSfxFileHdr *)0x0) {
          p_Var4 = p_Var4->nextDynSfxFile;
          p_Var3 = p_Var4->nextDynSfxFile;
        }
        p_Var4->nextDynSfxFile = *(_AadDynSfxFileHdr **)((int)data + 0x78);
        *(_AadDynSfxFileHdr **)(*(int *)((int)data + 0x78) + 0xc) = p_Var4;
      }
      *(undefined4 *)(*(int *)((int)data + 0x78) + 0x10) = 0;
      *(undefined4 *)((int)data + 0x60) = 0;
      *(uint *)((int)data + 0x5c) = *(uint *)((int)data + 0x5c) | 2;
      if (*(int *)((int)data + 0x54) != 0) {
        LOAD_SetSearchDirectory(*(int *)((int)data + 0x54));
      }
      (*aadMem->nonBlockBufferedLoadProc)((int)data + 0x28,aadLoadDynamicSfxReturn2,data,0);
      if (*(int *)((int)data + 0x54) != 0) {
        LOAD_SetSearchDirectory(0);
      }
    }
    else {
      aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data,(int)&DAT_0000100b);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadWaveMalloc(unsigned short waveID /*$t7*/, unsigned long waveSize /*$a1*/)
 // line 1476, offset 0x80053670
	/* begin block 1 */
		// Start line: 1477
		// Start offset: 0x80053670
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $a2
	// 		struct AadNewSramBlockDesc *bestFit; // $t2
	// 		struct AadNewSramBlockDesc *next; // $a2
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $t3
	// 		int i; // $t0
	// 		int sramDescIndex; // $t1
	// 		int bestFitIndex; // $t4
	/* end block 1 */
	// End offset: 0x800538A8
	// End Line: 1577

	/* begin block 2 */
		// Start line: 3481
	/* end block 2 */
	// End Line: 3482

int aadWaveMalloc(ushort waveID,ulong waveSize)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  AadNewSramBlockDesc *pAVar6;
  int iVar7;
  uchar uVar8;
  uint uVar9;
  AadNewSramBlockDesc *pAVar10;
  AadNewSramBlockDesc *pAVar11;
  uint uVar12;
  
  pAVar10 = (AadNewSramBlockDesc *)0x0;
  uVar12 = 0xff;
  uVar9 = aadMem->firstSramBlockDescIndex;
  pAVar11 = aadMem->sramDescriptorTbl;
  pAVar6 = pAVar11 + uVar9;
  uVar5 = waveSize >> 3;
  if (pAVar6 != (AadNewSramBlockDesc *)0x0) {
    iVar7 = 0x7f;
    do {
      if (iVar7 == -1) break;
      if ((((pAVar6->waveID & 0x4000) == 0) && (uVar5 + 6 <= (uint)pAVar6->size)) &&
         ((pAVar10 == (AadNewSramBlockDesc *)0x0 ||
          (((uint)pAVar6->size - 6) - uVar5 < ((uint)pAVar10->size - 6) - uVar5)))) {
        pAVar10 = pAVar6;
        uVar12 = uVar9;
      }
      if ((char)pAVar6->nextIndex < '\0') {
        pAVar6 = (AadNewSramBlockDesc *)0x0;
      }
      else {
        uVar3 = (uint)pAVar6->nextIndex;
        pAVar6 = (AadNewSramBlockDesc *)0x0;
        if (uVar3 != uVar9) {
          pAVar6 = pAVar11 + uVar3;
          uVar9 = uVar3;
        }
      }
      iVar7 = iVar7 + -1;
    } while (pAVar6 != (AadNewSramBlockDesc *)0x0);
  }
  if (pAVar10 == (AadNewSramBlockDesc *)0x0) {
    return 0xff;
  }
  pAVar10->waveID = waveID | 0xc000;
  if (uVar5 < pAVar10->size) {
    uVar4 = (ushort)uVar5;
    if (-1 < (char)pAVar10->nextIndex) {
      pAVar6 = pAVar11 + pAVar10->nextIndex;
      if ((pAVar6->waveID & 0x4000) == 0) {
        pAVar6->address = pAVar6->address - (pAVar10->size - uVar4);
        pAVar6->size = pAVar6->size + (pAVar10->size - uVar4);
        pAVar10->size = uVar4;
        return uVar12;
      }
    }
    uVar5 = aadMem->nextSramDescIndex;
    uVar8 = (uchar)uVar5;
    pAVar6 = pAVar11 + uVar5;
    uVar2 = pAVar6->waveID;
    uVar9 = uVar5;
    while ((uVar2 & 0x8000) != 0) {
      uVar9 = uVar9 + 1 & 0x7f;
      uVar8 = (uchar)uVar9;
      if (uVar9 == uVar5) {
        return 0xff;
      }
      pAVar6 = pAVar11 + uVar9;
      uVar2 = pAVar6->waveID;
    }
    aadMem->nextSramDescIndex = aadMem->nextSramDescIndex + 8U & 0x7f;
    pAVar6->waveID = 0x8000;
    pAVar6->address = pAVar10->address + uVar4;
    uVar2 = pAVar10->size;
    pAVar6->prevIndex = (uchar)uVar12;
    pAVar6->size = uVar2 - uVar4;
    bVar1 = pAVar10->nextIndex;
    pAVar6->nextIndex = bVar1;
    if (-1 < (int)((uint)bVar1 << 0x18)) {
      pAVar11[pAVar6->nextIndex].prevIndex = uVar8;
    }
    pAVar10->size = uVar4;
    pAVar10->nextIndex = uVar8;
  }
  return uVar12;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetSramBlockAddr(int handle /*$a0*/)
 // line 1581, offset 0x800538b0
	/* begin block 1 */
		// Start line: 1583
		// Start offset: 0x800538B0
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $v1
	/* end block 1 */
	// End offset: 0x800538D4
	// End Line: 1593

	/* begin block 2 */
		// Start line: 3725
	/* end block 2 */
	// End Line: 3726

	/* begin block 3 */
		// Start line: 3726
	/* end block 3 */
	// End Line: 3727

	/* begin block 4 */
		// Start line: 3728
	/* end block 4 */
	// End Line: 3729

ulong aadGetSramBlockAddr(int handle)

{
  if (0x7f < handle) {
    return 0;
  }
  return (uint)aadMem->sramDescriptorTbl[handle].address << 3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadWaveFree(int handle /*$a0*/)
 // line 1614, offset 0x800538dc
	/* begin block 1 */
		// Start line: 1616
		// Start offset: 0x800538DC
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $a1
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $a3

		/* begin block 1.1 */
			// Start line: 1627
			// Start offset: 0x8005390C
			// Variables:
		// 		struct AadNewSramBlockDesc *next; // $a2
		/* end block 1.1 */
		// End offset: 0x80053970
		// End Line: 1636

		/* begin block 1.2 */
			// Start line: 1640
			// Start offset: 0x80053980
			// Variables:
		// 		struct AadNewSramBlockDesc *prev; // $a0
		/* end block 1.2 */
		// End offset: 0x800539E4
		// End Line: 1649
	/* end block 1 */
	// End offset: 0x800539E4
	// End Line: 1652

	/* begin block 2 */
		// Start line: 3221
	/* end block 2 */
	// End Line: 3222

	/* begin block 3 */
		// Start line: 3775
	/* end block 3 */
	// End Line: 3776

	/* begin block 4 */
		// Start line: 3778
	/* end block 4 */
	// End Line: 3779

void aadWaveFree(int handle)

{
  byte bVar1;
  AadNewSramBlockDesc *pAVar2;
  AadNewSramBlockDesc *pAVar3;
  AadNewSramBlockDesc *pAVar4;
  
  if (handle < 0x80) {
    pAVar4 = aadMem->sramDescriptorTbl;
    pAVar2 = pAVar4 + handle;
    pAVar2->waveID = 0x8000;
    if ((-1 < (char)pAVar2->nextIndex) &&
       (pAVar3 = pAVar4 + pAVar2->nextIndex, (pAVar3->waveID & 0x4000) == 0)) {
      pAVar2->size = pAVar2->size + pAVar3->size;
      bVar1 = pAVar3->nextIndex;
      pAVar3->waveID = 0;
      pAVar2->nextIndex = bVar1;
      if (-1 < (int)((uint)bVar1 << 0x18)) {
        pAVar4[pAVar2->nextIndex].prevIndex = (uchar)handle;
      }
    }
    if ((-1 < (char)pAVar2->prevIndex) &&
       (pAVar3 = pAVar4 + pAVar2->prevIndex, (pAVar3->waveID & 0x4000) == 0)) {
      pAVar3->size = pAVar3->size + pAVar2->size;
      bVar1 = pAVar2->nextIndex;
      pAVar2->waveID = 0;
      pAVar3->nextIndex = bVar1;
      if (-1 < (int)((uint)bVar1 << 0x18)) {
        pAVar4[pAVar2->nextIndex].prevIndex = pAVar2->prevIndex;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadFreeSingleDynSfx(int sfxID /*$a0*/)
 // line 1656, offset 0x800539ec
	/* begin block 1 */
		// Start line: 1657
		// Start offset: 0x800539EC
		// Variables:
	// 		int ti; // $v1
	// 		int wi; // $v1
	// 		struct AadLoadedSfxToneAttr *toneAttr; // $a1
	// 		struct AadLoadedSfxWaveAttr *waveAttr; // $v1
	/* end block 1 */
	// End offset: 0x80053AA4
	// End Line: 1682

	/* begin block 2 */
		// Start line: 3862
	/* end block 2 */
	// End Line: 3863

	/* begin block 3 */
		// Start line: 3867
	/* end block 3 */
	// End Line: 3868

void aadFreeSingleDynSfx(int sfxID)

{
  byte bVar1;
  short sVar2;
  AadMemoryStruct *pAVar3;
  ushort uVar4;
  short *psVar5;
  AadLoadedSfxToneAttr *pAVar6;
  
  sfxID = (int)&aadMem->updateCounter + sfxID;
  bVar1 = *(byte *)(sfxID + 0x808);
  if (bVar1 < 0xfe) {
    pAVar6 = aadMem->sfxToneAttrTbl + bVar1;
    uVar4 = pAVar6->referenceCount - 1;
    pAVar6->referenceCount = uVar4;
    if (uVar4 == 0) {
      *(undefined *)(sfxID + 0x808) = 0xff;
      pAVar3 = aadMem;
      if (aadMem->sfxWaveMasterList[pAVar6->waveID] < 0xfe) {
        psVar5 = (short *)(&DAT_00001608 +
                          (int)(&aadMem->updateCounter + aadMem->sfxWaveMasterList[pAVar6->waveID]))
        ;
        sVar2 = *psVar5;
        *psVar5 = sVar2 + -1;
        if ((short)(sVar2 + -1) == 0) {
          pAVar3->sfxWaveMasterList[pAVar6->waveID] = -1;
          aadWaveFree((uint)*(byte *)((int)psVar5 + 3));
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ setSramFullAlarm()
 // line 1685, offset 0x80053ab4
	/* begin block 1 */
		// Start line: 1687
		// Start offset: 0x80053AB4
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $v1
	// 		struct AadNewSramBlockDesc *sramDesc; // $a1
	// 		long totalUsed; // $t0
	// 		long totalFree; // $t1
	// 		long largestFree; // $t2
	// 		long numFreeBlocks; // $t3
	// 		long numUsedBlocks; // $a3
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80053B60
	// End Line: 1724

	/* begin block 2 */
		// Start line: 3925
	/* end block 2 */
	// End Line: 3926

	/* begin block 3 */
		// Start line: 3926
	/* end block 3 */
	// End Line: 3927

	/* begin block 4 */
		// Start line: 3940
	/* end block 4 */
	// End Line: 3941

/* WARNING: Unknown calling convention yet parameter storage is locked */

void setSramFullAlarm(void)

{
  uint uVar1;
  AadNewSramBlockDesc *pAVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = 0;
  iVar5 = 0;
  uVar6 = 0;
  gSramFreeBlocks = 0;
  gSramUsedBlocks = 0;
  pAVar2 = aadMem->sramDescriptorTbl + aadMem->firstSramBlockDescIndex;
  iVar3 = 0x80;
  do {
    if (pAVar2 == (AadNewSramBlockDesc *)0x0) break;
    if ((pAVar2->waveID & 0x4000) == 0) {
      uVar1 = (uint)pAVar2->size;
      gSramFreeBlocks = gSramFreeBlocks + 1;
      iVar5 = iVar5 + uVar1;
      if (uVar6 < uVar1) {
        uVar6 = uVar1;
      }
    }
    else {
      gSramUsedBlocks = gSramUsedBlocks + 1;
      iVar4 = iVar4 + (uint)pAVar2->size;
    }
    if ((char)pAVar2->nextIndex < '\0') {
      pAVar2 = (AadNewSramBlockDesc *)0x0;
    }
    else {
      pAVar2 = aadMem->sramDescriptorTbl + pAVar2->nextIndex;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  gSramFullAlarm = 1;
  gSramLargestFree = uVar6 << 3;
  gSramTotalUsed = iVar4 << 3;
  gSramTotalFree = iVar5 << 3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info /*$s2*/)
 // line 1741, offset 0x80053b90
	/* begin block 1 */
		// Start line: 1742
		// Start offset: 0x80053B90
		// Variables:
	// 		int i; // $a0
	// 		struct AadLoadedSfxToneAttr *toneAttr; // $a1
	// 		struct AadLoadedSfxWaveAttr *waveAttr; // $s0
	// 		struct AadDynSfxAttr *attr; // $s1
	/* end block 1 */
	// End offset: 0x80053E48
	// End Line: 1855

	/* begin block 2 */
		// Start line: 4044
	/* end block 2 */
	// End Line: 4045

	/* begin block 3 */
		// Start line: 4053
	/* end block 3 */
	// End Line: 4054

void aadLoadSingleDynSfx(AadDynamicSfxLoadInfo *info)

{
  ushort uVar1;
  AadMemoryStruct *pAVar2;
  int iVar3;
  ulong uVar4;
  uchar uVar5;
  uint uVar6;
  int iVar7;
  AadLoadedSfxToneAttr *pAVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  short *psVar13;
  AadDynSfxAttr *pAVar14;
  
  pAVar2 = aadMem;
  uVar1 = (info->attr).sfxID;
  info->waveTransferAddr = 0;
  iVar3 = (int)&pAVar2->updateCounter + (uint)uVar1;
  pAVar14 = &info->attr;
  if (*(char *)(iVar3 + 0x808) == -2) {
    *(undefined *)(iVar3 + 0x808) = 0xff;
  }
  pAVar2 = aadMem;
  if (aadMem->sfxToneMasterList[(info->attr).sfxID] == 0xff) {
    _uVar5 = aadMem->nextToneIndex;
    uVar5 = (uchar)_uVar5;
    pAVar8 = aadMem->sfxToneAttrTbl + _uVar5;
    uVar1 = pAVar8->referenceCount;
    uVar6 = _uVar5;
    while (uVar1 != 0) {
      uVar6 = uVar6 + 1 & 0x7f;
      uVar5 = (uchar)uVar6;
      if (uVar6 == _uVar5) {
        info->smfLoadingState = 2;
        iVar3 = (int)&pAVar2->updateCounter + (uint)pAVar14->sfxID;
        goto LAB_80053e3c;
      }
      pAVar8 = aadMem->sfxToneAttrTbl + uVar6;
      uVar1 = pAVar8->referenceCount;
    }
    aadMem->nextToneIndex = aadMem->nextToneIndex + 8U & 0x7f;
    pAVar8->referenceCount = 1;
    pAVar8->waveID = (info->attr).waveID;
    pAVar2 = aadMem;
    uVar10 = *(undefined4 *)&(info->attr).toneAttr.centerNote;
    uVar11 = *(undefined4 *)&(info->attr).toneAttr.mode;
    uVar12 = *(undefined4 *)&(info->attr).toneAttr.adsr2;
    *(undefined4 *)&pAVar8->toneAttr = *(undefined4 *)&(info->attr).toneAttr;
    *(undefined4 *)&(pAVar8->toneAttr).centerNote = uVar10;
    *(undefined4 *)&(pAVar8->toneAttr).mode = uVar11;
    *(undefined4 *)&(pAVar8->toneAttr).adsr2 = uVar12;
    pAVar2->sfxToneMasterList[pAVar14->sfxID] = uVar5;
    pAVar2 = aadMem;
    if (aadMem->sfxWaveMasterList[(info->attr).waveID] == 0xff) {
      iVar3 = aadMem->nextWaveIndex;
      do {
        psVar13 = (short *)(&DAT_00001608 + (int)(&aadMem->updateCounter + iVar3));
        iVar7 = iVar3 + 1;
        if (*psVar13 == 0) {
          iVar9 = aadMem->nextWaveIndex;
          iVar7 = iVar9 + 8;
          aadMem->nextWaveIndex = iVar7;
          if (0x77 < iVar7) {
            pAVar2->nextWaveIndex = iVar9 + -0x70;
          }
          *psVar13 = 1;
          aadMem->sfxWaveMasterList[(info->attr).waveID] = (uchar)iVar3;
          iVar3 = aadWaveMalloc((info->attr).waveID,(info->attr).waveSize);
          *(undefined *)((int)psVar13 + 3) = (char)iVar3;
          if (-1 < iVar3 << 0x18) {
            uVar4 = aadGetSramBlockAddr((uint)*(byte *)((int)psVar13 + 3));
            info->waveTransferAddr = uVar4;
            info->smfLoadingState = 3;
            return;
          }
          break;
        }
        if (0x77 < iVar7) {
          iVar7 = 0;
        }
        iVar3 = iVar7;
      } while (iVar7 != aadMem->nextWaveIndex);
      aadFreeSingleDynSfx((uint)pAVar14->sfxID);
      info->smfLoadingState = 2;
      iVar3 = (int)&aadMem->updateCounter + (uint)pAVar14->sfxID;
LAB_80053e3c:
      *(undefined *)(iVar3 + 0x808) = 0xfe;
      setSramFullAlarm();
      return;
    }
    *(short *)(&DAT_00001608 +
              (int)(&aadMem->updateCounter + aadMem->sfxWaveMasterList[(info->attr).waveID])) =
         *(short *)(&DAT_00001608 +
                   (int)(&aadMem->updateCounter + aadMem->sfxWaveMasterList[(info->attr).waveID])) +
         1;
  }
  else {
    aadMem->sfxToneAttrTbl[aadMem->sfxToneMasterList[(info->attr).sfxID]].referenceCount =
         aadMem->sfxToneAttrTbl[aadMem->sfxToneMasterList[(info->attr).sfxID]].referenceCount + 1;
  }
  info->smfLoadingState = 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HackCallback()
 // line 1870, offset 0x80053e60
	/* begin block 1 */
		// Start line: 4378
	/* end block 1 */
	// End Line: 4379

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HackCallback(void)

{
  SpuSetTransferCallback(0);
  aadLoadDynamicSfxReturn2(smfDataPtr,smfBytesLeft,0,smfInfo,(void *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxReturn2(void *loadedDataPtr /*$a0*/, long loadedDataSize /*$a1*/, short status /*$a2*/, void *data1 /*$a3*/, void *data2 /*stack 16*/)
 // line 1879, offset 0x80053e98
	/* begin block 1 */
		// Start line: 1880
		// Start offset: 0x80053E98
		// Variables:
	// 		unsigned char *dataPtr; // $s4
	// 		unsigned long dataOffset; // $s3
	// 		unsigned long bytesRemaining; // $s2
	// 		struct AadDynamicSfxLoadInfo *info; // $s1
	// 		unsigned long n; // $s0
	/* end block 1 */
	// End offset: 0x80054138
	// End Line: 2032

	/* begin block 2 */
		// Start line: 4396
	/* end block 2 */
	// End Line: 4397

void aadLoadDynamicSfxReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  ulong uVar1;
  uint __n;
  int iVar2;
  void *__src;
  undefined2 in_register_0000001a;
  size_t sVar3;
  int iVar4;
  
  sVar3 = CONCAT22(in_register_0000001a,status);
  iVar4 = 0;
  if (loadedDataSize != 0) {
    do {
      iVar2 = *(int *)((int)data1 + 0x60);
      if (iVar2 == 1) {
        __src = (void *)((int)loadedDataPtr + iVar4);
        __n = *(uint *)((int)data1 + 100);
        if ((uint)loadedDataSize < *(uint *)((int)data1 + 100)) {
          __n = loadedDataSize;
        }
        iVar4 = iVar4 + __n;
        sVar3 = __n;
        memcpy((void *)((int)data1 - (*(int *)((int)data1 + 100) + -0x94)),__src,__n);
        loadedDataSize = loadedDataSize - __n;
        iVar2 = *(int *)((int)data1 + 100) - __n;
        *(int *)((int)data1 + 100) = iVar2;
        if (iVar2 == 0) {
          aadLoadSingleDynSfx((AadDynamicSfxLoadInfo *)data1);
          *(undefined4 *)((int)data1 + 100) = *(undefined4 *)((int)data1 + 0x90);
        }
      }
      else {
        if (iVar2 < 2) {
          if (iVar2 == 0) {
            sVar3 = 0x4d;
            uVar1 = aadCreateFourCharID('a','S','M','F');
            if (*(ulong *)loadedDataPtr != uVar1) {
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,(int)&DAT_0000100b);
              return;
            }
            if (*(short *)((int)loadedDataPtr + 4) != 0x100) {
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,(int)&DAT_0000100c);
              return;
            }
            if (*(short *)((int)loadedDataPtr + 6) != *(short *)(*(int *)((int)data1 + 0x78) + 6)) {
LAB_80053f98:
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,(int)&DAT_0000100d);
              return;
            }
            __n = (uint)*(ushort *)(*(int *)((int)data1 + 0x78) + 10);
            iVar4 = iVar4 + 0x10;
            if ((uint)*(ushort *)((int)loadedDataPtr + 8) != __n) goto LAB_80053f98;
            loadedDataSize = loadedDataSize - 0x10;
            *(undefined4 *)((int)data1 + 0x60) = 1;
            *(undefined4 *)((int)data1 + 100) = 0x18;
            *(uint *)((int)data1 + 0x68) = __n;
          }
        }
        else {
          if (iVar2 == 2) {
            __n = *(uint *)((int)data1 + 100);
            if ((uint)loadedDataSize < *(uint *)((int)data1 + 100)) {
              __n = loadedDataSize;
            }
            iVar4 = iVar4 + __n;
            loadedDataSize = loadedDataSize - __n;
            iVar2 = *(int *)((int)data1 + 100) - __n;
            *(int *)((int)data1 + 100) = iVar2;
            if (iVar2 == 0) {
              iVar2 = *(int *)((int)data1 + 0x68) + -1;
              *(int *)((int)data1 + 0x68) = iVar2;
              if (iVar2 == 0) {
LAB_800540f4:
                aadLoadDynamicSfxDone((AadDynamicSfxLoadInfo *)data1);
                return;
              }
              *(undefined4 *)((int)data1 + 0x60) = 1;
              *(undefined4 *)((int)data1 + 100) = 0x18;
            }
          }
          else {
            if (iVar2 == 3) {
              __n = *(uint *)((int)data1 + 100);
              if ((uint)loadedDataSize < *(uint *)((int)data1 + 100)) {
                __n = loadedDataSize;
              }
              loadedDataSize = loadedDataSize - __n;
              aadWaitForSramTransferComplete();
              SpuSetTransferCallback((int)HackCallback);
              SpuSetTransferStartAddr(*(uint *)((int)data1 + 0x70));
              SpuWrite((word *)((int)loadedDataPtr + iVar4),__n,sVar3);
              iVar4 = iVar4 + __n;
              iVar2 = *(int *)((int)data1 + 100) - __n;
              *(int *)((int)data1 + 0x70) = *(int *)((int)data1 + 0x70) + __n;
              *(int *)((int)data1 + 100) = iVar2;
              if (iVar2 == 0) {
                iVar2 = *(int *)((int)data1 + 0x68) + -1;
                *(int *)((int)data1 + 0x74) =
                     *(int *)((int)data1 + 0x74) + *(int *)((int)data1 + 0x90);
                *(int *)((int)data1 + 0x68) = iVar2;
                if (iVar2 == 0) {
                  SpuSetTransferCallback(0);
                  goto LAB_800540f4;
                }
                *(undefined4 *)((int)data1 + 0x60) = 1;
                *(undefined4 *)((int)data1 + 100) = 0x18;
              }
              if (loadedDataSize != 0) {
                smfDataPtr = (uchar *)((int)loadedDataPtr + iVar4);
                smfBytesLeft = loadedDataSize;
                smfInfo = (AadDynamicSfxLoadInfo *)data1;
                return;
              }
              SpuSetTransferCallback(0);
            }
          }
        }
      }
    } while (loadedDataSize != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadCheckSramFragmented()
 // line 2084, offset 0x80054160
	/* begin block 1 */
		// Start line: 2086
		// Start offset: 0x80054160
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $v1
	// 		struct AadNewSramBlockDesc *sramDesc; // $a1
	// 		long totalFree; // $t0
	// 		long smallestFree; // $t1
	// 		long numFreeBlocks; // $a3
	// 		int i; // $a2
	// 		int defragNeeded; // $v1
	/* end block 1 */
	// End offset: 0x8005420C
	// End Line: 2128

	/* begin block 2 */
		// Start line: 4859
	/* end block 2 */
	// End Line: 4860

	/* begin block 3 */
		// Start line: 4860
	/* end block 3 */
	// End Line: 4861

	/* begin block 4 */
		// Start line: 4870
	/* end block 4 */
	// End Line: 4871

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadCheckSramFragmented(void)

{
  uint uVar1;
  undefined *puVar2;
  AadNewSramBlockDesc *pAVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  
  puVar6 = (undefined *)0x0;
  puVar7 = &UNK_000f423f;
  iVar5 = 0;
  pAVar3 = aadMem->sramDescriptorTbl + aadMem->firstSramBlockDescIndex;
  iVar4 = 0x80;
  do {
    if (pAVar3 == (AadNewSramBlockDesc *)0x0) break;
    if ((pAVar3->waveID & 0x4000) == 0) {
      puVar2 = (undefined *)(uint)pAVar3->size;
      iVar5 = iVar5 + 1;
      puVar6 = puVar2 + (int)puVar6;
      if (puVar2 < puVar7) {
        puVar7 = puVar2;
      }
    }
    if ((char)pAVar3->nextIndex < '\0') {
      pAVar3 = (AadNewSramBlockDesc *)0x0;
    }
    else {
      pAVar3 = aadMem->sramDescriptorTbl + pAVar3->nextIndex;
    }
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar1 = 0;
  if (2 < iVar5) {
    uVar1 = (uint)((int)puVar7 < (int)puVar6 >> 2);
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadProcessSramDefrag()
 // line 2147, offset 0x80054214
	/* begin block 1 */
		// Start line: 2148
		// Start offset: 0x80054214
		// Variables:
	// 		struct AadSramDefragInfo *info; // $s3
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $s5
	// 		struct AadNewSramBlockDesc *firstBlock; // $s1
	// 		struct AadNewSramBlockDesc *secondBlock; // $s2
	// 		int n; // $s0
	// 		int waveID; // $a0
	// 		int firstBlockIndex; // $s4
	// 		int secondBlockIndex; // $s6

		/* begin block 1.1 */
			// Start line: 2250
			// Start offset: 0x800543DC
			// Variables:
		// 		struct AadNewSramBlockDesc *next; // $a0
		/* end block 1.1 */
		// End offset: 0x80054440
		// End Line: 2262
	/* end block 1 */
	// End offset: 0x80054540
	// End Line: 2339

	/* begin block 2 */
		// Start line: 4990
	/* end block 2 */
	// End Line: 4991

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadProcessSramDefrag(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  AadMemoryStruct *pAVar4;
  AadMemoryStruct *pAVar5;
  uchar *puVar6;
  int iVar7;
  undefined *puVar8;
  ulong uVar9;
  uint in_a2;
  undefined *puVar10;
  uint uVar11;
  AadNewSramBlockDesc *pAVar12;
  AadNewSramBlockDesc *pAVar13;
  AadSramDefragInfo *pAVar14;
  byte bVar15;
  AadNewSramBlockDesc *pAVar16;
  
  pAVar4 = aadMem;
  iVar7 = (aadMem->sramDefragInfo).status;
  pAVar14 = &aadMem->sramDefragInfo;
  if (iVar7 == 1) {
    uVar11 = aadMem->firstSramBlockDescIndex;
    pAVar16 = aadMem->sramDescriptorTbl;
    pAVar12 = pAVar16 + uVar11;
    iVar7 = 0x80;
    if (pAVar12 != (AadNewSramBlockDesc *)0x0) {
      do {
        bVar15 = (byte)uVar11;
        if ((pAVar12->waveID & 0x4000) == 0) break;
        iVar7 = iVar7 + -1;
        bVar15 = pAVar12->nextIndex;
        uVar11 = (uint)bVar15;
        if ((iVar7 == 0) || (0x7f < bVar15)) {
          pAVar12 = (AadNewSramBlockDesc *)0x0;
        }
        else {
          pAVar12 = pAVar16 + uVar11;
        }
      } while (pAVar12 != (AadNewSramBlockDesc *)0x0);
      if ((pAVar12 != (AadNewSramBlockDesc *)0x0) && (-1 < (char)pAVar12->nextIndex)) {
        bVar1 = pAVar12->nextIndex;
        pAVar13 = pAVar16 + bVar1;
        if ((pAVar13->waveID & 0x4000) != 0) {
          puVar6 = (uchar *)(*aadMem->memoryMallocProc)(0x1000,0x30);
          (pAVar4->sramDefragInfo).fragBuffer = puVar6;
          pAVar5 = aadMem;
          if (puVar6 != (uchar *)0x0) {
            uVar11 = (uint)pAVar13->waveID & 0x3fff;
            iVar7 = (int)&aadMem->updateCounter + uVar11;
            bVar2 = *(byte *)(iVar7 + 0xa08);
            (pAVar4->sramDefragInfo).masterListEntry = (uint)bVar2;
            if (bVar2 < 0xfe) {
              *(undefined *)(iVar7 + 0xa08) = 0xff;
              (pAVar4->sramDefragInfo).waveID = uVar11;
              (pAVar4->sramDefragInfo).destSramAddr = (uint)pAVar12->address << 3;
              (pAVar4->sramDefragInfo).srcSramAddr = (uint)pAVar13->address << 3;
              (pAVar4->sramDefragInfo).moveSize = (uint)pAVar13->size << 3;
              uVar3 = pAVar12->size;
              pAVar12->size = pAVar13->size;
              pAVar13->size = uVar3;
              uVar3 = pAVar12->waveID;
              pAVar12->waveID = pAVar13->waveID;
              pAVar13->waveID = uVar3;
              pAVar13->address = pAVar12->address + pAVar12->size;
              if ((-1 < (char)pAVar13->nextIndex) &&
                 (pAVar12 = pAVar16 + pAVar13->nextIndex, (pAVar12->waveID & 0x4000) == 0)) {
                pAVar13->size = pAVar13->size + pAVar12->size;
                bVar2 = pAVar12->nextIndex;
                pAVar12->waveID = 0;
                pAVar13->nextIndex = bVar2;
                if (-1 < (int)((uint)bVar2 << 0x18)) {
                  pAVar16[pAVar13->nextIndex].prevIndex = bVar1;
                }
              }
              aadMem->sfxWaveAttrTbl[(pAVar4->sramDefragInfo).masterListEntry].sramHandle = bVar15;
              pAVar14->status = 2;
              return;
            }
            (*pAVar5->memoryFreeProc)((pAVar4->sramDefragInfo).fragBuffer);
          }
        }
      }
    }
    pAVar14->status = 0;
  }
  else {
    if (1 < iVar7) {
      if (iVar7 == 2) {
        iVar7 = SpuIsTransferCompleted(0);
        if (iVar7 != 0) {
          puVar8 = (undefined *)(pAVar4->sramDefragInfo).moveSize;
          puVar10 = (undefined *)0x1000;
          if (puVar8 < &DAT_00001001) {
            puVar10 = puVar8;
          }
          SpuSetTransferStartAddr((pAVar4->sramDefragInfo).srcSramAddr);
          SpuRead((uint)(pAVar4->sramDefragInfo).fragBuffer,(uint)puVar10,in_a2);
          *(undefined **)&(pAVar4->sramDefragInfo).readSize = puVar10;
          (pAVar4->sramDefragInfo).status = 3;
        }
      }
      else {
        if ((iVar7 == 3) && (iVar7 = SpuIsTransferCompleted(0), iVar7 != 0)) {
          SpuSetTransferStartAddr((pAVar4->sramDefragInfo).destSramAddr);
          uVar11 = (pAVar4->sramDefragInfo).readSize;
          SpuWrite((word *)(pAVar4->sramDefragInfo).fragBuffer,uVar11,in_a2);
          (pAVar4->sramDefragInfo).srcSramAddr = (pAVar4->sramDefragInfo).srcSramAddr + uVar11;
          uVar9 = (pAVar4->sramDefragInfo).moveSize - uVar11;
          (pAVar4->sramDefragInfo).moveSize = uVar9;
          (pAVar4->sramDefragInfo).destSramAddr = (pAVar4->sramDefragInfo).destSramAddr + uVar11;
          if (uVar9 == 0) {
            (*aadMem->memoryFreeProc)((pAVar4->sramDefragInfo).fragBuffer);
            aadMem->sfxWaveMasterList[(pAVar4->sramDefragInfo).waveID] =
                 *(uchar *)&(pAVar4->sramDefragInfo).masterListEntry;
            (pAVar4->sramDefragInfo).status = 0;
            gSramCheckRequest = 1;
          }
          else {
            (pAVar4->sramDefragInfo).status = 2;
          }
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxLoaded(unsigned int toneID /*$a0*/)
 // line 2348, offset 0x80054568
	/* begin block 1 */
		// Start line: 4691
	/* end block 1 */
	// End Line: 4692

	/* begin block 2 */
		// Start line: 5418
	/* end block 2 */
	// End Line: 5419

int aadIsSfxLoaded(uint toneID)

{
  int iVar1;
  
  iVar1 = 1;
  if ((0xfd < aadMem->sfxToneMasterList[toneID]) &&
     (iVar1 = -1, aadMem->sfxToneMasterList[toneID] != 0xfe)) {
    return 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInitSequenceSlot(struct _AadSequenceSlot *slot /*$a2*/)
 // line 2591, offset 0x800545a4
	/* begin block 1 */
		// Start line: 2592
		// Start offset: 0x800545A4
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $t0
	// 		unsigned long trackOffset; // $v0
	// 		int i; // $a1
	// 		int bank; // $a0
	/* end block 1 */
	// End offset: 0x80054694
	// End Line: 2650

	/* begin block 2 */
		// Start line: 5670
	/* end block 2 */
	// End Line: 5671

	/* begin block 3 */
		// Start line: 5905
	/* end block 3 */
	// End Line: 5906

void aadInitSequenceSlot(_AadSequenceSlot *slot)

{
  undefined uVar1;
  int iVar2;
  _AadSequenceSlot *p_Var3;
  int iVar4;
  _func_41 *p_Var5;
  _func_41 *p_Var6;
  
  iVar4 = 0;
  slot->status = 0;
  slot->selectedDynamicBank = slot->sequenceAssignedDynamicBank;
  slot->slotFlags = slot->slotFlags & 1;
  p_Var6 = aadMem->dynamicSequenceAddressTbl[slot->sequenceAssignedDynamicBank]
           [slot->sequenceNumberAssigned];
  p_Var3 = slot;
  p_Var5 = p_Var6;
  do {
    if (iVar4 < (int)(uint)*(ushort *)(p_Var6 + 0xc)) {
      *(_func_41 **)p_Var3->sequencePosition = p_Var6 + *(int *)(p_Var5 + 0x10);
    }
    else {
      p_Var3->sequencePosition[0] = (_func_9 *)0x0;
    }
    p_Var3 = (_AadSequenceSlot *)&(p_Var3->tempo).currentError;
    iVar2 = (int)&(slot->tempo).currentTick + iVar4;
    *(undefined *)(iVar2 + 0x3d8) = 0;
    iVar4 = iVar4 + 1;
    *(undefined *)(iVar2 + 0x4e8) = 0;
    *(undefined *)(iVar2 + 0x338) = 0;
    *(undefined *)(iVar2 + 0x318) = 0;
    *(undefined *)(iVar2 + 0x328) = 0;
    *(byte *)(iVar2 + 0x3d8) = *(byte *)(iVar2 + 0x3d8) | 0x20;
    p_Var5 = p_Var5 + 4;
  } while (iVar4 < 0x10);
  iVar4 = 0;
  p_Var3 = slot;
  do {
    iVar2 = (int)&(slot->tempo).currentTick + iVar4;
    uVar1 = *(undefined *)&slot->sequenceAssignedDynamicBank;
    iVar4 = iVar4 + 1;
    *(undefined *)(iVar2 + 0x590) = 0xff;
    *(undefined *)(iVar2 + 0x5a0) = 0x7f;
    *(undefined *)(iVar2 + 0x5b0) = 0x3f;
    *(undefined *)(iVar2 + 0x560) = uVar1;
    p_Var3->pitchWheel[0] = 0x2000;
    p_Var3 = (_AadSequenceSlot *)((int)&(p_Var3->tempo).currentTick + 2);
  } while (iVar4 < 0x10);
  slot->selectedSlotPtr = slot;
  slot->delayedMuteMode = 0;
  slot->delayedMuteCmds = 0;
  slot->delayedUnMuteCmds = 0;
  slot->selectedSlotNum = slot->thisSlotNumber;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadWaitForSramTransferComplete()
 // line 2660, offset 0x800546b0
	/* begin block 1 */
		// Start line: 2661
		// Start offset: 0x800546B0
		// Variables:
	// 		int n; // $s0
	/* end block 1 */
	// End offset: 0x800546E0
	// End Line: 2668

	/* begin block 2 */
		// Start line: 6132
	/* end block 2 */
	// End Line: 6133

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadWaitForSramTransferComplete(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 100000;
  do {
    iVar1 = SpuIsTransferCompleted(0);
    if (iVar1 != 0) {
      return 1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInitReverb()
 // line 2671, offset 0x800546f0
	/* begin block 1 */
		// Start line: 6155
	/* end block 1 */
	// End Line: 6156

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadInitReverb(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint in_a2;
  
  uVar1 = aadGetReverbMode();
  SpuSetReverbModeType(uVar1);
  uVar4 = 0xffffff;
  SpuSetReverbVoice(0,0xffffff);
  iVar2 = aadWaitForSramTransferComplete();
  if (iVar2 != 0) {
    uVar1 = aadGetReverbMode();
    SpuClearReverbWorkArea(uVar1,uVar4,in_a2);
  }
  iVar2 = aadGetReverbDepth();
  iVar3 = aadGetReverbDepth();
  SpuSetReverbModeDepth((word)iVar2,(word)iVar3);
  SpuSetReverb(1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadShutdownReverb()
 // line 2687, offset 0x80054774
	/* begin block 1 */
		// Start line: 6187
	/* end block 1 */
	// End Line: 6188

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadShutdownReverb(void)

{
  int iVar1;
  uint uVar2;
  undefined4 in_a1;
  uint in_a2;
  
  iVar1 = aadWaitForSramTransferComplete();
  if (iVar1 != 0) {
    uVar2 = aadGetReverbMode();
    SpuClearReverbWorkArea(uVar2,in_a1,in_a2);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetReverbMode()
 // line 2701, offset 0x800547ac
	/* begin block 1 */
		// Start line: 6215
	/* end block 1 */
	// End Line: 6216

	/* begin block 2 */
		// Start line: 6216
	/* end block 2 */
	// End Line: 6217

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetReverbMode(void)

{
  return 3;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetReverbSize()
 // line 2723, offset 0x800547b4
	/* begin block 1 */
		// Start line: 6259
	/* end block 1 */
	// End Line: 6260

/* WARNING: Unknown calling convention yet parameter storage is locked */

ulong aadGetReverbSize(void)

{
  int iVar1;
  
  iVar1 = aadGetReverbMode();
  return (&aadReverbModeSize)[iVar1] + 0x30;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetReverbDepth()
 // line 2728, offset 0x800547e8
	/* begin block 1 */
		// Start line: 6269
	/* end block 1 */
	// End Line: 6270

	/* begin block 2 */
		// Start line: 6270
	/* end block 2 */
	// End Line: 6271

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetReverbDepth(void)

{
  return (int)&DAT_00002710;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetDynamicBankStatus(int bank /*$a0*/)
 // line 2734, offset 0x800547f0
	/* begin block 1 */
		// Start line: 6281
	/* end block 1 */
	// End Line: 6282

	/* begin block 2 */
		// Start line: 6284
	/* end block 2 */
	// End Line: 6285

int aadGetDynamicBankStatus(int bank)

{
  return aadMem->dynamicBankStatus[bank];
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetNumDynamicSequences(int bank /*$a0*/)
 // line 2741, offset 0x80054808
	/* begin block 1 */
		// Start line: 6295
	/* end block 1 */
	// End Line: 6296

	/* begin block 2 */
		// Start line: 6298
	/* end block 2 */
	// End Line: 6299

int aadGetNumDynamicSequences(int bank)

{
  int iVar1;
  
  iVar1 = 0;
  if ((&aadMem->updateCounter + bank)[0x140] == 2) {
    iVar1 = *(int *)((&aadMem->updateCounter + bank)[0x134] + 0x18);
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadAssignDynamicSequence(int bank /*$s1*/, int sequenceNumber /*$s3*/, int slotNumber /*$s2*/)
 // line 2758, offset 0x80054838
	/* begin block 1 */
		// Start line: 2759
		// Start offset: 0x80054838
		// Variables:
	// 		struct AadTempo tempo; // stack offset -32
	// 		struct _AadSequenceSlot *slot; // $s0
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x800548F8
	// End Line: 2805

	/* begin block 2 */
		// Start line: 6329
	/* end block 2 */
	// End Line: 6330

int aadAssignDynamicSequence(int bank,int sequenceNumber,int slotNumber)

{
  undefined *puVar1;
  AadTempo *tempo;
  int iVar2;
  int iVar3;
  _AadSequenceSlot *slot;
  AadTempo AStack32;
  
  if (aadMem->dynamicBankStatus[bank] == 2) {
    slot = (_AadSequenceSlot *)aadMem->sequenceSlots[slotNumber];
    slot->sequenceNumberAssigned = (uchar)sequenceNumber;
    slot->sequenceAssignedDynamicBank = bank;
    aadInitSequenceSlot(slot);
    aadAllNotesOff(slotNumber);
    if ((slot->tempo).ticksPerUpdate == 0) {
      tempo = aadGetTempoFromDynamicSequence(bank,sequenceNumber,&AStack32);
      aadSetSlotTempo(slotNumber,tempo);
    }
    iVar3 = 0xf;
    iVar2 = (int)&(slot->tempo).errorPerUpdate + 3;
    slot->channelMute = 0;
    slot->enableSustainUpdate = 0;
    slot->ignoreTranspose = 0;
    do {
      *(undefined *)(iVar2 + 0x5c0) = 0;
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + -1;
    } while (-1 < iVar3);
    puVar1 = (undefined *)0x0;
  }
  else {
    puVar1 = &DAT_00001007;
  }
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// struct AadTempo * /*$ra*/ aadGetTempoFromDynamicSequence(int bank /*$a0*/, int sequenceNumber /*$a1*/, struct AadTempo *tempo /*$a2*/)
 // line 2808, offset 0x80054914
	/* begin block 1 */
		// Start line: 2810
		// Start offset: 0x80054914
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $v1
	/* end block 1 */
	// End offset: 0x8005495C
	// End Line: 2823

	/* begin block 2 */
		// Start line: 6459
	/* end block 2 */
	// End Line: 6460

	/* begin block 3 */
		// Start line: 6460
	/* end block 3 */
	// End Line: 6461

	/* begin block 4 */
		// Start line: 6467
	/* end block 4 */
	// End Line: 6468

AadTempo * aadGetTempoFromDynamicSequence(int bank,int sequenceNumber,AadTempo *tempo)

{
  int iVar1;
  
  if ((&aadMem->updateCounter + bank)[0x140] == 2) {
    iVar1 = *(int *)((&aadMem->updateCounter + bank)[0x13c] + sequenceNumber * 4);
    tempo->quarterNoteTime = *(ulong *)(iVar1 + 4);
    tempo->ppqn = (uint)*(ushort *)(iVar1 + 8);
  }
  return tempo;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetSlotTempo(int slotNumber /*$a0*/, struct AadTempo *tempo /*$a1*/)
 // line 2942, offset 0x80054964
	/* begin block 1 */
		// Start line: 2944
		// Start offset: 0x80054964
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a0
	// 		unsigned long tickTime; // $v1
	// 		unsigned long tickTimeRemainder; // $a2
	/* end block 1 */
	// End offset: 0x80054964
	// End Line: 2950

	/* begin block 2 */
		// Start line: 6727
	/* end block 2 */
	// End Line: 6728

	/* begin block 3 */
		// Start line: 6728
	/* end block 3 */
	// End Line: 6729

	/* begin block 4 */
		// Start line: 6734
	/* end block 4 */
	// End Line: 6735

void aadSetSlotTempo(int slotNumber,AadTempo *tempo)

{
  AadMemoryStruct *pAVar1;
  uint uVar2;
  _func_36 *p_Var3;
  
  pAVar1 = aadMem;
  uVar2 = tempo->ppqn;
  p_Var3 = aadMem->sequenceSlots[slotNumber];
  uVar2 = (tempo->quarterNoteTime / uVar2) * 0x10000 +
          (tempo->quarterNoteTime % uVar2 << 0x10) / uVar2;
  *(uint *)(p_Var3 + 8) = uVar2;
  *(short *)(p_Var3 + 0x10) = (short)((&aadUpdateRate)[pAVar1->updateMode & 3] / uVar2);
  *(uint *)(p_Var3 + 0xc) = (&aadUpdateRate)[pAVar1->updateMode & 3] % *(uint *)(p_Var3 + 8);
  *(ulong *)(p_Var3 + 0x14) = tempo->quarterNoteTime;
  *(undefined2 *)(p_Var3 + 0x12) = *(undefined2 *)&tempo->ppqn;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStartSlot(int slotNumber /*$a0*/)
 // line 2963, offset 0x80054a1c
	/* begin block 1 */
		// Start line: 2964
		// Start offset: 0x80054A1C
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s0
	/* end block 1 */
	// End offset: 0x80054A88
	// End Line: 2977

	/* begin block 2 */
		// Start line: 6774
	/* end block 2 */
	// End Line: 6775

	/* begin block 3 */
		// Start line: 6777
	/* end block 3 */
	// End Line: 6778

void aadStartSlot(int slotNumber)

{
  _AadSequenceSlot *slot;
  
  if (((slotNumber < aadMem->numSlots) &&
      (slot = (_AadSequenceSlot *)aadMem->sequenceSlots[slotNumber], (slot->status & 1) == 0)) &&
     (slot->sequenceNumberAssigned != -1)) {
    aadInitSequenceSlot(slot);
    slot->status = slot->status | 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStopSlot(int slotNumber /*$s0*/)
 // line 2980, offset 0x80054a98
	/* begin block 1 */
		// Start line: 2981
		// Start offset: 0x80054A98
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a0
	/* end block 1 */
	// End offset: 0x80054AF4
	// End Line: 2995

	/* begin block 2 */
		// Start line: 6811
	/* end block 2 */
	// End Line: 6812

	/* begin block 3 */
		// Start line: 6814
	/* end block 3 */
	// End Line: 6815

void aadStopSlot(int slotNumber)

{
  _AadSequenceSlot *slot;
  
  if ((slotNumber < aadMem->numSlots) &&
     (slot = (_AadSequenceSlot *)aadMem->sequenceSlots[slotNumber],
     slot->sequenceNumberAssigned != -1)) {
    slot->status = slot->status & 0xfffe;
    aadInitSequenceSlot(slot);
    aadAllNotesOff(slotNumber);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStopAllSlots()
 // line 2998, offset 0x80054b04
	/* begin block 1 */
		// Start line: 2999
		// Start offset: 0x80054B04
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s1
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x80054B7C
	// End Line: 3013

	/* begin block 2 */
		// Start line: 6853
	/* end block 2 */
	// End Line: 6854

	/* begin block 3 */
		// Start line: 6858
	/* end block 3 */
	// End Line: 6859

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadStopAllSlots(void)

{
  int iVar1;
  int slotNumber;
  
  slotNumber = 0;
  if (0 < aadMem->numSlots) {
    iVar1 = 0;
    do {
      iVar1 = *(int *)((int)aadMem->sequenceSlots + iVar1);
      if ((*(ushort *)(iVar1 + 0x540) & 1) != 0) {
        aadStopSlot(slotNumber);
      }
      *(undefined *)(iVar1 + 0x53e) = 0xff;
      slotNumber = slotNumber + 1;
      iVar1 = slotNumber * 4;
    } while (slotNumber < aadMem->numSlots);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadDisableSlot(int slotNumber /*$a0*/)
 // line 3016, offset 0x80054b94
	/* begin block 1 */
		// Start line: 6900
	/* end block 1 */
	// End Line: 6901

	/* begin block 2 */
		// Start line: 6901
	/* end block 2 */
	// End Line: 6902

void aadDisableSlot(int slotNumber)

{
  if (slotNumber < aadMem->numSlots) {
    *(byte *)(aadMem->sequenceSlots[slotNumber] + 0x550) =
         (byte)aadMem->sequenceSlots[slotNumber][0x550] | 1;
    aadAllNotesOff(slotNumber);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadEnableSlot(int slotNumber /*$a0*/)
 // line 3027, offset 0x80054be4
	/* begin block 1 */
		// Start line: 6923
	/* end block 1 */
	// End Line: 6924

	/* begin block 2 */
		// Start line: 6924
	/* end block 2 */
	// End Line: 6925

void aadEnableSlot(int slotNumber)

{
  if (slotNumber < aadMem->numSlots) {
    *(byte *)(aadMem->sequenceSlots[slotNumber] + 0x550) =
         (byte)aadMem->sequenceSlots[slotNumber][0x550] & 0xfe;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPauseSlot(int slotNumber /*$a0*/)
 // line 3035, offset 0x80054c24
	/* begin block 1 */
		// Start line: 6939
	/* end block 1 */
	// End Line: 6940

	/* begin block 2 */
		// Start line: 6940
	/* end block 2 */
	// End Line: 6941

void aadPauseSlot(int slotNumber)

{
  if (slotNumber < aadMem->numSlots) {
    *(ushort *)(aadMem->sequenceSlots[slotNumber] + 0x540) =
         *(ushort *)(aadMem->sequenceSlots[slotNumber] + 0x540) & 0xfffe;
    aadAllNotesOff(slotNumber);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadResumeSlot(int slotNumber /*$a0*/)
 // line 3046, offset 0x80054c74
	/* begin block 1 */
		// Start line: 3048
		// Start offset: 0x80054C74
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a1
	// 		int track; // $a0
	/* end block 1 */
	// End offset: 0x80054CDC
	// End Line: 3062

	/* begin block 2 */
		// Start line: 6962
	/* end block 2 */
	// End Line: 6963

	/* begin block 3 */
		// Start line: 6963
	/* end block 3 */
	// End Line: 6964

	/* begin block 4 */
		// Start line: 6966
	/* end block 4 */
	// End Line: 6967

void aadResumeSlot(int slotNumber)

{
  _func_36 *p_Var1;
  int iVar2;
  _func_36 *p_Var3;
  
  if (slotNumber < aadMem->numSlots) {
    p_Var3 = aadMem->sequenceSlots[slotNumber];
    iVar2 = 0;
    p_Var1 = p_Var3;
    if (p_Var3[0x53e] != (_func_36)0xff) {
      do {
        iVar2 = iVar2 + 1;
        *(byte *)(p_Var1 + 0x3d8) = (byte)p_Var1[0x3d8] | 0x20;
        p_Var1 = p_Var3 + iVar2;
      } while (iVar2 < 0x10);
      *(ushort *)(p_Var3 + 0x540) = *(ushort *)(p_Var3 + 0x540) | 1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetSlotStatus(int slotNumber /*$a0*/)
 // line 3065, offset 0x80054ce4
	/* begin block 1 */
		// Start line: 7002
	/* end block 1 */
	// End Line: 7003

	/* begin block 2 */
		// Start line: 7003
	/* end block 2 */
	// End Line: 7004

int aadGetSlotStatus(int slotNumber)

{
  return (uint)*(ushort *)(aadMem->sequenceSlots[slotNumber] + 0x540);
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadAllNotesOff(int slotNumber /*$a0*/)
 // line 3091, offset 0x80054d04
	/* begin block 1 */
		// Start line: 3093
		// Start offset: 0x80054D04
		// Variables:
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned long vmask; // $a1
	// 		int i; // $a3
	// 		struct _AadSequenceSlot *slot; // $t0
	/* end block 1 */
	// End offset: 0x80054D9C
	// End Line: 3116

	/* begin block 2 */
		// Start line: 6178
	/* end block 2 */
	// End Line: 6179

	/* begin block 3 */
		// Start line: 7030
	/* end block 3 */
	// End Line: 7031

	/* begin block 4 */
		// Start line: 7036
	/* end block 4 */
	// End Line: 7037

void aadAllNotesOff(int slotNumber)

{
  AadMemoryStruct *pAVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  _func_36 *p_Var6;
  
  uVar3 = 0;
  iVar5 = 0;
  iVar4 = 0x1dc;
  p_Var6 = aadMem->sequenceSlots[slotNumber];
  do {
    puVar2 = (uint *)((int)&aadMem->updateCounter + iVar4);
    if ((_func_36)(*(byte *)(puVar2 + 2) & 0xf0) == p_Var6[0x551]) {
      *(undefined *)(puVar2 + 2) = 0xff;
      uVar3 = uVar3 | *puVar2;
      *(ushort *)((int)puVar2 + 0x12) = *(ushort *)((int)puVar2 + 0x12) | 2;
    }
    pAVar1 = aadMem;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x1c;
  } while (iVar5 < 0x18);
  if (uVar3 != 0) {
    aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | uVar3;
    pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~uVar3;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadMuteChannels(struct _AadSequenceSlot *slot /*$a0*/, unsigned long channelList /*$a1*/)
 // line 3133, offset 0x80054da4
	/* begin block 1 */
		// Start line: 3135
		// Start offset: 0x80054DA4
		// Variables:
	// 		struct AadSynthVoice *voice; // $a2
	// 		unsigned long vmask; // $t2
	// 		unsigned long delayedMute; // $a2
	// 		int channel; // $t1
	// 		int i; // $t0
	/* end block 1 */
	// End offset: 0x80054E78
	// End Line: 3170

	/* begin block 2 */
		// Start line: 6261
	/* end block 2 */
	// End Line: 6262

	/* begin block 3 */
		// Start line: 7107
	/* end block 3 */
	// End Line: 7108

	/* begin block 4 */
		// Start line: 7112
	/* end block 4 */
	// End Line: 7113

void aadMuteChannels(_AadSequenceSlot *slot,ulong channelList)

{
  AadMemoryStruct *pAVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = slot->delayedMuteMode & channelList;
  if (uVar2 != 0) {
    channelList = channelList & ~uVar2;
    slot->delayedMuteCmds = slot->delayedMuteCmds | (ushort)uVar2;
  }
  uVar7 = 0;
  uVar6 = 0;
  slot->channelMute = slot->channelMute | (ushort)channelList;
  uVar2 = 1;
  do {
    if ((channelList & uVar2) != 0) {
      iVar5 = 0;
      iVar4 = 0x1dc;
      do {
        puVar3 = (uint *)((int)&aadMem->updateCounter + iVar4);
        if ((uint)*(byte *)(puVar3 + 2) == (slot->slotID | uVar6)) {
          *(undefined *)(puVar3 + 2) = 0xff;
          uVar7 = uVar7 | *puVar3;
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x1c;
      } while (iVar5 < 0x18);
    }
    pAVar1 = aadMem;
    uVar6 = uVar6 + 1;
    uVar2 = 1 << (uVar6 & 0x1f);
  } while ((int)uVar6 < 0x10);
  if (uVar7 != 0) {
    aadMem->voiceKeyOffRequest = aadMem->voiceKeyOffRequest | uVar7;
    pAVar1->voiceKeyOnRequest = pAVar1->voiceKeyOnRequest & ~uVar7;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadUnMuteChannels(struct _AadSequenceSlot *slot /*$a0*/, unsigned long channelList /*$a1*/)
 // line 3173, offset 0x80054e80
	/* begin block 1 */
		// Start line: 3175
		// Start offset: 0x80054E80
		// Variables:
	// 		unsigned long delayedUnMute; // $a2
	/* end block 1 */
	// End offset: 0x80054EA4
	// End Line: 3183

	/* begin block 2 */
		// Start line: 7200
	/* end block 2 */
	// End Line: 7201

	/* begin block 3 */
		// Start line: 7201
	/* end block 3 */
	// End Line: 7202

	/* begin block 4 */
		// Start line: 7204
	/* end block 4 */
	// End Line: 7205

void aadUnMuteChannels(_AadSequenceSlot *slot,ulong channelList)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar2 = (ushort)channelList;
  uVar3 = slot->delayedMuteMode & channelList;
  uVar1 = (ushort)uVar3;
  if (uVar3 != 0) {
    uVar2 = uVar2 & ~uVar1;
    slot->delayedUnMuteCmds = slot->delayedUnMuteCmds | uVar1;
  }
  slot->channelMute = slot->channelMute & ~uVar2;
  return;
}



// decompiled code
// original method signature: 
// TDRFuncPtr_aadInstallEndSequenceCallback /*$ra*/ aadInstallEndSequenceCallback(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc /*$a0*/, long data /*$a1*/)
 // line 3286, offset 0x80054eb8
	/* begin block 1 */
		// Start line: 3288
		// Start offset: 0x80054EB8
		// Variables:
	// 		void (*previousCallbackProc)(); // $v0
	/* end block 1 */
	// End offset: 0x80054EB8
	// End Line: 3290

	/* begin block 2 */
		// Start line: 6568
	/* end block 2 */
	// End Line: 6569

	/* begin block 3 */
		// Start line: 7326
	/* end block 3 */
	// End Line: 7327

	/* begin block 4 */
		// Start line: 7328
	/* end block 4 */
	// End Line: 7329

TDRFuncPtr_aadInstallEndSequenceCallback
aadInstallEndSequenceCallback
          (TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc,long data)

{
  AadMemoryStruct *pAVar1;
  TDRFuncPtr_aadInstallEndSequenceCallback pTVar2;
  
  pAVar1 = aadMem;
  pTVar2 = (TDRFuncPtr_aadInstallEndSequenceCallback)aadMem->endSequenceCallback;
  *(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc *)&aadMem->endSequenceCallback =
       callbackProc;
  pAVar1->endSequenceCallbackData = data;
  return pTVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetUserVariable(int variableNumber /*$a0*/, int value /*$a1*/)
 // line 3297, offset 0x80054ed0
	/* begin block 1 */
		// Start line: 7347
	/* end block 1 */
	// End Line: 7348

	/* begin block 2 */
		// Start line: 7349
	/* end block 2 */
	// End Line: 7350

void aadSetUserVariable(int variableNumber,int value)

{
  (&DAT_00001c08)[(int)&aadMem->updateCounter + variableNumber] = (char)value;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetNoUpdateMode(int noUpdate /*$a0*/)
 // line 3327, offset 0x80054ee4
	/* begin block 1 */
		// Start line: 6646
	/* end block 1 */
	// End Line: 6647

	/* begin block 2 */
		// Start line: 7381
	/* end block 2 */
	// End Line: 7382

void aadSetNoUpdateMode(int noUpdate)

{
  if (noUpdate != 0) {
    aadMem->flags = aadMem->flags | 2;
    return;
  }
  aadMem->flags = aadMem->flags & 0xfffffffd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPauseSound()
 // line 3348, offset 0x80054f24
	/* begin block 1 */
		// Start line: 3349
		// Start offset: 0x80054F24
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80054FA4
	// End Line: 3365

	/* begin block 2 */
		// Start line: 6684
	/* end block 2 */
	// End Line: 6685

	/* begin block 3 */
		// Start line: 7411
	/* end block 3 */
	// End Line: 7412

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadPauseSound(void)

{
  int iVar1;
  word *pwVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((aadMem->flags & 8U) == 0) {
    aadMem->flags = aadMem->flags | 0xc;
    iVar3 = 0;
    iVar5 = 0x494;
    iVar4 = 0;
    do {
      pwVar2 = (word *)((int)&aadMem->updateCounter + iVar5);
      iVar5 = iVar5 + 2;
      iVar1 = (int)&aadMem->updateCounter + iVar4;
      iVar4 = iVar4 + 0x1c;
      *(ushort *)(iVar1 + 0x1ee) = *(ushort *)(iVar1 + 0x1ee) & 0xfffd;
      SpuGetVoicePitch(iVar3,pwVar2);
      SpuSetVoicePitch(iVar3,0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x18);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadCancelPauseSound()
 // line 3367, offset 0x80054fbc
	/* begin block 1 */
		// Start line: 7461
	/* end block 1 */
	// End Line: 7462

	/* begin block 2 */
		// Start line: 7463
	/* end block 2 */
	// End Line: 7464

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadCancelPauseSound(void)

{
  aadMem->flags = aadMem->flags & 0xfffffff3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadResumeSound()
 // line 3374, offset 0x80054fd8
	/* begin block 1 */
		// Start line: 3375
		// Start offset: 0x80054FD8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80055050
	// End Line: 3390

	/* begin block 2 */
		// Start line: 7475
	/* end block 2 */
	// End Line: 7476

	/* begin block 3 */
		// Start line: 7479
	/* end block 3 */
	// End Line: 7480

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadResumeSound(void)

{
  int iVar1;
  int iVar2;
  
  if ((aadMem->flags & 8U) != 0) {
    aadMem->flags = aadMem->flags & 0xfffffff3;
    iVar1 = 0;
    iVar2 = 0;
    do {
      if ((*(ushort *)((int)&aadMem->synthVoice[0].flags + iVar2) & 2) == 0) {
        SpuSetVoicePitch(iVar1,aadMem->voicePitchSave[iVar1]);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < 0x18);
  }
  return;
}





