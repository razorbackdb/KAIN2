#include "THISDUST.H"
#include "VOICEXA.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Init()
 // line 50, offset 0x800b0f84
	/* begin block 1 */
		// Start line: 51
		// Start offset: 0x800B0F84
		// Variables:
	// 		int i; // $s1
	// 		struct CdlFILE fp; // stack offset -80
	// 		struct XAVoiceTracker *vt; // $a0
	// 		char fileName[32]; // stack offset -56
	/* end block 1 */
	// End offset: 0x800B1038
	// End Line: 91

	/* begin block 2 */
		// Start line: 100
	/* end block 2 */
	// End Line: 101

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VOICEXA_Init(void)

{
  undefined4 *puVar1;
  int iVar2;
  XAVoiceTracker *pXVar3;
  int iVar4;
  undefined4 auStack80 [6];
  char acStack56 [32];
  
  pXVar3 = &voiceTracker;
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    iVar4 = 0;
    voiceTracker.unused2._0_1_ = 0;
    voiceTracker.unused2._1_1_ = 0;
    voiceTracker.voiceCmdOut = '\0';
    voiceTracker.voiceCmdsQueued = '\0';
    voiceTracker.unused1 = '\0';
    voiceTracker.reqOut = '\0';
    voiceTracker.reqsQueued = '\0';
    voiceTracker.voiceCmdIn = '\0';
    voiceTracker.voiceStatus = '\0';
    voiceTracker.cdStatus = '\0';
    voiceTracker.fileNum._0_1_ = 0;
    do {
      sprintf(acStack56,"\\VOICE\\VOICE%02d.XA;1");
      puVar1 = CdSearchFile(auStack80,acStack56);
      if (puVar1 == (undefined4 *)0x0) {
        pXVar3->xaFileInfo[1].startPos = 0;
      }
      else {
        iVar2 = CdPosToInt((byte *)auStack80);
        pXVar3->xaFileInfo[1].startPos = iVar2;
      }
      iVar4 = iVar4 + 1;
      pXVar3 = (XAVoiceTracker *)&pXVar3->endSector;
    } while (iVar4 < 0x1e);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ putCdCommand(struct XAVoiceTracker *vt /*$a0*/, unsigned char cdCommand /*$a1*/, int numParams /*$a2*/, unsigned char *params /*$a3*/)
 // line 94, offset 0x800b1054
	/* begin block 1 */
		// Start line: 95
		// Start offset: 0x800B1054
		// Variables:
	// 		int i; // $t0
	/* end block 1 */
	// End offset: 0x800B10D0
	// End Line: 108

	/* begin block 2 */
		// Start line: 217
	/* end block 2 */
	// End Line: 218

	/* begin block 3 */
		// Start line: 220
	/* end block 3 */
	// End Line: 221

void putCdCommand(XAVoiceTracker *vt,uchar cdCommand,int numParams,uchar *params)

{
  uchar uVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  vt->cdCmdQueue[vt->reqOut].cdCmdParam[3] = cdCommand;
  puVar2 = params;
  if (0 < numParams) {
    do {
      iVar4 = iVar3 + 1;
      *(uchar *)((int)&vt->cdCmdQueue[(uint)vt->reqOut + 1].flags + iVar3) = *puVar2;
      puVar2 = params + iVar4;
      iVar3 = iVar4;
    } while (iVar4 < numParams);
  }
  if (vt->voiceCmdIn < 7) {
    vt->voiceCmdIn = vt->voiceCmdIn + 1;
    uVar1 = vt->reqOut + '\x01';
    vt->reqOut = uVar1;
    if (uVar1 == '\b') {
      vt->reqOut = '\0';
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_CdSyncCallback(unsigned char status /*$a0*/, unsigned char *result /*$a1*/)
 // line 111, offset 0x800b10d8
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x800B10D8
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a1
	/* end block 1 */
	// End offset: 0x800B1138
	// End Line: 133

	/* begin block 2 */
		// Start line: 255
	/* end block 2 */
	// End Line: 256

void VOICEXA_CdSyncCallback(uchar status,uchar *result)

{
  if (status == '\x02') {
    voiceTracker.unused2._1_1_ = 0;
    voiceTracker.reqsQueued = voiceTracker.reqsQueued + '\x01';
    if (voiceTracker.reqsQueued == '\b') {
      voiceTracker.reqsQueued = '\0';
    }
    voiceTracker.voiceCmdIn = voiceTracker.voiceCmdIn + -1;
    CdSyncCallback(voiceTracker.cdResult._0_4_);
  }
  else {
    voiceTracker.unused2._1_1_ = 2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processCdCommands(struct XAVoiceTracker *vt /*$s1*/)
 // line 137, offset 0x800b1148
	/* begin block 1 */
		// Start line: 138
		// Start offset: 0x800B1148
		// Variables:
	// 		struct CdCommand *cmd; // $s0
	/* end block 1 */
	// End offset: 0x800B11DC
	// End Line: 159

	/* begin block 2 */
		// Start line: 311
	/* end block 2 */
	// End Line: 312

void processCdCommands(XAVoiceTracker *vt)

{
  char cVar1;
  undefined4 uVar2;
  byte bVar3;
  uchar *puVar4;
  
  cVar1 = *(char *)((int)&vt->unused2 + 1);
  if (cVar1 == '\x02') {
    bVar3 = vt->reqsQueued;
    *(undefined *)((int)&vt->unused2 + 1) = 1;
    puVar4 = vt->cdCmdQueue[bVar3].cdCmdParam;
    bVar3 = puVar4[3];
  }
  else {
    if (vt->voiceCmdIn == '\0') {
      return;
    }
    if (cVar1 == '\x01') {
      return;
    }
    bVar3 = vt->reqsQueued;
    *(undefined *)((int)&vt->unused2 + 1) = 1;
    puVar4 = vt->cdCmdQueue[bVar3].cdCmdParam;
    uVar2 = CdSyncCallback(VOICEXA_CdSyncCallback);
    *(undefined4 *)vt->cdResult = uVar2;
    bVar3 = puVar4[3];
  }
  CdControl(bVar3,puVar4 + 4,vt->cdResult + 4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ putVoiceCommand(struct XAVoiceTracker *vt /*$a0*/, unsigned char voiceCmd /*$a1*/, unsigned char nextVoiceStatus /*$a2*/, int voiceCmdParam /*$a3*/)
 // line 182, offset 0x800b11f0
	/* begin block 1 */
		// Start line: 406
	/* end block 1 */
	// End Line: 407

	/* begin block 2 */
		// Start line: 407
	/* end block 2 */
	// End Line: 408

void putVoiceCommand(XAVoiceTracker *vt,uchar voiceCmd,uchar nextVoiceStatus,int voiceCmdParam)

{
  uchar uVar1;
  
  vt->voiceCmdQueue[(uint)vt->voiceStatus + 1].voiceCmd = voiceCmd;
  vt->voiceCmdQueue[(uint)vt->voiceStatus + 1].nextVoiceStatus = nextVoiceStatus;
  vt->voiceCmdQueue[(uint)vt->voiceStatus + 1].voiceCmdParam = (ushort)voiceCmdParam;
  if (*(byte *)&vt->fileNum < 0xf) {
    *(byte *)&vt->fileNum = *(byte *)&vt->fileNum + 1;
    uVar1 = vt->voiceStatus + '\x01';
    vt->voiceStatus = uVar1;
    if (uVar1 == '\x10') {
      vt->voiceStatus = '\0';
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processVoiceCommands(struct XAVoiceTracker *vt /*$s1*/)
 // line 199, offset 0x800b126c
	/* begin block 1 */
		// Start line: 200
		// Start offset: 0x800B126C
		// Variables:
	// 		struct VoiceCommand *cmd; // $s0
	/* end block 1 */
	// End offset: 0x800B130C
	// End Line: 217

	/* begin block 2 */
		// Start line: 441
	/* end block 2 */
	// End Line: 442

void processVoiceCommands(XAVoiceTracker *vt)

{
  uint uVar1;
  VoiceCommand *pVVar2;
  
  if (*(char *)&vt->fileNum != '\0') {
    *(char *)&vt->fileNum = *(char *)&vt->fileNum + -1;
    uVar1 = (uint)vt->cdStatus + 1;
    pVVar2 = vt->voiceCmdQueue + (uint)vt->cdStatus + 1;
    vt->cdStatus = (uchar)uVar1;
    if ((uVar1 & 0xff) == 0x10) {
      vt->cdStatus = '\0';
    }
    if (pVVar2->voiceCmd < 5) {
      (*(code *)(&voiceCmdTbl)[pVVar2->voiceCmd])(vt,(int)(short)pVVar2->voiceCmdParam);
      *(uchar *)&vt->unused2 = pVVar2->nextVoiceStatus;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdPlay(struct XAVoiceTracker *vt /*$s2*/, short voiceIndex /*$s3*/)
 // line 222, offset 0x800b1320
	/* begin block 1 */
		// Start line: 223
		// Start offset: 0x800B1320
		// Variables:
	// 		struct CdlFILTER filter; // stack offset -88
	// 		struct CdlLOC pos; // stack offset -80
	// 		unsigned char mode; // stack offset -32
	// 		struct SpuCommonAttr spuattr; // stack offset -72
	// 		struct XAVoiceListEntry *voice; // $s1
	// 		struct XAFileInfo *file; // $s0
	/* end block 1 */
	// End offset: 0x800B1474
	// End Line: 295

	/* begin block 2 */
		// Start line: 491
	/* end block 2 */
	// End Line: 492

	/* begin block 3 */
		// Start line: 501
	/* end block 3 */
	// End Line: 502

void voiceCmdPlay(XAVoiceTracker *vt,short voiceIndex)

{
  ushort *puVar1;
  XAFileInfo *pXVar2;
  uchar local_58;
  byte local_57;
  uchar auStack80 [8];
  uint local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  short local_38;
  short local_36;
  undefined4 local_34;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined4 local_28;
  undefined4 local_24;
  uchar local_20 [8];
  
  if (voiceList != (XAVoiceListEntry *)0x0) {
    puVar1 = &voiceList->length;
    *(short *)&vt->xaFileInfo[0].startPos = voiceIndex >> 4;
    pXVar2 = vt->xaFileInfo + ((int)((uint)(ushort)voiceIndex << 0x10) >> 0x14) + 1;
    putCdCommand(vt,'\t',0,(uchar *)0x0);
    local_58 = '\x01';
    local_57 = (byte)voiceIndex & 0xf;
    putCdCommand(vt,'\r',4,&local_58);
    local_20[0] = -0x38;
    putCdCommand(vt,'\x0e',1,local_20);
    CdIntToPos(pXVar2->startPos,(char *)vt);
    vt->prevCallback =
         (_func_4600 *)
         (pXVar2->startPos +
         ((uint)*(ushort *)((int)puVar1 + ((int)((uint)(ushort)voiceIndex << 0x10) >> 0xf)) - 0x96))
    ;
    CdIntToPos(pXVar2->startPos,(char *)auStack80);
    putCdCommand(vt,'\x1b',4,auStack80);
    local_48 = 0x3fcf;
    local_44 = 0x3fff;
    local_42 = 0x3fff;
    local_40 = 0;
    local_3e = 0;
    local_34 = 0;
    local_30 = 1;
    local_2c = 0x7fff;
    local_2a = 0x7fff;
    local_28 = 0;
    local_24 = 1;
    local_38 = (short)gameTrackerX.sound.gVoiceVol << 8;
    local_36 = local_38;
    SpuSetCommonAttr(&local_48);
    if (0x3c < gameTrackerX.sound.gMusicVol) {
      aadStartMusicMasterVolFade
                (0x3c,-1,(TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdStop(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 298, offset 0x800b1490
	/* begin block 1 */
		// Start line: 299
		// Start offset: 0x800B1490
		// Variables:
	// 		struct SpuCommonAttr spuattr; // stack offset -48
	/* end block 1 */
	// End offset: 0x800B14DC
	// End Line: 314

	/* begin block 2 */
		// Start line: 705
	/* end block 2 */
	// End Line: 706

void voiceCmdStop(XAVoiceTracker *vt,short cmdParam)

{
  uint local_30 [6];
  undefined4 local_18;
  undefined4 local_c;
  
  if (*(char *)&vt->unused2 != '\0') {
    putCdCommand(vt,'\t',0,(uchar *)0x0);
    local_30[0] = 0x2200;
    local_18 = 0;
    local_c = 0;
    SpuSetCommonAttr(local_30);
    aadStartMusicMasterVolFade
              (gameTrackerX.sound.gMusicVol,1,
               (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdPause(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 317, offset 0x800b14ec
	/* begin block 1 */
		// Start line: 746
	/* end block 1 */
	// End Line: 747

void voiceCmdPause(XAVoiceTracker *vt,short cmdParam)

{
  if (*(char *)&vt->unused2 == '\x01') {
    putCdCommand(vt,'\t',0,(uchar *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdResume(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 325, offset 0x800b1520
	/* begin block 1 */
		// Start line: 762
	/* end block 1 */
	// End Line: 763

void voiceCmdResume(XAVoiceTracker *vt,short cmdParam)

{
  if (*(char *)&vt->unused2 == '\x02') {
    putCdCommand(vt,'\x1b',4,(uchar *)vt);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdNull(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 332, offset 0x800b1554
	/* begin block 1 */
		// Start line: 776
	/* end block 1 */
	// End Line: 777

	/* begin block 2 */
		// Start line: 777
	/* end block 2 */
	// End Line: 778

void voiceCmdNull(XAVoiceTracker *vt,short cmdParam)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Play(int voiceIndex /*$a3*/, int queueRequests /*$a1*/)
 // line 337, offset 0x800b155c
	/* begin block 1 */
		// Start line: 338
		// Start offset: 0x800B155C
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a0
	// 		struct XAFileInfo *file; // $a2
	/* end block 1 */
	// End offset: 0x800B1614
	// End Line: 364

	/* begin block 2 */
		// Start line: 786
	/* end block 2 */
	// End Line: 787

void VOICEXA_Play(int voiceIndex,int queueRequests)

{
  uchar uVar1;
  
  if ((((gameTrackerX.debugFlags & 0x80000U) != 0) &&
      (voiceTracker.xaFileInfo[(voiceIndex >> 4) + 1].startPos != 0)) &&
     (gameTrackerX.sound.gVoiceOn != '\0')) {
    if (queueRequests == 0) {
      putVoiceCommand(&voiceTracker,'\0','\x01',voiceIndex);
    }
    else {
      voiceTracker.requestQueue[(uint)voiceTracker.voiceCmdOut + 2] = (ushort)voiceIndex;
      uVar1 = voiceTracker.unused1 + '\x01';
      if (voiceTracker.unused1 < 3) {
        voiceTracker.voiceCmdOut = voiceTracker.voiceCmdOut + '\x01';
        voiceTracker.unused1 = uVar1;
        if (voiceTracker.voiceCmdOut == '\x04') {
          voiceTracker.voiceCmdOut = '\0';
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VOICEXA_FinalStatus(struct XAVoiceTracker *vt /*$a0*/)
 // line 383, offset 0x800b1624
	/* begin block 1 */
		// Start line: 385
		// Start offset: 0x800B1624
		// Variables:
	// 		int tailIndex; // $v0
	/* end block 1 */
	// End offset: 0x800B1660
	// End Line: 400

	/* begin block 2 */
		// Start line: 761
	/* end block 2 */
	// End Line: 762

	/* begin block 3 */
		// Start line: 864
	/* end block 3 */
	// End Line: 865

	/* begin block 4 */
		// Start line: 867
	/* end block 4 */
	// End Line: 868

int VOICEXA_FinalStatus(XAVoiceTracker *vt)

{
  int iVar1;
  
  if (*(char *)&vt->fileNum == '\0') {
    return (uint)*(byte *)&vt->unused2;
  }
  iVar1 = (uint)vt->voiceStatus - 1;
  if (vt->voiceStatus == 0) {
    iVar1 = 0xf;
  }
  return (uint)vt->voiceCmdQueue[iVar1 + 1].nextVoiceStatus;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Pause()
 // line 402, offset 0x800b1668
	/* begin block 1 */
		// Start line: 403
		// Start offset: 0x800B1668
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	// 		int finalStatus; // $a0
	/* end block 1 */
	// End offset: 0x800B16C8
	// End Line: 420

	/* begin block 2 */
		// Start line: 901
	/* end block 2 */
	// End Line: 902

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VOICEXA_Pause(void)

{
  int iVar1;
  uchar voiceCmd;
  uchar nextVoiceStatus;
  
  iVar1 = VOICEXA_FinalStatus(&voiceTracker);
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    voiceCmd = '\x02';
    if (iVar1 == 1) {
      nextVoiceStatus = '\x02';
    }
    else {
      if (iVar1 != 0) {
        return;
      }
      voiceCmd = '\x04';
      nextVoiceStatus = '\x03';
    }
    putVoiceCommand(&voiceTracker,voiceCmd,nextVoiceStatus,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Resume()
 // line 423, offset 0x800b16d8
	/* begin block 1 */
		// Start line: 424
		// Start offset: 0x800B16D8
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	// 		int finalStatus; // $a0
	/* end block 1 */
	// End offset: 0x800B173C
	// End Line: 441

	/* begin block 2 */
		// Start line: 944
	/* end block 2 */
	// End Line: 945

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VOICEXA_Resume(void)

{
  int iVar1;
  uchar voiceCmd;
  uchar nextVoiceStatus;
  
  iVar1 = VOICEXA_FinalStatus(&voiceTracker);
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    if (iVar1 == 2) {
      voiceCmd = '\x03';
      nextVoiceStatus = '\x01';
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      voiceCmd = '\x04';
      nextVoiceStatus = '\0';
    }
    putVoiceCommand(&voiceTracker,voiceCmd,nextVoiceStatus,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Tick()
 // line 459, offset 0x800b174c
	/* begin block 1 */
		// Start line: 460
		// Start offset: 0x800B174C
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	/* end block 1 */
	// End offset: 0x800B188C
	// End Line: 522

	/* begin block 2 */
		// Start line: 1017
	/* end block 2 */
	// End Line: 1018

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VOICEXA_Tick(void)

{
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    processVoiceCommands(&voiceTracker);
    processCdCommands(&voiceTracker);
    if ((voiceTracker.voiceCmdIn == '\0') && ((char)voiceTracker.fileNum == '\0')) {
      if ((byte)voiceTracker.unused2 == 1) {
        CdControlB(0x10,(byte *)0x0,voiceTracker.cdResult + 4);
        if ((voiceTracker.cdResult[7] & 2) != 0) {
          voiceTracker.currentSector._3_1_ = 0;
          voiceTracker.currentSector._0_1_ = voiceTracker.cdResult[4];
          voiceTracker.currentSector._1_1_ = voiceTracker.cdResult[5];
          voiceTracker.currentSector._2_1_ = voiceTracker.cdResult[6];
          voiceTracker.endSector = CdPosToInt((byte *)&voiceTracker);
          voiceTracker.endSector = voiceTracker.endSector + -0x96;
          if ((int)voiceTracker.prevCallback <= voiceTracker.endSector) {
            putVoiceCommand(&voiceTracker,'\x01','\0',0);
          }
        }
      }
      else {
        if ((((byte)voiceTracker.unused2 < 2) && ((byte)voiceTracker.unused2 == 0)) &&
           (voiceTracker.unused1 != '\0')) {
          putVoiceCommand(&voiceTracker,'\0','\x01',
                          (uint)voiceTracker.requestQueue[(uint)voiceTracker.voiceCmdsQueued + 2]);
          voiceTracker.unused1 = voiceTracker.unused1 + -1;
          voiceTracker.voiceCmdsQueued = voiceTracker.voiceCmdsQueued + '\x01';
          if (voiceTracker.voiceCmdsQueued == '\x04') {
            voiceTracker.voiceCmdsQueued = '\0';
          }
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VOICEXA_IsPlaying()
 // line 532, offset 0x800b189c
	/* begin block 1 */
		// Start line: 534
		// Start offset: 0x800B189C
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a1
	/* end block 1 */
	// End offset: 0x800B18C8
	// End Line: 537

	/* begin block 2 */
		// Start line: 1061
	/* end block 2 */
	// End Line: 1062

	/* begin block 3 */
		// Start line: 1171
	/* end block 3 */
	// End Line: 1172

/* WARNING: Unknown calling convention yet parameter storage is locked */

int VOICEXA_IsPlaying(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (((char)voiceTracker.unused2 == '\x01') || (voiceTracker.unused2._1_1_ != '\0')) {
    iVar1 = 1;
  }
  return iVar1;
}





