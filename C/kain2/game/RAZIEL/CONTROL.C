#include "THISDUST.H"
#include "CONTROL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SetPhysics(struct _Instance *instance /*$s0*/, short gravity /*$a1*/, long x /*$s1*/, long y /*$s2*/, long z /*stack 16*/)
 // line 27, offset 0x8009a1b0
	/* begin block 1 */
		// Start line: 54
	/* end block 1 */
	// End Line: 55

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetPhysics(_Instance *instance,short gravity,long x,long y,long z)

{
  SetExternalForce(_ExternalForces,0,0,gravity,0,0x1000);
  instance->xVel = x;
  instance->yVel = y;
  instance->zVel = z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetPhysics(struct _Instance *instance /*$s2*/, short gravity /*$s3*/)
 // line 36, offset 0x8009a224
	/* begin block 1 */
		// Start line: 37
		// Start offset: 0x8009A224
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8009A2A4
	// End Line: 45

	/* begin block 2 */
		// Start line: 75
	/* end block 2 */
	// End Line: 76

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetPhysics(_Instance *instance,short gravity)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  iVar1 = 0x14;
  SetExternalForce(_ExternalForces,0,0,gravity,0,0x1000);
  do {
    iVar2 = iVar2 + 1;
    SetExternalForce((__Force *)((int)&_ExternalForces->Type + iVar1),0,0,0,0,0);
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
 // line 55, offset 0x8009a2e0
	/* begin block 1 */
		// Start line: 134
	/* end block 1 */
	// End Line: 135

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  SetExternalForce(_ExternalForces,*(short *)&instance->xAccl,*(short *)&instance->yAccl,
                   *(short *)&instance->zAccl,0,0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetImpulsePhysics(struct _Instance *instance /*$t1*/, struct __Player *player /*$a1*/)
 // line 67, offset 0x8009a388
	/* begin block 1 */
		// Start line: 68
		// Start offset: 0x8009A388

		/* begin block 1.1 */
			// Start line: 70
			// Start offset: 0x8009A39C
			// Variables:
		// 		int Dot; // $a3
		// 		int vLength; // $a2
		/* end block 1.1 */
		// End offset: 0x8009A4B0
		// End Line: 87
	/* end block 1 */
	// End offset: 0x8009A4B0
	// End Line: 91

	/* begin block 2 */
		// Start line: 161
	/* end block 2 */
	// End Line: 162

	/* begin block 3 */
		// Start line: 163
	/* end block 3 */
	// End Line: 164

void SetImpulsePhysics(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((*(uint *)(param_2 + 0x360) & 0x40000) == 0) {
    iVar4 = (int)*(short *)(param_2 + 0x36c);
    iVar2 = (int)*(short *)(param_2 + 0x36e);
    iVar1 = (int)*(short *)(param_2 + 0x370);
    iVar3 = iVar4 * iVar4 + iVar2 * iVar2 + iVar1 * iVar1;
    iVar1 = -(int)*(short *)(param_1 + 0xe0) * iVar4 + -(int)*(short *)(param_1 + 0xe2) * iVar2 +
            -(int)*(short *)(param_1 + 0xe4) * iVar1;
    if (iVar3 != 0) {
      *(short *)(param_1 + 0x5c) =
           *(short *)(param_1 + 0x5c) +
           *(short *)(param_1 + 0xe0) + (short)((iVar1 * iVar4) / iVar3);
      *(short *)(param_1 + 0x5e) =
           *(short *)(param_1 + 0x5e) +
           *(short *)(param_1 + 0xe2) + (short)((iVar1 * *(short *)(param_2 + 0x36e)) / iVar3);
      *(short *)(param_1 + 0x60) =
           *(short *)(param_1 + 0x60) +
           *(short *)(param_1 + 0xe4) + (short)((iVar1 * *(short *)(param_2 + 0x370)) / iVar3);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetDropPhysics(struct _Instance *instance /*$a0*/, struct __Player *player /*$a1*/)
 // line 110, offset 0x8009a4b8
	/* begin block 1 */
		// Start line: 257
	/* end block 1 */
	// End Line: 258

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetExternalForce(__Force *In,short x,short y,short z,int Space,int Friction)

{
  SetExternalForce(_CHAR____800d6cb8,0,4,-0x10,0,0x1000);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitExternalForces(struct __Force *Forces /*$a0*/, int MaxForces /*$a1*/)
 // line 147, offset 0x8009a4f0
	/* begin block 1 */
		// Start line: 149
		// Start offset: 0x8009A4F0
		// Variables:
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8009A524
	// End Line: 157

	/* begin block 2 */
		// Start line: 294
	/* end block 2 */
	// End Line: 295

	/* begin block 3 */
		// Start line: 303
	/* end block 3 */
	// End Line: 304

	/* begin block 4 */
		// Start line: 305
	/* end block 4 */
	// End Line: 306

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  _ExternalForces = Forces;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetExternalForce(struct __Force *In /*$a0*/, short x /*$a1*/, short y /*$a2*/, short z /*$a3*/, int Space /*stack 16*/, int Friction /*stack 20*/)
 // line 162, offset 0x8009a530
	/* begin block 1 */
		// Start line: 336
	/* end block 1 */
	// End Line: 337

	/* begin block 2 */
		// Start line: 338
	/* end block 2 */
	// End Line: 339

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
 // line 173, offset 0x8009a570
	/* begin block 1 */
		// Start line: 364
	/* end block 1 */
	// End Line: 365

	/* begin block 2 */
		// Start line: 366
	/* end block 2 */
	// End Line: 367

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
 // line 188, offset 0x8009a5d8
	/* begin block 1 */
		// Start line: 189
		// Start offset: 0x8009A5D8
		// Variables:
	// 		int time; // $s1

		/* begin block 1.1 */
			// Start line: 233
			// Start offset: 0x8009A738
		/* end block 1.1 */
		// End offset: 0x8009A74C
		// End Line: 244

		/* begin block 1.2 */
			// Start line: 246
			// Start offset: 0x8009A74C
		/* end block 1.2 */
		// End offset: 0x8009A7B4
		// End Line: 258
	/* end block 1 */
	// End offset: 0x8009A7B4
	// End Line: 289

	/* begin block 2 */
		// Start line: 395
	/* end block 2 */
	// End Line: 396

	/* begin block 3 */
		// Start line: 403
	/* end block 3 */
	// End Line: 404

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessPhysics(__Player *player,__CharacterState *In,int CurrentSection,int Mode)

{
  _Instance *p_Var1;
  __Player *player_00;
  __Force *Forces;
  _Vector *local_20;
  
  player_00 = (__Player *)In->CharacterInstance;
  if ((player_00->State).SectionList[0].Event.Queue[5].ID != 0) {
    Forces = (__Force *)
             ((uint)((player_00->State).SectionList[1].Defer.Queue[1].Data *
                    theCamera.tiltList[0][0]) >> 0xc);
    if (Mode == 4) {
      ApplyExternalLocalForces
                (player,In->CharacterInstance,_ExternalForces,4,
                 (_Vector *)&(player_00->State).SectionList[1].Event.Queue[5].Data);
      PhysicsMoveLocalZClamp(In->CharacterInstance,player->RotationSegment,(long)Forces,0);
      PHYSICS_StopIfCloseToTarget(In->CharacterInstance,0,0,0);
      p_Var1 = In->CharacterInstance;
      if (((p_Var1->xAccl == 0) && (p_Var1->yAccl == 0)) && (p_Var1->zAccl == 0)) {
        SetExternalForce(_ExternalForces,0,0,0,0,0);
      }
    }
    else {
      if (Mode < 5) {
        if (Mode == 0) {
          ApplyExternalLocalForces
                    (player,In->CharacterInstance,_ExternalForces,4,
                     (_Vector *)&(player_00->State).SectionList[1].Event.Queue[5].Data);
          PhysicsMoveLocalZClamp(In->CharacterInstance,player->RotationSegment,(long)Forces,0);
        }
      }
      else {
        if (Mode == 5) {
          ApplyExternalLocalForces(player_00,(_Instance *)player->RotationSegment,Forces,0,local_20)
          ;
          return;
        }
        if (Mode == 6) {
          PhysicsMoveLocalZClamp((_Instance *)player_00,player->RotationSegment,(long)Forces,1);
          PHYSICS_StopIfCloseToTarget((_Instance *)player_00,0,0,(int)player->swimTargetSpeed);
          if ((((player_00->State).SectionList[1].Event.Queue[5].Data == 0) &&
              ((player_00->State).SectionList[1].Event.Queue[6].ID == 0)) &&
             ((player_00->State).SectionList[1].Event.Queue[6].Data == 0)) {
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post((_Instance *)player_00,(int)&DAT_00100011,(int)player->swimTargetSpeed);
          }
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ApplyExternalLocalForces(struct __Player *player /*$a0*/, struct _Instance *instance /*$a1*/, struct __Force *Forces /*$a2*/, int MaxForces /*$a3*/, struct _Vector *Out /*stack 16*/)
 // line 347, offset 0x8009a7d0
	/* begin block 1 */
		// Start line: 348
		// Start offset: 0x8009A7D0
		// Variables:
	// 		int i; // $t1

		/* begin block 1.1 */
			// Start line: 385
			// Start offset: 0x8009A8D4
			// Variables:
		// 		int friction; // $a1
		/* end block 1.1 */
		// End offset: 0x8009A960
		// End Line: 394
	/* end block 1 */
	// End offset: 0x8009A970
	// End Line: 397

	/* begin block 2 */
		// Start line: 724
	/* end block 2 */
	// End Line: 725

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
LAB_8009a85c:
          Out->y = iVar1;
          Out->z = Out->z + (Forces->LinearForce).z;
        }
        else {
          if (Forces->Type == 1) {
            Out->x = Out->x + (Forces->LinearForce).x;
            iVar1 = Out->y + (Forces->LinearForce).y;
            goto LAB_8009a85c;
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





