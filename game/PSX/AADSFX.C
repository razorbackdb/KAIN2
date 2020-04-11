
#include "AADSFX.H"


// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadPlaySfx(unsigned int toneID /*$a0*/, int volume /*$s1*/, int pan /*$s2*/, int pitchOffset /*$s0*/)
 // line 19, offset 0x80057114
	/* begin block 1 */
		// Start line: 20
		// Start offset: 0x80057114
		// Variables:
	// 		unsigned long handle; // $s0
	/* end block 1 */
	// End offset: 0x80057114
	// End Line: 20

	/* begin block 2 */
		// Start line: 38
	/* end block 2 */
	// End Line: 39

/* File: C:\kain2\game\PSX\AADSFX.C */

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
 // line 37, offset 0x80057178
	/* begin block 1 */
		// Start line: 75
	/* end block 1 */
	// End Line: 76

/* File: C:\kain2\game\PSX\AADSFX.C */

ulong aadStopSfx(ulong handle)

{
  aadPutSfxCommand(1,0,0,handle,0);
  return handle;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadStopAllSfx()
 // line 45, offset 0x800571b4
	/* begin block 1 */
		// Start line: 92
	/* end block 1 */
	// End Line: 93

/* File: C:\kain2\game\PSX\AADSFX.C */

void aadStopAllSfx(void)

{
  aadPutSfxCommand(4,0,0,0,0);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxPlaying(unsigned long handle /*$a0*/)
 // line 53, offset 0x800571e4
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800571E4
		// Variables:
	// 		struct AadSynthVoice *voice; // $v1
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8005724C
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

/* File: C:\kain2\game\PSX\AADSFX.C */

int aadIsSfxPlaying(ulong handle)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0x1dc;
  while( true ) {
    if ((((*(char *)(aadMem + iVar3 + 8) == -0x30) &&
         (cVar1 = *(char *)(aadMem + iVar2 + 0x47c), cVar1 != '\0')) && (cVar1 != '\x02')) &&
       (*(ulong *)(aadMem + iVar3 + 4) == handle)) break;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x1c;
    if (0x17 < iVar2) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxPlayingOrRequested(unsigned long handle /*$s0*/)
 // line 72, offset 0x80057254
	/* begin block 1 */
		// Start line: 73
		// Start offset: 0x80057254
		// Variables:
	// 		int commandOut; // $a1
	// 		int i; // $a2
	// 		struct AadSfxCommand *sfxCmd; // $v1
	/* end block 1 */
	// End offset: 0x800572FC
	// End Line: 89

	/* begin block 2 */
		// Start line: 154
	/* end block 2 */
	// End Line: 155

/* File: C:\kain2\game\PSX\AADSFX.C */

int aadIsSfxPlayingOrRequested(ulong handle)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  EnterCriticalSection();
  uVar3 = (uint)*(ushort *)(aadMem + 0x1d6);
  uVar2 = (uint)*(byte *)(aadMem + 0x1d5);
  if (*(ushort *)(aadMem + 0x1d6) != 0) {
    iVar1 = uVar2 * 0xc + 0x54;
    do {
      if ((*(char *)(aadMem + iVar1) == '\0') &&
         (*(ulong *)((char *)(aadMem + iVar1) + 4) == handle)) {
        ExitCriticalSection();
        return 1;
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0xc;
      if (uVar2 == 0x20) {
        iVar1 = 0x54;
        uVar2 = 0;
      }
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  ExitCriticalSection();
  iVar1 = aadIsSfxPlaying(handle);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxTypePlaying(unsigned int toneID /*$a0*/)
 // line 93, offset 0x8005730c
	/* begin block 1 */
		// Start line: 95
		// Start offset: 0x8005730C
		// Variables:
	// 		struct AadSynthVoice *voice; // $v1
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80057378
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

/* File: C:\kain2\game\PSX\AADSFX.C */

int aadIsSfxTypePlaying(uint toneID)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0x1dc;
  while ((((*(char *)(aadMem + iVar3 + 8) != -0x30 ||
           ((uint)*(ushort *)(aadMem + iVar3 + 4) != (toneID & 0xffff))) ||
          (cVar1 = *(char *)(aadMem + iVar2 + 0x47c), cVar1 == '\0')) || (cVar1 == '\x02'))) {
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x1c;
    if (0x17 < iVar2) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ aadIsSfxTypePlayingOrRequested(unsigned int sfxToneID /*$s0*/)
 // line 111, offset 0x80057380
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x80057380
		// Variables:
	// 		int commandOut; // $a1
	// 		int i; // $a2
	// 		struct AadSfxCommand *sfxCmd; // $v1
	/* end block 1 */
	// End offset: 0x80057428
	// End Line: 129

	/* begin block 2 */
		// Start line: 244
	/* end block 2 */
	// End Line: 245

/* File: C:\kain2\game\PSX\AADSFX.C */

int aadIsSfxTypePlayingOrRequested(uint sfxToneID)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  EnterCriticalSection();
  uVar3 = (uint)*(ushort *)(aadMem + 0x1d6);
  uVar2 = (uint)*(byte *)(aadMem + 0x1d5);
  if (*(ushort *)(aadMem + 0x1d6) != 0) {
    iVar1 = uVar2 * 0xc + 0x54;
    do {
      if ((*(char *)(aadMem + iVar1) == '\0') &&
         ((uint)*(ushort *)((char *)(aadMem + iVar1) + 4) == sfxToneID)) {
        ExitCriticalSection();
        return 1;
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0xc;
      if (uVar2 == 0x20) {
        iVar1 = 0x54;
        uVar2 = 0;
      }
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  ExitCriticalSection();
  iVar1 = aadIsSfxTypePlaying(sfxToneID);
  return iVar1;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadSetSfxVolPanPitch(unsigned long handle /*$s0*/, int volume /*$a1*/, int pan /*$a2*/, int pitch /*$a3*/)
 // line 160, offset 0x80057438
	/* begin block 1 */
		// Start line: 314
	/* end block 1 */
	// End Line: 315

/* File: C:\kain2\game\PSX\AADSFX.C */

ulong aadSetSfxVolPanPitch(ulong handle,int volume,int pan,int pitch)

{
  aadPutSfxCommand(3,volume & 0xff,pan & 0xff,handle,(int)(short)pitch);
  return handle;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ createSfxHandle(unsigned int toneID /*$a0*/)
 // line 168, offset 0x8005747c
	/* begin block 1 */
		// Start line: 334
	/* end block 1 */
	// End Line: 335

	/* begin block 2 */
		// Start line: 335
	/* end block 2 */
	// End Line: 336

/* File: C:\kain2\game\PSX\AADSFX.C */

ulong createSfxHandle(uint toneID)

{
  short sVar1;
  int iVar2;
  short sVar3;
  
  iVar2 = aadMem;
  sVar1 = *(short *)(aadMem + 0x1d8);
  sVar3 = sVar1 + 1;
  *(short *)(aadMem + 0x1d8) = sVar3;
  if (sVar3 == 0) {
    *(short *)(iVar2 + 0x1d8) = sVar1 + 2;
  }
  return (uint)*(ushort *)(aadMem + 0x1d8) << 0x10 | toneID & 0xffff;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadPutSfxCommand(int statusByte /*$s0*/, int dataByte0 /*$s2*/, int dataByte1 /*$s3*/, unsigned long ulongParam /*$s4*/, int shortParam /*stack 16*/)
 // line 177, offset 0x800574c4
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x800574C4
		// Variables:
	// 		struct AadSfxCommand *sfxCmd; // $v1
	/* end block 1 */
	// End offset: 0x80057598
	// End Line: 209

	/* begin block 2 */
		// Start line: 352
	/* end block 2 */
	// End Line: 353

	/* begin block 3 */
		// Start line: 354
	/* end block 3 */
	// End Line: 355

/* File: C:\kain2\game\PSX\AADSFX.C */

void aadPutSfxCommand(int statusByte,int dataByte0,int dataByte1,ulong ulongParam,int shortParam)

{
  int iVar1;
  char cVar2;
  undefined *puVar3;
  undefined uVar4;
  
  uVar4 = (undefined)statusByte;
  if ((*(ushort *)(aadMem + 0x1d6) < 0x1e) || (uVar4 = 4, *(ushort *)(aadMem + 0x1d6) < 0x1f)) {
    EnterCriticalSection();
    puVar3 = (undefined *)(aadMem + (uint)*(byte *)(aadMem + 0x1d4) * 0xc + 0x54);
    *puVar3 = uVar4;
    puVar3[1] = (char)dataByte0;
    puVar3[2] = (char)dataByte1;
    iVar1 = aadMem;
    *(ulong *)(puVar3 + 4) = ulongParam;
    *(short *)(puVar3 + 8) = (short)shortParam;
    cVar2 = *(char *)(iVar1 + 0x1d4) + '\x01';
    *(char *)(iVar1 + 0x1d4) = cVar2;
    if (cVar2 == ' ') {
      *(undefined *)(aadMem + 0x1d4) = 0;
    }
    *(short *)(aadMem + 0x1d6) = *(short *)(aadMem + 0x1d6) + 1;
    ExitCriticalSection();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadExecuteSfxCommand(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 229, offset 0x800575b8
	/* begin block 1 */
		// Start line: 463
	/* end block 1 */
	// End Line: 464

/* File: C:\kain2\game\PSX\AADSFX.C */

void aadExecuteSfxCommand(AadSfxCommand *sfxCmd)

{
  if (sfxCmd->statusByte < 9) {
    (*(code *)sfxCmdFunction[sfxCmd->statusByte])();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdPlayTone(struct AadSfxCommand *sfxCmd /*$s4*/)
 // line 248, offset 0x80057608
	/* begin block 1 */
		// Start line: 249
		// Start offset: 0x80057608
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
	// End offset: 0x80057748
	// End Line: 340

	/* begin block 2 */
		// Start line: 501
	/* end block 2 */
	// End Line: 502

/* File: C:\kain2\game\PSX\AADSFX.C */

void sfxCmdPlayTone(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  uchar uVar2;
  ulong waveStartAddr;
  AadSynthVoice *voice;
  int iVar3;
  uint uVar4;
  
  uVar4 = sfxCmd->ulongParam;
  bVar1 = *(byte *)(aadMem + (uVar4 & 0xffff) + 0x808);
  if (bVar1 < 0xfe) {
    iVar3 = aadMem + (uint)bVar1 * 0x14 + 0xc08;
    bVar1 = *(byte *)(aadMem + (uint)*(ushort *)(iVar3 + 2) + 0xa08);
    if (bVar1 < 0xfe) {
      waveStartAddr = aadGetSramBlockAddr((uint)(byte)(&DAT_0000160b)[(uint)bVar1 * 4 + aadMem]);
      bVar1 = *(byte *)(iVar3 + 10);
      voice = aadAllocateVoice((uint)*(byte *)(iVar3 + 4));
      if (voice != (AadSynthVoice *)0x0) {
        aadPlayTone((AadToneAtr *)(iVar3 + 4),waveStartAddr,(AadProgramAtr *)&aadDummySfxProgram,
                    (uint)bVar1,0x7f,(uint)sfxCmd->dataByte[0],(uint)sfxCmd->dataByte[1],
                    (uint)*(byte *)(aadMem + 0x1da),*(int *)(aadMem + 0x1c),voice,
                    (int)sfxCmd->shortParam);
        voice->handle = uVar4;
        voice->voiceID = -0x30;
        uVar2 = *(uchar *)(iVar3 + 4);
        voice->note = bVar1;
        voice->priority = uVar2;
        uVar2 = *(uchar *)(iVar3 + 5);
        voice->volume = '\x7f';
        voice->program = uVar2;
        voice->updateVol = sfxCmd->dataByte[0];
        uVar2 = sfxCmd->dataByte[1];
        *(AadProgramAtr **)&voice->progAtr = &aadDummySfxProgram;
        voice->toneAtr = (AadToneAtr *)(iVar3 + 4);
        voice->pan = uVar2;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdStopTone(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 344, offset 0x80057778
	/* begin block 1 */
		// Start line: 346
		// Start offset: 0x80057778
		// Variables:
	// 		unsigned long handle; // $t0
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned short i; // $a3
	// 		unsigned long vmask; // $v1
	/* end block 1 */
	// End offset: 0x80057804
	// End Line: 366

	/* begin block 2 */
		// Start line: 749
	/* end block 2 */
	// End Line: 750

	/* begin block 3 */
		// Start line: 750
	/* end block 3 */
	// End Line: 751

	/* begin block 4 */
		// Start line: 753
	/* end block 4 */
	// End Line: 754

/* File: C:\kain2\game\PSX\AADSFX.C */

void sfxCmdStopTone(AadSfxCommand *sfxCmd)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  
  uVar3 = 0;
  uVar7 = sfxCmd->ulongParam;
  uVar6 = 0;
  uVar5 = 0;
  do {
    puVar4 = (uint *)(aadMem + uVar5 * 0x1c + 0x1dc);
    if ((((*(char *)(puVar4 + 2) == -0x30) && (puVar4[1] == uVar7)) &&
        (cVar1 = *(char *)(aadMem + uVar5 + 0x47c), cVar1 != '\0')) && (cVar1 != '\x02')) {
      *(undefined *)(puVar4 + 2) = 0xff;
      uVar3 = uVar3 | *puVar4;
    }
    iVar2 = aadMem;
    uVar6 = uVar6 + 1;
    uVar5 = (uint)uVar6;
  } while (uVar6 < 0x18);
  *(uint *)(aadMem + 0x4c4) = *(uint *)(aadMem + 0x4c4) | uVar3;
  *(uint *)(iVar2 + 0x4c8) = *(uint *)(iVar2 + 0x4c8) & ~uVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdStopAllTones(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 372, offset 0x80057830
	/* begin block 1 */
		// Start line: 374
		// Start offset: 0x80057830
		// Variables:
	// 		struct AadSynthVoice *voice; // $a0
	// 		unsigned long vmask; // $v1
	// 		unsigned short i; // $a3
	/* end block 1 */
	// End offset: 0x800578A8
	// End Line: 393

	/* begin block 2 */
		// Start line: 816
	/* end block 2 */
	// End Line: 817

	/* begin block 3 */
		// Start line: 817
	/* end block 3 */
	// End Line: 818

	/* begin block 4 */
		// Start line: 821
	/* end block 4 */
	// End Line: 822

/* File: C:\kain2\game\PSX\AADSFX.C */

void sfxCmdStopAllTones(AadSfxCommand *sfxCmd)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  ushort uVar6;
  
  uVar3 = 0;
  uVar6 = 0;
  uVar5 = 0;
  do {
    puVar4 = (uint *)(aadMem + uVar5 * 0x1c + 0x1dc);
    if (((*(char *)(puVar4 + 2) == -0x30) &&
        (cVar1 = *(char *)(aadMem + uVar5 + 0x47c), cVar1 != '\0')) && (cVar1 != '\x02')) {
      *(undefined *)(puVar4 + 2) = 0xff;
      uVar3 = uVar3 | *puVar4;
    }
    iVar2 = aadMem;
    uVar6 = uVar6 + 1;
    uVar5 = (uint)uVar6;
  } while (uVar6 < 0x18);
  *(uint *)(aadMem + 0x4c4) = *(uint *)(aadMem + 0x4c4) | uVar3;
  *(uint *)(iVar2 + 0x4c8) = *(uint *)(iVar2 + 0x4c8) & ~uVar3;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetToneVolumeAndPan(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 399, offset 0x800578d4
	/* begin block 1 */
		// Start line: 400
		// Start offset: 0x800578D4
		// Variables:
	// 		unsigned long handle; // $a3
	// 		struct AadSynthVoice *voice; // $t0
	// 		unsigned short i; // $t1
	// 		struct AadVolume newVoiceVol; // stack offset -16

		/* begin block 1.1 */
			// Start line: 418
			// Start offset: 0x80057988
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x80057988
		// End Line: 418

		/* begin block 1.2 */
			// Start line: 419
			// Start offset: 0x800579F0
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.2 */
		// End offset: 0x800579F0
		// End Line: 419

		/* begin block 1.3 */
			// Start line: 420
			// Start offset: 0x80057A6C
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.3 */
		// End offset: 0x80057A6C
		// End Line: 420

		/* begin block 1.4 */
			// Start line: 421
			// Start offset: 0x80057AD4
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.4 */
		// End offset: 0x80057AD4
		// End Line: 421

		/* begin block 1.5 */
			// Start line: 421
			// Start offset: 0x80057AD4
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.5 */
		// End offset: 0x80057AD4
		// End Line: 421

		/* begin block 1.6 */
			// Start line: 421
			// Start offset: 0x80057AD4
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.6 */
		// End offset: 0x80057AD4
		// End Line: 421

		/* begin block 1.7 */
			// Start line: 421
			// Start offset: 0x80057AD4
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.7 */
		// End offset: 0x80057AD4
		// End Line: 421
	/* end block 1 */
	// End offset: 0x80057C18
	// End Line: 436

	/* begin block 2 */
		// Start line: 881
	/* end block 2 */
	// End Line: 882

/* File: C:\kain2\game\PSX\AADSFX.C */

void sfxCmdSetToneVolumeAndPan(AadSfxCommand *sfxCmd)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short local_10;
  short local_e;
  
  uVar5 = 0;
  uVar3 = 0;
  while ((((iVar4 = aadMem + uVar3 * 0x1c + 0x1dc, *(char *)(iVar4 + 8) != -0x30 ||
           (*(ulong *)(iVar4 + 4) != sfxCmd->ulongParam)) ||
          (cVar1 = *(char *)(aadMem + uVar3 + 0x47c), cVar1 == '\0')) || (cVar1 == '\x02'))) {
    uVar5 = uVar5 + 1;
    uVar3 = (uint)uVar5;
    if (0x17 < uVar5) {
      return;
    }
  }
  local_10 = (ushort)*(byte *)(iVar4 + 0xe) * (ushort)*(byte *)(iVar4 + 0xe);
  local_e = (ushort)*(byte *)(iVar4 + 0xe) * (ushort)*(byte *)(iVar4 + 0xe);
  if ((*(uint *)(aadMem + 0x24) & 1) == 0) {
    bVar2 = sfxCmd->dataByte[1];
    if (bVar2 < 0x41) {
      if (bVar2 < 0x3f) {
        local_e = (short)((int)((int)local_10 * (uint)sfxCmd->dataByte[1] *
                               (uint)sfxCmd->dataByte[1]) >> 0xc);
      }
    }
    else {
      local_10 = (short)((int)local_e * (0x7f - (uint)bVar2) * (0x7f - (uint)bVar2) >> 0xc);
    }
  }
  uVar3 = (uint)*(byte *)(*(int *)(iVar4 + 0x14) + 2);
  iVar6 = uVar3 * uVar3;
  local_10 = (short)((uint)(local_10 * iVar6) >> 0xe);
  local_e = (short)((uint)(local_e * iVar6) >> 0xe);
  if ((*(uint *)(aadMem + 0x24) & 1) == 0) {
    bVar2 = *(byte *)(*(int *)(iVar4 + 0x14) + 3);
    if (bVar2 < 0x41) {
      if (bVar2 < 0x3f) {
        uVar3 = (uint)*(byte *)(*(int *)(iVar4 + 0x14) + 3);
        local_e = (short)((int)((int)local_10 * uVar3 * uVar3) >> 0xc);
      }
    }
    else {
      local_10 = (short)((int)local_e * (0x7f - (uint)bVar2) * (0x7f - (uint)bVar2) >> 0xc);
    }
  }
  iVar6 = (uint)sfxCmd->dataByte[0] * (uint)sfxCmd->dataByte[0];
  *(uchar *)(iVar4 + 0xf) = sfxCmd->dataByte[0];
  uVar3 = (uint)*(byte *)(*(int *)(iVar4 + 0x18) + 4);
  iVar4 = uVar3 * uVar3;
  iVar7 = (uint)*(byte *)(aadMem + 0x1da) * (uint)*(byte *)(aadMem + 0x1da);
  iVar8 = *(int *)(aadMem + 0x1c) * *(int *)(aadMem + 0x1c);
  SpuSetVoiceVolume((uint)uVar5,
                    (short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_10 * iVar6) >>
                                                                        0xe) * iVar4) >> 0xe) *
                                                 iVar7) >> 0xe) * iVar8) >> 0xe),
                    (short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_e * iVar6) >>
                                                                        0xe) * iVar4) >> 0xe) *
                                                 iVar7) >> 0xe) * iVar8) >> 0xe));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetToneVolPanPitch(struct AadSfxCommand *sfxCmd /*$s2*/)
 // line 439, offset 0x80057c28
	/* begin block 1 */
		// Start line: 440
		// Start offset: 0x80057C28
		// Variables:
	// 		unsigned long handle; // $a2
	// 		struct AadSynthVoice *voice; // $s0
	// 		unsigned short i; // $s1
	// 		struct AadVolume newVoiceVol; // stack offset -24
	// 		unsigned short newPitch; // $a1
	// 		unsigned short finePitch; // $a1
	// 		unsigned short pitchIndex; // $a0

		/* begin block 1.1 */
			// Start line: 459
			// Start offset: 0x80057CEC
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.1 */
		// End offset: 0x80057CEC
		// End Line: 459

		/* begin block 1.2 */
			// Start line: 460
			// Start offset: 0x80057D54
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.2 */
		// End offset: 0x80057D54
		// End Line: 460

		/* begin block 1.3 */
			// Start line: 461
			// Start offset: 0x80057DD0
			// Variables:
		// 		unsigned long tmp; // $v1
		/* end block 1.3 */
		// End offset: 0x80057DD0
		// End Line: 461

		/* begin block 1.4 */
			// Start line: 462
			// Start offset: 0x80057E38
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.4 */
		// End offset: 0x80057E38
		// End Line: 462

		/* begin block 1.5 */
			// Start line: 462
			// Start offset: 0x80057E38
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.5 */
		// End offset: 0x80057E38
		// End Line: 462

		/* begin block 1.6 */
			// Start line: 462
			// Start offset: 0x80057E38
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v0
		/* end block 1.6 */
		// End offset: 0x80057E38
		// End Line: 462

		/* begin block 1.7 */
			// Start line: 462
			// Start offset: 0x80057E38
			// Variables:
		// 		unsigned long masterVolumeSquared; // $v1
		/* end block 1.7 */
		// End offset: 0x80057E38
		// End Line: 462
	/* end block 1 */
	// End offset: 0x8005806C
	// End Line: 494

	/* begin block 2 */
		// Start line: 999
	/* end block 2 */
	// End Line: 1000

/* File: C:\kain2\game\PSX\AADSFX.C */

void sfxCmdSetToneVolPanPitch(AadSfxCommand *sfxCmd)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short local_18;
  short local_16;
  
  uVar6 = 0;
  uVar3 = 0;
  while ((((iVar5 = aadMem + uVar3 * 0x1c + 0x1dc, *(char *)(iVar5 + 8) != -0x30 ||
           (*(ulong *)(iVar5 + 4) != sfxCmd->ulongParam)) ||
          (cVar1 = *(char *)(aadMem + uVar3 + 0x47c), cVar1 == '\0')) || (cVar1 == '\x02'))) {
    uVar6 = uVar6 + 1;
    uVar3 = (uint)uVar6;
    if (0x17 < uVar6) {
      return;
    }
  }
  local_18 = (ushort)*(byte *)(iVar5 + 0xe) * (ushort)*(byte *)(iVar5 + 0xe);
  local_16 = (ushort)*(byte *)(iVar5 + 0xe) * (ushort)*(byte *)(iVar5 + 0xe);
  if ((*(uint *)(aadMem + 0x24) & 1) == 0) {
    bVar2 = sfxCmd->dataByte[1];
    if (bVar2 < 0x41) {
      if (bVar2 < 0x3f) {
        local_16 = (short)((int)((int)local_18 * (uint)sfxCmd->dataByte[1] *
                                (uint)sfxCmd->dataByte[1]) >> 0xc);
      }
    }
    else {
      local_18 = (short)((int)local_16 * (0x7f - (uint)bVar2) * (0x7f - (uint)bVar2) >> 0xc);
    }
  }
  uVar3 = (uint)*(byte *)(*(int *)(iVar5 + 0x14) + 2);
  iVar7 = uVar3 * uVar3;
  local_18 = (short)((uint)(local_18 * iVar7) >> 0xe);
  local_16 = (short)((uint)(local_16 * iVar7) >> 0xe);
  if ((*(uint *)(aadMem + 0x24) & 1) == 0) {
    bVar2 = *(byte *)(*(int *)(iVar5 + 0x14) + 3);
    if (bVar2 < 0x41) {
      if (bVar2 < 0x3f) {
        uVar3 = (uint)*(byte *)(*(int *)(iVar5 + 0x14) + 3);
        local_16 = (short)((int)((int)local_18 * uVar3 * uVar3) >> 0xc);
      }
    }
    else {
      local_18 = (short)((int)local_16 * (0x7f - (uint)bVar2) * (0x7f - (uint)bVar2) >> 0xc);
    }
  }
  iVar7 = (uint)sfxCmd->dataByte[0] * (uint)sfxCmd->dataByte[0];
  *(uchar *)(iVar5 + 0xf) = sfxCmd->dataByte[0];
  uVar3 = (uint)*(byte *)(*(int *)(iVar5 + 0x18) + 4);
  iVar8 = uVar3 * uVar3;
  iVar9 = (uint)*(byte *)(aadMem + 0x1da) * (uint)*(byte *)(aadMem + 0x1da);
  iVar10 = *(int *)(aadMem + 0x1c) * *(int *)(aadMem + 0x1c);
  SpuSetVoiceVolume((uint)uVar6,
                    (short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_18 * iVar7) >>
                                                                        0xe) * iVar8) >> 0xe) *
                                                 iVar9) >> 0xe) * iVar10) >> 0xe),
                    (short)((uint)((short)((uint)((short)((uint)((short)((uint)(local_16 * iVar7) >>
                                                                        0xe) * iVar8) >> 0xe) *
                                                 iVar9) >> 0xe) * iVar10) >> 0xe));
  iVar7 = *(int *)(iVar5 + 0x14);
  uVar3 = (uint)*(byte *)(iVar5 + 10) - ((uint)*(byte *)(iVar7 + 4) - 0x3c);
  if ((*(byte *)(iVar7 + 5) & 0x80) == 0) {
    uVar3 = uVar3 & 0xffff;
    sVar4 = aadPitchTable[uVar3] +
            (ushort)(aadStepsPerCent[uVar3] * 100 * (uint)*(byte *)(iVar7 + 5) >> 0x17);
  }
  else {
    uVar3 = uVar3 & 0xffff;
    sVar4 = aadPitchTable[uVar3] -
            (ushort)(aadStepsPerCent[uVar3] * 100 * (0x100 - (uint)*(byte *)(iVar7 + 5) & 0xffff) >>
                    0x17);
  }
  SpuSetVoicePitch((uint)uVar6,sVar4 + sfxCmd->shortParam);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdLockVoice(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 498, offset 0x80058084
	/* begin block 1 */
		// Start line: 499
		// Start offset: 0x80058084
		// Variables:
	// 		void (*callbackProc)(); // $s0
	// 		struct AadSynthVoice *voice; // $v1
	/* end block 1 */
	// End offset: 0x800580C0
	// End Line: 513

	/* begin block 2 */
		// Start line: 1183
	/* end block 2 */
	// End Line: 1184

/* File: C:\kain2\game\PSX\AADSFX.C */

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
 // line 516, offset 0x800580d0
	/* begin block 1 */
		// Start line: 517
		// Start offset: 0x800580D0
		// Variables:
	// 		unsigned long v; // $s0
	// 		unsigned long vmask; // $v1
	// 		struct SpuVoiceAttr *voiceAttr; // $s1
	/* end block 1 */
	// End offset: 0x80058110
	// End Line: 528

	/* begin block 2 */
		// Start line: 1220
	/* end block 2 */
	// End Line: 1221

/* File: C:\kain2\game\PSX\AADSFX.C */

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
  SpuSetVoiceVolume(vNum,*(short *)(puVar2 + 2),*(short *)((int)puVar2 + 10));
  SpuSetVoicePitch(vNum,*(ushort *)(puVar2 + 5));
  SpuSetVoiceStartAddr(vNum,puVar2[7]);
  SpuSetVoiceADSR1ADSR2(vNum,*(ushort *)((int)puVar2 + 0x3a),*(ushort *)(puVar2 + 0xf));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetVoiceKeyOn(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 535, offset 0x8005815c
	/* begin block 1 */
		// Start line: 1265
	/* end block 1 */
	// End Line: 1266

	/* begin block 2 */
		// Start line: 1266
	/* end block 2 */
	// End Line: 1267

/* File: C:\kain2\game\PSX\AADSFX.C */

void sfxCmdSetVoiceKeyOn(AadSfxCommand *sfxCmd)

{
  *(uint *)(aadMem + 0x4c8) = *(uint *)(aadMem + 0x4c8) | sfxCmd->ulongParam;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ sfxCmdSetVoiceKeyOff(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 541, offset 0x80058178
	/* begin block 1 */
		// Start line: 1277
	/* end block 1 */
	// End Line: 1278

	/* begin block 2 */
		// Start line: 1278
	/* end block 2 */
	// End Line: 1279

/* File: C:\kain2\game\PSX\AADSFX.C */

void sfxCmdSetVoiceKeyOff(AadSfxCommand *sfxCmd)

{
  int iVar1;
  
  iVar1 = aadMem;
  *(uint *)(aadMem + 0x4c4) = *(uint *)(aadMem + 0x4c4) | sfxCmd->ulongParam;
  *(uint *)(iVar1 + 0x4c8) = *(uint *)(iVar1 + 0x4c8) & ~sfxCmd->ulongParam;
  return;
}





