#include "THISDUST.H"
#include "MONSENSE.H"


// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_FindHumanIR(struct _MonsterVars *mv /*$a0*/)
 // line 44, offset 0x80084994
	/* begin block 1 */
		// Start line: 45
		// Start offset: 0x80084994
		// Variables:
	// 		struct _MonsterIR *mir; // $s0
	/* end block 1 */
	// End offset: 0x800849D8
	// End Line: 52

	/* begin block 2 */
		// Start line: 88
	/* end block 2 */
	// End Line: 89

_MonsterIR * MONSENSE_FindHumanIR(_MonsterVars *mv)

{
  ulong uVar1;
  _MonsterIR *p_Var2;
  
  p_Var2 = mv->monsterIRList;
  while ((p_Var2 != (_MonsterIR *)0x0 &&
         (uVar1 = INSTANCE_Query(p_Var2->instance,1), (uVar1 & 8) == 0))) {
    p_Var2 = p_Var2->next;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_FindIR(struct _MonsterVars *mv /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 58, offset 0x800849e8
	/* begin block 1 */
		// Start line: 60
		// Start offset: 0x800849E8
		// Variables:
	// 		struct _MonsterIR *mir; // $v1
	/* end block 1 */
	// End offset: 0x80084A18
	// End Line: 66

	/* begin block 2 */
		// Start line: 117
	/* end block 2 */
	// End Line: 118

	/* begin block 3 */
		// Start line: 118
	/* end block 3 */
	// End Line: 119

	/* begin block 4 */
		// Start line: 120
	/* end block 4 */
	// End Line: 121

_MonsterIR * MONSENSE_FindIR(_MonsterVars *mv,_Instance *instance)

{
  _MonsterIR *p_Var1;
  
  p_Var1 = mv->monsterIRList;
  while ((p_Var1 != (_MonsterIR *)0x0 && (p_Var1->instance != instance))) {
    p_Var1 = p_Var1->next;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_See(struct _Instance *instance /*$s2*/, struct evCollideInstanceStatsData *data /*$s1*/)
 // line 91, offset 0x80084a20
	/* begin block 1 */
		// Start line: 92
		// Start offset: 0x80084A20
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _MonsterSenses *senses; // $s0

		/* begin block 1.1 */
			// Start line: 98
			// Start offset: 0x80084A64
			// Variables:
		// 		int arc; // $a1
		// 		int elevation; // $a2

			/* begin block 1.1.1 */
				// Start line: 108
				// Start offset: 0x80084AB4
				// Variables:
			// 		struct _Instance *target; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 112
					// Start offset: 0x80084ACC
					// Variables:
				// 		struct evPhysicsLOSData losData; // stack offset -40

					/* begin block 1.1.1.1.1 */
						// Start line: 116
						// Start offset: 0x80084ADC
						// Variables:
					// 		struct MATRIX *mat; // $v0
					/* end block 1.1.1.1.1 */
					// End offset: 0x80084ADC
					// End Line: 116

					/* begin block 1.1.1.1.2 */
						// Start line: 122
						// Start offset: 0x80084B18
						// Variables:
					// 		short _x1; // $v1
					// 		short _y1; // $a0
					// 		short _z1; // $a1
					// 		struct _Position *_v0; // $v0
					// 		struct _Position *_v1; // $v0
					/* end block 1.1.1.1.2 */
					// End offset: 0x80084B34
					// End Line: 122

					/* begin block 1.1.1.1.3 */
						// Start line: 126
						// Start offset: 0x80084B44
						// Variables:
					// 		struct MATRIX *mat; // $v1
					/* end block 1.1.1.1.3 */
					// End offset: 0x80084B44
					// End Line: 126

					/* begin block 1.1.1.1.4 */
						// Start line: 132
						// Start offset: 0x80084B68
						// Variables:
					// 		short _x1; // $v1
					// 		short _y1; // $a0
					// 		short _z1; // $a1
					// 		struct _Position *_v0; // $v0
					// 		struct _Position *_v1; // $v0
					/* end block 1.1.1.1.4 */
					// End offset: 0x80084B88
					// End Line: 132
				/* end block 1.1.1.1 */
				// End offset: 0x80084BA0
				// End Line: 135
			/* end block 1.1.1 */
			// End offset: 0x80084BA0
			// End Line: 138
		/* end block 1.1 */
		// End offset: 0x80084BA0
		// End Line: 139
	/* end block 1 */
	// End offset: 0x80084BA4
	// End Line: 142

	/* begin block 2 */
		// Start line: 170
	/* end block 2 */
	// End Line: 171

int MONSENSE_See(_Instance *instance,evCollideInstanceStatsData *data)

{
  short sVar1;
  int arc;
  ulong uVar2;
  MATRIX *pMVar3;
  int elevation;
  short *psVar4;
  _Instance *Inst;
  short local_28;
  short local_26;
  short local_24;
  short local_20;
  short local_1e;
  short local_1c;
  
  psVar4 = *(short **)(*(int *)((int)instance->extraData + 0x164) + 4);
  arc = 0;
  if (data->distance < (uint)(int)psVar4[1]) {
    sVar1 = MATH3D_FastAtan2(500,data->distance);
    elevation = (int)sVar1;
    arc = elevation;
    if (elevation < (int)*psVar4) {
      arc = (int)*psVar4;
    }
    if (elevation < (int)psVar4[2]) {
      elevation = (int)psVar4[2];
    }
    arc = MATH3D_ConeDetect(&data->relativePosition,arc,elevation);
    if (arc == 0) {
      arc = 0;
    }
    else {
      Inst = data->instance;
      uVar2 = INSTANCE_Query(Inst,1);
      arc = 1;
      if ((uVar2 & 1) != 0) {
        if (instance->matrix == (MATRIX *)0x0) {
          local_20 = (instance->position).x;
          local_1e = (instance->position).y;
          local_1c = (instance->position).z;
        }
        else {
          pMVar3 = instance->matrix + *(byte *)((int)instance->data + 0x19);
          local_20 = *(short *)pMVar3->t;
          local_1e = *(short *)(pMVar3->t + 1);
          local_1c = *(short *)(pMVar3->t + 2);
        }
        pMVar3 = Inst->matrix;
        if (pMVar3 == (MATRIX *)0x0) {
          local_28 = (Inst->position).x;
          local_26 = (Inst->position).y;
          local_24 = (Inst->position).z;
        }
        else {
          local_28 = *(short *)pMVar3[1].t;
          local_26 = *(short *)(pMVar3[1].t + 1);
          local_24 = *(short *)(pMVar3[1].t + 2);
        }
        arc = PhysicsCheckLOS(instance,(int)&local_28,4);
      }
    }
  }
  return arc;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_Hear(struct _Instance *instance /*$a0*/, struct evCollideInstanceStatsData *data /*$s1*/)
 // line 147, offset 0x80084bbc
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x80084BBC
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _MonsterSenses *senses; // $s0
	// 		long mode; // $a0
	/* end block 1 */
	// End offset: 0x80084C38
	// End Line: 165

	/* begin block 2 */
		// Start line: 273
	/* end block 2 */
	// End Line: 274

int MONSENSE_Hear(_Instance *instance,evCollideInstanceStatsData *data)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)((int)instance->extraData + 0x164) + 4);
  uVar1 = INSTANCE_Query(data->instance,10);
  if ((((uVar1 & 0x10b0143) == 0) || (iVar2 = 0, (uVar1 & 0x200000) != 0)) &&
     (iVar2 = 0, data->distance < (uint)(int)*(short *)(iVar3 + 8))) {
    iVar2 = MATH3D_ConeDetect(&data->relativePosition,(int)*(short *)(iVar3 + 6),
                              (int)*(short *)(iVar3 + 10));
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_Smell(struct _Instance *instance /*$a0*/, struct evCollideInstanceStatsData *data /*$a1*/)
 // line 170, offset 0x80084c4c
	/* begin block 1 */
		// Start line: 172
		// Start offset: 0x80084C4C
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x80084C4C
	// End Line: 172

	/* begin block 2 */
		// Start line: 322
	/* end block 2 */
	// End Line: 323

	/* begin block 3 */
		// Start line: 323
	/* end block 3 */
	// End Line: 324

int MONSENSE_Smell(_Instance *instance,evCollideInstanceStatsData *data)

{
  return (uint)(data->distance <
               (uint)*(ushort *)(*(int *)(*(int *)((int)instance->extraData + 0x164) + 4) + 0xc));
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_DetectPlayer(struct _Instance *instance /*$a0*/)
 // line 183, offset 0x80084c74
	/* begin block 1 */
		// Start line: 184
		// Start offset: 0x80084C74
	/* end block 1 */
	// End offset: 0x80084C74
	// End Line: 184

	/* begin block 2 */
		// Start line: 348
	/* end block 2 */
	// End Line: 349

int MONSENSE_DetectPlayer(_Instance *instance)

{
  _MonsterIR *p_Var1;
  
  p_Var1 = MONSENSE_FindIR((_MonsterVars *)instance->extraData,gameTrackerX.playerInstance);
  return (uint)(p_Var1 != (_MonsterIR *)0x0);
}



// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_FirstSense(struct _Instance *instance /*$s2*/, struct _Instance *sensed /*$s4*/)
 // line 193, offset 0x80084c9c
	/* begin block 1 */
		// Start line: 194
		// Start offset: 0x80084C9C
		// Variables:
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 201
			// Start offset: 0x80084CD8
			// Variables:
		// 		long whatAmI; // $s2
		// 		struct _MonsterAllegiances *allegiances; // $s3
		/* end block 1.1 */
		// End offset: 0x80084DF8
		// End Line: 231
	/* end block 1 */
	// End offset: 0x80084DF8
	// End Line: 233

	/* begin block 2 */
		// Start line: 372
	/* end block 2 */
	// End Line: 373

_MonsterIR * MONSENSE_FirstSense(_Instance *instance,_Instance *sensed)

{
  ushort uVar1;
  _MonsterIR *p_Var2;
  ulong uVar3;
  ulong uVar4;
  _MonsterVars *mv;
  _MonsterAllegiances *p_Var5;
  
  mv = (_MonsterVars *)instance->extraData;
  p_Var2 = MONSENSE_GetMonsterIR(mv);
  if (p_Var2 != (_MonsterIR *)0x0) {
    uVar3 = INSTANCE_Query(sensed,1);
    p_Var5 = mv->subAttr->allegiances;
    p_Var2->mirFlags = 0x100;
    p_Var2->instance = sensed;
    p_Var2->handle = sensed->instanceID;
    uVar4 = MON_GetTime(instance);
    p_Var2->forgetTimer = uVar4 + (int)mv->subAttr->forgetTime * 1000;
    p_Var2->next = mv->monsterIRList;
    mv->monsterIRList = p_Var2;
    p_Var2->mirConditions = 0;
    if ((uVar3 & p_Var5->enemies) != 0) {
      p_Var2->mirFlags = p_Var2->mirFlags | 1;
    }
    if ((uVar3 & p_Var5->allies) != 0) {
      uVar1 = p_Var2->mirFlags;
      p_Var2->mirFlags = uVar1 | 2;
      if ((*(uint *)sensed->extraData & 0x100000) != 0) {
        p_Var2->mirFlags = uVar1 | 0x12;
      }
    }
    if ((uVar3 & p_Var5->food) != 0) {
      p_Var2->mirFlags = p_Var2->mirFlags | 9;
    }
    if ((uVar3 & p_Var5->gods) != 0) {
      p_Var2->mirFlags = p_Var2->mirFlags | 4;
    }
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_SetupMIR(struct _Instance *instance /*$s4*/, struct evCollideInstanceStatsData *data /*$s1*/, int flags /*$s2*/)
 // line 240, offset 0x80084e1c
	/* begin block 1 */
		// Start line: 241
		// Start offset: 0x80084E1C
		// Variables:
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterVars *mv; // $s3

		/* begin block 1.1 */
			// Start line: 260
			// Start offset: 0x80084EC0
			// Variables:
		// 		long mode; // $s1

			/* begin block 1.1.1 */
				// Start line: 263
				// Start offset: 0x80084EC0
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			// 		struct _SVector *_v0; // $v0
			// 		struct _SVector *_v1; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80084EC0
			// End Line: 263

			/* begin block 1.1.2 */
				// Start line: 307
				// Start offset: 0x800850C0
			/* end block 1.1.2 */
			// End offset: 0x80085104
			// End Line: 310
		/* end block 1.1 */
		// End offset: 0x80085208
		// End Line: 339
	/* end block 1 */
	// End offset: 0x80085208
	// End Line: 340

	/* begin block 2 */
		// Start line: 480
	/* end block 2 */
	// End Line: 481

void MONSENSE_SetupMIR(_Instance *instance,evCollideInstanceStatsData *data,int flags)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  _MonsterIR *p_Var5;
  _MonsterCombatAttributes *p_Var6;
  ulong uVar7;
  ushort uVar8;
  _MonsterVars *mv;
  
  mv = (_MonsterVars *)instance->extraData;
  p_Var5 = MONSENSE_FindIR(mv,data->instance);
  if (p_Var5 == (_MonsterIR *)0x0) {
    if (flags != 0) {
      p_Var5 = MONSENSE_FirstSense(instance,data->instance);
    }
  }
  else {
    if (flags != 0) {
      uVar7 = MON_GetTime(instance);
      p_Var5->forgetTimer = uVar7 + (int)mv->subAttr->forgetTime * 1000;
    }
  }
  if (p_Var5 == (_MonsterIR *)0x0) {
    return;
  }
  p_Var5->mirFlags = p_Var5->mirFlags | (ushort)flags;
  p_Var5->distance = *(short *)&data->distance;
  sVar4 = (data->relativePosition).y;
  sVar1 = (data->relativePosition).z;
  (p_Var5->relativePosition).x = (data->relativePosition).x;
  (p_Var5->relativePosition).y = sVar4;
  (p_Var5->relativePosition).z = sVar1;
  p_Var6 = mv->subAttr->combatAttributes;
  if ((p_Var6 == (_MonsterCombatAttributes *)0x0) || (p_Var6->combatRange <= p_Var5->distance)) {
    uVar3 = p_Var5->mirConditions & 0xfff7;
  }
  else {
    uVar3 = p_Var5->mirConditions | 8;
  }
  p_Var5->mirConditions = uVar3;
  sVar4 = MATH3D_AngleFromPosToPos(&p_Var5->instance->position,&instance->position);
  if (((sVar4 - (p_Var5->instance->rotation).z) + 0x400U & 0xfff) < 0x801) {
    uVar3 = p_Var5->mirConditions & 0xfffd;
  }
  else {
    uVar3 = p_Var5->mirConditions | 2;
  }
  p_Var5->mirConditions = uVar3;
  if ((mv->mvFlags & 0x8000000) == 0) {
    uVar3 = p_Var5->mirConditions & 0xfffe;
  }
  else {
    uVar3 = p_Var5->mirConditions | 1;
  }
  p_Var5->mirConditions = uVar3;
  uVar7 = INSTANCE_Query(p_Var5->instance,10);
  if ((uVar7 & 0x208000) == 0x208000) {
    uVar7 = uVar7 & 0xffdfffff;
  }
  uVar3 = p_Var5->mirFlags;
  if ((uVar3 & 0x400) == 0) {
    if (((uVar7 & 0x200000) != 0) &&
       (mv->subAttr->combatAttributes != (_MonsterCombatAttributes *)0x0)) {
      p_Var5->mirConditions = p_Var5->mirConditions & 0xff1b;
      p_Var5->mirFlags = p_Var5->mirFlags | 0x400;
      if (((int)p_Var5->distance < ((int)mv->subAttr->combatAttributes->enemyAttackRange * 3) / 2)
         && (sVar4 = MATH3D_AngleFromPosToPos(&p_Var5->instance->position,&instance->position),
            ((sVar4 - (p_Var5->instance->rotation).z) + 0x200U & 0xfff) < 0x800)) {
        p_Var5->mirConditions = p_Var5->mirConditions | 0x800;
      }
    }
  }
  else {
    if ((uVar7 & 0x200000) != 0) goto LAB_80085110;
    uVar2 = p_Var5->mirConditions;
    p_Var5->mirFlags = uVar3 & 0xfbff;
    uVar8 = uVar2 & 0xf7ff;
    p_Var5->mirConditions = uVar8;
    if (((uVar3 & 1) != 0) && ((uVar2 & 0x400) == 0)) {
      p_Var5->mirConditions = uVar8 | 4;
    }
  }
  uVar3 = p_Var5->mirFlags;
LAB_80085110:
  if ((uVar3 & 0x800) == 0) {
    if (uVar7 == 1) {
      p_Var5->mirFlags = uVar3 | 0x800;
      uVar7 = MON_GetTime(instance);
      p_Var5->idleTime = uVar7 + 0x1356;
    }
  }
  else {
    if (uVar7 == 1) {
      if (((p_Var5->mirConditions & 0x10) == 0) &&
         (uVar7 = MON_GetTime(instance), p_Var5->idleTime < uVar7)) {
        p_Var5->mirConditions = p_Var5->mirConditions | 0x10;
      }
    }
    else {
      p_Var5->mirFlags = uVar3 & 0xf7ff;
      p_Var5->mirConditions = p_Var5->mirConditions & 0xffef;
    }
  }
  uVar3 = p_Var5->mirFlags;
  if ((uVar3 & 0x200) == 0) {
    if (((uVar3 & 2) != 0) && (p_Var5->distance < mv->subAttr->combatAttributes->allyRange)) {
      p_Var5->mirFlags = uVar3 | 0x200;
    }
  }
  else {
    if ((int)mv->subAttr->combatAttributes->allyRange + 300 < (int)p_Var5->distance) {
      p_Var5->mirFlags = uVar3 & 0xfdff;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_SenseInstance(struct _Instance *instance /*$s3*/, struct evCollideInstanceStatsData *data /*$s2*/)
 // line 346, offset 0x80085228
	/* begin block 1 */
		// Start line: 347
		// Start offset: 0x80085228
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long flags; // $s0
	// 		unsigned long whatAmI; // $s4

		/* begin block 1.1 */
			// Start line: 359
			// Start offset: 0x80085280
			// Variables:
		// 		struct PhysObProperties *prop; // $s0

			/* begin block 1.1.1 */
				// Start line: 362
				// Start offset: 0x800852A0
			/* end block 1.1.1 */
			// End offset: 0x80085340
			// End Line: 373
		/* end block 1.1 */
		// End offset: 0x80085340
		// End Line: 373
	/* end block 1 */
	// End offset: 0x800853FC
	// End Line: 391

	/* begin block 2 */
		// Start line: 697
	/* end block 2 */
	// End Line: 698

void MONSENSE_SenseInstance(_Instance *instance,evCollideInstanceStatsData *data)

{
  ulong uVar1;
  int iVar2;
  uint flags;
  void *pvVar3;
  uint *puVar4;
  
  flags = 0;
  puVar4 = (uint *)instance->extraData;
  uVar1 = INSTANCE_Query(data->instance,1);
  if ((*puVar4 & 0x200) == 0) {
    if ((uVar1 & 0x20) == 0) {
      if (*(char *)((int)puVar4 + 0x15e) == '\0') {
        iVar2 = MONSENSE_Smell(instance,data);
        if (iVar2 != 0) {
          flags = 0x80;
        }
        iVar2 = MONSENSE_See(instance,data);
        if (iVar2 != 0) {
          flags = flags | 0x20;
        }
        iVar2 = MONSENSE_Hear(instance,data);
        if (iVar2 != 0) {
          flags = flags | 0x40;
        }
        if (((uVar1 & *(uint *)(*(int *)(puVar4[0x59] + 0xc) + 4)) != 0) &&
           (data->distance < (uint)*(ushort *)(*(int *)(puVar4[0x59] + 4) + 0x10))) {
          flags = flags | 2;
        }
        MONSENSE_SetupMIR(instance,data,flags);
      }
    }
    else {
      pvVar3 = data->instance->data;
      if ((((*(short *)((int)pvVar3 + 2) == 3) &&
           (data->xyDistance < (int)(uint)*(ushort *)((int)pvVar3 + 0x1e))) &&
          (data->zDelta < (int)*(short *)((int)pvVar3 + 0x22))) &&
         ((int)*(short *)((int)pvVar3 + 0x20) < data->zDelta)) {
        if ((*(ushort *)((int)pvVar3 + 8) & 0x40) != 0) {
          INSTANCE_Post(instance,0x100000c,0x20);
        }
        if ((*(ushort *)((int)pvVar3 + 8) & 8) != 0) {
          INSTANCE_Post(instance,0x100000c,0x40);
        }
        if ((*(ushort *)((int)pvVar3 + 8) & 0x10) != 0) {
          INSTANCE_Post(instance,0x100000c,0x10);
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_StartMonsterIRList(struct _Instance *instance /*$s5*/)
 // line 396, offset 0x8008541c
	/* begin block 1 */
		// Start line: 397
		// Start offset: 0x8008541C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterIR *newlist; // $s2
	// 		int enemyOnList; // $s4

		/* begin block 1.1 */
			// Start line: 412
			// Start offset: 0x8008549C
			// Variables:
		// 		struct _MonsterIR *next; // $s3
		/* end block 1.1 */
		// End offset: 0x80085524
		// End Line: 440
	/* end block 1 */
	// End offset: 0x80085540
	// End Line: 448

	/* begin block 2 */
		// Start line: 801
	/* end block 2 */
	// End Line: 802

void MONSENSE_StartMonsterIRList(_Instance *instance)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  ulong uVar5;
  void *pvVar6;
  undefined4 *puVar7;
  
  pvVar6 = instance->extraData;
  cVar4 = *(char *)((int)pvVar6 + 0x15e) + -1;
  *(char *)((int)pvVar6 + 0x15e) = cVar4;
  bVar1 = false;
  if (cVar4 < '\0') {
    *(char *)((int)pvVar6 + 0x15e) = ('\x05' - *(char *)((int)pvVar6 + 0x15d)) * '\x04' + '\x01';
  }
  else {
    if (cVar4 == '\0') {
      puVar2 = (undefined4 *)0;
      puVar7 = *(undefined4 **)((int)pvVar6 + 0x90);
      while (puVar3 = puVar7, puVar3 != (undefined4 *)0x0) {
        puVar7 = (undefined4 *)*puVar3;
        if ((puVar3[2] == *(int *)(puVar3[1] + 0x10)) &&
           (((*(ushort *)((int)puVar3 + 0x16) & 0xe0) != 0 ||
            (uVar5 = MON_GetTime(instance), uVar5 <= (uint)puVar3[7])))) {
          *(undefined4 **)puVar3 = puVar2;
          *(ushort *)((int)puVar3 + 0x16) = *(ushort *)((int)puVar3 + 0x16) & 0xff1f;
          puVar2 = puVar3;
          if (*(undefined4 **)((int)pvVar6 + 0xc4) == puVar3) {
            bVar1 = true;
          }
        }
        else {
          *puVar3 = *(undefined4 *)((int)pvVar6 + 0x168);
          *(undefined4 **)((int)pvVar6 + 0x168) = puVar3;
        }
      }
      if (!bVar1) {
        *(undefined4 *)((int)pvVar6 + 0xc4) = 0;
      }
      *(undefined4 **)((int)pvVar6 + 0x90) = puVar2;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_GetMonsterIR(struct _MonsterVars *mv /*$a0*/)
 // line 453, offset 0x80085564
	/* begin block 1 */
		// Start line: 455
		// Start offset: 0x80085564
		// Variables:
	// 		struct _MonsterIR *mir; // $v1
	/* end block 1 */
	// End offset: 0x80085584
	// End Line: 465

	/* begin block 2 */
		// Start line: 947
	/* end block 2 */
	// End Line: 948

	/* begin block 3 */
		// Start line: 948
	/* end block 3 */
	// End Line: 949

	/* begin block 4 */
		// Start line: 950
	/* end block 4 */
	// End Line: 951

_MonsterIR * MONSENSE_GetMonsterIR(_MonsterVars *mv)

{
  _MonsterIR *p_Var1;
  
  p_Var1 = mv->freeIRs;
  if (p_Var1 == (_MonsterIR *)0x0) {
    p_Var1 = (_MonsterIR *)0x0;
  }
  else {
    mv->freeIRs = p_Var1->next;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_InitIRList(struct _MonsterVars *mv /*$a0*/, struct _MonsterIR *list /*$a1*/, int num /*$a2*/)
 // line 471, offset 0x8008558c
	/* begin block 1 */
		// Start line: 473
		// Start offset: 0x8008558C
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x800855AC
	// End Line: 482

	/* begin block 2 */
		// Start line: 983
	/* end block 2 */
	// End Line: 984

	/* begin block 3 */
		// Start line: 984
	/* end block 3 */
	// End Line: 985

	/* begin block 4 */
		// Start line: 988
	/* end block 4 */
	// End Line: 989

void MONSENSE_InitIRList(_MonsterVars *mv,_MonsterIR *list,int num)

{
  num = num + -1;
  mv->freeIRs = list;
  while (num != 0) {
    list->next = list + 1;
    num = num + -1;
    list = list + 1;
  }
  list->next = (_MonsterIR *)0x0;
  mv->monsterIRList = (_MonsterIR *)0x0;
  return;
}



// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_SetEnemy(struct _Instance *instance /*$s0*/, struct _Instance *newenemy /*$s1*/)
 // line 489, offset 0x800855b8
	/* begin block 1 */
		// Start line: 490
		// Start offset: 0x800855B8
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterIR *mir; // $a1

		/* begin block 1.1 */
			// Start line: 500
			// Start offset: 0x80085600
			// Variables:
		// 		long angle; // $v0
		/* end block 1.1 */
		// End offset: 0x8008565C
		// End Line: 506
	/* end block 1 */
	// End offset: 0x80085680
	// End Line: 516

	/* begin block 2 */
		// Start line: 1021
	/* end block 2 */
	// End Line: 1022

_MonsterIR * MONSENSE_SetEnemy(_Instance *instance,_Instance *newenemy)

{
  short sVar1;
  _MonsterIR *p_Var2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  _MonsterVars *mv;
  
  mv = (_MonsterVars *)instance->extraData;
  p_Var2 = MONSENSE_FindIR(mv,newenemy);
  if (p_Var2 == (_MonsterIR *)0x0) {
    p_Var2 = MONSENSE_FirstSense(instance,newenemy);
    if (p_Var2 == (_MonsterIR *)0x0) goto LAB_8008566c;
    uVar5 = (uint)(ushort)(instance->rotation).z & 0xfff;
    if (0x800 < uVar5) {
      uVar5 = uVar5 - 0x1000;
    }
    uVar4 = (uint)(ushort)(newenemy->rotation).z & 0xfff;
    iVar3 = uVar5 - uVar4;
    if (0x800 < uVar4) {
      iVar3 = (uVar5 + 0x1000) - uVar4;
    }
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    sVar1 = 100;
    if (0x3ff < iVar3) {
      sVar1 = -100;
    }
    (p_Var2->relativePosition).y = sVar1;
  }
  p_Var2->mirFlags = p_Var2->mirFlags | 1;
LAB_8008566c:
  if (mv->enemy == (_MonsterIR *)0x0) {
    mv->enemy = p_Var2;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_ProcessIRList(struct _Instance *instance /*$s7*/)
 // line 522, offset 0x8008569c
	/* begin block 1 */
		// Start line: 523
		// Start offset: 0x8008569C
		// Variables:
	// 		struct _MonsterVars *mv; // $s4
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterIR *closestEnemy; // $s1
	// 		struct _MonsterIR *closestLeader; // $s2
	// 		struct _MonsterIR *closestAlly; // $s3
	// 		struct _MonsterIR *player; // $s6
	// 		struct _MonsterCombatAttributes *combatAttr; // $s5
	/* end block 1 */
	// End offset: 0x80085870
	// End Line: 580

	/* begin block 2 */
		// Start line: 1088
	/* end block 2 */
	// End Line: 1089

void MONSENSE_ProcessIRList(_Instance *instance)

{
  ulong uVar1;
  int Message;
  int *Data;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  
  piVar2 = (int *)0x0;
  piVar3 = (int *)0x0;
  piVar4 = (int *)0x0;
  pvVar5 = instance->extraData;
  Data = *(int **)((int)pvVar5 + 0x90);
  iVar6 = *(int *)(*(int *)((int)pvVar5 + 0x164) + 8);
  piVar7 = (int *)0x0;
  while (Data != (int *)0x0) {
    if (((_Instance *)Data[1])->instanceID == Data[2]) {
      if ((*(ushort *)((int)Data + 0x16) & 1) != 0) {
        uVar1 = INSTANCE_Query((_Instance *)Data[1],1);
        if ((uVar1 & 1) != 0) {
          piVar7 = Data;
        }
        if ((piVar2 == (int *)0x0) || (*(short *)(Data + 5) < *(short *)((int)piVar2 + 0x14))) {
          piVar2 = Data;
        }
        if ((*(ushort *)((int)Data + 0x16) & 0x100) != 0) {
          if ((iVar6 == 0) || (*(short *)(iVar6 + 0xc) <= *(short *)(Data + 5))) {
            Message = 0x1000012;
          }
          else {
            Message = 0x100000e;
          }
          INSTANCE_Post(instance,Message,(int)Data);
        }
      }
      if (((*(ushort *)((int)Data + 0x16) & 0x10) != 0) &&
         ((piVar3 == (int *)0x0 || (*(short *)(Data + 5) < *(short *)((int)piVar3 + 0x14))))) {
        piVar3 = Data;
      }
      if (((*(ushort *)((int)Data + 0x16) & 2) != 0) &&
         ((piVar4 == (int *)0x0 || (*(short *)(Data + 5) < *(short *)((int)piVar4 + 0x14))))) {
        piVar4 = Data;
      }
      *(ushort *)((int)Data + 0x16) = *(ushort *)((int)Data + 0x16) & 0xfeff;
    }
    Data = (int *)*Data;
  }
  if ((piVar7 == (int *)0x0) ||
     (((iVar6 != 0 && (*(char *)(iVar6 + 0x16) != '\0')) && (*(short *)((int)pvVar5 + 0x140) == 0)))
     ) {
    *(int **)((int)pvVar5 + 0xc4) = piVar2;
  }
  else {
    *(int **)((int)pvVar5 + 0xc4) = piVar7;
  }
  *(int **)((int)pvVar5 + 200) = piVar3;
  *(int **)((int)pvVar5 + 0xcc) = piVar4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_SetupSenses(struct _Instance *instance /*$s2*/)
 // line 598, offset 0x800858a4
	/* begin block 1 */
		// Start line: 599
		// Start offset: 0x800858A4
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAllegiances *allegiances; // $s0
	/* end block 1 */
	// End offset: 0x80085914
	// End Line: 618

	/* begin block 2 */
		// Start line: 1193
	/* end block 2 */
	// End Line: 1194

void MONSENSE_SetupSenses(_Instance *instance)

{
  int iVar1;
  _MonsterAllegiances *p_Var2;
  _MonsterVars *mv;
  
  mv = (_MonsterVars *)instance->extraData;
  p_Var2 = mv->subAttr->allegiances;
  MONSENSE_InitIRList(mv,(_MonsterIR *)(mv + 1),5);
  instance->flags2 = instance->flags2 | 0x400;
  if (p_Var2 != (_MonsterAllegiances *)0x0) {
    instance->checkMask = p_Var2->enemies | p_Var2->allies | p_Var2->food | p_Var2->gods;
  }
  instance->maxCheckDistance = 12000;
  instance->checkMask = instance->checkMask | 0xb;
  mv->alertCount = (char)gNumMonsters;
  iVar1 = gNumMonsters;
  mv->enemy = (_MonsterIR *)0x0;
  mv->leader = (_MonsterIR *)0x0;
  (&monsterSenseArray20)[iVar1] = mv;
  mv->senseIndex = (char)gNumMonsters;
  gNumMonsters = gNumMonsters + 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_RemoveSenses(struct _Instance *instance /*$a0*/)
 // line 646, offset 0x8008597c
	/* begin block 1 */
		// Start line: 648
		// Start offset: 0x8008597C
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x800859D8
	// End Line: 659

	/* begin block 2 */
		// Start line: 1403
	/* end block 2 */
	// End Line: 1404

	/* begin block 3 */
		// Start line: 1404
	/* end block 3 */
	// End Line: 1405

	/* begin block 4 */
		// Start line: 1408
	/* end block 4 */
	// End Line: 1409

void MONSENSE_RemoveSenses(_Instance *instance)

{
  int iVar1;
  int iVar2;
  
  gNumMonsters = gNumMonsters + -1;
  iVar2 = (int)*(char *)((int)instance->extraData + 0x15f);
  if (iVar2 < gNumMonsters) {
    do {
      iVar1 = iVar2 + 1;
      (&monsterSenseArray20)[iVar2] = (&monsterSenseArray20)[iVar1];
      (&monsterSenseArray20)[iVar1]->senseIndex = (char)iVar2;
      iVar2 = iVar1;
    } while (iVar1 < gNumMonsters);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_Radar(struct _Instance *instance /*$s0*/)
 // line 763, offset 0x800859e0
	/* begin block 1 */
		// Start line: 764
		// Start offset: 0x800859E0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 768
			// Start offset: 0x80085A30
			// Variables:
		// 		struct SVECTOR newPos; // stack offset -96
		// 		struct SVECTOR oldPos; // stack offset -88
		// 		struct _PCollideInfo pCollideInfo; // stack offset -80
		// 		int index; // $s3
		/* end block 1.1 */
		// End offset: 0x80085BC8
		// End Line: 805
	/* end block 1 */
	// End offset: 0x80085BC8
	// End Line: 828

	/* begin block 2 */
		// Start line: 1644
	/* end block 2 */
	// End Line: 1645

	/* begin block 3 */
		// Start line: 1646
	/* end block 3 */
	// End Line: 1647

void MONSENSE_Radar(_Instance *instance)

{
  undefined2 uVar1;
  long lVar2;
  void *pvVar3;
  uint uVar4;
  SVECTOR local_60;
  SVECTOR local_58;
  _PCollideInfo local_50;
  
  pvVar3 = instance->extraData;
  if ((int)*(char *)((int)pvVar3 + 0x15f) != (int)gameTrackerX.frameCount % gNumMonsters) {
    return;
  }
  uVar4 = (uint)""[*(int *)((int)pvVar3 + 0xe4)];
  local_60.vx = (instance->position).x + (&radarDir)[uVar4].x;
  local_60.vy = (instance->position).y + (&radarDir)[uVar4].y;
  local_60.vz = (instance->position).z + 100;
  local_58.vx = (instance->position).x;
  local_58.vy = (instance->position).y;
  local_50.newPoint = &local_60;
  local_50.oldPoint = &local_58;
  local_58.vz = (instance->position).z + 100;
  PHYSICS_CheckLineInWorld(instance,&local_50);
  if (local_50.type == 0) {
    local_58.vx = (instance->position).x + (&radarDir)[uVar4].x;
    local_58.vy = (instance->position).y + (&radarDir)[uVar4].y;
    local_58.vz = (instance->position).z + -0x100;
    local_60.vx = (instance->position).x;
    local_60.vy = (instance->position).y;
    local_60.vz = (instance->position).z + -0x100;
    PHYSICS_CheckLineInWorld(instance,&local_50);
    if (local_50.type == 0) {
      *(uint *)((int)pvVar3 + 0xe0) = *(uint *)((int)pvVar3 + 0xe0) | 1 << (uVar4 & 0x1f);
      uVar1 = 0x500;
      goto LAB_80085ba4;
    }
  }
  *(uint *)((int)pvVar3 + 0xe0) = *(uint *)((int)pvVar3 + 0xe0) & ~(1 << (uVar4 & 0x1f));
  lVar2 = MATH3D_LengthXY((int)local_60.vx - (int)(instance->position).x,
                          (int)local_60.vy - (int)(instance->position).y);
  uVar1 = (undefined2)lVar2;
LAB_80085ba4:
  *(undefined2 *)((int)pvVar3 + uVar4 * 2 + 0xe8) = uVar1;
  uVar4 = *(int *)((int)pvVar3 + 0xe4) + 1;
  *(uint *)((int)pvVar3 + 0xe4) = uVar4;
  if (0xf < uVar4) {
    *(undefined4 *)((int)pvVar3 + 0xe4) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MONSENSE_GetClosestFreeDirection(struct _Instance *instance /*$a0*/, short angle /*$a3*/, long range /*$a2*/)
 // line 833, offset 0x80085bec
	/* begin block 1 */
		// Start line: 834
		// Start offset: 0x80085BEC
		// Variables:
	// 		struct _MonsterVars *mv; // $t0
	// 		int bit; // $a1
	// 		int search; // $a0
	/* end block 1 */
	// End offset: 0x80085C94
	// End Line: 863

	/* begin block 2 */
		// Start line: 1795
	/* end block 2 */
	// End Line: 1796

/* WARNING: Removing unreachable block (ram,0x80085c0c) */

short MONSENSE_GetClosestFreeDirection(_Instance *instance,short angle,long range)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (int)((int)angle + 0x80U & 0xfff) >> 8;
  sVar1 = *(short *)((int)instance->extraData + uVar3 * 2 + 0xe8);
  iVar2 = 1;
  while( true ) {
    if (range <= sVar1) {
      return angle;
    }
    if (iVar2 < 1) {
      uVar3 = uVar3 + iVar2 * 2;
      iVar2 = 1 - iVar2;
    }
    else {
      uVar3 = (uVar3 - 1) + iVar2 * 2;
      iVar2 = -iVar2;
    }
    uVar3 = uVar3 & 0xf;
    if (7 < iVar2) break;
    sVar1 = *(short *)((int)instance->extraData + uVar3 * 2 + 0xe8);
    angle = (&radarDir)[uVar3].angle;
  }
  return angle;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_GetDistanceInDirection(struct _Instance *instance /*$a0*/, short angle /*$a1*/)
 // line 869, offset 0x80085ca0
	/* begin block 1 */
		// Start line: 871
		// Start offset: 0x80085CA0
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int bit; // $v0
	/* end block 1 */
	// End offset: 0x80085CC0
	// End Line: 872

	/* begin block 2 */
		// Start line: 1872
	/* end block 2 */
	// End Line: 1873

	/* begin block 3 */
		// Start line: 1873
	/* end block 3 */
	// End Line: 1874

	/* begin block 4 */
		// Start line: 1874
	/* end block 4 */
	// End Line: 1875

/* WARNING: Removing unreachable block (ram,0x80085cbc) */

int MONSENSE_GetDistanceInDirection(_Instance *instance,short angle)

{
  return (int)*(short *)((int)instance->extraData +
                        ((int)((int)angle + 0x80U & 0xfff) >> 8) * 2 + 0xe8);
}





