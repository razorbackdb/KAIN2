
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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

int GetControllerInput(int *ZDirection,long *controlCommand)

{
  int iVar1;
  uint uVar2;
  
  if ((*(uint *)(DAT_800d20f8 + 0x14) & 0x100) == 0) {
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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

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
  
  if (((DAT_800d5acc == 9) || (DAT_800d5acc == 0xe)) || (DAT_800d5acc == 0xf)) {
    rc = 0;
  }
  else {
    rc = GetControllerInput(&iStack32,controlCommand);
  }
  razZeroAxis(controlCommand + 3,controlCommand + 4,0x400);
  ix = controlCommand[3];
  if (((ix == 0x80) || (ix == -0x80)) || ((iy = controlCommand[4], iy == 0x80 || (iy == -0x80)))) {
    ix = 0x1000;
LAB_800a17f8:
    DAT_800d5ab8 = ix;
  }
  else {
    DAT_800d5ab8 = MATH3D_veclen2(ix,iy);
    DAT_800d5ab8 = DAT_800d5ab8 << 5;
    if (0x1000 < DAT_800d5ab8) {
      DAT_800d5ab8 = 0x1000;
    }
    if ((DAT_800d5ab8 != 0) && (ix = 0x400, DAT_800d5ab8 < 0x400)) goto LAB_800a17f8;
  }
  DAT_800d5ac0 = DAT_800d5abc;
  ix = (controlCommand[4] << 0xc) >> 0x1f;
  iy = (controlCommand[3] << 0xc) >> 0x1f;
  DAT_800d5abc = rc;
  lVar2 = ratan2(((controlCommand[4] << 0xc) / 6 + ix >> 4) - ix,
                 ((controlCommand[3] << 0xc) / 6 + iy >> 4) - iy);
  DAT_800d5ac4 = 0x400U - lVar2 & 0xfff;
  if (rc != 0) {
    DAT_800d5aca = (short)DAT_800d5ac4 + DAT_800d1098;
  }
  DAT_800d5ac8 = AngleDiff((instance->rotation).z,DAT_800d5aca);
  switch(DAT_800d5acc) {
  case 0:
  case 0x10:
    goto switchD_800a18b4_caseD_0;
  case 1:
    DAT_800d5ad0 = 0x100;
    goto LAB_800a1928;
  case 2:
    SteerMove(instance,rc);
    break;
  case 4:
    local_28.y = 0;
    local_28.x = 0;
    local_28.z = (short)DAT_800d5ad4 - DAT_800d5aca;
    (instance->rotation).z = DAT_800d5aca;
    if (rc != 0) {
      lVar2 = 0x15;
      if (DAT_800d5aa4 == 0x10) {
        lVar2 = 0x28;
      }
      instance->yVel = lVar2;
    }
    G2Anim_SetController_Vector(&instance->anim,1,0xe,&local_28);
    break;
  case 5:
  case 9:
    if (rc != 0) {
LAB_800a1a80:
      rc = SteerAutoFace(instance,controlCommand);
      return rc;
    }
    if ((*PadData & RazielCommands[7]) == 0) {
      return 0;
    }
    if ((DAT_800d5b1c & 0x40) == 0) {
      return 0;
    }
    SteerDisableAutoFace(instance);
    destination = MATH3D_AngleFromPosToPos
                            (&instance->position,(_Position *)(*(int *)(DAT_800d5b18 + 0x30) + 0x5c)
                            );
    DAT_800d5ad0 = 0x80;
    step = (short)((uint)(DAT_800d2314 << 0xb) >> 0x10);
    goto LAB_800a1bb0;
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
    G2Anim_SetController_Vector(anim,1,0xe,(_G2SVector3_Type *)&DAT_800d5c50);
    break;
  case 7:
    SteerWallcrawling(instance);
    Difference = &sStack24;
    if (rc == 0) {
      return 0;
    }
    Zone = asStack22;
    goto LAB_800a1b74;
  case 8:
    DAT_800d5ad0 = 0x60;
    goto LAB_800a1928;
  case 10:
    destination = MATH3D_AngleFromPosToPos(&instance->position,(_Position *)(DAT_800d5ba0 + 0x5c));
    DAT_800d5ad0 = 0x100;
    step = (short)((uint)(DAT_800d2314 << 0xc) >> 0x10);
    goto LAB_800a1bb0;
  case 0xb:
    anim = &instance->anim;
    _Var3 = G2Anim_IsControllerActive(anim,1,0xe);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(anim,1,0xe);
    }
    G2Anim_SetController_Vector(anim,1,0xe,(_G2SVector3_Type *)&DAT_800d5c50);
    goto switchD_800a18b4_caseD_0;
  case 0xc:
    destination = MATH3D_AngleFromPosToPos(&instance->position,(_Position *)&DAT_800d5c8e);
    goto LAB_800a1c10;
  case 0xd:
    destination = DAT_800d5c92;
LAB_800a1c10:
    DAT_800d5ad0 = 0x100;
    AngleMoveToward(&(instance->rotation).z,destination,(short)((uint)(DAT_800d2314 << 0xc) >> 0x10)
                   );
    if (destination == (instance->rotation).z) {
      SteerSwitchMode(instance,0);
    }
    break;
  case 0xe:
    if (((*PadData & RazielCommands[7]) != 0) && ((DAT_800d5b1c & 0x40) != 0)) {
      destination = MATH3D_AngleFromPosToPos
                              (&instance->position,
                               (_Position *)(*(int *)(DAT_800d5b18 + 0x30) + 0x5c));
      (instance->rotation).z = destination;
    }
    break;
  case 0xf:
    if (rc != 0) goto LAB_800a1a80;
    if ((DAT_800d5b1c & 0x40) == 0) {
      return 0;
    }
    SteerDisableAutoFace(instance);
    destination = MATH3D_AngleFromPosToPos
                            (&instance->position,(_Position *)(*(int *)(DAT_800d5b18 + 0x30) + 0x5c)
                            );
    uVar1 = MON_FacingOffset(*(_Instance **)(DAT_800d5b18 + 0x30),instance);
    if (((uint)uVar1 & 0xfff) - 0x2ab < 0xaab) {
      return 0;
    }
    DAT_800d5ad0 = 0x80;
    step = (short)((uint)(DAT_800d2314 << 0xb) >> 0x10);
LAB_800a1bb0:
    AngleMoveToward(&(instance->rotation).z,destination,step);
    break;
  case 0x12:
    DAT_800d5ad0 = 0x40;
LAB_800a1928:
    SteerTurn(instance,rc);
  }
  return rc;
switchD_800a18b4_caseD_0:
  Difference = &sStack28;
  if (rc == 0) {
    return 0;
  }
  Zone = &sStack26;
LAB_800a1b74:
  rc = DecodeDirection((int)DAT_800d5ac8,0,Difference,Zone);
  return rc;
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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

void SteerTurn(_Instance *instance,int rc)

{
  short sVar1;
  
  if ((rc == 0) && (DAT_800d5ac8 == 0)) {
    DAT_800d5ad0 = 0;
  }
  else {
    sVar1 = DAT_800d5aca;
    if ((DAT_800d5ac8 == 0x800) &&
       (sVar1 = DAT_800d5aca + 1, (int)(instance->rotation).z - (int)DAT_800d5aca < 1)) {
      sVar1 = DAT_800d5aca + -1;
    }
    DAT_800d5aca = sVar1;
    AngleMoveToward(&(instance->rotation).z,DAT_800d5aca,
                    (short)((uint)(DAT_800d5ad0 * DAT_800d2314 * 0x10) >> 0x10));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerMove(struct _Instance *instance /*$a0*/, int rc /*$a1*/)
 // line 547, offset 0x800a1ce8
	/* begin block 1 */
		// Start line: 1088
	/* end block 1 */
	// End Line: 1089

/* File: C:\kain2\game\RAZIEL\STEERING.C */

void SteerMove(_Instance *instance,int rc)

{
  int iVar1;
  
  if ((rc == 0) && (DAT_800d5ac8 == 0)) {
    DAT_800d5ad0 = 0;
  }
  else {
    DAT_800d5ad0 = -DAT_800d5ac8;
    if (-1 < DAT_800d5ac8) {
      DAT_800d5ad0 = DAT_800d5ac8;
    }
    iVar1 = (int)DAT_800d5ad0;
    DAT_800d5ad0 = 0x70;
    if (0x300 < iVar1) {
      if (iVar1 < 0) {
        iVar1 = iVar1 + 3;
      }
      DAT_800d5ad0 = (short)(iVar1 >> 2) + 0x70;
    }
    AngleMoveToward(&(instance->rotation).z,DAT_800d5aca,
                    (short)((uint)(DAT_800d5ad0 * DAT_800d2314 * 0x10) >> 0x10));
  }
  return;
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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

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
                      (&instance->position,(_Position *)(*(int *)(DAT_800d5b18 + 0x30) + 0x5c));
  DAT_800d5c74 = (int)current;
  DAT_800d5c7c = DAT_800d5c78;
  sVar2 = AngleDiff(current,DAT_800d5aca);
  current = DAT_800d5aca;
  iVar4 = (int)sVar2;
  bVar1 = iVar4 + 0x17fU < 0x2ff;
  if (bVar1) {
    DAT_800d5c78 = 0;
    DAT_800d5c70 = 0;
  }
  uVar5 = (uint)bVar1;
  if (iVar4 + 0x5ffU < 0x480) {
    uVar5 = 2;
    DAT_800d5c78 = 1;
    DAT_800d5c70 = 0x400;
  }
  if (iVar4 - 0x180U < 0x480) {
    uVar5 = 4;
    DAT_800d5c78 = 3;
    DAT_800d5c70 = 0xfffffc00;
  }
  if (0xbfe < iVar4 + 0x5ffU) {
    uVar5 = 3;
    DAT_800d5c78 = 2;
    DAT_800d5c70 = 0x800;
  }
  DAT_800d5ad0 = 0x40;
  AngleMoveToward(&(instance->rotation).z,DAT_800d5aca,(short)((uint)(DAT_800d2314 << 10) >> 0x10));
  DAT_800d5c78 = uVar5 - 1;
  DAT_800d5c6a = current;
  if (DAT_800d5c78 != DAT_800d5c7c) {
    anim = &instance->anim;
    (instance->rotation).z = DAT_800d5aca;
    local_20.x = 0;
    local_20.y = 0;
    local_20.z = (short)DAT_800d5c70;
    _Var3 = G2Anim_IsControllerActive(anim,1,10);
    if (_Var3 == G2FALSE) {
      G2Anim_EnableController(anim,1,10);
    }
    if (DAT_800d5abc == DAT_800d5ac0) {
      G2EmulationSetInterpController_Vector(instance,1,10,&local_20,4,3);
    }
    else {
      G2Anim_SetController_Vector(anim,1,10,&local_20);
    }
  }
  anim = &instance->anim;
  current = AngleDiff((instance->rotation).z,(short)DAT_800d5c74);
  _Var3 = G2Anim_IsControllerInterpolating(anim,1,10);
  if (_Var3 == G2FALSE) {
    local_20.x = 0;
    local_20.y = 0;
    local_20.z = current - (short)DAT_800d5c70;
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
      local_20.z = current - (short)DAT_800d5c70;
      G2EmulationSetInterpController_Vector(instance,0xe,0xe,&local_20,4,3);
    }
  }
  return uVar5 | 0x10001000;
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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

void SteerSwim(_Instance *instance)

{
  int iVar1;
  
  iVar1 = rsin(DAT_800d5ac4);
  iVar1 = ((uint)(DAT_800d2314 << 5) >> 0xc) * iVar1;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  (instance->rotation).z = (instance->rotation).z - (short)(iVar1 >> 0xc);
  iVar1 = rcos(DAT_800d5ac4);
  if ((DAT_800d5acc != 0x11) || (iVar1 < 0)) {
    iVar1 = ((uint)(DAT_800d2314 * 0x30) >> 0xc) * iVar1;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    DAT_800d5c50 = DAT_800d5c50 - (short)(iVar1 >> 0xc);
  }
  if (0x800 < DAT_800d5c50) {
    DAT_800d5c50 = 0x800;
  }
  if (DAT_800d5c50 < 0) {
    DAT_800d5c50 = 0;
  }
  DAT_800d5c52 = 0;
  DAT_800d5c54 = 0;
  return;
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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

void SteerWallcrawling(_Instance *instance)

{
  DAT_800d5ac8 = AngleDiff((short)(((uint)(ushort)ExtraRot->y - 0x800) * 0x10000 >> 0x10),
                           (short)DAT_800d5ac4);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SteerDisableAutoFace(struct _Instance *instance /*$s1*/)
 // line 745, offset 0x800a2150
	/* begin block 1 */
		// Start line: 1543
	/* end block 1 */
	// End Line: 1544

/* File: C:\kain2\game\RAZIEL\STEERING.C */

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
  (instance->rotation).z = (instance->rotation).z + (short)DAT_800d5c70;
  DAT_800d5c70 = 0;
  DAT_800d5c78 = 0xffffffff;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\RAZIEL\STEERING.C */

void SteerSwitchMode(_Instance *instance,int mode)

{
  short sVar1;
  _G2Bool_Enum _Var2;
  
  switch(DAT_800d5acc) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x12:
    _Var2 = G2Anim_IsControllerActive(&instance->anim,1,0xe);
    if (_Var2 != G2FALSE) {
      G2Anim_DisableController(&instance->anim,1,0xe);
      (instance->rotation).z = (short)DAT_800d5ad4;
      DAT_800d5aca = (short)DAT_800d5ad4;
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
      DAT_800d5c50 = 0;
    }
    break;
  case 7:
    if (mode != DAT_800d5acc) {
      razDeinitWallCrawlSteering(instance);
    }
    break;
  case 10:
    DAT_800d5ba0 = 0;
    break;
  case 0xb:
    CAMERA_EndSwimThrowMode((Camera *)&theCamera);
    CAMERA_SetLookRot((Camera *)&theCamera,0,0);
    DAT_800d5c50 = DAT_800d5bbc;
  }
  DAT_800d5aac = 0;
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
    DAT_800d5aac = 0;
    break;
  case 7:
    if (mode != DAT_800d5acc) {
      razInitWallCrawlSteering(instance);
    }
    break;
  case 0xb:
    _DAT_800d5bbc = (int)DAT_800d5c50;
    DAT_800d5c50 = 0x1000 - DAT_800d104c;
    CAMERA_StartSwimThrowMode((Camera *)&theCamera);
    CAMERA_SetLookRot((Camera *)&theCamera,0x1000 - (int)DAT_800d5c50,0);
  case 6:
  case 0x11:
    DAT_800d5aac = 1;
    break;
  case 0xe:
    sVar1 = MATH3D_AngleFromPosToPos
                      (&instance->position,(_Position *)(*(int *)(DAT_800d5b18 + 0x30) + 0x5c));
    (instance->rotation).z = sVar1;
  }
  DAT_800d5acc = mode;
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

/* File: C:\kain2\game\RAZIEL\STEERING.C */

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
 // line 913, offset 0x800a2558
	/* begin block 1 */
		// Start line: 1910
	/* end block 1 */
	// End Line: 1911

/* File: C:\kain2\game\RAZIEL\STEERING.C */

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





