#include "THISDUST.H"
#include "ANMG2ILF.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_DisableSegment(struct _G2Anim_Type *anim /*$a0*/, int segmentID /*$a1*/)
 // line 57, offset 0x8008f308
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x8008F308
		// Variables:
	// 		unsigned long segmentIndex; // $v0
	// 		unsigned long segmentMask; // $v1
	/* end block 1 */
	// End offset: 0x8008F308
	// End Line: 64

	/* begin block 2 */
		// Start line: 64
	/* end block 2 */
	// End Line: 65

	/* begin block 3 */
		// Start line: 107
	/* end block 3 */
	// End Line: 108

	/* begin block 4 */
		// Start line: 66
	/* end block 4 */
	// End Line: 67

	/* begin block 5 */
		// Start line: 70
	/* end block 5 */
	// End Line: 71

void G2Anim_DisableSegment(_G2Anim_Type *anim,int segmentID)

{
  *(uint *)(&anim->sectionCount + (segmentID >> 5) * 4 + 0x18) =
       *(uint *)(&anim->sectionCount + (segmentID >> 5) * 4 + 0x18) | 1 << (segmentID & 0x1fU);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_EnableSegment(struct _G2Anim_Type *anim /*$a0*/, int segmentID /*$a1*/)
 // line 82, offset 0x8008f330
	/* begin block 1 */
		// Start line: 85
		// Start offset: 0x8008F330
		// Variables:
	// 		unsigned long segmentIndex; // $v0
	// 		unsigned long segmentMask; // $v1
	/* end block 1 */
	// End offset: 0x8008F330
	// End Line: 89

	/* begin block 2 */
		// Start line: 157
	/* end block 2 */
	// End Line: 158

	/* begin block 3 */
		// Start line: 103
	/* end block 3 */
	// End Line: 104

	/* begin block 4 */
		// Start line: 107
	/* end block 4 */
	// End Line: 108

void G2Anim_EnableSegment(_G2Anim_Type *anim,int segmentID)

{
  *(uint *)(&anim->sectionCount + (segmentID >> 5) * 4 + 0x18) =
       *(uint *)(&anim->sectionCount + (segmentID >> 5) * 4 + 0x18) & ~(1 << (segmentID & 0x1fU));
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ G2Anim_GetElapsedTime(struct _G2Anim_Type *anim /*$a0*/)
 // line 97, offset 0x8008f35c
	/* begin block 1 */
		// Start line: 100
		// Start offset: 0x8008F35C
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $v0
	/* end block 1 */
	// End offset: 0x8008F35C
	// End Line: 104

	/* begin block 2 */
		// Start line: 131
	/* end block 2 */
	// End Line: 132

	/* begin block 3 */
		// Start line: 133
	/* end block 3 */
	// End Line: 134

	/* begin block 4 */
		// Start line: 137
	/* end block 4 */
	// End Line: 138

short G2Anim_GetElapsedTime(_G2Anim_Type *anim)

{
  return anim->section[anim->masterSection].elapsedTime;
}



// decompiled code
// original method signature: 
// struct _G2AnimKeylist_Type * /*$ra*/ G2Anim_GetKeylist(struct _G2Anim_Type *anim /*$a0*/)
 // line 136, offset 0x8008f380
	/* begin block 1 */
		// Start line: 139
		// Start offset: 0x8008F380
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $v0
	/* end block 1 */
	// End offset: 0x8008F380
	// End Line: 143

	/* begin block 2 */
		// Start line: 260
	/* end block 2 */
	// End Line: 261

	/* begin block 3 */
		// Start line: 180
	/* end block 3 */
	// End Line: 181

	/* begin block 4 */
		// Start line: 184
	/* end block 4 */
	// End Line: 185

_G2AnimKeylist_Type * G2Anim_GetKeylist(_G2Anim_Type *anim)

{
  return anim->section[anim->masterSection].keylist;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_GetRootMotionOverInterval(struct _G2Anim_Type *anim /*$a0*/, short intervalStart /*$a1*/, short intervalEnd /*$a2*/, struct _G2SVector3_Type *motionVector /*$a3*/)
 // line 165, offset 0x8008f3a4
	/* begin block 1 */
		// Start line: 166
		// Start offset: 0x8008F3A4
	/* end block 1 */
	// End offset: 0x8008F3A4
	// End Line: 166

	/* begin block 2 */
		// Start line: 310
	/* end block 2 */
	// End Line: 311

void G2Anim_GetRootMotionOverInterval
               (_G2Anim_Type *anim,short intervalStart,short intervalEnd,
               _G2SVector3_Type *motionVector)

{
  G2Anim_GetRootMotionFromTimeForDuration
            (anim,intervalStart,
             (short)(((uint)(ushort)intervalEnd - (uint)(ushort)intervalStart) * 0x10000 >> 0x10),
             motionVector);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_InterpToKeylistFrame(struct _G2Anim_Type *anim /*$s2*/, struct _G2AnimKeylist_Type *keylist /*$s4*/, int keylistID /*$s5*/, int targetFrame /*$s6*/, int duration /*stack 16*/)
 // line 292, offset 0x8008f3d4
	/* begin block 1 */
		// Start line: 293
		// Start offset: 0x8008F3D4
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008F450
	// End Line: 307

	/* begin block 2 */
		// Start line: 575
	/* end block 2 */
	// End Line: 576

void G2Anim_InterpToKeylistFrame
               (_G2Anim_Type *anim,_G2AnimKeylist_Type *keylist,int keylistID,int targetFrame,
               int duration)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      G2AnimSection_InterpToKeylistFrame
                ((_G2AnimSection_Type *)(&anim->sectionCount + iVar2),keylist,keylistID,targetFrame,
                 (int)(short)duration);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// enum _G2Bool_Enum /*$ra*/ G2Anim_IsSegmentEnabled(struct _G2Anim_Type *anim /*$a0*/, int segmentID /*$a1*/)
 // line 350, offset 0x8008f478
	/* begin block 1 */
		// Start line: 352
		// Start offset: 0x8008F478
		// Variables:
	// 		unsigned long segmentIndex; // $v0
	// 		unsigned long segmentMask; // $v1
	/* end block 1 */
	// End offset: 0x8008F4D8
	// End Line: 366

	/* begin block 2 */
		// Start line: 696
	/* end block 2 */
	// End Line: 697

	/* begin block 3 */
		// Start line: 453
	/* end block 3 */
	// End Line: 454

	/* begin block 4 */
		// Start line: 455
	/* end block 4 */
	// End Line: 456

_G2Bool_Enum G2Anim_IsSegmentEnabled(_G2Anim_Type *anim,int segmentID)

{
  int iVar1;
  
  if (segmentID != -1) {
    iVar1 = segmentID >> 5;
    do {
      if ((anim->disabledBits[iVar1] & 1 << (segmentID & 0x1fU)) != 0) {
        return G2FALSE;
      }
      segmentID = (int)anim->modelData->segmentList[segmentID].parent;
      iVar1 = segmentID >> 5;
    } while (segmentID != 0xffffffff);
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetAlphaTable(struct _G2Anim_Type *anim /*$s2*/, struct _G2AnimAlphaTable_Type *table /*$s3*/)
 // line 412, offset 0x8008f4e0
	/* begin block 1 */
		// Start line: 413
		// Start offset: 0x8008F4E0
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008F534
	// End Line: 422

	/* begin block 2 */
		// Start line: 818
	/* end block 2 */
	// End Line: 819

void G2Anim_SetAlphaTable(_G2Anim_Type *anim,_G2AnimAlphaTable_Type *table)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      G2AnimSection_SetAlphaTable((_G2AnimSection_Type *)(&anim->sectionCount + iVar2),table);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetCallback(struct _G2Anim_Type *anim /*$a0*/, TDRFuncPtr_G2Anim_SetCallback1callback callback /*$a1*/, void *data /*$a2*/)
 // line 428, offset 0x8008f550
	/* begin block 1 */
		// Start line: 431
		// Start offset: 0x8008F550
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8008F584
	// End Line: 439

	/* begin block 2 */
		// Start line: 565
	/* end block 2 */
	// End Line: 566

	/* begin block 3 */
		// Start line: 567
	/* end block 3 */
	// End Line: 568

	/* begin block 4 */
		// Start line: 572
	/* end block 4 */
	// End Line: 573

void G2Anim_SetCallback(_G2Anim_Type *anim,TDRFuncPtr_G2Anim_SetCallback1callback callback,
                       void *data)

{
  int iVar1;
  _G2Anim_Type *p_Var2;
  
  iVar1 = 0;
  p_Var2 = anim;
  if (anim->sectionCount != '\0') {
    do {
      *(TDRFuncPtr_G2Anim_SetCallback1callback *)&p_Var2->section[0].callback = callback;
      p_Var2->section[0].callbackData = data;
      iVar1 = iVar1 + 1;
      p_Var2 = (_G2Anim_Type *)&p_Var2->section[0].swAlarmTable;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetLooping(struct _G2Anim_Type *anim /*$s2*/)
 // line 518, offset 0x8008f58c
	/* begin block 1 */
		// Start line: 519
		// Start offset: 0x8008F58C
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008F5D4
	// End Line: 527

	/* begin block 2 */
		// Start line: 1031
	/* end block 2 */
	// End Line: 1032

void G2Anim_SetLooping(_G2Anim_Type *anim)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      G2AnimSection_SetLooping((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetNoLooping(struct _G2Anim_Type *anim /*$s2*/)
 // line 565, offset 0x8008f5ec
	/* begin block 1 */
		// Start line: 566
		// Start offset: 0x8008F5EC
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008F634
	// End Line: 574

	/* begin block 2 */
		// Start line: 1125
	/* end block 2 */
	// End Line: 1126

void G2Anim_SetNoLooping(_G2Anim_Type *anim)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      G2AnimSection_SetNoLooping((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetPaused(struct _G2Anim_Type *anim /*$s2*/)
 // line 591, offset 0x8008f64c
	/* begin block 1 */
		// Start line: 592
		// Start offset: 0x8008F64C
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008F694
	// End Line: 600

	/* begin block 2 */
		// Start line: 1177
	/* end block 2 */
	// End Line: 1178

void G2Anim_SetPaused(_G2Anim_Type *anim)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      G2AnimSection_SetPaused((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetSpeedAdjustment(struct _G2Anim_Type *anim /*$a0*/, long adjustment /*$a1*/)
 // line 618, offset 0x8008f6ac
	/* begin block 1 */
		// Start line: 621
		// Start offset: 0x8008F6AC
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8008F6D8
	// End Line: 629

	/* begin block 2 */
		// Start line: 1230
	/* end block 2 */
	// End Line: 1231

	/* begin block 3 */
		// Start line: 795
	/* end block 3 */
	// End Line: 796

	/* begin block 4 */
		// Start line: 800
	/* end block 4 */
	// End Line: 801

void G2Anim_SetSpeedAdjustment(_G2Anim_Type *anim,long adjustment)

{
  int iVar1;
  _G2Anim_Type *p_Var2;
  
  iVar1 = 0;
  p_Var2 = anim;
  if (anim->sectionCount != '\0') {
    do {
      p_Var2->section[0].speedAdjustment = adjustment;
      iVar1 = iVar1 + 1;
      p_Var2 = (_G2Anim_Type *)&p_Var2->section[0].swAlarmTable;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetUnpaused(struct _G2Anim_Type *anim /*$s2*/)
 // line 649, offset 0x8008f6e0
	/* begin block 1 */
		// Start line: 650
		// Start offset: 0x8008F6E0
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008F728
	// End Line: 658

	/* begin block 2 */
		// Start line: 1292
	/* end block 2 */
	// End Line: 1293

void G2Anim_SetUnpaused(_G2Anim_Type *anim)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      G2AnimSection_SetUnpaused((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SwitchToKeylist(struct _G2Anim_Type *anim /*$s2*/, struct _G2AnimKeylist_Type *keylist /*$s3*/, int keylistID /*$s4*/)
 // line 678, offset 0x8008f740
	/* begin block 1 */
		// Start line: 679
		// Start offset: 0x8008F740
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008F7A0
	// End Line: 689

	/* begin block 2 */
		// Start line: 1348
	/* end block 2 */
	// End Line: 1349

void G2Anim_SwitchToKeylist(_G2Anim_Type *anim,_G2AnimKeylist_Type *keylist,int keylistID)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (anim->sectionCount != '\0') {
    iVar2 = 0x24;
    do {
      G2AnimSection_SwitchToKeylist
                ((_G2AnimSection_Type *)(&anim->sectionCount + iVar2),keylist,keylistID);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(uint)anim->sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ G2AnimKeylist_GetDuration(struct _G2AnimKeylist_Type *keylist /*$a0*/)
 // line 797, offset 0x8008f7c0
	/* begin block 1 */
		// Start line: 1585
	/* end block 1 */
	// End Line: 1586

	/* begin block 2 */
		// Start line: 1007
	/* end block 2 */
	// End Line: 1008

short G2AnimKeylist_GetDuration(_G2AnimKeylist_Type *keylist)

{
  return (short)(((uint)keylist->s0TailTime +
                 (int)keylist->timePerKey * ((uint)keylist->keyCount - 1)) * 0x10000 >> 0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2AnimKeylist_GetKeyframeCount(struct _G2AnimKeylist_Type *keylist /*$a0*/)
 // line 811, offset 0x8008f7e8
	/* begin block 1 */
		// Start line: 1031
	/* end block 1 */
	// End Line: 1032

	/* begin block 2 */
		// Start line: 1034
	/* end block 2 */
	// End Line: 1035

int G2AnimKeylist_GetKeyframeCount(_G2AnimKeylist_Type *keylist)

{
  return (int)((int)keylist->timePerKey * ((uint)keylist->keyCount - 1) + -1 +
              (uint)keylist->s0TailTime * 2) / (int)(uint)keylist->s0TailTime;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_ClearAlarm(struct _G2AnimSection_Type *section /*$a0*/, unsigned long flag /*$a1*/)
 // line 840, offset 0x8008f820
	/* begin block 1 */
		// Start line: 1089
	/* end block 1 */
	// End Line: 1090

	/* begin block 2 */
		// Start line: 1094
	/* end block 2 */
	// End Line: 1095

void G2AnimSection_ClearAlarm(_G2AnimSection_Type *section,ulong flag)

{
  section->alarmFlags = section->alarmFlags & ~flag;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2AnimSection_GetKeyframeNumber(struct _G2AnimSection_Type *section /*$s0*/)
 // line 870, offset 0x8008f834
	/* begin block 1 */
		// Start line: 1715
	/* end block 1 */
	// End Line: 1716

int G2AnimSection_GetKeyframeNumber(_G2AnimSection_Type *section)

{
  byte bVar1;
  short sVar2;
  _G2Bool_Enum _Var3;
  
  _Var3 = G2AnimSection_IsInInterpolation(section);
  if (_Var3 == G2FALSE) {
    sVar2 = section->elapsedTime;
    bVar1 = section->keylist->s0TailTime;
  }
  else {
    sVar2 = section->interpInfo->targetTime;
    bVar1 = section->keylist->s0TailTime;
  }
  return (int)sVar2 / (int)(uint)bVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2AnimSection_GetStoredKeyframeNumber(struct _G2AnimSection_Type *section /*$a0*/)
 // line 974, offset 0x8008f890
	/* begin block 1 */
		// Start line: 1246
	/* end block 1 */
	// End Line: 1247

	/* begin block 2 */
		// Start line: 1337
	/* end block 2 */
	// End Line: 1338

	/* begin block 3 */
		// Start line: 1342
	/* end block 3 */
	// End Line: 1343

int G2AnimSection_GetStoredKeyframeNumber(_G2AnimSection_Type *section)

{
  return (int)section->storedTime / (int)(uint)section->keylist->s0TailTime;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_InterpToKeylistFrame(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimKeylist_Type *keylist /*$a1*/, int keylistID /*$a2*/, int targetFrame /*$a3*/, int duration /*stack 16*/)
 // line 1005, offset 0x8008f8b0
	/* begin block 1 */
		// Start line: 1006
		// Start offset: 0x8008F8B0
	/* end block 1 */
	// End offset: 0x8008F8B0
	// End Line: 1006

	/* begin block 2 */
		// Start line: 1999
	/* end block 2 */
	// End Line: 2000

void G2AnimSection_InterpToKeylistFrame
               (_G2AnimSection_Type *section,_G2AnimKeylist_Type *keylist,int keylistID,
               int targetFrame,int duration)

{
  G2AnimSection_InterpToKeylistAtTime
            (section,keylist,keylistID,(short)targetFrame * (ushort)keylist->s0TailTime,
             (int)(short)duration);
  return;
}



// decompiled code
// original method signature: 
// enum _G2Bool_Enum /*$ra*/ G2AnimSection_IsInInterpolation(struct _G2AnimSection_Type *section /*$a0*/)
 // line 1023, offset 0x8008f8f0
	/* begin block 1 */
		// Start line: 1026
		// Start offset: 0x8008F8F0
		// Variables:
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $v0
	/* end block 1 */
	// End offset: 0x8008F918
	// End Line: 1035

	/* begin block 2 */
		// Start line: 1409
	/* end block 2 */
	// End Line: 1410

	/* begin block 3 */
		// Start line: 1411
	/* end block 3 */
	// End Line: 1412

	/* begin block 4 */
		// Start line: 1415
	/* end block 4 */
	// End Line: 1416

_G2Bool_Enum G2AnimSection_IsInInterpolation(_G2AnimSection_Type *section)

{
  if ((section->interpInfo != (_G2AnimInterpInfo_Type *)0x0) &&
     (section->interpInfo->stateBlockList != (_G2AnimInterpStateBlock_Type *)0x0)) {
    return 1;
  }
  return G2FALSE;
}



// decompiled code
// original method signature: 
// short /*$ra*/ G2AnimSection_NextKeyframe(struct _G2AnimSection_Type *section /*$s0*/)
 // line 1081, offset 0x8008f920
	/* begin block 1 */
		// Start line: 1525
	/* end block 1 */
	// End Line: 1526

short G2AnimSection_NextKeyframe(_G2AnimSection_Type *section)

{
  short interval;
  
  interval = 0;
  if ((section->flags & 1) == 0) {
    G2AnimSection_SetNotRewinding(section);
    interval = G2Timer_GetFrameTime();
    interval = G2AnimSection_UpdateOverInterval(section,interval);
  }
  return interval;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetAlphaTable(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimAlphaTable_Type *table /*$a1*/)
 // line 1112, offset 0x8008f97c
	/* begin block 1 */
		// Start line: 2203
	/* end block 1 */
	// End Line: 2204

	/* begin block 2 */
		// Start line: 1566
	/* end block 2 */
	// End Line: 1567

void G2AnimSection_SetAlphaTable(_G2AnimSection_Type *section,_G2AnimAlphaTable_Type *table)

{
  if (section->interpInfo != (_G2AnimInterpInfo_Type *)0x0) {
    section->interpInfo->alphaTable = table;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetInterpInfo(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimInterpInfo_Type *newInfoPtr /*$a1*/)
 // line 1162, offset 0x8008f998
	/* begin block 1 */
		// Start line: 1662
	/* end block 1 */
	// End Line: 1663

void G2AnimSection_SetInterpInfo(_G2AnimSection_Type *section,_G2AnimInterpInfo_Type *newInfoPtr)

{
  section->interpInfo = newInfoPtr;
  if (newInfoPtr != (_G2AnimInterpInfo_Type *)0x0) {
    memset(newInfoPtr,0,0xc);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetLooping(struct _G2AnimSection_Type *section /*$s0*/)
 // line 1208, offset 0x8008f9c8
	/* begin block 1 */
		// Start line: 2387
	/* end block 1 */
	// End Line: 2388

void G2AnimSection_SetLooping(_G2AnimSection_Type *section)

{
  G2AnimSection_ClearAlarm(section,3);
  G2AnimSection_SetLoopRangeAll(section);
  section->flags = section->flags | 2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetLoopRangeAll(struct _G2AnimSection_Type *section /*$s0*/)
 // line 1220, offset 0x8008fa08
	/* begin block 1 */
		// Start line: 1740
	/* end block 1 */
	// End Line: 1741

void G2AnimSection_SetLoopRangeAll(_G2AnimSection_Type *section)

{
  short sVar1;
  
  section->loopStartTime = 0;
  sVar1 = G2AnimKeylist_GetDuration(section->keylist);
  section->loopEndTime = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetNoLooping(struct _G2AnimSection_Type *section /*$a0*/)
 // line 1261, offset 0x8008fa38
	/* begin block 1 */
		// Start line: 2503
	/* end block 1 */
	// End Line: 2504

	/* begin block 2 */
		// Start line: 1789
	/* end block 2 */
	// End Line: 1790

void G2AnimSection_SetNoLooping(_G2AnimSection_Type *section)

{
  section->flags = section->flags & 0xfd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetNotRewinding(struct _G2AnimSection_Type *section /*$a0*/)
 // line 1270, offset 0x8008fa4c
	/* begin block 1 */
		// Start line: 1804
	/* end block 1 */
	// End Line: 1805

	/* begin block 2 */
		// Start line: 1807
	/* end block 2 */
	// End Line: 1808

void G2AnimSection_SetNotRewinding(_G2AnimSection_Type *section)

{
  section->flags = section->flags & 0xfb;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetPaused(struct _G2AnimSection_Type *section /*$a0*/)
 // line 1279, offset 0x8008fa60
	/* begin block 1 */
		// Start line: 1822
	/* end block 1 */
	// End Line: 1823

	/* begin block 2 */
		// Start line: 1825
	/* end block 2 */
	// End Line: 1826

void G2AnimSection_SetPaused(_G2AnimSection_Type *section)

{
  section->flags = section->flags | 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetUnpaused(struct _G2AnimSection_Type *section /*$a0*/)
 // line 1333, offset 0x8008fa74
	/* begin block 1 */
		// Start line: 2605
	/* end block 1 */
	// End Line: 2606

	/* begin block 2 */
		// Start line: 1882
	/* end block 2 */
	// End Line: 1883

void G2AnimSection_SetUnpaused(_G2AnimSection_Type *section)

{
  section->flags = section->flags & 0xfe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SwitchToKeylist(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimKeylist_Type *keylist /*$a1*/, int keylistID /*$a2*/)
 // line 1344, offset 0x8008fa88
	/* begin block 1 */
		// Start line: 1901
	/* end block 1 */
	// End Line: 1902

void G2AnimSection_SwitchToKeylist
               (_G2AnimSection_Type *section,_G2AnimKeylist_Type *keylist,int keylistID)

{
  G2AnimSection_SwitchToKeylistAtTime(section,keylist,keylistID,0);
  return;
}





