#include "THISDUST.H"
#include "MONSENSE.H"


// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_FindIR(struct _MonsterVars *mv /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 62, offset 0x800856cc
	/* begin block 1 */
		// Start line: 64
		// Start offset: 0x800856CC
		// Variables:
	// 		struct _MonsterIR *mir; // $v1
	/* end block 1 */
	// End offset: 0x800856FC
	// End Line: 70

	/* begin block 2 */
		// Start line: 110
	/* end block 2 */
	// End Line: 111

	/* begin block 3 */
		// Start line: 118
	/* end block 3 */
	// End Line: 119

	/* begin block 4 */
		// Start line: 111
	/* end block 4 */
	// End Line: 112

	/* begin block 5 */
		// Start line: 113
	/* end block 5 */
	// End Line: 114

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
 // line 95, offset 0x80085704
	/* begin block 1 */
		// Start line: 96
		// Start offset: 0x80085704
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _MonsterSenses *senses; // $s0

		/* begin block 1.1 */
			// Start line: 102
			// Start offset: 0x80085748
			// Variables:
		// 		int arc; // $a1
		// 		int elevation; // $a2

			/* begin block 1.1.1 */
				// Start line: 112
				// Start offset: 0x80085798
				// Variables:
			// 		struct _Instance *target; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 116
					// Start offset: 0x800857B0
					// Variables:
				// 		struct evPhysicsLOSData losData; // stack offset -40

					/* begin block 1.1.1.1.1 */
						// Start line: 120
						// Start offset: 0x800857C0
						// Variables:
					// 		struct MATRIX *mat; // $v0
					/* end block 1.1.1.1.1 */
					// End offset: 0x800857C0
					// End Line: 120

					/* begin block 1.1.1.1.2 */
						// Start line: 126
						// Start offset: 0x800857FC
						// Variables:
					// 		short _x1; // $v1
					// 		short _y1; // $a0
					// 		short _z1; // $a1
					// 		struct _Position *_v0; // $v0
					// 		struct _Position *_v1; // $v0
					/* end block 1.1.1.1.2 */
					// End offset: 0x80085818
					// End Line: 126

					/* begin block 1.1.1.1.3 */
						// Start line: 130
						// Start offset: 0x80085828
						// Variables:
					// 		struct MATRIX *mat; // $v1
					/* end block 1.1.1.1.3 */
					// End offset: 0x80085828
					// End Line: 130

					/* begin block 1.1.1.1.4 */
						// Start line: 136
						// Start offset: 0x8008584C
						// Variables:
					// 		short _x1; // $v1
					// 		short _y1; // $a0
					// 		short _z1; // $a1
					// 		struct _Position *_v0; // $v0
					// 		struct _Position *_v1; // $v0
					/* end block 1.1.1.1.4 */
					// End offset: 0x8008586C
					// End Line: 136
				/* end block 1.1.1.1 */
				// End offset: 0x80085884
				// End Line: 139
			/* end block 1.1.1 */
			// End offset: 0x80085884
			// End Line: 142
		/* end block 1.1 */
		// End offset: 0x80085884
		// End Line: 143
	/* end block 1 */
	// End offset: 0x80085888
	// End Line: 146

	/* begin block 2 */
		// Start line: 178
	/* end block 2 */
	// End Line: 179

int MONSENSE_SetEnemy(_Instance *instance,evCollideInstanceStatsData *data)

{
  short sVar1;
  int arc;
  u_long uVar2;
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
  if (data->distance < (u_int)(int)psVar4[1]) {
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
      uVar2 = INSTANCE_Post(Inst,1);
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
        arc = PhysicsCheckDropHeight(instance,(int)&local_28,4);
      }
    }
  }
  return arc;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_Hear(struct _Instance *instance /*$a0*/, struct evCollideInstanceStatsData *data /*$s1*/)
 // line 151, offset 0x800858a0
	/* begin block 1 */
		// Start line: 152
		// Start offset: 0x800858A0
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _MonsterSenses *senses; // $s0
	// 		long mode; // $a0
	/* end block 1 */
	// End offset: 0x8008591C
	// End Line: 169

	/* begin block 2 */
		// Start line: 266
	/* end block 2 */
	// End Line: 267

int MONSENSE_Hear(_Instance *instance,evCollideInstanceStatsData *data)

{
  u_long uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)((int)instance->extraData + 0x164) + 4);
  uVar1 = INSTANCE_Post(data->instance,10);
  if ((((uVar1 & 0x10b0143) == 0) || (iVar2 = 0, (uVar1 & 0x200000) != 0)) &&
     (iVar2 = 0, data->distance < (u_int)(int)*(short *)(iVar3 + 8))) {
    iVar2 = MATH3D_ConeDetect(&data->relativePosition,(int)*(short *)(iVar3 + 6),
                              (int)*(short *)(iVar3 + 10));
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_Smell(struct _Instance *instance /*$a0*/, struct evCollideInstanceStatsData *data /*$a1*/)
 // line 174, offset 0x80085930
	/* begin block 1 */
		// Start line: 176
		// Start offset: 0x80085930
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x80085930
	// End Line: 176

	/* begin block 2 */
		// Start line: 315
	/* end block 2 */
	// End Line: 316

	/* begin block 3 */
		// Start line: 316
	/* end block 3 */
	// End Line: 317

int MONSENSE_Smell(_Instance *instance,evCollideInstanceStatsData *data)

{
  return (u_int)(data->distance <
               (u_int)*(ushort *)(*(int *)(*(int *)((int)instance->extraData + 0x164) + 4) + 0xc));
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_DetectPlayer(struct _Instance *instance /*$a0*/)
 // line 187, offset 0x80085958
	/* begin block 1 */
		// Start line: 188
		// Start offset: 0x80085958
	/* end block 1 */
	// End offset: 0x80085958
	// End Line: 188

	/* begin block 2 */
		// Start line: 341
	/* end block 2 */
	// End Line: 342

int MONSENSE_DetectPlayer(_Instance *instance)

{
  _MonsterIR *p_Var1;
  
  p_Var1 = MONSENSE_FindIR((_MonsterVars *)instance->extraData,gameTrackerX.playerInstance);
  return (u_int)(p_Var1 != (_MonsterIR *)0x0);
}



// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_FirstSense(struct _Instance *instance /*$s2*/, struct _Instance *sensed /*$s4*/)
 // line 197, offset 0x80085980
	/* begin block 1 */
		// Start line: 198
		// Start offset: 0x80085980
		// Variables:
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 205
			// Start offset: 0x800859BC
			// Variables:
		// 		long whatAmI; // $s2
		// 		struct _MonsterAllegiances *allegiances; // $s3
		/* end block 1.1 */
		// End offset: 0x80085AF4
		// End Line: 235
	/* end block 1 */
	// End offset: 0x80085AF4
	// End Line: 237

	/* begin block 2 */
		// Start line: 365
	/* end block 2 */
	// End Line: 366

_MonsterIR * MONSENSE_SenseInstance(_Instance *instance,_Instance *sensed)

{
  ushort uVar1;
  _MonsterIR *p_Var2;
  u_long uVar3;
  u_long uVar4;
  _MonsterVars *mv;
  _MonsterAllegiances *p_Var5;
  
  mv = (_MonsterVars *)instance->extraData;
  p_Var2 = MONSENSE_GetMonsterIR(mv);
  if (p_Var2 != (_MonsterIR *)0x0) {
    uVar3 = INSTANCE_Post(sensed,1);
    p_Var5 = mv->subAttr->allegiances;
    p_Var2->mirFlags = 0x100;
    p_Var2->instance = sensed;
    p_Var2->handle = sensed->instanceID;
    uVar4 = MON_GetAnim(instance);
    p_Var2->forgetTimer = uVar4 + (int)mv->subAttr->forgetTime * 1000;
    p_Var2->next = mv->monsterIRList;
    mv->monsterIRList = p_Var2;
    p_Var2->mirConditions = 0;
    if (((uVar3 & p_Var5->enemies) != 0) &&
       (uVar4 = INSTANCE_Post(sensed,0), (uVar4 & 0x44000000) == 0)) {
      p_Var2->mirFlags = p_Var2->mirFlags | 1;
    }
    if ((uVar3 & p_Var5->allies) != 0) {
      uVar1 = p_Var2->mirFlags;
      p_Var2->mirFlags = uVar1 | 2;
      if ((*(u_int *)sensed->extraData & 0x100000) != 0) {
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
 // line 244, offset 0x80085b18
	/* begin block 1 */
		// Start line: 245
		// Start offset: 0x80085B18
		// Variables:
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterVars *mv; // $s3

		/* begin block 1.1 */
			// Start line: 264
			// Start offset: 0x80085BBC
			// Variables:
		// 		long mode; // $s1

			/* begin block 1.1.1 */
				// Start line: 267
				// Start offset: 0x80085BBC
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			// 		struct _SVector *_v0; // $v0
			// 		struct _SVector *_v1; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80085BBC
			// End Line: 267

			/* begin block 1.1.2 */
				// Start line: 317
				// Start offset: 0x80085DA4
			/* end block 1.1.2 */
			// End offset: 0x80085E00
			// End Line: 324
		/* end block 1.1 */
		// End offset: 0x80085F24
		// End Line: 356
	/* end block 1 */
	// End offset: 0x80085F24
	// End Line: 357

	/* begin block 2 */
		// Start line: 473
	/* end block 2 */
	// End Line: 474

void MONSENSE_SetupMIR(_Instance *instance,evCollideInstanceStatsData *data,int flags)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  _MonsterIR *p_Var5;
  _MonsterCombatAttributes *p_Var6;
  u_long uVar7;
  ushort uVar8;
  _MonsterVars *mv;
  
  mv = (_MonsterVars *)instance->extraData;
  p_Var5 = MONSENSE_FindIR(mv,data->instance);
  if (p_Var5 == (_MonsterIR *)0x0) {
    if (flags != 0) {
      p_Var5 = MONSENSE_SenseInstance(instance,data->instance);
    }
  }
  else {
    if (flags != 0) {
      uVar7 = MON_GetAnim(instance);
      p_Var5->forgetTimer = uVar7 + (int)mv->subAttr->forgetTime * 1000;
    }
  }
  if (p_Var5 == (_MonsterIR *)0x0) {
    return;
  }
  p_Var5->mirFlags = p_Var5->mirFlags | (ushort)flags;
  p_Var5->distance = *(short *)&data->distance;
  sVar3 = (data->relativePosition).y;
  sVar1 = (data->relativePosition).z;
  (p_Var5->relativePosition).x = (data->relativePosition).x;
  (p_Var5->relativePosition).y = sVar3;
  (p_Var5->relativePosition).z = sVar1;
  p_Var6 = mv->subAttr->combatAttributes;
  if ((p_Var6 == (_MonsterCombatAttributes *)0x0) || (p_Var6->combatRange <= p_Var5->distance)) {
    uVar4 = p_Var5->mirConditions & 0xfff7;
  }
  else {
    uVar4 = p_Var5->mirConditions | 8;
  }
  p_Var5->mirConditions = uVar4;
  sVar3 = MATH3D_AngleFromPosToPos(&p_Var5->instance->position,&instance->position);
  if (((sVar3 - (p_Var5->instance->rotation).z) + 0x400U & 0xfff) < 0x801) {
    uVar4 = p_Var5->mirConditions & 0xfffd;
  }
  else {
    uVar4 = p_Var5->mirConditions | 2;
  }
  p_Var5->mirConditions = uVar4;
  uVar7 = INSTANCE_Post(p_Var5->instance,10);
  if ((uVar7 & 0x208000) == 0x208000) {
    uVar7 = uVar7 & 0xffdfffff;
  }
  if ((uVar7 & 4) == 0) {
    uVar4 = p_Var5->mirConditions & 0xfffe;
  }
  else {
    uVar4 = p_Var5->mirConditions | 1;
  }
  p_Var5->mirConditions = uVar4;
  uVar4 = p_Var5->mirFlags;
  if ((uVar4 & 0x400) == 0) {
    if (((uVar7 & 0x200000) != 0) &&
       (mv->subAttr->combatAttributes != (_MonsterCombatAttributes *)0x0)) {
      p_Var5->mirConditions = p_Var5->mirConditions & 0xff1b;
      p_Var5->mirFlags = p_Var5->mirFlags | 0x400;
      if ((int)p_Var5->distance < (int)mv->subAttr->combatAttributes->enemyAttackRange << 1) {
        sVar3 = MATH3D_AngleFromPosToPos(&p_Var5->instance->position,&instance->position);
        if (((sVar3 - (p_Var5->instance->rotation).z) + 0x200U & 0xfff) < 0x800) {
          if ((uVar7 & 4) != 0) {
            p_Var5->mirConditions = p_Var5->mirConditions | 0x20;
          }
          p_Var5->mirConditions = p_Var5->mirConditions | 0x800;
        }
      }
    }
  }
  else {
    if ((uVar7 & 0x200000) != 0) goto LAB_80085e0c;
    uVar2 = p_Var5->mirConditions;
    p_Var5->mirFlags = uVar4 & 0xfbff;
    uVar8 = uVar2 & 0xf7df;
    p_Var5->mirConditions = uVar8;
    if (((uVar4 & 1) != 0) && ((uVar2 & 0x400) == 0)) {
      p_Var5->mirConditions = uVar8 | 4;
    }
  }
  uVar4 = p_Var5->mirFlags;
LAB_80085e0c:
  if ((uVar4 & 0x800) == 0) {
    if (uVar7 == 1) {
      p_Var5->mirFlags = uVar4 | 0x800;
      uVar7 = MON_GetAnim(instance);
      *(undefined **)&p_Var5->idleTime = &DAT_00001356 + uVar7;
    }
  }
  else {
    if (uVar7 == 1) {
      if (((p_Var5->mirConditions & 0x10) == 0) &&
         (uVar7 = MON_GetAnim(instance), p_Var5->idleTime < uVar7)) {
        p_Var5->mirConditions = p_Var5->mirConditions | 0x10;
      }
    }
    else {
      p_Var5->mirFlags = uVar4 & 0xf7ff;
      p_Var5->mirConditions = p_Var5->mirConditions & 0xffef;
    }
  }
  uVar4 = p_Var5->mirFlags;
  if ((uVar4 & 0x200) == 0) {
    if ((uVar4 & 2) == 0) {
      return;
    }
    uVar4 = uVar4 | 0x200;
    if (mv->subAttr->combatAttributes->allyRange <= p_Var5->distance) {
      return;
    }
  }
  else {
    if (((int)p_Var5->distance <= (int)mv->subAttr->combatAttributes->allyRange + 300) &&
       (uVar7 = INSTANCE_Post(p_Var5->instance,0), (uVar7 & 0x44000000) == 0)) {
      return;
    }
    uVar4 = p_Var5->mirFlags & 0xfdff;
  }
  p_Var5->mirFlags = uVar4;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_SenseInstance(struct _Instance *instance /*$s3*/, struct evCollideInstanceStatsData *data /*$s2*/)
 // line 363, offset 0x80085f44
	/* begin block 1 */
		// Start line: 364
		// Start offset: 0x80085F44
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long flags; // $s0
	// 		unsigned long whatAmI; // $s4

		/* begin block 1.1 */
			// Start line: 376
			// Start offset: 0x80085F9C
			// Variables:
		// 		struct PhysObProperties *prop; // $s0

			/* begin block 1.1.1 */
				// Start line: 379
				// Start offset: 0x80085FBC
			/* end block 1.1.1 */
			// End offset: 0x8008605C
			// End Line: 390
		/* end block 1.1 */
		// End offset: 0x8008605C
		// End Line: 390
	/* end block 1 */
	// End offset: 0x80086118
	// End Line: 408

	/* begin block 2 */
		// Start line: 716
	/* end block 2 */
	// End Line: 717

void MONSENSE_FirstSense(_Instance *instance,evCollideInstanceStatsData *data)

{
  u_long uVar1;
  int iVar2;
  u_int flags;
  void *pvVar3;
  u_int *puVar4;
  
  flags = 0;
  puVar4 = (u_int *)instance->extraData;
  uVar1 = INSTANCE_Post(data->instance,1);
  if ((*puVar4 & 0x200) == 0) {
    if ((uVar1 & 0x20) == 0) {
      if (*(char *)((int)puVar4 + 0x15e) != '\0') {
        iVar2 = MONSENSE_Smell(instance,data);
        if (iVar2 != 0) {
          flags = 0x80;
        }
        iVar2 = MONSENSE_SetEnemy(instance,data);
        if (iVar2 != 0) {
          flags = flags | 0x20;
        }
        iVar2 = MONSENSE_Hear(instance,data);
        if (iVar2 != 0) {
          flags = flags | 0x40;
        }
        if (((uVar1 & *(u_int *)(*(int *)(puVar4[0x59] + 0xc) + 4)) != 0) &&
           (data->distance < (u_int)*(ushort *)(*(int *)(puVar4[0x59] + 4) + 0x10))) {
          flags = flags | 2;
        }
        MONSENSE_SetupMIR(instance,data,flags);
      }
    }
    else {
      pvVar3 = data->instance->data;
      if ((((*(short *)((int)pvVar3 + 2) == 3) &&
           (data->xyDistance < (int)(u_int)(*(ushort *)((int)pvVar3 + 0x1e) >> 1))) &&
          (data->zDelta < (int)*(short *)((int)pvVar3 + 0x22))) &&
         ((int)*(short *)((int)pvVar3 + 0x20) < data->zDelta)) {
        if ((*(ushort *)((int)pvVar3 + 8) & 0x40) != 0) {
          INSTANCE_Query(instance,0x100000c,0x20);
        }
        if ((*(ushort *)((int)pvVar3 + 8) & 8) != 0) {
          INSTANCE_Query(instance,0x100000c,0x40);
        }
        if ((*(ushort *)((int)pvVar3 + 8) & 0x10) != 0) {
          INSTANCE_Query(instance,0x100000c,0x10);
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_StartMonsterIRList(struct _Instance *instance /*$s5*/)
 // line 413, offset 0x80086138
	/* begin block 1 */
		// Start line: 414
		// Start offset: 0x80086138
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterIR *newlist; // $s2
	// 		int enemyOnList; // $s4

		/* begin block 1.1 */
			// Start line: 424
			// Start offset: 0x80086184
			// Variables:
		// 		struct _MonsterIR *next; // $s3
		/* end block 1.1 */
		// End offset: 0x8008620C
		// End Line: 452
	/* end block 1 */
	// End offset: 0x80086228
	// End Line: 460

	/* begin block 2 */
		// Start line: 820
	/* end block 2 */
	// End Line: 821

void MONSENSE_StartMonsterIRList(_Instance *instance)

{
  bool bVar1;
  u_char *puVar2;
  u_char *puVar3;
  u_long uVar4;
  void *pvVar5;
  u_char *puVar6;
  
  pvVar5 = instance->extraData;
  bVar1 = false;
  if (*(char *)((int)pvVar5 + 0x15e) != '\0') {
    puVar2 = (u_char *)0;
    puVar6 = *(u_char **)((int)pvVar5 + 0x90);
    while (puVar3 = puVar6, puVar3 != (u_char *)0x0) {
      puVar6 = (u_char *)*puVar3;
      if ((puVar3[2] == *(int *)(puVar3[1] + 0x10)) &&
         (((*(ushort *)((int)puVar3 + 0x16) & 0xe0) != 0 ||
          (uVar4 = MON_GetAnim(instance), uVar4 <= (u_int)puVar3[7])))) {
        *(u_char **)puVar3 = puVar2;
        *(ushort *)((int)puVar3 + 0x16) = *(ushort *)((int)puVar3 + 0x16) & 0xff1f;
        puVar2 = puVar3;
        if (*(u_char **)((int)pvVar5 + 0xc4) == puVar3) {
          bVar1 = true;
        }
      }
      else {
        *puVar3 = *(u_char *)((int)pvVar5 + 0x168);
        *(u_char **)((int)pvVar5 + 0x168) = puVar3;
      }
    }
    if (!bVar1) {
      *(u_char *)((int)pvVar5 + 0xc4) = 0;
    }
    *(u_char **)((int)pvVar5 + 0x90) = puVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_GetMonsterIR(struct _MonsterVars *mv /*$a0*/)
 // line 465, offset 0x8008624c
	/* begin block 1 */
		// Start line: 467
		// Start offset: 0x8008624C
		// Variables:
	// 		struct _MonsterIR *mir; // $v1
	/* end block 1 */
	// End offset: 0x8008626C
	// End Line: 477

	/* begin block 2 */
		// Start line: 956
	/* end block 2 */
	// End Line: 957

	/* begin block 3 */
		// Start line: 957
	/* end block 3 */
	// End Line: 958

	/* begin block 4 */
		// Start line: 959
	/* end block 4 */
	// End Line: 960

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
 // line 483, offset 0x80086274
	/* begin block 1 */
		// Start line: 485
		// Start offset: 0x80086274
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80086294
	// End Line: 494

	/* begin block 2 */
		// Start line: 992
	/* end block 2 */
	// End Line: 993

	/* begin block 3 */
		// Start line: 993
	/* end block 3 */
	// End Line: 994

	/* begin block 4 */
		// Start line: 997
	/* end block 4 */
	// End Line: 998

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
// struct _MonsterIR * /*$ra*/ MONSENSE_SetEnemy(struct _Instance *instance /*$s1*/, struct _Instance *newenemy /*$s2*/)
 // line 501, offset 0x800862a0
	/* begin block 1 */
		// Start line: 502
		// Start offset: 0x800862A0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *mir; // $a2

		/* begin block 1.1 */
			// Start line: 521
			// Start offset: 0x80086314
			// Variables:
		// 		long angle; // $v0
		/* end block 1.1 */
		// End offset: 0x80086370
		// End Line: 527
	/* end block 1 */
	// End offset: 0x800863A4
	// End Line: 537

	/* begin block 2 */
		// Start line: 1030
	/* end block 2 */
	// End Line: 1031

_MonsterIR * MONSENSE_See(_Instance *instance,_Instance *newenemy)

{
  short sVar1;
  _MonsterIR *p_Var2;
  int iVar3;
  u_int uVar4;
  u_int uVar5;
  _MonsterVars *mv;
  
  mv = (_MonsterVars *)instance->extraData;
  p_Var2 = MONSENSE_FindIR(mv,newenemy);
  if (p_Var2 == (_MonsterIR *)0x0) {
    p_Var2 = MONSENSE_SenseInstance(instance,newenemy);
    if (p_Var2 == (_MonsterIR *)0x0) {
      p_Var2 = mv->monsterIRList;
      mv->monsterIRList = p_Var2->next;
      p_Var2->next = mv->freeIRs;
      mv->freeIRs = p_Var2;
      p_Var2 = MONSENSE_SenseInstance(instance,newenemy);
      if (p_Var2 == (_MonsterIR *)0x0) goto LAB_80086380;
    }
    uVar5 = (u_int)(ushort)(instance->rotation).z & 0xfff;
    if (0x800 < uVar5) {
      uVar5 = uVar5 - 0x1000;
    }
    uVar4 = (u_int)(ushort)(newenemy->rotation).z & 0xfff;
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
LAB_80086380:
  if ((mv->enemy == (_MonsterIR *)0x0) || (newenemy == gameTrackerX.playerInstance)) {
    mv->enemy = p_Var2;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_ProcessIRList(struct _Instance *instance /*$s7*/)
 // line 543, offset 0x800863c0
	/* begin block 1 */
		// Start line: 544
		// Start offset: 0x800863C0
		// Variables:
	// 		struct _MonsterVars *mv; // $s4
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterIR *closestEnemy; // $s1
	// 		struct _MonsterIR *closestLeader; // $s2
	// 		struct _MonsterIR *closestAlly; // $s3
	// 		struct _MonsterIR *player; // $s6
	// 		struct _MonsterCombatAttributes *combatAttr; // $s5
	/* end block 1 */
	// End offset: 0x80086594
	// End Line: 601

	/* begin block 2 */
		// Start line: 1119
	/* end block 2 */
	// End Line: 1120

void MONSENSE_ProcessIRList(_Instance *instance)

{
  u_long uVar1;
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
        uVar1 = INSTANCE_Post((_Instance *)Data[1],1);
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
          INSTANCE_Query(instance,Message,(int)Data);
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
     (((iVar6 != 0 && (*(char *)(iVar6 + 0x18) != '\0')) && (*(short *)((int)pvVar5 + 0x140) == 0)))
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
 // line 619, offset 0x800865c8
	/* begin block 1 */
		// Start line: 620
		// Start offset: 0x800865C8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAllegiances *allegiances; // $s0
	/* end block 1 */
	// End offset: 0x800866E8
	// End Line: 675

	/* begin block 2 */
		// Start line: 1235
	/* end block 2 */
	// End Line: 1236

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
  iVar1 = gNumMonsters;
  instance->checkMask = instance->checkMask | 0xb;
  mv->enemy = (_MonsterIR *)0x0;
  mv->leader = (_MonsterIR *)0x0;
  (&monsterSenseArray40)[iVar1] = mv;
  mv->senseIndex = (char)gNumMonsters;
  if (gNumMonsters == 0) {
    lastSenseFrame = -1;
  }
  gNumMonsters = gNumMonsters + 1;
  if (((6 < gNumMonsters) && (instance->parent == (_Instance *)0x0)) &&
     (instance->currentStreamUnitID != instance->birthStreamUnitID)) {
    instance->flags = instance->flags | 0x20;
    instance->flags2 = instance->flags2 | 0x20000;
    SAVE_Instance(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_RemoveSenses(struct _Instance *instance /*$a0*/)
 // line 680, offset 0x80086700
	/* begin block 1 */
		// Start line: 682
		// Start offset: 0x80086700
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x8008675C
	// End Line: 693

	/* begin block 2 */
		// Start line: 1498
	/* end block 2 */
	// End Line: 1499

	/* begin block 3 */
		// Start line: 1499
	/* end block 3 */
	// End Line: 1500

	/* begin block 4 */
		// Start line: 1503
	/* end block 4 */
	// End Line: 1504

void MONSENSE_RemoveSenses(_Instance *instance)

{
  int iVar1;
  int iVar2;
  
  gNumMonsters = gNumMonsters + -1;
  iVar2 = (int)*(char *)((int)instance->extraData + 0x15f);
  if (iVar2 < gNumMonsters) {
    do {
      iVar1 = iVar2 + 1;
      (&monsterSenseArray40)[iVar2] = (&monsterSenseArray40)[iVar1];
      (&monsterSenseArray40)[iVar1]->senseIndex = (char)iVar2;
      iVar2 = iVar1;
    } while (iVar1 < gNumMonsters);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_Radar(struct _Instance *instance /*$s0*/)
 // line 817, offset 0x80086764
	/* begin block 1 */
		// Start line: 818
		// Start offset: 0x80086764
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct SVECTOR newPos; // stack offset -96
	// 		struct SVECTOR oldPos; // stack offset -88
	// 		struct _PCollideInfo pCollideInfo; // stack offset -80
	// 		int index; // $s3
	/* end block 1 */
	// End offset: 0x80086980
	// End Line: 889

	/* begin block 2 */
		// Start line: 1779
	/* end block 2 */
	// End Line: 1780

void MONSENSE_Radar(_Instance *instance)

{
  undefined2 uVar1;
  long lVar2;
  void *pvVar3;
  u_int uVar4;
  SVECTOR local_60;
  SVECTOR local_58;
  _PCollideInfo local_50;
  
  pvVar3 = instance->extraData;
  uVar4 = (u_int)""[*(int *)((int)pvVar3 + 0xe4)];
  local_60.vx = (instance->position).x + (&radarDir)[uVar4].x;
  local_60.vy = (instance->position).y + (&radarDir)[uVar4].y;
  local_60.vz = (instance->position).z + 100;
  local_58.vx = (instance->position).x;
  local_58.vy = (instance->position).y;
  local_50.newPoint = &local_60;
  local_50.oldPoint = &local_58;
  local_50.collideType = 0x13f;
  local_58.vz = (instance->position).z + 100;
  PHYSICS_CheckLineInWorldMask(instance,&local_50);
  if (local_50.type == 0) {
    local_58.vx = (instance->position).x + (&radarDir)[uVar4].x;
    local_58.vy = (instance->position).y + (&radarDir)[uVar4].y;
    local_58.vz = (instance->position).z + -0x100;
    local_60.vx = (instance->position).x;
    local_60.vy = (instance->position).y;
    local_60.vz = (instance->position).z + -0x100;
    PHYSICS_CheckLineInWorld(instance,&local_50);
    if (local_50.type != 0) goto LAB_800868d4;
    *(u_int *)((int)pvVar3 + 0xe0) = *(u_int *)((int)pvVar3 + 0xe0) | 1 << (uVar4 & 0x1f);
    uVar1 = 0x500;
  }
  else {
LAB_800868d4:
    *(u_int *)((int)pvVar3 + 0xe0) = *(u_int *)((int)pvVar3 + 0xe0) & ~(1 << (uVar4 & 0x1f));
    if ((local_50.type == 3) &&
       ((*(ushort *)
          ((int)((local_50.inst)->node).prev[9].prev + (int)local_50.segment * 0x24 + 0x12) & 2) !=
        0)) {
      *(undefined2 *)((int)pvVar3 + uVar4 * 2 + 0xe8) = 0;
      goto LAB_80086960;
    }
    lVar2 = MATH3D_LengthXYZ((int)local_60.vx - (int)(instance->position).x,
                             (int)local_60.vy - (int)(instance->position).y);
    uVar1 = (undefined2)lVar2;
  }
  *(undefined2 *)((int)pvVar3 + uVar4 * 2 + 0xe8) = uVar1;
LAB_80086960:
  uVar4 = *(int *)((int)pvVar3 + 0xe4) + 1;
  *(u_int *)((int)pvVar3 + 0xe4) = uVar4;
  if (7 < uVar4) {
    *(u_char *)((int)pvVar3 + 0xe4) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MONSENSE_GetClosestFreeDirection(struct _Instance *instance /*$a0*/, short angle /*$t1*/, long range /*$a2*/)
 // line 894, offset 0x800869a4
	/* begin block 1 */
		// Start line: 895
		// Start offset: 0x800869A4
		// Variables:
	// 		struct _MonsterVars *mv; // $t0
	// 		int bit; // $a1
	// 		int search; // $a0
	/* end block 1 */
	// End offset: 0x80086AA8
	// End Line: 928

	/* begin block 2 */
		// Start line: 1952
	/* end block 2 */
	// End Line: 1953

/* WARNING: Removing unreachable block (ram,0x800869c4) */

short MONSENSE_GetDistanceInDirection(_Instance *instance,short angle,long range)

{
  short sVar1;
  int iVar2;
  u_int uVar3;
  u_int uVar4;
  void *pvVar5;
  
  pvVar5 = instance->extraData;
  uVar3 = (int)((int)angle + 0x100U & 0xfff) >> 9;
  iVar2 = 1;
  if ((*(short *)((int)pvVar5 + uVar3 * 2 + 0xe8) == 0) &&
     (uVar4 = uVar3 + 4 & 7, range < *(short *)((int)pvVar5 + uVar4 * 2 + 0xe8))) {
    return (&radarDir)[uVar4].angle;
  }
  sVar1 = *(short *)((int)pvVar5 + uVar3 * 2 + 0xe8);
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
    uVar3 = uVar3 & 7;
    if (3 < iVar2) break;
    sVar1 = *(short *)((int)pvVar5 + uVar3 * 2 + 0xe8);
    angle = (&radarDir)[uVar3].angle;
  }
  return angle;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_GetDistanceInDirection(struct _Instance *instance /*$a0*/, short angle /*$a1*/)
 // line 933, offset 0x80086ab0
	/* begin block 1 */
		// Start line: 935
		// Start offset: 0x80086AB0
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int bit; // $v0
	/* end block 1 */
	// End offset: 0x80086AD0
	// End Line: 936

	/* begin block 2 */
		// Start line: 2035
	/* end block 2 */
	// End Line: 2036

	/* begin block 3 */
		// Start line: 2036
	/* end block 3 */
	// End Line: 2037

	/* begin block 4 */
		// Start line: 2037
	/* end block 4 */
	// End Line: 2038

/* WARNING: Removing unreachable block (ram,0x80086acc) */

int MONSENSE_GetClosestFreeDirection(_Instance *instance,short angle)

{
  return (int)*(short *)((int)instance->extraData +
                        ((int)((int)angle + 0x100U & 0xfff) >> 9) * 2 + 0xe8);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_DoSenses(struct _Instance *instance /*$s1*/)
 // line 944, offset 0x80086ae8
	/* begin block 1 */
		// Start line: 945
		// Start offset: 0x80086AE8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		static int doneThisFrame; // offset 0x3c
	/* end block 1 */
	// End offset: 0x80086BD4
	// End Line: 975

	/* begin block 2 */
		// Start line: 2058
	/* end block 2 */
	// End Line: 2059

void MONSENSE_DoSenses(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MONSENSE_ProcessIRList(instance);
  if (lastSenseFrame < (int)gameTrackerX.frameCount) {
    if (lastSenseFrame < (int)(gameTrackerX.frameCount - 1)) {
      memset(&monsterSensed,0,0x28);
      lastSenseFrame = gameTrackerX.frameCount - 1;
    }
    DAT_800d08d0 = 0;
  }
  if ((DAT_800d08d0 == 0) && ((&monsterSensed)[*(char *)((int)pvVar1 + 0x15f)] == '\0')) {
    lastSenseFrame = gameTrackerX.frameCount;
    (&monsterSensed)[*(char *)((int)pvVar1 + 0x15f)] = '\x01';
    DAT_800d08d0 = 1;
    *(undefined *)((int)pvVar1 + 0x15e) = 1;
    if ((*(u_int *)((int)pvVar1 + 4) & 0x20000000) == 0) {
      MONSENSE_Radar(instance);
    }
  }
  else {
    *(undefined *)((int)pvVar1 + 0x15e) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_AdjustRadarFromObjects(struct _Instance *instance /*$s3*/)
 // line 980, offset 0x80086be8
	/* begin block 1 */
		// Start line: 981
		// Start offset: 0x80086BE8
		// Variables:
	// 		struct _MonsterVars *mv; // $s4
	// 		struct _Instance *physob; // $s2

		/* begin block 1.1 */
			// Start line: 989
			// Start offset: 0x80086C38
			// Variables:
		// 		struct PhysObProperties *prop; // $s1

			/* begin block 1.1.1 */
				// Start line: 992
				// Start offset: 0x80086C50

				/* begin block 1.1.1.1 */
					// Start line: 998
					// Start offset: 0x80086C8C
					// Variables:
				// 		long dist; // $s0

					/* begin block 1.1.1.1.1 */
						// Start line: 1003
						// Start offset: 0x80086CC0
						// Variables:
					// 		int i; // $v1
					// 		int min; // $a1
					// 		int max; // $a2
					// 		int ang; // $s0
					/* end block 1.1.1.1.1 */
					// End offset: 0x80086D9C
					// End Line: 1031
				/* end block 1.1.1.1 */
				// End offset: 0x80086D9C
				// End Line: 1032
			/* end block 1.1.1 */
			// End offset: 0x80086D9C
			// End Line: 1034
		/* end block 1.1 */
		// End offset: 0x80086D9C
		// End Line: 1035
	/* end block 1 */
	// End offset: 0x80086DAC
	// End Line: 1037

	/* begin block 2 */
		// Start line: 2130
	/* end block 2 */
	// End Line: 2131

	/* begin block 3 */
		// Start line: 2134
	/* end block 3 */
	// End Line: 2135

/* WARNING: Removing unreachable block (ram,0x80086cfc) */
/* WARNING: Removing unreachable block (ram,0x80086d14) */

void MONSENSE_AdjustRadarFromObjects(_Instance *instance)

{
  short sVar1;
  short sVar2;
  int iVar3;
  long x;
  u_int uVar4;
  u_int uVar5;
  void *pvVar6;
  _Instance *p_Var7;
  void *pvVar8;
  
  p_Var7 = (gameTrackerX.instanceList)->first;
  pvVar8 = instance->extraData;
  while (p_Var7 != (_Instance *)0x0) {
    if ((((p_Var7->object->oflags2 & 0x40000U) != 0) &&
        (pvVar6 = p_Var7->data, *(short *)((int)pvVar6 + 2) == 3)) &&
       ((*(ushort *)((int)pvVar6 + 8) & 0x40) != 0)) {
      iVar3 = (int)(p_Var7->position).z - (int)(instance->position).z;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if ((iVar3 < 400) &&
         (x = MATH3D_LengthXYZ((int)(p_Var7->position).x - (int)(instance->position).x,
                               (int)(p_Var7->position).y - (int)(instance->position).y),
         x < (int)((u_int)*(ushort *)((int)pvVar6 + 0x1e) + 0x500))) {
        sVar1 = MATH3D_AngleFromPosToPos(&instance->position,&p_Var7->position);
        sVar2 = MATH3D_FastAtan2((u_int)*(ushort *)((int)pvVar6 + 0x1e),x);
        uVar5 = (int)((int)sVar1 + (int)sVar2 + 0x100U & 0xfff) >> 9;
        uVar4 = (int)(((int)sVar1 - (int)sVar2) + 0x100U & 0xfff) >> 9;
        if (uVar4 < uVar5) {
          if (uVar4 <= uVar5) {
            pvVar6 = (void *)(uVar4 * 2 + (int)pvVar8);
            do {
              *(undefined2 *)((int)pvVar6 + 0xe8) = 0;
              uVar4 = uVar4 + 1;
              pvVar6 = (void *)((int)pvVar6 + 2);
            } while ((int)uVar4 <= (int)uVar5);
          }
        }
        else {
          iVar3 = 0;
          pvVar6 = pvVar8;
          do {
            *(undefined2 *)((int)pvVar6 + 0xe8) = 0;
            iVar3 = iVar3 + 1;
            pvVar6 = (void *)((int)pvVar6 + 2);
          } while (iVar3 <= (int)uVar5);
          if (uVar4 < 8) {
            pvVar6 = (void *)(uVar4 * 2 + (int)pvVar8);
            do {
              *(undefined2 *)((int)pvVar6 + 0xe8) = 0;
              uVar4 = uVar4 + 1;
              pvVar6 = (void *)((int)pvVar6 + 2);
            } while ((int)uVar4 < 8);
          }
        }
      }
    }
    p_Var7 = p_Var7->next;
  }
  return;
}





