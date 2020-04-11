#ifndef LOAD3D_H
#define LOAD3D_H


extern void LOAD_InitCd(); // 0x800371CC

extern void LOAD_CdSeekCallback(unsigned char intr, unsigned char *result); // 0x800371FC

extern void LOAD_CdDataReady(); // 0x80037248

extern void LOAD_CdReadReady(unsigned char intr, unsigned char *result); // 0x8003736C

extern void LOAD_UpdateCheckSum(long bytes); // 0x800374C8

extern void LOAD_DoCDReading(); // 0x8003750C

extern void LOAD_DoCDBufferedReading(); // 0x800375B8

extern void LOAD_SetupFileToDoCDReading(); // 0x800375D4

extern void LOAD_SetupFileToDoBufferedCDReading(); // 0x80037650

extern void LOAD_ProcessReadQueue(); // 0x800376C4

extern char * LOAD_ReadFileFromCD(char *filename, int memType); // 0x80037868

extern void LOAD_CdReadFromBigFile(long fileOffset, unsigned long *loadAddr, long bytes, long chksumLevel, long checksum); // 0x80037948

extern struct _BigFileDir * LOAD_ReadDirectory(struct _BigFileDirEntry *dirEntry); // 0x80037974

extern void LOAD_InitCdLoader(char *bigFileName, char *voiceFileName); // 0x800379DC

extern int LOAD_SetupFileInfo(struct _NonBlockLoadEntry *loadEntry); // 0x80037B34

extern void LOAD_NonBlockingReadFile(struct _NonBlockLoadEntry *loadEntry); // 0x80037BBC

extern void LOAD_CD_ReadPartOfFile(struct _NonBlockLoadEntry *loadEntry); // 0x80037C40

extern long LOAD_HashName(char *string); // 0x80037CE4

extern long LOAD_HashUnit(char *name); // 0x80037E3C

extern struct _BigFileEntry * LOAD_GetBigFileEntryByHash(long hash); // 0x80037EE0

extern struct _BigFileEntry * LOAD_GetBigFileEntry(char *fileName); // 0x80037F68

extern long LOAD_DoesFileExist(char *fileName); // 0x80037F90

extern void LOAD_LoadTIM(long *addr, long x_pos, long y_pos, long clut_x, long clut_y); // 0x80037FC4

extern void LOAD_LoadTIM2(long *addr, long x_pos, long y_pos, long width, long height); // 0x80038064

extern long LOAD_RelocBinaryData(long *data, long fileSize); // 0x800380AC

extern void LOAD_CleanUpBuffers(); // 0x80038164

extern void * LOAD_InitBuffers(); // 0x800381AC

extern void LOAD_InitCdStreamMode(); // 0x800381E8

extern void LOAD_DumpCurrentDir(); // 0x80038230

extern int LOAD_ChangeDirectoryByID(int id); // 0x80038280

extern void LOAD_SetSearchDirectory(long id); // 0x80038388

extern long LOAD_GetSearchDirectory(); // 0x80038394

extern int LOAD_ChangeDirectoryFlag(); // 0x800383A0

extern void LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir, struct _BigFileDir *newDir); // 0x800383AC

extern int LOAD_IsFileLoading(); // 0x800383DC

extern void LOAD_StopLoad(); // 0x800383E8


#endif
