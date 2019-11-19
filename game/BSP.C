#include "THISDUST.H"
#include "BSP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ BSP_TraverseIntrosWithVV(struct _BSPNode *root /*$a0*/, struct _CameraCore_Type *cameraCore /*$s1*/)
 // line 420, offset 0x8003ebac
	/* begin block 1 */
		// Start line: 421
		// Start offset: 0x8003EBAC
		// Variables:
	// 		struct VECTOR *dpv; // $s2
	// 		struct VECTOR *dpv2; // $s3
	// 		struct MATRIX *camMatrix; // $v1
	// 		long stackX[256]; // stack offset -1048
	// 		struct _BSPNode **stack; // $s0
	// 		struct _BSPNode *bspNode; // $a2
	// 		struct _Sphere_noSq *sphere; // $a3
	/* end block 1 */
	// End offset: 0x8003EDC0
	// End Line: 488

	/* begin block 2 */
		// Start line: 473
	/* end block 2 */
	// End Line: 474

	/* begin block 3 */
		// Start line: 782
	/* end block 3 */
	// End Line: 783

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BSP_TraverseIntrosWithVV(_BSPNode *root,_CameraCore_Type *cameraCore)

{
  undefined4 in_zero;
  undefined4 in_at;
  int iVar1;
  uint uVar2;
  _SBSPLeaf *sbspLeaf;
  _BSPNode *p_Var3;
  _BSPNode *p_Var4;
  undefined4 *****local_418;
  _BSPNode *local_414 [255];
  
  DAT_1f800018._0_2_ = (cameraCore->position).x;
  DAT_1f800018._2_2_ = (cameraCore->position).y;
  local_418 = &local_418;
  DAT_1f80001c._0_2_ = (cameraCore->position).z;
  local_414[0] = root;
  p_Var3 = (_BSPNode *)local_414;
  if (root != (_BSPNode *)local_414) {
    do {
      sbspLeaf = *(_SBSPLeaf **)&(p_Var3->sphere).position;
      p_Var4 = (_BSPNode *)&p_Var3[-1].front_material_error;
      setCopControlWord(2,0,*(undefined4 *)cameraCore->vvNormalWorVecMat[0].m);
      setCopControlWord(2,0x800,*(undefined4 *)(cameraCore->vvNormalWorVecMat[0].m + 2));
      setCopControlWord(2,0x1000,*(undefined4 *)(cameraCore->vvNormalWorVecMat[0].m + 4));
      setCopControlWord(2,0x1800,*(undefined4 *)(cameraCore->vvNormalWorVecMat[0].m + 6));
      setCopControlWord(2,0x2000,*(undefined4 *)(cameraCore->vvNormalWorVecMat[0].m + 8));
      setCopReg(2,in_zero,*(undefined4 *)&(sbspLeaf->sphere).position);
      setCopReg(2,in_at,*(undefined4 *)&(sbspLeaf->sphere).position.z);
      copFunction(2,0x486012);
      _DAT_1f800000 = getCopReg(2,0x19);
      _DAT_1f800004 = getCopReg(2,0x1a);
      _DAT_1f800008 = getCopReg(2,0x1b);
      _DAT_1f800000 = _DAT_1f800000 - cameraCore->vvPlaneConsts[0];
      uVar2 = (uint)(sbspLeaf->sphere).radius;
      iVar1 = -uVar2;
      if ((((iVar1 < _DAT_1f800000) && (_DAT_1f800000 < (int)(cameraCore->farPlane + uVar2))) &&
          (iVar1 < _DAT_1f800004 - cameraCore->vvPlaneConsts[1])) &&
         (iVar1 < _DAT_1f800008 - cameraCore->vvPlaneConsts[2])) {
        setCopControlWord(2,0,*(undefined4 *)cameraCore->vvNormalWorVecMat[1].m);
        setCopControlWord(2,0x800,*(undefined4 *)(cameraCore->vvNormalWorVecMat[1].m + 2));
        setCopControlWord(2,0x1000,*(undefined4 *)(cameraCore->vvNormalWorVecMat[1].m + 4));
        setCopControlWord(2,0x1800,*(undefined4 *)(cameraCore->vvNormalWorVecMat[1].m + 6));
        setCopControlWord(2,0x2000,*(undefined4 *)(cameraCore->vvNormalWorVecMat[1].m + 8));
        setCopReg(2,in_zero,*(undefined4 *)&(sbspLeaf->sphere).position);
        setCopReg(2,in_at,*(undefined4 *)&(sbspLeaf->sphere).position.z);
        copFunction(2,0x486012);
        _DAT_1f80000c = getCopReg(2,0x19);
        _DAT_1f800010 = getCopReg(2,0x1a);
        _DAT_1f800014 = getCopReg(2,0x1b);
        iVar1 = -(uint)(sbspLeaf->sphere).radius;
        if ((iVar1 < _DAT_1f80000c - cameraCore->vvPlaneConsts[3]) &&
           (iVar1 < _DAT_1f800010 - cameraCore->vvPlaneConsts[4])) {
          if ((sbspLeaf->flags & 1U) == 0) {
            SBSP_IntroduceInstancesAndLightsInLeaf(sbspLeaf);
          }
          else {
            iVar1 = *(int *)&sbspLeaf[1].sphere.position;
            if (iVar1 != 0) {
              *(int *)&(p_Var3->sphere).position = iVar1;
              p_Var4 = p_Var3;
            }
            if (*(int *)&sbspLeaf->numLights != 0) {
              p_Var4 = (_BSPNode *)&(p_Var4->sphere).position.z;
              *(int *)&(p_Var4->sphere).position = *(int *)&sbspLeaf->numLights;
            }
          }
        }
      }
      p_Var3 = p_Var4;
    } while (*(_BSPNode **)&(p_Var4->sphere).position != p_Var4);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SBSP_IntroduceInstancesAndLightsInLeaf(struct _SBSPLeaf *sbspLeaf /*$a0*/)
 // line 500, offset 0x8003eddc
	/* begin block 1 */
		// Start line: 501
		// Start offset: 0x8003EDDC
		// Variables:
	// 		struct CDLight **lightP; // $s2
	// 		int i; // $s1

		/* begin block 1.1 */
			// Start line: 507
			// Start offset: 0x8003EE00
			// Variables:
		// 		struct CDLight *light; // $s0
		/* end block 1.1 */
		// End offset: 0x8003EE60
		// End Line: 522
	/* end block 1 */
	// End offset: 0x8003EE6C
	// End Line: 523

	/* begin block 2 */
		// Start line: 656
	/* end block 2 */
	// End Line: 657

void SBSP_IntroduceInstancesAndLightsInLeaf(_SBSPLeaf *sbspLeaf)

{
  byte bVar1;
  NodeType *list;
  CDLight *node;
  int iVar2;
  CDLight **ppCVar3;
  
  iVar2 = (int)sbspLeaf->numLights;
  ppCVar3 = sbspLeaf->lightList;
  do {
    if (iVar2 == 0) {
      return;
    }
    node = *ppCVar3;
    bVar1 = node->flags;
    if ((bVar1 & 0x10) == 0) {
      if ((bVar1 & 0x40) == 0) {
        if ((bVar1 & 0x80) == 0) goto LAB_8003ee60;
        list = &sbsp_lightInfo->activeSpotLightList;
      }
      else {
        list = &sbsp_lightInfo->activePointLightList;
      }
      LIST_InsertFunc(list,(NodeType *)node);
      node->flags = node->flags | 0x10;
    }
LAB_8003ee60:
    iVar2 = iVar2 + -1;
    ppCVar3 = ppCVar3 + 1;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ SBSP_IntroduceInstances(struct _Terrain *terrain /*$s5*/, int unitID /*$a1*/)
 // line 527, offset 0x8003ee84
	/* begin block 1 */
		// Start line: 528
		// Start offset: 0x8003EE84
		// Variables:
	// 		int i; // $s0
	// 		struct _SBSPLeaf *sbspLeaf; // $s3
	// 		struct Intro **introP; // $s1

		/* begin block 1.1 */
			// Start line: 538
			// Start offset: 0x8003EED4
			// Variables:
		// 		struct Intro *intro; // $a0
		/* end block 1.1 */
		// End offset: 0x8003EEF8
		// End Line: 546
	/* end block 1 */
	// End offset: 0x8003EF18
	// End Line: 548

	/* begin block 2 */
		// Start line: 727
	/* end block 2 */
	// End Line: 728

/* WARNING: Type propagation algorithm not settling */

void SBSP_IntroduceInstances(_Terrain *terrain,int unitID)

{
  int iVar1;
  Intro *pIVar2;
  short *psVar3;
  _MorphVertex *p_Var4;
  
  p_Var4 = terrain->MorphDiffList;
  if (p_Var4 < (_MorphVertex *)terrain->MorphColorList) {
    psVar3 = &p_Var4->hz;
    do {
      iVar1 = (int)*psVar3;
      pIVar2 = *(Intro **)(psVar3 + -2);
      while (iVar1 != 0) {
        if (((*(Intro **)pIVar2->name)->flags & 0x4008U) == 0) {
          INSTANCE_IntroduceInstance(*(Intro **)pIVar2->name,(short)unitID);
        }
        iVar1 = iVar1 + -1;
        pIVar2 = (Intro *)((int)pIVar2->name + 4);
      }
      p_Var4 = (_MorphVertex *)&p_Var4[1].hy;
      psVar3 = psVar3 + 0xc;
    } while (p_Var4 < (_MorphVertex *)terrain->MorphColorList);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SBSP_IntroduceInstancesAndLights(struct _Terrain *terrain /*$s0*/, struct _CameraCore_Type *cameraCore /*$a1*/, struct LightInfo *lightInfo /*$a2*/, int unitID /*$s1*/)
 // line 550, offset 0x8003ef3c
	/* begin block 1 */
		// Start line: 786
	/* end block 1 */
	// End Line: 787

void SBSP_IntroduceInstancesAndLights
               (_Terrain *terrain,_CameraCore_Type *cameraCore,LightInfo *lightInfo,int unitID)

{
  if ((_BSPNode *)terrain->pad != (_BSPNode *)0x0) {
    sbsp_lightInfo = lightInfo;
    BSP_TraverseIntrosWithVV((_BSPNode *)terrain->pad,cameraCore);
  }
  SBSP_IntroduceInstances(terrain,unitID);
  return;
}





