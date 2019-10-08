#include "THISDUST.H"
#include "PLAYER.H"

void PLAYER_TurnHead(_Instance *instance, short *rotx, short *rotz, GameTracker *gameTracker)

{
  u_long uVar1;

  uVar1 = INSTANCE_Post(instance, 1);
  if ((uVar1 & 1) == 0)
  {
    MONAPI_TurnHead(instance, rotx, rotz, gameTracker);
  }
  else
  {
    RAZIEL_TurnHead(instance, rotx, rotz, gameTracker);
  }
  return;
}

long RAZIEL_OkToLookAround(_Instance *instance)

{
  u_long uVar1;
  long lVar2;

  uVar1 = INSTANCE_Post(instance, 1);
  if ((uVar1 & 1) == 0)
  {
    lVar2 = MONAPI_OkToLookAround(instance);
  }
  else
  {
    lVar2 = PLAYER_OkToLookAround(instance);
  }
  return lVar2;
}

void PLAYER_SetLookAround(_Instance *instance)

{
  u_long uVar1;

  uVar1 = INSTANCE_Post(instance, 1);
  if ((uVar1 & 1) == 0)
  {
    MONAPI_SetLookAround(instance);
  }
  else
  {
    RAZIEL_SetLookAround(instance);
  }
  return;
}

void RAZIEL_ResetLookAround(_Instance *instance)

{
  u_long uVar1;

  uVar1 = INSTANCE_Post(instance, 1);
  if ((uVar1 & 1) == 0)
  {
    MONAPI_ResetLookAround(instance);
  }
  else
  {
    PLAYER_ReSetLookAround(instance);
  }
  return;
}
