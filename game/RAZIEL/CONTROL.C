#include "THISDUST.H"
#include "CONTROL.H"

void SetPhysicsGravityData(_Instance *instance, short gravity, long x, long y, long z)

{
  SetExternalTransitionForce(ExternalForces, 0, 0, gravity, 0, 0x1000);
  instance->xVel = x;
  instance->yVel = y;
  instance->zVel = z;
  return;
}

void PhysicsMove(_Instance *instance, short gravity)

{
  int iVar1;
  int iVar2;

  iVar2 = 1;
  iVar1 = 0x14;
  SetExternalTransitionForce(ExternalForces, 0, 0, gravity, 0, 0x1000);
  do
  {
    iVar2 = iVar2 + 1;
    SetExternalTransitionForce((__Force *)((int)&ExternalForces->Type + iVar1), 0, 0, 0, 0, 0);
    iVar1 = iVar1 + 0x14;
  } while (iVar2 < 4);
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = (int)gravity;
  return;
}

void SetDampingPhysics(_Instance *instance, int damping)

{
  int iVar1;
  int iVar2;

  iVar1 = instance->xVel * damping;
  if (iVar1 < 0)
  {
    iVar1 = iVar1 + 0xfff;
  }
  iVar2 = instance->yVel * damping;
  instance->xAccl = -(iVar1 >> 0xc);
  if (iVar2 < 0)
  {
    iVar2 = iVar2 + 0xfff;
  }
  damping = instance->zVel * damping;
  instance->yAccl = -(iVar2 >> 0xc);
  if (damping < 0)
  {
    damping = damping + 0xfff;
  }
  instance->zAccl = -(damping >> 0xc);
  SetExternalTransitionForce(ExternalForces, *(short *)&instance->xAccl, *(short *)&instance->yAccl,
                             *(short *)&instance->zAccl, 0, 0x1000);
  return;
}

void SetImpulsePhysics(_Instance *instance, __Player *player)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  if ((player->Mode & 0x40000U) == 0)
  {
    iVar4 = (int)(player->iVelocity).x;
    iVar2 = (int)(player->iVelocity).y;
    iVar1 = (int)(player->iVelocity).z;
    iVar3 = iVar4 * iVar4 + iVar2 * iVar2 + iVar1 * iVar1;
    iVar1 = -(int)(instance->offset).x * iVar4 + -(int)(instance->offset).y * iVar2 +
            -(int)(instance->offset).z * iVar1;
    if (iVar3 != 0)
    {
      (instance->position).x =
 iVar3);
      (instance->position).y =
           (instance->position).y +
 iVar3);
      (instance->position).z =
           (instance->position).z +
 iVar3);
    }
  }
  return;
}

void SetDropPhysics(_Instance *instance, __Player *player)

{
  SetExternalTransitionForce(ExternalForces, 0, 4, -0x10, 0, 0x1000);
  return;
}

void InitExternalForces(__Force *Forces, int MaxForces)

{
  __Force *p_Var1;

  MaxForces = MaxForces + -1;
  if (MaxForces != 0)
  {
    p_Var1 = Forces + MaxForces;
    do
    {
      p_Var1->Friction = 0;
      (p_Var1->LinearForce).x = 0;
      (p_Var1->LinearForce).y = 0;
      (p_Var1->LinearForce).z = 0;
      MaxForces = MaxForces + -1;
      p_Var1 = p_Var1 + -1;
    } while (MaxForces != 0);
  }
  ExternalForces = Forces;
  return;
}

void SetExternalTransitionForce(__Force *In, short x, short y, short z, int Space, int Friction)

{
  (In->LinearForce).x = (int)x;
  (In->LinearForce).y = (int)y;
  (In->LinearForce).z = (int)z;
  In->Friction = (short)Friction;
  In->Type = (int)(short)Space;
  return;
}

void SetExternalForce(__Force *in, _Instance *instance, int time, int x, int y, int z)

{
  int iVar1;

  in->Type = 2;
  time;
  time;
  iVar1 = instance->zVel;
  in->Friction = (short)time;
  time;
  return;
}

void ProcessPhysicalObject(__Player *player, __CharacterState *In, int CurrentSection, int Mode)

{
  long segment;
  long clamp;
  _Instance *instance;
  u_int time;

  instance = In->CharacterInstance;
  if (instance->matrix != (MATRIX *)0x0)
  {
    time = (instance->anim).section[0].speedAdjustment * gameTrackerX.timeMult >> 0xc;
    if (Mode == 4)
    {
      ApplyExternalLocalForces(player, In->CharacterInstance, ExternalForces, 4, (_Vector *)&instance->xAccl);
      PhysicsMoveLocalZClamp(In->CharacterInstance, player->RotationSegment, time, 0);
      PHYSICS_StopIfCloseToTarget(In->CharacterInstance, 0, 0, 0);
      instance = In->CharacterInstance;
      if (((instance->xAccl == 0) && (instance->yAccl == 0)) && (instance->zAccl == 0))
      {
        SetExternalTransitionForce(ExternalForces, 0, 0, 0, 0, 0);
      }
    }
    else
    {
      if (Mode < 5)
      {
        if (Mode == 0)
        {
          ApplyExternalLocalForces(player, In->CharacterInstance, ExternalForces, 4, (_Vector *)&instance->xAccl);
          PhysicsMoveLocalZClamp(In->CharacterInstance, player->RotationSegment, time, 0);
        }
      }
      else
      {
        if (Mode == 5)
        {
          segment = player->RotationSegment;
          clamp = 0;
        }
        else
        {
          if (Mode != 6)
          {
            return;
          }
          segment = player->RotationSegment;
          clamp = 1;
        }
        PhysicsMoveLocalZClamp(instance, segment, time, clamp);
        PHYSICS_StopIfCloseToTarget(instance, 0, 0, (int)player->swimTargetSpeed);
        if (((instance->xAccl == 0) && (instance->yAccl == 0)) && (instance->zAccl == 0))
        {
          INSTANCE_Query(instance, (int)&DAT_00100011, (int)player->swimTargetSpeed);
        }
      }
    }
  }
  return;
}

void ApplyExternalLocalForces(__Player *player, _Instance *instance, __Force *Forces, int MaxForces, _Vector *Out)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  iVar3 = 0;
  Out->z = 0;
  Out->y = 0;
  Out->x = 0;
  if (0 < MaxForces)
  {
    do
    {
      if (Forces->Friction != 0)
      {
        if (Forces->Type == 0)
        {
          Out->x = Out->x + (Forces->LinearForce).x;
          iVar1 = Out->y - (Forces->LinearForce).y;
        LAB_80099fac:
          Out->y = iVar1;
          Out->z = Out->z + (Forces->LinearForce).z;
        }
        else
        {
          if (Forces->Type == 1)
          {
            Out->x = Out->x + (Forces->LinearForce).x;
            iVar1 = Out->y + (Forces->LinearForce).y;
            goto LAB_80099fac;
          }
        }
        if (Forces->Type == 2)
        {
          Out->x = Out->x + (Forces->LinearForce).x;
          Out->y = Out->y - (Forces->LinearForce).y;
          Out->z = Out->z + (Forces->LinearForce).z;
          Forces->Friction = Forces->Friction + -1;
        }
        else
        {
          iVar2 = (int)Forces->Friction;
          iVar1 = (Forces->LinearForce).x * iVar2;
          if (iVar1 < 0)
          {
            iVar1 = iVar1 + 0xfff;
          }
          iVar4 = (Forces->LinearForce).y * iVar2;
          (Forces->LinearForce).x = iVar1 >> 0xc;
          if (iVar4 < 0)
          {
            iVar4 = iVar4 + 0xfff;
          }
          iVar2 = (Forces->LinearForce).z * iVar2;
          (Forces->LinearForce).y = iVar4 >> 0xc;
          if (iVar2 < 0)
          {
            iVar2 = iVar2 + 0xfff;
          }
          (Forces->LinearForce).z = iVar2 >> 0xc;
          if ((((Forces->LinearForce).x == 0) && ((Forces->LinearForce).y == 0)) &&
              (iVar2 >> 0xc == 0))
          {
            Forces->Friction = 0;
          }
        }
      }
      iVar3 = iVar3 + 1;
      Forces = Forces + 1;
    } while (iVar3 < MaxForces);
  }
  Out->y = -Out->y;
  return;
}
