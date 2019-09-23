#include "THISDUST.H"
#include "REAVER.H"

// short @0x800D48B8, len = 0x00000002
FireReaverFlag = null;
// decompiled code
// original method signature:
// void /*$ra*/ SoulReaverInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
// line 55, offset 0x80079d48
/* begin block 1 */
// Start line: 56
// Start offset: 0x80079D48
// Variables:
// 		struct __ReaverData *data; // $v1
/* end block 1 */
// End offset: 0x80079DD0
// End Line: 109

/* begin block 2 */
// Start line: 110
/* end block 2 */
// End Line: 111

void SoulReaverInit(_Instance *instance, GameTracker *gameTracker)

{
  char *pcVar1;

  if ((instance->flags & 0x20000U) == 0)
  {
    pcVar1 = MEMPACK_Malloc(0x24, '\x1e');
    *(char **)&instance->extraData = pcVar1;
    *(undefined2 *)(pcVar1 + 4) = 2;
    FireReaverFlag = 0;
    pcVar1[1] = '\x01';
    *(undefined4 *)(pcVar1 + 8) = 0;
    *(undefined4 *)(pcVar1 + 0xc) = 0;
    *pcVar1 = '\0';
    *(undefined2 *)(pcVar1 + 2) = 0x1000;
    *(undefined2 *)(pcVar1 + 6) = 0;
    *(undefined2 *)(pcVar1 + 0x1c) = 0x1000;
    *(undefined2 *)(pcVar1 + 0x1e) = 0x1000;
    COLLIDE_SegmentCollisionOff(instance, 0);
  }
  else
  {
    MEMPACK_Free((char *)instance->extraData);
  }
  FX_ReaverBladeInit();
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SoulReaverCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
// line 114, offset 0x80079de8
/* begin block 1 */
// Start line: 115
// Start offset: 0x80079DE8
// Variables:
// 		struct _CollideInfo *collideInfo; // $s0
// 		struct _HSphere *S; // $v0
// 		struct _Instance *target; // $s3
// 		struct __ReaverData *reaverData; // $v0

/* begin block 1.1 */
// Start line: 130
// Start offset: 0x80079E54
// Variables:
// 		long type; // $s1
/* end block 1.1 */
// End offset: 0x80079F08
// End Line: 203

/* begin block 1.2 */
// Start line: 229
// Start offset: 0x80079F18
// Variables:
// 		struct _Instance *inst; // $v1
/* end block 1.2 */
// End offset: 0x80079F18
// End Line: 229
/* end block 1 */
// End offset: 0x80079F3C
// End Line: 236

/* begin block 2 */
// Start line: 292
/* end block 2 */
// End Line: 293

void SoulReaverCollide(_Instance *instance, GameTracker *gameTracker)

{
  short sVar1;
  int Data;
  _CollideInfo *collideInfo;
  int Power;
  _Instance *lastHit;

  collideInfo = (_CollideInfo *)instance->collideInfo;
  if ((((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000) &&
       (*(char *)((int)collideInfo->prim0 + 4) == '\t')) &&
      (*(char *)((int)collideInfo->prim1 + 4) == '\b'))
  {
    lastHit = (_Instance *)collideInfo->inst1;
    COLLIDE_SegmentCollisionOff(instance, 0);
    sVar1 = *(short *)((int)instance->extraData + 4);
    Power = 0;
    if (0 < sVar1)
    {
      if (sVar1 < 3)
      {
        Power = 0x1000;
      }
      else
      {
        if (sVar1 == 6)
        {
          Power = 0x20;
        }
      }
    }
    if (instance->LinkParent != (_Instance *)0x0)
    {
      COLLIDE_SegmentCollisionOff(instance, 0);
      Data = SetMonsterHitData(instance->LinkParent, lastHit, Power, 0, 0);
      INSTANCE_Post(gameTrackerX.playerInstance, 0x100001f, Data);
      Power = SetFXHitData(instance, (uint)(byte)collideInfo->segment, 0x32, Power);
      INSTANCE_Post(lastHit, 0x400000, Power);
    }
  }
  if (collideInfo->type1 == '\x03')
  {
    COLLIDE_SetBSPTreeFlag(collideInfo, 0x800);
  }
  else
  {
    *(uint *)((int)collideInfo->inst1 + 0x14) = *(uint *)((int)collideInfo->inst1 + 0x14) | 4;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SoulReaverProcess(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
// line 240, offset 0x80079f58
/* begin block 1 */
// Start line: 241
// Start offset: 0x80079F58
// Variables:
// 		struct __ReaverData *data; // $v0
/* end block 1 */
// End offset: 0x80079F8C
// End Line: 248

/* begin block 2 */
// Start line: 555
/* end block 2 */
// End Line: 556

void SoulReaverProcess(_Instance *instance, GameTracker *gameTracker)

{
  if (*(char *)instance->extraData != '\0')
  {
    instance->currentStreamUnitID = (gameTrackerX.playerInstance)->currentStreamUnitID;
  }
  _SoulReaverAnimate(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ CollideReaverProjectile(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s4*/)
// line 256, offset 0x80079fa4
/* begin block 1 */
// Start line: 257
// Start offset: 0x80079FA4
// Variables:
// 		struct _CollideInfo *collideInfo; // $s1
// 		struct _Instance *target; // $s3
// 		long type; // $s0
// 		long reavType; // $a0

/* begin block 1.1 */
// Start line: 279
// Start offset: 0x8007A01C
// Variables:
// 		struct Level *level; // $v1
/* end block 1.1 */
// End offset: 0x8007A04C
// End Line: 288

/* begin block 1.2 */
// Start line: 342
// Start offset: 0x8007A0B0
// Variables:
// 		struct _Instance *inst; // $v1
/* end block 1.2 */
// End offset: 0x8007A0B0
// End Line: 342
/* end block 1 */
// End offset: 0x8007A0E0
// End Line: 350

/* begin block 2 */
// Start line: 587
/* end block 2 */
// End Line: 588

void CollideReaverProjectile(_Instance *instance, GameTracker *gameTracker)

{
  Level *pLVar1;
  int Data;
  int Power;
  _CollideInfo *collideInfo;
  _Instance *Inst;

  collideInfo = (_CollideInfo *)instance->collideInfo;
  Inst = (_Instance *)collideInfo->inst1;
  Data = *(int *)((int)instance->extraData + 4) + -2;
  Power = 0;
  if ((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000)
  {
    if (0 < Data)
    {
      if (Data < 3)
      {
        Power = 0x1000;
      }
      else
      {
        if (Data == 6)
        {
          Power = 0x20;
          pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
          if ((pLVar1 != (Level *)0x0) && ((int)(instance->position).z < pLVar1->waterZLevel))
          {
            return;
          }
        }
      }
    }
    if (Power != 0)
    {
      Data = SetMonsterHitData(instance, (_Instance *)0x0, Power, 0, 0);
      INSTANCE_Post(Inst, 0x1000021, Data);
      Data = SetFXHitData(instance, 1, 0x32, Power);
      INSTANCE_Post(Inst, 0x400000, Data);
    }
  }
  if (collideInfo->type1 == '\x03')
  {
    COLLIDE_SetBSPTreeFlag(collideInfo, 0x800);
  }
  else
  {
    *(uint *)((int)collideInfo->inst1 + 0x14) = *(uint *)((int)collideInfo->inst1 + 0x14) | 4;
  }
  CollidePhysicalObject(instance, gameTracker);
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ SoulReaverQuery(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
// line 354, offset 0x8007a100
/* begin block 1 */
// Start line: 357
// Start offset: 0x8007A100

/* begin block 1.1 */
// Start line: 366
// Start offset: 0x8007A148
// Variables:
// 		struct __ReaverData *reaverData; // $a0
// 		unsigned long retval; // $v1
/* end block 1.1 */
// End offset: 0x8007A17C
// End Line: 375
/* end block 1 */
// End offset: 0x8007A17C
// End Line: 381

/* begin block 2 */
// Start line: 791
/* end block 2 */
// End Line: 792

/* begin block 3 */
// Start line: 793
/* end block 3 */
// End Line: 794

ulong SoulReaverQuery(_Instance *instance, ulong query)

{
  ulong uVar1;

  if (query == 4)
  {
    return 0x1000;
  }
  if (query < 5)
  {
    if (query == 1)
    {
      return 0x20000;
    }
  }
  else
  {
    if ((query == 0x28) && (*(char *)((int)instance->extraData + 1) != '\0'))
    {
      uVar1 = 1;
      if (*(short *)((int)instance->extraData + 0x1e) != 0)
      {
        uVar1 = 3;
      }
      return uVar1;
    }
  }
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ SoulReaverImbue(struct _Instance *instance /*$a0*/, int number /*$a1*/)
// line 383, offset 0x8007a184
/* begin block 1 */
// Start line: 384
// Start offset: 0x8007A184
// Variables:
// 		long color; // $a1
// 		struct __ReaverTuneData *tuneData; // $v0
/* end block 1 */
// End offset: 0x8007A184
// End Line: 384

/* begin block 2 */
// Start line: 849
/* end block 2 */
// End Line: 850

void SoulReaverImbue(_Instance *instance, int number)

{
  FX_DoBlastRing(instance, (_SVector *)&instance->position, instance->matrix, 0, 0x140, 0, 0xf0, 0, 0,
                 -0x10000, 0, 0, 0xa0, 0x140, *(long *)((int)instance->data + number * 4 + -4), 0, 0, 0x14, 1);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SoulReaverCharge(struct _Instance *instance /*$s2*/, struct __ReaverData *data /*$s0*/)
// line 415, offset 0x8007a210
/* begin block 1 */
// Start line: 416
// Start offset: 0x8007A210
// Variables:
// 		long color; // $v1
// 		long shock; // $a0
// 		struct __ReaverTuneData *tuneData; // $s1
/* end block 1 */
// End offset: 0x8007A31C
// End Line: 461

/* begin block 2 */
// Start line: 922
/* end block 2 */
// End Line: 923

void SoulReaverCharge(_Instance *instance, __ReaverData *data)

{
  int motor1_speed;
  void *pvVar1;

  pvVar1 = instance->data;
  if (data->ReaverChargeTime != 0)
  {
    data->ReaverChargeTime = data->ReaverChargeTime - gameTrackerX.timeMult;
    if (data->ReaverShockAmount < 0x3c000)
    {
      motor1_speed = data->ReaverShockAmount + gameTrackerX.timeMult;
      data->ReaverShockAmount = motor1_speed;
      if (motor1_speed < 0)
      {
        motor1_speed = motor1_speed + 0xfff;
      }
      motor1_speed = (motor1_speed >> 0xc) + 0x32;
    }
    else
    {
      motor1_speed = 0x6e;
    }
    GAMEPAD_Shock1(motor1_speed, (int)&DAT_00005000);
    if (data->ReaverChargeTime < 1)
    {
      data->ReaverChargeTime = data->ReaverChargeTime + 0xf000;
      FX_DoBlastRing(instance, (_SVector *)&instance->position, instance->matrix, 0, 0x168, 0, 0, 0, 0,
                     -0x10000, 0, 0x140, 0x110, 0xe0,
                     *(long *)((int)pvVar1 + (int)data->CurrentReaver * 4 + -4), 0, 0, -1, 1);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ StopSoulReaverCharge(struct __ReaverData *data /*$v0*/, struct _Instance *instance /*$s0*/)
// line 463, offset 0x8007a334
/* begin block 1 */
// Start line: 1032
/* end block 1 */
// End Line: 1033

void StopSoulReaverCharge(__ReaverData *data, _Instance *instance)

{
  data->ReaverChargeTime = 0;
  data->ReaverShockAmount = 0;
  GAMEPAD_Shock1(0, 0);
  FX_EndInstanceEffects(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SoulReaverPost(struct _Instance *instance /*$s1*/, unsigned long message /*$a1*/, unsigned long data /*$s3*/)
// line 475, offset 0x8007a374
/* begin block 1 */
// Start line: 476
// Start offset: 0x8007A374
// Variables:
// 		struct __ReaverData *reaverData; // $s0

/* begin block 1.1 */
// Start line: 526
// Start offset: 0x8007A55C
// Variables:
// 		struct SVECTOR oldVector; // stack offset -40
// 		struct SVECTOR startPos; // stack offset -32

/* begin block 1.1.1 */
// Start line: 530
// Start offset: 0x8007A55C
// Variables:
// 		struct __ReaverData *reaverData; // $v0
// 		struct evObjectBirthProjectileData *pData; // $s0

/* begin block 1.1.1.1 */
// Start line: 570
// Start offset: 0x8007A5F4
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $a2
// 		struct _Position *_v0; // $v0
/* end block 1.1.1.1 */
// End offset: 0x8007A5F4
// End Line: 570

/* begin block 1.1.1.2 */
// Start line: 570
// Start offset: 0x8007A5F4
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a0
// 		short _z1; // $a1
// 		struct _Position *_v0; // $v0
/* end block 1.1.1.2 */
// End offset: 0x8007A5F4
// End Line: 570
/* end block 1.1.1 */
// End offset: 0x8007A5F4
// End Line: 570
/* end block 1.1 */
// End offset: 0x8007A5F4
// End Line: 570
/* end block 1 */
// End offset: 0x8007A6B4
// End Line: 615

/* begin block 2 */
// Start line: 1059
/* end block 2 */
// End Line: 1060

void SoulReaverPost(_Instance *instance, ulong message, ulong data)

{
  int Data;
  evObjectBirthProjectileData *peVar1;
  _Instance *p_Var2;
  __ReaverData *data_00;
  short sVar3;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  short local_20;
  short local_1e;
  short local_1c;

  data_00 = (__ReaverData *)instance->extraData;
  if (message == 0x800101)
  {
    data_00->ReaverOn = '\0';
    StopSoulReaverCharge(data_00, instance);
    instance->flags = instance->flags | 0x800;
    return;
  }
  if (message < 0x800102)
  {
    if (message == 0x800002)
    {
      if (instance->LinkParent == (_Instance *)0x0)
      {
        INSTANCE_LinkToParent(instance, (_Instance *)data, 0x29);
      }
      data_00->ReaverOn = '\x01';
      data_00->ReaverPickedUp = '\x01';
      goto LAB_8007a694;
    }
    if (message < 0x800003)
    {
      if (message == 0x200002)
      {
        COLLIDE_SegmentCollisionOn(instance, 0);
        return;
      }
      if (message != 0x200003)
      {
        return;
      }
      COLLIDE_SegmentCollisionOff(instance, 0);
      return;
    }
    if (message == 0x800010)
    {
      StopSoulReaverCharge(data_00, instance);
      local_28 = 0;
      local_26 = 0;
      local_24 = 400;
      ApplyMatrixSV(instance->matrix, &local_28, &local_20);
      local_20 = local_20 + (instance->position).x;
      local_1e = local_1e + (instance->position).y;
      local_1c = local_1c + (instance->position).z;
      peVar1 = PHYSOB_BirthProjectile(instance->LinkParent, 0, (int)*(short *)((int)instance->extraData + 4) + 2);
      if (peVar1->birthInstance == (_Instance *)0x0)
      {
        return;
      }
      peVar1->birthInstance->collideFunc = CollideReaverProjectile;
      p_Var2 = peVar1->birthInstance;
      (p_Var2->position).x = local_20;
      (p_Var2->position).y = local_1e;
      (p_Var2->position).z = local_1c;
      INSTANCE_Post(peVar1->birthInstance, 0x800010, data);
      p_Var2 = peVar1->birthInstance;
      (p_Var2->position).x = local_20;
      (p_Var2->position).y = local_1e;
      (p_Var2->position).z = local_1c;
      return;
    }
    if (message != 0x800100)
    {
      return;
    }
    data_00->ReaverOn = '\x01';
    if (data_00->ReaverTargetScale != 0)
      goto LAB_8007a694;
  }
  else
  {
    if (message == 0x800105)
    {
      StopSoulReaverCharge(data_00, instance);
      return;
    }
    sVar3 = (short)data;
    if (message < 0x800106)
    {
      if (message == 0x800103)
      {
        data_00->CurrentReaver = sVar3;
        FireReaverFlag = ZEXT12(sVar3 == 6);
        SoulReaverImbue(instance, data);
        return;
      }
      if (message != 0x800104)
      {
        return;
      }
      data_00->ReaverChargeTime = 0xf000;
      Data = SetObjectAbsorbData(instance, 0, 0x3c);
      INSTANCE_Broadcast(instance, 0x20, 0x800028, Data);
      return;
    }
    if (message != 0x800108)
    {
      if (0x800108 < message)
      {
        if (message != 0x800109)
        {
          return;
        }
        StopSoulReaverCharge(data_00, instance);
        data_00->ReaverTargetScale = 0;
        return;
      }
      if (message != 0x800107)
      {
        return;
      }
      data_00->ReaverTargetScale = sVar3;
      return;
    }
  }
  data_00->ReaverTargetScale = 0x1000;
LAB_8007a694:
  instance->flags = instance->flags & 0xfffff7ff;
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ REAVER_GetGlowColor(struct _Instance *instance /*$a0*/)
// line 617, offset 0x8007a6d0
/* begin block 1 */
// Start line: 619
// Start offset: 0x8007A6D0
// Variables:
// 		struct __ReaverTuneData *tuneData; // $v1
// 		struct __ReaverData *data; // $v0
/* end block 1 */
// End offset: 0x8007A6D0
// End Line: 623

/* begin block 2 */
// Start line: 1357
/* end block 2 */
// End Line: 1358

/* begin block 3 */
// Start line: 1358
/* end block 3 */
// End Line: 1359

/* begin block 4 */
// Start line: 1362
/* end block 4 */
// End Line: 1363

ulong REAVER_GetGlowColor(_Instance *instance)

{
  return *(ulong *)((int)instance->data + (int)*(short *)((int)instance->extraData + 4) * 4 + -4);
}

// decompiled code
// original method signature:
// void /*$ra*/ _SoulReaverAnimate(struct _Instance *instance /*$s2*/)
// line 635, offset 0x8007a6f4
/* begin block 1 */
// Start line: 636
// Start offset: 0x8007A6F4
// Variables:
// 		struct __ReaverData *data; // $s0
// 		struct __ReaverTuneData *tuneData; // $s1
/* end block 1 */
// End offset: 0x8007A88C
// End Line: 687

/* begin block 2 */
// Start line: 1398
/* end block 2 */
// End Line: 1399

void _SoulReaverAnimate(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  __ReaverData *data;
  void *pvVar4;

  data = (__ReaverData *)instance->extraData;
  pvVar4 = instance->data;
  FX_SetReaverInstance(instance);
  iVar1 = rand();
  data->ReaverDeg = data->ReaverDeg + 0x100 + ((ushort)iVar1 & 0x1f) & 0xfff;
  if (data->ReaverOn == '\x01')
  {
    if (data->ReaverSize < 0x1000)
    {
      data->ReaverSize = data->ReaverSize + 0x100;
    }
  }
  else
  {
    if (0 < data->ReaverSize)
    {
      data->ReaverSize = data->ReaverSize + -0x100;
    }
  }
  if (0 < (int)data->CurrentReaver)
  {
    data->ReaverBladeColor = *(long *)((int)pvVar4 + (int)data->CurrentReaver * 4 + 0x1c);
    data->ReaverBladeGlowColor = *(long *)((int)pvVar4 + (int)data->CurrentReaver * 4 + 0x3c);
    data->ReaverGlowColor = *(long *)((int)pvVar4 + (int)data->CurrentReaver * 4 + -4);
  }
  iVar3 = (int)data->ReaverScale;
  iVar1 = (int)data->ReaverTargetScale - iVar3;
  if (iVar1 < 0)
  {
    if (0x80 < iVar3 - (int)data->ReaverTargetScale)
    {
      iVar3 = (int)data->ReaverScale;
      goto LAB_8007a814;
    }
  }
  else
  {
    if (0x80 < iVar1)
    {
    LAB_8007a814:
      if ((int)data->ReaverTargetScale < iVar3)
      {
        data->ReaverScale = data->ReaverScale + -0x80;
      }
      if (data->ReaverScale < data->ReaverTargetScale)
      {
        data->ReaverScale = data->ReaverScale + 0x80;
      }
      goto LAB_8007a850;
    }
  }
  data->ReaverScale = data->ReaverTargetScale;
LAB_8007a850:
  if ((data->ReaverOn == '\x01') && (0 < data->ReaverScale))
  {
    uVar2 = instance->flags & 0xfffff7ff;
  }
  else
  {
    uVar2 = instance->flags | 0x800;
  }
  instance->flags = uVar2;
  SoulReaverCharge(instance, data);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ SoulReaverFire()
// line 690, offset 0x8007a8b0
/* begin block 1 */
// Start line: 1514
/* end block 1 */
// End Line: 1515

/* begin block 2 */
// Start line: 1515
/* end block 2 */
// End Line: 1516

/* WARNING: Unknown calling convention yet parameter storage is locked */

int SoulReaverFire(void)

{
  return (int)FireReaverFlag;
}
