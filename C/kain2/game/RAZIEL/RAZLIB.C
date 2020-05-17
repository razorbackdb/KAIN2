#include "THISDUST.H"
#include "RAZLIB.H"


// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYMoveRot(struct _Instance *dest /*$s3*/, short distance /*$a1*/, struct _Position *position /*$s4*/, struct _Rotation *rotation /*$s2*/, int extraZ /*stack 16*/)
 // line 12, offset 0x800a505c
	/* begin block 1 */
		// Start line: 13
		// Start offset: 0x800A505C
		// Variables:
	// 		struct SVECTOR d; // stack offset -72
	// 		struct SVECTOR dd; // stack offset -64
	// 		struct MATRIX mat; // stack offset -56
	/* end block 1 */
	// End offset: 0x800A505C
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
  MATRIX MStack56;
  
  local_46 = -distance;
  local_48 = 0;
  local_44 = 0;
  uVar1 = INSTANCE_Query(dest,7);
  rotation->z = *(short *)(uVar1 + 4) + (short)extraZ + 0x800;
  MATH3D_SetUnityMatrix(&MStack56);
  RotMatrixZ((int)rotation->z,(uint *)&MStack56);
  ApplyMatrixSV(&MStack56,&local_48,&local_40);
  position->x = (dest->position).x + local_40;
  position->y = (dest->position).y + local_3e;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotMove(struct _Instance *dest /*$s1*/, short distance /*$a1*/, struct _Position *position /*$s2*/, struct _Rotation *rotation /*$s4*/, int extraZ /*stack 16*/)
 // line 54, offset 0x800a5120
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800A5120
		// Variables:
	// 		struct SVECTOR d; // stack offset -88
	// 		struct SVECTOR dd; // stack offset -80
	// 		struct SVECTOR rot; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64
	/* end block 1 */
	// End offset: 0x800A5120
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
  ushort auStack72 [2];
  short local_44;
  uint auStack64 [8];
  
  memset(auStack72,0,8);
  local_44 = MATH3D_AngleFromPosToPos(position,&dest->position);
  local_44 = local_44 + (short)extraZ;
  rotation->z = local_44;
  RotMatrix(auStack72,auStack64);
  local_58 = 0;
  local_54 = 0;
  local_56 = distance;
  ApplyMatrixSV(auStack64,&local_58,&local_50);
  position->x = (dest->position).x + local_50;
  position->y = (dest->position).y + local_4e;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotMoveInterp(struct _Instance *source /*$s1*/, struct _Instance *dest /*$a1*/, short distance /*$a2*/, unsigned char segNumber /*$s0*/, int Frames /*stack 16*/, int extraZ /*stack 20*/)
 // line 86, offset 0x800a51f8
	/* begin block 1 */
		// Start line: 87
		// Start offset: 0x800A51F8
		// Variables:
	// 		struct _Position position; // stack offset -40
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _G2SVector3_Type v; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A51F8
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
 // line 114, offset 0x800a52ec
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
 // line 195, offset 0x800a5318
	/* begin block 1 */
		// Start line: 196
		// Start offset: 0x800A5318
		// Variables:
	// 		int i; // $s0
	// 		int j; // $s2
	// 		int k; // $a2
	// 		int Total; // $s1
	// 		int outer; // stack offset -32
	// 		int rc; // $s3
	// 		struct _SVector point; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A5410
	// End Line: 243

	/* begin block 2 */
		// Start line: 390
	/* end block 2 */
	// End Line: 391

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
 // line 247, offset 0x800a542c
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x800A542C
		// Variables:
	// 		int tx; // $s0
	// 		int tz; // $s2
	// 		struct _G2SVector3_Type Rot; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A54B4
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
 // line 285, offset 0x800a55fc
	/* begin block 1 */
		// Start line: 640
	/* end block 1 */
	// End Line: 641

	/* begin block 2 */
		// Start line: 644
	/* end block 2 */
	// End Line: 645

void razSetFadeEffect(short source,short dest,int steps)

{
  Raziel.effectsFlags = Raziel.effectsFlags | 3;
  Raziel.effectsFadeSource = source;
  Raziel.effectsFadeDest = dest;
  Raziel.effectsFadeStep = steps;
  Raziel.effectsFadeSteps = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razPlaneShift(struct _Instance *instance /*$a0*/)
 // line 302, offset 0x800a5620
	/* begin block 1 */
		// Start line: 672
	/* end block 1 */
	// End Line: 673

	/* begin block 2 */
		// Start line: 679
	/* end block 2 */
	// End Line: 680

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
 // line 320, offset 0x800a567c
	/* begin block 1 */
		// Start line: 321
		// Start offset: 0x800A567C
		// Variables:
	// 		struct _Instance *inst; // $v0
	/* end block 1 */
	// End offset: 0x800A577C
	// End Line: 352

	/* begin block 2 */
		// Start line: 715
	/* end block 2 */
	// End Line: 716

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razSpectralShift(void)

{
  _Instance *Inst;
  int iVar1;
  undefined **ppuVar2;
  
  if (((gameTrackerX.streamFlags & 0x40000U) == 0) && (Raziel.CurrentPlane == 1)) {
    Inst = razGetHeldItem();
    if (Inst != (_Instance *)0x0) {
      INSTANCE_Post(Inst,0x800008,4);
      razSetFadeEffect(0x1000,0,0x100);
    }
    (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 | 0x8000000;
    INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00100014,0);
    iVar1 = GetMaxHealth();
    if (Raziel.HitPoints == iVar1) {
      ppuVar2 = (undefined **)0x186a0;
    }
    else {
      ppuVar2 = &PTR_00014586;
    }
    Raziel.CurrentPlane = 2;
    Raziel.HitPoints = (int)ppuVar2;
    razReaverOn();
    if (gameTrackerX.gameData.asmData.MorphType == 0) {
      MORPH_ToggleMorph();
      if ((Raziel.State.SectionList[0].Process != StateHandlerGlyphs) &&
         (Raziel.State.SectionList[0].Process != StateHandlerPuppetShow)) {
        INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00040005,0);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razMaterialShift()
 // line 355, offset 0x800a578c
	/* begin block 1 */
		// Start line: 787
	/* end block 1 */
	// End Line: 788

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razMaterialShift(void)

{
  if ((Raziel.CurrentPlane == 2) && (Raziel.HitPoints == 100000)) {
    Raziel.CurrentPlane = 1;
    (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 & 0xf7ffffff;
    Raziel.HitPoints = GetMaxHealth();
    Raziel.DamageFrequency = 0;
    razReaverOn();
    if (gameTrackerX.gameData.asmData.MorphType != 0) {
      MORPH_ToggleMorph();
      if ((Raziel.State.SectionList[0].Process != StateHandlerGlyphs) &&
         (Raziel.State.SectionList[0].Process != StateHandlerPuppetShow)) {
        INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00040005,0);
      }
      if (Raziel.Senses.Portal != (_Instance *)0x0) {
        FX_EndInstanceParticleEffects(Raziel.Senses.Portal);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ RAZIEL_OkToShift()
 // line 378, offset 0x800a5854
	/* begin block 1 */
		// Start line: 834
	/* end block 1 */
	// End Line: 835

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
// int /*$ra*/ razPickupAndGrab(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/)
 // line 404, offset 0x800a58e8
	/* begin block 1 */
		// Start line: 405
		// Start offset: 0x800A58E8

		/* begin block 1.1 */
			// Start line: 408
			// Start offset: 0x800A5944
			// Variables:
		// 		int index; // $a2

			/* begin block 1.1.1 */
				// Start line: 422
				// Start offset: 0x800A5974
				// Variables:
			// 		struct evObjectData *objData; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800A5A40
			// End Line: 443
		/* end block 1.1 */
		// End offset: 0x800A5ADC
		// End Line: 455
	/* end block 1 */
	// End offset: 0x800A5AE0
	// End Line: 459

	/* begin block 2 */
		// Start line: 886
	/* end block 2 */
	// End Line: 887

	/* begin block 3 */
		// Start line: 888
	/* end block 3 */
	// End Line: 889

int razPickupAndGrab(__CharacterState *In,int CurrentSection)

{
  _Instance *Inst;
  int iVar1;
  int Data;
  ulong uVar2;
  
  if ((Raziel.Senses.EngagedMask & 0x20) == 0) {
    iVar1 = 1;
  }
  else {
    Inst = razGetHeldItem();
    iVar1 = 1;
    if ((((Inst == (_Instance *)0x0) && (Raziel.CurrentPlane == 1)) &&
        (iVar1 = 1, (Raziel.Senses.Flags & 0x80U) == 0)) && (iVar1 = 0, CurrentSection == 1)) {
      Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
      if (Inst != (_Instance *)0x0) {
        INSTANCE_Query(Inst,0);
      }
      Data = SetObjectData(0,0,8,In->CharacterInstance,1);
      INSTANCE_Post(Raziel.Senses.EngagedList[5].instance,0x80002e,Data);
      iVar1 = 0;
      if (*(short *)(Data + 6) == 0) {
        Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
        if (Inst != (_Instance *)0x0) {
          INSTANCE_Post(Inst,(int)&DAT_0100001b,0);
          INSTANCE_UnlinkFromParent(Raziel.Senses.EngagedList[5].instance);
        }
        Data = SetObjectData(0,0,8,In->CharacterInstance,0x31);
        INSTANCE_Post(Raziel.Senses.EngagedList[5].instance,0x800002,Data);
        iVar1 = 0;
        if (*(short *)(Data + 6) == 0) {
          Raziel.Senses.Flags = Raziel.Senses.Flags | 0x80;
          razReaverOff();
          In->SectionList[1].Data1 = 0;
          uVar2 = INSTANCE_Query(Raziel.Senses.EngagedList[5].instance,4);
          iVar1 = 0;
          if ((Raziel.Mode & 0x40000U) == 0) {
            G2EmulationSwitchAnimation(In,1,(uint)""[uVar2],0,3,1);
            Raziel.returnState = (_func_60 *)In->SectionList[1].Process;
            StateSwitchStateData(In,1,StateHandlerPickupObject,0);
            iVar1 = 0;
          }
        }
      }
    }
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razZeroAxis(long *x /*$s1*/, long *y /*$s2*/, int radius /*$s0*/)
 // line 466, offset 0x800a5af8
	/* begin block 1 */
		// Start line: 467
		// Start offset: 0x800A5AF8
		// Variables:
	// 		unsigned long distance; // $v0
	/* end block 1 */
	// End offset: 0x800A5B40
	// End Line: 499

	/* begin block 2 */
		// Start line: 1013
	/* end block 2 */
	// End Line: 1014

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
 // line 503, offset 0x800a5b58
	/* begin block 1 */
		// Start line: 504
		// Start offset: 0x800A5B58
		// Variables:
	// 		long adjustment; // $s0

		/* begin block 1.1 */
			// Start line: 504
			// Start offset: 0x800A5B58
			// Variables:
		// 		int data; // $v1
		/* end block 1.1 */
		// End offset: 0x800A5BD4
		// End Line: 525
	/* end block 1 */
	// End offset: 0x800A5BD4
	// End Line: 532

	/* begin block 2 */
		// Start line: 1089
	/* end block 2 */
	// End Line: 1090

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
 // line 553, offset 0x800a5bf4
	/* begin block 1 */
		// Start line: 554
		// Start offset: 0x800A5BF4
	/* end block 1 */
	// End offset: 0x800A5BF4
	// End Line: 554

	/* begin block 2 */
		// Start line: 1197
	/* end block 2 */
	// End Line: 1198

void razLaunchForce(_Instance *instance)

{
  PHYSOB_BirthProjectile(instance,0x31,(uint)Raziel.Abilities._1_1_ & 1);
  Raziel.effectsFlags = Raziel.effectsFlags | 4;
  razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0xc,(int)PlayerData->forceMinPitch,
                    (int)PlayerData->forceMaxPitch,(int)PlayerData->forceMinVolume,
                    (int)PlayerData->forceMaxVolume,PlayerData->forceRampTime * 0x1e,
                    (int)&DAT_00002710);
  Raziel.soundTimerNext = 0;
  Raziel.soundTimerData = 0;
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ razGetHeldItem()
 // line 577, offset 0x800a5c84
	/* begin block 1 */
		// Start line: 579
		// Start offset: 0x800A5C84
		// Variables:
	// 		struct _Instance *instance; // $v0
	/* end block 1 */
	// End offset: 0x800A5CB4
	// End Line: 601

	/* begin block 2 */
		// Start line: 1256
	/* end block 2 */
	// End Line: 1257

	/* begin block 3 */
		// Start line: 1257
	/* end block 3 */
	// End Line: 1258

	/* begin block 4 */
		// Start line: 1259
	/* end block 4 */
	// End Line: 1260

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
 // line 605, offset 0x800a5cbc
	/* begin block 1 */
		// Start line: 606
		// Start offset: 0x800A5CBC
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x800A5D0C
	// End Line: 623

	/* begin block 2 */
		// Start line: 1314
	/* end block 2 */
	// End Line: 1315

/* WARNING: Unknown calling convention yet parameter storage is locked */

_Instance * razGetHeldWeapon(void)

{
  _Instance *Inst;
  ulong uVar1;
  
  Inst = razGetHeldItem();
  if (Inst == (_Instance *)0x0) {
    Inst = (_Instance *)0x0;
    if (Raziel.Senses.heldClass != 0) {
      Inst = Raziel.soulReaver;
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
 // line 626, offset 0x800a5d1c
	/* begin block 1 */
		// Start line: 1356
	/* end block 1 */
	// End Line: 1357

	/* begin block 2 */
		// Start line: 1357
	/* end block 2 */
	// End Line: 1358

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razReaverBladeOff(void)

{
  if (Raziel.soulReaver != (_Instance *)0x0) {
    INSTANCE_Post(Raziel.soulReaver,0x800109,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverBladeOn()
 // line 634, offset 0x800a5d4c
	/* begin block 1 */
		// Start line: 1373
	/* end block 1 */
	// End Line: 1374

	/* begin block 2 */
		// Start line: 1374
	/* end block 2 */
	// End Line: 1375

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razReaverBladeOn(void)

{
  _Instance *p_Var1;
  
  if ((Raziel.soulReaver != (_Instance *)0x0) &&
     (p_Var1 = razGetHeldItem(), p_Var1 == (_Instance *)0x0)) {
    INSTANCE_Post(Raziel.soulReaver,0x800108,0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razReaverOff()
 // line 644, offset 0x800a5d8c
	/* begin block 1 */
		// Start line: 645
		// Start offset: 0x800A5D8C

		/* begin block 1.1 */
			// Start line: 648
			// Start offset: 0x800A5DB0
			// Variables:
		// 		struct _Instance *heldWeapon; // $s0
		/* end block 1.1 */
		// End offset: 0x800A5E00
		// End Line: 656
	/* end block 1 */
	// End offset: 0x800A5E04
	// End Line: 658

	/* begin block 2 */
		// Start line: 1394
	/* end block 2 */
	// End Line: 1395

	/* begin block 3 */
		// Start line: 1396
	/* end block 3 */
	// End Line: 1397

/* WARNING: Unknown calling convention yet parameter storage is locked */

int razReaverOff(void)

{
  int iVar1;
  _Instance *p_Var2;
  ulong uVar3;
  
  if (Raziel.soulReaver == (_Instance *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    if (Raziel.Senses.heldClass == 0x1000) {
      p_Var2 = razGetHeldWeapon();
      uVar3 = INSTANCE_Query(Raziel.soulReaver,0x28);
      if ((uVar3 & 1) != 0) {
        INSTANCE_Post(Raziel.soulReaver,0x800101,0);
      }
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
 // line 661, offset 0x800a5e14
	/* begin block 1 */
		// Start line: 1430
	/* end block 1 */
	// End Line: 1431

	/* begin block 2 */
		// Start line: 1432
	/* end block 2 */
	// End Line: 1433

/* WARNING: Unknown calling convention yet parameter storage is locked */

int razReaverOn(void)

{
  _Instance *p_Var1;
  int iVar2;
  ulong uVar3;
  
  if (Raziel.soulReaver == (_Instance *)0x0) {
    iVar2 = 0;
  }
  else {
    p_Var1 = razGetHeldItem();
    iVar2 = 0;
    if ((p_Var1 == (_Instance *)0x0) &&
       ((iVar2 = GetMaxHealth(), Raziel.HitPoints == iVar2 || (iVar2 = 0, Raziel.CurrentPlane == 2))
       )) {
      uVar3 = INSTANCE_Query(Raziel.soulReaver,0x28);
      if ((uVar3 & 1) == 0) {
        INSTANCE_Post(Raziel.soulReaver,0x800100,0);
      }
      Raziel.Senses.heldClass = 0x1000;
      if ((Raziel.CurrentPlane == 2) && (Raziel.currentSoulReaver != 1)) {
        razReaverImbue(1);
      }
      iVar2 = 1;
      if ((Raziel.CurrentPlane == 1) && (iVar2 = 1, Raziel.currentSoulReaver == 1)) {
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
 // line 686, offset 0x800a5ef8
	/* begin block 1 */
		// Start line: 1485
	/* end block 1 */
	// End Line: 1486

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
 // line 714, offset 0x800a5fb4
	/* begin block 1 */
		// Start line: 1553
	/* end block 1 */
	// End Line: 1554

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
 // line 723, offset 0x800a5ff4
	/* begin block 1 */
		// Start line: 725
		// Start offset: 0x800A5FF4
		// Variables:
	// 		int rc; // $v0
	/* end block 1 */
	// End offset: 0x800A6010
	// End Line: 734

	/* begin block 2 */
		// Start line: 1576
	/* end block 2 */
	// End Line: 1577

	/* begin block 3 */
		// Start line: 1577
	/* end block 3 */
	// End Line: 1578

	/* begin block 4 */
		// Start line: 1579
	/* end block 4 */
	// End Line: 1580

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
// void /*$ra*/ razReaverScale(int scale /*$s1*/)
 // line 737, offset 0x800a6018
	/* begin block 1 */
		// Start line: 738
		// Start offset: 0x800A6018
		// Variables:
	// 		struct _Instance *Inst; // $s0
	/* end block 1 */
	// End offset: 0x800A606C
	// End Line: 749

	/* begin block 2 */
		// Start line: 1604
	/* end block 2 */
	// End Line: 1605

void razReaverScale(int scale)

{
  _Instance *Inst;
  ulong uVar1;
  
  Inst = razGetHeldWeapon();
  if (((Raziel.soulReaver != (_Instance *)0x0) && (Inst == Raziel.soulReaver)) &&
     (uVar1 = INSTANCE_Query(Inst,0x28), (uVar1 & 2) != 0)) {
    INSTANCE_Post(Inst,0x800107,scale);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razGetForwardNormal(struct _Instance *inst /*$a0*/, struct _Instance *target /*$a1*/)
 // line 752, offset 0x800a6080
	/* begin block 1 */
		// Start line: 753
		// Start offset: 0x800A6080
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -72
	// 		struct SVECTOR Old; // stack offset -24
	// 		struct SVECTOR New; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A6154
	// End Line: 786

	/* begin block 2 */
		// Start line: 1634
	/* end block 2 */
	// End Line: 1635

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
 // line 789, offset 0x800a6164
	/* begin block 1 */
		// Start line: 790
		// Start offset: 0x800A6164
		// Variables:
	// 		struct _Position a; // stack offset -24
	// 		struct _Position b; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A6164
	// End Line: 790

	/* begin block 2 */
		// Start line: 1717
	/* end block 2 */
	// End Line: 1718

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
 // line 803, offset 0x800a61b0
	/* begin block 1 */
		// Start line: 804
		// Start offset: 0x800A61B0
		// Variables:
	// 		struct SVECTOR d; // stack offset -88
	// 		struct SVECTOR dd; // stack offset -80
	// 		struct _Rotation rot; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64
	// 		struct _G2SVector3_Type v; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A6334
	// End Line: 855

	/* begin block 2 */
		// Start line: 1757
	/* end block 2 */
	// End Line: 1758

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
  short local_58;
  short local_56;
  undefined2 local_54;
  short local_50;
  short local_4e;
  _Rotation _Stack72;
  MATRIX MStack64;
  _G2SVector3_Type local_20;
  
  razGetForwardNormal(inst,target);
  razGetRotFromNormal(&Raziel.Senses.ForwardNormal,&_Stack72);
  iVar1 = (int)Raziel.Senses.ForwardNormal.z;
  if (iVar1 < 0) {
    iVar1 = -iVar1;
  }
  MATH3D_SetUnityMatrix(&MStack64);
  RotMatrixZ((int)_Stack72.z,(uint *)&MStack64);
  local_56 = 0x140 - (short)dist;
  local_54 = 0;
  local_58 = 0;
  ApplyMatrixSV(&MStack64,&local_58,&local_50);
  iVar4 = (uint)(ushort)(inst->position).x - (uint)(ushort)(target->position).x;
  iVar8 = iVar4 * 0x10000;
  iVar7 = iVar8 >> 0x10;
  local_58 = (short)iVar4;
  iVar4 = iVar7;
  if (iVar7 < 0) {
    iVar4 = -iVar7;
  }
  iVar5 = (uint)(ushort)(inst->position).y - (uint)(ushort)(target->position).y;
  local_56 = (short)iVar5;
  iVar5 = iVar5 * 0x10000;
  iVar6 = iVar5 >> 0x10;
  iVar2 = iVar6;
  if (iVar6 < 0) {
    iVar2 = -iVar6;
  }
  if (iVar4 < iVar2) {
    local_58 = (short)(iVar7 - (iVar8 >> 0x1f) >> 1);
    if (1000 < iVar1) {
      local_56 = local_4e;
    }
  }
  else {
    local_56 = (short)(iVar6 - (iVar5 >> 0x1f) >> 1);
    if (1000 < iVar1) {
      local_58 = local_50;
    }
  }
  local_20.x = local_50 + ((inst->position).x - local_58);
  local_20.y = local_4e + ((inst->position).y - local_56);
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
 // line 862, offset 0x800a6380
	/* begin block 1 */
		// Start line: 863
		// Start offset: 0x800A6380
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A63B4
	// End Line: 873

	/* begin block 2 */
		// Start line: 1895
	/* end block 2 */
	// End Line: 1896

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
 // line 879, offset 0x800a63f4
	/* begin block 1 */
		// Start line: 1937
	/* end block 1 */
	// End Line: 1938

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
 // line 889, offset 0x800a644c
	/* begin block 1 */
		// Start line: 890
		// Start offset: 0x800A644C
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -48
	// 		int switchType; // $s0
	// 		int frame; // $s1

		/* begin block 1.1 */
			// Start line: 1131
			// Start offset: 0x800A68CC
			// Variables:
		// 		int adjustment; // $s0
		/* end block 1.1 */
		// End offset: 0x800A69B8
		// End Line: 1152

		/* begin block 1.2 */
			// Start line: 1157
			// Start offset: 0x800A69D4
			// Variables:
		// 		struct _G2AnimSection_Type *animSectionA; // $s1
		// 		struct _G2AnimSection_Type *animSectionB; // $s2
		// 		struct _G2AnimKeylist_Type *keylist; // $s3
		// 		int keylistID; // $s5
		/* end block 1.2 */
		// End offset: 0x800A6A8C
		// End Line: 1179
	/* end block 1 */
	// End offset: 0x800A6A8C
	// End Line: 1187

	/* begin block 2 */
		// Start line: 1959
	/* end block 2 */
	// End Line: 1960

	/* begin block 3 */
		// Start line: 1968
	/* end block 3 */
	// End Line: 1969

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
  if (Raziel.Magnitude < 0xeb9) {
    if (Raziel.Magnitude - 0xae0U < 0x3d9) {
      uVar3 = ControlFlag & 0xffffdfff;
      uVar4 = ControlFlag & 0x20000000;
      ControlFlag = uVar3;
      if (uVar4 != 0) {
        razResetPauseTranslation(In->CharacterInstance);
      }
      frame = *Anim;
      if (frame == 0x3c) {
        if ((Raziel.passedMask & 0xf) != 0) {
          bVar7 = true;
        }
        if ((Raziel.passedMask & 8) != 0) {
          frame_00 = 7;
        }
        if ((Raziel.passedMask & 1) != 0) {
          frame_00 = 0xd;
        }
        uVar3 = Raziel.passedMask & 4;
        if ((Raziel.passedMask & 2) != 0) {
          frame_00 = 0x14;
        }
      }
      else {
        if (frame != 0x44) {
          if (frame != 0x40) {
            bVar7 = true;
          }
          goto LAB_800a6748;
        }
        if ((Raziel.passedMask & 0xf00) != 0) {
          bVar7 = true;
        }
        if ((Raziel.passedMask & 0x800) != 0) {
          frame_00 = 7;
        }
        if ((Raziel.passedMask & 0x100) != 0) {
          frame_00 = 0xd;
        }
        uVar3 = Raziel.passedMask & 0x400;
        if ((Raziel.passedMask & 0x200) != 0) {
          frame_00 = 0x14;
        }
      }
      if (uVar3 != 0) {
        frame_00 = 0x19;
      }
    }
    else {
      if (Raziel.Magnitude < 0xae0) {
        ControlFlag = ControlFlag | 0x2000;
        frame = *Anim;
        if (frame == 0x40) {
          bVar7 = (Raziel.passedMask & 0xf0) != 0;
          if ((Raziel.passedMask & 0x80) != 0) {
            frame_00 = 0xc;
          }
          if ((Raziel.passedMask & 0x10) != 0) {
            frame_00 = 0x14;
          }
          uVar3 = Raziel.passedMask & 0x40;
          if ((Raziel.passedMask & 0x20) != 0) {
            frame_00 = 0x20;
          }
        }
        else {
          if (frame != 0x44) {
            if (frame != 0x3c) {
              bVar7 = true;
            }
            goto LAB_800a6748;
          }
          bVar7 = (Raziel.passedMask & 0xf00) != 0;
          if ((Raziel.passedMask & 0x800) != 0) {
            frame_00 = 0xc;
          }
          if ((Raziel.passedMask & 0x100) != 0) {
            frame_00 = 0x14;
          }
          uVar3 = Raziel.passedMask & 0x400;
          if ((Raziel.passedMask & 0x200) != 0) {
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
    if (Raziel.nothingCounter == 0) {
      ControlFlag = ControlFlag & 0xffffdfff;
    }
    if ((ControlFlag & 0x20000000U) != 0) {
      razResetPauseTranslation(In->CharacterInstance);
    }
    frame = *Anim;
    if (frame == 0x3c) {
      if ((Raziel.passedMask & 0xf) != 0) {
        bVar7 = true;
      }
      if ((Raziel.passedMask & 8) != 0) {
        frame_00 = 5;
      }
      if ((Raziel.passedMask & 1) != 0) {
        frame_00 = 0x17;
      }
      uVar3 = Raziel.passedMask & 4;
      if ((Raziel.passedMask & 2) != 0) {
        frame_00 = 0x11;
      }
    }
    else {
      if (frame != 0x40) {
        if (frame != 0x44) {
          bVar7 = true;
        }
        goto LAB_800a6748;
      }
      if ((Raziel.passedMask & 0xf0) != 0) {
        bVar7 = true;
      }
      if ((Raziel.passedMask & 0x80) != 0) {
        frame_00 = 5;
      }
      if ((Raziel.passedMask & 0x10) != 0) {
        frame_00 = 0x17;
      }
      uVar3 = Raziel.passedMask & 0x40;
      if ((Raziel.passedMask & 0x20) != 0) {
        frame_00 = 0x11;
      }
    }
    if (uVar3 != 0) {
      frame_00 = 0xb;
    }
  }
LAB_800a6748:
  if (bVar7 == true) {
    if (CurrentSection == 2) {
      Raziel.passedMask = 0;
    }
    frame = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x40,frame_00,Frames);
    if (frame != 0) {
      G2EmulationSwitchAnimation(In,CurrentSection,0x7c,frame_00,Frames,2);
    }
    Raziel.movementMinRate = 0xccc;
    Raziel.movementMaxRate = 0x1800;
    Raziel.movementMinAnalog = 0xadf;
    Raziel.movementMaxAnalog = 0xeb8;
    frame_00 = 0x40;
LAB_800a68ac:
    *Anim = frame_00;
  }
  else {
    if (bVar7 < 3) {
      if (bVar7 == true) {
        if (CurrentSection == 2) {
          Raziel.passedMask = 0;
        }
        frame = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x3c,frame_00,Frames);
        if (frame != 0) {
          G2EmulationSwitchAnimation(In,CurrentSection,0x7b,frame_00,Frames,2);
        }
        Raziel.movementMinRate = 0x1000;
        Raziel.movementMaxRate = 0x1c00;
        Raziel.movementMinAnalog = 0x8fc;
        Raziel.movementMaxAnalog = 0xadf;
        frame_00 = 0x3c;
        goto LAB_800a68ac;
      }
    }
    else {
      if (bVar7 == true) {
        if (CurrentSection == 2) {
          Raziel.passedMask = 0;
        }
        frame = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x44,frame_00,Frames);
        if (frame != 0) {
          G2EmulationSwitchAnimation(In,CurrentSection,2,frame_00,Frames,2);
        }
        Raziel.movementMinRate = 0xddb;
        Raziel.movementMinAnalog = 0xeb8;
        frame_00 = 0x44;
        Raziel.movementMaxRate = 0x1000;
        Raziel.movementMaxAnalog = 0x1000;
        goto LAB_800a68ac;
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
      if (frame_00 != 0x3c) goto LAB_800a6918;
    }
    else {
      sVar2 = -0x3c;
      if (frame_00 != 0x44) goto LAB_800a6918;
    }
  }
  local_30.y = sVar2;
LAB_800a6918:
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
 // line 1191, offset 0x800a6abc
	/* begin block 1 */
		// Start line: 1192
		// Start offset: 0x800A6ABC
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1197
			// Start offset: 0x800A6AEC
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $s0

			/* begin block 1.1.1 */
				// Start line: 1237
				// Start offset: 0x800A6B94
				// Variables:
			// 		long adjustment; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800A6C30
			// End Line: 1247
		/* end block 1.1 */
		// End offset: 0x800A6C30
		// End Line: 1248
	/* end block 1 */
	// End offset: 0x800A6C30
	// End Line: 1250

	/* begin block 2 */
		// Start line: 2590
	/* end block 2 */
	// End Line: 2591

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
    if (iVar3 == 0) goto LAB_800a6c34;
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
LAB_800a6c34:
  return -iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razResetMotion(struct _Instance *instance /*$a0*/)
 // line 1254, offset 0x800a6c4c
	/* begin block 1 */
		// Start line: 2719
	/* end block 1 */
	// End Line: 2720

void razResetMotion(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim,0,0x22);
  if (_Var1 != G2FALSE) {
    G2Anim_DisableController(anim,0,0x22);
  }
  Raziel.passedMask = 0;
  G2Anim_SetSpeedAdjustment(anim,0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetDampingPhysics(struct _Instance *instance /*$a0*/)
 // line 1293, offset 0x800a6ca0
	/* begin block 1 */
		// Start line: 2586
	/* end block 1 */
	// End Line: 2587

	/* begin block 2 */
		// Start line: 2769
	/* end block 2 */
	// End Line: 2770

void razSetDampingPhysics(_Instance *instance)

{
  Raziel.RotationSegment = 0;
  Raziel.extraRot.x = 0;
  PhysicsMode = 4;
  SetDampingPhysics(instance,PlayerData->SwimPhysicsFallDamping);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razEnterWater(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, struct evPhysicsSwimData *SwimData /*$s3*/)
 // line 1303, offset 0x800a6cd8
	/* begin block 1 */
		// Start line: 1304
		// Start offset: 0x800A6CD8
		// Variables:
	// 		struct _Instance *Inst; // $s2
	/* end block 1 */
	// End offset: 0x800A6F60
	// End Line: 1401

	/* begin block 2 */
		// Start line: 2790
	/* end block 2 */
	// End Line: 2791

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
    if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
      Raziel.HitPoints = 100000;
      SetPhysics(In->CharacterInstance,-0x10,0,0,0);
      PhysicsMode = 0;
    }
    else {
      if ((Inst == (_Instance *)0x0) || (uVar1 = INSTANCE_Query(Inst,4), uVar1 != 3)) {
        if (((Raziel.Mode & 0x40000U) == 0) && (Raziel.CurrentPlane == 1)) {
          if (PhysicsMode != 4) {
            razSetDampingPhysics(In->CharacterInstance);
          }
          if ((In->CharacterInstance->zVel == 0) || ((Raziel.Mode & 0x400004U) != 0)) {
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
  if (((SwimData->rc & 0x800U) != 0) && (Raziel.Senses.heldClass == 1)) {
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
 // line 1428, offset 0x800a6f7c
	/* begin block 1 */
		// Start line: 1430
		// Start offset: 0x800A6F7C
	/* end block 1 */
	// End offset: 0x800A6FC8
	// End Line: 1444

	/* begin block 2 */
		// Start line: 3041
	/* end block 2 */
	// End Line: 3042

	/* begin block 3 */
		// Start line: 3042
	/* end block 3 */
	// End Line: 3043

	/* begin block 4 */
		// Start line: 3048
	/* end block 4 */
	// End Line: 3049

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
  Raziel.swimTargetSpeed = (short)(iVar1 >> 0xc);
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
 // line 1447, offset 0x800a6fd0
	/* begin block 1 */
		// Start line: 1448
		// Start offset: 0x800A6FD0
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1455
			// Start offset: 0x800A6FF8
		/* end block 1.1 */
		// End offset: 0x800A7068
		// End Line: 1493
	/* end block 1 */
	// End offset: 0x800A70A8
	// End Line: 1504

	/* begin block 2 */
		// Start line: 3081
	/* end block 2 */
	// End Line: 3082

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
 // line 1508, offset 0x800a70bc
	/* begin block 1 */
		// Start line: 1509
		// Start offset: 0x800A70BC
		// Variables:
	// 		int i; // $s0
	// 		int rc; // $v1
	// 		int temp[3]; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A7158
	// End Line: 1522

	/* begin block 2 */
		// Start line: 3219
	/* end block 2 */
	// End Line: 3220

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
 // line 1527, offset 0x800a7178
	/* begin block 1 */
		// Start line: 1528
		// Start offset: 0x800A7178
		// Variables:
	// 		int index; // $t0
	// 		int rc; // $v1
	/* end block 1 */
	// End offset: 0x800A71C4
	// End Line: 1548

	/* begin block 2 */
		// Start line: 3263
	/* end block 2 */
	// End Line: 3264

int razSwitchVAnimGroup(_Instance *instance,int section,int animGroup,int frame,int frames)

{
  int iVar1;
  
  iVar1 = 1;
  if (Raziel.Senses.heldClass != 0) {
    iVar1 = Raziel.Senses.heldClass - 1;
    if (2 < iVar1) {
      iVar1 = 3;
    }
    razSwitchVAnim(instance,section,PlayerData->virtualAnimations + animGroup + iVar1,frame,frames);
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnimCharacterSingle(struct _Instance *instance /*$s3*/, int anim /*$s4*/, int *frame /*$a2*/, int *frames /*$a3*/)
 // line 1553, offset 0x800a71d4
	/* begin block 1 */
		// Start line: 1554
		// Start offset: 0x800A71D4
		// Variables:
	// 		int i; // $s0
	// 		int temp[3]; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A726C
	// End Line: 1566

	/* begin block 2 */
		// Start line: 3322
	/* end block 2 */
	// End Line: 3323

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
 // line 1569, offset 0x800a728c
	/* begin block 1 */
		// Start line: 1570
		// Start offset: 0x800A728C
	/* end block 1 */
	// End offset: 0x800A728C
	// End Line: 1570

	/* begin block 2 */
		// Start line: 3359
	/* end block 2 */
	// End Line: 3360

void razSwitchVAnimSingle(_Instance *instance,int section,int anim,int frame,int frames)

{
  razSwitchVAnim(instance,section,PlayerData->virtualAnimSingle + anim,frame,frames);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnim(struct _Instance *instance /*$a0*/, int section /*$a1*/, struct __VAnim *vAnim /*$v1*/, int frame /*$a3*/, int frames /*stack 16*/)
 // line 1579, offset 0x800a72c0
	/* begin block 1 */
		// Start line: 3382
	/* end block 1 */
	// End Line: 3383

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
 // line 1607, offset 0x800a738c
	/* begin block 1 */
		// Start line: 1608
		// Start offset: 0x800A738C
		// Variables:
	// 		int rc; // $s2
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 1633
			// Start offset: 0x800A7454
			// Variables:
		// 		struct __VAnim *vanim; // $s1
		/* end block 1.1 */
		// End offset: 0x800A74BC
		// End Line: 1644
	/* end block 1 */
	// End offset: 0x800A74E0
	// End Line: 1655

	/* begin block 2 */
		// Start line: 3438
	/* end block 2 */
	// End Line: 3439

int razProcessSAnim(_Instance *instance,int mode)

{
  short sVar1;
  short sVar2;
  __SAnim *p_Var3;
  int section;
  __VAnim *vAnim;
  int iVar4;
  
  iVar4 = 0;
  if (mode == 0x8000000) {
    sVar2 = (Raziel.currentSAnim)->mode;
    sVar1 = 1;
  }
  else {
    if (mode < 0x8000001) {
      if ((undefined *)mode != &DAT_00100015) goto LAB_800a7434;
      sVar2 = (Raziel.currentSAnim)->mode;
      sVar1 = 2;
    }
    else {
      if (mode != 0x8000003) goto LAB_800a7434;
      sVar2 = (Raziel.currentSAnim)->mode;
      sVar1 = 3;
    }
  }
  if (sVar2 == sVar1) {
    iVar4 = 1;
  }
LAB_800a7434:
  if (iVar4 != 0) {
    p_Var3 = (Raziel.currentSAnim)->nextAnim;
    if (p_Var3 == (__SAnim *)0x0) {
      G2Anim_SetSpeedAdjustment(&instance->anim,0x1000);
      Raziel.currentSAnim = (__SAnim *)0x0;
      iVar4 = 0;
    }
    else {
      vAnim = p_Var3->anim;
      section = 0;
      Raziel.currentSAnim = p_Var3;
      if (vAnim != (__VAnim *)0x0) {
        do {
          razSwitchVAnim(instance,section,vAnim,-1,-1);
          section = section + 1;
          G2Anim_SetSpeedAdjustment(&instance->anim,(int)(Raziel.currentSAnim)->speedAdjust);
        } while (section < 3);
        if ((Raziel.currentSAnim)->mode == 2) {
          SetTimer((int)(Raziel.currentSAnim)->data);
        }
      }
    }
  }
  return iVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchStringAnimation(struct _Instance *instance /*$s2*/, int anim /*$a1*/)
 // line 1659, offset 0x800a7504
	/* begin block 1 */
		// Start line: 1660
		// Start offset: 0x800A7504
		// Variables:
	// 		struct __VAnim *vanim; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x800A75B0
	// End Line: 1676

	/* begin block 2 */
		// Start line: 3550
	/* end block 2 */
	// End Line: 3551

	/* begin block 3 */
		// Start line: 3554
	/* end block 3 */
	// End Line: 3555

void razSwitchStringAnimation(_Instance *instance,int anim)

{
  int section;
  __VAnim *vAnim;
  
  Raziel.currentSAnim = PlayerData->stringAnimations[anim];
  vAnim = (Raziel.currentSAnim)->anim;
  if (vAnim != (__VAnim *)0x0) {
    section = 0;
    do {
      razSwitchVAnim(instance,section,vAnim,-1,-1);
      section = section + 1;
    } while (section < 3);
    G2Anim_SetSpeedAdjustment(&instance->anim,(int)(Raziel.currentSAnim)->speedAdjust);
    if ((Raziel.currentSAnim)->mode == 2) {
      SetTimer((int)(Raziel.currentSAnim)->data);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckStringAnimation(struct _Instance *instance /*$s1*/, int mode /*$a1*/)
 // line 1679, offset 0x800a75cc
	/* begin block 1 */
		// Start line: 1680
		// Start offset: 0x800A75CC
		// Variables:
	// 		int rc; // $s0
	/* end block 1 */
	// End offset: 0x800A7614
	// End Line: 1690

	/* begin block 2 */
		// Start line: 3600
	/* end block 2 */
	// End Line: 3601

	/* begin block 3 */
		// Start line: 3603
	/* end block 3 */
	// End Line: 3604

int CheckStringAnimation(_Instance *instance,int mode)

{
  int iVar1;
  
  iVar1 = 0;
  if ((Raziel.currentSAnim == (__SAnim *)0x0) ||
     (iVar1 = razProcessSAnim(instance,mode), Raziel.currentSAnim == (__SAnim *)0x0)) {
    INSTANCE_Post(instance,0x100000,0);
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razLaunchBubbles(int segments /*$s2*/, int count /*$s0*/, int type /*$s1*/)
 // line 1744, offset 0x800a762c
	/* begin block 1 */
		// Start line: 3488
	/* end block 1 */
	// End Line: 3489

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
 // line 1757, offset 0x800a76c4
	/* begin block 1 */
		// Start line: 1758
		// Start offset: 0x800A76C4
	/* end block 1 */
	// End offset: 0x800A776C
	// End Line: 1767

	/* begin block 2 */
		// Start line: 3706
	/* end block 2 */
	// End Line: 3707

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
  } while ((int)puVar3 < -0x7ff2e39e);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAttachControllers()
 // line 1769, offset 0x800a7774
	/* begin block 1 */
		// Start line: 1770
		// Start offset: 0x800A7774
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x800A77C8
	// End Line: 1777

	/* begin block 2 */
		// Start line: 3734
	/* end block 2 */
	// End Line: 3735

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
 // line 1779, offset 0x800a77dc
	/* begin block 1 */
		// Start line: 1780
		// Start offset: 0x800A77DC
		// Variables:
	// 		void (*process)(); // $s0
	// 		int message; // stack offset -16
	// 		int data; // stack offset -12

		/* begin block 1.1 */
			// Start line: 1804
			// Start offset: 0x800A789C
		/* end block 1.1 */
		// End offset: 0x800A78D8
		// End Line: 1813
	/* end block 1 */
	// End offset: 0x800A7AD8
	// End Line: 1879

	/* begin block 2 */
		// Start line: 3764
	/* end block 2 */
	// End Line: 3765

	/* begin block 3 */
		// Start line: 3771
	/* end block 3 */
	// End Line: 3772

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razSetPlayerEvent(void)

{
  _func_14 *p_Var1;
  ulong uVar2;
  _Instance *p_Var3;
  int iVar4;
  int local_10;
  int local_c;
  
  p_Var1 = Raziel.State.SectionList[0].Process;
  local_10 = 0;
  local_c = 0;
  if ((((Raziel.Senses.EngagedMask & 1) != 0) && (Raziel.Senses.heldClass != 3)) &&
     (Raziel.State.SectionList[0].Process == StateHandlerIdle)) {
    Raziel.playerEvent = Raziel.playerEvent | 1;
  }
  if ((((Raziel.Senses.EngagedMask & 4) != 0) && (Raziel.Senses.heldClass != 3)) &&
     (Raziel.State.SectionList[0].Process == StateHandlerCrouch)) {
    Raziel.playerEvent = Raziel.playerEvent | 2;
  }
  if ((((Raziel.Senses.EngagedMask & 8) != 0) && (Raziel.Senses.heldClass != 3)) &&
     (Raziel.State.SectionList[0].Process == StateHandlerIdle)) {
    uVar2 = INSTANCE_Query(Raziel.Senses.EngagedList[3].instance,4);
    if (uVar2 == 9) {
      Raziel.playerEvent = Raziel.playerEvent | 8;
    }
    else {
      Raziel.playerEvent = Raziel.playerEvent | 4;
    }
  }
  if (((((Raziel.Senses.EngagedMask & 0x20) != 0) &&
       (p_Var3 = razGetHeldItem(), p_Var3 == (_Instance *)0x0)) && (Raziel.CurrentPlane == 1)) &&
     (((p_Var1 == StateHandlerIdle || (p_Var1 == StateHandlerStartMove)) ||
      ((((p_Var1 == StateHandlerMove ||
         ((p_Var1 == StateHandlerJump || (p_Var1 == StateHandlerFall)))) ||
        (p_Var1 == StateHandlerSwim)) || (p_Var1 == StateHandlerAutoFace)))))) {
    Raziel.playerEvent = Raziel.playerEvent | 0x10;
  }
  if (((Raziel.Senses.EngagedMask & 0x40) != 0) &&
     (uVar2 = INSTANCE_Query(Raziel.Senses.EngagedList[6].instance,10), (uVar2 & 4) == 0)) {
    Raziel.playerEvent = Raziel.playerEvent | 0x20;
  }
  iVar4 = StateHandlerDecodeHold(&local_10,&local_c);
  if ((iVar4 != 0) && (local_c != 0)) {
    if (local_10 == 0x1000002) {
      Raziel.playerEvent = Raziel.playerEvent | 0x40;
    }
    if (local_10 == 0x100000a) {
      Raziel.playerEvent = Raziel.playerEvent | 0x80;
    }
    if (local_10 == 0x1000018) {
      Raziel.playerEvent = Raziel.playerEvent | 0x100;
    }
  }
  if (((Raziel.Mode & 0x20000U) != 0) && (Raziel.Senses.heldClass - 1 < 3)) {
    Raziel.playerEvent = Raziel.playerEvent | 0x200;
  }
  if (local_10 == 0x80000) {
    Raziel.playerEvent = Raziel.playerEvent | 0x400;
  }
  if ((Raziel.Senses.EngagedMask & 0x4000) != 0) {
    Raziel.playerEvent = Raziel.playerEvent | 0x800;
  }
  if ((Raziel.Senses.Flags & 0x40U) != 0) {
    Raziel.playerEvent = Raziel.playerEvent | 0x2000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razClearPlayerEvent()
 // line 1881, offset 0x800a7ae8
	/* begin block 1 */
		// Start line: 3979
	/* end block 1 */
	// End Line: 3980

	/* begin block 2 */
		// Start line: 3981
	/* end block 2 */
	// End Line: 3982

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razClearPlayerEvent(void)

{
  if ((ControlFlag & 0x100000U) != 0) {
    Raziel.playerEvent = Raziel.playerEvent & 0x2000;
    return;
  }
  Raziel.playerEvent = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPlayerEventHistory(unsigned long event /*$a0*/)
 // line 1890, offset 0x800a7b20
	/* begin block 1 */
		// Start line: 3997
	/* end block 1 */
	// End Line: 3998

	/* begin block 2 */
		// Start line: 3998
	/* end block 2 */
	// End Line: 3999

void razSetPlayerEventHistory(ulong event)

{
  Raziel.playerEventHistory = Raziel.playerEventHistory | event;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSideMoveSpiderCheck(struct _Instance *instance /*$s2*/, int x /*$a1*/)
 // line 1897, offset 0x800a7b38
	/* begin block 1 */
		// Start line: 1898
		// Start offset: 0x800A7B38
		// Variables:
	// 		struct SVECTOR startVec; // stack offset -32
	// 		struct SVECTOR endVec; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A7BEC
	// End Line: 1917

	/* begin block 2 */
		// Start line: 4011
	/* end block 2 */
	// End Line: 4012

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



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ RAZIEL_QueryEngagedInstance(int index /*$a0*/)
 // line 1934, offset 0x800a7c04
	/* begin block 1 */
		// Start line: 4101
	/* end block 1 */
	// End Line: 4102

	/* begin block 2 */
		// Start line: 4103
	/* end block 2 */
	// End Line: 4104

_Instance * RAZIEL_QueryEngagedInstance(int index)

{
  if ((Raziel.Senses.EngagedMask & 1 << (index & 0x1fU)) == 0) {
    return (_Instance *)0x0;
  }
  return Raziel.Senses.EngagedList[index].instance;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razUpdateSoundRamp(struct _Instance *instance /*$a0*/, struct _SoundRamp *sound /*$s0*/)
 // line 1947, offset 0x800a7c3c
	/* begin block 1 */
		// Start line: 1948
		// Start offset: 0x800A7C3C
		// Variables:
	// 		int volume; // $s1
	// 		int time; // $t0

		/* begin block 1.1 */
			// Start line: 1963
			// Start offset: 0x800A7CA0
			// Variables:
		// 		int startPitch; // $v1
		// 		int endPitch; // $v0
		// 		int startVolume; // $a1
		// 		int endVolume; // $v0
		/* end block 1.1 */
		// End offset: 0x800A7D28
		// End Line: 1978
	/* end block 1 */
	// End offset: 0x800A7D28
	// End Line: 1981

	/* begin block 2 */
		// Start line: 4123
	/* end block 2 */
	// End Line: 4124

	/* begin block 3 */
		// Start line: 4130
	/* end block 3 */
	// End Line: 4131

int razUpdateSoundRamp(_Instance *instance,_SoundRamp *sound)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int maxVolume;
  
  maxVolume = 0;
  if (sound->soundHandle != 0) {
    iVar3 = sound->soundTotalTime;
    maxVolume = sound->soundTimer + gameTrackerX.timeMult;
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
 // line 1987, offset 0x800a7d40
	/* begin block 1 */
		// Start line: 4221
	/* end block 1 */
	// End Line: 4222

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
 // line 2011, offset 0x800a7de4
	/* begin block 1 */
		// Start line: 2012
		// Start offset: 0x800A7DE4
		// Variables:
	// 		int soundFlag; // $s0
	/* end block 1 */
	// End offset: 0x800A7E50
	// End Line: 2031

	/* begin block 2 */
		// Start line: 4276
	/* end block 2 */
	// End Line: 4277

void RAZIEL_SetInteractiveMusic(int modifier,int action)

{
  uint uVar1;
  
  uVar1 = 1 << (modifier & 0x1fU);
  if (action == 0) {
    if ((Raziel.soundModifier & uVar1) != 0) {
      SOUND_ResetMusicModifier(modifier);
    }
    Raziel.soundModifier = Raziel.soundModifier & ~uVar1;
  }
  else {
    if ((Raziel.soundModifier & uVar1) == 0) {
      SOUND_SetMusicModifier(modifier);
    }
    Raziel.soundModifier = Raziel.soundModifier | uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugHurtRaziel()
 // line 2032, offset 0x800a7e60
	/* begin block 1 */
		// Start line: 4324
	/* end block 1 */
	// End Line: 4325

/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_DebugHurtRaziel(void)

{
  LoseHealth(0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_StartNewGame()
 // line 2037, offset 0x800a7e80
	/* begin block 1 */
		// Start line: 4334
	/* end block 1 */
	// End Line: 4335

/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_StartNewGame(void)

{
  memset(&Raziel,0,0x5b8);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razInBaseArea(char *name /*$s1*/, int length /*$s0*/)
 // line 2046, offset 0x800a7ea8
	/* begin block 1 */
		// Start line: 2047
		// Start offset: 0x800A7EA8
		// Variables:
	// 		char string[9]; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A7EF0
	// End Line: 2060

	/* begin block 2 */
		// Start line: 4353
	/* end block 2 */
	// End Line: 4354

int razInBaseArea(char *name,int length)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  char acStack32 [16];
  
  pcVar1 = strcpy(acStack32,gameTrackerX.baseAreaName);
  if (pcVar1 == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    acStack32[length] = '\0';
    iVar3 = strcmp(name,acStack32);
    uVar2 = (uint)(iVar3 == 0);
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razPrepGlyph()
 // line 2065, offset 0x800a7f04
	/* begin block 1 */
		// Start line: 2066
		// Start offset: 0x800A7F04
		// Variables:
	// 		struct _Instance *heldInst; // $s0
	/* end block 1 */
	// End offset: 0x800A7F38
	// End Line: 2075

	/* begin block 2 */
		// Start line: 4402
	/* end block 2 */
	// End Line: 4403

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razPrepGlyph(void)

{
  _Instance *p_Var1;
  
  razReaverOff();
  p_Var1 = razGetHeldItem();
  if (p_Var1 != (_Instance *)0x0) {
    razSetFadeEffect(0,0x1000,0x100);
    Raziel.throwInstance = p_Var1;
  }
  ControlFlag = ControlFlag | 0x4000;
  return;
}





