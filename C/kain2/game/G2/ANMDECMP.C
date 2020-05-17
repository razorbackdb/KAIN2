#include "THISDUST.H"
#include "ANMDECMP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_DecompressChannel_AdaptiveDelta(struct _G2AnimDecompressChannelInfo_Type *dcInfo /*$a0*/, struct _G2AnimChanStatus_Type *status /*$a1*/)
 // line 135, offset 0x80090234
	/* begin block 1 */
		// Start line: 136
		// Start offset: 0x80090234
		// Variables:
	// 		unsigned short *chanData; // $t7
	// 		int index; // $t2
	// 		int keyData; // $t5
	// 		unsigned short step; // $v1
	// 		unsigned short predictedDelta; // $a2
	// 		int targetKey; // $t6
	// 		int storedKey; // $t4
	// 		int keyCount; // $t8
	/* end block 1 */
	// End offset: 0x8009033C
	// End Line: 189

	/* begin block 2 */
		// Start line: 270
	/* end block 2 */
	// End Line: 271

void _G2Anim_DecompressChannel_AdaptiveDelta
               (_G2AnimDecompressChannelInfo_Type *dcInfo,_G2AnimChanStatus_Type *status)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort uVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  short sVar10;
  
  uVar9 = dcInfo->storedKey;
  sVar10 = status->keyData;
  sVar6 = status->index;
  iVar7 = (int)sVar6;
  puVar3 = dcInfo->chanData;
  uVar1 = dcInfo->keylist->keyCount;
  while ((int)uVar9 < dcInfo->targetKey) {
    uVar9 = uVar9 + 1;
    uVar5 = (int)(uint)(puVar3 + 2)[(int)uVar9 >> 2] >> ((uVar9 & 3) << 2);
    uVar2 = *(ushort *)(&_stepSizeTable + iVar7);
    iVar8 = iVar7 + (&_indexTable)[uVar5 & 0xf];
    iVar7 = iVar8;
    if (iVar8 < 0) {
      iVar7 = 0;
    }
    if (0x3f < iVar8) {
      iVar7 = 0x3f;
    }
    sVar6 = (short)iVar7;
    uVar4 = uVar2 >> 3;
    if ((uVar5 & 4) != 0) {
      uVar4 = uVar2 + uVar4;
    }
    if ((uVar5 & 2) != 0) {
      uVar4 = uVar4 + (uVar2 >> 1);
    }
    if ((uVar5 & 1) != 0) {
      uVar4 = uVar4 + (uVar2 >> 2) + (uVar2 & 1);
    }
    if ((uVar5 & 8) != 0) {
      uVar4 = -uVar4;
    }
    sVar10 = sVar10 + uVar4;
  }
  status->index = sVar6;
  status->keyData = sVar10;
  dcInfo->chanData = puVar3 + 2 + ((int)((uint)uVar1 + 3) >> 2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_DecompressChannel_Linear(struct _G2AnimDecompressChannelInfo_Type *dcInfo /*$a0*/, struct _G2AnimChanStatus_Type *status /*$a1*/)
 // line 198, offset 0x80090360
	/* begin block 1 */
		// Start line: 201
		// Start offset: 0x80090360
		// Variables:
	// 		unsigned short *chanData; // $a2
	// 		short rangeBase; // $t0
	// 		short rangeInfo; // $v0
	// 		int rangeLength; // $v1
	// 		int rangeOffset; // $a0
	// 		int targetKey; // $a3
	/* end block 1 */
	// End offset: 0x800903C8
	// End Line: 232

	/* begin block 2 */
		// Start line: 412
	/* end block 2 */
	// End Line: 413

	/* begin block 3 */
		// Start line: 414
	/* end block 3 */
	// End Line: 415

	/* begin block 4 */
		// Start line: 423
	/* end block 4 */
	// End Line: 424

void _G2Anim_DecompressChannel_Linear
               (_G2AnimDecompressChannelInfo_Type *dcInfo,_G2AnimChanStatus_Type *status)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  
  puVar4 = dcInfo->chanData;
  iVar5 = dcInfo->targetKey;
  dcInfo->chanData = puVar4 + ((uint)*puVar4 & 0xfff) + 1;
  uVar6 = (uint)puVar4[1];
  uVar1 = puVar4[2];
  while( true ) {
    iVar2 = (int)((int)(short)uVar1 & 0xf800U) >> 0xb;
    iVar3 = ((int)(short)uVar1 << 0x15) >> 0x15;
    if (iVar5 <= iVar2) break;
    uVar1 = puVar4[3];
    iVar5 = iVar5 - iVar2;
    uVar6 = uVar6 + iVar3;
    puVar4 = puVar4 + 1;
  }
  status->keyData = (short)uVar6 + (short)((iVar3 * iVar5) / iVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_InitializeChannel_AdaptiveDelta(struct _G2AnimDecompressChannelInfo_Type *dcInfo /*$a0*/, struct _G2AnimChanStatus_Type *status /*$a1*/)
 // line 271, offset 0x800903f4
	/* begin block 1 */
		// Start line: 274
		// Start offset: 0x800903F4
		// Variables:
	// 		unsigned short *chanData; // $v1
	// 		int keyCount; // $v0
	/* end block 1 */
	// End offset: 0x800903F4
	// End Line: 277

	/* begin block 2 */
		// Start line: 561
	/* end block 2 */
	// End Line: 562

	/* begin block 3 */
		// Start line: 563
	/* end block 3 */
	// End Line: 564

	/* begin block 4 */
		// Start line: 566
	/* end block 4 */
	// End Line: 567

	/* begin block 5 */
		// Start line: 567
	/* end block 5 */
	// End Line: 568

void _G2Anim_InitializeChannel_AdaptiveDelta
               (_G2AnimDecompressChannelInfo_Type *dcInfo,_G2AnimChanStatus_Type *status)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = dcInfo->chanData;
  uVar1 = dcInfo->keylist->keyCount;
  status->index = (ushort)*(byte *)puVar2;
  status->keyData = puVar2[1];
  dcInfo->chanData = puVar2 + ((int)((uint)uVar1 + 3) >> 2) + 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_InitializeChannel_Linear(struct _G2AnimDecompressChannelInfo_Type *dcInfo /*$a0*/, struct _G2AnimChanStatus_Type *status /*$a1*/)
 // line 289, offset 0x8009042c
	/* begin block 1 */
		// Start line: 292
		// Start offset: 0x8009042C
		// Variables:
	// 		unsigned short *chanData; // $v1
	// 		int chanLength; // $v0
	/* end block 1 */
	// End offset: 0x8009042C
	// End Line: 295

	/* begin block 2 */
		// Start line: 603
	/* end block 2 */
	// End Line: 604

	/* begin block 3 */
		// Start line: 605
	/* end block 3 */
	// End Line: 606

	/* begin block 4 */
		// Start line: 608
	/* end block 4 */
	// End Line: 609

void _G2Anim_InitializeChannel_Linear
               (_G2AnimDecompressChannelInfo_Type *dcInfo,_G2AnimChanStatus_Type *status)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = dcInfo->chanData;
  uVar1 = *puVar2;
  status->keyData = puVar2[1];
  dcInfo->chanData = puVar2 + ((uint)uVar1 & 0xfff) + 1;
  return;
}





