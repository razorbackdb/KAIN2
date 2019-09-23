#include "THISDUST.H"
#include "CINEPSX.H"

// cinema_fn_table_t * @0x800CAD90, len = 0x00000004
the_cine_table = 00000000;
// _ObjectTracker * @0x800CAD94, len = 0x00000004
the_cine_tracker = 00000000;
// decompiled code
// original method signature:
// int /*$ra*/ CINE_CDIntrQuery()
// line 40, offset 0x800b777c
/* begin block 1 */
// Start line: 80
/* end block 1 */
// End Line: 81

/* begin block 2 */
// Start line: 81
/* end block 2 */
// End Line: 82

/* WARNING: Unknown calling convention yet parameter storage is locked */

int CINE_CDIntrQuery(void)

{
	if (StCdIntrFlag != 0)
	{
		StCdIntrFlag = 0;
		return 1;
	}
	return 0;
}

// decompiled code
// original method signature:
// unsigned short /*$ra*/ CINE_Pad(int pad /*$a0*/)
// line 51, offset 0x800b77a4
/* begin block 1 */
// Start line: 102
/* end block 1 */
// End Line: 103

/* begin block 2 */
// Start line: 103
/* end block 2 */
// End Line: 104

ushort CINE_Pad(int pad)

{
	if (pad == 0)
	{
		return readGPBuffer1.data._0_2_;
	}
	return readGPBuffer2.data._0_2_;
}

// decompiled code
// original method signature:
// void /*$ra*/ CINE_Play(char *strfile /*$a0*/, unsigned short mask /*$a1*/, int buffers /*$a2*/)
// line 62, offset 0x800b77c8
/* begin block 1 */
// Start line: 63
// Start offset: 0x800B77C8

/* begin block 1.1 */
// Start line: 74
// Start offset: 0x800B7810
/* end block 1.1 */
// End offset: 0x800B781C
// End Line: 75
/* end block 1 */
// End offset: 0x800B781C
// End Line: 77

/* begin block 2 */
// Start line: 119
/* end block 2 */
// End Line: 120

/* begin block 3 */
// Start line: 126
/* end block 3 */
// End Line: 127

/* begin block 4 */
// Start line: 128
/* end block 4 */
// End Line: 129

void CINE_Play(char *strfile, ushort mask, int buffers)

{
	if (the_cine_table != (cinema_fn_table_t *)0x0)
	{
		if (the_cine_table->versionID == &monVersion)
		{
			(*the_cine_table->play)(strfile, (uint)mask);
			LOAD_InitCdStreamMode();
		}
		else
		{
			printf(s_CINEMA___Version_number_is_wrong_8001242c);
		}
	}
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ CINE_Load()
// line 79, offset 0x800b782c
/* begin block 1 */
// Start line: 80
// Start offset: 0x800B782C
// Variables:
// 		struct _ObjectTracker *tracker; // $s1
// 		int attempts; // $s0

/* begin block 1.1 */
// Start line: 95
// Start offset: 0x800B788C
/* end block 1.1 */
// End offset: 0x800B78A8
// End Line: 105
/* end block 1 */
// End offset: 0x800B78B8
// End Line: 106

/* begin block 2 */
// Start line: 162
/* end block 2 */
// End Line: 163

/* WARNING: Unknown calling convention yet parameter storage is locked */

int CINE_Load(void)

{
	bool bVar1;
	_ObjectTracker *p_Var2;
	int iVar3;

	iVar3 = 0;
	p_Var2 = STREAM_GetObjectTracker(s_cinemax_8001246c);
	do
	{
		bVar1 = iVar3 < 400;
		if (p_Var2->objectStatus == 2)
			break;
		iVar3 = iVar3 + 1;
		STREAM_PollLoadQueue();
		VSync(0);
		bVar1 = iVar3 < 400;
	} while (bVar1);
	if (!bVar1)
	{
		printf(s_cinema_timeout_80012474);
	}
	else
	{
		the_cine_table = (cinema_fn_table_t *)p_Var2->object->relocModule;
		the_cine_tracker = p_Var2;
	}
	return (uint)bVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ CINE_Loaded()
// line 108, offset 0x800b78d0
/* begin block 1 */
// Start line: 238
/* end block 1 */
// End Line: 239

/* begin block 2 */
// Start line: 239
/* end block 2 */
// End Line: 240

/* WARNING: Unknown calling convention yet parameter storage is locked */

int CINE_Loaded(void)

{
	return (uint)(the_cine_tracker != (_ObjectTracker *)0x0);
}

// decompiled code
// original method signature:
// void /*$ra*/ CINE_Unload()
// line 113, offset 0x800b78e0
/* begin block 1 */
// Start line: 248
/* end block 1 */
// End Line: 249

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CINE_Unload(void)

{
	VSyncCallback(VblTick);
	the_cine_table = (cinema_fn_table_t *)0x0;
	if (the_cine_tracker != (_ObjectTracker *)0x0)
	{
		STREAM_DumpObject(the_cine_tracker);
		the_cine_tracker = (_ObjectTracker *)0x0;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ CINE_PlayIngame(int number /*$a2*/)
// line 126, offset 0x800b7928
/* begin block 1 */
// Start line: 127
// Start offset: 0x800B7928
// Variables:
// 		char movie_name[24]; // stack offset -32
/* end block 1 */
// End offset: 0x800B7968
// End Line: 138

/* begin block 2 */
// Start line: 278
/* end block 2 */
// End Line: 279

void CINE_PlayIngame(int number)

{
	int iVar1;
	char acStack32[24];

	sprintf(acStack32, s__CHRONO_d_STR_1_80012484);
	iVar1 = CINE_Load();
	if (iVar1 != 0)
	{
		CINE_Play(acStack32, 0, 2);
		CINE_Unload();
	}
	return;
}
