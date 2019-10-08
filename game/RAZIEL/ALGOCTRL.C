#include "THISDUST.H"
#include "ALGOCTRL.H"

bVar2 = 0x33;
if (pMVar1 == (MATRIX *)0x0)
{
  INSTANCE_Query(instance, (int)&DAT_00100006, 0);
}
ile(true)
{
  if (pMVar1 == (MATRIX *)0x0)
  {
    local_18.z = 0;
    local_18.y = 0;
    local_18.x = 0;
    else
    {
      G2EulerAngles_FromMatrix(&local_18, (instance->anim).segMatrices + ((u_int)bVar2 - 1), 0x15);
    }
    (u_int) bVar2;
    G2Anim_DisableController(&instance->anim, segNumber, 8);
    nSetInterpController_Vector(instance, segNumber, 8, (_G2SVector3_Type *)&local_18, (segNumber - 0x32) * 3, 2);
    bVar2 = bVar2 + 1;
Var2) break;
pMVar1 = instance->matrix;
r2 = 0x3b;
do
{
  if (instance->matrix == (MATRIX *)0x0)
  {
    local_18.z = 0;
    local_18.y = 0;
    local_18.x = 0;
  }
  else
  {
    G2EulerAngles_FromMatrix(&local_18, (instance->anim).segMatrices + ((u_int)bVar2 - 1), 0x15);
  }
  segNumber = (u_int)bVar2;
  G2Anim_DisableController(&instance->anim, segNumber, 8);
  G2EmulationSetInterpController_Vector(instance, segNumber, 8, (_G2SVector3_Type *)&local_18, (segNumber - 0x3a) * 3, 2);
  bVar2 = bVar2 + 1;
} while (bVar2 < 0x3e);
AlgoControlFlag = AlgoControlFlag | 1;
  }
}
return;
}

(&instance->anim, (u_int)bVar1, 8);
bVar1 = bVar1 + 1;
}
while (bVar1 < 0x36)
  ;
bVar1 = 0x3b;
do
{
  _G2Anim_FindController(&instance->anim, (u_int)bVar1, 8);
  bVar1 = bVar1 + 1;
} while (bVar1 < 0x3e);
AlgoControlFlag = AlgoControlFlag & 0xfffffffe;
}
return;
}

pController_Vector(instance, ControllerData->segment, ControllerData->type, (_G2SVector3_Type *)&_Stack24, 5, 2);
return;
}

STANCE_SetStatsData(Player, (_Instance *)0x0, &Raziel.Senses.lookAtPoint, &eStack40, &MStack72);
if (((iVar3 != 0) && (eStack40.distance < 0xc80)) &&
    (iVar3 = MATH3D_ConeDetect(&eStack40.relativePosition, 0x3c7, 0x3c7), iVar3 != 0))
{
  Raziel.Senses.Flags = Raziel.Senses.Flags | 8;
}
}
if ((Target == (_Instance *)0x0) && ((Raziel.Senses.Flags & 8U) == 0))
{
  _Var4 = G2Anim_DetachControllerFromSeg(&Player->anim, 0x11, 8);
  if (_Var4 != G2FALSE)
  {
    G2Anim_InterpDisableController(&Player->anim, 0x11, 8, 900);
  }
}
else
{
  _Var4 = G2Anim_DetachControllerFromSeg(&Player->anim, 0x11, 8);
ALSE)
{
  G2Anim_DisableController(&Player->anim, 0x11, 8);
}
if ((Raziel.Senses.Flags & 8U) == 0)
{
  uVar5 = INSTANCE_Post(Target, 0xc);
 0)
 {
   return;
 }
 local_58.x = *(short *)(uVar5 + 0x14);
 (short *)(uVar5 + 0x18);
 local_58.z = *(short *)(uVar5 + 0x1c);

 local_58.x = (short)Raziel.Senses.lookAtPoint.x;
short)Raziel.Senses.lookAtPoint.y;
local_58.z = (short)Raziel.Senses.lookAtPoint.z;
0.x = *(short *)Player->matrix[0x11].t;
local_60.y = *(short *)(Player->matrix[0x11].t + 1);
local_60.z = *(short *)(Player->matrix[0x11].t + 2);
MATH3D_RotationFromPosToPos(&local_60, &local_58, &local_50);
sVar1 = CAMERA_AngleDifference((Player->rotation).z, local_50.z);
if (0x200 < sVar1)
{
  local_50.z = (Player->rotation).z + 0x200;
}
if (sVar1 < -0x200)
{
  local_50.z = (Player->rotation).z + -0x200;
}
if ((u_int)local_50.x - 0x201 < 0x5ff)
{
  local_50.x = 0x200;
}
if ((u_int)local_50.x - 0x801 < 0x56d)
{
  local_50.x = 0xd6e;
}
MATH3D_ZYXtoXYZ(&local_50);
G2EmulationSetInterpController_Vector(Player, 0x11, 8, (_G2SVector3_Type *)&local_50, 3, 0);
}
return;
}}






 

		
		
		
	

	
	


		

	

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





