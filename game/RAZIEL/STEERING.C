#include "THISDUST.H"
#include "STEERING.H"


// decompiled code
// original method signature: 
// int /*$ra*/ UpdateZoneDelta(int rc /*$a0*/, int LastRC /*$a1*/)
 // line 20, offset 0x800a141c
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
  
  iVar1 = ZoneDelta;
  if ((LastRC != 0) && (iVar1 = 0x100, LastRC == rc)) {
    ZoneDelta = ZoneDelta + -4;
    iVar1 = 0x10;
    if (0xf < ZoneDelta) {
      return ZoneDelta;
    }
  }
  ZoneDelta = iVar1;
  return ZoneDelta;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetControllerInput(int *ZDirection /*$a2*/, long *controlCommand /*$a1*/)
 // line 34, offset 0x800a1458
	/* begin block 1 */
		// Start line: 35
		// Start offset: 0x800A1458
		// Variables:
	// 		int rc; // $s0
	/* end block 1 */
	// End offset: 0x800A1628
	// End Line: 114

	/* begin block 2 */
		// Start line: 68
	/* end block 2 */
	// End Line: 69

	/* begin block 3 */
		// Start line: 71
	/* end block 3 */
	// End Line: 72

int GetControllerInput(int *ZDirection,long *controlCommand)

{
  int iVar1;
  uint uVar2;
  
  if (((gameTrackerX.playerInstance)->flags & 0x100U) == 0) {
    uVar2 = *controlCommand;
    if ((uVar2 & 5) == 5) {
      iVar1 = 0x10000010;
      *ZDirection = 0xa00;
      UpdateZoneDelta(0x10000010,LastRC);
      LastRC = iVar1;
    }
    else {
      if ((uVar2 & 9) == 9) {
        iVar1 = 0x10000020;
        *ZDirection = 0x600;
        UpdateZoneDelta(0x10000020,LastRC);
        LastRC = iVar1;
      }
      else {
        if ((uVar2 & 6) == 6) {
          iVar1 = 0x10000040;
          *ZDirection = 0xe00;
          UpdateZoneDelta(0x10000040,LastRC);
          LastRC = iVar1;
        }
        else {
          if ((uVar2 & 10) == 10) {
            iVar1 = 0x10000030;
            *ZDirection = 0x200;
            UpdateZoneDelta(0x10000030,LastRC);
            LastRC = iVar1;
          }
          else {
            if ((uVar2 & 1) == 0) {
              iVar1 = 0x10000003;
              if ((uVar2 & 2) == 0) {
                if ((uVar2 & 8) == 0) {
                  iVar1 = 0x10000004;
                  if ((uVar2 & 4) == 0) {
                    iVar1 = 0;
                    ZoneDelta = 0x10;
                    *ZDirection = 0;
                    LastRC = iVar1;
                  }
                  else {
                    *ZDirection = 0xc00;
                    UpdateZoneDelta(0x10000004,LastRC);
                    LastRC = iVar1;
                  }
                }
                else {
                  iVar1 = 0x10000002;
                  *ZDirection = 0x400;
                  UpdateZoneDelta(0x10000002,LastRC);
                  LastRC = iVar1;
                }
              }
              else {
                *ZDirection = 0x1000;
                UpdateZoneDelta(0x10000003,LastRC);
                LastRC = iVar1;
              }
            }
            else {
              iVar1 = 0x10000001;
              *ZDirection = 0x800;
              UpdateZoneDelta(0x10000001,LastRC);
              LastRC = iVar1;
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
 // line 117, offset 0x800a1638
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x800A1638
		// Variables:
	// 		int rc; // $s1
	/* end block 1 */
	// End offset: 0x800A170C
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
 // line 188, offset 0x800a1728
	/* begin block 1 */
		// Start line: 189
		// Start offset: 0x800A1728
		// Variables:
	// 		int ZDirection; // stack offset -32
	// 		int rc; // $s2
	// 		int lag; // $v1

		/* begin block 1.1 */
			// Start line: 266
			// Start offset: 0x800A1904
			// Variables:
		// 		short diff; // stack offset -28
		// 		short zone; // stack offset -26
		/* end block 1.1 */
		// End offset: 0x800A1904
		// End Line: 267

		/* begin block 1.2 */
			// Start line: 316
			// Start offset: 0x800A1954
			// Variables:
		// 		struct _G2SVector3_Type rot; // stack offset -40
		/* end block 1.2 */
		// End offset: 0x800A19A8
		// End Line: 336

		/* begin block 1.3 */
			// Start line: 338
			// Start offset: 0x800A19A8
		/* end block 1.3 */
		// End offset: 0x800A19F4
		// End Line: 355

		/* begin block 1.4 */
			// Start line: 364
			// Start offset: 0x800A19FC
			// Variables:
		// 		short angle; // $s0
		/* end block 1.4 */
		// End offset: 0x800A1A58
		// End Line: 375

		/* begin block 1.5 */
			// Start line: 390
			// Start offset: 0x800A1A90
		/* end block 1.5 */
		// End offset: 0x800A1AC0
		// End Line: 394

		/* begin block 1.6 */
			// Start line: 423
			// Start offset: 0x800A1B68
			// Variables:
		// 		short diff; // stack offset -24
		// 		short zone; // stack offset -22
		/* end block 1.6 */
		// End offset: 0x800A1B68
		// End Line: 424

		/* begin block 1.7 */
			// Start line: 428
			// Start offset: 0x800A1B84
		/* end block 1.7 */
		// End offset: 0x800A1BC0
		// End Line: 438

		/* begin block 1.8 */
			// Start line: 440
			// Start offset: 0x800A1BC0
		/* end block 1.8 */
		// End offset: 0x800A1BF0
		// End Line: 451

		/* begin block 1.9 */
			// Start line: 453
			// Start offset: 0x800A1BF0
			// Variables:
		// 		short angle; // $s0
		/* end block 1.9 */
		// End offset: 0x800A1C38
		// End Line: 464
	/* end block 1 */
	// End offset: 0x800A1C38
	// End Line: 479

	/* begin block 2 */
		// Start line: 375
	/* end block 2 */
	// End Line: 376

int ProcessMovement(_Instance *instance,long *controlCommand,GameTracker *GT)

{
  int ix;
  int iy;
  int iVar1;
  int aiStack32 [4];
  
  if (((Raziel.steeringMode == 9) || (Raziel.steeringMode == 0xe)) || (Raziel.steeringMode == 0xf))
  {
    iVar1 = 0;
  }
  else {
    iVar1 = GetControllerInput(aiStack32,controlCommand);
  }
  razZeroAxis(controlCommand + 3,controlCommand + 4,0x400);
  ix = controlCommand[3];
  if (((ix == 0x80) || (ix == -0x80)) || ((iy = controlCommand[4], iy == 0x80 || (iy == -0x80)))) {
    ix = 0x1000;
  }
  else {
    Raziel.Magnitude = MATH3D_veclen2(ix,iy);
    Raziel.Magnitude = Raziel.Magnitude << 5;
    if (0x1000 < Raziel.Magnitude) {
      Raziel.Magnitude = 0x1000;
    }
    if ((Raziel.Magnitude == 0) || (ix = 0x400, 0x3ff < Raziel.Magnitude)) goto LAB_800a17fc;
  }
  Raziel.Magnitude = ix;
LAB_800a17fc:
  Raziel.lastInput = Raziel.input;
  ix = (controlCommand[4] << 0xc) >> 0x1f;
  iy = (controlCommand[3] << 0xc) >> 0x1f;
                    /* WARNING: Subroutine does not return */
  Raziel.input = iVar1;
  ratan2(((controlCommand[4] << 0xc) / 6 + ix >> 4) - ix,
         ((controlCommand[3] << 0xc) / 6 + iy >> 4) - iy);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerTurn(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
 // line 484, offset 0x800a1c54
	/* begin block 1 */
		// Start line: 485
		// Start offset: 0x800A1C54

		/* begin block 1.1 */
			// Start line: 491
			// Start offset: 0x800A1C80
			// Variables:
		// 		int rot; // $v0
		/* end block 1.1 */
		// End offset: 0x800A1CA4
		// End Line: 503
	/* end block 1 */
	// End offset: 0x800A1CD8
	// End Line: 508

	/* begin block 2 */
		// Start line: 968
	/* end block 2 */
	// End Line: 969

void SteerTurn(_Instance *instance,int rc)

{
  short sVar1;
  
  if ((rc == 0) && (Raziel.Bearing == 0)) {
    Raziel.steeringVelocity = 0;
    return;
  }
  sVar1 = Raziel.LastBearing;
  if ((Raziel.Bearing == 0x800) &&
     (sVar1 = Raziel.LastBearing + 1, (int)(instance->rotation).z - (int)Raziel.LastBearing < 1)) {
    sVar1 = Raziel.LastBearing + -1;
  }
  Raziel.LastBearing = sVar1;
                    /* WARNING: Subroutine does not return */
  AngleMoveToward(&(instance->rotation).z,Raziel.LastBearing,
                  (short)((int)Raziel.steeringVelocity * gameTrackerX.timeMult * 0x10 >> 0x10));
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerMove(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
 // line 547, offset 0x800a1ce8
	/* begin block 1 */
		// Start line: 1088
	/* end block 1 */
	// End Line: 1089

void SteerMove(_Instance *instance,int rc)

{
  int iVar1;
  
  if ((rc == 0) && (Raziel.Bearing == 0)) {
    Raziel.steeringVelocity = 0;
    return;
  }
  Raziel.steeringVelocity = -Raziel.Bearing;
  if (-1 < Raziel.Bearing) {
    Raziel.steeringVelocity = Raziel.Bearing;
  }
  iVar1 = (int)Raziel.steeringVelocity;
  Raziel.steeringVelocity = 0x70;
  if (0x300 < iVar1) {
    if (iVar1 < 0) {
      iVar1 = iVar1 + 3;
    }
    Raziel.steeringVelocity = (short)(iVar1 >> 2) + 0x70;
  }
                    /* WARNING: Subroutine does not return */
  AngleMoveToward(&(instance->rotation).z,Raziel.LastBearing,
                  (short)((int)Raziel.steeringVelocity * gameTrackerX.timeMult * 0x10 >> 0x10));
}



// decompiled code
// original method signature: 
// int /*$ra*/ SteerAutoFace(struct _Instance *instance /*$s3*/, long *controlCommand /*$a1*/)
 // line 586, offset 0x800a1d98
	/* begin block 1 */
		// Start line: 587
		// Start offset: 0x800A1D98
		// Variables:
	// 		short angle; // $s0
	// 		int rc; // $s2
	// 		struct _Instance *target; // $a1
	// 		struct _G2SVector3_Type autoFaceRot; // stack offset -32
	// 		int diff; // $s1
	// 		int predict; // $s2
	/* end block 1 */
	// End offset: 0x800A200C
	// End Line: 672

	/* begin block 2 */
		// Start line: 1132
	/* end block 2 */
	// End Line: 1133

	/* begin block 3 */
		// Start line: 1142
	/* end block 3 */
	// End Line: 1143

int SteerAutoFace(_Instance *instance,long *controlCommand)

{
                    /* WARNING: Subroutine does not return */
  MATH3D_AngleFromPosToPos(&instance->position,&(Raziel.Senses.EngagedList[6].instance)->position);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerSwim(struct _Instance *instance /*$s0*/)
 // line 678, offset 0x800a202c
	/* begin block 1 */
		// Start line: 679
		// Start offset: 0x800A202C
		// Variables:
	// 		int step; // $a0
	// 		int velocity; // $a1
	/* end block 1 */
	// End offset: 0x800A2104
	// End Line: 728

	/* begin block 2 */
		// Start line: 1365
	/* end block 2 */
	// End Line: 1366

void SteerSwim(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  rsin(Raziel.ZDirection);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerWallcrawling(struct _Instance *instance /*$a0*/)
 // line 732, offset 0x800a211c
	/* begin block 1 */
		// Start line: 1511
	/* end block 1 */
	// End Line: 1512

	/* begin block 2 */
		// Start line: 1517
	/* end block 2 */
	// End Line: 1518

void SteerWallcrawling(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  AngleDiff((short)(((uint)(ushort)ExtraRot->y - 0x800) * 0x10000 >> 0x10),(short)Raziel.ZDirection)
  ;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerDisableAutoFace(struct _Instance *instance /*$s1*/)
 // line 745, offset 0x800a2150
	/* begin block 1 */
		// Start line: 1543
	/* end block 1 */
	// End Line: 1544

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
  (instance->rotation).z = (instance->rotation).z + (short)Raziel.autoFaceRootAngle;
  Raziel.autoFaceRootAngle = 0;
  Raziel.autoFaceAnim = -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerSwitchMode(struct _Instance *instance /*$s1*/, int mode /*$s2*/)
 // line 773, offset 0x800a21e4
	/* begin block 1 */
		// Start line: 1601
	/* end block 1 */
	// End Line: 1602

	/* begin block 2 */
		// Start line: 1605
	/* end block 2 */
	// End Line: 1606

void SteerSwitchMode(_Instance *instance,int mode)

{
  _G2Bool_Enum _Var1;
  
  switch(Raziel.steeringMode) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x12:
    _Var1 = G2Anim_IsControllerActive(&instance->anim,1,0xe);
    if (_Var1 != G2FALSE) {
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
      _Var1 = G2Anim_IsControllerActive(&instance->anim,1,0xe);
      if (_Var1 != G2FALSE) {
        G2Anim_InterpDisableController(&instance->anim,1,0xe,600);
      }
      Raziel.extraRot.x = 0;
    }
    break;
  case 7:
    if (mode != Raziel.steeringMode) {
      razDeinitWallCrawlSteering(instance);
    }
    break;
  case 10:
    Raziel.attackedBy = (_Instance *)0x0;
    break;
  case 0xb:
    CAMERA_EndSwimThrowMode(&theCamera);
    CAMERA_SetLookRot(&theCamera,0,0);
    Raziel.extraRot.x = (short)Raziel.throwReturnRot;
  }
  Raziel.RotationSegment = 0;
  switch(mode) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 5:
  case 8:
  case 9:
  case 10:
  case 0xf:
  case 0x12:
    Raziel.RotationSegment = 0;
    break;
  case 7:
    if (mode != Raziel.steeringMode) {
      razInitWallCrawlSteering(instance);
    }
    break;
  case 0xb:
    Raziel.throwReturnRot = (int)Raziel.extraRot.x;
    Raziel.extraRot.x = 0x1000 - theCamera.core.rotation.x;
    CAMERA_StartSwimThrowMode(&theCamera);
    CAMERA_SetLookRot(&theCamera,0x1000 - (int)Raziel.extraRot.x,0);
  case 6:
  case 0x11:
    Raziel.RotationSegment = 1;
    break;
  case 0xe:
                    /* WARNING: Subroutine does not return */
    MATH3D_AngleFromPosToPos(&instance->position,&(Raziel.Senses.EngagedList[6].instance)->position)
    ;
  }
  Raziel.steeringMode = mode;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razInitWallCrawlSteering(struct _Instance *instance /*$s0*/)
 // line 879, offset 0x800a2418
	/* begin block 1 */
		// Start line: 880
		// Start offset: 0x800A2418
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A2418
	// End Line: 880

	/* begin block 2 */
		// Start line: 1819
	/* end block 2 */
	// End Line: 1820

void razInitWallCrawlSteering(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  G2Anim_EnableController(&instance->anim,1,0x26);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razDeinitWallCrawlSteering(struct _Instance *instance /*$s0*/)
 // line 913, offset 0x800a2558
	/* begin block 1 */
		// Start line: 1910
	/* end block 1 */
	// End Line: 1911

void razDeinitWallCrawlSteering(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  G2Anim_DisableController(&instance->anim,1,0x26);
}





