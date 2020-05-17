#include "THISDUST.H"
#include "AADLIB.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetMemorySize(struct AadInitAttr *attributes /*$a0*/)
 // line 40, offset 0x80051a90
	/* begin block 1 */
		// Start line: 80
	/* end block 1 */
	// End Line: 81

	/* begin block 2 */
		// Start line: 81
	/* end block 2 */
	// End Line: 82

ulong aadGetMemorySize(AadInitAttr *attributes)

{
  return (ulong)(&DAT_00001c88 + attributes->numSlots * 0x5d0);
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadInit(struct AadInitAttr *attributes /*$s1*/, unsigned char *memoryPtr /*$s0*/)
 // line 46, offset 0x80051ab4
	/* begin block 1 */
		// Start line: 47
		// Start offset: 0x80051AB4
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $v1
	// 		unsigned long size; // $v0
	// 		int slotNumber; // $a2
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80051D48
	// End Line: 183

	/* begin block 2 */
		// Start line: 92
	/* end block 2 */
	// End Line: 93

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
 // line 186, offset 0x80051d5c
	/* begin block 1 */
		// Start line: 495
	/* end block 1 */
	// End Line: 496

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
 // line 199, offset 0x80051dd8
	/* begin block 1 */
		// Start line: 521
	/* end block 1 */
	// End Line: 522

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
 // line 210, offset 0x80051e0c
	/* begin block 1 */
		// Start line: 547
	/* end block 1 */
	// End Line: 548

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
 // line 219, offset 0x80051e3c
	/* begin block 1 */
		// Start line: 568
	/* end block 1 */
	// End Line: 569

	/* begin block 2 */
		// Start line: 570
	/* end block 2 */
	// End Line: 571

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
 // line 229, offset 0x80051e54
	/* begin block 1 */
		// Start line: 588
	/* end block 1 */
	// End Line: 589

	/* begin block 2 */
		// Start line: 590
	/* end block 2 */
	// End Line: 591

void aadSetSfxMasterVolume(int volume)

{
  aadMem->sfxMasterVol = volume & 0xff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetMusicMasterVolume(int volume /*$a0*/)
 // line 237, offset 0x80051e64
	/* begin block 1 */
		// Start line: 238
		// Start offset: 0x80051E64
		// Variables:
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x80051EB8
	// End Line: 247

	/* begin block 2 */
		// Start line: 604
	/* end block 2 */
	// End Line: 605

	/* begin block 3 */
		// Start line: 608
	/* end block 3 */
	// End Line: 609

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
 // line 249, offset 0x80051ec8
	/* begin block 1 */
		// Start line: 633
	/* end block 1 */
	// End Line: 634

	/* begin block 2 */
		// Start line: 635
	/* end block 2 */
	// End Line: 636

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
 // line 285, offset 0x80051ee0
	/* begin block 1 */
		// Start line: 570
	/* end block 1 */
	// End Line: 571

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
 // line 321, offset 0x80051f68
	/* begin block 1 */
		// Start line: 322
		// Start offset: 0x80051F68
		// Variables:
	// 		unsigned long curGp; // $s0
	/* end block 1 */
	// End offset: 0x80051F68
	// End Line: 322

	/* begin block 2 */
		// Start line: 745
	/* end block 2 */
	// End Line: 746

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
 // line 338, offset 0x80051fac
	/* begin block 1 */
		// Start line: 339
		// Start offset: 0x80051FAC
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s2
	// 		struct AadSeqEvent *seqEventPtr; // $a1
	// 		int slotNumber; // $fp
	// 		int i; // $a3
	// 		int fadeComplete; // $v1
	// 		int track; // $s3
	// 		int newVol; // $s0
	// 		int slotDone; // $a2

		/* begin block 1.1 */
			// Start line: 354
			// Start offset: 0x80051FF4
			// Variables:
		// 		unsigned long vmask; // $a2
		/* end block 1.1 */
		// End offset: 0x8005206C
		// End Line: 369
	/* end block 1 */
	// End offset: 0x800524B4
	// End Line: 585

	/* begin block 2 */
		// Start line: 780
	/* end block 2 */
	// End Line: 781

	/* begin block 3 */
		// Start line: 789
	/* end block 3 */
	// End Line: 790

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
LAB_80052058:
          pAVar6->voiceKeyOffRequest = uVar7;
        }
        else {
          if (((pAVar6->voiceKeyOffRequest & uVar12) != 0) && ((cVar1 == '\0' || (cVar1 == '\x02')))
             ) {
            uVar7 = pAVar6->voiceKeyOffRequest & ~uVar12;
            goto LAB_80052058;
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
            do {
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
              bVar4 = true;
              track = 0;
              iVar8 = 0;
              p_Var14 = slot;
              p_Var15 = slot;
              do {
                if (p_Var14->sequencePosition[0] == (_func_9 *)0x0) break;
                uVar9 = p_Var15->eventsInQueue[0];
                while (uVar9 != '\0') {
                  event = (AadSeqEvent *)
                          ((int)&slot->eventQueue[(uint)p_Var15->eventOut[0] * 0x10].deltaTime +
                          iVar8);
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
                  bVar4 = false;
                }
                p_Var14 = (_AadSequenceSlot *)&(p_Var14->tempo).currentError;
                iVar8 = iVar8 + 0xc;
                track = track + 1;
                p_Var15 = (_AadSequenceSlot *)((int)&(p_Var15->tempo).currentTick + 1);
              } while (track < 0x10);
            } while (!bVar4);
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
 // line 629, offset 0x800524e4
	/* begin block 1 */
		// Start line: 1484
	/* end block 1 */
	// End Line: 1485

	/* begin block 2 */
		// Start line: 1485
	/* end block 2 */
	// End Line: 1486

ulong aadCreateFourCharID(char a,char b,char c,char d)

{
  return CONCAT13(a,CONCAT12(b,CONCAT11(c,d)));
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadLoadDynamicSoundBank(char *sndFileName /*$s3*/, char *smpFileName /*$s4*/, int dynamicBankIndex /*$s2*/, int loadOption /*$s5*/, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc /*stack 16*/)
 // line 637, offset 0x8005250c
	/* begin block 1 */
		// Start line: 638
		// Start offset: 0x8005250C
		// Variables:
	// 		int i; // $a0
	// 		struct AadDynamicBankLoadInfo *info; // $s1
	/* end block 1 */
	// End offset: 0x80052640
	// End Line: 692

	/* begin block 2 */
		// Start line: 1500
	/* end block 2 */
	// End Line: 1501

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
 // line 697, offset 0x80052664
	/* begin block 1 */
		// Start line: 698
		// Start offset: 0x80052664
		// Variables:
	// 		int dynamicBankIndex; // $s1
	// 		int error; // $s0
	/* end block 1 */
	// End offset: 0x80052718
	// End Line: 765

	/* begin block 2 */
		// Start line: 1665
	/* end block 2 */
	// End Line: 1666

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
 // line 775, offset 0x80052734
	/* begin block 1 */
		// Start line: 776
		// Start offset: 0x80052734
		// Variables:
	// 		unsigned char *dataPtr; // $s1
	// 		struct AadDynamicBankLoadInfo *info; // $s0
	// 		int dynamicBankIndex; // $s3
	// 		int error; // $v0

		/* begin block 1.1 */
			// Start line: 859
			// Start offset: 0x800528A8
			// Variables:
		// 		int i; // $a2
		/* end block 1.1 */
		// End offset: 0x8005293C
		// End Line: 873
	/* end block 1 */
	// End offset: 0x8005293C
	// End Line: 875

	/* begin block 2 */
		// Start line: 1823
	/* end block 2 */
	// End Line: 1824

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
      loadedDataSize = loadedDataSize + -8;
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
    SpuWrite((word *)loadedDataPtr,(undefined *)loadedDataSize,uVar5);
    *(undefined **)((int)data1 + 0x50) = (undefined *)loadedDataSize + *(int *)((int)data1 + 0x50);
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
 // line 893, offset 0x80052960
	/* begin block 1 */
		// Start line: 2091
	/* end block 1 */
	// End Line: 2092

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
 // line 923, offset 0x800529dc
	/* begin block 1 */
		// Start line: 924
		// Start offset: 0x800529DC
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
	// End offset: 0x80052AE8
	// End Line: 972

	/* begin block 2 */
		// Start line: 2158
	/* end block 2 */
	// End Line: 2159

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
 // line 989, offset 0x80052afc
	/* begin block 1 */
		// Start line: 990
		// Start offset: 0x80052AFC
		// Variables:
	// 		struct AadDynamicLoadRequest *loadReq; // $s0
	/* end block 1 */
	// End offset: 0x80052BA0
	// End Line: 1013

	/* begin block 2 */
		// Start line: 2362
	/* end block 2 */
	// End Line: 2363

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
 // line 1039, offset 0x80052bb0
	/* begin block 1 */
		// Start line: 1041
		// Start offset: 0x80052BB0
		// Variables:
	// 		struct AadDynamicLoadRequest *loadReq; // $a1
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80052C84
	// End Line: 1072

	/* begin block 2 */
		// Start line: 2488
	/* end block 2 */
	// End Line: 2489

	/* begin block 3 */
		// Start line: 2489
	/* end block 3 */
	// End Line: 2490

	/* begin block 4 */
		// Start line: 2496
	/* end block 4 */
	// End Line: 2497

int aadFreeDynamicSfx(int handle)

{
  AadMemoryStruct *pAVar1;
  AadDynamicLoadRequest *pAVar2;
  uint uVar3;
  
  pAVar1 = aadMem;
  uVar3 = aadMem->nextLoadReqOut;
  if (uVar3 != aadMem->nextLoadReqIn) {
    do {
      pAVar2 = aadMem->loadRequestQueue + uVar3;
      if ((pAVar2->type == 0) && (pAVar2->handle == handle)) {
        pAVar2->type = 2;
        return 0;
      }
      uVar3 = uVar3 + 1 & 0xf;
    } while (uVar3 != aadMem->nextLoadReqIn);
  }
  if (aadMem->numLoadReqsQueued < 0x10) {
    uVar3 = aadMem->nextLoadReqOut - 1U & 0xf;
    pAVar2 = aadMem->loadRequestQueue;
    aadMem->nextLoadReqOut = uVar3;
    pAVar2[uVar3].type = 1;
    pAVar2[uVar3].handle = handle;
    pAVar1->numLoadReqsQueued = pAVar1->numLoadReqsQueued + 1;
    return 0;
  }
  return (int)&DAT_0000100f;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadRelocateMusicMemoryBegin()
 // line 1116, offset 0x80052c8c
	/* begin block 1 */
		// Start line: 2664
	/* end block 1 */
	// End Line: 2665

	/* begin block 2 */
		// Start line: 2666
	/* end block 2 */
	// End Line: 2667

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadRelocateMusicMemoryBegin(void)

{
  aadMem->flags = aadMem->flags | 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadRelocateMusicMemoryEnd(void *oldAddress /*$v1*/, int offset /*$a1*/)
 // line 1124, offset 0x80052ca8
	/* begin block 1 */
		// Start line: 1125
		// Start offset: 0x80052CA8
		// Variables:
	// 		int bank; // $t6

		/* begin block 1.1 */
			// Start line: 1133
			// Start offset: 0x80052CC8
			// Variables:
		// 		int slotNumber; // $t4
		// 		int i; // $a2
		// 		struct AadSoundBankHdr *bankHdr; // $a0

			/* begin block 1.1.1 */
				// Start line: 1152
				// Start offset: 0x80052D70
				// Variables:
			// 		struct _AadSequenceSlot *slot; // $t2

				/* begin block 1.1.1.1 */
					// Start line: 1155
					// Start offset: 0x80052D98
					// Variables:
				// 		int track; // $t0
				/* end block 1.1.1.1 */
				// End offset: 0x80052E0C
				// End Line: 1171
			/* end block 1.1.1 */
			// End offset: 0x80052E0C
			// End Line: 1172
		/* end block 1.1 */
		// End offset: 0x80052E28
		// End Line: 1175
	/* end block 1 */
	// End offset: 0x80052E38
	// End Line: 1178

	/* begin block 2 */
		// Start line: 2680
	/* end block 2 */
	// End Line: 2681

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
    if (1 < iVar11) goto LAB_80052e38;
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
LAB_80052e38:
  aadMem->flags = aadMem->flags & 0xfffffffd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadRelocateSfxMemory(void *oldAddress /*$a0*/, int offset /*$a1*/)
 // line 1188, offset 0x80052e54
	/* begin block 1 */
		// Start line: 1190
		// Start offset: 0x80052E54
		// Variables:
	// 		struct _AadDynSfxFileHdr *snfFile; // $v1
	/* end block 1 */
	// End offset: 0x80052EB4
	// End Line: 1225

	/* begin block 2 */
		// Start line: 2895
	/* end block 2 */
	// End Line: 2896

	/* begin block 3 */
		// Start line: 2896
	/* end block 3 */
	// End Line: 2897

	/* begin block 4 */
		// Start line: 2901
	/* end block 4 */
	// End Line: 2902

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
 // line 1228, offset 0x80052ebc
	/* begin block 1 */
		// Start line: 2975
	/* end block 1 */
	// End Line: 2976

	/* begin block 2 */
		// Start line: 2977
	/* end block 2 */
	// End Line: 2978

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetNumLoadsQueued(void)

{
  return aadMem->numLoadReqsQueued;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPurgeLoadQueue()
 // line 1236, offset 0x80052ed0
	/* begin block 1 */
		// Start line: 2991
	/* end block 1 */
	// End Line: 2992

	/* begin block 2 */
		// Start line: 2993
	/* end block 2 */
	// End Line: 2994

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
 // line 1248, offset 0x80052ee8
	/* begin block 1 */
		// Start line: 1249
		// Start offset: 0x80052EE8
		// Variables:
	// 		struct AadDynamicSfxLoadInfo *info; // $s0
	// 		int i; // $a0
	// 		char *p; // $v0

		/* begin block 1.1 */
			// Start line: 1274
			// Start offset: 0x80052F70
			// Variables:
		// 		struct AadDynamicLoadRequest *loadReq; // $s2

			/* begin block 1.1.1 */
				// Start line: 1285
				// Start offset: 0x80052FC0
				// Variables:
			// 		char areaName[12]; // stack offset -32

				/* begin block 1.1.1.1 */
					// Start line: 1306
					// Start offset: 0x80052FFC
				/* end block 1.1.1.1 */
				// End offset: 0x80052FFC
				// End Line: 1306

				/* begin block 1.1.1.2 */
					// Start line: 1311
					// Start offset: 0x80053028
				/* end block 1.1.1.2 */
				// End offset: 0x80053058
				// End Line: 1313
			/* end block 1.1.1 */
			// End offset: 0x800530E0
			// End Line: 1332

			/* begin block 1.1.2 */
				// Start line: 1337
				// Start offset: 0x800530F0
				// Variables:
			// 		int i; // $s2
			// 		struct _AadDynSfxFileHdr *snfFile; // $s1
			// 		unsigned short *sfxIDListPtr; // $v1
			/* end block 1.1.2 */
			// End offset: 0x800531C8
			// End Line: 1369
		/* end block 1.1 */
		// End offset: 0x800531DC
		// End Line: 1377
	/* end block 1 */
	// End offset: 0x80053210
	// End Line: 1385

	/* begin block 2 */
		// Start line: 3015
	/* end block 2 */
	// End Line: 3016

	/* begin block 3 */
		// Start line: 3027
	/* end block 3 */
	// End Line: 3028

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadProcessLoadQueue(void)

{
  int *piVar1;
  ulong *puVar2;
  AadMemoryStruct *pAVar3;
  char *fmt;
  AadMemoryStruct *pAVar4;
  long lVar5;
  int id;
  AadDynamicSfxLoadInfo *string;
  _AadDynSfxFileHdr *p_Var6;
  _AadDynSfxFileHdr *p_Var7;
  AadDynamicLoadRequest *pAVar8;
  char acStack32 [16];
  
  pAVar3 = aadMem;
  string = &aadMem->dynamicSfxLoadInfo;
  id = 0;
  pAVar4 = aadMem;
  if (((aadMem->dynamicSfxLoadInfo).flags & 1U) != 0) {
    return;
  }
  do {
    id = id + 1;
    if (pAVar4->dynamicBankStatus[0] == 1) {
      return;
    }
    pAVar4 = (AadMemoryStruct *)&pAVar4->numSlots;
  } while (id < 2);
  if ((aadMem->numLoadReqsQueued == 0) || ((aadMem->sramDefragInfo).status != 0)) {
LAB_800531dc:
    if (gDefragRequest == 0) goto LAB_80053208;
  }
  else {
    if (gDefragRequest == 0) {
      id = aadMem->nextLoadReqOut;
      piVar1 = &aadMem->numLoadReqsQueued;
      aadMem->nextLoadReqOut = id + 1U & 0xf;
      pAVar8 = pAVar3->loadRequestQueue + id;
      pAVar3->numLoadReqsQueued = *piVar1 + -1;
      id = pAVar8->type;
      if (id == 1) {
        p_Var7 = pAVar3->firstDynSfxFile;
        if (p_Var7 != (_AadDynSfxFileHdr *)0x0) {
LAB_80053100:
          if ((uint)p_Var7->handle != pAVar8->handle) goto LAB_800531b8;
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
LAB_800531c8:
        id = aadCheckSramFragmented();
        if (id != 0) {
          gDefragRequest = 1;
        }
      }
      else {
        if ((id < 2) && (id == 0)) {
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
          id = pAVar8->directoryID;
          gSramFullAlarm = 0;
          (pAVar3->dynamicSfxLoadInfo).directoryID = id;
          lVar5 = pAVar8->flags;
          (pAVar3->dynamicSfxLoadInfo).flags = 1;
          (pAVar3->dynamicSfxLoadInfo).snfFile = (_AadDynSfxFileHdr *)0x0;
          (pAVar3->dynamicSfxLoadInfo).error = 0;
          (pAVar3->dynamicSfxLoadInfo).totalSramUsed = 0;
          (pAVar3->dynamicSfxLoadInfo).loadFlags = lVar5;
          if (id != 0) {
            LOAD_SetSearchDirectory(id);
          }
          (*aadMem->nonBlockLoadProc)
                    (string,aadLoadDynamicSfxReturn,string,0,&(pAVar3->dynamicSfxLoadInfo).snfFile,
                     0x2f);
          if ((pAVar3->dynamicSfxLoadInfo).directoryID != 0) {
            LOAD_SetSearchDirectory(0);
          }
        }
      }
      goto LAB_800531dc;
    }
  }
  id = SOUND_IsMusicLoading();
  if (id == 0) {
    gDefragRequest = 0;
    (aadMem->sramDefragInfo).status = 1;
  }
LAB_80053208:
  aadProcessSramDefrag();
  return;
LAB_800531b8:
  p_Var7 = p_Var7->nextDynSfxFile;
  if (p_Var7 == (_AadDynSfxFileHdr *)0x0) goto LAB_800531c8;
  goto LAB_80053100;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info /*$s0*/, int error /*$a1*/)
 // line 1388, offset 0x80053228
	/* begin block 1 */
		// Start line: 3335
	/* end block 1 */
	// End Line: 3336

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
 // line 1414, offset 0x800532ac
	/* begin block 1 */
		// Start line: 3387
	/* end block 1 */
	// End Line: 3388

	/* begin block 2 */
		// Start line: 3389
	/* end block 2 */
	// End Line: 3390

void aadLoadDynamicSfxDone(AadDynamicSfxLoadInfo *info)

{
  info->flags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxReturn(void *loadedDataPtr /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 1429, offset 0x800532b4
	/* begin block 1 */
		// Start line: 1430
		// Start offset: 0x800532B4
		// Variables:
	// 		struct _AadDynSfxFileHdr *p; // $v1
	// 		struct AadDynamicSfxLoadInfo *info; // $s0
	/* end block 1 */
	// End offset: 0x80053418
	// End Line: 1517

	/* begin block 2 */
		// Start line: 3417
	/* end block 2 */
	// End Line: 3418

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
// int /*$ra*/ aadWaveMalloc(unsigned short waveID /*$t6*/, unsigned long waveSize /*$a1*/)
 // line 1532, offset 0x8005342c
	/* begin block 1 */
		// Start line: 1533
		// Start offset: 0x8005342C
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $a2
	// 		struct AadNewSramBlockDesc *bestFit; // $t1
	// 		struct AadNewSramBlockDesc *next; // $a2
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $t2
	// 		unsigned long safeWaveSize; // $t4
	// 		int i; // $a3
	// 		int sramDescIndex; // $t0
	// 		int bestFitIndex; // $t3
	/* end block 1 */
	// End offset: 0x8005366C
	// End Line: 1636

	/* begin block 2 */
		// Start line: 3637
	/* end block 2 */
	// End Line: 3638

	/* begin block 3 */
		// Start line: 3647
	/* end block 3 */
	// End Line: 3648

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
  uint uVar13;
  
  uVar5 = waveSize >> 3;
  uVar13 = uVar5 & 0xfffffff8;
  if ((uVar5 & 7) != 0) {
    uVar13 = uVar13 + 8;
  }
  pAVar10 = (AadNewSramBlockDesc *)0x0;
  uVar12 = 0xff;
  uVar9 = aadMem->firstSramBlockDescIndex;
  pAVar11 = aadMem->sramDescriptorTbl;
  pAVar6 = pAVar11 + uVar9;
  if (pAVar6 != (AadNewSramBlockDesc *)0x0) {
    iVar7 = 0x7f;
    do {
      if (iVar7 == -1) break;
      if ((((pAVar6->waveID & 0x4000) == 0) && (uVar13 <= (uint)pAVar6->size)) &&
         ((pAVar10 == (AadNewSramBlockDesc *)0x0 || ((uint)pAVar6->size < (uint)pAVar10->size)))) {
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
    uVar13 = aadMem->nextSramDescIndex;
    uVar8 = (uchar)uVar13;
    pAVar6 = pAVar11 + uVar13;
    uVar2 = pAVar6->waveID;
    uVar5 = uVar13;
    while ((uVar2 & 0x8000) != 0) {
      uVar5 = uVar5 + 1 & 0x7f;
      uVar8 = (uchar)uVar5;
      if (uVar5 == uVar13) {
        return 0xff;
      }
      pAVar6 = pAVar11 + uVar5;
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
 // line 1640, offset 0x80053674
	/* begin block 1 */
		// Start line: 1642
		// Start offset: 0x80053674
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $v1
	/* end block 1 */
	// End offset: 0x80053698
	// End Line: 1652

	/* begin block 2 */
		// Start line: 3882
	/* end block 2 */
	// End Line: 3883

	/* begin block 3 */
		// Start line: 3883
	/* end block 3 */
	// End Line: 3884

	/* begin block 4 */
		// Start line: 3885
	/* end block 4 */
	// End Line: 3886

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
 // line 1673, offset 0x800536a0
	/* begin block 1 */
		// Start line: 1675
		// Start offset: 0x800536A0
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $a1
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $a3

		/* begin block 1.1 */
			// Start line: 1686
			// Start offset: 0x800536D0
			// Variables:
		// 		struct AadNewSramBlockDesc *next; // $a2
		/* end block 1.1 */
		// End offset: 0x80053734
		// End Line: 1695

		/* begin block 1.2 */
			// Start line: 1699
			// Start offset: 0x80053744
			// Variables:
		// 		struct AadNewSramBlockDesc *prev; // $a0
		/* end block 1.2 */
		// End offset: 0x800537A8
		// End Line: 1708
	/* end block 1 */
	// End offset: 0x800537A8
	// End Line: 1711

	/* begin block 2 */
		// Start line: 3346
	/* end block 2 */
	// End Line: 3347

	/* begin block 3 */
		// Start line: 3932
	/* end block 3 */
	// End Line: 3933

	/* begin block 4 */
		// Start line: 3935
	/* end block 4 */
	// End Line: 3936

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
 // line 1715, offset 0x800537b0
	/* begin block 1 */
		// Start line: 1716
		// Start offset: 0x800537B0
		// Variables:
	// 		int ti; // $v1
	// 		int wi; // $v1
	// 		struct AadLoadedSfxToneAttr *toneAttr; // $a1
	// 		struct AadLoadedSfxWaveAttr *waveAttr; // $v1
	/* end block 1 */
	// End offset: 0x80053868
	// End Line: 1741

	/* begin block 2 */
		// Start line: 4019
	/* end block 2 */
	// End Line: 4020

	/* begin block 3 */
		// Start line: 4024
	/* end block 3 */
	// End Line: 4025

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
 // line 1744, offset 0x80053878
	/* begin block 1 */
		// Start line: 1746
		// Start offset: 0x80053878
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
	// End offset: 0x80053924
	// End Line: 1783

	/* begin block 2 */
		// Start line: 4082
	/* end block 2 */
	// End Line: 4083

	/* begin block 3 */
		// Start line: 4083
	/* end block 3 */
	// End Line: 4084

	/* begin block 4 */
		// Start line: 4097
	/* end block 4 */
	// End Line: 4098

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
 // line 1800, offset 0x80053954
	/* begin block 1 */
		// Start line: 1801
		// Start offset: 0x80053954
		// Variables:
	// 		int i; // $a0
	// 		struct AadLoadedSfxToneAttr *toneAttr; // $a1
	// 		struct AadLoadedSfxWaveAttr *waveAttr; // $s0
	// 		struct AadDynSfxAttr *attr; // $s1
	/* end block 1 */
	// End offset: 0x80053C0C
	// End Line: 1914

	/* begin block 2 */
		// Start line: 4201
	/* end block 2 */
	// End Line: 4202

	/* begin block 3 */
		// Start line: 4210
	/* end block 3 */
	// End Line: 4211

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
        goto LAB_80053c00;
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
LAB_80053c00:
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
 // line 1929, offset 0x80053c24
	/* begin block 1 */
		// Start line: 4535
	/* end block 1 */
	// End Line: 4536

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
 // line 1938, offset 0x80053c5c
	/* begin block 1 */
		// Start line: 1939
		// Start offset: 0x80053C5C
		// Variables:
	// 		unsigned char *dataPtr; // $s4
	// 		unsigned long dataOffset; // $s3
	// 		unsigned long bytesRemaining; // $s2
	// 		struct AadDynamicSfxLoadInfo *info; // $s1
	// 		unsigned long n; // $s0
	/* end block 1 */
	// End offset: 0x80053EFC
	// End Line: 2091

	/* begin block 2 */
		// Start line: 4553
	/* end block 2 */
	// End Line: 4554

void aadLoadDynamicSfxReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  void *__src;
  undefined2 in_register_0000001a;
  undefined *puVar4;
  undefined *__n;
  undefined *puVar5;
  
  puVar4 = (undefined *)CONCAT22(in_register_0000001a,status);
  puVar5 = (undefined *)0x0;
  if (loadedDataSize != 0) {
    do {
      iVar3 = *(int *)((int)data1 + 0x60);
      if (iVar3 == 1) {
        __src = (void *)((int)loadedDataPtr + (int)puVar5);
        __n = *(undefined **)((int)data1 + 100);
        if ((uint)loadedDataSize < *(undefined **)((int)data1 + 100)) {
          __n = (undefined *)loadedDataSize;
        }
        puVar5 = __n + (int)puVar5;
        puVar4 = __n;
        memcpy((void *)((int)data1 - (*(int *)((int)data1 + 100) + -0x94)),__src,(size_t)__n);
        loadedDataSize = (long)((undefined *)loadedDataSize + -(int)__n);
        iVar3 = *(int *)((int)data1 + 100) - (int)__n;
        *(int *)((int)data1 + 100) = iVar3;
        if (iVar3 == 0) {
          aadLoadSingleDynSfx((AadDynamicSfxLoadInfo *)data1);
          *(undefined4 *)((int)data1 + 100) = *(undefined4 *)((int)data1 + 0x90);
        }
      }
      else {
        if (iVar3 < 2) {
          if (iVar3 == 0) {
            puVar4 = &UNK_0000004d;
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
LAB_80053d5c:
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,(int)&DAT_0000100d);
              return;
            }
            uVar2 = (uint)*(ushort *)(*(int *)((int)data1 + 0x78) + 10);
            puVar5 = puVar5 + 0x10;
            if ((uint)*(ushort *)((int)loadedDataPtr + 8) != uVar2) goto LAB_80053d5c;
            loadedDataSize = (long)((undefined *)loadedDataSize + -0x10);
            *(undefined4 *)((int)data1 + 0x60) = 1;
            *(undefined4 *)((int)data1 + 100) = 0x18;
            *(uint *)((int)data1 + 0x68) = uVar2;
          }
        }
        else {
          if (iVar3 == 2) {
            __n = *(undefined **)((int)data1 + 100);
            if ((uint)loadedDataSize < *(undefined **)((int)data1 + 100)) {
              __n = (undefined *)loadedDataSize;
            }
            puVar5 = __n + (int)puVar5;
            loadedDataSize = (long)((undefined *)loadedDataSize + -(int)__n);
            iVar3 = *(int *)((int)data1 + 100) - (int)__n;
            *(int *)((int)data1 + 100) = iVar3;
            if (iVar3 == 0) {
              iVar3 = *(int *)((int)data1 + 0x68) + -1;
              *(int *)((int)data1 + 0x68) = iVar3;
              if (iVar3 == 0) {
LAB_80053eb8:
                aadLoadDynamicSfxDone((AadDynamicSfxLoadInfo *)data1);
                return;
              }
              *(undefined4 *)((int)data1 + 0x60) = 1;
              *(undefined4 *)((int)data1 + 100) = 0x18;
            }
          }
          else {
            if (iVar3 == 3) {
              __n = *(undefined **)((int)data1 + 100);
              if ((uint)loadedDataSize < *(undefined **)((int)data1 + 100)) {
                __n = (undefined *)loadedDataSize;
              }
              loadedDataSize = (long)((undefined *)loadedDataSize + -(int)__n);
              aadWaitForSramTransferComplete();
              SpuSetTransferCallback((int)HackCallback);
              SpuSetTransferStartAddr(*(uint *)((int)data1 + 0x70));
              SpuWrite((word *)((int)loadedDataPtr + (int)puVar5),__n,(uint)puVar4);
              puVar5 = __n + (int)puVar5;
              iVar3 = *(int *)((int)data1 + 100) - (int)__n;
              *(undefined **)((int)data1 + 0x70) = __n + *(int *)((int)data1 + 0x70);
              *(int *)((int)data1 + 100) = iVar3;
              if (iVar3 == 0) {
                iVar3 = *(int *)((int)data1 + 0x68) + -1;
                *(int *)((int)data1 + 0x74) =
                     *(int *)((int)data1 + 0x74) + *(int *)((int)data1 + 0x90);
                *(int *)((int)data1 + 0x68) = iVar3;
                if (iVar3 == 0) {
                  SpuSetTransferCallback(0);
                  goto LAB_80053eb8;
                }
                *(undefined4 *)((int)data1 + 0x60) = 1;
                *(undefined4 *)((int)data1 + 100) = 0x18;
              }
              if ((undefined *)loadedDataSize != (undefined *)0x0) {
                smfDataPtr = (uchar *)((int)loadedDataPtr + (int)puVar5);
                smfBytesLeft = loadedDataSize;
                smfInfo = (AadDynamicSfxLoadInfo *)data1;
                return;
              }
              SpuSetTransferCallback(0);
            }
          }
        }
      }
    } while ((undefined *)loadedDataSize != (undefined *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadCheckSramFragmented()
 // line 2143, offset 0x80053f24
	/* begin block 1 */
		// Start line: 2145
		// Start offset: 0x80053F24
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $v1
	// 		struct AadNewSramBlockDesc *sramDesc; // $a1
	// 		long totalFree; // $t0
	// 		long smallestFree; // $t1
	// 		long numFreeBlocks; // $a3
	// 		int i; // $a2
	// 		int defragNeeded; // $v1
	/* end block 1 */
	// End offset: 0x80053FD0
	// End Line: 2187

	/* begin block 2 */
		// Start line: 5016
	/* end block 2 */
	// End Line: 5017

	/* begin block 3 */
		// Start line: 5017
	/* end block 3 */
	// End Line: 5018

	/* begin block 4 */
		// Start line: 5027
	/* end block 4 */
	// End Line: 5028

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
 // line 2206, offset 0x80053fd8
	/* begin block 1 */
		// Start line: 2207
		// Start offset: 0x80053FD8
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
			// Start line: 2309
			// Start offset: 0x800541A0
			// Variables:
		// 		struct AadNewSramBlockDesc *next; // $a0
		/* end block 1.1 */
		// End offset: 0x80054204
		// End Line: 2321
	/* end block 1 */
	// End offset: 0x80054314
	// End Line: 2399

	/* begin block 2 */
		// Start line: 5147
	/* end block 2 */
	// End Line: 5148

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
  AadNewSramBlockDesc *pAVar11;
  AadNewSramBlockDesc *pAVar12;
  AadSramDefragInfo *pAVar13;
  byte bVar14;
  uint uVar15;
  AadNewSramBlockDesc *pAVar16;
  
  pAVar4 = aadMem;
  iVar7 = (aadMem->sramDefragInfo).status;
  pAVar13 = &aadMem->sramDefragInfo;
  if (iVar7 == 1) {
    uVar15 = aadMem->firstSramBlockDescIndex;
    pAVar16 = aadMem->sramDescriptorTbl;
    pAVar11 = pAVar16 + uVar15;
    iVar7 = 0x80;
    if (pAVar11 != (AadNewSramBlockDesc *)0x0) {
      do {
        bVar14 = (byte)uVar15;
        if ((pAVar11->waveID & 0x4000) == 0) break;
        iVar7 = iVar7 + -1;
        bVar14 = pAVar11->nextIndex;
        uVar15 = (uint)bVar14;
        if ((iVar7 == 0) || (0x7f < bVar14)) {
          pAVar11 = (AadNewSramBlockDesc *)0x0;
        }
        else {
          pAVar11 = pAVar16 + uVar15;
        }
      } while (pAVar11 != (AadNewSramBlockDesc *)0x0);
      if ((pAVar11 != (AadNewSramBlockDesc *)0x0) && (-1 < (char)pAVar11->nextIndex)) {
        bVar1 = pAVar11->nextIndex;
        pAVar12 = pAVar16 + bVar1;
        if ((pAVar12->waveID & 0x4000) != 0) {
          puVar6 = (uchar *)(*aadMem->memoryMallocProc)(0x1000,0x30);
          (pAVar4->sramDefragInfo).fragBuffer = puVar6;
          pAVar5 = aadMem;
          if (puVar6 != (uchar *)0x0) {
            uVar15 = (uint)pAVar12->waveID & 0x3fff;
            iVar7 = (int)&aadMem->updateCounter + uVar15;
            bVar2 = *(byte *)(iVar7 + 0xa08);
            (pAVar4->sramDefragInfo).masterListEntry = (uint)bVar2;
            if (bVar2 < 0xfe) {
              *(undefined *)(iVar7 + 0xa08) = 0xff;
              (pAVar4->sramDefragInfo).waveID = uVar15;
              (pAVar4->sramDefragInfo).destSramAddr = (uint)pAVar11->address << 3;
              (pAVar4->sramDefragInfo).srcSramAddr = (uint)pAVar12->address << 3;
              (pAVar4->sramDefragInfo).moveSize = (uint)pAVar12->size << 3;
              uVar3 = pAVar11->size;
              pAVar11->size = pAVar12->size;
              pAVar12->size = uVar3;
              uVar3 = pAVar11->waveID;
              pAVar11->waveID = pAVar12->waveID;
              pAVar12->waveID = uVar3;
              pAVar12->address = pAVar11->address + pAVar11->size;
              if ((-1 < (char)pAVar12->nextIndex) &&
                 (pAVar11 = pAVar16 + pAVar12->nextIndex, (pAVar11->waveID & 0x4000) == 0)) {
                pAVar12->size = pAVar12->size + pAVar11->size;
                bVar2 = pAVar11->nextIndex;
                pAVar11->waveID = 0;
                pAVar12->nextIndex = bVar2;
                if (-1 < (int)((uint)bVar2 << 0x18)) {
                  pAVar16[pAVar12->nextIndex].prevIndex = bVar1;
                }
              }
              aadMem->sfxWaveAttrTbl[(pAVar4->sramDefragInfo).masterListEntry].sramHandle = bVar14;
              pAVar13->status = 2;
              return;
            }
            (*pAVar5->memoryFreeProc)((pAVar4->sramDefragInfo).fragBuffer);
          }
        }
      }
    }
    pAVar13->status = 0;
  }
  else {
    if (1 < iVar7) {
      if (iVar7 == 2) {
        iVar7 = SpuIsTransferCompleted(0);
        if (iVar7 != 0) {
          puVar8 = (undefined *)(pAVar4->sramDefragInfo).moveSize;
          puVar10 = &DAT_00001000;
          if (puVar8 < &DAT_00001001) {
            puVar10 = puVar8;
          }
          SpuSetTransferStartAddr((pAVar4->sramDefragInfo).srcSramAddr);
          SpuRead((uint)(pAVar4->sramDefragInfo).fragBuffer,puVar10,in_a2);
          *(undefined **)&(pAVar4->sramDefragInfo).readSize = puVar10;
          (pAVar4->sramDefragInfo).status = 3;
        }
      }
      else {
        if ((iVar7 == 3) && (iVar7 = SpuIsTransferCompleted(0), iVar7 != 0)) {
          SpuSetTransferStartAddr((pAVar4->sramDefragInfo).destSramAddr);
          puVar10 = (undefined *)(pAVar4->sramDefragInfo).readSize;
          SpuWrite((word *)(pAVar4->sramDefragInfo).fragBuffer,puVar10,in_a2);
          *(undefined **)&(pAVar4->sramDefragInfo).srcSramAddr =
               puVar10 + (pAVar4->sramDefragInfo).srcSramAddr;
          uVar9 = (pAVar4->sramDefragInfo).moveSize - (int)puVar10;
          (pAVar4->sramDefragInfo).moveSize = uVar9;
          *(undefined **)&(pAVar4->sramDefragInfo).destSramAddr =
               puVar10 + (pAVar4->sramDefragInfo).destSramAddr;
          if (uVar9 == 0) {
            (*aadMem->memoryFreeProc)((pAVar4->sramDefragInfo).fragBuffer);
            aadMem->sfxWaveMasterList[(pAVar4->sramDefragInfo).waveID] =
                 *(uchar *)&(pAVar4->sramDefragInfo).masterListEntry;
            iVar7 = aadCheckSramFragmented();
            if (iVar7 == 0) {
              (pAVar4->sramDefragInfo).status = 0;
            }
            else {
              (pAVar4->sramDefragInfo).status = 1;
            }
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
 // line 2408, offset 0x8005433c
	/* begin block 1 */
		// Start line: 4816
	/* end block 1 */
	// End Line: 4817

	/* begin block 2 */
		// Start line: 5577
	/* end block 2 */
	// End Line: 5578

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
 // line 2681, offset 0x80054378
	/* begin block 1 */
		// Start line: 2682
		// Start offset: 0x80054378
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $t0
	// 		unsigned long trackOffset; // $v0
	// 		int i; // $a1
	// 		int bank; // $a0
	/* end block 1 */
	// End offset: 0x80054468
	// End Line: 2740

	/* begin block 2 */
		// Start line: 5859
	/* end block 2 */
	// End Line: 5860

	/* begin block 3 */
		// Start line: 6124
	/* end block 3 */
	// End Line: 6125

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
 // line 2750, offset 0x80054484
	/* begin block 1 */
		// Start line: 2751
		// Start offset: 0x80054484
		// Variables:
	// 		int n; // $s0
	/* end block 1 */
	// End offset: 0x800544B4
	// End Line: 2758

	/* begin block 2 */
		// Start line: 6351
	/* end block 2 */
	// End Line: 6352

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
 // line 2761, offset 0x800544c4
	/* begin block 1 */
		// Start line: 6374
	/* end block 1 */
	// End Line: 6375

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
 // line 2777, offset 0x80054548
	/* begin block 1 */
		// Start line: 6406
	/* end block 1 */
	// End Line: 6407

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
 // line 2791, offset 0x80054580
	/* begin block 1 */
		// Start line: 6434
	/* end block 1 */
	// End Line: 6435

	/* begin block 2 */
		// Start line: 6435
	/* end block 2 */
	// End Line: 6436

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetReverbMode(void)

{
  return 3;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetReverbSize()
 // line 2813, offset 0x80054588
	/* begin block 1 */
		// Start line: 6478
	/* end block 1 */
	// End Line: 6479

/* WARNING: Unknown calling convention yet parameter storage is locked */

ulong aadGetReverbSize(void)

{
  int iVar1;
  
  iVar1 = aadGetReverbMode();
  return (&aadReverbModeSize)[iVar1] + 0x40;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetReverbDepth()
 // line 2818, offset 0x800545b8
	/* begin block 1 */
		// Start line: 6488
	/* end block 1 */
	// End Line: 6489

	/* begin block 2 */
		// Start line: 6489
	/* end block 2 */
	// End Line: 6490

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetReverbDepth(void)

{
  return (int)&DAT_00002710;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetNumDynamicSequences(int bank /*$a0*/)
 // line 2831, offset 0x800545c0
	/* begin block 1 */
		// Start line: 5662
	/* end block 1 */
	// End Line: 5663

	/* begin block 2 */
		// Start line: 6505
	/* end block 2 */
	// End Line: 6506

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
 // line 2848, offset 0x800545f0
	/* begin block 1 */
		// Start line: 2849
		// Start offset: 0x800545F0
		// Variables:
	// 		struct AadTempo tempo; // stack offset -32
	// 		struct _AadSequenceSlot *slot; // $s0
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x800546B0
	// End Line: 2895

	/* begin block 2 */
		// Start line: 6536
	/* end block 2 */
	// End Line: 6537

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
 // line 2898, offset 0x800546cc
	/* begin block 1 */
		// Start line: 2900
		// Start offset: 0x800546CC
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $v1
	/* end block 1 */
	// End offset: 0x80054714
	// End Line: 2913

	/* begin block 2 */
		// Start line: 6666
	/* end block 2 */
	// End Line: 6667

	/* begin block 3 */
		// Start line: 6667
	/* end block 3 */
	// End Line: 6668

	/* begin block 4 */
		// Start line: 6674
	/* end block 4 */
	// End Line: 6675

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
 // line 3032, offset 0x8005471c
	/* begin block 1 */
		// Start line: 3034
		// Start offset: 0x8005471C
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a0
	// 		unsigned long tickTime; // $v1
	// 		unsigned long tickTimeRemainder; // $a2
	/* end block 1 */
	// End offset: 0x8005471C
	// End Line: 3040

	/* begin block 2 */
		// Start line: 6934
	/* end block 2 */
	// End Line: 6935

	/* begin block 3 */
		// Start line: 6935
	/* end block 3 */
	// End Line: 6936

	/* begin block 4 */
		// Start line: 6941
	/* end block 4 */
	// End Line: 6942

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
 // line 3053, offset 0x800547d0
	/* begin block 1 */
		// Start line: 3054
		// Start offset: 0x800547D0
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s0
	/* end block 1 */
	// End offset: 0x8005483C
	// End Line: 3067

	/* begin block 2 */
		// Start line: 6981
	/* end block 2 */
	// End Line: 6982

	/* begin block 3 */
		// Start line: 6984
	/* end block 3 */
	// End Line: 6985

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
 // line 3070, offset 0x8005484c
	/* begin block 1 */
		// Start line: 3071
		// Start offset: 0x8005484C
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a0
	/* end block 1 */
	// End offset: 0x800548A8
	// End Line: 3085

	/* begin block 2 */
		// Start line: 7018
	/* end block 2 */
	// End Line: 7019

	/* begin block 3 */
		// Start line: 7021
	/* end block 3 */
	// End Line: 7022

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
 // line 3088, offset 0x800548b8
	/* begin block 1 */
		// Start line: 3089
		// Start offset: 0x800548B8
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s1
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x80054930
	// End Line: 3103

	/* begin block 2 */
		// Start line: 7060
	/* end block 2 */
	// End Line: 7061

	/* begin block 3 */
		// Start line: 7065
	/* end block 3 */
	// End Line: 7066

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
 // line 3106, offset 0x80054948
	/* begin block 1 */
		// Start line: 7107
	/* end block 1 */
	// End Line: 7108

	/* begin block 2 */
		// Start line: 7108
	/* end block 2 */
	// End Line: 7109

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
 // line 3117, offset 0x80054998
	/* begin block 1 */
		// Start line: 7130
	/* end block 1 */
	// End Line: 7131

	/* begin block 2 */
		// Start line: 7131
	/* end block 2 */
	// End Line: 7132

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
 // line 3125, offset 0x800549d8
	/* begin block 1 */
		// Start line: 7146
	/* end block 1 */
	// End Line: 7147

	/* begin block 2 */
		// Start line: 7147
	/* end block 2 */
	// End Line: 7148

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
 // line 3136, offset 0x80054a28
	/* begin block 1 */
		// Start line: 3138
		// Start offset: 0x80054A28
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a1
	// 		int track; // $a0
	/* end block 1 */
	// End offset: 0x80054A90
	// End Line: 3152

	/* begin block 2 */
		// Start line: 7169
	/* end block 2 */
	// End Line: 7170

	/* begin block 3 */
		// Start line: 7170
	/* end block 3 */
	// End Line: 7171

	/* begin block 4 */
		// Start line: 7173
	/* end block 4 */
	// End Line: 7174

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
 // line 3155, offset 0x80054a98
	/* begin block 1 */
		// Start line: 7209
	/* end block 1 */
	// End Line: 7210

	/* begin block 2 */
		// Start line: 7210
	/* end block 2 */
	// End Line: 7211

int aadGetSlotStatus(int slotNumber)

{
  return (uint)*(ushort *)(aadMem->sequenceSlots[slotNumber] + 0x540);
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadAllNotesOff(int slotNumber /*$a0*/)
 // line 3181, offset 0x80054ab8
	/* begin block 1 */
		// Start line: 3183
		// Start offset: 0x80054AB8
		// Variables:
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned long vmask; // $a1
	// 		int i; // $a3
	// 		struct _AadSequenceSlot *slot; // $t0
	/* end block 1 */
	// End offset: 0x80054B50
	// End Line: 3206

	/* begin block 2 */
		// Start line: 6362
	/* end block 2 */
	// End Line: 6363

	/* begin block 3 */
		// Start line: 7237
	/* end block 3 */
	// End Line: 7238

	/* begin block 4 */
		// Start line: 7243
	/* end block 4 */
	// End Line: 7244

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
 // line 3223, offset 0x80054b58
	/* begin block 1 */
		// Start line: 3225
		// Start offset: 0x80054B58
		// Variables:
	// 		struct AadSynthVoice *voice; // $a2
	// 		unsigned long vmask; // $t2
	// 		unsigned long delayedMute; // $a2
	// 		int channel; // $t1
	// 		int i; // $t0
	/* end block 1 */
	// End offset: 0x80054C2C
	// End Line: 3260

	/* begin block 2 */
		// Start line: 6446
	/* end block 2 */
	// End Line: 6447

	/* begin block 3 */
		// Start line: 7314
	/* end block 3 */
	// End Line: 7315

	/* begin block 4 */
		// Start line: 7319
	/* end block 4 */
	// End Line: 7320

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
 // line 3263, offset 0x80054c34
	/* begin block 1 */
		// Start line: 3265
		// Start offset: 0x80054C34
		// Variables:
	// 		unsigned long delayedUnMute; // $a2
	/* end block 1 */
	// End offset: 0x80054C58
	// End Line: 3273

	/* begin block 2 */
		// Start line: 7407
	/* end block 2 */
	// End Line: 7408

	/* begin block 3 */
		// Start line: 7408
	/* end block 3 */
	// End Line: 7409

	/* begin block 4 */
		// Start line: 7411
	/* end block 4 */
	// End Line: 7412

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
 // line 3376, offset 0x80054c6c
	/* begin block 1 */
		// Start line: 3378
		// Start offset: 0x80054C6C
		// Variables:
	// 		void (*previousCallbackProc)(); // $v0
	/* end block 1 */
	// End offset: 0x80054C6C
	// End Line: 3380

	/* begin block 2 */
		// Start line: 6752
	/* end block 2 */
	// End Line: 6753

	/* begin block 3 */
		// Start line: 7533
	/* end block 3 */
	// End Line: 7534

	/* begin block 4 */
		// Start line: 7535
	/* end block 4 */
	// End Line: 7536

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
 // line 3387, offset 0x80054c84
	/* begin block 1 */
		// Start line: 7554
	/* end block 1 */
	// End Line: 7555

	/* begin block 2 */
		// Start line: 7556
	/* end block 2 */
	// End Line: 7557

void aadSetUserVariable(int variableNumber,int value)

{
  (&DAT_00001c08)[(int)&aadMem->updateCounter + variableNumber] = (char)value;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetNoUpdateMode(int noUpdate /*$a0*/)
 // line 3417, offset 0x80054c98
	/* begin block 1 */
		// Start line: 6834
	/* end block 1 */
	// End Line: 6835

	/* begin block 2 */
		// Start line: 7588
	/* end block 2 */
	// End Line: 7589

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
 // line 3438, offset 0x80054cd8
	/* begin block 1 */
		// Start line: 3439
		// Start offset: 0x80054CD8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80054D58
	// End Line: 3455

	/* begin block 2 */
		// Start line: 6876
	/* end block 2 */
	// End Line: 6877

	/* begin block 3 */
		// Start line: 7618
	/* end block 3 */
	// End Line: 7619

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
 // line 3457, offset 0x80054d70
	/* begin block 1 */
		// Start line: 7668
	/* end block 1 */
	// End Line: 7669

	/* begin block 2 */
		// Start line: 7670
	/* end block 2 */
	// End Line: 7671

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadCancelPauseSound(void)

{
  aadMem->flags = aadMem->flags & 0xfffffff3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadResumeSound()
 // line 3464, offset 0x80054d8c
	/* begin block 1 */
		// Start line: 3465
		// Start offset: 0x80054D8C
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80054E04
	// End Line: 3480

	/* begin block 2 */
		// Start line: 7682
	/* end block 2 */
	// End Line: 7683

	/* begin block 3 */
		// Start line: 7686
	/* end block 3 */
	// End Line: 7687

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





