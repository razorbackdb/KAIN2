#include "THISDUST.H"
#include "ALGOCTRL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitAlgorithmicWings(struct _Instance *instance /*$s2*/)
 // line 24, offset 0x800a1c24
	/* begin block 1 */
		// Start line: 25
		// Start offset: 0x800A1C24
		// Variables:
	// 		struct _G2EulerAngles_Type Rot; // stack offset -24
	// 		unsigned char i; // $s1
	/* end block 1 */
	// End offset: 0x800A1DA4
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
  _G2EulerAngles_Type local_18;
  
  if ((InterfaceItem_800cf854.name._4_4_ & 1) != 0) {
    return;
  }
  if (instance->matrix == (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Post(instance,(int)&DAT_00100006,0);
  }
  if (instance->matrix == (MATRIX *)0x0) {
    local_18.z = 0;
    local_18.y = 0;
    local_18.x = 0;
  }
  else {
    G2EulerAngles_FromMatrix(&local_18,(instance->anim).segMatrices + 0x32,0x15);
  }
                    /* WARNING: Subroutine does not return */
  G2Anim_EnableController(&instance->anim,0x33,8);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DeInitAlgorithmicWings(struct _Instance *instance /*$s1*/)
 // line 94, offset 0x800a1dbc
	/* begin block 1 */
		// Start line: 95
		// Start offset: 0x800A1DBC
		// Variables:
	// 		unsigned char i; // $s0
	/* end block 1 */
	// End offset: 0x800A1E38
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
  if ((InterfaceItem_800cf854.name._4_4_ & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    G2Anim_DisableController(&instance->anim,0x33,8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ AlgorithmicWings(struct _Instance *instance /*$s0*/, struct evAnimationControllerDoneData *ControllerData /*$s1*/)
 // line 117, offset 0x800a1e4c
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x800A1E4C
		// Variables:
	// 		struct _G2EulerAngles_Type Rot; // stack offset -24
	/* end block 1 */
	// End offset: 0x800A1EA8
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
                    /* WARNING: Subroutine does not return */
  G2EmulationSetInterpController_Vector
            (instance,ControllerData->segment,ControllerData->type,(_G2SVector3_Type *)&_Stack24,5,2
            );
}



// decompiled code
// original method signature: 
// void /*$ra*/ AlgorithmicNeck(struct _Instance *Player /*$s1*/, struct _Instance *Target /*$s2*/)
 // line 150, offset 0x800a1ebc
	/* begin block 1 */
		// Start line: 151
		// Start offset: 0x800A1EBC
		// Variables:
	// 		struct _Position From; // stack offset -96
	// 		struct _Position To; // stack offset -88
	// 		struct _Rotation Rot1; // stack offset -80
	// 		int Diff; // $v1
	// 		struct MATRIX matrix; // stack offset -72

		/* begin block 1.1 */
			// Start line: 162
			// Start offset: 0x800A1EF0
			// Variables:
		// 		struct evCollideInstanceStatsData data; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x800A1F58
		// End Line: 183

		/* begin block 1.2 */
			// Start line: 208
			// Start offset: 0x800A1FFC
			// Variables:
		// 		struct MATRIX *matrix; // $v1
		/* end block 1.2 */
		// End offset: 0x800A2034
		// End Line: 223
	/* end block 1 */
	// End offset: 0x800A2124
	// End Line: 256

	/* begin block 2 */
		// Start line: 345
	/* end block 2 */
	// End Line: 346

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AlgorithmicNeck(_Instance *Player,_Instance *Target)

{
  uint uVar1;
  _G2Bool_Enum _Var2;
  _Position local_60;
  _Position local_58;
  _Rotation local_50;
  undefined4 auStack72 [14];
  
  uVar1 = _CHAR____800d55b0 & 0xfffffff7;
  if ((_CHAR____800d55b0 & 0x10) != 0) {
    _CHAR____800d55b0 = uVar1;
                    /* WARNING: Subroutine does not return */
    TransposeMatrix((undefined4 *)Player->oldMatrix,auStack72);
  }
  if (Target == (_Instance *)0x0) {
    _CHAR____800d55b0 = uVar1;
    _Var2 = G2Anim_IsControllerActive(&Player->anim,0x11,8);
    if (_Var2 != G2FALSE) {
      G2Anim_InterpDisableController(&Player->anim,0x11,8,900);
    }
    return;
  }
  _CHAR____800d55b0 = uVar1;
  _Var2 = G2Anim_IsControllerActive(&Player->anim,0x11,8);
  if (_Var2 == G2FALSE) {
                    /* WARNING: Subroutine does not return */
    G2Anim_EnableController(&Player->anim,0x11,8);
  }
  if ((_CHAR____800d55b0 & 8) == 0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Target,0xc);
  }
  local_58.x = _CHAR____800d55f4;
  local_58.y = _CHAR____800d55f8;
  local_58.z = _CHAR____800d55fc;
  local_60.x = *(short *)Player->matrix[0x11].t;
  local_60.y = *(short *)(Player->matrix[0x11].t + 1);
  local_60.z = *(short *)(Player->matrix[0x11].t + 2);
  MATH3D_RotationFromPosToPos(&local_60,&local_58,&local_50);
                    /* WARNING: Subroutine does not return */
  AngleDiff((Player->rotation).z,local_50.z);
}





