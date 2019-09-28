#include "THISDUST.H"
#include "AADLIB.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetMemorySize(struct AadInitAttr *attributes /*$a0*/)
 // line 40, offset 0x800514d4
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
 // line 46, offset 0x800514f8
	/* begin block 1 */
		// Start line: 47
		// Start offset: 0x800514F8
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $v1
	// 		unsigned long size; // $v0
	// 		int slotNumber; // $a2
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8005178C
	// End Line: 183

	/* begin block 2 */
		// Start line: 92
	/* end block 2 */
	// End Line: 93

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aadInit(AadInitAttr *attributes,uchar *memoryPtr)

{
  _aadGp = GetGp();
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr /*$s0*/, int hblanksPerUpdate /*$s1*/)
 // line 186, offset 0x800517a0
	/* begin block 1 */
		// Start line: 495
	/* end block 1 */
	// End Line: 496

void aadInstallUpdateFunc(void)

{
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInitVolume()
 // line 199, offset 0x8005181c
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
 // line 210, offset 0x80051850
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
 // line 219, offset 0x80051880
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
 // line 229, offset 0x80051898
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
 // line 237, offset 0x800518a8
	/* begin block 1 */
		// Start line: 238
		// Start offset: 0x800518A8
		// Variables:
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x800518FC
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
 // line 249, offset 0x8005190c
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
 // line 285, offset 0x80051924
	/* begin block 1 */
		// Start line: 570
	/* end block 1 */
	// End Line: 571

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadShutdown(void)

{
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}



// decompiled code
// original method signature: 
// long /*$ra*/ aadSlotUpdateWrapper()
 // line 321, offset 0x800519ac
	/* begin block 1 */
		// Start line: 322
		// Start offset: 0x800519AC
		// Variables:
	// 		unsigned long curGp; // $s0
	/* end block 1 */
	// End offset: 0x800519AC
	// End Line: 322

	/* begin block 2 */
		// Start line: 745
	/* end block 2 */
	// End Line: 746

undefined4 aadSlotUpdateWrapper(void)

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
 // line 338, offset 0x800519f0
	/* begin block 1 */
		// Start line: 339
		// Start offset: 0x800519F0
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s2
	// 		struct AadSeqEvent *seqEventPtr; // $a0
	// 		int slotNumber; // $fp
	// 		int i; // $a3
	// 		int fadeComplete; // $v1
	// 		int track; // $s3
	// 		int newVol; // $s0
	// 		int slotDone; // $a2

		/* begin block 1.1 */
			// Start line: 354
			// Start offset: 0x80051A38
			// Variables:
		// 		unsigned long vmask; // $a2
		/* end block 1.1 */
		// End offset: 0x80051AB0
		// End Line: 369
	/* end block 1 */
	// End offset: 0x80051F08
	// End Line: 592

	/* begin block 2 */
		// Start line: 780
	/* end block 2 */
	// End Line: 781

	/* begin block 3 */
		// Start line: 789
	/* end block 3 */
	// End Line: 790

void aadSlotUpdate(void)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  _func_10 *p_Var4;
  int volume;
  uchar uVar5;
  char cVar6;
  code *pcVar7;
  _AadSequenceSlot *event;
  _AadSequenceSlot *hblanksPerUpdate;
  uint uVar8;
  int iVar9;
  _AadSequenceSlot *p_Var10;
  ulong volume_00;
  _AadSequenceSlot *slot;
  _AadSequenceSlot *track;
  _AadSequenceSlot *p_Var11;
  int iVar12;
  
  if (p_Gpffff9224 != (_AadSequenceSlot *)0x0) {
    if ((p_Gpffff9224->eventQueue[1].deltaTime & 2) == 0) {
      event = (_AadSequenceSlot *)(p_Gpffff9224->loopSequencePosition + 0x25);
      SpuGetAllKeysStatus((undefined *)event);
      iVar9 = 0;
      uVar8 = 1;
      do {
        cVar6 = *(char *)((int)p_Gpffff9224->loopSequencePosition + iVar9 + 0x94);
        if (cVar6 == '\x03') {
          p_Var4 = (_func_10 *)((uint)p_Gpffff9224->loopSequencePosition[0x37] | uVar8);
LAB_80051a9c:
          p_Gpffff9224->loopSequencePosition[0x37] = p_Var4;
        }
        else {
          event = (_AadSequenceSlot *)p_Gpffff9224->loopSequencePosition[0x37];
          if ((((uint)event & uVar8) != 0) && ((cVar6 == '\0' || (cVar6 == '\x02')))) {
            p_Var4 = (_func_10 *)((uint)event & ~uVar8);
            goto LAB_80051a9c;
          }
        }
        iVar9 = iVar9 + 1;
        uVar8 = uVar8 << 1;
      } while (iVar9 < 0x18);
      hblanksPerUpdate = p_Gpffff9224;
      if (((p_Gpffff9224->eventQueue[1].deltaTime & 4) == 0) &&
         (iVar9 = 0, 0 < (int)(p_Gpffff9224->tempo).currentError)) {
        volume = 0;
        do {
          slot = *(_AadSequenceSlot **)(&p_Gpffff9224->eventQueue[2].track + volume);
          if (((slot->status & 1) != 0) && ((slot->slotFlags & 1) == 0)) {
            (slot->tempo).currentTick =
                 (slot->tempo).currentTick + (uint)(slot->tempo).ticksPerUpdate;
            hblanksPerUpdate = (_AadSequenceSlot *)(slot->tempo).tickTimeFixed;
            event = (_AadSequenceSlot *)((slot->tempo).currentError + (slot->tempo).errorPerUpdate);
            *(_AadSequenceSlot **)&(slot->tempo).currentError = event;
            if (hblanksPerUpdate <= event) {
              *(_AadSequenceSlot **)&(slot->tempo).currentError =
                   (_AadSequenceSlot *)((int)event - (int)hblanksPerUpdate);
              (slot->tempo).currentTick = (slot->tempo).currentTick + 1;
            }
            do {
              track = (_AadSequenceSlot *)0x0;
              p_Var10 = slot;
              p_Var11 = slot;
              do {
                if (p_Var11->sequencePosition[0] == (_func_9 *)0x0) break;
                bVar1 = p_Var10->eventsInQueue[0];
                while ((event = slot, bVar1 < 3 &&
                       (hblanksPerUpdate = track, volume = aadQueueNextEvent(slot,(int)track),
                       volume == 0))) {
                  bVar1 = p_Var10->eventsInQueue[0];
                }
                p_Var10 = (_AadSequenceSlot *)((int)&(p_Var10->tempo).currentTick + 1);
                track = (_AadSequenceSlot *)((int)&(track->tempo).currentTick + 1);
                p_Var11 = (_AadSequenceSlot *)&(p_Var11->tempo).currentError;
              } while ((int)track < 0x10);
              bVar3 = true;
              volume = 0;
              iVar12 = 0;
              p_Var10 = slot;
              p_Var11 = slot;
              do {
                if (p_Var10->sequencePosition[0] == (_func_9 *)0x0) break;
                uVar5 = p_Var11->eventsInQueue[0];
                while (uVar5 != '\0') {
                  event = (_AadSequenceSlot *)
                          ((int)&slot->eventQueue[(uint)p_Var11->eventOut[0] * 0x10].deltaTime +
                          iVar12);
                  hblanksPerUpdate = (_AadSequenceSlot *)(event->tempo).currentTick;
                  uVar8 = (int)&(hblanksPerUpdate->tempo).currentTick +
                          p_Var10->lastEventExecutedTime[0];
                  if (((slot->tempo).currentTick < uVar8) ||
                     ((_AadSequenceSlot *)&UNK_000f4240 < hblanksPerUpdate)) break;
                  p_Var10->lastEventExecutedTime[0] = uVar8;
                  uVar5 = p_Var11->eventOut[0] + '\x01';
                  p_Var11->eventOut[0] = uVar5;
                  p_Var11->eventsInQueue[0] = p_Var11->eventsInQueue[0] + -1;
                  if (uVar5 == '\x04') {
                    p_Var11->eventOut[0] = '\0';
                  }
                  hblanksPerUpdate = slot;
                  aadExecuteEvent((AadSeqEvent *)event,slot);
                  uVar5 = p_Var11->eventsInQueue[0];
                  bVar3 = false;
                }
                p_Var10 = (_AadSequenceSlot *)&(p_Var10->tempo).currentError;
                iVar12 = iVar12 + 0xc;
                volume = volume + 1;
                p_Var11 = (_AadSequenceSlot *)((int)&(p_Var11->tempo).currentTick + 1);
              } while (volume < 0x10);
            } while (!bVar3);
          }
          iVar9 = iVar9 + 1;
          volume = iVar9 * 4;
        } while (iVar9 < (int)(p_Gpffff9224->tempo).currentError);
      }
      if (*(short *)((int)&p_Gpffff9224->eventQueue[0x25].deltaTime + 2) == 0) {
        aadInstallUpdateFunc
                  ((TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr)event,(int)hblanksPerUpdate);
        return;
      }
      do {
        aadExecuteSfxCommand
                  ((AadSfxCommand *)
                   (p_Gpffff9224->eventQueue +
                   (uint)*(byte *)((int)&p_Gpffff9224->eventQueue[0x25].deltaTime + 1) + 5));
        sVar2 = *(short *)((int)&p_Gpffff9224->eventQueue[0x25].deltaTime + 2);
        cVar6 = *(char *)((int)&p_Gpffff9224->eventQueue[0x25].deltaTime + 1) + '\x01';
        *(char *)((int)&p_Gpffff9224->eventQueue[0x25].deltaTime + 1) = cVar6;
        *(short *)((int)&p_Gpffff9224->eventQueue[0x25].deltaTime + 2) = sVar2 + -1;
        if (cVar6 == ' ') {
          *(undefined *)((int)&p_Gpffff9224->eventQueue[0x25].deltaTime + 1) = 0;
        }
      } while (*(short *)((int)&p_Gpffff9224->eventQueue[0x25].deltaTime + 2) != 0);
      p_Var4 = (_func_10 *)
               ((uint)p_Gpffff9224->loopSequencePosition[0x37] &
               ~(uint)p_Gpffff9224->loopSequencePosition[0x38]);
      p_Gpffff9224->loopSequencePosition[0x37] = p_Var4;
      if (p_Var4 != (_func_10 *)0x0) {
        SpuSetKey(0,(uint)p_Var4);
      }
      SpuSetReverbVoice(1,(uint)p_Gpffff9224->loopSequencePosition[0x39]);
      SpuSetReverbVoice(0,~(uint)p_Gpffff9224->loopSequencePosition[0x39]);
      if (p_Gpffff9224->loopSequencePosition[0x38] != (_func_10 *)0x0) {
        SpuSetKey(1,(uint)p_Gpffff9224->loopSequencePosition[0x38]);
        p_Gpffff9224->loopSequencePosition[0x38] = (_func_10 *)0x0;
      }
    }
    iVar9 = *(int *)&(p_Gpffff9224->tempo).ticksPerUpdate;
    if (iVar9 != 0) {
      volume_00 = (p_Gpffff9224->tempo).errorPerUpdate + iVar9;
      if (-1 < iVar9) {
        aadSetMasterVolume((int)p_Gpffff9224);
        return;
      }
      if ((int)volume_00 < (int)(p_Gpffff9224->tempo).quarterNoteTime) {
        volume_00 = (p_Gpffff9224->tempo).quarterNoteTime;
        pcVar7 = (code *)p_Gpffff9224->eventQueue[0].deltaTime;
        *(undefined4 *)&(p_Gpffff9224->tempo).ticksPerUpdate = 0;
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)();
        }
      }
      aadSetMasterVolume(volume_00);
    }
    iVar9 = *(int *)&p_Gpffff9224->eventQueue[1].track;
    if ((iVar9 != 0) && (bVar3 = false, ((p_Gpffff9224->tempo).currentTick & 1) == 0)) {
      volume = *(int *)(p_Gpffff9224->eventQueue[0].dataByte + 2) + iVar9;
      if (iVar9 < 0) {
        bVar3 = volume <= *(int *)(p_Gpffff9224->eventQueue[1].dataByte + 2);
      }
      else {
        if (*(int *)(p_Gpffff9224->eventQueue[1].dataByte + 2) <= volume) {
          bVar3 = true;
        }
      }
      if (bVar3) {
        volume = *(int *)(p_Gpffff9224->eventQueue[1].dataByte + 2);
        pcVar7 = (code *)p_Gpffff9224->eventQueue[2].deltaTime;
        *(undefined4 *)&p_Gpffff9224->eventQueue[1].track = 0;
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)();
        }
      }
      aadSetMusicMasterVolume(volume);
    }
    (p_Gpffff9224->tempo).currentTick = (p_Gpffff9224->tempo).currentTick + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadCreateFourCharID(char a /*$a0*/, char b /*$a1*/, char c /*$a2*/, char d /*$a3*/)
 // line 636, offset 0x80051f38
	/* begin block 1 */
		// Start line: 1512
	/* end block 1 */
	// End Line: 1513

	/* begin block 2 */
		// Start line: 1513
	/* end block 2 */
	// End Line: 1514

ulong aadCreateFourCharID(char a,char b,char c,char d)

{
  return CONCAT13(a,CONCAT12(b,CONCAT11(c,d)));
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadLoadDynamicSoundBank(char *sndFileName /*$s3*/, char *smpFileName /*$s4*/, int dynamicBankIndex /*$s2*/, int loadOption /*$s5*/, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc /*stack 16*/)
 // line 644, offset 0x80051f60
	/* begin block 1 */
		// Start line: 645
		// Start offset: 0x80051F60
		// Variables:
	// 		int i; // $a0
	// 		struct AadDynamicBankLoadInfo *info; // $s1
	/* end block 1 */
	// End offset: 0x80052094
	// End Line: 699

	/* begin block 2 */
		// Start line: 1528
	/* end block 2 */
	// End Line: 1529

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
 // line 704, offset 0x800520b8
	/* begin block 1 */
		// Start line: 705
		// Start offset: 0x800520B8
		// Variables:
	// 		int dynamicBankIndex; // $s1
	// 		int error; // $s0
	/* end block 1 */
	// End offset: 0x8005216C
	// End Line: 772

	/* begin block 2 */
		// Start line: 1693
	/* end block 2 */
	// End Line: 1694

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
 // line 782, offset 0x80052188
	/* begin block 1 */
		// Start line: 783
		// Start offset: 0x80052188
		// Variables:
	// 		unsigned char *dataPtr; // $s1
	// 		struct AadDynamicBankLoadInfo *info; // $s0
	// 		int dynamicBankIndex; // $s3
	// 		int error; // $v0

		/* begin block 1.1 */
			// Start line: 866
			// Start offset: 0x800522FC
			// Variables:
		// 		int i; // $a2
		/* end block 1.1 */
		// End offset: 0x80052390
		// End Line: 880
	/* end block 1 */
	// End offset: 0x80052390
	// End Line: 882

	/* begin block 2 */
		// Start line: 1851
	/* end block 2 */
	// End Line: 1852

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
    SpuWrite((undefined2 *)loadedDataPtr,(undefined *)loadedDataSize,uVar5);
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
 // line 900, offset 0x800523b4
	/* begin block 1 */
		// Start line: 2119
	/* end block 1 */
	// End Line: 2120

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
 // line 930, offset 0x80052430
	/* begin block 1 */
		// Start line: 931
		// Start offset: 0x80052430
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
	// End offset: 0x8005253C
	// End Line: 979

	/* begin block 2 */
		// Start line: 2186
	/* end block 2 */
	// End Line: 2187

int aadOpenDynamicSoundBank(uchar *soundBank,int dynamicBankIndex)

{
  undefined *puVar1;
  ulong uVar2;
  uchar *puVar3;
  ulong *dynamicBankIndex_00;
  int iVar4;
  int *piVar5;
  int *sndFileName;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  TDRFuncPtr_aadLoadDynamicSoundBank4retProc local_10;
  
  if (dynamicBankIndex < 2) {
    uVar2 = aadCreateFourCharID('a','S','N','D');
    puVar1 = &DAT_00001001;
    if ((*(ulong *)soundBank == uVar2) && (puVar1 = &DAT_00001002, *(int *)(soundBank + 8) == 0x106)
       ) {
      iVar4 = *(int *)(soundBank + 0xc);
      iVar8 = *(int *)(soundBank + 0x10);
      iVar9 = *(int *)(soundBank + 0x14);
      iVar6 = *(int *)(soundBank + 0x18);
      iVar10 = *(int *)(soundBank + 0x1c);
      dynamicBankIndex_00 = &aadMem->updateCounter + dynamicBankIndex;
      puVar3 = soundBank + *(int *)(soundBank + 4);
      *(uchar **)(dynamicBankIndex_00 + 0x136) = puVar3;
      puVar3 = puVar3 + iVar4 * 8;
      *(uchar **)(dynamicBankIndex_00 + 0x138) = puVar3;
      piVar5 = (int *)(puVar3 + iVar8 * 0x10 + iVar9 * 4);
      piVar7 = piVar5 + iVar6;
      *(uchar **)(dynamicBankIndex_00 + 0x134) = soundBank;
      *(uchar **)(dynamicBankIndex_00 + 0x13a) = puVar3 + iVar8 * 0x10;
      *(int **)(dynamicBankIndex_00 + 0x13c) = piVar5;
      *(int **)(dynamicBankIndex_00 + 0x13e) = piVar7;
      if (0 < *(int *)(soundBank + 0x18)) {
        sndFileName = (int *)dynamicBankIndex_00[0x13c];
        *sndFileName = (int)(piVar7 + iVar10) + *piVar5;
        if (1 < *(int *)(soundBank + 0x18)) {
          iVar4 = aadLoadDynamicSoundBank
                            ((char *)sndFileName,(char *)(piVar5 + 1),(int)dynamicBankIndex_00,
                             (int)(piVar7 + iVar10),local_10);
          return iVar4;
        }
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
 // line 996, offset 0x80052550
	/* begin block 1 */
		// Start line: 997
		// Start offset: 0x80052550
		// Variables:
	// 		struct AadDynamicLoadRequest *loadReq; // $s0
	/* end block 1 */
	// End offset: 0x800525F4
	// End Line: 1020

	/* begin block 2 */
		// Start line: 2390
	/* end block 2 */
	// End Line: 2391

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
 // line 1046, offset 0x80052604
	/* begin block 1 */
		// Start line: 1048
		// Start offset: 0x80052604
		// Variables:
	// 		struct AadDynamicLoadRequest *loadReq; // $a1
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x800526D8
	// End Line: 1079

	/* begin block 2 */
		// Start line: 2516
	/* end block 2 */
	// End Line: 2517

	/* begin block 3 */
		// Start line: 2517
	/* end block 3 */
	// End Line: 2518

	/* begin block 4 */
		// Start line: 2524
	/* end block 4 */
	// End Line: 2525

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
 // line 1123, offset 0x800526e0
	/* begin block 1 */
		// Start line: 2692
	/* end block 1 */
	// End Line: 2693

	/* begin block 2 */
		// Start line: 2694
	/* end block 2 */
	// End Line: 2695

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadRelocateMusicMemoryBegin(void)

{
  aadMem->flags = aadMem->flags | 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadRelocateMusicMemoryEnd(struct MemHeader *newAddress /*$t9*/, long offset /*$a1*/, void *oldAddress /*$a2*/)
 // line 1132, offset 0x800526fc
	/* begin block 1 */
		// Start line: 1133
		// Start offset: 0x800526FC
		// Variables:
	// 		int bank; // $t7

		/* begin block 1.1 */
			// Start line: 1141
			// Start offset: 0x8005271C
			// Variables:
		// 		int slotNumber; // $t5
		// 		int i; // $a3
		// 		struct AadSoundBankHdr *bankHdr; // $a0

			/* begin block 1.1.1 */
				// Start line: 1160
				// Start offset: 0x800527C4
				// Variables:
			// 		struct _AadSequenceSlot *slot; // $t3

				/* begin block 1.1.1.1 */
					// Start line: 1163
					// Start offset: 0x800527EC
					// Variables:
				// 		int track; // $t1
				/* end block 1.1.1.1 */
				// End offset: 0x80052860
				// End Line: 1179
			/* end block 1.1.1 */
			// End offset: 0x80052860
			// End Line: 1180
		/* end block 1.1 */
		// End offset: 0x8005287C
		// End Line: 1183

		/* begin block 1.2 */
			// Start line: 1186
			// Start offset: 0x8005288C
			// Variables:
		// 		struct AadSynthVoice *voice; // $a0
		// 		int i; // $t0
		// 		long dataSize; // $v0
		/* end block 1.2 */
		// End offset: 0x80052908
		// End Line: 1205
	/* end block 1 */
	// End offset: 0x80052908
	// End Line: 1207

	/* begin block 2 */
		// Start line: 2710
	/* end block 2 */
	// End Line: 2711

void aadRelocateMusicMemoryEnd(MemHeader *newAddress,long offset,void *oldAddress)

{
  AadMemoryStruct *pAVar1;
  void *pvVar2;
  _func_37 *p_Var3;
  int iVar4;
  int iVar5;
  int iVar6;
  AadMemoryStruct *pAVar7;
  _func_36 *p_Var8;
  int iVar9;
  void *pvVar10;
  _func_36 *p_Var11;
  int iVar12;
  int iVar13;
  
  pAVar1 = aadMem;
  iVar13 = 0;
  pAVar7 = aadMem;
  while ((_func_43 *)oldAddress != pAVar7->dynamicSoundBankData[0]) {
    iVar13 = iVar13 + 1;
    pAVar7 = (AadMemoryStruct *)&pAVar7->numSlots;
    if (1 < iVar13) goto LAB_80052890;
  }
  pAVar7->dynamicSoundBankData[0] = (_func_43 *)((int)oldAddress + offset);
  pAVar7->dynamicProgramAtr[0] = pAVar7->dynamicProgramAtr[0] + offset;
  pAVar7->dynamicToneAtr[0] = pAVar7->dynamicToneAtr[0] + offset;
  p_Var3 = pAVar7->dynamicSoundBankHdr[0] + offset;
  pAVar7->dynamicSoundBankHdr[0] = p_Var3;
  pAVar7->dynamicWaveAddr[0] = pAVar7->dynamicWaveAddr[0] + offset;
  pAVar7->dynamicSequenceAddressTbl[0] =
       (_func_41 **)((int)pAVar7->dynamicSequenceAddressTbl[0] + offset);
  iVar5 = 0;
  if (0 < *(int *)(p_Var3 + 0x18)) {
    do {
      pAVar7->dynamicSequenceAddressTbl[0][iVar5] =
           pAVar7->dynamicSequenceAddressTbl[0][iVar5] + offset;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(p_Var3 + 0x18));
  }
  pAVar7->dynamicSequenceLabelOffsetTbl[0] = pAVar7->dynamicSequenceLabelOffsetTbl[0] + offset;
  iVar5 = 0;
  pAVar7 = pAVar1;
  if (0 < pAVar1->numSlots) {
    do {
      p_Var11 = pAVar7->sequenceSlots[0];
      if ((p_Var11[0x53e] != (_func_36)0xff) && (*(int *)(p_Var11 + 0x55c) == iVar13)) {
        iVar9 = 0;
        iVar12 = 0;
        p_Var8 = p_Var11;
        do {
          if (*(int *)(p_Var8 + 0x348) != 0) {
            *(int *)(p_Var8 + 0x348) = *(int *)(p_Var8 + 0x348) + offset;
            iVar6 = 0;
            iVar4 = iVar12;
            if ((p_Var11 + iVar9)[0x4e8] != (_func_36)0x0) {
              do {
                *(int *)(p_Var11 + iVar4 + 1000) = *(int *)(p_Var11 + iVar4 + 1000) + offset;
                iVar6 = iVar6 + 1;
                iVar4 = iVar4 + 0x40;
              } while (iVar6 < (int)(uint)(byte)(p_Var11 + iVar9)[0x4e8]);
            }
          }
          iVar12 = iVar12 + 4;
          iVar9 = iVar9 + 1;
          p_Var8 = p_Var8 + 4;
        } while (iVar9 < 0x10);
      }
      iVar5 = iVar5 + 1;
      pAVar7 = (AadMemoryStruct *)&pAVar7->numSlots;
    } while (iVar5 < pAVar1->numSlots);
  }
LAB_80052890:
  pAVar1 = aadMem;
  iVar5 = 0;
  iVar13 = 0x1dc;
  pvVar10 = (void *)((int)oldAddress + (newAddress->memSize - 8));
  do {
    iVar9 = (int)&pAVar1->updateCounter + iVar13;
    if (-1 < *(char *)(iVar9 + 8)) {
      pvVar2 = *(void **)(iVar9 + 0x14);
      if ((oldAddress <= pvVar2) && (pvVar2 < pvVar10)) {
        *(int *)(iVar9 + 0x14) = (int)pvVar2 + offset;
      }
      pvVar2 = *(void **)(iVar9 + 0x18);
      if ((oldAddress <= pvVar2) && (pvVar2 < pvVar10)) {
        *(int *)(iVar9 + 0x18) = (int)pvVar2 + offset;
      }
    }
    iVar5 = iVar5 + 1;
    iVar13 = iVar13 + 0x1c;
  } while (iVar5 < 0x18);
  aadMem->flags = aadMem->flags & 0xfffffffd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadRelocateSfxMemory(void *oldAddress /*$a0*/, int offset /*$a1*/)
 // line 1217, offset 0x80052924
	/* begin block 1 */
		// Start line: 1219
		// Start offset: 0x80052924
		// Variables:
	// 		struct _AadDynSfxFileHdr *snfFile; // $v1
	/* end block 1 */
	// End offset: 0x80052984
	// End Line: 1254

	/* begin block 2 */
		// Start line: 2982
	/* end block 2 */
	// End Line: 2983

	/* begin block 3 */
		// Start line: 2983
	/* end block 3 */
	// End Line: 2984

	/* begin block 4 */
		// Start line: 2988
	/* end block 4 */
	// End Line: 2989

void aadRelocateSfxMemory(void *oldAddress,int offset)

{
  _AadDynSfxFileHdr *p_Var1;
  
  p_Var1 = aadMem->firstDynSfxFile;
  if ((_AadDynSfxFileHdr *)oldAddress == p_Var1) {
    p_Var1 = (_AadDynSfxFileHdr *)((int)&p_Var1->snfID + offset);
    aadMem->firstDynSfxFile = p_Var1;
  }
  while( true ) {
    if (p_Var1 == (_AadDynSfxFileHdr *)0x0) {
      return;
    }
    if ((_AadDynSfxFileHdr *)oldAddress != p_Var1->prevDynSfxFile) break;
    p_Var1->prevDynSfxFile = (_AadDynSfxFileHdr *)((int)oldAddress + offset);
    if ((_AadDynSfxFileHdr *)oldAddress == p_Var1->nextDynSfxFile) {
      p_Var1->nextDynSfxFile = (_AadDynSfxFileHdr *)((int)oldAddress + offset);
    }
    p_Var1 = p_Var1->nextDynSfxFile;
  }
  aadFreeDynamicSoundBank((int)oldAddress);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetNumLoadsQueued()
 // line 1257, offset 0x8005298c
	/* begin block 1 */
		// Start line: 3062
	/* end block 1 */
	// End Line: 3063

	/* begin block 2 */
		// Start line: 3064
	/* end block 2 */
	// End Line: 3065

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetNumLoadsQueued(void)

{
  return aadMem->numLoadReqsQueued;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPurgeLoadQueue()
 // line 1265, offset 0x800529a0
	/* begin block 1 */
		// Start line: 3078
	/* end block 1 */
	// End Line: 3079

	/* begin block 2 */
		// Start line: 3080
	/* end block 2 */
	// End Line: 3081

void aadPurgeLoadQueue(void)

{
  *(undefined4 *)(iGpffff9224 + 0x740) = 0;
  *(undefined4 *)(iGpffff9224 + 0x744) = 0;
  *(undefined4 *)(iGpffff9224 + 0x748) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadProcessLoadQueue()
 // line 1277, offset 0x800529b8
	/* begin block 1 */
		// Start line: 1278
		// Start offset: 0x800529B8
		// Variables:
	// 		struct AadDynamicSfxLoadInfo *info; // $s0
	// 		int i; // $a0
	// 		char *p; // $v0

		/* begin block 1.1 */
			// Start line: 1303
			// Start offset: 0x80052A40
			// Variables:
		// 		struct AadDynamicLoadRequest *loadReq; // $s2

			/* begin block 1.1.1 */
				// Start line: 1314
				// Start offset: 0x80052A90
				// Variables:
			// 		char areaName[12]; // stack offset -32

				/* begin block 1.1.1.1 */
					// Start line: 1335
					// Start offset: 0x80052ACC
				/* end block 1.1.1.1 */
				// End offset: 0x80052ACC
				// End Line: 1335

				/* begin block 1.1.1.2 */
					// Start line: 1340
					// Start offset: 0x80052AF8
				/* end block 1.1.1.2 */
				// End offset: 0x80052B28
				// End Line: 1342
			/* end block 1.1.1 */
			// End offset: 0x80052BB0
			// End Line: 1361

			/* begin block 1.1.2 */
				// Start line: 1366
				// Start offset: 0x80052BC0
				// Variables:
			// 		int i; // $s2
			// 		struct _AadDynSfxFileHdr *snfFile; // $s1
			// 		unsigned short *sfxIDListPtr; // $v1
			/* end block 1.1.2 */
			// End offset: 0x80052C98
			// End Line: 1398
		/* end block 1.1 */
		// End offset: 0x80052CAC
		// End Line: 1406
	/* end block 1 */
	// End offset: 0x80052CE0
	// End Line: 1414

	/* begin block 2 */
		// Start line: 3102
	/* end block 2 */
	// End Line: 3103

	/* begin block 3 */
		// Start line: 3114
	/* end block 3 */
	// End Line: 3115

void aadLoadDynamicSoundBankReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  int *piVar7;
  char acStack32 [16];
  
  iVar3 = loadFromHead;
  iVar4 = 0;
  iVar5 = loadFromHead;
  if ((*(uint *)(loadFromHead + 0x7a8) & 1) != 0) {
    return;
  }
  do {
    iVar4 = iVar4 + 1;
    if (*(int *)(iVar5 + 0x500) == 1) {
      return;
    }
    iVar5 = iVar5 + 4;
  } while (iVar4 < 2);
  if ((*(int *)(loadFromHead + 0x748) == 0) || (*(int *)(loadFromHead + 0x7e8) != 0)) {
LAB_80052cac:
    if (loadCanFail == 0) goto LAB_80052cd8;
  }
  else {
    if (loadCanFail == 0) {
      iVar5 = *(int *)(loadFromHead + 0x744);
      piVar1 = (int *)(loadFromHead + 0x748);
      *(uint *)(loadFromHead + 0x744) = iVar5 + 1U & 0xf;
      piVar7 = (int *)(iVar3 + iVar5 * 0x1c + 0x518);
      *(int *)(iVar3 + 0x748) = *piVar1 + -1;
      iVar5 = *piVar7;
      if (iVar5 == 1) {
        iVar3 = *(int *)(iVar3 + 0x7e0);
        if (iVar3 != 0) {
LAB_80052bd0:
          if ((uint)*(ushort *)(iVar3 + 8) != piVar7[1]) goto LAB_80052c88;
          iVar5 = 0;
          puVar6 = (ushort *)(iVar3 + 0x14);
          if (*(short *)(iVar3 + 10) != 0) {
            do {
              uVar2 = *puVar6;
              puVar6 = puVar6 + 1;
              aadFreeSingleDynSfx((uint)uVar2);
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)(uint)*(ushort *)(iVar3 + 10));
          }
          if (*(int *)(iVar3 + 0xc) == 0) {
            *(undefined4 *)(loadFromHead + 0x7e0) = *(undefined4 *)(iVar3 + 0x10);
          }
          else {
            *(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x10) = *(undefined4 *)(iVar3 + 0x10);
          }
          if (*(int *)(iVar3 + 0x10) != 0) {
            *(undefined4 *)(*(int *)(iVar3 + 0x10) + 0xc) = *(undefined4 *)(iVar3 + 0xc);
          }
          (**(code **)(loadFromHead + 0x73c))(iVar3);
          SignalInfo_800cf28c._4_4_ = 0;
        }
LAB_80052c98:
        iVar3 = aadCheckSramFragmented();
        if (iVar3 != 0) {
          loadCanFail = 1;
        }
      }
      else {
        if ((iVar5 < 2) && (iVar5 == 0)) {
                    /* WARNING: Subroutine does not return */
          strcpy(acStack32,(char *)(piVar7 + 4));
        }
      }
      goto LAB_80052cac;
    }
  }
  iVar3 = SOUND_IsMusicLoading();
  if (iVar3 == 0) {
    loadCanFail = 0;
    *(undefined4 *)(loadFromHead + 0x7e8) = 1;
  }
LAB_80052cd8:
  aadProcessSramDefrag();
  return;
LAB_80052c88:
  iVar3 = *(int *)(iVar3 + 0x10);
  if (iVar3 == 0) goto LAB_80052c98;
  goto LAB_80052bd0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info /*$s0*/, int error /*$a1*/)
 // line 1417, offset 0x80052cf8
	/* begin block 1 */
		// Start line: 3422
	/* end block 1 */
	// End Line: 3423

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
 // line 1443, offset 0x80052d7c
	/* begin block 1 */
		// Start line: 3474
	/* end block 1 */
	// End Line: 3475

	/* begin block 2 */
		// Start line: 3476
	/* end block 2 */
	// End Line: 3477

void aadLoadDynamicSfxDone(AadDynamicSfxLoadInfo *info)

{
  info->flags = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxReturn(void *loadedDataPtr /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 1458, offset 0x80052d84
	/* begin block 1 */
		// Start line: 1459
		// Start offset: 0x80052D84
		// Variables:
	// 		struct _AadDynSfxFileHdr *p; // $v1
	// 		struct AadDynamicSfxLoadInfo *info; // $s0
	/* end block 1 */
	// End offset: 0x80052EE8
	// End Line: 1546

	/* begin block 2 */
		// Start line: 3504
	/* end block 2 */
	// End Line: 3505

void aadLoadDynamicSfxReturn(_AadDynSfxFileHdr *param_1,AadDynamicSfxLoadInfo *param_2)

{
  ulong uVar1;
  _AadDynSfxFileHdr *p_Var2;
  _AadDynSfxFileHdr *p_Var3;
  
  p_Var3 = param_2->snfFile;
  if ((p_Var3 == (_AadDynSfxFileHdr *)0x0) || (p_Var3 != param_1)) {
    aadLoadDynamicSfxAbort(param_2,(int)&DAT_0000100e);
    aadProcessLoadQueue();
    return;
  }
  uVar1 = aadCreateFourCharID('a','S','N','F');
  if ((p_Var3->snfID == uVar1) && (param_2->snfFile->snfVersion == 0x100)) {
    param_2->snfFile->handle = *(ushort *)&param_2->fileHandle;
    p_Var3 = *(_AadDynSfxFileHdr **)(iGpffff9224 + 0x7e0);
    if (p_Var3 == (_AadDynSfxFileHdr *)0x0) {
      *(_AadDynSfxFileHdr **)(iGpffff9224 + 0x7e0) = param_2->snfFile;
      param_2->snfFile->prevDynSfxFile = (_AadDynSfxFileHdr *)0x0;
    }
    else {
      p_Var2 = p_Var3->nextDynSfxFile;
      while (p_Var2 != (_AadDynSfxFileHdr *)0x0) {
        p_Var3 = p_Var3->nextDynSfxFile;
        p_Var2 = p_Var3->nextDynSfxFile;
      }
      p_Var3->nextDynSfxFile = param_2->snfFile;
      param_2->snfFile->prevDynSfxFile = p_Var3;
    }
    param_2->snfFile->nextDynSfxFile = (_AadDynSfxFileHdr *)0x0;
    param_2->smfLoadingState = 0;
    param_2->flags = param_2->flags | 2;
    if (param_2->directoryID == 0) {
      (**(code **)(iGpffff9224 + 0x734))(param_2->smfFileName,aadLoadDynamicSfxReturn2,param_2,0);
      if (param_2->directoryID != 0) {
                    /* WARNING: Subroutine does not return */
        LOAD_SetSearchDirectory(0);
      }
      aadProcessLoadQueue();
      return;
    }
                    /* WARNING: Subroutine does not return */
    LOAD_SetSearchDirectory(param_2->directoryID);
  }
  aadLoadDynamicSfxAbort(param_2,(int)&DAT_0000100b);
  aadProcessLoadQueue();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadWaveMalloc(unsigned short waveID /*$t6*/, unsigned long waveSize /*$a1*/)
 // line 1561, offset 0x80052efc
	/* begin block 1 */
		// Start line: 1562
		// Start offset: 0x80052EFC
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
	// End offset: 0x8005313C
	// End Line: 1665

	/* begin block 2 */
		// Start line: 3724
	/* end block 2 */
	// End Line: 3725

	/* begin block 3 */
		// Start line: 3734
	/* end block 3 */
	// End Line: 3735

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
 // line 1669, offset 0x80053144
	/* begin block 1 */
		// Start line: 1671
		// Start offset: 0x80053144
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $v1
	/* end block 1 */
	// End offset: 0x80053168
	// End Line: 1681

	/* begin block 2 */
		// Start line: 3969
	/* end block 2 */
	// End Line: 3970

	/* begin block 3 */
		// Start line: 3970
	/* end block 3 */
	// End Line: 3971

	/* begin block 4 */
		// Start line: 3972
	/* end block 4 */
	// End Line: 3973

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
 // line 1702, offset 0x80053170
	/* begin block 1 */
		// Start line: 1704
		// Start offset: 0x80053170
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $a1
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $a3

		/* begin block 1.1 */
			// Start line: 1715
			// Start offset: 0x800531A0
			// Variables:
		// 		struct AadNewSramBlockDesc *next; // $a2
		/* end block 1.1 */
		// End offset: 0x80053204
		// End Line: 1724

		/* begin block 1.2 */
			// Start line: 1728
			// Start offset: 0x80053214
			// Variables:
		// 		struct AadNewSramBlockDesc *prev; // $a0
		/* end block 1.2 */
		// End offset: 0x80053278
		// End Line: 1737
	/* end block 1 */
	// End offset: 0x80053278
	// End Line: 1740

	/* begin block 2 */
		// Start line: 3404
	/* end block 2 */
	// End Line: 3405

	/* begin block 3 */
		// Start line: 4019
	/* end block 3 */
	// End Line: 4020

	/* begin block 4 */
		// Start line: 4022
	/* end block 4 */
	// End Line: 4023

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
 // line 1744, offset 0x80053280
	/* begin block 1 */
		// Start line: 1745
		// Start offset: 0x80053280
		// Variables:
	// 		int ti; // $v1
	// 		int wi; // $v1
	// 		struct AadLoadedSfxToneAttr *toneAttr; // $a1
	// 		struct AadLoadedSfxWaveAttr *waveAttr; // $v1
	/* end block 1 */
	// End offset: 0x80053338
	// End Line: 1770

	/* begin block 2 */
		// Start line: 4106
	/* end block 2 */
	// End Line: 4107

	/* begin block 3 */
		// Start line: 4111
	/* end block 3 */
	// End Line: 4112

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
 // line 1773, offset 0x80053348
	/* begin block 1 */
		// Start line: 1775
		// Start offset: 0x80053348
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
	// End offset: 0x800533F4
	// End Line: 1812

	/* begin block 2 */
		// Start line: 4169
	/* end block 2 */
	// End Line: 4170

	/* begin block 3 */
		// Start line: 4170
	/* end block 3 */
	// End Line: 4171

	/* begin block 4 */
		// Start line: 4184
	/* end block 4 */
	// End Line: 4185

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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
  _gSramFreeBlocks = 0;
  _gSramUsedBlocks = 0;
  pAVar2 = aadMem->sramDescriptorTbl + aadMem->firstSramBlockDescIndex;
  iVar3 = 0x80;
  do {
    if (pAVar2 == (AadNewSramBlockDesc *)0x0) break;
    if ((pAVar2->waveID & 0x4000) == 0) {
      uVar1 = (uint)pAVar2->size;
      _gSramFreeBlocks = _gSramFreeBlocks + 1;
      iVar5 = iVar5 + uVar1;
      if (uVar6 < uVar1) {
        uVar6 = uVar1;
      }
    }
    else {
      _gSramUsedBlocks = _gSramUsedBlocks + 1;
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
  theCamera.savedCinematic[1]._16_4_ = uVar6 << 3;
  _gSramTotalUsed = iVar4 << 3;
  _gSramTotalFree = iVar5 << 3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info /*$s2*/)
 // line 1829, offset 0x80053424
	/* begin block 1 */
		// Start line: 1830
		// Start offset: 0x80053424
		// Variables:
	// 		int i; // $a0
	// 		struct AadLoadedSfxToneAttr *toneAttr; // $a1
	// 		struct AadLoadedSfxWaveAttr *waveAttr; // $s0
	// 		struct AadDynSfxAttr *attr; // $s1
	/* end block 1 */
	// End offset: 0x800536DC
	// End Line: 1943

	/* begin block 2 */
		// Start line: 4288
	/* end block 2 */
	// End Line: 4289

	/* begin block 3 */
		// Start line: 4297
	/* end block 3 */
	// End Line: 4298

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
        goto LAB_800536d0;
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
LAB_800536d0:
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
 // line 1958, offset 0x800536f4
	/* begin block 1 */
		// Start line: 4622
	/* end block 1 */
	// End Line: 4623

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HackCallback(void)

{
  SpuSetTransferCallback(0);
  aadLoadDynamicSfxReturn2
            (fontTracker.font_buffer[83]._2_4_,fontTracker.font_buffer[84]._0_4_,0,
             fontTracker.font_buffer._508_4_,(void *)0x0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxReturn2(void *loadedDataPtr /*$a0*/, long loadedDataSize /*$a1*/, short status /*$a2*/, void *data1 /*$a3*/, void *data2 /*stack 16*/)
 // line 1967, offset 0x8005372c
	/* begin block 1 */
		// Start line: 1968
		// Start offset: 0x8005372C
		// Variables:
	// 		unsigned char *dataPtr; // $s4
	// 		unsigned long dataOffset; // $s3
	// 		unsigned long bytesRemaining; // $s2
	// 		struct AadDynamicSfxLoadInfo *info; // $s1
	// 		unsigned long n; // $s0
	/* end block 1 */
	// End offset: 0x800539CC
	// End Line: 2120

	/* begin block 2 */
		// Start line: 4640
	/* end block 2 */
	// End Line: 4641

void aadLoadDynamicSfxReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  int iVar1;
  void *__src;
  undefined2 in_register_0000001a;
  undefined *puVar2;
  undefined *__n;
  undefined *puVar3;
  
  puVar2 = (undefined *)CONCAT22(in_register_0000001a,status);
  puVar3 = (undefined *)0x0;
  if (loadedDataSize != 0) {
    do {
      iVar1 = *(int *)((int)data1 + 0x60);
      if (iVar1 == 1) {
        __src = (void *)((int)loadedDataPtr + (int)puVar3);
        __n = *(undefined **)((int)data1 + 100);
        if ((uint)loadedDataSize < *(undefined **)((int)data1 + 100)) {
          __n = (undefined *)loadedDataSize;
        }
        puVar3 = __n + (int)puVar3;
        puVar2 = __n;
        memcpy((void *)((int)data1 - (*(int *)((int)data1 + 100) + -0x94)),__src,(size_t)__n);
        loadedDataSize = (long)((undefined *)loadedDataSize + -(int)__n);
        iVar1 = *(int *)((int)data1 + 100) - (int)__n;
        *(int *)((int)data1 + 100) = iVar1;
        if (iVar1 == 0) {
          aadLoadSingleDynSfx((AadDynamicSfxLoadInfo *)data1);
          *(undefined4 *)((int)data1 + 100) = *(undefined4 *)((int)data1 + 0x90);
        }
      }
      else {
        if (iVar1 < 2) {
          if (iVar1 == 0) {
            aadFreeSingleDynSfx(0x61);
            return;
          }
        }
        else {
          if (iVar1 == 2) {
            __n = *(undefined **)((int)data1 + 100);
            if ((uint)loadedDataSize < *(undefined **)((int)data1 + 100)) {
              __n = (undefined *)loadedDataSize;
            }
            puVar3 = __n + (int)puVar3;
            loadedDataSize = (long)((undefined *)loadedDataSize + -(int)__n);
            iVar1 = *(int *)((int)data1 + 100) - (int)__n;
            *(int *)((int)data1 + 100) = iVar1;
            if (iVar1 == 0) {
              iVar1 = *(int *)((int)data1 + 0x68) + -1;
              *(int *)((int)data1 + 0x68) = iVar1;
              if (iVar1 == 0) {
LAB_80053988:
                aadLoadDynamicSfxDone((AadDynamicSfxLoadInfo *)data1);
                return;
              }
              *(undefined4 *)((int)data1 + 0x60) = 1;
              *(undefined4 *)((int)data1 + 100) = 0x18;
            }
          }
          else {
            if (iVar1 == 3) {
              __n = *(undefined **)((int)data1 + 100);
              if ((uint)loadedDataSize < *(undefined **)((int)data1 + 100)) {
                __n = (undefined *)loadedDataSize;
              }
              loadedDataSize = (long)((undefined *)loadedDataSize + -(int)__n);
              aadWaitForSramTransferComplete();
              SpuSetTransferCallback((int)HackCallback);
              SpuSetTransferStartAddr(*(uint *)((int)data1 + 0x70));
              SpuWrite((undefined2 *)((int)loadedDataPtr + (int)puVar3),__n,(uint)puVar2);
              puVar3 = __n + (int)puVar3;
              iVar1 = *(int *)((int)data1 + 100) - (int)__n;
              *(undefined **)((int)data1 + 0x70) = __n + *(int *)((int)data1 + 0x70);
              *(int *)((int)data1 + 100) = iVar1;
              if (iVar1 == 0) {
                iVar1 = *(int *)((int)data1 + 0x68) + -1;
                *(int *)((int)data1 + 0x74) =
                     *(int *)((int)data1 + 0x74) + *(int *)((int)data1 + 0x90);
                *(int *)((int)data1 + 0x68) = iVar1;
                if (iVar1 == 0) {
                  SpuSetTransferCallback(0);
                  goto LAB_80053988;
                }
                *(undefined4 *)((int)data1 + 0x60) = 1;
                *(undefined4 *)((int)data1 + 100) = 0x18;
              }
              if ((undefined *)loadedDataSize != (undefined *)0x0) {
                fontTracker.font_buffer[83]._2_4_ = (int)loadedDataPtr + (int)puVar3;
                fontTracker.font_buffer[84]._0_4_ = (undefined *)loadedDataSize;
                fontTracker.font_buffer._508_4_ = data1;
                return;
              }
              SpuSetTransferCallback(0);
            }
          }
        }
      }
    } while ((undefined *)loadedDataSize != (undefined *)0x0);
  }
                    /* WARNING: Read-only address (ram,0x800d18ec) is written */
                    /* WARNING: Read-only address (ram,0x800d18f0) is written */
                    /* WARNING: Read-only address (ram,0x800d18f4) is written */
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadCheckSramFragmented()
 // line 2172, offset 0x800539f4
	/* begin block 1 */
		// Start line: 2174
		// Start offset: 0x800539F4
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $v1
	// 		struct AadNewSramBlockDesc *sramDesc; // $a1
	// 		long totalFree; // $t0
	// 		long smallestFree; // $t1
	// 		long numFreeBlocks; // $a3
	// 		int i; // $a2
	// 		int defragNeeded; // $v1
	/* end block 1 */
	// End offset: 0x80053AA0
	// End Line: 2216

	/* begin block 2 */
		// Start line: 5103
	/* end block 2 */
	// End Line: 5104

	/* begin block 3 */
		// Start line: 5104
	/* end block 3 */
	// End Line: 5105

	/* begin block 4 */
		// Start line: 5114
	/* end block 4 */
	// End Line: 5115

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
 // line 2235, offset 0x80053aa8
	/* begin block 1 */
		// Start line: 2236
		// Start offset: 0x80053AA8
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
			// Start line: 2338
			// Start offset: 0x80053C70
			// Variables:
		// 		struct AadNewSramBlockDesc *next; // $a0
		/* end block 1.1 */
		// End offset: 0x80053CD4
		// End Line: 2350
	/* end block 1 */
	// End offset: 0x80053DE4
	// End Line: 2428

	/* begin block 2 */
		// Start line: 5234
	/* end block 2 */
	// End Line: 5235

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
          SpuWrite((undefined2 *)(pAVar4->sramDefragInfo).fragBuffer,puVar10,in_a2);
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
 // line 2437, offset 0x80053e0c
	/* begin block 1 */
		// Start line: 4874
	/* end block 1 */
	// End Line: 4875

	/* begin block 2 */
		// Start line: 5664
	/* end block 2 */
	// End Line: 5665

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
 // line 2710, offset 0x80053e48
	/* begin block 1 */
		// Start line: 2711
		// Start offset: 0x80053E48
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $t0
	// 		unsigned long trackOffset; // $v0
	// 		int i; // $a1
	// 		int bank; // $a0
	/* end block 1 */
	// End offset: 0x80053F38
	// End Line: 2769

	/* begin block 2 */
		// Start line: 5946
	/* end block 2 */
	// End Line: 5947

	/* begin block 3 */
		// Start line: 6211
	/* end block 3 */
	// End Line: 6212

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
 // line 2779, offset 0x80053f54
	/* begin block 1 */
		// Start line: 2780
		// Start offset: 0x80053F54
		// Variables:
	// 		int n; // $s0
	/* end block 1 */
	// End offset: 0x80053F84
	// End Line: 2787

	/* begin block 2 */
		// Start line: 6438
	/* end block 2 */
	// End Line: 6439

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
 // line 2790, offset 0x80053f94
	/* begin block 1 */
		// Start line: 6461
	/* end block 1 */
	// End Line: 6462

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
  SpuSetReverbModeDepth((short)iVar2,(short)iVar3);
  SpuSetReverb(1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadShutdownReverb()
 // line 2806, offset 0x80054018
	/* begin block 1 */
		// Start line: 6493
	/* end block 1 */
	// End Line: 6494

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
 // line 2820, offset 0x80054050
	/* begin block 1 */
		// Start line: 6521
	/* end block 1 */
	// End Line: 6522

	/* begin block 2 */
		// Start line: 6522
	/* end block 2 */
	// End Line: 6523

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetReverbMode(void)

{
  return 3;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetReverbSize()
 // line 2842, offset 0x80054058
	/* begin block 1 */
		// Start line: 6565
	/* end block 1 */
	// End Line: 6566

/* WARNING: Unknown calling convention yet parameter storage is locked */

ulong aadGetReverbSize(void)

{
  int iVar1;
  
  iVar1 = aadGetReverbMode();
  return _spu_RXX[iVar1] + 0x40;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetReverbDepth()
 // line 2847, offset 0x80054088
	/* begin block 1 */
		// Start line: 6575
	/* end block 1 */
	// End Line: 6576

	/* begin block 2 */
		// Start line: 6576
	/* end block 2 */
	// End Line: 6577

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetReverbDepth(void)

{
  return (int)&DAT_00002710;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetNumDynamicSequences(int bank /*$a0*/)
 // line 2860, offset 0x80054090
	/* begin block 1 */
		// Start line: 5720
	/* end block 1 */
	// End Line: 5721

	/* begin block 2 */
		// Start line: 6592
	/* end block 2 */
	// End Line: 6593

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
 // line 2877, offset 0x800540c0
	/* begin block 1 */
		// Start line: 2878
		// Start offset: 0x800540C0
		// Variables:
	// 		struct AadTempo tempo; // stack offset -32
	// 		struct _AadSequenceSlot *slot; // $s0
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80054180
	// End Line: 2924

	/* begin block 2 */
		// Start line: 6623
	/* end block 2 */
	// End Line: 6624

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
    aadGetReverbSize();
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
 // line 2927, offset 0x8005419c
	/* begin block 1 */
		// Start line: 2929
		// Start offset: 0x8005419C
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $v1
	/* end block 1 */
	// End offset: 0x800541E4
	// End Line: 2942

	/* begin block 2 */
		// Start line: 6753
	/* end block 2 */
	// End Line: 6754

	/* begin block 3 */
		// Start line: 6754
	/* end block 3 */
	// End Line: 6755

	/* begin block 4 */
		// Start line: 6761
	/* end block 4 */
	// End Line: 6762

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
 // line 3061, offset 0x800541ec
	/* begin block 1 */
		// Start line: 3063
		// Start offset: 0x800541EC
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a0
	// 		unsigned long tickTime; // $v1
	// 		unsigned long tickTimeRemainder; // $a2
	/* end block 1 */
	// End offset: 0x800541EC
	// End Line: 3069

	/* begin block 2 */
		// Start line: 7021
	/* end block 2 */
	// End Line: 7022

	/* begin block 3 */
		// Start line: 7022
	/* end block 3 */
	// End Line: 7023

	/* begin block 4 */
		// Start line: 7028
	/* end block 4 */
	// End Line: 7029

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
  *(short *)(p_Var3 + 0x10) = (short)(aadUpdateRate[pAVar1->updateMode & 3] / uVar2);
  *(uint *)(p_Var3 + 0xc) = aadUpdateRate[pAVar1->updateMode & 3] % *(uint *)(p_Var3 + 8);
  *(ulong *)(p_Var3 + 0x14) = tempo->quarterNoteTime;
  *(undefined2 *)(p_Var3 + 0x12) = *(undefined2 *)&tempo->ppqn;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStartSlot(int slotNumber /*$a0*/)
 // line 3082, offset 0x800542a0
	/* begin block 1 */
		// Start line: 3083
		// Start offset: 0x800542A0
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s0
	/* end block 1 */
	// End offset: 0x8005430C
	// End Line: 3096

	/* begin block 2 */
		// Start line: 7068
	/* end block 2 */
	// End Line: 7069

	/* begin block 3 */
		// Start line: 7071
	/* end block 3 */
	// End Line: 7072

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
 // line 3099, offset 0x8005431c
	/* begin block 1 */
		// Start line: 3100
		// Start offset: 0x8005431C
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a0
	/* end block 1 */
	// End offset: 0x80054378
	// End Line: 3114

	/* begin block 2 */
		// Start line: 7105
	/* end block 2 */
	// End Line: 7106

	/* begin block 3 */
		// Start line: 7108
	/* end block 3 */
	// End Line: 7109

void aadStopSlot(int slotNumber)

{
  _AadSequenceSlot *slot;
  
  if (aadMem->numSlots <= slotNumber) {
    aadInitSequenceSlot((_AadSequenceSlot *)slotNumber);
    return;
  }
  slot = (_AadSequenceSlot *)aadMem->sequenceSlots[slotNumber];
  if (slot->sequenceNumberAssigned == -1) {
    aadInitSequenceSlot(slot);
    return;
  }
  slot->status = slot->status & 0xfffe;
  aadInitSequenceSlot(slot);
  aadGetReverbSize();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStopAllSlots()
 // line 3117, offset 0x80054388
	/* begin block 1 */
		// Start line: 3118
		// Start offset: 0x80054388
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s1
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x80054400
	// End Line: 3132

	/* begin block 2 */
		// Start line: 7147
	/* end block 2 */
	// End Line: 7148

	/* begin block 3 */
		// Start line: 7152
	/* end block 3 */
	// End Line: 7153

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
 // line 3135, offset 0x80054418
	/* begin block 1 */
		// Start line: 7194
	/* end block 1 */
	// End Line: 7195

	/* begin block 2 */
		// Start line: 7195
	/* end block 2 */
	// End Line: 7196

void aadDisableSlot(int slotNumber)

{
  if (slotNumber < aadMem->numSlots) {
    *(byte *)(aadMem->sequenceSlots[slotNumber] + 0x550) =
         (byte)aadMem->sequenceSlots[slotNumber][0x550] | 1;
    aadGetReverbSize();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadEnableSlot(int slotNumber /*$a0*/)
 // line 3146, offset 0x80054468
	/* begin block 1 */
		// Start line: 7217
	/* end block 1 */
	// End Line: 7218

	/* begin block 2 */
		// Start line: 7218
	/* end block 2 */
	// End Line: 7219

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
 // line 3154, offset 0x800544a8
	/* begin block 1 */
		// Start line: 7233
	/* end block 1 */
	// End Line: 7234

	/* begin block 2 */
		// Start line: 7234
	/* end block 2 */
	// End Line: 7235

void aadPauseSlot(int slotNumber)

{
  if (slotNumber < aadMem->numSlots) {
    *(ushort *)(aadMem->sequenceSlots[slotNumber] + 0x540) =
         *(ushort *)(aadMem->sequenceSlots[slotNumber] + 0x540) & 0xfffe;
    aadGetReverbSize();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadResumeSlot(int slotNumber /*$a0*/)
 // line 3165, offset 0x800544f8
	/* begin block 1 */
		// Start line: 3167
		// Start offset: 0x800544F8
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a1
	// 		int track; // $a0
	/* end block 1 */
	// End offset: 0x80054560
	// End Line: 3181

	/* begin block 2 */
		// Start line: 7256
	/* end block 2 */
	// End Line: 7257

	/* begin block 3 */
		// Start line: 7257
	/* end block 3 */
	// End Line: 7258

	/* begin block 4 */
		// Start line: 7260
	/* end block 4 */
	// End Line: 7261

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
 // line 3184, offset 0x80054568
	/* begin block 1 */
		// Start line: 7296
	/* end block 1 */
	// End Line: 7297

	/* begin block 2 */
		// Start line: 7297
	/* end block 2 */
	// End Line: 7298

int aadIsSfxLoaded(uint toneID)

{
  return (uint)*(ushort *)(*(int *)(loadFromHead + toneID * 4 + 0x34) + 0x540);
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadAllNotesOff(int slotNumber /*$a0*/)
 // line 3210, offset 0x80054588
	/* begin block 1 */
		// Start line: 3212
		// Start offset: 0x80054588
		// Variables:
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned long vmask; // $a1
	// 		int i; // $a3
	// 		struct _AadSequenceSlot *slot; // $t0
	/* end block 1 */
	// End offset: 0x80054620
	// End Line: 3235

	/* begin block 2 */
		// Start line: 6420
	/* end block 2 */
	// End Line: 6421

	/* begin block 3 */
		// Start line: 7324
	/* end block 3 */
	// End Line: 7325

	/* begin block 4 */
		// Start line: 7330
	/* end block 4 */
	// End Line: 7331

ulong aadGetReverbSize(void)

{
  int iVar1;
  ulong uVar2;
  int in_a0;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar4 = 0;
  iVar6 = 0;
  iVar5 = 0x1dc;
  iVar7 = *(int *)(DAT_800d07bc + in_a0 * 4 + 0x34);
  do {
    puVar3 = (uint *)(DAT_800d07bc + iVar5);
    if ((*(byte *)(puVar3 + 2) & 0xf0) == *(byte *)(iVar7 + 0x551)) {
      *(undefined *)(puVar3 + 2) = 0xff;
      uVar4 = uVar4 | *puVar3;
      *(ushort *)((int)puVar3 + 0x12) = *(ushort *)((int)puVar3 + 0x12) | 2;
    }
    iVar1 = DAT_800d07bc;
    iVar6 = iVar6 + 1;
    uVar2 = (ulong)(iVar6 < 0x18);
    iVar5 = iVar5 + 0x1c;
  } while (iVar6 < 0x18);
  if (uVar4 != 0) {
    *(uint *)(DAT_800d07bc + 0x4c4) = *(uint *)(DAT_800d07bc + 0x4c4) | uVar4;
    uVar2 = *(uint *)(iVar1 + 0x4c8) & ~uVar4;
    *(uint *)(iVar1 + 0x4c8) = uVar2;
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadMuteChannels(struct _AadSequenceSlot *slot /*$a0*/, unsigned long channelList /*$a1*/)
 // line 3252, offset 0x80054628
	/* begin block 1 */
		// Start line: 3254
		// Start offset: 0x80054628
		// Variables:
	// 		struct AadSynthVoice *voice; // $a2
	// 		unsigned long vmask; // $t2
	// 		unsigned long delayedMute; // $a2
	// 		int channel; // $t1
	// 		int i; // $t0
	/* end block 1 */
	// End offset: 0x800546FC
	// End Line: 3289

	/* begin block 2 */
		// Start line: 6504
	/* end block 2 */
	// End Line: 6505

	/* begin block 3 */
		// Start line: 7401
	/* end block 3 */
	// End Line: 7402

	/* begin block 4 */
		// Start line: 7406
	/* end block 4 */
	// End Line: 7407

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
 // line 3292, offset 0x80054704
	/* begin block 1 */
		// Start line: 3294
		// Start offset: 0x80054704
		// Variables:
	// 		unsigned long delayedUnMute; // $a2
	/* end block 1 */
	// End offset: 0x80054728
	// End Line: 3302

	/* begin block 2 */
		// Start line: 7494
	/* end block 2 */
	// End Line: 7495

	/* begin block 3 */
		// Start line: 7495
	/* end block 3 */
	// End Line: 7496

	/* begin block 4 */
		// Start line: 7498
	/* end block 4 */
	// End Line: 7499

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
 // line 3405, offset 0x8005473c
	/* begin block 1 */
		// Start line: 3407
		// Start offset: 0x8005473C
		// Variables:
	// 		void (*previousCallbackProc)(); // $v0
	/* end block 1 */
	// End offset: 0x8005473C
	// End Line: 3409

	/* begin block 2 */
		// Start line: 6810
	/* end block 2 */
	// End Line: 6811

	/* begin block 3 */
		// Start line: 7620
	/* end block 3 */
	// End Line: 7621

	/* begin block 4 */
		// Start line: 7622
	/* end block 4 */
	// End Line: 7623

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
 // line 3416, offset 0x80054754
	/* begin block 1 */
		// Start line: 7641
	/* end block 1 */
	// End Line: 7642

	/* begin block 2 */
		// Start line: 7643
	/* end block 2 */
	// End Line: 7644

void aadSetUserVariable(int variableNumber,int value)

{
  (&DAT_00001c08)[(int)&aadMem->updateCounter + variableNumber] = (char)value;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetNoUpdateMode(int noUpdate /*$a0*/)
 // line 3446, offset 0x80054768
	/* begin block 1 */
		// Start line: 6892
	/* end block 1 */
	// End Line: 6893

	/* begin block 2 */
		// Start line: 7675
	/* end block 2 */
	// End Line: 7676

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
 // line 3467, offset 0x800547a8
	/* begin block 1 */
		// Start line: 3468
		// Start offset: 0x800547A8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80054828
	// End Line: 3484

	/* begin block 2 */
		// Start line: 6934
	/* end block 2 */
	// End Line: 6935

	/* begin block 3 */
		// Start line: 7705
	/* end block 3 */
	// End Line: 7706

void aadPauseSound(void)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((*(uint *)(iGpffff9224 + 0x24) & 8) == 0) {
    *(uint *)(iGpffff9224 + 0x24) = *(uint *)(iGpffff9224 + 0x24) | 0xc;
    iVar3 = 0;
    iVar5 = 0x494;
    iVar4 = 0;
    do {
      puVar2 = (undefined2 *)(iGpffff9224 + iVar5);
      iVar5 = iVar5 + 2;
      iVar1 = iGpffff9224 + iVar4;
      iVar4 = iVar4 + 0x1c;
      *(ushort *)(iVar1 + 0x1ee) = *(ushort *)(iVar1 + 0x1ee) & 0xfffd;
      SpuGetVoicePitch(iVar3,puVar2);
      SpuSetVoicePitch(iVar3,0);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x18);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadCancelPauseSound()
 // line 3486, offset 0x80054840
	/* begin block 1 */
		// Start line: 7755
	/* end block 1 */
	// End Line: 7756

	/* begin block 2 */
		// Start line: 7757
	/* end block 2 */
	// End Line: 7758

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadCancelPauseSound(void)

{
  aadMem->flags = aadMem->flags & 0xfffffff3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadResumeSound()
 // line 3493, offset 0x8005485c
	/* begin block 1 */
		// Start line: 3494
		// Start offset: 0x8005485C
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x800548D4
	// End Line: 3509

	/* begin block 2 */
		// Start line: 7769
	/* end block 2 */
	// End Line: 7770

	/* begin block 3 */
		// Start line: 7773
	/* end block 3 */
	// End Line: 7774

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





