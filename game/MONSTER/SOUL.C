#include "THISDUST.H"
#include "SOUL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_QueueHandler(struct _Instance *instance /*$s0*/)
 // line 80, offset 0x8008d6d4
	/* begin block 1 */
		// Start line: 81
		// Start offset: 0x8008D6D4
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct __Event *message; // $a1
	/* end block 1 */
	// End offset: 0x8008D754
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
 // line 100, offset 0x8008d770
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x8008D770
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int a; // $a1
	/* end block 1 */
	// End offset: 0x8008D79C
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
  if ((*(ushort *)((int)pvVar1 + 0x110) & 0x1f) < 0x10) {
    iVar2 = 4;
  }
  instance->zAccl = instance->zAccl + iVar2;
  *(short *)((int)pvVar1 + 0x110) = *(short *)((int)pvVar1 + 0x110) + 1;
  PhysicsMove(instance,&instance->position,time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Fade(struct _Instance *instance /*$s0*/)
 // line 120, offset 0x8008d7d0
	/* begin block 1 */
		// Start line: 121
		// Start offset: 0x8008D7D0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		unsigned long time; // $a0
	/* end block 1 */
	// End offset: 0x8008D870
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
 // line 147, offset 0x8008d884
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x8008D884
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	/* end block 1 */
	// End offset: 0x8008D958
	// End Line: 158

	/* begin block 2 */
		// Start line: 305
	/* end block 2 */
	// End Line: 306

void SOUL_MoveToDest(_Instance *instance,long maxAccel,long time)

{
  _Instance *instance_00;
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  instance->xAccl =
       ((int)*(short *)((int)pvVar1 + 0x112) - (int)(instance->position).x) - instance->xVel;
  instance->yAccl =
       ((int)*(short *)((int)pvVar1 + 0x114) - (int)(instance->position).y) - instance->yVel;
  instance->zAccl =
       ((int)*(short *)((int)pvVar1 + 0x116) - (int)(instance->position).z) - instance->zVel;
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
  instance_00 = (_Instance *)instance->zAccl;
  if ((int)instance_00 < -maxAccel) {
    instance->zAccl = -maxAccel;
    SOUL_SoulSuckEntry(instance_00);
    return;
  }
  if (maxAccel < (int)instance_00) {
    instance->zAccl = maxAccel;
  }
  SOUL_Physics(instance,time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_MovePastWall(struct _Instance *instance /*$s2*/, struct _Instance *sucker /*$a1*/)
 // line 162, offset 0x8008d974
	/* begin block 1 */
		// Start line: 163
		// Start offset: 0x8008D974
		// Variables:
	// 		struct _PCollideInfo pcollideInfo; // stack offset -88
	// 		struct _Position newPos; // stack offset -40
	// 		struct _Position oldPos; // stack offset -32
	// 		struct _Position delta; // stack offset -24
	// 		struct MATRIX *to; // $a0
	// 		struct MATRIX *from; // $v1
	// 		long tmp; // $v0

		/* begin block 1.1 */
			// Start line: 163
			// Start offset: 0x8008D974
			// Variables:
		// 		short _y0; // $v0
		// 		short _z0; // $a0
		// 		short _y1; // $a1
		// 		short _z1; // $a2
		// 		struct _Position *_v; // $s0
		// 		struct _Position *_v0; // $s1
		// 		struct _Position *_v1; // $t0
		/* end block 1.1 */
		// End offset: 0x8008D974
		// End Line: 163

		/* begin block 1.2 */
			// Start line: 188
			// Start offset: 0x8008DA58
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a2
		// 		short _x1; // $a3
		// 		short _y1; // $t1
		// 		short _z1; // $t0
		// 		struct _Position *_v1; // $t0
		/* end block 1.2 */
		// End offset: 0x8008DA58
		// End Line: 188
	/* end block 1 */
	// End offset: 0x8008DACC
	// End Line: 201

	/* begin block 2 */
		// Start line: 336
	/* end block 2 */
	// End Line: 337

void SOUL_MovePastWall(_Instance *instance,_Instance *sucker)

{
  MATRIX *pMVar1;
  MATRIX *pMVar2;
  _PCollideInfo _Stack88;
  SVECTOR local_28;
  SVECTOR local_20;
  SVECTOR local_18;
  
  pMVar1 = sucker->matrix;
  pMVar2 = instance->matrix;
  local_20.vx = *(ushort *)pMVar1[2].t;
  local_20.vy = *(short *)(pMVar1[2].t + 1);
  local_20.vz = *(short *)(pMVar1[2].t + 2);
  local_28.vx = *(ushort *)pMVar2[2].t;
  _Stack88.newPoint = &local_28;
  local_28.vy = *(short *)(pMVar2[2].t + 1);
  _Stack88.oldPoint = &local_20;
  local_28.vz = *(short *)(pMVar2[2].t + 2);
  local_18.vx = (short)((uint)local_28.vx - (uint)local_20.vx);
  local_18.vy = local_28.vy - local_20.vy;
  local_18.vz = local_28.vz - local_20.vz;
  if (100 < ((int)(((uint)local_28.vx - (uint)local_20.vx) * 0x10000) >> 0x10) * instance->xVel +
            (int)local_18.vy * instance->yVel + (int)local_18.vz * instance->zVel) {
    PHYSICS_CheckLineInWorld(instance,&_Stack88);
    local_18.vx = local_28.vx - (instance->position).x;
    local_18.vy = local_28.vy - (instance->position).y;
    local_18.vz = local_28.vz - (instance->position).z;
                    /* WARNING: Subroutine does not return */
    COLLIDE_UpdateAllTransforms(instance,&local_18);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Init(struct _Instance *instance /*$s0*/)
 // line 206, offset 0x8008dae4
	/* begin block 1 */
		// Start line: 207
		// Start offset: 0x8008DAE4
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008DB94
	// End Line: 230

	/* begin block 2 */
		// Start line: 447
	/* end block 2 */
	// End Line: 448

void SOUL_Init(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_DefaultInit(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_CleanUp(struct _Instance *instance /*$a0*/)
 // line 236, offset 0x8008dba8
	/* begin block 1 */
		// Start line: 518
	/* end block 1 */
	// End Line: 519

void SOUL_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_BirthEntry(struct _Instance *instance /*$a0*/)
 // line 246, offset 0x8008dbc8
	/* begin block 1 */
		// Start line: 247
		// Start offset: 0x8008DBC8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008DBC8
	// End Line: 247

	/* begin block 2 */
		// Start line: 538
	/* end block 2 */
	// End Line: 539

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
 // line 257, offset 0x8008dc1c
	/* begin block 1 */
		// Start line: 258
		// Start offset: 0x8008DC1C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008DC68
	// End Line: 269

	/* begin block 2 */
		// Start line: 564
	/* end block 2 */
	// End Line: 565

void SOUL_Birth(_Instance *instance)

{
  instance->zAccl = 0;
  SOUL_Physics(instance,theCamera.tiltList[0][0]);
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_SoulSuckEntry(struct _Instance *instance /*$a0*/)
 // line 275, offset 0x8008dc84
	/* begin block 1 */
		// Start line: 603
	/* end block 1 */
	// End Line: 604

	/* begin block 2 */
		// Start line: 606
	/* end block 2 */
	// End Line: 607

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
 // line 283, offset 0x8008dcac
	/* begin block 1 */
		// Start line: 285
		// Start offset: 0x8008DCAC
		// Variables:
	// 		long rv; // $a2
	/* end block 1 */
	// End offset: 0x8008DCE4
	// End Line: 310

	/* begin block 2 */
		// Start line: 616
	/* end block 2 */
	// End Line: 617

	/* begin block 3 */
		// Start line: 621
	/* end block 3 */
	// End Line: 622

	/* begin block 4 */
		// Start line: 622
	/* end block 4 */
	// End Line: 623

	/* begin block 5 */
		// Start line: 628
	/* end block 5 */
	// End Line: 629

long SOUL_CalcAccel(long delta,long vel,long magnitude)

{
  int iVar1;
  
  if (delta < 1) {
    if (0 < vel) {
      iVar1 = delta << 4;
      goto LAB_8008dcdc;
    }
  }
  else {
    if (vel < 0) {
      iVar1 = delta << 4;
      goto LAB_8008dcdc;
    }
  }
  iVar1 = delta * 5;
LAB_8008dcdc:
  return iVar1 / magnitude;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_SoulSuck(struct _Instance *instance /*$s2*/)
 // line 313, offset 0x8008dcec
	/* begin block 1 */
		// Start line: 314
		// Start offset: 0x8008DCEC
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct __Event *message; // $s0
	// 		struct _Instance *sucker; // $s4
	// 		struct _Instance *collidedWith; // $s6
	// 		int collisionCnt; // $s5

		/* begin block 1.1 */
			// Start line: 330
			// Start offset: 0x8008DD98
			// Variables:
		// 		long distance; // $s1
		// 		struct evMonsterSoulSuckData *suckData; // $s0

			/* begin block 1.1.1 */
				// Start line: 357
				// Start offset: 0x8008DEBC
				// Variables:
			// 		struct _SVector dir; // stack offset -48

				/* begin block 1.1.1.1 */
					// Start line: 368
					// Start offset: 0x8008DEF0
					// Variables:
				// 		long animLen; // $s0
				// 		long curTim; // $v0

					/* begin block 1.1.1.1.1 */
						// Start line: 379
						// Start offset: 0x8008DF88
						// Variables:
					// 		short _x0; // $a3
					// 		short _y0; // $a0
					// 		short _z0; // $v1
					// 		short _x1; // $v0
					// 		short _y1; // $a2
					// 		short _z1; // $a1
					// 		struct _SVector *_v; // $s7
					// 		struct _Position *_v0; // $v1
					// 		struct _Position *_v1; // $a1
					/* end block 1.1.1.1.1 */
					// End offset: 0x8008DF88
					// End Line: 379
				/* end block 1.1.1.1 */
				// End offset: 0x8008E03C
				// End Line: 389
			/* end block 1.1.1 */
			// End offset: 0x8008E03C
			// End Line: 389
		/* end block 1.1 */
		// End offset: 0x8008E074
		// End Line: 398

		/* begin block 1.2 */
			// Start line: 452
			// Start offset: 0x8008E1E8
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.2 */
		// End offset: 0x8008E208
		// End Line: 456
	/* end block 1 */
	// End offset: 0x8008E264
	// End Line: 469

	/* begin block 2 */
		// Start line: 681
	/* end block 2 */
	// End Line: 682

void SOUL_SoulSuck(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)instance->extraData + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_WanderEntry(struct _Instance *instance /*$a0*/)
 // line 474, offset 0x8008e294
	/* begin block 1 */
		// Start line: 475
		// Start offset: 0x8008E294
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	/* end block 1 */
	// End offset: 0x8008E2F4
	// End Line: 487

	/* begin block 2 */
		// Start line: 1046
	/* end block 2 */
	// End Line: 1047

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
      r = *(short *)(puVar1 + 0x48);
      in = &instance->position;
    }
    else {
      r = *(short *)(puVar1 + 0x48);
    }
    MON_GetRandomDestinationInWorld(instance,in,r);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Wander(struct _Instance *instance /*$s0*/)
 // line 489, offset 0x8008e304
	/* begin block 1 */
		// Start line: 490
		// Start offset: 0x8008E304
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 502
			// Start offset: 0x8008E370
		/* end block 1.1 */
		// End offset: 0x8008E420
		// End Line: 515
	/* end block 1 */
	// End offset: 0x8008E478
	// End Line: 530

	/* begin block 2 */
		// Start line: 1076
	/* end block 2 */
	// End Line: 1077

void SOUL_Wander(_Instance *instance)

{
  long lVar1;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x40000) == 0) {
    if (instance->intro == (Intro *)0x0) {
      MON_GetRandomDestinationInWorld(instance,&instance->position,*(short *)(puVar2 + 0x48));
      instance->zAccl = 0;
    }
    else {
      MON_GetRandomDestinationInWorld(instance,&instance->intro->position,*(short *)(puVar2 + 0x48))
      ;
      instance->zAccl = 0;
    }
  }
  else {
    lVar1 = MATH3D_LengthXY((int)*(short *)((int)puVar2 + 0x112) - (int)(instance->position).x,
                            (int)*(short *)(puVar2 + 0x45) - (int)(instance->position).y);
    if (lVar1 < 100) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
    instance->xAccl =
         ((int)*(short *)((int)puVar2 + 0x112) - (int)(instance->position).x) - instance->xVel;
    instance->yAccl =
         ((int)*(short *)(puVar2 + 0x45) - (int)(instance->position).y) - instance->yVel;
    lVar1 = -2;
    if ((instance->xAccl < -2) || (lVar1 = 2, 2 < instance->xAccl)) {
      instance->xAccl = lVar1;
    }
    lVar1 = -2;
    if ((instance->yAccl < -2) || (lVar1 = 2, 2 < instance->yAccl)) {
      instance->yAccl = lVar1;
    }
    instance->zAccl = 0;
  }
  SOUL_Physics(instance,theCamera.tiltList[0][0]);
  if ((*puVar2 & 4) == 0) {
    if ((instance->flags2 & 0x8000000U) == 0) {
      SOUL_Fade(instance);
    }
    if (puVar2[0x31] != 0) {
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
 // line 536, offset 0x8008e494
	/* begin block 1 */
		// Start line: 1171
	/* end block 1 */
	// End Line: 1172

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
 // line 543, offset 0x8008e4c4
	/* begin block 1 */
		// Start line: 544
		// Start offset: 0x8008E4C4
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 553
			// Start offset: 0x8008E500
			// Variables:
		// 		struct _Instance *enemy; // $a0
		// 		int dx; // $s1
		// 		int dy; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E5E4
		// End Line: 568
	/* end block 1 */
	// End offset: 0x8008E614
	// End Line: 574

	/* begin block 2 */
		// Start line: 1186
	/* end block 2 */
	// End Line: 1187

void SOUL_Flee(_Instance *instance)

{
  short angle;
  int iVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  iVar1 = *(int *)((int)instance->extraData + 0xc4);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  angle = MATH3D_AngleFromPosToPos((_Position *)(*(int *)(iVar1 + 4) + 0x5c),&instance->position);
  angle = MONSENSE_GetClosestFreeDirection(instance,angle,500);
                    /* WARNING: Subroutine does not return */
  rsin((int)angle);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_IdleEntry(struct _Instance *instance /*$a0*/)
 // line 579, offset 0x8008e628
	/* begin block 1 */
		// Start line: 580
		// Start offset: 0x8008E628
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008E628
	// End Line: 580

	/* begin block 2 */
		// Start line: 1261
	/* end block 2 */
	// End Line: 1262

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
 // line 587, offset 0x8008e6cc
	/* begin block 1 */
		// Start line: 588
		// Start offset: 0x8008E6CC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long xAccl; // $a1
	// 		long yAccl; // $a0
	/* end block 1 */
	// End offset: 0x8008E7B0
	// End Line: 623

	/* begin block 2 */
		// Start line: 1278
	/* end block 2 */
	// End Line: 1279

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
  SOUL_Physics(instance,theCamera.tiltList[0][0]);
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
 // line 629, offset 0x8008e7cc
	/* begin block 1 */
		// Start line: 630
		// Start offset: 0x8008E7CC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _Instance *body; // $v0
	/* end block 1 */
	// End offset: 0x8008E7CC
	// End Line: 630

	/* begin block 2 */
		// Start line: 1365
	/* end block 2 */
	// End Line: 1366

void SOUL_ReanimateEntry(_Instance *instance)

{
  _Instance *p_Var1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  p_Var1 = INSTANCE_Find(*(long *)((int)pvVar2 + 0xd8));
  *(short *)((int)pvVar2 + 0x112) = (p_Var1->position).x;
  *(short *)((int)pvVar2 + 0x114) = (p_Var1->position).y;
  *(short *)((int)pvVar2 + 0x116) = (p_Var1->position).z + 0xa0;
  MON_TurnOffBodySpheres(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Reanimate(struct _Instance *instance /*$s1*/)
 // line 646, offset 0x8008e834
	/* begin block 1 */
		// Start line: 647
		// Start offset: 0x8008E834
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 659
			// Start offset: 0x8008E890
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E8B8
		// End Line: 663
	/* end block 1 */
	// End offset: 0x8008E8D8
	// End Line: 671

	/* begin block 2 */
		// Start line: 1401
	/* end block 2 */
	// End Line: 1402

void SOUL_Reanimate(_Instance *instance)

{
  long lVar1;
  _Instance *Inst;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  SOUL_MoveToDest(instance,0x10,theCamera.tiltList[0][0]);
  lVar1 = MATH3D_LengthXY((int)(instance->position).x - (int)*(short *)((int)pvVar2 + 0x112),
                          (int)(instance->position).y - (int)*(short *)((int)pvVar2 + 0x114));
  if (0xf9 < lVar1) {
                    /* WARNING: Subroutine does not return */
    DeMessageQueue((__MessageQueue *)((int)pvVar2 + 8));
  }
  if (*(int *)((int)pvVar2 + 0xd8) != 0) {
    Inst = INSTANCE_Find(*(int *)((int)pvVar2 + 0xd8));
    if (Inst != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Post(Inst,0x100000d,0);
    }
    SAVE_DeleteInstance(instance);
  }
  MON_KillMonster(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Effect(struct _Instance *instance /*$a0*/, struct evFXHitData *data /*$a1*/)
 // line 676, offset 0x8008e8ec
	/* begin block 1 */
		// Start line: 1465
	/* end block 1 */
	// End Line: 1466

	/* begin block 2 */
		// Start line: 1467
	/* end block 2 */
	// End Line: 1468

void SOUL_Effect(_Instance *instance,evFXHitData *data)

{
  return;
}





