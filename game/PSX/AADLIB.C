#include "THISDUST.H"
#include "AADLIB.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetMemorySize(struct AadInitAttr *attributes /*$a0*/)
 // line 37, offset 0x80053164
	/* begin block 1 */
		// Start line: 74
	/* end block 1 */
	// End Line: 75

	/* begin block 2 */
		// Start line: 75
	/* end block 2 */
	// End Line: 76

ulong aadGetMemorySize(AadInitAttr *attributes)

{
  return (uint)*(ushort *)((int)&attributes->updateMode + 2) * 0x5d4 + 0x1bec;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ aadInit(struct AadInitAttr *attributes /*$s1*/, unsigned char *memoryPtr /*$s0*/)
 // line 43, offset 0x80053190
	/* begin block 1 */
		// Start line: 44
		// Start offset: 0x80053190
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $v1
	// 		unsigned long size; // $v0
	// 		int slotNumber; // $a2
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80053460
	// End Line: 181

	/* begin block 2 */
		// Start line: 86
	/* end block 2 */
	// End Line: 87

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort aadInit(AadInitAttr *attributes,uchar *memoryPtr)

{
  ushort uVar1;
  ulong __n;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  aadGp = GetGp();
  EnterCriticalSection();
  __n = aadGetMemorySize(attributes);
                    /* WARNING: Read-only address (ram,0x800cf598) is written */
  aadMem = (AadMemoryStruct *)memoryPtr;
  if (memoryPtr == (uchar *)0x0) {
    uVar1 = 0x1009;
  }
  else {
    memset(memoryPtr,0,__n);
    uVar1 = 0x1008;
    if ((attributes->numSlots != 0) &&
       (uVar1 = 0x1008, attributes->nonBlockLoadProc != (_func_4504 *)0x0)) {
      if (attributes->nonBlockBufferedLoadProc == (_func_4505 *)0x0) {
        uVar1 = 0x1008;
      }
      else {
        p_Ram000006d0 = attributes->nonBlockLoadProc;
        p_Ram000006d4 = attributes->nonBlockBufferedLoadProc;
        p_Ram000006d8 = attributes->memoryMallocProc;
        uRam000006dc = *(undefined *)&attributes->memoryFreeProc;
        iRam000006cc = attributes->numSlots;
        memset((void *)0x770,0xff,0x200);
        memset((void *)0x970,0xff,0x200);
        uRam00001b56 = 0;
        uRam0000175a = 0xff;
        uRam00001b54 = 1;
        uRam00001754 = 0x8000;
        uRam00001756 = 0x202;
        uRam00001758 = 0x8e5a;
        uRam0000175b = 0xff;
        aadPurgeLoadQueue();
        SpuInit();
        SpuSetCommonMasterVolume(0,0);
        iVar6 = 0;
        if (*(short *)((int)&attributes->updateMode + 2) != 0) {
          iVar7 = 0x1bec;
          do {
            iVar4 = 0;
            *(int *)(iVar6 * 4 + 0x1c) = iVar7;
            *(undefined *)(iVar7 + 0x53f) = (char)iVar6;
            *(undefined *)(iVar7 + 0x53e) = 0xff;
            *(undefined *)(iVar7 + 0x549) = (char)(iVar6 << 4);
            *(undefined *)(iVar7 + 0x54a) = 0x7f;
            *(undefined *)(iVar7 + 0x54b) = 0x3f;
            *(undefined4 *)(iVar7 + 0x54c) = 0x11;
            iVar3 = iVar7;
            do {
              iVar2 = iVar7 + iVar4;
              *(undefined *)(iVar2 + 0x584) = 0xff;
              *(undefined *)(iVar2 + 0x594) = 0;
              *(undefined *)(iVar2 + 0x5a4) = 0x7f;
              *(undefined *)(iVar2 + 0x5b4) = 0x3f;
              *(undefined2 *)(iVar3 + 0x564) = 0x2000;
              iVar4 = iVar4 + 1;
              iVar3 = iVar3 + 2;
            } while (iVar4 < 0x10);
            *(int *)(iVar7 + 0x538) = iVar7;
            *(undefined *)(iVar7 + 0x53c) = (char)iVar6;
            iVar6 = iVar6 + 1;
            iVar7 = iVar7 + 0x5d4;
          } while (iVar6 < (int)(uint)*(ushort *)((int)&attributes->updateMode + 2));
        }
        uRam000001c0 = 0x3039;
        uRam000001c2 = 0x7f;
        mainMenuScreen = *(undefined *)((int)&attributes->updateMode + 2);
        DAT_00000005 = *(byte *)&attributes->updateMode;
        uVar5 = 0;
        DAT_00000010 = 0x7f;
        uRam00000011 = 0x7f;
        iVar6 = 0;
        uRam00001b60 = 0;
        uRam00001b5c = 0;
        do {
          *(undefined *)(iVar6 + 0x1cc) = 0xff;
          *(int *)(iVar6 + 0x1c4) = 1 << (uVar5 & 0x1f);
          *(undefined *)(iVar6 + 0x1d5) = (char)uVar5;
          uVar5 = uVar5 + 1;
          iVar6 = iVar6 + 0x1c;
        } while ((int)uVar5 < 0x18);
        uRam000004ac = 0;
        uRam000004b0 = 0;
        uRam000004b4 = 0;
        if (DAT_00000005 < 4) {
          aadInstallUpdateFunc(aadSlotUpdateWrapper,(&aadHblanksPerUpdate)[DAT_00000005]);
        }
        _DAT_00000012 = 0;
        ExitCriticalSection();
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInstallUpdateFunc(TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr /*$s0*/, unsigned short hblanksPerUpdate /*$s1*/)
 // line 184, offset 0x80053474
	/* begin block 1 */
		// Start line: 475
	/* end block 1 */
	// End Line: 476

void aadInstallUpdateFunc
               (TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr updateFuncPtr,ushort hblanksPerUpdate)

{
  EnterCriticalSection();
  __hblankEvent = OpenEvent();
  EnableEvent();
  SetRCnt(0xf2000001,hblanksPerUpdate,0x1000);
  StartRCnt(0xf2000001);
  ExitCriticalSection();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInitVolume()
 // line 197, offset 0x800534f0
	/* begin block 1 */
		// Start line: 501
	/* end block 1 */
	// End Line: 502

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadInitVolume(void)

{
  uRam00000006 = 0;
  SpuSetCommonCDMix(0);
  SpuSetCommonMasterVolume(0,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetMasterVolume(int volume /*$a0*/)
 // line 208, offset 0x80053524
	/* begin block 1 */
		// Start line: 527
	/* end block 1 */
	// End Line: 528

	/* begin block 2 */
		// Start line: 529
	/* end block 2 */
	// End Line: 530

void aadSetMasterVolume(int volume)

{
  sRam00000006 = (short)volume;
  SpuSetCommonMasterVolume((int)sRam00000006,(int)sRam00000006);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStartMasterVolumeFade(int targetVolume /*$a0*/, int volumeStep /*$a1*/, TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback /*$a2*/)
 // line 217, offset 0x80053554
	/* begin block 1 */
		// Start line: 547
	/* end block 1 */
	// End Line: 548

	/* begin block 2 */
		// Start line: 549
	/* end block 2 */
	// End Line: 550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadStartMasterVolumeFade
               (int targetVolume,int volumeStep,
               TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback)

{
  _DAT_00000008 = (short)volumeStep;
  _DAT_0000000a = (short)targetVolume;
  _DAT_0000000c = fadeCompleteCallback;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetSfxMasterVolume(int volume /*$a0*/)
 // line 227, offset 0x8005356c
	/* begin block 1 */
		// Start line: 567
	/* end block 1 */
	// End Line: 568

	/* begin block 2 */
		// Start line: 569
	/* end block 2 */
	// End Line: 570

void aadSetSfxMasterVolume(int volume)

{
  DAT_00000010 = (char)volume;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetMusicMasterVolume(int volume /*$a0*/)
 // line 235, offset 0x80053578
	/* begin block 1 */
		// Start line: 236
		// Start offset: 0x80053578
		// Variables:
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x800535D4
	// End Line: 245

	/* begin block 2 */
		// Start line: 583
	/* end block 2 */
	// End Line: 584

	/* begin block 3 */
		// Start line: 587
	/* end block 3 */
	// End Line: 588

void aadSetMusicMasterVolume(int volume)

{
  int iVar1;
  int iVar2;
  
  uRam00000011 = (undefined)volume;
  iVar2 = 0;
  if (mainMenuScreen != 0) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      aadUpdateSlotVolPan(*(_AadSequenceSlot **)(iVar1 + 0x1c));
      iVar1 = iVar2 * 4;
    } while (iVar2 < (int)(uint)mainMenuScreen);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStartMusicMasterVolFade(int targetVolume /*$a0*/, int volumeStep /*$a1*/, TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback /*$a2*/)
 // line 247, offset 0x800535e4
	/* begin block 1 */
		// Start line: 612
	/* end block 1 */
	// End Line: 613

	/* begin block 2 */
		// Start line: 614
	/* end block 2 */
	// End Line: 615

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadStartMusicMasterVolFade
               (int targetVolume,int volumeStep,
               TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback fadeCompleteCallback)

{
  _DAT_00000014 = (short)volumeStep;
  uRam00000016 = (short)targetVolume;
  _mcardSaveMenu = fadeCompleteCallback;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadShutdown()
 // line 283, offset 0x800535fc
	/* begin block 1 */
		// Start line: 562
	/* end block 1 */
	// End Line: 563

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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
  _DAT_00000012 = _DAT_00000012 | 2;
  ExitCriticalSection();
  uVar2 = 0xffffff;
  SpuSetKey(0,0xffffff);
  uVar1 = aadGetReverbMode();
  SpuClearReverbWorkArea(uVar1,uVar2,in_a2);
  SpuQuit();
  aadMem = (AadMemoryStruct *)0x0;
                    /* WARNING: Read-only address (ram,0x800cf598) is written */
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ aadSlotUpdateWrapper()
 // line 319, offset 0x80053684
	/* begin block 1 */
		// Start line: 320
		// Start offset: 0x80053684
		// Variables:
	// 		unsigned long curGp; // $s0
	/* end block 1 */
	// End offset: 0x80053684
	// End Line: 320

	/* begin block 2 */
		// Start line: 724
	/* end block 2 */
	// End Line: 725

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
 // line 336, offset 0x800536c8
	/* begin block 1 */
		// Start line: 337
		// Start offset: 0x800536C8
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s1
	// 		struct AadSeqEvent *seqEventPtr; // $a1
	// 		int slotNumber; // $fp
	// 		int i; // $a3
	// 		int fadeComplete; // $v1
	// 		int track; // $s4
	// 		int newVol; // $s0

		/* begin block 1.1 */
			// Start line: 352
			// Start offset: 0x80053710
			// Variables:
		// 		unsigned long vmask; // $a2
		/* end block 1.1 */
		// End offset: 0x80053788
		// End Line: 367
	/* end block 1 */
	// End offset: 0x80053BC4
	// End Line: 556

	/* begin block 2 */
		// Start line: 759
	/* end block 2 */
	// End Line: 760

	/* begin block 3 */
		// Start line: 768
	/* end block 3 */
	// End Line: 769

/* WARNING: Removing unreachable block (ram,0x800536fc) */
/* WARNING: Removing unreachable block (ram,0x80053710) */
/* WARNING: Removing unreachable block (ram,0x8005372c) */
/* WARNING: Removing unreachable block (ram,0x8005374c) */
/* WARNING: Removing unreachable block (ram,0x80053760) */
/* WARNING: Removing unreachable block (ram,0x80053768) */
/* WARNING: Removing unreachable block (ram,0x80053770) */
/* WARNING: Removing unreachable block (ram,0x80053740) */
/* WARNING: Removing unreachable block (ram,0x80053774) */
/* WARNING: Removing unreachable block (ram,0x80053778) */
/* WARNING: Removing unreachable block (ram,0x80053788) */
/* WARNING: Removing unreachable block (ram,0x800537a4) */
/* WARNING: Removing unreachable block (ram,0x800537b4) */
/* WARNING: Removing unreachable block (ram,0x800537b8) */
/* WARNING: Removing unreachable block (ram,0x800537d8) */
/* WARNING: Removing unreachable block (ram,0x800537ec) */
/* WARNING: Removing unreachable block (ram,0x8005381c) */
/* WARNING: Removing unreachable block (ram,0x80053830) */
/* WARNING: Removing unreachable block (ram,0x8005383c) */
/* WARNING: Removing unreachable block (ram,0x8005384c) */
/* WARNING: Removing unreachable block (ram,0x80053860) */
/* WARNING: Removing unreachable block (ram,0x80053864) */
/* WARNING: Removing unreachable block (ram,0x80053874) */
/* WARNING: Removing unreachable block (ram,0x80053888) */
/* WARNING: Removing unreachable block (ram,0x8005389c) */
/* WARNING: Removing unreachable block (ram,0x800538ac) */
/* WARNING: Removing unreachable block (ram,0x800538bc) */
/* WARNING: Removing unreachable block (ram,0x800538cc) */
/* WARNING: Removing unreachable block (ram,0x800538d8) */
/* WARNING: Removing unreachable block (ram,0x80053914) */
/* WARNING: Removing unreachable block (ram,0x80053940) */
/* WARNING: Removing unreachable block (ram,0x80053944) */
/* WARNING: Removing unreachable block (ram,0x8005395c) */
/* WARNING: Removing unreachable block (ram,0x80053974) */
/* WARNING: Removing unreachable block (ram,0x80053990) */
/* WARNING: Removing unreachable block (ram,0x80053998) */
/* WARNING: Removing unreachable block (ram,0x800539a8) */
/* WARNING: Removing unreachable block (ram,0x800539ac) */
/* WARNING: Removing unreachable block (ram,0x800539f4) */
/* WARNING: Removing unreachable block (ram,0x80053a00) */
/* WARNING: Removing unreachable block (ram,0x80053a18) */
/* WARNING: Removing unreachable block (ram,0x80053a38) */
/* WARNING: Removing unreachable block (ram,0x80053a40) */
/* WARNING: Removing unreachable block (ram,0x80053a84) */
/* WARNING: Removing unreachable block (ram,0x80053a98) */
/* WARNING: Removing unreachable block (ram,0x80053ab0) */
/* WARNING: Removing unreachable block (ram,0x80053ac8) */
/* WARNING: Removing unreachable block (ram,0x80053adc) */
/* WARNING: Removing unreachable block (ram,0x80053abc) */
/* WARNING: Removing unreachable block (ram,0x80053ae0) */
/* WARNING: Removing unreachable block (ram,0x80053ae8) */
/* WARNING: Removing unreachable block (ram,0x80053b04) */
/* WARNING: Removing unreachable block (ram,0x80053b0c) */
/* WARNING: Removing unreachable block (ram,0x80053b1c) */
/* WARNING: Removing unreachable block (ram,0x80053b2c) */
/* WARNING: Removing unreachable block (ram,0x80053b40) */
/* WARNING: Removing unreachable block (ram,0x80053b60) */
/* WARNING: Removing unreachable block (ram,0x80053b74) */
/* WARNING: Removing unreachable block (ram,0x80053b4c) */
/* WARNING: Removing unreachable block (ram,0x80053b78) */
/* WARNING: Removing unreachable block (ram,0x80053b80) */
/* WARNING: Removing unreachable block (ram,0x80053b9c) */
/* WARNING: Removing unreachable block (ram,0x80053ba4) */
/* WARNING: Removing unreachable block (ram,0x80053bac) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadSlotUpdate(void)

{
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadCreateFourCharID(char a /*$a0*/, char b /*$a1*/, char c /*$a2*/, char d /*$a3*/)
 // line 600, offset 0x80053bf4
	/* begin block 1 */
		// Start line: 1381
	/* end block 1 */
	// End Line: 1382

	/* begin block 2 */
		// Start line: 1382
	/* end block 2 */
	// End Line: 1383

ulong aadCreateFourCharID(char a,char b,char c,char d)

{
  return CONCAT13(a,CONCAT12(b,CONCAT11(c,d)));
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ aadLoadDynamicSoundBank(char *sndFileName /*$s1*/, char *smpFileName /*$s2*/, int dynamicBankIndex /*$s0*/, int loadOption /*$s3*/, TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc /*stack 16*/)
 // line 608, offset 0x80053c1c
	/* begin block 1 */
		// Start line: 609
		// Start offset: 0x80053C1C
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80053D34
	// End Line: 661

	/* begin block 2 */
		// Start line: 1397
	/* end block 2 */
	// End Line: 1398

ushort aadLoadDynamicSoundBank
                 (char *sndFileName,char *smpFileName,int dynamicBankIndex,int loadOption,
                 TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    pcVar1 = (char *)(iVar3 + 0x4e8);
    iVar3 = iVar3 + 1;
    if (*pcVar1 == '\x01') {
      return 0x1006;
    }
  } while (iVar3 < 2);
  uVar2 = 0x1005;
  if (dynamicBankIndex < 2) {
    if ((*(char *)(dynamicBankIndex + 0x4e8) == '\x02') &&
       (*(int *)(dynamicBankIndex * 4 + 0x4ec) != 0)) {
      aadFreeDynamicSoundBank(dynamicBankIndex);
    }
    *(undefined *)(dynamicBankIndex + 0x4e8) = 1;
    uRam000006b0 = (undefined2)dynamicBankIndex;
    uRam000006b2 = (undefined2)loadOption;
    uRam000006c0 = 0;
    pTRam000006b4 = retProc;
    pcRam000006a8 = sndFileName;
    pcRam000006ac = smpFileName;
    (*pcRam000006cc)(sndFileName,aadLoadDynamicSoundBankReturn,0x6a8,0,dynamicBankIndex * 4 + 0x4ec,
                     (uint)bRam000006dc);
    uVar2 = 0;
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSoundBankReturn(void *loadedDataPtr /*$a0*/, void *data /*$s2*/, void *data2 /*$a2*/)
 // line 666, offset 0x80053d50
	/* begin block 1 */
		// Start line: 667
		// Start offset: 0x80053D50
		// Variables:
	// 		unsigned short error; // $v1
	/* end block 1 */
	// End offset: 0x80053E20
	// End Line: 737

	/* begin block 2 */
		// Start line: 1565
	/* end block 2 */
	// End Line: 1566

void aadLoadDynamicSoundBankReturn(void *loadedDataPtr,void *data,void *data2)

{
  ushort uVar1;
  uint dynamicBankIndex;
  
  dynamicBankIndex = (uint)*(ushort *)((int)data + 8);
  uVar1 = aadOpenDynamicSoundBank((uchar *)loadedDataPtr,dynamicBankIndex);
  if (uVar1 == 0) {
    uRam000006c4 = 0;
    uRam000006c8 = 0;
    (*pcRam000006d0)(*(undefined4 *)((int)data + 4),aadLoadDynamicSoundBankReturn2,data,0);
  }
  else {
    *(byte *)(dynamicBankIndex + 0x4e8) = (byte)uVar1 | 0x80;
    if (*(int *)(dynamicBankIndex * 4 + 0x4ec) != 0) {
      (*pcRam000006d8)();
      *(undefined4 *)(dynamicBankIndex * 4 + 0x4ec) = 0;
    }
    if (*(code **)((int)data + 0xc) != (code *)0x0) {
      (**(code **)((int)data + 0xc))(dynamicBankIndex,(uint)uVar1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSoundBankReturn2(void *loadedDataPtr /*$a0*/, long loadedDataSize /*$s2*/, short status /*$s5*/, void *data1 /*$a3*/, void *data2 /*stack 16*/)
 // line 747, offset 0x80053e3c
	/* begin block 1 */
		// Start line: 748
		// Start offset: 0x80053E3C
		// Variables:
	// 		unsigned char *dataPtr; // $s1
	// 		struct AadDynamicBankLoadInfo *info; // $s0
	// 		unsigned short dynamicBankIndex; // $s3

		/* begin block 1.1 */
			// Start line: 832
			// Start offset: 0x80053FE8
			// Variables:
		// 		int i; // $a2
		/* end block 1.1 */
		// End offset: 0x8005407C
		// End Line: 846
	/* end block 1 */
	// End offset: 0x8005407C
	// End Line: 848

	/* begin block 2 */
		// Start line: 1735
	/* end block 2 */
	// End Line: 1736

void aadLoadDynamicSoundBankReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  ulong uVar1;
  int *piVar2;
  int iVar3;
  undefined2 in_register_0000001a;
  uint uVar4;
  code *pcVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  uVar4 = CONCAT22(in_register_0000001a,status);
  iVar8 = (int)(uVar4 << 0x10) >> 0x10;
  uVar7 = (uint)*(ushort *)((int)data1 + 8);
  if (iVar8 < 0x100) {
    if ((*(uint *)((int)data1 + 0x18) & 1) == 0) {
      puVar6 = (undefined4 *)((int)loadedDataPtr + 4);
      *(uint *)((int)data1 + 0x18) = *(uint *)((int)data1 + 0x18) | 1;
      loadedDataPtr = (void *)((int)loadedDataPtr + 8);
      loadedDataSize = loadedDataSize - 8;
      *(undefined4 *)((int)data1 + 0x10) = *puVar6;
      if ((*(short *)((int)data1 + 10) == 0) || (*(short *)((int)data1 + 10) != 1)) {
        *(undefined4 *)((int)data1 + 0x14) = 0x482e0;
      }
      else {
        uVar1 = aadGetReverbSize();
        *(int *)((int)data1 + 0x14) = (0x80000 - *(int *)((int)data1 + 0x10)) - uVar1;
      }
      *(undefined4 *)(uVar7 * 4 + 0x4f4) = *(undefined4 *)((int)data1 + 0x14);
      *(undefined4 *)(uVar7 * 4 + 0x4fc) = *(undefined4 *)((int)data1 + 0x10);
      *(undefined *)(uVar7 + 0x504) = *(undefined *)((int)data1 + 10);
    }
    do {
      iVar8 = SpuIsTransferCompleted(0);
    } while (iVar8 == 0);
    SpuSetTransferStartAddr(*(uint *)((int)data1 + 0x14));
    SpuWrite((word *)loadedDataPtr,loadedDataSize,uVar4);
    *(int *)((int)data1 + 0x14) = *(int *)((int)data1 + 0x14) + loadedDataSize;
    if (status != 1) {
      return;
    }
    iVar8 = 0;
    if (*(short *)(*(int *)(uVar7 * 4 + 0x4b8) + 0xe) != 0) {
      do {
        iVar3 = uVar7 * 4;
        piVar2 = (int *)(iVar8 * 4 + *(int *)(iVar3 + 0x4d0));
        *piVar2 = *piVar2 + *(int *)(iVar3 + 0x4f4);
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)(uint)*(ushort *)(*(int *)(iVar3 + 0x4b8) + 0xe));
    }
    *(undefined *)(uVar7 + 0x4e8) = 2;
    pcVar5 = *(code **)((int)data1 + 0xc);
    iVar8 = 0;
  }
  else {
    if ((*(uint *)((int)data1 + 0x18) & 2) != 0) {
      return;
    }
    *(uint *)((int)data1 + 0x18) = *(uint *)((int)data1 + 0x18) | 2;
    *(byte *)(uVar7 + 0x4e8) = (byte)((uVar4 << 0x10) >> 0x18) | 0x80;
    if (*(int *)(uVar7 * 4 + 0x4ec) != 0) {
      (*pcRam000006d8)();
      *(undefined4 *)(uVar7 * 4 + 0x4ec) = 0;
    }
    pcVar5 = *(code **)((int)data1 + 0xc);
  }
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(uVar7,iVar8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadFreeLoadBuffer()
 // line 854, offset 0x800540a0
	/* begin block 1 */
		// Start line: 1982
	/* end block 1 */
	// End Line: 1983

	/* begin block 2 */
		// Start line: 1983
	/* end block 2 */
	// End Line: 1984

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadFreeLoadBuffer(void)

{
  if (iRam000006c4 != 0) {
    (*pcRam000006d8)();
    iRam000006c4 = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ aadFreeDynamicSoundBank(int dynamicBankIndex /*$a0*/)
 // line 864, offset 0x800540e8
	/* begin block 1 */
		// Start line: 2003
	/* end block 1 */
	// End Line: 2004

ushort aadFreeDynamicSoundBank(int dynamicBankIndex)

{
  ushort uVar1;
  int iVar2;
  
  if (dynamicBankIndex < 2) {
    iVar2 = dynamicBankIndex * 4;
    if (*(char *)(dynamicBankIndex + 0x4e8) == '\x02') {
      uVar1 = 0x1007;
      if (*(int *)(iVar2 + 0x4ec) != 0) {
        *(undefined *)(dynamicBankIndex + 0x4e8) = 0;
        (*pcRam000006d8)(*(undefined4 *)(iVar2 + 0x4ec));
        uVar1 = 0;
        *(undefined4 *)(iVar2 + 0x4ec) = 0;
      }
    }
    else {
      uVar1 = 0x1007;
    }
  }
  else {
    uVar1 = 0x1005;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ aadOpenDynamicSoundBank(unsigned char *soundBank /*$a0*/, int dynamicBankIndex /*$s1*/)
 // line 894, offset 0x8005417c
	/* begin block 1 */
		// Start line: 895
		// Start offset: 0x8005417C
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
	// End offset: 0x80054288
	// End Line: 943

	/* begin block 2 */
		// Start line: 2070
	/* end block 2 */
	// End Line: 2071

ushort aadOpenDynamicSoundBank(uchar *soundBank,int dynamicBankIndex)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ulong uVar6;
  uchar *puVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  
  if (dynamicBankIndex < 2) {
    uVar6 = aadCreateFourCharID('a','S','N','D');
    uVar5 = 0x1001;
    if ((*(ulong *)soundBank == uVar6) && (uVar5 = 0x1002, *(short *)(soundBank + 8) == 0x106)) {
      iVar10 = 0;
      dynamicBankIndex = dynamicBankIndex * 4;
      bVar1 = soundBank[0xb];
      uVar5 = *(ushort *)(soundBank + 0xc);
      uVar3 = *(ushort *)(soundBank + 0xe);
      bVar2 = soundBank[0x10];
      uVar4 = *(ushort *)(soundBank + 0x12);
      puVar7 = soundBank + *(int *)(soundBank + 4);
      *(uchar **)(dynamicBankIndex + 0x4c0) = puVar7;
      puVar7 = puVar7 + (uint)bVar1 * 8;
      *(uchar **)(dynamicBankIndex + 0x4c8) = puVar7;
      piVar9 = (int *)(puVar7 + (uint)uVar5 * 0x10 + (uint)uVar3 * 4);
      piVar8 = piVar9 + bVar2;
      *(uchar **)(dynamicBankIndex + 0x4b8) = soundBank;
      *(uchar **)(dynamicBankIndex + 0x4d0) = puVar7 + (uint)uVar5 * 0x10;
      *(int **)(dynamicBankIndex + 0x4d8) = piVar9;
      *(int **)(dynamicBankIndex + 0x4e0) = piVar8;
      if (soundBank[0x10] != '\0') {
        do {
          *(int *)(iVar10 * 4 + *(int *)(dynamicBankIndex + 0x4d8)) =
               (int)piVar8 + *piVar9 + (uint)uVar4 * 4;
          iVar10 = iVar10 + 1;
          piVar9 = piVar9 + 1;
        } while (iVar10 < (int)(uint)soundBank[0x10]);
      }
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0x1005;
  }
  return uVar5;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ aadLoadDynamicSfx(char *fileName /*$a3*/, unsigned long userData /*$s1*/, TDRFuncPtr_aadLoadDynamicSfx2userReturnProc userReturnProc /*$s2*/)
 // line 960, offset 0x8005429c
	/* begin block 1 */
		// Start line: 961
		// Start offset: 0x8005429C
		// Variables:
	// 		struct AadDynamicLoadRequest *loadReq; // $s0
	/* end block 1 */
	// End offset: 0x80054374
	// End Line: 986

	/* begin block 2 */
		// Start line: 2274
	/* end block 2 */
	// End Line: 2275

ushort aadLoadDynamicSfx(char *fileName,ulong userData,
                        TDRFuncPtr_aadLoadDynamicSfx2userReturnProc userReturnProc)

{
  ushort uVar1;
  int iVar2;
  
  if (bRam000006df < 8) {
    iVar2 = (uint)bRam000006dd * 0x34;
    *(undefined2 *)(iVar2 + 0x508) = 0;
    uVar1 = uRam00001b5a & 0x3fff;
    uRam00001b5a = uRam00001b5a + 1;
    *(ushort *)(iVar2 + 0x50a) = uVar1 | 0x4000;
    strncpy((char *)(iVar2 + 0x510),fileName,0x27);
    *(ulong *)(iVar2 + 0x50c) = userData;
    *(TDRFuncPtr_aadLoadDynamicSfx2userReturnProc *)(iVar2 + 0x538) = userReturnProc;
    bRam000006dd = bRam000006dd + 1 & 7;
    bRam000006df = bRam000006df + 1;
    uVar1 = *(ushort *)(iVar2 + 0x50a);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ aadFreeDynamicSfx(unsigned short handle /*$a0*/)
 // line 991, offset 0x8005438c
	/* begin block 1 */
		// Start line: 993
		// Start offset: 0x8005438C
		// Variables:
	// 		struct AadDynamicLoadRequest *loadReq; // $v0
	/* end block 1 */
	// End offset: 0x80054414
	// End Line: 1009

	/* begin block 2 */
		// Start line: 2364
	/* end block 2 */
	// End Line: 2365

	/* begin block 3 */
		// Start line: 2365
	/* end block 3 */
	// End Line: 2366

	/* begin block 4 */
		// Start line: 2370
	/* end block 4 */
	// End Line: 2371

ushort aadFreeDynamicSfx(ushort handle)

{
  uint uVar1;
  
  if (bRam000006df < 8) {
    uVar1 = (uint)bRam000006dd;
    *(undefined2 *)(uVar1 * 0x34 + 0x508) = 1;
    *(ushort *)(uVar1 * 0x34 + 0x50a) = handle;
    bRam000006dd = bRam000006dd + 1 & 7;
    bRam000006df = bRam000006df + 1;
    return 0;
  }
  return 0x100f;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadFreeAllSfx()
 // line 1012, offset 0x80054424
	/* begin block 1 */
		// Start line: 1013
		// Start offset: 0x80054424
		// Variables:
	// 		int i; // $s1
	// 		struct _AadDynSfxFileHdr *snfFile; // $s2
	// 		struct _AadDynSfxFileHdr *nextSnfFile; // $v1
	// 		unsigned short *sfxIDListPtr; // $v1
	/* end block 1 */
	// End offset: 0x800544DC
	// End Line: 1039

	/* begin block 2 */
		// Start line: 2407
	/* end block 2 */
	// End Line: 2408

	/* begin block 3 */
		// Start line: 2415
	/* end block 3 */
	// End Line: 2416

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadFreeAllSfx(void)

{
  bool bVar1;
  ushort sfxID;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  
  bVar1 = cRam000006df != '\0';
  while (iVar2 = iRam0000076c, bVar1) {
    aadProcessLoadQueue();
    bVar1 = cRam000006df != '\0';
  }
  while (iVar2 != 0) {
    iVar4 = 0;
    puVar3 = (ushort *)(iVar2 + 0x14);
    if (*(short *)(iVar2 + 10) != 0) {
      do {
        sfxID = *puVar3;
        puVar3 = puVar3 + 1;
        aadFreeSingleDynSfx(sfxID);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(ushort *)(iVar2 + 10));
    }
    iVar2 = *(int *)(iVar2 + 0x10);
    (*pcRam000006d8)();
  }
  iRam0000076c = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetNumLoadsQueued()
 // line 1044, offset 0x80054500
	/* begin block 1 */
		// Start line: 2482
	/* end block 1 */
	// End Line: 2483

	/* begin block 2 */
		// Start line: 2484
	/* end block 2 */
	// End Line: 2485

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetNumLoadsQueued(void)

{
  return (uint)bRam000006df;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPurgeLoadQueue()
 // line 1052, offset 0x80054514
	/* begin block 1 */
		// Start line: 2498
	/* end block 1 */
	// End Line: 2499

	/* begin block 2 */
		// Start line: 2500
	/* end block 2 */
	// End Line: 2501

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadPurgeLoadQueue(void)

{
  uRam000006dd = 0;
  uRam000006de = 0;
  uRam000006df = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadProcessLoadQueue()
 // line 1062, offset 0x80054538
	/* begin block 1 */
		// Start line: 1063
		// Start offset: 0x80054538
		// Variables:
	// 		int i; // $v1
	// 		struct AadDynamicLoadRequest *loadReq; // $s2

		/* begin block 1.1 */
			// Start line: 1071
			// Start offset: 0x80054560
			// Variables:
		// 		struct AadDynamicSfxLoadInfo *info; // $s1

			/* begin block 1.1.1 */
				// Start line: 1125
				// Start offset: 0x800546F8
				// Variables:
			// 		int i; // $s2
			// 		struct _AadDynSfxFileHdr *snfFile; // $s1
			// 		unsigned short *sfxIDListPtr; // $v1
			/* end block 1.1.1 */
			// End offset: 0x800547D4
			// End Line: 1156
		/* end block 1.1 */
		// End offset: 0x800547D4
		// End Line: 1161
	/* end block 1 */
	// End offset: 0x800547D4
	// End Line: 1163

	/* begin block 2 */
		// Start line: 2518
	/* end block 2 */
	// End Line: 2519

	/* begin block 3 */
		// Start line: 2524
	/* end block 3 */
	// End Line: 2525

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadProcessLoadQueue(void)

{
  bool bVar1;
  ushort sfxID;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  char *__src;
  ushort *puVar5;
  int iVar6;
  
  if ((cRam000006df != '\0') && (iVar3 = 0, (uRam00000738 & 1) == 0)) {
    do {
      __src = (char *)(iVar3 + 0x4e8);
      iVar3 = iVar3 + 1;
      if (*__src == '\x01') {
        return;
      }
    } while (iVar3 < 2);
    uVar4 = (uint)bRam000006de;
    bRam000006de = bRam000006de + 1 & 7;
    cRam000006df = cRam000006df + -1;
    iVar3 = uVar4 * 0x34;
    if (*(short *)(iVar3 + 0x508) == 0) {
      __src = (char *)(iVar3 + 0x510);
      strncpy((char *)0x6e0,__src,0x27);
      sVar2 = strlen(__src);
      strncpy((char *)0x708,__src,sVar2 - 4);
      sVar2 = strlen(__src);
      *(undefined4 *)(sVar2 + 0x704) = 0x666d732e;
      *(undefined *)(sVar2 + 0x708) = 0;
      uRam0000074c = *(undefined2 *)(iVar3 + 0x50a);
      iRam00000730 = *(int *)(iVar3 + 0x50c);
      uRam00000734 = *(undefined4 *)(iVar3 + 0x538);
      uRam00000738 = 1;
      uRam00000750 = 0;
      uRam00000742 = 0;
      uRam00000748 = 0;
      if (iRam00000730 != 0) {
        LOAD_SetSearchDirectory(iRam00000730);
      }
      (*pcRam000006cc)(0x6e0,aadLoadDynamicSfxReturn,0x6e0,0,0x750,(uint)bRam000006dc);
    }
    else {
      if (*(short *)(iVar3 + 0x508) == 1) {
        bVar1 = iRam0000076c != 0;
        iVar6 = iRam0000076c;
        while (bVar1) {
          if (*(short *)(iVar6 + 8) == *(short *)(iVar3 + 0x50a)) {
            iVar3 = 0;
            puVar5 = (ushort *)(iVar6 + 0x14);
            if (*(short *)(iVar6 + 10) != 0) {
              do {
                sfxID = *puVar5;
                puVar5 = puVar5 + 1;
                aadFreeSingleDynSfx(sfxID);
                iVar3 = iVar3 + 1;
              } while (iVar3 < (int)(uint)*(ushort *)(iVar6 + 10));
            }
            if (*(int *)(iVar6 + 0xc) == 0) {
              iRam0000076c = *(int *)(iVar6 + 0x10);
            }
            else {
              *(undefined4 *)(*(int *)(iVar6 + 0xc) + 0x10) = *(undefined4 *)(iVar6 + 0x10);
            }
            if (*(int *)(iVar6 + 0x10) != 0) {
              *(undefined4 *)(*(int *)(iVar6 + 0x10) + 0xc) = *(undefined4 *)(iVar6 + 0xc);
            }
            (*pcRam000006d8)(iVar6);
            return;
          }
          iVar6 = *(int *)(iVar6 + 0x10);
          bVar1 = iVar6 != 0;
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxAbort(struct AadDynamicSfxLoadInfo *info /*$s0*/, unsigned short error /*$s1*/)
 // line 1166, offset 0x800547ec
	/* begin block 1 */
		// Start line: 2748
	/* end block 1 */
	// End Line: 2749

void aadLoadDynamicSfxAbort(AadDynamicSfxLoadInfo *info,ushort error)

{
  int iVar1;
  undefined2 in_register_00000016;
  
  if (info->waveTransferAddr != 0) {
    if ((*(ushort *)&info->loadFlags & 2) != 0) {
      iVar1 = *(int *)(info->waveTransferAddr + 0xc);
      if (iVar1 == 0) {
        uRam0000076c = 0;
      }
      else {
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
    }
    (*pcRam000006d8)(info->waveTransferAddr,CONCAT22(in_register_00000016,error));
  }
  *(undefined2 *)&info->loadFlags = 0;
  if ((code *)info->directoryID != (code *)0x0) {
    (*(code *)info->directoryID)(0xffffffff,info->fileHandle,info->numSfxToLoad,(uint)error);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxDone(struct AadDynamicSfxLoadInfo *info /*$v1*/)
 // line 1192, offset 0x80054898
	/* begin block 1 */
		// Start line: 2800
	/* end block 1 */
	// End Line: 2801

void aadLoadDynamicSfxDone(AadDynamicSfxLoadInfo *info)

{
  *(undefined2 *)&info->loadFlags = 0;
  if ((code *)info->directoryID != (code *)0x0) {
    (*(code *)info->directoryID)
              ((int)*(short *)(info->waveTransferAddr + 6),info->fileHandle,info->numSfxToLoad,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadDynamicSfxReturn(void *loadedDataPtr /*$a0*/, void *data /*$a1*/, void *data2 /*$a2*/)
 // line 1207, offset 0x800548dc
	/* begin block 1 */
		// Start line: 1208
		// Start offset: 0x800548DC
		// Variables:
	// 		struct _AadDynSfxFileHdr *p; // $v1
	// 		struct AadDynamicSfxLoadInfo *info; // $s0
	/* end block 1 */
	// End offset: 0x80054A18
	// End Line: 1287

	/* begin block 2 */
		// Start line: 2830
	/* end block 2 */
	// End Line: 2831

void aadLoadDynamicSfxReturn(void *loadedDataPtr,void *data,void *data2)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  
  puVar4 = *(ulong **)((int)data + 0x70);
  if ((puVar4 == (ulong *)0x0) || (puVar4 != (ulong *)loadedDataPtr)) {
    aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data,0x100e);
  }
  else {
    uVar1 = aadCreateFourCharID('a','S','N','F');
    if ((*puVar4 == uVar1) && (*(short *)(*(int *)((int)data + 0x70) + 4) == 0x100)) {
      *(undefined2 *)(*(int *)((int)data + 0x70) + 8) = *(undefined2 *)((int)data + 0x6c);
      if (iRam0000076c == 0) {
        iRam0000076c = *(int *)((int)data + 0x70);
        *(undefined4 *)(*(int *)((int)data + 0x70) + 0xc) = 0;
      }
      else {
        iVar2 = *(int *)(iRam0000076c + 0x10);
        iVar3 = iRam0000076c;
        while (iVar2 != 0) {
          iVar3 = *(int *)(iVar3 + 0x10);
          iVar2 = *(int *)(iVar3 + 0x10);
        }
        *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)((int)data + 0x70);
        *(int *)(*(int *)((int)data + 0x70) + 0xc) = iVar3;
      }
      *(undefined4 *)(*(int *)((int)data + 0x70) + 0x10) = 0;
      *(undefined2 *)((int)data + 0x5a) = 0;
      *(ushort *)((int)data + 0x58) = *(ushort *)((int)data + 0x58) | 2;
      (*pcRam000006d0)((int)data + 0x28,aadLoadDynamicSfxReturn2,data,0);
    }
    else {
      aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data,0x100b);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned char /*$ra*/ aadWaveMalloc(unsigned short waveID /*$t6*/, unsigned long waveSize /*$a1*/)
 // line 1298, offset 0x80054a2c
	/* begin block 1 */
		// Start line: 1299
		// Start offset: 0x80054A2C
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $a2
	// 		struct AadNewSramBlockDesc *bestFit; // $t2
	// 		struct AadNewSramBlockDesc *next; // $a2
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $t3
	// 		int i; // $t0
	// 		int sramDescIndex; // $t1
	// 		int bestFitIndex; // $t4
	/* end block 1 */
	// End offset: 0x80054C5C
	// End Line: 1399

	/* begin block 2 */
		// Start line: 3036
	/* end block 2 */
	// End Line: 3037

uchar aadWaveMalloc(ushort waveID,ulong waveSize)

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
  uchar uVar11;
  
  puVar10 = (ushort *)0x0;
  _uVar11 = 0xff;
  uVar11 = -1;
  uVar9 = (uint)bRam00001b56;
  puVar6 = (ushort *)(uVar9 * 8 + 0x1754);
  uVar5 = waveSize >> 3;
  if (puVar6 != (ushort *)0x0) {
    iVar7 = 0x7f;
    do {
      uVar11 = (uchar)_uVar11;
      if (iVar7 == -1) break;
      if ((((*puVar6 & 0x4000) == 0) && (uVar5 <= puVar6[2])) &&
         ((puVar10 == (ushort *)0x0 || (puVar6[2] - uVar5 < puVar10[2] - uVar5)))) {
        puVar10 = puVar6;
        _uVar11 = uVar9;
      }
      uVar11 = (uchar)_uVar11;
      if (*(char *)((int)puVar6 + 7) < '\0') {
        puVar6 = (ushort *)0x0;
      }
      else {
        uVar3 = (uint)*(byte *)((int)puVar6 + 7);
        puVar6 = (ushort *)0x0;
        if (uVar3 != uVar9) {
          puVar6 = (ushort *)(uVar3 * 8 + 0x1754);
          uVar9 = uVar3;
        }
      }
      iVar7 = iVar7 + -1;
    } while (puVar6 != (ushort *)0x0);
  }
  if (puVar10 == (ushort *)0x0) {
    return -1;
  }
  *puVar10 = waveID | 0xc000;
  if (uVar5 < puVar10[2]) {
    uVar4 = (ushort)uVar5;
    if ((-1 < *(char *)((int)puVar10 + 7)) &&
       (iVar7 = (uint)*(byte *)((int)puVar10 + 7) * 8, (*(ushort *)(iVar7 + 0x1754) & 0x4000) == 0))
    {
      *(short *)(iVar7 + 0x1756) = *(short *)(iVar7 + 0x1756) - (puVar10[2] - uVar4);
      *(short *)(iVar7 + 0x1758) = *(short *)(iVar7 + 0x1758) + (puVar10[2] - uVar4);
      puVar10[2] = uVar4;
      return uVar11;
    }
    _uVar11 = (uint)uRam00001b54;
    uVar8 = (undefined)uRam00001b54;
    puVar6 = (ushort *)(_uVar11 * 8 + 0x1754);
    uVar2 = *puVar6;
    uVar9 = _uVar11;
    while ((uVar2 & 0x8000) != 0) {
      uVar9 = uVar9 + 1 & 0x7f;
      uVar8 = (undefined)uVar9;
      if (uVar9 == _uVar11) {
        return -1;
      }
      puVar6 = (ushort *)(uVar9 * 8 + 0x1754);
      uVar2 = *puVar6;
    }
    uRam00001b54 = uRam00001b54 + 8 & 0x7f;
    *puVar6 = 0x8000;
    puVar6[1] = puVar10[1] + uVar4;
    uVar2 = puVar10[2];
    *(uchar *)(puVar6 + 3) = uVar11;
    puVar6[2] = uVar2 - uVar4;
    bVar1 = *(byte *)((int)puVar10 + 7);
    *(byte *)((int)puVar6 + 7) = bVar1;
    if (-1 < (int)((uint)bVar1 << 0x18)) {
      *(undefined *)((uint)*(byte *)((int)puVar6 + 7) * 8 + 0x175a) = uVar8;
    }
    puVar10[2] = uVar4;
    *(undefined *)((int)puVar10 + 7) = uVar8;
  }
  return uVar11;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetSramBlockAddr(unsigned char handle /*$v0*/)
 // line 1403, offset 0x80054c64
	/* begin block 1 */
		// Start line: 1404
		// Start offset: 0x80054C64
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $v0
	/* end block 1 */
	// End offset: 0x80054C8C
	// End Line: 1415

	/* begin block 2 */
		// Start line: 3280
	/* end block 2 */
	// End Line: 3281

ulong aadGetSramBlockAddr(uchar handle)

{
  if ((int)((uint)handle << 0x18) < 0) {
    return 0;
  }
  return (uint)*(ushort *)((uint)handle * 8 + 0x1756) << 3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadWaveFree(unsigned char handle /*$v1*/)
 // line 1436, offset 0x80054c94
	/* begin block 1 */
		// Start line: 1437
		// Start offset: 0x80054C94
		// Variables:
	// 		struct AadNewSramBlockDesc *sramDesc; // $a1
	// 		struct AadNewSramBlockDesc *sramDescTbl; // $a3

		/* begin block 1.1 */
			// Start line: 1449
			// Start offset: 0x80054CC8
			// Variables:
		// 		struct AadNewSramBlockDesc *next; // $a2
		/* end block 1.1 */
		// End offset: 0x80054D10
		// End Line: 1458

		/* begin block 1.2 */
			// Start line: 1462
			// Start offset: 0x80054D20
			// Variables:
		// 		struct AadNewSramBlockDesc *prev; // $a0
		/* end block 1.2 */
		// End offset: 0x80054D84
		// End Line: 1471
	/* end block 1 */
	// End offset: 0x80054D84
	// End Line: 1474

	/* begin block 2 */
		// Start line: 2865
	/* end block 2 */
	// End Line: 2866

	/* begin block 3 */
		// Start line: 3333
	/* end block 3 */
	// End Line: 3334

void aadWaveFree(uchar handle)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if (-1 < (int)((uint)handle << 0x18)) {
    iVar2 = (uint)handle * 8;
    *(undefined2 *)(iVar2 + 0x1754) = 0x8000;
    if ((-1 < *(char *)(iVar2 + 0x175b)) &&
       (iVar3 = (uint)*(byte *)(iVar2 + 0x175b) * 8, (*(ushort *)(iVar3 + 0x1754) & 0x4000) == 0)) {
      *(short *)(iVar2 + 0x1758) = *(short *)(iVar2 + 0x1758) + *(short *)(iVar3 + 0x1758);
      *(ushort *)(iVar3 + 0x1754) = 0;
      *(undefined *)(iVar2 + 0x175b) = *(undefined *)(iVar3 + 0x175b);
      *(uchar *)(iVar3 + 0x175a) = handle;
    }
    if ((-1 < *(char *)(iVar2 + 0x175a)) &&
       (iVar3 = (uint)*(byte *)(iVar2 + 0x175a) * 8, (*(ushort *)(iVar3 + 0x1754) & 0x4000) == 0)) {
      *(short *)(iVar3 + 0x1758) = *(short *)(iVar3 + 0x1758) + *(short *)(iVar2 + 0x1758);
      bVar1 = *(byte *)(iVar2 + 0x175b);
      *(undefined2 *)(iVar2 + 0x1754) = 0;
      *(byte *)(iVar3 + 0x175b) = bVar1;
      if (-1 < (int)((uint)bVar1 << 0x18)) {
        *(undefined *)((uint)*(byte *)(iVar2 + 0x175b) * 8 + 0x175a) =
             *(undefined *)(iVar2 + 0x175a);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadFreeSingleDynSfx(unsigned short sfxID /*$a0*/)
 // line 1478, offset 0x80054d8c
	/* begin block 1 */
		// Start line: 1479
		// Start offset: 0x80054D8C
		// Variables:
	// 		int ti; // $v1
	// 		int wi; // $v0
	// 		struct AadLoadedSfxToneAttr *toneAttr; // $a1
	// 		struct AadLoadedSfxWaveAttr *waveAttr; // $v1
	/* end block 1 */
	// End offset: 0x80054E40
	// End Line: 1502

	/* begin block 2 */
		// Start line: 3417
	/* end block 2 */
	// End Line: 3418

void aadFreeSingleDynSfx(ushort sfxID)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  
  bVar1 = *(byte *)((uint)sfxID + 0x770);
  if (bVar1 != 0xff) {
    iVar3 = (uint)bVar1 * 0x14;
    sVar2 = *(short *)(iVar3 + 0xb70) + -1;
    *(short *)(iVar3 + 0xb70) = sVar2;
    if (sVar2 == 0) {
      *(undefined *)((uint)sfxID + 0x770) = 0xff;
      bVar1 = *(byte *)((uint)*(ushort *)(iVar3 + 0xb72) + 0x970);
      iVar4 = (uint)bVar1 * 4;
      if (bVar1 != 0xff) {
        psVar5 = (short *)(iVar4 + 0x1570);
        sVar2 = *psVar5 + -1;
        *psVar5 = sVar2;
        if (sVar2 == 0) {
          *(undefined *)((uint)*(ushort *)(iVar3 + 0xb72) + 0x970) = 0xff;
          aadWaveFree(*(uchar *)(iVar4 + 0x1573));
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadLoadSingleDynSfx(struct AadDynamicSfxLoadInfo *info /*$s3*/)
 // line 1513, offset 0x80054e50
	/* begin block 1 */
		// Start line: 1514
		// Start offset: 0x80054E50
		// Variables:
	// 		int i; // $s0
	// 		struct AadLoadedSfxToneAttr *toneAttr; // $a0
	// 		struct AadLoadedSfxWaveAttr *waveAttr; // $s1
	// 		struct AadDynSfxAttr *attr; // $s2
	/* end block 1 */
	// End offset: 0x800550B4
	// End Line: 1611

	/* begin block 2 */
		// Start line: 3492
	/* end block 2 */
	// End Line: 3493

	/* begin block 3 */
		// Start line: 3501
	/* end block 3 */
	// End Line: 3502

void aadLoadSingleDynSfx(AadDynamicSfxLoadInfo *info)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  undefined2 uVar4;
  short *psVar5;
  int iVar6;
  ulong uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined uVar11;
  uint uVar12;
  
  info->bytesToLoad = 0;
  bVar3 = *(byte *)((uint)*(ushort *)&info->totalSramUsed + 0x770);
  if (bVar3 == 0xff) {
    _uVar11 = (uint)uRam00001750;
    uVar11 = (undefined)uRam00001750;
    psVar5 = (short *)(_uVar11 * 0x14 + 0xb70);
    sVar1 = *psVar5;
    uVar12 = _uVar11;
    while (sVar1 != 0) {
      uVar12 = uVar12 + 1 & 0x7f;
      uVar11 = (undefined)uVar12;
      if (uVar12 == _uVar11) goto LAB_800550ac;
      psVar5 = (short *)(uVar12 * 0x14 + 0xb70);
      sVar1 = *psVar5;
    }
    uRam00001750 = uRam00001750 + 8 & 0x7f;
    *psVar5 = 1;
    psVar5[1] = *(short *)((int)&info->totalSramUsed + 2);
    uVar8 = *(undefined4 *)&info->attr;
    uVar9 = *(undefined4 *)&(info->attr).toneAttr;
    uVar10 = *(undefined4 *)&(info->attr).toneAttr.centerNote;
    *(_AadDynSfxFileHdr **)(psVar5 + 2) = info->snfFile;
    *(undefined4 *)(psVar5 + 4) = uVar8;
    *(undefined4 *)(psVar5 + 6) = uVar9;
    *(undefined4 *)(psVar5 + 8) = uVar10;
    *(undefined *)((uint)*(ushort *)&info->totalSramUsed + 0x770) = uVar11;
    bVar3 = *(byte *)((uint)*(ushort *)((int)&info->totalSramUsed + 2) + 0x970);
    if (bVar3 == 0xff) {
      uVar12 = (uint)uRam00001752;
      do {
        iVar6 = uVar12 * 4;
        _uVar11 = uVar12 + 1;
        if (*(short *)(iVar6 + 0x1570) == 0) {
          uVar2 = uRam00001752 + 8;
          if (0x77 < (ushort)(uRam00001752 + 8)) {
            uVar2 = uRam00001752 - 0x70;
          }
          uRam00001752 = uVar2;
          *(short *)(iVar6 + 0x1570) = 1;
          bVar3 = aadWaveMalloc(*(ushort *)((int)&info->totalSramUsed + 2),
                                *(ulong *)&(info->attr).toneAttr.mode);
          *(byte *)(iVar6 + 0x1573) = bVar3;
          if (-1 < (int)((uint)bVar3 << 0x18)) {
            *(undefined *)((uint)*(ushort *)((int)&info->totalSramUsed + 2) + 0x970) = (char)uVar12;
            uVar7 = aadGetSramBlockAddr(*(uchar *)(iVar6 + 0x1573));
            info->bytesToLoad = uVar7;
            uVar4 = 3;
            goto LAB_800550b0;
          }
          break;
        }
        if (0x77 < (int)_uVar11) {
          _uVar11 = 0;
        }
        uVar12 = _uVar11;
      } while (_uVar11 != (uint)uRam00001750);
      aadFreeSingleDynSfx(*(ushort *)&info->totalSramUsed);
    }
    else {
      psVar5 = (short *)((uint)bVar3 * 4 + 0x1570);
      *psVar5 = *psVar5 + 1;
    }
  }
  else {
    psVar5 = (short *)((uint)bVar3 * 0x14 + 0xb70);
    *psVar5 = *psVar5 + 1;
  }
LAB_800550ac:
  uVar4 = 2;
LAB_800550b0:
  *(undefined2 *)((int)&info->loadFlags + 2) = uVar4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HackCallback()
 // line 1626, offset 0x800550d0
	/* begin block 1 */
		// Start line: 3785
	/* end block 1 */
	// End Line: 3786

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
 // line 1635, offset 0x80055108
	/* begin block 1 */
		// Start line: 1636
		// Start offset: 0x80055108
		// Variables:
	// 		unsigned char *dataPtr; // $s4
	// 		unsigned long dataOffset; // $s3
	// 		unsigned long bytesRemaining; // $s2
	// 		struct AadDynamicSfxLoadInfo *info; // $s1
	// 		unsigned long n; // $s0
	/* end block 1 */
	// End offset: 0x800553B0
	// End Line: 1789

	/* begin block 2 */
		// Start line: 3803
	/* end block 2 */
	// End Line: 3804

void aadLoadDynamicSfxReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  ushort uVar1;
  short sVar2;
  ulong uVar3;
  int iVar4;
  void *__src;
  undefined2 in_register_0000001a;
  size_t sVar5;
  uint __n;
  int iVar6;
  
  sVar5 = CONCAT22(in_register_0000001a,status);
  iVar6 = 0;
  if (loadedDataSize != 0) {
    do {
      uVar1 = *(ushort *)((int)data1 + 0x5a);
      if (uVar1 == 1) {
        __src = (void *)((int)loadedDataPtr + iVar6);
        __n = *(uint *)((int)data1 + 0x5c);
        if ((uint)loadedDataSize < *(uint *)((int)data1 + 0x5c)) {
          __n = loadedDataSize;
        }
        iVar6 = iVar6 + __n;
        sVar5 = __n;
        memcpy((void *)((int)data1 - (*(int *)((int)data1 + 0x5c) + -0x8c)),__src,__n);
        loadedDataSize = loadedDataSize - __n;
        iVar4 = *(int *)((int)data1 + 0x5c) - __n;
        *(int *)((int)data1 + 0x5c) = iVar4;
        if (iVar4 == 0) {
          aadLoadSingleDynSfx((AadDynamicSfxLoadInfo *)data1);
          *(undefined4 *)((int)data1 + 0x5c) = *(undefined4 *)((int)data1 + 0x88);
        }
      }
      else {
        if (uVar1 < 2) {
          if (uVar1 == 0) {
            sVar5 = 0x4d;
            uVar3 = aadCreateFourCharID('a','S','M','F');
            if (*(ulong *)loadedDataPtr != uVar3) {
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,0x100b);
              return;
            }
            if (*(short *)((int)loadedDataPtr + 4) != 0x100) {
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,0x100c);
              return;
            }
            if (*(short *)((int)loadedDataPtr + 6) != *(short *)(*(int *)((int)data1 + 0x70) + 6)) {
LAB_80055208:
              aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,0x100d);
              return;
            }
            sVar2 = *(short *)(*(int *)((int)data1 + 0x70) + 10);
            iVar6 = iVar6 + 0x10;
            if (*(short *)((int)loadedDataPtr + 8) != sVar2) goto LAB_80055208;
            loadedDataSize = loadedDataSize - 0x10;
            *(short *)((int)data1 + 0x60) = sVar2;
LAB_800552cc:
            *(undefined2 *)((int)data1 + 0x5a) = 1;
            *(undefined4 *)((int)data1 + 0x5c) = 0x18;
          }
        }
        else {
          if (uVar1 == 2) {
            __n = *(uint *)((int)data1 + 0x5c);
            if ((uint)loadedDataSize < *(uint *)((int)data1 + 0x5c)) {
              __n = loadedDataSize;
            }
            iVar6 = iVar6 + __n;
            loadedDataSize = loadedDataSize - __n;
            iVar4 = *(int *)((int)data1 + 0x5c) - __n;
            *(int *)((int)data1 + 0x5c) = iVar4;
            if (iVar4 == 0) {
              sVar2 = *(short *)((int)data1 + 0x60) + -1;
              *(short *)((int)data1 + 0x60) = sVar2;
              if (sVar2 == 0) {
LAB_8005536c:
                aadLoadDynamicSfxDone((AadDynamicSfxLoadInfo *)data1);
                return;
              }
              goto LAB_800552cc;
            }
          }
          else {
            if (uVar1 == 3) {
              __n = *(uint *)((int)data1 + 0x5c);
              if ((uint)loadedDataSize < *(uint *)((int)data1 + 0x5c)) {
                __n = loadedDataSize;
              }
              do {
                iVar4 = SpuIsTransferCompleted(0);
              } while (iVar4 == 0);
              SpuSetTransferCallback((int)HackCallback);
              loadedDataSize = loadedDataSize - __n;
              SpuSetTransferStartAddr(*(uint *)((int)data1 + 100));
              SpuWrite((word *)((int)loadedDataPtr + iVar6),__n,sVar5);
              iVar6 = iVar6 + __n;
              iVar4 = *(int *)((int)data1 + 0x5c) - __n;
              *(int *)((int)data1 + 100) = *(int *)((int)data1 + 100) + __n;
              *(int *)((int)data1 + 0x5c) = iVar4;
              if (iVar4 == 0) {
                sVar2 = *(short *)((int)data1 + 0x60) + -1;
                *(short *)((int)data1 + 0x60) = sVar2;
                *(int *)((int)data1 + 0x68) =
                     *(int *)((int)data1 + 0x68) + *(int *)((int)data1 + 0x88);
                if (sVar2 == 0) {
                  SpuSetTransferCallback(0);
                  goto LAB_8005536c;
                }
                *(undefined2 *)((int)data1 + 0x5a) = 1;
                *(undefined4 *)((int)data1 + 0x5c) = 0x18;
              }
              if (loadedDataSize != 0) {
                smfDataPtr = (uchar *)((int)loadedDataPtr + iVar6);
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
// int /*$ra*/ aadIsSfxLoaded(unsigned int toneID /*$a0*/)
 // line 1798, offset 0x800553d8
	/* begin block 1 */
		// Start line: 3591
	/* end block 1 */
	// End Line: 3592

	/* begin block 2 */
		// Start line: 4173
	/* end block 2 */
	// End Line: 4174

int aadIsSfxLoaded(uint toneID)

{
  return (uint)(*(char *)(toneID + 0x770) != -1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInitSequenceSlot(struct _AadSequenceSlot *slot /*$a2*/)
 // line 2027, offset 0x800553f8
	/* begin block 1 */
		// Start line: 2028
		// Start offset: 0x800553F8
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $t0
	// 		unsigned long trackOffset; // $v0
	// 		int i; // $a1
	// 		int bank; // $a0
	/* end block 1 */
	// End offset: 0x800554EC
	// End Line: 2086

	/* begin block 2 */
		// Start line: 4628
	/* end block 2 */
	// End Line: 4629

void aadInitSequenceSlot(_AadSequenceSlot *slot)

{
  uchar uVar1;
  int iVar2;
  _AadSequenceSlot *p_Var3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  slot->status = 0;
  slot->slotFlags = slot->slotID;
  *(byte *)&slot->delayedUnMuteCmds = *(byte *)&slot->delayedUnMuteCmds & 1;
  iVar6 = *(int *)((uint)slot->sequenceNumberAssigned * 4 + *(int *)((uint)slot->slotID * 4 + 0x4d8)
                  );
  p_Var3 = slot;
  iVar5 = iVar6;
  do {
    if (iVar4 < (int)(uint)*(ushort *)(iVar6 + 0xc)) {
      p_Var3->sequencePosition[0] = (_func_4397 *)(iVar6 + *(int *)(iVar5 + 0x10));
    }
    else {
      p_Var3->sequencePosition[0] = (_func_4397 *)0x0;
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
    uVar1 = slot->slotID;
    iVar5 = iVar5 + 1;
    *(undefined *)(iVar4 + 0x584) = 0xff;
    *(undefined *)(iVar4 + 0x594) = 0;
    *(undefined *)(iVar4 + 0x5a4) = 0x7f;
    *(undefined *)(iVar4 + 0x5b4) = 0x3f;
    *(uchar *)(iVar4 + 0x554) = uVar1;
    *(undefined2 *)(p_Var3->currentDynamicBank + 4) = 0x2000;
    p_Var3 = (_AadSequenceSlot *)((int)&(p_Var3->tempo).currentTick + 2);
  } while (iVar5 < 0x10);
  slot->selectedSlotPtr = slot;
  slot->selectedSlotNum = slot->thisSlotNumber;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadWaitForSramTransferComplete()
 // line 2092, offset 0x800554fc
	/* begin block 1 */
		// Start line: 2093
		// Start offset: 0x800554FC
		// Variables:
	// 		int n; // $s0
	/* end block 1 */
	// End offset: 0x80055528
	// End Line: 2100

	/* begin block 2 */
		// Start line: 4843
	/* end block 2 */
	// End Line: 4844

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadWaitForSramTransferComplete(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 10000;
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
 // line 2103, offset 0x80055538
	/* begin block 1 */
		// Start line: 4866
	/* end block 1 */
	// End Line: 4867

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
 // line 2119, offset 0x800555bc
	/* begin block 1 */
		// Start line: 4898
	/* end block 1 */
	// End Line: 4899

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
 // line 2133, offset 0x800555f4
	/* begin block 1 */
		// Start line: 4926
	/* end block 1 */
	// End Line: 4927

	/* begin block 2 */
		// Start line: 4927
	/* end block 2 */
	// End Line: 4928

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetReverbMode(void)

{
  return 3;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadGetReverbSize()
 // line 2155, offset 0x800555fc
	/* begin block 1 */
		// Start line: 4970
	/* end block 1 */
	// End Line: 4971

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
 // line 2160, offset 0x80055630
	/* begin block 1 */
		// Start line: 4980
	/* end block 1 */
	// End Line: 4981

	/* begin block 2 */
		// Start line: 4981
	/* end block 2 */
	// End Line: 4982

/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetReverbDepth(void)

{
  return 10000;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetDynamicBankStatus(int bank /*$a0*/)
 // line 2166, offset 0x80055638
	/* begin block 1 */
		// Start line: 4992
	/* end block 1 */
	// End Line: 4993

	/* begin block 2 */
		// Start line: 4995
	/* end block 2 */
	// End Line: 4996

int aadGetDynamicBankStatus(int bank)

{
  return (uint)*(byte *)(bank + 0x4e8);
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetNumDynamicSequences(int bank /*$a0*/)
 // line 2173, offset 0x80055650
	/* begin block 1 */
		// Start line: 5006
	/* end block 1 */
	// End Line: 5007

	/* begin block 2 */
		// Start line: 5009
	/* end block 2 */
	// End Line: 5010

int aadGetNumDynamicSequences(int bank)

{
  if (*(char *)(bank + 0x4e8) != '\x02') {
    return 0;
  }
  return (uint)*(byte *)(*(int *)(bank * 4 + 0x4b8) + 0x10);
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ aadAssignDynamicSequence(int bank /*$s1*/, int sequenceNumber /*$s3*/, int slotNumber /*$s2*/)
 // line 2190, offset 0x8005568c
	/* begin block 1 */
		// Start line: 2191
		// Start offset: 0x8005568C
		// Variables:
	// 		struct AadTempo tempo; // stack offset -32
	// 		struct _AadSequenceSlot *slot; // $s0
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80055748
	// End Line: 2237

	/* begin block 2 */
		// Start line: 5035
	/* end block 2 */
	// End Line: 5036

	/* begin block 3 */
		// Start line: 5043
	/* end block 3 */
	// End Line: 5044

ushort aadAssignDynamicSequence(int bank,int sequenceNumber,int slotNumber)

{
  ushort uVar1;
  AadTempo *tempo;
  int iVar2;
  int iVar3;
  _AadSequenceSlot *slot;
  AadTempo AStack32;
  
  if (*(char *)(bank + 0x4e8) == '\x02') {
    slot = *(_AadSequenceSlot **)(slotNumber * 4 + 0x1c);
    slot->sequenceNumberAssigned = (uchar)sequenceNumber;
    slot->slotID = (uchar)bank;
    aadInitSequenceSlot(slot);
    aadAllNotesOff(slotNumber);
    if ((slot->tempo).ticksPerUpdate == 0) {
      tempo = aadGetTempoFromDynamicSequence(bank,sequenceNumber,&AStack32);
      aadSetSlotTempo(slotNumber,tempo);
    }
    iVar3 = 0xf;
    iVar2 = (int)&(slot->tempo).errorPerUpdate + 3;
    slot->channelMute = 0;
    slot->delayedMuteMode = 0;
    slot->delayedMuteCmds = 0;
    do {
      *(undefined *)(iVar2 + 0x5c4) = 0;
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + -1;
    } while (-1 < iVar3);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x1007;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// struct AadTempo * /*$ra*/ aadGetTempoFromDynamicSequence(int bank /*$a0*/, int sequenceNumber /*$a1*/, struct AadTempo *tempo /*$a2*/)
 // line 2240, offset 0x80055764
	/* begin block 1 */
		// Start line: 2242
		// Start offset: 0x80055764
		// Variables:
	// 		struct AadSequenceHdr *seqHdr; // $v1
	/* end block 1 */
	// End offset: 0x800557B0
	// End Line: 2255

	/* begin block 2 */
		// Start line: 5173
	/* end block 2 */
	// End Line: 5174

	/* begin block 3 */
		// Start line: 5174
	/* end block 3 */
	// End Line: 5175

	/* begin block 4 */
		// Start line: 5181
	/* end block 4 */
	// End Line: 5182

AadTempo * aadGetTempoFromDynamicSequence(int bank,int sequenceNumber,AadTempo *tempo)

{
  int iVar1;
  
  if (*(char *)(bank + 0x4e8) == '\x02') {
    iVar1 = *(int *)(sequenceNumber * 4 + *(int *)(bank * 4 + 0x4d8));
    tempo->quarterNoteTime = *(ulong *)(iVar1 + 4);
    *(undefined2 *)&tempo->ppqn = *(undefined2 *)(iVar1 + 8);
  }
  return tempo;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetSlotTempo(int slotNumber /*$a0*/, struct AadTempo *tempo /*$a1*/)
 // line 2374, offset 0x800557b8
	/* begin block 1 */
		// Start line: 2376
		// Start offset: 0x800557B8
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a0
	// 		unsigned long tickTime; // $v1
	// 		unsigned long tickTimeRemainder; // $a2
	/* end block 1 */
	// End offset: 0x800557B8
	// End Line: 2382

	/* begin block 2 */
		// Start line: 5441
	/* end block 2 */
	// End Line: 5442

	/* begin block 3 */
		// Start line: 5442
	/* end block 3 */
	// End Line: 5443

	/* begin block 4 */
		// Start line: 5448
	/* end block 4 */
	// End Line: 5449

void aadSetSlotTempo(int slotNumber,AadTempo *tempo)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)*(ushort *)&tempo->ppqn;
  iVar2 = *(int *)(slotNumber * 4 + 0x1c);
  uVar1 = (tempo->quarterNoteTime / uVar1) * 0x10000 +
          (tempo->quarterNoteTime % uVar1 << 0x10) / uVar1;
  *(uint *)(iVar2 + 8) = uVar1;
  *(undefined2 *)(iVar2 + 0x10) = (short)((&aadUpdateRate)[(uint)DAT_00000005 & 3] / uVar1);
  *(uint *)(iVar2 + 0xc) = (&aadUpdateRate)[(uint)DAT_00000005 & 3] % *(uint *)(iVar2 + 8);
  *(ulong *)(iVar2 + 0x14) = tempo->quarterNoteTime;
  *(undefined2 *)(iVar2 + 0x12) = *(undefined2 *)&tempo->ppqn;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStartSlot(int slotNumber /*$a0*/)
 // line 2395, offset 0x80055870
	/* begin block 1 */
		// Start line: 2396
		// Start offset: 0x80055870
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s0
	/* end block 1 */
	// End offset: 0x800558DC
	// End Line: 2409

	/* begin block 2 */
		// Start line: 5488
	/* end block 2 */
	// End Line: 5489

	/* begin block 3 */
		// Start line: 5491
	/* end block 3 */
	// End Line: 5492

void aadStartSlot(int slotNumber)

{
  _AadSequenceSlot *slot;
  
  if (((slotNumber < (int)(uint)mainMenuScreen) &&
      (slot = *(_AadSequenceSlot **)(slotNumber * 4 + 0x1c), (slot->status & 1) == 0)) &&
     (slot->sequenceNumberAssigned != -1)) {
    aadInitSequenceSlot(slot);
    slot->status = slot->status | 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStopSlot(int slotNumber /*$s0*/)
 // line 2412, offset 0x800558ec
	/* begin block 1 */
		// Start line: 2413
		// Start offset: 0x800558EC
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a0
	/* end block 1 */
	// End offset: 0x80055948
	// End Line: 2427

	/* begin block 2 */
		// Start line: 5525
	/* end block 2 */
	// End Line: 5526

	/* begin block 3 */
		// Start line: 5528
	/* end block 3 */
	// End Line: 5529

void aadStopSlot(int slotNumber)

{
  _AadSequenceSlot *slot;
  
  if ((slotNumber < (int)(uint)mainMenuScreen) &&
     (slot = *(_AadSequenceSlot **)(slotNumber * 4 + 0x1c), slot->sequenceNumberAssigned != -1)) {
    slot->status = slot->status & 0xfffe;
    aadInitSequenceSlot(slot);
    aadAllNotesOff(slotNumber);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStopAllSlots()
 // line 2430, offset 0x80055958
	/* begin block 1 */
		// Start line: 2431
		// Start offset: 0x80055958
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $s1
	// 		int slotNumber; // $s0
	/* end block 1 */
	// End offset: 0x800559D0
	// End Line: 2445

	/* begin block 2 */
		// Start line: 5567
	/* end block 2 */
	// End Line: 5568

	/* begin block 3 */
		// Start line: 5572
	/* end block 3 */
	// End Line: 5573

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadStopAllSlots(void)

{
  int iVar1;
  int slotNumber;
  
  slotNumber = 0;
  if (mainMenuScreen != 0) {
    iVar1 = 0;
    do {
      iVar1 = *(int *)(iVar1 + 0x1c);
      if ((*(ushort *)(iVar1 + 0x540) & 1) != 0) {
        aadStopSlot(slotNumber);
      }
      *(undefined *)(iVar1 + 0x53e) = 0xff;
      slotNumber = slotNumber + 1;
      iVar1 = slotNumber * 4;
    } while (slotNumber < (int)(uint)mainMenuScreen);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadDisableSlot(int slotNumber /*$a0*/)
 // line 2448, offset 0x800559e8
	/* begin block 1 */
		// Start line: 5614
	/* end block 1 */
	// End Line: 5615

	/* begin block 2 */
		// Start line: 5615
	/* end block 2 */
	// End Line: 5616

void aadDisableSlot(int slotNumber)

{
  int iVar1;
  
  if (slotNumber < (int)(uint)mainMenuScreen) {
    iVar1 = *(int *)(slotNumber * 4 + 0x1c);
    *(byte *)(iVar1 + 0x548) = *(byte *)(iVar1 + 0x548) | 1;
    aadAllNotesOff(slotNumber);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadEnableSlot(int slotNumber /*$a0*/)
 // line 2459, offset 0x80055a38
	/* begin block 1 */
		// Start line: 5637
	/* end block 1 */
	// End Line: 5638

	/* begin block 2 */
		// Start line: 5638
	/* end block 2 */
	// End Line: 5639

void aadEnableSlot(int slotNumber)

{
  int iVar1;
  
  if (slotNumber < (int)(uint)mainMenuScreen) {
    iVar1 = *(int *)(slotNumber * 4 + 0x1c);
    *(byte *)(iVar1 + 0x548) = *(byte *)(iVar1 + 0x548) & 0xfe;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPauseSlot(int slotNumber /*$a0*/)
 // line 2467, offset 0x80055a78
	/* begin block 1 */
		// Start line: 5653
	/* end block 1 */
	// End Line: 5654

	/* begin block 2 */
		// Start line: 5654
	/* end block 2 */
	// End Line: 5655

void aadPauseSlot(int slotNumber)

{
  int iVar1;
  
  if (slotNumber < (int)(uint)mainMenuScreen) {
    iVar1 = *(int *)(slotNumber * 4 + 0x1c);
    *(ushort *)(iVar1 + 0x540) = *(ushort *)(iVar1 + 0x540) & 0xfffe;
    aadAllNotesOff(slotNumber);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadResumeSlot(int slotNumber /*$a0*/)
 // line 2478, offset 0x80055ac8
	/* begin block 1 */
		// Start line: 2480
		// Start offset: 0x80055AC8
		// Variables:
	// 		struct _AadSequenceSlot *slot; // $a1
	// 		int track; // $a0
	/* end block 1 */
	// End offset: 0x80055B30
	// End Line: 2494

	/* begin block 2 */
		// Start line: 5676
	/* end block 2 */
	// End Line: 5677

	/* begin block 3 */
		// Start line: 5677
	/* end block 3 */
	// End Line: 5678

	/* begin block 4 */
		// Start line: 5680
	/* end block 4 */
	// End Line: 5681

void aadResumeSlot(int slotNumber)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (slotNumber < (int)(uint)mainMenuScreen) {
    iVar3 = *(int *)(slotNumber * 4 + 0x1c);
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
 // line 2497, offset 0x80055b38
	/* begin block 1 */
		// Start line: 5716
	/* end block 1 */
	// End Line: 5717

	/* begin block 2 */
		// Start line: 5717
	/* end block 2 */
	// End Line: 5718

int aadGetSlotStatus(int slotNumber)

{
  return (uint)*(ushort *)(*(int *)(slotNumber * 4 + 0x1c) + 0x540);
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadAllNotesOff(int slotNumber /*$a0*/)
 // line 2523, offset 0x80055b58
	/* begin block 1 */
		// Start line: 2525
		// Start offset: 0x80055B58
		// Variables:
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned long vmask; // $a1
	// 		int i; // $a3
	// 		struct _AadSequenceSlot *slot; // $t0
	/* end block 1 */
	// End offset: 0x80055BF0
	// End Line: 2548

	/* begin block 2 */
		// Start line: 5042
	/* end block 2 */
	// End Line: 5043

	/* begin block 3 */
		// Start line: 5744
	/* end block 3 */
	// End Line: 5745

	/* begin block 4 */
		// Start line: 5750
	/* end block 4 */
	// End Line: 5751

void aadAllNotesOff(int slotNumber)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar3 = 0;
  puVar2 = (uint *)0x1c4;
  iVar4 = *(int *)(slotNumber * 4 + 0x1c);
  do {
    if ((*(byte *)(puVar2 + 2) & 0xf0) == *(byte *)(iVar4 + 0x549)) {
      *(undefined *)(puVar2 + 2) = 0xff;
      uVar1 = uVar1 | *puVar2;
      *(ushort *)((int)puVar2 + 0x12) = *(ushort *)((int)puVar2 + 0x12) | 2;
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 7;
  } while (iVar3 < 0x18);
  if (uVar1 != 0) {
    uRam000004ac = uRam000004ac | uVar1;
    uRam000004b0 = uRam000004b0 & ~uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadGetVoiceStatus(char *voiceStatusArray /*$a0*/)
 // line 2551, offset 0x80055bf8
	/* begin block 1 */
		// Start line: 5810
	/* end block 1 */
	// End Line: 5811

	/* begin block 2 */
		// Start line: 5811
	/* end block 2 */
	// End Line: 5812

void aadGetVoiceStatus(char *voiceStatusArray)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = uRam00000470;
  uVar2 = uRam0000046c;
  uVar1 = uRam00000468;
  *(undefined4 *)voiceStatusArray = uRam00000464;
  *(undefined4 *)(voiceStatusArray + 4) = uVar1;
  *(undefined4 *)(voiceStatusArray + 8) = uVar2;
  *(undefined4 *)(voiceStatusArray + 0xc) = uVar3;
  uVar1 = uRam00000478;
  *(undefined4 *)(voiceStatusArray + 0x10) = uRam00000474;
  *(undefined4 *)(voiceStatusArray + 0x14) = uVar1;
  return;
}



// decompiled code
// original method signature: 
// struct AadSynthVoice * /*$ra*/ aadGetVoicePointer(int voiceIndex /*$a0*/)
 // line 2558, offset 0x80055c68
	/* begin block 1 */
		// Start line: 5824
	/* end block 1 */
	// End Line: 5825

	/* begin block 2 */
		// Start line: 5826
	/* end block 2 */
	// End Line: 5827

AadSynthVoice * aadGetVoicePointer(int voiceIndex)

{
  return (AadSynthVoice *)(voiceIndex * 0x1c + 0x1c4);
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadMuteChannels(int slotNumber /*$a0*/, unsigned long channelList /*$a1*/)
 // line 2565, offset 0x80055c84
	/* begin block 1 */
		// Start line: 2567
		// Start offset: 0x80055C84
		// Variables:
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned long vmask; // $t1
	// 		int channel; // $t0
	// 		int i; // $a3
	// 		struct _AadSequenceSlot *slot; // $t2
	/* end block 1 */
	// End offset: 0x80055D44
	// End Line: 2598

	/* begin block 2 */
		// Start line: 5838
	/* end block 2 */
	// End Line: 5839

	/* begin block 3 */
		// Start line: 5839
	/* end block 3 */
	// End Line: 5840

	/* begin block 4 */
		// Start line: 5845
	/* end block 4 */
	// End Line: 5846

void aadMuteChannels(int slotNumber,ulong channelList)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  uVar4 = 0;
  iVar6 = *(int *)(slotNumber * 4 + 0x1c);
  *(ushort *)(iVar6 + 0x542) = *(ushort *)(iVar6 + 0x542) | (ushort)channelList;
  uVar1 = 1;
  do {
    if ((channelList & uVar1) != 0) {
      iVar3 = 0;
      puVar2 = (uint *)0x1c4;
      do {
        if ((uint)*(byte *)(puVar2 + 2) == (*(byte *)(iVar6 + 0x549) | uVar4)) {
          *(undefined *)(puVar2 + 2) = 0xff;
          uVar5 = uVar5 | *puVar2;
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 7;
      } while (iVar3 < 0x18);
    }
    uVar4 = uVar4 + 1;
    uVar1 = 1 << (uVar4 & 0x1f);
  } while ((int)uVar4 < 0x10);
  if (uVar5 != 0) {
    uRam000004ac = uRam000004ac | uVar5;
    uRam000004b0 = uRam000004b0 & ~uVar5;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadUnMuteChannels(int slotNumber /*$a0*/, unsigned long channelList /*$a1*/)
 // line 2601, offset 0x80055d4c
	/* begin block 1 */
		// Start line: 5926
	/* end block 1 */
	// End Line: 5927

	/* begin block 2 */
		// Start line: 5927
	/* end block 2 */
	// End Line: 5928

void aadUnMuteChannels(int slotNumber,ulong channelList)

{
  int iVar1;
  
  iVar1 = *(int *)(slotNumber * 4 + 0x1c);
  *(ushort *)(iVar1 + 0x542) = *(ushort *)(iVar1 + 0x542) & ~(ushort)channelList;
  return;
}



// decompiled code
// original method signature: 
// TDRFuncPtr_aadInstallEndSequenceCallback /*$ra*/ aadInstallEndSequenceCallback(TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc /*$a0*/, long data /*$a1*/)
 // line 2706, offset 0x80055d74
	/* begin block 1 */
		// Start line: 2708
		// Start offset: 0x80055D74
		// Variables:
	// 		void (*previousCallbackProc)(); // $v0
	/* end block 1 */
	// End offset: 0x80055D74
	// End Line: 2710

	/* begin block 2 */
		// Start line: 5408
	/* end block 2 */
	// End Line: 5409

	/* begin block 3 */
		// Start line: 6033
	/* end block 3 */
	// End Line: 6034

	/* begin block 4 */
		// Start line: 6035
	/* end block 4 */
	// End Line: 6036

TDRFuncPtr_aadInstallEndSequenceCallback
aadInstallEndSequenceCallback
          (TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc,long data)

{
  TDRFuncPtr_aadInstallEndSequenceCallback pTVar1;
  
  pTVar1 = pTRam00001b60;
  pTRam00001b60 = (TDRFuncPtr_aadInstallEndSequenceCallback)callbackProc;
  lRam00001b68 = data;
  return pTVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetUserVariable(int variableNumber /*$a0*/, int value /*$a1*/)
 // line 2717, offset 0x80055d8c
	/* begin block 1 */
		// Start line: 6054
	/* end block 1 */
	// End Line: 6055

	/* begin block 2 */
		// Start line: 6056
	/* end block 2 */
	// End Line: 6057

void aadSetUserVariable(int variableNumber,int value)

{
  *(undefined *)(variableNumber + 0x1b6c) = (char)value;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadGetUserVariable(int variableNumber /*$a0*/)
 // line 2725, offset 0x80055da0
	/* begin block 1 */
		// Start line: 6070
	/* end block 1 */
	// End Line: 6071

	/* begin block 2 */
		// Start line: 6072
	/* end block 2 */
	// End Line: 6073

int aadGetUserVariable(int variableNumber)

{
  return (uint)*(byte *)(variableNumber + 0x1b6c);
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadSetNoUpdateMode(int noUpdate /*$a0*/)
 // line 2747, offset 0x80055db8
	/* begin block 1 */
		// Start line: 5486
	/* end block 1 */
	// End Line: 5487

	/* begin block 2 */
		// Start line: 6096
	/* end block 2 */
	// End Line: 6097

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadSetNoUpdateMode(int noUpdate)

{
  if (noUpdate != 0) {
    _DAT_00000012 = _DAT_00000012 | 2;
    return;
  }
  _DAT_00000012 = _DAT_00000012 & 0xfffd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPauseSound()
 // line 2768, offset 0x80055df8
	/* begin block 1 */
		// Start line: 2769
		// Start offset: 0x80055DF8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80055E78
	// End Line: 2785

	/* begin block 2 */
		// Start line: 5524
	/* end block 2 */
	// End Line: 5525

	/* begin block 3 */
		// Start line: 6126
	/* end block 3 */
	// End Line: 6127

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadPauseSound(void)

{
  int iVar1;
  int iVar2;
  word *pwVar3;
  
  if ((_DAT_00000012 & 8) == 0) {
    iVar1 = 0;
    iVar2 = 0;
    pwVar3 = (word *)0x47c;
    _DAT_00000012 = _DAT_00000012 | 0xc;
    do {
      *(ushort *)(iVar2 + 0x1d6) = *(ushort *)(iVar2 + 0x1d6) & 0xfffd;
      SpuGetVoicePitch(iVar1,pwVar3);
      SpuSetVoicePitch(iVar1,0);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x1c;
      pwVar3 = pwVar3 + 1;
    } while (iVar1 < 0x18);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadCancelPauseSound()
 // line 2787, offset 0x80055e90
	/* begin block 1 */
		// Start line: 6176
	/* end block 1 */
	// End Line: 6177

	/* begin block 2 */
		// Start line: 6178
	/* end block 2 */
	// End Line: 6179

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadCancelPauseSound(void)

{
  _DAT_00000012 = _DAT_00000012 & 0xfff3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadResumeSound()
 // line 2794, offset 0x80055eac
	/* begin block 1 */
		// Start line: 2795
		// Start offset: 0x80055EAC
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80055F20
	// End Line: 2810

	/* begin block 2 */
		// Start line: 6190
	/* end block 2 */
	// End Line: 6191

	/* begin block 3 */
		// Start line: 6194
	/* end block 3 */
	// End Line: 6195

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadResumeSound(void)

{
  int iVar1;
  int iVar2;
  
  if ((_DAT_00000012 & 8) != 0) {
    iVar1 = 0;
    iVar2 = 0;
    _DAT_00000012 = _DAT_00000012 & 0xfff3;
    do {
      if ((*(ushort *)(iVar2 + 0x1d6) & 2) == 0) {
        SpuSetVoicePitch(iVar1,*(word *)(iVar1 * 2 + 0x47c));
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < 0x18);
  }
  return;
}





