#include "THISDUST.H"
#include "STEERING.H"

int UpdateZoneDelta(int rc, int LastRC)

{
  int iVar1;

  iVar1 = ZoneDelta;
  if ((LastRC != 0) && (iVar1 = 0x100, LastRC == rc))
  {
    ZoneDelta = ZoneDelta + -4;
    iVar1 = 0x10;
    if (0xf < ZoneDelta)
    {
      return ZoneDelta;
    }
  }
  ZoneDelta = iVar1;
  return ZoneDelta;
}

int GetControllerInput(int *ZDirection, long *controlCommand)

{
  int iVar1;
  u_int uVar2;

  if (((gameTrackerX.playerInstance)->flags & 0x100U) == 0)
  {
    uVar2 = *controlCommand;
    if ((uVar2 & 5) == 5)
    {
      iVar1 = 0x10000010;
      *ZDirection = 0xa00;
      UpdateZoneDelta(0x10000010, LastRC);
      LastRC = iVar1;
    }
    else
    {
      if ((uVar2 & 9) == 9)
      {
        iVar1 = 0x10000020;
        *ZDirection = 0x600;
        UpdateZoneDelta(0x10000020, LastRC);
        LastRC = iVar1;
      }
      else
      {
        if ((uVar2 & 6) == 6)
        {
          iVar1 = 0x10000040;
          *ZDirection = 0xe00;
          UpdateZoneDelta(0x10000040, LastRC);
          LastRC = iVar1;
        }
        else
        {
          if ((uVar2 & 10) == 10)
          {
            iVar1 = 0x10000030;
            *ZDirection = 0x200;
            UpdateZoneDelta(0x10000030, LastRC);
            LastRC = iVar1;
          }
          else
          {
            if ((uVar2 & 1) == 0)
            {
              iVar1 = 0x10000003;
              if ((uVar2 & 2) == 0)
              {
                if ((uVar2 & 8) == 0)
                {
                  iVar1 = 0x10000004;
                  if ((uVar2 & 4) == 0)
                  {
                    iVar1 = 0;
                    ZoneDelta = 0x10;
                    *ZDirection = 0;
                    LastRC = iVar1;
                  }
                  else
                  {
                    *ZDirection = 0xc00;
                    UpdateZoneDelta(0x10000004, LastRC);
                    LastRC = iVar1;
                  }
                }
                else
                {
                  iVar1 = 0x10000002;
                  *ZDirection = 0x400;
                  UpdateZoneDelta(0x10000002, LastRC);
                  LastRC = iVar1;
                }
              }
              else
              {
                *ZDirection = 0x1000;
                UpdateZoneDelta(0x10000003, LastRC);
                LastRC = iVar1;
              }
            }
            else
            {
              iVar1 = 0x10000001;
              *ZDirection = 0x800;
              UpdateZoneDelta(0x10000001, LastRC);
              LastRC = iVar1;
            }
          }
        }
      }
    }
  }
  else
  {
    iVar1 = 0;
  }
  return iVar1;
}

int SetThrowDirection(int Source, int Destination, short *Difference, short *Zone)

{
  short sVar1;
  short sVar2;
  int iVar3;

  sVar1 = CAMERA_AngleDifference((short)Destination, (short)Source);
  *Difference = sVar1;
  if ((u_short)(sVar1 + 0x1ffU) < 0x3ff)
  {
    *Zone = 0;
    iVar3 = 0x10000001;
  }
  else
  {
    if ((u_short)(sVar1 - 0x200U) < 0x400)
    {
      *Zone = 0x400;
      iVar3 = 0x10000004;
    }
    else
    {
      if ((u_short)(sVar1 + 0x5ffU) < 0x400)
      {
        *Zone = -0x400;
        iVar3 = 0x10000002;
      }
      else
      {
        if (sVar1 < 0x600)
        {
          sVar2 = -0x800;
          if (-0x600 < sVar1)
          {
            return 0;
          }
        }
        else
        {
          sVar2 = 0x800;
        }
        *Zone = sVar2;
        iVar3 = 0x10000003;
      }
    }
  }
  return iVar3;
}

int ProcessMovement(_Instance *instance, long *controlCommand, GameTracker *GT)

{
  short destination;
  u_short uVar1;
  long lVar2;
  _G2Bool_Enum _Var3;
  int ix;
  int iy;
  short step;
  short *Difference;
  short *Zone;
  _G2Anim_Type *anim;
  int rc;
  _G2SVector3_Type local_28;
  int iStack32;
  short sStack28;
  short sStack26;
  short sStack24;
  short asStack22[3];

  if (((Raziel.steeringMode == 9) || (Raziel.steeringMode == 0xe)) || (Raziel.steeringMode == 0xf))
  {
    rc = 0;
  }
  else
  {
    rc = GetControllerInput(&iStack32, controlCommand);
  }
  razZeroAxis(controlCommand + 3, controlCommand + 4, 0x400);
  ix = controlCommand[3];
  if (((ix == 0x80) || (ix == -0x80)) || ((iy = controlCommand[4], iy == 0x80 || (iy == -0x80))))
  {
    ix = 0x1000;
  LAB_800a17f8:
    Raziel.Magnitude = ix;
  }
  else
  {
    Raziel.Magnitude = MATH3D_veclen2(ix, iy);
    Raziel.Magnitude = Raziel.Magnitude << 5;
    if (0x1000 < Raziel.Magnitude)
    {
      Raziel.Magnitude = 0x1000;
    }
    if ((Raziel.Magnitude != 0) && (ix = 0x400, Raziel.Magnitude < 0x400))
      goto LAB_800a17f8;
  }
  Raziel.lastInput = Raziel.input;
  ix = (controlCommand[4] << 0xc) >> 0x1f;
  iy = (controlCommand[3] << 0xc) >> 0x1f;
  Raziel.input = rc;
 6 + ix >> 4) - ix,
 6 + iy >> 4) - iy);
 Raziel.ZDirection = 0x400U - ix & 0xfff;
 if (rc != 0)
 {
   Raziel.LastBearing = (short)Raziel.ZDirection + theCamera.lagZ;
 }
 Raziel.Bearing = CAMERA_AngleDifference((instance->rotation).z, Raziel.LastBearing);
 switch (Raziel.steeringMode)
 {
 case 0:
 case 0x10:
   goto switchD_800a18b4_caseD_0;
 case 1:
   Raziel.steeringVelocity = 0x100;
   goto LAB_800a1928;
 case 2:
   SteerMove(instance, rc);
   break;
 case 4:
   local_28.y = 0;
   local_28.x = 0;
   local_28.z = (short)Raziel.steeringLockRotation - Raziel.LastBearing;
   (instance->rotation).z = Raziel.LastBearing;
   if (rc != 0)
   {
     lVar2 = 0x15;
     if (Raziel.Mode == 0x10)
     {
       lVar2 = 0x28;
     }
     instance->yVel = lVar2;
   }
   G2Anim_GetControllerCurrentInterpVector(&instance->anim, 1, 0xe, &local_28);
   break;
 case 5:
 case 9:
   if (rc != 0)
   {
   LAB_800a1a80:
     rc = SteerAutoFace(instance, controlCommand);
     return rc;
   }
   if ((*PadData & 0x200) == 0)
   {
     return 0;
   }
   if ((Raziel.Senses.EngagedMask & 0x40) == 0)
   {
     return 0;
   }
   SteerDisableAutoFace(instance);
   destination = MATH3D_AngleFromPosToPos(&instance->position, &(Raziel.Senses.EngagedList[6].instance)->position);
   Raziel.steeringVelocity = 0x80;
   step = (short)((gameTrackerX.timeMult << 0xb) >> 0x10);
   goto LAB_800a1bb0;
 case 6:
 case 0x11:
   if (rc != 0)
   {
     SteerSwim(instance);
   }
   anim = &instance->anim;
   _Var3 = G2Anim_DetachControllerFromSeg(anim, 1, 0xe);
   if (_Var3 == G2FALSE)
   {
     G2Anim_DisableController(anim, 1, 0xe);
   }
   G2Anim_GetControllerCurrentInterpVector(anim, 1, 0xe, &Raziel.extraRot);
   break;
 case 7:
   SteerWallcrawling(instance);
   Difference = &sStack24;
   if (rc == 0)
   {
     return 0;
   }
   Zone = asStack22;
   goto LAB_800a1b74;
 case 8:
   Raziel.steeringVelocity = 0x60;
   goto LAB_800a1928;
 case 10:
   destination = MATH3D_AngleFromPosToPos(&instance->position, &(Raziel.attackedBy)->position);
   Raziel.steeringVelocity = 0x100;
   step = (short)((gameTrackerX.timeMult << 0xc) >> 0x10);
   goto LAB_800a1bb0;
 case 0xb:
   anim = &instance->anim;
   _Var3 = G2Anim_DetachControllerFromSeg(anim, 1, 0xe);
   if (_Var3 == G2FALSE)
   {
     G2Anim_DisableController(anim, 1, 0xe);
   }
   G2Anim_GetControllerCurrentInterpVector(anim, 1, 0xe, &Raziel.extraRot);
   goto switchD_800a18b4_caseD_0;
 case 0xc:
   destination = MATH3D_AngleFromPosToPos(&instance->position, &Raziel.puppetRotToPoint);
   goto LAB_800a1c10;
 case 0xd:
   destination = Raziel.puppetRotToPoint.z;
 LAB_800a1c10:
   Raziel.steeringVelocity = 0x100;
   AngleMoveToward(&(instance->rotation).z, destination,
                   (short)((gameTrackerX.timeMult << 0xc) >> 0x10));
   if (destination == (instance->rotation).z)
   {
     SteerSwitchMode(instance, 0);
   }
   break;
 case 0xe:
   if (((*PadData & 0x200) != 0) && ((Raziel.Senses.EngagedMask & 0x40) != 0))
   {
     destination = MATH3D_AngleFromPosToPos(&instance->position,
                                            &(Raziel.Senses.EngagedList[6].instance)->position);
     (instance->rotation).z = destination;
   }
   break;
 case 0xf:
   if (rc != 0)
     goto LAB_800a1a80;
   if ((Raziel.Senses.EngagedMask & 0x40) == 0)
   {
     return 0;
   }
   SteerDisableAutoFace(instance);
   destination = MATH3D_AngleFromPosToPos(&instance->position, &(Raziel.Senses.EngagedList[6].instance)->position);
   uVar1 = MON_FacingOffset(Raziel.Senses.EngagedList[6].instance, instance);
   if (((u_int)uVar1 & 0xfff) - 0x2ab < 0xaab)
   {
     return 0;
   }
   Raziel.steeringVelocity = 0x80;
   step = (short)((gameTrackerX.timeMult << 0xb) >> 0x10);
 LAB_800a1bb0:
   AngleMoveToward(&(instance->rotation).z, destination, step);
   break;
 case 0x12:
   Raziel.steeringVelocity = 0x40;
 LAB_800a1928:
   SteerTurn(instance, rc);
 }
 return rc;
switchD_800a18b4_caseD_0:
  Difference = &sStack28;
  if (rc == 0)
  {
    return 0;
  }
  Zone = &sStack26;
LAB_800a1b74:
  rc = SetThrowDirection((int)Raziel.Bearing, 0, Difference, Zone);
  return rc;
}

void SteerTurn(_Instance *instance, int rc)

{
  short sVar1;

  if ((rc == 0) && (Raziel.Bearing == 0))
  {
    Raziel.steeringVelocity = 0;
  }
  else
  {
    sVar1 = Raziel.LastBearing;
    if ((Raziel.Bearing == 0x800) &&
        (sVar1 = Raziel.LastBearing + 1, (int)(instance->rotation).z - (int)Raziel.LastBearing < 1))
    {
      sVar1 = Raziel.LastBearing + -1;
    }
    Raziel.LastBearing = sVar1;
    AngleMoveToward(&(instance->rotation).z, Raziel.LastBearing,
                    (short)((int)Raziel.steeringVelocity * gameTrackerX.timeMult * 0x10 >> 0x10));
  }
  return;
}

void SteerMove(_Instance *instance, int rc)

{
  int iVar1;

  if ((rc == 0) && (Raziel.Bearing == 0))
  {
    Raziel.steeringVelocity = 0;
  }
  else
  {
    Raziel.steeringVelocity = -Raziel.Bearing;
    if (-1 < Raziel.Bearing)
    {
      Raziel.steeringVelocity = Raziel.Bearing;
    }
    iVar1 = (int)Raziel.steeringVelocity;
    Raziel.steeringVelocity = 0x70;
    if (0x300 < iVar1)
    {
      if (iVar1 < 0)
      {
        iVar1 = iVar1 + 3;
      }
      Raziel.steeringVelocity = (short)(iVar1 >> 2) + 0x70;
    }
    AngleMoveToward(&(instance->rotation).z, Raziel.LastBearing,
                    (short)((int)Raziel.steeringVelocity * gameTrackerX.timeMult * 0x10 >> 0x10));
  }
  return;
}

int SteerAutoFace(_Instance *instance, long *controlCommand)

{
  bool bVar1;
  short current;
  short sVar2;
  _G2Bool_Enum _Var3;
  _G2Anim_Type *anim;
  int iVar4;
  u_int uVar5;
  _G2SVector3_Type local_20;

  current = MATH3D_AngleFromPosToPos(&instance->position, &(Raziel.Senses.EngagedList[6].instance)->position);
  Raziel.autoFaceTrueAngle = (int)current;
  Raziel.autoFaceLastAnim = Raziel.autoFaceAnim;
  sVar2 = CAMERA_AngleDifference(current, Raziel.LastBearing);
  current = Raziel.LastBearing;
  iVar4 = (int)sVar2;
  bVar1 = iVar4 + 0x17fU < 0x2ff;
  if (bVar1)
  {
    Raziel.autoFaceAnim = 0;
    Raziel.autoFaceRootAngle = 0;
  }
  uVar5 = (u_int)bVar1;
  if (iVar4 + 0x5ffU < 0x480)
  {
    uVar5 = 2;
    Raziel.autoFaceAnim = 1;
    Raziel.autoFaceRootAngle = 0x400;
  }
  if (iVar4 - 0x180U < 0x480)
  {
    uVar5 = 4;
    Raziel.autoFaceAnim = 3;
    Raziel.autoFaceRootAngle = -0x400;
  }
  if (0xbfe < iVar4 + 0x5ffU)
  {
    uVar5 = 3;
    Raziel.autoFaceAnim = 2;
    Raziel.autoFaceRootAngle = 0x800;
  }
  Raziel.steeringVelocity = 0x40;
  AngleMoveToward(&(instance->rotation).z, Raziel.LastBearing,
                  (short)((gameTrackerX.timeMult << 10) >> 0x10));
  Raziel.autoFaceAnim = uVar5 - 1;
  Raziel.autoFaceAngle = current;
  if (Raziel.autoFaceAnim != Raziel.autoFaceLastAnim)
  {
    anim = &instance->anim;
    (instance->rotation).z = Raziel.LastBearing;
    local_20.x = 0;
    local_20.y = 0;
    local_20.z = (short)Raziel.autoFaceRootAngle;
    _Var3 = G2Anim_DetachControllerFromSeg(anim, 1, 10);
    if (_Var3 == G2FALSE)
    {
      G2Anim_DisableController(anim, 1, 10);
    }
    if (Raziel.input == Raziel.lastInput)
    {
      G2EmulationSetInterpController_Vector(instance, 1, 10, &local_20, 4, 3);
    }
    else
    {
      G2Anim_GetControllerCurrentInterpVector(anim, 1, 10, &local_20);
    }
  }
  anim = &instance->anim;
  current = CAMERA_AngleDifference((instance->rotation).z, (short)Raziel.autoFaceTrueAngle);
  _Var3 = G2Anim_SetControllerAngleOrder(anim, 1, 10);
  if (_Var3 == G2FALSE)
  {
    local_20.x = 0;
    local_20.y = 0;
    local_20.z = current - (short)Raziel.autoFaceRootAngle;
    _Var3 = G2Anim_DetachControllerFromSeg(anim, 0xe, 0xe);
    if (_Var3 == G2FALSE)
    {
      G2Anim_DisableController(anim, 0xe, 0xe);
    }
    G2Anim_GetControllerCurrentInterpVector(anim, 0xe, 0xe, &local_20);
  }
  else
  {
    _Var3 = G2Anim_SetControllerAngleOrder(anim, 0xe, 0xe);
    if (_Var3 == G2FALSE)
    {
      local_20.x = 0;
      local_20.y = 0;
      local_20.z = current - (short)Raziel.autoFaceRootAngle;
      G2EmulationSetInterpController_Vector(instance, 0xe, 0xe, &local_20, 4, 3);
    }
  }
  return uVar5 | 0x10001000;
}

void SteerSwim(_Instance *instance)

{
  int iVar1;

  iVar1 = rsin(Raziel.ZDirection);
  iVar1 = ((gameTrackerX.timeMult << 5) >> 0xc) * iVar1;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  (instance->rotation).z = (instance->rotation).z - (short)(iVar1 >> 0xc);
  iVar1 = rcos(Raziel.ZDirection);
  if ((Raziel.steeringMode != 0x11) || (iVar1 < 0))
  {
    iVar1 = (gameTrackerX.timeMult * 0x30 >> 0xc) * iVar1;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0xfff;
    }
    Raziel.extraRot.x = Raziel.extraRot.x - (short)(iVar1 >> 0xc);
  }
  if (0x800 < Raziel.extraRot.x)
  {
    Raziel.extraRot.x = 0x800;
  }
  if (Raziel.extraRot.x < 0)
  {
    Raziel.extraRot.x = 0;
  }
  Raziel.extraRot.y = 0;
  Raziel.extraRot.z = 0;
  return;
}

void SteerWallcrawling(_Instance *instance)

{
  Raziel.Bearing =
      CAMERA_AngleDifference((short)(((u_int)(u_short)ExtraRot->y - 0x800) * 0x10000 >> 0x10),
                             (short)Raziel.ZDirection);
  return;
}

void SteerDisableAutoFace(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;

  anim = &instance->anim;
  _Var1 = G2Anim_DetachControllerFromSeg(anim, 1, 10);
  if (_Var1 != G2FALSE)
  {
    _G2Anim_FindController(anim, 1, 10);
  }
  _Var1 = G2Anim_DetachControllerFromSeg(anim, 0xe, 0xe);
  if (_Var1 != G2FALSE)
  {
    _G2Anim_FindController(anim, 0xe, 0xe);
  }
  (instance->rotation).z = (instance->rotation).z + (short)Raziel.autoFaceRootAngle;
  Raziel.autoFaceRootAngle = 0;
  Raziel.autoFaceAnim = -1;
  return;
}

void SteerSwitchMode(_Instance *instance, int mode)

{
  short sVar1;
  _G2Bool_Enum _Var2;

  switch (Raziel.steeringMode)
  {
  case 0:
  case 1:
  case 2:
  case 4:
  case 8:
  case 0x12:
    _Var2 = G2Anim_DetachControllerFromSeg(&instance->anim, 1, 0xe);
    if (_Var2 != G2FALSE)
    {
      _G2Anim_FindController(&instance->anim, 1, 0xe);
      (instance->rotation).z = (short)Raziel.steeringLockRotation;
      Raziel.LastBearing = (short)Raziel.steeringLockRotation;
    }
    break;
  case 5:
  case 9:
  case 0xf:
    SteerDisableAutoFace(instance);
    break;
  case 6:
  case 0x11:
    if ((((mode != 6) && (mode != 0xb)) && (mode != 0x10)) && (mode != 0x11))
    {
      _Var2 = G2Anim_DetachControllerFromSeg(&instance->anim, 1, 0xe);
      if (_Var2 != G2FALSE)
      {
        G2Anim_InterpDisableController(&instance->anim, 1, 0xe, 600);
      }
      Raziel.extraRot.x = 0;
    }
    break;
  case 7:
    if (mode != Raziel.steeringMode)
    {
      razDeinitWallCrawlSteering(instance);
    }
    break;
  case 10:
    Raziel.attackedBy = (_Instance *)0x0;
    break;
  case 0xb:
    CAMERA_EndSwimThrowMode(&theCamera);
    CAMERA_SetLookFocusAndBase(&theCamera, 0, 0);
    Raziel.extraRot.x = (short)Raziel.throwReturnRot;
  }
  Raziel.RotationSegment = 0;
  switch (mode)
  {
  case 0:
  case 1:
  case 2:
  case 4:
  case 5:
  case 8:
  case 9:
  case 10:
  case 0xf:
  case 0x12:
    Raziel.RotationSegment = 0;
    break;
  case 7:
    if (mode != Raziel.steeringMode)
    {
      razInitWallCrawlSteering(instance);
    }
    break;
  case 0xb:
    Raziel.throwReturnRot = (int)Raziel.extraRot.x;
    Raziel.extraRot.x = 0x1000 - theCamera.core.rotation.x;
    CAMERA_StartSwimThrowMode(&theCamera);
    CAMERA_SetLookFocusAndBase(&theCamera, 0x1000 - (int)Raziel.extraRot.x, 0);
  case 6:
  case 0x11:
    Raziel.RotationSegment = 1;
    break;
  case 0xe:
    sVar1 = MATH3D_AngleFromPosToPos(&instance->position, &(Raziel.Senses.EngagedList[6].instance)->position);
    (instance->rotation).z = sVar1;
  }
  Raziel.steeringMode = mode;
  return;
}

void razInitWallCrawlSteering(_Instance *instance)

{
  MATRIX *pMVar1;
  _G2Anim_Type *anim;
  _G2SVector3_Type local_18;

  anim = &instance->anim;
  G2Anim_DisableController(anim, 1, 0x26);
  local_18.x = 0;
  local_18.y = 0;
  local_18.z = -0x13e;
  (instance->position).z = (instance->position).z + 0x13e;
  pMVar1 = instance->matrix;
  (instance->oldPos).z = (instance->oldPos).z + 0x13e;
  pMVar1->t[2] = pMVar1->t[2] + 0x13e;
  instance->oldMatrix->t[2] = instance->oldMatrix->t[2] + 0x13e;
  G2Anim_GetControllerCurrentInterpVector(anim, 1, 0x26, &local_18);
  G2Anim_DisableController(anim, 0, 0xe);
  local_18.x = (instance->rotation).x;
  local_18.y = (instance->rotation).y;
  local_18.z = (instance->rotation).z;
  G2Anim_DisableController(anim, 0, 8);
  _G2Anim_ApplyControllersToStoredFrame(anim, 0, 8, 1);
  G2Anim_GetControllerCurrentInterpVector(anim, 0, 8, &local_18);
  G2Anim_DisableController(anim, 0xe, 0xe);
  G2Anim_DisableController(anim, 0x32, 0x4c);
  G2Anim_DisableController(anim, 0x3a, 0x4c);
  ExtraRotData.x = 0;
  ExtraRotData.y = 0;
  ExtraRotData.z = 0;
  ExtraRot = &ExtraRotData;
  return;
}

void razDeinitWallCrawlSteering(_Instance *instance)

{
  MATRIX *pMVar1;
  _G2Anim_Type *anim;

  anim = &instance->anim;
  _G2Anim_FindController(anim, 1, 0x26);
  (instance->position).z = (instance->position).z + -0x13e;
  pMVar1 = instance->matrix;
  (instance->oldPos).z = (instance->oldPos).z + -0x13e;
  pMVar1->t[2] = pMVar1->t[2] + -0x13e;
  instance->oldMatrix->t[2] = instance->oldMatrix->t[2] + -0x13e;
  G2Anim_InterpDisableController(anim, 0, 0xe, 300);
  G2Anim_InterpDisableController(anim, 0, 8, 300);
  G2Anim_InterpDisableController(anim, 0xe, 0xe, 300);
  G2Anim_InterpDisableController(anim, 0x32, 0x4c, 300);
  G2Anim_InterpDisableController(anim, 0x3a, 0x4c, 300);
  return;
}
