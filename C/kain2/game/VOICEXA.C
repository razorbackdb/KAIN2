#include "THISDUST.H"
#include "VOICEXA.H"

// XAVoiceTracker @0x800D5AD4, len = 0x00000128
voiceTracker =
	{
		// CdlLOC @0x800D5AD4, len = 0x00000004
		.currentPos =
			{
				// uchar @0x800D5AD4, len = 0x00000001
				.minute = 0x00,
				// uchar @0x800D5AD5, len = 0x00000001
				.second = 0x00,
				// uchar @0x800D5AD6, len = 0x00000001
				.sector = 0x00,
				// uchar @0x800D5AD7, len = 0x00000001
				.track = 0x00},
		// int @0x800D5AD8, len = 0x00000004
		.currentSector = null,
		// int @0x800D5ADC, len = 0x00000004
		.endSector = null,
		// _func_134 * @0x800D5AE0, len = 0x00000004
		.prevCallback = null,
		// uchar[8] @0x800D5AE4, len = 0x00000008
		.cdResult =
			{
				// uchar @0x800D5AE4, len = 0x00000001
				'\x00',
				// uchar @0x800D5AE5, len = 0x00000001
				'\x00',
				// uchar @0x800D5AE6, len = 0x00000001
				'\x00',
				// uchar @0x800D5AE7, len = 0x00000001
				'\x00',
				// uchar @0x800D5AE8, len = 0x00000001
				'\x00',
				// uchar @0x800D5AE9, len = 0x00000001
				'\x00',
				// uchar @0x800D5AEA, len = 0x00000001
				'\x00',
				// uchar @0x800D5AEB, len = 0x00000001
				'\x00'},
		// CdCommand[8] @0x800D5AEC, len = 0x00000040
		.cdCmdQueue =
			{
				// CdCommand @0x800D5AEC, len = 0x00000008
				{
					// ushort @0x800D5AEC, len = 0x00000002
					.flags = null,
					// uchar @0x800D5AEE, len = 0x00000001
					.unused = 0x00,
					// uchar @0x800D5AEF, len = 0x00000001
					.cdCommand = 0x00,
					// uchar[4] @0x800D5AF0, len = 0x00000004
					.cdCmdParam =
						{
							// uchar @0x800D5AF0, len = 0x00000001
							'\x00',
							// uchar @0x800D5AF1, len = 0x00000001
							'\x00',
							// uchar @0x800D5AF2, len = 0x00000001
							'\x00',
							// uchar @0x800D5AF3, len = 0x00000001
							'\x00'}},
				// CdCommand @0x800D5AF4, len = 0x00000008
				{
					// ushort @0x800D5AF4, len = 0x00000002
					.flags = null,
					// uchar @0x800D5AF6, len = 0x00000001
					.unused = 0x00,
					// uchar @0x800D5AF7, len = 0x00000001
					.cdCommand = 0x00,
					// uchar[4] @0x800D5AF8, len = 0x00000004
					.cdCmdParam =
						{
							// uchar @0x800D5AF8, len = 0x00000001
							'\x00',
							// uchar @0x800D5AF9, len = 0x00000001
							'\x00',
							// uchar @0x800D5AFA, len = 0x00000001
							'\x00',
							// uchar @0x800D5AFB, len = 0x00000001
							'\x00'}},
				// CdCommand @0x800D5AFC, len = 0x00000008
				{
					// ushort @0x800D5AFC, len = 0x00000002
					.flags = null,
					// uchar @0x800D5AFE, len = 0x00000001
					.unused = 0x00,
					// uchar @0x800D5AFF, len = 0x00000001
					.cdCommand = 0x00,
					// uchar[4] @0x800D5B00, len = 0x00000004
					.cdCmdParam =
						{
							// uchar @0x800D5B00, len = 0x00000001
							'\x00',
							// uchar @0x800D5B01, len = 0x00000001
							'\x00',
							// uchar @0x800D5B02, len = 0x00000001
							'\x00',
							// uchar @0x800D5B03, len = 0x00000001
							'\x00'}},
				// CdCommand @0x800D5B04, len = 0x00000008
				{
					// ushort @0x800D5B04, len = 0x00000002
					.flags = null,
					// uchar @0x800D5B06, len = 0x00000001
					.unused = 0x00,
					// uchar @0x800D5B07, len = 0x00000001
					.cdCommand = 0x00,
					// uchar[4] @0x800D5B08, len = 0x00000004
					.cdCmdParam =
						{
							// uchar @0x800D5B08, len = 0x00000001
							'\x00',
							// uchar @0x800D5B09, len = 0x00000001
							'\x00',
							// uchar @0x800D5B0A, len = 0x00000001
							'\x00',
							// uchar @0x800D5B0B, len = 0x00000001
							'\x00'}},
				// CdCommand @0x800D5B0C, len = 0x00000008
				{
					// ushort @0x800D5B0C, len = 0x00000002
					.flags = null,
					// uchar @0x800D5B0E, len = 0x00000001
					.unused = 0x00,
					// uchar @0x800D5B0F, len = 0x00000001
					.cdCommand = 0x00,
					// uchar[4] @0x800D5B10, len = 0x00000004
					.cdCmdParam =
						{
							// uchar @0x800D5B10, len = 0x00000001
							'\x00',
							// uchar @0x800D5B11, len = 0x00000001
							'\x00',
							// uchar @0x800D5B12, len = 0x00000001
							'\x00',
							// uchar @0x800D5B13, len = 0x00000001
							'\x00'}},
				// CdCommand @0x800D5B14, len = 0x00000008
				{
					// ushort @0x800D5B14, len = 0x00000002
					.flags = null,
					// uchar @0x800D5B16, len = 0x00000001
					.unused = 0x00,
					// uchar @0x800D5B17, len = 0x00000001
					.cdCommand = 0x00,
					// uchar[4] @0x800D5B18, len = 0x00000004
					.cdCmdParam =
						{
							// uchar @0x800D5B18, len = 0x00000001
							'\x00',
							// uchar @0x800D5B19, len = 0x00000001
							'\x00',
							// uchar @0x800D5B1A, len = 0x00000001
							'\x00',
							// uchar @0x800D5B1B, len = 0x00000001
							'\x00'}},
				// CdCommand @0x800D5B1C, len = 0x00000008
				{
					// ushort @0x800D5B1C, len = 0x00000002
					.flags = null,
					// uchar @0x800D5B1E, len = 0x00000001
					.unused = 0x00,
					// uchar @0x800D5B1F, len = 0x00000001
					.cdCommand = 0x00,
					// uchar[4] @0x800D5B20, len = 0x00000004
					.cdCmdParam =
						{
							// uchar @0x800D5B20, len = 0x00000001
							'\x00',
							// uchar @0x800D5B21, len = 0x00000001
							'\x00',
							// uchar @0x800D5B22, len = 0x00000001
							'\x00',
							// uchar @0x800D5B23, len = 0x00000001
							'\x00'}},
				// CdCommand @0x800D5B24, len = 0x00000008
				{
					// ushort @0x800D5B24, len = 0x00000002
					.flags = null,
					// uchar @0x800D5B26, len = 0x00000001
					.unused = 0x00,
					// uchar @0x800D5B27, len = 0x00000001
					.cdCommand = 0x00,
					// uchar[4] @0x800D5B28, len = 0x00000004
					.cdCmdParam =
						{
							// uchar @0x800D5B28, len = 0x00000001
							'\x00',
							// uchar @0x800D5B29, len = 0x00000001
							'\x00',
							// uchar @0x800D5B2A, len = 0x00000001
							'\x00',
							// uchar @0x800D5B2B, len = 0x00000001
							'\x00'}}},
		// ushort[4] @0x800D5B2C, len = 0x00000008
		.requestQueue =
			{
				// ushort @0x800D5B2C, len = 0x00000002
				null,
				// ushort @0x800D5B2E, len = 0x00000002
				null,
				// ushort @0x800D5B30, len = 0x00000002
				null,
				// ushort @0x800D5B32, len = 0x00000002
				null},
		// VoiceCommand[16] @0x800D5B34, len = 0x00000040
		.voiceCmdQueue =
			{
				// VoiceCommand @0x800D5B34, len = 0x00000004
				{
					// uchar @0x800D5B34, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B35, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B36, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B38, len = 0x00000004
				{
					// uchar @0x800D5B38, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B39, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B3A, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B3C, len = 0x00000004
				{
					// uchar @0x800D5B3C, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B3D, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B3E, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B40, len = 0x00000004
				{
					// uchar @0x800D5B40, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B41, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B42, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B44, len = 0x00000004
				{
					// uchar @0x800D5B44, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B45, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B46, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B48, len = 0x00000004
				{
					// uchar @0x800D5B48, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B49, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B4A, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B4C, len = 0x00000004
				{
					// uchar @0x800D5B4C, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B4D, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B4E, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B50, len = 0x00000004
				{
					// uchar @0x800D5B50, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B51, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B52, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B54, len = 0x00000004
				{
					// uchar @0x800D5B54, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B55, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B56, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B58, len = 0x00000004
				{
					// uchar @0x800D5B58, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B59, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B5A, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B5C, len = 0x00000004
				{
					// uchar @0x800D5B5C, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B5D, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B5E, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B60, len = 0x00000004
				{
					// uchar @0x800D5B60, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B61, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B62, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B64, len = 0x00000004
				{
					// uchar @0x800D5B64, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B65, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B66, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B68, len = 0x00000004
				{
					// uchar @0x800D5B68, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B69, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B6A, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B6C, len = 0x00000004
				{
					// uchar @0x800D5B6C, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B6D, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B6E, len = 0x00000002
					.voiceCmdParam = null},
				// VoiceCommand @0x800D5B70, len = 0x00000004
				{
					// uchar @0x800D5B70, len = 0x00000001
					.voiceCmd = 0x00,
					// uchar @0x800D5B71, len = 0x00000001
					.nextVoiceStatus = 0x00,
					// ushort @0x800D5B72, len = 0x00000002
					.voiceCmdParam = null}},
		// uchar @0x800D5B74, len = 0x00000001
		.cdCmdIn = 0x00,
		// uchar @0x800D5B75, len = 0x00000001
		.cdCmdOut = 0x00,
		// uchar @0x800D5B76, len = 0x00000001
		.cdCmdsQueued = 0x00,
		// uchar @0x800D5B77, len = 0x00000001
		.reqIn = 0x00,
		// uchar @0x800D5B78, len = 0x00000001
		.reqOut = 0x00,
		// uchar @0x800D5B79, len = 0x00000001
		.reqsQueued = 0x00,
		// uchar @0x800D5B7A, len = 0x00000001
		.voiceCmdIn = 0x00,
		// uchar @0x800D5B7B, len = 0x00000001
		.voiceCmdOut = 0x00,
		// uchar @0x800D5B7C, len = 0x00000001
		.voiceCmdsQueued = 0x00,
		// uchar @0x800D5B7D, len = 0x00000001
		.unused1 = 0x00,
		// uchar @0x800D5B7E, len = 0x00000001
		.voiceStatus = 0x00,
		// uchar @0x800D5B7F, len = 0x00000001
		.cdStatus = 0x00,
		// short @0x800D5B80, len = 0x00000002
		.fileNum = null,
		// short @0x800D5B82, len = 0x00000002
		.unused2 = null,
		// XAFileInfo[30] @0x800D5B84, len = 0x00000078
		.xaFileInfo =
			{
				// XAFileInfo @0x800D5B84, len = 0x00000004
				{
					// int @0x800D5B84, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5B88, len = 0x00000004
				{
					// int @0x800D5B88, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5B8C, len = 0x00000004
				{
					// int @0x800D5B8C, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5B90, len = 0x00000004
				{
					// int @0x800D5B90, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5B94, len = 0x00000004
				{
					// int @0x800D5B94, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5B98, len = 0x00000004
				{
					// int @0x800D5B98, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5B9C, len = 0x00000004
				{
					// int @0x800D5B9C, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BA0, len = 0x00000004
				{
					// int @0x800D5BA0, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BA4, len = 0x00000004
				{
					// int @0x800D5BA4, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BA8, len = 0x00000004
				{
					// int @0x800D5BA8, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BAC, len = 0x00000004
				{
					// int @0x800D5BAC, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BB0, len = 0x00000004
				{
					// int @0x800D5BB0, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BB4, len = 0x00000004
				{
					// int @0x800D5BB4, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BB8, len = 0x00000004
				{
					// int @0x800D5BB8, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BBC, len = 0x00000004
				{
					// int @0x800D5BBC, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BC0, len = 0x00000004
				{
					// int @0x800D5BC0, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BC4, len = 0x00000004
				{
					// int @0x800D5BC4, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BC8, len = 0x00000004
				{
					// int @0x800D5BC8, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BCC, len = 0x00000004
				{
					// int @0x800D5BCC, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BD0, len = 0x00000004
				{
					// int @0x800D5BD0, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BD4, len = 0x00000004
				{
					// int @0x800D5BD4, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BD8, len = 0x00000004
				{
					// int @0x800D5BD8, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BDC, len = 0x00000004
				{
					// int @0x800D5BDC, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BE0, len = 0x00000004
				{
					// int @0x800D5BE0, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BE4, len = 0x00000004
				{
					// int @0x800D5BE4, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BE8, len = 0x00000004
				{
					// int @0x800D5BE8, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BEC, len = 0x00000004
				{
					// int @0x800D5BEC, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BF0, len = 0x00000004
				{
					// int @0x800D5BF0, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BF4, len = 0x00000004
				{
					// int @0x800D5BF4, len = 0x00000004
					.startPos = null},
				// XAFileInfo @0x800D5BF8, len = 0x00000004
				{
					// int @0x800D5BF8, len = 0x00000004
					.startPos = null}}};
// decompiled code
// original method signature:
// void /*$ra*/ VOICEXA_Init()
// line 54, offset 0x800b6e14
/* begin block 1 */
// Start line: 55
// Start offset: 0x800B6E14
// Variables:
// 		int i; // $s1
// 		struct CdlFILE fp; // stack offset -80
// 		struct XAVoiceTracker *vt; // $a0
// 		char fileName[32]; // stack offset -56
/* end block 1 */
// End offset: 0x800B6EC4
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
	undefined4 auStack80[6];
	char acStack56[32];

	pXVar3 = &voiceTracker;
	if ((gameTrackerX.debugFlags & 0x80000U) != 0)
	{
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
		do
		{
			sprintf(acStack56, s__VOICE_VOICE_02d_XA_1_800cf968);
			puVar1 = CdSearchFile(auStack80, acStack56);
			if (puVar1 == (undefined4 *)0x0)
			{
				pXVar3->xaFileInfo[0].startPos = 0;
			}
			else
			{
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
// line 98, offset 0x800b6ee0
/* begin block 1 */
// Start line: 99
// Start offset: 0x800B6EE0
// Variables:
// 		int i; // $t0
/* end block 1 */
// End offset: 0x800B6F5C
// End Line: 112

/* begin block 2 */
// Start line: 225
/* end block 2 */
// End Line: 226

/* begin block 3 */
// Start line: 228
/* end block 3 */
// End Line: 229

void putCdCommand(XAVoiceTracker *vt, uchar cdCommand, int numParams, uchar *params)

{
	uchar uVar1;
	uchar *puVar2;
	int iVar3;
	int iVar4;

	iVar3 = 0;
	vt->cdCmdQueue[(uint)vt->cdCmdIn].cdCommand = cdCommand;
	puVar2 = params;
	if (0 < numParams)
	{
		do
		{
			iVar4 = iVar3 + 1;
			vt->cdCmdQueue[(uint)vt->cdCmdIn].cdCmdParam[iVar3] = *puVar2;
			puVar2 = params + iVar4;
			iVar3 = iVar4;
		} while (iVar4 < numParams);
	}
	if (vt->cdCmdsQueued < 7)
	{
		vt->cdCmdsQueued = vt->cdCmdsQueued + 1;
		uVar1 = vt->cdCmdIn + '\x01';
		vt->cdCmdIn = uVar1;
		if (uVar1 == '\b')
		{
			vt->cdCmdIn = '\0';
		}
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VOICEXA_CdSyncCallback(unsigned char status /*$a0*/, unsigned char *result /*$a1*/)
// line 115, offset 0x800b6f64
/* begin block 1 */
// Start line: 116
// Start offset: 0x800B6F64
// Variables:
// 		struct XAVoiceTracker *vt; // $a1
/* end block 1 */
// End offset: 0x800B6FC0
// End Line: 137

/* begin block 2 */
// Start line: 263
/* end block 2 */
// End Line: 264

void VOICEXA_CdSyncCallback(uchar status, uchar *result)

{
	if (status == '\x02')
	{
		voiceTracker.cdStatus = '\0';
		voiceTracker.cdCmdOut = voiceTracker.cdCmdOut + '\x01';
		if (voiceTracker.cdCmdOut == '\b')
		{
			voiceTracker.cdCmdOut = '\0';
		}
		voiceTracker.cdCmdsQueued = voiceTracker.cdCmdsQueued + -1;
		CdSyncCallback(voiceTracker.prevCallback);
	}
	else
	{
		voiceTracker.cdStatus = '\x02';
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ processCdCommands(struct XAVoiceTracker *vt /*$s1*/)
// line 141, offset 0x800b6fd0
/* begin block 1 */
// Start line: 142
// Start offset: 0x800B6FD0
// Variables:
// 		struct CdCommand *cmd; // $s0
/* end block 1 */
// End offset: 0x800B7064
// End Line: 163

/* begin block 2 */
// Start line: 319
/* end block 2 */
// End Line: 320

void processCdCommands(XAVoiceTracker *vt)

{
	_func_134 *p_Var1;
	byte bVar2;
	CdCommand *pCVar3;

	if (vt->cdStatus == '\x02')
	{
		vt->cdStatus = '\x01';
		pCVar3 = vt->cdCmdQueue + (uint)vt->cdCmdOut;
		bVar2 = pCVar3->cdCommand;
	}
	else
	{
		if (vt->cdCmdsQueued == '\0')
		{
			return;
		}
		if (vt->cdStatus == '\x01')
		{
			return;
		}
		vt->cdStatus = '\x01';
		pCVar3 = vt->cdCmdQueue + (uint)vt->cdCmdOut;
		p_Var1 = (_func_134 *)CdSyncCallback(VOICEXA_CdSyncCallback);
		vt->prevCallback = p_Var1;
		bVar2 = pCVar3->cdCommand;
	}
	CdControl(bVar2, pCVar3->cdCmdParam, vt->cdResult);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ putVoiceCommand(struct XAVoiceTracker *vt /*$a0*/, unsigned char voiceCmd /*$a1*/, unsigned char nextVoiceStatus /*$a2*/, int voiceCmdParam /*$a3*/)
// line 186, offset 0x800b7078
/* begin block 1 */
// Start line: 414
/* end block 1 */
// End Line: 415

/* begin block 2 */
// Start line: 415
/* end block 2 */
// End Line: 416

void putVoiceCommand(XAVoiceTracker *vt, uchar voiceCmd, uchar nextVoiceStatus, int voiceCmdParam)

{
	uchar uVar1;

	vt->voiceCmdQueue[(uint)vt->voiceCmdIn].voiceCmd = voiceCmd;
	vt->voiceCmdQueue[(uint)vt->voiceCmdIn].nextVoiceStatus = nextVoiceStatus;
	vt->voiceCmdQueue[(uint)vt->voiceCmdIn].voiceCmdParam = (ushort)voiceCmdParam;
	if (vt->voiceCmdsQueued < 0xf)
	{
		vt->voiceCmdsQueued = vt->voiceCmdsQueued + 1;
		uVar1 = vt->voiceCmdIn + '\x01';
		vt->voiceCmdIn = uVar1;
		if (uVar1 == '\x10')
		{
			vt->voiceCmdIn = '\0';
		}
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ processVoiceCommands(struct XAVoiceTracker *vt /*$s1*/)
// line 203, offset 0x800b70f4
/* begin block 1 */
// Start line: 204
// Start offset: 0x800B70F4
// Variables:
// 		struct VoiceCommand *cmd; // $s0
/* end block 1 */
// End offset: 0x800B7190
// End Line: 221

/* begin block 2 */
// Start line: 449
/* end block 2 */
// End Line: 450

void processVoiceCommands(XAVoiceTracker *vt)

{
	uint uVar1;
	VoiceCommand *pVVar2;

	if (vt->voiceCmdsQueued != '\0')
	{
		vt->voiceCmdsQueued = vt->voiceCmdsQueued + -1;
		uVar1 = (uint)vt->voiceCmdOut + 1;
		pVVar2 = vt->voiceCmdQueue + (uint)vt->voiceCmdOut;
		vt->voiceCmdOut = (uchar)uVar1;
		if ((uVar1 & 0xff) == 0x10)
		{
			vt->voiceCmdOut = '\0';
		}
		if (pVVar2->voiceCmd < 5)
		{
			(*(code *)voiceCmdTbl[(uint)pVVar2->voiceCmd])(vt, (int)(short)pVVar2->voiceCmdParam);
			vt->voiceStatus = pVVar2->nextVoiceStatus;
		}
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ voiceCmdPlay(struct XAVoiceTracker *vt /*$s2*/, short voiceIndex /*$s3*/)
// line 226, offset 0x800b71a4
/* begin block 1 */
// Start line: 227
// Start offset: 0x800B71A4
// Variables:
// 		struct CdlFILTER filter; // stack offset -88
// 		struct CdlLOC pos; // stack offset -80
// 		unsigned char mode; // stack offset -32
// 		struct SpuCommonAttr spuattr; // stack offset -72
// 		struct XAVoiceListEntry *voice; // $s1
// 		struct XAFileInfo *file; // $s0
/* end block 1 */
// End offset: 0x800B72F8
// End Line: 299

/* begin block 2 */
// Start line: 499
/* end block 2 */
// End Line: 500

/* begin block 3 */
// Start line: 509
/* end block 3 */
// End Line: 510

void voiceCmdPlay(XAVoiceTracker *vt, short voiceIndex)

{
	ushort *puVar1;
	XAFileInfo *pXVar2;
	uchar local_58;
	byte local_57;
	uchar auStack80[8];
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
	uchar local_20[8];

	if (voiceList != (XAVoiceListEntry *)0x0)
	{
		puVar1 = &voiceList->length;
		vt->fileNum = voiceIndex >> 4;
		pXVar2 = vt->xaFileInfo + ((int)((uint)(ushort)voiceIndex << 0x10) >> 0x14);
		putCdCommand(vt, '\t', 0, (uchar *)0x0);
		local_58 = '\x01';
		local_57 = (byte)voiceIndex & 0xf;
		putCdCommand(vt, '\r', 4, &local_58);
		local_20[0] = -0x38;
		putCdCommand(vt, '\x0e', 1, local_20);
		CdIntToPos(pXVar2->startPos, (char *)vt);
		vt->endSector =
			pXVar2->startPos +
			((uint) * (ushort *)((int)puVar1 + ((int)((uint)(ushort)voiceIndex << 0x10) >> 0xf)) - 0x96);
		CdIntToPos(pXVar2->startPos, (char *)auStack80);
		putCdCommand(vt, '\x1b', 4, auStack80);
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
		if (0x3c < gameTrackerX.sound.gMusicVol)
		{
			aadStartMusicMasterVolFade(0x3c, -1, (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
		}
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ voiceCmdStop(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
// line 302, offset 0x800b7314
/* begin block 1 */
// Start line: 303
// Start offset: 0x800B7314
// Variables:
// 		struct SpuCommonAttr spuattr; // stack offset -48
/* end block 1 */
// End offset: 0x800B7360
// End Line: 318

/* begin block 2 */
// Start line: 713
/* end block 2 */
// End Line: 714

void voiceCmdStop(XAVoiceTracker *vt, short cmdParam)

{
	undefined *local_30[6];
	undefined4 local_18;
	undefined4 local_c;

	if (vt->voiceStatus != '\0')
	{
		putCdCommand(vt, '\t', 0, (uchar *)0x0);
		local_30[0] = &DAT_00002200;
		local_18 = 0;
		local_c = 0;
		SpuSetCommonAttr((uint *)local_30);
		aadStartMusicMasterVolFade(gameTrackerX.sound.gMusicVol, 1,
								   (TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)0x0);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ voiceCmdPause(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
// line 321, offset 0x800b7370
/* begin block 1 */
// Start line: 754
/* end block 1 */
// End Line: 755

void voiceCmdPause(XAVoiceTracker *vt, short cmdParam)

{
	if ((uint)vt->voiceStatus - 1 < 2)
	{
		putCdCommand(vt, '\t', 0, (uchar *)0x0);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ voiceCmdResume(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
// line 329, offset 0x800b73ac
/* begin block 1 */
// Start line: 770
/* end block 1 */
// End Line: 771

void voiceCmdResume(XAVoiceTracker *vt, short cmdParam)

{
	if (vt->voiceStatus == '\x03')
	{
		putCdCommand(vt, '\x1b', 4, (uchar *)vt);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ voiceCmdNull(struct XAVoiceTracker *vt /*$a0*/, short cmdParam /*$a1*/)
// line 336, offset 0x800b73e0
/* begin block 1 */
// Start line: 784
/* end block 1 */
// End Line: 785

/* begin block 2 */
// Start line: 785
/* end block 2 */
// End Line: 786

void voiceCmdNull(XAVoiceTracker *vt, short cmdParam)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VOICEXA_Play(int voiceIndex /*$a3*/, int queueRequests /*$a1*/)
// line 341, offset 0x800b73e8
/* begin block 1 */
// Start line: 342
// Start offset: 0x800B73E8
// Variables:
// 		struct XAVoiceTracker *vt; // $a0
// 		struct XAFileInfo *file; // $a2
/* end block 1 */
// End offset: 0x800B749C
// End Line: 368

/* begin block 2 */
// Start line: 794
/* end block 2 */
// End Line: 795

void VOICEXA_Play(int voiceIndex, int queueRequests)

{
	uchar uVar1;

	if ((((gameTrackerX.debugFlags & 0x80000U) != 0) &&
		 (voiceTracker.xaFileInfo[voiceIndex >> 4].startPos != 0)) &&
		(gameTrackerX.sound.gVoiceOn != '\0'))
	{
		if (queueRequests == 0)
		{
			putVoiceCommand(&voiceTracker, '\0', '\x01', voiceIndex);
		}
		else
		{
			voiceTracker.requestQueue[(uint)voiceTracker.reqIn] = (ushort)voiceIndex;
			uVar1 = voiceTracker.reqsQueued + '\x01';
			if (voiceTracker.reqsQueued < 3)
			{
				voiceTracker.reqIn = voiceTracker.reqIn + '\x01';
				voiceTracker.reqsQueued = uVar1;
				if (voiceTracker.reqIn == '\x04')
				{
					voiceTracker.reqIn = '\0';
					voiceTracker.reqsQueued = uVar1;
				}
			}
		}
	}
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ VOICEXA_FinalStatus(struct XAVoiceTracker *vt /*$a0*/)
// line 387, offset 0x800b74ac
/* begin block 1 */
// Start line: 389
// Start offset: 0x800B74AC
// Variables:
// 		int tailIndex; // $v0
/* end block 1 */
// End offset: 0x800B74E8
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

	if (vt->voiceCmdsQueued == '\0')
	{
		return (uint)vt->voiceStatus;
	}
	iVar1 = (uint)vt->voiceCmdIn - 1;
	if (vt->voiceCmdIn == 0)
	{
		iVar1 = 0xf;
	}
	return (uint)vt->voiceCmdQueue[iVar1].nextVoiceStatus;
}

// decompiled code
// original method signature:
// void /*$ra*/ VOICEXA_Pause()
// line 406, offset 0x800b74f0
/* begin block 1 */
// Start line: 407
// Start offset: 0x800B74F0
// Variables:
// 		struct XAVoiceTracker *vt; // $s0
// 		int finalStatus; // $a0
/* end block 1 */
// End offset: 0x800B7550
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
	if ((gameTrackerX.debugFlags & 0x80000U) != 0)
	{
		voiceCmd = '\x02';
		if (iVar1 - 1U < 2)
		{
			nextVoiceStatus = '\x03';
		}
		else
		{
			if (iVar1 != 0)
			{
				return;
			}
			voiceCmd = '\x04';
			nextVoiceStatus = '\x04';
		}
		putVoiceCommand(&voiceTracker, voiceCmd, nextVoiceStatus, 0);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VOICEXA_Resume()
// line 427, offset 0x800b7560
/* begin block 1 */
// Start line: 428
// Start offset: 0x800B7560
// Variables:
// 		struct XAVoiceTracker *vt; // $s0
// 		int finalStatus; // $a0
/* end block 1 */
// End offset: 0x800B75C0
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
	if ((gameTrackerX.debugFlags & 0x80000U) != 0)
	{
		voiceCmd = '\x03';
		if (iVar1 == 3)
		{
			nextVoiceStatus = '\x01';
		}
		else
		{
			if (iVar1 != 4)
			{
				return;
			}
			voiceCmd = '\x04';
			nextVoiceStatus = '\0';
		}
		putVoiceCommand(&voiceTracker, voiceCmd, nextVoiceStatus, 0);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VOICEXA_Tick()
// line 464, offset 0x800b75d0
/* begin block 1 */
// Start line: 465
// Start offset: 0x800B75D0
// Variables:
// 		struct XAVoiceTracker *vt; // $s0
/* end block 1 */
// End offset: 0x800B7718
// End Line: 529

/* begin block 2 */
// Start line: 1027
/* end block 2 */
// End Line: 1028

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VOICEXA_Tick(void)

{
	if ((gameTrackerX.debugFlags & 0x80000U) != 0)
	{
		processVoiceCommands(&voiceTracker);
		processCdCommands(&voiceTracker);
		if (((voiceTracker.cdCmdsQueued == '\0') && (voiceTracker.voiceCmdsQueued == '\0')) &&
			(voiceTracker.voiceStatus < 3))
		{
			if (voiceTracker.voiceStatus == '\0')
			{
				if (voiceTracker.reqsQueued != '\0')
				{
					putVoiceCommand(&voiceTracker, '\0', '\x01',
									(uint)voiceTracker.requestQueue[(uint)voiceTracker.reqOut]);
					voiceTracker.reqsQueued = voiceTracker.reqsQueued + -1;
					voiceTracker.reqOut = voiceTracker.reqOut + '\x01';
					if (voiceTracker.reqOut == '\x04')
					{
						voiceTracker.reqOut = '\0';
					}
				}
			}
			else
			{
				CdControlB(0x10, (undefined *)0x0, voiceTracker.cdResult);
				if ((voiceTracker.cdResult[3] & 2) != 0)
				{
					voiceTracker.voiceStatus = '\x02';
					voiceTracker.currentPos.track = '\0';
					voiceTracker.currentPos.minute = voiceTracker.cdResult[0];
					voiceTracker.currentPos.second = voiceTracker.cdResult[1];
					voiceTracker.currentPos.sector = voiceTracker.cdResult[2];
					voiceTracker.currentSector = CdPosToInt((byte *)&voiceTracker);
					voiceTracker.currentSector = voiceTracker.currentSector + -0x96;
					if (voiceTracker.endSector + -8 <= voiceTracker.currentSector)
					{
						putVoiceCommand(&voiceTracker, '\x01', '\0', 0);
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
// line 546, offset 0x800b7728
/* begin block 1 */
// Start line: 548
// Start offset: 0x800B7728
// Variables:
// 		struct XAVoiceTracker *vt; // $a0
/* end block 1 */
// End offset: 0x800B7760
// End Line: 557

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
		((voiceTracker.voiceStatus == '\x01' || (iVar1 = 0, voiceTracker.cdStatus != '\0'))))
	{
		return 1;
	}
	return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ VOICEXA_IsPlayingOrPaused()
// line 559, offset 0x800b7768
/* begin block 1 */
// Start line: 561
// Start offset: 0x800B7768
/* end block 1 */
// End offset: 0x800B7768
// End Line: 564

/* begin block 2 */
// Start line: 1221
/* end block 2 */
// End Line: 1222

/* begin block 3 */
// Start line: 1222
/* end block 3 */
// End Line: 1223

/* begin block 4 */
// Start line: 1225
/* end block 4 */
// End Line: 1226

/* WARNING: Unknown calling convention yet parameter storage is locked */

int VOICEXA_IsPlayingOrPaused(void)

{
	return (uint)((voiceTracker._168_4_ & 0xffff0000) != 0);
}
