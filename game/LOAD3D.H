#ifndef LOAD3D_H
#define LOAD3D_H


extern void LOAD_InitCd(); // 0x80037C64

extern void LOAD_CdSeekCallback(unsigned char intr, unsigned char *result); // 0x80037C94

extern void LOAD_CdDataReady(); // 0x80037CE0

extern void LOAD_CdReadReady(unsigned char intr, unsigned char *result); // 0x80037E04

extern void LOAD_UpdateCheckSum(long bytes); // 0x80037F60

extern void LOAD_DoCDReading(); // 0x80037FA4

extern void LOAD_DoCDBufferedReading(); // 0x80038050

extern void LOAD_SetupFileToDoCDReading(); // 0x8003806C

extern void LOAD_SetupFileToDoBufferedCDReading(); // 0x800380E8

extern void LOAD_ProcessReadQueue(); // 0x8003815C

extern char * LOAD_ReadFileFromCD(char *filename, int memType); // 0x80038330

extern void LOAD_CdReadFromBigFile(long fileOffset, unsigned long *loadAddr, long bytes, long chksumLevel, long checksum); // 0x8003842C

extern struct _BigFileDir * LOAD_ReadDirectory(struct _BigFileDirEntry *dirEntry); // 0x80038458

extern void LOAD_InitCdLoader(char *bigFileName, char *voiceFileName); // 0x800384DC

extern int LOAD_SetupFileInfo(struct _NonBlockLoadEntry *loadEntry); // 0x80038678

extern void LOAD_NonBlockingReadFile(struct _NonBlockLoadEntry *loadEntry); // 0x800386FC

extern void LOAD_CD_ReadPartOfFile(struct _NonBlockLoadEntry *loadEntry); // 0x80038780

extern long LOAD_HashName(char *string); // 0x80038824

extern long LOAD_HashUnit(char *name); // 0x8003897C

extern struct _BigFileEntry * LOAD_GetBigFileEntryByHash(long hash); // 0x80038A20

extern struct _BigFileEntry * LOAD_GetBigFileEntry(char *fileName); // 0x80038AA8

extern long LOAD_DoesFileExist(char *fileName); // 0x80038AD0

extern void LOAD_LoadTIM(long *addr, long x_pos, long y_pos, long clut_x, long clut_y); // 0x80038B04

extern void LOAD_LoadTIM2(long *addr, long x_pos, long y_pos, long width, long height); // 0x80038BA4

extern long LOAD_RelocBinaryData(long *data, long fileSize); // 0x80038BEC

extern void LOAD_CleanUpBuffers(); // 0x80038CA4

extern void * LOAD_InitBuffers(); // 0x80038CEC

extern void LOAD_InitCdStreamMode(); // 0x80038D28

extern int LOAD_ChangeDirectoryByID(int id); // 0x80038D70

extern void LOAD_SetSearchDirectory(long id); // 0x80038E6C

extern long LOAD_GetSearchDirectory(); // 0x80038E78

extern int LOAD_ChangeDirectoryFlag(); // 0x80038E84

extern void LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir, struct _BigFileDir *newDir); // 0x80038E90

extern int LOAD_IsFileLoading(); // 0x80038EC0

extern void LOAD_StopLoad(); // 0x80038ECC


#endif
