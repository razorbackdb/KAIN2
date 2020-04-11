#include "THISDUST.H"
#include "PHYSOBS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_PlayDropSound(struct _Instance *instance /*$a0*/)
 // line 200, offset 0x80068d0c
	/* begin block 1 */
		// Start line: 201
		// Start offset: 0x80068D0C
		// Variables:
	// 		struct PhysObProperties *Prop; // $a1
	// 		int sound; // $v1
	/* end block 1 */
	// End offset: 0x80068E18
	// End Line: 239

	/* begin block 2 */
		// Start line: 400
	/* end block 2 */
	// End Line: 401

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_PlayDropSound(_Instance *instance)

{
  short sVar1;
  int sfxToneID;
  void *pvVar2;
  int pitch;
  int maxVolume;
  undefined *local_18;
  
  pvVar2 = instance->data;
  sVar1 = *(short *)((int)pvVar2 + 2);
  if (sVar1 == 1) {
    sfxToneID = (int)*(short *)((int)pvVar2 + 10);
  }
  else {
    if (sVar1 == 0) {
      sfxToneID = (int)*(char *)((int)pvVar2 + 0x13);
    }
    else {
      sfxToneID = 0;
      if ((sVar1 == 3) && (*(int *)((int)pvVar2 + 0x28) != 0)) {
        sfxToneID = (int)*(char *)(*(int *)((int)pvVar2 + 0x28) + 0xb);
      }
    }
  }
  if (sfxToneID == 2) {
    SOUND_Play3dSound(&instance->position,0x11a,-400,0x5a,(int)&DAT_000036b0);
    sfxToneID = 0x11a;
    pitch = -800;
    maxVolume = 100;
    local_18 = &DAT_000036b0;
  }
  else {
    if (sfxToneID < 3) {
      if (sfxToneID != 1) {
        return;
      }
      sfxToneID = 10;
      pitch = -100;
    }
    else {
      if (sfxToneID != 3) {
        return;
      }
      sfxToneID = 0xb2;
      pitch = -800;
    }
    local_18 = &DAT_00007530;
    maxVolume = 0x78;
  }
  SOUND_Play3dSound(&instance->position,sfxToneID,pitch,maxVolume,(int)local_18);
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ PHYSOBS_IsAPushBlockAttached(struct _Instance *block /*$s3*/)
 // line 251, offset 0x80068e2c
	/* begin block 1 */
		// Start line: 252
		// Start offset: 0x80068E2C
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	// 		struct _Instance *result; // $s2
	/* end block 1 */
	// End offset: 0x80068E94
	// End Line: 272

	/* begin block 2 */
		// Start line: 502
	/* end block 2 */
	// End Line: 503

	/* begin block 3 */
		// Start line: 503
	/* end block 3 */
	// End Line: 504

/* File: C:\kain2\game\PHYSOBS.C */

_Instance * PHYSOBS_IsAPushBlockAttached(_Instance *block)

{
  _Instance *instance;
  int iVar1;
  _Instance *p_Var2;
  
  p_Var2 = *(_Instance **)(DAT_800d2100 + 4);
  do {
    instance = p_Var2;
    if (instance == (_Instance *)0x0) {
      return (_Instance *)0x0;
    }
    p_Var2 = instance->next;
  } while ((instance->attachedID != block->introUniqueID) ||
          (iVar1 = CheckPhysObAbility(instance,2), iVar1 == 0));
  return instance;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ PHYSOBS_IsAnythingAttached(struct _Instance *block /*$a0*/)
 // line 276, offset 0x80068eb4
	/* begin block 1 */
		// Start line: 278
		// Start offset: 0x80068EB4
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $a1
	// 		struct _Instance *result; // $a2
	/* end block 1 */
	// End offset: 0x80068EF4
	// End Line: 295

	/* begin block 2 */
		// Start line: 556
	/* end block 2 */
	// End Line: 557

	/* begin block 3 */
		// Start line: 557
	/* end block 3 */
	// End Line: 558

/* File: C:\kain2\game\PHYSOBS.C */

_Instance * PHYSOBS_IsAnythingAttached(_Instance *block)

{
  _Instance **pp_Var1;
  _Instance *p_Var2;
  
  if (*(_Instance **)(DAT_800d2100 + 4) != (_Instance *)0x0) {
    p_Var2 = *(_Instance **)(DAT_800d2100 + 4);
    do {
      pp_Var1 = &p_Var2->next;
      if (p_Var2->attachedID == block->introUniqueID) {
        return p_Var2;
      }
      p_Var2 = *pp_Var1;
    } while (*pp_Var1 != (_Instance *)0x0);
  }
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckPhysOb(struct _Instance *instance /*$a0*/)
 // line 299, offset 0x80068efc
	/* begin block 1 */
		// Start line: 301
		// Start offset: 0x80068EFC
		// Variables:
	// 		struct PhysObProperties *Prop; // $v0
	/* end block 1 */
	// End offset: 0x80068F20
	// End Line: 311

	/* begin block 2 */
		// Start line: 605
	/* end block 2 */
	// End Line: 606

	/* begin block 3 */
		// Start line: 606
	/* end block 3 */
	// End Line: 607

	/* begin block 4 */
		// Start line: 610
	/* end block 4 */
	// End Line: 611

/* File: C:\kain2\game\PHYSOBS.C */

int CheckPhysOb(_Instance *instance)

{
  if (instance->data == (void *)0x0) {
    return 0;
  }
  return (uint)(*(short *)((int)instance->data + 4) == -0x4ff5);
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckPhysObAbility(struct _Instance *instance /*$a0*/, unsigned short ability /*$a3*/)
 // line 314, offset 0x80068f28
	/* begin block 1 */
		// Start line: 315
		// Start offset: 0x80068F28
		// Variables:
	// 		struct PhysObProperties *Prop; // $a2

		/* begin block 1.1 */
			// Start line: 327
			// Start offset: 0x80068F60
		/* end block 1.1 */
		// End offset: 0x80068F84
		// End Line: 331
	/* end block 1 */
	// End offset: 0x80068F9C
	// End Line: 337

	/* begin block 2 */
		// Start line: 637
	/* end block 2 */
	// End Line: 638

	/* begin block 3 */
		// Start line: 642
	/* end block 3 */
	// End Line: 643

/* File: C:\kain2\game\PHYSOBS.C */

int CheckPhysObAbility(_Instance *instance,ushort ability)

{
  void *pvVar1;
  
  pvVar1 = instance->data;
  if (pvVar1 != (void *)0x0) {
    if (*(short *)((int)pvVar1 + 4) != -0x4ff5) {
      return 0;
    }
    if (*(short *)((int)pvVar1 + 2) == 3) {
      if ((*(ushort *)((int)instance->extraData + 4) & ability) == 0) {
        return 0;
      }
      return 1;
    }
    if ((*(ushort *)((int)pvVar1 + 6) & ability) != 0) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckPhysObFamily(struct _Instance *instance /*$a0*/, unsigned short family /*$a1*/)
 // line 340, offset 0x80068fa4
	/* begin block 1 */
		// Start line: 342
		// Start offset: 0x80068FA4
		// Variables:
	// 		struct PhysObProperties *Prop; // $a0
	/* end block 1 */
	// End offset: 0x80068FE0
	// End Line: 357

	/* begin block 2 */
		// Start line: 694
	/* end block 2 */
	// End Line: 695

	/* begin block 3 */
		// Start line: 695
	/* end block 3 */
	// End Line: 696

	/* begin block 4 */
		// Start line: 699
	/* end block 4 */
	// End Line: 700

/* File: C:\kain2\game\PHYSOBS.C */

int CheckPhysObFamily(_Instance *instance,ushort family)

{
  void *pvVar1;
  
  pvVar1 = instance->data;
  if (pvVar1 != (void *)0x0) {
    if (*(short *)((int)pvVar1 + 4) != -0x4ff5) {
      return 0;
    }
    if (*(ushort *)((int)pvVar1 + 2) == family) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetPhysicalAbility(struct _Instance *instance /*$a0*/)
 // line 394, offset 0x80068fe8
	/* begin block 1 */
		// Start line: 396
		// Start offset: 0x80068FE8
		// Variables:
	// 		struct PhysObProperties *Prop; // $a1

		/* begin block 1.1 */
			// Start line: 405
			// Start offset: 0x80069018
		/* end block 1.1 */
		// End offset: 0x8006902C
		// End Line: 408
	/* end block 1 */
	// End offset: 0x80069038
	// End Line: 414

	/* begin block 2 */
		// Start line: 802
	/* end block 2 */
	// End Line: 803

	/* begin block 3 */
		// Start line: 803
	/* end block 3 */
	// End Line: 804

	/* begin block 4 */
		// Start line: 807
	/* end block 4 */
	// End Line: 808

/* File: C:\kain2\game\PHYSOBS.C */

int GetPhysicalAbility(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->data;
  if ((pvVar1 != (void *)0x0) && (*(short *)((int)pvVar1 + 4) == -0x4ff5)) {
    if (*(short *)((int)pvVar1 + 2) == 3) {
      return (int)*(short *)((int)instance->extraData + 4);
    }
    return (uint)*(ushort *)((int)pvVar1 + 6);
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ AnyBlocksInMotion()
 // line 418, offset 0x80069040
	/* begin block 1 */
		// Start line: 420
		// Start offset: 0x80069040
		// Variables:
	// 		struct _Instance *instance; // $a0

		/* begin block 1.1 */
			// Start line: 426
			// Start offset: 0x80069078
			// Variables:
		// 		struct PhysObProperties *Prop; // $v1
		// 		struct PhysObData *Data; // $v0
		/* end block 1.1 */
		// End offset: 0x800690C0
		// End Line: 437
	/* end block 1 */
	// End offset: 0x800690D0
	// End Line: 442

	/* begin block 2 */
		// Start line: 850
	/* end block 2 */
	// End Line: 851

	/* begin block 3 */
		// Start line: 851
	/* end block 3 */
	// End Line: 852

/* File: C:\kain2\game\PHYSOBS.C */

int AnyBlocksInMotion(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_800d2100 + 4);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (((((*(uint *)(*(int *)(iVar1 + 0x1c) + 0x2c) & 0x40000) != 0) &&
         ((*(ushort *)(*(int *)(iVar1 + 0x24) + 6) & 8) != 0)) &&
        (*(short *)(*(int *)(iVar1 + 0x24) + 4) == -0x4ff5)) &&
       ((**(uint **)(iVar1 + 0x168) & 0x14e) != 0)) break;
    iVar1 = *(int *)(iVar1 + 8);
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ThrowPhysOb(struct _Instance *instance /*$s2*/, struct evObjectThrowData *throwData /*$s1*/)
 // line 446, offset 0x800690e0
	/* begin block 1 */
		// Start line: 447
		// Start offset: 0x800690E0
		// Variables:
	// 		struct PhysObData *Data; // $s3
	// 		int collFlg; // $s5

		/* begin block 1.1 */
			// Start line: 455
			// Start offset: 0x80069118
			// Variables:
		// 		struct _Instance *parent; // $s4
		// 		struct PhysObProperties *Prop; // $s0

			/* begin block 1.1.1 */
				// Start line: 481
				// Start offset: 0x800691BC
				// Variables:
			// 		struct __PhysObProjectileData *ProjData; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80069210
			// End Line: 493

			/* begin block 1.1.2 */
				// Start line: 512
				// Start offset: 0x80069284
				// Variables:
			// 		long val; // $a1
			// 		struct _Instance *itarget; // $s0
			// 		struct MATRIX *matrix; // $t0
			/* end block 1.1.2 */
			// End offset: 0x80069354
			// End Line: 538

			/* begin block 1.1.3 */
				// Start line: 546
				// Start offset: 0x800693AC
				// Variables:
			// 		long val; // $a1
			// 		struct _Position *ptarget; // $s0
			/* end block 1.1.3 */
			// End offset: 0x80069464
			// End Line: 570

			/* begin block 1.1.4 */
				// Start line: 607
				// Start offset: 0x80069570
				// Variables:
			// 		struct _SVector *sv; // $v1
			/* end block 1.1.4 */
			// End offset: 0x8006959C
			// End Line: 613

			/* begin block 1.1.5 */
				// Start line: 628
				// Start offset: 0x800695C8
				// Variables:
			// 		struct _PCollideInfo pcollideInfo; // stack offset -96
			// 		struct _Position newPos; // stack offset -48
			// 		struct _Position oldPos; // stack offset -40
			// 		struct MATRIX *mat; // $v0

				/* begin block 1.1.5.1 */
					// Start line: 653
					// Start offset: 0x80069660
					// Variables:
				// 		short _x0; // $a2
				// 		short _y0; // $a3
				// 		short _z0; // $t0
				// 		short _x1; // $v0
				// 		short _y1; // $v1
				// 		short _z1; // $a0
				/* end block 1.1.5.1 */
				// End offset: 0x80069660
				// End Line: 653

				/* begin block 1.1.5.2 */
					// Start line: 653
					// Start offset: 0x80069660
					// Variables:
				// 		short _x0; // $v0
				// 		short _y0; // $v1
				// 		short _z0; // $a0
				// 		struct _Position *_v; // $a1
				/* end block 1.1.5.2 */
				// End offset: 0x80069660
				// End Line: 653
			/* end block 1.1.5 */
			// End offset: 0x80069660
			// End Line: 653
		/* end block 1.1 */
		// End offset: 0x80069708
		// End Line: 671
	/* end block 1 */
	// End offset: 0x80069708
	// End Line: 676

	/* begin block 2 */
		// Start line: 906
	/* end block 2 */
	// End Line: 907

/* File: C:\kain2\game\PHYSOBS.C */

void ThrowPhysOb(_Instance *instance,evObjectThrowData *throwData)

{
  short angle;
  int iVar1;
  ulong uVar2;
  MATRIX *pMVar3;
  _Instance *parent;
  int NewAnim;
  int iVar4;
  int iVar5;
  void *pvVar6;
  _Instance *Inst;
  uint *puVar7;
  int iVar8;
  _PCollideInfo local_60;
  SVECTOR local_30;
  SVECTOR local_28;
  
  parent = instance->LinkParent;
  if (parent == (_Instance *)0x0) {
    return;
  }
  pvVar6 = instance->data;
  instance->flags2 = instance->flags2 | 0x4000;
  INSTANCE_UnlinkFromParent(instance);
  iVar1 = PHYSOB_CheckThrownLineCollision(instance,parent);
  instance->flags2 = instance->flags2 | 0x80;
  if (throwData == (evObjectThrowData *)0x0) {
    throwData = (evObjectThrowData *)
                SetObjectThrowData((void *)0x0,(_SVector *)0x0,0,0,0x180,0,0x40,-0x400);
  }
  puVar7 = (uint *)instance->extraData;
  puVar7[2] = 0;
  *puVar7 = *puVar7 & 0xffffff7e | 0x1010;
  angle = throwData->initialXRot;
  *(_Instance **)(puVar7 + 0x10) = parent;
  *(short *)(puVar7 + 0xe) = angle;
  if ((*(short *)((int)pvVar6 + 2) == 7) &&
     (NewAnim = (int)*(char *)(*(int *)((int)pvVar6 + 0xc) +
                               *(int *)((int)instance->extraData + 4) * 0xc + 2), NewAnim != -1)) {
    G2EmulationInstanceSetAnimation(instance,0,NewAnim,0,0);
    G2EmulationInstanceSetMode(instance,0,2);
  }
  instance->zAccl = (int)throwData->gravity;
  switch(throwData->type) {
  case 0:
    if (parent->LinkParent == (_Instance *)0x0) {
      angle = (parent->rotation).z;
    }
    else {
      angle = (parent->LinkParent->rotation).z;
    }
    PhysicsSetVelFromZRot(instance,angle,(uint)throwData->speed);
    instance->zVel = (int)throwData->zVel;
    break;
  case 1:
    Inst = *(_Instance **)&throwData->data;
    *(_Instance **)(puVar7 + 2) = Inst;
    angle = MATH3D_AngleFromPosToPos(&instance->position,&Inst->position);
    PhysicsSetVelFromZRot(instance,angle,(uint)throwData->speed);
    instance->zVel = 0;
    uVar2 = INSTANCE_Query(Inst,0xc);
    iVar5 = instance->xVel;
    iVar4 = instance->yVel;
    NewAnim = iVar5;
    if (iVar5 < 0) {
      NewAnim = -iVar5;
    }
    iVar8 = iVar4;
    if (iVar4 < 0) {
      iVar8 = -iVar4;
    }
    if (iVar8 < NewAnim) {
      NewAnim = *(int *)(uVar2 + 0x14) - (int)(instance->position).x;
      if ((iVar5 == 0) || (NewAnim == 0)) break;
      iVar8 = (instance->zAccl * NewAnim) / iVar5;
      iVar5 = (*(int *)(uVar2 + 0x1c) - (int)(instance->position).z) * iVar5;
    }
    else {
      NewAnim = *(int *)(uVar2 + 0x18) - (int)(instance->position).y;
      if ((iVar4 == 0) || (NewAnim == 0)) break;
      iVar8 = (instance->zAccl * NewAnim) / iVar4;
      iVar5 = (*(int *)(uVar2 + 0x1c) - (int)(instance->position).z) * iVar4;
    }
    instance->zVel = iVar5 / NewAnim - (iVar8 >> 1);
    break;
  case 2:
    angle = MATH3D_AngleFromPosToPos(&instance->position,(_Position *)&throwData->data);
    PhysicsSetVelFromZRot(instance,angle,(uint)throwData->speed);
    iVar5 = instance->xVel;
    iVar4 = instance->yVel;
    NewAnim = iVar5;
    if (iVar5 < 0) {
      NewAnim = -iVar5;
    }
    iVar8 = iVar4;
    if (iVar4 < 0) {
      iVar8 = -iVar4;
    }
    instance->zVel = 0;
    if (iVar8 < NewAnim) {
      NewAnim = (int)*(short *)&throwData->data - (int)(instance->position).x;
      if ((iVar5 == 0) || (NewAnim == 0)) break;
      iVar8 = (instance->zAccl * NewAnim) / iVar5;
      iVar5 = ((int)*(short *)((int)&throwData->data + 4) - (int)(instance->position).z) * iVar5;
    }
    else {
      NewAnim = (int)*(short *)((int)&throwData->data + 2) - (int)(instance->position).y;
      if ((iVar4 == 0) || (NewAnim == 0)) break;
      iVar8 = (instance->zAccl * NewAnim) / iVar4;
      iVar5 = ((int)*(short *)((int)&throwData->data + 4) - (int)(instance->position).z) * iVar4;
    }
    instance->zVel = iVar5 / NewAnim - (iVar8 >> 1);
    break;
  case 3:
    PhysicsSetVelFromRot(instance,(_Rotation *)&throwData->data,(uint)throwData->speed);
    break;
  case 4:
    instance->xVel = (int)*(short *)&throwData->data;
    instance->yVel = (int)*(short *)((int)&throwData->data + 2);
    instance->zVel = (int)*(short *)((int)&throwData->data + 4);
    instance->zAccl = (int)throwData->gravity;
  }
  angle = throwData->spinType;
  if (angle == 1) {
    *(ushort *)((int)puVar7 + 0x36) = *(ushort *)((int)puVar7 + 0x36) | 1;
  }
  else {
    if (angle < 2) {
      if (angle == 0) {
        *(undefined2 *)((int)puVar7 + 0x3a) = 0;
        *(undefined2 *)(puVar7 + 0xf) = 0;
        *(undefined2 *)((int)puVar7 + 0x3e) = 0;
        *(ushort *)((int)puVar7 + 0x36) = *(ushort *)((int)puVar7 + 0x36) & 0xfffe;
      }
    }
    else {
      if (angle == 2) {
        *(short *)((int)puVar7 + 0x3a) = (throwData->angularVel).x;
        *(short *)(puVar7 + 0xf) = (throwData->angularVel).y;
        angle = (throwData->angularVel).z;
        *(ushort *)((int)puVar7 + 0x36) = *(ushort *)((int)puVar7 + 0x36) & 0xfffe;
        *(short *)((int)puVar7 + 0x3e) = angle;
      }
    }
  }
  if (iVar1 != 0) {
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
    NewAnim = CheckPhysObAbility(instance,0x200);
    if ((NewAnim == 0) || (iVar1 != 1)) {
      *puVar7 = *puVar7 & 0xffffefff;
    }
    else {
      *puVar7 = *puVar7 | 0x1000;
      instance->flags2 = instance->flags2 & 0xffffff7f;
      *puVar7 = *puVar7 & 0xffffffef;
      pMVar3 = instance->matrix;
      local_28.vx = *(short *)pMVar3[2].t;
      local_28.vy = *(short *)(pMVar3[2].t + 1);
      local_30.vz = *(short *)(pMVar3[2].t + 2);
      local_30.vx = (parent->position).x;
      local_60.newPoint = &local_30;
      local_30.vy = (parent->position).y;
      local_60.oldPoint = &local_28;
      local_28.vz = local_30.vz;
      PHYSICS_CheckLineInWorld(instance,&local_60);
      if (local_60.type == 3) {
        local_28.vx = local_30.vx - local_28.vx;
        local_28.vy = local_30.vy - local_28.vy;
        local_28.vz = local_30.vz - local_28.vz;
        (instance->position).x = (instance->position).x + local_28.vx;
        (instance->position).y = (instance->position).y + local_28.vy;
        (instance->position).z = (instance->position).z + local_28.vz;
      }
    }
  }
  if ((*puVar7 & 0x10) != 0) {
    if (iVar1 == 0) {
      PhysicsMove(instance,&instance->position,DAT_800d2314);
    }
    TurnOnCollisionPhysOb(instance,4);
  }
  puVar7[0x11] = 0x96000;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PushPhysOb(struct _Instance *instance /*$s1*/, short x /*stack -32*/, short y /*stack -30*/, short PathNumber /*$a3*/, struct _Instance *Force /*stack 16*/)
 // line 680, offset 0x8006972c
	/* begin block 1 */
		// Start line: 681
		// Start offset: 0x8006972C
		// Variables:
	// 		struct PhysObData *Data; // $s0
	// 		struct PhysObProperties *Prop; // $v1
	// 		int result; // $s2
	/* end block 1 */
	// End offset: 0x80069868
	// End Line: 731

	/* begin block 2 */
		// Start line: 1423
	/* end block 2 */
	// End Line: 1424

/* File: C:\kain2\game\PHYSOBS.C */

int PushPhysOb(_Instance *instance,short x,short y,short PathNumber,_Instance *Force)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  short local_20;
  short local_1e [3];
  
  uVar3 = 0;
  if (((*(ushort *)((int)instance->data + 6) & 8) != 0) &&
     (uVar3 = 0, *(short *)((int)instance->data + 4) == -0x4ff5)) {
    puVar2 = (uint *)instance->extraData;
    uVar3 = 0;
    if ((*puVar2 & 0x214a) == 0) {
      local_20 = x;
      local_1e[0] = y;
      iVar1 = AnyBlocksInMotion();
      uVar3 = 0;
      if (iVar1 == 0) {
        PHYSOB_NormalToAxis(&local_20,local_1e);
        *(_Instance **)(puVar2 + 2) = Force;
        *(short *)(puVar2 + 10) = PathNumber;
        *(short *)(puVar2 + 1) = local_20;
        *(short *)((int)puVar2 + 6) = local_1e[0];
        *puVar2 = *puVar2 & 0xfffffff7;
        instance->zVel = 0;
        instance->yVel = 0;
        instance->xVel = 0;
        instance->zAccl = 0;
        instance->yAccl = 0;
        instance->xAccl = 0;
        uVar3 = PHYSOBS_CheckForValidMove(instance);
        if ((uVar3 & 1) != 0) {
          if ((*puVar2 & 0x100) == 0) {
            *(short *)((int)puVar2 + 0xe) = (instance->position).x;
            *(short *)(puVar2 + 4) = (instance->position).y;
            *(short *)((int)puVar2 + 0x12) = (instance->position).z;
          }
          *puVar2 = *puVar2 | 0x1000;
          instance->flags2 = instance->flags2 | 8;
        }
      }
    }
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetSwitchPhysOb(struct _Instance *instance /*$s0*/)
 // line 735, offset 0x80069888
	/* begin block 1 */
		// Start line: 736
		// Start offset: 0x80069888
		// Variables:
	// 		struct PhysObData *Data; // $v1
	// 		struct PhysObSwitchProperties *Prop; // $a1
	/* end block 1 */
	// End offset: 0x80069910
	// End Line: 756

	/* begin block 2 */
		// Start line: 1569
	/* end block 2 */
	// End Line: 1570

/* File: C:\kain2\game\PHYSOBS.C */

void ResetSwitchPhysOb(_Instance *instance)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = CheckPhysObFamily(instance,2);
  if (iVar2 != 0) {
    pvVar3 = instance->data;
    *(uint *)instance->extraData = *(uint *)instance->extraData | 0x800;
    if (((*(ushort *)((int)instance->extraData + 0x14) & 2) != 0) &&
       (bVar1 = *(byte *)((int)pvVar3 + 0x10), bVar1 != 0)) {
      G2EmulationInstanceSetAnimation(instance,0,(uint)bVar1,0,0);
      G2EmulationInstanceSetMode(instance,0,1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SwitchPhysOb(struct _Instance *instance /*$s1*/)
 // line 760, offset 0x80069920
	/* begin block 1 */
		// Start line: 761
		// Start offset: 0x80069920
		// Variables:
	// 		struct PhysObData *Data; // $v0
	// 		struct PhysObSwitchProperties *Prop; // $s0
	// 		struct SwitchData *switchData; // $s3
	/* end block 1 */
	// End offset: 0x80069AE0
	// End Line: 821

	/* begin block 2 */
		// Start line: 1621
	/* end block 2 */
	// End Line: 1622

/* File: C:\kain2\game\PHYSOBS.C */

int SwitchPhysOb(_Instance *instance)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  void *pvVar6;
  
  pvVar5 = instance->data;
  iVar2 = CheckPhysObFamily(instance,2);
  iVar3 = 1;
  if (iVar2 != 0) {
    *(uint *)instance->extraData = *(uint *)instance->extraData | 0x800;
    pvVar6 = instance->extraData;
    uVar1 = *(ushort *)((int)pvVar6 + 0x14);
    if ((uVar1 & 1) == 0) {
      if ((uVar1 & 2) == 0) {
        if (*(byte *)((int)pvVar5 + 0xe) != 0xff) {
          G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar5 + 0xe),0,0);
        }
      }
      else {
        *(ushort *)((int)pvVar6 + 0x14) = uVar1 | 5;
        G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar5 + 0xc),0,0);
        if (*(short *)((int)pvVar5 + 10) == 7) {
          *(undefined2 *)((int)pvVar6 + 0x16) = 0x400;
        }
        else {
          *(undefined2 *)((int)pvVar6 + 0x16) = 0;
        }
        uVar4 = instance->flags;
        (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar6 + 0x16);
        instance->flags = uVar4 | 8;
      }
      G2EmulationInstanceSetMode(instance,0,1);
    }
    else {
      if ((uVar1 & 2) == 0) {
        if (*(byte *)((int)pvVar5 + 0xf) != 0xff) {
          G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar5 + 0xf),0,0);
          G2EmulationInstanceSetMode(instance,0,1);
          *(ushort *)((int)pvVar6 + 0x14) = *(ushort *)((int)pvVar6 + 0x14) | 2;
        }
      }
      else {
        *(ushort *)((int)pvVar6 + 0x14) = uVar1 & 0xfffe | 8;
        G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar5 + 0xd),0,0);
        G2EmulationInstanceSetMode(instance,0,1);
        (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar6 + 0x16);
        if (*(short *)((int)pvVar5 + 10) == 7) {
          *(undefined2 *)((int)pvVar6 + 0x16) = 0x400;
        }
        else {
          *(undefined2 *)((int)pvVar6 + 0x16) = 0;
        }
        instance->flags = instance->flags | 8;
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ InteractPhysOb(struct _Instance *instance /*$s1*/, struct _Instance *Force /*$s3*/, int LinkNode /*$s7*/, int Action /*$s4*/)
 // line 825, offset 0x80069afc
	/* begin block 1 */
		// Start line: 826
		// Start offset: 0x80069AFC
		// Variables:
	// 		struct PhysObData *Data; // $s5
	// 		struct PhysObInteractProperties *interactProp; // $s2

		/* begin block 1.1 */
			// Start line: 836
			// Start offset: 0x80069B48
			// Variables:
		// 		struct BreakOffData *BreakOff; // $s6

			/* begin block 1.1.1 */
				// Start line: 847
				// Start offset: 0x80069BBC
				// Variables:
			// 		struct _Instance *lightInst; // $s0
			/* end block 1.1.1 */
			// End offset: 0x80069BD4
			// End Line: 853

			/* begin block 1.1.2 */
				// Start line: 859
				// Start offset: 0x80069BFC
				// Variables:
			// 		struct _Instance *lightInst; // $s0
			/* end block 1.1.2 */
			// End offset: 0x80069C1C
			// End Line: 866

			/* begin block 1.1.3 */
				// Start line: 903
				// Start offset: 0x80069D3C
				// Variables:
			// 		int s; // $s0
			/* end block 1.1.3 */
			// End offset: 0x80069D8C
			// End Line: 908

			/* begin block 1.1.4 */
				// Start line: 908
				// Start offset: 0x80069D94
				// Variables:
			// 		int s; // $s0
			/* end block 1.1.4 */
			// End offset: 0x80069DE4
			// End Line: 914
		/* end block 1.1 */
		// End offset: 0x80069E20
		// End Line: 932
	/* end block 1 */
	// End offset: 0x80069E20
	// End Line: 934

	/* begin block 2 */
		// Start line: 1760
	/* end block 2 */
	// End Line: 1761

/* File: C:\kain2\game\PHYSOBS.C */

int InteractPhysOb(_Instance *instance,_Instance *Force,int LinkNode,int Action)

{
  int Mode;
  uint *puVar1;
  uint uVar2;
  _PhysObLight *pLight;
  byte bVar3;
  _Model **pp_Var4;
  _Instance *instance_00;
  void *pvVar5;
  
  pvVar5 = instance->data;
  Mode = CheckPhysObFamily(instance,3);
  if (Mode == 0) {
    return 1;
  }
  puVar1 = (uint *)instance->extraData;
  if (*(char *)((int)pvVar5 + 0x14) != -1) {
    if (Action == 2) {
      instance_00 = Force->LinkChild;
      pLight = PhysObGetLight(instance_00);
      PHYSOB_StartBurning(instance_00,pLight);
    }
    else {
      if (Action < 3) {
        if (Action == 1) {
          uVar2 = *puVar1;
          *puVar1 = uVar2 & 0xfffffffe | 0x1080;
          if ((uVar2 & 0x10000) != 0) {
            instance_00 = Force->LinkChild;
            pLight = PhysObGetLight(instance_00);
            PHYSOB_StartLighting(instance_00,pLight);
          }
          *(undefined2 *)(puVar1 + 1) = *(undefined2 *)((int)pvVar5 + 0x18);
          *(undefined2 *)((int)puVar1 + 6) = *(undefined2 *)((int)pvVar5 + 0x1a);
          INSTANCE_LinkToParent(instance,Force,LinkNode);
        }
      }
      else {
        if (Action == 9) {
          INSTANCE_Post(instance,0x40002,5);
        }
      }
    }
    if (Action == (uint)*(ushort *)((int)pvVar5 + 0xc)) {
      instance->flags = instance->flags | 8;
    }
    if (Action == (uint)*(ushort *)((int)pvVar5 + 0xe)) {
      instance->flags = instance->flags | 0x10;
    }
  }
  if ((*(byte *)((int)pvVar5 + 0x11) == 0xff) || ((*(ushort *)((int)pvVar5 + 6) & 0x8000) == 0))
  goto LAB_80069d10;
  G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar5 + 0x11),0,0);
  bVar3 = *(byte *)((int)pvVar5 + 0x15) & 0x30;
  if (bVar3 == 0x10) {
    Mode = 1;
LAB_80069d08:
    G2EmulationInstanceSetMode(instance,0,Mode);
  }
  else {
    if (bVar3 < 0x11) {
      if ((*(byte *)((int)pvVar5 + 0x15) & 0x30) == 0) {
        Mode = 2;
        goto LAB_80069d08;
      }
    }
    else {
      if (bVar3 == 0x20) {
        Mode = 0;
        goto LAB_80069d08;
      }
    }
  }
LAB_80069d10:
  pp_Var4 = instance->object->modelList;
  if (pp_Var4 != (_Model **)0x0) {
    if ((*(byte *)((int)pvVar5 + 0x15) & 0x80) == 0) {
      Mode = 0;
      if (0 < (*pp_Var4)->numSegments) {
        do {
          COLLIDE_SegmentCollisionOn(instance,Mode);
          Mode = Mode + 1;
        } while (Mode < (*instance->object->modelList)->numSegments);
      }
    }
    else {
      Mode = 0;
      if (0 < (*pp_Var4)->numSegments) {
        do {
          COLLIDE_SegmentCollisionOff(instance,Mode);
          Mode = Mode + 1;
        } while (Mode < (*instance->object->modelList)->numSegments);
        puVar1[2] = 0;
        goto LAB_80069de8;
      }
    }
  }
  puVar1[2] = 0;
LAB_80069de8:
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)(puVar1 + 1) = *(undefined2 *)((int)pvVar5 + 0x18);
  *(undefined2 *)((int)puVar1 + 6) = *(undefined2 *)((int)pvVar5 + 0x1a);
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetOrientation(struct _Instance *instance /*$s1*/)
 // line 934, offset 0x80069e4c
	/* begin block 1 */
		// Start line: 935
		// Start offset: 0x80069E4C
		// Variables:
	// 		struct _G2EulerAngles_Type ea; // stack offset -40
	// 		struct PhysObData *Data; // $a1
	// 		struct _G2SVector3_Type vec; // stack offset -32
	// 		struct _G2SVector3_Type vec2; // stack offset -24
	// 		int dp; // $a0
	// 		int fixxy; // $a2
	// 		int fixz; // $a3
	// 		int dx; // $v1
	// 		int dx2; // $v0
	// 		int dy; // $v0
	// 		int dy2; // $v1
	// 		int dz; // $v0
	// 		int dz2; // $v1

		/* begin block 1.1 */
			// Start line: 1064
			// Start offset: 0x8006A0DC
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a1
		// 		short _y1; // $a3
		// 		short _z1; // $a2
		// 		struct _G2SVector3_Type *_v; // $a1
		// 		struct _G2EulerAngles_Type *_v0; // $a0
		// 		struct _G2SVector3_Type *_v1; // $a2
		/* end block 1.1 */
		// End offset: 0x8006A0DC
		// End Line: 1064

		/* begin block 1.2 */
			// Start line: 1066
			// Start offset: 0x8006A220
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $v0
		// 		short _z0; // $a0
		// 		short _x1; // $t0
		// 		short _y1; // $a2
		// 		short _z1; // $a1
		// 		struct _G2SVector3_Type *_v; // $a3
		// 		struct _G2SVector3_Type *_v1; // $a1
		/* end block 1.2 */
		// End offset: 0x8006A220
		// End Line: 1066
	/* end block 1 */
	// End offset: 0x8006A320
	// End Line: 1090

	/* begin block 2 */
		// Start line: 1998
	/* end block 2 */
	// End Line: 1999

/* File: C:\kain2\game\PHYSOBS.C */

void ResetOrientation(_Instance *instance)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  _G2EulerAngles_Type local_28;
  _G2SVector3_Type local_20;
  ushort local_18;
  ushort local_16;
  ushort local_14;
  
  G2Anim_DisableController(&instance->anim,0,0x4c);
  pvVar5 = instance->extraData;
  iVar4 = (int)(instance->position).x - (int)*(short *)((int)pvVar5 + 0xe);
  if (iVar4 != 0) {
    if (iVar4 < 1) {
      iVar4 = iVar4 + -0x140;
    }
    else {
      iVar4 = iVar4 + 0x140;
    }
    (instance->position).x = *(short *)((int)pvVar5 + 0xe) + (short)(iVar4 / 0x280) * 0x280;
  }
  iVar4 = (int)(instance->position).y - (int)*(short *)((int)pvVar5 + 0x10);
  if (iVar4 != 0) {
    if (iVar4 < 1) {
      sVar1 = (short)((iVar4 + -0x140) / 0x280);
    }
    else {
      sVar1 = (short)((iVar4 + 0x140) / 0x280);
    }
    (instance->position).y = *(short *)((int)pvVar5 + 0x10) + sVar1 * 0x280;
  }
  iVar4 = (int)(instance->position).z - (int)*(short *)((int)pvVar5 + 0x12);
  if (iVar4 != 0) {
    if (iVar4 < 0) {
      sVar1 = (short)((iVar4 + -0x50) / 0xa0);
    }
    else {
      sVar1 = (short)((iVar4 + 0x50) / 0xa0);
    }
    (instance->position).z = *(short *)((int)pvVar5 + 0x12) + sVar1 * 0xa0;
  }
  *(short *)((int)pvVar5 + 0xe) = (instance->position).x;
  *(short *)((int)pvVar5 + 0x10) = (instance->position).y;
  *(short *)((int)pvVar5 + 0x12) = (instance->position).z;
  G2EulerAngles_FromMatrix(&local_28,(_G2Matrix_Type *)(instance->matrix + 2),0x15);
  iVar4 = (int)(short)local_28.x;
  if (iVar4 < 0) {
    local_18 = (ushort)(iVar4 + -0x200) & 0xfc00;
    if (iVar4 + -0x200 < 0) {
      sVar1 = 0x1ff;
LAB_8006a068:
      local_18 = local_28.x + sVar1 & 0xfc00;
    }
  }
  else {
    local_18 = (ushort)(iVar4 + 0x200) & 0xfc00;
    if (iVar4 + 0x200 < 0) {
      sVar1 = 0x5ff;
      goto LAB_8006a068;
    }
  }
  iVar4 = (int)local_28.y;
  if (iVar4 < 0) {
    local_16 = (ushort)(iVar4 + -0x200) & 0xfc00;
    if (iVar4 + -0x200 < 0) {
      sVar1 = 0x1ff;
LAB_8006a0a0:
      local_16 = local_28.y + sVar1 & 0xfc00;
    }
  }
  else {
    local_16 = (ushort)(iVar4 + 0x200) & 0xfc00;
    if (iVar4 + 0x200 < 0) {
      sVar1 = 0x5ff;
      goto LAB_8006a0a0;
    }
  }
  iVar4 = (int)local_28.z;
  if (iVar4 < 0) {
    local_14 = (ushort)(iVar4 + -0x200) & 0xfc00;
    if (-1 < iVar4 + -0x200) goto LAB_8006a0dc;
    sVar1 = 0x1ff;
  }
  else {
    local_14 = (ushort)(iVar4 + 0x200) & 0xfc00;
    if (-1 < iVar4 + 0x200) goto LAB_8006a0dc;
    sVar1 = 0x5ff;
  }
  local_14 = local_28.z + sVar1 & 0xfc00;
LAB_8006a0dc:
  iVar4 = (int)(((uint)local_28.x - (uint)local_18) * 0x10000) >> 0x10;
  if (iVar4 < 0) {
    iVar4 = iVar4 + -0x96;
  }
  else {
    iVar4 = iVar4 + 0x96;
  }
  iVar2 = (int)(short)(local_28.y - local_16);
  if (iVar2 < 0) {
    iVar2 = iVar2 + -0x96;
  }
  else {
    iVar2 = iVar2 + 0x96;
  }
  iVar3 = (int)(short)(local_28.z - local_14);
  if (iVar3 < 0) {
    iVar3 = iVar3 + -0x96;
  }
  else {
    iVar3 = iVar3 + 0x96;
  }
  local_20.x = (short)(iVar4 / 0x12d) * 0x12d + local_18;
  local_20.y = (short)(iVar2 / 0x12d) * 0x12d + local_16;
  local_20.z = (short)(iVar3 / 0x12d) * 0x12d + local_14;
  iVar4 = (int)(short)local_20.x - (int)(short)local_28.x;
  iVar2 = (int)(short)local_18 - (int)(short)local_28.x;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (iVar2 < iVar4) {
    local_20.x = local_18;
  }
  iVar4 = (int)(short)local_20.y - (int)local_28.y;
  iVar2 = (int)(short)local_16 - (int)local_28.y;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (iVar2 < iVar4) {
    local_20.y = local_16;
  }
  iVar4 = (int)(short)local_20.z - (int)local_28.z;
  iVar2 = (int)(short)local_14 - (int)local_28.z;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  if (iVar2 < 0) {
    iVar2 = -iVar2;
  }
  if (iVar2 < iVar4) {
    local_20.z = local_14;
  }
  G2Anim_SetController_Vector(&instance->anim,2,0xe,&local_20);
  G2Instance_RebuildTransforms(instance);
  G2Anim_SwitchToKeylist(&instance->anim,*instance->object->animList,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ FinishPush(struct _Instance *instance /*$a0*/)
 // line 1099, offset 0x8006a368
	/* begin block 1 */
		// Start line: 2384
	/* end block 1 */
	// End Line: 2385

/* File: C:\kain2\game\PHYSOBS.C */

void FinishPush(_Instance *instance)

{
  ResetOrientation(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysOb_AlignPush(struct _Instance *instance /*$s4*/, int x /*$s5*/, int y /*$s3*/, int path /*$s6*/, struct PhysObData *Data /*stack 16*/)
 // line 1105, offset 0x8006a388
	/* begin block 1 */
		// Start line: 1106
		// Start offset: 0x8006A388
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -96
	// 		int rotZ; // $s2
	// 		short temp[3][3]; // stack offset -88
	// 		short temp2[3][3]; // stack offset -64
	// 		struct _G2EulerAngles_Type ea; // stack offset -40
	/* end block 1 */
	// End offset: 0x8006A420
	// End Line: 1134

	/* begin block 2 */
		// Start line: 2396
	/* end block 2 */
	// End Line: 2397

/* File: C:\kain2\game\PHYSOBS.C */

void PhysOb_AlignPush(_Instance *instance,int x,int y,int path,PhysObData *Data)

{
  _G2Anim_Type *anim;
  short sVar1;
  SVECTOR local_60;
  undefined auStack88 [24];
  undefined auStack64 [24];
  _G2EulerAngles_Type local_28;
  
  G2Anim_EnableController(&instance->anim,0,0x4c);
  G2Anim_EnableController(&instance->anim,2,0xe);
  sVar1 = 0x800;
  Data->xForce = (short)x;
  Data->yForce = (short)y;
  Data->PathNumber = (short)path;
  Data->Mode = Data->Mode & 0xffefffff;
  if (((y < 1) && (sVar1 = 0, -1 < y)) && (sVar1 = 0x400, x < 0)) {
    sVar1 = -0x400;
  }
  anim = &instance->anim;
  local_60.vx = 0;
  local_60.vy = 0;
  local_60.vz = sVar1;
  G2Anim_SetController_Vector(anim,0,0x4c,(_G2SVector3_Type *)&local_60);
  local_60.vz = -sVar1;
  RotMatrixZYX(&local_60,(MATRIX *)auStack88);
  MulMatrix0((MATRIX *)auStack88,instance->matrix + 2,(MATRIX *)(_G2Matrix_Type *)(auStack88 + 0x18)
            );
  G2EulerAngles_FromMatrix(&local_28,(_G2Matrix_Type *)(auStack88 + 0x18),0x15);
  local_60.vx = local_28.x;
  local_60.vy = local_28.y;
  local_60.vz = local_28.z;
  G2Anim_SetController_Vector(anim,2,0xe,(_G2SVector3_Type *)&local_60);
  G2Anim_SwitchToKeylist(anim,instance->object->animList[path],path);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FlipPhysOb(struct _Instance *instance /*$s1*/, short x /*stack -32*/, short y /*stack -30*/, struct _Instance *Force /*$s3*/)
 // line 1151, offset 0x8006a4f8
	/* begin block 1 */
		// Start line: 1152
		// Start offset: 0x8006A4F8
		// Variables:
	// 		struct PhysObData *Data; // $s0
	// 		struct PhysObProperties *Prop; // $v0
	// 		int result; // $s2
	/* end block 1 */
	// End offset: 0x8006A61C
	// End Line: 1198

	/* begin block 2 */
		// Start line: 2517
	/* end block 2 */
	// End Line: 2518

/* File: C:\kain2\game\PHYSOBS.C */

int FlipPhysOb(_Instance *instance,short x,short y,_Instance *Force)

{
  short sVar1;
  _Instance *p_Var2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  short local_20;
  short local_1e [3];
  
  uVar5 = 0;
  if ((*(ushort *)((int)instance->data + 6) & 2) != 0) {
    local_20 = x;
    local_1e[0] = y;
    p_Var2 = PHYSOBS_IsAPushBlockAttached(instance);
    uVar5 = 0;
    if (p_Var2 == (_Instance *)0x0) {
      puVar4 = (uint *)instance->extraData;
      uVar5 = 0;
      if ((*puVar4 & 0x2000) == 0) {
        iVar3 = AnyBlocksInMotion();
        uVar5 = 0;
        if (iVar3 == 0) {
          PHYSOB_NormalToAxis(&local_20,local_1e);
          *(undefined2 *)(puVar4 + 10) = 1;
          *(_Instance **)(puVar4 + 2) = Force;
          *puVar4 = *puVar4 | 8;
          *(short *)(puVar4 + 1) = local_20;
          *(short *)((int)puVar4 + 6) = local_1e[0];
          instance->zVel = 0;
          instance->yVel = 0;
          instance->xVel = 0;
          instance->zAccl = 0;
          instance->yAccl = 0;
          instance->xAccl = 0;
          ResetOrientation(instance);
          uVar5 = PHYSOBS_CheckForValidMove(instance);
          if ((uVar5 & 1) != 0) {
            *(short *)((int)puVar4 + 0xe) = (instance->position).x;
            *(short *)(puVar4 + 4) = (instance->position).y;
            sVar1 = (instance->position).z;
            *puVar4 = *puVar4 | 0x1000;
            *(short *)((int)puVar4 + 0x12) = sVar1;
            instance->flags2 = instance->flags2 | 8;
          }
        }
      }
    }
  }
  return uVar5;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CanBePickedUp(struct _Instance *instance /*$s1*/, struct _Instance *Force /*$s0*/, int LinkNode /*$s2*/)
 // line 1241, offset 0x8006a63c
	/* begin block 1 */
		// Start line: 1242
		// Start offset: 0x8006A63C

		/* begin block 1.1 */
			// Start line: 1265
			// Start offset: 0x8006A6B8
			// Variables:
		// 		struct _PCollideInfo pcollideInfo; // stack offset -80
		// 		struct _Position newPos; // stack offset -32
		// 		struct _Position oldPos; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 1288
				// Start offset: 0x8006A784
			/* end block 1.1.1 */
			// End offset: 0x8006A7B8
			// End Line: 1297
		/* end block 1.1 */
		// End offset: 0x8006A7B8
		// End Line: 1299
	/* end block 1 */
	// End offset: 0x8006A7BC
	// End Line: 1303

	/* begin block 2 */
		// Start line: 2730
	/* end block 2 */
	// End Line: 2731

/* File: C:\kain2\game\PHYSOBS.C */

int CanBePickedUp(_Instance *instance,_Instance *Force,int LinkNode)

{
  int iVar1;
  long lVar2;
  _PCollideInfo local_50;
  SVECTOR local_20;
  SVECTOR local_18;
  
  if (Force == (_Instance *)0x0) {
    return 0;
  }
  if (((Force->object->oflags2 & 0x80000U) == 0) && (Force->matrix != (MATRIX *)0x0)) {
    iVar1 = CheckPhysObAbility(instance,1);
    if (iVar1 == 0) {
      return 0;
    }
    if (instance->matrix != (MATRIX *)0x0) {
      local_18.vx = *(short *)instance->matrix[2].t;
      local_18.vy = *(short *)(instance->matrix[2].t + 1);
      local_18.vz = *(short *)(instance->matrix[2].t + 2);
      local_20.vx = *(short *)Force->matrix[LinkNode].t;
      local_20.vy = *(short *)(Force->matrix[LinkNode].t + 1);
      local_20.vz = *(short *)(Force->matrix[LinkNode].t + 2);
      local_50.newPoint = &local_20;
      local_50.oldPoint = &local_18;
      iVar1 = CheckPhysObAbility(instance,0x20);
      if ((iVar1 != 0) && (local_20.vz < local_18.vz)) {
        return 1;
      }
      PHYSICS_CheckLineInWorld(instance,&local_50);
      if (1 < local_50.type) {
        lVar2 = MATH3D_LengthXYZ((int)local_20.vx - (int)local_18.vx,
                                 (int)local_20.vy - (int)local_18.vy,
                                 (int)local_20.vz - (int)local_18.vz);
        if (0x14 < lVar2) {
          return 0;
        }
        return 1;
      }
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PickUpPhysOb(struct _Instance *instance /*$s1*/, short Steps /*$a1*/, struct _Instance *Force /*$s3*/, int LinkNode /*$s4*/)
 // line 1306, offset 0x8006a7d4
	/* begin block 1 */
		// Start line: 1307
		// Start offset: 0x8006A7D4
		// Variables:
	// 		struct PhysObData *Data; // $s0

		/* begin block 1.1 */
			// Start line: 1347
			// Start offset: 0x8006A890
			// Variables:
		// 		struct _PhysObLight *pLight; // $v0
		/* end block 1.1 */
		// End offset: 0x8006A8A8
		// End Line: 1353
	/* end block 1 */
	// End offset: 0x8006A8B4
	// End Line: 1359

	/* begin block 2 */
		// Start line: 2879
	/* end block 2 */
	// End Line: 2880

/* File: C:\kain2\game\PHYSOBS.C */

int PickUpPhysOb(_Instance *instance,short Steps,_Instance *Force,int LinkNode)

{
  int iVar1;
  _PhysObLight *pLight;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if (instance->LinkParent == (_Instance *)0x0) {
    if ((*puVar2 & 0x2000000) != 0) {
      return 1;
    }
    TurnOffCollisionPhysOb(instance,7);
    iVar1 = CanBePickedUp(instance,Force,LinkNode);
    if (iVar1 != 0) {
      *(short *)(puVar2 + 9) = Steps;
      *(undefined2 *)((int)puVar2 + 0x26) = 0;
      *(_Instance **)(puVar2 + 2) = Force;
      *(short *)(puVar2 + 3) = (short)LinkNode;
      *puVar2 = *puVar2 & 0xff9fffff | 0x4000;
      iVar1 = CheckPhysObAbility(instance,0x20);
      if (iVar1 != 0) {
        if ((*puVar2 & 0x10000) == 0) {
          return 0;
        }
        pLight = PhysObGetLight(instance);
        if (pLight != (_PhysObLight *)0x0) {
          PHYSOB_StartLighting(instance,pLight);
        }
      }
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ PHYSOB_BirthCollectible(struct _Instance *parent /*$a0*/, int x /*$s1*/, int y /*$s2*/, int z /*$s3*/, int type /*stack 16*/, int lifeTime /*stack 20*/)
 // line 1388, offset 0x8006a8d4
	/* begin block 1 */
		// Start line: 1389
		// Start offset: 0x8006A8D4
		// Variables:
	// 		struct Object *object; // $a1
	// 		struct _Instance *instance; // $a2

		/* begin block 1.1 */
			// Start line: 1402
			// Start offset: 0x8006A940
		/* end block 1.1 */
		// End offset: 0x8006A964
		// End Line: 1411
	/* end block 1 */
	// End offset: 0x8006A964
	// End Line: 1414

	/* begin block 2 */
		// Start line: 2765
	/* end block 2 */
	// End Line: 2766

/* File: C:\kain2\game\PHYSOBS.C */

_Instance * PHYSOB_BirthCollectible(_Instance *parent,int x,int y,int z,int type,int lifeTime)

{
  Object *object;
  _Instance *p_Var1;
  
  p_Var1 = (_Instance *)0x0;
  object = (Object *)objectAccess[25].object;
  if (type != 0) {
    object = (Object *)objectAccess[26].object;
  }
  if ((object != (Object *)0x0) &&
     (p_Var1 = INSTANCE_BirthObject(parent,object,0), p_Var1 != (_Instance *)0x0)) {
    *(int *)((int)p_Var1->extraData + 4) = lifeTime * 0x1e000;
    p_Var1->fadeValue = 0x1000;
    (p_Var1->position).x = (short)x;
    (p_Var1->position).y = (short)y;
    (p_Var1->position).z = (short)z;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct evObjectBirthProjectileData * /*$ra*/ PHYSOB_BirthProjectile(struct _Instance *parent /*$s0*/, int joint /*$s1*/, int type /*$s2*/)
 // line 1418, offset 0x8006a984
	/* begin block 1 */
		// Start line: 1419
		// Start offset: 0x8006A984
		// Variables:
	// 		struct evObjectBirthProjectileData *rc; // $s0
	/* end block 1 */
	// End offset: 0x8006A984
	// End Line: 1419

	/* begin block 2 */
		// Start line: 3109
	/* end block 2 */
	// End Line: 3110

/* File: C:\kain2\game\PHYSOBS.C */

evObjectBirthProjectileData * PHYSOB_BirthProjectile(_Instance *parent,int joint,int type)

{
  evObjectBirthProjectileData *peVar1;
  _Instance *p_Var2;
  
  peVar1 = (evObjectBirthProjectileData *)SetObjectBirthProjectileData(parent,joint,type);
  p_Var2 = BirthProjectilePhysOb(parent,joint,type);
  peVar1->birthInstance = p_Var2;
  return peVar1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ BirthProjectilePhysOb(struct _Instance *instance /*$s2*/, int grabJoint /*$s3*/, int type /*$s0*/)
 // line 1429, offset 0x8006a9dc
	/* begin block 1 */
		// Start line: 1430
		// Start offset: 0x8006A9DC
		// Variables:
	// 		struct Object *ForceOb; // $a1
	// 		struct _Instance *iForce; // $s1
	// 		struct PhysObData *Data; // $s2
	// 		struct PhysObProperties *Prop; // $s0

		/* begin block 1.1 */
			// Start line: 1444
			// Start offset: 0x8006AA24
			// Variables:
		// 		struct __PhysObProjectileProperties *ProjProp; // $v1
		// 		struct __PhysObProjectileData *ProjData; // $s0

			/* begin block 1.1.1 */
				// Start line: 1467
				// Start offset: 0x8006AAAC
				// Variables:
			// 		struct __PhysObProjectileData *ProjData; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8006AB00
			// End Line: 1479
		/* end block 1.1 */
		// End offset: 0x8006AB50
		// End Line: 1501
	/* end block 1 */
	// End offset: 0x8006AB54
	// End Line: 1510

	/* begin block 2 */
		// Start line: 3131
	/* end block 2 */
	// End Line: 3132

/* File: C:\kain2\game\PHYSOBS.C */

_Instance * BirthProjectilePhysOb(_Instance *instance,int grabJoint,int type)

{
  void *pvVar1;
  int NewAnim;
  char *pcVar2;
  _Instance *instance_00;
  undefined4 *puVar3;
  
  instance_00 = (_Instance *)0x0;
  if ((objectAccess[19].object != (void *)0x0) &&
     (instance_00 = INSTANCE_BirthObject(instance,(Object *)objectAccess[19].object,0),
     instance_00 != (_Instance *)0x0)) {
    pvVar1 = instance_00->data;
    *(int *)((int)instance_00->extraData + 4) = type;
    pcVar2 = (char *)(*(int *)((int)pvVar1 + 0xc) + type * 0xc);
    puVar3 = (undefined4 *)instance_00->extraData;
    instance_00->currentModel = (short)*pcVar2;
    INSTANCE_LinkToParent(instance_00,instance,grabJoint);
    if ((*(uint *)(pcVar2 + 4) & 1) != 0) {
      instance_00->flags2 = instance_00->flags2 | 0x80000000;
    }
    TurnOffCollisionPhysOb(instance_00,7);
    pvVar1 = instance_00->data;
    if ((*(short *)((int)pvVar1 + 2) == 7) &&
       (NewAnim = (int)*(char *)(*(int *)((int)pvVar1 + 0xc) +
                                 *(int *)((int)instance_00->extraData + 4) * 0xc + 1), NewAnim != -1
       )) {
      G2EmulationInstanceSetAnimation(instance_00,0,NewAnim,0,0);
      G2EmulationInstanceSetMode(instance_00,0,2);
    }
    if ((*(ushort *)((int)pvVar1 + 6) & 1) == 0) {
      puVar3[0x11] = 0x96000;
    }
    else {
      *puVar3 = 0x1080;
      puVar3[2] = 0;
      *(undefined2 *)((int)puVar3 + 0x26) = 0;
      *(undefined2 *)(puVar3 + 9) = 0;
      instance_00->xVel = 0;
      instance_00->yVel = 0;
      instance_00->zVel = 0;
      instance_00->xAccl = 0;
      instance_00->yAccl = 0;
      instance_00->zAccl = 0;
    }
  }
  return instance_00;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_SetLightTable(struct _PhysObLight *pLight /*$a0*/, struct LightInstance *li /*$a1*/, short burnAmplitude /*$a2*/)
 // line 1538, offset 0x8006ab70
	/* begin block 1 */
		// Start line: 1541
		// Start offset: 0x8006AB70
		// Variables:
	// 		long idx; // $a3
	// 		long frac; // $t2
	// 		struct LightTableEntry *ltable; // $t1
	// 		struct LightTableEntry *ltable2; // $a0
	/* end block 1 */
	// End offset: 0x8006AC20
	// End Line: 1561

	/* begin block 2 */
		// Start line: 3379
	/* end block 2 */
	// End Line: 3380

	/* begin block 3 */
		// Start line: 3381
	/* end block 3 */
	// End Line: 3382

	/* begin block 4 */
		// Start line: 3385
	/* end block 4 */
	// End Line: 3386

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_SetLightTable(_PhysObLight *pLight,LightInstance *li,short burnAmplitude)

{
  int iVar1;
  LightTableEntry *pLVar2;
  LightTableEntry *pLVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (int)((uint)(ushort)DAT_800d2204 * (int)pLight->speed) % ((uint)pLight->length << 0xc);
  pLVar2 = pLight->lightTable;
  uVar4 = uVar5 & 0xfff;
  iVar1 = (int)uVar5 >> 0xc;
  uVar5 = iVar1 + 1;
  pLVar3 = pLVar2 + iVar1;
  if (uVar5 == (uint)pLight->length) {
    uVar5 = 0;
  }
  li->segment = pLight->segment;
  pLVar2 = pLVar2 + uVar5;
  iVar1 = ((int)(((uint)(ushort)pLVar3->radius +
                 ((int)(((int)pLVar2->radius - (int)pLVar3->radius) * uVar4) >> 0xc)) * 0x10000) >>
          0x10) * (int)burnAmplitude >> 0xc;
  li->radius = (short)iVar1;
  if (iVar1 << 0x10 < 1) {
    li->radius = 1;
  }
  li->r = (int)(short)((int)((int)pLVar3->r * 0x1000 + ((int)pLVar2->r - (int)pLVar3->r) * uVar4) /
                      (int)li->radius);
  li->g = (int)(short)((int)((int)pLVar3->g * 0x1000 + ((int)pLVar2->g - (int)pLVar3->g) * uVar4) /
                      (int)li->radius);
  li->b = (int)(short)((int)((int)pLVar3->b * 0x1000 + ((int)pLVar2->b - (int)pLVar3->b) * uVar4) /
                      (int)li->radius);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_EndLighting(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a1*/)
 // line 1567, offset 0x8006acd8
	/* begin block 1 */
		// Start line: 1571
		// Start offset: 0x8006ACD8

		/* begin block 1.1 */
			// Start line: 1573
			// Start offset: 0x8006ACE0
		/* end block 1.1 */
		// End offset: 0x8006ACF4
		// End Line: 1583
	/* end block 1 */
	// End offset: 0x8006ACF4
	// End Line: 1584

	/* begin block 2 */
		// Start line: 3443
	/* end block 2 */
	// End Line: 3444

	/* begin block 3 */
		// Start line: 3446
	/* end block 3 */
	// End Line: 3447

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_EndLighting(_Instance *instance,_PhysObLight *pLight)

{
  if ((pLight != (_PhysObLight *)0x0) && (DAT_800d20d8 == instance)) {
    DAT_800d20d8 = (_Instance *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_StartLighting(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a3*/)
 // line 1586, offset 0x8006acfc
	/* begin block 1 */
		// Start line: 1587
		// Start offset: 0x8006ACFC
		// Variables:
	// 		struct PhysObData *Data; // $a2

		/* begin block 1.1 */
			// Start line: 1602
			// Start offset: 0x8006AD3C
			// Variables:
		// 		struct LightInstance *li; // $a1
		/* end block 1.1 */
		// End offset: 0x8006AD5C
		// End Line: 1616
	/* end block 1 */
	// End offset: 0x8006AD5C
	// End Line: 1617

	/* begin block 2 */
		// Start line: 3481
	/* end block 2 */
	// End Line: 3482

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_StartLighting(_Instance *instance,_PhysObLight *pLight)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if (*(short *)(puVar1 + 0xd) < 0) {
    *(short *)(puVar1 + 0xd) = -*(short *)(puVar1 + 0xd);
  }
  *puVar1 = *puVar1 | 0x18000;
  if (pLight != (_PhysObLight *)0x0) {
    DAT_800d20d8 = instance;
    PHYSOB_SetLightTable(pLight,(LightInstance *)&DAT_800d20d8,*(short *)(puVar1 + 0xd));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_StartBurnFX(struct _Instance *instance /*$s2*/)
 // line 1619, offset 0x8006ad6c
	/* begin block 1 */
		// Start line: 1620
		// Start offset: 0x8006AD6C
		// Variables:
	// 		struct PhysObData *Data; // $v0
	// 		struct Object *object; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8006ADE0
	// End Line: 1636

	/* begin block 2 */
		// Start line: 3550
	/* end block 2 */
	// End Line: 3551

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_StartBurnFX(_Instance *instance)

{
  int iVar1;
  int iVar2;
  Object *pOVar3;
  
  pOVar3 = instance->object;
  if (((*(short *)((int)instance->extraData + 0x34) == 0) && (pOVar3->numberOfEffects != 0)) &&
     (iVar2 = 0, 0 < pOVar3->numberOfEffects)) {
    iVar1 = 0;
    do {
      FX_StartInstanceEffect(instance,(ObjectEffect *)(&pOVar3->effectList->effectNumber + iVar1),1)
      ;
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (iVar2 < pOVar3->numberOfEffects);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_StartBurning(struct _Instance *instance /*$s0*/, struct _PhysObLight *pLight /*$s1*/)
 // line 1638, offset 0x8006adf8
	/* begin block 1 */
		// Start line: 3594
	/* end block 1 */
	// End Line: 3595

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_StartBurning(_Instance *instance,_PhysObLight *pLight)

{
  PHYSOB_StartBurnFX(instance);
  PHYSOB_StartLighting(instance,pLight);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_StopLighting(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a1*/)
 // line 1646, offset 0x8006ae34
	/* begin block 1 */
		// Start line: 1648
		// Start offset: 0x8006AE34
		// Variables:
	// 		struct PhysObData *Data; // $v0
	/* end block 1 */
	// End offset: 0x8006AE34
	// End Line: 1648

	/* begin block 2 */
		// Start line: 3610
	/* end block 2 */
	// End Line: 3611

	/* begin block 3 */
		// Start line: 3611
	/* end block 3 */
	// End Line: 3612

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_StopLighting(_Instance *instance,_PhysObLight *pLight)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  *(undefined2 *)(puVar1 + 0xd) = 0xf000;
  *puVar1 = *puVar1 | 0x8000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_StopBurning(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a1*/)
 // line 1658, offset 0x8006ae54
	/* begin block 1 */
		// Start line: 1660
		// Start offset: 0x8006AE54
		// Variables:
	// 		struct PhysObData *Data; // $a0
	/* end block 1 */
	// End offset: 0x8006AE54
	// End Line: 1662

	/* begin block 2 */
		// Start line: 3635
	/* end block 2 */
	// End Line: 3636

	/* begin block 3 */
		// Start line: 3636
	/* end block 3 */
	// End Line: 3637

	/* begin block 4 */
		// Start line: 3638
	/* end block 4 */
	// End Line: 3639

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_StopBurning(_Instance *instance,_PhysObLight *pLight)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  *(undefined2 *)(puVar1 + 0xd) = 0xf000;
  *puVar1 = *puVar1 | 0x48000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_EndBurning(struct _Instance *instance /*$s0*/, struct _PhysObLight *pLight /*$s2*/)
 // line 1670, offset 0x8006ae78
	/* begin block 1 */
		// Start line: 1671
		// Start offset: 0x8006AE78
		// Variables:
	// 		struct PhysObData *Data; // $s1
	/* end block 1 */
	// End offset: 0x8006AE78
	// End Line: 1671

	/* begin block 2 */
		// Start line: 3662
	/* end block 2 */
	// End Line: 3663

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_EndBurning(_Instance *instance,_PhysObLight *pLight)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  FX_EndInstanceEffects(instance);
  PHYSOB_EndLighting(instance,pLight);
  *(undefined2 *)(puVar1 + 0xd) = 0;
  *puVar1 = *puVar1 & 0xfffeffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StopPhysOb(struct _Instance *instance /*$a0*/)
 // line 1688, offset 0x8006aed8
	/* begin block 1 */
		// Start line: 1689
		// Start offset: 0x8006AED8
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006AED8
	// End Line: 1689

	/* begin block 2 */
		// Start line: 3699
	/* end block 2 */
	// End Line: 3700

/* File: C:\kain2\game\PHYSOBS.C */

void StopPhysOb(_Instance *instance)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)instance->extraData;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)((int)puVar1 + 0x1a) = 1;
  ResetOrientation(instance);
  *puVar1 = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitPhysicalObject(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s5*/)
 // line 1711, offset 0x8006af14
	/* begin block 1 */
		// Start line: 1712
		// Start offset: 0x8006AF14
		// Variables:
	// 		struct PhysObData *Data; // $s3
	// 		struct PhysObProperties *Prop; // $s4

		/* begin block 1.1 */
			// Start line: 1719
			// Start offset: 0x8006AF4C
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $v0
		/* end block 1.1 */
		// End offset: 0x8006AFB8
		// End Line: 1734

		/* begin block 1.2 */
			// Start line: 1888
			// Start offset: 0x8006B150
			// Variables:
		// 		struct PhysObCollectibleProperties *collectibleProp; // $s0
		/* end block 1.2 */
		// End offset: 0x8006B204
		// End Line: 1907

		/* begin block 1.3 */
			// Start line: 1915
			// Start offset: 0x8006B238
			// Variables:
		// 		struct PhysObInteractProperties *interact; // $s1

			/* begin block 1.3.1 */
				// Start line: 1935
				// Start offset: 0x8006B2C0
				// Variables:
			// 		int s; // $s0
			/* end block 1.3.1 */
			// End offset: 0x8006B310
			// End Line: 1940

			/* begin block 1.3.2 */
				// Start line: 1940
				// Start offset: 0x8006B318
				// Variables:
			// 		int s; // $s0
			/* end block 1.3.2 */
			// End offset: 0x8006B368
			// End Line: 1946
		/* end block 1.3 */
		// End offset: 0x8006B43C
		// End Line: 1970

		/* begin block 1.4 */
			// Start line: 1984
			// Start offset: 0x8006B494
			// Variables:
		// 		struct _G2SVector3_Type vec; // stack offset -80
		// 		struct _G2Matrix_Type mat; // stack offset -72
		// 		struct _G2EulerAngles_Type ea; // stack offset -40
		/* end block 1.4 */
		// End offset: 0x8006B494
		// End Line: 1984

		/* begin block 1.5 */
			// Start line: 2022
			// Start offset: 0x8006B5C0
			// Variables:
		// 		struct PhysObSwitchProperties *switchProp; // $a2
		/* end block 1.5 */
		// End offset: 0x8006B620
		// End Line: 2041

		/* begin block 1.6 */
			// Start line: 2055
			// Start offset: 0x8006B658
			// Variables:
		// 		struct _PhysObLight *pLight; // $a1

			/* begin block 1.6.1 */
				// Start line: 2058
				// Start offset: 0x8006B66C
				// Variables:
			// 		struct INICommand *index; // $s0
			/* end block 1.6.1 */
			// End offset: 0x8006B6CC
			// End Line: 2071
		/* end block 1.6 */
		// End offset: 0x8006B6CC
		// End Line: 2073
	/* end block 1 */
	// End offset: 0x8006B724
	// End Line: 2090

	/* begin block 2 */
		// Start line: 3418
	/* end block 2 */
	// End Line: 3419

/* File: C:\kain2\game\PHYSOBS.C */

void InitPhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  int segment;
  uint *puVar1;
  ulong uVar2;
  uint uVar3;
  INICommand *pIVar4;
  _PhysObLight *pLight;
  byte bVar5;
  short sVar6;
  _Model **pp_Var7;
  void *pvVar8;
  _G2Anim_Type *anim;
  void *pvVar9;
  SVECTOR local_50;
  _G2Matrix_Type _Stack72;
  _G2EulerAngles_Type local_28;
  
  if ((instance->flags & 0x20000U) != 0) {
    if (*(short *)((int)instance->data + 0x1c) == 2) {
      segment = SetObjectIdleData(0,(_Instance *)0x0);
      INSTANCE_Post(gameTracker->playerInstance,0x800024,segment);
    }
    segment = CheckPhysObAbility(instance,8);
    if (segment != 0) {
      G2Anim_DetachControllerFromSeg(&instance->anim,0,0x4c);
      G2Anim_DetachControllerFromSeg(&instance->anim,2,0xe);
    }
    MEMPACK_Free((char *)instance->extraData);
    return;
  }
  pvVar9 = instance->data;
  puVar1 = (uint *)MEMPACK_Malloc(0x48,'\x1a');
  *(uint **)&instance->extraData = puVar1;
  *puVar1 = 1;
  *(undefined2 *)((int)puVar1 + 0x1a) = 0x1001;
  *(undefined2 *)((int)puVar1 + 0x22) = 0x1002;
  *(undefined2 *)((int)puVar1 + 0x2a) = 0xffff;
  *(undefined2 *)(puVar1 + 0xd) = 0x1000;
  *(undefined2 *)(puVar1 + 1) = 0;
  *(undefined2 *)((int)puVar1 + 6) = 0;
  puVar1[2] = 0;
  *(undefined2 *)((int)puVar1 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined2 *)((int)puVar1 + 0x12) = 0;
  *(undefined2 *)(puVar1 + 5) = 0;
  *(undefined2 *)((int)puVar1 + 0x16) = 0;
  *(undefined2 *)(puVar1 + 6) = 0;
  *(undefined2 *)(puVar1 + 7) = 0;
  *(undefined2 *)((int)puVar1 + 0x1e) = 0;
  *(undefined2 *)(puVar1 + 8) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  instance->maxXVel = 0x280;
  instance->maxYVel = 0x280;
  instance->maxZVel = 0x280;
  *(undefined2 *)((int)puVar1 + 0x3a) = 0;
  *(undefined2 *)(puVar1 + 0xf) = 0;
  *(undefined2 *)((int)puVar1 + 0x3e) = 0;
  if ((instance->object != (Object *)0x0) && ((instance->object->oflags & 1U) == 0)) {
    *puVar1 = *puVar1 | 0x1000;
  }
  if ((*(ushort *)((int)pvVar9 + 6) & 0x40) != 0) {
    *(ushort *)((int)pvVar9 + 6) = *(ushort *)((int)pvVar9 + 6) | 0x8000;
    instance->flags2 = instance->flags2 | 4;
  }
  if ((*(ushort *)((int)pvVar9 + 6) & 0x8000) != 0) {
    G2EmulationInstanceSetTotalSections(instance,1);
    G2EmulationInstanceSetStartAndEndSegment
              (instance,0,0,
               (short)(((uint)*(ushort *)
                               &instance->object->modelList[instance->currentModel]->numSegments - 1
                       ) * 0x10000 >> 0x10));
    G2EmulationInstanceSetAnimation(instance,0,0,0,0);
    G2EmulationInstanceSetMode(instance,0,2);
  }
  if (*(short *)((int)pvVar9 + 2) == 5) {
    pvVar8 = instance->data;
    G2EmulationInstanceInitSection(instance,0,PhysobAnimCallback,instance);
    if (*(byte *)((int)pvVar8 + 0x10) != 0xff) {
      G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar8 + 0x10),0,0);
      G2EmulationInstanceSetMode(instance,0,2);
    }
    sVar6 = *(short *)((int)pvVar8 + 8);
    if ((sVar6 == 2) && (DAT_800d20f8 != (_Instance *)0x0)) {
      uVar2 = INSTANCE_Query(DAT_800d20f8,0x24);
      if ((uVar2 & 0xfc0000) == 0) {
        instance->flags = instance->flags | 0x20;
      }
      sVar6 = *(short *)((int)pvVar8 + 8);
    }
    if (sVar6 != 3) {
      instance->flags2 = instance->flags2 | 0x20000;
    }
  }
  if ((*(ushort *)((int)pvVar9 + 6) & 0x8d00) != 0) {
    *puVar1 = *puVar1 | 0x1000;
  }
  if (*(short *)((int)pvVar9 + 2) != 3) {
    segment = CheckPhysObAbility(instance,1);
    if (segment == 0) {
      segment = CheckPhysObAbility(instance,8);
      if (segment == 0) {
        segment = CheckPhysObAbility(instance,0x40);
        if (segment != 0) {
          pvVar8 = instance->data;
          instance->flags2 = instance->flags2 | 4;
          pvVar9 = instance->extraData;
          bVar5 = *(byte *)((int)pvVar8 + 0x18);
          *(undefined2 *)((int)pvVar9 + 0x16) = 0;
          *(ushort *)((int)pvVar9 + 0x14) = (ushort)bVar5;
          if (*(char *)((int)pvVar8 + 0x19) == -1) {
            *(undefined *)((int)pvVar8 + 0x19) = 0;
          }
          G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar8 + 0x19),0,0);
          G2EmulationInstanceInitSection(instance,0,PhysobAnimCallback,instance);
        }
        segment = CheckPhysObFamily(instance,7);
        if (segment != 0) {
          G2EmulationInstanceInitSection(instance,0,PhysobAnimCallback,instance);
          instance->flags2 = instance->flags2 | 0x20000;
        }
      }
      else {
        instance->object->oflags = instance->object->oflags | 0x40000;
        *(short *)((int)puVar1 + 0xe) = (instance->position).x;
        *(short *)(puVar1 + 4) = (instance->position).y;
        *(short *)((int)puVar1 + 0x12) = (instance->position).z;
        instance->lightMatrix = 2;
        instance->object->oflags = instance->object->oflags | 0x400;
        G2EmulationInstanceInitSection(instance,0,PhysobAnimCallback,instance);
        anim = &instance->anim;
        G2Anim_AttachControllerToSeg(anim,0,0x4c);
        G2Anim_AttachControllerToSeg(anim,2,0xe);
        G2Anim_DisableController(anim,0,0x4c);
        G2Anim_EnableController(anim,2,0xe);
        local_50.vx = (instance->rotation).x;
        local_50.vy = (instance->rotation).y;
        local_50.vz = (instance->rotation).z;
        RotMatrixZYX(&local_50,(MATRIX *)&_Stack72);
        G2EulerAngles_FromMatrix(&local_28,&_Stack72,0x15);
        local_50.vx = local_28.x;
        local_50.vy = local_28.y;
        local_50.vz = local_28.z;
        (instance->rotation).x = 0;
        (instance->rotation).y = 0;
        (instance->rotation).z = 0;
        G2Anim_SetController_Vector(anim,2,0xe,(_G2SVector3_Type *)&local_50);
      }
    }
    else {
      TurnOffCollisionPhysOb(instance,7);
    }
    goto LAB_8006b65c;
  }
  pvVar8 = instance->extraData;
  *(ushort *)((int)pvVar8 + 4) = *(ushort *)((int)pvVar9 + 6) | 0x80;
  *(undefined2 *)((int)pvVar8 + 6) = 0;
  pvVar8 = instance->data;
  if ((*(ushort *)((int)pvVar8 + 0x18) & 0x80) == 0) {
    if ((*(ushort *)((int)pvVar8 + 0x18) & 1) == 0) {
      uVar3 = instance->flags2 | 4;
      goto LAB_8006b290;
    }
  }
  else {
    uVar3 = instance->flags2 | 0x20000;
LAB_8006b290:
    instance->flags2 = uVar3;
  }
  pp_Var7 = instance->object->modelList;
  if (pp_Var7 != (_Model **)0x0) {
    if ((*(byte *)((int)pvVar8 + 0x15) & 8) == 0) {
      segment = 0;
      if (0 < (*pp_Var7)->numSegments) {
        do {
          COLLIDE_SegmentCollisionOn(instance,segment);
          segment = segment + 1;
        } while (segment < (*instance->object->modelList)->numSegments);
      }
    }
    else {
      segment = 0;
      if (0 < (*pp_Var7)->numSegments) {
        do {
          COLLIDE_SegmentCollisionOff(instance,segment);
          segment = segment + 1;
        } while (segment < (*instance->object->modelList)->numSegments);
      }
    }
  }
  TurnOffCollisionPhysOb(instance,7);
  if ((*(ushort *)((int)pvVar9 + 6) & 0x8000) == 0) goto LAB_8006b3f4;
  bVar5 = *(byte *)((int)pvVar8 + 0x15) & 3;
  if (bVar5 == 1) {
    segment = 1;
LAB_8006b3ec:
    G2EmulationInstanceSetMode(instance,0,segment);
  }
  else {
    if (bVar5 < 2) {
      if ((*(byte *)((int)pvVar8 + 0x15) & 3) == 0) {
        segment = 2;
        goto LAB_8006b3ec;
      }
    }
    else {
      if (bVar5 == 2) {
        segment = 0;
        goto LAB_8006b3ec;
      }
    }
  }
LAB_8006b3f4:
  if ((*(byte *)((int)pvVar8 + 0x10) != 0xff) && ((*(ushort *)((int)pvVar9 + 6) & 0x8000) != 0)) {
    G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar8 + 0x10),0,0);
  }
  if (*(short *)((int)pvVar8 + 0x1c) == 2) {
    segment = SetObjectIdleData(1,instance);
    INSTANCE_Post(gameTracker->playerInstance,0x800024,segment);
  }
LAB_8006b65c:
  segment = CheckPhysObAbility(instance,0x20);
  if (segment != 0) {
    pIVar4 = INSTANCE_FindIntroCommand(instance,0x15);
    pLight = PhysObGetLight(instance);
    if ((pLight == (_PhysObLight *)0x0) ||
       ((pIVar4 != (INICommand *)0x0 && (((uint)pIVar4[1] & 1) != 0)))) {
      PHYSOB_EndBurning(instance,pLight);
    }
    else {
      *(undefined2 *)(puVar1 + 0xd) = 0;
      PHYSOB_StartBurnFX(instance);
      *puVar1 = *puVar1 | 0x10000;
    }
  }
  instance->flags = instance->flags | 0x10000;
  segment = CheckPhysObFamily(instance,6);
  if (segment != 0) {
    instance->flags2 = instance->flags2 | 0x20000;
  }
  segment = CheckPhysObFamily(instance,0);
  if (segment != 0) {
    instance->flags2 = instance->flags2 | 0x100;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessPhysicalObject(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s5*/)
 // line 2096, offset 0x8006b748
	/* begin block 1 */
		// Start line: 2097
		// Start offset: 0x8006B748
		// Variables:
	// 		struct PhysObData *Data; // $s1

		/* begin block 1.1 */
			// Start line: 2106
			// Start offset: 0x8006B780
			// Variables:
		// 		struct _PhysObLight *pLight; // $a0

			/* begin block 1.1.1 */
				// Start line: 2113
				// Start offset: 0x8006B794
				// Variables:
			// 		struct LightInstance *li; // $a1
			/* end block 1.1.1 */
			// End offset: 0x8006B7DC
			// End Line: 2119
		/* end block 1.1 */
		// End offset: 0x8006B7DC
		// End Line: 2120

		/* begin block 1.2 */
			// Start line: 2148
			// Start offset: 0x8006B89C
			// Variables:
		// 		struct PhysObWeaponProperties *properties; // $v0

			/* begin block 1.2.1 */
				// Start line: 2154
				// Start offset: 0x8006B8CC
				// Variables:
			// 		struct _PhysObLight *pLight; // $a1
			/* end block 1.2.1 */
			// End offset: 0x8006B904
			// End Line: 2161
		/* end block 1.2 */
		// End offset: 0x8006B904
		// End Line: 2161

		/* begin block 1.3 */
			// Start line: 2178
			// Start offset: 0x8006B964
		/* end block 1.3 */
		// End offset: 0x8006BA08
		// End Line: 2198

		/* begin block 1.4 */
			// Start line: 2203
			// Start offset: 0x8006BA1C
			// Variables:
		// 		struct PhysObAnimatedProperties *Prop; // $v0
		/* end block 1.4 */
		// End offset: 0x8006BA6C
		// End Line: 2211

		/* begin block 1.5 */
			// Start line: 2215
			// Start offset: 0x8006BA80
		/* end block 1.5 */
		// End offset: 0x8006BAC8
		// End Line: 2228

		/* begin block 1.6 */
			// Start line: 2282
			// Start offset: 0x8006BBD0
			// Variables:
		// 		struct PhysObCollectibleProperties *collectibleProp; // $a2
		/* end block 1.6 */
		// End offset: 0x8006BC20
		// End Line: 2289

		/* begin block 1.7 */
			// Start line: 2294
			// Start offset: 0x8006BC34
			// Variables:
		// 		struct Level *level; // $s2

			/* begin block 1.7.1 */
				// Start line: 2297
				// Start offset: 0x8006BC5C
				// Variables:
			// 		struct _PhysObLight *pLight; // $a1
			/* end block 1.7.1 */
			// End offset: 0x8006BC98
			// End Line: 2304
		/* end block 1.7 */
		// End offset: 0x8006BC98
		// End Line: 2305

		/* begin block 1.8 */
			// Start line: 2309
			// Start offset: 0x8006BCAC
			// Variables:
		// 		struct Level *level; // $v1

			/* begin block 1.8.1 */
				// Start line: 2317
				// Start offset: 0x8006BCF4
				// Variables:
			// 		struct PhysObProperties *Prop; // $a0
			// 		struct __PhysObProjectileData *ProjData; // $v0
			/* end block 1.8.1 */
			// End offset: 0x8006BD74
			// End Line: 2339
		/* end block 1.8 */
		// End offset: 0x8006BD74
		// End Line: 2340

		/* begin block 1.9 */
			// Start line: 2346
			// Start offset: 0x8006BD98
			// Variables:
		// 		struct evPhysicsGravityData *gravityData; // $s2
		// 		int rc; // $s3
		// 		int upperOffset; // $a0
		// 		short lowerOffset; // $a1
		// 		int wasFalling; // $s4

			/* begin block 1.9.1 */
				// Start line: 2423
				// Start offset: 0x8006BFE4
			/* end block 1.9.1 */
			// End offset: 0x8006BFF8
			// End Line: 2427

			/* begin block 1.9.2 */
				// Start line: 2452
				// Start offset: 0x8006C068
			/* end block 1.9.2 */
			// End offset: 0x8006C090
			// End Line: 2456

			/* begin block 1.9.3 */
				// Start line: 2482
				// Start offset: 0x8006C144
				// Variables:
			// 		struct _PCollideInfo CInfo; // stack offset -96
			// 		struct SVECTOR Old; // stack offset -48
			// 		struct SVECTOR New; // stack offset -40
			// 		short len; // $a2
			// 		long mult; // $a3
			/* end block 1.9.3 */
			// End offset: 0x8006C21C
			// End Line: 2515
		/* end block 1.9 */
		// End offset: 0x8006C21C
		// End Line: 2515
	/* end block 1 */
	// End offset: 0x8006C318
	// End Line: 2568

	/* begin block 2 */
		// Start line: 4672
	/* end block 2 */
	// End Line: 4673

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\PHYSOBS.C */

void ProcessPhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  byte bVar1;
  ushort uVar2;
  _PhysObLight *pLight;
  int NewAnim;
  _Instance *p_Var3;
  uint uVar4;
  ulong uVar5;
  Level *pLVar6;
  int iVar7;
  uint uVar8;
  short sVar9;
  void *pvVar10;
  short burnAmplitude;
  uint *puVar11;
  int iVar12;
  _PCollideInfo _Stack96;
  SVECTOR local_30;
  SVECTOR local_28;
  
  puVar11 = (uint *)instance->extraData;
  if (((instance == (gameTracker->gameData).asmData.lightInstances[0].lightInstance) &&
      (pLight = PhysObGetLight(instance), pLight != (_PhysObLight *)0x0)) &&
     ((gameTracker->gameData).asmData.lightInstances[0].lightInstance == instance)) {
    burnAmplitude = 0x1000;
    if (((*puVar11 & 0x8000) != 0) && (burnAmplitude = *(short *)(puVar11 + 0xd), burnAmplitude < 0)
       ) {
      burnAmplitude = -burnAmplitude;
    }
    PHYSOB_SetLightTable(pLight,(gameTracker->gameData).asmData.lightInstances,burnAmplitude);
  }
  NewAnim = CheckPhysObAbility(instance,2);
  if (NewAnim != 0) {
    p_Var3 = PHYSOBS_IsAnythingAttached(instance);
    if (p_Var3 == (_Instance *)0x0) {
      uVar4 = instance->flags2 & 0xffffff7f;
    }
    else {
      uVar4 = instance->flags2 | 0x80;
    }
    instance->flags2 = uVar4;
  }
  if (((*puVar11 & 0x2000000) != 0) &&
     (NewAnim = (uint)(ushort)instance->fadeValue + (DAT_800d2314 >> 5),
     instance->fadeValue = (short)NewAnim, 0xfff < NewAnim * 0x10000 >> 0x10)) {
    instance->flags = instance->flags | 0x20;
  }
  if ((*puVar11 & 0x8000) != 0) {
    uVar2 = *(short *)(puVar11 + 0xd) + 0x88;
    if (*(short *)(puVar11 + 0xd) < 0) {
      *(ushort *)(puVar11 + 0xd) = uVar2;
      if (-1 < (int)((uint)uVar2 << 0x10)) {
        *(undefined2 *)(puVar11 + 0xd) = 0;
        *puVar11 = *puVar11 & 0xffff7fff;
        if ((*(ushort *)((int)instance->data + 6) & 0x20) != 0) {
          pLight = PhysObGetLight(instance);
          if ((*puVar11 & 0x40000) == 0) {
            PHYSOB_EndLighting(instance,pLight);
          }
          else {
            PHYSOB_EndBurning(instance,pLight);
          }
          *puVar11 = *puVar11 & 0xfffbffff;
        }
      }
    }
    else {
      *(ushort *)(puVar11 + 0xd) = uVar2;
      if (0xfff < (short)uVar2) {
        *(undefined2 *)(puVar11 + 0xd) = 0x1000;
        *puVar11 = *puVar11 & 0xffff7fff;
      }
    }
  }
  NewAnim = CheckPhysObFamily(instance,5);
  if (NewAnim != 0) {
    pvVar10 = instance->extraData;
    if (0 < *(int *)((int)pvVar10 + 4)) {
      NewAnim = *(int *)((int)pvVar10 + 4) - DAT_800d2314;
      *(int *)((int)pvVar10 + 4) = NewAnim;
      if (NewAnim < 0) {
        *(undefined4 *)((int)pvVar10 + 4) = 0;
        INSTANCE_KillInstance(instance);
      }
      else {
        if (NewAnim < 0x1e000) {
          instance->fadeValue = 0x1000 - (short)(NewAnim / 0x1e);
        }
        else {
          uVar2 = instance->fadeValue - 0x40;
          if ((instance->fadeValue != 0) &&
             (instance->fadeValue = uVar2, (int)((uint)uVar2 << 0x10) < 0)) {
            instance->fadeValue = 0;
          }
        }
      }
    }
  }
  NewAnim = CheckPhysObFamily(instance,6);
  if ((NewAnim != 0) && ((*(ushort *)((int)instance->data + 8) & 1) != 0)) {
    uVar5 = INSTANCE_Query(DAT_800d20f8,0x24);
    if ((uVar5 & 0x10) == 0) {
      uVar4 = instance->flags | 0x800;
    }
    else {
      uVar4 = instance->flags & 0xfffff7ff;
    }
    instance->flags = uVar4;
  }
  NewAnim = CheckPhysObAbility(instance,0x40);
  if (NewAnim != 0) {
    if ((*puVar11 & 0x100000) != 0) {
      *(ushort *)((int)instance->extraData + 0x14) =
           *(ushort *)((int)instance->extraData + 0x14) & 0xfff3;
      *puVar11 = *puVar11 & 0xffeff7ff;
    }
    if ((*puVar11 & 0x800) == 0) {
      return;
    }
    G2EmulationInstancePlayAnimation(instance);
    return;
  }
  NewAnim = CheckPhysObAbility(instance,0x8000);
  if (NewAnim != 0) {
    G2EmulationInstancePlayAnimation(instance);
  }
  uVar4 = *puVar11;
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 8) != 0) {
      ExecuteFlip(instance);
      uVar4 = *puVar11;
    }
    if (((uVar4 & 1) == 0) && ((uVar4 & 0x40) != 0)) {
      ExecuteDrag(instance);
    }
  }
  if ((*puVar11 & 2) != 0) {
    ExecuteSlideToStop(instance);
  }
  if ((*puVar11 & 0x4000) != 0) {
    ExecuteGravitate(instance);
  }
  if ((*puVar11 & 0x10) != 0) {
    ExecuteThrow(instance);
  }
  if ((*puVar11 & 0x20) != 0) {
    ExecuteFollow(instance);
  }
  if (((*puVar11 & 0x100000) != 0) && (NewAnim = CheckPhysObFamily(instance,5), NewAnim != 0)) {
    bVar1 = *(byte *)((int)instance->data + 0x10);
    if (bVar1 != 0xff) {
      G2EmulationInstanceSetAnimation(instance,0,(uint)bVar1,0,0);
      G2EmulationInstanceSetMode(instance,0,2);
    }
    *puVar11 = *puVar11 & 0xffefffff;
  }
  if (((((*puVar11 & 0x10000) != 0) &&
       (pLVar6 = STREAM_GetLevelWithID(instance->currentStreamUnitID), pLVar6 != (Level *)0x0)) &&
      (instance->matrix != (MATRIX *)0x0)) &&
     (pLight = PhysObGetLight(instance),
     instance->matrix[pLight->segment].t[2] < pLVar6->waterZLevel)) {
    PHYSOB_EndBurning(instance,pLight);
  }
  NewAnim = CheckPhysObFamily(instance,7);
  if (((NewAnim != 0) && (pvVar10 = instance->extraData, *(int *)((int)pvVar10 + 4) == 8)) &&
     ((pLVar6 = STREAM_GetLevelWithID(instance->currentStreamUnitID), pLVar6 != (Level *)0x0 &&
      ((int)(instance->position).z < pLVar6->waterZLevel)))) {
    NewAnim = (int)*(char *)(*(int *)((int)instance->data + 0xc) + *(int *)((int)pvVar10 + 4) * 0xc
                            + 3);
    if (NewAnim == -1) {
      INSTANCE_KillInstance(instance);
    }
    else {
      if ((*puVar11 & 0x80000) == 0) {
        G2EmulationInstanceSetAnimation(instance,0,NewAnim,0,0);
        G2EmulationInstanceSetMode(instance,0,1);
        *puVar11 = *puVar11 | 0x81001;
      }
    }
  }
  uVar4 = *puVar11;
  if (((uVar4 & 0x1000) != 0) || (instance->matrix == (MATRIX *)0x0)) {
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
    goto LAB_8006c274;
  }
  NewAnim = (int)(instance->oldPos).z - (int)(instance->position).z;
  if (NewAnim < 0xa0) {
    NewAnim = 0xa0;
  }
  iVar12 = instance->zAccl * DAT_800d2314;
  if (iVar12 < 0) {
    iVar12 = iVar12 + 0xfff;
  }
  iVar12 = (instance->zVel + ((iVar12 << 4) >> 0x10)) * DAT_800d2314;
  if (iVar12 < 0) {
    iVar12 = iVar12 + 0xfff;
  }
  iVar12 = 0x40 - (iVar12 >> 0xc);
  burnAmplitude = (short)iVar12;
  iVar7 = iVar12 * 0x10000;
  if (iVar12 * 0x10000 >> 0x10 < 0xa0) {
    burnAmplitude = 0xa0;
    iVar7 = 0xa00000;
  }
  sVar9 = (short)((uint)iVar7 >> 0x10);
  if (iVar7 >> 0x10 < NewAnim) {
    sVar9 = (short)NewAnim;
    burnAmplitude = (short)NewAnim;
  }
  NewAnim = SetPhysicsGravityData((int)sVar9,(int)burnAmplitude,0,0,0,0xb50);
  uVar8 = PhysicsCheckGravity(instance,NewAnim,5);
  if ((uVar8 & 1) == 0) {
LAB_8006c040:
    iVar12 = instance->attachedID;
code_r0x8006c048:
    if ((iVar12 == 0) && (instance->oldMatrix != (MATRIX *)0x0)) {
      if ((uVar8 & 1) != 0) {
        (instance->position).x = (instance->position).x + *(short *)(NewAnim + 4);
        (instance->position).y = (instance->position).y + *(short *)(NewAnim + 6);
      }
      if ((instance->zVel == 0) && ((instance->object->oflags & 0x400U) != 0)) {
        instance->zVel = -0x32;
      }
      instance->zAccl = -10;
      *puVar11 = *puVar11 | 4;
    }
    else {
      instance->zAccl = 0;
      instance->zVel = 0;
    }
  }
  else {
    iVar12 = instance->attachedID;
    if ((iVar12 != 0) && ((uVar4 & 4) == 0)) goto code_r0x8006c048;
    if ((instance->wNormal).z < 0xb51) goto LAB_8006c040;
    NewAnim = instance->zVel;
    if ((*puVar11 & 0x14) != 0) {
      PHYSOB_PlayDropSound(instance);
    }
    uVar4 = *puVar11;
    *puVar11 = uVar4 & 0xfffffffb;
    if ((uVar4 & 0x400000) == 0) {
      *puVar11 = uVar4 & 0xff7ffffb;
    }
    else {
      *puVar11 = uVar4 & 0xffbfffeb | 0x200000;
      puVar11[0x11] = 10;
      TurnOnCollisionPhysOb(instance,7);
    }
    if ((*puVar11 & 0x10) != 0) {
      instance->flags2 = instance->flags2 & 0xffffff7f;
    }
    uVar4 = *puVar11;
    *puVar11 = uVar4 & 0xffffffef;
    if ((uVar4 & 0x200000) == 0) {
      TurnOffCollisionPhysOb(instance,4);
    }
    if ((uVar8 & 0x80000) == 0) {
      instance->zVel = -1;
    }
    else {
      *puVar11 = *puVar11 | 0x1000;
      instance->zAccl = 0;
      instance->zVel = 0;
    }
    if ((instance->oldMatrix != (MATRIX *)0x0) && ((*puVar11 & 0x18000) == 0x10000)) {
      pLight = PhysObGetLight(instance);
      PHYSOB_StopLighting(instance,pLight);
    }
    iVar12 = CheckPhysObAbility(instance,8);
    if ((iVar12 != 0) && ((*puVar11 & 0x100) == 0)) {
      if (NewAnim < -0x32) {
        instance->zAccl = 0;
        ResetOrientation(instance);
      }
      *(short *)((int)puVar11 + 0x12) = (instance->position).z;
    }
  }
  if (((((instance->object->oflags & 0x80000U) == 0) &&
       (NewAnim = CheckPhysObAbility(instance,8), NewAnim != 0)) && (DAT_800d20d6 == 0)) &&
     ((DAT_800d20d4 != 1000 && ((instance->flags2 & 0x8000000U) == 0)))) {
    _Stack96.newPoint = &local_28;
    local_30.vx = (instance->position).x;
    local_30.vy = (instance->position).y;
    local_30.vz = (instance->position).z;
    local_28.vz = local_30.vz - 0x500;
    _Stack96.oldPoint = &local_30;
    local_28.vx = local_30.vx;
    local_28.vy = local_30.vy;
    PHYSICS_CheckLineInWorld(instance,&_Stack96);
    instance->zAccl = 0;
    burnAmplitude = (short)((uint)local_30.vz - (uint)local_28.vz);
    if (0x3bf < (int)(((uint)local_30.vz - (uint)local_28.vz) * 0x10000) >> 0x10) {
      uVar2 = (instance->position).z;
      burnAmplitude =
           uVar2 - (*(ushort *)((int)puVar11 + 0x12) +
                   ((short)((uint)((((int)(((uint)*(ushort *)((int)puVar11 + 0x12) - (uint)uVar2) *
                                          0x10000) >> 0x10) / 0x280) * 0x10000) >> 0x10) + 1) *
                   -0x280);
    }
    instance->zVel =
         -(int)(short)((uint)((((int)burnAmplitude * 1000) / ((1000 - (int)DAT_800d20d4) * 0x32) <<
                              0x10) >> 4) / DAT_800d2314);
  }
LAB_8006c274:
  if ((*puVar11 & 0x200000) != 0) {
    puVar11[0x11] = puVar11[0x11] - 1;
    NewAnim = PHYSOB_ReAlignFalling(instance,-900);
    if ((NewAnim != 0) || ((int)puVar11[0x11] < 1)) {
      *puVar11 = *puVar11 & 0xff5fffff;
      TurnOffCollisionPhysOb(instance,7);
    }
  }
  if ((((instance->object->oflags & 0x80000U) != 0) ||
      (NewAnim = CheckPhysObAbility(instance,8), NewAnim != 0)) || (_DAT_800d20d4 == 1000)) {
    PhysicsMove(instance,&instance->position,gameTracker->timeMult);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ PhysicalObjectQuery(struct _Instance *instance /*$s0*/, unsigned long Query /*$a1*/)
 // line 2573, offset 0x8006c33c
	/* begin block 1 */
		// Start line: 2574
		// Start offset: 0x8006C33C
		// Variables:
	// 		struct PhysObData *Data; // $s2
	// 		int trueValue; // $s1

		/* begin block 1.1 */
			// Start line: 2602
			// Start offset: 0x8006C3FC
		/* end block 1.1 */
		// End offset: 0x8006C420
		// End Line: 2611

		/* begin block 1.2 */
			// Start line: 2618
			// Start offset: 0x8006C450
		/* end block 1.2 */
		// End offset: 0x8006C478
		// End Line: 2621

		/* begin block 1.3 */
			// Start line: 2626
			// Start offset: 0x8006C48C
			// Variables:
		// 		struct _G2EulerAngles_Type ea; // stack offset -24
		/* end block 1.3 */
		// End offset: 0x8006C4D8
		// End Line: 2637

		/* begin block 1.4 */
			// Start line: 2646
			// Start offset: 0x8006C4F4
			// Variables:
		// 		struct PhysObProperties *Prop; // $a0

			/* begin block 1.4.1 */
				// Start line: 2650
				// Start offset: 0x8006C50C
			/* end block 1.4.1 */
			// End offset: 0x8006C520
			// End Line: 2653

			/* begin block 1.4.2 */
				// Start line: 2655
				// Start offset: 0x8006C528
			/* end block 1.4.2 */
			// End offset: 0x8006C534
			// End Line: 2658

			/* begin block 1.4.3 */
				// Start line: 2660
				// Start offset: 0x8006C53C
			/* end block 1.4.3 */
			// End offset: 0x8006C548
			// End Line: 2663
		/* end block 1.4 */
		// End offset: 0x8006C554
		// End Line: 2671

		/* begin block 1.5 */
			// Start line: 2681
			// Start offset: 0x8006C57C
			// Variables:
		// 		struct PhysObCollectibleProperties *collectibleProp; // $v0
		/* end block 1.5 */
		// End offset: 0x8006C598
		// End Line: 2684

		/* begin block 1.6 */
			// Start line: 2730
			// Start offset: 0x8006C5F4
			// Variables:
		// 		struct PhysObDraftProperties *DraftProp; // $t0
		// 		struct INICommand *index; // $v0
		/* end block 1.6 */
		// End offset: 0x8006C64C
		// End Line: 2742

		/* begin block 1.7 */
			// Start line: 2750
			// Start offset: 0x8006C64C
			// Variables:
		// 		struct evControlSaveDataData *pdata; // $a1
		// 		struct _PhysObSaveData *data; // $a2
		/* end block 1.7 */
		// End offset: 0x8006C720
		// End Line: 2770

		/* begin block 1.8 */
			// Start line: 2778
			// Start offset: 0x8006C738
		/* end block 1.8 */
		// End offset: 0x8006C75C
		// End Line: 2790

		/* begin block 1.9 */
			// Start line: 2793
			// Start offset: 0x8006C75C
			// Variables:
		// 		struct PhysObSwitchProperties *Prop; // $v0

			/* begin block 1.9.1 */
				// Start line: 2798
				// Start offset: 0x8006C774
				// Variables:
			// 		struct PhysObData *Data; // $v0
			/* end block 1.9.1 */
			// End offset: 0x8006C798
			// End Line: 2810
		/* end block 1.9 */
		// End offset: 0x8006C798
		// End Line: 2811
	/* end block 1 */
	// End offset: 0x8006C7BC
	// End Line: 2824

	/* begin block 2 */
		// Start line: 5663
	/* end block 2 */
	// End Line: 5664

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\PHYSOBS.C */

ulong PhysicalObjectQuery(_Instance *instance,ulong Query)

{
  short sVar1;
  int iVar2;
  INICommand *pIVar3;
  MATRIX *pMVar4;
  ushort family;
  void *pvVar5;
  MATRIX *pMVar6;
  _G2EulerAngles_Type local_18;
  
  pMVar4 = (MATRIX *)instance->extraData;
  pMVar6 = (MATRIX *)0x1;
  switch(Query) {
  case 1:
    iVar2 = CheckPhysOb(instance);
    if (iVar2 != 0) {
      iVar2 = CheckPhysObFamily(instance,6);
      if (iVar2 == 0) {
        return (ulong)(MATRIX *)&DAT_00000020;
      }
      if ((*(ushort *)((int)instance->data + 8) & 1) == 0) {
        return (ulong)(MATRIX *)&DAT_00000020;
      }
      if ((instance->flags & 0x800U) != 0) {
        return (ulong)(MATRIX *)0x0;
      }
      return (ulong)(MATRIX *)&DAT_00000020;
    }
    goto switchD_8006c380_caseD_8;
  case 2:
    pMVar6 = (MATRIX *)GetPhysicalAbility(instance);
    break;
  case 3:
    pMVar6 = *(MATRIX **)pMVar4->m;
    break;
  case 4:
    pvVar5 = instance->data;
    sVar1 = *(short *)((int)pvVar5 + 2);
    if (sVar1 == 3) {
      pMVar6 = (MATRIX *)(int)*(short *)((int)instance->extraData + 6);
    }
    else {
      if (sVar1 == 0) {
        pMVar6 = (MATRIX *)(int)*(char *)((int)pvVar5 + 0x14);
      }
      else {
        if (sVar1 == 2) {
          pMVar6 = (MATRIX *)(int)*(short *)((int)pvVar5 + 10);
        }
        else {
          pMVar6 = (MATRIX *)((uint)(sVar1 == 7) << 3);
        }
      }
    }
    break;
  case 5:
    pvVar5 = instance->extraData;
    iVar2 = CheckPhysObAbility(instance,0x40);
    pMVar6 = (MATRIX *)0x0;
    if (iVar2 != 0) {
      pMVar6 = (MATRIX *)(int)*(short *)((int)pvVar5 + 0x14);
    }
    break;
  case 6:
    pMVar6 = (MATRIX *)
             SetPositionData((int)(instance->position).x,(int)(instance->position).y,
                             (int)(instance->position).z);
    break;
  case 7:
    iVar2 = CheckPhysObAbility(instance,0x40);
    if (iVar2 == 0) {
      iVar2 = CheckPhysObFamily(instance,1);
      if (iVar2 == 0) {
        pMVar6 = (MATRIX *)
                 SetPositionData((int)(instance->rotation).x,(int)(instance->rotation).y,
                                 (int)(instance->rotation).z);
      }
      else {
        if (instance->matrix == (MATRIX *)0x0) {
          local_18.x = 0;
          local_18.y = 0;
          local_18.z = 0;
        }
        else {
          G2EulerAngles_FromMatrix(&local_18,(_G2Matrix_Type *)(instance->matrix + 2),0);
        }
        pMVar6 = (MATRIX *)SetPositionData((int)local_18.x,(int)local_18.y,(int)local_18.z);
      }
    }
    else {
      pMVar6 = (MATRIX *)
               SetPositionData(0,0,(int)(((uint)(ushort)(instance->rotation).z +
                                         (uint)*(ushort *)((int)instance->extraData + 0x16)) *
                                        0x10000) >> 0x10);
    }
    break;
  default:
    goto switchD_8006c380_caseD_8;
  case 0xb:
    pMVar6 = (MATRIX *)0x3;
    break;
  case 0xc:
  case 0xd:
    pMVar6 = instance->matrix;
    break;
  case 0xe:
    iVar2 = CheckPhysObFamily(instance,5);
    if (iVar2 != 0) {
      return (ulong)(instance->matrix + *(ushort *)((int)instance->data + 0x12));
    }
    goto switchD_8006c380_caseD_8;
  case 0x15:
    family = 3;
    goto LAB_8006c5a0;
  case 0x16:
    iVar2 = CheckPhysObAbility(instance,0x100);
    if (iVar2 != 0) {
      pIVar3 = INSTANCE_FindIntroCommand(instance,0x13);
      if (pIVar3 == (INICommand *)0x0) {
        pvVar5 = instance->data;
      }
      else {
        pvVar5 = (void *)((int)instance->data + (int)pIVar3[1] * 0x14);
      }
      pMVar6 = (MATRIX *)
               SetObjectDraftData(*(short *)((int)pvVar5 + 8),*(ushort *)((int)pvVar5 + 10),
                                  *(ushort *)((int)pvVar5 + 0xc),*(ushort *)((int)pvVar5 + 0x10),
                                  (int)*(short *)((int)pvVar5 + 0xe));
      return (ulong)pMVar6;
    }
switchD_8006c380_caseD_8:
    pMVar6 = (MATRIX *)0x0;
    break;
  case 0x17:
    iVar2 = CheckPhysObAbility(instance,0x40);
    if (iVar2 == 0) {
      return (ulong)(MATRIX *)0x0;
    }
    goto LAB_8006c7ac;
  case 0x18:
    pMVar6 = (MATRIX *)CIRC_Alloc(0x10);
    *(undefined4 *)pMVar6->m = 8;
    *(short **)(pMVar6->m + 2) = pMVar6->m + 4;
    *(undefined4 *)(pMVar6->m + 4) = *(undefined4 *)((int)instance->extraData + 0x14);
    if (instance->LinkParent == (_Instance *)0x0) {
LAB_8006c70c:
      pMVar4 = *(MATRIX **)pMVar4->m;
    }
    else {
      if (((instance->LinkParent->object->oflags2 & 0x80000U) == 0) ||
         (instance->ParentLinkNode == 3)) {
        if ((instance->LinkParent != (_Instance *)0x0) && (instance->LinkParent == DAT_800d20f8)) {
          *(uint *)(pMVar6->m + 6) = (uint)*(MATRIX **)pMVar4->m & 0xffffef6f | 0x400004;
          return (ulong)pMVar6;
        }
        goto LAB_8006c70c;
      }
      pMVar4 = (MATRIX *)((uint)*(MATRIX **)pMVar4->m | 0x2000000);
    }
    *(MATRIX **)(pMVar6->m + 6) = pMVar4;
    break;
  case 0x1a:
    goto switchD_8006c380_caseD_1a;
  case 0x1b:
    pMVar6 = (MATRIX *)0x0;
    goto switchD_8006c380_caseD_1a;
  case 0x1c:
    iVar2 = CheckPhysObAbility(instance,0x40);
    goto joined_r0x8006c5d0;
  case 0x1d:
    family = 5;
LAB_8006c5a0:
    iVar2 = CheckPhysObFamily(instance,family);
joined_r0x8006c5d0:
    pMVar6 = (MATRIX *)0x0;
    if (iVar2 != 0) {
LAB_8006c7ac:
      pMVar6 = (MATRIX *)instance->data;
    }
  }
  return (ulong)pMVar6;
switchD_8006c380_caseD_1a:
  iVar2 = CheckPhysObFamily(instance,2);
  if (iVar2 != 0) {
    if ((*(ushort *)((int)instance->extraData + 0x14) & 2) != 0) {
      return (ulong)pMVar6;
    }
    return (ulong)(MATRIX *)((uint)pMVar6 ^ 1);
  }
  if (*(short *)((int)instance->data + 10) != 0) {
    return (ulong)pMVar6;
  }
  if ((*(uint *)instance->extraData & 0x2000) == 0) {
    return (ulong)pMVar6;
  }
  return (ulong)(MATRIX *)((uint)pMVar6 ^ 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicalObjectPost(struct _Instance *instance /*$s3*/, unsigned long Message /*$s0*/, unsigned long Data /*$s2*/)
 // line 2828, offset 0x8006c7d4
	/* begin block 1 */
		// Start line: 2829
		// Start offset: 0x8006C7D4
		// Variables:
	// 		struct evObjectData *Ptr; // $s4
	// 		struct PhysObData *PData; // $s1

		/* begin block 1.1 */
			// Start line: 2882
			// Start offset: 0x8006CB6C
		/* end block 1.1 */
		// End offset: 0x8006CB88
		// End Line: 2888

		/* begin block 1.2 */
			// Start line: 2908
			// Start offset: 0x8006CB98
			// Variables:
		// 		struct PhysObSwitchProperties *Prop; // $s1

			/* begin block 1.2.1 */
				// Start line: 2912
				// Start offset: 0x8006CBAC
			/* end block 1.2.1 */
			// End offset: 0x8006CBCC
			// End Line: 2921

			/* begin block 1.2.2 */
				// Start line: 2928
				// Start offset: 0x8006CBF0
				// Variables:
			// 		struct PhysObData *Data; // $a0
			/* end block 1.2.2 */
			// End offset: 0x8006CC10
			// End Line: 2937
		/* end block 1.2 */
		// End offset: 0x8006CC10
		// End Line: 2937

		/* begin block 1.3 */
			// Start line: 2945
			// Start offset: 0x8006CC24
			// Variables:
		// 		struct _PhysObSaveData *saveData; // $v0

			/* begin block 1.3.1 */
				// Start line: 2960
				// Start offset: 0x8006CC80
				// Variables:
			// 		struct _PhysObLight *pLight; // $a1
			/* end block 1.3.1 */
			// End offset: 0x8006CCA0
			// End Line: 2965
		/* end block 1.3 */
		// End offset: 0x8006CCB0
		// End Line: 2969

		/* begin block 1.4 */
			// Start line: 2972
			// Start offset: 0x8006CCB0
		/* end block 1.4 */
		// End offset: 0x8006CCB8
		// End Line: 2979

		/* begin block 1.5 */
			// Start line: 2986
			// Start offset: 0x8006CCF8
			// Variables:
		// 		struct PhysObCollectibleProperties *collectibleProp; // $s0
		/* end block 1.5 */
		// End offset: 0x8006CDD0
		// End Line: 3017

		/* begin block 1.6 */
			// Start line: 3019
			// Start offset: 0x8006CDD0
		/* end block 1.6 */
		// End offset: 0x8006CDF8
		// End Line: 3031

		/* begin block 1.7 */
			// Start line: 3057
			// Start offset: 0x8006CE5C
			// Variables:
		// 		struct _PhysObLight *pLight; // $a1

			/* begin block 1.7.1 */
				// Start line: 3071
				// Start offset: 0x8006CEB0
				// Variables:
			// 		struct PhysObData *podata; // $v1
			/* end block 1.7.1 */
			// End offset: 0x8006CEB0
			// End Line: 3071
		/* end block 1.7 */
		// End offset: 0x8006CED8
		// End Line: 3082

		/* begin block 1.8 */
			// Start line: 3091
			// Start offset: 0x8006CF0C
		/* end block 1.8 */
		// End offset: 0x8006CF0C
		// End Line: 3092

		/* begin block 1.9 */
			// Start line: 3099
			// Start offset: 0x8006CF18
		/* end block 1.9 */
		// End offset: 0x8006CF48
		// End Line: 3106
	/* end block 1 */
	// End offset: 0x8006CF48
	// End Line: 3110

	/* begin block 2 */
		// Start line: 6187
	/* end block 2 */
	// End Line: 6188

/* File: C:\kain2\game\PHYSOBS.C */

void PhysicalObjectPost(_Instance *instance,ulong Message,ulong Data)

{
  uint *puVar1;
  uint uVar2;
  int Mode;
  _PhysObLight *pLight;
  uint uVar3;
  uint *puVar4;
  void *pvVar5;
  
  puVar4 = (uint *)instance->extraData;
  if (Message == 0x800010) {
    ThrowPhysOb(instance,(evObjectThrowData *)Data);
    return;
  }
  if (Message < 0x800011) {
    if ((undefined *)Message == &DAT_00200005) {
      uVar2 = *puVar4;
      uVar3 = 0x1000000;
LAB_8006ce38:
      uVar2 = uVar2 | uVar3;
LAB_8006ce3c:
      *puVar4 = uVar2;
      return;
    }
    if (Message < &DAT_00200006) {
      if ((undefined *)Message == &DAT_00100007) {
        puVar1 = *(uint **)(Data + 4);
        puVar4[5] = *puVar1;
        uVar2 = puVar1[1];
        *puVar4 = uVar2 & 0xffeff7ff;
        if ((uVar2 & 0x2000000) != 0) {
          instance->flags = instance->flags | 0x20;
        }
        Mode = CheckPhysObAbility(instance,0x20);
        if (Mode == 0) {
          return;
        }
        pLight = PhysObGetLight(instance);
        if ((*puVar4 & 0x10000) != 0) {
          return;
        }
        PHYSOB_EndBurning(instance,pLight);
        return;
      }
      if (Message <= &DAT_00100007) {
        if (Message == 0x40002) {
          ScriptKillInstance(instance,Data);
          return;
        }
        if ((undefined *)Message != &DAT_00080005) {
          return;
        }
        ScriptKillInstance(instance,5);
        return;
      }
      if ((undefined *)Message == &DAT_00200002) {
        TurnOnCollisionPhysOb(instance,Data);
        return;
      }
      if (&DAT_00200002 < Message) {
        if ((undefined *)Message != &DAT_00200003) {
          return;
        }
        TurnOffCollisionPhysOb(instance,Data);
        return;
      }
      if ((undefined *)Message != &DAT_00100008) {
        return;
      }
      if (puVar4 == (uint *)0x0) {
        return;
      }
      *(short *)((int)puVar4 + 0xe) = *(short *)((int)puVar4 + 0xe) + *(short *)Data;
      *(short *)(puVar4 + 4) = *(short *)(puVar4 + 4) + *(short *)(Data + 2);
      *(short *)((int)puVar4 + 0x12) = *(short *)((int)puVar4 + 0x12) + *(short *)(Data + 4);
      return;
    }
    if (Message == 0x800001) {
      Mode = STREAM_IsMorphInProgress();
      if ((Mode == 0) && (DAT_800d20d6 != 0)) {
        return;
      }
      Mode = FlipPhysOb(instance,*(short *)Data,*(short *)(Data + 2),*(_Instance **)(Data + 8));
      *(int *)(Data + 0xc) = Mode;
      return;
    }
    if (0x800001 < Message) {
      if (Message == 0x800004) {
        StopPhysOb(instance);
        return;
      }
      if (Message < 0x800005) {
        if (Message != 0x800002) {
          return;
        }
        Mode = STREAM_IsMorphInProgress();
        if (((Mode == 0) && (DAT_800d20d6 != 0)) && (*(short *)(Data + 4) != 0)) {
          return;
        }
        Mode = PickUpPhysOb(instance,*(short *)(Data + 4),*(_Instance **)(Data + 8),
                            (int)*(short *)(Data + 6));
        *(undefined2 *)(Data + 6) = (short)Mode;
        if (*(short *)(Data + 4) != 0) {
          return;
        }
        if ((*puVar4 & 0x4000) == 0) {
          return;
        }
        ExecuteGravitate(instance);
        return;
      }
      if (Message != 0x800008) {
        return;
      }
      DropPhysOb(instance,Data);
      if ((Data & 1) == 0) {
        return;
      }
      uVar2 = *puVar4 | 0x2000000;
      goto LAB_8006ce3c;
    }
    if ((undefined *)Message != &DAT_00200006) {
      if (Message != 0x800000) {
        return;
      }
      Mode = STREAM_IsMorphInProgress();
      if ((Mode == 0) && (DAT_800d20d6 != 0)) {
        return;
      }
      Mode = PushPhysOb(instance,*(short *)Data,*(short *)(Data + 2),*(short *)(Data + 4),
                        *(_Instance **)(Data + 8));
      *(int *)(Data + 0xc) = Mode;
      return;
    }
    uVar2 = 0xfeff0000;
LAB_8006ce48:
    uVar2 = *puVar4 & (uVar2 | 0xffff);
LAB_8006ce54:
    *puVar4 = uVar2;
    return;
  }
  if (Message == 0x800027) {
    if (Data == 0) {
      *puVar4 = *puVar4 | 0x1000;
      return;
    }
    uVar2 = *puVar4 & 0xffffefff;
    goto LAB_8006ce54;
  }
  if (0x800027 < Message) {
    if (Message == 0x80002b) {
      uVar2 = 0xff7f0000;
      goto LAB_8006ce48;
    }
    if (Message < 0x80002c) {
      if (Message != 0x800029) {
        if (Message != 0x80002a) {
          return;
        }
        Mode = CheckPhysObFamily(instance,2);
        if (Mode == 0) {
          return;
        }
        *(undefined2 *)((int)instance->extraData + 0x14) = (short)Data;
        return;
      }
      pLight = PhysObGetLight(instance);
      if (pLight == (_PhysObLight *)0x0) {
        return;
      }
      if (Data == 1) {
        PHYSOB_StartBurning(instance,pLight);
        return;
      }
      if (Data == 0) {
        PHYSOB_StopBurning(instance,pLight);
        return;
      }
      if (Data != 2) {
        return;
      }
      puVar4 = (uint *)instance->extraData;
      *(undefined2 *)(puVar4 + 0xd) = 0;
      *puVar4 = *puVar4 & 0xffff7fff;
      PHYSOB_EndBurning(instance,pLight);
      return;
    }
    if (Message == 0x80002d) {
      ResetSwitchPhysOb(instance);
      return;
    }
    if (Message < 0x80002d) {
      uVar2 = *puVar4;
      uVar3 = 0x800000;
      goto LAB_8006ce38;
    }
    if (Message != 0x8000008) {
      return;
    }
    G2EmulationInstanceSetAnimation
              (instance,0,*(int *)(Data + 4),*(int *)(Data + 8),*(int *)(Data + 0xc));
    Mode = *(int *)(Data + 0x10);
    goto LAB_8006cf40;
  }
  if (Message < 0x800023) {
    if (Message < 0x800021) {
      if (Message != 0x800020) {
        return;
      }
      SwitchPhysOb(instance);
      return;
    }
    Mode = CheckPhysOb(instance);
    if (Mode == 0) {
      return;
    }
    pvVar5 = instance->data;
    Mode = CheckPhysObFamily(instance,2);
    if (Mode != 0) {
      pvVar5 = instance->extraData;
      if (Message == 0x800021) {
        *(ushort *)((int)pvVar5 + 0x14) = *(ushort *)((int)pvVar5 + 0x14) | 2;
        return;
      }
      *(ushort *)((int)pvVar5 + 0x14) = *(ushort *)((int)pvVar5 + 0x14) & 0xfffd;
      return;
    }
    if (*(short *)((int)pvVar5 + 10) != 0) {
      return;
    }
    puVar4 = (uint *)instance->extraData;
    if (Message == 0x800021) {
      *puVar4 = *puVar4 & 0xffffdfff;
      return;
    }
    *puVar4 = *puVar4 | 0x2000;
    return;
  }
  if (Message == 0x800025) {
    return;
  }
  if (Message < 0x800026) {
    if (Message != 0x800023) {
      return;
    }
    Mode = STREAM_IsMorphInProgress();
    if ((Mode == 0) && (DAT_800d20d6 != 0)) {
      return;
    }
    InteractPhysOb(instance,*(_Instance **)Data,(uint)*(ushort *)(Data + 4),
                   (uint)*(ushort *)(Data + 0xe));
    return;
  }
  pvVar5 = instance->data;
  switch((int)(((uint)*(ushort *)((int)pvVar5 + 8) - 1) * 0x10000) >> 0x10) {
  case 0:
    HEALTHU_Pickup(instance);
    break;
  case 1:
  case 4:
    MANNA_Pickup();
  case 2:
  case 3:
    INSTANCE_PlainDeath(instance);
    break;
  case 6:
    MANNA_Pickup();
  case 5:
    if ((*(char *)((int)pvVar5 + 0x11) != -1) &&
       (uVar2 = G2EmulationInstanceQueryAnimation(instance,0),
       uVar2 != (uint)*(byte *)((int)pvVar5 + 0x11))) {
      printf(s_Collect__s_800d079c,instance->object->name);
      G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar5 + 0x11),0,0);
      Mode = 1;
LAB_8006cf40:
      G2EmulationInstanceSetMode(instance,0,Mode);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PhysobAnimCallback(struct _G2Anim_Type *anim /*$v1*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s2*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
 // line 3112, offset 0x8006cf68
	/* begin block 1 */
		// Start line: 3113
		// Start offset: 0x8006CF68

		/* begin block 1.1 */
			// Start line: 3115
			// Start offset: 0x8006CF90
			// Variables:
		// 		struct PhysObData *Data; // $s0
		/* end block 1.1 */
		// End offset: 0x8006CFDC
		// End Line: 3132
	/* end block 1 */
	// End offset: 0x8006CFF4
	// End Line: 3136

	/* begin block 2 */
		// Start line: 6767
	/* end block 2 */
	// End Line: 6768

/* File: C:\kain2\game\PHYSOBS.C */

long PhysobAnimCallback(_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,
                       long messageDataA,long messageDataB,void *data)

{
  uint uVar1;
  uint *puVar2;
  
  if (message == G2ANIM_MSG_DONE) {
    puVar2 = *(uint **)((int)data + 0x168);
    G2AnimSection_SetPaused(anim->section + sectionID);
    uVar1 = *puVar2;
    *puVar2 = uVar1 | 0x100000;
    if ((uVar1 & 0x80000) != 0) {
      INSTANCE_KillInstance((_Instance *)data);
    }
  }
  else {
    messageDataA = INSTANCE_DefaultAnimCallback
                             (anim,sectionID,message,messageDataA,messageDataB,(_Instance *)data);
  }
  return messageDataA;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CollidePhysicalObject(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 3141, offset 0x8006d00c
	/* begin block 1 */
		// Start line: 3142
		// Start offset: 0x8006D00C
		// Variables:
	// 		struct PhysObData *Data; // $s4
	// 		struct _CollideInfo *collideInfo; // $s3
	// 		int obliqueFlg; // $fp
	// 		struct _Position vel; // stack offset -128
	// 		struct _Position dir; // stack offset -120
	// 		struct _Instance *hitinst; // $s5
	// 		struct _TFace *tface; // $s6
	// 		struct _Normal *norm; // $s1
	// 		struct _SVector normal; // stack offset -112
	// 		int stickFlg; // $s0
	// 		int drawFlg; // $s7

		/* begin block 1.1 */
			// Start line: 3163
			// Start offset: 0x8006D068
			// Variables:
		// 		struct Level *level; // $v1
		/* end block 1.1 */
		// End offset: 0x8006D0B0
		// End Line: 3173

		/* begin block 1.2 */
			// Start line: 3180
			// Start offset: 0x8006D0CC
			// Variables:
		// 		struct BSPTree *bsp; // $s0
		// 		struct Level *level; // $a0
		/* end block 1.2 */
		// End offset: 0x8006D120
		// End Line: 3187

		/* begin block 1.3 */
			// Start line: 3201
			// Start offset: 0x8006D1D0
			// Variables:
		// 		struct _Position delta; // stack offset -104

			/* begin block 1.3.1 */
				// Start line: 3203
				// Start offset: 0x8006D1D0
				// Variables:
			// 		short _x0; // $t0
			// 		short _y0; // $t1
			// 		short _z0; // $t2
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a2
			// 		struct _Position *_v; // $a1
			// 		struct _Position *_v0; // $v0
			// 		struct _Position *_v1; // $a3
			/* end block 1.3.1 */
			// End offset: 0x8006D1D0
			// End Line: 3203

			/* begin block 1.3.2 */
				// Start line: 3203
				// Start offset: 0x8006D1D0
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a2
			/* end block 1.3.2 */
			// End offset: 0x8006D1D0
			// End Line: 3203
		/* end block 1.3 */
		// End offset: 0x8006D254
		// End Line: 3209

		/* begin block 1.4 */
			// Start line: 3237
			// Start offset: 0x8006D308
			// Variables:
		// 		long axVel; // $a0
		// 		long ayVel; // $v1
		/* end block 1.4 */
		// End offset: 0x8006D390
		// End Line: 3261

		/* begin block 1.5 */
			// Start line: 3308
			// Start offset: 0x8006D438
		/* end block 1.5 */
		// End offset: 0x8006D46C
		// End Line: 3313

		/* begin block 1.6 */
			// Start line: 3322
			// Start offset: 0x8006D4A8
			// Variables:
		// 		struct _PCollideInfo CInfo; // stack offset -96
		// 		struct _SVector newPos; // stack offset -48
		/* end block 1.6 */
		// End offset: 0x8006D504
		// End Line: 3341

		/* begin block 1.7 */
			// Start line: 3361
			// Start offset: 0x8006D5A4
			// Variables:
		// 		struct _Position delta; // stack offset -104

			/* begin block 1.7.1 */
				// Start line: 3361
				// Start offset: 0x8006D5A4
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a2
			// 		short _y1; // $t1
			// 		short _z1; // $t2
			// 		struct _Position *_v; // $a3
			/* end block 1.7.1 */
			// End offset: 0x8006D5A4
			// End Line: 3361
		/* end block 1.7 */
		// End offset: 0x8006D614
		// End Line: 3381

		/* begin block 1.8 */
			// Start line: 3384
			// Start offset: 0x8006D624
		/* end block 1.8 */
		// End offset: 0x8006D67C
		// End Line: 3390

		/* begin block 1.9 */
			// Start line: 3423
			// Start offset: 0x8006D744
			// Variables:
		// 		struct _CollideInfo parentCI; // stack offset -104
		/* end block 1.9 */
		// End offset: 0x8006D79C
		// End Line: 3429

		/* begin block 1.10 */
			// Start line: 3437
			// Start offset: 0x8006D7D4
			// Variables:
		// 		struct PhysObSplinter *splintDef; // $v0
		// 		struct FXSplinter *splinterData; // $v1
		/* end block 1.10 */
		// End offset: 0x8006D81C
		// End Line: 3452

		/* begin block 1.11 */
			// Start line: 3456
			// Start offset: 0x8006D830
			// Variables:
		// 		struct PhysObProperties *Prop; // $s1
		// 		struct ProjectileData *ProjIData; // $s0
		// 		struct __PhysObProjectileData *ProjData; // $a2
		// 		int killImmediately; // $s7
		/* end block 1.11 */
		// End offset: 0x8006D9DC
		// End Line: 3534
	/* end block 1 */
	// End offset: 0x8006D9DC
	// End Line: 3536

	/* begin block 2 */
		// Start line: 6829
	/* end block 2 */
	// End Line: 6830

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* File: C:\kain2\game\PHYSOBS.C */

void CollidePhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int Data;
  Level *pLVar7;
  long lVar8;
  _CollideInfo *p_Var9;
  PhysObSplinter *pPVar10;
  ulong uVar11;
  int iVar12;
  void **ppvVar13;
  FXSplinter *splintDef;
  uint uVar14;
  void *pvVar15;
  void *pvVar16;
  SVECTOR *nrml;
  void *pvVar17;
  _CollideInfo *collideInfo;
  uint *puVar18;
  _Instance *instance_00;
  void *pvVar19;
  short local_78;
  short local_76;
  SVECTOR SStack112;
  undefined4 local_68;
  short local_64;
  _PCollideInfo local_60;
  SVECTOR local_30;
  
  bVar6 = false;
  instance_00 = (_Instance *)0x0;
  pvVar19 = (void *)0x0;
  bVar5 = true;
  collideInfo = (_CollideInfo *)instance->collideInfo;
  puVar18 = (uint *)instance->extraData;
  nrml = &collideInfo->point0;
  Data = CheckPhysObFamily(instance,7);
  if ((((Data == 0) || (*(int *)((int)instance->extraData + 4) != 8)) ||
      (pLVar7 = STREAM_GetLevelWithID(instance->currentStreamUnitID), pLVar7 == (Level *)0x0)) ||
     (pLVar7->waterZLevel <= (int)(instance->position).z)) {
    if (collideInfo->type1 == '\x03') {
      pvVar16 = collideInfo->inst1;
      pLVar7 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
      pvVar19 = collideInfo->prim1;
      if (((*(ushort *)((int)pvVar16 + 0x12) & 1) != 0) || ((*(byte *)((int)pvVar19 + 6) & 4) != 0))
      {
        bVar5 = false;
      }
      nrml = &SStack112;
      COLLIDE_GetNormal(*(short *)((int)pvVar19 + 8),(short *)pLVar7->terrain->normalList,
                        (_SVector *)nrml);
    }
    else {
      instance_00 = (_Instance *)collideInfo->inst1;
    }
    GetPhysObCollisionType(instance);
    if ((*puVar18 & 0x4000) != 0) {
      if ((_Instance *)puVar18[2] == instance_00) {
        return;
      }
      if (instance_00 != (_Instance *)0x0) {
        if ((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000) {
          return;
        }
        if ((instance_00->object->oflags2 & 0x40000U) != 0) {
          return;
        }
      }
      if (pvVar19 != (void *)0x0) {
        if (*(ushort *)((int)pvVar19 + 10) == 0xffff) {
          return;
        }
        if ((*(ushort *)
              (*(int *)(*(int *)collideInfo->level + 0x34) + (uint)*(ushort *)((int)pvVar19 + 10) +
              10) & 0x1000) == 0) {
          return;
        }
      }
      *puVar18 = *puVar18 & 0xffffbfff | 0x10;
      puVar18[0x11] = 0x96000;
      local_68._0_2_ = (instance->oldPos).x - (instance->position).x;
      local_68._2_2_ = (instance->oldPos).y - (instance->position).y;
      local_64 = (instance->oldPos).z - (instance->position).z;
      (instance->position).x = (instance->position).x + (short)local_68;
      (instance->position).y = (instance->position).y + local_68._2_2_;
      (instance->position).z = (instance->position).z + local_64;
      COLLIDE_UpdateAllTransforms(instance,0x98);
    }
    uVar14 = *puVar18;
    if ((uVar14 & 0x10) == 0) {
      if ((uVar14 & 0x200004) == 0) {
        if (((uVar14 & 0x80) != 0) &&
           (ppvVar13 = (void **)&local_68, instance->LinkParent != (_Instance *)0x0)) {
          p_Var9 = collideInfo;
          do {
            pvVar16 = *(void **)&p_Var9->flags;
            pvVar17 = p_Var9->prim0;
            pvVar15 = p_Var9->prim1;
            *ppvVar13 = p_Var9->level;
            ppvVar13[1] = pvVar16;
            ppvVar13[2] = pvVar17;
            ppvVar13[3] = pvVar15;
            p_Var9 = (_CollideInfo *)&p_Var9->inst0;
            ppvVar13 = ppvVar13 + 4;
          } while (p_Var9 != collideInfo + 1);
          local_60.inst = instance->LinkParent;
          Data = SetCollideInfoData((_CollideInfo *)&local_68);
          INSTANCE_Post(instance->LinkParent,(int)&DAT_00200004,Data);
        }
      }
      else {
        if ((collideInfo->type1 == '\x01') && ((_Instance *)puVar18[0x10] == instance_00)) {
          return;
        }
        if (nrml->vz < 0xb50) {
          return;
        }
        if ((uVar14 & 0x200000) != 0) {
          (collideInfo->offset).z = 0;
        }
        (instance->position).x = (instance->position).x + (collideInfo->offset).x;
        (instance->position).y = (instance->position).y + (collideInfo->offset).y;
        (instance->position).z = (instance->position).z + (collideInfo->offset).z;
        COLLIDE_UpdateAllTransforms(instance,(char)collideInfo + '(');
      }
    }
    else {
      if (instance_00 == (_Instance *)puVar18[0x10]) {
        return;
      }
      Data = CheckPhysObFamily(instance,7);
      if ((((Data != 0) && (pvVar19 != (void *)0x0)) && (*(ushort *)((int)pvVar19 + 10) != 0xffff))
         && ((*(ushort *)
               (*(int *)(*(int *)collideInfo->level + 0x34) + (uint)*(ushort *)((int)pvVar19 + 10) +
               10) & 0x1000) != 0)) {
        return;
      }
      sVar1 = *(short *)&instance->xVel;
      uVar2 = *(ushort *)&instance->yVel;
      uVar3 = *(ushort *)&instance->zVel;
      if ((sVar1 == 0) && (uVar2 == 0)) {
        local_76 = 0;
        local_78 = 0;
      }
      else {
        Data = instance->xVel;
        iVar12 = instance->yVel;
        if (Data < 0) {
          Data = -Data;
        }
        if (iVar12 < 0) {
          iVar12 = -iVar12;
        }
        if (iVar12 < Data) {
          if (instance->xVel < 1) {
            local_78 = -0x1000;
          }
          else {
            local_78 = 0x1000;
          }
          local_76 = 0;
          bVar4 = iVar12 < Data >> 1;
        }
        else {
          local_76 = 0x1000;
          if (instance->yVel < 1) {
            local_76 = -0x1000;
          }
          local_78 = 0;
          bVar4 = Data < iVar12 >> 1;
        }
        if (!bVar4) {
          bVar6 = true;
        }
      }
      if ((*puVar18 & 0x400000) == 0) {
        instance->xVel = 0;
        instance->yVel = 0;
        instance->zVel = 0;
        instance->xAccl = 0;
        instance->yAccl = 0;
        instance->zAccl = 0;
      }
      (instance->position).x = (instance->position).x + (collideInfo->offset).x;
      (instance->position).y = (instance->position).y + (collideInfo->offset).y;
      (instance->position).z = (instance->position).z + (collideInfo->offset).z;
      COLLIDE_UpdateAllTransforms(instance,(char)collideInfo + '(');
      if ((((int)sVar1 != 0) || ((uVar2 | uVar3) != 0)) &&
         (lVar8 = MATH3D_LengthXYZ((int)sVar1,(int)(short)uVar2,(int)(short)uVar3),
         100 < (short)lVar8)) {
        instance->flags2 = instance->flags2 | 0x2000;
      }
      bVar4 = false;
      Data = CheckPhysObAbility(instance,0x200);
      if ((Data != 0) && ((sVar1 != 0 || ((uVar2 | uVar3) != 0)))) {
        local_30.vx = (instance->position).x + sVar1 * 4;
        local_30.vy = (instance->position).y + uVar2 * 4;
        local_60.oldPoint = (SVECTOR *)&instance->position;
        local_60.newPoint = &local_30;
        local_30.vz = (instance->position).z + uVar3 * 4;
        PHYSICS_CheckLineInWorld(instance,&local_60);
        bVar4 = local_60.type != 0;
      }
      if ((((bVar4) && (bVar5)) && (instance_00 == (_Instance *)0x0)) && (nrml->vz < 0xb50)) {
        *puVar18 = *puVar18 | 0x1000;
        instance->flags2 = instance->flags2 & 0xffffff7f;
        *puVar18 = *puVar18 & 0xffffffef;
        TurnOffCollisionPhysOb(instance,4);
      }
      else {
        *puVar18 = *puVar18 & 0xffffefff | 0x400000;
        if ((sVar1 != 0) || (uVar2 != 0)) {
          memset();
          local_68._0_2_ = -sVar1;
          local_68._2_2_ = -uVar2;
          local_64 = -uVar3;
          (instance->position).x = (instance->position).x + (short)local_68;
          (instance->position).y = (instance->position).y + local_68._2_2_;
          (instance->position).z = (instance->position).z + local_64;
          COLLIDE_UpdateAllTransforms(instance,0x98);
        }
        if (((short)uVar3 < 0) &&
           (lVar8 = MATH3D_LengthXYZ((int)(collideInfo->offset).x,(int)(collideInfo->offset).y,
                                     (int)(collideInfo->offset).z),
           (int)(collideInfo->offset).z < (int)(short)lVar8 * 0xb500 >> 0x10)) {
          instance->zVel = (int)(short)uVar3;
        }
        DropPhysOb(instance,0);
      }
    }
    Data = CheckPhysObAbility(instance,0x1000);
    if (((Data != 0) && ((*puVar18 & 0x800000) == 0)) && (_DAT_800d20d4 == 1000)) {
      pPVar10 = PhysObGetSplinter(instance);
      splintDef = (FXSplinter *)0x0;
      if (pPVar10 != (PhysObSplinter *)0x0) {
        splintDef = (FXSplinter *)pPVar10->splinterData;
      }
      _FX_BuildSplinters(instance,0,0,0,splintDef,gFXT,(TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                         (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,0);
      INSTANCE_PlainDeath(instance);
    }
    Data = CheckPhysObFamily(instance,7);
    bVar5 = true;
    if (Data != 0) {
      pvVar17 = instance->data;
      pvVar16 = instance->extraData;
      COLLIDE_SegmentCollisionOff(instance,0);
      Data = *(int *)((int)pvVar17 + 0xc) + *(int *)((int)pvVar16 + 4) * 0xc;
      if (*(char *)(Data + 3) != -1) {
        *puVar18 = *puVar18 & 0xffbffffb | 0x1001;
        instance->xVel = 0;
        instance->yVel = 0;
        instance->zVel = 0;
        instance->xAccl = 0;
        instance->yAccl = 0;
        instance->zAccl = 0;
        if ((*puVar18 & 0x80000) != 0) {
          return;
        }
        bVar5 = false;
        G2EmulationInstanceSetAnimation(instance,0,(int)*(char *)(Data + 3),0,0);
        G2EmulationInstanceSetMode(instance,0,1);
        *puVar18 = *puVar18 | 0x81001;
      }
      if ((instance->parent != (_Instance *)0x0) &&
         (uVar11 = INSTANCE_Query(instance->parent,1), (uVar11 & 1) != 0)) {
        if ((pvVar19 == (void *)0x0) || (DAT_800d20d6 != 0)) {
          if ((instance_00 != DAT_800d20f8) && (DAT_800d20d6 == 0)) {
            Data = CheckPhysOb(instance_00);
            if ((Data != 0) && (!bVar6)) {
              Data = SetObjectData((int)local_78,(int)local_76,6,(_Instance *)0x0,0);
              INSTANCE_Post(instance_00,0x800000,Data);
            }
            if (*(int *)((int)pvVar16 + 4) == 1) {
              instance_00->flags2 = instance_00->flags2 | 0x10000;
            }
            else {
              instance_00->flags = instance_00->flags | 0x80000000;
            }
          }
        }
        else {
          COLLIDE_SetBSPTreeFlag(collideInfo,0x400);
        }
      }
      if (bVar5) {
        INSTANCE_KillInstance(instance);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct PhysObWeaponAttributes * /*$ra*/ PhysObGetWeapon(struct _Instance *instance /*$s1*/)
 // line 3539, offset 0x8006da0c
	/* begin block 1 */
		// Start line: 3540
		// Start offset: 0x8006DA0C
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $s0

		/* begin block 1.1 */
			// Start line: 3546
			// Start offset: 0x8006DA34
			// Variables:
		// 		struct PhysObWeaponProperties *Prop; // $v0
		/* end block 1.1 */
		// End offset: 0x8006DA40
		// End Line: 3548

		/* begin block 1.2 */
			// Start line: 3550
			// Start offset: 0x8006DA50
			// Variables:
		// 		struct PhysObInteractProperties *Prop; // $v0
		/* end block 1.2 */
		// End offset: 0x8006DA5C
		// End Line: 3552

		/* begin block 1.3 */
			// Start line: 3554
			// Start offset: 0x8006DA6C
			// Variables:
		// 		struct __PhysObProjectileProperties *Prop; // $a0
		/* end block 1.3 */
		// End offset: 0x8006DA94
		// End Line: 3558
	/* end block 1 */
	// End offset: 0x8006DA94
	// End Line: 3559

	/* begin block 2 */
		// Start line: 7749
	/* end block 2 */
	// End Line: 7750

/* File: C:\kain2\game\PHYSOBS.C */

PhysObWeaponAttributes * PhysObGetWeapon(_Instance *instance)

{
  int iVar1;
  PhysObWeaponAttributes *pPVar2;
  
  pPVar2 = (PhysObWeaponAttributes *)0x0;
  iVar1 = CheckPhysObFamily(instance,0);
  if (iVar1 != 0) {
    pPVar2 = (PhysObWeaponAttributes *)((int)instance->data + 8);
  }
  iVar1 = CheckPhysObFamily(instance,3);
  if (iVar1 != 0) {
    pPVar2 = *(PhysObWeaponAttributes **)((int)instance->data + 0x28);
  }
  iVar1 = CheckPhysObFamily(instance,7);
  if (iVar1 != 0) {
    pPVar2 = *(PhysObWeaponAttributes **)
              (*(int *)((int)instance->extraData + 4) * 0xc + *(int *)((int)instance->data + 0xc) +
              8);
  }
  return pPVar2;
}



// decompiled code
// original method signature: 
// struct _PhysObLight * /*$ra*/ PhysObGetLight(struct _Instance *instance /*$a0*/)
 // line 3564, offset 0x8006dab0
	/* begin block 1 */
		// Start line: 3565
		// Start offset: 0x8006DAB0
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $v0
	// 		struct _PhysObLight *pLight; // $s0
	/* end block 1 */
	// End offset: 0x8006DAD0
	// End Line: 3574

	/* begin block 2 */
		// Start line: 7803
	/* end block 2 */
	// End Line: 7804

/* File: C:\kain2\game\PHYSOBS.C */

_PhysObLight * PhysObGetLight(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  _PhysObLight *p_Var2;
  
  p_Var2 = (_PhysObLight *)0x0;
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0) {
    p_Var2 = pPVar1->Light;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// struct PhysObSplinter * /*$ra*/ PhysObGetSplinter(struct _Instance *instance /*$a0*/)
 // line 3578, offset 0x8006dae8
	/* begin block 1 */
		// Start line: 3579
		// Start offset: 0x8006DAE8
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $v0
	// 		struct PhysObSplinter *pSplinter; // $s0
	/* end block 1 */
	// End offset: 0x8006DB08
	// End Line: 3588

	/* begin block 2 */
		// Start line: 7831
	/* end block 2 */
	// End Line: 7832

/* File: C:\kain2\game\PHYSOBS.C */

PhysObSplinter * PhysObGetSplinter(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  PhysObSplinter *pPVar2;
  
  pPVar2 = (PhysObSplinter *)0x0;
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0) {
    pPVar2 = &pPVar1->splinter;
  }
  return pPVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TurnOnCollisionPhysOb(struct _Instance *instance /*$s1*/, int coll /*$s2*/)
 // line 3593, offset 0x8006db1c
	/* begin block 1 */
		// Start line: 3594
		// Start offset: 0x8006DB1C
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $s0
	// 		struct PhysObData *Data; // $v1
	/* end block 1 */
	// End offset: 0x8006DBA8
	// End Line: 3612

	/* begin block 2 */
		// Start line: 7861
	/* end block 2 */
	// End Line: 7862

/* File: C:\kain2\game\PHYSOBS.C */

void TurnOnCollisionPhysOb(_Instance *instance,int coll)

{
  PhysObWeaponAttributes *pPVar1;
  
  *(uint *)instance->extraData = *(uint *)instance->extraData & 0xfeffffff;
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0) {
    if ((coll & 2U) != 0) {
      COLLIDE_SegmentCollisionOn(instance,(int)pPVar1->LeftHandSphere);
    }
    if ((coll & 1U) != 0) {
      COLLIDE_SegmentCollisionOn(instance,(int)pPVar1->RightHandSphere);
    }
    if ((coll & 4U) != 0) {
      COLLIDE_SegmentCollisionOn(instance,(int)pPVar1->ThrowSphere);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TurnOffCollisionPhysOb(struct _Instance *instance /*$s1*/, int coll /*$s2*/)
 // line 3617, offset 0x8006dbc0
	/* begin block 1 */
		// Start line: 3618
		// Start offset: 0x8006DBC0
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $s0
	/* end block 1 */
	// End offset: 0x8006DC30
	// End Line: 3634

	/* begin block 2 */
		// Start line: 7916
	/* end block 2 */
	// End Line: 7917

/* File: C:\kain2\game\PHYSOBS.C */

void TurnOffCollisionPhysOb(_Instance *instance,int coll)

{
  PhysObWeaponAttributes *pPVar1;
  
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0) {
    if ((coll & 2U) != 0) {
      COLLIDE_SegmentCollisionOff(instance,(int)pPVar1->LeftHandSphere);
    }
    if ((coll & 1U) != 0) {
      COLLIDE_SegmentCollisionOff(instance,(int)pPVar1->RightHandSphere);
    }
    if ((coll & 4U) != 0) {
      COLLIDE_SegmentCollisionOff(instance,(int)pPVar1->ThrowSphere);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetPhysObCollisionType(struct _Instance *instance /*$s1*/)
 // line 3641, offset 0x8006dc48
	/* begin block 1 */
		// Start line: 3642
		// Start offset: 0x8006DC48
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s5
	// 		struct _HSphere *S; // $v0
	// 		struct _Instance *target; // $s2
	// 		struct PhysObWeaponAttributes *weapon; // $s0
	// 		struct PhysObData *Data; // $s4

		/* begin block 1.1 */
			// Start line: 3665
			// Start offset: 0x8006DCEC
			// Variables:
		// 		struct PhysObWeaponProperties *prop; // $s3

			/* begin block 1.1.1 */
				// Start line: 3709
				// Start offset: 0x8006DE10
				// Variables:
			// 		int damage; // $s3
			/* end block 1.1.1 */
			// End offset: 0x8006DE6C
			// End Line: 3715
		/* end block 1.1 */
		// End offset: 0x8006DECC
		// End Line: 3724
	/* end block 1 */
	// End offset: 0x8006DED0
	// End Line: 3731

	/* begin block 2 */
		// Start line: 7964
	/* end block 2 */
	// End Line: 7965

/* File: C:\kain2\game\PHYSOBS.C */

int GetPhysObCollisionType(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  ulong uVar2;
  int Data;
  _Instance *Inst;
  int Power;
  undefined *Message;
  _Instance *Sender;
  void *pvVar3;
  uint *puVar4;
  void *pvVar5;
  
  puVar4 = (uint *)instance->extraData;
  pvVar5 = instance->collideInfo;
  if ((*puVar4 & 0x1600001) != 0) {
    return 0;
  }
  if ((*(uint *)((int)pvVar5 + 4) & 0xffff0000) != 0x1010000) {
    return 0;
  }
  if (*(char *)(*(int *)((int)pvVar5 + 8) + 4) != '\t') {
    return 0;
  }
  if (*(char *)(*(int *)((int)pvVar5 + 0xc) + 4) != '\b') {
    return 0;
  }
  Sender = *(_Instance **)((int)pvVar5 + 0x14);
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 == (PhysObWeaponAttributes *)0x0) {
    return 0;
  }
  pvVar3 = instance->data;
  TurnOffCollisionPhysOb(instance,7);
  if (instance->LinkParent == (_Instance *)0x0) {
    uVar2 = INSTANCE_Query(Sender,0);
    if ((uVar2 & 0x10000000) == 0) {
LAB_8006dda8:
      Data = SetMonsterHitData(instance,(_Instance *)0x0,pPVar1->Damage,
                               (int)pPVar1->knockBackDistance,(int)pPVar1->knockBackFrames);
      Power = 0x1000000;
      Inst = Sender;
LAB_8006ddd0:
      INSTANCE_Post(Inst,Power,Data);
    }
    else {
      if ((*(ushort *)((int)pvVar3 + 6) & 0x200) == 0) {
        Data = CheckPhysObAbility(instance,0x20);
        if ((Data == 0) || ((*puVar4 & 0x10000) == 0)) goto LAB_8006dda8;
        INSTANCE_Post(Sender,0x100000c,0x20);
        Power = 0x800029;
        Data = 0;
        Inst = instance;
        goto LAB_8006ddd0;
      }
      INSTANCE_Post(Sender,0x1000019,(int)instance);
      *puVar4 = *puVar4 & 0xffffffef;
    }
    Data = CheckPhysObFamily(instance,7);
    if ((Data == 0) || (instance->parent != DAT_800d20f8)) goto LAB_8006de70;
    Message = &LAB_00080000_1;
    Data = 0;
    Inst = Sender;
  }
  else {
    Power = pPVar1->Damage;
    Data = CheckPhysObAbility(instance,0x20);
    if ((Data != 0) && ((*puVar4 & 0x10000) == 0)) {
      Power = pPVar1->AltDamage;
    }
    Data = SetMonsterHitData(Sender,(_Instance *)0x0,Power,0,0);
    Message = (undefined *)0x2000002;
    Inst = instance->LinkParent;
  }
  INSTANCE_Post(Inst,(int)Message,Data);
LAB_8006de70:
  Data = CheckPhysObAbility(instance,0x20);
  if ((Data == 0) || ((*puVar4 & 0x10000) == 0)) {
    Data = 0x100;
  }
  else {
    Data = 0x20;
  }
  Data = SetFXHitData(instance,(uint)*(byte *)((int)pvVar5 + 5),pPVar1->Damage >> 7,Data);
  INSTANCE_Post(Sender,0x400000,Data);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteThrow(struct _Instance *instance /*$s1*/)
 // line 3734, offset 0x8006def4
	/* begin block 1 */
		// Start line: 3735
		// Start offset: 0x8006DEF4
		// Variables:
	// 		struct PhysObData *Data; // $s2

		/* begin block 1.1 */
			// Start line: 3743
			// Start offset: 0x8006DF28
			// Variables:
		// 		short angley; // $s0
		// 		struct _Position zero; // stack offset -32
		// 		struct _Position velocity; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8006DF28
		// End Line: 3744
	/* end block 1 */
	// End offset: 0x8006DFEC
	// End Line: 3770

	/* begin block 2 */
		// Start line: 8165
	/* end block 2 */
	// End Line: 8166

/* File: C:\kain2\game\PHYSOBS.C */

void ExecuteThrow(_Instance *instance)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  void *pvVar5;
  _Position _Stack32;
  _Position local_18;
  
  pvVar5 = instance->extraData;
  if ((*(ushort *)((int)pvVar5 + 0x36) & 1) == 0) {
    (instance->rotation).x = (instance->rotation).x + *(short *)((int)pvVar5 + 0x3a);
    (instance->rotation).y = (instance->rotation).y + *(short *)((int)pvVar5 + 0x3c);
    (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar5 + 0x3e);
  }
  else {
    memset();
    local_18.x = *(short *)&instance->xVel;
    local_18.y = *(short *)&instance->yVel;
    local_18.z = *(short *)&instance->zVel;
    sVar2 = MATH3D_AngleFromPosToPos(&_Stack32,&local_18);
    sVar3 = MATH3D_ElevationFromPosToPos(&_Stack32,&local_18);
    sVar1 = *(short *)((int)pvVar5 + 0x38);
    (instance->rotation).z = sVar2;
    (instance->rotation).y = 0;
    (instance->rotation).x = sVar1 + sVar3;
    MATH3D_ZYXtoXYZ(&instance->rotation);
  }
  iVar4 = *(int *)((int)pvVar5 + 0x44) - DAT_800d2314;
  *(int *)((int)pvVar5 + 0x44) = iVar4;
  if (iVar4 < 0) {
    INSTANCE_KillInstance(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteDrag(struct _Instance *instance /*$s1*/)
 // line 3774, offset 0x8006e004
	/* begin block 1 */
		// Start line: 3775
		// Start offset: 0x8006E004
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006E098
	// End Line: 3809

	/* begin block 2 */
		// Start line: 8256
	/* end block 2 */
	// End Line: 8257

/* File: C:\kain2\game\PHYSOBS.C */

void ExecuteDrag(_Instance *instance)

{
  short sVar1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 2) != 0) {
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  if ((*puVar2 & 0x100000) == 0) {
    G2EmulationInstancePlayAnimation(instance);
  }
  else {
    puVar2[2] = 0;
    FinishPush(instance);
    *puVar2 = *puVar2 & 0xffeffeb5 | 1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteSlideToStop(struct _Instance *instance /*$s1*/)
 // line 3813, offset 0x8006e0ac
	/* begin block 1 */
		// Start line: 3814
		// Start offset: 0x8006E0AC
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006E124
	// End Line: 3842

	/* begin block 2 */
		// Start line: 8334
	/* end block 2 */
	// End Line: 8335

/* File: C:\kain2\game\PHYSOBS.C */

void ExecuteSlideToStop(_Instance *instance)

{
  short sVar1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x100000) == 0) {
    G2EmulationInstancePlayAnimation(instance);
  }
  else {
    puVar2[2] = 0;
    FinishPush(instance);
    *puVar2 = *puVar2 & 0xffefeeb5 | 1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteFlip(struct _Instance *instance /*$s1*/)
 // line 3846, offset 0x8006e138
	/* begin block 1 */
		// Start line: 3847
		// Start offset: 0x8006E138
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006E1E4
	// End Line: 3879

	/* begin block 2 */
		// Start line: 8400
	/* end block 2 */
	// End Line: 8401

/* File: C:\kain2\game\PHYSOBS.C */

void ExecuteFlip(_Instance *instance)

{
  short sVar1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 2) != 0) {
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  if ((*puVar2 & 0x100000) == 0) {
    G2EmulationInstancePlayAnimation(instance);
  }
  else {
    if (*(short *)(puVar2 + 10) == 0xe) {
      instance->zVel = -0x32;
    }
    ResetOrientation(instance);
    puVar2[2] = 0;
    *puVar2 = *puVar2 & 0xffefeeb5 | 1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckSlope(int Znormal /*$a0*/, int Slope /*$a1*/, int Slop /*$a2*/)
 // line 3939, offset 0x8006e1f8
	/* begin block 1 */
		// Start line: 8588
	/* end block 1 */
	// End Line: 8589

	/* begin block 2 */
		// Start line: 8589
	/* end block 2 */
	// End Line: 8590

/* File: C:\kain2\game\PHYSOBS.C */

int CheckSlope(int Znormal,int Slope,int Slop)

{
  uint uVar1;
  
  uVar1 = 0;
  if (Slope - Slop < Znormal) {
    uVar1 = (uint)(Znormal < Slope + Slop);
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckBlockSlope(struct _Instance *instance /*$a0*/, int x /*$a1*/, int y /*$a2*/, int hOff /*$a3*/, int vOff /*stack 16*/, int dH /*stack 20*/, int dV /*stack 24*/)
 // line 3948, offset 0x8006e218
	/* begin block 1 */
		// Start line: 3949
		// Start offset: 0x8006E218
		// Variables:
	// 		struct _PCollideInfo CInfo; // stack offset -72
	// 		struct SVECTOR Old; // stack offset -24
	// 		struct SVECTOR New; // stack offset -16
	// 		int xOff; // $t3
	// 		int yOff; // $t4
	// 		int dX; // $t2
	// 		int dY; // $t6
	// 		struct MATRIX *mat; // $v0
	/* end block 1 */
	// End offset: 0x8006E218
	// End Line: 3949

	/* begin block 2 */
		// Start line: 8606
	/* end block 2 */
	// End Line: 8607

	/* begin block 3 */
		// Start line: 8609
	/* end block 3 */
	// End Line: 8610

/* File: C:\kain2\game\PHYSOBS.C */

int CheckBlockSlope(_Instance *instance,int x,int y,int hOff,int vOff,int dH,int dV)

{
  MATRIX *pMVar1;
  _PCollideInfo local_48;
  SVECTOR local_18;
  SVECTOR local_10;
  
  local_48.oldPoint = &local_18;
  local_48.newPoint = &local_10;
  pMVar1 = instance->matrix;
  local_18.vx = *(short *)pMVar1->t + (short)x * (short)hOff;
  local_18.vy = *(short *)(pMVar1->t + 1) + (short)y * (short)hOff;
  local_18.vz = *(short *)(pMVar1->t + 2) + (short)vOff;
  local_10.vz = local_18.vz + (short)dV;
  local_10.vx = local_18.vx + (short)x * (short)dH;
  local_10.vy = local_18.vy + (short)y * (short)dH;
  PHYSICS_CheckLineInWorld(instance,&local_48);
  return (uint)(local_48.type == 5);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOBS_FigureDragForSlope(struct _Instance *instance /*$a0*/, int pathNumber /*$s1*/, int *result /*$s2*/)
 // line 3991, offset 0x8006e2d8
	/* begin block 1 */
		// Start line: 3992
		// Start offset: 0x8006E2D8
		// Variables:
	// 		int didSomething; // $s0
	/* end block 1 */
	// End offset: 0x8006E33C
	// End Line: 4022

	/* begin block 2 */
		// Start line: 8758
	/* end block 2 */
	// End Line: 8759

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOBS_FigureDragForSlope(_Instance *instance,int pathNumber,int *result)

{
  _Instance *p_Var1;
  int iVar2;
  
  p_Var1 = PHYSOBS_IsAPushBlockAttached(instance);
  if ((((p_Var1 != (_Instance *)0x0) || (pathNumber == 5)) || (pathNumber == 1)) ||
     (((pathNumber == 7 || (pathNumber == 4)) || ((pathNumber == 2 || (iVar2 = 0, pathNumber == 3)))
      ))) {
    *result = 0;
    iVar2 = 1;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckThrownLineCollision(struct _Instance *instance /*$s3*/, struct _Instance *parent /*$s0*/)
 // line 4026, offset 0x8006e358
	/* begin block 1 */
		// Start line: 4027
		// Start offset: 0x8006E358
		// Variables:
	// 		struct _PCollideInfo pcollideInfo; // stack offset -112
	// 		struct _Position newPos; // stack offset -64
	// 		struct _Position oldPos; // stack offset -56
	// 		struct _Position orgNew; // stack offset -48
	// 		struct MATRIX *mat; // $v1
	// 		struct PhysObWeaponAttributes *weapon; // $v0

		/* begin block 1.1 */
			// Start line: 4051
			// Start offset: 0x8006E3B8
			// Variables:
		// 		struct _SVector line; // stack offset -40
		// 		struct _SVector delta; // stack offset -32
		// 		long dp; // $s0

			/* begin block 1.1.1 */
				// Start line: 4082
				// Start offset: 0x8006E468
				// Variables:
			// 		short _x0; // $a0
			// 		short _y0; // $v0
			// 		short _z0; // $v1
			// 		short _y1; // $a1
			// 		short _z1; // $a2
			// 		struct _SVector *_v; // $s1
			// 		struct _Position *_v0; // $v1
			// 		struct _Position *_v1; // $s2
			/* end block 1.1.1 */
			// End offset: 0x8006E468
			// End Line: 4082

			/* begin block 1.1.2 */
				// Start line: 4086
				// Start offset: 0x8006E514
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _y1; // $a1
			// 		short _z1; // $a2
			/* end block 1.1.2 */
			// End offset: 0x8006E548
			// End Line: 4087
		/* end block 1.1 */
		// End offset: 0x8006E548
		// End Line: 4090

		/* begin block 1.2 */
			// Start line: 4092
			// Start offset: 0x8006E548
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a2
		// 		struct _Position *_v0; // $s0
		/* end block 1.2 */
		// End offset: 0x8006E548
		// End Line: 4092

		/* begin block 1.3 */
			// Start line: 4114
			// Start offset: 0x8006E608
			// Variables:
		// 		short _x0; // $t0
		// 		short _y0; // $t1
		// 		short _z0; // $t2
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a2
		/* end block 1.3 */
		// End offset: 0x8006E608
		// End Line: 4114

		/* begin block 1.4 */
			// Start line: 4114
			// Start offset: 0x8006E608
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a2
		// 		struct _Position *_v; // $a3
		/* end block 1.4 */
		// End offset: 0x8006E608
		// End Line: 4114
	/* end block 1 */
	// End offset: 0x8006E60C
	// End Line: 4115

	/* begin block 2 */
		// Start line: 8828
	/* end block 2 */
	// End Line: 8829

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_CheckThrownLineCollision(_Instance *instance,_Instance *parent)

{
  PhysObWeaponAttributes *pPVar1;
  int iVar2;
  long lVar3;
  MATRIX *pMVar4;
  int iVar5;
  int iVar6;
  _PCollideInfo local_70;
  SVECTOR local_40;
  SVECTOR local_38;
  ushort local_30;
  short local_2e;
  short local_2c;
  short local_28;
  short local_26;
  short local_24;
  undefined2 local_20;
  undefined2 local_1e;
  
  pMVar4 = instance->oldMatrix;
  if (pMVar4 != (MATRIX *)0x0) {
    local_38.vx = *(ushort *)pMVar4[2].t;
    local_38.vy = *(ushort *)(pMVar4[2].t + 1);
    local_38.vz = *(short *)(pMVar4[2].t + 2);
    pPVar1 = PhysObGetWeapon(instance);
    if (pPVar1 != (PhysObWeaponAttributes *)0x0) {
      pMVar4 = instance->matrix + pPVar1->ThrowSphere;
      local_40.vx = *(ushort *)pMVar4->t;
      local_40.vy = *(short *)(pMVar4->t + 1);
      local_40.vz = *(short *)(pMVar4->t + 2);
      iVar2 = rsin((int)(parent->rotation).z);
      local_28 = (short)iVar2;
      iVar2 = rcos((int)(parent->rotation).z);
      local_26 = -(short)iVar2;
      local_24 = 0;
      iVar2 = (uint)(ushort)(parent->position).x - (uint)local_38.vx;
      local_20 = (undefined2)iVar2;
      iVar5 = (uint)(ushort)(parent->position).y - (uint)local_38.vy;
      iVar2 = (iVar2 * 0x10000 >> 0x10) * (int)local_28 + (iVar5 * 0x10000 >> 0x10) * (int)local_26;
      local_1e = (undefined2)iVar5;
      if (0 < iVar2) {
        iVar5 = (uint)local_40.vx - (uint)local_38.vx;
        local_26 = local_40.vy - local_38.vy;
        local_24 = local_40.vz - local_38.vz;
        local_28 = (short)iVar5;
        lVar3 = MATH3D_LengthXY(iVar5 * 0x10000 >> 0x10,(int)local_26);
        iVar2 = iVar2 / lVar3;
        iVar5 = local_28 * iVar2;
        if (iVar5 < 0) {
          iVar5 = iVar5 + 0xfff;
        }
        iVar6 = local_26 * iVar2;
        local_28 = (short)(iVar5 >> 0xc);
        if (iVar6 < 0) {
          iVar6 = iVar6 + 0xfff;
        }
        iVar2 = local_24 * iVar2;
        local_26 = (short)(iVar6 >> 0xc);
        if (iVar2 < 0) {
          iVar2 = iVar2 + 0xfff;
        }
        local_24 = (short)(iVar2 >> 0xc);
        local_38.vx = local_38.vx + local_28;
        local_38.vy = local_38.vy + local_26;
        local_38.vz = local_38.vz + local_24;
      }
      local_70.newPoint = &local_40;
      local_70.oldPoint = &local_38;
      local_30 = local_40.vx;
      local_2e = local_40.vy;
      local_2c = local_40.vz;
      PHYSICS_CheckLineInWorld(instance,&local_70);
      if (local_70.type != 0) {
        local_30 = local_40.vx - local_30;
        local_2e = local_40.vy - local_2e;
        local_2c = local_40.vz - local_2c;
        (instance->position).x = (instance->position).x + local_30;
        (instance->position).y = (instance->position).y + local_2e;
        (instance->position).z = (instance->position).z + local_2c;
        COLLIDE_UpdateAllTransforms(instance,0xd0);
        if (local_70.type == 3) {
          return 1;
        }
        return 2;
      }
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckDroppedLineCollision(struct _Instance *instance /*$s3*/, struct _Instance *parent /*$s6*/)
 // line 4121, offset 0x8006e628
	/* begin block 1 */
		// Start line: 4122
		// Start offset: 0x8006E628
		// Variables:
	// 		struct _PCollideInfo pcollideInfo; // stack offset -200
	// 		struct _Position parentPos; // stack offset -152
	// 		struct _Position newPos; // stack offset -144
	// 		struct _Position oldPos; // stack offset -136
	// 		struct _SVector offset; // stack offset -128
	// 		struct _Position basePos; // stack offset -120
	// 		int seg; // $s2
	// 		int collided; // $s5

		/* begin block 1.1 */
			// Start line: 4155
			// Start offset: 0x8006E6B4
			// Variables:
		// 		struct MATRIX *mat; // $v1

			/* begin block 1.1.1 */
				// Start line: 4157
				// Start offset: 0x8006E6B4
				// Variables:
			// 		short _y0; // $v1
			// 		short _z0; // $a0
			// 		short _y1; // $t0
			// 		short _z1; // $t1
			// 		struct _SVector *_v; // $s1
			// 		struct _Position *_v0; // $s0
			// 		struct _Position *_v1; // $s4
			/* end block 1.1.1 */
			// End offset: 0x8006E6B4
			// End Line: 4157

			/* begin block 1.1.2 */
				// Start line: 4168
				// Start offset: 0x8006E7B4
				// Variables:
			// 		short _y0; // $v1
			// 		short _z0; // $a1
			/* end block 1.1.2 */
			// End offset: 0x8006E7B4
			// End Line: 4168
		/* end block 1.1 */
		// End offset: 0x8006E840
		// End Line: 4184

		/* begin block 1.2 */
			// Start line: 4187
			// Start offset: 0x8006E860
			// Variables:
		// 		struct _SVector origin; // stack offset -112
		// 		struct _SVector node2; // stack offset -104
		// 		struct _SVector orgDir; // stack offset -96
		// 		struct _SVector newDir; // stack offset -88
		// 		struct _SVector axis; // stack offset -80
		// 		short angle; // $s0
		// 		struct MATRIX mat; // stack offset -72
		// 		struct _G2EulerAngles_Type ea; // stack offset -40

			/* begin block 1.2.1 */
				// Start line: 4192
				// Start offset: 0x8006E860
				// Variables:
			// 		short _y0; // $v0
			// 		short _z0; // $v1
			// 		short _y1; // $a3
			// 		short _z1; // $a1
			// 		struct _SVector *_v; // $s0
			// 		struct _SVector *_v0; // $v1
			// 		struct _SVector *_v1; // $a1
			/* end block 1.2.1 */
			// End offset: 0x8006E860
			// End Line: 4192
		/* end block 1.2 */
		// End offset: 0x8006E9EC
		// End Line: 4215
	/* end block 1 */
	// End offset: 0x8006E9FC
	// End Line: 4230

	/* begin block 2 */
		// Start line: 9051
	/* end block 2 */
	// End Line: 9052

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_CheckDroppedLineCollision(_Instance *instance,_Instance *parent)

{
  bool bVar1;
  short angle;
  int iVar2;
  int iVar3;
  MATRIX *pMVar4;
  int iVar5;
  _PCollideInfo local_c8;
  undefined4 local_98;
  short local_94;
  undefined4 local_90;
  short local_8c;
  SVECTOR local_88;
  short local_80;
  short local_7e;
  short local_7c;
  undefined4 local_78;
  short local_74;
  short local_70;
  short local_6e;
  short local_6c;
  short local_68;
  short local_66;
  short local_64;
  _Normal local_60;
  _SVector local_58;
  _SVector _Stack80;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  long local_34;
  long local_30;
  long local_2c;
  _G2EulerAngles_Type local_28;
  
  if (parent != (_Instance *)0x0) {
    local_98 = *(uint *)&parent->position;
    local_94 = (parent->position).z;
    bVar1 = false;
    if (instance->matrix != (MATRIX *)0x0) {
      iVar5 = 0;
      pMVar4 = instance->matrix;
      (instance->position).x = *(short *)instance->matrix->t;
      (instance->position).y = *(short *)(pMVar4->t + 1);
      (instance->position).z = *(short *)(pMVar4->t + 2);
      do {
        local_88.vy = local_98._2_2_;
        pMVar4 = instance->matrix + iVar5;
        local_88.vx = (short)local_98;
        local_88.vz = *(short *)(pMVar4->t + 2) + 100;
        iVar2 = ((int)(((uint)*(ushort *)pMVar4->t - (local_98 & 0xffff)) * 0x10000) >> 0x10) * 6000
        ;
        if (iVar2 < 0) {
          iVar2 = iVar2 + 0xfff;
        }
        iVar3 = (int)(short)(*(short *)(pMVar4->t + 1) - local_98._2_2_) * 6000;
        local_80 = (short)(iVar2 >> 0xc);
        if (iVar3 < 0) {
          iVar3 = iVar3 + 0xfff;
        }
        local_7e = (short)(iVar3 >> 0xc);
        iVar2 = (int)(short)(*(short *)(pMVar4->t + 2) - local_88.vz) * 6000;
        if (iVar2 < 0) {
          iVar2 = iVar2 + 0xfff;
        }
        local_7c = (short)(iVar2 >> 0xc);
        local_8c = local_7c + local_88.vz;
        local_90 = CONCAT22(local_7e + local_98._2_2_,local_80 + (short)local_98);
        local_78 = local_90;
        local_c8.newPoint = (SVECTOR *)&local_90;
        local_c8.oldPoint = &local_88;
        local_74 = local_8c;
        SetNoPtCollideInFamily(parent);
        PHYSICS_CheckLineInWorld(instance,&local_c8);
        ResetNoPtCollideInFamily(parent);
        if ((local_c8.type != 0) && (local_c8.wNormal.vz < 0xed9)) {
          bVar1 = true;
        }
        iVar5 = iVar5 + 2;
      } while ((iVar5 < 3) && (!bVar1));
      if (bVar1) {
        local_70 = *(short *)instance->matrix->t;
        local_6e = *(short *)(instance->matrix->t + 1);
        local_6c = *(short *)(instance->matrix->t + 2);
        local_68 = *(short *)instance->matrix[2].t;
        local_66 = *(short *)(instance->matrix[2].t + 1);
        local_64 = *(short *)(instance->matrix[2].t + 2);
        local_60.x = local_68 - local_70;
        local_60.y = local_66 - local_6e;
        local_60.z = local_64 - local_6c;
        MATH3D_Normalize(&local_60);
        local_58.x = 10;
        local_58.y = 0;
        local_58.z = 0x1000;
        angle = MATH3D_AngleBetweenVectors(&local_58,(_SVector *)&local_60);
        MATH3D_CrossProduct(&_Stack80,(_SVector *)&local_60,&local_58);
        pMVar4 = instance->matrix;
        local_48 = *(undefined4 *)pMVar4->m;
        local_44 = *(undefined4 *)(pMVar4->m + 2);
        local_40 = *(undefined4 *)(pMVar4->m + 4);
        local_3c = *(undefined4 *)(pMVar4->m + 6);
        local_38 = *(undefined4 *)(pMVar4->m + 8);
        local_34 = pMVar4->t[0];
        local_30 = pMVar4->t[1];
        local_2c = pMVar4->t[2];
        MATH3D_RotMatAboutVec(&_Stack80,(char)(_G2Matrix_Type *)&local_48,angle);
        G2EulerAngles_FromMatrix(&local_28,(_G2Matrix_Type *)&local_48,0);
        (instance->rotation).x = local_28.x;
        (instance->rotation).y = local_28.y;
        (instance->rotation).z = local_28.z;
        angle = (parent->position).z;
        *(undefined4 *)&instance->position = *(undefined4 *)&parent->position;
        (instance->position).z = angle;
      }
      (instance->position).z = (instance->position).z + 0x14;
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckDirectedLineCollision(struct _Instance *instance /*$a0*/, int xoffset /*$a1*/, int yoffset /*$a2*/, int startZOffset /*$a3*/)
 // line 4234, offset 0x8006ea24
	/* begin block 1 */
		// Start line: 4235
		// Start offset: 0x8006EA24
		// Variables:
	// 		struct _PCollideInfo pcollideInfo; // stack offset -72
	// 		struct _Position newPos; // stack offset -24
	// 		struct _Position oldPos; // stack offset -16
	// 		struct MATRIX *mat; // $v0
	/* end block 1 */
	// End offset: 0x8006EA24
	// End Line: 4235

	/* begin block 2 */
		// Start line: 9371
	/* end block 2 */
	// End Line: 9372

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_CheckDirectedLineCollision(_Instance *instance,int xoffset,int yoffset,int startZOffset)

{
  MATRIX *pMVar1;
  _PCollideInfo local_48;
  SVECTOR local_18;
  SVECTOR local_10;
  
  pMVar1 = instance->matrix;
  local_10.vx = *(short *)pMVar1[1].t;
  local_18.vx = local_10.vx + (short)xoffset;
  local_10.vy = *(short *)(pMVar1[1].t + 1);
  local_18.vy = local_10.vy + (short)yoffset;
  local_48.newPoint = &local_18;
  local_48.oldPoint = &local_10;
  local_18.vz = *(short *)(pMVar1[1].t + 2) + (short)startZOffset;
  local_10.vz = local_18.vz;
  PHYSICS_CheckLineInWorld(instance,&local_48);
  return (int)local_48.type;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PHYSOBS_CheckForStackedForwardHits(struct _Instance *block /*$a0*/, long xoffset /*$s2*/, long yoffset /*$s3*/)
 // line 4255, offset 0x8006ea98
	/* begin block 1 */
		// Start line: 4256
		// Start offset: 0x8006EA98
		// Variables:
	// 		struct _Instance *attachedBlock; // $s0
	// 		long result; // $s1
	/* end block 1 */
	// End offset: 0x8006EAF4
	// End Line: 4275

	/* begin block 2 */
		// Start line: 9437
	/* end block 2 */
	// End Line: 9438

/* File: C:\kain2\game\PHYSOBS.C */

long PHYSOBS_CheckForStackedForwardHits(_Instance *block,long xoffset,long yoffset)

{
  int iVar1;
  
  do {
    block = PHYSOBS_IsAPushBlockAttached(block);
    if (block == (_Instance *)0x0) {
      return 0;
    }
    iVar1 = PHYSOB_CheckDirectedLineCollision(block,xoffset,yoffset,0);
  } while (iVar1 == 0);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOBS_SetNewAnim(struct _Instance *instance /*$s1*/, struct PhysObData *Data /*$s0*/, unsigned long modeBits /*$a2*/, int path /*$s2*/, int resetflg /*stack 16*/)
 // line 4278, offset 0x8006eb14
	/* begin block 1 */
		// Start line: 9485
	/* end block 1 */
	// End Line: 9486

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOBS_SetNewAnim(_Instance *instance,PhysObData *Data,ulong modeBits,int path,int resetflg)

{
  Data->PathNumber = (short)path;
  Data->Mode = Data->Mode & 0xfffffffeU | modeBits;
  if (resetflg != 0) {
    ResetOrientation(instance);
  }
  PhysOb_AlignPush(instance,(int)Data->xForce,(int)Data->yForce,path,Data);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PHYSOB_CheckForEnemyInBlkSpot(struct _Instance *instance /*$a0*/, int dx /*$a1*/, int dy /*$a2*/)
 // line 4291, offset 0x8006eb8c
	/* begin block 1 */
		// Start line: 4292
		// Start offset: 0x8006EB8C
		// Variables:
	// 		int x; // $v0
	// 		int y; // $v1
	// 		int z; // $v0
	// 		int x0; // $s6
	// 		int x1; // $s5
	// 		int y0; // $s4
	// 		int y1; // $s3
	// 		int z0; // $s2
	// 		int z1; // $s1
	// 		struct _Instance *inst; // $s0
	/* end block 1 */
	// End offset: 0x8006EC98
	// End Line: 4314

	/* begin block 2 */
		// Start line: 9514
	/* end block 2 */
	// End Line: 9515

/* File: C:\kain2\game\PHYSOBS.C */

long PHYSOB_CheckForEnemyInBlkSpot(_Instance *instance,int dx,int dy)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  _Instance *Inst;
  
  dy = (instance->position).y + dy;
  Inst = *(_Instance **)(DAT_800d2100 + 4);
  dx = (instance->position).x + dx;
  iVar1 = (int)(instance->position).z;
  while( true ) {
    if (Inst == (_Instance *)0x0) {
      return 0;
    }
    if (((((((Inst->object->oflags2 & 0x80000U) != 0) && ((Inst->flags2 & 0x8000000U) == 0)) &&
          (uVar2 = INSTANCE_Query(Inst,0), (uVar2 & 0x40000000) == 0)) &&
         ((iVar3 = (int)(Inst->position).x, dx + -0x140 <= iVar3 && (iVar3 <= dx + 0x140)))) &&
        ((iVar3 = (int)(Inst->position).y, dy + -0x140 <= iVar3 &&
         ((iVar3 <= dy + 0x140 && (iVar3 = (int)(Inst->position).z, iVar1 + -0x140 <= iVar3)))))) &&
       (iVar3 <= iVar1 + 0x140)) break;
    Inst = Inst->next;
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PHYSOBS_CheckForValidMove(struct _Instance *instance /*$s2*/)
 // line 4317, offset 0x8006ecc0
	/* begin block 1 */
		// Start line: 4318
		// Start offset: 0x8006ECC0
		// Variables:
	// 		int rc; // $s1
	// 		struct PhysObData *Data; // $s0
	// 		struct evPhysicsSlideData *Ptr; // stack offset -32
	// 		int result; // stack offset -28

		/* begin block 1.1 */
			// Start line: 4403
			// Start offset: 0x8006EE1C
			// Variables:
		// 		int Height; // $v0
		/* end block 1.1 */
		// End offset: 0x8006EE6C
		// End Line: 4416

		/* begin block 1.2 */
			// Start line: 4640
			// Start offset: 0x8006F0D8
			// Variables:
		// 		struct evPhysicsSlideData *Ptr; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x8006F1D0
		// End Line: 4687
	/* end block 1 */
	// End offset: 0x8006F1F0
	// End Line: 4696

	/* begin block 2 */
		// Start line: 9581
	/* end block 2 */
	// End Line: 9582

/* File: C:\kain2\game\PHYSOBS.C */

long PHYSOBS_CheckForValidMove(_Instance *instance)

{
  short sVar1;
  ushort uVar2;
  int Data;
  long lVar3;
  uint uVar4;
  uint uVar5;
  PhysObData *Data_00;
  evPhysicsSlideData *local_20;
  uint local_1c;
  evPhysicsSlideData *local_18 [2];
  
  DAT_800d22ec = 1;
  Data_00 = (PhysObData *)instance->extraData;
  local_1c = 7;
  if ((Data_00->Mode & 1U) == 0) goto LAB_8006f1d4;
  Data = SetPhysicsGravityData(0xa0,0x280,0,0,0,0xb50);
  PhysicsUpdateTface(instance,Data);
  lVar3 = PHYSOBS_CheckForStackedForwardHits
                    (instance,(int)Data_00->xForce * 0x2c0,(int)Data_00->yForce * 0x2c0);
  if (lVar3 == 0) {
    uVar4 = PHYSOB_CheckSlide(instance,(int)Data_00->xForce,(int)Data_00->yForce,&local_20);
    if ((uVar4 & 2) == 0) {
      if ((uVar4 & 0x4000) == 0) {
        uVar5 = PHYSOB_CheckDropOnSlope(instance,(int)Data_00->xForce,(int)Data_00->yForce,local_18)
        ;
        if (((uVar5 & 0x4000) == 0) || (0xf3c < (local_18[0]->DropNormal).z)) {
          if (((Data_00->Mode & 8U) != 0) && ((uVar4 & 0x8000) != 0)) {
            local_1c = 0;
          }
          uVar2 = Data_00->PathNumber;
          if ((1 < (uint)uVar2 - 2) && (local_1c != 0)) {
            if ((int)(short)uVar2 == 5) {
              local_1c = local_1c & 0xfffffffa;
            }
            else {
              if ((Data_00->Mode & 8U) == 0) {
                PHYSOBS_SetNewAnim(instance,Data_00,2,(int)(short)uVar2,1);
              }
              else {
                Data_00->PathNumber = 0xe;
                PHYSOBS_SetNewAnim(instance,Data_00,2,0xe,1);
              }
            }
            goto LAB_8006f1d4;
          }
        }
      }
      else {
        if ((Data_00->Mode & 8U) != 0) {
          if ((Data_00->Mode & 0x200U) != 0) {
            local_1c = 0;
          }
          if (((uVar4 & 0x8000) != 0) ||
             (Data = PHYSOB_CheckDirectedLineCollision
                               (instance,(int)Data_00->xForce * 0x2c0,(int)Data_00->yForce * 0x2c0,
                                0x280), Data != 0)) {
            local_1c = 0;
          }
        }
        if (local_1c == 0) goto LAB_8006f1d4;
        Data = CheckSlope(local_20->Dot,-0x13a,4);
        if (((Data == 0) && (Data = CheckSlope(local_20->Dot,0x13a,4), Data == 0)) &&
           ((Data_00->Mode & 0x200U) == 0)) {
          Data = CheckSlope((int)(local_20->DropNormal).z,0xe4f,4);
          if (Data == 0) {
            lVar3 = PHYSOB_CheckForEnemyInBlkSpot
                              (instance,(int)Data_00->xForce * 0x280,(int)Data_00->yForce * 0x280);
            if (((lVar3 == 0) ||
                (Data = PHYSOB_CheckDirectedLineCollision
                                  (instance,(int)Data_00->xForce * 0x540,
                                   (int)Data_00->yForce * 0x540,0), Data == 0)) &&
               (Data = CheckSlope((int)(local_20->DropNormal).z,0x1000,4), Data != 0)) {
              PHYSOBS_SetNewAnim(instance,Data_00,2,(int)Data_00->PathNumber,0);
              goto LAB_8006f1d4;
            }
          }
          else {
            sVar1 = (local_20->DropNormal).x;
            if ((((((10 < sVar1) && (0 < Data_00->xForce)) ||
                  ((sVar1 < -10 && (Data_00->xForce < 0)))) ||
                 ((sVar1 = (local_20->DropNormal).y, 10 < sVar1 && (0 < Data_00->yForce)))) ||
                ((sVar1 < -10 && (Data_00->yForce < 0)))) &&
               (Data = CheckBlockSlope(instance,(int)Data_00->xForce,(int)Data_00->yForce,0x2dc,
                                       -0xad,0x271,-0x138), Data == 0)) {
              Data = PHYSOBS_FigureDragForSlope(instance,(int)Data_00->PathNumber,(int *)&local_1c);
              if (Data == 0) {
                local_1c = 0;
              }
              goto LAB_8006f1d4;
            }
          }
        }
      }
    }
    else {
      Data = CheckSlope((int)(local_20->ForwardNormal).z,0xe4f,4);
      if (((((Data == 0) &&
            (Data = CheckSlope((int)(local_20->ForwardNormal).z,0x1000,4), Data == 0)) &&
           ((Data_00->Mode & 8U) != 0)) &&
          (((uVar4 & 4) != 0 &&
           (Data = PHYSOB_CheckDirectedLineCollision
                             (instance,(int)Data_00->xForce * 0x2c0,(int)Data_00->yForce * 0x2c0,
                              0x280), Data == 0)))) && (0xa9U - (int)local_20->Height < 0x13)) {
        PHYSOBS_SetNewAnim(instance,Data_00,2,7,1);
        local_1c = local_1c & 0xfffffffb | 8;
        goto LAB_8006f1d4;
      }
    }
  }
  local_1c = 0;
LAB_8006f1d4:
  DAT_800d22ec = 0;
  if (local_1c == 0) {
    Data_00->Mode = Data_00->Mode & 0xfffffeb5;
  }
  return local_1c;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteGravitate(struct _Instance *instance /*$s1*/)
 // line 4700, offset 0x8006f20c
	/* begin block 1 */
		// Start line: 4701
		// Start offset: 0x8006F20C
		// Variables:
	// 		struct PhysObData *Data; // $s0
	// 		struct _Instance *Force; // $s4
	// 		struct _G2EulerAngles_Type ea; // stack offset -48
	// 		struct _Vector Position; // stack offset -40
	// 		struct _Model *model; // $s3
	// 		struct MATRIX *forceMatrix; // $s2
	// 		int scale; // $v1
	/* end block 1 */
	// End offset: 0x8006F560
	// End Line: 4817

	/* begin block 2 */
		// Start line: 10369
	/* end block 2 */
	// End Line: 10370

/* File: C:\kain2\game\PHYSOBS.C */

void ExecuteGravitate(_Instance *instance)

{
  int iVar1;
  short sVar2;
  MATRIX *pMVar3;
  uint *puVar4;
  _G2Matrix_Type *matrix;
  _Model *p_Var5;
  _Instance *parent;
  _G2EulerAngles_Type local_30;
  VECTOR local_28;
  
  puVar4 = (uint *)instance->extraData;
  parent = (_Instance *)puVar4[2];
  p_Var5 = *instance->object->modelList;
  matrix = (_G2Matrix_Type *)(parent->matrix + *(short *)(puVar4 + 3));
  iVar1 = CheckPhysObAbility(instance,1);
  if (iVar1 != 0) {
    COLLIDE_SegmentCollisionOff(instance,1);
  }
  if (*(short *)(puVar4 + 9) != 0) {
    G2EulerAngles_FromMatrix(&local_30,matrix,0x15);
    if (*(short *)((int)puVar4 + 0x26) == 0) {
      *(short *)(puVar4 + 5) = (instance->rotation).x;
      *(short *)((int)puVar4 + 0x16) = (instance->rotation).y;
      *(short *)(puVar4 + 6) = (instance->rotation).z;
      *(short *)((int)puVar4 + 0xe) = (instance->position).x;
      *(short *)(puVar4 + 4) = (instance->position).y;
      *(short *)((int)puVar4 + 0x12) = (instance->position).z;
    }
    (instance->rotation).x =
         *(short *)(puVar4 + 5) +
         (short)((((int)local_30.x - (int)*(short *)(puVar4 + 5)) *
                 (int)*(short *)((int)puVar4 + 0x26)) / (int)*(short *)(puVar4 + 9));
    (instance->rotation).y =
         *(short *)((int)puVar4 + 0x16) +
         (short)((((int)local_30.y - (int)*(short *)((int)puVar4 + 0x16)) *
                 (int)*(short *)((int)puVar4 + 0x26)) / (int)*(short *)(puVar4 + 9));
    pMVar3 = instance->matrix;
    (instance->rotation).z =
         *(short *)(puVar4 + 6) +
         (short)((((int)local_30.z - (int)*(short *)(puVar4 + 6)) *
                 (int)*(short *)((int)puVar4 + 0x26)) / (int)*(short *)(puVar4 + 9));
    ApplyMatrix(pMVar3 + 2,(SVECTOR *)&p_Var5->segmentList[2].px,&local_28);
    local_28.vx = (matrix->trans).x - local_28.vx;
    local_28.vy = (matrix->trans).y - local_28.vy;
    local_28.vz = (matrix->trans).z - local_28.vz;
    (instance->position).x =
         *(short *)((int)puVar4 + 0xe) +
         (short)(((local_28.vx - *(short *)((int)puVar4 + 0xe)) *
                 (int)*(short *)((int)puVar4 + 0x26)) / (int)*(short *)(puVar4 + 9));
    (instance->position).y =
         *(short *)(puVar4 + 4) +
         (short)(((local_28.vy - *(short *)(puVar4 + 4)) * (int)*(short *)((int)puVar4 + 0x26)) /
                (int)*(short *)(puVar4 + 9));
    (instance->position).z =
         *(short *)((int)puVar4 + 0x12) +
         (short)(((local_28.vz - *(short *)((int)puVar4 + 0x12)) *
                 (int)*(short *)((int)puVar4 + 0x26)) / (int)*(short *)(puVar4 + 9));
    *(short *)((int)puVar4 + 0x26) = *(short *)((int)puVar4 + 0x26) + 1;
  }
  if ((*puVar4 & 0x20000) != 0) {
    if ((int)*(short *)(puVar4 + 9) == 0) {
      sVar2 = 0x1000;
    }
    else {
      sVar2 = 0x1000 - (short)(((int)*(short *)((int)puVar4 + 0x26) << 0xc) /
                              (int)*(short *)(puVar4 + 9));
    }
    (instance->scale).z = sVar2;
    (instance->scale).y = sVar2;
    (instance->scale).x = sVar2;
  }
  if (*(short *)((int)puVar4 + 0x26) == *(short *)(puVar4 + 9)) {
    if ((*puVar4 & 0x20000) == 0) {
      *puVar4 = *puVar4 & 0xfefdbffa | 0x1080;
      TurnOffCollisionPhysOb(instance,7);
      INSTANCE_LinkToParent(instance,parent,(int)*(short *)(puVar4 + 3));
      puVar4[2] = 0;
      *(undefined2 *)((int)puVar4 + 0x26) = 0;
      *(undefined2 *)(puVar4 + 9) = 0;
      instance->xVel = 0;
      instance->yVel = 0;
      instance->zVel = 0;
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->zAccl = 0;
    }
    else {
      INSTANCE_KillInstance(instance);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteFollow(struct _Instance *instance /*$a0*/)
 // line 4820, offset 0x8006f580
	/* begin block 1 */
		// Start line: 4822
		// Start offset: 0x8006F580
		// Variables:
	// 		struct PhysObData *Data; // $a1
	// 		struct _Instance *Force; // $a2
	/* end block 1 */
	// End offset: 0x8006F580
	// End Line: 4825

	/* begin block 2 */
		// Start line: 10651
	/* end block 2 */
	// End Line: 10652

	/* begin block 3 */
		// Start line: 10652
	/* end block 3 */
	// End Line: 10653

	/* begin block 4 */
		// Start line: 10655
	/* end block 4 */
	// End Line: 10656

/* File: C:\kain2\game\PHYSOBS.C */

void ExecuteFollow(_Instance *instance)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = instance->extraData;
  iVar2 = *(int *)((int)pvVar1 + 8);
  (instance->position).x =
       *(short *)((int)*(short *)((int)pvVar1 + 0x1a) * 0x20 + *(int *)(iVar2 + 0x40) + 0x14) +
       *(short *)((int)pvVar1 + 0xe);
  (instance->position).y =
       *(short *)((int)*(short *)((int)pvVar1 + 0x1a) * 0x20 + *(int *)(iVar2 + 0x40) + 0x18) +
       *(short *)((int)pvVar1 + 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_Normalize(struct _SVector *v /*$s0*/)
 // line 4842, offset 0x8006f5d8
	/* begin block 1 */
		// Start line: 4843
		// Start offset: 0x8006F5D8
		// Variables:
	// 		long len; // $a1
	/* end block 1 */
	// End offset: 0x8006F61C
	// End Line: 4850

	/* begin block 2 */
		// Start line: 10695
	/* end block 2 */
	// End Line: 10696

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_Normalize(_SVector *v)

{
  ulong square;
  long lVar1;
  
  square = MATH3D_SquareLength((int)v->x,(int)v->y,(int)v->z);
  if (square == 0) {
    lVar1 = 1;
  }
  else {
    lVar1 = MATH3D_FastSqrt0(square);
  }
  v->x = (short)(((int)v->x << 0xc) / lVar1);
  v->y = (short)(((int)v->y << 0xc) / lVar1);
  v->z = (short)(((int)v->z << 0xc) / lVar1);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_MoveTowardsAlign(struct _Instance *instance /*$s2*/, struct _SVector *orgVec /*$s0*/, struct _SVector *endVec /*$s1*/)
 // line 4857, offset 0x8006f674
	/* begin block 1 */
		// Start line: 4858
		// Start offset: 0x8006F674
		// Variables:
	// 		struct MATRIX xform; // stack offset -104
	// 		struct MATRIX dest; // stack offset -72
	// 		struct MATRIX *src; // $s4
	// 		struct _G2Quat_Type rot; // stack offset -40
	// 		long len; // $s0
	// 		int theta; // $s1
	// 		int sintheta; // $v0
	// 		struct _G2EulerAngles_Type ea; // stack offset -32
	/* end block 1 */
	// End offset: 0x8006F858
	// End Line: 4902

	/* begin block 2 */
		// Start line: 10727
	/* end block 2 */
	// End Line: 10728

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_MoveTowardsAlign(_Instance *instance,_SVector *orgVec,_SVector *endVec)

{
  int iVar1;
  int a;
  ulong square;
  long lVar2;
  MATRIX *m1;
  MATRIX MStack104;
  _G2Matrix_Type _Stack72;
  short local_28;
  short local_26;
  short local_24;
  undefined2 local_22;
  _G2EulerAngles_Type local_20;
  
  iVar1 = DAT_800d2314 * 0x32;
  PHYSOB_Normalize(orgVec);
  PHYSOB_Normalize(endVec);
  m1 = instance->matrix;
  a = (int)orgVec->y * (int)endVec->z - (int)orgVec->z * (int)endVec->y;
  if (a < 0) {
    a = a + 0xfff;
  }
  local_28 = (short)(a >> 0xc);
  a = (int)orgVec->z * (int)endVec->x - (int)orgVec->x * (int)endVec->z;
  if (a < 0) {
    a = a + 0xfff;
  }
  local_26 = (short)(a >> 0xc);
  a = (int)orgVec->x * (int)endVec->y - (int)orgVec->y * (int)endVec->x;
  if (a < 0) {
    a = a + 0xfff;
  }
  local_24 = (short)(a >> 0xc);
  a = (int)orgVec->x * (int)endVec->x + (int)orgVec->y * (int)endVec->y +
      (int)orgVec->z * (int)endVec->z;
  if (a < 0) {
    a = a + 0xfff;
  }
  a = MATH3D_racos_S(a >> 0xc);
  a = ((a << 0x10) >> 0x10) - ((a << 0x10) >> 0x1f) >> 1;
  iVar1 = (int)(short)(iVar1 >> 0xc);
  if (a < -iVar1) {
    a = -iVar1;
  }
  if (iVar1 < a) {
    a = iVar1;
  }
  square = MATH3D_SquareLength((int)local_28,(int)local_26,(int)local_24);
  if ((int)square < 1) {
    lVar2 = 0x1000;
  }
  else {
    lVar2 = MATH3D_FastSqrt0(square);
  }
  iVar1 = rsin(a);
  local_28 = (short)((local_28 * iVar1) / lVar2);
  local_26 = (short)((local_26 * iVar1) / lVar2);
  local_24 = (short)((local_24 * iVar1) / lVar2);
  iVar1 = rcos(a);
  local_22 = (undefined2)iVar1;
  G2Quat_ToMatrix_S(&local_28,(short *)&MStack104);
  MulMatrix0(&MStack104,m1,(MATRIX *)&_Stack72);
  G2EulerAngles_FromMatrix(&local_20,&_Stack72,0x15);
  (instance->rotation).x = local_20.x;
  (instance->rotation).y = local_20.y;
  (instance->rotation).z = local_20.z;
  return (uint)(a < 0x14);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_ReAlignFalling(struct _Instance *instance /*$s5*/, int zEndOff /*$fp*/)
 // line 4920, offset 0x8006f94c
	/* begin block 1 */
		// Start line: 4921
		// Start offset: 0x8006F94C
		// Variables:
	// 		struct _Model *model; // $s6
	// 		int i; // $s2
	// 		struct _Position seg0; // stack offset -208
	// 		struct _Position segn; // stack offset -200
	// 		struct _Position start0; // stack offset -192
	// 		struct _Position startn; // stack offset -184
	// 		int startFlg; // $s3
	// 		short zOff; // $s7

		/* begin block 1.1 */
			// Start line: 4932
			// Start offset: 0x8006F9B4
			// Variables:
		// 		struct _PCollideInfo pcollideInfo; // stack offset -176
		// 		struct _Position newPos; // stack offset -128
		// 		struct _Position oldPos; // stack offset -120
		// 		short x; // $s1
		// 		short y; // $s0
		// 		struct MATRIX *mat; // $v0

			/* begin block 1.1.1 */
				// Start line: 4951
				// Start offset: 0x8006FA2C
				// Variables:
			// 		short ax; // $a1
			// 		short ay; // $a2
			/* end block 1.1.1 */
			// End offset: 0x8006FB24
			// End Line: 4981

			/* begin block 1.1.2 */
				// Start line: 4989
				// Start offset: 0x8006FB50
			/* end block 1.1.2 */
			// End offset: 0x8006FC3C
			// End Line: 5017
		/* end block 1.1 */
		// End offset: 0x8006FC3C
		// End Line: 5019

		/* begin block 1.2 */
			// Start line: 5026
			// Start offset: 0x8006FC58
			// Variables:
		// 		short _x0; // $a3
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $t0
		// 		short _z1; // $a2
		// 		struct _Position *_v; // $a0
		// 		struct _Position *_v1; // $a2
		/* end block 1.2 */
		// End offset: 0x8006FC58
		// End Line: 5026

		/* begin block 1.3 */
			// Start line: 5026
			// Start offset: 0x8006FC58
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		short _x1; // $a2
		// 		short _y1; // $t1
		// 		short _z1; // $t0
		// 		struct _Position *_v; // $a1
		// 		struct _Position *_v1; // $t0
		/* end block 1.3 */
		// End offset: 0x8006FC58
		// End Line: 5026

		/* begin block 1.4 */
			// Start line: 5048
			// Start offset: 0x8006FD6C
			// Variables:
		// 		struct _PCollideInfo pcollideInfo; // stack offset -112
		// 		struct _Position newPos; // stack offset -64
		// 		struct _Position oldPos; // stack offset -56
		// 		struct _Position deltaPos; // stack offset -48
		// 		struct MATRIX *mat; // $a1

			/* begin block 1.4.1 */
				// Start line: 5055
				// Start offset: 0x8006FD90
				// Variables:
			// 		short _y0; // $v0
			// 		short _z0; // $v1
			// 		short _y1; // $a3
			// 		short _z1; // $t0
			// 		struct _Position *_v; // $s1
			// 		struct _Position *_v0; // $s0
			// 		struct _Position *_v1; // $s4
			/* end block 1.4.1 */
			// End offset: 0x8006FD90
			// End Line: 5055

			/* begin block 1.4.2 */
				// Start line: 5055
				// Start offset: 0x8006FD90
				// Variables:
			// 		short _y1; // $v0
			// 		short _z1; // $v1
			/* end block 1.4.2 */
			// End offset: 0x8006FD90
			// End Line: 5055
		/* end block 1.4 */
		// End offset: 0x8006FE74
		// End Line: 5080
	/* end block 1 */
	// End offset: 0x8006FEB0
	// End Line: 5084

	/* begin block 2 */
		// Start line: 10875
	/* end block 2 */
	// End Line: 10876

/* WARNING: Could not reconcile some variable overlaps */
/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_ReAlignFalling(_Instance *instance,int zEndOff)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  MATRIX *pMVar10;
  uint uVar11;
  undefined4 uVar12;
  short sVar13;
  short sVar14;
  int iVar15;
  int iVar16;
  _Model *p_Var17;
  uint uVar18;
  undefined4 local_d0;
  ushort local_cc;
  undefined4 local_c8;
  ushort local_c4;
  undefined4 local_c0;
  short local_bc;
  undefined4 local_b8;
  short local_b4;
  _PCollideInfo local_b0;
  uint local_80;
  ushort local_7c;
  uint local_78;
  short local_74;
  _PCollideInfo local_70;
  SVECTOR local_40;
  SVECTOR local_38;
  short local_30;
  short local_2e;
  short local_2c;
  
  uVar18 = 0xffff8300;
  p_Var17 = instance->object->modelList[instance->currentModel];
  iVar15 = 0;
  bVar3 = false;
  if (0 < p_Var17->numSegments) {
    iVar16 = 0;
    uVar7 = uVar18;
    do {
      sVar14 = 0;
      sVar13 = 0;
      uVar18 = uVar7;
      if ((p_Var17->segmentList[iVar15].hInfo != (_HInfo *)0x0) || (iVar15 == 0)) {
        iVar5 = (int)instance->matrix->m + iVar16;
        uVar1 = *(ushort *)(iVar5 + 0x14);
        uVar2 = *(ushort *)(iVar5 + 0x18);
        local_78 = CONCAT22(uVar2,uVar1);
        local_80 = CONCAT22(uVar2,uVar1);
        local_7c = *(short *)(iVar5 + 0x1c) + (short)zEndOff;
        local_74 = *(short *)(iVar5 + 0x1c) + 300;
        if (bVar3) {
          iVar5 = (uint)uVar1 - (local_c0 & 0xffff);
          iVar9 = (uint)uVar2 - (local_c0 >> 0x10);
          iVar6 = iVar5 * 0x10000;
          sVar4 = (short)((uint)iVar6 >> 0x10);
          if (iVar6 >> 0x10 < 0) {
            sVar4 = -sVar4;
          }
          iVar6 = iVar9 * 0x10000;
          sVar8 = (short)((uint)iVar6 >> 0x10);
          if (iVar6 >> 0x10 < 0) {
            sVar8 = -sVar8;
          }
          if ((sVar4 < 100) && (sVar8 < 100)) {
            if ((sVar4 == 0) && (sVar8 == 0)) {
              sVar14 = 0x40;
              sVar13 = 0;
            }
            else {
              sVar14 = (short)iVar5;
              sVar13 = (short)iVar9;
              if ((sVar4 < 0x14) && (sVar8 < 0x14)) {
                sVar14 = sVar14 * 0x10;
                sVar13 = sVar13 * 0x10;
              }
              else {
                sVar14 = sVar14 * 4;
                sVar13 = sVar13 * 4;
              }
            }
            local_78 = CONCAT22(uVar2 + sVar13,uVar1 + sVar14);
            local_80 = CONCAT22(uVar2 + sVar13,uVar1 + sVar14);
          }
          else {
            sVar13 = 0;
            sVar14 = 0;
          }
        }
        local_b0.newPoint = (SVECTOR *)&local_80;
        local_b0.oldPoint = (SVECTOR *)&local_78;
        PHYSICS_CheckLineInWorld(instance,&local_b0);
        if (local_b0.type != 0) {
          uVar18 = (uint)local_7c - (uint)*(ushort *)((int)instance->matrix->t + iVar16 + 8);
          if ((int)(uVar18 * 0x10000) < (int)(uVar7 << 0x10)) {
            uVar18 = uVar7;
          }
          if (bVar3) {
            local_c8 = local_80;
            local_c4 = local_7c;
            local_b4 = local_74;
            local_b8._0_2_ = (short)local_78;
            local_b8._2_2_ = (short)(local_78 >> 0x10);
            local_b8 = CONCAT22(local_b8._2_2_ - sVar13,(short)local_b8 - sVar14);
          }
          else {
            local_d0 = local_80;
            local_cc = local_7c;
            local_c0 = local_78;
            local_bc = local_74;
            local_c8 = local_80;
            local_c4 = local_7c;
            local_b8 = local_78;
            local_b4 = local_74;
            bVar3 = true;
          }
        }
      }
      iVar15 = iVar15 + 1;
      iVar16 = iVar16 + 0x20;
      uVar7 = uVar18;
    } while (iVar15 < p_Var17->numSegments);
  }
  uVar7 = 1;
  if (bVar3) {
    instance->zAccl = 0;
    instance->zVel = 0;
    (instance->position).z = *(short *)(instance->matrix->t + 2) + (short)uVar18;
    uVar11 = (local_b8 & 0xffff) - (local_c0 & 0xffff);
    local_b4 = local_b4 - local_bc;
    local_b8 = uVar11 & 0xffff | (uint)(ushort)(local_b8._2_2_ - local_c0._2_2_) << 0x10;
    uVar7 = (local_c8 & 0xffff) - (local_d0 & 0xffff);
    local_c4 = local_c4 - local_cc;
    local_c8 = uVar7 & 0xffff | (uint)(ushort)(local_c8._2_2_ - local_d0._2_2_) << 0x10;
    if ((((uVar11 * 0x10000 != uVar7 * 0x10000) ||
         ((short)(local_b8._2_2_ - local_c0._2_2_) != (short)(local_c8._2_2_ - local_d0._2_2_))) ||
        (local_b4 != local_c4)) || (uVar7 = 1, (uVar18 & 0xffff) != 0)) {
      iVar15 = 0;
      if (0 < p_Var17->numSegments) {
        iVar16 = 0;
        do {
          if ((*(int *)((int)&p_Var17->segmentList->hInfo + iVar16) != 0) || (iVar15 == 0)) {
            pMVar10 = instance->matrix + iVar15;
            local_38.vx = *(short *)pMVar10->t;
            local_38.vy = *(short *)(pMVar10->t + 1);
            local_38.vz = *(short *)(pMVar10->t + 2);
            pMVar10 = instance->oldMatrix + iVar15;
            local_30 = (*(short *)pMVar10->t - local_38.vx) * 2;
            local_2e = (*(short *)(pMVar10->t + 1) - local_38.vy) * 2;
            local_2c = (*(short *)(pMVar10->t + 2) - local_38.vz) * 2;
            local_40.vx = local_38.vx + local_30;
            local_40.vy = local_38.vy + local_2e;
            local_40.vz = local_38.vz + local_2c;
            local_70.newPoint = &local_40;
            local_70.oldPoint = &local_38;
            PHYSICS_CheckLineInWorld(instance,&local_70);
            if (local_70.type != 0) {
              uVar12 = *(undefined4 *)&(instance->oldRotation).z;
              *(undefined4 *)&instance->rotation = *(undefined4 *)&instance->oldRotation;
              *(undefined4 *)&(instance->rotation).z = uVar12;
              return 1;
            }
          }
          iVar15 = iVar15 + 1;
          iVar16 = iVar16 + 0x18;
        } while (iVar15 < p_Var17->numSegments);
      }
      iVar15 = PHYSOB_MoveTowardsAlign(instance,(_SVector *)&local_b8,(_SVector *)&local_c8);
      uVar7 = 0;
      if ((uVar18 & 0xffff) == 0) {
        uVar7 = (uint)(iVar15 != 0);
      }
    }
  }
  return uVar7;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DropPhysOb(struct _Instance *instance /*$s1*/, int flags /*$s3*/)
 // line 5087, offset 0x8006fee0
	/* begin block 1 */
		// Start line: 5088
		// Start offset: 0x8006FEE0
		// Variables:
	// 		struct PhysObData *Data; // $s0
	// 		struct _Instance *parent; // $s2
	/* end block 1 */
	// End offset: 0x8006FFAC
	// End Line: 5148

	/* begin block 2 */
		// Start line: 11431
	/* end block 2 */
	// End Line: 11432

/* File: C:\kain2\game\PHYSOBS.C */

void DropPhysOb(_Instance *instance,int flags)

{
  int zEndOff;
  uint *puVar1;
  _Instance *parent;
  
  parent = instance->LinkParent;
  puVar1 = (uint *)instance->extraData;
  if (parent == (_Instance *)0x0) {
    *puVar1 = *puVar1 & 0xff7fffff;
  }
  else {
    INSTANCE_UnlinkFromParent(instance);
  }
  PHYSOB_CheckDroppedLineCollision(instance,parent);
  if ((flags & 2U) == 0) {
    if ((flags & 4U) == 0) {
      zEndOff = 0;
      if (parent != (_Instance *)0x0) {
        zEndOff = -900;
      }
      PHYSOB_ReAlignFalling(instance,zEndOff);
    }
    *(_Instance **)(puVar1 + 0x10) = parent;
    *puVar1 = *puVar1 & 0xffffef6f | 0x400004;
    instance->zAccl = -10;
  }
  else {
    *puVar1 = *puVar1 & 0xffffff6f | 0x1000;
    instance->zAccl = 0;
  }
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicalRelocateTune(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 5160, offset 0x8006ffdc
	/* begin block 1 */
		// Start line: 5162
		// Start offset: 0x8006FFDC
		// Variables:
	// 		struct PhysObWeaponProperties *properties; // $t0
	// 		struct _PhysObLight *pLight; // $v0

		/* begin block 1.1 */
			// Start line: 5179
			// Start offset: 0x80070058
			// Variables:
		// 		struct PhysObInteractProperties *prop; // $a2
		// 		struct PhysObWeaponAttributes *weapon; // $a3
		/* end block 1.1 */
		// End offset: 0x800700CC
		// End Line: 5192

		/* begin block 1.2 */
			// Start line: 5194
			// Start offset: 0x800700DC
			// Variables:
		// 		struct __PhysObProjectileProperties *prop; // $a0

			/* begin block 1.2.1 */
				// Start line: 5200
				// Start offset: 0x80070100
				// Variables:
			// 		int i; // $t0
			/* end block 1.2.1 */
			// End offset: 0x8007016C
			// End Line: 5214
		/* end block 1.2 */
		// End offset: 0x8007016C
		// End Line: 5215
	/* end block 1 */
	// End offset: 0x8007016C
	// End Line: 5217

	/* begin block 2 */
		// Start line: 11581
	/* end block 2 */
	// End Line: 11582

	/* begin block 3 */
		// Start line: 11582
	/* end block 3 */
	// End Line: 11583

/* File: C:\kain2\game\PHYSOBS.C */

void PhysicalRelocateTune(Object *object,long offset)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  
  pvVar6 = object->data;
  if (pvVar6 != (void *)0x0) {
    if (*(short *)((int)pvVar6 + 2) == 0) {
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0x18) != 0) {
        iVar2 = *(int *)((int)pvVar6 + 0x18) + offset;
      }
      *(int *)((int)pvVar6 + 0x18) = iVar2;
      if (iVar2 != 0) {
        iVar3 = 0;
        if (*(int *)(iVar2 + 4) != 0) {
          iVar3 = *(int *)(iVar2 + 4) + offset;
        }
        *(int *)(iVar2 + 4) = iVar3;
      }
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0x20) != 0) {
        iVar2 = *(int *)((int)pvVar6 + 0x20) + offset;
      }
      *(int *)((int)pvVar6 + 0x20) = iVar2;
    }
    sVar1 = *(short *)((int)pvVar6 + 2);
    if (sVar1 == 3) {
      iVar3 = *(int *)((int)object->data + 0x28);
      iVar2 = 0;
      if (iVar3 != 0) {
        iVar2 = iVar3 + offset;
      }
      *(int *)((int)object->data + 0x28) = iVar2;
      if (iVar2 != 0) {
        iVar3 = 0;
        if (*(int *)(iVar2 + 0x10) != 0) {
          iVar3 = *(int *)(iVar2 + 0x10) + offset;
        }
        *(int *)(iVar2 + 0x10) = iVar3;
        if (iVar3 != 0) {
          iVar4 = 0;
          if (*(int *)(iVar3 + 4) != 0) {
            iVar4 = *(int *)(iVar3 + 4) + offset;
          }
          *(int *)(iVar3 + 4) = iVar4;
        }
        iVar3 = 0;
        if (*(int *)(iVar2 + 0x18) != 0) {
          iVar3 = *(int *)(iVar2 + 0x18) + offset;
        }
        *(int *)(iVar2 + 0x18) = iVar3;
      }
      sVar1 = *(short *)((int)pvVar6 + 2);
    }
    if (sVar1 == 7) {
      pvVar6 = object->data;
      iVar2 = 0;
      if (*(int *)((int)pvVar6 + 0xc) != 0) {
        iVar2 = *(int *)((int)pvVar6 + 0xc) + offset;
      }
      *(int *)((int)pvVar6 + 0xc) = iVar2;
      if ((iVar2 != 0) && (iVar3 = 0, 0 < *(int *)((int)pvVar6 + 8))) {
        do {
          iVar4 = 0;
          if (*(int *)(iVar2 + 8) != 0) {
            iVar4 = *(int *)(iVar2 + 8) + offset;
          }
          *(int *)(iVar2 + 8) = iVar4;
          if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x10), iVar4 != 0)) {
            iVar5 = 0;
            if (*(int *)(iVar4 + 4) != 0) {
              iVar5 = *(int *)(iVar4 + 4) + offset;
            }
            *(int *)(iVar4 + 4) = iVar5;
          }
          iVar3 = iVar3 + 1;
          iVar2 = iVar2 + 0xc;
        } while (iVar3 < *(int *)((int)pvVar6 + 8));
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOBS_CheckObjectAxisAlignment(struct MATRIX *m0 /*$a0*/, struct MATRIX *m1 /*$s1*/, struct _SVector *axis /*$s0*/)
 // line 5231, offset 0x80070174
	/* begin block 1 */
		// Start line: 5232
		// Start offset: 0x80070174
		// Variables:
	// 		struct VECTOR r0; // stack offset -64
	// 		struct VECTOR r1; // stack offset -48
	// 		struct _SVector v0; // stack offset -32
	// 		struct _SVector v1; // stack offset -24
	/* end block 1 */
	// End offset: 0x80070174
	// End Line: 5232

	/* begin block 2 */
		// Start line: 11729
	/* end block 2 */
	// End Line: 11730

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOBS_CheckObjectAxisAlignment(undefined m0,undefined m1,_SVector *axis)

{
  undefined3 in_register_00000011;
  undefined3 in_register_00000015;
  short local_40 [2];
  short local_3c;
  short local_38;
  short local_30 [2];
  short local_2c;
  short local_28;
  
  ApplyMatrix((MATRIX *)CONCAT31(in_register_00000011,m0),(SVECTOR *)axis,(VECTOR *)local_40);
  ApplyMatrix((MATRIX *)CONCAT31(in_register_00000015,m1),(SVECTOR *)axis,(VECTOR *)local_30);
  return ((int)local_40[0] * (int)local_30[0] + (int)local_3c * (int)local_2c +
         (int)local_38 * (int)local_28) * 0x10 >> 0x10;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckSlide(struct _Instance *instance /*$s0*/, int x /*$a1*/, int y /*$a2*/, struct evPhysicsSlideData **data /*$s1*/)
 // line 5252, offset 0x80070244
	/* begin block 1 */
		// Start line: 11797
	/* end block 1 */
	// End Line: 11798

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_CheckSlide(_Instance *instance,int x,int y,evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;
  
  Data = (evPhysicsSlideData *)
         SetPhysicsSlideData(1,x * 0x2c00000 >> 0x10,y * 0x2c00000 >> 0x10,0,0x280,0x280,-0xa0);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance,(int)Data,1);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckSlide2(struct _Instance *instance /*$s0*/, int x /*$a1*/, int y /*$a2*/, struct evPhysicsSlideData **data /*$s1*/)
 // line 5262, offset 0x800702d4
	/* begin block 1 */
		// Start line: 11819
	/* end block 1 */
	// End Line: 11820

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_CheckSlide2(_Instance *instance,int x,int y,evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;
  
  Data = (evPhysicsSlideData *)
         SetPhysicsSlideData(1,x * 0x2c00000 >> 0x10,y * 0x2c00000 >> 0x10,0,0x280,0x280,-0x96);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance,(int)Data,1);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckDropOnSlope(struct _Instance *instance /*$s0*/, int x /*$a1*/, int y /*$a2*/, struct evPhysicsSlideData **data /*$s1*/)
 // line 5271, offset 0x80070364
	/* begin block 1 */
		// Start line: 11839
	/* end block 1 */
	// End Line: 11840

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_CheckDropOnSlope(_Instance *instance,int x,int y,evPhysicsSlideData **data)

{
  evPhysicsSlideData *Data;
  int iVar1;
  
  Data = (evPhysicsSlideData *)
         SetPhysicsSlideData(1,x * 0x2c00000 >> 0x10,y * 0x2c00000 >> 0x10,0,0xa00,0x280,-0xa0);
  *data = Data;
  iVar1 = PhysicsCheckSliding(instance,(int)Data,1);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckSlideNormal(struct _Instance *instance /*$s0*/, int x /*stack 4*/, int y /*stack 8*/, struct evPhysicsSlideData **data /*$s1*/)
 // line 5281, offset 0x800703f8
	/* begin block 1 */
		// Start line: 11861
	/* end block 1 */
	// End Line: 11862

/* File: C:\kain2\game\PHYSOBS.C */

int PHYSOB_CheckSlideNormal(_Instance *instance,int x,int y,evPhysicsSlideData **data)

{
  int iVar1;
  int local_res4;
  int local_res8 [2];
  
  local_res4 = x;
  local_res8[0] = y;
  PHYSOB_NormalToAxis((short *)&local_res4,(short *)local_res8);
  iVar1 = PHYSOB_CheckSlide2(instance,local_res4,local_res8[0],data);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_NormalToAxis(short *x /*$a0*/, short *y /*$a1*/)
 // line 5289, offset 0x8007044c
	/* begin block 1 */
		// Start line: 5291
		// Start offset: 0x8007044C
		// Variables:
	// 		int x1; // $v1
	// 		int y1; // $a2
	/* end block 1 */
	// End offset: 0x800704A8
	// End Line: 5305

	/* begin block 2 */
		// Start line: 11879
	/* end block 2 */
	// End Line: 11880

	/* begin block 3 */
		// Start line: 11880
	/* end block 3 */
	// End Line: 11881

/* File: C:\kain2\game\PHYSOBS.C */

void PHYSOB_NormalToAxis(short *x,short *y)

{
  short sVar1;
  
  sVar1 = *y;
  if (*x < 0x401) {
    if (*x < -0x400) {
      *x = -1;
    }
    else {
      *x = 0;
    }
  }
  else {
    *x = 1;
  }
  if (0x400 < sVar1) {
    *y = 1;
    return;
  }
  if (sVar1 < -0x400) {
    *y = -1;
    return;
  }
  *y = 0;
  return;
}





