#ifndef LOAD3D_H
#define LOAD3D_H

extern void LOAD_InitCd();

extern void LOAD_CdSeekCallback(unsigned char intr, unsigned char *result);

extern void LOAD_CdDataReady();

extern void LOAD_CdReadReady(unsigned char intr, unsigned char *result);

extern void LOAD_UpdateCheckSum(long bytes);

extern void LOAD_DoCDReading();

extern void LOAD_DoCDBufferedReading();

extern void LOAD_SetupFileToDoCDReading();

extern void LOAD_SetupFileToDoBufferedCDReading();

extern void LOAD_ProcessReadQueue();

extern char *LOAD_ReadFileFromCD(char *filename, int memType);

extern void LOAD_CdReadFromBigFile(long fileOffset, unsigned long *loadAddr, long bytes, long chksumLevel, long checksum);

extern struct _BigFileDir *LOAD_ReadDirectory(struct _BigFileDirEntry *dirEntry);

extern void LOAD_InitCdLoader(char *bigFileName, char *voiceFileName);

extern int LOAD_SetupFileInfo(struct _NonBlockLoadEntry *loadEntry);

extern void LOAD_NonBlockingReadFile(struct _NonBlockLoadEntry *loadEntry);

extern void LOAD_CD_ReadPartOfFile(struct _NonBlockLoadEntry *loadEntry);

extern long LOAD_HashName(char *string);

extern long LOAD_HashUnit(char *name);

extern struct _BigFileEntry *LOAD_GetBigFileEntryByHash(long hash);

extern struct _BigFileEntry *LOAD_GetBigFileEntry(char *fileName);

extern long LOAD_DoesFileExist(char *fileName);

extern void LOAD_LoadTIM(long *addr, long x_pos, long y_pos, long clut_x, long clut_y);

extern void LOAD_LoadTIM2(long *addr, long x_pos, long y_pos, long width, long height);

extern long LOAD_RelocBinaryData(long *data, long fileSize);

extern void LOAD_CleanUpBuffers();

extern void *LOAD_InitBuffers();

extern void LOAD_InitCdStreamMode();

extern void LOAD_DumpCurrentDir();

extern int LOAD_ChangeDirectoryByID(int id);

extern void LOAD_SetSearchDirectory(long id);

extern long LOAD_GetSearchDirectory();

extern int LOAD_ChangeDirectoryFlag();

extern void LOAD_UpdateBigFilePointers(struct _BigFileDir *oldDir, struct _BigFileDir *newDir);

extern int LOAD_IsFileLoading();

extern void LOAD_StopLoad();

#endif
