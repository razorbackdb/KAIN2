#include "THISDUST.H"
#include "RAZLIB.H"


// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYMoveRot(struct _Instance *dest /*$s3*/, short distance /*$a1*/, struct _Position *position /*$s4*/, struct _Rotation *rotation /*$s2*/, int extraZ /*stack 16*/)
 // line 12, offset 0x800a51b0
	/* begin block 1 */
		// Start line: 13
		// Start offset: 0x800A51B0
		// Variables:
	// 		struct SVECTOR d; // stack offset -72
	// 		struct SVECTOR dd; // stack offset -64
	// 		struct MATRIX mat; // stack offset -56
	/* end block 1 */
	// End offset: 0x800A51B0
	// End Line: 13

	/* begin block 2 */
		// Start line: 24
	/* end block 2 */
	// End Line: 25

void razAlignYMoveRot(_Instance *dest,short distance,_Position *position,_Rotation *rotation,
                     int extraZ)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(dest,7);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotMove(struct _Instance *dest /*$s1*/, short distance /*$a1*/, struct _Position *position /*$s2*/, struct _Rotation *rotation /*$s4*/, int extraZ /*stack 16*/)
 // line 54, offset 0x800a5274
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x800A5274
		// Variables:
	// 		struct SVECTOR d; // stack offset -88
	// 		struct SVECTOR dd; // stack offset -80
	// 		struct SVECTOR rot; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64
	/* end block 1 */
	// End offset: 0x800A5274
	// End Line: 55

	/* begin block 2 */
		// Start line: 136
	/* end block 2 */
	// End Line: 137

void razAlignYRotMove(_Instance *dest,short distance,_Position *position,_Rotation *rotation,
                     int extraZ)

{
  undefined auStack72 [40];
  
                    /* WARNING: Subroutine does not return */
  memset(auStack72,0,8);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotMoveInterp(struct _Instance *source /*$s1*/, struct _Instance *dest /*$a1*/, short distance /*$a2*/, unsigned char segNumber /*$s0*/, int Frames /*stack 16*/, int extraZ /*stack 20*/)
 // line 86, offset 0x800a534c
	/* begin block 1 */
		// Start line: 87
		// Start offset: 0x800A534C
		// Variables:
	// 		struct _Position position; // stack offset -40
	// 		struct _Rotation rotation; // stack offset -32
	// 		struct _G2SVector3_Type v; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A534C
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
  undefined2 local_18;
  undefined2 local_16;
  short local_14;
  
  local_28 = *(undefined4 *)&source->position;
  local_24 = (source->position).z;
  razAlignYRotMove(dest,distance,(_Position *)&local_28,&_Stack32,(int)(short)extraZ);
  *(undefined4 *)&source->position = local_28;
  (source->position).z = local_24;
  local_18 = 0;
  local_16 = 0;
                    /* WARNING: Subroutine does not return */
  local_14 = _Stack32.z;
  G2Anim_EnableController(&source->anim,(uint)segNumber,8);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAlignYRotInterp(struct _Instance *source /*$s0*/, struct _Position *dest /*$a1*/, unsigned char segNumber /*$a2*/, int Frames /*$a3*/)
 // line 114, offset 0x800a5440
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
 // line 195, offset 0x800a546c
	/* begin block 1 */
		// Start line: 196
		// Start offset: 0x800A546C
		// Variables:
	// 		int i; // $s0
	// 		int j; // $s2
	// 		int k; // $a2
	// 		int Total; // $s1
	// 		int outer; // stack offset -32
	// 		int rc; // $s3
	// 		struct _SVector point; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A5564
	// End Line: 243

	/* begin block 2 */
		// Start line: 390
	/* end block 2 */
	// End Line: 391

int razConstrictAngle(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  _SVector local_28;
  int local_20;
  
  iVar3 = (int)sGpfffffb78;
  iVar4 = 0;
  local_28.x = *(short *)(param_1 + 0x5c);
  iVar6 = 0;
  local_28.y = *(short *)(param_1 + 0x5e);
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
    setCopReg(2,0x6000,uGpfffffb7c);
    setCopReg(2,0x7000,*(undefined4 *)(iVar2 * 4 + iGpfffffb74));
    setCopReg(2,0x6800,*(undefined4 *)(iVar3 * 4 + iGpfffffb74));
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
                      ((_SVector *)&uGpfffffb7c,(_SVector *)(iGpfffffb74 + iVar1),
                       (_SVector *)(iGpfffffb74 + iVar2 * 4),&local_28);
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
 // line 247, offset 0x800a5580
	/* begin block 1 */
		// Start line: 248
		// Start offset: 0x800A5580
		// Variables:
	// 		int tx; // $s0
	// 		int tz; // $s2
	// 		struct _G2SVector3_Type Rot; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A5608
	// End Line: 268

	/* begin block 2 */
		// Start line: 555
	/* end block 2 */
	// End Line: 556

void razRotateUpperBody(int param_1,short **param_2)

{
  short sVar1;
  short sVar2;
  _Rotation _Stack32;
  
  sVar1 = **param_2;
  sVar2 = *(short *)(param_2 + 2);
  if ((sVar1 < *(short *)(param_2 + 2)) ||
     (sVar2 = *(short *)((int)param_2 + 10), *(short *)((int)param_2 + 10) < sVar1)) {
    **param_2 = sVar2;
  }
  sVar1 = *param_2[1];
  sVar2 = *(short *)(param_2 + 3);
  if ((sVar1 < *(short *)(param_2 + 3)) ||
     (sVar2 = *(short *)((int)param_2 + 0xe), *(short *)((int)param_2 + 0xe) < sVar1)) {
    *param_2[1] = sVar2;
  }
  _Stack32.y = 0;
  _Stack32.x = (short)(-(int)**param_2 / 2);
  _Stack32.z = (short)(((int)((uint)(ushort)*param_2[1] << 0x10) >> 0x10) -
                       ((int)((uint)(ushort)*param_2[1] << 0x10) >> 0x1f) >> 1);
  MATH3D_ZYXtoXYZ(&_Stack32);
                    /* WARNING: Subroutine does not return */
  G2Anim_SetController_Vector
            ((_G2Anim_Type *)(param_1 + 0x194),0xe,0xe,(_G2SVector3_Type *)&_Stack32);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetFadeEffect(short source /*$a0*/, short dest /*$a1*/, int steps /*$a2*/)
 // line 285, offset 0x800a5750
	/* begin block 1 */
		// Start line: 640
	/* end block 1 */
	// End Line: 641

	/* begin block 2 */
		// Start line: 644
	/* end block 2 */
	// End Line: 645

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razSetFadeEffect(short source,short dest,int steps)

{
  _CHAR____800d5730 = _CHAR____800d5730 | 3;
  _LastTime_360 = source;
  _CHAR____800d5736 = dest;
  _CHAR____800d5738 = steps;
  _CHAR____800d573c = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razPlaneShift(struct _Instance *instance /*$a0*/)
 // line 302, offset 0x800a5774
	/* begin block 1 */
		// Start line: 672
	/* end block 1 */
	// End Line: 673

	/* begin block 2 */
		// Start line: 679
	/* end block 2 */
	// End Line: 680

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int razPlaneShift(_Instance *instance)

{
  int iVar1;
  
  if ((theCamera.positionAccl._4_4_ & 0x40000) == 0) {
    if (_CHAR____800d564c == 1) {
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
 // line 320, offset 0x800a57d0
	/* begin block 1 */
		// Start line: 321
		// Start offset: 0x800A57D0
		// Variables:
	// 		struct _Instance *inst; // $a0
	/* end block 1 */
	// End offset: 0x800A58F8
	// End Line: 357

	/* begin block 2 */
		// Start line: 715
	/* end block 2 */
	// End Line: 716

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void razSpectralShift(void)

{
  _Instance *Inst;
  
  if (((theCamera.positionAccl._4_4_ & 0x40000) != 0) || (_CHAR____800d564c != 1)) {
    return;
  }
  Inst = razGetHeldItem();
  if (Inst == (_Instance *)0x0) {
    *(uint *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x18) =
         *(uint *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x18) | 0x8000000;
                    /* WARNING: Subroutine does not return */
    INSTANCE_Post((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],(int)&DAT_00100014,0);
  }
  if (_CHAR____800d5600 == 8) {
    Inst = razGetHeldItem();
                    /* WARNING: Subroutine does not return */
    INSTANCE_PlainDeath(Inst);
  }
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(Inst,0x800008,4);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razMaterialShift()
 // line 360, offset 0x800a5908
	/* begin block 1 */
		// Start line: 797
	/* end block 1 */
	// End Line: 798

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void razMaterialShift(void)

{
  if ((_CHAR____800d564c == 2) && (_CHAR____800d5610 == 100000)) {
    _CHAR____800d564c = 1;
    *(uint *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x18) =
         *(uint *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x18) & 0xf7ffffff;
    _CHAR____800d5610 = GetMaxHealth();
    _CHAR____800d5614 = 0;
    razReaverOn();
    if (theCamera.core.vvNormalWorVecMat[0]._18_2_ != 0) {
      MORPH_ToggleMorph();
      if ((_CHAR____800d5220 != StateHandlerGlyphs) && (_CHAR____800d5220 != StateHandlerPuppetShow)
         ) {
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],(int)&DAT_00040005,0);
      }
      if (_CHAR____800d55e8 != (_Instance *)0x0) {
        FX_EndInstanceParticleEffects(_CHAR____800d55e8);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ RAZIEL_OkToShift()
 // line 383, offset 0x800a59d0
	/* begin block 1 */
		// Start line: 844
	/* end block 1 */
	// End Line: 845

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

int RAZIEL_OkToShift(void)

{
  int iVar1;
  uint uVar2;
  
  if (_CHAR____800d564c == 2) {
    iVar1 = GetMaxHealth();
    uVar2 = 0;
    if (_CHAR____800d5610 == iVar1) {
      if ((_CHAR____800d561c & 0x40) == 0) {
        uVar2 = (uint)((_CHAR____800d55b0 & 0x40) != 0);
      }
      else {
        uVar2 = (uint)((_CHAR____800d561c & 0x10) != 0);
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
 // line 409, offset 0x800a5a44
	/* begin block 1 */
		// Start line: 410
		// Start offset: 0x800A5A44

		/* begin block 1.1 */
			// Start line: 413
			// Start offset: 0x800A5AA0
			// Variables:
		// 		int index; // $a2

			/* begin block 1.1.1 */
				// Start line: 427
				// Start offset: 0x800A5AD0
				// Variables:
			// 		struct evObjectData *objData; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800A5B9C
			// End Line: 448
		/* end block 1.1 */
		// End offset: 0x800A5C38
		// End Line: 460
	/* end block 1 */
	// End offset: 0x800A5C3C
	// End Line: 464

	/* begin block 2 */
		// Start line: 896
	/* end block 2 */
	// End Line: 897

	/* begin block 3 */
		// Start line: 898
	/* end block 3 */
	// End Line: 899

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int razPickupAndGrab(__CharacterState *In,int CurrentSection)

{
  _Instance *Inst;
  int Data;
  
  if ((_CHAR____800d55f0 & 0x20) == 0) {
    Data = 1;
  }
  else {
    Inst = razGetHeldItem();
    Data = 1;
    if ((((Inst == (_Instance *)0x0) && (_CHAR____800d564c == 1)) &&
        (Data = 1, (_CHAR____800d55b0 & 0x80) == 0)) && (Data = 0, CurrentSection == 1)) {
      Inst = *(_Instance **)(*(int *)(_CHAR____800d55ec + 0x28) + 300);
      if (Inst != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query(Inst,0);
      }
      Data = SetPhysicsSwimData(0,(_SVector *)0x0,8,(int)In->CharacterInstance,1);
                    /* WARNING: Subroutine does not return */
      INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x28),0x80002e,Data);
    }
  }
  return Data;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razZeroAxis(long *x /*$s1*/, long *y /*$s2*/, int radius /*$s0*/)
 // line 471, offset 0x800a5c54
	/* begin block 1 */
		// Start line: 472
		// Start offset: 0x800A5C54
		// Variables:
	// 		unsigned long distance; // $v0
	/* end block 1 */
	// End offset: 0x800A5C9C
	// End Line: 504

	/* begin block 2 */
		// Start line: 1023
	/* end block 2 */
	// End Line: 1024

ulong razZeroAxis(long *param_1,long *param_2,uint param_3)

{
  ulong uVar1;
  
  uVar1 = MATH3D_SquareLength(*param_1,*param_2,0);
  if (uVar1 < param_3) {
    uVar1 = 0;
    *param_1 = 0;
    *param_2 = 0;
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razAdjustSpeed(struct _Instance *instance /*$a3*/, int minSpeed /*$a1*/)
 // line 508, offset 0x800a5cb4
	/* begin block 1 */
		// Start line: 509
		// Start offset: 0x800A5CB4
		// Variables:
	// 		long adjustment; // $s0

		/* begin block 1.1 */
			// Start line: 509
			// Start offset: 0x800A5CB4
			// Variables:
		// 		int data; // $v1
		/* end block 1.1 */
		// End offset: 0x800A5D30
		// End Line: 530
	/* end block 1 */
	// End offset: 0x800A5D30
	// End Line: 537

	/* begin block 2 */
		// Start line: 1099
	/* end block 2 */
	// End Line: 1100

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int razAdjustSpeed(_Instance *instance,int minSpeed)

{
  int iVar1;
  long adjustment;
  
  iVar1 = (int)_CHAR____800d55ae;
  if (iVar1 < _CHAR____800d5588) {
    adjustment = (long)_CHAR____800d55aa;
  }
  else {
    if (_CHAR____800d5588 < _CHAR____800d55ac) {
      adjustment = (long)_CHAR____800d55a8;
    }
    else {
      adjustment = (int)_CHAR____800d55aa -
                   (((int)_CHAR____800d55aa - (int)_CHAR____800d55a8) * (iVar1 - _CHAR____800d5588))
                   / (iVar1 - _CHAR____800d55ac);
    }
  }
                    /* WARNING: Subroutine does not return */
  G2Anim_SetSpeedAdjustment(&instance->anim,adjustment);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razLaunchForce(struct _Instance *instance /*$s0*/)
 // line 558, offset 0x800a5d50
	/* begin block 1 */
		// Start line: 559
		// Start offset: 0x800A5D50
	/* end block 1 */
	// End offset: 0x800A5D50
	// End Line: 559

	/* begin block 2 */
		// Start line: 1207
	/* end block 2 */
	// End Line: 1208

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razLaunchForce(_Instance *instance)

{
  PHYSOB_BirthProjectile(instance,0x31,(uint)(byte)CHAR____800d561d & 1);
  _CHAR____800d5730 = _CHAR____800d5730 | 4;
                    /* WARNING: Subroutine does not return */
  razSetupSoundRamp(instance,(_SoundRamp *)&CHAR____800d577c,0xc,(int)*(short *)(_PlayerData + 0x38)
                    ,(int)*(short *)(_PlayerData + 0x3a),(int)*(short *)(_PlayerData + 0x3c),
                    (int)*(short *)(_PlayerData + 0x3e),*(int *)(_PlayerData + 0x40) * 0x1e,
                    (int)&DAT_00002710);
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ razGetHeldItem()
 // line 582, offset 0x800a5de0
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x800A5DE0
		// Variables:
	// 		struct _Instance *instance; // $v0
	/* end block 1 */
	// End offset: 0x800A5E10
	// End Line: 606

	/* begin block 2 */
		// Start line: 1266
	/* end block 2 */
	// End Line: 1267

	/* begin block 3 */
		// Start line: 1267
	/* end block 3 */
	// End Line: 1268

	/* begin block 4 */
		// Start line: 1269
	/* end block 4 */
	// End Line: 1270

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

_Instance * razGetHeldItem(void)

{
  _Instance *p_Var1;
  
  p_Var1 = *(_Instance **)(_CHAR____800d5218 + 0x130);
  if (((_CHAR____800d5644 != (_Instance *)0x0) && (p_Var1 == _CHAR____800d5644)) &&
     (p_Var1 != (_Instance *)0x0)) {
    return p_Var1->LinkSibling;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ razGetHeldWeapon()
 // line 610, offset 0x800a5e18
	/* begin block 1 */
		// Start line: 611
		// Start offset: 0x800A5E18
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x800A5E68
	// End Line: 628

	/* begin block 2 */
		// Start line: 1324
	/* end block 2 */
	// End Line: 1325

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

_Instance * razGetHeldWeapon(void)

{
  _Instance *Inst;
  
  Inst = razGetHeldItem();
  if (Inst == (_Instance *)0x0) {
    Inst = (_Instance *)0x0;
    if (_CHAR____800d5600 != 0) {
      Inst = _CHAR____800d5644;
    }
    return Inst;
  }
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(Inst,1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverBladeOff()
 // line 631, offset 0x800a5e78
	/* begin block 1 */
		// Start line: 1366
	/* end block 1 */
	// End Line: 1367

	/* begin block 2 */
		// Start line: 1367
	/* end block 2 */
	// End Line: 1368

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void razReaverBladeOff(void)

{
  if (_CHAR____800d5644 != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Post(_CHAR____800d5644,0x800109,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverBladeOn()
 // line 639, offset 0x800a5ea8
	/* begin block 1 */
		// Start line: 1383
	/* end block 1 */
	// End Line: 1384

	/* begin block 2 */
		// Start line: 1384
	/* end block 2 */
	// End Line: 1385

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void razReaverBladeOn(void)

{
  _Instance *p_Var1;
  
  if ((_CHAR____800d5644 != (_Instance *)0x0) &&
     (p_Var1 = razGetHeldItem(), p_Var1 == (_Instance *)0x0)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Post(_CHAR____800d5644,0x800108,0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razReaverOff()
 // line 649, offset 0x800a5ee8
	/* begin block 1 */
		// Start line: 650
		// Start offset: 0x800A5EE8

		/* begin block 1.1 */
			// Start line: 653
			// Start offset: 0x800A5F0C
			// Variables:
		// 		struct _Instance *heldWeapon; // $s0
		/* end block 1.1 */
		// End offset: 0x800A5F5C
		// End Line: 661
	/* end block 1 */
	// End offset: 0x800A5F60
	// End Line: 663

	/* begin block 2 */
		// Start line: 1404
	/* end block 2 */
	// End Line: 1405

	/* begin block 3 */
		// Start line: 1406
	/* end block 3 */
	// End Line: 1407

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

int razReaverOff(void)

{
  if ((_CHAR____800d5644 != (_Instance *)0x0) && (_CHAR____800d5600 == 0x1000)) {
    razGetHeldWeapon();
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(_CHAR____800d5644,0x28);
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razReaverOn()
 // line 666, offset 0x800a5f70
	/* begin block 1 */
		// Start line: 1440
	/* end block 1 */
	// End Line: 1441

	/* begin block 2 */
		// Start line: 1442
	/* end block 2 */
	// End Line: 1443

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

int razReaverOn(void)

{
  _Instance *p_Var1;
  int iVar2;
  
  if (((_CHAR____800d5644 != (_Instance *)0x0) &&
      (p_Var1 = razGetHeldItem(), p_Var1 == (_Instance *)0x0)) &&
     ((iVar2 = GetMaxHealth(), _CHAR____800d5610 == iVar2 || (_CHAR____800d564c == 2)))) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(_CHAR____800d5644,0x28);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverPickup(struct _Instance *instance /*$a2*/, struct _Instance *soulReaver /*$s0*/)
 // line 691, offset 0x800a6054
	/* begin block 1 */
		// Start line: 1495
	/* end block 1 */
	// End Line: 1496

void razReaverPickup(_Instance *instance,_Instance *soulReaver)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(soulReaver,0x800002,(int)instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razReaverImbue(int reaverType /*$a2*/)
 // line 719, offset 0x800a6110
	/* begin block 1 */
		// Start line: 1563
	/* end block 1 */
	// End Line: 1564

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razReaverImbue(int reaverType)

{
  if ((1 < reaverType - 1U) && (reaverType != 6)) {
    return;
  }
  debugRazielFlags2 = 1 << (reaverType + 9U & 0x1f);
  _CHAR____800d5648 = reaverType;
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(_CHAR____800d5644,0x800103,reaverType);
}



// decompiled code
// original method signature: 
// int /*$ra*/ razGetReaverFromMask(int reaverMask /*$a0*/)
 // line 731, offset 0x800a6168
	/* begin block 1 */
		// Start line: 733
		// Start offset: 0x800A6168
		// Variables:
	// 		int rc; // $v0
	/* end block 1 */
	// End offset: 0x800A6184
	// End Line: 742

	/* begin block 2 */
		// Start line: 1590
	/* end block 2 */
	// End Line: 1591

	/* begin block 3 */
		// Start line: 1591
	/* end block 3 */
	// End Line: 1592

	/* begin block 4 */
		// Start line: 1593
	/* end block 4 */
	// End Line: 1594

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
 // line 745, offset 0x800a618c
	/* begin block 1 */
		// Start line: 746
		// Start offset: 0x800A618C
		// Variables:
	// 		struct _Instance *Inst; // $s0
	/* end block 1 */
	// End offset: 0x800A61E0
	// End Line: 757

	/* begin block 2 */
		// Start line: 1618
	/* end block 2 */
	// End Line: 1619

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razReaverScale(int scale)

{
  _Instance *Inst;
  
  Inst = razGetHeldWeapon();
  if ((_CHAR____800d5644 != (_Instance *)0x0) && (Inst == _CHAR____800d5644)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Inst,0x28);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razGetForwardNormal(struct _Instance *inst /*$a0*/, struct _Instance *target /*$a1*/)
 // line 760, offset 0x800a61f4
	/* begin block 1 */
		// Start line: 761
		// Start offset: 0x800A61F4
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -72
	// 		struct SVECTOR Old; // stack offset -24
	// 		struct SVECTOR New; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A62C8
	// End Line: 794

	/* begin block 2 */
		// Start line: 1648
	/* end block 2 */
	// End Line: 1649

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    _CHAR____800d55b4 = local_48.wNormal.vx;
    _CHAR____800d55b6 = local_48.wNormal.vy;
    _CHAR____800d55b8 = local_48.wNormal.vz;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razGetRotFromNormal(struct _SVector *normal /*$a0*/, struct _Rotation *rot /*$a2*/)
 // line 797, offset 0x800a62d8
	/* begin block 1 */
		// Start line: 798
		// Start offset: 0x800A62D8
		// Variables:
	// 		struct _Position a; // stack offset -24
	// 		struct _Position b; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A62D8
	// End Line: 798

	/* begin block 2 */
		// Start line: 1731
	/* end block 2 */
	// End Line: 1732

int razSwitchVAnimGroup(_Instance *instance,int section,int animGroup,int frame,int frames)

{
  uint uVar1;
  _Position local_18;
  _Position local_10;
  
  local_18.x = *(short *)&(instance->node).prev;
  local_18.y = *(short *)((int)&(instance->node).prev + 2);
  local_18.z = *(ushort *)&(instance->node).next;
  uVar1 = (uint)local_18.z;
  local_10.z = 0;
  local_10.y = 0;
  local_10.x = 0;
  MATH3D_RotationFromPosToPos(&local_18,&local_10,(_Rotation *)section);
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razCenterWithBlock(struct _Instance *inst /*$s3*/, struct _Instance *target /*$s1*/, int dist /*$s2*/)
 // line 811, offset 0x800a6324
	/* begin block 1 */
		// Start line: 812
		// Start offset: 0x800A6324
		// Variables:
	// 		struct SVECTOR d; // stack offset -88
	// 		struct SVECTOR dd; // stack offset -80
	// 		struct _Rotation rot; // stack offset -72
	// 		struct MATRIX mat; // stack offset -64
	// 		struct _G2SVector3_Type v; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A64A8
	// End Line: 863

	/* begin block 2 */
		// Start line: 1771
	/* end block 2 */
	// End Line: 1772

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razCenterWithBlock(_Instance *inst,_Instance *target,int dist)

{
  int animGroup;
  int in_a3;
  int local_60;
  undefined2 local_58;
  short local_56;
  undefined2 local_54;
  undefined local_50 [8];
  undefined auStack72 [4];
  short local_44;
  MATRIX MStack64;
  
  animGroup = dist;
  razGetForwardNormal(inst,target);
  razSwitchVAnimGroup((_Instance *)&CHAR____800d55b4,(int)auStack72,animGroup,in_a3,local_60);
  MATH3D_SetUnityMatrix(&MStack64);
  RotMatrixZ((int)local_44,(uint *)&MStack64);
  local_56 = 0x140 - (short)dist;
  local_54 = 0;
  local_58 = 0;
                    /* WARNING: Subroutine does not return */
  ApplyMatrixSV(&MStack64,&local_58,local_50);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPauseTranslation(struct _Instance *instance /*$a0*/)
 // line 870, offset 0x800a64f4
	/* begin block 1 */
		// Start line: 871
		// Start offset: 0x800A64F4
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -16
	/* end block 1 */
	// End offset: 0x800A6528
	// End Line: 881

	/* begin block 2 */
		// Start line: 1909
	/* end block 2 */
	// End Line: 1910

void razSetPauseTranslation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  _G2SVector3_Type local_10;
  
  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim,0,0x22);
  if (_Var1 == G2FALSE) {
                    /* WARNING: Subroutine does not return */
    G2Anim_EnableController(anim,0,0x22);
  }
  local_10.x = 0;
  local_10.y = 0;
                    /* WARNING: Subroutine does not return */
  local_10.z = 0;
  G2Anim_SetController_Vector(anim,0,0x22,&local_10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razResetPauseTranslation(struct _Instance *instance /*$a0*/)
 // line 887, offset 0x800a6568
	/* begin block 1 */
		// Start line: 1951
	/* end block 1 */
	// End Line: 1952

void razResetPauseTranslation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  
  _Var1 = G2Anim_IsControllerActive(&instance->anim,0,0x22);
  if (_Var1 != G2FALSE) {
                    /* WARNING: Subroutine does not return */
    G2Anim_DisableController(&instance->anim,0,0x22);
  }
  _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xdfffffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSelectMotionAnim(struct __CharacterState *In /*$s6*/, int CurrentSection /*$s7*/, int Frames /*$s4*/, int *Anim /*$fp*/)
 // line 897, offset 0x800a65c0
	/* begin block 1 */
		// Start line: 898
		// Start offset: 0x800A65C0
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -48
	// 		int switchType; // $s0
	// 		int frame; // $s1

		/* begin block 1.1 */
			// Start line: 1139
			// Start offset: 0x800A6A40
			// Variables:
		// 		int adjustment; // $s0
		/* end block 1.1 */
		// End offset: 0x800A6B2C
		// End Line: 1160

		/* begin block 1.2 */
			// Start line: 1165
			// Start offset: 0x800A6B48
			// Variables:
		// 		struct _G2AnimSection_Type *animSectionA; // $s1
		// 		struct _G2AnimSection_Type *animSectionB; // $s2
		// 		struct _G2AnimKeylist_Type *keylist; // $s3
		// 		int keylistID; // $s5
		/* end block 1.2 */
		// End offset: 0x800A6C00
		// End Line: 1187
	/* end block 1 */
	// End offset: 0x800A6C00
	// End Line: 1195

	/* begin block 2 */
		// Start line: 1973
	/* end block 2 */
	// End Line: 1974

	/* begin block 3 */
		// Start line: 1982
	/* end block 3 */
	// End Line: 1983

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razSelectMotionAnim(__CharacterState *In,int CurrentSection,int Frames,int *Anim)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  _G2Bool_Enum _Var4;
  int count;
  _Instance *p_Var5;
  __CharacterState *instance;
  int type;
  bool bVar6;
  int frame;
  _G2AnimSection_Type *section;
  _G2AnimSection_Type *section_00;
  _G2AnimKeylist_Type *keylist;
  
  bVar6 = false;
  frame = 0;
  if (_CHAR____800d5588 < 0xeb9) {
    if (_CHAR____800d5588 - 0xae0U < 0x3d9) {
      uVar2 = _BlockVramEntry_800d59a0._12_4_ & 0xffffdfff;
      uVar3 = _BlockVramEntry_800d59a0._12_4_ & 0x20000000;
      instance = In;
      count = CurrentSection;
      type = Frames;
      _BlockVramEntry_800d59a0._12_4_ = uVar2;
      if (uVar3 != 0) {
        instance = (__CharacterState *)In->CharacterInstance;
        razResetPauseTranslation((_Instance *)instance);
      }
      if (*Anim == 0x3c) {
        if ((_CHAR____800d5720 & 0xf) != 0) {
          bVar6 = true;
        }
        if ((_CHAR____800d5720 & 8) != 0) {
          frame = 7;
        }
        if ((_CHAR____800d5720 & 1) != 0) {
          frame = 0xd;
        }
        uVar2 = _CHAR____800d5720 & 4;
        if ((_CHAR____800d5720 & 2) != 0) {
          frame = 0x14;
        }
      }
      else {
        if (*Anim != 0x44) {
          razLaunchBubbles((int)instance,count,type);
          return;
        }
        if ((_CHAR____800d5720 & 0xf00) != 0) {
          bVar6 = true;
        }
        if ((_CHAR____800d5720 & 0x800) != 0) {
          frame = 7;
        }
        if ((_CHAR____800d5720 & 0x100) != 0) {
          frame = 0xd;
        }
        uVar2 = _CHAR____800d5720 & 0x400;
        if ((_CHAR____800d5720 & 0x200) != 0) {
          frame = 0x14;
        }
      }
      if (uVar2 != 0) {
        frame = 0x19;
      }
    }
    else {
      if (_CHAR____800d5588 < 0xae0) {
        _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x2000;
        count = *Anim;
        if (count == 0x40) {
          bVar6 = (_CHAR____800d5720 & 0xf0) != 0;
          if ((_CHAR____800d5720 & 0x80) != 0) {
            frame = 0xc;
          }
          if ((_CHAR____800d5720 & 0x10) != 0) {
            frame = 0x14;
          }
          uVar2 = _CHAR____800d5720 & 0x40;
          if ((_CHAR____800d5720 & 0x20) != 0) {
            frame = 0x20;
          }
        }
        else {
          if (count != 0x44) {
            if (count != 0x3c) {
              bVar6 = true;
            }
            goto LAB_800a68bc;
          }
          if ((_CHAR____800d5720 & 0xf00) == 0) {
            razSetCowlNoDraw((int)In);
            return;
          }
          bVar6 = true;
          if ((_CHAR____800d5720 & 0x800) != 0) {
            frame = 0xc;
          }
          if ((_CHAR____800d5720 & 0x100) != 0) {
            frame = 0x14;
          }
          uVar2 = _CHAR____800d5720 & 0x400;
          if ((_CHAR____800d5720 & 0x200) != 0) {
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
    if (_CHAR____800d5758 == 0) {
      _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xffffdfff;
    }
    if ((_BlockVramEntry_800d59a0._12_4_ & 0x20000000) != 0) {
      razResetPauseTranslation(In->CharacterInstance);
    }
    count = *Anim;
    if (count == 0x3c) {
      if ((_CHAR____800d5720 & 0xf) != 0) {
        bVar6 = true;
      }
      if ((_CHAR____800d5720 & 8) != 0) {
        frame = 5;
      }
      if ((_CHAR____800d5720 & 1) != 0) {
        frame = 0x17;
      }
      uVar2 = _CHAR____800d5720 & 4;
      if ((_CHAR____800d5720 & 2) != 0) {
        frame = 0x11;
      }
    }
    else {
      if (count != 0x40) {
        if (count != 0x44) {
          bVar6 = true;
        }
        goto LAB_800a68bc;
      }
      if ((_CHAR____800d5720 & 0xf0) != 0) {
        bVar6 = true;
      }
      if ((_CHAR____800d5720 & 0x80) != 0) {
        frame = 5;
      }
      if ((_CHAR____800d5720 & 0x10) != 0) {
        frame = 0x17;
      }
      uVar2 = _CHAR____800d5720 & 0x40;
      if ((_CHAR____800d5720 & 0x20) != 0) {
        frame = 0x11;
      }
    }
    if (uVar2 != 0) {
      frame = 0xb;
    }
  }
LAB_800a68bc:
  if (bVar6 == true) {
    if (CurrentSection == 2) {
      _CHAR____800d5720 = 0;
    }
    count = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x40,frame,Frames);
    if (count != 0) {
                    /* WARNING: Subroutine does not return */
      G2EmulationSwitchAnimation(In,CurrentSection,0x7c,frame,Frames,2);
    }
    _CHAR____800d55a8 = 0xccc;
    _CHAR____800d55aa = 0x1800;
    _CHAR____800d55ac = 0xadf;
    _CHAR____800d55ae = 0xeb8;
    frame = 0x40;
  }
  else {
    if (bVar6 < 3) {
      if (bVar6 != true) goto LAB_800a6a24;
      if (CurrentSection == 2) {
        _CHAR____800d5720 = 0;
      }
      count = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x3c,frame,Frames);
      if (count != 0) {
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0x7b,frame,Frames,2);
      }
      _CHAR____800d55a8 = 0x1000;
      _CHAR____800d55aa = 0x1c00;
      _CHAR____800d55ac = 0x8fc;
      _CHAR____800d55ae = 0xadf;
      frame = 0x3c;
    }
    else {
      if (bVar6 != true) goto LAB_800a6a24;
      if (CurrentSection == 2) {
        _CHAR____800d5720 = 0;
      }
      count = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x44,frame,Frames);
      if (count != 0) {
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,2,frame,Frames,2);
      }
      _CHAR____800d55a8 = 0xddb;
      _CHAR____800d55ac = 0xeb8;
      frame = 0x44;
      _CHAR____800d55aa = 0x1000;
      _CHAR____800d55ae = 0x1000;
    }
  }
  *Anim = frame;
LAB_800a6a24:
  if (CurrentSection == 0) {
    if ((_BlockVramEntry_800d59a0._12_4_ & 0x20000000) == 0) {
      razAdjustSpeed(In->CharacterInstance,1);
                    /* WARNING: Subroutine does not return */
      G2Timer_GetFrameTime();
    }
  }
  else {
    if (In->SectionList[0].Process == StateHandlerMove) {
      p_Var5 = In->CharacterInstance;
      section = (p_Var5->anim).section;
      section_00 = (p_Var5->anim).section + CurrentSection;
      _Var4 = G2AnimSection_IsInInterpolation(section);
      if ((_Var4 == G2FALSE) &&
         (_Var4 = G2AnimSection_IsInInterpolation(section_00), _Var4 == G2FALSE)) {
        frame = G2AnimSection_GetKeyframeNumber(section);
        count = G2AnimSection_GetKeyframeNumber(section_00);
        if (frame != count) {
          keylist = (p_Var5->anim).section[0].keylist;
          uVar1 = (p_Var5->anim).section[0].keylistID;
          frame = G2AnimSection_GetKeyframeNumber(section);
          count = G2AnimKeylist_GetKeyframeCount(keylist);
          count = (frame + 6) % count;
          frame = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,*Anim,count,6);
          if (frame != 0) {
            G2AnimSection_InterpToKeylistFrame(section_00,keylist,(uint)uVar1,count,600);
          }
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razApplyMotion(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/)
 // line 1199, offset 0x800a6c30
	/* begin block 1 */
		// Start line: 1200
		// Start offset: 0x800A6C30
		// Variables:
	// 		struct _G2SVector3_Type Vec; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1205
			// Start offset: 0x800A6C60
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $s0

			/* begin block 1.1.1 */
				// Start line: 1245
				// Start offset: 0x800A6D08
				// Variables:
			// 		long adjustment; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800A6DA4
			// End Line: 1255
		/* end block 1.1 */
		// End offset: 0x800A6DA4
		// End Line: 1256
	/* end block 1 */
	// End offset: 0x800A6DA4
	// End Line: 1258

	/* begin block 2 */
		// Start line: 2604
	/* end block 2 */
	// End Line: 2605

int razApplyMotion(__CharacterState *In,int CurrentSection)

{
  undefined auStack24 [8];
  
                    /* WARNING: Subroutine does not return */
  memset(auStack24,0,6);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razResetMotion(struct _Instance *instance /*$a0*/)
 // line 1262, offset 0x800a6dc0
	/* begin block 1 */
		// Start line: 2733
	/* end block 1 */
	// End Line: 2734

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razResetMotion(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  _Var1 = G2Anim_IsControllerActive(anim,0,0x22);
  if (_Var1 != G2FALSE) {
                    /* WARNING: Subroutine does not return */
    G2Anim_DisableController(anim,0,0x22);
  }
  _CHAR____800d5720 = 0;
                    /* WARNING: Subroutine does not return */
  G2Anim_SetSpeedAdjustment(anim,0x1000);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetDampingPhysics(struct _Instance *instance /*$a0*/)
 // line 1301, offset 0x800a6e14
	/* begin block 1 */
		// Start line: 2602
	/* end block 1 */
	// End Line: 2603

	/* begin block 2 */
		// Start line: 2783
	/* end block 2 */
	// End Line: 2784

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razSetDampingPhysics(_Instance *instance)

{
  _CHAR____800d557c = 0;
  _CHAR____800d5724 = 0;
  PhysicsMode.next = (_BlockVramEntry *)&mainMenuScreen;
  SetDampingPhysics(instance,*(int *)(_PlayerData + 0x44));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razEnterWater(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, struct evPhysicsSwimData *SwimData /*$s3*/)
 // line 1311, offset 0x800a6e4c
	/* begin block 1 */
		// Start line: 1312
		// Start offset: 0x800A6E4C
		// Variables:
	// 		struct _Instance *Inst; // $s2
	/* end block 1 */
	// End offset: 0x800A70D4
	// End Line: 1409

	/* begin block 2 */
		// Start line: 2804
	/* end block 2 */
	// End Line: 2805

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razEnterWater(__CharacterState *In,int CurrentSection,evPhysicsSwimData *SwimData)

{
  _Instance *Inst;
  int CurrentSection_00;
  int NewAnim;
  int local_20;
  int local_1c;
  
  Inst = razGetHeldWeapon();
  if ((SwimData->rc & 0x10U) != 0) {
    if ((_CHAR____800d564c == 1) && ((_CHAR____800d561c & 0x10) == 0)) {
      _CHAR____800d5610 = 100000;
      SetPhysics(In->CharacterInstance,-0x10,0,0,0);
      PhysicsMode.next = (_BlockVramEntry *)0x0;
    }
    else {
      if (Inst != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query(Inst,4);
      }
      if (((_CHAR____800d5574 & 0x40000) == 0) && (_CHAR____800d564c == 1)) {
        if (PhysicsMode.next != (_BlockVramEntry *)&mainMenuScreen) {
          razSetDampingPhysics(In->CharacterInstance);
        }
        if ((In->CharacterInstance->zVel == 0) || ((_CHAR____800d5574 & 0x400004) != 0)) {
          razResetMotion(In->CharacterInstance);
          StateSwitchStateCharacterData(In,StateHandlerSwim,0);
        }
        TrailWaterFX(In->CharacterInstance,9,1,1);
        TrailWaterFX(In->CharacterInstance,0xd,1,1);
        TrailWaterFX(In->CharacterInstance,0x1f,1,1);
        TrailWaterFX(In->CharacterInstance,0x29,1,1);
      }
    }
  }
  if (((SwimData->rc & 0x800U) != 0) && (_CHAR____800d5600 == 1)) {
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
                    /* WARNING: Subroutine does not return */
    G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,local_20,local_1c);
  }
  if (((SwimData->rc & 0x100U) != 0) && (CurrentSection == 0)) {
    if (Inst != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(Inst,4);
    }
    razSetDampingPhysics(In->CharacterInstance);
                    /* WARNING: Subroutine does not return */
    PurgeMessageQueue(&In->SectionList[0].Event);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetSwimVelocity(struct _Instance *instance /*$a0*/, int vel /*$a1*/, int accl /*$a2*/)
 // line 1436, offset 0x800a70f0
	/* begin block 1 */
		// Start line: 1438
		// Start offset: 0x800A70F0
	/* end block 1 */
	// End offset: 0x800A713C
	// End Line: 1452

	/* begin block 2 */
		// Start line: 3055
	/* end block 2 */
	// End Line: 3056

	/* begin block 3 */
		// Start line: 3056
	/* end block 3 */
	// End Line: 3057

	/* begin block 4 */
		// Start line: 3062
	/* end block 4 */
	// End Line: 3063

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  _CHAR____800d577a = (undefined2)(iVar1 >> 0xc);
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
 // line 1455, offset 0x800a7144
	/* begin block 1 */
		// Start line: 1456
		// Start offset: 0x800A7144
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -24

		/* begin block 1.1 */
			// Start line: 1463
			// Start offset: 0x800A716C
		/* end block 1.1 */
		// End offset: 0x800A71DC
		// End Line: 1501
	/* end block 1 */
	// End offset: 0x800A721C
	// End Line: 1512

	/* begin block 2 */
		// Start line: 3095
	/* end block 2 */
	// End Line: 3096

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
                    /* WARNING: Subroutine does not return */
    G2Anim_SetController_Vector(&instance->anim,0,8,&local_18);
  }
  if (data->rc == 10) {
    local_18.y = 0;
    local_18.z = 0;
    local_18.x = -data->ForwardXRotation;
                    /* WARNING: Subroutine does not return */
    G2EmulationSetInterpController_Vector(instance,0xe,0xe,&local_18,3,0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSwitchVAnimCharacterGroup(struct _Instance *instance /*$s3*/, int animGroup /*$s4*/, int *frame /*$a2*/, int *frames /*$a3*/)
 // line 1516, offset 0x800a7230
	/* begin block 1 */
		// Start line: 1517
		// Start offset: 0x800A7230
		// Variables:
	// 		int i; // $s0
	// 		int rc; // $v1
	// 		int temp[3]; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A72CC
	// End Line: 1530

	/* begin block 2 */
		// Start line: 3233
	/* end block 2 */
	// End Line: 3234

int razSwitchVAnimCharacterGroup(_Instance *instance,int animGroup,int *frame,int *frames)

{
  int *piVar1;
  int frames_00;
  int frame_00;
  int section;
  int iVar2;
  int local_30;
  int local_28 [4];
  
  local_28[0] = InterfaceItem_800cf854.name._20_4_;
  local_28[1] = InterfaceItem_800cf854.name._24_4_;
  local_28[2] = InterfaceItem_800cf854.name._28_4_;
  piVar1 = local_28;
  if (frame == (int *)0x0) {
    frame = piVar1;
  }
  section = 0;
  if (frames == (int *)0x0) {
    do {
      frames_00 = *piVar1;
      piVar1 = piVar1 + 1;
      iVar2 = section + 1;
      frame_00 = *frame;
      frame = frame + 1;
      frames_00 = razSwitchVAnimGroup(instance,section,animGroup,frame_00,frames_00);
      section = iVar2;
    } while (iVar2 < 3);
    return frames_00;
  }
  razSwitchVAnimSingle(instance,animGroup,(int)frame,(int)frames,local_30);
  return (int)piVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSwitchVAnimGroup(struct _Instance *instance /*$a0*/, int section /*$a1*/, int animGroup /*$a2*/, int frame /*$a3*/, int frames /*stack 16*/)
 // line 1535, offset 0x800a72ec
	/* begin block 1 */
		// Start line: 1536
		// Start offset: 0x800A72EC
		// Variables:
	// 		int index; // $t0
	// 		int rc; // $v1
	/* end block 1 */
	// End offset: 0x800A7338
	// End Line: 1556

	/* begin block 2 */
		// Start line: 3277
	/* end block 2 */
	// End Line: 3278

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int razSwitchVAnimGroup(_Instance *instance,int section,int animGroup,int frame,int frames)

{
  int iVar1;
  
  iVar1 = 1;
  if (_CHAR____800d5600 != 0) {
    iVar1 = _CHAR____800d5600 + -1;
    if (2 < iVar1) {
      iVar1 = 3;
    }
    razSwitchVAnim(instance,section,
                   (__VAnim *)(*(int *)(_PlayerData + 0x18) + (animGroup + iVar1) * 8),frame,frames)
    ;
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnimCharacterSingle(struct _Instance *instance /*$s3*/, int anim /*$s4*/, int *frame /*$a2*/, int *frames /*$a3*/)
 // line 1561, offset 0x800a7348
	/* begin block 1 */
		// Start line: 1562
		// Start offset: 0x800A7348
		// Variables:
	// 		int i; // $s0
	// 		int temp[3]; // stack offset -40
	/* end block 1 */
	// End offset: 0x800A73E0
	// End Line: 1574

	/* begin block 2 */
		// Start line: 3336
	/* end block 2 */
	// End Line: 3337

void razSwitchVAnimCharacterSingle(_Instance *instance,int anim,int *frame,int *frames)

{
  int frame_00;
  int section;
  int iVar1;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_28 = InterfaceItem_800cf854.name._20_4_;
  local_24 = InterfaceItem_800cf854.name._24_4_;
  local_20 = InterfaceItem_800cf854.name._28_4_;
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
 // line 1577, offset 0x800a7400
	/* begin block 1 */
		// Start line: 1578
		// Start offset: 0x800A7400
	/* end block 1 */
	// End offset: 0x800A7400
	// End Line: 1578

	/* begin block 2 */
		// Start line: 3373
	/* end block 2 */
	// End Line: 3374

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razSwitchVAnimSingle(_Instance *instance,int section,int anim,int frame,int frames)

{
  razSwitchVAnim(instance,section,(__VAnim *)(*(int *)(_PlayerData + 0x1c) + anim * 8),frame,frames)
  ;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchVAnim(struct _Instance *instance /*$a0*/, int section /*$a1*/, struct __VAnim *vAnim /*$v1*/, int frame /*$a3*/, int frames /*stack 16*/)
 // line 1587, offset 0x800a7434
	/* begin block 1 */
		// Start line: 3396
	/* end block 1 */
	// End Line: 3397

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
                    /* WARNING: Subroutine does not return */
  G2EmulationInstanceSwitchAnimationAlpha
            (instance,CurrentSection,NewAnim,frame,frames,local_14,AlphaTable);
}



// decompiled code
// original method signature: 
// int /*$ra*/ razProcessSAnim(struct _Instance *instance /*$s3*/, int mode /*$a1*/)
 // line 1615, offset 0x800a7500
	/* begin block 1 */
		// Start line: 1616
		// Start offset: 0x800A7500
		// Variables:
	// 		int rc; // $s2
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 1641
			// Start offset: 0x800A75C8
			// Variables:
		// 		struct __VAnim *vanim; // $s1
		/* end block 1.1 */
		// End offset: 0x800A7630
		// End Line: 1652
	/* end block 1 */
	// End offset: 0x800A7654
	// End Line: 1663

	/* begin block 2 */
		// Start line: 3452
	/* end block 2 */
	// End Line: 3453

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int razProcessSAnim(_Instance *instance,int mode)

{
  short sVar1;
  short sVar2;
  __VAnim *Data;
  int iVar3;
  
  iVar3 = 0;
  if (mode == 0x8000000) {
    sVar2 = *(short *)((int)_CHAR____800d57c0 + 8);
    sVar1 = 1;
  }
  else {
    if (mode < 0x8000001) {
      if ((undefined *)mode != &DAT_00100015) goto LAB_800a75a8;
      sVar2 = *(short *)((int)_CHAR____800d57c0 + 8);
      sVar1 = 2;
    }
    else {
      if (mode != 0x8000003) goto LAB_800a75a8;
      sVar2 = *(short *)((int)_CHAR____800d57c0 + 8);
      sVar1 = 3;
    }
  }
  if (sVar2 == sVar1) {
    iVar3 = 1;
  }
LAB_800a75a8:
  if (iVar3 == 0) {
    return iVar3;
  }
  Data = *(__VAnim **)((int)_CHAR____800d57c0 + 4);
  if (Data == (__VAnim *)0x0) {
                    /* WARNING: Subroutine does not return */
    G2Anim_SetSpeedAdjustment((_G2Anim_Type *)(__CharacterState *)&instance->anim,0x1000);
  }
  if (*(__VAnim **)Data != (__VAnim *)0x0) {
    _CHAR____800d57c0 = (__VAnim **)Data;
    razSwitchVAnim(instance,0,*(__VAnim **)Data,-1,-1);
                    /* WARNING: Subroutine does not return */
    G2Anim_SetSpeedAdjustment(&instance->anim,(int)*(short *)(_CHAR____800d57c0 + 3));
  }
  iVar3 = (int)_CHAR____800d57c0;
  _CHAR____800d57c0 = (__VAnim **)Data;
  StateHandlerIdle((__CharacterState *)&instance->anim,mode,(int)Data);
  return iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSwitchStringAnimation(struct _Instance *instance /*$s2*/, int anim /*$a1*/)
 // line 1667, offset 0x800a7678
	/* begin block 1 */
		// Start line: 1668
		// Start offset: 0x800A7678
		// Variables:
	// 		struct __VAnim *vanim; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x800A7724
	// End Line: 1684

	/* begin block 2 */
		// Start line: 3564
	/* end block 2 */
	// End Line: 3565

	/* begin block 3 */
		// Start line: 3568
	/* end block 3 */
	// End Line: 3569

/* WARNING: Removing unreachable block (ram,0x800a76ec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razSwitchStringAnimation(_Instance *instance,int anim)

{
  _CHAR____800d57c0 = *(__VAnim **)(anim * 4 + *(int *)(_PlayerData + 0x20));
  if (*(__VAnim **)_CHAR____800d57c0 != (__VAnim *)0x0) {
    razSwitchVAnim(instance,0,*(__VAnim **)_CHAR____800d57c0,-1,-1);
    razSetCowlNoDraw((int)instance);
    return;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckStringAnimation(struct _Instance *instance /*$s1*/, int mode /*$a1*/)
 // line 1687, offset 0x800a7740
	/* begin block 1 */
		// Start line: 1688
		// Start offset: 0x800A7740
		// Variables:
	// 		int rc; // $s0
	/* end block 1 */
	// End offset: 0x800A7788
	// End Line: 1698

	/* begin block 2 */
		// Start line: 3614
	/* end block 2 */
	// End Line: 3615

	/* begin block 3 */
		// Start line: 3617
	/* end block 3 */
	// End Line: 3618

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CheckStringAnimation(_Instance *instance,int mode)

{
  int iVar1;
  
  if ((_CHAR____800d57c0 != 0) && (iVar1 = razProcessSAnim(instance,mode), _CHAR____800d57c0 != 0))
  {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(instance,0x100000,0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razLaunchBubbles(int segments /*$s2*/, int count /*$s0*/, int type /*$s1*/)
 // line 1752, offset 0x800a77a0
	/* begin block 1 */
		// Start line: 3504
	/* end block 1 */
	// End Line: 3505

void razLaunchBubbles(int segments,int count,int type)

{
  if ((segments & 1U) != 0) {
    TrailWaterFX((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],0x20,count,type);
    TrailWaterFX((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],0x2a,count,type);
  }
  if ((segments & 2U) != 0) {
    TrailWaterFX((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],8,count,type);
    TrailWaterFX((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0],0xc,count,type);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetCowlNoDraw(int mode /*$t0*/)
 // line 1765, offset 0x800a7838
	/* begin block 1 */
		// Start line: 1766
		// Start offset: 0x800A7838
	/* end block 1 */
	// End offset: 0x800A78E0
	// End Line: 1775

	/* begin block 2 */
		// Start line: 3720
	/* end block 2 */
	// End Line: 3721

void razSetCowlNoDraw(int mode)

{
  byte bVar1;
  int iVar2;
  ushort *puVar3;
  
  puVar3 = (ushort *)(InterfaceItems.name + 0xc);
  do {
    if (mode == 0) {
      iVar2 = (uint)*puVar3 * 0xc +
              *(int *)(*(int *)((int)*(short *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x10a) *
                                4 + *(int *)(*(int *)(theCamera.core.vvNormalWorVecMat[1].t[0] +
                                                     0x1c) + 0xc)) + 0x14);
      bVar1 = *(byte *)(iVar2 + 7) & 0xef;
    }
    else {
      iVar2 = (uint)*puVar3 * 0xc +
              *(int *)(*(int *)((int)*(short *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x10a) *
                                4 + *(int *)(*(int *)(theCamera.core.vvNormalWorVecMat[1].t[0] +
                                                     0x1c) + 0xc)) + 0x14);
      bVar1 = *(byte *)(iVar2 + 7) | 0x10;
    }
    *(byte *)(iVar2 + 7) = bVar1;
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < -0x7ff3085a);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razAttachControllers()
 // line 1777, offset 0x800a78e8
	/* begin block 1 */
		// Start line: 1778
		// Start offset: 0x800A78E8
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x800A793C
	// End Line: 1785

	/* begin block 2 */
		// Start line: 3748
	/* end block 2 */
	// End Line: 3749

/* WARNING: Unknown calling convention yet parameter storage is locked */

void razAttachControllers(void)

{
  G2Anim_AttachControllerToSeg
            ((_G2Anim_Type *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x194),
             (uint)(ushort)InterfaceItems.itemType,(uint)(ushort)InterfaceItems.nextItem);
                    /* WARNING: Subroutine does not return */
  G2Anim_DisableController
            ((_G2Anim_Type *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x194),
             (uint)(ushort)InterfaceItems.itemType,(uint)(ushort)InterfaceItems.nextItem);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPlayerEvent()
 // line 1787, offset 0x800a7950
	/* begin block 1 */
		// Start line: 1788
		// Start offset: 0x800A7950
		// Variables:
	// 		void (*process)(); // $s0
	// 		int message; // stack offset -16
	// 		int data; // stack offset -12

		/* begin block 1.1 */
			// Start line: 1812
			// Start offset: 0x800A7A10
		/* end block 1.1 */
		// End offset: 0x800A7A4C
		// End Line: 1821
	/* end block 1 */
	// End offset: 0x800A7C4C
	// End Line: 1887

	/* begin block 2 */
		// Start line: 3778
	/* end block 2 */
	// End Line: 3779

	/* begin block 3 */
		// Start line: 3785
	/* end block 3 */
	// End Line: 3786

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void razSetPlayerEvent(void)

{
  code *pcVar1;
  uint uVar2;
  _Instance *p_Var3;
  int iVar4;
  int *Message;
  int local_10;
  int local_c;
  
  pcVar1 = _CHAR____800d5220;
  local_10 = 0;
  local_c = 0;
  if ((((_CHAR____800d55f0 & 1) != 0) && (_CHAR____800d5600 != 3)) &&
     (_CHAR____800d5220 == StateHandlerIdle)) {
    _CHAR____800d57c4 = _CHAR____800d57c4 | 1;
  }
  if ((((_CHAR____800d55f0 & 4) != 0) && (_CHAR____800d5600 != 3)) &&
     (_CHAR____800d5220 == StateHandlerCrouch)) {
    _CHAR____800d57c4 = _CHAR____800d57c4 | 2;
  }
  if ((((_CHAR____800d55f0 & 8) != 0) && (_CHAR____800d5600 != 3)) &&
     (_CHAR____800d5220 == StateHandlerIdle)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)(_CHAR____800d55ec + 0x18),4);
  }
  if (((((_CHAR____800d55f0 & 0x20) != 0) && (p_Var3 = razGetHeldItem(), p_Var3 == (_Instance *)0x0)
       ) && (_CHAR____800d564c == 1)) &&
     (((pcVar1 == StateHandlerIdle || (pcVar1 == StateHandlerStartMove)) ||
      ((((pcVar1 == StateHandlerMove ||
         ((pcVar1 == StateHandlerJump || (pcVar1 == StateHandlerFall)))) ||
        (pcVar1 == StateHandlerSwim)) || (pcVar1 == StateHandlerAutoFace)))))) {
    _CHAR____800d57c4 = _CHAR____800d57c4 | 0x10;
  }
  Message = &local_10;
  if ((_CHAR____800d55f0 & 0x40) != 0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)(_CHAR____800d55ec + 0x30),10);
  }
  iVar4 = StateHandlerDecodeHold(Message,&local_c);
  if ((iVar4 != 0) && (local_c != 0)) {
    if (local_10 == 0x1000002) {
      _CHAR____800d57c4 = _CHAR____800d57c4 | 0x40;
    }
    if (local_10 == 0x100000a) {
      _CHAR____800d57c4 = _CHAR____800d57c4 | 0x80;
    }
    if (local_10 == 0x1000018) {
      _CHAR____800d57c4 = _CHAR____800d57c4 | 0x100;
    }
  }
  if (((_CHAR____800d5574 & 0x20000) != 0) && (_CHAR____800d5600 - 1U < 3)) {
    _CHAR____800d57c4 = _CHAR____800d57c4 | 0x200;
  }
  if (local_10 != 0x80000) {
    RAZIEL_QueryEngagedInstance((int)Message);
    return;
  }
  uVar2 = _CHAR____800d57c4 | 0x400;
  if ((_CHAR____800d55f0 & 0x4000) != 0) {
    uVar2 = _CHAR____800d57c4 | 0xc00;
  }
  _CHAR____800d57c4 = uVar2;
  if ((_CHAR____800d55b0 & 0x40) != 0) {
    _CHAR____800d57c4 = _CHAR____800d57c4 | 0x2000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razClearPlayerEvent()
 // line 1889, offset 0x800a7c5c
	/* begin block 1 */
		// Start line: 3993
	/* end block 1 */
	// End Line: 3994

	/* begin block 2 */
		// Start line: 3995
	/* end block 2 */
	// End Line: 3996

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void razClearPlayerEvent(void)

{
  if ((_BlockVramEntry_800d59a0._12_4_ & 0x100000) != 0) {
    _CHAR____800d57c4 = _CHAR____800d57c4 & 0x2000;
    return;
  }
  _CHAR____800d57c4 = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetPlayerEventHistory(unsigned long event /*$a0*/)
 // line 1898, offset 0x800a7c94
	/* begin block 1 */
		// Start line: 4011
	/* end block 1 */
	// End Line: 4012

	/* begin block 2 */
		// Start line: 4012
	/* end block 2 */
	// End Line: 4013

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void razSetPlayerEventHistory(ulong event)

{
  _CHAR____800d57c8 = _CHAR____800d57c8 | event;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ razSideMoveSpiderCheck(struct _Instance *instance /*$s2*/, int x /*$a1*/)
 // line 1905, offset 0x800a7cac
	/* begin block 1 */
		// Start line: 1906
		// Start offset: 0x800A7CAC
		// Variables:
	// 		struct SVECTOR startVec; // stack offset -32
	// 		struct SVECTOR endVec; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A7D60
	// End Line: 1925

	/* begin block 2 */
		// Start line: 4025
	/* end block 2 */
	// End Line: 4026

int razSideMoveSpiderCheck(_Instance *instance,int x)

{
  SVECTOR aSStack32 [2];
  
                    /* WARNING: Subroutine does not return */
  PHYSICS_GenericLineCheckSetup((short)x,0,0xc0,aSStack32);
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ RAZIEL_QueryEngagedInstance(int index /*$a0*/)
 // line 1942, offset 0x800a7d78
	/* begin block 1 */
		// Start line: 4115
	/* end block 1 */
	// End Line: 4116

	/* begin block 2 */
		// Start line: 4117
	/* end block 2 */
	// End Line: 4118

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Instance * RAZIEL_QueryEngagedInstance(int index)

{
  if ((_CHAR____800d55f0 & 1 << (index & 0x1fU)) == 0) {
    return (_Instance *)0x0;
  }
  return *(_Instance **)(index * 8 + _CHAR____800d55ec);
}



// decompiled code
// original method signature: 
// int /*$ra*/ razUpdateSoundRamp(struct _Instance *instance /*$a0*/, struct _SoundRamp *sound /*$s0*/)
 // line 1955, offset 0x800a7db0
	/* begin block 1 */
		// Start line: 1956
		// Start offset: 0x800A7DB0
		// Variables:
	// 		int volume; // $s1
	// 		int time; // $t0

		/* begin block 1.1 */
			// Start line: 1971
			// Start offset: 0x800A7E14
			// Variables:
		// 		int startPitch; // $v1
		// 		int endPitch; // $v0
		// 		int startVolume; // $a1
		// 		int endVolume; // $v0
		/* end block 1.1 */
		// End offset: 0x800A7E9C
		// End Line: 1986
	/* end block 1 */
	// End offset: 0x800A7E9C
	// End Line: 1989

	/* begin block 2 */
		// Start line: 4137
	/* end block 2 */
	// End Line: 4138

	/* begin block 3 */
		// Start line: 4144
	/* end block 3 */
	// End Line: 4145

int razUpdateSoundRamp(_Instance *instance,_SoundRamp *sound)

{
  int maxVolume;
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  if (sound->soundHandle == 0) {
    maxVolume = 0;
  }
  else {
    iVar3 = sound->soundTotalTime;
    maxVolume = sound->soundTimer + theCamera.tiltList[0][0];
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
                    /* WARNING: Subroutine does not return */
          SndEndLoop(sound->soundHandle);
        }
      }
    }
  }
  return maxVolume;
}



// decompiled code
// original method signature: 
// void /*$ra*/ razSetupSoundRamp(struct _Instance *instance /*$a0*/, struct _SoundRamp *sound /*$s0*/, int sfx /*$a1*/, int startPitch /*$s2*/, int endPitch /*stack 16*/, int startVolume /*stack 20*/, int endVolume /*stack 24*/, int timer /*stack 28*/, int distance /*stack 32*/)
 // line 1995, offset 0x800a7eb4
	/* begin block 1 */
		// Start line: 4235
	/* end block 1 */
	// End Line: 4236

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
 // line 2019, offset 0x800a7f58
	/* begin block 1 */
		// Start line: 2020
		// Start offset: 0x800A7F58
		// Variables:
	// 		int soundFlag; // $s0
	/* end block 1 */
	// End offset: 0x800A7FC4
	// End Line: 2039

	/* begin block 2 */
		// Start line: 4290
	/* end block 2 */
	// End Line: 4291

void RAZIEL_SetInteractiveMusic(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 1 << (param_1 & 0x1f);
  if (param_2 == 0) {
    if ((uGpfffffcbc & uVar1) != 0) {
      SOUND_ResetMusicModifier(param_1);
    }
    uGpfffffcbc = uGpfffffcbc & ~uVar1;
  }
  else {
    if ((uGpfffffcbc & uVar1) == 0) {
      SOUND_SetMusicVolume(param_1);
    }
    uGpfffffcbc = uGpfffffcbc | uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_DebugHurtRaziel()
 // line 2040, offset 0x800a7fd4
	/* begin block 1 */
		// Start line: 4338
	/* end block 1 */
	// End Line: 4339

/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_DebugHurtRaziel(void)

{
                    /* WARNING: Subroutine does not return */
  LoseHealth(0x1000);
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_StartNewGame()
 // line 2045, offset 0x800a7ff4
	/* begin block 1 */
		// Start line: 4348
	/* end block 1 */
	// End Line: 4349

/* WARNING: Unknown calling convention yet parameter storage is locked */

void RAZIEL_StartNewGame(void)

{
                    /* WARNING: Subroutine does not return */
  memset(&Raziel,0,0x5bc);
}



// decompiled code
// original method signature: 
// int /*$ra*/ razInBaseArea(char *name /*$s1*/, int length /*$s0*/)
 // line 2054, offset 0x800a801c
	/* begin block 1 */
		// Start line: 2055
		// Start offset: 0x800A801C
		// Variables:
	// 		char string[9]; // stack offset -32
	/* end block 1 */
	// End offset: 0x800A8064
	// End Line: 2068

	/* begin block 2 */
		// Start line: 4367
	/* end block 2 */
	// End Line: 4368

int razInBaseArea(char *name,int length)

{
  char acStack32 [16];
  
                    /* WARNING: Subroutine does not return */
  strcpy(acStack32,(char *)&theCamera.focusRotVel);
}



// decompiled code
// original method signature: 
// void /*$ra*/ razPrepGlyph()
 // line 2073, offset 0x800a8078
	/* begin block 1 */
		// Start line: 2074
		// Start offset: 0x800A8078
		// Variables:
	// 		struct _Instance *heldInst; // $s0
	/* end block 1 */
	// End offset: 0x800A80AC
	// End Line: 2083

	/* begin block 2 */
		// Start line: 4416
	/* end block 2 */
	// End Line: 4417

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void razPrepGlyph(void)

{
  _Instance *p_Var1;
  
  razReaverOff();
  p_Var1 = razGetHeldItem();
  if (p_Var1 != (_Instance *)0x0) {
    razSetFadeEffect(0,0x1000,0x100);
    _CHAR____800d5688 = p_Var1;
  }
  _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x4000;
  return;
}





