#include "THISDUST.H"
#include "INSTANCE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_Deactivate(struct _Instance *instance /*$s0*/)
 // line 51, offset 0x800321b4
	/* begin block 1 */
		// Start line: 52
		// Start offset: 0x800321B4
		// Variables:
	// 		struct Object *object; // $a2
	/* end block 1 */
	// End offset: 0x80032260
	// End Line: 77

	/* begin block 2 */
		// Start line: 102
	/* end block 2 */
	// End Line: 103

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
    instance->waterFace = (_TFace *)0x0;
    instance->waterFaceTerrain = (_Terrain *)0x0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_Reactivate(struct _Instance *instance /*$a0*/)
 // line 80, offset 0x80032270
	/* begin block 1 */
		// Start line: 81
		// Start offset: 0x80032270
		// Variables:
	// 		struct Object *object; // $a2
	/* end block 1 */
	// End offset: 0x800322F8
	// End Line: 103

	/* begin block 2 */
		// Start line: 167
	/* end block 2 */
	// End Line: 168

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
 // line 106, offset 0x80032308
	/* begin block 1 */
		// Start line: 228
	/* end block 1 */
	// End Line: 229

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
 // line 116, offset 0x8003233c
	/* begin block 1 */
		// Start line: 248
	/* end block 1 */
	// End Line: 249

	/* begin block 2 */
		// Start line: 250
	/* end block 2 */
	// End Line: 251

void INSTANCE_DeactivatedProcess(_Instance *instance,GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_DeactivateFarInstances(struct GameTracker *gameTracker /*$s3*/)
 // line 122, offset 0x80032344
	/* begin block 1 */
		// Start line: 123
		// Start offset: 0x80032344
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
	// End offset: 0x800325A4
	// End Line: 220

	/* begin block 2 */
		// Start line: 260
	/* end block 2 */
	// End Line: 261

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
  if (iVar5 <= DAT_800d0810) {
    DAT_800d0810 = 0;
  }
  iVar3 = DAT_800d0810;
  DAT_800d0810 = DAT_800d0810 + iVar6;
  if (iVar5 <= DAT_800d0810) {
    DAT_800d0810 = 0;
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
       (((uVar1 = INSTANCE_Query(Inst,0x2f), uVar1 == 0 && (Inst->LinkParent == (_Instance *)0x0))
        && (Inst->matrix != (MATRIX *)0x0)))) {
      DAT_1f800000._0_2_ = (Inst->position).x - theCamera.core.position.x;
      iVar5 = (uint)(ushort)(Inst->position).y - (uint)(ushort)theCamera.core.position.y;
      DAT_1f800000._2_2_ = (undefined2)iVar5;
      iVar5 = iVar5 * 0x10000 >> 0x10;
      iVar4 = (uint)(ushort)(Inst->position).z - (uint)(ushort)theCamera.core.position.z;
      iVar3 = iVar4 * 0x10000 >> 0x10;
      DAT_1f800004._0_2_ = (undefined2)iVar4;
      iVar5 = (int)(short)DAT_1f800000 * (int)(short)DAT_1f800000 + iVar5 * iVar5 + iVar3 * iVar3;
      if ((Inst->flags & 0x200U) == 0) {
        if ((Inst->flags2 & 0x80000U) == 0) {
          iVar3 = (int)Inst->object->removeDist;
          iVar3 = iVar3 * iVar3;
        }
        else {
          iVar3 = gameTracker->defRemoveDist * gameTracker->defRemoveDist;
        }
        uVar2 = Inst->flags2 & 1;
        if (iVar5 <= iVar3) goto LAB_80032584;
      }
      else {
        iVar3 = (int)Inst->object->vvRemoveDist;
        if (iVar5 <= iVar3 * iVar3) {
          uVar2 = Inst->flags2 & 1;
          goto LAB_80032584;
        }
        uVar2 = Inst->flags2 & 1;
      }
      if (uVar2 == 0) {
        INSTANCE_Deactivate(Inst);
      }
    }
    else {
      uVar2 = Inst->flags2 & 1;
LAB_80032584:
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
 // line 243, offset 0x800325c0
	/* begin block 1 */
		// Start line: 245
		// Start offset: 0x800325C0
		// Variables:
	// 		long i; // $a3
	/* end block 1 */
	// End offset: 0x80032654
	// End Line: 278

	/* begin block 2 */
		// Start line: 528
	/* end block 2 */
	// End Line: 529

	/* begin block 3 */
		// Start line: 529
	/* end block 3 */
	// End Line: 530

	/* begin block 4 */
		// Start line: 532
	/* end block 4 */
	// End Line: 533

void INSTANCE_InitInstanceList(_InstanceList *list,_InstancePool *pool)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  pool->numFreeInstances = 0x3c;
  iVar4 = 1;
  iVar6 = 8;
  iVar5 = 0x540;
  plVar3 = &pool->instance[0].light_color;
  do {
    iVar2 = (int)&pool->nextInstanceID + iVar6;
    iVar6 = iVar6 + 0x29c;
    iVar1 = (int)&pool->nextInstanceID + iVar5;
    iVar5 = iVar5 + 0x29c;
    plVar3[4] = iVar1;
    plVar3[5] = iVar2;
    iVar4 = iVar4 + 1;
    plVar3 = plVar3 + 0xa7;
  } while (iVar4 < 0x3b);
  iVar4 = 0;
  pool->instance[0].next = pool->instance + 1;
  pool->instance[0].prev = (_Instance *)0x0;
  pool->instance[0x3b].prev = (_Instance *)(&DAT_00009760 + (int)pool);
  pool->instance[0x3b].next = (_Instance *)0x0;
  pool->first_free = pool->instance;
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
 // line 334, offset 0x80032660
	/* begin block 1 */
		// Start line: 336
		// Start offset: 0x80032660
		// Variables:
	// 		struct _Instance *temp; // $v0
	// 		struct _Instance *instance; // $a1
	/* end block 1 */
	// End offset: 0x800326E4
	// End Line: 375

	/* begin block 2 */
		// Start line: 745
	/* end block 2 */
	// End Line: 746

	/* begin block 3 */
		// Start line: 746
	/* end block 3 */
	// End Line: 747

	/* begin block 4 */
		// Start line: 751
	/* end block 4 */
	// End Line: 752

_Instance * INSTANCE_NewInstance(_InstanceList *list)

{
  int iVar1;
  _Instance *p_Var2;
  _InstancePool *p_Var3;
  _Instance *p_Var4;
  
  iVar1 = list->pool->numFreeInstances;
  if (iVar1 != 0) {
    list->pool->numFreeInstances = iVar1 + -1;
    p_Var4 = list->pool->first_free;
    list->pool->first_free = p_Var4->next;
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
    return p_Var4;
  }
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// long /*$ra*/ INSTANCE_InstanceGroupNumber(struct _Instance *instance /*$a0*/)
 // line 377, offset 0x800326ec
	/* begin block 1 */
		// Start line: 378
		// Start offset: 0x800326EC
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x800327F4
	// End Line: 417

	/* begin block 2 */
		// Start line: 834
	/* end block 2 */
	// End Line: 835

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
 // line 436, offset 0x80032808
	/* begin block 1 */
		// Start line: 437
		// Start offset: 0x80032808
	/* end block 1 */
	// End offset: 0x80032808
	// End Line: 437

	/* begin block 2 */
		// Start line: 952
	/* end block 2 */
	// End Line: 953

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
 // line 485, offset 0x80032850
	/* begin block 1 */
		// Start line: 486
		// Start offset: 0x80032850
		// Variables:
	// 		struct _Instance *temp; // $v1

		/* begin block 1.1 */
			// Start line: 588
			// Start offset: 0x80032A84
			// Variables:
		// 		int i; // $a0
		/* end block 1.1 */
		// End offset: 0x80032AA4
		// End Line: 597
	/* end block 1 */
	// End offset: 0x80032AA4
	// End Line: 598

	/* begin block 2 */
		// Start line: 970
	/* end block 2 */
	// End Line: 971

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
  p_Var1 = list->pool->first_free;
  list->pool->first_free = instance;
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
    *(undefined2 *)((int)instance->shadow0 + 0x10) = 0;
  }
  if (instance->shadow1 != (void *)0x0) {
    *(undefined2 *)((int)instance->shadow1 + 0x10) = 0;
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
  if (instance->perVertexColor != (CVECTOR *)0x0) {
    MEMPACK_Free((char *)instance->perVertexColor);
    instance->perVertexColor = (CVECTOR *)0x0;
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
 // line 601, offset 0x80032abc
	/* begin block 1 */
		// Start line: 602
		// Start offset: 0x80032ABC
		// Variables:
	// 		struct _Instance *instance; // $a1
	// 		struct _Instance *next; // $s0
	/* end block 1 */
	// End offset: 0x80032B60
	// End Line: 636

	/* begin block 2 */
		// Start line: 1320
	/* end block 2 */
	// End Line: 1321

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
 // line 706, offset 0x80032b78
	/* begin block 1 */
		// Start line: 707
		// Start offset: 0x80032B78
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $s1
	/* end block 1 */
	// End offset: 0x80032C18
	// End Line: 747

	/* begin block 2 */
		// Start line: 1412
	/* end block 2 */
	// End Line: 1413

	/* begin block 3 */
		// Start line: 1462
	/* end block 3 */
	// End Line: 1463

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
 // line 751, offset 0x80032c30
	/* begin block 1 */
		// Start line: 1572
	/* end block 1 */
	// End Line: 1573

	/* begin block 2 */
		// Start line: 1573
	/* end block 2 */
	// End Line: 1574

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
 // line 766, offset 0x80032c80
	/* begin block 1 */
		// Start line: 1604
	/* end block 1 */
	// End Line: 1605

INICommand * INSTANCE_FindIntroCommand(_Instance *instance,int cmd)

{
  INICommand *pIVar1;
  
  pIVar1 = INSTANCE_GetIntroCommand((INICommand *)instance->introData,cmd);
  return pIVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_ProcessIntro(struct _Instance *instance /*$a0*/)
 // line 773, offset 0x80032ca4
	/* begin block 1 */
		// Start line: 775
		// Start offset: 0x80032CA4

		/* begin block 1.1 */
			// Start line: 775
			// Start offset: 0x80032CC8
			// Variables:
		// 		struct INICommand *command; // $a1
		/* end block 1.1 */
		// End offset: 0x80032D18
		// End Line: 795
	/* end block 1 */
	// End offset: 0x80032D18
	// End Line: 796

	/* begin block 2 */
		// Start line: 1618
	/* end block 2 */
	// End Line: 1619

	/* begin block 3 */
		// Start line: 1619
	/* end block 3 */
	// End Line: 1620

void INSTANCE_ProcessIntro(_Instance *instance)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  
  psVar3 = (short *)instance->introData;
  if ((psVar3 != (short *)0x0) && ((instance->flags & 2U) == 0)) {
    sVar1 = *psVar3;
    sVar2 = *psVar3;
    while (sVar1 != 0) {
      if (sVar2 == 0x12) {
        instance->currentModel = psVar3[2];
      }
      psVar3 = psVar3 + (int)psVar3[1] * 2 + 2;
      sVar1 = *psVar3;
      sVar2 = *psVar3;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_InitEffects(struct _Instance *instance /*$s2*/, struct Object *object /*$s1*/)
 // line 798, offset 0x80032d20
	/* begin block 1 */
		// Start line: 799
		// Start offset: 0x80032D20
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80032D90
	// End Line: 811

	/* begin block 2 */
		// Start line: 1673
	/* end block 2 */
	// End Line: 1674

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
 // line 813, offset 0x80032da8
	/* begin block 1 */
		// Start line: 814
		// Start offset: 0x80032DA8
		// Variables:
	// 		struct Object *object; // $s6
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *attachInst; // $s5
	// 		struct _ObjectTracker *objectTracker; // $s1

		/* begin block 1.1 */
			// Start line: 829
			// Start offset: 0x80032DEC
			// Variables:
		// 		struct INICommand *index; // $v0
		// 		long attachedUniqueID; // $s4

			/* begin block 1.1.1 */
				// Start line: 966
				// Start offset: 0x800330B8
			/* end block 1.1.1 */
			// End offset: 0x800330F4
			// End Line: 976

			/* begin block 1.1.2 */
				// Start line: 1026
				// Start offset: 0x800331E8
				// Variables:
			// 		struct SavedIntroSpline *savedIntroSpline; // $s1
			// 		struct MultiSpline *spline; // $s2
			/* end block 1.1.2 */
			// End offset: 0x80033440
			// End Line: 1076

			/* begin block 1.1.3 */
				// Start line: 1078
				// Start offset: 0x80033440
				// Variables:
			// 		struct SavedIntroSmall *savedIntroSmall; // $v0

				/* begin block 1.1.3.1 */
					// Start line: 1092
					// Start offset: 0x8003346C
				/* end block 1.1.3.1 */
				// End offset: 0x80033494
				// End Line: 1099
			/* end block 1.1.3 */
			// End offset: 0x80033494
			// End Line: 1101
		/* end block 1.1 */
		// End offset: 0x8003349C
		// End Line: 1117
	/* end block 1 */
	// End offset: 0x800334A0
	// End Line: 1119

	/* begin block 2 */
		// Start line: 1705
	/* end block 2 */
	// End Line: 1706

_Instance * INSTANCE_IntroduceInstance(Intro *intro,short streamUnitID)

{
  byte bVar1;
  short frameNum;
  long lVar2;
  INICommand *pIVar3;
  _ObjectTracker *objectTracker;
  _Instance *instance;
  MultiSpline *pMVar4;
  SavedIntroSpline *pSVar5;
  SavedIntroSmall *pSVar6;
  int Data;
  uint uVar7;
  Spline *pSVar8;
  RSpline *pRVar9;
  undefined4 uVar10;
  INICommand introUniqueID;
  _Instance *instance_00;
  Object *object;
  
  instance_00 = (_Instance *)0x0;
  lVar2 = INSTANCE_Introduced(intro,streamUnitID);
  if (lVar2 != 0) {
    return (_Instance *)0x0;
  }
  introUniqueID = (INICommand)0x0;
  pIVar3 = INSTANCE_GetIntroCommand((INICommand *)intro->data,0x1a);
  if (pIVar3 != (INICommand *)0x0) {
    introUniqueID = pIVar3[1];
  }
  objectTracker = STREAM_GetObjectTracker((char *)intro);
  if (objectTracker != (_ObjectTracker *)0x0) {
    object = objectTracker->object;
    if (objectTracker->objectStatus != 2) {
      return (_Instance *)0x0;
    }
    if ((introUniqueID != (INICommand)0x0) &&
       (instance_00 = INSTANCE_Find((long)introUniqueID), instance_00 == (_Instance *)0x0)) {
      return (_Instance *)0x0;
    }
    if (((object->oflags2 & 0x10000000U) != 0) &&
       (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) != 0)) {
      return (_Instance *)0x0;
    }
    instance = INSTANCE_NewInstance(gameTrackerX.instanceList);
    if (instance != (_Instance *)0x0) {
      intro->flags = intro->flags | 8;
      objectTracker->numInUse = objectTracker->numInUse + 1;
      INSTANCE_DefaultInit(instance,object,0);
      strcpy(instance->introName,(char *)intro);
      instance->introUniqueID = intro->UniqueID;
      lVar2 = intro->intronum;
      instance->birthStreamUnitID = (int)streamUnitID;
      instance->currentStreamUnitID = (int)streamUnitID;
      instance->introNum = lVar2;
      intro->instance = instance;
      instance->intro = intro;
      instance->introData = intro->data;
      frameNum = (intro->position).z;
      *(undefined4 *)&instance->position = *(undefined4 *)&intro->position;
      (instance->position).z = frameNum;
      if ((gameTrackerX.gameData.asmData.MorphType == 1) &&
         ((*(int *)&intro->spectralPosition != 0 || ((intro->spectralPosition).z != 0)))) {
        (instance->position).x = (intro->position).x + (intro->spectralPosition).x;
        (instance->position).y = (intro->position).y + (intro->spectralPosition).y;
        (instance->position).z = (intro->position).z + (intro->spectralPosition).z;
      }
      frameNum = (instance->position).z;
      *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
      (instance->initialPos).z = frameNum;
      frameNum = (intro->position).z;
      *(undefined4 *)&instance->oldPos = *(undefined4 *)&intro->position;
      (instance->oldPos).z = frameNum;
      *(INICommand *)&instance->attachedID = introUniqueID;
      LIGHT_GetAmbient((_ColorType *)&instance->light_color,instance);
      uVar10 = *(undefined4 *)&(intro->rotation).z;
      *(undefined4 *)&instance->rotation = *(undefined4 *)&intro->rotation;
      *(undefined4 *)&(instance->rotation).z = uVar10;
      if ((instance->object->oflags & 0x100U) != 0) {
        INSTANCE_BuildStaticShadow(instance);
      }
      (instance->scale).x = 0x1000;
      (instance->scale).y = 0x1000;
      (instance->scale).z = 0x1000;
      if ((intro->flags & 0x2000U) != 0) {
        instance->flags = instance->flags | 0x400;
      }
      if ((intro->flags & 0x10000U) != 0) {
        instance->flags2 = instance->flags2 | 0x20000;
      }
      if (instance_00 != (_Instance *)0x0) {
        INSTANCE_ForceActive(instance_00);
        instance_00->flags2 = instance_00->flags2 | 0x80;
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
      MORPH_SetupInstanceFlags(instance);
      if ((intro->flags & 0x80U) != 0) {
        uVar7 = instance->flags2;
        instance->flags = instance->flags | 0x800;
        instance->flags2 = uVar7 | 0x20000000;
        if ((object->oflags2 & 0x80000U) != 0) {
          instance->flags2 = uVar7 | 0x30000000;
        }
      }
      pMVar4 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
      if (pMVar4 == (MultiSpline *)0x0) {
        instance->flags = instance->flags & 0xfdffffffU | 0x100000;
      }
      else {
        pMVar4 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
        pSVar5 = SAVE_GetIntroSpline(instance);
        if (pSVar5 != (SavedIntroSpline *)0x0) {
          SCRIPT_InstanceSplineSet
                    (instance,pSVar5->splineKeyFrame,(SplineDef *)0x0,(SplineDef *)0x0,
                     (SplineDef *)0x0);
          frameNum = (instance->position).z;
          *(undefined4 *)&instance->oldPos = *(undefined4 *)&instance->position;
          (instance->oldPos).z = frameNum;
          instance->splineFlags = pSVar5->splineFlags;
          instance->clipBeg = pSVar5->splineClipBeg;
          instance->clipEnd = pSVar5->splineClipEnd;
          if ((instance->splineFlags & 0x80U) != 0) {
            instance->flags = instance->flags | 0x1000000;
          }
          if ((instance->splineFlags & 0x100U) != 0) {
            instance->flags = instance->flags | 0x2000000;
          }
          if ((pSVar5->splineFlags & 0x10U) == 0) {
            if ((instance->splineFlags & 0x20U) == 0) {
              if ((instance->splineFlags & 0x40U) == 0) goto LAB_80033440;
              pSVar8 = pMVar4->positional;
              if (pSVar8 != (Spline *)0x0) {
                pSVar8->flags = pSVar8->flags | 4;
              }
              pRVar9 = pMVar4->rotational;
              if (pRVar9 != (RSpline *)0x0) {
                pRVar9->flags = pRVar9->flags | 4;
              }
              pSVar8 = pMVar4->scaling;
              if (pSVar8 != (Spline *)0x0) {
                pSVar8->flags = pSVar8->flags | 4;
              }
              pSVar8 = pMVar4->color;
              if (pSVar8 == (Spline *)0x0) goto LAB_80033440;
              bVar1 = pSVar8->flags | 4;
            }
            else {
              pSVar8 = pMVar4->positional;
              if (pSVar8 != (Spline *)0x0) {
                pSVar8->flags = pSVar8->flags | 2;
              }
              pRVar9 = pMVar4->rotational;
              if (pRVar9 != (RSpline *)0x0) {
                pRVar9->flags = pRVar9->flags | 2;
              }
              pSVar8 = pMVar4->scaling;
              if (pSVar8 != (Spline *)0x0) {
                pSVar8->flags = pSVar8->flags | 2;
              }
              pSVar8 = pMVar4->color;
              if (pSVar8 == (Spline *)0x0) goto LAB_80033440;
              bVar1 = pSVar8->flags | 2;
            }
          }
          else {
            pSVar8 = pMVar4->positional;
            if (pSVar8 != (Spline *)0x0) {
              pSVar8->flags = pSVar8->flags | 1;
            }
            pRVar9 = pMVar4->rotational;
            if (pRVar9 != (RSpline *)0x0) {
              pRVar9->flags = pRVar9->flags | 1;
            }
            pSVar8 = pMVar4->scaling;
            if (pSVar8 != (Spline *)0x0) {
              pSVar8->flags = pSVar8->flags | 1;
            }
            pSVar8 = pMVar4->color;
            if (pSVar8 == (Spline *)0x0) goto LAB_80033440;
            bVar1 = pSVar8->flags | 1;
          }
          pSVar8->flags = bVar1;
        }
      }
LAB_80033440:
      EVENT_AddInstanceToInstanceList(instance);
      INSTANCE_ProcessIntro(instance);
      INSTANCE_InitEffects(instance,object);
      pSVar6 = SAVE_GetSavedSmallIntro(instance);
      if (pSVar6 == (SavedIntroSmall *)0x0) {
        return instance;
      }
      Data = SetControlSaveDataData((uint)pSVar6->shiftedSaveSize * 4 + -4,pSVar6 + 1);
      INSTANCE_Post(instance,(int)&DAT_00100007,Data);
      return instance;
    }
  }
  return (_Instance *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_AdditionalCollideFunctions(struct _InstanceList *instanceList /*$a0*/)
 // line 1124, offset 0x800334c8
	/* begin block 1 */
		// Start line: 1125
		// Start offset: 0x800334C8
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x800335D8
	// End Line: 1156

	/* begin block 2 */
		// Start line: 2395
	/* end block 2 */
	// End Line: 2396

void INSTANCE_AdditionalCollideFunctions(_InstanceList *instanceList)

{
  _Instance *p_Var1;
  
  p_Var1 = instanceList->first;
  while (p_Var1 != (_Instance *)0x0) {
    if ((((gameTrackerX.gameMode != 6) || ((p_Var1->object->oflags & 0x20000U) != 0)) &&
        (((gameTrackerX.streamFlags & 0x100000U) == 0 || ((p_Var1->object->oflags & 0x40000U) != 0))
        )) && ((p_Var1->additionalCollideFunc != (_func_3 *)0x0 &&
               ((p_Var1->flags2 & 0x24000000U) == 0)))) {
      gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
      if ((p_Var1->object != (Object *)0x0) &&
         (((p_Var1->object->oflags2 & 0x2000000U) != 0 &&
          (gameTrackerX.timeMult = gameTrackerX.materialTimeMult, (p_Var1->flags2 & 0x8000000U) != 0
          )))) {
        gameTrackerX.timeMult = gameTrackerX.spectralTimeMult;
      }
      (*p_Var1->additionalCollideFunc)(p_Var1,&gameTrackerX);
    }
    p_Var1 = p_Var1->next;
  }
  gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ INSTANCE_GetSplineFrameNumber(struct _Instance *instance /*$s0*/, struct MultiSpline *spline /*$a1*/)
 // line 1159, offset 0x800335f0
	/* begin block 1 */
		// Start line: 1160
		// Start offset: 0x800335F0
	/* end block 1 */
	// End offset: 0x800335F0
	// End Line: 1160

	/* begin block 2 */
		// Start line: 2486
	/* end block 2 */
	// End Line: 2487

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
 // line 1172, offset 0x80033628
	/* begin block 1 */
		// Start line: 1173
		// Start offset: 0x80033628

		/* begin block 1.1 */
			// Start line: 1179
			// Start offset: 0x80033668
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.1.1 */
				// Start line: 1201
				// Start offset: 0x80033720
				// Variables:
			// 		int hidden; // $s2
			// 		int burning; // $s1
			/* end block 1.1.1 */
			// End offset: 0x800337D4
			// End Line: 1224

			/* begin block 1.1.2 */
				// Start line: 1250
				// Start offset: 0x800338A4
				// Variables:
			// 		long prevFrame; // $s2
			// 		struct MultiSpline *multi; // $s4

				/* begin block 1.1.2.1 */
					// Start line: 1257
					// Start offset: 0x800338D4
					// Variables:
				// 		long endOfSpline; // $s6
				// 		short direction; // $s7

					/* begin block 1.1.2.1.1 */
						// Start line: 1296
						// Start offset: 0x80033994
						// Variables:
					// 		long frame; // $s3
					// 		long maxFrames; // $s1
					/* end block 1.1.2.1.1 */
					// End offset: 0x80033BD4
					// End Line: 1375

					/* begin block 1.1.2.1.2 */
						// Start line: 1386
						// Start offset: 0x80033C08
					/* end block 1.1.2.1.2 */
					// End offset: 0x80033C2C
					// End Line: 1391
				/* end block 1.1.2.1 */
				// End offset: 0x80033DA4
				// End Line: 1451
			/* end block 1.1.2 */
			// End offset: 0x80033DA4
			// End Line: 1453

			/* begin block 1.1.3 */
				// Start line: 1476
				// Start offset: 0x80033DE8
				// Variables:
			// 		int killTest; // $s1
			/* end block 1.1.3 */
			// End offset: 0x80033E24
			// End Line: 1483
		/* end block 1.1 */
		// End offset: 0x80033E58
		// End Line: 1495
	/* end block 1 */
	// End offset: 0x80033E80
	// End Line: 1505

	/* begin block 2 */
		// Start line: 2516
	/* end block 2 */
	// End Line: 2517

void INSTANCE_ProcessFunctions(_InstanceList *instanceList)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  bool bVar5;
  short frameNum;
  uint uVar6;
  ulong uVar7;
  MultiSpline *multi;
  long lVar8;
  long lVar9;
  long lVar10;
  Spline *pSVar11;
  int iVar12;
  _Instance *Inst;
  uint burning;
  int iVar13;
  ushort uVar14;
  
  if ((gameTrackerX.debugFlags & 0x8000010U) == 0) {
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
      gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xfffffffb;
    }
    Inst = instanceList->first;
    while (Inst != (_Instance *)0x0) {
      gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
      if (((Inst->object != (Object *)0x0) && ((Inst->object->oflags2 & 0x2000000U) != 0)) &&
         (gameTrackerX.timeMult = gameTrackerX.materialTimeMult, (Inst->flags2 & 0x8000000U) != 0))
      {
        gameTrackerX.timeMult = gameTrackerX.spectralTimeMult;
      }
      burning = 0;
      if ((Inst->object->oflags2 & 4U) != 0) {
        uVar6 = Inst->flags;
        uVar7 = INSTANCE_Query(Inst,2);
        if ((uVar7 & 0x20) == 0) {
          if (((Inst->object->oflags2 & 0x80000U) != 0) &&
             ((*(uint *)Inst->extraData & 0x400000) != 0)) {
            burning = 1;
          }
        }
        else {
          uVar7 = INSTANCE_Query(Inst,3);
          burning = (uint)((uVar7 & 0x10000) != 0);
        }
        SOUND_ProcessInstanceSounds
                  (Inst->object->soundData,Inst->soundInstanceTbl,&Inst->position,
                   Inst->object->oflags2 & 0x2000000,Inst->flags2 & 0x8000000,uVar6 & 0x800,burning,
                   &Inst->flags2);
      }
      if ((((Inst->intro == (Intro *)0x0) || ((Inst->intro->flags & 0x100U) == 0)) &&
          ((gameTrackerX.gameMode != 6 || ((Inst->object->oflags & 0x20000U) != 0)))) &&
         ((((gameTrackerX.streamFlags & 0x100000U) == 0 || ((Inst->object->oflags & 0x40000U) != 0))
          && ((Inst->flags2 & 0x10000000U) == 0)))) {
        frameNum = (Inst->position).y;
        sVar1 = (Inst->position).z;
        sVar2 = (Inst->rotation).x;
        sVar3 = (Inst->rotation).y;
        burning = Inst->flags;
        sVar4 = (Inst->rotation).z;
        (Inst->oldPos).x = (Inst->position).x;
        (Inst->oldPos).y = frameNum;
        (Inst->oldPos).z = sVar1;
        (Inst->oldRotation).x = sVar2;
        (Inst->oldRotation).y = sVar3;
        (Inst->oldRotation).z = sVar4;
        if ((((burning & 0x100000) == 0) &&
            (multi = SCRIPT_GetMultiSpline(Inst,(ulong *)0x0,(ulong *)0x0),
            multi != (MultiSpline *)0x0)) && (burning = Inst->flags, (burning & 0x2000000) != 0)) {
          uVar14 = 1;
          if ((burning & 0x1000000) != 0) {
            uVar14 = 0xffff;
          }
          if ((Inst->object->oflags & 0x10000000U) != 0) {
            Inst->flags = burning | 0x400;
            frameNum = SplineMultiIsWhere(multi);
            if (frameNum != 0) {
              if ((int)((uint)uVar14 << 0x10) < 1) {
                Inst->intro->flags = Inst->intro->flags & 0xfffff7ff;
              }
              else {
                Inst->intro->flags = Inst->intro->flags | 0x800;
              }
            }
          }
          lVar8 = INSTANCE_GetSplineFrameNumber(Inst,multi);
          lVar9 = SCRIPT_InstanceSplineProcess
                            (Inst,&multi->curPositional,&multi->curRotational,&multi->curScaling,
                             (int)(short)uVar14);
          if (Inst->splineFlags == 0) {
            if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
              INSTANCE_GetSplineFrameNumber(Inst,multi);
              FONT_Print("Spline %s%d prevFrame=%d, frame=%d\n");
            }
          }
          else {
            lVar10 = INSTANCE_GetSplineFrameNumber(Inst,multi);
            frameNum = SCRIPTCountFramesInSpline(Inst);
            iVar13 = (int)frameNum;
            if ((Inst->splineFlags & 1U) != 0) {
              if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
                printf(
                      "Spline %s%ld playto %d preveFram=%ld frame=%ld endOfSpline=%ld, maxFrames=%ld\n"
                      );
              }
              if ((int)(short)uVar14 < 1) {
                iVar12 = (int)Inst->targetFrame;
                if (lVar10 <= iVar12) {
                  if (iVar12 <= lVar8) goto LAB_80033a78;
                  if (lVar8 < lVar10) {
                    bVar5 = lVar8 + iVar13 < iVar12;
                    goto LAB_80033a70;
                  }
                }
              }
              else {
                if (iVar13 < lVar8) {
                  lVar8 = iVar13;
                }
                iVar12 = (int)Inst->targetFrame;
                if ((lVar10 < iVar12) || (iVar12 < lVar8)) {
                  if ((lVar10 < lVar8) && (lVar10 >= iVar12)) {
                    bVar5 = iVar12 + iVar13 < lVar8;
LAB_80033a70:
                    if (!bVar5) goto LAB_80033a78;
                  }
                }
                else {
LAB_80033a78:
                  Inst->flags = Inst->flags & 0xfdffffff;
                  SCRIPT_InstanceSplineSet
                            (Inst,Inst->targetFrame,(SplineDef *)0x0,(SplineDef *)0x0,
                             (SplineDef *)0x0);
                  lVar9 = 0;
                  Inst->splineFlags = Inst->splineFlags & 0xfffe;
                }
              }
            }
            if ((Inst->splineFlags & 2U) != 0) {
              if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
                FONT_Print("Spline %s%d : clip(%d,%d) prevFrame=%d, frame=%d\n");
              }
              if (uVar14 == 1) {
                if (((lVar8 <= Inst->clipEnd) && (Inst->clipEnd <= lVar10)) ||
                   (lVar10 < Inst->clipBeg)) {
                  if ((*(uint *)&multi->positional->numkeys & 0x6000000) == 0) {
                    frameNum = Inst->clipEnd;
LAB_80033be0:
                    lVar9 = 1;
                  }
                  else {
                    frameNum = Inst->clipBeg;
                  }
LAB_80033be4:
                  SCRIPT_InstanceSplineSet
                            (Inst,frameNum,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
                }
              }
              else {
                if (((Inst->clipBeg <= lVar8) && (lVar10 <= Inst->clipBeg)) ||
                   (Inst->clipEnd < lVar10)) {
                  if ((*(uint *)&multi->positional->numkeys & 0x6000000) == 0) {
                    frameNum = Inst->clipBeg;
                    goto LAB_80033be0;
                  }
                  frameNum = Inst->clipEnd;
                  goto LAB_80033be4;
                }
              }
            }
          }
          if (0 < lVar9) {
            if ((Inst->object->oflags & 0x10000000U) != 0) {
              Inst->flags = Inst->flags & 0xfdfffbffU | 0x100000;
            }
            burning = Inst->object->oflags;
            if ((burning & 0x2000) != 0) {
              Inst->flags = Inst->flags | 0x100000;
              INSTANCE_KillInstance(Inst);
              goto LAB_80033e48;
            }
            if ((burning & 0x1000) == 0) {
              if ((burning & 0x1000000) != 0) {
                Inst->flags = Inst->flags & 0xfdffffff;
              }
            }
            else {
              Inst->flags = Inst->flags & 0xfdffffff;
              if ((Inst->object->oflags & 0x800000U) != 0) {
                SCRIPT_InstanceSplineInit(Inst);
              }
            }
            pSVar11 = multi->positional;
            if (((pSVar11 != (Spline *)0x0) ||
                (pSVar11 = (Spline *)multi->rotational, pSVar11 != (Spline *)0x0)) &&
               (((pSVar11->flags & 4) == 0 && ((Inst->object->oflags & 0x800000U) == 0)))) {
              Inst->flags = Inst->flags ^ 0x1000000;
            }
            if ((((Inst->object->oflags & 0x200000U) != 0) && ((int *)Inst->introData != (int *)0x0)
                ) && (iVar13 = *(int *)Inst->introData, iVar13 != 0)) {
              SIGNAL_HandleSignal(Inst,(Signal *)(iVar13 + 8),0);
            }
          }
        }
        if (Inst->processFunc != (_func_1 *)0x0) {
          if ((Inst->flags2 & 1U) == 0) {
            (*Inst->processFunc)(Inst,&gameTrackerX);
          }
          else {
            INSTANCE_DeactivatedProcess(Inst,&gameTrackerX);
          }
        }
        iVar13 = (int)(Inst->position).z - (int)(Inst->oldPos).z;
        if (0x8000 < iVar13) {
          INSTANCE_PlainDeath(Inst);
        }
        if (iVar13 < -0x8000) {
          INSTANCE_PlainDeath(Inst);
        }
        uVar7 = INSTANCE_Query(Inst,0x2f);
        if (uVar7 != 0) {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags | 4;
        }
      }
LAB_80033e48:
      Inst = Inst->next;
    }
  }
  if (gameTrackerX.gameData.asmData.MorphTime != 1000) {
    gameTrackerX.streamFlags = gameTrackerX.streamFlags | 4;
  }
  gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_BirthObject(struct _Instance *parent /*$s2*/, struct Object *object /*$s4*/, int modelNum /*$s1*/)
 // line 1508, offset 0x80033eb0
	/* begin block 1 */
		// Start line: 1509
		// Start offset: 0x80033EB0
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x80034100
	// End Line: 1580

	/* begin block 2 */
		// Start line: 3535
	/* end block 2 */
	// End Line: 3536

_Instance * INSTANCE_BirthObject(_Instance *parent,Object *object,int modelNum)

{
  short sVar1;
  _GlobalSaveTracker *p_Var2;
  _Instance *instance;
  size_t sVar3;
  MultiSpline *pMVar4;
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
    p_Var2 = GlobalSave;
    instance->currentStreamUnitID = parent->currentStreamUnitID;
    instance->birthStreamUnitID = parent->birthStreamUnitID;
    sVar1 = p_Var2->CurrentBirthID;
    iVar7 = 0;
    p_Var2->CurrentBirthID = sVar1 + 1;
    instance->introUniqueID = (int)sVar1;
    strcpy(instance->introName,object->name);
    do {
      sVar3 = strlen(instance->introName);
      iVar5 = (int)&(instance->node).prev + iVar7;
      if ((int)sVar3 <= iVar7) goto LAB_80034008;
      iVar7 = iVar7 + 1;
    } while (*(char *)(iVar5 + 0x15c) != '_');
    *(undefined *)(iVar5 + 0x15c) = 0;
LAB_80034008:
    instance->parent = parent;
    instance->intro = parent->intro;
    instance->introData = parent->introData;
    LIGHT_GetAmbient((_ColorType *)&instance->light_color,instance);
    if ((instance->object->oflags & 0x100U) != 0) {
      INSTANCE_BuildStaticShadow(instance);
    }
    pMVar4 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
    if (pMVar4 == (MultiSpline *)0x0) {
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
 // line 1597, offset 0x80034120
	/* begin block 1 */
		// Start line: 3194
	/* end block 1 */
	// End Line: 3195

	/* begin block 2 */
		// Start line: 3719
	/* end block 2 */
	// End Line: 3720

void INSTANCE_BuildStaticShadow(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_DefaultInit(struct _Instance *instance /*$s1*/, struct Object *object /*$s2*/, int modelNum /*$s0*/)
 // line 1631, offset 0x80034128
	/* begin block 1 */
		// Start line: 1632
		// Start offset: 0x80034128
		// Variables:
	// 		int i; // $t3
	// 		int j; // $a3
	// 		int numHPrims; // $a2
	// 		int numModels; // $s0
	// 		struct _HPrim *hprim; // $a2
	// 		struct _Model **pModel; // $t7
	// 		struct _HModel *hmodel; // $t8

		/* begin block 1.1 */
			// Start line: 1685
			// Start offset: 0x800342B0
			// Variables:
		// 		struct _Model *model; // $v0
		// 		struct _Segment *seg; // $a1

			/* begin block 1.1.1 */
				// Start line: 1690
				// Start offset: 0x800342C8
				// Variables:
			// 		struct _HInfo *hinfo; // $a0
			/* end block 1.1.1 */
			// End offset: 0x800342F0
			// End Line: 1694
		/* end block 1.1 */
		// End offset: 0x800342FC
		// End Line: 1695

		/* begin block 1.2 */
			// Start line: 1704
			// Start offset: 0x80034358
			// Variables:
		// 		struct _Model *model; // $s0
		// 		struct _Segment *seg; // $t4

			/* begin block 1.2.1 */
				// Start line: 1715
				// Start offset: 0x80034374
				// Variables:
			// 		struct _HInfo *hinfo; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 1719
					// Start offset: 0x80034384
					// Variables:
				// 		int k; // $v1
				// 		struct _HFace *hface; // $t0
				// 		struct _HSphere *hsphere; // $t1
				// 		struct _HBox *hbox; // $t2
				/* end block 1.2.1.1 */
				// End offset: 0x8003446C
				// End Line: 1758
			/* end block 1.2.1 */
			// End offset: 0x8003446C
			// End Line: 1759
		/* end block 1.2 */
		// End offset: 0x80034484
		// End Line: 1760
	/* end block 1 */
	// End offset: 0x800344C8
	// End Line: 1772

	/* begin block 2 */
		// Start line: 3778
	/* end block 2 */
	// End Line: 3779

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
  
  memset(&instance->flags,0,0x288);
  instance->object = object;
  pvVar1 = object->data;
  instance->currentModel = (short)modelNum;
  instance->cachedTFace = -1;
  instance->cachedTFaceLevel = (void *)0x0;
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
 // line 1775, offset 0x800344e4
	/* begin block 1 */
		// Start line: 1776
		// Start offset: 0x800344E4

		/* begin block 1.1 */
			// Start line: 1807
			// Start offset: 0x800345B0
			// Variables:
		// 		struct _Instance *oldOn; // $a0
		/* end block 1.1 */
		// End offset: 0x800345D8
		// End Line: 1814
	/* end block 1 */
	// End offset: 0x800345D8
	// End Line: 1816

	/* begin block 2 */
		// Start line: 4225
	/* end block 2 */
	// End Line: 4226

void INSTANCE_PlainDeath(_Instance *instance)

{
  uint uVar1;
  _Instance *p_Var2;
  Object *pOVar3;
  
  pOVar3 = instance->object;
  instance->flags = instance->flags & 0xfffffbff;
  if ((pOVar3->oflags2 & 4U) != 0) {
    uVar1 = instance->flags2;
    instance->flags2 = uVar1 | 0x1000;
    SOUND_ProcessInstanceSounds
              (pOVar3->soundData,instance->soundInstanceTbl,&instance->position,
               pOVar3->oflags2 & 0x2000000,uVar1 & 0x8000000,0,0,&instance->flags2);
    SOUND_ProcessInstanceSounds
              (instance->object->soundData,instance->soundInstanceTbl,&instance->position,
               instance->object->oflags2 & 0x2000000,instance->flags2 & 0x8000000,0,0,
               &instance->flags2);
  }
  p_Var2 = INSTANCE_Find(instance->attachedID);
  if (p_Var2 != (_Instance *)0x0) {
    p_Var2->flags2 = p_Var2->flags2 & 0xffffff7f;
  }
  SAVE_MarkDeadDead(instance);
  instance->flags = instance->flags | 0x20;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_KillInstance(struct _Instance *instance /*$a0*/)
 // line 1820, offset 0x80034614
	/* begin block 1 */
		// Start line: 4322
	/* end block 1 */
	// End Line: 4323

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
 // line 1839, offset 0x80034648
	/* begin block 1 */
		// Start line: 1840
		// Start offset: 0x80034648
		// Variables:
	// 		unsigned long (*Func)(); // $v0
	/* end block 1 */
	// End offset: 0x80034674
	// End Line: 1853

	/* begin block 2 */
		// Start line: 3678
	/* end block 2 */
	// End Line: 3679

ulong INSTANCE_Query(_Instance *Inst,int Query)

{
  ulong uVar1;
  
  if (Inst->queryFunc == (_func_4 *)0x0) {
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
 // line 1857, offset 0x80034684
	/* begin block 1 */
		// Start line: 1858
		// Start offset: 0x80034684
		// Variables:
	// 		void (*Func)(); // $s1
	/* end block 1 */
	// End offset: 0x800346CC
	// End Line: 1868

	/* begin block 2 */
		// Start line: 4388
	/* end block 2 */
	// End Line: 4389

void INSTANCE_Post(_Instance *Inst,int Message,int Data)

{
  _func_5 *p_Var1;
  
  p_Var1 = Inst->messageFunc;
  if (p_Var1 != (_func_5 *)0x0) {
    INSTANCE_ForceActive(Inst);
    (*p_Var1)(Inst,Message,Data);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_Broadcast(struct _Instance *sender /*$s2*/, long whatAmIMask /*$s3*/, int Message /*$s4*/, int Data /*$s5*/)
 // line 1874, offset 0x800346e8
	/* begin block 1 */
		// Start line: 1875
		// Start offset: 0x800346E8
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int plane; // $s1
	/* end block 1 */
	// End offset: 0x80034770
	// End Line: 1888

	/* begin block 2 */
		// Start line: 4426
	/* end block 2 */
	// End Line: 4427

	/* begin block 3 */
		// Start line: 4430
	/* end block 3 */
	// End Line: 4431

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
 // line 1893, offset 0x80034794
	/* begin block 1 */
		// Start line: 4476
	/* end block 1 */
	// End Line: 4477

	/* begin block 2 */
		// Start line: 4477
	/* end block 2 */
	// End Line: 4478

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
// long /*$ra*/ INSTANCE_FindWithID(long uniqueID /*$a0*/)
 // line 1920, offset 0x800347f0
	/* begin block 1 */
		// Start line: 1922
		// Start offset: 0x800347F0
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $a1
	/* end block 1 */
	// End offset: 0x80034828
	// End Line: 1938

	/* begin block 2 */
		// Start line: 3840
	/* end block 2 */
	// End Line: 3841

	/* begin block 3 */
		// Start line: 4505
	/* end block 3 */
	// End Line: 4506

long INSTANCE_FindWithID(long uniqueID)

{
  long *plVar1;
  _Instance *p_Var2;
  
  p_Var2 = (gameTrackerX.instanceList)->first;
  do {
    if (p_Var2 == (_Instance *)0x0) {
      return 0;
    }
    plVar1 = &p_Var2->introUniqueID;
    p_Var2 = p_Var2->next;
  } while (*plVar1 != uniqueID);
  return 1;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_FindWithName(long areaID /*$s3*/, char *instanceName /*$s4*/, struct _Instance *startInstance /*$a2*/)
 // line 1977, offset 0x80034830
	/* begin block 1 */
		// Start line: 1978
		// Start offset: 0x80034830
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *ret; // $s2
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x800348E0
	// End Line: 2021

	/* begin block 2 */
		// Start line: 3954
	/* end block 2 */
	// End Line: 3955

	/* begin block 3 */
		// Start line: 4582
	/* end block 3 */
	// End Line: 4583

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
 // line 2047, offset 0x80034904
	/* begin block 1 */
		// Start line: 2048
		// Start offset: 0x80034904
		// Variables:
	// 		struct Intro *ret; // $s0
	// 		long i; // $a0
	// 		struct Level *level; // $v1
	/* end block 1 */
	// End offset: 0x80034970
	// End Line: 2068

	/* begin block 2 */
		// Start line: 4094
	/* end block 2 */
	// End Line: 4095

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
 // line 2072, offset 0x80034988
	/* begin block 1 */
		// Start line: 2074
		// Start offset: 0x80034988
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x800349C0
	// End Line: 2080

	/* begin block 2 */
		// Start line: 4768
	/* end block 2 */
	// End Line: 4769

	/* begin block 3 */
		// Start line: 4769
	/* end block 3 */
	// End Line: 4770

	/* begin block 4 */
		// Start line: 4771
	/* end block 4 */
	// End Line: 4772

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
// struct _Instance * /*$ra*/ INSTANCE_IntroduceSavedInstance(struct _SavedIntro *savedIntro /*$s2*/, struct _StreamUnit *streamUnit /*$a1*/, int *deleted /*$fp*/)
 // line 2084, offset 0x800349c8
	/* begin block 1 */
		// Start line: 2085
		// Start offset: 0x800349C8
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s1
	// 		struct Object *object; // $s7
	// 		struct _Instance *instance; // $s0
	// 		struct _Position *levelOffset; // $s5
	// 		struct Level *level; // $v0
	// 		struct _Instance *attachInst; // $s4

		/* begin block 1.1 */
			// Start line: 2101
			// Start offset: 0x80034A24
			// Variables:
		// 		char savedName[12]; // stack offset -56

			/* begin block 1.1.1 */
				// Start line: 2127
				// Start offset: 0x80034AE0
				// Variables:
			// 		struct Level *birthLevel; // $v0
			// 		struct Intro *oldIntro; // $s1
			// 		int nosave; // $s3
			// 		int remove; // $s1

				/* begin block 1.1.1.1 */
					// Start line: 2153
					// Start offset: 0x80034B40
					// Variables:
				// 		struct Intro *intro; // $v1
				// 		int i; // $a0
				/* end block 1.1.1.1 */
				// End offset: 0x80034B74
				// End Line: 2164

				/* begin block 1.1.1.2 */
					// Start line: 2181
					// Start offset: 0x80034B9C
					// Variables:
				// 		short _x0; // $v0
				// 		short _y0; // $a0
				// 		short _z0; // $v1
				// 		short _x1; // $a1
				// 		short _y1; // $a2
				// 		short _z1; // $a3
				// 		struct _Position *_v; // $v0
				// 		struct _Position *_v0; // $v1
				/* end block 1.1.1.2 */
				// End offset: 0x80034B9C
				// End Line: 2181

				/* begin block 1.1.1.3 */
					// Start line: 2263
					// Start offset: 0x80034D84
				/* end block 1.1.1.3 */
				// End offset: 0x80034DA0
				// End Line: 2274
			/* end block 1.1.1 */
			// End offset: 0x80034DD4
			// End Line: 2283
		/* end block 1.1 */
		// End offset: 0x80034E00
		// End Line: 2295
	/* end block 1 */
	// End offset: 0x80034E00
	// End Line: 2304

	/* begin block 2 */
		// Start line: 4793
	/* end block 2 */
	// End Line: 4794

_Instance *
INSTANCE_IntroduceSavedInstance(_SavedIntro *savedIntro,_StreamUnit *streamUnit,int *deleted)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  BSPTree *pBVar5;
  long lVar6;
  _ObjectTracker *objectTracker;
  _Instance *instance;
  Level *pLVar7;
  uint uVar8;
  Intro *pIVar9;
  Object *pOVar10;
  int Data;
  uint uVar11;
  uint uVar12;
  Intro *pIVar13;
  Intro *pIVar14;
  _Instance *instance_00;
  Object *object;
  undefined4 local_38;
  undefined4 local_34;
  undefined local_30;
  
  instance_00 = (_Instance *)0x0;
  pBVar5 = streamUnit->level->terrain->BSPTreeArray;
  lVar6 = INSTANCE_FindWithID((int)savedIntro->introUniqueID);
  instance = (_Instance *)0x0;
  if (lVar6 == 0) {
    local_38 = *(undefined4 *)savedIntro->name;
    local_34 = *(undefined4 *)(savedIntro->name + 4);
    local_30 = 0;
    LOAD_SetSearchDirectory((int)savedIntro->birthUnitID);
    objectTracker = STREAM_GetObjectTracker((char *)&local_38);
    LOAD_SetSearchDirectory(0);
    instance = (_Instance *)0x0;
    if (objectTracker != (_ObjectTracker *)0x0) {
      object = objectTracker->object;
      if ((objectTracker->objectStatus == 2) &&
         ((savedIntro->attachedUniqueID == 0 ||
          (instance_00 = INSTANCE_Find((uint)savedIntro->attachedUniqueID),
          instance_00 != (_Instance *)0x0)))) {
        if (((object->oflags2 & 0x10000000U) != 0) &&
           (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) != 0)) {
          return (_Instance *)0x0;
        }
        instance = INSTANCE_NewInstance(gameTrackerX.instanceList);
        if (instance != (_Instance *)0x0) {
          objectTracker->numInUse = objectTracker->numInUse + 1;
          INSTANCE_DefaultInit(instance,object,0);
          strcpy(instance->introName,(char *)&local_38);
          instance->introUniqueID = (int)savedIntro->introUniqueID;
          instance->currentStreamUnitID = (int)savedIntro->streamUnitID;
          instance->birthStreamUnitID = (int)savedIntro->birthUnitID;
          LIGHT_GetAmbient((_ColorType *)&instance->light_color,instance);
          pIVar13 = (Intro *)0x0;
          pLVar7 = STREAM_GetLevelWithID(instance->birthStreamUnitID);
          pIVar14 = pIVar13;
          if (pLVar7 != (Level *)0x0) {
            Data = pLVar7->terrain->numIntros;
            pIVar9 = pLVar7->terrain->introList;
            if (Data != 0) {
              do {
                Data = Data + -1;
                pIVar14 = pIVar9;
                if (pIVar9->UniqueID == instance->introUniqueID) break;
                pIVar9 = pIVar9 + 1;
                pIVar14 = pIVar13;
              } while (Data != 0);
            }
          }
          if (pIVar14 == (Intro *)0x0) {
            instance->intro = (Intro *)0x0;
            instance->introData = (void *)0x0;
          }
          else {
            instance->intro = pIVar14;
            instance->introData = pIVar14->data;
          }
          sVar1 = (savedIntro->position).y;
          sVar2 = (savedIntro->position).z;
          sVar3 = (pBVar5->globalOffset).y;
          sVar4 = (pBVar5->globalOffset).z;
          (instance->position).x = (savedIntro->position).x + (pBVar5->globalOffset).x;
          (instance->position).y = sVar1 + sVar3;
          (instance->position).z = sVar2 + sVar4;
          sVar1 = (instance->position).z;
          *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
          (instance->initialPos).z = sVar1;
          sVar1 = (instance->position).z;
          *(undefined4 *)&instance->oldPos = *(undefined4 *)&instance->position;
          (instance->oldPos).z = sVar1;
          pOVar10 = instance->object;
          (instance->rotation).x = (savedIntro->smallRotation).x;
          (instance->rotation).y = (savedIntro->smallRotation).y;
          (instance->rotation).z = (savedIntro->smallRotation).z;
          if ((pOVar10->oflags & 0x100U) != 0) {
            INSTANCE_BuildStaticShadow(instance);
          }
          (instance->scale).x = 0x1000;
          (instance->scale).y = 0x1000;
          (instance->scale).z = 0x1000;
          instance->lightGroup = savedIntro->lightGroup;
          instance->spectralLightGroup = savedIntro->specturalLightGroup;
          INSTANCE_InsertInstanceGroup(gameTrackerX.instanceList,instance);
          OBTABLE_GetInstanceCollideFunc(instance);
          OBTABLE_GetInstanceProcessFunc(instance);
          OBTABLE_GetInstanceQueryFunc(instance);
          OBTABLE_GetInstanceMessageFunc(instance);
          OBTABLE_GetInstanceAdditionalCollideFunc(instance);
          OBTABLE_InstanceInit(instance);
          uVar12 = instance->flags;
          uVar11 = instance->flags2;
          instance->flags = savedIntro->flags;
          instance->flags2 = savedIntro->flags2 & 0xfffffffe;
          if (instance_00 != (_Instance *)0x0) {
            INSTANCE_ForceActive(instance_00);
            instance_00->flags2 = instance_00->flags2 | 0x80;
          }
          if ((instance->flags & 0x40000U) == 0) {
            uVar8 = instance->flags2 & 0xdfffffff;
          }
          else {
            uVar8 = instance->flags2 | 0x20000000;
          }
          instance->flags2 = uVar8;
          instance->flags = instance->flags & 0xfdfbffffU | 0x100000;
          MORPH_SetupInstanceFlags(instance);
          if (instance->intro != (Intro *)0x0) {
            INSTANCE_ProcessIntro(instance);
          }
          uVar8 = (uint)savedIntro->shiftedSaveSize * 4;
          if (0x28 < uVar8) {
            Data = SetControlSaveDataData(uVar8 - 0x28,savedIntro + 1);
            INSTANCE_Post(instance,(int)&DAT_00100007,Data);
          }
          EVENT_AddInstanceToInstanceList(instance);
          INSTANCE_InitEffects(instance,object);
          if ((uVar12 & 0x20) != 0) {
            instance->flags = instance->flags | 0x20;
          }
          if ((uVar11 & 0x20000) != 0) {
            instance->flags2 = instance->flags2 | 0x20000;
            SAVE_DeleteInstance(instance);
            *deleted = 1;
          }
        }
      }
      else {
        SAVE_BufferIntro((SavedBasic *)savedIntro);
      }
    }
  }
  return instance;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_IntroduceSavedInstanceWithIntro(struct _SavedIntroWithIntro *savedIntro /*$s4*/, struct _StreamUnit *streamUnit /*$s6*/, int *deleted /*stack 8*/)
 // line 2307, offset 0x80034e34
	/* begin block 1 */
		// Start line: 2308
		// Start offset: 0x80034E34
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s1
	// 		struct Object *object; // $s7
	// 		struct _Instance *instance; // $s0
	// 		struct _Position *levelOffset; // $fp
	// 		struct Level *level; // $v1
	// 		struct Intro *intro; // $s2
	// 		struct _Instance *attachedInst; // $s5

		/* begin block 1.1 */
			// Start line: 2352
			// Start offset: 0x80034F6C
			// Variables:
		// 		int remove; // $s1
		// 		int nosave; // $s2

			/* begin block 1.1.1 */
				// Start line: 2356
				// Start offset: 0x80034F6C
				// Variables:
			// 		short _x0; // $v0
			// 		short _y0; // $a0
			// 		short _z0; // $v1
			// 		short _x1; // $a1
			// 		short _y1; // $a2
			// 		short _z1; // $a3
			// 		struct _Position *_v; // $v0
			// 		struct _Position *_v0; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80034F6C
			// End Line: 2356

			/* begin block 1.1.2 */
				// Start line: 2493
				// Start offset: 0x800351F4
			/* end block 1.1.2 */
			// End offset: 0x80035210
			// End Line: 2504
		/* end block 1.1 */
		// End offset: 0x80035244
		// End Line: 2513
	/* end block 1 */
	// End offset: 0x80035274
	// End Line: 2529

	/* begin block 2 */
		// Start line: 5333
	/* end block 2 */
	// End Line: 5334

_Instance *
INSTANCE_IntroduceSavedInstanceWithIntro
          (_SavedIntroWithIntro *savedIntro,_StreamUnit *streamUnit,int *deleted)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  long lVar5;
  _ObjectTracker *objectTracker;
  _Instance *instance;
  MultiSpline *pMVar6;
  int Data;
  BSPTree *pBVar7;
  Object *pOVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  Intro *name;
  _Instance *instance_00;
  Object *object;
  
  instance_00 = (_Instance *)0x0;
  pBVar7 = streamUnit->level->terrain->BSPTreeArray;
  name = streamUnit->level->introList + savedIntro->introOffset;
  lVar5 = INSTANCE_FindWithID(name->UniqueID);
  instance = (_Instance *)0x0;
  if (lVar5 == 0) {
    LOAD_SetSearchDirectory(streamUnit->StreamUnitID);
    objectTracker = STREAM_GetObjectTracker((char *)name);
    LOAD_SetSearchDirectory(0);
    instance = (_Instance *)0x0;
    if (objectTracker != (_ObjectTracker *)0x0) {
      object = objectTracker->object;
      if ((objectTracker->objectStatus == 2) &&
         ((savedIntro->attachedUniqueID == 0 ||
          ((instance_00 = INSTANCE_Find((uint)savedIntro->attachedUniqueID),
           instance_00 != (_Instance *)0x0 && (instance_00->matrix != (MATRIX *)0x0)))))) {
        if (((object->oflags2 & 0x10000000U) != 0) &&
           (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) != 0)) {
          return (_Instance *)0x0;
        }
        instance = INSTANCE_NewInstance(gameTrackerX.instanceList);
        if (instance != (_Instance *)0x0) {
          objectTracker->numInUse = objectTracker->numInUse + 1;
          INSTANCE_DefaultInit(instance,object,0);
          strcpy(instance->introName,(char *)name);
          instance->introUniqueID = name->UniqueID;
          instance->introNum = name->intronum;
          instance->birthStreamUnitID = streamUnit->StreamUnitID;
          instance->currentStreamUnitID = streamUnit->StreamUnitID;
          instance->attachedID = (uint)savedIntro->attachedUniqueID;
          LIGHT_GetAmbient((_ColorType *)&instance->light_color,instance);
          name->instance = instance;
          STREAM_GetLevelWithID(instance->birthStreamUnitID);
          instance->intro = name;
          instance->introData = name->data;
          sVar1 = (savedIntro->position).y;
          sVar2 = (savedIntro->position).z;
          sVar3 = (pBVar7->globalOffset).y;
          sVar4 = (pBVar7->globalOffset).z;
          (instance->position).x = (savedIntro->position).x + (pBVar7->globalOffset).x;
          (instance->position).y = sVar1 + sVar3;
          (instance->position).z = sVar2 + sVar4;
          sVar1 = (instance->position).z;
          *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
          (instance->initialPos).z = sVar1;
          sVar1 = (instance->position).z;
          *(undefined4 *)&instance->oldPos = *(undefined4 *)&instance->position;
          (instance->oldPos).z = sVar1;
          pOVar8 = instance->object;
          (instance->rotation).x = (savedIntro->smallRotation).x;
          (instance->rotation).y = (savedIntro->smallRotation).y;
          (instance->rotation).z = (savedIntro->smallRotation).z;
          if ((pOVar8->oflags & 0x100U) != 0) {
            INSTANCE_BuildStaticShadow(instance);
          }
          (instance->scale).x = 0x1000;
          (instance->scale).y = 0x1000;
          (instance->scale).z = 0x1000;
          instance->lightGroup = savedIntro->lightGroup;
          instance->spectralLightGroup = savedIntro->specturalLightGroup;
          INSTANCE_InsertInstanceGroup(gameTrackerX.instanceList,instance);
          OBTABLE_GetInstanceCollideFunc(instance);
          OBTABLE_GetInstanceProcessFunc(instance);
          OBTABLE_GetInstanceQueryFunc(instance);
          OBTABLE_GetInstanceMessageFunc(instance);
          OBTABLE_GetInstanceAdditionalCollideFunc(instance);
          OBTABLE_InstanceInit(instance);
          uVar11 = instance->flags;
          uVar9 = instance->flags2;
          instance->flags = savedIntro->flags;
          instance->flags2 = savedIntro->flags2;
          if (instance_00 != (_Instance *)0x0) {
            INSTANCE_ForceActive(instance_00);
            instance_00->flags2 = instance_00->flags2 | 0x80;
          }
          uVar10 = instance->flags2;
          uVar12 = uVar10 & 0xfffffffe;
          instance->flags2 = uVar12;
          if ((instance->flags & 0x40000U) == 0) {
            uVar12 = uVar10 & 0xdffffffe;
          }
          else {
            uVar12 = uVar12 | 0x20000000;
          }
          instance->flags2 = uVar12;
          instance->flags = instance->flags & 0xfffbffff;
          pMVar6 = SCRIPT_GetMultiSpline(instance,(ulong *)0x0,(ulong *)0x0);
          if (pMVar6 == (MultiSpline *)0x0) {
            instance->flags = instance->flags & 0xfdffffffU | 0x100000;
          }
          MORPH_SetupInstanceFlags(instance);
          if (instance->intro != (Intro *)0x0) {
            INSTANCE_ProcessIntro(instance);
          }
          uVar12 = (uint)savedIntro->shiftedSaveSize * 4;
          if (0x20 < uVar12) {
            Data = SetControlSaveDataData(uVar12 - 0x20,savedIntro + 1);
            INSTANCE_Post(instance,(int)&DAT_00100007,Data);
          }
          EVENT_AddInstanceToInstanceList(instance);
          INSTANCE_InitEffects(instance,object);
          if ((uVar11 & 0x20) != 0) {
            instance->flags = instance->flags | 0x20;
          }
          if ((uVar9 & 0x20000) != 0) {
            instance->flags2 = instance->flags2 | 0x20000;
            SAVE_DeleteInstance(instance);
            *deleted = 1;
          }
        }
      }
      else {
        SAVE_BufferIntro((SavedBasic *)savedIntro);
      }
    }
  }
  return instance;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_SpatialRelationships(struct _InstanceList *instanceList /*$s4*/)
 // line 2576, offset 0x800352a8
	/* begin block 1 */
		// Start line: 2577
		// Start offset: 0x800352A8
		// Variables:
	// 		struct _Instance *instance; // $s1
	// 		struct _Instance *checkee; // $s0

		/* begin block 1.1 */
			// Start line: 2586
			// Start offset: 0x800352F4
			// Variables:
		// 		struct MATRIX *lookMatrix; // $s0
		// 		long checkMask; // $s3

			/* begin block 1.1.1 */
				// Start line: 2595
				// Start offset: 0x8003531C
				// Variables:
			// 		struct MATRIX invMatrix; // stack offset -80

				/* begin block 1.1.1.1 */
					// Start line: 2604
					// Start offset: 0x80035378
					// Variables:
				// 		struct evCollideInstanceStatsData data; // stack offset -48
				// 		struct MATRIX *mat; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x800353CC
				// End Line: 2614
			/* end block 1.1.1 */
			// End offset: 0x800353DC
			// End Line: 2616
		/* end block 1.1 */
		// End offset: 0x800353DC
		// End Line: 2617
	/* end block 1 */
	// End offset: 0x800353EC
	// End Line: 2619

	/* begin block 2 */
		// Start line: 5152
	/* end block 2 */
	// End Line: 5153

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
 // line 2623, offset 0x8003540c
	/* begin block 1 */
		// Start line: 2624
		// Start offset: 0x8003540C
		// Variables:
	// 		long distance; // $s4

		/* begin block 1.1 */
			// Start line: 2629
			// Start offset: 0x80035478
			// Variables:
		// 		struct SVECTOR *delta; // $s0
		/* end block 1.1 */
		// End offset: 0x80035480
		// End Line: 2646
	/* end block 1 */
	// End offset: 0x800354F8
	// End Line: 2648

	/* begin block 2 */
		// Start line: 6050
	/* end block 2 */
	// End Line: 6051

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
    DAT_1f800000._0_2_ = *(short *)&checkPoint->x - (instance->position).x;
    DAT_1f800000._2_2_ = *(short *)&checkPoint->y - (instance->position).y;
    DAT_1f800004._0_2_ = *(short *)&checkPoint->z - (instance->position).z;
    ApplyMatrixSV(mat,0x1f800000,&data->relativePosition);
    data->instance = checkee;
    data->distance = uVar2;
    data->zDelta = (int)(short)DAT_1f800004;
    lVar3 = MATH3D_LengthXY((int)(short)DAT_1f800000,(int)DAT_1f800000._2_2_);
    data->xyDistance = lVar3;
  }
  return (uint)bVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_LinkToParent(struct _Instance *instance /*$s0*/, struct _Instance *parent /*$s1*/, int node /*$a2*/)
 // line 2652, offset 0x8003551c
	/* begin block 1 */
		// Start line: 6133
	/* end block 1 */
	// End Line: 6134

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
  INSTANCE_Post(parent,(int)&DAT_00100012,(int)instance);
  instance->flags2 = instance->flags2 | 8;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_UnlinkFromParent(struct _Instance *instance /*$s0*/)
 // line 2673, offset 0x800355d8
	/* begin block 1 */
		// Start line: 2674
		// Start offset: 0x800355D8
		// Variables:
	// 		struct _Instance *parent; // $s1

		/* begin block 1.1 */
			// Start line: 2678
			// Start offset: 0x800355FC
			// Variables:
		// 		struct _G2EulerAngles_Type ea; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 2686
				// Start offset: 0x80035618
				// Variables:
			// 		struct _Instance *sibling; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8003564C
			// End Line: 2692
		/* end block 1.1 */
		// End offset: 0x80035728
		// End Line: 2712
	/* end block 1 */
	// End offset: 0x80035728
	// End Line: 2713

	/* begin block 2 */
		// Start line: 6181
	/* end block 2 */
	// End Line: 6182

void INSTANCE_UnlinkFromParent(_Instance *instance)

{
  short sVar1;
  _Instance *p_Var2;
  _Instance *p_Var3;
  _Instance *Inst;
  int iVar4;
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
    iVar4 = (int)sVar1 * (int)(Inst->scale).x;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    (instance->scale).x = (short)(iVar4 >> 0xc);
    iVar4 = (int)(instance->scale).y * (int)(Inst->scale).y;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    (instance->scale).y = (short)(iVar4 >> 0xc);
    iVar4 = (int)(instance->scale).z * (int)(Inst->scale).z;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    (instance->scale).z = (short)(iVar4 >> 0xc);
    if (Inst->matrix != (MATRIX *)0x0) {
      G2EulerAngles_FromMatrix
                (&local_18,(_G2Matrix_Type *)(Inst->matrix + instance->ParentLinkNode),0x15);
      (instance->rotation).x = local_18.x;
      (instance->rotation).y = local_18.y;
      (instance->rotation).z = local_18.z;
    }
    INSTANCE_Post(Inst,(int)&DAT_00100013,(int)instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_UnlinkChildren(struct _Instance *instance /*$s2*/)
 // line 2715, offset 0x8003573c
	/* begin block 1 */
		// Start line: 2716
		// Start offset: 0x8003573C
		// Variables:
	// 		struct _Instance *child; // $s1

		/* begin block 1.1 */
			// Start line: 2721
			// Start offset: 0x80035764
			// Variables:
		// 		struct _Instance *sibling; // $s0
		/* end block 1.1 */
		// End offset: 0x80035764
		// End Line: 2721
	/* end block 1 */
	// End offset: 0x8003578C
	// End Line: 2732

	/* begin block 2 */
		// Start line: 6270
	/* end block 2 */
	// End Line: 6271

void INSTANCE_UnlinkChildren(_Instance *instance)

{
  _Instance *Data;
  _Instance *p_Var1;
  
  Data = instance->LinkChild;
  while (Data != (_Instance *)0x0) {
    p_Var1 = Data->LinkSibling;
    INSTANCE_Post(instance,(int)&DAT_00100013,(int)Data);
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
 // line 2738, offset 0x800357a8
	/* begin block 1 */
		// Start line: 2739
		// Start offset: 0x800357A8
		// Variables:
	// 		struct _Instance *child; // $s0
	/* end block 1 */
	// End offset: 0x800357EC
	// End Line: 2747

	/* begin block 2 */
		// Start line: 6319
	/* end block 2 */
	// End Line: 6320

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
// void /*$ra*/ INSTANCE_ReallyRemoveAllChildren(struct _Instance *instance /*$a0*/)
 // line 2749, offset 0x80035800
	/* begin block 1 */
		// Start line: 2750
		// Start offset: 0x80035800
		// Variables:
	// 		struct _Instance *child; // $s1

		/* begin block 1.1 */
			// Start line: 2755
			// Start offset: 0x80035820
			// Variables:
		// 		struct _Instance *sibling; // $s0
		/* end block 1.1 */
		// End offset: 0x80035820
		// End Line: 2755
	/* end block 1 */
	// End offset: 0x80035848
	// End Line: 2760

	/* begin block 2 */
		// Start line: 6344
	/* end block 2 */
	// End Line: 6345

void INSTANCE_ReallyRemoveAllChildren(_Instance *instance)

{
  _Instance *instance_00;
  _Instance *p_Var1;
  
  instance_00 = instance->LinkChild;
  while (instance_00 != (_Instance *)0x0) {
    p_Var1 = instance_00->LinkSibling;
    INSTANCE_ReallyRemoveAllChildren(instance_00);
    INSTANCE_ReallyRemoveInstance(gameTrackerX.instanceList,instance_00,0);
    instance_00 = p_Var1;
  }
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_GetChildLinkedToSegment(struct _Instance *instance /*$a0*/, int segment /*$a1*/)
 // line 2765, offset 0x8003585c
	/* begin block 1 */
		// Start line: 2767
		// Start offset: 0x8003585C
		// Variables:
	// 		struct _Instance *child; // $v1
	/* end block 1 */
	// End offset: 0x8003588C
	// End Line: 2775

	/* begin block 2 */
		// Start line: 6381
	/* end block 2 */
	// End Line: 6382

	/* begin block 3 */
		// Start line: 6382
	/* end block 3 */
	// End Line: 6383

	/* begin block 4 */
		// Start line: 6384
	/* end block 4 */
	// End Line: 6385

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
 // line 2781, offset 0x80035894
	/* begin block 1 */
		// Start line: 2783
		// Start offset: 0x80035894
		// Variables:
	// 		struct _Instance *root1; // $a0
	// 		struct _Instance *root2; // $a1
	/* end block 1 */
	// End offset: 0x800358DC
	// End Line: 2791

	/* begin block 2 */
		// Start line: 6415
	/* end block 2 */
	// End Line: 6416

	/* begin block 3 */
		// Start line: 6416
	/* end block 3 */
	// End Line: 6417

	/* begin block 4 */
		// Start line: 6418
	/* end block 4 */
	// End Line: 6419

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
 // line 2799, offset 0x800358e4
	/* begin block 1 */
		// Start line: 2800
		// Start offset: 0x800358E4
		// Variables:
	// 		int fadeValue; // $s0
	/* end block 1 */
	// End offset: 0x800359B0
	// End Line: 2824

	/* begin block 2 */
		// Start line: 6451
	/* end block 2 */
	// End Line: 6452

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
      sVar1 = gameTrackerX.material_fadeValue;
      if ((instance->flags2 & 0x8000000U) != 0) {
        sVar1 = gameTrackerX.spectral_fadeValue;
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
// unsigned long /*$ra*/ INSTANCE_DefaultAnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s4*/, long messageDataB /*stack 16*/, struct _Instance *instance /*stack 20*/)
 // line 2835, offset 0x800359c8
	/* begin block 1 */
		// Start line: 2836
		// Start offset: 0x800359C8
		// Variables:
	// 		struct _AnimSoundData_Type *soundData; // $s2

		/* begin block 1.1 */
			// Start line: 2848
			// Start offset: 0x80035A18
			// Variables:
		// 		int id; // $s0
		// 		int vol; // $s1
		/* end block 1.1 */
		// End offset: 0x80035A78
		// End Line: 2857
	/* end block 1 */
	// End offset: 0x80035AAC
	// End Line: 2871

	/* begin block 2 */
		// Start line: 6527
	/* end block 2 */
	// End Line: 6528

ulong INSTANCE_DefaultAnimCallback
                (_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,long messageDataA,
                long messageDataB,_Instance *instance)

{
  int iVar1;
  int iVar2;
  int maxVolume;
  
  if (message == G2ANIM_MSG_PLAYEFFECT) {
    if (messageDataA == 0) {
      if (messageDataB != 0) {
        maxVolume = (int)*(short *)(messageDataB + 2);
        if (999 < maxVolume) {
          iVar1 = maxVolume / 1000;
          maxVolume = maxVolume % 1000;
          iVar2 = HUMAN_TypeOfHuman(instance);
          if (iVar1 != iVar2) {
            return 0;
          }
        }
        SOUND_Play3dSound(&instance->position,(int)*(short *)messageDataB,
                          (int)*(short *)(messageDataB + 4),maxVolume,
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





