#include "THISDUST.H"
#include "VOICEXA.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Init()
 // line 54, offset 0x800b6ae0
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800B6AE0
		// Variables:
	// 		int i; // $s1
	// 		struct CdlFILE fp; // stack offset -80
	// 		struct XAVoiceTracker *vt; // $a0
	// 		char fileName[32]; // stack offset -56
	/* end block 1 */
	// End offset: 0x800B6B90
	// End Line: 95

	/* begin block 2 */
		// Start line: 108
	/* end block 2 */
	// End Line: 109

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
    voiceTracker.voiceStatus = '\0';
    voiceTracker.cdStatus = '\0';
    voiceTracker.reqIn = '\0';
    voiceTracker.reqOut = '\0';
    voiceTracker.reqsQueued = '\0';
    voiceTracker.cdCmdIn = '\0';
    voiceTracker.cdCmdOut = '\0';
    voiceTracker.cdCmdsQueued = '\0';
    voiceTracker.voiceCmdIn = '\0';
    voiceTracker.voiceCmdOut = '\0';
    voiceTracker.voiceCmdsQueued = '\0';
    do {
      sprintf(acStack56,"\\VOICE\\VOICE%02d.XA;1");
      puVar1 = CdSearchFile(auStack80,acStack56);
      if (puVar1 == (undefined4 *)0x0) {
        pXVar3->xaFileInfo[0].startPos = 0;
      }
      else {
        iVar2 = CdPosToInt((byte *)auStack80);
        pXVar3->xaFileInfo[0].startPos = iVar2;
      }
      iVar4 = iVar4 + 1;
      pXVar3 = (XAVoiceTracker *)&pXVar3->currentSector;
    } while (iVar4 < 0x1e);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ putCdCommand(struct XAVoiceTracker *vt /*$a0*/, unsigned char cdCommand /*$a1*/, int numParams /*$a2*/, unsigned char *params /*$a3*/)
 // line 98, offset 0x800b6bac
	/* begin block 1 */
		// Start line: 99
		// Start offset: 0x800B6BAC
		// Variables:
	// 		int i; // $t0
	/* end block 1 */
	// End offset: 0x800B6C28
	// End Line: 112

	/* begin block 2 */
		// Start line: 225
	/* end block 2 */
	// End Line: 226

	/* begin block 3 */
		// Start line: 228
	/* end block 3 */
	// End Line: 229

void putCdCommand(XAVoiceTracker *vt,uchar cdCommand,int numParams,uchar *params)

{
  uchar uVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  vt->cdCmdQueue[vt->cdCmdIn].cdCommand = cdCommand;
  puVar2 = params;
  if (0 < numParams) {
    do {
      iVar4 = iVar3 + 1;
      vt->cdCmdQueue[vt->cdCmdIn].cdCmdParam[iVar3] = *puVar2;
      puVar2 = params + iVar4;
      iVar3 = iVar4;
    } while (iVar4 < numParams);
  }
  if (vt->cdCmdsQueued < 7) {
    vt->cdCmdsQueued = vt->cdCmdsQueued + 1;
    uVar1 = vt->cdCmdIn + '\x01';
    vt->cdCmdIn = uVar1;
    if (uVar1 == '\b') {
      vt->cdCmdIn = '\0';
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_CdSyncCallback(unsigned char status /*$a0*/, unsigned char *result /*$a1*/)
 // line 115, offset 0x800b6c30
	/* begin block 1 */
		// Start line: 116
		// Start offset: 0x800B6C30
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a1
	/* end block 1 */
	// End offset: 0x800B6C8C
	// End Line: 137

	/* begin block 2 */
		// Start line: 263
	/* end block 2 */
	// End Line: 264

void VOICEXA_CdSyncCallback(uchar status,uchar *result)

{
  if (status == '\x02') {
    voiceTracker.cdStatus = '\0';
    voiceTracker.cdCmdOut = voiceTracker.cdCmdOut + '\x01';
    if (voiceTracker.cdCmdOut == '\b') {
      voiceTracker.cdCmdOut = '\0';
    }
    voiceTracker.cdCmdsQueued = voiceTracker.cdCmdsQueued + -1;
    CdSyncCallback(voiceTracker.prevCallback);
  }
  else {
    voiceTracker.cdStatus = '\x02';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processCdCommands(struct XAVoiceTracker *vt /*$s1*/)
 // line 141, offset 0x800b6c9c
	/* begin block 1 */
		// Start line: 142
		// Start offset: 0x800B6C9C
		// Variables:
	// 		struct CdCommand *cmd; // $s0
	/* end block 1 */
	// End offset: 0x800B6D30
	// End Line: 163

	/* begin block 2 */
		// Start line: 319
	/* end block 2 */
	// End Line: 320

void processCdCommands(XAVoiceTracker *vt)

{
  _func_61 *p_Var1;
  byte bVar2;
  CdCommand *pCVar3;
  
  if (vt->cdStatus == '\x02') {
    vt->cdStatus = '\x01';
    pCVar3 = vt->cdCmdQueue + vt->cdCmdOut;
    bVar2 = pCVar3->cdCommand;
  }
  else {
    if (vt->cdCmdsQueued == '\0') {
      return;
    }
    if (vt->cdStatus == '\x01') {
      return;
    }
    vt->cdStatus = '\x01';
    pCVar3 = vt->cdCmdQueue + vt->cdCmdOut;
    p_Var1 = (_func_61 *)CdSyncCallback(VOICEXA_CdSyncCallback);
    vt->prevCallback = p_Var1;
    bVar2 = pCVar3->cdCommand;
  }
  CdControl(bVar2,pCVar3->cdCmdParam,vt->cdResult);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ putVoiceCommand(struct XAVoiceTracker *vt /*$a0*/, unsigned char voiceCmd /*$a1*/, unsigned char nextVoiceStatus /*$a2*/, int voiceCmdParam /*$a3*/)
 // line 186, offset 0x800b6d44
	/* begin block 1 */
		// Start line: 414
	/* end block 1 */
	// End Line: 415

	/* begin block 2 */
		// Start line: 415
	/* end block 2 */
	// End Line: 416

void putVoiceCommand(XAVoiceTracker *vt,uchar voiceCmd,uchar nextVoiceStatus,int voiceCmdParam)

{
  uchar uVar1;
  
  vt->voiceCmdQueue[vt->voiceCmdIn].voiceCmd = voiceCmd;
  vt->voiceCmdQueue[vt->voiceCmdIn].nextVoiceStatus = nextVoiceStatus;
  vt->voiceCmdQueue[vt->voiceCmdIn].voiceCmdParam = (ushort)voiceCmdParam;
  if (vt->voiceCmdsQueued < 0xf) {
    vt->voiceCmdsQueued = vt->voiceCmdsQueued + 1;
    uVar1 = vt->voiceCmdIn + '\x01';
    vt->voiceCmdIn = uVar1;
    if (uVar1 == '\x10') {
      vt->voiceCmdIn = '\0';
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processVoiceCommands(struct XAVoiceTracker *vt /*$s1*/)
 // line 203, offset 0x800b6dc0
	/* begin block 1 */
		// Start line: 204
		// Start offset: 0x800B6DC0
		// Variables:
	// 		struct VoiceCommand *cmd; // $s0
	/* end block 1 */
	// End offset: 0x800B6E5C
	// End Line: 221

	/* begin block 2 */
		// Start line: 449
	/* end block 2 */
	// End Line: 450

void processVoiceCommands(XAVoiceTracker *vt)

{
  uint uVar1;
  VoiceCommand *pVVar2;
  
  if (vt->voiceCmdsQueued != '\0') {
    vt->voiceCmdsQueued = vt->voiceCmdsQueued + -1;
    uVar1 = (uint)vt->voiceCmdOut + 1;
    pVVar2 = vt->voiceCmdQueue + (uint)vt->voiceCmdOut;
    vt->voiceCmdOut = (uchar)uVar1;
    if ((uVar1 & 0xff) == 0x10) {
      vt->voiceCmdOut = '\0';
    }
    if (pVVar2->voiceCmd < 5) {
      (*(code *)(&voiceCmdTbl)[pVVar2->voiceCmd])(vt,(int)(short)pVVar2->voiceCmdParam);
      vt->voiceStatus = pVVar2->nextVoiceStatus;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdPlay(struct XAVoiceTracker *vt /*$s2*/, short voiceIndex /*$s3*/)
 // line 226, offset 0x800b6e70
	/* begin block 1 */
		// Start line: 227
		// Start offset: 0x800B6E70
		// Variables:
	// 		struct CdlFILTER filter; // stack offset -88
	// 		struct CdlLOC pos; // stack offset -80
	// 		unsigned char mode; // stack offset -32
	// 		struct SpuCommonAttr spuattr; // stack offset -72
	// 		struct XAVoiceListEntry *voice; // $s1
	// 		struct XAFileInfo *file; // $s0
	/* end block 1 */
	// End offset: 0x800B6FC4
	// End Line: 299

	/* begin block 2 */
		// Start line: 499
	/* end block 2 */
	// End Line: 500

	/* begin block 3 */
		// Start line: 509
	/* end block 3 */
	// End Line: 510

void voiceCmdPlay(XAVoiceTracker *vt,short voiceIndex)

{
  ushort *puVar1;
  XAFileInfo *pXVar2;
  uchar local_58;
  byte local_57;
  uchar auStack80 [8];
  undefined *local_48;
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
    vt->fileNum = voiceIndex >> 4;
    pXVar2 = vt->xaFileInfo + ((int)((uint)(ushort)voiceIndex << 0x10) >> 0x14);
    putCdCommand(vt,'\t',0,(uchar *)0x0);
    local_58 = '\x01';
    local_57 = (byte)voiceIndex & 0xf;
    putCdCommand(vt,'\r',4,&local_58);
    local_20[0] = -0x38;
    putCdCommand(vt,'\x0e',1,local_20);
    CdIntToPos(pXVar2->startPos,(char *)vt);
    vt->endSector =
         pXVar2->startPos +
         ((uint)*(ushort *)((int)puVar1 + ((int)((uint)(ushort)voiceIndex << 0x10) >> 0xf)) - 0x96);
    CdIntToPos(pXVar2->startPos,(char *)auStack80);
    putCdCommand(vt,'\x1b',4,auStack80);
    local_48 = &DAT_00003fcf;
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
    SpuSetCommonAttr((uint *)&local_48);
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
 // line 302, offset 0x800b6fe0
	/* begin block 1 */
		// Start line: 303
		// Start offset: 0x800B6FE0
		// Variables:
	// 		struct SpuCommonAttr spuattr; // stack offset -48
	/* end block 1 */
	// End offset: 0x800B702C
	// End Line: 318

	/* begin block 2 */
		// Start line: 713
	/* end block 2 */
	// End Line: 714

void voiceCmdStop(XAVoiceTracker *vt,short cmdParam)

{
  undefined *local_30 [6];
  undefined4 local_18;
  undefined4 local_c;
  
  if (vt->voiceStatus != '\0') {
    putCdCommand(vt,'\t',0,(uchar *)0x0);
    local_30[0] = &DAT_00002200;
    local_18 = 0;
    local_c = 0;
    SpuSetCommonAttr((uint *)local_30);
    aadStartMusicMasterVolFade
              (gameTrackerX.sound.gMusicVol,1,
               (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdPause(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 321, offset 0x800b703c
	/* begin block 1 */
		// Start line: 754
	/* end block 1 */
	// End Line: 755

void voiceCmdPause(XAVoiceTracker *vt,short cmdParam)

{
  if ((uint)vt->voiceStatus - 1 < 2) {
    putCdCommand(vt,'\t',0,(uchar *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdResume(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 329, offset 0x800b7078
	/* begin block 1 */
		// Start line: 770
	/* end block 1 */
	// End Line: 771

void voiceCmdResume(XAVoiceTracker *vt,short cmdParam)

{
  if (vt->voiceStatus == '\x03') {
    putCdCommand(vt,'\x1b',4,(uchar *)vt);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdNull(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 336, offset 0x800b70ac
	/* begin block 1 */
		// Start line: 784
	/* end block 1 */
	// End Line: 785

	/* begin block 2 */
		// Start line: 785
	/* end block 2 */
	// End Line: 786

void voiceCmdNull(XAVoiceTracker *vt,short cmdParam)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Play(int voiceIndex /*$a3*/, int queueRequests /*$a1*/)
 // line 341, offset 0x800b70b4
	/* begin block 1 */
		// Start line: 342
		// Start offset: 0x800B70B4
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a0
	// 		struct XAFileInfo *file; // $a2
	/* end block 1 */
	// End offset: 0x800B7168
	// End Line: 368

	/* begin block 2 */
		// Start line: 794
	/* end block 2 */
	// End Line: 795

void VOICEXA_Play(int voiceIndex,int queueRequests)

{
  uchar uVar1;
  
  if ((((gameTrackerX.debugFlags & 0x80000U) != 0) &&
      (voiceTracker.xaFileInfo[voiceIndex >> 4].startPos != 0)) &&
     (gameTrackerX.sound.gVoiceOn != '\0')) {
    if (queueRequests == 0) {
      putVoiceCommand(&voiceTracker,'\0','\x01',voiceIndex);
    }
    else {
      voiceTracker.requestQueue[voiceTracker.reqIn] = (ushort)voiceIndex;
      uVar1 = voiceTracker.reqsQueued + '\x01';
      if (voiceTracker.reqsQueued < 3) {
        voiceTracker.reqIn = voiceTracker.reqIn + '\x01';
        voiceTracker.reqsQueued = uVar1;
        if (voiceTracker.reqIn == '\x04') {
          voiceTracker.reqIn = '\0';
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ VOICEXA_FinalStatus(struct XAVoiceTracker *vt /*$a0*/)
 // line 387, offset 0x800b7178
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x800B7178
		// Variables:
	// 		int tailIndex; // $v0
	/* end block 1 */
	// End offset: 0x800B71B4
	// End Line: 404

	/* begin block 2 */
		// Start line: 774
	/* end block 2 */
	// End Line: 775

	/* begin block 3 */
		// Start line: 872
	/* end block 3 */
	// End Line: 873

	/* begin block 4 */
		// Start line: 875
	/* end block 4 */
	// End Line: 876

int VOICEXA_FinalStatus(XAVoiceTracker *vt)

{
  int iVar1;
  
  if (vt->voiceCmdsQueued == '\0') {
    return (uint)vt->voiceStatus;
  }
  iVar1 = (uint)vt->voiceCmdIn - 1;
  if (vt->voiceCmdIn == 0) {
    iVar1 = 0xf;
  }
  return (uint)vt->voiceCmdQueue[iVar1].nextVoiceStatus;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Pause()
 // line 406, offset 0x800b71bc
	/* begin block 1 */
		// Start line: 407
		// Start offset: 0x800B71BC
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	// 		int finalStatus; // $a0
	/* end block 1 */
	// End offset: 0x800B721C
	// End Line: 424

	/* begin block 2 */
		// Start line: 909
	/* end block 2 */
	// End Line: 910

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VOICEXA_Pause(void)

{
  int iVar1;
  uchar voiceCmd;
  uchar nextVoiceStatus;
  
  iVar1 = VOICEXA_FinalStatus(&voiceTracker);
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    voiceCmd = '\x02';
    if (iVar1 - 1U < 2) {
      nextVoiceStatus = '\x03';
    }
    else {
      if (iVar1 != 0) {
        return;
      }
      voiceCmd = '\x04';
      nextVoiceStatus = '\x04';
    }
    putVoiceCommand(&voiceTracker,voiceCmd,nextVoiceStatus,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Resume()
 // line 427, offset 0x800b722c
	/* begin block 1 */
		// Start line: 428
		// Start offset: 0x800B722C
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	// 		int finalStatus; // $a0
	/* end block 1 */
	// End offset: 0x800B728C
	// End Line: 445

	/* begin block 2 */
		// Start line: 952
	/* end block 2 */
	// End Line: 953

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VOICEXA_Resume(void)

{
  int iVar1;
  uchar voiceCmd;
  uchar nextVoiceStatus;
  
  iVar1 = VOICEXA_FinalStatus(&voiceTracker);
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    voiceCmd = '\x03';
    if (iVar1 == 3) {
      nextVoiceStatus = '\x01';
    }
    else {
      if (iVar1 != 4) {
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
 // line 464, offset 0x800b729c
	/* begin block 1 */
		// Start line: 465
		// Start offset: 0x800B729C
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	/* end block 1 */
	// End offset: 0x800B73E4
	// End Line: 529

	/* begin block 2 */
		// Start line: 1027
	/* end block 2 */
	// End Line: 1028

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VOICEXA_Tick(void)

{
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    processVoiceCommands(&voiceTracker);
    processCdCommands(&voiceTracker);
    if (((voiceTracker.cdCmdsQueued == '\0') && (voiceTracker.voiceCmdsQueued == '\0')) &&
       (voiceTracker.voiceStatus < 3)) {
      if (voiceTracker.voiceStatus == '\0') {
        if (voiceTracker.reqsQueued != '\0') {
          putVoiceCommand(&voiceTracker,'\0','\x01',
                          (uint)voiceTracker.requestQueue[voiceTracker.reqOut]);
          voiceTracker.reqsQueued = voiceTracker.reqsQueued + -1;
          voiceTracker.reqOut = voiceTracker.reqOut + '\x01';
          if (voiceTracker.reqOut == '\x04') {
            voiceTracker.reqOut = '\0';
          }
        }
      }
      else {
        CdControlB(0x10,(byte *)0x0,voiceTracker.cdResult);
        if ((voiceTracker.cdResult[3] & 2) != 0) {
          voiceTracker.voiceStatus = '\x02';
          voiceTracker.currentPos.track = '\0';
          voiceTracker.currentPos.minute = voiceTracker.cdResult[0];
          voiceTracker.currentPos.second = voiceTracker.cdResult[1];
          voiceTracker.currentPos.sector = voiceTracker.cdResult[2];
          voiceTracker.currentSector = CdPosToInt((byte *)&voiceTracker);
          voiceTracker.currentSector = voiceTracker.currentSector + -0x96;
          if (voiceTracker.endSector + -8 <= voiceTracker.currentSector) {
            putVoiceCommand(&voiceTracker,'\x01','\0',0);
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
 // line 546, offset 0x800b73f4
	/* begin block 1 */
		// Start line: 548
		// Start offset: 0x800B73F4
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a0
	/* end block 1 */
	// End offset: 0x800B742C
	// End Line: 558

	/* begin block 2 */
		// Start line: 1092
	/* end block 2 */
	// End Line: 1093

	/* begin block 3 */
		// Start line: 1196
	/* end block 3 */
	// End Line: 1197

/* WARNING: Unknown calling convention yet parameter storage is locked */

int VOICEXA_IsPlaying(void)

{
  int iVar1;
  
  iVar1 = 2;
  if ((voiceTracker.voiceStatus != '\x02') &&
     ((voiceTracker.voiceStatus == '\x01' || (iVar1 = 0, voiceTracker.cdStatus != '\0')))) {
    return 1;
  }
  return iVar1;
}





