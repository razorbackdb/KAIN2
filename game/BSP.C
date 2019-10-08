#include "THISDUST.H"
#include "BSP.H"

void SBSP_IntroduceInstances(_Terrain *terrain, int unitID)

{
  Intro *intro;
  int iVar1;

  iVar1 = terrain->numIntros;
  intro = terrain->introList;
  while (iVar1 != 0)
  {
    if ((intro->flags & 0x4008U) == 0)
    {
      INSTANCE_InsertInstanceGroup(intro, (short)unitID);
    }
    iVar1 = iVar1 + -1;
    intro = intro + 1;
  }
  return;
}

void INSTANCE_IntroduceSavedInstance(_Terrain *terrain, _CameraCore_Type *cameraCore, LightInfo *lightInfo, int unitID)

{
  SBSP_IntroduceInstances(terrain, unitID);
  return;
}
