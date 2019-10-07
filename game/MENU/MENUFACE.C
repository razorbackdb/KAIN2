#include "THISDUST.H"
#include "MENUFACE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ menuface_initialize()
 // line 45, offset 0x800b7d3c
	/* begin block 1 */
		// Start line: 46
		// Start offset: 0x800B7D3C
		// Variables:
	// 		char prefix[8][4]; // stack offset -224
	// 		char postfix[3][8]; // stack offset -192
	// 		char facename[128]; // stack offset -168
	// 		int i; // $s3
	// 		int j; // $s0

		/* begin block 1.1 */
			// Start line: 65
			// Start offset: 0x800B7EA4
		/* end block 1.1 */
		// End offset: 0x800B7EA4
		// End Line: 65
	/* end block 1 */
	// End offset: 0x800B7F18
	// End Line: 76

	/* begin block 2 */
		// Start line: 90
	/* end block 2 */
	// End Line: 91

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menu_initialize(void)

{
  u_int uVar1;
  u_int uVar2;
  menuface_t *pmVar3;
  int iVar4;
  int iVar5;
  char acStack168 [128];
  
  if (hack_initialized == 0) {
    FaceButtons = (_ButtonTexture *)MEMPACK_Malloc(0x180,'-');
    iVar4 = 0;
    if (FaceButtons != (_ButtonTexture *)0x0) {
      pmVar3 = &MenuFaces;
      iVar5 = 0;
      do {
        uVar2 = 0;
        pmVar3->curFrame = -1;
        pmVar3->transitionDir = '\0';
        pmVar3->loaded = '\0';
        do {
          sprintf(acStack168,"\\kain2\\game\\psx\\frontend\\%s_%s.tim");
          DRAW_LoadButtonByName(acStack168,FaceButtons + iVar5 + uVar2);
          uVar1 = uVar2 & 0x1f;
          uVar2 = uVar2 + 1;
          pmVar3->loaded = pmVar3->loaded | (byte)(1 << uVar1);
        } while ((int)uVar2 < 3);
        pmVar3 = pmVar3 + 1;
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 3;
      } while (iVar4 < 8);
      hack_initialized = 1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menuface_terminate()
 // line 78, offset 0x800b7f44
	/* begin block 1 */
		// Start line: 79
		// Start offset: 0x800B7F44
		// Variables:
	// 		int i; // $s3
	// 		int j; // $s0
	/* end block 1 */
	// End offset: 0x800B7FD8
	// End Line: 95

	/* begin block 2 */
		// Start line: 181
	/* end block 2 */
	// End Line: 182

	/* begin block 3 */
		// Start line: 184
	/* end block 3 */
	// End Line: 185

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menuface_terminate(void)

{
  u_int uVar1;
  int iVar2;
  menuface_t *pmVar3;
  int iVar4;
  
  if (hack_initialized != 0) {
    iVar4 = 0;
    pmVar3 = &MenuFaces;
    iVar2 = 0;
    do {
      uVar1 = 0;
      do {
        if (((int)(u_int)pmVar3->loaded >> (uVar1 & 0x1f) & 1U) != 0) {
          DRAW_LoadButton(FaceButtons + iVar2 + uVar1);
        }
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < 3);
      pmVar3 = pmVar3 + 1;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 3;
    } while (iVar4 < 8);
    MEMPACK_Init((char *)FaceButtons);
    hack_initialized = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MENUFACE_ChangeStateRandomly(int index /*$a0*/)
 // line 100, offset 0x800b7ff4
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x800B7FF4
		// Variables:
	// 		struct menuface_t *face; // $s1
	// 		struct menuface_t *lastFace; // $s3

		/* begin block 1.1 */
			// Start line: 114
			// Start offset: 0x800B8050
		/* end block 1.1 */
		// End offset: 0x800B80A8
		// End Line: 119
	/* end block 1 */
	// End offset: 0x800B8100
	// End Line: 132

	/* begin block 2 */
		// Start line: 233
	/* end block 2 */
	// End Line: 234

	/* begin block 3 */
		// Start line: 236
	/* end block 3 */
	// End Line: 237

void MENUFACE_ChangeStateRandomly(int index)

{
  u_char uVar1;
  u_char uVar2;
  int iVar3;
  u_char *puVar4;
  menuface_t *pmVar5;
  
  if (hack_initialized != 0) {
    pmVar5 = &MenuFaces;
    puVar4 = &MenuFaces.delay;
    do {
      uVar1 = *puVar4 + -1;
      if (*puVar4 == '\0') {
        if (puVar4[-1] == '\0') {
          iVar3 = rand();
          if (iVar3 == (iVar3 / 0x96) * 0x96) {
            if (puVar4[-2] == -1) {
              puVar4[-1] = '\x01';
            }
            else {
              puVar4[-1] = -1;
            }
          }
        }
        else {
          uVar2 = puVar4[-2] + puVar4[-1];
          puVar4[-2] = uVar2;
          uVar1 = 'd';
          if (((int)(char)uVar2 == (u_int)puVar4[-3] * 3 + -1) || ((int)(char)uVar2 == -1)) {
            puVar4[-1] = '\0';
            goto LAB_800b80ec;
          }
        }
      }
      else {
LAB_800b80ec:
        *puVar4 = uVar1;
      }
      pmVar5 = pmVar5 + 1;
      puVar4 = puVar4 + 0xc;
    } while (pmVar5 < &hack_initialized);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MENUFACE_RefreshFaces()
 // line 135, offset 0x800b811c
	/* begin block 1 */
		// Start line: 136
		// Start offset: 0x800B811C
		// Variables:
	// 		int i; // $s3
	// 		struct menuface_t *face; // $s2
	/* end block 1 */
	// End offset: 0x800B81B0
	// End Line: 153

	/* begin block 2 */
		// Start line: 326
	/* end block 2 */
	// End Line: 327

	/* begin block 3 */
		// Start line: 330
	/* end block 3 */
	// End Line: 331

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MENUFACE_RefreshFaces(void)

{
  short *psVar1;
  int iVar2;
  menuface_t *pmVar3;
  int iVar4;
  
  if (hack_initialized != 0) {
    iVar4 = 0;
    pmVar3 = &MenuFaces;
    psVar1 = &MenuFaces.y;
    iVar2 = 0;
    do {
      if (-1 < (int)*(char *)((int)psVar1 + 5)) {
        DRAW_DrawButton(FaceButtons +
                        iVar2 + (int)*(char *)((int)psVar1 + 5) / (int)(u_int)*(byte *)(psVar1 + 2),
                        pmVar3->x,*psVar1,gameTrackerX.drawOT + 1);
      }
      iVar2 = iVar2 + 3;
      iVar4 = iVar4 + 1;
      psVar1 = psVar1 + 6;
      pmVar3 = pmVar3 + 1;
    } while (iVar4 < 8);
  }
  return;
}





