#include "THISDUST.H"
#include "MENUFACE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ menuface_initialize()
 // line 39, offset 0x800b3600
	/* begin block 1 */
		// Start line: 40
		// Start offset: 0x800B3600
		// Variables:
	// 		char facename[128]; // stack offset -224
	// 		int i; // $s2
	// 		int j; // $s1
	// 		char prefix[8][4]; // stack offset -96
	// 		char postfix[3][8]; // stack offset -64

		/* begin block 1.1 */
			// Start line: 58
			// Start offset: 0x800B3794
		/* end block 1.1 */
		// End offset: 0x800B3794
		// End Line: 58
	/* end block 1 */
	// End offset: 0x800B37F4
	// End Line: 65

	/* begin block 2 */
		// Start line: 78
	/* end block 2 */
	// End Line: 79

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menuface_initialize(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  menuface_t *pmVar5;
  char acStack224 [128];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_60 = 0x4131;
  local_5c = 0x4231;
  local_58 = 0x4331;
  local_54 = 0x4132;
  local_50 = 0x4232;
  local_4c = 0x4133;
  local_48 = 0x4233;
  local_44 = 0x4333;
  local_40 = 0x3164696d;
  local_3c = 0;
  local_38 = 0x3264696d;
  local_34 = 0;
  local_30 = 0x706d76;
  local_2c = 0;
  if (hack_initialized == 0) {
    FaceState = MEMPACK_Malloc(8,'-');
    FaceStateDir = MEMPACK_Malloc(8,'-');
    FaceButtons = (_ButtonTexture *)MEMPACK_Malloc(0x180,'-');
    iVar3 = 0;
    pmVar5 = &the_faces;
    iVar4 = 0;
    do {
      iVar2 = 0;
      FaceState[iVar3] = -1;
      FaceStateDir[iVar3] = '\x01';
      do {
        sprintf(acStack224,"\\kain2\\game\\psx\\frontend\\%s_%s.tim");
        iVar1 = iVar4 + iVar2;
        iVar2 = iVar2 + 1;
        DRAW_LoadButtonByName(acStack224,FaceButtons + iVar1);
        *(undefined4 *)&pmVar5[1].w = 1;
      } while (iVar2 < 3);
      pmVar5 = (menuface_t *)&pmVar5[1].transitionDir;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 3;
    } while (iVar3 < 8);
    hack_initialized = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menuface_terminate()
 // line 67, offset 0x800b3820
	/* begin block 1 */
		// Start line: 68
		// Start offset: 0x800B3820
		// Variables:
	// 		int i; // $s4
	// 		int j; // $s0
	/* end block 1 */
	// End offset: 0x800B38F4
	// End Line: 89

	/* begin block 2 */
		// Start line: 162
	/* end block 2 */
	// End Line: 163

	/* begin block 3 */
		// Start line: 165
	/* end block 3 */
	// End Line: 166

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menuface_terminate(void)

{
  int iVar1;
  int iVar2;
  menuface_t *pmVar3;
  int iVar4;
  int iVar5;
  
  if (hack_initialized != 0) {
    iVar5 = 0;
    pmVar3 = &the_faces;
    iVar4 = 0;
    do {
      if (*(int *)&pmVar3[1].w != 0) {
        iVar2 = 0;
        do {
          iVar1 = iVar4 + iVar2;
          iVar2 = iVar2 + 1;
          DRAW_FreeButton(FaceButtons + iVar1);
        } while (iVar2 < 3);
        *(undefined4 *)&pmVar3[1].w = 0;
      }
      pmVar3 = (menuface_t *)&pmVar3[1].transitionDir;
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 3;
    } while (iVar5 < 8);
    if (FaceState != (char *)0x0) {
      MEMPACK_Free(FaceState);
    }
    if (FaceStateDir != (char *)0x0) {
      MEMPACK_Free(FaceStateDir);
    }
    if (FaceButtons != (_ButtonTexture *)0x0) {
      MEMPACK_Free((char *)FaceButtons);
    }
    hack_initialized = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MENUFACE_ChangeStateRandomly(int index /*$a0*/)
 // line 94, offset 0x800b3914
	/* begin block 1 */
		// Start line: 95
		// Start offset: 0x800B3914
		// Variables:
	// 		int i; // $s0
	// 		int inMorph; // $v1
	// 		static int oldIndex; // offset 0x100

		/* begin block 1.1 */
			// Start line: 114
			// Start offset: 0x800B3970
			// Variables:
		// 		int j; // $a0

			/* begin block 1.1.1 */
				// Start line: 118
				// Start offset: 0x800B3970
			/* end block 1.1.1 */
			// End offset: 0x800B3988
			// End Line: 118

			/* begin block 1.1.2 */
				// Start line: 123
				// Start offset: 0x800B39B0
			/* end block 1.1.2 */
			// End offset: 0x800B39C8
			// End Line: 123
		/* end block 1.1 */
		// End offset: 0x800B3A6C
		// End Line: 138
	/* end block 1 */
	// End offset: 0x800B3A6C
	// End Line: 140

	/* begin block 2 */
		// Start line: 231
	/* end block 2 */
	// End Line: 232

void MENUFACE_ChangeStateRandomly(int index)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = false;
  if (DAT_800d0d9c != index) {
    iVar5 = 0;
    pbVar2 = (byte *)FaceState;
    do {
      if (*pbVar2 < 0xe) {
        bVar1 = true;
      }
      iVar5 = iVar5 + 1;
      pbVar2 = (byte *)(FaceState + iVar5);
    } while (iVar5 < 8);
    DAT_800d0d9c = index;
    if (!bVar1) {
      do {
        iVar3 = rand();
        iVar5 = iVar3;
        if (iVar3 < 0) {
          iVar5 = iVar3 + 7;
        }
        iVar3 = iVar3 + (iVar5 >> 3) * -8;
      } while (FaceState[iVar3] == '\x0e');
      do {
        iVar4 = rand();
        iVar5 = iVar4;
        if (iVar4 < 0) {
          iVar5 = iVar4 + 7;
        }
        iVar4 = iVar4 + (iVar5 >> 3) * -8;
      } while ((iVar4 == iVar3) || (FaceState[iVar4] == '\x0e'));
      FaceState[iVar3] = '\0';
      FaceStateDir[iVar3] = '\x01';
      FaceState[iVar4] = '\0';
      iVar5 = 0;
      FaceStateDir[iVar4] = '\x01';
      do {
        if (FaceState[iVar5] == '\x0e') {
          FaceStateDir[iVar5] = -1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MENUFACE_RefreshFaces()
 // line 142, offset 0x800b3a80
	/* begin block 1 */
		// Start line: 143
		// Start offset: 0x800B3A80
		// Variables:
	// 		int i; // $s0
	// 		struct menuface_t *face; // $a2
	/* end block 1 */
	// End offset: 0x800B3BAC
	// End Line: 165

	/* begin block 2 */
		// Start line: 353
	/* end block 2 */
	// End Line: 354

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MENUFACE_RefreshFaces(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  do {
    pcVar1 = FaceState + iVar2;
    if (*pcVar1 != -1) {
      if (FaceStateDir[iVar2] < '\x01') {
        *pcVar1 = *pcVar1 + -1;
        if (FaceState[iVar2] < -1) {
          FaceState[iVar2] = -1;
        }
      }
      else {
        *pcVar1 = *pcVar1 + '\x01';
        if ('\x0e' < FaceState[iVar2]) {
          FaceState[iVar2] = '\x0e';
        }
      }
      DRAW_DrawButton(FaceButtons + iVar4 + (((int)FaceState[iVar2] / 5) * 0x1000000 >> 0x18),
                      *(short *)((int)&the_faces.x + iVar3),*(short *)(&the_faces.w + iVar3),
                      (ulong **)gameTrackerX.defVVRemoveDist);
    }
    iVar4 = iVar4 + 3;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar2 < 8);
  return;
}





