#include "THISDUST.H"
#include "RAZLIB.H"


// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYMoveRot(struct _Instance *dest /*$s3*/, short distance /*$a1*/, struct _Position *position /*$s4*/, struct _Rotation *rotation /*$s2*/, int extraZ /*stack 16*/)
 // line 12, offset 0x800a4274
	/* begin block 1 */
		// Start line: 13
		// Start offset: 0x800A4274
		// Variables:
	// 		struct SVECTOR d; // stack offset -72
	// 		struct SVECTOR dd; // stack offset -64
	// 		struct MATRIX mat; // stack offset -56
	/* end block 1 */
	// End offset: 0x800A4274
	// End Line: 13

	/* begin block 2 */
		// Start line: 24
	/* end block 2 */
	// End Line: 25

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razAlignYMoveRot(_Instance *dest,short distance,_Position *position,_Rotation *rotation,
                     int extraZ)

{
  ulong uVar1;
  SVECTOR local_48;
  SVECTOR local_40;
  MATRIX MStack56;
  
  local_48.vy = -distance;
  local_48.vx = 0;
  local_48.vz = 0;
  uVar1 = INSTANCE_Query(dest,7);
  rotation->z = *(short *)(uVar1 + 4) + (short)extraZ + 0x800;
  MATH3D_SetUnityMatrix((char)&MStack56);
  RotMatrixZ((int)rotation->z,&MStack56);
  ApplyMatrixSV(&MStack56,&local_48,&local_40);
  position->x = (dest->position).x + local_40.vx;
  position->y = (dest->position).y + local_40.vy;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotMove(struct _Instance *dest /*$s1*/, short distance /*$a1*/, struct _Position *position /*$s2*/, struct _Rotation *rotation /*$s4*/, int extraZ /*stack 16*/)
 // line 54, offset 0x800a4338
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800A4338
		// Variables:
	// 		struct SVECTOR d; // stack offset -88
	// 		struct SVECTOR dd; // stack offset -80
	// 		struct SVECTOR rot; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64
	/* end block 1 */
	// End offset: 0x800A4338
	// End Line: 55

	/* begin block 2 */
		// Start line: 136
	/* end block 2 */
	// End Line: 137

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razAlignYRotMove(_Instance *dest,short distance,_Position *position,_Rotation *rotation,
                     int extraZ)

{
  SVECTOR local_58;
  SVECTOR local_50;
  SVECTOR SStack72;
  MATRIX MStack64;
  
  memset();
  SStack72.vz = MATH3D_AngleFromPosToPos(position,&dest->position);
  SStack72.vz = SStack72.vz + (short)extraZ;
  rotation->z = SStack72.vz;
  RotMatrix(&SStack72,&MStack64);
  local_58.vx = 0;
  local_58.vz = 0;
  local_58.vy = distance;
  ApplyMatrixSV(&MStack64,&local_58,&local_50);
  position->x = (dest->position).x + local_50.vx;
  position->y = (dest->position).y + local_50.vy;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotMoveInterp(struct _Instance *source /*$s1*/, struct _Instance *dest /*$a1*/, short distance /*$a2*/, unsigned char segNumber /*$s0*/, int Frames /*stack 16*/, int extraZ /*stack 20*/)
 // line 86, offset 0x800a4410
	/* begin block 1 */
		// Start line: 87
		// Start offset: 0x800A4410
		// Variables:
	// 		struct _Position position; // stack offset -40
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _G2SVector3_Type v; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A4410
	// End Line: 87

	/* begin block 2 */
		// Start line: 210
	/* end block 2 */
	// End Line: 211

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
 // line 114, offset 0x800a4504
	/* begin block 1 */
		// Start line: 306
	/* end block 1 */
	// End Line: 307

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
 // line 195, offset 0x800a4530
	/* begin block 1 */
		// Start line: 196
		// Start offset: 0x800A4530
		// Variables:
	// 		int i; // $s0
	// 		int j; // $s2
	// 		int k; // $a2
	// 		int Total; // $s1
	// 		int outer; // stack offset -32
	// 		int rc; // $s3
	// 		struct _SVector point; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A462C
	// End Line: 243

	/* begin block 2 */
		// Start line: 385
	/* end block 2 */
	// End Line: 386

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
  
  iVar3 = (int)DAT_800d5b58;
  iVar4 = 0;
  local_28 = (instance->position).x;
  iVar6 = 0;
  local_26 = (instance->position).y;
  iVar5 = 0;
  do {
    iVar2 = iVar3 + 1;
    if (0x1f < iVar3) {
      iVar3 = 0;
      iVar2 = 1;
    }
    if (0x1f < iVar2) {
      iVar2 = 0;
    }
    setCopReg(2,0x6000,_DAT_800d5b5c);
    setCopReg(2,0x7000,*(undefined4 *)(iVar2 * 4 + DAT_800d5b54));
    setCopReg(2,0x6800,*(undefined4 *)(iVar3 * 4 + DAT_800d5b54));
    copFunction(2,0x1400006);
    local_20 = getCopReg(2,0x18);
    if (local_20 < 1) {
      iVar4 = iVar4 + -1;
    }
    else {
      iVar4 = iVar4 + 1;
    }
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 1;
    iVar2 = COLLIDE_PointInTriangle2DPub
                      (&DAT_800d5b5c,(short *)(DAT_800d5b54 + iVar1),
                       (short *)(DAT_800d5b54 + iVar2 * 4),&local_28);
    iVar6 = iVar6 + iVar2;
  } while (iVar5 < 0x20);
  iVar3 = 0;
  if (iVar6 != 0) {
    iVar3 = iVar4;
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razRotateUpperBody(struct _Instance *instance /*$s3*/, struct evActionLookAroundData *data /*$a1*/)
 // line 247, offset 0x800a4648
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x800A4648
		// Variables:
	// 		int tx; // $s0
	// 		int tz; // $s2
	// 		struct _G2SVector3_Type Rot; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A46D0
	// End Line: 268

	/* begin block 2 */
		// Start line: 555
	/* end block 2 */
	// End Line: 556

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
 // line 285, offset 0x800a4818
	/* begin block 1 */
		// Start line: 640
	/* end block 1 */
	// End Line: 641

	/* begin block 2 */
		// Start line: 644
	/* end block 2 */
	// End Line: 645

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSetFadeEffect(short source,short dest,int steps)

{
  DAT_800d5c58 = DAT_800d5c58 | 3;
  DAT_800d5c5c = source;
  DAT_800d5c5e = dest;
  DAT_800d5c60 = steps;
  DAT_800d5c64 = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razPlaneShift(struct _Instance *instance /*$a0*/)
 // line 302, offset 0x800a483c
	/* begin block 1 */
		// Start line: 672
	/* end block 1 */
	// End Line: 673

	/* begin block 2 */
		// Start line: 679
	/* end block 2 */
	// End Line: 680

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razPlaneShift(_Instance *instance)

{
  int iVar1;
  
  if ((DAT_800d2210 & 0x40000) == 0) {
    if (DAT_800d5b78 == 1) {
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
 // line 320, offset 0x800a4898
	/* begin block 1 */
		// Start line: 321
		// Start offset: 0x800A4898
		// Variables:
	// 		struct _Instance *inst; // $v0
	/* end block 1 */
	// End offset: 0x800A498C
	// End Line: 351

	/* begin block 2 */
		// Start line: 715
	/* end block 2 */
	// End Line: 716

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSpectralShift(void)

{
  _Instance *Inst;
  int iVar1;
  
  if (((DAT_800d2210 & 0x40000) == 0) && (DAT_800d5b78 == 1)) {
    Inst = razGetHeldItem();
    if (Inst != (_Instance *)0x0) {
      INSTANCE_Post(Inst,0x800008,4);
      razSetFadeEffect(0x1000,0,0x100);
    }
    DAT_800d20f8->flags2 = DAT_800d20f8->flags2 | 0x8000000;
    INSTANCE_Post(DAT_800d20f8,(int)&DAT_00100014,0);
    iVar1 = GetMaxHealth();
    if (DAT_800d5b3c == iVar1) {
      DAT_800d5b3c = 100000;
    }
    else {
      DAT_800d5b3c = 0x14586;
    }
    DAT_800d5b78 = 2;
    razReaverOn();
    if ((DAT_800d20d6 == 0) && (MORPH_ToggleMorph(), DAT_800d5750 != StateHandlerGlyphs)) {
      INSTANCE_Post(DAT_800d20f8,0x40005,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razMaterialShift()
 // line 354, offset 0x800a499c
	/* begin block 1 */
		// Start line: 785
	/* end block 1 */
	// End Line: 786

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razMaterialShift(void)

{
  if ((DAT_800d5b78 == 2) && (DAT_800d5b3c == 100000)) {
    DAT_800d5b78 = 1;
    DAT_800d20f8->flags2 = DAT_800d20f8->flags2 & 0xf7ffffff;
    DAT_800d5b3c = GetMaxHealth();
    DAT_800d5b40 = 0;
    razReaverOn();
    if ((DAT_800d20d6 != 0) && (MORPH_ToggleMorph(), DAT_800d5750 != StateHandlerGlyphs)) {
      INSTANCE_Post(DAT_800d20f8,0x40005,0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ RAZIEL_OkToShift()
 // line 373, offset 0x800a4a40
	/* begin block 1 */
		// Start line: 824
	/* end block 1 */
	// End Line: 825

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int RAZIEL_OkToShift(void)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_800d5b78 == 2) {
    iVar1 = GetMaxHealth();
    uVar2 = 0;
    if (DAT_800d5b3c == iVar1) {
      if ((DAT_800d5b48 & 0x40) == 0) {
        uVar2 = (uint)((DAT_800d5ae0 & 0x40) != 0);
      }
      else {
        uVar2 = 1;
        if ((DAT_800d5b48 & 0x10) == 0) {
          FONT_Print(s__YOU_CAN_NOT_HAVE_SHIFT_ANYTIME_W_800d0ae8);
          FONT_Print(s__BEAT_THE_ALUKA_BOSS_THEN_WIN_TH_800d0b24);
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
// int /*$ra*/ razPickupAndGrab(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/)
 // line 399, offset 0x800a4ad4
	/* begin block 1 */
		// Start line: 400
		// Start offset: 0x800A4AD4

		/* begin block 1.1 */
			// Start line: 403
			// Start offset: 0x800A4B30

			/* begin block 1.1.1 */
				// Start line: 417
				// Start offset: 0x800A4B68
				// Variables:
			// 		struct evObjectData *objData; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800A4C00
			// End Line: 432
		/* end block 1.1 */
		// End offset: 0x800A4C88
		// End Line: 440
	/* end block 1 */
	// End offset: 0x800A4C8C
	// End Line: 444

	/* begin block 2 */
		// Start line: 876
	/* end block 2 */
	// End Line: 877

	/* begin block 3 */
		// Start line: 878
	/* end block 3 */
	// End Line: 879

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razPickupAndGrab(__CharacterState *In,int CurrentSection)

{
  _Instance *Inst;
  int Data;
  ulong uVar1;
  
  if ((DAT_800d5b1c & 0x20) == 0) {
    Data = 1;
  }
  else {
    Inst = razGetHeldItem();
    Data = 1;
    if ((((Inst == (_Instance *)0x0) && (DAT_800d5b78 == 1)) &&
        (Data = 1, (DAT_800d5aa4 & 0x800) == 0)) && (Data = 0, CurrentSection != 0)) {
      Inst = *(_Instance **)(*(int *)(DAT_800d5b18 + 0x28) + 0x144);
      if (Inst != (_Instance *)0x0) {
        INSTANCE_Query(Inst,0);
      }
      if (CurrentSection == 1) {
        Inst = *(_Instance **)(*(int *)(DAT_800d5b18 + 0x28) + 0x144);
        if (Inst != (_Instance *)0x0) {
          INSTANCE_Post(Inst,(int)&DAT_0100001b,0);
          INSTANCE_UnlinkFromParent(*(_Instance **)(DAT_800d5b18 + 0x28));
        }
        Data = SetObjectData(0,0,8,In->CharacterInstance,0x31);
        INSTANCE_Post(*(_Instance **)(DAT_800d5b18 + 0x28),0x800002,Data);
        if (*(short *)(Data + 6) != 0) {
          return 0;
        }
        razReaverOff();
      }
      (&In->CharacterInstance + CurrentSection * 0x47)[0x47] = (_Instance *)0x0;
      uVar1 = INSTANCE_Query(*(_Instance **)(DAT_800d5b18 + 0x28),4);
      G2EmulationSwitchAnimation(In,CurrentSection,(uint)PickupList[uVar1],0,3,1);
      DAT_800d5c48 = (&In->CharacterInstance + CurrentSection * 0x47)[2];
      StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,0);
      Data = 0;
    }
  }
  return Data;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razZeroAxis(long *x /*$s1*/, long *y /*$s2*/, int radius /*$s0*/)
 // line 451, offset 0x800a4ca4
	/* begin block 1 */
		// Start line: 452
		// Start offset: 0x800A4CA4
		// Variables:
	// 		unsigned long distance; // $v0
	/* end block 1 */
	// End offset: 0x800A4CEC
	// End Line: 484

	/* begin block 2 */
		// Start line: 984
	/* end block 2 */
	// End Line: 985

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
 // line 488, offset 0x800a4d04
	/* begin block 1 */
		// Start line: 489
		// Start offset: 0x800A4D04
		// Variables:
	// 		long adjustment; // $s0

		/* begin block 1.1 */
			// Start line: 489
			// Start offset: 0x800A4D04
			// Variables:
		// 		int data; // $v1
		/* end block 1.1 */
		// End offset: 0x800A4D80
		// End Line: 510
	/* end block 1 */
	// End offset: 0x800A4D80
	// End Line: 517

	/* begin block 2 */
		// Start line: 1060
	/* end block 2 */
	// End Line: 1061

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razAdjustSpeed(_Instance *instance,int minSpeed)

{
  int iVar1;
  long adjustment;
  
  iVar1 = (int)DAT_800d5ade;
  if (iVar1 < DAT_800d5ab8) {
    adjustment = (long)DAT_800d5ada;
  }
  else {
    if (DAT_800d5ab8 < DAT_800d5adc) {
      adjustment = (long)DAT_800d5ad8;
    }
    else {
      adjustment = (int)DAT_800d5ada -
                   (((int)DAT_800d5ada - (int)DAT_800d5ad8) * (iVar1 - DAT_800d5ab8)) /
                   (iVar1 - DAT_800d5adc);
    }
  }
  G2Anim_SetSpeedAdjustment(&instance->anim,adjustment);
  return adjustment;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razLaunchForce(struct _Instance *instance /*$s0*/)
 // line 538, offset 0x800a4da0
	/* begin block 1 */
		// Start line: 539
		// Start offset: 0x800A4DA0
	/* end block 1 */
	// End offset: 0x800A4DA0
	// End Line: 539

	/* begin block 2 */
		// Start line: 1168
	/* end block 2 */
	// End Line: 1169

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razLaunchForce(_Instance *instance)

{
  PHYSOB_BirthProjectile(instance,0x31,(uint)DAT_800d5b48._1_1_ & 1);
  DAT_800d5c58 = DAT_800d5c58 | 4;
  razSetupSoundRamp(instance,(_SoundRamp *)&DAT_800d5ca0,0xc,(int)*(short *)(PlayerData + 0x38),
                    (int)*(short *)(PlayerData + 0x3a),(int)*(short *)(PlayerData + 0x3c),
                    (int)*(short *)(PlayerData + 0x3e),*(int *)(PlayerData + 0x40) * 0x1e,
                    (int)&DAT_00002710);
  DAT_800d5cd0 = 0;
  DAT_800d5cd4 = 0;
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ razGetHeldItem()
 // line 562, offset 0x800a4e34
	/* begin block 1 */
		// Start line: 564
		// Start offset: 0x800A4E34
		// Variables:
	// 		struct _Instance *instance; // $v0
	/* end block 1 */
	// End offset: 0x800A4E64
	// End Line: 586

	/* begin block 2 */
		// Start line: 1227
	/* end block 2 */
	// End Line: 1228

	/* begin block 3 */
		// Start line: 1228
	/* end block 3 */
	// End Line: 1229

	/* begin block 4 */
		// Start line: 1230
	/* end block 4 */
	// End Line: 1231

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

_Instance * razGetHeldItem(void)

{
  _Instance *p_Var1;
  
  p_Var1 = *(_Instance **)(DAT_800d5748 + 0x148);
  if (((DAT_800d5b70 != (_Instance *)0x0) && (p_Var1 == DAT_800d5b70)) &&
     (p_Var1 != (_Instance *)0x0)) {
    return p_Var1->LinkSibling;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ razGetHeldWeapon()
 // line 590, offset 0x800a4e6c
	/* begin block 1 */
		// Start line: 591
		// Start offset: 0x800A4E6C
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x800A4EBC
	// End Line: 608

	/* begin block 2 */
		// Start line: 1285
	/* end block 2 */
	// End Line: 1286

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

_Instance * razGetHeldWeapon(void)

{
  _Instance *Inst;
  ulong uVar1;
  
  Inst = razGetHeldItem();
  if (Inst == (_Instance *)0x0) {
    Inst = (_Instance *)0x0;
    if (DAT_800d5b2c != 0) {
      Inst = DAT_800d5b70;
    }
  }
  else {
    uVar1 = INSTANCE_Query(Inst,1);
    if ((uVar1 & 0x20) == 0) {
      Inst = (_Instance *)0x0;
    }
  }
  return Inst;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverBladeOff()
 // line 611, offset 0x800a4ecc
	/* begin block 1 */
		// Start line: 1327
	/* end block 1 */
	// End Line: 1328

	/* begin block 2 */
		// Start line: 1328
	/* end block 2 */
	// End Line: 1329

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razReaverBladeOff(void)

{
  if (DAT_800d5b70 != (_Instance *)0x0) {
    INSTANCE_Post(DAT_800d5b70,0x800109,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverBladeOn()
 // line 619, offset 0x800a4efc
	/* begin block 1 */
		// Start line: 1344
	/* end block 1 */
	// End Line: 1345

	/* begin block 2 */
		// Start line: 1345
	/* end block 2 */
	// End Line: 1346

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razReaverBladeOn(void)

{
  if (DAT_800d5b70 != (_Instance *)0x0) {
    INSTANCE_Post(DAT_800d5b70,0x800108,0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razReaverOff()
 // line 628, offset 0x800a4f2c
	/* begin block 1 */
		// Start line: 629
		// Start offset: 0x800A4F2C

		/* begin block 1.1 */
			// Start line: 632
			// Start offset: 0x800A4F50
			// Variables:
		// 		struct _Instance *heldWeapon; // $s0
		/* end block 1.1 */
		// End offset: 0x800A4F8C
		// End Line: 639
	/* end block 1 */
	// End offset: 0x800A4F90
	// End Line: 641

	/* begin block 2 */
		// Start line: 1363
	/* end block 2 */
	// End Line: 1364

	/* begin block 3 */
		// Start line: 1365
	/* end block 3 */
	// End Line: 1366

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razReaverOff(void)

{
  int iVar1;
  _Instance *p_Var2;
  
  if (DAT_800d5b70 == (_Instance *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    if (DAT_800d5b2c == 0x1000) {
      p_Var2 = razGetHeldWeapon();
      INSTANCE_Post(DAT_800d5b70,0x800101,0);
      iVar1 = 1;
      if (p_Var2 == DAT_800d5b70) {
        DAT_800d5b2c = 0;
      }
    }
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razReaverOn()
 // line 644, offset 0x800a4fa0
	/* begin block 1 */
		// Start line: 1399
	/* end block 1 */
	// End Line: 1400

	/* begin block 2 */
		// Start line: 1401
	/* end block 2 */
	// End Line: 1402

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razReaverOn(void)

{
  _Instance *p_Var1;
  int iVar2;
  
  if (DAT_800d5b70 == (_Instance *)0x0) {
    iVar2 = 0;
  }
  else {
    p_Var1 = razGetHeldItem();
    iVar2 = 0;
    if ((p_Var1 == (_Instance *)0x0) &&
       ((iVar2 = GetMaxHealth(), DAT_800d5b3c == iVar2 || (iVar2 = 0, DAT_800d5b78 == 2)))) {
      INSTANCE_Post(DAT_800d5b70,0x800100,0);
      DAT_800d5b2c = 0x1000;
      if ((DAT_800d5b78 == 2) && (DAT_800d5b74 != 1)) {
        razReaverImbue(1);
      }
      iVar2 = 1;
      if ((DAT_800d5b78 == 1) && (iVar2 = 1, DAT_800d5b74 == 1)) {
        razReaverImbue(2);
        iVar2 = 1;
      }
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverPickup(struct _Instance *instance /*$a2*/, struct _Instance *soulReaver /*$s0*/)
 // line 668, offset 0x800a5070
	/* begin block 1 */
		// Start line: 1452
	/* end block 1 */
	// End Line: 1453

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razReaverPickup(_Instance *instance,_Instance *soulReaver)

{
  _Instance *p_Var1;
  int Data;
  
  INSTANCE_Post(soulReaver,0x800002,(int)instance);
  DAT_800d5b70 = soulReaver;
  p_Var1 = razGetHeldItem();
  if (p_Var1 != (_Instance *)0x0) {
    razReaverOff();
  }
  if (DAT_800d5b78 == 1) {
    Data = 2;
    DAT_800d5b74 = 2;
    debugRazielFlags2 = 0x800;
  }
  else {
    Data = 1;
    debugRazielFlags2 = 0x400;
    DAT_800d5b74 = 1;
  }
  debugRazielFlags1 = DAT_800d5b48 | 0xc08;
  DAT_800d5b48 = debugRazielFlags1;
  INSTANCE_Post(soulReaver,0x800103,Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverImbue(int reaverType /*$a2*/)
 // line 696, offset 0x800a512c
	/* begin block 1 */
		// Start line: 1520
	/* end block 1 */
	// End Line: 1521

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razReaverImbue(int reaverType)

{
  debugRazielFlags2 = 1 << (reaverType + 9U & 0x1f);
  DAT_800d5b74 = reaverType;
  INSTANCE_Post(DAT_800d5b70,0x800103,reaverType);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razGetReaverFromMask(int reaverMask /*$a0*/)
 // line 705, offset 0x800a516c
	/* begin block 1 */
		// Start line: 707
		// Start offset: 0x800A516C
		// Variables:
	// 		int rc; // $v0
	/* end block 1 */
	// End offset: 0x800A5188
	// End Line: 716

	/* begin block 2 */
		// Start line: 1543
	/* end block 2 */
	// End Line: 1544

	/* begin block 3 */
		// Start line: 1544
	/* end block 3 */
	// End Line: 1545

	/* begin block 4 */
		// Start line: 1546
	/* end block 4 */
	// End Line: 1547

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
 // line 719, offset 0x800a5190
	/* begin block 1 */
		// Start line: 720
		// Start offset: 0x800A5190
		// Variables:
	// 		struct _Instance *Inst; // $v0
	/* end block 1 */
	// End offset: 0x800A51CC
	// End Line: 730

	/* begin block 2 */
		// Start line: 1571
	/* end block 2 */
	// End Line: 1572

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razReaverScale(int scale)

{
  _Instance *Inst;
  
  Inst = razGetHeldWeapon();
  if ((DAT_800d5b70 != (_Instance *)0x0) && (Inst == DAT_800d5b70)) {
    INSTANCE_Post(Inst,0x800107,scale);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razGetForwardNormal(struct _Instance *inst /*$a0*/, struct _Instance *target /*$a1*/)
 // line 733, offset 0x800a51dc
	/* begin block 1 */
		// Start line: 734
		// Start offset: 0x800A51DC
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -72
	// 		struct SVECTOR Old; // stack offset -24
	// 		struct SVECTOR New; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A52B0
	// End Line: 767

	/* begin block 2 */
		// Start line: 1599
	/* end block 2 */
	// End Line: 1600

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
    DAT_800d5ae4 = local_48.wNormal.vx;
    DAT_800d5ae6 = local_48.wNormal.vy;
    DAT_800d5ae8 = local_48.wNormal.vz;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razGetRotFromNormal(struct _SVector *normal /*$a0*/, struct _Rotation *rot /*$a2*/)
 // line 770, offset 0x800a52c0
	/* begin block 1 */
		// Start line: 771
		// Start offset: 0x800A52C0
		// Variables:
	// 		struct _Position a; // stack offset -24
	// 		struct _Position b; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A52C0
	// End Line: 771

	/* begin block 2 */
		// Start line: 1682
	/* end block 2 */
	// End Line: 1683

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
// void /*$ra*/ razCenterWithBlock(struct _Instance *inst /*$s3*/, struct _Instance *target /*$s1*/, int dist /*$s2*/)
 // line 784, offset 0x800a530c
	/* begin block 1 */
		// Start line: 785
		// Start offset: 0x800A530C
		// Variables:
	// 		struct SVECTOR d; // stack offset -88
	// 		struct SVECTOR dd; // stack offset -80
	// 		struct _Rotation rot; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64
	// 		struct _G2SVector3_Type v; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A5494
	// End Line: 836

	/* begin block 2 */
		// Start line: 1722
	/* end block 2 */
	// End Line: 1723

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razCenterWithBlock(_Instance *inst,_Instance *target,int dist)

{
  int iVar1;
  int iVar2;
  _G2Bool_Enum _Var3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  SVECTOR local_58;
  SVECTOR local_50;
  _Rotation _Stack72;
  MATRIX MStack64;
  _G2SVector3_Type local_20;
  
  razGetForwardNormal(inst,target);
  razGetRotFromNormal((_SVector *)&DAT_800d5ae4,&_Stack72);
  iVar1 = (int)DAT_800d5ae8;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  MATH3D_SetUnityMatrix((char)&MStack64);
  RotMatrixZ((int)_Stack72.z,&MStack64);
  local_58.vy = 0x140 - (short)dist;
  local_58.vz = 0;
  local_58.vx = 0;
  ApplyMatrixSV(&MStack64,&local_58,&local_50);
  iVar4 = (uint)(ushort)(inst->position).x - (uint)(ushort)(target->position).x;
  iVar8 = iVar4 * 0x10000;
  iVar7 = iVar8 >> 0x10;
  local_58.vx = (short)iVar4;
  iVar4 = iVar7;
  if (iVar7 < 0) {
    iVar4 = -iVar7;
  }
  iVar5 = (uint)(ushort)(inst->position).y - (uint)(ushort)(target->position).y;
  local_58.vy = (short)iVar5;
  iVar5 = iVar5 * 0x10000;
  iVar6 = iVar5 >> 0x10;
  iVar2 = iVar6;
  if (iVar6 < 0) {
    iVar2 = -iVar6;
  }
  if (iVar4 < iVar2) {
    local_58.vx = (short)(iVar7 - (iVar8 >> 0x1f) >> 1);
    if (1000 < iVar1) {
      local_58.vy = local_50.vy;
    }
  }
  else {
    local_58.vy = (short)(iVar6 - (iVar5 >> 0x1f) >> 1);
    if (1000 < iVar1) {
      local_58.vx = local_50.vx;
    }
  }
  local_20.x = local_50.vx + ((inst->position).x - local_58.vx);
  local_20.y = local_50.vy + ((inst->position).y - local_58.vy);
  local_20.z = (inst->position).z;
  _Var3 = G2Anim_IsControllerActive(&inst->anim,0,0x20);
  if (_Var3 == G2FALSE) {
    G2Anim_EnableController(&inst->anim,0,0x20);
  }
  G2EmulationSetInterpController_Vector(inst,0,0x20,&local_20,6,0);
  (inst->rotation).z = _Stack72.z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPauseTranslation(struct _Instance *instance /*$a0*/)
 // line 843, offset 0x800a54e0
	/* begin block 1 */
		// Start line: 844
		// Start offset: 0x800A54E0
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A5514
	// End Line: 854

	/* begin block 2 */
		// Start line: 1860
	/* end block 2 */
	// End Line: 1861

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSetPauseTranslation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  _G2SVector3_Type local_10;
  
  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim,0,0x22);
  if (_Var1 == G2FALSE) {
    G2Anim_EnableController(anim,0,0x22);
  }
  local_10.x = 0;
  local_10.y = 0;
  local_10.z = 0;
  G2Anim_SetController_Vector(anim,0,0x22,&local_10);
  ControlFlag = ControlFlag | 0x20000000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razResetPauseTranslation(struct _Instance *instance /*$a0*/)
 // line 860, offset 0x800a5554
	/* begin block 1 */
		// Start line: 1902
	/* end block 1 */
	// End Line: 1903

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razResetPauseTranslation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  
  _Var1 = G2Anim_IsControllerActive(&instance->anim,0,0x22);
  if (_Var1 != G2FALSE) {
    G2Anim_DisableController(&instance->anim,0,0x22);
  }
  ControlFlag = ControlFlag & 0xdfffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSelectMotionAnim(struct __CharacterState *In /*$s6*/, int CurrentSection /*$s7*/, int Frames /*$s4*/, int *Anim /*$fp*/)
 // line 870, offset 0x800a55ac
	/* begin block 1 */
		// Start line: 871
		// Start offset: 0x800A55AC
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -48
	// 		int switchType; // $s0
	// 		int frame; // $s1

		/* begin block 1.1 */
			// Start line: 1112
			// Start offset: 0x800A5A2C
			// Variables:
		// 		int adjustment; // $s0
		/* end block 1.1 */
		// End offset: 0x800A5B18
		// End Line: 1133

		/* begin block 1.2 */
			// Start line: 1138
			// Start offset: 0x800A5B34
			// Variables:
		// 		struct _G2AnimSection_Type *animSectionA; // $s1
		// 		struct _G2AnimSection_Type *animSectionB; // $s2
		// 		struct _G2AnimKeylist_Type *keylist; // $s3
		// 		int keylistID; // $s5
		/* end block 1.2 */
		// End offset: 0x800A5BEC
		// End Line: 1160
	/* end block 1 */
	// End offset: 0x800A5BEC
	// End Line: 1168

	/* begin block 2 */
		// Start line: 1924
	/* end block 2 */
	// End Line: 1925

	/* begin block 3 */
		// Start line: 1933
	/* end block 3 */
	// End Line: 1934

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSelectMotionAnim(__CharacterState *In,int CurrentSection,int Frames,int *Anim)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  _G2Bool_Enum _Var5;
  int frame;
  _Instance *p_Var6;
  bool bVar7;
  int frame_00;
  _G2AnimSection_Type *section;
  _G2AnimSection_Type *section_00;
  _G2AnimKeylist_Type *keylist;
  _G2SVector3_Type local_30;
  
  bVar7 = false;
  frame_00 = 0;
  if (DAT_800d5ab8 < 0xeb9) {
    if (DAT_800d5ab8 - 0xae0U < 0x3d9) {
      uVar3 = ControlFlag & 0xffffdfff;
      uVar4 = ControlFlag & 0x20000000;
      ControlFlag = uVar3;
      if (uVar4 != 0) {
        razResetPauseTranslation(In->CharacterInstance);
      }
      frame = *Anim;
      if (frame == 0x3c) {
        if ((DAT_800d5c4c & 0xf) != 0) {
          bVar7 = true;
        }
        if ((DAT_800d5c4c & 8) != 0) {
          frame_00 = 7;
        }
        if ((DAT_800d5c4c & 1) != 0) {
          frame_00 = 0xd;
        }
        uVar3 = DAT_800d5c4c & 4;
        if ((DAT_800d5c4c & 2) != 0) {
          frame_00 = 0x14;
        }
      }
      else {
        if (frame != 0x44) {
          if (frame != 0x40) {
            bVar7 = true;
          }
          goto LAB_800a58a8;
        }
        if ((DAT_800d5c4c & 0xf00) != 0) {
          bVar7 = true;
        }
        if ((DAT_800d5c4c & 0x800) != 0) {
          frame_00 = 7;
        }
        if ((DAT_800d5c4c & 0x100) != 0) {
          frame_00 = 0xd;
        }
        uVar3 = DAT_800d5c4c & 0x400;
        if ((DAT_800d5c4c & 0x200) != 0) {
          frame_00 = 0x14;
        }
      }
      if (uVar3 != 0) {
        frame_00 = 0x19;
      }
    }
    else {
      if (DAT_800d5ab8 < 0xae0) {
        ControlFlag = ControlFlag | 0x2000;
        frame = *Anim;
        if (frame == 0x40) {
          bVar7 = (DAT_800d5c4c & 0xf0) != 0;
          if ((DAT_800d5c4c & 0x80) != 0) {
            frame_00 = 0xc;
          }
          if ((DAT_800d5c4c & 0x10) != 0) {
            frame_00 = 0x14;
          }
          uVar3 = DAT_800d5c4c & 0x40;
          if ((DAT_800d5c4c & 0x20) != 0) {
            frame_00 = 0x20;
          }
        }
        else {
          if (frame != 0x44) {
            if (frame != 0x3c) {
              bVar7 = true;
            }
            goto LAB_800a58a8;
          }
          bVar7 = (DAT_800d5c4c & 0xf00) != 0;
          if ((DAT_800d5c4c & 0x800) != 0) {
            frame_00 = 0xc;
          }
          if ((DAT_800d5c4c & 0x100) != 0) {
            frame_00 = 0x14;
          }
          uVar3 = DAT_800d5c4c & 0x400;
          if ((DAT_800d5c4c & 0x200) != 0) {
            frame_00 = 0x20;
          }
        }
        if (uVar3 != 0) {
          frame_00 = 0;
        }
      }
    }
  }
  else {
    if (DAT_800d5c80 == 0) {
      ControlFlag = ControlFlag & 0xffffdfff;
    }
    if ((ControlFlag & 0x20000000U) != 0) {
      razResetPauseTranslation(In->CharacterInstance);
    }
    frame = *Anim;
    if (frame == 0x3c) {
      if ((DAT_800d5c4c & 0xf) != 0) {
        bVar7 = true;
      }
      if ((DAT_800d5c4c & 8) != 0) {
        frame_00 = 5;
      }
      if ((DAT_800d5c4c & 1) != 0) {
        frame_00 = 0x17;
      }
      uVar3 = DAT_800d5c4c & 4;
      if ((DAT_800d5c4c & 2) != 0) {
        frame_00 = 0x11;
      }
    }
    else {
      if (frame != 0x40) {
        if (frame != 0x44) {
          bVar7 = true;
        }
        goto LAB_800a58a8;
      }
      if ((DAT_800d5c4c & 0xf0) != 0) {
        bVar7 = true;
      }
      if ((DAT_800d5c4c & 0x80) != 0) {
        frame_00 = 5;
      }
      if ((DAT_800d5c4c & 0x10) != 0) {
        frame_00 = 0x17;
      }
      uVar3 = DAT_800d5c4c & 0x40;
      if ((DAT_800d5c4c & 0x20) != 0) {
        frame_00 = 0x11;
      }
    }
    if (uVar3 != 0) {
      frame_00 = 0xb;
    }
  }
LAB_800a58a8:
  if (bVar7 == true) {
    if (CurrentSection == 2) {
      DAT_800d5c4c = 0;
    }
    frame = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x40,frame_00,Frames);
    if (frame != 0) {
      G2EmulationSwitchAnimation(In,CurrentSection,0x7c,frame_00,Frames,2);
    }
    DAT_800d5ad8 = 0xccc;
    DAT_800d5ada = 0x1800;
    DAT_800d5adc = 0xadf;
    DAT_800d5ade = 0xeb8;
    frame_00 = 0x40;
LAB_800a5a0c:
    *Anim = frame_00;
  }
  else {
    if (bVar7 < 3) {
      if (bVar7 == true) {
        if (CurrentSection == 2) {
          DAT_800d5c4c = 0;
        }
        frame = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x3c,frame_00,Frames);
        if (frame != 0) {
          G2EmulationSwitchAnimation(In,CurrentSection,0x7b,frame_00,Frames,2);
        }
        DAT_800d5ad8 = 0x1000;
        DAT_800d5ada = 0x1c00;
        DAT_800d5adc = 0x8fc;
        DAT_800d5ade = 0xadf;
        frame_00 = 0x3c;
        goto LAB_800a5a0c;
      }
    }
    else {
      if (bVar7 == true) {
        if (CurrentSection == 2) {
          DAT_800d5c4c = 0;
        }
        frame = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x44,frame_00,Frames);
        if (frame != 0) {
          G2EmulationSwitchAnimation(In,CurrentSection,2,frame_00,Frames,2);
        }
        DAT_800d5ad8 = 0xddb;
        DAT_800d5adc = 0xeb8;
        frame_00 = 0x44;
        DAT_800d5ada = 0x1000;
        DAT_800d5ade = 0x1000;
        goto LAB_800a5a0c;
      }
    }
  }
  if (CurrentSection != 0) {
    if (In->SectionList[0].Process != StateHandlerMove) {
      return;
    }
    p_Var6 = In->CharacterInstance;
    section = (p_Var6->anim).section;
    section_00 = (p_Var6->anim).section + CurrentSection;
    _Var5 = G2AnimSection_IsInInterpolation(section);
    if (_Var5 != G2FALSE) {
      return;
    }
    _Var5 = G2AnimSection_IsInInterpolation(section_00);
    if (_Var5 != G2FALSE) {
      return;
    }
    frame_00 = G2AnimSection_GetKeyframeNumber(section);
    frame = G2AnimSection_GetKeyframeNumber(section_00);
    if (frame_00 == frame) {
      return;
    }
    keylist = (p_Var6->anim).section[0].keylist;
    uVar1 = (p_Var6->anim).section[0].keylistID;
    frame_00 = G2AnimSection_GetKeyframeNumber(section);
    frame = G2AnimKeylist_GetKeyframeCount(keylist);
    frame = (frame_00 + 6) % frame;
    frame_00 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,*Anim,frame,6);
    if (frame_00 == 0) {
      return;
    }
    G2AnimSection_InterpToKeylistFrame(section_00,keylist,(uint)uVar1,frame,600);
    return;
  }
  if ((ControlFlag & 0x20000000U) != 0) {
    return;
  }
  local_30.z = 0;
  local_30.x = 0;
  frame_00 = *Anim;
  if (frame_00 == 0x40) {
    sVar2 = -0x23;
  }
  else {
    if (frame_00 < 0x41) {
      sVar2 = -0x10;
      if (frame_00 != 0x3c) goto LAB_800a5a78;
    }
    else {
      sVar2 = -0x3c;
      if (frame_00 != 0x44) goto LAB_800a5a78;
    }
  }
  local_30.y = sVar2;
LAB_800a5a78:
  frame_00 = razAdjustSpeed(In->CharacterInstance,1);
  sVar2 = G2Timer_GetFrameTime();
  local_30.y = (short)(((int)local_30.y * (int)sVar2 * frame_00 >> 0xc) / 100);
  _Var5 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,0,0x22);
  if (_Var5 == G2FALSE) {
    G2Anim_EnableController(&In->CharacterInstance->anim,0,0x22);
  }
  G2Anim_SetController_Vector(&In->CharacterInstance->anim,0,0x22,&local_30);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razApplyMotion(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/)
 // line 1172, offset 0x800a5c1c
	/* begin block 1 */
		// Start line: 1173
		// Start offset: 0x800A5C1C
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1178
			// Start offset: 0x800A5C4C
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $s0

			/* begin block 1.1.1 */
				// Start line: 1218
				// Start offset: 0x800A5CF4
				// Variables:
			// 		long adjustment; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800A5D90
			// End Line: 1228
		/* end block 1.1 */
		// End offset: 0x800A5D90
		// End Line: 1229
	/* end block 1 */
	// End offset: 0x800A5D90
	// End Line: 1231

	/* begin block 2 */
		// Start line: 2555
	/* end block 2 */
	// End Line: 2556

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razApplyMotion(__CharacterState *In,int CurrentSection)

{
  short sVar1;
  _G2AnimKeylist_Type *p_Var2;
  int iVar3;
  _G2Bool_Enum _Var4;
  _Instance *instance;
  _G2SVector3_Type _Stack24;
  
  memset();
  if (CurrentSection == 0) {
    instance = In->CharacterInstance;
    p_Var2 = G2Instance_GetKeylist(instance,2);
    if ((instance->anim).section[0].keylist == p_Var2) {
      _Stack24.y = -0x3c;
    }
    else {
      p_Var2 = G2Instance_GetKeylist(In->CharacterInstance,0x7c);
      if ((instance->anim).section[0].keylist == p_Var2) {
        _Stack24.y = -0x23;
      }
      else {
        p_Var2 = G2Instance_GetKeylist(In->CharacterInstance,0x7b);
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
    if (iVar3 == 0) goto LAB_800a5d94;
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
LAB_800a5d94:
  return -iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razResetMotion(struct _Instance *instance /*$a0*/)
 // line 1235, offset 0x800a5dac
	/* begin block 1 */
		// Start line: 2684
	/* end block 1 */
	// End Line: 2685

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razResetMotion(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim,0,0x22);
  if (_Var1 != G2FALSE) {
    G2Anim_DisableController(anim,0,0x22);
  }
  DAT_800d5c4c = 0;
  G2Anim_SetSpeedAdjustment(anim,0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetDampingPhysics(struct _Instance *instance /*$a0*/)
 // line 1274, offset 0x800a5e00
	/* begin block 1 */
		// Start line: 2546
	/* end block 1 */
	// End Line: 2547

	/* begin block 2 */
		// Start line: 2734
	/* end block 2 */
	// End Line: 2735

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSetDampingPhysics(_Instance *instance)

{
  DAT_800d5aac = 0;
  DAT_800d5c50 = 0;
  PhysicsMode = 4;
  SetDampingPhysics(instance,*(int *)(PlayerData + 0x44));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razEnterWater(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, struct evPhysicsSwimData *SwimData /*$s3*/)
 // line 1284, offset 0x800a5e38
	/* begin block 1 */
		// Start line: 1285
		// Start offset: 0x800A5E38
		// Variables:
	// 		struct _Instance *Inst; // $s2
	/* end block 1 */
	// End offset: 0x800A60C0
	// End Line: 1382

	/* begin block 2 */
		// Start line: 2755
	/* end block 2 */
	// End Line: 2756

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razEnterWater(__CharacterState *In,int CurrentSection,evPhysicsSwimData *SwimData)

{
  _Instance *Inst;
  ulong uVar1;
  int CurrentSection_00;
  int NewAnim;
  int local_20;
  int local_1c;
  
  Inst = razGetHeldWeapon();
  if ((SwimData->rc & 0x10U) != 0) {
    if ((DAT_800d5b78 == 1) && ((DAT_800d5b48 & 0x10) == 0)) {
      DAT_800d5b3c = 100000;
      SetPhysics(In->CharacterInstance,-0x10,0,0,0);
      PhysicsMode = 0;
    }
    else {
      if ((Inst == (_Instance *)0x0) || (uVar1 = INSTANCE_Query(Inst,4), uVar1 != 3)) {
        if (((DAT_800d5aa4 & 0x40000) == 0) && (DAT_800d5b78 == 1)) {
          if (PhysicsMode != 4) {
            razSetDampingPhysics(In->CharacterInstance);
          }
          if ((In->CharacterInstance->zVel == 0) || ((DAT_800d5aa4 & 0x400000) != 0)) {
            razResetMotion(In->CharacterInstance);
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
  if (((SwimData->rc & 0x800U) != 0) && (DAT_800d5b2c == 1)) {
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
    if (Inst == (_Instance *)0x0) {
      razSetDampingPhysics(In->CharacterInstance);
    }
    else {
      INSTANCE_Query(Inst,4);
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
 // line 1409, offset 0x800a60dc
	/* begin block 1 */
		// Start line: 1411
		// Start offset: 0x800A60DC
	/* end block 1 */
	// End offset: 0x800A6128
	// End Line: 1425

	/* begin block 2 */
		// Start line: 3006
	/* end block 2 */
	// End Line: 3007

	/* begin block 3 */
		// Start line: 3007
	/* end block 3 */
	// End Line: 3008

	/* begin block 4 */
		// Start line: 3013
	/* end block 4 */
	// End Line: 3014

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
  DAT_800d5c9e = (undefined2)(iVar1 >> 0xc);
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
 // line 1428, offset 0x800a6130
	/* begin block 1 */
		// Start line: 1429
		// Start offset: 0x800A6130
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1436
			// Start offset: 0x800A6158
		/* end block 1.1 */
		// End offset: 0x800A61C8
		// End Line: 1474
	/* end block 1 */
	// End offset: 0x800A6208
	// End Line: 1485

	/* begin block 2 */
		// Start line: 3046
	/* end block 2 */
	// End Line: 3047

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
    G2EmulationSetInterpController_Vector(instance,0xe,0xe,&local_18,3,0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSwitchVAnimCharacterGroup(struct _Instance *instance /*$s3*/, int animGroup /*$s4*/, int *frame /*$a2*/, int *frames /*$a3*/)
 // line 1489, offset 0x800a621c
	/* begin block 1 */
		// Start line: 1490
		// Start offset: 0x800A621C
		// Variables:
	// 		int i; // $s0
	// 		int rc; // $v1
	// 		int temp[3]; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A62B8
	// End Line: 1503

	/* begin block 2 */
		// Start line: 3184
	/* end block 2 */
	// End Line: 3185

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razSwitchVAnimCharacterGroup(_Instance *instance,int animGroup,int *frame,int *frames)

{
  int frame_00;
  int section;
  int iVar1;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = DAT_800d0b5c;
  local_24 = DAT_800d0b60;
  local_20 = DAT_800d0b64;
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
 // line 1508, offset 0x800a62d8
	/* begin block 1 */
		// Start line: 1509
		// Start offset: 0x800A62D8
		// Variables:
	// 		int index; // $t0
	// 		int rc; // $v1
	/* end block 1 */
	// End offset: 0x800A6324
	// End Line: 1529

	/* begin block 2 */
		// Start line: 3228
	/* end block 2 */
	// End Line: 3229

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razSwitchVAnimGroup(_Instance *instance,int section,int animGroup,int frame,int frames)

{
  int iVar1;
  
  iVar1 = 1;
  if (DAT_800d5b2c != 0) {
    iVar1 = DAT_800d5b2c + -1;
    if (2 < iVar1) {
      iVar1 = 3;
    }
    razSwitchVAnim(instance,section,
                   (__VAnim *)(*(int *)(PlayerData + 0x18) + (animGroup + iVar1) * 8),frame,frames);
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnimCharacterSingle(struct _Instance *instance /*$s3*/, int anim /*$s4*/, int *frame /*$a2*/, int *frames /*$a3*/)
 // line 1534, offset 0x800a6334
	/* begin block 1 */
		// Start line: 1535
		// Start offset: 0x800A6334
		// Variables:
	// 		int i; // $s0
	// 		int temp[3]; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A63CC
	// End Line: 1547

	/* begin block 2 */
		// Start line: 3287
	/* end block 2 */
	// End Line: 3288

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSwitchVAnimCharacterSingle(_Instance *instance,int anim,int *frame,int *frames)

{
  int frame_00;
  int section;
  int iVar1;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = DAT_800d0b5c;
  local_24 = DAT_800d0b60;
  local_20 = DAT_800d0b64;
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
 // line 1550, offset 0x800a63ec
	/* begin block 1 */
		// Start line: 1551
		// Start offset: 0x800A63EC
	/* end block 1 */
	// End offset: 0x800A63EC
	// End Line: 1551

	/* begin block 2 */
		// Start line: 3324
	/* end block 2 */
	// End Line: 3325

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSwitchVAnimSingle(_Instance *instance,int section,int anim,int frame,int frames)

{
  razSwitchVAnim(instance,section,(__VAnim *)(*(int *)(PlayerData + 0x1c) + anim * 8),frame,frames);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnim(struct _Instance *instance /*$a0*/, int section /*$a1*/, struct __VAnim *vAnim /*$v1*/, int frame /*$a3*/, int frames /*stack 16*/)
 // line 1560, offset 0x800a6420
	/* begin block 1 */
		// Start line: 3347
	/* end block 1 */
	// End Line: 3348

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
 // line 1588, offset 0x800a64ec
	/* begin block 1 */
		// Start line: 1589
		// Start offset: 0x800A64EC
		// Variables:
	// 		int rc; // $s2
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 1614
			// Start offset: 0x800A65B4
			// Variables:
		// 		struct __VAnim *vanim; // $s1
		/* end block 1.1 */
		// End offset: 0x800A661C
		// End Line: 1625
	/* end block 1 */
	// End offset: 0x800A6640
	// End Line: 1636

	/* begin block 2 */
		// Start line: 3403
	/* end block 2 */
	// End Line: 3404

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
    sVar2 = *(short *)(DAT_800d5ce4 + 1);
    sVar1 = 1;
  }
  else {
    if (mode < 0x8000001) {
      if ((undefined *)mode != &DAT_00100015) goto LAB_800a6594;
      sVar2 = *(short *)(DAT_800d5ce4 + 1);
      sVar1 = 2;
    }
    else {
      if (mode != 0x8000003) goto LAB_800a6594;
      sVar2 = *(short *)(DAT_800d5ce4 + 1);
      sVar1 = 3;
    }
  }
  if (sVar2 == sVar1) {
    iVar4 = 1;
  }
LAB_800a6594:
  if (iVar4 != 0) {
    p_Var3 = *(__VAnim **)&DAT_800d5ce4->mode;
    if (p_Var3 == (__VAnim *)0x0) {
      G2Anim_SetSpeedAdjustment(&instance->anim,0x1000);
      DAT_800d5ce4 = (__VAnim *)0x0;
      iVar4 = 0;
    }
    else {
      vAnim = *(__VAnim **)p_Var3;
      section = 0;
      DAT_800d5ce4 = p_Var3;
      if (vAnim != (__VAnim *)0x0) {
        do {
          razSwitchVAnim(instance,section,vAnim,-1,-1);
          section = section + 1;
          G2Anim_SetSpeedAdjustment(&instance->anim,(int)*(short *)((int)(DAT_800d5ce4 + 1) + 4));
        } while (section < 3);
        if (*(short *)(DAT_800d5ce4 + 1) == 2) {
          SetTimer((int)*(short *)((int)(DAT_800d5ce4 + 1) + 2));
        }
      }
    }
  }
  return iVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchStringAnimation(struct _Instance *instance /*$s2*/, int anim /*$a1*/)
 // line 1640, offset 0x800a6664
	/* begin block 1 */
		// Start line: 1641
		// Start offset: 0x800A6664
		// Variables:
	// 		struct __VAnim *vanim; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x800A6710
	// End Line: 1657

	/* begin block 2 */
		// Start line: 3515
	/* end block 2 */
	// End Line: 3516

	/* begin block 3 */
		// Start line: 3519
	/* end block 3 */
	// End Line: 3520

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSwitchStringAnimation(_Instance *instance,int anim)

{
  int section;
  __VAnim *vAnim;
  
  DAT_800d5ce4 = *(__VAnim **)(anim * 4 + *(int *)(PlayerData + 0x20));
  vAnim = *(__VAnim **)DAT_800d5ce4;
  if (vAnim != (__VAnim *)0x0) {
    section = 0;
    do {
      razSwitchVAnim(instance,section,vAnim,-1,-1);
      section = section + 1;
    } while (section < 3);
    G2Anim_SetSpeedAdjustment(&instance->anim,(int)*(short *)((__VAnim **)DAT_800d5ce4 + 3));
    if (*(short *)((__VAnim **)DAT_800d5ce4 + 2) == 2) {
      SetTimer((int)*(short *)((int)DAT_800d5ce4 + 10));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckStringAnimation(struct _Instance *instance /*$s1*/, int mode /*$a1*/)
 // line 1660, offset 0x800a672c
	/* begin block 1 */
		// Start line: 1661
		// Start offset: 0x800A672C
		// Variables:
	// 		int rc; // $s0
	/* end block 1 */
	// End offset: 0x800A6774
	// End Line: 1671

	/* begin block 2 */
		// Start line: 3565
	/* end block 2 */
	// End Line: 3566

	/* begin block 3 */
		// Start line: 3568
	/* end block 3 */
	// End Line: 3569

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int CheckStringAnimation(_Instance *instance,int mode)

{
  int iVar1;
  
  iVar1 = 0;
  if ((DAT_800d5ce4 == 0) || (iVar1 = razProcessSAnim(instance,mode), DAT_800d5ce4 == 0)) {
    INSTANCE_Post(instance,0x100000,0);
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razInitCollision(struct _Instance *instance /*$a0*/)
 // line 1693, offset 0x800a678c
	/* begin block 1 */
		// Start line: 1695
		// Start offset: 0x800A678C
		// Variables:
	// 		struct _HModel *hModel; // $v1
	// 		struct _HPrim *hprim; // $v0
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x800A67DC
	// End Line: 1724

	/* begin block 2 */
		// Start line: 3382
	/* end block 2 */
	// End Line: 3383

	/* begin block 3 */
		// Start line: 3614
	/* end block 3 */
	// End Line: 3615

	/* begin block 4 */
		// Start line: 3618
	/* end block 4 */
	// End Line: 3619

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

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
 // line 1725, offset 0x800a67e4
	/* begin block 1 */
		// Start line: 3683
	/* end block 1 */
	// End Line: 3684

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razLaunchBubbles(int segments,int count,int type)

{
  if ((segments & 1U) != 0) {
    TrailWaterFX(DAT_800d20f8,0x20,count,type);
    TrailWaterFX(DAT_800d20f8,0x2a,count,type);
  }
  if ((segments & 2U) != 0) {
    TrailWaterFX(DAT_800d20f8,8,count,type);
    TrailWaterFX(DAT_800d20f8,0xc,count,type);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetCowlNoDraw(int mode /*$t0*/)
 // line 1738, offset 0x800a687c
	/* begin block 1 */
		// Start line: 1739
		// Start offset: 0x800A687C
	/* end block 1 */
	// End offset: 0x800A692C
	// End Line: 1748

	/* begin block 2 */
		// Start line: 3709
	/* end block 2 */
	// End Line: 3710

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSetCowlNoDraw(int mode)

{
  byte bVar1;
  int iVar2;
  ushort *puVar3;
  
  puVar3 = cowlList;
  do {
    if (mode == 0) {
      iVar2 = (uint)*puVar3 * 0xc +
              *(int *)(*(int *)((int)*(short *)(DAT_800d20f8 + 0x122) * 4 +
                               *(int *)(*(int *)(DAT_800d20f8 + 0x1c) + 0xc)) + 0x14);
      bVar1 = *(byte *)(iVar2 + 7) & 0xef;
    }
    else {
      iVar2 = (uint)*puVar3 * 0xc +
              *(int *)(*(int *)((int)*(short *)(DAT_800d20f8 + 0x122) * 4 +
                               *(int *)(*(int *)(DAT_800d20f8 + 0x1c) + 0xc)) + 0x14);
      bVar1 = *(byte *)(iVar2 + 7) | 0x10;
    }
    *(byte *)(iVar2 + 7) = bVar1;
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < -0x7ff2f5da);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAttachControllers()
 // line 1750, offset 0x800a6934
	/* begin block 1 */
		// Start line: 1751
		// Start offset: 0x800A6934
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x800A698C
	// End Line: 1758

	/* begin block 2 */
		// Start line: 3737
	/* end block 2 */
	// End Line: 3738

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razAttachControllers(void)

{
  ushort *puVar1;
  bool bVar2;
  ushort *puVar3;
  __razController *p_Var4;
  int iVar5;
  
  p_Var4 = controllerList;
  iVar5 = 1;
  do {
    G2Anim_AttachControllerToSeg
              ((_G2Anim_Type *)(DAT_800d20f8 + 0x1c4),(uint)p_Var4->segment,(uint)p_Var4->type);
    puVar3 = &p_Var4->segment;
    puVar1 = &p_Var4->type;
    p_Var4 = p_Var4 + 1;
    G2Anim_DisableController((_G2Anim_Type *)(DAT_800d20f8 + 0x1c4),(uint)*puVar3,(uint)*puVar1);
    bVar2 = iVar5 < 0x18;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPlayerEvent()
 // line 1760, offset 0x800a69a0
	/* begin block 1 */
		// Start line: 1761
		// Start offset: 0x800A69A0
		// Variables:
	// 		void (*process)(); // $s0
	// 		int message; // stack offset -16
	// 		int data; // stack offset -12

		/* begin block 1.1 */
			// Start line: 1785
			// Start offset: 0x800A6A60
		/* end block 1.1 */
		// End offset: 0x800A6A9C
		// End Line: 1794
	/* end block 1 */
	// End offset: 0x800A6C7C
	// End Line: 1858

	/* begin block 2 */
		// Start line: 3767
	/* end block 2 */
	// End Line: 3768

	/* begin block 3 */
		// Start line: 3774
	/* end block 3 */
	// End Line: 3775

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSetPlayerEvent(void)

{
  code *pcVar1;
  ulong uVar2;
  _Instance *p_Var3;
  int iVar4;
  int local_10;
  int local_c;
  
  pcVar1 = DAT_800d5750;
  local_10 = 0;
  local_c = 0;
  if ((((DAT_800d5b1c & 1) != 0) && (DAT_800d5b2c != 3)) && (DAT_800d5750 == StateHandlerIdle)) {
    DAT_800d5ce8 = DAT_800d5ce8 | 1;
  }
  if ((((DAT_800d5b1c & 4) != 0) && (DAT_800d5b2c != 3)) && (DAT_800d5750 == StateHandlerCrouch)) {
    DAT_800d5ce8 = DAT_800d5ce8 | 2;
  }
  if ((((DAT_800d5b1c & 8) != 0) && (DAT_800d5b2c != 3)) && (DAT_800d5750 == StateHandlerIdle)) {
    uVar2 = INSTANCE_Query(*(_Instance **)(DAT_800d5b18 + 0x18),4);
    if (uVar2 == 9) {
      DAT_800d5ce8 = DAT_800d5ce8 | 8;
    }
    else {
      DAT_800d5ce8 = DAT_800d5ce8 | 4;
    }
  }
  if (((((DAT_800d5b1c & 0x20) != 0) && (p_Var3 = razGetHeldItem(), p_Var3 == (_Instance *)0x0)) &&
      (DAT_800d5b78 == 1)) &&
     (((pcVar1 == StateHandlerIdle || (pcVar1 == StateHandlerStartMove)) ||
      ((((pcVar1 == StateHandlerMove ||
         ((pcVar1 == StateHandlerJump || (pcVar1 == StateHandlerFall)))) ||
        (pcVar1 == StateHandlerSwim)) || (pcVar1 == StateHandlerAutoFace)))))) {
    DAT_800d5ce8 = DAT_800d5ce8 | 0x10;
  }
  if ((DAT_800d5b1c & 0x40) != 0) {
    DAT_800d5ce8 = DAT_800d5ce8 | 0x20;
  }
  iVar4 = StateHandlerDecodeHold(&local_10,&local_c);
  if ((iVar4 != 0) && (local_c != 0)) {
    if (local_10 == 0x1000002) {
      DAT_800d5ce8 = DAT_800d5ce8 | 0x40;
    }
    if (local_10 == 0x100000a) {
      DAT_800d5ce8 = DAT_800d5ce8 | 0x80;
    }
    if (local_10 == 0x1000018) {
      DAT_800d5ce8 = DAT_800d5ce8 | 0x100;
    }
  }
  if (((DAT_800d5aa4 & 0x20000) != 0) && (DAT_800d5b2c - 1U < 3)) {
    DAT_800d5ce8 = DAT_800d5ce8 | 0x200;
  }
  if (local_10 == 0x80000) {
    DAT_800d5ce8 = DAT_800d5ce8 | 0x400;
  }
  if ((DAT_800d5b1c & 0x4000) != 0) {
    DAT_800d5ce8 = DAT_800d5ce8 | 0x800;
  }
  if ((DAT_800d5ae0 & 0x40) != 0) {
    DAT_800d5ce8 = DAT_800d5ce8 | 0x2000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razClearPlayerEvent()
 // line 1860, offset 0x800a6c8c
	/* begin block 1 */
		// Start line: 3978
	/* end block 1 */
	// End Line: 3979

	/* begin block 2 */
		// Start line: 3980
	/* end block 2 */
	// End Line: 3981

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razClearPlayerEvent(void)

{
  if ((ControlFlag & 0x100000U) != 0) {
    DAT_800d5ce8 = DAT_800d5ce8 & 0x2000;
    return;
  }
  DAT_800d5ce8 = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPlayerEventHistory(unsigned long event /*$a0*/)
 // line 1869, offset 0x800a6cc4
	/* begin block 1 */
		// Start line: 3996
	/* end block 1 */
	// End Line: 3997

	/* begin block 2 */
		// Start line: 3997
	/* end block 2 */
	// End Line: 3998

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSetPlayerEventHistory(ulong event)

{
  DAT_800d5cec = DAT_800d5cec | event;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSideMoveSpiderCheck(struct _Instance *instance /*$s2*/, int x /*$a1*/)
 // line 1876, offset 0x800a6cdc
	/* begin block 1 */
		// Start line: 1877
		// Start offset: 0x800A6CDC
		// Variables:
	// 		struct SVECTOR startVec; // stack offset -32
	// 		struct SVECTOR endVec; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A6D90
	// End Line: 1896

	/* begin block 2 */
		// Start line: 4010
	/* end block 2 */
	// End Line: 4011

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razSideMoveSpiderCheck(_Instance *instance,int x)

{
  uint uVar1;
  short x_00;
  
  x_00 = (short)x;
  PHYSICS_GenericLineCheckSetup(x_00,0,0xc0,0xe0);
  PHYSICS_GenericLineCheckSetup(x_00,-0x140,0xc0,0xe8);
  uVar1 = PHYSICS_CheckForValidMove(instance,0xe0,0xe8,0);
  if ((uVar1 & 1) == 0) {
    uVar1 = 1;
  }
  else {
    PHYSICS_GenericLineCheckSetup(x_00,0,0,0xe0);
    PHYSICS_GenericLineCheckSetup(x_00,-0x140,0,0xe8);
    uVar1 = PHYSICS_CheckForValidMove(instance,0xe0,0xe8,0);
    uVar1 = uVar1 & 1 ^ 1;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ RAZIEL_QueryEngagedInstance(int index /*$a0*/)
 // line 1913, offset 0x800a6da8
	/* begin block 1 */
		// Start line: 4100
	/* end block 1 */
	// End Line: 4101

	/* begin block 2 */
		// Start line: 4102
	/* end block 2 */
	// End Line: 4103

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

_Instance * RAZIEL_QueryEngagedInstance(int index)

{
  if ((DAT_800d5b1c & 1 << (index & 0x1fU)) == 0) {
    return (_Instance *)0x0;
  }
  return *(_Instance **)(index * 8 + DAT_800d5b18);
}



// decompiled code
// original method signature: 
// int /*$ra*/ razUpdateSoundRamp(struct _Instance *instance /*$a0*/, struct _SoundRamp *sound /*$s0*/)
 // line 1926, offset 0x800a6de0
	/* begin block 1 */
		// Start line: 1927
		// Start offset: 0x800A6DE0
		// Variables:
	// 		int volume; // $s1
	// 		int time; // $t0

		/* begin block 1.1 */
			// Start line: 1942
			// Start offset: 0x800A6E44
			// Variables:
		// 		int startPitch; // $v1
		// 		int endPitch; // $v0
		// 		int startVolume; // $a1
		// 		int endVolume; // $v0
		/* end block 1.1 */
		// End offset: 0x800A6ECC
		// End Line: 1957
	/* end block 1 */
	// End offset: 0x800A6ECC
	// End Line: 1960

	/* begin block 2 */
		// Start line: 4122
	/* end block 2 */
	// End Line: 4123

	/* begin block 3 */
		// Start line: 4129
	/* end block 3 */
	// End Line: 4130

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razUpdateSoundRamp(_Instance *instance,_SoundRamp *sound)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int maxVolume;
  
  maxVolume = 0;
  if (sound->soundHandle != 0) {
    iVar3 = sound->soundTotalTime;
    maxVolume = sound->soundTimer + DAT_800d2314;
    sound->soundTimer = maxVolume;
    if (iVar3 < maxVolume) {
      sound->soundTimer = iVar3;
    }
    maxVolume = 0;
    if (iVar3 != 0) {
      iVar2 = sound->soundTimer;
      maxVolume = 0;
      if (iVar2 <= iVar3) {
        maxVolume = (int)sound->soundStartVolume +
                    (((int)sound->soundEndVolume - (int)sound->soundStartVolume) * iVar2) / iVar3;
        uVar1 = SOUND_Update3dSound(&instance->position,sound->soundHandle,
                                    (int)sound->soundStartPitch +
                                    (((int)sound->soundEndPitch - (int)sound->soundStartPitch) *
                                    iVar2) / iVar3,maxVolume,sound->soundDistance);
        if (uVar1 == 0) {
          SndEndLoop(sound->soundHandle);
          sound->soundHandle = 0;
        }
      }
    }
  }
  return maxVolume;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetupSoundRamp(struct _Instance *instance /*$a0*/, struct _SoundRamp *sound /*$s0*/, int sfx /*$a1*/, int startPitch /*$s2*/, int endPitch /*stack 16*/, int startVolume /*stack 20*/, int endVolume /*stack 24*/, int timer /*stack 28*/, int distance /*stack 32*/)
 // line 1966, offset 0x800a6ee4
	/* begin block 1 */
		// Start line: 4220
	/* end block 1 */
	// End Line: 4221

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void razSetupSoundRamp(_Instance *instance,_SoundRamp *sound,int sfx,int startPitch,int endPitch,
                      int startVolume,int endVolume,int timer,int distance)

{
  ulong uVar1;
  
  if (sound->soundHandle == 0) {
    uVar1 = SOUND_Play3dSound(&instance->position,sfx,startPitch,startVolume,distance);
    sound->soundHandle = uVar1;
  }
  if (timer == 0) {
    sound->soundHandle = 0;
  }
  sound->soundStartPitch = (short)startPitch;
  sound->soundStartVolume = (short)startVolume;
  sound->soundEndPitch = (short)endPitch;
  sound->soundDistance = distance;
  sound->soundTotalTime = timer;
  sound->soundTimer = 0;
  sound->soundEndVolume = (short)endVolume;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_SetInteractiveMusic(int modifier /*$a0*/, int action /*$a1*/)
 // line 1990, offset 0x800a6f88
	/* begin block 1 */
		// Start line: 1991
		// Start offset: 0x800A6F88
		// Variables:
	// 		int soundFlag; // $s0
	/* end block 1 */
	// End offset: 0x800A6FF4
	// End Line: 2010

	/* begin block 2 */
		// Start line: 4275
	/* end block 2 */
	// End Line: 4276

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void RAZIEL_SetInteractiveMusic(int modifier,int action)

{
  uint uVar1;
  
  uVar1 = 1 << (modifier & 0x1fU);
  if (action == 0) {
    if ((DAT_800d5c94 & uVar1) != 0) {
      SOUND_ResetMusicModifier(modifier);
    }
    DAT_800d5c94 = DAT_800d5c94 & ~uVar1;
  }
  else {
    if ((DAT_800d5c94 & uVar1) == 0) {
      SOUND_SetMusicModifier(modifier);
    }
    DAT_800d5c94 = DAT_800d5c94 | uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_StartNewGame()
 // line 2016, offset 0x800a7004
	/* begin block 1 */
		// Start line: 4028
	/* end block 1 */
	// End Line: 4029

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

void RAZIEL_StartNewGame(void)

{
  memset();
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razInBaseArea(char *name /*$s1*/, int length /*$s0*/)
 // line 2025, offset 0x800a7030
	/* begin block 1 */
		// Start line: 2026
		// Start offset: 0x800A7030
		// Variables:
	// 		char string[9]; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A707C
	// End Line: 2039

	/* begin block 2 */
		// Start line: 4345
	/* end block 2 */
	// End Line: 4346

/* File: C:\kain2\game\RAZIEL\RAZLIB.C */

int razInBaseArea(char *name,int length)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  undefined auStack32 [16];
  
  pcVar1 = strcpy();
  if (pcVar1 == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    auStack32[length] = 0;
    iVar3 = strcmp();
    uVar2 = (uint)(iVar3 == 0);
  }
  return uVar2;
}





