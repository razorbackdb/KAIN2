#include "THISDUST.H"
#include "ALGOCTRL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitAlgorithmicWings(struct _Instance *instance /*$s2*/)
 // line 24, offset 0x800a0f00
	/* begin block 1 */
		// Start line: 25
		// Start offset: 0x800A0F00
		// Variables:
	// 		struct _G2EulerAngles_Type Rot; // stack offset -24
	// 		unsigned char i; // $s1
	/* end block 1 */
	// End offset: 0x800A1080
	// End Line: 91

	/* begin block 2 */
		// Start line: 48
	/* end block 2 */
	// End Line: 49

	/* begin block 3 */
		// Start line: 59
	/* end block 3 */
	// End Line: 60

void InitAlgorithmicWings(_Instance *instance)

{
  MATRIX *pMVar1;
  u_int segNumber;
  byte bVar2;
  _G2EulerAngles_Type local_18;
  
  if ((AlgoControlFlag & 1U) == 0) {
    pMVar1 = instance->matrix;
    bVar2 = 0x33;
    if (pMVar1 == (MATRIX *)0x0) {
      INSTANCE_Query(instance,(int)&DAT_00100006,0);
    }
    else {
      while( true ) {
        if (pMVar1 == (MATRIX *)0x0) {
          local_18.z = 0;
          local_18.y = 0;
          local_18.x = 0;
        }
        else {
          G2EulerAngles_FromMatrix(&local_18,(instance->anim).segMatrices + ((u_int)bVar2 - 1),0x15);
        }
        segNumber = (u_int)bVar2;
        G2Anim_DisableController(&instance->anim,segNumber,8);
        G2EmulationSetInterpController_Vector
                  (instance,segNumber,8,(_G2SVector3_Type *)&local_18,(segNumber - 0x32) * 3,2);
        bVar2 = bVar2 + 1;
        if (0x35 < bVar2) break;
        pMVar1 = instance->matrix;
      }
      bVar2 = 0x3b;
      do {
        if (instance->matrix == (MATRIX *)0x0) {
          local_18.z = 0;
          local_18.y = 0;
          local_18.x = 0;
        }
        else {
          G2EulerAngles_FromMatrix(&local_18,(instance->anim).segMatrices + ((u_int)bVar2 - 1),0x15);
        }
        segNumber = (u_int)bVar2;
        G2Anim_DisableController(&instance->anim,segNumber,8);
        G2EmulationSetInterpController_Vector
                  (instance,segNumber,8,(_G2SVector3_Type *)&local_18,(segNumber - 0x3a) * 3,2);
        bVar2 = bVar2 + 1;
      } while (bVar2 < 0x3e);
      AlgoControlFlag = AlgoControlFlag | 1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DeInitAlgorithmicWings(struct _Instance *instance /*$s1*/)
 // line 94, offset 0x800a1098
	/* begin block 1 */
		// Start line: 95
		// Start offset: 0x800A1098
		// Variables:
	// 		unsigned char i; // $s0
	/* end block 1 */
	// End offset: 0x800A1114
	// End Line: 114

	/* begin block 2 */
		// Start line: 219
	/* end block 2 */
	// End Line: 220

	/* begin block 3 */
		// Start line: 225
	/* end block 3 */
	// End Line: 226

void DeInitAlgorithmicWings(_Instance *instance)

{
  byte bVar1;
  
  if ((AlgoControlFlag & 1U) != 0) {
    bVar1 = 0x33;
    do {
      _G2Anim_FindController(&instance->anim,(u_int)bVar1,8);
      bVar1 = bVar1 + 1;
    } while (bVar1 < 0x36);
    bVar1 = 0x3b;
    do {
      _G2Anim_FindController(&instance->anim,(u_int)bVar1,8);
      bVar1 = bVar1 + 1;
    } while (bVar1 < 0x3e);
    AlgoControlFlag = AlgoControlFlag & 0xfffffffe;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ AlgorithmicWings(struct _Instance *instance /*$s0*/, struct evAnimationControllerDoneData *ControllerData /*$s1*/)
 // line 117, offset 0x800a1128
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x800A1128
		// Variables:
	// 		struct _G2EulerAngles_Type Rot; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A1184
	// End Line: 143

	/* begin block 2 */
		// Start line: 273
	/* end block 2 */
	// End Line: 274

void AlgorithmicWings(_Instance *instance,evAnimationControllerDoneData *ControllerData)

{
  _G2EulerAngles_Type _Stack24;
  
  G2EulerAngles_FromMatrix
            (&_Stack24,(instance->anim).segMatrices + ControllerData->segment + -1,0x15);
  G2EmulationSetInterpController_Vector
            (instance,ControllerData->segment,ControllerData->type,(_G2SVector3_Type *)&_Stack24,5,2
            );
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ AlgorithmicNeck(struct _Instance *Player /*$s1*/, struct _Instance *Target /*$s2*/)
 // line 150, offset 0x800a1198
	/* begin block 1 */
		// Start line: 151
		// Start offset: 0x800A1198
		// Variables:
	// 		struct _Position From; // stack offset -96
	// 		struct _Position To; // stack offset -88
	// 		struct _Rotation Rot1; // stack offset -80
	// 		int Diff; // $v1
	// 		struct MATRIX matrix; // stack offset -72

		/* begin block 1.1 */
			// Start line: 162
			// Start offset: 0x800A11CC
			// Variables:
		// 		struct evCollideInstanceStatsData data; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x800A1238
		// End Line: 183

		/* begin block 1.2 */
			// Start line: 208
			// Start offset: 0x800A12DC
			// Variables:
		// 		struct MATRIX *matrix; // $v1
		/* end block 1.2 */
		// End offset: 0x800A1314
		// End Line: 223
	/* end block 1 */
	// End offset: 0x800A1404
	// End Line: 256

	/* begin block 2 */
		// Start line: 345
	/* end block 2 */
	// End Line: 346

void AlgorithmicNeck(_Instance *Player,_Instance *Target)

{
  short sVar1;
  u_int uVar2;
  int iVar3;
  _G2Bool_Enum _Var4;
  u_long uVar5;
  u_int uVar6;
  _Position local_60;
  _Position local_58;
  _Rotation local_50;
  MATRIX MStack72;
  evCollideInstanceStatsData eStack40;
  
  uVar2 = Raziel.Senses.Flags & 0xfffffff7;
  uVar6 = Raziel.Senses.Flags & 0x10;
  Raziel.Senses.Flags = uVar2;
  if (uVar6 != 0) {
    TransposeMatrix((u_char *)Player->oldMatrix,(u_char *)&MStack72);
    iVar3 = INSTANCE_SetStatsData
                      (Player,(_Instance *)0x0,&Raziel.Senses.lookAtPoint,&eStack40,&MStack72);
    if (((iVar3 != 0) && (eStack40.distance < 0xc80)) &&
       (iVar3 = MATH3D_ConeDetect(&eStack40.relativePosition,0x3c7,0x3c7), iVar3 != 0)) {
      Raziel.Senses.Flags = Raziel.Senses.Flags | 8;
    }
  }
  if ((Target == (_Instance *)0x0) && ((Raziel.Senses.Flags & 8U) == 0)) {
    _Var4 = G2Anim_DetachControllerFromSeg(&Player->anim,0x11,8);
    if (_Var4 != G2FALSE) {
      G2Anim_InterpDisableController(&Player->anim,0x11,8,900);
    }
  }
  else {
    _Var4 = G2Anim_DetachControllerFromSeg(&Player->anim,0x11,8);
    if (_Var4 == G2FALSE) {
      G2Anim_DisableController(&Player->anim,0x11,8);
    }
    if ((Raziel.Senses.Flags & 8U) == 0) {
      uVar5 = INSTANCE_Post(Target,0xc);
      if (uVar5 == 0) {
        return;
      }
      local_58.x = *(short *)(uVar5 + 0x14);
      local_58.y = *(short *)(uVar5 + 0x18);
      local_58.z = *(short *)(uVar5 + 0x1c);
    }
    else {
      local_58.x = (short)Raziel.Senses.lookAtPoint.x;
      local_58.y = (short)Raziel.Senses.lookAtPoint.y;
      local_58.z = (short)Raziel.Senses.lookAtPoint.z;
    }
    local_60.x = *(short *)Player->matrix[0x11].t;
    local_60.y = *(short *)(Player->matrix[0x11].t + 1);
    local_60.z = *(short *)(Player->matrix[0x11].t + 2);
    MATH3D_RotationFromPosToPos(&local_60,&local_58,&local_50);
    sVar1 = CAMERA_AngleDifference((Player->rotation).z,local_50.z);
    if (0x200 < sVar1) {
      local_50.z = (Player->rotation).z + 0x200;
    }
    if (sVar1 < -0x200) {
      local_50.z = (Player->rotation).z + -0x200;
    }
    if ((u_int)local_50.x - 0x201 < 0x5ff) {
      local_50.x = 0x200;
    }
    if ((u_int)local_50.x - 0x801 < 0x56d) {
      local_50.x = 0xd6e;
    }
    MATH3D_ZYXtoXYZ(&local_50);
    G2EmulationSetInterpController_Vector(Player,0x11,8,(_G2SVector3_Type *)&local_50,3,0);
  }
  return;
}





