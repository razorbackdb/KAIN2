
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

/* File: C:\kain2\game\MENU\MENUFACE.C */

void menuface_initialize(void)

{
  uint uVar1;
  uint uVar2;
  menuface_t *pmVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined *local_e0 [4];
  undefined *local_d0;
  undefined *local_cc;
  undefined *local_c8;
  undefined *local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined *local_b0;
  undefined4 local_ac;
  char acStack168 [128];
  
  local_e0[0] = PTR_DAT_800d0dc8;
  local_e0[1] = PTR_DAT_800d0dcc;
  local_e0[2] = PTR_DAT_800d0dd0;
  local_e0[3] = PTR_DAT_800d0dd4;
  local_d0 = PTR_DAT_800d0dd8;
  local_cc = PTR_DAT_800d0ddc;
  local_c8 = PTR_DAT_800d0de0;
  local_c4 = PTR_DAT_800d0de4;
  local_c0 = DAT_800d0de8;
  local_bc = DAT_800d0dec;
  local_b8 = DAT_800d0df0;
  local_b4 = DAT_800d0df4;
  local_b0 = PTR_DAT_800d0df8;
  local_ac = DAT_800d0dfc;
  if (hack_initialized == 0) {
    FaceButtons = MEMPACK_Malloc(0x180,'-');
    iVar5 = 0;
    if (FaceButtons != (char *)0x0) {
      pmVar3 = MenuFaces;
      iVar6 = 0;
      do {
        uVar2 = 0;
        pmVar3->curFrame = -1;
        pmVar3->transitionDir = '\0';
        pmVar3->loaded = '\0';
        puVar4 = &local_c0;
        do {
          sprintf(acStack168,s__kain2_game_psx_frontend__s__s_t_800d0e00,local_e0 + iVar5,puVar4);
          puVar4 = puVar4 + 2;
          DRAW_LoadButtonByName(acStack168,(_ButtonTexture *)(FaceButtons + (iVar6 + uVar2) * 0x10))
          ;
          uVar1 = uVar2 & 0x1f;
          uVar2 = uVar2 + 1;
          pmVar3->loaded = pmVar3->loaded | (byte)(1 << uVar1);
        } while ((int)uVar2 < 3);
        pmVar3 = pmVar3 + 1;
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 3;
      } while (iVar5 < 8);
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

/* File: C:\kain2\game\MENU\MENUFACE.C */

void menuface_terminate(void)

{
  uint uVar1;
  int iVar2;
  menuface_t *pmVar3;
  int iVar4;
  
  if (hack_initialized != 0) {
    iVar4 = 0;
    pmVar3 = MenuFaces;
    iVar2 = 0;
    do {
      uVar1 = 0;
      do {
        if (((int)(uint)pmVar3->loaded >> (uVar1 & 0x1f) & 1U) != 0) {
          DRAW_FreeButton((_ButtonTexture *)(FaceButtons + (iVar2 + uVar1) * 0x10));
        }
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < 3);
      pmVar3 = pmVar3 + 1;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 3;
    } while (iVar4 < 8);
    MEMPACK_Free(FaceButtons);
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

/* File: C:\kain2\game\MENU\MENUFACE.C */

void MENUFACE_ChangeStateRandomly(int index)

{
  uchar uVar1;
  uchar uVar2;
  int iVar3;
  uchar *puVar4;
  menuface_t *pmVar5;
  
  if (hack_initialized != 0) {
    pmVar5 = MenuFaces;
    puVar4 = &MenuFaces[0].delay;
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
          if (((int)(char)uVar2 == (uint)puVar4[-3] * 3 + -1) || ((int)(char)uVar2 == -1)) {
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

/* File: C:\kain2\game\MENU\MENUFACE.C */

void MENUFACE_RefreshFaces(void)

{
  short *psVar1;
  int iVar2;
  menuface_t *pmVar3;
  int iVar4;
  
  if (hack_initialized != 0) {
    iVar4 = 0;
    pmVar3 = MenuFaces;
    psVar1 = &MenuFaces[0].y;
    iVar2 = 0;
    do {
      if (-1 < (int)*(char *)((int)psVar1 + 5)) {
        DRAW_DrawButton((_ButtonTexture *)
                        (FaceButtons +
                        (iVar2 + (int)*(char *)((int)psVar1 + 5) / (int)(uint)*(byte *)(psVar1 + 2))
                        * 0x10),pmVar3->x,*psVar1,(ulong **)(DAT_800d22a4 + 4));
      }
      iVar2 = iVar2 + 3;
      iVar4 = iVar4 + 1;
      psVar1 = psVar1 + 6;
      pmVar3 = pmVar3 + 1;
    } while (iVar4 < 8);
  }
  return;
}





