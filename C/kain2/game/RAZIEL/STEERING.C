#include "THISDUST.H"
#include "STEERING.H"

// decompiled code
// original method signature:
// int /*$ra*/ UpdateZoneDelta(int rc /*$a0*/, int LastRC /*$a1*/)
// line 20, offset 0x800a213c
/* begin block 1 */
// Start line: 40
/* end block 1 */
// End Line: 41

/* begin block 2 */
// Start line: 42
/* end block 2 */
// End Line: 43

int UpdateZoneDelta(int rc, int LastRC)

{
  int iVar1;

  iVar1 = ZoneDelta;
  if ((LastRC != 0) && (iVar1 = 0x100, LastRC == rc))
  {
    ZoneDelta = ZoneDelta + -4;
    iVar1 = 0x10;
    if (0xf < ZoneDelta)
    {
      return ZoneDelta;
    }
  }
  ZoneDelta = iVar1;
  return ZoneDelta;
}

// decompiled code
// original method signature:
// int /*$ra*/ GetControllerInput(int *ZDirection /*$a2*/, long *controlCommand /*$a1*/)
// line 34, offset 0x800a2178
/* begin block 1 */
// Start line: 35
// Start offset: 0x800A2178
// Variables:
// 		int rc; // $s0
/* end block 1 */
// End offset: 0x800A2348
// End Line: 114

/* begin block 2 */
// Start line: 68
/* end block 2 */
// End Line: 69

/* begin block 3 */
// Start line: 71
/* end block 3 */
// End Line: 72

int GetControllerInput(int *ZDirection, long *controlCommand)

{
  int iVar1;
  uint uVar2;

  if ((*(uint *)(DAT_800d0fd8 + 0x14) & 0x100) == 0)
  {
    uVar2 = *controlCommand;
    if ((uVar2 & 5) == 5)
    {
      iVar1 = 0x10000010;
      *ZDirection = 0xa00;
      UpdateZoneDelta(0x10000010, _BlockVramEntry_800d59a0._4_4_);
      _BlockVramEntry_800d59a0._4_4_ = iVar1;
    }
    else
    {
      if ((uVar2 & 9) == 9)
      {
        iVar1 = 0x10000020;
        *ZDirection = 0x600;
        UpdateZoneDelta(0x10000020, _BlockVramEntry_800d59a0._4_4_);
        _BlockVramEntry_800d59a0._4_4_ = iVar1;
      }
      else
      {
        if ((uVar2 & 6) == 6)
        {
          iVar1 = 0x10000040;
          *ZDirection = 0xe00;
          UpdateZoneDelta(0x10000040, _BlockVramEntry_800d59a0._4_4_);
          _BlockVramEntry_800d59a0._4_4_ = iVar1;
        }
        else
        {
          if ((uVar2 & 10) == 10)
          {
            iVar1 = 0x10000030;
            *ZDirection = 0x200;
            UpdateZoneDelta(0x10000030, _BlockVramEntry_800d59a0._4_4_);
            _BlockVramEntry_800d59a0._4_4_ = iVar1;
          }
          else
          {
            if ((uVar2 & 1) == 0)
            {
              iVar1 = 0x10000003;
              if ((uVar2 & 2) == 0)
              {
                if ((uVar2 & 8) == 0)
                {
                  iVar1 = 0x10000004;
                  if ((uVar2 & 4) == 0)
                  {
                    iVar1 = 0;
                    ZoneDelta = 0x10;
                    *ZDirection = 0;
                    _BlockVramEntry_800d59a0._4_4_ = iVar1;
                  }
                  else
                  {
                    *ZDirection = 0xc00;
                    UpdateZoneDelta(0x10000004, _BlockVramEntry_800d59a0._4_4_);
                    _BlockVramEntry_800d59a0._4_4_ = iVar1;
                  }
                }
                else
                {
                  iVar1 = 0x10000002;
                  *ZDirection = 0x400;
                  UpdateZoneDelta(0x10000002, _BlockVramEntry_800d59a0._4_4_);
                  _BlockVramEntry_800d59a0._4_4_ = iVar1;
                }
              }
              else
              {
                *ZDirection = 0x1000;
                UpdateZoneDelta(0x10000003, _BlockVramEntry_800d59a0._4_4_);
                _BlockVramEntry_800d59a0._4_4_ = iVar1;
              }
            }
            else
            {
              iVar1 = 0x10000001;
              *ZDirection = 0x800;
              UpdateZoneDelta(0x10000001, _BlockVramEntry_800d59a0._4_4_);
              _BlockVramEntry_800d59a0._4_4_ = iVar1;
            }
          }
        }
      }
    }
  }
  else
  {
    iVar1 = 0;
  }
  return iVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ DecodeDirection(int Source /*$a0*/, int Destination /*$a1*/, short *Difference /*$s0*/, short *Zone /*$s2*/)
// line 117, offset 0x800a2358
/* begin block 1 */
// Start line: 118
// Start offset: 0x800A2358
// Variables:
// 		int rc; // $s1
/* end block 1 */
// End offset: 0x800A242C
// End Line: 142

/* begin block 2 */
// Start line: 253
/* end block 2 */
// End Line: 254

int DecodeDirection(int Source, int Destination, short *Difference, short *Zone)

{
  /* WARNING: Subroutine does not return */
  AngleDiff((short)Destination, (short)Source);
}

// decompiled code
// original method signature:
// int /*$ra*/ ProcessMovement(struct _Instance *instance /*$s1*/, long *controlCommand /*$s0*/, struct GameTracker *GT /*$a2*/)
// line 188, offset 0x800a2448
/* begin block 1 */
// Start line: 189
// Start offset: 0x800A2448
// Variables:
// 		int ZDirection; // stack offset -32
// 		int rc; // $s2
// 		int lag; // $v1

/* begin block 1.1 */
// Start line: 267
// Start offset: 0x800A2630
// Variables:
// 		short diff; // stack offset -28
// 		short zone; // stack offset -26
/* end block 1.1 */
// End offset: 0x800A2630
// End Line: 268

/* begin block 1.2 */
// Start line: 317
// Start offset: 0x800A2680
// Variables:
// 		struct _G2SVector3_Type rot; // stack offset -40
/* end block 1.2 */
// End offset: 0x800A26D4
// End Line: 337

/* begin block 1.3 */
// Start line: 339
// Start offset: 0x800A26D4
/* end block 1.3 */
// End offset: 0x800A2720
// End Line: 356

/* begin block 1.4 */
// Start line: 365
// Start offset: 0x800A2728
// Variables:
// 		short angle; // $s0
/* end block 1.4 */
// End offset: 0x800A2784
// End Line: 376

/* begin block 1.5 */
// Start line: 391
// Start offset: 0x800A27BC
/* end block 1.5 */
// End offset: 0x800A27EC
// End Line: 395

/* begin block 1.6 */
// Start line: 426
// Start offset: 0x800A28A4
// Variables:
// 		short diff; // stack offset -24
// 		short zone; // stack offset -22
/* end block 1.6 */
// End offset: 0x800A28A4
// End Line: 427

/* begin block 1.7 */
// Start line: 431
// Start offset: 0x800A28C0
/* end block 1.7 */
// End offset: 0x800A28FC
// End Line: 441

/* begin block 1.8 */
// Start line: 443
// Start offset: 0x800A28FC
/* end block 1.8 */
// End offset: 0x800A2928
// End Line: 454

/* begin block 1.9 */
// Start line: 456
// Start offset: 0x800A2928
// Variables:
// 		short angle; // $s0
/* end block 1.9 */
// End offset: 0x800A2970
// End Line: 467
/* end block 1 */
// End offset: 0x800A2970
// End Line: 482

/* begin block 2 */
// Start line: 376
/* end block 2 */
// End Line: 377

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ProcessMovement(_Instance *instance, long *controlCommand, GameTracker *GT)

{
  int ix;
  int iy;
  int iVar1;
  int aiStack32[4];

  if (((_CHAR____800d559c == 9) || (_CHAR____800d559c == 0xe)) || (_CHAR____800d559c == 0xf))
  {
    iVar1 = 0;
  }
  else
  {
    iVar1 = GetControllerInput(aiStack32, controlCommand);
  }
  razZeroAxis(controlCommand + 3, controlCommand + 4, 0x400);
  ix = controlCommand[3];
  if (((ix == 0x80) || (ix == -0x80)) || ((iy = controlCommand[4], iy == 0x80 || (iy == -0x80))))
  {
    ix = 0x1000;
  }
  else
  {
    _CHAR____800d5588 = MATH3D_veclen2(ix, iy);
    _CHAR____800d5588 = _CHAR____800d5588 << 5;
    if (0x1000 < _CHAR____800d5588)
    {
      _CHAR____800d5588 = 0x1000;
    }
    if ((_CHAR____800d5588 == 0) || (ix = 0x400, 0x3ff < _CHAR____800d5588))
      goto LAB_800a251c;
  }
  _CHAR____800d5588 = ix;
LAB_800a251c:
  _CHAR____800d5590 = _CHAR____800d558c;
  ix = (controlCommand[4] << 0xc) >> 0x1f;
  iy = (controlCommand[3] << 0xc) >> 0x1f;
  _CHAR____800d558c = iVar1;
  ix = ratan2(((controlCommand[4] << 0xc) / 6 + ix >> 4) - ix,
              ((controlCommand[3] << 0xc) / 6 + iy >> 4) - iy);
  _CHAR____800d5594 = 0x400U - ix & 0xfff;
  if (iVar1 != 0)
  {
    _CHAR____800d559a = _CHAR____800d5594 + DAT_800cff8c;
  }
  /* WARNING: Subroutine does not return */
  AngleDiff((instance->rotation).z, _CHAR____800d559a);
}

// decompiled code
// original method signature:
// void /*$ra*/ SteerTurn(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
// line 487, offset 0x800a298c
/* begin block 1 */
// Start line: 488
// Start offset: 0x800A298C

/* begin block 1.1 */
// Start line: 494
// Start offset: 0x800A29B8
// Variables:
// 		int rot; // $v0
/* end block 1.1 */
// End offset: 0x800A29DC
// End Line: 506
/* end block 1 */
// End offset: 0x800A2A10
// End Line: 511

/* begin block 2 */
// Start line: 974
/* end block 2 */
// End Line: 975

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SteerTurn(_Instance *instance, int rc)

{
  short sVar1;

  if ((rc == 0) && (_CHAR____800d5598 == 0))
  {
    _CHAR____800d55a0 = 0;
  }
  else
  {
    sVar1 = _CHAR____800d559a;
    if ((_CHAR____800d5598 == 0x800) &&
        (sVar1 = _CHAR____800d559a + 1, (int)(instance->rotation).z - (int)_CHAR____800d559a < 1))
    {
      sVar1 = _CHAR____800d559a + -1;
    }
    _CHAR____800d559a = sVar1;
    AngleMoveToward(&(instance->rotation).z, _CHAR____800d559a,
                    (short)((uint)(_CHAR____800d55a0 * DAT_800d11ec * 0x10) >> 0x10));
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SteerMove(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
// line 550, offset 0x800a2a20
/* begin block 1 */
// Start line: 1100
/* end block 1 */
// End Line: 1101

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SteerMove(_Instance *instance, int rc)

{
  int iVar1;

  if ((rc == 0) && (_CHAR____800d5598 == 0))
  {
    _CHAR____800d55a0 = 0;
  }
  else
  {
    _CHAR____800d55a0 = -_CHAR____800d5598;
    if (-1 < _CHAR____800d5598)
    {
      _CHAR____800d55a0 = _CHAR____800d5598;
    }
    iVar1 = (int)_CHAR____800d55a0;
    _CHAR____800d55a0 = 0x70;
    if (0x300 < iVar1)
    {
      if (iVar1 < 0)
      {
        iVar1 = iVar1 + 3;
      }
      _CHAR____800d55a0 = (short)(iVar1 >> 2) + 0x70;
    }
    AngleMoveToward(&(instance->rotation).z, _CHAR____800d559a,
                    (short)((uint)(_CHAR____800d55a0 * DAT_800d11ec * 0x10) >> 0x10));
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ SteerAutoFace(struct _Instance *instance /*$s3*/, long *controlCommand /*$a1*/)
// line 589, offset 0x800a2ad0
/* begin block 1 */
// Start line: 590
// Start offset: 0x800A2AD0
// Variables:
// 		short angle; // $s0
// 		int rc; // $s2
// 		struct _Instance *target; // $a1
// 		struct _G2SVector3_Type autoFaceRot; // stack offset -32
// 		int diff; // $s1
// 		int predict; // $s2
/* end block 1 */
// End offset: 0x800A2D44
// End Line: 675

/* begin block 2 */
// Start line: 1138
/* end block 2 */
// End Line: 1139

/* begin block 3 */
// Start line: 1148
/* end block 3 */
// End Line: 1149

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int SteerAutoFace(_Instance *instance, long *controlCommand)

{
  short current;

  current = MATH3D_AngleFromPosToPos(&instance->position, (_Position *)(*(int *)(_CHAR____800d55ec + 0x30) + 0x5c));
  _CHAR____800d574c = (int)current;
  _CHAR____800d5754 = _CHAR____800d5750;
  /* WARNING: Subroutine does not return */
  AngleDiff(current, _CHAR____800d559a);
}

// decompiled code
// original method signature:
// void /*$ra*/ SteerSwim(struct _Instance *instance /*$s0*/)
// line 681, offset 0x800a2d64
/* begin block 1 */
// Start line: 682
// Start offset: 0x800A2D64
// Variables:
// 		int step; // $a0
// 		int velocity; // $a1
/* end block 1 */
// End offset: 0x800A2E3C
// End Line: 731

/* begin block 2 */
// Start line: 1371
/* end block 2 */
// End Line: 1372

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SteerSwim(_Instance *instance)

{
  /* WARNING: Subroutine does not return */
  rsin(_CHAR____800d5594);
}

// decompiled code
// original method signature:
// void /*$ra*/ SteerWallcrawling(struct _Instance *instance /*$a0*/)
// line 735, offset 0x800a2e54
/* begin block 1 */
// Start line: 1517
/* end block 1 */
// End Line: 1518

/* begin block 2 */
// Start line: 1523
/* end block 2 */
// End Line: 1524

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SteerWallcrawling(_Instance *instance)

{
  /* WARNING: Subroutine does not return */
  AngleDiff((short)(((uint) * (ushort *)(gameTracker._16_4_ + 2) - 0x800) * 0x10000 >> 0x10),
            _CHAR____800d5594);
}

// decompiled code
// original method signature:
// void /*$ra*/ SteerDisableAutoFace(struct _Instance *instance /*$s1*/)
// line 748, offset 0x800a2e88
/* begin block 1 */
// Start line: 1549
/* end block 1 */
// End Line: 1550

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SteerDisableAutoFace(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;

  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim, 1, 10);
  if (_Var1 != G2FALSE)
  {
    G2Anim_DisableController(anim, 1, 10);
  }
  _Var1 = G2Anim_IsControllerActive(anim, 0xe, 0xe);
  if (_Var1 != G2FALSE)
  {
    G2Anim_DisableController(anim, 0xe, 0xe);
  }
  (instance->rotation).z = (instance->rotation).z + _CHAR____800d5748;
  _CHAR____800d5748 = 0;
  _CHAR____800d5750 = 0xffffffff;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ SteerSwitchMode(struct _Instance *instance /*$s1*/, int mode /*$s2*/)
// line 776, offset 0x800a2f1c
/* begin block 1 */
// Start line: 777
// Start offset: 0x800A2F1C

/* begin block 1.1 */
// Start line: 846
// Start offset: 0x800A30A8
// Variables:
// 		int rotx; // $v1
/* end block 1.1 */
// End offset: 0x800A3110
// End Line: 856
/* end block 1 */
// End offset: 0x800A315C
// End Line: 883

/* begin block 2 */
// Start line: 1607
/* end block 2 */
// End Line: 1608

/* begin block 3 */
// Start line: 1611
/* end block 3 */
// End Line: 1612

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SteerSwitchMode(_Instance *instance, int mode)

{
  short sVar1;
  _G2Bool_Enum _Var2;
  uint uVar3;

  switch (_CHAR____800d559c)
  {
  case 0:
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x12:
    _Var2 = G2Anim_IsControllerActive(&instance->anim, 1, 0xe);
    if (_Var2 != G2FALSE)
    {
      G2Anim_DisableController(&instance->anim, 1, 0xe);
      (instance->rotation).z = _CHAR____800d55a4;
      _CHAR____800d559a = _CHAR____800d55a4;
    }
    break;
  case 5:
  case 9:
  case 0xf:
    SteerDisableAutoFace(instance);
    break;
  case 6:
  case 0x11:
    if ((((mode != 6) && (mode != 0xb)) && (mode != 0x10)) && (mode != 0x11))
    {
      _Var2 = G2Anim_IsControllerActive(&instance->anim, 1, 0xe);
      if (_Var2 != G2FALSE)
      {
        G2Anim_InterpDisableController(&instance->anim, 1, 0xe, 600);
      }
      _CHAR____800d5724 = 0;
    }
    break;
  case 7:
    if (mode != _CHAR____800d559c)
    {
      razDeinitWallCrawlSteering(instance);
    }
    break;
  case 10:
    _CHAR____800d5674 = 0;
    break;
  case 0xb:
    CAMERA_EndSwimThrowMode((Camera *)&theCamera);
    CAMERA_SetLookRot((Camera *)&theCamera, 0, 0);
    _CHAR____800d5724 = _CHAR____800d5690;
  }
  _CHAR____800d557c = 0;
  switch (mode)
  {
  case 0:
    _CHAR____800d5728 = 0;
    _CHAR____800d5724 = 0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 8:
  case 9:
  case 10:
  case 0xf:
  case 0x12:
    _CHAR____800d557c = 0;
    break;
  case 7:
    if (mode != _CHAR____800d559c)
    {
      razInitWallCrawlSteering(instance);
    }
    break;
  case 0xb:
    _CHAR____800d5690 = (int)_CHAR____800d5724;
    uVar3 = 0x1000U - (int)DAT_800cff40 & 0xfff;
    _CHAR____800d5724 = (short)uVar3;
    if (uVar3 - 0x401 < 0x3ff)
    {
      _CHAR____800d5724 = 0x400;
    }
    else
    {
      if (uVar3 - 0x801 < 0x3ff)
      {
        _CHAR____800d5724 = 0xc00;
      }
    }
    CAMERA_StartSwimThrowMode((Camera *)&theCamera);
    CAMERA_SetLookRot((Camera *)&theCamera, 0x1000 - (int)_CHAR____800d5724, 0);
  case 6:
  case 0x11:
    _CHAR____800d557c = 1;
    break;
  case 0xe:
    sVar1 = MATH3D_AngleFromPosToPos(&instance->position, (_Position *)(*(int *)(_CHAR____800d55ec + 0x30) + 0x5c));
    (instance->rotation).z = sVar1;
  }
  _CHAR____800d559c = mode;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ razInitWallCrawlSteering(struct _Instance *instance /*$s0*/)
// line 888, offset 0x800a3178
/* begin block 1 */
// Start line: 889
// Start offset: 0x800A3178
// Variables:
// 		struct _G2SVector3_Type vec; // stack offset -24
/* end block 1 */
// End offset: 0x800A3178
// End Line: 889

/* begin block 2 */
// Start line: 1840
/* end block 2 */
// End Line: 1841

void razInitWallCrawlSteering(_Instance *instance)

{
  MATRIX *pMVar1;
  _G2Anim_Type *anim;
  _G2SVector3_Type local_18;

  anim = &instance->anim;
  G2Anim_EnableController(anim, 1, 0x26);
  local_18.x = 0;
  local_18.y = 0;
  local_18.z = -0x13e;
  (instance->position).z = (instance->position).z + 0x13e;
  pMVar1 = instance->matrix;
  (instance->oldPos).z = (instance->oldPos).z + 0x13e;
  pMVar1->t[2] = pMVar1->t[2] + 0x13e;
  instance->oldMatrix->t[2] = instance->oldMatrix->t[2] + 0x13e;
  G2Anim_SetController_Vector(anim, 1, 0x26, &local_18);
  G2Anim_EnableController(anim, 0, 0xe);
  local_18.x = (instance->rotation).x;
  local_18.y = (instance->rotation).y;
  local_18.z = (instance->rotation).z;
  G2Anim_EnableController(anim, 0, 8);
  G2Anim_SetControllerAngleOrder(anim, 0, 8, 1);
  G2Anim_SetController_Vector(anim, 0, 8, &local_18);
  G2Anim_EnableController(anim, 0xe, 0xe);
  G2Anim_EnableController(anim, 0x32, 0x4c);
  G2Anim_EnableController(anim, 0x3a, 0x4c);
  gameTracker.newX = 0;
  gameTracker.newY = 0;
  gameTracker.x = 0;
  gameTracker._16_4_ = 0x800d58ac;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ razDeinitWallCrawlSteering(struct _Instance *instance /*$s0*/)
// line 922, offset 0x800a32b4
/* begin block 1 */
// Start line: 1931
/* end block 1 */
// End Line: 1932

void razDeinitWallCrawlSteering(_Instance *instance)

{
  MATRIX *pMVar1;
  _G2Anim_Type *anim;

  anim = &instance->anim;
  G2Anim_DisableController(anim, 1, 0x26);
  (instance->position).z = (instance->position).z + -0x13e;
  pMVar1 = instance->matrix;
  (instance->oldPos).z = (instance->oldPos).z + -0x13e;
  pMVar1->t[2] = pMVar1->t[2] + -0x13e;
  instance->oldMatrix->t[2] = instance->oldMatrix->t[2] + -0x13e;
  G2Anim_InterpDisableController(anim, 0, 0xe, 300);
  G2Anim_InterpDisableController(anim, 0, 8, 300);
  G2Anim_InterpDisableController(anim, 0xe, 0xe, 300);
  G2Anim_InterpDisableController(anim, 0x32, 0x4c, 300);
  G2Anim_InterpDisableController(anim, 0x3a, 0x4c, 300);
  return;
}
