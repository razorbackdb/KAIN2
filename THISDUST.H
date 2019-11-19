#ifndef THISDUST_H
#define THISDUST_H


extern void FUN_80077bd4(void);; // 0x80077BD4

extern void ResetCallback(void);; // 0x800B40E4

extern void InterruptCallback(uint param_1,int param_2);; // 0x800B4114

extern void DMACallback(void);; // 0x800B4144

extern void VSyncCallback(undefined4 param_1);; // 0x800B4174

extern void VSyncCallbacks(void);; // 0x800B41A8

extern void StopCallback(void);; // 0x800B41D8

extern uint CheckCallback(void);; // 0x800B4208

extern uint SetIntrMask(word param_1);; // 0x800B4218

extern undefined2 * FUN_800b4230(void);; // 0x800B4230

extern void FUN_800b4308(void);; // 0x800B4308

extern int FUN_800b44d8(uint param_1,int param_2);; // 0x800B44D8

extern undefined2 * FUN_800b4620(void);; // 0x800B4620

extern undefined2 * FUN_800b46c0(void);; // 0x800B46C0

extern void FUN_800b4738(undefined4 *param_1,int param_2);; // 0x800B4738

extern short * RotMatrixZ(uint param_1,short *param_2);; // 0x800B475C

extern int strncmp(char *__s1,char *__s2,size_t __n);; // 0x800B48FC

extern uint ResetGraph(uint param_1);; // 0x800B497C

extern uint SetGraphDebug(char param_1);; // 0x800B4AF0

extern undefined4 DrawSyncCallback(undefined4 param_1);; // 0x800B4B4C

extern void SetDispMask(int param_1);; // 0x800B4BAC

extern void DrawSync(int param_1);; // 0x800B4C44

extern void FUN_800b4cac(undefined4 param_1,short *param_2);; // 0x800B4CAC

extern void ClearImage(undefined4 *param_1,uint param_2,uint param_3,uint param_4);; // 0x800B4DC8

extern void LoadImage(undefined4 *param_1,undefined4 param_2);; // 0x800B4E58

extern uint MoveImage(undefined4 *param_1,uint param_2,int param_3);; // 0x800B4EB8

extern void ClearOTagR(undefined4 *param_1,dword param_2);; // 0x800B4F70

extern void DrawPrim(int param_1);; // 0x800B501C

extern void DrawOTag(undefined4 *param_1);; // 0x800B5078

extern undefined4 * PutDrawEnv(undefined4 *param_1);; // 0x800B50E8

extern ushort * PutDispEnv(ushort *param_1);; // 0x800B51A8

extern void SetDrawArea(int param_1,ushort *param_2);; // 0x800B56A0

extern void SetDrawStp(int param_1,int param_2);; // 0x800B5720

extern void SetDrawEnv(int param_1,ushort *param_2);; // 0x800B5748

extern void FUN_800b5940(int param_1,undefined4 *param_2);; // 0x800B5940

extern uint FUN_800b5bb0(int param_1,int param_2,uint param_3);; // 0x800B5BB0

extern uint FUN_800b5bd0(uint param_1,uint param_2);; // 0x800B5BD0

extern uint FUN_800b5c68(uint param_1,uint param_2);; // 0x800B5C68

extern uint FUN_800b5d00(uint param_1,uint param_2);; // 0x800B5D00

extern uint FUN_800b5d1c(byte *param_1);; // 0x800B5D1C

extern dword FUN_800b5db4(int param_1,dword param_2);; // 0x800B5DB4

extern undefined4 FUN_800b5e94(undefined4 *param_1,uint param_2);; // 0x800B5E94

extern undefined4 FUN_800b60c4(int param_1,dword *param_2);; // 0x800B60C4

extern undefined4 FUN_800b6300(int param_1,dword *param_2);; // 0x800B6300

extern void FUN_800b6580(uint param_1);; // 0x800B6580

extern undefined4 FUN_800b65b8(dword *param_1,int param_2);; // 0x800B65B8

extern void FUN_800b65f8(dword param_1);; // 0x800B65F8

extern uint FUN_800b6640(uint param_1);; // 0x800B6640

extern void FUN_800b6670(undefined *param_1,undefined4 *param_2,undefined4 param_3);; // 0x800B6670

extern uint FUN_800b6694(undefined *param_1,undefined4 *param_2,int param_3,undefined4 param_4);; // 0x800B6694

extern uint FUN_800b6944(void);; // 0x800B6944

extern undefined4 FUN_800b6ba4(uint param_1);; // 0x800B6BA4

extern uint FUN_800b6cf4(int param_1);; // 0x800B6CF4

extern void FUN_800b6e30(void);; // 0x800B6E30

extern undefined4 FUN_800b6e64(void);; // 0x800B6E64

extern undefined8 FUN_800b6fa8(uint param_1);; // 0x800B6FA8

extern void FUN_800b7144(void);; // 0x800B7144

extern void FUN_800b716c(undefined *param_1,undefined param_2,int param_3);; // 0x800B716C

extern undefined4 * ApplyMatrix(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3);; // 0x800B7198

extern void * memset(void *__s,int __c,size_t __n);; // 0x800B71E8

extern int rand(void);; // 0x800B7218

extern void srand(uint __seed);; // 0x800B7248

extern void SetTransMatrix(int param_1);; // 0x800B7258

extern void SetRotMatrix(undefined4 *param_1);; // 0x800B7278

extern void SetDefDrawEnv(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,int param_5);; // 0x800B72A8

extern void SetDefDispEnv(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5);; // 0x800B735C

extern int RotMatrixX(uint param_1,int param_2);; // 0x800B7398

extern short * RotMatrixY(uint param_1,short *param_2);; // 0x800B7538

extern void SetGeomScreen(undefined4 param_1);; // 0x800B76D8

extern undefined2 * ApplyMatrixSV(undefined4 *param_1,undefined4 *param_2,undefined2 *param_3);; // 0x800B76E8

extern int ratan2(uint param_1,uint param_2);; // 0x800B7748

extern undefined4 LoadAverageShort12(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4,uint *param_5);; // 0x800B78C8

extern undefined4 LoadAverageCol(byte *param_1,byte *param_2,undefined4 param_3,undefined4 param_4,undefined *param_5);; // 0x800B7950

extern void SetFogNearFar(int param_1,int param_2,int param_3);; // 0x800B79D0

extern char * strchr(char *__s,int __c);; // 0x800B7AE0

extern char * strcpy(char *__dest,char *__src);; // 0x800B7B20

extern int * ApplyMatrixLV(undefined4 *param_1,uint *param_2,int *param_3);; // 0x800B7B70

extern undefined4 * TransposeMatrix(undefined4 *param_1,undefined4 *param_2);; // 0x800B7CD0

extern void RotTrans(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3);; // 0x800B7D10

extern void SetPolyFT4(int param_1);; // 0x800B7D40

extern size_t strlen(char *__s);; // 0x800B7D60

extern void SetFarColor(int param_1,int param_2,int param_3);; // 0x800B7DA0

extern undefined4 SetRCnt(uint param_1,undefined2 param_2,uint param_3);; // 0x800B7DC0

extern uint GetRCnt(uint param_1);; // 0x800B7E5C

extern uint StartRCnt(uint param_1);; // 0x800B7E94

extern undefined4 StopRCnt(uint param_1);; // 0x800B7EC4

extern void PadInitDirect(undefined4 param_1,undefined4 param_2);; // 0x800B7EF8

extern void FUN_800b81b4(int param_1);; // 0x800B81B4

extern char * strpbrk(char *__s,char *__accept);; // 0x800B8558

extern void PadStartCom(void);; // 0x800B85C8

extern void PadStopCom(void);; // 0x800B85E8

extern uint PadGetState(void);; // 0x800B8608

extern uint PadInfoAct(undefined4 param_1,int param_2,undefined4 param_3);; // 0x800B86C8

extern void PadSetActAlign(undefined4 param_1,undefined4 param_2);; // 0x800B879C

extern void PadSetAct(undefined4 param_1,undefined4 param_2,undefined param_3);; // 0x800B87D4

extern uint VSync(int param_1);; // 0x800B8824

extern void FUN_800b899c(int param_1,int param_2);; // 0x800B899C

extern int strcmp(char *__s1,char *__s2);; // 0x800B8A34

extern void SetLightMatrix(undefined4 *param_1);; // 0x800B8AA4

extern void SetBackColor(int param_1,int param_2,int param_3);; // 0x800B8AD4

extern void SetColorMatrix(undefined4 *param_1);; // 0x800B8AF4

extern uint * MulMatrix0(undefined4 *param_1,ushort *param_2,uint *param_3);; // 0x800B8B24

extern uint CdStatus(void);; // 0x800B8C34

extern uint CdMode(void);; // 0x800B8C44

extern undefined1 * CdLastPos(void);; // 0x800B8C54

extern undefined4 CdReset(int param_1);; // 0x800B8C60

extern void CdFlush(void);; // 0x800B8CCC

extern undefined4 CdSetDebug(undefined4 param_1);; // 0x800B8CEC

extern void CdSync(int param_1,undefined *param_2);; // 0x800B8D00

extern void CdReady(int param_1,undefined *param_2);; // 0x800B8D20

extern undefined4 CdSyncCallback(undefined4 param_1);; // 0x800B8D40

extern undefined4 CdReadyCallback(undefined4 param_1);; // 0x800B8D54

extern undefined4 CdControl(byte param_1,byte *param_2,undefined *param_3);; // 0x800B8D68

extern undefined4 CdControlF(byte param_1,byte *param_2);; // 0x800B8EA4

extern uint CdControlB(byte param_1,byte *param_2,undefined *param_3);; // 0x800B8FD8

extern uint CdGetSector(dword param_1,uint param_2);; // 0x800B9124

extern uint CdGetSector2(dword param_1,uint param_2);; // 0x800B9144

extern void CdDataCallback(void);; // 0x800B9164

extern void CdDataSync(int param_1);; // 0x800B9188

extern void CdIntToPos(int param_1,char *param_2);; // 0x800B91A8

extern int CdPosToInt(byte *param_1);; // 0x800B92AC

extern undefined4 CdInit(void);; // 0x800B932C

extern uint FUN_800b93bc(void);; // 0x800B93BC

extern void FUN_800b93f8(void);; // 0x800B93F8

extern void FUN_800b9420(void);; // 0x800B9420

extern void FUN_800b9448(void);; // 0x800B9448

extern undefined4 * CdSearchFile(undefined4 *param_1,char *param_2);; // 0x800B947C

extern uint FUN_800b9754(char *param_1,char *param_2);; // 0x800B9754

extern undefined4 FUN_800b9774(void);; // 0x800B9774

extern int FUN_800b9a38(int param_1,char *param_2);; // 0x800B9A38

extern undefined4 FUN_800b9adc(int param_1);; // 0x800B9ADC

extern uint FUN_800b9d78(undefined4 param_1,int param_2,undefined4 param_3);; // 0x800B9D78

extern void ExitCriticalSection(void);; // 0x800B9DEC

extern int SpuIsTransferCompleted(int param_1);; // 0x800B9DFC

extern void EnterCriticalSection(void);; // 0x800B9EAC

extern void SetGeomOffset(int param_1,int param_2);; // 0x800B9EBC

extern uint InitGeom(void);; // 0x800B9EE4

extern void EnableEvent(void);; // 0x800B9F6C

extern void StopPAD(void);; // 0x800B9F8C

extern undefined4 FUN_800b9fc4(void);; // 0x800B9FC4

extern undefined4 FUN_800ba03c(void);; // 0x800BA03C

extern undefined4 FUN_800ba074(void);; // 0x800BA074

extern void OpenEvent(void);; // 0x800BA120

extern void DisableEvent(void);; // 0x800BA130

extern void CloseEvent(void);; // 0x800BA140

extern uint * MulMatrix2(undefined4 *param_1,uint *param_2);; // 0x800BA150

extern uint * CompMatrix(undefined4 *param_1,ushort *param_2,uint *param_3);; // 0x800BA260

extern int TransMatrix(int param_1,undefined4 *param_2);; // 0x800BA3C0

extern uint GetTPage(uint param_1,uint param_2,uint param_3,uint param_4);; // 0x800BA3F0

extern void PushMatrix(void);; // 0x800BA430

extern void PopMatrix(void);; // 0x800BA4D4

extern int puts(char *__s);; // 0x800BA580

extern char * strncpy(char *__dest,char *__src,size_t __n);; // 0x800BA5E0

extern int SpuSetTransferStartAddr(uint param_1);; // 0x800BA650

extern uint SpuWrite(word *param_1,uint param_2,uint param_3);; // 0x800BA6B0

extern void SpuSetReverbModeDepth(word param_1,word param_2);; // 0x800BA710

extern void SpuGetVoicePitch(int param_1,word *param_2);; // 0x800BA740

extern void SpuSetVoicePitch(int param_1,word param_2);; // 0x800BA760

extern void SpuSetCommonCDMix(int param_1);; // 0x800BA7D0

extern void SpuSetKey(int param_1,uint param_2);; // 0x800BA810

extern void SpuGetAllKeysStatus(undefined *param_1);; // 0x800BA9D0

extern undefined4 SpuClearReverbWorkArea(uint param_1,undefined4 param_2,uint param_3);; // 0x800BAA5C

extern void SpuSetCommonMasterVolume(undefined4 param_1,undefined4 param_2);; // 0x800BABFC

extern void SpuSetTransferCallback(int param_1);; // 0x800BAC1C

extern void SpuSetReverbVoice(int param_1,uint param_2);; // 0x800BAC4C

extern int SpuSetReverb(int param_1);; // 0x800BAC7C

extern void SpuInit(void);; // 0x800BAD4C

extern undefined4 GetGp(void);; // 0x800BAD6C

extern void SpuQuit(void);; // 0x800BAD7C

extern undefined4 SpuSetReverbModeType(uint param_1);; // 0x800BADFC

extern void SpuSetVoiceVolume(int param_1,undefined4 param_2,undefined4 param_3);; // 0x800BAFCC

extern void SpuSetVoiceStartAddr(int param_1,uint param_2);; // 0x800BB04C

extern void SpuSetVoiceADSRAttr(int param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8,int param_9);; // 0x800BB0CC

extern int memcmp(byte *param_1,byte *param_2,int param_3);; // 0x800BB20C

extern int FUN_800bb228(byte *param_1,byte *param_2,int param_3);; // 0x800BB228

extern dword BreakDraw(void);; // 0x800BB25C

extern void * memmove(void *__dest,void *__src,size_t __n);; // 0x800BB2F0

extern void InitHeap(void);; // 0x800BB360

extern void SpuSetCommonAttr(uint *param_1);; // 0x800BB370

extern void FlushCache(void);; // 0x800BB6F0

extern char * strtok(char *__s,char *__delim);; // 0x800BB700

extern void StCdInterrupt(void);; // 0x800BB820

extern void FUN_800bc13c(undefined4 *param_1,undefined4 *param_2,uint param_3);; // 0x800BC13C

extern void FUN_800bc168(uint param_1,dword param_2,int param_3,uint param_4,dword param_5,char param_6);; // 0x800BC168

extern void StClearRing(void);; // 0x800BC310

extern void StUnSetRing(void);; // 0x800BC370

extern void CdRead2(uint param_1);; // 0x800BC3F0

extern void FUN_800bc474(void);; // 0x800BC474

extern void StSetStream(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);; // 0x800BC4A0

extern void StSetMask(undefined4 param_1,undefined4 param_2,undefined4 param_3);; // 0x800BC530

extern void StSetRing(undefined4 param_1,undefined4 param_2);; // 0x800BC550

extern void data_ready_callback(void);; // 0x800BC640

extern undefined4 StGetBackloc(char *param_1);; // 0x800BC6CC

extern void SpuInitHot(void);; // 0x800BC7E0

extern int setjmp(__jmp_buf_tag *__env);; // 0x800BC800

extern void HookEntryInt(void);; // 0x800BC83C

extern undefined * startIntrVSync(void);; // 0x800BC84C

extern void FUN_800bc8a4(void);; // 0x800BC8A4

extern void FUN_800bc93c(undefined4 *param_1,int param_2);; // 0x800BC93C

extern undefined * startIntrDMA(void);; // 0x800BC96C

extern void FUN_800bc9b8(void);; // 0x800BC9B8

extern void FUN_800bcbe4(undefined4 *param_1,int param_2);; // 0x800BCBE4

extern void _96_remove(void);; // 0x800BCC14

extern void ReturnFromException(void);; // 0x800BCC2C

extern void ChangeClearPAD(void);; // 0x800BCC3C

extern void ChangeClearRCnt(void);; // 0x800BCC4C

extern void ResetEntryInt(void);; // 0x800BCC5C

extern void GPU_cw(void);; // 0x800BCC6C

extern undefined4 GetVideoMode(void);; // 0x800BCC7C

extern void SetDQA(undefined4 param_1);; // 0x800BCC98

extern void SetDQB(undefined4 param_1);; // 0x800BCCA4

extern void _padSetVsyncParam(void);; // 0x800BCCB0

extern undefined4 FUN_800bccdc(void);; // 0x800BCCDC

extern undefined4 FUN_800bcd44(void);; // 0x800BCD44

extern void _padStartCom(void);; // 0x800BCEB0

extern void _padStopCom(void);; // 0x800BCF7C

extern undefined4 _padInitSioMode(int param_1);; // 0x800BCFC0

extern void FUN_800bd2f4(void);; // 0x800BD2F4

extern uint _padSioRW(int param_1,int param_2);; // 0x800BD3BC

extern uint _padSioRW2(int param_1,undefined param_2);; // 0x800BD594

extern undefined4 _padClrIntSio0(void);; // 0x800BD7CC

extern void _padWaitRXready(void);; // 0x800BD85C

extern void _padInitDirSeq(void);; // 0x800BD884

extern undefined4 FUN_800bd8b8(int param_1);; // 0x800BD8B8

extern void FUN_800bd9b8(int *param_1);; // 0x800BD9B8

extern void _dirFailAuto(int param_1);; // 0x800BDC08

extern undefined4 FUN_800bdce4(int param_1);; // 0x800BDCE4

extern void bzero(void *__s,size_t __n);; // 0x800BDD14

extern void _padSetAct(int param_1,undefined4 param_2,undefined param_3);; // 0x800BDD44

extern void _padSendAtLoadInfo(int param_1);; // 0x800BDD50

extern undefined4 _padRecvAtLoadInfo(int *param_1);; // 0x800BDDD4

extern int _padGetActSize(int param_1);; // 0x800BDF20

extern undefined4 _padLoadActInfo(int *param_1,int param_2);; // 0x800BDF58

extern void FUN_800be02c(int param_1);; // 0x800BE02C

extern uint _padSetActAlign(int param_1,undefined4 param_2);; // 0x800BE348

extern void _padCmdParaMode(int param_1,undefined param_2);; // 0x800BE494

extern void FUN_800be4b4(int param_1);; // 0x800BE4B4

extern void FUN_800be4c8(int param_1,undefined param_2);; // 0x800BE4C8

extern void FUN_800be4e8(int param_1,undefined param_2);; // 0x800BE4E8

extern void FUN_800be508(int param_1,undefined param_2);; // 0x800BE508

extern void FUN_800be528(int param_1);; // 0x800BE528

extern undefined4 FUN_800be548(void);; // 0x800BE548

extern uint CD_sync(int param_1,undefined *param_2);; // 0x800BEAA4

extern uint CD_ready(int param_1,undefined *param_2);; // 0x800BED24

extern undefined4 CD_cw(byte param_1,byte *param_2,undefined *param_3,int param_4);; // 0x800BEFEC

extern void CD_flush(void);; // 0x800BF3F8

extern undefined4 CD_initvol(void);; // 0x800BF4CC

extern void CD_initintr(void);; // 0x800BF5BC

extern undefined4 CD_init(void);; // 0x800BF608

extern undefined4 CD_datasync(int param_1);; // 0x800BF7E8

extern undefined4 CD_getsector(dword param_1,uint param_2);; // 0x800BF950

extern undefined4 CD_getsector2(dword param_1,uint param_2);; // 0x800BFA50

extern void FUN_800bfb48(void);; // 0x800BFB48

extern void DeliverEvent(void);; // 0x800BFC20

extern undefined4 FUN_800bff7c(int param_1);; // 0x800BFF7C

extern uint CdRead(undefined4 param_1,undefined4 param_2,uint param_3);; // 0x800C0164

extern int CdReadSync(int param_1,undefined *param_2);; // 0x800C0264

extern void _SpuInit(int param_1);; // 0x800C032C

extern void SpuStart(void);; // 0x800C0414

extern undefined4 _spu_init(int param_1);; // 0x800C048C

extern void FUN_800c070c(word *param_1,uint param_2);; // 0x800C070C

extern void _spu_FiDMA(void);; // 0x800C08CC

extern undefined4 _spu_t(int param_1,uint param_2,uint param_3);; // 0x800C0988

extern uint _spu_Fw(word *param_1,uint param_2,uint param_3);; // 0x800C0C08

extern void _spu_FsetRXX(int param_1,uint param_2,int param_3);; // 0x800C0C8C

extern uint _spu_FsetRXXa(int param_1,uint param_2);; // 0x800C0CD0

extern void FUN_800c0dcc(void);; // 0x800C0DCC

extern void FUN_800c0df4(void);; // 0x800C0DF4

extern void _spu_Fw1ts(void);; // 0x800C0E1C

extern void TestEvent(void);; // 0x800C0E84

extern void _patch_gte(void);; // 0x800C0E94

extern void DisablePAD(void);; // 0x800C0F74

extern void StopPAD2(void);; // 0x800C0F88

extern void SysDeqIntRP(void);; // 0x800C0F98

extern void SysEnqIntRP(void);; // 0x800C0FA8

extern int _putchar(int __c);; // 0x800C0FB8

extern void _putchar_flash(void);; // 0x800C10B4

extern undefined4 _SpuIsInAllocateArea_(int param_1);; // 0x800C10F0

extern void WaitEvent(void);; // 0x800C1180

extern uint _SpuSetAnyVoice(int param_1,uint param_2,int param_3,int param_4);; // 0x800C1190

extern void _SpuDataCallback(void);; // 0x800C1450

extern void _spu_setReverbAttr(uint *param_1);; // 0x800C1480

extern char * strcat(char *__dest,char *__src);; // 0x800C1950

extern int open(char *__file,int __oflag,...);; // 0x800C1A00

extern int close(int __fd);; // 0x800C1A10

extern __off_t lseek(int __fd,__off_t __offset,int __whence);; // 0x800C1A20

extern ssize_t read(int __fd,void *__buf,size_t __nbytes);; // 0x800C1A30

extern ssize_t write(int __fd,void *__buf,size_t __n);; // 0x800C1A40

extern void FUN_800c1bec(int *param_1,undefined4 param_2,undefined4 param_3);; // 0x800C1BEC

extern void init_ring_status(int param_1,uint param_2);; // 0x800C1D20

extern undefined4 DsReadyCallback(undefined4 param_1);; // 0x800C1D60

extern void DsDataCallback(void);; // 0x800C1D74

extern void setRC2wait(undefined4 param_1);; // 0x800C1D98

extern uint chkRC2wait(void);; // 0x800C1DB8

extern void FUN_800c1e58(int param_1);; // 0x800C1E58

extern uint FUN_800c1f78(int param_1);; // 0x800C1F78

extern uint FUN_800c2038(int param_1);; // 0x800C2038

extern uint FUN_800c20c4(int param_1);; // 0x800C20C4

extern void firstfile2(void);; // 0x800C2458

extern void FUN_800c727c(void);; // 0x800C727C

extern void FUN_800c72b4(void);; // 0x800C72B4

extern void FUN_800c732c(void);; // 0x800C732C

extern void FUN_800c7364(undefined4 param_1,uint param_2);; // 0x800C7364

extern void FUN_800c73e4(void);; // 0x800C73E4

extern void FUN_800c7420(void);; // 0x800C7420

extern void FUN_800c74a4(void);; // 0x800C74A4

extern void FUN_800c74e4(void);; // 0x800C74E4

extern void FUN_800c7530(void);; // 0x800C7530

extern void FUN_800c7570(void);; // 0x800C7570

extern void FUN_800c7600(void);; // 0x800C7600

extern void FUN_800c7694(void);; // 0x800C7694

extern void FUN_800c772c(void);; // 0x800C772C

extern void FUN_800c7784(void);; // 0x800C7784

extern void FUN_800c7824(void);; // 0x800C7824

extern void FUN_800c78c8(void);; // 0x800C78C8

extern void FUN_800c7920(void);; // 0x800C7920

extern void FUN_800c7a2c(void);; // 0x800C7A2C

extern void FUN_800c7a8c(void);; // 0x800C7A8C

extern void FUN_800c7aec(void);; // 0x800C7AEC

extern void FUN_800c7b4c(void);; // 0x800C7B4C

extern void FUN_800cba6e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);; // 0x800CBA6E

extern void FUN_800cba9e(undefined4 param_1,undefined4 param_2,undefined4 param_3);; // 0x800CBA9E

extern void FUN_800cbace(undefined4 param_1,undefined4 param_2,undefined4 param_3);; // 0x800CBACE

extern void FUN_800cbafe(void);; // 0x800CBAFE

extern void FUN_800cbb52(void);; // 0x800CBB52

extern void FUN_800cbb7e(void);; // 0x800CBB7E

extern void FUN_800cbbaa(void);; // 0x800CBBAA

extern void FUN_800cbbf6(void);; // 0x800CBBF6

extern void FUN_800cbc3e(void);; // 0x800CBC3E

extern void FUN_800cbc62(void);; // 0x800CBC62

extern void FUN_800cbca2(void);; // 0x800CBCA2

extern void FUN_800cbcde(void);; // 0x800CBCDE

extern void FUN_800cbd1a(void);; // 0x800CBD1A

extern void FUN_800cbd32(void);; // 0x800CBD32

extern void FUN_800cbd4a(void);; // 0x800CBD4A

extern void FUN_800cbd62(void);; // 0x800CBD62

extern void FUN_800cc02c(void);; // 0x800CC02C

extern void FUN_800cc08c(void);; // 0x800CC08C

extern void FUN_800cc0ec(void);; // 0x800CC0EC

extern void FUN_800cc19c(void);; // 0x800CC19C

extern void FUN_800cc1f8(void);; // 0x800CC1F8

extern void _spu_voice_centerNote(void);; // 0x800CC2F4

extern void FUN_800cc394(void);; // 0x800CC394

extern void FUN_800cc3ec(void);; // 0x800CC3EC

extern void FUN_800cc484(void);; // 0x800CC484

extern void FUN_800cc518(void);; // 0x800CC518

extern void FUN_800cc5a8(void);; // 0x800CC5A8

extern void FUN_800cc5e8(void);; // 0x800CC5E8

extern void FUN_800cc634(void);; // 0x800CC634

extern void FUN_800cc674(void);; // 0x800CC674

extern void FUN_800cc6f8(void);; // 0x800CC6F8

extern void FUN_800cc734(void);; // 0x800CC734

extern void FUN_800cc7b4(void);; // 0x800CC7B4

extern void FUN_800cc7ec(void);; // 0x800CC7EC

extern void FUN_800cc864(undefined4 param_1,uint param_2);; // 0x800CC864

extern void FUN_800cc89c(void);; // 0x800CC89C

extern void FUN_800ce8c8(void);; // 0x800CE8C8


static unsigned short __currentData; // offset 0x800CE59C

static unsigned short __dataCount; // offset 0x800CE59E

static unsigned short *__demoBuffer; // offset 0x800CE5A4

static unsigned short *__demoBufferStart; // offset 0x800CE5A0

static unsigned long __hblankEvent; // offset 0x800D2A30

extern unsigned long __timerEvent; // offset 0x800D1F94

static struct _G2AppDataVM_Type _appDataVM; // offset 0x800D55C4

static struct _G2AnimChanStatusBlockPool_Type _chanStatusBlockPool; // offset 0x800D4E14

static struct _G2AnimControllerPool_Type _controllerPool; // offset 0x800D55A4

static int _indexTable[16]; // offset 0x800C5CDC

static struct _G2AnimInterpStateBlockPool_Type _interpStateBlockPool; // offset 0x800D55B4

extern int _ramsize; // offset 0x800CEAD0

static struct _G2AnimSegValue_Type _segValues[80]; // offset 0x800D4E24

extern int _stacksize; // offset 0x800CEAD4

static int _stepSizeTable[64]; // offset 0x800C5D1C

static struct AadProgramAtr aadDummySfxProgram; // offset 0x800CF788

extern unsigned long aadGp; // offset 0x800C594C

static unsigned short aadHblanksPerUpdate[4]; // offset 0x800CF580

extern struct AadMemoryStruct *aadMem; // offset 0x800CF598

extern unsigned short aadPitchTable[85]; // offset 0x800CF790

static unsigned long aadReverbModeSize[10]; // offset 0x800CF5A4

extern unsigned long aadStepsPerCent[85]; // offset 0x800CF83C

extern short aadStepsPerSemitone[85]; // offset 0x800CF990

static unsigned long aadUpdateRate[4]; // offset 0x800CF588

static long ACE_amount; // offset 0x800D0EE0

extern struct DebugMenuLine AIMenu[6]; // offset 0x800C34B8

static int AlgoControlFlag; // offset 0x800D06EC

static short align_flag; // offset 0x800CE5A8

extern struct DebugMenuLine AlukaMenu[10]; // offset 0x800C3548

extern struct DebugMenuLine AnteRoomsMenu[8]; // offset 0x800C4340

extern struct DebugMenuLine AshVillageMenu[7]; // offset 0x800C3638

extern int AutoFaceAngle; // offset 0x800D5D20

extern short AXIS_LENGTH; // offset 0x800CDCA4

extern struct _ButtonTexture BexitLine[2]; // offset 0x800D1E30

static int blast_range; // offset 0x800D4D90

static int BlockCount; // offset 0x800D07C4

extern struct _ButtonTexture BmenuLines[3][2]; // offset 0x800D1F34

extern struct DebugMenuLine BossAreasMenu[9]; // offset 0x800C4400

static struct _SavedIntro (*bufferSavedIntroArray[64]); // offset 0x800D5D48

static struct burntTuneType burntTest; // offset 0x800D0544

static short Camera_lookDist; // offset 0x800D0EEE

static short Camera_lookHeight; // offset 0x800D0EEC

extern long camera_modeToIndex[15]; // offset 0x800CDD50

static struct _SVector camera_plane; // offset 0x800D0EC4

static struct _SVector camera_shakeOffset[16]; // offset 0x800D0E44

static short camera_still; // offset 0x800CDD96

extern int CameraCenterDelay; // offset 0x800D13BC

static short CameraLookStickyFlag; // offset 0x800CDDB4

extern struct DebugMenuLine cameraMenu[9]; // offset 0x800C33E0

extern long cameraMode; // offset 0x800CE4A0

extern long campoint_hh; // offset 0x800D13B8

extern long campoint_hw; // offset 0x800D13B4

static int cem_cursor_width; // offset 0x800CD964

static int cem_item_leading; // offset 0x800CD970

static int cem_line_leading; // offset 0x800CD96C

static int cem_line_width; // offset 0x800CD968

static int cem_x_base; // offset 0x800CD95C

static int cem_y_base; // offset 0x800CD960

static short CenterFlag; // offset 0x800CDDB2

extern char charMap[92][3]; // offset 0x800C4E48

static long cheatCodeLastCommand; // offset 0x800CD93C

static long cheatCodeStage; // offset 0x800CD938

static long cheatCombo[6]; // offset 0x800CD940

extern struct DebugMenuLine cheatsMenu[8]; // offset 0x800C2F78

static int checkMusicDelay; // offset 0x800CF00C

static char circBuf[4096]; // offset 0x800D3440

static void *circWhere; // offset 0x800D0178

extern struct DebugMenuLine CityMenu[6]; // offset 0x800C3D28

extern struct BLK_FILL clearRect[2]; // offset 0x800D1F98

extern struct DebugMenuLine CliffMenu[3]; // offset 0x800C3DB8

extern long collide_acceptAttr; // offset 0x800CE3A0

extern long collide_ignoreAttr; // offset 0x800CE39C

extern struct _SVector collide_localPoint; // offset 0x800D13D0

extern struct MATRIX *collide_lwTransform; // offset 0x800D13D8

extern struct _SVector *collide_normal0; // offset 0x800D13DC

extern struct _SVector *collide_normal1; // offset 0x800D13E0

extern struct _SVector *collide_point0; // offset 0x800D13C0

extern struct _SVector *collide_point1; // offset 0x800D13C4

extern long collide_t0; // offset 0x800D13C8

extern long collide_t1; // offset 0x800D13CC

static short combat_cam_angle; // offset 0x800CDD8E

static short combat_cam_distance; // offset 0x800CDD8C

static short combat_cam_weight; // offset 0x800CDD90

static struct __FitPoint constrictData[32]; // offset 0x800D5B7C

extern int ControlFlag; // offset 0x800D5D24

extern struct __razController controllerList[24]; // offset 0x800D068C

extern unsigned char controllerType[2]; // offset 0x800D1CC0

extern long *controlsScreen; // offset 0x800CEB70

static unsigned short cowlList[19]; // offset 0x800D0664

extern long crap1; // offset 0x800D1E2C

static long current_roll_amount; // offset 0x800CDD9C

static struct ScriptPCode *currentActionScript; // offset 0x800D2E70

extern unsigned long CurrentBirthID; // offset 0x800CE7C4

static char currentDynamicSoundName[16]; // offset 0x800D22E4

static struct Event *currentEventInstance; // offset 0x800D2E6C

static long CurrentEventLine; // offset 0x800CFF78

extern int currentIdleCount; // offset 0x800D07C0

extern struct __Idle **currentIdleList; // offset 0x800D07B8

extern int currentIdleListCount; // offset 0x800D07BC

extern struct DebugMenuLine *currentMenu; // offset 0x800CD930

static struct Level *CurrentPuzzleLevel; // offset 0x800D2F08

extern long CurrentWarpNumber; // offset 0x800CFA4C

static struct MATRIX cwTransform2X; // offset 0x800D0E24

extern struct DebugMenuLine DarkEdenMenu[3]; // offset 0x800C42F8

extern long debug_cameraMode; // offset 0x800CCB88

static struct debug_dispatch_t debug_dispatch_table[5]; // offset 0x800C4CE8

extern long debugFogBlu; // offset 0x800CCBA8

extern long debugFogFar; // offset 0x800CCB94

extern long debugFogGrn; // offset 0x800CCBA4

extern long debugFogNear; // offset 0x800CCB98

extern long debugFogRed; // offset 0x800CCBA0

extern struct DebugMenuLine debugForgedAbilitiesMenu[7]; // offset 0x800C2D20

extern long debugGameTime; // offset 0x800CCB9C

extern struct DebugMenuLine debugGlyphAbilitiesMenu[11]; // offset 0x800C2DC8

extern long debugHealthLevel; // offset 0x800CCBAC

extern struct DebugMenuLine debugHealthSystemMenu[7]; // offset 0x800C2B88

extern struct DebugMenuLine debugImbueSoulReaverMenu[7]; // offset 0x800C2ED0

static long debugMenuChoice; // offset 0x800CD934

extern unsigned char debugOrgFogBlu; // offset 0x800D0DAC

extern short debugOrgFogFar; // offset 0x800D0DB0

extern unsigned char debugOrgFogGrn; // offset 0x800D0DA8

extern short debugOrgFogNear; // offset 0x800D0DA0

extern unsigned char debugOrgFogRed; // offset 0x800D0DA4

extern unsigned long debugRazielFlags1; // offset 0x800D0DCC

extern unsigned long debugRazielFlags2; // offset 0x800D0DD0

extern struct DebugMenuLine debugRazielMenu[8]; // offset 0x800C2AC8

extern struct DebugMenuLine debugSoundMenu[14]; // offset 0x800C2978

extern struct DebugMenuLine debugSpecialAbilitiesMenu[10]; // offset 0x800C2C30

extern unsigned long debugTimeMult; // offset 0x800CCB90

extern long debugVoiceIndex; // offset 0x800CCB8C

static struct LightGroup default_lightgroup; // offset 0x800CE7C8

static struct _MonsterFunctionTable DefaultFunctionTable; // offset 0x800D055C

static struct _MonsterState DefaultStateTable[30]; // offset 0x800C5AB4

extern struct DebugMenuLine DemoAreaMenu[10]; // offset 0x800C44D8

extern struct DebugMenuLine demoMenu[8]; // offset 0x800C3260

extern int devstation; // offset 0x800D1E78

static struct _fth directionList[6]; // offset 0x800D0640

extern struct DISPENV disp[2]; // offset 0x800D1E50

extern long DoMainMenu; // offset 0x800CEB64

static int Down; // offset 0x800D0158

extern struct DRAWENV draw[2]; // offset 0x800D1E7C

extern long draw_belowSplit; // offset 0x800CE3D4

extern unsigned char *draw_stack; // offset 0x800D13E4

extern unsigned char dualshock_align[6]; // offset 0x800C4F60

extern unsigned char dualshock_motors[2]; // offset 0x800C4F5C

static short dualshock_onflag; // offset 0x800CE5AA

static long dualshock0_time; // offset 0x800D1CB8

static long dualshock1_time; // offset 0x800D1CBC

extern long dyna_clddyna[8]; // offset 0x800CE33C

extern long dyna_cldstat[8]; // offset 0x800CE37C

static void *enemyPlanPool; // offset 0x800D1C90

static struct __EngagedInstance EngagedList[15]; // offset 0x800D5C9C

static short *EventAbortedPosition; // offset 0x800D2E74

static short EventAbortLine; // offset 0x800CFF70

static long EventCurrentEventIndex; // offset 0x800CFF7C

static short EventJustRecievedTimer; // offset 0x800CFF72

extern struct _Instance (*eventListArray[20][10]); // offset 0x800D3120

extern long eventListNumInstances[20]; // offset 0x800D3090

extern struct DebugMenuLine eventMenu[10]; // offset 0x800C2630

static struct EventTimer eventTimerArray[16]; // offset 0x800D2F0C

static struct __Force *ExternalForces; // offset 0x800D561C

static struct __Force ExternalForces[4]; // offset 0x800D5C3C

static struct _G2SVector3_Type *ExtraRot; // offset 0x800D5C2C

static struct _G2SVector3_Type ExtraRotData; // offset 0x800D5C24

extern struct UVTYPE *face_uv0; // offset 0x800CE3F0

extern struct UVTYPE *face_uv01; // offset 0x800CE3FC

extern struct UVTYPE *face_uv1; // offset 0x800CE3F4

extern struct UVTYPE *face_uv12; // offset 0x800CE400

extern struct UVTYPE *face_uv2; // offset 0x800CE3F8

extern struct UVTYPE *face_uv20; // offset 0x800CE404

extern struct SVECTOR *face_v0; // offset 0x800CE3D8

extern struct SVECTOR *face_v01; // offset 0x800CE3E4

extern struct SVECTOR *face_v1; // offset 0x800CE3DC

extern struct SVECTOR *face_v12; // offset 0x800CE3E8

extern struct SVECTOR *face_v2; // offset 0x800CE3E0

extern struct SVECTOR *face_v20; // offset 0x800CE3EC

static struct _ButtonTexture *FaceButtons; // offset 0x800D5F80

static char *FaceState; // offset 0x800D5F78

static char *FaceStateDir; // offset 0x800D5F7C

extern struct DebugMenuLine fogMenu[8]; // offset 0x800C2720

extern struct _BlockVramEntry *FONT_vramBlock; // offset 0x800D1644

extern struct FontPos fontPos[72]; // offset 0x800C4D28

extern struct Object *fontsObject; // offset 0x800CE4A8

extern struct FontTracker fontTracker; // offset 0x800D164C

extern unsigned char fontTransTable[128]; // offset 0x800CE420

extern short forceDrawInFront; // offset 0x800CE3D0

static char fp_str[512]; // offset 0x800D1444

extern long FRAC_BITS; // offset 0x800CF0E8

extern struct FullScreenItem FullScreenItems[1]; // offset 0x800CEAF8

static struct MONTABLE_202fake functionChoiceTable[8]; // offset 0x800C5A74

extern struct _FXBlastringEffect *fx_blastring; // offset 0x800D03C0

extern long FX_ColorArray[6]; // offset 0x800CF154

static struct _Instance *FX_ConstrictInstance; // offset 0x800CF11C

static struct _Position FX_ConstrictPosition; // offset 0x800D25EC

static struct _Position *FX_ConstrictPositionPtr; // offset 0x800D25F4

static struct _FXRibbon *FX_ConstrictRibbon; // offset 0x800CF114

static short FX_ConstrictStage; // offset 0x800CF118

static short FX_Frames; // offset 0x800D25FC

static struct _FXGeneralEffect *FX_GeneralEffectTracker; // offset 0x800CF110

static short fx_going; // offset 0x800D03BC

static struct _FX_PRIM *FX_LastUsedPrim; // offset 0x800D25F8

static int fx_radius_old; // offset 0x800D4D94

static struct _Instance *FX_reaver_instance; // offset 0x800CF124

static short FX_TimeCount; // offset 0x800D25FE

extern struct _FXTracker *fxTracker; // offset 0x800D1CAC

static struct _G2AnimAlphaTable_Type (*G2AlphaTables[7]); // offset 0x800D015C

extern int gamePadControllerOut; // offset 0x800D1D68

static struct GameTracker *gameTracker; // offset 0x800D5C1C

extern struct GameTracker gameTrackerX; // offset 0x800D1FBC

extern long gDummyCommand[2][2]; // offset 0x800D1D58

extern short gEndGameNow; // offset 0x800CEADA

extern struct _FXTracker *gFXT; // offset 0x800D1C9C

extern struct HintSystemStruct gHintSystem; // offset 0x800CFF88

static struct LightInfo *gLightInfo; // offset 0x800D1C8C

static struct _ObjectTracker *GlobalObjects; // offset 0x800D1C98

extern struct _GlobalSaveTracker *GlobalSave; // offset 0x800D084C

static int glowdeg; // offset 0x800D4DBC

static short glyph_cost; // offset 0x800D4D88

static short glyph_time; // offset 0x800D4D84

static short glyph_trigger; // offset 0x800D4D86

extern struct _Normal gNormalList[244]; // offset 0x800C51AC

static int gNumMonsters; // offset 0x800D04D0

extern struct DebugMenuLine goodiesMenu[17]; // offset 0x800C27E0

static unsigned long (**gOt[2]); // offset 0x800D1C6C

extern struct DebugMenuLine gpadConfigMenu[4]; // offset 0x800C31A0

extern struct ControllerPacket gpbuffer1; // offset 0x800D1CC8

extern struct ControllerPacket gpbuffer2; // offset 0x800D1D10

extern long gTimerEnabled; // offset 0x800CEE24

static int hack_attract; // offset 0x800D0BA8

static int hack_attract_movie; // offset 0x800D0BAC

static int hack_initialized; // offset 0x800D0D3C

static int hack_reset_attract; // offset 0x800D0C70

extern char HashExtensions[7][4]; // offset 0x800CEA6C

static short hitline_rot; // offset 0x800D0EDC

extern struct DebugMenuLine HubAMenu[5]; // offset 0x800C3E90

extern struct DebugMenuLine HubBMenu[3]; // offset 0x800C3F08

static struct _SVector HUD_Cap_Pos; // offset 0x800D4DA8

static struct _SVector HUD_Cap_Vel; // offset 0x800D4DB0

static short HUD_Captured; // offset 0x800D03C4

static short HUD_Pos_vel; // offset 0x800D4D9E

static short HUD_Position; // offset 0x800D4D9C

static short HUD_Rot_vel; // offset 0x800D4D9A

static short HUD_Rotation; // offset 0x800D4D98

static short HUD_State; // offset 0x800D4DA0

static short HUD_Wait; // offset 0x800D4DA2

extern int hud_warp_arrow_flash; // offset 0x800D4DC0

static struct __GlyphHudSaveData HudSave; // offset 0x800D4D8C

extern struct _MonsterFunctionTable HUMAN_FunctionTable; // offset 0x800D03C8

extern struct _MonsterStateChoice HUMAN_StateChoiceTable[6]; // offset 0x800C59B4

extern struct _MonsterFunctionTable HUNTER_FunctionTable; // offset 0x800D03F4

extern struct _MonsterStateChoice HUNTER_StateChoiceTable[6]; // offset 0x800C59FC

extern short identityMatrix[3][3]; // offset 0x800CEDC0

static struct _InstanceList *instanceList; // offset 0x800D1C80

static struct _InstancePool *instancePool; // offset 0x800D1C84

extern int InStreamUnit; // offset 0x800D1CA0

static int ITEMSKIP; // offset 0x800D0BA4

extern struct DebugMenuLine keybConfigMenu[4]; // offset 0x800C3200

static int LastBlock; // offset 0x800D07C8

extern unsigned short lastData[2]; // offset 0x800CE614

static int LastRC; // offset 0x800D5D1C

static struct _SVector left_point; // offset 0x800D0ECC

extern struct DebugMenuLine level2SelectMenu[13]; // offset 0x800C45C8

extern struct DebugMenuLine levelSelectMenu[15]; // offset 0x800C4700

extern void *light_light; // offset 0x800D1D70

extern struct LightInfo *light_lightInfo; // offset 0x800D1D78

extern struct _Terrain *light_terrain; // offset 0x800D1D74

static int LINESKIP; // offset 0x800D0BA0

static int loadBufferedFromHead; // offset 0x800CFE64

static struct _LoadQueueEntry *loadFree; // offset 0x800D2E5C

static struct _LoadQueueEntry *loadHead; // offset 0x800D2E60

static struct _LoadQueueEntry LoadQueue[64]; // offset 0x800D92C0

static struct _LoadStatus loadStatus; // offset 0x800D1D8C

static struct _LoadQueueEntry *loadTail; // offset 0x800D2E64

static struct LocalizationHeader *LocalizationTable; // offset 0x800D0AD4

static char **LocalStrings; // offset 0x800D0AD8

extern int LoopCounter; // offset 0x800D0658

extern short M_TrackClutUpdate; // offset 0x800D4C74

static int MAIN_WIDTH; // offset 0x800D0B90

static int MAIN_XPOS; // offset 0x800D0B88

static int MAIN_YPOS; // offset 0x800D0B8C

static char mainFormatString[20]; // offset 0x800CCB6C

extern struct DebugMenuLine mainMenu[8]; // offset 0x800C3320

extern short mainMenuFadeInTime; // offset 0x800CEB74

extern long mainMenuMode; // offset 0x800CEB68

extern long *mainMenuScreen; // offset 0x4

extern long *mainMenuScreen; // offset 0x800CEB6C

extern short mainMenuTimeOut; // offset 0x800D1FB8

extern char mainOptionsInit; // offset 0x800CEAD8

extern struct MainTracker mainTrackerX; // offset 0x800D2244

static short MANNA_Pos_vel; // offset 0x800D4D82

static short MANNA_Position; // offset 0x800D4D80

extern struct DebugMenuLine mcardMenu[1]; // offset 0x18

extern struct DebugMenuLine mcardMenu[8]; // offset 0x800C4A48

extern struct DebugMenuLine mcardSaveMenu[1]; // offset 0x18

extern struct DebugMenuLine mcardSaveMenu[8]; // offset 0x800C4B08

extern long menuPauseSel; // offset 0x800CCB84

static char midiDataByteCount[8]; // offset 0x800CF5CC

static struct MissileGraphics MISSILE_objectTable[4]; // offset 0x800C5A44

extern long modelDQP; // offset 0x800D13E8

static struct _MonsterVars (*monsterSenseArray[20]); // offset 0x800D4DC4

extern char monVersion[12]; // offset 0x800D0A9C

extern struct DebugMenuLine MorlockMenu[3]; // offset 0x800C3E48

extern long MORPH_A_Component; // offset 0x800D2A44

extern long MORPH_B_Component; // offset 0x800D2A48

extern struct _Vector MORPH_BasePoint; // offset 0x800D2A4C

extern struct _TFace *MORPH_SavedFace; // offset 0x800D2E58

static long MoveCodeStreamExtra; // offset 0x800CFF74

static int musicLoadInProgress; // offset 0x800CF008

extern struct DebugMenuLine musicSelectMenu[20]; // offset 0x800C4868

static struct NewMemTracker newMemTracker; // offset 0x800D291C

extern int nomusic; // offset 0x800CEAE4

static struct _Normal Norm; // offset 0x800D5D14

extern int nosound; // offset 0x800CEAE0

static long numActiveEventTimers; // offset 0x800D308C

static long numbufferedIntros; // offset 0x800D0850

static int numLoads; // offset 0x800D2E68

extern long numOfBlocksUsed; // offset 0x800D4C78

extern long NumSignalsToReset; // offset 0x800CFF84

extern struct ObjectAccess objectAccess[31]; // offset 0x800C4F7C

extern struct ObjectFunc objectFunc[8]; // offset 0x800C5074

static long objectOneShotTriggerTbl[3]; // offset 0x800CF010

extern struct _BlockVramEntry *openVramBlocks; // offset 0x800D4C9C

extern struct DebugMenuLine optsMenu[15]; // offset 0x800C3038

extern struct DebugMenuLine OracleMenu[10]; // offset 0x800C36E0

static long *PadData; // offset 0x800D5C20

static short panic_count; // offset 0x800CDDB8

static int PAUSE_WIDTH; // offset 0x800D0B9C

static int PAUSE_XPOS; // offset 0x800D0B94

static int PAUSE_YPOS; // offset 0x800D0B98

extern struct _ButtonTexture PauseButtons[4][2]; // offset 0x800D2254

static char pauseFormatString[20]; // offset 0x800CCB58

extern struct DebugMenuLine pauseMenu[7]; // offset 0x800C4C40

extern struct DebugMenuLine pauseSaveMenu[5]; // offset 0x800C4BC8

extern int pcverify; // offset 0x800CEADC

static int Pending; // offset 0x800D0150

static int PhysicsMode; // offset 0x800D5C8C

static unsigned char PickupList[4]; // offset 0x800D0660

extern struct DebugMenuLine PillarsMenu[6]; // offset 0x800C37D0

static void *planningPool; // offset 0x800D1C94

extern long playerCameraMode; // offset 0x800CE4A4

static struct RazielData *PlayerData; // offset 0x800D5B48

static struct _PolytopeList *polytopeList; // offset 0x800D1C7C

extern struct PoolManagementData *poolManagementData; // offset 0x800D5618

static struct PoolManagementData poolManagementDataStorage; // offset 0x800D55CC

extern char *primBase; // offset 0x800D1CB0

static struct _PrimPool (*primPool[2]); // offset 0x800D1C74

extern unsigned short psxData[2]; // offset 0x800D1CC4

extern struct DebugMenuLine PushMenu[11]; // offset 0x800C3C20

static struct RadarInfo radarDir[16]; // offset 0x800D04D4

static unsigned char radarDirIndex[16]; // offset 0x800D0534

static short rain_amount; // offset 0x800CF122

static struct __Player Raziel; // offset 0x800D565C

extern long RazielCommands[10]; // offset 0x800D0128

static struct _G2AnimInterpInfo_Type razInterpInfo[3]; // offset 0x800D5B4C

extern struct ControllerPacket readGPBuffer1; // offset 0x800D1CEC

extern struct ControllerPacket readGPBuffer2; // offset 0x800D1D34

extern short RENDER_currentStreamUnitID; // offset 0x800D1CA4

extern struct _MultiSignal (*ResetSignalArray[16]); // offset 0x800D30E0

static struct _SVector right_point; // offset 0x800D0ED4

static int roll_inc; // offset 0x800CDDA0

static long roll_target; // offset 0x800CDD98

static int s_zval; // offset 0x800D2A40

extern long SaveArraySize[7]; // offset 0x800D0858

static struct SavedInfoTracker savedInfoTracker; // offset 0x800D5D38

extern struct DebugMenuLine saveMenu[4]; // offset 0x800C25D0

extern struct LightInfo *sbsp_lightInfo; // offset 0x800D22D4

static struct UW_ScreenXY *ScreenMorphArray; // offset 0x800D0838

extern char (*selectMenuText[5]); // offset 0x800C4F68

extern struct SVECTOR shadow_vertices[11]; // offset 0x800D13EC

static short shorten_count; // offset 0x800CDD92

static short shorten_flag; // offset 0x800CDD94

extern long SignalEndGame; // offset 0x800CDDDC

extern struct SignalInfo signalInfoList[111]; // offset 0x800CDE08

extern struct DebugMenuLine SilencedCathedralMenu[11]; // offset 0x800C3860

extern struct _MonsterFunctionTable SKINNER_FunctionTable; // offset 0x800D057C

extern struct _MonsterStateChoice SKINNER_StateChoiceTable[4]; // offset 0x800C5BA4

extern struct DebugMenuLine SkinnerMenu[7]; // offset 0x800C3968

extern struct _MonsterFunctionTable SLUAGH_FunctionTable; // offset 0x800D059C

extern struct _MonsterStateChoice SLUAGH_StateChoiceTable[4]; // offset 0x800C5BD4

static unsigned long smfBytesLeft; // offset 0x800D2A38

static unsigned char *smfDataPtr; // offset 0x800D2A34

static struct AadDynamicSfxLoadInfo *smfInfo; // offset 0x800D2A3C

static char smpFileName[64]; // offset 0x800D2334

static char sndFileName[64]; // offset 0x800D22F4

static short snow_amount; // offset 0x800CF120

extern struct _MonsterFunctionTable SOUL_FunctionTable; // offset 0x800D05C4

extern struct _MonsterStateChoice SOUL_StateChoiceTable[7]; // offset 0x800C5C04

extern char soundBuffer[13116]; // offset 0x800D5F84

extern struct SoundEffectChannel soundEffectChannelTbl[16]; // offset 0x800D2374

extern unsigned short SpecialFogClut; // offset 0x800D1648

static struct DVECTOR Spiral_Array[65]; // offset 0x800D260C

static long Spiral_Current; // offset 0x800CF170

static short Spiral_Degrees; // offset 0x800CF16E

static long Spiral_Max; // offset 0x800CF174

static short Spiral_Number; // offset 0x800CF16C

static struct DVECTOR Spiral_OffsetM[64]; // offset 0x800D281C

static struct DVECTOR Spiral_OffsetP[64]; // offset 0x800D271C

static struct _Rotation splinecam_helprot; // offset 0x800D0EE4

extern unsigned long StackSave; // offset 0x800D1CA8

extern struct DebugMenuLine standardMenu[15]; // offset 0x800C2468

extern long stat_clddyna[8]; // offset 0x800CE35C

extern struct DebugMenuLine statsMenu[1]; // offset 0x800D0DB4

extern int StCdIntrFlag; // offset 0x800DB2C0

extern struct DebugMenuLine StoneMenu[5]; // offset 0x800C3A10

extern struct STracker StreamTracker; // offset 0x800D2A58

extern struct DebugMenuLine SunLightMenu[7]; // offset 0x800C3A88

static struct MATRIX TempMat; // offset 0x800D5BFC

static struct MATRIX TempMat; // offset 0x800D562C

extern struct _BlockVramEntry TerrainVramBlock; // offset 0x800D4C7C

extern struct DebugMenuLine TestMenu[18]; // offset 0x800C4148

extern struct DebugMenuLine TestMenu2[16]; // offset 0x800C3FC8

static char (*the_attract_movies[4]); // offset 0x800C5E78

static struct cinema_fn_table_t *the_cine_table; // offset 0x800C5E40

static struct _ObjectTracker *the_cine_tracker; // offset 0x800C5E44

static struct menuface_t the_faces[8]; // offset 0x800D0C9C

static struct font_color_t the_font_color_table[2]; // offset 0x800C4D10

static char *the_format_string; // offset 0x800CCB80

static int the_header_size; // offset 0x800D0854

static enum language_t the_language; // offset 0x800D5F74

extern struct mcmenu_table_t the_mcmenu_table; // offset 0x24

static struct menu_sound_entry_t the_menu_sounds[6]; // offset 0x800C5E48

extern struct DebugMenuLine *the_previous_menu; // offset 0x800CD958

extern struct Camera theCamera; // offset 0x800D0EF0

static long timerArray[10]; // offset 0x800D55EC

static long timerIndex; // offset 0x800D5614

extern struct DebugMenuLine TombMenu[6]; // offset 0x800C3B30

extern struct DebugMenuLine TrainingMenu[5]; // offset 0x800C3F50

extern struct DebugMenuLine UnderMenu[3]; // offset 0x800C3E00

static int Up; // offset 0x800D0154

extern struct _BlockVramEntry *usedVramBlocks; // offset 0x800D4C98

static long UW_angle; // offset 0x800D5D28

static long UW_angleInc; // offset 0x800D5D34

static long UW_scalex; // offset 0x800D5D2C

static long UW_scalexInc; // offset 0x800D5D30

static struct _VertexPool *vertexPool; // offset 0x800D1C88

static long vmClock; // offset 0x800CF180

static long vmRealClock; // offset 0x800CF17C

extern struct XAVoiceListEntry *voiceList; // offset 0x800D0ADC

extern struct XAVoiceTracker voiceTracker; // offset 0x800D5E4C

extern long VRAM_NeedToUpdateMorph; // offset 0x800D017C

extern struct _BlockVramEntry vramBlockList[75]; // offset 0x800D4440

extern struct _MonsterFunctionTable VWRAITH_FunctionTable; // offset 0x800D05E4

extern struct _MonsterStateChoice VWRAITH_StateChoiceTable[6]; // offset 0x800C5C58

static int warpDraw; // offset 0x800D4DB8

extern struct STREAM_288fake WarpGateLoadInfo; // offset 0x800CFA3C

extern struct WarpRoom WarpRoomArray[14]; // offset 0x800CFA50

extern long WaterInUse; // offset 0x800CFF80

static struct WaterLevelProcess WaterLevelArray[5]; // offset 0x800D2E7C

extern struct DebugMenuLine WaterMenu[4]; // offset 0x800C3BC0

static int WaterStatus; // offset 0x800D065C

static struct MATRIX wcTransform2X; // offset 0x800D0E04

static struct MATRIX wcTransformX; // offset 0x800D0DE4

static short wind_deg; // offset 0x800CF150

static short wind_speed; // offset 0x800CF152

static short windx; // offset 0x800CF14C

static short windy; // offset 0x800CF14E

extern struct _MonsterFunctionTable WORSHIP_FunctionTable; // offset 0x800D0604

extern struct _MonsterStateChoice WORSHIP_StateChoiceTable[5]; // offset 0x800C5CA0

static int ZoneDelta; // offset 0x800D06F0

struct TCB // hashcode: 0x6A70BBF4 (dec: 1785773044)
{
	long status; // size=0, offset=0
	long mode; // size=0, offset=4
	unsigned long reg[40]; // size=160, offset=8
	long system[6]; // size=24, offset=168
};

struct EXEC // hashcode: 0x4291A2AD (dec: 1116840621)
{
	unsigned long pc0; // size=0, offset=0
	unsigned long gp0; // size=0, offset=4
	unsigned long t_addr; // size=0, offset=8
	unsigned long t_size; // size=0, offset=12
	unsigned long d_addr; // size=0, offset=16
	unsigned long d_size; // size=0, offset=20
	unsigned long b_addr; // size=0, offset=24
	unsigned long b_size; // size=0, offset=28
	unsigned long s_addr; // size=0, offset=32
	unsigned long s_size; // size=0, offset=36
	unsigned long sp; // size=0, offset=40
	unsigned long fp; // size=0, offset=44
	unsigned long gp; // size=0, offset=48
	unsigned long ret; // size=0, offset=52
	unsigned long base; // size=0, offset=56
};

struct DIRENTRY // hashcode: 0xD989A944 (dec: -645289660)
{
	char name[20]; // size=20, offset=0
	long attr; // size=0, offset=20
	long size; // size=0, offset=24
	struct DIRENTRY *next; // size=40, offset=28
	long head; // size=0, offset=32
	char system[4]; // size=4, offset=36
};

struct MATRIX // hashcode: 0x610186A2 (dec: 1627489954)
{
	short m[3][3]; // size=18, offset=0
	long t[3]; // size=12, offset=20
};

struct VECTOR // hashcode: 0xE0DB0D68 (dec: -522515096)
{
	long vx; // size=0, offset=0
	long vy; // size=0, offset=4
	long vz; // size=0, offset=8
	long pad; // size=0, offset=12
};

struct SVECTOR // hashcode: 0x55473CEB (dec: 1430732011)
{
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
	short vz; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct CVECTOR // hashcode: 0xDE4B0C81 (dec: -565506943)
{
	unsigned char r; // size=0, offset=0
	unsigned char g; // size=0, offset=1
	unsigned char b; // size=0, offset=2
	unsigned char cd; // size=0, offset=3
};

struct DVECTOR // hashcode: 0x5BF12E56 (dec: 1542532694)
{
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
};

struct RVECTOR // hashcode: 0xEC34D5C3 (dec: -332081725)
{
	struct SVECTOR v; // size=8, offset=0
	unsigned char uv[2]; // size=2, offset=8
	unsigned short pad; // size=0, offset=10
	struct CVECTOR c; // size=4, offset=12
	struct DVECTOR sxy; // size=4, offset=16
	unsigned long sz; // size=0, offset=20
};

struct CRVECTOR3 // hashcode: 0x9A564233 (dec: -1705622989)
{
	struct RVECTOR r01; // size=24, offset=0
	struct RVECTOR r12; // size=24, offset=24
	struct RVECTOR r20; // size=24, offset=48
	struct RVECTOR *r0; // size=24, offset=72
	struct RVECTOR *r1; // size=24, offset=76
	struct RVECTOR *r2; // size=24, offset=80
	unsigned long *rtn; // size=0, offset=84
};

struct CRVECTOR4 // hashcode: 0x56AED614 (dec: 1454298644)
{
	struct RVECTOR r01; // size=24, offset=0
	struct RVECTOR r02; // size=24, offset=24
	struct RVECTOR r31; // size=24, offset=48
	struct RVECTOR r32; // size=24, offset=72
	struct RVECTOR rc; // size=24, offset=96
	struct RVECTOR *r0; // size=24, offset=120
	struct RVECTOR *r1; // size=24, offset=124
	struct RVECTOR *r2; // size=24, offset=128
	struct RVECTOR *r3; // size=24, offset=132
	unsigned long *rtn; // size=0, offset=136
};

struct RECT // hashcode: 0xDFC821CB (dec: -540532277)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short w; // size=0, offset=4
	short h; // size=0, offset=6
};

struct DR_ENV // hashcode: 0xD77E7FD5 (dec: -679575595)
{
	unsigned long tag; // size=0, offset=0
	unsigned long code[15]; // size=60, offset=4
};

struct P_TAG // hashcode: 0x962C4103 (dec: -1775484669)
{
	unsigned int addr; // size=24, offset=0
	unsigned int len; // size=8, offset=24
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
};

struct CdlLOC // hashcode: 0x449289F8 (dec: 1150454264)
{
	unsigned char minute; // size=0, offset=0
	unsigned char second; // size=0, offset=1
	unsigned char sector; // size=0, offset=2
	unsigned char track; // size=0, offset=3
};

struct LightInstance // hashcode: 0xB8D5E61F (dec: -1193941473)
{
	struct _Instance *lightInstance; // size=0, offset=0
	long r; // size=0, offset=4
	long g; // size=0, offset=8
	long b; // size=0, offset=12
	short radius; // size=0, offset=16
	unsigned char segment; // size=0, offset=18
	unsigned char flags; // size=0, offset=19
};

struct _Instance // hashcode: 0x699A5B3D (dec: 1771723581)
{
	struct NodeType node; // size=8, offset=0
	struct _Instance *next; // size=664, offset=8
	struct _Instance *prev; // size=664, offset=12
	long instanceID; // size=0, offset=16
	long flags; // size=0, offset=20
	long flags2; // size=0, offset=24
	struct Object *object; // size=76, offset=28
	struct Intro *intro; // size=0, offset=32
	void *data; // size=0, offset=36
	void *introData; // size=0, offset=40
	struct _Instance *parent; // size=664, offset=44
	long introNum; // size=0, offset=48
	long birthStreamUnitID; // size=0, offset=52
	long currentStreamUnitID; // size=0, offset=56
	long introUniqueID; // size=0, offset=60
	struct MATRIX *matrix; // size=32, offset=64
	struct MATRIX *oldMatrix; // size=32, offset=68
	struct SoundInstance soundInstanceTbl[4]; // size=12, offset=72
	unsigned long maxCheckDistance; // size=0, offset=84
	unsigned long checkMask; // size=0, offset=88
	struct _Position position; // size=6, offset=92
	unsigned char lightGroup; // size=0, offset=98
	struct _Position oldPos; // size=6, offset=100
	unsigned char spectralLightGroup; // size=0, offset=106
	short currentTextureAnimFrame; // size=0, offset=108
	struct _Position initialPos; // size=6, offset=110
	struct _Rotation rotation; // size=8, offset=116
	struct _Rotation oldRotation; // size=8, offset=124
	struct _SVector scale; // size=8, offset=132
	long attachedID; // size=0, offset=140
	long attachedSegment; // size=0, offset=144
	struct MATRIX relativeMatrix; // size=32, offset=148
	struct _TFace *tface; // size=12, offset=180
	struct _TFace *oldTFace; // size=12, offset=184
	void *tfaceLevel; // size=0, offset=188
	void *collideInfo; // size=0, offset=192
	long bspTree; // size=0, offset=196
	short cachedTFace; // size=0, offset=200
	short cachedBSPTree; // size=0, offset=202
	struct _Normal oldWNormal; // size=8, offset=204
	struct _Normal wNormal; // size=8, offset=212
	struct _SVector offset; // size=8, offset=220
	void *dsignal; // size=0, offset=228
	void *shadow0; // size=0, offset=232
	void *shadow1; // size=0, offset=236
	void *extraLight; // size=0, offset=240
	struct _Position extraLightDir; // size=6, offset=244
	short extraLightScale; // size=0, offset=250
	struct _HModel *hModelList; // size=8, offset=252
	short fadeValue; // size=0, offset=256
	short lightMatrix; // size=0, offset=258
	void (*processFunc)(); // size=0, offset=260
	void (*collideFunc)(); // size=0, offset=264
	void (*additionalCollideFunc)(); // size=0, offset=268
	void *additionalDrawFunc; // size=0, offset=272
	unsigned long (*queryFunc)(); // size=0, offset=276
	void (*messageFunc)(); // size=0, offset=280
	struct _Position shadowPosition; // size=6, offset=284
	short currentModel; // size=0, offset=290
	struct _TFace *waterFace; // size=12, offset=292
	struct _TFace *oldWaterFace; // size=12, offset=296
	struct _Terrain *waterFaceTerrain; // size=0, offset=300
	struct _PlaneConstants halvePlane; // size=12, offset=304
	struct _SVector splitPoint; // size=8, offset=316
	struct _Instance *LinkParent; // size=664, offset=324
	struct _Instance *LinkChild; // size=664, offset=328
	struct _Instance *LinkSibling; // size=664, offset=332
	long ParentLinkNode; // size=0, offset=336
	void *InstanceState; // size=0, offset=340
	char introName[16]; // size=16, offset=344
	void *extraData; // size=0, offset=360
	short constrictAngle; // size=0, offset=364
	short petrifyValue; // size=0, offset=366
	long xVel; // size=0, offset=368
	long yVel; // size=0, offset=372
	long zVel; // size=0, offset=376
	long xAccl; // size=0, offset=380
	long yAccl; // size=0, offset=384
	long zAccl; // size=0, offset=388
	long maxXVel; // size=0, offset=392
	long maxYVel; // size=0, offset=396
	long maxZVel; // size=0, offset=400
	long currentMainState; // size=0, offset=404
	long currentSubState; // size=0, offset=408
	long work0; // size=0, offset=412
	long work1; // size=0, offset=416
	long work2; // size=0, offset=420
	long work3; // size=0, offset=424
	long work4; // size=0, offset=428
	long work5; // size=0, offset=432
	long work6; // size=0, offset=436
	long work7; // size=0, offset=440
	long work8; // size=0, offset=444
	long work9; // size=0, offset=448
	struct _G2Anim_Type anim; // size=180, offset=452
	enum _G2Bool_Enum (*rebuildCallback)(); // size=4, offset=632
	short splineFlags; // size=0, offset=636
	short targetFrame; // size=0, offset=638
	short clipBeg; // size=0, offset=640
	short clipEnd; // size=0, offset=642
	struct EventAliasCommandStruct aliasCommand; // size=12, offset=644
	long light_color; // size=0, offset=656
	struct CVECTOR *perVertexColor; // size=4, offset=660
};

struct _GameTrackerASMData_Type // hashcode: 0x28F0BFB9 (dec: 686866361)
{
	long drawBackFaces; // size=0, offset=0
	long dispPage; // size=0, offset=4
	short MorphTime; // size=0, offset=8
	short MorphType; // size=0, offset=10
	struct LightInstance lightInstances[1]; // size=20, offset=12
};

struct _GameData_Type // hashcode: 0xE05EBAD0 (dec: -530662704)
{
	struct _GameTrackerASMData_Type asmData; // size=32, offset=0
};

struct NodeType // hashcode: 0x5BF613D7 (dec: 1542853591)
{
	struct NodeType *prev; // size=8, offset=0
	struct NodeType *next; // size=8, offset=4
};

struct TextureFT3 // hashcode: 0x2D2801D6 (dec: 757596630)
{
	unsigned char u0; // size=0, offset=0
	unsigned char v0; // size=0, offset=1
	unsigned short clut; // size=0, offset=2
	unsigned char u1; // size=0, offset=4
	unsigned char v1; // size=0, offset=5
	unsigned short tpage; // size=0, offset=6
	unsigned char u2; // size=0, offset=8
	unsigned char v2; // size=0, offset=9
	unsigned short attr; // size=0, offset=10
};

struct TextureMT3 // hashcode: 0xC9D0A5B9 (dec: -909072967)
{
	unsigned char u0; // size=0, offset=0
	unsigned char v0; // size=0, offset=1
	unsigned short clut; // size=0, offset=2
	unsigned char u1; // size=0, offset=4
	unsigned char v1; // size=0, offset=5
	unsigned short tpage; // size=0, offset=6
	unsigned char u2; // size=0, offset=8
	unsigned char v2; // size=0, offset=9
	char pad1; // size=0, offset=10
	char sortPush; // size=0, offset=11
	long color; // size=0, offset=12
};

struct AniTexInfo // hashcode: 0x907C013D (dec: -1870921411)
{
	struct TextureMT3 *texture; // size=16, offset=0
	long numFrames; // size=0, offset=4
	long speed; // size=0, offset=8
};

struct AniTex // hashcode: 0xE4DA2729 (dec: -455465175)
{
	long numAniTextues; // size=0, offset=0
	struct AniTexInfo aniTexInfo; // size=12, offset=4
};

struct DrMoveAniTexSrcInfo // hashcode: 0x4AD6E543 (dec: 1255597379)
{
	short pixSrcX; // size=0, offset=0
	short pixSrcY; // size=0, offset=2
	short clutSrcX; // size=0, offset=4
	short clutSrcY; // size=0, offset=6
};

struct DrMoveAniTexDestInfo // hashcode: 0xF3A982EE (dec: -206994706)
{
	short pixDstX; // size=0, offset=0
	short pixDstY; // size=0, offset=2
	short pixW; // size=0, offset=4
	short pixH; // size=0, offset=6
	short clutDstX; // size=0, offset=8
	short clutDstY; // size=0, offset=10
	short clutW; // size=0, offset=12
	short clutH; // size=0, offset=14
	short pixCurrentX; // size=0, offset=16
	short pixCurrentY; // size=0, offset=18
	short clutCurrentX; // size=0, offset=20
	short clutCurrentY; // size=0, offset=22
	long numFrames; // size=0, offset=24
	long speed; // size=0, offset=28
	struct DrMoveAniTexSrcInfo frame; // size=8, offset=32
};

struct DrMoveAniTex // hashcode: 0x0820A5D4 (dec: 136357332)
{
	long numAniTextues; // size=0, offset=0
	struct DrMoveAniTexDestInfo *aniTexInfo; // size=40, offset=4
};

struct MemHeader // hashcode: 0xDAEE4890 (dec: -621918064)
{
	unsigned short magicNumber; // size=0, offset=0
	unsigned char memStatus; // size=0, offset=2
	unsigned char memType; // size=0, offset=3
	unsigned long memSize; // size=0, offset=4
};

enum _G2Bool_Enum // Hashcode: 0xFDD7E4E7 (dec: -36182809)
{
	G2FALSE = 0,
};

struct _G2SVector3_Type // hashcode: 0x60FF7CCD (dec: 1627356365)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _G2LVector3_Type // hashcode: 0xD8D79EE7 (dec: -656957721)
{
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

struct _G2Matrix_Type // hashcode: 0x647D6F57 (dec: 1685942103)
{
	short rotScale[3][3]; // size=18, offset=0
	short scaleFlag; // size=0, offset=18
	struct _G2LVector3_Type trans; // size=12, offset=20
};

struct _G2Quat_Type // hashcode: 0xC71F9EB1 (dec: -954229071)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short w; // size=0, offset=6
};

struct _G2AnimQuatInfo_Type // hashcode: 0x5A520473 (dec: 1515324531)
{
	struct _G2Quat_Type srcQuat; // size=8, offset=0
	struct _G2Quat_Type destQuat; // size=8, offset=8
	struct _G2SVector3_Type srcScale; // size=6, offset=16
	struct _G2SVector3_Type destScale; // size=6, offset=22
	struct _G2SVector3_Type srcTrans; // size=6, offset=28
	struct _G2SVector3_Type destTrans; // size=6, offset=34
};

struct _G2AnimAlphaTable_Type // hashcode: 0x2288BF48 (dec: 579387208)
{
	unsigned short size; // size=0, offset=0
	long data[0]; // size=0, offset=4
};

struct _G2AnimInterpStateBlock_Type // hashcode: 0xFB03DD89 (dec: -83632759)
{
	struct _G2AnimInterpStateBlock_Type *next; // size=164, offset=0
	struct _G2AnimQuatInfo_Type quatInfo[4]; // size=160, offset=4
};

struct _G2AnimInterpInfo_Type // hashcode: 0xAE13EB6F (dec: -1374426257)
{
	short duration; // size=0, offset=0
	short targetTime; // size=0, offset=2
	struct _G2AnimAlphaTable_Type *alphaTable; // size=4, offset=4
	struct _G2AnimInterpStateBlock_Type *stateBlockList; // size=164, offset=8
};

struct _G2AnimChanStatus_Type // hashcode: 0x575B81AB (dec: 1465614763)
{
	short keyData; // size=0, offset=0
	short index; // size=0, offset=2
};

struct _G2AnimChanStatusBlock_Type // hashcode: 0xC6C09C4F (dec: -960455601)
{
	struct _G2AnimChanStatusBlock_Type *next; // size=36, offset=0
	struct _G2AnimChanStatus_Type chunks[8]; // size=32, offset=4
};

struct _G2AnimFxHeader_Type // hashcode: 0xA004B4ED (dec: -1610304275)
{
	unsigned char sizeAndSection; // size=0, offset=0
	char type; // size=0, offset=1
	unsigned short keyframeID; // size=0, offset=2
};

struct _G2AnimKeylist_Type // hashcode: 0x87A15165 (dec: -2019471003)
{
	unsigned char sectionCount; // size=0, offset=0
	unsigned char s0TailTime; // size=0, offset=1
	unsigned char s1TailTime; // size=0, offset=2
	unsigned char s2TailTime; // size=0, offset=3
	unsigned short keyCount; // size=0, offset=4
	short timePerKey; // size=0, offset=6
	unsigned short pad00; // size=0, offset=8
	short pad01; // size=0, offset=10
	unsigned short pad10; // size=0, offset=12
	short pad11; // size=0, offset=14
	struct _G2AnimFxHeader_Type *fxList; // size=4, offset=16
	unsigned short (*sectionData[0]); // size=0, offset=20
};

union PLAYER_76fake // Hashcode: 0x35EA4737 (dec: 904546103)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: player.o, player.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: player.o, player.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: player.o, player.o
};

struct _G2AnimSection_Type // hashcode: 0xFC80328C (dec: -58707316)
{
	unsigned char flags; // size=0, offset=0
	unsigned char sectionID; // size=0, offset=1
	unsigned char firstSeg; // size=0, offset=2
	unsigned char segCount; // size=0, offset=3
	short elapsedTime; // size=0, offset=4
	short storedTime; // size=0, offset=6
	short loopStartTime; // size=0, offset=8
	short loopEndTime; // size=0, offset=10
	short *swAlarmTable; // size=0, offset=12
	long speedAdjustment; // size=0, offset=16
	unsigned short keylistID; // size=0, offset=20
	unsigned long alarmFlags; // size=0, offset=24
	long (*callback)(); // size=0, offset=28
	void *callbackData; // size=0, offset=32
	struct _G2AnimKeylist_Type *keylist; // size=20, offset=36
	struct _G2AnimChanStatusBlock_Type *chanStatusBlockList; // size=36, offset=40
	struct _G2AnimInterpInfo_Type *interpInfo; // size=12, offset=44
};

struct _G2Anim_Type // hashcode: 0xF35FCCD2 (dec: -211825454)
{
	unsigned char sectionCount; // size=0, offset=0
	unsigned char masterSection; // size=0, offset=1
	unsigned short controllerList; // size=0, offset=2
	unsigned short disabledControllerList; // size=0, offset=4
	unsigned short pad; // size=0, offset=6
	struct _G2SVector3_Type rootTrans; // size=6, offset=8
	unsigned short flags; // size=0, offset=14
	struct _Model *modelData; // size=0, offset=16
	struct _G2Matrix_Type *segMatrices; // size=32, offset=20
	unsigned long disabledBits[3]; // size=12, offset=24
	struct _G2AnimSection_Type section[3]; // size=144, offset=36
};

struct _Model // hashcode: 0x9BCE1D24 (dec: -1680990940)
{
	long numVertices; // size=0, offset=0
	struct _MVertex *vertexList; // size=8, offset=4
	long numNormals; // size=0, offset=8
	struct _SVectorNoPad *normalList; // size=6, offset=12
	long numFaces; // size=0, offset=16
	struct _MFace *faceList; // size=12, offset=20
	long numSegments; // size=0, offset=24
	struct _Segment *segmentList; // size=24, offset=28
	struct AniTex *aniTextures; // size=16, offset=32
	short maxRad; // size=0, offset=36
	short pad; // size=0, offset=38
	long maxRadSq; // size=0, offset=40
	struct MultiSpline *multiSpline; // size=0, offset=44
	struct TextureMT3 *startTextures; // size=16, offset=48
	struct TextureMT3 *endTextures; // size=16, offset=52
};

struct _SVector // hashcode: 0x73B07C09 (dec: 1940945929)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _SVectorNoPad // hashcode: 0xA6EDBBC6 (dec: -1494369338)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _Position // hashcode: 0x2523C22F (dec: 623100463)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _Rotation // hashcode: 0x5A40CBB0 (dec: 1514195888)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _Normal // hashcode: 0xC59D5A5B (dec: -979543461)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _PlaneConstants // hashcode: 0xE1AAD777 (dec: -508897417)
{
	short a; // size=0, offset=0
	short b; // size=0, offset=2
	short c; // size=0, offset=4
	short flags; // size=0, offset=6
	long d; // size=0, offset=8
};

struct _Vertex // hashcode: 0x97101469 (dec: -1760553879)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _Face // hashcode: 0x8775891B (dec: -2022340325)
{
	unsigned short v0; // size=0, offset=0
	unsigned short v1; // size=0, offset=2
	unsigned short v2; // size=0, offset=4
};

struct _MVertex // hashcode: 0x2B95C05B (dec: 731234395)
{
	struct _Vertex vertex; // size=6, offset=0
	unsigned short normal; // size=0, offset=6
};

struct _MFace // hashcode: 0xB75C604D (dec: -1218682803)
{
	struct _Face face; // size=6, offset=0
	unsigned char normal; // size=0, offset=6
	unsigned char flags; // size=0, offset=7
	long color; // size=0, offset=8
};

struct _RGBAColor // hashcode: 0xF7174D90 (dec: -149467760)
{
	unsigned char r; // size=0, offset=0
	unsigned char g; // size=0, offset=1
	unsigned char b; // size=0, offset=2
	unsigned char a; // size=0, offset=3
};

union PLAYER_77fake // Hashcode: 0xBB3AB3AC (dec: -1153780820)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _PVertex // hashcode: 0x4AC0ECE8 (dec: 1254157544)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	long otz; // size=0, offset=4
};

struct _VertexPool // hashcode: 0x98F8C96E (dec: -1728525970)
{
	struct _PVertex vertex[528]; // size=4224, offset=0
	struct CVECTOR color[528]; // size=2112, offset=4224
};

struct _PrimPool // hashcode: 0x9529B283 (dec: -1792429437)
{
	long numPrims; // size=0, offset=0
	unsigned long *nextPrim; // size=0, offset=4
	unsigned long *lastPrim; // size=0, offset=8
	unsigned long prim[24000]; // size=96000, offset=12
};

struct _Sphere // hashcode: 0x361BDD31 (dec: 907795761)
{
	struct _Position position; // size=6, offset=0
	unsigned short radius; // size=0, offset=6
	unsigned long radiusSquared; // size=0, offset=8
};

struct _Sphere_noSq // hashcode: 0xA031058C (dec: -1607400052)
{
	struct _Position position; // size=6, offset=0
	unsigned short radius; // size=0, offset=6
};

struct _CameraKey // hashcode: 0xB9E6B724 (dec: -1176062172)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short id; // size=0, offset=6
	short rx; // size=0, offset=8
	short ry; // size=0, offset=10
	short rz; // size=0, offset=12
	short flags; // size=0, offset=14
	short tx; // size=0, offset=16
	short ty; // size=0, offset=18
	short tz; // size=0, offset=20
	short pad; // size=0, offset=22
};

struct Object // hashcode: 0xEC12E9AC (dec: -334304852)
{
	long oflags; // size=0, offset=0
	short id; // size=0, offset=4
	short sfxFileHandle; // size=0, offset=6
	short numModels; // size=0, offset=8
	short numAnims; // size=0, offset=10
	struct _Model **modelList; // size=56, offset=12
	struct _G2AnimKeylist_Type **animList; // size=20, offset=16
	short introDist; // size=0, offset=20
	short vvIntroDist; // size=0, offset=22
	short removeDist; // size=0, offset=24
	short vvRemoveDist; // size=0, offset=26
	void *data; // size=0, offset=28
	char *script; // size=0, offset=32
	char *name; // size=0, offset=36
	unsigned char *soundData; // size=0, offset=40
	long oflags2; // size=0, offset=44
	short sectionA; // size=0, offset=48
	short sectionB; // size=0, offset=50
	short sectionC; // size=0, offset=52
	short numberOfEffects; // size=0, offset=54
	struct ObjectEffect *effectList; // size=4, offset=56
	unsigned long *relocList; // size=0, offset=60
	void *relocModule; // size=0, offset=64
	struct VramSize vramSize; // size=8, offset=68
};

struct _BVertex // hashcode: 0xADD3BD2F (dec: -1378632401)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _BFace // hashcode: 0x69100F99 (dec: 1762660249)
{
	short v0; // size=0, offset=0
	short v1; // size=0, offset=2
	short v2; // size=0, offset=4
	short pad; // size=0, offset=6
	struct TextureFT3 *texture; // size=12, offset=8
};

struct _BGObject // hashcode: 0xEC69FB30 (dec: -328598736)
{
	short flags; // size=0, offset=0
	short numFaces; // size=0, offset=2
	struct _BVertex *vertexList; // size=8, offset=4
	struct _BFace *faceList; // size=12, offset=8
	short x; // size=0, offset=12
	short y; // size=0, offset=14
	short z; // size=0, offset=16
	short radius; // size=0, offset=18
	long numVertices; // size=0, offset=20
};

struct Signal // hashcode: 0xA0225F88 (dec: -1608360056)
{
	long id; // size=0, offset=0
	union {
		struct {
			union {
				long l; // size=0, offset=0
				short s[2]; // size=4, offset=0
				char c[4]; // size=4, offset=0
			} size; // size=4, offset=0, found in object files: player.o, player.o
		} misc; // size=12, offset=0, found in object files: player.o, player.o
		struct _CameraKey *cameraKey; // size=24, offset=0
		struct {
			short x; // size=0, offset=0
			short y; // size=0, offset=2
			short z; // size=0, offset=4
			short zrot; // size=0, offset=6
			struct _SVector offset; // size=8, offset=8
		} teleport; // size=16, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} cameraValue; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} miscValue; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} logicValue; // size=8, offset=0, found in object files: player.o, player.o
		long timer; // size=0, offset=0
		long times; // size=0, offset=0
		long lightGroup; // size=0, offset=0
		long farPlane; // size=0, offset=0
		long cameraAdjust; // size=0, offset=0
		long cameraMode; // size=0, offset=0
		long cameraLock; // size=0, offset=0
		long cameraUnlock; // size=0, offset=0
		long cameraSmooth; // size=0, offset=0
		long cameraTimer; // size=0, offset=0
		struct {
			long time; // size=0, offset=0
			long scale; // size=0, offset=4
		} cameraShake; // size=8, offset=0, found in object files: player.o, player.o
		long cameraSave; // size=0, offset=0
		long cameraRestore; // size=0, offset=0
		struct _BGObject *bgObject; // size=24, offset=0
		long value[2]; // size=8, offset=0
		struct {
			long action; // size=0, offset=0
			long value[2]; // size=8, offset=4
		} sound; // size=12, offset=0, found in object files: player.o, player.o
		void *intro; // size=0, offset=0
		long deathZ; // size=0, offset=0
		struct {
			void *intro; // size=0, offset=0
			void *data; // size=0, offset=4
		} dsignal; // size=8, offset=0, found in object files: player.o, player.o
		void *mirror; // size=0, offset=0
		long fogNear; // size=0, offset=0
		long fogFar; // size=0, offset=0
		struct {
			void *intro; // size=0, offset=0
			long frame; // size=0, offset=4
		} gotoFrame; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			void *intro; // size=0, offset=0
			long model; // size=0, offset=4
		} changeModel; // size=8, offset=0, found in object files: player.o, player.o
		void *vmObject; // size=0, offset=0
		struct {
			unsigned char target; // size=0, offset=0
			unsigned char source1; // size=0, offset=1
			unsigned char source2; // size=0, offset=2
			unsigned char pad; // size=0, offset=3
			struct Signal *gotoLabel; // size=0, offset=4
		} logic; // size=8, offset=0, found in object files: player.o, player.o
		void *callSignal; // size=0, offset=0
		struct _SVector offset; // size=8, offset=0
		struct Signal *gotoLabel; // size=0, offset=0
		struct Signal *gosubLabel; // size=0, offset=0
		struct {
			long timer; // size=0, offset=0
			long action; // size=0, offset=4
		} control; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			short index; // size=0, offset=0
			short z; // size=0, offset=2
			struct MultiSignal *upSignal; // size=0, offset=4
			struct MultiSignal *downSignal; // size=0, offset=8
		} zSignal; // size=12, offset=0, found in object files: player.o, player.o
		struct {
			long currentnum; // size=0, offset=0
			long streamID; // size=0, offset=4
			char toname[16]; // size=16, offset=8
		} StreamLevel; // size=24, offset=0, found in object files: player.o, player.o
		struct {
			char num; // size=0, offset=0
			char vel; // size=0, offset=1
			short misc; // size=0, offset=2
			char flags; // size=0, offset=4
			char timeToLive; // size=0, offset=5
			short dummy2; // size=0, offset=6
			struct Object *object; // size=0, offset=8
		} shards; // size=12, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			void *intro; // size=0, offset=4
		} cameraSpline; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			short type; // size=0, offset=0
			short time; // size=0, offset=2
		} screenWipe; // size=4, offset=0, found in object files: player.o, player.o
		long voiceSitId; // size=0, offset=0
		struct {
			long time; // size=0, offset=0
			void *intro; // size=0, offset=4
		} introFX; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			void *intro; // size=0, offset=0
			struct Signal *gotoLabel; // size=0, offset=4
		} introActive; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			char world[9]; // size=9, offset=0
			char level[9]; // size=9, offset=9
		} levelChange; // size=18, offset=0, found in object files: player.o, player.o
		long blendStart; // size=0, offset=0
		struct {
			struct Signal *signal; // size=0, offset=0
			long times; // size=0, offset=4
		} setTimes; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			unsigned char r; // size=0, offset=0
			unsigned char g; // size=0, offset=1
			unsigned char b; // size=0, offset=2
			unsigned char pad; // size=0, offset=3
		} color; // size=4, offset=0, found in object files: player.o, player.o
		struct {
			short x; // size=0, offset=0
			short y; // size=0, offset=2
			short time; // size=0, offset=4
			short index; // size=0, offset=6
			char *text; // size=0, offset=8
		} print; // size=12, offset=0, found in object files: player.o, player.o
		long slideAngle; // size=0, offset=0
	} data; // size=24, offset=4, found in object files: player.o, player.o
};

struct _MultiSignal // hashcode: 0x0620B768 (dec: 102807400)
{
	long numSignals; // size=0, offset=0
	short signalNum; // size=0, offset=4
	short flags; // size=0, offset=6
	struct Signal signalList[32]; // size=896, offset=8
};

struct _HFace // hashcode: 0x30CA5CA6 (dec: 818568358)
{
	short v0; // size=0, offset=0
	short v1; // size=0, offset=2
	short v2; // size=0, offset=4
	unsigned char attr; // size=0, offset=6
	char pad; // size=0, offset=7
	unsigned short normal; // size=0, offset=8
	unsigned short n0; // size=0, offset=10
};

struct _HSphere // hashcode: 0x8E7B7191 (dec: -1904512623)
{
	long attr; // size=0, offset=0
	unsigned char id; // size=0, offset=4
	unsigned char rank; // size=0, offset=5
	short pad; // size=0, offset=6
	struct _Position position; // size=6, offset=8
	unsigned short radius; // size=0, offset=14
	unsigned long radiusSquared; // size=0, offset=16
};

struct _HBox // hashcode: 0x47CD8BDA (dec: 1204653018)
{
	short flags; // size=0, offset=0
	unsigned char id; // size=0, offset=2
	unsigned char rank; // size=0, offset=3
	short minX; // size=0, offset=4
	short minY; // size=0, offset=6
	short minZ; // size=0, offset=8
	short maxX; // size=0, offset=10
	short maxY; // size=0, offset=12
	short maxZ; // size=0, offset=14
	short refMinX; // size=0, offset=16
	short refMinY; // size=0, offset=18
	short refMinZ; // size=0, offset=20
	short refMaxX; // size=0, offset=22
	short refMaxY; // size=0, offset=24
	short refMaxZ; // size=0, offset=26
};

struct _HPrim // hashcode: 0x988F5E11 (dec: -1735434735)
{
	unsigned char hpFlags; // size=0, offset=0
	unsigned char withFlags; // size=0, offset=1
	unsigned char type; // size=0, offset=2
	unsigned char segment; // size=0, offset=3
	union {
		struct _HSphere *hsphere; // size=20, offset=0
		struct _HBox *hbox; // size=28, offset=0
		struct _HFace *hface; // size=12, offset=0
	} data; // size=4, offset=4, found in object files: player.o, player.o
};

struct _HModel // hashcode: 0xBC680356 (dec: -1134034090)
{
	struct _HPrim *hPrimList; // size=8, offset=0
	long numHPrims; // size=0, offset=4
};

struct _HInfo // hashcode: 0x6AC9807F (dec: 1791590527)
{
	long numHFaces; // size=0, offset=0
	struct _HFace *hfaceList; // size=12, offset=4
	long numHSpheres; // size=0, offset=8
	struct _HSphere *hsphereList; // size=20, offset=12
	long numHBoxes; // size=0, offset=16
	struct _HBox *hboxList; // size=28, offset=20
};

struct _Segment // hashcode: 0x2F06BF28 (dec: 788971304)
{
	long flags; // size=0, offset=0
	short firstTri; // size=0, offset=4
	short lastTri; // size=0, offset=6
	short firstVertex; // size=0, offset=8
	short lastVertex; // size=0, offset=10
	short px; // size=0, offset=12
	short py; // size=0, offset=14
	short pz; // size=0, offset=16
	short parent; // size=0, offset=18
	struct _HInfo *hInfo; // size=24, offset=20
};

struct MultiSpline // hashcode: 0x2823B2CF (dec: 673428175)
{
	struct Spline *positional; // size=8, offset=0
	struct RSpline *rotational; // size=8, offset=4
	struct Spline *scaling; // size=8, offset=8
	struct Spline *color; // size=8, offset=12
	struct SplineDef curPositional; // size=8, offset=16
	struct SplineDef curRotational; // size=8, offset=24
	struct SplineDef curScaling; // size=8, offset=32
	struct SplineDef curColor; // size=8, offset=40
	struct MATRIX curRotMatrix; // size=32, offset=48
};

struct SoundInstance // hashcode: 0xFF235679 (dec: -14461319)
{
	unsigned char channel; // size=0, offset=0
	unsigned char state; // size=0, offset=1
	unsigned char delay; // size=0, offset=2
};

struct ObjectEffect // hashcode: 0x2892438D (dec: 680674189)
{
	unsigned char effectNumber; // size=0, offset=0
	unsigned char modifierList[3]; // size=3, offset=1
};

struct VramSize // hashcode: 0xD96A55BF (dec: -647342657)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short w; // size=0, offset=4
	short h; // size=0, offset=6
};

struct _TFace // hashcode: 0x85FE430F (dec: -2046934257)
{
	struct _Face face; // size=6, offset=0
	unsigned char attr; // size=0, offset=6
	char sortPush; // size=0, offset=7
	unsigned short normal; // size=0, offset=8
	unsigned short textoff; // size=0, offset=10
};

struct _TVertex // hashcode: 0x0883ABD5 (dec: 142846933)
{
	struct _Vertex vertex; // size=6, offset=0
	unsigned short rgb15; // size=0, offset=6
	unsigned char r0; // size=0, offset=8
	unsigned char g0; // size=0, offset=9
	unsigned char b0; // size=0, offset=10
	unsigned char code; // size=0, offset=11
};

struct EventAliasCommandStruct // hashcode: 0xB6EF2AF6 (dec: -1225839882)
{
	struct _Instance *hostInstance; // size=0, offset=0
	short newanim; // size=0, offset=4
	short newframe; // size=0, offset=6
	short interpframes; // size=0, offset=8
	short speed; // size=0, offset=10
};

struct Intro // hashcode: 0x796E766D (dec: 2037282413)
{
	char name[16]; // size=16, offset=0
	long intronum; // size=0, offset=16
	long UniqueID; // size=0, offset=20
	struct _Rotation rotation; // size=8, offset=24
	struct _Position position; // size=6, offset=32
	short maxRad; // size=0, offset=38
	long maxRadSq; // size=0, offset=40
	long flags; // size=0, offset=44
	void *data; // size=0, offset=48
	struct _Instance *instance; // size=664, offset=52
	struct MultiSpline *multiSpline; // size=0, offset=56
	void *dsignal; // size=0, offset=60
	short specturalLightGroup; // size=0, offset=64
	short meshColor; // size=0, offset=66
	struct _Position spectralPosition; // size=6, offset=68
	short spad; // size=0, offset=74
};

struct _Terrain // hashcode: 0x5D541B4E (dec: 1565793102)
{
	short UnitChangeFlags; // size=0, offset=0
	short spad; // size=0, offset=2
	long lpad2; // size=0, offset=4
	long numIntros; // size=0, offset=8
	struct Intro *introList; // size=76, offset=12
	long numVertices; // size=0, offset=16
	long numFaces; // size=0, offset=20
	long numNormals; // size=0, offset=24
	struct _TVertex *vertexList; // size=12, offset=28
	struct _TFace *faceList; // size=12, offset=32
	struct _Normal *normalList; // size=8, offset=36
	struct DrMoveAniTex *aniList; // size=8, offset=40
	struct _BSPNode *sbspRoot; // size=44, offset=44
	void *StreamUnits; // size=0, offset=48
	struct TextureFT3 *StartTextureList; // size=12, offset=52
	struct TextureFT3 *EndTextureList; // size=12, offset=56
	struct _SBSPLeaf *sbspStartLeaves; // size=24, offset=60
	struct _SBSPLeaf *sbspEndLeaves; // size=24, offset=64
	struct _MorphVertex *MorphDiffList; // size=14, offset=68
	struct _MorphColor *MorphColorList; // size=2, offset=72
	long numBSPTrees; // size=0, offset=76
	struct BSPTree *BSPTreeArray; // size=36, offset=80
	short *morphNormalIdx; // size=0, offset=84
	struct _MultiSignal *signals; // size=904, offset=88
};

struct _InstancePool // hashcode: 0xC591AB92 (dec: -980309102)
{
	long nextInstanceID; // size=0, offset=0
	long numFreeInstances; // size=0, offset=4
	struct _Instance instance[60]; // size=39840, offset=8
	struct _Instance *first_free; // size=664, offset=39848
};

struct _InstanceList // hashcode: 0x7594B1C7 (dec: 1972679111)
{
	long numInstances; // size=0, offset=0
	struct _Instance *first; // size=664, offset=4
	struct _InstancePool *pool; // size=39852, offset=8
	struct NodeType group[32]; // size=256, offset=12
};

struct _ObjectTracker // hashcode: 0xFE4678BF (dec: -28936001)
{
	char name[16]; // size=16, offset=0
	struct Object *object; // size=76, offset=16
	short objectStatus; // size=0, offset=20
	short numInUse; // size=0, offset=22
	void *vramBlock; // size=0, offset=24
	char numObjectsUsing; // size=0, offset=28
	char objectsUsing[7]; // size=7, offset=29
};

struct _BoundingBox // hashcode: 0x2183782B (dec: 562264107)
{
	short minX; // size=0, offset=0
	short minY; // size=0, offset=2
	short minZ; // size=0, offset=4
	short maxX; // size=0, offset=6
	short maxY; // size=0, offset=8
	short maxZ; // size=0, offset=10
};

struct CDLight // hashcode: 0xD90757B8 (dec: -653830216)
{
	struct NodeType node; // size=8, offset=0
	unsigned char r; // size=0, offset=8
	unsigned char g; // size=0, offset=9
	unsigned char b; // size=0, offset=10
	unsigned char flags; // size=0, offset=11
	struct _Sphere sphere; // size=12, offset=12
};

struct _BSPNode // hashcode: 0x60C20F69 (dec: 1623330665)
{
	struct _Sphere_noSq sphere; // size=8, offset=0
	short a; // size=0, offset=8
	short b; // size=0, offset=10
	short c; // size=0, offset=12
	short flags; // size=0, offset=14
	long d; // size=0, offset=16
	void *front; // size=0, offset=20
	void *back; // size=0, offset=24
	struct _Sphere_noSq spectralSphere; // size=8, offset=28
	short front_spectral_error; // size=0, offset=36
	short back_spectral_error; // size=0, offset=38
	short front_material_error; // size=0, offset=40
	short back_material_error; // size=0, offset=42
};

struct _BSPLeaf // hashcode: 0xB2C1AC71 (dec: -1295930255)
{
	struct _Sphere_noSq sphere; // size=8, offset=0
	struct _TFace *faceList; // size=12, offset=8
	short numFaces; // size=0, offset=12
	short flags; // size=0, offset=14
	struct _BoundingBox box; // size=12, offset=16
	struct _BoundingBox spectralBox; // size=12, offset=28
	struct _Sphere_noSq spectralSphere; // size=8, offset=40
};

struct _SBSPLeaf // hashcode: 0xE9662C63 (dec: -379179933)
{
	struct _Sphere_noSq sphere; // size=8, offset=0
	struct Intro **introList; // size=76, offset=8
	short numIntros; // size=0, offset=12
	short flags; // size=0, offset=14
	struct CDLight **lightList; // size=24, offset=16
	short numLights; // size=0, offset=20
	short pad; // size=0, offset=22
};

struct _MorphVertex // hashcode: 0xD1AD5FA6 (dec: -777166938)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short vindex; // size=0, offset=6
	short hx; // size=0, offset=8
	short hy; // size=0, offset=10
	short hz; // size=0, offset=12
};

struct _MorphColor // hashcode: 0xE6E25EA7 (dec: -421372249)
{
	short morphColor15; // size=0, offset=0
};

struct Level // hashcode: 0xC3AE5FD0 (dec: -1011982384)
{
	struct _Terrain *terrain; // size=92, offset=0
	struct LightList *lightList; // size=12, offset=4
	long numVMObjects; // size=0, offset=8
	struct _VMObject *vmobjectList; // size=60, offset=12
	long numSpotLights; // size=0, offset=16
	struct SpotLight *spotLightList; // size=40, offset=20
	long numPointLights; // size=0, offset=24
	struct PointLight *pointLightList; // size=24, offset=28
	long numSpotSpecturalLights; // size=0, offset=32
	struct SpotLight *spotSpecturalLightList; // size=40, offset=36
	long numPointSpecturalLights; // size=0, offset=40
	struct PointLight *pointSpecturalLightList; // size=24, offset=44
	long numBGObjects; // size=0, offset=48
	struct _BGObject *bgObjectList; // size=24, offset=52
	long waterZLevel; // size=0, offset=56
	unsigned char backColorR; // size=0, offset=60
	unsigned char backColorG; // size=0, offset=61
	unsigned char backColorB; // size=0, offset=62
	unsigned char cpad1; // size=0, offset=63
	unsigned char specturalColorR; // size=0, offset=64
	unsigned char specturalColorG; // size=0, offset=65
	unsigned char specturalColorB; // size=0, offset=66
	unsigned char cpad2; // size=0, offset=67
	unsigned short fogFar; // size=0, offset=68
	unsigned short fogNear; // size=0, offset=70
	unsigned short spectralFogFar; // size=0, offset=72
	unsigned short spectralFogNear; // size=0, offset=74
	unsigned short waterFogFar; // size=0, offset=76
	unsigned short waterFogNear; // size=0, offset=78
	long depthQBlendStart; // size=0, offset=80
	struct LightList *spectrallightList; // size=12, offset=84
	long numCameras; // size=0, offset=88
	void *cameraList; // size=0, offset=92
	long bspPlaneError; // size=0, offset=96
	long numVGroups; // size=0, offset=100
	struct _VGroup *vGroupList; // size=12, offset=104
	long deathZ; // size=0, offset=108
	long flags; // size=0, offset=112
	struct _MultiSignal *startSignal; // size=904, offset=116
	long numIntros; // size=0, offset=120
	struct Intro *introList; // size=76, offset=124
	struct DrMoveAniTex *bgAniList; // size=8, offset=128
	long numHotSpots; // size=0, offset=132
	struct _HotSpot *hotSpotList; // size=8, offset=136
	void *objectNameList; // size=0, offset=140
	long depthQFogStart; // size=0, offset=144
	long morphLastStep; // size=0, offset=148
	char *worldName; // size=0, offset=152
	struct VramSize vramSize; // size=8, offset=156
	unsigned short holdFogFar; // size=0, offset=164
	unsigned short holdFogNear; // size=0, offset=166
	long numberEnemyUnits; // size=0, offset=168
	char **enemyUnitsNames; // size=0, offset=172
	long **timesSignalList; // size=0, offset=176
	struct _MultiSignal *spectralSignal; // size=904, offset=180
	struct _MultiSignal *materialSignal; // size=904, offset=184
	struct _MultiSignal *startUnitLoadedSignal; // size=904, offset=188
	struct _MultiSignal *startUnitMainSignal; // size=904, offset=192
	struct _MultiSignal *startGoingIntoWaterSignal; // size=904, offset=196
	struct _MultiSignal *startGoingOutOfWaterSignal; // size=904, offset=200
	long unitFlags; // size=0, offset=204
	struct _MultiSignal *SignalListStart; // size=904, offset=208
	struct _MultiSignal *SignalListEnd; // size=904, offset=212
	long numBSPLeaves; // size=0, offset=216
	struct EventPointers *PuzzleInstances; // size=0, offset=220
	long NumberOfPlanMarkers; // size=0, offset=224
	struct _PlanMkr *PlanMarkerList; // size=8, offset=228
	long NumberOfSFXMarkers; // size=0, offset=232
	struct _SFXMkr *SFXMarkerList; // size=36, offset=236
	unsigned long versionNumber; // size=0, offset=240
	char *dynamicMusicName; // size=0, offset=244
	long streamUnitID; // size=0, offset=248
	struct TClassAttr tClassAttr[16]; // size=64, offset=252
	short TODLighting[4][3]; // size=24, offset=316
	unsigned char TODbackColor[4][3]; // size=12, offset=340
	unsigned short TODfogNearFar[4][2]; // size=16, offset=352
	short TODRedScale; // size=0, offset=368
	short TODGrnScale; // size=0, offset=370
	short TODBluScale; // size=0, offset=372
	short TODfogNear; // size=0, offset=374
	short TODfogFar; // size=0, offset=376
	short short_pad; // size=0, offset=378
	unsigned char TODbackColorR; // size=0, offset=380
	unsigned char TODbackColorG; // size=0, offset=381
	unsigned char TODbackColorB; // size=0, offset=382
	unsigned char cpad3; // size=0, offset=383
	struct LightGroup *razielLightGroup; // size=64, offset=384
	struct LightGroup *razielSpectralLightGroup; // size=64, offset=388
};

struct _SavedCinematic // hashcode: 0xD17952AA (dec: -780578134)
{
	struct _Position position; // size=6, offset=0
	struct _Position focusPoint; // size=6, offset=6
	struct _Position base; // size=6, offset=12
	struct _Position targetPos; // size=6, offset=18
	struct _Position targetFocusPoint; // size=6, offset=24
	struct _Position targetBase; // size=6, offset=30
	struct _Rotation baseRot; // size=8, offset=36
	struct _Rotation focusRotation; // size=8, offset=44
	struct _Rotation targetFocusRotation; // size=8, offset=52
	short focusDistance; // size=0, offset=60
	short targetFocusDistance; // size=0, offset=62
	struct _SVector focusPointVel; // size=8, offset=64
	struct _SVector focusPointAccl; // size=8, offset=72
	struct _SVector baseVel; // size=8, offset=80
	struct _SVector baseAccl; // size=8, offset=88
	long maxVel; // size=0, offset=96
	struct MultiSpline *posSpline; // size=0, offset=100
	struct MultiSpline *targetSpline; // size=0, offset=104
	struct Level *level; // size=0, offset=108
};

struct BSPTree // hashcode: 0x6BB6F4D3 (dec: 1807152339)
{
	struct _BSPNode *bspRoot; // size=44, offset=0
	struct _BSPLeaf *startLeaves; // size=48, offset=4
	struct _BSPLeaf *endLeaves; // size=48, offset=8
	struct _Position globalOffset; // size=6, offset=12
	short flags; // size=0, offset=18
	struct _Position localOffset; // size=6, offset=20
	short ID; // size=0, offset=26
	long splineID; // size=0, offset=28
	struct _Instance *instanceSpline; // size=664, offset=32
};

struct LightGroup // hashcode: 0x69AA5FCD (dec: 1772773325)
{
	struct MATRIX lightMatrix; // size=32, offset=0
	struct MATRIX colorMatrix; // size=32, offset=32
};

struct LightList // hashcode: 0xC683766C (dec: -964462996)
{
	struct CVECTOR ambient; // size=4, offset=0
	long numLightGroups; // size=0, offset=4
	struct LightGroup *lightGroupList; // size=64, offset=8
};

struct PointLight // hashcode: 0x7AFA283C (dec: 2063214652)
{
	struct NodeType node; // size=8, offset=0
	unsigned char r; // size=0, offset=8
	unsigned char g; // size=0, offset=9
	unsigned char b; // size=0, offset=10
	unsigned char flags; // size=0, offset=11
	struct _Position position; // size=6, offset=12
	short radius; // size=0, offset=18
	long radiusSquared; // size=0, offset=20
};

struct SpotLight // hashcode: 0x83CCA3D6 (dec: -2083740714)
{
	struct NodeType node; // size=8, offset=0
	unsigned char r; // size=0, offset=8
	unsigned char g; // size=0, offset=9
	unsigned char b; // size=0, offset=10
	unsigned char flags; // size=0, offset=11
	struct _Position centroid; // size=6, offset=12
	short radius; // size=0, offset=18
	long radiusSquared; // size=0, offset=20
	struct _Position position; // size=6, offset=24
	struct _Position direction; // size=6, offset=30
	short cosFalloffAngle; // size=0, offset=36
	short attenuationScale; // size=0, offset=38
};

struct LightInfo // hashcode: 0x78922521 (dec: 2022843681)
{
	long numPointLights; // size=0, offset=0
	struct PointLight pointLightPool[32]; // size=768, offset=4
	struct NodeType usedPointLightList; // size=8, offset=772
	struct NodeType freePointLightList; // size=8, offset=780
	struct NodeType activePointLightList; // size=8, offset=788
	long numSpotLights; // size=0, offset=796
	struct SpotLight spotLightPool[8]; // size=320, offset=800
	struct NodeType usedSpotLightList; // size=8, offset=1120
	struct NodeType freeSpotLightList; // size=8, offset=1128
	struct NodeType activeSpotLightList; // size=8, offset=1136
	long numSavedColors; // size=0, offset=1144
};

struct _VMOffset // hashcode: 0xF7C87D30 (dec: -137855696)
{
	short dx; // size=0, offset=0
	short dy; // size=0, offset=2
	short dz; // size=0, offset=4
};

struct _VMColorOffset // hashcode: 0x55170A20 (dec: 1427573280)
{
	char dr; // size=0, offset=0
	char dg; // size=0, offset=1
	char db; // size=0, offset=2
};

struct _VMInterpolated // hashcode: 0x89F7E225 (dec: -1980243419)
{
	short tvIdx; // size=0, offset=0
	short startIdx; // size=0, offset=2
	short endIdx; // size=0, offset=4
	short time; // size=0, offset=6
};

struct _VMOffsetTable // hashcode: 0xF8DA9021 (dec: -119893983)
{
	long numVMOffsets; // size=0, offset=0
	union {
		struct _VMOffset moveOffsets; // size=6, offset=0
		struct _VMColorOffset colorOffsets; // size=3, offset=0
	} offsets; // size=6, offset=4, found in object files: player.o, player.o
};

struct _VMObject // hashcode: 0xEF326061 (dec: -281911199)
{
	unsigned short flags; // size=0, offset=0
	short bspIdx; // size=0, offset=2
	short materialIdx; // size=0, offset=4
	short spectralIdx; // size=0, offset=6
	short currentIdx; // size=0, offset=8
	short timeScale; // size=0, offset=10
	long timer; // size=0, offset=12
	struct _Position position; // size=6, offset=16
	short radius; // size=0, offset=22
	long radiusSquared; // size=0, offset=24
	long numVMOffsetTables; // size=0, offset=28
	struct _VMOffsetTable **vmoffsetTableList; // size=12, offset=32
	struct _VMOffsetTable *curVMOffsetTable; // size=12, offset=36
	long numVMVertices; // size=0, offset=40
	void *vmvertexList; // size=0, offset=44
	long numVMInterpolated; // size=0, offset=48
	struct _VMInterpolated *vminterpolatedList; // size=8, offset=52
	char *name; // size=0, offset=56
};

struct _VGroup // hashcode: 0xB57433BB (dec: -1250675781)
{
	long id; // size=0, offset=0
	long numVertices; // size=0, offset=4
	struct _TVertex **vertexList; // size=12, offset=8
};

struct _HotSpot // hashcode: 0x46C1F2C3 (dec: 1187115715)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short id; // size=0, offset=6
};

struct _PlanMkr // hashcode: 0x0C3AB7E6 (dec: 205174758)
{
	struct _Position pos; // size=6, offset=0
	short id; // size=0, offset=6
};

struct _SFXMkr // hashcode: 0x35415AA9 (dec: 893475497)
{
	unsigned char *soundData; // size=0, offset=0
	long uniqueID; // size=0, offset=4
	struct SoundInstance sfxTbl[4]; // size=12, offset=8
	struct _Position pos; // size=6, offset=20
	short pad; // size=0, offset=26
	long livesInOnePlace; // size=0, offset=28
	long inSpectral; // size=0, offset=32
};

struct TClassAttr // hashcode: 0x7807BF4D (dec: 2013773645)
{
	short flags; // size=0, offset=0
	unsigned short sound; // size=0, offset=2
};

struct _ColorType // hashcode: 0xAC51C547 (dec: -1403927225)
{
	unsigned char r; // size=0, offset=0
	unsigned char g; // size=0, offset=1
	unsigned char b; // size=0, offset=2
	unsigned char code; // size=0, offset=3
};

struct _CameraCore_Type // hashcode: 0x581965E4 (dec: 1478059492)
{
	struct _Position position; // size=6, offset=0
	short pad1; // size=0, offset=6
	struct MATRIX vvNormalWorVecMat[2]; // size=64, offset=8
	long vvPlaneConsts[6]; // size=24, offset=72
	struct MATRIX *wcTransform; // size=32, offset=96
	long farPlane; // size=0, offset=100
	long projDistance; // size=0, offset=104
	long nearPlane; // size=0, offset=108
	struct MATRIX *wcTransform2; // size=32, offset=112
	struct MATRIX *cwTransform2; // size=32, offset=116
	struct _Normal viewVolumeNormal[5]; // size=40, offset=120
	int leftX; // size=0, offset=160
	int rightX; // size=0, offset=164
	int topY; // size=0, offset=168
	int bottomY; // size=0, offset=172
	struct _Rotation rotation; // size=8, offset=176
	short pad2; // size=0, offset=184
	struct _SVector screenScale; // size=8, offset=186
	short pad3; // size=0, offset=194
	struct _Position debugPos; // size=6, offset=196
	short pad4; // size=0, offset=202
	struct _Rotation debugRot; // size=8, offset=204
	short pad5; // size=0, offset=212
	struct _Position nondebugPos; // size=6, offset=214
	short pad6; // size=0, offset=220
};

struct PLAYER_114fake // hashcode: 0xCB9D3D9A (dec: -878887526)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: player.o, player.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: player.o, player.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: player.o, player.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: player.o, player.o
};

struct SpuVolume // hashcode: 0xED294644 (dec: -316062140)
{
	short left; // size=0, offset=0
	short right; // size=0, offset=2
};

struct SpuExtAttr // hashcode: 0x58B0F474 (dec: 1487991924)
{
	struct SpuVolume volume; // size=4, offset=0
	long reverb; // size=0, offset=4
	long mix; // size=0, offset=8
};

struct SpuStVoiceAttr // hashcode: 0xAFDFBA7E (dec: -1344292226)
{
	char status; // size=0, offset=0
	char pad1; // size=0, offset=1
	char pad2; // size=0, offset=2
	char pad3; // size=0, offset=3
	long last_size; // size=0, offset=4
	unsigned long buf_addr; // size=0, offset=8
	unsigned long data_addr; // size=0, offset=12
};

struct AadSoundBankHdr // hashcode: 0x453DB83F (dec: 1161672767)
{
	unsigned long bankID; // size=0, offset=0
	unsigned long headerSize; // size=0, offset=4
	unsigned short bankVersion; // size=0, offset=8
	unsigned char numBanks; // size=0, offset=10
	unsigned char numPrograms; // size=0, offset=11
	unsigned short numTones; // size=0, offset=12
	unsigned short numWaves; // size=0, offset=14
	unsigned char numSequences; // size=0, offset=16
	unsigned char numPitchMaps; // size=0, offset=17
	unsigned short numLabels; // size=0, offset=18
	unsigned char reverbMode; // size=0, offset=20
	unsigned char unused1; // size=0, offset=21
	short reverbDepth; // size=0, offset=22
	unsigned short objectID; // size=0, offset=24
	unsigned short unused2; // size=0, offset=26
	unsigned long unused3; // size=0, offset=28
	unsigned long unused4; // size=0, offset=32
	unsigned long unused5; // size=0, offset=36
	unsigned long unused6; // size=0, offset=40
	unsigned long unused7; // size=0, offset=44
	unsigned long unused8; // size=0, offset=48
	unsigned long unused9; // size=0, offset=52
	unsigned long unused10; // size=0, offset=56
	unsigned long unused11; // size=0, offset=60
	unsigned long unused12; // size=0, offset=64
	unsigned long unused13; // size=0, offset=68
	unsigned long unused14; // size=0, offset=72
	unsigned long unused15; // size=0, offset=76
	unsigned char baseProgramTbl[16]; // size=16, offset=80
	unsigned short baseToneTbl[16]; // size=32, offset=96
};

struct AadProgramAtr // hashcode: 0x13FC0BEF (dec: 335285231)
{
	unsigned short numTones; // size=0, offset=0
	unsigned short firstTone; // size=0, offset=2
	unsigned char volume; // size=0, offset=4
	unsigned char panPosition; // size=0, offset=5
	unsigned short unused; // size=0, offset=6
};

struct AadToneAtr // hashcode: 0x990CD685 (dec: -1727211899)
{
	unsigned char priority; // size=0, offset=0
	unsigned char parentProgram; // size=0, offset=1
	unsigned char volume; // size=0, offset=2
	unsigned char panPosition; // size=0, offset=3
	unsigned char centerNote; // size=0, offset=4
	char centerFine; // size=0, offset=5
	unsigned char minNote; // size=0, offset=6
	unsigned char maxNote; // size=0, offset=7
	unsigned char mode; // size=0, offset=8
	unsigned char pitchBendMax; // size=0, offset=9
	unsigned short adsr1; // size=0, offset=10
	unsigned short adsr2; // size=0, offset=12
	short waveIndex; // size=0, offset=14
};

struct _AadDynSfxFileHdr // hashcode: 0xB9609773 (dec: -1184852109)
{
	unsigned long snfID; // size=0, offset=0
	unsigned short snfVersion; // size=0, offset=4
	unsigned short uniqueID; // size=0, offset=6
	unsigned short handle; // size=0, offset=8
	unsigned short numSfxInFile; // size=0, offset=10
	struct _AadDynSfxFileHdr *prevDynSfxFile; // size=20, offset=12
	struct _AadDynSfxFileHdr *nextDynSfxFile; // size=20, offset=16
};

struct AadDynSfxAttr // hashcode: 0x20751E4B (dec: 544546379)
{
	unsigned short sfxID; // size=0, offset=0
	unsigned short waveID; // size=0, offset=2
	struct AadToneAtr toneAttr; // size=16, offset=4
	unsigned long waveSize; // size=0, offset=20
};

struct AadTempoCounter // hashcode: 0x15707CC0 (dec: 359693504)
{
	unsigned long currentTick; // size=0, offset=0
	unsigned long currentError; // size=0, offset=4
	unsigned long tickTimeFixed; // size=0, offset=8
	unsigned long errorPerUpdate; // size=0, offset=12
	unsigned short ticksPerUpdate; // size=0, offset=16
	unsigned short ppqn; // size=0, offset=18
	unsigned long quarterNoteTime; // size=0, offset=20
};

struct AadSeqEvent // hashcode: 0x3E306185 (dec: 1043358085)
{
	unsigned long deltaTime; // size=0, offset=0
	unsigned char track; // size=0, offset=4
	unsigned char statusByte; // size=0, offset=5
	char dataByte[6]; // size=6, offset=6
};

struct _AadSequenceSlot // hashcode: 0xD7421DD6 (dec: -683532842)
{
	struct AadTempoCounter tempo; // size=24, offset=0
	struct AadSeqEvent eventQueue[4][16]; // size=768, offset=24
	unsigned char eventIn[16]; // size=16, offset=792
	unsigned char eventOut[16]; // size=16, offset=808
	unsigned char eventsInQueue[16]; // size=16, offset=824
	unsigned char (*sequencePosition[16]); // size=64, offset=840
	unsigned long lastEventExecutedTime[16]; // size=64, offset=904
	unsigned char runningStatus[16]; // size=16, offset=968
	unsigned char trackFlags[16]; // size=16, offset=984
	unsigned char (*loopSequencePosition[4][16]); // size=256, offset=1000
	unsigned char loopCurrentNestLevel[16]; // size=16, offset=1256
	unsigned char loopCounter[4][16]; // size=64, offset=1272
	struct _AadSequenceSlot *selectedSlotPtr; // size=1492, offset=1336
	unsigned char selectedSlotNum; // size=0, offset=1340
	unsigned char selectedChannel; // size=0, offset=1341
	unsigned char sequenceNumberAssigned; // size=0, offset=1342
	unsigned char thisSlotNumber; // size=0, offset=1343
	unsigned short status; // size=0, offset=1344
	unsigned short channelMute; // size=0, offset=1346
	unsigned short enableSustainUpdate; // size=0, offset=1348
	unsigned short ignoreTranspose; // size=0, offset=1350
	unsigned char slotFlags; // size=0, offset=1352
	unsigned char slotID; // size=0, offset=1353
	unsigned char slotVolume; // size=0, offset=1354
	unsigned char slotPan; // size=0, offset=1355
	unsigned char *masterVolPtr; // size=0, offset=1356
	unsigned char selectedDynamicBank; // size=0, offset=1360
	unsigned char sequenceAssignedDynamicBank; // size=0, offset=1361
	unsigned short unused1; // size=0, offset=1362
	unsigned char currentDynamicBank[16]; // size=16, offset=1364
	unsigned short pitchWheel[16]; // size=32, offset=1380
	unsigned char currentProgram[16]; // size=16, offset=1412
	unsigned char baseProgram[16]; // size=16, offset=1428
	unsigned char volume[16]; // size=16, offset=1444
	unsigned char panPosition[16]; // size=16, offset=1460
	char transpose[16]; // size=16, offset=1476
};

struct AadSfxCommand // hashcode: 0xD8F832F6 (dec: -654822666)
{
	unsigned char statusByte; // size=0, offset=0
	unsigned char dataByte[3]; // size=3, offset=1
	unsigned long ulongParam; // size=0, offset=4
	short shortParam; // size=0, offset=8
	unsigned short unused; // size=0, offset=10
};

struct AadSfxSlot // hashcode: 0x6E655A78 (dec: 1852136056)
{
	struct AadSfxCommand commandQueue[32]; // size=384, offset=0
	unsigned char commandIn; // size=0, offset=384
	unsigned char commandOut; // size=0, offset=385
	unsigned short commandsInQueue; // size=0, offset=386
	unsigned short handleCounter; // size=0, offset=388
	unsigned char sfxVolume; // size=0, offset=390
	unsigned char sfxPan; // size=0, offset=391
};

struct AadSynthVoice // hashcode: 0x12E02CA2 (dec: 316681378)
{
	unsigned long voiceMask; // size=0, offset=0
	unsigned long handle; // size=0, offset=4
	unsigned char voiceID; // size=0, offset=8
	unsigned char priority; // size=0, offset=9
	unsigned char note; // size=0, offset=10
	unsigned char unused; // size=0, offset=11
	unsigned char program; // size=0, offset=12
	unsigned char baseProg; // size=0, offset=13
	unsigned char volume; // size=0, offset=14
	unsigned char updateVol; // size=0, offset=15
	unsigned char pan; // size=0, offset=16
	unsigned char voiceNum; // size=0, offset=17
	unsigned short flags; // size=0, offset=18
	struct AadToneAtr *toneAtr; // size=16, offset=20
	struct AadProgramAtr *progAtr; // size=8, offset=24
};

struct AadDynamicLoadRequest // hashcode: 0xB68D12F8 (dec: -1232268552)
{
	unsigned short type; // size=0, offset=0
	unsigned short handle; // size=0, offset=2
	unsigned long userData; // size=0, offset=4
	char fileName[40]; // size=40, offset=8
	union {
		void (*dynSfxReturnProc)(); // size=0, offset=0
		void (*dynMusReturnProc)(); // size=0, offset=0
	} u; // size=4, offset=48, found in object files: player.o, player.o
};

struct AadDynamicBankLoadInfo // hashcode: 0xBC8E127A (dec: -1131539846)
{
	char *sndFileName; // size=0, offset=0
	char *smpFileName; // size=0, offset=4
	unsigned short dynamicBankIndex; // size=0, offset=8
	unsigned short loadOption; // size=0, offset=10
	void (*userCallbackProc)(); // size=0, offset=12
	unsigned long sramDataSize; // size=0, offset=16
	unsigned long nextSramAddr; // size=0, offset=20
	unsigned long flags; // size=0, offset=24
};

struct AadDynamicSfxLoadInfo // hashcode: 0x19283748 (dec: 422065992)
{
	char snfFileName[40]; // size=40, offset=0
	char smfFileName[40]; // size=40, offset=40
	unsigned long userData; // size=0, offset=80
	void (*userCallbackProc)(); // size=0, offset=84
	unsigned short flags; // size=0, offset=88
	unsigned short smfLoadingState; // size=0, offset=90
	unsigned long bytesToLoad; // size=0, offset=92
	unsigned short numSfxToLoad; // size=0, offset=96
	unsigned short error; // size=0, offset=98
	unsigned long waveTransferAddr; // size=0, offset=100
	unsigned long totalSramUsed; // size=0, offset=104
	unsigned short fileHandle; // size=0, offset=108
	unsigned short unused; // size=0, offset=110
	struct _AadDynSfxFileHdr *snfFile; // size=20, offset=112
	struct AadDynSfxAttr attr; // size=24, offset=116
};

struct AadNewSramBlockDesc // hashcode: 0xCD1D2552 (dec: -853727918)
{
	unsigned short waveID; // size=0, offset=0
	unsigned short address; // size=0, offset=2
	unsigned short size; // size=0, offset=4
	unsigned char prevIndex; // size=0, offset=6
	unsigned char nextIndex; // size=0, offset=7
};

struct AadLoadedSfxToneAttr // hashcode: 0xFD77D066 (dec: -42479514)
{
	unsigned short referenceCount; // size=0, offset=0
	unsigned short waveID; // size=0, offset=2
	struct AadToneAtr toneAttr; // size=16, offset=4
};

struct AadLoadedSfxWaveAttr // hashcode: 0xF1726163 (dec: -244162205)
{
	unsigned short referenceCount; // size=0, offset=0
	unsigned char unused; // size=0, offset=2
	unsigned char sramHandle; // size=0, offset=3
};

struct AadMasterVolFader // hashcode: 0xDED3738B (dec: -556567669)
{
	short volumeStep; // size=0, offset=0
	short targetVolume; // size=0, offset=2
	void (*fadeCompleteCallback)(); // size=0, offset=4
};

struct AadVolFader // hashcode: 0x154D2357 (dec: 357376855)
{
	short volumeStep; // size=0, offset=0
	short targetVolume; // size=0, offset=2
	void (*fadeCompleteCallback)(); // size=0, offset=4
};

struct gSoundData // hashcode: 0x100090FC (dec: 268472572)
{
	unsigned long gMasterVol; // size=0, offset=0
	unsigned long gMusicVol; // size=0, offset=4
	unsigned long gSfxVol; // size=0, offset=8
	unsigned long gVoiceVol; // size=0, offset=12
	char gSfxOn; // size=0, offset=16
	char gMusicOn; // size=0, offset=17
	char gVoiceOn; // size=0, offset=18
	char soundsLoaded; // size=0, offset=19
};

struct GameTracker // hashcode: 0x4EB3EFC5 (dec: 1320415173)
{
	struct _GameData_Type gameData; // size=32, offset=0
	struct menu_t *menu; // size=0, offset=32
	struct memcard_t *memcard; // size=0, offset=36
	struct Level *level; // size=392, offset=40
	struct _Instance *playerInstance; // size=664, offset=44
	long drawPage; // size=0, offset=48
	struct _InstanceList *instanceList; // size=268, offset=52
	struct _InstancePool *instancePool; // size=39852, offset=56
	struct _VertexPool *vertexPool; // size=6336, offset=60
	struct _PrimPool *primPool; // size=96012, offset=64
	struct _ObjectTracker *GlobalObjects; // size=36, offset=68
	long controlCommand[2][5]; // size=40, offset=72
	long controlData[2][5]; // size=40, offset=112
	long overrideData[2][5]; // size=40, offset=152
	long debugFlags; // size=0, offset=192
	long debugFlags2; // size=0, offset=196
	struct CVECTOR wipeColor; // size=4, offset=200
	short wipeTime; // size=0, offset=204
	short maxWipeTime; // size=0, offset=206
	short wipeType; // size=0, offset=208
	short numGSignals; // size=0, offset=210
	void (*gSignal[16]); // size=64, offset=212
	struct LightInfo *lightInfo; // size=1148, offset=276
	void *reqDisp; // size=0, offset=280
	long *drawTimerReturn; // size=0, offset=284
	long usecsStartDraw; // size=0, offset=288
	void *disp; // size=0, offset=292
	unsigned long displayFrameCount; // size=0, offset=296
	unsigned long frameCount; // size=0, offset=300
	unsigned long fps30Count; // size=0, offset=304
	unsigned long vblFrames; // size=0, offset=308
	unsigned long vblCount; // size=0, offset=312
	long numMatrices; // size=0, offset=316
	long gameFlags; // size=0, offset=320
	long streamFlags; // size=0, offset=324
	void *drawNonAnimatedSegmentFunc; // size=0, offset=328
	void *drawAnimatedModelFunc; // size=0, offset=332
	void *drawDisplayPolytopeListFunc; // size=0, offset=336
	void *drawBgFunc; // size=0, offset=340
	struct Level *mainDrawUnit; // size=392, offset=344
	char baseAreaName[16]; // size=16, offset=348
	short levelDone; // size=0, offset=364
	short levelChange; // size=0, offset=366
	short hideBG; // size=0, offset=368
	short gameMode; // size=0, offset=370
	long currentHotSpot; // size=0, offset=372
	long StreamUnitID; // size=0, offset=376
	short SwitchToNewStreamUnit; // size=0, offset=380
	short SwitchToNewWarpIndex; // size=0, offset=382
	char S_baseAreaName[16]; // size=16, offset=384
	short toSignal; // size=0, offset=400
	short fromSignal; // size=0, offset=402
	char LastSignal; // size=0, offset=404
	short StreamNormalA; // size=0, offset=406
	short StreamNormalB; // size=0, offset=408
	short StreamNormalC; // size=0, offset=410
	long StreamNormalD; // size=0, offset=412
	long moveRazielToStreamID; // size=0, offset=416
	struct _ColorType animObjLine; // size=4, offset=420
	struct _ColorType animObjShade; // size=4, offset=424
	long introFXTime; // size=0, offset=428
	long maxIntroFXTime; // size=0, offset=432
	struct gSoundData sound; // size=20, offset=436
	short controllerMode; // size=0, offset=456
	short cheatMode; // size=0, offset=458
	char curDynamicSoundName[16]; // size=16, offset=460
	char currentLvl; // size=0, offset=476
	char lastLvl; // size=0, offset=477
	struct Object *introFX; // size=76, offset=480
	struct Intro *introFXIntro; // size=76, offset=484
	unsigned long **drawOT; // size=0, offset=488
	unsigned long **dispOT; // size=0, offset=492
	struct P_TAG *savedOTStart; // size=8, offset=496
	struct P_TAG *savedOTEnd; // size=8, offset=500
	long introWaitTime; // size=0, offset=504
	long mirrorZPush; // size=0, offset=508
	long defVVRemoveDist; // size=0, offset=512
	long defRemoveDist; // size=0, offset=516
	struct _Position forcedStartPosition; // size=6, offset=520
	short hudCollDisplay; // size=0, offset=526
	long primMemUsed; // size=0, offset=528
	char demoMode; // size=0, offset=532
	char setDemoMode; // size=0, offset=533
	char demoIndex; // size=0, offset=534
	char demoEnabled; // size=0, offset=535
	long cheatTimerCount; // size=0, offset=536
	long playerCheatFlags; // size=0, offset=540
	long savedPlayerCameraMode; // size=0, offset=544
	long debugDrawFlags; // size=0, offset=548
	void *planningPool; // size=0, offset=552
	void *enemyPlanPool; // size=0, offset=556
	unsigned char block_collide_override; // size=0, offset=560
	unsigned char raziel_collide_override; // size=0, offset=561
	short timeOfDay; // size=0, offset=562
	long decoupleGame; // size=0, offset=564
	long multGameTime; // size=0, offset=568
	short spectral_fadeValue; // size=0, offset=572
	short material_fadeValue; // size=0, offset=574
	unsigned long drawTime; // size=0, offset=576
	unsigned long currentTime; // size=0, offset=580
	unsigned long currentMaterialTime; // size=0, offset=584
	unsigned long currentSpectralTime; // size=0, offset=588
	unsigned long currentTimeOfDayTime; // size=0, offset=592
	unsigned long lastLoopTime; // size=0, offset=596
	unsigned long timeMult; // size=0, offset=600
	unsigned long globalTimeMult; // size=0, offset=604
	unsigned long spectralTimeMult; // size=0, offset=608
	unsigned long materialTimeMult; // size=0, offset=612
	unsigned long currentTicks; // size=0, offset=616
	unsigned long totalTime; // size=0, offset=620
	unsigned long idleTime; // size=0, offset=624
	long visibleInstances; // size=0, offset=628
	int gameFramePassed; // size=0, offset=632
	unsigned long timeSinceLastGameFrame; // size=0, offset=636
	long frameRateLock; // size=0, offset=640
	short frameRate24fps; // size=0, offset=644
};

struct Spline // hashcode: 0xA7B8D53F (dec: -1481059009)
{
	struct SplineKey *key; // size=32, offset=0
	short numkeys; // size=0, offset=4
	unsigned char type; // size=0, offset=6
	unsigned char flags; // size=0, offset=7
};

struct vecS // hashcode: 0xEADB8F3A (dec: -354709702)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct vecL // hashcode: 0x7575CB14 (dec: 1970653972)
{
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

struct SplineRotKey // hashcode: 0xD2E3A87E (dec: -756832130)
{
	short count; // size=0, offset=0
	struct _G2Quat_Type q; // size=8, offset=2
};

struct RSpline // hashcode: 0xD9C500BD (dec: -641400643)
{
	struct SplineRotKey *key; // size=10, offset=0
	short numkeys; // size=0, offset=4
	unsigned char type; // size=0, offset=6
	unsigned char flags; // size=0, offset=7
};

struct SplineKey // hashcode: 0x5D3D994D (dec: 1564318029)
{
	short count; // size=0, offset=0
	struct vecS point; // size=6, offset=2
	struct vecL dd; // size=12, offset=8
	struct vecL ds; // size=12, offset=20
};

struct SplineDef // hashcode: 0x04DD5459 (dec: 81613913)
{
	short currkey; // size=0, offset=0
	unsigned short denomFlag; // size=0, offset=2
	long fracCurr; // size=0, offset=4
};

struct _HVertex // hashcode: 0xC488A83D (dec: -997676995)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short normal; // size=0, offset=6
	long pad; // size=0, offset=8
};

struct _MONAPI_Regenerator // hashcode: 0x37E0AA1B (dec: 937470491)
{
	unsigned long regenTime; // size=0, offset=0
	short introUniqueID; // size=0, offset=4
	short streamUnitID; // size=0, offset=6
};

enum DEBUG_LINE_TYPE // Hashcode: 0xC0FB4779 (dec: -1057273991)
{
	DEBUG_LINE_TYPE_BIT = 0,
	DEBUG_LINE_TYPE_LONG = 1,
	DEBUG_LINE_TYPE_ACTION = 2,
	DEBUG_LINE_TYPE_ACTION_WITH_LINE = 3,
	DEBUG_LINE_TYPE_MENU = 4,
	DEBUG_LINE_TYPE_ENDLIST = 5,
	DEBUG_LINE_TYPE_FORMAT = 6,
	DEBUG_LINE_TYPE_INFO = 7,
};

struct __Event // hashcode: 0xBC16D673 (dec: -1139353997)
{
	int ID; // size=0, offset=0
	int Data; // size=0, offset=4
};

struct __MessageQueue // hashcode: 0x473062B5 (dec: 1194353333)
{
	int Head; // size=0, offset=0
	int Tail; // size=0, offset=4
	struct __Event Queue[16]; // size=128, offset=8
};

struct __State // hashcode: 0xA27CC1F7 (dec: -1568882185)
{
	void (*Process)(); // size=0, offset=0
	struct __MessageQueue Event; // size=136, offset=4
	struct __MessageQueue Defer; // size=136, offset=140
	int Data1; // size=0, offset=276
	int Data2; // size=0, offset=280
};

union PLAYER_203fake // Hashcode: 0xD9D68A52 (dec: -640251310)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct MATRIX MATRIX;

typedef struct VECTOR VECTOR;

typedef struct SVECTOR SVECTOR;

typedef struct CVECTOR CVECTOR;

typedef struct DVECTOR DVECTOR;

typedef struct RVECTOR RVECTOR;

typedef struct CRVECTOR3 CRVECTOR3;

typedef struct CRVECTOR4 CRVECTOR4;

typedef struct RECT RECT;

typedef struct DR_ENV DR_ENV;

typedef struct P_TAG P_TAG;

typedef struct CdlLOC CdlLOC;

typedef struct LightInstance LightInstance;

typedef struct _GameTrackerASMData_Type GameTrackerASMData;

typedef struct _GameData_Type GameData;

typedef struct NodeType NodeType;

typedef struct TextureFT3 TextureFT3;

typedef struct TextureMT3 TextureMT3;

typedef struct AniTexInfo AniTexInfo;

typedef struct AniTex AniTex;

typedef struct DrMoveAniTexSrcInfo DrMoveAniTexSrcInfo;

typedef struct DrMoveAniTexDestInfo DrMoveAniTexDestInfo;

typedef struct DrMoveAniTex DrMoveAniTex;

typedef struct MemHeader MemHeader;

typedef enum _G2Bool_Enum G2Bool;

typedef struct _G2SVector3_Type G2SVector3;

typedef struct _G2LVector3_Type G2LVector3;

typedef struct _G2Matrix_Type G2Matrix;

typedef struct _G2Quat_Type G2Quat;

typedef struct _G2AnimQuatInfo_Type G2AnimQuatInfo;

typedef struct _G2AnimAlphaTable_Type G2AnimAlphaTable;

typedef struct _G2AnimInterpStateBlock_Type G2AnimInterpStateBlock;

typedef struct _G2AnimInterpInfo_Type G2AnimInterpInfo;

typedef struct _G2AnimChanStatus_Type G2AnimChanStatus;

typedef struct _G2AnimChanStatusBlock_Type G2AnimChanStatusBlock;

typedef struct _G2AnimFxHeader_Type G2AnimFxHeader;

typedef struct _G2AnimKeylist_Type G2AnimKeylist;

typedef struct _G2AnimSection_Type G2AnimSection;

typedef struct _G2Anim_Type G2Anim;

typedef struct _SVector SVector;

typedef struct _SVectorNoPad SVectorNoPad;

typedef struct MATRIX Transform;

typedef struct _Position Position;

typedef struct _Rotation Rotation;

typedef struct _Normal Normal;

typedef struct _PlaneConstants PlaneConstants;

typedef struct _Vertex Vertex;

typedef struct _Face Face;

typedef struct _MVertex MVertex;

typedef struct _MFace MFace;

typedef struct _RGBAColor RGBAColor;

typedef struct _PVertex PVertex;

typedef struct _VertexPool VertexPool;

typedef struct _PrimPool PrimPool;

typedef struct _Sphere Sphere;

typedef struct _Sphere_noSq Sphere_noSq;

typedef struct _CameraKey CameraKey;

typedef struct Object Object;

typedef struct _BVertex BVertex;

typedef struct _BFace BFace;

typedef struct _BGObject BGObject;

typedef struct Signal Signal;

typedef struct _MultiSignal MultiSignal;

typedef struct _HFace HFace;

typedef struct _HSphere HSphere;

typedef struct _HBox HBox;

typedef struct _HPrim HPrim;

typedef struct _HModel HModel;

typedef struct _HInfo HInfo;

typedef struct _Segment Segment;

typedef struct MultiSpline MultiSpline;

typedef struct _Model Model;

typedef struct SoundInstance SoundInstance;

typedef struct ObjectEffect ObjectEffect;

typedef struct ObjectEffect AnimEffectData;

typedef struct VramSize VramSize;

typedef struct _TFace TFace;

typedef struct _TVertex TVertex;

typedef struct EventAliasCommandStruct EventAliasCommandStruct;

typedef struct _Instance Instance;

typedef struct _InstancePool InstancePool;

typedef struct _InstanceList InstanceList;

typedef struct _ObjectTracker ObjectTracker;

typedef struct Intro Intro;

typedef struct _BoundingBox BoundingBox;

typedef struct CDLight CDLight;

typedef struct _BSPNode BSPNode;

typedef struct _BSPNode SBSPNode;

typedef struct _BSPLeaf BSPLeaf;

typedef struct _SBSPLeaf SBSPLeaf;

typedef struct _MorphVertex MorphVertex;

typedef struct _MorphColor MorphColor;

typedef struct _SavedCinematic SavedCinematic;

typedef struct BSPTree BSPTree;

typedef struct _Terrain Terrain;

typedef struct LightGroup LightGroup;

typedef struct LightList LightList;

typedef struct PointLight PointLight;

typedef struct SpotLight SpotLight;

typedef struct LightInfo LightInfo;

typedef struct _VMOffset VMMoveOffset;

typedef struct _VMColorOffset VMColorOffset;

typedef struct _VMInterpolated VMInterpolated;

typedef struct _VMOffsetTable VMOffsetTable;

typedef struct _VMObject VMObject;

typedef struct _VGroup VGroup;

typedef struct _HotSpot HotSpot;

typedef struct _PlanMkr PlanMkr;

typedef struct _SFXMkr SFXMkr;

typedef struct TClassAttr TClassAttr;

typedef struct Level Level;

typedef struct _ColorType ColorType;

typedef struct _CameraCore_Type CameraCore;

typedef struct SpuVolume SpuVolume;

typedef struct SpuExtAttr SpuExtAttr;

typedef struct SpuStVoiceAttr SpuStVoiceAttr;

typedef struct AadSoundBankHdr AadSoundBankHdr;

typedef struct AadProgramAtr AadProgramAtr;

typedef struct AadToneAtr AadToneAtr;

typedef struct _AadDynSfxFileHdr AadDynSfxSnfFileHdr;

typedef struct AadDynSfxAttr AadDynSfxAttr;

typedef struct AadTempoCounter AadTempoCounter;

typedef struct AadSeqEvent AadSeqEvent;

typedef struct _AadSequenceSlot AadSequenceSlot;

typedef struct AadSfxCommand AadSfxCommand;

typedef struct AadSfxSlot AadSfxSlot;

typedef struct AadSynthVoice AadSynthVoice;

typedef struct AadDynamicLoadRequest AadDynamicLoadRequest;

typedef struct AadDynamicBankLoadInfo AadDynamicBankLoadInfo;

typedef struct AadDynamicSfxLoadInfo AadDynamicSfxLoadInfo;

typedef struct AadNewSramBlockDesc AadNewSramBlockDesc;

typedef struct AadLoadedSfxToneAttr AadLoadedSfxToneAttr;

typedef struct AadLoadedSfxWaveAttr AadLoadedSfxWaveAttr;

typedef struct AadMasterVolFader AadMasterVolFader;

typedef struct AadVolFader AadVolFader;

typedef struct gSoundData gSoundData;

typedef struct GameTracker GameTracker;

typedef struct Spline Spline;

typedef struct vecS vecS;

typedef struct vecL vecL;

typedef struct SplineRotKey SplineRotKey;

typedef struct RSpline RSpline;

typedef struct SplineKey SplineKey;

typedef struct SplineDef SplineDef;

typedef struct _HVertex HVertex;

typedef struct _MONAPI_Regenerator MONAPI_Regenerator;

typedef enum DEBUG_LINE_TYPE DEBUG_LINE_TYPE;

typedef struct __Event Message;

typedef struct __MessageQueue MessageQueue;

typedef struct __State State;

typedef unsigned char u_char;

typedef unsigned short u_short;

typedef unsigned int u_int;

typedef unsigned long u_long;

typedef unsigned short ushort;

typedef struct _physadr *physadr;

typedef long daddr_t;

typedef char *caddr_t;

typedef long *qaddr_t;

typedef unsigned long ino_t;

typedef long swblk_t;

typedef unsigned int size_t;

typedef long time_t;

typedef short dev_t;

typedef long off_t;

typedef unsigned short uid_t;

typedef unsigned short gid_t;

typedef unsigned long wchar_t;

typedef void (*CdlCB)();

typedef void *va_list;

typedef unsigned char uchar;

typedef unsigned char u_byte;

typedef unsigned char ubyte;

typedef unsigned long ulong;

typedef char int8;

typedef short int16;

typedef long int32;

typedef long int64;

typedef unsigned char uint8;

typedef unsigned short uint16;

typedef unsigned long uint32;

typedef unsigned long uint64;

typedef char BYTE;

typedef unsigned char UBYTE;

typedef unsigned long ULONG;

typedef unsigned short USHORT;

typedef unsigned long bool;

typedef long ListOrderFunc();

typedef unsigned long *OTag;

typedef unsigned char G2UInt8;

typedef unsigned short G2UInt16;

typedef unsigned long G2UInt32;

typedef char G2Int8;

typedef short G2Int16;

typedef long G2Int32;

typedef long G2fp4dot12;

typedef long G2fp8dot24;

typedef short G2TimerAtomicUnit;

typedef int G2AnimKeyframeNumber;

typedef int G2AnimKeylistID;

typedef int G2AnimSectionID;

typedef unsigned char G2AnimSegmentID;

typedef unsigned char G2AnimControllerType;

typedef unsigned short G2AnimChanMask;

typedef long (*G2AnimCallback)();

typedef unsigned long (*G2AnimControllerFn)();

typedef short G2AnimChanKeyData;

typedef short G2AnimChanFinalValue;

typedef enum _G2Bool_Enum (*G2InstanceRebuildCallback)();

typedef long lfixed;

typedef short sfixed;

typedef short MatEntry;

typedef short Fraction;

typedef long VectorCoord;

typedef short SVectorCoord;

typedef short NormalCoord;

typedef short TrigVal;

typedef short Angle;

typedef short Matrix[3][3];

typedef void InitFunc();

typedef void ProcessFunc();

typedef void CollideFunc();

typedef unsigned long QueryFunc();

typedef void MessageFunc();

typedef void RelocateTuneFunc();

typedef void (*SpuIRQCallbackProc)();

typedef void (*SpuTransferCallbackProc)();

typedef void (*SpuStCallbackProc)();

typedef unsigned short MidiParam;

typedef unsigned short AADRESULT;

typedef unsigned long AadChannelList;

typedef unsigned short AadFileHandle;

typedef void (*AadFadeCompleteCallbackProc)();

typedef void (*AadLockVoiceCallbackProc)();

typedef void (*AadController11CallbackProc)();

typedef void (*AadEndSequenceCallbackProc)();

typedef void (*AadLoadDynamicSoundBankReturnProc)();

typedef void (*AadLoadDynamicSfxReturnProc)();

typedef void (**AadMemoryMallocProc)();

typedef void (*AadMemoryFreeProc)();

typedef void (*AadNonBlockLoadReturnProc)();

typedef void (*AadNonBlockLoadProc)();

typedef void (*AadNonBlockBufferedLoadReturnProc)();

typedef void (*AadNonBlockBufferedLoadProc)();

typedef unsigned char AadNewSramBlockHandle;

typedef unsigned long AadSfxHandle;

typedef unsigned int AadSfxToneID;

typedef void (*EndSequenceCallbackProc)();

typedef void (*Controller11CallbackProc)();

typedef unsigned long *DrawNonAnimatedSegmentFunc();

typedef unsigned long *DrawAnimatedModelFunc();

typedef unsigned long *DrawDisplayPolytopeListFunc();

typedef unsigned long *AdditionalDrawFunc();

typedef void BG_DisplayFunc();

typedef void RelocateInstObFunc();

typedef void (*VoidProc)();

typedef void (*StateHandler)();

struct POLY_F4 // hashcode: 0xE2AC295D (dec: -492033699)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	short x1; // size=0, offset=12
	short y1; // size=0, offset=14
	short x2; // size=0, offset=16
	short y2; // size=0, offset=18
	short x3; // size=0, offset=20
	short y3; // size=0, offset=22
};

union DEBUG_117fake // Hashcode: 0x841D75EE (dec: -2078444050)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: debug.o, debug.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: debug.o, debug.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: debug.o, debug.o
};

union DEBUG_118fake // Hashcode: 0x47B0A530 (dec: 1202758960)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct EventPointers // hashcode: 0x3787E212 (dec: 931652114)
{
	long numPuzzles; // size=0, offset=0
	struct Event (*eventInstances[1]); // size=4, offset=4
};

struct Camera // hashcode: 0x0670C20F (dec: 108053007)
{
	struct _CameraCore_Type core; // size=224, offset=0
	long shake; // size=0, offset=224
	short shakeFrame; // size=0, offset=228
	short shakeScale; // size=0, offset=230
	long flags; // size=0, offset=232
	long lock; // size=0, offset=236
	short mode; // size=0, offset=240
	short state; // size=0, offset=242
	short posState; // size=0, offset=244
	short rotState; // size=0, offset=246
	short tiltState; // size=0, offset=248
	short distanceState; // size=0, offset=250
	short lagZ; // size=0, offset=252
	short tilt; // size=0, offset=254
	struct _Position focusPoint; // size=6, offset=256
	short focusDistance; // size=0, offset=262
	struct _Instance *focusInstance; // size=664, offset=264
	struct _Position oldFocusInstancePos; // size=6, offset=268
	struct _Position newFocusInstancePos; // size=6, offset=274
	struct _Rotation oldFocusInstanceRot; // size=8, offset=280
	struct _Rotation newFocusInstanceRot; // size=8, offset=288
	struct _SVector focusInstanceVelVec; // size=8, offset=296
	struct _Position focusLeadPivot; // size=6, offset=304
	struct _Position focusOffset; // size=6, offset=310
	struct _Rotation focusRotation; // size=8, offset=316
	short tiltVel; // size=0, offset=324
	short tiltAccl; // size=0, offset=326
	struct _SVector positionVel; // size=8, offset=328
	struct _SVector positionAccl; // size=8, offset=336
	struct _SVector focusPointVel; // size=8, offset=344
	struct _SVector focusPointAccl; // size=8, offset=352
	short focusDistanceVel; // size=0, offset=360
	short focusDistanceAccl; // size=0, offset=362
	struct _SVector focusRotVel; // size=8, offset=364
	struct _SVector focusRotAccl; // size=8, offset=372
	struct _SVector maxFocusVel; // size=8, offset=380
	struct _SVector rotationVel; // size=8, offset=388
	struct _SVector rotationAccl; // size=8, offset=396
	short maxVel; // size=0, offset=404
	short maxRot; // size=0, offset=406
	struct _Position targetPos; // size=6, offset=408
	short targetTilt; // size=0, offset=414
	struct _Rotation targetRotation; // size=8, offset=416
	short targetFocusDistance; // size=0, offset=424
	struct _Position targetFocusPoint; // size=6, offset=426
	short collisionTargetFocusDistance; // size=0, offset=432
	struct _Rotation targetFocusRotation; // size=8, offset=434
	short tfaceTilt; // size=0, offset=442
	struct _Rotation collisionTargetFocusRotation; // size=8, offset=444
	short smooth; // size=0, offset=452
	struct _CameraKey *cameraKey; // size=24, offset=456
	struct _Sphere focusSphere; // size=12, offset=460
	struct _Sphere smallBaseSphere; // size=12, offset=472
	struct _Sphere posSphere; // size=12, offset=484
	short lookTimer; // size=0, offset=496
	short lookSavedMode; // size=0, offset=498
	short presetIndex; // size=0, offset=500
	short presetFocusDistance[3]; // size=6, offset=502
	long minFocusDistance; // size=0, offset=508
	long maxFocusDistance; // size=0, offset=512
	long minTilt; // size=0, offset=516
	long maxTilt; // size=0, offset=520
	long pad[3]; // size=12, offset=524
	long minXYDist; // size=0, offset=536
	long maxXYDist; // size=0, offset=540
	long oppositeError; // size=0, offset=544
	long tempsplinePointAhead; // size=0, offset=548
	long noTeleport; // size=0, offset=552
	long focusDistanceList[3][3]; // size=36, offset=556
	long tiltList[3][3]; // size=36, offset=592
	long cineControl; // size=0, offset=628
	short stack; // size=0, offset=632
	short targetStack; // size=0, offset=634
	long savedMode[3]; // size=12, offset=636
	long savedTargetFocusDistance[3]; // size=12, offset=648
	struct _Rotation savedFocusRotation; // size=8, offset=660
	short savedFocusDistance; // size=0, offset=668
	short signalFocusDistance; // size=0, offset=670
	struct _SavedCinematic savedCinematic[3]; // size=336, offset=672
	struct _Rotation savedfocusRotation; // size=8, offset=1008
	struct _Position signalPos; // size=6, offset=1016
	short pad11; // size=0, offset=1022
	struct _Rotation signalRot; // size=8, offset=1024
	short forced_movement; // size=0, offset=1032
	short last_forced_movement; // size=0, offset=1034
	short rotDirection; // size=0, offset=1036
	unsigned long lastModTime; // size=0, offset=1040
	struct _Rotation lookRot; // size=8, offset=1044
	struct MultiSpline *Spline00; // size=0, offset=1052
	struct MultiSpline *Spline01; // size=0, offset=1056
	struct {
		struct {
			struct MultiSpline *posSpline; // size=0, offset=0
			struct MultiSpline *targetSpline; // size=0, offset=4
			struct _SVector lastSplinePos; // size=8, offset=8
			short splinePointAhead; // size=0, offset=16
			short cinema_done; // size=0, offset=18
			int splinecam_currkey; // size=0, offset=20
			int splinecam_helpkey; // size=0, offset=24
		} Cinematic; // size=28, offset=0, found in object files: debug.o, debug.o
		struct {
			struct _Position offset; // size=6, offset=0
			struct _Rotation rotation; // size=8, offset=6
			long focusDistance; // size=0, offset=16
		} Idle; // size=20, offset=28, found in object files: debug.o, debug.o
		struct {
			struct _TFace *tface; // size=12, offset=0
			struct _TFace *oldTFace; // size=12, offset=4
			struct _SVector oldTargetRot; // size=8, offset=8
			long timer; // size=0, offset=16
			struct _SVector oldFocusInstancePos; // size=8, offset=20
		} Behind; // size=28, offset=48, found in object files: debug.o, debug.o
		struct {
			long stopTimer; // size=0, offset=0
			long stopHit; // size=0, offset=4
			struct _TFace *tface; // size=12, offset=8
			struct _TFace *oldTFace; // size=12, offset=12
			long hit; // size=0, offset=16
		} Follow; // size=20, offset=76, found in object files: debug.o, debug.o
	} data; // size=96, offset=1060, found in object files: debug.o, debug.o
	long cuckooTimer; // size=0, offset=1156
	short teleportZRot; // size=0, offset=1160
	short extraZRot; // size=0, offset=1162
	short extraXRot; // size=0, offset=1164
	short leftTimer; // size=0, offset=1166
	short rightTimer; // size=0, offset=1168
	short collideRotControl; // size=0, offset=1170
	short collision_lastPush; // size=0, offset=1172
	short collision_timer; // size=0, offset=1174
	unsigned long prev_instance_mode; // size=0, offset=1176
	unsigned long instance_mode; // size=0, offset=1180
	long instance_xyvel; // size=0, offset=1184
	long instance_prev_xyvel; // size=0, offset=1188
	struct _Position real_focuspoint; // size=6, offset=1192
	short always_rotate_flag; // size=0, offset=1198
	short follow_flag; // size=0, offset=1200
	short actual_x_rot; // size=0, offset=1202
	short actual_vel_x; // size=0, offset=1204
	short actual_acc_x; // size=0, offset=1206
	short x_rot_change; // size=0, offset=1208
	short focuspoint_fallz; // size=0, offset=1210
	short lead_angle; // size=0, offset=1212
	short lead_vel; // size=0, offset=1214
	short lead_accl; // size=0, offset=1216
	short lead_timer; // size=0, offset=1218
};

struct DebugMenuLine // hashcode: 0xB294890C (dec: -1298888436)
{
	enum DEBUG_LINE_TYPE type; // size=4, offset=0
	long lower; // size=0, offset=4
	long upper; // size=0, offset=8
	char *text; // size=0, offset=12
	long *var_address; // size=0, offset=16
	long bit_mask; // size=0, offset=20
};

struct _ButtonTexture // hashcode: 0x36C27A0D (dec: 918714893)
{
	short tpage; // size=0, offset=0
	short clut; // size=0, offset=2
	short textureW; // size=0, offset=4
	short textureH; // size=0, offset=6
	struct _BlockVramEntry *vramBlock; // size=0, offset=8
	long xshift; // size=0, offset=12
};

struct _BlockVramEntry // hashcode: 0xD1D970C9 (dec: -774278967)
{
	struct _BlockVramEntry *next; // size=28, offset=0
	unsigned char type; // size=0, offset=4
	unsigned char flags; // size=0, offset=5
	short time; // size=0, offset=6
	long ID; // size=0, offset=8
	short x; // size=0, offset=12
	short y; // size=0, offset=14
	short w; // size=0, offset=16
	short h; // size=0, offset=18
	long area; // size=0, offset=20
	union {
		struct _StreamUnit *streamUnit; // size=64, offset=0
		struct _ObjectTracker *streamObject; // size=36, offset=0
		struct _ButtonTexture *button; // size=16, offset=0
	} udata; // size=4, offset=24, found in object files: debug.o, debug.o
};

struct FontChar // hashcode: 0x2FA2E9BF (dec: 799205823)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	char c; // size=0, offset=4
	char color; // size=0, offset=5
};

struct _BigFileEntry // hashcode: 0x6A105923 (dec: 1779456291)
{
	long fileHash; // size=0, offset=0
	long fileLen; // size=0, offset=4
	long filePos; // size=0, offset=8
	long checkSumFull; // size=0, offset=12
};

struct _BigFileDirEntry // hashcode: 0x292FD76D (dec: 691001197)
{
	short streamUnitID; // size=0, offset=0
	short numFiles; // size=0, offset=2
	long subDirOffset; // size=0, offset=4
};

struct _BigFileDir // hashcode: 0xD1645829 (dec: -781952983)
{
	long numFiles; // size=0, offset=0
	struct _BigFileEntry fileList[0]; // size=0, offset=4
};

struct _BigFile // hashcode: 0x88AA68E7 (dec: -2002097945)
{
	long bigfileBaseOffset; // size=0, offset=0
	struct _BigFileDir *rootDir; // size=4, offset=4
	struct _BigFileDir *currentDir; // size=4, offset=8
	struct _BigFileDir *cachedDir; // size=4, offset=12
	long currentDirID; // size=0, offset=16
	long cachedDirID; // size=0, offset=20
	long searchDirID; // size=0, offset=24
	long numSubDirs; // size=0, offset=28
	struct _BigFileDirEntry *subDirList; // size=8, offset=32
};

struct _NonBlockLoadEntry // hashcode: 0x133F5082 (dec: 322916482)
{
	long fileHash; // size=0, offset=0
	long dirHash; // size=0, offset=4
	long filePos; // size=0, offset=8
	long *loadAddr; // size=0, offset=12
	long loadSize; // size=0, offset=16
	long checksum; // size=0, offset=20
	long checksumType; // size=0, offset=24
	long memType; // size=0, offset=28
	long posInFile; // size=0, offset=32
	void *retFunc; // size=0, offset=36
	void *retData; // size=0, offset=40
	void *retData2; // size=0, offset=44
	void **retPointer; // size=0, offset=48
	char fileName[64]; // size=64, offset=52
};

struct _ReadQueueEntry // hashcode: 0xEB400E05 (dec: -348123643)
{
	long readStartPos; // size=0, offset=0
	long readSize; // size=0, offset=4
	long readCurSize; // size=0, offset=8
	void *readStartDest; // size=0, offset=12
	void *readCurDest; // size=0, offset=16
	long readStatus; // size=0, offset=20
	long checksum; // size=0, offset=24
	long checksumType; // size=0, offset=28
	void *retFunc; // size=0, offset=32
	void *retData; // size=0, offset=36
	void *retData2; // size=0, offset=40
};

struct _FX_MATRIX // hashcode: 0x2EB85885 (dec: 783833221)
{
	struct NodeType node; // size=8, offset=0
	long flags; // size=0, offset=8
	struct MATRIX lwTransform; // size=32, offset=12
};

struct _FX_PRIM // hashcode: 0x16BF818E (dec: 381649294)
{
	struct NodeType node; // size=8, offset=0
	struct TextureMT3 *texture; // size=16, offset=8
	long flags; // size=0, offset=12
	long timeToLive; // size=0, offset=16
	void *process; // size=0, offset=20
	struct _FX_MATRIX *matrix; // size=44, offset=24
	long color; // size=0, offset=28
	long startColor; // size=0, offset=32
	long endColor; // size=0, offset=36
	short colorFadeValue; // size=0, offset=40
	short colorFadeStep; // size=0, offset=42
	struct _Position position; // size=6, offset=44
	short fadeStep; // size=0, offset=50
	short fadeValue[4]; // size=8, offset=52
	struct _Position v0; // size=6, offset=60
	short work0; // size=0, offset=66
	struct _Position v1; // size=6, offset=68
	short work1; // size=0, offset=74
	struct _Position v2; // size=6, offset=76
	short work2; // size=0, offset=82
	struct _Position v3; // size=6, offset=84
	short work3; // size=0, offset=90
	union {
		struct {
			struct _Instance *parent; // size=664, offset=0
			long segment; // size=0, offset=4
		} flame; // size=8, offset=0, found in object files: debug.o, debug.o
		struct {
			short xVel; // size=0, offset=0
			short yVel; // size=0, offset=2
			short zVel; // size=0, offset=4
			short xAccl; // size=0, offset=6
			short yAccl; // size=0, offset=8
			short zAccl; // size=0, offset=10
		} phys; // size=12, offset=0, found in object files: debug.o, debug.o
	} duo; // size=12, offset=92, found in object files: debug.o, debug.o
	struct {
		struct TextureMT3 *texMem; // size=16, offset=0
		struct AniTex *aniTextures; // size=16, offset=4
		short curFrame; // size=0, offset=8
	} ani; // size=12, offset=104, found in object files: debug.o, debug.o
};

struct BASIC_LINE_G2 // hashcode: 0x684545B2 (dec: 1749370290)
{
	unsigned char r0; // size=0, offset=0
	unsigned char g0; // size=0, offset=1
	unsigned char b0; // size=0, offset=2
	unsigned char code; // size=0, offset=3
	short x0; // size=0, offset=4
	short y0; // size=0, offset=6
	unsigned char r1; // size=0, offset=8
	unsigned char g1; // size=0, offset=9
	unsigned char b1; // size=0, offset=10
	unsigned char p1; // size=0, offset=11
	short x1; // size=0, offset=12
	short y1; // size=0, offset=14
};

struct _BASIC_G4 // hashcode: 0xC15AD9EF (dec: -1051010577)
{
	unsigned char r0; // size=0, offset=0
	unsigned char g0; // size=0, offset=1
	unsigned char b0; // size=0, offset=2
	unsigned char code; // size=0, offset=3
	short x0; // size=0, offset=4
	short y0; // size=0, offset=6
	unsigned char r1; // size=0, offset=8
	unsigned char g1; // size=0, offset=9
	unsigned char b1; // size=0, offset=10
	unsigned char pad1; // size=0, offset=11
	short x1; // size=0, offset=12
	short y1; // size=0, offset=14
	unsigned char r2; // size=0, offset=16
	unsigned char g2; // size=0, offset=17
	unsigned char b2; // size=0, offset=18
	unsigned char pad2; // size=0, offset=19
	short x2; // size=0, offset=20
	short y2; // size=0, offset=22
	unsigned char r3; // size=0, offset=24
	unsigned char g3; // size=0, offset=25
	unsigned char b3; // size=0, offset=26
	unsigned char pad3; // size=0, offset=27
	short x3; // size=0, offset=28
	short y3; // size=0, offset=30
};

struct _BASIC_F4 // hashcode: 0x2871008E (dec: 678494350)
{
	unsigned char r0; // size=0, offset=0
	unsigned char g0; // size=0, offset=1
	unsigned char b0; // size=0, offset=2
	unsigned char code; // size=0, offset=3
	short x0; // size=0, offset=4
	short y0; // size=0, offset=6
	short x1; // size=0, offset=8
	short y1; // size=0, offset=10
	short x2; // size=0, offset=12
	short y2; // size=0, offset=14
	short x3; // size=0, offset=16
	short y3; // size=0, offset=18
};

struct __BubbleParams // hashcode: 0xE483C494 (dec: -461126508)
{
	short DisperseFrames; // size=0, offset=0
	short KillScale; // size=0, offset=2
	short MinSplashSize; // size=0, offset=4
	short MaxSpeed; // size=0, offset=6
	short MaxSpeedRange; // size=0, offset=8
	short ScaleRate; // size=0, offset=10
	short ScaleRateRange; // size=0, offset=12
	short StartScale; // size=0, offset=14
	short StartScaleRange; // size=0, offset=16
	short UniqueBubbles; // size=0, offset=18
};

struct _GenericParticleParams // hashcode: 0x7A6370AD (dec: 2053337261)
{
	short model; // size=0, offset=0
	short texture; // size=0, offset=2
	short size; // size=0, offset=4
	unsigned char StartOnInit; // size=0, offset=6
	unsigned char type; // size=0, offset=7
	short birthRadius; // size=0, offset=8
	char startSegment; // size=0, offset=10
	char endSegment; // size=0, offset=11
	struct _Position direction; // size=6, offset=12
	unsigned char spectral_colorize; // size=0, offset=18
	unsigned char absolute_direction; // size=0, offset=19
	struct _Position acceleration; // size=6, offset=20
	short useInstanceModel; // size=0, offset=26
	long startColor; // size=0, offset=28
	long endColor; // size=0, offset=32
	short lifeTime; // size=0, offset=36
	short primLifeTime; // size=0, offset=38
	short startFadeValue; // size=0, offset=40
	short fadeStep; // size=0, offset=42
	char numberBirthParticles; // size=0, offset=44
	char z_undulation_mode; // size=0, offset=45
	short scaleSpeed; // size=0, offset=46
	struct _Position offset; // size=6, offset=48
	short startScale; // size=0, offset=54
};

struct _GenericRibbonParams // hashcode: 0xD243E3C9 (dec: -767302711)
{
	short id; // size=0, offset=0
	short StartOnInit; // size=0, offset=2
	short startSegment; // size=0, offset=4
	short endSegment; // size=0, offset=6
	short type; // size=0, offset=8
	short ribbonLifeTime; // size=0, offset=10
	short faceLifeTime; // size=0, offset=12
	short startFadeValue; // size=0, offset=14
	long startColor; // size=0, offset=16
	long endColor; // size=0, offset=20
};

struct _GenericGlowParams // hashcode: 0xF67692B8 (dec: -160001352)
{
	short id; // size=0, offset=0
	short StartOnInit; // size=0, offset=2
	unsigned char segment; // size=0, offset=4
	unsigned char segmentEnd; // size=0, offset=5
	short numSegments; // size=0, offset=6
	short color_num; // size=0, offset=8
	short numColors; // size=0, offset=10
	long atuColorCycleRate; // size=0, offset=12
	short width; // size=0, offset=16
	short height; // size=0, offset=18
	long lifetime; // size=0, offset=20
	short fadein_time; // size=0, offset=24
	short fadeout_time; // size=0, offset=26
};

struct _GenericLightningParams // hashcode: 0x226C68CF (dec: 577530063)
{
	short type; // size=0, offset=0
	short lifeTime; // size=0, offset=2
	short deg; // size=0, offset=4
	short deg_inc; // size=0, offset=6
	struct _Position start_offset; // size=6, offset=8
	short startSeg; // size=0, offset=14
	struct _Position end_offset; // size=6, offset=16
	short endSeg; // size=0, offset=22
	short matrixSeg; // size=0, offset=24
	short width; // size=0, offset=26
	short small_width; // size=0, offset=28
	short segs; // size=0, offset=30
	short sine_size; // size=0, offset=32
	short variation; // size=0, offset=34
	long color; // size=0, offset=36
	long glow_color; // size=0, offset=40
};

struct _GenericBlastringParams // hashcode: 0xAB3B2462 (dec: -1422187422)
{
	short type; // size=0, offset=0
	short lifeTime; // size=0, offset=2
	short matrixSeg; // size=0, offset=4
	short segment; // size=0, offset=6
	struct _SVector offset; // size=8, offset=8
	short sortInWorld; // size=0, offset=16
	short radius; // size=0, offset=18
	short size1; // size=0, offset=20
	short size2; // size=0, offset=22
	short endRadius; // size=0, offset=24
	short colorchange_radius; // size=0, offset=26
	int vel; // size=0, offset=28
	int accl; // size=0, offset=32
	short height1; // size=0, offset=36
	short height2; // size=0, offset=38
	short height3; // size=0, offset=40
	short predator_offset; // size=0, offset=42
	long startColor; // size=0, offset=44
	long endColor; // size=0, offset=48
};

struct _GenericFlashParams // hashcode: 0x06D8DB60 (dec: 114875232)
{
	short type; // size=0, offset=0
	short timeToColor; // size=0, offset=2
	long color; // size=0, offset=4
	short timeAtColor; // size=0, offset=8
	short timeFromColor; // size=0, offset=10
};

struct XAFileInfo // hashcode: 0xD20CF9DB (dec: -770901541)
{
	int startPos; // size=0, offset=0
};

struct CdCommand // hashcode: 0x5AFC9D1E (dec: 1526504734)
{
	unsigned short flags; // size=0, offset=0
	unsigned char unused; // size=0, offset=2
	unsigned char cdCommand; // size=0, offset=3
	unsigned char cdCmdParam[4]; // size=4, offset=4
};

struct VoiceCommand // hashcode: 0xBF82A118 (dec: -1081958120)
{
	unsigned char voiceCmd; // size=0, offset=0
	unsigned char nextVoiceStatus; // size=0, offset=1
	unsigned short voiceCmdParam; // size=0, offset=2
};

union DEBUG_232fake // Hashcode: 0xB8D12125 (dec: -1194254043)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _StreamUnit // hashcode: 0x1D5D5061 (dec: 492654689)
{
	long StreamUnitID; // size=0, offset=0
	short used; // size=0, offset=4
	short flags; // size=0, offset=6
	struct Level *level; // size=392, offset=8
	char baseAreaName[16]; // size=16, offset=12
	short toSignal; // size=0, offset=28
	short fromSignal; // size=0, offset=30
	long FrameCount; // size=0, offset=32
	short eventVariables[6]; // size=12, offset=36
	long FogColor; // size=0, offset=48
	short UnitFogFar; // size=0, offset=52
	short UnitFogNear; // size=0, offset=54
	short TargetFogFar; // size=0, offset=56
	short TargetFogNear; // size=0, offset=58
	short sfxFileHandle; // size=0, offset=60
	short pad; // size=0, offset=62
};

struct _LoadQueueEntry // hashcode: 0xFEE70962 (dec: -18413214)
{
	struct _LoadQueueEntry *next; // size=128, offset=0
	short status; // size=0, offset=4
	char relocateBinary; // size=0, offset=6
	char mempackUsed; // size=0, offset=7
	struct _NonBlockLoadEntry loadEntry; // size=116, offset=8
	long endLoadTime; // size=0, offset=124
};

struct _SavedIntro // hashcode: 0x743E92B6 (dec: 1950257846)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
	char name[12]; // size=12, offset=4
	short introUniqueID; // size=0, offset=16
	short streamUnitID; // size=0, offset=18
	short birthUnitID; // size=0, offset=20
	unsigned char lightGroup; // size=0, offset=22
	unsigned char specturalLightGroup; // size=0, offset=23
	struct _Rotation rotation; // size=8, offset=24
	struct _Position position; // size=6, offset=32
	long flags; // size=0, offset=40
	long flags2; // size=0, offset=44
	short extraDataSize; // size=0, offset=48
	unsigned short attachedUniqueID; // size=0, offset=50
	short splineFlags; // size=0, offset=52
	short splineKeyFrame; // size=0, offset=54
	short splineClipBeg; // size=0, offset=56
	short splineClipEnd; // size=0, offset=58
};

struct SavedEvent // hashcode: 0x4773A235 (dec: 1198760501)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
	long areaID; // size=0, offset=4
	short eventNumber; // size=0, offset=8
	short eventVariables[5]; // size=10, offset=10
};

struct SavedBspTree // hashcode: 0x329673FB (dec: 848720891)
{
	struct _Position localOffset; // size=6, offset=0
	short flags; // size=0, offset=6
};

struct EventBasicObject // hashcode: 0x4FDD9FC4 (dec: 1339924420)
{
	short id; // size=0, offset=0
};

union DEBUG_254fake // Hashcode: 0x60BE10A9 (dec: 1623068841)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

struct EventWildCardObject // hashcode: 0x74046471 (dec: 1946444913)
{
	short id; // size=0, offset=0
	short spad; // size=0, offset=2
	long unitID; // size=0, offset=4
	char *objectName; // size=0, offset=8
};

struct Event // hashcode: 0x4BE0FA04 (dec: 1273035268)
{
	short eventNumber; // size=0, offset=0
	short numInstances; // size=0, offset=2
	unsigned char numActions; // size=0, offset=4
	unsigned char processingPuppetShow; // size=0, offset=5
	short eventVariables[5]; // size=10, offset=6
	struct EventBasicObject **instanceList; // size=2, offset=16
	struct ScriptPCode **conditionalList; // size=8, offset=20
	struct ScriptPCode **actionList; // size=8, offset=24
};

struct ScriptPCode // hashcode: 0x76385939 (dec: 1983404345)
{
	unsigned short sizeOfPcodeStream; // size=0, offset=0
	unsigned short conditionBits; // size=0, offset=2
	short *data; // size=0, offset=4
};

struct InstanceSpline // hashcode: 0x94835ECF (dec: -1803329841)
{
	struct _Instance *instance; // size=664, offset=0
	struct MultiSpline *spline; // size=80, offset=4
	long attribute; // size=0, offset=8
	long isParent; // size=0, offset=12
	long isClass; // size=0, offset=16
	long splineFlags; // size=0, offset=20
};

struct Vector3d // hashcode: 0xCF00F1CB (dec: -822021685)
{
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
	short vz; // size=0, offset=4
	short pad1; // size=0, offset=6
	short errorx; // size=0, offset=8
	short errory; // size=0, offset=10
	short errorz; // size=0, offset=12
	short pad2; // size=0, offset=14
};

struct Rotation3d // hashcode: 0xD1DEA474 (dec: -773938060)
{
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
	short vz; // size=0, offset=4
	short pad1; // size=0, offset=6
	short errorx; // size=0, offset=8
	short errory; // size=0, offset=10
	short errorz; // size=0, offset=12
	short pad2; // size=0, offset=14
	long attribute; // size=0, offset=16
};

struct InstanceObject // hashcode: 0xFFFDD125 (dec: -143067)
{
	struct _Instance *instance; // size=664, offset=0
	long attribute; // size=0, offset=4
};

struct EventObject // hashcode: 0xA118721F (dec: -1592233441)
{
	struct Event *event; // size=28, offset=0
	long attribute; // size=0, offset=4
};

struct SavedEventObject // hashcode: 0x9ABD1A18 (dec: -1698883048)
{
	struct SavedEvent *savedEvent; // size=20, offset=0
	long attribute; // size=0, offset=4
	long areaID; // size=0, offset=8
	long eventNumber; // size=0, offset=12
};

struct GameObject // hashcode: 0x8102C17E (dec: -2130525826)
{
	long attribute; // size=0, offset=0
};

struct SignalObject // hashcode: 0x7CFF5F95 (dec: 2097110933)
{
	struct _MultiSignal *msignal; // size=904, offset=0
	long attribute; // size=0, offset=4
};

struct IntroObject // hashcode: 0x17A7AB97 (dec: 396864407)
{
	struct Intro *intro; // size=76, offset=0
	long attribute; // size=0, offset=4
};

struct InstanceAnimate // hashcode: 0xD71AE6DE (dec: -686102818)
{
	struct _Instance *instance; // size=664, offset=0
	long attribute; // size=0, offset=4
};

struct InstanceAnimateTexture // hashcode: 0x2EE83E97 (dec: 786972311)
{
	struct _Instance *instance; // size=664, offset=0
	struct AniTex *aniTextures; // size=16, offset=4
	long attribute; // size=0, offset=8
};

struct ListObject // hashcode: 0x97253D02 (dec: -1759167230)
{
	struct EventWildCardObject *eventInstance; // size=12, offset=0
	long attribute[5]; // size=20, offset=4
	long numberOfAttributes; // size=0, offset=24
	long lineID; // size=0, offset=28
};

struct SubListObject // hashcode: 0x91F2E4A5 (dec: -1846352731)
{
	struct _Instance **instanceList; // size=664, offset=0
	long numberOfInstances; // size=0, offset=4
	long numberOfAttributes; // size=0, offset=8
	long attribute[5]; // size=20, offset=12
};

struct TGroupObject // hashcode: 0x345F62D1 (dec: 878666449)
{
	struct BSPTree *bspTree; // size=36, offset=0
	struct _StreamUnit *streamUnit; // size=64, offset=4
	long attribute; // size=0, offset=8
	short arg[2]; // size=4, offset=12
};

struct ConstrictInfo // hashcode: 0x3D981F77 (dec: 1033379703)
{
	struct _Instance *instance; // size=664, offset=0
	long attribute; // size=0, offset=4
};

struct CameraObject // hashcode: 0x64AF783A (dec: 1689221178)
{
	struct Camera *camera; // size=1220, offset=0
	long frames; // size=0, offset=4
	long attribute; // size=0, offset=8
};

struct EventVmObject // hashcode: 0x01933B22 (dec: 26426146)
{
	struct _VMObject *vmObjectPtr; // size=60, offset=0
	struct Level *level; // size=392, offset=4
	long attribute; // size=0, offset=8
};

struct AreaObject // hashcode: 0xE8811A72 (dec: -394192270)
{
	struct _StreamUnit *streamUnit; // size=64, offset=0
	long attribute; // size=0, offset=4
	long unitID; // size=0, offset=8
};

struct SoundObject // hashcode: 0xF99EA31D (dec: -107044067)
{
	short flags; // size=0, offset=0
	short attribute; // size=0, offset=2
	long soundNumber; // size=0, offset=4
	long value; // size=0, offset=8
	long duration; // size=0, offset=12
	union {
		struct _Instance *instance; // size=664, offset=0
		struct _SFXMkr *sfxMarker; // size=36, offset=0
	} data; // size=4, offset=16, found in object files: debug.o, debug.o
};

struct StackType // hashcode: 0x2F5F50E2 (dec: 794775778)
{
	long id; // size=0, offset=0
	union {
		struct {
			long instanceNumber; // size=0, offset=0
			long attribute; // size=0, offset=4
		} Object; // size=8, offset=0, found in object files: debug.o, debug.o
		struct {
			struct _SavedIntro *intro; // size=60, offset=0
			long attribute; // size=0, offset=4
		} SavedIntroObject; // size=8, offset=0, found in object files: debug.o, debug.o
		struct InstanceSpline instanceSpline; // size=24, offset=0
		struct {
			long currentNumber; // size=0, offset=0
			long error; // size=0, offset=4
			short flags; // size=0, offset=8
		} Number; // size=12, offset=0, found in object files: debug.o, debug.o
		struct {
			short vx; // size=0, offset=0
			short vy; // size=0, offset=2
		} Vector2d; // size=4, offset=0, found in object files: debug.o, debug.o
		struct {
			short *pointer; // size=0, offset=0
		} ShortPointer; // size=4, offset=0, found in object files: debug.o, debug.o
		struct {
			long *pointer; // size=0, offset=0
		} LongPointer; // size=4, offset=0, found in object files: debug.o, debug.o
		struct AreaObject areaObject; // size=12, offset=0
		struct InstanceObject instanceObject; // size=8, offset=0
		struct Vector3d vector3d; // size=16, offset=0
		struct Rotation3d rotation3d; // size=20, offset=0
		struct SignalObject signalObject; // size=8, offset=0
		struct EventObject eventObject; // size=8, offset=0
		struct GameObject gameObject; // size=4, offset=0
		struct ListObject listObject; // size=32, offset=0
		struct IntroObject introObject; // size=8, offset=0
		struct InstanceAnimate instanceAnimate; // size=8, offset=0
		struct InstanceAnimateTexture instanceAniTexture; // size=12, offset=0
		struct SavedEventObject savedEventObject; // size=16, offset=0
		struct SubListObject subListObject; // size=32, offset=0
		struct TGroupObject terrainGroup; // size=16, offset=0
		struct ConstrictInfo constrictInfo; // size=8, offset=0
		struct CameraObject cameraObject; // size=12, offset=0
		struct EventVmObject vmObject; // size=12, offset=0
		struct SoundObject soundObject; // size=20, offset=0
	} data; // size=32, offset=4, found in object files: debug.o, debug.o
};

struct __ReaverSaveDat // hashcode: 0x29690AA7 (dec: 694749863)
{
	unsigned long pad; // size=0, offset=0
};

enum option_ctrl_t // Hashcode: 0x7CF7344B (dec: 2096575563)
{
	option_ctrl_bogus = 0,
	option_ctrl_none = 1,
	option_ctrl_select = 2,
	option_ctrl_left = 3,
	option_ctrl_right = 4,
	option_ctrl_num_states = 5,
};

struct debug_dispatch_t // hashcode: 0xD1295757 (dec: -785819817)
{
	enum DEBUG_LINE_TYPE type; // size=4, offset=0
	void (*fn)(); // size=0, offset=4
};

struct debug_format_t // hashcode: 0xA92B8A65 (dec: -1456764315)
{
	int xpos; // size=0, offset=0
	int ypos; // size=0, offset=4
	int is_centered; // size=0, offset=8
};

typedef struct POLY_F4 POLY_F4;

typedef struct Camera Camera;

typedef struct DebugMenuLine DebugMenuLine;

typedef struct _ButtonTexture ButtonTexture;

typedef struct FontChar FontChar;

typedef struct _BigFileEntry BigFileEntry;

typedef struct _BigFileDirEntry BigFileDirEntry;

typedef struct _BigFileDir BigFileDir;

typedef struct _BigFile BigFile;

typedef struct _NonBlockLoadEntry NonBlockLoadEntry;

typedef struct _ReadQueueEntry ReadQueueEntry;

typedef struct _FX_MATRIX FX_MATRIX;

typedef struct _FX_PRIM FX_PRIM;

typedef struct BASIC_LINE_G2 BASIC_LINE_G2;

typedef struct _BASIC_G4 BASIC_G4;

typedef struct _BASIC_F4 BASIC_F4;

typedef struct __BubbleParams BubbleParams;

typedef struct _GenericParticleParams GenericParticleParams;

typedef struct _GenericRibbonParams GenericRibbonParams;

typedef struct _GenericGlowParams GenericGlowParams;

typedef struct _GenericLightningParams GenericLightningParams;

typedef struct _GenericBlastringParams GenericBlastringParams;

typedef struct _GenericFlashParams GenericFlashParams;

typedef struct XAFileInfo XAFileInfo;

typedef struct CdCommand CdCommand;

typedef struct VoiceCommand VoiceCommand;

typedef struct _StreamUnit StreamUnit;

typedef struct _LoadQueueEntry LoadQueueEntry;

typedef struct _BlockVramEntry BlockVramEntry;

typedef struct _SavedIntro SavedIntro;

typedef struct SavedEvent SavedEvent;

typedef struct SavedBspTree SavedBspTree;

typedef struct EventBasicObject EventBasicObject;

typedef struct EventWildCardObject EventWildCardObject;

typedef struct ScriptPCode ScriptPCode;

typedef struct Event Event;

typedef struct EventPointers EventPointers;

typedef struct InstanceSpline InstanceSpline;

typedef struct Vector3d Vector3d;

typedef struct Rotation3d Rotation3d;

typedef struct InstanceObject InstanceObject;

typedef struct EventObject EventObject;

typedef struct SavedEventObject SavedEventObject;

typedef struct GameObject GameObject;

typedef struct SignalObject SignalObject;

typedef struct IntroObject IntroObject;

typedef struct InstanceAnimate InstanceAnimate;

typedef struct InstanceAnimateTexture InstanceAnimateTexture;

typedef struct ListObject ListObject;

typedef struct SubListObject SubListObject;

typedef struct TGroupObject TGroupObject;

typedef struct ConstrictInfo ConstrictInfo;

typedef struct CameraObject CameraObject;

typedef struct EventVmObject EventVmObject;

typedef struct AreaObject AreaObject;

typedef struct SoundObject SoundObject;

typedef struct StackType StackType;

typedef struct __ReaverSaveDat ReaverSaveData;

typedef enum option_ctrl_t option_ctrl_t;

typedef struct debug_dispatch_t debug_dispatch_t;

typedef struct debug_format_t debug_format_t;

typedef void FX_PRIM_MODIFY_PROCESS();

typedef void FX_PROCESS();

typedef void FX_PARTICLE_PROCESS();

typedef void FX_GENERAL_PROCESS();

typedef void FX_SETUP();

typedef long TFract;

typedef void (*LoadReturnProc)();

typedef void (*BufferedLoadReturnProc)();

typedef void option_fn_t();

typedef int menu_fn_t();

typedef void debug_dispatch_fn_t();

struct POLY_GT3 // hashcode: 0x3999F1FF (dec: 966390271)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	unsigned short clut; // size=0, offset=14
	unsigned char r1; // size=0, offset=16
	unsigned char g1; // size=0, offset=17
	unsigned char b1; // size=0, offset=18
	unsigned char p1; // size=0, offset=19
	short x1; // size=0, offset=20
	short y1; // size=0, offset=22
	unsigned char u1; // size=0, offset=24
	unsigned char v1; // size=0, offset=25
	unsigned short tpage; // size=0, offset=26
	unsigned char r2; // size=0, offset=28
	unsigned char g2; // size=0, offset=29
	unsigned char b2; // size=0, offset=30
	unsigned char p2; // size=0, offset=31
	short x2; // size=0, offset=32
	short y2; // size=0, offset=34
	unsigned char u2; // size=0, offset=36
	unsigned char v2; // size=0, offset=37
	unsigned short pad2; // size=0, offset=38
};

struct POLY_GT4 // hashcode: 0xB2900D85 (dec: -1299182203)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	unsigned short clut; // size=0, offset=14
	unsigned char r1; // size=0, offset=16
	unsigned char g1; // size=0, offset=17
	unsigned char b1; // size=0, offset=18
	unsigned char p1; // size=0, offset=19
	short x1; // size=0, offset=20
	short y1; // size=0, offset=22
	unsigned char u1; // size=0, offset=24
	unsigned char v1; // size=0, offset=25
	unsigned short tpage; // size=0, offset=26
	unsigned char r2; // size=0, offset=28
	unsigned char g2; // size=0, offset=29
	unsigned char b2; // size=0, offset=30
	unsigned char p2; // size=0, offset=31
	short x2; // size=0, offset=32
	short y2; // size=0, offset=34
	unsigned char u2; // size=0, offset=36
	unsigned char v2; // size=0, offset=37
	unsigned short pad2; // size=0, offset=38
	unsigned char r3; // size=0, offset=40
	unsigned char g3; // size=0, offset=41
	unsigned char b3; // size=0, offset=42
	unsigned char p3; // size=0, offset=43
	short x3; // size=0, offset=44
	short y3; // size=0, offset=46
	unsigned char u3; // size=0, offset=48
	unsigned char v3; // size=0, offset=49
	unsigned short pad3; // size=0, offset=50
};

union DRAW_71fake // Hashcode: 0x84D5D42F (dec: -2066361297)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: draw.o, draw.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: draw.o, draw.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: draw.o, draw.o
};

struct _Vector // hashcode: 0xB0A1B5AB (dec: -1331579477)
{
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

union DRAW_72fake // Hashcode: 0x0B7EC0ED (dec: 192856301)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _PFace // hashcode: 0xE00ABD34 (dec: -536167116)
{
	unsigned long *tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	short clut; // size=0, offset=14
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	unsigned char u1; // size=0, offset=20
	unsigned char v1; // size=0, offset=21
	unsigned short tpage; // size=0, offset=22
	short x2; // size=0, offset=24
	short y2; // size=0, offset=26
	unsigned char u2; // size=0, offset=28
	unsigned char v2; // size=0, offset=29
	short pad1; // size=0, offset=30
	long pad2; // size=0, offset=32
	long pad3; // size=0, offset=36
};

struct _PolytopeList // hashcode: 0x0E6C33C5 (dec: 241972165)
{
	long numPolytopes; // size=0, offset=0
	void (*polytope[1024]); // size=4096, offset=4
};

struct DRAW_109fake // hashcode: 0xC960285E (dec: -916445090)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: draw.o, draw.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: draw.o, draw.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: draw.o, draw.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: draw.o, draw.o
};

struct UVTYPE // hashcode: 0x9F5B71F3 (dec: -1621397005)
{
	unsigned char u; // size=0, offset=0
	unsigned char v; // size=0, offset=1
	short pad; // size=0, offset=2
};

struct POLY_G3_SEMITRANS // hashcode: 0xA2D25D65 (dec: -1563271835)
{
	unsigned long tag; // size=0, offset=0
	unsigned long dr_tpage; // size=0, offset=4
	unsigned char r0; // size=0, offset=8
	unsigned char g0; // size=0, offset=9
	unsigned char b0; // size=0, offset=10
	unsigned char code; // size=0, offset=11
	short x0; // size=0, offset=12
	short y0; // size=0, offset=14
	unsigned char r1; // size=0, offset=16
	unsigned char g1; // size=0, offset=17
	unsigned char b1; // size=0, offset=18
	unsigned char pad1; // size=0, offset=19
	short x1; // size=0, offset=20
	short y1; // size=0, offset=22
	unsigned char r2; // size=0, offset=24
	unsigned char g2; // size=0, offset=25
	unsigned char b2; // size=0, offset=26
	unsigned char pad2; // size=0, offset=27
	short x2; // size=0, offset=28
	short y2; // size=0, offset=30
};

struct _POLY_NG4 // hashcode: 0x3F211518 (dec: 1059132696)
{
	unsigned long tag; // size=0, offset=0
	unsigned long drawTPage1; // size=0, offset=4
	struct _BASIC_G4 p1; // size=32, offset=8
};

struct _GT3ZVertexD3D_Type // hashcode: 0x1BBE2E68 (dec: 465448552)
{
	float x; // size=0, offset=0
	float y; // size=0, offset=4
	float z; // size=0, offset=8
	float rhw; // size=0, offset=12
	unsigned int rgba; // size=0, offset=16
	float u; // size=0, offset=20
	float v; // size=0, offset=24
};

struct SP_SUBDIV_STRUCT // hashcode: 0x4D2189BB (dec: 1294043579)
{
	struct _SVector vertex0; // size=8, offset=0
	struct _SVector vertex1; // size=8, offset=8
	struct _SVector vertex2; // size=8, offset=16
	struct SVECTOR face_v0; // size=8, offset=24
	struct SVECTOR face_v1; // size=8, offset=32
	struct SVECTOR face_v2; // size=8, offset=40
	struct SVECTOR face_v01; // size=8, offset=48
	struct SVECTOR face_v12; // size=8, offset=56
	struct SVECTOR face_v20; // size=8, offset=64
	struct UVTYPE face_uv0; // size=4, offset=72
	struct UVTYPE face_uv1; // size=4, offset=76
	struct UVTYPE face_uv2; // size=4, offset=80
	struct UVTYPE face_uv01; // size=4, offset=84
	struct UVTYPE face_uv12; // size=4, offset=88
	struct UVTYPE face_uv20; // size=4, offset=92
	struct _ColorType color0; // size=4, offset=96
	struct _ColorType color1; // size=4, offset=100
	struct _ColorType color2; // size=4, offset=104
	struct _ColorType color01; // size=4, offset=108
	struct _ColorType color12; // size=4, offset=112
	struct _ColorType color20; // size=4, offset=116
	struct _Vector out[4]; // size=48, offset=120
	long color[4]; // size=16, offset=168
	long texinfo[3]; // size=12, offset=184
	struct DVECTOR sxy[4]; // size=16, offset=196
};

typedef struct POLY_GT3 POLY_GT3;

typedef struct POLY_GT4 POLY_GT4;

typedef struct _Vector Vector;

typedef struct _PFace PFace;

typedef struct _PolytopeList PolytopeList;

typedef struct UVTYPE UVTYPE;

typedef struct POLY_G3_SEMITRANS POLY_G3_SEMITRANS;

typedef struct _POLY_NG4 POLY_NG4;

typedef struct _GT3ZVertexD3D_Type GT3ZVertexD3D;

typedef struct SP_SUBDIV_STRUCT SP_SUBDIV_STRUCT;

typedef void BSPLeafFunc();

typedef void G2AppData;

struct POLY_FT4 // hashcode: 0xE80A6EF5 (dec: -401969419)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	unsigned short clut; // size=0, offset=14
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	unsigned char u1; // size=0, offset=20
	unsigned char v1; // size=0, offset=21
	unsigned short tpage; // size=0, offset=22
	short x2; // size=0, offset=24
	short y2; // size=0, offset=26
	unsigned char u2; // size=0, offset=28
	unsigned char v2; // size=0, offset=29
	unsigned short pad1; // size=0, offset=30
	short x3; // size=0, offset=32
	short y3; // size=0, offset=34
	unsigned char u3; // size=0, offset=36
	unsigned char v3; // size=0, offset=37
	unsigned short pad2; // size=0, offset=38
};

union FONT_76fake // Hashcode: 0x5CBA53B5 (dec: 1555714997)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: font.o, font.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: font.o, font.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: font.o, font.o
};

union FONT_77fake // Hashcode: 0x3A35F4F6 (dec: 976614646)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct FontTracker // hashcode: 0xF3EACAD7 (dec: -202716457)
{
	struct FontChar font_buffer[256]; // size=1536, offset=0
	long font_xpos; // size=0, offset=1536
	long font_ypos; // size=0, offset=1540
	long font_buffIndex; // size=0, offset=1544
	short font_tpage; // size=0, offset=1548
	short font_clut; // size=0, offset=1550
	short font_vramU; // size=0, offset=1552
	short font_vramV; // size=0, offset=1554
	short font_width; // size=0, offset=1556
	short sprite_sort_push; // size=0, offset=1558
	short font_vramX; // size=0, offset=1560
	short font_vramY; // size=0, offset=1562
	char color_global; // size=0, offset=1564
	char color_local; // size=0, offset=1565
};

struct FONT_117fake // hashcode: 0xD31E71DD (dec: -752979491)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: font.o, font.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: font.o, font.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: font.o, font.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: font.o, font.o
};

struct font_color_t // hashcode: 0x444C2095 (dec: 1145839765)
{
	int r; // size=0, offset=0
	int g; // size=0, offset=4
	int b; // size=0, offset=8
};

struct FontPos // hashcode: 0xD28D6F4B (dec: -762482869)
{
	char x; // size=0, offset=0
	char y; // size=0, offset=1
	char w; // size=0, offset=2
	char h; // size=0, offset=3
};

typedef struct POLY_FT4 POLY_FT4;

typedef struct FontTracker FontTracker;

typedef struct font_color_t font_color_t;

typedef struct FontPos FontPos;

union GAMEPAD_76fake // Hashcode: 0xE68CFCAC (dec: -426967892)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: gamepad.o, gamepad.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: gamepad.o, gamepad.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: gamepad.o, gamepad.o
};

union GAMEPAD_77fake // Hashcode: 0xE491B901 (dec: -460211967)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct GAMEPAD_114fake // hashcode: 0x9DB41AFD (dec: -1649140995)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: gamepad.o, gamepad.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: gamepad.o, gamepad.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: gamepad.o, gamepad.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: gamepad.o, gamepad.o
};

union GAMEPAD_194fake // Hashcode: 0xA89F75F6 (dec: -1465944586)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct JoypadMappingStruct // hashcode: 0xFBD1C09A (dec: -70139750)
{
	unsigned short psxData; // size=0, offset=0
	unsigned short translation; // size=0, offset=2
};

struct AnalogueData // hashcode: 0xAA926500 (dec: -1433246464)
{
	unsigned short pad; // size=0, offset=0
	unsigned char xR; // size=0, offset=2
	unsigned char yR; // size=0, offset=3
	unsigned char xL; // size=0, offset=4
	unsigned char yL; // size=0, offset=5
};

struct ControllerPacket // hashcode: 0xEA7D8F3D (dec: -360870083)
{
	unsigned char transStatus; // size=0, offset=0
	unsigned char dataFormat; // size=0, offset=1
	union {
		unsigned short pad; // size=0, offset=0
		unsigned short multitap[16]; // size=32, offset=0
		unsigned short mouse[2]; // size=4, offset=0
		unsigned short negcon[3]; // size=6, offset=0
		struct AnalogueData analogue; // size=6, offset=0
	} data; // size=32, offset=2, found in object files: gamepad.o, gamepad.o
};

typedef struct JoypadMappingStruct JoypadMapping;

typedef struct AnalogueData AnalogueData;

typedef struct ControllerPacket ControllerPacket;

struct _G2EulerAngles_Type // hashcode: 0x7B78521B (dec: 2071482907)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short order; // size=0, offset=6
};

enum _G2AnimCallbackMsg_Enum // Hashcode: 0x53E4976B (dec: 1407489899)
{
	G2ANIM_MSG_DONE = 1,
	G2ANIM_MSG_LOOPPOINT = 2,
	G2ANIM_MSG_SECTION_INTERPDONE = 3,
	G2ANIM_MSG_SEGCTRLR_INTERPDONE = 4,
	G2ANIM_MSG_SWALARMSET = 5,
	G2ANIM_MSG_PLAYEFFECT = 6,
};

union INSTANCE_76fake // Hashcode: 0x4082B530 (dec: 1082307888)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: instance.o, instance.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: instance.o, instance.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: instance.o, instance.o
};

union INSTANCE_77fake // Hashcode: 0xCEEC7BCA (dec: -823362614)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _InstanceHandle // hashcode: 0x6CCD5C02 (dec: 1825397762)
{
	struct _Instance *instance; // size=664, offset=0
	long instanceID; // size=0, offset=4
};

struct evCollideInstanceStatsData // hashcode: 0xB47C627B (dec: -1266916741)
{
	struct _Instance *instance; // size=664, offset=0
	unsigned long distance; // size=0, offset=4
	struct _SVector relativePosition; // size=8, offset=8
	long xyDistance; // size=0, offset=16
	long zDelta; // size=0, offset=20
};

union INSTANCE_219fake // Hashcode: 0xF3528BAA (dec: -212694102)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct INICommand // hashcode: 0x1F5BD226 (dec: 526111270)
{
	short command; // size=0, offset=0
	short numParameters; // size=0, offset=2
	long parameter[0]; // size=0, offset=4
};

struct PhysObProperties // hashcode: 0xF5D09A10 (dec: -170878448)
{
	unsigned short version; // size=0, offset=0
	unsigned short family; // size=0, offset=2
	unsigned short ID; // size=0, offset=4
	unsigned short Type; // size=0, offset=6
};

struct PhysObSplinter // hashcode: 0xC0FCEF99 (dec: -1057165415)
{
	long numSplintData; // size=0, offset=0
	void *splinterData; // size=0, offset=4
};

struct PhysObWeaponAttributes // hashcode: 0xA4F6F91F (dec: -1527318241)
{
	long Damage; // size=0, offset=0
	long AltDamage; // size=0, offset=4
	short knockBackDistance; // size=0, offset=8
	char knockBackFrames; // size=0, offset=10
	char dropSound; // size=0, offset=11
	char Class; // size=0, offset=12
	char ThrowSphere; // size=0, offset=13
	char LeftHandSphere; // size=0, offset=14
	char RightHandSphere; // size=0, offset=15
	struct _PhysObLight *Light; // size=0, offset=16
	struct PhysObSplinter splinter; // size=8, offset=20
};

struct _PhysObLight // hashcode: 0x5300709A (dec: 1392537754)
{
	unsigned char length; // size=0, offset=0
	unsigned char segment; // size=0, offset=1
	short speed; // size=0, offset=2
	struct LightTableEntry *lightTable; // size=8, offset=4
};

struct __PhysObProjectileData // hashcode: 0x40B34E2E (dec: 1085492782)
{
	char model; // size=0, offset=0
	char startAnim; // size=0, offset=1
	char loopAnim; // size=0, offset=2
	char endAnim; // size=0, offset=3
	long flags; // size=0, offset=4
	struct PhysObWeaponAttributes *weapon; // size=28, offset=8
};

struct LightTableEntry // hashcode: 0xB084076C (dec: -1333524628)
{
	short r; // size=0, offset=0
	short g; // size=0, offset=2
	short b; // size=0, offset=4
	short radius; // size=0, offset=6
};

struct SavedIntroSmall // hashcode: 0x6F798336 (dec: 1870234422)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
	short introUniqueID; // size=0, offset=4
	short extraDataSize; // size=0, offset=6
};

union INSTANCE_265fake // Hashcode: 0x06F11160 (dec: 116461920)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

typedef struct _G2EulerAngles_Type G2EulerAngles;

typedef enum _G2AnimCallbackMsg_Enum G2AnimCallbackMsg;

typedef struct _InstanceHandle InstanceHandle;

typedef struct evCollideInstanceStatsData evCollideInstanceStatsData;

typedef struct INICommand INICommand;

typedef struct PhysObProperties PhysObProperties;

typedef struct PhysObSplinter PhysObSplinter;

typedef struct PhysObWeaponAttributes PhysObWeaponAttributes;

typedef struct __PhysObProjectileData PhysObProjData;

typedef struct LightTableEntry LightTableEntry;

typedef struct _PhysObLight PhysObLight;

typedef struct SavedIntroSmall SavedIntroSmall;

union CAMERA_71fake // Hashcode: 0x87FAE04B (dec: -2013601717)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: camera.o, camera.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: camera.o, camera.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: camera.o, camera.o
};

union CAMERA_72fake // Hashcode: 0x67A99979 (dec: 1739168121)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct CameraCollisionInfo // hashcode: 0xC0691B43 (dec: -1066853565)
{
	struct _TFace (*tfaceList[5]); // size=20, offset=0
	struct _Terrain (*tfaceTerrain[5]); // size=20, offset=20
	short bspTree[6]; // size=12, offset=40
	short lengthList[6]; // size=12, offset=52
	long flags; // size=0, offset=64
	long line; // size=0, offset=68
	long numCollided; // size=0, offset=72
	long lenCenterToExtend; // size=0, offset=76
	struct _Sphere *start; // size=12, offset=80
	struct _Sphere *end; // size=12, offset=84
	long cldLines; // size=0, offset=88
};

struct _LCollideInfo // hashcode: 0x59317F55 (dec: 1496416085)
{
	struct _TFace *tface; // size=12, offset=0
	struct _Terrain *terrain; // size=92, offset=4
	int curTree; // size=0, offset=8
};

union CAMERA_200fake // Hashcode: 0x07BCF479 (dec: 129823865)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct CameraCollisionInfo CameraCollisionInfo;

typedef struct _LCollideInfo LCollideInfo;

union LIGHT3D_71fake // Hashcode: 0x61885C11 (dec: 1636326417)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: light3d.o, light3d.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: light3d.o, light3d.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: light3d.o, light3d.o
};

union LIGHT3D_72fake // Hashcode: 0xBDAA1016 (dec: -1112928234)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _PCollideInfo // hashcode: 0x0EA8C99E (dec: 245942686)
{
	short type; // size=0, offset=0
	short segment; // size=0, offset=2
	void *prim; // size=0, offset=4
	struct _Instance *inst; // size=0, offset=8
	struct SVECTOR wNormal; // size=8, offset=12
	struct SVECTOR *newPoint; // size=8, offset=20
	struct SVECTOR *oldPoint; // size=8, offset=24
	struct SVECTOR cldPoint; // size=8, offset=28
	long collideType; // size=0, offset=36
	struct _Instance *instance; // size=0, offset=40
};

struct LIGHT3D_109fake // hashcode: 0x7353679E (dec: 1934845854)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: light3d.o, light3d.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: light3d.o, light3d.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: light3d.o, light3d.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: light3d.o, light3d.o
};

union LIGHT3D_204fake // Hashcode: 0x19FFDDE0 (dec: 436198880)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct LIGHT3D_224fake // hashcode: 0xA3512640 (dec: -1554962880)
{
	long m[5]; // size=20, offset=0
};

typedef struct _PCollideInfo PCollideInfo;

typedef long LightFunc();

struct CdlFILE // hashcode: 0x759BDCAF (dec: 1973148847)
{
	struct CdlLOC pos; // size=4, offset=0
	unsigned long size; // size=0, offset=4
	char name[16]; // size=16, offset=8
};

union LOAD3D_76fake // Hashcode: 0x4B3EBA8B (dec: 1262402187)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: load3d.o, load3d.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: load3d.o, load3d.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: load3d.o, load3d.o
};

union LOAD3D_77fake // Hashcode: 0xA0DF87EE (dec: -1595963410)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct LOAD3D_114fake // hashcode: 0x79896BBE (dec: 2039049150)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: load3d.o, load3d.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: load3d.o, load3d.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: load3d.o, load3d.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: load3d.o, load3d.o
};

struct _LoadStatus // hashcode: 0xE16450FD (dec: -513519363)
{
	struct _ReadQueueEntry currentQueueFile; // size=44, offset=0
	long state; // size=0, offset=44
	long bytesTransferred; // size=0, offset=48
	long lastCheckPos; // size=0, offset=52
	long cdWaitTime; // size=0, offset=56
	unsigned char *compSrcAddr; // size=0, offset=60
	unsigned char *compDstAddr; // size=0, offset=64
	long compControlbits; // size=0, offset=68
	long compControl; // size=0, offset=72
	long compEndBytes; // size=0, offset=76
	long decompressLen; // size=0, offset=80
	long checksum; // size=0, offset=84
	long *checkAddr; // size=0, offset=88
	struct _BigFile bigFile; // size=36, offset=92
	void *buffer1; // size=0, offset=128
	void *buffer2; // size=0, offset=132
	int changeDir; // size=0, offset=136
	long endLoadTime; // size=0, offset=140
	long currentDirLoading; // size=0, offset=144
	long currentSector; // size=0, offset=148
	long sectorTime; // size=0, offset=152
	long seekTime; // size=0, offset=156
};

struct RedirectList // hashcode: 0x2A55578C (dec: 710236044)
{
	long numPointers; // size=0, offset=0
	long *data; // size=0, offset=4
};

typedef struct CdlFILE CdlFILE;

typedef struct _LoadStatus LoadStatus;

typedef struct RedirectList RedirectList;

struct DRAWENV // hashcode: 0x16100ADC (dec: 370150108)
{
	struct RECT clip; // size=8, offset=0
	short ofs[2]; // size=4, offset=8
	struct RECT tw; // size=8, offset=12
	unsigned short tpage; // size=0, offset=20
	unsigned char dtd; // size=0, offset=22
	unsigned char dfe; // size=0, offset=23
	unsigned char isbg; // size=0, offset=24
	unsigned char r0; // size=0, offset=25
	unsigned char g0; // size=0, offset=26
	unsigned char b0; // size=0, offset=27
	struct DR_ENV dr_env; // size=64, offset=28
};

struct DISPENV // hashcode: 0x2FE28827 (dec: 803375143)
{
	struct RECT disp; // size=8, offset=0
	struct RECT screen; // size=8, offset=8
	unsigned char isinter; // size=0, offset=16
	unsigned char isrgb24; // size=0, offset=17
	unsigned char pad0; // size=0, offset=18
	unsigned char pad1; // size=0, offset=19
};

struct BLK_FILL // hashcode: 0xB175B1A2 (dec: -1317686878)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	unsigned short x0; // size=0, offset=8
	unsigned short y0; // size=0, offset=10
	unsigned short w; // size=0, offset=12
	unsigned short h; // size=0, offset=14
};

union MAIN_76fake // Hashcode: 0x41DA11A7 (dec: 1104810407)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: main.o, main.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: main.o, main.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: main.o, main.o
};

union MAIN_77fake // Hashcode: 0x72C9141F (dec: 1925780511)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MAIN_114fake // hashcode: 0xFCD71962 (dec: -53012126)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: main.o, main.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: main.o, main.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: main.o, main.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: main.o, main.o
};

struct MainTracker // hashcode: 0x4DA4AE2D (dec: 1302638125)
{
	long mainState; // size=0, offset=0
	long previousState; // size=0, offset=4
	long movieNum; // size=0, offset=8
	long done; // size=0, offset=12
};

union MAIN_198fake // Hashcode: 0x204E9087 (dec: 542019719)
{
	unsigned short pad; // size=0, offset=0
	unsigned short multitap[16]; // size=32, offset=0
	unsigned short mouse[2]; // size=4, offset=0
	unsigned short negcon[3]; // size=6, offset=0
	struct AnalogueData analogue; // size=6, offset=0
};

struct POLY_F4_SEMITRANS // hashcode: 0xF864E0C5 (dec: -127606587)
{
	unsigned long tag; // size=0, offset=0
	unsigned long dr_tpage; // size=0, offset=4
	unsigned char r0; // size=0, offset=8
	unsigned char g0; // size=0, offset=9
	unsigned char b0; // size=0, offset=10
	unsigned char code; // size=0, offset=11
	short x0; // size=0, offset=12
	short y0; // size=0, offset=14
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	short x2; // size=0, offset=20
	short y2; // size=0, offset=22
	short x3; // size=0, offset=24
	short y3; // size=0, offset=26
};

union MAIN_236fake // Hashcode: 0x4EE029EC (dec: 1323313644)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct FullScreenItem // hashcode: 0x62EB9D24 (dec: 1659608356)
{
	char name[48]; // size=48, offset=0
	int timeout; // size=0, offset=48
	int buttonTimeout; // size=0, offset=52
	int nextItem; // size=0, offset=56
};

typedef struct DRAWENV DRAWENV;

typedef struct DISPENV DISPENV;

typedef struct BLK_FILL BLK_FILL;

typedef struct MainTracker MainTracker;

typedef struct POLY_F4_SEMITRANS POLY_F4_SEMITRANS;

typedef struct FullScreenItem FullScreenItem;

union GAMELOOP_76fake // Hashcode: 0xE58B499C (dec: -443856484)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: gameloop.o, gameloop.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: gameloop.o, gameloop.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: gameloop.o, gameloop.o
};

union GAMELOOP_77fake // Hashcode: 0x3FA41784 (dec: 1067718532)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union GAMELOOP_187fake // Hashcode: 0x469F0A75 (dec: 1184828021)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

struct _FXTracker // hashcode: 0x19DF49A8 (dec: 434063784)
{
	struct _FX_MATRIX matrixPool[32]; // size=1408, offset=0
	struct NodeType usedMatrixList; // size=8, offset=1408
	struct NodeType freeMatrixList; // size=8, offset=1416
	struct _FX_PRIM primPool[256]; // size=29696, offset=1424
	struct NodeType usedPrimList; // size=8, offset=31120
	struct NodeType usedPrimListSprite; // size=8, offset=31128
	struct NodeType freePrimList; // size=8, offset=31136
};

union GAMELOOP_230fake // Hashcode: 0x342B6FC3 (dec: 875261891)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct StreamUnitPortal // hashcode: 0x3C2EA24A (dec: 1009689162)
{
	char tolevelname[16]; // size=16, offset=0
	long MSignalID; // size=0, offset=16
	long streamID; // size=0, offset=20
	short minx; // size=0, offset=24
	short miny; // size=0, offset=26
	short minz; // size=0, offset=28
	short flags; // size=0, offset=30
	short maxx; // size=0, offset=32
	short maxy; // size=0, offset=34
	short maxz; // size=0, offset=36
	short pad2; // size=0, offset=38
	struct _StreamUnit *toStreamUnit; // size=64, offset=40
	struct _SVector t1[3]; // size=24, offset=44
	struct _SVector t2[3]; // size=24, offset=68
};

typedef struct _FXTracker FXTracker;

typedef struct StreamUnitPortal StreamUnitPortal;

typedef void GlyphProcessFunction();

union SIGNAL_71fake // Hashcode: 0xEA0A4DF9 (dec: -368423431)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: signal.o, signal.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: signal.o, signal.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: signal.o, signal.o
};

union SIGNAL_72fake // Hashcode: 0x846FFEC0 (dec: -2073035072)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct SIGNAL_109fake // hashcode: 0xC48F5300 (dec: -997240064)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: signal.o, signal.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: signal.o, signal.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: signal.o, signal.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: signal.o, signal.o
};

union SIGNAL_200fake // Hashcode: 0x1BF60E5E (dec: 469110366)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct SignalInfo // hashcode: 0xA082A240 (dec: -1602051520)
{
	long (*signalHandleFunc)(); // size=0, offset=0
	short length; // size=0, offset=4
	short onlyPlayer; // size=0, offset=6
	void (*signalRelocateFunc)(); // size=0, offset=8
};

typedef struct SignalInfo SignalInfo;

typedef void SignalGlobalValueFunc();

typedef long HandleSignalFunc();

typedef long SignalHandleFunc();

typedef void RelocateSignalFunc();

union COLLIDE_76fake // Hashcode: 0x9C424E0A (dec: -1673376246)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: collide.o, collide.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: collide.o, collide.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: collide.o, collide.o
};

struct _Triangle2D // hashcode: 0x65119702 (dec: 1695651586)
{
	short x0; // size=0, offset=0
	short y0; // size=0, offset=2
	short x1; // size=0, offset=4
	short y1; // size=0, offset=6
	short x2; // size=0, offset=8
	short y2; // size=0, offset=10
};

union COLLIDE_77fake // Hashcode: 0xB964C5D4 (dec: -1184578092)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _HNormal // hashcode: 0x7FA79C4C (dec: 2141690956)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _HFaceInfo // hashcode: 0xF9D750FD (dec: -103329539)
{
	long flags; // size=0, offset=0
	long attr; // size=0, offset=4
	struct _HFace *hface; // size=12, offset=8
	struct _SVector normal; // size=8, offset=12
	struct _HVertex *vertex0; // size=12, offset=20
	struct _HVertex *vertex1; // size=12, offset=24
	struct _HVertex *vertex2; // size=12, offset=28
};

struct _CollideInfo // hashcode: 0x1039D452 (dec: 272225362)
{
	void *level; // size=0, offset=0
	char flags; // size=0, offset=4
	char segment; // size=0, offset=5
	char type0; // size=0, offset=6
	char type1; // size=0, offset=7
	void *prim0; // size=0, offset=8
	void *prim1; // size=0, offset=12
	void *inst0; // size=0, offset=16
	void *inst1; // size=0, offset=20
	struct SVECTOR point0; // size=8, offset=24
	struct SVECTOR point1; // size=8, offset=32
	struct _Position offset; // size=6, offset=40
	short bspID; // size=0, offset=46
};

struct SCollideInfo // hashcode: 0x4BB0D6E5 (dec: 1269880549)
{
	struct _Sphere *sphere; // size=12, offset=0
	struct SVECTOR *oldPos; // size=8, offset=4
	void (*collideFunc)(); // size=0, offset=8
	long id; // size=0, offset=12
	long segment; // size=0, offset=16
	struct _Instance *instance; // size=664, offset=20
	void *prim; // size=0, offset=24
};

union COLLIDE_216fake // Hashcode: 0xC5459EA9 (dec: -985293143)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct PandTScratch // hashcode: 0x9609B610 (dec: -1777748464)
{
	struct MATRIX posMatrix; // size=32, offset=0
	struct _SVector normal; // size=8, offset=32
	struct _Vector dpv; // size=12, offset=40
	struct _SVector planePoint; // size=8, offset=52
	long ignore_attr; // size=0, offset=60
	long accept_attr; // size=0, offset=64
	short *backface_flag; // size=0, offset=68
	struct _SVector newPos; // size=8, offset=72
	struct _SVector oldPos; // size=8, offset=80
	int flags; // size=0, offset=88
	int i; // size=0, offset=92
	int slack; // size=0, offset=96
	long in_spectral; // size=0, offset=100
	short *normalList; // size=0, offset=104
	struct _TVertex *vertexList; // size=12, offset=108
	struct _TFace *result; // size=12, offset=112
	struct _SVector line; // size=8, offset=116
};

struct COLLIDE_239fake // hashcode: 0xC1DBC6F7 (dec: -1042561289)
{
	long m[3]; // size=12, offset=0
};

struct SandHFScratch // hashcode: 0xADF2919E (dec: -1376611938)
{
	struct _SVector normal; // size=8, offset=0
	struct MATRIX posMatrix; // size=32, offset=8
	struct _Vector dpv; // size=12, offset=40
	struct _SVector triPoint; // size=8, offset=52
	struct _SVector planePoint; // size=8, offset=60
};

struct SandTScratch // hashcode: 0x3D095FBA (dec: 1024024506)
{
	struct MATRIX posMatrix; // size=32, offset=0
	struct _Vector dpv; // size=12, offset=32
	struct _HNormal *normalList; // size=8, offset=44
	struct _CollideInfo collideInfo; // size=48, offset=48
	struct _HFaceInfo hfaceInfo; // size=32, offset=96
	struct _SVector midPoint; // size=8, offset=128
	struct _SVector spherePos; // size=8, offset=136
	void (*collideFunc)(); // size=0, offset=144
	struct _Instance *instance; // size=664, offset=148
	long edge; // size=0, offset=152
	long in_spectral; // size=0, offset=156
	struct _SVector oldPos; // size=8, offset=160
	void *prim; // size=0, offset=168
	struct _SVector normal; // size=8, offset=172
	struct _Sphere sphere; // size=12, offset=180
	short result; // size=0, offset=192
	short i; // size=0, offset=194
	long collide_ignoreAttr; // size=0, offset=196
	long collide_acceptAttr; // size=0, offset=200
	long midRadius; // size=0, offset=204
	struct _TVertex *vertexList; // size=12, offset=208
};

struct IandTScratch // hashcode: 0x8958027F (dec: -1990720897)
{
	struct MATRIX posMatrix; // size=32, offset=0
	struct _SVector normal; // size=8, offset=32
	struct _Vector dpv; // size=12, offset=40
	struct _SVector planePoint; // size=8, offset=52
	struct _SVector line; // size=8, offset=60
	struct _SVector oldPos; // size=8, offset=68
	struct _SVector newPos; // size=8, offset=76
	int i; // size=0, offset=84
	long in_spectral; // size=0, offset=88
	short *normalList; // size=0, offset=92
	struct _TVertex *vertexList; // size=12, offset=96
};

struct PandTFScratch // hashcode: 0x9B3A4ECC (dec: -1690677556)
{
	struct MATRIX posMatrix; // size=32, offset=0
	struct _SVector planePoint; // size=8, offset=32
	struct _SVector newPos; // size=8, offset=40
	struct _SVector oldPos; // size=8, offset=48
	struct _SVector normal; // size=8, offset=56
	struct _Vector dpv; // size=12, offset=64
};

typedef struct _Triangle2D Triangle2D;

typedef struct _HNormal HNormal;

typedef struct _HFaceInfo HFaceInfo;

typedef struct _CollideInfo CollideInfo;

typedef struct SCollideInfo SCollideInfo;

typedef long CollideBoundFunc();

union TIMER_71fake // Hashcode: 0xEC9D7CBD (dec: -325223235)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: timer.o, timer.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: timer.o, timer.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: timer.o, timer.o
};

union TIMER_72fake // Hashcode: 0x484CB7D1 (dec: 1212987345)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct TIMER_109fake // hashcode: 0x71B7A8DF (dec: 1907861727)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: timer.o, timer.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: timer.o, timer.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: timer.o, timer.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: timer.o, timer.o
};

union BSP_71fake // Hashcode: 0x0DEDCD90 (dec: 233688464)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: bsp.o, bsp.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: bsp.o, bsp.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: bsp.o, bsp.o
};

union BSP_72fake // Hashcode: 0x04FFC095 (dec: 83869845)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct BSP_109fake // hashcode: 0x3228DEB2 (dec: 841539250)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: bsp.o, bsp.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: bsp.o, bsp.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: bsp.o, bsp.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: bsp.o, bsp.o
};

union BSP_204fake // Hashcode: 0xF94FDEB8 (dec: -112206152)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct BSPScratch // hashcode: 0xA7753475 (dec: -1485491083)
{
	struct MATRIX vv[2]; // size=64, offset=0
	struct MATRIX camMatrix; // size=32, offset=64
	struct VECTOR dpv[3]; // size=48, offset=96
	long d[6]; // size=24, offset=144
	struct MATRIX boundMatrix; // size=32, offset=168
	long in_spectral; // size=0, offset=200
};

typedef void asm_fn();

typedef long hook_fn_1();

typedef long hook_fn_2();

typedef long hook_fn_3();

typedef long hook_fn_4();

typedef long hook_fn_5();

typedef long hook_fn_6();

typedef long hook_fn_7();

typedef long hook_fn_8();

union OBTABLE_76fake // Hashcode: 0x54966F09 (dec: 1419144969)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: obtable.o, obtable.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: obtable.o, obtable.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: obtable.o, obtable.o
};

union OBTABLE_77fake // Hashcode: 0xA27C1FFE (dec: -1568923650)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _ObjectOwnerInfo // hashcode: 0x6198BBF6 (dec: 1637399542)
{
	long magicnum; // size=0, offset=0
	short animID; // size=0, offset=4
	char objectName[0]; // size=0, offset=6
};

struct OBTABLE_114fake // hashcode: 0x4745AD9E (dec: 1195748766)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: obtable.o, obtable.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: obtable.o, obtable.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: obtable.o, obtable.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: obtable.o, obtable.o
};

struct ObjectAccess // hashcode: 0xBD2BD58C (dec: -1121200756)
{
	char *objectName; // size=0, offset=0
	void *object; // size=0, offset=4
};

union OBTABLE_191fake // Hashcode: 0x3F249253 (dec: 1059361363)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct _ObjectOwnerInfo ObjectOwnerInfo;

typedef struct ObjectAccess ObjectAccess;

struct POLY_FT3 // hashcode: 0x689EE460 (dec: 1755243616)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	unsigned short clut; // size=0, offset=14
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	unsigned char u1; // size=0, offset=20
	unsigned char v1; // size=0, offset=21
	unsigned short tpage; // size=0, offset=22
	short x2; // size=0, offset=24
	short y2; // size=0, offset=26
	unsigned char u2; // size=0, offset=28
	unsigned char v2; // size=0, offset=29
	unsigned short pad1; // size=0, offset=30
};

union PIPE3D_71fake // Hashcode: 0x75AF626A (dec: 1974428266)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: pipe3d.o, pipe3d.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: pipe3d.o, pipe3d.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: pipe3d.o, pipe3d.o
};

union PIPE3D_72fake // Hashcode: 0xD623A6AE (dec: -702306642)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct _Mirror // hashcode: 0x1B2B4DFD (dec: 455822845)
{
	short a; // size=0, offset=0
	short b; // size=0, offset=2
	short c; // size=0, offset=4
	short d; // size=0, offset=6
};

struct PIPE3D_109fake // hashcode: 0x0CB302E8 (dec: 213058280)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: pipe3d.o, pipe3d.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: pipe3d.o, pipe3d.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: pipe3d.o, pipe3d.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: pipe3d.o, pipe3d.o
};

struct _FXHalvePlane // hashcode: 0xBA4E20A8 (dec: -1169284952)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	long diffTime; // size=0, offset=16
	struct _PlaneConstants ringPlane; // size=12, offset=20
	long currentColor; // size=0, offset=32
	long *colorArray; // size=0, offset=36
	short numColors; // size=0, offset=40
	short colorBlendLife; // size=0, offset=42
};

struct _FXGlowEffect // hashcode: 0xC183A1B1 (dec: -1048337999)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	unsigned long diffTime; // size=0, offset=16
	long *colorArray; // size=0, offset=20
	long currentColor; // size=0, offset=24
	short numColors; // size=0, offset=28
	short colorBlendCycle; // size=0, offset=30
	short width; // size=0, offset=32
	short height; // size=0, offset=34
	unsigned char numSegments; // size=0, offset=36
	unsigned char SegmentInc; // size=0, offset=37
	short segment; // size=0, offset=38
	short fadein_time; // size=0, offset=40
	short fadeout_time; // size=0, offset=42
};

union PIPE3D_214fake // Hashcode: 0x4F1430CB (dec: 1326723275)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct PIPE3D_234fake // hashcode: 0x8E2640D1 (dec: -1910095663)
{
	long m[3]; // size=12, offset=0
};

struct PIPE3D_235fake // hashcode: 0xD78796BC (dec: -678979908)
{
	long m[5]; // size=20, offset=0
};

struct TransformAnimatedInstanceVerticesWork_t // hashcode: 0x1916DCEE (dec: 420928750)
{
	struct MATRIX scTransform; // size=32, offset=0
	struct MATRIX mirrorMatrix; // size=32, offset=32
	struct MATRIX llm; // size=32, offset=64
	struct _Vector vector; // size=12, offset=96
};

typedef struct POLY_FT3 POLY_FT3;

typedef struct _Mirror Mirror;

typedef struct _FXHalvePlane FXHalvePlane;

typedef struct _FXGlowEffect FXGlowEffect;

typedef struct TransformAnimatedInstanceVerticesWork_t TransformAnimatedInstanceVerticesWork_t;

union SCRIPT_76fake // Hashcode: 0x8B52F04F (dec: -1957498801)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: script.o, script.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: script.o, script.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: script.o, script.o
};

union SCRIPT_77fake // Hashcode: 0x12F87ABB (dec: 318274235)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct SCRIPT_114fake // hashcode: 0x07F19899 (dec: 133273753)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: script.o, script.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: script.o, script.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: script.o, script.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: script.o, script.o
};

union SCRIPT_196fake // Hashcode: 0x2E5369C7 (dec: 777218503)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct GenericTune // hashcode: 0x09E33D5D (dec: 165887325)
{
	long flags; // size=0, offset=0
	void *shatterData; // size=0, offset=4
};

struct FXSplinter // hashcode: 0xA1CAB3DA (dec: -1580551206)
{
	short flags; // size=0, offset=0
	short soundFx; // size=0, offset=2
	short chunkVelXY; // size=0, offset=4
	short chunkVelZ; // size=0, offset=6
	short chunkVelRng; // size=0, offset=8
	short triVelRng; // size=0, offset=10
	short lifetime; // size=0, offset=12
	short faceLimit; // size=0, offset=14
	short rotRateRng; // size=0, offset=16
	short gravityZ; // size=0, offset=18
};

typedef struct GenericTune GenericTune;

typedef struct FXSplinter FXSplinter;

union MATH3D_76fake // Hashcode: 0x1E884C68 (dec: 512248936)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: math3d.o, math3d.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: math3d.o, math3d.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: math3d.o, math3d.o
};

union MATH3D_77fake // Hashcode: 0xF3BD4CE6 (dec: -205697818)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

enum MATH3D_AXIS // Hashcode: 0x49D572F5 (dec: 1238725365)
{
	AXIS_X = 0,
	AXIS_Y = 1,
	AXIS_Z = 2,
	AXIS_NEG_X = 3,
	AXIS_NEG_Y = 4,
	AXIS_NEG_Z = 5,
};

union SPLINE_71fake // Hashcode: 0x026BF980 (dec: 40630656)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: spline.o, spline.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: spline.o, spline.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: spline.o, spline.o
};

union SPLINE_72fake // Hashcode: 0x15012A95 (dec: 352397973)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct DR_TPAGE // hashcode: 0xC8B03788 (dec: -927975544)
{
	unsigned long tag; // size=0, offset=0
	unsigned long code[1]; // size=4, offset=4
};

union FX_71fake // Hashcode: 0x5CFDA5A1 (dec: 1560126881)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: fx.o, fx.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: fx.o, fx.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: fx.o, fx.o
};

union FX_72fake // Hashcode: 0x0E72D00D (dec: 242405389)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct FX_109fake // hashcode: 0xBBADB4D2 (dec: -1146243886)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: fx.o, fx.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: fx.o, fx.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: fx.o, fx.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: fx.o, fx.o
};

struct _POLY_SG4 // hashcode: 0x9BC50268 (dec: -1681587608)
{
	unsigned long tag; // size=0, offset=0
	unsigned long drawTPage1; // size=0, offset=4
	struct _BASIC_G4 p1; // size=32, offset=8
	unsigned long drawTPage2; // size=0, offset=40
	struct _BASIC_F4 p2; // size=20, offset=44
};

struct __GenericBubbleParams // hashcode: 0x56A8B0D6 (dec: 1453895894)
{
	struct __BubbleParams BP; // size=20, offset=0
	short number; // size=0, offset=20
	short birthradius; // size=0, offset=22
	short velx; // size=0, offset=24
	short vely; // size=0, offset=26
	short velz; // size=0, offset=28
	short velxrange; // size=0, offset=30
	short velyrange; // size=0, offset=32
	short velzrange; // size=0, offset=34
	short accx; // size=0, offset=36
	short accy; // size=0, offset=38
	short accz; // size=0, offset=40
	short accxrange; // size=0, offset=42
	short accyrange; // size=0, offset=44
	short acczrange; // size=0, offset=46
};

struct _FXGeneralEffect // hashcode: 0x42F7AAD9 (dec: 1123527385)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
};

struct _FXRibbon // hashcode: 0x969CC159 (dec: -1768111783)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	short numberVerts; // size=0, offset=16
	short endIndex; // size=0, offset=18
	struct SVECTOR *vertexPool; // size=8, offset=20
	short startSegment; // size=0, offset=24
	short endSegment; // size=0, offset=26
	long startColor; // size=0, offset=28
	long endColor; // size=0, offset=32
	short colorStepValue; // size=0, offset=36
	short faceLifeTime; // size=0, offset=38
	short startFadeValue; // size=0, offset=40
	short fadeStep; // size=0, offset=42
};

struct _FXParticle // hashcode: 0xF0C66D33 (dec: -255431373)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	struct TextureMT3 *texture; // size=16, offset=16
	void *fxprim_modify_process; // size=0, offset=20
	void *fxprim_process; // size=0, offset=24
	short size; // size=0, offset=28
	short primLifeTime; // size=0, offset=30
	short birthRadius; // size=0, offset=32
	short scaleSpeed; // size=0, offset=34
	struct _Position direction; // size=6, offset=36
	unsigned short flag_bits; // size=0, offset=42
	struct _Position acceleration; // size=6, offset=44
	short startScale; // size=0, offset=50
	struct _Position offset; // size=6, offset=52
	char startSegment; // size=0, offset=58
	char z_undulate; // size=0, offset=59
	long startColor; // size=0, offset=60
	long endColor; // size=0, offset=64
	short colorStepValue; // size=0, offset=68
	char numberBirthParticles; // size=0, offset=70
	char endSegment; // size=0, offset=71
	short startFadeValue; // size=0, offset=72
	short fadeStep; // size=0, offset=74
};

struct _FXLightBeam // hashcode: 0x09210877 (dec: 153159799)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	short startSeg; // size=0, offset=16
	short endSeg; // size=0, offset=18
	long color; // size=0, offset=20
};

struct _FXBlastringEffect // hashcode: 0x77A4372F (dec: 2007250735)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	struct _SVector position; // size=8, offset=16
	struct MATRIX matrix; // size=32, offset=24
	short segment; // size=0, offset=56
	short pad; // size=0, offset=58
	int radius; // size=0, offset=60
	int size1; // size=0, offset=64
	int size2; // size=0, offset=68
	int endRadius; // size=0, offset=72
	int colorchange_radius; // size=0, offset=76
	int vel; // size=0, offset=80
	int accl; // size=0, offset=84
	int height1; // size=0, offset=88
	int height2; // size=0, offset=92
	int height3; // size=0, offset=96
	short predator_offset; // size=0, offset=100
	short sortInWorld; // size=0, offset=102
	long color; // size=0, offset=104
	long startColor; // size=0, offset=108
	long endColor; // size=0, offset=112
};

struct _FXForceFieldEffect // hashcode: 0xC5F122A7 (dec: -974052697)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	struct _SVector offset; // size=8, offset=16
	short size; // size=0, offset=24
	short size_diff; // size=0, offset=26
	short size_change; // size=0, offset=28
	short deg; // size=0, offset=30
	short deg_change; // size=0, offset=32
	short start_fade; // size=0, offset=34
	short end_fade; // size=0, offset=36
	long color; // size=0, offset=40
};

struct _FXLightning // hashcode: 0xD5591AF3 (dec: -715580685)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	short deg; // size=0, offset=16
	short deg_inc; // size=0, offset=18
	struct _Position start_offset; // size=6, offset=20
	short startSeg; // size=0, offset=26
	struct _Instance *end_instance; // size=664, offset=28
	struct _Position end_offset; // size=6, offset=32
	short endSeg; // size=0, offset=38
	short matrixSeg; // size=0, offset=40
	short width; // size=0, offset=42
	short small_width; // size=0, offset=44
	short segs; // size=0, offset=46
	short sine_size; // size=0, offset=48
	short variation; // size=0, offset=50
	long color; // size=0, offset=52
	long glow_color; // size=0, offset=56
};

struct _FXFlash // hashcode: 0x5E4997AC (dec: 1581881260)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	long timeToColor; // size=0, offset=16
	long timeAtColor; // size=0, offset=20
	long timeFromColor; // size=0, offset=24
	long currentTime; // size=0, offset=28
	long color; // size=0, offset=32
};

struct GenericFXObject // hashcode: 0xEF654A2A (dec: -278574550)
{
	struct _GenericParticleParams *ParticleList; // size=56, offset=0
	struct _GenericRibbonParams *RibbonList; // size=24, offset=4
	struct _GenericGlowParams *GlowList; // size=28, offset=8
	struct _GenericLightningParams *LightningList; // size=44, offset=12
	struct _GenericBlastringParams *BlastList; // size=52, offset=16
	struct _GenericFlashParams *FlashList; // size=12, offset=20
	long *ColorList; // size=0, offset=24
};

union FX_200fake // Hashcode: 0xDBE294D8 (dec: -605907752)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct evObjectDraftData // hashcode: 0xAB2C029A (dec: -1423179110)
{
	short force; // size=0, offset=0
	unsigned short radius; // size=0, offset=2
	unsigned short radiusCoef; // size=0, offset=4
	unsigned short height; // size=0, offset=6
	unsigned short maxVelocity; // size=0, offset=8
};

struct _GlyphTuneData // hashcode: 0x5F8AD12F (dec: 1602933039)
{
	short glyph_size; // size=0, offset=0
	short glyph_darkness; // size=0, offset=2
	char glyph_costs[8]; // size=8, offset=4
	short glyph_range[8]; // size=16, offset=12
	long color_array[28]; // size=112, offset=28
};

struct __ReaverData // hashcode: 0xDF72C1BB (dec: -546127429)
{
	char ReaverPickedUp; // size=0, offset=0
	char ReaverOn; // size=0, offset=1
	short ReaverSize; // size=0, offset=2
	short CurrentReaver; // size=0, offset=4
	short ReaverDeg; // size=0, offset=6
	long ReaverImbueTime; // size=0, offset=8
	long ReaverGlowColor; // size=0, offset=12
	long ReaverBladeColor; // size=0, offset=16
	long ReaverBladeGlowColor; // size=0, offset=20
	short ReaverScale; // size=0, offset=24
	short ReaverTargetScale; // size=0, offset=26
	struct __ReaverSaveDat saveData; // size=4, offset=28
};

struct __ReaverTuneData // hashcode: 0x7544F4D5 (dec: 1967453397)
{
	unsigned long spectralGlowColor; // size=0, offset=0
	unsigned long materialGlowColor; // size=0, offset=4
	unsigned long sunlightGlowColor; // size=0, offset=8
	unsigned long waterGlowColor; // size=0, offset=12
	unsigned long stoneGlowColor; // size=0, offset=16
	unsigned long fireGlowColor; // size=0, offset=20
	unsigned long spiritGlowColor; // size=0, offset=24
	unsigned long soundGlowColor; // size=0, offset=28
	unsigned long spectralInnerColor; // size=0, offset=32
	unsigned long materialInnerColor; // size=0, offset=36
	unsigned long sunlightInnerColor; // size=0, offset=40
	unsigned long waterInnerColor; // size=0, offset=44
	unsigned long stoneInnerColor; // size=0, offset=48
	unsigned long fireInnerColor; // size=0, offset=52
	unsigned long spiritInnerColor; // size=0, offset=56
	unsigned long soundInnerColor; // size=0, offset=60
	unsigned long spectralInnerGlowColor; // size=0, offset=64
	unsigned long materialInnerGlowColor; // size=0, offset=68
	unsigned long sunlightInnerGlowColor; // size=0, offset=72
	unsigned long waterInnerGlowColor; // size=0, offset=76
	unsigned long stoneInnerGlowColor; // size=0, offset=80
	unsigned long fireInnerGlowColor; // size=0, offset=84
	unsigned long spiritInnerGlowColor; // size=0, offset=88
	unsigned long soundInnerGlowColor; // size=0, offset=92
	unsigned long icon_colors[24]; // size=96, offset=96
};

struct _POLY_TF4 // hashcode: 0xC4A7AB5D (dec: -995644579)
{
	unsigned long tag; // size=0, offset=0
	unsigned long drawTPage; // size=0, offset=4
	struct _BASIC_F4 p1; // size=20, offset=8
};

struct _POLY_2G4 // hashcode: 0x7A5D0AE3 (dec: 2052917987)
{
	unsigned long tag; // size=0, offset=0
	struct _BASIC_G4 p1; // size=32, offset=4
	struct _BASIC_G4 p2; // size=32, offset=36
};

struct _POLY_2G4T // hashcode: 0x6BFD6813 (dec: 1811769363)
{
	unsigned long tag; // size=0, offset=0
	unsigned long drawTPage1; // size=0, offset=4
	struct _BASIC_G4 p1; // size=32, offset=8
	struct _BASIC_G4 p2; // size=32, offset=40
};

typedef struct DR_TPAGE DR_TPAGE;

typedef struct _POLY_SG4 POLY_SG4;

typedef struct __GenericBubbleParams GenericBubbleParams;

typedef struct _FXGeneralEffect FXGeneralEffect;

typedef struct _FXRibbon FXRibbon;

typedef struct _FXParticle FXParticle;

typedef struct _FXLightBeam FXLightBeam;

typedef struct _FXBlastringEffect FXBlastringEffect;

typedef struct _FXForceFieldEffect FXForceFieldEffect;

typedef struct _FXLightning FXLightning;

typedef struct _FXFlash FXFlash;

typedef struct GenericFXObject GenericFXObject;

typedef struct evObjectDraftData evObjectDraftData;

typedef struct _GlyphTuneData GlyphTuneData;

typedef struct __ReaverData ReaverData;

typedef struct __ReaverTuneData ReaverTuneData;

typedef struct _POLY_TF4 POLY_TF4;

typedef struct _POLY_2G4 POLY_2G4;

typedef struct _POLY_2G4T POLY_2G4T;

union OBTABLE2_76fake // Hashcode: 0x4D642E63 (dec: 1298411107)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: obtable2.o, obtable2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: obtable2.o, obtable2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: obtable2.o, obtable2.o
};

union OBTABLE2_77fake // Hashcode: 0x61F15595 (dec: 1643206037)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct OBTABLE2_114fake // hashcode: 0xE2840E26 (dec: -494662106)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: obtable2.o, obtable2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: obtable2.o, obtable2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: obtable2.o, obtable2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: obtable2.o, obtable2.o
};

struct ObjectFunc // hashcode: 0xA268CEB6 (dec: -1570189642)
{
	char *scriptName; // size=0, offset=0
	void (*initFunc)(); // size=0, offset=4
	void (*processFunc)(); // size=0, offset=8
	void (*collideFunc)(); // size=0, offset=12
	unsigned long (*queryFunc)(); // size=0, offset=16
	void (*messageFunc)(); // size=0, offset=20
	void (*additionalCollideFunc)(); // size=0, offset=24
	void (*relocateTuneFunc)(); // size=0, offset=28
	void (*relocateInstObFunc)(); // size=0, offset=32
};

union OBTABLE2_204fake // Hashcode: 0x345A5DAC (dec: 878337452)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct ObjectFunc ObjectFunc;

union GENERIC_76fake // Hashcode: 0xA12E1DE7 (dec: -1590813209)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: generic.o, generic.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: generic.o, generic.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: generic.o, generic.o
};

union GENERIC_77fake // Hashcode: 0x1629F67D (dec: 371848829)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct GENERIC_114fake // hashcode: 0xE19B175E (dec: -509929634)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: generic.o, generic.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: generic.o, generic.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: generic.o, generic.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: generic.o, generic.o
};

struct evAnimationInstanceSwitchData // hashcode: 0xE6D47736 (dec: -422283466)
{
	struct _Instance *instance; // size=664, offset=0
	int anim; // size=0, offset=4
	int frame; // size=0, offset=8
	int frames; // size=0, offset=12
	int mode; // size=0, offset=16
};

union GENERIC_196fake // Hashcode: 0x4764A1AA (dec: 1197777322)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct evControlSaveDataData // hashcode: 0x87180C7A (dec: -2028467078)
{
	long length; // size=0, offset=0
	void *data; // size=0, offset=4
};

typedef struct evAnimationInstanceSwitchData evAnimationInstanceSwitchData;

typedef struct evControlSaveDataData evControlSaveDataData;

union SOUND_76fake // Hashcode: 0xB6D1F6DB (dec: -1227753765)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: sound.o, sound.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: sound.o, sound.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: sound.o, sound.o
};

union SOUND_77fake // Hashcode: 0x1FAF3D20 (dec: 531578144)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct SOUND_114fake // hashcode: 0x894DC33F (dec: -1991392449)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: sound.o, sound.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: sound.o, sound.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: sound.o, sound.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: sound.o, sound.o
};

struct AadInitAttr // hashcode: 0x44FDABE1 (dec: 1157475297)
{
	unsigned short updateMode; // size=0, offset=0
	unsigned short numSlots; // size=0, offset=2
	void (*nonBlockLoadProc)(); // size=0, offset=4
	void (*nonBlockBufferedLoadProc)(); // size=0, offset=8
	void (**memoryMallocProc)(); // size=0, offset=12
	void (*memoryFreeProc)(); // size=0, offset=16
	unsigned char memMallocType; // size=0, offset=20
	unsigned char unused1; // size=0, offset=21
	unsigned short unused2; // size=0, offset=22
};

struct ObjectPeriodicSound // hashcode: 0x20119A4E (dec: 538024526)
{
	unsigned char type; // size=0, offset=0
	unsigned char numSfxIDs; // size=0, offset=1
	unsigned char soundInst; // size=0, offset=2
	unsigned char flags; // size=0, offset=3
	unsigned short minVolDistance; // size=0, offset=4
	short pitch; // size=0, offset=6
	unsigned short pitchVariation; // size=0, offset=8
	unsigned char maxVolume; // size=0, offset=10
	unsigned char maxVolVariation; // size=0, offset=11
	unsigned char initialDelay; // size=0, offset=12
	unsigned char initialDelayVariation; // size=0, offset=13
	unsigned char onTime; // size=0, offset=14
	unsigned char onTimeVariation; // size=0, offset=15
	unsigned char offTime; // size=0, offset=16
	unsigned char offTimeVariation; // size=0, offset=17
};

struct ObjectEventSound // hashcode: 0xFC3D5C69 (dec: -63087511)
{
	unsigned char type; // size=0, offset=0
	unsigned char numSfxIDs; // size=0, offset=1
	unsigned char soundInst; // size=0, offset=2
	unsigned char flags; // size=0, offset=3
	unsigned short minVolDistance; // size=0, offset=4
	short pitch; // size=0, offset=6
	unsigned short pitchVariation; // size=0, offset=8
	unsigned char maxVolume; // size=0, offset=10
	unsigned char maxVolVariation; // size=0, offset=11
	unsigned char initialDelay; // size=0, offset=12
	unsigned char initialDelayVariation; // size=0, offset=13
};

struct ObjectOneShotSound // hashcode: 0xB059B6AF (dec: -1336297809)
{
	unsigned char type; // size=0, offset=0
	unsigned char numSfxIDs; // size=0, offset=1
	unsigned char soundInst; // size=0, offset=2
	unsigned char flags; // size=0, offset=3
	unsigned short minVolDistance; // size=0, offset=4
	short pitch; // size=0, offset=6
	unsigned short pitchVariation; // size=0, offset=8
	unsigned char maxVolume; // size=0, offset=10
	unsigned char maxVolVariation; // size=0, offset=11
	unsigned char initialDelay; // size=0, offset=12
	unsigned char initialDelayVariation; // size=0, offset=13
};

struct SoundEffectChannel // hashcode: 0x7A1E0979 (dec: 2048788857)
{
	unsigned char inUse; // size=0, offset=0
	unsigned char unused; // size=0, offset=1
	unsigned short unused1; // size=0, offset=2
	unsigned long handle; // size=0, offset=4
	short volume; // size=0, offset=8
	short volumeChangeTime; // size=0, offset=10
	short volumeChangeTimeSave; // size=0, offset=12
	short volumeChangePerUpdate; // size=0, offset=14
	short volumeChangeSign; // size=0, offset=16
	short volumeChangeErrPerUpdate; // size=0, offset=18
	short volumeChangeError; // size=0, offset=20
	short pitch; // size=0, offset=22
	short pitchChangeTime; // size=0, offset=24
	short pitchChangeTimeSave; // size=0, offset=26
	short pitchChangePerUpdate; // size=0, offset=28
	short pitchChangeSign; // size=0, offset=30
	short pitchChangeErrPerUpdate; // size=0, offset=32
	short pitchChangeError; // size=0, offset=34
};

union SOUND_196fake // Hashcode: 0xF2E8043D (dec: -219675587)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct AadInitAttr AadInitAttr;

typedef struct ObjectPeriodicSound ObjectPeriodicSound;

typedef struct ObjectEventSound ObjectEventSound;

typedef struct ObjectOneShotSound ObjectOneShotSound;

typedef struct SoundEffectChannel SoundEffectChannel;

struct AadVolume // hashcode: 0x9222ACDA (dec: -1843221286)
{
	short left; // size=0, offset=0
	short right; // size=0, offset=2
};

typedef struct AadVolume AadVolume;

struct AadSequenceHdr // hashcode: 0x29887C25 (dec: 696810533)
{
	unsigned long sequenceID; // size=0, offset=0
	unsigned long quarterNoteTime; // size=0, offset=4
	unsigned short ppqn; // size=0, offset=8
	unsigned short version; // size=0, offset=10
	unsigned short numTracks; // size=0, offset=12
	unsigned short unused; // size=0, offset=14
};

struct AadTempo // hashcode: 0x93159870 (dec: -1827301264)
{
	unsigned long quarterNoteTime; // size=0, offset=0
	unsigned short ppqn; // size=0, offset=4
};

typedef struct AadSequenceHdr AadSequenceHdr;

typedef struct AadTempo AadTempo;

union GXASSERT_76fake // Hashcode: 0x8B5B331F (dec: -1956957409)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: gxassert.o, gxassert.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: gxassert.o, gxassert.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: gxassert.o, gxassert.o
};

union GXASSERT_77fake // Hashcode: 0x3248AAC4 (dec: 843623108)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union AADASSRT_117fake // Hashcode: 0x37D1422D (dec: 936460845)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: aadassrt.o, aadassrt.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: aadassrt.o, aadassrt.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: aadassrt.o, aadassrt.o
};

union AADASSRT_118fake // Hashcode: 0x513C7E9E (dec: 1362919070)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct AadMemoryStruct // hashcode: 0xAF233074 (dec: -1356648332)
{
	unsigned long updateCounter; // size=0, offset=0
	unsigned char numSlots; // size=0, offset=4
	unsigned char updateMode; // size=0, offset=5
	short masterVolume; // size=0, offset=6
	struct AadMasterVolFader masterVolFader; // size=8, offset=8
	unsigned char sfxMasterVol; // size=0, offset=16
	unsigned char musicMasterVol; // size=0, offset=17
	unsigned short flags; // size=0, offset=18
	struct AadVolFader musicMasterVolFader; // size=8, offset=20
	struct _AadSequenceSlot (*sequenceSlots[8]); // size=32, offset=28
	struct AadSfxSlot sfxSlot; // size=392, offset=60
	struct AadSynthVoice synthVoice[24]; // size=672, offset=452
	char voiceStatus[24]; // size=24, offset=1124
	unsigned short voicePitchSave[24]; // size=48, offset=1148
	unsigned long voiceKeyOffRequest; // size=0, offset=1196
	unsigned long voiceKeyOnRequest; // size=0, offset=1200
	unsigned long voiceReverbRequest; // size=0, offset=1204
	struct AadSoundBankHdr (*dynamicSoundBankHdr[2]); // size=8, offset=1208
	struct AadProgramAtr (*dynamicProgramAtr[2]); // size=8, offset=1216
	struct AadToneAtr (*dynamicToneAtr[2]); // size=8, offset=1224
	unsigned long (*dynamicWaveAddr[2]); // size=8, offset=1232
	unsigned char (**dynamicSequenceAddressTbl[2]); // size=8, offset=1240
	unsigned long (*dynamicSequenceLabelOffsetTbl[2]); // size=8, offset=1248
	unsigned char dynamicBankStatus[2]; // size=2, offset=1256
	unsigned char (*dynamicSoundBankData[2]); // size=8, offset=1260
	unsigned long dynamicSoundBankSramData[2]; // size=8, offset=1268
	unsigned long dynamicSoundBankSramDataSize[2]; // size=8, offset=1276
	unsigned char dynamicSoundBankLoadOption[2]; // size=2, offset=1284
	struct AadDynamicLoadRequest loadRequestQueue[8]; // size=416, offset=1288
	struct AadDynamicBankLoadInfo dynamicBankLoadInfo; // size=28, offset=1704
	unsigned char *loadBufferAddress; // size=0, offset=1732
	unsigned long loadBufferSize; // size=0, offset=1736
	void (*nonBlockLoadProc)(); // size=0, offset=1740
	void (*nonBlockBufferedLoadProc)(); // size=0, offset=1744
	void (**memoryMallocProc)(); // size=0, offset=1748
	void (*memoryFreeProc)(); // size=0, offset=1752
	unsigned char memMallocType; // size=0, offset=1756
	unsigned char nextLoadReqIn; // size=0, offset=1757
	unsigned char nextLoadReqOut; // size=0, offset=1758
	unsigned char numLoadReqsQueued; // size=0, offset=1759
	struct AadDynamicSfxLoadInfo dynamicSfxLoadInfo; // size=140, offset=1760
	struct _AadDynSfxFileHdr *firstDynSfxFile; // size=20, offset=1900
	unsigned char sfxToneMasterList[512]; // size=512, offset=1904
	unsigned char sfxWaveMasterList[512]; // size=512, offset=2416
	struct AadLoadedSfxToneAttr sfxToneAttrTbl[128]; // size=2560, offset=2928
	struct AadLoadedSfxWaveAttr sfxWaveAttrTbl[120]; // size=480, offset=5488
	unsigned short nextToneIndex; // size=0, offset=5968
	unsigned short nextWaveIndex; // size=0, offset=5970
	struct AadNewSramBlockDesc sramDescriptorTbl[128]; // size=1024, offset=5972
	unsigned short nextSramDescIndex; // size=0, offset=6996
	unsigned char firstSramBlockDescIndex; // size=0, offset=6998
	unsigned char unused; // size=0, offset=6999
	unsigned short unused1; // size=0, offset=7000
	unsigned short nextFileHandle; // size=0, offset=7002
	void (*controller11Callback)(); // size=0, offset=7004
	void (*endSequenceCallback)(); // size=0, offset=7008
	long controller11CallbackData; // size=0, offset=7012
	long endSequenceCallbackData; // size=0, offset=7016
	unsigned char userVariables[128]; // size=128, offset=7020
};

struct AadSlotAttributes // hashcode: 0x0D6866B0 (dec: 224945840)
{
	unsigned short sequenceNumberAssigned; // size=0, offset=0
	unsigned short sequenceAssignedDynamicBank; // size=0, offset=2
	unsigned short playingStatus; // size=0, offset=4
	unsigned short channelMute; // size=0, offset=6
	unsigned char slotVolume; // size=0, offset=8
	unsigned char slotPan; // size=0, offset=9
	unsigned short eventsInQueue[16]; // size=32, offset=10
};

typedef struct AadMemoryStruct AadMemoryStruct;

typedef struct AadSlotAttributes AadSlotAttributes;

union TABLES_71fake // Hashcode: 0x351174B3 (dec: 890336435)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: tables.o, tables.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: tables.o, tables.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: tables.o, tables.o
};

union TABLES_72fake // Hashcode: 0x90F10426 (dec: -1863252954)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VM_71fake // Hashcode: 0x36796B2E (dec: 913926958)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: vm.o, vm.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: vm.o, vm.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: vm.o, vm.o
};

union VM_72fake // Hashcode: 0x56241E94 (dec: 1445207700)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct VM_109fake // hashcode: 0x714C8672 (dec: 1900840562)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: vm.o, vm.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: vm.o, vm.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: vm.o, vm.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: vm.o, vm.o
};

union VM_194fake // Hashcode: 0x7FC9D97F (dec: 2143934847)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct NewMemTracker // hashcode: 0x84C0F863 (dec: -2067728285)
{
	struct MemHeader *rootNode; // size=8, offset=0
	unsigned long totalMemory; // size=0, offset=4
	unsigned long currentMemoryUsed; // size=0, offset=8
	char *lastMemoryAddress; // size=0, offset=12
	long doingGarbageCollection; // size=0, offset=16
};

union MEMPACK_71fake // Hashcode: 0x29689957 (dec: 694720855)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: mempack.o, mempack.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: mempack.o, mempack.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: mempack.o, mempack.o
};

union MEMPACK_72fake // Hashcode: 0x22AE332E (dec: 581841710)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MEMPACK_183fake // Hashcode: 0x62744547 (dec: 1651787079)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MEMPACK_239fake // Hashcode: 0x0B864EA1 (dec: 193351329)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

typedef struct NewMemTracker NewMemTracker;

struct SpuVoiceAttr // hashcode: 0x4C2AB4B6 (dec: 1277867190)
{
	unsigned long voice; // size=0, offset=0
	unsigned long mask; // size=0, offset=4
	struct SpuVolume volume; // size=4, offset=8
	struct SpuVolume volmode; // size=4, offset=12
	struct SpuVolume volumex; // size=4, offset=16
	unsigned short pitch; // size=0, offset=20
	unsigned short note; // size=0, offset=22
	unsigned short sample_note; // size=0, offset=24
	short envx; // size=0, offset=26
	unsigned long addr; // size=0, offset=28
	unsigned long loop_addr; // size=0, offset=32
	long a_mode; // size=0, offset=36
	long s_mode; // size=0, offset=40
	long r_mode; // size=0, offset=44
	unsigned short ar; // size=0, offset=48
	unsigned short dr; // size=0, offset=50
	unsigned short sr; // size=0, offset=52
	unsigned short rr; // size=0, offset=54
	unsigned short sl; // size=0, offset=56
	unsigned short adsr1; // size=0, offset=58
	unsigned short adsr2; // size=0, offset=60
};

typedef struct SpuVoiceAttr SpuVoiceAttr;

struct POLY_G4 // hashcode: 0xC602E7AA (dec: -972888150)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char r1; // size=0, offset=12
	unsigned char g1; // size=0, offset=13
	unsigned char b1; // size=0, offset=14
	unsigned char pad1; // size=0, offset=15
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	unsigned char r2; // size=0, offset=20
	unsigned char g2; // size=0, offset=21
	unsigned char b2; // size=0, offset=22
	unsigned char pad2; // size=0, offset=23
	short x2; // size=0, offset=24
	short y2; // size=0, offset=26
	unsigned char r3; // size=0, offset=28
	unsigned char g3; // size=0, offset=29
	unsigned char b3; // size=0, offset=30
	unsigned char pad3; // size=0, offset=31
	short x3; // size=0, offset=32
	short y3; // size=0, offset=34
};

struct DR_AREA // hashcode: 0xC8AB7091 (dec: -928288623)
{
	unsigned long tag; // size=0, offset=0
	unsigned long code[2]; // size=8, offset=4
};

union STREAM_76fake // Hashcode: 0xB702DE8E (dec: -1224548722)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: stream.o, stream.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: stream.o, stream.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: stream.o, stream.o
};

union STREAM_77fake // Hashcode: 0x2D6B78C8 (dec: 762017992)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct evPositionData // hashcode: 0x8B586211 (dec: -1957141999)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

union STREAM_221fake // Hashcode: 0x22956C57 (dec: 580217943)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct STracker // hashcode: 0xBA6DA077 (dec: -1167220617)
{
	struct _StreamUnit StreamList[16]; // size=1024, offset=0
};

struct FaceExtents // hashcode: 0x81F54A5F (dec: -2114631073)
{
	long smallx; // size=0, offset=0
	long bigx; // size=0, offset=4
	long smally; // size=0, offset=8
	long bigy; // size=0, offset=12
	long smallz; // size=0, offset=16
	long bigz; // size=0, offset=20
};

struct WarpRoom // hashcode: 0xCE515662 (dec: -833530270)
{
	char name[16]; // size=16, offset=0
	struct _StreamUnit *streamUnit; // size=64, offset=16
};

struct PlanningNode // hashcode: 0xEA32DC84 (dec: -365765500)
{
	struct _Position pos; // size=6, offset=0
	unsigned short flags; // size=0, offset=6
	unsigned long connectionStatus; // size=0, offset=8
	unsigned long connections; // size=0, offset=12
	unsigned short cost; // size=0, offset=16
	unsigned short parent; // size=0, offset=18
	unsigned short nodeType; // size=0, offset=20
	unsigned short id; // size=0, offset=22
	long streamUnitID; // size=0, offset=24
};

union STREAM_256fake // Hashcode: 0xDF67A27D (dec: -546856323)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

struct VramBuffer // hashcode: 0xED8172BA (dec: -310283590)
{
	long flags; // size=0, offset=0
	short x; // size=0, offset=4
	short y; // size=0, offset=6
	short w; // size=0, offset=8
	short h; // size=0, offset=10
	short yOffset; // size=0, offset=12
	short lengthOfLeftOverData; // size=0, offset=14
	short *lineOverFlow; // size=0, offset=16
};

struct STREAM_288fake // hashcode: 0x2611F8B3 (dec: 638711987)
{
	short loading; // size=0, offset=0
	short fadeValue; // size=0, offset=2
	long curTime; // size=0, offset=4
	long maxTime; // size=0, offset=8
	struct _Instance *warpFaceInstance; // size=664, offset=12
};

typedef struct POLY_G4 POLY_G4;

typedef struct DR_AREA DR_AREA;

typedef struct evPositionData evPositionData;

typedef struct STracker STracker;

typedef struct FaceExtents FaceExtents;

typedef struct WarpRoom WarpRoom;

typedef struct PlanningNode PlanningNode;

typedef struct VramBuffer VramBuffer;

union PHYSOBS_71fake // Hashcode: 0x26E4FB7A (dec: 652540794)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: PhysObs.o, PhysObs.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: PhysObs.o, PhysObs.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: PhysObs.o, PhysObs.o
};

union PHYSOBS_72fake // Hashcode: 0x25E00833 (dec: 635439155)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PHYSOBS_109fake // hashcode: 0xEE95CCE3 (dec: -292172573)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: PhysObs.o, PhysObs.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: PhysObs.o, PhysObs.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: PhysObs.o, PhysObs.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: PhysObs.o, PhysObs.o
};

struct evObjectData // hashcode: 0x4F0DD970 (dec: 1326307696)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short PathNumber; // size=0, offset=4
	short LinkNode; // size=0, offset=6
	struct _Instance *Force; // size=664, offset=8
	int rc; // size=0, offset=12
};

struct evPhysicsSlideData // hashcode: 0xDB552464 (dec: -615177116)
{
	struct _SVector ForwardVector; // size=8, offset=0
	struct _SVector ForwardNormal; // size=8, offset=8
	struct _SVector DropNormal; // size=8, offset=16
	short Segment; // size=0, offset=24
	short DropOffset; // size=0, offset=26
	short UpperOffset; // size=0, offset=28
	short Height; // size=0, offset=30
	struct _Instance *UpperInstance; // size=664, offset=32
	int Dot; // size=0, offset=36
};

struct evObjectThrowData // hashcode: 0x24DB0DBC (dec: 618335676)
{
	short type; // size=0, offset=0
	short spinType; // size=0, offset=2
	union {
		struct _Instance *target; // size=664, offset=0
		struct _Position position; // size=6, offset=0
		struct _Rotation direction; // size=8, offset=0
		struct _Position throwVector; // size=6, offset=0
	} data; // size=8, offset=4, found in object files: PhysObs.o, PhysObs.o
	struct _SVector angularVel; // size=8, offset=12
	unsigned short speed; // size=0, offset=20
	short gravity; // size=0, offset=22
	short initialXRot; // size=0, offset=24
	short zVel; // size=0, offset=26
};

struct evObjectBirthProjectileData // hashcode: 0xD0E2D162 (dec: -790441630)
{
	struct _Instance *instance; // size=664, offset=0
	int joint; // size=0, offset=4
	int type; // size=0, offset=8
	struct _Instance *birthInstance; // size=664, offset=12
};

struct PhysObWeaponProperties // hashcode: 0xB082F6F5 (dec: -1333594379)
{
	struct PhysObProperties Properties; // size=8, offset=0
	struct PhysObWeaponAttributes WeaponAttributes; // size=28, offset=8
};

struct PhysObInteractProperties // hashcode: 0xA5543975 (dec: -1521206923)
{
	struct PhysObProperties Properties; // size=8, offset=0
	unsigned short conditions; // size=0, offset=8
	unsigned short auxConditions; // size=0, offset=10
	unsigned short action; // size=0, offset=12
	unsigned short auxAction; // size=0, offset=14
	unsigned char startAnim; // size=0, offset=16
	unsigned char endAnim; // size=0, offset=17
	unsigned char razielAnim; // size=0, offset=18
	unsigned char razielAuxAnim; // size=0, offset=19
	unsigned char frame; // size=0, offset=20
	unsigned char startAnimMode; // size=0, offset=21
	unsigned short distance; // size=0, offset=22
	unsigned short newType; // size=0, offset=24
	unsigned short newClass; // size=0, offset=26
	unsigned short mode; // size=0, offset=28
	unsigned short engageXYDistance; // size=0, offset=30
	short engageZMinDelta; // size=0, offset=32
	short engageZMaxDelta; // size=0, offset=34
	unsigned char engageYCone; // size=0, offset=36
	unsigned char engageZCone; // size=0, offset=37
	unsigned short pad; // size=0, offset=38
	struct PhysObWeaponAttributes *weapon; // size=28, offset=40
};

struct __PhysObProjectileProperties // hashcode: 0xB1F990D3 (dec: -1309044525)
{
	struct PhysObProperties Properties; // size=8, offset=0
	long totalProjectiles; // size=0, offset=8
	struct __PhysObProjectileData *data; // size=12, offset=12
};

struct PhysObDraftProperties // hashcode: 0x94602C47 (dec: -1805636537)
{
	struct PhysObProperties Properties; // size=8, offset=0
	short force; // size=0, offset=8
	unsigned short radius; // size=0, offset=10
	unsigned short radiusCoef; // size=0, offset=12
	short maxVelocity; // size=0, offset=14
	unsigned long height; // size=0, offset=16
};

struct PhysObSwitchProperties // hashcode: 0x65265E7B (dec: 1697013371)
{
	struct PhysObProperties Properties; // size=8, offset=0
	short Distance; // size=0, offset=8
	short Class; // size=0, offset=10
	unsigned char onAnim; // size=0, offset=12
	unsigned char offAnim; // size=0, offset=13
	unsigned char failedOnAnim; // size=0, offset=14
	unsigned char enableAnim; // size=0, offset=15
	unsigned char shutAnim; // size=0, offset=16
	unsigned char onWalkTimer; // size=0, offset=17
	unsigned char offWalkTimer; // size=0, offset=18
	unsigned char walkMode; // size=0, offset=19
	unsigned char razielOnAnim; // size=0, offset=20
	unsigned char razielOffAnim; // size=0, offset=21
	unsigned char razielFailedOnAnim; // size=0, offset=22
	unsigned char razielEnableAnim; // size=0, offset=23
	unsigned char startMode; // size=0, offset=24
	unsigned char startAnim; // size=0, offset=25
	unsigned short engageXYDistance; // size=0, offset=26
	char engageZMinDelta; // size=0, offset=28
	char engageZMaxDelta; // size=0, offset=29
	unsigned char engageYCone; // size=0, offset=30
	unsigned char engageZCone; // size=0, offset=31
};

struct PhysObCollectibleProperties // hashcode: 0x173595BD (dec: 389387709)
{
	struct PhysObProperties Properties; // size=8, offset=0
	short collectClass; // size=0, offset=8
	short collectValue; // size=0, offset=10
	unsigned long distance; // size=0, offset=12
	unsigned char idleAnim; // size=0, offset=16
	unsigned char collectAnim; // size=0, offset=17
	unsigned short spatialNode; // size=0, offset=18
};

struct PhysObAnimatedProperties // hashcode: 0x9BAE907D (dec: -1683058563)
{
	struct PhysObProperties Properties; // size=8, offset=0
	unsigned short flags; // size=0, offset=8
	unsigned short pad; // size=0, offset=10
};

struct PhysObData // hashcode: 0x0D644D12 (dec: 224677138)
{
	long Mode; // size=0, offset=0
	short xForce; // size=0, offset=4
	short yForce; // size=0, offset=6
	struct _Instance *Force; // size=664, offset=8
	short LinkNode; // size=0, offset=12
	short px; // size=0, offset=14
	short py; // size=0, offset=16
	short pz; // size=0, offset=18
	short rx1; // size=0, offset=20
	short ry1; // size=0, offset=22
	short rz1; // size=0, offset=24
	short Segment1; // size=0, offset=26
	short rx2; // size=0, offset=28
	short ry2; // size=0, offset=30
	short rz2; // size=0, offset=32
	short Segment2; // size=0, offset=34
	short Steps; // size=0, offset=36
	short Step; // size=0, offset=38
	short PathNumber; // size=0, offset=40
	short Pad1; // size=0, offset=42
	struct _HInfo *RightCollision; // size=24, offset=44
	struct _HInfo *LeftCollision; // size=24, offset=48
	short burnAmpl; // size=0, offset=52
	short throwFlags; // size=0, offset=54
	short initialXRot; // size=0, offset=56
	short xRotVel; // size=0, offset=58
	short yRotVel; // size=0, offset=60
	short zRotVel; // size=0, offset=62
	struct _Instance *throwingInstance; // size=664, offset=64
	int physObTimer; // size=0, offset=68
};

struct SwitchData // hashcode: 0xEC701AED (dec: -328197395)
{
	short state; // size=0, offset=0
	short accumulator; // size=0, offset=2
};

struct BreakOffData // hashcode: 0x38A19561 (dec: 950113633)
{
	short NewType; // size=0, offset=0
	short NewClass; // size=0, offset=2
};

struct ProjectileData // hashcode: 0x9DC04551 (dec: -1648343727)
{
	int Type; // size=0, offset=0
};

typedef struct evObjectData evObjectData;

typedef struct evPhysicsSlideData evPhysicsSlideData;

typedef struct evObjectThrowData evObjectThrowData;

typedef struct evObjectBirthProjectileData evObjectBirthProjectileData;

typedef struct PhysObWeaponProperties PhysObWeaponProperties;

typedef struct PhysObInteractProperties PhysObInteractProperties;

typedef struct __PhysObProjectileProperties PhysObProjectileProperties;

typedef struct PhysObDraftProperties PhysObDraftProperties;

typedef struct PhysObSwitchProperties PhysObSwitchProperties;

typedef struct PhysObCollectibleProperties PhysObCollectibleProperties;

typedef struct PhysObAnimatedProperties PhysObAnimatedProperties;

typedef struct PhysObData PhysObData;

typedef struct SwitchData SwitchData;

typedef struct BreakOffData BreakOffData;

typedef struct ProjectileData ProjectileData;

union EVENT_76fake // Hashcode: 0xB053DF44 (dec: -1336680636)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: event.o, event.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: event.o, event.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: event.o, event.o
};

union EVENT_77fake // Hashcode: 0xE5DBF00B (dec: -438570997)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct WaterLevelProcess // hashcode: 0x87B8A7A6 (dec: -2017941594)
{
	long flags; // size=0, offset=0
	struct BSPTree *bspTree; // size=36, offset=4
	struct _StreamUnit *streamUnit; // size=0, offset=8
	short oldWaterZ; // size=0, offset=12
	short oldGlobalOffset; // size=0, offset=14
	short zValueFrom; // size=0, offset=16
	short zValueTo; // size=0, offset=18
	long maxSteps; // size=0, offset=20
	long curStep; // size=0, offset=24
};

struct EventInstanceObject // hashcode: 0xF9BF7B16 (dec: -104891626)
{
	short id; // size=0, offset=0
	short flags; // size=0, offset=2
	long unitID; // size=0, offset=4
	long introUniqueID; // size=0, offset=8
	struct _Instance *instance; // size=664, offset=12
	union {
		struct Intro *intro; // size=76, offset=0
		struct _SFXMkr *sfxMarker; // size=36, offset=0
	} data; // size=4, offset=16, found in object files: event.o, event.o
};

struct EventEventObject // hashcode: 0x99F832F3 (dec: -1711787277)
{
	short id; // size=0, offset=0
	short eventNumber; // size=0, offset=2
	long unitID; // size=0, offset=4
	struct Event *event; // size=0, offset=8
};

struct EventTGroupObject // hashcode: 0xDE337D53 (dec: -567050925)
{
	short id; // size=0, offset=0
	short tgroupNumber; // size=0, offset=2
	long unitID; // size=0, offset=4
	struct BSPTree *bspTree; // size=36, offset=8
	struct _StreamUnit *stream; // size=0, offset=12
};

struct _PCodeStack // hashcode: 0xCDC22647 (dec: -842914233)
{
	long topOfStack; // size=0, offset=0
	struct StackType stack[32]; // size=1152, offset=4
};

union EVENT_212fake // Hashcode: 0x92F57DD9 (dec: -1829405223)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct EventTimer // hashcode: 0x6428D219 (dec: 1680396825)
{
	long flags; // size=1, offset=0
	long time; // size=31, offset=1
	struct Event *event; // size=28, offset=4
	struct ScriptPCode *actionScript; // size=8, offset=8
	short *scriptPos; // size=0, offset=12
	struct Level *level; // size=392, offset=16
	long nextEventIndex; // size=0, offset=20
};

struct HintSystemStruct // hashcode: 0x6396612B (dec: 1670799659)
{
	short flags; // size=0, offset=0
	short hintNumber; // size=0, offset=2
	short stringNumber; // size=0, offset=4
	long fadeTimer; // size=0, offset=8
	long spawningUnitID; // size=0, offset=12
};

typedef struct WaterLevelProcess WaterLevelProcess;

typedef struct EventInstanceObject EventInstanceObject;

typedef struct EventEventObject EventEventObject;

typedef struct EventTGroupObject EventTGroupObject;

typedef struct _PCodeStack PCodeStack;

typedef struct EventTimer EventTimer;

typedef struct HintSystemStruct HintSystemStruct;

union STRMLOAD_76fake // Hashcode: 0x13BBDD6D (dec: 331079021)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: strmload.o, strmload.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: strmload.o, strmload.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: strmload.o, strmload.o
};

union STRMLOAD_77fake // Hashcode: 0xF5325EE9 (dec: -181248279)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct STRMLOAD_116fake // hashcode: 0x64E8AA3B (dec: 1692969531)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: strmload.o, strmload.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: strmload.o, strmload.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: strmload.o, strmload.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: strmload.o, strmload.o
};

union SCRIPT2_71fake // Hashcode: 0x2642ED76 (dec: 641920374)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: script2.o, script2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: script2.o, script2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: script2.o, script2.o
};

union SCRIPT2_72fake // Hashcode: 0x3F4B8BC6 (dec: 1061915590)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct SCRIPT2_114fake // hashcode: 0x94366133 (dec: -1808375501)
{
	struct {
		struct MultiSpline *posSpline; // size=80, offset=0
		struct MultiSpline *targetSpline; // size=80, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: script2.o, script2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: script2.o, script2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: script2.o, script2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: script2.o, script2.o
};

union SCRIPT2_198fake // Hashcode: 0xDAF43D61 (dec: -621527711)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct LitShaftProperties // hashcode: 0xABEDB0DC (dec: -1410486052)
{
	short fadeValue; // size=0, offset=0
	short pad; // size=0, offset=2
};

typedef struct LitShaftProperties LitShaftProperties;

union PHYSICS_71fake // Hashcode: 0xCF90567A (dec: -812624262)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: physics.o, physics.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: physics.o, physics.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: physics.o, physics.o
};

union PHYSICS_72fake // Hashcode: 0x7825FF45 (dec: 2015756101)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PHYSICS_109fake // hashcode: 0x5DACEA60 (dec: 1571613280)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: physics.o, physics.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: physics.o, physics.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: physics.o, physics.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: physics.o, physics.o
};

struct evPhysicsGravityData // hashcode: 0xFD3A4285 (dec: -46513531)
{
	short UpperOffset; // size=0, offset=0
	short LowerOffset; // size=0, offset=2
	short x; // size=0, offset=4
	short y; // size=0, offset=6
	short z; // size=0, offset=8
	short slipSlope; // size=0, offset=10
};

struct evPhysicsDropOffData // hashcode: 0x85B95E3E (dec: -2051449282)
{
	short xOffset; // size=0, offset=0
	short yOffset; // size=0, offset=2
	short DropOffset; // size=0, offset=4
	short slipSlope; // size=0, offset=6
};

struct evPhysicsEdgeData // hashcode: 0x09C258F2 (dec: 163731698)
{
	short UpperOffset; // size=0, offset=0
	short ForwardOffset; // size=0, offset=2
	short AboveOffset; // size=0, offset=4
	short XDistance; // size=0, offset=6
	short YDistance; // size=0, offset=8
	short ZDistance; // size=0, offset=10
	struct _SVector *Normal1; // size=8, offset=12
	struct _SVector *Normal2; // size=8, offset=16
	struct _SVector *Delta; // size=8, offset=20
	struct _Instance *instance; // size=664, offset=24
	int zRot; // size=0, offset=28
	int rc; // size=0, offset=32
};

struct evPhysicsWallCrawlData // hashcode: 0xB2FCB4EA (dec: -1292061462)
{
	short Segment; // size=0, offset=0
	short Length; // size=0, offset=2
	short ForwardOffset; // size=0, offset=4
	short NormalDistance; // size=0, offset=6
	struct _SVector DropNormal; // size=8, offset=8
	struct _SVector ForwardNormal; // size=8, offset=16
	struct _Position NewPosition; // size=6, offset=24
	struct _Rotation DropRotation; // size=8, offset=30
	short ForwardXRotation; // size=0, offset=38
	int rc; // size=0, offset=40
};

struct evPhysicsSwimData // hashcode: 0xCE6688EE (dec: -832141074)
{
	short CheckDepth; // size=0, offset=0
	short SwimDepth; // size=0, offset=2
	short WadeDepth; // size=0, offset=4
	short TreadDepth; // size=0, offset=6
	struct _SVector *iVelocity; // size=8, offset=8
	short Depth; // size=0, offset=12
	short WaterDepth; // size=0, offset=14
	short rc; // size=0, offset=16
	short pad; // size=0, offset=18
	int WaterLevel; // size=0, offset=20
};

struct evPhysicsDropHeightData // hashcode: 0x1C82CF3E (dec: 478334782)
{
	struct _Position origin; // size=6, offset=0
	short mode; // size=0, offset=6
	short DropOffset; // size=0, offset=8
	short result; // size=0, offset=10
	struct BSPTree *bsp; // size=36, offset=12
	struct _TFace *tface; // size=12, offset=16
};

struct evPhysicsLinkedMoveData // hashcode: 0x5A2EDF33 (dec: 1513021235)
{
	struct _Instance *instance; // size=664, offset=0
	int segment; // size=0, offset=4
	struct _SVector posDelta; // size=8, offset=8
	struct _SVector rotDelta; // size=8, offset=16
};

union PHYSICS_198fake // Hashcode: 0xA42560D1 (dec: -1541054255)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct evPhysicsGravityData evPhysicsGravityData;

typedef struct evPhysicsDropOffData evPhysicsDropOffData;

typedef struct evPhysicsEdgeData evPhysicsEdgeData;

typedef struct evPhysicsWallCrawlData evPhysicsWallCrawlData;

typedef struct evPhysicsSwimData evPhysicsSwimData;

typedef struct evPhysicsDropHeightData evPhysicsDropHeightData;

typedef struct evPhysicsLinkedMoveData evPhysicsLinkedMoveData;

union RAZCNTRL_71fake // Hashcode: 0xE6DC196F (dec: -421783185)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: razcntrl.o, razcntrl.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: razcntrl.o, razcntrl.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: razcntrl.o, razcntrl.o
};

union RAZCNTRL_72fake // Hashcode: 0x4C8A59A2 (dec: 1284135330)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct RAZCNTRL_109fake // hashcode: 0xFD097EFC (dec: -49709316)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: razcntrl.o, razcntrl.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: razcntrl.o, razcntrl.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: razcntrl.o, razcntrl.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: razcntrl.o, razcntrl.o
};

union STATE_71fake // Hashcode: 0xF000B97C (dec: -268387972)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: state.o, state.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: state.o, state.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: state.o, state.o
};

union STATE_72fake // Hashcode: 0x08AB5737 (dec: 145446711)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct STATE_109fake // hashcode: 0xBCEFCE7D (dec: -1125134723)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: state.o, state.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: state.o, state.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: state.o, state.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: state.o, state.o
};

struct __CharacterState // hashcode: 0x765BDE09 (dec: 1985732105)
{
	struct _Instance *CharacterInstance; // size=664, offset=0
	int TotalSections; // size=0, offset=4
	struct __State SectionList[3]; // size=852, offset=8
};

struct evMonsterHitData // hashcode: 0xA70C5467 (dec: -1492364185)
{
	struct _Instance *sender; // size=664, offset=0
	struct _Instance *lastHit; // size=664, offset=4
	short knockBackDistance; // size=0, offset=8
	short knockBackDuration; // size=0, offset=10
	long power; // size=0, offset=12
};

struct evMonsterThrownData // hashcode: 0x902A9E9A (dec: -1876255078)
{
	struct _Instance *sender; // size=664, offset=0
	struct _Rotation direction; // size=8, offset=4
	short power; // size=0, offset=12
};

struct evMonsterAlarmData // hashcode: 0xDEB0B984 (dec: -558843516)
{
	struct _Instance *sender; // size=664, offset=0
	struct _Position position; // size=6, offset=4
	short type; // size=0, offset=10
};

struct evMonsterSoulSuckData // hashcode: 0x522C2FD4 (dec: 1378627540)
{
	struct _Instance *sender; // size=664, offset=0
	struct _Position Destination; // size=6, offset=4
};

struct evFXHitData // hashcode: 0xD39E05E9 (dec: -744618519)
{
	struct _SVector location; // size=8, offset=0
	struct _SVector velocity; // size=8, offset=8
	short amount; // size=0, offset=16
	short type; // size=0, offset=18
};

struct evAnimationControllerDoneData // hashcode: 0xC039DD39 (dec: -1069949639)
{
	struct _Instance *instance; // size=664, offset=0
	long segment; // size=0, offset=4
	long type; // size=0, offset=8
	int data; // size=0, offset=12
};

struct evMonsterImpaleData // hashcode: 0x5F304C39 (dec: 1597000761)
{
	struct _Instance *weapon; // size=664, offset=0
	struct _Rotation direction; // size=8, offset=4
	struct _Position position; // size=6, offset=12
	short distance; // size=0, offset=18
};

struct evObjectBreakOffData // hashcode: 0x8FBEEADA (dec: -1883313446)
{
	struct _Instance *force; // size=664, offset=0
	unsigned short node; // size=0, offset=4
	short distance; // size=0, offset=6
	unsigned short animation; // size=0, offset=8
	unsigned short frame; // size=0, offset=10
	unsigned short type; // size=0, offset=12
	unsigned short action; // size=0, offset=14
};

struct evObjectAbsorbData // hashcode: 0x05BCBE59 (dec: 96255577)
{
	struct _Instance *force; // size=664, offset=0
	unsigned short node; // size=0, offset=4
	unsigned short steps; // size=0, offset=6
};

struct evObjectIdleData // hashcode: 0x8FA2B908 (dec: -1885161208)
{
	long mode; // size=0, offset=0
	struct _Instance *instance; // size=664, offset=4
};

struct evControlInitHangData // hashcode: 0x314E13CA (dec: 827200458)
{
	struct _Instance *instance; // size=664, offset=0
	int frame; // size=0, offset=4
	int frames; // size=0, offset=8
};

struct evControlInitIdleData // hashcode: 0x9436AF5A (dec: -1808355494)
{
	int mode; // size=0, offset=0
	int frame; // size=0, offset=4
	int frames; // size=0, offset=8
};

struct evActionLookAroundData // hashcode: 0x9293C9EB (dec: -1835808277)
{
	short *rotx; // size=0, offset=0
	short *rotz; // size=0, offset=4
	short minx; // size=0, offset=8
	short maxx; // size=0, offset=10
	short minz; // size=0, offset=12
	short maxz; // size=0, offset=14
};

struct evActionPlayHostAnimationData // hashcode: 0xC5EC5248 (dec: -974368184)
{
	struct _Instance *instance; // size=664, offset=0
	struct _Instance *host; // size=664, offset=4
	int newAnim; // size=0, offset=8
	int newFrame; // size=0, offset=12
	int frames; // size=0, offset=16
	int mode; // size=0, offset=20
};

struct evShadowSegmentData // hashcode: 0x223B434B (dec: 574309195)
{
	unsigned long totalShadowSegments; // size=0, offset=0
	unsigned short shadowSegments[4]; // size=8, offset=4
};

typedef struct __CharacterState CharacterState;

typedef struct evMonsterHitData evMonsterHitData;

typedef struct evMonsterThrownData evMonsterThrownData;

typedef struct evMonsterAlarmData evMonsterAlarmData;

typedef struct evMonsterSoulSuckData evMonsterSoulSuckData;

typedef struct evFXHitData evFXHitData;

typedef struct evAnimationControllerDoneData evAnimationControllerDoneData;

typedef struct evMonsterImpaleData evMonsterImpaleData;

typedef struct evObjectBreakOffData evObjectBreakOffData;

typedef struct evObjectAbsorbData evObjectAbsorbData;

typedef struct evObjectIdleData evObjectIdleData;

typedef struct evControlInitHangData evControlInitHangData;

typedef struct evControlInitIdleData evControlInitIdleData;

typedef struct evActionLookAroundData evActionLookAroundData;

typedef struct evActionPlayHostAnimationData evActionPlayHostAnimationData;

typedef struct evShadowSegmentData evShadowSegmentData;

union VRAM_76fake // Hashcode: 0xE489D06B (dec: -460730261)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: vram.o, vram.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: vram.o, vram.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: vram.o, vram.o
};

union VRAM_77fake // Hashcode: 0xFBFBBE2E (dec: -67387858)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct VRAM_114fake // hashcode: 0x4E7C0E6B (dec: 1316753003)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: vram.o, vram.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: vram.o, vram.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: vram.o, vram.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: vram.o, vram.o
};

union VRAM_221fake // Hashcode: 0xEEB06D44 (dec: -290427580)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MONMSG_76fake // Hashcode: 0x8637AC3E (dec: -2043171778)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monmsg.o, monmsg.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monmsg.o, monmsg.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monmsg.o, monmsg.o
};

union MONMSG_77fake // Hashcode: 0x757C35DB (dec: 1971074523)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MONMSG_114fake // hashcode: 0x592BAF87 (dec: 1496035207)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monmsg.o, monmsg.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monmsg.o, monmsg.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monmsg.o, monmsg.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monmsg.o, monmsg.o
};

union MONMSG_191fake // Hashcode: 0xD3DC89E2 (dec: -740521502)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _MonsterAnim // hashcode: 0x0634BB96 (dec: 104119190)
{
	unsigned short velocity; // size=0, offset=0
	unsigned short distance; // size=0, offset=2
	unsigned short playSpeed; // size=0, offset=4
	unsigned char interpFrames; // size=0, offset=6
	unsigned char startFrame; // size=0, offset=7
	unsigned char interpOut; // size=0, offset=8
	unsigned char alphaTable; // size=0, offset=9
	unsigned char alphaTableOut; // size=0, offset=10
	unsigned char controllingSection; // size=0, offset=11
	char index[3]; // size=3, offset=12
	char pad; // size=0, offset=15
};

struct _MonsterIdle // hashcode: 0xA90F0257 (dec: -1458634153)
{
	char anim; // size=0, offset=0
	char alertMod; // size=0, offset=1
	char probability; // size=0, offset=2
	char pad; // size=0, offset=3
};

struct _MonsterBehavior // hashcode: 0xD5258491 (dec: -718961519)
{
	char alertness; // size=0, offset=0
	char idleFreq; // size=0, offset=1
	char numIdles; // size=0, offset=2
	char idleList[5]; // size=5, offset=3
};

struct _MonsterSenses // hashcode: 0xAFC3C0D7 (dec: -1346125609)
{
	short sightArc; // size=0, offset=0
	short sightRadius; // size=0, offset=2
	short sightElevation; // size=0, offset=4
	short soundArc; // size=0, offset=6
	short soundRadius; // size=0, offset=8
	short soundElevation; // size=0, offset=10
	unsigned short scentRadius; // size=0, offset=12
	short alarmRadius; // size=0, offset=14
	unsigned short allyRadius; // size=0, offset=16
};

struct _MonsterAllegiances // hashcode: 0xBE9F67ED (dec: -1096849427)
{
	unsigned long enemies; // size=0, offset=0
	unsigned long allies; // size=0, offset=4
	unsigned long food; // size=0, offset=8
	unsigned long gods; // size=0, offset=12
};

struct _MonsterAttackAttributes // hashcode: 0xBA522505 (dec: -1169021691)
{
	short attackRange; // size=0, offset=0
	short attackHeight; // size=0, offset=2
	short knockBackDistance; // size=0, offset=4
	char knockBackDuration; // size=0, offset=6
	char damage; // size=0, offset=7
	char sphereSegment; // size=0, offset=8
	char sphereOnFrame; // size=0, offset=9
	char sphereOnAnim; // size=0, offset=10
	char sphereOffFrame; // size=0, offset=11
	char sphereOffAnim; // size=0, offset=12
	char turnFrames; // size=0, offset=13
	char numAnims; // size=0, offset=14
	char attackProbability[12]; // size=12, offset=15
	char animList[5]; // size=5, offset=27
};

struct _MonsterMissile // hashcode: 0x51F61C82 (dec: 1375083650)
{
	unsigned short speed; // size=0, offset=0
	unsigned short range; // size=0, offset=2
	unsigned char frame; // size=0, offset=4
	unsigned char anim; // size=0, offset=5
	unsigned char segment; // size=0, offset=6
	unsigned char damage; // size=0, offset=7
	unsigned char type; // size=0, offset=8
	unsigned char graphic; // size=0, offset=9
	char gravity; // size=0, offset=10
	char reload; // size=0, offset=11
	char fireChance; // size=0, offset=12
	unsigned char numAnims; // size=0, offset=13
	char animList[2]; // size=2, offset=14
};

struct _MonsterCombatAttributes // hashcode: 0x93C3BF22 (dec: -1815888094)
{
	short stunTime; // size=0, offset=0
	short damageTime; // size=0, offset=2
	short recovery; // size=0, offset=4
	short surpriseTime; // size=0, offset=6
	short grabTime; // size=0, offset=8
	short combatRange; // size=0, offset=10
	short surpriseRange; // size=0, offset=12
	short allyRange; // size=0, offset=14
	short enemyAttackRange; // size=0, offset=16
	short suckPower; // size=0, offset=18
	short suckRange; // size=0, offset=20
	char hitPoints; // size=0, offset=22
	char numAttacks; // size=0, offset=23
	char missileAttack; // size=0, offset=24
	char ambushAttack; // size=0, offset=25
	char evadeProbability[12]; // size=12, offset=26
	char attackList[1]; // size=1, offset=38
};

struct _MonsterSubAttributes // hashcode: 0x903F2950 (dec: -1874908848)
{
	char *animList; // size=0, offset=0
	struct _MonsterSenses *senses; // size=18, offset=4
	struct _MonsterCombatAttributes *combatAttributes; // size=40, offset=8
	struct _MonsterAllegiances *allegiances; // size=16, offset=12
	char *behaviorList; // size=0, offset=16
	short scale; // size=0, offset=20
	short fallDistance; // size=0, offset=22
	short defAmbushRange; // size=0, offset=24
	short fleeRange; // size=0, offset=26
	short speedPivotTurn; // size=0, offset=28
	short speedWalkTurn; // size=0, offset=30
	short speedRunTurn; // size=0, offset=32
	short speedFleeTurn; // size=0, offset=34
	short forgetTime; // size=0, offset=36
	unsigned char modelNum; // size=0, offset=38
	unsigned char physAbility; // size=0, offset=39
	unsigned char stunnable; // size=0, offset=40
	unsigned char grabable; // size=0, offset=41
	unsigned char numSections; // size=0, offset=42
	unsigned char sectionEnd[3]; // size=3, offset=43
	short defPlayerAttitude; // size=0, offset=46
	short defWanderRange; // size=0, offset=48
	short defGuardRange; // size=0, offset=50
	unsigned char defInitialBehavior; // size=0, offset=52
	unsigned char defTriggeredBehavior; // size=0, offset=53
	char defActiveBehavior; // size=0, offset=54
	unsigned char defSpectral; // size=0, offset=55
	unsigned char sunVuln; // size=0, offset=56
	unsigned char fireVuln; // size=0, offset=57
	unsigned char waterVuln; // size=0, offset=58
	unsigned char impaleVuln; // size=0, offset=59
	unsigned char soundVuln; // size=0, offset=60
	unsigned char weaponVuln; // size=0, offset=61
	unsigned char missileVuln; // size=0, offset=62
	short minSpikeRange; // size=0, offset=64
	short maxSpikeRange; // size=0, offset=66
	short maxSpikeAngle; // size=0, offset=68
	short minSpikeHorzSpeed; // size=0, offset=70
	short maxSpikeHorzSpeed; // size=0, offset=72
	short maxSpikeVertSpeed; // size=0, offset=74
	short upOnGroundOffset; // size=0, offset=76
	short downOnGroundOffset; // size=0, offset=78
};

struct _MonsterVars // hashcode: 0xE3366FA4 (dec: -482971740)
{
	unsigned long mvFlags; // size=0, offset=0
	unsigned long auxFlags; // size=0, offset=4
	struct __MessageQueue messageQueue; // size=136, offset=8
	struct _MonsterIR *monsterIRList; // size=0, offset=144
	struct _G2AnimInterpInfo_Type interpInfo[3]; // size=36, offset=148
	struct _MonsterAttackAttributes *attackType; // size=32, offset=184
	struct _MonsterAnim *anim; // size=16, offset=188
	void *messageData; // size=0, offset=192
	struct _MonsterIR *enemy; // size=0, offset=196
	struct _MonsterIR *leader; // size=0, offset=200
	struct _MonsterIR *ally; // size=0, offset=204
	struct _Instance *held; // size=664, offset=208
	long heldID; // size=0, offset=212
	long soulID; // size=0, offset=216
	void *effect; // size=0, offset=220
	unsigned long radarMap; // size=0, offset=224
	unsigned long radarCounter; // size=0, offset=228
	short radarDistance[16]; // size=32, offset=232
	unsigned long mode; // size=0, offset=264
	unsigned long damageTimer; // size=0, offset=268
	unsigned long stunTimer; // size=0, offset=272
	unsigned long generalTimer; // size=0, offset=276
	unsigned long effectTimer; // size=0, offset=280
	struct _Position *lookAtPos; // size=6, offset=284
	struct _Position destination; // size=6, offset=288
	short speed; // size=0, offset=294
	struct _Position lastValidPos; // size=6, offset=296
	struct _Position lookAtPosData; // size=6, offset=302
	short fleeMarker; // size=0, offset=308
	short wanderRange; // size=0, offset=310
	short guardRange; // size=0, offset=312
	short ambushRange; // size=0, offset=314
	short ambushArc; // size=0, offset=316
	short ambushElevation; // size=0, offset=318
	short hitPoints; // size=0, offset=320
	short maxHitPoints; // size=0, offset=322
	short soulJuice; // size=0, offset=324
	short regenTime; // size=0, offset=326
	short mainColorVertex; // size=0, offset=328
	short lookAngleX; // size=0, offset=330
	short lookAngleZ; // size=0, offset=332
	unsigned short avoidMask; // size=0, offset=334
	unsigned short damageType; // size=0, offset=336
	char ambushMarker; // size=0, offset=338
	char ambushJumpType; // size=0, offset=339
	unsigned char causeOfDeath; // size=0, offset=340
	char previousMainState; // size=0, offset=341
	unsigned char behaviorState; // size=0, offset=342
	unsigned char initialBehavior; // size=0, offset=343
	unsigned char triggeredBehavior; // size=0, offset=344
	char activeBehavior; // size=0, offset=345
	unsigned char age; // size=0, offset=346
	char attackState; // size=0, offset=347
	unsigned char ambient; // size=0, offset=348
	char alertness; // size=0, offset=349
	char alertCount; // size=0, offset=350
	char senseIndex; // size=0, offset=351
	char lastSideMove; // size=0, offset=352
	char chance; // size=0, offset=353
	char pathSlotID; // size=0, offset=354
	struct _MonsterSubAttributes *subAttr; // size=80, offset=356
	struct _MonsterIR *freeIRs; // size=0, offset=360
	void *extraVars; // size=0, offset=364
	short validUnits[10]; // size=20, offset=368
	short patrolMarkers[12]; // size=24, offset=388
	short *currentMarker; // size=0, offset=412
	long terrainImpaleID; // size=0, offset=416
	short targetFade; // size=0, offset=420
	short fadeRate; // size=0, offset=422
};

struct _MonsterIR // hashcode: 0x9BD91DB3 (dec: -1680269901)
{
	struct _MonsterIR *next; // size=36, offset=0
	struct _Instance *instance; // size=664, offset=4
	long handle; // size=0, offset=8
	struct _SVector relativePosition; // size=8, offset=12
	short distance; // size=0, offset=20
	unsigned short mirFlags; // size=0, offset=22
	unsigned short mirConditions; // size=0, offset=24
	unsigned long forgetTimer; // size=0, offset=28
	unsigned long idleTime; // size=0, offset=32
};

struct burntTuneType // hashcode: 0x67AAA348 (dec: 1739236168)
{
	int burntDist; // size=0, offset=0
	int fadeDelta; // size=0, offset=4
};

struct _MonsterState // hashcode: 0x23738AC4 (dec: 594774724)
{
	void (*entryFunction)(); // size=0, offset=0
	void (*stateFunction)(); // size=0, offset=4
};

struct _MonsterStateChoice // hashcode: 0x0841A8E9 (dec: 138520809)
{
	int state; // size=0, offset=0
	struct _MonsterState functions; // size=8, offset=4
};

typedef struct _MonsterAnim MonsterAnim;

typedef struct _MonsterIdle MonsterIdle;

typedef struct _MonsterBehavior MonsterBehavior;

typedef struct _MonsterSenses MonsterSenses;

typedef struct _MonsterAllegiances MonsterAllegiances;

typedef struct _MonsterAttackAttributes MonsterAttackAttributes;

typedef struct _MonsterMissile MonsterMissile;

typedef struct _MonsterCombatAttributes MonsterCombatAttributes;

typedef struct _MonsterSubAttributes MonsterSubAttributes;

typedef struct _MonsterVars MonsterVars;

typedef struct _MonsterIR MonsterIR;

typedef struct burntTuneType burntTuneType;

typedef struct _MonsterState MonsterState;

typedef struct _MonsterStateChoice MonsterStateChoice;

typedef void (*processVert_t)();

typedef void (*MonsterFunc)();

typedef void (*MonsterDamageFunc)();

union REAVER_76fake // Hashcode: 0xFA310C8A (dec: -97448822)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: reaver.o, reaver.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: reaver.o, reaver.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: reaver.o, reaver.o
};

union REAVER_77fake // Hashcode: 0xEE38D1A7 (dec: -298266201)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct REAVER_114fake // hashcode: 0xB051AA65 (dec: -1336825243)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: reaver.o, reaver.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: reaver.o, reaver.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: reaver.o, reaver.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: reaver.o, reaver.o
};

union REAVER_212fake // Hashcode: 0xC845B58D (dec: -934955635)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union GLYPH_76fake // Hashcode: 0xEA39A91C (dec: -365319908)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: glyph.o, glyph.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: glyph.o, glyph.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: glyph.o, glyph.o
};

union GLYPH_77fake // Hashcode: 0x0EE2E853 (dec: 249751635)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct GLYPH_114fake // hashcode: 0x8563DD2E (dec: -2057052882)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: glyph.o, glyph.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: glyph.o, glyph.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: glyph.o, glyph.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: glyph.o, glyph.o
};

union GLYPH_212fake // Hashcode: 0xD88B8723 (dec: -661944541)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct __GlyphData // hashcode: 0x54A12564 (dec: 1419847012)
{
	void (*process)(); // size=0, offset=0
	struct __MessageQueue messages; // size=136, offset=4
	long selectedGlyph; // size=0, offset=140
	short glyph_time; // size=0, offset=144
	short glyph_radius; // size=0, offset=146
	short glyph_scale; // size=0, offset=148
	short glyph_rotation; // size=0, offset=150
	short target_glyph_rotation; // size=0, offset=152
	short glyph_movement; // size=0, offset=154
};

struct __GlyphHudSaveData // hashcode: 0xAFAF1CC5 (dec: -1347478331)
{
	short MANNA_Count; // size=0, offset=0
	short HUD_Count; // size=0, offset=2
};

typedef struct __GlyphData GlyphData;

typedef struct __GlyphHudSaveData GlyphHudSaveData;

union HUMAN_76fake // Hashcode: 0x40C37265 (dec: 1086550629)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: human.o, human.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: human.o, human.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: human.o, human.o
};

union HUMAN_77fake // Hashcode: 0x77688036 (dec: 2003337270)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct HUMAN_114fake // hashcode: 0xB0B780DE (dec: -1330151202)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: human.o, human.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: human.o, human.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: human.o, human.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: human.o, human.o
};

union HUMAN_188fake // Hashcode: 0xA0EC6F3A (dec: -1595117766)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _MonsterAttributes // hashcode: 0xAFA2C05F (dec: -1348288417)
{
	unsigned long magicnum; // size=0, offset=0
	void *tunData; // size=0, offset=4
	char *auxAnimList; // size=0, offset=8
	char *ambientAnimList; // size=0, offset=12
	long whatAmI; // size=0, offset=16
	char numAuxAnims; // size=0, offset=20
	char numAmbientAnims; // size=0, offset=21
	unsigned char defaultAge; // size=0, offset=22
	char pupateObject; // size=0, offset=23
	unsigned char damageFXSegment; // size=0, offset=24
	unsigned char headSegment; // size=0, offset=25
	unsigned char neckSegment; // size=0, offset=26
	unsigned char leftShoulderSegment; // size=0, offset=27
	unsigned char rightShoulderSegment; // size=0, offset=28
	unsigned char waistSegment; // size=0, offset=29
	unsigned char leftKneeSegment; // size=0, offset=30
	unsigned char rightKneeSegment; // size=0, offset=31
	unsigned char leftFootSegment; // size=0, offset=32
	unsigned char rightFootSegment; // size=0, offset=33
	unsigned char spineSegment; // size=0, offset=34
	unsigned char leftWeaponSegment; // size=0, offset=35
	unsigned char rightWeaponSegment; // size=0, offset=36
	unsigned char grabSegment; // size=0, offset=37
	unsigned char bloodImpaleFrame; // size=0, offset=38
	unsigned char bloodConeFrame; // size=0, offset=39
	unsigned char bruiseRed; // size=0, offset=40
	unsigned char bruiseGreen; // size=0, offset=41
	unsigned char bruiseBlue; // size=0, offset=42
	char numSubAttributes; // size=0, offset=43
	char numCombatAttributes; // size=0, offset=44
	char numAttackAttributes; // size=0, offset=45
	char numMissiles; // size=0, offset=46
	char numAnims; // size=0, offset=47
	char numIdles; // size=0, offset=48
	char numBehaviors; // size=0, offset=49
	char numShatters; // size=0, offset=50
	struct _MonsterSubAttributes **subAttributesList; // size=80, offset=52
	struct _MonsterCombatAttributes **combatAttributesList; // size=40, offset=56
	struct _MonsterAttackAttributes *attackAttributesList; // size=32, offset=60
	struct _MonsterMissile *missileList; // size=16, offset=64
	struct _MonsterAnim *animList; // size=16, offset=68
	struct _MonsterIdle *idleList; // size=4, offset=72
	struct _MonsterBehavior *behaviorList; // size=8, offset=76
	void *shatterList; // size=0, offset=80
};

struct _MonsterFunctionTable // hashcode: 0x6ADF1C02 (dec: 1793006594)
{
	void (*initFunc)(); // size=0, offset=0
	void (*cleanUpFunc)(); // size=0, offset=4
	void (*damageEffectFunc)(); // size=0, offset=8
	unsigned long (*queryFunc)(); // size=0, offset=12
	void (*messageFunc)(); // size=0, offset=16
	struct _MonsterStateChoice *stateFuncs; // size=12, offset=20
	char *versionID; // size=0, offset=24
	char *localVersionID; // size=0, offset=28
};

typedef struct _MonsterAttributes MonsterAttributes;

typedef struct _MonsterFunctionTable MonsterFunctionTable;

union HUNTER_76fake // Hashcode: 0x8B2F9E92 (dec: -1959813486)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: hunter.o, hunter.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: hunter.o, hunter.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: hunter.o, hunter.o
};

union HUNTER_77fake // Hashcode: 0xEB123B3C (dec: -351126724)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct HUNTER_114fake // hashcode: 0x26220B6D (dec: 639765357)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: hunter.o, hunter.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: hunter.o, hunter.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: hunter.o, hunter.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: hunter.o, hunter.o
};

union HUNTER_188fake // Hashcode: 0xA6C5F937 (dec: -1496975049)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _HunterVars // hashcode: 0x2703CB78 (dec: 654560120)
{
	short startIdx; // size=0, offset=0
	short endIdx; // size=0, offset=2
	int rem_time; // size=0, offset=4
	short angles[16]; // size=32, offset=8
};

typedef struct _HunterVars HunterVars;

union MISSILE_76fake // Hashcode: 0x903F369C (dec: -1874905444)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: missile.o, missile.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: missile.o, missile.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: missile.o, missile.o
};

union MISSILE_77fake // Hashcode: 0x1941FB53 (dec: 423754579)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MISSILE_114fake // hashcode: 0x9E93F839 (dec: -1634469831)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: missile.o, missile.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: missile.o, missile.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: missile.o, missile.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: missile.o, missile.o
};

union MISSILE_191fake // Hashcode: 0x8A59B574 (dec: -1973832332)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MissileGraphics // hashcode: 0xA133FA7D (dec: -1590429059)
{
	unsigned char object; // size=0, offset=0
	unsigned char model; // size=0, offset=1
};

typedef struct MissileGraphics MissileGraphics;

union MONAPI_76fake // Hashcode: 0x34730FFD (dec: 879955965)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monapi.o, monapi.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monapi.o, monapi.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monapi.o, monapi.o
};

union MONAPI_77fake // Hashcode: 0x929BD08B (dec: -1835282293)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MONAPI_114fake // hashcode: 0xD6D7DFD3 (dec: -690495533)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monapi.o, monapi.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monapi.o, monapi.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monapi.o, monapi.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monapi.o, monapi.o
};

struct evMonsterHitTerrainData // hashcode: 0x0035BA96 (dec: 3521174)
{
	struct _Normal normal; // size=8, offset=0
	short faceFlags; // size=0, offset=8
};

struct evMonsterHitObjectData // hashcode: 0x2EC15C0C (dec: 784423948)
{
	struct _Instance *instance; // size=664, offset=0
	int hitType; // size=0, offset=4
};

union MONAPI_196fake // Hashcode: 0x84876DDA (dec: -2071499302)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _MonsterSaveInfo // hashcode: 0x5130240C (dec: 1362109452)
{
	long mvFlags; // size=0, offset=0
	long auxFlags; // size=0, offset=4
	short soulID; // size=0, offset=8
	short soulJuice; // size=0, offset=10
	unsigned int age; // size=3, offset=96
	unsigned int state; // size=6, offset=99
	unsigned int behaviorState; // size=5, offset=105
	unsigned int anim; // size=6, offset=110
	unsigned int causeOfDeath; // size=3, offset=116
	char versionNumber; // size=0, offset=15
};

typedef struct evMonsterHitTerrainData evMonsterHitTerrainData;

typedef struct evMonsterHitObjectData evMonsterHitObjectData;

typedef struct _MonsterSaveInfo MonsterSaveInfo;

union MONLIB_76fake // Hashcode: 0x1BA14368 (dec: 463553384)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monlib.o, monlib.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monlib.o, monlib.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monlib.o, monlib.o
};

union MONLIB_77fake // Hashcode: 0x3D5FBB71 (dec: 1029684081)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MONLIB_114fake // hashcode: 0x7334BE32 (dec: 1932836402)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monlib.o, monlib.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monlib.o, monlib.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monlib.o, monlib.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monlib.o, monlib.o
};

struct evPhysicsLOSData // hashcode: 0xAFB4D364 (dec: -1347103900)
{
	struct _Position destination; // size=6, offset=0
	short arc; // size=0, offset=6
	struct _Position origin; // size=6, offset=8
	short flags; // size=0, offset=14
	short result; // size=0, offset=16
};

union MONLIB_202fake // Hashcode: 0x77EE2943 (dec: 2012096835)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

enum MonsterAnim // Hashcode: 0x36ADC593 (dec: 917357971)
{
	MONSTER_ANIM_HIT1 = 0,
	MONSTER_ANIM_HIT2 = 1,
	MONSTER_ANIM_WALK = 2,
	MONSTER_ANIM_RUN = 3,
	MONSTER_ANIM_GRABBED = 4,
	MONSTER_ANIM_STUNNED = 5,
	MONSTER_ANIM_JUMPFORWARD = 6,
	MONSTER_ANIM_JUMPBACK = 7,
	MONSTER_ANIM_JUMPLEFT = 8,
	MONSTER_ANIM_JUMPRIGHT = 9,
	MONSTER_ANIM_STANCE_HEALTHY = 10,
	MONSTER_ANIM_STANCE_VULNERABLE = 11,
	MONSTER_ANIM_STUNNED_RECOVERY = 12,
	MONSTER_ANIM_IMPALED = 13,
	MONSTER_ANIM_STRUGGLE = 14,
	MONSTER_ANIM_BREAKHOLD = 15,
	MONSTER_ANIM_THROWN = 16,
	MONSTER_ANIM_IMPACT = 17,
	MONSTER_ANIM_LANDONFEET = 18,
	MONSTER_ANIM_FALL = 19,
	MONSTER_ANIM_BREAKFALL = 20,
	MONSTER_ANIM_SPINLAND = 21,
	MONSTER_ANIM_IMPALEDEATH = 22,
	MONSTER_ANIM_GETUP = 23,
	MONSTER_ANIM_GENERALDEATH = 24,
	MONSTER_ANIM_MISSILEIMPALEDEATH = 25,
	MONSTER_ANIM_SURPRISED = 26,
	MONSTER_ANIM_AGONY = 27,
	MONSTER_ANIM_PUPATE = 28,
	MONSTER_ANIM_NOTICE = 29,
	MONSTER_ANIM_SOULSUCK = 30,
	MONSTER_ANIM_IMPALEHORZ = 31,
	MONSTER_ANIM_IMPALEVERT = 32,
	MONSTER_ANIM_SOULOUTGRND = 33,
	MONSTER_ANIM_SOULOUTHORZ = 34,
	MONSTER_ANIM_SOULOUTVERT = 35,
	MONSTER_ANIM_FALLOVER = 36,
	MONSTER_ANIM_EMBRACE = 37,
	MONSTER_ANIM_SHOVE = 38,
	MONSTER_ANIM_FLIPSWITCH = 39,
	MONSTER_ANIM_EVADELEFT = 40,
	MONSTER_ANIM_EVADERIGHT = 41,
	MONSTER_ANIM_ALARM = 42,
	MONSTER_ANIM_DEAF = 43,
	MONSTER_ANIM_BLIND = 44,
	MONSTER_ANIM_SUCKED = 45,
	MONSTER_NUM_ANIMS = 46,
};

enum MonsterState // Hashcode: 0x70638545 (dec: 1885570373)
{
	MONSTER_STATE_BIRTH = 0,
	MONSTER_STATE_PURSUE = 1,
	MONSTER_STATE_IDLE = 2,
	MONSTER_STATE_MISSILEHIT = 3,
	MONSTER_STATE_FALL = 4,
	MONSTER_STATE_WANDER = 5,
	MONSTER_STATE_ATTACK = 6,
	MONSTER_STATE_IMPALEDEATH = 7,
	MONSTER_STATE_HIT = 8,
	MONSTER_STATE_STUNNED = 9,
	MONSTER_STATE_GRABBED = 10,
	MONSTER_STATE_THROWN = 11,
	MONSTER_STATE_IMPACT = 12,
	MONSTER_STATE_COMBAT = 13,
	MONSTER_STATE_BREAKHOLD = 14,
	MONSTER_STATE_LANDONFEET = 15,
	MONSTER_STATE_GENERALDEATH = 16,
	MONSTER_STATE_ENVIRONMENTDAMAGE = 17,
	MONSTER_STATE_LANDINWATER = 18,
	MONSTER_STATE_FLEE = 19,
	MONSTER_STATE_HIDE = 20,
	MONSTER_STATE_SURPRISEATTACK = 21,
	MONSTER_STATE_PARRY = 22,
	MONSTER_STATE_DEAD = 23,
	MONSTER_STATE_SURPRISED = 24,
	MONSTER_STATE_NOTICE = 25,
	MONSTER_STATE_PUPATE = 26,
	MONSTER_STATE_EMBRACE = 27,
	MONSTER_STATE_PROJECTILE = 28,
	MONSTER_STATE_TERRAINIMPALEDEATH = 29,
	MONSTER_NUM_STATES = 30,
};

typedef struct evPhysicsLOSData evPhysicsLOSData;

union MONTABLE_71fake // Hashcode: 0xF2B7BF79 (dec: -222838919)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: montable.o, montable.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: montable.o, montable.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: montable.o, montable.o
};

union MONTABLE_72fake // Hashcode: 0x3115DCBB (dec: 823516347)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MONTABLE_109fake // hashcode: 0x77231B26 (dec: 1998789414)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: montable.o, montable.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: montable.o, montable.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: montable.o, montable.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: montable.o, montable.o
};

union MONTABLE_183fake // Hashcode: 0xC31585D6 (dec: -1021999658)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MONTABLE_202fake // hashcode: 0x526787ED (dec: 1382516717)
{
	long whatAmI; // size=0, offset=0
	struct _MonsterFunctionTable *table; // size=32, offset=4
};

union MORLOCK_76fake // Hashcode: 0x7F6AAB7F (dec: 2137697151)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: morlock.o, morlock.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: morlock.o, morlock.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: morlock.o, morlock.o
};

union MORLOCK_77fake // Hashcode: 0xC13B96D4 (dec: -1053059372)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MORLOCK_114fake // hashcode: 0xCD447DAB (dec: -851149397)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: morlock.o, morlock.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: morlock.o, morlock.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: morlock.o, morlock.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: morlock.o, morlock.o
};

union MORLOCK_188fake // Hashcode: 0x645912AF (dec: 1683559087)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SKINNER_76fake // Hashcode: 0xDD29EE77 (dec: -584454537)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: skinner.o, skinner.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: skinner.o, skinner.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: skinner.o, skinner.o
};

union SKINNER_77fake // Hashcode: 0x9A4CFC90 (dec: -1706230640)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct SKINNER_114fake // hashcode: 0x26820941 (dec: 646056257)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: skinner.o, skinner.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: skinner.o, skinner.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: skinner.o, skinner.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: skinner.o, skinner.o
};

union SKINNER_208fake // Hashcode: 0xB9B9D017 (dec: -1179004905)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SLUAGH_76fake // Hashcode: 0xF30AD16A (dec: -217394838)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: sluagh.o, sluagh.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: sluagh.o, sluagh.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: sluagh.o, sluagh.o
};

union SLUAGH_77fake // Hashcode: 0x3F4416B8 (dec: 1061426872)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct SLUAGH_114fake // hashcode: 0xAA0587E2 (dec: -1442478110)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: sluagh.o, sluagh.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: sluagh.o, sluagh.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: sluagh.o, sluagh.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: sluagh.o, sluagh.o
};

union SLUAGH_188fake // Hashcode: 0xC5A70FC4 (dec: -978907196)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MONSENSE_76fake // Hashcode: 0x64C38F9E (dec: 1690537886)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monsense.o, monsense.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monsense.o, monsense.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monsense.o, monsense.o
};

union MONSENSE_77fake // Hashcode: 0x0CBD975E (dec: 213751646)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MONSENSE_114fake // hashcode: 0xB20692BF (dec: -1308192065)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monsense.o, monsense.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monsense.o, monsense.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monsense.o, monsense.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monsense.o, monsense.o
};

union MONSENSE_191fake // Hashcode: 0xFF34478D (dec: -13351027)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct RadarInfo // hashcode: 0x061DFEEE (dec: 102629102)
{
	short angle; // size=0, offset=0
	short x; // size=0, offset=2
	short y; // size=0, offset=4
};

typedef struct RadarInfo RadarInfo;

union MONSTER_76fake // Hashcode: 0x0FEE007D (dec: 267255933)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monster.o, monster.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monster.o, monster.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monster.o, monster.o
};

union MONSTER_77fake // Hashcode: 0x88404073 (dec: -2009055117)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MONSTER_114fake // hashcode: 0x3DAE1517 (dec: 1034818839)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monster.o, monster.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monster.o, monster.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monster.o, monster.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monster.o, monster.o
};

union MONSTER_208fake // Hashcode: 0xB25E2301 (dec: -1302453503)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct burntMessType // hashcode: 0xA7801ACB (dec: -1484776757)
{
	int closestvert; // size=0, offset=0
	int closestdist; // size=0, offset=4
	int closestseg; // size=0, offset=8
	struct burntTuneType *burntTune; // size=8, offset=12
};

struct bloodyMessType // hashcode: 0xE0FCE556 (dec: -520297130)
{
	int closestvert; // size=0, offset=0
	int closestdist; // size=0, offset=4
	int closestseg; // size=0, offset=8
	int bloodiedAVert; // size=0, offset=12
	int bloodIntensity; // size=0, offset=16
};

typedef struct burntMessType burntMessType;

typedef struct bloodyMessType bloodyMessType;

union INSTNCG2_23fake // Hashcode: 0x687DD2D0 (dec: 1753076432)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: InstncG2.o, InstncG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: InstncG2.o, InstncG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: InstncG2.o, InstncG2.o
};

union INSTNCG2_72fake // Hashcode: 0xA04B6616 (dec: -1605671402)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct INSTNCG2_109fake // hashcode: 0xC756EEE5 (dec: -950604059)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: InstncG2.o, InstncG2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: InstncG2.o, InstncG2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: InstncG2.o, InstncG2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: InstncG2.o, InstncG2.o
};

union MAING2_71fake // Hashcode: 0x78373087 (dec: 2016882823)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: MainG2.o, MainG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: MainG2.o, MainG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: MainG2.o, MainG2.o
};

union MAING2_72fake // Hashcode: 0xA1388DAF (dec: -1590129233)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MATRIXG2_71fake // Hashcode: 0xB98B6128 (dec: -1182047960)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: MatrixG2.o, MatrixG2.o
};

union MATRIXG2_72fake // Hashcode: 0xFCD7C665 (dec: -52967835)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MATRIXG2_109fake // hashcode: 0x79F9E45F (dec: 2046420063)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: MatrixG2.o, MatrixG2.o
};

struct _G2PoolMemPool_Type // hashcode: 0x72EED9F3 (dec: 1928255987)
{
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2PoolMem_Type *blockPool; // size=0, offset=12
};

typedef struct _G2PoolMemPool_Type G2PoolMemPool;

typedef void G2PoolMem;

union QUATG2_71fake // Hashcode: 0x047F948C (dec: 75469964)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: QuatG2.o, QuatG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: QuatG2.o, QuatG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: QuatG2.o, QuatG2.o
};

union QUATG2_72fake // Hashcode: 0xCB06D631 (dec: -888744399)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SOUL_76fake // Hashcode: 0xF74A8D15 (dec: -146109163)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: soul.o, soul.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: soul.o, soul.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: soul.o, soul.o
};

union SOUL_77fake // Hashcode: 0x3587F274 (dec: 898101876)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct SOUL_114fake // hashcode: 0xACFAAB70 (dec: -1392858256)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: soul.o, soul.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: soul.o, soul.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: soul.o, soul.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: soul.o, soul.o
};

union SOUL_188fake // Hashcode: 0x80E7DFFE (dec: -2132287490)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union VWRAITH_76fake // Hashcode: 0x88B03CE3 (dec: -2001715997)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: vwraith.o, vwraith.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: vwraith.o, vwraith.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: vwraith.o, vwraith.o
};

union VWRAITH_77fake // Hashcode: 0x927B2535 (dec: -1837423307)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct VWRAITH_114fake // hashcode: 0xBF80376B (dec: -1082116245)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: vwraith.o, vwraith.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: vwraith.o, vwraith.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: vwraith.o, vwraith.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: vwraith.o, vwraith.o
};

union VWRAITH_188fake // Hashcode: 0x162AA617 (dec: 371893783)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union WORSHIP_76fake // Hashcode: 0x9C87D41D (dec: -1668819939)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: worship.o, worship.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: worship.o, worship.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: worship.o, worship.o
};

union WORSHIP_77fake // Hashcode: 0x0FD5B694 (dec: 265664148)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct WORSHIP_114fake // hashcode: 0x3514D2A0 (dec: 890557088)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: worship.o, worship.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: worship.o, worship.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: worship.o, worship.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: worship.o, worship.o
};

union WORSHIP_188fake // Hashcode: 0x10ACD8AB (dec: 279763115)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MBMISS_76fake // Hashcode: 0x684B0470 (dec: 1749746800)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: mbmiss.o, mbmiss.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: mbmiss.o, mbmiss.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: mbmiss.o, mbmiss.o
};

union MBMISS_77fake // Hashcode: 0xCC2DCA9C (dec: -869414244)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MBMISS_114fake // hashcode: 0x8CAF429E (dec: -1934671202)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: mbmiss.o, mbmiss.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: mbmiss.o, mbmiss.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: mbmiss.o, mbmiss.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: mbmiss.o, mbmiss.o
};

union MBMISS_208fake // Hashcode: 0x21B3C728 (dec: 565430056)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _walbossAttributes // hashcode: 0x77E820E3 (dec: 2011701475)
{
	unsigned char segmentToAttach; // size=0, offset=0
	unsigned char frameToBirth; // size=0, offset=1
	unsigned char frameToExpel; // size=0, offset=2
	unsigned char maxEggHits; // size=0, offset=3
	short maxAngle; // size=0, offset=4
	short timeForHitAgony; // size=0, offset=6
	short segmentForBodyTwist; // size=0, offset=8
	short timeToThornPrep; // size=0, offset=10
	short timeToThornPoke; // size=0, offset=12
	short timeToEggThrob; // size=0, offset=14
	short timeToEggExplode; // size=0, offset=16
	short razielStunTime; // size=0, offset=18
	struct {
		short plusDelta; // size=0, offset=0
		short minusDelta; // size=0, offset=2
		short validAtHitPoint; // size=0, offset=4
	} attackDeltas; // size=0, offset=20, found in object files: mbmiss.o, mbmiss.o
};

typedef struct _walbossAttributes WalbossAttributes;

struct _G2AnimController_Type // hashcode: 0xED8DD7EF (dec: -309471249)
{
	unsigned short next; // size=0, offset=0
	unsigned char type; // size=0, offset=2
	unsigned char segNumber; // size=0, offset=3
	void *callbackData; // size=0, offset=4
	unsigned short flags; // size=0, offset=8
	short duration; // size=0, offset=10
	short elapsedTime; // size=0, offset=12
	struct _G2AnimAlphaTable_Type *alphaTable; // size=4, offset=16
	union {
		struct {
			unsigned long (*function)(); // size=0, offset=0
			void *fnData; // size=0, offset=4
		} callback; // size=8, offset=0, found in object files: AnimG2.o, AnimG2.o
		struct {
			struct _G2SVector3_Type base; // size=6, offset=0
			struct _G2SVector3_Type offset; // size=6, offset=6
		} vector; // size=12, offset=0, found in object files: AnimG2.o, AnimG2.o
		struct {
			struct _G2Quat_Type src; // size=8, offset=0
			struct _G2Quat_Type dest; // size=8, offset=8
		} quat; // size=16, offset=0, found in object files: AnimG2.o, AnimG2.o
	} data; // size=16, offset=20, found in object files: AnimG2.o, AnimG2.o
};

union ANIMG2_72fake // Hashcode: 0xC8333D29 (dec: -936166103)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct ANIMG2_109fake // hashcode: 0x1D789B70 (dec: 494443376)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: AnimG2.o, AnimG2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: AnimG2.o, AnimG2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: AnimG2.o, AnimG2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: AnimG2.o, AnimG2.o
};

struct _G2AnimSegKeyflagInfo_Type // hashcode: 0x639C0AF3 (dec: 1671170803)
{
	unsigned long *stream; // size=0, offset=0
	unsigned long flags; // size=0, offset=4
	int bitCount; // size=0, offset=8
};

struct _G2AnimDecompressChannelInfo_Type // hashcode: 0x261A7343 (dec: 639267651)
{
	struct _G2AnimKeylist_Type *keylist; // size=20, offset=0
	unsigned short *chanData; // size=0, offset=4
	int storedKey; // size=0, offset=8
	int targetKey; // size=0, offset=12
};

struct _G2AnimSegValue_Type // hashcode: 0x627C0711 (dec: 1652295441)
{
	union {
		struct _G2SVector3_Type rot; // size=6, offset=0
		struct _G2Quat_Type quat; // size=8, offset=0
	} rotQuat; // size=8, offset=0, found in object files: AnimG2.o, AnimG2.o
	struct _G2SVector3_Type scale; // size=6, offset=8
	unsigned short pad; // size=0, offset=14
	struct _G2SVector3_Type trans; // size=6, offset=16
	unsigned short bIsQuat; // size=0, offset=22
};

struct _G2AnimChanStatusBlockPool_Type // hashcode: 0x471CDEDE (dec: 1193074398)
{
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimChanStatusBlock_Type *blockPool; // size=36, offset=12
};

struct _G2AnimControllerPool_Type // hashcode: 0x97F99D91 (dec: -1745248879)
{
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimController_Type *blockPool; // size=36, offset=12
};

struct _G2AnimInterpStateBlockPool_Type // hashcode: 0x0C45A027 (dec: 205889575)
{
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimInterpStateBlock_Type *blockPool; // size=164, offset=12
};

typedef struct _G2AnimController_Type G2AnimController;

typedef struct _G2AnimSegKeyflagInfo_Type G2AnimSegKeyflagInfo;

typedef struct _G2AnimDecompressChannelInfo_Type G2AnimDecompressChannelInfo;

typedef struct _G2AnimSegValue_Type G2AnimSegValue;

typedef struct _G2AnimChanStatusBlockPool_Type G2AnimChanStatusBlockPool;

typedef struct _G2AnimControllerPool_Type G2AnimControllerPool;

typedef struct _G2AnimInterpStateBlockPool_Type G2AnimInterpStateBlockPool;

typedef void (*G2AnimApplyControllerFn)();

union PLAN_76fake // Hashcode: 0xA8B6EFA5 (dec: -1464406107)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: plan.o, plan.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: plan.o, plan.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: plan.o, plan.o
};

union PLAN_77fake // Hashcode: 0xD38C3208 (dec: -745786872)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PLAN_114fake // hashcode: 0x87BFCF7E (dec: -2017472642)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: plan.o, plan.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: plan.o, plan.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: plan.o, plan.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: plan.o, plan.o
};

union PLAN_211fake // Hashcode: 0x1FAF9740 (dec: 531601216)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _PlanCollideInfo // hashcode: 0x440F4D04 (dec: 1141853444)
{
	long StreamUnitID; // size=0, offset=0
	struct _TFace *tFace; // size=12, offset=4
	struct _Position collidePos; // size=6, offset=8
};

typedef struct _PlanCollideInfo PlanCollideInfo;

union PLANAPI_112fake // Hashcode: 0xD4496305 (dec: -733388027)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: planapi.o, planapi.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: planapi.o, planapi.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: planapi.o, planapi.o
};

union PLANAPI_113fake // Hashcode: 0xF6EB893E (dec: -152336066)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PLANAPI_150fake // hashcode: 0x9937E4D7 (dec: -1724390185)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: planapi.o, planapi.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: planapi.o, planapi.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: planapi.o, planapi.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: planapi.o, planapi.o
};

union PLANAPI_206fake // Hashcode: 0x9BA82680 (dec: -1683478912)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct PoolManagementData // hashcode: 0xAFD71D6F (dec: -1344856721)
{
	char state; // size=0, offset=0
	unsigned char numNodesInPool; // size=0, offset=1
	struct _Position playerPosAtLastPlanMkrUpdate; // size=6, offset=2
	struct PlanningNode *expansionNode1; // size=28, offset=8
	struct PlanningNode *expansionNode2; // size=28, offset=12
	unsigned short (*distanceMatrix)[32]; // size=4, offset=16
	unsigned short pairType; // size=0, offset=20
	struct _Position peakPos; // size=6, offset=22
	unsigned char currentNode; // size=0, offset=28
	unsigned char currentBit; // size=0, offset=29
};

struct EnemyPlanData // hashcode: 0xC3D6AA44 (dec: -1009341884)
{
	unsigned char nodeSkipArray[8]; // size=8, offset=0
	unsigned char nodeTypeArray[8]; // size=8, offset=8
	struct _Position wayPointArray[8]; // size=48, offset=16
	short goalUnitID; // size=0, offset=64
	unsigned char numWayPoints; // size=0, offset=66
};

typedef struct PoolManagementData PoolManagementData;

typedef struct EnemyPlanData EnemyPlanData;

union PLANCOLL_76fake // Hashcode: 0xE13058DD (dec: -516925219)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: plancoll.o, plancoll.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: plancoll.o, plancoll.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: plancoll.o, plancoll.o
};

union PLANCOLL_77fake // Hashcode: 0x43B37F69 (dec: 1135837033)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PLANCOLL_114fake // hashcode: 0xD7BEA986 (dec: -675370618)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: plancoll.o, plancoll.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: plancoll.o, plancoll.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: plancoll.o, plancoll.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: plancoll.o, plancoll.o
};

union PLANCOLL_211fake // Hashcode: 0x54CB5BFA (dec: 1422613498)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct _fth // hashcode: 0xDF22FD5E (dec: -551355042)
{
	char x; // size=0, offset=0
	char y; // size=0, offset=1
	char z; // size=0, offset=2
	char nodeType; // size=0, offset=3
};

typedef struct _fth FindTerrainHit;

union PLANDRAW_76fake // Hashcode: 0xD8EC0781 (dec: -655620223)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: plandraw.o, plandraw.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: plandraw.o, plandraw.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: plandraw.o, plandraw.o
};

union PLANDRAW_77fake // Hashcode: 0x52638305 (dec: 1382253317)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PLANDRAW_114fake // hashcode: 0xAD1348FA (dec: -1391245062)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: plandraw.o, plandraw.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: plandraw.o, plandraw.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: plandraw.o, plandraw.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: plandraw.o, plandraw.o
};

union PLANDRAW_205fake // Hashcode: 0x22FBE687 (dec: 586933895)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union TIMERG2_71fake // Hashcode: 0x0924C782 (dec: 153405314)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: TimerG2.o, TimerG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: TimerG2.o, TimerG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: TimerG2.o, TimerG2.o
};

union TIMERG2_72fake // Hashcode: 0xD0D3A43D (dec: -791436227)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct TIMERG2_109fake // hashcode: 0xA22EB04C (dec: -1573998516)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: TimerG2.o, TimerG2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: TimerG2.o, TimerG2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: TimerG2.o, TimerG2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: TimerG2.o, TimerG2.o
};

struct _G2AppDataVM_Type // hashcode: 0x6CC3DAF0 (dec: 1824774896)
{
	int argc; // size=0, offset=0
	int *argv; // size=0, offset=4
};

typedef struct _G2AppDataVM_Type G2AppDataVM;

union QUATVM_71fake // Hashcode: 0x14E72EB7 (dec: 350695095)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: QuatVM.o, QuatVM.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: QuatVM.o, QuatVM.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: QuatVM.o, QuatVM.o
};

union QUATVM_72fake // Hashcode: 0x1D28694F (dec: 489187663)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union ENMYPLAN_76fake // Hashcode: 0xF14E3C4C (dec: -246530996)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: enmyplan.o, enmyplan.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: enmyplan.o, enmyplan.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: enmyplan.o, enmyplan.o
};

union ENMYPLAN_77fake // Hashcode: 0x2BAB784E (dec: 732657742)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct ENMYPLAN_114fake // hashcode: 0x7472D781 (dec: 1953683329)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: enmyplan.o, enmyplan.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: enmyplan.o, enmyplan.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: enmyplan.o, enmyplan.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: enmyplan.o, enmyplan.o
};

union ENMYPLAN_211fake // Hashcode: 0xF07A0EC5 (dec: -260436283)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct EnemyPlanSlotData // hashcode: 0x825BCDA8 (dec: -2107912792)
{
	char slotInUse; // size=0, offset=0
	char state; // size=0, offset=1
	char wayPointBeingServoedTo; // size=0, offset=2
	struct _Position startPos; // size=6, offset=4
	struct _Position goalPos; // size=6, offset=10
	struct _Position oldCurrentPos; // size=6, offset=16
	struct EnemyPlanData planData; // size=68, offset=22
	char targetType; // size=0, offset=90
	short timer; // size=0, offset=92
};

typedef struct EnemyPlanSlotData EnemyPlanSlotData;

union RAZIEL_71fake // Hashcode: 0x0DB7372E (dec: 230111022)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: raziel.o, raziel.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: raziel.o, raziel.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: raziel.o, raziel.o
};

union RAZIEL_72fake // Hashcode: 0xABB3835A (dec: -1414298790)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct RAZIEL_109fake // hashcode: 0xA8796B46 (dec: -1468437690)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: raziel.o, raziel.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: raziel.o, raziel.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: raziel.o, raziel.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: raziel.o, raziel.o
};

union RAZIEL_198fake // Hashcode: 0x07BB3AC0 (dec: 129710784)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct __Force // hashcode: 0xE77B83F4 (dec: -411335692)
{
	int Type; // size=0, offset=0
	struct _Vector LinearForce; // size=12, offset=4
	short Friction; // size=0, offset=16
};

struct __AlarmData // hashcode: 0x750BC99A (dec: 1963706778)
{
	short command; // size=0, offset=0
	short data; // size=0, offset=2
};

struct __Idle // hashcode: 0xA491A70B (dec: -1533958389)
{
	unsigned char anim; // size=0, offset=0
	unsigned char frame; // size=0, offset=1
	unsigned char frames; // size=0, offset=2
	unsigned char type; // size=0, offset=3
};

struct __VAnim // hashcode: 0x3A259E9B (dec: 975543963)
{
	unsigned char anim0; // size=0, offset=0
	unsigned char anim1; // size=0, offset=1
	unsigned char anim2; // size=0, offset=2
	unsigned char frames; // size=0, offset=3
	unsigned char mode; // size=0, offset=4
	unsigned char alpha; // size=0, offset=5
	unsigned short frame; // size=0, offset=6
};

struct __SAnim // hashcode: 0x79E7F93A (dec: 2045245754)
{
	struct __VAnim *anim; // size=8, offset=0
	struct __SAnim *nextAnim; // size=16, offset=4
	short mode; // size=0, offset=8
	short data; // size=0, offset=10
	short speedAdjust; // size=0, offset=12
	short pad; // size=0, offset=14
};

struct __AttackItem // hashcode: 0x9DC393B6 (dec: -1648127050)
{
	unsigned char anim; // size=0, offset=0
	unsigned char framesIn; // size=0, offset=1
	unsigned char alphaIn; // size=0, offset=2
	unsigned char framesOut; // size=0, offset=3
	unsigned char switchDelay; // size=0, offset=4
	unsigned char ignoreDelay; // size=0, offset=5
	unsigned char segmentToGlow; // size=0, offset=6
	unsigned char startCollisionFrame; // size=0, offset=7
	unsigned char handsToCollide; // size=0, offset=8
	unsigned char endCollisionFrame; // size=0, offset=9
	unsigned char ribbonStartFrame; // size=0, offset=10
	unsigned char ribbonStartSegment; // size=0, offset=11
	unsigned char ribbonEndSegment; // size=0, offset=12
	unsigned char ribbonLifeTime; // size=0, offset=13
	unsigned char ribbonFaceLifeTime; // size=0, offset=14
	unsigned char knockBackFrames; // size=0, offset=15
	unsigned char glowFadeInFrames; // size=0, offset=16
	unsigned char glowFadeOutFrames; // size=0, offset=17
	unsigned short ribbonStartOpacity; // size=0, offset=18
	unsigned long ribbonStartColor; // size=0, offset=20
	unsigned long ribbonEndColor; // size=0, offset=24
	unsigned long glowColor; // size=0, offset=28
	unsigned short knockBackDistance; // size=0, offset=32
	unsigned short hitPowerScale; // size=0, offset=34
};

struct __ThrowItem // hashcode: 0xE8539A6B (dec: -397174165)
{
	unsigned char prepAnim; // size=0, offset=0
	unsigned char prepAnimFramesIn; // size=0, offset=1
	unsigned char prepAnimAlphaIn; // size=0, offset=2
	unsigned char coilAnim; // size=0, offset=3
	unsigned char coilAnimFramesIn; // size=0, offset=4
	unsigned char coilAnimAlphaIn; // size=0, offset=5
	unsigned char throwAnim; // size=0, offset=6
	unsigned char throwAnimFramesInFactor; // size=0, offset=7
	unsigned char throwFrameToLaunch; // size=0, offset=8
	unsigned char framesOut; // size=0, offset=9
	short launchPointX; // size=0, offset=10
	short launchPointY; // size=0, offset=12
	short launchPointZ; // size=0, offset=14
	short maxXRotation; // size=0, offset=16
	short minXRotation; // size=0, offset=18
	short maxZRotation; // size=0, offset=20
	short minZRotation; // size=0, offset=22
	short velocity; // size=0, offset=24
	short gravity; // size=0, offset=26
	short coilRot; // size=0, offset=28
	short pad; // size=0, offset=30
};

struct __EngagedInstance // hashcode: 0x2C1C3442 (dec: 740045890)
{
	struct _Instance *instance; // size=664, offset=0
	unsigned long distance; // size=0, offset=4
};

struct __FitPoint // hashcode: 0x351A2C67 (dec: 890907751)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
};

struct __SensoryData // hashcode: 0xDC5B7A71 (dec: -597984655)
{
	int Flags; // size=0, offset=0
	struct _SVector ForwardNormal; // size=8, offset=4
	struct _SVector AboveNormal; // size=8, offset=12
	struct _SVector BelowNormal; // size=8, offset=20
	struct _SVector BelowPoint; // size=8, offset=28
	struct _SVector Delta; // size=8, offset=36
	struct _Instance *HitMonster; // size=664, offset=44
	struct _Instance *CurrentAutoFace; // size=664, offset=48
	struct _Instance *LastAutoFace; // size=664, offset=52
	struct __EngagedInstance *EngagedList; // size=8, offset=56
	unsigned long EngagedMask; // size=0, offset=60
	struct _Vector lookAtPoint; // size=12, offset=64
	unsigned long heldClass; // size=0, offset=76
};

struct __Player // hashcode: 0x97A9F0B8 (dec: -1750470472)
{
	int footPrint; // size=0, offset=0
	struct __CharacterState State; // size=860, offset=4
	int Mode; // size=0, offset=864
	int Anim; // size=0, offset=868
	int RotationSegment; // size=0, offset=872
	struct _SVector iVelocity; // size=8, offset=876
	int Magnitude; // size=0, offset=884
	int input; // size=0, offset=888
	int lastInput; // size=0, offset=892
	int ZDirection; // size=0, offset=896
	short Bearing; // size=0, offset=900
	short LastBearing; // size=0, offset=902
	int steeringMode; // size=0, offset=904
	short steeringVelocity; // size=0, offset=908
	short steeringAcceleration; // size=0, offset=910
	int steeringLockRotation; // size=0, offset=912
	short movementMinRate; // size=0, offset=916
	short movementMaxRate; // size=0, offset=918
	short movementMinAnalog; // size=0, offset=920
	short movementMaxAnalog; // size=0, offset=922
	struct __SensoryData Senses; // size=80, offset=924
	struct _Instance *attachedPlatform; // size=664, offset=1004
	short dropOffHeight; // size=0, offset=1008
	short fallZVelocity; // size=0, offset=1010
	short HealthScale; // size=0, offset=1012
	short HealthBalls; // size=0, offset=1014
	int HitPoints; // size=0, offset=1016
	int DamageFrequency; // size=0, offset=1020
	int invincibleTimer; // size=0, offset=1024
	int Abilities; // size=0, offset=1028
	struct _Instance *GlyphSystem; // size=664, offset=1032
	unsigned short GlyphManaBalls; // size=0, offset=1036
	unsigned short GlyphManaMax; // size=0, offset=1038
	struct __FitPoint *constrictData; // size=4, offset=1040
	short constrictIndex; // size=0, offset=1044
	short constrictWaitIndex; // size=0, offset=1046
	struct _SVector constrictCenter; // size=8, offset=1048
	short constrictFlag; // size=0, offset=1056
	short constrictGoodCircle; // size=0, offset=1058
	unsigned long constrictXTotal; // size=0, offset=1060
	unsigned long constrictYTotal; // size=0, offset=1064
	struct _Instance *soulReaver; // size=664, offset=1068
	unsigned long currentSoulReaver; // size=0, offset=1072
	int CurrentPlane; // size=0, offset=1076
	int slipSlope; // size=0, offset=1080
	unsigned long idleCount; // size=0, offset=1084
	struct _Instance *idleInstance; // size=664, offset=1088
	struct __AttackItem *attack; // size=36, offset=1092
	int attackFlags; // size=0, offset=1096
	struct _Instance *attackCurrentHit; // size=664, offset=1100
	struct _Instance *attackLastHit; // size=664, offset=1104
	struct _FXGlowEffect *glowEffect; // size=44, offset=1108
	struct _Instance *attackedBy; // size=664, offset=1112
	struct __ThrowItem *throwData; // size=32, offset=1116
	int throwMode; // size=0, offset=1120
	struct _Position throwTarget; // size=6, offset=1124
	struct _Instance *throwInstance; // size=664, offset=1132
	short throwXRot; // size=0, offset=1136
	short throwZRot; // size=0, offset=1138
	void (*returnState)(); // size=0, offset=1140
	unsigned long passedMask; // size=0, offset=1144
	struct _G2SVector3_Type extraRot; // size=6, offset=1148
	int effectsFlags; // size=0, offset=1156
	short effectsFadeSource; // size=0, offset=1160
	short effectsFadeDest; // size=0, offset=1162
	int effectsFadeStep; // size=0, offset=1164
	int effectsFadeSteps; // size=0, offset=1168
	short autoFaceZone; // size=0, offset=1172
	short autoFaceAngle; // size=0, offset=1174
	int autoFaceLastRootAngle; // size=0, offset=1176
	int autoFaceRootAngle; // size=0, offset=1180
	int autoFaceTrueAngle; // size=0, offset=1184
	int autoFaceAnim; // size=0, offset=1188
	int autoFaceLastAnim; // size=0, offset=1192
	int nothingCounter; // size=0, offset=1196
	int timeAccumulator; // size=0, offset=1200
	struct _Position puppetMoveToPoint; // size=6, offset=1204
	struct _Position puppetRotToPoint; // size=6, offset=1210
	int soundModifier; // size=0, offset=1216
	short alarmTable; // size=0, offset=1220
	short terminator; // size=0, offset=1222
	short swimSpeedAdjustment; // size=0, offset=1224
	short swimTargetSpeed; // size=0, offset=1226
	unsigned long soundHandle; // size=0, offset=1228
	unsigned long soundTimer; // size=0, offset=1232
	unsigned long forcedGlideSpeed; // size=0, offset=1236
	struct _SVector collisionEdgeOffset; // size=8, offset=1240
	struct __SAnim *currentSAnim; // size=16, offset=1248
	unsigned long playerEvent; // size=0, offset=1252
	unsigned long playerEventHistory; // size=0, offset=1256
};

struct PlayerSaveData // hashcode: 0xA056606D (dec: -1604951955)
{
	unsigned long abilities; // size=0, offset=0
	unsigned long currentPlane; // size=0, offset=4
	unsigned long healthScale; // size=0, offset=8
	unsigned long healthBalls; // size=0, offset=12
	unsigned short manaBalls; // size=0, offset=16
	unsigned short manaMax; // size=0, offset=18
	unsigned long playerEventHistory; // size=0, offset=20
};

struct RazielData // hashcode: 0xDE95DD4C (dec: -560603828)
{
	unsigned long version; // size=0, offset=0
	unsigned long nonBurningRibbonStartColor; // size=0, offset=4
	unsigned long nonBurningRibbonEndColor; // size=0, offset=8
	struct __Idle ***idleList; // size=4, offset=12
	struct __AttackItem ***attackList; // size=36, offset=16
	struct __ThrowItem **throwList; // size=32, offset=20
	struct __VAnim *virtualAnimations; // size=8, offset=24
	struct __VAnim *virtualAnimSingle; // size=8, offset=28
	struct __SAnim **stringAnimations; // size=16, offset=32
	short throwFadeValue; // size=0, offset=36
	short throwFadeInRate; // size=0, offset=38
	int throwFadeOutRate; // size=0, offset=40
	int throwManualDistance; // size=0, offset=44
	short healthMaterialRate; // size=0, offset=48
	short healthSpectralRate; // size=0, offset=50
	short healthInvinciblePostHit; // size=0, offset=52
	short healthInvinciblePostShunt; // size=0, offset=54
	short forceMinPitch; // size=0, offset=56
	short forceMaxPitch; // size=0, offset=58
	short forceMinVolume; // size=0, offset=60
	short forceMaxVolume; // size=0, offset=62
	unsigned long forceRampTime; // size=0, offset=64
	int SwimPhysicsFallDamping; // size=0, offset=68
	int SwimPhysicsWaterFrequency; // size=0, offset=72
	int SwimPhysicsWaterAmplitude; // size=0, offset=76
	int SwimPhysicsUnderDeceleration; // size=0, offset=80
	int SwimPhysicsUnderKickVelocity; // size=0, offset=84
	int SwimPhysicsUnderKickAccel; // size=0, offset=88
	int SwimPhysicsUnderVelocity; // size=0, offset=92
	int SwimPhysicsUnderKickDecel; // size=0, offset=96
	int SwimPhysicsUnderStealthAdjust; // size=0, offset=100
	int SwimPhysicsCoilVelocity; // size=0, offset=104
	int SwimPhysicsCoilDecelerationIn; // size=0, offset=108
	int SwimPhysicsCoilDecelerationOut; // size=0, offset=112
	int SwimPhysicsShotVelocity; // size=0, offset=116
	int SwimPhysicsShotAccelerationIn; // size=0, offset=120
	int SwimPhysicsShotAccelerationOut; // size=0, offset=124
	int SwimPhysicsSurfVelocity; // size=0, offset=128
	int SwimPhysicsSurfAccelerationIn; // size=0, offset=132
	int SwimPhysicsSurfAccelerationOut; // size=0, offset=136
	int SwimPhysicsSurfKickVelocity; // size=0, offset=140
	int SwimPhysicsSurfKickAccel; // size=0, offset=144
	int SwimPhysicsSurfMinRotation; // size=0, offset=148
	int SwimPhysicsSurfMaxRotation; // size=0, offset=152
	int SwimPhysicsSurfKickDecel; // size=0, offset=156
};

struct __razController // hashcode: 0x5BBC2C78 (dec: 1539058808)
{
	unsigned short segment; // size=0, offset=0
	unsigned short type; // size=0, offset=2
};

typedef struct __Force Force;

typedef struct __AlarmData AlarmData;

typedef struct __Idle Idle;

typedef struct __VAnim VAnim;

typedef struct __SAnim SAnim;

typedef struct __AttackItem AttackItem;

typedef struct __ThrowItem ThrowItem;

typedef struct __EngagedInstance EngagedInstance;

typedef struct __FitPoint FitPoint;

typedef struct __SensoryData SensoryData;

typedef struct __Player Player;

typedef struct PlayerSaveData PlayerSaveData;

typedef struct RazielData RazielData;

typedef struct __razController razController;

union PLANOPT_112fake // Hashcode: 0xA099040F (dec: -1600584689)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: planopt.o, planopt.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: planopt.o, planopt.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: planopt.o, planopt.o
};

union PLANOPT_113fake // Hashcode: 0x063C74E2 (dec: 104625378)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PLANOPT_150fake // hashcode: 0x099573EC (dec: 160789484)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: planopt.o, planopt.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: planopt.o, planopt.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: planopt.o, planopt.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: planopt.o, planopt.o
};

union PLANOPT_206fake // Hashcode: 0xD9E5FD2C (dec: -639238868)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLANPOOL_112fake // Hashcode: 0xD2C9AD99 (dec: -758534759)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: planpool.o, planpool.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: planpool.o, planpool.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: planpool.o, planpool.o
};

union PLANPOOL_113fake // Hashcode: 0xF941FB28 (dec: -113116376)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PLANPOOL_150fake // hashcode: 0x57F61968 (dec: 1475746152)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: planpool.o, planpool.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: planpool.o, planpool.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: planpool.o, planpool.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: planpool.o, planpool.o
};

union PLANPOOL_206fake // Hashcode: 0x41B5DC13 (dec: 1102437395)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLANSRCH_112fake // Hashcode: 0x6ED1F8B4 (dec: 1859254452)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: plansrch.o, plansrch.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: plansrch.o, plansrch.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: plansrch.o, plansrch.o
};

union PLANSRCH_113fake // Hashcode: 0x754D1B66 (dec: 1967987558)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct PLANSRCH_150fake // hashcode: 0xC9DE00BB (dec: -908197701)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: plansrch.o, plansrch.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: plansrch.o, plansrch.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: plansrch.o, plansrch.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: plansrch.o, plansrch.o
};

union PLANSRCH_206fake // Hashcode: 0x7C9ED748 (dec: 2090784584)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union CONTROL_71fake // Hashcode: 0x52AEF142 (dec: 1387196738)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: control.o, control.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: control.o, control.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: control.o, control.o
};

union CONTROL_72fake // Hashcode: 0xD7A62127 (dec: -676978393)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct CONTROL_109fake // hashcode: 0x9D2339BC (dec: -1658635844)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: control.o, control.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: control.o, control.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: control.o, control.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: control.o, control.o
};

union CONTROL_198fake // Hashcode: 0x90DD126E (dec: -1864560018)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct DR_STP // hashcode: 0x0D49853A (dec: 222922042)
{
	unsigned long tag; // size=0, offset=0
	unsigned long code[2]; // size=8, offset=4
};

union UNDRWRLD_76fake // Hashcode: 0x242C6890 (dec: 606890128)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: undrwrld.o, undrwrld.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: undrwrld.o, undrwrld.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: undrwrld.o, undrwrld.o
};

union UNDRWRLD_77fake // Hashcode: 0xC68F32F4 (dec: -963693836)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct UNDRWRLD_114fake // hashcode: 0xD8EA38BC (dec: -655738692)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: undrwrld.o, undrwrld.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: undrwrld.o, undrwrld.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: undrwrld.o, undrwrld.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: undrwrld.o, undrwrld.o
};

union UNDRWRLD_190fake // Hashcode: 0xDC642D09 (dec: -597414647)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct UW_ScreenXY // hashcode: 0x17355DB4 (dec: 389373364)
{
	short sx; // size=0, offset=0
	short sy; // size=0, offset=2
	short dx; // size=0, offset=4
	short dy; // size=0, offset=6
};

typedef struct DR_STP DR_STP;

typedef struct UW_ScreenXY UW_ScreenXY;

union SAVEINFO_71fake // Hashcode: 0xD00637F3 (dec: -804898829)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: saveinfo.o, saveinfo.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: saveinfo.o, saveinfo.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: saveinfo.o, saveinfo.o
};

union SAVEINFO_72fake // Hashcode: 0xF72E4DF5 (dec: -147960331)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SAVEINFO_189fake // Hashcode: 0x7AD24D41 (dec: 2060602689)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct SavedInfoTracker // hashcode: 0x4F7BECD7 (dec: 1333521623)
{
	char *MemoryCardBuffer; // size=0, offset=0
	char *InfoStart; // size=0, offset=4
	char *InfoEnd; // size=0, offset=8
	char *EndOfMemory; // size=0, offset=12
};

struct SavedBasic // hashcode: 0x9B6EDD8F (dec: -1687233137)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
};

struct SavedLevel // hashcode: 0x6D9B66CD (dec: 1838900941)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
	long areaID; // size=0, offset=4
	short waterZ; // size=0, offset=8
	short numberBSPTrees; // size=0, offset=10
};

struct SavedDeadDeadBits // hashcode: 0x15716A06 (dec: 359754246)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
	char deadDeadBits[1024]; // size=1024, offset=4
};

struct ActualSavedLevel // hashcode: 0x75BAD6F5 (dec: 1975178997)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
	long areaID; // size=0, offset=4
	short waterZ; // size=0, offset=8
	short numberBSPTrees; // size=0, offset=10
	struct SavedBspTree bspTreeArray[1]; // size=8, offset=12
};

struct _GlobalSaveTracker // hashcode: 0x4AA6E48F (dec: 1252451471)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
	short flags; // size=0, offset=4
	unsigned long currentTime; // size=0, offset=8
	short humanOpinionOfRaziel; // size=0, offset=12
	char numRegens; // size=0, offset=14
	struct _MONAPI_Regenerator regenEntries[10]; // size=80, offset=16
	struct gSoundData sound; // size=20, offset=96
	long sizeUsedInBlock; // size=0, offset=116
};

union SAVEINFO_216fake // Hashcode: 0xCCEC7C0B (dec: -856916981)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

typedef struct SavedInfoTracker SavedInfoTracker;

typedef struct SavedBasic SavedBasic;

typedef struct SavedLevel SavedLevel;

typedef struct SavedDeadDeadBits SavedDeadDeadBits;

typedef struct ActualSavedLevel ActualSavedLevel;

typedef struct _GlobalSaveTracker GlobalSaveTracker;

struct CdlFILTER // hashcode: 0x7735ACA5 (dec: 2000006309)
{
	unsigned char file; // size=0, offset=0
	unsigned char chan; // size=0, offset=1
	unsigned short pad; // size=0, offset=2
};

struct SpuCommonAttr // hashcode: 0x01966CA3 (dec: 26635427)
{
	unsigned long mask; // size=0, offset=0
	struct SpuVolume mvol; // size=4, offset=4
	struct SpuVolume mvolmode; // size=4, offset=8
	struct SpuVolume mvolx; // size=4, offset=12
	struct SpuExtAttr cd; // size=12, offset=16
	struct SpuExtAttr ext; // size=12, offset=28
};

union VOICEXA_85fake // Hashcode: 0x7F5675DE (dec: 2136372702)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: voicexa.o, voicexa.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: voicexa.o, voicexa.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: voicexa.o, voicexa.o
};

union VOICEXA_86fake // Hashcode: 0x8076132D (dec: -2139745491)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct VOICEXA_169fake // hashcode: 0x98E9B1B8 (dec: -1729515080)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: voicexa.o, voicexa.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: voicexa.o, voicexa.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: voicexa.o, voicexa.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: voicexa.o, voicexa.o
};

struct XAVoiceListEntry // hashcode: 0x212FB95C (dec: 556775772)
{
	unsigned short length; // size=0, offset=0
};

struct XAVoiceTracker // hashcode: 0xB0A69E83 (dec: -1331257725)
{
	struct CdlLOC currentPos; // size=4, offset=0
	int currentSector; // size=0, offset=4
	int endSector; // size=0, offset=8
	void (*prevCallback)(); // size=0, offset=12
	unsigned char cdResult[8]; // size=8, offset=16
	struct CdCommand cdCmdQueue[8]; // size=64, offset=24
	unsigned short requestQueue[4]; // size=8, offset=88
	struct VoiceCommand voiceCmdQueue[16]; // size=64, offset=96
	unsigned char cdCmdIn; // size=0, offset=160
	unsigned char cdCmdOut; // size=0, offset=161
	unsigned char cdCmdsQueued; // size=0, offset=162
	unsigned char reqIn; // size=0, offset=163
	unsigned char reqOut; // size=0, offset=164
	unsigned char reqsQueued; // size=0, offset=165
	unsigned char voiceCmdIn; // size=0, offset=166
	unsigned char voiceCmdOut; // size=0, offset=167
	unsigned char voiceCmdsQueued; // size=0, offset=168
	unsigned char unused1; // size=0, offset=169
	unsigned char voiceStatus; // size=0, offset=170
	unsigned char cdStatus; // size=0, offset=171
	short fileNum; // size=0, offset=172
	short unused2; // size=0, offset=174
	struct XAFileInfo xaFileInfo[30]; // size=120, offset=176
};

typedef struct CdlFILTER CdlFILTER;

typedef struct SpuCommonAttr SpuCommonAttr;

typedef struct XAVoiceListEntry XAVoiceListEntry;

typedef struct XAVoiceTracker XAVoiceTracker;

typedef void (*VoiceCmdProc)();

struct cinema_fn_table_t // hashcode: 0x2963A004 (dec: 694394884)
{
	int (*play)(); // size=0, offset=0
	char *versionID; // size=0, offset=4
};

union CINEPSX_71fake // Hashcode: 0x25ED3A6A (dec: 636303978)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: cinepsx.o, cinepsx.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: cinepsx.o, cinepsx.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: cinepsx.o, cinepsx.o
};

union CINEPSX_72fake // Hashcode: 0xCE3741D3 (dec: -835239469)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct CINEPSX_109fake // hashcode: 0xB4189C9E (dec: -1273455458)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: cinepsx.o, cinepsx.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: cinepsx.o, cinepsx.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: cinepsx.o, cinepsx.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: cinepsx.o, cinepsx.o
};

union CINEPSX_183fake // Hashcode: 0xDFEDC6CE (dec: -538065202)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union CINEPSX_207fake // Hashcode: 0x8E885B9A (dec: -1903666278)
{
	unsigned short pad; // size=0, offset=0
	unsigned short multitap[16]; // size=32, offset=0
	unsigned short mouse[2]; // size=4, offset=0
	unsigned short negcon[3]; // size=6, offset=0
	struct AnalogueData analogue; // size=6, offset=0
};

typedef struct cinema_fn_table_t cinema_fn_table_t;

typedef int PlayCinematic_t();

enum language_t // Hashcode: 0xB438CA3E (dec: -1271346626)
{
	language_default = -1,
	language_english = 0,
	language_french = 1,
	language_german = 2,
	language_italian = 3,
	language_spanish = 4,
	language_num_states = 5,
};

enum localstr_t // Hashcode: 0x0DBA27A9 (dec: 230303657)
{
	LOCALSTR_BOGUS = 0,
	LOCALSTR_format_card = 1,
	LOCALSTR_accessing_card = 2,
	LOCALSTR_back = 3,
	LOCALSTR_cancel = 4,
	LOCALSTR_choose_load_file = 5,
	LOCALSTR_choose_save_file = 6,
	LOCALSTR_confirm = 7,
	LOCALSTR_continue = 8,
	LOCALSTR_controller = 9,
	LOCALSTR_create_file = 10,
	LOCALSTR_creating = 11,
	LOCALSTR_demos = 12,
	LOCALSTR_do_not_remove_card = 13,
	LOCALSTR_done = 14,
	LOCALSTR_exit_game = 15,
	LOCALSTR_formatting = 16,
	LOCALSTR_go_back = 17,
	LOCALSTR_insert_card = 18,
	LOCALSTR_insert_card_free = 19,
	LOCALSTR_invalid_card = 20,
	LOCALSTR_load_failed = 21,
	LOCALSTR_load_game = 22,
	LOCALSTR_loading = 23,
	LOCALSTR_music = 24,
	LOCALSTR_new_game = 25,
	LOCALSTR_no = 26,
	LOCALSTR_no_card = 27,
	LOCALSTR_no_room = 28,
	LOCALSTR_ok = 29,
	LOCALSTR_options = 30,
	LOCALSTR_overwrite_game = 31,
	LOCALSTR_paused = 32,
	LOCALSTR_press_start = 33,
	LOCALSTR_query_format_card = 34,
	LOCALSTR_query_overwrite = 35,
	LOCALSTR_query_quit = 36,
	LOCALSTR_quit_game = 37,
	LOCALSTR_resume_game = 38,
	LOCALSTR_save_failed = 39,
	LOCALSTR_save_game = 40,
	LOCALSTR_save_ok = 41,
	LOCALSTR_saving = 42,
	LOCALSTR_sound = 43,
	LOCALSTR_start_game = 44,
	LOCALSTR_start_new_game = 45,
	LOCALSTR_try_card_again = 46,
	LOCALSTR_unformatted_card = 47,
	LOCALSTR_vibration_off = 48,
	LOCALSTR_vibration_on = 49,
	LOCALSTR_voice = 50,
	LOCALSTR_warning_one = 51,
	LOCALSTR_warning_two = 52,
	LOCALSTR_yes = 53,
	LOCALSTR_Hint0 = 54,
	LOCALSTR_Hint1 = 55,
	LOCALSTR_Hint2 = 56,
	LOCALSTR_Hint3 = 57,
	LOCALSTR_Hint4 = 58,
	LOCALSTR_Hint5 = 59,
	LOCALSTR_Hint6 = 60,
	LOCALSTR_Hint7 = 61,
	LOCALSTR_Hint8 = 62,
	LOCALSTR_Hint9 = 63,
	LOCALSTR_Hint10 = 64,
	LOCALSTR_Hint11 = 65,
	LOCALSTR_Hint12 = 66,
	LOCALSTR_Hint13 = 67,
	LOCALSTR_Hint14 = 68,
	LOCALSTR_Hint15 = 69,
	LOCALSTR_Hint16 = 70,
	LOCALSTR_Hint17 = 71,
	LOCALSTR_Hint18 = 72,
	LOCALSTR_Hint19 = 73,
	LOCALSTR_Hint20 = 74,
	LOCALSTR_Hint21 = 75,
	LOCALSTR_Hint22 = 76,
	LOCALSTR_Hint23 = 77,
	LOCALSTR_Hint24 = 78,
	LOCALSTR_Hint25 = 79,
	LOCALSTR_Hint26 = 80,
	LOCALSTR_Hint27 = 81,
	LOCALSTR_Hint28 = 82,
	LOCALSTR_Hint29 = 83,
	LOCALSTR_Hint30 = 84,
	LOCALSTR_Hint31 = 85,
	LOCALSTR_Hint32 = 86,
	LOCALSTR_Hint33 = 87,
	LOCALSTR_Hint34 = 88,
	LOCALSTR_Hint35 = 89,
	LOCALSTR_Hint36 = 90,
	LOCALSTR_Hint37 = 91,
	LOCALSTR_Hint38 = 92,
	LOCALSTR_Hint39 = 93,
	LOCALSTR_Hint40 = 94,
	LOCALSTR_Hint41 = 95,
	LOCALSTR_Hint42 = 96,
	LOCALSTR_Hint43 = 97,
	LOCALSTR_Hint44 = 98,
	LOCALSTR_Hint45 = 99,
	LOCALSTR_Hint46 = 100,
	LOCALSTR_Hint47 = 101,
	LOCALSTR_Hint48 = 102,
	LOCALSTR_Hint49 = 103,
	LOCALSTR_Hint50 = 104,
	LOCALSTR_Hint51 = 105,
	LOCALSTR_EndOfHintStrings = 106,
	LOCALSTR_no_controller = 107,
	LOCALSTR_NUM_ITEMS = 108,
};

struct LocalizationHeader // hashcode: 0x86C8750F (dec: -2033683185)
{
	enum language_t language; // size=4, offset=0
	int numXAfiles; // size=0, offset=4
	int XATableOffset; // size=0, offset=8
	int numStrings; // size=0, offset=12
};

typedef enum language_t language_t;

typedef enum localstr_t localstr_t;

typedef struct LocalizationHeader LocalizationHeader;

enum menu_ctrl_t // Hashcode: 0x2C5050CB (dec: 743461067)
{
	menu_ctrl_none = 0,
	menu_ctrl_up = 1,
	menu_ctrl_down = 2,
	menu_ctrl_left = 3,
	menu_ctrl_right = 4,
	menu_ctrl_engage = 5,
	menu_ctrl_cancel = 6,
	menu_ctrl_start = 7,
	menu_ctrl_num_items = 8,
};

enum menu_sound_t // Hashcode: 0xE07891FA (dec: -528969222)
{
	menu_sound_none = 0,
	menu_sound_default = 1,
	menu_sound_select = 2,
	menu_sound_adjust = 3,
	menu_sound_engage = 4,
	menu_sound_pop = 5,
};

struct menu_t // hashcode: 0x3290E656 (dec: 848356950)
{
	int nmenus; // size=0, offset=0
	int nitems; // size=0, offset=4
	int nbytes; // size=0, offset=8
	struct menu_stack_t stack[5]; // size=180, offset=12
	struct menu_item_t items[12]; // size=192, offset=192
	char bytes[512]; // size=512, offset=384
	void (*drawfn)(); // size=0, offset=896
	void *opaque; // size=0, offset=900
};

union MENU_71fake // Hashcode: 0xAC5B6C8A (dec: -1403294582)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: menu.o, menu.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: menu.o, menu.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: menu.o, menu.o
};

union MENU_72fake // Hashcode: 0x09480D5D (dec: 155716957)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MENU_109fake // hashcode: 0x80B304BB (dec: -2135751493)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: menu.o, menu.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: menu.o, menu.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: menu.o, menu.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: menu.o, menu.o
};

struct menu_format_t // hashcode: 0x40A387C4 (dec: 1084458948)
{
	int xpos; // size=0, offset=0
	int ypos; // size=0, offset=4
	int lineskip; // size=0, offset=8
	int itemskip; // size=0, offset=12
	int width; // size=0, offset=16
	int center; // size=0, offset=20
	int border; // size=0, offset=24
};

struct menu_stack_t // hashcode: 0x9B2B9505 (dec: -1691642619)
{
	int (*fn)(); // size=0, offset=0
	int index; // size=0, offset=4
	struct menu_format_t format; // size=28, offset=8
};

struct menu_item_t // hashcode: 0xAE3D258D (dec: -1371724403)
{
	char *text; // size=0, offset=0
	int (*fn)(); // size=0, offset=4
	long parameter; // size=0, offset=8
	long flags; // size=0, offset=12
};

struct Extents2d // hashcode: 0xC91243F6 (dec: -921549834)
{
	int xmin; // size=0, offset=0
	int xmax; // size=0, offset=4
	int ymin; // size=0, offset=8
	int ymax; // size=0, offset=12
};

typedef enum menu_ctrl_t menu_ctrl_t;

typedef enum menu_sound_t menu_sound_t;

typedef struct menu_t menu_t;

typedef struct menu_format_t menu_format_t;

typedef struct menu_stack_t menu_stack_t;

typedef struct menu_item_t menu_item_t;

typedef struct Extents2d Extents2d;

typedef int menu_item_fn_t();

typedef void menu_draw_fn_t();

union MENUUTIL_71fake // Hashcode: 0xED43B2B1 (dec: -314330447)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: menuutil.o, menuutil.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: menuutil.o, menuutil.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: menuutil.o, menuutil.o
};

union MENUUTIL_72fake // Hashcode: 0x7FEC4CA1 (dec: 2146192545)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MENUUTIL_109fake // hashcode: 0xC7CB553C (dec: -942975684)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: menuutil.o, menuutil.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: menuutil.o, menuutil.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: menuutil.o, menuutil.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: menuutil.o, menuutil.o
};

struct menu_sound_entry_t // hashcode: 0xDBE287CC (dec: -605911092)
{
	enum menu_sound_t sound; // size=4, offset=0
	int sfx; // size=0, offset=4
};

typedef struct menu_sound_entry_t menu_sound_entry_t;

union MENUDEFS_71fake // Hashcode: 0xFC92848F (dec: -57506673)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: menudefs.o, menudefs.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: menudefs.o, menudefs.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: menudefs.o, menudefs.o
};

union MENUDEFS_72fake // Hashcode: 0x19577F96 (dec: 425164694)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MENUDEFS_109fake // hashcode: 0xAD9C997A (dec: -1382246022)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: menudefs.o, menudefs.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: menudefs.o, menudefs.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: menudefs.o, menudefs.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: menudefs.o, menudefs.o
};

enum sfx_t // Hashcode: 0x865BE503 (dec: -2040797949)
{
	sfx_sound = 0,
	sfx_music = 1,
	sfx_voice = 2,
	sfx_error = 3,
};

typedef enum sfx_t sfx_t;

union MENUFACE_71fake // Hashcode: 0x7504B00A (dec: 1963241482)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: menuface.o, menuface.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: menuface.o, menuface.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: menuface.o, menuface.o
};

union MENUFACE_72fake // Hashcode: 0x17657042 (dec: 392523842)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MENUFACE_109fake // hashcode: 0x4BDC7F6B (dec: 1272741739)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: menuface.o, menuface.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: menuface.o, menuface.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: menuface.o, menuface.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: menuface.o, menuface.o
};

struct menuface_t // hashcode: 0xD09068C2 (dec: -795842366)
{
	int x; // size=0, offset=0
	int y; // size=0, offset=4
	int w; // size=0, offset=8
	int h; // size=0, offset=12
	int loaded; // size=0, offset=16
};

typedef struct menuface_t menuface_t;

struct mcmenu_table_t // hashcode: 0x01EECDC1 (dec: 32427457)
{
	int (*data_size)(); // size=0, offset=0
	void (*initialize)(); // size=0, offset=4
	void (*terminate)(); // size=0, offset=8
	void (*begin)(); // size=0, offset=12
	void (*end)(); // size=0, offset=16
	int (*set_buffer)(); // size=0, offset=20
	int (*main)(); // size=0, offset=24
	int (*pause)(); // size=0, offset=28
	char *versionID; // size=0, offset=32
};

union MEMCARD_72fake // Hashcode: 0x7247A912 (dec: 1917298962)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: memcard.o, memcard.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: memcard.o, memcard.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: memcard.o, memcard.o
};

union MEMCARD_73fake // Hashcode: 0x816CBE1F (dec: -2123579873)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

struct MEMCARD_110fake // hashcode: 0x004E88F3 (dec: 5146867)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: memcard.o, memcard.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: memcard.o, memcard.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: memcard.o, memcard.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: memcard.o, memcard.o
};

struct memcard_t // hashcode: 0x0AD83860 (dec: 181942368)
{
	struct Object *object; // size=76, offset=0
	struct mcmenu_table_t *table; // size=36, offset=4
	struct mcmenu_t *mcmenu; // size=0, offset=8
	short running; // size=0, offset=12
	short wrongVerison; // size=0, offset=14
	struct GameTracker *gt; // size=648, offset=16
};

union MEMCARD_184fake // Hashcode: 0x1063ABE6 (dec: 274967526)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

typedef struct mcmenu_table_t mcmenu_table_t;

typedef struct memcard_t memcard_t;


#endif
