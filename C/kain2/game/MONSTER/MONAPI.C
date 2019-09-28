#include "THISDUST.H"
#include "MONAPI.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MonsterProcess(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 165, offset 0x8007da80
	/* begin block 1 */
		// Start line: 166
		// Start offset: 0x8007DA80
		// Variables:
	// 		struct _MonsterState *state; // $s0
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAttributes *attributes; // $v0
	/* end block 1 */
	// End offset: 0x8007DBA0
	// End Line: 237

	/* begin block 2 */
		// Start line: 330
	/* end block 2 */
	// End Line: 331

_Instance * MISSILE_Find(_Instance *instance,_MonsterMissile *missiledef)

{
  _MonsterState *p_Var1;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar2;
  _Instance *p_Var3;
  uint *puVar4;
  
  puVar4 = (uint *)instance->extraData;
  p_Var3 = (_Instance *)instance->data;
  if (((puVar4 != (uint *)0x0) && (p_Var3 != (_Instance *)0x0)) &&
     (p_Var3 = (_Instance *)(*puVar4 & 0x80000), p_Var3 == (_Instance *)0x0)) {
    instance->waterFace = (_TFace *)0x0;
    instance->waterFaceTerrain = (_Terrain *)0x0;
    MONSENSE_DoSenses(instance);
    MON_DoCombatTimers(instance);
    p_Var1 = MONTABLE_GetStateFuncs(instance,instance->currentMainState);
    instance->flags2 = instance->flags2 & 0xffffffed;
    if ((*puVar4 & 0x80) == 0) {
      G2EmulationInstancePlayAnimation(instance);
    }
    (*p_Var1->stateFunction)(instance);
    if ((*puVar4 & 1) != 0) {
      p_Var1 = MONTABLE_GetStateFuncs(instance,instance->currentMainState);
      (*p_Var1->entryFunction)(instance);
    }
    *puVar4 = *puVar4 & 0xffffffbe;
    p_Var3 = (_Instance *)(instance->flags & 0x200);
    if (p_Var3 != (_Instance *)0x0) {
      pTVar2 = MONTABLE_GetDamageEffectFunc(instance);
      p_Var3 = (_Instance *)(*pTVar2)(instance,0);
    }
    MON_ProcessLookAt(instance);
    MON_ProcessSpecialFade(instance);
  }
  return p_Var3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 243, offset 0x8007dbb8
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x8007DBB8
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $s2
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 262
			// Start offset: 0x8007DC24
		/* end block 1.1 */
		// End offset: 0x8007DC24
		// End Line: 282

		/* begin block 1.2 */
			// Start line: 349
			// Start offset: 0x8007DD7C
		/* end block 1.2 */
		// End offset: 0x8007DDA8
		// End Line: 354
	/* end block 1 */
	// End offset: 0x8007DDA8
	// End Line: 356

	/* begin block 2 */
		// Start line: 491
	/* end block 2 */
	// End Line: 492

void MonsterInit(_Instance *instance,GameTracker *gameTracker)

{
  TDRFuncPtr_MONTABLE_GetCleanUpFunc pTVar1;
  _G2AnimKeylist_Type *keylist;
  char *address;
  
  if ((instance->flags & 0x20000U) != 0) {
    address = (char *)instance->extraData;
    pTVar1 = MONTABLE_GetCleanUpFunc(instance);
    (*pTVar1)(instance);
    MONSENSE_RemoveSenses(instance);
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free(address);
  }
  if (((int *)instance->data != (int *)0x0) && (*(int *)instance->data == -0x531fff9b)) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Malloc(0x24c,'\x17');
  }
  instance->data = (void *)0x0;
  keylist = G2Instance_GetKeylist(instance,0);
  G2Anim_SwitchToKeylist(&instance->anim,keylist,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SendHitObject(struct _Instance *instance /*$s1*/, struct _Instance *hit /*$s0*/, int type /*$s2*/)
 // line 358, offset 0x8007ddc0
	/* begin block 1 */
		// Start line: 359
		// Start offset: 0x8007DDC0
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	// 		int i; // $a0

		/* begin block 1.1 */
			// Start line: 365
			// Start offset: 0x8007DE10
			// Variables:
		// 		struct evMonsterHitObjectData *data1; // $v0
		/* end block 1.1 */
		// End offset: 0x8007DE28
		// End Line: 368

		/* begin block 1.2 */
			// Start line: 377
			// Start offset: 0x8007DE58
			// Variables:
		// 		struct evMonsterHitObjectData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x8007DE7C
		// End Line: 381
	/* end block 1 */
	// End offset: 0x8007DE7C
	// End Line: 382

	/* begin block 2 */
		// Start line: 732
	/* end block 2 */
	// End Line: 733

/* WARNING: Type propagation algorithm not settling */

void SendHitObject(_Instance *instance,_Instance *hit,int type)

{
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
                    /* WARNING: Subroutine does not return */
    CIRC_Alloc(8);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterCollide(struct _Instance *instance /*$s3*/, struct GameTracker *gameTracker /*$a1*/)
 // line 388, offset 0x8007de94
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x8007DE94
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s1
	// 		struct _MonsterVars *mv; // $s6

		/* begin block 1.1 */
			// Start line: 398
			// Start offset: 0x8007DEE4
			// Variables:
		// 		struct _HSphere *s0; // $v0

			/* begin block 1.1.1 */
				// Start line: 412
				// Start offset: 0x8007DF1C
				// Variables:
			// 		struct _HSphere *s1; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 415
					// Start offset: 0x8007DF34
					// Variables:
				// 		struct _Instance *inst1; // $s4
				// 		int power; // $s0
				/* end block 1.1.1.1 */
				// End offset: 0x8007DFF4
				// End Line: 436
			/* end block 1.1.1 */
			// End offset: 0x8007DFF4
			// End Line: 436

			/* begin block 1.1.2 */
				// Start line: 452
				// Start offset: 0x8007E010
				// Variables:
			// 		int move; // $s7

				/* begin block 1.1.2.1 */
					// Start line: 458
					// Start offset: 0x8007E048
					// Variables:
				// 		struct _HSphere *hsphere; // $s0
				/* end block 1.1.2.1 */
				// End offset: 0x8007E09C
				// End Line: 466

				/* begin block 1.1.2.2 */
					// Start line: 496
					// Start offset: 0x8007E11C
					// Variables:
				// 		struct BSPTree *bsp; // $s4

					/* begin block 1.1.2.2.1 */
						// Start line: 503
						// Start offset: 0x8007E158
						// Variables:
					// 		struct evMonsterHitTerrainData *data; // $s0
					// 		struct Level *level; // $s5
					// 		struct Intro *impaler; // $v0
					// 		struct _TFace *tface; // $s2

						/* begin block 1.1.2.2.1.1 */
							// Start line: 534
							// Start offset: 0x8007E2A0
							// Variables:
						// 		struct _CollideInfo parentCI; // stack offset -88
						/* end block 1.1.2.2.1.1 */
						// End offset: 0x8007E30C
						// End Line: 541
					/* end block 1.1.2.2.1 */
					// End offset: 0x8007E330
					// End Line: 545
				/* end block 1.1.2.2 */
				// End offset: 0x8007E334
				// End Line: 550
			/* end block 1.1.2 */
			// End offset: 0x8007E37C
			// End Line: 576
		/* end block 1.1 */
		// End offset: 0x8007E37C
		// End Line: 577
	/* end block 1 */
	// End offset: 0x8007E37C
	// End Line: 581

	/* begin block 2 */
		// Start line: 798
	/* end block 2 */
	// End Line: 799

void MonsterCollide(_Instance *instance,GameTracker *gameTracker)

{
  bool bVar1;
  int Data;
  void *pvVar2;
  uint uVar3;
  _Instance *Inst;
  BSPTree *bsp;
  
  pvVar2 = instance->collideInfo;
  if (instance->data == (void *)0x0) {
    return;
  }
  if (*(char *)((int)pvVar2 + 6) != '\x01') {
    return;
  }
  if (*(char *)(*(int *)((int)pvVar2 + 8) + 4) == '\t') {
    uVar3 = *(uint *)(instance->extraData + 0x2e);
    if (uVar3 == 0) {
      return;
    }
    if (*(char *)((int)pvVar2 + 7) != '\x01') {
      return;
    }
    if (*(char *)(*(int *)((int)pvVar2 + 0xc) + 4) != '\b') {
      return;
    }
    Data = (int)*(char *)(uVar3 + 7);
    Inst = *(_Instance **)((int)pvVar2 + 0x14);
    if ((*(uint *)instance->extraData & 0x20000000) != 0) {
      Data = Data << 1;
    }
    MON_TurnOffWeaponSpheres(instance);
    Data = Data * 0x100;
    if (Data < 0) {
      Data = Data + 0x7f;
    }
    Data = SetFXHitData(instance,(uint)*(byte *)((int)pvVar2 + 5),Data >> 7,0x100);
                    /* WARNING: Subroutine does not return */
    INSTANCE_Post(Inst,0x400000,Data);
  }
  bVar1 = true;
  switch(*(undefined *)((int)pvVar2 + 7)) {
  case 1:
    Data = *(int *)((int)pvVar2 + 0xc);
    SendHitObject(instance,*(_Instance **)((int)pvVar2 + 0x14),1);
    if (*(char *)(Data + 4) != '\t') {
      if ((*(int *)&instance->position == *(int *)&instance->oldPos) &&
         ((instance->position).z == (instance->oldPos).z)) {
        bVar1 = false;
      }
      break;
    }
    goto LAB_8007e330;
  case 2:
    SendHitObject(instance,*(_Instance **)((int)pvVar2 + 0x14),2);
    break;
  case 3:
    bsp = *(BSPTree **)((int)pvVar2 + 0x14);
    if ((bsp->flags & 0xe0U) != 0) {
      MON_CheckTerrainAndRespond(instance,bsp,*(_TFace **)((int)pvVar2 + 0xc));
    }
    if ((bsp->flags & 0x102U) == 0) {
                    /* WARNING: Subroutine does not return */
      CIRC_Alloc(0x10);
    }
LAB_8007e330:
    bVar1 = false;
    break;
  case 5:
    if ((((instance->flags2 & 0x8000000U) == 0) && (*(short *)((int)pvVar2 + 0x2c) < -0x32)) &&
       ((*(uint *)((int)instance->data + 0x10) & 0x10004) == 0)) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Post(instance,(int)&LAB_00040014_3,6);
    }
    SendHitObject(instance,*(_Instance **)((int)pvVar2 + 0x14),5);
  }
  if (!bVar1) {
    return;
  }
  (instance->position).x = (instance->position).x + *(short *)((int)pvVar2 + 0x28);
  (instance->position).y = (instance->position).y + *(short *)((int)pvVar2 + 0x2a);
                    /* WARNING: Subroutine does not return */
  (instance->position).z = (instance->position).z + *(short *)((int)pvVar2 + 0x2c);
  COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)((int)pvVar2 + 0x28));
}



// decompiled code
// original method signature: 
// void /*$ra*/ MonsterAdditionalCollide(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 586, offset 0x8007e3a8
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
 // line 595, offset 0x8007e3d8
	/* begin block 1 */
		// Start line: 596
		// Start offset: 0x8007E3D8
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	// 		struct _MonsterAttributes *ma; // $s0
	// 		unsigned long ret; // $a0

		/* begin block 1.1 */
			// Start line: 608
			// Start offset: 0x8007E424
			// Variables:
		// 		struct evShadowSegmentData *shadowData; // $v0
		/* end block 1.1 */
		// End offset: 0x8007E424
		// End Line: 609

		/* begin block 1.2 */
			// Start line: 684
			// Start offset: 0x8007E590
			// Variables:
		// 		struct _MonsterSaveInfo *saveInfo; // $s0
		/* end block 1.2 */
		// End offset: 0x8007E590
		// End Line: 684
	/* end block 1 */
	// End offset: 0x8007E624
	// End Line: 707

	/* begin block 2 */
		// Start line: 1228
	/* end block 2 */
	// End Line: 1229

ulong MonsterQuery(_Instance *instance,ulong query)

{
  MATRIX *pMVar1;
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
              if (*(char *)(puVar4[0x55] + 0x29) == '\0') {
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
      pMVar1 = (MATRIX *)(uint)*(byte *)(puVar4[0x55] + 0x27);
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
      pMVar1 = (MATRIX *)puVar4[0x3d];
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
                    /* WARNING: Subroutine does not return */
      CIRC_Alloc(0x10);
    case 0x19:
      pMVar1 = (MATRIX *)(int)*(short *)(puVar4 + 0x4d);
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
 // line 713, offset 0x8007e638
	/* begin block 1 */
		// Start line: 714
		// Start offset: 0x8007E638
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 739
			// Start offset: 0x8007E70C
		/* end block 1.1 */
		// End offset: 0x8007E718
		// End Line: 742

		/* begin block 1.2 */
			// Start line: 767
			// Start offset: 0x8007E80C
		/* end block 1.2 */
		// End offset: 0x8007E80C
		// End Line: 769

		/* begin block 1.3 */
			// Start line: 774
			// Start offset: 0x8007E820
		/* end block 1.3 */
		// End offset: 0x8007E820
		// End Line: 776
	/* end block 1 */
	// End offset: 0x8007E8E4
	// End Line: 815

	/* begin block 2 */
		// Start line: 1467
	/* end block 2 */
	// End Line: 1468

void MonsterMessage(_Instance *instance,ulong message,ulong data)

{
  uint uVar1;
  int iVar2;
  _MonsterSaveInfo *saveData;
  ulong data_00;
  undefined4 local_18;
  uint *puVar3;
  undefined4 local_14;
  
  puVar3 = (uint *)instance->extraData;
  if (puVar3 != (uint *)0x0) {
    data_00 = data;
    if ((undefined *)message == &DAT_00100007) {
      saveData = *(_MonsterSaveInfo **)(data + 4);
      MON_GetSaveInfo(instance,saveData);
    }
    else {
      saveData = (_MonsterSaveInfo *)message;
      if (&DAT_00100007 < message) {
        if (message == 0x1000020) {
          uVar1 = puVar3[0x31];
          if (uVar1 != 0) {
            *(ushort *)(uVar1 + 0x16) = *(ushort *)(uVar1 + 0x16) & 0xefff;
          }
          if ((*(char *)(puVar3 + 0x51) == '\x03') && (puVar3[0x37] != 0)) {
                    /* WARNING: Subroutine does not return */
            SndEndLoop(puVar3[0x37]);
          }
        }
      }
      else {
        if ((undefined **)message == &PTR_00040026) {
                    /* WARNING: Subroutine does not return */
          PurgeMessageQueue((__MessageQueue *)(puVar3 + 2));
        }
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
          if ((undefined *)message == &DAT_0004000b) {
            (instance->rotation).x = *(short *)data;
            (instance->rotation).y = *(short *)(data + 2);
            (instance->rotation).z = *(short *)(data + 4);
          }
          else {
            if (&DAT_0004000b < message) {
              if ((undefined *)message != &LAB_0004000c_2) goto LAB_8007e8dc;
              if (data == 0) {
                MonsterMessage((_Instance *)(puVar3 + 2),(ulong)saveData,data_00);
                return;
              }
              *puVar3 = *puVar3 | 4;
              iVar2 = instance->currentMainState;
              if ((((iVar2 == 1) || (iVar2 == 5)) || (iVar2 == 0x1c)) || (iVar2 == 0x13)) {
                MON_SwitchStateDoEntry(instance,(MonsterState)CONCAT44(local_14,local_18));
              }
            }
            else {
              if ((undefined *)message != &DAT_0004000a) {
LAB_8007e8dc:
                    /* WARNING: Subroutine does not return */
                EnMessageQueueData((__MessageQueue *)(puVar3 + 2),message,data);
              }
              RelocateTerrain((_Terrain *)instance,(_SVector *)data);
            }
          }
        }
        else {
          if (message == 0x200000) {
            MONSENSE_StartMonsterIRList(instance);
          }
          else {
            if (message < 0x200001) {
              if ((undefined *)message != &DAT_00100008) goto LAB_8007e8dc;
              MON_ShouldIFireAtTarget(instance,(_MonsterIR *)data);
            }
            else {
              if (message == 0x200001) {
                MONSENSE_SenseInstance(instance,(evCollideInstanceStatsData *)data);
              }
              else {
                if (message != 0x1000024) goto LAB_8007e8dc;
                *puVar3 = *puVar3 | 0x40;
              }
            }
          }
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ AnimDistanceAndVel(struct Object *object /*$s1*/, struct _MonsterAnim *mAnim /*$s3*/)
 // line 820, offset 0x8007e900
	/* begin block 1 */
		// Start line: 821
		// Start offset: 0x8007E900
		// Variables:
	// 		struct _G2Anim_Type anim; // stack offset -216
	// 		struct _G2AnimSection_Type *animSection; // $s0
	// 		struct _G2AnimKeylist_Type *keylist; // $s2
	// 		long total; // $s0

		/* begin block 1.1 */
			// Start line: 841
			// Start offset: 0x8007E9A4
			// Variables:
		// 		struct _G2SVector3_Type dist; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x8007EA44
		// End Line: 848
	/* end block 1 */
	// End offset: 0x8007EA44
	// End Line: 850

	/* begin block 2 */
		// Start line: 1682
	/* end block 2 */
	// End Line: 1683

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
 // line 974, offset 0x8007ea68
	/* begin block 1 */
		// Start line: 975
		// Start offset: 0x8007EA68
		// Variables:
	// 		int i; // $s2

		/* begin block 1.1 */
			// Start line: 978
			// Start offset: 0x8007EA98
			// Variables:
		// 		struct _MonsterAnim *animPtr; // $s3

			/* begin block 1.1.1 */
				// Start line: 986
				// Start offset: 0x8007EAA8
				// Variables:
			// 		int index; // $a0
			// 		struct _G2AnimKeylist_Type *keylist; // $s4
			/* end block 1.1.1 */
			// End offset: 0x8007EB28
			// End Line: 1021
		/* end block 1.1 */
		// End offset: 0x8007EB3C
		// End Line: 1022
	/* end block 1 */
	// End offset: 0x8007EB3C
	// End Line: 1023

	/* begin block 2 */
		// Start line: 2002
	/* end block 2 */
	// End Line: 2003

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
 // line 1032, offset 0x8007eb64
	/* begin block 1 */
		// Start line: 1033
		// Start offset: 0x8007EB64
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $s0
	// 		int i; // $a3

		/* begin block 1.1 */
			// Start line: 1048
			// Start offset: 0x8007EBA4
			// Variables:
		// 		void *relocModule; // $v0
		/* end block 1.1 */
		// End offset: 0x8007EBD0
		// End Line: 1073

		/* begin block 1.2 */
			// Start line: 1100
			// Start offset: 0x8007EC10
			// Variables:
		// 		struct _MonsterAttackAttributes *attackAttr; // $v1
		/* end block 1.2 */
		// End offset: 0x8007EC4C
		// End Line: 1128

		/* begin block 1.3 */
			// Start line: 1131
			// Start offset: 0x8007EC70
			// Variables:
		// 		struct _MonsterCombatAttributes *combatAttr; // $v1

			/* begin block 1.3.1 */
				// Start line: 1133
				// Start offset: 0x8007EC94
				// Variables:
			// 		int largest; // $a2
			// 		int j; // $a1

				/* begin block 1.3.1.1 */
					// Start line: 1140
					// Start offset: 0x8007ECB0
					// Variables:
				// 		struct _MonsterAttackAttributes *attack; // $v0
				/* end block 1.3.1.1 */
				// End offset: 0x8007ECDC
				// End Line: 1143
			/* end block 1.3.1 */
			// End offset: 0x8007ECF4
			// End Line: 1146
		/* end block 1.3 */
		// End offset: 0x8007ECF4
		// End Line: 1150
	/* end block 1 */
	// End offset: 0x8007ED08
	// End Line: 1166

	/* begin block 2 */
		// Start line: 2157
	/* end block 2 */
	// End Line: 2158

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
         (*(char **)((int)object->relocModule + 0x18) != monVersion)) {
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
 // line 1171, offset 0x8007ed1c
	/* begin block 1 */
		// Start line: 1173
		// Start offset: 0x8007ED1C
		// Variables:
	// 		struct _MonsterAttributes *attributes; // $t0

		/* begin block 1.1 */
			// Start line: 1177
			// Start offset: 0x8007ED3C
			// Variables:
		// 		int i; // $a3
		// 		struct _MonsterSubAttributes *subAttr; // $a2
		// 		struct _MonsterSubAttributes **pSubAttr; // $t1
		// 		struct _MonsterCombatAttributes **pCombatAttr; // $v0

			/* begin block 1.1.1 */
				// Start line: 1196
				// Start offset: 0x8007EE2C
				// Variables:
			// 		int j; // $v1
			// 		struct _MonsterSubAttributes **oldSubAttr; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8007EEE4
			// End Line: 1217
		/* end block 1.1 */
		// End offset: 0x8007EF30
		// End Line: 1221
	/* end block 1 */
	// End offset: 0x8007EF30
	// End Line: 1222

	/* begin block 2 */
		// Start line: 2498
	/* end block 2 */
	// End Line: 2499

	/* begin block 3 */
		// Start line: 2499
	/* end block 3 */
	// End Line: 2500

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
 // line 1227, offset 0x8007ef38
	/* begin block 1 */
		// Start line: 1229
		// Start offset: 0x8007EF38
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x8007F054
	// End Line: 1250

	/* begin block 2 */
		// Start line: 2640
	/* end block 2 */
	// End Line: 2641

	/* begin block 3 */
		// Start line: 2641
	/* end block 3 */
	// End Line: 2642

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
    if (*(int *)((int)pvVar1 + 0x154) != 0) {
      iVar6 = *(int *)((int)pvVar1 + 0x154) + offset;
    }
    iVar7 = 0;
    *(int *)((int)pvVar1 + 0x154) = iVar6;
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
 // line 1299, offset 0x8007f05c
	/* begin block 1 */
		// Start line: 2598
	/* end block 1 */
	// End Line: 2599

void MONAPI_DeleteRegen(_MONAPI_Regenerator *regen)

{
  short sVar1;
  short *in_a1;
  short *in_a2;
  
  sVar1 = -0x300;
  if ((*in_a1 < -0x300) || (sVar1 = 0x200, 0x200 < *in_a1)) {
    *in_a1 = sVar1;
  }
  if (*in_a2 < 0x401) {
    sVar1 = -0x400;
    if (-0x401 < *in_a2) goto LAB_8007f0b0;
  }
  else {
    sVar1 = 0x400;
  }
  *in_a2 = sVar1;
LAB_8007f0b0:
  MON_LookInDirection((_Instance *)regen,-*in_a1,*in_a2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_SetLookAround(struct _Instance *instance /*$a0*/)
 // line 1320, offset 0x8007f0d8
	/* begin block 1 */
		// Start line: 1321
		// Start offset: 0x8007F0D8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007F0D8
	// End Line: 1321

	/* begin block 2 */
		// Start line: 2776
	/* end block 2 */
	// End Line: 2777

void MONAPI_SetLookAround(_Instance *param_1)

{
  void *pvVar1;
  
  pvVar1 = param_1->extraData;
  MON_EnableHeadMove(param_1);
  *(undefined4 *)((int)pvVar1 + 0xf4) = 0x80000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_ResetLookAround(struct _Instance *instance /*$a0*/)
 // line 1329, offset 0x8007f108
	/* begin block 1 */
		// Start line: 1330
		// Start offset: 0x8007F108
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007F108
	// End Line: 1330

	/* begin block 2 */
		// Start line: 2794
	/* end block 2 */
	// End Line: 2795

void MONAPI_ResetLookAround(_Instance *param_1)

{
  void *pvVar1;
  
  pvVar1 = param_1->extraData;
  MON_DisableHeadMove(param_1);
  *(undefined4 *)((int)pvVar1 + 0xf4) = 1;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MONAPI_OkToLookAround(struct _Instance *instance /*$a0*/)
 // line 1338, offset 0x8007f138
	/* begin block 1 */
		// Start line: 2812
	/* end block 1 */
	// End Line: 2813

	/* begin block 2 */
		// Start line: 2813
	/* end block 2 */
	// End Line: 2814

uint MONAPI_OkToLookAround(int param_1)

{
  return (uint)(*(int *)(param_1 + 0x178) == 2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_DeleteRegen(struct _MONAPI_Regenerator *regen /*$a0*/)
 // line 1343, offset 0x8007f14c
	/* begin block 1 */
		// Start line: 2822
	/* end block 1 */
	// End Line: 2823

	/* begin block 2 */
		// Start line: 2825
	/* end block 2 */
	// End Line: 2826

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
 // line 1354, offset 0x8007f198
	/* begin block 1 */
		// Start line: 1355
		// Start offset: 0x8007F198
		// Variables:
	// 		int i; // $s2
	// 		struct _MONAPI_Regenerator *regen; // $s0

		/* begin block 1.1 */
			// Start line: 1363
			// Start offset: 0x8007F1D8
			// Variables:
		// 		unsigned long time; // $v1

			/* begin block 1.1.1 */
				// Start line: 1372
				// Start offset: 0x8007F20C
				// Variables:
			// 		struct Level *level; // $v0

				/* begin block 1.1.1.1 */
					// Start line: 1375
					// Start offset: 0x8007F220
					// Variables:
				// 		struct Intro *intro; // $a0
				// 		int j; // $a1
				// 		long id; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x8007F280
				// End Line: 1393
			/* end block 1.1.1 */
			// End offset: 0x8007F288
			// End Line: 1396
		/* end block 1.1 */
		// End offset: 0x8007F2A4
		// End Line: 1404
	/* end block 1 */
	// End offset: 0x8007F2C0
	// End Line: 1406

	/* begin block 2 */
		// Start line: 2848
	/* end block 2 */
	// End Line: 2849

	/* begin block 3 */
		// Start line: 2852
	/* end block 3 */
	// End Line: 2853

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MONAPI_ProcessGenerator(void)

{
  uint uVar1;
  _MONAPI_Regenerator *p_Var2;
  short *psVar3;
  int iVar4;
  
  p_Var2 = GlobalSave->regenEntries;
  if (((GlobalSave->flags & 1U) == 0) && (iVar4 = 0, '\0' < GlobalSave->numRegens)) {
    psVar3 = &GlobalSave->regenEntries[0].streamUnitID;
    do {
      uVar1 = theCamera.focusDistanceList[1][2];
      if (theCamera.core.vvNormalWorVecMat[0]._18_2_ != 0) {
        uVar1 = theCamera.focusDistanceList[2][0];
      }
      if (p_Var2->regenTime < uVar1) {
                    /* WARNING: Subroutine does not return */
        STREAM_GetLevelWithID((int)*psVar3);
      }
      iVar4 = iVar4 + 1;
      psVar3 = psVar3 + 4;
      p_Var2 = p_Var2 + 1;
    } while (iVar4 < GlobalSave->numRegens);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_AddToGenerator(struct _Instance *instance /*$s2*/)
 // line 1408, offset 0x8007f2d8
	/* begin block 1 */
		// Start line: 1409
		// Start offset: 0x8007F2D8

		/* begin block 1.1 */
			// Start line: 1413
			// Start offset: 0x8007F308
			// Variables:
		// 		struct _MonsterVars *mv; // $s1
		// 		struct _MONAPI_Regenerator *regen; // $s0
		/* end block 1.1 */
		// End offset: 0x8007F360
		// End Line: 1420
	/* end block 1 */
	// End offset: 0x8007F360
	// End Line: 1421

	/* begin block 2 */
		// Start line: 3028
	/* end block 2 */
	// End Line: 3029

void MONAPI_AddToGenerator(_Instance *instance)

{
  if (GlobalSave->numRegens < '\t') {
    GlobalSave->numRegens = GlobalSave->numRegens + '\x01';
                    /* WARNING: Subroutine does not return */
    MON_GetTime(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONAPI_CheckGenerator(struct _Instance *instance /*$a0*/)
 // line 1426, offset 0x8007f378
	/* begin block 1 */
		// Start line: 1427
		// Start offset: 0x8007F378
		// Variables:
	// 		int i; // $a1
	// 		struct _MONAPI_Regenerator *regen; // $v1
	// 		int id; // $a0
	/* end block 1 */
	// End offset: 0x8007F3D4
	// End Line: 1439

	/* begin block 2 */
		// Start line: 3067
	/* end block 2 */
	// End Line: 3068

void MONAPI_CheckGenerator(_Instance *instance)

{
  _Instance *instance_00;
  int iVar1;
  
  instance_00 = (_Instance *)GlobalSave->regenEntries;
  iVar1 = 0;
  if (GlobalSave->numRegens < '\x01') {
    MON_TurnOnWeaponSpheres((_Instance *)instance->introUniqueID);
    return;
  }
  do {
    iVar1 = iVar1 + 1;
    if ((_Instance *)(int)*(short *)&(instance_00->node).next ==
        (_Instance *)instance->introUniqueID) {
      MONAPI_DeleteRegen((_MONAPI_Regenerator *)instance_00);
      MON_TurnOnWeaponSpheres(instance_00);
      return;
    }
    instance_00 = (_Instance *)&instance_00->next;
  } while (iVar1 < GlobalSave->numRegens);
  return;
}





