#include "THISDUST.H"
#include "VOICEXA.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Init()
 // line 54, offset 0x800b5754
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800B5754
		// Variables:
	// 		int i; // $s1
	// 		struct CdlFILE fp; // stack offset -80
	// 		struct XAVoiceTracker *vt; // $a0
	// 		char fileName[32]; // stack offset -56
	/* end block 1 */
	// End offset: 0x800B5808
	// End Line: 95

	/* begin block 2 */
		// Start line: 108
	/* end block 2 */
	// End Line: 109

/* File: C:\kain2\game\VOICEXA.C */

void VOICEXA_Init(void)

{
  CdlFILE *pCVar1;
  int iVar2;
  XAVoiceTracker *pXVar3;
  int iVar4;
  CdlFILE CStack80;
  char acStack56 [32];
  
  pXVar3 = &voiceTracker;
  if ((DAT_800d218c & 0x80000) != 0) {
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
      sprintf(acStack56,s__VOICE_VOICE_02d_XA_1_800d0c24,iVar4);
      pCVar1 = CdSearchFile(&CStack80,acStack56);
      if (pCVar1 == (CdlFILE *)0x0) {
        pXVar3->xaFileInfo[0].startPos = 0;
      }
      else {
        iVar2 = CdPosToInt((CdlLOC *)&CStack80);
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
 // line 98, offset 0x800b5824
	/* begin block 1 */
		// Start line: 99
		// Start offset: 0x800B5824
		// Variables:
	// 		int i; // $t0
	/* end block 1 */
	// End offset: 0x800B58A0
	// End Line: 112

	/* begin block 2 */
		// Start line: 225
	/* end block 2 */
	// End Line: 226

	/* begin block 3 */
		// Start line: 228
	/* end block 3 */
	// End Line: 229

/* File: C:\kain2\game\VOICEXA.C */

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
 // line 115, offset 0x800b58a8
	/* begin block 1 */
		// Start line: 116
		// Start offset: 0x800B58A8
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a1
	/* end block 1 */
	// End offset: 0x800B5908
	// End Line: 137

	/* begin block 2 */
		// Start line: 263
	/* end block 2 */
	// End Line: 264

/* File: C:\kain2\game\VOICEXA.C */

void VOICEXA_CdSyncCallback(uchar status,uchar *result)

{
  if (status == '\x02') {
    voiceTracker.cdStatus = '\0';
    voiceTracker.cdCmdOut = voiceTracker.cdCmdOut + '\x01';
    if (voiceTracker.cdCmdOut == '\b') {
      voiceTracker.cdCmdOut = '\0';
    }
    voiceTracker.cdCmdsQueued = voiceTracker.cdCmdsQueued + -1;
    CdSyncCallback((CdlCB)voiceTracker.prevCallback);
  }
  else {
    voiceTracker.cdStatus = '\x02';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ processCdCommands(struct XAVoiceTracker *vt /*$s1*/)
 // line 141, offset 0x800b5918
	/* begin block 1 */
		// Start line: 142
		// Start offset: 0x800B5918
		// Variables:
	// 		struct CdCommand *cmd; // $s0
	/* end block 1 */
	// End offset: 0x800B59AC
	// End Line: 163

	/* begin block 2 */
		// Start line: 319
	/* end block 2 */
	// End Line: 320

/* File: C:\kain2\game\VOICEXA.C */

void processCdCommands(XAVoiceTracker *vt)

{
  CdlCB pCVar1;
  u_char com;
  CdCommand *pCVar2;
  
  if (vt->cdStatus == '\x02') {
    vt->cdStatus = '\x01';
    pCVar2 = vt->cdCmdQueue + vt->cdCmdOut;
    com = pCVar2->cdCommand;
  }
  else {
    if (vt->cdCmdsQueued == '\0') {
      return;
    }
    if (vt->cdStatus == '\x01') {
      return;
    }
    vt->cdStatus = '\x01';
    pCVar2 = vt->cdCmdQueue + vt->cdCmdOut;
    pCVar1 = CdSyncCallback(VOICEXA_CdSyncCallback);
    *(CdlCB *)&vt->prevCallback = pCVar1;
    com = pCVar2->cdCommand;
  }
  CdControl(com,pCVar2->cdCmdParam,vt->cdResult);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ putVoiceCommand(struct XAVoiceTracker *vt /*$a0*/, unsigned char voiceCmd /*$a1*/, unsigned char nextVoiceStatus /*$a2*/, int voiceCmdParam /*$a3*/)
 // line 186, offset 0x800b59c0
	/* begin block 1 */
		// Start line: 414
	/* end block 1 */
	// End Line: 415

	/* begin block 2 */
		// Start line: 415
	/* end block 2 */
	// End Line: 416

/* File: C:\kain2\game\VOICEXA.C */

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
 // line 203, offset 0x800b5a3c
	/* begin block 1 */
		// Start line: 204
		// Start offset: 0x800B5A3C
		// Variables:
	// 		struct VoiceCommand *cmd; // $s0
	/* end block 1 */
	// End offset: 0x800B5ADC
	// End Line: 221

	/* begin block 2 */
		// Start line: 449
	/* end block 2 */
	// End Line: 450

/* File: C:\kain2\game\VOICEXA.C */

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
      (*(code *)voiceCmdTbl[pVVar2->voiceCmd])(vt,(int)(short)pVVar2->voiceCmdParam);
      vt->voiceStatus = pVVar2->nextVoiceStatus;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdPlay(struct XAVoiceTracker *vt /*$s2*/, short voiceIndex /*$s3*/)
 // line 226, offset 0x800b5af0
	/* begin block 1 */
		// Start line: 227
		// Start offset: 0x800B5AF0
		// Variables:
	// 		struct CdlFILTER filter; // stack offset -88
	// 		struct CdlLOC pos; // stack offset -80
	// 		unsigned char mode; // stack offset -32
	// 		struct SpuCommonAttr spuattr; // stack offset -72
	// 		struct XAVoiceListEntry *voice; // $s1
	// 		struct XAFileInfo *file; // $s0
	/* end block 1 */
	// End offset: 0x800B5C44
	// End Line: 299

	/* begin block 2 */
		// Start line: 499
	/* end block 2 */
	// End Line: 500

	/* begin block 3 */
		// Start line: 509
	/* end block 3 */
	// End Line: 510

/* File: C:\kain2\game\VOICEXA.C */

void voiceCmdPlay(XAVoiceTracker *vt,short voiceIndex)

{
  ushort *puVar1;
  XAFileInfo *pXVar2;
  uchar local_58;
  byte local_57;
  CdlLOC aCStack80 [2];
  SpuCommonAttr local_48;
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
    CdIntToPos(pXVar2->startPos,(CdlLOC *)vt);
    vt->endSector =
         pXVar2->startPos +
         ((uint)*(ushort *)((int)puVar1 + ((int)((uint)(ushort)voiceIndex << 0x10) >> 0xf)) - 0x96);
    CdIntToPos(pXVar2->startPos,aCStack80);
    putCdCommand(vt,'\x1b',4,(uchar *)aCStack80);
    local_48.mask = &DAT_00003fcf;
    local_48.mvol.left = 0x3fff;
    local_48.mvol.right = 0x3fff;
    local_48.mvolmode.left = 0;
    local_48.mvolmode.right = 0;
    local_48.cd.reverb = 0;
    local_48.cd.mix = 1;
    local_48.ext.volume.left = 0x7fff;
    local_48.ext.volume.right = 0x7fff;
    local_48.ext.reverb = 0;
    local_48.ext.mix = 1;
    local_48.cd.volume.left = DAT_800d228c << 8;
    local_48.cd.volume.right = local_48.cd.volume.left;
    SpuSetCommonAttr(&local_48);
    if (0x3c < DAT_800d2284) {
      aadStartMusicMasterVolFade
                (0x3c,-1,(TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdStop(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 302, offset 0x800b5c60
	/* begin block 1 */
		// Start line: 303
		// Start offset: 0x800B5C60
		// Variables:
	// 		struct SpuCommonAttr spuattr; // stack offset -48
	/* end block 1 */
	// End offset: 0x800B5CAC
	// End Line: 318

	/* begin block 2 */
		// Start line: 713
	/* end block 2 */
	// End Line: 714

/* File: C:\kain2\game\VOICEXA.C */

void voiceCmdStop(XAVoiceTracker *vt,short cmdParam)

{
  SpuCommonAttr local_30;
  
  if (vt->voiceStatus != '\0') {
    putCdCommand(vt,'\t',0,(uchar *)0x0);
    local_30.mask = &DAT_00002200;
    local_30.cd.mix = 0;
    local_30.ext.mix = 0;
    SpuSetCommonAttr(&local_30);
    aadStartMusicMasterVolFade
              (DAT_800d2284,1,(TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ voiceCmdPause(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
 // line 321, offset 0x800b5cbc
	/* begin block 1 */
		// Start line: 754
	/* end block 1 */
	// End Line: 755

/* File: C:\kain2\game\VOICEXA.C */

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
 // line 329, offset 0x800b5cf8
	/* begin block 1 */
		// Start line: 770
	/* end block 1 */
	// End Line: 771

/* File: C:\kain2\game\VOICEXA.C */

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
 // line 336, offset 0x800b5d2c
	/* begin block 1 */
		// Start line: 784
	/* end block 1 */
	// End Line: 785

	/* begin block 2 */
		// Start line: 785
	/* end block 2 */
	// End Line: 786

/* File: C:\kain2\game\VOICEXA.C */

void voiceCmdNull(XAVoiceTracker *vt,short cmdParam)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Play(int voiceIndex /*$a3*/, int queueRequests /*$a1*/)
 // line 341, offset 0x800b5d34
	/* begin block 1 */
		// Start line: 342
		// Start offset: 0x800B5D34
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a0
	// 		struct XAFileInfo *file; // $a2
	/* end block 1 */
	// End offset: 0x800B5DEC
	// End Line: 368

	/* begin block 2 */
		// Start line: 794
	/* end block 2 */
	// End Line: 795

/* File: C:\kain2\game\VOICEXA.C */

void VOICEXA_Play(int voiceIndex,int queueRequests)

{
  uchar uVar1;
  
  if ((((DAT_800d218c & 0x80000) != 0) && (voiceTracker.xaFileInfo[voiceIndex >> 4].startPos != 0))
     && (DAT_800d2292 != '\0')) {
    if (queueRequests == 0) {
      putVoiceCommand((XAVoiceTracker *)&voiceTracker,'\0','\x01',voiceIndex);
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
 // line 387, offset 0x800b5dfc
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x800B5DFC
		// Variables:
	// 		int tailIndex; // $v0
	/* end block 1 */
	// End offset: 0x800B5E38
	// End Line: 404

	/* begin block 2 */
		// Start line: 769
	/* end block 2 */
	// End Line: 770

	/* begin block 3 */
		// Start line: 872
	/* end block 3 */
	// End Line: 873

	/* begin block 4 */
		// Start line: 875
	/* end block 4 */
	// End Line: 876

/* File: C:\kain2\game\VOICEXA.C */

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
 // line 406, offset 0x800b5e40
	/* begin block 1 */
		// Start line: 407
		// Start offset: 0x800B5E40
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	// 		int finalStatus; // $a0
	/* end block 1 */
	// End offset: 0x800B5EA4
	// End Line: 424

	/* begin block 2 */
		// Start line: 909
	/* end block 2 */
	// End Line: 910

/* File: C:\kain2\game\VOICEXA.C */

void VOICEXA_Pause(void)

{
  int iVar1;
  uchar voiceCmd;
  uchar nextVoiceStatus;
  
  iVar1 = VOICEXA_FinalStatus((XAVoiceTracker *)&voiceTracker);
  if ((DAT_800d218c & 0x80000) != 0) {
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
    putVoiceCommand((XAVoiceTracker *)&voiceTracker,voiceCmd,nextVoiceStatus,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Resume()
 // line 427, offset 0x800b5eb4
	/* begin block 1 */
		// Start line: 428
		// Start offset: 0x800B5EB4
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	// 		int finalStatus; // $a0
	/* end block 1 */
	// End offset: 0x800B5F18
	// End Line: 445

	/* begin block 2 */
		// Start line: 952
	/* end block 2 */
	// End Line: 953

/* File: C:\kain2\game\VOICEXA.C */

void VOICEXA_Resume(void)

{
  int iVar1;
  uchar voiceCmd;
  uchar nextVoiceStatus;
  
  iVar1 = VOICEXA_FinalStatus((XAVoiceTracker *)&voiceTracker);
  if ((DAT_800d218c & 0x80000) != 0) {
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
    putVoiceCommand((XAVoiceTracker *)&voiceTracker,voiceCmd,nextVoiceStatus,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VOICEXA_Tick()
 // line 464, offset 0x800b5f28
	/* begin block 1 */
		// Start line: 465
		// Start offset: 0x800B5F28
		// Variables:
	// 		struct XAVoiceTracker *vt; // $s0
	/* end block 1 */
	// End offset: 0x800B6074
	// End Line: 529

	/* begin block 2 */
		// Start line: 1027
	/* end block 2 */
	// End Line: 1028

/* File: C:\kain2\game\VOICEXA.C */

void VOICEXA_Tick(void)

{
  if ((DAT_800d218c & 0x80000) != 0) {
    processVoiceCommands((XAVoiceTracker *)&voiceTracker);
    processCdCommands((XAVoiceTracker *)&voiceTracker);
    if (((voiceTracker.cdCmdsQueued == '\0') && (voiceTracker.voiceCmdsQueued == '\0')) &&
       (voiceTracker.voiceStatus < 3)) {
      if (voiceTracker.voiceStatus == '\0') {
        if (voiceTracker.reqsQueued != '\0') {
          putVoiceCommand((XAVoiceTracker *)&voiceTracker,'\0','\x01',
                          (uint)voiceTracker.requestQueue[voiceTracker.reqOut]);
          voiceTracker.reqsQueued = voiceTracker.reqsQueued + -1;
          voiceTracker.reqOut = voiceTracker.reqOut + '\x01';
          if (voiceTracker.reqOut == '\x04') {
            voiceTracker.reqOut = '\0';
          }
        }
      }
      else {
        CdControlB('\x10',(u_char *)0x0,voiceTracker.cdResult);
        if ((voiceTracker.cdResult[3] & 2) != 0) {
          voiceTracker.voiceStatus = '\x02';
          voiceTracker.currentPos.track = '\0';
          voiceTracker.currentPos.minute = voiceTracker.cdResult[0];
          voiceTracker.currentPos.second = voiceTracker.cdResult[1];
          voiceTracker.currentPos.sector = voiceTracker.cdResult[2];
          voiceTracker.currentSector = CdPosToInt((CdlLOC *)&voiceTracker);
          voiceTracker.currentSector = voiceTracker.currentSector + -0x96;
          if (voiceTracker.endSector <= voiceTracker.currentSector) {
            putVoiceCommand((XAVoiceTracker *)&voiceTracker,'\x01','\0',0);
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
 // line 546, offset 0x800b6084
	/* begin block 1 */
		// Start line: 548
		// Start offset: 0x800B6084
		// Variables:
	// 		struct XAVoiceTracker *vt; // $a0
	/* end block 1 */
	// End offset: 0x800B60C0
	// End Line: 558

	/* begin block 2 */
		// Start line: 1082
	/* end block 2 */
	// End Line: 1083

	/* begin block 3 */
		// Start line: 1196
	/* end block 3 */
	// End Line: 1197

/* File: C:\kain2\game\VOICEXA.C */

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





