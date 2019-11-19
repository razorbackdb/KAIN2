#include "THISDUST.H"
#include "INSTANCE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_Deactivate(struct _Instance *instance /*$a1*/)
 // line 49, offset 0x80032c48
	/* begin block 1 */
		// Start line: 50
		// Start offset: 0x80032C48
		// Variables:
	// 		struct Object *object; // $a3
	/* end block 1 */
	// End offset: 0x80032CE8
	// End Line: 72

	/* begin block 2 */
		// Start line: 98
	/* end block 2 */
	// End Line: 99

void INSTANCE_Deactivate(_Instance *instance)

{
  uint uVar1;
  
  if ((gameTrackerX.streamFlags & 0x2000000U) == 0) {
    uVar1 = instance->flags2;
    instance->flags2 = uVar1 | 1;
    if ((uVar1 & 0x20000000) == 0) {
      instance->flags = instance->flags & 0xfffbffff;
      instance->flags2 = instance->flags2 | 0x20000000;
    }
    else {
      instance->flags = instance->flags | 0x40000;
    }
    if ((instance->object->animList != (_G2AnimKeylist_Type **)0x0) &&
       ((instance->object->oflags2 & 0x40000000U) == 0)) {
      G2Anim_Free(&instance->anim);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_Reactivate(struct _Instance *instance /*$a0*/)
 // line 75, offset 0x80032cf8
	/* begin block 1 */
		// Start line: 76
		// Start offset: 0x80032CF8
		// Variables:
	// 		struct Object *object; // $a2
	/* end block 1 */
	// End offset: 0x80032D80
	// End Line: 98

	/* begin block 2 */
		// Start line: 157
	/* end block 2 */
	// End Line: 158

void INSTANCE_Reactivate(_Instance *instance)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = instance->flags2;
  uVar2 = uVar1 & 0xfffffffe;
  instance->flags2 = uVar2;
  if ((instance->flags & 0x40000U) == 0) {
    uVar2 = uVar1 & 0xdffffffe;
  }
  else {
    instance->flags = instance->flags & 0xfffbffff;
    uVar2 = uVar2 | 0x20000000;
  }
  instance->flags2 = uVar2;
  if ((instance->object->animList != (_G2AnimKeylist_Type **)0x0) &&
     ((instance->object->oflags2 & 0x40000000U) == 0)) {
    G2Anim_Restore(&instance->anim);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_ForceActive(struct _Instance *instance /*$a0*/)
 // line 101, offset 0x80032d90
	/* begin block 1 */
		// Start line: 218
	/* end block 1 */
	// End Line: 219

void INSTANCE_ForceActive(_Instance *instance)

{
  if ((instance->flags2 & 1U) != 0) {
    INSTANCE_Reactivate(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_DeactivatedProcess(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 111, offset 0x80032dc4
	/* begin block 1 */
		// Start line: 238
	/* end block 1 */
	// End Line: 239

	/* begin block 2 */
		// Start line: 240
	/* end block 2 */
	// End Line: 241

void INSTANCE_DeactivatedProcess(_Instance *instance,GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_DeactivateFarInstances(struct GameTracker *gameTracker /*$s3*/)
 // line 117, offset 0x80032dcc
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x80032DCC
		// Variables:
	// 		struct _InstanceList *instanceList; // $v0
	// 		struct _Instance *instance; // $s0
	// 		struct SVECTOR *line; // $s2
	// 		long distSq; // $v1
	// 		int numInstances; // $a0
	// 		int numToProcess; // $s1
	// 		int cntInst; // $v1
	// 		static int lastInst; // offset 0x0
	/* end block 1 */
	// End offset: 0x8003301C
	// End Line: 214

	/* begin block 2 */
		// Start line: 250
	/* end block 2 */
	// End Line: 251

void INSTANCE_DeactivateFarInstances(GameTracker *gameTracker)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  _Instance *Inst;
  int iVar6;
  
  iVar5 = gameTracker->instanceList->numInstances;
  Inst = gameTracker->instanceList->first;
  iVar6 = (iVar5 >> 3) + 1;
  if (iVar5 <= DAT_800ce624) {
    DAT_800ce624 = 0;
  }
  iVar3 = DAT_800ce624;
  DAT_800ce624 = DAT_800ce624 + iVar6;
  if (iVar5 <= DAT_800ce624) {
    DAT_800ce624 = 0;
  }
  while (iVar3 != 0) {
    Inst = Inst->next;
    iVar3 = iVar3 + -1;
  }
  do {
    if ((Inst == (_Instance *)0x0) || (iVar6 == 0)) {
      return;
    }
    if (((((Inst->flags2 & 0x80U) == 0) && ((Inst->object->oflags & 0x10000U) == 0)) &&
        (uVar1 = INSTANCE_Query(Inst,0x23), uVar1 == 0)) &&
       ((Inst->LinkParent == (_Instance *)0x0 && (Inst->matrix != (MATRIX *)0x0)))) {
      DAT_1f800000 = (Inst->position).x - theCamera.core.position.x;
      iVar5 = (uint)(ushort)(Inst->position).y - (uint)(ushort)theCamera.core.position.y;
      DAT_1f800002 = (undefined2)iVar5;
      iVar5 = iVar5 * 0x10000 >> 0x10;
      iVar4 = (uint)(ushort)(Inst->position).z - (uint)(ushort)theCamera.core.position.z;
      iVar3 = iVar4 * 0x10000 >> 0x10;
      DAT_1f800004 = (undefined2)iVar4;
      iVar5 = (int)DAT_1f800000 * (int)DAT_1f800000 + iVar5 * iVar5 + iVar3 * iVar3;
      if ((Inst->flags & 0x200U) == 0) {
        if ((Inst->flags2 & 0x80000U) == 0) {
          iVar3 = (int)Inst->object->removeDist;
          iVar3 = iVar3 * iVar3;
        }
        else {
          iVar3 = gameTracker->playerCheatFlags * gameTracker->playerCheatFlags;
        }
        uVar2 = Inst->flags2 & 1;
        if (iVar5 <= iVar3) goto LAB_80032ffc;
      }
      else {
        iVar3 = (int)Inst->object->vvRemoveDist;
        if (iVar5 <= iVar3 * iVar3) {
          uVar2 = Inst->flags2 & 1;
          goto LAB_80032ffc;
        }
        uVar2 = Inst->flags2 & 1;
      }
      if (uVar2 == 0) {
        INSTANCE_Deactivate(Inst);
      }
    }
    else {
      uVar2 = Inst->flags2 & 1;
LAB_80032ffc:
      if (uVar2 != 0) {
        INSTANCE_Reactivate(Inst);
      }
    }
    Inst = Inst->next;
    iVar6 = iVar6 + -1;
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_InitInstanceList(struct _InstanceList *list /*$a0*/, struct _InstancePool *pool /*$a1*/)
 // line 237, offset 0x80033038
	/* begin block 1 */
		// Start line: 239
		// Start offset: 0x80033038
		// Variables:
	// 		long i; // $a3
	/* end block 1 */
	// End offset: 0x800330CC
	// End Line: 272

	/* begin block 2 */
		// Start line: 516
	/* end block 2 */
	// End Line: 517

	/* begin block 3 */
		// Start line: 517
	/* end block 3 */
	// End Line: 518

	/* begin block 4 */
		// Start line: 520
	/* end block 4 */
	// End Line: 521

void INSTANCE_InitInstanceList(_InstanceList *list,_InstancePool *pool)

{
  NodeType *pNVar1;
  NodeType *pNVar2;
  NodeType **ppNVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  pool->numFreeInstances = 0x3c;
  iVar4 = 1;
  iVar6 = 8;
  iVar5 = 0x538;
  ppNVar3 = &pool->instance[1].node.next;
  do {
    pNVar2 = (NodeType *)((int)&pool->nextInstanceID + iVar6);
    iVar6 = iVar6 + 0x298;
    pNVar1 = (NodeType *)((int)&pool->nextInstanceID + iVar5);
    iVar5 = iVar5 + 0x298;
    ppNVar3[4] = pNVar1;
    ppNVar3[5] = pNVar2;
    iVar4 = iVar4 + 1;
    ppNVar3 = ppNVar3 + 0xa6;
  } while (iVar4 < 0x3b);
  iVar4 = 0;
  pool->instance[0].next = (_Instance *)&pool->instance[1].prev;
  pool->instance[0].prev = (_Instance *)0x0;
  *(_Instance **)&pool[1].instance[0].currentStreamUnitID =
       (_Instance *)&pool->instance[0x3b].parent;
  pool[1].instance[0].birthStreamUnitID = 0;
  *(_Instance **)&pool[1].instance[1].currentStreamUnitID = pool->instance;
  list->pool = pool;
  list->numInstances = 0;
  list->first = (_Instance *)0x0;
  do {
    list->group[0].next = (NodeType *)0x0;
    list->group[0].prev = (NodeType *)0x0;
    iVar4 = iVar4 + 1;
    list = (_InstanceList *)&list->pool;
  } while (iVar4 < 0x20);
  pool->nextInstanceID = 1;
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_NewInstance(struct _InstanceList *list /*$a0*/)
 // line 328, offset 0x800330d8
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x800330D8
		// Variables:
	// 		struct _Instance *temp; // $v0
	// 		struct _Instance *instance; // $a1
	/* end block 1 */
	// End offset: 0x80033178
	// End Line: 366

	/* begin block 2 */
		// Start line: 733
	/* end block 2 */
	// End Line: 734

_Instance * INSTANCE_NewInstance(_InstanceList *list)

{
  int iVar1;
  _Instance *p_Var2;
  _InstancePool *p_Var3;
  _Instance *p_Var4;
  
  iVar1 = list->pool->numFreeInstances;
  if (iVar1 == 0) {
    GXFilePrint("Ran out of instances need more than %d - contact a programmer\n");
    p_Var4 = (_Instance *)0x0;
  }
  else {
    list->pool->numFreeInstances = iVar1 + -1;
    p_Var4 = (_Instance *)list->pool[1].instance[1].currentStreamUnitID;
    *(_Instance **)&list->pool[1].instance[1].currentStreamUnitID = p_Var4->next;
    p_Var2 = list->first;
    list->first = p_Var4;
    p_Var4->next = p_Var2;
    if (p_Var2 != (_Instance *)0x0) {
      p_Var2->prev = p_Var4;
    }
    p_Var4->prev = (_Instance *)0x0;
    p_Var3 = list->pool;
    iVar1 = p_Var3->nextInstanceID;
    p_Var4->instanceID = iVar1;
    p_Var3->nextInstanceID = iVar1 + 1;
    list->numInstances = list->numInstances + 1;
  }
  return p_Var4;
}



// decompiled code
// original method signature: 
// long /*$ra*/ INSTANCE_InstanceGroupNumber(struct _Instance *instance /*$a0*/)
 // line 368, offset 0x80033188
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x80033188
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x80033290
	// End Line: 408

	/* begin block 2 */
		// Start line: 816
	/* end block 2 */
	// End Line: 817

long INSTANCE_InstanceGroupNumber(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = instance->object->oflags;
  uVar3 = 0;
  if ((uVar2 & 0x80) != 0) {
    uVar3 = (uint)((instance->flags & 0x8000U) == 0);
  }
  if (((uVar2 & 0x20) != 0) && ((instance->flags & 0x2000U) == 0)) {
    uVar3 = uVar3 | 2;
  }
  if (((instance->object->oflags & 0x40U) != 0) && ((instance->flags & 0x4000U) == 0)) {
    uVar3 = uVar3 | 4;
  }
  if (((instance->object->oflags & 0x10U) != 0) && ((instance->flags & 0x1000U) == 0)) {
    uVar3 = uVar3 | 0x10;
  }
  if ((instance->object->oflags & 1U) == 0) {
    iVar1 = strcmp(instance->object->name,"raziel__");
    if (iVar1 != 0) {
      uVar3 = uVar3 & 0xfffffffc;
    }
  }
  else {
    uVar3 = uVar3 | 8;
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_InsertInstanceGroup(struct _InstanceList *list /*$s1*/, struct _Instance *instance /*$s0*/)
 // line 427, offset 0x800332a4
	/* begin block 1 */
		// Start line: 428
		// Start offset: 0x800332A4
	/* end block 1 */
	// End offset: 0x800332A4
	// End Line: 428

	/* begin block 2 */
		// Start line: 934
	/* end block 2 */
	// End Line: 935

void INSTANCE_InsertInstanceGroup(_InstanceList *list,_Instance *instance)

{
  long lVar1;
  
  lVar1 = INSTANCE_InstanceGroupNumber(instance);
  LIST_InsertFunc(list->group + lVar1,(NodeType *)instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_ReallyRemoveInstance(struct _InstanceList *list /*$s1*/, struct _Instance *instance /*$s0*/, long reset /*$s2*/)
 // line 476, offset 0x800332ec
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x800332EC
		// Variables:
	// 		struct _Instance *temp; // $v1

		/* begin block 1.1 */
			// Start line: 579
			// Start offset: 0x80033520
			// Variables:
		// 		int i; // $a0
		/* end block 1.1 */
		// End offset: 0x80033544
		// End Line: 588
	/* end block 1 */
	// End offset: 0x80033544
	// End Line: 589

	/* begin block 2 */
		// Start line: 939
	/* end block 2 */
	// End Line: 940

void INSTANCE_ReallyRemoveInstance(_InstanceList *list,_Instance *instance,long reset)

{
  _Instance *p_Var1;
  GameTracker *pGVar2;
  Intro *pIVar3;
  int iVar4;
  
  EVENT_RemoveInstanceFromInstanceList(instance);
  if ((instance->flags & 0x800000U) != 0) {
    SAVE_DoInstanceDeadDead(instance);
  }
  if ((instance->flags & 2U) == 0) {
    pIVar3 = instance->intro;
    if (pIVar3 != (Intro *)0x0) {
      pIVar3->flags = pIVar3->flags & ~reset;
      instance->intro->instance = (_Instance *)0x0;
    }
  }
  if (instance->prev == (_Instance *)0x0) {
    list->first = instance->next;
  }
  else {
    instance->prev->next = instance->next;
  }
  if (instance->next != (_Instance *)0x0) {
    instance->next->prev = instance->prev;
  }
  instance->instanceID = 0;
  list->numInstances = list->numInstances + -1;
  list->pool->numFreeInstances = list->pool->numFreeInstances + 1;
  p_Var1 = (_Instance *)list->pool[1].instance[1].currentStreamUnitID;
  *(_Instance **)&list->pool[1].instance[1].currentStreamUnitID = instance;
  instance->prev = (_Instance *)0x0;
  instance->next = p_Var1;
  if (p_Var1 != (_Instance *)0x0) {
    p_Var1->prev = instance;
  }
  LIST_DeleteFunc((NodeType *)instance);
  FX_EndInstanceEffects(instance);
  if ((instance->flags & 0x10000U) != 0) {
    instance->flags = instance->flags | 0x20000;
    OBTABLE_InstanceInit(instance);
  }
  if ((instance->object->animList != (_G2AnimKeylist_Type **)0x0) &&
     ((instance->object->oflags2 & 0x40000000U) == 0)) {
    G2Anim_Free(&instance->anim);
  }
  if (instance->shadow0 != (void *)0x0) {
    *(undefined4 *)((int)instance->shadow0 + 0x10) = 0;
  }
  if (instance->shadow1 != (void *)0x0) {
    *(undefined4 *)((int)instance->shadow1 + 0x10) = 0;
  }
  if ((instance->object->oflags2 & 4U) != 0) {
    SOUND_EndInstanceSounds(instance->object->soundData,instance->soundInstanceTbl);
  }
  if (instance->LinkParent != (_Instance *)0x0) {
    INSTANCE_UnlinkFromParent(instance);
  }
  if (instance->LinkChild != (_Instance *)0x0) {
    INSTANCE_UnlinkChildren(instance);
  }
  if (instance->hModelList != (_HModel *)0x0) {
    MEMPACK_Free((char *)instance->hModelList);
  }
  if (instance[1].next != (_Instance *)0x0) {
    MEMPACK_Free((char *)instance[1].next);
    instance[1].next = (_Instance *)0x0;
  }
  iVar4 = 0;
  pGVar2 = &gameTrackerX;
  do {
    iVar4 = iVar4 + 1;
    if ((pGVar2->gameData).asmData.lightInstances[0].lightInstance == instance) {
      (pGVar2->gameData).asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
      return;
    }
    pGVar2 = (GameTracker *)&(pGVar2->gameData).asmData.lightInstances[0].g;
  } while (iVar4 < 1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_CleanUpInstanceList(struct _InstanceList *list /*$s1*/, long reset /*$s2*/)
 // line 592, offset 0x8003355c
	/* begin block 1 */
		// Start line: 593
		// Start offset: 0x8003355C
		// Variables:
	// 		struct _Instance *instance; // $a1
	// 		struct _Instance *next; // $s0
	/* end block 1 */
	// End offset: 0x80033600
	// End Line: 627

	/* begin block 2 */
		// Start line: 1302
	/* end block 2 */
	// End Line: 1303

void INSTANCE_CleanUpInstanceList(_InstanceList *list,long reset)

{
  _Instance **pp_Var1;
  _Instance *instance;
  uint uVar2;
  _Instance *p_Var3;
  
  p_Var3 = list->first;
  if (p_Var3 != (_Instance *)0x0) {
    do {
      uVar2 = p_Var3->flags;
      pp_Var1 = &p_Var3->next;
      if ((uVar2 & 0x400) == 0) {
        if ((uVar2 & 0x20) != 0) {
          p_Var3->flags = uVar2 | 0x20;
        }
      }
      else {
        if ((uVar2 & 0x20) != 0) {
          p_Var3->flags = uVar2 & 0xffffffdf;
        }
      }
      p_Var3 = *pp_Var1;
    } while (*pp_Var1 != (_Instance *)0x0);
    p_Var3 = list->first;
  }
  while (instance = p_Var3, instance != (_Instance *)0x0) {
    p_Var3 = instance->next;
    if ((instance->flags & 0x20U) != 0) {
      INSTANCE_ReallyRemoveInstance(list,instance,reset);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ INSTANCE_Introduced(struct Intro *intro /*$s0*/, short streamUnitID /*$a1*/)
 // line 697, offset 0x80033618
	/* begin block 1 */
		// Start line: 698
		// Start offset: 0x80033618
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $s1
	/* end block 1 */
	// End offset: 0x800336B8
	// End Line: 738

	/* begin block 2 */
		// Start line: 1374
	/* end block 2 */
	// End Line: 1375

	/* begin block 3 */
		// Start line: 1444
	/* end block 3 */
	// End Line: 1445

long INSTANCE_Introduced(Intro *intro,short streamUnitID)

{
  long *plVar1;
  long lVar2;
  _Instance *p_Var3;
  long lVar4;
  
  p_Var3 = (gameTrackerX.instanceList)->first;
  lVar4 = 0;
  if (p_Var3 != (_Instance *)0x0) {
    do {
      plVar1 = &p_Var3->introUniqueID;
      p_Var3 = p_Var3->next;
      if (intro->UniqueID == *plVar1) {
        lVar4 = 1;
        intro->flags = intro->flags | 8;
        break;
      }
    } while (p_Var3 != (_Instance *)0x0);
  }
  if ((lVar4 == 0) &&
     ((lVar2 = SAVE_HasSavedIntro(intro,(int)streamUnitID), lVar2 != 0 ||
      (lVar2 = SAVE_IsIntroDeadDead(intro), lVar2 != 0)))) {
    intro->flags = intro->flags | 8;
    lVar4 = 1;
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// struct INICommand * /*$ra*/ INSTANCE_GetIntroCommand(struct INICommand *command /*$a0*/, int cmd /*$a1*/)
 // line 742, offset 0x800336d0
	/* begin block 1 */
		// Start line: 1554
	/* end block 1 */
	// End Line: 1555

	/* begin block 2 */
		// Start line: 1555
	/* end block 2 */
	// End Line: 1556

INICommand * INSTANCE_GetIntroCommand(INICommand *command,int cmd)

{
  if (command != (INICommand *)0x0) {
    while (command->command != 0) {
      if ((int)command->command == cmd) {
        return command;
      }
      command = command + (int)command->numParameters + 1;
    }
  }
  return (INICommand *)0x0;
}



// decompiled code
// original method signature: 
// struct INICommand * /*$ra*/ INSTANCE_FindIntroCommand(struct _Instance *instance /*$a0*/, int cmd /*$a1*/)
 // line 757, offset 0x80033720
	/* begin block 1 */
		// Start line: 1586
	/* end block 1 */
	// End Line: 1587

INICommand * INSTANCE_FindIntroCommand(_Instance *instance,int cmd)

{
  INICommand *pIVar1;
  
  pIVar1 = INSTANCE_GetIntroCommand((INICommand *)instance->introData,cmd);
  return pIVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_ProcessIntro(struct _Instance *instance /*$s1*/)
 // line 764, offset 0x80033744
	/* begin block 1 */
		// Start line: 765
		// Start offset: 0x80033744

		/* begin block 1.1 */
			// Start line: 766
			// Start offset: 0x8003377C
			// Variables:
		// 		struct INICommand *command; // $s0
		/* end block 1.1 */
		// End offset: 0x800337F0
		// End Line: 786
	/* end block 1 */
	// End offset: 0x800337F0
	// End Line: 787

	/* begin block 2 */
		// Start line: 1600
	/* end block 2 */
	// End Line: 1601

void INSTANCE_ProcessIntro(_Instance *instance)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)instance->introData;
  if ((psVar2 != (short *)0x0) && ((instance->flags & 2U) == 0)) {
    while (*psVar2 != 0) {
      if ((*psVar2 == 0x12) &&
         (sVar1 = psVar2[2], instance->currentModel = sVar1, instance->object->numModels <= sVar1))
      {
        GXFilePrint("Error: Specify model num %d on a instance(%s%d) with %d models.\n");
      }
      psVar2 = psVar2 + (int)psVar2[1] * 2 + 2;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_InitEffects(struct _Instance *instance /*$s2*/, struct Object *object /*$s1*/)
 // line 789, offset 0x80033804
	/* begin block 1 */
		// Start line: 790
		// Start offset: 0x80033804
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80033874
	// End Line: 802

	/* begin block 2 */
		// Start line: 1661
	/* end block 2 */
	// End Line: 1662

void INSTANCE_InitEffects(_Instance *instance,Object *object)

{
  int iVar1;
  int iVar2;
  
  if ((((object->oflags2 & 0x100U) == 0) && (object->numberOfEffects != 0)) &&
     (iVar2 = 0, 0 < object->numberOfEffects)) {
    iVar1 = 0;
    do {
      FX_StartInstanceEffect(instance,(ObjectEffect *)(&object->effectList->effectNumber + iVar1),1)
      ;
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (iVar2 < object->numberOfEffects);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_IntroduceInstance(struct Intro *intro /*$s2*/, short streamUnitID /*$a1*/)
 // line 804, offset 0x8003388c
	/* begin block 1 */
		// Start line: 805
		// Start offset: 0x8003388C
		// Variables:
	// 		struct Object *object; // $s3
	// 		struct _Instance *instance; // $s0
	// 		struct _ObjectTracker *objectTracker; // $s1

		/* begin block 1.1 */
			// Start line: 819
			// Start offset: 0x800338C8
			// Variables:
		// 		struct INICommand *index; // $v0
		// 		long attachedUniqueID; // $s4

			/* begin block 1.1.1 */
				// Start line: 922
				// Start offset: 0x80033B00
			/* end block 1.1.1 */
			// End offset: 0x80033B3C
			// End Line: 932

			/* begin block 1.1.2 */
				// Start line: 984
				// Start offset: 0x80033C1C
				// Variables:
			// 		struct SavedIntroSmall *savedIntroSmall; // $v0
			/* end block 1.1.2 */
			// End offset: 0x80033C68
			// End Line: 1005
		/* end block 1.1 */
		// End offset: 0x80033C8C
		// End Line: 1021
	/* end block 1 */
	// End offset: 0x80033C90
	// End Line: 1023

	/* begin block 2 */
		// Start line: 1693
	/* end block 2 */
	// End Line: 1694

_Instance * INSTANCE_IntroduceInstance(Intro *intro,short streamUnitID)

{
  short frameNum;
  long lVar1;
  _Instance *instance;
  INICommand *pIVar2;
  _ObjectTracker *objectTracker;
  MultiSpline *pMVar3;
  SavedIntroSmall *pSVar4;
  int Data;
  undefined4 uVar5;
  Object *object;
  INICommand introUniqueID;
  
  lVar1 = INSTANCE_Introduced(intro,streamUnitID);
  instance = (_Instance *)0x0;
  if (lVar1 == 0) {
    introUniqueID = (INICommand)0x0;
    pIVar2 = INSTANCE_GetIntroCommand((INICommand *)intro->data,0x1a);
    if (pIVar2 != (INICommand *)0x0) {
      introUniqueID = pIVar2[1];
    }
    objectTracker = STREAM_GetObjectTracker((char *)intro);
    instance = (_Instance *)0x0;
    if (objectTracker != (_ObjectTracker *)0x0) {
      object = objectTracker->object;
      if (object == (Object *)0x0) {
        FONT_Print("%s not loaded.\n");
        instance = (_Instance *)0x0;
      }
      else {
        lVar1 = MEMPACK_MemoryValidFunc((char *)object);
        instance = (_Instance *)0x0;
        if (lVar1 != 0) {
          if ((introUniqueID != (INICommand)0x0) &&
             (instance = INSTANCE_Find((long)introUniqueID), instance == (_Instance *)0x0)) {
            return (_Instance *)0x0;
          }
          if (((object->oflags2 & 0x10000000U) != 0) &&
             (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) != 0)) {
            return (_Instance *)0x0;
          }
          instance = INSTANCE_NewInstance(gameTrackerX.instanceList);
          if (instance == (_Instance *)0x0) {
            GXFilePrint("Ran out of instances for object %s%d num used %d.\n");
            instance = (_Instance *)0x0;
          }
          else {
            intro->flags = intro->flags | 8;
            objectTracker->numInUse = objectTracker->numInUse + 1;
            INSTANCE_DefaultInit(instance,object,0);
            strcpy(instance->introName,(char *)intro);
            instance->introUniqueID = intro->UniqueID;
            lVar1 = intro->intronum;
            instance->birthStreamUnitID = (int)streamUnitID;
            instance->currentStreamUnitID = (int)streamUnitID;
            instance->introNum = lVar1;
            intro->instance = instance;
            instance->intro = intro;
            instance->introData = intro->data;
            frameNum = (intro->position).z;
            *(undefined4 *)&instance->position = *(undefined4 *)&intro->position;
            (instance->position).z = frameNum;
            frameNum = (instance->position).z;
            *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
            (instance->initialPos).z = frameNum;
            frameNum = (intro->position).z;
            *(undefined4 *)&instance->oldPos = *(undefined4 *)&intro->position;
            (instance->oldPos).z = frameNum;
            *(INICommand *)&instance->attachedID = introUniqueID;
            LIGHT_GetAmbient((_ColorType *)&instance[1].node.next,instance);
            uVar5 = *(undefined4 *)&(intro->rotation).z;
            *(undefined4 *)&instance->rotation = *(undefined4 *)&intro->rotation;
            *(undefined4 *)&(instance->rotation).z = uVar5;
            if ((instance->object->oflags & 0x100U) != 0) {
              INSTANCE_BuildStaticShadow(instance);
            }
            (instance->scale).x = 0x1000;
            (instance->scale).y = 0x1000;
            (instance->scale).z = 0x1000;
            if ((intro->flags & 0x2000U) != 0) {
              instance->flags = instance->flags | 0x400;
            }
            if ((object->oflags2 & 0x80U) != 0) {
              instance->flags = instance->flags | 0x800;
            }
            if (((intro->flags & 0x800U) != 0) && (object->id == -1)) {
              frameNum = SCRIPTCountFramesInSpline(instance);
              SCRIPT_InstanceSplineSet
                        (instance,frameNum,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
              instance->flags = instance->flags ^ 0x1000000U | 0x100000;
            }
            pMVar3 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
            if (pMVar3 == (MultiSpline *)0x0) {
              instance->flags = instance->flags & 0xfdffffffU | 0x100000;
            }
            instance->lightGroup = *(uchar *)&(intro->rotation).pad;
            instance->spectralLightGroup = *(uchar *)&intro->specturalLightGroup;
            INSTANCE_InsertInstanceGroup(gameTrackerX.instanceList,instance);
            OBTABLE_GetInstanceCollideFunc(instance);
            OBTABLE_GetInstanceProcessFunc(instance);
            OBTABLE_GetInstanceQueryFunc(instance);
            OBTABLE_GetInstanceMessageFunc(instance);
            OBTABLE_GetInstanceAdditionalCollideFunc(instance);
            if ((intro->flags & 0x10U) == 0) {
              OBTABLE_InstanceInit(instance);
            }
            MORPH_SetupInstanceFlags(&gameTrackerX,instance);
            if ((intro->flags & 0x80U) != 0) {
              instance->flags = instance->flags | 0x800;
              instance->flags2 = instance->flags2 | 0x20000000;
            }
            EVENT_AddInstanceToInstanceList(instance);
            INSTANCE_ProcessIntro(instance);
            INSTANCE_InitEffects(instance,object);
            pSVar4 = SAVE_GetSavedSmallIntro(instance);
            if (pSVar4 != (SavedIntroSmall *)0x0) {
              Data = SetControlSaveDataData((int)pSVar4[1].introUniqueID,pSVar4 + 2);
              INSTANCE_Post(instance,0x100007,Data);
            }
          }
        }
      }
    }
  }
  return instance;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_AdditionalCollideFunctions(struct _InstanceList *instanceList /*$a0*/)
 // line 1028, offset 0x80033cb4
	/* begin block 1 */
		// Start line: 1029
		// Start offset: 0x80033CB4
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x80033DC8
	// End Line: 1060

	/* begin block 2 */
		// Start line: 2205
	/* end block 2 */
	// End Line: 2206

void INSTANCE_AdditionalCollideFunctions(_InstanceList *instanceList)

{
  _Instance *p_Var1;
  
  p_Var1 = instanceList->first;
  while (p_Var1 != (_Instance *)0x0) {
    if ((((gameTrackerX.gameMode != 6) || ((p_Var1->object->oflags & 0x20000U) != 0)) &&
        (((gameTrackerX.streamFlags & 0x100000U) == 0 || ((p_Var1->object->oflags & 0x40000U) != 0))
        )) && ((p_Var1->additionalCollideFunc != (_func_4391 *)0x0 &&
               ((p_Var1->flags2 & 0x24000000U) == 0)))) {
      gameTrackerX.idleTime = gameTrackerX.visibleInstances;
      if ((p_Var1->object != (Object *)0x0) &&
         (((p_Var1->object->oflags2 & 0x2000000U) != 0 &&
          (gameTrackerX.idleTime = gameTrackerX.timeSinceLastGameFrame,
          (p_Var1->flags2 & 0x8000000U) != 0)))) {
        gameTrackerX.idleTime = gameTrackerX.gameFramePassed;
      }
      (*p_Var1->additionalCollideFunc)(p_Var1,&gameTrackerX);
    }
    p_Var1 = p_Var1->next;
  }
  gameTrackerX.idleTime = gameTrackerX.visibleInstances;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ INSTANCE_GetSplineFrameNumber(struct _Instance *instance /*$s0*/, struct MultiSpline *spline /*$a1*/)
 // line 1063, offset 0x80033de0
	/* begin block 1 */
		// Start line: 1064
		// Start offset: 0x80033DE0
	/* end block 1 */
	// End offset: 0x80033DE0
	// End Line: 1064

	/* begin block 2 */
		// Start line: 2296
	/* end block 2 */
	// End Line: 2297

long INSTANCE_GetSplineFrameNumber(_Instance *instance,MultiSpline *spline)

{
  SplineDef *splineDef;
  int iVar1;
  
  splineDef = SCRIPT_GetPosSplineDef(instance,spline,0,0);
  iVar1 = SCRIPT_GetSplineFrameNumber(instance,splineDef);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_ProcessFunctions(struct _InstanceList *instanceList /*$a0*/)
 // line 1076, offset 0x80033e18
	/* begin block 1 */
		// Start line: 1077
		// Start offset: 0x80033E18

		/* begin block 1.1 */
			// Start line: 1083
			// Start offset: 0x80033E58
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.1.1 */
				// Start line: 1103
				// Start offset: 0x80033EE4
				// Variables:
			// 		int hidden; // $s1
			/* end block 1.1.1 */
			// End offset: 0x80033F58
			// End Line: 1119

			/* begin block 1.1.2 */
				// Start line: 1144
				// Start offset: 0x80034028
				// Variables:
			// 		long prevFrame; // $s2
			// 		struct MultiSpline *multi; // $s4

				/* begin block 1.1.2.1 */
					// Start line: 1151
					// Start offset: 0x80034058
					// Variables:
				// 		long endOfSpline; // $s6
				// 		short direction; // $s7

					/* begin block 1.1.2.1.1 */
						// Start line: 1190
						// Start offset: 0x80034118
						// Variables:
					// 		long frame; // $s3
					// 		long maxFrames; // $s1
					/* end block 1.1.2.1.1 */
					// End offset: 0x80034370
					// End Line: 1270

					/* begin block 1.1.2.1.2 */
						// Start line: 1281
						// Start offset: 0x800343A4
					/* end block 1.1.2.1.2 */
					// End offset: 0x800343C8
					// End Line: 1286
				/* end block 1.1.2.1 */
				// End offset: 0x80034540
				// End Line: 1346
			/* end block 1.1.2 */
			// End offset: 0x80034540
			// End Line: 1348
		/* end block 1.1 */
		// End offset: 0x8003459C
		// End Line: 1373
	/* end block 1 */
	// End offset: 0x8003459C
	// End Line: 1374

	/* begin block 2 */
		// Start line: 2326
	/* end block 2 */
	// End Line: 2327

void INSTANCE_ProcessFunctions(_InstanceList *instanceList)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short frameNum;
  ulong uVar5;
  MultiSpline *multi;
  long lVar6;
  long lVar7;
  long lVar8;
  Spline *pSVar9;
  int iVar10;
  _Instance *Inst;
  uint hidden;
  int iVar11;
  ushort uVar12;
  
  if ((gameTrackerX.debugFlags & 0x8000010U) == 0) {
    Inst = instanceList->first;
    while (Inst != (_Instance *)0x0) {
      gameTrackerX.idleTime = gameTrackerX.visibleInstances;
      if (((Inst->object != (Object *)0x0) && ((Inst->object->oflags2 & 0x2000000U) != 0)) &&
         (gameTrackerX.idleTime = gameTrackerX.timeSinceLastGameFrame,
         (Inst->flags2 & 0x8000000U) != 0)) {
        gameTrackerX.idleTime = gameTrackerX.gameFramePassed;
      }
      if ((Inst->object->oflags2 & 4U) != 0) {
        hidden = Inst->flags & 0x800;
        uVar5 = INSTANCE_Query(Inst,2);
        if (((uVar5 & 0x20) != 0) && (uVar5 = INSTANCE_Query(Inst,3), (uVar5 & 0x10000) == 0)) {
          hidden = 1;
        }
        SOUND_ProcessInstanceSounds
                  (Inst->object->soundData,Inst->soundInstanceTbl,&Inst->position,
                   Inst->object->oflags2 & 0x2000000,Inst->flags2 & 0x8000000,hidden,&Inst->flags2);
      }
      if ((((Inst->intro == (Intro *)0x0) || ((Inst->intro->flags & 0x100U) == 0)) &&
          ((gameTrackerX.gameMode != 6 || ((Inst->object->oflags & 0x20000U) != 0)))) &&
         ((((gameTrackerX.streamFlags & 0x100000U) == 0 || ((Inst->object->oflags & 0x40000U) != 0))
          && ((Inst->flags2 & 0x10000000U) == 0)))) {
        frameNum = (Inst->position).y;
        sVar1 = (Inst->position).z;
        sVar2 = (Inst->rotation).x;
        sVar3 = (Inst->rotation).y;
        hidden = Inst->flags;
        sVar4 = (Inst->rotation).z;
        (Inst->oldPos).x = (Inst->position).x;
        (Inst->oldPos).y = frameNum;
        (Inst->oldPos).z = sVar1;
        (Inst->oldRotation).x = sVar2;
        (Inst->oldRotation).y = sVar3;
        (Inst->oldRotation).z = sVar4;
        if ((((hidden & 0x100000) == 0) &&
            (multi = SCRIPT_GetMultiSpline(Inst,(ulong *)0x0,(ulong *)0x0),
            multi != (MultiSpline *)0x0)) && (hidden = Inst->flags, (hidden & 0x2000000) != 0)) {
          uVar12 = 1;
          if ((hidden & 0x1000000) != 0) {
            uVar12 = 0xffff;
          }
          if ((Inst->object->oflags & 0x10000000U) != 0) {
            Inst->flags = hidden | 0x400;
            frameNum = SplineMultiIsWhere(multi);
            if (frameNum != 0) {
              if ((int)((uint)uVar12 << 0x10) < 1) {
                Inst->intro->flags = Inst->intro->flags & 0xfffff7ff;
              }
              else {
                Inst->intro->flags = Inst->intro->flags | 0x800;
              }
            }
          }
          lVar6 = INSTANCE_GetSplineFrameNumber(Inst,multi);
          lVar7 = SCRIPT_InstanceSplineProcess
                            (Inst,&multi->curPositional,&multi->curRotational,&multi->curScaling,
                             (int)(short)uVar12);
          if (Inst->splineFlags == 0) {
            if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
              INSTANCE_GetSplineFrameNumber(Inst,multi);
              FONT_Print("Spline %s%d prevFrame=%d, frame=%d\n");
            }
          }
          else {
            lVar8 = INSTANCE_GetSplineFrameNumber(Inst,multi);
            frameNum = SCRIPTCountFramesInSpline(Inst);
            iVar11 = (int)frameNum;
            if ((Inst->splineFlags & 1U) != 0) {
              if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
                printf(
                      "Spline %s%ld playto %d preveFram=%ld frame=%ld endOfSpline=%ld, maxFrames=%ld\n"
                      );
              }
              if ((int)(short)uVar12 < 1) {
                iVar10 = (int)Inst->targetFrame;
                if ((lVar8 <= iVar10) &&
                   ((iVar10 <= lVar6 || ((lVar6 < lVar8 && (iVar10 <= lVar6 + iVar11))))))
                goto LAB_80034218;
              }
              else {
                if (iVar11 < lVar6) {
                  lVar6 = iVar11;
                }
                iVar10 = (int)Inst->targetFrame;
                if (((iVar10 <= lVar8) && (lVar6 <= iVar10)) ||
                   ((lVar8 < lVar6 && ((iVar10 <= lVar8 && (lVar6 <= iVar10 + iVar11)))))) {
                  printf("hit the end of the play to.\n");
LAB_80034218:
                  Inst->flags = Inst->flags & 0xfdffffff;
                  SCRIPT_InstanceSplineSet
                            (Inst,Inst->targetFrame,(SplineDef *)0x0,(SplineDef *)0x0,
                             (SplineDef *)0x0);
                  lVar7 = 0;
                  Inst->splineFlags = Inst->splineFlags & 0xfffe;
                }
              }
            }
            if ((Inst->splineFlags & 2U) != 0) {
              if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
                FONT_Print("Spline %s%d : clip(%d,%d) prevFrame=%d, frame=%d\n");
              }
              if (uVar12 == 1) {
                if (((lVar6 <= Inst->clipEnd) && (Inst->clipEnd <= lVar8)) ||
                   (lVar8 < Inst->clipBeg)) {
                  if ((*(uint *)&multi->positional->numkeys & 0x6000000) == 0) {
                    frameNum = Inst->clipEnd;
LAB_8003437c:
                    lVar7 = 1;
                  }
                  else {
                    frameNum = Inst->clipBeg;
                  }
LAB_80034380:
                  SCRIPT_InstanceSplineSet
                            (Inst,frameNum,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
                }
              }
              else {
                if (((Inst->clipBeg <= lVar6) && (lVar8 <= Inst->clipBeg)) ||
                   (Inst->clipEnd < lVar8)) {
                  if ((*(uint *)&multi->positional->numkeys & 0x6000000) == 0) {
                    frameNum = Inst->clipBeg;
                    goto LAB_8003437c;
                  }
                  frameNum = Inst->clipEnd;
                  goto LAB_80034380;
                }
              }
            }
          }
          if (0 < lVar7) {
            if ((Inst->object->oflags & 0x10000000U) != 0) {
              Inst->flags = Inst->flags & 0xfdfffbffU | 0x100000;
            }
            hidden = Inst->object->oflags;
            if ((hidden & 0x2000) != 0) {
              Inst->flags = Inst->flags | 0x100000;
              INSTANCE_KillInstance(Inst);
              goto LAB_8003458c;
            }
            if ((hidden & 0x1000) == 0) {
              if ((hidden & 0x1000000) != 0) {
                Inst->flags = Inst->flags & 0xfdffffff;
              }
            }
            else {
              Inst->flags = Inst->flags & 0xfdffffff;
              if ((Inst->object->oflags & 0x800000U) != 0) {
                SCRIPT_InstanceSplineInit(Inst);
              }
            }
            pSVar9 = multi->positional;
            if (((pSVar9 != (Spline *)0x0) ||
                (pSVar9 = (Spline *)multi->rotational, pSVar9 != (Spline *)0x0)) &&
               (((pSVar9->flags & 4) == 0 && ((Inst->object->oflags & 0x800000U) == 0)))) {
              Inst->flags = Inst->flags ^ 0x1000000;
            }
            if ((((Inst->object->oflags & 0x200000U) != 0) && ((int *)Inst->introData != (int *)0x0)
                ) && (iVar11 = *(int *)Inst->introData, iVar11 != 0)) {
              SIGNAL_HandleSignal(Inst,(Signal *)(iVar11 + 8),0);
            }
          }
        }
        if (Inst->processFunc != (_func_4389 *)0x0) {
          if ((Inst->flags2 & 1U) == 0) {
            (*Inst->processFunc)(Inst,&gameTrackerX);
          }
          else {
            INSTANCE_DeactivatedProcess(Inst,&gameTrackerX);
          }
        }
      }
LAB_8003458c:
      Inst = Inst->next;
    }
  }
  gameTrackerX.idleTime = gameTrackerX.visibleInstances;
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_BirthObject(struct _Instance *parent /*$s2*/, struct Object *object /*$s4*/, int modelNum /*$s1*/)
 // line 1381, offset 0x800345d4
	/* begin block 1 */
		// Start line: 1382
		// Start offset: 0x800345D4
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x80034814
	// End Line: 1453

	/* begin block 2 */
		// Start line: 3245
	/* end block 2 */
	// End Line: 3246

_Instance * INSTANCE_BirthObject(_Instance *parent,Object *object,int modelNum)

{
  short sVar1;
  _Instance *instance;
  size_t sVar2;
  MultiSpline *pMVar3;
  long lVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if ((object == (Object *)0x0) ||
     (instance = INSTANCE_NewInstance(gameTrackerX.instanceList), instance == (_Instance *)0x0)) {
    instance = (_Instance *)0x0;
  }
  else {
    INSTANCE_DefaultInit(instance,object,modelNum);
    sVar1 = (parent->position).z;
    *(undefined4 *)&instance->position = *(undefined4 *)&parent->position;
    (instance->position).z = sVar1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
    sVar1 = (parent->position).z;
    *(undefined4 *)&instance->oldPos = *(undefined4 *)&parent->position;
    (instance->oldPos).z = sVar1;
    uVar6 = *(undefined4 *)&(parent->rotation).z;
    *(undefined4 *)&instance->rotation = *(undefined4 *)&parent->rotation;
    *(undefined4 *)&(instance->rotation).z = uVar6;
    uVar6 = *(undefined4 *)&(parent->scale).z;
    *(undefined4 *)&instance->scale = *(undefined4 *)&parent->scale;
    *(undefined4 *)&(instance->scale).z = uVar6;
    instance->lightGroup = parent->lightGroup;
    instance->spectralLightGroup = parent->spectralLightGroup;
    iVar7 = 0;
    instance->currentStreamUnitID = parent->currentStreamUnitID;
    lVar4 = parent->birthStreamUnitID;
    instance->introUniqueID = CurrentBirthID;
    instance->birthStreamUnitID = lVar4;
    CurrentBirthID = CurrentBirthID + 1;
    strcpy(instance->introName,object->name);
    do {
      sVar2 = strlen(instance->introName);
      iVar5 = (int)&(instance->node).prev + iVar7;
      if ((int)sVar2 <= iVar7) goto LAB_8003471c;
      iVar7 = iVar7 + 1;
    } while (*(char *)(iVar5 + 0x158) != '_');
    *(undefined *)(iVar5 + 0x158) = 0;
LAB_8003471c:
    instance->parent = parent;
    instance->intro = parent->intro;
    instance->introData = parent->introData;
    LIGHT_GetAmbient((_ColorType *)&instance[1].node.next,instance);
    if ((instance->object->oflags & 0x100U) != 0) {
      INSTANCE_BuildStaticShadow(instance);
    }
    pMVar3 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
    if (pMVar3 == (MultiSpline *)0x0) {
      instance->flags = instance->flags | 0x100000;
    }
    if ((parent->flags2 & 0x8000000U) != 0) {
      instance->flags2 = instance->flags2 | 0x8000000;
    }
    INSTANCE_InsertInstanceGroup(gameTrackerX.instanceList,instance);
    OBTABLE_GetInstanceCollideFunc(instance);
    OBTABLE_GetInstanceProcessFunc(instance);
    OBTABLE_GetInstanceQueryFunc(instance);
    OBTABLE_GetInstanceMessageFunc(instance);
    OBTABLE_GetInstanceAdditionalCollideFunc(instance);
    instance->flags = instance->flags | 2;
    OBTABLE_InstanceInit(instance);
    EVENT_AddInstanceToInstanceList(instance);
    INSTANCE_InitEffects(instance,object);
  }
  return instance;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_BuildStaticShadow(struct _Instance *instance /*$a0*/)
 // line 1470, offset 0x80034834
	/* begin block 1 */
		// Start line: 2937
	/* end block 1 */
	// End Line: 2938

	/* begin block 2 */
		// Start line: 3436
	/* end block 2 */
	// End Line: 3437

void INSTANCE_BuildStaticShadow(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_DefaultInit(struct _Instance *instance /*$s1*/, struct Object *object /*$s2*/, int modelNum /*$s0*/)
 // line 1504, offset 0x8003483c
	/* begin block 1 */
		// Start line: 1505
		// Start offset: 0x8003483C
		// Variables:
	// 		int i; // $t3
	// 		int j; // $a3
	// 		int numHPrims; // $a2
	// 		int numModels; // $s0
	// 		struct _HPrim *hprim; // $a2
	// 		struct _Model **pModel; // $t7
	// 		struct _HModel *hmodel; // $t8

		/* begin block 1.1 */
			// Start line: 1557
			// Start offset: 0x800349C0
			// Variables:
		// 		struct _Model *model; // $v0
		// 		struct _Segment *seg; // $a1

			/* begin block 1.1.1 */
				// Start line: 1562
				// Start offset: 0x800349D8
				// Variables:
			// 		struct _HInfo *hinfo; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80034A00
			// End Line: 1566
		/* end block 1.1 */
		// End offset: 0x80034A0C
		// End Line: 1567

		/* begin block 1.2 */
			// Start line: 1576
			// Start offset: 0x80034A68
			// Variables:
		// 		struct _Model *model; // $s0
		// 		struct _Segment *seg; // $t4

			/* begin block 1.2.1 */
				// Start line: 1587
				// Start offset: 0x80034A84
				// Variables:
			// 		struct _HInfo *hinfo; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 1591
					// Start offset: 0x80034A94
					// Variables:
				// 		int k; // $v1
				// 		struct _HFace *hface; // $t0
				// 		struct _HSphere *hsphere; // $t1
				// 		struct _HBox *hbox; // $t2
				/* end block 1.2.1.1 */
				// End offset: 0x80034B7C
				// End Line: 1630
			/* end block 1.2.1 */
			// End offset: 0x80034B7C
			// End Line: 1631
		/* end block 1.2 */
		// End offset: 0x80034B94
		// End Line: 1632
	/* end block 1 */
	// End offset: 0x80034BD8
	// End Line: 1644

	/* begin block 2 */
		// Start line: 3495
	/* end block 2 */
	// End Line: 3496

void INSTANCE_DefaultInit(_Instance *instance,Object *object,int modelNum)

{
  void *pvVar1;
  _G2AnimKeylist_Type *keylist;
  _HFace **pp_Var2;
  _HSphere **pp_Var3;
  _HBox **pp_Var4;
  _HInfo *p_Var5;
  _Segment *p_Var6;
  int iVar7;
  _HPrim *p_Var8;
  undefined uVar9;
  int iVar10;
  _HFace *p_Var11;
  _HSphere *p_Var12;
  _HBox *p_Var13;
  int iVar14;
  int *piVar15;
  _Model **pp_Var16;
  _G2Anim_Type *anim;
  int iVar17;
  _Model *p_Var18;
  _HModel *p_Var19;
  
  memset(&instance->flags,0,0x284);
  instance->object = object;
  pvVar1 = object->data;
  instance->currentModel = (short)modelNum;
  instance->cachedTFace = -1;
  instance->data = pvVar1;
  if ((object->animList != (_G2AnimKeylist_Type **)0x0) && ((object->oflags2 & 0x40000000U) == 0)) {
    anim = &instance->anim;
    G2Anim_Init(anim,object->modelList[modelNum]);
    keylist = G2Instance_GetKeylist(instance,0);
    G2Anim_SwitchToKeylist(anim,keylist,0);
    G2Anim_SetCallback(anim,INSTANCE_DefaultAnimCallback,instance);
  }
  if ((object->oflags & 0x4000000U) != 0) {
    instance->flags2 = instance->flags2 | 4;
  }
  if ((object->oflags & 0x200U) != 0) {
    instance->flags2 = instance->flags2 | 0x40;
  }
  if ((object->oflags & 8U) != 0) {
    instance->flags2 = instance->flags2 | 0x8000000;
  }
  if ((object->oflags & 0x1000800U) == 0) {
    instance->flags = instance->flags | 0x2000000;
  }
  if ((object->oflags & 0x20000000U) != 0) {
    instance->flags2 = instance->flags2 | 0x20;
  }
  iVar17 = (int)object->numModels;
  pp_Var16 = object->modelList;
  iVar7 = 0;
  iVar14 = iVar17;
  while (iVar14 != 0) {
    iVar10 = (*pp_Var16)->numSegments;
    p_Var6 = (*pp_Var16)->segmentList;
    while (iVar10 != 0) {
      p_Var5 = p_Var6->hInfo;
      if (p_Var5 != (_HInfo *)0x0) {
        iVar7 = iVar7 + p_Var5->numHFaces + p_Var5->numHSpheres + p_Var5->numHBoxes;
      }
      iVar10 = iVar10 + -1;
      p_Var6 = p_Var6 + 1;
    }
    iVar14 = iVar14 + -1;
    pp_Var16 = pp_Var16 + 1;
  }
  if (iVar7 == 0) {
    instance->hModelList = (_HModel *)0x0;
    instance->flags2 = instance->flags2 | 0x40000;
  }
  else {
    p_Var19 = (_HModel *)MEMPACK_Malloc((instance->object->numModels + iVar7) * 8,'\x0e');
    instance->hModelList = p_Var19;
    pp_Var16 = object->modelList;
    p_Var8 = (_HPrim *)(p_Var19 + iVar17);
    if (iVar17 != 0) {
      piVar15 = &p_Var19->numHPrims;
      do {
        p_Var18 = *pp_Var16;
        *piVar15 = 0;
        p_Var19->hPrimList = p_Var8;
        p_Var6 = p_Var18->segmentList;
        iVar14 = 0;
        if (0 < p_Var18->numSegments) {
          do {
            p_Var5 = p_Var6->hInfo;
            if (p_Var5 != (_HInfo *)0x0) {
              p_Var11 = p_Var5->hfaceList;
              p_Var12 = p_Var5->hsphereList;
              p_Var13 = p_Var5->hboxList;
              *piVar15 = *piVar15 + p_Var5->numHFaces + p_Var5->numHSpheres + p_Var5->numHBoxes;
              iVar7 = p_Var5->numHFaces;
              pp_Var2 = (_HFace **)&p_Var8->data;
              uVar9 = (undefined)iVar14;
              while (iVar7 != 0) {
                p_Var8->hpFlags = 'M';
                *(undefined *)((int)pp_Var2 + -3) = 0x24;
                *(undefined *)((int)pp_Var2 + -2) = 2;
                *(undefined *)((int)pp_Var2 + -1) = uVar9;
                *pp_Var2 = p_Var11;
                pp_Var2 = pp_Var2 + 2;
                p_Var8 = p_Var8 + 1;
                iVar7 = iVar7 + -1;
                p_Var11 = p_Var11 + 1;
              }
              iVar7 = p_Var5->numHSpheres;
              pp_Var3 = (_HSphere **)&p_Var8->data;
              while (iVar7 != 0) {
                p_Var8->hpFlags = '/';
                *(undefined *)((int)pp_Var3 + -3) = 0x76;
                *(undefined *)((int)pp_Var3 + -2) = 1;
                *(undefined *)((int)pp_Var3 + -1) = uVar9;
                *pp_Var3 = p_Var12;
                pp_Var3 = pp_Var3 + 2;
                p_Var8 = p_Var8 + 1;
                iVar7 = iVar7 + -1;
                p_Var12 = p_Var12 + 1;
              }
              iVar7 = p_Var5->numHBoxes;
              pp_Var4 = (_HBox **)&p_Var8->data;
              while (iVar7 != 0) {
                p_Var8->hpFlags = '\x1d';
                *(undefined *)((int)pp_Var4 + -3) = 0x24;
                *(undefined *)((int)pp_Var4 + -2) = 5;
                *(undefined *)((int)pp_Var4 + -1) = uVar9;
                *pp_Var4 = p_Var13;
                pp_Var4 = pp_Var4 + 2;
                p_Var8 = p_Var8 + 1;
                iVar7 = iVar7 + -1;
                p_Var13 = p_Var13 + 1;
              }
            }
            iVar14 = iVar14 + 1;
            p_Var6 = p_Var6 + 1;
          } while (iVar14 < p_Var18->numSegments);
        }
        iVar17 = iVar17 + -1;
        pp_Var16 = pp_Var16 + 1;
        piVar15 = piVar15 + 2;
        p_Var19 = p_Var19 + 1;
      } while (iVar17 != 0);
    }
  }
  if (instance->maxCheckDistance == 0) {
    instance->maxCheckDistance = 12000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_PlainDeath(struct _Instance *instance /*$s5*/)
 // line 1647, offset 0x80034bf4
	/* begin block 1 */
		// Start line: 3939
	/* end block 1 */
	// End Line: 3940

void INSTANCE_PlainDeath(_Instance *instance)

{
  uint uVar1;
  Object *pOVar2;
  
  pOVar2 = instance->object;
  instance->flags = instance->flags & 0xfffffbff;
  if ((pOVar2->oflags2 & 4U) != 0) {
    uVar1 = instance->flags2;
    instance->flags2 = uVar1 | 0x1000;
    SOUND_ProcessInstanceSounds
              (pOVar2->soundData,instance->soundInstanceTbl,&instance->position,
               pOVar2->oflags2 & 0x2000000,uVar1 & 0x8000000,0,&instance->flags2);
    SOUND_ProcessInstanceSounds
              (instance->object->soundData,instance->soundInstanceTbl,&instance->position,
               instance->object->oflags2 & 0x2000000,instance->flags2 & 0x8000000,0,
               &instance->flags2);
  }
  SAVE_MarkDeadDead(instance);
  instance->flags = instance->flags | 0x20;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_KillInstance(struct _Instance *instance /*$a0*/)
 // line 1679, offset 0x80034cf4
	/* begin block 1 */
		// Start line: 4010
	/* end block 1 */
	// End Line: 4011

void INSTANCE_KillInstance(_Instance *instance)

{
  if ((instance->flags & 0x20U) == 0) {
    INSTANCE_PlainDeath(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ INSTANCE_Query(struct _Instance *Inst /*$a0*/, int Query /*$a1*/)
 // line 1698, offset 0x80034d28
	/* begin block 1 */
		// Start line: 1699
		// Start offset: 0x80034D28
		// Variables:
	// 		unsigned long (*Func)(); // $v0
	/* end block 1 */
	// End offset: 0x80034D54
	// End Line: 1712

	/* begin block 2 */
		// Start line: 3390
	/* end block 2 */
	// End Line: 3391

ulong INSTANCE_Query(_Instance *Inst,int Query)

{
  ulong uVar1;
  
  if (Inst->queryFunc == (_func_4392 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*Inst->queryFunc)();
  }
  return uVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_Post(struct _Instance *Inst /*$s0*/, int Message /*$s2*/, int Data /*$s3*/)
 // line 1716, offset 0x80034d64
	/* begin block 1 */
		// Start line: 1717
		// Start offset: 0x80034D64
		// Variables:
	// 		void (*Func)(); // $s1
	/* end block 1 */
	// End offset: 0x80034DAC
	// End Line: 1727

	/* begin block 2 */
		// Start line: 4076
	/* end block 2 */
	// End Line: 4077

void INSTANCE_Post(_Instance *Inst,int Message,int Data)

{
  _func_4393 *p_Var1;
  
  p_Var1 = Inst->messageFunc;
  if (p_Var1 != (_func_4393 *)0x0) {
    INSTANCE_ForceActive(Inst);
    (*p_Var1)(Inst,Message,Data);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_Broadcast(struct _Instance *sender /*$s2*/, long whatAmIMask /*$s3*/, int Message /*$s4*/, int Data /*$s5*/)
 // line 1733, offset 0x80034dc8
	/* begin block 1 */
		// Start line: 1734
		// Start offset: 0x80034DC8
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int plane; // $s1
	/* end block 1 */
	// End offset: 0x80034E50
	// End Line: 1747

	/* begin block 2 */
		// Start line: 4114
	/* end block 2 */
	// End Line: 4115

	/* begin block 3 */
		// Start line: 4118
	/* end block 3 */
	// End Line: 4119

void INSTANCE_Broadcast(_Instance *sender,long whatAmIMask,int Message,int Data)

{
  ulong uVar1;
  int iVar2;
  _Instance *Inst;
  int plane;
  
  Inst = (gameTrackerX.instanceList)->first;
  plane = (int)gameTrackerX.gameData.asmData.MorphType;
  while (Inst != (_Instance *)0x0) {
    if (((Inst != sender) && (uVar1 = INSTANCE_Query(Inst,1), (uVar1 & whatAmIMask) != 0)) &&
       (iVar2 = INSTANCE_InPlane(Inst,plane), iVar2 != 0)) {
      INSTANCE_Post(Inst,Message,Data);
    }
    Inst = Inst->next;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ INSTANCE_InPlane(struct _Instance *instance /*$a0*/, int plane /*$a1*/)
 // line 1752, offset 0x80034e74
	/* begin block 1 */
		// Start line: 4164
	/* end block 1 */
	// End Line: 4165

	/* begin block 2 */
		// Start line: 4165
	/* end block 2 */
	// End Line: 4166

int INSTANCE_InPlane(_Instance *instance,int plane)

{
  if (instance->object == (Object *)0x0) {
    return 0;
  }
  if ((instance->object->oflags2 & 0x2000000U) != 0) {
    if ((instance->flags2 & 0x8000000U) == 0) {
      if (plane != 0) {
        return 0;
      }
      return 1;
    }
    if (plane == 0) {
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ INSTANCE_SavedIntroduced(struct _SavedIntro *savedIntro /*$a0*/)
 // line 1758, offset 0x80034ed0
	/* begin block 1 */
		// Start line: 1760
		// Start offset: 0x80034ED0
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $a1
	/* end block 1 */
	// End offset: 0x80034F0C
	// End Line: 1776

	/* begin block 2 */
		// Start line: 4176
	/* end block 2 */
	// End Line: 4177

	/* begin block 3 */
		// Start line: 4177
	/* end block 3 */
	// End Line: 4178

long INSTANCE_SavedIntroduced(_SavedIntro *savedIntro)

{
  long *plVar1;
  _Instance *p_Var2;
  
  p_Var2 = (gameTrackerX.instanceList)->first;
  if (p_Var2 != (_Instance *)0x0) {
    do {
      plVar1 = &p_Var2->introUniqueID;
      p_Var2 = p_Var2->next;
      if (*plVar1 == (int)savedIntro->birthUnitID) {
        return 1;
      }
    } while (p_Var2 != (_Instance *)0x0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_FindWithName(long areaID /*$s3*/, char *instanceName /*$s4*/, struct _Instance *startInstance /*$a2*/)
 // line 1815, offset 0x80034f14
	/* begin block 1 */
		// Start line: 1816
		// Start offset: 0x80034F14
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *ret; // $s2
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x80034FC4
	// End Line: 1859

	/* begin block 2 */
		// Start line: 3623
	/* end block 2 */
	// End Line: 3624

	/* begin block 3 */
		// Start line: 4254
	/* end block 3 */
	// End Line: 4255

_Instance * INSTANCE_FindWithName(long areaID,char *instanceName,_Instance *startInstance)

{
  int iVar1;
  _Instance *p_Var2;
  _Instance *p_Var3;
  
  p_Var3 = (gameTrackerX.instanceList)->first;
  if (startInstance != (_Instance *)0x0) {
    p_Var3 = startInstance->next;
  }
  if (areaID == 0) {
    do {
      p_Var2 = p_Var3;
      if (p_Var2 == (_Instance *)0x0) {
        return (_Instance *)0x0;
      }
      p_Var3 = p_Var2->next;
      iVar1 = strcmpi(p_Var2->introName,instanceName);
    } while (iVar1 != 0);
  }
  else {
    do {
      p_Var2 = p_Var3;
      if (p_Var2 == (_Instance *)0x0) {
        return (_Instance *)0x0;
      }
      p_Var3 = p_Var2->next;
    } while ((p_Var2->birthStreamUnitID != areaID) ||
            (iVar1 = strcmpi(p_Var2->introName,instanceName), iVar1 != 0));
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// struct Intro * /*$ra*/ INSTANCE_FindIntro(long areaID /*$a0*/, long introUniqueID /*$s1*/)
 // line 1885, offset 0x80034fe8
	/* begin block 1 */
		// Start line: 1886
		// Start offset: 0x80034FE8
		// Variables:
	// 		struct Intro *ret; // $s0
	// 		long i; // $a0
	// 		struct Level *level; // $v1
	/* end block 1 */
	// End offset: 0x80035054
	// End Line: 1906

	/* begin block 2 */
		// Start line: 3767
	/* end block 2 */
	// End Line: 3768

Intro * INSTANCE_FindIntro(long areaID,long introUniqueID)

{
  Level *pLVar1;
  Intro *pIVar2;
  int iVar3;
  
  pLVar1 = STREAM_GetLevelWithID(areaID);
  if (pLVar1 != (Level *)0x0) {
    iVar3 = 0;
    if (0 < pLVar1->numIntros) {
      pIVar2 = pLVar1->introList;
      do {
        if (introUniqueID == pIVar2->UniqueID) {
          return pIVar2;
        }
        iVar3 = iVar3 + 1;
        pIVar2 = pIVar2 + 1;
      } while (iVar3 < pLVar1->numIntros);
    }
  }
  return (Intro *)0x0;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_Find(long introUniqueID /*$a0*/)
 // line 1910, offset 0x8003506c
	/* begin block 1 */
		// Start line: 1912
		// Start offset: 0x8003506C
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x800350A4
	// End Line: 1918

	/* begin block 2 */
		// Start line: 4440
	/* end block 2 */
	// End Line: 4441

	/* begin block 3 */
		// Start line: 4441
	/* end block 3 */
	// End Line: 4442

	/* begin block 4 */
		// Start line: 4443
	/* end block 4 */
	// End Line: 4444

_Instance * INSTANCE_Find(long introUniqueID)

{
  _Instance *p_Var1;
  
  p_Var1 = (gameTrackerX.instanceList)->first;
  while ((p_Var1 != (_Instance *)0x0 && (p_Var1->introUniqueID != introUniqueID))) {
    p_Var1 = p_Var1->next;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_IntroduceSavedInstance(struct _SavedIntro *savedIntro /*$s3*/, struct Level *level /*$a1*/)
 // line 1922, offset 0x800350ac
	/* begin block 1 */
		// Start line: 1923
		// Start offset: 0x800350AC
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s1
	// 		struct Object *object; // $s6
	// 		struct _Instance *instance; // $s0
	// 		struct _Position *levelOffset; // $s4

		/* begin block 1.1 */
			// Start line: 1972
			// Start offset: 0x80035190
			// Variables:
		// 		struct Level *birthLevel; // $v0
		// 		struct Intro *oldIntro; // $s1
		// 		struct MultiSpline *spline; // $s1

			/* begin block 1.1.1 */
				// Start line: 1997
				// Start offset: 0x800351F0
				// Variables:
			// 		struct Intro *intro; // $v1
			// 		int i; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80035224
			// End Line: 2008

			/* begin block 1.1.2 */
				// Start line: 2025
				// Start offset: 0x8003524C
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $a0
			// 		short _z0; // $v1
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _Position *_v; // $v0
			// 		struct _Position *_v0; // $v1
			/* end block 1.1.2 */
			// End offset: 0x8003524C
			// End Line: 2025

			/* begin block 1.1.3 */
				// Start line: 2160
				// Start offset: 0x800355F8
			/* end block 1.1.3 */
			// End offset: 0x80035614
			// End Line: 2169
		/* end block 1.1 */
		// End offset: 0x80035614
		// End Line: 2170
	/* end block 1 */
	// End offset: 0x80035638
	// End Line: 2190

	/* begin block 2 */
		// Start line: 4465
	/* end block 2 */
	// End Line: 4466

/* WARNING: Type propagation algorithm not settling */

_Instance * INSTANCE_IntroduceSavedInstance(_SavedIntro *savedIntro,Level *level)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  byte bVar6;
  _MultiSignal *p_Var7;
  long lVar8;
  _ObjectTracker *objectTracker;
  _Instance *instance;
  Level *pLVar9;
  MultiSpline *pMVar10;
  Intro *pIVar11;
  uint uVar12;
  Spline *pSVar13;
  RSpline *pRVar14;
  int Data;
  uint uVar15;
  undefined4 uVar16;
  Intro *pIVar17;
  Intro *pIVar18;
  Object *object;
  
  p_Var7 = level->terrain->signals;
  LOAD_SetSearchDirectory((int)(savedIntro->smallRotation).x);
  lVar8 = INSTANCE_SavedIntroduced(savedIntro);
  if (lVar8 != 0) {
    return (_Instance *)0x0;
  }
  objectTracker = STREAM_GetObjectTracker(savedIntro->name);
  if (objectTracker == (_ObjectTracker *)0x0) {
    return (_Instance *)0x0;
  }
  object = objectTracker->object;
  lVar8 = MEMPACK_MemoryValidFunc((char *)object);
  if ((lVar8 == 0) ||
     ((*(ushort *)(savedIntro[1].name + 6) != 0 &&
      (instance = INSTANCE_Find((uint)*(ushort *)(savedIntro[1].name + 6)),
      instance == (_Instance *)0x0)))) {
    SAVE_BufferIntro(savedIntro);
    return (_Instance *)0x0;
  }
  if (((object->oflags2 & 0x10000000U) != 0) &&
     (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) != 0)) {
    return (_Instance *)0x0;
  }
  instance = INSTANCE_NewInstance(gameTrackerX.instanceList);
  if (instance == (_Instance *)0x0) {
    return (_Instance *)0x0;
  }
  objectTracker->numInUse = objectTracker->numInUse + 1;
  INSTANCE_DefaultInit(instance,object,0);
  strcpy(instance->introName,savedIntro->name);
  instance->introUniqueID = (int)savedIntro->birthUnitID;
  instance->currentStreamUnitID = (int)(short)savedIntro->attachedUniqueID;
  instance->birthStreamUnitID = (int)(savedIntro->smallRotation).x;
  LIGHT_GetAmbient((_ColorType *)&instance[1].node.next,instance);
  pIVar17 = (Intro *)0x0;
  pLVar9 = STREAM_GetLevelWithID(instance->birthStreamUnitID);
  pIVar18 = pIVar17;
  if (pLVar9 != (Level *)0x0) {
    Data = pLVar9->terrain->numIntros;
    pIVar11 = pLVar9->terrain->introList;
    if (Data != 0) {
      do {
        Data = Data + -1;
        pIVar18 = pIVar11;
        if (pIVar11->UniqueID == instance->introUniqueID) break;
        pIVar11 = pIVar11 + 1;
        pIVar18 = pIVar17;
      } while (Data != 0);
    }
  }
  if (pIVar18 == (Intro *)0x0) {
    instance->intro = (Intro *)0x0;
    instance->introData = (void *)0x0;
  }
  else {
    instance->intro = pIVar18;
    instance->introData = pIVar18->data;
  }
  sVar1 = *(short *)((int)&savedIntro->flags + 2);
  sVar2 = *(short *)&savedIntro->flags2;
  sVar3 = *(short *)(p_Var7->signalList[0].data + 2);
  sVar4 = *(short *)(p_Var7->signalList[0].data + 4);
  (instance->position).x = *(short *)&savedIntro->flags + *(short *)p_Var7->signalList[0].data;
  (instance->position).y = sVar1 + sVar3;
  (instance->position).z = sVar2 + sVar4;
  sVar1 = (instance->position).z;
  *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
  (instance->initialPos).z = sVar1;
  sVar1 = (instance->position).z;
  *(undefined4 *)&instance->oldPos = *(undefined4 *)&instance->position;
  (instance->oldPos).z = sVar1;
  uVar16 = *(undefined4 *)&(savedIntro->position).y;
  *(undefined4 *)&instance->rotation = *(undefined4 *)&(savedIntro->smallRotation).z;
  *(undefined4 *)&(instance->rotation).z = uVar16;
  if ((instance->object->oflags & 0x100U) != 0) {
    INSTANCE_BuildStaticShadow(instance);
  }
  (instance->scale).x = 0x1000;
  (instance->scale).y = 0x1000;
  (instance->scale).z = 0x1000;
  instance->lightGroup = *(uchar *)&(savedIntro->smallRotation).y;
  instance->spectralLightGroup = *(uchar *)((int)&(savedIntro->smallRotation).y + 1);
  INSTANCE_InsertInstanceGroup(gameTrackerX.instanceList,instance);
  OBTABLE_GetInstanceCollideFunc(instance);
  OBTABLE_GetInstanceProcessFunc(instance);
  OBTABLE_GetInstanceQueryFunc(instance);
  OBTABLE_GetInstanceMessageFunc(instance);
  OBTABLE_GetInstanceAdditionalCollideFunc(instance);
  OBTABLE_InstanceInit(instance);
  instance->flags = *(long *)(savedIntro + 1);
  uVar12 = *(uint *)savedIntro[1].name;
  uVar15 = uVar12 & 0xfffffffe;
  instance->flags2 = uVar15;
  if ((instance->flags & 0x40000U) == 0) {
    uVar15 = uVar12 & 0xdffffffe;
  }
  else {
    uVar15 = uVar15 | 0x20000000;
  }
  instance->flags2 = uVar15;
  instance->flags = instance->flags & 0xfffbffff;
  pMVar10 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
  if (pMVar10 == (MultiSpline *)0x0) {
    instance->flags = instance->flags & 0xfdffffffU | 0x100000;
    goto LAB_800355c0;
  }
  SCRIPT_InstanceSplineSet
            (instance,savedIntro[1].streamUnitID,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0)
  ;
  instance->splineFlags = savedIntro[1].introUniqueID;
  uVar5 = instance->splineFlags;
  instance->clipBeg = savedIntro[1].birthUnitID;
  instance->clipEnd = savedIntro[1].attachedUniqueID;
  if ((uVar5 & 0x10) == 0) {
    if ((uVar5 & 0x20) == 0) {
      if ((uVar5 & 0x40) == 0) goto LAB_800355c0;
      pSVar13 = pMVar10->positional;
      if (pSVar13 != (Spline *)0x0) {
        pSVar13->flags = pSVar13->flags | 4;
      }
      pRVar14 = pMVar10->rotational;
      if (pRVar14 != (RSpline *)0x0) {
        pRVar14->flags = pRVar14->flags | 4;
      }
      pSVar13 = pMVar10->scaling;
      if (pSVar13 != (Spline *)0x0) {
        pSVar13->flags = pSVar13->flags | 4;
      }
      pSVar13 = pMVar10->color;
      if (pSVar13 == (Spline *)0x0) goto LAB_800355c0;
      bVar6 = pSVar13->flags | 4;
    }
    else {
      pSVar13 = pMVar10->positional;
      if (pSVar13 != (Spline *)0x0) {
        pSVar13->flags = pSVar13->flags | 2;
      }
      pRVar14 = pMVar10->rotational;
      if (pRVar14 != (RSpline *)0x0) {
        pRVar14->flags = pRVar14->flags | 2;
      }
      pSVar13 = pMVar10->scaling;
      if (pSVar13 != (Spline *)0x0) {
        pSVar13->flags = pSVar13->flags | 2;
      }
      pSVar13 = pMVar10->color;
      if (pSVar13 == (Spline *)0x0) goto LAB_800355c0;
      bVar6 = pSVar13->flags | 2;
    }
  }
  else {
    pSVar13 = pMVar10->positional;
    if (pSVar13 != (Spline *)0x0) {
      pSVar13->flags = pSVar13->flags | 1;
    }
    pRVar14 = pMVar10->rotational;
    if (pRVar14 != (RSpline *)0x0) {
      pRVar14->flags = pRVar14->flags | 1;
    }
    pSVar13 = pMVar10->scaling;
    if (pSVar13 != (Spline *)0x0) {
      pSVar13->flags = pSVar13->flags | 1;
    }
    pSVar13 = pMVar10->color;
    if (pSVar13 == (Spline *)0x0) goto LAB_800355c0;
    bVar6 = pSVar13->flags | 1;
  }
  pSVar13->flags = bVar6;
LAB_800355c0:
  MORPH_SetupInstanceFlags(&gameTrackerX,instance);
  if (instance->intro != (Intro *)0x0) {
    INSTANCE_ProcessIntro(instance);
  }
  if ((int)*(short *)(savedIntro[1].name + 4) != 0) {
    Data = SetControlSaveDataData
                     ((int)*(short *)(savedIntro[1].name + 4),&savedIntro[1].smallRotation);
    INSTANCE_Post(instance,0x100007,Data);
  }
  EVENT_AddInstanceToInstanceList(instance);
  INSTANCE_InitEffects(instance,object);
  return instance;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_SpatialRelationships(struct _InstanceList *instanceList /*$s4*/)
 // line 2237, offset 0x80035664
	/* begin block 1 */
		// Start line: 2238
		// Start offset: 0x80035664
		// Variables:
	// 		struct _Instance *instance; // $s1
	// 		struct _Instance *checkee; // $s0

		/* begin block 1.1 */
			// Start line: 2247
			// Start offset: 0x800356B0
			// Variables:
		// 		struct MATRIX *lookMatrix; // $s0
		// 		long checkMask; // $s3

			/* begin block 1.1.1 */
				// Start line: 2256
				// Start offset: 0x800356D8
				// Variables:
			// 		struct MATRIX invMatrix; // stack offset -80

				/* begin block 1.1.1.1 */
					// Start line: 2265
					// Start offset: 0x80035734
					// Variables:
				// 		struct evCollideInstanceStatsData data; // stack offset -48
				// 		struct MATRIX *mat; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x80035788
				// End Line: 2275
			/* end block 1.1.1 */
			// End offset: 0x80035798
			// End Line: 2277
		/* end block 1.1 */
		// End offset: 0x80035798
		// End Line: 2278
	/* end block 1 */
	// End offset: 0x800357A8
	// End Line: 2280

	/* begin block 2 */
		// Start line: 4467
	/* end block 2 */
	// End Line: 4468

void INSTANCE_SpatialRelationships(_InstanceList *instanceList)

{
  undefined4 *puVar1;
  ulong uVar2;
  int iVar3;
  MATRIX *pMVar4;
  _Instance *Inst;
  _Instance *Inst_00;
  uint uVar5;
  MATRIX MStack80;
  evCollideInstanceStatsData eStack48;
  
  Inst_00 = instanceList->first;
  while (Inst_00 != (_Instance *)0x0) {
    if ((Inst_00->flags2 & 0x10000401U) == 0x400) {
      uVar5 = Inst_00->checkMask;
      puVar1 = (undefined4 *)INSTANCE_Query(Inst_00,0xd);
      INSTANCE_Post(Inst_00,0x200000,0);
      if (puVar1 != (undefined4 *)0x0) {
        TransposeMatrix(puVar1,(undefined4 *)&MStack80);
        Inst = instanceList->first;
        while (Inst != (_Instance *)0x0) {
          if ((((Inst != Inst_00) && ((Inst->flags2 & 0x10000000U) == 0)) &&
              ((Inst->flags & 0x20U) == 0)) &&
             (uVar2 = INSTANCE_Query(Inst,1), (uVar2 & uVar5) != 0)) {
            pMVar4 = (MATRIX *)INSTANCE_Query(Inst,0xe);
            if (((pMVar4 != (MATRIX *)0x0) || (pMVar4 = Inst->matrix, pMVar4 != (MATRIX *)0x0)) &&
               (iVar3 = INSTANCE_SetStatsData(Inst_00,Inst,(_Vector *)pMVar4->t,&eStack48,&MStack80)
               , iVar3 != 0)) {
              INSTANCE_Post(Inst_00,0x200001,(int)&eStack48);
            }
          }
          Inst = Inst->next;
        }
      }
    }
    Inst_00 = Inst_00->next;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ INSTANCE_SetStatsData(struct _Instance *instance /*$s1*/, struct _Instance *checkee /*$s5*/, struct _Vector *checkPoint /*$s2*/, struct evCollideInstanceStatsData *data /*$s3*/, struct MATRIX *mat /*stack 16*/)
 // line 2284, offset 0x800357c8
	/* begin block 1 */
		// Start line: 2285
		// Start offset: 0x800357C8
		// Variables:
	// 		long distance; // $s4

		/* begin block 1.1 */
			// Start line: 2290
			// Start offset: 0x80035834
			// Variables:
		// 		struct SVECTOR *delta; // $s0
		/* end block 1.1 */
		// End offset: 0x8003583C
		// End Line: 2307
	/* end block 1 */
	// End offset: 0x800358B4
	// End Line: 2309

	/* begin block 2 */
		// Start line: 5243
	/* end block 2 */
	// End Line: 5244

int INSTANCE_SetStatsData
              (_Instance *instance,_Instance *checkee,_Vector *checkPoint,
              evCollideInstanceStatsData *data,MATRIX *mat)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  
  uVar2 = MATH3D_LengthXYZ((int)(instance->position).x - checkPoint->x,
                           (int)(instance->position).y - checkPoint->y,
                           (int)(instance->position).z - checkPoint->z);
  bVar1 = uVar2 < instance->maxCheckDistance;
  if (bVar1) {
    DAT_1f800000 = *(short *)&checkPoint->x - (instance->position).x;
    DAT_1f800002 = *(short *)&checkPoint->y - (instance->position).y;
    DAT_1f800004 = *(short *)&checkPoint->z - (instance->position).z;
    ApplyMatrixSV(mat,0x1f800000,&data->relativePosition);
    data->instance = checkee;
    data->distance = uVar2;
    data->zDelta = (int)DAT_1f800004;
    lVar3 = MATH3D_LengthXY((int)DAT_1f800000,(int)DAT_1f800002);
    data->xyDistance = lVar3;
  }
  return (uint)bVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_LinkToParent(struct _Instance *instance /*$s0*/, struct _Instance *parent /*$s1*/, int node /*$a2*/)
 // line 2313, offset 0x800358d8
	/* begin block 1 */
		// Start line: 5326
	/* end block 1 */
	// End Line: 5327

void INSTANCE_LinkToParent(_Instance *instance,_Instance *parent,int node)

{
  short sVar1;
  
  instance->LinkSibling = parent->LinkChild;
  parent->LinkChild = instance;
  sVar1 = (instance->scale).x;
  instance->LinkParent = parent;
  instance->ParentLinkNode = node;
  (instance->scale).x = (short)(((int)sVar1 << 0xc) / (int)(parent->scale).x);
  (instance->scale).y = (short)(((int)(instance->scale).y << 0xc) / (int)(parent->scale).y);
  (instance->scale).z = (short)(((int)(instance->scale).z << 0xc) / (int)(parent->scale).z);
  INSTANCE_UpdateFamilyStreamUnitID(parent);
  INSTANCE_Post(parent,0x100012,(int)instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_UnlinkFromParent(struct _Instance *instance /*$s0*/)
 // line 2332, offset 0x80035984
	/* begin block 1 */
		// Start line: 2333
		// Start offset: 0x80035984
		// Variables:
	// 		struct _Instance *parent; // $s1

		/* begin block 1.1 */
			// Start line: 2337
			// Start offset: 0x800359A8
			// Variables:
		// 		struct _G2EulerAngles_Type ea; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 2345
				// Start offset: 0x800359C4
				// Variables:
			// 		struct _Instance *sibling; // $v1
			/* end block 1.1.1 */
			// End offset: 0x800359F8
			// End Line: 2351
		/* end block 1.1 */
		// End offset: 0x80035ABC
		// End Line: 2371
	/* end block 1 */
	// End offset: 0x80035ABC
	// End Line: 2372

	/* begin block 2 */
		// Start line: 5370
	/* end block 2 */
	// End Line: 5371

void INSTANCE_UnlinkFromParent(_Instance *instance)

{
  short sVar1;
  _Instance *p_Var2;
  _Instance *p_Var3;
  int iVar4;
  _Instance *Inst;
  int iVar5;
  _G2EulerAngles_Type local_18;
  
  Inst = instance->LinkParent;
  if (Inst != (_Instance *)0x0) {
    p_Var2 = Inst->LinkChild;
    if (p_Var2 == instance) {
      Inst->LinkChild = instance->LinkSibling;
    }
    else {
      p_Var3 = p_Var2->LinkSibling;
      while (p_Var3 != instance) {
        p_Var2 = p_Var2->LinkSibling;
        p_Var3 = p_Var2->LinkSibling;
      }
      p_Var2->LinkSibling = instance->LinkSibling;
    }
    sVar1 = (instance->scale).x;
    instance->LinkSibling = (_Instance *)0x0;
    instance->LinkParent = (_Instance *)0x0;
    iVar5 = (int)sVar1 * (int)(Inst->scale).x;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0xfff;
    }
    (instance->scale).x = (short)(iVar5 >> 0xc);
    iVar5 = (int)(instance->scale).y * (int)(Inst->scale).y;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0xfff;
    }
    (instance->scale).y = (short)(iVar5 >> 0xc);
    iVar5 = (int)(instance->scale).z * (int)(Inst->scale).z;
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0xfff;
    }
    iVar4 = instance->ParentLinkNode;
    (instance->scale).z = (short)(iVar5 >> 0xc);
    G2EulerAngles_FromMatrix(&local_18,(_G2Matrix_Type *)(Inst->matrix + iVar4),0x15);
    (instance->rotation).x = local_18.x;
    (instance->rotation).y = local_18.y;
    (instance->rotation).z = local_18.z;
    INSTANCE_Post(Inst,0x100013,(int)instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_UnlinkChildren(struct _Instance *instance /*$s2*/)
 // line 2374, offset 0x80035ad0
	/* begin block 1 */
		// Start line: 2375
		// Start offset: 0x80035AD0
		// Variables:
	// 		struct _Instance *child; // $s1

		/* begin block 1.1 */
			// Start line: 2380
			// Start offset: 0x80035AF8
			// Variables:
		// 		struct _Instance *sibling; // $s0
		/* end block 1.1 */
		// End offset: 0x80035AF8
		// End Line: 2380
	/* end block 1 */
	// End offset: 0x80035B20
	// End Line: 2391

	/* begin block 2 */
		// Start line: 5479
	/* end block 2 */
	// End Line: 5480

void INSTANCE_UnlinkChildren(_Instance *instance)

{
  _Instance *Data;
  _Instance *p_Var1;
  
  Data = instance->LinkChild;
  while (Data != (_Instance *)0x0) {
    p_Var1 = Data->LinkSibling;
    INSTANCE_Post(instance,0x100013,(int)Data);
    Data->LinkParent = (_Instance *)0x0;
    Data->LinkSibling = (_Instance *)0x0;
    Data = p_Var1;
  }
  instance->LinkChild = (_Instance *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_UpdateFamilyStreamUnitID(struct _Instance *instance /*$s1*/)
 // line 2397, offset 0x80035b3c
	/* begin block 1 */
		// Start line: 2398
		// Start offset: 0x80035B3C
		// Variables:
	// 		struct _Instance *child; // $s0
	/* end block 1 */
	// End offset: 0x80035B80
	// End Line: 2406

	/* begin block 2 */
		// Start line: 5528
	/* end block 2 */
	// End Line: 5529

void INSTANCE_UpdateFamilyStreamUnitID(_Instance *instance)

{
  _Instance *instance_00;
  
  instance_00 = instance->LinkChild;
  while (instance_00 != (_Instance *)0x0) {
    instance_00->currentStreamUnitID = instance->currentStreamUnitID;
    INSTANCE_UpdateFamilyStreamUnitID(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_GetChildLinkedToSegment(struct _Instance *instance /*$a0*/, int segment /*$a1*/)
 // line 2411, offset 0x80035b94
	/* begin block 1 */
		// Start line: 2413
		// Start offset: 0x80035B94
		// Variables:
	// 		struct _Instance *child; // $v1
	/* end block 1 */
	// End offset: 0x80035BC4
	// End Line: 2421

	/* begin block 2 */
		// Start line: 5559
	/* end block 2 */
	// End Line: 5560

	/* begin block 3 */
		// Start line: 5560
	/* end block 3 */
	// End Line: 5561

	/* begin block 4 */
		// Start line: 5562
	/* end block 4 */
	// End Line: 5563

_Instance * INSTANCE_GetChildLinkedToSegment(_Instance *instance,int segment)

{
  _Instance *p_Var1;
  
  p_Var1 = instance->LinkChild;
  while ((p_Var1 != (_Instance *)0x0 && (p_Var1->ParentLinkNode != segment))) {
    p_Var1 = p_Var1->LinkSibling;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ INSTANCE_Linked(struct _Instance *instance1 /*$a0*/, struct _Instance *instance2 /*$a1*/)
 // line 2427, offset 0x80035bcc
	/* begin block 1 */
		// Start line: 2429
		// Start offset: 0x80035BCC
		// Variables:
	// 		struct _Instance *root1; // $a0
	// 		struct _Instance *root2; // $a1
	/* end block 1 */
	// End offset: 0x80035C14
	// End Line: 2437

	/* begin block 2 */
		// Start line: 5593
	/* end block 2 */
	// End Line: 5594

	/* begin block 3 */
		// Start line: 5594
	/* end block 3 */
	// End Line: 5595

	/* begin block 4 */
		// Start line: 5596
	/* end block 4 */
	// End Line: 5597

int INSTANCE_Linked(_Instance *instance1,_Instance *instance2)

{
  _Instance *p_Var1;
  
  p_Var1 = instance1->LinkParent;
  while (p_Var1 != (_Instance *)0x0) {
    instance1 = instance1->LinkParent;
    p_Var1 = instance1->LinkParent;
  }
  while (instance2->LinkParent != (_Instance *)0x0) {
    instance2 = instance2->LinkParent;
  }
  return (uint)(instance1 == instance2);
}



// decompiled code
// original method signature: 
// int /*$ra*/ INSTANCE_GetFadeValue(struct _Instance *instance /*$s1*/)
 // line 2445, offset 0x80035c1c
	/* begin block 1 */
		// Start line: 2446
		// Start offset: 0x80035C1C
		// Variables:
	// 		int fadeValue; // $s0
	/* end block 1 */
	// End offset: 0x80035CE8
	// End Line: 2470

	/* begin block 2 */
		// Start line: 5629
	/* end block 2 */
	// End Line: 5630

int INSTANCE_GetFadeValue(_Instance *instance)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)instance->fadeValue;
  if (gameTrackerX.gameData.asmData.MorphTime != 1000) {
    iVar3 = 0x1000 - iVar3;
    lVar2 = MEMPACK_MemoryValidFunc((char *)instance->object);
    if ((lVar2 != 0) &&
       (((instance->object->oflags2 & 0x2000000U) != 0 ||
        ((instance->LinkParent != (_Instance *)0x0 &&
         ((instance->LinkParent->object->oflags2 & 0x2000000U) != 0)))))) {
      sVar1 = gameTrackerX.lastLoopTime._2_2_;
      if ((instance->flags2 & 0x8000000U) != 0) {
        sVar1 = (short)gameTrackerX.lastLoopTime;
      }
      iVar4 = sVar1 * iVar3;
      iVar3 = iVar4 >> 0xc;
      if (iVar4 < 0) {
        iVar3 = iVar4 + 0xfff >> 0xc;
      }
    }
    iVar3 = 0x1000 - iVar3;
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ INSTANCE_DefaultAnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s0*/, long messageDataB /*stack 16*/, struct _Instance *instance /*stack 20*/)
 // line 2481, offset 0x80035d00
	/* begin block 1 */
		// Start line: 2482
		// Start offset: 0x80035D00
	/* end block 1 */
	// End offset: 0x80035D6C
	// End Line: 2506

	/* begin block 2 */
		// Start line: 5705
	/* end block 2 */
	// End Line: 5706

ulong INSTANCE_DefaultAnimCallback
                (_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,long messageDataA,
                long messageDataB,_Instance *instance)

{
  if (message == G2ANIM_MSG_PLAYEFFECT) {
    if (messageDataA == 0) {
      if (messageDataB != 0) {
        SOUND_Play3dSound(&instance->position,(int)*(short *)messageDataB,
                          (int)*(short *)(messageDataB + 4),(int)*(short *)(messageDataB + 2),
                          (int)*(short *)(messageDataB + 6));
      }
    }
    else {
      if (messageDataA == 1) {
        FX_StartInstanceEffect(instance,(ObjectEffect *)messageDataB,0);
      }
    }
  }
  return messageDataA;
}





