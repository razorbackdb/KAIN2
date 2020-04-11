
#include "CINEPSX.H"


// decompiled code
// original method signature: 
// int /*$ra*/ CINE_CDIntrQuery()
 // line 40, offset 0x800b60c8
	/* begin block 1 */
		// Start line: 80
	/* end block 1 */
	// End Line: 81

	/* begin block 2 */
		// Start line: 81
	/* end block 2 */
	// End Line: 82

/* File: C:\kain2\game\CINEMA\CINEPSX.C */

int CINE_CDIntrQuery(void)

{
  if (StCdIntrFlag != 0) {
    StCdIntrFlag = 0;
    return 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ CINE_Pad(int pad /*$a0*/)
 // line 51, offset 0x800b60f0
	/* begin block 1 */
		// Start line: 102
	/* end block 1 */
	// End Line: 103

	/* begin block 2 */
		// Start line: 103
	/* end block 2 */
	// End Line: 104

/* File: C:\kain2\game\CINEMA\CINEPSX.C */

ushort CINE_Pad(int pad)

{
  if (pad == 0) {
    return DAT_800d1dfa;
  }
  return DAT_800d1e42;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CINE_Play(char *strfile /*$a0*/, unsigned short mask /*$a1*/, int buffers /*$a2*/)
 // line 62, offset 0x800b6114
	/* begin block 1 */
		// Start line: 63
		// Start offset: 0x800B6114

		/* begin block 1.1 */
			// Start line: 74
			// Start offset: 0x800B615C
		/* end block 1.1 */
		// End offset: 0x800B6168
		// End Line: 75
	/* end block 1 */
	// End offset: 0x800B6168
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

/* File: C:\kain2\game\CINEMA\CINEPSX.C */

void CINE_Play(char *strfile,ushort mask,int buffers)

{
  undefined2 in_register_00000016;
  
  if (the_cine_table != (cinema_fn_table_t *)0x0) {
    if (the_cine_table->versionID == monVersion) {
      (*(code *)the_cine_table->play)(strfile,(uint)mask);
      LOAD_InitCdStreamMode();
    }
    else {
      printf(s_CINEMA___Version_number_is_wrong_800122fc,CONCAT22(in_register_00000016,mask));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CINE_Load()
 // line 79, offset 0x800b6178
	/* begin block 1 */
		// Start line: 80
		// Start offset: 0x800B6178
		// Variables:
	// 		struct _ObjectTracker *tracker; // $s1
	// 		int attempts; // $s0

		/* begin block 1.1 */
			// Start line: 95
			// Start offset: 0x800B61D8
		/* end block 1.1 */
		// End offset: 0x800B61F4
		// End Line: 105
	/* end block 1 */
	// End offset: 0x800B6204
	// End Line: 106

	/* begin block 2 */
		// Start line: 162
	/* end block 2 */
	// End Line: 163

/* File: C:\kain2\game\CINEMA\CINEPSX.C */

int CINE_Load(void)

{
  bool bVar1;
  _ObjectTracker *p_Var2;
  int iVar3;
  
  iVar3 = 0;
  p_Var2 = (_ObjectTracker *)STREAM_GetObjectTracker(s_cinemax_8001233c);
  do {
    bVar1 = iVar3 < 400;
    if (p_Var2->objectStatus == 2) break;
    iVar3 = iVar3 + 1;
    STREAM_PollLoadQueue();
    VSync(0);
    bVar1 = iVar3 < 400;
  } while (bVar1);
  if (!bVar1) {
    printf(s_cinema_timeout_80012344);
  }
  else {
    the_cine_table = (cinema_fn_table_t *)p_Var2->object->relocModule;
    the_cine_tracker = p_Var2;
  }
  return (uint)bVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CINE_Loaded()
 // line 108, offset 0x800b621c
	/* begin block 1 */
		// Start line: 238
	/* end block 1 */
	// End Line: 239

	/* begin block 2 */
		// Start line: 239
	/* end block 2 */
	// End Line: 240

/* File: C:\kain2\game\CINEMA\CINEPSX.C */

int CINE_Loaded(void)

{
  return (uint)(the_cine_tracker != (_ObjectTracker *)0x0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ CINE_Unload()
 // line 113, offset 0x800b622c
	/* begin block 1 */
		// Start line: 248
	/* end block 1 */
	// End Line: 249

/* File: C:\kain2\game\CINEMA\CINEPSX.C */

void CINE_Unload(void)

{
  VSyncCallback(VblTick);
  the_cine_table = (cinema_fn_table_t *)0x0;
  if (the_cine_tracker != (_ObjectTracker *)0x0) {
    STREAM_DumpObject((_ObjectTracker *)the_cine_tracker);
    the_cine_tracker = (_ObjectTracker *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CINE_PlayIngame(int number /*$a2*/)
 // line 126, offset 0x800b6274
	/* begin block 1 */
		// Start line: 127
		// Start offset: 0x800B6274
		// Variables:
	// 		char movie_name[24]; // stack offset -32
	/* end block 1 */
	// End offset: 0x800B62B4
	// End Line: 138

	/* begin block 2 */
		// Start line: 278
	/* end block 2 */
	// End Line: 279

/* File: C:\kain2\game\CINEMA\CINEPSX.C */

void CINE_PlayIngame(int number)

{
  int iVar1;
  char acStack32 [24];
  
  sprintf(acStack32,s__CHRONO_d_STR_1_80012354,number);
  iVar1 = CINE_Load();
  if (iVar1 != 0) {
    CINE_Play(acStack32,0,2);
    CINE_Unload();
  }
  return;
}





