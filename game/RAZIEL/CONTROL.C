#include "THISDUST.H"
#include "CONTROL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SetPhysics(struct _Instance *instance /*$s0*/, short gravity /*$a1*/, long x /*$s1*/, long y /*$s2*/, long z /*stack 16*/)
 // line 27, offset 0x80097bf0
	/* begin block 1 */
		// Start line: 54
	/* end block 1 */
	// End Line: 55

void SetPhysics(_Instance *instance,short gravity,long x,long y,long z)

{
  SetExternalForce(ExternalForces,0,0,gravity,0,0x1000);
  instance->xVel = x;
  instance->yVel = y;
  instance->zVel = z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetPhysics(struct _Instance *instance /*$s2*/, short gravity /*$s3*/)
 // line 36, offset 0x80097c64
	/* begin block 1 */
		// Start line: 37
		// Start offset: 0x80097C64
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x80097CE4
	// End Line: 45

	/* begin block 2 */
		// Start line: 75
	/* end block 2 */
	// End Line: 76

void ResetPhysics(_Instance *instance,short gravity)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  iVar1 = 0x14;
  SetExternalForce(ExternalForces,0,0,gravity,0,0x1000);
  do {
    iVar2 = iVar2 + 1;
    SetExternalForce((__Force *)((int)&ExternalForces->Type + iVar1),0,0,0,0,0);
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



// decompiled code
// original method signature: 
// void /*$ra*/ SetDampingPhysics(struct _Instance *instance /*$a0*/, int damping /*$a1*/)
 // line 55, offset 0x80097d20
	/* begin block 1 */
		// Start line: 134
	/* end block 1 */
	// End Line: 135

void SetDampingPhysics(_Instance *instance,int damping)

{
  int iVar1;
  int iVar2;
  
  iVar1 = instance->xVel * damping;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  iVar2 = instance->yVel * damping;
  instance->xAccl = -(iVar1 >> 0xc);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  damping = instance->zVel * damping;
  instance->yAccl = -(iVar2 >> 0xc);
  if (damping < 0) {
    damping = damping + 0xfff;
  }
  instance->zAccl = -(damping >> 0xc);
  SetExternalForce(ExternalForces,*(short *)&instance->xAccl,*(short *)&instance->yAccl,
                   *(short *)&instance->zAccl,0,0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetImpulsePhysics(struct _Instance *instance /*$t1*/, struct __Player *player /*$a1*/)
 // line 67, offset 0x80097dc8
	/* begin block 1 */
		// Start line: 68
		// Start offset: 0x80097DC8

		/* begin block 1.1 */
			// Start line: 70
			// Start offset: 0x80097DD8
			// Variables:
		// 		int Dot; // $a3
		// 		int vLength; // $a2
		/* end block 1.1 */
		// End offset: 0x80097EEC
		// End Line: 86
	/* end block 1 */
	// End offset: 0x80097EEC
	// End Line: 90

	/* begin block 2 */
		// Start line: 161
	/* end block 2 */
	// End Line: 162

	/* begin block 3 */
		// Start line: 163
	/* end block 3 */
	// End Line: 164

void SetImpulsePhysics(_Instance *instance,__Player *player)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (player->Mode != 0x40000) {
    iVar4 = (int)(player->iVelocity).x;
    iVar2 = (int)(player->iVelocity).y;
    iVar1 = (int)(player->iVelocity).z;
    iVar3 = iVar4 * iVar4 + iVar2 * iVar2 + iVar1 * iVar1;
    iVar1 = -(int)(instance->offset).x * iVar4 + -(int)(instance->offset).y * iVar2 +
            -(int)(instance->offset).z * iVar1;
    if (iVar3 != 0) {
      (instance->position).x =
           (instance->position).x + (instance->offset).x + (short)((iVar1 * iVar4) / iVar3);
      (instance->position).y =
           (instance->position).y +
           (instance->offset).y + (short)((iVar1 * (player->iVelocity).y) / iVar3);
      (instance->position).z =
           (instance->position).z +
           (instance->offset).z + (short)((iVar1 * (player->iVelocity).z) / iVar3);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetDropPhysics(struct _Instance *instance /*$a0*/, struct __Player *player /*$a1*/)
 // line 109, offset 0x80097ef4
	/* begin block 1 */
		// Start line: 255
	/* end block 1 */
	// End Line: 256

void SetDropPhysics(_Instance *instance,__Player *player)

{
  SetExternalForce(ExternalForces,0,4,-0x10,0,0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitExternalForces(struct __Force *Forces /*$a0*/, int MaxForces /*$a1*/)
 // line 146, offset 0x80097f2c
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x80097F2C
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80097F60
	// End Line: 156

	/* begin block 2 */
		// Start line: 285
	/* end block 2 */
	// End Line: 286

	/* begin block 3 */
		// Start line: 301
	/* end block 3 */
	// End Line: 302

	/* begin block 4 */
		// Start line: 303
	/* end block 4 */
	// End Line: 304

void InitExternalForces(__Force *Forces,int MaxForces)

{
  __Force *p_Var1;
  
  MaxForces = MaxForces + -1;
  if (MaxForces != 0) {
    p_Var1 = Forces + MaxForces;
    do {
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



// decompiled code
// original method signature: 
// void /*$ra*/ SetExternalForce(struct __Force *In /*$a0*/, short x /*$a1*/, short y /*$a2*/, short z /*$a3*/, int Space /*stack 16*/, int Friction /*stack 20*/)
 // line 161, offset 0x80097f6c
	/* begin block 1 */
		// Start line: 334
	/* end block 1 */
	// End Line: 335

	/* begin block 2 */
		// Start line: 336
	/* end block 2 */
	// End Line: 337

void SetExternalForce(__Force *In,short x,short y,short z,int Space,int Friction)

{
  (In->LinearForce).x = (int)x;
  (In->LinearForce).y = (int)y;
  (In->LinearForce).z = (int)z;
  In->Friction = (short)Friction;
  In->Type = (int)(short)Space;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetExternalTransitionForce(struct __Force *in /*$a0*/, struct _Instance *instance /*$a1*/, int time /*$a2*/, int x /*$a3*/, int y /*stack 16*/, int z /*stack 20*/)
 // line 172, offset 0x80097fac
	/* begin block 1 */
		// Start line: 362
	/* end block 1 */
	// End Line: 363

	/* begin block 2 */
		// Start line: 364
	/* end block 2 */
	// End Line: 365

void SetExternalTransitionForce(__Force *in,_Instance *instance,int time,int x,int y,int z)

{
  int iVar1;
  
  in->Type = 2;
  (in->LinearForce).x = (x - instance->xVel) / time;
  (in->LinearForce).y = (y - instance->yVel) / time;
  iVar1 = instance->zVel;
  in->Friction = (short)time;
  (in->LinearForce).z = (z - iVar1) / time;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessPhysics(struct __Player *player /*$s3*/, struct __CharacterState *In /*$s2*/, int CurrentSection /*$a2*/, int Mode /*$a3*/)
 // line 187, offset 0x80098014
	/* begin block 1 */
		// Start line: 188
		// Start offset: 0x80098014
		// Variables:
	// 		int time; // $s1

		/* begin block 1.1 */
			// Start line: 232
			// Start offset: 0x80098174
		/* end block 1.1 */
		// End offset: 0x80098188
		// End Line: 243

		/* begin block 1.2 */
			// Start line: 245
			// Start offset: 0x80098188
		/* end block 1.2 */
		// End offset: 0x800981F0
		// End Line: 257
	/* end block 1 */
	// End offset: 0x800981F0
	// End Line: 288

	/* begin block 2 */
		// Start line: 393
	/* end block 2 */
	// End Line: 394

	/* begin block 3 */
		// Start line: 401
	/* end block 3 */
	// End Line: 402

void ProcessPhysics(__Player *player,__CharacterState *In,int CurrentSection,int Mode)

{
  long segment;
  long clamp;
  _Instance *instance;
  uint time;
  
  instance = In->CharacterInstance;
  if (instance->matrix != (MATRIX *)0x0) {
    time = (instance->anim).section[0].speedAdjustment * gameTrackerX.idleTime >> 0xc;
    if (Mode == 4) {
      ApplyExternalLocalForces
                (player,In->CharacterInstance,ExternalForces,4,(_Vector *)&instance->xAccl);
      PhysicsMoveLocalZClamp(In->CharacterInstance,player->RotationSegment,time,0);
      PHYSICS_StopIfCloseToTarget(In->CharacterInstance,0,0,0);
      instance = In->CharacterInstance;
      if (((instance->xAccl == 0) && (instance->yAccl == 0)) && (instance->zAccl == 0)) {
        SetExternalForce(ExternalForces,0,0,0,0,0);
      }
    }
    else {
      if (Mode < 5) {
        if (Mode == 0) {
          ApplyExternalLocalForces
                    (player,In->CharacterInstance,ExternalForces,4,(_Vector *)&instance->xAccl);
          PhysicsMoveLocalZClamp(In->CharacterInstance,player->RotationSegment,time,0);
        }
      }
      else {
        if (Mode == 5) {
          segment = player->RotationSegment;
          clamp = 0;
        }
        else {
          if (Mode != 6) {
            return;
          }
          segment = player->RotationSegment;
          clamp = 1;
        }
        PhysicsMoveLocalZClamp(instance,segment,time,clamp);
        PHYSICS_StopIfCloseToTarget
                  (instance,0,0,(int)*(short *)((int)&(player->padCommands).Queue[8].Data + 2));
        if (((instance->xAccl == 0) && (instance->yAccl == 0)) && (instance->zAccl == 0)) {
          INSTANCE_Post(instance,0x100011,
                        (int)*(short *)((int)&(player->padCommands).Queue[8].Data + 2));
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ApplyExternalLocalForces(struct __Player *player /*$a0*/, struct _Instance *instance /*$a1*/, struct __Force *Forces /*$a2*/, int MaxForces /*$a3*/, struct _Vector *Out /*stack 16*/)
 // line 346, offset 0x8009820c
	/* begin block 1 */
		// Start line: 347
		// Start offset: 0x8009820C
		// Variables:
	// 		int i; // $t1

		/* begin block 1.1 */
			// Start line: 384
			// Start offset: 0x80098310
			// Variables:
		// 		int friction; // $a1
		/* end block 1.1 */
		// End offset: 0x8009839C
		// End Line: 393
	/* end block 1 */
	// End offset: 0x800983AC
	// End Line: 396

	/* begin block 2 */
		// Start line: 722
	/* end block 2 */
	// End Line: 723

void ApplyExternalLocalForces
               (__Player *player,_Instance *instance,__Force *Forces,int MaxForces,_Vector *Out)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  Out->z = 0;
  Out->y = 0;
  Out->x = 0;
  if (0 < MaxForces) {
    do {
      if (Forces->Friction != 0) {
        if (Forces->Type == 0) {
          Out->x = Out->x + (Forces->LinearForce).x;
          iVar1 = Out->y - (Forces->LinearForce).y;
LAB_80098298:
          Out->y = iVar1;
          Out->z = Out->z + (Forces->LinearForce).z;
        }
        else {
          if (Forces->Type == 1) {
            Out->x = Out->x + (Forces->LinearForce).x;
            iVar1 = Out->y + (Forces->LinearForce).y;
            goto LAB_80098298;
          }
        }
        if (Forces->Type == 2) {
          Out->x = Out->x + (Forces->LinearForce).x;
          Out->y = Out->y - (Forces->LinearForce).y;
          Out->z = Out->z + (Forces->LinearForce).z;
          Forces->Friction = Forces->Friction + -1;
        }
        else {
          iVar2 = (int)Forces->Friction;
          iVar1 = (Forces->LinearForce).x * iVar2;
          if (iVar1 < 0) {
            iVar1 = iVar1 + 0xfff;
          }
          iVar4 = (Forces->LinearForce).y * iVar2;
          (Forces->LinearForce).x = iVar1 >> 0xc;
          if (iVar4 < 0) {
            iVar4 = iVar4 + 0xfff;
          }
          iVar2 = (Forces->LinearForce).z * iVar2;
          (Forces->LinearForce).y = iVar4 >> 0xc;
          if (iVar2 < 0) {
            iVar2 = iVar2 + 0xfff;
          }
          (Forces->LinearForce).z = iVar2 >> 0xc;
          if ((((Forces->LinearForce).x == 0) && ((Forces->LinearForce).y == 0)) &&
             (iVar2 >> 0xc == 0)) {
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





