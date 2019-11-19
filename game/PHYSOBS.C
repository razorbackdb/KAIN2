#include "THISDUST.H"
#include "PHYSOBS.H"


// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_PlayDropSound(struct _Instance *instance /*$a0*/)
 // line 165, offset 0x80069678
	/* begin block 1 */
		// Start line: 166
		// Start offset: 0x80069678
		// Variables:
	// 		struct PhysObProperties *Prop; // $a1
	// 		int sound; // $v1
	/* end block 1 */
	// End offset: 0x80069784
	// End Line: 204

	/* begin block 2 */
		// Start line: 330
	/* end block 2 */
	// End Line: 331

void PHYSOB_PlayDropSound(_Instance *instance)

{
  short sVar1;
  int sfxToneID;
  void *pvVar2;
  int pitch;
  int maxVolume;
  int local_18;
  
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
    SOUND_Play3dSound(&instance->position,0x149,-400,0x5a,14000);
    sfxToneID = 0x149;
    pitch = -800;
    maxVolume = 100;
    local_18 = 14000;
  }
  else {
    if (sfxToneID < 3) {
      if (sfxToneID != 1) {
        return;
      }
      sfxToneID = 0xc;
      pitch = -100;
    }
    else {
      if (sfxToneID != 3) {
        return;
      }
      sfxToneID = 0x10a;
      pitch = -800;
    }
    local_18 = 30000;
    maxVolume = 0x78;
  }
  SOUND_Play3dSound(&instance->position,sfxToneID,pitch,maxVolume,local_18);
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ PHYSOBS_IsAPushBlockAttached(struct _Instance *block /*$s3*/)
 // line 216, offset 0x80069798
	/* begin block 1 */
		// Start line: 217
		// Start offset: 0x80069798
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *next; // $s1
	// 		struct _Instance *result; // $s2
	/* end block 1 */
	// End offset: 0x80069800
	// End Line: 237

	/* begin block 2 */
		// Start line: 432
	/* end block 2 */
	// End Line: 433

	/* begin block 3 */
		// Start line: 433
	/* end block 3 */
	// End Line: 434

_Instance * PHYSOBS_IsAPushBlockAttached(_Instance *block)

{
  _Instance *instance;
  int iVar1;
  _Instance *p_Var2;
  
  p_Var2 = (gameTrackerX.instanceList)->first;
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
 // line 241, offset 0x80069820
	/* begin block 1 */
		// Start line: 243
		// Start offset: 0x80069820
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $a1
	// 		struct _Instance *result; // $a2
	/* end block 1 */
	// End offset: 0x80069860
	// End Line: 260

	/* begin block 2 */
		// Start line: 486
	/* end block 2 */
	// End Line: 487

	/* begin block 3 */
		// Start line: 487
	/* end block 3 */
	// End Line: 488

_Instance * PHYSOBS_IsAnythingAttached(_Instance *block)

{
  _Instance **pp_Var1;
  _Instance *p_Var2;
  
  if ((gameTrackerX.instanceList)->first != (_Instance *)0x0) {
    p_Var2 = (gameTrackerX.instanceList)->first;
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
 // line 264, offset 0x80069868
	/* begin block 1 */
		// Start line: 266
		// Start offset: 0x80069868
		// Variables:
	// 		struct PhysObProperties *Prop; // $v0
	/* end block 1 */
	// End offset: 0x8006988C
	// End Line: 276

	/* begin block 2 */
		// Start line: 535
	/* end block 2 */
	// End Line: 536

	/* begin block 3 */
		// Start line: 536
	/* end block 3 */
	// End Line: 537

	/* begin block 4 */
		// Start line: 540
	/* end block 4 */
	// End Line: 541

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
 // line 279, offset 0x80069894
	/* begin block 1 */
		// Start line: 280
		// Start offset: 0x80069894
		// Variables:
	// 		struct PhysObProperties *Prop; // $a2

		/* begin block 1.1 */
			// Start line: 292
			// Start offset: 0x800698CC
		/* end block 1.1 */
		// End offset: 0x800698F0
		// End Line: 296
	/* end block 1 */
	// End offset: 0x80069908
	// End Line: 302

	/* begin block 2 */
		// Start line: 567
	/* end block 2 */
	// End Line: 568

	/* begin block 3 */
		// Start line: 572
	/* end block 3 */
	// End Line: 573

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
 // line 305, offset 0x80069910
	/* begin block 1 */
		// Start line: 307
		// Start offset: 0x80069910
		// Variables:
	// 		struct PhysObProperties *Prop; // $a0
	/* end block 1 */
	// End offset: 0x8006994C
	// End Line: 322

	/* begin block 2 */
		// Start line: 624
	/* end block 2 */
	// End Line: 625

	/* begin block 3 */
		// Start line: 625
	/* end block 3 */
	// End Line: 626

	/* begin block 4 */
		// Start line: 629
	/* end block 4 */
	// End Line: 630

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
 // line 359, offset 0x80069954
	/* begin block 1 */
		// Start line: 361
		// Start offset: 0x80069954
		// Variables:
	// 		struct PhysObProperties *Prop; // $a1

		/* begin block 1.1 */
			// Start line: 370
			// Start offset: 0x80069984
		/* end block 1.1 */
		// End offset: 0x80069998
		// End Line: 373
	/* end block 1 */
	// End offset: 0x800699A4
	// End Line: 379

	/* begin block 2 */
		// Start line: 732
	/* end block 2 */
	// End Line: 733

	/* begin block 3 */
		// Start line: 733
	/* end block 3 */
	// End Line: 734

	/* begin block 4 */
		// Start line: 737
	/* end block 4 */
	// End Line: 738

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
// void /*$ra*/ ThrowPhysOb(struct _Instance *instance /*$s1*/, struct evObjectThrowData *throwData /*$s2*/)
 // line 383, offset 0x800699ac
	/* begin block 1 */
		// Start line: 384
		// Start offset: 0x800699AC
		// Variables:
	// 		struct PhysObData *Data; // $s3
	// 		int collFlg; // $s5

		/* begin block 1.1 */
			// Start line: 392
			// Start offset: 0x800699E0
			// Variables:
		// 		struct _Instance *parent; // $s0
		// 		struct PhysObProperties *Prop; // $s4

			/* begin block 1.1.1 */
				// Start line: 418
				// Start offset: 0x80069A84
				// Variables:
			// 		struct __PhysObProjectileData *ProjData; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80069AD8
			// End Line: 430

			/* begin block 1.1.2 */
				// Start line: 449
				// Start offset: 0x80069B4C
				// Variables:
			// 		long val; // $a1
			// 		struct _Instance *itarget; // $s0
			// 		struct MATRIX *matrix; // $t0
			/* end block 1.1.2 */
			// End offset: 0x80069C1C
			// End Line: 475

			/* begin block 1.1.3 */
				// Start line: 483
				// Start offset: 0x80069C74
				// Variables:
			// 		long val; // $a1
			// 		struct _Position *ptarget; // $s0
			/* end block 1.1.3 */
			// End offset: 0x80069D2C
			// End Line: 507

			/* begin block 1.1.4 */
				// Start line: 544
				// Start offset: 0x80069E38
				// Variables:
			// 		struct _SVector *sv; // $v1
			/* end block 1.1.4 */
			// End offset: 0x80069E64
			// End Line: 550
		/* end block 1.1 */
		// End offset: 0x80069F04
		// End Line: 580
	/* end block 1 */
	// End offset: 0x80069F04
	// End Line: 585

	/* begin block 2 */
		// Start line: 780
	/* end block 2 */
	// End Line: 781

void ThrowPhysOb(_Instance *instance,evObjectThrowData *throwData)

{
  short angle;
  int iVar1;
  ulong uVar2;
  uint uVar3;
  _Instance *Inst;
  uint uVar4;
  int NewAnim;
  int iVar5;
  int iVar6;
  uint *puVar7;
  void *pvVar8;
  int iVar9;
  
  Inst = instance->LinkParent;
  if (Inst == (_Instance *)0x0) {
    return;
  }
  pvVar8 = instance->data;
  instance->flags2 = instance->flags2 | 0x4000;
  INSTANCE_UnlinkFromParent(instance);
  iVar1 = PHYSOB_CheckThrownLineCollision(instance);
  instance->flags2 = instance->flags2 | 0x80;
  if (throwData == (evObjectThrowData *)0x0) {
    throwData = (evObjectThrowData *)
                SetObjectThrowData((void *)0x0,(_SVector *)0x0,0,0,0x180,0,0x40,-0x400);
  }
  puVar7 = (uint *)instance->extraData;
  puVar7[2] = 0;
  *puVar7 = *puVar7 & 0xffffff7e | 0x1010;
  angle = throwData->initialXRot;
  *(_Instance **)(puVar7 + 0x10) = Inst;
  *(short *)(puVar7 + 0xe) = angle;
  if ((*(short *)((int)pvVar8 + 2) == 7) &&
     (NewAnim = (int)*(char *)(*(int *)((int)pvVar8 + 0xc) +
                               *(int *)((int)instance->extraData + 4) * 0xc + 2), NewAnim != -1)) {
    G2EmulationInstanceSetAnimation(instance,0,NewAnim,0,0);
    G2EmulationInstanceSetMode(instance,0,2);
  }
  instance->zAccl = (int)throwData->gravity;
  switch(throwData->type) {
  case 0:
    if (Inst->LinkParent == (_Instance *)0x0) {
      angle = (Inst->rotation).z;
    }
    else {
      angle = (Inst->LinkParent->rotation).z;
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
    iVar6 = instance->xVel;
    iVar5 = instance->yVel;
    NewAnim = iVar6;
    if (iVar6 < 0) {
      NewAnim = -iVar6;
    }
    iVar9 = iVar5;
    if (iVar5 < 0) {
      iVar9 = -iVar5;
    }
    if (iVar9 < NewAnim) {
      NewAnim = *(int *)(uVar2 + 0x14) - (int)(instance->position).x;
      if ((iVar6 == 0) || (NewAnim == 0)) break;
      iVar9 = (instance->zAccl * NewAnim) / iVar6;
      iVar6 = (*(int *)(uVar2 + 0x1c) - (int)(instance->position).z) * iVar6;
    }
    else {
      NewAnim = *(int *)(uVar2 + 0x18) - (int)(instance->position).y;
      if ((iVar5 == 0) || (NewAnim == 0)) break;
      iVar9 = (instance->zAccl * NewAnim) / iVar5;
      iVar6 = (*(int *)(uVar2 + 0x1c) - (int)(instance->position).z) * iVar5;
    }
    instance->zVel = iVar6 / NewAnim - (iVar9 >> 1);
    break;
  case 2:
    angle = MATH3D_AngleFromPosToPos(&instance->position,(_Position *)&throwData->data);
    PhysicsSetVelFromZRot(instance,angle,(uint)throwData->speed);
    iVar6 = instance->xVel;
    iVar5 = instance->yVel;
    NewAnim = iVar6;
    if (iVar6 < 0) {
      NewAnim = -iVar6;
    }
    iVar9 = iVar5;
    if (iVar5 < 0) {
      iVar9 = -iVar5;
    }
    instance->zVel = 0;
    if (iVar9 < NewAnim) {
      NewAnim = (int)*(short *)&throwData->data - (int)(instance->position).x;
      if ((iVar6 == 0) || (NewAnim == 0)) break;
      iVar9 = (instance->zAccl * NewAnim) / iVar6;
      iVar6 = ((int)*(short *)((int)&throwData->data + 4) - (int)(instance->position).z) * iVar6;
    }
    else {
      NewAnim = (int)*(short *)((int)&throwData->data + 2) - (int)(instance->position).y;
      if ((iVar5 == 0) || (NewAnim == 0)) break;
      iVar9 = (instance->zAccl * NewAnim) / iVar5;
      iVar6 = ((int)*(short *)((int)&throwData->data + 4) - (int)(instance->position).z) * iVar5;
    }
    instance->zVel = iVar6 / NewAnim - (iVar9 >> 1);
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
      uVar3 = *puVar7;
      uVar4 = 0xffffefff;
    }
    else {
      *puVar7 = *puVar7 | 0x1000;
      instance->flags2 = instance->flags2 & 0xffffff7f;
      uVar3 = *puVar7;
      uVar4 = 0xffffffef;
    }
    *puVar7 = uVar3 & uVar4;
  }
  if ((*puVar7 & 0x10) != 0) {
    PhysicsMove(instance,&instance->position,gameTrackerX.idleTime);
    TurnOnCollisionPhysOb(instance,4);
  }
  puVar7[0x11] = 0x96000;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PushPhysOb(struct _Instance *instance /*$s1*/, short x /*stack -24*/, short y /*stack -22*/, short PathNumber /*$a3*/, struct _Instance *Force /*stack 16*/)
 // line 589, offset 0x80069f28
	/* begin block 1 */
		// Start line: 590
		// Start offset: 0x80069F28
		// Variables:
	// 		struct PhysObData *Data; // $s0
	// 		struct PhysObProperties *Prop; // $v1
	// 		int result; // $a0
	/* end block 1 */
	// End offset: 0x8006A040
	// End Line: 638

	/* begin block 2 */
		// Start line: 1213
	/* end block 2 */
	// End Line: 1214

int PushPhysOb(_Instance *instance,short x,short y,short PathNumber,_Instance *Force)

{
  uint uVar1;
  uint *puVar2;
  short local_18;
  short local_16 [3];
  
  uVar1 = 0;
  if ((((*(ushort *)((int)instance->data + 6) & 8) != 0) &&
      (*(short *)((int)instance->data + 4) == -0x4ff5)) &&
     (puVar2 = (uint *)instance->extraData, (*puVar2 & 0x2000) == 0)) {
    local_18 = x;
    local_16[0] = y;
    PHYSOB_NormalToAxis(&local_18,local_16);
    *(_Instance **)(puVar2 + 2) = Force;
    *(short *)(puVar2 + 10) = PathNumber;
    *(short *)(puVar2 + 1) = local_18;
    *(short *)((int)puVar2 + 6) = local_16[0];
    *puVar2 = *puVar2 & 0xfffffff7;
    instance->zVel = 0;
    instance->yVel = 0;
    instance->xVel = 0;
    instance->zAccl = 0;
    instance->yAccl = 0;
    instance->xAccl = 0;
    uVar1 = PHYSOBS_CheckForValidMove(instance);
    if ((uVar1 & 1) != 0) {
      if ((*puVar2 & 0x100) == 0) {
        *(short *)((int)puVar2 + 0xe) = (instance->position).x;
        *(short *)(puVar2 + 4) = (instance->position).y;
        *(short *)((int)puVar2 + 0x12) = (instance->position).z;
      }
      *puVar2 = *puVar2 | 0x1000;
    }
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetSwitchPhysOb(struct _Instance *instance /*$s0*/)
 // line 642, offset 0x8006a05c
	/* begin block 1 */
		// Start line: 643
		// Start offset: 0x8006A05C
		// Variables:
	// 		struct PhysObData *Data; // $v1
	// 		struct PhysObSwitchProperties *Prop; // $a1
	/* end block 1 */
	// End offset: 0x8006A0E4
	// End Line: 663

	/* begin block 2 */
		// Start line: 1356
	/* end block 2 */
	// End Line: 1357

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
 // line 667, offset 0x8006a0f4
	/* begin block 1 */
		// Start line: 668
		// Start offset: 0x8006A0F4
		// Variables:
	// 		struct PhysObData *Data; // $v0
	// 		struct PhysObSwitchProperties *Prop; // $s0
	// 		struct SwitchData *switchData; // $s3
	/* end block 1 */
	// End offset: 0x8006A2B4
	// End Line: 728

	/* begin block 2 */
		// Start line: 1408
	/* end block 2 */
	// End Line: 1409

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
 // line 732, offset 0x8006a2d0
	/* begin block 1 */
		// Start line: 733
		// Start offset: 0x8006A2D0
		// Variables:
	// 		struct PhysObData *Data; // $s5
	// 		struct PhysObInteractProperties *interactProp; // $s2

		/* begin block 1.1 */
			// Start line: 743
			// Start offset: 0x8006A31C
			// Variables:
		// 		struct BreakOffData *BreakOff; // $s6

			/* begin block 1.1.1 */
				// Start line: 754
				// Start offset: 0x8006A390
				// Variables:
			// 		struct _Instance *lightInst; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8006A3A8
			// End Line: 760

			/* begin block 1.1.2 */
				// Start line: 766
				// Start offset: 0x8006A3D0
				// Variables:
			// 		struct _Instance *lightInst; // $s0
			/* end block 1.1.2 */
			// End offset: 0x8006A3F0
			// End Line: 773

			/* begin block 1.1.3 */
				// Start line: 810
				// Start offset: 0x8006A510
				// Variables:
			// 		int s; // $s0
			/* end block 1.1.3 */
			// End offset: 0x8006A560
			// End Line: 815

			/* begin block 1.1.4 */
				// Start line: 815
				// Start offset: 0x8006A568
				// Variables:
			// 		int s; // $s0
			/* end block 1.1.4 */
			// End offset: 0x8006A5B8
			// End Line: 821
		/* end block 1.1 */
		// End offset: 0x8006A5F4
		// End Line: 839
	/* end block 1 */
	// End offset: 0x8006A5F4
	// End Line: 841

	/* begin block 2 */
		// Start line: 1547
	/* end block 2 */
	// End Line: 1548

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
  goto LAB_8006a4e4;
  G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar5 + 0x11),0,0);
  bVar3 = *(byte *)((int)pvVar5 + 0x15) & 0x30;
  if (bVar3 == 0x10) {
    Mode = 1;
LAB_8006a4dc:
    G2EmulationInstanceSetMode(instance,0,Mode);
  }
  else {
    if (bVar3 < 0x11) {
      if ((*(byte *)((int)pvVar5 + 0x15) & 0x30) == 0) {
        Mode = 2;
        goto LAB_8006a4dc;
      }
    }
    else {
      if (bVar3 == 0x20) {
        Mode = 0;
        goto LAB_8006a4dc;
      }
    }
  }
LAB_8006a4e4:
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
        goto LAB_8006a5bc;
      }
    }
  }
  puVar1[2] = 0;
LAB_8006a5bc:
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
 // line 841, offset 0x8006a620
	/* begin block 1 */
		// Start line: 842
		// Start offset: 0x8006A620
		// Variables:
	// 		struct _G2EulerAngles_Type ea; // stack offset -40
	// 		struct PhysObData *Data; // $a1
	// 		struct _G2SVector3_Type vec; // stack offset -32
	// 		struct _G2SVector3_Type vec2; // stack offset -24
	// 		int dp; // $a0
	// 		int dx; // $v1
	// 		int dx2; // $v0
	// 		int dy; // $v1
	// 		int dy2; // $v0
	// 		int dz; // $v1
	// 		int dz2; // $v0
	/* end block 1 */
	// End offset: 0x8006A9D0
	// End Line: 919

	/* begin block 2 */
		// Start line: 1785
	/* end block 2 */
	// End Line: 1786

void ResetOrientation(_Instance *instance)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  _G2EulerAngles_Type local_28;
  _G2SVector3_Type local_20;
  short local_18;
  short local_16;
  short local_14;
  
  G2Anim_DisableController(&instance->anim,0,0x4c);
  puVar9 = (uint *)instance->extraData;
  if ((*puVar9 & 0x100) != 0) goto LAB_8006a780;
  iVar8 = (int)(instance->position).x - (int)*(short *)((int)puVar9 + 0xe);
  if (iVar8 < 1) {
    iVar8 = iVar8 + -0x140;
  }
  else {
    iVar8 = iVar8 + 0x140;
  }
  (instance->position).x = *(short *)((int)puVar9 + 0xe) + (short)(iVar8 / 0x280) * 0x280;
  iVar8 = (int)(instance->position).y - (int)*(short *)(puVar9 + 4);
  if (iVar8 < 1) {
    iVar8 = iVar8 + -0x140;
  }
  else {
    iVar8 = iVar8 + 0x140;
  }
  (instance->position).y = *(short *)(puVar9 + 4) + (short)(iVar8 / 0x280) * 0x280;
  iVar8 = (int)(instance->position).z - (int)*(short *)((int)puVar9 + 0x12);
  if (iVar8 < 0) {
    sVar4 = (short)(iVar8 + -0x20 >> 6);
    if (iVar8 + -0x20 < 0) {
      iVar8 = iVar8 + 0x1f;
      goto LAB_8006a748;
    }
  }
  else {
    sVar4 = (short)(iVar8 + 0x20 >> 6);
    if (iVar8 + 0x20 < 0) {
      iVar8 = iVar8 + 0x5f;
LAB_8006a748:
      sVar4 = (short)(iVar8 >> 6);
    }
  }
  (instance->position).z = *(short *)((int)puVar9 + 0x12) + sVar4 * 0x40;
  *(short *)((int)puVar9 + 0xe) = (instance->position).x;
  *(short *)(puVar9 + 4) = (instance->position).y;
  *(short *)((int)puVar9 + 0x12) = (instance->position).z;
LAB_8006a780:
  G2EulerAngles_FromMatrix(&local_28,(_G2Matrix_Type *)(instance->matrix + 2),0x15);
  iVar8 = (int)local_28.x;
  iVar12 = iVar8 * 0x41a;
  iVar1 = (iVar8 * 0x132) / 0x161e9;
  iVar11 = (int)local_28.y;
  iVar10 = (int)local_28.z;
  iVar2 = (iVar11 * 0x132) / 0x161e9;
  iVar3 = (iVar10 * 0x132) / 0x161e9;
  if (iVar12 < 0) {
    iVar12 = iVar12 + 0xfffff;
  }
  iVar5 = iVar11 * 0x41a;
  local_18 = (short)((iVar12 >> 0x14) << 10);
  if (iVar5 < 0) {
    iVar5 = iVar5 + 0xfffff;
  }
  iVar6 = iVar10 * 0x41a;
  local_16 = (short)((iVar5 >> 0x14) << 10);
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xfffff;
  }
  iVar7 = (iVar1 * 0x12d0000 >> 0x10) - iVar8;
  iVar8 = (((iVar12 >> 0x14) << 0x1a) >> 0x10) - iVar8;
  if (iVar7 < 0) {
    iVar7 = -iVar7;
  }
  if (iVar8 < 0) {
    iVar8 = -iVar8;
  }
  local_14 = (short)((iVar6 >> 0x14) << 10);
  local_20.x = (short)iVar1 * 0x12d;
  if (iVar8 < iVar7) {
    local_20.x = local_18;
  }
  iVar8 = (iVar2 * 0x12d0000 >> 0x10) - iVar11;
  iVar11 = (((iVar5 >> 0x14) << 0x1a) >> 0x10) - iVar11;
  if (iVar8 < 0) {
    iVar8 = -iVar8;
  }
  if (iVar11 < 0) {
    iVar11 = -iVar11;
  }
  local_20.y = (short)iVar2 * 0x12d;
  if (iVar11 < iVar8) {
    local_20.y = local_16;
  }
  iVar8 = (iVar3 * 0x12d0000 >> 0x10) - iVar10;
  iVar10 = (((iVar6 >> 0x14) << 0x1a) >> 0x10) - iVar10;
  if (iVar8 < 0) {
    iVar8 = -iVar8;
  }
  if (iVar10 < 0) {
    iVar10 = -iVar10;
  }
  local_20.z = (short)iVar3 * 0x12d;
  if (iVar10 < iVar8) {
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
 // line 928, offset 0x8006aa1c
	/* begin block 1 */
		// Start line: 1984
	/* end block 1 */
	// End Line: 1985

void FinishPush(_Instance *instance)

{
  ResetOrientation(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysOb_AlignPush(struct _Instance *instance /*$s4*/, int x /*$s5*/, int y /*$s3*/, int path /*$s6*/, struct PhysObData *Data /*stack 16*/)
 // line 934, offset 0x8006aa3c
	/* begin block 1 */
		// Start line: 935
		// Start offset: 0x8006AA3C
		// Variables:
	// 		struct _G2SVector3_Type vec; // stack offset -96
	// 		int rotZ; // $s2
	// 		short temp[3][3]; // stack offset -88
	// 		short temp2[3][3]; // stack offset -64
	// 		struct _G2EulerAngles_Type ea; // stack offset -40
	/* end block 1 */
	// End offset: 0x8006AAD4
	// End Line: 963

	/* begin block 2 */
		// Start line: 1996
	/* end block 2 */
	// End Line: 1997

void PhysOb_AlignPush(_Instance *instance,int x,int y,int path,PhysObData *Data)

{
  _G2Anim_Type *anim;
  short sVar1;
  _G2SVector3_Type local_60;
  uint auStack88 [6];
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
  local_60.x = 0;
  local_60.y = 0;
  local_60.z = sVar1;
  G2Anim_SetController_Vector(anim,0,0x4c,&local_60);
  local_60.z = -sVar1;
  RotMatrixZYX((short *)&local_60,auStack88);
  MulMatrix0(auStack88,(ushort *)(instance->matrix + 2),(uint *)(_G2Matrix_Type *)auStack64);
  G2EulerAngles_FromMatrix(&local_28,(_G2Matrix_Type *)auStack64,0x15);
  local_60.x = local_28.x;
  local_60.y = local_28.y;
  local_60.z = local_28.z;
  G2Anim_SetController_Vector(anim,2,0xe,&local_60);
  G2Anim_SwitchToKeylist(anim,instance->object->animList[path],path);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ FlipPhysOb(struct _Instance *instance /*$s1*/, short x /*stack -32*/, short y /*stack -30*/, struct _Instance *Force /*$s3*/)
 // line 980, offset 0x8006abac
	/* begin block 1 */
		// Start line: 981
		// Start offset: 0x8006ABAC
		// Variables:
	// 		struct PhysObData *Data; // $s0
	// 		struct PhysObProperties *Prop; // $v0
	// 		int result; // $s2
	/* end block 1 */
	// End offset: 0x8006ACB0
	// End Line: 1025

	/* begin block 2 */
		// Start line: 2117
	/* end block 2 */
	// End Line: 2118

int FlipPhysOb(_Instance *instance,short x,short y,_Instance *Force)

{
  short sVar1;
  _Instance *p_Var2;
  uint *puVar3;
  uint uVar4;
  short local_20;
  short local_1e [3];
  
  uVar4 = 0;
  if ((*(ushort *)((int)instance->data + 6) & 2) != 0) {
    local_20 = x;
    local_1e[0] = y;
    p_Var2 = PHYSOBS_IsAPushBlockAttached(instance);
    uVar4 = 0;
    if (p_Var2 == (_Instance *)0x0) {
      puVar3 = (uint *)instance->extraData;
      uVar4 = 0;
      if ((*puVar3 & 0x2000) == 0) {
        PHYSOB_NormalToAxis(&local_20,local_1e);
        *(undefined2 *)(puVar3 + 10) = 1;
        *(_Instance **)(puVar3 + 2) = Force;
        *puVar3 = *puVar3 | 8;
        *(short *)(puVar3 + 1) = local_20;
        *(short *)((int)puVar3 + 6) = local_1e[0];
        instance->zVel = 0;
        instance->yVel = 0;
        instance->xVel = 0;
        instance->zAccl = 0;
        instance->yAccl = 0;
        instance->xAccl = 0;
        ResetOrientation(instance);
        uVar4 = PHYSOBS_CheckForValidMove(instance);
        if ((uVar4 & 1) != 0) {
          *(short *)((int)puVar3 + 0xe) = (instance->position).x;
          *(short *)(puVar3 + 4) = (instance->position).y;
          sVar1 = (instance->position).z;
          *puVar3 = *puVar3 | 0x1000;
          *(short *)((int)puVar3 + 0x12) = sVar1;
        }
      }
    }
  }
  return uVar4;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PickUpPhysOb(struct _Instance *instance /*$s1*/, short Steps /*$a1*/, struct _Instance *Force /*$s3*/, int LinkNode /*$s4*/)
 // line 1069, offset 0x8006acd0
	/* begin block 1 */
		// Start line: 1070
		// Start offset: 0x8006ACD0
		// Variables:
	// 		struct PhysObData *Data; // $s0

		/* begin block 1.1 */
			// Start line: 1103
			// Start offset: 0x8006AD94
			// Variables:
		// 		struct _PhysObLight *pLight; // $v0
		/* end block 1.1 */
		// End offset: 0x8006ADAC
		// End Line: 1109
	/* end block 1 */
	// End offset: 0x8006ADB8
	// End Line: 1115

	/* begin block 2 */
		// Start line: 2328
	/* end block 2 */
	// End Line: 2329

int PickUpPhysOb(_Instance *instance,short Steps,_Instance *Force,int LinkNode)

{
  int iVar1;
  _PhysObLight *pLight;
  uint *puVar2;
  
  if (instance->LinkParent == (_Instance *)0x0) {
    TurnOffCollisionPhysOb(instance,7);
    iVar1 = CheckPhysObAbility(instance,1);
    if (iVar1 != 0) {
      puVar2 = (uint *)instance->extraData;
      *puVar2 = *puVar2 & 0xff9fffff;
      TurnOnCollisionPhysOb(instance,7);
      *(short *)(puVar2 + 9) = Steps;
      *(undefined2 *)((int)puVar2 + 0x26) = 0;
      *(_Instance **)(puVar2 + 2) = Force;
      *(short *)(puVar2 + 3) = (short)LinkNode;
      *puVar2 = *puVar2 | 0x1004000;
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
 // line 1144, offset 0x8006add8
	/* begin block 1 */
		// Start line: 1145
		// Start offset: 0x8006ADD8
		// Variables:
	// 		struct Object *object; // $a1
	// 		struct _Instance *instance; // $a2

		/* begin block 1.1 */
			// Start line: 1158
			// Start offset: 0x8006AE44
		/* end block 1.1 */
		// End offset: 0x8006AE68
		// End Line: 1167
	/* end block 1 */
	// End offset: 0x8006AE68
	// End Line: 1170

	/* begin block 2 */
		// Start line: 2277
	/* end block 2 */
	// End Line: 2278

/* WARNING: Removing unreachable block (ram,0x8006ae30) */
/* WARNING: Removing unreachable block (ram,0x8006ae44) */

_Instance * PHYSOB_BirthCollectible(_Instance *parent,int x,int y,int z,int type,int lifeTime)

{
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// struct evObjectBirthProjectileData * /*$ra*/ PHYSOB_BirthProjectile(struct _Instance *parent /*$s0*/, int joint /*$s1*/, int type /*$s2*/)
 // line 1174, offset 0x8006ae88
	/* begin block 1 */
		// Start line: 1175
		// Start offset: 0x8006AE88
		// Variables:
	// 		struct evObjectBirthProjectileData *rc; // $s0
	/* end block 1 */
	// End offset: 0x8006AE88
	// End Line: 1175

	/* begin block 2 */
		// Start line: 2545
	/* end block 2 */
	// End Line: 2546

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
 // line 1185, offset 0x8006aee0
	/* begin block 1 */
		// Start line: 1186
		// Start offset: 0x8006AEE0
		// Variables:
	// 		struct Object *ForceOb; // $a1
	// 		struct _Instance *iForce; // $s1
	// 		struct PhysObData *Data; // $s2
	// 		struct PhysObProperties *Prop; // $s0

		/* begin block 1.1 */
			// Start line: 1200
			// Start offset: 0x8006AF28
			// Variables:
		// 		struct __PhysObProjectileProperties *ProjProp; // $v1
		// 		struct __PhysObProjectileData *ProjData; // $s0

			/* begin block 1.1.1 */
				// Start line: 1223
				// Start offset: 0x8006AFB0
				// Variables:
			// 		struct __PhysObProjectileData *ProjData; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8006B004
			// End Line: 1235
		/* end block 1.1 */
		// End offset: 0x8006B054
		// End Line: 1257
	/* end block 1 */
	// End offset: 0x8006B058
	// End Line: 1266

	/* begin block 2 */
		// Start line: 2567
	/* end block 2 */
	// End Line: 2568

/* WARNING: Removing unreachable block (ram,0x8006af14) */
/* WARNING: Removing unreachable block (ram,0x8006af28) */
/* WARNING: Removing unreachable block (ram,0x8006af7c) */
/* WARNING: Removing unreachable block (ram,0x8006af8c) */
/* WARNING: Removing unreachable block (ram,0x8006afb0) */
/* WARNING: Removing unreachable block (ram,0x8006afe4) */
/* WARNING: Removing unreachable block (ram,0x8006b004) */
/* WARNING: Removing unreachable block (ram,0x8006b018) */
/* WARNING: Removing unreachable block (ram,0x8006b048) */

_Instance * BirthProjectilePhysOb(_Instance *instance,int grabJoint,int type)

{
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_SetLightTable(struct _PhysObLight *pLight /*$a0*/, struct LightInstance *li /*$a1*/, short burnAmplitude /*$a2*/)
 // line 1294, offset 0x8006b074
	/* begin block 1 */
		// Start line: 1297
		// Start offset: 0x8006B074
		// Variables:
	// 		long idx; // $a3
	// 		long frac; // $t2
	// 		struct LightTableEntry *ltable; // $t1
	// 		struct LightTableEntry *ltable2; // $a0
	/* end block 1 */
	// End offset: 0x8006B124
	// End Line: 1317

	/* begin block 2 */
		// Start line: 2815
	/* end block 2 */
	// End Line: 2816

	/* begin block 3 */
		// Start line: 2817
	/* end block 3 */
	// End Line: 2818

	/* begin block 4 */
		// Start line: 2821
	/* end block 4 */
	// End Line: 2822

void PHYSOB_SetLightTable(_PhysObLight *pLight,LightInstance *li,short burnAmplitude)

{
  int iVar1;
  LightTableEntry *pLVar2;
  LightTableEntry *pLVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (int)((uint)(ushort)gameTrackerX.vblCount * (int)pLight->speed) %
          ((uint)pLight->length << 0xc);
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
 // line 1323, offset 0x8006b1dc
	/* begin block 1 */
		// Start line: 1327
		// Start offset: 0x8006B1DC

		/* begin block 1.1 */
			// Start line: 1329
			// Start offset: 0x8006B1E4
		/* end block 1.1 */
		// End offset: 0x8006B1F8
		// End Line: 1339
	/* end block 1 */
	// End offset: 0x8006B1F8
	// End Line: 1340

	/* begin block 2 */
		// Start line: 2879
	/* end block 2 */
	// End Line: 2880

	/* begin block 3 */
		// Start line: 2882
	/* end block 3 */
	// End Line: 2883

void PHYSOB_EndLighting(_Instance *instance,_PhysObLight *pLight)

{
  if ((pLight != (_PhysObLight *)0x0) &&
     (gameTrackerX.gameData.asmData.lightInstances[0].lightInstance == instance)) {
    gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_StartLighting(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a3*/)
 // line 1342, offset 0x8006b200
	/* begin block 1 */
		// Start line: 1343
		// Start offset: 0x8006B200
		// Variables:
	// 		struct PhysObData *Data; // $a2

		/* begin block 1.1 */
			// Start line: 1358
			// Start offset: 0x8006B240
			// Variables:
		// 		struct LightInstance *li; // $a1
		/* end block 1.1 */
		// End offset: 0x8006B260
		// End Line: 1372
	/* end block 1 */
	// End offset: 0x8006B260
	// End Line: 1373

	/* begin block 2 */
		// Start line: 2917
	/* end block 2 */
	// End Line: 2918

void PHYSOB_StartLighting(_Instance *instance,_PhysObLight *pLight)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if (*(short *)(puVar1 + 0xd) < 0) {
    *(short *)(puVar1 + 0xd) = -*(short *)(puVar1 + 0xd);
  }
  *puVar1 = *puVar1 | 0x18000;
  if (pLight != (_PhysObLight *)0x0) {
    gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = instance;
    PHYSOB_SetLightTable
              (pLight,gameTrackerX.gameData.asmData.lightInstances,*(short *)(puVar1 + 0xd));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_StartBurnFX(struct _Instance *instance /*$s2*/)
 // line 1375, offset 0x8006b270
	/* begin block 1 */
		// Start line: 1376
		// Start offset: 0x8006B270
		// Variables:
	// 		struct PhysObData *Data; // $v0
	// 		struct Object *object; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x8006B2E4
	// End Line: 1392

	/* begin block 2 */
		// Start line: 2986
	/* end block 2 */
	// End Line: 2987

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
 // line 1394, offset 0x8006b2fc
	/* begin block 1 */
		// Start line: 3030
	/* end block 1 */
	// End Line: 3031

void PHYSOB_StartBurning(_Instance *instance,_PhysObLight *pLight)

{
  PHYSOB_StartBurnFX(instance);
  PHYSOB_StartLighting(instance,pLight);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PHYSOB_StopLighting(struct _Instance *instance /*$a0*/, struct _PhysObLight *pLight /*$a1*/)
 // line 1402, offset 0x8006b338
	/* begin block 1 */
		// Start line: 1404
		// Start offset: 0x8006B338
		// Variables:
	// 		struct PhysObData *Data; // $v0
	/* end block 1 */
	// End offset: 0x8006B338
	// End Line: 1404

	/* begin block 2 */
		// Start line: 3046
	/* end block 2 */
	// End Line: 3047

	/* begin block 3 */
		// Start line: 3047
	/* end block 3 */
	// End Line: 3048

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
 // line 1414, offset 0x8006b358
	/* begin block 1 */
		// Start line: 1416
		// Start offset: 0x8006B358
		// Variables:
	// 		struct PhysObData *Data; // $a0
	/* end block 1 */
	// End offset: 0x8006B358
	// End Line: 1418

	/* begin block 2 */
		// Start line: 3071
	/* end block 2 */
	// End Line: 3072

	/* begin block 3 */
		// Start line: 3072
	/* end block 3 */
	// End Line: 3073

	/* begin block 4 */
		// Start line: 3074
	/* end block 4 */
	// End Line: 3075

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
 // line 1426, offset 0x8006b37c
	/* begin block 1 */
		// Start line: 1427
		// Start offset: 0x8006B37C
		// Variables:
	// 		struct PhysObData *Data; // $s1
	/* end block 1 */
	// End offset: 0x8006B37C
	// End Line: 1427

	/* begin block 2 */
		// Start line: 3098
	/* end block 2 */
	// End Line: 3099

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
 // line 1444, offset 0x8006b3dc
	/* begin block 1 */
		// Start line: 1445
		// Start offset: 0x8006B3DC
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006B3DC
	// End Line: 1445

	/* begin block 2 */
		// Start line: 3135
	/* end block 2 */
	// End Line: 3136

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
// void /*$ra*/ InitPhysicalObject(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$s5*/)
 // line 1467, offset 0x8006b418
	/* begin block 1 */
		// Start line: 1468
		// Start offset: 0x8006B418
		// Variables:
	// 		struct PhysObData *Data; // $s2
	// 		struct PhysObProperties *Prop; // $s4

		/* begin block 1.1 */
			// Start line: 1475
			// Start offset: 0x8006B450
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $v0
		/* end block 1.1 */
		// End offset: 0x8006B484
		// End Line: 1483

		/* begin block 1.2 */
			// Start line: 1636
			// Start offset: 0x8006B60C
			// Variables:
		// 		struct PhysObCollectibleProperties *collectibleProp; // $s0
		/* end block 1.2 */
		// End offset: 0x8006B690
		// End Line: 1652

		/* begin block 1.3 */
			// Start line: 1660
			// Start offset: 0x8006B6C4
			// Variables:
		// 		struct PhysObInteractProperties *interact; // $s3

			/* begin block 1.3.1 */
				// Start line: 1670
				// Start offset: 0x8006B704
				// Variables:
			// 		int s; // $s0
			/* end block 1.3.1 */
			// End offset: 0x8006B754
			// End Line: 1675

			/* begin block 1.3.2 */
				// Start line: 1675
				// Start offset: 0x8006B75C
				// Variables:
			// 		int s; // $s0
			/* end block 1.3.2 */
			// End offset: 0x8006B7AC
			// End Line: 1681
		/* end block 1.3 */
		// End offset: 0x8006B880
		// End Line: 1705

		/* begin block 1.4 */
			// Start line: 1719
			// Start offset: 0x8006B8D4
			// Variables:
		// 		struct _G2SVector3_Type vec; // stack offset -40
		/* end block 1.4 */
		// End offset: 0x8006B8D4
		// End Line: 1719

		/* begin block 1.5 */
			// Start line: 1744
			// Start offset: 0x8006B99C
			// Variables:
		// 		struct PhysObSwitchProperties *switchProp; // $a2
		/* end block 1.5 */
		// End offset: 0x8006B9F0
		// End Line: 1762

		/* begin block 1.6 */
			// Start line: 1780
			// Start offset: 0x8006BA38
			// Variables:
		// 		struct _PhysObLight *pLight; // $a1

			/* begin block 1.6.1 */
				// Start line: 1783
				// Start offset: 0x8006BA48
				// Variables:
			// 		struct INICommand *index; // $s0
			/* end block 1.6.1 */
			// End offset: 0x8006BAAC
			// End Line: 1796
		/* end block 1.6 */
		// End offset: 0x8006BAAC
		// End Line: 1798
	/* end block 1 */
	// End offset: 0x8006BABC
	// End Line: 1808

	/* begin block 2 */
		// Start line: 2930
	/* end block 2 */
	// End Line: 2931

void InitPhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  int segment;
  uint *puVar1;
  ulong uVar2;
  INICommand *pIVar3;
  _PhysObLight *pLight;
  byte bVar4;
  _Model **pp_Var5;
  void *pvVar6;
  void *pvVar7;
  _G2Anim_Type *anim;
  void *pvVar8;
  _G2SVector3_Type local_28;
  
  if ((instance->flags & 0x20000U) != 0) {
    if (*(short *)((int)instance->data + 0x1c) == 2) {
      segment = SetObjectIdleData(0,(_Instance *)0x0);
      INSTANCE_Post(gameTracker->playerInstance,0x800024,segment);
    }
    MEMPACK_Free((char *)instance->extraData);
    return;
  }
  pvVar8 = instance->data;
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
  if ((*(ushort *)((int)pvVar8 + 6) & 0x40) != 0) {
    *(ushort *)((int)pvVar8 + 6) = *(ushort *)((int)pvVar8 + 6) | 0x8000;
  }
  if ((*(ushort *)((int)pvVar8 + 6) & 0x8000) != 0) {
    G2EmulationInstanceSetTotalSections(instance,1);
    G2EmulationInstanceSetStartAndEndSegment
              (instance,0,0,
               (short)(((uint)*(ushort *)
                               &instance->object->modelList[instance->currentModel]->numSegments - 1
                       ) * 0x10000 >> 0x10));
    G2EmulationInstanceSetAnimation(instance,0,0,0,0);
    G2EmulationInstanceSetMode(instance,0,2);
  }
  if (*(short *)((int)pvVar8 + 2) == 5) {
    pvVar7 = instance->data;
    bVar4 = *(byte *)((int)pvVar7 + 0x10);
    if (bVar4 != 0xff) {
      G2EmulationInstanceSetAnimation(instance,0,(uint)bVar4,0,0);
      G2EmulationInstanceSetMode(instance,0,2);
    }
    if (((*(short *)((int)pvVar7 + 8) == 2) && (gameTrackerX.playerInstance != (_Instance *)0x0)) &&
       (uVar2 = INSTANCE_Query(gameTrackerX.playerInstance,0x24), (uVar2 & 0xfc0000) == 0)) {
      instance->flags = instance->flags | 0x20;
    }
  }
  if ((*(ushort *)((int)pvVar8 + 6) & 0x8d00) != 0) {
    *puVar1 = *puVar1 | 0x1000;
  }
  if (*(short *)((int)pvVar8 + 2) != 3) {
    segment = CheckPhysObAbility(instance,1);
    if (segment == 0) {
      segment = CheckPhysObAbility(instance,8);
      if (segment == 0) {
        segment = CheckPhysObAbility(instance,0x40);
        if (segment != 0) {
          pvVar6 = instance->data;
          pvVar7 = instance->extraData;
          bVar4 = *(byte *)((int)pvVar6 + 0x18);
          *(undefined2 *)((int)pvVar7 + 0x16) = 0;
          *(ushort *)((int)pvVar7 + 0x14) = (ushort)bVar4;
          if (*(char *)((int)pvVar6 + 0x19) == -1) {
            *(undefined *)((int)pvVar6 + 0x19) = 0;
          }
          G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar6 + 0x19),0,0);
          G2EmulationInstanceInitSection(instance,0,PhysobAnimCallback,instance);
        }
        segment = CheckPhysObFamily(instance,7);
        if (segment != 0) {
          G2EmulationInstanceInitSection(instance,0,PhysobAnimCallback,instance);
        }
      }
      else {
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
        local_28.y = 0;
        local_28.x = 0;
        local_28.z = (instance->rotation).z;
        (instance->rotation).z = 0;
        G2Anim_SetController_Vector(anim,2,0xe,&local_28);
      }
    }
    else {
      TurnOffCollisionPhysOb(instance,7);
    }
    goto LAB_8006ba18;
  }
  pvVar7 = instance->extraData;
  *(ushort *)((int)pvVar7 + 4) = *(ushort *)((int)pvVar8 + 6) | 0x80;
  *(undefined2 *)((int)pvVar7 + 6) = 0;
  pp_Var5 = instance->object->modelList;
  pvVar7 = instance->data;
  if (pp_Var5 != (_Model **)0x0) {
    if ((*(byte *)((int)pvVar7 + 0x15) & 8) == 0) {
      segment = 0;
      if (0 < (*pp_Var5)->numSegments) {
        do {
          COLLIDE_SegmentCollisionOn(instance,segment);
          segment = segment + 1;
        } while (segment < (*instance->object->modelList)->numSegments);
      }
    }
    else {
      segment = 0;
      if (0 < (*pp_Var5)->numSegments) {
        do {
          COLLIDE_SegmentCollisionOff(instance,segment);
          segment = segment + 1;
        } while (segment < (*instance->object->modelList)->numSegments);
      }
    }
  }
  TurnOffCollisionPhysOb(instance,7);
  if ((*(ushort *)((int)pvVar8 + 6) & 0x8000) == 0) goto LAB_8006b838;
  bVar4 = *(byte *)((int)pvVar7 + 0x15) & 3;
  if (bVar4 == 1) {
    segment = 1;
LAB_8006b830:
    G2EmulationInstanceSetMode(instance,0,segment);
  }
  else {
    if (bVar4 < 2) {
      if ((*(byte *)((int)pvVar7 + 0x15) & 3) == 0) {
        segment = 2;
        goto LAB_8006b830;
      }
    }
    else {
      if (bVar4 == 2) {
        segment = 0;
        goto LAB_8006b830;
      }
    }
  }
LAB_8006b838:
  if ((*(byte *)((int)pvVar7 + 0x10) != 0xff) && ((*(ushort *)((int)pvVar8 + 6) & 0x8000) != 0)) {
    G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar7 + 0x10),0,0);
  }
  if (*(short *)((int)pvVar7 + 0x1c) == 2) {
    segment = SetObjectIdleData(1,instance);
    INSTANCE_Post(gameTracker->playerInstance,0x800024,segment);
  }
LAB_8006ba18:
  if (*(short *)((int)pvVar8 + 2) == 7) {
    instance->flags2 = instance->flags2 | 0x20000;
  }
  segment = CheckPhysObAbility(instance,0x20);
  if (segment != 0) {
    pIVar3 = INSTANCE_FindIntroCommand(instance,0x15);
    pLight = PhysObGetLight(instance);
    if ((pLight == (_PhysObLight *)0x0) ||
       ((pIVar3 != (INICommand *)0x0 && (((uint)pIVar3[1] & 1) != 0)))) {
      PHYSOB_EndBurning(instance,pLight);
    }
    else {
      *(undefined2 *)(puVar1 + 0xd) = 0;
      PHYSOB_StartBurnFX(instance);
      *puVar1 = *puVar1 | 0x10000;
    }
  }
  instance->flags = instance->flags | 0x10000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessPhysicalObject(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$s4*/)
 // line 1814, offset 0x8006bae0
	/* begin block 1 */
		// Start line: 1815
		// Start offset: 0x8006BAE0
		// Variables:
	// 		struct PhysObData *Data; // $s1

		/* begin block 1.1 */
			// Start line: 1823
			// Start offset: 0x8006BB14
			// Variables:
		// 		struct _PhysObLight *pLight; // $a0

			/* begin block 1.1.1 */
				// Start line: 1830
				// Start offset: 0x8006BB28
				// Variables:
			// 		struct LightInstance *li; // $a1
			/* end block 1.1.1 */
			// End offset: 0x8006BB70
			// End Line: 1836
		/* end block 1.1 */
		// End offset: 0x8006BB70
		// End Line: 1837

		/* begin block 1.2 */
			// Start line: 1858
			// Start offset: 0x8006BBE4
			// Variables:
		// 		struct PhysObWeaponProperties *properties; // $v0

			/* begin block 1.2.1 */
				// Start line: 1864
				// Start offset: 0x8006BC14
				// Variables:
			// 		struct _PhysObLight *pLight; // $a1
			/* end block 1.2.1 */
			// End offset: 0x8006BC4C
			// End Line: 1871
		/* end block 1.2 */
		// End offset: 0x8006BC4C
		// End Line: 1871

		/* begin block 1.3 */
			// Start line: 1888
			// Start offset: 0x8006BCAC
		/* end block 1.3 */
		// End offset: 0x8006BD50
		// End Line: 1908

		/* begin block 1.4 */
			// Start line: 1913
			// Start offset: 0x8006BD64
			// Variables:
		// 		struct PhysObAnimatedProperties *Prop; // $v0
		/* end block 1.4 */
		// End offset: 0x8006BDB4
		// End Line: 1921

		/* begin block 1.5 */
			// Start line: 1925
			// Start offset: 0x8006BDC8
		/* end block 1.5 */
		// End offset: 0x8006BE10
		// End Line: 1937

		/* begin block 1.6 */
			// Start line: 1989
			// Start offset: 0x8006BF34
			// Variables:
		// 		struct PhysObCollectibleProperties *collectibleProp; // $a2
		/* end block 1.6 */
		// End offset: 0x8006BF84
		// End Line: 1996

		/* begin block 1.7 */
			// Start line: 2001
			// Start offset: 0x8006BF98
			// Variables:
		// 		struct Level *level; // $s2

			/* begin block 1.7.1 */
				// Start line: 2004
				// Start offset: 0x8006BFC0
				// Variables:
			// 		struct _PhysObLight *pLight; // $a1
			/* end block 1.7.1 */
			// End offset: 0x8006BFFC
			// End Line: 2011
		/* end block 1.7 */
		// End offset: 0x8006BFFC
		// End Line: 2012

		/* begin block 1.8 */
			// Start line: 2018
			// Start offset: 0x8006C010
			// Variables:
		// 		int rc; // $s3
		// 		int upperOffset; // $v1
		// 		short lowerOffset; // $a1
		// 		int wasFalling; // $s2

			/* begin block 1.8.1 */
				// Start line: 2088
				// Start offset: 0x8006C268
			/* end block 1.8.1 */
			// End offset: 0x8006C27C
			// End Line: 2092

			/* begin block 1.8.2 */
				// Start line: 2140
				// Start offset: 0x8006C388
				// Variables:
			// 		struct _PCollideInfo CInfo; // stack offset -88
			// 		struct SVECTOR Old; // stack offset -40
			// 		struct SVECTOR New; // stack offset -32
			// 		short len; // $a2
			// 		long mult; // $a3
			/* end block 1.8.2 */
			// End offset: 0x8006C460
			// End Line: 2173
		/* end block 1.8 */
		// End offset: 0x8006C460
		// End Line: 2173
	/* end block 1 */
	// End offset: 0x8006C508
	// End Line: 2218

	/* begin block 2 */
		// Start line: 4010
	/* end block 2 */
	// End Line: 4011

void ProcessPhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  byte bVar1;
  ushort uVar2;
  _PhysObLight *pLight;
  int Data;
  _Instance *p_Var3;
  uint uVar4;
  ulong uVar5;
  Level *pLVar6;
  uint uVar7;
  void *pvVar8;
  short sVar9;
  short burnAmplitude;
  uint *puVar10;
  int iVar11;
  int iVar12;
  _PCollideInfo _Stack88;
  SVECTOR local_28;
  SVECTOR local_20;
  
  puVar10 = (uint *)instance->extraData;
  if (((instance == (gameTracker->gameData).asmData.lightInstances[0].lightInstance) &&
      (pLight = PhysObGetLight(instance), pLight != (_PhysObLight *)0x0)) &&
     ((gameTracker->gameData).asmData.lightInstances[0].lightInstance == instance)) {
    burnAmplitude = 0x1000;
    if (((*puVar10 & 0x8000) != 0) && (burnAmplitude = *(short *)(puVar10 + 0xd), burnAmplitude < 0)
       ) {
      burnAmplitude = -burnAmplitude;
    }
    PHYSOB_SetLightTable(pLight,(gameTracker->gameData).asmData.lightInstances,burnAmplitude);
  }
  Data = CheckPhysObAbility(instance,2);
  if (Data != 0) {
    p_Var3 = PHYSOBS_IsAnythingAttached(instance);
    if (p_Var3 == (_Instance *)0x0) {
      uVar4 = instance->flags2 & 0xffffff7f;
    }
    else {
      uVar4 = instance->flags2 | 0x80;
    }
    instance->flags2 = uVar4;
  }
  if ((*puVar10 & 0x8000) != 0) {
    uVar2 = *(short *)(puVar10 + 0xd) + 0x88;
    if (*(short *)(puVar10 + 0xd) < 0) {
      *(ushort *)(puVar10 + 0xd) = uVar2;
      if (-1 < (int)((uint)uVar2 << 0x10)) {
        *(undefined2 *)(puVar10 + 0xd) = 0;
        *puVar10 = *puVar10 & 0xffff7fff;
        if ((*(ushort *)((int)instance->data + 6) & 0x20) != 0) {
          pLight = PhysObGetLight(instance);
          if ((*puVar10 & 0x40000) == 0) {
            PHYSOB_EndLighting(instance,pLight);
          }
          else {
            PHYSOB_EndBurning(instance,pLight);
          }
          *puVar10 = *puVar10 & 0xfffbffff;
        }
      }
    }
    else {
      *(ushort *)(puVar10 + 0xd) = uVar2;
      if (0xfff < (short)uVar2) {
        *(undefined2 *)(puVar10 + 0xd) = 0x1000;
        *puVar10 = *puVar10 & 0xffff7fff;
      }
    }
  }
  Data = CheckPhysObFamily(instance,5);
  if (Data != 0) {
    pvVar8 = instance->extraData;
    if (0 < *(int *)((int)pvVar8 + 4)) {
      Data = *(int *)((int)pvVar8 + 4) - gameTrackerX.idleTime;
      *(int *)((int)pvVar8 + 4) = Data;
      if (Data < 0) {
        *(undefined4 *)((int)pvVar8 + 4) = 0;
        INSTANCE_KillInstance(instance);
      }
      else {
        if (Data < 0x1e000) {
          instance->fadeValue = 0x1000 - (short)(Data / 0x1e);
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
  Data = CheckPhysObFamily(instance,6);
  if ((Data != 0) && ((*(ushort *)((int)instance->data + 8) & 1) != 0)) {
    uVar5 = INSTANCE_Query(gameTrackerX.playerInstance,0x24);
    if ((uVar5 & 0x10) == 0) {
      uVar4 = instance->flags | 0x800;
    }
    else {
      uVar4 = instance->flags & 0xfffff7ff;
    }
    instance->flags = uVar4;
  }
  Data = CheckPhysObAbility(instance,0x40);
  if (Data != 0) {
    if ((*puVar10 & 0x100000) != 0) {
      *(ushort *)((int)instance->extraData + 0x14) =
           *(ushort *)((int)instance->extraData + 0x14) & 0xfff3;
      *puVar10 = *puVar10 & 0xffefffff;
    }
    if ((*puVar10 & 0x800) == 0) {
      return;
    }
    G2EmulationInstancePlayAnimation(instance);
    return;
  }
  Data = CheckPhysObAbility(instance,0x8000);
  if (Data != 0) {
    G2EmulationInstancePlayAnimation(instance);
  }
  if ((*puVar10 & 1) == 0) {
    if ((*puVar10 & 8) != 0) {
      ExecuteFlip(instance);
    }
    if ((*puVar10 & 0x100) != 0) {
      ExecuteSlopeSlideToStop(instance);
    }
    if (((*puVar10 & 1) == 0) && ((*puVar10 & 0x40) != 0)) {
      ExecuteDrag(instance);
    }
  }
  if ((*puVar10 & 2) != 0) {
    ExecuteSlideToStop(instance);
  }
  if ((*puVar10 & 0x4000) != 0) {
    ExecuteGravitate(instance);
  }
  if ((*puVar10 & 0x10) != 0) {
    ExecuteThrow(instance);
  }
  if ((*puVar10 & 0x20) != 0) {
    ExecuteFollow(instance);
  }
  if (((*puVar10 & 0x100000) != 0) && (Data = CheckPhysObFamily(instance,5), Data != 0)) {
    bVar1 = *(byte *)((int)instance->data + 0x10);
    if (bVar1 != 0xff) {
      G2EmulationInstanceSetAnimation(instance,0,(uint)bVar1,0,0);
      G2EmulationInstanceSetMode(instance,0,2);
    }
    *puVar10 = *puVar10 & 0xffefffff;
  }
  if (((((*puVar10 & 0x10000) != 0) &&
       (pLVar6 = STREAM_GetLevelWithID(instance->currentStreamUnitID), pLVar6 != (Level *)0x0)) &&
      (instance->matrix != (MATRIX *)0x0)) &&
     (pLight = PhysObGetLight(instance),
     instance->matrix[pLight->segment].t[2] < pLVar6->waterZLevel)) {
    PHYSOB_EndBurning(instance,pLight);
  }
  uVar4 = *puVar10;
  if ((uVar4 & 0x1000) != 0) {
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
    goto LAB_8006c4b8;
  }
  Data = (int)(instance->oldPos).z - (int)(instance->position).z;
  if (Data < 0xa0) {
    Data = 0xa0;
  }
  iVar11 = instance->zAccl * gameTrackerX.idleTime;
  if (iVar11 < 0) {
    iVar11 = iVar11 + 0xfff;
  }
  iVar12 = instance->zVel * gameTrackerX.idleTime;
  if (iVar12 < 0) {
    iVar12 = iVar12 + 0xfff;
  }
  iVar11 = (int)(short)(iVar11 >> 0xc) * gameTrackerX.idleTime;
  if (iVar11 < 0) {
    iVar11 = iVar11 + 0x1fff;
  }
  iVar11 = 0x40 - ((iVar12 >> 0xc) + (iVar11 >> 0xd));
  burnAmplitude = (short)iVar11;
  iVar12 = iVar11 * 0x10000;
  if (iVar11 * 0x10000 >> 0x10 < 0xa0) {
    burnAmplitude = 0xa0;
    iVar12 = 0xa00000;
  }
  sVar9 = (short)((uint)iVar12 >> 0x10);
  if (iVar12 >> 0x10 < Data) {
    sVar9 = (short)Data;
    burnAmplitude = (short)Data;
  }
  Data = SetPhysicsGravityData((int)sVar9,(int)burnAmplitude,0,0,0,0xb50);
  uVar7 = PhysicsCheckGravity(instance,Data,5);
  if ((uVar7 & 1) == 0) {
LAB_8006c2c4:
    Data = instance->attachedID;
code_r0x8006c2cc:
    if ((Data == 0) && (instance->oldMatrix != (MATRIX *)0x0)) {
      if ((instance->zVel == 0) && ((instance->object->oflags & 0x400U) != 0)) {
        instance->zVel = -0x32;
      }
      instance->zAccl = -10;
      *puVar10 = *puVar10 | 4;
    }
    else {
      instance->zAccl = 0;
      instance->zVel = 0;
    }
  }
  else {
    Data = instance->attachedID;
    if ((Data != 0) && ((uVar4 & 4) == 0)) goto code_r0x8006c2cc;
    if ((instance->wNormal).z < 0xb51) goto LAB_8006c2c4;
    Data = instance->zVel;
    if ((*puVar10 & 0x14) != 0) {
      PHYSOB_PlayDropSound(instance);
    }
    uVar4 = *puVar10;
    *puVar10 = uVar4 & 0xfffffffb;
    if ((uVar4 & 0x400000) == 0) {
      *puVar10 = uVar4 & 0xff7ffffb;
    }
    else {
      *puVar10 = uVar4 & 0xffbffffb | 0x200000;
      TurnOnCollisionPhysOb(instance,7);
    }
    if ((*puVar10 & 0x10) != 0) {
      instance->flags2 = instance->flags2 & 0xffffff7f;
    }
    uVar4 = *puVar10;
    *puVar10 = uVar4 & 0xffffffef;
    if ((uVar4 & 0x200000) == 0) {
      TurnOffCollisionPhysOb(instance,4);
    }
    if ((uVar7 & 0x80000) == 0) {
      instance->zVel = -1;
    }
    else {
      *puVar10 = *puVar10 | 0x1000;
      instance->zAccl = 0;
      instance->zVel = 0;
    }
    if ((instance->oldMatrix != (MATRIX *)0x0) && ((*puVar10 & 0x18000) == 0x10000)) {
      pLight = PhysObGetLight(instance);
      PHYSOB_StopLighting(instance,pLight);
    }
    iVar11 = CheckPhysObAbility(instance,8);
    if ((iVar11 != 0) && ((*puVar10 & 0x100) == 0)) {
      if (Data < -0x32) {
        instance->zAccl = 0;
        ResetOrientation(instance);
      }
      *(short *)((int)puVar10 + 0x12) = (instance->position).z;
    }
  }
  if (((((instance->object->oflags & 0x80000U) == 0) &&
       (gameTrackerX.gameData.asmData.MorphType == 0)) &&
      (gameTrackerX.gameData.asmData.MorphTime != 1000)) && ((instance->flags2 & 0x8000000U) == 0))
  {
    _Stack88.newPoint = &local_20;
    local_28.vx = (instance->position).x;
    local_28.vy = (instance->position).y;
    local_28.vz = (instance->position).z;
    local_20.vz = local_28.vz - 0x500;
    _Stack88.oldPoint = &local_28;
    local_20.vx = local_28.vx;
    local_20.vy = local_28.vy;
    PHYSICS_CheckLineInWorld(instance,&_Stack88);
    instance->zAccl = 0;
    burnAmplitude = (short)((uint)local_28.vz - (uint)local_20.vz);
    if (0x3bf < (int)(((uint)local_28.vz - (uint)local_20.vz) * 0x10000) >> 0x10) {
      uVar2 = (instance->position).z;
      burnAmplitude =
           uVar2 - (*(ushort *)((int)puVar10 + 0x12) +
                   ((short)((uint)((((int)(((uint)*(ushort *)((int)puVar10 + 0x12) - (uint)uVar2) *
                                          0x10000) >> 0x10) / 0x280) * 0x10000) >> 0x10) + 1) *
                   -0x280);
    }
    instance->zVel =
         -(int)(short)((uint)((((int)burnAmplitude * 1000) /
                               ((1000 - (int)gameTrackerX.gameData.asmData.MorphTime) * 0x32) <<
                              0x10) >> 4) / gameTrackerX.idleTime);
  }
LAB_8006c4b8:
  if (((*puVar10 & 0x200000) != 0) && (Data = PHYSOB_ReAlignFalling(instance,-900), Data != 0)) {
    *puVar10 = *puVar10 & 0xff5fffff;
    TurnOffCollisionPhysOb(instance,7);
  }
  PhysicsMove(instance,&instance->position,gameTracker->idleTime);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ PhysicalObjectQuery(struct _Instance *instance /*$s0*/, unsigned long Query /*$a1*/)
 // line 2223, offset 0x8006c528
	/* begin block 1 */
		// Start line: 2224
		// Start offset: 0x8006C528
		// Variables:
	// 		struct PhysObData *Data; // $a0
	// 		int trueValue; // $s1

		/* begin block 1.1 */
			// Start line: 2252
			// Start offset: 0x8006C5E4
		/* end block 1.1 */
		// End offset: 0x8006C608
		// End Line: 2261

		/* begin block 1.2 */
			// Start line: 2268
			// Start offset: 0x8006C638
		/* end block 1.2 */
		// End offset: 0x8006C660
		// End Line: 2271

		/* begin block 1.3 */
			// Start line: 2279
			// Start offset: 0x8006C690
			// Variables:
		// 		struct _G2EulerAngles_Type ea; // stack offset -24
		/* end block 1.3 */
		// End offset: 0x8006C6BC
		// End Line: 2282

		/* begin block 1.4 */
			// Start line: 2287
			// Start offset: 0x8006C6BC
			// Variables:
		// 		struct PhysObProperties *Prop; // $a0

			/* begin block 1.4.1 */
				// Start line: 2291
				// Start offset: 0x8006C6D4
			/* end block 1.4.1 */
			// End offset: 0x8006C6E8
			// End Line: 2294

			/* begin block 1.4.2 */
				// Start line: 2296
				// Start offset: 0x8006C6F0
			/* end block 1.4.2 */
			// End offset: 0x8006C6FC
			// End Line: 2299

			/* begin block 1.4.3 */
				// Start line: 2301
				// Start offset: 0x8006C704
			/* end block 1.4.3 */
			// End offset: 0x8006C710
			// End Line: 2304
		/* end block 1.4 */
		// End offset: 0x8006C71C
		// End Line: 2312

		/* begin block 1.5 */
			// Start line: 2322
			// Start offset: 0x8006C744
			// Variables:
		// 		struct PhysObCollectibleProperties *collectibleProp; // $v0
		/* end block 1.5 */
		// End offset: 0x8006C760
		// End Line: 2325

		/* begin block 1.6 */
			// Start line: 2370
			// Start offset: 0x8006C7BC
			// Variables:
		// 		struct PhysObDraftProperties *DraftProp; // $t0
		// 		struct INICommand *index; // $v0
		/* end block 1.6 */
		// End offset: 0x8006C814
		// End Line: 2382

		/* begin block 1.7 */
			// Start line: 2389
			// Start offset: 0x8006C814
			// Variables:
		// 		struct evControlSaveDataData *pdata; // $v0
		/* end block 1.7 */
		// End offset: 0x8006C838
		// End Line: 2397

		/* begin block 1.8 */
			// Start line: 2405
			// Start offset: 0x8006C850
		/* end block 1.8 */
		// End offset: 0x8006C874
		// End Line: 2417

		/* begin block 1.9 */
			// Start line: 2420
			// Start offset: 0x8006C874
			// Variables:
		// 		struct PhysObSwitchProperties *Prop; // $v0

			/* begin block 1.9.1 */
				// Start line: 2425
				// Start offset: 0x8006C88C
				// Variables:
			// 		struct PhysObData *Data; // $v0
			/* end block 1.9.1 */
			// End offset: 0x8006C8B0
			// End Line: 2437
		/* end block 1.9 */
		// End offset: 0x8006C8B0
		// End Line: 2438
	/* end block 1 */
	// End offset: 0x8006C8D4
	// End Line: 2451

	/* begin block 2 */
		// Start line: 4854
	/* end block 2 */
	// End Line: 4855

/* WARNING: Type propagation algorithm not settling */

ulong PhysicalObjectQuery(_Instance *instance,ulong Query)

{
  short sVar1;
  int iVar2;
  INICommand *pIVar3;
  ushort family;
  void *pvVar4;
  MATRIX *pMVar5;
  _G2EulerAngles_Type local_18;
  
  pMVar5 = (MATRIX *)0x1;
  switch(Query) {
  case 1:
    iVar2 = CheckPhysOb(instance);
    if (iVar2 != 0) {
      iVar2 = CheckPhysObFamily(instance,6);
      if (iVar2 == 0) {
        return (ulong)(MATRIX *)&DAT_00000020;
      }
      if ((*(ushort *)((int)instance->data + 8) & 1) != 0) {
        if ((instance->flags & 0x800U) == 0) {
          return (ulong)(MATRIX *)&DAT_00000020;
        }
        return (ulong)(MATRIX *)0x0;
      }
      return (ulong)(MATRIX *)&DAT_00000020;
    }
    goto switchD_8006c568_caseD_8;
  case 2:
    pMVar5 = (MATRIX *)GetPhysicalAbility(instance);
    break;
  case 3:
    pMVar5 = *(MATRIX **)((MATRIX *)instance->extraData)->m;
    break;
  case 4:
    pvVar4 = instance->data;
    sVar1 = *(short *)((int)pvVar4 + 2);
    if (sVar1 == 3) {
      pMVar5 = (MATRIX *)(int)*(short *)((int)instance->extraData + 6);
    }
    else {
      if (sVar1 == 0) {
        pMVar5 = (MATRIX *)(int)*(char *)((int)pvVar4 + 0x14);
      }
      else {
        if (sVar1 == 2) {
          pMVar5 = (MATRIX *)(int)*(short *)((int)pvVar4 + 10);
        }
        else {
          pMVar5 = (MATRIX *)((uint)(sVar1 == 7) << 3);
        }
      }
    }
    break;
  case 5:
    pvVar4 = instance->extraData;
    iVar2 = CheckPhysObAbility(instance,0x40);
    pMVar5 = (MATRIX *)0x0;
    if (iVar2 != 0) {
      pMVar5 = (MATRIX *)(int)*(short *)((int)pvVar4 + 0x14);
    }
    break;
  case 6:
    pMVar5 = (MATRIX *)
             SetPositionData((int)(instance->position).x,(int)(instance->position).y,
                             (int)(instance->position).z);
    break;
  case 7:
    iVar2 = CheckPhysObAbility(instance,0x40);
    if (iVar2 == 0) {
      iVar2 = CheckPhysObAbility(instance,0x80);
      if (iVar2 == 0) {
        G2EulerAngles_FromMatrix(&local_18,(_G2Matrix_Type *)(instance->matrix + 2),0);
        pMVar5 = (MATRIX *)SetPositionData((int)local_18.x,(int)local_18.y,(int)local_18.z);
      }
      else {
        pMVar5 = (MATRIX *)
                 SetPositionData((int)(instance->rotation).x,(int)(instance->rotation).y,
                                 (int)(instance->rotation).z);
      }
    }
    else {
      pMVar5 = (MATRIX *)
               SetPositionData(0,0,(int)(((uint)(ushort)(instance->rotation).z +
                                         (uint)*(ushort *)((int)instance->extraData + 0x16)) *
                                        0x10000) >> 0x10);
    }
    break;
  default:
    goto switchD_8006c568_caseD_8;
  case 0xb:
    pMVar5 = (MATRIX *)0x3;
    break;
  case 0xc:
  case 0xd:
    pMVar5 = instance->matrix;
    break;
  case 0xe:
    iVar2 = CheckPhysObFamily(instance,5);
    if (iVar2 != 0) {
      return (ulong)(instance->matrix + *(ushort *)((int)instance->data + 0x12));
    }
    goto switchD_8006c568_caseD_8;
  case 0x15:
    family = 3;
    goto LAB_8006c768;
  case 0x16:
    iVar2 = CheckPhysObAbility(instance,0x100);
    if (iVar2 != 0) {
      pIVar3 = INSTANCE_FindIntroCommand(instance,0x13);
      if (pIVar3 == (INICommand *)0x0) {
        pvVar4 = instance->data;
      }
      else {
        pvVar4 = (void *)((int)instance->data + (int)pIVar3[1] * 0x14);
      }
      pMVar5 = (MATRIX *)
               SetObjectDraftData(*(short *)((int)pvVar4 + 8),*(ushort *)((int)pvVar4 + 10),
                                  *(ushort *)((int)pvVar4 + 0xc),*(ushort *)((int)pvVar4 + 0x10),
                                  (int)*(short *)((int)pvVar4 + 0xe));
      return (ulong)pMVar5;
    }
switchD_8006c568_caseD_8:
    pMVar5 = (MATRIX *)0x0;
    break;
  case 0x17:
    iVar2 = CheckPhysObAbility(instance,0x40);
    if (iVar2 == 0) {
      return (ulong)(MATRIX *)0x0;
    }
    goto LAB_8006c8c4;
  case 0x18:
    pMVar5 = (MATRIX *)CIRC_Alloc(8);
    *(undefined4 *)pMVar5->m = 4;
    *(int *)(pMVar5->m + 2) = (int)instance->extraData + 0x14;
    break;
  case 0x1b:
    pMVar5 = (MATRIX *)0x0;
  case 0x1a:
    iVar2 = CheckPhysObFamily(instance,2);
    if (iVar2 == 0) {
      if (*(short *)((int)instance->data + 10) != 0) {
        return (ulong)pMVar5;
      }
      if ((*(uint *)instance->extraData & 0x2000) != 0) {
        return (ulong)(MATRIX *)((uint)pMVar5 ^ 1);
      }
    }
    else {
      if ((*(ushort *)((int)instance->extraData + 0x14) & 2) == 0) {
        return (ulong)(MATRIX *)((uint)pMVar5 ^ 1);
      }
    }
    break;
  case 0x1c:
    iVar2 = CheckPhysObAbility(instance,0x40);
    goto joined_r0x8006c798;
  case 0x1d:
    family = 5;
LAB_8006c768:
    iVar2 = CheckPhysObFamily(instance,family);
joined_r0x8006c798:
    pMVar5 = (MATRIX *)0x0;
    if (iVar2 != 0) {
LAB_8006c8c4:
      pMVar5 = (MATRIX *)instance->data;
    }
  }
  return (ulong)pMVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicalObjectPost(struct _Instance *instance /*$s3*/, unsigned long Message /*$s0*/, unsigned long Data /*$s1*/)
 // line 2455, offset 0x8006c8e8
	/* begin block 1 */
		// Start line: 2456
		// Start offset: 0x8006C8E8
		// Variables:
	// 		struct evObjectData *Ptr; // $s2
	// 		struct PhysObData *PData; // $a0

		/* begin block 1.1 */
			// Start line: 2504
			// Start offset: 0x8006CC30
		/* end block 1.1 */
		// End offset: 0x8006CC4C
		// End Line: 2510

		/* begin block 1.2 */
			// Start line: 2530
			// Start offset: 0x8006CC5C
			// Variables:
		// 		struct PhysObSwitchProperties *Prop; // $s1

			/* begin block 1.2.1 */
				// Start line: 2534
				// Start offset: 0x8006CC70
			/* end block 1.2.1 */
			// End offset: 0x8006CC90
			// End Line: 2543

			/* begin block 1.2.2 */
				// Start line: 2550
				// Start offset: 0x8006CCB4
				// Variables:
			// 		struct PhysObData *Data; // $a0
			/* end block 1.2.2 */
			// End offset: 0x8006CCCC
			// End Line: 2559
		/* end block 1.2 */
		// End offset: 0x8006CCCC
		// End Line: 2559

		/* begin block 1.3 */
			// Start line: 2567
			// Start offset: 0x8006CCE0
			// Variables:
		// 		struct SwitchData *switchData1; // $v0
		/* end block 1.3 */
		// End offset: 0x8006CD04
		// End Line: 2576

		/* begin block 1.4 */
			// Start line: 2579
			// Start offset: 0x8006CD04
		/* end block 1.4 */
		// End offset: 0x8006CD0C
		// End Line: 2586

		/* begin block 1.5 */
			// Start line: 2593
			// Start offset: 0x8006CD4C
			// Variables:
		// 		struct PhysObCollectibleProperties *collectibleProp; // $a2
		/* end block 1.5 */
		// End offset: 0x8006CDF8
		// End Line: 2620

		/* begin block 1.6 */
			// Start line: 2622
			// Start offset: 0x8006CDF8
		/* end block 1.6 */
		// End offset: 0x8006CE20
		// End Line: 2634

		/* begin block 1.7 */
			// Start line: 2660
			// Start offset: 0x8006CE84
			// Variables:
		// 		struct _PhysObLight *pLight; // $a1

			/* begin block 1.7.1 */
				// Start line: 2674
				// Start offset: 0x8006CED8
				// Variables:
			// 		struct PhysObData *podata; // $v1
			/* end block 1.7.1 */
			// End offset: 0x8006CED8
			// End Line: 2674
		/* end block 1.7 */
		// End offset: 0x8006CF00
		// End Line: 2685

		/* begin block 1.8 */
			// Start line: 2694
			// Start offset: 0x8006CF34
		/* end block 1.8 */
		// End offset: 0x8006CF34
		// End Line: 2695

		/* begin block 1.9 */
			// Start line: 2702
			// Start offset: 0x8006CF40
		/* end block 1.9 */
		// End offset: 0x8006CF70
		// End Line: 2709
	/* end block 1 */
	// End offset: 0x8006CF70
	// End Line: 2713

	/* begin block 2 */
		// Start line: 5327
	/* end block 2 */
	// End Line: 5328

void PhysicalObjectPost(_Instance *instance,ulong Message,ulong Data)

{
  int Mode;
  _PhysObLight *pLight;
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  void *pvVar4;
  
  puVar3 = (uint *)instance->extraData;
  if (Message == 0x800010) {
    ThrowPhysOb(instance,(evObjectThrowData *)Data);
    return;
  }
  if (Message < 0x800011) {
    if (Message == 0x200005) {
      uVar2 = *puVar3;
      uVar1 = 0x1000000;
LAB_8006ce60:
      *puVar3 = uVar2 | uVar1;
      return;
    }
    if (Message < 0x200006) {
      if (Message == 0x100007) {
        puVar3[5] = **(uint **)(Data + 4);
        return;
      }
      if (Message < 0x100008) {
        if (Message == 0x40002) {
          ScriptKillInstance(instance,Data);
          return;
        }
        if (Message != 0x80003) {
          return;
        }
        ScriptKillInstance(instance,5);
        return;
      }
      if (Message == 0x200002) {
        TurnOnCollisionPhysOb(instance,Data);
        return;
      }
      if (0x200002 < Message) {
        if (Message != 0x200003) {
          return;
        }
        TurnOffCollisionPhysOb(instance,Data);
        return;
      }
      if (Message != 0x100008) {
        return;
      }
      if (puVar3 == (uint *)0x0) {
        return;
      }
      *(short *)((int)puVar3 + 0xe) = *(short *)((int)puVar3 + 0xe) + *(short *)Data;
      *(short *)(puVar3 + 4) = *(short *)(puVar3 + 4) + *(short *)(Data + 2);
      *(short *)((int)puVar3 + 0x12) = *(short *)((int)puVar3 + 0x12) + *(short *)(Data + 4);
      return;
    }
    if (Message == 0x800001) {
      Mode = STREAM_IsMorphInProgress();
      if ((Mode == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) {
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
      if (0x800004 < Message) {
        if (Message != 0x800008) {
          return;
        }
        DropPhysOb(instance);
        return;
      }
      if (Message != 0x800002) {
        return;
      }
      Mode = STREAM_IsMorphInProgress();
      if ((Mode == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) {
        return;
      }
      PickUpPhysOb(instance,*(short *)(Data + 4),*(_Instance **)(Data + 8),(int)*(short *)(Data + 6)
                  );
      return;
    }
    if (Message != 0x200006) {
      if (Message != 0x800000) {
        return;
      }
      Mode = STREAM_IsMorphInProgress();
      if ((Mode == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) {
        return;
      }
      Mode = PushPhysOb(instance,*(short *)Data,*(short *)(Data + 2),*(short *)(Data + 4),
                        *(_Instance **)(Data + 8));
      *(int *)(Data + 0xc) = Mode;
      return;
    }
    uVar2 = 0xfeff0000;
  }
  else {
    if (Message == 0x800027) {
      if (Data == 0) {
        *puVar3 = *puVar3 | 0x1000;
        return;
      }
      uVar2 = *puVar3 & 0xffffefff;
      goto LAB_8006ce7c;
    }
    if (Message < 0x800028) {
      if (0x800022 < Message) {
        if (Message == 0x800025) {
          return;
        }
        if (0x800025 < Message) {
          pvVar4 = instance->data;
          switch((int)(((uint)*(ushort *)((int)pvVar4 + 8) - 1) * 0x10000) >> 0x10) {
          case 0:
            HEALTHU_Pickup(instance);
            return;
          case 1:
            MANNA_Pickup(instance,(int)*(short *)((int)pvVar4 + 10));
            return;
          case 2:
          case 3:
            INSTANCE_PlainDeath(instance);
            return;
          default:
            return;
          case 5:
          case 6:
            goto switchD_8006cd88_caseD_5;
          }
        }
        if (Message != 0x800023) {
          return;
        }
        Mode = STREAM_IsMorphInProgress();
        if ((Mode == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) {
          return;
        }
        InteractPhysOb(instance,*(_Instance **)Data,(uint)*(ushort *)(Data + 4),
                       (uint)*(ushort *)(Data + 0xe));
        return;
      }
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
      pvVar4 = instance->data;
      Mode = CheckPhysObFamily(instance,2);
      if (Mode != 0) {
        pvVar4 = instance->extraData;
        if (Message == 0x800021) {
          *(ushort *)((int)pvVar4 + 0x14) = *(ushort *)((int)pvVar4 + 0x14) | 2;
          return;
        }
        *(ushort *)((int)pvVar4 + 0x14) = *(ushort *)((int)pvVar4 + 0x14) & 0xfffd;
        return;
      }
      if (*(short *)((int)pvVar4 + 10) != 0) {
        return;
      }
      puVar3 = (uint *)instance->extraData;
      if (Message != 0x800021) {
        *puVar3 = *puVar3 | 0x2000;
        return;
      }
      uVar2 = *puVar3 & 0xffffdfff;
      goto LAB_8006ce7c;
    }
    if (Message != 0x80002b) {
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
        puVar3 = (uint *)instance->extraData;
        *(undefined2 *)(puVar3 + 0xd) = 0;
        *puVar3 = *puVar3 & 0xffff7fff;
        PHYSOB_EndBurning(instance,pLight);
        return;
      }
      if (Message == 0x80002d) {
        ResetSwitchPhysOb(instance);
        return;
      }
      if (0x80002c < Message) {
        if (Message != 0x8000008) {
          return;
        }
        G2EmulationInstanceSetAnimation
                  (instance,0,*(int *)(Data + 4),*(int *)(Data + 8),*(int *)(Data + 0xc));
        Mode = *(int *)(Data + 0x10);
        goto LAB_8006cf68;
      }
      uVar2 = *puVar3;
      uVar1 = 0x800000;
      goto LAB_8006ce60;
    }
    uVar2 = 0xff7f0000;
  }
  uVar2 = *puVar3 & (uVar2 | 0xffff);
LAB_8006ce7c:
  *puVar3 = uVar2;
  return;
switchD_8006cd88_caseD_5:
  if (*(byte *)((int)pvVar4 + 0x11) == 0xff) {
    return;
  }
  G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar4 + 0x11),0,0);
  Mode = 1;
LAB_8006cf68:
  G2EmulationInstanceSetMode(instance,0,Mode);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PhysobAnimCallback(struct _G2Anim_Type *anim /*$v1*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s2*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
 // line 2715, offset 0x8006cf8c
	/* begin block 1 */
		// Start line: 2716
		// Start offset: 0x8006CF8C

		/* begin block 1.1 */
			// Start line: 2718
			// Start offset: 0x8006CFB4
			// Variables:
		// 		struct PhysObData *Data; // $s0
		/* end block 1.1 */
		// End offset: 0x8006D000
		// End Line: 2735
	/* end block 1 */
	// End offset: 0x8006D018
	// End Line: 2739

	/* begin block 2 */
		// Start line: 5855
	/* end block 2 */
	// End Line: 5856

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
// void /*$ra*/ CollidePhysicalObject(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 2744, offset 0x8006d030
	/* begin block 1 */
		// Start line: 2745
		// Start offset: 0x8006D030
		// Variables:
	// 		struct PhysObData *Data; // $s3
	// 		struct _CollideInfo *collideInfo; // $s2
	// 		int obliqueFlg; // $fp
	// 		struct _Position vel; // stack offset -128
	// 		struct _Position dir; // stack offset -120
	// 		struct _Instance *hitinst; // $s4
	// 		struct _TFace *tface; // $s5
	// 		struct _Normal *norm; // $s6
	// 		struct _SVector normal; // stack offset -112
	// 		int stickFlg; // $s0
	// 		int drawFlg; // $s7

		/* begin block 1.1 */
			// Start line: 2767
			// Start offset: 0x8006D098
			// Variables:
		// 		struct BSPTree *bsp; // $s0
		// 		struct Level *level; // $a0
		/* end block 1.1 */
		// End offset: 0x8006D0EC
		// End Line: 2774

		/* begin block 1.2 */
			// Start line: 2788
			// Start offset: 0x8006D19C
			// Variables:
		// 		struct _Position delta; // stack offset -104

			/* begin block 1.2.1 */
				// Start line: 2790
				// Start offset: 0x8006D19C
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
			/* end block 1.2.1 */
			// End offset: 0x8006D19C
			// End Line: 2790

			/* begin block 1.2.2 */
				// Start line: 2790
				// Start offset: 0x8006D19C
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a2
			/* end block 1.2.2 */
			// End offset: 0x8006D19C
			// End Line: 2790
		/* end block 1.2 */
		// End offset: 0x8006D220
		// End Line: 2796

		/* begin block 1.3 */
			// Start line: 2824
			// Start offset: 0x8006D2D4
			// Variables:
		// 		long axVel; // $a0
		// 		long ayVel; // $v1
		/* end block 1.3 */
		// End offset: 0x8006D35C
		// End Line: 2848

		/* begin block 1.4 */
			// Start line: 2892
			// Start offset: 0x8006D3F0
		/* end block 1.4 */
		// End offset: 0x8006D424
		// End Line: 2897

		/* begin block 1.5 */
			// Start line: 2906
			// Start offset: 0x8006D460
			// Variables:
		// 		struct _PCollideInfo CInfo; // stack offset -96
		// 		struct _SVector newPos; // stack offset -48
		/* end block 1.5 */
		// End offset: 0x8006D4BC
		// End Line: 2925

		/* begin block 1.6 */
			// Start line: 2945
			// Start offset: 0x8006D55C
			// Variables:
		// 		struct _Position delta; // stack offset -104

			/* begin block 1.6.1 */
				// Start line: 2955
				// Start offset: 0x8006D5C8
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a2
			// 		short _x1; // $t0
			// 		short _y1; // $t1
			// 		short _z1; // $t2
			// 		struct _Position *_v; // $a3
			// 		struct _Position *_v1; // $a1
			/* end block 1.6.1 */
			// End offset: 0x8006D5C8
			// End Line: 2955
		/* end block 1.6 */
		// End offset: 0x8006D608
		// End Line: 2957

		/* begin block 1.7 */
			// Start line: 2960
			// Start offset: 0x8006D618
		/* end block 1.7 */
		// End offset: 0x8006D664
		// End Line: 2964

		/* begin block 1.8 */
			// Start line: 2998
			// Start offset: 0x8006D728
			// Variables:
		// 		struct _CollideInfo parentCI; // stack offset -104
		/* end block 1.8 */
		// End offset: 0x8006D780
		// End Line: 3004

		/* begin block 1.9 */
			// Start line: 3012
			// Start offset: 0x8006D7B8
			// Variables:
		// 		struct PhysObSplinter *splintDef; // $v0
		// 		struct FXSplinter *splinterData; // $v1
		/* end block 1.9 */
		// End offset: 0x8006D800
		// End Line: 3027

		/* begin block 1.10 */
			// Start line: 3031
			// Start offset: 0x8006D814
			// Variables:
		// 		struct PhysObProperties *Prop; // $v0
		// 		struct ProjectileData *ProjIData; // $s6
		// 		struct __PhysObProjectileData *ProjData; // $v0
		// 		int killImmediately; // $s0
		/* end block 1.10 */
		// End offset: 0x8006D984
		// End Line: 3092
	/* end block 1 */
	// End offset: 0x8006D984
	// End Line: 3094

	/* begin block 2 */
		// Start line: 5917
	/* end block 2 */
	// End Line: 5918

void CollidePhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  Level *pLVar8;
  int Data;
  long lVar9;
  _CollideInfo *p_Var10;
  PhysObSplinter *pPVar11;
  void *pvVar12;
  ulong uVar13;
  int iVar14;
  void **ppvVar15;
  FXSplinter *splintDef;
  uint uVar16;
  void *pvVar17;
  void *pvVar18;
  _CollideInfo *collideInfo;
  uint *puVar19;
  _Instance *instance_00;
  void *pvVar20;
  SVECTOR *nrml;
  short local_78;
  short local_76;
  SVECTOR SStack112;
  short local_68;
  short sStack102;
  short local_64;
  _PCollideInfo local_60;
  SVECTOR local_30;
  
  bVar7 = false;
  instance_00 = (_Instance *)0x0;
  pvVar20 = (void *)0x0;
  bVar6 = true;
  collideInfo = (_CollideInfo *)instance->collideInfo;
  puVar19 = (uint *)instance->extraData;
  nrml = &collideInfo->point0;
  if (collideInfo->type1 == '\x03') {
    pvVar12 = collideInfo->inst1;
    pLVar8 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    pvVar20 = collideInfo->prim1;
    if (((*(ushort *)((int)pvVar12 + 0x12) & 1) != 0) || ((*(byte *)((int)pvVar20 + 6) & 4) != 0)) {
      bVar6 = false;
    }
    nrml = &SStack112;
    COLLIDE_GetNormal(*(short *)((int)pvVar20 + 8),(short *)pLVar8->terrain->normalList,
                      (_SVector *)nrml);
  }
  else {
    instance_00 = (_Instance *)collideInfo->inst1;
  }
  GetPhysObCollisionType(instance);
  if ((*puVar19 & 0x4000) != 0) {
    if ((_Instance *)puVar19[2] == instance_00) {
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
    if (pvVar20 != (void *)0x0) {
      if (*(ushort *)((int)pvVar20 + 10) == 0xffff) {
        return;
      }
      if ((*(ushort *)
            (*(int *)(*(int *)collideInfo->level + 0x34) + (uint)*(ushort *)((int)pvVar20 + 10) + 10
            ) & 0x1000) == 0) {
        return;
      }
    }
    *puVar19 = *puVar19 & 0xffffbfff | 0x10;
    puVar19[0x11] = 0x96000;
    local_68 = (instance->oldPos).x - (instance->position).x;
    sStack102 = (instance->oldPos).y - (instance->position).y;
    local_64 = (instance->oldPos).z - (instance->position).z;
    (instance->position).x = (instance->position).x + local_68;
    (instance->position).y = (instance->position).y + sStack102;
    (instance->position).z = (instance->position).z + local_64;
    COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_68);
  }
  uVar16 = *puVar19;
  if ((uVar16 & 0x10) == 0) {
    if ((uVar16 & 0x200004) == 0) {
      if (((uVar16 & 0x80) != 0) &&
         (ppvVar15 = (void **)&local_68, instance->LinkParent != (_Instance *)0x0)) {
        p_Var10 = collideInfo;
        do {
          pvVar12 = *(void **)&p_Var10->flags;
          pvVar17 = p_Var10->prim0;
          pvVar18 = p_Var10->prim1;
          *ppvVar15 = p_Var10->level;
          ppvVar15[1] = pvVar12;
          ppvVar15[2] = pvVar17;
          ppvVar15[3] = pvVar18;
          p_Var10 = (_CollideInfo *)&p_Var10->inst0;
          ppvVar15 = ppvVar15 + 4;
        } while (p_Var10 != collideInfo + 1);
        local_60.inst = instance->LinkParent;
        Data = SetCollideInfoData((_CollideInfo *)&local_68);
        INSTANCE_Post(instance->LinkParent,0x200004,Data);
      }
    }
    else {
      if ((collideInfo->type1 == '\x01') && ((_Instance *)puVar19[0x10] == instance_00)) {
        return;
      }
      if (nrml->vz < 0xb50) {
        return;
      }
      if ((uVar16 & 0x200000) != 0) {
        (collideInfo->offset).z = 0;
      }
      (instance->position).x = (instance->position).x + (collideInfo->offset).x;
      (instance->position).y = (instance->position).y + (collideInfo->offset).y;
      (instance->position).z = (instance->position).z + (collideInfo->offset).z;
      COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&collideInfo->offset);
    }
  }
  else {
    if (instance_00 == (_Instance *)puVar19[0x10]) {
      return;
    }
    Data = CheckPhysObFamily(instance,7);
    if ((((Data != 0) && (pvVar20 != (void *)0x0)) && (*(ushort *)((int)pvVar20 + 10) != 0xffff)) &&
       ((*(ushort *)
          (*(int *)(*(int *)collideInfo->level + 0x34) + (uint)*(ushort *)((int)pvVar20 + 10) + 10)
        & 0x1000) != 0)) {
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
      iVar14 = instance->yVel;
      if (Data < 0) {
        Data = -Data;
      }
      if (iVar14 < 0) {
        iVar14 = -iVar14;
      }
      if (iVar14 < Data) {
        if (instance->xVel < 1) {
          local_78 = -0x1000;
        }
        else {
          local_78 = 0x1000;
        }
        local_76 = 0;
        bVar5 = iVar14 < Data >> 1;
      }
      else {
        local_76 = 0x1000;
        if (instance->yVel < 1) {
          local_76 = -0x1000;
        }
        local_78 = 0;
        bVar5 = Data < iVar14 >> 1;
      }
      if (!bVar5) {
        bVar7 = true;
      }
    }
    sVar4 = (instance->position).x;
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = 0;
    (instance->position).x = sVar4 + (collideInfo->offset).x;
    (instance->position).y = (instance->position).y + (collideInfo->offset).y;
    (instance->position).z = (instance->position).z + (collideInfo->offset).z;
    COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&collideInfo->offset);
    if ((((int)sVar1 != 0) || ((uVar2 | uVar3) != 0)) &&
       (lVar9 = MATH3D_LengthXYZ((int)sVar1,(int)(short)uVar2,(int)(short)uVar3), 100 < (short)lVar9
       )) {
      instance->flags2 = instance->flags2 | 0x2000;
    }
    bVar5 = false;
    Data = CheckPhysObAbility(instance,0x200);
    if ((Data != 0) && ((sVar1 != 0 || ((uVar2 | uVar3) != 0)))) {
      local_30.vx = (instance->position).x + sVar1 * 4;
      local_30.vy = (instance->position).y + uVar2 * 4;
      local_60.oldPoint = (SVECTOR *)&instance->position;
      local_60.newPoint = &local_30;
      local_30.vz = (instance->position).z + uVar3 * 4;
      PHYSICS_CheckLineInWorld(instance,&local_60);
      bVar5 = local_60.type != 0;
    }
    if ((((bVar5) && (bVar6)) && (instance_00 == (_Instance *)0x0)) && (nrml->vz < 0xb50)) {
      *puVar19 = *puVar19 | 0x1000;
      instance->flags2 = instance->flags2 & 0xffffff7f;
      *puVar19 = *puVar19 & 0xffffffef;
      TurnOffCollisionPhysOb(instance,4);
    }
    else {
      *puVar19 = *puVar19 & 0xffffefff | 0x400000;
      if ((sVar1 != 0) || (uVar2 != 0)) {
        memset(&local_68,0,6);
        sVar1 = (collideInfo->offset).x;
        if ((sVar1 != 0) && (local_68 = -0x14, 0 < sVar1)) {
          local_68 = 0x14;
        }
        sVar1 = (collideInfo->offset).y;
        if ((sVar1 != 0) && (sStack102 = -0x14, 0 < sVar1)) {
          sStack102 = 0x14;
        }
        sVar1 = (collideInfo->offset).z;
        if ((sVar1 != 0) && (local_64 = -0x14, 0 < sVar1)) {
          local_64 = 0x14;
        }
        (instance->position).x = (instance->position).x + local_68;
        (instance->position).y = (instance->position).y + sStack102;
        (instance->position).z = (instance->position).z + local_64;
        COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_68);
      }
      if (((short)uVar3 < 0) &&
         (lVar9 = MATH3D_LengthXYZ((int)(collideInfo->offset).x,(int)(collideInfo->offset).y,
                                   (int)(collideInfo->offset).z),
         (int)(collideInfo->offset).z < (int)(short)lVar9 * 0xb500 >> 0x10)) {
        instance->zVel = (int)(short)uVar3;
      }
    }
  }
  Data = CheckPhysObAbility(instance,0x1000);
  if (((Data != 0) && ((*puVar19 & 0x800000) == 0)) && (gameTrackerX.gameData.asmData._8_4_ == 1000)
     ) {
    pPVar11 = PhysObGetSplinter(instance);
    splintDef = (FXSplinter *)0x0;
    if (pPVar11 != (PhysObSplinter *)0x0) {
      splintDef = (FXSplinter *)pPVar11->splinterData;
    }
    _FX_BuildSplinters(instance,(SVECTOR *)0x0,(SVECTOR *)0x0,(SVECTOR *)0x0,splintDef,gFXT,
                       (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                       (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,0);
    INSTANCE_PlainDeath(instance);
  }
  Data = CheckPhysObFamily(instance,7);
  bVar6 = true;
  if (Data != 0) {
    pvVar12 = instance->extraData;
    Data = (int)*(char *)(*(int *)((int)instance->data + 0xc) + *(int *)((int)pvVar12 + 4) * 0xc + 3
                         );
    if (Data != -1) {
      if ((*puVar19 & 0x80000) != 0) {
        return;
      }
      G2EmulationInstanceSetAnimation(instance,0,Data,0,0);
      G2EmulationInstanceSetMode(instance,0,1);
      bVar6 = false;
      *puVar19 = *puVar19 | 0x81001;
    }
    if ((instance->parent != (_Instance *)0x0) &&
       (uVar13 = INSTANCE_Query(instance->parent,1), (uVar13 & 1) != 0)) {
      if ((pvVar20 == (void *)0x0) || (gameTrackerX.gameData.asmData.MorphType != 0)) {
        if ((instance_00 != gameTrackerX.playerInstance) &&
           (gameTrackerX.gameData.asmData.MorphType == 0)) {
          Data = CheckPhysOb(instance_00);
          if ((Data != 0) && (!bVar7)) {
            Data = SetObjectData((int)local_78,(int)local_76,6,(_Instance *)0x0,0);
            INSTANCE_Post(instance_00,0x800000,Data);
          }
          if (*(int *)((int)pvVar12 + 4) == 1) {
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
    if (bVar6) {
      INSTANCE_KillInstance(instance);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct PhysObWeaponAttributes * /*$ra*/ PhysObGetWeapon(struct _Instance *instance /*$s1*/)
 // line 3097, offset 0x8006d9b4
	/* begin block 1 */
		// Start line: 3098
		// Start offset: 0x8006D9B4
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $s0

		/* begin block 1.1 */
			// Start line: 3104
			// Start offset: 0x8006D9DC
			// Variables:
		// 		struct PhysObWeaponProperties *Prop; // $v0
		/* end block 1.1 */
		// End offset: 0x8006D9E8
		// End Line: 3106

		/* begin block 1.2 */
			// Start line: 3108
			// Start offset: 0x8006D9F8
			// Variables:
		// 		struct PhysObInteractProperties *Prop; // $v0
		/* end block 1.2 */
		// End offset: 0x8006DA04
		// End Line: 3110

		/* begin block 1.3 */
			// Start line: 3112
			// Start offset: 0x8006DA14
			// Variables:
		// 		struct __PhysObProjectileProperties *Prop; // $a0
		/* end block 1.3 */
		// End offset: 0x8006DA3C
		// End Line: 3116
	/* end block 1 */
	// End offset: 0x8006DA3C
	// End Line: 3117

	/* begin block 2 */
		// Start line: 6726
	/* end block 2 */
	// End Line: 6727

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
 // line 3122, offset 0x8006da58
	/* begin block 1 */
		// Start line: 3123
		// Start offset: 0x8006DA58
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $v0
	// 		struct _PhysObLight *pLight; // $s0
	/* end block 1 */
	// End offset: 0x8006DA78
	// End Line: 3132

	/* begin block 2 */
		// Start line: 6780
	/* end block 2 */
	// End Line: 6781

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
 // line 3136, offset 0x8006da90
	/* begin block 1 */
		// Start line: 3137
		// Start offset: 0x8006DA90
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $v0
	// 		struct PhysObSplinter *pSplinter; // $s0
	/* end block 1 */
	// End offset: 0x8006DAB0
	// End Line: 3146

	/* begin block 2 */
		// Start line: 6808
	/* end block 2 */
	// End Line: 6809

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
 // line 3151, offset 0x8006dac4
	/* begin block 1 */
		// Start line: 3152
		// Start offset: 0x8006DAC4
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $s0
	// 		struct PhysObData *Data; // $v1
	/* end block 1 */
	// End offset: 0x8006DB50
	// End Line: 3170

	/* begin block 2 */
		// Start line: 6838
	/* end block 2 */
	// End Line: 6839

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
 // line 3175, offset 0x8006db68
	/* begin block 1 */
		// Start line: 3176
		// Start offset: 0x8006DB68
		// Variables:
	// 		struct PhysObWeaponAttributes *weapon; // $s0
	/* end block 1 */
	// End offset: 0x8006DBD8
	// End Line: 3192

	/* begin block 2 */
		// Start line: 6893
	/* end block 2 */
	// End Line: 6894

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
 // line 3199, offset 0x8006dbf0
	/* begin block 1 */
		// Start line: 3200
		// Start offset: 0x8006DBF0
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s5
	// 		struct _HSphere *S; // $v0
	// 		struct _Instance *target; // $s2
	// 		struct PhysObWeaponAttributes *weapon; // $s0
	// 		struct PhysObData *Data; // $s4

		/* begin block 1.1 */
			// Start line: 3223
			// Start offset: 0x8006DC94
			// Variables:
		// 		struct PhysObWeaponProperties *prop; // $s3

			/* begin block 1.1.1 */
				// Start line: 3268
				// Start offset: 0x8006DDB0
				// Variables:
			// 		int damage; // $s3
			/* end block 1.1.1 */
			// End offset: 0x8006DE0C
			// End Line: 3274
		/* end block 1.1 */
		// End offset: 0x8006DE6C
		// End Line: 3283
	/* end block 1 */
	// End offset: 0x8006DE70
	// End Line: 3290

	/* begin block 2 */
		// Start line: 6941
	/* end block 2 */
	// End Line: 6942

int GetPhysObCollisionType(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  ulong uVar2;
  int Data;
  _Instance *Inst;
  int Power;
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
LAB_8006dd54:
      Data = SetMonsterHitData(instance,(_Instance *)0x0,pPVar1->Damage,
                               (int)pPVar1->knockBackDistance,(int)pPVar1->knockBackFrames);
      Power = 0x1000000;
      Inst = Sender;
LAB_8006dd7c:
      INSTANCE_Post(Inst,Power,Data);
      DropPhysOb(instance);
    }
    else {
      if ((*(ushort *)((int)pvVar3 + 6) & 0x200) == 0) {
        Data = CheckPhysObAbility(instance,0x20);
        if ((Data == 0) || ((*puVar4 & 0x10000) == 0)) goto LAB_8006dd54;
        INSTANCE_Post(Sender,0x100000c,0x20);
        Power = 0x800029;
        Data = 0;
        Inst = instance;
        goto LAB_8006dd7c;
      }
      INSTANCE_Post(Sender,0x1000019,(int)instance);
      *puVar4 = *puVar4 & 0xffffffef;
    }
    Data = CheckPhysObFamily(instance,7);
    if (Data == 0) goto LAB_8006de0c;
    Power = 0x80005;
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
    Power = 0x2000002;
    Inst = instance->LinkParent;
  }
  INSTANCE_Post(Inst,Power,Data);
LAB_8006de0c:
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
 // line 3293, offset 0x8006de94
	/* begin block 1 */
		// Start line: 3294
		// Start offset: 0x8006DE94
		// Variables:
	// 		struct PhysObData *Data; // $s2

		/* begin block 1.1 */
			// Start line: 3302
			// Start offset: 0x8006DEC8
			// Variables:
		// 		short angley; // $s0
		// 		struct _Position zero; // stack offset -32
		// 		struct _Position velocity; // stack offset -24
		/* end block 1.1 */
		// End offset: 0x8006DEC8
		// End Line: 3303
	/* end block 1 */
	// End offset: 0x8006DF8C
	// End Line: 3329

	/* begin block 2 */
		// Start line: 7144
	/* end block 2 */
	// End Line: 7145

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
    memset(&_Stack32,0,6);
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
  iVar4 = *(int *)((int)pvVar5 + 0x44) - gameTrackerX.idleTime;
  *(int *)((int)pvVar5 + 0x44) = iVar4;
  if (iVar4 < 0) {
    INSTANCE_KillInstance(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteDrag(struct _Instance *instance /*$s1*/)
 // line 3333, offset 0x8006dfa4
	/* begin block 1 */
		// Start line: 3334
		// Start offset: 0x8006DFA4
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006E034
	// End Line: 3368

	/* begin block 2 */
		// Start line: 7235
	/* end block 2 */
	// End Line: 7236

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
    *puVar2 = *puVar2 & 0xffffffbf | 1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteSlideToStop(struct _Instance *instance /*$s1*/)
 // line 3372, offset 0x8006e048
	/* begin block 1 */
		// Start line: 3373
		// Start offset: 0x8006E048
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006E0C0
	// End Line: 3401

	/* begin block 2 */
		// Start line: 7313
	/* end block 2 */
	// End Line: 7314

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
    *puVar2 = *puVar2 & 0xffefeffd | 1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteFlip(struct _Instance *instance /*$s1*/)
 // line 3405, offset 0x8006e0d4
	/* begin block 1 */
		// Start line: 3406
		// Start offset: 0x8006E0D4
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006E17C
	// End Line: 3438

	/* begin block 2 */
		// Start line: 7379
	/* end block 2 */
	// End Line: 7380

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
    *puVar2 = *puVar2 & 0xffffeff7 | 1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteSlopeSlideToStop(struct _Instance *instance /*$s1*/)
 // line 3441, offset 0x8006e190
	/* begin block 1 */
		// Start line: 3442
		// Start offset: 0x8006E190
		// Variables:
	// 		struct PhysObData *Data; // $s0
	/* end block 1 */
	// End offset: 0x8006E28C
	// End Line: 3490

	/* begin block 2 */
		// Start line: 7453
	/* end block 2 */
	// End Line: 7454

void ExecuteSlopeSlideToStop(_Instance *instance)

{
  short sVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  if ((*puVar3 & 2) != 0) {
    *puVar3 = *puVar3 & 0xfffffffd;
  }
  if ((*puVar3 & 0x100000) == 0) {
    G2EmulationInstancePlayAnimation(instance);
  }
  else {
    ResetOrientation(instance);
    uVar2 = *puVar3;
    *puVar3 = uVar2 & 0xfffffeff | 1;
    if (*(short *)(puVar3 + 10) == 8) {
      *puVar3 = uVar2 & 0xfffffaff | 0x201;
    }
    sVar1 = *(short *)(puVar3 + 10);
    if (sVar1 == 9) {
      *puVar3 = *puVar3 & 0xfffffbff | 0x200;
      sVar1 = *(short *)(puVar3 + 10);
    }
    if (sVar1 == 10) {
      *puVar3 = *puVar3 & 0xfffff9ff;
    }
    puVar3[2] = 0;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckSlope(int Znormal /*$a0*/, int Slope /*$a1*/, int Slop /*$a2*/)
 // line 3494, offset 0x8006e2a0
	/* begin block 1 */
		// Start line: 7561
	/* end block 1 */
	// End Line: 7562

	/* begin block 2 */
		// Start line: 7562
	/* end block 2 */
	// End Line: 7563

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
 // line 3503, offset 0x8006e2c0
	/* begin block 1 */
		// Start line: 3504
		// Start offset: 0x8006E2C0
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
	// End offset: 0x8006E2C0
	// End Line: 3504

	/* begin block 2 */
		// Start line: 7579
	/* end block 2 */
	// End Line: 7580

	/* begin block 3 */
		// Start line: 7582
	/* end block 3 */
	// End Line: 7583

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
 // line 3546, offset 0x8006e380
	/* begin block 1 */
		// Start line: 3547
		// Start offset: 0x8006E380
		// Variables:
	// 		int didSomething; // $s0
	/* end block 1 */
	// End offset: 0x8006E3E4
	// End Line: 3577

	/* begin block 2 */
		// Start line: 7731
	/* end block 2 */
	// End Line: 7732

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
// int /*$ra*/ PHYSOB_CheckThrownLineCollision(struct _Instance *instance /*$s2*/)
 // line 3581, offset 0x8006e400
	/* begin block 1 */
		// Start line: 3582
		// Start offset: 0x8006E400
		// Variables:
	// 		struct _PCollideInfo pcollideInfo; // stack offset -88
	// 		struct _Position newPos; // stack offset -40
	// 		struct _Position oldPos; // stack offset -32
	// 		struct _Position orgNew; // stack offset -24
	// 		struct MATRIX *mat; // $v1
	// 		struct PhysObWeaponAttributes *weapon; // $v0

		/* begin block 1.1 */
			// Start line: 3606
			// Start offset: 0x8006E458
			// Variables:
		// 		short _y1; // $v0
		// 		short _z1; // $v1
		// 		struct _Position *_v0; // $s0
		/* end block 1.1 */
		// End offset: 0x8006E458
		// End Line: 3606

		/* begin block 1.2 */
			// Start line: 3634
			// Start offset: 0x8006E530
			// Variables:
		// 		short _x0; // $a3
		// 		short _y0; // $t0
		// 		short _z0; // $t1
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.2 */
		// End offset: 0x8006E530
		// End Line: 3634

		/* begin block 1.3 */
			// Start line: 3634
			// Start offset: 0x8006E530
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $a0
		// 		short _z0; // $a1
		// 		struct _Position *_v; // $a2
		/* end block 1.3 */
		// End offset: 0x8006E530
		// End Line: 3634
	/* end block 1 */
	// End offset: 0x8006E534
	// End Line: 3635

	/* begin block 2 */
		// Start line: 7801
	/* end block 2 */
	// End Line: 7802

int PHYSOB_CheckThrownLineCollision(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  MATRIX *pMVar2;
  _PCollideInfo local_58;
  SVECTOR local_28;
  SVECTOR local_20;
  short local_18;
  short local_16;
  short local_14;
  
  pMVar2 = instance->oldMatrix;
  if (pMVar2 != (MATRIX *)0x0) {
    local_20.vx = *(short *)pMVar2[2].t;
    local_20.vy = *(short *)(pMVar2[2].t + 1);
    local_20.vz = *(short *)(pMVar2[2].t + 2);
    pPVar1 = PhysObGetWeapon(instance);
    local_58.newPoint = &local_28;
    if (pPVar1 != (PhysObWeaponAttributes *)0x0) {
      pMVar2 = instance->matrix + pPVar1->ThrowSphere;
      local_28.vx = *(short *)pMVar2->t;
      local_28.vy = *(short *)(pMVar2->t + 1);
      local_28.vz = *(short *)(pMVar2->t + 2);
      local_58.oldPoint = &local_20;
      local_18 = local_28.vx;
      local_16 = local_28.vy;
      local_14 = local_28.vz;
      PHYSICS_CheckLineInWorld(instance,&local_58);
      if (local_58.type != 0) {
        (instance->position).x = (instance->position).x + (local_28.vx - local_18);
        (instance->position).y = (instance->position).y + (local_28.vy - local_16);
        (instance->position).z = (instance->position).z + (local_28.vz - local_14);
        if (local_58.type == 3) {
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
// int /*$ra*/ PHYSOB_CheckDroppedLineCollision(struct _Instance *instance /*$s1*/, struct _Instance *parent /*$s5*/)
 // line 3641, offset 0x8006e54c
	/* begin block 1 */
		// Start line: 3642
		// Start offset: 0x8006E54C
		// Variables:
	// 		struct _PCollideInfo pcollideInfo; // stack offset -112
	// 		struct _Position parentPos; // stack offset -64
	// 		struct _Position newPos; // stack offset -56
	// 		struct _Position oldPos; // stack offset -48
	// 		struct _SVector offset; // stack offset -40
	// 		struct _Model *model; // $s4
	// 		int seg; // $s2

		/* begin block 1.1 */
			// Start line: 3661
			// Start offset: 0x8006E5D0
			// Variables:
		// 		struct MATRIX *mat; // $s0
		/* end block 1.1 */
		// End offset: 0x8006E6C8
		// End Line: 3691
	/* end block 1 */
	// End offset: 0x8006E6E0
	// End Line: 3694

	/* begin block 2 */
		// Start line: 7953
	/* end block 2 */
	// End Line: 7954

/* WARNING: Could not reconcile some variable overlaps */

int PHYSOB_CheckDroppedLineCollision(_Instance *instance,_Instance *parent)

{
  int iVar1;
  MATRIX *pMVar2;
  int iVar3;
  _Model *p_Var4;
  _PCollideInfo local_70;
  undefined4 local_40;
  short local_3c;
  SVECTOR local_38;
  SVECTOR local_30;
  SVECTOR local_28;
  
  p_Var4 = instance->object->modelList[instance->currentModel];
  iVar1 = 0;
  if (parent != (_Instance *)0x0) {
    local_40 = *(undefined4 *)&parent->position;
    local_3c = (parent->position).z;
    iVar1 = 0;
    if (instance->matrix != (MATRIX *)0x0) {
      iVar1 = 0;
      if (0 < p_Var4->numSegments) {
        iVar3 = 0;
        do {
          if (*(int *)((int)&p_Var4->segmentList->hInfo + iVar3) != 0) {
            local_30.vy = local_40._2_2_;
            pMVar2 = instance->matrix + iVar1;
            local_30.vx = (short)local_40;
            local_38.vz = *(short *)(pMVar2->t + 2);
            local_38.vx = *(short *)pMVar2->t;
            local_38.vy = *(short *)(pMVar2->t + 1);
            local_70.newPoint = &local_38;
            local_70.oldPoint = &local_30;
            local_30.vz = local_38.vz;
            SetNoPtCollideInFamily(parent);
            PHYSICS_CheckLineInWorld(instance,&local_70);
            ResetNoPtCollideInFamily(parent);
            if (local_70.type != 0) {
              local_28.vx = local_38.vx - *(short *)pMVar2->t;
              local_28.vz = 0;
              local_28.vy = local_38.vy - *(short *)(pMVar2->t + 1);
              (instance->position).x = (instance->position).x + local_28.vx;
              (instance->position).y = (instance->position).y + local_28.vy;
              (instance->position).z = (instance->position).z;
              COLLIDE_UpdateAllTransforms(instance,&local_28);
            }
          }
          iVar1 = iVar1 + 1;
          iVar3 = iVar3 + 0x18;
        } while (iVar1 < p_Var4->numSegments);
      }
      iVar1 = 1;
    }
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckDirectedLineCollision(struct _Instance *instance /*$a0*/, int xoffset /*$a1*/, int yoffset /*$a2*/, int startZOffset /*$a3*/)
 // line 3698, offset 0x8006e704
	/* begin block 1 */
		// Start line: 3699
		// Start offset: 0x8006E704
		// Variables:
	// 		struct _PCollideInfo pcollideInfo; // stack offset -72
	// 		struct _Position newPos; // stack offset -24
	// 		struct _Position oldPos; // stack offset -16
	// 		struct MATRIX *mat; // $v0
	/* end block 1 */
	// End offset: 0x8006E704
	// End Line: 3699

	/* begin block 2 */
		// Start line: 8116
	/* end block 2 */
	// End Line: 8117

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
 // line 3719, offset 0x8006e778
	/* begin block 1 */
		// Start line: 3720
		// Start offset: 0x8006E778
		// Variables:
	// 		struct _Instance *attachedBlock; // $s0
	// 		long result; // $s1
	/* end block 1 */
	// End offset: 0x8006E7D4
	// End Line: 3739

	/* begin block 2 */
		// Start line: 8182
	/* end block 2 */
	// End Line: 8183

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
 // line 3742, offset 0x8006e7f4
	/* begin block 1 */
		// Start line: 8230
	/* end block 1 */
	// End Line: 8231

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
 // line 3755, offset 0x8006e86c
	/* begin block 1 */
		// Start line: 3757
		// Start offset: 0x8006E86C
		// Variables:
	// 		int x; // $v0
	// 		int y; // $v1
	// 		int z; // $v0
	// 		int x0; // $t2
	// 		int x1; // $t1
	// 		int y0; // $t0
	// 		int y1; // $v1
	// 		int z0; // $a2
	// 		int z1; // $a1
	// 		struct _Instance *inst; // $a3
	/* end block 1 */
	// End offset: 0x8006E928
	// End Line: 3778

	/* begin block 2 */
		// Start line: 8259
	/* end block 2 */
	// End Line: 8260

	/* begin block 3 */
		// Start line: 8260
	/* end block 3 */
	// End Line: 8261

	/* begin block 4 */
		// Start line: 8264
	/* end block 4 */
	// End Line: 8265

long PHYSOB_CheckForEnemyInBlkSpot(_Instance *instance,int dx,int dy)

{
  int iVar1;
  int iVar2;
  _Instance *p_Var3;
  
  dy = (instance->position).y + dy;
  p_Var3 = (gameTrackerX.instanceList)->first;
  dx = (instance->position).x + dx;
  iVar1 = (int)(instance->position).z;
  while( true ) {
    if (p_Var3 == (_Instance *)0x0) {
      return 0;
    }
    if (((((p_Var3->object->oflags2 & 0x80000U) != 0) &&
         (iVar2 = (int)(p_Var3->position).x, dx + -0x140 <= iVar2)) && (iVar2 <= dx + 0x140)) &&
       (((iVar2 = (int)(p_Var3->position).y, dy + -0x140 <= iVar2 && (iVar2 <= dy + 0x140)) &&
        ((iVar2 = (int)(p_Var3->position).z, iVar1 + -0x140 <= iVar2 && (iVar2 <= iVar1 + 0x140)))))
       ) break;
    p_Var3 = p_Var3->next;
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ PHYSOBS_CheckForValidMove(struct _Instance *instance /*$s2*/)
 // line 3781, offset 0x8006e938
	/* begin block 1 */
		// Start line: 3782
		// Start offset: 0x8006E938
		// Variables:
	// 		int rc; // $s1
	// 		struct PhysObData *Data; // $s0
	// 		struct evPhysicsSlideData *Ptr; // stack offset -24
	// 		int result; // stack offset -20

		/* begin block 1.1 */
			// Start line: 3855
			// Start offset: 0x8006EB0C
			// Variables:
		// 		int Height; // $v0
		/* end block 1.1 */
		// End offset: 0x8006EB3C
		// End Line: 3867
	/* end block 1 */
	// End offset: 0x8006EF3C
	// End Line: 4092

	/* begin block 2 */
		// Start line: 8326
	/* end block 2 */
	// End Line: 8327

uint PHYSOBS_CheckForValidMove(_Instance *instance)

{
  ushort uVar1;
  int Data;
  long lVar2;
  uint uVar3;
  ulong modeBits;
  PhysObData *Data_00;
  evPhysicsSlideData *local_18;
  uint local_14;
  
  gameTrackerX.currentMaterialTime._0_1_ = 1;
  Data_00 = (PhysObData *)instance->extraData;
  local_14 = 7;
  if ((Data_00->Mode & 1U) == 0) {
    gameTrackerX.currentMaterialTime._0_1_ = 0;
    return 7;
  }
  Data = SetPhysicsGravityData(0xa0,0x280,0,0,0,0xb50);
  PhysicsUpdateTface(instance,Data);
  lVar2 = PHYSOBS_CheckForStackedForwardHits
                    (instance,(int)Data_00->xForce * 0x2c0,(int)Data_00->yForce * 0x2c0);
  if (lVar2 == 0) {
    uVar3 = PHYSOB_CheckSlide(instance,(int)Data_00->xForce,(int)Data_00->yForce,&local_18);
    if ((uVar3 & 2) != 0) {
      Data = CheckSlope((int)(local_18->ForwardNormal).z,0xe4f,4);
      if (Data == 0) {
        Data = CheckSlope((int)(local_18->ForwardNormal).z,0x1000,4);
        if (Data == 0) {
          if ((Data_00->Mode & 8U) == 0) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return 0;
          }
          if ((uVar3 & 4) == 0) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return 0;
          }
          Data = PHYSOB_CheckDirectedLineCollision
                           (instance,(int)Data_00->xForce * 0x2c0,(int)Data_00->yForce * 0x2c0,0x280
                           );
          if (Data != 0) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return 0;
          }
          if (0x12 < 0xa9U - (int)local_18->Height) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return 0;
          }
          modeBits = 2;
          Data = 7;
        }
        else {
          Data = PHYSOBS_FigureDragForSlope(instance,(int)Data_00->PathNumber,(int *)&local_14);
          if (Data != 0) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return local_14;
          }
          modeBits = 0x100;
          Data = 0xd;
        }
      }
      else {
        Data = CheckBlockSlope(instance,(int)Data_00->xForce,(int)Data_00->yForce,0x205,0x8b,0x271,
                               0x138);
        if (Data != 0) {
          gameTrackerX.currentMaterialTime._0_1_ = 0;
          return 0;
        }
        Data = PHYSOBS_FigureDragForSlope(instance,(int)Data_00->PathNumber,(int *)&local_14);
        if (Data != 0) {
          gameTrackerX.currentMaterialTime._0_1_ = 0;
          return local_14;
        }
        modeBits = 0x100;
        Data = 8;
      }
LAB_8006edb4:
      PHYSOBS_SetNewAnim(instance,Data_00,modeBits,Data,1);
      gameTrackerX.currentMaterialTime._0_1_ = 0;
      return local_14 & 0xfffffffb;
    }
    if ((uVar3 & 0x4000) == 0) {
      if (((Data_00->Mode & 8U) != 0) && ((uVar3 & 0x8000) != 0)) {
        local_14 = 0;
      }
      uVar1 = Data_00->PathNumber;
      if ((1 < (uint)uVar1 - 2) && (local_14 != 0)) {
        if ((int)(short)uVar1 == 5) {
          gameTrackerX.currentMaterialTime._0_1_ = 0;
          return local_14 & 0xfffffffa;
        }
        if ((Data_00->Mode & 8U) == 0) {
          PHYSOBS_SetNewAnim(instance,Data_00,2,(int)(short)uVar1,1);
          gameTrackerX.currentMaterialTime._0_1_ = 0;
          return local_14;
        }
        Data_00->PathNumber = 0xe;
        PHYSOBS_SetNewAnim(instance,Data_00,2,0xe,1);
        gameTrackerX.currentMaterialTime._0_1_ = 0;
        return local_14;
      }
    }
    else {
      if (((Data_00->Mode & 8U) != 0) &&
         (((uVar3 & 0x8000) != 0 ||
          (Data = PHYSOB_CheckDirectedLineCollision
                            (instance,(int)Data_00->xForce * 0x2c0,(int)Data_00->yForce * 0x2c0,
                             0x280), Data != 0)))) {
        local_14 = 0;
      }
      if (local_14 == 0) {
        gameTrackerX.currentMaterialTime._0_1_ = 0;
        return 0;
      }
      Data = CheckSlope(local_18->Dot,-0x13a,4);
      if (Data != 0) {
        Data = CheckSlope((int)(local_18->DropNormal).z,0xe4f,4);
        if (Data == 0) {
          Data = CheckSlope((int)(local_18->DropNormal).z,0x1000,4);
          if (Data == 0) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return local_14;
          }
          Data = PHYSOBS_FigureDragForSlope(instance,(int)Data_00->PathNumber,(int *)&local_14);
          if (Data != 0) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return local_14;
          }
          modeBits = 0x100;
          Data = 10;
        }
        else {
          Data = CheckBlockSlope(instance,(int)Data_00->xForce,(int)Data_00->yForce,0x271,0x138,
                                 0x271,0x138);
          if (Data != 0) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return 0;
          }
          Data = PHYSOBS_FigureDragForSlope(instance,(int)Data_00->PathNumber,(int *)&local_14);
          if (Data != 0) {
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return local_14;
          }
          modeBits = 0x100;
          Data = 9;
        }
        goto LAB_8006edb4;
      }
      Data = CheckSlope(local_18->Dot,0x13a,4);
      if (Data == 0) {
        Data = CheckSlope((int)(local_18->DropNormal).z,0xe4f,4);
        if (Data == 0) {
          lVar2 = PHYSOB_CheckForEnemyInBlkSpot
                            (instance,(int)Data_00->xForce * 0x280,(int)Data_00->yForce * 0x280);
          if (((lVar2 == 0) ||
              (Data = PHYSOB_CheckDirectedLineCollision
                                (instance,(int)Data_00->xForce * 0x540,(int)Data_00->yForce * 0x540,
                                 0), Data == 0)) &&
             (Data = CheckSlope((int)(local_18->DropNormal).z,0x1000,4), Data != 0)) {
            PHYSOBS_SetNewAnim(instance,Data_00,2,(int)Data_00->PathNumber,0);
            gameTrackerX.currentMaterialTime._0_1_ = 0;
            return local_14;
          }
        }
        else {
          Data = CheckBlockSlope(instance,(int)Data_00->xForce,(int)Data_00->yForce,0x2dc,-0xad,
                                 0x271,-0x138);
          if (Data == 0) {
            Data = PHYSOBS_FigureDragForSlope(instance,(int)Data_00->PathNumber,(int *)&local_14);
            if (Data != 0) {
              gameTrackerX.currentMaterialTime._0_1_ = 0;
              return local_14;
            }
            modeBits = 0x100;
            Data = 0xb;
            goto LAB_8006edb4;
          }
        }
      }
      else {
        Data = CheckSlope((int)(local_18->DropNormal).z,0xe4f,4);
        if (Data == 0) {
          Data = CheckSlope((int)(local_18->DropNormal).z,0x1000,4);
          if (Data != 0) {
            Data = PHYSOBS_FigureDragForSlope(instance,(int)Data_00->PathNumber,(int *)&local_14);
            if (Data != 0) {
              gameTrackerX.currentMaterialTime._0_1_ = 0;
              return local_14;
            }
            modeBits = 0x100;
            Data = 0xd;
            goto LAB_8006edb4;
          }
        }
        else {
          Data = CheckBlockSlope(instance,(int)Data_00->xForce,(int)Data_00->yForce,0x271,-0x138,
                                 0x271,-0x138);
          if (Data == 0) {
            Data = PHYSOBS_FigureDragForSlope(instance,(int)Data_00->PathNumber,(int *)&local_14);
            if (Data != 0) {
              gameTrackerX.currentMaterialTime._0_1_ = 0;
              return local_14;
            }
            modeBits = 0x100;
            Data = 0xc;
            goto LAB_8006edb4;
          }
        }
      }
    }
  }
  gameTrackerX.currentMaterialTime._0_1_ = 0;
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ExecuteGravitate(struct _Instance *instance /*$s1*/)
 // line 4096, offset 0x8006ef5c
	/* begin block 1 */
		// Start line: 4097
		// Start offset: 0x8006EF5C
		// Variables:
	// 		struct PhysObData *Data; // $s0
	// 		struct _Instance *Force; // $s4
	// 		struct _G2EulerAngles_Type ea; // stack offset -48
	// 		struct _Vector Position; // stack offset -40
	// 		struct _Model *model; // $s3
	// 		struct MATRIX *forceMatrix; // $s2
	// 		int scale; // $v1
	/* end block 1 */
	// End offset: 0x8006F2B0
	// End Line: 4213

	/* begin block 2 */
		// Start line: 8979
	/* end block 2 */
	// End Line: 8980

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
  int local_28;
  int local_24;
  int local_20;
  
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
    ApplyMatrix(pMVar3 + 2,&p_Var5->segmentList[2].px,&local_28);
    local_28 = (matrix->trans).x - local_28;
    local_24 = (matrix->trans).y - local_24;
    local_20 = (matrix->trans).z - local_20;
    (instance->position).x =
         *(short *)((int)puVar4 + 0xe) +
         (short)(((local_28 - *(short *)((int)puVar4 + 0xe)) * (int)*(short *)((int)puVar4 + 0x26))
                / (int)*(short *)(puVar4 + 9));
    (instance->position).y =
         *(short *)(puVar4 + 4) +
         (short)(((local_24 - *(short *)(puVar4 + 4)) * (int)*(short *)((int)puVar4 + 0x26)) /
                (int)*(short *)(puVar4 + 9));
    (instance->position).z =
         *(short *)((int)puVar4 + 0x12) +
         (short)(((local_20 - *(short *)((int)puVar4 + 0x12)) * (int)*(short *)((int)puVar4 + 0x26))
                / (int)*(short *)(puVar4 + 9));
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
      *puVar4 = *puVar4 & 0xfefdbffe | 0x1080;
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
 // line 4216, offset 0x8006f2d0
	/* begin block 1 */
		// Start line: 4218
		// Start offset: 0x8006F2D0
		// Variables:
	// 		struct PhysObData *Data; // $a1
	// 		struct _Instance *Force; // $a2
	/* end block 1 */
	// End offset: 0x8006F2D0
	// End Line: 4221

	/* begin block 2 */
		// Start line: 9261
	/* end block 2 */
	// End Line: 9262

	/* begin block 3 */
		// Start line: 9262
	/* end block 3 */
	// End Line: 9263

	/* begin block 4 */
		// Start line: 9265
	/* end block 4 */
	// End Line: 9266

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
 // line 4238, offset 0x8006f328
	/* begin block 1 */
		// Start line: 4239
		// Start offset: 0x8006F328
		// Variables:
	// 		long len; // $a1
	/* end block 1 */
	// End offset: 0x8006F36C
	// End Line: 4246

	/* begin block 2 */
		// Start line: 9305
	/* end block 2 */
	// End Line: 9306

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
 // line 4253, offset 0x8006f3c4
	/* begin block 1 */
		// Start line: 4254
		// Start offset: 0x8006F3C4
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
	// End offset: 0x8006F5A8
	// End Line: 4298

	/* begin block 2 */
		// Start line: 9337
	/* end block 2 */
	// End Line: 9338

int PHYSOB_MoveTowardsAlign(_Instance *instance,_SVector *orgVec,_SVector *endVec)

{
  int iVar1;
  int iVar2;
  ulong square;
  uint uVar3;
  long lVar4;
  uint uVar5;
  MATRIX *pMVar6;
  undefined4 auStack104 [8];
  _G2Matrix_Type _Stack72;
  short local_28;
  short local_26;
  short local_24;
  undefined2 local_22;
  _G2EulerAngles_Type local_20;
  
  iVar1 = gameTrackerX.idleTime * 0x32;
  PHYSOB_Normalize(orgVec);
  PHYSOB_Normalize(endVec);
  pMVar6 = instance->matrix;
  iVar2 = (int)orgVec->y * (int)endVec->z - (int)orgVec->z * (int)endVec->y;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_28 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->z * (int)endVec->x - (int)orgVec->x * (int)endVec->z;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_26 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->x * (int)endVec->y - (int)orgVec->y * (int)endVec->x;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  local_24 = (short)(iVar2 >> 0xc);
  iVar2 = (int)orgVec->x * (int)endVec->x + (int)orgVec->y * (int)endVec->y +
          (int)orgVec->z * (int)endVec->z;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  iVar2 = MATH3D_racos_S(iVar2 >> 0xc);
  uVar5 = ((iVar2 << 0x10) >> 0x10) - ((iVar2 << 0x10) >> 0x1f) >> 1;
  uVar3 = SEXT24((short)(iVar1 >> 0xc));
  if ((int)uVar5 < (int)-uVar3) {
    uVar5 = -uVar3;
  }
  if ((int)uVar3 < (int)uVar5) {
    uVar5 = uVar3;
  }
  square = MATH3D_SquareLength((int)local_28,(int)local_26,(int)local_24);
  if ((int)square < 1) {
    lVar4 = 0x1000;
  }
  else {
    lVar4 = MATH3D_FastSqrt0(square);
  }
  iVar1 = rsin(uVar5);
  local_28 = (short)((local_28 * iVar1) / lVar4);
  local_26 = (short)((local_26 * iVar1) / lVar4);
  local_24 = (short)((local_24 * iVar1) / lVar4);
  iVar1 = rcos(uVar5);
  local_22 = (undefined2)iVar1;
  G2Quat_ToMatrix_S(&local_28,(short *)auStack104);
  MulMatrix0(auStack104,(ushort *)pMVar6,(uint *)&_Stack72);
  G2EulerAngles_FromMatrix(&local_20,&_Stack72,0x15);
  (instance->rotation).x = local_20.x;
  (instance->rotation).y = local_20.y;
  (instance->rotation).z = local_20.z;
  return (uint)((int)uVar5 < 0x14);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_ReAlignFalling(struct _Instance *instance /*$s6*/, int zEndOff /*$fp*/)
 // line 4316, offset 0x8006f69c
	/* begin block 1 */
		// Start line: 4317
		// Start offset: 0x8006F69C
		// Variables:
	// 		struct _Model *model; // $s7
	// 		int i; // $s2
	// 		struct _Position seg0; // stack offset -136
	// 		struct _Position segn; // stack offset -128
	// 		struct _Position start0; // stack offset -120
	// 		struct _Position startn; // stack offset -112
	// 		int startFlg; // $s3
	// 		short zOff; // $s5

		/* begin block 1.1 */
			// Start line: 4328
			// Start offset: 0x8006F704
			// Variables:
		// 		struct _PCollideInfo pcollideInfo; // stack offset -104
		// 		struct _Position newPos; // stack offset -56
		// 		struct _Position oldPos; // stack offset -48
		// 		short x; // $s1
		// 		short y; // $s0
		// 		struct MATRIX *mat; // $v0

			/* begin block 1.1.1 */
				// Start line: 4347
				// Start offset: 0x8006F77C
				// Variables:
			// 		short ax; // $a1
			// 		short ay; // $a2
			/* end block 1.1.1 */
			// End offset: 0x8006F874
			// End Line: 4377

			/* begin block 1.1.2 */
				// Start line: 4385
				// Start offset: 0x8006F8A0
			/* end block 1.1.2 */
			// End offset: 0x8006F98C
			// End Line: 4413
		/* end block 1.1 */
		// End offset: 0x8006F98C
		// End Line: 4415

		/* begin block 1.2 */
			// Start line: 4422
			// Start offset: 0x8006F9A8
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
		// End offset: 0x8006F9A8
		// End Line: 4422

		/* begin block 1.3 */
			// Start line: 4422
			// Start offset: 0x8006F9A8
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
		// End offset: 0x8006F9A8
		// End Line: 4422
	/* end block 1 */
	// End offset: 0x8006FA9C
	// End Line: 4443

	/* begin block 2 */
		// Start line: 9485
	/* end block 2 */
	// End Line: 9486

/* WARNING: Could not reconcile some variable overlaps */

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
  uint uVar10;
  short sVar11;
  short sVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  _Model *p_Var16;
  undefined4 local_88;
  ushort local_84;
  undefined4 local_80;
  ushort local_7c;
  undefined4 local_78;
  short local_74;
  undefined4 local_70;
  short local_6c;
  _PCollideInfo local_68;
  uint local_38;
  ushort local_34;
  uint local_30;
  short local_2c;
  
  uVar15 = 0xffff8300;
  p_Var16 = instance->object->modelList[instance->currentModel];
  iVar13 = 0;
  bVar3 = false;
  if (0 < p_Var16->numSegments) {
    iVar14 = 0;
    uVar7 = uVar15;
    do {
      sVar12 = 0;
      sVar11 = 0;
      uVar15 = uVar7;
      if ((p_Var16->segmentList[iVar13].hInfo != (_HInfo *)0x0) || (iVar13 == 0)) {
        iVar5 = (int)instance->matrix->m + iVar14;
        uVar1 = *(ushort *)(iVar5 + 0x14);
        uVar2 = *(ushort *)(iVar5 + 0x18);
        local_30 = CONCAT22(uVar2,uVar1);
        local_38 = CONCAT22(uVar2,uVar1);
        local_34 = *(short *)(iVar5 + 0x1c) + (short)zEndOff;
        local_2c = *(short *)(iVar5 + 0x1c) + 300;
        if (bVar3) {
          iVar5 = (uint)uVar1 - (local_78 & 0xffff);
          iVar9 = (uint)uVar2 - (local_78 >> 0x10);
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
              sVar12 = 0x40;
              sVar11 = 0;
            }
            else {
              sVar12 = (short)iVar5;
              sVar11 = (short)iVar9;
              if ((sVar4 < 0x14) && (sVar8 < 0x14)) {
                sVar12 = sVar12 * 0x10;
                sVar11 = sVar11 * 0x10;
              }
              else {
                sVar12 = sVar12 * 4;
                sVar11 = sVar11 * 4;
              }
            }
            local_30 = CONCAT22(uVar2 + sVar11,uVar1 + sVar12);
            local_38 = CONCAT22(uVar2 + sVar11,uVar1 + sVar12);
          }
          else {
            sVar11 = 0;
            sVar12 = 0;
          }
        }
        local_68.newPoint = (SVECTOR *)&local_38;
        local_68.oldPoint = (SVECTOR *)&local_30;
        PHYSICS_CheckLineInWorld(instance,&local_68);
        if (local_68.type != 0) {
          uVar15 = (uint)local_34 - (uint)*(ushort *)((int)instance->matrix->t + iVar14 + 8);
          if ((int)(uVar15 * 0x10000) < (int)(uVar7 << 0x10)) {
            uVar15 = uVar7;
          }
          if (bVar3) {
            local_80 = local_38;
            local_7c = local_34;
            local_6c = local_2c;
            local_70._0_2_ = (short)local_30;
            local_70._2_2_ = (short)(local_30 >> 0x10);
            local_70 = CONCAT22(local_70._2_2_ - sVar11,(short)local_70 - sVar12);
          }
          else {
            local_88 = local_38;
            local_84 = local_34;
            local_78 = local_30;
            local_74 = local_2c;
            local_80 = local_38;
            local_7c = local_34;
            local_70 = local_30;
            local_6c = local_2c;
            bVar3 = true;
          }
        }
      }
      iVar13 = iVar13 + 1;
      iVar14 = iVar14 + 0x20;
      uVar7 = uVar15;
    } while (iVar13 < p_Var16->numSegments);
  }
  uVar7 = 1;
  if (bVar3) {
    instance->zAccl = 0;
    instance->zVel = 0;
    (instance->position).z = *(short *)(instance->matrix->t + 2) + (short)uVar15;
    uVar10 = (local_70 & 0xffff) - (local_78 & 0xffff);
    local_6c = local_6c - local_74;
    local_70 = uVar10 & 0xffff | (uint)(ushort)(local_70._2_2_ - local_78._2_2_) << 0x10;
    uVar7 = (local_80 & 0xffff) - (local_88 & 0xffff);
    local_7c = local_7c - local_84;
    local_80 = uVar7 & 0xffff | (uint)(ushort)(local_80._2_2_ - local_88._2_2_) << 0x10;
    if ((((uVar10 * 0x10000 == uVar7 * 0x10000) &&
         ((short)(local_70._2_2_ - local_78._2_2_) == (short)(local_80._2_2_ - local_88._2_2_))) &&
        (local_6c == local_7c)) && ((uVar15 & 0xffff) == 0)) {
      uVar7 = 1;
    }
    else {
      iVar13 = PHYSOB_MoveTowardsAlign(instance,(_SVector *)&local_70,(_SVector *)&local_80);
      uVar7 = 0;
      if ((uVar15 & 0xffff) == 0) {
        uVar7 = (uint)(iVar13 != 0);
      }
    }
  }
  return uVar7;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DropPhysOb(struct _Instance *instance /*$s0*/)
 // line 4446, offset 0x8006facc
	/* begin block 1 */
		// Start line: 4447
		// Start offset: 0x8006FACC
		// Variables:
	// 		struct PhysObData *Data; // $s1
	// 		struct _Instance *parent; // $s2
	/* end block 1 */
	// End offset: 0x8006FB14
	// End Line: 4489

	/* begin block 2 */
		// Start line: 9876
	/* end block 2 */
	// End Line: 9877

void DropPhysOb(_Instance *instance)

{
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
  PHYSOB_ReAlignFalling(instance,0);
  *(_Instance **)(puVar1 + 0x10) = parent;
  *puVar1 = *puVar1 & 0xffffef6f | 0x400004;
  PHYSOB_CheckDroppedLineCollision(instance,parent);
  TurnOnCollisionPhysOb(instance,7);
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = -10;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PhysicalRelocateTune(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 4510, offset 0x8006fb8c
	/* begin block 1 */
		// Start line: 4512
		// Start offset: 0x8006FB8C
		// Variables:
	// 		struct PhysObWeaponProperties *properties; // $a3
	// 		struct _PhysObLight *pLight; // $v0

		/* begin block 1.1 */
			// Start line: 4528
			// Start offset: 0x8006FBF0
			// Variables:
		// 		struct PhysObInteractProperties *prop; // $a2
		// 		struct PhysObWeaponAttributes *weapon; // $v0
		/* end block 1.1 */
		// End offset: 0x8006FC4C
		// End Line: 4540

		/* begin block 1.2 */
			// Start line: 4542
			// Start offset: 0x8006FC5C
			// Variables:
		// 		struct __PhysObProjectileProperties *prop; // $a0

			/* begin block 1.2.1 */
				// Start line: 4548
				// Start offset: 0x8006FC80
				// Variables:
			// 		int i; // $t0
			/* end block 1.2.1 */
			// End offset: 0x8006FCEC
			// End Line: 4562
		/* end block 1.2 */
		// End offset: 0x8006FCEC
		// End Line: 4563
	/* end block 1 */
	// End offset: 0x8006FCEC
	// End Line: 4565

	/* begin block 2 */
		// Start line: 10016
	/* end block 2 */
	// End Line: 10017

	/* begin block 3 */
		// Start line: 10017
	/* end block 3 */
	// End Line: 10018

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
        iVar4 = 0;
        if (*(int *)(iVar2 + 4) != 0) {
          iVar4 = *(int *)(iVar2 + 4) + offset;
        }
        *(int *)(iVar2 + 4) = iVar4;
      }
    }
    sVar1 = *(short *)((int)pvVar6 + 2);
    if (sVar1 == 3) {
      iVar2 = *(int *)((int)object->data + 0x28);
      iVar4 = 0;
      if (iVar2 != 0) {
        iVar4 = iVar2 + offset;
      }
      *(int *)((int)object->data + 0x28) = iVar4;
      if (iVar4 != 0) {
        iVar2 = 0;
        if (*(int *)(iVar4 + 0x10) != 0) {
          iVar2 = *(int *)(iVar4 + 0x10) + offset;
        }
        *(int *)(iVar4 + 0x10) = iVar2;
        if (iVar2 != 0) {
          iVar4 = 0;
          if (*(int *)(iVar2 + 4) != 0) {
            iVar4 = *(int *)(iVar2 + 4) + offset;
          }
          *(int *)(iVar2 + 4) = iVar4;
        }
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
      if ((iVar2 != 0) && (iVar4 = 0, 0 < *(int *)((int)pvVar6 + 8))) {
        do {
          iVar3 = 0;
          if (*(int *)(iVar2 + 8) != 0) {
            iVar3 = *(int *)(iVar2 + 8) + offset;
          }
          *(int *)(iVar2 + 8) = iVar3;
          if ((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0x10), iVar3 != 0)) {
            iVar5 = 0;
            if (*(int *)(iVar3 + 4) != 0) {
              iVar5 = *(int *)(iVar3 + 4) + offset;
            }
            *(int *)(iVar3 + 4) = iVar5;
          }
          iVar4 = iVar4 + 1;
          iVar2 = iVar2 + 0xc;
        } while (iVar4 < *(int *)((int)pvVar6 + 8));
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOBS_CheckObjectAxisAlignment(struct MATRIX *m0 /*$a0*/, struct MATRIX *m1 /*$s1*/, struct _SVector *axis /*$s0*/)
 // line 4579, offset 0x8006fcf4
	/* begin block 1 */
		// Start line: 4580
		// Start offset: 0x8006FCF4
		// Variables:
	// 		struct VECTOR r0; // stack offset -64
	// 		struct VECTOR r1; // stack offset -48
	// 		struct _SVector v0; // stack offset -32
	// 		struct _SVector v1; // stack offset -24
	/* end block 1 */
	// End offset: 0x8006FCF4
	// End Line: 4580

	/* begin block 2 */
		// Start line: 10160
	/* end block 2 */
	// End Line: 10161

int PHYSOBS_CheckObjectAxisAlignment(MATRIX *m0,MATRIX *m1,_SVector *axis)

{
  short local_40 [2];
  short local_3c;
  short local_38;
  short local_30 [2];
  short local_2c;
  short local_28;
  
  ApplyMatrix(m0,axis,local_40);
  ApplyMatrix(m1,axis,local_30);
  return ((int)local_40[0] * (int)local_30[0] + (int)local_3c * (int)local_2c +
         (int)local_38 * (int)local_28) * 0x10 >> 0x10;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckSlide(struct _Instance *instance /*$s0*/, int x /*$a1*/, int y /*$a2*/, struct evPhysicsSlideData **data /*$s1*/)
 // line 4600, offset 0x8006fdc4
	/* begin block 1 */
		// Start line: 10228
	/* end block 1 */
	// End Line: 10229

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
 // line 4610, offset 0x8006fe54
	/* begin block 1 */
		// Start line: 10250
	/* end block 1 */
	// End Line: 10251

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
// int /*$ra*/ PHYSOB_CheckSlideNormal(struct _Instance *instance /*$s0*/, int x /*stack 4*/, int y /*stack 8*/, struct evPhysicsSlideData **data /*$s1*/)
 // line 4620, offset 0x8006fee4
	/* begin block 1 */
		// Start line: 10272
	/* end block 1 */
	// End Line: 10273

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
 // line 4628, offset 0x8006ff38
	/* begin block 1 */
		// Start line: 4630
		// Start offset: 0x8006FF38
		// Variables:
	// 		int x1; // $v1
	// 		int y1; // $a2
	/* end block 1 */
	// End offset: 0x8006FF94
	// End Line: 4644

	/* begin block 2 */
		// Start line: 10290
	/* end block 2 */
	// End Line: 10291

	/* begin block 3 */
		// Start line: 10291
	/* end block 3 */
	// End Line: 10292

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





