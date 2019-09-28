// WARNING: This file's extension ('.S') indicates that it may not have been a C or C++ file.
// It should contain Ghidra's best effort at decompiling the machine language to C, 
// but TDR does not currently attempt to handle assembly language or other non-C/C++ code differently, 
// so any decompiled code below may not reflect the original project source code for this file.
// If the source file is from a library, you should replace it with the original library version of the file.
// Otherwise, manual reconstruction of the code may be required, 
// Especially if the original source code was assembly language which used hardware features inaccessible to C.
#include "THISDUST.H"
#include "SNMAIN.H"


// decompiled code
// original method signature: 
// void __SN_ENTRY_POINT() /* __SN_ENTRY_POINT method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 39, offset 0x800b6d2c
	/* begin block 1 */
		// Start line: 79
	/* end block 1 */
	// End Line: 80

	/* begin block 2 */
		// Start line: 80
	/* end block 2 */
	// End Line: 81

	/* begin block 3 */
		// Start line: 81
	/* end block 3 */
	// End Line: 82

	/* begin block 4 */
		// Start line: 82
	/* end block 4 */
	// End Line: 83

	/* begin block 5 */
		// Start line: 83
	/* end block 5 */
	// End Line: 84

	/* begin block 6 */
		// Start line: 84
	/* end block 6 */
	// End Line: 85

	/* begin block 7 */
		// Start line: 85
	/* end block 7 */
	// End Line: 86

	/* begin block 8 */
		// Start line: 86
	/* end block 8 */
	// End Line: 87

	/* begin block 9 */
		// Start line: 87
	/* end block 9 */
	// End Line: 88

	/* begin block 10 */
		// Start line: 88
	/* end block 10 */
	// End Line: 89

	/* begin block 11 */
		// Start line: 89
	/* end block 11 */
	// End Line: 90

	/* begin block 12 */
		// Start line: 90
	/* end block 12 */
	// End Line: 91

	/* begin block 13 */
		// Start line: 91
	/* end block 13 */
	// End Line: 92

	/* begin block 14 */
		// Start line: 92
	/* end block 14 */
	// End Line: 93

	/* begin block 15 */
		// Start line: 93
	/* end block 15 */
	// End Line: 94

	/* begin block 16 */
		// Start line: 94
	/* end block 16 */
	// End Line: 95

	/* begin block 17 */
		// Start line: 95
	/* end block 17 */
	// End Line: 96

	/* begin block 18 */
		// Start line: 96
	/* end block 18 */
	// End Line: 97

	/* begin block 19 */
		// Start line: 97
	/* end block 19 */
	// End Line: 98

	/* begin block 20 */
		// Start line: 98
	/* end block 20 */
	// End Line: 99

	/* begin block 21 */
		// Start line: 99
	/* end block 21 */
	// End Line: 100

	/* begin block 22 */
		// Start line: 100
	/* end block 22 */
	// End Line: 101

	/* begin block 23 */
		// Start line: 101
	/* end block 23 */
	// End Line: 102

	/* begin block 24 */
		// Start line: 102
	/* end block 24 */
	// End Line: 103

	/* begin block 25 */
		// Start line: 103
	/* end block 25 */
	// End Line: 104

	/* begin block 26 */
		// Start line: 104
	/* end block 26 */
	// End Line: 105

	/* begin block 27 */
		// Start line: 105
	/* end block 27 */
	// End Line: 106

	/* begin block 28 */
		// Start line: 106
	/* end block 28 */
	// End Line: 107

	/* begin block 29 */
		// Start line: 107
	/* end block 29 */
	// End Line: 108

	/* begin block 30 */
		// Start line: 108
	/* end block 30 */
	// End Line: 109

	/* begin block 31 */
		// Start line: 109
	/* end block 31 */
	// End Line: 110

	/* begin block 32 */
		// Start line: 110
	/* end block 32 */
	// End Line: 111

	/* begin block 33 */
		// Start line: 111
	/* end block 33 */
	// End Line: 112

	/* begin block 34 */
		// Start line: 112
	/* end block 34 */
	// End Line: 113

	/* begin block 35 */
		// Start line: 113
	/* end block 35 */
	// End Line: 114

	/* begin block 36 */
		// Start line: 114
	/* end block 36 */
	// End Line: 115

	/* begin block 37 */
		// Start line: 115
	/* end block 37 */
	// End Line: 116

	/* begin block 38 */
		// Start line: 116
	/* end block 38 */
	// End Line: 117

	/* begin block 39 */
		// Start line: 117
	/* end block 39 */
	// End Line: 118

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void start(void)

{
  int iVar1;
  DebugMenuLine *pDVar2;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined *puVar3;
  undefined4 unaff_retaddr;
  undefined4 uVar4;
  
  pDVar2 = &eventMenu;
  do {
    pDVar2->type = DEBUG_LINE_TYPE_BIT;
    pDVar2 = (DebugMenuLine *)&pDVar2->lower;
  } while (pDVar2 < (DebugMenuLine *)&DAT_800dd340);
  puVar3 = (undefined *)(_ramsize - 8U | 0x80000000);
  ___heapsize = ((_ramsize - 8U) - _stacksize) + -0xdd340;
  ___heapbase = &DAT_800dd340;
  _BlockVramEntry_800d5ab8.udata = unaff_retaddr;
                    /* WARNING: Read-only address (ram,0x800d5ad0) is written */
  InitHeap(*puVar3);
  uVar4 = 0x800b6dd0;
  main(*puVar3);
  iVar1 = ___initialised;
  trap(1);
  *(undefined4 *)(puVar3 + -0xc) = unaff_s0;
  *(undefined4 *)(puVar3 + -8) = unaff_s1;
  *(undefined4 *)(puVar3 + -4) = uVar4;
  if (iVar1 == 0) {
    ___initialised = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void __main() /* __main method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
 // line 145, offset 0x800b6dd4
	/* begin block 1 */
		// Start line: 291
	/* end block 1 */
	// End Line: 292

	/* begin block 2 */
		// Start line: 292
	/* end block 2 */
	// End Line: 293

	/* begin block 3 */
		// Start line: 293
	/* end block 3 */
	// End Line: 294

	/* begin block 4 */
		// Start line: 294
	/* end block 4 */
	// End Line: 295

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __main(void)

{
  if (___initialised == 0) {
    ___initialised = 1;
  }
  return;
}



// autogenerated function stub: 
// void __initialised() /* __initialised method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __initialised() 
{ // line 181, offset 0x800cad6c
	/* begin block 1 */
		// Start line: 363
	/* end block 1 */
	// End Line: 364

	return null;
}


// autogenerated function stub: 
// void __heapbase() /* __heapbase method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __heapbase() 
{ // line 183, offset 0x800cad70
	return null;
}


// autogenerated function stub: 
// void __heapsize() /* __heapsize method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __heapsize() 
{ // line 184, offset 0x800cad74
	return null;
}


// autogenerated function stub: 
// void __text() /* __text method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __text() 
{ // line 185, offset 0x800cad78
	return null;
}


// autogenerated function stub: 
// void __textlen() /* __textlen method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __textlen() 
{ // line 186, offset 0x800cad7c
	return null;
}


// autogenerated function stub: 
// void __data() /* __data method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __data() 
{ // line 187, offset 0x800cad80
	return null;
}


// autogenerated function stub: 
// void __datalen() /* __datalen method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __datalen() 
{ // line 188, offset 0x800cad84
	return null;
}


// autogenerated function stub: 
// void __bss() /* __bss method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __bss() 
{ // line 189, offset 0x800cad88
	return null;
}


// autogenerated function stub: 
// void __bsslen() /* __bsslen method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __bsslen() 
{ // line 190, offset 0x800cad8c
	return null;
}


// autogenerated function stub: 
// void the_cine_table() /* the_cine_table method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void the_cine_table() 
{ // line 191, offset 0x800cad90
	/* begin block 1 */
		// Start line: 383
	/* end block 1 */
	// End Line: 384

	return null;
}


// autogenerated function stub: 
// void __ra_temp() /* __ra_temp method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void __ra_temp() 
{ // line 193, offset 0x800d5ad0
	/* begin block 1 */
		// Start line: 387
	/* end block 1 */
	// End Line: 388

	return null;
}


// autogenerated function stub: 
// void voiceTracker() /* voiceTracker method signature is not contained in the debug symbol data. This is likely either a library function or the game was compiled without debug symbols. Please refer to the TDR documentation for additional guidance. */
void voiceTracker() 
{ // line 195, offset 0x800d5ad4
	/* begin block 1 */
		// Start line: 391
	/* end block 1 */
	// End Line: 392

	return null;
}



