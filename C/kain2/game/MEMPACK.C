#include "THISDUST.H"
#include "MEMPACK.H"

// NewMemTracker @0x800D18D4, len = 0x00000014
newMemTracker =
    {
        // MemHeader * @0x800D18D4, len = 0x00000004
        .rootNode = null,
        // ulong @0x800D18D8, len = 0x00000004
        .totalMemory = null,
        // ulong @0x800D18DC, len = 0x00000004
        .currentMemoryUsed = null,
        // char * @0x800D18E0, len = 0x00000004
        .lastMemoryAddress = null,
        // long @0x800D18E4, len = 0x00000004
        .doingGarbageCollection = null};
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
  newMemTracker.totalMemory = (ulong)(&DAT_801ff000 + -(int)overlayAddress);
  newMemTracker.rootNode = (MemHeader *)overlayAddress;
  *(undefined2 *)overlayAddress = 0xbade;
  (newMemTracker.rootNode)->memStatus = '\0';
  (newMemTracker.rootNode)->memType = '\0';
  (newMemTracker.rootNode)->memSize = newMemTracker.totalMemory;
  newMemTracker.currentMemoryUsed = 0;
  newMemTracker.lastMemoryAddress =
      (char *)((int)&(newMemTracker.rootNode)->magicNumber + newMemTracker.totalMemory);
  newMemTracker.doingGarbageCollection = 0;
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

MemHeader *MEMPACK_GetSmallestBlockTopBottom(long allocSize)

{
  MemHeader *pMVar1;

  pMVar1 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress)
  {
    do
    {
      if ((pMVar1->memStatus == '\0') && ((uint)allocSize <= pMVar1->memSize))
      {
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

MemHeader *MEMPACK_GetSmallestBlockBottomTop(long allocSize)

{
  MemHeader *pMVar1;
  MemHeader *pMVar2;

  pMVar2 = (MemHeader *)0x0;
  pMVar1 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress)
  {
    do
    {
      if (((pMVar1->memStatus == '\0') && ((uint)allocSize <= pMVar1->memSize)) &&
          ((pMVar2 == (MemHeader *)0x0 || (pMVar2 < pMVar1))))
      {
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
  if ((((1 < memType - 1U) && (memType != 0x2c)) && (memType != 0x2f)) && (memType != 4))
  {
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

char *MEMPACK_Malloc(ulong allocSize, uchar memType)

{
  char *pcVar1;

  pcVar1 = MEMPACK_MallocFailOk(allocSize, memType);
  if (pcVar1 == (char *)0x0)
  {
    MEMPACK_ReportMemory2();
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

char *MEMPACK_MallocFailOk(ulong allocSize, uchar memType)

{
  long lVar1;
  MemHeader *pMVar2;
  ulong uVar3;
  MemHeader *pMVar4;
  undefined2 *puVar5;
  uint allocSize_00;

  lVar1 = MEMPACK_RelocatableType((uint)memType);
  allocSize_00 = allocSize + 0xb & 0xfffffffc;
  do
  {
    if (newMemTracker.doingGarbageCollection == 0)
    {
      if (lVar1 != 0)
      {
        MEMPACK_DoGarbageCollection();
        goto LAB_8004fcec;
      }
    LAB_8004fd04:
      pMVar2 = MEMPACK_GetSmallestBlockBottomTop(allocSize_00);
    }
    else
    {
    LAB_8004fcec:
      if (lVar1 == 0)
        goto LAB_8004fd04;
      pMVar2 = MEMPACK_GetSmallestBlockTopBottom(allocSize_00);
    }
    uVar3 = newMemTracker.currentMemoryUsed;
    if (pMVar2 != (MemHeader *)0x0)
    {
      uVar3 = pMVar2->memSize;
      if (uVar3 - allocSize_00 < 8)
      {
        allocSize_00 = uVar3;
      }
      if (allocSize_00 == uVar3)
      {
        pMVar2->magicNumber = 0xbade;
      }
      else
      {
        puVar5 = (undefined2 *)((int)&pMVar2->magicNumber + allocSize_00);
        if (lVar1 == 0)
        {
          pMVar4 = (MemHeader *)((int)pMVar2 + (uVar3 - allocSize_00));
          pMVar4->magicNumber = 0xbade;
          pMVar4->memStatus = '\x01';
          pMVar4->memType = memType;
          pMVar4->memSize = allocSize_00;
          newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + allocSize_00;
          pMVar2->magicNumber = 0xbade;
          pMVar2->memStatus = '\0';
          pMVar2->memType = '\0';
          pMVar2->memSize = uVar3 - allocSize_00;
          goto LAB_8004fe00;
        }
        *puVar5 = 0xbade;
        *(undefined *)(puVar5 + 1) = 0;
        *(undefined *)((int)puVar5 + 3) = 0;
        *(ulong *)(puVar5 + 2) = pMVar2->memSize - allocSize_00;
        pMVar2->magicNumber = 0xbade;
      }
      pMVar2->memStatus = '\x01';
      pMVar2->memType = memType;
      pMVar2->memSize = allocSize_00;
      newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + allocSize_00;
      pMVar4 = pMVar2;
    LAB_8004fe00:
      return (char *)(pMVar4 + 1);
    }
    STREAM_TryAndDumpANonResidentObject();
    if (uVar3 == newMemTracker.currentMemoryUsed)
    {
      return (char *)0x0;
    }
  } while (true);
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

void MEMORY_MergeAddresses(MemHeader *firstAddress, MemHeader *secondAddress)

{
  if ((firstAddress->memStatus == '\0') && (secondAddress->memStatus == '\0'))
  {
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

void MEMPACK_Return(char *address, long takeBackSize)

{
  MemHeader *firstAddress;
  int iVar1;

  iVar1 = takeBackSize >> 2;
  if (7 < iVar1 * 4)
  {
    *(int *)(address + -4) = *(int *)(address + -4) + iVar1 * -4;
    newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + iVar1 * -4;
    firstAddress = (MemHeader *)(address + *(int *)(address + -4) + -8);
    firstAddress->magicNumber = 0xbade;
    firstAddress->memStatus = '\0';
    firstAddress->memType = '\0';
    firstAddress->memSize = iVar1 * 4;
    if ((MemHeader *)(&firstAddress->magicNumber + iVar1 * 2) !=
        (MemHeader *)newMemTracker.lastMemoryAddress)
    {
      MEMORY_MergeAddresses(firstAddress, (MemHeader *)(&firstAddress->magicNumber + iVar1 * 2));
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
  newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed - *(int *)(address + -4);
  secondAddress = (MemHeader *)((int)&firstAddress->magicNumber + *(int *)(address + -4));
  secondAddress_00 = newMemTracker.rootNode;
  if (secondAddress != (MemHeader *)newMemTracker.lastMemoryAddress)
  {
    MEMORY_MergeAddresses(firstAddress, secondAddress);
    secondAddress_00 = newMemTracker.rootNode;
  }
  do
  {
    secondAddress = secondAddress_00;
    if (secondAddress == (MemHeader *)newMemTracker.lastMemoryAddress)
    {
      return;
    }
    secondAddress_00 = (MemHeader *)((int)&secondAddress->magicNumber + secondAddress->memSize);
  } while (secondAddress_00 != firstAddress);
  MEMORY_MergeAddresses(secondAddress, secondAddress_00);
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
  bool bVar1;
  MemHeader *pMVar2;

  do
  {
    bVar1 = false;
    pMVar2 = newMemTracker.rootNode;
    while (pMVar2 != (MemHeader *)newMemTracker.lastMemoryAddress)
    {
      if ((pMVar2->memStatus == '\x01') && (pMVar2->memType == memType))
      {
        bVar1 = true;
        MEMPACK_Free((char *)(pMVar2 + 1));
        break;
      }
      pMVar2 = (MemHeader *)((int)&pMVar2->magicNumber + pMVar2->memSize);
    }
    if (!bVar1)
    {
      return;
    }
  } while (true);
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

ulong MEMPACK_ReportFreeMemory(void)

{
  return newMemTracker.totalMemory - newMemTracker.currentMemoryUsed;
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
  MemHeader *pMVar1;

  pMVar1 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress)
  {
    do
    {
      pMVar1 = (MemHeader *)((int)&pMVar1->magicNumber + pMVar1->memSize);
    } while (pMVar1 != (MemHeader *)newMemTracker.lastMemoryAddress);
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
  MemHeader *pMVar2;
  uint uVar3;

  pMVar2 = newMemTracker.rootNode;
  if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress)
  {
    do
    {
      pMVar2 = (MemHeader *)((int)&pMVar2->magicNumber + pMVar2->memSize);
    } while (pMVar2 != (MemHeader *)newMemTracker.lastMemoryAddress);
  }
  uVar3 = 0;
  do
  {
    bVar1 = true;
    pMVar2 = newMemTracker.rootNode;
    if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress)
    {
      do
      {
        if (((pMVar2->memStatus != '\0') && ((uint)pMVar2->memType == uVar3)) && (bVar1))
        {
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
  if ((address != (char *)0xfafbfcfd) && (address != (char *)0x0))
  {
    return (uint)(address[-6] == '\x01');
  }
  return 0;
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

char *MEMPACK_GarbageCollectMalloc(ulong *allocSize, uchar memType, ulong *freeSize)

{
  MemHeader *pMVar1;
  uint allocSize_00;

  allocSize_00 = *allocSize + 0xb & 0xfffffffc;
  *allocSize = allocSize_00;
  pMVar1 = MEMPACK_GetSmallestBlockTopBottom(allocSize_00);
  if (pMVar1 == (MemHeader *)0x0)
  {
    STREAM_DumpNonResidentObjects();
    pMVar1 = MEMPACK_GetSmallestBlockTopBottom(*allocSize);
    if (pMVar1 == (MemHeader *)0x0)
    {
      MEMPACK_ReportMemory();
      DEBUG_FatalError(s_Trying_to_fit_memory_size__d_Typ_800cec2c);
    }
  }
  if (pMVar1->memSize - *allocSize < 8)
  {
    *allocSize = pMVar1->memSize;
  }
  if (*allocSize == pMVar1->memSize)
  {
    pMVar1->magicNumber = 0xbade;
    pMVar1->memStatus = '\x01';
    pMVar1->memType = memType;
    pMVar1->memSize = *allocSize;
    newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed + *allocSize;
    *freeSize = 0;
  }
  else
  {
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

void MEMPACK_GarbageSplitMemoryNow(ulong allocSize, MemHeader *bestAddress, long memType, ulong freeSize)

{
  undefined2 *puVar1;

  puVar1 = (undefined2 *)((int)&bestAddress->magicNumber + allocSize);
  if (freeSize != 0)
  {
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

void MEMPACK_GarbageCollectFree(MemHeader *memAddress)

{
  MemHeader *secondAddress;
  MemHeader *secondAddress_00;

  memAddress->memStatus = '\0';
  memAddress->memType = '\0';
  newMemTracker.currentMemoryUsed = newMemTracker.currentMemoryUsed - memAddress->memSize;
  secondAddress = (MemHeader *)((int)&memAddress->magicNumber + memAddress->memSize);
  secondAddress_00 = newMemTracker.rootNode;
  if (secondAddress != (MemHeader *)newMemTracker.lastMemoryAddress)
  {
    MEMORY_MergeAddresses(memAddress, secondAddress);
    secondAddress_00 = newMemTracker.rootNode;
  }
  do
  {
    secondAddress = secondAddress_00;
    if (secondAddress == (MemHeader *)newMemTracker.lastMemoryAddress)
    {
      return;
    }
    secondAddress_00 = (MemHeader *)((int)&secondAddress->magicNumber + secondAddress->memSize);
  } while (secondAddress_00 != memAddress);
  MEMORY_MergeAddresses(secondAddress, secondAddress_00);
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
  MemHeader *memAddress;
  Level *level;
  int iVar3;
  size_t __n;
  size_t local_28;
  ulong local_24;

  bVar1 = false;
  local_24 = 0;
  newMemTracker.doingGarbageCollection = 1;
  do
  {
    iVar3 = 0;
    memAddress = newMemTracker.rootNode;
    if (newMemTracker.rootNode != (MemHeader *)newMemTracker.lastMemoryAddress)
    {
      do
      {
        if (memAddress->memStatus == '\0')
        {
          iVar3 = 1;
        }
        else
        {
          lVar2 = MEMPACK_RelocatableType((uint)memAddress->memType);
          if (((lVar2 != 0) && (iVar3 == 1)) && (memAddress->memStatus != '\x02'))
          {
            iVar3 = 2;
            break;
          }
        }
        memAddress = (MemHeader *)((int)&memAddress->magicNumber + memAddress->memSize);
      } while (memAddress != (MemHeader *)newMemTracker.lastMemoryAddress);
    }
    if (iVar3 == 2)
    {
      memType = memAddress->memType;
      __n = memAddress->memSize - 8;
      MEMPACK_GarbageCollectFree(memAddress);
      local_28 = __n;
      newHModel = (_HModel *)MEMPACK_GarbageCollectMalloc(&local_28, memType, &local_24);
      level = (Level *)(memAddress + 1);
      if (newHModel != (_HModel *)0x0)
      {
        if (memType == 2)
        {
          RemoveIntroducedLights(level);
        }
        else
        {
          if (memType == 4)
          {
            aadRelocateMusicMemoryBegin();
          }
        }
        memcpy(newHModel, level, __n);
        if (memType == 2)
        {
          MEMPACK_RelocateAreaType((MemHeader *)(newHModel + -1), (long)((int)newHModel - (int)level), level);
        }
        else
        {
          if (memType == 1)
          {
            MEMPACK_RelocateObjectType((MemHeader *)(newHModel + -1), (long)((int)newHModel - (int)level),
                                       (Object *)level);
          }
          else
          {
            if (memType == 0xe)
            {
              STREAM_UpdateInstanceCollisionInfo((_HModel *)level, newHModel);
            }
            else
            {
              if (memType == 0x2c)
              {
                MEMPACK_RelocateCDMemory((MemHeader *)(newHModel + -1), (long)((int)newHModel - (int)level),
                                         (_BigFileDir *)level);
              }
              else
              {
                if (memType == 4)
                {
                  aadRelocateMusicMemoryEnd((MemHeader *)(newHModel + -1), (long)((int)newHModel - (int)level), level);
                }
                else
                {
                  if (memType == 0x2f)
                  {
                    aadRelocateSfxMemory(level, (int)((int)newHModel - (int)level));
                  }
                }
              }
            }
          }
        }
        MEMPACK_GarbageSplitMemoryNow(local_28, (MemHeader *)(newHModel + -1), (uint)memType, local_24);
      }
    }
    else
    {
      bVar1 = true;
    }
    if (bVar1)
    {
      newMemTracker.doingGarbageCollection = 0;
      return;
    }
  } while (true);
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

void MEMPACK_RelocateAreaType(MemHeader *newAddress, long offset, Level *oldLevel)

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
  if (*(int *)(newAddress + 1) != 0)
  {
    iVar28 = *(int *)(newAddress + 1) + offset;
  }
  *(int *)(newAddress + 1) = iVar28;
  uVar6 = 0;
  if (newAddress[1].memSize != 0)
  {
    uVar6 = newAddress[1].memSize + offset;
  }
  iVar28 = *(int *)(newAddress + 0x31);
  iVar17 = 0;
  newAddress[1].memSize = uVar6;
  if (iVar28 != 0)
  {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x31].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x31) = iVar17;
  if (uVar6 != 0)
  {
    uVar7 = uVar6 + offset;
  }
  uVar6 = 0;
  newAddress[0x31].memSize = uVar7;
  if (newAddress[2].memSize != 0)
  {
    uVar6 = newAddress[2].memSize + offset;
  }
  uVar7 = 0;
  newAddress[2].memSize = uVar6;
  if (newAddress[3].memSize != 0)
  {
    uVar7 = newAddress[3].memSize + offset;
  }
  uVar6 = 0;
  newAddress[3].memSize = uVar7;
  if (newAddress[4].memSize != 0)
  {
    uVar6 = newAddress[4].memSize + offset;
  }
  uVar7 = 0;
  newAddress[4].memSize = uVar6;
  if (newAddress[5].memSize != 0)
  {
    uVar7 = newAddress[5].memSize + offset;
  }
  uVar6 = 0;
  newAddress[5].memSize = uVar7;
  if (newAddress[6].memSize != 0)
  {
    uVar6 = newAddress[6].memSize + offset;
  }
  uVar7 = 0;
  newAddress[6].memSize = uVar6;
  if (newAddress[7].memSize != 0)
  {
    uVar7 = newAddress[7].memSize + offset;
  }
  uVar6 = 0;
  newAddress[7].memSize = uVar7;
  if (newAddress[0xc].memSize != 0)
  {
    uVar6 = newAddress[0xc].memSize + offset;
  }
  iVar28 = *(int *)(newAddress + 0xe);
  iVar17 = 0;
  newAddress[0xc].memSize = uVar6;
  if (iVar28 != 0)
  {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0xf].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0xe) = iVar17;
  if (uVar6 != 0)
  {
    uVar7 = uVar6 + offset;
  }
  uVar6 = 0;
  newAddress[0xf].memSize = uVar7;
  if (newAddress[0x10].memSize != 0)
  {
    uVar6 = newAddress[0x10].memSize + offset;
  }
  iVar28 = *(int *)(newAddress + 0x11);
  iVar17 = 0;
  newAddress[0x10].memSize = uVar6;
  if (iVar28 != 0)
  {
    iVar17 = iVar28 + offset;
  }
  iVar28 = 0;
  *(int *)(newAddress + 0x11) = iVar17;
  if (*(int *)(newAddress + 0x12) != 0)
  {
    iVar28 = *(int *)(newAddress + 0x12) + offset;
  }
  uVar6 = newAddress[0x12].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x12) = iVar28;
  if (uVar6 != 0)
  {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x14);
  iVar17 = 0;
  newAddress[0x12].memSize = uVar7;
  if (iVar28 != 0)
  {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x16].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x14) = iVar17;
  if (uVar6 != 0)
  {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x17);
  iVar17 = 0;
  newAddress[0x16].memSize = uVar7;
  if (iVar28 != 0)
  {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x17].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x17) = iVar17;
  if (uVar6 != 0)
  {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x18);
  iVar17 = 0;
  newAddress[0x17].memSize = uVar7;
  if (iVar28 != 0)
  {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x18].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x18) = iVar17;
  if (uVar6 != 0)
  {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x19);
  iVar17 = 0;
  newAddress[0x18].memSize = uVar7;
  if (iVar28 != 0)
  {
    iVar17 = iVar28 + offset;
  }
  uVar6 = newAddress[0x19].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x19) = iVar17;
  if (uVar6 != 0)
  {
    uVar7 = uVar6 + offset;
  }
  iVar28 = *(int *)(newAddress + 0x1a);
  iVar17 = 0;
  newAddress[0x19].memSize = uVar7;
  if (iVar28 != 0)
  {
    iVar17 = iVar28 + offset;
  }
  iVar28 = 0;
  *(int *)(newAddress + 0x1a) = iVar17;
  if (*(int *)(newAddress + 0x1b) != 0)
  {
    iVar28 = *(int *)(newAddress + 0x1b) + offset;
  }
  uVar6 = newAddress[0x1b].memSize;
  uVar7 = 0;
  *(int *)(newAddress + 0x1b) = iVar28;
  if (uVar6 != 0)
  {
    uVar7 = uVar6 + offset;
  }
  uVar6 = 0;
  newAddress[0x1b].memSize = uVar7;
  if (newAddress[0x1c].memSize != 0)
  {
    uVar6 = newAddress[0x1c].memSize + offset;
  }
  uVar7 = 0;
  newAddress[0x1c].memSize = uVar6;
  if (newAddress[0x1d].memSize != 0)
  {
    uVar7 = newAddress[0x1d].memSize + offset;
  }
  uVar6 = 0;
  newAddress[0x1d].memSize = uVar7;
  if (newAddress[0x1e].memSize != 0)
  {
    uVar6 = newAddress[0x1e].memSize + offset;
  }
  iVar28 = *(int *)(newAddress + 0x1e);
  iVar17 = 0;
  newAddress[0x1e].memSize = uVar6;
  if (0 < iVar28)
  {
    iVar28 = 0;
    do
    {
      piVar24 = (int *)(iVar28 + newAddress[0x1e].memSize);
      iVar1 = *piVar24;
      iVar8 = 0;
      if (iVar1 != 0)
      {
        iVar8 = iVar1 + offset;
      }
      *piVar24 = iVar8;
      iVar17 = iVar17 + 1;
      iVar28 = iVar28 + 0x24;
    } while (iVar17 < *(int *)(newAddress + 0x1e));
  }
  uVar6 = 0;
  if (newAddress[0x1f].memSize != 0)
  {
    uVar6 = newAddress[0x1f].memSize + offset;
  }
  uVar7 = 0;
  newAddress[0x1f].memSize = uVar6;
  if (newAddress[0xb].memSize != 0)
  {
    uVar7 = newAddress[0xb].memSize + offset;
  }
  p_Var2 = newLevel->terrain;
  newAddress[0xb].memSize = uVar7;
  if (p_Var2 != (_Terrain *)0x0)
  {
    pIVar9 = (Intro *)0x0;
    if (p_Var2->introList != (Intro *)0x0)
    {
      pIVar9 = (Intro *)(p_Var2->introList->name + offset);
    }
    p_Var18 = (_TVertex *)0x0;
    p_Var2->introList = pIVar9;
    if (p_Var2->vertexList != (_TVertex *)0x0)
    {
      p_Var18 = (_TVertex *)((int)&(p_Var2->vertexList->vertex).x + offset);
    }
    p_Var10 = (_TFace *)0x0;
    p_Var2->vertexList = p_Var18;
    if (p_Var2->faceList != (_TFace *)0x0)
    {
      p_Var10 = (_TFace *)((int)&(p_Var2->faceList->face).v0 + offset);
    }
    p_Var19 = (_Normal *)0x0;
    p_Var2->faceList = p_Var10;
    if (p_Var2->normalList != (_Normal *)0x0)
    {
      p_Var19 = (_Normal *)((int)&p_Var2->normalList->x + offset);
    }
    pDVar11 = (DrMoveAniTex *)0x0;
    p_Var2->normalList = p_Var19;
    if (p_Var2->aniList != (DrMoveAniTex *)0x0)
    {
      pDVar11 = (DrMoveAniTex *)((int)&p_Var2->aniList->numAniTextues + offset);
    }
    pvVar20 = (void *)0x0;
    p_Var2->aniList = pDVar11;
    if (p_Var2->StreamUnits != (void *)0x0)
    {
      pvVar20 = (void *)((int)p_Var2->StreamUnits + offset);
    }
    pTVar12 = (TextureFT3 *)0x0;
    p_Var2->StreamUnits = pvVar20;
    if (p_Var2->StartTextureList != (TextureFT3 *)0x0)
    {
      pTVar12 = (TextureFT3 *)(&p_Var2->StartTextureList->u0 + offset);
    }
    pTVar21 = (TextureFT3 *)0x0;
    p_Var2->StartTextureList = pTVar12;
    if (p_Var2->EndTextureList != (TextureFT3 *)0x0)
    {
      pTVar21 = (TextureFT3 *)(&p_Var2->EndTextureList->u0 + offset);
    }
    p_Var13 = (_MorphVertex *)0x0;
    p_Var2->EndTextureList = pTVar21;
    if (p_Var2->MorphDiffList != (_MorphVertex *)0x0)
    {
      p_Var13 = (_MorphVertex *)((int)&p_Var2->MorphDiffList->x + offset);
    }
    p_Var22 = (_MorphColor *)0x0;
    p_Var2->MorphDiffList = p_Var13;
    if (p_Var2->MorphColorList != (_MorphColor *)0x0)
    {
      p_Var22 = (_MorphColor *)((int)&p_Var2->MorphColorList->morphColor15 + offset);
    }
    pBVar14 = (BSPTree *)0x0;
    p_Var2->MorphColorList = p_Var22;
    if (p_Var2->BSPTreeArray != (BSPTree *)0x0)
    {
      pBVar14 = (BSPTree *)((int)&p_Var2->BSPTreeArray->bspRoot + offset);
    }
    psVar23 = (short *)0x0;
    p_Var2->BSPTreeArray = pBVar14;
    if (p_Var2->morphNormalIdx != (short *)0x0)
    {
      psVar23 = (short *)((int)p_Var2->morphNormalIdx + offset);
    }
    multiSignal = (_MultiSignal *)0x0;
    p_Var2->morphNormalIdx = psVar23;
    if (p_Var2->signals != (_MultiSignal *)0x0)
    {
      multiSignal = (_MultiSignal *)((int)&p_Var2->signals->numSignals + offset);
    }
    iVar28 = 0;
    p_Var2->signals = multiSignal;
    if (0 < p_Var2->numIntros)
    {
      iVar17 = 0;
      do
      {
        pcVar3 = p_Var2->introList->name + iVar17;
        iVar1 = 0;
        if (*(int *)(pcVar3 + 0x30) != 0)
        {
          iVar1 = *(int *)(pcVar3 + 0x30) + offset;
        }
        ppiVar15 = (int **)0x0;
        *(int *)(pcVar3 + 0x30) = iVar1;
        if (*(int *)(pcVar3 + 0x38) != 0)
        {
          ppiVar15 = (int **)(*(int *)(pcVar3 + 0x38) + offset);
        }
        *(int ***)(pcVar3 + 0x38) = ppiVar15;
        if (ppiVar15 != (int **)0x0)
        {
          piVar24 = (int *)0x0;
          if (*ppiVar15 != (int *)0x0)
          {
            piVar24 = (int *)((int)*ppiVar15 + offset);
          }
          piVar29 = (int *)0x0;
          *ppiVar15 = piVar24;
          if (ppiVar15[1] != (int *)0x0)
          {
            piVar29 = (int *)((int)ppiVar15[1] + offset);
          }
          piVar24 = (int *)0x0;
          ppiVar15[1] = piVar29;
          if (ppiVar15[2] != (int *)0x0)
          {
            piVar24 = (int *)((int)ppiVar15[2] + offset);
          }
          piVar29 = (int *)0x0;
          ppiVar15[2] = piVar24;
          if (ppiVar15[3] != (int *)0x0)
          {
            piVar29 = (int *)((int)ppiVar15[3] + offset);
          }
          piVar24 = *ppiVar15;
          ppiVar15[3] = piVar29;
          if (piVar24 != (int *)0x0)
          {
            iVar1 = 0;
            if (*piVar24 != 0)
            {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
          }
          piVar24 = ppiVar15[1];
          if (piVar24 != (int *)0x0)
          {
            iVar1 = 0;
            if (*piVar24 != 0)
            {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
          }
          piVar24 = ppiVar15[2];
          if (piVar24 != (int *)0x0)
          {
            iVar1 = 0;
            if (*piVar24 != 0)
            {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
          }
          piVar24 = ppiVar15[3];
          if (piVar24 != (int *)0x0)
          {
            iVar1 = 0;
            if (*piVar24 != 0)
            {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
          }
        }
        iVar1 = 0;
        if (*(int *)(pcVar3 + 0x3c) != 0)
        {
          iVar1 = *(int *)(pcVar3 + 0x3c) + offset;
        }
        *(int *)(pcVar3 + 0x3c) = iVar1;
        iVar28 = iVar28 + 1;
        iVar17 = iVar17 + 0x4c;
      } while (iVar28 < p_Var2->numIntros);
    }
    pDVar11 = p_Var2->aniList;
    if (((pDVar11 != (DrMoveAniTex *)0x0) && (0 < pDVar11->numAniTextues)) &&
        (iVar28 = 0, 0 < pDVar11->numAniTextues))
    {
      do
      {
        pDVar11 = (DrMoveAniTex *)&pDVar11->aniTexInfo;
        iVar17 = 0;
        if (pDVar11->numAniTextues != 0)
        {
          iVar17 = pDVar11->numAniTextues + offset;
        }
        pDVar11->numAniTextues = iVar17;
        iVar28 = iVar28 + 1;
      } while (iVar28 < p_Var2->aniList->numAniTextues);
    }
    uVar6 = newAddress[1].memSize;
    if (uVar6 != 0)
    {
      iVar28 = 0;
      if (*(int *)(uVar6 + 8) != 0)
      {
        iVar28 = *(int *)(uVar6 + 8) + offset;
      }
      *(int *)(uVar6 + 8) = iVar28;
    }
    uVar6 = newAddress[0xb].memSize;
    if (uVar6 != 0)
    {
      iVar28 = 0;
      if (*(int *)(uVar6 + 8) != 0)
      {
        iVar28 = *(int *)(uVar6 + 8) + offset;
      }
      *(int *)(uVar6 + 8) = iVar28;
    }
    iVar28 = 0;
    if (0 < *(int *)(newAddress + 2))
    {
      iVar17 = 0;
      do
      {
        iVar8 = newAddress[2].memSize + iVar17;
        iVar1 = 0;
        if (*(int *)(iVar8 + 0x20) != 0)
        {
          iVar1 = *(int *)(iVar8 + 0x20) + offset;
        }
        *(int *)(iVar8 + 0x20) = iVar1;
        iVar16 = *(int *)(iVar8 + 0x24);
        if (iVar16 == *(int *)((int)*(short *)(iVar8 + 8) * 4 + iVar1))
        {
          iVar1 = 0;
          if (iVar16 != 0)
          {
            iVar1 = iVar16 + offset;
          }
          *(int *)(iVar8 + 0x24) = iVar1;
        }
        iVar1 = 0;
        if (0 < *(int *)(iVar8 + 0x1c))
        {
          do
          {
            piVar24 = (int *)(iVar1 * 4 + *(int *)(iVar8 + 0x20));
            iVar25 = *piVar24;
            iVar16 = 0;
            if (iVar25 != 0)
            {
              iVar16 = iVar25 + offset;
            }
            *piVar24 = iVar16;
            iVar1 = iVar1 + 1;
          } while (iVar1 < *(int *)(iVar8 + 0x1c));
        }
        iVar1 = 0;
        if (*(int *)(iVar8 + 0x2c) != 0)
        {
          iVar1 = *(int *)(iVar8 + 0x2c) + offset;
        }
        iVar16 = 0;
        *(int *)(iVar8 + 0x2c) = iVar1;
        if (*(int *)(iVar8 + 0x34) != 0)
        {
          iVar16 = *(int *)(iVar8 + 0x34) + offset;
        }
        iVar1 = 0;
        *(int *)(iVar8 + 0x34) = iVar16;
        if (*(int *)(iVar8 + 0x38) != 0)
        {
          iVar1 = *(int *)(iVar8 + 0x38) + offset;
        }
        *(int *)(iVar8 + 0x38) = iVar1;
        iVar28 = iVar28 + 1;
        iVar17 = iVar17 + 0x3c;
      } while (iVar28 < *(int *)(newAddress + 2));
    }
    pBVar14 = p_Var2->BSPTreeArray;
    iVar28 = 0;
    if (0 < p_Var2->numBSPTrees)
    {
      pp_Var30 = &pBVar14->endLeaves;
      do
      {
        p_Var4 = (_BSPNode *)0x0;
        if (pBVar14->bspRoot != (_BSPNode *)0x0)
        {
          p_Var4 = (_BSPNode *)((int)&(pBVar14->bspRoot->sphere).position.x + offset);
        }
        pBVar14->bspRoot = p_Var4;
        p_Var26 = (_BSPLeaf *)0x0;
        if (pp_Var30[-1] != (_BSPLeaf *)0x0)
        {
          p_Var26 = (_BSPLeaf *)((int)&(pp_Var30[-1]->sphere).position.x + offset);
        }
        p_Var5 = (_BSPLeaf *)0x0;
        pp_Var30[-1] = p_Var26;
        if (*pp_Var30 != (_BSPLeaf *)0x0)
        {
          p_Var5 = (_BSPLeaf *)((int)&((*pp_Var30)->sphere).position.x + offset);
        }
        *pp_Var30 = p_Var5;
        p_Var26 = (_BSPLeaf *)pBVar14->bspRoot;
        if (p_Var26 < pp_Var30[-1])
        {
          piVar24 = (int *)&(p_Var26->box).maxY;
          do
          {
            iVar17 = 0;
            if (piVar24[-1] != 0)
            {
              iVar17 = piVar24[-1] + offset;
            }
            iVar1 = 0;
            piVar24[-1] = iVar17;
            if (*piVar24 != 0)
            {
              iVar1 = *piVar24 + offset;
            }
            *piVar24 = iVar1;
            p_Var26 = (_BSPLeaf *)&(p_Var26->spectralSphere).position.z;
            piVar24 = piVar24 + 0xb;
          } while (p_Var26 < pp_Var30[-1]);
        }
        p_Var26 = pp_Var30[-1];
        if (p_Var26 < *pp_Var30)
        {
          pp_Var27 = &p_Var26->faceList;
          do
          {
            p_Var10 = (_TFace *)0x0;
            if (*pp_Var27 != (_TFace *)0x0)
            {
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
  if (multiSignal < (_MultiSignal *)newAddress[0x1b].memSize)
  {
    do
    {
      multiSignal = SIGNAL_RelocateSignal(multiSignal, offset);
    } while (multiSignal < (_MultiSignal *)newAddress[0x1b].memSize);
  }
  EVENT_UpdatePuzzlePointers((EventPointers *)newAddress[0x1c].memSize, offset);
  STREAM_UpdateLevelPointer(oldLevel, newLevel, sizeOfLevel);
  EVENT_RelocateInstanceList(oldLevel, newLevel, sizeOfLevel);
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

void MEMPACK_RelocateG2AnimKeylistType(_G2AnimKeylist_Type **pKeylist, int offset, char *start, char *end)

{
  _G2AnimKeylist_Type *p_Var1;
  _func_7 **pp_Var2;
  _G2AnimKeylist_Type *p_Var3;
  _G2AnimFxHeader_Type *p_Var4;
  int iVar5;

  p_Var3 = *pKeylist;
  if ((start <= p_Var3) && (p_Var3 < end))
  {
    p_Var1 = (_G2AnimKeylist_Type *)0x0;
    if (p_Var3 != (_G2AnimKeylist_Type *)0x0)
    {
      p_Var1 = (_G2AnimKeylist_Type *)(&p_Var3->sectionCount + offset);
    }
    *pKeylist = p_Var1;
    if (*(int *)p_Var1 != 0xface0ff)
    {
      p_Var4 = (_G2AnimFxHeader_Type *)0x0;
      if (p_Var1->fxList != (_G2AnimFxHeader_Type *)0x0)
      {
        p_Var4 = (_G2AnimFxHeader_Type *)(&p_Var1->fxList->sizeAndSection + offset);
      }
      iVar5 = 0;
      p_Var1->fxList = p_Var4;
      p_Var3 = p_Var1;
      if (p_Var1->sectionCount != '\0')
      {
        do
        {
          pp_Var2 = (_func_7 **)0x0;
          if (p_Var3->sectionData != (_func_7 **)0x0)
          {
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

void MEMPACK_RelocateObjectType(MemHeader *newAddress, long offset, Object *oldObject)

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
  if (newAddress[2].memSize != 0)
  {
    uVar17 = newAddress[2].memSize + offset;
  }
  iVar2 = *(int *)(newAddress + 3);
  iVar9 = 0;
  newAddress[2].memSize = uVar17;
  if (iVar2 != 0)
  {
    iVar9 = iVar2 + offset;
  }
  iVar2 = 0;
  *(int *)(newAddress + 3) = iVar9;
  if (*(int *)(newAddress + 6) != 0)
  {
    iVar2 = *(int *)(newAddress + 6) + offset;
  }
  uVar17 = newAddress[4].memSize;
  uVar10 = 0;
  *(int *)(newAddress + 6) = iVar2;
  if (uVar17 != 0)
  {
    uVar10 = uVar17 + offset;
  }
  iVar2 = *(int *)(newAddress + 5);
  iVar9 = 0;
  newAddress[4].memSize = uVar10;
  if (iVar2 != 0)
  {
    iVar9 = iVar2 + offset;
  }
  uVar17 = newAddress[5].memSize;
  uVar10 = 0;
  *(int *)(newAddress + 5) = iVar9;
  if (uVar17 != 0)
  {
    uVar10 = uVar17 + offset;
  }
  iVar9 = *(int *)(newAddress + 8);
  iVar2 = 0;
  newAddress[5].memSize = uVar10;
  if (iVar9 != 0)
  {
    iVar2 = iVar9 + offset;
  }
  *(int *)(newAddress + 8) = iVar2;
  if ((*(uint *)(newAddress + 1) & 0x8000000) != 0)
  {
    uVar17 = 0;
    if (newAddress[8].memSize != 0)
    {
      uVar17 = newAddress[8].memSize + offset;
    }
    iVar9 = *(int *)(newAddress + 9);
    iVar2 = 0;
    newAddress[8].memSize = uVar17;
    if (iVar9 != 0)
    {
      iVar2 = iVar9 + offset;
    }
    *(int *)(newAddress + 9) = iVar2;
  }
  iVar2 = 0;
  if (0 < (short)newAddress[2].magicNumber)
  {
    iVar9 = 0;
    do
    {
      piVar5 = (int *)(iVar9 + newAddress[2].memSize);
      iVar11 = *piVar5;
      iVar3 = 0;
      if (iVar11 != 0)
      {
        iVar3 = iVar11 + offset;
      }
      *piVar5 = iVar3;
      iVar11 = *(int *)(iVar9 + newAddress[2].memSize);
      iVar3 = 0;
      if (*(int *)(iVar11 + 4) != 0)
      {
        iVar3 = *(int *)(iVar11 + 4) + offset;
      }
      iVar14 = 0;
      *(int *)(iVar11 + 4) = iVar3;
      if (*(int *)(iVar11 + 0xc) != 0)
      {
        iVar14 = *(int *)(iVar11 + 0xc) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar11 + 0xc) = iVar14;
      if (*(int *)(iVar11 + 0x14) != 0)
      {
        iVar3 = *(int *)(iVar11 + 0x14) + offset;
      }
      iVar14 = 0;
      *(int *)(iVar11 + 0x14) = iVar3;
      if (*(int *)(iVar11 + 0x1c) != 0)
      {
        iVar14 = *(int *)(iVar11 + 0x1c) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar11 + 0x1c) = iVar14;
      if (*(int *)(iVar11 + 0x20) != 0)
      {
        iVar3 = *(int *)(iVar11 + 0x20) + offset;
      }
      iVar14 = 0;
      *(int *)(iVar11 + 0x20) = iVar3;
      if (*(int *)(iVar11 + 0x2c) != 0)
      {
        iVar14 = *(int *)(iVar11 + 0x2c) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar11 + 0x2c) = iVar14;
      if (*(int *)(iVar11 + 0x30) != 0)
      {
        iVar3 = *(int *)(iVar11 + 0x30) + offset;
      }
      iVar14 = 0;
      *(int *)(iVar11 + 0x30) = iVar3;
      if (*(int *)(iVar11 + 0x34) != 0)
      {
        iVar14 = *(int *)(iVar11 + 0x34) + offset;
      }
      iVar3 = 0;
      *(int *)(iVar11 + 0x34) = iVar14;
      if (0 < *(int *)(iVar11 + 0x10))
      {
        iVar14 = 0;
        do
        {
          iVar15 = *(int *)(iVar11 + 0x14) + iVar14;
          if ((*(byte *)(iVar15 + 7) & 2) != 0)
          {
            iVar4 = 0;
            if (*(int *)(iVar15 + 8) != 0)
            {
              iVar4 = *(int *)(iVar15 + 8) + offset;
            }
            *(int *)(iVar15 + 8) = iVar4;
          }
          iVar3 = iVar3 + 1;
          iVar14 = iVar14 + 0xc;
        } while (iVar3 < *(int *)(iVar11 + 0x10));
      }
      iVar3 = 0;
      if (0 < *(int *)(iVar11 + 0x18))
      {
        iVar14 = 0;
        do
        {
          iVar15 = *(int *)(iVar11 + 0x1c) + iVar14;
          iVar4 = *(int *)(iVar15 + 0x14);
          iVar20 = 0;
          if (iVar4 != 0)
          {
            iVar20 = iVar4 + offset;
          }
          *(int *)(iVar15 + 0x14) = iVar20;
          if (iVar20 != 0)
          {
            iVar15 = 0;
            if (*(int *)(iVar20 + 4) != 0)
            {
              iVar15 = *(int *)(iVar20 + 4) + offset;
            }
            iVar4 = 0;
            *(int *)(iVar20 + 4) = iVar15;
            if (*(int *)(iVar20 + 0xc) != 0)
            {
              iVar4 = *(int *)(iVar20 + 0xc) + offset;
            }
            iVar15 = 0;
            *(int *)(iVar20 + 0xc) = iVar4;
            if (*(int *)(iVar20 + 0x14) != 0)
            {
              iVar15 = *(int *)(iVar20 + 0x14) + offset;
            }
            *(int *)(iVar20 + 0x14) = iVar15;
          }
          iVar3 = iVar3 + 1;
          iVar14 = iVar14 + 0x18;
        } while (iVar3 < *(int *)(iVar11 + 0x18));
      }
      piVar5 = *(int **)(iVar11 + 0x20);
      if (piVar5 != (int *)0x0)
      {
        piVar18 = piVar5 + 1;
        iVar3 = 0;
        if (0 < *piVar5)
        {
          do
          {
            iVar14 = 0;
            if (*piVar18 != 0)
            {
              iVar14 = *piVar18 + offset;
            }
            *piVar18 = iVar14;
            iVar3 = iVar3 + 1;
            piVar18 = piVar18 + 3;
          } while (iVar3 < **(int **)(iVar11 + 0x20));
        }
      }
      ppiVar6 = *(int ***)(iVar11 + 0x2c);
      if (ppiVar6 != (int **)0x0)
      {
        piVar5 = (int *)0x0;
        if (*ppiVar6 != (int *)0x0)
        {
          piVar5 = (int *)((int)*ppiVar6 + offset);
        }
        piVar18 = (int *)0x0;
        *ppiVar6 = piVar5;
        if (ppiVar6[1] != (int *)0x0)
        {
          piVar18 = (int *)((int)ppiVar6[1] + offset);
        }
        piVar5 = (int *)0x0;
        ppiVar6[1] = piVar18;
        if (ppiVar6[2] != (int *)0x0)
        {
          piVar5 = (int *)((int)ppiVar6[2] + offset);
        }
        piVar18 = (int *)0x0;
        ppiVar6[2] = piVar5;
        if (ppiVar6[3] != (int *)0x0)
        {
          piVar18 = (int *)((int)ppiVar6[3] + offset);
        }
        piVar5 = *ppiVar6;
        ppiVar6[3] = piVar18;
        if (piVar5 != (int *)0x0)
        {
          iVar3 = 0;
          if (*piVar5 != 0)
          {
            iVar3 = *piVar5 + offset;
          }
          *piVar5 = iVar3;
        }
        piVar5 = ppiVar6[1];
        if (piVar5 != (int *)0x0)
        {
          iVar3 = 0;
          if (*piVar5 != 0)
          {
            iVar3 = *piVar5 + offset;
          }
          *piVar5 = iVar3;
        }
        piVar5 = ppiVar6[2];
        if (piVar5 != (int *)0x0)
        {
          iVar3 = 0;
          if (*piVar5 != 0)
          {
            iVar3 = *piVar5 + offset;
          }
          *piVar5 = iVar3;
        }
        piVar5 = ppiVar6[3];
        if (piVar5 != (int *)0x0)
        {
          iVar3 = 0;
          if (*piVar5 != 0)
          {
            iVar3 = *piVar5 + offset;
          }
          *piVar5 = iVar3;
        }
      }
      iVar2 = iVar2 + 1;
      iVar9 = iVar9 + 4;
    } while (iVar2 < (int)(short)newAddress[2].magicNumber);
  }
  iVar2 = 0;
  if (0 < *(short *)&newAddress[2].memStatus)
  {
    do
    {
      MEMPACK_RelocateG2AnimKeylistType((_G2AnimKeylist_Type **)(*(int *)(newAddress + 3) + iVar2 * 4), offset,
                                        (char *)oldObject, (char *)((int)&oldObject->name + uVar1));
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)*(short *)&newAddress[2].memStatus);
  }
  if (*(int *)(newAddress + 3) != 0)
  {
    p_Var19 = (gameTrackerX.instanceList)->first;
    while (p_Var19 != (_Instance *)0x0)
    {
      if (p_Var19->object == oldObject)
      {
        p_Var12 = (p_Var19->anim).modelData;
        p_Var7 = (_Model *)0x0;
        if (p_Var12 != (_Model *)0x0)
        {
          p_Var7 = (_Model *)((int)&p_Var12->numVertices + offset);
        }
        (p_Var19->anim).modelData = p_Var7;
      }
      iVar2 = 0;
      p_Var16 = p_Var19;
      if ((p_Var19->anim).sectionCount != '\0')
      {
        do
        {
          pOVar13 = (Object *)(p_Var16->anim).section[0].keylist;
          if ((oldObject <= pOVar13) && (pOVar13 <= (Object *)((int)&oldObject->name + uVar1)))
          {
            p_Var8 = (_G2AnimKeylist_Type *)0x0;
            if (pOVar13 != (Object *)0x0)
            {
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
  STREAM_UpdateObjectPointer(oldObject, (Object *)(newAddress + 1), uVar1 - 8);
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

void MEMPACK_RelocateCDMemory(MemHeader *newAddress, long offset, _BigFileDir *oldDir)

{
  LOAD_UpdateBigFilePointers(oldDir, (_BigFileDir *)(newAddress + 1));
  return;
}
