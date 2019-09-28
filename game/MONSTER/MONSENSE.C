#include "THISDUST.H"
#include "MONSENSE.H"


// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_FindIR(struct _MonsterVars *mv /*$a0*/, struct _Instance *instance /*$a1*/)
 // line 64, offset 0x80085aa4
	/* begin block 1 */
		// Start line: 66
		// Start offset: 0x80085AA4
		// Variables:
	// 		struct _MonsterIR *mir; // $v1
	/* end block 1 */
	// End offset: 0x80085AD4
	// End Line: 72

	/* begin block 2 */
		// Start line: 114
	/* end block 2 */
	// End Line: 115

	/* begin block 3 */
		// Start line: 128
	/* end block 3 */
	// End Line: 129

	/* begin block 4 */
		// Start line: 115
	/* end block 4 */
	// End Line: 116

	/* begin block 5 */
		// Start line: 117
	/* end block 5 */
	// End Line: 118

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
 // line 97, offset 0x80085adc
	/* begin block 1 */
		// Start line: 98
		// Start offset: 0x80085ADC
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _MonsterSenses *senses; // $s0

		/* begin block 1.1 */
			// Start line: 104
			// Start offset: 0x80085B20
			// Variables:
		// 		int arc; // $a1
		// 		int elevation; // $a2

			/* begin block 1.1.1 */
				// Start line: 114
				// Start offset: 0x80085B70
				// Variables:
			// 		struct _Instance *target; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 118
					// Start offset: 0x80085B88
					// Variables:
				// 		struct evPhysicsLOSData losData; // stack offset -40

					/* begin block 1.1.1.1.1 */
						// Start line: 122
						// Start offset: 0x80085B98
						// Variables:
					// 		struct MATRIX *mat; // $v0
					/* end block 1.1.1.1.1 */
					// End offset: 0x80085B98
					// End Line: 122

					/* begin block 1.1.1.1.2 */
						// Start line: 128
						// Start offset: 0x80085BD4
						// Variables:
					// 		short _x1; // $v1
					// 		short _y1; // $a0
					// 		short _z1; // $a1
					// 		struct _Position *_v0; // $v0
					// 		struct _Position *_v1; // $v0
					/* end block 1.1.1.1.2 */
					// End offset: 0x80085BF0
					// End Line: 128

					/* begin block 1.1.1.1.3 */
						// Start line: 132
						// Start offset: 0x80085C00
						// Variables:
					// 		struct MATRIX *mat; // $v1
					/* end block 1.1.1.1.3 */
					// End offset: 0x80085C00
					// End Line: 132

					/* begin block 1.1.1.1.4 */
						// Start line: 138
						// Start offset: 0x80085C24
						// Variables:
					// 		short _x1; // $v1
					// 		short _y1; // $a0
					// 		short _z1; // $a1
					// 		struct _Position *_v0; // $v0
					// 		struct _Position *_v1; // $v0
					/* end block 1.1.1.1.4 */
					// End offset: 0x80085C44
					// End Line: 138
				/* end block 1.1.1.1 */
				// End offset: 0x80085C5C
				// End Line: 141
			/* end block 1.1.1 */
			// End offset: 0x80085C5C
			// End Line: 144
		/* end block 1.1 */
		// End offset: 0x80085C5C
		// End Line: 145
	/* end block 1 */
	// End offset: 0x80085C60
	// End Line: 148

	/* begin block 2 */
		// Start line: 194
	/* end block 2 */
	// End Line: 195

undefined4 MONSENSE_See(int param_1,_Instance **param_2)

{
  bool bVar1;
  short angle;
  uint uVar2;
  MATRIX *mat;
  MATRIX *pMVar3;
  short *psVar4;
  
  psVar4 = *(short **)(*(int *)(*(int *)(param_1 + 0x14c) + 0x154) + 4);
  if (param_2[1] < (_Instance *)(int)psVar4[1]) {
    angle = MATH3D_FastAtan2(500,(long)param_2[1]);
    pMVar3 = (MATRIX *)(int)angle;
    mat = pMVar3;
    if ((int)pMVar3 < (int)(MATRIX *)(int)*psVar4) {
      mat = (MATRIX *)(int)*psVar4;
    }
    bVar1 = (int)pMVar3 < (int)psVar4[2];
    uVar2 = (uint)bVar1;
    if (bVar1) {
      angle = psVar4[2];
    }
    MATH3D_RotMatAboutVec((_SVector *)(param_2 + 2),mat,angle);
    if (uVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(*param_2,1);
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_Hear(struct _Instance *instance /*$a0*/, struct evCollideInstanceStatsData *data /*$s1*/)
 // line 153, offset 0x80085c78
	/* begin block 1 */
		// Start line: 154
		// Start offset: 0x80085C78
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _MonsterSenses *senses; // $s0
	// 		long mode; // $a0
	/* end block 1 */
	// End offset: 0x80085CF4
	// End Line: 171

	/* begin block 2 */
		// Start line: 270
	/* end block 2 */
	// End Line: 271

void MONSENSE_Hear(undefined4 param_1,_Instance **param_2)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(*param_2,10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_Smell(struct _Instance *instance /*$a0*/, struct evCollideInstanceStatsData *data /*$a1*/)
 // line 176, offset 0x80085d08
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x80085D08
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x80085D08
	// End Line: 178

	/* begin block 2 */
		// Start line: 319
	/* end block 2 */
	// End Line: 320

	/* begin block 3 */
		// Start line: 320
	/* end block 3 */
	// End Line: 321

uint MONSENSE_Smell(int param_1,int param_2)

{
  return (uint)(*(uint *)(param_2 + 4) <
               (uint)*(ushort *)(*(int *)(*(int *)(*(int *)(param_1 + 0x14c) + 0x154) + 4) + 0xc));
}



// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_FirstSense(struct _Instance *instance /*$s2*/, struct _Instance *sensed /*$s4*/)
 // line 186, offset 0x80085d30
	/* begin block 1 */
		// Start line: 187
		// Start offset: 0x80085D30
		// Variables:
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 194
			// Start offset: 0x80085D6C
			// Variables:
		// 		long whatAmI; // $s2
		// 		struct _MonsterAllegiances *allegiances; // $s3
		/* end block 1.1 */
		// End offset: 0x80085EB0
		// End Line: 224
	/* end block 1 */
	// End offset: 0x80085EB0
	// End Line: 226

	/* begin block 2 */
		// Start line: 339
	/* end block 2 */
	// End Line: 340

_MonsterIR * MONSENSE_FirstSense(_Instance *instance,_Instance *sensed)

{
  _MonsterIR *p_Var1;
  
  p_Var1 = MONSENSE_GetMonsterIR((_MonsterVars *)instance->extraData);
  if (p_Var1 != (_MonsterIR *)0x0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(sensed,1);
  }
  return (_MonsterIR *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_SetupMIR(struct _Instance *instance /*$s3*/, struct evCollideInstanceStatsData *data /*$s1*/, int flags /*$s2*/)
 // line 233, offset 0x80085ed4
	/* begin block 1 */
		// Start line: 234
		// Start offset: 0x80085ED4
		// Variables:
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterVars *mv; // $s4

		/* begin block 1.1 */
			// Start line: 253
			// Start offset: 0x80085F78
			// Variables:
		// 		long mode; // $s1

			/* begin block 1.1.1 */
				// Start line: 256
				// Start offset: 0x80085F78
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			// 		struct _SVector *_v0; // $v0
			// 		struct _SVector *_v1; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80085F78
			// End Line: 256

			/* begin block 1.1.2 */
				// Start line: 301
				// Start offset: 0x80086120
				// Variables:
			// 		int run; // $s2
			// 		int distance; // $a0

				/* begin block 1.1.2.1 */
					// Start line: 312
					// Start offset: 0x8008615C
				/* end block 1.1.2.1 */
				// End offset: 0x800861BC
				// End Line: 319
			/* end block 1.1.2 */
			// End offset: 0x800861BC
			// End Line: 336
		/* end block 1.1 */
		// End offset: 0x800862E0
		// End Line: 367
	/* end block 1 */
	// End offset: 0x800862E0
	// End Line: 368

	/* begin block 2 */
		// Start line: 447
	/* end block 2 */
	// End Line: 448

int MONSENSE_Smell(_Instance *instance,evCollideInstanceStatsData *data)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  _MonsterIR *p_Var4;
  _MonsterCombatAttributes *p_Var5;
  int in_a2;
  _MonsterVars *mv;
  
  mv = (_MonsterVars *)instance->extraData;
  p_Var4 = MONSENSE_FindIR(mv,data->instance);
  if (p_Var4 == (_MonsterIR *)0x0) {
    if (in_a2 != 0) {
      p_Var4 = MONSENSE_FirstSense(instance,data->instance);
    }
  }
  else {
    if (in_a2 != 0) {
                    /* WARNING: Subroutine does not return */
      MON_GetTime(instance);
    }
  }
  if (p_Var4 != (_MonsterIR *)0x0) {
    p_Var4->mirFlags = p_Var4->mirFlags | (ushort)in_a2;
    p_Var4->distance = *(short *)&data->distance;
    sVar3 = (data->relativePosition).y;
    sVar1 = (data->relativePosition).z;
    (p_Var4->relativePosition).x = (data->relativePosition).x;
    (p_Var4->relativePosition).y = sVar3;
    (p_Var4->relativePosition).z = sVar1;
    p_Var5 = mv->subAttr->combatAttributes;
    if ((p_Var5 == (_MonsterCombatAttributes *)0x0) || (p_Var5->combatRange <= p_Var4->distance)) {
      uVar2 = p_Var4->mirConditions & 0xfff7;
    }
    else {
      uVar2 = p_Var4->mirConditions | 8;
    }
    p_Var4->mirConditions = uVar2;
    sVar3 = MATH3D_AngleFromPosToPos(&p_Var4->instance->position,&instance->position);
    if (((sVar3 - (p_Var4->instance->rotation).z) + 0x400U & 0xfff) < 0x801) {
      uVar2 = p_Var4->mirConditions & 0xfffd;
    }
    else {
      uVar2 = p_Var4->mirConditions | 2;
    }
    p_Var4->mirConditions = uVar2;
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(p_Var4->instance,10);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_SenseInstance(struct _Instance *instance /*$s3*/, struct evCollideInstanceStatsData *data /*$s2*/)
 // line 374, offset 0x80086300
	/* begin block 1 */
		// Start line: 375
		// Start offset: 0x80086300
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long flags; // $s0
	// 		unsigned long whatAmI; // $s4

		/* begin block 1.1 */
			// Start line: 387
			// Start offset: 0x80086358
			// Variables:
		// 		struct PhysObProperties *prop; // $s0

			/* begin block 1.1.1 */
				// Start line: 390
				// Start offset: 0x80086378
			/* end block 1.1.1 */
			// End offset: 0x80086418
			// End Line: 401
		/* end block 1.1 */
		// End offset: 0x80086418
		// End Line: 401
	/* end block 1 */
	// End offset: 0x800864D4
	// End Line: 419

	/* begin block 2 */
		// Start line: 735
	/* end block 2 */
	// End Line: 736

void MONSENSE_SenseInstance(_Instance *instance,evCollideInstanceStatsData *data)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(data->instance,1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_StartMonsterIRList(struct _Instance *instance /*$s5*/)
 // line 424, offset 0x800864f4
	/* begin block 1 */
		// Start line: 425
		// Start offset: 0x800864F4
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterIR *newlist; // $s2
	// 		int enemyOnList; // $s4

		/* begin block 1.1 */
			// Start line: 435
			// Start offset: 0x80086540
			// Variables:
		// 		struct _MonsterIR *next; // $s3
		/* end block 1.1 */
		// End offset: 0x800865C8
		// End Line: 463
	/* end block 1 */
	// End offset: 0x800865E4
	// End Line: 471

	/* begin block 2 */
		// Start line: 839
	/* end block 2 */
	// End Line: 840

void MONSENSE_StartMonsterIRList(_Instance *instance)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 *puVar5;
  
  pvVar4 = instance->extraData;
  bVar1 = false;
  if (*(char *)((int)pvVar4 + 0x14e) != '\0') {
    puVar2 = (undefined4 *)0x0;
    puVar5 = *(undefined4 **)((int)pvVar4 + 0x90);
    while (puVar3 = puVar5, puVar3 != (undefined4 *)0x0) {
      puVar5 = (undefined4 *)*puVar3;
      if (puVar3[2] != *(int *)(puVar3[1] + 0x10)) {
        *puVar3 = *(undefined4 *)((int)pvVar4 + 0x158);
        *(undefined4 **)((int)pvVar4 + 0x158) = puVar3;
        MONSENSE_SetupSenses(instance);
        return;
      }
      if ((*(ushort *)((int)puVar3 + 0x16) & 0xe0) == 0) {
                    /* WARNING: Subroutine does not return */
        MON_GetTime(instance);
      }
      *(undefined4 **)puVar3 = puVar2;
      *(ushort *)((int)puVar3 + 0x16) = *(ushort *)((int)puVar3 + 0x16) & 0xff1f;
      puVar2 = puVar3;
      if (*(undefined4 **)((int)pvVar4 + 0xc4) == puVar3) {
        bVar1 = true;
      }
    }
    if (!bVar1) {
      *(undefined4 *)((int)pvVar4 + 0xc4) = 0;
    }
    *(undefined4 **)((int)pvVar4 + 0x90) = puVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _MonsterIR * /*$ra*/ MONSENSE_GetMonsterIR(struct _MonsterVars *mv /*$a0*/)
 // line 476, offset 0x80086608
	/* begin block 1 */
		// Start line: 478
		// Start offset: 0x80086608
		// Variables:
	// 		struct _MonsterIR *mir; // $v1
	/* end block 1 */
	// End offset: 0x80086628
	// End Line: 488

	/* begin block 2 */
		// Start line: 975
	/* end block 2 */
	// End Line: 976

	/* begin block 3 */
		// Start line: 976
	/* end block 3 */
	// End Line: 977

	/* begin block 4 */
		// Start line: 978
	/* end block 4 */
	// End Line: 979

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
 // line 494, offset 0x80086630
	/* begin block 1 */
		// Start line: 496
		// Start offset: 0x80086630
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80086650
	// End Line: 505

	/* begin block 2 */
		// Start line: 1011
	/* end block 2 */
	// End Line: 1012

	/* begin block 3 */
		// Start line: 1012
	/* end block 3 */
	// End Line: 1013

	/* begin block 4 */
		// Start line: 1016
	/* end block 4 */
	// End Line: 1017

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
 // line 512, offset 0x8008665c
	/* begin block 1 */
		// Start line: 513
		// Start offset: 0x8008665C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *mir; // $a2

		/* begin block 1.1 */
			// Start line: 532
			// Start offset: 0x800866D0
			// Variables:
		// 		long angle; // $v0
		/* end block 1.1 */
		// End offset: 0x8008672C
		// End Line: 538
	/* end block 1 */
	// End offset: 0x80086760
	// End Line: 548

	/* begin block 2 */
		// Start line: 1049
	/* end block 2 */
	// End Line: 1050

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
    if (p_Var2 == (_MonsterIR *)0x0) {
      p_Var2 = mv->monsterIRList;
      mv->monsterIRList = p_Var2->next;
      p_Var2->next = mv->freeIRs;
      mv->freeIRs = p_Var2;
      p_Var2 = MONSENSE_FirstSense(instance,newenemy);
      if (p_Var2 == (_MonsterIR *)0x0) goto LAB_8008673c;
    }
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
LAB_8008673c:
  if ((mv->enemy == (_MonsterIR *)0x0) ||
     (newenemy == (_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0])) {
    mv->enemy = p_Var2;
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_ProcessIRList(struct _Instance *instance /*$s7*/)
 // line 554, offset 0x8008677c
	/* begin block 1 */
		// Start line: 555
		// Start offset: 0x8008677C
		// Variables:
	// 		struct _MonsterVars *mv; // $s4
	// 		struct _MonsterIR *mir; // $s0
	// 		struct _MonsterIR *closestEnemy; // $s1
	// 		struct _MonsterIR *closestLeader; // $s2
	// 		struct _MonsterIR *closestAlly; // $s3
	// 		struct _MonsterIR *player; // $s6
	// 		struct _MonsterCombatAttributes *combatAttr; // $s5
	/* end block 1 */
	// End offset: 0x80086968
	// End Line: 612

	/* begin block 2 */
		// Start line: 1138
	/* end block 2 */
	// End Line: 1139

/* WARNING: Removing unreachable block (ram,0x80086934) */
/* WARNING: Removing unreachable block (ram,0x8008693c) */
/* WARNING: Removing unreachable block (ram,0x8008694c) */
/* WARNING: Removing unreachable block (ram,0x8008695c) */

void MONSENSE_ProcessIRList(_Instance *instance)

{
  int *piVar1;
  int *piVar2;
  void *pvVar3;
  
  piVar2 = (int *)0x0;
  pvVar3 = instance->extraData;
  piVar1 = *(int **)((int)pvVar3 + 0x90);
  do {
    if (piVar1 == (int *)0x0) {
      *(undefined4 *)((int)pvVar3 + 0xc4) = 0;
      *(int **)((int)pvVar3 + 200) = piVar2;
      *(undefined4 *)((int)pvVar3 + 0xcc) = 0;
      return;
    }
    if (((_Instance *)piVar1[1])->instanceID == piVar1[2]) {
      if ((*(ushort *)((int)piVar1 + 0x16) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query((_Instance *)piVar1[1],1);
      }
      if (((*(ushort *)((int)piVar1 + 0x16) & 0x10) != 0) &&
         ((piVar2 == (int *)0x0 || (*(short *)(piVar1 + 5) < *(short *)((int)piVar2 + 0x14))))) {
        piVar2 = piVar1;
      }
      if ((*(ushort *)((int)piVar1 + 0x16) & 2) != 0) {
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query((_Instance *)piVar1[1],1);
      }
      *(ushort *)((int)piVar1 + 0x16) = *(ushort *)((int)piVar1 + 0x16) & 0xfeff;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_SetupSenses(struct _Instance *instance /*$s2*/)
 // line 630, offset 0x8008699c
	/* begin block 1 */
		// Start line: 631
		// Start offset: 0x8008699C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _MonsterAllegiances *allegiances; // $s0
	// 		int num; // $v0
	/* end block 1 */
	// End offset: 0x80086AF0
	// End Line: 697

	/* begin block 2 */
		// Start line: 1260
	/* end block 2 */
	// End Line: 1261

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  iVar1 = gNumMonsters * 4;
  instance->checkMask = instance->checkMask | 0xb;
  mv->enemy = (_MonsterIR *)0x0;
  mv->leader = (_MonsterIR *)0x0;
  *(_MonsterVars **)(&monsterSenseArray40 + iVar1) = mv;
  mv->senseIndex = (char)gNumMonsters;
  if (gNumMonsters == 0) {
    _lastSenseFrame = 0xffffffff;
  }
  gNumMonsters = gNumMonsters + 1;
  if ((*(uint *)((int)instance->data + 0x10) & 0x1804) == 0) {
    iVar1 = gNumMaterialMonsters + 1;
    gNumMaterialMonsters = iVar1;
  }
  else {
    iVar1 = gNumSpectralMonsters + 1;
    gNumSpectralMonsters = iVar1;
  }
  if (((6 < iVar1) && (instance->parent == (_Instance *)0x0)) &&
     (instance->currentStreamUnitID != instance->birthStreamUnitID)) {
    instance->flags = instance->flags | 0x20;
    instance->flags2 = instance->flags2 | 0x20000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_RemoveSenses(struct _Instance *instance /*$a0*/)
 // line 702, offset 0x80086b08
	/* begin block 1 */
		// Start line: 704
		// Start offset: 0x80086B08
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80086BA0
	// End Line: 723

	/* begin block 2 */
		// Start line: 1541
	/* end block 2 */
	// End Line: 1542

	/* begin block 3 */
		// Start line: 1542
	/* end block 3 */
	// End Line: 1543

	/* begin block 4 */
		// Start line: 1547
	/* end block 4 */
	// End Line: 1548

void MONSENSE_RemoveSenses(_Instance *instance)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  gNumMonsters = gNumMonsters + -1;
  if ((*(uint *)((int)instance->data + 0x10) & 0x1804) == 0) {
    gNumMaterialMonsters = gNumMaterialMonsters + -1;
  }
  else {
    gNumSpectralMonsters = gNumSpectralMonsters + -1;
  }
  iVar3 = (int)*(char *)((int)instance->extraData + 0x14f);
  if (iVar3 < gNumMonsters) {
    do {
      iVar2 = iVar3 + 1;
      iVar1 = *(int *)(&monsterSenseArray40 + iVar2 * 4);
      *(int *)(&monsterSenseArray40 + iVar3 * 4) = iVar1;
      *(undefined *)(iVar1 + 0x14f) = (char)iVar3;
      iVar3 = iVar2;
    } while (iVar2 < gNumMonsters);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_Radar(struct _Instance *instance /*$s0*/)
 // line 847, offset 0x80086ba8
	/* begin block 1 */
		// Start line: 848
		// Start offset: 0x80086BA8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct SVECTOR newPos; // stack offset -96
	// 		struct SVECTOR oldPos; // stack offset -88
	// 		struct _PCollideInfo pCollideInfo; // stack offset -80
	// 		int index; // $s3
	/* end block 1 */
	// End offset: 0x80086DC0
	// End Line: 919

	/* begin block 2 */
		// Start line: 1840
	/* end block 2 */
	// End Line: 1841

void MONSENSE_Radar(_Instance *instance)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  void *pvVar5;
  uint uVar6;
  SVECTOR local_60;
  SVECTOR local_58;
  _PCollideInfo local_50;
  
  pvVar5 = instance->extraData;
  uVar6 = (uint)*(byte *)((int)default_lightgroup.colorMatrix.m +
                         (uint)*(ushort *)((int)pvVar5 + 0xe2) + 8);
  iVar3 = uVar6 * 6;
  local_60.vx = (instance->position).x + *(short *)(&DAT_800cf63a + iVar3);
  local_60.vy = (instance->position).y + *(short *)(&DAT_800cf63c + iVar3);
  local_60.vz = (instance->position).z + 100;
  local_58.vx = (instance->position).x;
  local_58.vy = (instance->position).y;
  local_50.newPoint = &local_60;
  local_50.oldPoint = &local_58;
  local_50.collideType = 0x13f;
  local_58.vz = (instance->position).z + 100;
  PHYSICS_CheckLineInWorldMask(instance,&local_50);
  if (local_50.type == 0) {
    local_58.vx = (instance->position).x + *(short *)(&DAT_800cf63a + iVar3);
    local_58.vy = (instance->position).y + *(short *)(&DAT_800cf63c + iVar3);
    local_58.vz = (instance->position).z + -0x100;
    local_60.vx = (instance->position).x;
    local_60.vy = (instance->position).y;
    local_60.vz = (instance->position).z + -0x100;
    PHYSICS_CheckLineInWorld(instance,&local_50);
    if (local_50.type != 0) goto LAB_80086d10;
    *(ushort *)((int)pvVar5 + 0xe0) =
         *(ushort *)((int)pvVar5 + 0xe0) | (ushort)(1 << (uVar6 & 0x1f));
    uVar1 = 0x500;
  }
  else {
LAB_80086d10:
    *(ushort *)((int)pvVar5 + 0xe0) =
         *(ushort *)((int)pvVar5 + 0xe0) & ~(ushort)(1 << (uVar6 & 0x1f));
    if ((local_50.type == 3) &&
       ((*(ushort *)
          ((int)((local_50.inst)->node).prev[9].prev + (int)local_50.segment * 0x24 + 0x12) & 2) !=
        0)) {
      *(undefined2 *)((int)pvVar5 + uVar6 * 2 + 0xe4) = 0;
      goto LAB_80086d9c;
    }
    lVar4 = MATH3D_LengthXY((int)local_60.vx - (int)(instance->position).x,
                            (int)local_60.vy - (int)(instance->position).y);
    uVar1 = (undefined2)lVar4;
  }
  *(undefined2 *)((int)pvVar5 + uVar6 * 2 + 0xe4) = uVar1;
LAB_80086d9c:
  uVar2 = *(short *)((int)pvVar5 + 0xe2) + 1;
  *(ushort *)((int)pvVar5 + 0xe2) = uVar2;
  if (7 < uVar2) {
    *(undefined2 *)((int)pvVar5 + 0xe2) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MONSENSE_GetClosestFreeDirection(struct _Instance *instance /*$a0*/, short angle /*$t1*/, long range /*$a2*/)
 // line 924, offset 0x80086de4
	/* begin block 1 */
		// Start line: 925
		// Start offset: 0x80086DE4
		// Variables:
	// 		struct _MonsterVars *mv; // $t0
	// 		int bit; // $a1
	// 		int search; // $a0
	/* end block 1 */
	// End offset: 0x80086EE0
	// End Line: 958

	/* begin block 2 */
		// Start line: 2013
	/* end block 2 */
	// End Line: 2014

/* WARNING: Removing unreachable block (ram,0x80086e04) */

short MONSENSE_GetClosestFreeDirection(_Instance *instance,short angle,long range)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  
  pvVar5 = instance->extraData;
  uVar3 = (int)((int)angle + 0x100U & 0xfff) >> 9;
  iVar2 = 1;
  if ((*(short *)((int)pvVar5 + uVar3 * 2 + 0xe4) == 0) &&
     (uVar4 = uVar3 + 4 & 7, range < *(short *)((int)pvVar5 + uVar4 * 2 + 0xe4))) {
    return *(short *)(&radarDir + uVar4 * 6);
  }
  sVar1 = *(short *)((int)pvVar5 + uVar3 * 2 + 0xe4);
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
    sVar1 = *(short *)((int)pvVar5 + uVar3 * 2 + 0xe4);
    angle = *(short *)(&radarDir + uVar3 * 6);
  }
  return angle;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MONSENSE_GetDistanceInDirection(struct _Instance *instance /*$a0*/, short angle /*$a1*/)
 // line 963, offset 0x80086ee8
	/* begin block 1 */
		// Start line: 965
		// Start offset: 0x80086EE8
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int bit; // $v0
	/* end block 1 */
	// End offset: 0x80086F08
	// End Line: 966

	/* begin block 2 */
		// Start line: 2096
	/* end block 2 */
	// End Line: 2097

	/* begin block 3 */
		// Start line: 2097
	/* end block 3 */
	// End Line: 2098

	/* begin block 4 */
		// Start line: 2098
	/* end block 4 */
	// End Line: 2099

/* WARNING: Removing unreachable block (ram,0x80086f04) */

int MONSENSE_GetDistanceInDirection(_Instance *instance,short angle)

{
  return (int)*(short *)((int)instance->extraData +
                        ((int)((int)angle + 0x100U & 0xfff) >> 9) * 2 + 0xe4);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_DoSenses(struct _Instance *instance /*$s1*/)
 // line 974, offset 0x80086f20
	/* begin block 1 */
		// Start line: 975
		// Start offset: 0x80086F20
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		static int doneThisFrame; // offset 0x44
	/* end block 1 */
	// End offset: 0x80087004
	// End Line: 1005

	/* begin block 2 */
		// Start line: 2119
	/* end block 2 */
	// End Line: 2120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MONSENSE_DoSenses(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MONSENSE_ProcessIRList(instance);
  if (_lastSenseFrame < theCamera.focusRotation._0_4_) {
    if (_lastSenseFrame < theCamera.focusRotation._0_4_ + -1) {
                    /* WARNING: Subroutine does not return */
      memset(&monsterSensed,0,0x28);
    }
    default_lightgroup.colorMatrix._16_4_ = 0;
  }
  if ((default_lightgroup.colorMatrix._16_4_ == 0) &&
     ((&monsterSensed)[*(char *)((int)pvVar1 + 0x14f)] == '\0')) {
    _lastSenseFrame = theCamera.focusRotation._0_4_;
    (&monsterSensed)[*(char *)((int)pvVar1 + 0x14f)] = '\x01';
    default_lightgroup.colorMatrix._16_4_ = 1;
    *(undefined *)((int)pvVar1 + 0x14e) = 1;
    if ((*(uint *)((int)pvVar1 + 4) & 0x20000000) == 0) {
      MONSENSE_Radar(instance);
    }
  }
  else {
    *(undefined *)((int)pvVar1 + 0x14e) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONSENSE_AdjustRadarFromObjects(struct _Instance *instance /*$s3*/)
 // line 1010, offset 0x80087018
	/* begin block 1 */
		// Start line: 1011
		// Start offset: 0x80087018
		// Variables:
	// 		struct _MonsterVars *mv; // $s4
	// 		struct _Instance *physob; // $s2

		/* begin block 1.1 */
			// Start line: 1019
			// Start offset: 0x80087068
			// Variables:
		// 		struct PhysObProperties *prop; // $s1

			/* begin block 1.1.1 */
				// Start line: 1022
				// Start offset: 0x80087080

				/* begin block 1.1.1.1 */
					// Start line: 1028
					// Start offset: 0x800870BC
					// Variables:
				// 		long dist; // $s0

					/* begin block 1.1.1.1.1 */
						// Start line: 1033
						// Start offset: 0x800870F0
						// Variables:
					// 		int i; // $v1
					// 		int min; // $a1
					// 		int max; // $a2
					// 		int ang; // $s0
					/* end block 1.1.1.1.1 */
					// End offset: 0x800871CC
					// End Line: 1060
				/* end block 1.1.1.1 */
				// End offset: 0x800871CC
				// End Line: 1061
			/* end block 1.1.1 */
			// End offset: 0x800871CC
			// End Line: 1063
		/* end block 1.1 */
		// End offset: 0x800871CC
		// End Line: 1064
	/* end block 1 */
	// End offset: 0x800871DC
	// End Line: 1066

	/* begin block 2 */
		// Start line: 2191
	/* end block 2 */
	// End Line: 2192

	/* begin block 3 */
		// Start line: 2195
	/* end block 3 */
	// End Line: 2196

/* WARNING: Removing unreachable block (ram,0x8008712c) */
/* WARNING: Removing unreachable block (ram,0x80087144) */

void MONSENSE_AdjustRadarFromObjects(_Instance *instance)

{
  short sVar1;
  short sVar2;
  int iVar3;
  long x;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  
  iVar8 = *(int *)(theCamera.core.vvNormalWorVecMat[1].t[2] + 4);
  pvVar9 = instance->extraData;
  while (iVar8 != 0) {
    if ((((*(uint *)(*(int *)(iVar8 + 0x1c) + 0x2c) & 0x40000) != 0) &&
        (iVar7 = *(int *)(iVar8 + 0x24), *(short *)(iVar7 + 2) == 3)) &&
       ((*(ushort *)(iVar7 + 8) & 0x40) != 0)) {
      iVar3 = (int)*(short *)(iVar8 + 0x60) - (int)(instance->position).z;
      if (iVar3 < 0) {
        iVar3 = -iVar3;
      }
      if ((iVar3 < 400) &&
         (x = MATH3D_LengthXY((int)*(short *)(iVar8 + 0x5c) - (int)(instance->position).x,
                              (int)*(short *)(iVar8 + 0x5e) - (int)(instance->position).y),
         x < (int)((uint)*(ushort *)(iVar7 + 0x1e) + 0x500))) {
        sVar1 = MATH3D_AngleFromPosToPos(&instance->position,(_Position *)(iVar8 + 0x5c));
        sVar2 = MATH3D_FastAtan2((uint)*(ushort *)(iVar7 + 0x1e),x);
        uVar6 = (int)((int)sVar1 + (int)sVar2 + 0x100U & 0xfff) >> 9;
        uVar5 = (int)(((int)sVar1 - (int)sVar2) + 0x100U & 0xfff) >> 9;
        if (uVar5 < uVar6) {
          if (uVar5 <= uVar6) {
            pvVar4 = (void *)(uVar5 * 2 + (int)pvVar9);
            do {
              *(undefined2 *)((int)pvVar4 + 0xe4) = 0;
              uVar5 = uVar5 + 1;
              pvVar4 = (void *)((int)pvVar4 + 2);
            } while ((int)uVar5 <= (int)uVar6);
          }
        }
        else {
          iVar7 = 0;
          pvVar4 = pvVar9;
          do {
            *(undefined2 *)((int)pvVar4 + 0xe4) = 0;
            iVar7 = iVar7 + 1;
            pvVar4 = (void *)((int)pvVar4 + 2);
          } while (iVar7 <= (int)uVar6);
          if (uVar5 < 8) {
            pvVar4 = (void *)(uVar5 * 2 + (int)pvVar9);
            do {
              *(undefined2 *)((int)pvVar4 + 0xe4) = 0;
              uVar5 = uVar5 + 1;
              pvVar4 = (void *)((int)pvVar4 + 2);
            } while ((int)uVar5 < 8);
          }
        }
      }
    }
    iVar8 = *(int *)(iVar8 + 8);
  }
  return;
}





