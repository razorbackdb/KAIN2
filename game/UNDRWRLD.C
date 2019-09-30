#include "THISDUST.H"
#include "UNDRWRLD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ UNDERWORLD_StartProcess()
 // line 66, offset 0x800b34dc
	/* begin block 1 */
		// Start line: 132
	/* end block 1 */
	// End Line: 133

/* WARNING: Unknown calling convention yet parameter storage is locked */

void UNDERWORLD_StartProcess(void)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(gameTrackerX.playerInstance,0x40001,0);
}



// decompiled code
// original method signature: 
// long /*$ra*/ UNDERWORLD_RotateScreenStep(long time /*$s1*/)
 // line 86, offset 0x800b3554
	/* begin block 1 */
		// Start line: 87
		// Start offset: 0x800B3554
		// Variables:
	// 		int row; // $t2
	// 		int col; // $a3
	// 		int sinAngle; // $s0
	// 		int cosAngle; // $t3
	// 		int hx; // $v1
	// 		int hy; // $v0

		/* begin block 1.1 */
			// Start line: 102
			// Start offset: 0x800B35B4
			// Variables:
		// 		struct UW_ScreenXY *p; // $a0
		// 		int scaleY; // $t0
		/* end block 1.1 */
		// End offset: 0x800B35B4
		// End Line: 102
	/* end block 1 */
	// End offset: 0x800B36A8
	// End Line: 125

	/* begin block 2 */
		// Start line: 177
	/* end block 2 */
	// End Line: 178

	/* begin block 3 */
		// Start line: 183
	/* end block 3 */
	// End Line: 184

long UNDERWORLD_RotateScreenStep(long time)

{
  if ((gameTrackerX.vblCount != time) && (UW_scalex != 0)) {
                    /* WARNING: Subroutine does not return */
    rsin(UW_angle);
  }
  return time;
}



// decompiled code
// original method signature: 
// void /*$ra*/ UNDERWORLD_DoUV(unsigned char *uv /*$a0*/, struct UW_ScreenXY *p0 /*$a1*/, int tx /*$a2*/)
 // line 161, offset 0x800b36c0
	/* begin block 1 */
		// Start line: 163
		// Start offset: 0x800B36C0
		// Variables:
	// 		int u; // $v1
	/* end block 1 */
	// End offset: 0x800B3704
	// End Line: 173

	/* begin block 2 */
		// Start line: 362
	/* end block 2 */
	// End Line: 363

	/* begin block 3 */
		// Start line: 363
	/* end block 3 */
	// End Line: 364

void UNDERWORLD_DoUV(uchar *uv,UW_ScreenXY *p0,int tx)

{
  tx = p0->sx - tx;
  if (tx < 0x100) {
    *uv = (uchar)tx;
  }
  else {
    *uv = -1;
  }
  if (0xff < p0->sy) {
    uv[1] = -1;
    return;
  }
  uv[1] = *(uchar *)&p0->sy;
  return;
}



// decompiled code
// original method signature: 
// struct POLY_GT3 * /*$ra*/ UNDERWORLD_Poly(struct POLY_GT3 *last /*$s4*/, struct UW_ScreenXY *p0 /*$a1*/, struct UW_ScreenXY *p1 /*$s3*/, struct UW_ScreenXY *p2 /*$s2*/, int drawY /*stack 16*/)
 // line 175, offset 0x800b370c
	/* begin block 1 */
		// Start line: 176
		// Start offset: 0x800B370C
		// Variables:
	// 		int tx; // $s0
	// 		struct POLY_GT3 *poly; // $s1
	// 		int col; // $v1
	/* end block 1 */
	// End offset: 0x800B3794
	// End Line: 181

	/* begin block 2 */
		// Start line: 390
	/* end block 2 */
	// End Line: 391

POLY_GT3 * UNDERWORLD_Poly(POLY_GT3 *last,UW_ScreenXY *p0,UW_ScreenXY *p1,UW_ScreenXY *p2,int drawY)

{
  ushort uVar1;
  int iVar2;
  uint tx;
  
  uVar1 = p0->sx;
  if ((int)p0->sx < (int)p1->sx) {
    iVar2 = (int)p2->sx << 0x10;
    if ((int)p2->sx <= (int)p0->sx) goto SAVE_Instance;
  }
  else {
    iVar2 = (int)p2->sx << 0x10;
    uVar1 = p1->sx;
    if ((int)p2->sx <= (int)p1->sx) goto SAVE_Instance;
  }
  iVar2 = (uint)uVar1 << 0x10;
SAVE_Instance:
  tx = iVar2 >> 0x10 & 0xffffffc0;
  *(undefined *)((int)&last[1].tag + 3) = 9;
  last[1].code = '4';
  *(undefined4 *)&last[1].x0 = *(undefined4 *)&p0->dx;
  *(undefined4 *)&last[1].x1 = *(undefined4 *)&p1->dx;
  *(undefined4 *)&last[1].x2 = *(undefined4 *)&p2->dx;
  UNDERWORLD_DoUV(&last[1].u0,p0,tx);
  UNDERWORLD_DoUV(&last[1].u1,p1,tx);
  UNDERWORLD_DoUV(&last[1].u2,p2,tx);
                    /* WARNING: Subroutine does not return */
  GetTPage(2,1,tx,drawY);
}



// decompiled code
// original method signature: 
// void /*$ra*/ UNDERWORLD_DisplayFrame(long *primStart /*$a0*/, long drawY /*$s7*/)
 // line 222, offset 0x800b3884
	/* begin block 1 */
		// Start line: 223
		// Start offset: 0x800B3884
		// Variables:
	// 		long row; // $s5
	// 		long col; // $s0
	// 		long d; // $v0
	// 		struct UW_ScreenXY *p0; // $s2
	// 		struct UW_ScreenXY *p1; // $s1
	// 		struct UW_ScreenXY *p2; // $s3
	// 		struct UW_ScreenXY *p3; // $s4
	// 		struct POLY_GT3 *poly; // $a1
	// 		struct POLY_GT3 *terminator; // $fp
	/* end block 1 */
	// End offset: 0x800B3990
	// End Line: 267

	/* begin block 2 */
		// Start line: 526
	/* end block 2 */
	// End Line: 527

void UNDERWORLD_DisplayFrame(long *primStart,long drawY)

{
  UW_ScreenXY *p2;
  POLY_GT3 *last;
  int iVar1;
  UW_ScreenXY *p1;
  UW_ScreenXY *p2_00;
  UW_ScreenXY *p0;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = (uint *)(primStart + 10);
  iVar3 = 0;
  iVar4 = 0;
  *primStart = 0xffffff;
  do {
    iVar2 = 0;
    iVar1 = iVar4;
    do {
      p0 = (UW_ScreenXY *)(iVar1 * 8);
      p1 = p0 + 1;
      p2_00 = p0 + 4;
      p2 = p0 + 3;
      if (((iVar3 < 1) && (1 < iVar2)) || ((1 < iVar3 && (iVar2 < 1)))) {
        last = UNDERWORLD_Poly((POLY_GT3 *)primStart,p0,p1,p2,drawY);
        p0 = p1;
      }
      else {
        last = UNDERWORLD_Poly((POLY_GT3 *)primStart,p0,p1,p2_00,drawY);
      }
      primStart = (long *)UNDERWORLD_Poly(last,p0,p2_00,p2,drawY);
      iVar2 = iVar2 + 1;
      iVar1 = iVar4 + iVar2;
    } while (iVar2 < 2);
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 3;
  } while (iVar3 < 2);
                    /* WARNING: Subroutine does not return */
  *puVar5 = *puVar5 | 0xffffff;
  DrawOTag(primStart);
}



// decompiled code
// original method signature: 
// void /*$ra*/ UNDERWORLD_SetupSource()
 // line 272, offset 0x800b39dc
	/* begin block 1 */
		// Start line: 273
		// Start offset: 0x800B39DC
		// Variables:
	// 		struct RECT rect; // stack offset -32
	// 		struct DR_STP stp; // stack offset -24
	/* end block 1 */
	// End offset: 0x800B39DC
	// End Line: 273

	/* begin block 2 */
		// Start line: 691
	/* end block 2 */
	// End Line: 692

/* WARNING: Unknown calling convention yet parameter storage is locked */

void UNDERWORLD_SetupSource(void)

{
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined auStack24 [16];
  
  SetDrawStp((int)auStack24,1);
  DrawPrim((int)auStack24);
  local_1c = 0x200;
  local_20 = 0;
  local_1a = 0xf0;
  local_1e = (undefined2)(gameTrackerX.gameData.asmData.dispPage << 8);
  MoveImage((undefined4 *)&local_20,0,(gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8);
  SetDrawStp((int)auStack24,0);
  DrawPrim((int)auStack24);
                    /* WARNING: Subroutine does not return */
  DrawSync(0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ UNDERWORLD_InitDisplayProcess()
 // line 295, offset 0x800b3a8c
	/* begin block 1 */
		// Start line: 297
		// Start offset: 0x800B3A94
		// Variables:
	// 		int row; // $t0
	// 		int col; // $a1

		/* begin block 1.1 */
			// Start line: 306
			// Start offset: 0x800B3AE4
			// Variables:
		// 		struct UW_ScreenXY *p; // $v0
		/* end block 1.1 */
		// End offset: 0x800B3AE4
		// End Line: 306
	/* end block 1 */
	// End offset: 0x800B3B18
	// End Line: 314

	/* begin block 2 */
		// Start line: 745
	/* end block 2 */
	// End Line: 746

/* WARNING: Unknown calling convention yet parameter storage is locked */

void UNDERWORLD_InitDisplayProcess(void)

{
  int iVar1;
  
  do {
    do {
      iVar1 = CheckVolatile(gameTrackerX.drawTimerReturn);
    } while (iVar1 != 0);
    iVar1 = CheckVolatile(gameTrackerX.reqDisp);
  } while (iVar1 != 0);
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x48,'\x18');
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ UNDERWORLD_LoadLevel(char *baseAreaName /*$s0*/, struct GameTracker *gameTracker /*$s4*/)
 // line 324, offset 0x800b3b4c
	/* begin block 1 */
		// Start line: 325
		// Start offset: 0x800B3B4C
		// Variables:
	// 		struct _SVector offset; // stack offset -72
	// 		struct _StreamUnit *streamUnit; // $s3
	// 		long i; // $s1
	// 		long UW_time; // $s2

		/* begin block 1.1 */
			// Start line: 351
			// Start offset: 0x800B3C00
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _SVector *_v0; // $v0
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x800B3C00
		// End Line: 351

		/* begin block 1.2 */
			// Start line: 400
			// Start offset: 0x800B3D8C
			// Variables:
		// 		struct POLY_F4 poly; // stack offset -64
		// 		struct DR_TPAGE tpage; // stack offset -40
		/* end block 1.2 */
		// End offset: 0x800B3E18
		// End Line: 420
	/* end block 1 */
	// End offset: 0x800B3E18
	// End Line: 433

	/* begin block 2 */
		// Start line: 821
	/* end block 2 */
	// End Line: 822

_StreamUnit * UNDERWORLD_LoadLevel(char *baseAreaName,GameTracker *gameTracker)

{
                    /* WARNING: Subroutine does not return */
  STREAM_PollLoadQueue();
}



// decompiled code
// original method signature: 
// void /*$ra*/ UNDERWORLD_UpdatePlayer(struct Intro *playerIntro /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 438, offset 0x800b3e48
	/* begin block 1 */
		// Start line: 439
		// Start offset: 0x800B3E48
		// Variables:
	// 		struct _SVector offset; // stack offset -16

		/* begin block 1.1 */
			// Start line: 439
			// Start offset: 0x800B3E48
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $a3
		// 		struct _SVector *_v; // $a2
		// 		struct _Position *_v0; // $a2
		// 		struct _Position *_v1; // $a3
		/* end block 1.1 */
		// End offset: 0x800B3E48
		// End Line: 439
	/* end block 1 */
	// End offset: 0x800B3E48
	// End Line: 439

	/* begin block 2 */
		// Start line: 1085
	/* end block 2 */
	// End Line: 1086

void UNDERWORLD_UpdatePlayer(Intro *playerIntro,_Instance *instance)

{
  _SVector local_10;
  
  local_10.x = (playerIntro->position).x - (instance->position).x;
  local_10.y = (playerIntro->position).y - (instance->position).y;
  local_10.z = (playerIntro->position).z - (instance->position).z;
  STREAM_RelocateInstance(&gameTrackerX,instance,&local_10);
  return;
}





