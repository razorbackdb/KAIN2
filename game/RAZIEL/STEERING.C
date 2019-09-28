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

int UpdateZoneDelta(int rc,int LastRC)

{
  int iVar1;
  
  iVar1 = InterfaceItem_800cf854.name._8_4_;
  if ((LastRC != 0) && (iVar1 = 0x100, LastRC == rc)) {
    InterfaceItem_800cf854.name._8_4_ = InterfaceItem_800cf854.name._8_4_ + -4;
    iVar1 = 0x10;
    if (0xf < InterfaceItem_800cf854.name._8_4_) {
      return InterfaceItem_800cf854.name._8_4_;
    }
  }
  InterfaceItem_800cf854.name._8_4_ = iVar1;
  return InterfaceItem_800cf854.name._8_4_;
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

int GetControllerInput(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((*(uint *)(iGpffffb524 + 0x14) & 0x100) == 0) {
    uVar2 = *param_2;
    if ((uVar2 & 5) == 5) {
      iVar1 = 0x10000010;
      *param_1 = 0xa00;
      UpdateZoneDelta(0x10000010,iGpfffffef0);
      iGpfffffef0 = iVar1;
    }
    else {
      if ((uVar2 & 9) == 9) {
        iVar1 = 0x10000020;
        *param_1 = 0x600;
        UpdateZoneDelta(0x10000020,iGpfffffef0);
        iGpfffffef0 = iVar1;
      }
      else {
        if ((uVar2 & 6) == 6) {
          iVar1 = 0x10000040;
          *param_1 = 0xe00;
          UpdateZoneDelta(0x10000040,iGpfffffef0);
          iGpfffffef0 = iVar1;
        }
        else {
          if ((uVar2 & 10) == 10) {
            iVar1 = 0x10000030;
            *param_1 = 0x200;
            UpdateZoneDelta(0x10000030,iGpfffffef0);
            iGpfffffef0 = iVar1;
          }
          else {
            if ((uVar2 & 1) == 0) {
              iVar1 = 0x10000003;
              if ((uVar2 & 2) == 0) {
                if ((uVar2 & 8) == 0) {
                  iVar1 = 0x10000004;
                  if ((uVar2 & 4) == 0) {
                    iVar1 = 0;
                    uGpffff9da8 = 0x10;
                    *param_1 = 0;
                    iGpfffffef0 = iVar1;
                  }
                  else {
                    *param_1 = 0xc00;
                    UpdateZoneDelta(0x10000004,iGpfffffef0);
                    iGpfffffef0 = iVar1;
                  }
                }
                else {
                  iVar1 = 0x10000002;
                  *param_1 = 0x400;
                  UpdateZoneDelta(0x10000002,iGpfffffef0);
                  iGpfffffef0 = iVar1;
                }
              }
              else {
                *param_1 = 0x1000;
                UpdateZoneDelta(0x10000003,iGpfffffef0);
                iGpfffffef0 = iVar1;
              }
            }
            else {
              iVar1 = 0x10000001;
              *param_1 = 0x800;
              UpdateZoneDelta(0x10000001,iGpfffffef0);
              iGpfffffef0 = iVar1;
            }
          }
        }
      }
    }
  }
  else {
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

int DecodeDirection(int Source,int Destination,short *Difference,short *Zone)

{
                    /* WARNING: Subroutine does not return */
  AngleDiff((short)Destination,(short)Source);
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

void ProcessMovement(undefined4 param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint ix;
  uint iy;
  int iVar3;
  undefined4 auStack32 [4];
  
  if (((iGpfffffae8 == 9) || (iGpfffffae8 == 0xe)) || (iGpfffffae8 == 0xf)) {
    iVar3 = 0;
  }
  else {
    iVar3 = GetControllerInput(auStack32,param_2);
  }
  razZeroAxis((long *)(param_2 + 3),(long *)(param_2 + 4),0x400);
  ix = param_2[3];
  if (((ix == 0x80) || (ix == 0xffffff80)) || ((iy = param_2[4], iy == 0x80 || (iy == 0xffffff80))))
  {
    iVar2 = 0x1000;
  }
  else {
    iGpfffffad4 = MATH3D_veclen2(ix,iy);
    iGpfffffad4 = iGpfffffad4 << 5;
    if (0x1000 < iGpfffffad4) {
      iGpfffffad4 = 0x1000;
    }
    if ((iGpfffffad4 == 0) || (iVar2 = 0x400, 0x3ff < iGpfffffad4)) goto LAB_800a251c;
  }
  iGpfffffad4 = iVar2;
LAB_800a251c:
  uGpfffffadc = iGpfffffad8;
  iVar2 = (int)(param_2[4] << 0xc) >> 0x1f;
  iVar1 = (int)(param_2[3] << 0xc) >> 0x1f;
                    /* WARNING: Subroutine does not return */
  iGpfffffad8 = iVar3;
  ratan2(((int)(param_2[4] << 0xc) / 6 + iVar2 >> 4) - iVar2,
         ((int)(param_2[3] << 0xc) / 6 + iVar1 >> 4) - iVar1);
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

void SteerTurn(_Instance *instance,int rc)

{
  short sVar1;
  
  if ((rc == 0) && (_CHAR____800d5598 == 0)) {
    _CHAR____800d55a0 = 0;
  }
  else {
    sVar1 = _CHAR____800d559a;
    if ((_CHAR____800d5598 == 0x800) &&
       (sVar1 = _CHAR____800d559a + 1, (int)(instance->rotation).z - (int)_CHAR____800d559a < 1)) {
      sVar1 = _CHAR____800d559a + -1;
    }
    _CHAR____800d559a = sVar1;
    AngleMoveToward(&(instance->rotation).z,_CHAR____800d559a,
                    (short)((uint)(_CHAR____800d55a0 * theCamera.tiltList[0][0] * 0x10) >> 0x10));
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

void SteerMove(_Instance *instance,int rc)

{
  int iVar1;
  
  if ((rc == 0) && (_CHAR____800d5598 == 0)) {
    _CHAR____800d55a0 = 0;
  }
  else {
    _CHAR____800d55a0 = -_CHAR____800d5598;
    if (-1 < _CHAR____800d5598) {
      _CHAR____800d55a0 = _CHAR____800d5598;
    }
    iVar1 = (int)_CHAR____800d55a0;
    _CHAR____800d55a0 = 0x70;
    if (0x300 < iVar1) {
      if (iVar1 < 0) {
        iVar1 = iVar1 + 3;
      }
      _CHAR____800d55a0 = (short)(iVar1 >> 2) + 0x70;
    }
    AngleMoveToward(&(instance->rotation).z,_CHAR____800d559a,
                    (short)((uint)(_CHAR____800d55a0 * theCamera.tiltList[0][0] * 0x10) >> 0x10));
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

int SteerAutoFace(_Instance *instance,long *controlCommand)

{
  short current;
  
  current = MATH3D_AngleFromPosToPos
                      (&instance->position,(_Position *)(*(int *)(_CHAR____800d55ec + 0x30) + 0x5c))
  ;
  _CHAR____800d574c = (int)current;
  _CHAR____800d5754 = _CHAR____800d5750;
                    /* WARNING: Subroutine does not return */
  AngleDiff(current,_CHAR____800d559a);
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
  AngleDiff((short)(((uint)*(ushort *)(gameTracker._16_4_ + 2) - 0x800) * 0x10000 >> 0x10),
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
  _Var1 = G2Anim_IsControllerActive(anim,1,10);
  if (_Var1 != G2FALSE) {
                    /* WARNING: Subroutine does not return */
    G2Anim_DisableController(anim,1,10);
  }
  _Var1 = G2Anim_IsControllerActive(anim,0xe,0xe);
  if (_Var1 != G2FALSE) {
                    /* WARNING: Subroutine does not return */
    G2Anim_DisableController(anim,0xe,0xe);
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

void SteerSwitchMode(_Instance *instance,int mode)

{
  short sVar1;
  _G2Bool_Enum _Var2;
  uint uVar3;
  
  switch(_CHAR____800d559c) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x12:
    _Var2 = G2Anim_IsControllerActive(&instance->anim,1,0xe);
    if (_Var2 != G2FALSE) {
                    /* WARNING: Subroutine does not return */
      G2Anim_DisableController(&instance->anim,1,0xe);
    }
    break;
  case 5:
  case 9:
  case 0xf:
    SteerDisableAutoFace(instance);
    break;
  case 6:
  case 0x11:
    if ((((mode != 6) && (mode != 0xb)) && (mode != 0x10)) && (mode != 0x11)) {
      _Var2 = G2Anim_IsControllerActive(&instance->anim,1,0xe);
      if (_Var2 != G2FALSE) {
        G2Anim_InterpDisableController(&instance->anim,1,0xe,600);
      }
      _CHAR____800d5724 = 0;
    }
    break;
  case 7:
    if (mode != _CHAR____800d559c) {
      razDeinitWallCrawlSteering(instance);
    }
    break;
  case 10:
    _CHAR____800d5674 = 0;
    break;
  case 0xb:
    CAMERA_EndSwimThrowMode((Camera *)&theCamera);
    CAMERA_SetLookRot((Camera *)&theCamera,0,0);
    _CHAR____800d5724 = _CHAR____800d5690;
  }
  _CHAR____800d557c = 0;
  switch(mode) {
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
    if (mode != _CHAR____800d559c) {
      razInitWallCrawlSteering(instance);
    }
    break;
  case 0xb:
    _CHAR____800d5690 = (int)_CHAR____800d5724;
    uVar3 = 0x1000U - (int)DAT_800cff40 & 0xfff;
    _CHAR____800d5724 = (short)uVar3;
    if (uVar3 - 0x401 < 0x3ff) {
      _CHAR____800d5724 = 0x400;
    }
    else {
      if (uVar3 - 0x801 < 0x3ff) {
        _CHAR____800d5724 = 0xc00;
      }
    }
    CAMERA_StartSwimThrowMode((Camera *)&theCamera);
    CAMERA_SetLookRot((Camera *)&theCamera,0x1000 - (int)_CHAR____800d5724,0);
  case 6:
  case 0x11:
    _CHAR____800d557c = 1;
    break;
  case 0xe:
    sVar1 = MATH3D_AngleFromPosToPos
                      (&instance->position,(_Position *)(*(int *)(_CHAR____800d55ec + 0x30) + 0x5c))
    ;
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
                    /* WARNING: Subroutine does not return */
  G2Anim_EnableController(&instance->anim,1,0x26);
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
                    /* WARNING: Subroutine does not return */
  G2Anim_DisableController(&instance->anim,1,0x26);
}





