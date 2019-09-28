#include "THISDUST.H"
#include "MENUFACE.H"


// decompiled code
// original method signature: 
// char * /*$ra*/ NextTimAddr(char *addr /*$a0*/, int w /*$a1*/, int h /*$a2*/, enum bdepth bpp /*$a3*/)
 // line 25, offset 0x800b9538
	/* begin block 1 */
		// Start line: 27
		// Start offset: 0x800B9538
		// Variables:
	// 		long addtl; // $v0
	/* end block 1 */
	// End offset: 0x800B9574
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

int NextTimAddr(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_4 == 0) {
    iVar1 = (param_2 * param_3 >> 1) + 0x2c;
  }
  else {
    if (param_4 == 1) {
      iVar1 = param_2 * param_3 + 0x20c;
    }
    else {
      iVar1 = param_2 * param_3 * 2;
    }
  }
  return param_1 + iVar1 + 0x14;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menuface_initialize()
 // line 76, offset 0x800b9580
	/* begin block 1 */
		// Start line: 77
		// Start offset: 0x800B9580
		// Variables:
	// 		char *addr; // $s6
	// 		char *buttonAddr; // $s2
	// 		int i; // $s5
	// 		int j; // $s1

		/* begin block 1.1 */
			// Start line: 92
			// Start offset: 0x800B95AC
		/* end block 1.1 */
		// End offset: 0x800B9684
		// End Line: 134
	/* end block 1 */
	// End offset: 0x800B9684
	// End Line: 139

	/* begin block 2 */
		// Start line: 152
	/* end block 2 */
	// End Line: 153

	/* begin block 3 */
		// Start line: 161
	/* end block 3 */
	// End Line: 162

void menuface_initialize(void)

{
  long *plVar1;
  
  if ((iGpffffa088 == 0) &&
     (plVar1 = LOAD_ReadFile(s__kain2_game_psx_frontend_faces_t_800cfb40,'\v'),
     plVar1 != (long *)0x0)) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Malloc(0x380,'-');
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menuface_terminate()
 // line 141, offset 0x800b96ac
	/* begin block 1 */
		// Start line: 142
		// Start offset: 0x800B96AC
		// Variables:
	// 		int i; // $s3
	// 		int j; // $s0
	/* end block 1 */
	// End offset: 0x800B973C
	// End Line: 158

	/* begin block 2 */
		// Start line: 329
	/* end block 2 */
	// End Line: 330

	/* begin block 3 */
		// Start line: 332
	/* end block 3 */
	// End Line: 333

/* WARNING: Removing unreachable block (ram,0x800b972c) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void menuface_terminate(void)

{
  _ButtonTexture *in_a0;
  void *in_a1;
  int in_a2;
  void *in_a3;
  int local_18;
  uint uVar1;
  
  if (hack_initialized != 0) {
    uVar1 = 0;
    do {
      if (((int)(uint)DAT_800cfaca >> (uVar1 & 0x1f) & 1U) != 0) {
        in_a0 = (_ButtonTexture *)(_BlockVramEntry_800d5bec.udata + uVar1 * 0x10);
        DRAW_FreeButton(in_a0);
      }
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < 7);
    memcard_initialize((memcard_t *)in_a0,in_a1,in_a2,in_a3,local_18);
    return;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MENUFACE_ChangeStateRandomly(int index /*$a0*/)
 // line 163, offset 0x800b9758
	/* begin block 1 */
		// Start line: 164
		// Start offset: 0x800B9758
		// Variables:
	// 		struct menuface_t *face; // $s1
	// 		struct menuface_t *lastFace; // $s3

		/* begin block 1.1 */
			// Start line: 177
			// Start offset: 0x800B97B0
		/* end block 1.1 */
		// End offset: 0x800B9808
		// End Line: 182
	/* end block 1 */
	// End offset: 0x800B9860
	// End Line: 195

	/* begin block 2 */
		// Start line: 381
	/* end block 2 */
	// End Line: 382

	/* begin block 3 */
		// Start line: 384
	/* end block 3 */
	// End Line: 385

void MENUFACE_ChangeStateRandomly(int index)

{
  short sVar1;
  void *gt;
  int in_a1;
  short *psVar2;
  int *piVar3;
  
  if (hack_initialized != 0) {
    piVar3 = (int *)&MenuFaces;
    psVar2 = &DAT_800cfac8;
    do {
      sVar1 = *psVar2 + -1;
      if (*psVar2 == 0) {
        if (psVar2[-1] == 0) {
                    /* WARNING: Subroutine does not return */
          rand();
        }
        sVar1 = psVar2[-2];
        psVar2[-2] = sVar1 + psVar2[-1];
        gt = (void *)(int)(short)(sVar1 + psVar2[-1]);
        sVar1 = 200;
        if (gt == (void *)((uint)*(byte *)(psVar2 + -3) * 7 + -1)) {
          memcard_main_menu(gt,in_a1);
          return;
        }
        if (gt == (void *)0xffffffff) {
          psVar2[-1] = 0;
          goto LAB_800b984c;
        }
      }
      else {
LAB_800b984c:
        *psVar2 = sVar1;
      }
      piVar3 = piVar3 + 4;
      psVar2 = psVar2 + 8;
    } while (piVar3 < &hack_initialized);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MENUFACE_RefreshFaces()
 // line 198, offset 0x800b987c
	/* begin block 1 */
		// Start line: 199
		// Start offset: 0x800B987C
		// Variables:
	// 		int i; // $s3
	// 		struct menuface_t *face; // $s2
	/* end block 1 */
	// End offset: 0x800B9908
	// End Line: 218

	/* begin block 2 */
		// Start line: 474
	/* end block 2 */
	// End Line: 475

	/* begin block 3 */
		// Start line: 478
	/* end block 3 */
	// End Line: 479

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MENUFACE_RefreshFaces(void)

{
  void *gt;
  short *psVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  
  if (hack_initialized != 0) {
    iVar4 = 0;
    psVar3 = &MenuFaces;
    psVar1 = &DAT_800cfabe;
    iVar2 = 0;
    do {
      gt = (void *)(int)psVar1[3];
      if ((int)gt < (int)(uint)*(byte *)(psVar1 + 2)) {
        gt2mcmenu(gt);
        return;
      }
      DRAW_DrawButton((_ButtonTexture *)
                      (_BlockVramEntry_800d5bec.udata +
                      (iVar2 + (int)gt / (int)(uint)*(byte *)(psVar1 + 2)) * 0x10),*psVar3,*psVar1,
                      (ulong **)(theCamera.posSphere.position._0_4_ + 4));
      iVar2 = iVar2 + 7;
      iVar4 = iVar4 + 1;
      psVar1 = psVar1 + 8;
      psVar3 = psVar3 + 8;
    } while (iVar4 < 8);
  }
  return;
}





