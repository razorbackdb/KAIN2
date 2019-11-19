#include "THISDUST.H"
#include "ANMG2ILF.H"


// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_DisableSegment(struct _G2Anim_Type *anim /*$a0*/, int segmentID /*$a1*/)
 // line 57, offset 0x8008d80c
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x8008D80C
		// Variables:
	// 		unsigned long segmentIndex; // $v0
	// 		unsigned long segmentMask; // $v1
	/* end block 1 */
	// End offset: 0x8008D80C
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
 // line 82, offset 0x8008d834
	/* begin block 1 */
		// Start line: 85
		// Start offset: 0x8008D834
		// Variables:
	// 		unsigned long segmentIndex; // $v0
	// 		unsigned long segmentMask; // $v1
	/* end block 1 */
	// End offset: 0x8008D834
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
 // line 97, offset 0x8008d860
	/* begin block 1 */
		// Start line: 100
		// Start offset: 0x8008D860
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $v0
	/* end block 1 */
	// End offset: 0x8008D860
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
 // line 136, offset 0x8008d884
	/* begin block 1 */
		// Start line: 139
		// Start offset: 0x8008D884
		// Variables:
	// 		struct _G2AnimSection_Type *section; // $v0
	/* end block 1 */
	// End offset: 0x8008D884
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
 // line 165, offset 0x8008d8a8
	/* begin block 1 */
		// Start line: 166
		// Start offset: 0x8008D8A8
	/* end block 1 */
	// End offset: 0x8008D8A8
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
 // line 292, offset 0x8008d8d8
	/* begin block 1 */
		// Start line: 293
		// Start offset: 0x8008D8D8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008D954
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
 // line 353, offset 0x8008d97c
	/* begin block 1 */
		// Start line: 356
		// Start offset: 0x8008D97C
		// Variables:
	// 		unsigned long segmentIndex; // $v0
	// 		unsigned long segmentMask; // $v1
	/* end block 1 */
	// End offset: 0x8008D97C
	// End Line: 360

	/* begin block 2 */
		// Start line: 699
	/* end block 2 */
	// End Line: 700

	/* begin block 3 */
		// Start line: 457
	/* end block 3 */
	// End Line: 458

	/* begin block 4 */
		// Start line: 461
	/* end block 4 */
	// End Line: 462

_G2Bool_Enum G2Anim_IsSegmentEnabled(_G2Anim_Type *anim,int segmentID)

{
  return (uint)((anim->disabledBits[segmentID >> 5] & 1 << (segmentID & 0x1fU)) == 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2Anim_SetAlphaTable(struct _G2Anim_Type *anim /*$s2*/, struct _G2AnimAlphaTable_Type *table /*$s3*/)
 // line 410, offset 0x8008d9a4
	/* begin block 1 */
		// Start line: 411
		// Start offset: 0x8008D9A4
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008D9F8
	// End Line: 420

	/* begin block 2 */
		// Start line: 814
	/* end block 2 */
	// End Line: 815

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
 // line 426, offset 0x8008da14
	/* begin block 1 */
		// Start line: 429
		// Start offset: 0x8008DA14
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8008DA48
	// End Line: 437

	/* begin block 2 */
		// Start line: 557
	/* end block 2 */
	// End Line: 558

	/* begin block 3 */
		// Start line: 559
	/* end block 3 */
	// End Line: 560

	/* begin block 4 */
		// Start line: 564
	/* end block 4 */
	// End Line: 565

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
 // line 516, offset 0x8008da50
	/* begin block 1 */
		// Start line: 517
		// Start offset: 0x8008DA50
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008DA98
	// End Line: 525

	/* begin block 2 */
		// Start line: 1027
	/* end block 2 */
	// End Line: 1028

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
 // line 563, offset 0x8008dab0
	/* begin block 1 */
		// Start line: 564
		// Start offset: 0x8008DAB0
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008DAF8
	// End Line: 572

	/* begin block 2 */
		// Start line: 1121
	/* end block 2 */
	// End Line: 1122

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
 // line 589, offset 0x8008db10
	/* begin block 1 */
		// Start line: 590
		// Start offset: 0x8008DB10
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008DB58
	// End Line: 598

	/* begin block 2 */
		// Start line: 1173
	/* end block 2 */
	// End Line: 1174

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
 // line 616, offset 0x8008db70
	/* begin block 1 */
		// Start line: 619
		// Start offset: 0x8008DB70
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x8008DB9C
	// End Line: 627

	/* begin block 2 */
		// Start line: 1226
	/* end block 2 */
	// End Line: 1227

	/* begin block 3 */
		// Start line: 787
	/* end block 3 */
	// End Line: 788

	/* begin block 4 */
		// Start line: 792
	/* end block 4 */
	// End Line: 793

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
 // line 647, offset 0x8008dba4
	/* begin block 1 */
		// Start line: 648
		// Start offset: 0x8008DBA4
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008DBEC
	// End Line: 656

	/* begin block 2 */
		// Start line: 1288
	/* end block 2 */
	// End Line: 1289

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
 // line 676, offset 0x8008dc04
	/* begin block 1 */
		// Start line: 677
		// Start offset: 0x8008DC04
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8008DC64
	// End Line: 687

	/* begin block 2 */
		// Start line: 1344
	/* end block 2 */
	// End Line: 1345

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
 // line 795, offset 0x8008dc84
	/* begin block 1 */
		// Start line: 1581
	/* end block 1 */
	// End Line: 1582

	/* begin block 2 */
		// Start line: 999
	/* end block 2 */
	// End Line: 1000

short G2AnimKeylist_GetDuration(_G2AnimKeylist_Type *keylist)

{
  return (short)(((uint)keylist->s0TailTime +
                 (int)keylist->timePerKey * ((uint)keylist->keyCount - 1)) * 0x10000 >> 0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2AnimKeylist_GetKeyframeCount(struct _G2AnimKeylist_Type *keylist /*$a0*/)
 // line 809, offset 0x8008dcac
	/* begin block 1 */
		// Start line: 1023
	/* end block 1 */
	// End Line: 1024

	/* begin block 2 */
		// Start line: 1026
	/* end block 2 */
	// End Line: 1027

int G2AnimKeylist_GetKeyframeCount(_G2AnimKeylist_Type *keylist)

{
  return (int)((int)keylist->timePerKey * ((uint)keylist->keyCount - 1) + -1 +
              (uint)keylist->s0TailTime * 2) / (int)(uint)keylist->s0TailTime;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_ClearAlarm(struct _G2AnimSection_Type *section /*$a0*/, unsigned long flag /*$a1*/)
 // line 838, offset 0x8008dce4
	/* begin block 1 */
		// Start line: 1081
	/* end block 1 */
	// End Line: 1082

	/* begin block 2 */
		// Start line: 1086
	/* end block 2 */
	// End Line: 1087

void G2AnimSection_ClearAlarm(_G2AnimSection_Type *section,ulong flag)

{
  section->alarmFlags = section->alarmFlags & ~flag;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2AnimSection_GetKeyframeNumber(struct _G2AnimSection_Type *section /*$s0*/)
 // line 868, offset 0x8008dcf8
	/* begin block 1 */
		// Start line: 1711
	/* end block 1 */
	// End Line: 1712

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
 // line 972, offset 0x8008dd54
	/* begin block 1 */
		// Start line: 1238
	/* end block 1 */
	// End Line: 1239

	/* begin block 2 */
		// Start line: 1329
	/* end block 2 */
	// End Line: 1330

	/* begin block 3 */
		// Start line: 1334
	/* end block 3 */
	// End Line: 1335

int G2AnimSection_GetStoredKeyframeNumber(_G2AnimSection_Type *section)

{
  return (int)section->storedTime / (int)(uint)section->keylist->s0TailTime;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_InterpToKeylistFrame(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimKeylist_Type *keylist /*$a1*/, int keylistID /*$a2*/, int targetFrame /*$a3*/, int duration /*stack 16*/)
 // line 1003, offset 0x8008dd74
	/* begin block 1 */
		// Start line: 1004
		// Start offset: 0x8008DD74
	/* end block 1 */
	// End offset: 0x8008DD74
	// End Line: 1004

	/* begin block 2 */
		// Start line: 1995
	/* end block 2 */
	// End Line: 1996

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
 // line 1021, offset 0x8008ddb4
	/* begin block 1 */
		// Start line: 1024
		// Start offset: 0x8008DDB4
		// Variables:
	// 		struct _G2AnimInterpInfo_Type *interpInfo; // $v0
	/* end block 1 */
	// End offset: 0x8008DDDC
	// End Line: 1033

	/* begin block 2 */
		// Start line: 1401
	/* end block 2 */
	// End Line: 1402

	/* begin block 3 */
		// Start line: 1403
	/* end block 3 */
	// End Line: 1404

	/* begin block 4 */
		// Start line: 1407
	/* end block 4 */
	// End Line: 1408

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
 // line 1079, offset 0x8008dde4
	/* begin block 1 */
		// Start line: 1517
	/* end block 1 */
	// End Line: 1518

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
 // line 1110, offset 0x8008de40
	/* begin block 1 */
		// Start line: 2199
	/* end block 1 */
	// End Line: 2200

	/* begin block 2 */
		// Start line: 1558
	/* end block 2 */
	// End Line: 1559

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
 // line 1160, offset 0x8008de5c
	/* begin block 1 */
		// Start line: 1654
	/* end block 1 */
	// End Line: 1655

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
 // line 1206, offset 0x8008de8c
	/* begin block 1 */
		// Start line: 2383
	/* end block 1 */
	// End Line: 2384

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
 // line 1218, offset 0x8008decc
	/* begin block 1 */
		// Start line: 1732
	/* end block 1 */
	// End Line: 1733

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
 // line 1259, offset 0x8008defc
	/* begin block 1 */
		// Start line: 2499
	/* end block 1 */
	// End Line: 2500

	/* begin block 2 */
		// Start line: 1781
	/* end block 2 */
	// End Line: 1782

void G2AnimSection_SetNoLooping(_G2AnimSection_Type *section)

{
  section->flags = section->flags & 0xfd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetNotRewinding(struct _G2AnimSection_Type *section /*$a0*/)
 // line 1268, offset 0x8008df10
	/* begin block 1 */
		// Start line: 1796
	/* end block 1 */
	// End Line: 1797

	/* begin block 2 */
		// Start line: 1799
	/* end block 2 */
	// End Line: 1800

void G2AnimSection_SetNotRewinding(_G2AnimSection_Type *section)

{
  section->flags = section->flags & 0xfb;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetPaused(struct _G2AnimSection_Type *section /*$a0*/)
 // line 1277, offset 0x8008df24
	/* begin block 1 */
		// Start line: 1814
	/* end block 1 */
	// End Line: 1815

	/* begin block 2 */
		// Start line: 1817
	/* end block 2 */
	// End Line: 1818

void G2AnimSection_SetPaused(_G2AnimSection_Type *section)

{
  section->flags = section->flags | 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SetUnpaused(struct _G2AnimSection_Type *section /*$a0*/)
 // line 1331, offset 0x8008df38
	/* begin block 1 */
		// Start line: 2601
	/* end block 1 */
	// End Line: 2602

	/* begin block 2 */
		// Start line: 1874
	/* end block 2 */
	// End Line: 1875

void G2AnimSection_SetUnpaused(_G2AnimSection_Type *section)

{
  section->flags = section->flags & 0xfe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2AnimSection_SwitchToKeylist(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimKeylist_Type *keylist /*$a1*/, int keylistID /*$a2*/)
 // line 1342, offset 0x8008df4c
	/* begin block 1 */
		// Start line: 1893
	/* end block 1 */
	// End Line: 1894

void G2AnimSection_SwitchToKeylist
               (_G2AnimSection_Type *section,_G2AnimKeylist_Type *keylist,int keylistID)

{
  G2AnimSection_SwitchToKeylistAtTime(section,keylist,keylistID,0);
  return;
}





