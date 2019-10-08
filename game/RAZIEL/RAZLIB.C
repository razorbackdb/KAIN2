#include "THISDUST.H"
#include "RAZLIB.H"

void razAlignYRotMove(_Instance *dest, short distance, _Position *position, _Rotation *rotation,
                      int extraZ)

{
  u_long uVar1;
  undefined2 local_48;
  short local_46;
  undefined2 local_44;
  short local_40;
  short local_3e;
  MATRIX MStack56;

  local_46 = -distance;
  local_48 = 0;
  local_44 = 0;
  uVar1 = INSTANCE_Post(dest, 7);
  rotation->z = *(short *)(uVar1 + 4) + (short)extraZ + 0x800;
  MATH3D_SetUnityMatrix(&MStack56);
  RotMatrixX((int)rotation->z, (u_int *)&MStack56);
  ApplyMatrix(&MStack56, &local_48, &local_40);
  position->x = (dest->position).x + local_40;
  position->y = (dest->position).y + local_3e;
  return;
}

void razAlignYRotMoveInterp(_Instance *dest, short distance, _Position *position, _Rotation *rotation, int extraZ)

{
  undefined2 local_58;
  short local_56;
  undefined2 local_54;
  short local_50;
  short local_4e;
  u_short auStack72[2];
  short local_44;
  u_int auStack64[8];

  memset(auStack72, 0, 8);
  local_44 = MATH3D_AngleFromPosToPos(position, &dest->position);
  local_44 = local_44 + (short)extraZ;
  rotation->z = local_44;
  RotMatrixY(auStack72, auStack64);
  local_58 = 0;
  local_54 = 0;
  local_56 = distance;
  ApplyMatrix(auStack64, &local_58, &local_50);
  position->x = (dest->position).x + local_50;
  position->y = (dest->position).y + local_4e;
  return;
}

void razAlignYMoveRot(_Instance *source, _Instance *dest, short distance, u_char segNumber, int Frames,
                      int extraZ)

{
  u_char local_28;
  short local_24;
  _Rotation _Stack32;
  _G2SVector3_Type local_18;

  local_28 = *(u_char *)&source->position;
  local_24 = (source->position).z;
  razAlignYRotMoveInterp(dest, distance, (_Position *)&local_28, &_Stack32, (int)(short)extraZ);
  *(u_char *)&source->position = local_28;
  (source->position).z = local_24;
  local_18.x = 0;
  local_18.y = 0;
  local_18.z = _Stack32.z;
  G2Anim_DisableController(&source->anim, (u_int)segNumber, 8);
  G2EmulationSetInterpController_Vector(source, (u_int)segNumber, 8, &local_18, Frames, 0);
  (source->rotation).z = _Stack32.z;
  return;
}

void razAlignYRotInterp(_Instance *source, _Position *dest, u_char segNumber, int Frames)

{
  short sVar1;

  sVar1 = MATH3D_AngleFromPosToPos(&source->position, dest);
  (source->rotation).z = sVar1;
  return;
}

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
  do
  {
    iVar1 = iVar2 + 1;
    iVar3 = iVar2;
    if (0x1f < iVar2)
    {
      iVar3 = 0;
      iVar1 = 1;
    }
    if (0x1f < iVar1)
    {
      iVar1 = 0;
    }
    setCopReg(2, 0x6000, Raziel.constrictCenter._0_4_);
    setCopReg(2, 0x7000, Raziel.constrictData[iVar1]);
    setCopReg(2, 0x6800, Raziel.constrictData[iVar3]);
    copFunction(2, 0x1400006);
    local_20 = getCopReg(2, 0x18);
    if (local_20 < 1)
    {
      iVar4 = iVar4 + -1;
    }
    else
    {
      iVar4 = iVar4 + 1;
    }
    iVar2 = iVar3 + 1;
    iVar5 = iVar5 + 1;
    iVar3 = COLLIDE_PointInTriangle((short *)&Raziel.constrictCenter, (short *)(Raziel.constrictData + iVar3),
                                    (short *)(Raziel.constrictData + iVar1), &local_28);
    iVar6 = iVar6 + iVar3;
  } while (iVar5 < 0x20);
  iVar2 = 0;
  if (iVar6 != 0)
  {
    iVar2 = iVar4;
  }
  return iVar2;
}

void razRotateUpperBody(_Instance *instance, evActionLookAroundData *data)

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
  if ((sVar1 < data->minx) || (sVar3 = data->maxx, data->maxx < sVar1))
  {
    *data->rotx = sVar3;
  }
  sVar1 = *data->rotz;
  sVar3 = data->minz;
  if ((sVar1 < data->minz) || (sVar3 = data->maxz, data->maxz < sVar1))
  {
    *data->rotz = sVar3;
  }
  sVar1 = *data->rotx;
  local_20.y = 0;
  iVar2 = -(int)sVar1;
  iVar4 = (u_int)(u_short)*data->rotz << 0x10;
  iVar5 = iVar4 >> 0x10;
 2);
 local_20.z = (short)(iVar5 - (iVar4 >> 0x1f) >> 1);
 MATH3D_ZYXtoXYZ(&local_20);
 anim = &instance->anim;
 G2Anim_GetControllerCurrentInterpVector(anim, 0xe, 0xe, (_G2SVector3_Type *)&local_20);
 local_20.y = 0;
 100);
 100);
 MATH3D_ZYXtoXYZ(&local_20);
 G2Anim_GetControllerCurrentInterpVector(anim, 0x10, 0xe, (_G2SVector3_Type *)&local_20);
 local_20.y = 0;
 5);
 5);
 MATH3D_ZYXtoXYZ(&local_20);
 G2Anim_GetControllerCurrentInterpVector(anim, 0x11, 0xe, (_G2SVector3_Type *)&local_20);
 return;
}

void razSetFadeEffect(short source, short dest, int steps)

{
  Raziel.effectsFlags = Raziel.effectsFlags | 3;
  Raziel.effectsFadeSource = source;
  Raziel.effectsFadeDest = dest;
  Raziel.effectsFadeStep = steps;
  Raziel.effectsFadeSteps = 0;
  return;
}

int SOUND_PlaneShift(_Instance *instance)

{
  int iVar1;

  if ((gameTrackerX.streamFlags & 0x40000U) == 0)
  {
    if (Raziel.CurrentPlane == 1)
    {
      razSpectralShift();
      iVar1 = 1;
    }
    else
    {
      razMaterialShift();
      iVar1 = 1;
    }
  }
  else
  {
    iVar1 = 0;
  }
  return iVar1;
}

void razSpectralShift(void)

{
  _Instance *Inst;
  int iVar1;

  if (((gameTrackerX.streamFlags & 0x40000U) == 0) && (Raziel.CurrentPlane == 1))
  {
    Inst = razGetHeldItem();
    if (Inst != (_Instance *)0x0)
    {
      INSTANCE_Query(Inst, 0x800008, 4);
      razSetFadeEffect(0x1000, 0, 0x100);
    }
    (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 | 0x8000000;
    INSTANCE_Query(gameTrackerX.playerInstance, (int)&DAT_00100014, 0);
    iVar1 = GetMaxHealth();
    if (Raziel.HitPoints == iVar1)
    {
      Raziel.HitPoints = 100000;
    }
    else
    {
      Raziel.HitPoints = 0x14586;
    }
    Raziel.CurrentPlane = 2;
    razReaverOff();
    if ((gameTrackerX.gameData.asmData.MorphType == 0) &&
        (MORPH_ToggleMorph(), Raziel.State.SectionList[0].Process != StateHandlerWallGrab))
    {
      INSTANCE_Query(gameTrackerX.playerInstance, 0x40005, 0);
    }
  }
  return;
}

void razMaterialShift(void)

{
  if ((Raziel.CurrentPlane == 2) && (Raziel.HitPoints == 100000))
  {
    Raziel.CurrentPlane = 1;
    (gameTrackerX.playerInstance)->flags2 = (gameTrackerX.playerInstance)->flags2 & 0xf7ffffff;
    Raziel.HitPoints = GetMaxHealth();
    Raziel.DamageFrequency = 0;
    razReaverOff();
    if ((gameTrackerX.gameData.asmData.MorphType != 0) &&
        (MORPH_ToggleMorph(), Raziel.State.SectionList[0].Process != StateHandlerWallGrab))
    {
      INSTANCE_Query(gameTrackerX.playerInstance, 0x40005, 0);
    }
  }
  return;
}

int RAZIEL_OkToShift(void)

{
  int iVar1;
  u_int uVar2;

  if (Raziel.CurrentPlane == 2)
  {
    iVar1 = GetMaxHealth();
    uVar2 = 0;
    if (Raziel.HitPoints == iVar1)
    {
      if ((Raziel.Abilities & 0x40U) == 0)
      {
        uVar2 = (u_int)((Raziel.Senses.Flags & 0x40U) != 0);
      }
      else
      {
        uVar2 = 1;
        if ((Raziel.Abilities & 0x10U) == 0)
        {
          FONT_Print("\nYOU CAN NOT HAVE SHIFT ANYTIME WITHOUT THE SWIM ABILITY");
          FONT_Print("\nBEAT THE ALUKA BOSS THEN WIN THE SECOND KAIN ENCOUNTER");
          uVar2 = 0;
        }
      }
    }
  }
  else
  {
    uVar2 = 1;
  }
  return uVar2;
}

int razPickupAndGrab(__CharacterState *In, int CurrentSection)

{
  _Instance *Inst;
  int Data;
  u_long uVar1;

  if ((Raziel.Senses.EngagedMask & 0x20) == 0)
  {
    Data = 1;
  }
  else
  {
    Inst = razGetHeldItem();
    Data = 1;
    if ((((Inst == (_Instance *)0x0) && (Raziel.CurrentPlane == 1)) &&
         (Data = 1, (Raziel.Mode & 0x800U) == 0)) &&
        (Data = 0, CurrentSection != 0))
    {
      Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
      if (Inst != (_Instance *)0x0)
      {
        INSTANCE_Post(Inst, 0);
      }
      if (CurrentSection == 1)
      {
        Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
        if (Inst != (_Instance *)0x0)
        {
          INSTANCE_Query(Inst, (int)&DAT_0100001b, 0);
          INSTANCE_UnlinkFromParent(Raziel.Senses.EngagedList[5].instance);
        }
        Data = SetObjectBreakOffData(0, 0, 8, In->CharacterInstance, 0x31);
        INSTANCE_Query(Raziel.Senses.EngagedList[5].instance, 0x800002, Data);
        if (*(short *)(Data + 6) != 0)
        {
          return 0;
        }
        razReaverOn();
      }
      (&In->CharacterInstance + CurrentSection * 0x47)[0x47] = (_Instance *)0x0;
      uVar1 = INSTANCE_Post(Raziel.Senses.EngagedList[5].instance, 4);
      G2EmulatePlayAnimation(In, CurrentSection, (u_int) ""[uVar1], 0, 3, 1);
      Raziel.returnState = (_func_60 *)(&In->CharacterInstance + CurrentSection * 0x47)[2];
      StateSwitchStateData(In, CurrentSection, StateHandlerPullSwitch, 0);
      Data = 0;
    }
  }
  return Data;
}

int razZeroAxis(long *x, long *y, int radius)

{
  u_long uVar1;

  uVar1 = MATH3D_SquareLength(*x, *y, 0);
  if (uVar1 < (u_int)radius)
  {
    uVar1 = 0;
    *x = 0;
    *y = 0;
  }
  return uVar1;
}

int razAdjustSpeed(_Instance *instance, int minSpeed)

{
  int iVar1;
  long adjustment;

  iVar1 = (int)Raziel.movementMaxAnalog;
  if (iVar1 < Raziel.Magnitude)
  {
    adjustment = (long)Raziel.movementMaxRate;
  }
  else
  {
    if (Raziel.Magnitude < Raziel.movementMinAnalog)
    {
      adjustment = (long)Raziel.movementMinRate;
    }
    else
    {
      adjustment = (int)Raziel.movementMaxRate -
                   (((int)Raziel.movementMaxRate - (int)Raziel.movementMinRate) *
 (iVar1 - Raziel.movementMinAnalog);
    }
  }
  G2Anim_SetSpeedAdjustment(&instance->anim, adjustment);
  return adjustment;
}

void razLaunchForce(_Instance *instance)

{
  PHYSOB_BirthCollectible(instance, 0x31, (u_int)Raziel.Abilities._1_1_ & 1);
  Raziel.effectsFlags = Raziel.effectsFlags | 4;
  razSetupSoundRamp(instance, (_SoundRamp *)&Raziel.soundHandle, 0xc, (int)PlayerData->forceMinPitch,
                    (int)PlayerData->forceMaxPitch, (int)PlayerData->forceMinVolume,
                    (int)PlayerData->forceMaxVolume, PlayerData->forceRampTime * 0x1e,
                    (int)&DAT_00002710);
  Raziel.soundTimerNext = 0;
  Raziel.soundTimerData = 0;
  return;
}

_Instance *razGetHeldItem(void)

{
  _Instance *p_Var1;

  p_Var1 = (Raziel.State.CharacterInstance)->LinkChild;
  if (((Raziel.soulReaver != (_Instance *)0x0) && (p_Var1 == Raziel.soulReaver)) &&
      (p_Var1 != (_Instance *)0x0))
  {
    return p_Var1->LinkSibling;
  }
  return p_Var1;
}

_Instance *razGetHeldWeapon(void)

{
  _Instance *Inst;
  u_long uVar1;

  Inst = razGetHeldItem();
  if (Inst == (_Instance *)0x0)
  {
    Inst = (_Instance *)0x0;
    if (Raziel.Senses.heldClass != 0)
    {
      Inst = Raziel.soulReaver;
    }
  }
  else
  {
    uVar1 = INSTANCE_Post(Inst, 1);
    if ((uVar1 & 0x20) == 0)
    {
      Inst = (_Instance *)0x0;
    }
  }
  return Inst;
}

void FX_ReaverBladeInit(void)

{
  if (Raziel.soulReaver != (_Instance *)0x0)
  {
    INSTANCE_Query(Raziel.soulReaver, 0x800109, 0);
  }
  return;
}

void razReaverBladeOn(void)

{
  if (Raziel.soulReaver != (_Instance *)0x0)
  {
    INSTANCE_Query(Raziel.soulReaver, 0x800108, 0);
  }
  return;
}

int razReaverOn(void)

{
  int iVar1;
  _Instance *p_Var2;

  if (Raziel.soulReaver == (_Instance *)0x0)
  {
    iVar1 = 0;
  }
  else
  {
    iVar1 = 0;
    if (Raziel.Senses.heldClass == 0x1000)
    {
      p_Var2 = razGetHeldWeapon();
      INSTANCE_Query(Raziel.soulReaver, 0x800101, 0);
      iVar1 = 1;
      if (p_Var2 == Raziel.soulReaver)
      {
        Raziel.Senses.heldClass = 0;
      }
    }
  }
  return iVar1;
}

int razReaverOff(void)

{
  _Instance *p_Var1;
  int iVar2;

  if (Raziel.soulReaver == (_Instance *)0x0)
  {
    iVar2 = 0;
  }
  else
  {
    p_Var1 = razGetHeldItem();
    iVar2 = 0;
    if ((p_Var1 == (_Instance *)0x0) &&
        ((iVar2 = GetMaxHealth(), Raziel.HitPoints == iVar2 || (iVar2 = 0, Raziel.CurrentPlane == 2))))
    {
      INSTANCE_Query(Raziel.soulReaver, 0x800100, 0);
      Raziel.Senses.heldClass = 0x1000;
      if ((Raziel.CurrentPlane == 2) && (Raziel.currentSoulReaver != 1))
      {
        razReaverBladeOff(1);
      }
      iVar2 = 1;
      if ((Raziel.CurrentPlane == 1) && (iVar2 = 1, Raziel.currentSoulReaver == 1))
      {
        razReaverBladeOff(2);
        iVar2 = 1;
      }
    }
  }
  return iVar2;
}

void razReaverImbue(_Instance *instance, _Instance *soulReaver)

{
  _Instance *p_Var1;
  int Data;

  INSTANCE_Query(soulReaver, 0x800002, (int)instance);
  Raziel.soulReaver = soulReaver;
  p_Var1 = razGetHeldItem();
  if (p_Var1 != (_Instance *)0x0)
  {
    razReaverOn();
  }
  if (Raziel.CurrentPlane == 1)
  {
    Data = 2;
    Raziel.currentSoulReaver = 2;
    debugRazielFlags2 = 0x800;
  }
  else
  {
    Data = 1;
    debugRazielFlags2 = 0x400;
    Raziel.currentSoulReaver = 1;
  }
  debugRazielFlags1 = Raziel.Abilities | 0xc08;
  Raziel.Abilities = debugRazielFlags1;
  INSTANCE_Query(soulReaver, 0x800103, Data);
  return;
}

void razReaverBladeOff(int reaverType)

{
  debugRazielFlags2 = 1 << (reaverType + 9U & 0x1f);
  Raziel.currentSoulReaver = reaverType;
  INSTANCE_Query(Raziel.soulReaver, 0x800103, reaverType);
  return;
}

int razGetReaverFromMask(int reaverMask)

{
  int iVar1;
  u_int uVar2;

  uVar2 = (u_int)reaverMask >> 10 & 0xff;
  iVar1 = 0;
  while (uVar2 != 0)
  {
    uVar2 = (int)uVar2 >> 1;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

void razReaverPickup(int scale)

{
  _Instance *Inst;

  Inst = razGetHeldWeapon();
  if ((Raziel.soulReaver != (_Instance *)0x0) && (Inst == Raziel.soulReaver))
  {
    INSTANCE_Query(Inst, 0x800107, scale);
  }
  return;
}

void razGetForwardNormal(_Instance *inst, _Instance *target)

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
  PHYSICS_CheckLineInWorld(inst, &local_48);
  if (((u_int)local_48.type - 2 < 2) || (local_48.type == 5))
  {
    Raziel.Senses.ForwardNormal.x = local_48.wNormal.vx;
    Raziel.Senses.ForwardNormal.y = local_48.wNormal.vy;
    Raziel.Senses.ForwardNormal.z = local_48.wNormal.vz;
  }
  return;
}

void razGetRotFromNormal(_SVector *normal, _Rotation *rot)

{
  _Position local_18;
  _Position local_10;

  local_18.x = normal->x;
  local_18.y = normal->y;
  local_18.z = normal->z;
  local_10.z = 0;
  local_10.y = 0;
  local_10.x = 0;
  MATH3D_RotationFromPosToPos(&local_18, &local_10, rot);
  return;
}

void razCenterWithBlock(_Instance *inst, _Instance *target, int dist)

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

  razGetForwardNormal(inst, target);
  razGetRotFromNormal(&Raziel.Senses.ForwardNormal, &_Stack72);
  iVar1 = (int)Raziel.Senses.ForwardNormal.z;
  if (iVar1 < 0)
  {
    iVar1 = -iVar1;
  }
  MATH3D_SetUnityMatrix(&MStack64);
  RotMatrixX((int)_Stack72.z, (u_int *)&MStack64);
  local_56 = 0x140 - (short)dist;
  local_54 = 0;
  local_58 = 0;
  ApplyMatrix(&MStack64, &local_58, &local_50);
  iVar4 = (u_int)(u_short)(inst->position).x - (u_int)(u_short)(target->position).x;
  iVar8 = iVar4 * 0x10000;
  iVar7 = iVar8 >> 0x10;
  local_58 = (short)iVar4;
  iVar4 = iVar7;
  if (iVar7 < 0)
  {
    iVar4 = -iVar7;
  }
  iVar5 = (u_int)(u_short)(inst->position).y - (u_int)(u_short)(target->position).y;
  local_56 = (short)iVar5;
  iVar5 = iVar5 * 0x10000;
  iVar6 = iVar5 >> 0x10;
  iVar2 = iVar6;
  if (iVar6 < 0)
  {
    iVar2 = -iVar6;
  }
  if (iVar4 < iVar2)
  {
    local_58 = (short)(iVar7 - (iVar8 >> 0x1f) >> 1);
    if (1000 < iVar1)
    {
      local_56 = local_4e;
    }
  }
  else
  {
    local_56 = (short)(iVar6 - (iVar5 >> 0x1f) >> 1);
    if (1000 < iVar1)
    {
      local_58 = local_50;
    }
  }
  local_20.x = local_50 + ((inst->position).x - local_58);
  local_20.y = local_4e + ((inst->position).y - local_56);
  local_20.z = (inst->position).z;
  _Var3 = G2Anim_DetachControllerFromSeg(&inst->anim, 0, 0x20);
  if (_Var3 == G2FALSE)
  {
    G2Anim_DisableController(&inst->anim, 0, 0x20);
  }
  G2EmulationSetInterpController_Vector(inst, 0, 0x20, &local_20, 6, 0);
  (inst->rotation).z = _Stack72.z;
  return;
}

void razResetPauseTranslation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;
  _G2SVector3_Type local_10;

  anim = &instance->anim;
  _Var1 = G2Anim_DetachControllerFromSeg(anim, 0, 0x22);
  if (_Var1 == G2FALSE)
  {
    G2Anim_DisableController(anim, 0, 0x22);
  }
  local_10.x = 0;
  local_10.y = 0;
  local_10.z = 0;
  G2Anim_GetControllerCurrentInterpVector(anim, 0, 0x22, &local_10);
  ControlFlag = ControlFlag | 0x20000000;
  return;
}

void razSetPauseTranslation(_Instance *instance)

{
  _G2Bool_Enum _Var1;

  _Var1 = G2Anim_DetachControllerFromSeg(&instance->anim, 0, 0x22);
  if (_Var1 != G2FALSE)
  {
    _G2Anim_FindController(&instance->anim, 0, 0x22);
  }
  ControlFlag = ControlFlag & 0xdfffffff;
  return;
}

void razSelectMotionAnim(__CharacterState *In, int CurrentSection, int Frames, int *Anim)

{
  u_short uVar1;
  short sVar2;
  u_int uVar3;
  u_int uVar4;
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
  if (Raziel.Magnitude < 0xeb9)
  {
    if (Raziel.Magnitude - 0xae0U < 0x3d9)
    {
      uVar3 = ControlFlag & 0xffffdfff;
      uVar4 = ControlFlag & 0x20000000;
      ControlFlag = uVar3;
      if (uVar4 != 0)
      {
        razSetPauseTranslation(In->CharacterInstance);
      }
      frame = *Anim;
      if (frame == 0x3c)
      {
        if ((Raziel.passedMask & 0xf) != 0)
        {
          bVar7 = true;
        }
        if ((Raziel.passedMask & 8) != 0)
        {
          frame_00 = 7;
        }
        if ((Raziel.passedMask & 1) != 0)
        {
          frame_00 = 0xd;
        }
        uVar3 = Raziel.passedMask & 4;
        if ((Raziel.passedMask & 2) != 0)
        {
          frame_00 = 0x14;
        }
      }
      else
      {
        if (frame != 0x44)
        {
          if (frame != 0x40)
          {
            bVar7 = true;
          }
          goto LAB_800a58a8;
        }
        if ((Raziel.passedMask & 0xf00) != 0)
        {
          bVar7 = true;
        }
        if ((Raziel.passedMask & 0x800) != 0)
        {
          frame_00 = 7;
        }
        if ((Raziel.passedMask & 0x100) != 0)
        {
          frame_00 = 0xd;
        }
        uVar3 = Raziel.passedMask & 0x400;
        if ((Raziel.passedMask & 0x200) != 0)
        {
          frame_00 = 0x14;
        }
      }
      if (uVar3 != 0)
      {
        frame_00 = 0x19;
      }
    }
    else
    {
      if (Raziel.Magnitude < 0xae0)
      {
        ControlFlag = ControlFlag | 0x2000;
        frame = *Anim;
        if (frame == 0x40)
        {
          bVar7 = (Raziel.passedMask & 0xf0) != 0;
          if ((Raziel.passedMask & 0x80) != 0)
          {
            frame_00 = 0xc;
          }
          if ((Raziel.passedMask & 0x10) != 0)
          {
            frame_00 = 0x14;
          }
          uVar3 = Raziel.passedMask & 0x40;
          if ((Raziel.passedMask & 0x20) != 0)
          {
            frame_00 = 0x20;
          }
        }
        else
        {
          if (frame != 0x44)
          {
            if (frame != 0x3c)
            {
              bVar7 = true;
            }
            goto LAB_800a58a8;
          }
          bVar7 = (Raziel.passedMask & 0xf00) != 0;
          if ((Raziel.passedMask & 0x800) != 0)
          {
            frame_00 = 0xc;
          }
          if ((Raziel.passedMask & 0x100) != 0)
          {
            frame_00 = 0x14;
          }
          uVar3 = Raziel.passedMask & 0x400;
          if ((Raziel.passedMask & 0x200) != 0)
          {
            frame_00 = 0x20;
          }
        }
        if (uVar3 != 0)
        {
          frame_00 = 0;
        }
      }
    }
  }
  else
  {
    if (Raziel.nothingCounter == 0)
    {
      ControlFlag = ControlFlag & 0xffffdfff;
    }
    if ((ControlFlag & 0x20000000U) != 0)
    {
      razSetPauseTranslation(In->CharacterInstance);
    }
    frame = *Anim;
    if (frame == 0x3c)
    {
      if ((Raziel.passedMask & 0xf) != 0)
      {
        bVar7 = true;
      }
      if ((Raziel.passedMask & 8) != 0)
      {
        frame_00 = 5;
      }
      if ((Raziel.passedMask & 1) != 0)
      {
        frame_00 = 0x17;
      }
      uVar3 = Raziel.passedMask & 4;
      if ((Raziel.passedMask & 2) != 0)
      {
        frame_00 = 0x11;
      }
    }
    else
    {
      if (frame != 0x40)
      {
        if (frame != 0x44)
        {
          bVar7 = true;
        }
        goto LAB_800a58a8;
      }
      if ((Raziel.passedMask & 0xf0) != 0)
      {
        bVar7 = true;
      }
      if ((Raziel.passedMask & 0x80) != 0)
      {
        frame_00 = 5;
      }
      if ((Raziel.passedMask & 0x10) != 0)
      {
        frame_00 = 0x17;
      }
      uVar3 = Raziel.passedMask & 0x40;
      if ((Raziel.passedMask & 0x20) != 0)
      {
        frame_00 = 0x11;
      }
    }
    if (uVar3 != 0)
    {
      frame_00 = 0xb;
    }
  }
LAB_800a58a8:
  if (bVar7 == true)
  {
    if (CurrentSection == 2)
    {
      Raziel.passedMask = 0;
    }
    frame = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x40, frame_00, Frames);
    if (frame != 0)
    {
      G2EmulatePlayAnimation(In, CurrentSection, 0x7c, frame_00, Frames, 2);
    }
    Raziel.movementMinRate = 0xccc;
    Raziel.movementMaxRate = 0x1800;
    Raziel.movementMinAnalog = 0xadf;
    Raziel.movementMaxAnalog = 0xeb8;
    frame_00 = 0x40;
  LAB_800a5a0c:
    *Anim = frame_00;
  }
  else
  {
    if (bVar7 < 3)
    {
      if (bVar7 == true)
      {
        if (CurrentSection == 2)
        {
          Raziel.passedMask = 0;
        }
        frame = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x3c, frame_00, Frames);
        if (frame != 0)
        {
          G2EmulatePlayAnimation(In, CurrentSection, 0x7b, frame_00, Frames, 2);
        }
        Raziel.movementMinRate = 0x1000;
        Raziel.movementMaxRate = 0x1c00;
        Raziel.movementMinAnalog = 0x8fc;
        Raziel.movementMaxAnalog = 0xadf;
        frame_00 = 0x3c;
        goto LAB_800a5a0c;
      }
    }
    else
    {
      if (bVar7 == true)
      {
        if (CurrentSection == 2)
        {
          Raziel.passedMask = 0;
        }
        frame = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, 0x44, frame_00, Frames);
        if (frame != 0)
        {
          G2EmulatePlayAnimation(In, CurrentSection, 2, frame_00, Frames, 2);
        }
        Raziel.movementMinRate = 0xddb;
        Raziel.movementMinAnalog = 0xeb8;
        frame_00 = 0x44;
        Raziel.movementMaxRate = 0x1000;
        Raziel.movementMaxAnalog = 0x1000;
        goto LAB_800a5a0c;
      }
    }
  }
  if (CurrentSection != 0)
  {
    if (In->SectionList[0].Process != DefaultPuppetStateHandler)
    {
      return;
    }
    p_Var6 = In->CharacterInstance;
    section = (p_Var6->anim).section;
    section_00 = (p_Var6->anim).section + CurrentSection;
    _Var5 = G2AnimSection_AdvanceOverInterval(section);
    if (_Var5 != G2FALSE)
    {
      return;
    }
    _Var5 = G2AnimSection_AdvanceOverInterval(section_00);
    if (_Var5 != G2FALSE)
    {
      return;
    }
    frame_00 = G2AnimSection_GetKeyframeNumber(section);
    frame = G2AnimSection_GetKeyframeNumber(section_00);
    if (frame_00 == frame)
    {
      return;
    }
    keylist = (p_Var6->anim).section[0].keylist;
    uVar1 = (p_Var6->anim).section[0].keylistID;
    frame_00 = G2AnimSection_GetKeyframeNumber(section);
    frame = G2AnimKeylist_GetKeyframeCount(keylist);
    frame = (frame_00 + 6) % frame;
    frame_00 = razSwitchVAnimGroup(In->CharacterInstance, CurrentSection, *Anim, frame, 6);
    if (frame_00 == 0)
    {
      return;
    }
    G2AnimSection_InterpToKeylistFrame(section_00, keylist, (u_int)uVar1, frame, 600);
    return;
  }
  if ((ControlFlag & 0x20000000U) != 0)
  {
    return;
  }
  local_30.z = 0;
  local_30.x = 0;
  frame_00 = *Anim;
  if (frame_00 == 0x40)
  {
    sVar2 = -0x23;
  }
  else
  {
    if (frame_00 < 0x41)
    {
      sVar2 = -0x10;
      if (frame_00 != 0x3c)
        goto LAB_800a5a78;
    }
    else
    {
      sVar2 = -0x3c;
      if (frame_00 != 0x44)
        goto LAB_800a5a78;
    }
  }
  local_30.y = sVar2;
LAB_800a5a78:
  frame_00 = razAdjustSpeed(In->CharacterInstance, 1);
  sVar2 = G2Timer_GetFrameTime();
 100);
 _Var5 = G2Anim_DetachControllerFromSeg(&In->CharacterInstance->anim, 0, 0x22);
 if (_Var5 == G2FALSE)
 {
   G2Anim_DisableController(&In->CharacterInstance->anim, 0, 0x22);
 }
 G2Anim_GetControllerCurrentInterpVector(&In->CharacterInstance->anim, 0, 0x22, &local_30);
 return;
}

int razApplyMotion(__CharacterState *In, int CurrentSection)

{
  short sVar1;
  _G2AnimKeylist_Type *p_Var2;
  int iVar3;
  _G2Bool_Enum _Var4;
  _Instance *instance;
  _G2SVector3_Type _Stack24;

  memset(&_Stack24, 0, 6);
  if (CurrentSection == 0)
  {
    instance = In->CharacterInstance;
    p_Var2 = G2Instance_GetKeylist(instance, 2);
    if ((instance->anim).section[0].keylist == p_Var2)
    {
      _Stack24.y = -0x3c;
    }
    else
    {
      p_Var2 = G2Instance_GetKeylist(In->CharacterInstance, 0x7c);
      if ((instance->anim).section[0].keylist == p_Var2)
      {
        _Stack24.y = -0x23;
      }
      else
      {
        p_Var2 = G2Instance_GetKeylist(In->CharacterInstance, 0x7b);
        if ((instance->anim).section[0].keylist == p_Var2)
        {
          _Stack24.y = -0x10;
        }
        else
        {
          _Var4 = G2Anim_DetachControllerFromSeg(&In->CharacterInstance->anim, 0, 0x22);
          if (_Var4 != G2FALSE)
          {
            _G2Anim_FindController(&In->CharacterInstance->anim, 0, 0x22);
          }
        }
      }
    }
    iVar3 = (int)_Stack24.y;
    if (iVar3 == 0)
      goto LAB_800a5d94;
    _Var4 = G2Anim_DetachControllerFromSeg(&In->CharacterInstance->anim, 0, 0x22);
    if (_Var4 == G2FALSE)
    {
      G2Anim_DisableController(&In->CharacterInstance->anim, 0, 0x22);
    }
    iVar3 = (In->CharacterInstance->anim).section[0].speedAdjustment;
    sVar1 = G2Timer_GetFrameTime();
 100);
 G2Anim_GetControllerCurrentInterpVector(&In->CharacterInstance->anim, 0, 0x22, &_Stack24);
  }
  iVar3 = (int)_Stack24.y;
LAB_800a5d94:
  return -iVar3;
}

void razResetMotion(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  _G2Anim_Type *anim;

  anim = &instance->anim;
  _Var1 = G2Anim_DetachControllerFromSeg(anim, 0, 0x22);
  if (_Var1 != G2FALSE)
  {
    _G2Anim_FindController(anim, 0, 0x22);
  }
  Raziel.passedMask = 0;
  G2Anim_SetSpeedAdjustment(anim, 0x1000);
  return;
}

void razSetDampingPhysics(_Instance *instance)

{
  Raziel.RotationSegment = 0;
  Raziel.extraRot.x = 0;
  PhysicsMode = 4;
  SetDampingPhysics(instance, PlayerData->SwimPhysicsFallDamping);
  return;
}

void razEnterWater(__CharacterState *In, int CurrentSection, evPhysicsSwimData *SwimData)

{
  _Instance *Inst;
  u_long uVar1;
  int CurrentSection_00;
  int NewAnim;
  int local_20;
  int local_1c;

  Inst = razGetHeldWeapon();
  if ((SwimData->rc & 0x10U) != 0)
  {
    if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0))
    {
      Raziel.HitPoints = 100000;
      SetPhysicsGravityData(In->CharacterInstance, -0x10, 0, 0, 0);
      PhysicsMode = 0;
    }
    else
    {
      if ((Inst == (_Instance *)0x0) || (uVar1 = INSTANCE_Post(Inst, 4), uVar1 != 3))
      {
        if (((Raziel.Mode & 0x40000U) == 0) && (Raziel.CurrentPlane == 1))
        {
          if (PhysicsMode != 4)
          {
            razSetDampingPhysics(In->CharacterInstance);
          }
          if ((In->CharacterInstance->zVel == 0) || ((Raziel.Mode & 0x400000U) != 0))
          {
            razResetMotion(In->CharacterInstance);
            StateSwitchStateCharacterDataDefault(In, StateHandlerSwimTread, 0);
          }
          TrailWaterFX(In->CharacterInstance, 9, 1, 1);
          TrailWaterFX(In->CharacterInstance, 0xd, 1, 1);
          TrailWaterFX(In->CharacterInstance, 0x1f, 1, 1);
          TrailWaterFX(In->CharacterInstance, 0x29, 1, 1);
        }
      }
      else
      {
        G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim, 0x800);
      }
    }
  }
  if (((SwimData->rc & 0x800U) != 0) && (Raziel.Senses.heldClass == 1))
  {
    if (CurrentSection == 2)
    {
      NewAnim = 0x3d;
      local_20 = 3;
      CurrentSection_00 = 2;
      local_1c = CurrentSection;
    }
    else
    {
      NewAnim = 0x3f;
      local_20 = 0x10;
      local_1c = 2;
      CurrentSection_00 = CurrentSection;
    }
    G2EmulatePlayAnimation(In, CurrentSection_00, NewAnim, 0, local_20, local_1c);
  }
  if (((SwimData->rc & 0x100U) != 0) && (CurrentSection == 0))
  {
    if (Inst == (_Instance *)0x0)
    {
      razSetDampingPhysics(In->CharacterInstance);
    }
    else
    {
      INSTANCE_Post(Inst, 4);
    }
    EnMessageQueueData(&In->SectionList[0].Event);
    TrailWaterFX(In->CharacterInstance, 9, 4, 1);
    TrailWaterFX(In->CharacterInstance, 0xd, 4, 1);
  }
  return;
}

void razSetSwimVelocity(_Instance *instance, int vel, int accl)

{
  int iVar1;

  iVar1 = vel * (instance->anim).section[0].speedAdjustment;
  instance->yAccl = 0;
  instance->xAccl = 0;
  instance->yVel = 0;
  instance->xVel = 0;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  Raziel.swimTargetSpeed = (short)(iVar1 >> 0xc);
  if (vel < instance->zVel)
  {
    instance->zAccl = -accl;
    return;
  }
  instance->zAccl = accl;
  return;
}

void razSetWallCrawlNodes(_Instance *instance, evPhysicsWallCrawlData *data)

{
  u_long uVar1;
  _G2SVector3_Type local_18;

  if ((data->rc & 8U) != 0)
  {
    uVar1 = MATH3D_SquareLength((int)(data->NewPosition).x, (int)(data->NewPosition).y,
                                (int)(data->NewPosition).z);
    if (100 < (int)uVar1)
    {
      (instance->position).x = (instance->position).x - (data->NewPosition).x;
      (instance->position).y = (instance->position).y - (data->NewPosition).y;
    }
    local_18.x = (data->DropRotation).x;
    local_18.y = (data->DropRotation).y;
    local_18.z = (data->DropRotation).z;
    G2Anim_GetControllerCurrentInterpVector(&instance->anim, 0, 8, &local_18);
  }
  if (data->rc == 10)
  {
    local_18.y = 0;
    local_18.z = 0;
    local_18.x = -data->ForwardXRotation;
    G2EmulationSetInterpController_Vector(instance, 0xe, 0xe, &local_18, 3, 0);
  }
  return;
}

int razSwitchVAnimCharacterSingle(_Instance *instance, int animGroup, int *frame, int *frames)

{
  int frame_00;
  int section;
  int iVar1;
  int local_28;
  u_char local_24;
  u_char local_20;

  local_28 = -1;
  local_24 = 0xffffffff;
  local_20 = 0xffffffff;
  if (frame == (int *)0x0)
  {
    frame = &local_28;
  }
  section = 0;
  if (frames == (int *)0x0)
  {
    frames = &local_28;
  }
  do
  {
    iVar1 = section + 1;
    frame_00 = *frame;
    frame = frame + 1;
    frame_00 = razSwitchVAnimGroup(instance, section, animGroup, frame_00, *frames);
    section = iVar1;
    frames = frames + 1;
  } while (iVar1 < 3);
  return frame_00;
}

int razSwitchVAnimGroup(_Instance *instance, int section, int animGroup, int frame, int frames)

{
  int iVar1;

  iVar1 = 1;
  if (Raziel.Senses.heldClass != 0)
  {
    iVar1 = Raziel.Senses.heldClass - 1;
    if (2 < iVar1)
    {
      iVar1 = 3;
    }
    razSwitchVAnim(instance, section, PlayerData->virtualAnimations + animGroup + iVar1, frame, frames);
    iVar1 = 0;
  }
  return iVar1;
}

void razSwitchVAnimCharacterGroup(_Instance *instance, int anim, int *frame, int *frames)

{
  int frame_00;
  int section;
  int iVar1;
  int local_28;
  u_char local_24;
  u_char local_20;

  local_28 = -1;
  local_24 = 0xffffffff;
  local_20 = 0xffffffff;
  if (frame == (int *)0x0)
  {
    frame = &local_28;
  }
  section = 0;
  if (frames == (int *)0x0)
  {
    frames = &local_28;
  }
  do
  {
    iVar1 = section + 1;
    frame_00 = *frame;
    frame = frame + 1;
    razSwitchVAnimSingle(instance, section, anim, frame_00, *frames);
    section = iVar1;
    frames = frames + 1;
  } while (iVar1 < 3);
  return;
}

void razSwitchVAnimSingle(_Instance *instance, int section, int anim, int frame, int frames)

{
  razSwitchVAnim(instance, section, PlayerData->virtualAnimSingle + anim, frame, frames);
  return;
}

void razSwitchVAnim(_Instance *instance, int section, __VAnim *vAnim, int frame, int frames)

{
  u_int local_14;
  u_int AlphaTable;
  int CurrentSection;
  u_int NewAnim;

  if (frame == -1)
  {
    frame = ZEXT24(vAnim->frame);
  }
  if (frames == -1)
  {
    frames = ZEXT14(vAnim->frames);
  }
  if (section == 1)
  {
    NewAnim = (u_int)vAnim->anim1;
    local_14 = (u_int)vAnim->mode;
    AlphaTable = (u_int)vAnim->alpha;
    CurrentSection = 1;
  }
  else
  {
    if (section < 2)
    {
      if (section != 0)
      {
        return;
      }
      NewAnim = (u_int)vAnim->anim0;
      local_14 = (u_int)vAnim->mode;
      AlphaTable = (u_int)vAnim->alpha;
      CurrentSection = 0;
    }
    else
    {
      CurrentSection = 2;
      if (section != 2)
      {
        return;
      }
      NewAnim = (u_int)vAnim->anim2;
      local_14 = (u_int)vAnim->mode;
      AlphaTable = (u_int)vAnim->alpha;
    }
  }
  G2EmulationSwitchAnimationCharacter(instance, CurrentSection, NewAnim, frame, frames, local_14, AlphaTable);
  return;
}

int razProcessSAnim(_Instance *instance, int mode)

{
  short sVar1;
  short sVar2;
  __SAnim *p_Var3;
  int section;
  __VAnim *vAnim;
  int iVar4;

  iVar4 = 0;
  if (mode == 0x8000000)
  {
    sVar2 = (Raziel.currentSAnim)->mode;
    sVar1 = 1;
  }
  else
  {
    if (mode < 0x8000001)
    {
      if ((undefined *)mode != &DAT_00100015)
        goto LAB_800a6594;
      sVar2 = (Raziel.currentSAnim)->mode;
      sVar1 = 2;
    }
    else
    {
      if (mode != 0x8000003)
        goto LAB_800a6594;
      sVar2 = (Raziel.currentSAnim)->mode;
      sVar1 = 3;
    }
  }
  if (sVar2 == sVar1)
  {
    iVar4 = 1;
  }
LAB_800a6594:
  if (iVar4 != 0)
  {
    p_Var3 = (Raziel.currentSAnim)->nextAnim;
    if (p_Var3 == (__SAnim *)0x0)
    {
      G2Anim_SetSpeedAdjustment(&instance->anim, 0x1000);
      Raziel.currentSAnim = (__SAnim *)0x0;
      iVar4 = 0;
    }
    else
    {
      vAnim = p_Var3->anim;
      section = 0;
      Raziel.currentSAnim = p_Var3;
      if (vAnim != (__VAnim *)0x0)
      {
        do
        {
          razSwitchVAnim(instance, section, vAnim, -1, -1);
          section = section + 1;
          G2Anim_SetSpeedAdjustment(&instance->anim, (int)(Raziel.currentSAnim)->speedAdjust);
        } while (section < 3);
        if ((Raziel.currentSAnim)->mode == 2)
        {
          CAMERA_SetShake((int)(Raziel.currentSAnim)->data);
        }
      }
    }
  }
  return iVar4;
}

void razSwitchStringAnimation(_Instance *instance, int anim)

{
  int section;
  __VAnim *vAnim;

  Raziel.currentSAnim = PlayerData->stringAnimations[anim];
  vAnim = (Raziel.currentSAnim)->anim;
  if (vAnim != (__VAnim *)0x0)
  {
    section = 0;
    do
    {
      razSwitchVAnim(instance, section, vAnim, -1, -1);
      section = section + 1;
    } while (section < 3);
    G2Anim_SetSpeedAdjustment(&instance->anim, (int)(Raziel.currentSAnim)->speedAdjust);
    if ((Raziel.currentSAnim)->mode == 2)
    {
      CAMERA_SetShake((int)(Raziel.currentSAnim)->data);
    }
  }
  return;
}

int CheckStringAnimation(_Instance *instance, int mode)

{
  int iVar1;

  iVar1 = 0;
  if ((Raziel.currentSAnim == (__SAnim *)0x0) ||
      (iVar1 = razProcessSAnim(instance, mode), Raziel.currentSAnim == (__SAnim *)0x0))
  {
    INSTANCE_Query(instance, 0x100000, 0);
  }
  return iVar1;
}

void razInitCollision(_Instance *instance)

{
  byte *pbVar1;
  int iVar2;

  iVar2 = instance->hModelList[instance->currentModel].numHPrims;
  if (iVar2 != 0)
  {
    pbVar1 = &(instance->hModelList[instance->currentModel].hPrimList)->withFlags;
    do
    {
      if (pbVar1[2] != 1)
      {
        *pbVar1 = *pbVar1 & 0xa5;
      }
      iVar2 = iVar2 + -1;
      pbVar1 = pbVar1 + 8;
    } while (iVar2 != 0);
  }
  return;
}

void razLaunchBubbles(int segments, int count, int type)

{
  if ((segments & 1U) != 0)
  {
    TrailWaterFX(gameTrackerX.playerInstance, 0x20, count, type);
    TrailWaterFX(gameTrackerX.playerInstance, 0x2a, count, type);
  }
  if ((segments & 2U) != 0)
  {
    TrailWaterFX(gameTrackerX.playerInstance, 8, count, type);
    TrailWaterFX(gameTrackerX.playerInstance, 0xc, count, type);
  }
  return;
}

void razSetCowlNoDraw(int mode)

{
  byte bVar1;
  _MFace *p_Var2;
  u_short *puVar3;

  puVar3 = &cowlList;
  do
  {
    if (mode == 0)
    {
      p_Var2 = (gameTrackerX.playerInstance)->object->modelList[(gameTrackerX.playerInstance)->currentModel]->faceList + *puVar3;
      bVar1 = p_Var2->flags & 0xef;
    }
    else
    {
      p_Var2 = (gameTrackerX.playerInstance)->object->modelList[(gameTrackerX.playerInstance)->currentModel]->faceList + *puVar3;
      bVar1 = p_Var2->flags | 0x10;
    }
    p_Var2->flags = bVar1;
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < -0x7ff2f5da);
  return;
}

void razAttachControllers(void)

{
  u_short *puVar1;
  bool bVar2;
  u_short *puVar3;
  __razController *p_Var4;
  int iVar5;

  p_Var4 = &controllerList;
  iVar5 = 1;
  do
  {
    G2Anim_AttachControllerToSeg(&(gameTrackerX.playerInstance)->anim, (u_int)p_Var4->segment, (u_int)p_Var4->type);
    puVar3 = &p_Var4->segment;
    puVar1 = &p_Var4->type;
    p_Var4 = p_Var4 + 1;
    _G2Anim_FindController(&(gameTrackerX.playerInstance)->anim, (u_int)*puVar3, (u_int)*puVar1);
    bVar2 = iVar5 < 0x18;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  return;
}

void razSetPlayerEvent(void)

{
  _func_14 *p_Var1;
  u_long uVar2;
  _Instance *p_Var3;
  int iVar4;
  int local_10;
  int local_c;

  p_Var1 = Raziel.State.SectionList[0].Process;
  local_10 = 0;
  local_c = 0;
  if ((((Raziel.Senses.EngagedMask & 1) != 0) && (Raziel.Senses.heldClass != 3)) &&
      (Raziel.State.SectionList[0].Process == StateHandlerPickupObject))
  {
    Raziel.playerEvent = Raziel.playerEvent | 1;
  }
  if ((((Raziel.Senses.EngagedMask & 4) != 0) && (Raziel.Senses.heldClass != 3)) &&
      (Raziel.State.SectionList[0].Process == StateHandlerSwimCoil))
  {
    Raziel.playerEvent = Raziel.playerEvent | 2;
  }
  if ((((Raziel.Senses.EngagedMask & 8) != 0) && (Raziel.Senses.heldClass != 3)) &&
      (Raziel.State.SectionList[0].Process == StateHandlerPickupObject))
  {
    uVar2 = INSTANCE_Post(Raziel.Senses.EngagedList[3].instance, 4);
    if (uVar2 == 9)
    {
      Raziel.playerEvent = Raziel.playerEvent | 8;
    }
    else
    {
      Raziel.playerEvent = Raziel.playerEvent | 4;
    }
  }
  if (((((Raziel.Senses.EngagedMask & 0x20) != 0) &&
        (p_Var3 = razGetHeldItem(), p_Var3 == (_Instance *)0x0)) &&
       (Raziel.CurrentPlane == 1)) &&
      (((p_Var1 == StateHandlerPickupObject || (p_Var1 == StateHandlerDecodeHold)) ||
        ((((p_Var1 == DefaultPuppetStateHandler ||
            ((p_Var1 == StateHandlerDeCompression || (p_Var1 == StateHandlerGrab)))) ||
           (p_Var1 == StateHandlerSwimTread)) ||
          (p_Var1 == StateHandlerPushObject))))))
  {
    Raziel.playerEvent = Raziel.playerEvent | 0x10;
  }
  if ((Raziel.Senses.EngagedMask & 0x40) != 0)
  {
    Raziel.playerEvent = Raziel.playerEvent | 0x20;
  }
  iVar4 = StateHandlerAutoFace(&local_10, &local_c);
  if ((iVar4 != 0) && (local_c != 0))
  {
    if (local_10 == 0x1000002)
    {
      Raziel.playerEvent = Raziel.playerEvent | 0x40;
    }
    if (local_10 == 0x100000a)
    {
      Raziel.playerEvent = Raziel.playerEvent | 0x80;
    }
    if (local_10 == 0x1000018)
    {
      Raziel.playerEvent = Raziel.playerEvent | 0x100;
    }
  }
  if (((Raziel.Mode & 0x20000U) != 0) && (Raziel.Senses.heldClass - 1 < 3))
  {
    Raziel.playerEvent = Raziel.playerEvent | 0x200;
  }
  if (local_10 == 0x80000)
  {
    Raziel.playerEvent = Raziel.playerEvent | 0x400;
  }
  if ((Raziel.Senses.EngagedMask & 0x4000) != 0)
  {
    Raziel.playerEvent = Raziel.playerEvent | 0x800;
  }
  if ((Raziel.Senses.Flags & 0x40U) != 0)
  {
    Raziel.playerEvent = Raziel.playerEvent | 0x2000;
  }
  return;
}

void razClearPlayerEvent(void)

{
  if ((ControlFlag & 0x100000U) != 0)
  {
    Raziel.playerEvent = Raziel.playerEvent & 0x2000;
    return;
  }
  Raziel.playerEvent = 0;
  return;
}

void razSetPlayerEventHistory(u_long event)

{
  Raziel.playerEventHistory = Raziel.playerEventHistory | event;
  return;
}

int razSideMoveSpiderCheck(_Instance *instance, int x)

{
  u_int uVar1;
  short x_00;
  SVECTOR SStack32;
  SVECTOR SStack24;

  x_00 = (short)x;
  PHYSICS_GenericLineCheckMask(x_00, 0, 0xc0, &SStack32);
  PHYSICS_GenericLineCheckMask(x_00, -0x140, 0xc0, &SStack24);
  uVar1 = PHYSOBS_CheckForValidMove(instance, &SStack32, &SStack24, 0);
  if ((uVar1 & 1) == 0)
  {
    uVar1 = 1;
  }
  else
  {
    PHYSICS_GenericLineCheckMask(x_00, 0, 0, &SStack32);
    PHYSICS_GenericLineCheckMask(x_00, -0x140, 0, &SStack24);
    uVar1 = PHYSOBS_CheckForValidMove(instance, &SStack32, &SStack24, 0);
    uVar1 = uVar1 & 1 ^ 1;
  }
  return uVar1;
}

_Instance *RAZIEL_QueryEngagedInstance(int index)

{
  if ((Raziel.Senses.EngagedMask & 1 << (index & 0x1fU)) == 0)
  {
    return (_Instance *)0x0;
  }
  return Raziel.Senses.EngagedList[index].instance;
}

int SOUND_UpdateSound(_Instance *instance, _SoundRamp *sound)

{
  u_long uVar1;
  int iVar2;
  int iVar3;
  int maxVolume;

  maxVolume = 0;
  if (sound->soundHandle != 0)
  {
    iVar3 = sound->soundTotalTime;
    maxVolume = sound->soundTimer + gameTrackerX.timeMult;
    sound->soundTimer = maxVolume;
    if (iVar3 < maxVolume)
    {
      sound->soundTimer = iVar3;
    }
    maxVolume = 0;
    if (iVar3 != 0)
    {
      iVar2 = sound->soundTimer;
      maxVolume = 0;
      if (iVar2 <= iVar3)
      {
        maxVolume = (int)sound->soundStartVolume +
                    iVar3;
        uVar1 = SOUND_Update3dSound(&instance->position,sound->soundHandle,
                                    (int)sound->soundStartPitch +
                                    (((int)sound->soundEndPitch - (int)sound->soundStartPitch) *
 iVar3,maxVolume,sound->soundDistance);
        if (uVar1 == 0) {
          SndEndLoop(sound->soundHandle);
          sound->soundHandle = 0;
        }
      }
    }
  }
  return maxVolume;
}

void razSetupSoundRamp(_Instance *instance, _SoundRamp *sound, int sfx, int startPitch, int endPitch,
                       int startVolume, int endVolume, int timer, int distance)

{
  u_long uVar1;

  if (sound->soundHandle == 0)
  {
    uVar1 = SOUND_Play3dSound(&instance->position, sfx, startPitch, startVolume, distance);
    sound->soundHandle = uVar1;
  }
  if (timer == 0)
  {
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

void RAZIEL_SetInteractiveMusic(int modifier, int action)

{
  u_int uVar1;

  uVar1 = 1 << (modifier & 0x1fU);
  if (action == 0)
  {
    if ((Raziel.soundModifier & uVar1) != 0)
    {
      SOUND_SetMusicModifier(modifier);
    }
    Raziel.soundModifier = Raziel.soundModifier & ~uVar1;
  }
  else
  {
    if ((Raziel.soundModifier & uVar1) == 0)
    {
      SOUND_ResetMusicModifier(modifier);
    }
    Raziel.soundModifier = Raziel.soundModifier | uVar1;
  }
  return;
}

void RAZIEL_StartNewGame(void)

{
  memset(&Raziel, 0, 0x5b0);
  return;
}

int razInBaseArea(char *name, int length)

{
  char *pcVar1;
  u_int uVar2;
  int iVar3;
  char acStack32[16];

  pcVar1 = strcmp(acStack32, gameTrackerX.baseAreaName);
  if (pcVar1 == (char *)0x0)
  {
    uVar2 = 0;
  }
  else
  {
    acStack32[length] = '\0';
    iVar3 = strcmpi(name, acStack32);
    uVar2 = (u_int)(iVar3 == 0);
  }
  return uVar2;
}
