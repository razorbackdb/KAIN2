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

/* File: C:\kain2\game\PSX\AADLIB.C */

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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadInit(AadInitAttr *attributes,uchar *memoryPtr)

{
  byte bVar1;
  undefined *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  aadGp = GetGp();
  EnterCriticalSection();
  aadGetMemorySize(attributes);
  aadMem = memoryPtr;
  if (memoryPtr == (uchar *)0x0) {
    puVar2 = &DAT_00001009;
  }
  else {
    memset();
    puVar5 = aadMem;
    puVar2 = &DAT_00001008;
    if ((attributes->nonBlockLoadProc != (_func_32 *)0x0) &&
       (puVar2 = &DAT_00001008, attributes->nonBlockBufferedLoadProc != (_func_33 *)0x0)) {
      if (attributes->memoryMallocProc == (_func_34 *)0x0) {
        puVar2 = &DAT_00001008;
      }
      else {
        *(_func_32 **)(aadMem + 0x730) = attributes->nonBlockLoadProc;
        *(_func_33 **)(puVar5 + 0x734) = attributes->nonBlockBufferedLoadProc;
        *(_func_34 **)(puVar5 + 0x738) = attributes->memoryMallocProc;
        *(_func_35 **)(puVar5 + 0x73c) = attributes->memoryFreeProc;
        memset();
        memset();
        puVar5 = aadMem;
        aadMem[0x17f6] = -1;
        puVar4 = aadMem;
        *(undefined4 *)(puVar5 + 0x1bf0) = 1;
        *(undefined2 *)(puVar5 + 0x17f0) = 0x8000;
        *(undefined2 *)(puVar5 + 0x17f2) = 0x202;
        *(undefined4 *)(puVar5 + 0x1bf4) = 0;
        *(undefined2 *)(puVar5 + 0x17f4) = 0x91d8;
        puVar4[0x17f7] = -1;
        aadPurgeLoadQueue();
        SpuInit();
        SpuSetCommonMasterVolume(0,0);
        iVar8 = 0;
        if (0 < attributes->numSlots) {
          puVar2 = &DAT_00001c88;
          do {
            iVar6 = 0;
            puVar4 = aadMem + (int)puVar2;
            *(uchar **)(aadMem + iVar8 * 4 + 0x34) = puVar4;
            puVar4[0x53f] = (uchar)iVar8;
            puVar4[0x53e] = -1;
            puVar4[0x551] = (uchar)(iVar8 << 4);
            puVar4[0x552] = '\x7f';
            puVar4[0x553] = '?';
            *(uchar **)(puVar4 + 0x554) = aadMem + 0x20;
            puVar5 = puVar4;
            do {
              puVar3 = puVar4 + iVar6;
              puVar3[0x590] = -1;
              puVar3[0x5a0] = '\x7f';
              puVar3[0x5b0] = '?';
              *(undefined2 *)(puVar5 + 0x570) = 0x2000;
              iVar6 = iVar6 + 1;
              puVar5 = puVar5 + 2;
            } while (iVar6 < 0x10);
            *(uchar **)(puVar4 + 0x538) = puVar4;
            puVar4[0x53c] = (uchar)iVar8;
            iVar8 = iVar8 + 1;
            puVar2 = puVar2 + 0x5d0;
          } while (iVar8 < attributes->numSlots);
        }
        puVar5 = aadMem;
        uVar7 = 0;
        *(undefined2 *)(aadMem + 0x1d8) = 0x3039;
        puVar5[0x1da] = '\x7f';
        puVar5 = aadMem;
        iVar8 = 0;
        *(uint *)(aadMem + 4) = (uint)*(byte *)&attributes->numSlots;
        bVar1 = *(byte *)&attributes->updateMode;
        *(undefined4 *)(puVar5 + 0x1c) = 0x7f;
        *(undefined4 *)(puVar5 + 0x20) = 0x7f;
        *(undefined4 *)(puVar5 + 0x1bfc) = 0;
        *(undefined4 *)(puVar5 + 0x1bf8) = 0;
        *(uint *)(puVar5 + 8) = (uint)bVar1;
        do {
          puVar4 = aadMem + iVar8;
          puVar4[0x1e4] = -1;
          puVar5 = aadMem;
          *(int *)(puVar4 + 0x1dc) = 1 << (uVar7 & 0x1f);
          puVar5[iVar8 + 0x1ed] = (uchar)uVar7;
          puVar5 = aadMem;
          uVar7 = uVar7 + 1;
          iVar8 = iVar8 + 0x1c;
        } while ((int)uVar7 < 0x18);
        iVar8 = *(int *)(aadMem + 8);
        *(undefined4 *)(aadMem + 0x4c4) = 0;
        *(undefined4 *)(puVar5 + 0x4c8) = 0;
        *(undefined4 *)(puVar5 + 0x4cc) = 0;
        if (iVar8 < 4) {
          aadInstallUpdateFunc(aadSlotUpdateWrapper,(uint)aadHblanksPerUpdate[iVar8]);
        }
        *(undefined4 *)(aadMem + 0x24) = 0;
        ExitCriticalSection();
        puVar2 = (undefined *)0x0;
      }
    }
  }
  return (int)puVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr /*$s0*/, int hblanksPerUpdate /*$s1*/)
 // line 185, offset 0x80051fec
	/* begin block 1 */
		// Start line: 493
	/* end block 1 */
	// End Line: 494

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadInstallUpdateFunc
               (TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr,int hblanksPerUpdate)

{
  EnterCriticalSection();
  __hblankEvent = OpenEvent(0xf2000001,2,0x1000,(func *)updateFuncPtr);
  EnableEvent(__hblankEvent);
  SetRCnt(0xf2000001,(ushort)hblanksPerUpdate,0x1000);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadInitVolume(void)

{
  *(undefined4 *)(aadMem + 0xc) = 0;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadSetMasterVolume(int volume)

{
  short mvol_left;
  
  mvol_left = (short)volume;
  *(int *)(aadMem + 0xc) = (int)mvol_left;
  SpuSetCommonMasterVolume(mvol_left,mvol_left);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadStartMasterVolumeFade
               (int targetVolume,int volumeStep,
               TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback)

{
  int iVar1;
  
  iVar1 = aadMem;
  *(int *)(aadMem + 0x10) = volumeStep;
  *(int *)(iVar1 + 0x14) = targetVolume;
  *(TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback *)(iVar1 + 0x18) = fadeCompleteCallback
  ;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadSetSfxMasterVolume(int volume)

{
  *(uint *)(aadMem + 0x1c) = volume & 0xff;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadSetMusicMasterVolume(int volume)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(aadMem + 4);
  iVar3 = 0;
  *(int *)(aadMem + 0x20) = volume;
  if (0 < *piVar1) {
    do {
      iVar2 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      aadUpdateSlotVolPan(*(_AadSequenceSlot **)(aadMem + iVar2 + 0x34));
    } while (iVar3 < *(int *)(aadMem + 4));
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadStartMusicMasterVolFade
               (int targetVolume,int volumeStep,
               TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback)

{
  int iVar1;
  
  iVar1 = aadMem;
  *(int *)(aadMem + 0x28) = volumeStep;
  *(int *)(iVar1 + 0x2c) = targetVolume;
  *(TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback *)(iVar1 + 0x30) =
       fadeCompleteCallback;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadShutdown(void)

{
  int mode;
  
  EnterCriticalSection();
  StopRCnt(0xf2000001);
  DisableEvent(__hblankEvent);
  CloseEvent(__hblankEvent);
  *(uint *)(aadMem + 0x24) = *(uint *)(aadMem + 0x24) | 2;
  ExitCriticalSection();
  SpuSetKey(0,0xffffff);
  mode = aadGetReverbMode();
  SpuClearReverbWorkArea(mode);
  SpuQuit();
  aadMem = 0;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadSlotUpdate(void)

{
  short *psVar1;
  code **ppcVar2;
  byte bVar3;
  short sVar4;
  bool bVar5;
  uint *puVar6;
  uint volume;
  int track;
  int iVar7;
  uchar uVar8;
  char cVar9;
  AadSeqEvent *event;
  uint voice_bit;
  int iVar10;
  _AadSequenceSlot *p_Var11;
  _AadSequenceSlot *slot;
  _AadSequenceSlot *p_Var12;
  
  if (aadMem != (uint *)0x0) {
    if ((aadMem[9] & 2) == 0) {
      SpuGetAllKeysStatus((char *)(aadMem + 0x11f));
      puVar6 = aadMem;
      iVar10 = 0;
      voice_bit = 1;
      do {
        cVar9 = *(char *)((int)puVar6 + iVar10 + 0x47c);
        if (cVar9 == '\x03') {
          volume = puVar6[0x131] | voice_bit;
LAB_800522e8:
          puVar6[0x131] = volume;
        }
        else {
          if (((puVar6[0x131] & voice_bit) != 0) && ((cVar9 == '\0' || (cVar9 == '\x02')))) {
            volume = puVar6[0x131] & ~voice_bit;
            goto LAB_800522e8;
          }
        }
        iVar10 = iVar10 + 1;
        voice_bit = voice_bit << 1;
      } while (iVar10 < 0x18);
      if (((aadMem[9] & 4) == 0) && (iVar10 = 0, 0 < (int)aadMem[1])) {
        track = 0;
        do {
          slot = *(_AadSequenceSlot **)((int)aadMem + track + 0x34);
          if (((slot->status & 1) != 0) && ((slot->slotFlags & 1) == 0)) {
            (slot->tempo).currentTick =
                 (slot->tempo).currentTick + (uint)(slot->tempo).ticksPerUpdate;
            volume = (slot->tempo).tickTimeFixed;
            voice_bit = (slot->tempo).currentError + (slot->tempo).errorPerUpdate;
            (slot->tempo).currentError = voice_bit;
            if (volume <= voice_bit) {
              (slot->tempo).currentError = voice_bit - volume;
              (slot->tempo).currentTick = (slot->tempo).currentTick + 1;
            }
            track = 0;
            p_Var11 = slot;
            p_Var12 = slot;
            do {
              if (p_Var12->sequencePosition[0] == (_func_9 *)0x0) break;
              bVar3 = p_Var11->eventsInQueue[0];
              while ((bVar3 < 3 && (iVar7 = aadQueueNextEvent(slot,track), iVar7 == 0))) {
                bVar3 = p_Var11->eventsInQueue[0];
              }
              p_Var11 = (_AadSequenceSlot *)((int)&(p_Var11->tempo).currentTick + 1);
              track = track + 1;
              p_Var12 = (_AadSequenceSlot *)&(p_Var12->tempo).currentError;
            } while (track < 0x10);
            track = 0;
            iVar7 = 0;
            p_Var11 = slot;
            p_Var12 = slot;
            do {
              if (p_Var11->sequencePosition[0] == (_func_9 *)0x0) break;
              uVar8 = p_Var12->eventsInQueue[0];
              while (uVar8 != '\0') {
                event = (AadSeqEvent *)
                        ((int)&slot->eventQueue[(uint)p_Var12->eventOut[0] * 0x10].deltaTime + iVar7
                        );
                voice_bit = event->deltaTime + p_Var11->lastEventExecutedTime[0];
                if ((slot->tempo).currentTick < voice_bit) break;
                p_Var11->lastEventExecutedTime[0] = voice_bit;
                uVar8 = p_Var12->eventOut[0] + '\x01';
                p_Var12->eventOut[0] = uVar8;
                p_Var12->eventsInQueue[0] = p_Var12->eventsInQueue[0] + -1;
                if (uVar8 == '\x04') {
                  p_Var12->eventOut[0] = '\0';
                }
                aadExecuteEvent(event,slot);
                uVar8 = p_Var12->eventsInQueue[0];
              }
              p_Var11 = (_AadSequenceSlot *)&(p_Var11->tempo).currentError;
              iVar7 = iVar7 + 0xc;
              track = track + 1;
              p_Var12 = (_AadSequenceSlot *)((int)&(p_Var12->tempo).currentTick + 1);
            } while (track < 0x10);
          }
          iVar10 = iVar10 + 1;
          track = iVar10 * 4;
        } while (iVar10 < (int)aadMem[1]);
      }
      sVar4 = *(short *)((int)aadMem + 0x1d6);
      while (sVar4 != 0) {
        aadExecuteSfxCommand
                  ((AadSfxCommand *)(aadMem + (uint)*(byte *)((int)aadMem + 0x1d5) * 3 + 0x15));
        puVar6 = aadMem;
        psVar1 = (short *)((int)aadMem + 0x1d6);
        cVar9 = *(char *)((int)aadMem + 0x1d5) + '\x01';
        *(char *)((int)aadMem + 0x1d5) = cVar9;
        *(short *)((int)puVar6 + 0x1d6) = *psVar1 + -1;
        if (cVar9 == ' ') {
          *(undefined *)((int)aadMem + 0x1d5) = 0;
        }
        sVar4 = *(short *)((int)aadMem + 0x1d6);
      }
      voice_bit = aadMem[0x131] & ~aadMem[0x132];
      aadMem[0x131] = voice_bit;
      if (voice_bit != 0) {
        SpuSetKey(0,voice_bit);
      }
      SpuSetReverbVoice(1,aadMem[0x133]);
      SpuSetReverbVoice(0,~aadMem[0x133]);
      if (aadMem[0x132] != 0) {
        SpuSetKey(1,aadMem[0x132]);
        aadMem[0x132] = 0;
      }
    }
    voice_bit = aadMem[4];
    bVar5 = false;
    if (voice_bit != 0) {
      volume = aadMem[3] + voice_bit;
      if ((int)voice_bit < 0) {
        bVar5 = (int)volume < (int)aadMem[5];
      }
      else {
        if ((int)aadMem[5] < (int)volume) {
          bVar5 = true;
        }
      }
      if (bVar5) {
        volume = aadMem[5];
        ppcVar2 = (code **)(aadMem + 6);
        aadMem[4] = 0;
        if (*ppcVar2 != (code *)0x0) {
          (**ppcVar2)();
        }
      }
      aadSetMasterVolume(volume);
    }
    voice_bit = aadMem[10];
    if ((voice_bit != 0) && (bVar5 = false, (*aadMem & 1) == 0)) {
      volume = aadMem[8] + voice_bit;
      if ((int)voice_bit < 0) {
        bVar5 = (int)volume <= (int)aadMem[0xb];
      }
      else {
        if ((int)aadMem[0xb] <= (int)volume) {
          bVar5 = true;
        }
      }
      if (bVar5) {
        volume = aadMem[0xb];
        ppcVar2 = (code **)(aadMem + 0xc);
        aadMem[10] = 0;
        if (*ppcVar2 != (code *)0x0) {
          (**ppcVar2)();
        }
      }
      aadSetMusicMasterVolume(volume);
    }
    *aadMem = *aadMem + 1;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadLoadDynamicSoundBank
              (char *sndFileName,char *smpFileName,int dynamicBankIndex,int loadOption,
              TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar1 = aadMem;
  iVar4 = 0;
  pcVar5 = (char *)(aadMem + 0x6d8);
  iVar3 = aadMem;
  do {
    iVar4 = iVar4 + 1;
    if (*(int *)(iVar3 + 0x500) == 1) {
      return (int)&DAT_00001006;
    }
    iVar3 = iVar3 + 4;
  } while (iVar4 < 2);
  if (dynamicBankIndex < 2) {
    iVar3 = aadMem + dynamicBankIndex * 4;
    if ((*(int *)(iVar3 + 0x500) == 2) && (*(int *)(iVar3 + 0x508) != 0)) {
      aadFreeDynamicSoundBank(dynamicBankIndex);
    }
    *(undefined4 *)(aadMem + dynamicBankIndex * 4 + 0x500) = 1;
    strncpy(pcVar5,sndFileName,0x1f);
    strncpy((char *)(iVar1 + 0x6f8),smpFileName,0x1f);
    *(int *)(iVar1 + 0x718) = dynamicBankIndex;
    *(int *)(iVar1 + 0x71c) = loadOption;
    *(undefined4 *)(iVar1 + 0x72c) = 0;
    *(TDRFuncPtr_aadLoadDynamicSoundBank4retProc *)(iVar1 + 0x720) = retProc;
    (**(code **)(aadMem + 0x730))
              (sndFileName,aadLoadDynamicSoundBankReturn,pcVar5,0,
               aadMem + dynamicBankIndex * 4 + 0x508,4);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadLoadDynamicSoundBankReturn(void *loadedDataPtr,void *data,void *data2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint dynamicBankIndex;
  
  dynamicBankIndex = *(uint *)((int)data + 0x40);
  uVar2 = aadOpenDynamicSoundBank((uchar *)loadedDataPtr,dynamicBankIndex);
  iVar1 = aadMem;
  if (uVar2 == 0) {
    (**(code **)(aadMem + 0x734))((int)data + 0x20,aadLoadDynamicSoundBankReturn2,data,0);
  }
  else {
    iVar3 = aadMem + dynamicBankIndex * 4;
    *(uint *)(iVar3 + 0x500) = uVar2 & 0xff | 0x80;
    if (*(int *)(iVar3 + 0x508) != 0) {
      (**(code **)(iVar1 + 0x73c))();
      *(undefined4 *)(aadMem + dynamicBankIndex * 4 + 0x508) = 0;
    }
    if (*(code **)((int)data + 0x48) != (code *)0x0) {
      (**(code **)((int)data + 0x48))(dynamicBankIndex & 0xffff,uVar2);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadLoadDynamicSoundBankReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = (int)((uint)(ushort)status << 0x10) >> 0x10;
  uVar7 = *(uint *)((int)data1 + 0x40);
  if (iVar8 < 0x100) {
    if ((*(uint *)((int)data1 + 0x54) & 1) == 0) {
      puVar6 = (undefined4 *)((int)loadedDataPtr + 4);
      *(uint *)((int)data1 + 0x54) = *(uint *)((int)data1 + 0x54) | 1;
      loadedDataPtr = (void *)((int)loadedDataPtr + 8);
      loadedDataSize = loadedDataSize - 8;
      *(undefined4 *)((int)data1 + 0x4c) = *puVar6;
      if ((*(int *)((int)data1 + 0x44) == 0) || (*(int *)((int)data1 + 0x44) != 1)) {
        *(undefined4 *)((int)data1 + 0x50) = 0x49ed0;
      }
      else {
        uVar1 = aadGetReverbSize();
        *(int *)((int)data1 + 0x50) = (0x80000 - *(int *)((int)data1 + 0x4c)) - uVar1;
      }
      *(undefined4 *)(aadMem + uVar7 * 4 + 0x510) = *(undefined4 *)((int)data1 + 0x50);
    }
    aadWaitForSramTransferComplete();
    SpuSetTransferStartAddr(*(ulong *)((int)data1 + 0x50));
    SpuWrite((uchar *)loadedDataPtr,loadedDataSize);
    *(int *)((int)data1 + 0x50) = *(int *)((int)data1 + 0x50) + loadedDataSize;
    if (status != 1) {
      return;
    }
    iVar8 = 0;
    if (0 < *(int *)(*(int *)(aadMem + uVar7 * 4 + 0x4d0) + 0x14)) {
      iVar2 = aadMem + uVar7 * 4;
      iVar3 = 0;
      do {
        piVar4 = (int *)(iVar3 + *(int *)(iVar2 + 0x4e8));
        *piVar4 = *piVar4 + *(int *)(iVar2 + 0x510);
        iVar8 = iVar8 + 1;
        iVar3 = iVar8 * 4;
      } while (iVar8 < *(int *)(*(int *)(iVar2 + 0x4d0) + 0x14));
    }
    *(undefined4 *)(aadMem + uVar7 * 4 + 0x500) = 2;
    pcVar5 = *(code **)((int)data1 + 0x48);
    uVar7 = uVar7 & 0xffff;
    if (pcVar5 == (code *)0x0) {
      return;
    }
    iVar8 = 0;
  }
  else {
    if ((*(uint *)((int)data1 + 0x54) & 2) != 0) {
      return;
    }
    *(uint *)((int)data1 + 0x54) = *(uint *)((int)data1 + 0x54) | 2;
    iVar3 = aadMem;
    iVar2 = aadMem + uVar7 * 4;
    *(uint *)(iVar2 + 0x500) = ((uint)(ushort)status << 0x10) >> 0x18 | 0x80;
    if (*(int *)(iVar2 + 0x508) != 0) {
      (**(code **)(iVar3 + 0x73c))();
      *(undefined4 *)(aadMem + uVar7 * 4 + 0x508) = 0;
    }
    pcVar5 = *(code **)((int)data1 + 0x48);
    if (pcVar5 == (code *)0x0) {
      return;
    }
  }
  (*pcVar5)(uVar7,iVar8);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadFreeDynamicSoundBank(int dynamicBankIndex)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar1 = aadMem;
  if (dynamicBankIndex < 2) {
    iVar3 = aadMem + dynamicBankIndex * 4;
    puVar2 = &DAT_00001007;
    if ((*(int *)(iVar3 + 0x500) == 2) && (puVar2 = &DAT_00001007, *(int *)(iVar3 + 0x508) != 0)) {
      *(undefined4 *)(iVar3 + 0x500) = 0;
      (**(code **)(iVar1 + 0x73c))(*(undefined4 *)(iVar3 + 0x508));
      puVar2 = (undefined *)0x0;
      *(undefined4 *)(aadMem + dynamicBankIndex * 4 + 0x508) = 0;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadOpenDynamicSoundBank(uchar *soundBank,int dynamicBankIndex)

{
  undefined *puVar1;
  ulong uVar2;
  uchar *puVar3;
  int iVar4;
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
      iVar4 = aadMem + dynamicBankIndex * 4;
      puVar3 = soundBank + *(int *)(soundBank + 4);
      *(uchar **)(iVar4 + 0x4d8) = puVar3;
      puVar3 = puVar3 + iVar5 * 8;
      *(uchar **)(iVar4 + 0x4e0) = puVar3;
      piVar8 = (int *)(puVar3 + iVar9 * 0x10 + iVar10 * 4);
      piVar7 = piVar8 + iVar6;
      *(uchar **)(iVar4 + 0x4d0) = soundBank;
      *(uchar **)(iVar4 + 0x4e8) = puVar3 + iVar9 * 0x10;
      *(int **)(iVar4 + 0x4f0) = piVar8;
      *(int **)(iVar4 + 0x4f8) = piVar7;
      if (0 < *(int *)(soundBank + 0x18)) {
        do {
          *(int *)(iVar12 * 4 + *(int *)(iVar4 + 0x4f0)) = (int)piVar7 + *piVar8 + iVar11 * 4;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadLoadDynamicSfx(char *fileName,long directoryID,long flags)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar2 = aadMem;
  iVar3 = 0;
  if (*(int *)(aadMem + 0x748) < 0x10) {
    puVar5 = (undefined4 *)(aadMem + *(int *)(aadMem + 0x740) * 0x1c + 0x518);
    *puVar5 = 0;
    uVar4 = *(uint *)(iVar2 + 0x7e4);
    puVar5[1] = uVar4 & 0x3fff | 0x4000;
    *(int *)(iVar2 + 0x7e4) = uVar4 + 1;
    puVar5[2] = directoryID;
    puVar5[3] = flags;
    strncpy((char *)(puVar5 + 4),fileName,0xb);
    iVar2 = aadMem;
    piVar1 = (int *)(aadMem + 0x748);
    *(uint *)(aadMem + 0x740) = *(int *)(aadMem + 0x740) + 1U & 0xf;
    *(int *)(iVar2 + 0x748) = *piVar1 + 1;
    iVar3 = puVar5[1];
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadFreeDynamicSfx(int handle)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = aadMem;
  if (*(int *)(aadMem + 0x748) < 0x10) {
    puVar2 = (undefined4 *)(aadMem + *(int *)(aadMem + 0x740) * 0x1c + 0x518);
    *puVar2 = 1;
    puVar2[1] = handle;
    *(uint *)(iVar1 + 0x740) = *(int *)(iVar1 + 0x740) + 1U & 0xf;
    *(int *)(iVar1 + 0x748) = *(int *)(iVar1 + 0x748) + 1;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadRelocateMusicMemoryBegin(void)

{
  *(uint *)(aadMem + 0x24) = *(uint *)(aadMem + 0x24) | 2;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadRelocateMusicMemoryEnd(void *oldAddress,int offset)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar1 = aadMem;
  iVar11 = 0;
  iVar8 = aadMem;
  while (oldAddress != *(void **)(iVar8 + 0x508)) {
    iVar11 = iVar11 + 1;
    iVar8 = iVar8 + 4;
    if (1 < iVar11) goto LAB_80053050;
  }
  *(int *)(iVar8 + 0x508) = (int)oldAddress + offset;
  *(int *)(iVar8 + 0x4d8) = *(int *)(iVar8 + 0x4d8) + offset;
  *(int *)(iVar8 + 0x4e0) = *(int *)(iVar8 + 0x4e0) + offset;
  iVar3 = *(int *)(iVar8 + 0x4d0) + offset;
  *(int *)(iVar8 + 0x4d0) = iVar3;
  *(int *)(iVar8 + 0x4e8) = *(int *)(iVar8 + 0x4e8) + offset;
  *(int *)(iVar8 + 0x4f0) = *(int *)(iVar8 + 0x4f0) + offset;
  iVar5 = 0;
  if (0 < *(int *)(iVar3 + 0x18)) {
    do {
      piVar2 = (int *)(iVar5 * 4 + *(int *)(iVar8 + 0x4f0));
      *piVar2 = *piVar2 + offset;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(iVar3 + 0x18));
  }
  *(int *)(iVar8 + 0x4f8) = *(int *)(iVar8 + 0x4f8) + offset;
  iVar3 = 0;
  iVar8 = iVar1;
  if (0 < *(int *)(iVar1 + 4)) {
    do {
      iVar5 = *(int *)(iVar8 + 0x34);
      if ((*(char *)(iVar5 + 0x53e) != -1) && (*(int *)(iVar5 + 0x55c) == iVar11)) {
        iVar9 = 0;
        iVar10 = 0;
        iVar7 = iVar5;
        do {
          if (*(int *)(iVar7 + 0x348) != 0) {
            *(int *)(iVar7 + 0x348) = *(int *)(iVar7 + 0x348) + offset;
            iVar6 = 0;
            iVar4 = iVar10;
            if (*(char *)(iVar5 + iVar9 + 0x4e8) != '\0') {
              do {
                *(int *)(iVar5 + iVar4 + 1000) = *(int *)(iVar5 + iVar4 + 1000) + offset;
                iVar6 = iVar6 + 1;
                iVar4 = iVar4 + 0x40;
              } while (iVar6 < (int)(uint)*(byte *)(iVar5 + iVar9 + 0x4e8));
            }
          }
          iVar10 = iVar10 + 4;
          iVar9 = iVar9 + 1;
          iVar7 = iVar7 + 4;
        } while (iVar9 < 0x10);
      }
      iVar3 = iVar3 + 1;
      iVar8 = iVar8 + 4;
    } while (iVar3 < *(int *)(iVar1 + 4));
  }
LAB_80053050:
  *(uint *)(aadMem + 0x24) = *(uint *)(aadMem + 0x24) & 0xfffffffd;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadRelocateSfxMemory(void *oldAddress,int offset)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(aadMem + 0x7e0);
  if (oldAddress == pvVar1) {
    pvVar1 = (void *)((int)pvVar1 + offset);
    *(void **)(aadMem + 0x7e0) = pvVar1;
  }
  while (pvVar1 != (void *)0x0) {
    if (oldAddress == *(void **)((int)pvVar1 + 0xc)) {
      *(int *)((int)pvVar1 + 0xc) = (int)oldAddress + offset;
    }
    if (oldAddress == *(void **)((int)pvVar1 + 0x10)) {
      *(int *)((int)pvVar1 + 0x10) = (int)oldAddress + offset;
    }
    pvVar1 = *(void **)((int)pvVar1 + 0x10);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadGetNumLoadsQueued(void)

{
  return *(int *)(aadMem + 0x748);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadPurgeLoadQueue(void)

{
  int iVar1;
  
  iVar1 = aadMem;
  *(undefined4 *)(aadMem + 0x740) = 0;
  *(undefined4 *)(iVar1 + 0x744) = 0;
  *(undefined4 *)(iVar1 + 0x748) = 0;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadProcessLoadQueue(void)

{
  ushort uVar1;
  char *fmt;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *buffer;
  ushort *puVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int aiStack32 [4];
  
  iVar7 = aadMem;
  buffer = (char *)(aadMem + 0x74c);
  iVar2 = 0;
  iVar3 = aadMem;
  if ((*(uint *)(aadMem + 0x7a8) & 1) == 0) {
    do {
      iVar2 = iVar2 + 1;
      if (*(int *)(iVar3 + 0x500) == 1) {
        return;
      }
      iVar3 = iVar3 + 4;
    } while (iVar2 < 2);
    if ((*(int *)(aadMem + 0x748) == 0) || (*(int *)(aadMem + 0x7e8) != 0)) {
      if (gSramCheckRequest == 0) {
        if (((gDfragRequest != 0) && (*(int *)(aadMem + 0x7e8) == 0)) && (musicLoadInProgress == 0))
        {
          *(undefined4 *)(aadMem + 0x7e8) = 1;
          gDfragRequest = 0;
        }
      }
      else {
        gDfragRequest = aadCheckSramFragmented();
        gSramCheckRequest = 0;
      }
    }
    else {
      iVar3 = *(int *)(aadMem + 0x744);
      piVar6 = (int *)(aadMem + 0x748);
      *(uint *)(aadMem + 0x744) = iVar3 + 1U & 0xf;
      piVar8 = (int *)(iVar7 + iVar3 * 0x1c + 0x518);
      *(int *)(iVar7 + 0x748) = *piVar6 + -1;
      if (*piVar8 == 0) {
        piVar6 = piVar8 + 4;
        strcpy();
        fmt = strpbrk((char *)aiStack32,s_0123456789_800cfef0);
        if (fmt != (char *)0x0) {
          *fmt = '\0';
        }
        if ((piVar8[3] & 1U) == 0) {
          sprintf(buffer,s__kain2_sfx_object__s__s_snf_800cff34,piVar6,piVar6);
          fmt = s__kain2_sfx_object__s__s_smf_800cff50;
          piVar4 = piVar6;
        }
        else {
          sprintf(buffer,s__kain2_area__s_bin__s_snf_800cfefc,aiStack32,piVar6);
          fmt = s__kain2_area__s_bin__s_smf_800cff18;
          piVar4 = aiStack32;
        }
        sprintf((char *)(iVar7 + 0x774),fmt,piVar4,piVar6);
        *(int *)(iVar7 + 0x79c) = piVar8[1];
        *(int *)(iVar7 + 0x7a0) = piVar8[2];
        iVar3 = piVar8[3];
        gSramFullAlarm = 0;
        *(undefined4 *)(iVar7 + 0x7a8) = 1;
        *(undefined4 *)(iVar7 + 0x7c4) = 0;
        *(undefined4 *)(iVar7 + 0x7b8) = 0;
        *(undefined4 *)(iVar7 + 0x7c0) = 0;
        *(int *)(iVar7 + 0x7a4) = iVar3;
        if (*(int *)(iVar7 + 0x7a0) != 0) {
          LOAD_SetSearchDirectory(*(int *)(iVar7 + 0x7a0));
        }
        (**(code **)(aadMem + 0x730))(buffer,aadLoadDynamicSfxReturn,buffer,0,iVar7 + 0x7c4,0x2f);
        if (*(int *)(iVar7 + 0x7a0) != 0) {
          LOAD_SetSearchDirectory(0);
        }
        gSramCheckRequest = 1;
      }
      else {
        if (*piVar8 == 1) {
          iVar7 = *(int *)(iVar7 + 0x7e0);
          if (iVar7 != 0) {
LAB_80053310:
            if ((uint)*(ushort *)(iVar7 + 8) != piVar8[1]) goto LAB_800533c8;
            iVar3 = 0;
            puVar5 = (ushort *)(iVar7 + 0x14);
            if (*(short *)(iVar7 + 10) != 0) {
              do {
                uVar1 = *puVar5;
                puVar5 = puVar5 + 1;
                aadFreeSingleDynSfx((uint)uVar1);
                iVar3 = iVar3 + 1;
              } while (iVar3 < (int)(uint)*(ushort *)(iVar7 + 10));
            }
            if (*(int *)(iVar7 + 0xc) == 0) {
              *(undefined4 *)(aadMem + 0x7e0) = *(undefined4 *)(iVar7 + 0x10);
            }
            else {
              *(undefined4 *)(*(int *)(iVar7 + 0xc) + 0x10) = *(undefined4 *)(iVar7 + 0x10);
            }
            if (*(int *)(iVar7 + 0x10) != 0) {
              *(undefined4 *)(*(int *)(iVar7 + 0x10) + 0xc) = *(undefined4 *)(iVar7 + 0xc);
            }
            (**(code **)(aadMem + 0x73c))(iVar7);
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
  iVar7 = *(int *)(iVar7 + 0x10);
  if (iVar7 == 0) goto LAB_800533d8;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadLoadDynamicSfxAbort(AadDynamicSfxLoadInfo *info,int error)

{
  _AadDynSfxFileHdr *p_Var1;
  
  if (info->snfFile != (_AadDynSfxFileHdr *)0x0) {
    if ((info->flags & 2U) != 0) {
      p_Var1 = info->snfFile->prevDynSfxFile;
      if (p_Var1 == (_AadDynSfxFileHdr *)0x0) {
        *(undefined4 *)(aadMem + 0x7e0) = 0;
      }
      else {
        p_Var1->nextDynSfxFile = (_AadDynSfxFileHdr *)0x0;
      }
    }
    (**(code **)(aadMem + 0x73c))(info->snfFile);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadLoadDynamicSfxReturn(void *loadedDataPtr,void *data,void *data2)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  
  puVar4 = *(ulong **)((int)data + 0x78);
  if ((puVar4 == (ulong *)0x0) || (puVar4 != (ulong *)loadedDataPtr)) {
    aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data,(int)&DAT_0000100e);
  }
  else {
    uVar1 = aadCreateFourCharID('a','S','N','F');
    iVar2 = aadMem;
    if ((*puVar4 == uVar1) && (*(short *)(*(int *)((int)data + 0x78) + 4) == 0x100)) {
      *(undefined2 *)(*(int *)((int)data + 0x78) + 8) = *(undefined2 *)((int)data + 0x50);
      iVar3 = *(int *)(iVar2 + 0x7e0);
      if (iVar3 == 0) {
        *(undefined4 *)(iVar2 + 0x7e0) = *(undefined4 *)((int)data + 0x78);
        *(undefined4 *)(*(int *)((int)data + 0x78) + 0xc) = 0;
      }
      else {
        iVar2 = *(int *)(iVar3 + 0x10);
        while (iVar2 != 0) {
          iVar3 = *(int *)(iVar3 + 0x10);
          iVar2 = *(int *)(iVar3 + 0x10);
        }
        *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)((int)data + 0x78);
        *(int *)(*(int *)((int)data + 0x78) + 0xc) = iVar3;
      }
      *(undefined4 *)(*(int *)((int)data + 0x78) + 0x10) = 0;
      *(undefined4 *)((int)data + 0x60) = 0;
      *(uint *)((int)data + 0x5c) = *(uint *)((int)data + 0x5c) | 2;
      if (*(int *)((int)data + 0x54) != 0) {
        LOAD_SetSearchDirectory(*(int *)((int)data + 0x54));
      }
      (**(code **)(aadMem + 0x734))((int)data + 0x28,aadLoadDynamicSfxReturn2,data,0);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadWaveMalloc(ushort waveID,ulong waveSize)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  undefined uVar8;
  uint uVar9;
  ushort *puVar10;
  undefined *puVar11;
  uint uVar12;
  
  puVar10 = (ushort *)0x0;
  uVar12 = 0xff;
  uVar9 = *(uint *)(&DAT_00001bf4 + aadMem);
  puVar11 = &DAT_000017f0 + aadMem;
  puVar6 = (ushort *)(puVar11 + uVar9 * 8);
  uVar5 = waveSize >> 3;
  if (puVar6 != (ushort *)0x0) {
    iVar7 = 0x7f;
    do {
      if (iVar7 == -1) break;
      if ((((*puVar6 & 0x4000) == 0) && (uVar5 + 6 <= (uint)puVar6[2])) &&
         ((puVar10 == (ushort *)0x0 ||
          (((uint)puVar6[2] - 6) - uVar5 < ((uint)puVar10[2] - 6) - uVar5)))) {
        puVar10 = puVar6;
        uVar12 = uVar9;
      }
      if (*(char *)((int)puVar6 + 7) < '\0') {
        puVar6 = (ushort *)0x0;
      }
      else {
        uVar3 = (uint)*(byte *)((int)puVar6 + 7);
        puVar6 = (ushort *)0x0;
        if (uVar3 != uVar9) {
          puVar6 = (ushort *)(puVar11 + uVar3 * 8);
          uVar9 = uVar3;
        }
      }
      iVar7 = iVar7 + -1;
    } while (puVar6 != (ushort *)0x0);
  }
  if (puVar10 == (ushort *)0x0) {
    return 0xff;
  }
  *puVar10 = waveID | 0xc000;
  if (uVar5 < puVar10[2]) {
    uVar4 = (ushort)uVar5;
    if (-1 < *(char *)((int)puVar10 + 7)) {
      puVar6 = (ushort *)(puVar11 + (uint)*(byte *)((int)puVar10 + 7) * 8);
      if ((*puVar6 & 0x4000) == 0) {
        puVar6[1] = puVar6[1] - (puVar10[2] - uVar4);
        puVar6[2] = puVar6[2] + (puVar10[2] - uVar4);
        puVar10[2] = uVar4;
        return uVar12;
      }
    }
    uVar5 = *(uint *)(&DAT_00001bf0 + aadMem);
    uVar8 = (undefined)uVar5;
    puVar6 = (ushort *)(puVar11 + uVar5 * 8);
    uVar2 = *puVar6;
    uVar9 = uVar5;
    while ((uVar2 & 0x8000) != 0) {
      uVar9 = uVar9 + 1 & 0x7f;
      uVar8 = (undefined)uVar9;
      if (uVar9 == uVar5) {
        return 0xff;
      }
      puVar6 = (ushort *)(puVar11 + uVar9 * 8);
      uVar2 = *puVar6;
    }
    *(uint *)(&DAT_00001bf0 + aadMem) = *(int *)(&DAT_00001bf0 + aadMem) + 8U & 0x7f;
    *puVar6 = 0x8000;
    puVar6[1] = puVar10[1] + uVar4;
    uVar2 = puVar10[2];
    *(char *)(puVar6 + 3) = (char)uVar12;
    puVar6[2] = uVar2 - uVar4;
    bVar1 = *(byte *)((int)puVar10 + 7);
    *(byte *)((int)puVar6 + 7) = bVar1;
    if (-1 < (int)((uint)bVar1 << 0x18)) {
      puVar11[(uint)*(byte *)((int)puVar6 + 7) * 8 + 6] = uVar8;
    }
    puVar10[2] = uVar4;
    *(undefined *)((int)puVar10 + 7) = uVar8;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

ulong aadGetSramBlockAddr(int handle)

{
  if (0x7f < handle) {
    return 0;
  }
  return (uint)*(ushort *)(&DAT_000017f2 + handle * 8 + aadMem) << 3;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadWaveFree(int handle)

{
  byte bVar1;
  undefined2 *puVar2;
  ushort *puVar3;
  undefined *puVar4;
  
  if (handle < 0x80) {
    puVar4 = &DAT_000017f0 + aadMem;
    puVar2 = (undefined2 *)(puVar4 + handle * 8);
    *puVar2 = 0x8000;
    if ((-1 < *(char *)((int)puVar2 + 7)) &&
       (puVar3 = (ushort *)(puVar4 + (uint)*(byte *)((int)puVar2 + 7) * 8), (*puVar3 & 0x4000) == 0)
       ) {
      puVar2[2] = puVar2[2] + puVar3[2];
      bVar1 = *(byte *)((int)puVar3 + 7);
      *puVar3 = 0;
      *(byte *)((int)puVar2 + 7) = bVar1;
      if (-1 < (int)((uint)bVar1 << 0x18)) {
        puVar4[(uint)*(byte *)((int)puVar2 + 7) * 8 + 6] = (char)handle;
      }
    }
    if ((-1 < *(char *)(puVar2 + 3)) &&
       (puVar3 = (ushort *)(puVar4 + (uint)*(byte *)(puVar2 + 3) * 8), (*puVar3 & 0x4000) == 0)) {
      puVar3[2] = puVar3[2] + puVar2[2];
      bVar1 = *(byte *)((int)puVar2 + 7);
      *puVar2 = 0;
      *(byte *)((int)puVar3 + 7) = bVar1;
      if (-1 < (int)((uint)bVar1 << 0x18)) {
        puVar4[(uint)*(byte *)((int)puVar2 + 7) * 8 + 6] = *(undefined *)(puVar2 + 3);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadFreeSingleDynSfx(int sfxID)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  
  sfxID = aadMem + sfxID;
  bVar1 = *(byte *)(sfxID + 0x808);
  if (bVar1 < 0xfe) {
    psVar5 = (short *)(aadMem + (uint)bVar1 * 0x14 + 0xc08);
    sVar2 = *psVar5;
    *psVar5 = sVar2 + -1;
    if ((short)(sVar2 + -1) == 0) {
      *(undefined *)(sfxID + 0x808) = 0xff;
      iVar3 = aadMem;
      bVar1 = *(byte *)(aadMem + (uint)(ushort)psVar5[1] + 0xa08);
      if (bVar1 < 0xfe) {
        psVar4 = (short *)(&DAT_00001608 + aadMem + (uint)bVar1 * 4);
        sVar2 = *psVar4;
        *psVar4 = sVar2 + -1;
        if ((short)(sVar2 + -1) == 0) {
          *(undefined *)(iVar3 + (uint)(ushort)psVar5[1] + 0xa08) = 0xff;
          aadWaveFree((uint)*(byte *)((int)psVar4 + 3));
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void setSramFullAlarm(void)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar4 = 0;
  iVar5 = 0;
  uVar6 = 0;
  gSramFreeBlocks = 0;
  gSramUsedBlocks = 0;
  puVar2 = (ushort *)(&DAT_000017f0 + aadMem + *(int *)(&DAT_00001bf4 + aadMem) * 8);
  iVar3 = 0x80;
  do {
    if (puVar2 == (ushort *)0x0) break;
    if ((*puVar2 & 0x4000) == 0) {
      uVar1 = (uint)puVar2[2];
      gSramFreeBlocks = gSramFreeBlocks + 1;
      iVar5 = iVar5 + uVar1;
      if (uVar6 < uVar1) {
        uVar6 = uVar1;
      }
    }
    else {
      gSramUsedBlocks = gSramUsedBlocks + 1;
      iVar4 = iVar4 + (uint)puVar2[2];
    }
    if (*(char *)((int)puVar2 + 7) < '\0') {
      puVar2 = (ushort *)0x0;
    }
    else {
      puVar2 = (ushort *)(&DAT_000017f0 + aadMem + (uint)*(byte *)((int)puVar2 + 7) * 8);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadLoadSingleDynSfx(AadDynamicSfxLoadInfo *info)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  ulong uVar4;
  undefined uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  AadDynSfxAttr *pAVar15;
  
  iVar6 = aadMem;
  uVar2 = (info->attr).sfxID;
  info->waveTransferAddr = 0;
  iVar6 = iVar6 + (uint)uVar2;
  pAVar15 = &info->attr;
  if (*(char *)(iVar6 + 0x808) == -2) {
    *(undefined *)(iVar6 + 0x808) = 0xff;
  }
  iVar6 = aadMem;
  bVar1 = *(byte *)(aadMem + (uint)(info->attr).sfxID + 0x808);
  if (bVar1 == 0xff) {
    _uVar5 = *(uint *)(&DAT_000017e8 + aadMem);
    uVar5 = (undefined)_uVar5;
    psVar10 = (short *)(aadMem + _uVar5 * 0x14 + 0xc08);
    sVar3 = *psVar10;
    uVar7 = _uVar5;
    while (sVar3 != 0) {
      uVar7 = uVar7 + 1 & 0x7f;
      uVar5 = (undefined)uVar7;
      if (uVar7 == _uVar5) {
        info->smfLoadingState = 2;
        iVar6 = (uint)pAVar15->sfxID + iVar6;
        goto LAB_80053e3c;
      }
      psVar10 = (short *)(aadMem + uVar7 * 0x14 + 0xc08);
      sVar3 = *psVar10;
    }
    *(uint *)(&DAT_000017e8 + aadMem) = *(int *)(&DAT_000017e8 + aadMem) + 8U & 0x7f;
    *psVar10 = 1;
    psVar10[1] = (info->attr).waveID;
    iVar6 = aadMem;
    uVar12 = *(undefined4 *)&(info->attr).toneAttr.centerNote;
    uVar13 = *(undefined4 *)&(info->attr).toneAttr.mode;
    uVar14 = *(undefined4 *)&(info->attr).toneAttr.adsr2;
    *(undefined4 *)(psVar10 + 2) = *(undefined4 *)&(info->attr).toneAttr;
    *(undefined4 *)(psVar10 + 4) = uVar12;
    *(undefined4 *)(psVar10 + 6) = uVar13;
    *(undefined4 *)(psVar10 + 8) = uVar14;
    *(undefined *)(iVar6 + (uint)pAVar15->sfxID + 0x808) = uVar5;
    iVar6 = aadMem;
    bVar1 = *(byte *)(aadMem + (uint)(info->attr).waveID + 0xa08);
    if (bVar1 == 0xff) {
      iVar8 = *(int *)(&DAT_000017ec + aadMem);
      do {
        psVar10 = (short *)(&DAT_00001608 + aadMem + iVar8 * 4);
        iVar9 = iVar8 + 1;
        if (*psVar10 == 0) {
          iVar11 = *(int *)(&DAT_000017ec + aadMem);
          iVar9 = iVar11 + 8;
          *(int *)(&DAT_000017ec + aadMem) = iVar9;
          if (0x77 < iVar9) {
            *(int *)(&DAT_000017ec + iVar6) = iVar11 + -0x70;
          }
          *psVar10 = 1;
          *(undefined *)(aadMem + (uint)(info->attr).waveID + 0xa08) = (char)iVar8;
          iVar6 = aadWaveMalloc((info->attr).waveID,(info->attr).waveSize);
          *(undefined *)((int)psVar10 + 3) = (char)iVar6;
          if (-1 < iVar6 << 0x18) {
            uVar4 = aadGetSramBlockAddr((uint)*(byte *)((int)psVar10 + 3));
            info->waveTransferAddr = uVar4;
            info->smfLoadingState = 3;
            return;
          }
          break;
        }
        if (0x77 < iVar9) {
          iVar9 = 0;
        }
        iVar8 = iVar9;
      } while (iVar9 != *(int *)(&DAT_000017ec + aadMem));
      aadFreeSingleDynSfx((uint)pAVar15->sfxID);
      info->smfLoadingState = 2;
      iVar6 = aadMem + (uint)pAVar15->sfxID;
LAB_80053e3c:
      *(undefined *)(iVar6 + 0x808) = 0xfe;
      setSramFullAlarm();
      return;
    }
    *(short *)(&DAT_00001608 + aadMem + (uint)bVar1 * 4) =
         *(short *)(&DAT_00001608 + aadMem + (uint)bVar1 * 4) + 1;
  }
  else {
    psVar10 = (short *)(aadMem + (uint)bVar1 * 0x14 + 0xc08);
    *psVar10 = *psVar10 + 1;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void HackCallback(void)

{
  SpuSetTransferCallback((SpuTransferCallbackProc)0x0);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadLoadDynamicSfxReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  ulong uVar1;
  uint size;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (loadedDataSize != 0) {
    do {
      iVar2 = *(int *)((int)data1 + 0x60);
      if (iVar2 == 1) {
        size = *(uint *)((int)data1 + 100);
        if ((uint)loadedDataSize < *(uint *)((int)data1 + 100)) {
          size = loadedDataSize;
        }
        iVar3 = iVar3 + size;
        memcpy();
        loadedDataSize = loadedDataSize - size;
        iVar2 = *(int *)((int)data1 + 100) - size;
        *(int *)((int)data1 + 100) = iVar2;
        if (iVar2 == 0) {
          aadLoadSingleDynSfx((AadDynamicSfxLoadInfo *)data1);
          *(undefined4 *)((int)data1 + 100) = *(undefined4 *)((int)data1 + 0x90);
        }
      }
      else {
        if (iVar2 < 2) {
          if (iVar2 == 0) {
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
            size = (uint)*(ushort *)(*(int *)((int)data1 + 0x78) + 10);
            iVar3 = iVar3 + 0x10;
            if ((uint)*(ushort *)((int)loadedDataPtr + 8) != size) goto LAB_80053f98;
            loadedDataSize = loadedDataSize - 0x10;
            *(undefined4 *)((int)data1 + 0x60) = 1;
            *(undefined4 *)((int)data1 + 100) = 0x18;
            *(uint *)((int)data1 + 0x68) = size;
          }
        }
        else {
          if (iVar2 == 2) {
            size = *(uint *)((int)data1 + 100);
            if ((uint)loadedDataSize < *(uint *)((int)data1 + 100)) {
              size = loadedDataSize;
            }
            iVar3 = iVar3 + size;
            loadedDataSize = loadedDataSize - size;
            iVar2 = *(int *)((int)data1 + 100) - size;
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
              size = *(uint *)((int)data1 + 100);
              if ((uint)loadedDataSize < *(uint *)((int)data1 + 100)) {
                size = loadedDataSize;
              }
              loadedDataSize = loadedDataSize - size;
              aadWaitForSramTransferComplete();
              SpuSetTransferCallback(HackCallback);
              SpuSetTransferStartAddr(*(ulong *)((int)data1 + 0x70));
              SpuWrite((uchar *)((int)loadedDataPtr + iVar3),size);
              iVar3 = iVar3 + size;
              iVar2 = *(int *)((int)data1 + 100) - size;
              *(int *)((int)data1 + 0x70) = *(int *)((int)data1 + 0x70) + size;
              *(int *)((int)data1 + 100) = iVar2;
              if (iVar2 == 0) {
                iVar2 = *(int *)((int)data1 + 0x68) + -1;
                *(int *)((int)data1 + 0x74) =
                     *(int *)((int)data1 + 0x74) + *(int *)((int)data1 + 0x90);
                *(int *)((int)data1 + 0x68) = iVar2;
                if (iVar2 == 0) {
                  SpuSetTransferCallback((SpuTransferCallbackProc)0x0);
                  goto LAB_800540f4;
                }
                *(undefined4 *)((int)data1 + 0x60) = 1;
                *(undefined4 *)((int)data1 + 100) = 0x18;
              }
              if (loadedDataSize != 0) {
                smfDataPtr = (uchar *)((int)loadedDataPtr + iVar3);
                smfBytesLeft = loadedDataSize;
                smfInfo = data1;
                return;
              }
              SpuSetTransferCallback((SpuTransferCallbackProc)0x0);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadCheckSramFragmented(void)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = 0;
  uVar6 = 999999;
  iVar4 = 0;
  puVar2 = (ushort *)(&DAT_000017f0 + aadMem + *(int *)(&DAT_00001bf4 + aadMem) * 8);
  iVar3 = 0x80;
  do {
    if (puVar2 == (ushort *)0x0) break;
    if ((*puVar2 & 0x4000) == 0) {
      uVar1 = (uint)puVar2[2];
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + uVar1;
      if (uVar1 < uVar6) {
        uVar6 = uVar1;
      }
    }
    if (*(char *)((int)puVar2 + 7) < '\0') {
      puVar2 = (ushort *)0x0;
    }
    else {
      puVar2 = (ushort *)(&DAT_000017f0 + aadMem + (uint)*(byte *)((int)puVar2 + 7) * 8);
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar1 = 0;
  if (2 < iVar4) {
    uVar1 = (uint)((int)uVar6 < iVar5 >> 2);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadProcessSramDefrag(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  ulong size;
  ushort *puVar8;
  ushort *puVar9;
  undefined4 *puVar10;
  byte bVar11;
  uint uVar12;
  undefined *size_00;
  
  iVar4 = aadMem;
  iVar7 = *(int *)(aadMem + 0x7e8);
  puVar10 = (undefined4 *)(aadMem + 0x7e8);
  if (iVar7 == 1) {
    uVar12 = *(uint *)(&DAT_00001bf4 + aadMem);
    size_00 = &DAT_000017f0 + aadMem;
    puVar8 = (ushort *)(size_00 + uVar12 * 8);
    iVar7 = 0x80;
    if (puVar8 != (ushort *)0x0) {
      do {
        bVar11 = (byte)uVar12;
        if ((*puVar8 & 0x4000) == 0) break;
        iVar7 = iVar7 + -1;
        bVar11 = *(byte *)((int)puVar8 + 7);
        uVar12 = (uint)bVar11;
        if ((iVar7 == 0) || (0x7f < bVar11)) {
          puVar8 = (ushort *)0x0;
        }
        else {
          puVar8 = (ushort *)(size_00 + uVar12 * 8);
        }
      } while (puVar8 != (ushort *)0x0);
      if ((puVar8 != (ushort *)0x0) && (-1 < *(char *)((int)puVar8 + 7))) {
        bVar1 = *(byte *)((int)puVar8 + 7);
        puVar9 = (ushort *)(size_00 + (uint)bVar1 * 8);
        if ((*puVar9 & 0x4000) != 0) {
          iVar5 = (**(code **)(aadMem + 0x738))(0x1000,0x30);
          *(int *)(iVar4 + 0x7ec) = iVar5;
          iVar7 = aadMem;
          if (iVar5 != 0) {
            uVar3 = *puVar9;
            iVar5 = aadMem + ((uint)uVar3 & 0x3fff);
            bVar2 = *(byte *)(iVar5 + 0xa08);
            *(uint *)(iVar4 + 0x7f0) = (uint)bVar2;
            if (bVar2 < 0xfe) {
              *(undefined *)(iVar5 + 0xa08) = 0xff;
              *(uint *)(iVar4 + 0x7f4) = (uint)uVar3 & 0x3fff;
              *(int *)(iVar4 + 0x7f8) = (uint)puVar8[1] << 3;
              *(int *)(iVar4 + 0x7fc) = (uint)puVar9[1] << 3;
              *(int *)(iVar4 + 0x800) = (uint)puVar9[2] << 3;
              uVar3 = puVar8[2];
              puVar8[2] = puVar9[2];
              puVar9[2] = uVar3;
              uVar3 = *puVar8;
              *puVar8 = *puVar9;
              *puVar9 = uVar3;
              puVar9[1] = puVar8[1] + puVar8[2];
              if ((-1 < *(char *)((int)puVar9 + 7)) &&
                 (puVar8 = (ushort *)(size_00 + (uint)*(byte *)((int)puVar9 + 7) * 8),
                 (*puVar8 & 0x4000) == 0)) {
                puVar9[2] = puVar9[2] + puVar8[2];
                bVar2 = *(byte *)((int)puVar8 + 7);
                *puVar8 = 0;
                *(byte *)((int)puVar9 + 7) = bVar2;
                if (-1 < (int)((uint)bVar2 << 0x18)) {
                  size_00[(uint)*(byte *)((int)puVar9 + 7) * 8 + 6] = bVar1;
                }
              }
              (&DAT_0000160b)[aadMem + *(int *)(iVar4 + 0x7f0) * 4] = bVar11;
              *puVar10 = 2;
              return;
            }
            (**(code **)(iVar7 + 0x73c))(*(undefined4 *)(iVar4 + 0x7ec));
          }
        }
      }
    }
    *puVar10 = 0;
  }
  else {
    if (1 < iVar7) {
      if (iVar7 == 2) {
        lVar6 = SpuIsTransferCompleted(0);
        if (lVar6 != 0) {
          size_00 = (undefined *)0x1000;
          if (*(undefined **)(iVar4 + 0x800) < &DAT_00001001) {
            size_00 = *(undefined **)(iVar4 + 0x800);
          }
          SpuSetTransferStartAddr(*(ulong *)(iVar4 + 0x7fc));
          SpuRead(*(uchar **)(iVar4 + 0x7ec),(ulong)size_00);
          *(undefined **)(iVar4 + 0x804) = size_00;
          *(undefined4 *)(iVar4 + 0x7e8) = 3;
        }
      }
      else {
        if ((iVar7 == 3) && (lVar6 = SpuIsTransferCompleted(0), lVar6 != 0)) {
          SpuSetTransferStartAddr(*(ulong *)(iVar4 + 0x7f8));
          size = *(ulong *)(iVar4 + 0x804);
          SpuWrite(*(uchar **)(iVar4 + 0x7ec),size);
          *(int *)(iVar4 + 0x7fc) = *(int *)(iVar4 + 0x7fc) + size;
          iVar7 = *(int *)(iVar4 + 0x800) - size;
          *(int *)(iVar4 + 0x800) = iVar7;
          *(int *)(iVar4 + 0x7f8) = *(int *)(iVar4 + 0x7f8) + size;
          if (iVar7 == 0) {
            (**(code **)(aadMem + 0x73c))(*(undefined4 *)(iVar4 + 0x7ec));
            *(undefined *)(aadMem + *(int *)(iVar4 + 0x7f4) + 0xa08) = *(undefined *)(iVar4 + 0x7f0)
            ;
            *(undefined4 *)(iVar4 + 0x7e8) = 0;
            gSramCheckRequest = 1;
          }
          else {
            *(undefined4 *)(iVar4 + 0x7e8) = 2;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadIsSfxLoaded(uint toneID)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(aadMem + toneID + 0x808);
  iVar2 = 1;
  if ((0xfd < bVar1) && (iVar2 = -1, bVar1 != 0xfe)) {
    return 0;
  }
  return iVar2;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadInitSequenceSlot(_AadSequenceSlot *slot)

{
  undefined uVar1;
  int iVar2;
  _AadSequenceSlot *p_Var3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  slot->status = 0;
  slot->selectedDynamicBank = slot->sequenceAssignedDynamicBank;
  slot->slotFlags = slot->slotFlags & 1;
  iVar6 = *(int *)((uint)slot->sequenceNumberAssigned * 4 +
                  *(int *)(aadMem + slot->sequenceAssignedDynamicBank * 4 + 0x4f0));
  p_Var3 = slot;
  iVar5 = iVar6;
  do {
    if (iVar4 < (int)(uint)*(ushort *)(iVar6 + 0xc)) {
      p_Var3->sequencePosition[0] = (_func_9 *)(iVar6 + *(int *)(iVar5 + 0x10));
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
    iVar5 = iVar5 + 4;
  } while (iVar4 < 0x10);
  iVar5 = 0;
  p_Var3 = slot;
  do {
    iVar4 = (int)&(slot->tempo).currentTick + iVar5;
    uVar1 = *(undefined *)&slot->sequenceAssignedDynamicBank;
    iVar5 = iVar5 + 1;
    *(undefined *)(iVar4 + 0x590) = 0xff;
    *(undefined *)(iVar4 + 0x5a0) = 0x7f;
    *(undefined *)(iVar4 + 0x5b0) = 0x3f;
    *(undefined *)(iVar4 + 0x560) = uVar1;
    p_Var3->pitchWheel[0] = 0x2000;
    p_Var3 = (_AadSequenceSlot *)((int)&(p_Var3->tempo).currentTick + 2);
  } while (iVar5 < 0x10);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadWaitForSramTransferComplete(void)

{
  long lVar1;
  int iVar2;
  
  iVar2 = 100000;
  do {
    lVar1 = SpuIsTransferCompleted(0);
    if (lVar1 != 0) {
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadInitReverb(void)

{
  int mode;
  int iVar1;
  
  mode = aadGetReverbMode();
  SpuSetReverbModeType(mode);
  SpuSetReverbVoice(0,0xffffff);
  mode = aadWaitForSramTransferComplete();
  if (mode != 0) {
    mode = aadGetReverbMode();
    SpuClearReverbWorkArea(mode);
  }
  mode = aadGetReverbDepth();
  iVar1 = aadGetReverbDepth();
  SpuSetReverbModeDepth((short)mode,(short)iVar1);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadShutdownReverb(void)

{
  int mode;
  
  mode = aadWaitForSramTransferComplete();
  if (mode != 0) {
    mode = aadGetReverbMode();
    SpuClearReverbWorkArea(mode);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

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

/* File: C:\kain2\game\PSX\AADLIB.C */

ulong aadGetReverbSize(void)

{
  int iVar1;
  
  iVar1 = aadGetReverbMode();
  return aadReverbModeSize[iVar1] + 0x30;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadGetDynamicBankStatus(int bank)

{
  return *(int *)(aadMem + bank * 4 + 0x500);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadGetNumDynamicSequences(int bank)

{
  int iVar1;
  int iVar2;
  
  iVar2 = aadMem + bank * 4;
  iVar1 = 0;
  if (*(int *)(iVar2 + 0x500) == 2) {
    iVar1 = *(int *)(*(int *)(iVar2 + 0x4d0) + 0x18);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadAssignDynamicSequence(int bank,int sequenceNumber,int slotNumber)

{
  undefined *puVar1;
  AadTempo *tempo;
  int iVar2;
  int iVar3;
  _AadSequenceSlot *slot;
  AadTempo AStack32;
  
  if (*(int *)(aadMem + bank * 4 + 0x500) == 2) {
    slot = *(_AadSequenceSlot **)(aadMem + slotNumber * 4 + 0x34);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

AadTempo * aadGetTempoFromDynamicSequence(int bank,int sequenceNumber,AadTempo *tempo)

{
  int iVar1;
  
  iVar1 = aadMem + bank * 4;
  if (*(int *)(iVar1 + 0x500) == 2) {
    iVar1 = *(int *)(sequenceNumber * 4 + *(int *)(iVar1 + 0x4f0));
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadSetSlotTempo(int slotNumber,AadTempo *tempo)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = aadMem;
  uVar2 = tempo->ppqn;
  iVar3 = *(int *)(aadMem + slotNumber * 4 + 0x34);
  uVar2 = (tempo->quarterNoteTime / uVar2) * 0x10000 +
          (tempo->quarterNoteTime % uVar2 << 0x10) / uVar2;
  *(uint *)(iVar3 + 8) = uVar2;
  *(undefined2 *)(iVar3 + 0x10) = (short)(aadUpdateRate[*(uint *)(iVar1 + 8) & 3] / uVar2);
  *(uint *)(iVar3 + 0xc) = aadUpdateRate[*(uint *)(iVar1 + 8) & 3] % *(uint *)(iVar3 + 8);
  *(ulong *)(iVar3 + 0x14) = tempo->quarterNoteTime;
  *(undefined2 *)(iVar3 + 0x12) = *(undefined2 *)&tempo->ppqn;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadStartSlot(int slotNumber)

{
  _AadSequenceSlot *slot;
  
  if (((slotNumber < *(int *)(aadMem + 4)) &&
      (slot = *(_AadSequenceSlot **)(aadMem + slotNumber * 4 + 0x34), (slot->status & 1) == 0)) &&
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadStopSlot(int slotNumber)

{
  _AadSequenceSlot *slot;
  
  if ((slotNumber < *(int *)(aadMem + 4)) &&
     (slot = *(_AadSequenceSlot **)(aadMem + slotNumber * 4 + 0x34),
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadStopAllSlots(void)

{
  int iVar1;
  int slotNumber;
  
  slotNumber = 0;
  if (0 < *(int *)(aadMem + 4)) {
    iVar1 = 0;
    do {
      iVar1 = *(int *)(aadMem + iVar1 + 0x34);
      if ((*(ushort *)(iVar1 + 0x540) & 1) != 0) {
        aadStopSlot(slotNumber);
      }
      *(undefined *)(iVar1 + 0x53e) = 0xff;
      slotNumber = slotNumber + 1;
      iVar1 = slotNumber * 4;
    } while (slotNumber < *(int *)(aadMem + 4));
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadDisableSlot(int slotNumber)

{
  int iVar1;
  
  if (slotNumber < *(int *)(aadMem + 4)) {
    iVar1 = *(int *)(aadMem + slotNumber * 4 + 0x34);
    *(byte *)(iVar1 + 0x550) = *(byte *)(iVar1 + 0x550) | 1;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadEnableSlot(int slotNumber)

{
  int iVar1;
  
  if (slotNumber < *(int *)(aadMem + 4)) {
    iVar1 = *(int *)(aadMem + slotNumber * 4 + 0x34);
    *(byte *)(iVar1 + 0x550) = *(byte *)(iVar1 + 0x550) & 0xfe;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadPauseSlot(int slotNumber)

{
  int iVar1;
  
  if (slotNumber < *(int *)(aadMem + 4)) {
    iVar1 = *(int *)(aadMem + slotNumber * 4 + 0x34);
    *(ushort *)(iVar1 + 0x540) = *(ushort *)(iVar1 + 0x540) & 0xfffe;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadResumeSlot(int slotNumber)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (slotNumber < *(int *)(aadMem + 4)) {
    iVar3 = *(int *)(aadMem + slotNumber * 4 + 0x34);
    iVar2 = 0;
    iVar1 = iVar3;
    if (*(char *)(iVar3 + 0x53e) != -1) {
      do {
        iVar2 = iVar2 + 1;
        *(byte *)(iVar1 + 0x3d8) = *(byte *)(iVar1 + 0x3d8) | 0x20;
        iVar1 = iVar3 + iVar2;
      } while (iVar2 < 0x10);
      *(ushort *)(iVar3 + 0x540) = *(ushort *)(iVar3 + 0x540) | 1;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

int aadGetSlotStatus(int slotNumber)

{
  return (uint)*(ushort *)(*(int *)(aadMem + slotNumber * 4 + 0x34) + 0x540);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadAllNotesOff(int slotNumber)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = 0;
  iVar5 = 0;
  iVar4 = 0x1dc;
  iVar6 = *(int *)(aadMem + slotNumber * 4 + 0x34);
  do {
    puVar2 = (uint *)(aadMem + iVar4);
    if ((*(byte *)(puVar2 + 2) & 0xf0) == *(byte *)(iVar6 + 0x551)) {
      *(undefined *)(puVar2 + 2) = 0xff;
      uVar3 = uVar3 | *puVar2;
      *(ushort *)((int)puVar2 + 0x12) = *(ushort *)((int)puVar2 + 0x12) | 2;
    }
    iVar1 = aadMem;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x1c;
  } while (iVar5 < 0x18);
  if (uVar3 != 0) {
    *(uint *)(aadMem + 0x4c4) = *(uint *)(aadMem + 0x4c4) | uVar3;
    *(uint *)(iVar1 + 0x4c8) = *(uint *)(iVar1 + 0x4c8) & ~uVar3;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadMuteChannels(_AadSequenceSlot *slot,ulong channelList)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = slot->delayedMuteMode & channelList;
  if (uVar1 != 0) {
    channelList = channelList & ~uVar1;
    slot->delayedMuteCmds = slot->delayedMuteCmds | (ushort)uVar1;
  }
  uVar6 = 0;
  uVar5 = 0;
  slot->channelMute = slot->channelMute | (ushort)channelList;
  uVar1 = 1;
  do {
    if ((channelList & uVar1) != 0) {
      iVar4 = 0;
      iVar3 = 0x1dc;
      do {
        puVar2 = (uint *)(aadMem + iVar3);
        if ((uint)*(byte *)(puVar2 + 2) == (slot->slotID | uVar5)) {
          *(undefined *)(puVar2 + 2) = 0xff;
          uVar6 = uVar6 | *puVar2;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x1c;
      } while (iVar4 < 0x18);
    }
    iVar3 = aadMem;
    uVar5 = uVar5 + 1;
    uVar1 = 1 << (uVar5 & 0x1f);
  } while ((int)uVar5 < 0x10);
  if (uVar6 != 0) {
    *(uint *)(aadMem + 0x4c4) = *(uint *)(aadMem + 0x4c4) | uVar6;
    *(uint *)(iVar3 + 0x4c8) = *(uint *)(iVar3 + 0x4c8) & ~uVar6;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

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

/* File: C:\kain2\game\PSX\AADLIB.C */

TDRFuncPtr_aadInstallEndSequenceCallback
aadInstallEndSequenceCallback
          (TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc,long data)

{
  int iVar1;
  TDRFuncPtr_aadInstallEndSequenceCallback pTVar2;
  
  iVar1 = aadMem;
  pTVar2 = *(TDRFuncPtr_aadInstallEndSequenceCallback *)(&DAT_00001bfc + aadMem);
  *(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc *)(&DAT_00001bfc + aadMem) = callbackProc;
  *(long *)(&DAT_00001c04 + iVar1) = data;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadSetUserVariable(int variableNumber,int value)

{
  (&DAT_00001c08)[aadMem + variableNumber] = (char)value;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadSetNoUpdateMode(int noUpdate)

{
  if (noUpdate != 0) {
    *(uint *)(aadMem + 0x24) = *(uint *)(aadMem + 0x24) | 2;
    return;
  }
  *(uint *)(aadMem + 0x24) = *(uint *)(aadMem + 0x24) & 0xfffffffd;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadPauseSound(void)

{
  int iVar1;
  ushort *pitch;
  int vNum;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(aadMem + 0x24) & 8) == 0) {
    *(uint *)(aadMem + 0x24) = *(uint *)(aadMem + 0x24) | 0xc;
    vNum = 0;
    iVar3 = 0x494;
    iVar2 = 0;
    do {
      pitch = (ushort *)(aadMem + iVar3);
      iVar3 = iVar3 + 2;
      iVar1 = aadMem + iVar2;
      iVar2 = iVar2 + 0x1c;
      *(ushort *)(iVar1 + 0x1ee) = *(ushort *)(iVar1 + 0x1ee) & 0xfffd;
      SpuGetVoicePitch(vNum,pitch);
      SpuSetVoicePitch(vNum,0);
      vNum = vNum + 1;
    } while (vNum < 0x18);
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadCancelPauseSound(void)

{
  *(uint *)(aadMem + 0x24) = *(uint *)(aadMem + 0x24) & 0xfffffff3;
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

/* File: C:\kain2\game\PSX\AADLIB.C */

void aadResumeSound(void)

{
  int vNum;
  int iVar1;
  
  if ((*(uint *)(aadMem + 0x24) & 8) != 0) {
    *(uint *)(aadMem + 0x24) = *(uint *)(aadMem + 0x24) & 0xfffffff3;
    vNum = 0;
    iVar1 = 0;
    do {
      if ((*(ushort *)(aadMem + iVar1 + 0x1ee) & 2) == 0) {
        SpuSetVoicePitch(vNum,*(ushort *)(aadMem + vNum * 2 + 0x494));
      }
      vNum = vNum + 1;
      iVar1 = iVar1 + 0x1c;
    } while (vNum < 0x18);
  }
  return;
}





