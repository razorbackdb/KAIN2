
#include "PLAYER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ PLAYER_TurnHead(struct _Instance *instance /*$s0*/, short *rotx /*$s1*/, short *rotz /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 25, offset 0x80012c2c
	/* begin block 1 */
		// Start line: 50
	/* end block 1 */
	// End Line: 51

/* File: C:\kain2\game\PLAYER.C */

void PLAYER_TurnHead(_Instance *instance,short *rotx,short *rotz,GameTracker *gameTracker)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(instance,1);
  if ((uVar1 & 1) == 0) {
    MONAPI_TurnHead(instance,rotx,rotz,gameTracker);
  }
  else {
    RAZIEL_TurnHead(instance,rotx,rotz,gameTracker);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PLAYER_OkToLookAround(struct _Instance *instance /*$s0*/)
 // line 33, offset 0x80012cac
	/* begin block 1 */
		// Start line: 66
	/* end block 1 */
	// End Line: 67

/* File: C:\kain2\game\PLAYER.C */

long PLAYER_OkToLookAround(_Instance *instance)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = INSTANCE_Query(instance,1);
  if ((uVar1 & 1) == 0) {
    lVar2 = MONAPI_OkToLookAround(instance);
  }
  else {
    lVar2 = RAZIEL_OkToLookAround(instance);
  }
  return lVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAYER_SetLookAround(struct _Instance *instance /*$s0*/)
 // line 41, offset 0x80012cf8
	/* begin block 1 */
		// Start line: 80
	/* end block 1 */
	// End Line: 81

	/* begin block 2 */
		// Start line: 84
	/* end block 2 */
	// End Line: 85

/* File: C:\kain2\game\PLAYER.C */

void PLAYER_SetLookAround(_Instance *instance)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(instance,1);
  if ((uVar1 & 1) == 0) {
    MONAPI_SetLookAround(instance);
  }
  else {
    RAZIEL_SetLookAround(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAYER_ReSetLookAround(struct _Instance *instance /*$s0*/)
 // line 49, offset 0x80012d44
	/* begin block 1 */
		// Start line: 100
	/* end block 1 */
	// End Line: 101

/* File: C:\kain2\game\PLAYER.C */

void PLAYER_ReSetLookAround(_Instance *instance)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(instance,1);
  if ((uVar1 & 1) == 0) {
    MONAPI_ResetLookAround(instance);
  }
  else {
    RAZIEL_ResetLookAround(instance);
  }
  return;
}





