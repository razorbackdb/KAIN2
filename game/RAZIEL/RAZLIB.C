#include "THISDUST.H"
#include "RAZLIB.H"


// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYMoveRot(struct _Instance *dest /*$s3*/, short distance /*$a1*/, struct _Position *position /*$s4*/, struct _Rotation *rotation /*$s2*/, int extraZ /*stack 16*/)
 // line 12, offset 0x800a1774
	/* begin block 1 */
		// Start line: 13
		// Start offset: 0x800A1774
		// Variables:
	// 		struct SVECTOR d; // stack offset -72
	// 		struct SVECTOR dd; // stack offset -64
	// 		struct MATRIX mat; // stack offset -56
	/* end block 1 */
	// End offset: 0x800A1774
	// End Line: 13

	/* begin block 2 */
		// Start line: 24
	/* end block 2 */
	// End Line: 25

void razAlignYMoveRot(_Instance *dest,short distance,_Position *position,_Rotation *rotation,
                     int extraZ)

{
  ulong uVar1;
  undefined2 local_48;
  short local_46;
  undefined2 local_44;
  short local_40;
  short local_3e;
  short local_3c;
  MATRIX MStack56;
  
  local_46 = -distance;
  local_48 = 0;
  local_44 = 0;
  uVar1 = INSTANCE_Query(dest,7);
  rotation->z = *(short *)(uVar1 + 4) + (short)extraZ + 0x800;
  MATH3D_SetUnityMatrix(&MStack56);
  RotMatrixZ((int)rotation->z,(short *)&MStack56);
  ApplyMatrixSV(&MStack56,&local_48,&local_40);
  position->x = (dest->position).x + local_40;
  position->y = (dest->position).y + local_3e;
  position->z = (dest->position).z + local_3c;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotMove(struct _Instance *dest /*$s1*/, short distance /*$a1*/, struct _Position *position /*$s2*/, struct _Rotation *rotation /*$s4*/, int extraZ /*stack 16*/)
 // line 54, offset 0x800a184c
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800A184C
		// Variables:
	// 		struct SVECTOR d; // stack offset -88
	// 		struct SVECTOR dd; // stack offset -80
	// 		struct SVECTOR rot; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64
	/* end block 1 */
	// End offset: 0x800A184C
	// End Line: 55

	/* begin block 2 */
		// Start line: 136
	/* end block 2 */
	// End Line: 137

void razAlignYRotMove(_Instance *dest,short distance,_Position *position,_Rotation *rotation,
                     int extraZ)

{
  undefined2 local_58;
  short local_56;
  undefined2 local_54;
  short local_50;
  short local_4e;
  short local_4c;
  short asStack72 [2];
  short local_44;
  uint auStack64 [8];
  
  memset(asStack72,0,8);
  local_44 = MATH3D_AngleFromPosToPos(position,&dest->position);
  local_44 = local_44 + (short)extraZ;
  rotation->z = local_44;
  RotMatrix(asStack72,auStack64);
  local_58 = 0;
  local_54 = 0;
  local_56 = distance;
  ApplyMatrixSV(auStack64,&local_58,&local_50);
  position->x = (dest->position).x + local_50;
  position->y = (dest->position).y + local_4e;
  position->z = (dest->position).z + local_4c;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotMoveInterp(struct _Instance *source /*$s1*/, struct _Instance *dest /*$a1*/, short distance /*$a2*/, unsigned char segNumber /*$s0*/, int Frames /*stack 16*/, int extraZ /*stack 20*/)
 // line 86, offset 0x800a1938
	/* begin block 1 */
		// Start line: 87
		// Start offset: 0x800A1938
		// Variables:
	// 		struct _Position position; // stack offset -40
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _G2SVector3_Type v; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A1938
	// End Line: 87

	/* begin block 2 */
		// Start line: 210
	/* end block 2 */
	// End Line: 211

void razAlignYRotMoveInterp
               (_Instance *source,_Instance *dest,short distance,uchar segNumber,int Frames,
               int extraZ)

{
  undefined4 local_28;
  short local_24;
  _Rotation _Stack32;
  _G2SVector3_Type local_18;
  
  local_28 = *(undefined4 *)&source->position;
  local_24 = (source->position).z;
  razAlignYRotMove(dest,distance,(_Position *)&local_28,&_Stack32,(int)(short)extraZ);
  *(undefined4 *)&source->position = local_28;
  (source->position).z = local_24;
  local_18.x = 0;
  local_18.y = 0;
  local_18.z = _Stack32.z;
  G2Anim_EnableController(&source->anim,(uint)segNumber,8);
  G2EmulationSetInterpController_Vector(source,(uint)segNumber,8,&local_18,Frames,0);
  (source->rotation).z = _Stack32.z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotInterp(struct _Instance *source /*$s0*/, struct _Position *dest /*$a1*/, unsigned char segNumber /*$a2*/, int Frames /*$a3*/)
 // line 114, offset 0x800a1a2c
	/* begin block 1 */
		// Start line: 306
	/* end block 1 */
	// End Line: 307

void razAlignYRotInterp(_Instance *source,_Position *dest,uchar segNumber,int Frames)

{
  short sVar1;
  
  sVar1 = MATH3D_AngleFromPosToPos(&source->position,dest);
  (source->rotation).z = sVar1;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razConstrictAngle(struct _Instance *instance /*$a0*/)
 // line 195, offset 0x800a1a58
	/* begin block 1 */
		// Start line: 196
		// Start offset: 0x800A1A58
		// Variables:
	// 		int i; // $s0
	// 		int j; // $s2
	// 		int k; // $a2
	// 		int Total; // $s1
	// 		int outer; // stack offset -32
	// 		int rc; // $s3
	// 		struct _SVector point; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A1B54
	// End Line: 243

	/* begin block 2 */
		// Start line: 385
	/* end block 2 */
	// End Line: 386

int razConstrictAngle(_Instance *instance)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short local_28;
  short local_26;
  int local_20;
  
  iVar2 = (int)Raziel.constrictIndex;
  iVar4 = 0;
  local_28 = (instance->position).x;
  iVar6 = 0;
  local_26 = (instance->position).y;
  iVar5 = 0;
  do {
    iVar1 = iVar2 + 1;
    iVar3 = iVar2;
    if (0x1f < iVar2) {
      iVar3 = 0;
      iVar1 = 1;
    }
    if (0x1f < iVar1) {
      iVar1 = 0;
    }
    setCopReg(2,0x6000,Raziel.constrictCenter._0_4_);
    setCopReg(2,0x7000,Raziel.constrictData[iVar1]);
    setCopReg(2,0x6800,Raziel.constrictData[iVar3]);
    copFunction(2,0x1400006);
    local_20 = getCopReg(2,0x18);
    if (local_20 < 1) {
      iVar4 = iVar4 + -1;
    }
    else {
      iVar4 = iVar4 + 1;
    }
    iVar2 = iVar3 + 1;
    iVar5 = iVar5 + 1;
    iVar3 = COLLIDE_PointInTriangle2DPub
                      ((short *)&Raziel.constrictCenter,(short *)(Raziel.constrictData + iVar3),
                       (short *)(Raziel.constrictData + iVar1),&local_28);
    iVar6 = iVar6 + iVar3;
  } while (iVar5 < 0x20);
  iVar2 = 0;
  if (iVar6 != 0) {
    iVar2 = iVar4;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razRotateUpperBody(struct _Instance *instance /*$s3*/, struct evActionLookAroundData *data /*$a1*/)
 // line 247, offset 0x800a1b70
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x800A1B70
		// Variables:
	// 		int tx; // $s0
	// 		int tz; // $s2
	// 		struct _G2SVector3_Type Rot; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A1BF8
	// End Line: 268

	/* begin block 2 */
		// Start line: 555
	/* end block 2 */
	// End Line: 556

void razRotateUpperBody(_Instance *instance,evActionLookAroundData *data)

{
  short sVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  _G2Anim_Type *anim;
  _Rotation local_20;
  
  sVar1 = *data->rotx;
  sVar3 = data->minx;
  if ((sVar1 < data->minx) || (sVar3 = data->maxx, data->maxx < sVar1)) {
    *data->rotx = sVar3;
  }
  sVar1 = *data->rotz;
  sVar3 = data->minz;
  if ((sVar1 < data->minz) || (sVar3 = data->maxz, data->maxz < sVar1)) {
    *data->rotz = sVar3;
  }
  sVar1 = *data->rotx;
  local_20.y = 0;
  iVar2 = -(int)sVar1;
  iVar4 = (uint)(ushort)*data->rotz << 0x10;
  iVar5 = iVar4 >> 0x10;
  local_20.x = (short)(iVar2 / 2);
  local_20.z = (short)(iVar5 - (iVar4 >> 0x1f) >> 1);
  MATH3D_ZYXtoXYZ(&local_20);
  anim = &instance->anim;
  G2Anim_SetController_Vector(anim,0xe,0xe,(_G2SVector3_Type *)&local_20);
  local_20.y = 0;
  local_20.x = (short)(((int)sVar1 * -0x1e) / 100);
  local_20.z = (short)((iVar5 * 0x1e) / 100);
  MATH3D_ZYXtoXYZ(&local_20);
  G2Anim_SetController_Vector(anim,0x10,0xe,(_G2SVector3_Type *)&local_20);
  local_20.y = 0;
  local_20.x = (short)(iVar2 / 5);
  local_20.z = (short)(iVar5 / 5);
  MATH3D_ZYXtoXYZ(&local_20);
  G2Anim_SetController_Vector(anim,0x11,0xe,(_G2SVector3_Type *)&local_20);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetFadeEffect(short source /*$a0*/, short dest /*$a1*/, int steps /*$a2*/)
 // line 285, offset 0x800a1d40
	/* begin block 1 */
		// Start line: 640
	/* end block 1 */
	// End Line: 641

	/* begin block 2 */
		// Start line: 643
	/* end block 2 */
	// End Line: 644

void razSetFadeEffect(short source,short dest,int steps)

{
  Raziel.padCommands.Queue[0].ID = Raziel.padCommands.Queue[0].ID | 3;
  Raziel.padCommands.Queue[0].Data._0_2_ = source;
  Raziel.padCommands.Queue[0].Data._2_2_ = dest;
  Raziel.padCommands.Queue[1].ID = steps;
  Raziel.padCommands.Queue[1].Data = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razPlaneShift(struct _Instance *instance /*$a0*/)
 // line 301, offset 0x800a1d64
	/* begin block 1 */
		// Start line: 670
	/* end block 1 */
	// End Line: 671

	/* begin block 2 */
		// Start line: 677
	/* end block 2 */
	// End Line: 678

int razPlaneShift(_Instance *instance)

{
  int iVar1;
  
  if ((gameTrackerX.streamFlags & 0x40000U) == 0) {
    if (Raziel.CurrentPlane == 1) {
      razSpectralShift();
      iVar1 = 1;
    }
    else {
      razMaterialShift();
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSpectralShift()
 // line 319, offset 0x800a1dc0
	/* begin block 1 */
		// Start line: 320
		// Start offset: 0x800A1DC0
		// Variables:
	// 		struct _Instance *inst; // $v0
	/* end block 1 */
	// End offset: 0x800A1EA4
	// End Line: 347

	/* begin block 2 */
		// Start line: 713
	/* end block 2 */
	// End Line: 714

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razSpectralShift(void)

{
  _Instance *Inst;
  int iVar1;
  
  if (((gameTrackerX.streamFlags & 0x40000U) == 0) && (Raziel.CurrentPlane == 1)) {
    Inst = razGetHeldItem();
    if (Inst != (_Instance *)0x0) {
      INSTANCE_Post(Inst,0x800008,0);
    }
    (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 | 0x8000000;
    INSTANCE_Post(gameTrackerX.playerInstance,0x100014,0);
    iVar1 = GetMaxHealth();
    if (Raziel.HitPoints == iVar1) {
      Raziel.HitPoints = 100000;
    }
    else {
      Raziel.HitPoints = 0x14586;
    }
    Raziel.CurrentPlane = 2;
    razReaverOn();
    if ((gameTrackerX.gameData.asmData.MorphType == 0) &&
       (MORPH_ToggleMorph(), Raziel.State.SectionList[0].Process != StateHandlerGlyphs)) {
      INSTANCE_Post(gameTrackerX.playerInstance,0x40005,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razMaterialShift()
 // line 350, offset 0x800a1eb4
	/* begin block 1 */
		// Start line: 777
	/* end block 1 */
	// End Line: 778

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razMaterialShift(void)

{
  if ((Raziel.CurrentPlane == 2) && (Raziel.HitPoints == 100000)) {
    Raziel.CurrentPlane = 1;
    (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 & 0xf7ffffff;
    Raziel.HitPoints = GetMaxHealth();
    Raziel.DamageFrequency = 0;
    razReaverOn();
    if ((gameTrackerX.gameData.asmData.MorphType != 0) &&
       (MORPH_ToggleMorph(), Raziel.State.SectionList[0].Process != StateHandlerGlyphs)) {
      INSTANCE_Post(gameTrackerX.playerInstance,0x40005,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ RAZIEL_OkToShift()
 // line 369, offset 0x800a1f58
	/* begin block 1 */
		// Start line: 816
	/* end block 1 */
	// End Line: 817

/* WARNING: Unknown calling convention yet parameter storage is locked */

int RAZIEL_OkToShift(void)

{
  int iVar1;
  uint uVar2;
  
  if (Raziel.CurrentPlane == 2) {
    iVar1 = GetMaxHealth();
    uVar2 = 0;
    if (Raziel.HitPoints == iVar1) {
      if ((Raziel.Abilities & 0x40U) == 0) {
        uVar2 = (uint)((Raziel.Senses.Flags & 0x40U) != 0);
      }
      else {
        uVar2 = 1;
        if ((Raziel.Abilities & 0x10U) == 0) {
          FONT_Print("\nYOU CAN NOT HAVE SHIFT ANYTIME WITHOUT THE SWIM ABILITY");
          FONT_Print("\nBEAT THE ALUKA BOSS THEN WIN THE SECOND KAIN ENCOUNTER");
          uVar2 = 0;
        }
      }
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razPickupAndGrab(struct __CharacterState *In /*$s3*/, int CurrentSection /*$s1*/)
 // line 395, offset 0x800a1fec
	/* begin block 1 */
		// Start line: 396
		// Start offset: 0x800A1FEC

		/* begin block 1.1 */
			// Start line: 399
			// Start offset: 0x800A204C
		/* end block 1.1 */
		// End offset: 0x800A2188
		// End Line: 427
	/* end block 1 */
	// End offset: 0x800A218C
	// End Line: 431

	/* begin block 2 */
		// Start line: 868
	/* end block 2 */
	// End Line: 869

	/* begin block 3 */
		// Start line: 870
	/* end block 3 */
	// End Line: 871

int razPickupAndGrab(__CharacterState *In,int CurrentSection)

{
  _Instance *Inst;
  int Data;
  ulong uVar1;
  
  if ((Raziel.Senses.EngagedMask & 0x20) == 0) {
    Data = 1;
  }
  else {
    Inst = razGetHeldItem();
    Data = 1;
    if ((((Inst == (_Instance *)0x0) && (Raziel.CurrentPlane == 1)) &&
        (Data = 1, (Raziel.Mode & 0x800U) == 0)) && (Data = 0, CurrentSection != 0)) {
      Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
      if (Inst != (_Instance *)0x0) {
        INSTANCE_Query(Inst,0);
      }
      (&In->CharacterInstance + CurrentSection * 0x47)[0x47] = (_Instance *)0x0;
      uVar1 = INSTANCE_Query(Raziel.Senses.EngagedList[5].instance,4);
      G2EmulationSwitchAnimation(In,CurrentSection,(uint)""[uVar1],0,3,1);
      Raziel._1140_4_ = (&In->CharacterInstance + CurrentSection * 0x47)[2];
      StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,0);
      Data = 0;
      if (CurrentSection == 1) {
        Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
        if (Inst != (_Instance *)0x0) {
          INSTANCE_Post(Inst,(int)&DAT_0100001b,0);
          INSTANCE_UnlinkFromParent(Raziel.Senses.EngagedList[5].instance);
        }
        Data = SetObjectData(0,0,8,In->CharacterInstance,0x31);
        INSTANCE_Post(Raziel.Senses.EngagedList[5].instance,0x800002,Data);
        razReaverOff();
        Data = 0;
      }
    }
  }
  return Data;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razZeroAxis(long *x /*$s1*/, long *y /*$s2*/, int radius /*$s0*/)
 // line 438, offset 0x800a21a8
	/* begin block 1 */
		// Start line: 439
		// Start offset: 0x800A21A8
		// Variables:
	// 		unsigned long distance; // $v0
	/* end block 1 */
	// End offset: 0x800A21F0
	// End Line: 471

	/* begin block 2 */
		// Start line: 957
	/* end block 2 */
	// End Line: 958

int razZeroAxis(long *x,long *y,int radius)

{
  ulong uVar1;
  
  uVar1 = MATH3D_SquareLength(*x,*y,0);
  if (uVar1 < (uint)radius) {
    uVar1 = 0;
    *x = 0;
    *y = 0;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razAdjustSpeed(struct _Instance *instance /*$a3*/, int minSpeed /*$a1*/)
 // line 475, offset 0x800a2208
	/* begin block 1 */
		// Start line: 476
		// Start offset: 0x800A2208
		// Variables:
	// 		long adjustment; // $s0

		/* begin block 1.1 */
			// Start line: 476
			// Start offset: 0x800A2208
			// Variables:
		// 		int data; // $v1
		/* end block 1.1 */
		// End offset: 0x800A2284
		// End Line: 497
	/* end block 1 */
	// End offset: 0x800A2284
	// End Line: 504

	/* begin block 2 */
		// Start line: 1033
	/* end block 2 */
	// End Line: 1034

int razAdjustSpeed(_Instance *instance,int minSpeed)

{
  int iVar1;
  long adjustment;
  
  iVar1 = (int)Raziel.movementMaxAnalog;
  if (iVar1 < Raziel.Magnitude) {
    adjustment = (long)Raziel.movementMaxRate;
  }
  else {
    if (Raziel.Magnitude < Raziel.movementMinAnalog) {
      adjustment = (long)Raziel.movementMinRate;
    }
    else {
      adjustment = (int)Raziel.movementMaxRate -
                   (((int)Raziel.movementMaxRate - (int)Raziel.movementMinRate) *
                   (iVar1 - Raziel.Magnitude)) / (iVar1 - Raziel.movementMinAnalog);
    }
  }
  G2Anim_SetSpeedAdjustment(&instance->anim,adjustment);
  return adjustment;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razLaunchForce(struct _Instance *instance /*$s0*/)
 // line 525, offset 0x800a22a4
	/* begin block 1 */
		// Start line: 526
		// Start offset: 0x800A22A4
	/* end block 1 */
	// End offset: 0x800A22A4
	// End Line: 526

	/* begin block 2 */
		// Start line: 1141
	/* end block 2 */
	// End Line: 1142

void razLaunchForce(_Instance *instance)

{
  PHYSOB_BirthProjectile(instance,0x31,(uint)Raziel.Abilities._1_1_ & 1);
  Raziel.padCommands.Queue[9].ID =
       SOUND_Play3dSound(&instance->position,0xe,
                         (int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x38),
                         (int)*(short *)(Raziel.padCommands.Queue[13].ID + 0x3e),10000);
  Raziel.padCommands.Queue[9].Data = 0;
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ razGetHeldItem()
 // line 542, offset 0x800a22fc
	/* begin block 1 */
		// Start line: 544
		// Start offset: 0x800A22FC
		// Variables:
	// 		struct _Instance *instance; // $v0
	/* end block 1 */
	// End offset: 0x800A232C
	// End Line: 566

	/* begin block 2 */
		// Start line: 1184
	/* end block 2 */
	// End Line: 1185

	/* begin block 3 */
		// Start line: 1185
	/* end block 3 */
	// End Line: 1186

	/* begin block 4 */
		// Start line: 1187
	/* end block 4 */
	// End Line: 1188

/* WARNING: Unknown calling convention yet parameter storage is locked */

_Instance * razGetHeldItem(void)

{
  _Instance *p_Var1;
  
  p_Var1 = (Raziel.State.CharacterInstance)->LinkChild;
  if (((Raziel.soulReaver != (_Instance *)0x0) && (p_Var1 == Raziel.soulReaver)) &&
     (p_Var1 != (_Instance *)0x0)) {
    return p_Var1->LinkSibling;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ razGetHeldWeapon()
 // line 570, offset 0x800a2334
	/* begin block 1 */
		// Start line: 571
		// Start offset: 0x800A2334
		// Variables:
	// 		struct _Instance *instance; // $v0
	/* end block 1 */
	// End offset: 0x800A2360
	// End Line: 585

	/* begin block 2 */
		// Start line: 1242
	/* end block 2 */
	// End Line: 1243

/* WARNING: Unknown calling convention yet parameter storage is locked */

_Instance * razGetHeldWeapon(void)

{
  _Instance *p_Var1;
  
  p_Var1 = razGetHeldItem();
  if ((p_Var1 == (_Instance *)0x0) && (p_Var1 = (_Instance *)0x0, Raziel.Senses.heldClass != 0)) {
    p_Var1 = Raziel.soulReaver;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razReaverOff()
 // line 589, offset 0x800a2370
	/* begin block 1 */
		// Start line: 590
		// Start offset: 0x800A2370

		/* begin block 1.1 */
			// Start line: 593
			// Start offset: 0x800A2394
			// Variables:
		// 		struct _Instance *heldWeapon; // $s0
		/* end block 1.1 */
		// End offset: 0x800A23D0
		// End Line: 600
	/* end block 1 */
	// End offset: 0x800A23D4
	// End Line: 602

	/* begin block 2 */
		// Start line: 1280
	/* end block 2 */
	// End Line: 1281

	/* begin block 3 */
		// Start line: 1282
	/* end block 3 */
	// End Line: 1283

/* WARNING: Unknown calling convention yet parameter storage is locked */

int razReaverOff(void)

{
  int iVar1;
  _Instance *p_Var2;
  
  if (Raziel.soulReaver == (_Instance *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    if (Raziel.Senses.heldClass == 0x1000) {
      p_Var2 = razGetHeldWeapon();
      INSTANCE_Post(Raziel.soulReaver,0x800101,0);
      iVar1 = 1;
      if (p_Var2 == Raziel.soulReaver) {
        Raziel.Senses.heldClass = 0;
      }
    }
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razReaverOn()
 // line 605, offset 0x800a23e4
	/* begin block 1 */
		// Start line: 1316
	/* end block 1 */
	// End Line: 1317

	/* begin block 2 */
		// Start line: 1318
	/* end block 2 */
	// End Line: 1319

/* WARNING: Unknown calling convention yet parameter storage is locked */

int razReaverOn(void)

{
  _Instance *p_Var1;
  int iVar2;
  
  if (Raziel.soulReaver == (_Instance *)0x0) {
    iVar2 = 0;
  }
  else {
    p_Var1 = razGetHeldItem();
    iVar2 = 0;
    if ((p_Var1 == (_Instance *)0x0) &&
       ((iVar2 = GetMaxHealth(), Raziel.HitPoints == iVar2 || (iVar2 = 0, Raziel.CurrentPlane == 2))
       )) {
      INSTANCE_Post(Raziel.soulReaver,0x800100,0);
      Raziel.Senses.heldClass = 0x1000;
      iVar2 = 1;
      if ((Raziel.CurrentPlane == 2) && (Raziel.currentSoulReaver != 1)) {
        razReaverImbue(1);
        iVar2 = 1;
      }
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverPickup(struct _Instance *instance /*$a2*/, struct _Instance *soulReaver /*$s0*/)
 // line 621, offset 0x800a248c
	/* begin block 1 */
		// Start line: 1351
	/* end block 1 */
	// End Line: 1352

void razReaverPickup(_Instance *instance,_Instance *soulReaver)

{
  _Instance *p_Var1;
  int Data;
  
  INSTANCE_Post(soulReaver,0x800002,(int)instance);
  Raziel.soulReaver = soulReaver;
  p_Var1 = razGetHeldItem();
  if (p_Var1 != (_Instance *)0x0) {
    razReaverOff();
  }
  if (Raziel.CurrentPlane == 1) {
    Data = 2;
    Raziel.currentSoulReaver = 2;
    debugRazielFlags2 = 0x800;
  }
  else {
    Data = 1;
    debugRazielFlags2 = 0x400;
    Raziel.currentSoulReaver = 1;
  }
  debugRazielFlags1 = Raziel.Abilities | 0xc08;
  Raziel.Abilities = debugRazielFlags1;
  INSTANCE_Post(soulReaver,0x800103,Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverImbue(int reaverType /*$a2*/)
 // line 649, offset 0x800a2548
	/* begin block 1 */
		// Start line: 1419
	/* end block 1 */
	// End Line: 1420

void razReaverImbue(int reaverType)

{
  debugRazielFlags2 = 1 << (reaverType + 9U & 0x1f);
  Raziel.currentSoulReaver = reaverType;
  INSTANCE_Post(Raziel.soulReaver,0x800103,reaverType);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razGetReaverFromMask(int reaverMask /*$a0*/)
 // line 658, offset 0x800a2588
	/* begin block 1 */
		// Start line: 660
		// Start offset: 0x800A2588
		// Variables:
	// 		int rc; // $v0
	/* end block 1 */
	// End offset: 0x800A25A4
	// End Line: 669

	/* begin block 2 */
		// Start line: 1442
	/* end block 2 */
	// End Line: 1443

	/* begin block 3 */
		// Start line: 1443
	/* end block 3 */
	// End Line: 1444

	/* begin block 4 */
		// Start line: 1445
	/* end block 4 */
	// End Line: 1446

int razGetReaverFromMask(int reaverMask)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)reaverMask >> 10 & 0xff;
  iVar1 = 0;
  while (uVar2 != 0) {
    uVar2 = (int)uVar2 >> 1;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverScale(int scale /*$s0*/)
 // line 672, offset 0x800a25ac
	/* begin block 1 */
		// Start line: 673
		// Start offset: 0x800A25AC
		// Variables:
	// 		struct _Instance *Inst; // $v0
	/* end block 1 */
	// End offset: 0x800A25E8
	// End Line: 683

	/* begin block 2 */
		// Start line: 1470
	/* end block 2 */
	// End Line: 1471

void razReaverScale(int scale)

{
  _Instance *Inst;
  
  Inst = razGetHeldWeapon();
  if ((Raziel.soulReaver != (_Instance *)0x0) && (Inst == Raziel.soulReaver)) {
    INSTANCE_Post(Inst,0x800107,scale);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razGetForwardNormal(struct _Instance *inst /*$a0*/, struct _Instance *target /*$a1*/)
 // line 686, offset 0x800a25f8
	/* begin block 1 */
		// Start line: 687
		// Start offset: 0x800A25F8
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -72
	// 		struct SVECTOR Old; // stack offset -24
	// 		struct SVECTOR New; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A26CC
	// End Line: 715

	/* begin block 2 */
		// Start line: 1498
	/* end block 2 */
	// End Line: 1499

void razGetForwardNormal(_Instance *inst,_Instance *target)

{
  _PCollideInfo local_48;
  SVECTOR local_18;
  SVECTOR local_10;
  
  local_48.oldPoint = &local_18;
  local_48.newPoint = &local_10;
  local_18.vx = *(short *)inst->matrix[1].t;
  local_18.vy = *(short *)(inst->matrix[1].t + 1);
  local_18.vz = *(short *)(inst->matrix[1].t + 2);
  local_10.vx = *(short *)target->matrix[1].t;
  local_10.vy = *(short *)(target->matrix[1].t + 1);
  local_10.vz = *(short *)(target->matrix[1].t + 2);
  PHYSICS_CheckLineInWorld(inst,&local_48);
  if (((uint)local_48.type - 2 < 2) || (local_48.type == 5)) {
    Raziel.Senses.ForwardNormal.x = local_48.wNormal.vx;
    Raziel.Senses.ForwardNormal.y = local_48.wNormal.vy;
    Raziel.Senses.ForwardNormal.z = local_48.wNormal.vz;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razGetRotFromNormal(struct _SVector *normal /*$a0*/, struct _Rotation *rot /*$a2*/)
 // line 718, offset 0x800a26dc
	/* begin block 1 */
		// Start line: 719
		// Start offset: 0x800A26DC
		// Variables:
	// 		struct _Position a; // stack offset -24
	// 		struct _Position b; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A26DC
	// End Line: 719

	/* begin block 2 */
		// Start line: 1571
	/* end block 2 */
	// End Line: 1572

void razGetRotFromNormal(_SVector *normal,_Rotation *rot)

{
  _Position local_18;
  _Position local_10;
  
  local_18.x = normal->x;
  local_18.y = normal->y;
  local_18.z = normal->z;
  local_10.z = 0;
  local_10.y = 0;
  local_10.x = 0;
  MATH3D_RotationFromPosToPos(&local_18,&local_10,rot);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPauseTranslation(struct _Instance *instance /*$a0*/)
 // line 734, offset 0x800a2728
	/* begin block 1 */
		// Start line: 735
		// Start offset: 0x800A2728
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A277C
	// End Line: 747

	/* begin block 2 */
		// Start line: 1615
	/* end block 2 */
	// End Line: 1616

void razSetPauseTranslation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  _G2SVector3_Type local_10;
  
  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim,0,0x22);
  if (_Var1 == G2FALSE) {
    G2Anim_EnableController(anim,0,0x22);
    local_10.x = 0;
    local_10.y = 0;
    local_10.z = 0;
    G2Anim_SetController_Vector(anim,0,0x22,&local_10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razResetPauseTranslation(struct _Instance *instance /*$a0*/)
 // line 750, offset 0x800a278c
	/* begin block 1 */
		// Start line: 1653
	/* end block 1 */
	// End Line: 1654

void razResetPauseTranslation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  
  _Var1 = G2Anim_IsControllerActive(&instance->anim,0,0x22);
  if (_Var1 != G2FALSE) {
    G2Anim_DisableController(&instance->anim,0,0x22);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSelectMotionAnim(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Frames /*$s4*/, int *Anim /*$s3*/)
 // line 760, offset 0x800a27d0
	/* begin block 1 */
		// Start line: 761
		// Start offset: 0x800A27D0
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -32
	// 		int switchType; // $a0
	// 		int frame; // $s0

		/* begin block 1.1 */
			// Start line: 986
			// Start offset: 0x800A2CDC
			// Variables:
		// 		int adjustment; // $s0
		/* end block 1.1 */
		// End offset: 0x800A2DC8
		// End Line: 1007
	/* end block 1 */
	// End offset: 0x800A2DC8
	// End Line: 1012

	/* begin block 2 */
		// Start line: 1675
	/* end block 2 */
	// End Line: 1676

void razSelectMotionAnim(__CharacterState *In,int CurrentSection,int Frames,int *Anim)

{
  short sVar1;
  uint uVar2;
  _G2Bool_Enum _Var3;
  int iVar4;
  bool bVar5;
  int frame;
  _G2SVector3_Type local_20;
  
  bVar5 = false;
  frame = 0;
  if (Raziel.Magnitude < 0xeeb) {
    if (Raziel.Magnitude - 0xba7U < 0x344) {
      iVar4 = *Anim;
      if (iVar4 == 0x3c) {
        if ((Raziel.throwReturnRot & 0xfU) != 0) {
          bVar5 = true;
        }
        if ((Raziel.throwReturnRot & 8U) != 0) {
          frame = 7;
        }
        if ((Raziel.throwReturnRot & 1U) != 0) {
          frame = 0xd;
        }
        uVar2 = Raziel.throwReturnRot & 4;
        if ((Raziel.throwReturnRot & 2U) != 0) {
          frame = 0x14;
        }
      }
      else {
        if (iVar4 != 0x44) {
          if (iVar4 != 0x40) {
            bVar5 = true;
          }
          goto LAB_800a2a48;
        }
        if ((Raziel.throwReturnRot & 0xf00U) != 0) {
          bVar5 = true;
        }
        if ((Raziel.throwReturnRot & 0x800U) != 0) {
          frame = 7;
        }
        if ((Raziel.throwReturnRot & 0x100U) != 0) {
          frame = 0xd;
        }
        uVar2 = Raziel.throwReturnRot & 0x400;
        if ((Raziel.throwReturnRot & 0x200U) != 0) {
          frame = 0x14;
        }
      }
      if (uVar2 != 0) {
        frame = 0x19;
      }
    }
    else {
      if (Raziel.Magnitude < 0xba7) {
        iVar4 = *Anim;
        if (iVar4 == 0x40) {
          bVar5 = (Raziel.throwReturnRot & 0xf0U) != 0;
          if ((Raziel.throwReturnRot & 0x80U) != 0) {
            frame = 0xc;
          }
          if ((Raziel.throwReturnRot & 0x10U) != 0) {
            frame = 0x14;
          }
          uVar2 = Raziel.throwReturnRot & 0x40;
          if ((Raziel.throwReturnRot & 0x20U) != 0) {
            frame = 0x20;
          }
        }
        else {
          if (iVar4 != 0x44) {
            if (iVar4 != 0x3c) {
              bVar5 = true;
            }
            goto LAB_800a2a48;
          }
          bVar5 = (Raziel.throwReturnRot & 0xf00U) != 0;
          if ((Raziel.throwReturnRot & 0x800U) != 0) {
            frame = 0xc;
          }
          if ((Raziel.throwReturnRot & 0x100U) != 0) {
            frame = 0x14;
          }
          uVar2 = Raziel.throwReturnRot & 0x400;
          if ((Raziel.throwReturnRot & 0x200U) != 0) {
            frame = 0x20;
          }
        }
        if (uVar2 != 0) {
          frame = 0;
        }
      }
    }
  }
  else {
    iVar4 = *Anim;
    if (iVar4 == 0x3c) {
      if ((Raziel.throwReturnRot & 0xfU) != 0) {
        bVar5 = true;
      }
      if ((Raziel.throwReturnRot & 8U) != 0) {
        frame = 5;
      }
      if ((Raziel.throwReturnRot & 1U) != 0) {
        frame = 0x17;
      }
      uVar2 = Raziel.throwReturnRot & 4;
      if ((Raziel.throwReturnRot & 2U) != 0) {
        frame = 0x11;
      }
    }
    else {
      if (iVar4 != 0x40) {
        if (iVar4 != 0x44) {
          bVar5 = true;
        }
        goto LAB_800a2a48;
      }
      if ((Raziel.throwReturnRot & 0xf0U) != 0) {
        bVar5 = true;
      }
      if ((Raziel.throwReturnRot & 0x80U) != 0) {
        frame = 5;
      }
      if ((Raziel.throwReturnRot & 0x10U) != 0) {
        frame = 0x17;
      }
      uVar2 = Raziel.throwReturnRot & 0x40;
      if ((Raziel.throwReturnRot & 0x20U) != 0) {
        frame = 0x11;
      }
    }
    if (uVar2 != 0) {
      frame = 0xb;
    }
  }
LAB_800a2a48:
  if (bVar5 == true) {
    if (CurrentSection == 2) {
      Raziel.throwReturnRot = 0;
    }
    if (CurrentSection == 0) {
      _Var3 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,0,0x22);
      if (_Var3 == G2FALSE) {
        G2Anim_EnableController(&In->CharacterInstance->anim,0,0x22);
      }
      local_20.y = -0x23;
      G2Anim_SetController_Vector(&In->CharacterInstance->anim,0,0x22,&local_20);
    }
    iVar4 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x40,frame,Frames);
    if (iVar4 != 0) {
      G2EmulationSwitchAnimation(In,CurrentSection,0x7d,frame,Frames,2);
    }
    Raziel.movementMinRate = 0xccc;
    Raziel.movementMaxRate = 0x1800;
    Raziel.movementMinAnalog = 0xba6;
    Raziel.movementMaxAnalog = 0xeea;
    frame = 0x40;
LAB_800a2cd0:
    *Anim = frame;
  }
  else {
    if (bVar5 < 3) {
      if (bVar5 == true) {
        if (CurrentSection == 2) {
          Raziel.throwReturnRot = 0;
        }
        if (CurrentSection == 0) {
          _Var3 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,0,0x22);
          if (_Var3 == G2FALSE) {
            G2Anim_EnableController(&In->CharacterInstance->anim,0,0x22);
          }
          local_20.z = 0;
          local_20.x = 0;
          local_20.y = -0x10;
          G2Anim_SetController_Vector(&In->CharacterInstance->anim,0,0x22,&local_20);
        }
        iVar4 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x3c,frame,Frames);
        if (iVar4 != 0) {
          G2EmulationSwitchAnimation(In,CurrentSection,0x7c,frame,Frames,2);
        }
        Raziel.movementMinRate = 0x800;
        Raziel.movementMaxRate = 0x1c00;
        Raziel.movementMinAnalog = 0x8fc;
        Raziel.movementMaxAnalog = 0xba6;
        frame = 0x3c;
        goto LAB_800a2cd0;
      }
    }
    else {
      if (bVar5 == true) {
        if (CurrentSection == 2) {
          Raziel.throwReturnRot = 0;
        }
        if (CurrentSection == 0) {
          _Var3 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,0,0x22);
          if (_Var3 == G2FALSE) {
            G2Anim_EnableController(&In->CharacterInstance->anim,0,0x22);
          }
          local_20.z = 0;
          local_20.x = 0;
          local_20.y = -0x3c;
          G2Anim_SetController_Vector(&In->CharacterInstance->anim,0,0x22,&local_20);
        }
        iVar4 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x44,frame,Frames);
        if (iVar4 != 0) {
          G2EmulationSwitchAnimation(In,CurrentSection,2,frame,Frames,2);
        }
        Raziel.movementMinRate = 0xddb;
        Raziel.movementMinAnalog = 0xeea;
        frame = 0x44;
        Raziel.movementMaxRate = 0x1000;
        Raziel.movementMaxAnalog = 0x1000;
        goto LAB_800a2cd0;
      }
    }
  }
  if (CurrentSection != 0) {
    return;
  }
  local_20.z = 0;
  local_20.x = 0;
  frame = *Anim;
  if (frame == 0x40) {
    sVar1 = -0x23;
  }
  else {
    if (frame < 0x41) {
      sVar1 = -0x10;
      if (frame != 0x3c) goto LAB_800a2d28;
    }
    else {
      sVar1 = -0x3c;
      if (frame != 0x44) goto LAB_800a2d28;
    }
  }
  local_20.y = sVar1;
LAB_800a2d28:
  frame = razAdjustSpeed(In->CharacterInstance,1);
  sVar1 = G2Timer_GetFrameTime();
  local_20.y = (short)(((int)local_20.y * (int)sVar1 * frame >> 0xc) / 100);
  _Var3 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,0,0x22);
  if (_Var3 == G2FALSE) {
    G2Anim_EnableController(&In->CharacterInstance->anim,0,0x22);
  }
  G2Anim_SetController_Vector(&In->CharacterInstance->anim,0,0x22,&local_20);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razApplyMotion(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/)
 // line 1016, offset 0x800a2de8
	/* begin block 1 */
		// Start line: 1017
		// Start offset: 0x800A2DE8
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1022
			// Start offset: 0x800A2E18
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $s0

			/* begin block 1.1.1 */
				// Start line: 1062
				// Start offset: 0x800A2EC0
				// Variables:
			// 		long adjustment; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800A2F5C
			// End Line: 1072
		/* end block 1.1 */
		// End offset: 0x800A2F5C
		// End Line: 1073
	/* end block 1 */
	// End offset: 0x800A2F5C
	// End Line: 1075

	/* begin block 2 */
		// Start line: 2214
	/* end block 2 */
	// End Line: 2215

int razApplyMotion(__CharacterState *In,int CurrentSection)

{
  short sVar1;
  _G2AnimKeylist_Type *p_Var2;
  int iVar3;
  _G2Bool_Enum _Var4;
  _Instance *instance;
  _G2SVector3_Type _Stack24;
  
  memset(&_Stack24,0,6);
  if (CurrentSection == 0) {
    instance = In->CharacterInstance;
    p_Var2 = G2Instance_GetKeylist(instance,2);
    if ((instance->anim).section[0].keylist == p_Var2) {
      _Stack24.y = -0x3c;
    }
    else {
      p_Var2 = G2Instance_GetKeylist(In->CharacterInstance,0x7d);
      if ((instance->anim).section[0].keylist == p_Var2) {
        _Stack24.y = -0x23;
      }
      else {
        p_Var2 = G2Instance_GetKeylist(In->CharacterInstance,0x7c);
        if ((instance->anim).section[0].keylist == p_Var2) {
          _Stack24.y = -0x10;
        }
        else {
          _Var4 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,0,0x22);
          if (_Var4 != G2FALSE) {
            G2Anim_DisableController(&In->CharacterInstance->anim,0,0x22);
          }
        }
      }
    }
    iVar3 = (int)_Stack24.y;
    if (iVar3 == 0) goto LAB_800a2f60;
    _Var4 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,0,0x22);
    if (_Var4 == G2FALSE) {
      G2Anim_EnableController(&In->CharacterInstance->anim,0,0x22);
    }
    iVar3 = (In->CharacterInstance->anim).section[0].speedAdjustment;
    sVar1 = G2Timer_GetFrameTime();
    _Stack24.y = (short)(((int)_Stack24.y * (int)sVar1 * iVar3 >> 0xc) / 100);
    G2Anim_SetController_Vector(&In->CharacterInstance->anim,0,0x22,&_Stack24);
  }
  iVar3 = (int)_Stack24.y;
LAB_800a2f60:
  return -iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razResetMotion(struct _Instance *instance /*$a0*/)
 // line 1079, offset 0x800a2f78
	/* begin block 1 */
		// Start line: 2343
	/* end block 1 */
	// End Line: 2344

void razResetMotion(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim,0,0x22);
  if (_Var1 != G2FALSE) {
    G2Anim_DisableController(anim,0,0x22);
  }
  Raziel.throwReturnRot = 0;
  G2Anim_SetSpeedAdjustment(anim,0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetDampingPhysics(struct _Instance *instance /*$a0*/)
 // line 1118, offset 0x800a2fcc
	/* begin block 1 */
		// Start line: 2234
	/* end block 1 */
	// End Line: 2235

	/* begin block 2 */
		// Start line: 2393
	/* end block 2 */
	// End Line: 2394

void razSetDampingPhysics(_Instance *instance)

{
  Raziel.RotationSegment = 0;
  Raziel.padCommands.Head._0_2_ = 0;
  PhysicsMode = 4;
  SetDampingPhysics(instance,PlayerData->SwimPhysicsFallDamping);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razEnterWater(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, struct evPhysicsSwimData *SwimData /*$s3*/)
 // line 1128, offset 0x800a3004
	/* begin block 1 */
		// Start line: 1129
		// Start offset: 0x800A3004
		// Variables:
	// 		struct _Instance *Inst; // $s2
	/* end block 1 */
	// End offset: 0x800A32A0
	// End Line: 1228

	/* begin block 2 */
		// Start line: 2414
	/* end block 2 */
	// End Line: 2415

void razEnterWater(__CharacterState *In,int CurrentSection,evPhysicsSwimData *SwimData)

{
  _Instance *Inst;
  ulong uVar1;
  int CurrentSection_00;
  int NewAnim;
  int local_20;
  int local_1c;
  
  Inst = razGetHeldWeapon();
  if ((((CurrentSection == 0) && (In->CharacterInstance->waterFace != (_TFace *)0x0)) &&
      (Raziel.CurrentPlane == 1)) && ((Raziel.Abilities & 0x10U) == 0)) {
    DrainHealth(0xa000);
  }
  if ((SwimData->rc & 0x10U) != 0) {
    if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
      Raziel.HitPoints = 100000;
      SetPhysics(In->CharacterInstance,-0x10,0,0,0);
      PhysicsMode = 0;
    }
    else {
      if ((Inst == (_Instance *)0x0) || (uVar1 = INSTANCE_Query(Inst,4), uVar1 != 3)) {
        if ((Raziel.Mode & 0x40000U) == 0) {
          if (PhysicsMode != 4) {
            razSetDampingPhysics(In->CharacterInstance);
          }
          if (In->CharacterInstance->zVel == 0) {
            StateSwitchStateCharacterData(In,StateHandlerSwim,0);
          }
          TrailWaterFX(In->CharacterInstance,9,1,1);
          TrailWaterFX(In->CharacterInstance,0xd,1,1);
          TrailWaterFX(In->CharacterInstance,0x1f,1,1);
          TrailWaterFX(In->CharacterInstance,0x29,1,1);
        }
      }
      else {
        G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x800);
      }
    }
  }
  if ((SwimData->rc & 0x800U) != 0) {
    if (CurrentSection == 2) {
      NewAnim = 0x3d;
      local_20 = 3;
      CurrentSection_00 = 2;
      local_1c = CurrentSection;
    }
    else {
      NewAnim = 0x3f;
      local_20 = 0x10;
      local_1c = 2;
      CurrentSection_00 = CurrentSection;
    }
    G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,local_20,local_1c);
  }
  if (((SwimData->rc & 0x100U) != 0) && (CurrentSection == 0)) {
    if ((Inst == (_Instance *)0x0) || (uVar1 = INSTANCE_Query(Inst,4), uVar1 != 3)) {
      razSetDampingPhysics(In->CharacterInstance);
    }
    PurgeMessageQueue(&In->SectionList[0].Event);
    TrailWaterFX(In->CharacterInstance,9,4,1);
    TrailWaterFX(In->CharacterInstance,0xd,4,1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetSwimVelocity(struct _Instance *instance /*$a0*/, int vel /*$a1*/, int accl /*$a2*/)
 // line 1255, offset 0x800a32bc
	/* begin block 1 */
		// Start line: 1257
		// Start offset: 0x800A32BC
	/* end block 1 */
	// End offset: 0x800A3308
	// End Line: 1271

	/* begin block 2 */
		// Start line: 2669
	/* end block 2 */
	// End Line: 2670

	/* begin block 3 */
		// Start line: 2670
	/* end block 3 */
	// End Line: 2671

	/* begin block 4 */
		// Start line: 2676
	/* end block 4 */
	// End Line: 2677

void razSetSwimVelocity(_Instance *instance,int vel,int accl)

{
  int iVar1;
  
  iVar1 = vel * (instance->anim).section[0].speedAdjustment;
  instance->yAccl = 0;
  instance->xAccl = 0;
  instance->yVel = 0;
  instance->xVel = 0;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  Raziel.padCommands.Queue[8].Data._2_2_ = (undefined2)(iVar1 >> 0xc);
  if (vel < instance->zVel) {
    instance->zAccl = -accl;
    return;
  }
  instance->zAccl = accl;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetWallCrawlNodes(struct _Instance *instance /*$s1*/, struct evPhysicsWallCrawlData *data /*$s0*/)
 // line 1274, offset 0x800a3310
	/* begin block 1 */
		// Start line: 1275
		// Start offset: 0x800A3310
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1281
			// Start offset: 0x800A3338
		/* end block 1.1 */
		// End offset: 0x800A33BC
		// End Line: 1317
	/* end block 1 */
	// End offset: 0x800A3400
	// End Line: 1328

	/* begin block 2 */
		// Start line: 2709
	/* end block 2 */
	// End Line: 2710

void razSetWallCrawlNodes(_Instance *instance,evPhysicsWallCrawlData *data)

{
  ulong uVar1;
  _G2SVector3_Type local_18;
  
  if ((data->rc & 8U) != 0) {
    uVar1 = MATH3D_SquareLength((int)(data->NewPosition).x,(int)(data->NewPosition).y,
                                (int)(data->NewPosition).z);
    if (100 < (int)uVar1) {
      (instance->position).x = (instance->position).x - (data->NewPosition).x;
      (instance->position).y = (instance->position).y - (data->NewPosition).y;
      (instance->position).z = (instance->position).z - (data->NewPosition).z;
    }
    local_18.x = (data->DropRotation).x;
    local_18.y = (data->DropRotation).y;
    local_18.z = (data->DropRotation).z;
    G2Anim_SetController_Vector(&instance->anim,0,8,&local_18);
  }
  if (data->rc == 10) {
    local_18.y = 0;
    local_18.z = 0;
    local_18.x = -data->ForwardXRotation;
    G2EmulationSetInterpController_Vector(instance,0xe,0xe,&local_18,3,2);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSwitchVAnimCharacterGroup(struct _Instance *instance /*$s3*/, int animGroup /*$s4*/, int *frame /*$a2*/, int *frames /*$a3*/)
 // line 1332, offset 0x800a3414
	/* begin block 1 */
		// Start line: 1333
		// Start offset: 0x800A3414
		// Variables:
	// 		int i; // $s0
	// 		int rc; // $v1
	// 		int temp[3]; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A34B0
	// End Line: 1346

	/* begin block 2 */
		// Start line: 2841
	/* end block 2 */
	// End Line: 2842

int razSwitchVAnimCharacterGroup(_Instance *instance,int animGroup,int *frame,int *frames)

{
  int frame_00;
  int section;
  int iVar1;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = -1;
  local_24 = 0xffffffff;
  local_20 = 0xffffffff;
  if (frame == (int *)0x0) {
    frame = &local_28;
  }
  section = 0;
  if (frames == (int *)0x0) {
    frames = &local_28;
  }
  do {
    iVar1 = section + 1;
    frame_00 = *frame;
    frame = frame + 1;
    frame_00 = razSwitchVAnimGroup(instance,section,animGroup,frame_00,*frames);
    section = iVar1;
    frames = frames + 1;
  } while (iVar1 < 3);
  return frame_00;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSwitchVAnimGroup(struct _Instance *instance /*$a0*/, int section /*$a1*/, int animGroup /*$a2*/, int frame /*$a3*/, int frames /*stack 16*/)
 // line 1351, offset 0x800a34d0
	/* begin block 1 */
		// Start line: 1352
		// Start offset: 0x800A34D0
		// Variables:
	// 		int index; // $t0
	// 		int rc; // $v1
	/* end block 1 */
	// End offset: 0x800A351C
	// End Line: 1372

	/* begin block 2 */
		// Start line: 2885
	/* end block 2 */
	// End Line: 2886

int razSwitchVAnimGroup(_Instance *instance,int section,int animGroup,int frame,int frames)

{
  int iVar1;
  
  iVar1 = 1;
  if (Raziel.Senses.heldClass != 0) {
    iVar1 = Raziel.Senses.heldClass - 1;
    if (2 < iVar1) {
      iVar1 = 3;
    }
    razSwitchVAnim(instance,section,
                   (__VAnim *)
                   (*(int *)(Raziel.padCommands.Queue[13].ID + 0x18) + (animGroup + iVar1) * 8),
                   frame,frames);
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnimCharacterSingle(struct _Instance *instance /*$s3*/, int anim /*$s4*/, int *frame /*$a2*/, int *frames /*$a3*/)
 // line 1377, offset 0x800a352c
	/* begin block 1 */
		// Start line: 1378
		// Start offset: 0x800A352C
		// Variables:
	// 		int i; // $s0
	// 		int temp[3]; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A35C4
	// End Line: 1390

	/* begin block 2 */
		// Start line: 2944
	/* end block 2 */
	// End Line: 2945

void razSwitchVAnimCharacterSingle(_Instance *instance,int anim,int *frame,int *frames)

{
  int frame_00;
  int section;
  int iVar1;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = -1;
  local_24 = 0xffffffff;
  local_20 = 0xffffffff;
  if (frame == (int *)0x0) {
    frame = &local_28;
  }
  section = 0;
  if (frames == (int *)0x0) {
    frames = &local_28;
  }
  do {
    iVar1 = section + 1;
    frame_00 = *frame;
    frame = frame + 1;
    razSwitchVAnimSingle(instance,section,anim,frame_00,*frames);
    section = iVar1;
    frames = frames + 1;
  } while (iVar1 < 3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnimSingle(struct _Instance *instance /*$a0*/, int section /*$a1*/, int anim /*$a2*/, int frame /*$a3*/, int frames /*stack 16*/)
 // line 1393, offset 0x800a35e4
	/* begin block 1 */
		// Start line: 1394
		// Start offset: 0x800A35E4
	/* end block 1 */
	// End offset: 0x800A35E4
	// End Line: 1394

	/* begin block 2 */
		// Start line: 2981
	/* end block 2 */
	// End Line: 2982

void razSwitchVAnimSingle(_Instance *instance,int section,int anim,int frame,int frames)

{
  razSwitchVAnim(instance,section,PlayerData->virtualAnimSingle + anim,frame,frames);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnim(struct _Instance *instance /*$a0*/, int section /*$a1*/, struct __VAnim *vAnim /*$v1*/, int frame /*$a3*/, int frames /*stack 16*/)
 // line 1403, offset 0x800a3618
	/* begin block 1 */
		// Start line: 3004
	/* end block 1 */
	// End Line: 3005

void razSwitchVAnim(_Instance *instance,int section,__VAnim *vAnim,int frame,int frames)

{
  uint local_14;
  uint AlphaTable;
  int CurrentSection;
  uint NewAnim;
  
  if (frame == -1) {
    frame = ZEXT24(vAnim->frame);
  }
  if (frames == -1) {
    frames = ZEXT14(vAnim->frames);
  }
  if (section == 1) {
    NewAnim = (uint)vAnim->anim1;
    local_14 = (uint)vAnim->mode;
    AlphaTable = (uint)vAnim->alpha;
    CurrentSection = 1;
  }
  else {
    if (section < 2) {
      if (section != 0) {
        return;
      }
      NewAnim = (uint)vAnim->anim0;
      local_14 = (uint)vAnim->mode;
      AlphaTable = (uint)vAnim->alpha;
      CurrentSection = 0;
    }
    else {
      CurrentSection = 2;
      if (section != 2) {
        return;
      }
      NewAnim = (uint)vAnim->anim2;
      local_14 = (uint)vAnim->mode;
      AlphaTable = (uint)vAnim->alpha;
    }
  }
  G2EmulationInstanceSwitchAnimationAlpha
            (instance,CurrentSection,NewAnim,frame,frames,local_14,AlphaTable);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razProcessSAnim(struct _Instance *instance /*$s3*/, int mode /*$a1*/)
 // line 1431, offset 0x800a36e4
	/* begin block 1 */
		// Start line: 1432
		// Start offset: 0x800A36E4
		// Variables:
	// 		int rc; // $s2
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 1457
			// Start offset: 0x800A37AC
			// Variables:
		// 		struct __VAnim *vanim; // $s1
		/* end block 1.1 */
		// End offset: 0x800A3814
		// End Line: 1468
	/* end block 1 */
	// End offset: 0x800A3838
	// End Line: 1479

	/* begin block 2 */
		// Start line: 3060
	/* end block 2 */
	// End Line: 3061

int razProcessSAnim(_Instance *instance,int mode)

{
  short sVar1;
  short sVar2;
  __VAnim *p_Var3;
  int section;
  __VAnim *vAnim;
  int iVar4;
  
  iVar4 = 0;
  if (mode == 0x8000000) {
    sVar2 = *(short *)(Raziel.padCommands.Queue[11].Data + 8);
    sVar1 = 1;
  }
  else {
    if (mode < 0x8000001) {
      if (mode != 0x100015) goto LAB_800a378c;
      sVar2 = *(short *)(Raziel.padCommands.Queue[11].Data + 8);
      sVar1 = 2;
    }
    else {
      if (mode != 0x8000003) goto LAB_800a378c;
      sVar2 = *(short *)(Raziel.padCommands.Queue[11].Data + 8);
      sVar1 = 3;
    }
  }
  if (sVar2 == sVar1) {
    iVar4 = 1;
  }
LAB_800a378c:
  if (iVar4 != 0) {
    p_Var3 = *(__VAnim **)(Raziel.padCommands.Queue[11].Data + 4);
    if (p_Var3 == (__VAnim *)0x0) {
      G2Anim_SetSpeedAdjustment(&instance->anim,0x1000);
      Raziel.padCommands.Queue[11].Data = 0;
      iVar4 = 0;
    }
    else {
      vAnim = *(__VAnim **)p_Var3;
      section = 0;
      Raziel.padCommands.Queue[11].Data = (int)p_Var3;
      if (vAnim != (__VAnim *)0x0) {
        do {
          razSwitchVAnim(instance,section,vAnim,-1,-1);
          section = section + 1;
          G2Anim_SetSpeedAdjustment
                    (&instance->anim,(int)*(short *)(Raziel.padCommands.Queue[11].Data + 0xc));
        } while (section < 3);
        if (*(short *)(Raziel.padCommands.Queue[11].Data + 8) == 2) {
          SetTimer((int)*(short *)(Raziel.padCommands.Queue[11].Data + 10));
        }
      }
    }
  }
  return iVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchStringAnimation(struct _Instance *instance /*$s2*/, int anim /*$a1*/)
 // line 1483, offset 0x800a385c
	/* begin block 1 */
		// Start line: 1484
		// Start offset: 0x800A385C
		// Variables:
	// 		struct __VAnim *vanim; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x800A3908
	// End Line: 1500

	/* begin block 2 */
		// Start line: 3172
	/* end block 2 */
	// End Line: 3173

	/* begin block 3 */
		// Start line: 3176
	/* end block 3 */
	// End Line: 3177

void razSwitchStringAnimation(_Instance *instance,int anim)

{
  int section;
  __VAnim *vAnim;
  
  Raziel.padCommands.Queue[11].Data = (int)PlayerData->stringAnimations[anim];
  vAnim = ((__SAnim *)Raziel.padCommands.Queue[11].Data)->anim;
  if (vAnim != (__VAnim *)0x0) {
    section = 0;
    do {
      razSwitchVAnim(instance,section,vAnim,-1,-1);
      section = section + 1;
    } while (section < 3);
    G2Anim_SetSpeedAdjustment
              (&instance->anim,(int)*(short *)(Raziel.padCommands.Queue[11].Data + 0xc));
    if (*(short *)(Raziel.padCommands.Queue[11].Data + 8) == 2) {
      SetTimer((int)*(short *)(Raziel.padCommands.Queue[11].Data + 10));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckStringAnimation(struct _Instance *instance /*$s1*/, int mode /*$a1*/)
 // line 1503, offset 0x800a3924
	/* begin block 1 */
		// Start line: 1504
		// Start offset: 0x800A3924
		// Variables:
	// 		int rc; // $s0
	/* end block 1 */
	// End offset: 0x800A396C
	// End Line: 1514

	/* begin block 2 */
		// Start line: 3222
	/* end block 2 */
	// End Line: 3223

	/* begin block 3 */
		// Start line: 3225
	/* end block 3 */
	// End Line: 3226

int CheckStringAnimation(_Instance *instance,int mode)

{
  int iVar1;
  
  iVar1 = 0;
  if ((Raziel.padCommands.Queue[11].Data == 0) ||
     (iVar1 = razProcessSAnim(instance,mode), Raziel.padCommands.Queue[11].Data == 0)) {
    INSTANCE_Post(instance,0x100000,0);
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razInitCollision(struct _Instance *instance /*$a0*/)
 // line 1536, offset 0x800a3984
	/* begin block 1 */
		// Start line: 1538
		// Start offset: 0x800A3984
		// Variables:
	// 		struct _HModel *hModel; // $v1
	// 		struct _HPrim *hprim; // $v0
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x800A39D4
	// End Line: 1567

	/* begin block 2 */
		// Start line: 3068
	/* end block 2 */
	// End Line: 3069

	/* begin block 3 */
		// Start line: 3271
	/* end block 3 */
	// End Line: 3272

	/* begin block 4 */
		// Start line: 3275
	/* end block 4 */
	// End Line: 3276

void razInitCollision(_Instance *instance)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = instance->hModelList[instance->currentModel].numHPrims;
  if (iVar2 != 0) {
    pbVar1 = &(instance->hModelList[instance->currentModel].hPrimList)->withFlags;
    do {
      if (pbVar1[2] != 1) {
        *pbVar1 = *pbVar1 & 0xa5;
      }
      iVar2 = iVar2 + -1;
      pbVar1 = pbVar1 + 8;
    } while (iVar2 != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razLaunchBubbles(int segments /*$s2*/, int count /*$s0*/, int type /*$s1*/)
 // line 1568, offset 0x800a39dc
	/* begin block 1 */
		// Start line: 3340
	/* end block 1 */
	// End Line: 3341

void razLaunchBubbles(int segments,int count,int type)

{
  if ((segments & 1U) != 0) {
    TrailWaterFX(gameTrackerX.playerInstance,0x20,count,type);
    TrailWaterFX(gameTrackerX.playerInstance,0x2a,count,type);
  }
  if ((segments & 2U) != 0) {
    TrailWaterFX(gameTrackerX.playerInstance,8,count,type);
    TrailWaterFX(gameTrackerX.playerInstance,0xc,count,type);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetCowlNoDraw(int mode /*$t0*/)
 // line 1581, offset 0x800a3a74
	/* begin block 1 */
		// Start line: 1582
		// Start offset: 0x800A3A74
	/* end block 1 */
	// End offset: 0x800A3B24
	// End Line: 1591

	/* begin block 2 */
		// Start line: 3366
	/* end block 2 */
	// End Line: 3367

void razSetCowlNoDraw(int mode)

{
  byte bVar1;
  _MFace *p_Var2;
  ushort *puVar3;
  
  puVar3 = &cowlList;
  do {
    if (mode == 0) {
      p_Var2 = (gameTrackerX.playerInstance)->object->modelList
               [(gameTrackerX.playerInstance)->currentModel]->faceList + *puVar3;
      bVar1 = p_Var2->flags & 0xef;
    }
    else {
      p_Var2 = (gameTrackerX.playerInstance)->object->modelList
               [(gameTrackerX.playerInstance)->currentModel]->faceList + *puVar3;
      bVar1 = p_Var2->flags | 0x10;
    }
    p_Var2->flags = bVar1;
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < -0x7ff2f976);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAttachControllers()
 // line 1593, offset 0x800a3b2c
	/* begin block 1 */
		// Start line: 1594
		// Start offset: 0x800A3B2C
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x800A3B84
	// End Line: 1601

	/* begin block 2 */
		// Start line: 3394
	/* end block 2 */
	// End Line: 3395

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razAttachControllers(void)

{
  ushort *puVar1;
  bool bVar2;
  ushort *puVar3;
  __razController *p_Var4;
  int iVar5;
  
  p_Var4 = &controllerList;
  iVar5 = 1;
  do {
    G2Anim_AttachControllerToSeg
              (&(gameTrackerX.playerInstance)->anim,(uint)p_Var4->segment,(uint)p_Var4->type);
    puVar3 = &p_Var4->segment;
    puVar1 = &p_Var4->type;
    p_Var4 = p_Var4 + 1;
    G2Anim_DisableController(&(gameTrackerX.playerInstance)->anim,(uint)*puVar3,(uint)*puVar1);
    bVar2 = iVar5 < 0x18;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPlayerEvent()
 // line 1603, offset 0x800a3b98
	/* begin block 1 */
		// Start line: 1604
		// Start offset: 0x800A3B98
		// Variables:
	// 		void (*process)(); // $s0
	// 		int message; // stack offset -16
	// 		int data; // stack offset -12

		/* begin block 1.1 */
			// Start line: 1628
			// Start offset: 0x800A3C58
		/* end block 1.1 */
		// End offset: 0x800A3C94
		// End Line: 1637
	/* end block 1 */
	// End offset: 0x800A3E2C
	// End Line: 1691

	/* begin block 2 */
		// Start line: 3424
	/* end block 2 */
	// End Line: 3425

	/* begin block 3 */
		// Start line: 3431
	/* end block 3 */
	// End Line: 3432

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razSetPlayerEvent(void)

{
  _func_4402 *p_Var1;
  ulong uVar2;
  _Instance *p_Var3;
  int local_10;
  int local_c;
  
  p_Var1 = Raziel.State.SectionList[0].Process;
  local_10 = 0;
  local_c = 0;
  if ((((Raziel.Senses.EngagedMask & 1) != 0) && (Raziel.Senses.heldClass != 3)) &&
     (Raziel.State.SectionList[0].Process == StateHandlerIdle)) {
    Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 1;
  }
  if ((((Raziel.Senses.EngagedMask & 4) != 0) && (Raziel.Senses.heldClass != 3)) &&
     (Raziel.State.SectionList[0].Process == StateHandlerCrouch)) {
    Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 2;
  }
  if ((((Raziel.Senses.EngagedMask & 8) != 0) && (Raziel.Senses.heldClass != 3)) &&
     (Raziel.State.SectionList[0].Process == StateHandlerIdle)) {
    uVar2 = INSTANCE_Query(Raziel.Senses.EngagedList[3].instance,4);
    if (uVar2 == 9) {
      Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 8;
    }
    else {
      Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 4;
    }
  }
  if (((((Raziel.Senses.EngagedMask & 0x20) != 0) &&
       (p_Var3 = razGetHeldItem(), p_Var3 == (_Instance *)0x0)) && (Raziel.CurrentPlane == 1)) &&
     (((p_Var1 == StateHandlerIdle || (p_Var1 == StateHandlerStartMove)) ||
      ((((p_Var1 == StateHandlerMove ||
         ((p_Var1 == StateHandlerJump || (p_Var1 == StateHandlerFall)))) ||
        (p_Var1 == StateHandlerSwim)) || (p_Var1 == StateHandlerAutoFace)))))) {
    Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x10;
  }
  if ((Raziel.Senses.EngagedMask & 0x40) != 0) {
    Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x20;
  }
  StateHandlerDecodeHold(&local_10,&local_c);
  if (local_c != 0) {
    if (local_10 == 0x1000002) {
      Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x40;
    }
    if (local_10 == 0x100000a) {
      Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x80;
    }
    if (local_10 == 0x1000018) {
      Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x100;
    }
  }
  if (local_10 == 0x800010) {
    Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x200;
  }
  if (local_10 == 0x80000) {
    Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x400;
  }
  if ((Raziel.Senses.EngagedMask & 0x4000) != 0) {
    Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x800;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPlayerEventHistory(unsigned long event /*$a0*/)
 // line 1698, offset 0x800a3e3c
	/* begin block 1 */
		// Start line: 3392
	/* end block 1 */
	// End Line: 3393

	/* begin block 2 */
		// Start line: 3618
	/* end block 2 */
	// End Line: 3619

void razSetPlayerEventHistory(ulong event)

{
  Raziel.padCommands.Queue[12].Data = Raziel.padCommands.Queue[12].Data | event;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSideMoveSpiderCheck(struct _Instance *instance /*$s2*/, int x /*$a1*/)
 // line 1705, offset 0x800a3e54
	/* begin block 1 */
		// Start line: 1706
		// Start offset: 0x800A3E54
		// Variables:
	// 		struct SVECTOR startVec; // stack offset -32
	// 		struct SVECTOR endVec; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A3F08
	// End Line: 1726

	/* begin block 2 */
		// Start line: 3631
	/* end block 2 */
	// End Line: 3632

int razSideMoveSpiderCheck(_Instance *instance,int x)

{
  uint uVar1;
  short x_00;
  SVECTOR SStack32;
  SVECTOR SStack24;
  
  x_00 = (short)x;
  PHYSICS_GenericLineCheckSetup(x_00,0,0xc0,&SStack32);
  PHYSICS_GenericLineCheckSetup(x_00,-0x140,0xc0,&SStack24);
  uVar1 = PHYSICS_CheckForValidMove(instance,&SStack32,&SStack24,0);
  if ((uVar1 & 1) == 0) {
    uVar1 = 1;
  }
  else {
    PHYSICS_GenericLineCheckSetup(x_00,0,0,&SStack32);
    PHYSICS_GenericLineCheckSetup(x_00,-0x140,0,&SStack24);
    uVar1 = PHYSICS_CheckForValidMove(instance,&SStack32,&SStack24,0);
    uVar1 = uVar1 & 1 ^ 1;
  }
  return uVar1;
}





