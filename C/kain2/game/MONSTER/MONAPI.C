#include "THISDUST.H"
#include "MONAPI.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MonsterProcess(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 165, offset 0x8007dcb0
	/* begin block 1 */
		// Start line: 166
		// Start offset: 0x8007DCB0
		// Variables:
	// 		struct _MonsterState *state; // $s0
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *attributes; // $v0
	/* end block 1 */
	// End offset: 0x8007DDD0
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
    instance->waterFace = (_TFace *)0x0;
    instance->waterFaceTerrain = (_Terrain *)0x0;
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
 // line 243, offset 0x8007dde8
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x8007DDE8
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $s2
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 262
			// Start offset: 0x8007DE54
		/* end block 1.1 */
		// End offset: 0x8007DE54
		// End Line: 282

		/* begin block 1.2 */
			// Start line: 349
			// Start offset: 0x8007DFAC
		/* end block 1.2 */
		// End offset: 0x8007DFD8
		// End Line: 354
	/* end block 1 */
	// End offset: 0x8007DFD8
	// End Line: 356

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
  int *piVar5;
  
  piVar5 = (int *)instance->data;
  if ((instance->flags & 0x20000U) == 0) {
    if ((piVar5 != (int *)0x0) && (*piVar5 == -0x531fff9b)) {
      __s = (uint *)MEMPACK_Malloc(0x260,'\x17');
      *(uint **)&instance->extraData = __s;
      if (instance->instanceID == 0) {
        if (__s == (uint *)0x0) {
          return;
        }
        goto LAB_8007de74;
      }
      if (__s != (uint *)0x0) {
        memset(__s,0,0x260);
        InitMessageQueue((__MessageQueue *)(__s + 2));
        instance->currentMainState = -1;
        *(char *)((int)__s + 0x166) = -1;
        sVar1 = (instance->position).z;
        __s[0x4b] = *(uint *)&instance->position;
        *(short *)(__s + 0x4c) = sVar1;
        __s[0x69] = 0xffffffff;
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
        *(undefined2 *)((int)__s + 0x146) = *(undefined2 *)(__s + 0x51);
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
LAB_8007de74:
    MEMPACK_Free((char *)__s);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SendHitObject(struct _Instance *instance /*$s1*/, struct _Instance *hit /*$s0*/, int type /*$s2*/)
 // line 358, offset 0x8007dff0
	/* begin block 1 */
		// Start line: 359
		// Start offset: 0x8007DFF0
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	// 		int i; // $a0

		/* begin block 1.1 */
			// Start line: 365
			// Start offset: 0x8007E040
			// Variables:
		// 		struct evMonsterHitObjectData *data1; // $v0
		/* end block 1.1 */
		// End offset: 0x8007E058
		// End Line: 368

		/* begin block 1.2 */
			// Start line: 377
			// Start offset: 0x8007E088
			// Variables:
		// 		struct evMonsterHitObjectData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x8007E0AC
		// End Line: 381
	/* end block 1 */
	// End offset: 0x8007E0AC
	// End Line: 382

	/* begin block 2 */
		// Start line: 732
	/* end block 2 */
	// End Line: 733

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
// void /*$ra*/ MonsterCollide(struct _Instance *instance /*$s4*/, struct GameTracker *gameTracker /*$a1*/)
 // line 388, offset 0x8007e0c4
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x8007E0C4
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s1
	// 		struct _MonsterVars *mv; // $s6

		/* begin block 1.1 */
			// Start line: 398
			// Start offset: 0x8007E114
			// Variables:
		// 		struct _HSphere *s0; // $v0

			/* begin block 1.1.1 */
				// Start line: 412
				// Start offset: 0x8007E14C
				// Variables:
			// 		struct _HSphere *s1; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 415
					// Start offset: 0x8007E164
					// Variables:
				// 		struct _Instance *inst1; // $s3
				// 		int power; // $s0
				/* end block 1.1.1.1 */
				// End offset: 0x8007E224
				// End Line: 436
			/* end block 1.1.1 */
			// End offset: 0x8007E224
			// End Line: 436

			/* begin block 1.1.2 */
				// Start line: 452
				// Start offset: 0x8007E240
				// Variables:
			// 		int move; // $s7

				/* begin block 1.1.2.1 */
					// Start line: 458
					// Start offset: 0x8007E278
					// Variables:
				// 		struct _HSphere *hsphere; // $s0
				/* end block 1.1.2.1 */
				// End offset: 0x8007E2CC
				// End Line: 466

				/* begin block 1.1.2.2 */
					// Start line: 496
					// Start offset: 0x8007E33C
					// Variables:
				// 		struct BSPTree *bsp; // $s3

					/* begin block 1.1.2.2.1 */
						// Start line: 503
						// Start offset: 0x8007E378
						// Variables:
					// 		struct evMonsterHitTerrainData *data; // $s0
					// 		struct Level *level; // $s5
					// 		struct Intro *impaler; // $v0
					// 		struct _TFace *tface; // $s2

						/* begin block 1.1.2.2.1.1 */
							// Start line: 534
							// Start offset: 0x8007E4C0
							// Variables:
						// 		struct _CollideInfo parentCI; // stack offset -88
						/* end block 1.1.2.2.1.1 */
						// End offset: 0x8007E52C
						// End Line: 541
					/* end block 1.1.2.2.1 */
					// End offset: 0x8007E550
					// End Line: 545
				/* end block 1.1.2.2 */
				// End offset: 0x8007E554
				// End Line: 550
			/* end block 1.1.2 */
			// End offset: 0x8007E59C
			// End Line: 576
		/* end block 1.1 */
		// End offset: 0x8007E59C
		// End Line: 577
	/* end block 1 */
	// End offset: 0x8007E59C
	// End Line: 581

	/* begin block 2 */
		// Start line: 798
	/* end block 2 */
	// End Line: 799

void MonsterCollide(_Instance *instance,GameTracker *gameTracker)

{
  bool bVar1;
  ulong uVar2;
  Intro *pIVar3;
  long lVar4;
  _CollideInfo *p_Var5;
  void **Data;
  int Data_00;
  void *pvVar6;
  void *pvVar7;
  int Data_01;
  _CollideInfo *collideInfo;
  uint uVar8;
  void *pvVar9;
  _Instance *Inst;
  BSPTree *bsp;
  _Terrain *p_Var10;
  uint *puVar11;
  void *local_58 [4];
  _Instance *local_48;
  _Instance *local_44;
  
  collideInfo = (_CollideInfo *)instance->collideInfo;
  puVar11 = (uint *)instance->extraData;
  if (instance->data == (void *)0x0) {
    return;
  }
  if (collideInfo->type0 != '\x01') {
    return;
  }
  if (*(char *)((int)collideInfo->prim0 + 4) == '\t') {
    uVar8 = puVar11[0x2e];
    if (uVar8 == 0) {
      return;
    }
    if (collideInfo->type1 != '\x01') {
      return;
    }
    if (*(char *)((int)collideInfo->prim1 + 4) != '\b') {
      return;
    }
    Data_01 = (int)*(char *)(uVar8 + 7);
    Inst = (_Instance *)collideInfo->inst1;
    if ((*puVar11 & 0x20000000) != 0) {
      Data_01 = Data_01 << 1;
    }
    MON_TurnOffWeaponSpheres(instance);
    Data_01 = Data_01 * 0x100;
    Data_00 = Data_01;
    if (Data_01 < 0) {
      Data_00 = Data_01 + 0x7f;
    }
    Data_00 = SetFXHitData(instance,(uint)(byte)collideInfo->segment,Data_00 >> 7,0x100);
    INSTANCE_Post(Inst,0x400000,Data_00);
    Data_01 = SetMonsterHitData(instance,(_Instance *)0x0,Data_01,(int)*(short *)(uVar8 + 4),
                                (int)*(char *)(uVar8 + 6));
    INSTANCE_Post(Inst,0x1000000,Data_01);
    uVar8 = puVar11[0x31];
    if (Inst != *(_Instance **)(uVar8 + 4)) {
      return;
    }
    if ((*puVar11 & 0x10000000) != 0) {
      *(ushort *)(uVar8 + 0x16) = *(ushort *)(uVar8 + 0x16) | 0x1000;
    }
    *(ushort *)(puVar11[0x31] + 0x18) = *(ushort *)(puVar11[0x31] + 0x18) | 0x100;
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
    goto LAB_8007e550;
  case '\x02':
    SendHitObject(instance,(_Instance *)collideInfo->inst1,2);
    break;
  case '\x03':
    bsp = (BSPTree *)collideInfo->inst1;
    if ((bsp->flags & 0xe0U) != 0) {
      MON_CheckTerrainAndRespond(instance,bsp,(_TFace *)collideInfo->prim1);
    }
    if ((bsp->flags & 0x102U) == 0) {
      Data = (void **)CIRC_Alloc(0x10);
      pvVar9 = collideInfo->prim1;
      p_Var10 = (_Terrain *)collideInfo->level;
      if (*(short *)((int)pvVar9 + 10) == -1) {
        *(undefined2 *)(Data + 3) = 0;
      }
      else {
        *(undefined2 *)(Data + 3) =
             *(undefined2 *)
              ((int)&(*(_Terrain **)p_Var10)->StartTextureList->attr +
              (uint)*(ushort *)((int)pvVar9 + 10));
      }
      *Data = pvVar9;
      *(short *)((int)Data + 0xe) = bsp->flags;
      uVar2 = INSTANCE_Query(instance,1);
      if ((((uVar2 & 4) == 0) || (*(ushort *)((int)pvVar9 + 10) == 0xffff)) ||
         ((*(ushort *)
            ((int)&(*(_Terrain **)p_Var10)->StartTextureList->attr +
            (uint)*(ushort *)((int)pvVar9 + 10)) & 0x1000) == 0)) {
        pIVar3 = MON_TestForTerrainImpale(instance,*(_Terrain **)p_Var10);
        if (pIVar3 == (Intro *)0x0) {
          lVar4 = COLLIDE_FindCollisionFaceNormal(collideInfo,(_Normal *)(Data + 1));
          if (lVar4 != 0) {
            (collideInfo->offset).x = (collideInfo->offset).x + (*(short *)(Data + 1) >> 10);
            (collideInfo->offset).y = (collideInfo->offset).y + (*(short *)((int)Data + 6) >> 10);
            INSTANCE_Post(instance,0x1000007,(int)Data);
          }
        }
        else {
          INSTANCE_Post(instance,0x100001c,pIVar3->UniqueID);
          (collideInfo->offset).x = 0;
          (collideInfo->offset).y = 0;
        }
        *puVar11 = *puVar11 | 8;
        Data = (void **)local_58;
        if (instance->LinkParent != (_Instance *)0x0) {
          p_Var5 = collideInfo;
          do {
            pvVar9 = *(void **)&p_Var5->flags;
            pvVar6 = p_Var5->prim0;
            pvVar7 = p_Var5->prim1;
            *Data = p_Var5->level;
            Data[1] = pvVar9;
            Data[2] = pvVar6;
            Data[3] = pvVar7;
            p_Var5 = (_CollideInfo *)&p_Var5->inst0;
            Data = Data + 4;
          } while (p_Var5 != collideInfo + 1);
          if (local_48 == instance) {
            local_48 = instance->LinkParent;
          }
          if (local_44 == instance) {
            local_44 = instance->LinkParent;
          }
          Data_01 = SetCollideInfoData((_CollideInfo *)local_58);
          INSTANCE_Post(instance->LinkParent,0x200004,Data_01);
        }
        break;
      }
    }
LAB_8007e550:
    bVar1 = false;
    break;
  case '\x05':
    if (((collideInfo->offset).z < -0x32) &&
       ((*(uint *)((int)instance->data + 0x10) & 0x10004) == 0)) {
      INSTANCE_Post(instance,(int)&DAT_00040017,6);
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
 // line 586, offset 0x8007e5c8
	/* begin block 1 */
		// Start line: 1210
	/* end block 1 */
	// End Line: 1211

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
 // line 595, offset 0x8007e5f8
	/* begin block 1 */
		// Start line: 596
		// Start offset: 0x8007E5F8
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	// 		struct _MonsterAttributes *ma; // $s0
	// 		unsigned long ret; // $a0

		/* begin block 1.1 */
			// Start line: 608
			// Start offset: 0x8007E644
			// Variables:
		// 		struct evShadowSegmentData *shadowData; // $v0
		/* end block 1.1 */
		// End offset: 0x8007E644
		// End Line: 609

		/* begin block 1.2 */
			// Start line: 684
			// Start offset: 0x8007E7B0
			// Variables:
		// 		struct _MonsterSaveInfo *saveInfo; // $s0
		/* end block 1.2 */
		// End offset: 0x8007E7B0
		// End Line: 684
	/* end block 1 */
	// End offset: 0x8007E844
	// End Line: 707

	/* begin block 2 */
		// Start line: 1228
	/* end block 2 */
	// End Line: 1229

ulong MonsterQuery(_Instance *instance,ulong query)

{
  MATRIX *pMVar1;
  _MonsterSaveInfo *saveData;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  void *pvVar5;
  
  pvVar5 = instance->data;
  puVar4 = (uint *)instance->extraData;
  pMVar1 = (MATRIX *)0x0;
  if (pvVar5 != (void *)0x0) {
    switch(query) {
    case 0:
      uVar2 = *puVar4;
      pMVar1 = (MATRIX *)0x40000000;
      if ((uVar2 & 0x200) == 0) {
        pMVar1 = (MATRIX *)0x12000000;
        if (instance->currentMainState != 0x1e) {
          pMVar1 = (MATRIX *)0x0;
          if ((uVar2 & 0x200000) == 0) {
            if ((((uVar2 & 0x10) != 0) || (puVar4[0x31] == 0)) ||
               (instance->currentMainState == 0x18)) {
              if (*(char *)(puVar4[0x5a] + 0x29) == '\0') {
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
          if ((*puVar4 & 0x100) != 0) {
            pMVar1 = (MATRIX *)((uint)pMVar1 | 0x20000000);
          }
        }
      }
      break;
    case 1:
      pMVar1 = *(MATRIX **)((int)pvVar5 + 0x10);
      break;
    case 2:
      pMVar1 = (MATRIX *)(uint)*(byte *)(puVar4[0x5a] + 0x27);
      break;
    default:
      pMVar1 = (MATRIX *)GenericQuery(instance,query);
      break;
    case 9:
      pMVar1 = (MATRIX *)&DAT_00000020;
      if ((*puVar4 & 0x400) != 0) {
        pMVar1 = (MATRIX *)&DAT_00000010;
      }
      break;
    case 10:
      pMVar1 = (MATRIX *)puVar4[0x42];
      break;
    case 0xc:
      if (instance->matrix == (MATRIX *)0x0) {
        pMVar1 = (MATRIX *)0x0;
      }
      else {
        pMVar1 = instance->matrix + *(byte *)((int)pvVar5 + 0x19);
      }
      break;
    case 0xd:
      pMVar1 = (MATRIX *)0x0;
      if (instance->matrix != (MATRIX *)0x0) {
        pMVar1 = instance->matrix + 1;
      }
      break;
    case 0xf:
      pMVar1 = (MATRIX *)(uint)*(byte *)((int)pvVar5 + 0x1a);
      break;
    case 0x18:
      saveData = (_MonsterSaveInfo *)CIRC_Alloc(0x10);
      MON_SetUpSaveInfo(instance,saveData);
      pMVar1 = (MATRIX *)SetControlSaveDataData(0x10,saveData);
      break;
    case 0x19:
      pMVar1 = (MATRIX *)(int)*(short *)(puVar4 + 0x52);
      break;
    case 0x21:
      pMVar1 = (MATRIX *)(*puVar4 >> 0x1d & 1);
      break;
    case 0x23:
      pMVar1 = (MATRIX *)PeekMessageQueue((__MessageQueue *)(puVar4 + 2));
      break;
    case 0x26:
      pMVar1 = (MATRIX *)SetShadowSegmentData(2);
      pMVar1->m[1] = (ushort)*(byte *)((int)pvVar5 + 0x20);
      *(ushort *)((int)pMVar1->m + 6) = (ushort)*(byte *)((int)pvVar5 + 0x21);
      break;
    case 0x2f:
      iVar3 = instance->currentMainState;
      if (((1 < iVar3 - 0xbU) && (iVar3 != 4)) && (iVar3 != 10)) {
        return 0;
      }
    case 0x25:
      pMVar1 = (MATRIX *)&UNK_00000001;
    }
  }
  return (ulong)pMVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterMessage(struct _Instance *instance /*$s2*/, unsigned long message /*$s1*/, unsigned long data /*$s3*/)
 // line 713, offset 0x8007e858
	/* begin block 1 */
		// Start line: 714
		// Start offset: 0x8007E858
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 734
			// Start offset: 0x8007E900
		/* end block 1.1 */
		// End offset: 0x8007E90C
		// End Line: 737

		/* begin block 1.2 */
			// Start line: 762
			// Start offset: 0x8007EA00
		/* end block 1.2 */
		// End offset: 0x8007EA00
		// End Line: 764

		/* begin block 1.3 */
			// Start line: 769
			// Start offset: 0x8007EA14
		/* end block 1.3 */
		// End offset: 0x8007EA14
		// End Line: 771
	/* end block 1 */
	// End offset: 0x8007EAD8
	// End Line: 810

	/* begin block 2 */
		// Start line: 1467
	/* end block 2 */
	// End Line: 1468

void MonsterMessage(_Instance *instance,ulong message,ulong data)

{
  uint uVar1;
  int iVar2;
  undefined4 local_18;
  uint *puVar3;
  undefined4 local_14;
  
  puVar3 = (uint *)instance->extraData;
  if (puVar3 != (uint *)0x0) {
    if ((undefined *)message == &DAT_00100007) {
      MON_GetSaveInfo(instance,*(_MonsterSaveInfo **)(data + 4));
    }
    else {
      if (&DAT_00100007 < message) {
        if ((message == 0x1000020) && (uVar1 = puVar3[0x31], uVar1 != 0)) {
          *(ushort *)(uVar1 + 0x16) = *(ushort *)(uVar1 + 0x16) & 0xefff;
        }
      }
      else {
        if ((undefined *)message == &DAT_00040026) {
          PurgeMessageQueue((__MessageQueue *)(puVar3 + 2));
        }
      }
    }
    if ((instance->flags2 & 0x4000000U) == 0) {
      if ((undefined *)message == &DAT_00040013) {
        if (data == 0) {
          *puVar3 = *puVar3 & 0xfff7ffff;
        }
        else {
          *puVar3 = *puVar3 | 0x80000;
        }
      }
      else {
        if (&DAT_00040013 < message) {
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
            if (message == 0x1000024) {
              *puVar3 = *puVar3 | 0x40;
              return;
            }
          }
        }
        else {
          if ((undefined *)message == &DAT_0004000b) {
            (instance->rotation).x = *(short *)data;
            (instance->rotation).y = *(short *)(data + 2);
            (instance->rotation).z = *(short *)(data + 4);
            return;
          }
          if (&DAT_0004000b < message) {
            if ((undefined *)message == &DAT_0004000e) {
              if (data == 0) {
                uVar1 = *puVar3 & 0xfffffffb;
              }
              else {
                uVar1 = *puVar3 | 4;
              }
              *puVar3 = uVar1;
              iVar2 = instance->currentMainState;
              if ((((iVar2 != 1) && (iVar2 != 5)) && (iVar2 != 0x1c)) && (iVar2 != 0x13)) {
                return;
              }
              MON_SwitchStateDoEntry(instance,(MonsterState)CONCAT44(local_14,local_18));
              return;
            }
          }
          else {
            if ((undefined *)message == &DAT_0004000a) {
              STREAM_SetInstancePosition(instance,(evPositionData *)data);
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
 // line 815, offset 0x8007eaf4
	/* begin block 1 */
		// Start line: 816
		// Start offset: 0x8007EAF4
		// Variables:
	// 		struct _G2Anim_Type anim; // stack offset -216
	// 		struct _G2AnimSection_Type *animSection; // $s0
	// 		struct _G2AnimKeylist_Type *keylist; // $s2
	// 		long total; // $s0

		/* begin block 1.1 */
			// Start line: 836
			// Start offset: 0x8007EB98
			// Variables:
		// 		struct _G2SVector3_Type dist; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x8007EC38
		// End Line: 843
	/* end block 1 */
	// End offset: 0x8007EC38
	// End Line: 845

	/* begin block 2 */
		// Start line: 1672
	/* end block 2 */
	// End Line: 1673

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
         (ushort)((int)((uint)mAnim->playSpeed * lVar3 * 100) / ((int)((uint)uVar1 << 0x10) >> 4));
  }
  G2Anim_Free(&_Stack216);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TranslateAnimList(struct Object *object /*$s5*/, struct _MonsterAnim *animList /*$a1*/, int numAnims /*$s6*/)
 // line 969, offset 0x8007ec5c
	/* begin block 1 */
		// Start line: 970
		// Start offset: 0x8007EC5C
		// Variables:
	// 		int i; // $s2

		/* begin block 1.1 */
			// Start line: 973
			// Start offset: 0x8007EC8C
			// Variables:
		// 		struct _MonsterAnim *animPtr; // $s3

			/* begin block 1.1.1 */
				// Start line: 981
				// Start offset: 0x8007EC9C
				// Variables:
			// 		int index; // $a0
			// 		struct _G2AnimKeylist_Type *keylist; // $s4
			/* end block 1.1.1 */
			// End offset: 0x8007ED1C
			// End Line: 1016
		/* end block 1.1 */
		// End offset: 0x8007ED30
		// End Line: 1017
	/* end block 1 */
	// End offset: 0x8007ED30
	// End Line: 1018

	/* begin block 2 */
		// Start line: 1992
	/* end block 2 */
	// End Line: 1993

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
 // line 1027, offset 0x8007ed58
	/* begin block 1 */
		// Start line: 1028
		// Start offset: 0x8007ED58
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $s0
	// 		int i; // $a3

		/* begin block 1.1 */
			// Start line: 1043
			// Start offset: 0x8007ED98
			// Variables:
		// 		void *relocModule; // $v0
		/* end block 1.1 */
		// End offset: 0x8007EDC4
		// End Line: 1068

		/* begin block 1.2 */
			// Start line: 1095
			// Start offset: 0x8007EE04
			// Variables:
		// 		struct _MonsterAttackAttributes *attackAttr; // $v1
		/* end block 1.2 */
		// End offset: 0x8007EE40
		// End Line: 1123

		/* begin block 1.3 */
			// Start line: 1126
			// Start offset: 0x8007EE64
			// Variables:
		// 		struct _MonsterCombatAttributes *combatAttr; // $v1

			/* begin block 1.3.1 */
				// Start line: 1128
				// Start offset: 0x8007EE88
				// Variables:
			// 		int largest; // $a2
			// 		int j; // $a1

				/* begin block 1.3.1.1 */
					// Start line: 1135
					// Start offset: 0x8007EEA4
					// Variables:
				// 		struct _MonsterAttackAttributes *attack; // $v0
				/* end block 1.3.1.1 */
				// End offset: 0x8007EED0
				// End Line: 1138
			/* end block 1.3.1 */
			// End offset: 0x8007EEE8
			// End Line: 1141
		/* end block 1.3 */
		// End offset: 0x8007EEE8
		// End Line: 1145
	/* end block 1 */
	// End offset: 0x8007EEFC
	// End Line: 1161

	/* begin block 2 */
		// Start line: 2147
	/* end block 2 */
	// End Line: 2148

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
         (*(char **)((int)object->relocModule + 0x18) != "Jun 30 1999")) {
        object->data = (void *)0x0;
        return;
      }
    }
    if ((piVar7 != (int *)0x0) && (*piVar7 == -0x531fff9b)) {
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
            if (0 < (int)*(char *)(iVar3 + 0x1d)) {
              iVar2 = iVar3;
              sVar5 = 0;
              do {
                sVar1 = *(short *)(piVar7[0xe] + (int)*(char *)(iVar2 + 0x2c) * 0x20);
                if (sVar5 < sVar1) {
                  sVar5 = sVar1;
                }
                iVar4 = iVar4 + 1;
                iVar2 = iVar3 + iVar4;
              } while (iVar4 < (int)*(char *)(iVar3 + 0x1d));
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
 // line 1166, offset 0x8007ef10
	/* begin block 1 */
		// Start line: 1168
		// Start offset: 0x8007EF10
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $t0

		/* begin block 1.1 */
			// Start line: 1172
			// Start offset: 0x8007EF30
			// Variables:
		// 		int i; // $a3
		// 		struct _MonsterSubAttributes *subAttr; // $a2
		// 		struct _MonsterSubAttributes **pSubAttr; // $t1
		// 		struct _MonsterCombatAttributes **pCombatAttr; // $v0

			/* begin block 1.1.1 */
				// Start line: 1191
				// Start offset: 0x8007F020
				// Variables:
			// 		int j; // $v1
			// 		struct _MonsterSubAttributes **oldSubAttr; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8007F0D8
			// End Line: 1212
		/* end block 1.1 */
		// End offset: 0x8007F124
		// End Line: 1216
	/* end block 1 */
	// End offset: 0x8007F124
	// End Line: 1217

	/* begin block 2 */
		// Start line: 2488
	/* end block 2 */
	// End Line: 2489

	/* begin block 3 */
		// Start line: 2489
	/* end block 3 */
	// End Line: 2490

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
  if ((piVar2 != (int *)0x0) && (*piVar2 == -0x531fff9b)) {
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
 // line 1222, offset 0x8007f12c
	/* begin block 1 */
		// Start line: 1224
		// Start offset: 0x8007F12C
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x8007F248
	// End Line: 1245

	/* begin block 2 */
		// Start line: 2630
	/* end block 2 */
	// End Line: 2631

	/* begin block 3 */
		// Start line: 2631
	/* end block 3 */
	// End Line: 2632

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
    if (*(int *)((int)pvVar1 + 0x168) != 0) {
      iVar6 = *(int *)((int)pvVar1 + 0x168) + offset;
    }
    iVar7 = 0;
    *(int *)((int)pvVar1 + 0x168) = iVar6;
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
      pvVar1 = instance->object->relocModule;
      if (pvVar1 < *(void **)((int)pvVar1 + 0xc)) {
        p_Var2 = (_func_4 *)0x0;
        if (instance->queryFunc != (_func_4 *)0x0) {
          p_Var2 = instance->queryFunc + offset;
        }
        instance->queryFunc = p_Var2;
      }
      pvVar1 = instance->object->relocModule;
      if (pvVar1 < *(void **)((int)pvVar1 + 0x10)) {
        p_Var3 = (_func_5 *)0x0;
        if (instance->messageFunc != (_func_5 *)0x0) {
          p_Var3 = instance->messageFunc + offset;
        }
        instance->messageFunc = p_Var3;
      }
      p_Var5 = instance->collideFunc;
      if ((p_Var5 != MonsterCollide) && (instance->object->relocModule < p_Var5)) {
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
 // line 1294, offset 0x8007f250
	/* begin block 1 */
		// Start line: 2588
	/* end block 1 */
	// End Line: 2589

void MONAPI_TurnHead(_Instance *instance,short *rotx,short *rotz,GameTracker *gameTracker)

{
  short sVar1;
  
  sVar1 = -0x300;
  if ((*rotx < -0x300) || (sVar1 = 0x200, 0x200 < *rotx)) {
    *rotx = sVar1;
  }
  if (*rotz < 0x401) {
    sVar1 = -0x400;
    if (-0x401 < *rotz) goto LAB_8007f2a4;
  }
  else {
    sVar1 = 0x400;
  }
  *rotz = sVar1;
LAB_8007f2a4:
  MON_LookInDirection(instance,-*rotx,*rotz);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_SetLookAround(struct _Instance *instance /*$a0*/)
 // line 1315, offset 0x8007f2cc
	/* begin block 1 */
		// Start line: 1316
		// Start offset: 0x8007F2CC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007F2CC
	// End Line: 1316

	/* begin block 2 */
		// Start line: 2766
	/* end block 2 */
	// End Line: 2767

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
 // line 1324, offset 0x8007f2fc
	/* begin block 1 */
		// Start line: 1325
		// Start offset: 0x8007F2FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007F2FC
	// End Line: 1325

	/* begin block 2 */
		// Start line: 2784
	/* end block 2 */
	// End Line: 2785

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
 // line 1333, offset 0x8007f32c
	/* begin block 1 */
		// Start line: 2802
	/* end block 1 */
	// End Line: 2803

	/* begin block 2 */
		// Start line: 2803
	/* end block 2 */
	// End Line: 2804

long MONAPI_OkToLookAround(_Instance *instance)

{
  return (uint)(instance->currentMainState == 2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen /*$a0*/)
 // line 1338, offset 0x8007f340
	/* begin block 1 */
		// Start line: 2812
	/* end block 1 */
	// End Line: 2813

	/* begin block 2 */
		// Start line: 2815
	/* end block 2 */
	// End Line: 2816

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
 // line 1349, offset 0x8007f38c
	/* begin block 1 */
		// Start line: 1350
		// Start offset: 0x8007F38C
		// Variables:
	// 		int i; // $s2
	// 		struct _MONAPI_Regenerator *regen; // $s0

		/* begin block 1.1 */
			// Start line: 1358
			// Start offset: 0x8007F3CC
			// Variables:
		// 		unsigned long time; // $v1

			/* begin block 1.1.1 */
				// Start line: 1367
				// Start offset: 0x8007F400
				// Variables:
			// 		struct Level *level; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 1370
					// Start offset: 0x8007F414
					// Variables:
				// 		struct Intro *intro; // $a0
				// 		int j; // $a1
				// 		long id; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x8007F474
				// End Line: 1388
			/* end block 1.1.1 */
			// End offset: 0x8007F47C
			// End Line: 1391
		/* end block 1.1 */
		// End offset: 0x8007F498
		// End Line: 1399
	/* end block 1 */
	// End offset: 0x8007F4B4
	// End Line: 1401

	/* begin block 2 */
		// Start line: 2838
	/* end block 2 */
	// End Line: 2839

	/* begin block 3 */
		// Start line: 2842
	/* end block 3 */
	// End Line: 2843

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MONAPI_ProcessGenerator(void)

{
  Level *pLVar1;
  _Instance *p_Var2;
  ulong uVar3;
  uint *puVar4;
  Intro *intro;
  int iVar5;
  _MONAPI_Regenerator *regen;
  short *psVar6;
  int iVar7;
  
  regen = GlobalSave->regenEntries;
  if (((GlobalSave->flags & 1U) == 0) && (iVar7 = 0, '\0' < GlobalSave->numRegens)) {
    psVar6 = &GlobalSave->regenEntries[0].streamUnitID;
    do {
      uVar3 = gameTrackerX.currentMaterialTime;
      if (gameTrackerX.gameData.asmData.MorphType != 0) {
        uVar3 = gameTrackerX.currentSpectralTime;
      }
      if (regen->regenTime < uVar3) {
        pLVar1 = STREAM_GetLevelWithID((int)*psVar6);
        if (pLVar1 == (Level *)0x0) {
LAB_8007f47c:
          MONAPI_DeleteRegen(regen);
        }
        else {
          iVar5 = pLVar1->numIntros;
          intro = pLVar1->introList;
          puVar4 = (uint *)&intro->flags;
          while (iVar5 != 0) {
            iVar5 = iVar5 + -1;
            if (puVar4[-6] == (int)psVar6[-1]) {
              if (((*puVar4 & 0x400) != 0) ||
                 (p_Var2 = INSTANCE_IntroduceInstance(intro,*psVar6), p_Var2 == (_Instance *)0x0))
              goto LAB_8007f47c;
              break;
            }
            puVar4 = puVar4 + 0x13;
            intro = intro + 1;
          }
        }
      }
      else {
        iVar7 = iVar7 + 1;
        psVar6 = psVar6 + 4;
        regen = regen + 1;
      }
    } while (iVar7 < GlobalSave->numRegens);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_AddToGenerator(struct _Instance *instance /*$s2*/)
 // line 1403, offset 0x8007f4cc
	/* begin block 1 */
		// Start line: 1404
		// Start offset: 0x8007F4CC

		/* begin block 1.1 */
			// Start line: 1408
			// Start offset: 0x8007F4FC
			// Variables:
		// 		struct _MonsterVars *mv; // $s1
		// 		struct _MONAPI_Regenerator *regen; // $s0
		/* end block 1.1 */
		// End offset: 0x8007F554
		// End Line: 1415
	/* end block 1 */
	// End offset: 0x8007F554
	// End Line: 1416

	/* begin block 2 */
		// Start line: 3018
	/* end block 2 */
	// End Line: 3019

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
    p_Var2->regenTime = uVar1 + (int)*(short *)((int)pvVar3 + 0x14a) * 1000;
    p_Var2->introUniqueID = *(short *)&instance->introUniqueID;
    p_Var2->streamUnitID = *(short *)&instance->birthStreamUnitID;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_CheckGenerator(struct _Instance *instance /*$a0*/)
 // line 1421, offset 0x8007f56c
	/* begin block 1 */
		// Start line: 1422
		// Start offset: 0x8007F56C
		// Variables:
	// 		int i; // $a1
	// 		struct _MONAPI_Regenerator *regen; // $v1
	// 		int id; // $a0
	/* end block 1 */
	// End offset: 0x8007F5C8
	// End Line: 1434

	/* begin block 2 */
		// Start line: 3057
	/* end block 2 */
	// End Line: 3058

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





