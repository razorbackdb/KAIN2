#include "THISDUST.H"
#include "STEERING.H"


// decompiled code
// original method signature: 
// int /*$ra*/ UpdateZoneDelta(int rc /*$a0*/, int LastRC /*$a1*/)
 // line 20, offset 0x8009ece8
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
 // line 34, offset 0x8009ed24
	/* begin block 1 */
		// Start line: 35
		// Start offset: 0x8009ED24
		// Variables:
	// 		int rc; // $s0
	/* end block 1 */
	// End offset: 0x8009EEF4
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
 // line 117, offset 0x8009ef04
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x8009EF04
		// Variables:
	// 		int rc; // $s1
	/* end block 1 */
	// End offset: 0x8009EFD8
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
 // line 188, offset 0x8009eff4
	/* begin block 1 */
		// Start line: 189
		// Start offset: 0x8009EFF4
		// Variables:
	// 		int ZDirection; // stack offset -32
	// 		int rc; // $s2
	// 		int lag; // $v1

		/* begin block 1.1 */
			// Start line: 266
			// Start offset: 0x8009F1D0
			// Variables:
		// 		short diff; // stack offset -28
		// 		short zone; // stack offset -26
		/* end block 1.1 */
		// End offset: 0x8009F1D0
		// End Line: 267

		/* begin block 1.2 */
			// Start line: 309
			// Start offset: 0x8009F218
			// Variables:
		// 		struct _G2SVector3_Type rot; // stack offset -40
		/* end block 1.2 */
		// End offset: 0x8009F26C
		// End Line: 329

		/* begin block 1.3 */
			// Start line: 331
			// Start offset: 0x8009F26C
		/* end block 1.3 */
		// End offset: 0x8009F2B8
		// End Line: 348

		/* begin block 1.4 */
			// Start line: 357
			// Start offset: 0x8009F2C0
			// Variables:
		// 		short angle; // $s0
		/* end block 1.4 */
		// End offset: 0x8009F31C
		// End Line: 368

		/* begin block 1.5 */
			// Start line: 383
			// Start offset: 0x8009F354
		/* end block 1.5 */
		// End offset: 0x8009F384
		// End Line: 387

		/* begin block 1.6 */
			// Start line: 416
			// Start offset: 0x8009F42C
			// Variables:
		// 		short diff; // stack offset -24
		// 		short zone; // stack offset -22
		/* end block 1.6 */
		// End offset: 0x8009F42C
		// End Line: 417

		/* begin block 1.7 */
			// Start line: 421
			// Start offset: 0x8009F448
		/* end block 1.7 */
		// End offset: 0x8009F484
		// End Line: 431

		/* begin block 1.8 */
			// Start line: 433
			// Start offset: 0x8009F484
		/* end block 1.8 */
		// End offset: 0x8009F4B4
		// End Line: 444

		/* begin block 1.9 */
			// Start line: 446
			// Start offset: 0x8009F4B4
			// Variables:
		// 		short angle; // $s0
		/* end block 1.9 */
		// End offset: 0x8009F4FC
		// End Line: 457
	/* end block 1 */
	// End offset: 0x8009F4FC
	// End Line: 472

	/* begin block 2 */
		// Start line: 375
	/* end block 2 */
	// End Line: 376

/* WARNING: Type propagation algorithm not settling */

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
  _G2Anim_Type *anim;
  int rc;
  _G2SVector3_Type local_28;
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
LAB_8009f0c4:
    Raziel.Magnitude = ix;
  }
  else {
    Raziel.Magnitude = MATH3D_veclen2(ix,iy);
    Raziel.Magnitude = Raziel.Magnitude << 5;
    if (0x1000 < Raziel.Magnitude) {
      Raziel.Magnitude = 0x1000;
    }
    if ((Raziel.Magnitude != 0) && (ix = 0x400, Raziel.Magnitude < 0x400)) goto LAB_8009f0c4;
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
    goto switchD_8009f180_caseD_0;
  case 1:
    Raziel.steeringVelocity = 0x100;
    goto LAB_8009f1ec;
  case 2:
    SteerMove(instance,rc);
    break;
  case 4:
    local_28.y = 0;
    local_28.x = 0;
    local_28.z = (short)Raziel.steeringLockRotation - Raziel.LastBearing;
    (instance->rotation).z = Raziel.LastBearing;
    if (rc != 0) {
      lVar2 = 0x15;
      if (Raziel.Mode == 0x10) {
        lVar2 = 0x28;
      }
      instance->yVel = lVar2;
    }
    G2Anim_SetController_Vector(&instance->anim,1,0xe,&local_28);
    break;
  case 5:
  case 9:
    if (rc != 0) {
LAB_8009f344:
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
    step = (short)((gameTrackerX.idleTime << 0xb) >> 0x10);
    goto LAB_8009f474;
  case 6:
  case 0x11:
    if (rc != 0) {
      SteerSwim(instance);
    }
    anim = &instance->anim;
    _Var3 = G2Anim_IsControllerActive(anim,1,0xe);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(anim,1,0xe);
    }
    G2Anim_SetController_Vector(anim,1,0xe,(_G2SVector3_Type *)&Raziel.padCommands);
    break;
  case 7:
    SteerWallcrawling(instance);
    Difference = &sStack24;
    if (rc == 0) {
      return 0;
    }
    Zone = asStack22;
    goto LAB_8009f438;
  case 8:
    Raziel.steeringVelocity = 0x60;
LAB_8009f1ec:
    SteerTurn(instance,rc);
    break;
  case 10:
    destination = MATH3D_AngleFromPosToPos
                            (&instance->position,(_Position *)&Raziel.glowEffect[2].continue_process
                            );
    Raziel.steeringVelocity = 0x100;
    step = (short)((gameTrackerX.idleTime << 0xc) >> 0x10);
    goto LAB_8009f474;
  case 0xb:
    anim = &instance->anim;
    _Var3 = G2Anim_IsControllerActive(anim,1,0xe);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(anim,1,0xe);
    }
    G2Anim_SetController_Vector(anim,1,0xe,(_G2SVector3_Type *)&Raziel.padCommands);
    goto switchD_8009f180_caseD_0;
  case 0xc:
    destination = MATH3D_AngleFromPosToPos
                            (&instance->position,
                             (_Position *)((int)&Raziel.padCommands.Queue[6].Data + 2));
    goto LAB_8009f4d4;
  case 0xd:
    destination = Raziel.padCommands.Queue[7].ID._2_2_;
LAB_8009f4d4:
    Raziel.steeringVelocity = 0x100;
    AngleMoveToward(&(instance->rotation).z,destination,
                    (short)((gameTrackerX.idleTime << 0xc) >> 0x10));
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
    if (rc != 0) goto LAB_8009f344;
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
    step = (short)((gameTrackerX.idleTime << 0xb) >> 0x10);
LAB_8009f474:
    AngleMoveToward(&(instance->rotation).z,destination,step);
  }
  return rc;
switchD_8009f180_caseD_0:
  Difference = &sStack28;
  if (rc == 0) {
    return 0;
  }
  Zone = &sStack26;
LAB_8009f438:
  rc = DecodeDirection((int)Raziel.Bearing,0,Difference,Zone);
  return rc;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerTurn(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
 // line 477, offset 0x8009f518
	/* begin block 1 */
		// Start line: 478
		// Start offset: 0x8009F518

		/* begin block 1.1 */
			// Start line: 484
			// Start offset: 0x8009F544
			// Variables:
		// 		int rot; // $v0
		/* end block 1.1 */
		// End offset: 0x8009F568
		// End Line: 496
	/* end block 1 */
	// End offset: 0x8009F59C
	// End Line: 501

	/* begin block 2 */
		// Start line: 954
	/* end block 2 */
	// End Line: 955

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
                    (short)((int)Raziel.steeringVelocity * gameTrackerX.idleTime * 0x10 >> 0x10));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerMove(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
 // line 540, offset 0x8009f5ac
	/* begin block 1 */
		// Start line: 1074
	/* end block 1 */
	// End Line: 1075

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
    if (0x200 < iVar1) {
      if (iVar1 < 0) {
        iVar1 = iVar1 + 3;
      }
      Raziel.steeringVelocity = (short)(iVar1 >> 2) + 0x70;
    }
    AngleMoveToward(&(instance->rotation).z,Raziel.LastBearing,
                    (short)((int)Raziel.steeringVelocity * gameTrackerX.idleTime * 0x10 >> 0x10));
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SteerAutoFace(struct _Instance *instance /*$s3*/, long *controlCommand /*$a1*/)
 // line 575, offset 0x8009f65c
	/* begin block 1 */
		// Start line: 576
		// Start offset: 0x8009F65C
		// Variables:
	// 		short angle; // $s0
	// 		int rc; // $s2
	// 		struct _Instance *target; // $a1
	// 		struct _G2SVector3_Type autoFaceRot; // stack offset -32
	// 		int diff; // $s1
	// 		int predict; // $s2
	/* end block 1 */
	// End offset: 0x8009F8D0
	// End Line: 661

	/* begin block 2 */
		// Start line: 1110
	/* end block 2 */
	// End Line: 1111

	/* begin block 3 */
		// Start line: 1120
	/* end block 3 */
	// End Line: 1121

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
  Raziel.padCommands.Queue[3].Data = (int)current;
  Raziel.padCommands.Queue[4].Data = Raziel.padCommands.Queue[4].ID;
  sVar2 = AngleDiff(current,Raziel.LastBearing);
  current = Raziel.LastBearing;
  iVar4 = (int)sVar2;
  bVar1 = iVar4 + 0x17fU < 0x2ff;
  if (bVar1) {
    Raziel.padCommands.Queue[4].ID = 0;
    Raziel.padCommands.Queue[3].ID = 0;
  }
  uVar5 = (uint)bVar1;
  if (iVar4 + 0x5ffU < 0x480) {
    uVar5 = 2;
    Raziel.padCommands.Queue[4].ID = 1;
    Raziel.padCommands.Queue[3].ID = 0x400;
  }
  if (iVar4 - 0x180U < 0x480) {
    uVar5 = 4;
    Raziel.padCommands.Queue[4].ID = 3;
    Raziel.padCommands.Queue[3].ID = -0x400;
  }
  if (0xbfe < iVar4 + 0x5ffU) {
    uVar5 = 3;
    Raziel.padCommands.Queue[4].ID = 2;
    Raziel.padCommands.Queue[3].ID = 0x800;
  }
  Raziel.steeringVelocity = 0x40;
  AngleMoveToward(&(instance->rotation).z,Raziel.LastBearing,
                  (short)((gameTrackerX.idleTime << 10) >> 0x10));
  Raziel.padCommands.Queue[4].ID = uVar5 - 1;
  Raziel.padCommands.Queue[2].ID._2_2_ = current;
  if (Raziel.padCommands.Queue[4].ID != Raziel.padCommands.Queue[4].Data) {
    anim = &instance->anim;
    (instance->rotation).z = Raziel.LastBearing;
    local_20.x = 0;
    local_20.y = 0;
    local_20.z = (short)Raziel.padCommands.Queue[3].ID;
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
  current = AngleDiff((instance->rotation).z,(short)Raziel.padCommands.Queue[3].Data);
  _Var3 = G2Anim_IsControllerInterpolating(anim,1,10);
  if (_Var3 == G2FALSE) {
    local_20.x = 0;
    local_20.y = 0;
    local_20.z = current - (short)Raziel.padCommands.Queue[3].ID;
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
      local_20.z = current - (short)Raziel.padCommands.Queue[3].ID;
      G2EmulationSetInterpController_Vector(instance,0xe,0xe,&local_20,4,3);
    }
  }
  return uVar5 | 0x10001000;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerSwim(struct _Instance *instance /*$s0*/)
 // line 667, offset 0x8009f8f0
	/* begin block 1 */
		// Start line: 668
		// Start offset: 0x8009F8F0
		// Variables:
	// 		int step; // $a0
	// 		int velocity; // $a1
	/* end block 1 */
	// End offset: 0x8009F9C8
	// End Line: 717

	/* begin block 2 */
		// Start line: 1343
	/* end block 2 */
	// End Line: 1344

void SteerSwim(_Instance *instance)

{
  int iVar1;
  
  iVar1 = rsin(Raziel.ZDirection);
  iVar1 = ((gameTrackerX.idleTime << 5) >> 0xc) * iVar1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  (instance->rotation).z = (instance->rotation).z - (short)(iVar1 >> 0xc);
  iVar1 = rcos(Raziel.ZDirection);
  if ((Raziel.steeringMode != 0x11) || (iVar1 < 0)) {
    iVar1 = (gameTrackerX.idleTime * 0x30 >> 0xc) * iVar1;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    Raziel.padCommands.Head._0_2_ = (short)Raziel.padCommands.Head - (short)(iVar1 >> 0xc);
  }
  if (0x800 < (short)Raziel.padCommands.Head) {
    Raziel.padCommands.Head._0_2_ = 0x800;
  }
  if ((short)Raziel.padCommands.Head < 0) {
    Raziel.padCommands.Head._0_2_ = 0;
  }
  Raziel.padCommands.Head._2_2_ = 0;
  Raziel.padCommands.Tail._0_2_ = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerWallcrawling(struct _Instance *instance /*$a0*/)
 // line 721, offset 0x8009f9e0
	/* begin block 1 */
		// Start line: 1489
	/* end block 1 */
	// End Line: 1490

	/* begin block 2 */
		// Start line: 1495
	/* end block 2 */
	// End Line: 1496

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
 // line 734, offset 0x8009fa14
	/* begin block 1 */
		// Start line: 1521
	/* end block 1 */
	// End Line: 1522

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
  (instance->rotation).z = (instance->rotation).z + (short)Raziel.padCommands.Queue[3].ID;
  Raziel.padCommands.Queue[3].ID = 0;
  Raziel.padCommands.Queue[4].ID = -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerSwitchMode(struct _Instance *instance /*$s1*/, int mode /*$s2*/)
 // line 762, offset 0x8009faa8
	/* begin block 1 */
		// Start line: 1579
	/* end block 1 */
	// End Line: 1580

	/* begin block 2 */
		// Start line: 1582
	/* end block 2 */
	// End Line: 1583

void SteerSwitchMode(_Instance *instance,int mode)

{
  short sVar1;
  _G2Bool_Enum _Var2;
  
  switch(Raziel.steeringMode) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 8:
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
      Raziel.padCommands.Head._0_2_ = 0;
    }
    break;
  case 7:
    if (mode != Raziel.steeringMode) {
      razDeinitWallCrawlSteering(instance);
    }
    break;
  case 10:
    Raziel.glowEffect = (_FXGlowEffect *)0x0;
    break;
  case 0xb:
    CAMERA_EndSwimThrowMode(&theCamera);
    CAMERA_SetLookRot(&theCamera,0,0);
  }
  switch(mode) {
  default:
    Raziel.RotationSegment = 0;
    break;
  case 7:
    if (mode != Raziel.steeringMode) {
      razInitWallCrawlSteering(instance);
    }
    break;
  case 0xb:
    Raziel.padCommands.Head._0_2_ = 0x1000 - theCamera.core.rotation.x;
    CAMERA_StartSwimThrowMode(&theCamera);
    CAMERA_SetLookRot(&theCamera,0x1000 - (int)(short)Raziel.padCommands.Head,0);
  case 6:
  case 0x11:
    Raziel.RotationSegment = 1;
    break;
  case 0xe:
    sVar1 = MATH3D_AngleFromPosToPos
                      (&instance->position,&(Raziel.Senses.EngagedList[6].instance)->position);
    (instance->rotation).z = sVar1;
    break;
  case 0x10:
    break;
  }
  Raziel.steeringMode = mode;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razInitWallCrawlSteering(struct _Instance *instance /*$s0*/)
 // line 866, offset 0x8009fcc0
	/* begin block 1 */
		// Start line: 867
		// Start offset: 0x8009FCC0
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -24
	/* end block 1 */
	// End offset: 0x8009FCC0
	// End Line: 867

	/* begin block 2 */
		// Start line: 1791
	/* end block 2 */
	// End Line: 1792

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
 // line 900, offset 0x8009fe00
	/* begin block 1 */
		// Start line: 1882
	/* end block 1 */
	// End Line: 1883

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





