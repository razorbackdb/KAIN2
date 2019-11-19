#include "THISDUST.H"
#include "MONAPI.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MonsterProcess(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 165, offset 0x8007cfec
	/* begin block 1 */
		// Start line: 166
		// Start offset: 0x8007CFEC
		// Variables:
	// 		struct _MonsterState *state; // $s0
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *attributes; // $v0
	/* end block 1 */
	// End offset: 0x8007D124
	// End Line: 237

	/* begin block 2 */
		// Start line: 330
	/* end block 2 */
	// End Line: 331

void MonsterProcess(_Instance *instance,GameTracker *gameTracker)

{
  _MonsterState *p_Var1;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  if (((puVar3 != (uint *)0x0) && (instance->data != (void *)0x0)) && ((*puVar3 & 0x80000) == 0)) {
    MONSENSE_ProcessIRList(instance);
    if ((puVar3[1] & 0x20000000) == 0) {
      MONSENSE_Radar(instance);
    }
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
// void /*$ra*/ MonsterInit(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 243, offset 0x8007d13c
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x8007D13C
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $a0
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 262
			// Start offset: 0x8007D1A4
		/* end block 1.1 */
		// End offset: 0x8007D1A4
		// End Line: 282

		/* begin block 1.2 */
			// Start line: 345
			// Start offset: 0x8007D2D8
		/* end block 1.2 */
		// End offset: 0x8007D304
		// End Line: 350
	/* end block 1 */
	// End offset: 0x8007D304
	// End Line: 352

	/* begin block 2 */
		// Start line: 491
	/* end block 2 */
	// End Line: 492

void MonsterInit(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  TDRFuncPtr_MONTABLE_GetCleanUpFunc pTVar2;
  _G2AnimKeylist_Type *keylist;
  TDRFuncPtr_MONTABLE_GetInitFunc pTVar3;
  _MonsterState *p_Var4;
  uint *__s;
  
  if ((instance->flags & 0x20000U) == 0) {
    if (((int *)instance->data != (int *)0x0) && (*(int *)instance->data == -0x531fff9e)) {
      __s = (uint *)MEMPACK_Malloc(0x25c,'\x17');
      *(uint **)&instance->extraData = __s;
      if (instance->instanceID == 0) {
        if (__s == (uint *)0x0) {
          return;
        }
        goto LAB_8007d1c4;
      }
      if (__s != (uint *)0x0) {
        memset(__s,0,0x25c);
        InitMessageQueue((__MessageQueue *)(__s + 2));
        instance->currentMainState = -1;
        *(char *)((int)__s + 0x162) = -1;
        sVar1 = (instance->position).z;
        __s[0x4a] = *(uint *)&instance->position;
        *(short *)(__s + 0x4b) = sVar1;
        __s[0x68] = 0xffffffff;
        __s[0x42] = 0;
        instance->maxXVel = 400;
        instance->maxYVel = 400;
        instance->maxZVel = 400;
        instance->xVel = 0;
        instance->yVel = 0;
        instance->zVel = 0;
        instance->flags = instance->flags | 0x10040;
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
    __s = (uint *)instance->extraData;
    pTVar2 = MONTABLE_GetCleanUpFunc(instance);
    (*pTVar2)(instance);
    MONSENSE_RemoveSenses(instance);
LAB_8007d1c4:
    MEMPACK_Free((char *)__s);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SendHitObject(struct _Instance *instance /*$s1*/, struct _Instance *hit /*$s0*/, int type /*$s2*/)
 // line 354, offset 0x8007d318
	/* begin block 1 */
		// Start line: 355
		// Start offset: 0x8007D318
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	// 		int i; // $a0

		/* begin block 1.1 */
			// Start line: 361
			// Start offset: 0x8007D368
			// Variables:
		// 		struct evMonsterHitObjectData *data1; // $v0
		/* end block 1.1 */
		// End offset: 0x8007D380
		// End Line: 364

		/* begin block 1.2 */
			// Start line: 373
			// Start offset: 0x8007D3B0
			// Variables:
		// 		struct evMonsterHitObjectData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x8007D3D4
		// End Line: 377
	/* end block 1 */
	// End offset: 0x8007D3D4
	// End Line: 378

	/* begin block 2 */
		// Start line: 735
	/* end block 2 */
	// End Line: 736

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
// void /*$ra*/ MonsterCollide(struct _Instance *instance /*$s3*/, struct GameTracker *gameTracker /*$a1*/)
 // line 384, offset 0x8007d3ec
	/* begin block 1 */
		// Start line: 385
		// Start offset: 0x8007D3EC
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s1
	// 		struct _MonsterVars *mv; // $s5

		/* begin block 1.1 */
			// Start line: 394
			// Start offset: 0x8007D438
			// Variables:
		// 		struct _HSphere *s0; // $v0

			/* begin block 1.1.1 */
				// Start line: 408
				// Start offset: 0x8007D470
				// Variables:
			// 		struct _HSphere *s1; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 411
					// Start offset: 0x8007D488
					// Variables:
				// 		struct _Instance *inst1; // $s4
				// 		int power; // $s0
				/* end block 1.1.1.1 */
				// End offset: 0x8007D548
				// End Line: 432
			/* end block 1.1.1 */
			// End offset: 0x8007D548
			// End Line: 432

			/* begin block 1.1.2 */
				// Start line: 448
				// Start offset: 0x8007D564
				// Variables:
			// 		int move; // $s6

				/* begin block 1.1.2.1 */
					// Start line: 454
					// Start offset: 0x8007D59C
					// Variables:
				// 		struct _HSphere *hsphere; // $s0
				/* end block 1.1.2.1 */
				// End offset: 0x8007D5F0
				// End Line: 462

				/* begin block 1.1.2.2 */
					// Start line: 492
					// Start offset: 0x8007D644
					// Variables:
				// 		struct BSPTree *bsp; // $s0

					/* begin block 1.1.2.2.1 */
						// Start line: 498
						// Start offset: 0x8007D680
						// Variables:
					// 		struct evMonsterHitTerrainData *data; // $s4
					// 		struct Level *level; // $s2
					// 		struct Intro *impaler; // $v0
					// 		struct _TFace *tface; // $s0

						/* begin block 1.1.2.2.1.1 */
							// Start line: 527
							// Start offset: 0x8007D7BC
							// Variables:
						// 		struct _CollideInfo parentCI; // stack offset -80
						/* end block 1.1.2.2.1.1 */
						// End offset: 0x8007D828
						// End Line: 534
					/* end block 1.1.2.2.1 */
					// End offset: 0x8007D84C
					// End Line: 538
				/* end block 1.1.2.2 */
				// End offset: 0x8007D850
				// End Line: 543
			/* end block 1.1.2 */
			// End offset: 0x8007D898
			// End Line: 569
		/* end block 1.1 */
		// End offset: 0x8007D898
		// End Line: 570
	/* end block 1 */
	// End offset: 0x8007D898
	// End Line: 574

	/* begin block 2 */
		// Start line: 801
	/* end block 2 */
	// End Line: 802

void MonsterCollide(_Instance *instance,GameTracker *gameTracker)

{
  bool bVar1;
  _Normal *normal;
  ulong uVar2;
  Intro *pIVar3;
  long lVar4;
  _CollideInfo *p_Var5;
  void **ppvVar6;
  int Data;
  void *pvVar7;
  void *pvVar8;
  int Data_00;
  BSPTree *bsp;
  void *pvVar9;
  _CollideInfo *collideInfo;
  uint uVar10;
  _Terrain *p_Var11;
  _Instance *Inst;
  uint *puVar12;
  void *local_50 [4];
  _Instance *local_40;
  _Instance *local_3c;
  
  collideInfo = (_CollideInfo *)instance->collideInfo;
  puVar12 = (uint *)instance->extraData;
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
    Data_00 = (int)*(char *)(uVar10 + 7);
    Inst = (_Instance *)collideInfo->inst1;
    if ((*puVar12 & 0x20000000) != 0) {
      Data_00 = Data_00 << 1;
    }
    MON_TurnOffWeaponSpheres(instance);
    Data_00 = Data_00 * 0x100;
    Data = Data_00;
    if (Data_00 < 0) {
      Data = Data_00 + 0x7f;
    }
    Data = SetFXHitData(instance,(uint)(byte)collideInfo->segment,Data >> 7,0x100);
    INSTANCE_Post(Inst,0x400000,Data);
    Data_00 = SetMonsterHitData(instance,(_Instance *)0x0,Data_00,(int)*(short *)(uVar10 + 4),
                                (int)*(char *)(uVar10 + 6));
    INSTANCE_Post(Inst,0x1000000,Data_00);
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
    goto LAB_8007d84c;
  case '\x02':
    SendHitObject(instance,(_Instance *)collideInfo->inst1,2);
    break;
  case '\x03':
    bsp = (BSPTree *)collideInfo->inst1;
    if ((bsp->flags & 0xe0U) != 0) {
      MON_CheckTerrainAndRespond(instance,bsp,(_TFace *)collideInfo->prim1);
    }
    if ((bsp->flags & 0x102U) == 0) {
      normal = (_Normal *)CIRC_Alloc(10);
      pvVar9 = collideInfo->prim1;
      p_Var11 = (_Terrain *)collideInfo->level;
      if (*(short *)((int)pvVar9 + 10) == -1) {
        normal[1].x = 0;
      }
      else {
        normal[1].x = *(short *)((int)&(*(_Terrain **)p_Var11)->StartTextureList->attr +
                                (uint)*(ushort *)((int)pvVar9 + 10));
      }
      uVar2 = INSTANCE_Query(instance,1);
      if ((((uVar2 & 4) == 0) || (*(ushort *)((int)pvVar9 + 10) == 0xffff)) ||
         ((*(ushort *)
            ((int)&(*(_Terrain **)p_Var11)->StartTextureList->attr +
            (uint)*(ushort *)((int)pvVar9 + 10)) & 0x1000) == 0)) {
        pIVar3 = MON_TestForTerrainImpale(instance,*(_Terrain **)p_Var11);
        if (pIVar3 == (Intro *)0x0) {
          lVar4 = COLLIDE_FindCollisionFaceNormal(collideInfo,normal);
          if (lVar4 != 0) {
            (collideInfo->offset).x = (collideInfo->offset).x + (normal->x >> 10);
            (collideInfo->offset).y = (collideInfo->offset).y + (normal->y >> 10);
            INSTANCE_Post(instance,0x1000007,(int)normal);
          }
        }
        else {
          INSTANCE_Post(instance,0x100001c,pIVar3->UniqueID);
          (collideInfo->offset).x = 0;
          (collideInfo->offset).y = 0;
        }
        *puVar12 = *puVar12 | 8;
        ppvVar6 = (void **)local_50;
        if (instance->LinkParent != (_Instance *)0x0) {
          p_Var5 = collideInfo;
          do {
            pvVar9 = *(void **)&p_Var5->flags;
            pvVar7 = p_Var5->prim0;
            pvVar8 = p_Var5->prim1;
            *ppvVar6 = p_Var5->level;
            ppvVar6[1] = pvVar9;
            ppvVar6[2] = pvVar7;
            ppvVar6[3] = pvVar8;
            p_Var5 = (_CollideInfo *)&p_Var5->inst0;
            ppvVar6 = ppvVar6 + 4;
          } while (p_Var5 != collideInfo + 1);
          if (local_40 == instance) {
            local_40 = instance->LinkParent;
          }
          if (local_3c == instance) {
            local_3c = instance->LinkParent;
          }
          Data_00 = SetCollideInfoData((_CollideInfo *)local_50);
          INSTANCE_Post(instance->LinkParent,0x200004,Data_00);
        }
        break;
      }
    }
LAB_8007d84c:
    bVar1 = false;
    break;
  case '\x05':
    if ((collideInfo->offset).z < -0x32) {
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
 // line 579, offset 0x8007d8c0
	/* begin block 1 */
		// Start line: 1207
	/* end block 1 */
	// End Line: 1208

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
 // line 588, offset 0x8007d8f0
	/* begin block 1 */
		// Start line: 589
		// Start offset: 0x8007D8F0
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	// 		struct _MonsterAttributes *ma; // $s0
	// 		unsigned long ret; // $a0

		/* begin block 1.1 */
			// Start line: 601
			// Start offset: 0x8007D93C
			// Variables:
		// 		struct evShadowSegmentData *shadowData; // $v0
		/* end block 1.1 */
		// End offset: 0x8007D93C
		// End Line: 602

		/* begin block 1.2 */
			// Start line: 670
			// Start offset: 0x8007DAA8
			// Variables:
		// 		struct _MonsterSaveInfo *saveInfo; // $s0
		/* end block 1.2 */
		// End offset: 0x8007DAA8
		// End Line: 670
	/* end block 1 */
	// End offset: 0x8007DB08
	// End Line: 687

	/* begin block 2 */
		// Start line: 1225
	/* end block 2 */
	// End Line: 1226

ulong MonsterQuery(_Instance *instance,ulong query)

{
  MATRIX *pMVar1;
  _MonsterSaveInfo *saveData;
  uint uVar2;
  uint *puVar3;
  void *pvVar4;
  
  pvVar4 = instance->data;
  puVar3 = (uint *)instance->extraData;
  pMVar1 = (MATRIX *)0x0;
  if (pvVar4 != (void *)0x0) {
    switch(query) {
    case 0:
      uVar2 = *puVar3;
      pMVar1 = (MATRIX *)0x40000000;
      if ((uVar2 & 0x200) == 0) {
        pMVar1 = (MATRIX *)0x0;
        if ((uVar2 & 0x200000) == 0) {
          if ((((uVar2 & 0x10) != 0) || (puVar3[0x31] == 0)) || (instance->currentMainState == 0x18)
             ) {
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
          pMVar1 = (MATRIX *)((uint)pMVar1 | 0x20000000);
        }
      }
      break;
    case 1:
      pMVar1 = *(MATRIX **)((int)pvVar4 + 0x10);
      break;
    case 2:
      pMVar1 = (MATRIX *)(uint)*(byte *)(puVar3[0x59] + 0x27);
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
      pMVar1 = (MATRIX *)(uint)*(byte *)((int)pvVar4 + 0x1a);
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
      pMVar1 = (MATRIX *)0x1;
      break;
    case 0x26:
      pMVar1 = (MATRIX *)SetShadowSegmentData(2);
      pMVar1->m[1] = (ushort)*(byte *)((int)pvVar4 + 0x20);
      *(ushort *)((int)pMVar1->m + 6) = (ushort)*(byte *)((int)pvVar4 + 0x21);
    }
  }
  return (ulong)pMVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterMessage(struct _Instance *instance /*$s2*/, unsigned long message /*$s1*/, unsigned long data /*$s3*/)
 // line 693, offset 0x8007db1c
	/* begin block 1 */
		// Start line: 694
		// Start offset: 0x8007DB1C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 709
			// Start offset: 0x8007DB8C
		/* end block 1.1 */
		// End offset: 0x8007DB98
		// End Line: 711

		/* begin block 1.2 */
			// Start line: 733
			// Start offset: 0x8007DC74
		/* end block 1.2 */
		// End offset: 0x8007DC74
		// End Line: 735

		/* begin block 1.3 */
			// Start line: 740
			// Start offset: 0x8007DC90
		/* end block 1.3 */
		// End offset: 0x8007DC90
		// End Line: 742
	/* end block 1 */
	// End offset: 0x8007DD48
	// End Line: 780

	/* begin block 2 */
		// Start line: 1438
	/* end block 2 */
	// End Line: 1439

void MonsterMessage(_Instance *instance,ulong message,ulong data)

{
  uint uVar1;
  int iVar2;
  undefined4 local_18;
  uint *puVar3;
  undefined4 local_14;
  
  puVar3 = (uint *)instance->extraData;
  if (puVar3 != (uint *)0x0) {
    if (message == 0x100007) {
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
            if (message == 0x100008) {
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
 // line 785, offset 0x8007dd64
	/* begin block 1 */
		// Start line: 786
		// Start offset: 0x8007DD64
		// Variables:
	// 		struct _G2Anim_Type anim; // stack offset -216
	// 		struct _G2AnimSection_Type *animSection; // $s0
	// 		struct _G2AnimKeylist_Type *keylist; // $s2
	// 		long total; // $s0

		/* begin block 1.1 */
			// Start line: 806
			// Start offset: 0x8007DE08
			// Variables:
		// 		struct _G2SVector3_Type dist; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x8007DEA8
		// End Line: 813
	/* end block 1 */
	// End offset: 0x8007DEA8
	// End Line: 815

	/* begin block 2 */
		// Start line: 1623
	/* end block 2 */
	// End Line: 1624

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
  _Stack216.section[0].segCount = *(uchar *)&(*object->modelList)->numSegments;
  _Stack216.section[0].callback = (_func_4388 *)0x0;
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
         (ushort)((int)((uint)mAnim->playSpeed * lVar3 * 100) / ((int)((uint)uVar1 << 0x10) >> 4));
  }
  G2Anim_Free(&_Stack216);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TranslateAnimList(struct Object *object /*$s5*/, struct _MonsterAnim *animList /*$a1*/, int numAnims /*$s6*/)
 // line 939, offset 0x8007decc
	/* begin block 1 */
		// Start line: 940
		// Start offset: 0x8007DECC
		// Variables:
	// 		int i; // $s2

		/* begin block 1.1 */
			// Start line: 943
			// Start offset: 0x8007DEFC
			// Variables:
		// 		struct _MonsterAnim *animPtr; // $s3

			/* begin block 1.1.1 */
				// Start line: 951
				// Start offset: 0x8007DF0C
				// Variables:
			// 		int index; // $a0
			// 		struct _G2AnimKeylist_Type *keylist; // $s4
			/* end block 1.1.1 */
			// End offset: 0x8007DF8C
			// End Line: 986
		/* end block 1.1 */
		// End offset: 0x8007DFA0
		// End Line: 987
	/* end block 1 */
	// End offset: 0x8007DFA0
	// End Line: 988

	/* begin block 2 */
		// Start line: 1943
	/* end block 2 */
	// End Line: 1944

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
        if (((int)sVar2 / 100) * 0x10000 >> 0x10 <= (int)(uint)bVar1) {
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
 // line 997, offset 0x8007dfc8
	/* begin block 1 */
		// Start line: 998
		// Start offset: 0x8007DFC8
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $s0
	// 		int i; // $a3

		/* begin block 1.1 */
			// Start line: 1015
			// Start offset: 0x8007E014
			// Variables:
		// 		void *relocModule; // $v0
		/* end block 1.1 */
		// End offset: 0x8007E058
		// End Line: 1040

		/* begin block 1.2 */
			// Start line: 1067
			// Start offset: 0x8007E0C4
			// Variables:
		// 		struct _MonsterAttackAttributes *attackAttr; // $v1
		/* end block 1.2 */
		// End offset: 0x8007E100
		// End Line: 1095

		/* begin block 1.3 */
			// Start line: 1098
			// Start offset: 0x8007E124
			// Variables:
		// 		struct _MonsterCombatAttributes *combatAttr; // $v1

			/* begin block 1.3.1 */
				// Start line: 1100
				// Start offset: 0x8007E148
				// Variables:
			// 		int largest; // $a2
			// 		int j; // $a1

				/* begin block 1.3.1.1 */
					// Start line: 1107
					// Start offset: 0x8007E164
					// Variables:
				// 		struct _MonsterAttackAttributes *attack; // $v0
				/* end block 1.3.1.1 */
				// End offset: 0x8007E190
				// End Line: 1110
			/* end block 1.3.1 */
			// End offset: 0x8007E1A8
			// End Line: 1113
		/* end block 1.3 */
		// End offset: 0x8007E1A8
		// End Line: 1122
	/* end block 1 */
	// End offset: 0x8007E1BC
	// End Line: 1138

	/* begin block 2 */
		// Start line: 2098
	/* end block 2 */
	// End Line: 2099

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
  GlobalSave->humanOpinionOfRaziel = -100;
  if ((object->oflags2 & 0x10000000U) != 0) {
    return;
  }
  if ((object->oflags & 0x8000000U) == 0) {
    MONTABLE_SetupTablePointer(object);
  }
  else {
    if (object->relocModule == (void *)0x0) {
      object->data = (void *)0x0;
      return;
    }
    if (*(char **)((int)object->relocModule + 0x18) != "May 12 1999") {
      GXFilePrint("ERROR: Object %s\'s relocatable code is out of sync with game.\n");
      object->data = (void *)0x0;
      return;
    }
  }
  if (piVar7 == (int *)0x0) {
    GXFilePrint("ERROR: Object %s: I seem to have no .oed file\n");
  }
  else {
    if (*piVar7 == -0x531fff9e) {
      TranslateAnimList(object,(_MonsterAnim *)piVar7[0x11],(int)*(char *)((int)piVar7 + 0x2f));
      iVar6 = 0;
      if ('\0' < *(char *)((int)piVar7 + 0x2d)) {
        do {
          iVar3 = piVar7[0xf] + iVar6 * 0x20;
          if ((*(char *)(iVar3 + 0xe) <= *(char *)(iVar3 + 10)) ||
             (*(char *)(iVar3 + 0xe) <= *(char *)(iVar3 + 0xc))) {
            object->data = (void *)0x0;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(char *)((int)piVar7 + 0x2d));
      }
      iVar6 = 0;
      if ('\0' < *(char *)(piVar7 + 0xb)) {
        do {
          iVar3 = *(int *)(iVar6 * 4 + piVar7[0xe]);
          if (*(short *)(iVar3 + 10) == 0) {
            iVar4 = 0;
            sVar5 = 0;
            if (0 < (int)*(char *)(iVar3 + 0x17)) {
              iVar2 = iVar3;
              sVar5 = 0;
              do {
                sVar1 = *(short *)(piVar7[0xf] + (int)*(char *)(iVar2 + 0x26) * 0x20);
                if (sVar5 < sVar1) {
                  sVar5 = sVar1;
                }
                iVar4 = iVar4 + 1;
                iVar2 = iVar3 + iVar4;
              } while (iVar4 < (int)*(char *)(iVar3 + 0x17));
            }
            *(short *)(iVar3 + 10) = sVar5 + 200;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(char *)(piVar7 + 0xb));
      }
    }
    else {
      GXFilePrint("ERROR: Object %s: I seem to be version %x\n");
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterRelocateTune(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 1143, offset 0x8007e1d0
	/* begin block 1 */
		// Start line: 1145
		// Start offset: 0x8007E1D0
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $t0

		/* begin block 1.1 */
			// Start line: 1149
			// Start offset: 0x8007E1F0
			// Variables:
		// 		int i; // $a3
		// 		struct _MonsterSubAttributes *subAttr; // $a2
		// 		struct _MonsterSubAttributes **pSubAttr; // $t1
		// 		struct _MonsterCombatAttributes **pCombatAttr; // $v0

			/* begin block 1.1.1 */
				// Start line: 1167
				// Start offset: 0x8007E2CC
				// Variables:
			// 		int j; // $v1
			// 		struct _MonsterSubAttributes **oldSubAttr; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8007E384
			// End Line: 1188
		/* end block 1.1 */
		// End offset: 0x8007E3D0
		// End Line: 1192
	/* end block 1 */
	// End offset: 0x8007E3D0
	// End Line: 1193

	/* begin block 2 */
		// Start line: 2451
	/* end block 2 */
	// End Line: 2452

	/* begin block 3 */
		// Start line: 2452
	/* end block 3 */
	// End Line: 2453

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
  if ((piVar2 != (int *)0x0) && (*piVar2 == -0x531fff9e)) {
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
    if (piVar2[0xd] != 0) {
      iVar4 = piVar2[0xd] + offset;
    }
    iVar3 = 0;
    piVar2[0xd] = iVar4;
    if (piVar2[0xe] != 0) {
      iVar3 = piVar2[0xe] + offset;
    }
    iVar4 = 0;
    piVar2[0xe] = iVar3;
    if (piVar2[0xf] != 0) {
      iVar4 = piVar2[0xf] + offset;
    }
    iVar3 = 0;
    piVar2[0xf] = iVar4;
    if (piVar2[0x10] != 0) {
      iVar3 = piVar2[0x10] + offset;
    }
    iVar4 = 0;
    piVar2[0x10] = iVar3;
    if (piVar2[0x11] != 0) {
      iVar4 = piVar2[0x11] + offset;
    }
    iVar3 = 0;
    piVar2[0x11] = iVar4;
    if (piVar2[0x12] != 0) {
      iVar3 = piVar2[0x12] + offset;
    }
    iVar4 = 0;
    piVar2[0x12] = iVar3;
    if (piVar2[0x13] != 0) {
      iVar4 = piVar2[0x13] + offset;
    }
    ppiVar7 = (int **)piVar2[0xd];
    iVar3 = 0;
    piVar2[0x13] = iVar4;
    if ('\0' < *(char *)((int)piVar2 + 0x2b)) {
      do {
        piVar1 = (int *)0x0;
        if (*ppiVar7 != (int *)0x0) {
          piVar1 = (int *)((int)*ppiVar7 + offset);
        }
        iVar4 = 0;
        *ppiVar7 = piVar1;
        ppiVar5 = (int **)piVar2[0xd];
        if (0 < iVar3) {
          do {
            if (*ppiVar5 == piVar1) break;
            iVar4 = iVar4 + 1;
            ppiVar5 = ppiVar5 + 1;
          } while (iVar4 < iVar3);
        }
        if (iVar4 == iVar3) {
          iVar4 = 0;
          if (*piVar1 != 0) {
            iVar4 = *piVar1 + offset;
          }
          iVar6 = 0;
          *piVar1 = iVar4;
          if (piVar1[1] != 0) {
            iVar6 = piVar1[1] + offset;
          }
          iVar4 = 0;
          piVar1[1] = iVar6;
          if (piVar1[2] != 0) {
            iVar4 = piVar1[2] + offset;
          }
          iVar6 = 0;
          piVar1[2] = iVar4;
          if (piVar1[3] != 0) {
            iVar6 = piVar1[3] + offset;
          }
          iVar4 = 0;
          piVar1[3] = iVar6;
          if (piVar1[4] != 0) {
            iVar4 = piVar1[4] + offset;
          }
          piVar1[4] = iVar4;
        }
        iVar3 = iVar3 + 1;
        ppiVar7 = ppiVar7 + 1;
      } while (iVar3 < *(char *)((int)piVar2 + 0x2b));
    }
    iVar3 = (int)*(char *)(piVar2 + 0xb);
    piVar2 = (int *)piVar2[0xe];
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
 // line 1198, offset 0x8007e3d8
	/* begin block 1 */
		// Start line: 1200
		// Start offset: 0x8007E3D8
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x8007E4D0
	// End Line: 1221

	/* begin block 2 */
		// Start line: 2591
	/* end block 2 */
	// End Line: 2592

	/* begin block 3 */
		// Start line: 2592
	/* end block 3 */
	// End Line: 2593

void MonsterRelocateInstanceObject(_Instance *instance,long offset)

{
  void *pvVar1;
  _func_4392 *p_Var2;
  _func_4393 *p_Var3;
  _func_4390 *p_Var4;
  _func_4390 *p_Var5;
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
        p_Var2 = (_func_4392 *)0x0;
        if (instance->queryFunc != (_func_4392 *)0x0) {
          p_Var2 = instance->queryFunc + offset;
        }
        instance->queryFunc = p_Var2;
      }
      if (*(int *)((int)instance->object->relocModule + 0x10) != 0) {
        p_Var3 = (_func_4393 *)0x0;
        if (instance->messageFunc != (_func_4393 *)0x0) {
          p_Var3 = instance->messageFunc + offset;
        }
        instance->messageFunc = p_Var3;
      }
      p_Var5 = instance->collideFunc;
      if (p_Var5 != MonsterCollide) {
        p_Var4 = (_func_4390 *)0x0;
        if (p_Var5 != (_func_4390 *)0x0) {
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
 // line 1270, offset 0x8007e4d8
	/* begin block 1 */
		// Start line: 2537
	/* end block 1 */
	// End Line: 2538

void MONAPI_TurnHead(_Instance *instance,short *rotx,short *rotz,GameTracker *gameTracker)

{
  short sVar1;
  
  sVar1 = -0x300;
  if ((*rotx < -0x300) || (sVar1 = 0x200, 0x200 < *rotx)) {
    *rotx = sVar1;
  }
  if (*rotz < 0x401) {
    sVar1 = -0x400;
    if (-0x401 < *rotz) goto LAB_8007e52c;
  }
  else {
    sVar1 = 0x400;
  }
  *rotz = sVar1;
LAB_8007e52c:
  MON_LookInDirection(instance,-*rotx,*rotz);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_SetLookAround(struct _Instance *instance /*$a0*/)
 // line 1291, offset 0x8007e554
	/* begin block 1 */
		// Start line: 1292
		// Start offset: 0x8007E554
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007E554
	// End Line: 1292

	/* begin block 2 */
		// Start line: 2727
	/* end block 2 */
	// End Line: 2728

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
 // line 1300, offset 0x8007e584
	/* begin block 1 */
		// Start line: 1301
		// Start offset: 0x8007E584
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007E584
	// End Line: 1301

	/* begin block 2 */
		// Start line: 2745
	/* end block 2 */
	// End Line: 2746

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
 // line 1309, offset 0x8007e5b4
	/* begin block 1 */
		// Start line: 2763
	/* end block 1 */
	// End Line: 2764

	/* begin block 2 */
		// Start line: 2764
	/* end block 2 */
	// End Line: 2765

long MONAPI_OkToLookAround(_Instance *instance)

{
  return (uint)(instance->currentMainState == 2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen /*$a0*/)
 // line 1314, offset 0x8007e5c8
	/* begin block 1 */
		// Start line: 2773
	/* end block 1 */
	// End Line: 2774

	/* begin block 2 */
		// Start line: 2776
	/* end block 2 */
	// End Line: 2777

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
 // line 1325, offset 0x8007e614
	/* begin block 1 */
		// Start line: 1326
		// Start offset: 0x8007E614
		// Variables:
	// 		int i; // $s2
	// 		struct _MONAPI_Regenerator *regen; // $s1

		/* begin block 1.1 */
			// Start line: 1331
			// Start offset: 0x8007E644
			// Variables:
		// 		unsigned long time; // $v1

			/* begin block 1.1.1 */
				// Start line: 1340
				// Start offset: 0x8007E678
				// Variables:
			// 		struct Level *level; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 1343
					// Start offset: 0x8007E68C
					// Variables:
				// 		struct Intro *intro; // $a0
				// 		int j; // $a1
				// 		long id; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x8007E6E4
				// End Line: 1358
			/* end block 1.1.1 */
			// End offset: 0x8007E6EC
			// End Line: 1361
		/* end block 1.1 */
		// End offset: 0x8007E708
		// End Line: 1369
	/* end block 1 */
	// End offset: 0x8007E724
	// End Line: 1370

	/* begin block 2 */
		// Start line: 2799
	/* end block 2 */
	// End Line: 2800

	/* begin block 3 */
		// Start line: 2802
	/* end block 3 */
	// End Line: 2803

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MONAPI_ProcessGenerator(void)

{
  Level *pLVar1;
  ulong uVar2;
  uint *puVar3;
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
      uVar2 = gameTrackerX.spectralTimeMult;
      if (gameTrackerX.gameData.asmData.MorphType != 0) {
        uVar2 = gameTrackerX.materialTimeMult;
      }
      if (regen->regenTime < uVar2) {
        pLVar1 = STREAM_GetLevelWithID((int)*psVar5);
        if (pLVar1 == (Level *)0x0) {
LAB_8007e6ec:
          MONAPI_DeleteRegen(regen);
        }
        else {
          iVar4 = pLVar1->numIntros;
          intro = pLVar1->introList;
          puVar3 = (uint *)&intro->flags;
          while (iVar4 != 0) {
            iVar4 = iVar4 + -1;
            if (puVar3[-6] == (int)psVar5[-1]) {
              if ((*puVar3 & 0x400) != 0) goto LAB_8007e6ec;
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
 // line 1372, offset 0x8007e73c
	/* begin block 1 */
		// Start line: 1373
		// Start offset: 0x8007E73C

		/* begin block 1.1 */
			// Start line: 1377
			// Start offset: 0x8007E76C
			// Variables:
		// 		struct _MonsterVars *mv; // $s1
		// 		struct _MONAPI_Regenerator *regen; // $s0
		/* end block 1.1 */
		// End offset: 0x8007E7C4
		// End Line: 1384
	/* end block 1 */
	// End offset: 0x8007E7C4
	// End Line: 1385

	/* begin block 2 */
		// Start line: 2958
	/* end block 2 */
	// End Line: 2959

void MONAPI_AddToGenerator(_Instance *instance)

{
  ulong uVar1;
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
 // line 1390, offset 0x8007e7dc
	/* begin block 1 */
		// Start line: 1391
		// Start offset: 0x8007E7DC
		// Variables:
	// 		int i; // $a1
	// 		struct _MONAPI_Regenerator *regen; // $v1
	// 		int id; // $a0
	/* end block 1 */
	// End offset: 0x8007E838
	// End Line: 1403

	/* begin block 2 */
		// Start line: 2997
	/* end block 2 */
	// End Line: 2998

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





