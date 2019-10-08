#include "THISDUST.H"
#include "ANIMG2.H"

_G2Bool_Enum G2Anim_Install(void)

{
  undefined2 *puVar1;

  G2PoolMem_Free(&_chanStatusBlockPool, 0xb4, 0x24);
  G2PoolMem_Free(&_interpStateBlockPool, 0x60, 0xa4);
  G2PoolMem_Free(&_controllerPool, 0x7a, 0x24);
  puVar1 = (undefined2 *)G2PoolMem_Allocate(&_controllerPool);
  *puVar1 = 0;
  *(undefined *)((int)puVar1 + 3) = 0xff;
  *(undefined *)(puVar1 + 1) = 0;
  return 1;
}

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

void _G2Anim_InitializeChannel_AdaptiveDelta(_G2Anim_Type *anim, _Model *modelData)

{
  u_char *puVar1;
  int iVar2;
  int iVar3;

  anim->sectionCount = '\x01';
  anim->masterSection = '\0';
  anim->controllerList = 0;
  anim->disabledControllerList = 0;
  anim->segMatrices = (_G2Matrix_Type *)0x0;
  anim->modelData = modelData;
  memset(anim->disabledBits, 0, 0x9c);
  iVar3 = 0;
  iVar2 = 0x24;
  do
  {
    puVar1 = &anim->sectionCount + iVar2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)(puVar1 + 6) = 0xffff;
    *(u_char *)(puVar1 + 0xc) = 0;
    *(u_char *)(puVar1 + 0x10) = 0x1000;
    iVar2 = iVar2 + 0x30;
  } while (iVar3 < 3);
  anim->section[0].segCount = *(u_char *)&modelData->numSegments;
  return;
}

_G2AnimSection_Type *G2Anim_AddSection(_G2Anim_Type *anim, int firstSegID, int segCount)

{
  u_char uVar1;
  _G2AnimSection_Type *__s;

  __s = anim->section + anim->sectionCount;
  memset(__s, 0, 0x30);
  uVar1 = anim->sectionCount;
  __s->storedTime = -1;
  __s->firstSeg = (u_char)firstSegID;
  __s->segCount = (u_char)segCount;
  __s->swAlarmTable = (short *)0x0;
  __s->speedAdjustment = 0x1000;
  __s->sectionID = uVar1;
  anim->sectionCount = anim->sectionCount + '\x01';
  return __s;
}

void G2Anim_Init(_G2Anim_Type *anim)

{
  _G2Bool_Enum _Var1;
  _G2AnimInterpInfo_Type *p_Var2;
  _G2AnimSection_Type *section;
  int iVar3;
  int iVar4;

  iVar3 = 0;
  if (anim->sectionCount != '\0')
  {
    iVar4 = 0x24;
    do
    {
      section = (_G2AnimSection_Type *)(&anim->sectionCount + iVar4);
      _Var1 = G2AnimSection_AdvanceOverInterval(section);
      if (_Var1 != G2FALSE)
      {
        section->elapsedTime = section->interpInfo->targetTime;
      }
      G2Anim_Free(section->chanStatusBlockList);
      p_Var2 = section->interpInfo;
      section->chanStatusBlockList = (_G2AnimChanStatusBlock_Type *)0x0;
      if (p_Var2 != (_G2AnimInterpInfo_Type *)0x0)
      {
        _G2Anim_AllocateInterpStateBlockList(p_Var2->stateBlockList);
        p_Var2->stateBlockList = (_G2AnimInterpStateBlock_Type *)0x0;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x30;
    } while (iVar3 < (int)(u_int)anim->sectionCount);
  }
  return;
}

void G2Anim_Restore(_G2Anim_Type *anim)

{
  _G2AnimSection_Type *section;
  int iVar1;
  int iVar2;

  iVar1 = 0;
  if (anim->sectionCount != '\0')
  {
    iVar2 = 0x24;
    do
    {
      section = (_G2AnimSection_Type *)(&anim->sectionCount + iVar2);
      if (section->keylist != (_G2AnimKeylist_Type *)0x0)
      {
        section->storedTime = -section->keylist->timePerKey;
        G2AnimSection_NextKeyframe(section, section->elapsedTime);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x30;
    } while (iVar1 < (int)(u_int)anim->sectionCount);
  }
  return;
}

void _G2Anim_BuildTransformsNoControllers(_G2Anim_Type *anim)

{
  byte bVar1;
  u_short uVar2;

  _G2AnimSection_UpdateStoredFrameFromData(anim);
  if ((anim->section[0].flags & 0x88) != 0x80)
  {
    *(u_char *)&anim->rootTrans = 0;
    (anim->rootTrans).z = 0;
  }
  if ((anim->section[0].flags & 4) != 0)
  {
    (anim->rootTrans).x = -(anim->rootTrans).x;
    (anim->rootTrans).z = -(anim->rootTrans).z;
    (anim->rootTrans).y = -(anim->rootTrans).y;
  }
  _segValues.trans.z = (anim->rootTrans).z;
  _segValues.trans._0_4_ = *(u_char *)&anim->rootTrans;
  if (anim->controllerList == 0)
  {
    _G2Anim_BuildTransformsWithControllers(anim);
  }
  else
  {
    _G2Anim_BuildSegTransformNoControllers(anim);
  }
  bVar1 = anim->section[0].flags;
  uVar2 = anim->flags;
  *(u_char *)&anim->rootTrans = 0;
  (anim->rootTrans).z = 0;
  anim->section[0].flags = bVar1 & 0x7f;
  anim->flags = uVar2 & 0xfffe;
  return;
}

void _G2AnimSection_UpdateStoredFrameFromData(_G2Anim_Type *anim)

{
  u_short uVar1;
  bool bVar2;
  u_short intervalStart;
  u_short intervalEnd;
  _G2AnimSection_Type *section;
  u_int uVar3;
  u_char local_20;
  short local_1c;

  section = anim->section;
  uVar3 = (u_int)anim->sectionCount;
  intervalStart = anim->section[0].storedTime;
  uVar1 = anim->section[0].elapsedTime;
  if (anim->sectionCount != 0)
  {
    do
    {
      if ((section->interpInfo == (_G2AnimInterpInfo_Type *)0x0) ||
          (section->interpInfo->stateBlockList == (_G2AnimInterpStateBlock_Type *)0x0))
      {
        G2Anim_UpdateStoredFrame(section, anim);
      }
      else
      {
        _G2AnimSection_UpdateStoredFrameFromQuat(section);
      }
      section = section + 1;
      uVar3 = uVar3 - 1;
    } while (0 < (int)uVar3);
  }
  if ((int)((u_int)intervalStart << 0x10) < 0)
  {
    intervalStart = 0;
  }
  local_20 = 0;
  local_1c = 0;
  intervalEnd = uVar1;
  if (((short)intervalStart < (short)uVar1) ||
      (bVar2 = (short)uVar1 < (short)intervalStart, intervalEnd = intervalStart,
       intervalStart = uVar1, bVar2))
  {
    G2AnimSection_UpdateOverInterval(anim, intervalStart, intervalEnd, (_G2SVector3_Type *)&local_20);
  }
  if ((anim->section[0].flags & 4) == 0)
  {
    (anim->rootTrans).x = (anim->rootTrans).x + (short)local_20;
    (anim->rootTrans).y = (anim->rootTrans).y + local_20._2_2_;
    local_1c = (anim->rootTrans).z + local_1c;
  }
  else
  {
    (anim->rootTrans).x = (anim->rootTrans).x - (short)local_20;
    (anim->rootTrans).y = (anim->rootTrans).y - local_20._2_2_;
    local_1c = (anim->rootTrans).z - local_1c;
  }
  (anim->rootTrans).z = local_1c;
  return;
}

_G2AnimSection_Type *G2Anim_GetSectionWithSeg(_G2Anim_Type *anim, int segNumber)

{
  _G2AnimSection_Type *p_Var1;
  _G2AnimSection_Type *p_Var2;

  p_Var1 = anim->section;
  while ((p_Var2 = (_G2AnimSection_Type *)0x0, p_Var1 < anim->section + anim->sectionCount &&
                                                   ((segNumber < (int)(u_int)p_Var1->firstSeg ||
                                                     (p_Var2 = p_Var1, (int)((u_int)p_Var1->firstSeg + (u_int)p_Var1->segCount) <= segNumber)))))
  {
    p_Var1 = p_Var1 + 1;
  }
  return p_Var2;
}

_G2Bool_Enum G2Anim_SegmentHasActiveChannels(_G2Anim_Type *anim, int segNumber, u_short chanMask)

{
  byte bVar1;
  u_short uVar2;
  _G2AnimSection_Type *p_Var3;
  _G2AnimKeylist_Type *p_Var4;
  int iVar5;
  u_short *puVar6;
  int iVar7;
  u_int uVar8;
  int iVar9;
  u_int uVar10;

  p_Var3 = G2Anim_GetSectionWithSeg(anim, segNumber);
  iVar7 = anim->modelData->numSegments * 3;
  iVar5 = iVar7 + 7;
  if (iVar5 < 0)
  {
    iVar5 = iVar7 + 0xe;
  }
  segNumber = segNumber * 3;
  p_Var4 = p_Var3->keylist;
  iVar7 = segNumber;
  if (segNumber < 0)
  {
    iVar7 = segNumber + 7;
  }
  iVar9 = (int)&p_Var4->sectionData + (iVar7 >> 3) + (u_int)p_Var4->sectionCount * 4;
  puVar6 = (u_short *)(iVar9 + 1);
  uVar10 = segNumber + (iVar7 >> 3) * -8;
  bVar1 = *(byte *)(&p_Var4->sectionData + (u_int)p_Var4->sectionCount);
  uVar8 = 0;
  if ((bVar1 & 1) != 0)
  {
    puVar6 = (u_short *)((int)puVar6 + (iVar5 >> 3));
    uVar8 = (int)(u_int) * (u_short *)(iVar9 + 1) >> (uVar10 & 0x1f) & 7;
  }
  if ((bVar1 & 2) != 0)
  {
    uVar2 = *puVar6;
    puVar6 = (u_short *)((int)puVar6 + (iVar5 >> 3));
    uVar8 = uVar8 | ((int)(u_int)uVar2 >> (uVar10 & 0x1f) & 7U) << 4;
  }
  if ((bVar1 & 4) != 0)
  {
    uVar8 = uVar8 | ((int)(u_int)*puVar6 >> (uVar10 & 0x1f) & 7U) << 8;
  }
  return (u_int)((uVar8 & chanMask) != 0);
}

void G2Anim_GetSegChannelValue(_G2Anim_Type *anim, int segIndex, u_short *valueTable, u_short channelMask)

{
  _G2AnimSegValue_Type *p_Var1;
  u_int uVar2;

  uVar2 = (u_int)channelMask;
  _G2AnimSection_UpdateStoredFrameFromData(anim);
  _segValues.trans._0_4_ = *(u_char *)&anim->rootTrans;
  _segValues.trans.z = (anim->rootTrans).z;
  _G2Anim_ApplyControllersToStoredFrame(anim);
  p_Var1 = &_segValues + segIndex;
  if (channelMask != 0)
  {
    do
    {
      if ((uVar2 & 1) != 0)
      {
        *valueTable = *(u_short *)&p_Var1->rotQuat;
        valueTable = valueTable + 1;
      }
      uVar2 = uVar2 >> 1;
      p_Var1 = (_G2AnimSegValue_Type *)((int)&p_Var1->rotQuat + 2);
    } while (uVar2 != 0);
  }
  return;
}

void G2Anim_GetRootMotionFromTimeForDuration(_G2Anim_Type *anim, short durationStart, short duration, _G2SVector3_Type *motionVector)

{
  short sVar1;
  u_short uVar2;
  u_int uVar3;
  long lVar4;
  u_int uVar5;
  _G2AnimInterpInfo_Type *p_Var6;
  u_int uVar7;
  u_char uVar8;
  u_char uVar9;
  u_char uVar10;
  _G2AnimInterpStateBlock_Type *p_Var11;
  u_int uVar12;
  _G2AnimKeylist_Type *p_Var13;
  int iVar14;
  u_int uVar15;
  _G2Anim_Type local_d8;

  uVar5 = (u_int)(u_short)duration;
  uVar7 = (u_int)(u_short)durationStart;
  p_Var6 = anim->section[0].interpInfo;
  if (p_Var6 != (_G2AnimInterpInfo_Type *)0x0)
  {
    p_Var11 = p_Var6->stateBlockList;
    if (p_Var11 != (_G2AnimInterpStateBlock_Type *)0x0)
    {
      lVar4 = _G2AnimAlphaTable_GetValue
 (int)p_Var6->duration);
      setCopReg(2, 0xc800, (u_int)(u_short)p_Var11->quatInfo[0].srcTrans.x);
      setCopReg(2, 0xd000, (u_int)(u_short)p_Var11->quatInfo[0].srcTrans.y);
      setCopReg(2, 0xd800, (u_int)(u_short)p_Var11->quatInfo[0].srcTrans.z);
      setCopReg(2, 0x4800, (u_int)(u_short)p_Var11->quatInfo[0].destTrans.x);
      setCopReg(2, 0x5000, (u_int)(u_short)p_Var11->quatInfo[0].destTrans.y);
      setCopReg(2, 0x5800, (u_int)(u_short)p_Var11->quatInfo[0].destTrans.z);
      setCopReg(2, 0x4000, lVar4);
      copFunction(2, 0x1a8003e);
      uVar8 = getCopReg(2, 0xc800);
      uVar9 = getCopReg(2, 0xd000);
      uVar10 = getCopReg(2, 0xd800);
      motionVector->x = (short)uVar8;
      motionVector->y = (short)uVar9;
      motionVector->z = (short)uVar10;
      (int)(anim->section[0].keylist)->timePerKey;
      motionVector->x = (short)(motionVector->x * iVar14 >> 0xc);
      motionVector->y = (short)(motionVector->y * iVar14 >> 0xc);
      motionVector->z = (short)(motionVector->z * iVar14 >> 0xc);
      return;
    }
  }
  p_Var13 = anim->section[0].keylist;
  sVar1 = p_Var13->timePerKey;
  uVar12 = (u_int)(u_short)p_Var13->timePerKey;
 (int)sVar1 + 1);
 uVar2 = p_Var13->keyCount;
 local_d8.sectionCount = '\x01';
 local_d8.modelData = anim->modelData;
 local_d8.section[0].sectionID = '\0';
 local_d8.section[0].firstSeg = '\0';
 local_d8.section[0].segCount = '\x01';
 local_d8.section[0].chanStatusBlockList = (_G2AnimChanStatusBlock_Type *)0x0;
 local_d8.section[0].storedTime = -p_Var13->timePerKey;
 *(u_char *)motionVector = 0;
 motionVector->z = 0;
 local_d8.section[0].keylist = p_Var13;
 if (duration != 0)
 {
   do
   {
     local_d8.section[0].elapsedTime = (short)uVar7;
     if ((short)(sVar1 * (uVar2 - 1)) <= local_d8.section[0].elapsedTime)
     {
       uVar12 = (u_int)p_Var13->s0TailTime;
     }
     G2Anim_UpdateStoredFrame(local_d8.section, &local_d8);
     uVar3 = uVar15 - uVar7;
     if ((int)(uVar5 << 0x10) < (int)((uVar15 - uVar7) * 0x10000))
     {
       uVar3 = uVar5;
     }
     if ((int)(short)uVar3 < (int)(short)uVar12)
     {
       (int)(short) uVar12;
     }
     else
     {
       iVar14 = 0x1000;
     }
     setCopReg(2, 0xc800, (u_int)(u_short)motionVector->x);
     setCopReg(2, 0xd000, (u_int)(u_short)motionVector->y);
     setCopReg(2, 0xd800, (u_int)(u_short)motionVector->z);
     setCopReg(2, 0x4800, (u_int)(u_short)_segValues.trans.x);
     setCopReg(2, 0x5000, (u_int)(u_short)_segValues.trans.y);
     setCopReg(2, 0x5800, (u_int)(u_short)_segValues.trans.z);
     setCopReg(2, 0x4000, iVar14);
     copFunction(2, 0x1a8003e);
     uVar8 = getCopReg(2, 0xc800);
     uVar9 = getCopReg(2, 0xd000);
     uVar10 = getCopReg(2, 0xd800);
     motionVector->x = (short)uVar8;
     motionVector->y = (short)uVar9;
     motionVector->z = (short)uVar10;
     uVar5 = uVar5 - uVar3;
     uVar7 = uVar15;
     uVar15 = uVar15 + uVar12;
   } while ((uVar5 & 0xffff) != 0);
 }
 G2Anim_Free(local_d8.section[0].chanStatusBlockList);
 return;
}

void G2AnimSection_InterpToKeylistAtTime(_G2AnimSection_Type *section, _G2AnimKeylist_Type *keylist, int keylistID,
                                         short targetTime)

{
  _G2Anim_Type *anim;
  _G2AnimInterpInfo_Type *p_Var1;
  u_char local_28;
  short local_24;

  anim = G2AnimSection_SetUnpaused(section);
  if (section->firstSeg == '\0')
  {
    anim->flags = anim->flags | 1;
    if ((section->keylist == (_G2AnimKeylist_Type *)0x0) || (section->storedTime < 0))
    {
      local_28 = 0;
      local_24 = 0;
    }
    else
    {
      G2AnimSection_UpdateOverInterval(anim, section->storedTime, section->elapsedTime, (_G2SVector3_Type *)&local_28);
    }
    local_28 = CONCAT22((short)((u_int)local_28 >> 0x10) + (anim->rootTrans).y,
                        (short)local_28 + (anim->rootTrans).x);
    local_24 = local_24 + (anim->rootTrans).z;
  }
  p_Var1 = section->interpInfo;
  if ((p_Var1 != (_G2AnimInterpInfo_Type *)0x0) &&
      (p_Var1->stateBlockList != (_G2AnimInterpStateBlock_Type *)0x0))
  {
    _G2Anim_AllocateInterpStateBlockList(p_Var1->stateBlockList);
    p_Var1->stateBlockList = (_G2AnimInterpStateBlock_Type *)0x0;
  }
  G2AnimSection_SetLooping(section, 3);
  if (keylist != section->keylist)
  {
    section->keylist = keylist;
    section->keylistID = (u_short)keylistID;
    section->storedTime = -keylist->timePerKey;
  }
  G2AnimSection_NextKeyframe(section, targetTime);
  if (section->firstSeg == '\0')
  {
    section->flags = section->flags | 0x80;
    *(u_char *)&anim->rootTrans = local_28;
    (anim->rootTrans).z = local_24;
  }
  if ((section->flags & 2) != 0)
  {
    G2AnimSection_SetPaused(section);
  }
  G2Anim_SetUnpaused(section);
  section->swAlarmTable = (short *)0x0;
  return;
}

void G2AnimSection_NextKeyframe(_G2AnimSection_Type *section, short targetTime)

{
  _G2Anim_Type *anim;

  anim = G2AnimSection_SetUnpaused(section);
  if (targetTime < section->elapsedTime)
  {
    section->storedTime = -section->keylist->timePerKey;
  }
  section->elapsedTime = targetTime;
  G2Anim_UpdateStoredFrame(section, anim);
  G2AnimSection_SetLooping(section, 3);
  section->flags = section->flags & 0x7f;
  if (section->firstSeg == '\0')
  {
    *(u_char *)&anim->rootTrans = 0;
    (anim->rootTrans).z = 0;
  }
  return;
}

short G2AnimSection_SetInterpInfo(_G2AnimSection_Type *section, short interval)

{
  u_short intervalStart;
  short sVar1;
  _G2Anim_Type *anim;
  int iVar2;
  int iVar3;
  _G2AnimInterpInfo_Type *p_Var4;
  u_char local_20;
  short local_1c;

  if ((section->flags & 1) == 0)
  {
    p_Var4 = section->interpInfo;
    if ((p_Var4 == (_G2AnimInterpInfo_Type *)0x0) ||
        (p_Var4->stateBlockList == (_G2AnimInterpStateBlock_Type *)0x0))
    {
      if ((section->flags & 4) == 0)
      {
        sVar1 = G2Anim_GetRootMotionOverInterval(section, interval);
      }
      else
      {
        sVar1 = G2AnimSection_IsInInterpolation(section, interval);
      }
    }
    else
    {
      anim = G2AnimSection_SetUnpaused(section);
      anim->flags = anim->flags | 1;
      intervalStart = section->elapsedTime;
      iVar3 = (u_int)intervalStart + ((int)interval * section->speedAdjustment >> 0xc);
      iVar2 = (iVar3 - (u_int)(u_short)p_Var4->duration) * 0x10000;
      sVar1 = (short)((u_int)iVar2 >> 0x10);
      if (iVar2 >> 0x10 < 0)
      {
        section->elapsedTime = (short)iVar3;
        sVar1 = 0;
      }
      else
      {
        section->storedTime = -section->keylist->timePerKey;
        G2AnimSection_NextKeyframe(section, p_Var4->targetTime);
        if (section->firstSeg == '\0')
        {
          G2AnimSection_UpdateOverInterval(anim, intervalStart, p_Var4->duration, (_G2SVector3_Type *)&local_20);
          *(u_char *)&anim->rootTrans = local_20;
          (anim->rootTrans).z = local_1c;
          section->flags = section->flags | 0x80;
        }
        _G2Anim_AllocateInterpStateBlockList(p_Var4->stateBlockList);
        p_Var4->stateBlockList = (_G2AnimInterpStateBlock_Type *)0x0;
        if ((section->flags & 2) != 0)
        {
          G2AnimSection_SetPaused(section);
        }
        section->alarmFlags = section->alarmFlags | 0x10;
        if (section->callback != (_func_8 *)0x0)
        {
          (*section->callback)(anim, (u_int)section->sectionID, 3, 0, 0, section->callbackData);
        }
      }
    }
  }
  else
  {
    sVar1 = 0;
  }
  return sVar1;
}

short G2Anim_GetRootMotionOverInterval(_G2AnimSection_Type *section, short interval)

{
  byte bVar1;
  u_short startTime;
  u_short uVar2;
  short intervalEnd;
  short sVar3;
  _G2Anim_Type *anim;
  short *psVar4;
  _G2Anim_Type *p_Var5;
  long lVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  u_int uVar10;
  int iVar11;
  u_char uVar12;
  u_int uVar13;
  u_char local_38;
  short local_34;
  u_short local_30;

  local_30 = 0;
  if (((section->flags & 1) == 0) && ((section->alarmFlags & 1) == 0))
  {
    anim = G2AnimSection_SetUnpaused(section);
    anim->flags = anim->flags | 1;
    G2AnimSection_SetLooping(section, 3);
    bVar1 = section->flags;
    startTime = section->elapsedTime;
    section->flags = bVar1 & 0xfb;
    if ((bVar1 & 2) == 0)
    {
      uVar2 = G2AnimKeylist_GetDuration(section->keylist);
    }
    else
    {
      uVar2 = section->loopEndTime;
    }
    uVar13 = (u_int)uVar2;
    lVar8 = (u_int)startTime + ((int)interval * section->speedAdjustment >> 0xc);
    psVar4 = section->swAlarmTable;
    if (psVar4 == (short *)0x0)
    {
      G2AnimSection_SetLooping(section, 0x20);
    }
    else
    {
      iVar7 = (int)*psVar4;
      if (iVar7 != -1)
      {
        iVar11 = (int)(short)startTime;
        iVar9 = lVar8 * 0x10000 >> 0x10;
        do
        {
          if ((((iVar11 < iVar7) && (iVar7 <= iVar9)) ||
               ((section->storedTime < 1 && (iVar11 == iVar7)))) &&
              (section->alarmFlags = section->alarmFlags | 0x20, section->callback != (_func_8 *)0x0))
          {
            (*section->callback)(anim, (u_int)section->sectionID, 5, iVar11, iVar9, section->callbackData);
          }
          psVar4 = psVar4 + 1;
          iVar7 = (int)*psVar4;
        } while (iVar7 != -1);
      }
    }
    G2AnimSection_GetStoredKeyframeNumber(section, startTime, (short)lVar8);
    uVar10 = lVar8 - uVar13;
    iVar7 = uVar10 * 0x10000;
    while (true)
    {
      sVar3 = (short)uVar10;
      intervalEnd = (short)lVar8;
      if (iVar7 < 0)
        break;
      uVar12 = 2;
      intervalEnd = (short)uVar13;
      if ((section->flags & 2) == 0)
      {
        uVar12 = 1;
        lVar8 = uVar13 - 1;
        section->alarmFlags = section->alarmFlags | 1;
      }
      else
      {
        section->alarmFlags = section->alarmFlags | 4;
        G2AnimSection_NextKeyframe(section, section->loopStartTime);
        lVar8 = (u_int)(u_short)section->loopStartTime + uVar10;
        local_30 = (short)lVar8 - intervalEnd;
        G2AnimSection_GetStoredKeyframeNumber(section, (short)(((u_int)(u_short)section->loopStartTime - 1) * 0x10000 >> 0x10),
                                              (short)((u_int)(lVar8 * 0x10000) >> 0x10));
        if ((int)intervalEnd <= lVar8 * 0x10000 >> 0x10)
        {
          lVar8 = uVar13 - 1;
        }
      }
      if (section->firstSeg == '\0')
      {
        anim = G2AnimSection_SetUnpaused(section);
        G2AnimSection_UpdateOverInterval(anim, startTime, intervalEnd, (_G2SVector3_Type *)&local_38);
      }
      if (section->callback != (_func_8 *)0x0)
      {
        p_Var5 = G2AnimSection_SetUnpaused(section);
        lVar6 = (*section->callback)(p_Var5, (u_int)section->sectionID, uVar12, (int)(short)lVar8, (int)sVar3,
                                     section->callbackData);
        intervalEnd = (short)lVar6;
        if ((int)intervalEnd == (int)(short)lVar8)
        {
          if ((section->flags & 2) == 0)
          {
            local_38 = 0;
            local_34 = 0;
          }
          else
          {
            G2AnimSection_NextKeyframe(section, intervalEnd);
            section->storedTime = section->loopStartTime;
          }
        }
        else
        {
          G2AnimSection_NextKeyframe(section, intervalEnd);
          lVar8 = lVar6;
        }
      }
      intervalEnd = (short)lVar8;
      if (section->firstSeg == '\0')
      {
        *(u_char *)&anim->rootTrans = local_38;
        (anim->rootTrans).z = local_34;
        section->flags = section->flags | 0x80;
      }
      if ((section->flags & 2) == 0)
        goto LAB_80093634;
      uVar13 = (u_int)(u_short)section->loopEndTime;
      uVar10 = (u_int)local_30;
      iVar7 = uVar10 << 0x10;
    }
    sVar3 = 0;
  LAB_80093634:
    section->elapsedTime = intervalEnd;
  }
  else
  {
    sVar3 = 0;
  }
  return sVar3;
}

short G2AnimSection_IsInInterpolation(_G2AnimSection_Type *section, short interval)

{
  byte bVar1;
  u_short intervalStart;
  short targetTime;
  short sVar2;
  _G2Anim_Type *anim;
  int iVar3;
  _G2Anim_Type *p_Var4;
  long lVar5;
  u_int uVar6;
  short sVar7;
  u_char uVar8;
  u_char local_30;
  short local_2c;

  if (((section->flags & 1) == 0) && ((section->alarmFlags & 2) == 0))
  {
    anim = G2AnimSection_SetUnpaused(section);
    anim->flags = anim->flags | 1;
    G2AnimSection_SetLooping(section, 3);
    uVar6 = 0;
    bVar1 = section->flags;
    intervalStart = section->elapsedTime;
    section->flags = bVar1 | 4;
    if ((bVar1 & 2) != 0)
    {
      uVar6 = (u_int)(u_short)section->loopStartTime;
    }
    iVar3 = (u_int)intervalStart - ((int)interval * section->speedAdjustment >> 0xc);
    sVar7 = (short)iVar3;
    iVar3 = uVar6 - iVar3;
    sVar2 = (short)iVar3;
    if (iVar3 * 0x10000 < 1)
    {
      sVar2 = 0;
    }
    else
    {
      if ((bVar1 & 2) == 0)
      {
        uVar8 = 1;
        section->alarmFlags = section->alarmFlags | 2;
        sVar7 = (short)uVar6;
      }
      else
      {
        section->alarmFlags = section->alarmFlags | 4;
        G2AnimSection_NextKeyframe(section, section->loopEndTime);
        uVar8 = 2;
        sVar7 = section->loopEndTime - sVar2;
      }
      if (section->firstSeg == '\0')
      {
        G2AnimSection_UpdateOverInterval(anim, intervalStart, (short)uVar6, (_G2SVector3_Type *)&local_30);
      }
      if (section->callback != (_func_8 *)0x0)
      {
        p_Var4 = G2AnimSection_SetUnpaused(section);
        lVar5 = (*section->callback)(p_Var4, (u_int)section->sectionID, uVar8, (int)sVar7, (int)sVar2,
                                     section->callbackData);
        targetTime = (short)lVar5;
        if (((section->flags & 2) == 0) && ((int)targetTime == (int)sVar7))
        {
          local_30 = 0;
          local_2c = 0;
        }
        else
        {
          G2AnimSection_NextKeyframe(section, targetTime);
          sVar7 = targetTime;
        }
      }
      if (section->firstSeg == '\0')
      {
        *(u_char *)&anim->rootTrans = local_30;
        (anim->rootTrans).z = local_2c;
        section->flags = section->flags | 0x80;
      }
    }
    section->elapsedTime = sVar7;
  }
  else
  {
    sVar2 = 0;
  }
  return sVar2;
}

void _G2Anim_BuildTransformsWithControllers(_G2Anim_Type *anim)

{
  int iVar1;
  _G2Bool_Enum bRootTransUpdated;
  u_int *puVar2;
  u_int uVar3;
  u_short *puVar4;
  int segIndex;
  _G2Matrix_Type *segMatrix;
  int iVar5;
  u_long local_38[4];

  segMatrix = anim->segMatrices;
  uVar3 = 1;
  local_38[0] = anim->disabledBits[0];
  segIndex = 0;
  local_38[1] = anim->disabledBits[1];
  local_38[2] = anim->disabledBits[2];
  iVar5 = anim->modelData->numSegments;
  bRootTransUpdated = (_G2Bool_Enum)((anim->section[0].flags & 0x88) == 0x80);
  if (0 < iVar5)
  {
    puVar4 = (u_short *)&anim->modelData->segmentList->parent;
    puVar2 = local_38;
    do
    {
      iVar1 = (u_int)*puVar4 << 0x10;
      if ((iVar1 >> 0x10 != -1) && ((local_38[iVar1 >> 0x15] & 1 << (*puVar4 & 0x1f)) != 0))
      {
        *puVar2 = *puVar2 | uVar3;
      }
      if ((*puVar2 & uVar3) == 0)
      {
        _G2Anim_BuildSegTransformWithControllers(segMatrix, anim->segMatrices + (short)*puVar4, bRootTransUpdated, segIndex);
      }
      bRootTransUpdated = G2FALSE;
      puVar4 = puVar4 + 0xc;
      segMatrix = segMatrix + 1;
      uVar3 = uVar3 << 1;
      segIndex = segIndex + 1;
      if (uVar3 == 0)
      {
        puVar2 = puVar2 + 1;
        uVar3 = 1;
      }
    } while (segIndex < iVar5);
  }
  return;
}

void _G2Anim_BuildSegTransformWithControllers(_G2Matrix_Type *segMatrix, _G2Matrix_Type *parentMatrix,
                                              _G2Bool_Enum bRootTransUpdated, int segIndex)

{
  u_short uVar1;
  u_short uVar2;
  u_short uVar3;
  bool bVar4;
  long lVar5;
  u_char in_zero;
  u_char in_at;
  u_char uVar6;
  u_char uVar7;
  u_char uVar8;
  u_char uVar9;
  int local_28;
  int local_24;
  int local_20;

  uVar1 = (&_segValues)[segIndex].scale.x;
  local_28 = (int)(short)uVar1;
  uVar2 = (&_segValues)[segIndex].scale.y;
  local_24 = (int)(short)uVar2;
  uVar3 = (&_segValues)[segIndex].scale.z;
  local_20 = (int)(short)uVar3;
  bVar4 = (u_short)(uVar1 | uVar2 | uVar3) != 0x1000;
  _G2Anim_BuildSegLocalRotMatrix(&_segValues + segIndex, segMatrix);
  if (bVar4)
  {
    ScaleMatrix((int *)segMatrix, &local_28);
    segMatrix->scaleFlag = (u_short)bVar4;
  }
  setCopControlWord(2, 0, *(u_char *)parentMatrix->rotScale);
  setCopControlWord(2, 0x800, *(u_char *)(parentMatrix->rotScale + 2));
  setCopControlWord(2, 0x1000, *(u_char *)(parentMatrix->rotScale + 4));
  setCopControlWord(2, 0x1800, *(u_char *)(parentMatrix->rotScale + 6));
  setCopControlWord(2, 0x2000, *(u_char *)(parentMatrix->rotScale + 8));
  setCopReg(2, 0x4800, (u_int)(u_short)segMatrix->rotScale[0]);
  setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[3]);
  setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[6]);
  copFunction(2, 0x49e012);
  uVar1 = segMatrix->rotScale[2];
  uVar7 = getCopReg(2, 0x4800);
  uVar8 = getCopReg(2, 0x5000);
  uVar9 = getCopReg(2, 0x5800);
  setCopReg(2, 0x4800, (u_int)(u_short)segMatrix->rotScale[1]);
  setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[4]);
  setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[7]);
  segMatrix->rotScale[0] = (short)uVar7;
  segMatrix->rotScale[3] = (short)uVar8;
  copFunction(2, 0x49e012);
  uVar7 = getCopReg(2, 0x4800);
  uVar8 = getCopReg(2, 0x5000);
  uVar6 = getCopReg(2, 0x5800);
  setCopReg(2, 0x4800, (u_int)uVar1);
  setCopReg(2, 0x5000, (u_int)(u_short)segMatrix->rotScale[5]);
  setCopReg(2, 0x5800, (u_int)(u_short)segMatrix->rotScale[8]);
  segMatrix->rotScale[6] = (short)uVar9;
  segMatrix->rotScale[1] = (short)uVar7;
  copFunction(2, 0x49e012);
  segMatrix->rotScale[4] = (short)uVar8;
  segMatrix->rotScale[7] = (short)uVar6;
  uVar7 = getCopReg(2, 0x4800);
  uVar8 = getCopReg(2, 0x5000);
  uVar6 = getCopReg(2, 0x5800);
  segMatrix->rotScale[2] = (short)uVar7;
  segMatrix->rotScale[5] = (short)uVar8;
  segMatrix->rotScale[8] = (short)uVar6;
  setCopReg(2, in_zero, *(u_char *)&(&_segValues)[segIndex].trans);
  setCopReg(2, in_at, *(u_char *)&(&_segValues)[segIndex].trans.z);
  copFunction(2, 0x486012);
  lVar5 = getCopReg(2, 0x19);
  (segMatrix->trans).x = lVar5;
  lVar5 = getCopReg(2, 0x1a);
  (segMatrix->trans).y = lVar5;
  lVar5 = getCopReg(2, 0x1b);
  (segMatrix->trans).z = lVar5;
  if (bRootTransUpdated != G2FALSE)
  {
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

void _G2Anim_BuildSegLocalRotMatrix(_G2AnimSegValue_Type *segValue, _G2Matrix_Type *segMatrix)

{
  u_int local_10;
  u_short local_c;

  if (segValue->bIsQuat == 0)
  {
    local_c = *(u_short *)((int)&segValue->rotQuat + 4) & 0xfff;
    local_10 = *(u_int *)&segValue->rotQuat & 0xfff0fff;
    RotMatrixZYX((u_short *)&local_10, (u_int *)segMatrix);
  }
  else
  {
    G2Quat_ToMatrix_S((short *)segValue, (short *)segMatrix);
  }
  return;
}

void MON_Combat(u_char *segKeyList, int flagBitOffset, _G2AnimSegKeyflagInfo_Type *kfInfo)

{
  u_int uVar1;

  *(u_char **)&kfInfo->stream = segKeyList + (flagBitOffset >> 5) * 4;
  uVar1 = *(u_int *)(segKeyList + (flagBitOffset >> 5) * 4);
  kfInfo->bitCount = 0x20 - (flagBitOffset & 0x1fU);
  kfInfo->flags = uVar1 >> (flagBitOffset & 0x1fU);
  return;
}

u_long kangaroo(_G2AnimSegKeyflagInfo_Type *kfInfo)

{
  int iVar1;
  u_long *puVar2;
  u_int uVar3;
  u_long uVar4;

  uVar4 = 0;
  if (kfInfo->stream != (u_long *)0x0)
  {
    uVar4 = kfInfo->flags & 7;
    iVar1 = kfInfo->bitCount + -3;
    kfInfo->flags = kfInfo->flags >> 3;
    kfInfo->bitCount = iVar1;
    if (iVar1 < 1)
    {
      puVar2 = kfInfo->stream;
      kfInfo->stream = puVar2 + 1;
      uVar3 = puVar2[1];
      iVar1 = kfInfo->bitCount;
      kfInfo->flags = uVar3;
      if (iVar1 < 0)
      {
        uVar4 = uVar4 | uVar3 << (iVar1 + 3U & 0x1f) & 7;
        kfInfo->flags = uVar3 >> (-iVar1 & 0x1fU);
      }
      kfInfo->bitCount = kfInfo->bitCount + 0x20;
    }
  }
  return uVar4;
}

void _G2Anim_InitializeChannel_Linear(_G2Anim_Type *anim, _G2AnimSegValue_Type *segValue, int segIndex)

{
  _Segment *p_Var1;
  u_int uVar2;

  *(u_char *)((int)&segValue->rotQuat + 4) = 0x10000000;
  *(u_char *)&segValue->scale = 0x10001000;
  *(u_char *)&segValue->rotQuat = 0;
  (segValue->scale).z = 0x1000;
  p_Var1 = anim->modelData->segmentList + segIndex;
  uVar2 = *(u_int *)&p_Var1->pz;
  *(u_char *)&segValue->trans = *(u_char *)&p_Var1->px;
  *(u_int *)&(segValue->trans).z = uVar2 & 0xffff;
  return;
}

void _G2AnimSection_InitStatus(_G2AnimSection_Type *section, _G2Anim_Type *anim)

{
  _func_7 **pp_Var1;
  u_int uVar2;
  u_long uVar3;
  u_long uVar4;
  byte bVar5;
  int flagBitOffset;
  _func_7 ***segKeyList;
  u_int uVar6;
  u_int segIndex;
  _G2AnimChanStatus_Type *status;
  _G2AnimChanStatusBlock_Type *p_Var7;
  _G2AnimChanStatusBlock_Type *p_Var8;
  _G2AnimSegValue_Type *segValue;
  u_int uVar9;
  _G2AnimDecompressChannelInfo_Type local_68;
  _G2AnimSegKeyflagInfo_Type local_58;
  _G2AnimSegKeyflagInfo_Type local_48;
  _G2AnimSegKeyflagInfo_Type local_38;

  flagBitOffset = (u_int)section->firstSeg * 3 + 8;
  segKeyList = &section->keylist->sectionData + section->keylist->sectionCount;
  bVar5 = *(byte *)segKeyList;
  segIndex = anim->modelData->numSegments * 3 + 7U & 0xfffffff8;
  local_58.stream = (u_long *)0x0;
  local_48.stream = (u_long *)0x0;
  local_38.stream = (u_long *)0x0;
  if ((bVar5 & 1) != 0)
  {
    MON_Combat((u_char *)segKeyList, flagBitOffset, &local_58);
    flagBitOffset = flagBitOffset + segIndex;
  }
  if ((bVar5 & 2) != 0)
  {
    MON_Combat((u_char *)segKeyList, flagBitOffset, &local_48);
    flagBitOffset = flagBitOffset + segIndex;
  }
  if ((bVar5 & 4) != 0)
  {
    MON_Combat((u_char *)segKeyList, flagBitOffset, &local_38);
  }
  status = (_G2AnimChanStatus_Type *)0x0;
  G2Anim_Free(section->chanStatusBlockList);
  flagBitOffset = 0;
  local_68.keylist = section->keylist;
  section->chanStatusBlockList = (_G2AnimChanStatusBlock_Type *)0x0;
  local_68.chanData = (&section->keylist->sectionData)[section->sectionID];
  segIndex = (u_int)section->firstSeg;
  segValue = &_segValues + segIndex;
  uVar9 = segIndex + section->segCount;
  p_Var8 = (_G2AnimChanStatusBlock_Type *)&section->chanStatusBlockList;
  if (segIndex < uVar9)
  {
    do
    {
      uVar2 = kangaroo(&local_58);
      uVar3 = kangaroo(&local_48);
      uVar4 = kangaroo(&local_38);
      uVar6 = uVar2 | uVar3 << 4 | uVar4 << 8;
      _G2Anim_InitializeChannel_Linear(anim, segValue, segIndex);
      while (uVar6 != 0)
      {
        pp_Var1 = local_68.chanData;
        if ((uVar2 & 1) != 0)
        {
          bVar5 = *(byte *)((int)local_68.chanData + 1) & 0xe0;
          if (bVar5 == 0xe0)
          {
            bVar5 = 0;
          }
          if (bVar5 == 0)
          {
            pp_Var1 = (_func_7 **)((int)local_68.chanData + (u_int)(local_68.keylist)->keyCount * 2);
          }
          else
          {
            pp_Var1 = local_68.chanData + 1;
            if (bVar5 != 0x20)
            {
              p_Var7 = p_Var8;
              if (flagBitOffset == 0)
              {
                flagBitOffset = 8;
                p_Var7 = (_G2AnimChanStatusBlock_Type *)G2PoolMem_Allocate(&_chanStatusBlockPool);
                p_Var7->next = (_G2AnimChanStatusBlock_Type *)0x0;
                p_Var8->next = p_Var7;
                status = p_Var7->chunks;
              }
              if (bVar5 == 0x40)
              {
                _G2Anim_InitializeSegValue(&local_68, status);
              }
              else
              {
                if (bVar5 == 0x60)
                {
                  _G2Anim_DecompressChannel_Linear(&local_68, status);
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

void FooBar(_G2AnimSection_Type *section, _G2Anim_Type *anim, int decompressedKey, int targetKey,
            long timeOffset)

{
  u_int uVar1;
  u_long uVar2;
  u_long uVar3;
  u_long uVar4;
  _func_7 **pp_Var5;
  u_int uVar6;
  byte bVar7;
  int flagBitOffset;
  _func_7 ***segKeyList;
  _G2AnimSegValue_Type *p_Var8;
  u_int segIndex;
  u_int uVar9;
  _G2AnimChanStatus_Type *status;
  _G2AnimSegValue_Type *segValue;
  _G2AnimChanStatusBlock_Type *p_Var10;
  _G2AnimDecompressChannelInfo_Type local_98;
  _G2AnimSegKeyflagInfo_Type local_88;
  _G2AnimSegKeyflagInfo_Type local_78;
  _G2AnimSegKeyflagInfo_Type local_68;
  _G2AnimDecompressChannelInfo_Type local_58;
  _G2AnimDecompressChannelInfo_Type local_48;
  _G2AnimChanStatus_Type local_38[2];
  u_int local_30;

  flagBitOffset = (u_int)section->firstSeg * 3 + 8;
  segKeyList = &section->keylist->sectionData + section->keylist->sectionCount;
  bVar7 = *(byte *)segKeyList;
  segIndex = anim->modelData->numSegments * 3 + 7U & 0xfffffff8;
  local_88.stream = (u_long *)0x0;
  local_78.stream = (u_long *)0x0;
  local_68.stream = (u_long *)0x0;
  if ((bVar7 & 1) != 0)
  {
    MON_Combat((u_char *)segKeyList, flagBitOffset, &local_88);
    flagBitOffset = flagBitOffset + segIndex;
  }
  if ((bVar7 & 2) != 0)
  {
    MON_Combat((u_char *)segKeyList, flagBitOffset, &local_78);
    flagBitOffset = flagBitOffset + segIndex;
  }
  if ((bVar7 & 4) != 0)
  {
    MON_Combat((u_char *)segKeyList, flagBitOffset, &local_68);
  }
  p_Var10 = section->chanStatusBlockList;
  local_98.keylist = section->keylist;
  flagBitOffset = 8;
  local_98.chanData = (&section->keylist->sectionData)[section->sectionID];
  status = p_Var10->chunks;
  if ((timeOffset != 0) &&
      (local_58.targetKey = targetKey + 1, local_58.keylist = local_98.keylist,
       local_58.chanData = local_98.chanData, local_58.storedKey = targetKey,
       (int)(u_int)section->keylist->keyCount <= local_58.targetKey))
  {
    if ((section->flags & 2) == 0)
    {
      timeOffset = 0;
    }
    else
    {
      local_58.storedKey = -1;
      local_58.targetKey = 0;
      local_48.keylist = local_98.keylist;
      local_48.chanData = local_98.chanData;
    }
  }
  segIndex = (u_int)section->firstSeg;
  segValue = &_segValues + segIndex;
  local_30 = segIndex + section->segCount;
  local_98.storedKey = decompressedKey;
  local_98.targetKey = targetKey;
  if (segIndex < local_30)
  {
    do
    {
      _G2Anim_InitializeChannel_Linear(anim, segValue, segIndex);
      uVar2 = kangaroo(&local_88);
      uVar3 = kangaroo(&local_78);
      uVar4 = kangaroo(&local_68);
      uVar9 = uVar2 | uVar3 << 4 | uVar4 << 8;
      p_Var8 = segValue;
      while (uVar9 != 0)
      {
        if ((uVar9 & 1) != 0)
        {
          bVar7 = *(byte *)((int)local_98.chanData + 1) & 0xe0;
          if (bVar7 == 0xe0)
          {
            bVar7 = 0;
          }
          if (bVar7 == 0)
          {
            *(undefined2 *)&p_Var8->rotQuat =
                *(undefined2 *)((int)local_98.chanData + targetKey * 2);
            local_98.chanData =
                (_func_7 **)((int)local_98.chanData + (u_int)(local_98.keylist)->keyCount * 2);
          }
          else
          {
            if (bVar7 == 0x20)
            {
              *(undefined2 *)&p_Var8->rotQuat = *(undefined2 *)((int)local_98.chanData + 2);
              local_98.chanData = local_98.chanData + 1;
            }
            else
            {
              if (bVar7 == 0x40)
              {
                _G2Anim_DecompressChannel_AdaptiveDelta(&local_98, status);
              }
              else
              {
                if (bVar7 == 0x60)
                {
                  _G2Anim_DecompressChannel_Linear(&local_98, status);
                }
              }
              flagBitOffset = flagBitOffset + -1;
              *(short *)&p_Var8->rotQuat = status->keyData;
              local_38[0] = *status;
              status = status + 1;
              if (flagBitOffset == 0)
              {
                p_Var10 = p_Var10->next;
                flagBitOffset = 8;
                status = p_Var10->chunks;
              }
            }
          }
          if (timeOffset != 0)
          {
            if (bVar7 == 0x40)
            {
              if (local_58.storedKey == -1)
              {
                _G2Anim_InitializeSegValue(&local_48, local_38);
              }
              _G2Anim_DecompressChannel_AdaptiveDelta(&local_58, local_38);
            }
            else
            {
              if (bVar7 < 0x41)
              {
                if (bVar7 == 0)
                {
                  pp_Var5 = (_func_7 **)((int)local_58.chanData + local_58.targetKey * 2);
                  local_58.chanData = local_98.chanData;
                  local_48.chanData = local_98.chanData;
                  local_38[0] = (_G2AnimChanStatus_Type)((u_int)local_38[0] & 0xffff0000 | (u_int) * (u_short *)pp_Var5);
                }
                else
                {
                  if (bVar7 == 0x20)
                  {
                    local_38[0] = (_G2AnimChanStatus_Type)((u_int)local_38[0] & 0xffff0000 |
                                                           (u_int) * (u_short *)&p_Var8->rotQuat);
                    local_58.chanData = local_98.chanData;
                    local_48.chanData = local_98.chanData;
                  }
                }
              }
              else
              {
                if (bVar7 == 0x60)
                {
                  if (local_58.storedKey == -1)
                  {
                    _G2Anim_DecompressChannel_Linear(&local_48, local_38);
                  }
                  _G2Anim_DecompressChannel_Linear(&local_58, local_38);
                }
              }
            }
            uVar6 = ((u_int)local_38[0] & 0xffff) - (u_int) * (u_short *)&p_Var8->rotQuat;
            uVar1 = uVar6 & 0xffff;
            if (0x7ff < (int)(uVar6 * 0x10000) >> 0x10)
            {
              uVar1 = (u_int)(u_short)((short)uVar6 - 0x1000);
            }
            local_38[0].keyData = (short)uVar1;
            if (local_38[0].keyData < -0x7ff)
            {
              uVar1 = (u_int)(u_short)(local_38[0].keyData + 0x1000);
            }
            local_38[0] = (_G2AnimChanStatus_Type)((u_int)local_38[0] & 0xffff0000 | uVar1);
            if (segIndex != 0)
            {
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

void G2Anim_UpdateStoredFrame(_G2AnimSection_Type *section, _G2Anim_Type *anim)

{
  short sVar1;
  int targetKey;
  int iVar2;
  int decompressedKey;

  targetKey = (int)section->keylist->timePerKey;
  targetKey;
  sVar1 = section->keylist->timePerKey;
  targetKey;
  if ((decompressedKey < 0) || (targetKey < decompressedKey))
  {
    _G2AnimSection_InitStatus(section, anim);
    decompressedKey = -1;
  }
  iVar2 = (int)sVar1;
  FooBar(section, anim, decompressedKey, targetKey,
         iVar2);
  section->storedTime = section->elapsedTime;
  section->flags = section->flags | 0x80;
  return;
}

_G2Anim_Type *G2AnimSection_SetUnpaused(_G2AnimSection_Type *section)

{
  return (_G2Anim_Type *)((int)section - ((u_int)section->sectionID * 0x30 + 0x24));
}

void G2AnimSection_GetStoredKeyframeNumber(_G2AnimSection_Type *section, short startTime, short endTime)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  _G2AnimFxHeader_Type *p_Var4;
  _G2Anim_Type *p_Var5;
  _G2AnimKeylist_Type *p_Var6;

  p_Var6 = section->keylist;
  p_Var4 = p_Var6->fxList;
  if (p_Var4 != (_G2AnimFxHeader_Type *)0x0)
  {
    cVar1 = p_Var4->type;
    while (cVar1 != -1)
    {
      bVar2 = p_Var4->sizeAndSection;
      if (((((u_int)bVar2 & 0xf) == (u_int)section->sectionID) &&
           (((sVar3 = p_Var4->keyframeID * (u_short)p_Var6->s0TailTime, startTime < sVar3 ||
                                                                            ((sVar3 == 0 && (startTime <= sVar3)))) &&
             (sVar3 <= endTime)))) &&
          (section->callback != (_func_8 *)0x0))
      {
        p_Var5 = G2AnimSection_SetUnpaused(section);
        (*section->callback)(p_Var5, (u_int)section->sectionID, 6, (int)p_Var4->type, p_Var4 + 1,
                             section->callbackData);
      }
      p_Var4 = (_G2AnimFxHeader_Type *)(&p_Var4->sizeAndSection + (((u_int)bVar2 & 0xf0) >> 2));
      cVar1 = p_Var4->type;
    }
  }
  return;
}

void G2Anim_Free(_G2AnimChanStatusBlock_Type *block)

{
  _G2AnimChanStatusBlock_Type *p_Var1;

  if (block != (_G2AnimChanStatusBlock_Type *)0x0)
  {
    do
    {
      p_Var1 = block->next;
      G2PoolMem_InitPool(&_chanStatusBlockPool, block);
      block = p_Var1;
    } while (p_Var1 != (_G2AnimChanStatusBlock_Type *)0x0);
  }
  return;
}

long _G2AnimAlphaTable_GetValue(_G2AnimAlphaTable_Type *table, long trueAlpha)

{
  int iVar1;
  u_int uVar2;

  if (table != (_G2AnimAlphaTable_Type *)0x0)
  {
    uVar2 = ((u_int)table->size - 1) * trueAlpha;
    iVar1 = (int)uVar2 >> 0xc;
    return (int)table[iVar1 + 1] +
           ((int)(((int)table[iVar1 + 2] - (int)table[iVar1 + 1]) * (uVar2 & 0xfff)) >> 0xc);
  }
  return trueAlpha;
}
