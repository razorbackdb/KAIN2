#include "THISDUST.H"
#include "SOUL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_QueueHandler(struct _Instance *instance /*$s0*/)
 // line 80, offset 0x8008d504
	/* begin block 1 */
		// Start line: 81
		// Start offset: 0x8008D504
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct __Event *message; // $a1
	/* end block 1 */
	// End offset: 0x8008D584
	// End Line: 95

	/* begin block 2 */
		// Start line: 160
	/* end block 2 */
	// End Line: 161

void SOUL_QueueHandler(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Physics(struct _Instance *instance /*$a0*/, long time /*$a2*/)
 // line 100, offset 0x8008d5a0
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x8008D5A0
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int a; // $a1
	/* end block 1 */
	// End offset: 0x8008D5CC
	// End Line: 114

	/* begin block 2 */
		// Start line: 208
	/* end block 2 */
	// End Line: 209

void SOUL_Physics(_Instance *instance,long time)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = instance->extraData;
  iVar2 = -4;
  if ((*(ushort *)((int)pvVar1 + 0x126) & 0x1f) < 0x10) {
    iVar2 = 4;
  }
  instance->zAccl = instance->zAccl + iVar2;
  *(short *)((int)pvVar1 + 0x126) = *(short *)((int)pvVar1 + 0x126) + 1;
  PhysicsMove(instance,&instance->position,time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Fade(struct _Instance *instance /*$s0*/)
 // line 120, offset 0x8008d600
	/* begin block 1 */
		// Start line: 121
		// Start offset: 0x8008D600
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		unsigned long time; // $a0
	/* end block 1 */
	// End offset: 0x8008D6A8
	// End Line: 145

	/* begin block 2 */
		// Start line: 251
	/* end block 2 */
	// End Line: 252

void SOUL_Fade(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_MoveToDest(struct _Instance *instance /*$a3*/, long maxAccel /*$t0*/, long time /*$a2*/)
 // line 147, offset 0x8008d6bc
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x8008D6BC
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	/* end block 1 */
	// End offset: 0x8008D790
	// End Line: 158

	/* begin block 2 */
		// Start line: 306
	/* end block 2 */
	// End Line: 307

void SOUL_MoveToDest(_Instance *instance,long maxAccel,long time)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  instance->xAccl =
       ((int)*(short *)((int)pvVar1 + 0x120) - (int)(instance->position).x) - instance->xVel;
  instance->yAccl =
       ((int)*(short *)((int)pvVar1 + 0x122) - (int)(instance->position).y) - instance->yVel;
  instance->zAccl =
       ((int)*(short *)((int)pvVar1 + 0x124) - (int)(instance->position).z) - instance->zVel;
  if (instance->xAccl < -maxAccel) {
    instance->xAccl = -maxAccel;
  }
  else {
    if (maxAccel < instance->xAccl) {
      instance->xAccl = maxAccel;
    }
  }
  if (instance->yAccl < -maxAccel) {
    instance->yAccl = -maxAccel;
  }
  else {
    if (maxAccel < instance->yAccl) {
      instance->yAccl = maxAccel;
    }
  }
  if (instance->zAccl < -maxAccel) {
    instance->zAccl = -maxAccel;
  }
  else {
    if (maxAccel < instance->zAccl) {
      instance->zAccl = maxAccel;
    }
  }
  SOUL_Physics(instance,time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Init(struct _Instance *instance /*$s0*/)
 // line 164, offset 0x8008d7ac
	/* begin block 1 */
		// Start line: 165
		// Start offset: 0x8008D7AC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008D868
	// End Line: 189

	/* begin block 2 */
		// Start line: 341
	/* end block 2 */
	// End Line: 342

void SOUL_Init(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_DefaultInit(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_CleanUp(struct _Instance *instance /*$a0*/)
 // line 195, offset 0x8008d87c
	/* begin block 1 */
		// Start line: 414
	/* end block 1 */
	// End Line: 415

void SOUL_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_BirthEntry(struct _Instance *instance /*$a0*/)
 // line 205, offset 0x8008d89c
	/* begin block 1 */
		// Start line: 206
		// Start offset: 0x8008D89C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008D89C
	// End Line: 206

	/* begin block 2 */
		// Start line: 434
	/* end block 2 */
	// End Line: 435

void SOUL_BirthEntry(_Instance *instance)

{
  short sVar1;
  
  sVar1 = (instance->position).z;
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
  instance->maxZVel = 0x11;
  instance->zAccl = 0;
  instance->zVel = 0;
                    /* WARNING: Subroutine does not return */
  (instance->position).z = sVar1 + 0x78;
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Birth(struct _Instance *instance /*$s1*/)
 // line 216, offset 0x8008d8f0
	/* begin block 1 */
		// Start line: 217
		// Start offset: 0x8008D8F0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008D93C
	// End Line: 228

	/* begin block 2 */
		// Start line: 460
	/* end block 2 */
	// End Line: 461

void SOUL_Birth(_Instance *instance)

{
  instance->zAccl = 0;
  SOUL_Physics(instance,gameTrackerX.timeMult);
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_SoulSuckEntry(struct _Instance *instance /*$a0*/)
 // line 234, offset 0x8008d958
	/* begin block 1 */
		// Start line: 499
	/* end block 1 */
	// End Line: 500

	/* begin block 2 */
		// Start line: 502
	/* end block 2 */
	// End Line: 503

void SOUL_SoulSuckEntry(_Instance *instance)

{
  instance->maxXVel = 600;
  instance->maxYVel = 600;
  instance->maxZVel = 0x11;
  instance->flags = instance->flags & 0xfffff7ff;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SOUL_CalcAccel(long delta /*$a0*/, long vel /*$a1*/, long magnitude /*$a2*/)
 // line 242, offset 0x8008d980
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x8008D980
		// Variables:
	// 		long rv; // $a2
	/* end block 1 */
	// End offset: 0x8008D9B8
	// End Line: 269

	/* begin block 2 */
		// Start line: 512
	/* end block 2 */
	// End Line: 513

	/* begin block 3 */
		// Start line: 517
	/* end block 3 */
	// End Line: 518

	/* begin block 4 */
		// Start line: 518
	/* end block 4 */
	// End Line: 519

	/* begin block 5 */
		// Start line: 524
	/* end block 5 */
	// End Line: 525

long SOUL_CalcAccel(long delta,long vel,long magnitude)

{
  int iVar1;
  
  if (delta < 1) {
    if (0 < vel) {
      iVar1 = delta << 4;
      goto LAB_8008d9b0;
    }
  }
  else {
    if (vel < 0) {
      iVar1 = delta << 4;
      goto LAB_8008d9b0;
    }
  }
  iVar1 = delta * 5;
LAB_8008d9b0:
  return iVar1 / magnitude;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_SoulSuck(struct _Instance *instance /*$s2*/)
 // line 272, offset 0x8008d9c0
	/* begin block 1 */
		// Start line: 273
		// Start offset: 0x8008D9C0
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct __Event *message; // $s0
	// 		int mindist; // $fp
	// 		struct _Instance *sucker; // $s4
	// 		struct _Instance *collidedWith; // $s5

		/* begin block 1.1 */
			// Start line: 288
			// Start offset: 0x8008DA60
			// Variables:
		// 		long distance; // $s1
		// 		struct evMonsterSoulSuckData *suckData; // $s0

			/* begin block 1.1.1 */
				// Start line: 315
				// Start offset: 0x8008DB84
				// Variables:
			// 		struct _SVector dir; // stack offset -48

				/* begin block 1.1.1.1 */
					// Start line: 326
					// Start offset: 0x8008DBB8
					// Variables:
				// 		long animLen; // $s0
				// 		long curTim; // $v0

					/* begin block 1.1.1.1.1 */
						// Start line: 337
						// Start offset: 0x8008DC50
						// Variables:
					// 		short _x0; // $a3
					// 		short _y0; // $a0
					// 		short _z0; // $v1
					// 		short _x1; // $v0
					// 		short _y1; // $a2
					// 		short _z1; // $a1
					// 		struct _SVector *_v; // $s6
					// 		struct _Position *_v0; // $v1
					// 		struct _Position *_v1; // $a1
					/* end block 1.1.1.1.1 */
					// End offset: 0x8008DC50
					// End Line: 337
				/* end block 1.1.1.1 */
				// End offset: 0x8008DD04
				// End Line: 347
			/* end block 1.1.1 */
			// End offset: 0x8008DD04
			// End Line: 347
		/* end block 1.1 */
		// End offset: 0x8008DD3C
		// End Line: 356

		/* begin block 1.2 */
			// Start line: 389
			// Start offset: 0x8008DE5C
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.2 */
		// End offset: 0x8008DE7C
		// End Line: 393
	/* end block 1 */
	// End offset: 0x8008DED8
	// End Line: 406

	/* begin block 2 */
		// Start line: 577
	/* end block 2 */
	// End Line: 578

void SOUL_SoulSuck(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_WanderEntry(struct _Instance *instance /*$a0*/)
 // line 411, offset 0x8008df08
	/* begin block 1 */
		// Start line: 412
		// Start offset: 0x8008DF08
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	/* end block 1 */
	// End offset: 0x8008DF68
	// End Line: 424

	/* begin block 2 */
		// Start line: 893
	/* end block 2 */
	// End Line: 894

void SOUL_WanderEntry(_Instance *instance)

{
  _Position *in;
  short r;
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  instance->maxXVel = 10;
  instance->maxYVel = 10;
  instance->maxZVel = 0x11;
  if ((*puVar1 & 0x40000) == 0) {
    in = &instance->intro->position;
    if (instance->intro == (Intro *)0x0) {
      r = *(short *)((int)puVar1 + 0x136);
      in = &instance->position;
    }
    else {
      r = *(short *)((int)puVar1 + 0x136);
    }
    MON_GetRandomDestinationInWorld(instance,in,r);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Wander(struct _Instance *instance /*$s0*/)
 // line 426, offset 0x8008df78
	/* begin block 1 */
		// Start line: 427
		// Start offset: 0x8008DF78
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 439
			// Start offset: 0x8008DFE4
		/* end block 1.1 */
		// End offset: 0x8008E094
		// End Line: 452
	/* end block 1 */
	// End offset: 0x8008E0EC
	// End Line: 467

	/* begin block 2 */
		// Start line: 923
	/* end block 2 */
	// End Line: 924

void SOUL_Wander(_Instance *instance)

{
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if ((*puVar1 & 0x40000) != 0) {
                    /* WARNING: Subroutine does not return */
    MATH3D_LengthXY((int)*(short *)(puVar1 + 0x48) - (int)(instance->position).x,
                    (int)*(short *)((int)puVar1 + 0x122) - (int)(instance->position).y);
  }
  if (instance->intro == (Intro *)0x0) {
    MON_GetRandomDestinationInWorld(instance,&instance->position,*(short *)((int)puVar1 + 0x136));
    instance->zAccl = 0;
  }
  else {
    MON_GetRandomDestinationInWorld
              (instance,&instance->intro->position,*(short *)((int)puVar1 + 0x136));
    instance->zAccl = 0;
  }
  SOUL_Physics(instance,gameTrackerX.timeMult);
  if ((*puVar1 & 4) == 0) {
    if ((instance->flags2 & 0x8000000U) == 0) {
      SOUL_Fade(instance);
    }
    if (puVar1[0x31] != 0) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
  }
  SOUL_QueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_FleeEntry(struct _Instance *instance /*$a0*/)
 // line 473, offset 0x8008e108
	/* begin block 1 */
		// Start line: 1018
	/* end block 1 */
	// End Line: 1019

void SOUL_FleeEntry(_Instance *instance)

{
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
  instance->maxZVel = 0x11;
  MON_FleeEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Flee(struct _Instance *instance /*$s0*/)
 // line 480, offset 0x8008e138
	/* begin block 1 */
		// Start line: 481
		// Start offset: 0x8008E138
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 490
			// Start offset: 0x8008E174
			// Variables:
		// 		struct _Instance *enemy; // $a0
		// 		int dx; // $s1
		// 		int dy; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E258
		// End Line: 505
	/* end block 1 */
	// End offset: 0x8008E288
	// End Line: 511

	/* begin block 2 */
		// Start line: 1033
	/* end block 2 */
	// End Line: 1034

void SOUL_Flee(_Instance *instance)

{
  int iVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  iVar1 = *(int *)((int)instance->extraData + 0xc4);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
                    /* WARNING: Subroutine does not return */
  MATH3D_AngleFromPosToPos((_Position *)(*(int *)(iVar1 + 4) + 0x5c),&instance->position);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_IdleEntry(struct _Instance *instance /*$a0*/)
 // line 516, offset 0x8008e29c
	/* begin block 1 */
		// Start line: 517
		// Start offset: 0x8008E29C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008E29C
	// End Line: 517

	/* begin block 2 */
		// Start line: 1108
	/* end block 2 */
	// End Line: 1109

void SOUL_IdleEntry(_Instance *instance)

{
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
                    /* WARNING: Subroutine does not return */
  instance->maxZVel = 0x11;
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Idle(struct _Instance *instance /*$s0*/)
 // line 524, offset 0x8008e340
	/* begin block 1 */
		// Start line: 525
		// Start offset: 0x8008E340
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long xAccl; // $a1
	// 		long yAccl; // $a0
	/* end block 1 */
	// End offset: 0x8008E424
	// End Line: 560

	/* begin block 2 */
		// Start line: 1125
	/* end block 2 */
	// End Line: 1126

void SOUL_Idle(_Instance *instance)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar4;
  
  iVar1 = instance->xVel;
  puVar4 = (uint *)instance->extraData;
  iVar3 = 3;
  if ((-4 < iVar1) && (iVar3 = -3, iVar1 < 4)) {
    iVar3 = -iVar1;
  }
  iVar2 = instance->yVel;
  iVar1 = 3;
  if ((-4 < iVar2) && (iVar1 = -3, iVar2 < 4)) {
    iVar1 = -iVar2;
  }
  instance->xAccl = iVar3;
  instance->yAccl = iVar1;
  instance->zAccl = 0;
  SOUL_Physics(instance,gameTrackerX.timeMult);
  if ((*puVar4 & 4) == 0) {
    if (puVar4[0x31] != 0) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  SOUL_QueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_ReanimateEntry(struct _Instance *instance /*$s1*/)
 // line 566, offset 0x8008e440
	/* begin block 1 */
		// Start line: 567
		// Start offset: 0x8008E440
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _Instance *body; // $v0
	/* end block 1 */
	// End offset: 0x8008E440
	// End Line: 567

	/* begin block 2 */
		// Start line: 1212
	/* end block 2 */
	// End Line: 1213

void SOUL_ReanimateEntry(_Instance *instance)

{
  _Instance *p_Var1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  p_Var1 = INSTANCE_Find(*(long *)((int)pvVar2 + 0xd8));
  *(short *)((int)pvVar2 + 0x120) = (p_Var1->position).x;
  *(short *)((int)pvVar2 + 0x122) = (p_Var1->position).y;
                    /* WARNING: Subroutine does not return */
  *(short *)((int)pvVar2 + 0x124) = (p_Var1->position).z + 0xa0;
  MON_TurnOffBodySpheres(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Reanimate(struct _Instance *instance /*$s1*/)
 // line 583, offset 0x8008e4a8
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x8008E4A8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 596
			// Start offset: 0x8008E504
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E52C
		// End Line: 600
	/* end block 1 */
	// End offset: 0x8008E54C
	// End Line: 608

	/* begin block 2 */
		// Start line: 1248
	/* end block 2 */
	// End Line: 1249

void SOUL_Reanimate(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  SOUL_MoveToDest(instance,0x10,gameTrackerX.timeMult);
                    /* WARNING: Subroutine does not return */
  MATH3D_LengthXY((int)(instance->position).x - (int)*(short *)((int)pvVar1 + 0x120),
                  (int)(instance->position).y - (int)*(short *)((int)pvVar1 + 0x122));
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Effect(struct _Instance *instance /*$a0*/, struct evFXHitData *data /*$a1*/)
 // line 613, offset 0x8008e560
	/* begin block 1 */
		// Start line: 1312
	/* end block 1 */
	// End Line: 1313

	/* begin block 2 */
		// Start line: 1314
	/* end block 2 */
	// End Line: 1315

void SOUL_Effect(_Instance *instance,evFXHitData *data)

{
  return;
}





