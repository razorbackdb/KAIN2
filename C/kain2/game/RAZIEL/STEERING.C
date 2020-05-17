#include "THISDUST.H"
#include "STEERING.H"


// decompiled code
// original method signature: 
// int /*$ra*/ UpdateZoneDelta(int rc /*$a0*/, int LastRC /*$a1*/)
 // line 20, offset 0x800a206c
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
 // line 34, offset 0x800a20a8
	/* begin block 1 */
		// Start line: 35
		// Start offset: 0x800A20A8
		// Variables:
	// 		int rc; // $s0
	/* end block 1 */
	// End offset: 0x800A2278
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
 // line 117, offset 0x800a2288
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x800A2288
		// Variables:
	// 		int rc; // $s1
	/* end block 1 */
	// End offset: 0x800A235C
	// End Line: 142

	/* begin block 2 */
		// Start line: 253
	/* end block 2 */
	// End Line: 254

int DecodeDirection(int Source,int Destination,short *Difference,short *Zone)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  sVar1 = AngleDiff((short)Destination,(short)Source);
  *Difference = sVar1;
  if ((ushort)(sVar1 + 0x1ffU) < 0x3ff) {
    *Zone = 0;
    iVar3 = 0x10000001;
  }
  else {
    if ((ushort)(sVar1 - 0x200U) < 0x400) {
      *Zone = 0x400;
      iVar3 = 0x10000004;
    }
    else {
      if ((ushort)(sVar1 + 0x5ffU) < 0x400) {
        *Zone = -0x400;
        iVar3 = 0x10000002;
      }
      else {
        if (sVar1 < 0x600) {
          sVar2 = -0x800;
          if (-0x600 < sVar1) {
            return 0;
          }
        }
        else {
          sVar2 = 0x800;
        }
        *Zone = sVar2;
        iVar3 = 0x10000003;
      }
    }
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ProcessMovement(struct _Instance *instance /*$s1*/, long *controlCommand /*$s0*/, struct GameTracker *GT /*$a2*/)
 // line 188, offset 0x800a2378
	/* begin block 1 */
		// Start line: 189
		// Start offset: 0x800A2378
		// Variables:
	// 		int ZDirection; // stack offset -32
	// 		int rc; // $s2
	// 		int lag; // $v1

		/* begin block 1.1 */
			// Start line: 267
			// Start offset: 0x800A2560
			// Variables:
		// 		short diff; // stack offset -28
		// 		short zone; // stack offset -26
		/* end block 1.1 */
		// End offset: 0x800A2560
		// End Line: 268

		/* begin block 1.2 */
			// Start line: 317
			// Start offset: 0x800A25B0
			// Variables:
		// 		struct _G2SVector3_Type rot; // stack offset -40
		/* end block 1.2 */
		// End offset: 0x800A2604
		// End Line: 337

		/* begin block 1.3 */
			// Start line: 339
			// Start offset: 0x800A2604
		/* end block 1.3 */
		// End offset: 0x800A2650
		// End Line: 356

		/* begin block 1.4 */
			// Start line: 365
			// Start offset: 0x800A2658
			// Variables:
		// 		short angle; // $s0
		/* end block 1.4 */
		// End offset: 0x800A26B4
		// End Line: 376

		/* begin block 1.5 */
			// Start line: 391
			// Start offset: 0x800A26EC
		/* end block 1.5 */
		// End offset: 0x800A271C
		// End Line: 395

		/* begin block 1.6 */
			// Start line: 426
			// Start offset: 0x800A27D4
			// Variables:
		// 		short diff; // stack offset -24
		// 		short zone; // stack offset -22
		/* end block 1.6 */
		// End offset: 0x800A27D4
		// End Line: 427

		/* begin block 1.7 */
			// Start line: 431
			// Start offset: 0x800A27F0
		/* end block 1.7 */
		// End offset: 0x800A282C
		// End Line: 441

		/* begin block 1.8 */
			// Start line: 443
			// Start offset: 0x800A282C
		/* end block 1.8 */
		// End offset: 0x800A2858
		// End Line: 454

		/* begin block 1.9 */
			// Start line: 456
			// Start offset: 0x800A2858
			// Variables:
		// 		short angle; // $s0
		/* end block 1.9 */
		// End offset: 0x800A28A0
		// End Line: 467
	/* end block 1 */
	// End offset: 0x800A28A0
	// End Line: 482

	/* begin block 2 */
		// Start line: 376
	/* end block 2 */
	// End Line: 377

int ProcessMovement(_Instance *instance,long *controlCommand,GameTracker *GT)

{
  short destination;
  ushort uVar1;
  long lVar2;
  _G2Bool_Enum _Var3;
  int ix;
  int iy;
  short step;
  short *Difference;
  short *Zone;
  int rc;
  _G2SVector3_Type _Stack40;
  int iStack32;
  short sStack28;
  short sStack26;
  short sStack24;
  short asStack22 [3];
  
  if (((Raziel.steeringMode == 9) || (Raziel.steeringMode == 0xe)) || (Raziel.steeringMode == 0xf))
  {
    rc = 0;
  }
  else {
    rc = GetControllerInput(&iStack32,controlCommand);
  }
  razZeroAxis(controlCommand + 3,controlCommand + 4,0x400);
  ix = controlCommand[3];
  if (((ix == 0x80) || (ix == -0x80)) || ((iy = controlCommand[4], iy == 0x80 || (iy == -0x80)))) {
    ix = 0x1000;
LAB_800a2448:
    Raziel.Magnitude = ix;
  }
  else {
    Raziel.Magnitude = MATH3D_veclen2(ix,iy);
    Raziel.Magnitude = Raziel.Magnitude << 5;
    if (0x1000 < Raziel.Magnitude) {
      Raziel.Magnitude = 0x1000;
    }
    if ((Raziel.Magnitude != 0) && (ix = 0x400, Raziel.Magnitude < 0x400)) goto LAB_800a2448;
  }
  Raziel.lastInput = Raziel.input;
  ix = (controlCommand[4] << 0xc) >> 0x1f;
  iy = (controlCommand[3] << 0xc) >> 0x1f;
  Raziel.input = rc;
  ix = ratan2(((controlCommand[4] << 0xc) / 6 + ix >> 4) - ix,
              ((controlCommand[3] << 0xc) / 6 + iy >> 4) - iy);
  Raziel.ZDirection = 0x400U - ix & 0xfff;
  if (rc != 0) {
    Raziel.LastBearing = (short)Raziel.ZDirection + theCamera.lagZ;
  }
  Raziel.Bearing = AngleDiff((instance->rotation).z,Raziel.LastBearing);
  switch(Raziel.steeringMode) {
  case 0:
  case 0x10:
    goto switchD_800a2504_caseD_0;
  case 1:
    Raziel.steeringVelocity = 0x100;
    goto LAB_800a2584;
  case 2:
    SteerMove(instance,rc);
    break;
  case 4:
    _Stack40.y = 0;
    _Stack40.x = 0;
    _Stack40.z = (short)Raziel.steeringLockRotation - Raziel.LastBearing;
    (instance->rotation).z = Raziel.LastBearing;
    if (rc != 0) {
      lVar2 = 0x15;
      if (Raziel.Mode == 0x10) {
        lVar2 = 0x28;
      }
      instance->yVel = lVar2;
    }
    G2Anim_SetController_Vector(&instance->anim,1,0xe,&_Stack40);
    break;
  case 5:
  case 9:
    if (rc != 0) {
LAB_800a26dc:
      rc = SteerAutoFace(instance,controlCommand);
      return rc;
    }
    if ((*PadData & 0x200) == 0) {
      return 0;
    }
    if ((Raziel.Senses.EngagedMask & 0x40) == 0) {
      return 0;
    }
    SteerDisableAutoFace(instance);
    destination = MATH3D_AngleFromPosToPos
                            (&instance->position,&(Raziel.Senses.EngagedList[6].instance)->position)
    ;
    Raziel.steeringVelocity = 0x80;
    step = (short)((gameTrackerX.timeMult << 0xb) >> 0x10);
    goto LAB_800a281c;
  case 6:
  case 0x11:
    if (rc != 0) {
      SteerSwim(instance);
    }
    _Var3 = G2Anim_IsControllerActive(&instance->anim,1,0xe);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(&instance->anim,1,0xe);
    }
    G2EmulationSetInterpController_Vector(instance,1,0xe,&Raziel.extraRot,4,3);
    break;
  case 7:
    SteerWallcrawling(instance);
    Difference = &sStack24;
    if (rc == 0) {
      return 0;
    }
    Zone = asStack22;
    goto LAB_800a27e0;
  case 8:
    Raziel.steeringVelocity = 0x60;
    goto LAB_800a2584;
  case 10:
    destination = MATH3D_AngleFromPosToPos(&instance->position,&(Raziel.attackedBy)->position);
    Raziel.steeringVelocity = 0x100;
    step = (short)((gameTrackerX.timeMult << 0xc) >> 0x10);
    goto LAB_800a281c;
  case 0xb:
    _Var3 = G2Anim_IsControllerActive(&instance->anim,1,0xe);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(&instance->anim,1,0xe);
    }
    G2EmulationSetInterpController_Vector(instance,1,0xe,&Raziel.extraRot,5,0);
    goto switchD_800a2504_caseD_0;
  case 0xc:
    destination = MATH3D_AngleFromPosToPos(&instance->position,&Raziel.puppetRotToPoint);
    goto LAB_800a2878;
  case 0xd:
    destination = Raziel.puppetRotToPoint.z;
LAB_800a2878:
    Raziel.steeringVelocity = 0x100;
    AngleMoveToward(&(instance->rotation).z,destination,
                    (short)((gameTrackerX.timeMult << 0xc) >> 0x10));
    if (destination == (instance->rotation).z) {
      SteerSwitchMode(instance,0);
    }
    break;
  case 0xe:
    if (((*PadData & 0x200) != 0) && ((Raziel.Senses.EngagedMask & 0x40) != 0)) {
      destination = MATH3D_AngleFromPosToPos
                              (&instance->position,
                               &(Raziel.Senses.EngagedList[6].instance)->position);
      (instance->rotation).z = destination;
    }
    break;
  case 0xf:
    if (rc != 0) goto LAB_800a26dc;
    if ((Raziel.Senses.EngagedMask & 0x40) == 0) {
      return 0;
    }
    SteerDisableAutoFace(instance);
    destination = MATH3D_AngleFromPosToPos
                            (&instance->position,&(Raziel.Senses.EngagedList[6].instance)->position)
    ;
    uVar1 = MON_FacingOffset(Raziel.Senses.EngagedList[6].instance,instance);
    if (((uint)uVar1 & 0xfff) - 0x2ab < 0xaab) {
      return 0;
    }
    Raziel.steeringVelocity = 0x80;
    step = (short)((gameTrackerX.timeMult << 0xb) >> 0x10);
LAB_800a281c:
    AngleMoveToward(&(instance->rotation).z,destination,step);
    break;
  case 0x12:
    Raziel.steeringVelocity = 0x40;
LAB_800a2584:
    SteerTurn(instance,rc);
  }
  return rc;
switchD_800a2504_caseD_0:
  Difference = &sStack28;
  if (rc == 0) {
    return 0;
  }
  Zone = &sStack26;
LAB_800a27e0:
  rc = DecodeDirection((int)Raziel.Bearing,0,Difference,Zone);
  return rc;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerTurn(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
 // line 487, offset 0x800a28bc
	/* begin block 1 */
		// Start line: 488
		// Start offset: 0x800A28BC

		/* begin block 1.1 */
			// Start line: 494
			// Start offset: 0x800A28E8
			// Variables:
		// 		int rot; // $v0
		/* end block 1.1 */
		// End offset: 0x800A290C
		// End Line: 506
	/* end block 1 */
	// End offset: 0x800A2940
	// End Line: 511

	/* begin block 2 */
		// Start line: 974
	/* end block 2 */
	// End Line: 975

void SteerTurn(_Instance *instance,int rc)

{
  short sVar1;
  
  if ((rc == 0) && (Raziel.Bearing == 0)) {
    Raziel.steeringVelocity = 0;
  }
  else {
    sVar1 = Raziel.LastBearing;
    if ((Raziel.Bearing == 0x800) &&
       (sVar1 = Raziel.LastBearing + 1, (int)(instance->rotation).z - (int)Raziel.LastBearing < 1))
    {
      sVar1 = Raziel.LastBearing + -1;
    }
    Raziel.LastBearing = sVar1;
    AngleMoveToward(&(instance->rotation).z,Raziel.LastBearing,
                    (short)((int)Raziel.steeringVelocity * gameTrackerX.timeMult * 0x10 >> 0x10));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerMove(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
 // line 550, offset 0x800a2950
	/* begin block 1 */
		// Start line: 1100
	/* end block 1 */
	// End Line: 1101

void SteerMove(_Instance *instance,int rc)

{
  int iVar1;
  
  if ((rc == 0) && (Raziel.Bearing == 0)) {
    Raziel.steeringVelocity = 0;
  }
  else {
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
    AngleMoveToward(&(instance->rotation).z,Raziel.LastBearing,
                    (short)((int)Raziel.steeringVelocity * gameTrackerX.timeMult * 0x10 >> 0x10));
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SteerAutoFace(struct _Instance *instance /*$s3*/, long *controlCommand /*$a1*/)
 // line 589, offset 0x800a2a00
	/* begin block 1 */
		// Start line: 590
		// Start offset: 0x800A2A00
		// Variables:
	// 		short angle; // $s0
	// 		int rc; // $s2
	// 		struct _Instance *target; // $a1
	// 		struct _G2SVector3_Type autoFaceRot; // stack offset -32
	// 		int diff; // $s1
	// 		int predict; // $s2
	/* end block 1 */
	// End offset: 0x800A2C74
	// End Line: 675

	/* begin block 2 */
		// Start line: 1138
	/* end block 2 */
	// End Line: 1139

	/* begin block 3 */
		// Start line: 1148
	/* end block 3 */
	// End Line: 1149

int SteerAutoFace(_Instance *instance,long *controlCommand)

{
  bool bVar1;
  short current;
  short sVar2;
  _G2Bool_Enum _Var3;
  _G2Anim_Type *anim;
  int iVar4;
  uint uVar5;
  _G2SVector3_Type local_20;
  
  current = MATH3D_AngleFromPosToPos
                      (&instance->position,&(Raziel.Senses.EngagedList[6].instance)->position);
  Raziel.autoFaceTrueAngle = (int)current;
  Raziel.autoFaceLastAnim = Raziel.autoFaceAnim;
  sVar2 = AngleDiff(current,Raziel.LastBearing);
  current = Raziel.LastBearing;
  iVar4 = (int)sVar2;
  bVar1 = iVar4 + 0x17fU < 0x2ff;
  if (bVar1) {
    Raziel.autoFaceAnim = 0;
    Raziel.autoFaceRootAngle = 0;
  }
  uVar5 = (uint)bVar1;
  if (iVar4 + 0x5ffU < 0x480) {
    uVar5 = 2;
    Raziel.autoFaceAnim = 1;
    Raziel.autoFaceRootAngle = 0x400;
  }
  if (iVar4 - 0x180U < 0x480) {
    uVar5 = 4;
    Raziel.autoFaceAnim = 3;
    Raziel.autoFaceRootAngle = -0x400;
  }
  if (0xbfe < iVar4 + 0x5ffU) {
    uVar5 = 3;
    Raziel.autoFaceAnim = 2;
    Raziel.autoFaceRootAngle = 0x800;
  }
  Raziel.steeringVelocity = 0x40;
  AngleMoveToward(&(instance->rotation).z,Raziel.LastBearing,
                  (short)((gameTrackerX.timeMult << 10) >> 0x10));
  Raziel.autoFaceAnim = uVar5 - 1;
  Raziel.autoFaceAngle = current;
  if (Raziel.autoFaceAnim != Raziel.autoFaceLastAnim) {
    anim = &instance->anim;
    (instance->rotation).z = Raziel.LastBearing;
    local_20.x = 0;
    local_20.y = 0;
    local_20.z = (short)Raziel.autoFaceRootAngle;
    _Var3 = G2Anim_IsControllerActive(anim,1,10);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(anim,1,10);
    }
    if (Raziel.input == Raziel.lastInput) {
      G2EmulationSetInterpController_Vector(instance,1,10,&local_20,4,3);
    }
    else {
      G2Anim_SetController_Vector(anim,1,10,&local_20);
    }
  }
  anim = &instance->anim;
  current = AngleDiff((instance->rotation).z,(short)Raziel.autoFaceTrueAngle);
  _Var3 = G2Anim_IsControllerInterpolating(anim,1,10);
  if (_Var3 == G2FALSE) {
    local_20.x = 0;
    local_20.y = 0;
    local_20.z = current - (short)Raziel.autoFaceRootAngle;
    _Var3 = G2Anim_IsControllerActive(anim,0xe,0xe);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(anim,0xe,0xe);
    }
    G2Anim_SetController_Vector(anim,0xe,0xe,&local_20);
  }
  else {
    _Var3 = G2Anim_IsControllerInterpolating(anim,0xe,0xe);
    if (_Var3 == G2FALSE) {
      local_20.x = 0;
      local_20.y = 0;
      local_20.z = current - (short)Raziel.autoFaceRootAngle;
      G2EmulationSetInterpController_Vector(instance,0xe,0xe,&local_20,4,3);
    }
  }
  return uVar5 | 0x10001000;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerSwim(struct _Instance *instance /*$s0*/)
 // line 681, offset 0x800a2c94
	/* begin block 1 */
		// Start line: 682
		// Start offset: 0x800A2C94
		// Variables:
	// 		int step; // $a0
	// 		int velocity; // $a1
	/* end block 1 */
	// End offset: 0x800A2D6C
	// End Line: 731

	/* begin block 2 */
		// Start line: 1371
	/* end block 2 */
	// End Line: 1372

void SteerSwim(_Instance *instance)

{
  int iVar1;
  
  iVar1 = rsin(Raziel.ZDirection);
  iVar1 = ((gameTrackerX.timeMult << 5) >> 0xc) * iVar1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  (instance->rotation).z = (instance->rotation).z - (short)(iVar1 >> 0xc);
  iVar1 = rcos(Raziel.ZDirection);
  if ((Raziel.steeringMode != 0x11) || (iVar1 < 0)) {
    iVar1 = (gameTrackerX.timeMult * 0x30 >> 0xc) * iVar1;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    Raziel.extraRot.x = Raziel.extraRot.x - (short)(iVar1 >> 0xc);
  }
  if (0x800 < Raziel.extraRot.x) {
    Raziel.extraRot.x = 0x800;
  }
  if (Raziel.extraRot.x < 0) {
    Raziel.extraRot.x = 0;
  }
  Raziel.extraRot.y = 0;
  Raziel.extraRot.z = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerWallcrawling(struct _Instance *instance /*$a0*/)
 // line 735, offset 0x800a2d84
	/* begin block 1 */
		// Start line: 1517
	/* end block 1 */
	// End Line: 1518

	/* begin block 2 */
		// Start line: 1523
	/* end block 2 */
	// End Line: 1524

void SteerWallcrawling(_Instance *instance)

{
  Raziel.Bearing =
       AngleDiff((short)(((uint)(ushort)ExtraRot->y - 0x800) * 0x10000 >> 0x10),
                 (short)Raziel.ZDirection);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerDisableAutoFace(struct _Instance *instance /*$s1*/)
 // line 748, offset 0x800a2db8
	/* begin block 1 */
		// Start line: 1549
	/* end block 1 */
	// End Line: 1550

void SteerDisableAutoFace(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim,1,10);
  if (_Var1 != G2FALSE) {
    G2Anim_DisableController(anim,1,10);
  }
  _Var1 = G2Anim_IsControllerActive(anim,0xe,0xe);
  if (_Var1 != G2FALSE) {
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
 // line 776, offset 0x800a2e4c
	/* begin block 1 */
		// Start line: 777
		// Start offset: 0x800A2E4C

		/* begin block 1.1 */
			// Start line: 846
			// Start offset: 0x800A2FD8
			// Variables:
		// 		int rotx; // $v1
		/* end block 1.1 */
		// End offset: 0x800A3040
		// End Line: 856
	/* end block 1 */
	// End offset: 0x800A308C
	// End Line: 883

	/* begin block 2 */
		// Start line: 1607
	/* end block 2 */
	// End Line: 1608

	/* begin block 3 */
		// Start line: 1611
	/* end block 3 */
	// End Line: 1612

void SteerSwitchMode(_Instance *instance,int mode)

{
  short sVar1;
  _G2Bool_Enum _Var2;
  uint uVar3;
  
  switch(Raziel.steeringMode) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x12:
    _Var2 = G2Anim_IsControllerActive(&instance->anim,1,0xe);
    if (_Var2 != G2FALSE) {
      G2Anim_DisableController(&instance->anim,1,0xe);
      (instance->rotation).z = (short)Raziel.steeringLockRotation;
      Raziel.LastBearing = (short)Raziel.steeringLockRotation;
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
    Raziel.extraRot.z = 0;
    Raziel.extraRot.x = 0;
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
    uVar3 = 0x1000U - (int)theCamera.core.rotation.x & 0xfff;
    Raziel.extraRot.x = (short)uVar3;
    if (uVar3 - 0x401 < 0x3ff) {
      Raziel.extraRot.x = 0x400;
    }
    else {
      if (uVar3 - 0x801 < 0x3ff) {
        Raziel.extraRot.x = 0xc00;
      }
    }
    CAMERA_StartSwimThrowMode(&theCamera);
    CAMERA_SetLookRot(&theCamera,0x1000 - (int)Raziel.extraRot.x,0);
  case 6:
  case 0x11:
    Raziel.RotationSegment = 1;
    break;
  case 0xe:
    sVar1 = MATH3D_AngleFromPosToPos
                      (&instance->position,&(Raziel.Senses.EngagedList[6].instance)->position);
    (instance->rotation).z = sVar1;
  }
  Raziel.steeringMode = mode;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razInitWallCrawlSteering(struct _Instance *instance /*$s0*/)
 // line 888, offset 0x800a30a8
	/* begin block 1 */
		// Start line: 889
		// Start offset: 0x800A30A8
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A30A8
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
  G2Anim_EnableController(anim,1,0x26);
  local_18.x = 0;
  local_18.y = 0;
  local_18.z = -0x13e;
  (instance->position).z = (instance->position).z + 0x13e;
  pMVar1 = instance->matrix;
  (instance->oldPos).z = (instance->oldPos).z + 0x13e;
  pMVar1->t[2] = pMVar1->t[2] + 0x13e;
  instance->oldMatrix->t[2] = instance->oldMatrix->t[2] + 0x13e;
  G2Anim_SetController_Vector(anim,1,0x26,&local_18);
  G2Anim_EnableController(anim,0,0xe);
  local_18.x = (instance->rotation).x;
  local_18.y = (instance->rotation).y;
  local_18.z = (instance->rotation).z;
  G2Anim_EnableController(anim,0,8);
  G2Anim_SetControllerAngleOrder(anim,0,8,1);
  G2Anim_SetController_Vector(anim,0,8,&local_18);
  G2Anim_EnableController(anim,0xe,0xe);
  G2Anim_EnableController(anim,0x32,0x4c);
  G2Anim_EnableController(anim,0x3a,0x4c);
  ExtraRotData.x = 0;
  ExtraRotData.y = 0;
  ExtraRotData.z = 0;
  ExtraRot = &ExtraRotData;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razDeinitWallCrawlSteering(struct _Instance *instance /*$s0*/)
 // line 922, offset 0x800a31e4
	/* begin block 1 */
		// Start line: 1931
	/* end block 1 */
	// End Line: 1932

void razDeinitWallCrawlSteering(_Instance *instance)

{
  MATRIX *pMVar1;
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  G2Anim_DisableController(anim,1,0x26);
  (instance->position).z = (instance->position).z + -0x13e;
  pMVar1 = instance->matrix;
  (instance->oldPos).z = (instance->oldPos).z + -0x13e;
  pMVar1->t[2] = pMVar1->t[2] + -0x13e;
  instance->oldMatrix->t[2] = instance->oldMatrix->t[2] + -0x13e;
  G2Anim_InterpDisableController(anim,0,0xe,300);
  G2Anim_InterpDisableController(anim,0,8,300);
  G2Anim_InterpDisableController(anim,0xe,0xe,300);
  G2Anim_InterpDisableController(anim,0x32,0x4c,300);
  G2Anim_InterpDisableController(anim,0x3a,0x4c,300);
  return;
}





