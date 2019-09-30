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

_Instance * PHYSOBS_IsAPushBlockAttached(_Instance *block)

{
  _Instance *instance;
  int iVar1;
  undefined instance_00;
  _Instance *p_Var2;
  
  p_Var2 = (gameTrackerX.instanceList)->first;
  do {
    instance = p_Var2;
    if (instance == (_Instance *)0x0) {
      return (_Instance *)0x0;
    }
    instance_00 = SUB41(instance,0);
    p_Var2 = instance->next;
  } while ((instance->attachedID != block->introUniqueID) ||
          (iVar1 = CheckPhysObAbility(instance,2), iVar1 == 0));
  p_Var2 = (_Instance *)CheckPhysOb(instance_00);
  return p_Var2;
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

int AnyBlocksInMotion(void)

{
  _Instance *p_Var1;
  
  p_Var1 = (gameTrackerX.instanceList)->first;
  while( true ) {
    if (p_Var1 == (_Instance *)0x0) {
      return 0;
    }
    if (((((p_Var1->object->oflags2 & 0x40000U) != 0) &&
         ((*(ushort *)((int)p_Var1->data + 6) & 8) != 0)) &&
        (*(short *)((int)p_Var1->data + 4) == -0x4ff5)) &&
       ((*(uint *)p_Var1->extraData & 0x14e) != 0)) break;
    p_Var1 = p_Var1->next;
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

void ThrowPhysOb(_Instance *instance,evObjectThrowData *throwData)

{
  if (instance->LinkParent != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
    instance->flags2 = instance->flags2 | 0x4000;
    INSTANCE_UnlinkFromParent(instance);
  }
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
                    /* WARNING: Subroutine does not return */
      G2EmulationInstanceSetAnimation(instance,0,(uint)bVar1,0,0);
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

int SwitchPhysOb(_Instance *instance)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  
  pvVar4 = instance->data;
  iVar2 = CheckPhysObFamily(instance,2);
  iVar3 = 1;
  if (iVar2 != 0) {
    *(uint *)instance->extraData = *(uint *)instance->extraData | 0x800;
    pvVar5 = instance->extraData;
    uVar1 = *(ushort *)((int)pvVar5 + 0x14);
    if ((uVar1 & 1) == 0) {
      if ((uVar1 & 2) != 0) {
        *(ushort *)((int)pvVar5 + 0x14) = uVar1 | 5;
                    /* WARNING: Subroutine does not return */
        G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar4 + 0xc),0,0);
      }
      if (*(byte *)((int)pvVar4 + 0xe) != 0xff) {
                    /* WARNING: Subroutine does not return */
        G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar4 + 0xe),0,0);
      }
      G2EmulationInstanceSetMode(instance,0,1);
    }
    else {
      if ((uVar1 & 2) != 0) {
        *(ushort *)((int)pvVar5 + 0x14) = uVar1 & 0xfffe | 8;
                    /* WARNING: Subroutine does not return */
        G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar4 + 0xd),0,0);
      }
      if (*(byte *)((int)pvVar4 + 0xf) != 0xff) {
                    /* WARNING: Subroutine does not return */
        G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar4 + 0xf),0,0);
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

int InteractPhysOb(_Instance *instance,_Instance *Force,int LinkNode,int Action)

{
  int segment;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  _PhysObLight *pLight;
  _Model **pp_Var4;
  undefined instance_00;
  undefined instance_01;
  _Instance *instance_02;
  void *pvVar5;
  
  instance_00 = SUB41(instance,0);
  pvVar5 = instance->data;
  instance_01 = instance_00;
  segment = CheckPhysObFamily(instance,3);
  iVar1 = 1;
  if (segment != 0) {
    puVar2 = (uint *)instance->extraData;
    if (*(char *)((int)pvVar5 + 0x14) != -1) {
      if (Action == 2) {
        instance_02 = Force->LinkChild;
        instance_01 = SUB41(instance_02,0);
        pLight = PhysObGetLight(instance_02);
        PHYSOB_StartBurning(instance_02,pLight);
        FUN_80069c2c(instance_01);
        return (int)pLight;
      }
      segment = 1;
      if (Action < 3) {
        if (Action == 1) {
          uVar3 = *puVar2;
          *puVar2 = uVar3 & 0xfffffffe | 0x1080;
          if ((uVar3 & 0x10000) != 0) {
            instance_02 = Force->LinkChild;
            pLight = PhysObGetLight(instance_02);
            PHYSOB_StartLighting(instance_02,pLight);
          }
          *(undefined2 *)(puVar2 + 1) = *(undefined2 *)((int)pvVar5 + 0x18);
          uVar3 = (uint)*(ushort *)((int)pvVar5 + 0x1a);
          *(ushort *)((int)puVar2 + 6) = *(ushort *)((int)pvVar5 + 0x1a);
          INSTANCE_LinkToParent(instance,Force,LinkNode);
          FUN_80069c2c(instance_00);
          return uVar3;
        }
        FUN_80069c2c(instance_01);
        return segment;
      }
      if (Action == 9) {
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post(instance,0x40002,5);
      }
      if (Action == (uint)*(ushort *)((int)pvVar5 + 0xc)) {
        instance->flags = instance->flags | 8;
      }
      if (Action == (uint)*(ushort *)((int)pvVar5 + 0xe)) {
        instance->flags = instance->flags | 0x10;
      }
    }
    if ((*(byte *)((int)pvVar5 + 0x11) != 0xff) && ((*(ushort *)((int)pvVar5 + 6) & 0x8000) != 0)) {
                    /* WARNING: Subroutine does not return */
      G2EmulationInstanceSetAnimation(instance,0,(uint)*(byte *)((int)pvVar5 + 0x11),0,0);
    }
    pp_Var4 = instance->object->modelList;
    if (pp_Var4 != (_Model **)0x0) {
      if ((*(byte *)((int)pvVar5 + 0x15) & 0x80) == 0) {
        segment = 0;
        if (0 < (*pp_Var4)->numSegments) {
          do {
            COLLIDE_SegmentCollisionOn(instance,segment);
            segment = segment + 1;
          } while (segment < (*instance->object->modelList)->numSegments);
        }
      }
      else {
        if (0 < (*pp_Var4)->numSegments) {
                    /* WARNING: Subroutine does not return */
          COLLIDE_SegmentCollisionOff(instance,0);
        }
      }
    }
    puVar2[2] = 0;
    *(undefined2 *)((int)puVar2 + 0x26) = 0;
    *(undefined2 *)(puVar2 + 9) = 0;
    *(undefined2 *)(puVar2 + 1) = *(undefined2 *)((int)pvVar5 + 0x18);
    iVar1 = 0;
    *(undefined2 *)((int)puVar2 + 6) = *(undefined2 *)((int)pvVar5 + 0x1a);
    instance->xVel = 0;
    instance->yVel = 0;
    instance->zVel = 0;
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = 0;
  }
  return iVar1;
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

void ResetOrientation(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  G2Anim_DisableController(&instance->anim,0,0x4c);
}



// decompiled code
// original method signature: 
// void /*$ra*/ FinishPush(struct _Instance *instance /*$a0*/)
 // line 1099, offset 0x8006a368
	/* begin block 1 */
		// Start line: 2384
	/* end block 1 */
	// End Line: 2385

void FinishPush(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  ResetOrientation(instance);
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

void PhysOb_AlignPush(_Instance *instance,int x,int y,int path,PhysObData *Data)

{
                    /* WARNING: Subroutine does not return */
  G2Anim_EnableController(&instance->anim,0,0x4c);
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

int FlipPhysOb(_Instance *instance,short x,short y,_Instance *Force)

{
  _Instance *p_Var1;
  int iVar2;
  uint *puVar3;
  short local_20;
  short local_1e [3];
  
  if (((((*(ushort *)((int)instance->data + 6) & 2) != 0) &&
       (local_20 = x, local_1e[0] = y, p_Var1 = PHYSOBS_IsAPushBlockAttached(instance),
       p_Var1 == (_Instance *)0x0)) &&
      (puVar3 = (uint *)instance->extraData, (*puVar3 & 0x2000) == 0)) &&
     (iVar2 = AnyBlocksInMotion(), iVar2 == 0)) {
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
                    /* WARNING: Subroutine does not return */
    instance->xAccl = 0;
    ResetOrientation(instance);
  }
  return 0;
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

int CanBePickedUp(_Instance *instance,_Instance *Force,int LinkNode)

{
  int iVar1;
  _PCollideInfo _Stack80;
  SVECTOR SStack32;
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
      SStack32.vx = *(short *)Force->matrix[LinkNode].t;
      SStack32.vy = *(short *)(Force->matrix[LinkNode].t + 1);
      SStack32.vz = *(short *)(Force->matrix[LinkNode].t + 2);
      _Stack80.newPoint = &SStack32;
      _Stack80.oldPoint = &local_18;
      iVar1 = CheckPhysObAbility(instance,0x20);
      if ((iVar1 != 0) && (SStack32.vz < local_18.vz)) {
        return 1;
      }
                    /* WARNING: Subroutine does not return */
      PHYSICS_CheckLineInWorld(instance,&_Stack80);
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

int PickUpPhysOb(_Instance *instance,short Steps,_Instance *Force,int LinkNode)

{
  if ((instance->LinkParent == (_Instance *)0x0) &&
     ((*(uint *)instance->extraData & 0x2000000) == 0)) {
                    /* WARNING: Subroutine does not return */
    TurnOffCollisionPhysOb(instance,7);
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

/* WARNING: Removing unreachable block (ram,0x8006a92c) */
/* WARNING: Removing unreachable block (ram,0x8006a940) */

_Instance * PHYSOB_BirthCollectible(_Instance *parent,int x,int y,int z,int type,int lifeTime)

{
  return (_Instance *)0x0;
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

/* WARNING: Removing unreachable block (ram,0x8006aa10) */
/* WARNING: Removing unreachable block (ram,0x8006aa24) */
/* WARNING: Removing unreachable block (ram,0x8006aa78) */
/* WARNING: Removing unreachable block (ram,0x8006aa88) */

_Instance * BirthProjectilePhysOb(_Instance *instance,int grabJoint,int type)

{
  return (_Instance *)0x0;
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

void StopPhysOb(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  *(undefined2 *)((int)pvVar1 + 0x24) = 0;
  *(undefined2 *)((int)pvVar1 + 0x26) = 0;
                    /* WARNING: Subroutine does not return */
  *(undefined2 *)((int)pvVar1 + 0x1a) = 1;
  ResetOrientation(instance);
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

void InitPhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  int Data;
  
  if ((instance->flags & 0x20000U) == 0) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Malloc(0x48,'\x1a');
  }
  if (*(short *)((int)instance->data + 0x1c) == 2) {
    Data = SetObjectIdleData(0,(_Instance *)0x0);
                    /* WARNING: Subroutine does not return */
    INSTANCE_Post(gameTracker->playerInstance,0x800024,Data);
  }
  Data = CheckPhysObAbility(instance,8);
  if (Data != 0) {
    G2Anim_DetachControllerFromSeg(&instance->anim,0,0x4c);
    G2Anim_DetachControllerFromSeg(&instance->anim,2,0xe);
  }
                    /* WARNING: Subroutine does not return */
  MEMPACK_Free((char *)instance->extraData);
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

void ProcessPhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  byte bVar1;
  ushort uVar2;
  _PhysObLight *pLight;
  int Data;
  _Instance *p_Var3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  void *pvVar8;
  short burnAmplitude;
  uint *puVar9;
  int iVar10;
  _PCollideInfo _Stack96;
  SVECTOR local_30;
  SVECTOR local_28;
  
  puVar9 = (uint *)instance->extraData;
  if (((instance == (gameTracker->gameData).asmData.lightInstances[0].lightInstance) &&
      (pLight = PhysObGetLight(instance), pLight != (_PhysObLight *)0x0)) &&
     ((gameTracker->gameData).asmData.lightInstances[0].lightInstance == instance)) {
    burnAmplitude = 0x1000;
    if (((*puVar9 & 0x8000) != 0) && (burnAmplitude = *(short *)(puVar9 + 0xd), burnAmplitude < 0))
    {
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
  if (((*puVar9 & 0x2000000) != 0) &&
     (Data = (uint)(ushort)instance->fadeValue + (gameTrackerX.timeMult >> 5),
     instance->fadeValue = (short)Data, 0xfff < Data * 0x10000 >> 0x10)) {
    instance->flags = instance->flags | 0x20;
  }
  if ((*puVar9 & 0x8000) != 0) {
    uVar2 = *(short *)(puVar9 + 0xd) + 0x88;
    if (*(short *)(puVar9 + 0xd) < 0) {
      *(ushort *)(puVar9 + 0xd) = uVar2;
      if (-1 < (int)((uint)uVar2 << 0x10)) {
        *(undefined2 *)(puVar9 + 0xd) = 0;
        *puVar9 = *puVar9 & 0xffff7fff;
        if ((*(ushort *)((int)instance->data + 6) & 0x20) != 0) {
          pLight = PhysObGetLight(instance);
          if ((*puVar9 & 0x40000) == 0) {
            PHYSOB_EndLighting(instance,pLight);
          }
          else {
            PHYSOB_EndBurning(instance,pLight);
          }
          *puVar9 = *puVar9 & 0xfffbffff;
        }
      }
    }
    else {
      *(ushort *)(puVar9 + 0xd) = uVar2;
      if (0xfff < (short)uVar2) {
        *(undefined2 *)(puVar9 + 0xd) = 0x1000;
        *puVar9 = *puVar9 & 0xffff7fff;
      }
    }
  }
  Data = CheckPhysObFamily(instance,5);
  if (Data != 0) {
    pvVar8 = instance->extraData;
    if (0 < *(int *)((int)pvVar8 + 4)) {
      Data = *(int *)((int)pvVar8 + 4) - gameTrackerX.timeMult;
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
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(gameTrackerX.playerInstance,0x24);
  }
  Data = CheckPhysObAbility(instance,0x40);
  if (Data != 0) {
    if ((*puVar9 & 0x100000) != 0) {
      *(ushort *)((int)instance->extraData + 0x14) =
           *(ushort *)((int)instance->extraData + 0x14) & 0xfff3;
      *puVar9 = *puVar9 & 0xffeff7ff;
    }
    if ((*puVar9 & 0x800) == 0) {
      return;
    }
    G2EmulationInstancePlayAnimation(instance);
    return;
  }
  Data = CheckPhysObAbility(instance,0x8000);
  if (Data != 0) {
    G2EmulationInstancePlayAnimation(instance);
  }
  uVar4 = *puVar9;
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 8) != 0) {
      ExecuteFlip(instance);
      uVar4 = *puVar9;
    }
    if (((uVar4 & 1) == 0) && ((uVar4 & 0x40) != 0)) {
      ExecuteDrag(instance);
    }
  }
  if ((*puVar9 & 2) != 0) {
    ExecuteSlideToStop(instance);
  }
  if ((*puVar9 & 0x4000) != 0) {
    ExecuteGravitate(instance);
  }
  if ((*puVar9 & 0x10) != 0) {
    ExecuteThrow(instance);
  }
  if ((*puVar9 & 0x20) != 0) {
    ExecuteFollow(instance);
  }
  if (((*puVar9 & 0x100000) != 0) && (Data = CheckPhysObFamily(instance,5), Data != 0)) {
    bVar1 = *(byte *)((int)instance->data + 0x10);
    if (bVar1 != 0xff) {
                    /* WARNING: Subroutine does not return */
      G2EmulationInstanceSetAnimation(instance,0,(uint)bVar1,0,0);
    }
    *puVar9 = *puVar9 & 0xffefffff;
  }
  if ((*puVar9 & 0x10000) != 0) {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  Data = CheckPhysObFamily(instance,7);
  if ((Data != 0) && (*(int *)((int)instance->extraData + 4) == 8)) {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  uVar4 = *puVar9;
  if (((uVar4 & 0x1000) != 0) || (instance->matrix == (MATRIX *)0x0)) {
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
    goto LAB_8006c274;
  }
  Data = (int)(instance->oldPos).z - (int)(instance->position).z;
  if (Data < 0xa0) {
    Data = 0xa0;
  }
  iVar10 = instance->zAccl * gameTrackerX.timeMult;
  if (iVar10 < 0) {
    iVar10 = iVar10 + 0xfff;
  }
  iVar10 = (instance->zVel + ((iVar10 << 4) >> 0x10)) * gameTrackerX.timeMult;
  if (iVar10 < 0) {
    iVar10 = iVar10 + 0xfff;
  }
  iVar10 = 0x40 - (iVar10 >> 0xc);
  burnAmplitude = (short)iVar10;
  iVar5 = iVar10 * 0x10000;
  if (iVar10 * 0x10000 >> 0x10 < 0xa0) {
    burnAmplitude = 0xa0;
    iVar5 = 0xa00000;
  }
  sVar7 = (short)((uint)iVar5 >> 0x10);
  if (iVar5 >> 0x10 < Data) {
    sVar7 = (short)Data;
    burnAmplitude = (short)Data;
  }
  Data = SetPhysicsGravityData((int)sVar7,(int)burnAmplitude,0,0,0,0xb50);
  uVar6 = PhysicsCheckGravity(instance,Data,5);
  if ((uVar6 & 1) == 0) {
LAB_8006c040:
    iVar10 = instance->attachedID;
code_r0x8006c048:
    if ((iVar10 == 0) && (instance->oldMatrix != (MATRIX *)0x0)) {
      if ((uVar6 & 1) != 0) {
        (instance->position).x = (instance->position).x + *(short *)(Data + 4);
        (instance->position).y = (instance->position).y + *(short *)(Data + 6);
      }
      if ((instance->zVel == 0) && ((instance->object->oflags & 0x400U) != 0)) {
        instance->zVel = -0x32;
      }
      instance->zAccl = -10;
      *puVar9 = *puVar9 | 4;
    }
    else {
      instance->zAccl = 0;
      instance->zVel = 0;
    }
  }
  else {
    iVar10 = instance->attachedID;
    if ((iVar10 != 0) && ((uVar4 & 4) == 0)) goto code_r0x8006c048;
    if ((instance->wNormal).z < 0xb51) goto LAB_8006c040;
    Data = instance->zVel;
    if ((*puVar9 & 0x14) != 0) {
      PHYSOB_PlayDropSound(instance);
    }
    uVar4 = *puVar9;
    *puVar9 = uVar4 & 0xfffffffb;
    if ((uVar4 & 0x400000) == 0) {
      *puVar9 = uVar4 & 0xff7ffffb;
    }
    else {
      *puVar9 = uVar4 & 0xffbfffeb | 0x200000;
      puVar9[0x11] = 10;
      TurnOnCollisionPhysOb(instance,7);
    }
    if ((*puVar9 & 0x10) != 0) {
      instance->flags2 = instance->flags2 & 0xffffff7f;
    }
    uVar4 = *puVar9;
    *puVar9 = uVar4 & 0xffffffef;
    if ((uVar4 & 0x200000) == 0) {
                    /* WARNING: Subroutine does not return */
      TurnOffCollisionPhysOb(instance,4);
    }
    if ((uVar6 & 0x80000) == 0) {
      instance->zVel = -1;
    }
    else {
      *puVar9 = *puVar9 | 0x1000;
      instance->zAccl = 0;
      instance->zVel = 0;
    }
    if ((instance->oldMatrix != (MATRIX *)0x0) && ((*puVar9 & 0x18000) == 0x10000)) {
      pLight = PhysObGetLight(instance);
      PHYSOB_StopLighting(instance,pLight);
    }
    iVar10 = CheckPhysObAbility(instance,8);
    if ((iVar10 != 0) && ((*puVar9 & 0x100) == 0)) {
      if (Data < -0x32) {
        instance->zAccl = 0;
                    /* WARNING: Subroutine does not return */
        ResetOrientation(instance);
      }
      *(short *)((int)puVar9 + 0x12) = (instance->position).z;
    }
  }
  if (((((instance->object->oflags & 0x80000U) == 0) &&
       (Data = CheckPhysObAbility(instance,8), Data != 0)) &&
      (gameTrackerX.gameData.asmData.MorphType == 0)) &&
     ((gameTrackerX.gameData.asmData.MorphTime != 1000 &&
      (_Stack96.oldPoint = &local_30, (instance->flags2 & 0x8000000U) == 0)))) {
    _Stack96.newPoint = &local_28;
    local_30.vx = (instance->position).x;
    local_30.vy = (instance->position).y;
    local_30.vz = (instance->position).z;
    local_28.vz = local_30.vz + -0x500;
    local_28.vx = local_30.vx;
    local_28.vy = local_30.vy;
                    /* WARNING: Subroutine does not return */
    PHYSICS_CheckLineInWorld(instance,&_Stack96);
  }
LAB_8006c274:
  if ((*puVar9 & 0x200000) != 0) {
    puVar9[0x11] = puVar9[0x11] - 1;
    Data = PHYSOB_ReAlignFalling(instance,-900);
    if ((Data != 0) || ((int)puVar9[0x11] < 1)) {
                    /* WARNING: Subroutine does not return */
      *puVar9 = *puVar9 & 0xff5fffff;
      TurnOffCollisionPhysOb(instance,7);
    }
  }
  if ((((instance->object->oflags & 0x80000U) != 0) ||
      (Data = CheckPhysObAbility(instance,8), Data != 0)) ||
     (gameTrackerX.gameData.asmData._8_4_ == 1000)) {
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

ulong PhysicalObjectQuery(_Instance *instance,ulong Query)

{
  short sVar1;
  int iVar2;
  INICommand *pIVar3;
  MATRIX *pMVar4;
  ushort family;
  void *pvVar5;
  _G2EulerAngles_Type local_18;
  
  pMVar4 = (MATRIX *)&UNK_00000001;
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
    goto switchD_8006c380_caseD_8;
  case 2:
    pMVar4 = (MATRIX *)GetPhysicalAbility(instance);
    break;
  case 3:
    pMVar4 = *(MATRIX **)((MATRIX *)instance->extraData)->m;
    break;
  case 4:
    pvVar5 = instance->data;
    sVar1 = *(short *)((int)pvVar5 + 2);
    if (sVar1 == 3) {
      pMVar4 = (MATRIX *)(int)*(short *)((int)instance->extraData + 6);
    }
    else {
      if (sVar1 == 0) {
        pMVar4 = (MATRIX *)(int)*(char *)((int)pvVar5 + 0x14);
      }
      else {
        if (sVar1 == 2) {
          pMVar4 = (MATRIX *)(int)*(short *)((int)pvVar5 + 10);
        }
        else {
          pMVar4 = (MATRIX *)((uint)(sVar1 == 7) << 3);
        }
      }
    }
    break;
  case 5:
    pvVar5 = instance->extraData;
    iVar2 = CheckPhysObAbility(instance,0x40);
    pMVar4 = (MATRIX *)0x0;
    if (iVar2 != 0) {
      pMVar4 = (MATRIX *)(int)*(short *)((int)pvVar5 + 0x14);
    }
    break;
  case 6:
    pMVar4 = (MATRIX *)
             SetPositionData((int)(instance->position).x,(int)(instance->position).y,
                             (int)(instance->position).z);
    break;
  case 7:
    iVar2 = CheckPhysObAbility(instance,0x40);
    if (iVar2 == 0) {
      iVar2 = CheckPhysObFamily(instance,1);
      if (iVar2 == 0) {
        pMVar4 = (MATRIX *)
                 SetPositionData((int)(instance->rotation).x,(int)(instance->rotation).y,
                                 (int)(instance->rotation).z);
      }
      else {
        if (instance->matrix != (MATRIX *)0x0) {
                    /* WARNING: Subroutine does not return */
          G2EulerAngles_FromMatrix(&local_18,(_G2Matrix_Type *)(instance->matrix + 2),0);
        }
        local_18.x = 0;
        local_18.y = 0;
        local_18.z = 0;
        pMVar4 = (MATRIX *)SetPositionData(0,0,0);
      }
    }
    else {
      pMVar4 = (MATRIX *)
               SetPositionData(0,0,(int)(((uint)(ushort)(instance->rotation).z +
                                         (uint)*(ushort *)((int)instance->extraData + 0x16)) *
                                        0x10000) >> 0x10);
    }
    break;
  default:
    goto switchD_8006c380_caseD_8;
  case 0xb:
    pMVar4 = (MATRIX *)&UNK_00000003;
    break;
  case 0xc:
  case 0xd:
    pMVar4 = instance->matrix;
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
      pMVar4 = (MATRIX *)
               SetObjectDraftData(*(short *)((int)pvVar5 + 8),*(ushort *)((int)pvVar5 + 10),
                                  *(ushort *)((int)pvVar5 + 0xc),*(ushort *)((int)pvVar5 + 0x10),
                                  (int)*(short *)((int)pvVar5 + 0xe));
      return (ulong)pMVar4;
    }
switchD_8006c380_caseD_8:
    pMVar4 = (MATRIX *)0x0;
    break;
  case 0x17:
    iVar2 = CheckPhysObAbility(instance,0x40);
    if (iVar2 == 0) {
      return (ulong)(MATRIX *)0x0;
    }
    goto LAB_8006c7ac;
  case 0x18:
                    /* WARNING: Subroutine does not return */
    CIRC_Alloc(0x10);
  case 0x1b:
    pMVar4 = (MATRIX *)0x0;
  case 0x1a:
    iVar2 = CheckPhysObFamily(instance,2);
    if (iVar2 == 0) {
      if (*(short *)((int)instance->data + 10) != 0) {
        return (ulong)pMVar4;
      }
      if ((*(uint *)instance->extraData & 0x2000) != 0) {
        return (ulong)(MATRIX *)((uint)pMVar4 ^ 1);
      }
    }
    else {
      if ((*(ushort *)((int)instance->extraData + 0x14) & 2) == 0) {
        return (ulong)(MATRIX *)((uint)pMVar4 ^ 1);
      }
    }
    break;
  case 0x1c:
    iVar2 = CheckPhysObAbility(instance,0x40);
    goto joined_r0x8006c5d0;
  case 0x1d:
    family = 5;
LAB_8006c5a0:
    iVar2 = CheckPhysObFamily(instance,family);
joined_r0x8006c5d0:
    pMVar4 = (MATRIX *)0x0;
    if (iVar2 != 0) {
LAB_8006c7ac:
      pMVar4 = (MATRIX *)instance->data;
    }
  }
  return (ulong)pMVar4;
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

void PhysicalObjectPost(_Instance *instance,ulong Message,ulong Data)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  _PhysObLight *pLight;
  long in_a3;
  uint *puVar4;
  void *pvVar5;
  long local_20;
  void *in_stack_ffffffe4;
  
  puVar4 = (uint *)instance->extraData;
  if (Message == 0x800010) {
    ThrowPhysOb(instance,(evObjectThrowData *)Data);
    return;
  }
  if (Message < 0x800011) {
    if (Message == 0x200005) {
      uVar2 = *puVar4 | 0x1000000;
    }
    else {
      if (Message < 0x200006) {
        if ((undefined *)Message == &DAT_00100007) {
          puVar1 = *(uint **)(Data + 4);
          puVar4[5] = *puVar1;
          uVar2 = puVar1[1];
          *puVar4 = uVar2 & 0xffeff7ff;
          if ((uVar2 & 0x2000000) != 0) {
            instance->flags = instance->flags | 0x20;
          }
          iVar3 = CheckPhysObAbility(instance,0x20);
          if (iVar3 == 0) {
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
          if (Message != 0x80005) {
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
                    /* WARNING: Subroutine does not return */
          TurnOffCollisionPhysOb(instance,Data);
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
        iVar3 = STREAM_IsMorphInProgress();
        if ((iVar3 == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) {
          return;
        }
        iVar3 = FlipPhysOb(instance,*(short *)Data,*(short *)(Data + 2),*(_Instance **)(Data + 8));
        *(int *)(Data + 0xc) = iVar3;
        return;
      }
      if (Message < 0x800002) {
        if (Message != 0x200006) {
          if (Message != 0x800000) {
            return;
          }
          iVar3 = STREAM_IsMorphInProgress();
          if ((iVar3 == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) {
            return;
          }
          iVar3 = PushPhysOb(instance,*(short *)Data,*(short *)(Data + 2),*(short *)(Data + 4),
                             *(_Instance **)(Data + 8));
          *(int *)(Data + 0xc) = iVar3;
          return;
        }
        uVar2 = 0xfeff0000;
        goto LAB_8006ce48;
      }
      if (Message == 0x800004) {
        StopPhysOb(instance);
        return;
      }
      if (Message < 0x800005) {
        if (Message != 0x800002) {
          return;
        }
        iVar3 = STREAM_IsMorphInProgress();
        if (((iVar3 == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) &&
           (*(short *)(Data + 4) != 0)) {
          return;
        }
        iVar3 = PickUpPhysOb(instance,*(short *)(Data + 4),*(_Instance **)(Data + 8),
                             (int)*(short *)(Data + 6));
        *(undefined2 *)(Data + 6) = (short)iVar3;
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
    }
    *puVar4 = uVar2;
  }
  else {
    if (Message == 0x800027) {
      if (Data == 0) {
        *puVar4 = *puVar4 | 0x1000;
        return;
      }
      uVar2 = *puVar4 & 0xffffefff;
    }
    else {
      if (Message < 0x800028) {
        if (Message < 0x800023) {
          if (Message < 0x800021) {
            if (Message != 0x800020) {
              return;
            }
            SwitchPhysOb(instance);
            return;
          }
          iVar3 = CheckPhysOb(instance);
          if (iVar3 == 0) {
            return;
          }
          pvVar5 = instance->data;
          iVar3 = CheckPhysObFamily(instance,2);
          if (iVar3 != 0) {
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
        if (0x800025 < Message) {
          pvVar5 = instance->data;
          switch((int)(((uint)*(ushort *)((int)pvVar5 + 8) - 1) * 0x10000) >> 0x10) {
          case 0:
            HEALTHU_Pickup(instance);
            return;
          case 1:
          case 4:
            MANNA_Pickup();
          case 2:
          case 3:
            INSTANCE_PlainDeath(instance);
            return;
          case 5:
            goto switchD_8006cd34_caseD_5;
          case 6:
            goto switchD_8006cd34_caseD_6;
          default:
            return;
          }
        }
        if (Message != 0x800023) {
          return;
        }
        iVar3 = STREAM_IsMorphInProgress();
        if ((iVar3 == 0) && (gameTrackerX.gameData.asmData.MorphType != 0)) {
          return;
        }
        InteractPhysOb(instance,*(_Instance **)Data,(uint)*(ushort *)(Data + 4),
                       (uint)*(ushort *)(Data + 0xe));
        return;
      }
      if (Message != 0x80002b) {
        if (0x80002b < Message) {
          if (Message == 0x80002d) {
            ResetSwitchPhysOb(instance);
            return;
          }
          if (0x80002c < Message) {
            if (Message != 0x8000008) {
              return;
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationInstanceSetAnimation
                      (instance,0,*(int *)(Data + 4),*(int *)(Data + 8),*(int *)(Data + 0xc));
          }
          PhysobAnimCallback((char)instance,Message,(char)Data,in_a3,local_20,in_stack_ffffffe4);
          return;
        }
        if (Message != 0x800029) {
          if (Message != 0x80002a) {
            return;
          }
          iVar3 = CheckPhysObFamily(instance,2);
          if (iVar3 == 0) {
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
      uVar2 = 0xff7f0000;
LAB_8006ce48:
      uVar2 = *puVar4 & (uVar2 | 0xffff);
    }
    *puVar4 = uVar2;
  }
  return;
switchD_8006cd34_caseD_6:
  MANNA_Pickup();
switchD_8006cd34_caseD_5:
  if (*(char *)((int)pvVar5 + 0x11) == -1) {
    return;
  }
  uVar2 = G2EmulationInstanceQueryAnimation(instance,0);
  if (uVar2 == (uint)*(byte *)((int)pvVar5 + 0x11)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  printf("Collect %s\n");
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

long PhysobAnimCallback(_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,
                       long messageDataA,long messageDataB,void *data)

{
  ulong uVar1;
  
  if (message == G2ANIM_MSG_DONE) {
                    /* WARNING: Subroutine does not return */
    G2AnimSection_SetPaused(anim->section + sectionID);
  }
  uVar1 = INSTANCE_DefaultAnimCallback
                    (anim,sectionID,message,messageDataA,messageDataB,(_Instance *)data);
  return uVar1;
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

/* WARNING: Removing unreachable block (ram,0x8006d294) */
/* WARNING: Removing unreachable block (ram,0x8006d2a4) */
/* WARNING: Removing unreachable block (ram,0x8006d190) */
/* WARNING: Removing unreachable block (ram,0x8006d1a0) */

void CollidePhysicalObject(_Instance *instance,GameTracker *gameTracker)

{
  int Data;
  undefined4 *puVar1;
  PhysObSplinter *pPVar2;
  undefined4 *puVar3;
  FXSplinter *splintDef;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  short local_68;
  short sStack102;
  short local_64;
  _Instance *local_60 [14];
  
  puVar1 = (undefined4 *)instance->collideInfo;
  puVar9 = (uint *)instance->extraData;
  Data = CheckPhysObFamily(instance,7);
  if ((Data != 0) && (*(int *)((int)instance->extraData + 4) == 8)) {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  if (*(char *)((int)puVar1 + 7) == '\x03') {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  uVar10 = puVar1[5];
  GetPhysObCollisionType(instance);
  if ((*puVar9 & 0x4000) == 0) {
    uVar4 = *puVar9;
    if ((uVar4 & 0x10) == 0) {
      if ((uVar4 & 0x200004) == 0) {
        if (((uVar4 & 0x80) != 0) &&
           (puVar3 = (undefined4 *)&local_68, instance->LinkParent != (_Instance *)0x0)) {
          puVar5 = puVar1 + 0xc;
          do {
            uVar6 = puVar1[1];
            uVar7 = puVar1[2];
            uVar8 = puVar1[3];
            *puVar3 = *puVar1;
            puVar3[1] = uVar6;
            puVar3[2] = uVar7;
            puVar3[3] = uVar8;
            puVar1 = puVar1 + 4;
            puVar3 = puVar3 + 4;
          } while (puVar1 != puVar5);
          local_60[2] = instance->LinkParent;
          Data = SetCollideInfoData((_CollideInfo *)&local_68);
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(instance->LinkParent,0x200004,Data);
        }
        Data = CheckPhysObAbility(instance,0x1000);
        if (((Data != 0) && ((*puVar9 & 0x800000) == 0)) &&
           (gameTrackerX.gameData.asmData._8_4_ == 1000)) {
          pPVar2 = PhysObGetSplinter(instance);
          splintDef = (FXSplinter *)0x0;
          if (pPVar2 != (PhysObSplinter *)0x0) {
            splintDef = (FXSplinter *)pPVar2->splinterData;
          }
          _FX_BuildSplinters(instance,(SVECTOR *)0x0,(SVECTOR *)0x0,(SVECTOR *)0x0,splintDef,gFXT,
                             (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                             (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,0);
          INSTANCE_PlainDeath(instance);
        }
        Data = CheckPhysObFamily(instance,7);
        if (Data != 0) {
                    /* WARNING: Subroutine does not return */
          COLLIDE_SegmentCollisionOff(instance,0);
        }
      }
      else {
        if (((*(char *)((int)puVar1 + 7) != '\x01') || (puVar9[0x10] != uVar10)) &&
           (0xb4f < *(short *)(puVar1 + 7))) {
          if ((uVar4 & 0x200000) != 0) {
            *(undefined2 *)(puVar1 + 0xb) = 0;
          }
          (instance->position).x = (instance->position).x + *(short *)(puVar1 + 10);
          (instance->position).y = (instance->position).y + *(short *)((int)puVar1 + 0x2a);
                    /* WARNING: Subroutine does not return */
          (instance->position).z = (instance->position).z + *(short *)(puVar1 + 0xb);
          COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)(puVar1 + 10));
        }
      }
    }
    else {
      if (uVar10 != puVar9[0x10]) {
        CheckPhysObFamily(instance,7);
        if ((*puVar9 & 0x400000) == 0) {
          instance->xVel = 0;
          instance->yVel = 0;
          instance->zVel = 0;
          instance->xAccl = 0;
          instance->yAccl = 0;
          instance->zAccl = 0;
        }
        (instance->position).x = (instance->position).x + *(short *)(puVar1 + 10);
        (instance->position).y = (instance->position).y + *(short *)((int)puVar1 + 0x2a);
                    /* WARNING: Subroutine does not return */
        (instance->position).z = (instance->position).z + *(short *)(puVar1 + 0xb);
        COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)(puVar1 + 10));
      }
    }
  }
  else {
    if ((puVar9[2] != uVar10) &&
       ((uVar10 == 0 ||
        (((puVar1[1] & 0xffff0000) != 0x1010000 &&
         ((*(uint *)(*(int *)(uVar10 + 0x1c) + 0x2c) & 0x40000) == 0)))))) {
      *puVar9 = *puVar9 & 0xffffbfff | 0x10;
      puVar9[0x11] = 0x96000;
      local_68 = (instance->oldPos).x - (instance->position).x;
      sStack102 = (instance->oldPos).y - (instance->position).y;
      local_64 = (instance->oldPos).z - (instance->position).z;
      (instance->position).x = (instance->position).x + local_68;
      (instance->position).y = (instance->position).y + sStack102;
                    /* WARNING: Subroutine does not return */
      (instance->position).z = (instance->position).z + local_64;
      COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&local_68);
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

void TurnOffCollisionPhysOb(_Instance *instance,int coll)

{
  PhysObWeaponAttributes *pPVar1;
  
  pPVar1 = PhysObGetWeapon(instance);
  if (pPVar1 != (PhysObWeaponAttributes *)0x0) {
    if ((coll & 2U) != 0) {
                    /* WARNING: Subroutine does not return */
      COLLIDE_SegmentCollisionOff(instance,(int)pPVar1->LeftHandSphere);
    }
    if ((coll & 1U) != 0) {
                    /* WARNING: Subroutine does not return */
      COLLIDE_SegmentCollisionOff(instance,(int)pPVar1->RightHandSphere);
    }
    if ((coll & 4U) != 0) {
                    /* WARNING: Subroutine does not return */
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

int GetPhysObCollisionType(_Instance *instance)

{
  PhysObWeaponAttributes *pPVar1;
  void *pvVar2;
  
  pvVar2 = instance->collideInfo;
  if (((((*(uint *)instance->extraData & 0x1600001) == 0) &&
       ((*(uint *)((int)pvVar2 + 4) & 0xffff0000) == 0x1010000)) &&
      (*(char *)(*(int *)((int)pvVar2 + 8) + 4) == '\t')) &&
     ((*(char *)(*(int *)((int)pvVar2 + 0xc) + 4) == '\b' &&
      (pPVar1 = PhysObGetWeapon(instance), pPVar1 != (PhysObWeaponAttributes *)0x0)))) {
                    /* WARNING: Subroutine does not return */
    TurnOffCollisionPhysOb(instance,7);
  }
  return 0;
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

void ExecuteThrow(_Instance *instance)

{
  int iVar1;
  void *pvVar2;
  undefined auStack32 [16];
  
  pvVar2 = instance->extraData;
  if ((*(ushort *)((int)pvVar2 + 0x36) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    memset(auStack32,0,6);
  }
  (instance->rotation).x = (instance->rotation).x + *(short *)((int)pvVar2 + 0x3a);
  (instance->rotation).y = (instance->rotation).y + *(short *)((int)pvVar2 + 0x3c);
  (instance->rotation).z = (instance->rotation).z + *(short *)((int)pvVar2 + 0x3e);
  iVar1 = *(int *)((int)pvVar2 + 0x44) - gameTrackerX.timeMult;
  *(int *)((int)pvVar2 + 0x44) = iVar1;
  if (iVar1 < 0) {
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

void ExecuteFlip(_Instance *instance)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if ((*puVar1 & 2) != 0) {
    *puVar1 = *puVar1 & 0xfffffffd;
  }
  if ((*puVar1 & 0x100000) != 0) {
    if (*(short *)(puVar1 + 10) == 0xe) {
      instance->zVel = -0x32;
    }
                    /* WARNING: Subroutine does not return */
    ResetOrientation(instance);
  }
  G2EmulationInstancePlayAnimation(instance);
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
                    /* WARNING: Subroutine does not return */
  PHYSICS_CheckLineInWorld(instance,&local_48);
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

int PHYSOB_CheckThrownLineCollision(_Instance *instance,_Instance *parent)

{
  PhysObWeaponAttributes *pPVar1;
  
  if (instance->oldMatrix != (MATRIX *)0x0) {
    pPVar1 = PhysObGetWeapon(instance);
    if (pPVar1 != (PhysObWeaponAttributes *)0x0) {
                    /* WARNING: Subroutine does not return */
      rsin((int)(parent->rotation).z);
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

int PHYSOB_CheckDroppedLineCollision(_Instance *instance,_Instance *parent)

{
  int iVar1;
  int iVar2;
  MATRIX *pMVar3;
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
  
  if (parent != (_Instance *)0x0) {
    local_98 = *(uint *)&parent->position;
    local_94 = (parent->position).z;
    if (instance->matrix != (MATRIX *)0x0) {
      pMVar3 = instance->matrix;
      (instance->position).x = *(short *)instance->matrix->t;
      local_c8.newPoint = (SVECTOR *)&local_90;
      (instance->position).y = *(short *)(pMVar3->t + 1);
      local_c8.oldPoint = &local_88;
      (instance->position).z = *(short *)(pMVar3->t + 2);
      local_98._2_2_ = (short)(local_98 >> 0x10);
      pMVar3 = instance->matrix;
      local_88.vy = local_98._2_2_;
      local_88.vx = (short)local_98;
      local_88.vz = *(short *)(pMVar3->t + 2) + 100;
      iVar1 = ((int)(((uint)*(ushort *)pMVar3->t - (local_98 & 0xffff)) * 0x10000) >> 0x10) * 6000;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 0xfff;
      }
      iVar2 = (int)(short)(*(short *)(pMVar3->t + 1) - local_98._2_2_) * 6000;
      local_80 = (short)(iVar1 >> 0xc);
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0xfff;
      }
      local_7e = (short)(iVar2 >> 0xc);
      iVar1 = (int)(short)(*(short *)(pMVar3->t + 2) - local_88.vz) * 6000;
      if (iVar1 < 0) {
        iVar1 = iVar1 + 0xfff;
      }
      local_7c = (short)(iVar1 >> 0xc);
      local_8c = local_7c + local_88.vz;
      local_90 = CONCAT22(local_7e + local_98._2_2_,local_80 + (short)local_98);
      local_78 = local_90;
      local_74 = local_8c;
      SetNoPtCollideInFamily(parent);
                    /* WARNING: Subroutine does not return */
      PHYSICS_CheckLineInWorld(instance,&local_c8);
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
                    /* WARNING: Subroutine does not return */
  PHYSICS_CheckLineInWorld(instance,&local_48);
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

void PHYSOBS_SetNewAnim(_Instance *instance,PhysObData *Data,ulong modeBits,int path,int resetflg)

{
  Data->PathNumber = (short)path;
  Data->Mode = Data->Mode & 0xfffffffeU | modeBits;
  if (resetflg != 0) {
                    /* WARNING: Subroutine does not return */
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

long PHYSOB_CheckForEnemyInBlkSpot(_Instance *instance,int dx,int dy)

{
  _Instance *Inst;
  
  Inst = (gameTrackerX.instanceList)->first;
  while( true ) {
    if (Inst == (_Instance *)0x0) {
      return 0;
    }
    if (((Inst->object->oflags2 & 0x80000U) != 0) && ((Inst->flags2 & 0x8000000U) == 0)) break;
    Inst = Inst->next;
  }
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(Inst,0);
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
  
  gameTrackerX.block_collide_override = '\x01';
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
  gameTrackerX.block_collide_override = '\0';
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

void ExecuteGravitate(_Instance *instance)

{
  int iVar1;
  short sVar2;
  int iVar3;
  uint *puVar4;
  _G2EulerAngles_Type local_30 [3];
  
  puVar4 = (uint *)instance->extraData;
  sVar2 = *(short *)(puVar4 + 3);
  iVar3 = *(int *)(puVar4[2] + 0x40);
  iVar1 = CheckPhysObAbility(instance,1);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    COLLIDE_SegmentCollisionOff(instance,1);
  }
  if (*(short *)(puVar4 + 9) != 0) {
                    /* WARNING: Subroutine does not return */
    G2EulerAngles_FromMatrix(local_30,(_G2Matrix_Type *)(iVar3 + (int)sVar2 * 0x20),0x15);
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
                    /* WARNING: Subroutine does not return */
      *puVar4 = *puVar4 & 0xfefdbffa | 0x1080;
      TurnOffCollisionPhysOb(instance,7);
    }
    INSTANCE_KillInstance(instance);
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

void PHYSOB_Normalize(_SVector *v)

{
  ulong square;
  
  square = MATH3D_SquareLength((int)v->x,(int)v->y,(int)v->z);
  if (square != 0) {
                    /* WARNING: Subroutine does not return */
    MATH3D_FastSqrt0(square);
  }
  v->x = (short)(((int)v->x << 0xc) / 1);
  v->y = (short)(((int)v->y << 0xc) / 1);
  v->z = (short)(((int)v->z << 0xc) / 1);
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

int PHYSOB_MoveTowardsAlign(_Instance *instance,_SVector *orgVec,_SVector *endVec)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulong square;
  uint uVar6;
  uint uVar7;
  
  iVar1 = gameTrackerX.timeMult * 0x32;
  PHYSOB_Normalize(orgVec);
  PHYSOB_Normalize(endVec);
  iVar2 = (int)orgVec->y * (int)endVec->z - (int)orgVec->z * (int)endVec->y;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfff;
  }
  iVar3 = (int)orgVec->z * (int)endVec->x - (int)orgVec->x * (int)endVec->z;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0xfff;
  }
  iVar4 = (int)orgVec->x * (int)endVec->y - (int)orgVec->y * (int)endVec->x;
  if (iVar4 < 0) {
    iVar4 = iVar4 + 0xfff;
  }
  iVar5 = (int)orgVec->x * (int)endVec->x + (int)orgVec->y * (int)endVec->y +
          (int)orgVec->z * (int)endVec->z;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 0xfff;
  }
  iVar5 = MATH3D_racos_S(iVar5 >> 0xc);
  uVar7 = ((iVar5 << 0x10) >> 0x10) - ((iVar5 << 0x10) >> 0x1f) >> 1;
  uVar6 = SEXT24((short)(iVar1 >> 0xc));
  if ((int)uVar7 < (int)-uVar6) {
    uVar7 = -uVar6;
  }
  if ((int)uVar6 < (int)uVar7) {
    uVar7 = uVar6;
  }
  square = MATH3D_SquareLength((int)(short)(iVar2 >> 0xc),(int)(short)(iVar3 >> 0xc),
                               (int)(short)(iVar4 >> 0xc));
  if ((int)square < 1) {
                    /* WARNING: Subroutine does not return */
    rsin(uVar7);
  }
                    /* WARNING: Subroutine does not return */
  MATH3D_FastSqrt0(square);
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

/* WARNING: Removing unreachable block (ram,0x8006fea8) */
/* WARNING: Removing unreachable block (ram,0x8006fc58) */
/* WARNING: Removing unreachable block (ram,0x8006fcec) */
/* WARNING: Removing unreachable block (ram,0x8006fd00) */
/* WARNING: Removing unreachable block (ram,0x8006fd14) */
/* WARNING: Removing unreachable block (ram,0x8006fd4c) */
/* WARNING: Removing unreachable block (ram,0x8006fd5c) */
/* WARNING: Removing unreachable block (ram,0x8006fd6c) */
/* WARNING: Removing unreachable block (ram,0x8006fd88) */
/* WARNING: Removing unreachable block (ram,0x8006fd90) */
/* WARNING: Removing unreachable block (ram,0x8006fe74) */
/* WARNING: Removing unreachable block (ram,0x8006fe88) */
/* WARNING: Removing unreachable block (ram,0x8006feac) */
/* WARNING: Removing unreachable block (ram,0x8006fd1c) */
/* WARNING: Removing unreachable block (ram,0x8006fa2c) */
/* WARNING: Removing unreachable block (ram,0x8006fa54) */
/* WARNING: Removing unreachable block (ram,0x8006fa58) */
/* WARNING: Removing unreachable block (ram,0x8006fa6c) */
/* WARNING: Removing unreachable block (ram,0x8006fa70) */
/* WARNING: Removing unreachable block (ram,0x8006fa84) */
/* WARNING: Removing unreachable block (ram,0x8006fb1c) */
/* WARNING: Removing unreachable block (ram,0x8006fa98) */
/* WARNING: Removing unreachable block (ram,0x8006fab4) */
/* WARNING: Removing unreachable block (ram,0x8006faa0) */
/* WARNING: Removing unreachable block (ram,0x8006fab8) */
/* WARNING: Removing unreachable block (ram,0x8006fac4) */
/* WARNING: Removing unreachable block (ram,0x8006fae0) */
/* WARNING: Removing unreachable block (ram,0x8006fad4) */
/* WARNING: Removing unreachable block (ram,0x8006faa8) */
/* WARNING: Removing unreachable block (ram,0x8006fae8) */

int PHYSOB_ReAlignFalling(_Instance *instance,int zEndOff)

{
  int iVar1;
  int iVar2;
  _Model *p_Var3;
  _PCollideInfo local_b0;
  SVECTOR local_80;
  SVECTOR local_78 [10];
  
  p_Var3 = instance->object->modelList[instance->currentModel];
  iVar1 = 0;
  if (0 < p_Var3->numSegments) {
    iVar2 = 0;
    do {
      if ((p_Var3->segmentList[iVar1].hInfo != (_HInfo *)0x0) || (iVar1 == 0)) {
        iVar2 = (int)instance->matrix->m + iVar2;
        local_80.vx = *(short *)(iVar2 + 0x14);
        local_80.vy = *(short *)(iVar2 + 0x18);
        local_80.vz = *(short *)(iVar2 + 0x1c) + (short)zEndOff;
        local_78[0].vz = *(short *)(iVar2 + 0x1c) + 300;
        local_b0.newPoint = &local_80;
        local_b0.oldPoint = local_78;
        local_78[0].vx = local_80.vx;
        local_78[0].vy = local_80.vy;
                    /* WARNING: Subroutine does not return */
        PHYSICS_CheckLineInWorld(instance,&local_b0);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x20;
    } while (iVar1 < p_Var3->numSegments);
  }
  return 1;
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

/* WARNING: Removing unreachable block (ram,0x8006ff78) */

void DropPhysOb(_Instance *instance,int flags)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if (instance->LinkParent == (_Instance *)0x0) {
    *puVar1 = *puVar1 & 0xff7fffff;
    PHYSOB_CheckDroppedLineCollision(instance,(_Instance *)0x0);
    if ((flags & 2U) == 0) {
      if ((flags & 4U) == 0) {
        PHYSOB_ReAlignFalling(instance,0);
      }
      puVar1[0x10] = 0;
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
                    /* WARNING: Subroutine does not return */
  INSTANCE_UnlinkFromParent(instance);
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

int PHYSOBS_CheckObjectAxisAlignment(MATRIX *m0,MATRIX *m1,_SVector *axis)

{
  undefined local_40 [48];
  
                    /* WARNING: Subroutine does not return */
  ApplyMatrix(m0,axis,local_40);
}



// decompiled code
// original method signature: 
// int /*$ra*/ PHYSOB_CheckSlide(struct _Instance *instance /*$s0*/, int x /*$a1*/, int y /*$a2*/, struct evPhysicsSlideData **data /*$s1*/)
 // line 5252, offset 0x80070244
	/* begin block 1 */
		// Start line: 11797
	/* end block 1 */
	// End Line: 11798

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





