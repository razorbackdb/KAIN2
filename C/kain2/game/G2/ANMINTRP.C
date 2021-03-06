#include "THISDUST.H"
#include "ANMINTRP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_InterpToKeylistAtTime(struct _G2AnimSection_Type *section /*$s1*/, struct _G2AnimKeylist_Type *keylist /*$s7*/, int keylistID /*$fp*/, short targetTime /*stack -48*/, int duration /*stack 16*/)
 // line 49, offset 0x8009221c
	/* begin block 1 */
		// Start line: 50
		// Start offset: 0x8009221C
		// Variables:
	// 		struct _G2Anim_Type *anim; // $s5
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $s3
	// 		struct _G2AnimInterpStateBlock_Type *stateBlockList; // $t0
	// 		struct _G2AnimQuatInfo_Type *quatInfo; // $a2
	// 		unsigned long alarmFlags; // $s0
	// 		short elapsedTime; // $s4
	// 		int quatInfoChunkCount; // $a3
	// 		int segCount; // $s2
	/* end block 1 */
	// End offset: 0x800924D0
	// End Line: 183

	/* begin block 2 */
		// Start line: 98
	/* end block 2 */
	// End Line: 99

void G2AnimSection_InterpToKeylistAtTime
               (_G2AnimSection_Type *section,_G2AnimKeylist_Type *keylist,int keylistID,
               short targetTime,int duration)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  _G2Anim_Type *anim;
  _G2AnimQuatInfo_Type *p_Var4;
  int iVar5;
  _G2AnimInterpStateBlock_Type *p_Var6;
  ulong uVar7;
  uint uVar8;
  _G2AnimInterpInfo_Type *p_Var9;
  short sVar10;
  short sVar11;
  
  if ((duration & 0xffffU) == 0) {
LAB_800922b4:
    G2AnimSection_SwitchToKeylistAtTime(section,keylist,keylistID,targetTime);
  }
  else {
    anim = _G2AnimSection_GetAnim(section);
    p_Var9 = section->interpInfo;
    bVar1 = section->segCount;
    uVar8 = (uint)bVar1;
    if (p_Var9->stateBlockList == (_G2AnimInterpStateBlock_Type *)0x0) {
      p_Var6 = _G2Anim_AllocateInterpStateBlockList(section);
      if (p_Var6 == (_G2AnimInterpStateBlock_Type *)0x0) goto LAB_800922b4;
      section->interpInfo = (_G2AnimInterpInfo_Type *)0x0;
      _G2AnimSection_UpdateStoredFrameFromData(section,anim);
      section->interpInfo = p_Var9;
      _G2AnimSection_SegValueToQuat(section,0);
    }
    else {
      _G2AnimSection_InterpStateToQuat(section);
    }
    sVar10 = section->elapsedTime;
    uVar7 = section->alarmFlags;
    section->interpInfo = (_G2AnimInterpInfo_Type *)0x0;
    G2AnimSection_SwitchToKeylistAtTime(section,keylist,keylistID,targetTime);
    _G2AnimSection_UpdateStoredFrameFromData(section,anim);
    section->interpInfo = p_Var9;
    section->alarmFlags = uVar7;
    section->elapsedTime = sVar10;
    _G2AnimSection_SegValueToQuat(section,1);
    p_Var6 = p_Var9->stateBlockList;
    iVar5 = 4;
    p_Var4 = p_Var6->quatInfo;
    if ((ushort)(p_Var6->quatInfo[0].destTrans.z |
                p_Var6->quatInfo[0].destTrans.x | p_Var6->quatInfo[0].destTrans.y) == 0) {
      p_Var6->quatInfo[0].srcTrans.x = 0;
      p_Var6->quatInfo[0].srcTrans.y = 0;
      p_Var6->quatInfo[0].srcTrans.z = 0;
    }
    if (bVar1 != 0) {
      do {
        uVar8 = uVar8 - 1;
        iVar5 = iVar5 + -1;
        sVar11 = (p_Var4->srcScale).y;
        (p_Var4->destScale).x = (p_Var4->destScale).x - (p_Var4->srcScale).x;
        sVar2 = (p_Var4->srcScale).z;
        (p_Var4->destScale).y = (p_Var4->destScale).y - sVar11;
        sVar11 = (p_Var4->destTrans).x;
        sVar3 = (p_Var4->srcTrans).x;
        (p_Var4->destScale).z = (p_Var4->destScale).z - sVar2;
        sVar2 = (p_Var4->srcTrans).y;
        (p_Var4->destTrans).x = sVar11 - sVar3;
        sVar11 = (p_Var4->srcTrans).z;
        (p_Var4->destTrans).y = (p_Var4->destTrans).y - sVar2;
        (p_Var4->destTrans).z = (p_Var4->destTrans).z - sVar11;
        p_Var4 = p_Var4 + 1;
        if (iVar5 == 0) {
          p_Var6 = p_Var6->next;
          iVar5 = 4;
          p_Var4 = p_Var6->quatInfo;
        }
      } while (0 < (int)uVar8);
    }
    p_Var9->targetTime = targetTime;
    sVar11 = (short)duration;
    p_Var9->duration = sVar11;
    if (((section->flags & 2) == 0) && ((section->alarmFlags & 3) != 0)) {
      iVar5 = (int)sVar10 % (uint)section->keylist->s0TailTime + 1;
      sVar10 = (short)iVar5;
      if (sVar11 < iVar5) {
        sVar10 = sVar11;
      }
      section->elapsedTime = sVar10;
    }
    else {
      section->elapsedTime = 0;
    }
    section->keylist = keylist;
    section->keylistID = (ushort)keylistID;
    section->storedTime = -keylist->timePerKey;
    if ((section->flags & 2) != 0) {
      G2AnimSection_SetLoopRangeAll(section);
    }
    G2AnimSection_ClearAlarm(section,3);
    section->flags = section->flags & 0x7f;
    G2AnimSection_SetUnpaused(section);
    section->swAlarmTable = (short *)0x0;
    section->interpInfo = p_Var9;
    anim->flags = anim->flags | 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimSection_UpdateStoredFrameFromQuat(struct _G2AnimSection_Type *section /*$s7*/)
 // line 193, offset 0x80092500
	/* begin block 1 */
		// Start line: 194
		// Start offset: 0x80092500
		// Variables:
	// 		struct _G2AnimSegValue_Type *segValue; // $s1
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $s0
	// 		struct _G2AnimInterpStateBlock_Type *stateBlockList; // $s3
	// 		struct _G2AnimQuatInfo_Type *quatInfo; // $s0
	// 		long alpha; // $s5
	// 		struct _G2Quat_Type newQuat; // stack offset -48
	// 		int quatInfoChunkCount; // $s4
	// 		int segCount; // $s6

		/* begin block 1.1 */
			// Start line: 223
			// Start offset: 0x8009258C
			// Variables:
		// 		struct _G2Quat_Type *source; // $fp
		// 		struct _G2Quat_Type *dest; // $s1

			/* begin block 1.1.1 */
				// Start line: 223
				// Start offset: 0x8009258C
				// Variables:
			// 		unsigned long zw; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8009258C
			// End Line: 223
		/* end block 1.1 */
		// End offset: 0x8009258C
		// End Line: 223

		/* begin block 1.2 */
			// Start line: 223
			// Start offset: 0x8009258C
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $a0
		// 		struct _G2SVector3_Type *base; // $v0
		// 		struct _G2SVector3_Type *offset; // $v1
		// 		long alpha; // $s5
		/* end block 1.2 */
		// End offset: 0x8009258C
		// End Line: 223

		/* begin block 1.3 */
			// Start line: 223
			// Start offset: 0x8009258C
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $a0
		// 		struct _G2SVector3_Type *base; // $v0
		// 		struct _G2SVector3_Type *offset; // $v1
		// 		long alpha; // $s5
		/* end block 1.3 */
		// End offset: 0x8009258C
		// End Line: 223
	/* end block 1 */
	// End offset: 0x800926AC
	// End Line: 252

	/* begin block 2 */
		// Start line: 434
	/* end block 2 */
	// End Line: 435

void _G2AnimSection_UpdateStoredFrameFromQuat(_G2AnimSection_Type *section)

{
  byte bVar1;
  long ratio;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  _G2AnimInterpInfo_Type *p_Var5;
  _G2AnimQuatInfo_Type *quatA;
  _G2AnimSegValue_Type *p_Var6;
  ushort *puVar7;
  _G2AnimInterpStateBlock_Type *p_Var8;
  int iVar9;
  uint uVar10;
  undefined4 local_30;
  undefined4 local_2c;
  
  p_Var5 = section->interpInfo;
  iVar9 = 4;
  bVar1 = section->segCount;
  uVar10 = (uint)bVar1;
  ratio = _G2AnimAlphaTable_GetValue
                    (p_Var5->alphaTable,((int)section->elapsedTime << 0xc) / (int)p_Var5->duration);
  p_Var8 = p_Var5->stateBlockList;
  p_Var6 = &_segValues + section->firstSeg;
  quatA = p_Var8->quatInfo;
  if (bVar1 != 0) {
    puVar7 = &(&_segValues)[section->firstSeg].bIsQuat;
    do {
      G2Quat_Slerp_VM(ratio,(_G2Quat_Type *)quatA,&quatA->destQuat,(_G2Quat_Type *)&local_30,0);
      *(undefined4 *)&p_Var6->rotQuat = local_30;
      *(undefined4 *)(puVar7 + -9) = local_2c;
      setCopReg(2,0xc800,(uint)(ushort)(quatA->srcScale).x);
      setCopReg(2,0xd000,(uint)(ushort)(quatA->srcScale).y);
      setCopReg(2,0xd800,(uint)(ushort)(quatA->srcScale).z);
      setCopReg(2,0x4800,(uint)(ushort)(quatA->destScale).x);
      setCopReg(2,0x5000,(uint)(ushort)(quatA->destScale).y);
      setCopReg(2,0x5800,(uint)(ushort)(quatA->destScale).z);
      setCopReg(2,0x4000,ratio);
      copFunction(2,0x1a8003e);
      uVar2 = getCopReg(2,0xc800);
      uVar3 = getCopReg(2,0xd000);
      uVar4 = getCopReg(2,0xd800);
      (p_Var6->scale).x = (short)uVar2;
      (p_Var6->scale).y = (short)uVar3;
      (p_Var6->scale).z = (short)uVar4;
      setCopReg(2,0xc800,(uint)(ushort)(quatA->srcTrans).x);
      setCopReg(2,0xd000,(uint)(ushort)(quatA->srcTrans).y);
      setCopReg(2,0xd800,(uint)(ushort)(quatA->srcTrans).z);
      setCopReg(2,0x4800,(uint)(ushort)(quatA->destTrans).x);
      setCopReg(2,0x5000,(uint)(ushort)(quatA->destTrans).y);
      setCopReg(2,0x5800,(uint)(ushort)(quatA->destTrans).z);
      setCopReg(2,0x4000,ratio);
      copFunction(2,0x1a8003e);
      uVar2 = getCopReg(2,0xc800);
      uVar3 = getCopReg(2,0xd000);
      uVar4 = getCopReg(2,0xd800);
      (p_Var6->trans).x = (short)uVar2;
      (p_Var6->trans).y = (short)uVar3;
      (p_Var6->trans).z = (short)uVar4;
      uVar10 = uVar10 - 1;
      iVar9 = iVar9 + -1;
      quatA = quatA + 1;
      if (iVar9 == 0) {
        p_Var8 = p_Var8->next;
        iVar9 = 4;
        quatA = p_Var8->quatInfo;
      }
      *puVar7 = 1;
      puVar7 = puVar7 + 0xc;
      p_Var6 = p_Var6 + 1;
    } while (0 < (int)uVar10);
  }
  section->storedTime = section->elapsedTime;
  section->flags = section->flags | 0x80;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimSection_InterpStateToQuat(struct _G2AnimSection_Type *section /*$a0*/)
 // line 258, offset 0x800926f0
	/* begin block 1 */
		// Start line: 259
		// Start offset: 0x800926F0
		// Variables:
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $s0
	// 		struct _G2AnimInterpStateBlock_Type *stateBlockList; // $s3
	// 		struct _G2AnimQuatInfo_Type *quatInfo; // $s0
	// 		long alpha; // $s1
	// 		struct _G2Quat_Type newQuat; // stack offset -40
	// 		int quatInfoChunkCount; // $s2
	// 		int segCount; // $s4

		/* begin block 1.1 */
			// Start line: 288
			// Start offset: 0x80092750
			// Variables:
		// 		struct _G2Quat_Type *source; // $s5
		// 		struct _G2Quat_Type *dest; // $s0

			/* begin block 1.1.1 */
				// Start line: 288
				// Start offset: 0x80092750
				// Variables:
			// 		unsigned long zw; // $v1
			// 		unsigned long xy; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80092750
			// End Line: 288
		/* end block 1.1 */
		// End offset: 0x80092750
		// End Line: 288

		/* begin block 1.2 */
			// Start line: 288
			// Start offset: 0x80092750
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $v1
		// 		struct _G2SVector3_Type *offset; // $v0
		// 		long alpha; // $s1
		/* end block 1.2 */
		// End offset: 0x80092750
		// End Line: 288

		/* begin block 1.3 */
			// Start line: 288
			// Start offset: 0x80092750
			// Variables:
		// 		struct _G2SVector3_Type *dest; // $v1
		// 		struct _G2SVector3_Type *offset; // $v0
		// 		long alpha; // $s1
		/* end block 1.3 */
		// End offset: 0x80092750
		// End Line: 288
	/* end block 1 */
	// End offset: 0x8009285C
	// End Line: 313

	/* begin block 2 */
		// Start line: 582
	/* end block 2 */
	// End Line: 583

void _G2AnimSection_InterpStateToQuat(_G2AnimSection_Type *section)

{
  byte bVar1;
  long ratio;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  _G2AnimInterpInfo_Type *p_Var5;
  _G2AnimQuatInfo_Type *quatA;
  int iVar6;
  _G2AnimInterpStateBlock_Type *p_Var7;
  uint uVar8;
  undefined4 local_28;
  undefined4 local_24;
  
  p_Var5 = section->interpInfo;
  iVar6 = 4;
  bVar1 = section->segCount;
  uVar8 = (uint)bVar1;
  ratio = _G2AnimAlphaTable_GetValue
                    (p_Var5->alphaTable,((int)section->elapsedTime << 0xc) / (int)p_Var5->duration);
  p_Var7 = p_Var5->stateBlockList;
  quatA = p_Var7->quatInfo;
  if (bVar1 != 0) {
    do {
      G2Quat_Slerp_VM(ratio,(_G2Quat_Type *)quatA,&quatA->destQuat,(_G2Quat_Type *)&local_28,0);
      *(undefined4 *)&(quatA->srcQuat).z = local_24;
      *(undefined4 *)&quatA->srcQuat = local_28;
      setCopReg(2,0xc800,(uint)(ushort)(quatA->srcScale).x);
      setCopReg(2,0xd000,(uint)(ushort)(quatA->srcScale).y);
      setCopReg(2,0xd800,(uint)(ushort)(quatA->srcScale).z);
      setCopReg(2,0x4800,(uint)(ushort)(quatA->destScale).x);
      setCopReg(2,0x5000,(uint)(ushort)(quatA->destScale).y);
      setCopReg(2,0x5800,(uint)(ushort)(quatA->destScale).z);
      setCopReg(2,0x4000,ratio);
      copFunction(2,0x1a8003e);
      uVar2 = getCopReg(2,0xc800);
      uVar3 = getCopReg(2,0xd000);
      uVar4 = getCopReg(2,0xd800);
      (quatA->srcScale).x = (short)uVar2;
      (quatA->srcScale).y = (short)uVar3;
      (quatA->srcScale).z = (short)uVar4;
      setCopReg(2,0xc800,(uint)(ushort)(quatA->srcTrans).x);
      setCopReg(2,0xd000,(uint)(ushort)(quatA->srcTrans).y);
      setCopReg(2,0xd800,(uint)(ushort)(quatA->srcTrans).z);
      setCopReg(2,0x4800,(uint)(ushort)(quatA->destTrans).x);
      setCopReg(2,0x5000,(uint)(ushort)(quatA->destTrans).y);
      setCopReg(2,0x5800,(uint)(ushort)(quatA->destTrans).z);
      setCopReg(2,0x4000,ratio);
      copFunction(2,0x1a8003e);
      uVar2 = getCopReg(2,0xc800);
      uVar3 = getCopReg(2,0xd000);
      uVar4 = getCopReg(2,0xd800);
      (quatA->srcTrans).x = (short)uVar2;
      (quatA->srcTrans).y = (short)uVar3;
      (quatA->srcTrans).z = (short)uVar4;
      uVar8 = uVar8 - 1;
      iVar6 = iVar6 + -1;
      quatA = quatA + 1;
      if (iVar6 == 0) {
        p_Var7 = p_Var7->next;
        iVar6 = 4;
        quatA = p_Var7->quatInfo;
      }
    } while (0 < (int)uVar8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2AnimSection_SegValueToQuat(struct _G2AnimSection_Type *section /*$a0*/, int zeroOne /*$s6*/)
 // line 318, offset 0x80092880
	/* begin block 1 */
		// Start line: 319
		// Start offset: 0x80092880
		// Variables:
	// 		struct _G2AnimSegValue_Type *segValue; // $s2
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $v0
	// 		struct _G2AnimInterpStateBlock_Type *stateBlockList; // $s4
	// 		struct _G2AnimQuatInfo_Type *quatInfo; // $s0
	// 		struct _G2EulerAngles_Type preQuat; // stack offset -40
	// 		int quatInfoChunkCount; // $s3
	// 		int segCount; // $s5
	/* end block 1 */
	// End offset: 0x800929E4
	// End Line: 384

	/* begin block 2 */
		// Start line: 716
	/* end block 2 */
	// End Line: 717

void _G2AnimSection_SegValueToQuat(_G2AnimSection_Type *section,int zeroOne)

{
  _G2AnimQuatInfo_Type *p_Var1;
  short *psVar2;
  _G2AnimSegValue_Type *p_Var3;
  int iVar4;
  _G2AnimInterpStateBlock_Type *p_Var5;
  uint uVar6;
  ushort local_28;
  ushort local_26;
  ushort local_24;
  undefined2 local_22;
  
  iVar4 = 4;
  uVar6 = (uint)section->segCount;
  p_Var5 = section->interpInfo->stateBlockList;
  p_Var3 = &_segValues + section->firstSeg;
  p_Var1 = p_Var5->quatInfo;
  if (section->segCount != 0) {
    psVar2 = &(&_segValues)[section->firstSeg].trans.z;
    do {
      local_28 = *(ushort *)&p_Var3->rotQuat & 0xfff;
      local_26 = psVar2[-9] & 0xfff;
      local_22 = 0;
      local_24 = psVar2[-8] & 0xfff;
      if (zeroOne == 0) {
        G2Quat_FromEuler_S((int)p_Var1,(short *)&local_28);
        (p_Var1->srcScale).x = psVar2[-6];
        (p_Var1->srcScale).y = psVar2[-5];
        (p_Var1->srcScale).z = psVar2[-4];
        (p_Var1->srcTrans).x = psVar2[-2];
        (p_Var1->srcTrans).y = psVar2[-1];
        (p_Var1->srcTrans).z = *psVar2;
      }
      else {
        G2Quat_FromEuler_S((int)&p_Var1->destQuat,(short *)&local_28);
        (p_Var1->destScale).x = psVar2[-6];
        (p_Var1->destScale).y = psVar2[-5];
        (p_Var1->destScale).z = psVar2[-4];
        (p_Var1->destTrans).x = psVar2[-2];
        (p_Var1->destTrans).y = psVar2[-1];
        (p_Var1->destTrans).z = *psVar2;
      }
      psVar2 = psVar2 + 0xc;
      p_Var3 = p_Var3 + 1;
      uVar6 = uVar6 - 1;
      iVar4 = iVar4 + -1;
      p_Var1 = p_Var1 + 1;
      if (iVar4 == 0) {
        p_Var5 = p_Var5->next;
        iVar4 = 4;
        p_Var1 = p_Var5->quatInfo;
      }
    } while (0 < (int)uVar6);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _G2AnimInterpStateBlock_Type * /*$ra*/ _G2Anim_AllocateInterpStateBlockList(struct _G2AnimSection_Type *section /*$v0*/)
 // line 388, offset 0x80092a0c
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x80092A0C
		// Variables:
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $s2
	// 		struct _G2AnimInterpStateBlock_Type *newBlock; // $s1
	// 		int segCount; // $s0
	/* end block 1 */
	// End offset: 0x80092A8C
	// End Line: 425

	/* begin block 2 */
		// Start line: 891
	/* end block 2 */
	// End Line: 892

_G2AnimInterpStateBlock_Type * _G2Anim_AllocateInterpStateBlockList(_G2AnimSection_Type *section)

{
  _G2AnimInterpStateBlock_Type *p_Var1;
  _G2AnimInterpStateBlock_Type *p_Var2;
  uint uVar3;
  _G2AnimInterpInfo_Type *p_Var4;
  
  uVar3 = (uint)section->segCount;
  p_Var4 = section->interpInfo;
  p_Var2 = (_G2AnimInterpStateBlock_Type *)G2PoolMem_Allocate(&_interpStateBlockPool);
  p_Var4->stateBlockList = p_Var2;
  if (p_Var2 == (_G2AnimInterpStateBlock_Type *)0x0) {
LAB_80092a88:
    p_Var2 = p_Var4->stateBlockList;
  }
  else {
    do {
      uVar3 = uVar3 - 4;
      if ((int)uVar3 < 1) {
        p_Var2->next = (_G2AnimInterpStateBlock_Type *)0x0;
        goto LAB_80092a88;
      }
      p_Var1 = (_G2AnimInterpStateBlock_Type *)G2PoolMem_Allocate(&_interpStateBlockPool);
      p_Var2->next = p_Var1;
      p_Var2 = p_Var1;
    } while (p_Var1 != (_G2AnimInterpStateBlock_Type *)0x0);
    _G2Anim_FreeInterpStateBlockList(p_Var4->stateBlockList);
    p_Var2 = (_G2AnimInterpStateBlock_Type *)0x0;
    p_Var4->stateBlockList = (_G2AnimInterpStateBlock_Type *)0x0;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _G2Anim_FreeInterpStateBlockList(struct _G2AnimInterpStateBlock_Type *block /*$a1*/)
 // line 429, offset 0x80092aa4
	/* begin block 1 */
		// Start line: 430
		// Start offset: 0x80092AA4
		// Variables:
	// 		struct _G2AnimInterpStateBlock_Type *nextBlock; // $s0
	/* end block 1 */
	// End offset: 0x80092AD4
	// End Line: 441

	/* begin block 2 */
		// Start line: 985
	/* end block 2 */
	// End Line: 986

void _G2Anim_FreeInterpStateBlockList(_G2AnimInterpStateBlock_Type *block)

{
  _G2AnimInterpStateBlock_Type *p_Var1;
  
  if (block != (_G2AnimInterpStateBlock_Type *)0x0) {
    do {
      p_Var1 = block->next;
      G2PoolMem_Free(&_interpStateBlockPool,block);
      block = p_Var1;
    } while (p_Var1 != (_G2AnimInterpStateBlock_Type *)0x0);
  }
  return;
}





