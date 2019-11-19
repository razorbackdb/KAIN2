#include "THISDUST.H"
#include "CINEPSX.H"


// decompiled code
// original method signature: 
// int /*$ra*/ CINE_CDIntrQuery()
 // line 40, offset 0x800b18d0
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
  if (StCdIntrFlag != 0) {
    StCdIntrFlag = 0;
    return 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ CINE_Pad(int pad /*$a0*/)
 // line 51, offset 0x800b18f8
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
  if (pad == 0) {
    return readGPBuffer1.data._0_2_;
  }
  return readGPBuffer2.data._0_2_;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CINE_Play(char *strfile /*$a0*/, unsigned short mask /*$a1*/, int buffers /*$a2*/)
 // line 62, offset 0x800b191c
	/* begin block 1 */
		// Start line: 63
		// Start offset: 0x800B191C

		/* begin block 1.1 */
			// Start line: 74
			// Start offset: 0x800B1964
		/* end block 1.1 */
		// End offset: 0x800B1970
		// End Line: 75
	/* end block 1 */
	// End offset: 0x800B1970
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

void CINE_Play(char *strfile,ushort mask,int buffers)

{
  if (the_cine_table != (cinema_fn_table_t *)0x0) {
    if (the_cine_table->versionID == "May 12 1999") {
      (*the_cine_table->play)(strfile,(uint)mask);
      LOAD_InitCdStreamMode();
    }
    else {
      printf("CINEMA : Version number is wrong. Not playing the cinematics.\n");
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CINE_Load()
 // line 79, offset 0x800b1980
	/* begin block 1 */
		// Start line: 80
		// Start offset: 0x800B1980
		// Variables:
	// 		struct _ObjectTracker *tracker; // $s1
	// 		int attempts; // $s0

		/* begin block 1.1 */
			// Start line: 95
			// Start offset: 0x800B19E0
		/* end block 1.1 */
		// End offset: 0x800B1A08
		// End Line: 105
	/* end block 1 */
	// End offset: 0x800B1A18
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
  p_Var2 = STREAM_GetObjectTracker("cinemax");
  do {
    bVar1 = iVar3 < 400;
    if (p_Var2->objectStatus == 2) break;
    iVar3 = iVar3 + 1;
    STREAM_PollLoadQueue();
    VSync(0);
    bVar1 = iVar3 < 400;
  } while (bVar1);
  if (!bVar1) {
    printf("cinema timeout\n");
  }
  else {
    the_cine_table = (cinema_fn_table_t *)p_Var2->object->relocModule;
    the_cine_tracker = p_Var2;
    FlushCache();
    ExitCriticalSection();
  }
  return (uint)bVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CINE_Unload()
 // line 108, offset 0x800b1a30
	/* begin block 1 */
		// Start line: 238
	/* end block 1 */
	// End Line: 239

/* WARNING: Unknown calling convention yet parameter storage is locked */

void CINE_Unload(void)

{
  VSyncCallback(VblTick);
  the_cine_table = (cinema_fn_table_t *)0x0;
  if (the_cine_tracker != (_ObjectTracker *)0x0) {
    STREAM_DumpObject(the_cine_tracker);
    the_cine_tracker = (_ObjectTracker *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CINE_PlayIngame(int number /*$s0*/)
 // line 121, offset 0x800b1a78
	/* begin block 1 */
		// Start line: 268
	/* end block 1 */
	// End Line: 269

void CINE_PlayIngame(int number)

{
  int iVar1;
  
  iVar1 = CINE_Load();
  if (iVar1 != 0) {
    CINE_Play("\\CRYLOGO.STR;1",0x4001,2);
    CINE_Unload();
  }
  return;
}





