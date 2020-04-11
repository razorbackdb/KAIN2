
#include "ANIMG2.H"


// decompiled code
// original method signature: 
// enum _G2Bool_Enum /*$ra*/ G2Anim_Install()
 // line 260, offset 0x80092380
	/* begin block 1 */
		// Start line: 261
		// Start offset: 0x80092380
		// Variables:
	// 		struct _G2AnimController_Type *dummyController; // $a0
	/* end block 1 */
	// End offset: 0x80092380
	// End Line: 261

	/* begin block 2 */
		// Start line: 520
	/* end block 2 */
	// End Line: 521

/* File: C:\kain2\game\G2\ANIMG2.C */

_G2Bool_Enum G2Anim_Install(void)

{
  undefined2 *puVar1;
  
  G2PoolMem_InitPool(&_chanStatusBlockPool,0xb4,0x24);
  G2PoolMem_InitPool(&_interpStateBlockPool,0x60,0xa4);
  G2PoolMem_InitPool(&_controllerPool,0x7a,0x24);
  puVar1 = (undefined2 *)G2PoolMem_Allocate(&_controllerPool);
  *puVar1 = 0;
  *(undefined *)((int)puVar1 + 3) = 0xff;
  *(undefined *)(puVar1 + 1) = 0;
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_ResetInternalState()
 // line 309, offset 0x800923f8
	/* begin block 1 */
		// Start line: 310
		// Start offset: 0x800923F8
		// Variables:
	// 		struct _G2AnimController_Type *dummyController; // $v0
	/* end block 1 */
	// End offset: 0x800923F8
	// End Line: 310

	/* begin block 2 */
		// Start line: 627
	/* end block 2 */
	// End Line: 628

/* File: C:\kain2\game\G2\ANIMG2.C */

void G2Anim_ResetInternalState(void)

{
  undefined2 *puVar1;
  
  G2PoolMem_ResetPool(&_chanStatusBlockPool);
  G2PoolMem_ResetPool(&_interpStateBlockPool);
  G2PoolMem_ResetPool(&_controllerPool);
  puVar1 = (undefined2 *)G2PoolMem_Allocate(&_controllerPool);
  *puVar1 = 0;
  *(undefined *)((int)puVar1 + 3) = 0xff;
  *(undefined *)(puVar1 + 1) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_Init(struct _G2Anim_Type *anim /*$s0*/, struct _Model *modelData /*$s1*/)
 // line 374, offset 0x80092460
	/* begin block 1 */
		// Start line: 375
		// Start offset: 0x80092460
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $v0
	// 		int sectionID; // $a0
	/* end block 1 */
	// End offset: 0x800924D4
	// End Line: 428

	/* begin block 2 */
		// Start line: 736
	/* end block 2 */
	// End Line: 737

/* File: C:\kain2\game\G2\ANIMG2.C */

void G2Anim_Init(_G2Anim_Type *anim,_Model *modelData)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  
  anim->sectionCount = '\x01';
  anim->masterSection = '\0';
  anim->controllerList = 0;
  anim->disabledControllerList = 0;
  anim->segMatrices = (_G2Matrix_Type *)0x0;
  anim->modelData = modelData;
  memset();
  iVar3 = 0;
  iVar2 = 0x24;
  do {
    puVar1 = &anim->sectionCount + iVar2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(puVar1 + 6) = 0xffff;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0x1000;
    iVar2 = iVar2 + 0x30;
  } while (iVar3 < 3);
  anim->section[0].segCount = *(uchar *)&modelData->numSegments;
  return;
}



// decompiled code
// original method signature: 
// struct _G2AnimSection_Type * /*$ra*/ G2Anim_AddSection(struct _G2Anim_Type *anim /*$s1*/, int firstSegID /*$s2*/, int segCount /*$s3*/)
 // line 439, offset 0x800924f4
	/* begin block 1 */
		// Start line: 440
		// Start offset: 0x800924F4
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $s0
	/* end block 1 */
	// End offset: 0x800924F4
	// End Line: 440

	/* begin block 2 */
		// Start line: 904
	/* end block 2 */
	// End Line: 905

/* File: C:\kain2\game\G2\ANIMG2.C */

_G2AnimSection_Type * G2Anim_AddSection(_G2Anim_Type *anim,int firstSegID,int segCount)

{
  uchar uVar1;
  _G2AnimSection_Type *p_Var2;
  
  p_Var2 = anim->section + anim->sectionCount;
  memset();
  uVar1 = anim->sectionCount;
  p_Var2->storedTime = -1;
  p_Var2->firstSeg = (uchar)firstSegID;
  p_Var2->segCount = (uchar)segCount;
  p_Var2->swAlarmTable = (short *)0x0;
  p_Var2->speedAdjustment = 0x1000;
  p_Var2->sectionID = uVar1;
  anim->sectionCount = anim->sectionCount + '\x01';
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_Free(struct _G2Anim_Type *anim /*$s4*/)
 // line 487, offset 0x80092590
	/* begin block 1 */
		// Start line: 488
		// Start offset: 0x80092590
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s1
	// 		int sectionID; // $s2
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $s0
	/* end block 1 */
	// End offset: 0x8009262C
	// End Line: 527

	/* begin block 2 */
		// Start line: 1048
	/* end block 2 */
	// End Line: 1049

/* File: C:\kain2\game\G2\ANIMG2.C */

void G2Anim_Free(_G2Anim_Type *anim)

{
  _G2Bool_Enum _Var1;
  _G2AnimInterpInfo_Type *p_Var2;
  _G2AnimSection_Type *section;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (anim->sectionCount != '\0') {
    iVar4 = 0x24;
    do {
      section = (_G2AnimSection_Type *)(&anim->sectionCount + iVar4);
      _Var1 = G2AnimSection_IsInInterpolation(section);
      if (_Var1 != G2FALSE) {
        section->elapsedTime = section->interpInfo->targetTime;
      }
      _G2Anim_FreeChanStatusBlockList(section->chanStatusBlockList);
      p_Var2 = section->interpInfo;
      section->chanStatusBlockList = (_G2AnimChanStatusBlock_Type *)0x0;
      if (p_Var2 != (_G2AnimInterpInfo_Type *)0x0) {
        _G2Anim_FreeInterpStateBlockList(p_Var2->stateBlockList);
        p_Var2->stateBlockList = (_G2AnimInterpStateBlock_Type *)0x0;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x30;
    } while (iVar3 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_Restore(struct _G2Anim_Type *anim /*$s2*/)
 // line 531, offset 0x8009264c
	/* begin block 1 */
		// Start line: 532
		// Start offset: 0x8009264C
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $a0
	// 		int sectionID; // $s0
	/* end block 1 */
	// End offset: 0x800926B4
	// End Line: 553

	/* begin block 2 */
		// Start line: 1162
	/* end block 2 */
	// End Line: 1163

/* File: C:\kain2\game\G2\ANIMG2.C */

void G2Anim_Restore(_G2Anim_Type *anim)

{
  _G2AnimSection_Type *section;
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      section = (_G2AnimSection_Type *)(&anim->sectionCount + iVar2);
      if (section->keylist != (_G2AnimKeylist_Type *)0x0) {
        section->storedTime = -section->keylist->timePerKey;
        G2AnimSection_JumpToTime(section,section->elapsedTime);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_BuildTransforms(struct _G2Anim_Type *anim /*$s0*/)
 // line 562, offset 0x800926cc
	/* begin block 1 */
		// Start line: 563
		// Start offset: 0x800926CC

		/* begin block 1.1 */
			// Start line: 574
			// Start offset: 0x800926F4
		/* end block 1.1 */
		// End offset: 0x800926FC
		// End Line: 574

		/* begin block 1.2 */
			// Start line: 586
			// Start offset: 0x80092734

			/* begin block 1.2.1 */
				// Start line: 586
				// Start offset: 0x80092734
				// Variables:
			// 		unsigned short z; // $v0
			// 		unsigned long xy; // $v1
			/* end block 1.2.1 */
			// End offset: 0x80092734
			// End Line: 586
		/* end block 1.2 */
		// End offset: 0x80092734
		// End Line: 586

		/* begin block 1.3 */
			// Start line: 598
			// Start offset: 0x80092768
		/* end block 1.3 */
		// End offset: 0x80092768
		// End Line: 598
	/* end block 1 */
	// End offset: 0x80092768
	// End Line: 598

	/* begin block 2 */
		// Start line: 1238
	/* end block 2 */
	// End Line: 1239

/* File: C:\kain2\game\G2\ANIMG2.C */

void G2Anim_BuildTransforms(_G2Anim_Type *anim)

{
  byte bVar1;
  ushort uVar2;
  
  G2Anim_UpdateStoredFrame(anim);
  if ((anim->section[0].flags & 0x88) != 0x80) {
    *(undefined4 *)&anim->rootTrans = 0;
    (anim->rootTrans).z = 0;
  }
  if ((anim->section[0].flags & 4) != 0) {
    (anim->rootTrans).x = -(anim->rootTrans).x;
    (anim->rootTrans).z = -(anim->rootTrans).z;
    (anim->rootTrans).y = -(anim->rootTrans).y;
  }
  DAT_800d4f20 = (anim->rootTrans).z;
  DAT_800d4f1c = *(undefined4 *)&anim->rootTrans;
  if (anim->controllerList == 0) {
    _G2Anim_BuildTransformsNoControllers(anim);
  }
  else {
    _G2Anim_BuildTransformsWithControllers(anim);
  }
  bVar1 = anim->section[0].flags;
  uVar2 = anim->flags;
  *(undefined4 *)&anim->rootTrans = 0;
  (anim->rootTrans).z = 0;
  anim->section[0].flags = bVar1 & 0x7f;
  anim->flags = uVar2 & 0xfffe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_UpdateStoredFrame(struct _G2Anim_Type *anim /*$s2*/)
 // line 617, offset 0x80092798
	/* begin block 1 */
		// Start line: 618
		// Start offset: 0x80092798
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $s0
	// 		short storedTime; // $s3
	// 		short elapsedTime; // $s4
	// 		struct _G2SVector3_Type motionVector; // stack offset -32
	// 		int sectionCount; // $s1
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $v0

		/* begin block 1.1 */
			// Start line: 669
			// Start offset: 0x80092824
			// Variables:
		// 		struct _G2SVector3_Type *vector; // $a3
		/* end block 1.1 */
		// End offset: 0x80092824
		// End Line: 669
	/* end block 1 */
	// End offset: 0x800928F4
	// End Line: 703

	/* begin block 2 */
		// Start line: 1353
	/* end block 2 */
	// End Line: 1354

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\G2\ANIMG2.C */

void G2Anim_UpdateStoredFrame(_G2Anim_Type *anim)

{
  ushort uVar1;
  bool bVar2;
  ushort intervalStart;
  ushort intervalEnd;
  _G2AnimSection_Type *section;
  uint uVar3;
  undefined4 local_20;
  short local_1c;
  
  section = anim->section;
  uVar3 = (uint)anim->sectionCount;
  intervalStart = anim->section[0].storedTime;
  uVar1 = anim->section[0].elapsedTime;
  if (anim->sectionCount != 0) {
    do {
      if ((section->interpInfo == (_G2AnimInterpInfo_Type *)0x0) ||
         (section->interpInfo->stateBlockList == (_G2AnimInterpStateBlock_Type *)0x0)) {
        _G2AnimSection_UpdateStoredFrameFromData(section,anim);
      }
      else {
        _G2AnimSection_UpdateStoredFrameFromQuat(section);
      }
      section = section + 1;
      uVar3 = uVar3 - 1;
    } while (0 < (int)uVar3);
  }
  if ((int)((uint)intervalStart << 0x10) < 0) {
    intervalStart = 0;
  }
  local_20 = 0;
  local_1c = 0;
  intervalEnd = uVar1;
  if (((short)intervalStart < (short)uVar1) ||
     (bVar2 = (short)uVar1 < (short)intervalStart, intervalEnd = intervalStart,
     intervalStart = uVar1, bVar2)) {
    G2Anim_GetRootMotionOverInterval(anim,intervalStart,intervalEnd,(_G2SVector3_Type *)&local_20);
  }
  if ((anim->section[0].flags & 4) == 0) {
    (anim->rootTrans).x = (anim->rootTrans).x + (short)local_20;
    (anim->rootTrans).y = (anim->rootTrans).y + local_20._2_2_;
    local_1c = (anim->rootTrans).z + local_1c;
  }
  else {
    (anim->rootTrans).x = (anim->rootTrans).x - (short)local_20;
    (anim->rootTrans).y = (anim->rootTrans).y - local_20._2_2_;
    local_1c = (anim->rootTrans).z - local_1c;
  }
  (anim->rootTrans).z = local_1c;
  return;
}



// decompiled code
// original method signature: 
// struct _G2AnimSection_Type * /*$ra*/ G2Anim_GetSectionWithSeg(struct _G2Anim_Type *anim /*$a0*/, int segNumber /*$a1*/)
 // line 712, offset 0x80092914
	/* begin block 1 */
		// Start line: 715
		// Start offset: 0x80092914
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $a3
	// 		struct _G2AnimSection_Type *tempSection; // $a2
	// 		struct _G2AnimSection_Type *endSection; // $a0
	// 		int firstSeg; // $v1
	// 		int lastSeg; // $v0
	/* end block 1 */
	// End offset: 0x80092978
	// End Line: 747

	/* begin block 2 */
		// Start line: 1557
	/* end block 2 */
	// End Line: 1558

	/* begin block 3 */
		// Start line: 1559
	/* end block 3 */
	// End Line: 1560

	/* begin block 4 */
		// Start line: 1570
	/* end block 4 */
	// End Line: 1571

	/* begin block 5 */
		// Start line: 1574
	/* end block 5 */
	// End Line: 1575

/* File: C:\kain2\game\G2\ANIMG2.C */

_G2AnimSection_Type * G2Anim_GetSectionWithSeg(_G2Anim_Type *anim,int segNumber)

{
  _G2AnimSection_Type *p_Var1;
  _G2AnimSection_Type *p_Var2;
  
  p_Var1 = anim->section;
  while ((p_Var2 = (_G2AnimSection_Type *)0x0, p_Var1 < anim->section + anim->sectionCount &&
         ((segNumber < (int)(uint)p_Var1->firstSeg ||
          (p_Var2 = p_Var1, (int)((uint)p_Var1->firstSeg + (uint)p_Var1->segCount) <= segNumber)))))
  {
    p_Var1 = p_Var1 + 1;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// enum _G2Bool_Enum /*$ra*/ G2Anim_SegmentHasActiveChannels(struct _G2Anim_Type *anim /*$s0*/, int segNumber /*$s1*/, unsigned short chanMask /*$a2*/)
 // line 758, offset 0x80092980
	/* begin block 1 */
		// Start line: 759
		// Start offset: 0x80092980
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $a1
	// 		unsigned char *segChanFlagStream; // $a0
	// 		unsigned char activeChanBits; // $a2
	// 		unsigned short dataFlagBits; // $v1
	// 		unsigned short segFlagBits; // $a1
	// 		int flagBytesPerSeg; // $t0
	/* end block 1 */
	// End offset: 0x80092A9C
	// End Line: 848

	/* begin block 2 */
		// Start line: 1650
	/* end block 2 */
	// End Line: 1651

/* File: C:\kain2\game\G2\ANIMG2.C */

_G2Bool_Enum G2Anim_SegmentHasActiveChannels(_G2Anim_Type *anim,int segNumber,ushort chanMask)

{
  byte bVar1;
  ushort uVar2;
  _G2AnimSection_Type *p_Var3;
  _G2AnimKeylist_Type *p_Var4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  p_Var3 = G2Anim_GetSectionWithSeg(anim,segNumber);
  iVar7 = anim->modelData->numSegments * 3;
  iVar5 = iVar7 + 7;
  if (iVar5 < 0) {
    iVar5 = iVar7 + 0xe;
  }
  segNumber = segNumber * 3;
  p_Var4 = p_Var3->keylist;
  iVar7 = segNumber;
  if (segNumber < 0) {
    iVar7 = segNumber + 7;
  }
  iVar9 = (int)&p_Var4->sectionData + (iVar7 >> 3) + (uint)p_Var4->sectionCount * 4;
  puVar6 = (ushort *)(iVar9 + 1);
  uVar10 = segNumber + (iVar7 >> 3) * -8;
  bVar1 = *(byte *)(&p_Var4->sectionData + (uint)p_Var4->sectionCount);
  uVar8 = 0;
  if ((bVar1 & 1) != 0) {
    puVar6 = (ushort *)((int)puVar6 + (iVar5 >> 3));
    uVar8 = (int)(uint)*(ushort *)(iVar9 + 1) >> (uVar10 & 0x1f) & 7;
  }
  if ((bVar1 & 2) != 0) {
    uVar2 = *puVar6;
    puVar6 = (ushort *)((int)puVar6 + (iVar5 >> 3));
    uVar8 = uVar8 | ((int)(uint)uVar2 >> (uVar10 & 0x1f) & 7U) << 4;
  }
  if ((bVar1 & 4) != 0) {
    uVar8 = uVar8 | ((int)(uint)*puVar6 >> (uVar10 & 0x1f) & 7U) << 8;
  }
  return (uint)((uVar8 & chanMask) != 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_GetSegChannelValue(struct _G2Anim_Type *anim /*$s0*/, int segIndex /*$s1*/, unsigned short *valueTable /*$s3*/, unsigned short channelMask /*$s2*/)
 // line 866, offset 0x80092ac0
	/* begin block 1 */
		// Start line: 867
		// Start offset: 0x80092AC0
		// Variables:
	// 		unsigned short *chanFinalValue; // $v1

		/* begin block 1.1 */
			// Start line: 867
			// Start offset: 0x80092AC0

			/* begin block 1.1.1 */
				// Start line: 867
				// Start offset: 0x80092AC0
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80092AC0
			// End Line: 867
		/* end block 1.1 */
		// End offset: 0x80092AC0
		// End Line: 867
	/* end block 1 */
	// End offset: 0x80092B54
	// End Line: 905

	/* begin block 2 */
		// Start line: 1902
	/* end block 2 */
	// End Line: 1903

/* File: C:\kain2\game\G2\ANIMG2.C */

void G2Anim_GetSegChannelValue
               (_G2Anim_Type *anim,int segIndex,ushort *valueTable,ushort channelMask)

{
  ushort *puVar1;
  uint uVar2;
  
  uVar2 = (uint)channelMask;
  G2Anim_UpdateStoredFrame(anim);
  DAT_800d4f1c = *(undefined4 *)&anim->rootTrans;
  DAT_800d4f20 = (anim->rootTrans).z;
  _G2Anim_ApplyControllersToStoredFrame(anim);
  puVar1 = (ushort *)(&_segValues + segIndex * 0x18);
  if (channelMask != 0) {
    do {
      if ((uVar2 & 1) != 0) {
        *valueTable = *puVar1;
        valueTable = valueTable + 1;
      }
      uVar2 = uVar2 >> 1;
      puVar1 = puVar1 + 1;
    } while (uVar2 != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_GetRootMotionFromTimeForDuration(struct _G2Anim_Type *anim /*$t0*/, short durationStart /*$s1*/, short duration /*$s3*/, struct _G2SVector3_Type *motionVector /*$s5*/)
 // line 922, offset 0x80092b70
	/* begin block 1 */
		// Start line: 923
		// Start offset: 0x80092B70
		// Variables:
	// 		struct _G2Anim_Type dummyAnim; // stack offset -216
	// 		struct _G2AnimSection_Type *section; // $s2
	// 		struct _G2AnimKeylist_Type *keylist; // $s4
	// 		short storedKeyEndTime; // $s2
	// 		short timePerKey; // $s0
	// 		short keyTime; // $a0
	// 		long alpha; // $a1
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $a0

		/* begin block 1.1 */
			// Start line: 949
			// Start offset: 0x80092BC8
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $s5
		// 		struct _G2SVector3_Type *base; // $v0
		// 		struct _G2SVector3_Type *offset; // $v1
		// 		long alpha; // $a1
		/* end block 1.1 */
		// End offset: 0x80092BC8
		// End Line: 949

		/* begin block 1.2 */
			// Start line: 965
			// Start offset: 0x80092CAC
			// Variables:
		// 		struct _G2SVector3_Type *vector; // $s5
		/* end block 1.2 */
		// End offset: 0x80092CAC
		// End Line: 965

		/* begin block 1.3 */
			// Start line: 1001
			// Start offset: 0x80092DA0
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $s5
		// 		struct _G2SVector3_Type *base; // $s5
		// 		long alpha; // $a1
		/* end block 1.3 */
		// End offset: 0x80092DA0
		// End Line: 1001
	/* end block 1 */
	// End offset: 0x80092E24
	// End Line: 1015

	/* begin block 2 */
		// Start line: 2014
	/* end block 2 */
	// End Line: 2015

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\G2\ANIMG2.C */

void G2Anim_GetRootMotionFromTimeForDuration
               (_G2Anim_Type *anim,short durationStart,short duration,_G2SVector3_Type *motionVector
               )

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  _G2AnimInterpInfo_Type *p_Var6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  _G2AnimInterpStateBlock_Type *p_Var11;
  uint uVar12;
  _G2AnimKeylist_Type *p_Var13;
  int iVar14;
  uint uVar15;
  _G2Anim_Type local_d8;
  
  uVar5 = (uint)(ushort)duration;
  uVar7 = (uint)(ushort)durationStart;
  p_Var6 = anim->section[0].interpInfo;
  if (p_Var6 != (_G2AnimInterpInfo_Type *)0x0) {
    p_Var11 = p_Var6->stateBlockList;
    if (p_Var11 != (_G2AnimInterpStateBlock_Type *)0x0) {
      lVar4 = _G2AnimAlphaTable_GetValue
                        (p_Var6->alphaTable,((int)(uVar7 << 0x10) >> 4) / (int)p_Var6->duration);
      setCopReg(2,0xc800,(uint)(ushort)p_Var11->quatInfo[0].srcTrans.x);
      setCopReg(2,0xd000,(uint)(ushort)p_Var11->quatInfo[0].srcTrans.y);
      setCopReg(2,0xd800,(uint)(ushort)p_Var11->quatInfo[0].srcTrans.z);
      setCopReg(2,0x4800,(uint)(ushort)p_Var11->quatInfo[0].destTrans.x);
      setCopReg(2,0x5000,(uint)(ushort)p_Var11->quatInfo[0].destTrans.y);
      setCopReg(2,0x5800,(uint)(ushort)p_Var11->quatInfo[0].destTrans.z);
      setCopReg(2,0x4000,lVar4);
      copFunction(2,0x1a8003e);
      uVar8 = getCopReg(2,0xc800);
      uVar9 = getCopReg(2,0xd000);
      uVar10 = getCopReg(2,0xd800);
      motionVector->x = (short)uVar8;
      motionVector->y = (short)uVar9;
      motionVector->z = (short)uVar10;
      iVar14 = ((int)(uVar5 << 0x10) >> 4) / (int)(anim->section[0].keylist)->timePerKey;
      motionVector->x = (short)(motionVector->x * iVar14 >> 0xc);
      motionVector->y = (short)(motionVector->y * iVar14 >> 0xc);
      motionVector->z = (short)(motionVector->z * iVar14 >> 0xc);
      return;
    }
  }
  p_Var13 = anim->section[0].keylist;
  sVar1 = p_Var13->timePerKey;
  uVar12 = (uint)(ushort)p_Var13->timePerKey;
  uVar15 = uVar12 * ((int)durationStart / (int)sVar1 + 1);
  uVar2 = p_Var13->keyCount;
  local_d8.sectionCount = '\x01';
  local_d8.modelData = anim->modelData;
  local_d8.section[0].sectionID = '\0';
  local_d8.section[0].firstSeg = '\0';
  local_d8.section[0].segCount = '\x01';
  local_d8.section[0].chanStatusBlockList = (_G2AnimChanStatusBlock_Type *)0x0;
  local_d8.section[0].storedTime = -p_Var13->timePerKey;
  *(undefined4 *)motionVector = 0;
  motionVector->z = 0;
  local_d8.section[0].keylist = p_Var13;
  if (duration != 0) {
    do {
      local_d8.section[0].elapsedTime = (short)uVar7;
      if ((short)(sVar1 * (uVar2 - 1)) <= local_d8.section[0].elapsedTime) {
        uVar12 = (uint)p_Var13->s0TailTime;
      }
      _G2AnimSection_UpdateStoredFrameFromData(local_d8.section,&local_d8);
      uVar3 = uVar15 - uVar7;
      if ((int)(uVar5 << 0x10) < (int)((uVar15 - uVar7) * 0x10000)) {
        uVar3 = uVar5;
      }
      if ((int)(short)uVar3 < (int)(short)uVar12) {
        iVar14 = ((int)(short)uVar3 << 0xc) / (int)(short)uVar12;
      }
      else {
        iVar14 = 0x1000;
      }
      setCopReg(2,0xc800,(uint)(ushort)motionVector->x);
      setCopReg(2,0xd000,(uint)(ushort)motionVector->y);
      setCopReg(2,0xd800,(uint)(ushort)motionVector->z);
      setCopReg(2,0x4800,(uint)(ushort)DAT_800d4f1c);
      setCopReg(2,0x5000,(uint)DAT_800d4f1c._2_2_);
      setCopReg(2,0x5800,(uint)DAT_800d4f20);
      setCopReg(2,0x4000,iVar14);
      copFunction(2,0x1a8003e);
      uVar8 = getCopReg(2,0xc800);
      uVar9 = getCopReg(2,0xd000);
      uVar10 = getCopReg(2,0xd800);
      motionVector->x = (short)uVar8;
      motionVector->y = (short)uVar9;
      motionVector->z = (short)uVar10;
      uVar5 = uVar5 - uVar3;
      uVar7 = uVar15;
      uVar15 = uVar15 + uVar12;
    } while ((uVar5 & 0xffff) != 0);
  }
  _G2Anim_FreeChanStatusBlockList(local_d8.section[0].chanStatusBlockList);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SwitchToKeylistAtTime(struct _G2AnimSection_Type *section /*$s1*/, struct _G2AnimKeylist_Type *keylist /*$s4*/, int keylistID /*$s5*/, short targetTime /*$s3*/)
 // line 1121, offset 0x80092e4c
	/* begin block 1 */
		// Start line: 1122
		// Start offset: 0x80092E4C
		// Variables:
	// 		struct _G2Anim_Type *anim; // $s2
	// 		struct _G2SVector3_Type rootMotion; // stack offset -40
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $s0

		/* begin block 1.1 */
			// Start line: 1144
			// Start offset: 0x80092ED4
		/* end block 1.1 */
		// End offset: 0x80092EDC
		// End Line: 1144

		/* begin block 1.2 */
			// Start line: 1197
			// Start offset: 0x80092F98

			/* begin block 1.2.1 */
				// Start line: 1197
				// Start offset: 0x80092F98
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.2.1 */
			// End offset: 0x80092FB8
			// End Line: 1197
		/* end block 1.2 */
		// End offset: 0x80092FB8
		// End Line: 1197
	/* end block 1 */
	// End offset: 0x80092FD4
	// End Line: 1206

	/* begin block 2 */
		// Start line: 2234
	/* end block 2 */
	// End Line: 2235

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\G2\ANIMG2.C */

void G2AnimSection_SwitchToKeylistAtTime
               (_G2AnimSection_Type *section,_G2AnimKeylist_Type *keylist,int keylistID,
               short targetTime)

{
  _G2Anim_Type *anim;
  _G2AnimInterpInfo_Type *p_Var1;
  undefined4 local_28;
  short local_24;
  
  anim = _G2AnimSection_GetAnim(section);
  if (section->firstSeg == '\0') {
    anim->flags = anim->flags | 1;
    if ((section->keylist == (_G2AnimKeylist_Type *)0x0) || (section->storedTime < 0)) {
      local_28 = 0;
      local_24 = 0;
    }
    else {
      G2Anim_GetRootMotionOverInterval
                (anim,section->storedTime,section->elapsedTime,(_G2SVector3_Type *)&local_28);
    }
    local_28 = CONCAT22((short)((uint)local_28 >> 0x10) + (anim->rootTrans).y,
                        (short)local_28 + (anim->rootTrans).x);
    local_24 = local_24 + (anim->rootTrans).z;
  }
  p_Var1 = section->interpInfo;
  if ((p_Var1 != (_G2AnimInterpInfo_Type *)0x0) &&
     (p_Var1->stateBlockList != (_G2AnimInterpStateBlock_Type *)0x0)) {
    _G2Anim_FreeInterpStateBlockList(p_Var1->stateBlockList);
    p_Var1->stateBlockList = (_G2AnimInterpStateBlock_Type *)0x0;
  }
  G2AnimSection_ClearAlarm(section,3);
  if (keylist != section->keylist) {
    section->keylist = keylist;
    section->keylistID = (ushort)keylistID;
    section->storedTime = -keylist->timePerKey;
  }
  G2AnimSection_JumpToTime(section,targetTime);
  if (section->firstSeg == '\0') {
    section->flags = section->flags | 0x80;
    *(undefined4 *)&anim->rootTrans = local_28;
    (anim->rootTrans).z = local_24;
  }
  if ((section->flags & 2) != 0) {
    G2AnimSection_SetLoopRangeAll(section);
  }
  G2AnimSection_SetUnpaused(section);
  section->swAlarmTable = (short *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_JumpToTime(struct _G2AnimSection_Type *section /*$s0*/, short targetTime /*$a1*/)
 // line 1225, offset 0x80093004
	/* begin block 1 */
		// Start line: 1226
		// Start offset: 0x80093004
		// Variables:
	// 		struct _G2Anim_Type *anim; // $s1

		/* begin block 1.1 */
			// Start line: 1266
			// Start offset: 0x80093084
		/* end block 1.1 */
		// End offset: 0x8009308C
		// End Line: 1266
	/* end block 1 */
	// End offset: 0x8009308C
	// End Line: 1268

	/* begin block 2 */
		// Start line: 2628
	/* end block 2 */
	// End Line: 2629

/* File: C:\kain2\game\G2\ANIMG2.C */

void G2AnimSection_JumpToTime(_G2AnimSection_Type *section,short targetTime)

{
  _G2Anim_Type *anim;
  
  anim = _G2AnimSection_GetAnim(section);
  if (targetTime < section->elapsedTime) {
    section->storedTime = -section->keylist->timePerKey;
  }
  section->elapsedTime = targetTime;
  _G2AnimSection_UpdateStoredFrameFromData(section,anim);
  G2AnimSection_ClearAlarm(section,3);
  section->flags = section->flags & 0x7f;
  if (section->firstSeg == '\0') {
    *(undefined4 *)&anim->rootTrans = 0;
    (anim->rootTrans).z = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ G2AnimSection_UpdateOverInterval(struct _G2AnimSection_Type *section /*$s0*/, short interval /*$a1*/)
 // line 1273, offset 0x800930a4
	/* begin block 1 */
		// Start line: 1274
		// Start offset: 0x800930A4
		// Variables:
	// 		struct _G2Anim_Type *anim; // $s2
	// 		struct _G2SVector3_Type motionVector; // stack offset -32
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $s1
	// 		short elapsedTime; // $s3

		/* begin block 1.1 */
			// Start line: 1324
			// Start offset: 0x8009318C

			/* begin block 1.1.1 */
				// Start line: 1324
				// Start offset: 0x8009318C
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8009318C
			// End Line: 1324
		/* end block 1.1 */
		// End offset: 0x8009318C
		// End Line: 1324
	/* end block 1 */
	// End offset: 0x80093278
	// End Line: 1361

	/* begin block 2 */
		// Start line: 2725
	/* end block 2 */
	// End Line: 2726

/* File: C:\kain2\game\G2\ANIMG2.C */

short G2AnimSection_UpdateOverInterval(_G2AnimSection_Type *section,short interval)

{
  ushort intervalStart;
  short sVar1;
  _G2Anim_Type *anim;
  int iVar2;
  int iVar3;
  _G2AnimInterpInfo_Type *p_Var4;
  undefined4 local_20;
  short local_1c;
  
  if ((section->flags & 1) == 0) {
    p_Var4 = section->interpInfo;
    if ((p_Var4 == (_G2AnimInterpInfo_Type *)0x0) ||
       (p_Var4->stateBlockList == (_G2AnimInterpStateBlock_Type *)0x0)) {
      if ((section->flags & 4) == 0) {
        sVar1 = G2AnimSection_AdvanceOverInterval(section,interval);
      }
      else {
        sVar1 = G2AnimSection_RewindOverInterval(section,interval);
      }
    }
    else {
      anim = _G2AnimSection_GetAnim(section);
      anim->flags = anim->flags | 1;
      intervalStart = section->elapsedTime;
      iVar3 = (uint)intervalStart + ((int)interval * section->speedAdjustment >> 0xc);
      iVar2 = (iVar3 - (uint)(ushort)p_Var4->duration) * 0x10000;
      sVar1 = (short)((uint)iVar2 >> 0x10);
      if (iVar2 >> 0x10 < 0) {
        section->elapsedTime = (short)iVar3;
        sVar1 = 0;
      }
      else {
        section->storedTime = -section->keylist->timePerKey;
        G2AnimSection_JumpToTime(section,p_Var4->targetTime);
        if (section->firstSeg == '\0') {
          G2Anim_GetRootMotionOverInterval
                    (anim,intervalStart,p_Var4->duration,(_G2SVector3_Type *)&local_20);
          *(undefined4 *)&anim->rootTrans = local_20;
          (anim->rootTrans).z = local_1c;
          section->flags = section->flags | 0x80;
        }
        _G2Anim_FreeInterpStateBlockList(p_Var4->stateBlockList);
        p_Var4->stateBlockList = (_G2AnimInterpStateBlock_Type *)0x0;
        if ((section->flags & 2) != 0) {
          G2AnimSection_SetLoopRangeAll(section);
        }
        section->alarmFlags = section->alarmFlags | 0x10;
        if (section->callback != (_func_8 *)0x0) {
          (*section->callback)(anim,(uint)section->sectionID,3,0,0,section->callbackData);
        }
      }
    }
  }
  else {
    sVar1 = 0;
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ G2AnimSection_AdvanceOverInterval(struct _G2AnimSection_Type *section /*$s1*/, short interval /*$s0*/)
 // line 1381, offset 0x80093298
	/* begin block 1 */
		// Start line: 1382
		// Start offset: 0x80093298
		// Variables:
	// 		struct _G2AnimKeylist_Type *keylist; // $a0
	// 		short newTime; // $s6
	// 		short extraTime; // $s2
	// 		short elapsedTime; // $fp
	// 		short endTime; // $s4
	// 		short loopExtraTime; // stack offset -48
	// 		short *swAlarmTable; // $s0
	// 		short swAlarmTime; // $v1
	// 		struct _G2Anim_Type *anim; // $s7
	// 		struct _G2SVector3_Type motionVector; // stack offset -56
	// 		unsigned long message; // $s3

		/* begin block 1.1 */
			// Start line: 1614
			// Start offset: 0x800935D4
		/* end block 1.1 */
		// End offset: 0x800935DC
		// End Line: 1614

		/* begin block 1.2 */
			// Start line: 1624
			// Start offset: 0x800935EC

			/* begin block 1.2.1 */
				// Start line: 1624
				// Start offset: 0x800935EC
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.2.1 */
			// End offset: 0x800935EC
			// End Line: 1624
		/* end block 1.2 */
		// End offset: 0x800935EC
		// End Line: 1624
	/* end block 1 */
	// End offset: 0x80093640
	// End Line: 1658

	/* begin block 2 */
		// Start line: 2959
	/* end block 2 */
	// End Line: 2960

/* File: C:\kain2\game\G2\ANIMG2.C */

short G2AnimSection_AdvanceOverInterval(_G2AnimSection_Type *section,short interval)

{
  byte bVar1;
  ushort startTime;
  ushort uVar2;
  short intervalEnd;
  short sVar3;
  _G2Anim_Type *anim;
  short *psVar4;
  _G2Anim_Type *p_Var5;
  long lVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 local_38;
  short local_34;
  ushort local_30;
  
  local_30 = 0;
  if (((section->flags & 1) == 0) && ((section->alarmFlags & 1) == 0)) {
    anim = _G2AnimSection_GetAnim(section);
    anim->flags = anim->flags | 1;
    G2AnimSection_ClearAlarm(section,3);
    bVar1 = section->flags;
    startTime = section->elapsedTime;
    section->flags = bVar1 & 0xfb;
    if ((bVar1 & 2) == 0) {
      uVar2 = G2AnimKeylist_GetDuration(section->keylist);
    }
    else {
      uVar2 = section->loopEndTime;
    }
    uVar13 = (uint)uVar2;
    lVar8 = (uint)startTime + ((int)interval * section->speedAdjustment >> 0xc);
    psVar4 = section->swAlarmTable;
    if (psVar4 == (short *)0x0) {
      G2AnimSection_ClearAlarm(section,0x20);
    }
    else {
      iVar7 = (int)*psVar4;
      if (iVar7 != -1) {
        iVar11 = (int)(short)startTime;
        iVar9 = lVar8 * 0x10000 >> 0x10;
        do {
          if ((((iVar11 < iVar7) && (iVar7 <= iVar9)) ||
              ((section->storedTime < 1 && (iVar11 == iVar7)))) &&
             (section->alarmFlags = section->alarmFlags | 0x20, section->callback != (_func_8 *)0x0)
             ) {
            (*section->callback)(anim,(uint)section->sectionID,5,iVar11,iVar9,section->callbackData)
            ;
          }
          psVar4 = psVar4 + 1;
          iVar7 = (int)*psVar4;
        } while (iVar7 != -1);
      }
    }
    _G2AnimSection_TriggerEffects(section,startTime,(short)lVar8);
    uVar10 = lVar8 - uVar13;
    iVar7 = uVar10 * 0x10000;
    while( true ) {
      sVar3 = (short)uVar10;
      intervalEnd = (short)lVar8;
      if (iVar7 < 0) break;
      uVar12 = 2;
      intervalEnd = (short)uVar13;
      if ((section->flags & 2) == 0) {
        uVar12 = 1;
        lVar8 = uVar13 - 1;
        section->alarmFlags = section->alarmFlags | 1;
      }
      else {
        section->alarmFlags = section->alarmFlags | 4;
        G2AnimSection_JumpToTime(section,section->loopStartTime);
        lVar8 = (uint)(ushort)section->loopStartTime + uVar10;
        local_30 = (short)lVar8 - intervalEnd;
        _G2AnimSection_TriggerEffects
                  (section,(short)(((uint)(ushort)section->loopStartTime - 1) * 0x10000 >> 0x10),
                   (short)((uint)(lVar8 * 0x10000) >> 0x10));
        if ((int)intervalEnd <= lVar8 * 0x10000 >> 0x10) {
          lVar8 = uVar13 - 1;
        }
      }
      if (section->firstSeg == '\0') {
        anim = _G2AnimSection_GetAnim(section);
        G2Anim_GetRootMotionOverInterval(anim,startTime,intervalEnd,(_G2SVector3_Type *)&local_38);
      }
      if (section->callback != (_func_8 *)0x0) {
        p_Var5 = _G2AnimSection_GetAnim(section);
        lVar6 = (*section->callback)
                          (p_Var5,(uint)section->sectionID,uVar12,(int)(short)lVar8,(int)sVar3,
                           section->callbackData);
        intervalEnd = (short)lVar6;
        if ((int)intervalEnd == (int)(short)lVar8) {
          if ((section->flags & 2) == 0) {
            local_38 = 0;
            local_34 = 0;
          }
          else {
            G2AnimSection_JumpToTime(section,intervalEnd);
            section->storedTime = section->loopStartTime;
          }
        }
        else {
          G2AnimSection_JumpToTime(section,intervalEnd);
          lVar8 = lVar6;
        }
      }
      intervalEnd = (short)lVar8;
      if (section->firstSeg == '\0') {
        *(undefined4 *)&anim->rootTrans = local_38;
        (anim->rootTrans).z = local_34;
        section->flags = section->flags | 0x80;
      }
      if ((section->flags & 2) == 0) goto LAB_80093634;
      uVar13 = (uint)(ushort)section->loopEndTime;
      uVar10 = (uint)local_30;
      iVar7 = uVar10 << 0x10;
    }
    sVar3 = 0;
LAB_80093634:
    section->elapsedTime = intervalEnd;
  }
  else {
    sVar3 = 0;
  }
  return sVar3;
}



// decompiled code
// original method signature: 
// short /*$ra*/ G2AnimSection_RewindOverInterval(struct _G2AnimSection_Type *section /*$s1*/, short interval /*$a1*/)
 // line 1671, offset 0x80093670
	/* begin block 1 */
		// Start line: 1672
		// Start offset: 0x80093670
		// Variables:
	// 		short newTime; // $s3
	// 		short extraTime; // $s6
	// 		short elapsedTime; // $s7
	// 		short endTime; // $s2
	// 		struct _G2Anim_Type *anim; // $s4
	// 		struct _G2SVector3_Type motionVector; // stack offset -48
	// 		unsigned long message; // $s5

		/* begin block 1.1 */
			// Start line: 1832
			// Start offset: 0x80093838
		/* end block 1.1 */
		// End offset: 0x80093840
		// End Line: 1832

		/* begin block 1.2 */
			// Start line: 1841
			// Start offset: 0x80093850

			/* begin block 1.2.1 */
				// Start line: 1841
				// Start offset: 0x80093850
				// Variables:
			// 		unsigned short z; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.2.1 */
			// End offset: 0x80093850
			// End Line: 1841
		/* end block 1.2 */
		// End offset: 0x80093850
		// End Line: 1841
	/* end block 1 */
	// End offset: 0x80093884
	// End Line: 1867

	/* begin block 2 */
		// Start line: 3631
	/* end block 2 */
	// End Line: 3632

/* File: C:\kain2\game\G2\ANIMG2.C */

short G2AnimSection_RewindOverInterval(_G2AnimSection_Type *section,short interval)

{
  byte bVar1;
  ushort intervalStart;
  short targetTime;
  short sVar2;
  _G2Anim_Type *anim;
  int iVar3;
  _G2Anim_Type *p_Var4;
  long lVar5;
  uint uVar6;
  short sVar7;
  undefined4 uVar8;
  undefined4 local_30;
  short local_2c;
  
  if (((section->flags & 1) == 0) && ((section->alarmFlags & 2) == 0)) {
    anim = _G2AnimSection_GetAnim(section);
    anim->flags = anim->flags | 1;
    G2AnimSection_ClearAlarm(section,3);
    uVar6 = 0;
    bVar1 = section->flags;
    intervalStart = section->elapsedTime;
    section->flags = bVar1 | 4;
    if ((bVar1 & 2) != 0) {
      uVar6 = (uint)(ushort)section->loopStartTime;
    }
    iVar3 = (uint)intervalStart - ((int)interval * section->speedAdjustment >> 0xc);
    sVar7 = (short)iVar3;
    iVar3 = uVar6 - iVar3;
    sVar2 = (short)iVar3;
    if (iVar3 * 0x10000 < 1) {
      sVar2 = 0;
    }
    else {
      if ((bVar1 & 2) == 0) {
        uVar8 = 1;
        section->alarmFlags = section->alarmFlags | 2;
        sVar7 = (short)uVar6;
      }
      else {
        section->alarmFlags = section->alarmFlags | 4;
        G2AnimSection_JumpToTime(section,section->loopEndTime);
        uVar8 = 2;
        sVar7 = section->loopEndTime - sVar2;
      }
      if (section->firstSeg == '\0') {
        G2Anim_GetRootMotionOverInterval
                  (anim,intervalStart,(short)uVar6,(_G2SVector3_Type *)&local_30);
      }
      if (section->callback != (_func_8 *)0x0) {
        p_Var4 = _G2AnimSection_GetAnim(section);
        lVar5 = (*section->callback)
                          (p_Var4,(uint)section->sectionID,uVar8,(int)sVar7,(int)sVar2,
                           section->callbackData);
        targetTime = (short)lVar5;
        if (((section->flags & 2) == 0) && ((int)targetTime == (int)sVar7)) {
          local_30 = 0;
          local_2c = 0;
        }
        else {
          G2AnimSection_JumpToTime(section,targetTime);
          sVar7 = targetTime;
        }
      }
      if (section->firstSeg == '\0') {
        *(undefined4 *)&anim->rootTrans = local_30;
        (anim->rootTrans).z = local_2c;
        section->flags = section->flags | 0x80;
      }
    }
    section->elapsedTime = sVar7;
  }
  else {
    sVar2 = 0;
  }
  return sVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_BuildTransformsNoControllers(struct _G2Anim_Type *anim /*$s4*/)
 // line 1876, offset 0x800938b0
	/* begin block 1 */
		// Start line: 1877
		// Start offset: 0x800938B0
		// Variables:
	// 		struct _Segment *segment; // $a1
	// 		struct _G2Matrix_Type *segMatrix; // $s5
	// 		enum _G2Bool_Enum bRootTransUpdated; // $a2
	// 		int segIndex; // $s3
	// 		int segCount; // $s6
	// 		unsigned long disabledBits[3]; // stack offset -56
	// 		unsigned long disabledMask; // $s1
	// 		unsigned long parentMask; // $v1
	// 		unsigned long parentIndex; // $v0
	/* end block 1 */
	// End offset: 0x800939D8
	// End Line: 1949

	/* begin block 2 */
		// Start line: 4114
	/* end block 2 */
	// End Line: 4115

/* File: C:\kain2\game\G2\ANIMG2.C */

void _G2Anim_BuildTransformsNoControllers(_G2Anim_Type *anim)

{
  int iVar1;
  _G2Bool_Enum bRootTransUpdated;
  uint *puVar2;
  uint uVar3;
  ushort *puVar4;
  int segIndex;
  _G2Matrix_Type *segMatrix;
  int iVar5;
  uint local_38;
  ulong local_34;
  ulong local_30;
  
  segMatrix = anim->segMatrices;
  uVar3 = 1;
  local_38 = anim->disabledBits[0];
  segIndex = 0;
  local_34 = anim->disabledBits[1];
  local_30 = anim->disabledBits[2];
  iVar5 = anim->modelData->numSegments;
  bRootTransUpdated = (_G2Bool_Enum)((anim->section[0].flags & 0x88) == 0x80);
  if (0 < iVar5) {
    puVar4 = (ushort *)&anim->modelData->segmentList->parent;
    puVar2 = &local_38;
    do {
      iVar1 = (uint)*puVar4 << 0x10;
      if ((iVar1 >> 0x10 != -1) && (((&local_38)[iVar1 >> 0x15] & 1 << (*puVar4 & 0x1f)) != 0)) {
        *puVar2 = *puVar2 | uVar3;
      }
      if ((*puVar2 & uVar3) == 0) {
        _G2Anim_BuildSegTransformNoControllers
                  (segMatrix,anim->segMatrices + (short)*puVar4,bRootTransUpdated,segIndex);
      }
      bRootTransUpdated = G2FALSE;
      puVar4 = puVar4 + 0xc;
      segMatrix = segMatrix + 1;
      uVar3 = uVar3 << 1;
      segIndex = segIndex + 1;
      if (uVar3 == 0) {
        puVar2 = puVar2 + 1;
        uVar3 = 1;
      }
    } while (segIndex < iVar5);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_BuildSegTransformNoControllers(struct _G2Matrix_Type *segMatrix /*$s0*/, struct _G2Matrix_Type *parentMatrix /*$s3*/, enum _G2Bool_Enum bRootTransUpdated /*$s4*/, int segIndex /*$a3*/)
 // line 1959, offset 0x80093a04
	/* begin block 1 */
		// Start line: 1960
		// Start offset: 0x80093A04
		// Variables:
	// 		struct _G2AnimSegValue_Type *segValue; // $s1
	// 		struct _G2LVector3_Type scale; // stack offset -40

		/* begin block 1.1 */
			// Start line: 2009
			// Start offset: 0x80093A8C
			// Variables:
		// 		struct _G2SVector3_Type *svector; // $v0
		// 		struct _G2LVector3_Type *lvector; // $v1
		/* end block 1.1 */
		// End offset: 0x80093A8C
		// End Line: 2009
	/* end block 1 */
	// End offset: 0x80093BD4
	// End Line: 2055

	/* begin block 2 */
		// Start line: 4369
	/* end block 2 */
	// End Line: 4370

/* File: C:\kain2\game\G2\ANIMG2.C */

void _G2Anim_BuildSegTransformNoControllers
               (_G2Matrix_Type *segMatrix,_G2Matrix_Type *parentMatrix,
               _G2Bool_Enum bRootTransUpdated,int segIndex)

{
  ushort uVar1;
  bool bVar2;
  long lVar3;
  undefined4 in_zero;
  undefined4 in_at;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  VECTOR local_28;
  
  iVar4 = segIndex * 0x18;
  local_28.vx = (int)(short)*(ushort *)(&DAT_800d4f14 + iVar4);
  local_28.vy = (int)(short)*(ushort *)(&DAT_800d4f16 + iVar4);
  local_28.vz = (int)(short)*(ushort *)(&DAT_800d4f18 + iVar4);
  bVar2 = (ushort)(*(ushort *)(&DAT_800d4f14 + iVar4) | *(ushort *)(&DAT_800d4f16 + iVar4) |
                  *(ushort *)(&DAT_800d4f18 + iVar4)) != 0x1000;
  _G2Anim_BuildSegLocalRotMatrix((_G2AnimSegValue_Type *)(&_segValues + iVar4),segMatrix);
  if (bVar2) {
    ScaleMatrix((MATRIX *)segMatrix,&local_28);
    segMatrix->scaleFlag = (ushort)bVar2;
  }
  setCopControlWord(2,0,*(undefined4 *)parentMatrix->rotScale);
  setCopControlWord(2,0x800,*(undefined4 *)(parentMatrix->rotScale + 2));
  setCopControlWord(2,0x1000,*(undefined4 *)(parentMatrix->rotScale + 4));
  setCopControlWord(2,0x1800,*(undefined4 *)(parentMatrix->rotScale + 6));
  setCopControlWord(2,0x2000,*(undefined4 *)(parentMatrix->rotScale + 8));
  setCopReg(2,0x4800,(uint)(ushort)segMatrix->rotScale[0]);
  setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[3]);
  setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[6]);
  copFunction(2,0x49e012);
  uVar1 = segMatrix->rotScale[2];
  uVar6 = getCopReg(2,0x4800);
  uVar7 = getCopReg(2,0x5000);
  uVar8 = getCopReg(2,0x5800);
  setCopReg(2,0x4800,(uint)(ushort)segMatrix->rotScale[1]);
  setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[4]);
  setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[7]);
  segMatrix->rotScale[0] = (short)uVar6;
  segMatrix->rotScale[3] = (short)uVar7;
  copFunction(2,0x49e012);
  uVar6 = getCopReg(2,0x4800);
  uVar7 = getCopReg(2,0x5000);
  uVar5 = getCopReg(2,0x5800);
  setCopReg(2,0x4800,(uint)uVar1);
  setCopReg(2,0x5000,(uint)(ushort)segMatrix->rotScale[5]);
  setCopReg(2,0x5800,(uint)(ushort)segMatrix->rotScale[8]);
  segMatrix->rotScale[6] = (short)uVar8;
  segMatrix->rotScale[1] = (short)uVar6;
  copFunction(2,0x49e012);
  segMatrix->rotScale[4] = (short)uVar7;
  segMatrix->rotScale[7] = (short)uVar5;
  uVar6 = getCopReg(2,0x4800);
  uVar7 = getCopReg(2,0x5000);
  uVar5 = getCopReg(2,0x5800);
  segMatrix->rotScale[2] = (short)uVar6;
  segMatrix->rotScale[5] = (short)uVar7;
  segMatrix->rotScale[8] = (short)uVar5;
  setCopReg(2,in_zero,(&DAT_800d4f1c)[segIndex * 6]);
  setCopReg(2,in_at,*(undefined4 *)(&DAT_800d4f20 + segIndex * 0xc));
  copFunction(2,0x486012);
  lVar3 = getCopReg(2,0x19);
  (segMatrix->trans).x = lVar3;
  lVar3 = getCopReg(2,0x1a);
  (segMatrix->trans).y = lVar3;
  lVar3 = getCopReg(2,0x1b);
  (segMatrix->trans).z = lVar3;
  if (bRootTransUpdated != G2FALSE) {
    (parentMatrix->trans).x = (parentMatrix->trans).x + (segMatrix->trans).x;
    (parentMatrix->trans).y = (parentMatrix->trans).y + (segMatrix->trans).y;
    (parentMatrix->trans).z = (parentMatrix->trans).z + (segMatrix->trans).z;
    (segMatrix->trans).x = 0;
    (segMatrix->trans).y = 0;
    (segMatrix->trans).z = 0;
  }
  (segMatrix->trans).x = (segMatrix->trans).x + (parentMatrix->trans).x;
  (segMatrix->trans).y = (segMatrix->trans).y + (parentMatrix->trans).y;
  (segMatrix->trans).z = (segMatrix->trans).z + (parentMatrix->trans).z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_BuildSegLocalRotMatrix(struct _G2AnimSegValue_Type *segValue /*$v1*/, struct _G2Matrix_Type *segMatrix /*$a1*/)
 // line 2063, offset 0x80093c30
	/* begin block 1 */
		// Start line: 2064
		// Start offset: 0x80093C30
		// Variables:
	// 		struct _G2SVector3_Type rot; // stack offset -16

		/* begin block 1.1 */
			// Start line: 2070
			// Start offset: 0x80093C5C
			// Variables:
		// 		struct _G2SVector3_Type *source; // $v1
		// 		struct _G2SVector3_Type *dest; // $a0

			/* begin block 1.1.1 */
				// Start line: 2070
				// Start offset: 0x80093C5C
				// Variables:
			// 		unsigned long mask; // $a2
			// 		unsigned short z; // $v0
			// 		unsigned long xy; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80093C5C
			// End Line: 2070
		/* end block 1.1 */
		// End offset: 0x80093C5C
		// End Line: 2070
	/* end block 1 */
	// End offset: 0x80093C80
	// End Line: 2074

	/* begin block 2 */
		// Start line: 4616
	/* end block 2 */
	// End Line: 4617

/* File: C:\kain2\game\G2\ANIMG2.C */

void _G2Anim_BuildSegLocalRotMatrix(_G2AnimSegValue_Type *segValue,_G2Matrix_Type *segMatrix)

{
  uint local_10;
  ushort local_c;
  
  if (segValue->bIsQuat == 0) {
    local_c = *(ushort *)((int)&segValue->rotQuat + 4) & 0xfff;
    local_10 = *(uint *)&segValue->rotQuat & 0xfff0fff;
    RotMatrixZYX((SVECTOR *)&local_10,(MATRIX *)segMatrix);
  }
  else {
    G2Quat_ToMatrix_S((short *)segValue,(short *)segMatrix);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ wombat(unsigned char *segKeyList /*$a0*/, int flagBitOffset /*$a1*/, struct _G2AnimSegKeyflagInfo_Type *kfInfo /*$a2*/)
 // line 2113, offset 0x80093c90
	/* begin block 1 */
		// Start line: 2116
		// Start offset: 0x80093C90
		// Variables:
	// 		int flagDWordOffset; // $a3
	// 		int flagBitShift; // $a1
	/* end block 1 */
	// End offset: 0x80093C90
	// End Line: 2118

	/* begin block 2 */
		// Start line: 4716
	/* end block 2 */
	// End Line: 4717

	/* begin block 3 */
		// Start line: 4718
	/* end block 3 */
	// End Line: 4719

	/* begin block 4 */
		// Start line: 4720
	/* end block 4 */
	// End Line: 4721

/* File: C:\kain2\game\G2\ANIMG2.C */

void wombat(uchar *segKeyList,int flagBitOffset,_G2AnimSegKeyflagInfo_Type *kfInfo)

{
  uint uVar1;
  
  *(uchar **)&kfInfo->stream = segKeyList + (flagBitOffset >> 5) * 4;
  uVar1 = *(uint *)(segKeyList + (flagBitOffset >> 5) * 4);
  kfInfo->bitCount = 0x20 - (flagBitOffset & 0x1fU);
  kfInfo->flags = uVar1 >> (flagBitOffset & 0x1fU);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ kangaroo(struct _G2AnimSegKeyflagInfo_Type *kfInfo /*$a0*/)
 // line 2129, offset 0x80093cc8
	/* begin block 1 */
		// Start line: 2132
		// Start offset: 0x80093CC8
		// Variables:
	// 		unsigned long keyflags; // $a2
	// 		unsigned long tempFlags; // $v0
	/* end block 1 */
	// End offset: 0x80093D48
	// End Line: 2160

	/* begin block 2 */
		// Start line: 4758
	/* end block 2 */
	// End Line: 4759

	/* begin block 3 */
		// Start line: 4760
	/* end block 3 */
	// End Line: 4761

	/* begin block 4 */
		// Start line: 4763
	/* end block 4 */
	// End Line: 4764

/* File: C:\kain2\game\G2\ANIMG2.C */

ulong kangaroo(_G2AnimSegKeyflagInfo_Type *kfInfo)

{
  int iVar1;
  ulong *puVar2;
  uint uVar3;
  ulong uVar4;
  
  uVar4 = 0;
  if (kfInfo->stream != (ulong *)0x0) {
    uVar4 = kfInfo->flags & 7;
    iVar1 = kfInfo->bitCount + -3;
    kfInfo->flags = kfInfo->flags >> 3;
    kfInfo->bitCount = iVar1;
    if (iVar1 < 1) {
      puVar2 = kfInfo->stream;
      kfInfo->stream = puVar2 + 1;
      uVar3 = puVar2[1];
      iVar1 = kfInfo->bitCount;
      kfInfo->flags = uVar3;
      if (iVar1 < 0) {
        uVar4 = uVar4 | uVar3 << (iVar1 + 3U & 0x1f) & 7;
        kfInfo->flags = uVar3 >> (-iVar1 & 0x1fU);
      }
      kfInfo->bitCount = kfInfo->bitCount + 0x20;
    }
  }
  return uVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_InitializeSegValue(struct _G2Anim_Type *anim /*$a0*/, struct _G2AnimSegValue_Type *segValue /*$a1*/, int segIndex /*$a2*/)
 // line 2167, offset 0x80093d50
	/* begin block 1 */
		// Start line: 2170
		// Start offset: 0x80093D50
		// Variables:
	// 		struct _Segment *segment; // $v0

		/* begin block 1.1 */
			// Start line: 2170
			// Start offset: 0x80093D50
			// Variables:
		// 		struct _G2Quat_Type *quat; // $a1
		/* end block 1.1 */
		// End offset: 0x80093D50
		// End Line: 2170

		/* begin block 1.2 */
			// Start line: 2170
			// Start offset: 0x80093D50
		/* end block 1.2 */
		// End offset: 0x80093D50
		// End Line: 2170

		/* begin block 1.3 */
			// Start line: 2170
			// Start offset: 0x80093D50

			/* begin block 1.3.1 */
				// Start line: 2170
				// Start offset: 0x80093D50
				// Variables:
			// 		unsigned long zpad; // $v0
			// 		unsigned long xy; // $v1
			/* end block 1.3.1 */
			// End offset: 0x80093D50
			// End Line: 2170
		/* end block 1.3 */
		// End offset: 0x80093D50
		// End Line: 2170
	/* end block 1 */
	// End offset: 0x80093D50
	// End Line: 2170

	/* begin block 2 */
		// Start line: 4838
	/* end block 2 */
	// End Line: 4839

	/* begin block 3 */
		// Start line: 4840
	/* end block 3 */
	// End Line: 4841

/* File: C:\kain2\game\G2\ANIMG2.C */

void _G2Anim_InitializeSegValue(_G2Anim_Type *anim,_G2AnimSegValue_Type *segValue,int segIndex)

{
  _Segment *p_Var1;
  uint uVar2;
  
  *(undefined4 *)((int)&segValue->rotQuat + 4) = 0x10000000;
  *(undefined4 *)&segValue->scale = 0x10001000;
  *(undefined4 *)&segValue->rotQuat = 0;
  (segValue->scale).z = 0x1000;
  p_Var1 = anim->modelData->segmentList + segIndex;
  uVar2 = *(uint *)&p_Var1->pz;
  *(undefined4 *)&segValue->trans = *(undefined4 *)&p_Var1->px;
  *(uint *)&(segValue->trans).z = uVar2 & 0xffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimSection_InitStatus(struct _G2AnimSection_Type *section /*$s7*/, struct _G2Anim_Type *anim /*stack 4*/)
 // line 2224, offset 0x80093da4
	/* begin block 1 */
		// Start line: 2225
		// Start offset: 0x80093DA4
		// Variables:
	// 		struct _G2AnimDecompressChannelInfo_Type dcInfo; // stack offset -104
	// 		struct _G2AnimSegValue_Type *segValue; // $s6
	// 		struct _G2AnimChanStatusBlock_Type **chanStatusNextBlockPtr; // $s5
	// 		struct _G2AnimChanStatusBlock_Type *chanStatusBlock; // $v0
	// 		struct _G2AnimChanStatus_Type *chanStatus; // $s2
	// 		int chanStatusChunkCount; // $s3
	// 		struct _G2AnimSegKeyflagInfo_Type rotKfInfo; // stack offset -88
	// 		struct _G2AnimSegKeyflagInfo_Type scaleKfInfo; // stack offset -72
	// 		struct _G2AnimSegKeyflagInfo_Type transKfInfo; // stack offset -56
	// 		int type; // $s0
	// 		unsigned long segChanFlags; // $s1
	// 		int segIndex; // $s4
	// 		int lastSeg; // $fp

		/* begin block 1.1 */
			// Start line: 2225
			// Start offset: 0x80093DA4
			// Variables:
		// 		struct _G2Anim_Type *anim; // stack offset 4
		// 		struct _G2AnimSection_Type *section; // $s7

			/* begin block 1.1.1 */
				// Start line: 2225
				// Start offset: 0x80093DA4
				// Variables:
			// 		int bitsPerFlagType; // $s2
			// 		int flagBitOffset; // $s0
			// 		unsigned long activeChanBits; // $s3
			// 		unsigned char *segKeyList; // $s1
			/* end block 1.1.1 */
			// End offset: 0x80093E78
			// End Line: 2225
		/* end block 1.1 */
		// End offset: 0x80093E78
		// End Line: 2225
	/* end block 1 */
	// End offset: 0x80094010
	// End Line: 2336

	/* begin block 2 */
		// Start line: 4952
	/* end block 2 */
	// End Line: 4953

/* File: C:\kain2\game\G2\ANIMG2.C */

void _G2AnimSection_InitStatus(_G2AnimSection_Type *section,_G2Anim_Type *anim)

{
  _func_7 **pp_Var1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  byte bVar5;
  int flagBitOffset;
  _func_7 ***segKeyList;
  uint uVar6;
  uint segIndex;
  _G2AnimChanStatus_Type *status;
  _G2AnimChanStatusBlock_Type *p_Var7;
  _G2AnimChanStatusBlock_Type *p_Var8;
  _G2AnimSegValue_Type *segValue;
  uint uVar9;
  _G2AnimDecompressChannelInfo_Type local_68;
  _G2AnimSegKeyflagInfo_Type local_58;
  _G2AnimSegKeyflagInfo_Type local_48;
  _G2AnimSegKeyflagInfo_Type local_38;
  
  flagBitOffset = (uint)section->firstSeg * 3 + 8;
  segKeyList = &section->keylist->sectionData + section->keylist->sectionCount;
  bVar5 = *(byte *)segKeyList;
  segIndex = anim->modelData->numSegments * 3 + 7U & 0xfffffff8;
  local_58.stream = (ulong *)0x0;
  local_48.stream = (ulong *)0x0;
  local_38.stream = (ulong *)0x0;
  if ((bVar5 & 1) != 0) {
    wombat((uchar *)segKeyList,flagBitOffset,&local_58);
    flagBitOffset = flagBitOffset + segIndex;
  }
  if ((bVar5 & 2) != 0) {
    wombat((uchar *)segKeyList,flagBitOffset,&local_48);
    flagBitOffset = flagBitOffset + segIndex;
  }
  if ((bVar5 & 4) != 0) {
    wombat((uchar *)segKeyList,flagBitOffset,&local_38);
  }
  status = (_G2AnimChanStatus_Type *)0x0;
  _G2Anim_FreeChanStatusBlockList(section->chanStatusBlockList);
  flagBitOffset = 0;
  local_68.keylist = section->keylist;
  section->chanStatusBlockList = (_G2AnimChanStatusBlock_Type *)0x0;
  local_68.chanData = (&section->keylist->sectionData)[section->sectionID];
  segIndex = (uint)section->firstSeg;
  segValue = (_G2AnimSegValue_Type *)(&_segValues + segIndex * 0x18);
  uVar9 = segIndex + section->segCount;
  p_Var8 = (_G2AnimChanStatusBlock_Type *)&section->chanStatusBlockList;
  if (segIndex < uVar9) {
    do {
      uVar2 = kangaroo(&local_58);
      uVar3 = kangaroo(&local_48);
      uVar4 = kangaroo(&local_38);
      uVar6 = uVar2 | uVar3 << 4 | uVar4 << 8;
      _G2Anim_InitializeSegValue(anim,segValue,segIndex);
      while (uVar6 != 0) {
        pp_Var1 = local_68.chanData;
        if ((uVar2 & 1) != 0) {
          bVar5 = *(byte *)((int)local_68.chanData + 1) & 0xe0;
          if (bVar5 == 0xe0) {
            bVar5 = 0;
          }
          if (bVar5 == 0) {
            pp_Var1 = (_func_7 **)((int)local_68.chanData + (uint)(local_68.keylist)->keyCount * 2);
          }
          else {
            pp_Var1 = local_68.chanData + 1;
            if (bVar5 != 0x20) {
              p_Var7 = p_Var8;
              if (flagBitOffset == 0) {
                flagBitOffset = 8;
                p_Var7 = (_G2AnimChanStatusBlock_Type *)G2PoolMem_Allocate(&_chanStatusBlockPool);
                p_Var7->next = (_G2AnimChanStatusBlock_Type *)0x0;
                p_Var8->next = p_Var7;
                status = p_Var7->chunks;
              }
              if (bVar5 == 0x40) {
                _G2Anim_InitializeChannel_AdaptiveDelta(&local_68,status);
              }
              else {
                if (bVar5 == 0x60) {
                  _G2Anim_InitializeChannel_Linear(&local_68,status);
                }
              }
              status = status + 1;
              flagBitOffset = flagBitOffset + -1;
              p_Var8 = p_Var7;
              pp_Var1 = local_68.chanData;
            }
          }
        }
        local_68.chanData = pp_Var1;
        uVar6 = uVar6 >> 1;
        uVar2 = uVar6;
      }
      segIndex = segIndex + 1;
      segValue = segValue + 1;
    } while ((int)segIndex < (int)uVar9);
  }
  section->storedTime = -section->keylist->timePerKey;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FooBar(struct _G2AnimSection_Type *section /*$s6*/, struct _G2Anim_Type *anim /*stack 4*/, int decompressedKey /*$s4*/, int targetKey /*stack 12*/, long timeOffset /*stack 16*/)
 // line 2346, offset 0x80094058
	/* begin block 1 */
		// Start line: 2347
		// Start offset: 0x80094058
		// Variables:
	// 		struct _G2AnimDecompressChannelInfo_Type dcInfo; // stack offset -152
	// 		struct _G2AnimSegValue_Type *segValue; // $s6
	// 		short *chanValue; // $s1
	// 		struct _G2AnimChanStatusBlock_Type *chanStatusBlock; // $s7
	// 		struct _G2AnimChanStatus_Type *chanStatus; // $s3
	// 		int chanStatusChunkCount; // $s5
	// 		struct _G2AnimSegKeyflagInfo_Type rotKfInfo; // stack offset -136
	// 		struct _G2AnimSegKeyflagInfo_Type scaleKfInfo; // stack offset -120
	// 		struct _G2AnimSegKeyflagInfo_Type transKfInfo; // stack offset -104
	// 		int type; // $s0
	// 		unsigned long segChanFlags; // $s2
	// 		int segIndex; // $s4
	// 		int lastSeg; // stack offset -48
	// 		struct _G2AnimDecompressChannelInfo_Type nextDCInfo; // stack offset -88
	// 		struct _G2AnimDecompressChannelInfo_Type initDCInfo; // stack offset -72
	// 		struct _G2AnimChanStatus_Type nextChanStatus; // stack offset -56

		/* begin block 1.1 */
			// Start line: 2347
			// Start offset: 0x80094058
			// Variables:
		// 		struct _G2Anim_Type *anim; // stack offset 4
		// 		struct _G2AnimSection_Type *section; // $s6

			/* begin block 1.1.1 */
				// Start line: 2347
				// Start offset: 0x80094058
				// Variables:
			// 		int bitsPerFlagType; // $s2
			// 		int flagBitOffset; // $s0
			// 		unsigned long activeChanBits; // $s3
			// 		unsigned char *segKeyList; // $s1
			/* end block 1.1.1 */
			// End offset: 0x80094138
			// End Line: 2347
		/* end block 1.1 */
		// End offset: 0x80094138
		// End Line: 2347
	/* end block 1 */
	// End offset: 0x800944B4
	// End Line: 2508

	/* begin block 2 */
		// Start line: 5213
	/* end block 2 */
	// End Line: 5214

/* File: C:\kain2\game\G2\ANIMG2.C */

void FooBar(_G2AnimSection_Type *section,_G2Anim_Type *anim,int decompressedKey,int targetKey,
           long timeOffset)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  _func_7 **pp_Var5;
  uint uVar6;
  byte bVar7;
  int flagBitOffset;
  _func_7 ***segKeyList;
  _G2AnimSegValue_Type *p_Var8;
  uint segIndex;
  uint uVar9;
  _G2AnimChanStatus_Type *status;
  _G2AnimSegValue_Type *segValue;
  _G2AnimChanStatusBlock_Type *p_Var10;
  _G2AnimDecompressChannelInfo_Type local_98;
  _G2AnimSegKeyflagInfo_Type local_88;
  _G2AnimSegKeyflagInfo_Type local_78;
  _G2AnimSegKeyflagInfo_Type local_68;
  _G2AnimDecompressChannelInfo_Type local_58;
  _G2AnimDecompressChannelInfo_Type local_48;
  _G2AnimChanStatus_Type local_38 [2];
  uint local_30;
  
  flagBitOffset = (uint)section->firstSeg * 3 + 8;
  segKeyList = &section->keylist->sectionData + section->keylist->sectionCount;
  bVar7 = *(byte *)segKeyList;
  segIndex = anim->modelData->numSegments * 3 + 7U & 0xfffffff8;
  local_88.stream = (ulong *)0x0;
  local_78.stream = (ulong *)0x0;
  local_68.stream = (ulong *)0x0;
  if ((bVar7 & 1) != 0) {
    wombat((uchar *)segKeyList,flagBitOffset,&local_88);
    flagBitOffset = flagBitOffset + segIndex;
  }
  if ((bVar7 & 2) != 0) {
    wombat((uchar *)segKeyList,flagBitOffset,&local_78);
    flagBitOffset = flagBitOffset + segIndex;
  }
  if ((bVar7 & 4) != 0) {
    wombat((uchar *)segKeyList,flagBitOffset,&local_68);
  }
  p_Var10 = section->chanStatusBlockList;
  local_98.keylist = section->keylist;
  flagBitOffset = 8;
  local_98.chanData = (&section->keylist->sectionData)[section->sectionID];
  status = p_Var10->chunks;
  if ((timeOffset != 0) &&
     (local_58.targetKey = targetKey + 1, local_58.keylist = local_98.keylist,
     local_58.chanData = local_98.chanData, local_58.storedKey = targetKey,
     (int)(uint)section->keylist->keyCount <= local_58.targetKey)) {
    if ((section->flags & 2) == 0) {
      timeOffset = 0;
    }
    else {
      local_58.storedKey = -1;
      local_58.targetKey = 0;
      local_48.keylist = local_98.keylist;
      local_48.chanData = local_98.chanData;
    }
  }
  segIndex = (uint)section->firstSeg;
  segValue = (_G2AnimSegValue_Type *)(&_segValues + segIndex * 0x18);
  local_30 = segIndex + section->segCount;
  local_98.storedKey = decompressedKey;
  local_98.targetKey = targetKey;
  if (segIndex < local_30) {
    do {
      _G2Anim_InitializeSegValue(anim,segValue,segIndex);
      uVar2 = kangaroo(&local_88);
      uVar3 = kangaroo(&local_78);
      uVar4 = kangaroo(&local_68);
      uVar9 = uVar2 | uVar3 << 4 | uVar4 << 8;
      p_Var8 = segValue;
      while (uVar9 != 0) {
        if ((uVar9 & 1) != 0) {
          bVar7 = *(byte *)((int)local_98.chanData + 1) & 0xe0;
          if (bVar7 == 0xe0) {
            bVar7 = 0;
          }
          if (bVar7 == 0) {
            *(undefined2 *)&p_Var8->rotQuat =
                 *(undefined2 *)((int)local_98.chanData + targetKey * 2);
            local_98.chanData =
                 (_func_7 **)((int)local_98.chanData + (uint)(local_98.keylist)->keyCount * 2);
          }
          else {
            if (bVar7 == 0x20) {
              *(undefined2 *)&p_Var8->rotQuat = *(undefined2 *)((int)local_98.chanData + 2);
              local_98.chanData = local_98.chanData + 1;
            }
            else {
              if (bVar7 == 0x40) {
                _G2Anim_DecompressChannel_AdaptiveDelta(&local_98,status);
              }
              else {
                if (bVar7 == 0x60) {
                  _G2Anim_DecompressChannel_Linear(&local_98,status);
                }
              }
              flagBitOffset = flagBitOffset + -1;
              *(short *)&p_Var8->rotQuat = status->keyData;
              local_38[0] = *status;
              status = status + 1;
              if (flagBitOffset == 0) {
                p_Var10 = p_Var10->next;
                flagBitOffset = 8;
                status = p_Var10->chunks;
              }
            }
          }
          if (timeOffset != 0) {
            if (bVar7 == 0x40) {
              if (local_58.storedKey == -1) {
                _G2Anim_InitializeChannel_AdaptiveDelta(&local_48,local_38);
              }
              _G2Anim_DecompressChannel_AdaptiveDelta(&local_58,local_38);
            }
            else {
              if (bVar7 < 0x41) {
                if (bVar7 == 0) {
                  pp_Var5 = (_func_7 **)((int)local_58.chanData + local_58.targetKey * 2);
                  local_58.chanData = local_98.chanData;
                  local_48.chanData = local_98.chanData;
                  local_38[0] = (_G2AnimChanStatus_Type)
                                ((uint)local_38[0] & 0xffff0000 | (uint)*(ushort *)pp_Var5);
                }
                else {
                  if (bVar7 == 0x20) {
                    local_38[0] = (_G2AnimChanStatus_Type)
                                  ((uint)local_38[0] & 0xffff0000 |
                                  (uint)*(ushort *)&p_Var8->rotQuat);
                    local_58.chanData = local_98.chanData;
                    local_48.chanData = local_98.chanData;
                  }
                }
              }
              else {
                if (bVar7 == 0x60) {
                  if (local_58.storedKey == -1) {
                    _G2Anim_InitializeChannel_Linear(&local_48,local_38);
                  }
                  _G2Anim_DecompressChannel_Linear(&local_58,local_38);
                }
              }
            }
            uVar6 = ((uint)local_38[0] & 0xffff) - (uint)*(ushort *)&p_Var8->rotQuat;
            uVar1 = uVar6 & 0xffff;
            if (0x7ff < (int)(uVar6 * 0x10000) >> 0x10) {
              uVar1 = (uint)(ushort)((short)uVar6 - 0x1000);
            }
            local_38[0].keyData = (short)uVar1;
            if (local_38[0].keyData < -0x7ff) {
              uVar1 = (uint)(ushort)(local_38[0].keyData + 0x1000);
            }
            local_38[0] = (_G2AnimChanStatus_Type)((uint)local_38[0] & 0xffff0000 | uVar1);
            if (segIndex != 0) {
              local_38[0].keyData = (short)uVar1;
              *(short *)&p_Var8->rotQuat =
                   *(short *)&p_Var8->rotQuat + (short)(local_38[0].keyData * timeOffset >> 0xc);
            }
          }
        }
        uVar9 = uVar9 >> 1;
        p_Var8 = (_G2AnimSegValue_Type *)((int)&p_Var8->rotQuat + 2);
      }
      segIndex = segIndex + 1;
      segValue = segValue + 1;
    } while ((int)segIndex < (int)local_30);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimSection_UpdateStoredFrameFromData(struct _G2AnimSection_Type *section /*$s0*/, struct _G2Anim_Type *anim /*$s3*/)
 // line 2513, offset 0x800944e4
	/* begin block 1 */
		// Start line: 2514
		// Start offset: 0x800944E4
		// Variables:
	// 		short timePerKey; // $s2
	// 		long storedKey; // $a2
	// 		long targetKey; // $s1
	// 		long timeOffset; // $v0
	/* end block 1 */
	// End offset: 0x8009454C
	// End Line: 2546

	/* begin block 2 */
		// Start line: 5585
	/* end block 2 */
	// End Line: 5586

/* File: C:\kain2\game\G2\ANIMG2.C */

void _G2AnimSection_UpdateStoredFrameFromData(_G2AnimSection_Type *section,_G2Anim_Type *anim)

{
  short sVar1;
  int targetKey;
  int iVar2;
  int decompressedKey;
  
  targetKey = (int)section->keylist->timePerKey;
  decompressedKey = (int)section->storedTime / targetKey;
  sVar1 = section->keylist->timePerKey;
  targetKey = (int)section->elapsedTime / targetKey;
  if ((decompressedKey < 0) || (targetKey < decompressedKey)) {
    _G2AnimSection_InitStatus(section,anim);
    decompressedKey = -1;
  }
  iVar2 = (int)sVar1;
  FooBar(section,anim,decompressedKey,targetKey,
         (((int)section->elapsedTime - targetKey * iVar2) * 0x1000) / iVar2);
  section->storedTime = section->elapsedTime;
  section->flags = section->flags | 0x80;
  return;
}



// decompiled code
// original method signature: 
// struct _G2Anim_Type * /*$ra*/ _G2AnimSection_GetAnim(struct _G2AnimSection_Type *section /*$a0*/)
 // line 2557, offset 0x800945b4
	/* begin block 1 */
		// Start line: 2560
		// Start offset: 0x800945B4
	/* end block 1 */
	// End offset: 0x800945B4
	// End Line: 2564

	/* begin block 2 */
		// Start line: 5694
	/* end block 2 */
	// End Line: 5695

	/* begin block 3 */
		// Start line: 5696
	/* end block 3 */
	// End Line: 5697

	/* begin block 4 */
		// Start line: 5700
	/* end block 4 */
	// End Line: 5701

/* File: C:\kain2\game\G2\ANIMG2.C */

_G2Anim_Type * _G2AnimSection_GetAnim(_G2AnimSection_Type *section)

{
  return (_G2Anim_Type *)((int)section - ((uint)section->sectionID * 0x30 + 0x24));
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimSection_TriggerEffects(struct _G2AnimSection_Type *section /*$s1*/, short startTime /*$a1*/, short endTime /*$a2*/)
 // line 2576, offset 0x800945d4
	/* begin block 1 */
		// Start line: 2577
		// Start offset: 0x800945D4
		// Variables:
	// 		struct _G2AnimKeylist_Type *keylist; // $s4
	// 		struct _G2AnimFxHeader_Type *fxHeader; // $s0
	// 		int fxSectionID; // $a0
	// 		unsigned long fxSize; // $s2
	/* end block 1 */
	// End offset: 0x800946DC
	// End Line: 2617

	/* begin block 2 */
		// Start line: 5732
	/* end block 2 */
	// End Line: 5733

/* File: C:\kain2\game\G2\ANIMG2.C */

void _G2AnimSection_TriggerEffects(_G2AnimSection_Type *section,short startTime,short endTime)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  _G2AnimFxHeader_Type *p_Var4;
  _G2Anim_Type *p_Var5;
  _G2AnimKeylist_Type *p_Var6;
  
  p_Var6 = section->keylist;
  p_Var4 = p_Var6->fxList;
  if (p_Var4 != (_G2AnimFxHeader_Type *)0x0) {
    cVar1 = p_Var4->type;
    while (cVar1 != -1) {
      bVar2 = p_Var4->sizeAndSection;
      if (((((uint)bVar2 & 0xf) == (uint)section->sectionID) &&
          (((sVar3 = p_Var4->keyframeID * (ushort)p_Var6->s0TailTime, startTime < sVar3 ||
            ((sVar3 == 0 && (startTime <= sVar3)))) && (sVar3 <= endTime)))) &&
         (section->callback != (_func_8 *)0x0)) {
        p_Var5 = _G2AnimSection_GetAnim(section);
        (*section->callback)
                  (p_Var5,(uint)section->sectionID,6,(int)p_Var4->type,p_Var4 + 1,
                   section->callbackData);
      }
      p_Var4 = (_G2AnimFxHeader_Type *)(&p_Var4->sizeAndSection + (((uint)bVar2 & 0xf0) >> 2));
      cVar1 = p_Var4->type;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_FreeChanStatusBlockList(struct _G2AnimChanStatusBlock_Type *block /*$a1*/)
 // line 2621, offset 0x80094700
	/* begin block 1 */
		// Start line: 2622
		// Start offset: 0x80094700
		// Variables:
	// 		struct _G2AnimChanStatusBlock_Type *nextBlock; // $s0
	/* end block 1 */
	// End offset: 0x80094734
	// End Line: 2633

	/* begin block 2 */
		// Start line: 5825
	/* end block 2 */
	// End Line: 5826

/* File: C:\kain2\game\G2\ANIMG2.C */

void _G2Anim_FreeChanStatusBlockList(_G2AnimChanStatusBlock_Type *block)

{
  _G2AnimChanStatusBlock_Type *p_Var1;
  
  if (block != (_G2AnimChanStatusBlock_Type *)0x0) {
    do {
      p_Var1 = block->next;
      G2PoolMem_Free(&_chanStatusBlockPool,block);
      block = p_Var1;
    } while (p_Var1 != (_G2AnimChanStatusBlock_Type *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ _G2AnimAlphaTable_GetValue(struct _G2AnimAlphaTable_Type *table /*$a2*/, long trueAlpha /*$v0*/)
 // line 2638, offset 0x80094744
	/* begin block 1 */
		// Start line: 2639
		// Start offset: 0x80094744
		// Variables:
	// 		long position; // $a0
	// 		long positionInt; // $v1
	// 		long positionFrac; // $a0
	// 		long value; // $a1
	/* end block 1 */
	// End offset: 0x800947A0
	// End Line: 2657

	/* begin block 2 */
		// Start line: 5859
	/* end block 2 */
	// End Line: 5860

/* File: C:\kain2\game\G2\ANIMG2.C */

long _G2AnimAlphaTable_GetValue(_G2AnimAlphaTable_Type *table,long trueAlpha)

{
  int iVar1;
  uint uVar2;
  
  if (table != (_G2AnimAlphaTable_Type *)0x0) {
    uVar2 = ((uint)table->size - 1) * trueAlpha;
    iVar1 = (int)uVar2 >> 0xc;
    return (int)table[iVar1 + 1] +
           ((int)(((int)table[iVar1 + 2] - (int)table[iVar1 + 1]) * (uVar2 & 0xfff)) >> 0xc);
  }
  return trueAlpha;
}





