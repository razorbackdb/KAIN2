//#include "THISDUST.H"
#include "MEMPACK.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_Init()
 // line 194, offset 0x8004faa4
	/* begin block 1 */
		// Start line: 388
	/* end block 1 */
	// End Line: 389

	/* begin block 2 */
		// Start line: 396
	/* end block 2 */
	// End Line: 397

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_Init(void)

{
  fontTracker.font_buffer[80]._0_4_ = &DAT_801ff000 + -(int)overlayAddress;
                    /* WARNING: Read-only address (ram,0x800d18d8) is written */
                    /* WARNING: Read-only address (ram,0x800d18d4) is written */
  fontTracker.font_buffer[79]._2_4_ = overlayAddress;
  *(undefined2 *)overlayAddress = 0xbade;
  fontTracker.font_buffer[79]._2_4_[2] = 0;
  fontTracker.font_buffer[79]._2_4_[3] = 0;
  *(undefined **)(fontTracker.font_buffer[79]._2_4_ + 4) = fontTracker.font_buffer[80]._0_4_;
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
                    /* WARNING: Read-only address (ram,0x800d18e4) is written */
  fontTracker.font_buffer._484_4_ = 0;
  fontTracker.font_buffer[81]._2_4_ =
       fontTracker.font_buffer[79]._2_4_ + (int)fontTracker.font_buffer[80]._0_4_;
  fontTracker.font_buffer[82]._0_4_ = 0;
                    /* WARNING: Read-only address (ram,0x800d18e0) is written */
  return;
}



// decompiled code
// original method signature: 
// struct MemHeader * /*$ra*/ MEMPACK_GetSmallestBlockTopBottom(long allocSize /*$a0*/)
 // line 250, offset 0x8004fb0c
	/* begin block 1 */
		// Start line: 252
		// Start offset: 0x8004FB0C
		// Variables:
	// 		struct MemHeader *address; // $v1
	// 		struct MemHeader *bestAddress; // $a1
	/* end block 1 */
	// End offset: 0x8004FB6C
	// End Line: 273

	/* begin block 2 */
		// Start line: 516
	/* end block 2 */
	// End Line: 517

	/* begin block 3 */
		// Start line: 532
	/* end block 3 */
	// End Line: 533

	/* begin block 4 */
		// Start line: 533
	/* end block 4 */
	// End Line: 534

	/* begin block 5 */
		// Start line: 535
	/* end block 5 */
	// End Line: 536

MemHeader * MEMPACK_GetSmallestBlockTopBottom(long allocSize)

{
  MemHeader *pMVar1;
  
  pMVar1 = fontTracker.font_buffer[79]._2_4_;
  if (fontTracker.font_buffer[79]._2_4_ != fontTracker.font_buffer[81]._2_4_) {
    do {
      if ((pMVar1->memStatus == '\0') && ((uint)allocSize <= pMVar1->memSize)) {
        return pMVar1;
      }
      pMVar1 = (MemHeader *)((int)&pMVar1->magicNumber + pMVar1->memSize);
    } while (pMVar1 != fontTracker.font_buffer[81]._2_4_);
  }
  return (MemHeader *)0x0;
}



// decompiled code
// original method signature: 
// struct MemHeader * /*$ra*/ MEMPACK_GetSmallestBlockBottomTop(long allocSize /*$a0*/)
 // line 279, offset 0x8004fb74
	/* begin block 1 */
		// Start line: 281
		// Start offset: 0x8004FB74
		// Variables:
	// 		struct MemHeader *address; // $v1
	// 		struct MemHeader *bestAddress; // $a1
	/* end block 1 */
	// End offset: 0x8004FBD8
	// End Line: 309

	/* begin block 2 */
		// Start line: 590
	/* end block 2 */
	// End Line: 591

	/* begin block 3 */
		// Start line: 591
	/* end block 3 */
	// End Line: 592

	/* begin block 4 */
		// Start line: 593
	/* end block 4 */
	// End Line: 594

MemHeader * MEMPACK_GetSmallestBlockBottomTop(long allocSize)

{
  MemHeader *pMVar1;
  MemHeader *pMVar2;
  
  pMVar2 = (MemHeader *)0x0;
  pMVar1 = fontTracker.font_buffer[79]._2_4_;
  if (fontTracker.font_buffer[79]._2_4_ != fontTracker.font_buffer[81]._2_4_) {
    do {
      if (((pMVar1->memStatus == '\0') && ((uint)allocSize <= pMVar1->memSize)) &&
         ((pMVar2 == (MemHeader *)0x0 || (pMVar2 < pMVar1)))) {
        pMVar2 = pMVar1;
      }
      pMVar1 = (MemHeader *)((int)&pMVar1->magicNumber + pMVar1->memSize);
    } while (pMVar1 != fontTracker.font_buffer[81]._2_4_);
  }
  return pMVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MEMPACK_RelocatableType(long memType /*$a0*/)
 // line 312, offset 0x8004fbe0
	/* begin block 1 */
		// Start line: 656
	/* end block 1 */
	// End Line: 657

	/* begin block 2 */
		// Start line: 657
	/* end block 2 */
	// End Line: 658

long MEMPACK_RelocatableType(long memType)

{
  if ((((1 < memType - 1U) && (memType != 0x2c)) && (memType != 0x2f)) && (memType != 4)) {
    return 0;
  }
  return 1;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ MEMPACK_Malloc(unsigned long allocSize /*$s2*/, unsigned char memType /*$a1*/)
 // line 331, offset 0x8004fc18
	/* begin block 1 */
		// Start line: 332
		// Start offset: 0x8004FC18
		// Variables:
	// 		char *ptr; // $s0
	/* end block 1 */
	// End offset: 0x8004FC78
	// End Line: 346

	/* begin block 2 */
		// Start line: 694
	/* end block 2 */
	// End Line: 695

char * MEMPACK_Malloc(ulong allocSize,uchar memType)

{
  char *pcVar1;
  
  pcVar1 = MEMPACK_MallocFailOk(allocSize,memType);
  if (pcVar1 == (char *)0x0) {
    MEMPACK_ReportMemory2();
                    /* WARNING: Subroutine does not return */
    DEBUG_FatalError(s_Trying_to_fit_memory_size__d_Typ_800cebdc);
  }
  return pcVar1;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ MEMPACK_MallocFailOk(unsigned long allocSize /*$s1*/, unsigned char memType /*$s3*/)
 // line 349, offset 0x8004fc94
	/* begin block 1 */
		// Start line: 350
		// Start offset: 0x8004FC94
		// Variables:
	// 		struct MemHeader *bestAddress; // $a1
	// 		long relocatableMemory; // $s2

		/* begin block 1.1 */
			// Start line: 378
			// Start offset: 0x8004FD18
			// Variables:
		// 		int curMem; // $s0
		/* end block 1.1 */
		// End offset: 0x8004FD34
		// End Line: 390

		/* begin block 1.2 */
			// Start line: 404
			// Start offset: 0x8004FD60
			// Variables:
		// 		struct MemHeader *address; // $a2

			/* begin block 1.2.1 */
				// Start line: 424
				// Start offset: 0x8004FD94
				// Variables:
			// 		long topOffset; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8004FD94
			// End Line: 426
		/* end block 1.2 */
		// End offset: 0x8004FD94
		// End Line: 426
	/* end block 1 */
	// End offset: 0x8004FE04
	// End Line: 457

	/* begin block 2 */
		// Start line: 733
	/* end block 2 */
	// End Line: 734

char * MEMPACK_MallocFailOk(ulong allocSize,uchar memType)

{
  int iVar1;
  long lVar2;
  MemHeader *pMVar3;
  NodeType *allocSize_00;
  NodeType *list;
  undefined2 *puVar4;
  MemHeader *pMVar5;
  
  lVar2 = MEMPACK_RelocatableType((uint)memType);
  allocSize_00 = (NodeType *)(allocSize + 0xb & 0xfffffffc);
  do {
    if (fontTracker.font_buffer[82]._0_4_ == 0) {
      if (lVar2 != 0) {
        MEMPACK_DoGarbageCollection();
        goto LAB_8004fcec;
      }
LAB_8004fd04:
      pMVar3 = MEMPACK_GetSmallestBlockBottomTop((long)allocSize_00);
    }
    else {
LAB_8004fcec:
      if (lVar2 == 0) goto LAB_8004fd04;
      pMVar3 = MEMPACK_GetSmallestBlockTopBottom((long)allocSize_00);
    }
    iVar1 = fontTracker.font_buffer._484_4_;
    if (pMVar3 != (MemHeader *)0x0) {
      list = (NodeType *)pMVar3->memSize;
      if ((NodeType *)((int)list - (int)allocSize_00) < (NodeType *)&DAT_00000008) {
        allocSize_00 = list;
      }
      if (allocSize_00 == list) {
        pMVar3->magicNumber = 0xbade;
        pMVar3->memStatus = '\x01';
        pMVar3->memType = memType;
        *(NodeType **)&pMVar3->memSize = allocSize_00;
        fontTracker.font_buffer._484_4_ = (int)&allocSize_00->prev + fontTracker.font_buffer._484_4_
        ;
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
      }
      else {
        puVar4 = (undefined2 *)((int)&allocSize_00->prev + (int)&pMVar3->magicNumber);
        if (lVar2 != 0) {
          *puVar4 = 0xbade;
          *(undefined *)(puVar4 + 1) = 0;
          *(undefined *)((int)puVar4 + 3) = 0;
          *(ulong *)(puVar4 + 2) = pMVar3->memSize - (int)allocSize_00;
          pMVar3->magicNumber = 0xbade;
          allocSize_00 = LIST_GetFunc(list);
          return (char *)allocSize_00;
        }
        pMVar5 = (MemHeader *)((int)pMVar3 + (int)(NodeType *)((int)list - (int)allocSize_00));
        pMVar5->magicNumber = 0xbade;
        pMVar5->memStatus = '\x01';
        pMVar5->memType = memType;
        *(NodeType **)&pMVar5->memSize = allocSize_00;
        fontTracker.font_buffer._484_4_ = (int)&allocSize_00->prev + fontTracker.font_buffer._484_4_
        ;
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
        pMVar3->magicNumber = 0xbade;
        pMVar3->memStatus = '\0';
        pMVar3->memType = '\0';
        *(NodeType **)&pMVar3->memSize = (NodeType *)((int)list - (int)allocSize_00);
        pMVar3 = pMVar5;
      }
      return (char *)(pMVar3 + 1);
    }
    STREAM_TryAndDumpANonResidentObject();
    if (iVar1 == fontTracker.font_buffer._484_4_) {
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
                    /* WARNING: Read-only address (ram,0x800d18e4) is written */
      return (char *)0x0;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMORY_MergeAddresses(struct MemHeader *firstAddress /*$a0*/, struct MemHeader *secondAddress /*$a1*/)
 // line 461, offset 0x8004fe20
	/* begin block 1 */
		// Start line: 963
	/* end block 1 */
	// End Line: 964

	/* begin block 2 */
		// Start line: 969
	/* end block 2 */
	// End Line: 970

void MEMORY_MergeAddresses(MemHeader *firstAddress,MemHeader *secondAddress)

{
  if ((firstAddress->memStatus == '\0') && (secondAddress->memStatus == '\0')) {
    firstAddress->memSize = firstAddress->memSize + secondAddress->memSize;
    secondAddress->magicNumber = 0;
    secondAddress->memStatus = '\x01';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_Return(char *address /*$a0*/, long takeBackSize /*$a1*/)
 // line 480, offset 0x8004fe68
	/* begin block 1 */
		// Start line: 481
		// Start offset: 0x8004FE68
		// Variables:
	// 		struct MemHeader *memAddress; // $a0
	// 		struct MemHeader *nextAddress; // $a1
	/* end block 1 */
	// End offset: 0x8004FEDC
	// End Line: 508

	/* begin block 2 */
		// Start line: 1002
	/* end block 2 */
	// End Line: 1003

void MEMPACK_Return(char *address,long takeBackSize)

{
  MemHeader *firstAddress;
  int iVar1;
  
  iVar1 = takeBackSize >> 2;
  if (7 < iVar1 * 4) {
    *(int *)(address + -4) = *(int *)(address + -4) + iVar1 * -4;
    fontTracker.font_buffer._484_4_ = fontTracker.font_buffer._484_4_ + iVar1 * -4;
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
    firstAddress = (MemHeader *)(address + *(int *)(address + -4) + -8);
    firstAddress->magicNumber = 0xbade;
    firstAddress->memStatus = '\0';
    firstAddress->memType = '\0';
    firstAddress->memSize = iVar1 * 4;
    if ((MemHeader *)(&firstAddress->magicNumber + iVar1 * 2) != fontTracker.font_buffer[81]._2_4_)
    {
      MEMORY_MergeAddresses(firstAddress,(MemHeader *)(&firstAddress->magicNumber + iVar1 * 2));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_Free(char *address /*$a0*/)
 // line 539, offset 0x8004feec
	/* begin block 1 */
		// Start line: 540
		// Start offset: 0x8004FEEC
		// Variables:
	// 		struct MemHeader *memAddress; // $s0
	// 		struct MemHeader *secondAddress; // $v1
	/* end block 1 */
	// End offset: 0x8004FF8C
	// End Line: 584

	/* begin block 2 */
		// Start line: 1078
	/* end block 2 */
	// End Line: 1079

void MEMPACK_Free(char *address)

{
  MemHeader *secondAddress;
  MemHeader *secondAddress_00;
  MemHeader *firstAddress;
  
  firstAddress = (MemHeader *)(address + -8);
  address[-6] = '\0';
  address[-5] = '\0';
  fontTracker.font_buffer._484_4_ = fontTracker.font_buffer._484_4_ - *(int *)(address + -4);
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
  secondAddress = (MemHeader *)((int)&firstAddress->magicNumber + *(int *)(address + -4));
  secondAddress_00 = fontTracker.font_buffer[79]._2_4_;
  if (secondAddress != fontTracker.font_buffer[81]._2_4_) {
    MEMORY_MergeAddresses(firstAddress,secondAddress);
    secondAddress_00 = fontTracker.font_buffer[79]._2_4_;
  }
  do {
    secondAddress = secondAddress_00;
    if (secondAddress == fontTracker.font_buffer[81]._2_4_) {
      return;
    }
    secondAddress_00 = (MemHeader *)((int)&secondAddress->magicNumber + secondAddress->memSize);
  } while (secondAddress_00 != firstAddress);
  MEMORY_MergeAddresses(secondAddress,secondAddress_00);
                    /* WARNING: Read-only address (ram,0x800d18d4) is written */
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
                    /* WARNING: Read-only address (ram,0x800d18e0) is written */
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_FreeByType(unsigned char memType /*$a0*/)
 // line 586, offset 0x8004ff9c
	/* begin block 1 */
		// Start line: 587
		// Start offset: 0x8004FF9C
		// Variables:
	// 		struct MemHeader *address; // $a0
	// 		int freed; // $s0
	/* end block 1 */
	// End offset: 0x8005001C
	// End Line: 608

	/* begin block 2 */
		// Start line: 1187
	/* end block 2 */
	// End Line: 1188

void MEMPACK_FreeByType(uchar memType)

{
  int iVar1;
  
  iVar1 = fontTracker.font_buffer[79]._2_4_;
  if (fontTracker.font_buffer[79]._2_4_ != fontTracker.font_buffer[81]._2_4_) {
    do {
      if ((*(char *)(iVar1 + 2) == '\x01') && (*(uchar *)(iVar1 + 3) == memType)) {
                    /* WARNING: Subroutine does not return */
        MEMPACK_Free((char *)(iVar1 + 8));
      }
      iVar1 = iVar1 + *(int *)(iVar1 + 4);
    } while (iVar1 != fontTracker.font_buffer[81]._2_4_);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MEMPACK_Size(char *address /*$a0*/)
 // line 611, offset 0x80050034
	/* begin block 1 */
		// Start line: 613
		// Start offset: 0x80050034
	/* end block 1 */
	// End offset: 0x80050034
	// End Line: 618

	/* begin block 2 */
		// Start line: 1248
	/* end block 2 */
	// End Line: 1249

	/* begin block 3 */
		// Start line: 1249
	/* end block 3 */
	// End Line: 1250

	/* begin block 4 */
		// Start line: 1254
	/* end block 4 */
	// End Line: 1255

ulong MEMPACK_Size(char *address)

{
  return *(int *)(address + -4) - 8;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MEMPACK_ReportFreeMemory()
 // line 621, offset 0x80050040
	/* begin block 1 */
		// Start line: 1268
	/* end block 1 */
	// End Line: 1269

	/* begin block 2 */
		// Start line: 1269
	/* end block 2 */
	// End Line: 1270

int MEMPACK_ReportFreeMemory(void)

{
  return iGpffffbe24 - iGpffffbe28;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_ReportMemory2()
 // line 689, offset 0x80050050
	/* begin block 1 */
		// Start line: 691
		// Start offset: 0x80050050
		// Variables:
	// 		struct MemHeader *address; // $v1
	/* end block 1 */
	// End offset: 0x80050078
	// End Line: 725

	/* begin block 2 */
		// Start line: 1378
	/* end block 2 */
	// End Line: 1379

	/* begin block 3 */
		// Start line: 1338
	/* end block 3 */
	// End Line: 1339

	/* begin block 4 */
		// Start line: 1342
	/* end block 4 */
	// End Line: 1343

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_ReportMemory2(void)

{
  int iVar1;
  
  iVar1 = fontTracker.font_buffer[79]._2_4_;
  if (fontTracker.font_buffer[79]._2_4_ != fontTracker.font_buffer[81]._2_4_) {
    do {
      iVar1 = iVar1 + *(int *)(iVar1 + 4);
    } while (iVar1 != fontTracker.font_buffer[81]._2_4_);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_ReportMemory()
 // line 727, offset 0x80050080
	/* begin block 1 */
		// Start line: 729
		// Start offset: 0x80050080
		// Variables:
	// 		struct MemHeader *address; // $v1
	// 		long i; // $a1
	// 		long firstTime; // $a0
	/* end block 1 */
	// End offset: 0x80050114
	// End Line: 799

	/* begin block 2 */
		// Start line: 1413
	/* end block 2 */
	// End Line: 1414

	/* begin block 3 */
		// Start line: 1414
	/* end block 3 */
	// End Line: 1415

	/* begin block 4 */
		// Start line: 1421
	/* end block 4 */
	// End Line: 1422

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_ReportMemory(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = fontTracker.font_buffer[79]._2_4_;
  if (fontTracker.font_buffer[79]._2_4_ != fontTracker.font_buffer[81]._2_4_) {
    do {
      iVar2 = iVar2 + *(int *)(iVar2 + 4);
    } while (iVar2 != fontTracker.font_buffer[81]._2_4_);
  }
  uVar3 = 0;
  do {
    bVar1 = true;
    iVar2 = fontTracker.font_buffer[79]._2_4_;
    if (fontTracker.font_buffer[79]._2_4_ != fontTracker.font_buffer[81]._2_4_) {
      do {
        if (((*(char *)(iVar2 + 2) != '\0') && ((uint)*(byte *)(iVar2 + 3) == uVar3)) && (bVar1)) {
          bVar1 = false;
        }
        iVar2 = iVar2 + *(int *)(iVar2 + 4);
      } while (iVar2 != fontTracker.font_buffer[81]._2_4_);
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x31);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_SetMemoryBeingStreamed(char *address /*$a0*/)
 // line 801, offset 0x8005011c
	/* begin block 1 */
		// Start line: 803
		// Start offset: 0x8005011C
	/* end block 1 */
	// End offset: 0x8005011C
	// End Line: 808

	/* begin block 2 */
		// Start line: 1597
	/* end block 2 */
	// End Line: 1598

	/* begin block 3 */
		// Start line: 1598
	/* end block 3 */
	// End Line: 1599

	/* begin block 4 */
		// Start line: 1603
	/* end block 4 */
	// End Line: 1604

void MEMPACK_SetMemoryBeingStreamed(char *address)

{
  address[-6] = '\x02';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_SetMemoryDoneStreamed(char *address /*$a0*/)
 // line 811, offset 0x80050128
	/* begin block 1 */
		// Start line: 813
		// Start offset: 0x80050128
	/* end block 1 */
	// End offset: 0x80050128
	// End Line: 818

	/* begin block 2 */
		// Start line: 1617
	/* end block 2 */
	// End Line: 1618

	/* begin block 3 */
		// Start line: 1618
	/* end block 3 */
	// End Line: 1619

	/* begin block 4 */
		// Start line: 1623
	/* end block 4 */
	// End Line: 1624

void MEMPACK_SetMemoryDoneStreamed(char *address)

{
  address[-6] = '\x01';
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MEMPACK_MemoryValidFunc(char *address /*$a0*/)
 // line 826, offset 0x80050134
	/* begin block 1 */
		// Start line: 828
		// Start offset: 0x80050134
	/* end block 1 */
	// End offset: 0x80050160
	// End Line: 853

	/* begin block 2 */
		// Start line: 1647
	/* end block 2 */
	// End Line: 1648

	/* begin block 3 */
		// Start line: 1648
	/* end block 3 */
	// End Line: 1649

	/* begin block 4 */
		// Start line: 1650
	/* end block 4 */
	// End Line: 1651

long MEMPACK_MemoryValidFunc(char *address)

{
  MemHeader *pMVar1;
  
  if (address == (char *)0xfafbfcfd) {
    pMVar1 = MEMPACK_GetSmallestBlockBottomTop(-0x5040303);
    return (long)pMVar1;
  }
  if (address == (char *)0x0) {
    pMVar1 = MEMPACK_GetSmallestBlockBottomTop(0);
    return (long)pMVar1;
  }
  return (uint)(address[-6] == '\x01');
}



// decompiled code
// original method signature: 
// char * /*$ra*/ MEMPACK_GarbageCollectMalloc(unsigned long *allocSize /*$s1*/, unsigned char memType /*$s2*/, unsigned long *freeSize /*$s3*/)
 // line 855, offset 0x80050168
	/* begin block 1 */
		// Start line: 856
		// Start offset: 0x80050168
		// Variables:
	// 		struct MemHeader *bestAddress; // $s0
	/* end block 1 */
	// End offset: 0x800502AC
	// End Line: 918

	/* begin block 2 */
		// Start line: 1705
	/* end block 2 */
	// End Line: 1706

char * MEMPACK_GarbageCollectMalloc(ulong *allocSize,uchar memType,ulong *freeSize)

{
  MemHeader *pMVar1;
  uint allocSize_00;
  
  allocSize_00 = *allocSize + 0xb & 0xfffffffc;
  *allocSize = allocSize_00;
  pMVar1 = MEMPACK_GetSmallestBlockTopBottom(allocSize_00);
  if (pMVar1 == (MemHeader *)0x0) {
    STREAM_DumpNonResidentObjects();
    pMVar1 = MEMPACK_GetSmallestBlockTopBottom(*allocSize);
    if (pMVar1 == (MemHeader *)0x0) {
      MEMPACK_ReportMemory();
                    /* WARNING: Subroutine does not return */
      DEBUG_FatalError(s_Trying_to_fit_memory_size__d_Typ_800cec2c);
    }
  }
  if (pMVar1->memSize - *allocSize < 8) {
    *allocSize = pMVar1->memSize;
  }
  if (*allocSize == pMVar1->memSize) {
    pMVar1->magicNumber = 0xbade;
    pMVar1->memStatus = '\x01';
    pMVar1->memType = memType;
    pMVar1->memSize = *allocSize;
    fontTracker.font_buffer._484_4_ = fontTracker.font_buffer._484_4_ + *allocSize;
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
    *freeSize = 0;
  }
  else {
    *freeSize = pMVar1->memSize - *allocSize;
    pMVar1->magicNumber = 0xbade;
    pMVar1->memStatus = '\x01';
    pMVar1->memType = memType;
    pMVar1->memSize = *allocSize;
    fontTracker.font_buffer._484_4_ = fontTracker.font_buffer._484_4_ + *allocSize;
                    /* WARNING: Read-only address (ram,0x800d18dc) is written */
  }
  return (char *)(pMVar1 + 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_GarbageSplitMemoryNow(unsigned long allocSize /*$a0*/, struct MemHeader *bestAddress /*$a1*/, long memType /*$a2*/, unsigned long freeSize /*$a3*/)
 // line 921, offset 0x800502cc
	/* begin block 1 */
		// Start line: 923
		// Start offset: 0x800502CC

		/* begin block 1.1 */
			// Start line: 925
			// Start offset: 0x800502D4
			// Variables:
		// 		struct MemHeader *address; // $v0
		/* end block 1.1 */
		// End offset: 0x800502E8
		// End Line: 933
	/* end block 1 */
	// End offset: 0x800502E8
	// End Line: 935

	/* begin block 2 */
		// Start line: 1842
	/* end block 2 */
	// End Line: 1843

	/* begin block 3 */
		// Start line: 1843
	/* end block 3 */
	// End Line: 1844

void MEMPACK_GarbageSplitMemoryNow
               (ulong allocSize,MemHeader *bestAddress,long memType,ulong freeSize)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)((int)&bestAddress->magicNumber + allocSize);
  if (freeSize != 0) {
    *puVar1 = 0xbade;
    *(undefined *)(puVar1 + 1) = 0;
    *(undefined *)((int)puVar1 + 3) = 0;
    *(ulong *)(puVar1 + 2) = freeSize;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_GarbageCollectFree(struct MemHeader *memAddress /*$s0*/)
 // line 940, offset 0x800502f0
	/* begin block 1 */
		// Start line: 941
		// Start offset: 0x800502F0
		// Variables:
	// 		struct MemHeader *secondAddress; // $v1
	/* end block 1 */
	// End offset: 0x80050390
	// End Line: 977

	/* begin block 2 */
		// Start line: 1880
	/* end block 2 */
	// End Line: 1881

void MEMPACK_Init(void)

{
  MemHeader *secondAddress;
  MemHeader *in_a0;
  MemHeader *secondAddress_00;
  
  in_a0->memStatus = '\0';
  in_a0->memType = '\0';
  gameTrackerX.gameData.asmData.lightInstances[0].b =
       gameTrackerX.gameData.asmData.lightInstances[0].b - in_a0->memSize;
  secondAddress = (MemHeader *)((int)&in_a0->magicNumber + in_a0->memSize);
  secondAddress_00 = (MemHeader *)gameTrackerX.gameData.asmData.lightInstances[0].r;
  if (secondAddress != gameTrackerX.gameData.asmData.lightInstances[0]._16_4_) {
    MEMORY_MergeAddresses(in_a0,secondAddress);
    secondAddress_00 = (MemHeader *)gameTrackerX.gameData.asmData.lightInstances[0].r;
  }
  do {
    secondAddress = secondAddress_00;
    if (secondAddress == gameTrackerX.gameData.asmData.lightInstances[0]._16_4_) {
      return;
    }
    secondAddress_00 = (MemHeader *)((int)&secondAddress->magicNumber + secondAddress->memSize);
  } while (secondAddress_00 != in_a0);
  MEMORY_MergeAddresses(secondAddress,secondAddress_00);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_DoGarbageCollection()
 // line 998, offset 0x800503a0
	/* begin block 1 */
		// Start line: 999
		// Start offset: 0x800503A0
		// Variables:
	// 		struct MemHeader *relocateAddress; // $s0
	// 		long foundOpening; // $s1
	// 		long done; // $s5
	// 		long addressSize; // $s3
	// 		long addressMemType; // $s2
	// 		long holdSize; // stack offset -40
	// 		long freeSize; // stack offset -36
	// 		char *oldAddress; // $s0
	// 		char *newAddress; // $s1
	/* end block 1 */
	// End offset: 0x80050590
	// End Line: 1131

	/* begin block 2 */
		// Start line: 1996
	/* end block 2 */
	// End Line: 1997

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_DoGarbageCollection(void)

{
  byte memType;
  bool bVar1;
  long lVar2;
  _HModel *newHModel;
  int iVar3;
  Level *level;
  int iVar4;
  size_t __n;
  size_t local_28;
  ulong local_24;
  
  bVar1 = false;
  local_24 = 0;
                    /* WARNING: Read-only address (ram,0x800d18e4) is written */
  fontTracker.font_buffer[82]._0_4_ = 1;
  do {
    iVar4 = 0;
    iVar3 = fontTracker.font_buffer[79]._2_4_;
    if (fontTracker.font_buffer[79]._2_4_ != fontTracker.font_buffer[81]._2_4_) {
      do {
        if (*(char *)(iVar3 + 2) == '\0') {
          iVar4 = 1;
        }
        else {
          lVar2 = MEMPACK_RelocatableType((uint)*(byte *)(iVar3 + 3));
          if (((lVar2 != 0) && (iVar4 == 1)) && (*(char *)(iVar3 + 2) != '\x02')) {
            iVar4 = 2;
            break;
          }
        }
        iVar3 = iVar3 + *(int *)(iVar3 + 4);
      } while (iVar3 != fontTracker.font_buffer[81]._2_4_);
    }
    if (iVar4 == 2) {
      memType = *(byte *)(iVar3 + 3);
      __n = *(int *)(iVar3 + 4) - 8;
      MEMPACK_Init();
      local_28 = __n;
      newHModel = (_HModel *)MEMPACK_GarbageCollectMalloc(&local_28,memType,&local_24);
      level = (Level *)(iVar3 + 8);
      if (newHModel != (_HModel *)0x0) {
        if (memType == 2) {
          RemoveIntroducedLights(level);
        }
        else {
          if (memType == 4) {
            aadRelocateMusicMemoryBegin();
          }
        }
        memcpy(newHModel,level,__n);
        if (memType == 2) {
          MEMPACK_RelocateAreaType
                    ((MemHeader *)(newHModel + -1),(long)((int)newHModel - (int)level),level);
        }
        else {
          if (memType == 1) {
            MEMPACK_RelocateObjectType
                      ((MemHeader *)(newHModel + -1),(long)((int)newHModel - (int)level),
                       (Object *)level);
          }
          else {
            if (memType == 0xe) {
              STREAM_UpdateInstanceCollisionInfo((_HModel *)level,newHModel);
            }
            else {
              if (memType == 0x2c) {
                MEMPACK_RelocateCDMemory
                          ((MemHeader *)(newHModel + -1),(long)((int)newHModel - (int)level),
                           (_BigFileDir *)level);
              }
              else {
                if (memType == 4) {
                  aadRelocateMusicMemoryEnd
                            ((MemHeader *)(newHModel + -1),(long)((int)newHModel - (int)level),level
                            );
                }
                else {
                  if (memType == 0x2f) {
                    aadRelocateSfxMemory(level,(int)((int)newHModel - (int)level));
                  }
                }
              }
            }
          }
        }
        MEMPACK_GarbageSplitMemoryNow(local_28,(MemHeader *)(newHModel + -1),(uint)memType,local_24)
        ;
      }
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      fontTracker.font_buffer[82]._0_4_ = 0;
                    /* WARNING: Read-only address (ram,0x800d18e4) is written */
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateAreaType(struct MemHeader *newAddress /*$a0*/, long offset /*$s1*/, struct Level *oldLevel /*$s3*/)
 // line 1163, offset 0x800505bc
	/* begin block 1 */
		// Start line: 1164
		// Start offset: 0x800505BC
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct _MultiSignal *msignal; // $a0
	// 		long sizeOfLevel; // $s2
	// 		long i; // $t0
	// 		long d; // $a3

		/* begin block 1.1 */
			// Start line: 1229
			// Start offset: 0x800508DC
			// Variables:
		// 		struct _Terrain *terrain; // $t1

			/* begin block 1.1.1 */
				// Start line: 1257
				// Start offset: 0x800509F8
				// Variables:
			// 		struct Intro *intro; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 1267
					// Start offset: 0x80050A34
					// Variables:
				// 		struct MultiSpline *multiSpline; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x80050B28
				// End Line: 1290
			/* end block 1.1.1 */
			// End offset: 0x80050B3C
			// End Line: 1292

			/* begin block 1.1.2 */
				// Start line: 1310
				// Start offset: 0x80050B64
				// Variables:
			// 		struct DrMoveAniTexDestInfo **dest; // $v0
			/* end block 1.1.2 */
			// End offset: 0x80050BB8
			// End Line: 1320

			/* begin block 1.1.3 */
				// Start line: 1363
				// Start offset: 0x80050C1C
				// Variables:
			// 		struct _VMObject *vmo; // $a1
			/* end block 1.1.3 */
			// End offset: 0x80050CF4
			// End Line: 1374

			/* begin block 1.1.4 */
				// Start line: 1361
				// Start offset: 0x80050D0C
				// Variables:
			// 		struct BSPTree *bsp; // $t2
			// 		struct _BSPNode *node; // $a2
			// 		struct _BSPLeaf *leaf; // $a1
			/* end block 1.1.4 */
			// End offset: 0x80050E24
			// End Line: 1401
		/* end block 1.1 */
		// End offset: 0x80050E24
		// End Line: 1403
	/* end block 1 */
	// End offset: 0x80050E58
	// End Line: 1421

	/* begin block 2 */
		// Start line: 2348
	/* end block 2 */
	// End Line: 2349

void MEMPACK_RelocateAreaType(MemHeader *newAddress,long offset,Level *oldLevel)

{
  bool bVar1;
  int iVar2;
  _Terrain *p_Var3;
  char *pcVar4;
  _BSPNode *p_Var5;
  _BSPLeaf *p_Var6;
  _Instance *p_Var7;
  ulong freeSize;
  int iVar8;
  Intro *pIVar9;
  _TFace *p_Var10;
  DrMoveAniTex *pDVar11;
  TextureFT3 *pTVar12;
  _MorphVertex *p_Var13;
  BSPTree *pBVar14;
  _MultiSignal *p_Var15;
  Level *memType;
  LightList *pLVar16;
  _VMObject *p_Var17;
  int iVar18;
  MemHeader *firstAddress;
  ulong uVar19;
  _TVertex *p_Var20;
  _Normal *p_Var21;
  void *pvVar22;
  TextureFT3 *pTVar23;
  _MorphColor *p_Var24;
  short *psVar25;
  _Terrain *p_Var26;
  CVECTOR allocSize;
  int iVar27;
  _BSPLeaf *offset_00;
  int *allocSize_00;
  _Instance *instance;
  MemHeader *newAddress_00;
  int iVar28;
  CVECTOR bestAddress;
  Level *oldLevel_00;
  ulong in_a3;
  _BSPLeaf **pp_Var29;
  Level *newLevel;
  int sizeOfLevel;
  
  newLevel = (Level *)(newAddress + 1);
  sizeOfLevel = newAddress->memSize - 8;
  if (*(int *)(newAddress + 1) == 0) {
    MEMPACK_ReportMemory2();
    return;
  }
  newAddress_00 = (MemHeader *)(*(int *)(newAddress + 1) + offset);
  *(MemHeader **)(newAddress + 1) = newAddress_00;
  freeSize = 0;
  if (newAddress[1].memSize != 0) {
    freeSize = newAddress[1].memSize + offset;
  }
  iVar2 = *(int *)(newAddress + 0x31);
  firstAddress = (MemHeader *)0x0;
  newAddress[1].memSize = freeSize;
  if (iVar2 != 0) {
    firstAddress = (MemHeader *)(iVar2 + offset);
  }
  freeSize = newAddress[0x31].memSize;
  *(MemHeader **)(newAddress + 0x31) = firstAddress;
  if (freeSize != 0) {
    uVar19 = 0;
    newAddress[0x31].memSize = freeSize + offset;
    if (newAddress[2].memSize != 0) {
      uVar19 = newAddress[2].memSize + offset;
    }
    freeSize = 0;
    newAddress[2].memSize = uVar19;
    if (newAddress[3].memSize != 0) {
      freeSize = newAddress[3].memSize + offset;
    }
    uVar19 = 0;
    newAddress[3].memSize = freeSize;
    if (newAddress[4].memSize != 0) {
      uVar19 = newAddress[4].memSize + offset;
    }
    freeSize = 0;
    newAddress[4].memSize = uVar19;
    if (newAddress[5].memSize != 0) {
      freeSize = newAddress[5].memSize + offset;
    }
    uVar19 = 0;
    newAddress[5].memSize = freeSize;
    if (newAddress[6].memSize != 0) {
      uVar19 = newAddress[6].memSize + offset;
    }
    freeSize = 0;
    newAddress[6].memSize = uVar19;
    if (newAddress[7].memSize != 0) {
      freeSize = newAddress[7].memSize + offset;
    }
    newAddress[7].memSize = freeSize;
    if (newAddress[0xc].memSize != 0) {
      iVar2 = *(int *)(newAddress + 0xe);
      iVar8 = 0;
      newAddress[0xc].memSize = newAddress[0xc].memSize + offset;
      if (iVar2 != 0) {
        iVar8 = iVar2 + offset;
      }
      freeSize = newAddress[0xf].memSize;
      uVar19 = 0;
      *(int *)(newAddress + 0xe) = iVar8;
      if (freeSize != 0) {
        uVar19 = freeSize + offset;
      }
      freeSize = 0;
      newAddress[0xf].memSize = uVar19;
      if (newAddress[0x10].memSize != 0) {
        freeSize = newAddress[0x10].memSize + offset;
      }
      iVar2 = *(int *)(newAddress + 0x11);
      iVar8 = 0;
      newAddress[0x10].memSize = freeSize;
      if (iVar2 != 0) {
        iVar8 = iVar2 + offset;
      }
      iVar2 = 0;
      *(int *)(newAddress + 0x11) = iVar8;
      if (*(int *)(newAddress + 0x12) != 0) {
        iVar2 = *(int *)(newAddress + 0x12) + offset;
      }
      freeSize = newAddress[0x12].memSize;
      uVar19 = 0;
      *(int *)(newAddress + 0x12) = iVar2;
      if (freeSize != 0) {
        uVar19 = freeSize + offset;
      }
      iVar2 = *(int *)(newAddress + 0x14);
      iVar8 = 0;
      newAddress[0x12].memSize = uVar19;
      if (iVar2 != 0) {
        iVar8 = iVar2 + offset;
      }
      freeSize = newAddress[0x16].memSize;
      uVar19 = 0;
      *(int *)(newAddress + 0x14) = iVar8;
      if (freeSize != 0) {
        uVar19 = freeSize + offset;
      }
      iVar2 = *(int *)(newAddress + 0x17);
      iVar8 = 0;
      newAddress[0x16].memSize = uVar19;
      if (iVar2 != 0) {
        iVar8 = iVar2 + offset;
      }
      freeSize = newAddress[0x17].memSize;
      uVar19 = 0;
      *(int *)(newAddress + 0x17) = iVar8;
      if (freeSize != 0) {
        uVar19 = freeSize + offset;
      }
      iVar2 = *(int *)(newAddress + 0x18);
      iVar8 = 0;
      newAddress[0x17].memSize = uVar19;
      if (iVar2 != 0) {
        iVar8 = iVar2 + offset;
      }
      freeSize = newAddress[0x18].memSize;
      uVar19 = 0;
      *(int *)(newAddress + 0x18) = iVar8;
      if (freeSize != 0) {
        uVar19 = freeSize + offset;
      }
      iVar2 = *(int *)(newAddress + 0x19);
      iVar8 = 0;
      newAddress[0x18].memSize = uVar19;
      if (iVar2 != 0) {
        iVar8 = iVar2 + offset;
      }
      freeSize = newAddress[0x19].memSize;
      uVar19 = 0;
      *(int *)(newAddress + 0x19) = iVar8;
      if (freeSize != 0) {
        uVar19 = freeSize + offset;
      }
      iVar2 = *(int *)(newAddress + 0x1a);
      iVar8 = 0;
      newAddress[0x19].memSize = uVar19;
      if (iVar2 != 0) {
        iVar8 = iVar2 + offset;
      }
      iVar2 = 0;
      *(int *)(newAddress + 0x1a) = iVar8;
      if (*(int *)(newAddress + 0x1b) != 0) {
        iVar2 = *(int *)(newAddress + 0x1b) + offset;
      }
      freeSize = newAddress[0x1b].memSize;
      uVar19 = 0;
      *(int *)(newAddress + 0x1b) = iVar2;
      if (freeSize != 0) {
        uVar19 = freeSize + offset;
      }
      freeSize = 0;
      newAddress[0x1b].memSize = uVar19;
      if (newAddress[0x1c].memSize != 0) {
        freeSize = newAddress[0x1c].memSize + offset;
      }
      uVar19 = 0;
      newAddress[0x1c].memSize = freeSize;
      if (newAddress[0x1d].memSize != 0) {
        uVar19 = newAddress[0x1d].memSize + offset;
      }
      freeSize = 0;
      newAddress[0x1d].memSize = uVar19;
      if (newAddress[0x1e].memSize != 0) {
        freeSize = newAddress[0x1e].memSize + offset;
      }
      iVar2 = *(int *)(newAddress + 0x1e);
      iVar8 = 0;
      newAddress[0x1e].memSize = freeSize;
      if (0 < iVar2) {
        newAddress_00 = (MemHeader *)0x0;
        do {
          allocSize_00 = (int *)((int)&newAddress_00->magicNumber + newAddress[0x1e].memSize);
          if (*allocSize_00 == 0) {
            MEMPACK_GarbageSplitMemoryNow((ulong)allocSize_00,newAddress_00,(long)oldLevel,in_a3);
            return;
          }
          *allocSize_00 = *allocSize_00 + offset;
          iVar8 = iVar8 + 1;
          newAddress_00 = (MemHeader *)&newAddress_00[4].memSize;
        } while (iVar8 < *(int *)(newAddress + 0x1e));
      }
      freeSize = 0;
      if (newAddress[0x1f].memSize != 0) {
        freeSize = newAddress[0x1f].memSize + offset;
      }
      uVar19 = 0;
      newAddress[0x1f].memSize = freeSize;
      if (newAddress[0xb].memSize != 0) {
        uVar19 = newAddress[0xb].memSize + offset;
      }
      p_Var3 = newLevel->terrain;
      newAddress[0xb].memSize = uVar19;
      oldLevel_00 = oldLevel;
      if (p_Var3 != (_Terrain *)0x0) {
        pIVar9 = (Intro *)0x0;
        if (p_Var3->introList != (Intro *)0x0) {
          pIVar9 = (Intro *)(p_Var3->introList->name + offset);
        }
        p_Var20 = (_TVertex *)0x0;
        p_Var3->introList = pIVar9;
        if (p_Var3->vertexList != (_TVertex *)0x0) {
          p_Var20 = (_TVertex *)((int)&(p_Var3->vertexList->vertex).x + offset);
        }
        p_Var10 = (_TFace *)0x0;
        p_Var3->vertexList = p_Var20;
        if (p_Var3->faceList != (_TFace *)0x0) {
          p_Var10 = (_TFace *)((int)&(p_Var3->faceList->face).v0 + offset);
        }
        p_Var21 = (_Normal *)0x0;
        p_Var3->faceList = p_Var10;
        if (p_Var3->normalList != (_Normal *)0x0) {
          p_Var21 = (_Normal *)((int)&p_Var3->normalList->x + offset);
        }
        pDVar11 = (DrMoveAniTex *)0x0;
        p_Var3->normalList = p_Var21;
        if (p_Var3->aniList != (DrMoveAniTex *)0x0) {
          pDVar11 = (DrMoveAniTex *)((int)&p_Var3->aniList->numAniTextues + offset);
        }
        pvVar22 = (void *)0x0;
        p_Var3->aniList = pDVar11;
        if (p_Var3->StreamUnits != (void *)0x0) {
          pvVar22 = (void *)((int)p_Var3->StreamUnits + offset);
        }
        pTVar12 = (TextureFT3 *)0x0;
        p_Var3->StreamUnits = pvVar22;
        if (p_Var3->StartTextureList != (TextureFT3 *)0x0) {
          pTVar12 = (TextureFT3 *)(&p_Var3->StartTextureList->u0 + offset);
        }
        pTVar23 = (TextureFT3 *)0x0;
        p_Var3->StartTextureList = pTVar12;
        if (p_Var3->EndTextureList != (TextureFT3 *)0x0) {
          pTVar23 = (TextureFT3 *)(&p_Var3->EndTextureList->u0 + offset);
        }
        p_Var13 = (_MorphVertex *)0x0;
        p_Var3->EndTextureList = pTVar23;
        if (p_Var3->MorphDiffList != (_MorphVertex *)0x0) {
          p_Var13 = (_MorphVertex *)((int)&p_Var3->MorphDiffList->x + offset);
        }
        p_Var24 = (_MorphColor *)0x0;
        p_Var3->MorphDiffList = p_Var13;
        if (p_Var3->MorphColorList != (_MorphColor *)0x0) {
          p_Var24 = (_MorphColor *)((int)&p_Var3->MorphColorList->morphColor15 + offset);
        }
        pBVar14 = (BSPTree *)0x0;
        p_Var3->MorphColorList = p_Var24;
        if (p_Var3->BSPTreeArray != (BSPTree *)0x0) {
          pBVar14 = (BSPTree *)((int)&p_Var3->BSPTreeArray->bspRoot + offset);
        }
        psVar25 = (short *)0x0;
        p_Var3->BSPTreeArray = pBVar14;
        if (p_Var3->morphNormalIdx != (short *)0x0) {
          psVar25 = (short *)((int)p_Var3->morphNormalIdx + offset);
        }
        p_Var15 = (_MultiSignal *)0x0;
        p_Var3->morphNormalIdx = psVar25;
        if (p_Var3->signals != (_MultiSignal *)0x0) {
          p_Var15 = (_MultiSignal *)((int)&p_Var3->signals->numSignals + offset);
        }
        iVar2 = 0;
        p_Var3->signals = p_Var15;
        if (0 < p_Var3->numIntros) {
          iVar8 = 0;
          do {
            pcVar4 = p_Var3->introList->name + iVar8;
            iVar28 = 0;
            if (*(int *)(pcVar4 + 0x30) != 0) {
              iVar28 = *(int *)(pcVar4 + 0x30) + offset;
            }
            memType = (Level *)0x0;
            *(int *)(pcVar4 + 0x30) = iVar28;
            if (*(int *)(pcVar4 + 0x38) != 0) {
              memType = (Level *)(*(int *)(pcVar4 + 0x38) + offset);
            }
            *(Level **)(pcVar4 + 0x38) = memType;
            if (memType != (Level *)0x0) {
              p_Var26 = (_Terrain *)0x0;
              if (memType->terrain != (_Terrain *)0x0) {
                p_Var26 = (_Terrain *)((int)&memType->terrain->UnitChangeFlags + offset);
              }
              bestAddress = (CVECTOR)0x0;
              memType->terrain = p_Var26;
              if (memType->lightList != (LightList *)0x0) {
                bestAddress = (CVECTOR)(&(memType->lightList->ambient).r + offset);
              }
              freeSize = 0;
              *(CVECTOR *)&memType->lightList = bestAddress;
              if (memType->numVMObjects != 0) {
                freeSize = memType->numVMObjects + offset;
              }
              allocSize = (CVECTOR)0x0;
              memType->numVMObjects = freeSize;
              if (memType->vmobjectList != (_VMObject *)0x0) {
                allocSize = (CVECTOR)((int)&memType->vmobjectList->flags + offset);
              }
              p_Var26 = memType->terrain;
              *(CVECTOR *)&memType->vmobjectList = allocSize;
              if (p_Var26 != (_Terrain *)0x0) {
                bestAddress = *(CVECTOR *)p_Var26;
                allocSize = (CVECTOR)0x0;
                if (bestAddress != (CVECTOR)0x0) {
                  allocSize = (CVECTOR)((int)bestAddress + offset);
                }
                *(CVECTOR *)p_Var26 = allocSize;
              }
              pLVar16 = memType->lightList;
              if (pLVar16 != (LightList *)0x0) {
                bestAddress = pLVar16->ambient;
                allocSize = (CVECTOR)0x0;
                if (bestAddress != (CVECTOR)0x0) {
                  allocSize = (CVECTOR)((int)bestAddress + offset);
                }
                pLVar16->ambient = allocSize;
              }
              allocSize_00 = (int *)memType->numVMObjects;
              if (allocSize_00 == (int *)0x0) {
                MEMPACK_GarbageSplitMemoryNow
                          ((ulong)allocSize,(MemHeader *)bestAddress,(long)memType,freeSize);
                return;
              }
              iVar28 = 0;
              if (*allocSize_00 != 0) {
                iVar28 = *allocSize_00 + offset;
              }
              *allocSize_00 = iVar28;
              p_Var17 = memType->vmobjectList;
              oldLevel_00 = memType;
              if (p_Var17 != (_VMObject *)0x0) {
                if (*(int *)p_Var17 == 0) {
                  MEMPACK_GarbageCollectFree((MemHeader *)0x0);
                  return;
                }
                *(int *)p_Var17 = *(int *)p_Var17 + offset;
              }
            }
            iVar28 = 0;
            if (*(int *)(pcVar4 + 0x3c) != 0) {
              iVar28 = *(int *)(pcVar4 + 0x3c) + offset;
            }
            *(int *)(pcVar4 + 0x3c) = iVar28;
            iVar2 = iVar2 + 1;
            iVar8 = iVar8 + 0x4c;
          } while (iVar2 < p_Var3->numIntros);
        }
        pDVar11 = p_Var3->aniList;
        if (((pDVar11 != (DrMoveAniTex *)0x0) && (0 < pDVar11->numAniTextues)) &&
           (iVar2 = 0, 0 < pDVar11->numAniTextues)) {
          do {
            pDVar11 = (DrMoveAniTex *)&pDVar11->aniTexInfo;
            iVar8 = 0;
            if (pDVar11->numAniTextues != 0) {
              iVar8 = pDVar11->numAniTextues + offset;
            }
            pDVar11->numAniTextues = iVar8;
            iVar2 = iVar2 + 1;
          } while (iVar2 < p_Var3->aniList->numAniTextues);
        }
        freeSize = newAddress[1].memSize;
        if (freeSize != 0) {
          iVar2 = 0;
          if (*(int *)(freeSize + 8) != 0) {
            iVar2 = *(int *)(freeSize + 8) + offset;
          }
          *(int *)(freeSize + 8) = iVar2;
        }
        freeSize = newAddress[0xb].memSize;
        if (freeSize != 0) {
          iVar2 = 0;
          if (*(int *)(freeSize + 8) != 0) {
            iVar2 = *(int *)(freeSize + 8) + offset;
          }
          *(int *)(freeSize + 8) = iVar2;
        }
        iVar2 = 0;
        if (0 < *(int *)(newAddress + 2)) {
          oldLevel_00 = (Level *)0x0;
          do {
            iVar28 = (int)&oldLevel_00->terrain + newAddress[2].memSize;
            iVar8 = 0;
            if (*(int *)(iVar28 + 0x20) != 0) {
              iVar8 = *(int *)(iVar28 + 0x20) + offset;
            }
            *(int *)(iVar28 + 0x20) = iVar8;
            iVar18 = *(int *)(iVar28 + 0x24);
            if (iVar18 == *(int *)((int)*(short *)(iVar28 + 8) * 4 + iVar8)) {
              iVar8 = 0;
              if (iVar18 != 0) {
                iVar8 = iVar18 + offset;
              }
              *(int *)(iVar28 + 0x24) = iVar8;
            }
            iVar8 = 0;
            if (0 < *(int *)(iVar28 + 0x1c)) {
              do {
                allocSize_00 = (int *)(iVar8 * 4 + *(int *)(iVar28 + 0x20));
                iVar27 = *allocSize_00;
                iVar18 = 0;
                if (iVar27 != 0) {
                  iVar18 = iVar27 + offset;
                }
                *allocSize_00 = iVar18;
                iVar8 = iVar8 + 1;
              } while (iVar8 < *(int *)(iVar28 + 0x1c));
            }
            iVar8 = 0;
            if (*(int *)(iVar28 + 0x2c) != 0) {
              iVar8 = *(int *)(iVar28 + 0x2c) + offset;
            }
            iVar18 = 0;
            *(int *)(iVar28 + 0x2c) = iVar8;
            if (*(int *)(iVar28 + 0x34) != 0) {
              iVar18 = *(int *)(iVar28 + 0x34) + offset;
            }
            iVar8 = 0;
            *(int *)(iVar28 + 0x34) = iVar18;
            if (*(int *)(iVar28 + 0x38) != 0) {
              iVar8 = *(int *)(iVar28 + 0x38) + offset;
            }
            *(int *)(iVar28 + 0x38) = iVar8;
            iVar2 = iVar2 + 1;
            oldLevel_00 = (Level *)&oldLevel_00->backColorR;
          } while (iVar2 < *(int *)(newAddress + 2));
        }
        pBVar14 = p_Var3->BSPTreeArray;
        iVar2 = 0;
        if (0 < p_Var3->numBSPTrees) {
          pp_Var29 = &pBVar14->endLeaves;
          do {
            p_Var5 = (_BSPNode *)0x0;
            if (pBVar14->bspRoot != (_BSPNode *)0x0) {
              p_Var5 = (_BSPNode *)((int)&(pBVar14->bspRoot->sphere).position.x + offset);
            }
            pBVar14->bspRoot = p_Var5;
            offset_00 = (_BSPLeaf *)0x0;
            if (pp_Var29[-1] != (_BSPLeaf *)0x0) {
              offset_00 = (_BSPLeaf *)((int)&(pp_Var29[-1]->sphere).position.x + offset);
            }
            p_Var6 = (_BSPLeaf *)0x0;
            pp_Var29[-1] = offset_00;
            if (*pp_Var29 != (_BSPLeaf *)0x0) {
              p_Var6 = (_BSPLeaf *)((int)&((*pp_Var29)->sphere).position.x + offset);
            }
            *pp_Var29 = p_Var6;
            oldLevel_00 = (Level *)pBVar14->bspRoot;
            if (oldLevel_00 < (Level *)pp_Var29[-1]) {
              allocSize_00 = &oldLevel_00->numPointLights;
              do {
                iVar8 = 0;
                if (allocSize_00[-1] != 0) {
                  iVar8 = allocSize_00[-1] + offset;
                }
                iVar28 = 0;
                allocSize_00[-1] = iVar8;
                if (*allocSize_00 != 0) {
                  iVar28 = *allocSize_00 + offset;
                }
                *allocSize_00 = iVar28;
                oldLevel_00 = (Level *)&oldLevel_00->pointSpecturalLightList;
                allocSize_00 = allocSize_00 + 0xb;
              } while (oldLevel_00 < (Level *)pp_Var29[-1]);
            }
            offset_00 = pp_Var29[-1];
            if (offset_00 < *pp_Var29) {
              newAddress_00 = (MemHeader *)&offset_00->faceList;
              do {
                if (*(int *)newAddress_00 == 0) {
                  MEMPACK_RelocateAreaType(newAddress_00,(long)offset_00,oldLevel_00);
                  return;
                }
                *(int *)newAddress_00 = *(int *)newAddress_00 + offset;
                offset_00 = offset_00 + 1;
                newAddress_00 = newAddress_00 + 6;
              } while (offset_00 < *pp_Var29);
            }
            iVar2 = iVar2 + 1;
            pp_Var29 = pp_Var29 + 9;
            pBVar14 = pBVar14 + 1;
          } while (iVar2 < p_Var3->numBSPTrees);
        }
      }
      instance = *(_Instance **)(newAddress + 0x1b);
      bVar1 = instance < (_Instance *)newAddress[0x1b].memSize;
      p_Var7 = (_Instance *)(uint)bVar1;
      if (bVar1) {
        do {
          SIGNAL_HandleSignal(instance,(Signal *)offset,(int)oldLevel_00);
          instance = p_Var7;
        } while (p_Var7 < (_Instance *)newAddress[0x1b].memSize);
      }
      EVENT_UpdatePuzzlePointers((EventPointers *)newAddress[0x1c].memSize,offset);
      STREAM_UpdateLevelPointer(oldLevel,newLevel,sizeOfLevel);
      EVENT_RelocateInstanceList(oldLevel,newLevel,sizeOfLevel);
      return;
    }
    MEMPACK_SetMemoryBeingStreamed((char *)0x0);
    return;
  }
  MEMORY_MergeAddresses(firstAddress,newAddress_00);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist /*$a0*/, int offset /*$a1*/, char *start /*$a2*/, char *end /*$a3*/)
 // line 1432, offset 0x80050ea0
	/* begin block 1 */
		// Start line: 1433
		// Start offset: 0x80050EA0

		/* begin block 1.1 */
			// Start line: 1436
			// Start offset: 0x80050EBC
			// Variables:
		// 		int j; // $a2
		// 		struct _G2AnimKeylist_Type *keylist; // $a3
		/* end block 1.1 */
		// End offset: 0x80050F38
		// End Line: 1452
	/* end block 1 */
	// End offset: 0x80050F38
	// End Line: 1453

	/* begin block 2 */
		// Start line: 3034
	/* end block 2 */
	// End Line: 3035

	/* begin block 3 */
		// Start line: 3035
	/* end block 3 */
	// End Line: 3036

void MEMPACK_RelocateG2AnimKeylistType
               (_G2AnimKeylist_Type **pKeylist,int offset,char *start,char *end)

{
  _G2AnimKeylist_Type *p_Var1;
  _func_7 **pp_Var2;
  _G2AnimKeylist_Type *p_Var3;
  _G2AnimFxHeader_Type *p_Var4;
  int iVar5;
  
  p_Var3 = *pKeylist;
  if ((start <= p_Var3) && (p_Var3 < end)) {
    p_Var1 = (_G2AnimKeylist_Type *)0x0;
    if (p_Var3 != (_G2AnimKeylist_Type *)0x0) {
      p_Var1 = (_G2AnimKeylist_Type *)(&p_Var3->sectionCount + offset);
    }
    *pKeylist = p_Var1;
    if (*(int *)p_Var1 != 0xface0ff) {
      p_Var4 = (_G2AnimFxHeader_Type *)0x0;
      if (p_Var1->fxList != (_G2AnimFxHeader_Type *)0x0) {
        p_Var4 = (_G2AnimFxHeader_Type *)(&p_Var1->fxList->sizeAndSection + offset);
      }
      iVar5 = 0;
      p_Var1->fxList = p_Var4;
      p_Var3 = p_Var1;
      if (p_Var1->sectionCount != '\0') {
        do {
          pp_Var2 = (_func_7 **)0x0;
          if (p_Var3->sectionData != (_func_7 **)0x0) {
            pp_Var2 = (_func_7 **)((int)p_Var3->sectionData + offset);
          }
          p_Var3->sectionData = pp_Var2;
          iVar5 = iVar5 + 1;
          p_Var3 = (_G2AnimKeylist_Type *)&p_Var3->keyCount;
        } while (iVar5 < (int)(uint)p_Var1->sectionCount);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateObjectType(struct MemHeader *newAddress /*$a0*/, long offset /*$s0*/, struct Object *oldObject /*$s3*/)
 // line 1455, offset 0x80050f40
	/* begin block 1 */
		// Start line: 1456
		// Start offset: 0x80050F40
		// Variables:
	// 		struct _Instance *instance; // $a1
	// 		struct Object *object; // $s1
	// 		int i; // $s2
	// 		int j; // $a2
	// 		int d; // $a3
	// 		int sizeOfObject; // $s4
	// 		struct _Model *model; // $t0

		/* begin block 1.1 */
			// Start line: 1502
			// Start offset: 0x80051140
			// Variables:
		// 		struct _MFace *mface; // $a0
		/* end block 1.1 */
		// End offset: 0x80051178
		// End Line: 1507

		/* begin block 1.2 */
			// Start line: 1511
			// Start offset: 0x800511A0
			// Variables:
		// 		struct _Segment *segment; // $v0

			/* begin block 1.2.1 */
				// Start line: 1515
				// Start offset: 0x800511C8
				// Variables:
			// 		struct _HInfo *hInfo; // $v1
			/* end block 1.2.1 */
			// End offset: 0x8005120C
			// End Line: 1519
		/* end block 1.2 */
		// End offset: 0x8005120C
		// End Line: 1520

		/* begin block 1.3 */
			// Start line: 1522
			// Start offset: 0x80051230
			// Variables:
		// 		struct AniTexInfo *aniTexInfo; // $a0
		/* end block 1.3 */
		// End offset: 0x80051278
		// End Line: 1531

		/* begin block 1.4 */
			// Start line: 1535
			// Start offset: 0x80051288
			// Variables:
		// 		struct MultiSpline *multiSpline; // $v0
		/* end block 1.4 */
		// End offset: 0x80051378
		// End Line: 1557
	/* end block 1 */
	// End offset: 0x80051480
	// End Line: 1607

	/* begin block 2 */
		// Start line: 3084
	/* end block 2 */
	// End Line: 3085

void MEMPACK_RelocateObjectType(MemHeader *newAddress,long offset,Object *oldObject)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int **ppiVar6;
  _func_7 **pp_Var7;
  int iVar8;
  ulong uVar9;
  int iVar10;
  Object *pOVar11;
  int iVar12;
  int iVar13;
  _G2AnimKeylist_Type *pKeylist;
  ulong uVar14;
  int *piVar15;
  _G2AnimKeylist_Type *offset_00;
  int iVar16;
  char *start;
  Object *end;
  
  uVar14 = 0;
  uVar1 = newAddress->memSize;
  if (newAddress[2].memSize != 0) {
    uVar14 = newAddress[2].memSize + offset;
  }
  iVar2 = *(int *)(newAddress + 3);
  iVar8 = 0;
  newAddress[2].memSize = uVar14;
  if (iVar2 != 0) {
    iVar8 = iVar2 + offset;
  }
  iVar2 = 0;
  *(int *)(newAddress + 3) = iVar8;
  if (*(int *)(newAddress + 6) != 0) {
    iVar2 = *(int *)(newAddress + 6) + offset;
  }
  uVar14 = newAddress[4].memSize;
  uVar9 = 0;
  *(int *)(newAddress + 6) = iVar2;
  if (uVar14 != 0) {
    uVar9 = uVar14 + offset;
  }
  iVar2 = *(int *)(newAddress + 5);
  iVar8 = 0;
  newAddress[4].memSize = uVar9;
  if (iVar2 != 0) {
    iVar8 = iVar2 + offset;
  }
  uVar14 = newAddress[5].memSize;
  uVar9 = 0;
  *(int *)(newAddress + 5) = iVar8;
  if (uVar14 != 0) {
    uVar9 = uVar14 + offset;
  }
  iVar8 = *(int *)(newAddress + 8);
  iVar2 = 0;
  newAddress[5].memSize = uVar9;
  if (iVar8 != 0) {
    iVar2 = iVar8 + offset;
  }
  *(int *)(newAddress + 8) = iVar2;
  if ((*(uint *)(newAddress + 1) & 0x8000000) != 0) {
    uVar14 = 0;
    if (newAddress[8].memSize != 0) {
      uVar14 = newAddress[8].memSize + offset;
    }
    iVar8 = *(int *)(newAddress + 9);
    iVar2 = 0;
    newAddress[8].memSize = uVar14;
    if (iVar8 != 0) {
      iVar2 = iVar8 + offset;
    }
    *(int *)(newAddress + 9) = iVar2;
  }
  iVar2 = 0;
  if (0 < (short)newAddress[2].magicNumber) {
    iVar8 = 0;
    do {
      piVar5 = (int *)(iVar8 + newAddress[2].memSize);
      iVar10 = *piVar5;
      iVar3 = 0;
      if (iVar10 != 0) {
        iVar3 = iVar10 + offset;
      }
      *piVar5 = iVar3;
      iVar10 = *(int *)(iVar8 + newAddress[2].memSize);
      iVar3 = 0;
      if (*(int *)(iVar10 + 4) != 0) {
        iVar3 = *(int *)(iVar10 + 4) + offset;
      }
      iVar12 = 0;
      *(int *)(iVar10 + 4) = iVar3;
      if (*(int *)(iVar10 + 0xc) != 0) {
        iVar12 = *(int *)(iVar10 + 0xc) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar10 + 0xc) = iVar12;
      if (*(int *)(iVar10 + 0x14) != 0) {
        iVar3 = *(int *)(iVar10 + 0x14) + offset;
      }
      iVar12 = 0;
      *(int *)(iVar10 + 0x14) = iVar3;
      if (*(int *)(iVar10 + 0x1c) != 0) {
        iVar12 = *(int *)(iVar10 + 0x1c) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar10 + 0x1c) = iVar12;
      if (*(int *)(iVar10 + 0x20) != 0) {
        iVar3 = *(int *)(iVar10 + 0x20) + offset;
      }
      iVar12 = 0;
      *(int *)(iVar10 + 0x20) = iVar3;
      if (*(int *)(iVar10 + 0x2c) != 0) {
        iVar12 = *(int *)(iVar10 + 0x2c) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar10 + 0x2c) = iVar12;
      if (*(int *)(iVar10 + 0x30) != 0) {
        iVar3 = *(int *)(iVar10 + 0x30) + offset;
      }
      iVar12 = 0;
      *(int *)(iVar10 + 0x30) = iVar3;
      if (*(int *)(iVar10 + 0x34) != 0) {
        iVar12 = *(int *)(iVar10 + 0x34) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar10 + 0x34) = iVar12;
      if (0 < *(int *)(iVar10 + 0x10)) {
        iVar12 = 0;
        do {
          iVar13 = *(int *)(iVar10 + 0x14) + iVar12;
          if ((*(byte *)(iVar13 + 7) & 2) != 0) {
            iVar4 = 0;
            if (*(int *)(iVar13 + 8) != 0) {
              iVar4 = *(int *)(iVar13 + 8) + offset;
            }
            *(int *)(iVar13 + 8) = iVar4;
          }
          iVar3 = iVar3 + 1;
          iVar12 = iVar12 + 0xc;
        } while (iVar3 < *(int *)(iVar10 + 0x10));
      }
      iVar3 = 0;
      if (0 < *(int *)(iVar10 + 0x18)) {
        iVar12 = 0;
        do {
          iVar13 = *(int *)(iVar10 + 0x1c) + iVar12;
          iVar4 = *(int *)(iVar13 + 0x14);
          iVar16 = 0;
          if (iVar4 != 0) {
            iVar16 = iVar4 + offset;
          }
          *(int *)(iVar13 + 0x14) = iVar16;
          if (iVar16 != 0) {
            iVar13 = 0;
            if (*(int *)(iVar16 + 4) != 0) {
              iVar13 = *(int *)(iVar16 + 4) + offset;
            }
            iVar4 = 0;
            *(int *)(iVar16 + 4) = iVar13;
            if (*(int *)(iVar16 + 0xc) != 0) {
              iVar4 = *(int *)(iVar16 + 0xc) + offset;
            }
            iVar13 = 0;
            *(int *)(iVar16 + 0xc) = iVar4;
            if (*(int *)(iVar16 + 0x14) != 0) {
              iVar13 = *(int *)(iVar16 + 0x14) + offset;
            }
            *(int *)(iVar16 + 0x14) = iVar13;
          }
          iVar3 = iVar3 + 1;
          iVar12 = iVar12 + 0x18;
        } while (iVar3 < *(int *)(iVar10 + 0x18));
      }
      piVar5 = *(int **)(iVar10 + 0x20);
      if (piVar5 != (int *)0x0) {
        piVar15 = piVar5 + 1;
        iVar3 = 0;
        if (0 < *piVar5) {
          do {
            iVar12 = 0;
            if (*piVar15 != 0) {
              iVar12 = *piVar15 + offset;
            }
            *piVar15 = iVar12;
            iVar3 = iVar3 + 1;
            piVar15 = piVar15 + 3;
          } while (iVar3 < **(int **)(iVar10 + 0x20));
        }
      }
      ppiVar6 = *(int ***)(iVar10 + 0x2c);
      if (ppiVar6 != (int **)0x0) {
        piVar5 = (int *)0x0;
        if (*ppiVar6 != (int *)0x0) {
          piVar5 = (int *)((int)*ppiVar6 + offset);
        }
        piVar15 = (int *)0x0;
        *ppiVar6 = piVar5;
        if (ppiVar6[1] != (int *)0x0) {
          piVar15 = (int *)((int)ppiVar6[1] + offset);
        }
        piVar5 = (int *)0x0;
        ppiVar6[1] = piVar15;
        if (ppiVar6[2] != (int *)0x0) {
          piVar5 = (int *)((int)ppiVar6[2] + offset);
        }
        piVar15 = (int *)0x0;
        ppiVar6[2] = piVar5;
        if (ppiVar6[3] != (int *)0x0) {
          piVar15 = (int *)((int)ppiVar6[3] + offset);
        }
        piVar5 = *ppiVar6;
        ppiVar6[3] = piVar15;
        if (piVar5 != (int *)0x0) {
          iVar3 = 0;
          if (*piVar5 != 0) {
            iVar3 = *piVar5 + offset;
          }
          *piVar5 = iVar3;
        }
        piVar5 = ppiVar6[1];
        if (piVar5 != (int *)0x0) {
          iVar3 = 0;
          if (*piVar5 != 0) {
            iVar3 = *piVar5 + offset;
          }
          *piVar5 = iVar3;
        }
        piVar5 = ppiVar6[2];
        if (piVar5 != (int *)0x0) {
          iVar3 = 0;
          if (*piVar5 != 0) {
            iVar3 = *piVar5 + offset;
          }
          *piVar5 = iVar3;
        }
        piVar5 = ppiVar6[3];
        if (piVar5 != (int *)0x0) {
          iVar3 = 0;
          if (*piVar5 != 0) {
            iVar3 = *piVar5 + offset;
          }
          *piVar5 = iVar3;
        }
      }
      iVar2 = iVar2 + 1;
      iVar8 = iVar8 + 4;
    } while (iVar2 < (short)newAddress[2].magicNumber);
  }
  iVar2 = 0;
  if (0 < *(short *)&newAddress[2].memStatus) {
    do {
      MEMPACK_RelocateG2AnimKeylistType
                ((_G2AnimKeylist_Type **)(*(int *)(newAddress + 3) + iVar2 * 4),offset,
                 (char *)oldObject,(char *)((int)&oldObject[-1].vramSize.x + uVar1));
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(short *)&newAddress[2].memStatus);
  }
  if (*(int *)(newAddress + 3) != 0) {
    offset_00 = *(_G2AnimKeylist_Type **)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
    end = (Object *)((int)&oldObject[-1].vramSize.x + uVar1);
    while (offset_00 != (_G2AnimKeylist_Type *)0x0) {
      if (*(Object **)&offset_00[1].keyCount == oldObject) {
        iVar2 = 0;
        if (*(int *)&offset_00[0x11].pad10 != 0) {
          iVar2 = *(int *)&offset_00[0x11].pad10 + offset;
        }
        *(int *)&offset_00[0x11].pad10 = iVar2;
      }
      start = (char *)0x0;
      pKeylist = offset_00;
      if (*(char *)&offset_00[0x10].sectionData != '\0') {
        do {
          pOVar11 = (Object *)pKeylist[0x13].sectionData;
          if (pOVar11 < oldObject) {
            MEMPACK_RelocateG2AnimKeylistType
                      ((_G2AnimKeylist_Type **)pKeylist,(int)offset_00,start,(char *)end);
            return;
          }
          if (end < pOVar11) {
            MEMPACK_RelocateG2AnimKeylistType
                      ((_G2AnimKeylist_Type **)pKeylist,(int)offset_00,start,(char *)end);
            return;
          }
          pp_Var7 = (_func_7 **)0x0;
          if (pOVar11 != (Object *)0x0) {
            pp_Var7 = (_func_7 **)((int)&pOVar11->oflags + offset);
          }
          pKeylist[0x13].sectionData = pp_Var7;
          start = start + 1;
          pKeylist = pKeylist + 2;
        } while ((int)start < (int)(uint)*(byte *)&offset_00[0x10].sectionData);
      }
      offset_00 = *(_G2AnimKeylist_Type **)&offset_00->pad00;
    }
  }
  STREAM_UpdateObjectPointer(oldObject,(Object *)(newAddress + 1),uVar1 - 8);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateCDMemory(struct MemHeader *newAddress /*$a0*/, long offset /*$a1*/, struct _BigFileDir *oldDir /*$a2*/)
 // line 1617, offset 0x800514b0
	/* begin block 1 */
		// Start line: 1618
		// Start offset: 0x800514B0
		// Variables:
	// 		struct _BigFileDir *newDir; // $a1
	/* end block 1 */
	// End offset: 0x800514B0
	// End Line: 1618

	/* begin block 2 */
		// Start line: 3234
	/* end block 2 */
	// End Line: 3235

void MEMPACK_RelocateCDMemory(MemHeader *newAddress,long offset,_BigFileDir *oldDir)

{
  LOAD_UpdateBigFilePointers(oldDir,(_BigFileDir *)(newAddress + 1));
  return;
}





