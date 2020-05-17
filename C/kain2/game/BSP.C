#include "THISDUST.H"
#include "BSP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SBSP_IntroduceInstances(struct _Terrain *terrain /*$a0*/, int unitID /*$a1*/)
 // line 527, offset 0x8003df34
	/* begin block 1 */
		// Start line: 528
		// Start offset: 0x8003DF34
		// Variables:
	// 		int i; // $s1
	// 		struct Intro *intro; // $s0
	/* end block 1 */
	// End offset: 0x8003DF80
	// End Line: 561

	/* begin block 2 */
		// Start line: 580
	/* end block 2 */
	// End Line: 581

	/* begin block 3 */
		// Start line: 1054
	/* end block 3 */
	// End Line: 1055

void SBSP_IntroduceInstances(_Terrain *terrain,int unitID)

{
  Intro *intro;
  int iVar1;
  
  iVar1 = terrain->numIntros;
  intro = terrain->introList;
  while (iVar1 != 0) {
    if ((intro->flags & 0x4008U) == 0) {
      INSTANCE_IntroduceInstance(intro,(short)unitID);
    }
    iVar1 = iVar1 + -1;
    intro = intro + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SBSP_IntroduceInstancesAndLights(struct _Terrain *terrain /*$a0*/, struct _CameraCore_Type *cameraCore /*$a1*/, struct LightInfo *lightInfo /*$a2*/, int unitID /*$a3*/)
 // line 563, offset 0x8003df98
	/* begin block 1 */
		// Start line: 657
	/* end block 1 */
	// End Line: 658

void SBSP_IntroduceInstancesAndLights
               (_Terrain *terrain,_CameraCore_Type *cameraCore,LightInfo *lightInfo,int unitID)

{
  SBSP_IntroduceInstances(terrain,unitID);
  return;
}





