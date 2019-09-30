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
  aadGp = (ulong)GetGp();
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
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
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadInitVolume()
 // line 198, offset 0x80052068
	/* begin block 1 */
		// Start line: 519
	/* end block 1 */
	// End Line: 520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadInitVolume(void)

{
  _DAT_0000000c = 0;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadSetMasterVolume(int volume)

{
  _DAT_0000000c = (int)(short)volume;
  SpuSetCommonMasterVolume(_DAT_0000000c,_DAT_0000000c);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadStartMasterVolumeFade
               (int targetVolume,int volumeStep,
               TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback fadeCompleteCallback)

{
  DAT_00000010 = volumeStep;
  _DAT_00000014 = targetVolume;
  mcardSaveMenu = fadeCompleteCallback;
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
  DAT_0000001c = volume & 0xff;
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
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_00000020 = volume;
  if (0 < (int)mainMenuScreen) {
    do {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      aadUpdateSlotVolPan(*(_AadSequenceSlot **)(iVar1 + 0x34));
    } while (iVar2 < (int)mainMenuScreen);
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
  the_mcmenu_table.initialize = (_func_67 *)volumeStep;
  the_mcmenu_table.terminate = (_func_68 *)targetVolume;
  the_mcmenu_table.begin = (_func_69 *)fadeCompleteCallback;
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
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
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

/* WARNING: Removing unreachable block (ram,0x80052270) */
/* WARNING: Removing unreachable block (ram,0x80052284) */
/* WARNING: Removing unreachable block (ram,0x800522a0) */
/* WARNING: Removing unreachable block (ram,0x800522c0) */
/* WARNING: Removing unreachable block (ram,0x800522d4) */
/* WARNING: Removing unreachable block (ram,0x800522dc) */
/* WARNING: Removing unreachable block (ram,0x800522e4) */
/* WARNING: Removing unreachable block (ram,0x800522b4) */
/* WARNING: Removing unreachable block (ram,0x800522e8) */
/* WARNING: Removing unreachable block (ram,0x800522ec) */
/* WARNING: Removing unreachable block (ram,0x800522fc) */
/* WARNING: Removing unreachable block (ram,0x80052318) */
/* WARNING: Removing unreachable block (ram,0x80052328) */
/* WARNING: Removing unreachable block (ram,0x8005232c) */
/* WARNING: Removing unreachable block (ram,0x8005234c) */
/* WARNING: Removing unreachable block (ram,0x80052360) */
/* WARNING: Removing unreachable block (ram,0x80052390) */
/* WARNING: Removing unreachable block (ram,0x800523a4) */
/* WARNING: Removing unreachable block (ram,0x800523b0) */
/* WARNING: Removing unreachable block (ram,0x800523c0) */
/* WARNING: Removing unreachable block (ram,0x800523d4) */
/* WARNING: Removing unreachable block (ram,0x800523d8) */
/* WARNING: Removing unreachable block (ram,0x800523e8) */
/* WARNING: Removing unreachable block (ram,0x800523fc) */
/* WARNING: Removing unreachable block (ram,0x80052410) */
/* WARNING: Removing unreachable block (ram,0x80052420) */
/* WARNING: Removing unreachable block (ram,0x80052430) */
/* WARNING: Removing unreachable block (ram,0x80052440) */
/* WARNING: Removing unreachable block (ram,0x8005244c) */
/* WARNING: Removing unreachable block (ram,0x80052488) */
/* WARNING: Removing unreachable block (ram,0x800524b4) */
/* WARNING: Removing unreachable block (ram,0x800524b8) */
/* WARNING: Removing unreachable block (ram,0x800524d0) */
/* WARNING: Removing unreachable block (ram,0x800524e8) */
/* WARNING: Removing unreachable block (ram,0x80052504) */
/* WARNING: Removing unreachable block (ram,0x8005250c) */
/* WARNING: Removing unreachable block (ram,0x8005251c) */
/* WARNING: Removing unreachable block (ram,0x80052520) */
/* WARNING: Removing unreachable block (ram,0x80052568) */
/* WARNING: Removing unreachable block (ram,0x80052574) */
/* WARNING: Removing unreachable block (ram,0x8005258c) */
/* WARNING: Removing unreachable block (ram,0x800525ac) */
/* WARNING: Removing unreachable block (ram,0x800525b4) */
/* WARNING: Removing unreachable block (ram,0x8005260c) */
/* WARNING: Removing unreachable block (ram,0x80052624) */
/* WARNING: Removing unreachable block (ram,0x8005263c) */
/* WARNING: Removing unreachable block (ram,0x80052650) */
/* WARNING: Removing unreachable block (ram,0x80052630) */
/* WARNING: Removing unreachable block (ram,0x80052654) */
/* WARNING: Removing unreachable block (ram,0x8005265c) */
/* WARNING: Removing unreachable block (ram,0x80052678) */
/* WARNING: Removing unreachable block (ram,0x80052680) */
/* WARNING: Removing unreachable block (ram,0x80052690) */
/* WARNING: Removing unreachable block (ram,0x800526a0) */
/* WARNING: Removing unreachable block (ram,0x800526b4) */
/* WARNING: Removing unreachable block (ram,0x800526d4) */
/* WARNING: Removing unreachable block (ram,0x800526e8) */
/* WARNING: Removing unreachable block (ram,0x800526c0) */
/* WARNING: Removing unreachable block (ram,0x800526ec) */
/* WARNING: Removing unreachable block (ram,0x800526f4) */
/* WARNING: Removing unreachable block (ram,0x80052710) */
/* WARNING: Removing unreachable block (ram,0x80052718) */
/* WARNING: Removing unreachable block (ram,0x80052720) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadSlotUpdate(void)

{
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aadLoadDynamicSoundBank
              (char *sndFileName,char *smpFileName,int dynamicBankIndex,int loadOption,
              TDRFuncPtr_aadLoadDynamicSoundBank4retProc retProc)

{
  AadMemoryStruct *pAVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = 0;
  pAVar1 = (AadMemoryStruct *)0x0;
  do {
    iVar3 = iVar3 + 1;
    if (pAVar1->dynamicBankStatus[0] == 1) {
      return (int)&DAT_00001006;
    }
    pAVar1 = (AadMemoryStruct *)&pAVar1->numSlots;
  } while (iVar3 < 2);
  if (dynamicBankIndex < 2) {
    if ((*(int *)(dynamicBankIndex * 4 + 0x500) == 2) &&
       (*(int *)(dynamicBankIndex * 4 + 0x508) != 0)) {
      aadFreeDynamicSoundBank(dynamicBankIndex);
    }
    *(undefined4 *)(dynamicBankIndex * 4 + 0x500) = 1;
    strncpy(&UNK_000006d8,sndFileName,0x1f);
    strncpy(&UNK_000006f8,smpFileName,0x1f);
    _DAT_0000072c = 0;
    _DAT_00000720 = retProc;
    _DAT_00000718 = dynamicBankIndex;
    _DAT_0000071c = loadOption;
    (*_DAT_00000730)(sndFileName,aadLoadDynamicSoundBankReturn,0x6d8,0,dynamicBankIndex * 4 + 0x508,
                     4);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadLoadDynamicSoundBankReturn(void *loadedDataPtr,void *data,void *data2)

{
  uint uVar1;
  uint dynamicBankIndex;
  int iVar2;
  
  dynamicBankIndex = *(uint *)((int)data + 0x40);
  uVar1 = aadOpenDynamicSoundBank((uchar *)loadedDataPtr,dynamicBankIndex);
  iVar2 = dynamicBankIndex * 4;
  if (uVar1 == 0) {
    (*_DAT_00000734)((int)data + 0x20,aadLoadDynamicSoundBankReturn2,data,0);
  }
  else {
    *(uint *)(iVar2 + 0x500) = uVar1 & 0xff | 0x80;
    if (*(int *)(iVar2 + 0x508) != 0) {
      (*_DAT_0000073c)();
      *(undefined4 *)(iVar2 + 0x508) = 0;
    }
    if (*(code **)((int)data + 0x48) != (code *)0x0) {
      (**(code **)((int)data + 0x48))(dynamicBankIndex & 0xffff,uVar1);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadLoadDynamicSoundBankReturn2
               (void *loadedDataPtr,long loadedDataSize,short status,void *data1,void *data2)

{
  ulong uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  
  uVar4 = (uint)(ushort)status << 0x10;
  iVar9 = (int)uVar4 >> 0x10;
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
        uVar1 = aadGetReverbSize();
        *(int *)((int)data1 + 0x50) = (0x80000 - *(int *)((int)data1 + 0x4c)) - uVar1;
      }
      *(undefined4 *)(uVar8 * 4 + 0x510) = *(undefined4 *)((int)data1 + 0x50);
    }
    aadWaitForSramTransferComplete();
    SpuSetTransferStartAddr(*(uint *)((int)data1 + 0x50));
    SpuWrite((word *)loadedDataPtr,(undefined *)loadedDataSize,uVar4);
    *(undefined **)((int)data1 + 0x50) = (undefined *)loadedDataSize + *(int *)((int)data1 + 0x50);
    iVar9 = uVar8 * 4;
    if (status != 1) {
      return;
    }
    iVar6 = 0;
    if (0 < *(int *)(*(int *)(iVar9 + 0x4d0) + 0x14)) {
      iVar2 = 0;
      do {
        piVar3 = (int *)(iVar2 + *(int *)(iVar9 + 0x4e8));
        *piVar3 = *piVar3 + *(int *)(iVar9 + 0x510);
        iVar6 = iVar6 + 1;
        iVar2 = iVar6 * 4;
      } while (iVar6 < *(int *)(*(int *)(iVar9 + 0x4d0) + 0x14));
    }
    *(undefined4 *)(uVar8 * 4 + 0x500) = 2;
    pcVar5 = *(code **)((int)data1 + 0x48);
    uVar8 = uVar8 & 0xffff;
    if (pcVar5 == (code *)0x0) {
      return;
    }
    iVar9 = 0;
  }
  else {
    if ((*(uint *)((int)data1 + 0x54) & 2) != 0) {
      return;
    }
    *(uint *)((int)data1 + 0x54) = *(uint *)((int)data1 + 0x54) | 2;
    iVar6 = uVar8 * 4;
    *(uint *)(iVar6 + 0x500) = uVar4 >> 0x18 | 0x80;
    if (*(int *)(iVar6 + 0x508) != 0) {
      (*_DAT_0000073c)();
      *(undefined4 *)(iVar6 + 0x508) = 0;
    }
    pcVar5 = *(code **)((int)data1 + 0x48);
    if (pcVar5 == (code *)0x0) {
      return;
    }
  }
  (*pcVar5)(uVar8,iVar9);
                    /* WARNING: Read-only address (ram,0x0000073c) is written */
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aadFreeDynamicSoundBank(int dynamicBankIndex)

{
  undefined *puVar1;
  
  if (dynamicBankIndex < 2) {
    dynamicBankIndex = dynamicBankIndex * 4;
    puVar1 = &DAT_00001007;
    if ((*(int *)(dynamicBankIndex + 0x500) == 2) &&
       (puVar1 = &DAT_00001007, *(int *)(dynamicBankIndex + 0x508) != 0)) {
      *(undefined4 *)(dynamicBankIndex + 0x500) = 0;
      (*_DAT_0000073c)(*(undefined4 *)(dynamicBankIndex + 0x508));
      puVar1 = (undefined *)0x0;
      *(undefined4 *)(dynamicBankIndex + 0x508) = 0;
    }
  }
  else {
    puVar1 = &DAT_00001005;
  }
  return (int)puVar1;
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
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if (dynamicBankIndex < 2) {
    uVar2 = aadCreateFourCharID('a','S','N','D');
    puVar1 = &DAT_00001001;
    if ((*(ulong *)soundBank == uVar2) && (puVar1 = &DAT_00001002, *(int *)(soundBank + 8) == 0x106)
       ) {
      iVar11 = 0;
      dynamicBankIndex = dynamicBankIndex * 4;
      iVar4 = *(int *)(soundBank + 0xc);
      iVar8 = *(int *)(soundBank + 0x10);
      iVar9 = *(int *)(soundBank + 0x14);
      iVar5 = *(int *)(soundBank + 0x18);
      iVar10 = *(int *)(soundBank + 0x1c);
      puVar3 = soundBank + *(int *)(soundBank + 4);
      *(uchar **)(dynamicBankIndex + 0x4d8) = puVar3;
      puVar3 = puVar3 + iVar4 * 8;
      *(uchar **)(dynamicBankIndex + 0x4e0) = puVar3;
      piVar7 = (int *)(puVar3 + iVar8 * 0x10 + iVar9 * 4);
      piVar6 = piVar7 + iVar5;
      *(uchar **)(dynamicBankIndex + 0x4d0) = soundBank;
      *(uchar **)(dynamicBankIndex + 0x4e8) = puVar3 + iVar8 * 0x10;
      *(int **)(dynamicBankIndex + 0x4f0) = piVar7;
      *(int **)(dynamicBankIndex + 0x4f8) = piVar6;
      if (0 < *(int *)(soundBank + 0x18)) {
        do {
          *(int *)(iVar11 * 4 + *(int *)(dynamicBankIndex + 0x4f0)) =
               (int)piVar6 + *piVar7 + iVar10 * 4;
          iVar11 = iVar11 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar11 < *(int *)(soundBank + 0x18));
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aadLoadDynamicSfx(char *fileName,long directoryID,long flags)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (_DAT_00000748 < 0x10) {
    iVar1 = _DAT_00000740 * 0x1c;
    *(undefined4 *)(iVar1 + 0x518) = 0;
    uVar2 = _DAT_000007e4 & 0x3fff;
    _DAT_000007e4 = _DAT_000007e4 + 1;
    *(uint *)(iVar1 + 0x51c) = uVar2 | 0x4000;
    *(long *)(iVar1 + 0x520) = directoryID;
    *(long *)(iVar1 + 0x524) = flags;
    strncpy((char *)(iVar1 + 0x528),fileName,0xb);
    _DAT_00000740 = _DAT_00000740 + 1 & 0xf;
    _DAT_00000748 = _DAT_00000748 + 1;
    iVar1 = *(int *)(iVar1 + 0x51c);
  }
  return iVar1;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aadFreeDynamicSfx(int handle)

{
  int iVar1;
  
  if (_DAT_00000748 < 0x10) {
    iVar1 = _DAT_00000740 * 0x1c;
    *(undefined4 *)(iVar1 + 0x518) = 1;
    *(int *)(iVar1 + 0x51c) = handle;
    _DAT_00000740 = _DAT_00000740 + 1 & 0xf;
    _DAT_00000748 = _DAT_00000748 + 1;
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
  the_mcmenu_table.data_size = (_func_66 *)((uint)the_mcmenu_table.data_size | 2);
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
  _func_37 *p_Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  AadMemoryStruct *pAVar5;
  AadMemoryStruct *pAVar6;
  _func_36 *p_Var7;
  int iVar8;
  _func_36 *p_Var9;
  int iVar10;
  int iVar11;
  
  pAVar5 = (AadMemoryStruct *)0x0;
  iVar11 = 0;
  pAVar6 = pAVar5;
  while ((_func_43 *)oldAddress != pAVar6->dynamicSoundBankData[0]) {
    iVar11 = iVar11 + 1;
    pAVar6 = (AadMemoryStruct *)&pAVar6->numSlots;
    if (1 < iVar11) goto LAB_80053050;
  }
  pAVar6->dynamicSoundBankData[0] = (_func_43 *)((int)oldAddress + offset);
  pAVar6->dynamicProgramAtr[0] = pAVar6->dynamicProgramAtr[0] + offset;
  pAVar6->dynamicToneAtr[0] = pAVar6->dynamicToneAtr[0] + offset;
  p_Var1 = pAVar6->dynamicSoundBankHdr[0] + offset;
  pAVar6->dynamicSoundBankHdr[0] = p_Var1;
  pAVar6->dynamicWaveAddr[0] = pAVar6->dynamicWaveAddr[0] + offset;
  pAVar6->dynamicSequenceAddressTbl[0] =
       (_func_41 **)((int)pAVar6->dynamicSequenceAddressTbl[0] + offset);
  iVar3 = 0;
  if (0 < *(int *)(p_Var1 + 0x18)) {
    do {
      pAVar6->dynamicSequenceAddressTbl[0][iVar3] =
           pAVar6->dynamicSequenceAddressTbl[0][iVar3] + offset;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(p_Var1 + 0x18));
  }
  pAVar6->dynamicSequenceLabelOffsetTbl[0] = pAVar6->dynamicSequenceLabelOffsetTbl[0] + offset;
  iVar3 = 0;
  if (0 < (int)mainMenuScreen) {
    do {
      p_Var9 = pAVar5->sequenceSlots[0];
      if ((p_Var9[0x53e] != (_func_36)0xff) && (*(int *)(p_Var9 + 0x55c) == iVar11)) {
        iVar8 = 0;
        iVar10 = 0;
        p_Var7 = p_Var9;
        do {
          if (*(int *)(p_Var7 + 0x348) != 0) {
            *(int *)(p_Var7 + 0x348) = *(int *)(p_Var7 + 0x348) + offset;
            iVar4 = 0;
            iVar2 = iVar10;
            if ((p_Var9 + iVar8)[0x4e8] != (_func_36)0x0) {
              do {
                *(int *)(p_Var9 + iVar2 + 1000) = *(int *)(p_Var9 + iVar2 + 1000) + offset;
                iVar4 = iVar4 + 1;
                iVar2 = iVar2 + 0x40;
              } while (iVar4 < (int)(uint)(byte)(p_Var9 + iVar8)[0x4e8]);
            }
          }
          iVar10 = iVar10 + 4;
          iVar8 = iVar8 + 1;
          p_Var7 = p_Var7 + 4;
        } while (iVar8 < 0x10);
      }
      iVar3 = iVar3 + 1;
      pAVar5 = (AadMemoryStruct *)&pAVar5->numSlots;
    } while (iVar3 < (int)mainMenuScreen);
  }
LAB_80053050:
  the_mcmenu_table.data_size = (_func_66 *)((uint)the_mcmenu_table.data_size & 0xfffffffd);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadRelocateSfxMemory(void *oldAddress,int offset)

{
  void *pvVar1;
  
  if (oldAddress == _DAT_000007e0) {
    _DAT_000007e0 = (void *)((int)_DAT_000007e0 + offset);
  }
  pvVar1 = _DAT_000007e0;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadGetNumLoadsQueued(void)

{
  return _DAT_00000748;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadPurgeLoadQueue(void)

{
  _DAT_00000740 = 0;
  _DAT_00000744 = 0;
  _DAT_00000748 = 0;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadProcessLoadQueue(void)

{
  ushort uVar1;
  uint uVar2;
  AadMemoryStruct *pAVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  char acStack32 [16];
  
  pAVar3 = (AadMemoryStruct *)0x0;
  iVar4 = 0;
  if ((_DAT_000007a8 & 1) == 0) {
    do {
      iVar4 = iVar4 + 1;
      if (pAVar3->dynamicBankStatus[0] == 1) {
        return;
      }
      pAVar3 = (AadMemoryStruct *)&pAVar3->numSlots;
    } while (iVar4 < 2);
    if ((_DAT_00000748 == 0) || (_DAT_000007e8 != 0)) {
      if (gSramCheckRequest == 0) {
        if (((gDfragRequest != 0) && (_DAT_000007e8 == 0)) && (musicLoadInProgress == 0)) {
          _DAT_000007e8 = 1;
          gDfragRequest = 0;
        }
      }
      else {
        gDfragRequest = aadCheckSramFragmented();
        gSramCheckRequest = 0;
      }
    }
    else {
      uVar2 = _DAT_00000744 + 1 & 0xf;
      _DAT_00000748 = _DAT_00000748 + -1;
      iVar4 = _DAT_00000744 * 0x1c;
      _DAT_00000744 = uVar2;
      if (*(int *)(iVar4 + 0x518) == 0) {
                    /* WARNING: Subroutine does not return */
        strcpy(acStack32,(char *)(iVar4 + 0x528));
      }
      if (*(int *)(iVar4 + 0x518) == 1) {
        iVar6 = _DAT_000007e0;
        if (_DAT_000007e0 != 0) {
LAB_80053310:
          if ((uint)*(ushort *)(iVar6 + 8) != *(uint *)(iVar4 + 0x51c)) goto LAB_800533c8;
          iVar4 = 0;
          puVar5 = (ushort *)(iVar6 + 0x14);
          if (*(short *)(iVar6 + 10) != 0) {
            do {
              uVar1 = *puVar5;
              puVar5 = puVar5 + 1;
              aadFreeSingleDynSfx((uint)uVar1);
              iVar4 = iVar4 + 1;
            } while (iVar4 < (int)(uint)*(ushort *)(iVar6 + 10));
          }
          if (*(int *)(iVar6 + 0xc) == 0) {
            _DAT_000007e0 = *(int *)(iVar6 + 0x10);
          }
          else {
            *(undefined4 *)(*(int *)(iVar6 + 0xc) + 0x10) = *(undefined4 *)(iVar6 + 0x10);
          }
          if (*(int *)(iVar6 + 0x10) != 0) {
            *(undefined4 *)(*(int *)(iVar6 + 0x10) + 0xc) = *(undefined4 *)(iVar6 + 0xc);
          }
          (*_DAT_0000073c)(iVar6);
          gSramFullAlarm = 0;
        }
LAB_800533d8:
        gSramCheckRequest = 1;
      }
    }
    aadProcessSramDefrag();
  }
                    /* WARNING: Read-only address (ram,0x0000073c) is written */
                    /* WARNING: Read-only address (ram,0x000007a8) is written */
  return;
LAB_800533c8:
  iVar6 = *(int *)(iVar6 + 0x10);
  if (iVar6 == 0) goto LAB_800533d8;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadLoadDynamicSfxAbort(AadDynamicSfxLoadInfo *info,int error)

{
  _AadDynSfxFileHdr *p_Var1;
  
  if (info->snfFile != (_AadDynSfxFileHdr *)0x0) {
    if ((info->flags & 2U) != 0) {
      p_Var1 = info->snfFile->prevDynSfxFile;
      if (p_Var1 == (_AadDynSfxFileHdr *)0x0) {
        _DAT_000007e0 = 0;
      }
      else {
        p_Var1->nextDynSfxFile = (_AadDynSfxFileHdr *)0x0;
      }
    }
    (*_DAT_0000073c)(info->snfFile);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    if ((*puVar4 == uVar1) && (*(short *)(*(int *)((int)data + 0x78) + 4) == 0x100)) {
      *(undefined2 *)(*(int *)((int)data + 0x78) + 8) = *(undefined2 *)((int)data + 0x50);
      if (_DAT_000007e0 == 0) {
        _DAT_000007e0 = *(int *)((int)data + 0x78);
        *(undefined4 *)(*(int *)((int)data + 0x78) + 0xc) = 0;
      }
      else {
        iVar2 = *(int *)(_DAT_000007e0 + 0x10);
        iVar3 = _DAT_000007e0;
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
      (*_DAT_00000734)((int)data + 0x28,aadLoadDynamicSfxReturn2,data,0);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  uint uVar11;
  
  puVar10 = (ushort *)0x0;
  uVar11 = 0xff;
  puVar6 = (ushort *)(&DAT_000017f0 + _DAT_00001bf4 * 8);
  uVar5 = waveSize >> 3;
  if (puVar6 != (ushort *)0x0) {
    iVar7 = 0x7f;
    uVar9 = _DAT_00001bf4;
    do {
      if (iVar7 == -1) break;
      if ((((*puVar6 & 0x4000) == 0) && (uVar5 + 6 <= (uint)puVar6[2])) &&
         ((puVar10 == (ushort *)0x0 ||
          (((uint)puVar6[2] - 6) - uVar5 < ((uint)puVar10[2] - 6) - uVar5)))) {
        puVar10 = puVar6;
        uVar11 = uVar9;
      }
      if (*(char *)((int)puVar6 + 7) < '\0') {
        puVar6 = (ushort *)0x0;
      }
      else {
        uVar3 = (uint)*(byte *)((int)puVar6 + 7);
        puVar6 = (ushort *)0x0;
        if (uVar3 != uVar9) {
          puVar6 = (ushort *)(&DAT_000017f0 + uVar3 * 8);
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
      iVar7 = (uint)*(byte *)((int)puVar10 + 7) * 8;
      if ((*(ushort *)(&DAT_000017f0 + iVar7) & 0x4000) == 0) {
        *(ushort *)(&DAT_000017f2 + iVar7) =
             *(short *)(&DAT_000017f2 + iVar7) - (puVar10[2] - uVar4);
        *(ushort *)(&DAT_000017f4 + iVar7) =
             *(short *)(&DAT_000017f4 + iVar7) + (puVar10[2] - uVar4);
        puVar10[2] = uVar4;
        return uVar11;
      }
    }
    uVar8 = (undefined)_DAT_00001bf0;
    puVar6 = (ushort *)(&DAT_000017f0 + _DAT_00001bf0 * 8);
    uVar2 = *puVar6;
    uVar5 = _DAT_00001bf0;
    while ((uVar2 & 0x8000) != 0) {
      uVar5 = uVar5 + 1 & 0x7f;
      uVar8 = (undefined)uVar5;
      if (uVar5 == _DAT_00001bf0) {
        return 0xff;
      }
      puVar6 = (ushort *)(&DAT_000017f0 + uVar5 * 8);
      uVar2 = *puVar6;
    }
    _DAT_00001bf0 = _DAT_00001bf0 + 8 & 0x7f;
    *puVar6 = 0x8000;
    puVar6[1] = puVar10[1] + uVar4;
    uVar2 = puVar10[2];
    *(char *)(puVar6 + 3) = (char)uVar11;
    puVar6[2] = uVar2 - uVar4;
    bVar1 = *(byte *)((int)puVar10 + 7);
    *(byte *)((int)puVar6 + 7) = bVar1;
    if (-1 < (int)((uint)bVar1 << 0x18)) {
      (&DAT_000017f6)[(uint)*(byte *)((int)puVar6 + 7) * 8] = uVar8;
    }
    puVar10[2] = uVar4;
    *(undefined *)((int)puVar10 + 7) = uVar8;
  }
  return uVar11;
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
  return (uint)*(ushort *)(&DAT_000017f2 + handle * 8) << 3;
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
  int iVar2;
  int iVar3;
  
  if (handle < 0x80) {
    iVar2 = handle * 8;
    *(undefined2 *)(&DAT_000017f0 + iVar2) = 0x8000;
    if ((-1 < (char)(&DAT_000017f7)[iVar2]) &&
       (iVar3 = (uint)(byte)(&DAT_000017f7)[iVar2] * 8,
       (*(ushort *)(&DAT_000017f0 + iVar3) & 0x4000) == 0)) {
      *(short *)(&DAT_000017f4 + iVar2) =
           *(short *)(&DAT_000017f4 + iVar2) + *(short *)(&DAT_000017f4 + iVar3);
      bVar1 = (&DAT_000017f7)[iVar3];
      *(ushort *)(&DAT_000017f0 + iVar3) = 0;
      (&DAT_000017f7)[iVar2] = bVar1;
      if (-1 < (int)((uint)bVar1 << 0x18)) {
        (&DAT_000017f6)[(uint)(byte)(&DAT_000017f7)[iVar2] * 8] = (char)handle;
      }
    }
    if ((-1 < (char)(&DAT_000017f6)[iVar2]) &&
       (iVar3 = (uint)(byte)(&DAT_000017f6)[iVar2] * 8,
       (*(ushort *)(&DAT_000017f0 + iVar3) & 0x4000) == 0)) {
      *(short *)(&DAT_000017f4 + iVar3) =
           *(short *)(&DAT_000017f4 + iVar3) + *(short *)(&DAT_000017f4 + iVar2);
      bVar1 = (&DAT_000017f7)[iVar2];
      *(undefined2 *)(&DAT_000017f0 + iVar2) = 0;
      (&DAT_000017f7)[iVar3] = bVar1;
      if (-1 < (int)((uint)bVar1 << 0x18)) {
        (&DAT_000017f6)[(uint)(byte)(&DAT_000017f7)[iVar2] * 8] = (&DAT_000017f6)[iVar2];
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
  int iVar3;
  int iVar4;
  
  if (*(byte *)(sfxID + 0x808) < 0xfe) {
    iVar3 = (uint)*(byte *)(sfxID + 0x808) * 0x14;
    sVar2 = *(short *)(iVar3 + 0xc08) + -1;
    *(short *)(iVar3 + 0xc08) = sVar2;
    if (sVar2 == 0) {
      *(undefined *)(sfxID + 0x808) = 0xff;
      bVar1 = *(byte *)((uint)*(ushort *)(iVar3 + 0xc0a) + 0xa08);
      iVar4 = (uint)bVar1 * 4;
      if (bVar1 < 0xfe) {
        sVar2 = *(short *)(&DAT_00001608 + iVar4) + -1;
        *(short *)(&DAT_00001608 + iVar4) = sVar2;
        if (sVar2 == 0) {
          *(undefined *)((uint)*(ushort *)(iVar3 + 0xc0a) + 0xa08) = 0xff;
          aadWaveFree((uint)(byte)(&DAT_0000160b)[iVar4]);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

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
  puVar2 = (ushort *)(&DAT_000017f0 + _DAT_00001bf4 * 8);
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
      puVar2 = (ushort *)(&DAT_000017f0 + (uint)*(byte *)((int)puVar2 + 7) * 8);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadLoadSingleDynSfx(AadDynamicSfxLoadInfo *info)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  undefined uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  AadDynSfxAttr *pAVar14;
  
  uVar4 = (uint)(info->attr).sfxID;
  info->waveTransferAddr = 0;
  pAVar14 = &info->attr;
  if (*(char *)(uVar4 + 0x808) == -2) {
    *(undefined *)(uVar4 + 0x808) = 0xff;
  }
  bVar1 = *(byte *)((uint)(info->attr).sfxID + 0x808);
  if (bVar1 == 0xff) {
    uVar9 = (undefined)_DAT_000017e8;
    psVar5 = (short *)(_DAT_000017e8 * 0x14 + 0xc08);
    sVar2 = *psVar5;
    uVar4 = _DAT_000017e8;
    while (sVar2 != 0) {
      uVar4 = uVar4 + 1 & 0x7f;
      uVar9 = (undefined)uVar4;
      if (uVar4 == _DAT_000017e8) {
        info->smfLoadingState = 2;
        uVar3 = pAVar14->sfxID;
        goto LAB_80053e3c;
      }
      psVar5 = (short *)(uVar4 * 0x14 + 0xc08);
      sVar2 = *psVar5;
    }
    _DAT_000017e8 = _DAT_000017e8 + 8 & 0x7f;
    *psVar5 = 1;
    psVar5[1] = (info->attr).waveID;
    uVar11 = *(undefined4 *)&(info->attr).toneAttr.centerNote;
    uVar12 = *(undefined4 *)&(info->attr).toneAttr.mode;
    uVar13 = *(undefined4 *)&(info->attr).toneAttr.adsr2;
    *(undefined4 *)(psVar5 + 2) = *(undefined4 *)&(info->attr).toneAttr;
    *(undefined4 *)(psVar5 + 4) = uVar11;
    *(undefined4 *)(psVar5 + 6) = uVar12;
    *(undefined4 *)(psVar5 + 8) = uVar13;
    *(undefined *)((uint)pAVar14->sfxID + 0x808) = uVar9;
    bVar1 = *(byte *)((uint)(info->attr).waveID + 0xa08);
    iVar7 = _DAT_000017ec;
    if (bVar1 == 0xff) {
      do {
        iVar6 = iVar7 * 4;
        iVar10 = iVar7 + 1;
        if (*(short *)(&DAT_00001608 + iVar6) == 0) {
          iVar10 = _DAT_000017ec + 8;
          if (0x77 < _DAT_000017ec + 8) {
            iVar10 = _DAT_000017ec + -0x70;
          }
          _DAT_000017ec = iVar10;
          *(short *)(&DAT_00001608 + iVar6) = 1;
          *(undefined *)((uint)(info->attr).waveID + 0xa08) = (char)iVar7;
          iVar7 = aadWaveMalloc((info->attr).waveID,(info->attr).waveSize);
          (&DAT_0000160b)[iVar6] = (char)iVar7;
          if (-1 < iVar7 << 0x18) {
            uVar8 = aadGetSramBlockAddr((uint)(byte)(&DAT_0000160b)[iVar6]);
            info->waveTransferAddr = uVar8;
            info->smfLoadingState = 3;
            return;
          }
          break;
        }
        if (0x77 < iVar10) {
          iVar10 = 0;
        }
        iVar7 = iVar10;
      } while (iVar10 != _DAT_000017ec);
      aadFreeSingleDynSfx((uint)pAVar14->sfxID);
      info->smfLoadingState = 2;
      uVar3 = pAVar14->sfxID;
LAB_80053e3c:
      *(undefined *)((uint)uVar3 + 0x808) = 0xfe;
      setSramFullAlarm();
      return;
    }
    *(short *)(&DAT_00001608 + (uint)bVar1 * 4) = *(short *)(&DAT_00001608 + (uint)bVar1 * 4) + 1;
  }
  else {
    psVar5 = (short *)((uint)bVar1 * 0x14 + 0xc08);
    *psVar5 = *psVar5 + 1;
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
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  void *__src;
  undefined2 in_register_0000001a;
  undefined *puVar4;
  undefined slot;
  undefined *__n;
  undefined *puVar5;
  
  slot = SUB41(data1,0);
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
          FUN_80054130(slot);
          return;
        }
      }
      else {
        if (iVar3 < 2) {
          if (iVar3 != 0) {
            FUN_80054130(0x61);
            return;
          }
          uVar2 = aadCreateFourCharID('a','S','M','F');
          if (*(ulong *)loadedDataPtr != uVar2) {
            aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,(int)&DAT_0000100b);
            return;
          }
          if (*(short *)((int)loadedDataPtr + 4) != 0x100) {
            aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,(int)&DAT_0000100c);
            return;
          }
          iVar3 = *(int *)((int)data1 + 0x78);
          if ((*(short *)((int)loadedDataPtr + 6) == *(short *)(iVar3 + 6)) &&
             (uVar1 = *(ushort *)(iVar3 + 10),
             (uint)*(ushort *)((int)loadedDataPtr + 8) == (uint)uVar1)) {
            *(undefined4 *)((int)data1 + 0x60) = 1;
            *(undefined4 *)((int)data1 + 100) = 0x18;
            *(uint *)((int)data1 + 0x68) = (uint)uVar1;
            FUN_80054130((char)iVar3);
            return;
          }
          aadLoadDynamicSfxAbort((AadDynamicSfxLoadInfo *)data1,(int)&DAT_0000100d);
          return;
        }
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
LAB_800540f4:
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
                goto LAB_800540f4;
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
    } while ((undefined *)loadedDataSize != (undefined *)0x0);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

int aadCheckSramFragmented(void)

{
  uint uVar1;
  undefined *puVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined *puVar7;
  
  puVar6 = (undefined *)0x0;
  puVar7 = &UNK_000f423f;
  iVar5 = 0;
  puVar3 = (ushort *)(&DAT_000017f0 + _DAT_00001bf4 * 8);
  iVar4 = 0x80;
  do {
    if (puVar3 == (ushort *)0x0) break;
    if ((*puVar3 & 0x4000) == 0) {
      puVar2 = (undefined *)(uint)puVar3[2];
      iVar5 = iVar5 + 1;
      puVar6 = puVar2 + (int)puVar6;
      if (puVar2 < puVar7) {
        puVar7 = puVar2;
      }
    }
    if (*(char *)((int)puVar3 + 7) < '\0') {
      puVar3 = (ushort *)0x0;
    }
    else {
      puVar3 = (ushort *)(&DAT_000017f0 + (uint)*(byte *)((int)puVar3 + 7) * 8);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadProcessSramDefrag(void)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint in_a2;
  undefined *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  byte bVar9;
  uint uVar10;
  
  if (_DAT_000007e8 == 1) {
    puVar7 = (ushort *)(&DAT_000017f0 + _DAT_00001bf4 * 8);
    iVar5 = 0x80;
    uVar10 = _DAT_00001bf4;
    if (puVar7 != (ushort *)0x0) {
      do {
        bVar9 = (byte)uVar10;
        if ((*puVar7 & 0x4000) == 0) break;
        iVar5 = iVar5 + -1;
        bVar9 = *(byte *)((int)puVar7 + 7);
        uVar10 = (uint)bVar9;
        if ((iVar5 == 0) || (0x7f < bVar9)) {
          puVar7 = (ushort *)0x0;
        }
        else {
          puVar7 = (ushort *)(&DAT_000017f0 + uVar10 * 8);
        }
      } while (puVar7 != (ushort *)0x0);
      if ((puVar7 != (ushort *)0x0) && (-1 < *(char *)((int)puVar7 + 7))) {
        bVar1 = *(byte *)((int)puVar7 + 7);
        iVar5 = (uint)bVar1 * 8;
        puVar8 = (ushort *)(&DAT_000017f0 + iVar5);
        if (((*puVar8 & 0x4000) != 0) &&
           (_DAT_000007ec = (word *)(*_DAT_00000738)(0x1000,0x30), _DAT_000007ec != (word *)0x0)) {
          uVar10 = (uint)*puVar8 & 0x3fff;
          _DAT_000007f0 = (uint)*(byte *)(uVar10 + 0xa08);
          if (*(byte *)(uVar10 + 0xa08) < 0xfe) {
            *(undefined *)(uVar10 + 0xa08) = 0xff;
            _DAT_000007f8 = (undefined *)((uint)puVar7[1] << 3);
            _DAT_000007fc = (undefined *)((uint)*(ushort *)(&DAT_000017f2 + iVar5) << 3);
            _DAT_00000800 = (undefined *)((uint)*(ushort *)(&DAT_000017f4 + iVar5) << 3);
            uVar3 = puVar7[2];
            _DAT_000007f4 = uVar10;
            puVar7[2] = *(ushort *)(&DAT_000017f4 + iVar5);
            *(ushort *)(&DAT_000017f4 + iVar5) = uVar3;
            uVar3 = *puVar7;
            *puVar7 = *puVar8;
            *puVar8 = uVar3;
            *(ushort *)(&DAT_000017f2 + iVar5) = puVar7[1] + puVar7[2];
            if (-1 < (char)(&DAT_000017f7)[iVar5]) {
              iVar4 = (uint)(byte)(&DAT_000017f7)[iVar5] * 8;
              if ((*(ushort *)(&DAT_000017f0 + iVar4) & 0x4000) == 0) {
                *(short *)(&DAT_000017f4 + iVar5) =
                     *(short *)(&DAT_000017f4 + iVar5) + *(short *)(&DAT_000017f4 + iVar4);
                bVar2 = (&DAT_000017f7)[iVar4];
                *(ushort *)(&DAT_000017f0 + iVar4) = 0;
                (&DAT_000017f7)[iVar5] = bVar2;
                if (-1 < (int)((uint)bVar2 << 0x18)) {
                  (&DAT_000017f6)[(uint)(byte)(&DAT_000017f7)[iVar5] * 8] = bVar1;
                }
              }
            }
            (&DAT_0000160b)[_DAT_000007f0 * 4] = bVar9;
            _DAT_000007e8 = 2;
            return;
          }
          (*_DAT_0000073c)(_DAT_000007ec);
        }
      }
    }
    _DAT_000007e8 = 0;
  }
  else {
    if (1 < _DAT_000007e8) {
      if (_DAT_000007e8 == 2) {
        iVar5 = SpuIsTransferCompleted(0);
        if (iVar5 != 0) {
          puVar6 = &DAT_00001000;
          if (_DAT_00000800 < &DAT_00001001) {
            puVar6 = _DAT_00000800;
          }
          SpuSetTransferStartAddr((uint)_DAT_000007fc);
          SpuRead((uint)_DAT_000007ec,puVar6,in_a2);
          _DAT_000007e8 = 3;
          _DAT_00000804 = puVar6;
        }
      }
      else {
        if ((_DAT_000007e8 == 3) && (iVar5 = SpuIsTransferCompleted(0), iVar5 != 0)) {
          SpuSetTransferStartAddr((uint)_DAT_000007f8);
          puVar6 = _DAT_00000804;
          SpuWrite(_DAT_000007ec,_DAT_00000804,in_a2);
          _DAT_000007fc = puVar6 + (int)_DAT_000007fc;
          _DAT_00000800 = _DAT_00000800 + -(int)puVar6;
          _DAT_000007f8 = puVar6 + (int)_DAT_000007f8;
          if (_DAT_00000800 == (undefined *)0x0) {
            (*_DAT_0000073c)(_DAT_000007ec);
            *(undefined *)(_DAT_000007f4 + 0xa08) = DAT_000007f0;
            _DAT_000007e8 = 0;
            gSramCheckRequest = 1;
          }
          else {
            _DAT_000007e8 = 2;
          }
        }
      }
    }
  }
                    /* WARNING: Read-only address (ram,0x0000073c) is written */
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
  if ((0xfd < *(byte *)(toneID + 0x808)) && (iVar1 = -1, *(byte *)(toneID + 0x808) != 0xfe)) {
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
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  slot->status = 0;
  slot->selectedDynamicBank = slot->sequenceAssignedDynamicBank;
  slot->slotFlags = slot->slotFlags & 1;
  iVar6 = *(int *)((uint)slot->sequenceNumberAssigned * 4 +
                  *(int *)(slot->sequenceAssignedDynamicBank * 4 + 0x4f0));
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
  
  uVar1 = aadGetReverbMode();
  SpuSetReverbModeType(uVar1);
                    /* WARNING: Subroutine does not return */
  SpuSetReverbVoice(0,0xffffff);
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
  return *(int *)(bank * 4 + 0x500);
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
  if (*(int *)(bank * 4 + 0x500) == 2) {
    iVar1 = *(int *)(*(int *)(bank * 4 + 0x4d0) + 0x18);
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
  
  if (*(int *)(bank * 4 + 0x500) == 2) {
    slot = *(_AadSequenceSlot **)(slotNumber * 4 + 0x34);
    slot->sequenceNumberAssigned = (uchar)sequenceNumber;
    slot->sequenceAssignedDynamicBank = bank;
    aadInitSequenceSlot(slot);
    aadAllNotesOff(slotNumber);
    iVar3 = 0xf;
    if ((slot->tempo).ticksPerUpdate == 0) {
      tempo = aadGetTempoFromDynamicSequence(bank,sequenceNumber,&AStack32);
                    /* WARNING: Subroutine does not return */
      aadSetSlotTempo(slotNumber,tempo);
    }
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
  
  if (*(int *)(bank * 4 + 0x500) == 2) {
    iVar1 = *(int *)(sequenceNumber * 4 + *(int *)(bank * 4 + 0x4f0));
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadSetSlotTempo(int slotNumber,AadTempo *tempo)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = tempo->ppqn;
  iVar2 = *(int *)(slotNumber * 4 + 0x34);
  uVar1 = (tempo->quarterNoteTime / uVar1) * 0x10000 +
          (tempo->quarterNoteTime % uVar1 << 0x10) / uVar1;
  *(uint *)(iVar2 + 8) = uVar1;
  *(undefined2 *)(iVar2 + 0x10) = (short)((&aadUpdateRate)[_DAT_00000008 & 3] / uVar1);
  *(uint *)(iVar2 + 0xc) = (&aadUpdateRate)[_DAT_00000008 & 3] % *(uint *)(iVar2 + 8);
  *(ulong *)(iVar2 + 0x14) = tempo->quarterNoteTime;
  *(undefined2 *)(iVar2 + 0x12) = *(undefined2 *)&tempo->ppqn;
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
  
  if (((slotNumber < (int)mainMenuScreen) &&
      (slot = *(_AadSequenceSlot **)(slotNumber * 4 + 0x34), (slot->status & 1) == 0)) &&
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
  
  if ((slotNumber < (int)mainMenuScreen) &&
     (slot = *(_AadSequenceSlot **)(slotNumber * 4 + 0x34), slot->sequenceNumberAssigned != -1)) {
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
  if (0 < (int)mainMenuScreen) {
    iVar1 = 0;
    do {
      iVar1 = *(int *)(iVar1 + 0x34);
      if ((*(ushort *)(iVar1 + 0x540) & 1) != 0) {
        aadStopSlot(slotNumber);
      }
      *(undefined *)(iVar1 + 0x53e) = 0xff;
      slotNumber = slotNumber + 1;
      iVar1 = slotNumber * 4;
    } while (slotNumber < (int)mainMenuScreen);
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
  int iVar1;
  
  if (slotNumber < (int)mainMenuScreen) {
    iVar1 = *(int *)(slotNumber * 4 + 0x34);
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

void aadEnableSlot(int slotNumber)

{
  int iVar1;
  
  if (slotNumber < (int)mainMenuScreen) {
    iVar1 = *(int *)(slotNumber * 4 + 0x34);
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

void aadPauseSlot(int slotNumber)

{
  int iVar1;
  
  if (slotNumber < (int)mainMenuScreen) {
    iVar1 = *(int *)(slotNumber * 4 + 0x34);
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

void aadResumeSlot(int slotNumber)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (slotNumber < (int)mainMenuScreen) {
    iVar3 = *(int *)(slotNumber * 4 + 0x34);
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

int aadGetSlotStatus(int slotNumber)

{
  return (uint)*(ushort *)(*(int *)(slotNumber * 4 + 0x34) + 0x540);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadAllNotesOff(int slotNumber)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar3 = 0;
  puVar2 = (uint *)&UNK_000001dc;
  iVar4 = *(int *)(slotNumber * 4 + 0x34);
  do {
    if ((*(byte *)(puVar2 + 2) & 0xf0) == *(byte *)(iVar4 + 0x551)) {
      *(undefined *)(puVar2 + 2) = 0xff;
      uVar1 = uVar1 | *puVar2;
      *(ushort *)((int)puVar2 + 0x12) = *(ushort *)((int)puVar2 + 0x12) | 2;
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 7;
  } while (iVar3 < 0x18);
  if (uVar1 != 0) {
    _DAT_000004c4 = _DAT_000004c4 | uVar1;
    _DAT_000004c8 = _DAT_000004c8 & ~uVar1;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadMuteChannels(_AadSequenceSlot *slot,ulong channelList)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = slot->delayedMuteMode & channelList;
  if (uVar1 != 0) {
    channelList = channelList & ~uVar1;
    slot->delayedMuteCmds = slot->delayedMuteCmds | (ushort)uVar1;
  }
  uVar5 = 0;
  uVar4 = 0;
  slot->channelMute = slot->channelMute | (ushort)channelList;
  uVar1 = 1;
  do {
    if ((channelList & uVar1) != 0) {
      iVar3 = 0;
      puVar2 = (uint *)&UNK_000001dc;
      do {
        if ((uint)*(byte *)(puVar2 + 2) == (slot->slotID | uVar4)) {
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
    _DAT_000004c4 = _DAT_000004c4 | uVar5;
    _DAT_000004c8 = _DAT_000004c8 & ~uVar5;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

TDRFuncPtr_aadInstallEndSequenceCallback
aadInstallEndSequenceCallback
          (TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc callbackProc,long data)

{
  TDRFuncPtr_aadInstallEndSequenceCallback pTVar1;
  
  pTVar1 = _DAT_00001bfc;
  _DAT_00001bfc = (TDRFuncPtr_aadInstallEndSequenceCallback)callbackProc;
  _DAT_00001c04 = data;
  return pTVar1;
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
  (&DAT_00001c08)[variableNumber] = (char)value;
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
    the_mcmenu_table.data_size = (_func_66 *)((uint)the_mcmenu_table.data_size | 2);
    return;
  }
  the_mcmenu_table.data_size = (_func_66 *)((uint)the_mcmenu_table.data_size & 0xfffffffd);
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
  int iVar2;
  word *pwVar3;
  
  if (((uint)the_mcmenu_table.data_size & 8) == 0) {
    iVar1 = 0;
    iVar2 = 0;
    pwVar3 = (word *)&DAT_00000494;
    the_mcmenu_table.data_size = (_func_66 *)((uint)the_mcmenu_table.data_size | 0xc);
    do {
      *(ushort *)(iVar2 + 0x1ee) = *(ushort *)(iVar2 + 0x1ee) & 0xfffd;
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
  the_mcmenu_table.data_size = (_func_66 *)((uint)the_mcmenu_table.data_size & 0xfffffff3);
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
  
  if (((uint)the_mcmenu_table.data_size & 8) != 0) {
    the_mcmenu_table.data_size = (_func_66 *)((uint)the_mcmenu_table.data_size & 0xfffffff3);
    iVar1 = 0;
    iVar2 = 0;
    do {
      if ((*(ushort *)(iVar2 + 0x1ee) & 2) == 0) {
        SpuSetVoicePitch(iVar1,*(word *)(iVar1 * 2 + 0x494));
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x1c;
    } while (iVar1 < 0x18);
  }
  return;
}





