#include "THISDUST.H"
#include "MEMPACK.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_Init()
 // line 194, offset 0x80050090
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
  newMemTracker.rootNode = &DAT_800dfe74;
  newMemTracker.totalMemory = &DAT_0011f18c;
  newMemTracker.currentMemoryUsed = 0;
  newMemTracker.lastMemoryAddress = &DAT_801ff000;
  newMemTracker.doingGarbageCollection = 0;
  DAT_800dfe74 = 0xbade;
  DAT_800dfe76 = 0;
  DAT_800dfe77 = 0;
  DAT_800dfe78 = &DAT_0011f18c;
  return;
}



// decompiled code
// original method signature: 
// struct MemHeader * /*$ra*/ MEMPACK_GetSmallestBlockTopBottom(long allocSize /*$a0*/)
 // line 250, offset 0x800500f8
	/* begin block 1 */
		// Start line: 252
		// Start offset: 0x800500F8
		// Variables:
	// 		struct MemHeader *address; // $v1
	// 		struct MemHeader *bestAddress; // $a1
	/* end block 1 */
	// End offset: 0x80050158
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
  
  pMVar1 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
    do {
      if ((pMVar1->memStatus == '\0') && ((uint)allocSize <= pMVar1->memSize)) {
        return pMVar1;
      }
      pMVar1 = (MemHeader *)((int)&pMVar1->magicNumber + pMVar1->memSize);
    } while (pMVar1 != (MemHeader *)newMemTracker.lastMemoryAddress);
  }
  return (MemHeader *)0x0;
}



// decompiled code
// original method signature: 
// struct MemHeader * /*$ra*/ MEMPACK_GetSmallestBlockBottomTop(long allocSize /*$a0*/)
 // line 279, offset 0x80050160
	/* begin block 1 */
		// Start line: 281
		// Start offset: 0x80050160
		// Variables:
	// 		struct MemHeader *address; // $v1
	// 		struct MemHeader *bestAddress; // $a1
	/* end block 1 */
	// End offset: 0x800501C4
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
  pMVar1 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
    do {
      if (((pMVar1->memStatus == '\0') && ((uint)allocSize <= pMVar1->memSize)) &&
         ((pMVar2 == (MemHeader *)0x0 || (pMVar2 < pMVar1)))) {
        pMVar2 = pMVar1;
      }
      pMVar1 = (MemHeader *)((int)&pMVar1->magicNumber + pMVar1->memSize);
    } while (pMVar1 != (MemHeader *)newMemTracker.lastMemoryAddress);
  }
  return pMVar2;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MEMPACK_RelocatableType(long memType /*$a0*/)
 // line 312, offset 0x800501cc
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
// char * /*$ra*/ MEMPACK_Malloc(unsigned long allocSize /*$s2*/, unsigned char memType /*$s4*/)
 // line 333, offset 0x80050204
	/* begin block 1 */
		// Start line: 334
		// Start offset: 0x80050204
		// Variables:
	// 		struct MemHeader *bestAddress; // $s1
	// 		long relocatableMemory; // $s3

		/* begin block 1.1 */
			// Start line: 362
			// Start offset: 0x8005028C
			// Variables:
		// 		int curMem; // $s0
		/* end block 1.1 */
		// End offset: 0x800502A8
		// End Line: 373

		/* begin block 1.2 */
			// Start line: 400
			// Start offset: 0x80050308
			// Variables:
		// 		struct MemHeader *address; // $a1

			/* begin block 1.2.1 */
				// Start line: 420
				// Start offset: 0x8005033C
				// Variables:
			// 		long topOffset; // $a0
			/* end block 1.2.1 */
			// End offset: 0x8005033C
			// End Line: 422
		/* end block 1.2 */
		// End offset: 0x8005033C
		// End Line: 422
	/* end block 1 */
	// End offset: 0x800503AC
	// End Line: 453

	/* begin block 2 */
		// Start line: 698
	/* end block 2 */
	// End Line: 699

char * MEMPACK_Malloc(ulong allocSize,uchar memType)

{
  long lVar1;
  MemHeader *pMVar2;
  ulong uVar3;
  undefined2 *puVar4;
  MemHeader *pMVar5;
  uint allocSize_00;
  
  lVar1 = MEMPACK_RelocatableType((uint)memType);
  allocSize_00 = allocSize + 0xb & 0xfffffffc;
  do {
    if (newMemTracker.doingGarbageCollection == 0) {
      if (lVar1 != 0) {
        MEMPACK_DoGarbageCollection();
        goto LAB_80050260;
      }
LAB_80050278:
      pMVar2 = MEMPACK_GetSmallestBlockBottomTop(allocSize_00);
    }
    else {
LAB_80050260:
      if (lVar1 == 0) goto LAB_80050278;
      pMVar2 = MEMPACK_GetSmallestBlockTopBottom(allocSize_00);
    }
    uVar3 = newMemTracker.currentMemoryUsed;
    if (pMVar2 != (MemHeader *)0x0) goto LAB_800502e4;
    STREAM_TryAndDumpANonResidentObject();
  } while (uVar3 != newMemTracker.currentMemoryUsed);
  if (memType == '\x10') {
    return (char *)0x0;
  }
  MEMPACK_ReportMemory2();
  DEBUG_FatalError(
                  "Trying to fit memory size %d Type = %d\nAvailable memory : used = %d, free = %d\n"
                  );
LAB_800502e4:
  uVar3 = pMVar2->memSize;
  if (uVar3 - allocSize_00 < 8) {
    allocSize_00 = uVar3;
  }
  if (allocSize_00 == uVar3) {
    pMVar2->magicNumber = 0xbade;
  }
  else {
    puVar4 = (undefined2 *)((int)&pMVar2->magicNumber + allocSize_00);
    if (lVar1 == 0) {
      pMVar5 = (MemHeader *)((int)pMVar2 + (uVar3 - allocSize_00));
      pMVar5->magicNumber = 0xbade;
      pMVar5->memStatus = '\x01';
      pMVar5->memType = memType;
      pMVar5->memSize = allocSize_00;
      newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + allocSize_00;
      pMVar2->magicNumber = 0xbade;
      pMVar2->memStatus = '\0';
      pMVar2->memType = '\0';
      pMVar2->memSize = uVar3 - allocSize_00;
      goto LAB_800503a8;
    }
    *puVar4 = 0xbade;
    *(undefined *)(puVar4 + 1) = 0;
    *(undefined *)((int)puVar4 + 3) = 0;
    *(ulong *)(puVar4 + 2) = pMVar2->memSize - allocSize_00;
    pMVar2->magicNumber = 0xbade;
  }
  pMVar2->memStatus = '\x01';
  pMVar2->memType = memType;
  pMVar2->memSize = allocSize_00;
  newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + allocSize_00;
  pMVar5 = pMVar2;
LAB_800503a8:
  return (char *)(pMVar5 + 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMORY_MergeAddresses(struct MemHeader *firstAddress /*$a0*/, struct MemHeader *secondAddress /*$a1*/)
 // line 457, offset 0x800503cc
	/* begin block 1 */
		// Start line: 952
	/* end block 1 */
	// End Line: 953

	/* begin block 2 */
		// Start line: 958
	/* end block 2 */
	// End Line: 959

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
 // line 476, offset 0x80050414
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x80050414
		// Variables:
	// 		struct MemHeader *memAddress; // $a0
	// 		struct MemHeader *nextAddress; // $a1
	/* end block 1 */
	// End offset: 0x80050488
	// End Line: 504

	/* begin block 2 */
		// Start line: 991
	/* end block 2 */
	// End Line: 992

void MEMPACK_Return(char *address,long takeBackSize)

{
  MemHeader *firstAddress;
  int iVar1;
  
  iVar1 = takeBackSize >> 2;
  if (7 < iVar1 * 4) {
    *(int *)(address + -4) = *(int *)(address + -4) + iVar1 * -4;
    newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + iVar1 * -4;
    firstAddress = (MemHeader *)(address + *(int *)(address + -4) + -8);
    firstAddress->magicNumber = 0xbade;
    firstAddress->memStatus = '\0';
    firstAddress->memType = '\0';
    firstAddress->memSize = iVar1 * 4;
    if ((MemHeader *)(&firstAddress->magicNumber + iVar1 * 2) !=
        (MemHeader *)newMemTracker.lastMemoryAddress) {
      MEMORY_MergeAddresses(firstAddress,(MemHeader *)(&firstAddress->magicNumber + iVar1 * 2));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_Free(char *address /*$a0*/)
 // line 535, offset 0x80050498
	/* begin block 1 */
		// Start line: 536
		// Start offset: 0x80050498
		// Variables:
	// 		struct MemHeader *memAddress; // $s0
	// 		struct MemHeader *secondAddress; // $v1
	/* end block 1 */
	// End offset: 0x80050538
	// End Line: 580

	/* begin block 2 */
		// Start line: 1070
	/* end block 2 */
	// End Line: 1071

void MEMPACK_Free(char *address)

{
  MemHeader *secondAddress;
  MemHeader *secondAddress_00;
  MemHeader *firstAddress;
  
  firstAddress = (MemHeader *)(address + -8);
  address[-6] = '\0';
  address[-5] = '\0';
  newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed - *(int *)(address + -4);
  secondAddress = (MemHeader *)((int)&firstAddress->magicNumber + *(int *)(address + -4));
  secondAddress_00 = newMemTracker.rootNode;
  if (secondAddress != (MemHeader *)newMemTracker.lastMemoryAddress) {
    MEMORY_MergeAddresses(firstAddress,secondAddress);
    secondAddress_00 = newMemTracker.rootNode;
  }
  do {
    secondAddress = secondAddress_00;
    if (secondAddress == (MemHeader *)newMemTracker.lastMemoryAddress) {
      return;
    }
    secondAddress_00 = (MemHeader *)((int)&secondAddress->magicNumber + secondAddress->memSize);
  } while (secondAddress_00 != firstAddress);
  MEMORY_MergeAddresses(secondAddress,secondAddress_00);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_FreeByType(unsigned char memType /*$a0*/)
 // line 582, offset 0x80050548
	/* begin block 1 */
		// Start line: 583
		// Start offset: 0x80050548
		// Variables:
	// 		struct MemHeader *address; // $a0
	// 		int freed; // $s0
	/* end block 1 */
	// End offset: 0x800505C8
	// End Line: 604

	/* begin block 2 */
		// Start line: 1176
	/* end block 2 */
	// End Line: 1177

void MEMPACK_FreeByType(uchar memType)

{
  bool bVar1;
  MemHeader *pMVar2;
  
  do {
    bVar1 = false;
    pMVar2 = newMemTracker.rootNode;
    while (pMVar2 != (MemHeader *)newMemTracker.lastMemoryAddress) {
      if ((pMVar2->memStatus == '\x01') && (pMVar2->memType == memType)) {
        bVar1 = true;
        MEMPACK_Free((char *)(pMVar2 + 1));
        break;
      }
      pMVar2 = (MemHeader *)((int)&pMVar2->magicNumber + pMVar2->memSize);
    }
    if (!bVar1) {
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MEMPACK_Size(char *address /*$a0*/)
 // line 607, offset 0x800505e0
	/* begin block 1 */
		// Start line: 609
		// Start offset: 0x800505E0
	/* end block 1 */
	// End offset: 0x800505E0
	// End Line: 614

	/* begin block 2 */
		// Start line: 1237
	/* end block 2 */
	// End Line: 1238

	/* begin block 3 */
		// Start line: 1238
	/* end block 3 */
	// End Line: 1239

	/* begin block 4 */
		// Start line: 1243
	/* end block 4 */
	// End Line: 1244

ulong MEMPACK_Size(char *address)

{
  return *(int *)(address + -4) - 8;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MEMPACK_ReportFreeMemory()
 // line 617, offset 0x800505ec
	/* begin block 1 */
		// Start line: 1257
	/* end block 1 */
	// End Line: 1258

	/* begin block 2 */
		// Start line: 1258
	/* end block 2 */
	// End Line: 1259

/* WARNING: Unknown calling convention yet parameter storage is locked */

ulong MEMPACK_ReportFreeMemory(void)

{
  return newMemTracker.totalMemory - newMemTracker.currentMemoryUsed;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_ReportMemory2()
 // line 685, offset 0x800505fc
	/* begin block 1 */
		// Start line: 687
		// Start offset: 0x800505FC
		// Variables:
	// 		struct MemHeader *address; // $v1
	/* end block 1 */
	// End offset: 0x80050624
	// End Line: 721

	/* begin block 2 */
		// Start line: 1370
	/* end block 2 */
	// End Line: 1371

	/* begin block 3 */
		// Start line: 1327
	/* end block 3 */
	// End Line: 1328

	/* begin block 4 */
		// Start line: 1331
	/* end block 4 */
	// End Line: 1332

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_ReportMemory2(void)

{
  MemHeader *pMVar1;
  
  pMVar1 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
    do {
      pMVar1 = (MemHeader *)((int)&pMVar1->magicNumber + pMVar1->memSize);
    } while (pMVar1 != (MemHeader *)newMemTracker.lastMemoryAddress);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_ReportMemory()
 // line 723, offset 0x8005062c
	/* begin block 1 */
		// Start line: 725
		// Start offset: 0x8005062C
		// Variables:
	// 		struct MemHeader *address; // $v1
	// 		long i; // $a1
	// 		long firstTime; // $a0
	/* end block 1 */
	// End offset: 0x800506C0
	// End Line: 795

	/* begin block 2 */
		// Start line: 1402
	/* end block 2 */
	// End Line: 1403

	/* begin block 3 */
		// Start line: 1403
	/* end block 3 */
	// End Line: 1404

	/* begin block 4 */
		// Start line: 1410
	/* end block 4 */
	// End Line: 1411

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_ReportMemory(void)

{
  bool bVar1;
  MemHeader *pMVar2;
  uint uVar3;
  
  pMVar2 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
    do {
      pMVar2 = (MemHeader *)((int)&pMVar2->magicNumber + pMVar2->memSize);
    } while (pMVar2 != (MemHeader *)newMemTracker.lastMemoryAddress);
  }
  uVar3 = 0;
  do {
    bVar1 = true;
    pMVar2 = newMemTracker.rootNode;
    if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
      do {
        if (((pMVar2->memStatus != '\0') && ((uint)pMVar2->memType == uVar3)) && (bVar1)) {
          bVar1 = false;
        }
        pMVar2 = (MemHeader *)((int)&pMVar2->magicNumber + pMVar2->memSize);
      } while (pMVar2 != (MemHeader *)newMemTracker.lastMemoryAddress);
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x31);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_SetMemoryBeingStreamed(char *address /*$a0*/)
 // line 797, offset 0x800506c8
	/* begin block 1 */
		// Start line: 799
		// Start offset: 0x800506C8
	/* end block 1 */
	// End offset: 0x800506C8
	// End Line: 804

	/* begin block 2 */
		// Start line: 1586
	/* end block 2 */
	// End Line: 1587

	/* begin block 3 */
		// Start line: 1587
	/* end block 3 */
	// End Line: 1588

	/* begin block 4 */
		// Start line: 1592
	/* end block 4 */
	// End Line: 1593

void MEMPACK_SetMemoryBeingStreamed(char *address)

{
  address[-6] = '\x02';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_SetMemoryDoneStreamed(char *address /*$a0*/)
 // line 807, offset 0x800506d4
	/* begin block 1 */
		// Start line: 809
		// Start offset: 0x800506D4
	/* end block 1 */
	// End offset: 0x800506D4
	// End Line: 814

	/* begin block 2 */
		// Start line: 1606
	/* end block 2 */
	// End Line: 1607

	/* begin block 3 */
		// Start line: 1607
	/* end block 3 */
	// End Line: 1608

	/* begin block 4 */
		// Start line: 1612
	/* end block 4 */
	// End Line: 1613

void MEMPACK_SetMemoryDoneStreamed(char *address)

{
  address[-6] = '\x01';
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MEMPACK_MemoryValidFunc(char *address /*$a0*/)
 // line 822, offset 0x800506e0
	/* begin block 1 */
		// Start line: 824
		// Start offset: 0x800506E0
	/* end block 1 */
	// End offset: 0x8005070C
	// End Line: 849

	/* begin block 2 */
		// Start line: 1636
	/* end block 2 */
	// End Line: 1637

	/* begin block 3 */
		// Start line: 1637
	/* end block 3 */
	// End Line: 1638

	/* begin block 4 */
		// Start line: 1639
	/* end block 4 */
	// End Line: 1640

long MEMPACK_MemoryValidFunc(char *address)

{
  if ((address != (char *)0xfafbfcfd) && (address != (char *)0x0)) {
    return (uint)(address[-6] == '\x01');
  }
  return 0;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ MEMPACK_GarbageCollectMalloc(unsigned long *allocSize /*$s1*/, unsigned char memType /*$s3*/, unsigned long *freeSize /*$s4*/)
 // line 851, offset 0x80050714
	/* begin block 1 */
		// Start line: 852
		// Start offset: 0x80050714
		// Variables:
	// 		struct MemHeader *bestAddress; // $s0
	/* end block 1 */
	// End offset: 0x8005086C
	// End Line: 922

	/* begin block 2 */
		// Start line: 1694
	/* end block 2 */
	// End Line: 1695

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
      if (memType == '\x10') {
        return (char *)0x0;
      }
      MEMPACK_ReportMemory();
      DEBUG_FatalError(
                      "Trying to fit memory size %d Type = %d\nAvalible memory : used = %d, free = %d\n"
                      );
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
    newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + *allocSize;
    *freeSize = 0;
  }
  else {
    *freeSize = pMVar1->memSize - *allocSize;
    pMVar1->magicNumber = 0xbade;
    pMVar1->memStatus = '\x01';
    pMVar1->memType = memType;
    pMVar1->memSize = *allocSize;
    newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + *allocSize;
  }
  return (char *)(pMVar1 + 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_GarbageSplitMemoryNow(unsigned long allocSize /*$a0*/, struct MemHeader *bestAddress /*$a1*/, long memType /*$a2*/, unsigned long freeSize /*$a3*/)
 // line 924, offset 0x8005088c
	/* begin block 1 */
		// Start line: 926
		// Start offset: 0x8005088C

		/* begin block 1.1 */
			// Start line: 928
			// Start offset: 0x80050894
			// Variables:
		// 		struct MemHeader *address; // $v0
		/* end block 1.1 */
		// End offset: 0x800508A8
		// End Line: 936
	/* end block 1 */
	// End offset: 0x800508A8
	// End Line: 938

	/* begin block 2 */
		// Start line: 1845
	/* end block 2 */
	// End Line: 1846

	/* begin block 3 */
		// Start line: 1846
	/* end block 3 */
	// End Line: 1847

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
 // line 943, offset 0x800508b0
	/* begin block 1 */
		// Start line: 944
		// Start offset: 0x800508B0
		// Variables:
	// 		struct MemHeader *secondAddress; // $v1
	/* end block 1 */
	// End offset: 0x80050950
	// End Line: 980

	/* begin block 2 */
		// Start line: 1883
	/* end block 2 */
	// End Line: 1884

void MEMPACK_GarbageCollectFree(MemHeader *memAddress)

{
  MemHeader *secondAddress;
  MemHeader *secondAddress_00;
  
  memAddress->memStatus = '\0';
  memAddress->memType = '\0';
  newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed - memAddress->memSize;
  secondAddress = (MemHeader *)((int)&memAddress->magicNumber + memAddress->memSize);
  secondAddress_00 = newMemTracker.rootNode;
  if (secondAddress != (MemHeader *)newMemTracker.lastMemoryAddress) {
    MEMORY_MergeAddresses(memAddress,secondAddress);
    secondAddress_00 = newMemTracker.rootNode;
  }
  do {
    secondAddress = secondAddress_00;
    if (secondAddress == (MemHeader *)newMemTracker.lastMemoryAddress) {
      return;
    }
    secondAddress_00 = (MemHeader *)((int)&secondAddress->magicNumber + secondAddress->memSize);
  } while (secondAddress_00 != memAddress);
  MEMORY_MergeAddresses(secondAddress,secondAddress_00);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_DoGarbageCollection()
 // line 1001, offset 0x80050960
	/* begin block 1 */
		// Start line: 1002
		// Start offset: 0x80050960
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
	// End offset: 0x80050B4C
	// End Line: 1133

	/* begin block 2 */
		// Start line: 2002
	/* end block 2 */
	// End Line: 2003

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_DoGarbageCollection(void)

{
  byte memType;
  bool bVar1;
  long lVar2;
  _HModel *newHModel;
  MemHeader *memAddress;
  Level *level;
  int iVar3;
  size_t __n;
  ulong local_28;
  ulong local_24;
  
  bVar1 = false;
  local_24 = 0;
  newMemTracker.doingGarbageCollection = 1;
  do {
    iVar3 = 0;
    memAddress = newMemTracker.rootNode;
    if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
      do {
        if (memAddress->memStatus == '\0') {
          iVar3 = 1;
        }
        else {
          lVar2 = MEMPACK_RelocatableType((uint)memAddress->memType);
          if (((lVar2 != 0) && (iVar3 == 1)) && (memAddress->memStatus != '\x02')) {
            iVar3 = 2;
            break;
          }
        }
        memAddress = (MemHeader *)((int)&memAddress->magicNumber + memAddress->memSize);
      } while (memAddress != (MemHeader *)newMemTracker.lastMemoryAddress);
    }
    if (iVar3 == 2) {
      memType = memAddress->memType;
      __n = memAddress->memSize - 8;
      MEMPACK_GarbageCollectFree(memAddress);
      local_28 = __n;
      newHModel = (_HModel *)MEMPACK_GarbageCollectMalloc(&local_28,memType,&local_24);
      level = (Level *)(memAddress + 1);
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
                  aadRelocateMusicMemoryEnd(level,(int)((int)newHModel - (int)level));
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
      newMemTracker.doingGarbageCollection = 0;
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateAreaType(struct MemHeader *newAddress /*$a0*/, long offset /*$s1*/, struct Level *oldLevel /*$s3*/)
 // line 1165, offset 0x80050b78
	/* begin block 1 */
		// Start line: 1166
		// Start offset: 0x80050B78
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct _MultiSignal *msignal; // $a0
	// 		long sizeOfLevel; // $s2
	// 		long i; // $t0
	// 		long d; // $a3

		/* begin block 1.1 */
			// Start line: 1231
			// Start offset: 0x80050E98
			// Variables:
		// 		struct _Terrain *terrain; // $t1

			/* begin block 1.1.1 */
				// Start line: 1259
				// Start offset: 0x80050FB4
				// Variables:
			// 		struct Intro *intro; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 1269
					// Start offset: 0x80050FF0
					// Variables:
				// 		struct MultiSpline *multiSpline; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x800510E4
				// End Line: 1292
			/* end block 1.1.1 */
			// End offset: 0x800510F8
			// End Line: 1294

			/* begin block 1.1.2 */
				// Start line: 1312
				// Start offset: 0x80051120
				// Variables:
			// 		struct DrMoveAniTexDestInfo **dest; // $v0
			/* end block 1.1.2 */
			// End offset: 0x80051174
			// End Line: 1322

			/* begin block 1.1.3 */
				// Start line: 1365
				// Start offset: 0x800511D8
				// Variables:
			// 		struct _VMObject *vmo; // $a1
			/* end block 1.1.3 */
			// End offset: 0x800512B0
			// End Line: 1376

			/* begin block 1.1.4 */
				// Start line: 1363
				// Start offset: 0x800512C8
				// Variables:
			// 		struct BSPTree *bsp; // $t2
			// 		struct _BSPNode *node; // $a2
			// 		struct _BSPLeaf *leaf; // $a1
			/* end block 1.1.4 */
			// End offset: 0x800513E0
			// End Line: 1403
		/* end block 1.1 */
		// End offset: 0x800513E0
		// End Line: 1405
	/* end block 1 */
	// End offset: 0x80051414
	// End Line: 1423

	/* begin block 2 */
		// Start line: 2349
	/* end block 2 */
	// End Line: 2350

void MEMPACK_RelocateAreaType(MemHeader *newAddress,long offset,Level *oldLevel)

{
  int iVar1;
  _Terrain *p_Var2;
  char *pcVar3;
  _BSPNode *p_Var4;
  _BSPLeaf *p_Var5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  Intro *pIVar9;
  _TFace *p_Var10;
  DrMoveAniTex *pDVar11;
  TextureFT3 *pTVar12;
  _MorphVertex *p_Var13;
  BSPTree *pBVar14;
  _MultiSignal *multiSignal;
  int **ppiVar15;
  int iVar16;
  int iVar17;
  _TVertex *p_Var18;
  _Normal *p_Var19;
  void *pvVar20;
  TextureFT3 *pTVar21;
  _MorphColor *p_Var22;
  short *psVar23;
  int *piVar24;
  int iVar25;
  _BSPLeaf *p_Var26;
  _TFace **pp_Var27;
  int iVar28;
  int *piVar29;
  _BSPLeaf **pp_Var30;
  Level *newLevel;
  int sizeOfLevel;
  
  iVar28 = 0;
  newLevel = (Level *)(newAddress + 1);
  sizeOfLevel = newAddress->memSize - 8;
  if (*(int *)(newAddress + 1) != 0) {
    iVar28 = *(int *)(newAddress + 1) + offset;
  }
  *(int *)(newAddress + 1) = iVar28;
  uVar6 = 0;
  if (newAddress[1].memSize != 0) {
    uVar6 = newAddress[1].memSize + offset;
  }
  iVar28 = *(int *)(newAddress + 0x31);
  iVar17 = 0;
  newAddress[1].memSize = uVar6;
  if (iVar28 != 0) {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x31].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x31) = iVar17;
  if (uVar6 != 0) {
    uVar7 = uVar6 + offset;
  }
  uVar6 = 0;
  newAddress[0x31].memSize = uVar7;
  if (newAddress[2].memSize != 0) {
    uVar6 = newAddress[2].memSize + offset;
  }
  uVar7 = 0;
  newAddress[2].memSize = uVar6;
  if (newAddress[3].memSize != 0) {
    uVar7 = newAddress[3].memSize + offset;
  }
  uVar6 = 0;
  newAddress[3].memSize = uVar7;
  if (newAddress[4].memSize != 0) {
    uVar6 = newAddress[4].memSize + offset;
  }
  uVar7 = 0;
  newAddress[4].memSize = uVar6;
  if (newAddress[5].memSize != 0) {
    uVar7 = newAddress[5].memSize + offset;
  }
  uVar6 = 0;
  newAddress[5].memSize = uVar7;
  if (newAddress[6].memSize != 0) {
    uVar6 = newAddress[6].memSize + offset;
  }
  uVar7 = 0;
  newAddress[6].memSize = uVar6;
  if (newAddress[7].memSize != 0) {
    uVar7 = newAddress[7].memSize + offset;
  }
  uVar6 = 0;
  newAddress[7].memSize = uVar7;
  if (newAddress[0xc].memSize != 0) {
    uVar6 = newAddress[0xc].memSize + offset;
  }
  iVar28 = *(int *)(newAddress + 0xe);
  iVar17 = 0;
  newAddress[0xc].memSize = uVar6;
  if (iVar28 != 0) {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0xf].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0xe) = iVar17;
  if (uVar6 != 0) {
    uVar7 = uVar6 + offset;
  }
  uVar6 = 0;
  newAddress[0xf].memSize = uVar7;
  if (newAddress[0x10].memSize != 0) {
    uVar6 = newAddress[0x10].memSize + offset;
  }
  iVar28 = *(int *)(newAddress + 0x11);
  iVar17 = 0;
  newAddress[0x10].memSize = uVar6;
  if (iVar28 != 0) {
    iVar17 = iVar28 + offset;
  }
  iVar28 = 0;
  *(int *)(newAddress + 0x11) = iVar17;
  if (*(int *)(newAddress + 0x12) != 0) {
    iVar28 = *(int *)(newAddress + 0x12) + offset;
  }
  uVar6 = newAddress[0x12].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x12) = iVar28;
  if (uVar6 != 0) {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x14);
  iVar17 = 0;
  newAddress[0x12].memSize = uVar7;
  if (iVar28 != 0) {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x16].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x14) = iVar17;
  if (uVar6 != 0) {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x17);
  iVar17 = 0;
  newAddress[0x16].memSize = uVar7;
  if (iVar28 != 0) {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x17].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x17) = iVar17;
  if (uVar6 != 0) {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x18);
  iVar17 = 0;
  newAddress[0x17].memSize = uVar7;
  if (iVar28 != 0) {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x18].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x18) = iVar17;
  if (uVar6 != 0) {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x19);
  iVar17 = 0;
  newAddress[0x18].memSize = uVar7;
  if (iVar28 != 0) {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x19].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x19) = iVar17;
  if (uVar6 != 0) {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x1a);
  iVar17 = 0;
  newAddress[0x19].memSize = uVar7;
  if (iVar28 != 0) {
    iVar17 = iVar28 + offset;
  }
  iVar28 = 0;
  *(int *)(newAddress + 0x1a) = iVar17;
  if (*(int *)(newAddress + 0x1b) != 0) {
    iVar28 = *(int *)(newAddress + 0x1b) + offset;
  }
  uVar6 = newAddress[0x1b].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x1b) = iVar28;
  if (uVar6 != 0) {
    uVar7 = uVar6 + offset;
  }
  uVar6 = 0;
  newAddress[0x1b].memSize = uVar7;
  if (newAddress[0x1c].memSize != 0) {
    uVar6 = newAddress[0x1c].memSize + offset;
  }
  uVar7 = 0;
  newAddress[0x1c].memSize = uVar6;
  if (newAddress[0x1d].memSize != 0) {
    uVar7 = newAddress[0x1d].memSize + offset;
  }
  uVar6 = 0;
  newAddress[0x1d].memSize = uVar7;
  if (newAddress[0x1e].memSize != 0) {
    uVar6 = newAddress[0x1e].memSize + offset;
  }
  iVar28 = *(int *)(newAddress + 0x1e);
  iVar17 = 0;
  newAddress[0x1e].memSize = uVar6;
  if (0 < iVar28) {
    iVar28 = 0;
    do {
      piVar24 = (int *)(iVar28 + newAddress[0x1e].memSize);
      iVar1 = *piVar24;
      iVar8 = 0;
      if (iVar1 != 0) {
        iVar8 = iVar1 + offset;
      }
      *piVar24 = iVar8;
      iVar17 = iVar17 + 1;
      iVar28 = iVar28 + 0x24;
    } while (iVar17 < *(int *)(newAddress + 0x1e));
  }
  uVar6 = 0;
  if (newAddress[0x1f].memSize != 0) {
    uVar6 = newAddress[0x1f].memSize + offset;
  }
  uVar7 = 0;
  newAddress[0x1f].memSize = uVar6;
  if (newAddress[0xb].memSize != 0) {
    uVar7 = newAddress[0xb].memSize + offset;
  }
  p_Var2 = newLevel->terrain;
  newAddress[0xb].memSize = uVar7;
  if (p_Var2 != (_Terrain *)0x0) {
    pIVar9 = (Intro *)0x0;
    if (p_Var2->introList != (Intro *)0x0) {
      pIVar9 = (Intro *)(p_Var2->introList->name + offset);
    }
    p_Var18 = (_TVertex *)0x0;
    p_Var2->introList = pIVar9;
    if (p_Var2->vertexList != (_TVertex *)0x0) {
      p_Var18 = (_TVertex *)((int)&(p_Var2->vertexList->vertex).x + offset);
    }
    p_Var10 = (_TFace *)0x0;
    p_Var2->vertexList = p_Var18;
    if (p_Var2->faceList != (_TFace *)0x0) {
      p_Var10 = (_TFace *)((int)&(p_Var2->faceList->face).v0 + offset);
    }
    p_Var19 = (_Normal *)0x0;
    p_Var2->faceList = p_Var10;
    if (p_Var2->normalList != (_Normal *)0x0) {
      p_Var19 = (_Normal *)((int)&p_Var2->normalList->x + offset);
    }
    pDVar11 = (DrMoveAniTex *)0x0;
    p_Var2->normalList = p_Var19;
    if (p_Var2->aniList != (DrMoveAniTex *)0x0) {
      pDVar11 = (DrMoveAniTex *)((int)&p_Var2->aniList->numAniTextues + offset);
    }
    pvVar20 = (void *)0x0;
    p_Var2->aniList = pDVar11;
    if (p_Var2->StreamUnits != (void *)0x0) {
      pvVar20 = (void *)((int)p_Var2->StreamUnits + offset);
    }
    pTVar12 = (TextureFT3 *)0x0;
    p_Var2->StreamUnits = pvVar20;
    if (p_Var2->StartTextureList != (TextureFT3 *)0x0) {
      pTVar12 = (TextureFT3 *)(&p_Var2->StartTextureList->u0 + offset);
    }
    pTVar21 = (TextureFT3 *)0x0;
    p_Var2->StartTextureList = pTVar12;
    if (p_Var2->EndTextureList != (TextureFT3 *)0x0) {
      pTVar21 = (TextureFT3 *)(&p_Var2->EndTextureList->u0 + offset);
    }
    p_Var13 = (_MorphVertex *)0x0;
    p_Var2->EndTextureList = pTVar21;
    if (p_Var2->MorphDiffList != (_MorphVertex *)0x0) {
      p_Var13 = (_MorphVertex *)((int)&p_Var2->MorphDiffList->x + offset);
    }
    p_Var22 = (_MorphColor *)0x0;
    p_Var2->MorphDiffList = p_Var13;
    if (p_Var2->MorphColorList != (_MorphColor *)0x0) {
      p_Var22 = (_MorphColor *)((int)&p_Var2->MorphColorList->morphColor15 + offset);
    }
    pBVar14 = (BSPTree *)0x0;
    p_Var2->MorphColorList = p_Var22;
    if (p_Var2->BSPTreeArray != (BSPTree *)0x0) {
      pBVar14 = (BSPTree *)((int)&p_Var2->BSPTreeArray->bspRoot + offset);
    }
    psVar23 = (short *)0x0;
    p_Var2->BSPTreeArray = pBVar14;
    if (p_Var2->morphNormalIdx != (short *)0x0) {
      psVar23 = (short *)((int)p_Var2->morphNormalIdx + offset);
    }
    multiSignal = (_MultiSignal *)0x0;
    p_Var2->morphNormalIdx = psVar23;
    if (p_Var2->signals != (_MultiSignal *)0x0) {
      multiSignal = (_MultiSignal *)((int)&p_Var2->signals->numSignals + offset);
    }
    iVar28 = 0;
    p_Var2->signals = multiSignal;
    if (0 < p_Var2->numIntros) {
      iVar17 = 0;
      do {
        pcVar3 = p_Var2->introList->name + iVar17;
        iVar1 = 0;
        if (*(int *)(pcVar3 + 0x30) != 0) {
          iVar1 = *(int *)(pcVar3 + 0x30) + offset;
        }
        ppiVar15 = (int **)0x0;
        *(int *)(pcVar3 + 0x30) = iVar1;
        if (*(int *)(pcVar3 + 0x38) != 0) {
          ppiVar15 = (int **)(*(int *)(pcVar3 + 0x38) + offset);
        }
        *(int ***)(pcVar3 + 0x38) = ppiVar15;
        if (ppiVar15 != (int **)0x0) {
          piVar24 = (int *)0x0;
          if (*ppiVar15 != (int *)0x0) {
            piVar24 = (int *)((int)*ppiVar15 + offset);
          }
          piVar29 = (int *)0x0;
          *ppiVar15 = piVar24;
          if (ppiVar15[1] != (int *)0x0) {
            piVar29 = (int *)((int)ppiVar15[1] + offset);
          }
          piVar24 = (int *)0x0;
          ppiVar15[1] = piVar29;
          if (ppiVar15[2] != (int *)0x0) {
            piVar24 = (int *)((int)ppiVar15[2] + offset);
          }
          piVar29 = (int *)0x0;
          ppiVar15[2] = piVar24;
          if (ppiVar15[3] != (int *)0x0) {
            piVar29 = (int *)((int)ppiVar15[3] + offset);
          }
          piVar24 = *ppiVar15;
          ppiVar15[3] = piVar29;
          if (piVar24 != (int *)0x0) {
            iVar1 = 0;
            if (*piVar24 != 0) {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
          }
          piVar24 = ppiVar15[1];
          if (piVar24 != (int *)0x0) {
            iVar1 = 0;
            if (*piVar24 != 0) {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
          }
          piVar24 = ppiVar15[2];
          if (piVar24 != (int *)0x0) {
            iVar1 = 0;
            if (*piVar24 != 0) {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
          }
          piVar24 = ppiVar15[3];
          if (piVar24 != (int *)0x0) {
            iVar1 = 0;
            if (*piVar24 != 0) {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
          }
        }
        iVar1 = 0;
        if (*(int *)(pcVar3 + 0x3c) != 0) {
          iVar1 = *(int *)(pcVar3 + 0x3c) + offset;
        }
        *(int *)(pcVar3 + 0x3c) = iVar1;
        iVar28 = iVar28 + 1;
        iVar17 = iVar17 + 0x4c;
      } while (iVar28 < p_Var2->numIntros);
    }
    pDVar11 = p_Var2->aniList;
    if (((pDVar11 != (DrMoveAniTex *)0x0) && (0 < pDVar11->numAniTextues)) &&
       (iVar28 = 0, 0 < pDVar11->numAniTextues)) {
      do {
        pDVar11 = (DrMoveAniTex *)&pDVar11->aniTexInfo;
        iVar17 = 0;
        if (pDVar11->numAniTextues != 0) {
          iVar17 = pDVar11->numAniTextues + offset;
        }
        pDVar11->numAniTextues = iVar17;
        iVar28 = iVar28 + 1;
      } while (iVar28 < p_Var2->aniList->numAniTextues);
    }
    uVar6 = newAddress[1].memSize;
    if (uVar6 != 0) {
      iVar28 = 0;
      if (*(int *)(uVar6 + 8) != 0) {
        iVar28 = *(int *)(uVar6 + 8) + offset;
      }
      *(int *)(uVar6 + 8) = iVar28;
    }
    uVar6 = newAddress[0xb].memSize;
    if (uVar6 != 0) {
      iVar28 = 0;
      if (*(int *)(uVar6 + 8) != 0) {
        iVar28 = *(int *)(uVar6 + 8) + offset;
      }
      *(int *)(uVar6 + 8) = iVar28;
    }
    iVar28 = 0;
    if (0 < *(int *)(newAddress + 2)) {
      iVar17 = 0;
      do {
        iVar8 = newAddress[2].memSize + iVar17;
        iVar1 = 0;
        if (*(int *)(iVar8 + 0x20) != 0) {
          iVar1 = *(int *)(iVar8 + 0x20) + offset;
        }
        *(int *)(iVar8 + 0x20) = iVar1;
        iVar16 = *(int *)(iVar8 + 0x24);
        if (iVar16 == *(int *)((int)*(short *)(iVar8 + 8) * 4 + iVar1)) {
          iVar1 = 0;
          if (iVar16 != 0) {
            iVar1 = iVar16 + offset;
          }
          *(int *)(iVar8 + 0x24) = iVar1;
        }
        iVar1 = 0;
        if (0 < *(int *)(iVar8 + 0x1c)) {
          do {
            piVar24 = (int *)(iVar1 * 4 + *(int *)(iVar8 + 0x20));
            iVar25 = *piVar24;
            iVar16 = 0;
            if (iVar25 != 0) {
              iVar16 = iVar25 + offset;
            }
            *piVar24 = iVar16;
            iVar1 = iVar1 + 1;
          } while (iVar1 < *(int *)(iVar8 + 0x1c));
        }
        iVar1 = 0;
        if (*(int *)(iVar8 + 0x2c) != 0) {
          iVar1 = *(int *)(iVar8 + 0x2c) + offset;
        }
        iVar16 = 0;
        *(int *)(iVar8 + 0x2c) = iVar1;
        if (*(int *)(iVar8 + 0x34) != 0) {
          iVar16 = *(int *)(iVar8 + 0x34) + offset;
        }
        iVar1 = 0;
        *(int *)(iVar8 + 0x34) = iVar16;
        if (*(int *)(iVar8 + 0x38) != 0) {
          iVar1 = *(int *)(iVar8 + 0x38) + offset;
        }
        *(int *)(iVar8 + 0x38) = iVar1;
        iVar28 = iVar28 + 1;
        iVar17 = iVar17 + 0x3c;
      } while (iVar28 < *(int *)(newAddress + 2));
    }
    pBVar14 = p_Var2->BSPTreeArray;
    iVar28 = 0;
    if (0 < p_Var2->numBSPTrees) {
      pp_Var30 = &pBVar14->endLeaves;
      do {
        p_Var4 = (_BSPNode *)0x0;
        if (pBVar14->bspRoot != (_BSPNode *)0x0) {
          p_Var4 = (_BSPNode *)((int)&(pBVar14->bspRoot->sphere).position.x + offset);
        }
        pBVar14->bspRoot = p_Var4;
        p_Var26 = (_BSPLeaf *)0x0;
        if (pp_Var30[-1] != (_BSPLeaf *)0x0) {
          p_Var26 = (_BSPLeaf *)((int)&(pp_Var30[-1]->sphere).position.x + offset);
        }
        p_Var5 = (_BSPLeaf *)0x0;
        pp_Var30[-1] = p_Var26;
        if (*pp_Var30 != (_BSPLeaf *)0x0) {
          p_Var5 = (_BSPLeaf *)((int)&((*pp_Var30)->sphere).position.x + offset);
        }
        *pp_Var30 = p_Var5;
        p_Var26 = (_BSPLeaf *)pBVar14->bspRoot;
        if (p_Var26 < pp_Var30[-1]) {
          piVar24 = (int *)&(p_Var26->box).maxY;
          do {
            iVar17 = 0;
            if (piVar24[-1] != 0) {
              iVar17 = piVar24[-1] + offset;
            }
            iVar1 = 0;
            piVar24[-1] = iVar17;
            if (*piVar24 != 0) {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
            p_Var26 = (_BSPLeaf *)&(p_Var26->spectralSphere).position.z;
            piVar24 = piVar24 + 0xb;
          } while (p_Var26 < pp_Var30[-1]);
        }
        p_Var26 = pp_Var30[-1];
        if (p_Var26 < *pp_Var30) {
          pp_Var27 = &p_Var26->faceList;
          do {
            p_Var10 = (_TFace *)0x0;
            if (*pp_Var27 != (_TFace *)0x0) {
              p_Var10 = (_TFace *)((int)&((*pp_Var27)->face).v0 + offset);
            }
            *pp_Var27 = p_Var10;
            p_Var26 = p_Var26 + 1;
            pp_Var27 = pp_Var27 + 0xc;
          } while (p_Var26 < *pp_Var30);
        }
        iVar28 = iVar28 + 1;
        pp_Var30 = pp_Var30 + 9;
        pBVar14 = pBVar14 + 1;
      } while (iVar28 < p_Var2->numBSPTrees);
    }
  }
  multiSignal = *(_MultiSignal **)(newAddress + 0x1b);
  if (multiSignal < (_MultiSignal *)newAddress[0x1b].memSize) {
    do {
      multiSignal = SIGNAL_RelocateSignal(multiSignal,offset);
    } while (multiSignal < (_MultiSignal *)newAddress[0x1b].memSize);
  }
  EVENT_UpdatePuzzlePointers((EventPointers *)newAddress[0x1c].memSize,offset);
  STREAM_UpdateLevelPointer(oldLevel,newLevel,sizeOfLevel);
  EVENT_RelocateInstanceList(oldLevel,newLevel,sizeOfLevel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist /*$a0*/, int offset /*$a1*/, char *start /*$a2*/, char *end /*$a3*/)
 // line 1434, offset 0x8005145c
	/* begin block 1 */
		// Start line: 1435
		// Start offset: 0x8005145C

		/* begin block 1.1 */
			// Start line: 1438
			// Start offset: 0x80051478
			// Variables:
		// 		int j; // $a2
		// 		struct _G2AnimKeylist_Type *keylist; // $a3
		/* end block 1.1 */
		// End offset: 0x800514F4
		// End Line: 1454
	/* end block 1 */
	// End offset: 0x800514F4
	// End Line: 1455

	/* begin block 2 */
		// Start line: 3035
	/* end block 2 */
	// End Line: 3036

	/* begin block 3 */
		// Start line: 3036
	/* end block 3 */
	// End Line: 3037

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
 // line 1457, offset 0x800514fc
	/* begin block 1 */
		// Start line: 1458
		// Start offset: 0x800514FC
		// Variables:
	// 		struct _Instance *instance; // $a1
	// 		struct Object *object; // $s1
	// 		int i; // $s2
	// 		int j; // $a2
	// 		int d; // $a3
	// 		int sizeOfObject; // $s4
	// 		struct _Model *model; // $t0

		/* begin block 1.1 */
			// Start line: 1504
			// Start offset: 0x800516FC
			// Variables:
		// 		struct _MFace *mface; // $a0
		/* end block 1.1 */
		// End offset: 0x80051734
		// End Line: 1509

		/* begin block 1.2 */
			// Start line: 1513
			// Start offset: 0x8005175C
			// Variables:
		// 		struct _Segment *segment; // $v0

			/* begin block 1.2.1 */
				// Start line: 1517
				// Start offset: 0x80051784
				// Variables:
			// 		struct _HInfo *hInfo; // $v1
			/* end block 1.2.1 */
			// End offset: 0x800517C8
			// End Line: 1521
		/* end block 1.2 */
		// End offset: 0x800517C8
		// End Line: 1522

		/* begin block 1.3 */
			// Start line: 1524
			// Start offset: 0x800517EC
			// Variables:
		// 		struct AniTexInfo *aniTexInfo; // $a0
		/* end block 1.3 */
		// End offset: 0x80051834
		// End Line: 1533

		/* begin block 1.4 */
			// Start line: 1537
			// Start offset: 0x80051844
			// Variables:
		// 		struct MultiSpline *multiSpline; // $v0
		/* end block 1.4 */
		// End offset: 0x80051934
		// End Line: 1559
	/* end block 1 */
	// End offset: 0x80051A3C
	// End Line: 1609

	/* begin block 2 */
		// Start line: 3085
	/* end block 2 */
	// End Line: 3086

void MEMPACK_RelocateObjectType(MemHeader *newAddress,long offset,Object *oldObject)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int **ppiVar6;
  _Model *p_Var7;
  _G2AnimKeylist_Type *p_Var8;
  int iVar9;
  ulong uVar10;
  int iVar11;
  _Model *p_Var12;
  Object *pOVar13;
  int iVar14;
  int iVar15;
  _Instance *p_Var16;
  ulong uVar17;
  int *piVar18;
  _Instance *p_Var19;
  int iVar20;
  
  uVar17 = 0;
  uVar1 = newAddress->memSize;
  if (newAddress[2].memSize != 0) {
    uVar17 = newAddress[2].memSize + offset;
  }
  iVar2 = *(int *)(newAddress + 3);
  iVar9 = 0;
  newAddress[2].memSize = uVar17;
  if (iVar2 != 0) {
    iVar9 = iVar2 + offset;
  }
  iVar2 = 0;
  *(int *)(newAddress + 3) = iVar9;
  if (*(int *)(newAddress + 6) != 0) {
    iVar2 = *(int *)(newAddress + 6) + offset;
  }
  uVar17 = newAddress[4].memSize;
  uVar10 = 0;
  *(int *)(newAddress + 6) = iVar2;
  if (uVar17 != 0) {
    uVar10 = uVar17 + offset;
  }
  iVar2 = *(int *)(newAddress + 5);
  iVar9 = 0;
  newAddress[4].memSize = uVar10;
  if (iVar2 != 0) {
    iVar9 = iVar2 + offset;
  }
  uVar17 = newAddress[5].memSize;
  uVar10 = 0;
  *(int *)(newAddress + 5) = iVar9;
  if (uVar17 != 0) {
    uVar10 = uVar17 + offset;
  }
  iVar9 = *(int *)(newAddress + 8);
  iVar2 = 0;
  newAddress[5].memSize = uVar10;
  if (iVar9 != 0) {
    iVar2 = iVar9 + offset;
  }
  *(int *)(newAddress + 8) = iVar2;
  if ((*(uint *)(newAddress + 1) & 0x8000000) != 0) {
    uVar17 = 0;
    if (newAddress[8].memSize != 0) {
      uVar17 = newAddress[8].memSize + offset;
    }
    iVar9 = *(int *)(newAddress + 9);
    iVar2 = 0;
    newAddress[8].memSize = uVar17;
    if (iVar9 != 0) {
      iVar2 = iVar9 + offset;
    }
    *(int *)(newAddress + 9) = iVar2;
  }
  iVar2 = 0;
  if (0 < (short)newAddress[2].magicNumber) {
    iVar9 = 0;
    do {
      piVar5 = (int *)(iVar9 + newAddress[2].memSize);
      iVar11 = *piVar5;
      iVar3 = 0;
      if (iVar11 != 0) {
        iVar3 = iVar11 + offset;
      }
      *piVar5 = iVar3;
      iVar11 = *(int *)(iVar9 + newAddress[2].memSize);
      iVar3 = 0;
      if (*(int *)(iVar11 + 4) != 0) {
        iVar3 = *(int *)(iVar11 + 4) + offset;
      }
      iVar14 = 0;
      *(int *)(iVar11 + 4) = iVar3;
      if (*(int *)(iVar11 + 0xc) != 0) {
        iVar14 = *(int *)(iVar11 + 0xc) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar11 + 0xc) = iVar14;
      if (*(int *)(iVar11 + 0x14) != 0) {
        iVar3 = *(int *)(iVar11 + 0x14) + offset;
      }
      iVar14 = 0;
      *(int *)(iVar11 + 0x14) = iVar3;
      if (*(int *)(iVar11 + 0x1c) != 0) {
        iVar14 = *(int *)(iVar11 + 0x1c) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar11 + 0x1c) = iVar14;
      if (*(int *)(iVar11 + 0x20) != 0) {
        iVar3 = *(int *)(iVar11 + 0x20) + offset;
      }
      iVar14 = 0;
      *(int *)(iVar11 + 0x20) = iVar3;
      if (*(int *)(iVar11 + 0x2c) != 0) {
        iVar14 = *(int *)(iVar11 + 0x2c) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar11 + 0x2c) = iVar14;
      if (*(int *)(iVar11 + 0x30) != 0) {
        iVar3 = *(int *)(iVar11 + 0x30) + offset;
      }
      iVar14 = 0;
      *(int *)(iVar11 + 0x30) = iVar3;
      if (*(int *)(iVar11 + 0x34) != 0) {
        iVar14 = *(int *)(iVar11 + 0x34) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar11 + 0x34) = iVar14;
      if (0 < *(int *)(iVar11 + 0x10)) {
        iVar14 = 0;
        do {
          iVar15 = *(int *)(iVar11 + 0x14) + iVar14;
          if ((*(byte *)(iVar15 + 7) & 2) != 0) {
            iVar4 = 0;
            if (*(int *)(iVar15 + 8) != 0) {
              iVar4 = *(int *)(iVar15 + 8) + offset;
            }
            *(int *)(iVar15 + 8) = iVar4;
          }
          iVar3 = iVar3 + 1;
          iVar14 = iVar14 + 0xc;
        } while (iVar3 < *(int *)(iVar11 + 0x10));
      }
      iVar3 = 0;
      if (0 < *(int *)(iVar11 + 0x18)) {
        iVar14 = 0;
        do {
          iVar15 = *(int *)(iVar11 + 0x1c) + iVar14;
          iVar4 = *(int *)(iVar15 + 0x14);
          iVar20 = 0;
          if (iVar4 != 0) {
            iVar20 = iVar4 + offset;
          }
          *(int *)(iVar15 + 0x14) = iVar20;
          if (iVar20 != 0) {
            iVar15 = 0;
            if (*(int *)(iVar20 + 4) != 0) {
              iVar15 = *(int *)(iVar20 + 4) + offset;
            }
            iVar4 = 0;
            *(int *)(iVar20 + 4) = iVar15;
            if (*(int *)(iVar20 + 0xc) != 0) {
              iVar4 = *(int *)(iVar20 + 0xc) + offset;
            }
            iVar15 = 0;
            *(int *)(iVar20 + 0xc) = iVar4;
            if (*(int *)(iVar20 + 0x14) != 0) {
              iVar15 = *(int *)(iVar20 + 0x14) + offset;
            }
            *(int *)(iVar20 + 0x14) = iVar15;
          }
          iVar3 = iVar3 + 1;
          iVar14 = iVar14 + 0x18;
        } while (iVar3 < *(int *)(iVar11 + 0x18));
      }
      piVar5 = *(int **)(iVar11 + 0x20);
      if (piVar5 != (int *)0x0) {
        piVar18 = piVar5 + 1;
        iVar3 = 0;
        if (0 < *piVar5) {
          do {
            iVar14 = 0;
            if (*piVar18 != 0) {
              iVar14 = *piVar18 + offset;
            }
            *piVar18 = iVar14;
            iVar3 = iVar3 + 1;
            piVar18 = piVar18 + 3;
          } while (iVar3 < **(int **)(iVar11 + 0x20));
        }
      }
      ppiVar6 = *(int ***)(iVar11 + 0x2c);
      if (ppiVar6 != (int **)0x0) {
        piVar5 = (int *)0x0;
        if (*ppiVar6 != (int *)0x0) {
          piVar5 = (int *)((int)*ppiVar6 + offset);
        }
        piVar18 = (int *)0x0;
        *ppiVar6 = piVar5;
        if (ppiVar6[1] != (int *)0x0) {
          piVar18 = (int *)((int)ppiVar6[1] + offset);
        }
        piVar5 = (int *)0x0;
        ppiVar6[1] = piVar18;
        if (ppiVar6[2] != (int *)0x0) {
          piVar5 = (int *)((int)ppiVar6[2] + offset);
        }
        piVar18 = (int *)0x0;
        ppiVar6[2] = piVar5;
        if (ppiVar6[3] != (int *)0x0) {
          piVar18 = (int *)((int)ppiVar6[3] + offset);
        }
        piVar5 = *ppiVar6;
        ppiVar6[3] = piVar18;
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
      iVar9 = iVar9 + 4;
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
    p_Var19 = (gameTrackerX.instanceList)->first;
    while (p_Var19 != (_Instance *)0x0) {
      if (p_Var19->object == oldObject) {
        p_Var12 = (p_Var19->anim).modelData;
        p_Var7 = (_Model *)0x0;
        if (p_Var12 != (_Model *)0x0) {
          p_Var7 = (_Model *)((int)&p_Var12->numVertices + offset);
        }
        (p_Var19->anim).modelData = p_Var7;
      }
      iVar2 = 0;
      p_Var16 = p_Var19;
      if ((p_Var19->anim).sectionCount != '\0') {
        do {
          pOVar13 = (Object *)(p_Var16->anim).section[0].keylist;
          if ((oldObject <= pOVar13) &&
             (pOVar13 <= (Object *)((int)&oldObject[-1].vramSize.x + uVar1))) {
            p_Var8 = (_G2AnimKeylist_Type *)0x0;
            if (pOVar13 != (Object *)0x0) {
              p_Var8 = (_G2AnimKeylist_Type *)((int)&pOVar13->oflags + offset);
            }
            (p_Var16->anim).section[0].keylist = p_Var8;
          }
          iVar2 = iVar2 + 1;
          p_Var16 = (_Instance *)&p_Var16->introNum;
        } while (iVar2 < (int)(uint)(p_Var19->anim).sectionCount);
      }
      p_Var19 = p_Var19->next;
    }
  }
  STREAM_UpdateObjectPointer(oldObject,(Object *)(newAddress + 1),uVar1 - 8);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateCDMemory(struct MemHeader *newAddress /*$a0*/, long offset /*$a1*/, struct _BigFileDir *oldDir /*$a2*/)
 // line 1619, offset 0x80051a6c
	/* begin block 1 */
		// Start line: 1620
		// Start offset: 0x80051A6C
		// Variables:
	// 		struct _BigFileDir *newDir; // $a1
	/* end block 1 */
	// End offset: 0x80051A6C
	// End Line: 1620

	/* begin block 2 */
		// Start line: 3238
	/* end block 2 */
	// End Line: 3239

void MEMPACK_RelocateCDMemory(MemHeader *newAddress,long offset,_BigFileDir *oldDir)

{
  LOAD_UpdateBigFilePointers(oldDir,(_BigFileDir *)(newAddress + 1));
  return;
}





