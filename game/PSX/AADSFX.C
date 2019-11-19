#include "THISDUST.H"
#include "AADSFX.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadPlaySfx(unsigned int toneID /*$a0*/, int volume /*$s1*/, int pan /*$s2*/, int pitchOffset /*$s0*/)
 // line 19, offset 0x80058014
	/* begin block 1 */
		// Start line: 20
		// Start offset: 0x80058014
		// Variables:
	// 		unsigned long handle; // $s0
	/* end block 1 */
	// End offset: 0x80058014
	// End Line: 20

	/* begin block 2 */
		// Start line: 38
	/* end block 2 */
	// End Line: 39

ulong aadPlaySfx(uint toneID,int volume,int pan,int pitchOffset)

{
  ulong ulongParam;
  
  ulongParam = createSfxHandle(toneID);
  aadPutSfxCommand(0,volume,pan,ulongParam,(int)(short)pitchOffset);
  return ulongParam;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadStopSfx(unsigned long handle /*$s0*/)
 // line 37, offset 0x80058078
	/* begin block 1 */
		// Start line: 75
	/* end block 1 */
	// End Line: 76

ulong aadStopSfx(ulong handle)

{
  aadPutSfxCommand(1,0,0,handle,0);
  return handle;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStopAllSfx()
 // line 45, offset 0x800580b4
	/* begin block 1 */
		// Start line: 92
	/* end block 1 */
	// End Line: 93

/* WARNING: Unknown calling convention yet parameter storage is locked */

void aadStopAllSfx(void)

{
  aadPutSfxCommand(4,0,0,0,0);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxPlaying(unsigned long handle /*$a0*/)
 // line 53, offset 0x800580e4
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800580E4
		// Variables:
	// 		struct AadSynthVoice *voice; // $v1
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8005814C
	// End Line: 69

	/* begin block 2 */
		// Start line: 109
	/* end block 2 */
	// End Line: 110

	/* begin block 3 */
		// Start line: 110
	/* end block 3 */
	// End Line: 111

	/* begin block 4 */
		// Start line: 114
	/* end block 4 */
	// End Line: 115

int aadIsSfxPlaying(ulong handle)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x1c4;
  while ((((*(char *)(iVar2 + 8) != -0x30 || (*(char *)(iVar1 + 0x464) == '\0')) ||
          (*(char *)(iVar1 + 0x464) == '\x02')) || (*(ulong *)(iVar2 + 4) != handle))) {
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x1c;
    if (0x17 < iVar1) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxPlayingOrRequested(unsigned long handle /*$s0*/)
 // line 72, offset 0x80058154
	/* begin block 1 */
		// Start line: 73
		// Start offset: 0x80058154
		// Variables:
	// 		int commandOut; // $a1
	// 		int i; // $a2
	// 		struct AadSfxCommand *sfxCmd; // $v1
	/* end block 1 */
	// End offset: 0x800581FC
	// End Line: 89

	/* begin block 2 */
		// Start line: 154
	/* end block 2 */
	// End Line: 155

int aadIsSfxPlayingOrRequested(ulong handle)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  EnterCriticalSection();
  uVar4 = (uint)uRam000001be;
  uVar3 = (uint)bRam000001bd;
  if (uRam000001be != 0) {
    pcVar2 = (char *)(uVar3 * 0xc + 0x3c);
    do {
      if ((*pcVar2 == '\0') && (*(ulong *)(pcVar2 + 4) == handle)) {
        ExitCriticalSection();
        return 1;
      }
      uVar3 = uVar3 + 1;
      pcVar2 = pcVar2 + 0xc;
      if (uVar3 == 0x20) {
        pcVar2 = (char *)0x3c;
        uVar3 = 0;
      }
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  ExitCriticalSection();
  iVar1 = aadIsSfxPlaying(handle);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxTypePlaying(unsigned int toneID /*$a0*/)
 // line 93, offset 0x8005820c
	/* begin block 1 */
		// Start line: 95
		// Start offset: 0x8005820C
		// Variables:
	// 		struct AadSynthVoice *voice; // $v1
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80058278
	// End Line: 108

	/* begin block 2 */
		// Start line: 202
	/* end block 2 */
	// End Line: 203

	/* begin block 3 */
		// Start line: 203
	/* end block 3 */
	// End Line: 204

	/* begin block 4 */
		// Start line: 207
	/* end block 4 */
	// End Line: 208

int aadIsSfxTypePlaying(uint toneID)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x1c4;
  while ((((*(char *)(iVar2 + 8) != -0x30 || ((uint)*(ushort *)(iVar2 + 4) != (toneID & 0xffff))) ||
          (*(char *)(iVar1 + 0x464) == '\0')) || (*(char *)(iVar1 + 0x464) == '\x02'))) {
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x1c;
    if (0x17 < iVar1) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxTypePlayingOrRequested(unsigned int sfxToneID /*$s0*/)
 // line 111, offset 0x80058280
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x80058280
		// Variables:
	// 		int commandOut; // $a1
	// 		int i; // $a2
	// 		struct AadSfxCommand *sfxCmd; // $v1
	/* end block 1 */
	// End offset: 0x80058328
	// End Line: 129

	/* begin block 2 */
		// Start line: 244
	/* end block 2 */
	// End Line: 245

int aadIsSfxTypePlayingOrRequested(uint sfxToneID)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  EnterCriticalSection();
  uVar4 = (uint)uRam000001be;
  uVar3 = (uint)bRam000001bd;
  if (uRam000001be != 0) {
    pcVar2 = (char *)(uVar3 * 0xc + 0x3c);
    do {
      if ((*pcVar2 == '\0') && ((uint)*(ushort *)(pcVar2 + 4) == sfxToneID)) {
        ExitCriticalSection();
        return 1;
      }
      uVar3 = uVar3 + 1;
      pcVar2 = pcVar2 + 0xc;
      if (uVar3 == 0x20) {
        pcVar2 = (char *)0x3c;
        uVar3 = 0;
      }
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  ExitCriticalSection();
  iVar1 = aadIsSfxTypePlaying(sfxToneID);
  return iVar1;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadSetSfxVolPanPitch(unsigned long handle /*$s0*/, int volume /*$a1*/, int pan /*$a2*/, int pitch /*$a3*/)
 // line 160, offset 0x80058338
	/* begin block 1 */
		// Start line: 314
	/* end block 1 */
	// End Line: 315

ulong aadSetSfxVolPanPitch(ulong handle,int volume,int pan,int pitch)

{
  aadPutSfxCommand(3,volume & 0xff,pan & 0xff,handle,(int)(short)pitch);
  return handle;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ createSfxHandle(unsigned int toneID /*$a0*/)
 // line 168, offset 0x8005837c
	/* begin block 1 */
		// Start line: 334
	/* end block 1 */
	// End Line: 335

	/* begin block 2 */
		// Start line: 335
	/* end block 2 */
	// End Line: 336

ulong createSfxHandle(uint toneID)

{
  ushort uVar1;
  
  uVar1 = uRam000001c0 + 1;
  if ((ushort)(uRam000001c0 + 1) == 0) {
    uVar1 = uRam000001c0 + 2;
  }
  uRam000001c0 = uVar1;
  return (uint)uRam000001c0 << 0x10 | toneID & 0xffff;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPutSfxCommand(int statusByte /*$s0*/, int dataByte0 /*$s2*/, int dataByte1 /*$s3*/, unsigned long ulongParam /*$s4*/, int shortParam /*stack 16*/)
 // line 177, offset 0x800583c4
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x800583C4
		// Variables:
	// 		struct AadSfxCommand *sfxCmd; // $v1
	/* end block 1 */
	// End offset: 0x80058498
	// End Line: 209

	/* begin block 2 */
		// Start line: 352
	/* end block 2 */
	// End Line: 353

	/* begin block 3 */
		// Start line: 354
	/* end block 3 */
	// End Line: 355

void aadPutSfxCommand(int statusByte,int dataByte0,int dataByte1,ulong ulongParam,int shortParam)

{
  int iVar1;
  undefined uVar2;
  
  uVar2 = (undefined)statusByte;
  if ((uRam000001be < 0x1e) || (uVar2 = 4, uRam000001be < 0x1f)) {
    EnterCriticalSection();
    iVar1 = (uint)bRam000001bc * 0xc;
    *(undefined *)(iVar1 + 0x3c) = uVar2;
    *(undefined *)(iVar1 + 0x3d) = (char)dataByte0;
    *(undefined *)(iVar1 + 0x3e) = (char)dataByte1;
    *(ulong *)(iVar1 + 0x40) = ulongParam;
    *(undefined2 *)(iVar1 + 0x44) = (short)shortParam;
    bRam000001bc = bRam000001bc + 1;
    if (bRam000001bc == 0x20) {
      bRam000001bc = 0;
    }
    uRam000001be = uRam000001be + 1;
    ExitCriticalSection();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadExecuteSfxCommand(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 229, offset 0x800584b8
	/* begin block 1 */
		// Start line: 463
	/* end block 1 */
	// End Line: 464

void aadExecuteSfxCommand(AadSfxCommand *sfxCmd)

{
  if (sfxCmd->statusByte < 9) {
    (*(code *)(&sfxCmdFunction)[sfxCmd->statusByte])();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdPlayTone(struct AadSfxCommand *sfxCmd /*$s4*/)
 // line 248, offset 0x80058508
	/* begin block 1 */
		// Start line: 249
		// Start offset: 0x80058508
		// Variables:
	// 		unsigned long handle; // $s7
	// 		struct AadProgramAtr *progAtr; // $fp
	// 		struct AadToneAtr *toneAtr; // $s2
	// 		struct AadSynthVoice *voice; // $s1
	// 		unsigned short midiNote; // $s5
	// 		unsigned long waveAddr; // $s6
	// 		struct AadLoadedSfxToneAttr *sfxToneAttr; // $s3
	// 		struct AadLoadedSfxWaveAttr *sfxWaveAttr; // $v0
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80058640
	// End Line: 339

	/* begin block 2 */
		// Start line: 501
	/* end block 2 */
	// End Line: 502

void sfxCmdPlayTone(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  uchar uVar2;
  int iVar3;
  ulong waveStartAddr;
  AadSynthVoice *voice;
  uint uVar4;
  
  uVar4 = sfxCmd->ulongParam;
  bVar1 = *(byte *)((uVar4 & 0xffff) + 0x770);
  if (bVar1 != 0xff) {
    iVar3 = (uint)bVar1 * 0x14;
    bVar1 = *(byte *)((uint)*(ushort *)(iVar3 + 0xb72) + 0x970);
    if (bVar1 != 0xff) {
      waveStartAddr = aadGetSramBlockAddr(*(uchar *)((uint)bVar1 * 4 + 0x1573));
      bVar1 = *(byte *)(iVar3 + 0xb7a);
      voice = aadAllocateVoice((uint)*(byte *)(iVar3 + 0xb74));
      if (voice != (AadSynthVoice *)0x0) {
        aadPlayTone((AadToneAtr *)(iVar3 + 0xb74),waveStartAddr,&aadDummySfxProgram,(uint)bVar1,0x7f
                    ,(uint)sfxCmd->dataByte[0],(uint)sfxCmd->dataByte[1],(uint)bRam000001c2,
                    (uint)DAT_00000010,voice,(int)sfxCmd->shortParam);
        voice->handle = uVar4;
        voice->voiceID = -0x30;
        uVar2 = *(uchar *)(iVar3 + 0xb74);
        voice->note = bVar1;
        voice->priority = uVar2;
        uVar2 = *(uchar *)(iVar3 + 0xb75);
        voice->volume = '\x7f';
        voice->program = uVar2;
        voice->updateVol = sfxCmd->dataByte[0];
        uVar2 = sfxCmd->dataByte[1];
        voice->progAtr = &aadDummySfxProgram;
        voice->toneAtr = (AadToneAtr *)(iVar3 + 0xb74);
        voice->pan = uVar2;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdStopTone(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 343, offset 0x80058670
	/* begin block 1 */
		// Start line: 345
		// Start offset: 0x80058670
		// Variables:
	// 		unsigned long handle; // $t0
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned short i; // $a3
	// 		unsigned long vmask; // $v1
	/* end block 1 */
	// End offset: 0x800586FC
	// End Line: 365

	/* begin block 2 */
		// Start line: 746
	/* end block 2 */
	// End Line: 747

	/* begin block 3 */
		// Start line: 747
	/* end block 3 */
	// End Line: 748

	/* begin block 4 */
		// Start line: 750
	/* end block 4 */
	// End Line: 751

void sfxCmdStopTone(AadSfxCommand *sfxCmd)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  ulong uVar5;
  
  uVar2 = 0;
  uVar5 = sfxCmd->ulongParam;
  uVar4 = 0;
  uVar3 = 0;
  do {
    iVar1 = uVar3 * 0x1c;
    if ((((*(char *)(iVar1 + 0x1cc) == -0x30) && (*(ulong *)(iVar1 + 0x1c8) == uVar5)) &&
        (*(char *)(uVar3 + 0x464) != '\0')) && (*(char *)(uVar3 + 0x464) != '\x02')) {
      *(undefined *)(iVar1 + 0x1cc) = 0xff;
      uVar2 = uVar2 | *(uint *)(iVar1 + 0x1c4);
    }
    uVar4 = uVar4 + 1;
    uVar3 = (uint)uVar4;
  } while (uVar4 < 0x18);
  uRam000004ac = uRam000004ac | uVar2;
  uRam000004b0 = uRam000004b0 & ~uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdStopAllTones(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 371, offset 0x80058728
	/* begin block 1 */
		// Start line: 373
		// Start offset: 0x80058728
		// Variables:
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned long vmask; // $v1
	// 		unsigned short i; // $a3
	/* end block 1 */
	// End offset: 0x800587A0
	// End Line: 392

	/* begin block 2 */
		// Start line: 813
	/* end block 2 */
	// End Line: 814

	/* begin block 3 */
		// Start line: 814
	/* end block 3 */
	// End Line: 815

	/* begin block 4 */
		// Start line: 818
	/* end block 4 */
	// End Line: 819

void sfxCmdStopAllTones(AadSfxCommand *sfxCmd)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar2 = 0;
  uVar4 = 0;
  uVar3 = 0;
  do {
    iVar1 = uVar3 * 0x1c;
    if (((*(char *)(iVar1 + 0x1cc) == -0x30) && (*(char *)(uVar3 + 0x464) != '\0')) &&
       (*(char *)(uVar3 + 0x464) != '\x02')) {
      *(undefined *)(iVar1 + 0x1cc) = 0xff;
      uVar2 = uVar2 | *(uint *)(iVar1 + 0x1c4);
    }
    uVar4 = uVar4 + 1;
    uVar3 = (uint)uVar4;
  } while (uVar4 < 0x18);
  uRam000004ac = uRam000004ac | uVar2;
  uRam000004b0 = uRam000004b0 & ~uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetToneVolumeAndPan(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 398, offset 0x800587cc
	/* begin block 1 */
		// Start line: 399
		// Start offset: 0x800587CC
		// Variables:
	// 		unsigned long handle; // $a3
	// 		struct AadSynthVoice *voice; // $t0
	// 		unsigned short i; // $t1
	// 		struct AadVolume newVoiceVol; // stack offset -16

		/* begin block 1.1 */
			// Start line: 417
			// Start offset: 0x80058880
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x80058880
		// End Line: 417

		/* begin block 1.2 */
			// Start line: 418
			// Start offset: 0x800588E8
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.2 */
		// End offset: 0x800588E8
		// End Line: 418

		/* begin block 1.3 */
			// Start line: 419
			// Start offset: 0x80058964
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.3 */
		// End offset: 0x80058964
		// End Line: 419

		/* begin block 1.4 */
			// Start line: 420
			// Start offset: 0x800589CC
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.4 */
		// End offset: 0x800589CC
		// End Line: 420

		/* begin block 1.5 */
			// Start line: 420
			// Start offset: 0x800589CC
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.5 */
		// End offset: 0x800589CC
		// End Line: 420

		/* begin block 1.6 */
			// Start line: 420
			// Start offset: 0x800589CC
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.6 */
		// End offset: 0x800589CC
		// End Line: 420

		/* begin block 1.7 */
			// Start line: 420
			// Start offset: 0x800589CC
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.7 */
		// End offset: 0x800589CC
		// End Line: 420
	/* end block 1 */
	// End offset: 0x80058B10
	// End Line: 435

	/* begin block 2 */
		// Start line: 878
	/* end block 2 */
	// End Line: 879

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sfxCmdSetToneVolumeAndPan(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short local_10;
  short local_e;
  
  uVar4 = 0;
  uVar3 = 0;
  while ((((iVar2 = uVar3 * 0x1c, *(char *)(iVar2 + 0x1cc) != -0x30 ||
           (*(ulong *)(iVar2 + 0x1c8) != sfxCmd->ulongParam)) || (*(char *)(uVar3 + 0x464) == '\0'))
         || (*(char *)(uVar3 + 0x464) == '\x02'))) {
    uVar4 = uVar4 + 1;
    uVar3 = (uint)uVar4;
    if (0x17 < uVar4) {
      return;
    }
  }
  local_10 = (ushort)*(byte *)(iVar2 + 0x1d2) * (ushort)*(byte *)(iVar2 + 0x1d2);
  local_e = (ushort)*(byte *)(iVar2 + 0x1d2) * (ushort)*(byte *)(iVar2 + 0x1d2);
  if ((_DAT_00000012 & 1) == 0) {
    bVar1 = sfxCmd->dataByte[1];
    if (bVar1 < 0x41) {
      if (bVar1 < 0x3f) {
        local_e = (short)((int)((int)local_10 * (uint)sfxCmd->dataByte[1] *
                               (uint)sfxCmd->dataByte[1]) >> 0xc);
      }
    }
    else {
      local_10 = (short)((int)local_e * (0x7f - (uint)bVar1) * (0x7f - (uint)bVar1) >> 0xc);
    }
  }
  uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1d8) + 2);
  iVar5 = uVar3 * uVar3;
  local_10 = (short)((uint)(local_10 * iVar5) >> 0xe);
  local_e = (short)((uint)(local_e * iVar5) >> 0xe);
  if ((_DAT_00000012 & 1) == 0) {
    bVar1 = *(byte *)(*(int *)(iVar2 + 0x1d8) + 3);
    if (bVar1 < 0x41) {
      if (bVar1 < 0x3f) {
        uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1d8) + 3);
        local_e = (short)((int)((int)local_10 * uVar3 * uVar3) >> 0xc);
      }
    }
    else {
      local_10 = (short)((int)local_e * (0x7f - (uint)bVar1) * (0x7f - (uint)bVar1) >> 0xc);
    }
  }
  iVar5 = (uint)sfxCmd->dataByte[0] * (uint)sfxCmd->dataByte[0];
  *(uchar *)(iVar2 + 0x1d3) = sfxCmd->dataByte[0];
  uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1dc) + 4);
  iVar2 = uVar3 * uVar3;
  iVar6 = (uint)bRam000001c2 * (uint)bRam000001c2;
  iVar7 = (uint)DAT_00000010 * (uint)DAT_00000010;
  SpuSetVoiceVolume((uint)uVar4,
                    (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_10 *
                                                                                    iVar5) >> 0xe) *
                                                                     iVar2) >> 0xe) * iVar6) >> 0xe)
                                       * iVar7) >> 0xe),
                    (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_e * iVar5
                                                                                    ) >> 0xe) *
                                                                     iVar2) >> 0xe) * iVar6) >> 0xe)
                                       * iVar7) >> 0xe));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetToneVolPanPitch(struct AadSfxCommand *sfxCmd /*$s2*/)
 // line 438, offset 0x80058b20
	/* begin block 1 */
		// Start line: 439
		// Start offset: 0x80058B20
		// Variables:
	// 		unsigned long handle; // $a2
	// 		struct AadSynthVoice *voice; // $s0
	// 		unsigned short i; // $s1
	// 		struct AadVolume newVoiceVol; // stack offset -24
	// 		unsigned short newPitch; // $a1
	// 		unsigned short finePitch; // $a1
	// 		unsigned short pitchIndex; // $a0

		/* begin block 1.1 */
			// Start line: 458
			// Start offset: 0x80058BE4
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x80058BE4
		// End Line: 458

		/* begin block 1.2 */
			// Start line: 459
			// Start offset: 0x80058C4C
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.2 */
		// End offset: 0x80058C4C
		// End Line: 459

		/* begin block 1.3 */
			// Start line: 460
			// Start offset: 0x80058CC8
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.3 */
		// End offset: 0x80058CC8
		// End Line: 460

		/* begin block 1.4 */
			// Start line: 461
			// Start offset: 0x80058D30
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.4 */
		// End offset: 0x80058D30
		// End Line: 461

		/* begin block 1.5 */
			// Start line: 461
			// Start offset: 0x80058D30
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.5 */
		// End offset: 0x80058D30
		// End Line: 461

		/* begin block 1.6 */
			// Start line: 461
			// Start offset: 0x80058D30
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.6 */
		// End offset: 0x80058D30
		// End Line: 461

		/* begin block 1.7 */
			// Start line: 461
			// Start offset: 0x80058D30
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.7 */
		// End offset: 0x80058D30
		// End Line: 461
	/* end block 1 */
	// End offset: 0x80058F64
	// End Line: 493

	/* begin block 2 */
		// Start line: 996
	/* end block 2 */
	// End Line: 997

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sfxCmdSetToneVolPanPitch(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short local_18;
  short local_16;
  
  uVar5 = 0;
  uVar3 = 0;
  while ((((iVar2 = uVar3 * 0x1c, *(char *)(iVar2 + 0x1cc) != -0x30 ||
           (*(ulong *)(iVar2 + 0x1c8) != sfxCmd->ulongParam)) || (*(char *)(uVar3 + 0x464) == '\0'))
         || (*(char *)(uVar3 + 0x464) == '\x02'))) {
    uVar5 = uVar5 + 1;
    uVar3 = (uint)uVar5;
    if (0x17 < uVar5) {
      return;
    }
  }
  local_18 = (ushort)*(byte *)(iVar2 + 0x1d2) * (ushort)*(byte *)(iVar2 + 0x1d2);
  local_16 = (ushort)*(byte *)(iVar2 + 0x1d2) * (ushort)*(byte *)(iVar2 + 0x1d2);
  if ((_DAT_00000012 & 1) == 0) {
    bVar1 = sfxCmd->dataByte[1];
    if (bVar1 < 0x41) {
      if (bVar1 < 0x3f) {
        local_16 = (short)((int)((int)local_18 * (uint)sfxCmd->dataByte[1] *
                                (uint)sfxCmd->dataByte[1]) >> 0xc);
      }
    }
    else {
      local_18 = (short)((int)local_16 * (0x7f - (uint)bVar1) * (0x7f - (uint)bVar1) >> 0xc);
    }
  }
  uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1d8) + 2);
  iVar6 = uVar3 * uVar3;
  local_18 = (short)((uint)(local_18 * iVar6) >> 0xe);
  local_16 = (short)((uint)(local_16 * iVar6) >> 0xe);
  if ((_DAT_00000012 & 1) == 0) {
    bVar1 = *(byte *)(*(int *)(iVar2 + 0x1d8) + 3);
    if (bVar1 < 0x41) {
      if (bVar1 < 0x3f) {
        uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1d8) + 3);
        local_16 = (short)((int)((int)local_18 * uVar3 * uVar3) >> 0xc);
      }
    }
    else {
      local_18 = (short)((int)local_16 * (0x7f - (uint)bVar1) * (0x7f - (uint)bVar1) >> 0xc);
    }
  }
  iVar6 = (uint)sfxCmd->dataByte[0] * (uint)sfxCmd->dataByte[0];
  *(uchar *)(iVar2 + 0x1d3) = sfxCmd->dataByte[0];
  uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1dc) + 4);
  iVar7 = uVar3 * uVar3;
  iVar8 = (uint)bRam000001c2 * (uint)bRam000001c2;
  iVar9 = (uint)DAT_00000010 * (uint)DAT_00000010;
  SpuSetVoiceVolume((uint)uVar5,
                    (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_18 *
                                                                                    iVar6) >> 0xe) *
                                                                     iVar7) >> 0xe) * iVar8) >> 0xe)
                                       * iVar9) >> 0xe),
                    (int)(short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_16 *
                                                                                    iVar6) >> 0xe) *
                                                                     iVar7) >> 0xe) * iVar8) >> 0xe)
                                       * iVar9) >> 0xe));
  iVar6 = *(int *)(iVar2 + 0x1d8);
  uVar3 = (uint)*(byte *)(iVar2 + 0x1ce) - ((uint)*(byte *)(iVar6 + 4) - 0x3c);
  if ((*(byte *)(iVar6 + 5) & 0x80) == 0) {
    uVar3 = uVar3 & 0xffff;
    sVar4 = (&aadPitchTable)[uVar3] +
            (ushort)((&aadStepsPerCent)[uVar3] * 100 * (uint)*(byte *)(iVar6 + 5) >> 0x17);
  }
  else {
    uVar3 = uVar3 & 0xffff;
    sVar4 = (&aadPitchTable)[uVar3] -
            (ushort)((&aadStepsPerCent)[uVar3] * 100 * (0x100 - (uint)*(byte *)(iVar6 + 5) & 0xffff)
                    >> 0x17);
  }
  SpuSetVoicePitch((uint)uVar5,sVar4 + sfxCmd->shortParam);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdLockVoice(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 497, offset 0x80058f7c
	/* begin block 1 */
		// Start line: 498
		// Start offset: 0x80058F7C
		// Variables:
	// 		void (*callbackProc)(); // $s0
	// 		struct AadSynthVoice *voice; // $v1
	/* end block 1 */
	// End offset: 0x80058FB8
	// End Line: 512

	/* begin block 2 */
		// Start line: 1180
	/* end block 2 */
	// End Line: 1181

void sfxCmdLockVoice(AadSfxCommand *sfxCmd)

{
  AadSynthVoice *pAVar1;
  ulong uVar2;
  code *pcVar3;
  
  pcVar3 = (code *)sfxCmd->ulongParam;
  pAVar1 = aadAllocateVoice(0xff);
  uVar2 = 0;
  if (pAVar1 != (AadSynthVoice *)0x0) {
    uVar2 = pAVar1->voiceMask;
    pAVar1->flags = pAVar1->flags | 1;
  }
  (*pcVar3)(uVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetVoiceAttr(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 515, offset 0x80058fc8
	/* begin block 1 */
		// Start line: 516
		// Start offset: 0x80058FC8
		// Variables:
	// 		unsigned long v; // $s0
	// 		unsigned long vmask; // $v1
	// 		struct SpuVoiceAttr *voiceAttr; // $s1
	/* end block 1 */
	// End offset: 0x80059008
	// End Line: 527

	/* begin block 2 */
		// Start line: 1217
	/* end block 2 */
	// End Line: 1218

void sfxCmdSetVoiceAttr(AadSfxCommand *sfxCmd)

{
  uint uVar1;
  uint vNum;
  uint *puVar2;
  
  vNum = 0;
  puVar2 = (uint *)sfxCmd->ulongParam;
  uVar1 = 1;
  do {
    if ((uVar1 & *puVar2) != 0) break;
    vNum = vNum + 1;
    uVar1 = uVar1 << 1;
  } while (vNum < 0x18);
  SpuSetVoiceVolume(vNum,(int)*(short *)(puVar2 + 2),(int)*(short *)((int)puVar2 + 10));
  SpuSetVoicePitch(vNum,*(word *)(puVar2 + 5));
  SpuSetVoiceStartAddr(vNum,puVar2[7]);
  SpuSetVoiceADSR1ADSR2(vNum,*(ushort *)((int)puVar2 + 0x3a),*(ushort *)(puVar2 + 0xf));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetVoiceKeyOn(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 534, offset 0x80059054
	/* begin block 1 */
		// Start line: 1262
	/* end block 1 */
	// End Line: 1263

	/* begin block 2 */
		// Start line: 1263
	/* end block 2 */
	// End Line: 1264

void sfxCmdSetVoiceKeyOn(AadSfxCommand *sfxCmd)

{
  uRam000004b0 = uRam000004b0 | sfxCmd->ulongParam;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetVoiceKeyOff(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 540, offset 0x80059070
	/* begin block 1 */
		// Start line: 1274
	/* end block 1 */
	// End Line: 1275

	/* begin block 2 */
		// Start line: 1275
	/* end block 2 */
	// End Line: 1276

void sfxCmdSetVoiceKeyOff(AadSfxCommand *sfxCmd)

{
  uRam000004ac = uRam000004ac | sfxCmd->ulongParam;
  uRam000004b0 = uRam000004b0 & ~sfxCmd->ulongParam;
  return;
}





