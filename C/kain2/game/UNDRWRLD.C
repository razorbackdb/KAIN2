#include "THISDUST.H"
#include "UNDRWRLD.H"

// decompiled code
// original method signature:
// void /*$ra*/ UNDERWORLD_StartProcess()
// line 66, offset 0x800b4b90
/* begin block 1 */
// Start line: 132
/* end block 1 */
// End Line: 133

/* WARNING: Unknown calling convention yet parameter storage is locked */

void UNDERWORLD_StartProcess(void)

{
	FX_Start_Snow(0);
	FX_Start_Rain(0);
	/* WARNING: Subroutine does not return */
	INSTANCE_Post(DAT_800d0fd8, (int)&DAT_00040001, 0);
}

// decompiled code
// original method signature:
// long /*$ra*/ UNDERWORLD_RotateScreenStep(long time /*$s1*/)
// line 93, offset 0x800b4c14
/* begin block 1 */
// Start line: 94
// Start offset: 0x800B4C14
// Variables:
// 		int row; // $t2
// 		int col; // $a3
// 		int sinAngle; // $s0
// 		int cosAngle; // $t3
// 		int hx; // $v1
// 		int hy; // $v0

/* begin block 1.1 */
// Start line: 109
// Start offset: 0x800B4C74
// Variables:
// 		struct UW_ScreenXY *p; // $a0
// 		int scaleY; // $t0
/* end block 1.1 */
// End offset: 0x800B4C74
// End Line: 109
/* end block 1 */
// End offset: 0x800B4D68
// End Line: 132

/* begin block 2 */
// Start line: 186
/* end block 2 */
// End Line: 187

/* begin block 3 */
// Start line: 192
/* end block 3 */
// End Line: 193

long UNDERWORLD_RotateScreenStep(long time)

{
	if ((DAT_800d10e4 != time) && (_BlockVramEntry_800d59a0.area != 0))
	{
		/* WARNING: Subroutine does not return */
		rsin(_BlockVramEntry_800d59a0._16_4_);
	}
	return time;
}

// decompiled code
// original method signature:
// void /*$ra*/ UNDERWORLD_DoUV(unsigned char *uv /*$a0*/, struct UW_ScreenXY *p0 /*$a1*/, int tx /*$a2*/)
// line 168, offset 0x800b4d80
/* begin block 1 */
// Start line: 170
// Start offset: 0x800B4D80
// Variables:
// 		int u; // $v1
/* end block 1 */
// End offset: 0x800B4DC4
// End Line: 180

/* begin block 2 */
// Start line: 371
/* end block 2 */
// End Line: 372

/* begin block 3 */
// Start line: 372
/* end block 3 */
// End Line: 373

void UNDERWORLD_DoUV(uchar *uv, UW_ScreenXY *p0, int tx)

{
	tx = p0->sx - tx;
	if (tx < 0x100)
	{
		*uv = (uchar)tx;
	}
	else
	{
		*uv = -1;
	}
	if (0xff < p0->sy)
	{
		uv[1] = -1;
		return;
	}
	uv[1] = *(uchar *)&p0->sy;
	return;
}

// decompiled code
// original method signature:
// struct POLY_GT3 * /*$ra*/ UNDERWORLD_Poly(struct POLY_GT3 *last /*$s4*/, struct UW_ScreenXY *p0 /*$a1*/, struct UW_ScreenXY *p1 /*$s3*/, struct UW_ScreenXY *p2 /*$s2*/, int drawY /*stack 16*/)
// line 182, offset 0x800b4dcc
/* begin block 1 */
// Start line: 183
// Start offset: 0x800B4DCC
// Variables:
// 		int tx; // $s0
// 		struct POLY_GT3 *poly; // $s1
// 		int col; // $v1
/* end block 1 */
// End offset: 0x800B4E54
// End Line: 188

/* begin block 2 */
// Start line: 399
/* end block 2 */
// End Line: 400

POLY_GT3 *UNDERWORLD_Poly(POLY_GT3 *last, UW_ScreenXY *p0, UW_ScreenXY *p1, UW_ScreenXY *p2, int drawY)

{
	ushort uVar1;
	int iVar2;
	uint tx;
	POLY_GT3 *pPVar3;

	uVar1 = p0->sx;
	pPVar3 = last + 1;
	if ((int)p0->sx < (int)p1->sx)
	{
		iVar2 = (int)p2->sx << 0x10;
		if ((int)p2->sx <= (int)p0->sx)
			goto LAB_800b4e50;
	}
	else
	{
		iVar2 = (int)p2->sx << 0x10;
		uVar1 = p1->sx;
		if ((int)p2->sx <= (int)p1->sx)
			goto LAB_800b4e50;
	}
	iVar2 = (uint)uVar1 << 0x10;
LAB_800b4e50:
	tx = iVar2 >> 0x10 & 0xffffffc0;
	*(undefined *)((int)&last[1].tag + 3) = 9;
	last[1].code = '4';
	*(undefined4 *)&last[1].x0 = *(undefined4 *)&p0->dx;
	*(undefined4 *)&last[1].x1 = *(undefined4 *)&p1->dx;
	*(undefined4 *)&last[1].x2 = *(undefined4 *)&p2->dx;
	UNDERWORLD_DoUV(&last[1].u0, p0, tx);
	UNDERWORLD_DoUV(&last[1].u1, p1, tx);
	UNDERWORLD_DoUV(&last[1].u2, p2, tx);
	tx = GetTPage(2, 1, tx, drawY);
	last[1].tpage = (ushort)tx;
	last[1].r0 = '\x10';
	last[1].g0 = '\x10';
	last[1].b0 = '\x10';
	last[1].r1 = '\x10';
	last[1].g1 = '\x10';
	last[1].b1 = '\x10';
	last[1].r2 = '\x10';
	last[1].g2 = '\x10';
	last[1].b2 = '\x10';
	pPVar3->tag = pPVar3->tag & 0xff000000 | (uint)last & 0xffffff;
	last[1].code = last[1].code | 2;
	return pPVar3;
}

// decompiled code
// original method signature:
// void /*$ra*/ UNDERWORLD_DisplayFrame(long *primStart /*$a0*/, long drawY /*$s7*/)
// line 229, offset 0x800b4f44
/* begin block 1 */
// Start line: 230
// Start offset: 0x800B4F44
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
// End offset: 0x800B5050
// End Line: 274

/* begin block 2 */
// Start line: 535
/* end block 2 */
// End Line: 536

void UNDERWORLD_DisplayFrame(long *primStart, long drawY)

{
	POLY_GT3 *last;
	int iVar1;
	UW_ScreenXY *p0;
	int iVar2;
	UW_ScreenXY *p1;
	UW_ScreenXY *p2;
	UW_ScreenXY *p2_00;
	int iVar3;
	int iVar4;
	uint *puVar5;

	puVar5 = (uint *)(primStart + 10);
	iVar3 = 0;
	iVar4 = 0;
	*primStart = 0xffffff;
	do
	{
		iVar2 = 0;
		iVar1 = iVar4;
		do
		{
			p0 = ScreenMorphArray + iVar1;
			p1 = ScreenMorphArray + iVar1 + 1;
			p2 = ScreenMorphArray + iVar1 + 4;
			p2_00 = ScreenMorphArray + iVar1 + 3;
			if (((iVar3 < 1) && (1 < iVar2)) || ((1 < iVar3 && (iVar2 < 1))))
			{
				last = UNDERWORLD_Poly((POLY_GT3 *)primStart, p0, p1, p2_00, drawY);
				p0 = p1;
			}
			else
			{
				last = UNDERWORLD_Poly((POLY_GT3 *)primStart, p0, p1, p2, drawY);
			}
			primStart = (long *)UNDERWORLD_Poly(last, p0, p2, p2_00, drawY);
			iVar2 = iVar2 + 1;
			iVar1 = iVar4 + iVar2;
		} while (iVar2 < 2);
		iVar3 = iVar3 + 1;
		iVar4 = iVar4 + 3;
	} while (iVar3 < 2);
	*puVar5 = *puVar5 | 0xffffff;
	DrawOTag(primStart);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ UNDERWORLD_SetupSource()
// line 279, offset 0x800b509c
/* begin block 1 */
// Start line: 280
// Start offset: 0x800B509C
// Variables:
// 		struct RECT rect; // stack offset -32
// 		struct DR_STP stp; // stack offset -24
/* end block 1 */
// End offset: 0x800B509C
// End Line: 280

/* begin block 2 */
// Start line: 700
/* end block 2 */
// End Line: 701

/* WARNING: Unknown calling convention yet parameter storage is locked */

void UNDERWORLD_SetupSource(void)

{
	undefined2 local_20;
	undefined2 local_1e;
	undefined2 local_1c;
	undefined2 local_1a;
	undefined auStack24[16];

	SetDrawStp((int)auStack24, 1);
	DrawPrim((int)auStack24);
	local_1c = 0x200;
	local_20 = 0;
	local_1a = 0xf0;
	local_1e = (undefined2)(DAT_800d0fb0 << 8);
	MoveImage((undefined4 *)&local_20, 0, (DAT_800d0fb0 ^ 1) << 8);
	SetDrawStp((int)auStack24, 0);
	DrawPrim((int)auStack24);
	DrawSync(0);
	PutDrawEnv((undefined4 *)(&draw + DAT_800d0fb0));
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ UNDERWORLD_InitDisplayProcess()
// line 302, offset 0x800b5148
/* begin block 1 */
// Start line: 304
// Start offset: 0x800B5150
// Variables:
// 		int row; // $t0
// 		int col; // $a1

/* begin block 1.1 */
// Start line: 313
// Start offset: 0x800B51A0
// Variables:
// 		struct UW_ScreenXY *p; // $v0
/* end block 1.1 */
// End offset: 0x800B51A0
// End Line: 313
/* end block 1 */
// End offset: 0x800B51D4
// End Line: 321

/* begin block 2 */
// Start line: 754
/* end block 2 */
// End Line: 755

void UNDERWORLD_InitDisplayProcess(void)

{
	int iVar1;

	do
	{
		do
		{
			iVar1 = CheckVolatile(uGpffffb614);
		} while (iVar1 != 0);
		iVar1 = CheckVolatile(uGpffffb610);
	} while (iVar1 != 0);
	/* WARNING: Subroutine does not return */
	MEMPACK_Malloc(0x48, '\x18');
}

// decompiled code
// original method signature:
// struct _StreamUnit * /*$ra*/ UNDERWORLD_LoadLevel(char *baseAreaName /*$s0*/, struct GameTracker *gameTracker /*$s4*/)
// line 331, offset 0x800b5208
/* begin block 1 */
// Start line: 332
// Start offset: 0x800B5208
// Variables:
// 		struct _SVector offset; // stack offset -72
// 		struct _StreamUnit *streamUnit; // $s3
// 		long i; // $s1
// 		long UW_time; // $s2

/* begin block 1.1 */
// Start line: 368
// Start offset: 0x800B52B8
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $a1
// 		struct _SVector *_v0; // $v0
// 		struct _Position *_v1; // $v0
/* end block 1.1 */
// End offset: 0x800B52B8
// End Line: 368

/* begin block 1.2 */
// Start line: 419
// Start offset: 0x800B5444
// Variables:
// 		struct POLY_F4 poly; // stack offset -64
// 		struct DR_TPAGE tpage; // stack offset -40
/* end block 1.2 */
// End offset: 0x800B54D0
// End Line: 439
/* end block 1 */
// End offset: 0x800B54D0
// End Line: 452

/* begin block 2 */
// Start line: 830
/* end block 2 */
// End Line: 831

_StreamUnit *UNDERWORLD_LoadLevel(char *baseAreaName, GameTracker *gameTracker)

{
	int iVar1;
	long time;
	_StreamUnit *streamUnit;
	_MultiSignal *p_Var2;

	time = DAT_800d10e4;
	while (iVar1 = STREAM_PollLoadQueue(), iVar1 != 0)
	{
		time = UNDERWORLD_RotateScreenStep(time);
	}
	LOAD_ChangeDirectory(baseAreaName);
	streamUnit = STREAM_LoadLevel(baseAreaName, (StreamUnitPortal *)0x0, 0);
	while (iVar1 = STREAM_PollLoadQueue(), iVar1 != 0)
	{
		time = UNDERWORLD_RotateScreenStep(time);
	}
	p_Var2 = streamUnit->level->startUnitMainSignal;
	if (p_Var2 != (_MultiSignal *)0x0)
	{
		SIGNAL_HandleSignal(gameTracker->playerInstance, p_Var2->signalList, 0);
	}
	STREAM_LoadMainVram(gameTracker, s_under1_800cf898, streamUnit);
	/* WARNING: Subroutine does not return */
	INSTANCE_Post(gameTracker->playerInstance, (int)&DAT_00040001, streamUnit->level->streamUnitID);
}

// decompiled code
// original method signature:
// void /*$ra*/ UNDERWORLD_UpdatePlayer(struct Intro *playerIntro /*$a0*/, struct _Instance *instance /*$a2*/)
// line 461, offset 0x800b5500
/* begin block 1 */
// Start line: 462
// Start offset: 0x800B5500
// Variables:
// 		struct _SVector offset; // stack offset -16

/* begin block 1.1 */
// Start line: 462
// Start offset: 0x800B5500
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $t0
// 		short _z1; // $a3
// 		struct _SVector *_v; // $a1
// 		struct _Position *_v0; // $a1
// 		struct _Position *_v1; // $a3
/* end block 1.1 */
// End offset: 0x800B5500
// End Line: 462
/* end block 1 */
// End offset: 0x800B5500
// End Line: 462

/* begin block 2 */
// Start line: 1127
/* end block 2 */
// End Line: 1128

void UNDERWORLD_UpdatePlayer(Intro *playerIntro, _Instance *instance)

{
	_SVector local_10;

	local_10.x = (playerIntro->position).x - (instance->position).x;
	local_10.y = (playerIntro->position).y - (instance->position).y;
	local_10.z = (playerIntro->position).z - (instance->position).z;
	STREAM_RelocateInstance(instance, &local_10);
	return;
}
