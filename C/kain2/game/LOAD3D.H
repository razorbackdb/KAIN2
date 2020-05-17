#ifndef LOAD3D_H
#define LOAD3D_H


extern void LOAD_InitCd(); // 0x800372C8

extern void LOAD_CdSeekCallback(unsigned char intr, unsigned char *result); // 0x800372F8

extern void LOAD_CdDataReady(); // 0x80037344

extern void LOAD_CdReadReady(unsigned char intr, unsigned char *result); // 0x80037464

extern void LOAD_UpdateCheckSum(long bytes); // 0x800375C0

extern void LOAD_DoCDReading(); // 0x80037604

extern void LOAD_DoCDBufferedReading(); // 0x800376B0

extern void LOAD_SetupFileToDoCDReading(); // 0x800376CC

extern void LOAD_SetupFileToDoBufferedCDReading(); // 0x80037748

extern void LOAD_ProcessReadQueue(); // 0x800377BC

extern char * LOAD_ReadFileFromCD(char *filename, int memType); // 0x80037960

extern void LOAD_CdReadFromBigFile(long fileOffset, unsigned long *loadAddr, long bytes, long chksumLevel, long checksum); // 0x80037A40

extern struct _BigFileDir * LOAD_ReadDirectory(struct _BigFileDirEntry *dirEntry); // 0x80037A6C

extern void LOAD_InitCdLoader(char *bigFileName, char *voiceFileName); // 0x80037AD4

extern int LOAD_SetupFileInfo(struct _NonBlockLoadEntry *loadEntry); // 0x80037C28

extern void LOAD_NonBlockingReadFile(struct _NonBlockLoadEntry *loadEntry); // 0x80037CB0

extern void LOAD_CD_ReadPartOfFile(struct _NonBlockLoadEntry *loadEntry); // 0x80037D34

extern long LOAD_HashName(char *string); // 0x80037DD4

extern long LOAD_HashUnit(char *name); // 0x80037F28

extern struct _BigFileEntry * LOAD_GetBigFileEntryByHash(long hash); // 0x80037FCC

extern struct _BigFileEntry * LOAD_GetBigFileEntry(char *fileName); // 0x80038054

extern long LOAD_DoesFileExist(char *fileName); // 0x8003807C

extern void LOAD_LoadTIM(long *addr, long x_pos, long y_pos, long clut_x, long clut_y); // 0x800380B0

extern void LOAD_LoadTIM2(long *addr, long x_pos, long y_pos, long width, long height); // 0x80038150

extern long LOAD_RelocBinaryData(long *data, long fileSize); // 0x80038198

extern void LOAD_CleanUpBuffers(); // 0x80038250

extern void * LOAD_InitBuffers(); // 0x80038298

extern void LOAD_InitCdStreamMode(); // 0x800382D4

extern void LOAD_DumpCurrentDir(); // 0x8003831C

extern int LOAD_ChangeDirectoryByID(int id); // 0x8003836C

extern void LOAD_SetSearchDirectory(long id); // 0x80038474

extern long LOAD_GetSearchDirectory(); // 0x80038480

extern int LOAD_ChangeDirectoryFlag(); // 0x8003848C

extern void LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir, struct _BigFileDir *newDir); // 0x80038498

extern int LOAD_IsFileLoading(); // 0x800384C8

extern void LOAD_StopLoad(); // 0x800384D4


#endif
