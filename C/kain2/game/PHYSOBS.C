#include "THISDUST.H"
#include "PHYSOBS.H"

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_PlayDropSound(struct _Instance *instance /*$a0*/)
// line 208, offset 0x80068700
/* begin block 1 */
// Start line: 209
// Start offset: 0x80068700
// Variables:
// 		struct PhysObProperties *Prop; // $a1
// 		int sound; // $v1
/* end block 1 */
// End offset: 0x8006880C
// End Line: 247

/* begin block 2 */
// Start line: 416
/* end block 2 */
// End Line: 417

void PHYSOB_PlayDropSound(_Instance *instance)

{
  short sVar1;
  int sfxToneID;
  void *pvVar2;
  int pitch;
  int maxVolume;
  undefined *local_18;

  pvVar2 = instance->data;
  sVar1 = *(short *)((int)pvVar2 + 2);
  if (sVar1 == 1)
  {
    sfxToneID = (int)*(short *)((int)pvVar2 + 10);
  }
  else
  {
    if (sVar1 == 0)
    {
      sfxToneID = (int)*(char *)((int)pvVar2 + 0x13);
    }
    else
    {
      sfxToneID = 0;
      if ((sVar1 == 3) && (*(int *)((int)pvVar2 + 0x28) != 0))
      {
        sfxToneID = (int)*(char *)(*(int *)((int)pvVar2 + 0x28) + 0xb);
      }
    }
  }
  if (sfxToneID == 2)
  {
    SOUND_Play3dSound(&instance->position, 0x11a, -400, 0x5a, (int)&DAT_000036b0);
    sfxToneID = 0x11a;
    pitch = -800;
    maxVolume = 100;
    local_18 = &DAT_000036b0;
  }
  else
  {
    if (sfxToneID < 3)
    {
      if (sfxToneID != 1)
      {
        return;
      }
      sfxToneID = 10;
      pitch = -100;
    }
    else
    {
      if (sfxToneID != 3)
      {
        return;
      }
      sfxToneID = 0xb2;
      pitch = -800;
    }
    local_18 = &DAT_00007530;
    maxVolume = 0x78;
  }
  SOUND_Play3dSound(&instance->position, sfxToneID, pitch, maxVolume, (int)local_18);
  return;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ PHYSOBS_IsAPushBlockAttached(struct _Instance *block /*$s3*/)
// line 259, offset 0x80068820
/* begin block 1 */
// Start line: 260
// Start offset: 0x80068820
// Variables:
// 		struct _Instance *instance; // $s0
// 		struct _Instance *next; // $s1
// 		struct _Instance *result; // $s2
/* end block 1 */
// End offset: 0x80068888
// End Line: 280

/* begin block 2 */
// Start line: 518
/* end block 2 */
// End Line: 519

/* begin block 3 */
// Start line: 519
/* end block 3 */
// End Line: 520

_Instance *PHYSOBS_IsAPushBlockAttached(_Instance *block)

{
  _Instance *instance;
  int iVar1;
  _Instance *p_Var2;

  p_Var2 = (gameTrackerX.instanceList)->first;
  do
  {
    instance = p_Var2;
    if (instance == (_Instance *)0x0)
    {
      return (_Instance *)0x0;
    }
    p_Var2 = instance->next;
  } while ((instance->attachedID != block->introUniqueID) ||
           (iVar1 = CheckPhysObAbility(instance, 2), iVar1 == 0));
  return instance;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ PHYSOBS_IsAnythingAttached(struct _Instance *block /*$a0*/)
// line 284, offset 0x800688a8
/* begin block 1 */
// Start line: 286
// Start offset: 0x800688A8
// Variables:
// 		struct _Instance *instance; // $v1
// 		struct _Instance *next; // $a1
// 		struct _Instance *result; // $a2
/* end block 1 */
// End offset: 0x800688E8
// End Line: 303

/* begin block 2 */
// Start line: 572
/* end block 2 */
// End Line: 573

/* begin block 3 */
// Start line: 573
/* end block 3 */
// End Line: 574

_Instance *PHYSOBS_IsAnythingAttached(_Instance *block)

{
  _Instance **pp_Var1;
  _Instance *p_Var2;

  if ((gameTrackerX.instanceList)->first != (_Instance *)0x0)
  {
    p_Var2 = (gameTrackerX.instanceList)->first;
    do
    {
      pp_Var1 = &p_Var2->next;
      if (p_Var2->attachedID == block->introUniqueID)
      {
        return p_Var2;
      }
      p_Var2 = *pp_Var1;
    } while (*pp_Var1 != (_Instance *)0x0);
  }
  return (_Instance *)0x0;
}

// decompiled code
// original method signature:
// int /*$ra*/ CheckPhysOb(struct _Instance *instance /*$a0*/)
// line 307, offset 0x800688f0
/* begin block 1 */
// Start line: 309
// Start offset: 0x800688F0
// Variables:
// 		struct PhysObProperties *Prop; // $v0
/* end block 1 */
// End offset: 0x80068914
// End Line: 319

/* begin block 2 */
// Start line: 621
/* end block 2 */
// End Line: 622

/* begin block 3 */
// Start line: 622
/* end block 3 */
// End Line: 623

/* begin block 4 */
// Start line: 626
/* end block 4 */
// End Line: 627

int CheckPhysOb(_Instance *instance)

{
  if (instance->data == (void *)0x0)
  {
    return 0;
  }
  return (uint)(*(short *)((int)instance->data + 4) == -0x4ff5);
}

// decompiled code
// original method signature:
// int /*$ra*/ CheckPhysObAbility(struct _Instance *instance /*$a0*/, unsigned short ability /*$a3*/)
// line 322, offset 0x8006891c
/* begin block 1 */
// Start line: 323
// Start offset: 0x8006891C
// Variables:
// 		struct PhysObProperties *Prop; // $a2

/* begin block 1.1 */
// Start line: 335
// Start offset: 0x80068954
/* end block 1.1 */
// End offset: 0x80068978
// End Line: 339
/* end block 1 */
// End offset: 0x80068990
// End Line: 345

/* begin block 2 */
// Start line: 653
/* end block 2 */
// End Line: 654

/* begin block 3 */
// Start line: 658
/* end block 3 */
// End Line: 659

int CheckPhysObAbility(_Instance *instance, ushort ability)

{
  void *pvVar1;

  pvVar1 = instance->data;
  if (pvVar1 != (void *)0x0)
  {
    if (*(short *)((int)pvVar1 + 4) != -0x4ff5)
    {
      return 0;
    }
    if (*(short *)((int)pvVar1 + 2) == 3)
    {
      if ((*(ushort *)((int)instance->extraData + 4) & ability) == 0)
      {
        return 0;
      }
      return 1;
    }
    if ((*(ushort *)((int)pvVar1 + 6) & ability) != 0)
    {
      return 1;
    }
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ CheckPhysObFamily(struct _Instance *instance /*$a0*/, unsigned short family /*$a1*/)
// line 348, offset 0x80068998
/* begin block 1 */
// Start line: 350
// Start offset: 0x80068998
// Variables:
// 		struct PhysObProperties *Prop; // $a0
/* end block 1 */
// End offset: 0x800689D4
// End Line: 365

/* begin block 2 */
// Start line: 710
/* end block 2 */
// End Line: 711

/* begin block 3 */
// Start line: 711
/* end block 3 */
// End Line: 712

/* begin block 4 */
// Start line: 715
/* end block 4 */
// End Line: 716

int CheckPhysObFamily(_Instance *instance, ushort family)

{
  void *pvVar1;

  pvVar1 = instance->data;
  if (pvVar1 != (void *)0x0)
  {
    if (*(short *)((int)pvVar1 + 4) != -0x4ff5)
    {
      return 0;
    }
    if (*(ushort *)((int)pvVar1 + 2) == family)
    {
      return 1;
    }
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ GetPhysicalAbility(struct _Instance *instance /*$a0*/)
// line 402, offset 0x800689dc
/* begin block 1 */
// Start line: 404
// Start offset: 0x800689DC
// Variables:
// 		struct PhysObProperties *Prop; // $a1

/* begin block 1.1 */
// Start line: 413
// Start offset: 0x80068A0C
/* end block 1.1 */
// End offset: 0x80068A20
// End Line: 416
/* end block 1 */
// End offset: 0x80068A2C
// End Line: 422

/* begin block 2 */
// Start line: 818
/* end block 2 */
// End Line: 819

/* begin block 3 */
// Start line: 819
/* end block 3 */
// End Line: 820

/* begin block 4 */
// Start line: 823
/* end block 4 */
// End Line: 824

int GetPhysicalAbility(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->data;
  if ((pvVar1 != (void *)0x0) && (*(short *)((int)pvVar1 + 4) == -0x4ff5))
  {
    if (*(short *)((int)pvVar1 + 2) == 3)
    {
      return (int)*(short *)((int)instance->extraData + 4);
    }
    return (uint) * (ushort *)((int)pvVar1 + 6);
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ AnyBlocksInMotion()
// line 426, offset 0x80068a34
/* begin block 1 */
// Start line: 428
// Start offset: 0x80068A34
// Variables:
// 		struct _Instance *instance; // $a0

/* begin block 1.1 */
// Start line: 434
// Start offset: 0x80068A6C
// Variables:
// 		struct PhysObProperties *Prop; // $v1
// 		struct PhysObData *Data; // $v0
/* end block 1.1 */
// End offset: 0x80068AB4
// End Line: 445
/* end block 1 */
// End offset: 0x80068AC4
// End Line: 450

/* begin block 2 */
// Start line: 866
/* end block 2 */
// End Line: 867

/* begin block 3 */
// Start line: 867
/* end block 3 */
// End Line: 868

/* WARNING: Unknown calling convention yet parameter storage is locked */

int AnyBlocksInMotion(void)

{
  _Instance *p_Var1;

  p_Var1 = (gameTrackerX.instanceList)->first;
  while (true)
  {
    if (p_Var1 == (_Instance *)0x0)
    {
      return 0;
    }
    if (((((p_Var1->object->oflags2 & 0x40000U) != 0) &&
          ((*(ushort *)((int)p_Var1->data + 6) & 8) != 0)) &&
         (*(short *)((int)p_Var1->data + 4) == -0x4ff5)) &&
        ((*(uint *)p_Var1->extraData & 0x14e) != 0))
      break;
    p_Var1 = p_Var1->next;
  }
  return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ SetThrowDirection(struct _Instance *instance /*$s1*/, struct _Instance *parent /*$a1*/, struct evObjectThrowData *throwData /*$s2*/, struct PhysObData *Data /*$a3*/)
// line 456, offset 0x80068ad4
/* begin block 1 */
// Start line: 457
// Start offset: 0x80068AD4

/* begin block 1.1 */
// Start line: 473
// Start offset: 0x80068B58
// Variables:
// 		long val; // $a2
// 		struct _Instance *itarget; // $s0
// 		struct MATRIX *matrix; // $a1
/* end block 1.1 */
// End offset: 0x80068C58
// End Line: 503

/* begin block 1.2 */
// Start line: 511
// Start offset: 0x80068CB0
// Variables:
// 		long val; // $a1
// 		struct _Position *ptarget; // $s0
/* end block 1.2 */
// End offset: 0x80068D68
// End Line: 535
/* end block 1 */
// End offset: 0x80068E08
// End Line: 558

/* begin block 2 */
// Start line: 926
/* end block 2 */
// End Line: 927

void SetThrowDirection(_Instance *instance, _Instance *parent, evObjectThrowData *throwData,
                       PhysObData *Data)

{
  short angle;
  MATRIX *pMVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _Instance *p_Var5;
  int iVar6;

  switch (throwData->type)
  {
  case 0:
    if (parent->LinkParent == (_Instance *)0x0)
    {
      angle = (parent->rotation).z;
    }
    else
    {
      angle = (parent->LinkParent->rotation).z;
    }
    PhysicsSetVelFromZRot(instance, angle, (uint)throwData->speed);
    instance->zVel = (int)throwData->zVel;
    break;
  case 1:
    p_Var5 = *(_Instance **)&throwData->data;
    Data->Force = p_Var5;
    angle = MATH3D_AngleFromPosToPos(&instance->position, &p_Var5->position);
    PhysicsSetVelFromZRot(instance, angle, (uint)throwData->speed);
    instance->zVel = 0;
    if (p_Var5->object->modelList[(int)p_Var5->currentModel]->numSegments < 2)
    {
      pMVar1 = p_Var5->matrix;
    }
    else
    {
      pMVar1 = p_Var5->matrix + 1;
    }
    iVar4 = instance->xVel;
    iVar3 = instance->yVel;
    iVar2 = iVar4;
    if (iVar4 < 0)
    {
      iVar2 = -iVar4;
    }
    iVar6 = iVar3;
    if (iVar3 < 0)
    {
      iVar6 = -iVar3;
    }
    if (iVar6 < iVar2)
    {
      iVar2 = pMVar1->t[0] - (int)(instance->position).x;
      if (iVar4 == 0)
      {
        return;
      }
      if (iVar2 == 0)
      {
        return;
      }
      iVar6 = (instance->zAccl * iVar2) / iVar4;
      iVar4 = (pMVar1->t[2] - (int)(instance->position).z) * iVar4;
    }
    else
    {
      iVar2 = pMVar1->t[1] - (int)(instance->position).y;
      if (iVar3 == 0)
      {
        return;
      }
      if (iVar2 == 0)
      {
        return;
      }
      iVar6 = (instance->zAccl * iVar2) / iVar3;
      iVar4 = (pMVar1->t[2] - (int)(instance->position).z) * iVar3;
    }
    instance->zVel = iVar4 / iVar2 - (iVar6 >> 1);
    break;
  case 2:
    angle = MATH3D_AngleFromPosToPos(&instance->position, (_Position *)&throwData->data);
    PhysicsSetVelFromZRot(instance, angle, (uint)throwData->speed);
    iVar4 = instance->xVel;
    iVar3 = instance->yVel;
    iVar2 = iVar4;
    if (iVar4 < 0)
    {
      iVar2 = -iVar4;
    }
    iVar6 = iVar3;
    if (iVar3 < 0)
    {
      iVar6 = -iVar3;
    }
    instance->zVel = 0;
    if (iVar6 < iVar2)
    {
      iVar2 = (int)*(short *)&throwData->data - (int)(instance->position).x;
      if (iVar4 == 0)
      {
        return;
      }
      if (iVar2 == 0)
      {
        return;
      }
      iVar6 = (instance->zAccl * iVar2) / iVar4;
      iVar4 = ((int)*(short *)((int)&throwData->data + 4) - (int)(instance->position).z) * iVar4;
    }
    else
    {
      iVar2 = (int)*(short *)((int)&throwData->data + 2) - (int)(instance->position).y;
      if (iVar3 == 0)
      {
        return;
      }
      if (iVar2 == 0)
      {
        return;
      }
      iVar6 = (instance->zAccl * iVar2) / iVar3;
      iVar4 = ((int)*(short *)((int)&throwData->data + 4) - (int)(instance->position).z) * iVar3;
    }
    instance->zVel = iVar4 / iVar2 - (iVar6 >> 1);
    break;
  case 3:
    PhysicsSetVelFromRot(instance, (_Rotation *)&throwData->data, (uint)throwData->speed);
    break;
  case 4:
    instance->xVel = (int)*(short *)&throwData->data;
    instance->yVel = (int)*(short *)((int)&throwData->data + 2);
    instance->zVel = (int)*(short *)((int)&throwData->data + 4);
    instance->zAccl = (int)throwData->gravity;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ThrowPhysOb(struct _Instance *instance /*$s3*/, struct evObjectThrowData *throwData /*$s0*/)
// line 564, offset 0x80068e20
/* begin block 1 */
// Start line: 565
// Start offset: 0x80068E20
// Variables:
// 		struct PhysObData *Data; // $s2
// 		int collFlg; // $s4
// 		int endAnimFlg; // $s6

/* begin block 1.1 */
// Start line: 574
// Start offset: 0x80068E5C
// Variables:
// 		struct _Instance *parent; // $s5
// 		struct PhysObProperties *Prop; // $s1

/* begin block 1.1.1 */
// Start line: 611
// Start offset: 0x80068F4C
// Variables:
// 		struct _SVector *sv; // $v1
/* end block 1.1.1 */
// End offset: 0x80068F78
// End Line: 617

/* begin block 1.1.2 */
// Start line: 630
// Start offset: 0x80068FA8
// Variables:
// 		struct __PhysObProjectileData *ProjData; // $s0

/* begin block 1.1.2.1 */
// Start line: 647
// Start offset: 0x8006901C
/* end block 1.1.2.1 */
// End offset: 0x8006903C
// End Line: 650
/* end block 1.1.2 */
// End offset: 0x80069044
// End Line: 654

/* begin block 1.1.3 */
// Start line: 672
// Start offset: 0x80069090
// Variables:
// 		struct _PCollideInfo pcollideInfo; // stack offset -96
// 		struct _Position newPos; // stack offset -48
// 		struct _Position oldPos; // stack offset -40
// 		struct MATRIX *mat; // $v0

/* begin block 1.1.3.1 */
// Start line: 697
// Start offset: 0x80069128
// Variables:
// 		short _x0; // $a2
// 		short _y0; // $a3
// 		short _z0; // $t0
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a0
/* end block 1.1.3.1 */
// End offset: 0x80069128
// End Line: 697

/* begin block 1.1.3.2 */
// Start line: 697
// Start offset: 0x80069128
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		struct _Position *_v; // $a1
/* end block 1.1.3.2 */
// End offset: 0x80069128
// End Line: 697
/* end block 1.1.3 */
// End offset: 0x80069128
// End Line: 697
/* end block 1.1 */
// End offset: 0x800691D8
// End Line: 724
/* end block 1 */
// End offset: 0x800691D8
// End Line: 729

/* begin block 2 */
// Start line: 1147
/* end block 2 */
// End Line: 1148

void ThrowPhysOb(_Instance *instance, evObjectThrowData *throwData)

{
  bool bVar1;
  short sVar2;
  MATRIX *pMVar3;
  uint uVar4;
  uint uVar5;
  _Instance *parent;
  int NewAnim;
  int iVar6;
  void *pvVar7;
  PhysObData *Data;
  _PCollideInfo local_60;
  SVECTOR local_30;
  SVECTOR local_28;

  parent = instance->LinkParent;
  bVar1 = false;
  if (parent != (_Instance *)0x0)
  {
    pvVar7 = instance->data;
    Data = (PhysObData *)instance->extraData;
    instance->flags2 = instance->flags2 | 0x4000;
    Data->Force = (_Instance *)0x0;
    Data->physObTimer = 0x96000;
    if (throwData == (evObjectThrowData *)0x0)
    {
      throwData = (evObjectThrowData *)
          SetObjectThrowData((void *)0x0, (_SVector *)0x0, 0, 0, 0x180, 0, 0x40, -0x400);
    }
    INSTANCE_UnlinkFromParent(instance);
    SetThrowDirection(instance, parent, throwData, Data);
    instance->zAccl = (int)throwData->gravity;
    sVar2 = throwData->spinType;
    if (sVar2 == 1)
    {
      Data->throwFlags = Data->throwFlags | 1;
    }
    else
    {
      if (sVar2 < 2)
      {
        if (sVar2 == 0)
        {
          Data->xRotVel = 0;
          Data->yRotVel = 0;
          Data->zRotVel = 0;
          Data->throwFlags = Data->throwFlags & 0xfffe;
        }
      }
      else
      {
        if (sVar2 == 2)
        {
          Data->xRotVel = (throwData->angularVel).x;
          Data->yRotVel = (throwData->angularVel).y;
          sVar2 = (throwData->angularVel).z;
          Data->throwFlags = Data->throwFlags & 0xfffe;
          Data->zRotVel = sVar2;
        }
      }
    }
    Data->Mode = Data->Mode & 0xffffff7eU | 0x1010;
    sVar2 = throwData->initialXRot;
    Data->throwingInstance = parent;
    Data->initialXRot = sVar2;
    if (*(short *)((int)pvVar7 + 2) == 7)
    {
      iVar6 = *(int *)((int)pvVar7 + 0xc) + *(int *)((int)instance->extraData + 4) * 0xc;
      NewAnim = (int)*(char *)(iVar6 + 2);
      if (NewAnim != -1)
      {
        G2EmulationInstanceSetAnimation(instance, 0, NewAnim, 0, 0);
        G2EmulationInstanceSetMode(instance, 0, 2);
      }
      bVar1 = *(char *)(iVar6 + 3) != -1;
      if (instance->currentModel == 0)
      {
        FX_EndFField(instance);
        FX_StartGenericParticle(instance, 0, 0, 0, 0);
      }
      ExecuteThrow(instance);
    }
    NewAnim = PHYSOB_CheckThrownLineCollision(instance, parent);
    instance->flags2 = instance->flags2 | 0x80;
    if (NewAnim != 0)
    {
      instance->xVel = 0;
      instance->yVel = 0;
      instance->zVel = 0;
      instance->zAccl = 0;
      iVar6 = CheckPhysObAbility(instance, 0x200);
      if ((iVar6 == 0) || (NewAnim != 1))
      {
        uVar5 = 0xffffffef;
        if (bVar1)
        {
          uVar4 = Data->Mode | 0x1000;
        }
        else
        {
          uVar4 = Data->Mode;
          uVar5 = 0xffffefff;
        }
        Data->Mode = uVar4 & uVar5;
      }
      else
      {
        Data->Mode = Data->Mode | 0x1000;
        instance->flags2 = instance->flags2 & 0xffffff7f;
        Data->Mode = Data->Mode & 0xffffffef;
        pMVar3 = instance->matrix;
        local_28.vx = *(short *)pMVar3[2].t;
        local_28.vy = *(short *)(pMVar3[2].t + 1);
        local_30.vz = *(short *)(pMVar3[2].t + 2);
        local_30.vx = (parent->position).x;
        local_60.newPoint = &local_30;
        local_30.vy = (parent->position).y;
        local_60.oldPoint = &local_28;
        local_28.vz = local_30.vz;
        PHYSICS_CheckLineInWorld(instance, &local_60);
        if (local_60.type == 3)
        {
          local_28.vx = local_30.vx - local_28.vx;
          local_28.vy = local_30.vy - local_28.vy;
          local_28.vz = local_30.vz - local_28.vz;
          (instance->position).x = (instance->position).x + local_28.vx;
          (instance->position).y = (instance->position).y + local_28.vy;
          (instance->position).z = (instance->position).z + local_28.vz;
        }
      }
    }
    if ((Data->Mode & 0x10U) != 0)
    {
      if (NewAnim == 0)
      {
        PhysicsMove(instance, &instance->position, gameTrackerX.timeMult);
      }
      TurnOnCollisionPhysOb(instance, 4);
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ PushPhysOb(struct _Instance *instance /*$s1*/, short x /*stack -32*/, short y /*stack -30*/, short PathNumber /*$a3*/, struct _Instance *Force /*stack 16*/)
// line 733, offset 0x80069200
/* begin block 1 */
// Start line: 734
// Start offset: 0x80069200
// Variables:
// 		struct PhysObData *Data; // $s0
// 		struct PhysObProperties *Prop; // $v1
// 		int result; // $s2
/* end block 1 */
// End offset: 0x8006933C
// End Line: 784

/* begin block 2 */
// Start line: 1536
/* end block 2 */
// End Line: 1537

int PushPhysOb(_Instance *instance, short x, short y, short PathNumber, _Instance *Force)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  short local_20;
  short local_1e[3];

  uVar3 = 0;
  if (((*(ushort *)((int)instance->data + 6) & 8) != 0) &&
      (uVar3 = 0, *(short *)((int)instance->data + 4) == -0x4ff5))
  {
    puVar2 = (uint *)instance->extraData;
    uVar3 = 0;
    if ((*puVar2 & 0x214a) == 0)
    {
      local_20 = x;
      local_1e[0] = y;
      iVar1 = AnyBlocksInMotion();
      uVar3 = 0;
      if (iVar1 == 0)
      {
        PHYSOB_NormalToAxis(&local_20, local_1e);
        *(_Instance **)(puVar2 + 2) = Force;
        *(short *)(puVar2 + 10) = PathNumber;
        *(short *)(puVar2 + 1) = local_20;
        *(short *)((int)puVar2 + 6) = local_1e[0];
        *puVar2 = *puVar2 & 0xfffffff7;
        instance->zVel = 0;
        instance->yVel = 0;
        instance->xVel = 0;
        instance->zAccl = 0;
        instance->yAccl = 0;
        instance->xAccl = 0;
        uVar3 = PHYSOBS_CheckForValidMove(instance);
        if ((uVar3 & 1) != 0)
        {
          if ((*puVar2 & 0x100) == 0)
          {
            *(short *)((int)puVar2 + 0xe) = (instance->position).x;
            *(short *)(puVar2 + 4) = (instance->position).y;
            *(short *)((int)puVar2 + 0x12) = (instance->position).z;
          }
          *puVar2 = *puVar2 | 0x1000;
          instance->flags2 = instance->flags2 | 8;
        }
      }
    }
  }
  return uVar3;
}

// decompiled code
// original method signature:
// void /*$ra*/ ResetSwitchPhysOb(struct _Instance *instance /*$s0*/)
// line 788, offset 0x8006935c
/* begin block 1 */
// Start line: 789
// Start offset: 0x8006935C
// Variables:
// 		struct PhysObData *Data; // $v1
// 		struct PhysObSwitchProperties *Prop; // $a1
/* end block 1 */
// End offset: 0x800693E4
// End Line: 809

/* begin block 2 */
// Start line: 1682
/* end block 2 */
// End Line: 1683

void ResetSwitchPhysOb(_Instance *instance)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;

  iVar2 = CheckPhysObFamily(instance, 2);
  if (iVar2 != 0)
  {
    pvVar3 = instance->data;
    *(uint *)instance->extraData = *(uint *)instance->extraData | 0x800;
    if (((*(ushort *)((int)instance->extraData + 4) & 2) != 0) &&
        (bVar1 = *(byte *)((int)pvVar3 + 0x10), bVar1 != 0))
    {
      G2EmulationInstanceSetAnimation(instance, 0, (uint)bVar1, 0, 0);
      G2EmulationInstanceSetMode(instance, 0, 1);
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ SwitchPhysOb(struct _Instance *instance /*$s1*/)
// line 813, offset 0x800693f4
/* begin block 1 */
// Start line: 814
// Start offset: 0x800693F4
// Variables:
// 		struct PhysObData *Data; // $v0
// 		struct PhysObSwitchProperties *Prop; // $s0
// 		struct SwitchData *switchData; // $s3
/* end block 1 */
// End offset: 0x800695B4
// End Line: 874

/* begin block 2 */
// Start line: 1734
/* end block 2 */
// End Line: 1735

int SwitchPhysOb(_Instance *instance)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  void *pvVar6;

  pvVar5 = instance->data;
  iVar2 = CheckPhysObFamily(instance, 2);
  iVar3 = 1;
  if (iVar2 != 0)
  {
    *(uint *)instance->extraData = *(uint *)instance->extraData | 0x800;
    pvVar6 = instance->extraData;
    uVar1 = *(ushort *)((int)pvVar6 + 4);
    if ((uVar1 & 1) == 0)
    {
      if ((uVar1 & 2) == 0)
      {
        if (*(byte *)((int)pvVar5 + 0xe) != 0xff)
        {
          G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar5 + 0xe), 0, 0);
        }
      }
      else
      {
        *(ushort *)((int)pvVar6 + 4) = uVar1 | 5;
        G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar5 + 0xc), 0, 0);
        if (*(short *)((int)pvVar5 + 10) == 7)
        {
          *(undefined2 *)((int)pvVar6 + 6) = 0x400;
        }
        else
        {
          *(undefined2 *)((int)pvVar6 + 6) = 0;
        }
        uVar4 = instance->flags;
        (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar6 + 6);
        instance->flags = uVar4 | 8;
      }
      G2EmulationInstanceSetMode(instance, 0, 1);
    }
    else
    {
      if ((uVar1 & 2) == 0)
      {
        if (*(byte *)((int)pvVar5 + 0xf) != 0xff)
        {
          G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar5 + 0xf), 0, 0);
          G2EmulationInstanceSetMode(instance, 0, 1);
          *(ushort *)((int)pvVar6 + 4) = *(ushort *)((int)pvVar6 + 4) | 2;
        }
      }
      else
      {
        *(ushort *)((int)pvVar6 + 4) = uVar1 & 0xfffe | 8;
        G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar5 + 0xd), 0, 0);
        G2EmulationInstanceSetMode(instance, 0, 1);
        (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar6 + 6);
        if (*(short *)((int)pvVar5 + 10) == 7)
        {
          *(undefined2 *)((int)pvVar6 + 6) = 0x400;
        }
        else
        {
          *(undefined2 *)((int)pvVar6 + 6) = 0;
        }
        instance->flags = instance->flags | 8;
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}

// decompiled code
// original method signature:
// int /*$ra*/ InteractPhysOb(struct _Instance *instance /*$s1*/, struct _Instance *Force /*$s3*/, int LinkNode /*$s7*/, int Action /*$s4*/)
// line 878, offset 0x800695d0
/* begin block 1 */
// Start line: 879
// Start offset: 0x800695D0
// Variables:
// 		struct PhysObData *Data; // $s5
// 		struct PhysObInteractProperties *interactProp; // $s2

/* begin block 1.1 */
// Start line: 889
// Start offset: 0x8006961C
// Variables:
// 		struct BreakOffData *BreakOff; // $s6

/* begin block 1.1.1 */
// Start line: 900
// Start offset: 0x80069690
// Variables:
// 		struct _Instance *lightInst; // $s0
/* end block 1.1.1 */
// End offset: 0x800696A8
// End Line: 906

/* begin block 1.1.2 */
// Start line: 912
// Start offset: 0x800696D0
// Variables:
// 		struct _Instance *lightInst; // $s0
/* end block 1.1.2 */
// End offset: 0x80069700
// End Line: 921

/* begin block 1.1.3 */
// Start line: 958
// Start offset: 0x80069820
// Variables:
// 		int s; // $s0
/* end block 1.1.3 */
// End offset: 0x80069870
// End Line: 963

/* begin block 1.1.4 */
// Start line: 963
// Start offset: 0x80069878
// Variables:
// 		int s; // $s0
/* end block 1.1.4 */
// End offset: 0x800698C8
// End Line: 969
/* end block 1.1 */
// End offset: 0x80069904
// End Line: 987
/* end block 1 */
// End offset: 0x80069904
// End Line: 989

/* begin block 2 */
// Start line: 1873
/* end block 2 */
// End Line: 1874

int InteractPhysOb(_Instance *instance, _Instance *Force, int LinkNode, int Action)

{
  int Mode;
  uint *puVar1;
  uint uVar2;
  _PhysObLight *pLight;
  byte bVar3;
  _Model **pp_Var4;
  _Instance *instance_00;
  void *pvVar5;

  pvVar5 = instance->data;
  Mode = CheckPhysObFamily(instance, 3);
  if (Mode == 0)
  {
    return 1;
  }
  puVar1 = (uint *)instance->extraData;
  if (*(char *)((int)pvVar5 + 0x14) != -1)
  {
    if (Action == 2)
    {
      instance_00 = Force->LinkChild;
      Mode = CheckPhysOb(instance_00);
      if (Mode != 0)
      {
        pLight = PhysObGetLight(instance_00);
        PHYSOB_StartBurning(instance_00, pLight);
      }
    }
    else
    {
      if (Action < 3)
      {
        if (Action == 1)
        {
          uVar2 = *puVar1;
          *puVar1 = uVar2 & 0xfffffffe | 0x1080;
          if ((uVar2 & 0x10000) != 0)
          {
            instance_00 = Force->LinkChild;
            pLight = PhysObGetLight(instance_00);
            PHYSOB_StartLighting(instance_00, pLight);
          }
          *(undefined2 *)(puVar1 + 1) = *(undefined2 *)((int)pvVar5 + 0x18);
          *(undefined2 *)((int)puVar1 + 6) = *(undefined2 *)((int)pvVar5 + 0x1a);
          INSTANCE_LinkToParent(instance, Force, LinkNode);
        }
      }
      else
      {
        if (Action == 9)
        {
          INSTANCE_Post(instance, (int)&DAT_00040002, 5);
        }
      }
    }
    if (Action == (uint) * (ushort *)((int)pvVar5 + 0xc))
    {
      instance->flags = instance->flags | 8;
    }
    if (Action == (uint) * (ushort *)((int)pvVar5 + 0xe))
    {
      instance->flags = instance->flags | 0x10;
    }
  }
  if ((*(byte *)((int)pvVar5 + 0x11) == 0xff) || ((*(ushort *)((int)pvVar5 + 6) & 0x8000) == 0))
    goto LAB_800697f4;
  G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar5 + 0x11), 0, 0);
  bVar3 = *(byte *)((int)pvVar5 + 0x15) & 0x30;
  if (bVar3 == 0x10)
  {
    Mode = 1;
  LAB_800697ec:
    G2EmulationInstanceSetMode(instance, 0, Mode);
  }
  else
  {
    if (bVar3 < 0x11)
    {
      if ((*(byte *)((int)pvVar5 + 0x15) & 0x30) == 0)
      {
        Mode = 2;
        goto LAB_800697ec;
      }
    }
    else
    {
      if (bVar3 == 0x20)
      {
        Mode = 0;
        goto LAB_800697ec;
      }
    }
  }
LAB_800697f4:
  pp_Var4 = instance->object->modelList;
  if (pp_Var4 != (_Model **)0x0)
  {
    if ((*(byte *)((int)pvVar5 + 0x15) & 0x80) == 0)
    {
      Mode = 0;
      if (0 < (*pp_Var4)->numSegments)
      {
        do
        {
          COLLIDE_SegmentCollisionOn(instance, Mode);
          Mode = Mode + 1;
        } while (Mode < (*instance->object->modelList)->numSegments);
      }
    }
    else
    {
      Mode = 0;
      if (0 < (*pp_Var4)->numSegments)
      {
        do
        {
          COLLIDE_SegmentCollisionOff(instance, Mode);
          Mode = Mode + 1;
        } while (Mode < (*instance->object->modelList)->numSegments);
        puVar1[2] = 0;
        goto LAB_800698cc;
      }
    }
  }
  puVar1[2] = 0;
LAB_800698cc:
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)(puVar1 + 1) = *(undefined2 *)((int)pvVar5 + 0x18);
  *(undefined2 *)((int)puVar1 + 6) = *(undefined2 *)((int)pvVar5 + 0x1a);
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ ResetOrientation(struct _Instance *instance /*$s1*/)
// line 989, offset 0x80069930
/* begin block 1 */
// Start line: 990
// Start offset: 0x80069930
// Variables:
// 		struct _G2EulerAngles_Type ea; // stack offset -40
// 		struct PhysObData *Data; // $a1
// 		struct _G2SVector3_Type vec; // stack offset -32
// 		struct _G2SVector3_Type vec2; // stack offset -24
// 		int dp; // $a0
// 		int fixxy; // $a2
// 		int fixz; // $a3
// 		int dx; // $v1
// 		int dx2; // $v0
// 		int dy; // $v0
// 		int dy2; // $v1
// 		int dz; // $v0
// 		int dz2; // $v1

/* begin block 1.1 */
// Start line: 1119
// Start offset: 0x80069BC0
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a1
// 		short _y1; // $a3
// 		short _z1; // $a2
// 		struct _G2SVector3_Type *_v; // $a1
// 		struct _G2EulerAngles_Type *_v0; // $a0
// 		struct _G2SVector3_Type *_v1; // $a2
/* end block 1.1 */
// End offset: 0x80069BC0
// End Line: 1119

/* begin block 1.2 */
// Start line: 1121
// Start offset: 0x80069D04
// Variables:
// 		short _x0; // $v1
// 		short _y0; // $v0
// 		short _z0; // $a0
// 		short _x1; // $t0
// 		short _y1; // $a2
// 		short _z1; // $a1
// 		struct _G2SVector3_Type *_v; // $a3
// 		struct _G2SVector3_Type *_v1; // $a1
/* end block 1.2 */
// End offset: 0x80069D04
// End Line: 1121
/* end block 1 */
// End offset: 0x80069E04
// End Line: 1145

/* begin block 2 */
// Start line: 2115
/* end block 2 */
// End Line: 2116

void ResetOrientation(_Instance *instance)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  _G2EulerAngles_Type local_28;
  _G2SVector3_Type local_20;
  ushort local_18;
  ushort local_16;
  ushort local_14;

  G2Anim_DisableController(&instance->anim, 0, 0x4c);
  pvVar5 = instance->extraData;
  iVar4 = (int)(instance->position).x - (int)*(short *)((int)pvVar5 + 0xe);
  if (iVar4 != 0)
  {
    if (iVar4 < 1)
    {
      iVar4 = iVar4 + -0x140;
    }
    else
    {
      iVar4 = iVar4 + 0x140;
    }
    (instance->position).x = *(short *)((int)pvVar5 + 0xe) + (short)(iVar4 / 0x280) * 0x280;
  }
  iVar4 = (int)(instance->position).y - (int)*(short *)((int)pvVar5 + 0x10);
  if (iVar4 != 0)
  {
    if (iVar4 < 1)
    {
      sVar1 = (short)((iVar4 + -0x140) / 0x280);
    }
    else
    {
      sVar1 = (short)((iVar4 + 0x140) / 0x280);
    }
    (instance->position).y = *(short *)((int)pvVar5 + 0x10) + sVar1 * 0x280;
  }
  iVar4 = (int)(instance->position).z - (int)*(short *)((int)pvVar5 + 0x12);
  if (iVar4 != 0)
  {
    if (iVar4 < 0)
    {
      sVar1 = (short)((iVar4 + -0x50) / 0xa0);
    }
    else
    {
      sVar1 = (short)((iVar4 + 0x50) / 0xa0);
    }
    (instance->position).z = *(short *)((int)pvVar5 + 0x12) + sVar1 * 0xa0;
  }
  *(short *)((int)pvVar5 + 0xe) = (instance->position).x;
  *(short *)((int)pvVar5 + 0x10) = (instance->position).y;
  *(short *)((int)pvVar5 + 0x12) = (instance->position).z;
  G2EulerAngles_FromMatrix(&local_28, (_G2Matrix_Type *)(instance->matrix + 2), 0x15);
  iVar4 = (int)(short)local_28.x;
  if (iVar4 < 0)
  {
    local_18 = (ushort)(iVar4 + -0x200) & 0xfc00;
    if (iVar4 + -0x200 < 0)
    {
      sVar1 = 0x1ff;
    LAB_80069b4c:
      local_18 = local_28.x + sVar1 & 0xfc00;
    }
  }
  else
  {
    local_18 = (ushort)(iVar4 + 0x200) & 0xfc00;
    if (iVar4 + 0x200 < 0)
    {
      sVar1 = 0x5ff;
      goto LAB_80069b4c;
    }
  }
  iVar4 = (int)local_28.y;
  if (iVar4 < 0)
  {
    local_16 = (ushort)(iVar4 + -0x200) & 0xfc00;
    if (iVar4 + -0x200 < 0)
    {
      sVar1 = 0x1ff;
    LAB_80069b84:
      local_16 = local_28.y + sVar1 & 0xfc00;
    }
  }
  else
  {
    local_16 = (ushort)(iVar4 + 0x200) & 0xfc00;
    if (iVar4 + 0x200 < 0)
    {
      sVar1 = 0x5ff;
      goto LAB_80069b84;
    }
  }
  iVar4 = (int)local_28.z;
  if (iVar4 < 0)
  {
    local_14 = (ushort)(iVar4 + -0x200) & 0xfc00;
    if (-1 < iVar4 + -0x200)
      goto LAB_80069bc0;
    sVar1 = 0x1ff;
  }
  else
  {
    local_14 = (ushort)(iVar4 + 0x200) & 0xfc00;
    if (-1 < iVar4 + 0x200)
      goto LAB_80069bc0;
    sVar1 = 0x5ff;
  }
  local_14 = local_28.z + sVar1 & 0xfc00;
LAB_80069bc0:
  iVar4 = (int)(((uint)local_28.x - (uint)local_18) * 0x10000) >> 0x10;
  if (iVar4 < 0)
  {
    iVar4 = iVar4 + -0x96;
  }
  else
  {
    iVar4 = iVar4 + 0x96;
  }
  iVar2 = (int)(short)(local_28.y - local_16);
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + -0x96;
  }
  else
  {
    iVar2 = iVar2 + 0x96;
  }
  iVar3 = (int)(short)(local_28.z - local_14);
  if (iVar3 < 0)
  {
    iVar3 = iVar3 + -0x96;
  }
  else
  {
    iVar3 = iVar3 + 0x96;
  }
  local_20.x = (short)(iVar4 / 0x12d) * 0x12d + local_18;
  local_20.y = (short)(iVar2 / 0x12d) * 0x12d + local_16;
  local_20.z = (short)(iVar3 / 0x12d) * 0x12d + local_14;
  iVar4 = (int)(short)local_20.x - (int)(short)local_28.x;
  iVar2 = (int)(short)local_18 - (int)(short)local_28.x;
  if (iVar4 < 0)
  {
    iVar4 = -iVar4;
  }
  if (iVar2 < 0)
  {
    iVar2 = -iVar2;
  }
  if (iVar2 < iVar4)
  {
    local_20.x = local_18;
  }
  iVar4 = (int)(short)local_20.y - (int)local_28.y;
  iVar2 = (int)(short)local_16 - (int)local_28.y;
  if (iVar4 < 0)
  {
    iVar4 = -iVar4;
  }
  if (iVar2 < 0)
  {
    iVar2 = -iVar2;
  }
  if (iVar2 < iVar4)
  {
    local_20.y = local_16;
  }
  iVar4 = (int)(short)local_20.z - (int)local_28.z;
  iVar2 = (int)(short)local_14 - (int)local_28.z;
  if (iVar4 < 0)
  {
    iVar4 = -iVar4;
  }
  if (iVar2 < 0)
  {
    iVar2 = -iVar2;
  }
  if (iVar2 < iVar4)
  {
    local_20.z = local_14;
  }
  G2Anim_SetController_Vector(&instance->anim, 2, 0xe, &local_20);
  G2Instance_RebuildTransforms(instance);
  G2Anim_SwitchToKeylist(&instance->anim, *instance->object->animList, 0);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FinishPush(struct _Instance *instance /*$a0*/)
// line 1154, offset 0x80069e4c
/* begin block 1 */
// Start line: 2501
/* end block 1 */
// End Line: 2502

void FinishPush(_Instance *instance)

{
  ResetOrientation(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysOb_AlignPush(struct _Instance *instance /*$s4*/, int x /*$s5*/, int y /*$s3*/, int path /*$s6*/, struct PhysObData *Data /*stack 16*/)
// line 1160, offset 0x80069e6c
/* begin block 1 */
// Start line: 1161
// Start offset: 0x80069E6C
// Variables:
// 		struct _G2SVector3_Type vec; // stack offset -96
// 		int rotZ; // $s2
// 		short temp[3][3]; // stack offset -88
// 		short temp2[3][3]; // stack offset -64
// 		struct _G2EulerAngles_Type ea; // stack offset -40
/* end block 1 */
// End offset: 0x80069F04
// End Line: 1189

/* begin block 2 */
// Start line: 2513
/* end block 2 */
// End Line: 2514

void PhysOb_AlignPush(_Instance *instance, int x, int y, int path, PhysObData *Data)

{
  _G2Anim_Type *anim;
  short sVar1;
  _G2SVector3_Type local_60;
  uint auStack88[6];
  undefined auStack64[24];
  short local_28;
  short local_26;
  short local_24;

  G2Anim_EnableController(&instance->anim, 0, 0x4c);
  G2Anim_EnableController(&instance->anim, 2, 0xe);
  sVar1 = 0x800;
  Data->xForce = (short)x;
  Data->yForce = (short)y;
  Data->PathNumber = (short)path;
  Data->Mode = Data->Mode & 0xffefffff;
  if (((y < 1) && (sVar1 = 0, -1 < y)) && (sVar1 = 0x400, x < 0))
  {
    sVar1 = -0x400;
  }
  anim = &instance->anim;
  local_60.x = 0;
  local_60.y = 0;
  local_60.z = sVar1;
  G2Anim_SetController_Vector(anim, 0, 0x4c, &local_60);
  local_60.z = -sVar1;
  RotMatrixZYX((ushort *)&local_60, auStack88);
  MulMatrix0(auStack88, (ushort *)(instance->matrix + 2), (uint *)(_G2Matrix_Type *)auStack64);
  G2EulerAngles_FromMatrix((_G2EulerAngles_Type *)(auStack64 + 0x18), (_G2Matrix_Type *)auStack64, 0x15);
  local_60.x = local_28;
  local_60.y = local_26;
  local_60.z = local_24;
  G2Anim_SetController_Vector(anim, 2, 0xe, &local_60);
  G2Anim_SwitchToKeylist(anim, instance->object->animList[path], path);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ FlipPhysOb(struct _Instance *instance /*$s1*/, short x /*stack -32*/, short y /*stack -30*/, struct _Instance *Force /*$s3*/)
// line 1206, offset 0x80069fdc
/* begin block 1 */
// Start line: 1207
// Start offset: 0x80069FDC
// Variables:
// 		struct PhysObData *Data; // $s0
// 		struct PhysObProperties *Prop; // $v0
// 		int result; // $s2
/* end block 1 */
// End offset: 0x8006A100
// End Line: 1253

/* begin block 2 */
// Start line: 2634
/* end block 2 */
// End Line: 2635

int FlipPhysOb(_Instance *instance, short x, short y, _Instance *Force)

{
  short sVar1;
  _Instance *p_Var2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  short local_20;
  short local_1e[3];

  uVar5 = 0;
  if ((*(ushort *)((int)instance->data + 6) & 2) != 0)
  {
    local_20 = x;
    local_1e[0] = y;
    p_Var2 = PHYSOBS_IsAPushBlockAttached(instance);
    uVar5 = 0;
    if (p_Var2 == (_Instance *)0x0)
    {
      puVar4 = (uint *)instance->extraData;
      uVar5 = 0;
      if ((*puVar4 & 0x2000) == 0)
      {
        iVar3 = AnyBlocksInMotion();
        uVar5 = 0;
        if (iVar3 == 0)
        {
          PHYSOB_NormalToAxis(&local_20, local_1e);
          *(undefined2 *)(puVar4 + 10) = 1;
          *(_Instance **)(puVar4 + 2) = Force;
          *puVar4 = *puVar4 | 8;
          *(short *)(puVar4 + 1) = local_20;
          *(short *)((int)puVar4 + 6) = local_1e[0];
          instance->zVel = 0;
          instance->yVel = 0;
          instance->xVel = 0;
          instance->zAccl = 0;
          instance->yAccl = 0;
          instance->xAccl = 0;
          ResetOrientation(instance);
          uVar5 = PHYSOBS_CheckForValidMove(instance);
          if ((uVar5 & 1) != 0)
          {
            *(short *)((int)puVar4 + 0xe) = (instance->position).x;
            *(short *)(puVar4 + 4) = (instance->position).y;
            sVar1 = (instance->position).z;
            *puVar4 = *puVar4 | 0x1000;
            *(short *)((int)puVar4 + 0x12) = sVar1;
            instance->flags2 = instance->flags2 | 8;
          }
        }
      }
    }
  }
  return uVar5;
}

// decompiled code
// original method signature:
// int /*$ra*/ CanBePickedUp(struct _Instance *instance /*$s1*/, struct _Instance *Force /*$s0*/, int LinkNode /*$s2*/)
// line 1296, offset 0x8006a120
/* begin block 1 */
// Start line: 1297
// Start offset: 0x8006A120

/* begin block 1.1 */
// Start line: 1320
// Start offset: 0x8006A19C
// Variables:
// 		struct _PCollideInfo pcollideInfo; // stack offset -80
// 		struct _Position newPos; // stack offset -32
// 		struct _Position oldPos; // stack offset -24

/* begin block 1.1.1 */
// Start line: 1343
// Start offset: 0x8006A268
/* end block 1.1.1 */
// End offset: 0x8006A29C
// End Line: 1352
/* end block 1.1 */
// End offset: 0x8006A29C
// End Line: 1354
/* end block 1 */
// End offset: 0x8006A2A0
// End Line: 1358

/* begin block 2 */
// Start line: 2847
/* end block 2 */
// End Line: 2848

int CanBePickedUp(_Instance *instance, _Instance *Force, int LinkNode)

{
  int iVar1;
  long lVar2;
  _PCollideInfo local_50;
  SVECTOR local_20;
  SVECTOR local_18;

  if (Force == (_Instance *)0x0)
  {
    return 0;
  }
  if (((Force->object->oflags2 & 0x80000U) == 0) && (Force->matrix != (MATRIX *)0x0))
  {
    iVar1 = CheckPhysObAbility(instance, 1);
    if (iVar1 == 0)
    {
      return 0;
    }
    if (instance->matrix != (MATRIX *)0x0)
    {
      local_18.vx = *(short *)instance->matrix[2].t;
      local_18.vy = *(short *)(instance->matrix[2].t + 1);
      local_18.vz = *(short *)(instance->matrix[2].t + 2);
      local_20.vx = *(short *)Force->matrix[LinkNode].t;
      local_20.vy = *(short *)(Force->matrix[LinkNode].t + 1);
      local_20.vz = *(short *)(Force->matrix[LinkNode].t + 2);
      local_50.newPoint = &local_20;
      local_50.oldPoint = &local_18;
      iVar1 = CheckPhysObAbility(instance, 0x20);
      if ((iVar1 != 0) && (local_20.vz < local_18.vz))
      {
        return 1;
      }
      PHYSICS_CheckLineInWorld(instance, &local_50);
      if (1 < local_50.type)
      {
        lVar2 = MATH3D_LengthXYZ((int)local_20.vx - (int)local_18.vx,
                                 (int)local_20.vy - (int)local_18.vy,
                                 (int)local_20.vz - (int)local_18.vz);
        if (0x14 < lVar2)
        {
          return 0;
        }
        return 1;
      }
    }
  }
  return 1;
}

// decompiled code
// original method signature:
// int /*$ra*/ PickUpPhysOb(struct _Instance *instance /*$s1*/, short Steps /*$a1*/, struct _Instance *Force /*$s3*/, int LinkNode /*$s4*/)
// line 1361, offset 0x8006a2b8
/* begin block 1 */
// Start line: 1362
// Start offset: 0x8006A2B8
// Variables:
// 		struct PhysObData *Data; // $s0

/* begin block 1.1 */
// Start line: 1402
// Start offset: 0x8006A374
// Variables:
// 		struct _PhysObLight *pLight; // $v0
/* end block 1.1 */
// End offset: 0x8006A38C
// End Line: 1408
/* end block 1 */
// End offset: 0x8006A398
// End Line: 1414

/* begin block 2 */
// Start line: 2996
/* end block 2 */
// End Line: 2997

int PickUpPhysOb(_Instance *instance, short Steps, _Instance *Force, int LinkNode)

{
  int iVar1;
  _PhysObLight *pLight;
  uint *puVar2;

  puVar2 = (uint *)instance->extraData;
  if (instance->LinkParent == (_Instance *)0x0)
  {
    if ((*puVar2 & 0x2000000) != 0)
    {
      return 1;
    }
    TurnOffCollisionPhysOb(instance, 7);
    iVar1 = CanBePickedUp(instance, Force, LinkNode);
    if (iVar1 != 0)
    {
      *(short *)(puVar2 + 9) = Steps;
      *(undefined2 *)((int)puVar2 + 0x26) = 0;
      *(_Instance **)(puVar2 + 2) = Force;
      *(short *)(puVar2 + 3) = (short)LinkNode;
      *puVar2 = *puVar2 & 0xff9fffff | 0x4000;
      iVar1 = CheckPhysObAbility(instance, 0x20);
      if (iVar1 != 0)
      {
        if ((*puVar2 & 0x10000) == 0)
        {
          return 0;
        }
        pLight = PhysObGetLight(instance);
        if (pLight != (_PhysObLight *)0x0)
        {
          PHYSOB_StartLighting(instance, pLight);
        }
      }
      return 0;
    }
  }
  return 1;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ PHYSOB_BirthCollectible(struct _Instance *parent /*$a0*/, int x /*$s1*/, int y /*$s2*/, int z /*$s3*/, int type /*stack 16*/, int lifeTime /*stack 20*/)
// line 1443, offset 0x8006a3b8
/* begin block 1 */
// Start line: 1444
// Start offset: 0x8006A3B8
// Variables:
// 		struct Object *object; // $a1
// 		struct _Instance *instance; // $a2

/* begin block 1.1 */
// Start line: 1457
// Start offset: 0x8006A424
/* end block 1.1 */
// End offset: 0x8006A448
// End Line: 1466
/* end block 1 */
// End offset: 0x8006A448
// End Line: 1469

/* begin block 2 */
// Start line: 2886
/* end block 2 */
// End Line: 2887

_Instance *PHYSOB_BirthCollectible(_Instance *parent, int x, int y, int z, int type, int lifeTime)

{
  Object *object;
  _Instance *p_Var1;

  p_Var1 = (_Instance *)0x0;
  object = (Object *)ObjectAccess_800c8844.object;
  if (type != 0)
  {
    object = (Object *)ObjectAccess_800c884c.object;
  }
  if ((object != (Object *)0x0) &&
      (p_Var1 = INSTANCE_BirthObject(parent, object, 0), p_Var1 != (_Instance *)0x0))
  {
    *(int *)((int)p_Var1->extraData + 4) = lifeTime * 0x1e000;
    p_Var1->fadeValue = 0x1000;
    (p_Var1->position).x = (short)x;
    (p_Var1->position).y = (short)y;
    (p_Var1->position).z = (short)z;
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// struct evObjectBirthProjectileData * /*$ra*/ PHYSOB_BirthProjectile(struct _Instance *parent /*$s0*/, int joint /*$s1*/, int type /*$s2*/)
// line 1473, offset 0x8006a468
/* begin block 1 */
// Start line: 1474
// Start offset: 0x8006A468
// Variables:
// 		struct evObjectBirthProjectileData *rc; // $s0
/* end block 1 */
// End offset: 0x8006A468
// End Line: 1474

/* begin block 2 */
// Start line: 3226
/* end block 2 */
// End Line: 3227

evObjectBirthProjectileData *PHYSOB_BirthProjectile(_Instance *parent, int joint, int type)

{
  evObjectBirthProjectileData *peVar1;
  _Instance *p_Var2;

  peVar1 = (evObjectBirthProjectileData *)SetObjectBirthProjectileData(parent, joint, type);
  p_Var2 = BirthProjectilePhysOb(parent, joint, type);
  peVar1->birthInstance = p_Var2;
  return peVar1;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ BirthProjectilePhysOb(struct _Instance *instance /*$s3*/, int grabJoint /*$s4*/, int type /*$s1*/)
// line 1484, offset 0x8006a4c0
/* begin block 1 */
// Start line: 1485
// Start offset: 0x8006A4C0
// Variables:
// 		struct Object *ForceOb; // $a1
// 		struct _Instance *iForce; // $s0
// 		struct PhysObData *Data; // $s2
// 		struct PhysObProperties *Prop; // $s1

/* begin block 1.1 */
// Start line: 1499
// Start offset: 0x8006A50C
// Variables:
// 		struct __PhysObProjectileProperties *ProjProp; // $v1
// 		struct __PhysObProjectileData *ProjData; // $v1

/* begin block 1.1.1 */
// Start line: 1514
// Start offset: 0x8006A550
// Variables:
// 		struct _Position offset; // stack offset -32
// 		struct _FXForceFieldEffect *field; // $v1
/* end block 1.1.1 */
// End offset: 0x8006A598
// End Line: 1522

/* begin block 1.1.2 */
// Start line: 1535
// Start offset: 0x8006A5CC
// Variables:
// 		struct __PhysObProjectileData *ProjData; // $v1
/* end block 1.1.2 */
// End offset: 0x8006A620
// End Line: 1547
/* end block 1.1 */
// End offset: 0x8006A670
// End Line: 1569
/* end block 1 */
// End offset: 0x8006A674
// End Line: 1578

/* begin block 2 */
// Start line: 3248
/* end block 2 */
// End Line: 3249

_Instance *BirthProjectilePhysOb(_Instance *instance, int grabJoint, int type)

{
  _FXForceFieldEffect *p_Var1;
  void *pvVar2;
  char *pcVar3;
  int NewAnim;
  _Instance *instance_00;
  undefined4 *puVar4;
  _Position local_20;

  instance_00 = (_Instance *)0x0;
  if ((ObjectAccess_800c8814.object != (void *)0x0) &&
      (instance_00 = INSTANCE_BirthObject(instance, (Object *)ObjectAccess_800c8814.object, 0),
       instance_00 != (_Instance *)0x0))
  {
    pvVar2 = instance_00->data;
    *(int *)((int)instance_00->extraData + 4) = type;
    pcVar3 = (char *)(*(int *)((int)pvVar2 + 0xc) + type * 0xc);
    instance_00->currentModel = (short)*pcVar3;
    puVar4 = (undefined4 *)instance_00->extraData;
    if (*pcVar3 == '\0')
    {
      local_20.x = 0;
      local_20.y = 0;
      local_20.z = 0;
      p_Var1 = FX_StartFField(instance_00, 0x78, &local_20, 0x20, 0x10, 0x80, 0x202020);
      if (p_Var1 != (_FXForceFieldEffect *)0x0)
      {
        p_Var1->type = '\x01';
      }
    }
    INSTANCE_LinkToParent(instance_00, instance, grabJoint);
    TurnOffCollisionPhysOb(instance_00, 7);
    pvVar2 = instance_00->data;
    if ((*(short *)((int)pvVar2 + 2) == 7) &&
        (NewAnim = (int)*(char *)(*(int *)((int)pvVar2 + 0xc) +
                                  *(int *)((int)instance_00->extraData + 4) * 0xc + 1),
         NewAnim != -1))
    {
      G2EmulationInstanceSetAnimation(instance_00, 0, NewAnim, 0, 0);
      G2EmulationInstanceSetMode(instance_00, 0, 2);
    }
    if ((*(ushort *)((int)pvVar2 + 6) & 1) == 0)
    {
      puVar4[0x11] = 0x96000;
    }
    else
    {
      *puVar4 = 0x1080;
      puVar4[2] = 0;
      *(undefined2 *)((int)puVar4 + 0x26) = 0;
      *(undefined2 *)(puVar4 + 9) = 0;
      instance_00->xVel = 0;
      instance_00->yVel = 0;
      instance_00->zVel = 0;
      instance_00->xAccl = 0;
      instance_00->yAccl = 0;
      instance_00->zAccl = 0;
    }
  }
  return instance_00;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_SetLightTable(struct _PhysObLight *pLight /*$a0*/, struct LightInstance *li /*$a1*/, short burnAmplitude /*$a2*/)
// line 1606, offset 0x8006a694
/* begin block 1 */
// Start line: 1609
// Start offset: 0x8006A694
// Variables:
// 		long idx; // $a3
// 		long frac; // $t2
// 		struct LightTableEntry *ltable; // $t1
// 		struct LightTableEntry *ltable2; // $a0
/* end block 1 */
// End offset: 0x8006A744
// End Line: 1629

/* begin block 2 */
// Start line: 3507
/* end block 2 */
// End Line: 3508

/* begin block 3 */
// Start line: 3509
/* end block 3 */
// End Line: 3510

/* begin block 4 */
// Start line: 3513
/* end block 4 */
// End Line: 3514

void PHYSOB_SetLightTable(_PhysObLight *pLight, LightInstance *li, short burnAmplitude)

{
  int iVar1;
  LightTableEntry *pLVar2;
  LightTableEntry *pLVar3;
  uint uVar4;
  uint uVar5;

  uVar5 = (int)((uint)(ushort)gameTrackerX.vblCount * (int)pLight->speed) %
          ((uint)pLight->length << 0xc);
  pLVar2 = pLight->lightTable;
  uVar4 = uVar5 & 0xfff;
  iVar1 = (int)uVar5 >> 0xc;
  uVar5 = iVar1 + 1;
  pLVar3 = pLVar2 + iVar1;
  if (uVar5 == (uint)pLight->length)
  {
    uVar5 = 0;
  }
  li->segment = pLight->segment;
  pLVar2 = pLVar2 + uVar5;
  iVar1 = ((int)(((uint)(ushort)pLVar3->radius +
                  ((int)(((int)pLVar2->radius - (int)pLVar3->radius) * uVar4) >> 0xc)) *
                 0x10000) >>
           0x10) *
              (int)burnAmplitude >>
          0xc;
  li->radius = (short)iVar1;
  if (iVar1 << 0x10 < 1)
  {
    li->radius = 1;
  }
  li->r = (int)(short)((int)((int)pLVar3->r * 0x1000 + ((int)pLVar2->r - (int)pLVar3->r) * uVar4) /
                       (int)li->radius);
  li->g = (int)(short)((int)((int)pLVar3->g * 0x1000 + ((int)pLVar2->g - (int)pLVar3->g) * uVar4) /
                       (int)li->radius);
  li->b = (int)(short)((int)((int)pLVar3->b * 0x1000 + ((int)pLVar2->b - (int)pLVar3->b) * uVar4) /
                       (int)li->radius);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_EndLighting(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a1*/)
// line 1635, offset 0x8006a7fc
/* begin block 1 */
// Start line: 1639
// Start offset: 0x8006A7FC

/* begin block 1.1 */
// Start line: 1641
// Start offset: 0x8006A804
/* end block 1.1 */
// End offset: 0x8006A818
// End Line: 1651
/* end block 1 */
// End offset: 0x8006A818
// End Line: 1652

/* begin block 2 */
// Start line: 3571
/* end block 2 */
// End Line: 3572

/* begin block 3 */
// Start line: 3574
/* end block 3 */
// End Line: 3575

void PHYSOB_EndLighting(_Instance *instance, _PhysObLight *pLight)

{
  if ((pLight != (_PhysObLight *)0x0) &&
      (gameTrackerX.gameData.asmData.lightInstances[0].lightInstance == instance))
  {
    gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_StartLighting(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a3*/)
// line 1654, offset 0x8006a820
/* begin block 1 */
// Start line: 1655
// Start offset: 0x8006A820
// Variables:
// 		struct PhysObData *Data; // $a2

/* begin block 1.1 */
// Start line: 1670
// Start offset: 0x8006A860
// Variables:
// 		struct LightInstance *li; // $a1
/* end block 1.1 */
// End offset: 0x8006A87C
// End Line: 1684
/* end block 1 */
// End offset: 0x8006A87C
// End Line: 1685

/* begin block 2 */
// Start line: 3609
/* end block 2 */
// End Line: 3610

void PHYSOB_StartLighting(_Instance *instance, _PhysObLight *pLight)

{
  uint *puVar1;

  puVar1 = (uint *)instance->extraData;
  if (*(short *)(puVar1 + 0xd) < 0)
  {
    *(short *)(puVar1 + 0xd) = -*(short *)(puVar1 + 0xd);
  }
  *puVar1 = *puVar1 | 0x18000;
  if (pLight != (_PhysObLight *)0x0)
  {
    gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = instance;
    PHYSOB_SetLightTable(pLight, gameTrackerX.gameData.asmData.lightInstances, *(short *)(puVar1 + 0xd));
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_StartBurnFX(struct _Instance *instance /*$s2*/)
// line 1687, offset 0x8006a88c
/* begin block 1 */
// Start line: 1688
// Start offset: 0x8006A88C
// Variables:
// 		struct PhysObData *Data; // $v0
// 		struct Object *object; // $s1
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8006A900
// End Line: 1704

/* begin block 2 */
// Start line: 3678
/* end block 2 */
// End Line: 3679

void PHYSOB_StartBurnFX(_Instance *instance)

{
  int iVar1;
  int iVar2;
  Object *pOVar3;

  pOVar3 = instance->object;
  if (((*(short *)((int)instance->extraData + 0x34) == 0) && (pOVar3->numberOfEffects != 0)) &&
      (iVar2 = 0, 0 < pOVar3->numberOfEffects))
  {
    iVar1 = 0;
    do
    {
      FX_StartInstanceEffect(instance, (ObjectEffect *)(&pOVar3->effectList->effectNumber + iVar1), 1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (iVar2 < (int)pOVar3->numberOfEffects);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_StartBurning(struct _Instance *instance /*$s0*/, struct _PhysObLight *pLight /*$s1*/)
// line 1706, offset 0x8006a918
/* begin block 1 */
// Start line: 3722
/* end block 1 */
// End Line: 3723

void PHYSOB_StartBurning(_Instance *instance, _PhysObLight *pLight)

{
  PHYSOB_StartBurnFX(instance);
  PHYSOB_StartLighting(instance, pLight);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_StopLighting(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a1*/)
// line 1714, offset 0x8006a954
/* begin block 1 */
// Start line: 1716
// Start offset: 0x8006A954
// Variables:
// 		struct PhysObData *Data; // $v0
/* end block 1 */
// End offset: 0x8006A954
// End Line: 1716

/* begin block 2 */
// Start line: 3738
/* end block 2 */
// End Line: 3739

/* begin block 3 */
// Start line: 3739
/* end block 3 */
// End Line: 3740

void PHYSOB_StopLighting(_Instance *instance, _PhysObLight *pLight)

{
  uint *puVar1;

  puVar1 = (uint *)instance->extraData;
  *(undefined2 *)(puVar1 + 0xd) = 0xf000;
  *puVar1 = *puVar1 | 0x8000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_StopBurning(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a1*/)
// line 1726, offset 0x8006a974
/* begin block 1 */
// Start line: 1728
// Start offset: 0x8006A974
// Variables:
// 		struct PhysObData *Data; // $a0
/* end block 1 */
// End offset: 0x8006A974
// End Line: 1730

/* begin block 2 */
// Start line: 3763
/* end block 2 */
// End Line: 3764

/* begin block 3 */
// Start line: 3764
/* end block 3 */
// End Line: 3765

/* begin block 4 */
// Start line: 3766
/* end block 4 */
// End Line: 3767

void PHYSOB_StopBurning(_Instance *instance, _PhysObLight *pLight)

{
  uint *puVar1;

  puVar1 = (uint *)instance->extraData;
  *(undefined2 *)(puVar1 + 0xd) = 0xf000;
  *puVar1 = *puVar1 | 0x48000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_EndBurning(struct _Instance *instance /*$s0*/, struct _PhysObLight *pLight /*$s2*/)
// line 1738, offset 0x8006a998
/* begin block 1 */
// Start line: 1739
// Start offset: 0x8006A998
// Variables:
// 		struct PhysObData *Data; // $s1
/* end block 1 */
// End offset: 0x8006A998
// End Line: 1739

/* begin block 2 */
// Start line: 3790
/* end block 2 */
// End Line: 3791

void PHYSOB_EndBurning(_Instance *instance, _PhysObLight *pLight)

{
  uint *puVar1;

  puVar1 = (uint *)instance->extraData;
  FX_EndInstanceEffects(instance);
  PHYSOB_EndLighting(instance, pLight);
  *(undefined2 *)(puVar1 + 0xd) = 0;
  *puVar1 = *puVar1 & 0xfffeffff;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ StopPhysOb(struct _Instance *instance /*$a0*/)
// line 1756, offset 0x8006a9f8
/* begin block 1 */
// Start line: 1757
// Start offset: 0x8006A9F8
// Variables:
// 		struct PhysObData *Data; // $s0
/* end block 1 */
// End offset: 0x8006A9F8
// End Line: 1757

/* begin block 2 */
// Start line: 3827
/* end block 2 */
// End Line: 3828

void StopPhysOb(_Instance *instance)

{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)instance->extraData;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)((int)puVar1 + 0x1a) = 1;
  ResetOrientation(instance);
  *puVar1 = 1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ InitPhysicalObject(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s5*/)
// line 1779, offset 0x8006aa34
/* begin block 1 */
// Start line: 1780
// Start offset: 0x8006AA34
// Variables:
// 		struct PhysObData *Data; // $s3
// 		struct PhysObProperties *Prop; // $s4

/* begin block 1.1 */
// Start line: 1788
// Start offset: 0x8006AA6C
// Variables:
// 		struct PhysObInteractProperties *interactProp; // $v0
/* end block 1.1 */
// End offset: 0x8006AAD8
// End Line: 1803

/* begin block 1.2 */
// Start line: 1957
// Start offset: 0x8006AC70
// Variables:
// 		struct PhysObCollectibleProperties *collectibleProp; // $s0
/* end block 1.2 */
// End offset: 0x8006AD24
// End Line: 1976

/* begin block 1.3 */
// Start line: 1984
// Start offset: 0x8006AD58
// Variables:
// 		struct PhysObInteractProperties *interact; // $s1

/* begin block 1.3.1 */
// Start line: 2004
// Start offset: 0x8006ADE0
// Variables:
// 		int s; // $s0
/* end block 1.3.1 */
// End offset: 0x8006AE30
// End Line: 2009

/* begin block 1.3.2 */
// Start line: 2009
// Start offset: 0x8006AE38
// Variables:
// 		int s; // $s0
/* end block 1.3.2 */
// End offset: 0x8006AE88
// End Line: 2015
/* end block 1.3 */
// End offset: 0x8006AF5C
// End Line: 2041

/* begin block 1.4 */
// Start line: 2055
// Start offset: 0x8006AFB4
// Variables:
// 		struct _G2SVector3_Type vec; // stack offset -80
// 		struct _G2Matrix_Type mat; // stack offset -72
// 		struct _G2EulerAngles_Type ea; // stack offset -40
/* end block 1.4 */
// End offset: 0x8006AFB4
// End Line: 2055

/* begin block 1.5 */
// Start line: 2093
// Start offset: 0x8006B0E0
// Variables:
// 		struct SwitchData *switchData; // $s1
// 		struct PhysObSwitchProperties *switchProp; // $s0
/* end block 1.5 */
// End offset: 0x8006B188
// End Line: 2117

/* begin block 1.6 */
// Start line: 2131
// Start offset: 0x8006B1C0
// Variables:
// 		struct _PhysObLight *pLight; // $a1

/* begin block 1.6.1 */
// Start line: 2134
// Start offset: 0x8006B1D4
// Variables:
// 		struct INICommand *index; // $s0
/* end block 1.6.1 */
// End offset: 0x8006B234
// End Line: 2147
/* end block 1.6 */
// End offset: 0x8006B234
// End Line: 2149
/* end block 1 */
// End offset: 0x8006B28C
// End Line: 2166

/* begin block 2 */
// Start line: 3558
/* end block 2 */
// End Line: 3559

void InitPhysicalObject(_Instance *instance, GameTracker *gameTracker)

{
  int segment;
  uint *puVar1;
  ulong uVar2;
  uint uVar3;
  INICommand *pIVar4;
  _PhysObLight *pLight;
  byte bVar5;
  short sVar6;
  _Model **pp_Var7;
  void *pvVar8;
  _G2Anim_Type *anim;
  void *pvVar9;
  _G2SVector3_Type local_50;
  _G2Matrix_Type _Stack72;
  _G2EulerAngles_Type local_28;

  if ((instance->flags & 0x20000U) != 0)
  {
    if (*(short *)((int)instance->data + 0x1c) == 2)
    {
      segment = SetObjectIdleData(0, (_Instance *)0x0);
      INSTANCE_Post(gameTracker->playerInstance, 0x800024, segment);
    }
    segment = CheckPhysObAbility(instance, 8);
    if (segment != 0)
    {
      G2Anim_DetachControllerFromSeg(&instance->anim, 0, 0x4c);
      G2Anim_DetachControllerFromSeg(&instance->anim, 2, 0xe);
    }
    MEMPACK_Free((char *)instance->extraData);
    return;
  }
  pvVar9 = instance->data;
  puVar1 = (uint *)MEMPACK_Malloc(0x48, '\x1a');
  *(uint **)&instance->extraData = puVar1;
  *puVar1 = 1;
  *(undefined2 *)((int)puVar1 + 0x1a) = 0x1001;
  *(undefined2 *)((int)puVar1 + 0x22) = 0x1002;
  *(undefined2 *)((int)puVar1 + 0x2a) = 0xffff;
  *(undefined2 *)(puVar1 + 0xd) = 0x1000;
  *(undefined2 *)(puVar1 + 1) = 0;
  *(undefined2 *)((int)puVar1 + 6) = 0;
  puVar1[2] = 0;
  *(undefined2 *)((int)puVar1 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined2 *)((int)puVar1 + 0x12) = 0;
  *(undefined2 *)(puVar1 + 5) = 0;
  *(undefined2 *)((int)puVar1 + 0x16) = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)(puVar1 + 7) = 0;
  *(undefined2 *)((int)puVar1 + 0x1e) = 0;
  *(undefined2 *)(puVar1 + 8) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  instance->maxXVel = 0x280;
  instance->maxYVel = 0x280;
  instance->maxZVel = 0x280;
  *(undefined2 *)((int)puVar1 + 0x3a) = 0;
  *(undefined2 *)(puVar1 + 0xf) = 0;
  *(undefined2 *)((int)puVar1 + 0x3e) = 0;
  if ((instance->object != (Object *)0x0) && ((instance->object->oflags & 1U) == 0))
  {
    *puVar1 = *puVar1 | 0x1000;
  }
  if ((*(ushort *)((int)pvVar9 + 6) & 0x40) != 0)
  {
    *(ushort *)((int)pvVar9 + 6) = *(ushort *)((int)pvVar9 + 6) | 0x8000;
    instance->flags2 = instance->flags2 | 4;
  }
  if ((*(ushort *)((int)pvVar9 + 6) & 0x8000) != 0)
  {
    G2EmulationInstanceSetTotalSections(instance, 1);
    G2EmulationInstanceSetStartAndEndSegment(instance, 0, 0,
                                             (short)(((uint) * (ushort *)&instance->object->modelList[(int)instance->currentModel]->numSegments - 1) * 0x10000 >> 0x10));
    G2EmulationInstanceSetAnimation(instance, 0, 0, 0, 0);
    G2EmulationInstanceSetMode(instance, 0, 2);
  }
  if (*(short *)((int)pvVar9 + 2) == 5)
  {
    pvVar8 = instance->data;
    G2EmulationInstanceInitSection(instance, 0, PhysobAnimCallback, instance);
    if (*(byte *)((int)pvVar8 + 0x10) != 0xff)
    {
      G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar8 + 0x10), 0, 0);
      G2EmulationInstanceSetMode(instance, 0, 2);
    }
    sVar6 = *(short *)((int)pvVar8 + 8);
    if ((sVar6 == 2) && (gameTrackerX.playerInstance != (_Instance *)0x0))
    {
      uVar2 = INSTANCE_Query(gameTrackerX.playerInstance, 0x24);
      if ((uVar2 & 0xfc0000) == 0)
      {
        instance->flags = instance->flags | 0x20;
      }
      sVar6 = *(short *)((int)pvVar8 + 8);
    }
    if (sVar6 != 3)
    {
      instance->flags2 = instance->flags2 | 0x20000;
    }
  }
  if ((*(ushort *)((int)pvVar9 + 6) & 0x8d00) != 0)
  {
    *puVar1 = *puVar1 | 0x1000;
  }
  if (*(short *)((int)pvVar9 + 2) != 3)
  {
    segment = CheckPhysObAbility(instance, 1);
    if (segment == 0)
    {
      segment = CheckPhysObAbility(instance, 8);
      if (segment == 0)
      {
        segment = CheckPhysObAbility(instance, 0x40);
        if (segment != 0)
        {
          pvVar8 = instance->data;
          pvVar9 = instance->extraData;
          instance->flags2 = instance->flags2 | 4;
          *(ushort *)((int)pvVar9 + 4) = (ushort) * (byte *)((int)pvVar8 + 0x18);
          *(undefined2 *)((int)pvVar9 + 6) = 0;
          if (*(char *)((int)pvVar8 + 0x19) == -1)
          {
            *(undefined *)((int)pvVar8 + 0x19) = 0;
          }
          G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar8 + 0x19), 0, 0);
          G2EmulationInstanceInitSection(instance, 0, PhysobAnimCallback, instance);
          if (*(short *)((int)pvVar8 + 10) == 7)
          {
            *(undefined2 *)((int)pvVar9 + 6) = 0x400;
            G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar8 + 0x19), 0x5a, 0);
            G2EmulationInstanceSetMode(instance, 0, 1);
            G2EmulationInstancePlayAnimation(instance);
          }
        }
        segment = CheckPhysObFamily(instance, 7);
        if (segment != 0)
        {
          G2EmulationInstanceInitSection(instance, 0, PhysobAnimCallback, instance);
          instance->flags2 = instance->flags2 | 0x20000;
        }
      }
      else
      {
        instance->object->oflags = instance->object->oflags | 0x40000;
        *(short *)((int)puVar1 + 0xe) = (instance->position).x;
        *(short *)(puVar1 + 4) = (instance->position).y;
        *(short *)((int)puVar1 + 0x12) = (instance->position).z;
        instance->lightMatrix = 2;
        instance->object->oflags = instance->object->oflags | 0x400;
        G2EmulationInstanceInitSection(instance, 0, PhysobAnimCallback, instance);
        anim = &instance->anim;
        G2Anim_AttachControllerToSeg(anim, 0, 0x4c);
        G2Anim_AttachControllerToSeg(anim, 2, 0xe);
        G2Anim_DisableController(anim, 0, 0x4c);
        G2Anim_EnableController(anim, 2, 0xe);
        local_50.x = (instance->rotation).x;
        local_50.y = (instance->rotation).y;
        local_50.z = (instance->rotation).z;
        RotMatrixZYX((ushort *)&local_50, (uint *)&_Stack72);
        G2EulerAngles_FromMatrix(&local_28, &_Stack72, 0x15);
        local_50.x = local_28.x;
        local_50.y = local_28.y;
        local_50.z = local_28.z;
        (instance->rotation).x = 0;
        (instance->rotation).y = 0;
        (instance->rotation).z = 0;
        G2Anim_SetController_Vector(anim, 2, 0xe, &local_50);
      }
    }
    else
    {
      TurnOffCollisionPhysOb(instance, 7);
    }
    goto LAB_8006b1c4;
  }
  pvVar8 = instance->extraData;
  *(ushort *)((int)pvVar8 + 4) = *(ushort *)((int)pvVar9 + 6) | 0x80;
  *(undefined2 *)((int)pvVar8 + 6) = 0;
  pvVar8 = instance->data;
  if ((*(ushort *)((int)pvVar8 + 0x18) & 0x80) == 0)
  {
    if ((*(ushort *)((int)pvVar8 + 0x18) & 1) == 0)
    {
      uVar3 = instance->flags2 | 4;
      goto LAB_8006adb0;
    }
  }
  else
  {
    uVar3 = instance->flags2 | 0x20000;
  LAB_8006adb0:
    instance->flags2 = uVar3;
  }
  pp_Var7 = instance->object->modelList;
  if (pp_Var7 != (_Model **)0x0)
  {
    if ((*(byte *)((int)pvVar8 + 0x15) & 8) == 0)
    {
      segment = 0;
      if (0 < (*pp_Var7)->numSegments)
      {
        do
        {
          COLLIDE_SegmentCollisionOn(instance, segment);
          segment = segment + 1;
        } while (segment < (*instance->object->modelList)->numSegments);
      }
    }
    else
    {
      segment = 0;
      if (0 < (*pp_Var7)->numSegments)
      {
        do
        {
          COLLIDE_SegmentCollisionOff(instance, segment);
          segment = segment + 1;
        } while (segment < (*instance->object->modelList)->numSegments);
      }
    }
  }
  TurnOffCollisionPhysOb(instance, 7);
  if ((*(ushort *)((int)pvVar9 + 6) & 0x8000) == 0)
    goto LAB_8006af14;
  bVar5 = *(byte *)((int)pvVar8 + 0x15) & 3;
  if (bVar5 == 1)
  {
    segment = 1;
  LAB_8006af0c:
    G2EmulationInstanceSetMode(instance, 0, segment);
  }
  else
  {
    if (bVar5 < 2)
    {
      if ((*(byte *)((int)pvVar8 + 0x15) & 3) == 0)
      {
        segment = 2;
        goto LAB_8006af0c;
      }
    }
    else
    {
      if (bVar5 == 2)
      {
        segment = 0;
        goto LAB_8006af0c;
      }
    }
  }
LAB_8006af14:
  if ((*(byte *)((int)pvVar8 + 0x10) != 0xff) && ((*(ushort *)((int)pvVar9 + 6) & 0x8000) != 0))
  {
    G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar8 + 0x10), 0, 0);
  }
  if (*(short *)((int)pvVar8 + 0x1c) == 2)
  {
    segment = SetObjectIdleData(1, instance);
    INSTANCE_Post(gameTracker->playerInstance, 0x800024, segment);
  }
LAB_8006b1c4:
  segment = CheckPhysObAbility(instance, 0x20);
  if (segment != 0)
  {
    pIVar4 = INSTANCE_FindIntroCommand(instance, 0x15);
    pLight = PhysObGetLight(instance);
    if ((pLight == (_PhysObLight *)0x0) ||
        ((pIVar4 != (INICommand *)0x0 && (((uint)pIVar4[1] & 1) != 0))))
    {
      PHYSOB_EndBurning(instance, pLight);
    }
    else
    {
      *(undefined2 *)(puVar1 + 0xd) = 0;
      PHYSOB_StartBurnFX(instance);
      *puVar1 = *puVar1 | 0x10000;
    }
  }
  instance->flags = instance->flags | 0x10000;
  segment = CheckPhysObFamily(instance, 6);
  if (segment != 0)
  {
    instance->flags2 = instance->flags2 | 0x20000;
  }
  segment = CheckPhysObFamily(instance, 0);
  if (segment != 0)
  {
    instance->flags2 = instance->flags2 | 0x100;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessPhysicalObject(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s5*/)
// line 2172, offset 0x8006b2b0
/* begin block 1 */
// Start line: 2173
// Start offset: 0x8006B2B0
// Variables:
// 		struct PhysObData *Data; // $s1

/* begin block 1.1 */
// Start line: 2182
// Start offset: 0x8006B2E8
// Variables:
// 		struct _PhysObLight *pLight; // $a0

/* begin block 1.1.1 */
// Start line: 2189
// Start offset: 0x8006B2FC
// Variables:
// 		struct LightInstance *li; // $a1
/* end block 1.1.1 */
// End offset: 0x8006B344
// End Line: 2195
/* end block 1.1 */
// End offset: 0x8006B344
// End Line: 2196

/* begin block 1.2 */
// Start line: 2224
// Start offset: 0x8006B404
// Variables:
// 		struct PhysObWeaponProperties *properties; // $v0

/* begin block 1.2.1 */
// Start line: 2230
// Start offset: 0x8006B434
// Variables:
// 		struct _PhysObLight *pLight; // $a1
/* end block 1.2.1 */
// End offset: 0x8006B46C
// End Line: 2237
/* end block 1.2 */
// End offset: 0x8006B46C
// End Line: 2237

/* begin block 1.3 */
// Start line: 2254
// Start offset: 0x8006B4CC
/* end block 1.3 */
// End offset: 0x8006B570
// End Line: 2274

/* begin block 1.4 */
// Start line: 2279
// Start offset: 0x8006B584
// Variables:
// 		struct PhysObAnimatedProperties *Prop; // $v0
/* end block 1.4 */
// End offset: 0x8006B5D4
// End Line: 2287

/* begin block 1.5 */
// Start line: 2291
// Start offset: 0x8006B5E8
/* end block 1.5 */
// End offset: 0x8006B630
// End Line: 2304

/* begin block 1.6 */
// Start line: 2358
// Start offset: 0x8006B738
// Variables:
// 		struct PhysObCollectibleProperties *collectibleProp; // $a2
/* end block 1.6 */
// End offset: 0x8006B788
// End Line: 2365

/* begin block 1.7 */
// Start line: 2370
// Start offset: 0x8006B79C
// Variables:
// 		struct Level *level; // $s2

/* begin block 1.7.1 */
// Start line: 2373
// Start offset: 0x8006B7C4
// Variables:
// 		struct _PhysObLight *pLight; // $a1
/* end block 1.7.1 */
// End offset: 0x8006B800
// End Line: 2380
/* end block 1.7 */
// End offset: 0x8006B800
// End Line: 2381

/* begin block 1.8 */
// Start line: 2385
// Start offset: 0x8006B814
// Variables:
// 		struct Level *level; // $v1

/* begin block 1.8.1 */
// Start line: 2393
// Start offset: 0x8006B85C
// Variables:
// 		struct __PhysObProjectileProperties *ProjProp; // $s2
// 		struct __PhysObProjectileData *ProjData; // $v1
/* end block 1.8.1 */
// End offset: 0x8006B8F4
// End Line: 2419
/* end block 1.8 */
// End offset: 0x8006B8F4
// End Line: 2420

/* begin block 1.9 */
// Start line: 2426
// Start offset: 0x8006B918
// Variables:
// 		struct evPhysicsGravityData *gravityData; // $s2
// 		int rc; // $s3
// 		int upperOffset; // $a0
// 		short lowerOffset; // $a1
// 		int wasFalling; // $s4

/* begin block 1.9.1 */
// Start line: 2509
// Start offset: 0x8006BB7C
/* end block 1.9.1 */
// End offset: 0x8006BB90
// End Line: 2513

/* begin block 1.9.2 */
// Start line: 2540
// Start offset: 0x8006BC00
/* end block 1.9.2 */
// End offset: 0x8006BC28
// End Line: 2544

/* begin block 1.9.3 */
// Start line: 2570
// Start offset: 0x8006BCDC
// Variables:
// 		struct _PCollideInfo CInfo; // stack offset -96
// 		struct SVECTOR Old; // stack offset -48
// 		struct SVECTOR New; // stack offset -40
// 		short len; // $a2
// 		long mult; // $a3
/* end block 1.9.3 */
// End offset: 0x8006BDC0
// End Line: 2604
/* end block 1.9 */
// End offset: 0x8006BDC0
// End Line: 2604
/* end block 1 */
// End offset: 0x8006BEC0
// End Line: 2658

/* begin block 2 */
// Start line: 4820
/* end block 2 */
// End Line: 4821

void ProcessPhysicalObject(_Instance *instance, GameTracker *gameTracker)

{
  byte bVar1;
  ushort uVar2;
  _PhysObLight *pLight;
  int NewAnim;
  _Instance *p_Var3;
  uint uVar4;
  ulong uVar5;
  Level *pLVar6;
  int iVar7;
  uint uVar8;
  short sVar9;
  void *pvVar10;
  short burnAmplitude;
  uint *puVar11;
  void *pvVar12;
  int iVar13;
  _PCollideInfo _Stack96;
  SVECTOR local_30;
  SVECTOR local_28;

  puVar11 = (uint *)instance->extraData;
  if (((instance == (gameTracker->gameData).asmData.lightInstances[0].lightInstance) &&
       (pLight = PhysObGetLight(instance), pLight != (_PhysObLight *)0x0)) &&
      ((gameTracker->gameData).asmData.lightInstances[0].lightInstance == instance))
  {
    burnAmplitude = 0x1000;
    if (((*puVar11 & 0x8000) != 0) && (burnAmplitude = *(short *)(puVar11 + 0xd), burnAmplitude < 0))
    {
      burnAmplitude = -burnAmplitude;
    }
    PHYSOB_SetLightTable(pLight, (gameTracker->gameData).asmData.lightInstances, burnAmplitude);
  }
  NewAnim = CheckPhysObAbility(instance, 2);
  if (NewAnim != 0)
  {
    p_Var3 = PHYSOBS_IsAnythingAttached(instance);
    if (p_Var3 == (_Instance *)0x0)
    {
      uVar4 = instance->flags2 & 0xffffff7f;
    }
    else
    {
      uVar4 = instance->flags2 | 0x80;
    }
    instance->flags2 = uVar4;
  }
  if (((*puVar11 & 0x2000000) != 0) &&
      (NewAnim = (uint)(ushort)instance->fadeValue + (gameTrackerX.timeMult >> 5),
       instance->fadeValue = (short)NewAnim, 0xfff < NewAnim * 0x10000 >> 0x10))
  {
    instance->flags = instance->flags | 0x20;
  }
  if ((*puVar11 & 0x8000) != 0)
  {
    uVar2 = *(short *)(puVar11 + 0xd) + 0x88;
    if (*(short *)(puVar11 + 0xd) < 0)
    {
      *(ushort *)(puVar11 + 0xd) = uVar2;
      if (-1 < (int)((uint)uVar2 << 0x10))
      {
        *(undefined2 *)(puVar11 + 0xd) = 0;
        *puVar11 = *puVar11 & 0xffff7fff;
        if ((*(ushort *)((int)instance->data + 6) & 0x20) != 0)
        {
          pLight = PhysObGetLight(instance);
          if ((*puVar11 & 0x40000) == 0)
          {
            PHYSOB_EndLighting(instance, pLight);
          }
          else
          {
            PHYSOB_EndBurning(instance, pLight);
          }
          *puVar11 = *puVar11 & 0xfffbffff;
        }
      }
    }
    else
    {
      *(ushort *)(puVar11 + 0xd) = uVar2;
      if (0xfff < (short)uVar2)
      {
        *(undefined2 *)(puVar11 + 0xd) = 0x1000;
        *puVar11 = *puVar11 & 0xffff7fff;
      }
    }
  }
  NewAnim = CheckPhysObFamily(instance, 5);
  if (NewAnim != 0)
  {
    pvVar10 = instance->extraData;
    if (0 < *(int *)((int)pvVar10 + 4))
    {
      NewAnim = *(int *)((int)pvVar10 + 4) - gameTrackerX.timeMult;
      *(int *)((int)pvVar10 + 4) = NewAnim;
      if (NewAnim < 0)
      {
        *(undefined4 *)((int)pvVar10 + 4) = 0;
        INSTANCE_KillInstance(instance);
      }
      else
      {
        if (NewAnim < 0x1e000)
        {
          instance->fadeValue = 0x1000 - (short)(NewAnim / 0x1e);
        }
        else
        {
          uVar2 = instance->fadeValue - 0x40;
          if ((instance->fadeValue != 0) &&
              (instance->fadeValue = uVar2, (int)((uint)uVar2 << 0x10) < 0))
          {
            instance->fadeValue = 0;
          }
        }
      }
    }
  }
  NewAnim = CheckPhysObFamily(instance, 6);
  if ((NewAnim != 0) && ((*(ushort *)((int)instance->data + 8) & 1) != 0))
  {
    uVar5 = INSTANCE_Query(gameTrackerX.playerInstance, 0x24);
    if ((uVar5 & 0x10) == 0)
    {
      uVar4 = instance->flags | 0x800;
    }
    else
    {
      uVar4 = instance->flags & 0xfffff7ff;
    }
    instance->flags = uVar4;
  }
  NewAnim = CheckPhysObAbility(instance, 0x40);
  if (NewAnim != 0)
  {
    if ((*puVar11 & 0x100000) != 0)
    {
      *(ushort *)((int)instance->extraData + 4) = *(ushort *)((int)instance->extraData + 4) & 0xfff3;
      *puVar11 = *puVar11 & 0xffeff7ff;
    }
    if ((*puVar11 & 0x800) == 0)
    {
      return;
    }
    G2EmulationInstancePlayAnimation(instance);
    return;
  }
  NewAnim = CheckPhysObAbility(instance, 0x8000);
  if (NewAnim != 0)
  {
    G2EmulationInstancePlayAnimation(instance);
  }
  uVar4 = *puVar11;
  if ((uVar4 & 1) == 0)
  {
    if ((uVar4 & 8) != 0)
    {
      ExecuteFlip(instance);
      uVar4 = *puVar11;
    }
    if (((uVar4 & 1) == 0) && ((uVar4 & 0x40) != 0))
    {
      ExecuteDrag(instance);
    }
  }
  if ((*puVar11 & 2) != 0)
  {
    ExecuteSlideToStop(instance);
  }
  if ((*puVar11 & 0x4000) != 0)
  {
    ExecuteGravitate(instance);
  }
  if ((*puVar11 & 0x10) != 0)
  {
    ExecuteThrow(instance);
  }
  if ((*puVar11 & 0x20) != 0)
  {
    ExecuteFollow(instance);
  }
  if (((*puVar11 & 0x100000) != 0) && (NewAnim = CheckPhysObFamily(instance, 5), NewAnim != 0))
  {
    bVar1 = *(byte *)((int)instance->data + 0x10);
    if (bVar1 != 0xff)
    {
      G2EmulationInstanceSetAnimation(instance, 0, (uint)bVar1, 0, 0);
      G2EmulationInstanceSetMode(instance, 0, 2);
    }
    *puVar11 = *puVar11 & 0xffefffff;
  }
  if (((((*puVar11 & 0x10000) != 0) &&
        (pLVar6 = STREAM_GetLevelWithID(instance->currentStreamUnitID), pLVar6 != (Level *)0x0)) &&
       (instance->matrix != (MATRIX *)0x0)) &&
      (pLight = PhysObGetLight(instance),
       instance->matrix[(uint)pLight->segment].t[2] < pLVar6->waterZLevel))
  {
    PHYSOB_EndBurning(instance, pLight);
  }
  NewAnim = CheckPhysObFamily(instance, 7);
  if (((NewAnim != 0) && (pvVar10 = instance->extraData, *(int *)((int)pvVar10 + 4) == 8)) &&
      ((pLVar6 = STREAM_GetLevelWithID(instance->currentStreamUnitID), pLVar6 != (Level *)0x0 &&
                                                                           ((int)(instance->position).z < pLVar6->waterZLevel))))
  {
    pvVar12 = instance->data;
    if (instance->currentModel == 0)
    {
      FX_EndInstanceEffects(instance);
    }
    NewAnim = (int)*(char *)(*(int *)((int)pvVar12 + 0xc) + *(int *)((int)pvVar10 + 4) * 0xc + 3);
    if (NewAnim == -1)
    {
      INSTANCE_KillInstance(instance);
    }
    else
    {
      if ((*puVar11 & 0x80000) == 0)
      {
        G2EmulationInstanceSetAnimation(instance, 0, NewAnim, 0, 0);
        G2EmulationInstanceSetMode(instance, 0, 1);
        *puVar11 = *puVar11 | 0x81001;
      }
    }
  }
  uVar4 = *puVar11;
  if (((uVar4 & 0x1000) != 0) || (instance->matrix == (MATRIX *)0x0))
  {
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
    goto LAB_8006be18;
  }
  NewAnim = (int)(instance->oldPos).z - (int)(instance->position).z;
  if (NewAnim < 0xa0)
  {
    NewAnim = 0xa0;
  }
  iVar13 = instance->zAccl * gameTrackerX.timeMult;
  if (iVar13 < 0)
  {
    iVar13 = iVar13 + 0xfff;
  }
  iVar13 = (instance->zVel + ((iVar13 << 4) >> 0x10)) * gameTrackerX.timeMult;
  if (iVar13 < 0)
  {
    iVar13 = iVar13 + 0xfff;
  }
  iVar13 = 0x40 - (iVar13 >> 0xc);
  burnAmplitude = (short)iVar13;
  iVar7 = iVar13 * 0x10000;
  if (iVar13 * 0x10000 >> 0x10 < 0xa0)
  {
    burnAmplitude = 0xa0;
    iVar7 = 0xa00000;
  }
  sVar9 = (short)((uint)iVar7 >> 0x10);
  if (iVar7 >> 0x10 < NewAnim)
  {
    sVar9 = (short)NewAnim;
    burnAmplitude = (short)NewAnim;
  }
  NewAnim = SetPhysicsGravityData((int)sVar9, (int)burnAmplitude, 0, 0, 0, 0xb50);
  uVar8 = PhysicsCheckGravity(instance, NewAnim, 0xd);
  if ((uVar8 & 1) == 0)
  {
  LAB_8006bbd8:
    iVar13 = instance->attachedID;
  code_r0x8006bbe0:
    if ((iVar13 == 0) && (instance->oldMatrix != (MATRIX *)0x0))
    {
      if ((uVar8 & 1) != 0)
      {
        (instance->position).x = (instance->position).x + *(short *)(NewAnim + 4);
        (instance->position).y = (instance->position).y + *(short *)(NewAnim + 6);
      }
      if ((instance->zVel == 0) && ((instance->object->oflags & 0x400U) != 0))
      {
        instance->zVel = -0x32;
      }
      instance->zAccl = -10;
      *puVar11 = *puVar11 | 4;
    }
    else
    {
      instance->zAccl = 0;
      instance->zVel = 0;
    }
  }
  else
  {
    iVar13 = instance->attachedID;
    if ((iVar13 != 0) && ((uVar4 & 4) == 0))
      goto code_r0x8006bbe0;
    if ((instance->wNormal).z < 0xb51)
      goto LAB_8006bbd8;
    NewAnim = instance->zVel;
    if ((*puVar11 & 0x14) != 0)
    {
      PHYSOB_PlayDropSound(instance);
    }
    uVar4 = *puVar11;
    *puVar11 = uVar4 & 0xfffffffb;
    if ((uVar4 & 0x400000) == 0)
    {
      *puVar11 = uVar4 & 0xff7ffffb;
      if ((uVar4 & 0x4000000) == 0)
      {
        *puVar11 = uVar4 & 0xff7ffffb | 1;
      }
    }
    else
    {
      *puVar11 = uVar4 & 0xffbfffeb | 0x200000;
      puVar11[0x11] = 10;
      TurnOnCollisionPhysOb(instance, 7);
    }
    if ((*puVar11 & 0x10) != 0)
    {
      instance->flags2 = instance->flags2 & 0xffffff7f;
    }
    uVar4 = *puVar11;
    *puVar11 = uVar4 & 0xffffffef;
    if ((uVar4 & 0x200000) == 0)
    {
      TurnOffCollisionPhysOb(instance, 4);
    }
    if ((uVar8 & 0x80000) == 0)
    {
      instance->zAccl = -1;
      instance->zVel = -1;
    }
    else
    {
      *puVar11 = *puVar11 | 0x1000;
      instance->zAccl = 0;
      instance->zVel = 0;
    }
    if ((instance->oldMatrix != (MATRIX *)0x0) && ((*puVar11 & 0x18000) == 0x10000))
    {
      pLight = PhysObGetLight(instance);
      PHYSOB_StopLighting(instance, pLight);
    }
    iVar13 = CheckPhysObAbility(instance, 8);
    if ((iVar13 != 0) && ((*puVar11 & 0x100) == 0))
    {
      if (NewAnim < -0x32)
      {
        instance->zAccl = 0;
        ResetOrientation(instance);
      }
      *(short *)((int)puVar11 + 0x12) = (instance->position).z;
    }
  }
  if (((((instance->object->oflags & 0x80000U) == 0) &&
        (NewAnim = CheckPhysObAbility(instance, 8), NewAnim != 0)) &&
       (gameTrackerX.gameData.asmData.MorphType == 0)) &&
      ((gameTrackerX.gameData.asmData.MorphTime != 1000 && ((instance->flags2 & 0x8000000U) == 0))))
  {
    _Stack96.newPoint = &local_28;
    local_30.vx = (instance->position).x;
    local_30.vy = (instance->position).y;
    burnAmplitude = (instance->position).z;
    local_28.vz = burnAmplitude - 0x500;
    local_30.vz = burnAmplitude + 0x140;
    _Stack96.oldPoint = &local_30;
    local_28.vx = local_30.vx;
    local_28.vy = local_30.vy;
    PHYSICS_CheckLineInWorld(instance, &_Stack96);
    instance->zAccl = 0;
    NewAnim = ((uint)local_30.vz - (uint)local_28.vz) + -0x140;
    burnAmplitude = (short)NewAnim;
    if (0x3bf < NewAnim * 0x10000 >> 0x10)
    {
      uVar2 = (instance->position).z;
      iVar13 = ((uint) * (ushort *)((int)puVar11 + 0x12) - (uint)uVar2) * 0x10000;
      NewAnim = iVar13 >> 0x10;
      burnAmplitude =
          uVar2 - (*(ushort *)((int)puVar11 + 0x12) +
                   ((short)((uint)(((NewAnim / 0x280 + (NewAnim >> 0x1f)) - (iVar13 >> 0x1f)) *
                                   0x10000) >>
                            0x10) +
                    1) *
                       -0x280);
    }
    instance->zVel =
        -(int)(short)((uint)((((int)burnAmplitude * 1000) /
                                  ((1000 - (int)gameTrackerX.gameData.asmData.MorphTime) * 0x32)
                              << 0x10) >>
                             4) /
                      gameTrackerX.timeMult);
  }
LAB_8006be18:
  if ((*puVar11 & 0x200000) != 0)
  {
    puVar11[0x11] = puVar11[0x11] - 1;
    NewAnim = PHYSOB_ReAlignFalling(instance, -900);
    if ((NewAnim != 0) || ((int)puVar11[0x11] < 1))
    {
      *puVar11 = *puVar11 & 0xff5fffff | 1;
      TurnOffCollisionPhysOb(instance, 7);
    }
  }
  if ((((instance->object->oflags & 0x80000U) != 0) ||
       (NewAnim = CheckPhysObAbility(instance, 8), NewAnim != 0)) ||
      (gameTrackerX.gameData.asmData._8_4_ == 1000))
  {
    PhysicsMove(instance, &instance->position, gameTracker->timeMult);
  }
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ PhysicalObjectQuery(struct _Instance *instance /*$s0*/, unsigned long Query /*$a1*/)
// line 2663, offset 0x8006bee4
/* begin block 1 */
// Start line: 2664
// Start offset: 0x8006BEE4
// Variables:
// 		struct PhysObData *Data; // $s2
// 		int trueValue; // $s1

/* begin block 1.1 */
// Start line: 2692
// Start offset: 0x8006BFA4
/* end block 1.1 */
// End offset: 0x8006BFC8
// End Line: 2701

/* begin block 1.2 */
// Start line: 2708
// Start offset: 0x8006BFF8
/* end block 1.2 */
// End offset: 0x8006C020
// End Line: 2711

/* begin block 1.3 */
// Start line: 2716
// Start offset: 0x8006C034
// Variables:
// 		struct _G2EulerAngles_Type ea; // stack offset -24
/* end block 1.3 */
// End offset: 0x8006C080
// End Line: 2727

/* begin block 1.4 */
// Start line: 2736
// Start offset: 0x8006C09C
// Variables:
// 		struct PhysObProperties *Prop; // $a0

/* begin block 1.4.1 */
// Start line: 2740
// Start offset: 0x8006C0B4
/* end block 1.4.1 */
// End offset: 0x8006C0C8
// End Line: 2743

/* begin block 1.4.2 */
// Start line: 2745
// Start offset: 0x8006C0D0
/* end block 1.4.2 */
// End offset: 0x8006C0DC
// End Line: 2748

/* begin block 1.4.3 */
// Start line: 2750
// Start offset: 0x8006C0E4
/* end block 1.4.3 */
// End offset: 0x8006C0F0
// End Line: 2753
/* end block 1.4 */
// End offset: 0x8006C0FC
// End Line: 2761

/* begin block 1.5 */
// Start line: 2771
// Start offset: 0x8006C130
// Variables:
// 		struct PhysObCollectibleProperties *collectibleProp; // $v0
/* end block 1.5 */
// End offset: 0x8006C14C
// End Line: 2774

/* begin block 1.6 */
// Start line: 2820
// Start offset: 0x8006C1A8
// Variables:
// 		struct PhysObDraftProperties *DraftProp; // $t0
// 		struct INICommand *index; // $v0
/* end block 1.6 */
// End offset: 0x8006C200
// End Line: 2832

/* begin block 1.7 */
// Start line: 2840
// Start offset: 0x8006C200
// Variables:
// 		struct evControlSaveDataData *pdata; // $a1
// 		struct _PhysObSaveData *data; // $a2
/* end block 1.7 */
// End offset: 0x8006C2D4
// End Line: 2861

/* begin block 1.8 */
// Start line: 2869
// Start offset: 0x8006C2EC
/* end block 1.8 */
// End offset: 0x8006C310
// End Line: 2881

/* begin block 1.9 */
// Start line: 2884
// Start offset: 0x8006C310
// Variables:
// 		struct PhysObSwitchProperties *Prop; // $v0

/* begin block 1.9.1 */
// Start line: 2889
// Start offset: 0x8006C328
// Variables:
// 		struct PhysObData *Data; // $v0
/* end block 1.9.1 */
// End offset: 0x8006C34C
// End Line: 2901
/* end block 1.9 */
// End offset: 0x8006C34C
// End Line: 2902

/* begin block 1.10 */
// Start line: 2912
// Start offset: 0x8006C36C
// Variables:
// 		struct PhysObData *physobData; // $v0
/* end block 1.10 */
// End offset: 0x8006C3A4
// End Line: 2924
/* end block 1 */
// End offset: 0x8006C3BC
// End Line: 2933

/* begin block 2 */
// Start line: 5843
/* end block 2 */
// End Line: 5844

/* WARNING: Type propagation algorithm not settling */

ulong PhysicalObjectQuery(_Instance *instance, ulong Query)

{
  short sVar1;
  int iVar2;
  INICommand *pIVar3;
  MATRIX *pMVar4;
  MATRIX *pMVar5;
  ushort family;
  void *pvVar6;
  _G2EulerAngles_Type local_18;

  pMVar4 = (MATRIX *)instance->extraData;
  pMVar5 = (MATRIX *)&UNK_00000001;
  switch (Query)
  {
  case 1:
    iVar2 = CheckPhysOb(instance);
    if (iVar2 != 0)
    {
      iVar2 = CheckPhysObFamily(instance, 6);
      if (iVar2 == 0)
      {
        return (ulong)(MATRIX *)&DAT_00000020;
      }
      if ((*(ushort *)((int)instance->data + 8) & 1) == 0)
      {
        return (ulong)(MATRIX *)&DAT_00000020;
      }
      if ((instance->flags & 0x800U) != 0)
      {
        return (ulong)(MATRIX *)0x0;
      }
      return (ulong)(MATRIX *)&DAT_00000020;
    }
    goto switchD_8006bf28_caseD_8;
  case 2:
    pMVar5 = (MATRIX *)GetPhysicalAbility(instance);
    break;
  case 3:
    pMVar5 = *(MATRIX **)pMVar4->m;
    break;
  case 4:
    pvVar6 = instance->data;
    sVar1 = *(short *)((int)pvVar6 + 2);
    if (sVar1 == 3)
    {
      pMVar5 = (MATRIX *)(int)*(short *)((int)instance->extraData + 6);
    }
    else
    {
      if (sVar1 == 0)
      {
        pMVar5 = (MATRIX *)(int)*(char *)((int)pvVar6 + 0x14);
      }
      else
      {
        if (sVar1 == 2)
        {
          pMVar5 = (MATRIX *)(int)*(short *)((int)pvVar6 + 10);
        }
        else
        {
          pMVar5 = (MATRIX *)((uint)(sVar1 == 7) << 3);
        }
      }
    }
    break;
  case 5:
    pvVar6 = instance->extraData;
    iVar2 = CheckPhysObAbility(instance, 0x40);
    pMVar5 = (MATRIX *)0x0;
    if (iVar2 != 0)
    {
      pMVar5 = (MATRIX *)(int)*(short *)((int)pvVar6 + 4);
    }
    break;
  case 6:
    pMVar5 = (MATRIX *)
        SetPositionData((int)(instance->position).x, (int)(instance->position).y,
                        (int)(instance->position).z);
    break;
  case 7:
    iVar2 = CheckPhysObAbility(instance, 0x40);
    if (iVar2 == 0)
    {
      iVar2 = CheckPhysObFamily(instance, 1);
      if (iVar2 == 0)
      {
        pMVar5 = (MATRIX *)
            SetPositionData((int)(instance->rotation).x, (int)(instance->rotation).y,
                            (int)(instance->rotation).z);
      }
      else
      {
        if (instance->matrix == (MATRIX *)0x0)
        {
          local_18.x = 0;
          local_18.y = 0;
          local_18.z = 0;
        }
        else
        {
          G2EulerAngles_FromMatrix(&local_18, (_G2Matrix_Type *)(instance->matrix + 2), 0);
        }
        pMVar5 = (MATRIX *)SetPositionData((int)local_18.x, (int)local_18.y, (int)local_18.z);
      }
    }
    else
    {
      pMVar5 = (MATRIX *)
          SetPositionData(0, 0, (int)(((uint)(ushort)(instance->rotation).z + (uint) * (ushort *)((int)instance->extraData + 6)) * 0x10000) >> 0x10);
    }
    break;
  default:
    goto switchD_8006bf28_caseD_8;
  case 0xb:
    pMVar5 = (MATRIX *)&UNK_00000003;
    break;
  case 0xc:
  case 0xd:
    pMVar5 = instance->matrix;
    break;
  case 0xe:
    if ((instance->matrix != (MATRIX *)0x0) && (iVar2 = CheckPhysObFamily(instance, 5), iVar2 != 0))
    {
      return (ulong)(instance->matrix + (uint) * (ushort *)((int)instance->data + 0x12));
    }
    goto switchD_8006bf28_caseD_8;
  case 0x11:
    pMVar5 = (MATRIX *)G2EmulationInstanceQueryAnimation(instance, 0);
    break;
  case 0x15:
    family = 3;
    goto LAB_8006c154;
  case 0x16:
    iVar2 = CheckPhysObAbility(instance, 0x100);
    if (iVar2 != 0)
    {
      pIVar3 = INSTANCE_FindIntroCommand(instance, 0x13);
      if (pIVar3 == (INICommand *)0x0)
      {
        pvVar6 = instance->data;
      }
      else
      {
        pvVar6 = (void *)((int)instance->data + (int)pIVar3[1] * 0x14);
      }
      pMVar5 = (MATRIX *)
          SetObjectDraftData(*(short *)((int)pvVar6 + 8), *(ushort *)((int)pvVar6 + 10),
                             *(ushort *)((int)pvVar6 + 0xc), *(ushort *)((int)pvVar6 + 0x10),
                             (int)*(short *)((int)pvVar6 + 0xe));
      return (ulong)pMVar5;
    }
    goto switchD_8006bf28_caseD_8;
  case 0x17:
    iVar2 = CheckPhysObAbility(instance, 0x40);
    if (iVar2 == 0)
    {
      return (ulong)(MATRIX *)0x0;
    }
    goto LAB_8006c360;
  case 0x18:
    pMVar5 = (MATRIX *)CIRC_Alloc(0x10);
    *(undefined4 *)pMVar5->m = 8;
    *(short **)(pMVar5->m + 2) = pMVar5->m + 4;
    *(undefined4 *)(pMVar5->m + 4) = *(undefined4 *)((int)instance->extraData + 4);
    if (instance->LinkParent == (_Instance *)0x0)
    {
    LAB_8006c2c0:
      pMVar4 = *(MATRIX **)pMVar4->m;
    }
    else
    {
      if (((instance->LinkParent->object->oflags2 & 0x80000U) == 0) ||
          (instance->ParentLinkNode == 3))
      {
        if ((instance->LinkParent != (_Instance *)0x0) &&
            (instance->LinkParent == gameTrackerX.playerInstance))
        {
          *(uint *)(pMVar5->m + 6) = (uint) * (MATRIX **)pMVar4->m & 0xffffef6f | 0x400004;
          return (ulong)pMVar5;
        }
        goto LAB_8006c2c0;
      }
      pMVar4 = (MATRIX *)((uint) * (MATRIX **)pMVar4->m | 0x2000000);
    }
    *(MATRIX **)(pMVar5->m + 6) = pMVar4;
    break;
  case 0x1a:
    goto switchD_8006bf28_caseD_1a;
  case 0x1b:
    pMVar5 = (MATRIX *)0x0;
    goto switchD_8006bf28_caseD_1a;
  case 0x1c:
    iVar2 = CheckPhysObAbility(instance, 0x40);
    goto joined_r0x8006c184;
  case 0x1d:
    family = 5;
  LAB_8006c154:
    iVar2 = CheckPhysObFamily(instance, family);
  joined_r0x8006c184:
    pMVar5 = (MATRIX *)0x0;
    if (iVar2 != 0)
    {
    LAB_8006c360:
      pMVar5 = (MATRIX *)instance->data;
    }
    break;
  case 0x2f:
    if (instance->extraData == (void *)0x0)
    {
      return (ulong)(MATRIX *)0x0;
    }
    if (((uint) * (MATRIX **)pMVar4->m & 0x800) != 0)
    {
      return (ulong)(MATRIX *)&UNK_00000001;
    }
    if (((uint) * (MATRIX **)pMVar4->m & 0x14e) != 0)
    {
      return (ulong)(MATRIX *)&UNK_00000001;
    }
  switchD_8006bf28_caseD_8:
    pMVar5 = (MATRIX *)0x0;
  }
  return (ulong)pMVar5;
switchD_8006bf28_caseD_1a:
  iVar2 = CheckPhysObFamily(instance, 2);
  if (iVar2 != 0)
  {
    if ((*(ushort *)((int)instance->extraData + 4) & 2) != 0)
    {
      return (ulong)pMVar5;
    }
    return (ulong)(MATRIX *)((uint)pMVar5 ^ 1);
  }
  if (*(short *)((int)instance->data + 10) != 0)
  {
    return (ulong)pMVar5;
  }
  if ((*(uint *)instance->extraData & 0x2000) == 0)
  {
    return (ulong)pMVar5;
  }
  return (ulong)(MATRIX *)((uint)pMVar5 ^ 1);
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysicalObjectPost(struct _Instance *instance /*$s4*/, unsigned long Message /*$s0*/, unsigned long Data /*$s3*/)
// line 2937, offset 0x8006c3d4
/* begin block 1 */
// Start line: 2938
// Start offset: 0x8006C3D4
// Variables:
// 		struct evObjectData *Ptr; // $s2
// 		struct PhysObData *PData; // $s1

/* begin block 1.1 */
// Start line: 2995
// Start offset: 0x8006C7B8
/* end block 1.1 */
// End offset: 0x8006C7D4
// End Line: 3001

/* begin block 1.2 */
// Start line: 3021
// Start offset: 0x8006C7E4
// Variables:
// 		struct PhysObSwitchProperties *Prop; // $s1

/* begin block 1.2.1 */
// Start line: 3025
// Start offset: 0x8006C7F8
/* end block 1.2.1 */
// End offset: 0x8006C818
// End Line: 3034

/* begin block 1.2.2 */
// Start line: 3041
// Start offset: 0x8006C83C
// Variables:
// 		struct PhysObData *Data; // $a0
/* end block 1.2.2 */
// End offset: 0x8006C85C
// End Line: 3050
/* end block 1.2 */
// End offset: 0x8006C85C
// End Line: 3050

/* begin block 1.3 */
// Start line: 3058
// Start offset: 0x8006C870
// Variables:
// 		struct _PhysObSaveData *saveData; // $v0

/* begin block 1.3.1 */
// Start line: 3073
// Start offset: 0x8006C8CC
// Variables:
// 		struct _PhysObLight *pLight; // $a1
/* end block 1.3.1 */
// End offset: 0x8006C8F4
// End Line: 3080

/* begin block 1.3.2 */
// Start line: 3083
// Start offset: 0x8006C908
// Variables:
// 		struct PhysObSwitchProperties *Prop; // $v1
/* end block 1.3.2 */
// End offset: 0x8006C94C
// End Line: 3099

/* begin block 1.3.3 */
// Start line: 3101
// Start offset: 0x8006C960
/* end block 1.3.3 */
// End offset: 0x8006C978
// End Line: 3105
/* end block 1.3 */
// End offset: 0x8006C9AC
// End Line: 3111

/* begin block 1.4 */
// Start line: 3114
// Start offset: 0x8006C9AC
/* end block 1.4 */
// End offset: 0x8006C9B4
// End Line: 3121

/* begin block 1.5 */
// Start line: 3128
// Start offset: 0x8006C9F4
// Variables:
// 		struct PhysObCollectibleProperties *collectibleProp; // $s0
/* end block 1.5 */
// End offset: 0x8006CAD4
// End Line: 3159

/* begin block 1.6 */
// Start line: 3161
// Start offset: 0x8006CAD4
/* end block 1.6 */
// End offset: 0x8006CAFC
// End Line: 3173

/* begin block 1.7 */
// Start line: 3199
// Start offset: 0x8006CB58
// Variables:
// 		struct _PhysObLight *pLight; // $a1

/* begin block 1.7.1 */
// Start line: 3213
// Start offset: 0x8006CBAC
// Variables:
// 		struct PhysObData *podata; // $v1
/* end block 1.7.1 */
// End offset: 0x8006CBAC
// End Line: 3213
/* end block 1.7 */
// End offset: 0x8006CBD4
// End Line: 3224

/* begin block 1.8 */
// Start line: 3233
// Start offset: 0x8006CC10
/* end block 1.8 */
// End offset: 0x8006CC10
// End Line: 3234

/* begin block 1.9 */
// Start line: 3241
// Start offset: 0x8006CC1C
/* end block 1.9 */
// End offset: 0x8006CC50
// End Line: 3248

/* begin block 1.10 */
// Start line: 3252
// Start offset: 0x8006CC58
// Variables:
// 		struct PhysObProperties *Prop; // $v0
/* end block 1.10 */
// End offset: 0x8006CCA4
// End Line: 3258
/* end block 1 */
// End offset: 0x8006CCA4
// End Line: 3263

/* begin block 2 */
// Start line: 6405
/* end block 2 */
// End Line: 6406

void PhysicalObjectPost(_Instance *instance, ulong Message, ulong Data)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  _PhysObLight *pLight;
  ulong uVar4;
  uint uVar5;
  uint *puVar6;
  void *pvVar7;

  puVar6 = (uint *)instance->extraData;
  if (Message == 0x800010)
  {
    ThrowPhysOb(instance, (evObjectThrowData *)Data);
    return;
  }
  if (Message < 0x800011)
  {
    if (Message == 0x200003)
    {
      TurnOffCollisionPhysOb(instance, Data);
      return;
    }
    if (Message < 0x200004)
    {
      if (Message == 0x80005)
      {
        ScriptKillInstance(instance, 5);
        return;
      }
      if (0x80005 < Message)
      {
        if ((undefined *)Message == &DAT_00100008)
        {
          if (puVar6 != (uint *)0x0)
          {
            *(short *)((int)puVar6 + 0xe) = *(short *)((int)puVar6 + 0xe) + *(short *)Data;
            *(short *)(puVar6 + 4) = *(short *)(puVar6 + 4) + *(short *)(Data + 2);
            *(short *)((int)puVar6 + 0x12) = *(short *)((int)puVar6 + 0x12) + *(short *)(Data + 4);
            return;
          }
          return;
        }
        if (&DAT_00100008 < Message)
        {
          if (Message == 0x200002)
          {
            TurnOnCollisionPhysOb(instance, Data);
            return;
          }
          return;
        }
        if ((undefined *)Message != &DAT_00100007)
        {
          return;
        }
        puVar1 = *(uint **)(Data + 4);
        puVar6[1] = *puVar1;
        uVar2 = puVar1[1];
        *puVar6 = uVar2 & 0xffeff7ff;
        if ((uVar2 & 0x2000000) != 0)
        {
          instance->flags = instance->flags | 0x20;
        }
        iVar3 = CheckPhysObAbility(instance, 0x20);
        if ((iVar3 != 0) && (pLight = PhysObGetLight(instance), (*puVar6 & 0x10000) == 0))
        {
          PHYSOB_EndBurning(instance, pLight);
        }
        iVar3 = CheckPhysObFamily(instance, 2);
        if ((iVar3 != 0) && ((*(ushort *)((int)instance->extraData + 4) & 1) != 0))
        {
          G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)instance->data + 0xd), 0, 0);
          G2EmulationInstanceSetMode(instance, 0, 1);
          G2EmulationInstancePlayAnimation(instance);
        }
        iVar3 = CheckPhysObFamily(instance, 3);
        if (iVar3 != 0)
        {
          if (*(short *)((int)instance->extraData + 6) != 0)
          {
            G2EmulationInstanceSetAnimation(instance, 0, 0, 0, 0);
            G2EmulationInstanceSetMode(instance, 0, 1);
            G2EmulationInstancePlayAnimation(instance);
            return;
          }
          return;
        }
        return;
      }
      if ((undefined *)Message == &DAT_00040002)
      {
        ScriptKillInstance(instance, Data);
        return;
      }
      if ((undefined *)Message != &DAT_0004000e)
      {
        return;
      }
      if (Data == 0)
      {
        return;
      }
      if (*(short *)((int)instance->data + 2) == 7)
      {
        if (instance->parent == (_Instance *)0x0)
        {
          return;
        }
        uVar4 = INSTANCE_Query(instance->parent, 1);
        if ((uVar4 & 10) != 0)
        {
          instance->flags = instance->flags | 0x20;
          return;
        }
        return;
      }
      return;
    }
    if (Message == 0x800001)
    {
      iVar3 = STREAM_IsMorphInProgress();
      if ((iVar3 == 0) && (gameTrackerX.gameData.asmData.MorphType != 0))
      {
        return;
      }
      iVar3 = FlipPhysOb(instance, *(short *)Data, *(short *)(Data + 2), *(_Instance **)(Data + 8));
      *(int *)(Data + 0xc) = iVar3;
      return;
    }
    if (0x800001 < Message)
    {
      if (Message == 0x800004)
      {
        StopPhysOb(instance);
        return;
      }
      if (Message < 0x800005)
      {
        if (Message != 0x800002)
        {
          return;
        }
        iVar3 = STREAM_IsMorphInProgress();
        if (((iVar3 == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) &&
            (*(short *)(Data + 4) != 0))
        {
          return;
        }
        iVar3 = PickUpPhysOb(instance, *(short *)(Data + 4), *(_Instance **)(Data + 8),
                             (int)*(short *)(Data + 6));
        *(undefined2 *)(Data + 6) = (short)iVar3;
        if (*(short *)(Data + 4) != 0)
        {
          return;
        }
        if ((*puVar6 & 0x4000) != 0)
        {
          ExecuteGravitate(instance);
          return;
        }
        return;
      }
      if (Message != 0x800008)
      {
        return;
      }
      DropPhysOb(instance, Data);
      if ((Data & 1) == 0)
      {
        return;
      }
      uVar2 = *puVar6 | 0x2000000;
      goto LAB_8006cb38;
    }
    if (Message == 0x200006)
    {
      uVar2 = 0xfeff0000;
    LAB_8006cb44:
      uVar2 = *puVar6 & (uVar2 | 0xffff);
    LAB_8006cb50:
      *puVar6 = uVar2;
      return;
    }
    if (0x200006 < Message)
    {
      if (Message != 0x800000)
      {
        return;
      }
      iVar3 = STREAM_IsMorphInProgress();
      if ((iVar3 == 0) && (gameTrackerX.gameData.asmData.MorphType != 0))
      {
        return;
      }
      iVar3 = PushPhysOb(instance, *(short *)Data, *(short *)(Data + 2), *(short *)(Data + 4),
                         *(_Instance **)(Data + 8));
      *(int *)(Data + 0xc) = iVar3;
      return;
    }
    uVar5 = 0x1000000;
    if (Message != 0x200005)
    {
      return;
    }
    uVar2 = *puVar6;
  }
  else
  {
    if (Message == 0x800027)
    {
      if (Data == 0)
      {
        *puVar6 = *puVar6 | 0x1000;
        return;
      }
      uVar2 = *puVar6 & 0xffffefff;
      goto LAB_8006cb50;
    }
    if (Message < 0x800028)
    {
      if (Message < 0x800023)
      {
        if (Message < 0x800021)
        {
          if (Message == 0x800020)
          {
            SwitchPhysOb(instance);
            return;
          }
          return;
        }
        iVar3 = CheckPhysOb(instance);
        if (iVar3 == 0)
        {
          return;
        }
        pvVar7 = instance->data;
        iVar3 = CheckPhysObFamily(instance, 2);
        if (iVar3 != 0)
        {
          pvVar7 = instance->extraData;
          if (Message != 0x800021)
          {
            *(ushort *)((int)pvVar7 + 4) = *(ushort *)((int)pvVar7 + 4) & 0xfffd;
            return;
          }
          *(ushort *)((int)pvVar7 + 4) = *(ushort *)((int)pvVar7 + 4) | 2;
          return;
        }
        if (*(short *)((int)pvVar7 + 10) == 0)
        {
          puVar6 = (uint *)instance->extraData;
          if (Message != 0x800021)
          {
            *puVar6 = *puVar6 | 0x2000;
            return;
          }
          *puVar6 = *puVar6 & 0xffffdfff;
          return;
        }
        return;
      }
      if (Message == 0x800025)
      {
        return;
      }
      if (0x800025 < Message)
      {
        pvVar7 = instance->data;
        switch ((int)(((uint) * (ushort *)((int)pvVar7 + 8) - 1) * 0x10000) >> 0x10)
        {
        case 0:
          HEALTHU_Pickup(instance);
          return;
        case 1:
        case 4:
          MANNA_Pickup();
        case 2:
        case 3:
          INSTANCE_PlainDeath(instance);
          return;
        case 5:
          goto switchD_8006ca30_caseD_5;
        case 6:
          goto switchD_8006ca30_caseD_6;
        default:
          return;
        }
      }
      if (Message != 0x800023)
      {
        return;
      }
      iVar3 = STREAM_IsMorphInProgress();
      if ((iVar3 == 0) && (gameTrackerX.gameData.asmData.MorphType != 0))
      {
        return;
      }
      InteractPhysOb(instance, *(_Instance **)Data, (uint) * (ushort *)(Data + 4),
                     (uint) * (ushort *)(Data + 0xe));
      return;
    }
    if (Message != 0x80002c)
    {
      if (0x80002c < Message)
      {
        if (Message == 0x80002e)
        {
          iVar3 = CanBePickedUp(instance, *(_Instance **)(Data + 8), (int)*(short *)(Data + 6));
          if (iVar3 != 0)
          {
            *(undefined2 *)(Data + 6) = 0;
            return;
          }
          return;
        }
        if (Message < 0x80002e)
        {
          ResetSwitchPhysOb(instance);
          return;
        }
        if (Message == 0x8000008)
        {
          G2EmulationInstanceSetAnimation(instance, 0, *(int *)(Data + 4), *(int *)(Data + 8), *(int *)(Data + 0xc));
          G2EmulationInstanceSetMode(instance, 0, *(int *)(Data + 0x10));
          return;
        }
        return;
      }
      if (Message == 0x80002a)
      {
        iVar3 = CheckPhysObFamily(instance, 2);
        if (iVar3 != 0)
        {
          *(undefined2 *)((int)instance->extraData + 4) = (short)Data;
          return;
        }
        return;
      }
      uVar2 = 0xff7f0000;
      if (Message < 0x80002b)
      {
        if (Message != 0x800029)
        {
          return;
        }
        pLight = PhysObGetLight(instance);
        if (pLight == (_PhysObLight *)0x0)
        {
          return;
        }
        if (Data == 1)
        {
          PHYSOB_StartBurning(instance, pLight);
          return;
        }
        if (Data == 0)
        {
          PHYSOB_StopBurning(instance, pLight);
          return;
        }
        if (Data == 2)
        {
          puVar6 = (uint *)instance->extraData;
          *(undefined2 *)(puVar6 + 0xd) = 0;
          *puVar6 = *puVar6 & 0xffff7fff;
          PHYSOB_EndBurning(instance, pLight);
          return;
        }
        return;
      }
      goto LAB_8006cb44;
    }
    uVar2 = *puVar6;
    uVar5 = 0x800000;
  }
  uVar2 = uVar2 | uVar5;
LAB_8006cb38:
  *puVar6 = uVar2;
  return;
switchD_8006ca30_caseD_6:
  MANNA_Pickup();
switchD_8006ca30_caseD_5:
  if (*(char *)((int)pvVar7 + 0x11) != -1)
  {
    uVar2 = G2EmulationInstanceQueryAnimation(instance, 0);
    if (uVar2 != (uint) * (byte *)((int)pvVar7 + 0x11))
    {
      printf(s_Collect__s_800cf554);
      G2EmulationInstanceSetAnimation(instance, 0, (uint) * (byte *)((int)pvVar7 + 0x11), 0, 0);
      G2EmulationInstanceSetMode(instance, 0, 1);
      return;
    }
    return;
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ PhysobAnimCallback(struct _G2Anim_Type *anim /*$v1*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s2*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
// line 3265, offset 0x8006ccc4
/* begin block 1 */
// Start line: 3266
// Start offset: 0x8006CCC4

/* begin block 1.1 */
// Start line: 3268
// Start offset: 0x8006CCEC
// Variables:
// 		struct PhysObData *Data; // $s0
/* end block 1.1 */
// End offset: 0x8006CD38
// End Line: 3285
/* end block 1 */
// End offset: 0x8006CD50
// End Line: 3289

/* begin block 2 */
// Start line: 7074
/* end block 2 */
// End Line: 7075

long PhysobAnimCallback(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message,
                        long messageDataA, long messageDataB, void *data)

{
  uint uVar1;
  uint *puVar2;

  if (message == G2ANIM_MSG_DONE)
  {
    puVar2 = *(uint **)((int)data + 0x14c);
    G2AnimSection_SetPaused(anim->section + sectionID);
    uVar1 = *puVar2;
    *puVar2 = uVar1 | 0x100000;
    if ((uVar1 & 0x80000) != 0)
    {
      INSTANCE_KillInstance((_Instance *)data);
    }
  }
  else
  {
    messageDataA = INSTANCE_DefaultAnimCallback(anim, sectionID, message, messageDataA, messageDataB, (_Instance *)data);
  }
  return messageDataA;
}

// decompiled code
// original method signature:
// void /*$ra*/ CheckForceCollision(struct _Instance *instance /*$s2*/, struct _Instance *hitinst /*$s4*/, struct _TFace *tface /*$s7*/, struct _CollideInfo *collideInfo /*$fp*/, struct _SVector *dir /*stack 16*/, int obliqueFlg /*stack 20*/)
// line 3300, offset 0x8006cd68
/* begin block 1 */
// Start line: 3301
// Start offset: 0x8006CD68
// Variables:
// 		struct PhysObData *Data; // $s3

/* begin block 1.1 */
// Start line: 3307
// Start offset: 0x8006CDBC
// Variables:
// 		struct PhysObProperties *Prop; // $s1
// 		struct ProjectileData *ProjIData; // $s0
// 		struct __PhysObProjectileData *ProjData; // $s1
// 		int killImmediately; // $s5
/* end block 1.1 */
// End offset: 0x8006CFA4
// End Line: 3393
/* end block 1 */
// End offset: 0x8006CFA4
// End Line: 3394

/* begin block 2 */
// Start line: 7148
/* end block 2 */
// End Line: 7149

void CheckForceCollision(_Instance *instance, _Instance *hitinst, _TFace *tface,
                         _CollideInfo *collideInfo, _SVector *dir, int obliqueFlg)

{
  bool bVar1;
  int Data;
  ulong uVar2;
  void *pvVar3;
  void *pvVar4;
  uint *puVar5;

  puVar5 = (uint *)instance->extraData;
  Data = CheckPhysObFamily(instance, 7);
  bVar1 = true;
  if (Data != 0)
  {
    pvVar4 = instance->data;
    pvVar3 = instance->extraData;
    COLLIDE_SegmentCollisionOff(instance, 0);
    Data = *(int *)((int)pvVar4 + 0xc) + *(int *)((int)pvVar3 + 4) * 0xc;
    if (*(char *)(Data + 3) != -1)
    {
      *puVar5 = *puVar5 & 0xffbffffb | 0x1001;
      instance->xVel = 0;
      instance->yVel = 0;
      instance->zVel = 0;
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = 0;
      if ((*puVar5 & 0x80000) != 0)
      {
        return;
      }
      if (instance->currentModel == 0)
      {
        FX_EndInstanceEffects(instance);
      }
      bVar1 = false;
      G2EmulationInstanceSetAnimation(instance, 0, (int)*(char *)(Data + 3), 0, 0);
      G2EmulationInstanceSetMode(instance, 0, 1);
      *puVar5 = *puVar5 | 0x81001;
    }
    if ((instance->parent != (_Instance *)0x0) &&
        (uVar2 = INSTANCE_Query(instance->parent, 1), (uVar2 & 1) != 0))
    {
      if ((tface == (_TFace *)0x0) || (gameTrackerX.gameData.asmData.MorphType != 0))
      {
        if ((hitinst != gameTrackerX.playerInstance) &&
            (gameTrackerX.gameData.asmData.MorphType == 0))
        {
          Data = CheckPhysOb(hitinst);
          if ((Data != 0) &&
              ((hitinst->introUniqueID != (gameTrackerX.playerInstance)->attachedID &&
                (obliqueFlg == 0))))
          {
            Data = SetObjectData((int)dir->x, (int)dir->y, 6, (_Instance *)0x0, 0);
            INSTANCE_Post(hitinst, 0x800000, Data);
          }
          if (*(int *)((int)pvVar3 + 4) == 1)
          {
            hitinst->flags2 = hitinst->flags2 | 0x10000;
          }
          else
          {
            hitinst->flags = hitinst->flags | 0x80000000;
          }
        }
      }
      else
      {
        COLLIDE_SetBSPTreeFlag(collideInfo, 0x400);
      }
    }
    if (bVar1)
    {
      INSTANCE_KillInstance(instance);
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ GetObliqueDirection(struct _Instance *instance /*$a0*/, struct _SVector *dir /*$a1*/)
// line 3397, offset 0x8006cfd4
/* begin block 1 */
// Start line: 3398
// Start offset: 0x8006CFD4
// Variables:
// 		struct _SVector vel; // stack offset -8
// 		int obliqueFlg; // $a3

/* begin block 1.1 */
// Start line: 3407
// Start offset: 0x8006D008
// Variables:
// 		long axVel; // $a2
// 		long ayVel; // $v1
/* end block 1.1 */
// End offset: 0x8006D090
// End Line: 3431
/* end block 1 */
// End offset: 0x8006D0A4
// End Line: 3439

/* begin block 2 */
// Start line: 7361
/* end block 2 */
// End Line: 7362

/* begin block 3 */
// Start line: 7365
/* end block 3 */
// End Line: 7366

int GetObliqueDirection(_Instance *instance, _SVector *dir)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;

  iVar4 = 0;
  if ((*(short *)&instance->xVel == 0) && (*(short *)&instance->yVel == 0))
  {
    dir->z = 0;
    dir->y = 0;
    dir->x = 0;
  }
  else
  {
    iVar4 = instance->xVel;
    iVar3 = instance->yVel;
    if (iVar4 < 0)
    {
      iVar4 = -iVar4;
    }
    if (iVar3 < 0)
    {
      iVar3 = -iVar3;
    }
    dir->z = 0;
    if (iVar3 < iVar4)
    {
      if (instance->xVel < 1)
      {
        sVar2 = -0x1000;
      }
      else
      {
        sVar2 = 0x1000;
      }
      dir->x = sVar2;
      dir->y = 0;
      bVar1 = iVar3<iVar4>> 1;
    }
    else
    {
      sVar2 = 0x1000;
      if (instance->yVel < 1)
      {
        sVar2 = -0x1000;
      }
      dir->y = sVar2;
      dir->x = 0;
      bVar1 = iVar4<iVar3>> 1;
    }
    iVar4 = 0;
    if (!bVar1)
    {
      iVar4 = 1;
    }
  }
  return iVar4;
}

// decompiled code
// original method signature:
// void /*$ra*/ CollidePhysicalObject(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
// line 3444, offset 0x8006d0b0
/* begin block 1 */
// Start line: 3445
// Start offset: 0x8006D0B0
// Variables:
// 		struct PhysObData *Data; // $s3
// 		struct _CollideInfo *collideInfo; // $s2
// 		int obliqueFlg; // stack offset -48
// 		struct _SVector vel; // stack offset -136
// 		struct _SVector dir; // stack offset -128
// 		struct _Instance *hitinst; // $s5
// 		struct _TFace *tface; // $s4
// 		struct _Normal *norm; // $s6
// 		struct _SVector normal; // stack offset -120
// 		int stickFlg; // $s0
// 		int drawFlg; // $s7
// 		int projectile; // $fp

/* begin block 1.1 */
// Start line: 3470
// Start offset: 0x8006D10C
// Variables:
// 		struct Level *level; // $v1
/* end block 1.1 */
// End offset: 0x8006D154
// End Line: 3480

/* begin block 1.2 */
// Start line: 3487
// Start offset: 0x8006D170
// Variables:
// 		struct BSPTree *bsp; // $s0
// 		struct Level *level; // $a0
/* end block 1.2 */
// End offset: 0x8006D1C4
// End Line: 3494

/* begin block 1.3 */
// Start line: 3517
// Start offset: 0x8006D298
// Variables:
// 		struct _Position delta; // stack offset -112

/* begin block 1.3.1 */
// Start line: 3519
// Start offset: 0x8006D298
// Variables:
// 		short _x0; // $t0
// 		short _y0; // $t1
// 		short _z0; // $t2
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a2
// 		struct _Position *_v; // $a1
// 		struct _Position *_v0; // $v0
// 		struct _Position *_v1; // $a3
/* end block 1.3.1 */
// End offset: 0x8006D298
// End Line: 3519

/* begin block 1.3.2 */
// Start line: 3519
// Start offset: 0x8006D298
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a2
/* end block 1.3.2 */
// End offset: 0x8006D298
// End Line: 3519
/* end block 1.3 */
// End offset: 0x8006D31C
// End Line: 3525

/* begin block 1.4 */
// Start line: 3569
// Start offset: 0x8006D440
/* end block 1.4 */
// End offset: 0x8006D474
// End Line: 3574

/* begin block 1.5 */
// Start line: 3583
// Start offset: 0x8006D4B0
// Variables:
// 		struct _PCollideInfo CInfo; // stack offset -104
// 		struct _SVector newPos; // stack offset -56
/* end block 1.5 */
// End offset: 0x8006D50C
// End Line: 3602

/* begin block 1.6 */
// Start line: 3622
// Start offset: 0x8006D5B4
// Variables:
// 		struct _Position delta; // stack offset -112

/* begin block 1.6.1 */
// Start line: 3622
// Start offset: 0x8006D5B4
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a2
// 		short _y1; // $t1
// 		short _z1; // $t2
// 		struct _Position *_v; // $a3
/* end block 1.6.1 */
// End offset: 0x8006D5B4
// End Line: 3622
/* end block 1.6 */
// End offset: 0x8006D624
// End Line: 3642

/* begin block 1.7 */
// Start line: 3645
// Start offset: 0x8006D634
/* end block 1.7 */
// End offset: 0x8006D68C
// End Line: 3651

/* begin block 1.8 */
// Start line: 3684
// Start offset: 0x8006D758
// Variables:
// 		struct _CollideInfo parentCI; // stack offset -112
/* end block 1.8 */
// End offset: 0x8006D7B0
// End Line: 3690

/* begin block 1.9 */
// Start line: 3698
// Start offset: 0x8006D7E8
// Variables:
// 		struct PhysObSplinter *splintDef; // $v0
// 		struct FXSplinter *splinterData; // $v1
/* end block 1.9 */
// End offset: 0x8006D830
// End Line: 3721
/* end block 1 */
// End offset: 0x8006D854
// End Line: 3726

/* begin block 2 */
// Start line: 7463
/* end block 2 */
// End Line: 7464

void CollidePhysicalObject(_Instance *instance, GameTracker *gameTracker)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int Data;
  Level *pLVar7;
  long lVar8;
  _CollideInfo *p_Var9;
  PhysObSplinter *pPVar10;
  void **ppvVar11;
  FXSplinter *splintDef;
  uint uVar12;
  void *pvVar13;
  void *pvVar14;
  void *pvVar15;
  _CollideInfo *collideInfo;
  uint *puVar16;
  _TFace *tface;
  _Instance *hitinst;
  SVECTOR *nrml;
  _SVector _Stack128;
  SVECTOR SStack120;
  short local_70;
  short sStack110;
  short local_6c;
  short local_68;
  _Instance *local_60;
  SVECTOR *local_54;
  _Position *local_50;
  SVECTOR local_38;
  int local_30;

  hitinst = (_Instance *)0x0;
  tface = (_TFace *)0x0;
  bVar6 = true;
  local_30 = 0;
  collideInfo = (_CollideInfo *)instance->collideInfo;
  puVar16 = (uint *)instance->extraData;
  Data = CheckPhysObFamily(instance, 7);
  bVar4 = Data != 0;
  nrml = &collideInfo->point0;
  if ((((!bVar4) || (*(int *)((int)instance->extraData + 4) != 8)) ||
       (pLVar7 = STREAM_GetLevelWithID(instance->currentStreamUnitID), pLVar7 == (Level *)0x0)) ||
      (pLVar7->waterZLevel <= (int)(instance->position).z))
  {
    if (collideInfo->type1 == '\x03')
    {
      pvVar13 = collideInfo->inst1;
      pLVar7 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
      tface = (_TFace *)collideInfo->prim1;
      if (((*(ushort *)((int)pvVar13 + 0x12) & 1) != 0) || ((tface->attr & 4) != 0))
      {
        bVar6 = false;
      }
      nrml = &SStack120;
      COLLIDE_GetNormal(tface->normal, (short *)pLVar7->terrain->normalList, (_SVector *)nrml);
    }
    else
    {
      hitinst = (_Instance *)collideInfo->inst1;
    }
    if (((*puVar16 & 0x10) == 0) || (hitinst != (_Instance *)puVar16[0x10]))
    {
      GetPhysObCollisionType(instance);
      if ((*puVar16 & 0x4000) != 0)
      {
        if ((_Instance *)puVar16[2] == hitinst)
        {
          return;
        }
        if (hitinst != (_Instance *)0x0)
        {
          if ((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000)
          {
            return;
          }
          if ((hitinst->object->oflags2 & 0x40000U) != 0)
          {
            return;
          }
        }
        if (tface != (_TFace *)0x0)
        {
          if (tface->textoff == 0xffff)
          {
            return;
          }
          if ((*(ushort *)(*(int *)(*(int *)collideInfo->level + 0x34) + (uint)tface->textoff + 10) & 0x1000) == 0)
          {
            return;
          }
        }
        *puVar16 = *puVar16 & 0xffffbfff | 0x10;
        puVar16[0x11] = 0x96000;
        local_70 = (instance->oldPos).x - (instance->position).x;
        sStack110 = (instance->oldPos).y - (instance->position).y;
        local_6c = (instance->oldPos).z - (instance->position).z;
        (instance->position).x = (instance->position).x + local_70;
        (instance->position).y = (instance->position).y + sStack110;
        (instance->position).z = (instance->position).z + local_6c;
        COLLIDE_UpdateAllTransforms(instance, (SVECTOR *)&local_70);
      }
      uVar12 = *puVar16;
      if ((uVar12 & 0x10) == 0)
      {
        if ((uVar12 & 0x200004) == 0)
        {
          if (((uVar12 & 0x80) != 0) &&
              (ppvVar11 = (void **)&local_70, instance->LinkParent != (_Instance *)0x0))
          {
            p_Var9 = collideInfo;
            do
            {
              pvVar13 = *(void **)&p_Var9->flags;
              pvVar14 = p_Var9->prim0;
              pvVar15 = p_Var9->prim1;
              *ppvVar11 = p_Var9->level;
              ppvVar11[1] = pvVar13;
              ppvVar11[2] = pvVar14;
              ppvVar11[3] = pvVar15;
              p_Var9 = (_CollideInfo *)&p_Var9->inst0;
              ppvVar11 = ppvVar11 + 4;
            } while (p_Var9 != collideInfo + 1);
            local_60 = instance->LinkParent;
            Data = SetCollideInfoData((_CollideInfo *)&local_70);
            INSTANCE_Post(instance->LinkParent, 0x200004, Data);
          }
        }
        else
        {
          if ((collideInfo->type1 == '\x01') && ((_Instance *)puVar16[0x10] == hitinst))
          {
            return;
          }
          if (nrml->vz < 0xb50)
          {
            return;
          }
          if ((uVar12 & 0x200000) != 0)
          {
            (collideInfo->offset).z = 0;
          }
          (instance->position).x = (instance->position).x + (collideInfo->offset).x;
          (instance->position).y = (instance->position).y + (collideInfo->offset).y;
          (instance->position).z = (instance->position).z + (collideInfo->offset).z;
          COLLIDE_UpdateAllTransforms(instance, (SVECTOR *)&collideInfo->offset);
        }
      }
      else
      {
        if ((((bVar4) && (tface != (_TFace *)0x0)) && (tface->textoff != 0xffff)) &&
            ((*(ushort *)(*(int *)(*(int *)collideInfo->level + 0x34) + (uint)tface->textoff + 10) &
              0x1000) != 0))
        {
          return;
        }
        sVar1 = *(short *)&instance->xVel;
        uVar2 = *(ushort *)&instance->yVel;
        uVar3 = *(ushort *)&instance->zVel;
        local_30 = GetObliqueDirection(instance, &_Stack128);
        if ((*puVar16 & 0x400000) == 0)
        {
          instance->xVel = 0;
          instance->yVel = 0;
          instance->zVel = 0;
          instance->xAccl = 0;
          instance->yAccl = 0;
          instance->zAccl = 0;
        }
        (instance->position).x = (instance->position).x + (collideInfo->offset).x;
        (instance->position).y = (instance->position).y + (collideInfo->offset).y;
        (instance->position).z = (instance->position).z + (collideInfo->offset).z;
        COLLIDE_UpdateAllTransforms(instance, (SVECTOR *)&collideInfo->offset);
        if ((((int)sVar1 != 0) || ((uVar2 | uVar3) != 0)) &&
            (lVar8 = MATH3D_LengthXYZ((int)sVar1, (int)(short)uVar2, (int)(short)uVar3),
             100 < (short)lVar8))
        {
          instance->flags2 = instance->flags2 | 0x2000;
        }
        bVar5 = false;
        Data = CheckPhysObAbility(instance, 0x200);
        if ((Data != 0) && ((sVar1 != 0 || ((uVar2 | uVar3) != 0))))
        {
          local_38.vx = (instance->position).x + sVar1 * 4;
          local_38.vy = (instance->position).y + uVar2 * 4;
          local_50 = &instance->position;
          local_54 = &local_38;
          local_38.vz = (instance->position).z + uVar3 * 4;
          PHYSICS_CheckLineInWorld(instance, (_PCollideInfo *)(&local_70 + 8));
          bVar5 = local_68 != 0;
        }
        if ((((bVar5) && (bVar6)) && (hitinst == (_Instance *)0x0)) && (nrml->vz < 0xb50))
        {
          *puVar16 = *puVar16 | 0x1000;
          instance->flags2 = instance->flags2 & 0xffffff7f;
          *puVar16 = *puVar16 & 0xffffffef;
          TurnOffCollisionPhysOb(instance, 4);
        }
        else
        {
          *puVar16 = *puVar16 & 0xffffefff | 0x400000;
          if (((sVar1 != 0) || (uVar2 != 0)) && (!bVar4))
          {
            memset((SVECTOR *)&local_70, 0, 6);
            local_70 = -sVar1;
            sStack110 = -uVar2;
            local_6c = -uVar3;
            (instance->position).x = (instance->position).x + local_70;
            (instance->position).y = (instance->position).y + sStack110;
            (instance->position).z = (instance->position).z + local_6c;
            COLLIDE_UpdateAllTransforms(instance, (SVECTOR *)&local_70);
          }
          if (((short)uVar3 < 0) &&
              (lVar8 = MATH3D_LengthXYZ((int)(collideInfo->offset).x, (int)(collideInfo->offset).y,
                                        (int)(collideInfo->offset).z),
               (int)(collideInfo->offset).z<(int)(short)lVar8 * 0xb500>> 0x10))
          {
            instance->zVel = (int)(short)uVar3;
          }
          DropPhysOb(instance, 0);
        }
      }
      Data = CheckPhysObAbility(instance, 0x1000);
      if (((Data != 0) && ((*puVar16 & 0x800000) == 0)) &&
          (gameTrackerX.gameData.asmData._8_4_ == 1000))
      {
        pPVar10 = PhysObGetSplinter(instance);
        splintDef = (FXSplinter *)0x0;
        if (pPVar10 != (PhysObSplinter *)0x0)
        {
          splintDef = (FXSplinter *)pPVar10->splinterData;
        }
        _FX_BuildSplinters(instance, (SVECTOR *)0x0, (SVECTOR *)0x0, (SVECTOR *)0x0, splintDef, gFXT,
                           (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                           (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0, 0);
        INSTANCE_PlainDeath(instance);
      }
      CheckForceCollision(instance, hitinst, tface, collideInfo, &_Stack128, local_30);
    }
  }
  return;
}

// decompiled code
// original method signature:
// struct PhysObWeaponAttributes * /*$ra*/ PhysObGetWeapon(struct _Instance *instance /*$s1*/)
// line 3729, offset 0x8006d884
/* begin block 1 */
// Start line: 3730
// Start offset: 0x8006D884
// Variables:
// 		struct PhysObWeaponAttributes *weapon; // $s0

/* begin block 1.1 */
// Start line: 3736
// Start offset: 0x8006D8AC
// Variables:
// 		struct PhysObWeaponProperties *Prop; // $v0
/* end block 1.1 */
// End offset: 0x8006D8B8
// End Line: 3738

/* begin block 1.2 */
// Start line: 3740
// Start offset: 0x8006D8C8
// Variables:
// 		struct PhysObInteractProperties *Prop; // $v0
/* end block 1.2 */
// End offset: 0x8006D8D4
// End Line: 3742

/* begin block 1.3 */
// Start line: 3744
// Start offset: 0x8006D8E4
// Variables:
// 		struct __PhysObProjectileProperties *Prop; // $a0
/* end block 1.3 */
// End offset: 0x8006D90C
// End Line: 3748
/* end block 1 */
// End offset: 0x8006D90C
// End Line: 3749

/* begin block 2 */
// Start line: 8132
/* end block 2 */
// End Line: 8133

PhysObWeaponAttributes *PhysObGetWeapon(_Instance *instance)

{
  int iVar1;
  PhysObWeaponAttributes *pPVar2;

  pPVar2 = (PhysObWeaponAttributes *)0x0;
  iVar1 = CheckPhysObFamily(instance, 0);
  if (iVar1 != 0)
  {
    pPVar2 = (PhysObWeaponAttributes *)((int)instance->data + 8);
  }
  iVar1 = CheckPhysObFamily(instance, 3);
  if (iVar1 != 0)
  {
    pPVar2 = *(PhysObWeaponAttributes **)((int)instance->data + 0x28);
  }
  iVar1 = CheckPhysObFamily(instance, 7);
  if (iVar1 != 0)
  {
    pPVar2 = *(PhysObWeaponAttributes **)(*(int *)((int)instance->extraData + 4) * 0xc + *(int *)((int)instance->data + 0xc) +
                                          8);
  }
  return pPVar2;
}

// decompiled code
// original method signature:
// struct _PhysObLight * /*$ra*/ PhysObGetLight(struct _Instance *instance /*$a0*/)
// line 3754, offset 0x8006d928
/* begin block 1 */
// Start line: 3755
// Start offset: 0x8006D928
// Variables:
// 		struct PhysObWeaponAttributes *weapon; // $v0
// 		struct _PhysObLight *pLight; // $s0
/* end block 1 */
// End offset: 0x8006D948
// End Line: 3764

/* begin block 2 */
// Start line: 8186
/* end block 2 */
// End Line: 8187

_PhysObLight *PhysObGetLight(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  _PhysObLight *p_Var2;

  p_Var2 = (_PhysObLight *)0x0;
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0)
  {
    p_Var2 = pPVar1->Light;
  }
  return p_Var2;
}

// decompiled code
// original method signature:
// struct PhysObSplinter * /*$ra*/ PhysObGetSplinter(struct _Instance *instance /*$a0*/)
// line 3768, offset 0x8006d960
/* begin block 1 */
// Start line: 3769
// Start offset: 0x8006D960
// Variables:
// 		struct PhysObWeaponAttributes *weapon; // $v0
// 		struct PhysObSplinter *pSplinter; // $s0
/* end block 1 */
// End offset: 0x8006D980
// End Line: 3778

/* begin block 2 */
// Start line: 8214
/* end block 2 */
// End Line: 8215

PhysObSplinter *PhysObGetSplinter(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  PhysObSplinter *pPVar2;

  pPVar2 = (PhysObSplinter *)0x0;
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0)
  {
    pPVar2 = &pPVar1->splinter;
  }
  return pPVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ TurnOnCollisionPhysOb(struct _Instance *instance /*$s1*/, int coll /*$s2*/)
// line 3783, offset 0x8006d994
/* begin block 1 */
// Start line: 3784
// Start offset: 0x8006D994
// Variables:
// 		struct PhysObWeaponAttributes *weapon; // $s0
// 		struct PhysObData *Data; // $v1
/* end block 1 */
// End offset: 0x8006DA20
// End Line: 3802

/* begin block 2 */
// Start line: 8244
/* end block 2 */
// End Line: 8245

void TurnOnCollisionPhysOb(_Instance *instance, int coll)

{
  PhysObWeaponAttributes *pPVar1;

  *(uint *)instance->extraData = *(uint *)instance->extraData & 0xfeffffff;
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0)
  {
    if ((coll & 2U) != 0)
    {
      COLLIDE_SegmentCollisionOn(instance, (int)pPVar1->LeftHandSphere);
    }
    if ((coll & 1U) != 0)
    {
      COLLIDE_SegmentCollisionOn(instance, (int)pPVar1->RightHandSphere);
    }
    if ((coll & 4U) != 0)
    {
      COLLIDE_SegmentCollisionOn(instance, (int)pPVar1->ThrowSphere);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ TurnOffCollisionPhysOb(struct _Instance *instance /*$s1*/, int coll /*$s2*/)
// line 3807, offset 0x8006da38
/* begin block 1 */
// Start line: 3808
// Start offset: 0x8006DA38
// Variables:
// 		struct PhysObWeaponAttributes *weapon; // $s0
/* end block 1 */
// End offset: 0x8006DAA8
// End Line: 3824

/* begin block 2 */
// Start line: 8299
/* end block 2 */
// End Line: 8300

void TurnOffCollisionPhysOb(_Instance *instance, int coll)

{
  PhysObWeaponAttributes *pPVar1;

  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0)
  {
    if ((coll & 2U) != 0)
    {
      COLLIDE_SegmentCollisionOff(instance, (int)pPVar1->LeftHandSphere);
    }
    if ((coll & 1U) != 0)
    {
      COLLIDE_SegmentCollisionOff(instance, (int)pPVar1->RightHandSphere);
    }
    if ((coll & 4U) != 0)
    {
      COLLIDE_SegmentCollisionOff(instance, (int)pPVar1->ThrowSphere);
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ GetPhysObCollisionType(struct _Instance *instance /*$s1*/)
// line 3831, offset 0x8006dac0
/* begin block 1 */
// Start line: 3832
// Start offset: 0x8006DAC0
// Variables:
// 		struct _CollideInfo *collideInfo; // $s4
// 		struct _HSphere *S; // $s0
// 		struct _Instance *target; // $s2
// 		struct PhysObWeaponAttributes *weapon; // $s0
// 		struct PhysObData *Data; // $s5

/* begin block 1.1 */
// Start line: 3851
// Start offset: 0x8006DB38
// Variables:
// 		struct _Instance *inst; // $v1
/* end block 1.1 */
// End offset: 0x8006DB38
// End Line: 3851

/* begin block 1.2 */
// Start line: 3919
// Start offset: 0x8006DD18
// Variables:
// 		int damage; // $s3
/* end block 1.2 */
// End offset: 0x8006DD74
// End Line: 3925
/* end block 1 */
// End offset: 0x8006DDD8
// End Line: 3941

/* begin block 2 */
// Start line: 8347
/* end block 2 */
// End Line: 8348

int GetPhysObCollisionType(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  ulong uVar2;
  int Data;
  _Instance *Inst;
  int Power;
  void *pvVar3;
  _Instance *Sender;
  _CollideInfo *collideInfo;
  uint *puVar4;

  puVar4 = (uint *)instance->extraData;
  collideInfo = (_CollideInfo *)instance->collideInfo;
  if ((*puVar4 & 0x1600001) != 0)
  {
    return 0;
  }
  pvVar3 = collideInfo->prim0;
  if ((instance->LinkParent == gameTrackerX.playerInstance) && (*(char *)((int)pvVar3 + 4) == '\t'))
  {
    if (collideInfo->type1 == '\x03')
    {
      COLLIDE_SetBSPTreeFlag(collideInfo, 0x800);
    }
    else
    {
      *(uint *)((int)collideInfo->inst1 + 0x14) = *(uint *)((int)collideInfo->inst1 + 0x14) | 4;
    }
    if (collideInfo->type1 != '\x01')
    {
      COLLIDE_SegmentCollisionOff(instance, (uint)(byte)collideInfo->segment);
      if (instance->LinkParent == gameTrackerX.playerInstance)
      {
        INSTANCE_Post(instance->LinkParent, 0x1000024, 0);
      }
    }
  }
  if ((*(uint *)&collideInfo->flags & 0xffff0000) != 0x1010000)
  {
    return 0;
  }
  if (*(char *)((int)pvVar3 + 4) != '\t')
  {
    return 0;
  }
  if (*(char *)((int)collideInfo->prim1 + 4) != '\b')
  {
    return 0;
  }
  Sender = (_Instance *)collideInfo->inst1;
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 == (PhysObWeaponAttributes *)0x0)
  {
    return 0;
  }
  TurnOffCollisionPhysOb(instance, 7);
  if (instance->LinkParent == (_Instance *)0x0)
  {
    uVar2 = INSTANCE_Query(Sender, 0);
    if ((uVar2 & 0x10000000) == 0)
    {
    LAB_8006dca4:
      Data = SetMonsterHitData(instance, (_Instance *)0x0, pPVar1->Damage,
                               (int)pPVar1->knockBackDistance, (int)pPVar1->knockBackFrames);
      Power = 0x1000000;
      Inst = Sender;
    LAB_8006dccc:
      INSTANCE_Post(Inst, Power, Data);
    }
    else
    {
      if (pPVar1->Class != '\x01')
      {
        Data = CheckPhysObAbility(instance, 0x20);
        if ((Data == 0) || ((*puVar4 & 0x10000) == 0))
          goto LAB_8006dca4;
        INSTANCE_Post(Sender, 0x100000c, 0x20);
        Power = 0x800029;
        Data = 0;
        Inst = instance;
        goto LAB_8006dccc;
      }
      INSTANCE_Post(Sender, 0x1000019, (int)instance);
      *puVar4 = *puVar4 & 0xffffffef;
    }
    if (((gameTrackerX.gameData.asmData.MorphType != 0) ||
         (Data = CheckPhysObFamily(instance, 7), Data == 0)) ||
        (instance->parent != gameTrackerX.playerInstance))
      goto LAB_8006dd78;
    Power = 0x80001;
    Data = 0;
    Inst = Sender;
  }
  else
  {
    Power = pPVar1->Damage;
    Data = CheckPhysObAbility(instance, 0x20);
    if ((Data != 0) && ((*puVar4 & 0x10000) == 0))
    {
      Power = pPVar1->AltDamage;
    }
    Data = SetMonsterHitData(Sender, (_Instance *)0x0, Power, 0, 0);
    Power = 0x2000002;
    Inst = instance->LinkParent;
  }
  INSTANCE_Post(Inst, Power, Data);
LAB_8006dd78:
  Data = CheckPhysObAbility(instance, 0x20);
  if ((Data == 0) || ((*puVar4 & 0x10000) == 0))
  {
    Data = 0x100;
  }
  else
  {
    Data = 0x20;
  }
  Data = SetFXHitData(instance, (uint)(byte)collideInfo->segment, pPVar1->Damage >> 7, Data);
  INSTANCE_Post(Sender, 0x400000, Data);
  return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExecuteThrow(struct _Instance *instance /*$s1*/)
// line 3944, offset 0x8006ddfc
/* begin block 1 */
// Start line: 3945
// Start offset: 0x8006DDFC
// Variables:
// 		struct PhysObData *Data; // $s2

/* begin block 1.1 */
// Start line: 3953
// Start offset: 0x8006DE30
// Variables:
// 		short angley; // $s0
// 		struct _Position zero; // stack offset -32
// 		struct _Position velocity; // stack offset -24
/* end block 1.1 */
// End offset: 0x8006DE30
// End Line: 3954
/* end block 1 */
// End offset: 0x8006DEF4
// End Line: 3980

/* begin block 2 */
// Start line: 8590
/* end block 2 */
// End Line: 8591

void ExecuteThrow(_Instance *instance)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  void *pvVar5;
  _Position _Stack32;
  _Position local_18;

  pvVar5 = instance->extraData;
  if ((*(ushort *)((int)pvVar5 + 0x36) & 1) == 0)
  {
    (instance->rotation).x = (instance->rotation).x + *(short *)((int)pvVar5 + 0x3a);
    (instance->rotation).y = (instance->rotation).y + *(short *)((int)pvVar5 + 0x3c);
    (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar5 + 0x3e);
  }
  else
  {
    memset(&_Stack32, 0, 6);
    local_18.x = *(short *)&instance->xVel;
    local_18.y = *(short *)&instance->yVel;
    local_18.z = *(short *)&instance->zVel;
    sVar2 = MATH3D_AngleFromPosToPos(&_Stack32, &local_18);
    sVar3 = MATH3D_ElevationFromPosToPos(&_Stack32, &local_18);
    sVar1 = *(short *)((int)pvVar5 + 0x38);
    (instance->rotation).z = sVar2;
    (instance->rotation).y = 0;
    (instance->rotation).x = sVar1 + sVar3;
    MATH3D_ZYXtoXYZ(&instance->rotation);
  }
  iVar4 = *(int *)((int)pvVar5 + 0x44) - gameTrackerX.timeMult;
  *(int *)((int)pvVar5 + 0x44) = iVar4;
  if (iVar4 < 0)
  {
    INSTANCE_KillInstance(instance);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExecuteDrag(struct _Instance *instance /*$s1*/)
// line 3984, offset 0x8006df0c
/* begin block 1 */
// Start line: 3985
// Start offset: 0x8006DF0C
// Variables:
// 		struct PhysObData *Data; // $s0
/* end block 1 */
// End offset: 0x8006DFA0
// End Line: 4019

/* begin block 2 */
// Start line: 8681
/* end block 2 */
// End Line: 8682

void ExecuteDrag(_Instance *instance)

{
  short sVar1;
  uint *puVar2;

  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 2) != 0)
  {
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  if ((*puVar2 & 0x100000) == 0)
  {
    G2EmulationInstancePlayAnimation(instance);
  }
  else
  {
    puVar2[2] = 0;
    FinishPush(instance);
    *puVar2 = *puVar2 & 0xffeffeb5 | 1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExecuteSlideToStop(struct _Instance *instance /*$s1*/)
// line 4023, offset 0x8006dfb4
/* begin block 1 */
// Start line: 4024
// Start offset: 0x8006DFB4
// Variables:
// 		struct PhysObData *Data; // $s0
/* end block 1 */
// End offset: 0x8006E05C
// End Line: 4061

/* begin block 2 */
// Start line: 8759
/* end block 2 */
// End Line: 8760

void ExecuteSlideToStop(_Instance *instance)

{
  short sVar1;
  uint uVar2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  uVar2 = *puVar3;
  if ((uVar2 & 0x100000) == 0)
  {
    G2EmulationInstancePlayAnimation(instance);
  }
  else
  {
    if ((uVar2 & 0x4000000) == 0)
    {
      puVar3[2] = 0;
      FinishPush(instance);
      *puVar3 = *puVar3 & 0xffffefff | 0x4000000;
      sVar1 = (instance->position).z;
      *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
      (instance->initialPos).z = sVar1;
    }
    else
    {
      *puVar3 = uVar2 & 0xfbefeeb5;
      if ((uVar2 & 4) == 0)
      {
        *puVar3 = uVar2 & 0xfbefeeb5 | 1;
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExecuteFlip(struct _Instance *instance /*$s1*/)
// line 4065, offset 0x8006e074
/* begin block 1 */
// Start line: 4066
// Start offset: 0x8006E074
// Variables:
// 		struct PhysObData *Data; // $s0
/* end block 1 */
// End offset: 0x8006E14C
// End Line: 4108

/* begin block 2 */
// Start line: 8843
/* end block 2 */
// End Line: 8844

void ExecuteFlip(_Instance *instance)

{
  short sVar1;
  uint uVar2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  uVar2 = *puVar3;
  if ((uVar2 & 2) != 0)
  {
    *puVar3 = uVar2 & 0xfffffffd;
    uVar2 = *puVar3;
  }
  if ((uVar2 & 0x100000) == 0)
  {
    G2EmulationInstancePlayAnimation(instance);
  }
  else
  {
    if ((uVar2 & 0x4000000) == 0)
    {
      if (*(short *)(puVar3 + 10) == 0xe)
      {
        instance->zVel = -0x32;
      }
      ResetOrientation(instance);
      puVar3[2] = 0;
      *puVar3 = *puVar3 & 0xffffefff | 0x4000000;
      sVar1 = (instance->position).z;
      *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
      (instance->initialPos).z = sVar1;
    }
    else
    {
      *puVar3 = uVar2 & 0xfbefeeb5;
      if ((uVar2 & 4) == 0)
      {
        *puVar3 = uVar2 & 0xfbefeeb5 | 1;
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ CheckSlope(int Znormal /*$a0*/, int Slope /*$a1*/, int Slop /*$a2*/)
// line 4168, offset 0x8006e164
/* begin block 1 */
// Start line: 9050
/* end block 1 */
// End Line: 9051

/* begin block 2 */
// Start line: 9051
/* end block 2 */
// End Line: 9052

int CheckSlope(int Znormal, int Slope, int Slop)

{
  uint uVar1;

  uVar1 = 0;
  if (Slope - Slop < Znormal)
  {
    uVar1 = (uint)(Znormal < Slope + Slop);
  }
  return uVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ CheckBlockSlope(struct _Instance *instance /*$a0*/, int x /*$a1*/, int y /*$a2*/, int hOff /*$a3*/, int vOff /*stack 16*/, int dH /*stack 20*/, int dV /*stack 24*/)
// line 4177, offset 0x8006e184
/* begin block 1 */
// Start line: 4178
// Start offset: 0x8006E184
// Variables:
// 		struct _PCollideInfo CInfo; // stack offset -72
// 		struct SVECTOR Old; // stack offset -24
// 		struct SVECTOR New; // stack offset -16
// 		int xOff; // $t3
// 		int yOff; // $t4
// 		int dX; // $t2
// 		int dY; // $t6
// 		struct MATRIX *mat; // $v0
/* end block 1 */
// End offset: 0x8006E184
// End Line: 4178

/* begin block 2 */
// Start line: 9068
/* end block 2 */
// End Line: 9069

/* begin block 3 */
// Start line: 9071
/* end block 3 */
// End Line: 9072

int CheckBlockSlope(_Instance *instance, int x, int y, int hOff, int vOff, int dH, int dV)

{
  MATRIX *pMVar1;
  _PCollideInfo local_48;
  SVECTOR local_18;
  SVECTOR local_10;

  local_48.oldPoint = &local_18;
  local_48.newPoint = &local_10;
  pMVar1 = instance->matrix;
  local_18.vx = *(short *)pMVar1->t + (short)x * (short)hOff;
  local_18.vy = *(short *)(pMVar1->t + 1) + (short)y * (short)hOff;
  local_18.vz = *(short *)(pMVar1->t + 2) + (short)vOff;
  local_10.vz = local_18.vz + (short)dV;
  local_10.vx = local_18.vx + (short)x * (short)dH;
  local_10.vy = local_18.vy + (short)y * (short)dH;
  PHYSICS_CheckLineInWorld(instance, &local_48);
  return (uint)(local_48.type == 5);
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOBS_FigureDragForSlope(struct _Instance *instance /*$a0*/, int pathNumber /*$s1*/, int *result /*$s2*/)
// line 4220, offset 0x8006e244
/* begin block 1 */
// Start line: 4221
// Start offset: 0x8006E244
// Variables:
// 		int didSomething; // $s0
/* end block 1 */
// End offset: 0x8006E2A8
// End Line: 4251

/* begin block 2 */
// Start line: 9220
/* end block 2 */
// End Line: 9221

int PHYSOBS_FigureDragForSlope(_Instance *instance, int pathNumber, int *result)

{
  _Instance *p_Var1;
  int iVar2;

  p_Var1 = PHYSOBS_IsAPushBlockAttached(instance);
  if ((((p_Var1 != (_Instance *)0x0) || (pathNumber == 5)) || (pathNumber == 1)) ||
      (((pathNumber == 7 || (pathNumber == 4)) || ((pathNumber == 2 || (iVar2 = 0, pathNumber == 3))))))
  {
    *result = 0;
    iVar2 = 1;
  }
  return iVar2;
}

// autogenerated function stub:
// int /*$ra*/ PHYSOB_CheckThrownLineCollision(struct _Instance *instance /*$s3*/, struct _Instance *parent /*$s1*/)
int PHYSOB_CheckThrownLineCollision(struct _Instance *instance, struct _Instance *parent)
{                                        // line 4255, offset 0x8006e2c4
                                         /* begin block 1 */
                                         // Start line: 4256
                                         // Start offset: 0x8006E2C4
                                         // Variables:
  struct _PCollideInfo pcollideInfo;     // stack offset -160
  struct _Position newPos;               // stack offset -112
  struct _Position oldPos;               // stack offset -104
  struct _Position orgNew;               // stack offset -96
  struct MATRIX *mat;                    // $v1
  struct PhysObWeaponAttributes *weapon; // $v0

  /* begin block 1.1 */
  // Start line: 4280
  // Start offset: 0x8006E32C
  // Variables:
  struct _SVector line;  // stack offset -88
  struct _SVector delta; // stack offset -80
  long dp;               // $s0

  /* begin block 1.1.1 */
  // Start line: 4312
  // Start offset: 0x8006E3DC
  // Variables:
  short _x0;             // $a0
  short _y0;             // $v0
  short _z0;             // $v1
  short _y1;             // $a1
  short _z1;             // $a2
  struct _SVector *_v;   // $s1
  struct _Position *_v0; // $v1
  struct _Position *_v1; // $s2
                         /* end block 1.1.1 */
                         // End offset: 0x8006E3DC
                         // End Line: 4312

  /* begin block 1.1.2 */
  // Start line: 4316
  // Start offset: 0x8006E488
  // Variables:
  short _x0; // $v0
  short _y0; // $v1
  short _z0; // $a0
  short _y1; // $a1
  short _z1; // $a2
             /* end block 1.1.2 */
             // End offset: 0x8006E488
             // End Line: 4316

  /* begin block 1.1.3 */
  // Start line: 4326
  // Start offset: 0x8006E4D8
  // Variables:
  short _x1;             // $a2
  short _y1;             // $v1
  short _z1;             // $a3
  struct _Position *_v0; // $v0
  struct _Position *_v1; // $v0
                         /* end block 1.1.3 */
                         // End offset: 0x8006E4D8
                         // End Line: 4326
                         /* end block 1.1 */
                         // End offset: 0x8006E580
                         // End Line: 4338

  /* begin block 1.2 */
  // Start line: 4349
  // Start offset: 0x8006E5B4
  // Variables:
  struct _TFace *tface; // $a0
  struct Level *level;  // $a1
                        /* end block 1.2 */
                        // End offset: 0x8006E604
                        // End Line: 4355

  /* begin block 1.3 */
  // Start line: 4363
  // Start offset: 0x8006E604
  // Variables:
  short _x0;             // $t0
  short _y0;             // $t1
  short _z0;             // $t2
  short _x1;             // $v0
  short _y1;             // $v1
  short _z1;             // $a2
  struct _Position *_v;  // $a1
  struct _Position *_v0; // $v0
                         /* end block 1.3 */
                         // End offset: 0x8006E604
                         // End Line: 4363

  /* begin block 1.4 */
  // Start line: 4363
  // Start offset: 0x8006E604
  // Variables:
  short _x0;            // $v0
  short _y0;            // $v1
  short _z0;            // $a2
  struct _Position *_v; // $a3
                        /* end block 1.4 */
                        // End offset: 0x8006E604
                        // End Line: 4363

  /* begin block 1.5 */
  // Start line: 4363
  // Start offset: 0x8006E604
  // Variables:
  struct PhysObData *Data; // $s0

  /* begin block 1.5.1 */
  // Start line: 4377
  // Start offset: 0x8006E6A8
  // Variables:
  struct PhysObSplinter *splintDef; // $v0
  struct FXSplinter *splinterData;  // $v1
                                    /* end block 1.5.1 */
                                    // End offset: 0x8006E6F0
                                    // End Line: 4392

  /* begin block 1.5.2 */
  // Start line: 4395
  // Start offset: 0x8006E6F0
  // Variables:
  struct _SVector dir;             // stack offset -80
  struct _Instance *hitInst;       // $s1
  struct _TFace *tface;            // $s2
  struct _CollideInfo collideInfo; // stack offset -72
                                   /* end block 1.5.2 */
                                   // End offset: 0x8006E714
                                   // End Line: 4406
                                   /* end block 1.5 */
                                   // End offset: 0x8006E714
                                   // End Line: 4406

  /* begin block 1.6 */
  // Start line: 4414
  // Start offset: 0x8006E760
  // Variables:
  struct Level *level; // $v0
  int bspID;           // $a0
  struct BSPTree *bsp; // $v0
                       /* end block 1.6 */
                       // End offset: 0x8006E768
                       // End Line: 4425
  /* end block 1 */
  // End offset: 0x8006E7A0
  // End Line: 4426

  /* begin block 2 */
  // Start line: 9290
  /* end block 2 */
  // End Line: 9291

  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOB_CheckDroppedLineCollision(struct _Instance *instance /*$s3*/, struct _Instance *parent /*$s6*/)
// line 4432, offset 0x8006e7bc
/* begin block 1 */
// Start line: 4433
// Start offset: 0x8006E7BC
// Variables:
// 		struct _PCollideInfo pcollideInfo; // stack offset -208
// 		struct _Position parentPos; // stack offset -160
// 		struct _Position newPos; // stack offset -152
// 		struct _Position oldPos; // stack offset -144
// 		struct _SVector offset; // stack offset -136
// 		struct _Position basePos; // stack offset -128
// 		int seg; // $s2
// 		int collided; // $s5

/* begin block 1.1 */
// Start line: 4466
// Start offset: 0x8006E848
// Variables:
// 		struct MATRIX *mat; // $v1

/* begin block 1.1.1 */
// Start line: 4468
// Start offset: 0x8006E848
// Variables:
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _y1; // $t0
// 		short _z1; // $t1
// 		struct _SVector *_v; // $s1
// 		struct _Position *_v0; // $s0
// 		struct _Position *_v1; // $s4
/* end block 1.1.1 */
// End offset: 0x8006E848
// End Line: 4468

/* begin block 1.1.2 */
// Start line: 4479
// Start offset: 0x8006E948
// Variables:
// 		short _y0; // $v1
// 		short _z0; // $a1
/* end block 1.1.2 */
// End offset: 0x8006E948
// End Line: 4479
/* end block 1.1 */
// End offset: 0x8006E9D4
// End Line: 4495

/* begin block 1.2 */
// Start line: 4496
// Start offset: 0x8006E9F4
// Variables:
// 		struct _SVector origin; // stack offset -120
// 		struct _SVector node2; // stack offset -112
// 		struct _SVector orgDir; // stack offset -104
// 		struct _SVector newDir; // stack offset -96
// 		struct _SVector axis; // stack offset -88
// 		short angle; // $s0
// 		struct MATRIX mat; // stack offset -80
// 		struct _G2EulerAngles_Type ea; // stack offset -48

/* begin block 1.2.1 */
// Start line: 4496
// Start offset: 0x8006E9F4
// Variables:
// 		short _y0; // $v0
// 		short _z0; // $v1
// 		short _y1; // $a3
// 		short _z1; // $a1
// 		struct _SVector *_v; // $s0
// 		struct _SVector *_v0; // $v1
// 		struct _SVector *_v1; // $a1
/* end block 1.2.1 */
// End offset: 0x8006E9F4
// End Line: 4496

/* begin block 1.2.2 */
// Start line: 4496
// Start offset: 0x8006E9F4
// Variables:
// 		struct _SVector delta; // stack offset -40
// 		int i; // $a0
// 		struct _Model *model; // $a2
// 		struct MATRIX *m; // $a1
/* end block 1.2.2 */
// End offset: 0x8006EC40
// End Line: 4546
/* end block 1.2 */
// End offset: 0x8006EC40
// End Line: 4547
/* end block 1 */
// End offset: 0x8006EC50
// End Line: 4562

/* begin block 2 */
// Start line: 9698
/* end block 2 */
// End Line: 9699

/* WARNING: Could not reconcile some variable overlaps */

int PHYSOB_CheckDroppedLineCollision(_Instance *instance, _Instance *parent)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  bool bVar6;
  short angle;
  int iVar7;
  int iVar8;
  MATRIX *pMVar9;
  _Model *p_Var10;
  int iVar11;
  _PCollideInfo local_d0;
  undefined4 local_a0;
  short local_9c;
  undefined4 local_98;
  short local_94;
  SVECTOR local_90;
  short local_88;
  short local_86;
  short local_84;
  undefined4 local_80;
  short local_7c;
  short local_78;
  short local_76;
  short local_74;
  short local_70;
  short local_6e;
  short local_6c;
  _Normal local_68;
  _SVector local_60;
  _SVector _Stack88;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  long local_3c;
  long local_38;
  long local_34;
  _G2EulerAngles_Type local_30[2];

  if (parent != (_Instance *)0x0)
  {
    local_a0 = *(uint *)&parent->position;
    local_9c = (parent->position).z;
    bVar6 = false;
    if (instance->matrix != (MATRIX *)0x0)
    {
      iVar11 = 0;
      pMVar9 = instance->matrix;
      (instance->position).x = *(short *)instance->matrix->t;
      (instance->position).y = *(short *)(pMVar9->t + 1);
      (instance->position).z = *(short *)(pMVar9->t + 2);
      do
      {
        local_90.vy = local_a0._2_2_;
        pMVar9 = instance->matrix + iVar11;
        local_90.vx = (short)local_a0;
        local_90.vz = *(short *)(pMVar9->t + 2) + 100;
        iVar7 = ((int)(((uint) * (ushort *)pMVar9->t - (local_a0 & 0xffff)) * 0x10000) >> 0x10) * 6000;
        if (iVar7 < 0)
        {
          iVar7 = iVar7 + 0xfff;
        }
        iVar8 = (int)(short)(*(short *)(pMVar9->t + 1) - local_a0._2_2_) * 6000;
        local_88 = (short)(iVar7 >> 0xc);
        if (iVar8 < 0)
        {
          iVar8 = iVar8 + 0xfff;
        }
        local_86 = (short)(iVar8 >> 0xc);
        iVar7 = (int)(short)(*(short *)(pMVar9->t + 2) - local_90.vz) * 6000;
        if (iVar7 < 0)
        {
          iVar7 = iVar7 + 0xfff;
        }
        local_84 = (short)(iVar7 >> 0xc);
        local_94 = local_84 + local_90.vz;
        local_98 = CONCAT22(local_86 + local_a0._2_2_, local_88 + (short)local_a0);
        local_80 = local_98;
        local_d0.newPoint = (SVECTOR *)&local_98;
        local_d0.oldPoint = &local_90;
        local_7c = local_94;
        SetNoPtCollideInFamily(parent);
        PHYSICS_CheckLineInWorld(instance, &local_d0);
        ResetNoPtCollideInFamily(parent);
        if ((local_d0.type != 0) && (local_d0.wNormal.vz < 0xed9))
        {
          bVar6 = true;
        }
        iVar11 = iVar11 + 2;
      } while ((iVar11 < 3) && (!bVar6));
      if (bVar6)
      {
        local_78 = *(short *)instance->matrix->t;
        local_76 = *(short *)(instance->matrix->t + 1);
        local_74 = *(short *)(instance->matrix->t + 2);
        local_70 = *(short *)instance->matrix[2].t;
        local_6e = *(short *)(instance->matrix[2].t + 1);
        local_6c = *(short *)(instance->matrix[2].t + 2);
        local_68.x = local_70 - local_78;
        local_68.y = local_6e - local_76;
        local_68.z = local_6c - local_74;
        MATH3D_Normalize(&local_68);
        local_60.x = 10;
        local_60.y = 0;
        local_60.z = 0x1000;
        angle = MATH3D_AngleBetweenVectors(&local_60, (_SVector *)&local_68);
        MATH3D_CrossProduct(&_Stack88, (_SVector *)&local_68, &local_60);
        pMVar9 = instance->matrix;
        local_50 = *(undefined4 *)pMVar9->m;
        local_4c = *(undefined4 *)(pMVar9->m + 2);
        local_48 = *(undefined4 *)(pMVar9->m + 4);
        local_44 = *(undefined4 *)(pMVar9->m + 6);
        local_40 = *(undefined4 *)(pMVar9->m + 8);
        local_3c = pMVar9->t[0];
        local_38 = pMVar9->t[1];
        local_34 = pMVar9->t[2];
        MATH3D_RotMatAboutVec(&_Stack88, (MATRIX *)(_G2Matrix_Type *)&local_50, angle);
        G2EulerAngles_FromMatrix(local_30, (_G2Matrix_Type *)&local_50, 0);
        (instance->rotation).x = local_30[0].x;
        (instance->rotation).y = local_30[0].y;
        (instance->rotation).z = local_30[0].z;
        angle = (parent->position).z;
        *(undefined4 *)&instance->position = *(undefined4 *)&parent->position;
        (instance->position).z = angle;
        pMVar9 = instance->matrix;
        angle = *(short *)pMVar9->t;
        sVar1 = (instance->position).x;
        p_Var10 = instance->object->modelList[(int)instance->currentModel];
        sVar2 = (instance->position).y;
        sVar3 = *(short *)(pMVar9->t + 1);
        sVar4 = *(short *)(pMVar9->t + 2);
        sVar5 = (instance->position).z;
        iVar11 = 0;
        if (0 < p_Var10->numSegments)
        {
          do
          {
            pMVar9 = instance->matrix + iVar11;
            pMVar9->t[0] = pMVar9->t[0] + (int)(short)(sVar1 - angle);
            pMVar9->t[1] = pMVar9->t[1] + (int)(short)(sVar2 - sVar3);
            pMVar9->t[2] = pMVar9->t[2] + (int)(short)(sVar5 - (sVar4 + -0x14));
            iVar11 = iVar11 + 1;
          } while (iVar11 < p_Var10->numSegments);
        }
      }
      (instance->position).z = (instance->position).z + 0x14;
      return 1;
    }
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOB_CheckDirectedLineCollision(struct _Instance *instance /*$a0*/, int xoffset /*$a1*/, int yoffset /*$a2*/, int startZOffset /*$a3*/)
// line 4566, offset 0x8006ec78
/* begin block 1 */
// Start line: 4567
// Start offset: 0x8006EC78
// Variables:
// 		struct _PCollideInfo pcollideInfo; // stack offset -72
// 		struct _Position newPos; // stack offset -24
// 		struct _Position oldPos; // stack offset -16
// 		struct MATRIX *mat; // $v0
/* end block 1 */
// End offset: 0x8006EC78
// End Line: 4567

/* begin block 2 */
// Start line: 10074
/* end block 2 */
// End Line: 10075

int PHYSOB_CheckDirectedLineCollision(_Instance *instance, int xoffset, int yoffset, int startZOffset)

{
  MATRIX *pMVar1;
  _PCollideInfo local_48;
  SVECTOR local_18;
  SVECTOR local_10;

  pMVar1 = instance->matrix;
  local_10.vx = *(short *)pMVar1[1].t;
  local_18.vx = local_10.vx + (short)xoffset;
  local_10.vy = *(short *)(pMVar1[1].t + 1);
  local_18.vy = local_10.vy + (short)yoffset;
  local_48.newPoint = &local_18;
  local_48.oldPoint = &local_10;
  local_18.vz = *(short *)(pMVar1[1].t + 2) + (short)startZOffset;
  local_10.vz = local_18.vz;
  PHYSICS_CheckLineInWorld(instance, &local_48);
  return (int)local_48.type;
}

// decompiled code
// original method signature:
// long /*$ra*/ PHYSOBS_CheckForStackedForwardHits(struct _Instance *block /*$a0*/, long xoffset /*$s2*/, long yoffset /*$s3*/)
// line 4587, offset 0x8006ecec
/* begin block 1 */
// Start line: 4588
// Start offset: 0x8006ECEC
// Variables:
// 		struct _Instance *attachedBlock; // $s0
// 		long result; // $s1
/* end block 1 */
// End offset: 0x8006ED48
// End Line: 4607

/* begin block 2 */
// Start line: 10140
/* end block 2 */
// End Line: 10141

long PHYSOBS_CheckForStackedForwardHits(_Instance *block, long xoffset, long yoffset)

{
  int iVar1;

  do
  {
    block = PHYSOBS_IsAPushBlockAttached(block);
    if (block == (_Instance *)0x0)
    {
      return 0;
    }
    iVar1 = PHYSOB_CheckDirectedLineCollision(block, xoffset, yoffset, 0);
  } while (iVar1 == 0);
  return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOBS_SetNewAnim(struct _Instance *instance /*$s1*/, struct PhysObData *Data /*$s0*/, unsigned long modeBits /*$a2*/, int path /*$s2*/, int resetflg /*stack 16*/)
// line 4610, offset 0x8006ed68
/* begin block 1 */
// Start line: 10188
/* end block 1 */
// End Line: 10189

void PHYSOBS_SetNewAnim(_Instance *instance, PhysObData *Data, ulong modeBits, int path, int resetflg)

{
  Data->PathNumber = (short)path;
  Data->Mode = Data->Mode & 0xfffffffeU | modeBits;
  if (resetflg != 0)
  {
    ResetOrientation(instance);
  }
  PhysOb_AlignPush(instance, (int)Data->xForce, (int)Data->yForce, path, Data);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ PHYSOB_CheckForEnemyInBlkSpot(struct _Instance *instance /*$a0*/, int dx /*$a1*/, int dy /*$a2*/)
// line 4623, offset 0x8006ede0
/* begin block 1 */
// Start line: 4624
// Start offset: 0x8006EDE0
// Variables:
// 		int x; // $v0
// 		int y; // $v1
// 		int z; // $v0
// 		int x0; // $s6
// 		int x1; // $s5
// 		int y0; // $s4
// 		int y1; // $s3
// 		int z0; // $s2
// 		int z1; // $s1
// 		struct _Instance *inst; // $s0
/* end block 1 */
// End offset: 0x8006EEEC
// End Line: 4646

/* begin block 2 */
// Start line: 10217
/* end block 2 */
// End Line: 10218

long PHYSOB_CheckForEnemyInBlkSpot(_Instance *instance, int dx, int dy)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  _Instance *Inst;

  dy = (int)(instance->position).y + dy;
  Inst = (gameTrackerX.instanceList)->first;
  dx = (int)(instance->position).x + dx;
  iVar1 = (int)(instance->position).z;
  while (true)
  {
    if (Inst == (_Instance *)0x0)
    {
      return 0;
    }
    if (((((((Inst->object->oflags2 & 0x80000U) != 0) && ((Inst->flags2 & 0x8000000U) == 0)) &&
           (uVar2 = INSTANCE_Query(Inst, 0), (uVar2 & 0x40000000) == 0)) &&
          ((iVar3 = (int)(Inst->position).x, dx + -0x140 <= iVar3 && (iVar3 <= dx + 0x140)))) &&
         ((iVar3 = (int)(Inst->position).y, dy + -0x140 <= iVar3 &&
                                                ((iVar3 <= dy + 0x140 && (iVar3 = (int)(Inst->position).z, iVar1 + -0x140 <= iVar3)))))) &&
        (iVar3 <= iVar1 + 0x140))
      break;
    Inst = Inst->next;
  }
  return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ PHYSOBS_CheckForValidMove(struct _Instance *instance /*$s2*/)
// line 4649, offset 0x8006ef14
/* begin block 1 */
// Start line: 4650
// Start offset: 0x8006EF14
// Variables:
// 		int rc; // $s1
// 		struct PhysObData *Data; // $s0
// 		struct evPhysicsSlideData *Ptr; // stack offset -32
// 		int result; // stack offset -28

/* begin block 1.1 */
// Start line: 4735
// Start offset: 0x8006F070
// Variables:
// 		int Height; // $v0
/* end block 1.1 */
// End offset: 0x8006F0C0
// End Line: 4748

/* begin block 1.2 */
// Start line: 4972
// Start offset: 0x8006F32C
// Variables:
// 		struct evPhysicsSlideData *Ptr; // stack offset -24
/* end block 1.2 */
// End offset: 0x8006F420
// End Line: 5017
/* end block 1 */
// End offset: 0x8006F444
// End Line: 5033

/* begin block 2 */
// Start line: 10284
/* end block 2 */
// End Line: 10285

long PHYSOBS_CheckForValidMove(_Instance *instance)

{
  short sVar1;
  ushort uVar2;
  int Data;
  long lVar3;
  uint uVar4;
  uint uVar5;
  PhysObData *Data_00;
  evPhysicsSlideData *local_20;
  uint local_1c;
  evPhysicsSlideData *local_18[2];

  gameTrackerX.block_collide_override = '\x01';
  Data_00 = (PhysObData *)instance->extraData;
  local_1c = 7;
  if ((Data_00->Mode & 1U) != 0)
  {
    Data = SetPhysicsGravityData(0xa0, 0x280, 0, 0, 0, 0xb50);
    PhysicsUpdateTface(instance, Data);
    lVar3 = PHYSOBS_CheckForStackedForwardHits(instance, (int)Data_00->xForce * 0x2c0, (int)Data_00->yForce * 0x2c0);
    if (lVar3 == 0)
    {
      uVar4 = PHYSOB_CheckSlide(instance, (int)Data_00->xForce, (int)Data_00->yForce, &local_20);
      if ((uVar4 & 2) == 0)
      {
        if ((uVar4 & 0x4000) == 0)
        {
          uVar5 = PHYSOB_CheckDropOnSlope(instance, (int)Data_00->xForce, (int)Data_00->yForce, local_18);
          if (((uVar5 & 0x4000) == 0) || (0xf3c < (local_18[0]->DropNormal).z))
          {
            if (((Data_00->Mode & 8U) != 0) && ((uVar4 & 0x8000) != 0))
            {
              local_1c = 0;
            }
            uVar2 = Data_00->PathNumber;
            if ((1 < (uint)uVar2 - 2) && (local_1c != 0))
            {
              if ((int)(short)uVar2 == 5)
              {
                local_1c = local_1c & 0xfffffffa;
              }
              else
              {
                if ((Data_00->Mode & 8U) == 0)
                {
                  PHYSOBS_SetNewAnim(instance, Data_00, 2, (int)(short)uVar2, 1);
                }
                else
                {
                  Data_00->PathNumber = 0xe;
                  PHYSOBS_SetNewAnim(instance, Data_00, 2, 0xe, 1);
                }
              }
              goto LAB_8006f428;
            }
          }
        }
        else
        {
          if ((Data_00->Mode & 8U) != 0)
          {
            if ((Data_00->Mode & 0x200U) != 0)
            {
              local_1c = 0;
            }
            if (((uVar4 & 0x8000) != 0) ||
                (Data = PHYSOB_CheckDirectedLineCollision(instance, (int)Data_00->xForce * 0x2c0, (int)Data_00->yForce * 0x2c0, 0x280), Data != 0))
            {
              local_1c = 0;
            }
          }
          if (local_1c == 0)
            goto LAB_8006f428;
          Data = CheckSlope(local_20->Dot, -0x13a, 4);
          if (((Data == 0) && (Data = CheckSlope(local_20->Dot, 0x13a, 4), Data == 0)) &&
              ((Data_00->Mode & 0x200U) == 0))
          {
            Data = CheckSlope((int)(local_20->DropNormal).z, 0xe4f, 4);
            if (Data == 0)
            {
              lVar3 = PHYSOB_CheckForEnemyInBlkSpot(instance, (int)Data_00->xForce * 0x280, (int)Data_00->yForce * 0x280);
              if (((lVar3 == 0) ||
                   (Data = PHYSOB_CheckDirectedLineCollision(instance, (int)Data_00->xForce * 0x540,
                                                             (int)Data_00->yForce * 0x540, 0),
                    Data == 0)) &&
                  (Data = CheckSlope((int)(local_20->DropNormal).z, 0x1000, 4), Data != 0))
              {
                PHYSOBS_SetNewAnim(instance, Data_00, 2, (int)Data_00->PathNumber, 0);
                goto LAB_8006f428;
              }
            }
            else
            {
              sVar1 = (local_20->DropNormal).x;
              if ((((((10 < sVar1) && (0 < Data_00->xForce)) ||
                     ((sVar1 < -10 && (Data_00->xForce < 0)))) ||
                    ((sVar1 = (local_20->DropNormal).y, 10 < sVar1 && (0 < Data_00->yForce)))) ||
                   ((sVar1 < -10 && (Data_00->yForce < 0)))) &&
                  (Data = CheckBlockSlope(instance, (int)Data_00->xForce, (int)Data_00->yForce, 0x2dc,
                                          -0xad, 0x271, -0x138),
                   Data == 0))
              {
                Data = PHYSOBS_FigureDragForSlope(instance, (int)Data_00->PathNumber, (int *)&local_1c);
                if (Data == 0)
                {
                  local_1c = 0;
                }
                goto LAB_8006f428;
              }
            }
          }
        }
      }
      else
      {
        Data = CheckSlope((int)(local_20->ForwardNormal).z, 0xe4f, 4);
        if (((((Data == 0) &&
               (Data = CheckSlope((int)(local_20->ForwardNormal).z, 0x1000, 4), Data == 0)) &&
              ((Data_00->Mode & 8U) != 0)) &&
             (((uVar4 & 4) != 0 &&
               (Data = PHYSOB_CheckDirectedLineCollision(instance, (int)Data_00->xForce * 0x2c0, (int)Data_00->yForce * 0x2c0,
                                                         0x280),
                Data == 0)))) &&
            (0xa9U - (int)local_20->Height < 0x13))
        {
          PHYSOBS_SetNewAnim(instance, Data_00, 2, 7, 1);
          local_1c = local_1c & 0xfffffffb | 8;
          goto LAB_8006f428;
        }
      }
    }
  }
  local_1c = 0;
LAB_8006f428:
  gameTrackerX.block_collide_override = '\0';
  if (local_1c == 0)
  {
    Data_00->Mode = Data_00->Mode & 0xfffffeb5;
  }
  return local_1c;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExecuteGravitate(struct _Instance *instance /*$s1*/)
// line 5037, offset 0x8006f460
/* begin block 1 */
// Start line: 5038
// Start offset: 0x8006F460
// Variables:
// 		struct PhysObData *Data; // $s0
// 		struct _Instance *Force; // $s4
// 		struct _G2EulerAngles_Type ea; // stack offset -48
// 		struct _Vector Position; // stack offset -40
// 		struct _Model *model; // $s3
// 		struct MATRIX *forceMatrix; // $s2
// 		int scale; // $v1
/* end block 1 */
// End offset: 0x8006F7B4
// End Line: 5154

/* begin block 2 */
// Start line: 11082
/* end block 2 */
// End Line: 11083

void ExecuteGravitate(_Instance *instance)

{
  int iVar1;
  short sVar2;
  MATRIX *pMVar3;
  uint *puVar4;
  _G2Matrix_Type *matrix;
  _Model *p_Var5;
  _Instance *parent;
  _G2EulerAngles_Type local_30;
  int local_28;
  int local_24;
  int local_20;

  puVar4 = (uint *)instance->extraData;
  parent = (_Instance *)puVar4[2];
  p_Var5 = *instance->object->modelList;
  matrix = (_G2Matrix_Type *)(parent->matrix + (int)*(short *)(puVar4 + 3));
  iVar1 = CheckPhysObAbility(instance, 1);
  if (iVar1 != 0)
  {
    COLLIDE_SegmentCollisionOff(instance, 1);
  }
  if (*(short *)(puVar4 + 9) != 0)
  {
    G2EulerAngles_FromMatrix(&local_30, matrix, 0x15);
    if (*(short *)((int)puVar4 + 0x26) == 0)
    {
      *(short *)(puVar4 + 5) = (instance->rotation).x;
      *(short *)((int)puVar4 + 0x16) = (instance->rotation).y;
      *(short *)(puVar4 + 6) = (instance->rotation).z;
      *(short *)((int)puVar4 + 0xe) = (instance->position).x;
      *(short *)(puVar4 + 4) = (instance->position).y;
      *(short *)((int)puVar4 + 0x12) = (instance->position).z;
    }
    (instance->rotation).x =
        *(short *)(puVar4 + 5) +
        (short)((((int)local_30.x - (int)*(short *)(puVar4 + 5)) *
                 (int)*(short *)((int)puVar4 + 0x26)) /
                (int)*(short *)(puVar4 + 9));
    (instance->rotation).y =
        *(short *)((int)puVar4 + 0x16) +
        (short)((((int)local_30.y - (int)*(short *)((int)puVar4 + 0x16)) *
                 (int)*(short *)((int)puVar4 + 0x26)) /
                (int)*(short *)(puVar4 + 9));
    pMVar3 = instance->matrix;
    (instance->rotation).z =
        *(short *)(puVar4 + 6) +
        (short)((((int)local_30.z - (int)*(short *)(puVar4 + 6)) *
                 (int)*(short *)((int)puVar4 + 0x26)) /
                (int)*(short *)(puVar4 + 9));
    ApplyMatrix(pMVar3 + 2, &p_Var5->segmentList[2].px, &local_28);
    local_28 = (matrix->trans).x - local_28;
    local_24 = (matrix->trans).y - local_24;
    local_20 = (matrix->trans).z - local_20;
    (instance->position).x =
        *(short *)((int)puVar4 + 0xe) +
        (short)(((local_28 - (int)*(short *)((int)puVar4 + 0xe)) *
                 (int)*(short *)((int)puVar4 + 0x26)) /
                (int)*(short *)(puVar4 + 9));
    (instance->position).y =
        *(short *)(puVar4 + 4) +
        (short)(((local_24 - (int)*(short *)(puVar4 + 4)) * (int)*(short *)((int)puVar4 + 0x26)) /
                (int)*(short *)(puVar4 + 9));
    (instance->position).z =
        *(short *)((int)puVar4 + 0x12) +
        (short)(((local_20 - (int)*(short *)((int)puVar4 + 0x12)) *
                 (int)*(short *)((int)puVar4 + 0x26)) /
                (int)*(short *)(puVar4 + 9));
    *(short *)((int)puVar4 + 0x26) = *(short *)((int)puVar4 + 0x26) + 1;
  }
  if ((*puVar4 & 0x20000) != 0)
  {
    if ((int)*(short *)(puVar4 + 9) == 0)
    {
      sVar2 = 0x1000;
    }
    else
    {
      sVar2 = 0x1000 - (short)(((int)*(short *)((int)puVar4 + 0x26) << 0xc) /
                               (int)*(short *)(puVar4 + 9));
    }
    (instance->scale).z = sVar2;
    (instance->scale).y = sVar2;
    (instance->scale).x = sVar2;
  }
  if (*(short *)((int)puVar4 + 0x26) == *(short *)(puVar4 + 9))
  {
    if ((*puVar4 & 0x20000) == 0)
    {
      *puVar4 = *puVar4 & 0xfefdbffa | 0x1080;
      TurnOffCollisionPhysOb(instance, 7);
      INSTANCE_LinkToParent(instance, parent, (int)*(short *)(puVar4 + 3));
      puVar4[2] = 0;
      *(undefined2 *)((int)puVar4 + 0x26) = 0;
      *(undefined2 *)(puVar4 + 9) = 0;
      instance->xVel = 0;
      instance->yVel = 0;
      instance->zVel = 0;
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = 0;
    }
    else
    {
      INSTANCE_KillInstance(instance);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExecuteFollow(struct _Instance *instance /*$a0*/)
// line 5157, offset 0x8006f7d4
/* begin block 1 */
// Start line: 5159
// Start offset: 0x8006F7D4
// Variables:
// 		struct PhysObData *Data; // $a1
// 		struct _Instance *Force; // $a2
/* end block 1 */
// End offset: 0x8006F7D4
// End Line: 5162

/* begin block 2 */
// Start line: 11364
/* end block 2 */
// End Line: 11365

/* begin block 3 */
// Start line: 11365
/* end block 3 */
// End Line: 11366

/* begin block 4 */
// Start line: 11368
/* end block 4 */
// End Line: 11369

void ExecuteFollow(_Instance *instance)

{
  void *pvVar1;
  int iVar2;

  pvVar1 = instance->extraData;
  iVar2 = *(int *)((int)pvVar1 + 8);
  (instance->position).x =
      *(short *)((int)*(short *)((int)pvVar1 + 0x1a) * 0x20 + *(int *)(iVar2 + 0x40) + 0x14) +
      *(short *)((int)pvVar1 + 0xe);
  (instance->position).y =
      *(short *)((int)*(short *)((int)pvVar1 + 0x1a) * 0x20 + *(int *)(iVar2 + 0x40) + 0x18) +
      *(short *)((int)pvVar1 + 0x10);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_Normalize(struct _SVector *v /*$s0*/)
// line 5179, offset 0x8006f82c
/* begin block 1 */
// Start line: 5180
// Start offset: 0x8006F82C
// Variables:
// 		long len; // $a1
/* end block 1 */
// End offset: 0x8006F870
// End Line: 5187

/* begin block 2 */
// Start line: 11408
/* end block 2 */
// End Line: 11409

void PHYSOB_Normalize(_SVector *v)

{
  ulong square;
  long lVar1;

  square = MATH3D_SquareLength((int)v->x, (int)v->y, (int)v->z);
  if (square == 0)
  {
    lVar1 = 1;
  }
  else
  {
    lVar1 = MATH3D_FastSqrt0(square);
  }
  v->x = (short)(((int)v->x << 0xc) / lVar1);
  v->y = (short)(((int)v->y << 0xc) / lVar1);
  v->z = (short)(((int)v->z << 0xc) / lVar1);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOB_MoveTowardsAlign(struct _Instance *instance /*$s2*/, struct _SVector *orgVec /*$s0*/, struct _SVector *endVec /*$s1*/)
// line 5194, offset 0x8006f8c8
/* begin block 1 */
// Start line: 5195
// Start offset: 0x8006F8C8
// Variables:
// 		struct MATRIX xform; // stack offset -104
// 		struct MATRIX dest; // stack offset -72
// 		struct MATRIX *src; // $s4
// 		struct _G2Quat_Type rot; // stack offset -40
// 		long len; // $s0
// 		int theta; // $s1
// 		int sintheta; // $v0
// 		struct _G2EulerAngles_Type ea; // stack offset -32
/* end block 1 */
// End offset: 0x8006FAAC
// End Line: 5239

/* begin block 2 */
// Start line: 11440
/* end block 2 */
// End Line: 11441

int PHYSOB_MoveTowardsAlign(_Instance *instance, _SVector *orgVec, _SVector *endVec)

{
  int iVar1;
  int iVar2;
  ulong square;
  uint uVar3;
  long lVar4;
  uint uVar5;
  MATRIX *pMVar6;
  undefined4 auStack104[8];
  _G2Matrix_Type _Stack72;
  short local_28;
  short local_26;
  short local_24;
  undefined2 local_22;
  _G2EulerAngles_Type local_20;

  iVar1 = gameTrackerX.timeMult * 0x32;
  PHYSOB_Normalize(orgVec);
  PHYSOB_Normalize(endVec);
  pMVar6 = instance->matrix;
  iVar2 = (int)orgVec->y * (int)endVec->z - (int)orgVec->z * (int)endVec->y;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_28 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->z * (int)endVec->x - (int)orgVec->x * (int)endVec->z;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_26 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->x * (int)endVec->y - (int)orgVec->y * (int)endVec->x;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  local_24 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->x * (int)endVec->x + (int)orgVec->y * (int)endVec->y +
          (int)orgVec->z * (int)endVec->z;
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  iVar2 = MATH3D_racos_S(iVar2 >> 0xc);
  uVar5 = (int)(((iVar2 << 0x10) >> 0x10) + ((uint)(iVar2 << 0x10) >> 0x1f)) >> 1;
  uVar3 = SEXT24((short)(iVar1 >> 0xc));
  if ((int)uVar5 < (int)-uVar3)
  {
    uVar5 = -uVar3;
  }
  if ((int)uVar3 < (int)uVar5)
  {
    uVar5 = uVar3;
  }
  square = MATH3D_SquareLength((int)local_28, (int)local_26, (int)local_24);
  if ((int)square < 1)
  {
    lVar4 = 0x1000;
  }
  else
  {
    lVar4 = MATH3D_FastSqrt0(square);
  }
  iVar1 = rsin(uVar5);
  local_28 = (short)(((int)local_28 * iVar1) / lVar4);
  local_26 = (short)(((int)local_26 * iVar1) / lVar4);
  local_24 = (short)(((int)local_24 * iVar1) / lVar4);
  iVar1 = rcos(uVar5);
  local_22 = (undefined2)iVar1;
  G2Quat_ToMatrix_S(&local_28, (short *)auStack104);
  MulMatrix0(auStack104, (ushort *)pMVar6, (uint *)&_Stack72);
  G2EulerAngles_FromMatrix(&local_20, &_Stack72, 0x15);
  (instance->rotation).x = local_20.x;
  (instance->rotation).y = local_20.y;
  (instance->rotation).z = local_20.z;
  return (uint)((int)uVar5 < 0x14);
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOB_ReAlignFalling(struct _Instance *instance /*$s5*/, int zEndOff /*$fp*/)
// line 5257, offset 0x8006fba0
/* begin block 1 */
// Start line: 5258
// Start offset: 0x8006FBA0
// Variables:
// 		struct _Model *model; // $s6
// 		int i; // $s2
// 		struct _Position seg0; // stack offset -208
// 		struct _Position segn; // stack offset -200
// 		struct _Position start0; // stack offset -192
// 		struct _Position startn; // stack offset -184
// 		int startFlg; // $s3
// 		short zOff; // $s7

/* begin block 1.1 */
// Start line: 5309
// Start offset: 0x8006FC08
// Variables:
// 		struct _PCollideInfo pcollideInfo; // stack offset -176
// 		struct _Position newPos; // stack offset -128
// 		struct _Position oldPos; // stack offset -120
// 		short x; // $s1
// 		short y; // $s0
// 		struct MATRIX *mat; // $v0

/* begin block 1.1.1 */
// Start line: 5328
// Start offset: 0x8006FC80
// Variables:
// 		short ax; // $a1
// 		short ay; // $a2
/* end block 1.1.1 */
// End offset: 0x8006FD78
// End Line: 5358

/* begin block 1.1.2 */
// Start line: 5366
// Start offset: 0x8006FDA4
/* end block 1.1.2 */
// End offset: 0x8006FE90
// End Line: 5394
/* end block 1.1 */
// End offset: 0x8006FE90
// End Line: 5396

/* begin block 1.2 */
// Start line: 5403
// Start offset: 0x8006FEAC
// Variables:
// 		short _x0; // $a3
// 		short _y0; // $v0
// 		short _z0; // $v1
// 		short _x1; // $a1
// 		short _y1; // $t0
// 		short _z1; // $a2
// 		struct _Position *_v; // $a0
// 		struct _Position *_v1; // $a2
/* end block 1.2 */
// End offset: 0x8006FEAC
// End Line: 5403

/* begin block 1.3 */
// Start line: 5403
// Start offset: 0x8006FEAC
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a0
// 		short _x1; // $a2
// 		short _y1; // $t1
// 		short _z1; // $t0
// 		struct _Position *_v; // $a1
// 		struct _Position *_v1; // $t0
/* end block 1.3 */
// End offset: 0x8006FEAC
// End Line: 5403

/* begin block 1.4 */
// Start line: 5425
// Start offset: 0x8006FFB4
// Variables:
// 		struct _PCollideInfo pcollideInfo; // stack offset -112
// 		struct _Position newPos; // stack offset -64
// 		struct _Position oldPos; // stack offset -56
// 		struct _Position deltaPos; // stack offset -48
// 		struct MATRIX *mat; // $a2
/* end block 1.4 */
// End offset: 0x80070058
// End Line: 5481
/* end block 1 */
// End offset: 0x80070094
// End Line: 5485

/* begin block 2 */
// Start line: 11588
/* end block 2 */
// End Line: 11589

/* WARNING: Could not reconcile some variable overlaps */

int PHYSOB_ReAlignFalling(_Instance *instance, int zEndOff)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  MATRIX *pMVar10;
  uint uVar11;
  undefined4 uVar12;
  short sVar13;
  short sVar14;
  int iVar15;
  int iVar16;
  _Model *p_Var17;
  uint uVar18;
  undefined4 local_d0;
  ushort local_cc;
  undefined4 local_c8;
  ushort local_c4;
  undefined4 local_c0;
  short local_bc;
  undefined4 local_b8;
  short local_b4;
  _PCollideInfo local_b0;
  uint local_80;
  ushort local_7c;
  uint local_78;
  short local_74;
  _PCollideInfo local_70;
  SVECTOR local_40;
  SVECTOR local_38[2];

  uVar18 = 0xffff8300;
  p_Var17 = instance->object->modelList[(int)instance->currentModel];
  iVar15 = 0;
  bVar3 = false;
  if (0 < p_Var17->numSegments)
  {
    iVar16 = 0;
    uVar7 = uVar18;
    do
    {
      sVar14 = 0;
      sVar13 = 0;
      if ((p_Var17->segmentList[iVar15].hInfo != (_HInfo *)0x0) || (uVar18 = uVar7, iVar15 == 0))
      {
        iVar5 = (int)instance->matrix->m + iVar16;
        uVar1 = *(ushort *)(iVar5 + 0x14);
        uVar2 = *(ushort *)(iVar5 + 0x18);
        local_78 = CONCAT22(uVar2, uVar1);
        local_80 = CONCAT22(uVar2, uVar1);
        local_7c = *(short *)(iVar5 + 0x1c) + (short)zEndOff;
        local_74 = *(short *)(iVar5 + 0x1c) + 300;
        if (bVar3)
        {
          iVar5 = (uint)uVar1 - (local_c0 & 0xffff);
          iVar9 = (uint)uVar2 - (local_c0 >> 0x10);
          iVar6 = iVar5 * 0x10000;
          sVar4 = (short)((uint)iVar6 >> 0x10);
          if (iVar6 >> 0x10 < 0)
          {
            sVar4 = -sVar4;
          }
          iVar6 = iVar9 * 0x10000;
          sVar8 = (short)((uint)iVar6 >> 0x10);
          if (iVar6 >> 0x10 < 0)
          {
            sVar8 = -sVar8;
          }
          if ((sVar4 < 100) && (sVar8 < 100))
          {
            if ((sVar4 == 0) && (sVar8 == 0))
            {
              sVar14 = 0x40;
              sVar13 = 0;
            }
            else
            {
              sVar14 = (short)iVar5;
              sVar13 = (short)iVar9;
              if ((sVar4 < 0x14) && (sVar8 < 0x14))
              {
                sVar14 = sVar14 * 0x10;
                sVar13 = sVar13 * 0x10;
              }
              else
              {
                sVar14 = sVar14 * 4;
                sVar13 = sVar13 * 4;
              }
            }
            local_78 = CONCAT22(uVar2 + sVar13, uVar1 + sVar14);
            local_80 = CONCAT22(uVar2 + sVar13, uVar1 + sVar14);
          }
          else
          {
            sVar13 = 0;
            sVar14 = 0;
          }
        }
        local_b0.newPoint = (SVECTOR *)&local_80;
        local_b0.oldPoint = (SVECTOR *)&local_78;
        PHYSICS_CheckLineInWorld(instance, &local_b0);
        uVar18 = uVar7;
        if (local_b0.type != 0)
        {
          uVar18 = (uint)local_7c - (uint) * (ushort *)((int)instance->matrix->t + iVar16 + 8);
          if ((int)(uVar18 * 0x10000) < (int)(uVar7 << 0x10))
          {
            uVar18 = uVar7;
          }
          if (bVar3)
          {
            local_c8 = local_80;
            local_c4 = local_7c;
            local_b4 = local_74;
            local_b8._0_2_ = (short)local_78;
            local_b8._2_2_ = (short)(local_78 >> 0x10);
            local_b8 = CONCAT22(local_b8._2_2_ - sVar13, (short)local_b8 - sVar14);
          }
          else
          {
            local_d0 = local_80;
            local_cc = local_7c;
            local_c0 = local_78;
            local_bc = local_74;
            local_c8 = local_80;
            local_c4 = local_7c;
            local_b8 = local_78;
            local_b4 = local_74;
            bVar3 = true;
          }
        }
      }
      iVar15 = iVar15 + 1;
      iVar16 = iVar16 + 0x20;
      uVar7 = uVar18;
    } while (iVar15 < p_Var17->numSegments);
  }
  uVar7 = 1;
  if (bVar3)
  {
    instance->zAccl = 0;
    instance->zVel = 0;
    (instance->position).z = *(short *)(instance->matrix->t + 2) + (short)uVar18;
    uVar11 = (local_b8 & 0xffff) - (local_c0 & 0xffff);
    local_b4 = local_b4 - local_bc;
    local_b8 = uVar11 & 0xffff | (uint)(ushort)(local_b8._2_2_ - local_c0._2_2_) << 0x10;
    uVar7 = (local_c8 & 0xffff) - (local_d0 & 0xffff);
    local_c4 = local_c4 - local_cc;
    local_c8 = uVar7 & 0xffff | (uint)(ushort)(local_c8._2_2_ - local_d0._2_2_) << 0x10;
    if ((((uVar11 * 0x10000 != uVar7 * 0x10000) ||
          ((short)(local_b8._2_2_ - local_c0._2_2_) != (short)(local_c8._2_2_ - local_d0._2_2_))) ||
         (local_b4 != local_c4)) ||
        (uVar7 = 1, (uVar18 & 0xffff) != 0))
    {
      iVar16 = 1;
      iVar15 = 0x18;
      if (1 < p_Var17->numSegments)
      {
        do
        {
          if ((*(int *)((int)&p_Var17->segmentList->hInfo + iVar15) != 0) || (iVar16 == 0))
          {
            pMVar10 = instance->oldMatrix + iVar16;
            local_38[0].vx = *(short *)pMVar10->t;
            local_38[0].vy = *(short *)(pMVar10->t + 1);
            local_38[0].vz = *(short *)(pMVar10->t + 2);
            pMVar10 = instance->matrix + iVar16;
            local_40.vx = *(short *)pMVar10->t;
            local_40.vy = *(short *)(pMVar10->t + 1);
            local_40.vz = *(short *)(pMVar10->t + 2);
            local_70.newPoint = &local_40;
            local_70.oldPoint = local_38;
            PHYSICS_CheckLineInWorld(instance, &local_70);
            if (local_70.type != 0)
            {
              uVar12 = *(undefined4 *)&(instance->oldRotation).z;
              *(undefined4 *)&instance->rotation = *(undefined4 *)&instance->oldRotation;
              *(undefined4 *)&(instance->rotation).z = uVar12;
              return 1;
            }
          }
          iVar16 = iVar16 + 1;
          iVar15 = iVar15 + 0x18;
        } while (iVar16 < p_Var17->numSegments);
      }
      iVar15 = PHYSOB_MoveTowardsAlign(instance, (_SVector *)&local_b8, (_SVector *)&local_c8);
      uVar7 = 0;
      if ((uVar18 & 0xffff) == 0)
      {
        uVar7 = (uint)(iVar15 != 0);
      }
    }
  }
  return uVar7;
}

// decompiled code
// original method signature:
// void /*$ra*/ DropPhysOb(struct _Instance *instance /*$s1*/, int flags /*$s3*/)
// line 5488, offset 0x800700c4
/* begin block 1 */
// Start line: 5489
// Start offset: 0x800700C4
// Variables:
// 		struct PhysObData *Data; // $s0
// 		struct _Instance *parent; // $s2
/* end block 1 */
// End offset: 0x80070190
// End Line: 5549

/* begin block 2 */
// Start line: 12348
/* end block 2 */
// End Line: 12349

void DropPhysOb(_Instance *instance, int flags)

{
  int zEndOff;
  uint *puVar1;
  _Instance *parent;

  parent = instance->LinkParent;
  puVar1 = (uint *)instance->extraData;
  if (parent == (_Instance *)0x0)
  {
    *puVar1 = *puVar1 & 0xff7fffff;
  }
  else
  {
    INSTANCE_UnlinkFromParent(instance);
  }
  PHYSOB_CheckDroppedLineCollision(instance, parent);
  if ((flags & 2U) == 0)
  {
    if ((flags & 4U) == 0)
    {
      zEndOff = 0;
      if (parent != (_Instance *)0x0)
      {
        zEndOff = -900;
      }
      PHYSOB_ReAlignFalling(instance, zEndOff);
    }
    *(_Instance **)(puVar1 + 0x10) = parent;
    *puVar1 = *puVar1 & 0xffffef6f | 0x400004;
    instance->zAccl = -10;
  }
  else
  {
    *puVar1 = *puVar1 & 0xffffff6f | 0x1000;
    instance->zAccl = 0;
  }
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PhysicalRelocateTune(struct Object *object /*$a0*/, long offset /*$a1*/)
// line 5561, offset 0x800701c0
/* begin block 1 */
// Start line: 5563
// Start offset: 0x800701C0
// Variables:
// 		struct PhysObWeaponProperties *properties; // $t0
// 		struct _PhysObLight *pLight; // $v0

/* begin block 1.1 */
// Start line: 5580
// Start offset: 0x8007023C
// Variables:
// 		struct PhysObInteractProperties *prop; // $a2
// 		struct PhysObWeaponAttributes *weapon; // $a3
/* end block 1.1 */
// End offset: 0x800702B0
// End Line: 5593

/* begin block 1.2 */
// Start line: 5595
// Start offset: 0x800702C0
// Variables:
// 		struct __PhysObProjectileProperties *prop; // $a0

/* begin block 1.2.1 */
// Start line: 5601
// Start offset: 0x800702E4
// Variables:
// 		int i; // $t0
/* end block 1.2.1 */
// End offset: 0x80070350
// End Line: 5615
/* end block 1.2 */
// End offset: 0x80070350
// End Line: 5616
/* end block 1 */
// End offset: 0x80070350
// End Line: 5618

/* begin block 2 */
// Start line: 12498
/* end block 2 */
// End Line: 12499

/* begin block 3 */
// Start line: 12499
/* end block 3 */
// End Line: 12500

void PhysicalRelocateTune(Object *object, long offset)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;

  pvVar6 = object->data;
  if (pvVar6 != (void *)0x0)
  {
    if (*(short *)((int)pvVar6 + 2) == 0)
    {
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0x18) != 0)
      {
        iVar2 = *(int *)((int)pvVar6 + 0x18) + offset;
      }
      *(int *)((int)pvVar6 + 0x18) = iVar2;
      if (iVar2 != 0)
      {
        iVar3 = 0;
        if (*(int *)(iVar2 + 4) != 0)
        {
          iVar3 = *(int *)(iVar2 + 4) + offset;
        }
        *(int *)(iVar2 + 4) = iVar3;
      }
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0x20) != 0)
      {
        iVar2 = *(int *)((int)pvVar6 + 0x20) + offset;
      }
      *(int *)((int)pvVar6 + 0x20) = iVar2;
    }
    sVar1 = *(short *)((int)pvVar6 + 2);
    if (sVar1 == 3)
    {
      iVar3 = *(int *)((int)object->data + 0x28);
      iVar2 = 0;
      if (iVar3 != 0)
      {
        iVar2 = iVar3 + offset;
      }
      *(int *)((int)object->data + 0x28) = iVar2;
      if (iVar2 != 0)
      {
        iVar3 = 0;
        if (*(int *)(iVar2 + 0x10) != 0)
        {
          iVar3 = *(int *)(iVar2 + 0x10) + offset;
        }
        *(int *)(iVar2 + 0x10) = iVar3;
        if (iVar3 != 0)
        {
          iVar4 = 0;
          if (*(int *)(iVar3 + 4) != 0)
          {
            iVar4 = *(int *)(iVar3 + 4) + offset;
          }
          *(int *)(iVar3 + 4) = iVar4;
        }
        iVar3 = 0;
        if (*(int *)(iVar2 + 0x18) != 0)
        {
          iVar3 = *(int *)(iVar2 + 0x18) + offset;
        }
        *(int *)(iVar2 + 0x18) = iVar3;
      }
      sVar1 = *(short *)((int)pvVar6 + 2);
    }
    if (sVar1 == 7)
    {
      pvVar6 = object->data;
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0xc) != 0)
      {
        iVar2 = *(int *)((int)pvVar6 + 0xc) + offset;
      }
      *(int *)((int)pvVar6 + 0xc) = iVar2;
      if ((iVar2 != 0) && (iVar3 = 0, 0 < *(int *)((int)pvVar6 + 8)))
      {
        do
        {
          iVar4 = 0;
          if (*(int *)(iVar2 + 8) != 0)
          {
            iVar4 = *(int *)(iVar2 + 8) + offset;
          }
          *(int *)(iVar2 + 8) = iVar4;
          if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x10), iVar4 != 0))
          {
            iVar5 = 0;
            if (*(int *)(iVar4 + 4) != 0)
            {
              iVar5 = *(int *)(iVar4 + 4) + offset;
            }
            *(int *)(iVar4 + 4) = iVar5;
          }
          iVar3 = iVar3 + 1;
          iVar2 = iVar2 + 0xc;
        } while (iVar3 < *(int *)((int)pvVar6 + 8));
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOBS_CheckObjectAxisAlignment(struct MATRIX *m0 /*$a0*/, struct MATRIX *m1 /*$s1*/, struct _SVector *axis /*$s0*/)
// line 5632, offset 0x80070358
/* begin block 1 */
// Start line: 5633
// Start offset: 0x80070358
// Variables:
// 		struct VECTOR r0; // stack offset -64
// 		struct VECTOR r1; // stack offset -48
// 		struct _SVector v0; // stack offset -32
// 		struct _SVector v1; // stack offset -24
/* end block 1 */
// End offset: 0x80070358
// End Line: 5633

/* begin block 2 */
// Start line: 12646
/* end block 2 */
// End Line: 12647

int PHYSOBS_CheckObjectAxisAlignment(MATRIX *m0, MATRIX *m1, _SVector *axis)

{
  short local_40[2];
  short local_3c;
  short local_38;
  short local_30[2];
  short local_2c;
  short local_28;

  ApplyMatrix(m0, axis, local_40);
  ApplyMatrix(m1, axis, local_30);
  return ((int)local_40[0] * (int)local_30[0] + (int)local_3c * (int)local_2c +
          (int)local_38 * (int)local_28) *
             0x10 >>
         0x10;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOB_CheckSlide(struct _Instance *instance /*$s0*/, int x /*$a1*/, int y /*$a2*/, struct evPhysicsSlideData **data /*$s1*/)
// line 5653, offset 0x80070428
/* begin block 1 */
// Start line: 12714
/* end block 1 */
// End Line: 12715

int PHYSOB_CheckSlide(_Instance *instance, int x, int y, evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;

  Data = (evPhysicsSlideData *)
      SetPhysicsSlideData(1, x * 0x2c00000 >> 0x10, y * 0x2c00000 >> 0x10, 0, 0x280, 0x280, -0xa0);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance, (int)Data, 1);
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOB_CheckSlide2(struct _Instance *instance /*$s0*/, int x /*$a1*/, int y /*$a2*/, struct evPhysicsSlideData **data /*$s1*/)
// line 5663, offset 0x800704b8
/* begin block 1 */
// Start line: 12736
/* end block 1 */
// End Line: 12737

int PHYSOB_CheckSlide2(_Instance *instance, int x, int y, evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;

  Data = (evPhysicsSlideData *)
      SetPhysicsSlideData(1, x * 0x2c00000 >> 0x10, y * 0x2c00000 >> 0x10, 0, 0x280, 0x280, -0x96);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance, (int)Data, 1);
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOB_CheckDropOnSlope(struct _Instance *instance /*$s0*/, int x /*$a1*/, int y /*$a2*/, struct evPhysicsSlideData **data /*$s1*/)
// line 5672, offset 0x80070548
/* begin block 1 */
// Start line: 12756
/* end block 1 */
// End Line: 12757

int PHYSOB_CheckDropOnSlope(_Instance *instance, int x, int y, evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;

  Data = (evPhysicsSlideData *)
      SetPhysicsSlideData(1, x * 0x2c00000 >> 0x10, y * 0x2c00000 >> 0x10, 0, 0xa00, 0x280, -0xa0);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance, (int)Data, 1);
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ PHYSOB_CheckSlideNormal(struct _Instance *instance /*$s0*/, int x /*stack 4*/, int y /*stack 8*/, struct evPhysicsSlideData **data /*$s1*/)
// line 5682, offset 0x800705dc
/* begin block 1 */
// Start line: 12778
/* end block 1 */
// End Line: 12779

int PHYSOB_CheckSlideNormal(_Instance *instance, int x, int y, evPhysicsSlideData **data)

{
  int iVar1;
  int local_res4;
  int local_res8[2];

  local_res4 = x;
  local_res8[0] = y;
  PHYSOB_NormalToAxis((short *)&local_res4, (short *)local_res8);
  iVar1 = PHYSOB_CheckSlide2(instance, local_res4, local_res8[0], data);
  return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ PHYSOB_NormalToAxis(short *x /*$a0*/, short *y /*$a1*/)
// line 5690, offset 0x80070630
/* begin block 1 */
// Start line: 5692
// Start offset: 0x80070630
// Variables:
// 		int x1; // $v1
// 		int y1; // $a2
/* end block 1 */
// End offset: 0x8007068C
// End Line: 5706

/* begin block 2 */
// Start line: 12796
/* end block 2 */
// End Line: 12797

/* begin block 3 */
// Start line: 12797
/* end block 3 */
// End Line: 12798

void PHYSOB_NormalToAxis(short *x, short *y)

{
  short sVar1;

  sVar1 = *y;
  if (*x < 0x401)
  {
    if (*x < -0x400)
    {
      *x = -1;
    }
    else
    {
      *x = 0;
    }
  }
  else
  {
    *x = 1;
  }
  if (0x400 < sVar1)
  {
    *y = 1;
    return;
  }
  if (sVar1 < -0x400)
  {
    *y = -1;
    return;
  }
  *y = 0;
  return;
}
