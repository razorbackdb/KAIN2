#include "THISDUST.H"
#include "MONSTER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MON_DoCombatTimers(struct _Instance *instance /*$s2*/)
 // line 100, offset 0x80086dcc
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x80086DCC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		unsigned long curtime; // $s1

		/* begin block 1.1 */
			// Start line: 116
			// Start offset: 0x80086E50
			// Variables:
		// 		struct _MonsterCombatAttributes *combat; // $v0
		/* end block 1.1 */
		// End offset: 0x80086EC0
		// End Line: 125
	/* end block 1 */
	// End offset: 0x80086F9C
	// End Line: 141

	/* begin block 2 */
		// Start line: 200
	/* end block 2 */
	// End Line: 201

void MON_DoCombatTimers(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ChangeHumanOpinion(struct _Instance *instance /*$a0*/)
 // line 146, offset 0x80086fb4
	/* begin block 1 */
		// Start line: 147
		// Start offset: 0x80086FB4
		// Variables:
	// 		int opinion; // $s0
	// 		int good; // $v0
	/* end block 1 */
	// End offset: 0x80087034
	// End Line: 187

	/* begin block 2 */
		// Start line: 296
	/* end block 2 */
	// End Line: 297

void MON_ChangeHumanOpinion(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(instance,1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CutOut_Monster(struct _Instance *instance /*$s2*/, int fade_amount /*$t4*/, int startseg /*$a2*/, int endseg /*$a3*/)
 // line 191, offset 0x80087050
	/* begin block 1 */
		// Start line: 192
		// Start offset: 0x80087050
		// Variables:
	// 		struct _SVector point; // stack offset -56
	// 		struct _SVector normal; // stack offset -48
	// 		struct _SVector p1; // stack offset -40
	// 		struct _SVector p2; // stack offset -32
	// 		int tmp; // $t0
	// 		struct MATRIX *mat; // $a0

		/* begin block 1.1 */
			// Start line: 218
			// Start offset: 0x80087184
			// Variables:
		// 		long color; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 218
				// Start offset: 0x80087184
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $v1
			// 		short _z0; // $a1
			// 		short _x1; // $a2
			// 		short _y1; // $a3
			// 		short _z1; // $t0
			// 		struct _SVector *_v; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80087184
			// End Line: 218
		/* end block 1.1 */
		// End offset: 0x8008722C
		// End Line: 229
	/* end block 1 */
	// End offset: 0x8008722C
	// End Line: 231

	/* begin block 2 */
		// Start line: 387
	/* end block 2 */
	// End Line: 388

void MON_CutOut_Monster(_Instance *instance,int fade_amount,int startseg,int endseg)

{
  int iVar1;
  int iVar2;
  MATRIX *pMVar3;
  MATRIX *pMVar4;
  uint auStack56 [4];
  short local_28;
  short local_26;
  short sStack36;
  short sStack32;
  short sStack30;
  short sStack28;
  
  pMVar3 = instance->matrix + startseg;
  pMVar4 = instance->matrix + endseg;
  iVar1 = (int)*(short *)pMVar3->t - (int)*(short *)pMVar4->t;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 7;
  }
  iVar2 = (int)*(short *)(pMVar3->t + 1) - (int)*(short *)(pMVar4->t + 1);
  sStack32 = (short)(iVar1 >> 3);
  local_28 = *(short *)pMVar3->t + sStack32;
  sStack32 = *(short *)pMVar4->t - sStack32;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 7;
  }
  iVar1 = (int)*(short *)(pMVar3->t + 2) - (int)*(short *)(pMVar4->t + 2);
  sStack30 = (short)(iVar2 >> 3);
  local_26 = *(short *)(pMVar3->t + 1) + sStack30;
  sStack30 = *(short *)(pMVar4->t + 1) - sStack30;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 7;
  }
  sStack28 = (short)(iVar1 >> 3);
  sStack36 = *(short *)(pMVar3->t + 2) + sStack28;
  sStack28 = *(short *)(pMVar4->t + 2) - sStack28;
                    /* WARNING: Subroutine does not return */
  LoadAverageShort12((uint *)&sStack32,(uint *)&local_28,fade_amount,0x1000 - fade_amount,auStack56)
  ;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DeadEntry(struct _Instance *instance /*$s1*/)
 // line 245, offset 0x80087294
	/* begin block 1 */
		// Start line: 246
		// Start offset: 0x80087294
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80087364
	// End Line: 269

	/* begin block 2 */
		// Start line: 528
	/* end block 2 */
	// End Line: 529

void MON_DeadEntry(_Instance *instance)

{
  undefined4 local_10;
  uint *puVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  puVar1 = (uint *)instance->extraData;
  MON_TurnOffAllSpheres(instance);
  if (puVar1[0x31] != 0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)(puVar1[0x31] + 4),1);
  }
  if (*(char *)((int)puVar1 + 0x155) == -1) {
                    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
                 0x18);
  }
  *puVar1 = *puVar1 | 0x200;
  instance->flags2 = instance->flags2 & 0xffffff3f;
  if ((puVar1[0x36] == 0) && (*(short *)(puVar1 + 0x51) != 0)) {
    MON_BirthSoul(instance,1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Dead(struct _Instance *instance /*$s2*/)
 // line 271, offset 0x80087378
	/* begin block 1 */
		// Start line: 272
		// Start offset: 0x80087378
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _Instance *soul; // $s5
	// 		struct __Event *message; // $v0
	// 		int reanimate; // $s6

		/* begin block 1.1 */
			// Start line: 295
			// Start offset: 0x80087424
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s0
		// 		int fade_amount; // $a1
		/* end block 1.1 */
		// End offset: 0x80087458
		// End Line: 307

		/* begin block 1.2 */
			// Start line: 326
			// Start offset: 0x800874E4
			// Variables:
		// 		struct _Model *model; // $s0
		// 		int i; // $s0
		// 		struct CVECTOR *ptr; // $v0
		/* end block 1.2 */
		// End offset: 0x80087534
		// End Line: 334

		/* begin block 1.3 */
			// Start line: 337
			// Start offset: 0x8008755C
			// Variables:
		// 		struct _Instance *imp; // $s0
		// 		struct _Instance *closest; // $s3

			/* begin block 1.3.1 */
				// Start line: 341
				// Start offset: 0x8008757C
				// Variables:
			// 		long closestdist; // $s4

				/* begin block 1.3.1.1 */
					// Start line: 350
					// Start offset: 0x800875F0
					// Variables:
				// 		long dist; // $v1
				/* end block 1.3.1.1 */
				// End offset: 0x80087630
				// End Line: 357
			/* end block 1.3.1 */
			// End offset: 0x80087640
			// End Line: 360

			/* begin block 1.3.2 */
				// Start line: 368
				// Start offset: 0x8008765C
				// Variables:
			// 		struct _MonsterAttributes *ma; // $v0
			/* end block 1.3.2 */
			// End offset: 0x800876E4
			// End Line: 375
		/* end block 1.3 */
		// End offset: 0x800876E4
		// End Line: 375

		/* begin block 1.4 */
			// Start line: 386
			// Start offset: 0x80087728
			// Variables:
		// 		struct SVECTOR New; // stack offset -96
		// 		struct SVECTOR Old; // stack offset -88
		// 		struct _PCollideInfo pcinfo; // stack offset -80
		/* end block 1.4 */
		// End offset: 0x80087790
		// End Line: 403

		/* begin block 1.5 */
			// Start line: 422
			// Start offset: 0x80087858
			// Variables:
		// 		struct _MonsterAttributes *ma; // $a0
		/* end block 1.5 */
		// End offset: 0x80087944
		// End Line: 454
	/* end block 1 */
	// End offset: 0x800879DC
	// End Line: 491

	/* begin block 2 */
		// Start line: 580
	/* end block 2 */
	// End Line: 581

void MON_Dead(_Instance *instance)

{
  char cVar1;
  int Data;
  uint introUniqueID;
  int Message;
  _Instance *instance_00;
  uint *puVar2;
  _Instance *instance_01;
  undefined4 local_70;
  undefined4 local_6c;
  SVECTOR local_60;
  SVECTOR local_58;
  _PCollideInfo _Stack80;
  
  puVar2 = (uint *)instance->extraData;
  instance_01 = (_Instance *)0x0;
  introUniqueID = puVar2[0x36];
  if (introUniqueID == 0) {
    if ((*puVar2 & 0x200) != 0) {
                    /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
    if ((instance->flags2 & 0x10U) != 0) {
      MON_PlayCombatIdle(instance,2);
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_6c,local_70));
    }
  }
  else {
    if (introUniqueID != 0x7fffffff) {
      instance_01 = INSTANCE_Find(introUniqueID);
    }
    if (instance_01 == (_Instance *)0x0) {
      MON_BirthSoul(instance,1);
    }
    else {
      if (*(int *)((int)instance_01->extraData + 0xd8) == 0) {
        *(long *)((int)instance_01->extraData + 0xd8) = instance->introUniqueID;
      }
    }
  }
  cVar1 = *(char *)(puVar2 + 0x55);
  if ((cVar1 == '\x06') || (cVar1 == '\x04')) {
    MON_KillMonster(instance);
  }
  else {
    if (((byte)(cVar1 - 1U) < 3) && (instance->perVertexColor == (CVECTOR *)0x0)) {
                    /* WARNING: Subroutine does not return */
      MEMPACK_Malloc(instance->object->modelList[instance->currentModel]->numVertices << 2,'!');
    }
    if ((*(char *)(puVar2 + 0x55) == '\0') && (puVar2[0x34] == 0)) {
      instance->flags2 = instance->flags2 | 0x80;
      instance_01 = (_Instance *)0x0;
      if (puVar2[0x35] == 0) {
        instance_00 = (gameTrackerX.instanceList)->first;
        while (instance_00 != (_Instance *)0x0) {
          if ((((instance != instance_00) && (instance_00->object != (Object *)0x0)) &&
              ((instance_00->object->oflags2 & 0x40000U) != 0)) &&
             ((instance_00->LinkParent == (_Instance *)0x0 &&
              ((Data = CheckPhysObFamily(instance_00,0), Data != 0 ||
               (Data = CheckPhysObFamily(instance_00,3), Data != 0)))))) {
                    /* WARNING: Subroutine does not return */
            MATH3D_LengthXYZ((int)(instance_00->position).x - (int)(instance->position).x,
                             (int)(instance_00->position).y - (int)(instance->position).y,
                             (int)(instance_00->position).z - (int)(instance->position).z);
          }
          instance_00 = instance_00->next;
        }
      }
      else {
        instance_01 = INSTANCE_Find(puVar2[0x35]);
      }
      if (instance_01 != (_Instance *)0x0) {
        G2Anim_EnableSegment(&instance->anim,(uint)*(byte *)((int)instance->data + 0x25));
        Data = CheckPhysObFamily(instance_01,3);
        if (Data == 0) {
          Data = SetObjectData(0,0,0,instance,3);
          Message = 0x800002;
        }
        else {
          Data = SetObjectBreakOffData(instance,3,0,0,0,0,1);
          Message = 0x800023;
        }
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post(instance_01,Message,Data);
      }
    }
    else {
      if ((*(char *)(puVar2 + 0x55) == '\x03') && ((*puVar2 & 0x400) == 0)) {
        local_60.vx = (instance->position).x;
        local_60.vy = (instance->position).y;
        local_60.vz = (instance->position).z;
        _Stack80.newPoint = &local_60;
        _Stack80.oldPoint = &local_58;
        local_58.vz = (instance->position).z + 0x200;
        local_58.vx = local_60.vx;
        local_58.vy = local_60.vy;
                    /* WARNING: Subroutine does not return */
        PHYSICS_CheckLineInWorld(instance,&_Stack80);
      }
    }
  }
  if ((*puVar2 & 0x400000) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  MON_ApplyPhysics(instance);
  Data = MON_OnGround(instance);
  if (Data != 0) {
    *puVar2 = *puVar2 | 2;
  }
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)(puVar2 + 2));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MissileHitEntry(struct _Instance *instance /*$s0*/)
 // line 496, offset 0x80087a04
	/* begin block 1 */
		// Start line: 497
		// Start offset: 0x80087A04
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s2
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80087A04
	// End Line: 497

	/* begin block 2 */
		// Start line: 1082
	/* end block 2 */
	// End Line: 1083

void MON_MissileHitEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined8 in_stack_ffffffe8;
  
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->xVel = 0;
                    /* WARNING: Subroutine does not return */
  instance->yVel = 0;
  MON_PlayAnim(instance,(MonsterAnim)CONCAT412(unaff_s1,CONCAT48(unaff_s0,in_stack_ffffffe8)),0x19);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MissileHit(struct _Instance *instance /*$s1*/)
 // line 522, offset 0x80087ae8
	/* begin block 1 */
		// Start line: 523
		// Start offset: 0x80087AE8
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct _MonsterAttributes *ma; // $s0
	// 		int thisFrame; // $s2
	// 		int lastFrame; // $a0
	/* end block 1 */
	// End offset: 0x80087BAC
	// End Line: 545

	/* begin block 2 */
		// Start line: 1153
	/* end block 2 */
	// End Line: 1154

void MON_MissileHit(_Instance *instance)

{
  int iVar1;
  int iVar2;
  undefined instance_00;
  undefined4 local_18;
  void *pvVar3;
  undefined4 local_14;
  void *pvVar4;
  
  instance_00 = SUB41(instance,0);
  pvVar4 = instance->extraData;
  pvVar3 = instance->data;
  iVar1 = G2EmulationInstanceQueryFrame(instance,0);
  iVar2 = G2EmulationInstanceQueryLastFrame(instance,0);
  if ((iVar2 < (int)(uint)*(byte *)((int)pvVar3 + 0x26)) &&
     ((int)(uint)*(byte *)((int)pvVar3 + 0x26) <= iVar1)) {
    FX_Blood_Impale(instance,(ushort)*(byte *)((int)pvVar3 + 0x25),instance,
                    (ushort)*(byte *)((int)pvVar3 + 0x25));
    MON_TerrainImpaleDeathEntry(instance_00);
    return;
  }
  if ((iVar2 < (int)(uint)*(byte *)((int)pvVar3 + 0x27)) &&
     ((int)(uint)*(byte *)((int)pvVar3 + 0x27) <= iVar1)) {
    FX_BloodCone(instance,(ushort)*(byte *)((int)pvVar3 + 0x25),0x50);
  }
  if ((instance->flags2 & 0x10U) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
  }
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)pvVar4 + 8));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BirthEntry(struct _Instance *instance /*$a0*/)
 // line 550, offset 0x80087bc8
	/* begin block 1 */
		// Start line: 1211
	/* end block 1 */
	// End Line: 1212

	/* begin block 2 */
		// Start line: 1212
	/* end block 2 */
	// End Line: 1213

void MON_BirthEntry(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Birth(struct _Instance *instance /*$a0*/)
 // line 554, offset 0x80087bd0
	/* begin block 1 */
		// Start line: 1219
	/* end block 1 */
	// End Line: 1220

void MON_Birth(_Instance *instance)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_fffffffc,unaff_retaddr));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ParryEntry(struct _Instance *instance /*$s1*/)
 // line 562, offset 0x80087bf0
	/* begin block 1 */
		// Start line: 563
		// Start offset: 0x80087BF0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80087BF0
	// End Line: 563

	/* begin block 2 */
		// Start line: 1235
	/* end block 2 */
	// End Line: 1236

void MON_ParryEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),9);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Parry(struct _Instance *instance /*$s0*/)
 // line 586, offset 0x80087c40
	/* begin block 1 */
		// Start line: 1299
	/* end block 1 */
	// End Line: 1300

void MON_Parry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  
  if ((instance->flags2 & 0x10U) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_retaddr,unaff_s0));
  }
                    /* WARNING: Subroutine does not return */
  MON_DefaultQueueHandler(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LandOnFeetEntry(struct _Instance *instance /*$s0*/)
 // line 599, offset 0x80087c84
	/* begin block 1 */
		// Start line: 600
		// Start offset: 0x80087C84
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 614
			// Start offset: 0x80087CDC
			// Variables:
		// 		int damage; // $a1
		/* end block 1.1 */
		// End offset: 0x80087D00
		// End Line: 624
	/* end block 1 */
	// End offset: 0x80087D00
	// End Line: 625

	/* begin block 2 */
		// Start line: 1325
	/* end block 2 */
	// End Line: 1326

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void MON_LandOnFeetEntry(_Instance *instance)

{
  int mode;
  undefined4 unaff_s0;
  undefined4 unaff_retaddr;
  undefined8 uStackX0;
  
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  mode = 0x12;
  if (*(char *)((int)instance->extraData + 0x155) == '\v') {
    mode = 0x15;
  }
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)CONCAT88(uStackX0,CONCAT44(unaff_retaddr,unaff_s0)),mode);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LandOnFeet(struct _Instance *instance /*$s1*/)
 // line 629, offset 0x80087d2c
	/* begin block 1 */
		// Start line: 630
		// Start offset: 0x80087D2C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 648
			// Start offset: 0x80087D94
			// Variables:
		// 		int state; // $a1
		/* end block 1.1 */
		// End offset: 0x80087E20
		// End Line: 672
	/* end block 1 */
	// End offset: 0x80087E20
	// End Line: 673

	/* begin block 2 */
		// Start line: 1386
	/* end block 2 */
	// End Line: 1387

void MON_LandOnFeet(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_DefaultQueueHandler(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LandInWaterEntry(struct _Instance *instance /*$a0*/)
 // line 678, offset 0x80087e34
	/* begin block 1 */
		// Start line: 1484
	/* end block 1 */
	// End Line: 1485

	/* begin block 2 */
		// Start line: 1485
	/* end block 2 */
	// End Line: 1486

void MON_LandInWaterEntry(_Instance *instance)

{
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LandInWater(struct _Instance *instance /*$a0*/)
 // line 683, offset 0x80087e48
	/* begin block 1 */
		// Start line: 1494
	/* end block 1 */
	// End Line: 1495

void MON_LandInWater(_Instance *instance)

{
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_fffffffc,unaff_retaddr));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BreakHoldEntry(struct _Instance *instance /*$s1*/)
 // line 691, offset 0x80087e68
	/* begin block 1 */
		// Start line: 692
		// Start offset: 0x80087E68
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80087EC0
	// End Line: 701

	/* begin block 2 */
		// Start line: 1510
	/* end block 2 */
	// End Line: 1511

void MON_BreakHoldEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0xf);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BreakHold(struct _Instance *instance /*$s0*/)
 // line 703, offset 0x80087ed4
	/* begin block 1 */
		// Start line: 1537
	/* end block 1 */
	// End Line: 1538

void MON_BreakHold(_Instance *instance)

{
  if ((instance->flags2 & 0x10U) != 0) {
    MON_UnlinkFromRaziel(instance);
    if ((instance->LinkParent != (_Instance *)0x0) && (instance->currentMainState != 0xe)) {
      MON_UnlinkFromRaziel(instance);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  MON_DefaultQueueHandler(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ImpactEntry(struct _Instance *instance /*$s0*/)
 // line 720, offset 0x80087f48
	/* begin block 1 */
		// Start line: 721
		// Start offset: 0x80087F48
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterCombatAttributes *combat; // $s2
	/* end block 1 */
	// End offset: 0x80087F48
	// End Line: 721

	/* begin block 2 */
		// Start line: 1571
	/* end block 2 */
	// End Line: 1572

void MON_ImpactEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_retaddr;
  
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(unaff_retaddr,CONCAT48(unaff_s2,CONCAT44(unaff_s1,unaff_s0))),0x11
              );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Impact(struct _Instance *instance /*$s0*/)
 // line 739, offset 0x80087fec
	/* begin block 1 */
		// Start line: 740
		// Start offset: 0x80087FEC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80088058
	// End Line: 760

	/* begin block 2 */
		// Start line: 1619
	/* end block 2 */
	// End Line: 1620

void MON_Impact(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  if ((instance->flags2 & 0x10U) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
                    /* WARNING: Subroutine does not return */
  MON_DefaultQueueHandler(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_FallEntry(struct _Instance *instance /*$s0*/)
 // line 765, offset 0x8008806c
	/* begin block 1 */
		// Start line: 766
		// Start offset: 0x8008806C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x800880F0
	// End Line: 787

	/* begin block 2 */
		// Start line: 1673
	/* end block 2 */
	// End Line: 1674

void MON_FallEntry(_Instance *instance)

{
  char cVar1;
  int mode;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  cVar1 = *(char *)((int)instance->extraData + 0x155);
  if (cVar1 == '\x0e') {
    mode = 0x14;
  }
  else {
    if ((((cVar1 == '\x01') || (cVar1 == '\x13')) || (cVar1 == '\r')) || (cVar1 == '\x05')) {
      PhysicsSetVelFromRot(instance,&instance->rotation,0x28);
      instance->zVel = 0x28;
    }
    mode = 0x13;
  }
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
               mode);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Fall(struct _Instance *instance /*$s0*/)
 // line 794, offset 0x8008811c
	/* begin block 1 */
		// Start line: 795
		// Start offset: 0x8008811C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct __Event *message; // $a1
	/* end block 1 */
	// End offset: 0x800881F0
	// End Line: 838

	/* begin block 2 */
		// Start line: 1731
	/* end block 2 */
	// End Line: 1732

void MON_Fall(_Instance *instance)

{
  uint uVar1;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  uVar1 = *puVar2;
  if ((uVar1 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  if ((uVar1 & 0x400) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  MON_ApplyPhysics(instance);
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)(puVar2 + 2));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ThrownEntry(struct _Instance *instance /*$s0*/)
 // line 843, offset 0x80088208
	/* begin block 1 */
		// Start line: 844
		// Start offset: 0x80088208
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80088270
	// End Line: 860

	/* begin block 2 */
		// Start line: 1829
	/* end block 2 */
	// End Line: 1830

void MON_ThrownEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  instance->xAccl = 0;
  instance->yAccl = 0;
                    /* WARNING: Subroutine does not return */
  instance->zAccl = -8;
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Thrown(struct _Instance *instance /*$s0*/)
 // line 864, offset 0x800882a4
	/* begin block 1 */
		// Start line: 865
		// Start offset: 0x800882A4
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct Intro *impaler; // $v0

		/* begin block 1.1 */
			// Start line: 871
			// Start offset: 0x800882D4
		/* end block 1.1 */
		// End offset: 0x80088314
		// End Line: 881

		/* begin block 1.2 */
			// Start line: 887
			// Start offset: 0x80088330
			// Variables:
		// 		struct __Event *message; // $a1

			/* begin block 1.2.1 */
				// Start line: 899
				// Start offset: 0x80088370
				// Variables:
			// 		struct evMonsterHitTerrainData *data; // $v0
			/* end block 1.2.1 */
			// End offset: 0x80088370
			// End Line: 899
		/* end block 1.2 */
		// End offset: 0x800883E8
		// End Line: 924
	/* end block 1 */
	// End offset: 0x800883E8
	// End Line: 925

	/* begin block 2 */
		// Start line: 1874
	/* end block 2 */
	// End Line: 1875

void MON_Thrown(_Instance *instance)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if ((*puVar1 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  MON_ApplyPhysics(instance);
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)(puVar1 + 2));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ImpaleDeathEntry(struct _Instance *instance /*$s0*/)
 // line 930, offset 0x800883fc
	/* begin block 1 */
		// Start line: 931
		// Start offset: 0x800883FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttributes *ma; // $s2
	/* end block 1 */
	// End offset: 0x800883FC
	// End Line: 931

	/* begin block 2 */
		// Start line: 2010
	/* end block 2 */
	// End Line: 2011

void MON_ImpaleDeathEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_retaddr;
  
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(unaff_retaddr,CONCAT48(unaff_s2,CONCAT44(unaff_s1,unaff_s0))),0xd)
  ;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ImpaleDeath(struct _Instance *instance /*$s1*/)
 // line 950, offset 0x80088494
	/* begin block 1 */
		// Start line: 951
		// Start offset: 0x80088494
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s2
	// 		struct __Event *message; // $v0

		/* begin block 1.1 */
			// Start line: 958
			// Start offset: 0x800884C8
			// Variables:
		// 		int thisFrame; // $s3
		// 		int lastFrame; // $a0
		/* end block 1.1 */
		// End offset: 0x8008853C
		// End Line: 969
	/* end block 1 */
	// End offset: 0x80088680
	// End Line: 1004

	/* begin block 2 */
		// Start line: 2063
	/* end block 2 */
	// End Line: 2064

void MON_ImpaleDeath(_Instance *instance)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  void *pvVar3;
  undefined4 local_14;
  void *pvVar4;
  MonsterState in_stack_ffffffe0;
  
  pvVar3 = instance->extraData;
  pvVar4 = instance->data;
  iVar1 = MON_AnimPlaying(instance,(MonsterAnim)
                                   CONCAT412(local_14,CONCAT48(local_18,in_stack_ffffffe0)));
  if (iVar1 != 0) {
    iVar1 = G2EmulationInstanceQueryFrame(instance,0);
    iVar2 = G2EmulationInstanceQueryLastFrame(instance,0);
    if ((iVar2 < (int)(uint)*(byte *)((int)pvVar4 + 0x26)) &&
       ((int)(uint)*(byte *)((int)pvVar4 + 0x26) <= iVar1)) {
      FX_Blood_Impale(instance,(ushort)*(byte *)((int)pvVar4 + 0x25),instance,
                      (ushort)*(byte *)((int)pvVar4 + 0x25));
    }
    else {
      if ((iVar2 < (int)(uint)*(byte *)((int)pvVar4 + 0x27)) &&
         ((int)(uint)*(byte *)((int)pvVar4 + 0x27) <= iVar1)) {
        FX_BloodCone(instance,(ushort)*(byte *)((int)pvVar4 + 0x25),0x50);
      }
    }
  }
  if ((instance->flags2 & 0x10U) != 0) {
    iVar1 = MON_AnimPlaying(instance,(MonsterAnim)
                                     CONCAT412(local_14,CONCAT48(local_18,in_stack_ffffffe0)));
    if ((iVar1 != 0) &&
       (iVar1 = **(int **)((int)pvVar3 + 0x164), *(char *)(iVar1 + 0xd) != *(char *)(iVar1 + 0x16)))
    {
                    /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,in_stack_ffffffe0);
  }
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_TerrainImpaleDeathEntry(struct _Instance *instance /*$s1*/)
 // line 1009, offset 0x8008869c
	/* begin block 1 */
		// Start line: 1010
		// Start offset: 0x8008869C
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *ma; // $s0
	// 		struct Intro *impaler; // $s0
	/* end block 1 */
	// End offset: 0x800887E0
	// End Line: 1051

	/* begin block 2 */
		// Start line: 2187
	/* end block 2 */
	// End Line: 2188

void MON_TerrainImpaleDeathEntry(_Instance *instance)

{
  Intro *pIVar1;
  uint uVar2;
  undefined instance_00;
  int mode;
  undefined4 local_10;
  void *pvVar3;
  undefined4 local_c;
  undefined4 local_8;
  uint *puVar4;
  undefined4 local_4;
  
  puVar4 = (uint *)instance->extraData;
  pvVar3 = instance->data;
  *puVar4 = *puVar4 & 0xffffffef | 0x200000;
  MON_TurnOffAllSpheres(instance);
  MON_DropAllObjects(instance);
  G2Anim_EnableSegment(&instance->anim,(uint)*(byte *)((int)pvVar3 + 0x25));
  FX_BloodCone(instance,(ushort)*(byte *)((int)pvVar3 + 0x25),0x50);
  *puVar4 = *puVar4 | 0x800;
  instance->xVel = 0;
  instance->yVel = 0;
  instance->zVel = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  if (-1 < (int)puVar4[0x68]) {
    instance_00 = (undefined)instance->currentStreamUnitID;
    INSTANCE_FindIntro(instance->currentStreamUnitID,puVar4[0x68]);
    MON_Surprised(instance_00);
    return;
  }
  pIVar1 = MON_FindNearestImpalingIntro(instance->currentStreamUnitID,&instance->position);
  puVar4[0x68] = pIVar1->UniqueID;
  MON_MoveInstanceToImpalePoint(instance);
  if ((pIVar1 == (Intro *)0x0) ||
     (pIVar1->flags = pIVar1->flags & 0xffff7fff, pIVar1 == (Intro *)0x0)) {
LAB_800887d0:
    mode = 0x1f;
  }
  else {
    uVar2 = (uint)(ushort)(pIVar1->rotation).x & 0xfff;
    if (uVar2 < 0x801) {
      if (0x2a9 < uVar2) {
        mode = 0x1f;
        goto LAB_800887d8;
      }
    }
    else {
      mode = uVar2 - 0x1000;
      if (mode < 0) {
        mode = -mode;
      }
      if (0x2a9 < mode) goto LAB_800887d0;
    }
    mode = 0x20;
  }
LAB_800887d8:
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_4,CONCAT48(local_8,CONCAT44(local_c,local_10)))
               ,mode);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_TerrainImpaleDeath(struct _Instance *instance /*$s3*/)
 // line 1054, offset 0x800887fc
	/* begin block 1 */
		// Start line: 1055
		// Start offset: 0x800887FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct Intro *impaler; // $v1

		/* begin block 1.1 */
			// Start line: 1079
			// Start offset: 0x800888E4
		/* end block 1.1 */
		// End offset: 0x800888F4
		// End Line: 1082

		/* begin block 1.2 */
			// Start line: 1090
			// Start offset: 0x80088910
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s1
		// 		int fade_amount; // $s0
		/* end block 1.2 */
		// End offset: 0x80088978
		// End Line: 1108
	/* end block 1 */
	// End offset: 0x800889D4
	// End Line: 1120

	/* begin block 2 */
		// Start line: 2280
	/* end block 2 */
	// End Line: 2281

void MON_TerrainImpaleDeath(_Instance *instance)

{
  _Instance *p_Var1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x200) == 0) {
    MON_MoveInstanceToImpalePoint(instance);
    if ((instance->flags2 & 0x10U) != 0) {
      if (puVar2[0x31] != 0) {
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query(*(_Instance **)(puVar2[0x31] + 4),1);
      }
      *puVar2 = *puVar2 | 0x200;
      instance->flags2 = instance->flags2 & 0xffffffbf;
      if ((puVar2[0x36] == 0) && (*(short *)(puVar2 + 0x51) != 0)) {
        MON_BirthSoul(instance,1);
      }
    }
    return;
  }
  if (puVar2[0x36] == 0) {
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  p_Var1 = INSTANCE_Find(puVar2[0x36]);
  if (p_Var1 == (_Instance *)0x0) {
    MON_MoveInstanceToImpalePoint(instance);
    MON_BirthSoul(instance,1);
  }
  if ((*puVar2 & 0x400000) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)(puVar2 + 2));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SurprisedEntry(struct _Instance *instance /*$s0*/)
 // line 1125, offset 0x800889f0
	/* begin block 1 */
		// Start line: 1126
		// Start offset: 0x800889F0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x800889F0
	// End Line: 1126

	/* begin block 2 */
		// Start line: 2426
	/* end block 2 */
	// End Line: 2427

void MON_SurprisedEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x1a);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Surprised(struct _Instance *instance /*$s1*/)
 // line 1136, offset 0x80088a50
	/* begin block 1 */
		// Start line: 1137
		// Start offset: 0x80088A50
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80088AF8
	// End Line: 1157

	/* begin block 2 */
		// Start line: 2448
	/* end block 2 */
	// End Line: 2449

void MON_Surprised(_Instance *instance)

{
  if ((instance->flags2 & 0x10U) != 0) {
    MON_PlayCombatIdle(instance,2);
  }
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_StunnedEntry(struct _Instance *instance /*$s1*/)
 // line 1163, offset 0x80088b14
	/* begin block 1 */
		// Start line: 1164
		// Start offset: 0x80088B14
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterCombatAttributes *combat; // $s2
	/* end block 1 */
	// End offset: 0x80088C94
	// End Line: 1205

	/* begin block 2 */
		// Start line: 2504
	/* end block 2 */
	// End Line: 2505

void MON_StunnedEntry(_Instance *instance)

{
  short sVar1;
  int mode;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x40) == 0) {
    if ((*puVar2 & 0x100) != 0) {
                    /* WARNING: Subroutine does not return */
      *puVar2 = *puVar2 | 0x10110;
      MON_GetTime(instance);
    }
    sVar1 = *(short *)(puVar2 + 0x54);
    if ((sVar1 == 0x40) || (sVar1 == 0x2000)) {
      mode = 0x2c;
    }
    else {
      if (sVar1 == 0x10) {
        mode = 0x1b;
      }
      else {
        mode = 5;
      }
    }
  }
  else {
    *(ushort *)(puVar2[0x31] + 0x18) = *(ushort *)(puVar2[0x31] + 0x18) | 0x400;
    *(ushort *)(puVar2[0x31] + 0x16) = *(ushort *)(puVar2[0x31] + 0x16) & 0xefff;
    *puVar2 = *puVar2 | 0x810000;
    mode = MON_SetUpKnockBack(instance,*(_Instance **)(puVar2[0x31] + 4),
                              (evMonsterHitData *)puVar2[0x30]);
    if (mode == 0) {
      mode = 1;
    }
    else {
      mode = 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_4,CONCAT48(local_8,CONCAT44(local_c,local_10)))
               ,mode);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Stunned(struct _Instance *instance /*$s0*/)
 // line 1209, offset 0x80088cc4
	/* begin block 1 */
		// Start line: 1210
		// Start offset: 0x80088CC4
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x80088DC0
	// End Line: 1238

	/* begin block 2 */
		// Start line: 2615
	/* end block 2 */
	// End Line: 2616

void MON_Stunned(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  if ((instance->flags2 & 0x10U) == 0) {
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  if ((*(uint *)instance->extraData & 0x100) == 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),5);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GrabbedEntry(struct _Instance *instance /*$s0*/)
 // line 1243, offset 0x80088dd4
	/* begin block 1 */
		// Start line: 1244
		// Start offset: 0x80088DD4
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttributes *ma; // $s2
	/* end block 1 */
	// End offset: 0x80088E30
	// End Line: 1261

	/* begin block 2 */
		// Start line: 2684
	/* end block 2 */
	// End Line: 2685

void MON_GrabbedEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_retaddr;
  
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(unaff_retaddr,CONCAT48(unaff_s2,CONCAT44(unaff_s1,unaff_s0))),4);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Grabbed(struct _Instance *instance /*$s1*/)
 // line 1275, offset 0x80088ed0
	/* begin block 1 */
		// Start line: 1276
		// Start offset: 0x80088ED0
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *ma; // $s3
	// 		struct __Event *message; // $a1
	// 		int time; // $v1

		/* begin block 1.1 */
			// Start line: 1290
			// Start offset: 0x80088F28
		/* end block 1.1 */
		// End offset: 0x80088F28
		// End Line: 1290

		/* begin block 1.2 */
			// Start line: 1306
			// Start offset: 0x80088FFC
			// Variables:
		// 		struct evMonsterThrownData *data; // $s0
		/* end block 1.2 */
		// End offset: 0x8008906C
		// End Line: 1325
	/* end block 1 */
	// End offset: 0x80089150
	// End Line: 1360

	/* begin block 2 */
		// Start line: 2750
	/* end block 2 */
	// End Line: 2751

void MON_Grabbed(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  
  if ((instance->flags2 & 0x10U) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(unaff_s3,CONCAT48(unaff_s2,CONCAT44(unaff_s1,unaff_s0))),0xe);
  }
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_HitEntry(struct _Instance *instance /*$s1*/)
 // line 1365, offset 0x8008916c
	/* begin block 1 */
		// Start line: 1366
		// Start offset: 0x8008916C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $a0
	/* end block 1 */
	// End offset: 0x800891E4
	// End Line: 1381

	/* begin block 2 */
		// Start line: 2941
	/* end block 2 */
	// End Line: 2942

void MON_HitEntry(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  puVar3 = (uint *)instance->extraData;
  uVar2 = puVar3[0x31];
  *(ushort *)(uVar2 + 0x16) = *(ushort *)(uVar2 + 0x16) & 0xefff;
  *(ushort *)(uVar2 + 0x18) = *(ushort *)(uVar2 + 0x18) | 0x400;
  *puVar3 = *puVar3 | 0x10000;
  iVar1 = MON_SetUpKnockBack(instance,*(_Instance **)(uVar2 + 4),(evMonsterHitData *)puVar3[0x30]);
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
               (uint)(iVar1 == 0));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Hit(struct _Instance *instance /*$s0*/)
 // line 1385, offset 0x80089210
	/* begin block 1 */
		// Start line: 1386
		// Start offset: 0x80089210
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x800892E4
	// End Line: 1410

	/* begin block 2 */
		// Start line: 2986
	/* end block 2 */
	// End Line: 2987

void MON_Hit(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_AttackEntry(struct _Instance *instance /*$s0*/)
 // line 1415, offset 0x800892f8
	/* begin block 1 */
		// Start line: 1416
		// Start offset: 0x800892F8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttackAttributes *attack; // $s2
	/* end block 1 */
	// End offset: 0x800892F8
	// End Line: 1416

	/* begin block 2 */
		// Start line: 3046
	/* end block 2 */
	// End Line: 3047

void MON_AttackEntry(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
                    /* WARNING: Subroutine does not return */
  *(undefined4 *)((int)pvVar1 + 0x108) = 0x200000;
  MON_PlayAnimFromList(instance,(char *)(*(int *)((int)pvVar1 + 0xb8) + 0x1b),0,1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Attack(struct _Instance *instance /*$s2*/)
 // line 1431, offset 0x8008936c
	/* begin block 1 */
		// Start line: 1432
		// Start offset: 0x8008936C
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct _MonsterIR *enemy; // $s4
	// 		struct _MonsterAttackAttributes *attack; // $s0
	// 		struct _MonsterAnim *anim; // $s1
	/* end block 1 */
	// End offset: 0x80089524
	// End Line: 1475

	/* begin block 2 */
		// Start line: 3078
	/* end block 2 */
	// End Line: 3079

void MON_Attack(_Instance *instance)

{
  char cVar1;
  _MonsterAnim *p_Var2;
  int iVar3;
  undefined instance_00;
  undefined4 local_18;
  uint uVar4;
  undefined4 local_14;
  uint *puVar5;
  uint uVar6;
  
  instance_00 = SUB41(instance,0);
  puVar5 = (uint *)instance->extraData;
  uVar4 = puVar5[0x2e];
  uVar6 = puVar5[0x31];
  p_Var2 = MON_GetAnim(instance,(char *)(uVar4 + 0x1b),(int)*(char *)((int)puVar5 + 0x15b));
  if ((p_Var2->velocity != 0) && (iVar3 = MON_TransNodeAnimation(instance), iVar3 == 0)) {
    *(ushort *)((int)puVar5 + 0x126) = p_Var2->velocity;
    MON_MoveForward(instance);
  }
  iVar3 = MON_AnimPlayingFromList(instance,(char *)(uVar4 + 0x1b),(int)*(char *)(uVar4 + 10));
  if ((iVar3 != 0) &&
     (iVar3 = G2EmulationInstanceQueryPassedFrame(instance,0,(int)*(char *)(uVar4 + 9)), iVar3 != 0)
     ) {
    MON_TurnOnWeaponSphere(instance,(int)*(char *)(uVar4 + 8));
    MON_StunnedEntry(instance_00);
    return;
  }
  iVar3 = MON_AnimPlayingFromList(instance,(char *)(uVar4 + 0x1b),(int)*(char *)(uVar4 + 0xc));
  if ((iVar3 != 0) &&
     ((iVar3 = G2EmulationInstanceQueryPassedFrame(instance,0,(int)*(char *)(uVar4 + 0xb)),
      iVar3 != 0 && ((*puVar5 & 0x4000) != 0)))) {
                    /* WARNING: Subroutine does not return */
    MON_TurnOffWeaponSpheres(instance);
  }
  if ((instance->flags2 & 0x10U) == 0) {
    if (uVar6 != 0) {
                    /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
                    /* WARNING: Subroutine does not return */
    MON_DefaultQueueHandler(instance);
  }
  instance->flags2 = instance->flags2 & 0xffffffef;
  cVar1 = *(char *)((int)puVar5 + 0x15b) + '\x01';
  *(char *)((int)puVar5 + 0x15b) = cVar1;
  if ((int)cVar1 < (int)*(char *)(uVar4 + 0xe)) {
                    /* WARNING: Subroutine does not return */
    MON_PlayAnimFromList(instance,(char *)(uVar4 + 0x1b),(int)cVar1,1);
  }
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CombatEntry(struct _Instance *instance /*$a0*/)
 // line 1481, offset 0x8008954c
	/* begin block 1 */
		// Start line: 1483
		// Start offset: 0x8008954C
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	/* end block 1 */
	// End offset: 0x8008954C
	// End Line: 1488

	/* begin block 2 */
		// Start line: 3180
	/* end block 2 */
	// End Line: 3181

	/* begin block 3 */
		// Start line: 3181
	/* end block 3 */
	// End Line: 3182

	/* begin block 4 */
		// Start line: 3186
	/* end block 4 */
	// End Line: 3187

void MON_CombatEntry(_Instance *instance)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  puVar1[0x42] = 0x2000000;
  *puVar1 = *puVar1 & 0xfffbffff | 0x10000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Combat(struct _Instance *instance /*$s1*/)
 // line 1494, offset 0x80089578
	/* begin block 1 */
		// Start line: 1495
		// Start offset: 0x80089578
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s3

		/* begin block 1.1 */
			// Start line: 1513
			// Start offset: 0x8008960C
			// Variables:
		// 		struct _MonsterCombatAttributes *combat; // $s2

			/* begin block 1.1.1 */
				// Start line: 1523
				// Start offset: 0x8008965C
				// Variables:
			// 		int reason; // $a1

				/* begin block 1.1.1.1 */
					// Start line: 1538
					// Start offset: 0x800896AC
					// Variables:
				// 		int anim; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x800896BC
				// End Line: 1542

				/* begin block 1.1.1.2 */
					// Start line: 1553
					// Start offset: 0x80089718
				/* end block 1.1.1.2 */
				// End offset: 0x80089734
				// End Line: 1556

				/* begin block 1.1.1.3 */
					// Start line: 1567
					// Start offset: 0x80089784
					// Variables:
				// 		int anim; // $v0
				/* end block 1.1.1.3 */
				// End offset: 0x800897BC
				// End Line: 1578
			/* end block 1.1.1 */
			// End offset: 0x800897BC
			// End Line: 1582

			/* begin block 1.1.2 */
				// Start line: 1586
				// Start offset: 0x800897DC
				// Variables:
			// 		int state; // $a1
			/* end block 1.1.2 */
			// End offset: 0x80089820
			// End Line: 1597
		/* end block 1.1 */
		// End offset: 0x80089820
		// End Line: 1598
	/* end block 1 */
	// End offset: 0x80089820
	// End Line: 1600

	/* begin block 2 */
		// Start line: 3213
	/* end block 2 */
	// End Line: 3214

void MON_Combat(_Instance *instance)

{
  int reason;
  _MonsterAttackAttributes *attack;
  undefined4 local_18;
  uint *puVar1;
  undefined4 local_14;
  undefined4 local_10;
  int iVar2;
  undefined4 local_c;
  _MonsterIR *enemy;
  
  puVar1 = (uint *)instance->extraData;
  enemy = (_MonsterIR *)puVar1[0x31];
  if ((((enemy != (_MonsterIR *)0x0) && ((*puVar1 & 4) == 0)) &&
      (((*puVar1 & 0x10000000) == 0 || ((enemy->mirFlags & 0x1000) == 0)))) &&
     (reason = MON_ValidPosition(instance), reason != 0)) {
    iVar2 = *(int *)(puVar1[0x59] + 8);
    *(_Position **)(puVar1 + 0x47) = &enemy->instance->position;
    reason = MON_ShouldIFlee(instance);
    if (reason == 0) {
      if ((enemy->distance < *(short *)(iVar2 + 10)) || (*(char *)((int)puVar1 + 0x156) == '\n')) {
        if (((*puVar1 & 0x20000) != 0) && ((instance->flags2 & 0x12U) != 0)) {
          *puVar1 = *puVar1 & 0xbffdffff;
        }
        reason = MON_ShouldIEvade(instance);
        if (reason == 0) {
          if ((*puVar1 & 0x40000000) == 0) {
            if (*(char *)((int)puVar1 + 0x156) == '\n') {
              reason = MON_ShouldIFireAtTarget(instance,enemy);
            }
            else {
              attack = MON_ChooseAttack(instance,enemy);
              reason = MON_ShouldIAttack(instance,enemy,attack);
            }
            if (reason == 1) {
                    /* WARNING: Subroutine does not return */
              MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
            }
            if (reason == 2) {
                    /* WARNING: Subroutine does not return */
              MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
            }
            if ((*puVar1 & 0x20000) == 0) {
              reason = MON_ChooseCombatMove(instance,reason);
              if (reason != 0) {
                    /* WARNING: Subroutine does not return */
                MON_PlayAnim(instance,(MonsterAnim)
                                      CONCAT412(local_c,CONCAT48(local_10,CONCAT44(local_14,local_18
                                                                                  ))),reason);
              }
              MON_PlayCombatIdle(instance,2);
            }
          }
        }
        else {
          reason = MON_ChooseEvadeMove(instance);
          if (reason != 0) {
                    /* WARNING: Subroutine does not return */
            MON_PlayAnim(instance,(MonsterAnim)
                                  CONCAT412(local_c,CONCAT48(local_10,CONCAT44(local_14,local_18))),
                         reason);
          }
        }
                    /* WARNING: Subroutine does not return */
        MON_TurnToPosition(instance,&enemy->instance->position,*(short *)(puVar1[0x59] + 0x1c));
      }
      if (*(char *)((int)puVar1 + 0x156) == '\t') {
        MON_Grabbed((char)instance);
        return;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ProjectileEntry(struct _Instance *instance /*$a0*/)
 // line 1606, offset 0x80089844
	/* begin block 1 */
		// Start line: 1607
		// Start offset: 0x80089844
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $v1
	// 		struct _MonsterMissile *missileDef; // $a1
	/* end block 1 */
	// End offset: 0x80089844
	// End Line: 1607

	/* begin block 2 */
		// Start line: 3440
	/* end block 2 */
	// End Line: 3441

void MON_ProjectileEntry(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_PlayAnimFromList
            (instance,(char *)(*(int *)((int)instance->data + 0x3c) +
                               (int)*(char *)(*(int *)(*(int *)((int)instance->extraData + 0x164) +
                                                      8) + 0x1a) * 0x10 + 0xe),0,1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Projectile(struct _Instance *instance /*$s2*/)
 // line 1618, offset 0x8008989c
	/* begin block 1 */
		// Start line: 1619
		// Start offset: 0x8008989C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAttributes *ma; // $v1
	// 		struct _MonsterMissile *missileDef; // $s0
	/* end block 1 */
	// End offset: 0x800899C0
	// End Line: 1648

	/* begin block 2 */
		// Start line: 3465
	/* end block 2 */
	// End Line: 3466

void MON_Projectile(_Instance *instance)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_s0;
  _MonsterMissile *missiledef;
  undefined4 unaff_s1;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  missiledef = (_MonsterMissile *)
               (*(int *)((int)instance->data + 0x3c) +
               (int)*(char *)(*(int *)(puVar3[0x59] + 8) + 0x1a) * 0x10);
  if (puVar3[0x31] != 0) {
    if ((instance->flags2 & 0x10U) == 0) {
      iVar2 = MON_AnimPlayingFromList(instance,missiledef->animList,(uint)missiledef->anim);
      if (((iVar2 != 0) &&
          (iVar2 = G2EmulationInstanceQueryPassedFrame(instance,0,(uint)missiledef->frame),
          iVar2 != 0)) &&
         (MISSILE_FireAtInstance(instance,missiledef,*(_Instance **)(puVar3[0x31] + 4)),
         missiledef->reload != '\0')) {
        *puVar3 = *puVar3 & 0xffffffdf;
      }
                    /* WARNING: Subroutine does not return */
      MON_TurnToPosition(instance,(_Position *)(*(int *)(puVar3[0x31] + 4) + 0x5c),
                         *(short *)(puVar3[0x59] + 0x1c));
    }
    cVar1 = *(char *)((int)puVar3 + 0x15b) + '\x01';
    *(char *)((int)puVar3 + 0x15b) = cVar1;
    if ((int)cVar1 < (int)(uint)missiledef->numAnims) {
                    /* WARNING: Subroutine does not return */
      MON_PlayAnimFromList(instance,missiledef->animList,(int)cVar1,1);
    }
  }
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_IdleEntry(struct _Instance *instance /*$a1*/)
 // line 1657, offset 0x800899e0
	/* begin block 1 */
		// Start line: 1658
		// Start offset: 0x800899E0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 1668
			// Start offset: 0x80089A20
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v1
		/* end block 1.1 */
		// End offset: 0x80089A40
		// End Line: 1673
	/* end block 1 */
	// End offset: 0x80089A88
	// End Line: 1683

	/* begin block 2 */
		// Start line: 3546
	/* end block 2 */
	// End Line: 3547

void MON_IdleEntry(_Instance *instance)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  uVar1 = *puVar2;
  *puVar2 = uVar1 & 0xfffbefff;
  puVar2[0x42] = 1;
  if ((uVar1 & 4) == 0) {
    if (((instance->anim).section[0].flags & 1) == 0) {
      G2Anim_SetLooping(&instance->anim);
      *puVar2 = *puVar2 | 0x4000000;
    }
  }
  else {
    if (puVar2[0x31] == 0) {
                    /* WARNING: Subroutine does not return */
      MON_PlayAnimID(instance,(int)**(char **)((int)instance->data + 0x44),2);
    }
    MON_PlayCombatIdle(instance,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Idle(struct _Instance *instance /*$s3*/)
 // line 1685, offset 0x80089a98
	/* begin block 1 */
		// Start line: 1686
		// Start offset: 0x80089A98
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		int combatIdle; // $s4

		/* begin block 1.1 */
			// Start line: 1692
			// Start offset: 0x80089AD4
			// Variables:
		// 		int state; // $s1
		// 		struct _MonsterIR *enemy; // $s2
		/* end block 1.1 */
		// End offset: 0x80089BC8
		// End Line: 1721
	/* end block 1 */
	// End offset: 0x80089C90
	// End Line: 1738

	/* begin block 2 */
		// Start line: 3611
	/* end block 2 */
	// End Line: 3612

void MON_Idle(_Instance *instance)

{
  bool bVar1;
  int iVar2;
  undefined4 local_18;
  uint *puVar3;
  undefined4 local_14;
  int iVar4;
  uint uVar5;
  
  puVar3 = (uint *)instance->extraData;
  bVar1 = false;
  if ((*puVar3 & 4) == 0) {
    uVar5 = puVar3[0x31];
    iVar4 = -1;
    iVar2 = MON_ValidPosition(instance);
    if (iVar2 == 0) {
      iVar4 = 1;
    }
    else {
      if (uVar5 == 0) {
        if (((uint)*(byte *)((int)puVar3 + 0x156) - 2 < 2) && ((instance->flags2 & 2U) != 0)) {
          iVar4 = 5;
        }
      }
      else {
        bVar1 = true;
        iVar2 = MON_ShouldIFlee(instance);
        if (iVar2 == 0) {
          if ((*(ushort *)(uVar5 + 0x16) & 0x100) == 0) {
            if ((*(char *)((int)puVar3 + 0x156) == '\a') &&
               (*(short *)(puVar3 + 0x4e) < *(short *)(uVar5 + 0x14))) {
                    /* WARNING: Subroutine does not return */
              MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar5 + 4) + 0x5c),
                                 *(short *)(puVar3[0x59] + 0x1c));
            }
            iVar4 = 0xd;
          }
          else {
            iVar4 = 0x19;
          }
        }
        else {
          iVar4 = 0x13;
        }
        puVar3[0x47] = *(int *)(uVar5 + 4) + 0x5c;
      }
    }
    if (iVar4 != -1) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
  }
  else {
    if ((puVar3[1] & 0x10000000) != 0) {
                    /* WARNING: Subroutine does not return */
      AngleMoveToward(&(instance->rotation).z,*(short *)(puVar3 + 0x49),
                      (short)((int)*(short *)(puVar3[0x59] + 0x1c) * gameTrackerX.timeMult * 0x10 >>
                             0x10));
    }
  }
  if (((*puVar3 & 4) == 0) && (((*puVar3 & 0x4000000) == 0 || ((instance->flags2 & 2U) != 0)))) {
    if (bVar1) {
      MON_PlayCombatIdle(instance,2);
    }
    else {
      MON_PlayRandomIdle(instance,2);
    }
  }
  MON_IdleQueueHandler(instance);
  return;
}



// autogenerated function stub: 
// void /*$ra*/ MON_FleeEntry(struct _Instance *instance /*$a0*/)
void MON_FleeEntry(struct _Instance *instance)
{ // line 1744, offset 0x80089cb8
	/* begin block 1 */
		// Start line: 1745
		// Start offset: 0x80089CB8
		// Variables:
			struct _MonsterVars *mv; // $a1
	/* end block 1 */
	// End offset: 0x80089CB8
	// End Line: 1745

	/* begin block 2 */
		// Start line: 3729
	/* end block 2 */
	// End Line: 3730

}


// decompiled code
// original method signature: 
// void /*$ra*/ MON_Flee(struct _Instance *instance /*$s1*/)
 // line 1759, offset 0x80089d0c
	/* begin block 1 */
		// Start line: 1760
		// Start offset: 0x80089D0C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 1785
			// Start offset: 0x80089DE0
		/* end block 1.1 */
		// End offset: 0x80089E28
		// End Line: 1792
	/* end block 1 */
	// End offset: 0x80089E28
	// End Line: 1793

	/* begin block 2 */
		// Start line: 3770
	/* end block 2 */
	// End Line: 3771

void MON_Flee(_Instance *instance)

{
  int iVar1;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;
  
  puVar2 = (uint *)instance->extraData;
  if (puVar2[0x31] == 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
  if ((((*puVar2 & 0x2000000) == 0) || (puVar2[0x33] == 0)) ||
     (*(short *)(puVar2[0x31] + 0x14) <= *(short *)(puVar2[0x33] + 0x14))) {
    if (*(short *)(puVar2[0x59] + 0x1a) < *(short *)(puVar2[0x31] + 0x14)) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
    iVar1 = MON_ValidPosition(instance);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      MATH3D_AngleFromPosToPos((_Position *)(*(int *)(puVar2[0x31] + 4) + 0x5c),&instance->position)
      ;
    }
  }
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PursueEntry(struct _Instance *instance /*$s1*/)
 // line 1798, offset 0x80089e3c
	/* begin block 1 */
		// Start line: 1799
		// Start offset: 0x80089E3C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80089E9C
	// End Line: 1814

	/* begin block 2 */
		// Start line: 3848
	/* end block 2 */
	// End Line: 3849

void MON_PursueEntry(_Instance *instance)

{
  uint uVar1;
  undefined4 unaff_s0;
  _MonsterVars *mv;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  mv = (_MonsterVars *)instance->extraData;
  uVar1 = mv->mvFlags;
  mv->mvFlags = uVar1 & 0xfffeffff | 0x1000;
  if ((uVar1 & 4) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,
                                    CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),3);
  }
  MON_GetPlanSlot(mv);
  MON_PlayCombatIdle(instance,2);
  mv->mode = 4;
  mv->mvFlags = mv->mvFlags & 0xfffdffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Pursue(struct _Instance *instance /*$s5*/)
 // line 1819, offset 0x80089ecc
	/* begin block 1 */
		// Start line: 1820
		// Start offset: 0x80089ECC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 1839
			// Start offset: 0x80089F58
			// Variables:
		// 		int anim; // $a1
		// 		int planresult; // $v1
		// 		long range; // $s2
		// 		struct _MonsterIR *target; // $s3
		// 		struct _MonsterCombatAttributes *combat; // $a2

			/* begin block 1.1.1 */
				// Start line: 1847
				// Start offset: 0x80089F74
				// Variables:
			// 		struct _MonsterIR *ally; // $a1
			/* end block 1.1.1 */
			// End offset: 0x80089FA4
			// End Line: 1866

			/* begin block 1.1.2 */
				// Start line: 1889
				// Start offset: 0x80089FD0
				// Variables:
			// 		int backtobase; // $s6

				/* begin block 1.1.2.1 */
					// Start line: 1904
					// Start offset: 0x8008A078
				/* end block 1.1.2.1 */
				// End offset: 0x8008A0D8
				// End Line: 1914

				/* begin block 1.1.2.2 */
					// Start line: 1918
					// Start offset: 0x8008A0F0
					// Variables:
				// 		int state; // $s4
				/* end block 1.1.2.2 */
				// End offset: 0x8008A1A8
				// End Line: 1983
			/* end block 1.1.2 */
			// End offset: 0x8008A1C0
			// End Line: 1991
		/* end block 1.1 */
		// End offset: 0x8008A1C0
		// End Line: 1992
	/* end block 1 */
	// End offset: 0x8008A1C0
	// End Line: 1993

	/* begin block 2 */
		// Start line: 3894
	/* end block 2 */
	// End Line: 3895

void MON_Pursue(_Instance *instance)

{
  short sVar1;
  bool bVar2;
  int anim;
  Intro *pIVar3;
  _MonsterAnim *p_Var4;
  _MonsterIR *target;
  _MonsterCombatAttributes *p_Var5;
  undefined4 local_20;
  undefined4 local_1c;
  _MonsterVars *mv;
  long distance;
  int iVar6;
  
  mv = (_MonsterVars *)instance->extraData;
  if ((mv->mvFlags & 4) != 0) {
    MON_GroundMoveQueueHandler(instance);
    return;
  }
  if ((mv->enemy == (_MonsterIR *)0x0) ||
     (((mv->mvFlags & 0x10000000) != 0 && ((mv->enemy->mirFlags & 0x1000) != 0))))
  goto LAB_8008a1b8;
  p_Var5 = mv->subAttr->combatAttributes;
  if (((mv->mvFlags & 0x2000000) == 0) ||
     ((target = mv->ally, target == (_MonsterIR *)0x0 || ((target->mirFlags & 0x200) != 0)))) {
    target = mv->enemy;
    distance = (int)p_Var5->combatRange + -200;
  }
  else {
    distance = (long)p_Var5->allyRange;
  }
  if ((target == (_MonsterIR *)0x0) || (anim = MON_ShouldIFireAtTarget(instance,target), anim != 0))
  goto LAB_8008a1b8;
  bVar2 = false;
  sVar1 = (target->instance->position).z;
  *(undefined4 *)&mv->destination = *(undefined4 *)&target->instance->position;
  (mv->destination).z = sVar1;
  mv->lookAtPos = &mv->destination;
  anim = MON_ValidPosition(instance);
  if (anim == 0) {
    pIVar3 = instance->intro;
    distance = 100;
    if (pIVar3 == (Intro *)0x0) {
      sVar1 = (mv->lastValidPos).z;
      *(undefined4 *)&mv->destination = *(undefined4 *)&mv->lastValidPos;
      (mv->destination).z = sVar1;
    }
    else {
      sVar1 = (pIVar3->position).z;
      *(undefined4 *)&mv->destination = *(undefined4 *)&pIVar3->position;
      (mv->destination).z = sVar1;
    }
    bVar2 = true;
  }
  else {
    if ((mv->behaviorState == '\a') && (pIVar3 = instance->intro, pIVar3 != (Intro *)0x0)) {
                    /* WARNING: Subroutine does not return */
      MATH3D_LengthXYZ((int)(mv->destination).x - (int)(pIVar3->position).x,
                       (int)(mv->destination).y - (int)(pIVar3->position).y,
                       (int)(mv->destination).z - (int)(pIVar3->position).z);
    }
  }
  anim = MON_CheckPointSuitability(instance,&instance->position,&mv->destination);
  iVar6 = -1;
  if (anim == 0) goto LAB_8008a1b8;
  sVar1 = target->distance;
  p_Var4 = MON_GetAnim(instance,mv->subAttr->animList,2);
  anim = 3;
  if ((int)sVar1 < (int)(distance + (uint)p_Var4->distance)) {
    anim = 2;
  }
  if (distance < 0) {
    distance = 0;
  }
  anim = MON_DefaultPlanMovement(instance,anim,distance);
  switch(anim) {
  case 2:
  case 3:
switchD_8008a164_caseD_2:
    iVar6 = 2;
    break;
  case 4:
    if ((target->mirFlags & 2) == 0) {
      iVar6 = 0xd;
      if (bVar2) goto switchD_8008a164_caseD_2;
    }
    else {
      MON_GetPlanSlot(mv);
    }
  }
  if (iVar6 == -1) {
    return;
  }
LAB_8008a1b8:
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_1c,local_20));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_WanderEntry(struct _Instance *instance /*$s1*/)
 // line 1998, offset 0x8008a1e8
	/* begin block 1 */
		// Start line: 1999
		// Start offset: 0x8008A1E8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008A258
	// End Line: 2015

	/* begin block 2 */
		// Start line: 4260
	/* end block 2 */
	// End Line: 4261

void MON_WanderEntry(_Instance *instance)

{
  uint uVar1;
  int iVar2;
  undefined4 local_10;
  _MonsterVars *mv;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 in_stack_fffffffc;
  
  mv = (_MonsterVars *)instance->extraData;
  uVar1 = mv->mvFlags;
  mv->mvFlags = uVar1 | 0x11000;
  if ((uVar1 & 4) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,CONCAT48(local_8,CONCAT44(local_c,local_10))),
                 2);
  }
  MON_GetPlanSlot(mv);
  iVar2 = MON_AnimPlaying(instance,(MonsterAnim)
                                   CONCAT412(in_stack_fffffffc,
                                             CONCAT48(local_8,CONCAT44(local_c,local_10))));
  if (iVar2 == 0) {
    MON_PlayRandomIdle(instance,2);
  }
  mv->mvFlags = mv->mvFlags & 0xfffdffff;
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Wander(struct _Instance *instance /*$s2*/)
 // line 2021, offset 0x8008a290
	/* begin block 1 */
		// Start line: 2022
		// Start offset: 0x8008A290
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 2027
			// Start offset: 0x8008A2C8
		/* end block 1.1 */
		// End offset: 0x8008A31C
		// End Line: 2032

		/* begin block 1.2 */
			// Start line: 2042
			// Start offset: 0x8008A36C
			// Variables:
		// 		int markerID; // $s0
		/* end block 1.2 */
		// End offset: 0x8008A3B4
		// End Line: 2046

		/* begin block 1.3 */
			// Start line: 2054
			// Start offset: 0x8008A3C8
			// Variables:
		// 		struct _Position *target; // $a1
		// 		short range; // $a2
		/* end block 1.3 */
		// End offset: 0x8008A40C
		// End Line: 2068

		/* begin block 1.4 */
			// Start line: 2074
			// Start offset: 0x8008A41C
			// Variables:
		// 		int planresult; // $v1
		// 		int state; // $a1
		/* end block 1.4 */
		// End offset: 0x8008A4AC
		// End Line: 2111
	/* end block 1 */
	// End offset: 0x8008A4EC
	// End Line: 2119

	/* begin block 2 */
		// Start line: 4308
	/* end block 2 */
	// End Line: 4309

void MON_Wander(_Instance *instance)

{
  int iVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  if ((*puVar3 & 4) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_TurnToPosition(instance,(_Position *)(puVar3 + 0x48),*(short *)(puVar3[0x59] + 0x1e));
  }
  if ((*puVar3 & 0x40000) == 0) {
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  iVar1 = MON_DefaultPlanMovement(instance,2,100);
  iVar2 = -1;
  switch(iVar1) {
  case 2:
  case 3:
    iVar2 = 2;
    break;
  case 4:
    iVar2 = 0x14;
    if (*(char *)((int)puVar3 + 0x156) != '\x04') {
                    /* WARNING: Subroutine does not return */
      rand();
    }
  }
  if (iVar2 != -1) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
  }
  if (puVar3[0x31] != 0) {
    iVar1 = MON_ShouldIFlee(instance);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
    }
    puVar3[0x47] = *(int *)(puVar3[0x31] + 4) + 0x5c;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_HideEntry(struct _Instance *instance /*$a0*/)
 // line 2124, offset 0x8008a508
	/* begin block 1 */
		// Start line: 4517
	/* end block 1 */
	// End Line: 4518

void MON_HideEntry(_Instance *instance)

{
  MON_PlayRandomIdle(instance,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Hide(struct _Instance *instance /*$s1*/)
 // line 2130, offset 0x8008a528
	/* begin block 1 */
		// Start line: 2131
		// Start offset: 0x8008A528
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s2
	/* end block 1 */
	// End offset: 0x8008A684
	// End Line: 2179

	/* begin block 2 */
		// Start line: 4529
	/* end block 2 */
	// End Line: 4530

void MON_Hide(_Instance *instance)

{
  byte bVar1;
  int mode;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;
  undefined4 local_8;
  uint uVar3;
  undefined4 local_4;
  
  puVar2 = (uint *)instance->extraData;
  uVar3 = puVar2[0x31];
  if (((*puVar2 & 4) == 0) && (uVar3 != 0)) {
    bVar1 = *(byte *)((int)puVar2 + 0x156);
    if (bVar1 == 8) {
      if (((*puVar2 & 0x40000000) == 0) && (mode = MON_ShouldIAmbushEnemy(instance), mode != 0)) {
        if (*(char *)((int)puVar2 + 0x153) == '\0') {
                    /* WARNING: Subroutine does not return */
          MON_TurnToPosition(instance,(_Position *)(*(int *)(uVar3 + 4) + 0x5c),0x1000);
        }
        if (*(char *)((int)puVar2 + 0x153) == '\x01') {
          mode = 0x28;
        }
        else {
          mode = 0x29;
        }
                    /* WARNING: Subroutine does not return */
        MON_PlayAnim(instance,(MonsterAnim)
                              CONCAT412(local_4,CONCAT48(local_8,CONCAT44(local_c,local_10))),mode);
      }
    }
    else {
      if ((8 < bVar1) || (bVar1 != 4)) {
                    /* WARNING: Subroutine does not return */
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
      }
      MON_ChangeBehavior(instance,(uint)*(byte *)(puVar2 + 0x56));
    }
  }
  if ((instance->flags2 & 0x10U) != 0) {
    if ((*puVar2 & 0x40000000) != 0) {
                    /* WARNING: Subroutine does not return */
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
    MON_PlayRandomIdle(instance,1);
  }
                    /* WARNING: Subroutine does not return */
  MON_DefaultQueueHandler(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SurpriseAttackEntry(struct _Instance *instance /*$a0*/)
 // line 2185, offset 0x8008a6a4
	/* begin block 1 */
		// Start line: 2186
		// Start offset: 0x8008A6A4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterCombatAttributes *combatAttr; // $v0
	// 		struct _MonsterAttributes *ma; // $v1
	/* end block 1 */
	// End offset: 0x8008A728
	// End Line: 2212

	/* begin block 2 */
		// Start line: 4641
	/* end block 2 */
	// End Line: 4642

void MON_SurpriseAttackEntry(_Instance *instance)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  cVar1 = *(char *)(*(int *)(*(int *)((int)pvVar3 + 0x164) + 8) + 0x1b);
  iVar2 = *(int *)((int)instance->data + 0x38);
  *(undefined *)((int)pvVar3 + 0x15b) = 0;
  iVar2 = iVar2 + (int)cVar1 * 0x20;
  *(int *)((int)pvVar3 + 0xb8) = iVar2;
                    /* WARNING: Subroutine does not return */
  MON_PlayAnimFromList(instance,(char *)(iVar2 + 0x1b),0,1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SurpriseAttack(struct _Instance *instance /*$a0*/)
 // line 2214, offset 0x8008a738
	/* begin block 1 */
		// Start line: 4710
	/* end block 1 */
	// End Line: 4711

void MON_SurpriseAttack(_Instance *instance)

{
  MON_Attack(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_EnvironmentDamageEntry(struct _Instance *instance /*$a0*/)
 // line 2222, offset 0x8008a758
	/* begin block 1 */
		// Start line: 4726
	/* end block 1 */
	// End Line: 4727

	/* begin block 2 */
		// Start line: 4727
	/* end block 2 */
	// End Line: 4728

void MON_EnvironmentDamageEntry(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_EnvironmentDamage(struct _Instance *instance /*$a0*/)
 // line 2226, offset 0x8008a760
	/* begin block 1 */
		// Start line: 4734
	/* end block 1 */
	// End Line: 4735

	/* begin block 2 */
		// Start line: 4735
	/* end block 2 */
	// End Line: 4736

void MON_EnvironmentDamage(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MonsterGlow(struct _Instance *instance /*$fp*/, long color /*stack 4*/, int glowtime /*$s5*/, int glowin /*$s6*/, int glowfade /*stack 16*/)
 // line 2230, offset 0x8008a768
	/* begin block 1 */
		// Start line: 2231
		// Start offset: 0x8008A768
		// Variables:
	// 		struct _FXGlowEffect *glow; // $v0
	// 		struct _MonsterAttributes *ma; // $s4
	/* end block 1 */
	// End offset: 0x8008A7D0
	// End Line: 2239

	/* begin block 2 */
		// Start line: 4742
	/* end block 2 */
	// End Line: 4743

void MON_MonsterGlow(_Instance *instance,long color,int glowtime,int glowin,int glowfade)

{
  long local_res4 [3];
  
  local_res4[0] = color;
                    /* WARNING: Subroutine does not return */
  FX_DoInstanceTwoSegmentGlow
            (instance,(uint)*(byte *)((int)instance->data + 0x1d),
             (uint)*(byte *)((int)instance->data + 0x20),local_res4,1,0x400,0xa0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GeneralDeathEntry(struct _Instance *instance /*$s1*/)
 // line 2258, offset 0x8008a8f4
	/* begin block 1 */
		// Start line: 2259
		// Start offset: 0x8008A8F4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s2
	/* end block 1 */
	// End offset: 0x8008AB14
	// End Line: 2328

	/* begin block 2 */
		// Start line: 4806
	/* end block 2 */
	// End Line: 4807

void MON_GeneralDeathEntry(_Instance *instance)

{
  ushort uVar1;
  int iVar2;
  int mode;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;
  void *pvVar4;
  undefined8 in_stack_ffffffe8;
  
  puVar3 = (uint *)instance->extraData;
  pvVar4 = instance->data;
  if (instance->LinkParent != (_Instance *)0x0) {
    MON_UnlinkFromRaziel(instance);
    instance->xAccl = 0;
    instance->yAccl = 0;
    instance->zAccl = -0x10;
  }
  instance->flags2 = instance->flags2 | 0x80;
  uVar1 = *(ushort *)(puVar3 + 0x54);
  *puVar3 = *puVar3 & 0xffffffef | 0x202000;
  if (uVar1 == 0x40) {
LAB_8008a9ec:
    if ((*(uint *)((int)pvVar4 + 0x10) & 8) == 0) {
      mode = 0x1b;
    }
    else {
      mode = 0x24;
    }
                    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_c,CONCAT48(local_10,in_stack_ffffffe8)),mode)
    ;
  }
  if (uVar1 < 0x41) {
    if (uVar1 == 0x10) {
                    /* WARNING: Subroutine does not return */
      MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_c,CONCAT48(local_10,in_stack_ffffffe8)),
                   0x1b);
    }
    if (uVar1 == 0x20) {
      *(undefined *)(puVar3 + 0x55) = 1;
      goto LAB_8008a9ec;
    }
  }
  else {
    if (uVar1 == 0x200) {
                    /* WARNING: Subroutine does not return */
      MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_c,CONCAT48(local_10,in_stack_ffffffe8)),
                   0x2b);
    }
    if (uVar1 == 0x400) {
      *(undefined *)(puVar3 + 0x55) = 6;
      puVar3[0x45] = 0;
      instance->xAccl = 0;
      instance->yAccl = 0;
      instance->xVel = 0;
      instance->yVel = 0;
      MON_DropAllObjects(instance);
      return;
    }
  }
  if (puVar3[0x31] == 0) {
    mode = 0x24;
  }
  else {
    iVar2 = MON_SetUpKnockBack(instance,*(_Instance **)(puVar3[0x31] + 4),
                               (evMonsterHitData *)puVar3[0x30]);
    mode = 0;
    if (iVar2 == 0) {
      mode = 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_c,CONCAT48(local_10,in_stack_ffffffe8)),mode);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GeneralDeath(struct _Instance *instance /*$s1*/)
 // line 2341, offset 0x8008ab44
	/* begin block 1 */
		// Start line: 2342
		// Start offset: 0x8008AB44
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		int dead; // $s2
	/* end block 1 */
	// End offset: 0x8008AC4C
	// End Line: 2378

	/* begin block 2 */
		// Start line: 4986
	/* end block 2 */
	// End Line: 4987

void MON_GeneralDeath(_Instance *instance)

{
  bool bVar1;
  int iVar2;
  undefined4 local_10;
  uint *puVar3;
  undefined4 local_c;
  undefined4 unaff_s2;
  undefined4 unaff_retaddr;
  
  puVar3 = (uint *)instance->extraData;
  bVar1 = false;
  if ((((instance->flags2 & 0x10U) == 0) ||
      (iVar2 = MON_AnimPlaying(instance,(MonsterAnim)
                                        CONCAT412(unaff_retaddr,
                                                  CONCAT48(unaff_s2,CONCAT44(local_c,local_10)))),
      iVar2 == 0)) && (*(char *)(puVar3 + 0x55) != '\x06')) {
    if ((instance->flags2 & 0x12U) != 0) {
                    /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    *puVar3 = *puVar3 & 0xffffffef;
    G2Anim_SetNoLooping(&instance->anim);
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
  MON_ApplyPhysics(instance);
  iVar2 = MON_OnGround(instance);
  if (iVar2 != 0) {
    *puVar3 = *puVar3 | 2;
  }
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)(puVar3 + 2));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_NoticeEntry(struct _Instance *instance /*$s1*/)
 // line 2383, offset 0x8008ac64
	/* begin block 1 */
		// Start line: 2384
		// Start offset: 0x8008AC64
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008AD08
	// End Line: 2396

	/* begin block 2 */
		// Start line: 5074
	/* end block 2 */
	// End Line: 5075

void MON_NoticeEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
  if ((*(int *)((int)instance->extraData + 4) < 0) &&
     (*(int *)(*(int *)(*(int *)((int)instance->extraData + 0x164) + 0xc) + 4) != 0)) {
                    /* WARNING: Subroutine does not return */
    MON_PlayAnim(instance,(MonsterAnim)
                          CONCAT412(in_stack_fffffffc,
                                    CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x2a);
  }
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x1d);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Notice(struct _Instance *instance /*$s1*/)
 // line 2398, offset 0x8008ad1c
	/* begin block 1 */
		// Start line: 2399
		// Start offset: 0x8008AD1C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008ADA0
	// End Line: 2416

	/* begin block 2 */
		// Start line: 5104
	/* end block 2 */
	// End Line: 5105

void MON_Notice(_Instance *instance)

{
  undefined4 unaff_s0;
  void *pvVar1;
  undefined4 unaff_s1;
  
  pvVar1 = instance->extraData;
  if ((instance->flags2 & 0x10U) != 0) {
                    /* WARNING: Subroutine does not return */
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  if (*(int *)((int)pvVar1 + 0xc4) != 0) {
    *(int *)((int)pvVar1 + 0x11c) = *(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c;
                    /* WARNING: Subroutine does not return */
    MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar1 + 0xc4) + 4) + 0x5c),
                       *(short *)(*(int *)((int)pvVar1 + 0x164) + 0x1c));
  }
                    /* WARNING: Subroutine does not return */
  MON_DefaultQueueHandler(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PupateEntry(struct _Instance *instance /*$a0*/)
 // line 2422, offset 0x8008adbc
	/* begin block 1 */
		// Start line: 2423
		// Start offset: 0x8008ADBC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008ADBC
	// End Line: 2423

	/* begin block 2 */
		// Start line: 5154
	/* end block 2 */
	// End Line: 5155

void MON_PupateEntry(_Instance *instance)

{
  instance->flags = instance->flags | 0x800;
                    /* WARNING: Subroutine does not return */
  instance->flags2 = instance->flags2 | 0x20000000;
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Pupate(struct _Instance *instance /*$s2*/)
 // line 2432, offset 0x8008ae1c
	/* begin block 1 */
		// Start line: 2433
		// Start offset: 0x8008AE1C
		// Variables:
	// 		struct _MonsterVars *mv; // $s3

		/* begin block 1.1 */
			// Start line: 2439
			// Start offset: 0x8008AE5C
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s0
		// 		static unsigned char pupateObjects[4]; // offset 0x0
		// 		struct Object *cocoonOb; // $s6
		// 		struct _Instance *cocoon; // $s1
		// 		struct _Instance *closest; // $s4
		// 		long closestDist; // $s5
		// 		int burst; // $s7

			/* begin block 1.1.1 */
				// Start line: 2457
				// Start offset: 0x8008AEDC
				// Variables:
			// 		long dist; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8008AFDC
			// End Line: 2475
		/* end block 1.1 */
		// End offset: 0x8008B0C8
		// End Line: 2512
	/* end block 1 */
	// End offset: 0x8008B130
	// End Line: 2528

	/* begin block 2 */
		// Start line: 5179
	/* end block 2 */
	// End Line: 5180

/* WARNING: Removing unreachable block (ram,0x8008aff4) */
/* WARNING: Removing unreachable block (ram,0x8008b01c) */
/* WARNING: Removing unreachable block (ram,0x8008b030) */
/* WARNING: Removing unreachable block (ram,0x8008b0c8) */

void MON_Pupate(_Instance *instance)

{
  bool bVar1;
  Intro *pIVar2;
  int iVar3;
  undefined4 local_28;
  void *pvVar4;
  undefined4 local_24;
  _Instance *p_Var5;
  uint *puVar6;
  Object *pOVar7;
  undefined8 in_stack_ffffffd0;
  
  puVar6 = (uint *)instance->extraData;
  pOVar7 = (Object *)0x0;
  if ((instance->flags & 0x800U) == 0) {
                    /* WARNING: Subroutine does not return */
    MON_DefaultQueueHandler(instance);
  }
  pvVar4 = instance->data;
  bVar1 = false;
  MON_PupateQueueHandler(instance);
  iVar3 = (int)*(char *)((int)pvVar4 + 0x17);
  if (iVar3 != -1) {
    p_Var5 = (gameTrackerX.instanceList)->first;
    pOVar7 = (Object *)(&objectAccess)[(byte)(&DAT_800cb1b8)[iVar3]].object;
    while (p_Var5 != (_Instance *)0x0) {
      if ((p_Var5->object == pOVar7) && ((p_Var5->flags & 0x20U) == 0)) {
        pIVar2 = instance->intro;
                    /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)(p_Var5->position).x - (int)(pIVar2->position).x,
                         (int)(p_Var5->position).y - (int)(pIVar2->position).y,
                         (int)(p_Var5->position).z - (int)(pIVar2->position).z);
      }
      p_Var5 = p_Var5->next;
    }
  }
  if (instance->currentMainState == 0x1a) {
    if (pOVar7 == (Object *)0x0) {
      iVar3 = MON_ShouldIAmbushEnemy(instance);
      if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
        MON_PlayAnim(instance,(MonsterAnim)CONCAT412(local_24,CONCAT48(local_28,in_stack_ffffffd0)),
                     0x1c);
      }
    }
    else {
      *(undefined2 *)((int)puVar6 + 0x146) = 0;
      MON_KillMonster(instance);
    }
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    instance->flags = instance->flags & 0xfffff7ff;
    instance->flags2 = instance->flags2 & 0xdfffffff;
    *puVar6 = *puVar6 & 0xffffff7f;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_EmbraceEntry(struct _Instance *instance /*$s0*/)
 // line 2533, offset 0x8008b15c
	/* begin block 1 */
		// Start line: 2534
		// Start offset: 0x8008B15C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008B15C
	// End Line: 2534

	/* begin block 2 */
		// Start line: 5416
	/* end block 2 */
	// End Line: 5417

void MON_EmbraceEntry(_Instance *instance)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  undefined4 unaff_retaddr;
  undefined4 in_stack_fffffffc;
  
                    /* WARNING: Subroutine does not return */
  MON_PlayAnim(instance,(MonsterAnim)
                        CONCAT412(in_stack_fffffffc,
                                  CONCAT48(unaff_retaddr,CONCAT44(unaff_s1,unaff_s0))),0x1e);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Embrace(struct _Instance *instance /*$s2*/)
 // line 2542, offset 0x8008b1bc
	/* begin block 1 */
		// Start line: 2543
		// Start offset: 0x8008B1BC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterIR *enemy; // $s0

		/* begin block 1.1 */
			// Start line: 2560
			// Start offset: 0x8008B26C
			// Variables:
		// 		struct _Instance *ei; // $s0
		/* end block 1.1 */
		// End offset: 0x8008B26C
		// End Line: 2560
	/* end block 1 */
	// End offset: 0x8008B308
	// End Line: 2573

	/* begin block 2 */
		// Start line: 5437
	/* end block 2 */
	// End Line: 5438

void MON_Embrace(_Instance *instance)

{
  undefined4 unaff_s0;
  uint uVar1;
  undefined4 unaff_s1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  uVar1 = puVar2[0x31];
  if (uVar1 != 0) {
    if (((*(short *)(uVar1 + 0x14) <= *(short *)(*(int *)(puVar2[0x59] + 8) + 0x14)) &&
        ((*(uint *)(uVar1 + 0x14) & 0x10200000) == 0x10200000)) && ((*puVar2 & 4) == 0)) {
                    /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
    *(ushort *)(uVar1 + 0x16) = *(ushort *)(uVar1 + 0x16) & 0xefff;
  }
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PetrifiedEntry(struct _Instance *instance /*$a0*/)
 // line 2658, offset 0x8008b328
	/* begin block 1 */
		// Start line: 2659
		// Start offset: 0x8008B328
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008B328
	// End Line: 2659

	/* begin block 2 */
		// Start line: 5312
	/* end block 2 */
	// End Line: 5313

void MON_PetrifiedEntry(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_Petrified(struct _Instance *instance /*$s1*/)
 // line 2666, offset 0x8008b364
	/* begin block 1 */
		// Start line: 2667
		// Start offset: 0x8008B364
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct __Event *message; // $v0
	/* end block 1 */
	// End offset: 0x8008B42C
	// End Line: 2686

	/* begin block 2 */
		// Start line: 5603
	/* end block 2 */
	// End Line: 5604

void MON_Petrified(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSTER_CalcDamageIntensity(int hp /*$a0*/, int maxHp /*$a1*/)
 // line 2694, offset 0x8008b450
	/* begin block 1 */
		// Start line: 5661
	/* end block 1 */
	// End Line: 5662

	/* begin block 2 */
		// Start line: 5662
	/* end block 2 */
	// End Line: 5663

int MONSTER_CalcDamageIntensity(int hp,int maxHp)

{
  return ((maxHp - hp) * 0x100) / maxHp;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSTER_ProcessClosestVerts(struct _Instance *instance /*$fp*/, struct _SVector *location /*stack 4*/, TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb /*stack 8*/, void *cb_data /*stack 12*/)
 // line 2704, offset 0x8008b468
	/* begin block 1 */
		// Start line: 2705
		// Start offset: 0x8008B468
		// Variables:
	// 		int i; // $s2
	// 		struct _Model *model; // $s7
	// 		struct _MVertex *vertexList; // $s4
	// 		struct _Vector locVec; // stack offset -96
	// 		long flag; // stack offset -48

		/* begin block 1.1 */
			// Start line: 2722
			// Start offset: 0x8008B4EC
			// Variables:
		// 		struct _MVertex *firstVertex; // $s0
		// 		struct _MVertex *lastVertex; // $s5
		// 		struct _MVertex *modelVertex; // $s0
		// 		struct MATRIX inverse; // stack offset -80
		// 		int tmp; // $a3
		// 		int dist; // $a0
		/* end block 1.1 */
		// End offset: 0x8008B5E8
		// End Line: 2755
	/* end block 1 */
	// End offset: 0x8008B600
	// End Line: 2757

	/* begin block 2 */
		// Start line: 5681
	/* end block 2 */
	// End Line: 5682

void MONSTER_ProcessClosestVerts
               (_Instance *instance,_SVector *location,
               TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb processVert_cb,void *cb_data)

{
  int iVar1;
  short *psVar2;
  _Model *p_Var3;
  MATRIX MStack80;
  
  p_Var3 = instance->object->modelList[instance->currentModel];
  iVar1 = 1;
  if (1 < p_Var3->numSegments) {
    psVar2 = &p_Var3->segmentList[1].firstVertex;
    do {
      if (psVar2[1] != -1) {
        PIPE3D_InvertTransform(&MStack80,instance->matrix + iVar1);
                    /* WARNING: Subroutine does not return */
        SetRotMatrix((undefined4 *)&MStack80);
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0xc;
    } while (iVar1 < p_Var3->numSegments);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessBloodyMess(struct _Instance *instance /*$a0*/, int vertidx /*$a1*/, int segidx /*$a2*/, int dist /*$a3*/, void *cb_data /*stack 16*/)
 // line 2764, offset 0x8008b630
	/* begin block 1 */
		// Start line: 2765
		// Start offset: 0x8008B630
		// Variables:
	// 		struct _MonsterVars *mv; // $t0

		/* begin block 1.1 */
			// Start line: 2785
			// Start offset: 0x8008B660
			// Variables:
		// 		long scl; // $a2
		// 		struct CVECTOR *cv; // $a0
		/* end block 1.1 */
		// End offset: 0x8008B734
		// End Line: 2811
	/* end block 1 */
	// End offset: 0x8008B734
	// End Line: 2812

	/* begin block 2 */
		// Start line: 5875
	/* end block 2 */
	// End Line: 5876

void ProcessBloodyMess(_Instance *instance,int vertidx,int segidx,int dist,void *cb_data)

{
  byte bVar1;
  CVECTOR *pCVar2;
  int iVar3;
  void *pvVar4;
  
  pvVar4 = instance->extraData;
  if (dist < *(int *)((int)cb_data + 4)) {
    *(int *)cb_data = vertidx;
    *(int *)((int)cb_data + 4) = dist;
    *(int *)((int)cb_data + 8) = segidx;
  }
  if (dist < 100) {
    iVar3 = ((100 - dist) * *(int *)((int)cb_data + 0x10) * 2) / 100;
    pCVar2 = instance->perVertexColor + vertidx;
    if (0x100 < iVar3) {
      iVar3 = 0x100;
    }
    pCVar2->r = ~(byte)((0xff - (uint)*(byte *)(*(int *)((int)pvVar4 + 0x164) + 0x3f)) * iVar3 >> 8)
    ;
    pCVar2->g = ~(byte)((0xff - (uint)*(byte *)(*(int *)((int)pvVar4 + 0x164) + 0x40)) * iVar3 >> 8)
    ;
    bVar1 = *(byte *)(*(int *)((int)pvVar4 + 0x164) + 0x41);
    pCVar2->cd = '\x01';
    pCVar2->b = ~(byte)((0xff - (uint)bVar1) * iVar3 >> 8);
    *(undefined4 *)((int)cb_data + 0xc) = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSTER_InitVertexColors(struct _Instance *instance /*$s1*/, struct _Model *model /*$s0*/)
 // line 2814, offset 0x8008b73c
	/* begin block 1 */
		// Start line: 2815
		// Start offset: 0x8008B73C
		// Variables:
	// 		int i; // $s0
	// 		struct CVECTOR *ptr; // $v0
	/* end block 1 */
	// End offset: 0x8008B790
	// End Line: 2824

	/* begin block 2 */
		// Start line: 5990
	/* end block 2 */
	// End Line: 5991

void MONSTER_InitVertexColors(_Instance *instance,_Model *model)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(model->numVertices << 2,'!');
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSTER_StartVertexBlood(struct _Instance *instance /*$s2*/, struct _SVector *location /*$s0*/, int amount /*$s4*/)
 // line 2826, offset 0x8008b7a4
	/* begin block 1 */
		// Start line: 2827
		// Start offset: 0x8008B7A4
		// Variables:
	// 		struct _Model *model; // $s1
	// 		struct bloodyMessType bmt; // stack offset -88

		/* begin block 1.1 */
			// Start line: 2838
			// Start offset: 0x8008B808
			// Variables:
		// 		struct _SVector localloc; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 2849
				// Start offset: 0x8008B878
				// Variables:
			// 		struct _MVertex *vertexList; // $s1
			// 		struct _Vector locVec; // stack offset -56
			// 		long flag; // stack offset -40
			// 		struct MATRIX *segMatrix; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8008B878
			// End Line: 2849
		/* end block 1.1 */
		// End offset: 0x8008B908
		// End Line: 2872
	/* end block 1 */
	// End offset: 0x8008B908
	// End Line: 2876

	/* begin block 2 */
		// Start line: 6015
	/* end block 2 */
	// End Line: 6016

int MONSTER_StartVertexBlood(_Instance *instance,_SVector *location,int amount)

{
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;
  
  if ((instance->perVertexColor == (CVECTOR *)0x0) &&
     (MONSTER_InitVertexColors(instance,instance->object->modelList[instance->currentModel]),
     instance->perVertexColor == (CVECTOR *)0x0)) {
    return -1;
  }
  local_40 = *(undefined4 *)location;
  local_3c = *(undefined4 *)&location->z;
  local_58 = -1;
  local_54 = 0x10000;
  local_50 = -1;
  local_4c = 0;
  local_48 = amount;
  MONSTER_ProcessClosestVerts(instance,(_SVector *)&local_40,ProcessBloodyMess,&local_58);
  if (local_54 < 0x33) {
    FX_MakeHitFX((_SVector *)&local_40);
    return local_58;
  }
                    /* WARNING: Subroutine does not return */
  SetRotMatrix((undefined4 *)(instance->matrix + local_50));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSTER_VertexBlood(struct _Instance *instance /*$s0*/, int vert /*$a1*/, int amount /*$a2*/)
 // line 2878, offset 0x8008b92c
	/* begin block 1 */
		// Start line: 2879
		// Start offset: 0x8008B92C
		// Variables:
	// 		int i; // $v1
	// 		struct _Model *model; // $t0

		/* begin block 1.1 */
			// Start line: 2885
			// Start offset: 0x8008B960
			// Variables:
		// 		struct CVECTOR *c; // $a3

			/* begin block 1.1.1 */
				// Start line: 2894
				// Start offset: 0x8008B978
				// Variables:
			// 		struct _MonsterVars *mv; // $v1
			// 		int current; // $a1
			// 		int wanted; // $a0
			// 		int col; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8008BAE8
			// End Line: 2952
		/* end block 1.1 */
		// End offset: 0x8008BAE8
		// End Line: 2953
	/* end block 1 */
	// End offset: 0x8008BAE8
	// End Line: 2954

	/* begin block 2 */
		// Start line: 6150
	/* end block 2 */
	// End Line: 6151

void MONSTER_VertexBlood(_Instance *instance,int vert,int amount)

{
  void *pvVar1;
  int iVar2;
  CVECTOR *address;
  uint uVar3;
  uint uVar4;
  uchar *puVar5;
  CVECTOR *pCVar6;
  
  address = instance->perVertexColor;
  if (address == (CVECTOR *)0x0) {
    return;
  }
  pCVar6 = address + vert;
  if (amount == 0) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)address);
  }
  uVar4 = (uint)pCVar6->g;
  pvVar1 = instance->extraData;
  if ((uint)pCVar6->r < uVar4) {
    if ((uint)pCVar6->r < (uint)pCVar6->b) {
      uVar4 = (uint)pCVar6->r;
      uVar3 = (uint)*(byte *)(*(int *)((int)pvVar1 + 0x164) + 0x3f);
      goto LAB_8008b9f0;
    }
  }
  else {
    if (uVar4 < pCVar6->b) {
      uVar3 = (uint)*(byte *)(*(int *)((int)pvVar1 + 0x164) + 0x40);
      goto LAB_8008b9f0;
    }
  }
  uVar4 = (uint)pCVar6->b;
  uVar3 = (uint)*(byte *)(*(int *)((int)pvVar1 + 0x164) + 0x41);
LAB_8008b9f0:
  if ((pCVar6->cd == '\x01') && ((int)uVar4 < (int)((0x100 - amount) * (0xff - uVar3)) >> 8)) {
    iVar2 = instance->object->modelList[instance->currentModel]->numVertices;
    address = instance->perVertexColor;
    if (iVar2 != 0) {
      puVar5 = &address->cd;
      do {
        if (*puVar5 == '\x01') {
          uVar4 = (uint)address->r + 8;
          if (uVar4 < 0x100) {
            address->r = (uchar)uVar4;
          }
          else {
            address->r = -1;
          }
          if ((uint)puVar5[-2] + 8 < 0x100) {
            puVar5[-2] = (uchar)((uint)puVar5[-2] + 8);
          }
          else {
            puVar5[-2] = -1;
          }
          if ((uint)puVar5[-1] + 8 < 0x100) {
            puVar5[-1] = (uchar)((uint)puVar5[-1] + 8);
          }
          else {
            puVar5[-1] = -1;
          }
          if (((uint)*address & 0xffffff) == 0xffffff) {
            *puVar5 = '\0';
          }
        }
        iVar2 = iVar2 + -1;
        puVar5 = puVar5 + 4;
        address = address + 1;
      } while (iVar2 != 0);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessBurntMess(struct _Instance *instance /*$a0*/, int vertidx /*$a1*/, int segidx /*$a2*/, int dist /*$a3*/, void *cb_data /*stack 16*/)
 // line 2961, offset 0x8008baf8
	/* begin block 1 */
		// Start line: 2962
		// Start offset: 0x8008BAF8
		// Variables:
	// 		short scl; // $a2
	// 		struct burntTuneType *burntTune; // $t0
	/* end block 1 */
	// End offset: 0x8008BB5C
	// End Line: 2982

	/* begin block 2 */
		// Start line: 6345
	/* end block 2 */
	// End Line: 6346

void ProcessBurntMess(_Instance *instance,int vertidx,int segidx,int dist,void *cb_data)

{
  uchar uVar1;
  
  if (dist < *(int *)((int)cb_data + 4)) {
    *(int *)cb_data = vertidx;
    *(int *)((int)cb_data + 4) = dist;
    *(int *)((int)cb_data + 8) = segidx;
  }
  if ((**(int **)((int)cb_data + 0xc) <= dist) ||
     (_uVar1 = ((dist << 0xc) / **(int **)((int)cb_data + 0xc) << 0x10) >> 0x14,
     uVar1 = (uchar)_uVar1, 0xfe < _uVar1)) {
    uVar1 = -2;
  }
  instance->perVertexColor[vertidx].r = uVar1;
  instance->perVertexColor[vertidx].g = uVar1;
  instance->perVertexColor[vertidx].b = uVar1;
  instance->perVertexColor[vertidx].cd = '\x01';
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSTER_StartVertexBurnt(struct _Instance *instance /*$s2*/, struct _SVector *location /*$s4*/, struct burntTuneType *burntTune /*$s0*/)
 // line 2992, offset 0x8008bba4
	/* begin block 1 */
		// Start line: 2993
		// Start offset: 0x8008BBA4
		// Variables:
	// 		struct _Model *model; // $s1
	// 		struct burntMessType bmt; // stack offset -80

		/* begin block 1.1 */
			// Start line: 3003
			// Start offset: 0x8008BC08
			// Variables:
		// 		struct _SVector localloc; // stack offset -64

			/* begin block 1.1.1 */
				// Start line: 3013
				// Start offset: 0x8008BC78
				// Variables:
			// 		struct _MVertex *vertexList; // $s1
			// 		struct _Vector locVec; // stack offset -56
			// 		long flag; // stack offset -40
			// 		struct MATRIX *segMatrix; // $s0
			/* end block 1.1.1 */
			// End offset: 0x8008BC78
			// End Line: 3013
		/* end block 1.1 */
		// End offset: 0x8008BD00
		// End Line: 3034
	/* end block 1 */
	// End offset: 0x8008BD00
	// End Line: 3037

	/* begin block 2 */
		// Start line: 6409
	/* end block 2 */
	// End Line: 6410

int MONSTER_StartVertexBurnt(_Instance *instance,_SVector *location,burntTuneType *burntTune)

{
  int local_50;
  int local_4c;
  int local_48;
  burntTuneType *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  if ((instance->perVertexColor == (CVECTOR *)0x0) &&
     (MONSTER_InitVertexColors(instance,instance->object->modelList[instance->currentModel]),
     instance->perVertexColor == (CVECTOR *)0x0)) {
    return -1;
  }
  local_40 = *(undefined4 *)location;
  local_3c = *(undefined4 *)&location->z;
  local_50 = -1;
  local_4c = 0x10000;
  local_48 = -1;
  local_44 = burntTune;
  MONSTER_ProcessClosestVerts(instance,(_SVector *)&local_40,ProcessBurntMess,&local_50);
  if (local_4c <= burntTune->burntDist >> 1) {
    FX_MakeHitFX((_SVector *)&local_40);
    return local_50;
  }
                    /* WARNING: Subroutine does not return */
  SetRotMatrix((undefined4 *)(instance->matrix + local_48));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSTER_VertexBurnt(struct _Instance *instance /*$a0*/, struct burntTuneType *burntTune /*$a1*/)
 // line 3039, offset 0x8008bd24
	/* begin block 1 */
		// Start line: 3041
		// Start offset: 0x8008BD24
		// Variables:
	// 		int i; // $a3
	// 		int fade; // $a2
	// 		struct _Model *model; // $t0

		/* begin block 1.1 */
			// Start line: 3050
			// Start offset: 0x8008BD5C
			// Variables:
		// 		struct CVECTOR *c; // $v1
		/* end block 1.1 */
		// End offset: 0x8008BDB0
		// End Line: 3059
	/* end block 1 */
	// End offset: 0x8008BDC8
	// End Line: 3062

	/* begin block 2 */
		// Start line: 6527
	/* end block 2 */
	// End Line: 6528

	/* begin block 3 */
		// Start line: 6528
	/* end block 3 */
	// End Line: 6529

	/* begin block 4 */
		// Start line: 6529
	/* end block 4 */
	// End Line: 6530

void MONSTER_VertexBurnt(_Instance *instance,burntTuneType *burntTune)

{
  char cVar1;
  CVECTOR *pCVar2;
  int iVar3;
  int iVar4;
  _Model *p_Var5;
  
  p_Var5 = instance->object->modelList[instance->currentModel];
  iVar3 = burntTune->fadeDelta;
  if ((instance->perVertexColor != (CVECTOR *)0x0) && (iVar4 = 0, 0 < p_Var5->numVertices)) {
    do {
      pCVar2 = instance->perVertexColor + iVar4;
      cVar1 = (char)iVar3;
      if (iVar3 <= (int)(uint)pCVar2->r) {
        pCVar2->r = pCVar2->r - cVar1;
      }
      if (iVar3 <= (int)(uint)pCVar2->g) {
        pCVar2->g = pCVar2->g - cVar1;
      }
      if (iVar3 <= (int)(uint)pCVar2->b) {
        pCVar2->b = pCVar2->b - cVar1;
      }
      pCVar2->cd = '\0';
      iVar4 = iVar4 + 1;
    } while (iVar4 < p_Var5->numVertices);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DamageEffect(struct _Instance *instance /*$s2*/, struct evFXHitData *data /*$s0*/)
 // line 3069, offset 0x8008bdd0
	/* begin block 1 */
		// Start line: 3070
		// Start offset: 0x8008BDD0
		// Variables:
	// 		struct _SVector accel; // stack offset -104
	// 		struct _MonsterVars *mv; // $s4

		/* begin block 1.1 */
			// Start line: 3086
			// Start offset: 0x8008BE2C
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s3

			/* begin block 1.1.1 */
				// Start line: 3090
				// Start offset: 0x8008BE4C
				// Variables:
			// 		struct MATRIX *mat; // $s1
			// 		struct _SVector location; // stack offset -96
			// 		struct _SVector vel; // stack offset -88
			// 		struct _SVector accel; // stack offset -80
			/* end block 1.1.1 */
			// End offset: 0x8008BF28
			// End Line: 3103

			/* begin block 1.1.2 */
				// Start line: 3107
				// Start offset: 0x8008BF40
				// Variables:
			// 		struct MATRIX *mat; // $s0
			// 		struct _SVector location; // stack offset -72
			// 		struct _SVector vel; // stack offset -64
			/* end block 1.1.2 */
			// End offset: 0x8008BFA0
			// End Line: 3116

			/* begin block 1.1.3 */
				// Start line: 3120
				// Start offset: 0x8008BFB4
				// Variables:
			// 		struct Object *flame; // $v0

				/* begin block 1.1.3.1 */
					// Start line: 3127
					// Start offset: 0x8008BFC4
					// Variables:
				// 		struct _Model *model; // $s0
				/* end block 1.1.3.1 */
				// End offset: 0x8008C01C
				// End Line: 3133
			/* end block 1.1.3 */
			// End offset: 0x8008C02C
			// End Line: 3135

			/* begin block 1.1.4 */
				// Start line: 3140
				// Start offset: 0x8008C06C
				// Variables:
			// 		struct MATRIX *mat; // $s0
			// 		struct _SVector location; // stack offset -56
			// 		struct _SVector vel; // stack offset -48
			// 		struct _SVector accel; // stack offset -40
			// 		int n; // $s1
			// 		int cnt; // $s4
			/* end block 1.1.4 */
			// End offset: 0x8008C180
			// End Line: 3162
		/* end block 1.1 */
		// End offset: 0x8008C180
		// End Line: 3163
	/* end block 1 */
	// End offset: 0x8008C22C
	// End Line: 3185

	/* begin block 2 */
		// Start line: 6599
	/* end block 2 */
	// End Line: 6600

/* WARNING: Removing unreachable block (ram,0x8008bfc4) */

void MON_DamageEffect(_Instance *instance,evFXHitData *data)

{
  int amount;
  evFXHitData *location;
  void *pvVar1;
  uint *puVar2;
  undefined4 local_68;
  undefined *local_64;
  undefined auStack64 [32];
  
  local_68 = 0;
  local_64 = &DAT_0000fffe;
  puVar2 = (uint *)instance->extraData;
  if (data == (evFXHitData *)0x0) {
    pvVar1 = instance->data;
    if ((*puVar2 & 0x10000200) == 0x10000000) {
                    /* WARNING: Subroutine does not return */
      rand();
    }
    if ((*puVar2 & 0x800010) != 0x800010) {
      if ((*puVar2 & 0x400000) != 0) {
        local_64 = &DAT_0000fffe;
        local_68 = 0;
        MONSTER_VertexBurnt(instance,&burntTest);
      }
      if (*(char *)(puVar2 + 0x55) != '\x03') {
        return;
      }
      if ((*(uint *)((int)pvVar1 + 0x10) & 2) == 0) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
                    /* WARNING: Subroutine does not return */
    memset(auStack64,0,8);
  }
  if (data->type == 0x20) {
    location = data;
    if (data->amount == 0) goto LAB_8008c1b8;
  }
  else {
    if (data->type != 0x10) {
      amount = MONSTER_CalcDamageIntensity
                         ((int)*(short *)(puVar2 + 0x50),(int)*(short *)((int)puVar2 + 0x142));
      amount = MONSTER_StartVertexBlood(instance,(_SVector *)data,amount);
      *(short *)(puVar2 + 0x52) = (short)amount;
      goto LAB_8008c1fc;
    }
LAB_8008c1b8:
    location = (evFXHitData *)&instance->position;
  }
  MONSTER_StartVertexBurnt(instance,(_SVector *)location,&burntTest);
LAB_8008c1fc:
  if ((int)data->amount != 0) {
    FX_Blood((_SVector *)data,&data->velocity,(_SVector *)&local_68,(int)data->amount,
             (long)&DAT_00180080,8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DefaultInit(struct _Instance *instance /*$s3*/)
 // line 3190, offset 0x8008c250
	/* begin block 1 */
		// Start line: 3191
		// Start offset: 0x8008C250
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s1
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _HModel *hModel; // $v0
	// 		struct _HPrim *hprim; // $v0
	// 		int i; // $a0
	// 		int state; // $a1
	/* end block 1 */
	// End offset: 0x8008C43C
	// End Line: 3261

	/* begin block 2 */
		// Start line: 6890
	/* end block 2 */
	// End Line: 6891

void MON_DefaultInit(_Instance *instance)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  _HModel *p_Var4;
  byte *pbVar5;
  undefined instance_00;
  undefined4 local_18;
  undefined4 local_14;
  void *pvVar6;
  uint *puVar7;
  
  instance_00 = SUB41(instance,0);
  puVar7 = (uint *)instance->extraData;
  pvVar6 = instance->data;
  if ((*puVar7 & 0x1000000) != 0) {
    MONAPI_CheckGenerator(instance);
  }
  iVar3 = MON_OnGround(instance);
  if (iVar3 != 0) {
    MONTABLE_GetDamageEffectFunc(instance_00);
    return;
  }
  *puVar7 = *puVar7 & 0xfffffffd;
  if (instance->hModelList != (_HModel *)0x0) {
    p_Var4 = instance->hModelList + instance->currentModel;
    iVar3 = p_Var4->numHPrims;
    if (iVar3 != 0) {
      pbVar5 = &p_Var4->hPrimList->withFlags;
      do {
        if (pbVar5[2] != 1) {
          *pbVar5 = *pbVar5 & 0xa5;
        }
        iVar3 = iVar3 + -1;
        pbVar5 = pbVar5 + 8;
      } while (iVar3 != 0);
    }
  }
  if (*(byte *)((int)pvVar6 + 0x1a) != 0) {
    G2Anim_AttachControllerToSeg(&instance->anim,(uint)*(byte *)((int)pvVar6 + 0x1a),0xe);
                    /* WARNING: Subroutine does not return */
    G2Anim_DisableController(&instance->anim,(uint)*(byte *)((int)pvVar6 + 0x1a),0xe);
  }
  bVar1 = *(byte *)((int)pvVar6 + 0x22);
  if ((bVar1 != 0) && ((uint)bVar1 != (uint)*(byte *)((int)pvVar6 + 0x1a))) {
    G2Anim_AttachControllerToSeg(&instance->anim,(uint)bVar1,0xe);
                    /* WARNING: Subroutine does not return */
    G2Anim_DisableController(&instance->anim,(uint)*(byte *)((int)pvVar6 + 0x22),0xe);
  }
  if (*(byte *)((int)pvVar6 + 0x25) != 0) {
    G2Anim_DisableSegment(&instance->anim,(uint)*(byte *)((int)pvVar6 + 0x25));
  }
  if ((instance->object->oflags & 0x80000U) == 0) {
    instance->fadeValue = 0x1000;
    MON_StartSpecialFade(instance,0,0x14);
  }
  if (((((instance->flags & 2U) == 0) && (cVar2 = *(char *)((int)puVar7 + 0x156), cVar2 != '\x04'))
      && (cVar2 != '\x10')) && (cVar2 == '\r')) {
    *(undefined2 *)(puVar7 + 0x54) = 0;
  }
                    /* WARNING: Subroutine does not return */
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CleanUp(struct _Instance *instance /*$s2*/)
 // line 3267, offset 0x8008c460
	/* begin block 1 */
		// Start line: 3268
		// Start offset: 0x8008C460
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s1
	/* end block 1 */
	// End offset: 0x8008C518
	// End Line: 3301

	/* begin block 2 */
		// Start line: 7058
	/* end block 2 */
	// End Line: 7059

void MON_CleanUp(_Instance *instance)

{
  byte bVar1;
  int slotID;
  void *pvVar2;
  void *pvVar3;
  
  pvVar2 = instance->extraData;
  pvVar3 = instance->data;
  MON_DropAllObjects(instance);
  slotID = (int)*(char *)((int)pvVar2 + 0x162);
  if (slotID != -1) {
    ENMYPLAN_ReleasePlanningWorkspace(slotID);
  }
  if (*(byte *)((int)pvVar3 + 0x1a) != 0) {
    G2Anim_DetachControllerFromSeg(&instance->anim,(uint)*(byte *)((int)pvVar3 + 0x1a),0xe);
  }
  bVar1 = *(byte *)((int)pvVar3 + 0x22);
  if ((bVar1 != 0) && ((uint)bVar1 != (uint)*(byte *)((int)pvVar3 + 0x1a))) {
    G2Anim_DetachControllerFromSeg(&instance->anim,(uint)bVar1,0xe);
  }
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(instance,1);
}





