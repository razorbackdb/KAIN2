#include "THISDUST.H"
#include "MONAPI.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MonsterProcess(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 165, offset 0x8007da70
	/* begin block 1 */
		// Start line: 166
		// Start offset: 0x8007DA70
		// Variables:
	// 		struct _MonsterState *state; // $s0
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *attributes; // $v0
	/* end block 1 */
	// End offset: 0x8007DB8C
	// End Line: 234

	/* begin block 2 */
		// Start line: 330
	/* end block 2 */
	// End Line: 331

void MonsterProcess(_Instance *instance,GameTracker *gameTracker)

{
  _MonsterState *p_Var1;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar2;
  u_int *puVar3;
  
  puVar3 = (u_int *)instance->extraData;
  if (((puVar3 != (u_int *)0x0) && (instance->data != (void *)0x0)) && ((*puVar3 & 0x80000) == 0)) {
    MONSENSE_DoSenses(instance);
    MON_DoCombatTimers(instance);
    p_Var1 = MONTABLE_GetStateFuncs(instance,instance->currentMainState);
    instance->flags2 = instance->flags2 & 0xffffffed;
    if ((*puVar3 & 0x80) == 0) {
      G2EmulationInstancePlayAnimation(instance);
    }
    (*p_Var1->stateFunction)(instance);
    if ((*puVar3 & 1) != 0) {
      p_Var1 = MONTABLE_GetStateFuncs(instance,instance->currentMainState);
      (*p_Var1->entryFunction)(instance);
    }
    *puVar3 = *puVar3 & 0xffffffbe;
    if ((instance->flags & 0x200U) != 0) {
      pTVar2 = MONTABLE_GetDamageEffectFunc(instance);
      (*pTVar2)(instance,0);
    }
    MON_ProcessLookAt(instance);
    MON_ProcessSpecialFade(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 240, offset 0x8007dba4
	/* begin block 1 */
		// Start line: 241
		// Start offset: 0x8007DBA4
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $s2
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 259
			// Start offset: 0x8007DC10
		/* end block 1.1 */
		// End offset: 0x8007DC10
		// End Line: 279

		/* begin block 1.2 */
			// Start line: 346
			// Start offset: 0x8007DD68
		/* end block 1.2 */
		// End offset: 0x8007DD94
		// End Line: 351
	/* end block 1 */
	// End offset: 0x8007DD94
	// End Line: 353

	/* begin block 2 */
		// Start line: 485
	/* end block 2 */
	// End Line: 486

void MonsterInit(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  TDRFuncPtr_MONTABLE_GetCleanUpFunc pTVar2;
  _G2AnimKeylist_Type *keylist;
  TDRFuncPtr_MONTABLE_GetInitFunc pTVar3;
  _MonsterState *p_Var4;
  u_int *__s;
  int *piVar5;
  
  piVar5 = (int *)instance->data;
  if ((instance->flags & 0x20000U) == 0) {
    if ((piVar5 != (int *)0x0) && (*piVar5 == -0x531fff9c)) {
      __s = (u_int *)MEMPACK_Malloc(0x25c,'\x17');
      *(u_int **)&instance->extraData = __s;
      if (instance->instanceID == 0) {
        if (__s == (u_int *)0x0) {
          return;
        }
        goto LAB_8007dc30;
      }
      if (__s != (u_int *)0x0) {
        memset(__s,0,0x25c);
        InitMessageQueue((__MessageQueue *)(__s + 2));
        instance->currentMainState = -1;
        *(char *)((int)__s + 0x162) = -1;
        sVar1 = (instance->position).z;
        __s[0x4a] = *(u_int *)&instance->position;
        *(short *)(__s + 0x4b) = sVar1;
        __s[0x68] = 0xffffffff;
        __s[0x42] = 0;
        instance->flags = instance->flags | 0x10040;
        if ((piVar5[4] & 0x10000U) == 0) {
          instance->flags2 = instance->flags2 | 0x100;
        }
        instance->maxXVel = 400;
        instance->maxYVel = 400;
        instance->maxZVel = 400;
        instance->xVel = 0;
        instance->yVel = 0;
        instance->zVel = 0;
        MONTABLE_SetQueryFunc(instance);
        MONTABLE_SetMessageFunc(instance);
        MON_ProcessIntro(instance);
        *(undefined2 *)((int)__s + 0x142) = *(undefined2 *)(__s + 0x50);
        MON_TurnOnAllSpheres(instance);
        MON_TurnOffWeaponSpheres(instance);
        MONSENSE_SetupSenses(instance);
        MON_AnimInit(instance);
        pTVar3 = MONTABLE_GetInitFunc(instance);
        (*pTVar3)(instance);
        if ((*__s & 1) == 0) {
          return;
        }
        p_Var4 = MONTABLE_GetStateFuncs(instance,instance->currentMainState);
        *__s = *__s & 0xfffffffe;
        (*p_Var4->entryFunction)(instance);
        return;
      }
    }
    instance->data = (void *)0x0;
    keylist = G2Instance_GetKeylist(instance,0);
    G2Anim_SwitchToKeylist(&instance->anim,keylist,0);
  }
  else {
    __s = (u_int *)instance->extraData;
    pTVar2 = MONTABLE_GetCleanUpFunc(instance);
    (*pTVar2)(instance);
    MONSENSE_RemoveSenses(instance);
LAB_8007dc30:
    MEMPACK_Free((char *)__s);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SendHitObject(struct _Instance *instance /*$s1*/, struct _Instance *hit /*$s0*/, int type /*$s2*/)
 // line 355, offset 0x8007ddac
	/* begin block 1 */
		// Start line: 356
		// Start offset: 0x8007DDAC
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	// 		int i; // $a0

		/* begin block 1.1 */
			// Start line: 362
			// Start offset: 0x8007DDFC
			// Variables:
		// 		struct evMonsterHitObjectData *data1; // $v0
		/* end block 1.1 */
		// End offset: 0x8007DE14
		// End Line: 365

		/* begin block 1.2 */
			// Start line: 374
			// Start offset: 0x8007DE44
			// Variables:
		// 		struct evMonsterHitObjectData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x8007DE68
		// End Line: 378
	/* end block 1 */
	// End offset: 0x8007DE68
	// End Line: 379

	/* begin block 2 */
		// Start line: 726
	/* end block 2 */
	// End Line: 727

/* WARNING: Type propagation algorithm not settling */

void SendHitObject(_Instance *instance,_Instance *hit,int type)

{
  _Instance **Data;
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  iVar2 = *(int *)((int)pvVar3 + 8);
  do {
    pvVar1 = (void *)((int)pvVar3 + iVar2 * 8);
    if ((*(int *)((int)pvVar1 + 0x10) == 0x1000008) &&
       (*(_Instance **)&(*(_Instance **)((int)pvVar1 + 0x14))->node == hit)) break;
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x10) {
      iVar2 = 0;
    }
  } while (iVar2 != *(int *)((int)pvVar3 + 0xc));
  if (iVar2 == *(int *)((int)pvVar3 + 0xc)) {
    Data = (_Instance **)CIRC_Alloc(8);
    *Data = hit;
    *(int *)(Data + 1) = type;
    INSTANCE_Post(instance,0x1000008,(int)Data);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 385, offset 0x8007de80
	/* begin block 1 */
		// Start line: 386
		// Start offset: 0x8007DE80
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s1
	// 		struct _MonsterVars *mv; // $s5

		/* begin block 1.1 */
			// Start line: 395
			// Start offset: 0x8007DECC
			// Variables:
		// 		struct _HSphere *s0; // $v0

			/* begin block 1.1.1 */
				// Start line: 409
				// Start offset: 0x8007DF04
				// Variables:
			// 		struct _HSphere *s1; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 412
					// Start offset: 0x8007DF1C
					// Variables:
				// 		struct _Instance *inst1; // $s4
				// 		int power; // $s0
				/* end block 1.1.1.1 */
				// End offset: 0x8007DFDC
				// End Line: 433
			/* end block 1.1.1 */
			// End offset: 0x8007DFDC
			// End Line: 433

			/* begin block 1.1.2 */
				// Start line: 449
				// Start offset: 0x8007DFF8
				// Variables:
			// 		int move; // $s6

				/* begin block 1.1.2.1 */
					// Start line: 455
					// Start offset: 0x8007E030
					// Variables:
				// 		struct _HSphere *hsphere; // $s0
				/* end block 1.1.2.1 */
				// End offset: 0x8007E084
				// End Line: 463

				/* begin block 1.1.2.2 */
					// Start line: 493
					// Start offset: 0x8007E0F4
					// Variables:
				// 		struct BSPTree *bsp; // $s0

					/* begin block 1.1.2.2.1 */
						// Start line: 500
						// Start offset: 0x8007E144
						// Variables:
					// 		struct evMonsterHitTerrainData *data; // $s4
					// 		struct Level *level; // $s3
					// 		struct Intro *impaler; // $v0
					// 		struct _TFace *tface; // $s0

						/* begin block 1.1.2.2.1.1 */
							// Start line: 530
							// Start offset: 0x8007E284
							// Variables:
						// 		struct _CollideInfo parentCI; // stack offset -80
						/* end block 1.1.2.2.1.1 */
						// End offset: 0x8007E2F0
						// End Line: 537
					/* end block 1.1.2.2.1 */
					// End offset: 0x8007E314
					// End Line: 541
				/* end block 1.1.2.2 */
				// End offset: 0x8007E318
				// End Line: 546
			/* end block 1.1.2 */
			// End offset: 0x8007E360
			// End Line: 572
		/* end block 1.1 */
		// End offset: 0x8007E360
		// End Line: 573
	/* end block 1 */
	// End offset: 0x8007E360
	// End Line: 577

	/* begin block 2 */
		// Start line: 792
	/* end block 2 */
	// End Line: 793

void MonsterCollide(_Instance *instance,GameTracker *gameTracker)

{
  bool bVar1;
  undefined2 uVar2;
  u_long uVar3;
  Intro *pIVar4;
  long lVar5;
  _CollideInfo *p_Var6;
  void **Data;
  int Data_00;
  void *pvVar7;
  void *pvVar8;
  int Data_01;
  BSPTree *bsp;
  void *pvVar9;
  _CollideInfo *collideInfo;
  u_int uVar10;
  _Terrain *p_Var11;
  _Instance *Inst;
  u_int *puVar12;
  void *local_50 [4];
  _Instance *local_40;
  _Instance *local_3c;
  
  collideInfo = (_CollideInfo *)instance->collideInfo;
  puVar12 = (u_int *)instance->extraData;
  if (instance->data == (void *)0x0) {
    return;
  }
  if (collideInfo->type0 != '\x01') {
    return;
  }
  if (*(char *)((int)collideInfo->prim0 + 4) == '\t') {
    uVar10 = puVar12[0x2e];
    if (uVar10 == 0) {
      return;
    }
    if (collideInfo->type1 != '\x01') {
      return;
    }
    if (*(char *)((int)collideInfo->prim1 + 4) != '\b') {
      return;
    }
    Data_01 = (int)*(char *)(uVar10 + 7);
    Inst = (_Instance *)collideInfo->inst1;
    if ((*puVar12 & 0x20000000) != 0) {
      Data_01 = Data_01 << 1;
    }
    MON_TurnOffWeaponSpheres(instance);
    Data_01 = Data_01 * 0x100;
    Data_00 = Data_01;
    if (Data_01 < 0) {
      Data_00 = Data_01 + 0x7f;
    }
    Data_00 = SetFXHitData(instance,(u_int)(byte)collideInfo->segment,Data_00 >> 7,0x100);
    INSTANCE_Post(Inst,0x400000,Data_00);
    Data_01 = SetMonsterHitData(instance,(_Instance *)0x0,Data_01,(int)*(short *)(uVar10 + 4),
                                (int)*(char *)(uVar10 + 6));
    INSTANCE_Post(Inst,0x1000000,Data_01);
    uVar10 = puVar12[0x31];
    if (Inst != *(_Instance **)(uVar10 + 4)) {
      return;
    }
    if ((*puVar12 & 0x10000000) != 0) {
      *(ushort *)(uVar10 + 0x16) = *(ushort *)(uVar10 + 0x16) | 0x1000;
    }
    *(ushort *)(puVar12[0x31] + 0x18) = *(ushort *)(puVar12[0x31] + 0x18) | 0x100;
    return;
  }
  bVar1 = true;
  switch(collideInfo->type1) {
  case '\x01':
    pvVar9 = collideInfo->prim1;
    SendHitObject(instance,(_Instance *)collideInfo->inst1,1);
    if (*(char *)((int)pvVar9 + 4) != '\t') {
      if ((*(int *)&instance->position == *(int *)&instance->oldPos) &&
         ((instance->position).z == (instance->oldPos).z)) {
        bVar1 = false;
      }
      break;
    }
    goto LAB_8007e314;
  case '\x02':
    SendHitObject(instance,(_Instance *)collideInfo->inst1,2);
    break;
  case '\x03':
    bsp = (BSPTree *)collideInfo->inst1;
    if (((bsp->flags & 0xe0U) != 0) && ((instance->checkMask & 0x20) != 0)) {
      MON_CheckTerrainAndRespond(instance,bsp,(_TFace *)collideInfo->prim1);
    }
    if ((bsp->flags & 0x102U) == 0) {
      Data = (void **)CIRC_Alloc(0x10);
      pvVar9 = collideInfo->prim1;
      p_Var11 = (_Terrain *)collideInfo->level;
      if (*(short *)((int)pvVar9 + 10) == -1) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined2 *)
                 ((int)&(*(_Terrain **)p_Var11)->StartTextureList->attr +
                 (u_int)*(ushort *)((int)pvVar9 + 10));
      }
      *(undefined2 *)(Data + 3) = uVar2;
      *Data = pvVar9;
      uVar3 = INSTANCE_Query(instance,1);
      if ((((uVar3 & 4) == 0) || (*(ushort *)((int)pvVar9 + 10) == 0xffff)) ||
         ((*(ushort *)
            ((int)&(*(_Terrain **)p_Var11)->StartTextureList->attr +
            (u_int)*(ushort *)((int)pvVar9 + 10)) & 0x1000) == 0)) {
        pIVar4 = MON_TestForTerrainImpale(instance,*(_Terrain **)p_Var11);
        if (pIVar4 == (Intro *)0x0) {
          lVar5 = COLLIDE_FindCollisionFaceNormal(collideInfo,(_Normal *)(Data + 1));
          if (lVar5 != 0) {
            (collideInfo->offset).x = (collideInfo->offset).x + (*(short *)(Data + 1) >> 10);
            (collideInfo->offset).y = (collideInfo->offset).y + (*(short *)((int)Data + 6) >> 10);
            INSTANCE_Post(instance,0x1000007,(int)Data);
          }
        }
        else {
          INSTANCE_Post(instance,0x100001c,pIVar4->UniqueID);
          (collideInfo->offset).x = 0;
          (collideInfo->offset).y = 0;
        }
        *puVar12 = *puVar12 | 8;
        Data = (void **)local_50;
        if (instance->LinkParent != (_Instance *)0x0) {
          p_Var6 = collideInfo;
          do {
            pvVar9 = *(void **)&p_Var6->flags;
            pvVar7 = p_Var6->prim0;
            pvVar8 = p_Var6->prim1;
            *Data = p_Var6->level;
            Data[1] = pvVar9;
            Data[2] = pvVar7;
            Data[3] = pvVar8;
            p_Var6 = (_CollideInfo *)&p_Var6->inst0;
            Data = Data + 4;
          } while (p_Var6 != collideInfo + 1);
          if (local_40 == instance) {
            local_40 = instance->LinkParent;
          }
          if (local_3c == instance) {
            local_3c = instance->LinkParent;
          }
          Data_01 = SetCollideInfoData((_CollideInfo *)local_50);
          INSTANCE_Post(instance->LinkParent,0x200004,Data_01);
        }
        break;
      }
    }
LAB_8007e314:
    bVar1 = false;
    break;
  case '\x05':
    if (((collideInfo->offset).z < -0x32) &&
       ((*(u_int *)((int)instance->data + 0x10) & 0x10004) == 0)) {
      INSTANCE_Post(instance,0x40017,6);
    }
    SendHitObject(instance,(_Instance *)collideInfo->inst1,5);
  }
  if (bVar1) {
    (instance->position).x = (instance->position).x + (collideInfo->offset).x;
    (instance->position).y = (instance->position).y + (collideInfo->offset).y;
    (instance->position).z = (instance->position).z + (collideInfo->offset).z;
    COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)&collideInfo->offset);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterAdditionalCollide(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 582, offset 0x8007e388
	/* begin block 1 */
		// Start line: 1204
	/* end block 1 */
	// End Line: 1205

void MonsterAdditionalCollide(_Instance *instance,GameTracker *gameTracker)

{
  if (instance->data != (void *)0x0) {
    MON_CheckEnvironment(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MonsterQuery(struct _Instance *instance /*$s1*/, unsigned long query /*$a1*/)
 // line 591, offset 0x8007e3b8
	/* begin block 1 */
		// Start line: 592
		// Start offset: 0x8007E3B8
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	// 		struct _MonsterAttributes *ma; // $s0
	// 		unsigned long ret; // $a0

		/* begin block 1.1 */
			// Start line: 604
			// Start offset: 0x8007E404
			// Variables:
		// 		struct evShadowSegmentData *shadowData; // $v0
		/* end block 1.1 */
		// End offset: 0x8007E404
		// End Line: 605

		/* begin block 1.2 */
			// Start line: 680
			// Start offset: 0x8007E578
			// Variables:
		// 		struct _MonsterSaveInfo *saveInfo; // $s0
		/* end block 1.2 */
		// End offset: 0x8007E578
		// End Line: 680
	/* end block 1 */
	// End offset: 0x8007E5D8
	// End Line: 697

	/* begin block 2 */
		// Start line: 1222
	/* end block 2 */
	// End Line: 1223

u_long MonsterQuery(_Instance *instance,u_long query)

{
  MATRIX *pMVar1;
  _MonsterSaveInfo *saveData;
  u_int uVar2;
  u_int *puVar3;
  void *pvVar4;
  
  pvVar4 = instance->data;
  puVar3 = (u_int *)instance->extraData;
  pMVar1 = (MATRIX *)0x0;
  if (pvVar4 != (void *)0x0) {
    switch(query) {
    case 0:
      uVar2 = *puVar3;
      pMVar1 = (MATRIX *)0x40000000;
      if ((uVar2 & 0x200) == 0) {
        pMVar1 = (MATRIX *)0x12000000;
        if (instance->currentMainState != 0x1e) {
          pMVar1 = (MATRIX *)0x0;
          if ((uVar2 & 0x200000) == 0) {
            if ((((uVar2 & 0x10) != 0) || (puVar3[0x31] == 0)) ||
               (instance->currentMainState == 0x18)) {
              if (*(char *)(puVar3[0x59] + 0x29) == '\0') {
                pMVar1 = (MATRIX *)0x10000000;
              }
              else {
                pMVar1 = (MATRIX *)0x90000000;
              }
            }
          }
          else {
            pMVar1 = (MATRIX *)0x4000000;
          }
          if ((*puVar3 & 0x100) != 0) {
            pMVar1 = (MATRIX *)((u_int)pMVar1 | 0x20000000);
          }
        }
      }
      break;
    case 1:
      pMVar1 = *(MATRIX **)((int)pvVar4 + 0x10);
      break;
    case 2:
      pMVar1 = (MATRIX *)(u_int)*(byte *)(puVar3[0x59] + 0x27);
      break;
    default:
      pMVar1 = (MATRIX *)GenericQuery(instance,query);
      break;
    case 9:
      pMVar1 = (MATRIX *)&DAT_00000020;
      if ((*puVar3 & 0x400) != 0) {
        pMVar1 = (MATRIX *)&DAT_00000010;
      }
      break;
    case 10:
      pMVar1 = (MATRIX *)puVar3[0x42];
      break;
    case 0xc:
      if (instance->matrix == (MATRIX *)0x0) {
        pMVar1 = (MATRIX *)0x0;
      }
      else {
        pMVar1 = instance->matrix + *(byte *)((int)pvVar4 + 0x19);
      }
      break;
    case 0xd:
      pMVar1 = (MATRIX *)0x0;
      if (instance->matrix != (MATRIX *)0x0) {
        pMVar1 = instance->matrix + 1;
      }
      break;
    case 0xf:
      pMVar1 = (MATRIX *)(u_int)*(byte *)((int)pvVar4 + 0x1a);
      break;
    case 0x18:
      saveData = (_MonsterSaveInfo *)CIRC_Alloc(0x10);
      MON_SetUpSaveInfo(instance,saveData);
      pMVar1 = (MATRIX *)SetControlSaveDataData(0x10,saveData);
      break;
    case 0x19:
      pMVar1 = (MATRIX *)(int)*(short *)(puVar3 + 0x51);
      break;
    case 0x21:
      pMVar1 = (MATRIX *)(*puVar3 >> 0x1d & 1);
      break;
    case 0x23:
      pMVar1 = (MATRIX *)PeekMessageQueue((__MessageQueue *)(puVar3 + 2));
      break;
    case 0x25:
      pMVar1 = (MATRIX *)&UNK_00000001;
      break;
    case 0x26:
      pMVar1 = (MATRIX *)SetShadowSegmentData(2);
      pMVar1->m[1] = (ushort)*(byte *)((int)pvVar4 + 0x20);
      *(ushort *)((int)pMVar1->m + 6) = (ushort)*(byte *)((int)pvVar4 + 0x21);
    }
  }
  return (u_long)pMVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterMessage(struct _Instance *instance /*$s2*/, unsigned long message /*$s1*/, unsigned long data /*$s3*/)
 // line 703, offset 0x8007e5ec
	/* begin block 1 */
		// Start line: 704
		// Start offset: 0x8007E5EC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 721
			// Start offset: 0x8007E65C
		/* end block 1.1 */
		// End offset: 0x8007E668
		// End Line: 724

		/* begin block 1.2 */
			// Start line: 746
			// Start offset: 0x8007E744
		/* end block 1.2 */
		// End offset: 0x8007E744
		// End Line: 748

		/* begin block 1.3 */
			// Start line: 753
			// Start offset: 0x8007E760
		/* end block 1.3 */
		// End offset: 0x8007E760
		// End Line: 755
	/* end block 1 */
	// End offset: 0x8007E818
	// End Line: 793

	/* begin block 2 */
		// Start line: 1449
	/* end block 2 */
	// End Line: 1450

void MonsterMessage(_Instance *instance,u_long message,u_long data)

{
  u_int uVar1;
  int iVar2;
  undefined4 local_18;
  u_int *puVar3;
  undefined4 local_14;
  
  puVar3 = (u_int *)instance->extraData;
  if (puVar3 != (u_int *)0x0) {
    if ((undefined *)message == &DAT_00100007) {
      MON_GetSaveInfo(instance,*(_MonsterSaveInfo **)(data + 4));
    }
    else {
      if ((message == 0x1000020) && (uVar1 = puVar3[0x31], uVar1 != 0)) {
        *(ushort *)(uVar1 + 0x16) = *(ushort *)(uVar1 + 0x16) & 0xefff;
      }
    }
    if ((instance->flags2 & 0x4000000U) == 0) {
      if (message == 0x40013) {
        if (data == 0) {
          *puVar3 = *puVar3 & 0xfff7ffff;
        }
        else {
          *puVar3 = *puVar3 | 0x80000;
        }
      }
      else {
        if (message < 0x40014) {
          if (message == 0x4000b) {
            (instance->rotation).x = *(short *)data;
            (instance->rotation).y = *(short *)(data + 2);
            (instance->rotation).z = *(short *)(data + 4);
            return;
          }
          if (message < 0x4000c) {
            if (message == 0x4000a) {
              STREAM_SetInstancePosition(&gameTrackerX,instance,(evPositionData *)data);
              return;
            }
          }
          else {
            if (message == 0x4000e) {
              if (data == 0) {
                uVar1 = *puVar3 & 0xfffffffb;
              }
              else {
                uVar1 = *puVar3 | 4;
              }
              *puVar3 = uVar1;
              iVar2 = instance->currentMainState;
              if (((iVar2 != 1) && (iVar2 != 5)) && (iVar2 != 0x13)) {
                return;
              }
              MON_SwitchStateDoEntry(instance,(MonsterState)CONCAT44(local_14,local_18));
              return;
            }
          }
        }
        else {
          if (message == 0x200000) {
            MONSENSE_StartMonsterIRList(instance);
            return;
          }
          if (message < 0x200001) {
            if ((undefined *)message == &DAT_00100008) {
              MON_RelocateCoords(instance,(_SVector *)data);
              return;
            }
          }
          else {
            if (message == 0x200001) {
              MONSENSE_SenseInstance(instance,(evCollideInstanceStatsData *)data);
              return;
            }
          }
        }
        EnMessageQueueData((__MessageQueue *)(puVar3 + 2),message,data);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ AnimDistanceAndVel(struct Object *object /*$s1*/, struct _MonsterAnim *mAnim /*$s3*/)
 // line 798, offset 0x8007e834
	/* begin block 1 */
		// Start line: 799
		// Start offset: 0x8007E834
		// Variables:
	// 		struct _G2Anim_Type anim; // stack offset -216
	// 		struct _G2AnimSection_Type *animSection; // $s0
	// 		struct _G2AnimKeylist_Type *keylist; // $s2
	// 		long total; // $s0

		/* begin block 1.1 */
			// Start line: 819
			// Start offset: 0x8007E8D8
			// Variables:
		// 		struct _G2SVector3_Type dist; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x8007E978
		// End Line: 826
	/* end block 1 */
	// End offset: 0x8007E978
	// End Line: 828

	/* begin block 2 */
		// Start line: 1640
	/* end block 2 */
	// End Line: 1641

void AnimDistanceAndVel(Object *object,_MonsterAnim *mAnim)

{
  short intervalEnd;
  ushort uVar1;
  _G2Bool_Enum _Var2;
  long lVar3;
  _G2AnimKeylist_Type *keylist;
  _G2Anim_Type _Stack216;
  _G2SVector3_Type local_20;
  
  keylist = object->animList[mAnim->index[0]];
  G2Anim_Init(&_Stack216,*object->modelList);
  _Stack216.section[0].firstSeg = '\0';
  _Stack216.section[0].segCount = *(u_char *)&(*object->modelList)->numSegments;
  _Stack216.section[0].callback = (_func_8 *)0x0;
  _Stack216.section[0].callbackData = (void *)0x0;
  G2AnimSection_SetInterpInfo(_Stack216.section,(_G2AnimInterpInfo_Type *)0x0);
  G2AnimSection_SwitchToKeylistAtTime(_Stack216.section,keylist,(int)mAnim->index[0],0);
  _Var2 = G2Anim_SegmentHasActiveChannels(&_Stack216,0,0x700);
  if (_Var2 != G2FALSE) {
    intervalEnd = G2AnimKeylist_GetDuration(keylist);
    G2Anim_GetRootMotionOverInterval(&_Stack216,0,intervalEnd,&local_20);
    lVar3 = MATH3D_FastSqrt0((int)local_20.x * (int)local_20.x + (int)local_20.y * (int)local_20.y +
                             (int)local_20.z * (int)local_20.z);
    uVar1 = G2AnimKeylist_GetDuration(keylist);
    mAnim->distance = (ushort)lVar3;
    mAnim->velocity =
         (ushort)((int)((u_int)mAnim->playSpeed * lVar3 * 100) / ((int)((u_int)uVar1 << 0x10) >> 4));
  }
  G2Anim_Free(&_Stack216);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TranslateAnimList(struct Object *object /*$s5*/, struct _MonsterAnim *animList /*$a1*/, int numAnims /*$s6*/)
 // line 952, offset 0x8007e99c
	/* begin block 1 */
		// Start line: 953
		// Start offset: 0x8007E99C
		// Variables:
	// 		int i; // $s2

		/* begin block 1.1 */
			// Start line: 956
			// Start offset: 0x8007E9CC
			// Variables:
		// 		struct _MonsterAnim *animPtr; // $s3

			/* begin block 1.1.1 */
				// Start line: 964
				// Start offset: 0x8007E9DC
				// Variables:
			// 		int index; // $a0
			// 		struct _G2AnimKeylist_Type *keylist; // $s4
			/* end block 1.1.1 */
			// End offset: 0x8007EA5C
			// End Line: 999
		/* end block 1.1 */
		// End offset: 0x8007EA70
		// End Line: 1000
	/* end block 1 */
	// End offset: 0x8007EA70
	// End Line: 1001

	/* begin block 2 */
		// Start line: 1960
	/* end block 2 */
	// End Line: 1961

void TranslateAnimList(Object *object,_MonsterAnim *animList,int numAnims)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  _G2AnimKeylist_Type *keylist;
  
  if ((animList != (_MonsterAnim *)0x0) && (iVar5 = 0, 0 < numAnims)) {
    pbVar4 = &animList->startFrame;
    do {
      keylist = object->animList[(int)(char)pbVar4[5]];
      if ((int)(char)pbVar4[5] != -1) {
        AnimDistanceAndVel(object,animList);
        bVar1 = *pbVar4;
        sVar2 = G2AnimKeylist_GetDuration(keylist);
        if (((int)sVar2 / 100) * 0x10000 >> 0x10 <= (int)(u_int)bVar1) {
          iVar3 = G2AnimKeylist_GetKeyframeCount(keylist);
          *pbVar4 = (char)iVar3 - 1;
        }
      }
      iVar5 = iVar5 + 1;
      pbVar4 = pbVar4 + 0x10;
      animList = animList + 1;
    } while (iVar5 < numAnims);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterTranslateAnim(struct Object *object /*$s1*/)
 // line 1010, offset 0x8007ea98
	/* begin block 1 */
		// Start line: 1011
		// Start offset: 0x8007EA98
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $s0
	// 		int i; // $a3

		/* begin block 1.1 */
			// Start line: 1026
			// Start offset: 0x8007EAD8
			// Variables:
		// 		void *relocModule; // $v0
		/* end block 1.1 */
		// End offset: 0x8007EB04
		// End Line: 1051

		/* begin block 1.2 */
			// Start line: 1078
			// Start offset: 0x8007EB44
			// Variables:
		// 		struct _MonsterAttackAttributes *attackAttr; // $v1
		/* end block 1.2 */
		// End offset: 0x8007EB80
		// End Line: 1106

		/* begin block 1.3 */
			// Start line: 1109
			// Start offset: 0x8007EBA4
			// Variables:
		// 		struct _MonsterCombatAttributes *combatAttr; // $v1

			/* begin block 1.3.1 */
				// Start line: 1111
				// Start offset: 0x8007EBC8
				// Variables:
			// 		int largest; // $a2
			// 		int j; // $a1

				/* begin block 1.3.1.1 */
					// Start line: 1118
					// Start offset: 0x8007EBE4
					// Variables:
				// 		struct _MonsterAttackAttributes *attack; // $v0
				/* end block 1.3.1.1 */
				// End offset: 0x8007EC10
				// End Line: 1121
			/* end block 1.3.1 */
			// End offset: 0x8007EC28
			// End Line: 1124
		/* end block 1.3 */
		// End offset: 0x8007EC28
		// End Line: 1128
	/* end block 1 */
	// End offset: 0x8007EC3C
	// End Line: 1144

	/* begin block 2 */
		// Start line: 2115
	/* end block 2 */
	// End Line: 2116

void MonsterTranslateAnim(Object *object)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int *piVar7;
  
  piVar7 = (int *)object->data;
  if ((object->oflags2 & 0x10000000U) == 0) {
    if ((object->oflags & 0x8000000U) == 0) {
      MONTABLE_SetupTablePointer(object);
    }
    else {
      if ((object->relocModule == (void *)0x0) ||
         (*(char **)((int)object->relocModule + 0x18) != "May 25 1999")) {
        object->data = (void *)0x0;
        return;
      }
    }
    if ((piVar7 != (int *)0x0) && (*piVar7 == -0x531fff9c)) {
      TranslateAnimList(object,(_MonsterAnim *)piVar7[0x10],(int)*(char *)(piVar7 + 0xb));
      iVar6 = 0;
      if ('\0' < *(char *)((int)piVar7 + 0x2a)) {
        do {
          iVar3 = piVar7[0xe] + iVar6 * 0x20;
          if ((*(char *)(iVar3 + 0xe) <= *(char *)(iVar3 + 10)) ||
             (*(char *)(iVar3 + 0xe) <= *(char *)(iVar3 + 0xc))) {
            object->data = (void *)0x0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(char *)((int)piVar7 + 0x2a));
      }
      iVar6 = 0;
      if ('\0' < *(char *)((int)piVar7 + 0x29)) {
        do {
          iVar3 = *(int *)(iVar6 * 4 + piVar7[0xd]);
          if (*(short *)(iVar3 + 10) == 0) {
            iVar4 = 0;
            sVar5 = 0;
            if (0 < (int)*(char *)(iVar3 + 0x19)) {
              iVar2 = iVar3;
              sVar5 = 0;
              do {
                sVar1 = *(short *)(piVar7[0xe] + (int)*(char *)(iVar2 + 0x28) * 0x20);
                if (sVar5 < sVar1) {
                  sVar5 = sVar1;
                }
                iVar4 = iVar4 + 1;
                iVar2 = iVar3 + iVar4;
              } while (iVar4 < (int)*(char *)(iVar3 + 0x19));
            }
            *(short *)(iVar3 + 10) = sVar5 + 200;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(char *)((int)piVar7 + 0x29));
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterRelocateTune(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 1149, offset 0x8007ec50
	/* begin block 1 */
		// Start line: 1151
		// Start offset: 0x8007EC50
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $t0

		/* begin block 1.1 */
			// Start line: 1155
			// Start offset: 0x8007EC70
			// Variables:
		// 		int i; // $a3
		// 		struct _MonsterSubAttributes *subAttr; // $a2
		// 		struct _MonsterSubAttributes **pSubAttr; // $t1
		// 		struct _MonsterCombatAttributes **pCombatAttr; // $v0

			/* begin block 1.1.1 */
				// Start line: 1174
				// Start offset: 0x8007ED60
				// Variables:
			// 		int j; // $v1
			// 		struct _MonsterSubAttributes **oldSubAttr; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8007EE18
			// End Line: 1195
		/* end block 1.1 */
		// End offset: 0x8007EE64
		// End Line: 1199
	/* end block 1 */
	// End offset: 0x8007EE64
	// End Line: 1200

	/* begin block 2 */
		// Start line: 2456
	/* end block 2 */
	// End Line: 2457

	/* begin block 3 */
		// Start line: 2457
	/* end block 3 */
	// End Line: 2458

void MonsterRelocateTune(Object *object,long offset)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int **ppiVar5;
  int iVar6;
  int **ppiVar7;
  
  piVar2 = (int *)object->data;
  if ((piVar2 != (int *)0x0) && (*piVar2 == -0x531fff9c)) {
    iVar3 = 0;
    if (piVar2[1] != 0) {
      iVar3 = piVar2[1] + offset;
    }
    iVar4 = 0;
    piVar2[1] = iVar3;
    if (piVar2[2] != 0) {
      iVar4 = piVar2[2] + offset;
    }
    iVar3 = 0;
    piVar2[2] = iVar4;
    if (piVar2[3] != 0) {
      iVar3 = piVar2[3] + offset;
    }
    iVar4 = 0;
    piVar2[3] = iVar3;
    if (piVar2[0xc] != 0) {
      iVar4 = piVar2[0xc] + offset;
    }
    iVar3 = 0;
    piVar2[0xc] = iVar4;
    if (piVar2[0xd] != 0) {
      iVar3 = piVar2[0xd] + offset;
    }
    iVar4 = 0;
    piVar2[0xd] = iVar3;
    if (piVar2[0xe] != 0) {
      iVar4 = piVar2[0xe] + offset;
    }
    iVar3 = 0;
    piVar2[0xe] = iVar4;
    if (piVar2[0xf] != 0) {
      iVar3 = piVar2[0xf] + offset;
    }
    iVar4 = 0;
    piVar2[0xf] = iVar3;
    if (piVar2[0x10] != 0) {
      iVar4 = piVar2[0x10] + offset;
    }
    iVar3 = 0;
    piVar2[0x10] = iVar4;
    if (piVar2[0x11] != 0) {
      iVar3 = piVar2[0x11] + offset;
    }
    iVar4 = 0;
    piVar2[0x11] = iVar3;
    if (piVar2[0x12] != 0) {
      iVar4 = piVar2[0x12] + offset;
    }
    iVar3 = 0;
    piVar2[0x12] = iVar4;
    if (piVar2[0x13] != 0) {
      iVar3 = piVar2[0x13] + offset;
    }
    ppiVar7 = (int **)piVar2[0xc];
    iVar4 = 0;
    piVar2[0x13] = iVar3;
    if ('\0' < *(char *)(piVar2 + 10)) {
      do {
        piVar1 = (int *)0x0;
        if (*ppiVar7 != (int *)0x0) {
          piVar1 = (int *)((int)*ppiVar7 + offset);
        }
        iVar3 = 0;
        *ppiVar7 = piVar1;
        ppiVar5 = (int **)piVar2[0xc];
        if (0 < iVar4) {
          do {
            if (*ppiVar5 == piVar1) break;
            iVar3 = iVar3 + 1;
            ppiVar5 = ppiVar5 + 1;
          } while (iVar3 < iVar4);
        }
        if (iVar3 == iVar4) {
          iVar3 = 0;
          if (*piVar1 != 0) {
            iVar3 = *piVar1 + offset;
          }
          iVar6 = 0;
          *piVar1 = iVar3;
          if (piVar1[1] != 0) {
            iVar6 = piVar1[1] + offset;
          }
          iVar3 = 0;
          piVar1[1] = iVar6;
          if (piVar1[2] != 0) {
            iVar3 = piVar1[2] + offset;
          }
          iVar6 = 0;
          piVar1[2] = iVar3;
          if (piVar1[3] != 0) {
            iVar6 = piVar1[3] + offset;
          }
          iVar3 = 0;
          piVar1[3] = iVar6;
          if (piVar1[4] != 0) {
            iVar3 = piVar1[4] + offset;
          }
          piVar1[4] = iVar3;
        }
        iVar4 = iVar4 + 1;
        ppiVar7 = ppiVar7 + 1;
      } while (iVar4 < *(char *)(piVar2 + 10));
    }
    iVar3 = (int)*(char *)((int)piVar2 + 0x29);
    piVar2 = (int *)piVar2[0xd];
    while (iVar3 != 0) {
      iVar4 = 0;
      if (*piVar2 != 0) {
        iVar4 = *piVar2 + offset;
      }
      *piVar2 = iVar4;
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + 1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterRelocateInstanceObject(struct _Instance *instance /*$a0*/, long offset /*$a1*/)
 // line 1205, offset 0x8007ee6c
	/* begin block 1 */
		// Start line: 1207
		// Start offset: 0x8007EE6C
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x8007EF64
	// End Line: 1228

	/* begin block 2 */
		// Start line: 2598
	/* end block 2 */
	// End Line: 2599

	/* begin block 3 */
		// Start line: 2599
	/* end block 3 */
	// End Line: 2600

void MonsterRelocateInstanceObject(_Instance *instance,long offset)

{
  void *pvVar1;
  _func_4 *p_Var2;
  _func_5 *p_Var3;
  _func_2 *p_Var4;
  _func_2 *p_Var5;
  int iVar6;
  int iVar7;
  
  pvVar1 = instance->extraData;
  if (pvVar1 != (void *)0x0) {
    iVar6 = 0;
    if (*(int *)((int)pvVar1 + 0x164) != 0) {
      iVar6 = *(int *)((int)pvVar1 + 0x164) + offset;
    }
    iVar7 = 0;
    *(int *)((int)pvVar1 + 0x164) = iVar6;
    if (*(int *)((int)pvVar1 + 0xb8) != 0) {
      iVar7 = *(int *)((int)pvVar1 + 0xb8) + offset;
    }
    iVar6 = 0;
    *(int *)((int)pvVar1 + 0xb8) = iVar7;
    if (*(int *)((int)pvVar1 + 0xbc) != 0) {
      iVar6 = *(int *)((int)pvVar1 + 0xbc) + offset;
    }
    *(int *)((int)pvVar1 + 0xbc) = iVar6;
    if ((instance->object->oflags & 0x8000000U) != 0) {
      if (*(int *)((int)instance->object->relocModule + 0xc) != 0) {
        p_Var2 = (_func_4 *)0x0;
        if (instance->queryFunc != (_func_4 *)0x0) {
          p_Var2 = instance->queryFunc + offset;
        }
        instance->queryFunc = p_Var2;
      }
      if (*(int *)((int)instance->object->relocModule + 0x10) != 0) {
        p_Var3 = (_func_5 *)0x0;
        if (instance->messageFunc != (_func_5 *)0x0) {
          p_Var3 = instance->messageFunc + offset;
        }
        instance->messageFunc = p_Var3;
      }
      p_Var5 = instance->collideFunc;
      if (p_Var5 != MonsterCollide) {
        p_Var4 = (_func_2 *)0x0;
        if (p_Var5 != (_func_2 *)0x0) {
          p_Var4 = p_Var5 + offset;
        }
        instance->collideFunc = p_Var4;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_TurnHead(struct _Instance *instance /*$a0*/, short *rotx /*$a1*/, short *rotz /*$a2*/, struct GameTracker *gameTracker /*$a3*/)
 // line 1277, offset 0x8007ef6c
	/* begin block 1 */
		// Start line: 2551
	/* end block 1 */
	// End Line: 2552

void MONAPI_TurnHead(_Instance *instance,short *rotx,short *rotz,GameTracker *gameTracker)

{
  short sVar1;
  
  sVar1 = -0x300;
  if ((*rotx < -0x300) || (sVar1 = 0x200, 0x200 < *rotx)) {
    *rotx = sVar1;
  }
  if (*rotz < 0x401) {
    sVar1 = -0x400;
    if (-0x401 < *rotz) goto LAB_8007efc0;
  }
  else {
    sVar1 = 0x400;
  }
  *rotz = sVar1;
LAB_8007efc0:
  MON_LookInDirection(instance,-*rotx,*rotz);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_SetLookAround(struct _Instance *instance /*$a0*/)
 // line 1298, offset 0x8007efe8
	/* begin block 1 */
		// Start line: 1299
		// Start offset: 0x8007EFE8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007EFE8
	// End Line: 1299

	/* begin block 2 */
		// Start line: 2734
	/* end block 2 */
	// End Line: 2735

void MONAPI_SetLookAround(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_EnableHeadMove(instance);
  *(undefined4 *)((int)pvVar1 + 0x108) = 0x80000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_ResetLookAround(struct _Instance *instance /*$a0*/)
 // line 1307, offset 0x8007f018
	/* begin block 1 */
		// Start line: 1308
		// Start offset: 0x8007F018
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007F018
	// End Line: 1308

	/* begin block 2 */
		// Start line: 2752
	/* end block 2 */
	// End Line: 2753

void MONAPI_ResetLookAround(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_DisableHeadMove(instance);
  *(undefined4 *)((int)pvVar1 + 0x108) = 1;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MONAPI_OkToLookAround(struct _Instance *instance /*$a0*/)
 // line 1316, offset 0x8007f048
	/* begin block 1 */
		// Start line: 2770
	/* end block 1 */
	// End Line: 2771

	/* begin block 2 */
		// Start line: 2771
	/* end block 2 */
	// End Line: 2772

long MONAPI_OkToLookAround(_Instance *instance)

{
  return (u_int)(instance->currentMainState == 2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen /*$a0*/)
 // line 1321, offset 0x8007f05c
	/* begin block 1 */
		// Start line: 2780
	/* end block 1 */
	// End Line: 2781

	/* begin block 2 */
		// Start line: 2783
	/* end block 2 */
	// End Line: 2784

void MONAPI_DeleteRegen(_MONAPI_Regenerator *regen)

{
  GlobalSave->numRegens = GlobalSave->numRegens + -1;
  memcpy(regen,regen + 1,
         ((int)GlobalSave->numRegens - ((int)regen + (-0x10 - (int)GlobalSave) >> 3)) * 8);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_ProcessGenerator()
 // line 1332, offset 0x8007f0a8
	/* begin block 1 */
		// Start line: 1333
		// Start offset: 0x8007F0A8
		// Variables:
	// 		int i; // $s2
	// 		struct _MONAPI_Regenerator *regen; // $s1

		/* begin block 1.1 */
			// Start line: 1338
			// Start offset: 0x8007F0D8
			// Variables:
		// 		unsigned long time; // $v1

			/* begin block 1.1.1 */
				// Start line: 1347
				// Start offset: 0x8007F10C
				// Variables:
			// 		struct Level *level; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 1350
					// Start offset: 0x8007F120
					// Variables:
				// 		struct Intro *intro; // $a0
				// 		int j; // $a1
				// 		long id; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x8007F178
				// End Line: 1365
			/* end block 1.1.1 */
			// End offset: 0x8007F180
			// End Line: 1368
		/* end block 1.1 */
		// End offset: 0x8007F19C
		// End Line: 1376
	/* end block 1 */
	// End offset: 0x8007F1B8
	// End Line: 1377

	/* begin block 2 */
		// Start line: 2806
	/* end block 2 */
	// End Line: 2807

	/* begin block 3 */
		// Start line: 2809
	/* end block 3 */
	// End Line: 2810

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MONAPI_ProcessGenerator(void)

{
  Level *pLVar1;
  u_long uVar2;
  u_int *puVar3;
  Intro *intro;
  int iVar4;
  short *psVar5;
  _MONAPI_Regenerator *regen;
  int iVar6;
  
  iVar6 = 0;
  regen = GlobalSave->regenEntries;
  if ('\0' < GlobalSave->numRegens) {
    psVar5 = &GlobalSave->regenEntries[0].streamUnitID;
    do {
      uVar2 = gameTrackerX.currentMaterialTime;
      if (gameTrackerX.gameData.asmData.MorphType != 0) {
        uVar2 = gameTrackerX.currentSpectralTime;
      }
      if (regen->regenTime < uVar2) {
        pLVar1 = STREAM_GetLevelWithID((int)*psVar5);
        if (pLVar1 == (Level *)0x0) {
LAB_8007f180:
          MONAPI_DeleteRegen(regen);
        }
        else {
          iVar4 = pLVar1->numIntros;
          intro = pLVar1->introList;
          puVar3 = (u_int *)&intro->flags;
          while (iVar4 != 0) {
            iVar4 = iVar4 + -1;
            if (puVar3[-6] == (int)psVar5[-1]) {
              if ((*puVar3 & 0x400) != 0) goto LAB_8007f180;
              INSTANCE_IntroduceInstance(intro,*psVar5);
              break;
            }
            puVar3 = puVar3 + 0x13;
            intro = intro + 1;
          }
        }
      }
      else {
        iVar6 = iVar6 + 1;
        psVar5 = psVar5 + 4;
        regen = regen + 1;
      }
    } while (iVar6 < GlobalSave->numRegens);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_AddToGenerator(struct _Instance *instance /*$s2*/)
 // line 1379, offset 0x8007f1d0
	/* begin block 1 */
		// Start line: 1380
		// Start offset: 0x8007F1D0

		/* begin block 1.1 */
			// Start line: 1384
			// Start offset: 0x8007F200
			// Variables:
		// 		struct _MonsterVars *mv; // $s1
		// 		struct _MONAPI_Regenerator *regen; // $s0
		/* end block 1.1 */
		// End offset: 0x8007F258
		// End Line: 1391
	/* end block 1 */
	// End offset: 0x8007F258
	// End Line: 1392

	/* begin block 2 */
		// Start line: 2965
	/* end block 2 */
	// End Line: 2966

void MONAPI_AddToGenerator(_Instance *instance)

{
  u_long uVar1;
  _MONAPI_Regenerator *p_Var2;
  void *pvVar3;
  
  if ((int)GlobalSave->numRegens < 9) {
    pvVar3 = instance->extraData;
    p_Var2 = GlobalSave->regenEntries + (int)GlobalSave->numRegens;
    GlobalSave->numRegens = GlobalSave->numRegens + '\x01';
    uVar1 = MON_GetTime(instance);
    p_Var2->regenTime = uVar1 + (int)*(short *)((int)pvVar3 + 0x146) * 1000;
    p_Var2->introUniqueID = *(short *)&instance->introUniqueID;
    p_Var2->streamUnitID = *(short *)&instance->birthStreamUnitID;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_CheckGenerator(struct _Instance *instance /*$a0*/)
 // line 1397, offset 0x8007f270
	/* begin block 1 */
		// Start line: 1398
		// Start offset: 0x8007F270
		// Variables:
	// 		int i; // $a1
	// 		struct _MONAPI_Regenerator *regen; // $v1
	// 		int id; // $a0
	/* end block 1 */
	// End offset: 0x8007F2CC
	// End Line: 1410

	/* begin block 2 */
		// Start line: 3004
	/* end block 2 */
	// End Line: 3005

void MONAPI_CheckGenerator(_Instance *instance)

{
  _MONAPI_Regenerator *regen;
  int iVar1;
  
  regen = GlobalSave->regenEntries;
  iVar1 = 0;
  if ('\0' < GlobalSave->numRegens) {
    do {
      iVar1 = iVar1 + 1;
      if ((int)regen->introUniqueID == instance->introUniqueID) {
        MONAPI_DeleteRegen(regen);
        return;
      }
      regen = regen + 1;
    } while (iVar1 < GlobalSave->numRegens);
  }
  return;
}





