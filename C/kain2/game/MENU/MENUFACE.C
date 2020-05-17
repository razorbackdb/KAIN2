#include "THISDUST.H"
#include "MENUFACE.H"


// decompiled code
// original method signature: 
// char * /*$ra*/ NextTimAddr(char *addr /*$a0*/, int w /*$a1*/, int h /*$a2*/, enum bdepth bpp /*$a3*/)
 // line 25, offset 0x800b91b0
	/* begin block 1 */
		// Start line: 27
		// Start offset: 0x800B91B0
		// Variables:
	// 		long addtl; // $v0
	/* end block 1 */
	// End offset: 0x800B91EC
	// End Line: 34

	/* begin block 2 */
		// Start line: 50
	/* end block 2 */
	// End Line: 51

	/* begin block 3 */
		// Start line: 51
	/* end block 3 */
	// End Line: 52

	/* begin block 4 */
		// Start line: 52
	/* end block 4 */
	// End Line: 53

char * NextTimAddr(char *addr,int w,int h,bdepth bpp)

{
  int iVar1;
  
  if (bpp == TIM_4BIT) {
    iVar1 = (w * h >> 1) + 0x2c;
  }
  else {
    if (bpp == TIM_8BIT) {
      iVar1 = w * h + 0x20c;
    }
    else {
      iVar1 = w * h * 2;
    }
  }
  return addr + iVar1 + 0x14;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menuface_initialize()
 // line 70, offset 0x800b91f8
	/* begin block 1 */
		// Start line: 71
		// Start offset: 0x800B91F8
		// Variables:
	// 		char *addr; // $s6
	// 		char *buttonAddr; // $s2
	// 		int i; // $s5
	// 		int j; // $s1

		/* begin block 1.1 */
			// Start line: 83
			// Start offset: 0x800B9224
		/* end block 1.1 */
		// End offset: 0x800B92FC
		// End Line: 120
	/* end block 1 */
	// End offset: 0x800B92FC
	// End Line: 125

	/* begin block 2 */
		// Start line: 140
	/* end block 2 */
	// End Line: 141

	/* begin block 3 */
		// Start line: 149
	/* end block 3 */
	// End Line: 150

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menuface_initialize(void)

{
  uint uVar1;
  long *address;
  menuface_t *pmVar2;
  uint uVar3;
  long *addr;
  int iVar4;
  int iVar5;
  
  if ((hack_initialized == 0) &&
     (address = LOAD_ReadFile("\\kain2\\game\\psx\\frontend\\faces.tim",'\v'),
     address != (long *)0x0)) {
    FaceButtons = (_ButtonTexture *)MEMPACK_Malloc(0x380,'-');
    iVar5 = 0;
    if (FaceButtons == (_ButtonTexture *)0x0) {
      MEMPACK_Free((char *)address);
    }
    else {
      pmVar2 = &MenuFaces;
      iVar4 = 0;
      addr = address;
      do {
        uVar3 = 0;
        pmVar2->curFrame = -1;
        pmVar2->transitionDir = 0;
        pmVar2->loaded = 0;
        pmVar2->delay = 0;
        do {
          DRAW_LoadButton(addr,FaceButtons + iVar4 + uVar3);
          addr = (long *)NextTimAddr((char *)addr,(uint)(byte)pmVar2->w,(uint)(byte)pmVar2->h,
                                     TIM_4BIT);
          uVar1 = uVar3 & 0x1f;
          uVar3 = uVar3 + 1;
          pmVar2->loaded = pmVar2->loaded | (ushort)(1 << uVar1);
        } while ((int)uVar3 < 7);
        pmVar2 = pmVar2 + 1;
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 7;
      } while (iVar5 < 8);
      MEMPACK_Free((char *)address);
      hack_initialized = 1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menuface_terminate()
 // line 127, offset 0x800b9324
	/* begin block 1 */
		// Start line: 128
		// Start offset: 0x800B9324
		// Variables:
	// 		int i; // $s3
	// 		int j; // $s0
	/* end block 1 */
	// End offset: 0x800B93B4
	// End Line: 144

	/* begin block 2 */
		// Start line: 293
	/* end block 2 */
	// End Line: 294

	/* begin block 3 */
		// Start line: 296
	/* end block 3 */
	// End Line: 297

/* WARNING: Unknown calling convention yet parameter storage is locked */

void menuface_terminate(void)

{
  uint uVar1;
  menuface_t *pmVar2;
  int iVar3;
  int iVar4;
  
  if (hack_initialized != 0) {
    iVar4 = 0;
    iVar3 = 0;
    pmVar2 = &MenuFaces;
    do {
      uVar1 = 0;
      do {
        if (((int)(uint)pmVar2->loaded >> (uVar1 & 0x1f) & 1U) != 0) {
          DRAW_FreeButton(FaceButtons + iVar3 + uVar1);
        }
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < 7);
      iVar3 = iVar3 + 7;
      iVar4 = iVar4 + 1;
      pmVar2 = pmVar2 + 1;
    } while (iVar4 < 8);
    MEMPACK_Free((char *)FaceButtons);
    hack_initialized = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MENUFACE_ChangeStateRandomly(int index /*$a0*/)
 // line 149, offset 0x800b93d0
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x800B93D0
		// Variables:
	// 		struct menuface_t *face; // $s1
	// 		struct menuface_t *lastFace; // $s3

		/* begin block 1.1 */
			// Start line: 163
			// Start offset: 0x800B9428
		/* end block 1.1 */
		// End offset: 0x800B9480
		// End Line: 168
	/* end block 1 */
	// End offset: 0x800B94D8
	// End Line: 181

	/* begin block 2 */
		// Start line: 345
	/* end block 2 */
	// End Line: 346

	/* begin block 3 */
		// Start line: 348
	/* end block 3 */
	// End Line: 349

void MENUFACE_ChangeStateRandomly(int index)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  menuface_t *pmVar5;
  
  if (hack_initialized != 0) {
    pmVar5 = &MenuFaces;
    puVar4 = &MenuFaces.delay;
    do {
      uVar1 = *puVar4 - 1;
      if (*puVar4 == 0) {
        if (puVar4[-1] == 0) {
          iVar3 = rand();
          if (iVar3 == (iVar3 / 500) * 500) {
            if (puVar4[-2] == 0xffff) {
              puVar4[-1] = 1;
            }
            else {
              puVar4[-1] = 0xffff;
            }
          }
        }
        else {
          uVar2 = puVar4[-2] + puVar4[-1];
          puVar4[-2] = uVar2;
          uVar1 = 200;
          if (((int)(short)uVar2 == (uint)*(byte *)(puVar4 + -3) * 7 + -1) ||
             ((int)(short)uVar2 == -1)) {
            puVar4[-1] = 0;
            goto LAB_800b94c4;
          }
        }
      }
      else {
LAB_800b94c4:
        *puVar4 = uVar1;
      }
      pmVar5 = pmVar5 + 1;
      puVar4 = puVar4 + 8;
    } while (pmVar5 < &hack_initialized);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MENUFACE_RefreshFaces()
 // line 184, offset 0x800b94f4
	/* begin block 1 */
		// Start line: 185
		// Start offset: 0x800B94F4
		// Variables:
	// 		int i; // $s3
	// 		struct menuface_t *face; // $s2
	/* end block 1 */
	// End offset: 0x800B9580
	// End Line: 208

	/* begin block 2 */
		// Start line: 438
	/* end block 2 */
	// End Line: 439

	/* begin block 3 */
		// Start line: 446
	/* end block 3 */
	// End Line: 447

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
      if ((int)(uint)*(byte *)(psVar1 + 2) <= (int)psVar1[3]) {
        DRAW_DrawButton(FaceButtons + iVar2 + (int)psVar1[3] / (int)(uint)*(byte *)(psVar1 + 2),
                        pmVar3->x,*psVar1,gameTrackerX.drawOT + 1);
      }
      iVar2 = iVar2 + 7;
      iVar4 = iVar4 + 1;
      psVar1 = psVar1 + 8;
      pmVar3 = pmVar3 + 1;
    } while (iVar4 < 8);
  }
  return;
}





