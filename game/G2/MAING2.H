#ifndef MAING2_H
#define MAING2_H

#include "TYPES.H"

enum _G2Bool_Enum // Hashcode: 0x6B6BC2D2 (dec: 1802224338)
{
	G2FALSE = 0,
};

typedef enum _G2Bool_Enum G2Bool;

extern G2Bool MainG2_InitEngine(void *appData, uint screenWidth, uint screenHeight, char *filesystemName); // 0x800957CC

extern void MainG2_ShutDownEngine(void *appData); // 0x800957D4


#endif
