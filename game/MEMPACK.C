#include "THISDUST.H"
#include "MEMPACK.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_Init()
 // line 192, offset 0x8005137c
	/* begin block 1 */
		// Start line: 384
	/* end block 1 */
	// End Line: 385

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_Init(void)

{
  newMemTracker.totalMemory = 0x11fbd4;
  newMemTracker.rootNode = (MemHeader *)&DAT_800df42c;
  DAT_800df42c = 0xbade;
  DAT_800df42e = 0;
  DAT_800df42f = 0;
  DAT_800df430 = 0x11fbd4;
  newMemTracker.currentMemoryUsed = 0;
  newMemTracker.doingGarbageCollection = 0;
  newMemTracker.lastMemoryAddress = &DAT_801ff000;
  GXFilePrint("MemPack init: %d free bytes\n");
  return;
}



// decompiled code
// original method signature: 
// struct MemHeader * /*$ra*/ MEMPACK_GetSmallestBlockTopBottom(long allocSize /*$a0*/)
 // line 246, offset 0x800513fc
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x800513FC
		// Variables:
	// 		struct MemHeader *address; // $v1
	// 		struct MemHeader *bestAddress; // $a1
	/* end block 1 */
	// End offset: 0x8005145C
	// End Line: 281

	/* begin block 2 */
		// Start line: 542
	/* end block 2 */
	// End Line: 543

	/* begin block 3 */
		// Start line: 543
	/* end block 3 */
	// End Line: 544

	/* begin block 4 */
		// Start line: 545
	/* end block 4 */
	// End Line: 546

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
 // line 287, offset 0x80051464
	/* begin block 1 */
		// Start line: 289
		// Start offset: 0x80051464
		// Variables:
	// 		struct MemHeader *address; // $v1
	// 		struct MemHeader *bestAddress; // $a1
	/* end block 1 */
	// End offset: 0x800514C8
	// End Line: 317

	/* begin block 2 */
		// Start line: 624
	/* end block 2 */
	// End Line: 625

	/* begin block 3 */
		// Start line: 625
	/* end block 3 */
	// End Line: 626

	/* begin block 4 */
		// Start line: 627
	/* end block 4 */
	// End Line: 628

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
 // line 320, offset 0x800514d0
	/* begin block 1 */
		// Start line: 690
	/* end block 1 */
	// End Line: 691

	/* begin block 2 */
		// Start line: 691
	/* end block 2 */
	// End Line: 692

long MEMPACK_RelocatableType(long memType)

{
  if ((1 < memType - 1U) && (memType != 0x2c)) {
    return 0;
  }
  return 1;
}



// decompiled code
// original method signature: 
// char * /*$ra*/ MEMPACK_Malloc(unsigned long allocSize /*$s1*/, unsigned char memType /*$s4*/)
 // line 339, offset 0x800514f8
	/* begin block 1 */
		// Start line: 340
		// Start offset: 0x800514F8
		// Variables:
	// 		struct MemHeader *bestAddress; // $s0
	// 		long relocatableMemory; // $s2

		/* begin block 1.1 */
			// Start line: 418
			// Start offset: 0x80051624
			// Variables:
		// 		struct MemHeader *address; // $a1

			/* begin block 1.1.1 */
				// Start line: 441
				// Start offset: 0x80051658
				// Variables:
			// 		long topOffset; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80051658
			// End Line: 443
		/* end block 1.1 */
		// End offset: 0x80051658
		// End Line: 443
	/* end block 1 */
	// End offset: 0x800516C8
	// End Line: 475

	/* begin block 2 */
		// Start line: 728
	/* end block 2 */
	// End Line: 729

char * MEMPACK_Malloc(ulong allocSize,uchar memType)

{
  long lVar1;
  MemHeader *pMVar2;
  ulong uVar3;
  undefined2 *puVar4;
  MemHeader *pMVar5;
  uint allocSize_00;
  
  lVar1 = MEMPACK_RelocatableType((uint)memType);
  if ((newMemTracker.doingGarbageCollection == 0) && (lVar1 != 0)) {
    MEMPACK_DoGarbageCollection();
  }
  allocSize_00 = allocSize + 0xb & 0xfffffffc;
  if (lVar1 == 0) {
    pMVar2 = MEMPACK_GetSmallestBlockBottomTop(allocSize_00);
  }
  else {
    pMVar2 = MEMPACK_GetSmallestBlockTopBottom(allocSize_00);
  }
  if (pMVar2 == (MemHeader *)0x0) {
    STREAM_DumpAMonster(allocSize_00);
    STREAM_DumpNonResidentObjects();
    if (lVar1 == 0) {
      pMVar2 = MEMPACK_GetSmallestBlockBottomTop(allocSize_00);
    }
    else {
      pMVar2 = MEMPACK_GetSmallestBlockTopBottom(allocSize_00);
    }
    if (pMVar2 == (MemHeader *)0x0) {
      if (memType == '\x10') {
        return (char *)0x0;
      }
      GXFilePrint("---------------------\n");
      MEMPACK_ReportMemory2();
      DEBUG_FatalError(
                      "Trying to fit memory size %d Type = %d\nAvailable memory : used = %d, free = %d\n"
                      );
    }
  }
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
      goto LAB_800516c4;
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
LAB_800516c4:
  return (char *)(pMVar5 + 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMORY_MergeAddresses(struct MemHeader *firstAddress /*$a0*/, struct MemHeader *secondAddress /*$a1*/)
 // line 479, offset 0x800516e8
	/* begin block 1 */
		// Start line: 1022
	/* end block 1 */
	// End Line: 1023

	/* begin block 2 */
		// Start line: 1028
	/* end block 2 */
	// End Line: 1029

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
 // line 498, offset 0x80051730
	/* begin block 1 */
		// Start line: 499
		// Start offset: 0x80051730
		// Variables:
	// 		struct MemHeader *memAddress; // $a0
	// 		struct MemHeader *nextAddress; // $a1
	/* end block 1 */
	// End offset: 0x800517A4
	// End Line: 526

	/* begin block 2 */
		// Start line: 1061
	/* end block 2 */
	// End Line: 1062

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
 // line 557, offset 0x800517b4
	/* begin block 1 */
		// Start line: 558
		// Start offset: 0x800517B4
		// Variables:
	// 		struct MemHeader *memAddress; // $s0
	// 		struct MemHeader *secondAddress; // $v1
	/* end block 1 */
	// End offset: 0x80051858
	// End Line: 602

	/* begin block 2 */
		// Start line: 1111
	/* end block 2 */
	// End Line: 1112

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
 // line 604, offset 0x80051868
	/* begin block 1 */
		// Start line: 605
		// Start offset: 0x80051868
		// Variables:
	// 		struct MemHeader *address; // $a0
	// 		int freed; // $s0
	/* end block 1 */
	// End offset: 0x800518E8
	// End Line: 626

	/* begin block 2 */
		// Start line: 1246
	/* end block 2 */
	// End Line: 1247

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
 // line 629, offset 0x80051900
	/* begin block 1 */
		// Start line: 631
		// Start offset: 0x80051900
	/* end block 1 */
	// End offset: 0x80051900
	// End Line: 636

	/* begin block 2 */
		// Start line: 1307
	/* end block 2 */
	// End Line: 1308

	/* begin block 3 */
		// Start line: 1308
	/* end block 3 */
	// End Line: 1309

	/* begin block 4 */
		// Start line: 1313
	/* end block 4 */
	// End Line: 1314

ulong MEMPACK_Size(char *address)

{
  return *(int *)(address + -4) - 8;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MEMPACK_ReportFreeMemory()
 // line 639, offset 0x8005190c
	/* begin block 1 */
		// Start line: 1327
	/* end block 1 */
	// End Line: 1328

	/* begin block 2 */
		// Start line: 1328
	/* end block 2 */
	// End Line: 1329

/* WARNING: Unknown calling convention yet parameter storage is locked */

ulong MEMPACK_ReportFreeMemory(void)

{
  return newMemTracker.totalMemory - newMemTracker.currentMemoryUsed;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_ReportMemory2()
 // line 684, offset 0x8005191c
	/* begin block 1 */
		// Start line: 685
		// Start offset: 0x8005191C
		// Variables:
	// 		struct MemHeader *address; // $s0
	// 		char *caddress; // $a1
	/* end block 1 */
	// End offset: 0x800519E4
	// End Line: 719

	/* begin block 2 */
		// Start line: 1365
	/* end block 2 */
	// End Line: 1366

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_ReportMemory2(void)

{
  char *fmt;
  MemHeader *pMVar1;
  
  GXFilePrint("----- Memory Map -----\n");
  pMVar1 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
    do {
      if (pMVar1->memStatus == '\0') {
        GXFilePrint("OPEN) addr %x size=%d\n");
      }
      else {
        if (pMVar1->memType == '\x01') {
          fmt = "CLOSED) addr %x size=%d type=OBJECT : %s\n";
        }
        else {
          if (pMVar1->memType == '\x02') {
            fmt = "CLOSED) addr %x size=%d type=AREA : %s\n";
          }
          else {
            fmt = "CLOSED) addr %x size=%d type=%d\n";
          }
        }
        GXFilePrint(fmt);
      }
      pMVar1 = (MemHeader *)((int)&pMVar1->magicNumber + pMVar1->memSize);
    } while (pMVar1 != (MemHeader *)newMemTracker.lastMemoryAddress);
  }
  GXFilePrint("Total Memory Used = %d, Total Memory Free = %d\n");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_ReportMemory()
 // line 722, offset 0x80051a08
	/* begin block 1 */
		// Start line: 723
		// Start offset: 0x80051A08
		// Variables:
	// 		struct MemHeader *address; // $s0
	// 		char *caddress; // $a1
	// 		long i; // $s2
	// 		long total; // $s1
	// 		long firstTime; // $s3
	/* end block 1 */
	// End offset: 0x80051B94
	// End Line: 793

	/* begin block 2 */
		// Start line: 1454
	/* end block 2 */
	// End Line: 1455

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MEMPACK_ReportMemory(void)

{
  bool bVar1;
  char *fmt;
  MemHeader *pMVar2;
  uint uVar3;
  
  GXFilePrint("----- Memory Map Organized By Type -----\n");
  GXFilePrint("\n-------  Open Memory Blocks ---------\n");
  pMVar2 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
    do {
      if (pMVar2->memStatus == '\0') {
        GXFilePrint("addr %x \t size=%d\n");
      }
      pMVar2 = (MemHeader *)((int)&pMVar2->magicNumber + pMVar2->memSize);
    } while (pMVar2 != (MemHeader *)newMemTracker.lastMemoryAddress);
  }
  GXFilePrint("Total Memory Open = %d\n");
  uVar3 = 0;
  do {
    bVar1 = true;
    pMVar2 = newMemTracker.rootNode;
    if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress) {
      do {
        if ((pMVar2->memStatus != '\0') && ((uint)pMVar2->memType == uVar3)) {
          if (bVar1) {
            bVar1 = false;
            GXFilePrint("\n-------  CLOSED Memory Type =%d ---------\n");
          }
          if (pMVar2->memType == '\x01') {
            fmt = "addr %x \t size=%d \t type=OBJECT : %s\n";
          }
          else {
            if (pMVar2->memType == '\x02') {
              fmt = "addr %x \t size=%d \t type=AREA : %s\n";
            }
            else {
              fmt = "addr %x \t size=%d \t type=%d\n";
            }
          }
          GXFilePrint(fmt);
        }
        pMVar2 = (MemHeader *)((int)&pMVar2->magicNumber + pMVar2->memSize);
      } while (pMVar2 != (MemHeader *)newMemTracker.lastMemoryAddress);
    }
    if (!bVar1) {
      GXFilePrint("Total Memory Used by %d = %d\n");
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x2f);
  GXFilePrint("Total Memory Used = %d, Total Memory Free = %d\n");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_SetMemoryBeingStreamed(char *address /*$a0*/)
 // line 796, offset 0x80051bc8
	/* begin block 1 */
		// Start line: 798
		// Start offset: 0x80051BC8
	/* end block 1 */
	// End offset: 0x80051BC8
	// End Line: 803

	/* begin block 2 */
		// Start line: 1652
	/* end block 2 */
	// End Line: 1653

	/* begin block 3 */
		// Start line: 1653
	/* end block 3 */
	// End Line: 1654

	/* begin block 4 */
		// Start line: 1658
	/* end block 4 */
	// End Line: 1659

void MEMPACK_SetMemoryBeingStreamed(char *address)

{
  address[-6] = '\x02';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_SetMemoryDoneStreamed(char *address /*$a0*/)
 // line 806, offset 0x80051bd4
	/* begin block 1 */
		// Start line: 808
		// Start offset: 0x80051BD4
	/* end block 1 */
	// End offset: 0x80051BD4
	// End Line: 813

	/* begin block 2 */
		// Start line: 1672
	/* end block 2 */
	// End Line: 1673

	/* begin block 3 */
		// Start line: 1673
	/* end block 3 */
	// End Line: 1674

	/* begin block 4 */
		// Start line: 1678
	/* end block 4 */
	// End Line: 1679

void MEMPACK_SetMemoryDoneStreamed(char *address)

{
  address[-6] = '\x01';
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MEMPACK_MemoryValidFunc(char *address /*$a0*/)
 // line 821, offset 0x80051be0
	/* begin block 1 */
		// Start line: 823
		// Start offset: 0x80051BE0
	/* end block 1 */
	// End offset: 0x80051C0C
	// End Line: 848

	/* begin block 2 */
		// Start line: 1702
	/* end block 2 */
	// End Line: 1703

	/* begin block 3 */
		// Start line: 1703
	/* end block 3 */
	// End Line: 1704

	/* begin block 4 */
		// Start line: 1705
	/* end block 4 */
	// End Line: 1706

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
 // line 850, offset 0x80051c14
	/* begin block 1 */
		// Start line: 851
		// Start offset: 0x80051C14
		// Variables:
	// 		struct MemHeader *bestAddress; // $s0
	/* end block 1 */
	// End offset: 0x80051D7C
	// End Line: 921

	/* begin block 2 */
		// Start line: 1760
	/* end block 2 */
	// End Line: 1761

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
      GXFilePrint("---GARBAGE COLLECT-------\n");
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
 // line 923, offset 0x80051d9c
	/* begin block 1 */
		// Start line: 925
		// Start offset: 0x80051D9C

		/* begin block 1.1 */
			// Start line: 927
			// Start offset: 0x80051DA4
			// Variables:
		// 		struct MemHeader *address; // $v0
		/* end block 1.1 */
		// End offset: 0x80051DB8
		// End Line: 935
	/* end block 1 */
	// End offset: 0x80051DB8
	// End Line: 937

	/* begin block 2 */
		// Start line: 1919
	/* end block 2 */
	// End Line: 1920

	/* begin block 3 */
		// Start line: 1920
	/* end block 3 */
	// End Line: 1921

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
 // line 942, offset 0x80051dc0
	/* begin block 1 */
		// Start line: 943
		// Start offset: 0x80051DC0
		// Variables:
	// 		struct MemHeader *secondAddress; // $v1
	/* end block 1 */
	// End offset: 0x80051E64
	// End Line: 979

	/* begin block 2 */
		// Start line: 1957
	/* end block 2 */
	// End Line: 1958

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
 // line 1000, offset 0x80051e74
	/* begin block 1 */
		// Start line: 1001
		// Start offset: 0x80051E74
		// Variables:
	// 		struct MemHeader *relocateAddress; // $s0
	// 		long foundOpening; // $s2
	// 		long done; // $s5
	// 		long addressSize; // $s4
	// 		long addressMemType; // $s3
	// 		long holdSize; // stack offset -48
	// 		long freeSize; // stack offset -44
	// 		char *oldAddress; // $s0
	// 		char *newAddress; // $s1
	/* end block 1 */
	// End offset: 0x80052028
	// End Line: 1128

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
  MemHeader *memAddress;
  Level *level;
  int iVar3;
  size_t __n;
  ulong local_30;
  ulong local_2c;
  
  bVar1 = false;
  local_2c = 0;
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
      local_30 = __n;
      newHModel = (_HModel *)MEMPACK_GarbageCollectMalloc(&local_30,memType,&local_2c);
      level = (Level *)(memAddress + 1);
      if (newHModel != (_HModel *)0x0) {
        if (memType == 2) {
          RemoveIntroducedLights(level);
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
                GXFilePrint("Bad type in garbage collects type=%d\n");
              }
            }
          }
        }
        MEMPACK_GarbageSplitMemoryNow(local_30,(MemHeader *)(newHModel + -1),(uint)memType,local_2c)
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
 // line 1156, offset 0x80052058
	/* begin block 1 */
		// Start line: 1157
		// Start offset: 0x80052058
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct _MultiSignal *msignal; // $a0
	// 		long sizeOfLevel; // $s2
	// 		long i; // $t0
	// 		long d; // $a3

		/* begin block 1.1 */
			// Start line: 1222
			// Start offset: 0x80052378
			// Variables:
		// 		struct _Terrain *terrain; // $t1

			/* begin block 1.1.1 */
				// Start line: 1244
				// Start offset: 0x800524BC
				// Variables:
			// 		struct _BSPNode *snode; // $a2
			// 		struct _SBSPLeaf *sleaf; // $a2

				/* begin block 1.1.1.1 */
					// Start line: 1253
					// Start offset: 0x800524D0
					// Variables:
				// 		struct Intro *intro; // $v0

					/* begin block 1.1.1.1.1 */
						// Start line: 1263
						// Start offset: 0x8005250C
						// Variables:
					// 		struct MultiSpline *multiSpline; // $a2
					/* end block 1.1.1.1.1 */
					// End offset: 0x80052600
					// End Line: 1286
				/* end block 1.1.1.1 */
				// End offset: 0x80052614
				// End Line: 1288

				/* begin block 1.1.1.2 */
					// Start line: 1306
					// Start offset: 0x8005263C
					// Variables:
				// 		struct DrMoveAniTexDestInfo **dest; // $v0
				/* end block 1.1.1.2 */
				// End offset: 0x80052690
				// End Line: 1316
			/* end block 1.1.1 */
			// End offset: 0x800527D4
			// End Line: 1342

			/* begin block 1.1.2 */
				// Start line: 1354
				// Start offset: 0x80052838
				// Variables:
			// 		struct _VMObject *vmo; // $a1
			/* end block 1.1.2 */
			// End offset: 0x80052910
			// End Line: 1365

			/* begin block 1.1.3 */
				// Start line: 1352
				// Start offset: 0x80052928
				// Variables:
			// 		struct BSPTree *bsp; // $t2
			// 		struct _BSPNode *node; // $a2
			// 		struct _BSPLeaf *leaf; // $a1
			/* end block 1.1.3 */
			// End offset: 0x80052A40
			// End Line: 1392
		/* end block 1.1 */
		// End offset: 0x80052A40
		// End Line: 1394
	/* end block 1 */
	// End offset: 0x80052A74
	// End Line: 1412

	/* begin block 2 */
		// Start line: 2407
	/* end block 2 */
	// End Line: 2408

void MEMPACK_RelocateAreaType(MemHeader *newAddress,long offset,Level *oldLevel)

{
  int iVar1;
  _Terrain *p_Var2;
  char *pcVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  Intro *pIVar7;
  _TFace *p_Var8;
  DrMoveAniTex *pDVar9;
  void *pvVar10;
  TextureFT3 *pTVar11;
  _MorphColor *p_Var12;
  BSPTree *pBVar13;
  int **ppiVar14;
  int iVar15;
  int iVar16;
  _TVertex *p_Var17;
  _Normal *p_Var18;
  TextureFT3 *pTVar19;
  _MorphVertex *p_Var20;
  _MultiSignal *multiSignal;
  int *piVar21;
  int iVar22;
  int iVar23;
  int *piVar24;
  short *psVar25;
  uint uVar26;
  Signal *pSVar27;
  Level *newLevel;
  int sizeOfLevel;
  
  iVar23 = 0;
  newLevel = (Level *)(newAddress + 1);
  sizeOfLevel = newAddress->memSize - 8;
  if (*(int *)(newAddress + 1) != 0) {
    iVar23 = *(int *)(newAddress + 1) + offset;
  }
  *(int *)(newAddress + 1) = iVar23;
  uVar4 = 0;
  if (newAddress[1].memSize != 0) {
    uVar4 = newAddress[1].memSize + offset;
  }
  iVar23 = *(int *)(newAddress + 0x31);
  iVar16 = 0;
  newAddress[1].memSize = uVar4;
  if (iVar23 != 0) {
    iVar16 = iVar23 + offset;
  }
  uVar4 = newAddress[0x31].memSize;
  uVar5 = 0;
  *(int *)(newAddress + 0x31) = iVar16;
  if (uVar4 != 0) {
    uVar5 = uVar4 + offset;
  }
  uVar4 = 0;
  newAddress[0x31].memSize = uVar5;
  if (newAddress[2].memSize != 0) {
    uVar4 = newAddress[2].memSize + offset;
  }
  uVar5 = 0;
  newAddress[2].memSize = uVar4;
  if (newAddress[3].memSize != 0) {
    uVar5 = newAddress[3].memSize + offset;
  }
  uVar4 = 0;
  newAddress[3].memSize = uVar5;
  if (newAddress[4].memSize != 0) {
    uVar4 = newAddress[4].memSize + offset;
  }
  uVar5 = 0;
  newAddress[4].memSize = uVar4;
  if (newAddress[5].memSize != 0) {
    uVar5 = newAddress[5].memSize + offset;
  }
  uVar4 = 0;
  newAddress[5].memSize = uVar5;
  if (newAddress[6].memSize != 0) {
    uVar4 = newAddress[6].memSize + offset;
  }
  uVar5 = 0;
  newAddress[6].memSize = uVar4;
  if (newAddress[7].memSize != 0) {
    uVar5 = newAddress[7].memSize + offset;
  }
  uVar4 = 0;
  newAddress[7].memSize = uVar5;
  if (newAddress[0xc].memSize != 0) {
    uVar4 = newAddress[0xc].memSize + offset;
  }
  iVar23 = *(int *)(newAddress + 0xe);
  iVar16 = 0;
  newAddress[0xc].memSize = uVar4;
  if (iVar23 != 0) {
    iVar16 = iVar23 + offset;
  }
  uVar4 = newAddress[0xf].memSize;
  uVar5 = 0;
  *(int *)(newAddress + 0xe) = iVar16;
  if (uVar4 != 0) {
    uVar5 = uVar4 + offset;
  }
  uVar4 = 0;
  newAddress[0xf].memSize = uVar5;
  if (newAddress[0x10].memSize != 0) {
    uVar4 = newAddress[0x10].memSize + offset;
  }
  iVar23 = *(int *)(newAddress + 0x11);
  iVar16 = 0;
  newAddress[0x10].memSize = uVar4;
  if (iVar23 != 0) {
    iVar16 = iVar23 + offset;
  }
  iVar23 = 0;
  *(int *)(newAddress + 0x11) = iVar16;
  if (*(int *)(newAddress + 0x12) != 0) {
    iVar23 = *(int *)(newAddress + 0x12) + offset;
  }
  uVar4 = newAddress[0x12].memSize;
  uVar5 = 0;
  *(int *)(newAddress + 0x12) = iVar23;
  if (uVar4 != 0) {
    uVar5 = uVar4 + offset;
  }
  iVar23 = *(int *)(newAddress + 0x14);
  iVar16 = 0;
  newAddress[0x12].memSize = uVar5;
  if (iVar23 != 0) {
    iVar16 = iVar23 + offset;
  }
  uVar4 = newAddress[0x16].memSize;
  uVar5 = 0;
  *(int *)(newAddress + 0x14) = iVar16;
  if (uVar4 != 0) {
    uVar5 = uVar4 + offset;
  }
  iVar23 = *(int *)(newAddress + 0x17);
  iVar16 = 0;
  newAddress[0x16].memSize = uVar5;
  if (iVar23 != 0) {
    iVar16 = iVar23 + offset;
  }
  uVar4 = newAddress[0x17].memSize;
  uVar5 = 0;
  *(int *)(newAddress + 0x17) = iVar16;
  if (uVar4 != 0) {
    uVar5 = uVar4 + offset;
  }
  iVar23 = *(int *)(newAddress + 0x18);
  iVar16 = 0;
  newAddress[0x17].memSize = uVar5;
  if (iVar23 != 0) {
    iVar16 = iVar23 + offset;
  }
  uVar4 = newAddress[0x18].memSize;
  uVar5 = 0;
  *(int *)(newAddress + 0x18) = iVar16;
  if (uVar4 != 0) {
    uVar5 = uVar4 + offset;
  }
  iVar23 = *(int *)(newAddress + 0x19);
  iVar16 = 0;
  newAddress[0x18].memSize = uVar5;
  if (iVar23 != 0) {
    iVar16 = iVar23 + offset;
  }
  uVar4 = newAddress[0x19].memSize;
  uVar5 = 0;
  *(int *)(newAddress + 0x19) = iVar16;
  if (uVar4 != 0) {
    uVar5 = uVar4 + offset;
  }
  iVar23 = *(int *)(newAddress + 0x1a);
  iVar16 = 0;
  newAddress[0x19].memSize = uVar5;
  if (iVar23 != 0) {
    iVar16 = iVar23 + offset;
  }
  iVar23 = 0;
  *(int *)(newAddress + 0x1a) = iVar16;
  if (*(int *)(newAddress + 0x1b) != 0) {
    iVar23 = *(int *)(newAddress + 0x1b) + offset;
  }
  uVar4 = newAddress[0x1b].memSize;
  uVar5 = 0;
  *(int *)(newAddress + 0x1b) = iVar23;
  if (uVar4 != 0) {
    uVar5 = uVar4 + offset;
  }
  uVar4 = 0;
  newAddress[0x1b].memSize = uVar5;
  if (newAddress[0x1c].memSize != 0) {
    uVar4 = newAddress[0x1c].memSize + offset;
  }
  uVar5 = 0;
  newAddress[0x1c].memSize = uVar4;
  if (newAddress[0x1d].memSize != 0) {
    uVar5 = newAddress[0x1d].memSize + offset;
  }
  uVar4 = 0;
  newAddress[0x1d].memSize = uVar5;
  if (newAddress[0x1e].memSize != 0) {
    uVar4 = newAddress[0x1e].memSize + offset;
  }
  iVar23 = *(int *)(newAddress + 0x1e);
  iVar16 = 0;
  newAddress[0x1e].memSize = uVar4;
  if (0 < iVar23) {
    iVar23 = 0;
    do {
      piVar21 = (int *)(iVar23 + newAddress[0x1e].memSize);
      iVar1 = *piVar21;
      iVar6 = 0;
      if (iVar1 != 0) {
        iVar6 = iVar1 + offset;
      }
      *piVar21 = iVar6;
      iVar16 = iVar16 + 1;
      iVar23 = iVar23 + 0x24;
    } while (iVar16 < *(int *)(newAddress + 0x1e));
  }
  uVar4 = 0;
  if (newAddress[0x1f].memSize != 0) {
    uVar4 = newAddress[0x1f].memSize + offset;
  }
  uVar5 = 0;
  newAddress[0x1f].memSize = uVar4;
  if (newAddress[0xb].memSize != 0) {
    uVar5 = newAddress[0xb].memSize + offset;
  }
  p_Var2 = newLevel->terrain;
  newAddress[0xb].memSize = uVar5;
  if (p_Var2 != (_Terrain *)0x0) {
    pIVar7 = (Intro *)0x0;
    if (p_Var2->introList != (Intro *)0x0) {
      pIVar7 = (Intro *)(p_Var2->introList->name + offset);
    }
    p_Var17 = (_TVertex *)0x0;
    p_Var2->introList = pIVar7;
    if (p_Var2->vertexList != (_TVertex *)0x0) {
      p_Var17 = (_TVertex *)((int)&(p_Var2->vertexList->vertex).x + offset);
    }
    p_Var8 = (_TFace *)0x0;
    p_Var2->vertexList = p_Var17;
    if (p_Var2->faceList != (_TFace *)0x0) {
      p_Var8 = (_TFace *)((int)&(p_Var2->faceList->face)._2 + offset);
    }
    p_Var18 = (_Normal *)0x0;
    p_Var2->faceList = p_Var8;
    if (p_Var2->normalList != (_Normal *)0x0) {
      p_Var18 = (_Normal *)((int)&p_Var2->normalList->x + offset);
    }
    pDVar9 = (DrMoveAniTex *)0x0;
    p_Var2->normalList = p_Var18;
    if (p_Var2->aniList != (DrMoveAniTex *)0x0) {
      pDVar9 = (DrMoveAniTex *)((int)&p_Var2->aniList->numAniTextues + offset);
    }
    iVar23 = 0;
    p_Var2->aniList = pDVar9;
    if (p_Var2->pad != 0) {
      iVar23 = p_Var2->pad + offset;
    }
    pvVar10 = (void *)0x0;
    p_Var2->pad = iVar23;
    if (p_Var2->StreamUnits != (void *)0x0) {
      pvVar10 = (void *)((int)p_Var2->StreamUnits + offset);
    }
    pTVar19 = (TextureFT3 *)0x0;
    p_Var2->StreamUnits = pvVar10;
    if (p_Var2->StartTextureList != (TextureFT3 *)0x0) {
      pTVar19 = (TextureFT3 *)(&p_Var2->StartTextureList->u0 + offset);
    }
    pTVar11 = (TextureFT3 *)0x0;
    p_Var2->StartTextureList = pTVar19;
    if (p_Var2->EndTextureList != (TextureFT3 *)0x0) {
      pTVar11 = (TextureFT3 *)(&p_Var2->EndTextureList->u0 + offset);
    }
    p_Var20 = (_MorphVertex *)0x0;
    p_Var2->EndTextureList = pTVar11;
    if (p_Var2->MorphDiffList != (_MorphVertex *)0x0) {
      p_Var20 = (_MorphVertex *)((int)&p_Var2->MorphDiffList->x + offset);
    }
    p_Var12 = (_MorphColor *)0x0;
    p_Var2->MorphDiffList = p_Var20;
    if (p_Var2->MorphColorList != (_MorphColor *)0x0) {
      p_Var12 = (_MorphColor *)((int)&p_Var2->MorphColorList->morphColor15 + offset);
    }
    iVar23 = 0;
    p_Var2->MorphColorList = p_Var12;
    if (p_Var2->numBSPTrees != 0) {
      iVar23 = p_Var2->numBSPTrees + offset;
    }
    pBVar13 = (BSPTree *)0x0;
    p_Var2->numBSPTrees = iVar23;
    if (p_Var2->BSPTreeArray != (BSPTree *)0x0) {
      pBVar13 = (BSPTree *)((int)&p_Var2->BSPTreeArray->bspRoot + offset);
    }
    multiSignal = (_MultiSignal *)0x0;
    p_Var2->BSPTreeArray = pBVar13;
    if (p_Var2->signals != (_MultiSignal *)0x0) {
      multiSignal = (_MultiSignal *)((int)&p_Var2->signals->numSignals + offset);
    }
    iVar23 = 0;
    p_Var2->signals = multiSignal;
    if (*(int *)(p_Var2 + 1) != 0) {
      iVar23 = *(int *)(p_Var2 + 1) + offset;
    }
    iVar16 = p_Var2[1].lpad2;
    iVar1 = 0;
    *(int *)(p_Var2 + 1) = iVar23;
    if (iVar16 != 0) {
      iVar1 = iVar16 + offset;
    }
    iVar23 = p_Var2->numIntros;
    iVar16 = 0;
    p_Var2[1].lpad2 = iVar1;
    if (0 < iVar23) {
      iVar23 = 0;
      do {
        pcVar3 = p_Var2->introList->name + iVar23;
        iVar1 = 0;
        if (*(int *)(pcVar3 + 0x30) != 0) {
          iVar1 = *(int *)(pcVar3 + 0x30) + offset;
        }
        ppiVar14 = (int **)0x0;
        *(int *)(pcVar3 + 0x30) = iVar1;
        if (*(int *)(pcVar3 + 0x38) != 0) {
          ppiVar14 = (int **)(*(int *)(pcVar3 + 0x38) + offset);
        }
        *(int ***)(pcVar3 + 0x38) = ppiVar14;
        if (ppiVar14 != (int **)0x0) {
          piVar21 = (int *)0x0;
          if (*ppiVar14 != (int *)0x0) {
            piVar21 = (int *)((int)*ppiVar14 + offset);
          }
          piVar24 = (int *)0x0;
          *ppiVar14 = piVar21;
          if (ppiVar14[1] != (int *)0x0) {
            piVar24 = (int *)((int)ppiVar14[1] + offset);
          }
          piVar21 = (int *)0x0;
          ppiVar14[1] = piVar24;
          if (ppiVar14[2] != (int *)0x0) {
            piVar21 = (int *)((int)ppiVar14[2] + offset);
          }
          piVar24 = (int *)0x0;
          ppiVar14[2] = piVar21;
          if (ppiVar14[3] != (int *)0x0) {
            piVar24 = (int *)((int)ppiVar14[3] + offset);
          }
          piVar21 = *ppiVar14;
          ppiVar14[3] = piVar24;
          if (piVar21 != (int *)0x0) {
            iVar1 = 0;
            if (*piVar21 != 0) {
              iVar1 = *piVar21 + offset;
            }
            *piVar21 = iVar1;
          }
          piVar21 = ppiVar14[1];
          if (piVar21 != (int *)0x0) {
            iVar1 = 0;
            if (*piVar21 != 0) {
              iVar1 = *piVar21 + offset;
            }
            *piVar21 = iVar1;
          }
          piVar21 = ppiVar14[2];
          if (piVar21 != (int *)0x0) {
            iVar1 = 0;
            if (*piVar21 != 0) {
              iVar1 = *piVar21 + offset;
            }
            *piVar21 = iVar1;
          }
          piVar21 = ppiVar14[3];
          if (piVar21 != (int *)0x0) {
            iVar1 = 0;
            if (*piVar21 != 0) {
              iVar1 = *piVar21 + offset;
            }
            *piVar21 = iVar1;
          }
        }
        iVar1 = 0;
        if (*(int *)(pcVar3 + 0x3c) != 0) {
          iVar1 = *(int *)(pcVar3 + 0x3c) + offset;
        }
        *(int *)(pcVar3 + 0x3c) = iVar1;
        iVar16 = iVar16 + 1;
        iVar23 = iVar23 + 0x4c;
      } while (iVar16 < p_Var2->numIntros);
    }
    pDVar9 = p_Var2->aniList;
    if (((pDVar9 != (DrMoveAniTex *)0x0) && (0 < pDVar9->numAniTextues)) &&
       (iVar23 = 0, 0 < pDVar9->numAniTextues)) {
      do {
        pDVar9 = (DrMoveAniTex *)&pDVar9->aniTexInfo;
        iVar16 = 0;
        if (pDVar9->numAniTextues != 0) {
          iVar16 = pDVar9->numAniTextues + offset;
        }
        pDVar9->numAniTextues = iVar16;
        iVar23 = iVar23 + 1;
      } while (iVar23 < p_Var2->aniList->numAniTextues);
    }
    p_Var20 = (_MorphVertex *)p_Var2->pad;
    if (p_Var20 < p_Var2->MorphDiffList) {
      piVar21 = (int *)&p_Var20[1].hy;
      do {
        iVar23 = 0;
        if (piVar21[-1] != 0) {
          iVar23 = piVar21[-1] + offset;
        }
        iVar16 = 0;
        piVar21[-1] = iVar23;
        if (*piVar21 != 0) {
          iVar16 = *piVar21 + offset;
        }
        *piVar21 = iVar16;
        p_Var20 = (_MorphVertex *)&p_Var20[3].y;
        piVar21 = piVar21 + 0xb;
      } while (p_Var20 < p_Var2->MorphDiffList);
    }
    p_Var20 = p_Var2->MorphDiffList;
    if (p_Var20 < (_MorphVertex *)p_Var2->MorphColorList) {
      psVar25 = &p_Var20[1].vindex;
      do {
        iVar23 = 0;
        if (*(int *)(psVar25 + -6) != 0) {
          iVar23 = *(int *)(psVar25 + -6) + offset;
        }
        iVar16 = 0;
        *(int *)(psVar25 + -6) = iVar23;
        if (0 < psVar25[-4]) {
          do {
            piVar21 = (int *)(iVar16 * 4 + *(int *)(psVar25 + -6));
            iVar1 = *piVar21;
            iVar23 = 0;
            if (iVar1 != 0) {
              iVar23 = iVar1 + offset;
            }
            *piVar21 = iVar23;
            iVar16 = iVar16 + 1;
          } while (iVar16 < psVar25[-4]);
        }
        iVar23 = 0;
        if (*(int *)(psVar25 + -2) != 0) {
          iVar23 = *(int *)(psVar25 + -2) + offset;
        }
        iVar16 = 0;
        *(int *)(psVar25 + -2) = iVar23;
        if (0 < *psVar25) {
          do {
            piVar21 = (int *)(iVar16 * 4 + *(int *)(psVar25 + -2));
            iVar1 = *piVar21;
            iVar23 = 0;
            if (iVar1 != 0) {
              iVar23 = iVar1 + offset;
            }
            *piVar21 = iVar23;
            iVar16 = iVar16 + 1;
          } while (iVar16 < *psVar25);
        }
        p_Var20 = (_MorphVertex *)&p_Var20[1].hy;
        psVar25 = psVar25 + 0xc;
      } while (p_Var20 < (_MorphVertex *)p_Var2->MorphColorList);
    }
    uVar4 = newAddress[1].memSize;
    if (uVar4 != 0) {
      iVar23 = 0;
      if (*(int *)(uVar4 + 8) != 0) {
        iVar23 = *(int *)(uVar4 + 8) + offset;
      }
      *(int *)(uVar4 + 8) = iVar23;
    }
    uVar4 = newAddress[0xb].memSize;
    if (uVar4 != 0) {
      iVar23 = 0;
      if (*(int *)(uVar4 + 8) != 0) {
        iVar23 = *(int *)(uVar4 + 8) + offset;
      }
      *(int *)(uVar4 + 8) = iVar23;
    }
    iVar23 = 0;
    if (0 < *(int *)(newAddress + 2)) {
      iVar16 = 0;
      do {
        iVar6 = newAddress[2].memSize + iVar16;
        iVar1 = 0;
        if (*(int *)(iVar6 + 0x20) != 0) {
          iVar1 = *(int *)(iVar6 + 0x20) + offset;
        }
        *(int *)(iVar6 + 0x20) = iVar1;
        iVar15 = *(int *)(iVar6 + 0x24);
        if (iVar15 == *(int *)((int)*(short *)(iVar6 + 8) * 4 + iVar1)) {
          iVar1 = 0;
          if (iVar15 != 0) {
            iVar1 = iVar15 + offset;
          }
          *(int *)(iVar6 + 0x24) = iVar1;
        }
        iVar1 = 0;
        if (0 < *(int *)(iVar6 + 0x1c)) {
          do {
            piVar21 = (int *)(iVar1 * 4 + *(int *)(iVar6 + 0x20));
            iVar22 = *piVar21;
            iVar15 = 0;
            if (iVar22 != 0) {
              iVar15 = iVar22 + offset;
            }
            *piVar21 = iVar15;
            iVar1 = iVar1 + 1;
          } while (iVar1 < *(int *)(iVar6 + 0x1c));
        }
        iVar1 = 0;
        if (*(int *)(iVar6 + 0x2c) != 0) {
          iVar1 = *(int *)(iVar6 + 0x2c) + offset;
        }
        iVar15 = 0;
        *(int *)(iVar6 + 0x2c) = iVar1;
        if (*(int *)(iVar6 + 0x34) != 0) {
          iVar15 = *(int *)(iVar6 + 0x34) + offset;
        }
        iVar1 = 0;
        *(int *)(iVar6 + 0x34) = iVar15;
        if (*(int *)(iVar6 + 0x38) != 0) {
          iVar1 = *(int *)(iVar6 + 0x38) + offset;
        }
        *(int *)(iVar6 + 0x38) = iVar1;
        iVar23 = iVar23 + 1;
        iVar16 = iVar16 + 0x3c;
      } while (iVar23 < *(int *)(newAddress + 2));
    }
    multiSignal = p_Var2->signals;
    iVar23 = 0;
    if (0 < (int)p_Var2->morphNormalIdx) {
      pSVar27 = multiSignal->signalList;
      do {
        iVar16 = 0;
        if (multiSignal->numSignals != 0) {
          iVar16 = multiSignal->numSignals + offset;
        }
        multiSignal->numSignals = iVar16;
        iVar16 = 0;
        if (*(int *)(pSVar27[-1].data + 0x14) != 0) {
          iVar16 = *(int *)(pSVar27[-1].data + 0x14) + offset;
        }
        iVar6 = pSVar27->id;
        iVar1 = 0;
        *(int *)(pSVar27[-1].data + 0x14) = iVar16;
        if (iVar6 != 0) {
          iVar1 = iVar6 + offset;
        }
        pSVar27->id = iVar1;
        uVar26 = multiSignal->numSignals;
        if (uVar26 < *(uint *)(pSVar27[-1].data + 0x14)) {
          piVar21 = (int *)(uVar26 + 0x18);
          do {
            iVar16 = 0;
            if (piVar21[-1] != 0) {
              iVar16 = piVar21[-1] + offset;
            }
            iVar1 = 0;
            piVar21[-1] = iVar16;
            if (*piVar21 != 0) {
              iVar1 = *piVar21 + offset;
            }
            *piVar21 = iVar1;
            uVar26 = uVar26 + 0x2c;
            piVar21 = piVar21 + 0xb;
          } while (uVar26 < *(uint *)(pSVar27[-1].data + 0x14));
        }
        uVar26 = *(uint *)(pSVar27[-1].data + 0x14);
        if (uVar26 < (uint)pSVar27->id) {
          piVar21 = (int *)(uVar26 + 8);
          do {
            iVar16 = 0;
            if (*piVar21 != 0) {
              iVar16 = *piVar21 + offset;
            }
            *piVar21 = iVar16;
            uVar26 = uVar26 + 0x30;
            piVar21 = piVar21 + 0xc;
          } while (uVar26 < (uint)pSVar27->id);
        }
        iVar23 = iVar23 + 1;
        pSVar27 = (Signal *)(pSVar27[1].data + 4);
        multiSignal = (_MultiSignal *)(multiSignal->signalList + 1);
      } while (iVar23 < (int)p_Var2->morphNormalIdx);
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
  LIGHT_RelocateLights(gameTrackerX.lightInfo,oldLevel,sizeOfLevel,offset);
  EVENT_RelocateInstanceList(oldLevel,newLevel,sizeOfLevel);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateG2AnimKeylistType(struct _G2AnimKeylist_Type **pKeylist /*$a0*/, int offset /*$a1*/, char *start /*$a2*/, char *end /*$a3*/)
 // line 1422, offset 0x80052ad0
	/* begin block 1 */
		// Start line: 1423
		// Start offset: 0x80052AD0

		/* begin block 1.1 */
			// Start line: 1426
			// Start offset: 0x80052AEC
			// Variables:
		// 		int j; // $a2
		// 		struct _G2AnimKeylist_Type *keylist; // $a3
		/* end block 1.1 */
		// End offset: 0x80052B68
		// End Line: 1442
	/* end block 1 */
	// End offset: 0x80052B68
	// End Line: 1443

	/* begin block 2 */
		// Start line: 3107
	/* end block 2 */
	// End Line: 3108

	/* begin block 3 */
		// Start line: 3108
	/* end block 3 */
	// End Line: 3109

void MEMPACK_RelocateG2AnimKeylistType
               (_G2AnimKeylist_Type **pKeylist,int offset,char *start,char *end)

{
  _G2AnimKeylist_Type *p_Var1;
  _func_4395 **pp_Var2;
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
          pp_Var2 = (_func_4395 **)0x0;
          if (p_Var3->sectionData != (_func_4395 **)0x0) {
            pp_Var2 = (_func_4395 **)((int)p_Var3->sectionData + offset);
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
 // line 1445, offset 0x80052b70
	/* begin block 1 */
		// Start line: 1446
		// Start offset: 0x80052B70
		// Variables:
	// 		struct _Instance *instance; // $a1
	// 		struct Object *object; // $s1
	// 		int i; // $s2
	// 		int j; // $a2
	// 		int d; // $a3
	// 		int sizeOfObject; // $s4
	// 		struct _Model *model; // $t0

		/* begin block 1.1 */
			// Start line: 1492
			// Start offset: 0x80052D70
			// Variables:
		// 		struct _MFace *mface; // $a0
		/* end block 1.1 */
		// End offset: 0x80052DA8
		// End Line: 1497

		/* begin block 1.2 */
			// Start line: 1501
			// Start offset: 0x80052DD0
			// Variables:
		// 		struct _Segment *segment; // $v0

			/* begin block 1.2.1 */
				// Start line: 1505
				// Start offset: 0x80052DF8
				// Variables:
			// 		struct _HInfo *hInfo; // $v1
			/* end block 1.2.1 */
			// End offset: 0x80052E3C
			// End Line: 1509
		/* end block 1.2 */
		// End offset: 0x80052E3C
		// End Line: 1510

		/* begin block 1.3 */
			// Start line: 1512
			// Start offset: 0x80052E60
			// Variables:
		// 		struct AniTexInfo *aniTexInfo; // $a0
		/* end block 1.3 */
		// End offset: 0x80052EA8
		// End Line: 1521

		/* begin block 1.4 */
			// Start line: 1525
			// Start offset: 0x80052EB8
			// Variables:
		// 		struct MultiSpline *multiSpline; // $v0
		/* end block 1.4 */
		// End offset: 0x80052FA8
		// End Line: 1547
	/* end block 1 */
	// End offset: 0x800530B0
	// End Line: 1597

	/* begin block 2 */
		// Start line: 3157
	/* end block 2 */
	// End Line: 3158

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
// int /*$ra*/ MEMPACK_AvailableMemory()
 // line 1601, offset 0x800530e0
	/* begin block 1 */
		// Start line: 3583
	/* end block 1 */
	// End Line: 3584

	/* begin block 2 */
		// Start line: 3584
	/* end block 2 */
	// End Line: 3585

/* WARNING: Unknown calling convention yet parameter storage is locked */

int MEMPACK_AvailableMemory(void)

{
  return newMemTracker.totalMemory - newMemTracker.currentMemoryUsed;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MEMPACK_RelocateCDMemory(struct MemHeader *newAddress /*$a0*/, long offset /*$a1*/, struct _BigFileDir *oldDir /*$a2*/)
 // line 1607, offset 0x800530f0
	/* begin block 1 */
		// Start line: 1608
		// Start offset: 0x800530F0
		// Variables:
	// 		struct _BigFileDir *newDir; // $a1
	/* end block 1 */
	// End offset: 0x800530F0
	// End Line: 1608

	/* begin block 2 */
		// Start line: 3595
	/* end block 2 */
	// End Line: 3596

void MEMPACK_RelocateCDMemory(MemHeader *newAddress,long offset,_BigFileDir *oldDir)

{
  LOAD_UpdateBigFilePointers(oldDir,(_BigFileDir *)(newAddress + 1));
  return;
}





