#include "THISDUST.H"
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

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

int aadIsSfxPlaying(ulong handle)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x1dc;
  while ((((*(char *)(iVar2 + 8) != -0x30 || (*(char *)(iVar1 + 0x47c) == '\0')) ||
          (*(char *)(iVar1 + 0x47c) == '\x02')) || (*(ulong *)(iVar2 + 4) != handle))) {
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

int aadIsSfxPlayingOrRequested(ulong handle)

{
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
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

int aadIsSfxTypePlaying(uint toneID)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x1dc;
  while ((((*(char *)(iVar2 + 8) != -0x30 || ((uint)*(ushort *)(iVar2 + 4) != (toneID & 0xffff))) ||
          (*(char *)(iVar1 + 0x47c) == '\0')) || (*(char *)(iVar1 + 0x47c) == '\x02'))) {
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

int aadIsSfxTypePlayingOrRequested(uint sfxToneID)

{
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ aadSetSfxVolPanPitch(unsigned long handle /*$s0*/, int volume /*$a1*/, int pan /*$a2*/, int pitch /*$a3*/)
 // line 160, offset 0x80057438
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
 // line 168, offset 0x8005747c
	/* begin block 1 */
		// Start line: 334
	/* end block 1 */
	// End Line: 335

	/* begin block 2 */
		// Start line: 335
	/* end block 2 */
	// End Line: 336

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong createSfxHandle(uint toneID)

{
  ushort uVar1;
  
                    /* WARNING: Read-only address (ram,0x000001d8) is written */
  uVar1 = _UNK_000001d8 + 1;
  if ((ushort)(_UNK_000001d8 + 1) == 0) {
                    /* WARNING: Read-only address (ram,0x000001d8) is written */
    uVar1 = _UNK_000001d8 + 2;
  }
  _UNK_000001d8 = uVar1;
  return (uint)_UNK_000001d8 << 0x10 | toneID & 0xffff;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aadPutSfxCommand(int statusByte,int dataByte0,int dataByte1,ulong ulongParam,int shortParam)

{
  if ((0x1d < _UNK_000001d6) && (0x1e < _UNK_000001d6)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  EnterCriticalSection();
}



// decompiled code
// original method signature: 
// void /*$ra*/ aadExecuteSfxCommand(struct AadSfxCommand *sfxCmd /*$a0*/)
 // line 229, offset 0x800575b8
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

void sfxCmdPlayTone(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  uchar uVar2;
  int iVar3;
  ulong waveStartAddr;
  AadSynthVoice *voice;
  uint uVar4;
  
  uVar4 = sfxCmd->ulongParam;
  bVar1 = *(byte *)((uVar4 & 0xffff) + 0x808);
  if (bVar1 < 0xfe) {
    iVar3 = (uint)bVar1 * 0x14;
    bVar1 = *(byte *)((uint)*(ushort *)(iVar3 + 0xc0a) + 0xa08);
    if (bVar1 < 0xfe) {
      waveStartAddr = aadGetSramBlockAddr((uint)(byte)(&DAT_0000160b)[(uint)bVar1 * 4]);
      bVar1 = *(byte *)(iVar3 + 0xc12);
      voice = aadAllocateVoice((uint)*(byte *)(iVar3 + 0xc0c));
      if (voice != (AadSynthVoice *)0x0) {
        aadPlayTone((AadToneAtr *)(iVar3 + 0xc0c),waveStartAddr,&aadDummySfxProgram,(uint)bVar1,0x7f
                    ,(uint)sfxCmd->dataByte[0],(uint)sfxCmd->dataByte[1],(uint)UNK_000001da,
                    DAT_0000001c,voice,(int)sfxCmd->shortParam);
        voice->handle = uVar4;
        voice->voiceID = -0x30;
        uVar2 = *(uchar *)(iVar3 + 0xc0c);
        voice->note = bVar1;
        voice->priority = uVar2;
        uVar2 = *(uchar *)(iVar3 + 0xc0d);
        voice->volume = '\x7f';
        voice->program = uVar2;
        voice->updateVol = sfxCmd->dataByte[0];
        uVar2 = sfxCmd->dataByte[1];
        voice->progAtr = &aadDummySfxProgram;
        voice->toneAtr = (AadToneAtr *)(iVar3 + 0xc0c);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    if ((((*(char *)(iVar1 + 0x1e4) == -0x30) && (*(ulong *)(iVar1 + 0x1e0) == uVar5)) &&
        (*(char *)(uVar3 + 0x47c) != '\0')) && (*(char *)(uVar3 + 0x47c) != '\x02')) {
      *(undefined *)(iVar1 + 0x1e4) = 0xff;
      uVar2 = uVar2 | *(uint *)(iVar1 + 0x1dc);
    }
    uVar4 = uVar4 + 1;
    uVar3 = (uint)uVar4;
  } while (uVar4 < 0x18);
  _DAT_000004c4 = _DAT_000004c4 | uVar2;
  _DAT_000004c8 = _DAT_000004c8 & ~uVar2;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    if (((*(char *)(iVar1 + 0x1e4) == -0x30) && (*(char *)(uVar3 + 0x47c) != '\0')) &&
       (*(char *)(uVar3 + 0x47c) != '\x02')) {
      *(undefined *)(iVar1 + 0x1e4) = 0xff;
      uVar2 = uVar2 | *(uint *)(iVar1 + 0x1dc);
    }
    uVar4 = uVar4 + 1;
    uVar3 = (uint)uVar4;
  } while (uVar4 < 0x18);
  _DAT_000004c4 = _DAT_000004c4 | uVar2;
  _DAT_000004c8 = _DAT_000004c8 & ~uVar2;
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

void sfxCmdSetToneVolumeAndPan(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  short local_10;
  short local_e;
  
  uVar4 = 0;
  uVar3 = 0;
  while( true ) {
    iVar2 = uVar3 * 0x1c;
    if ((((*(char *)(iVar2 + 0x1e4) == -0x30) && (*(ulong *)(iVar2 + 0x1e0) == sfxCmd->ulongParam))
        && (*(char *)(uVar3 + 0x47c) != '\0')) && (*(char *)(uVar3 + 0x47c) != '\x02')) break;
    uVar4 = uVar4 + 1;
    uVar3 = (uint)uVar4;
    if (0x17 < uVar4) {
      return;
    }
  }
  local_10 = (ushort)*(byte *)(iVar2 + 0x1ea) * (ushort)*(byte *)(iVar2 + 0x1ea);
  local_e = (ushort)*(byte *)(iVar2 + 0x1ea) * (ushort)*(byte *)(iVar2 + 0x1ea);
  if (((uint)the_mcmenu_table.data_size & 1) == 0) {
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
  uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1f0) + 2);
  iVar5 = uVar3 * uVar3;
  local_10 = (short)((uint)(local_10 * iVar5) >> 0xe);
  local_e = (short)((uint)(local_e * iVar5) >> 0xe);
  if (((uint)the_mcmenu_table.data_size & 1) == 0) {
    bVar1 = *(byte *)(*(int *)(iVar2 + 0x1f0) + 3);
    if (bVar1 < 0x41) {
      if (bVar1 < 0x3f) {
        uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1f0) + 3);
        local_e = (short)((int)((int)local_10 * uVar3 * uVar3) >> 0xc);
      }
    }
    else {
      local_10 = (short)((int)local_e * (0x7f - (uint)bVar1) * (0x7f - (uint)bVar1) >> 0xc);
    }
  }
  iVar5 = (uint)sfxCmd->dataByte[0] * (uint)sfxCmd->dataByte[0];
  *(uchar *)(iVar2 + 0x1eb) = sfxCmd->dataByte[0];
  uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 500) + 4);
  iVar2 = uVar3 * uVar3;
  iVar6 = (uint)UNK_000001da * (uint)UNK_000001da;
                    /* WARNING: Subroutine does not return */
  SpuSetVoiceVolume((uint)uVar4,
                    (int)(short)((uint)((int)(short)((uint)((short)((uint)((short)((uint)(local_10 *
                                                                                         iVar5) >>
                                                                                  0xe) * iVar2) >>
                                                                   0xe) * iVar6) >> 0xe) *
                                       DAT_0000001c * DAT_0000001c) >> 0xe),
                    (int)(short)((uint)((int)(short)((uint)((short)((uint)((short)((uint)(local_e *
                                                                                         iVar5) >>
                                                                                  0xe) * iVar2) >>
                                                                   0xe) * iVar6) >> 0xe) *
                                       DAT_0000001c * DAT_0000001c) >> 0xe));
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

void sfxCmdSetToneVolPanPitch(AadSfxCommand *sfxCmd)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  short local_18;
  short local_16;
  
  uVar4 = 0;
  uVar3 = 0;
  while( true ) {
    iVar2 = uVar3 * 0x1c;
    if ((((*(char *)(iVar2 + 0x1e4) == -0x30) && (*(ulong *)(iVar2 + 0x1e0) == sfxCmd->ulongParam))
        && (*(char *)(uVar3 + 0x47c) != '\0')) && (*(char *)(uVar3 + 0x47c) != '\x02')) break;
    uVar4 = uVar4 + 1;
    uVar3 = (uint)uVar4;
    if (0x17 < uVar4) {
      return;
    }
  }
  local_18 = (ushort)*(byte *)(iVar2 + 0x1ea) * (ushort)*(byte *)(iVar2 + 0x1ea);
  local_16 = (ushort)*(byte *)(iVar2 + 0x1ea) * (ushort)*(byte *)(iVar2 + 0x1ea);
  if (((uint)the_mcmenu_table.data_size & 1) == 0) {
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
  uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1f0) + 2);
  iVar5 = uVar3 * uVar3;
  local_18 = (short)((uint)(local_18 * iVar5) >> 0xe);
  local_16 = (short)((uint)(local_16 * iVar5) >> 0xe);
  if (((uint)the_mcmenu_table.data_size & 1) == 0) {
    bVar1 = *(byte *)(*(int *)(iVar2 + 0x1f0) + 3);
    if (bVar1 < 0x41) {
      if (bVar1 < 0x3f) {
        uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 0x1f0) + 3);
        local_16 = (short)((int)((int)local_18 * uVar3 * uVar3) >> 0xc);
      }
    }
    else {
      local_18 = (short)((int)local_16 * (0x7f - (uint)bVar1) * (0x7f - (uint)bVar1) >> 0xc);
    }
  }
  iVar5 = (uint)sfxCmd->dataByte[0] * (uint)sfxCmd->dataByte[0];
  *(uchar *)(iVar2 + 0x1eb) = sfxCmd->dataByte[0];
  uVar3 = (uint)*(byte *)(*(int *)(iVar2 + 500) + 4);
  iVar2 = uVar3 * uVar3;
  iVar6 = (uint)UNK_000001da * (uint)UNK_000001da;
                    /* WARNING: Subroutine does not return */
  SpuSetVoiceVolume((uint)uVar4,
                    (int)(short)((uint)((int)(short)((uint)((short)((uint)((short)((uint)(local_18 *
                                                                                         iVar5) >>
                                                                                  0xe) * iVar2) >>
                                                                   0xe) * iVar6) >> 0xe) *
                                       DAT_0000001c * DAT_0000001c) >> 0xe),
                    (int)(short)((uint)((int)(short)((uint)((short)((uint)((short)((uint)(local_16 *
                                                                                         iVar5) >>
                                                                                  0xe) * iVar2) >>
                                                                   0xe) * iVar6) >> 0xe) *
                                       DAT_0000001c * DAT_0000001c) >> 0xe));
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

void sfxCmdSetVoiceAttr(AadSfxCommand *sfxCmd)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = 0;
  puVar3 = (uint *)sfxCmd->ulongParam;
  uVar1 = 1;
  do {
    if ((uVar1 & *puVar3) != 0) break;
    uVar2 = uVar2 + 1;
    uVar1 = uVar1 << 1;
  } while (uVar2 < 0x18);
                    /* WARNING: Subroutine does not return */
  SpuSetVoiceVolume(uVar2,(int)*(short *)(puVar3 + 2),(int)*(short *)((int)puVar3 + 10));
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sfxCmdSetVoiceKeyOn(AadSfxCommand *sfxCmd)

{
  _DAT_000004c8 = _DAT_000004c8 | sfxCmd->ulongParam;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sfxCmdSetVoiceKeyOff(AadSfxCommand *sfxCmd)

{
  _DAT_000004c4 = _DAT_000004c4 | sfxCmd->ulongParam;
  _DAT_000004c8 = _DAT_000004c8 & ~sfxCmd->ulongParam;
  return;
}





