#include "THISDUST.H"
#include "INSTANCE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_Deactivate(struct _Instance *instance /*$a1*/)
 // line 49, offset 0x80031c84
	/* begin block 1 */
		// Start line: 50
		// Start offset: 0x80031C84
		// Variables:
	// 		struct Object *object; // $a3
	/* end block 1 */
	// End offset: 0x80031D24
	// End Line: 72

	/* begin block 2 */
		// Start line: 98
	/* end block 2 */
	// End Line: 99

void INSTANCE_Deactivate(_Instance *instance)

{
  u_int uVar1;
  
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
 // line 75, offset 0x80031d34
	/* begin block 1 */
		// Start line: 76
		// Start offset: 0x80031D34
		// Variables:
	// 		struct Object *object; // $a2
	/* end block 1 */
	// End offset: 0x80031DBC
	// End Line: 98

	/* begin block 2 */
		// Start line: 157
	/* end block 2 */
	// End Line: 158

void INSTANCE_Reactivate(_Instance *instance)

{
  u_int uVar1;
  u_int uVar2;
  
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
 // line 101, offset 0x80031dcc
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
 // line 111, offset 0x80031e00
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
 // line 117, offset 0x80031e08
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x80031E08
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
	// End offset: 0x80032058
	// End Line: 214

	/* begin block 2 */
		// Start line: 250
	/* end block 2 */
	// End Line: 251

void INSTANCE_DeactivateFarInstances(GameTracker *gameTracker)

{
  u_long uVar1;
  u_int uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  _Instance *Inst;
  int iVar6;
  
  iVar5 = gameTracker->instanceList->numInstances;
  Inst = gameTracker->instanceList->first;
  iVar6 = (iVar5 >> 3) + 1;
  if (iVar5 <= DAT_800cf588) {
    DAT_800cf588 = 0;
  }
  iVar3 = DAT_800cf588;
  DAT_800cf588 = DAT_800cf588 + iVar6;
  if (iVar5 <= DAT_800cf588) {
    DAT_800cf588 = 0;
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
      iVar5 = (u_int)(ushort)(Inst->position).y - (u_int)(ushort)theCamera.core.position.y;
      DAT_1f800002 = (undefined2)iVar5;
      iVar5 = iVar5 * 0x10000 >> 0x10;
      iVar4 = (u_int)(ushort)(Inst->position).z - (u_int)(ushort)theCamera.core.position.z;
      iVar3 = iVar4 * 0x10000 >> 0x10;
      DAT_1f800004 = (undefined2)iVar4;
      iVar5 = (int)DAT_1f800000 * (int)DAT_1f800000 + iVar5 * iVar5 + iVar3 * iVar3;
      if ((Inst->flags & 0x200U) == 0) {
        if ((Inst->flags2 & 0x80000U) == 0) {
          iVar3 = (int)Inst->object->removeDist;
          iVar3 = iVar3 * iVar3;
        }
        else {
          iVar3 = gameTracker->defRemoveDist * gameTracker->defRemoveDist;
        }
        uVar2 = Inst->flags2 & 1;
        if (iVar5 <= iVar3) goto LAB_80032038;
      }
      else {
        iVar3 = (int)Inst->object->vvRemoveDist;
        if (iVar5 <= iVar3 * iVar3) {
          uVar2 = Inst->flags2 & 1;
          goto LAB_80032038;
        }
        uVar2 = Inst->flags2 & 1;
      }
      if (uVar2 == 0) {
        INSTANCE_Deactivate(Inst);
      }
    }
    else {
      uVar2 = Inst->flags2 & 1;
LAB_80032038:
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
 // line 237, offset 0x80032074
	/* begin block 1 */
		// Start line: 239
		// Start offset: 0x80032074
		// Variables:
	// 		long i; // $a3
	/* end block 1 */
	// End offset: 0x80032108
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
  int iVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  pool->numFreeInstances = 0x3c;
  iVar4 = 1;
  iVar6 = 8;
  iVar5 = 0x538;
  plVar3 = &pool->instance[0].light_color;
  do {
    iVar2 = (int)&pool->nextInstanceID + iVar6;
    iVar6 = iVar6 + 0x298;
    iVar1 = (int)&pool->nextInstanceID + iVar5;
    iVar5 = iVar5 + 0x298;
    plVar3[4] = iVar1;
    plVar3[5] = iVar2;
    iVar4 = iVar4 + 1;
    plVar3 = plVar3 + 0xa6;
  } while (iVar4 < 0x3b);
  iVar4 = 0;
  pool->instance[0].next = pool->instance + 1;
  pool->instance[0].prev = (_Instance *)0x0;
  pool->instance[0x3b].prev = (_Instance *)(&DAT_00009678 + (int)pool);
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
 // line 328, offset 0x80032114
	/* begin block 1 */
		// Start line: 330
		// Start offset: 0x80032114
		// Variables:
	// 		struct _Instance *temp; // $v0
	// 		struct _Instance *instance; // $a1
	/* end block 1 */
	// End offset: 0x80032198
	// End Line: 366

	/* begin block 2 */
		// Start line: 733
	/* end block 2 */
	// End Line: 734

	/* begin block 3 */
		// Start line: 734
	/* end block 3 */
	// End Line: 735

	/* begin block 4 */
		// Start line: 739
	/* end block 4 */
	// End Line: 740

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
 // line 368, offset 0x800321a0
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x800321A0
		// Variables:
	// 		long result; // $s0
	/* end block 1 */
	// End offset: 0x800322A8
	// End Line: 408

	/* begin block 2 */
		// Start line: 816
	/* end block 2 */
	// End Line: 817

long INSTANCE_InstanceGroupNumber(_Instance *instance)

{
  int iVar1;
  u_int uVar2;
  u_int uVar3;
  
  uVar2 = instance->object->oflags;
  uVar3 = 0;
  if ((uVar2 & 0x80) != 0) {
    uVar3 = (u_int)((instance->flags & 0x8000U) == 0);
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
 // line 427, offset 0x800322bc
	/* begin block 1 */
		// Start line: 428
		// Start offset: 0x800322BC
	/* end block 1 */
	// End offset: 0x800322BC
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
 // line 476, offset 0x80032304
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x80032304
		// Variables:
	// 		struct _Instance *temp; // $v1

		/* begin block 1.1 */
			// Start line: 579
			// Start offset: 0x80032538
			// Variables:
		// 		int i; // $a0
		/* end block 1.1 */
		// End offset: 0x8003255C
		// End Line: 588
	/* end block 1 */
	// End offset: 0x8003255C
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
 // line 592, offset 0x80032574
	/* begin block 1 */
		// Start line: 593
		// Start offset: 0x80032574
		// Variables:
	// 		struct _Instance *instance; // $a1
	// 		struct _Instance *next; // $s0
	/* end block 1 */
	// End offset: 0x80032618
	// End Line: 627

	/* begin block 2 */
		// Start line: 1302
	/* end block 2 */
	// End Line: 1303

void INSTANCE_CleanUpInstanceList(_InstanceList *list,long reset)

{
  _Instance **pp_Var1;
  _Instance *instance;
  u_int uVar2;
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
 // line 697, offset 0x80032630
	/* begin block 1 */
		// Start line: 698
		// Start offset: 0x80032630
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $s1
	/* end block 1 */
	// End offset: 0x800326D0
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
 // line 742, offset 0x800326e8
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
 // line 757, offset 0x80032738
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
// void /*$ra*/ INSTANCE_ProcessIntro(struct _Instance *instance /*$a0*/)
 // line 764, offset 0x8003275c
	/* begin block 1 */
		// Start line: 766
		// Start offset: 0x8003275C

		/* begin block 1.1 */
			// Start line: 766
			// Start offset: 0x80032780
			// Variables:
		// 		struct INICommand *command; // $a1
		/* end block 1.1 */
		// End offset: 0x800327D0
		// End Line: 786
	/* end block 1 */
	// End offset: 0x800327D0
	// End Line: 787

	/* begin block 2 */
		// Start line: 1600
	/* end block 2 */
	// End Line: 1601

	/* begin block 3 */
		// Start line: 1601
	/* end block 3 */
	// End Line: 1602

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
 // line 789, offset 0x800327d8
	/* begin block 1 */
		// Start line: 790
		// Start offset: 0x800327D8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80032848
	// End Line: 802

	/* begin block 2 */
		// Start line: 1655
	/* end block 2 */
	// End Line: 1656

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
 // line 804, offset 0x80032860
	/* begin block 1 */
		// Start line: 805
		// Start offset: 0x80032860
		// Variables:
	// 		struct Object *object; // $s6
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *attachInst; // $s5
	// 		struct _ObjectTracker *objectTracker; // $s1

		/* begin block 1.1 */
			// Start line: 820
			// Start offset: 0x800328A4
			// Variables:
		// 		struct INICommand *index; // $v0
		// 		long attachedUniqueID; // $s4

			/* begin block 1.1.1 */
				// Start line: 956
				// Start offset: 0x80032B74
			/* end block 1.1.1 */
			// End offset: 0x80032BB0
			// End Line: 966

			/* begin block 1.1.2 */
				// Start line: 1016
				// Start offset: 0x80032CB0
				// Variables:
			// 		struct SavedIntroSpline *savedIntroSpline; // $s1
			// 		struct MultiSpline *spline; // $s2
			/* end block 1.1.2 */
			// End offset: 0x80032F08
			// End Line: 1066

			/* begin block 1.1.3 */
				// Start line: 1068
				// Start offset: 0x80032F08
				// Variables:
			// 		struct SavedIntroSmall *savedIntroSmall; // $v0

				/* begin block 1.1.3.1 */
					// Start line: 1082
					// Start offset: 0x80032F34
				/* end block 1.1.3.1 */
				// End offset: 0x80032F5C
				// End Line: 1089
			/* end block 1.1.3 */
			// End offset: 0x80032F5C
			// End Line: 1091
		/* end block 1.1 */
		// End offset: 0x80032F64
		// End Line: 1107
	/* end block 1 */
	// End offset: 0x80032F68
	// End Line: 1109

	/* begin block 2 */
		// Start line: 1687
	/* end block 2 */
	// End Line: 1688

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
  u_int uVar7;
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
  if (objectTracker == (_ObjectTracker *)0x0) {
    return (_Instance *)0x0;
  }
  object = objectTracker->object;
  lVar2 = MEMPACK_MemoryValidFunc((char *)object);
  if (lVar2 == 0) {
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
  if (instance == (_Instance *)0x0) {
    return (_Instance *)0x0;
  }
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
    SCRIPT_InstanceSplineSet(instance,frameNum,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
    instance->flags = instance->flags ^ 0x1000000U | 0x100000;
  }
  instance->lightGroup = *(u_char *)&(intro->rotation).pad;
  instance->spectralLightGroup = *(u_char *)&intro->specturalLightGroup;
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
    uVar7 = instance->flags2;
    instance->flags = instance->flags | 0x800;
    instance->flags2 = uVar7 | 0x20000000;
    if ((object->oflags2 & 0x80000U) != 0) {
      instance->flags2 = uVar7 | 0x30000000;
    }
  }
  pMVar4 = SCRIPT_GetMultiSpline(instance,(u_long *)0x0,(u_long *)0x0);
  if (pMVar4 == (MultiSpline *)0x0) {
    instance->flags = instance->flags & 0xfdffffffU | 0x100000;
  }
  else {
    pMVar4 = SCRIPT_GetMultiSpline(instance,(u_long *)0x0,(u_long *)0x0);
    pSVar5 = SAVE_GetIntroSpline(instance);
    if (pSVar5 != (SavedIntroSpline *)0x0) {
      SCRIPT_InstanceSplineSet
                (instance,pSVar5->splineKeyFrame,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0)
      ;
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
          if ((instance->splineFlags & 0x40U) == 0) goto LAB_80032f08;
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
          if (pSVar8 == (Spline *)0x0) goto LAB_80032f08;
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
          if (pSVar8 == (Spline *)0x0) goto LAB_80032f08;
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
        if (pSVar8 == (Spline *)0x0) goto LAB_80032f08;
        bVar1 = pSVar8->flags | 1;
      }
      pSVar8->flags = bVar1;
    }
  }
LAB_80032f08:
  EVENT_AddInstanceToInstanceList(instance);
  INSTANCE_ProcessIntro(instance);
  INSTANCE_InitEffects(instance,object);
  pSVar6 = SAVE_GetSavedSmallIntro(instance);
  if (pSVar6 != (SavedIntroSmall *)0x0) {
    Data = SetControlSaveDataData((u_int)pSVar6->shiftedSaveSize * 4 + -4,pSVar6 + 1);
    INSTANCE_Post(instance,(int)&DAT_00100007,Data);
  }
  return instance;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_AdditionalCollideFunctions(struct _InstanceList *instanceList /*$a0*/)
 // line 1114, offset 0x80032f90
	/* begin block 1 */
		// Start line: 1115
		// Start offset: 0x80032F90
		// Variables:
	// 		struct _Instance *instance; // $s0
	/* end block 1 */
	// End offset: 0x800330A4
	// End Line: 1146

	/* begin block 2 */
		// Start line: 2358
	/* end block 2 */
	// End Line: 2359

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
 // line 1149, offset 0x800330bc
	/* begin block 1 */
		// Start line: 1150
		// Start offset: 0x800330BC
	/* end block 1 */
	// End offset: 0x800330BC
	// End Line: 1150

	/* begin block 2 */
		// Start line: 2449
	/* end block 2 */
	// End Line: 2450

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
 // line 1162, offset 0x800330f4
	/* begin block 1 */
		// Start line: 1163
		// Start offset: 0x800330F4

		/* begin block 1.1 */
			// Start line: 1169
			// Start offset: 0x80033134
			// Variables:
		// 		struct _Instance *instance; // $s0

			/* begin block 1.1.1 */
				// Start line: 1189
				// Start offset: 0x800331C0
				// Variables:
			// 		int hidden; // $s1
			/* end block 1.1.1 */
			// End offset: 0x80033234
			// End Line: 1205

			/* begin block 1.1.2 */
				// Start line: 1231
				// Start offset: 0x80033304
				// Variables:
			// 		long prevFrame; // $s2
			// 		struct MultiSpline *multi; // $s4

				/* begin block 1.1.2.1 */
					// Start line: 1238
					// Start offset: 0x80033334
					// Variables:
				// 		long endOfSpline; // $s6
				// 		short direction; // $s7

					/* begin block 1.1.2.1.1 */
						// Start line: 1277
						// Start offset: 0x800333F4
						// Variables:
					// 		long frame; // $s3
					// 		long maxFrames; // $s1
					/* end block 1.1.2.1.1 */
					// End offset: 0x80033634
					// End Line: 1356

					/* begin block 1.1.2.1.2 */
						// Start line: 1367
						// Start offset: 0x80033668
					/* end block 1.1.2.1.2 */
					// End offset: 0x8003368C
					// End Line: 1372
				/* end block 1.1.2.1 */
				// End offset: 0x80033804
				// End Line: 1432
			/* end block 1.1.2 */
			// End offset: 0x80033804
			// End Line: 1434

			/* begin block 1.1.3 */
				// Start line: 1457
				// Start offset: 0x80033850
				// Variables:
			// 		int killTest; // $s1
			/* end block 1.1.3 */
			// End offset: 0x8003388C
			// End Line: 1464
		/* end block 1.1 */
		// End offset: 0x8003389C
		// End Line: 1472
	/* end block 1 */
	// End offset: 0x8003389C
	// End Line: 1473

	/* begin block 2 */
		// Start line: 2479
	/* end block 2 */
	// End Line: 2480

void INSTANCE_ProcessFunctions(_InstanceList *instanceList)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  bool bVar5;
  short frameNum;
  u_long uVar6;
  MultiSpline *multi;
  long lVar7;
  long lVar8;
  long lVar9;
  Spline *pSVar10;
  int iVar11;
  _Instance *Inst;
  u_int hidden;
  int iVar12;
  ushort uVar13;
  
  if ((gameTrackerX.debugFlags & 0x8000010U) == 0) {
    Inst = instanceList->first;
    while (Inst != (_Instance *)0x0) {
      gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
      if (((Inst->object != (Object *)0x0) && ((Inst->object->oflags2 & 0x2000000U) != 0)) &&
         (gameTrackerX.timeMult = gameTrackerX.materialTimeMult, (Inst->flags2 & 0x8000000U) != 0))
      {
        gameTrackerX.timeMult = gameTrackerX.spectralTimeMult;
      }
      if ((Inst->object->oflags2 & 4U) != 0) {
        hidden = Inst->flags & 0x800;
        uVar6 = INSTANCE_Query(Inst,2);
        if (((uVar6 & 0x20) != 0) && (uVar6 = INSTANCE_Query(Inst,3), (uVar6 & 0x10000) == 0)) {
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
            (multi = SCRIPT_GetMultiSpline(Inst,(u_long *)0x0,(u_long *)0x0),
            multi != (MultiSpline *)0x0)) && (hidden = Inst->flags, (hidden & 0x2000000) != 0)) {
          uVar13 = 1;
          if ((hidden & 0x1000000) != 0) {
            uVar13 = 0xffff;
          }
          if ((Inst->object->oflags & 0x10000000U) != 0) {
            Inst->flags = hidden | 0x400;
            frameNum = SplineMultiIsWhere(multi);
            if (frameNum != 0) {
              if ((int)((u_int)uVar13 << 0x10) < 1) {
                Inst->intro->flags = Inst->intro->flags & 0xfffff7ff;
              }
              else {
                Inst->intro->flags = Inst->intro->flags | 0x800;
              }
            }
          }
          lVar7 = INSTANCE_GetSplineFrameNumber(Inst,multi);
          lVar8 = SCRIPT_InstanceSplineProcess
                            (Inst,&multi->curPositional,&multi->curRotational,&multi->curScaling,
                             (int)(short)uVar13);
          if (Inst->splineFlags == 0) {
            if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
              INSTANCE_GetSplineFrameNumber(Inst,multi);
              FONT_Print("Spline %s%d prevFrame=%d, frame=%d\n");
            }
          }
          else {
            lVar9 = INSTANCE_GetSplineFrameNumber(Inst,multi);
            frameNum = SCRIPTCountFramesInSpline(Inst);
            iVar12 = (int)frameNum;
            if ((Inst->splineFlags & 1U) != 0) {
              if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
                printf(
                      "Spline %s%ld playto %d preveFram=%ld frame=%ld endOfSpline=%ld, maxFrames=%ld\n"
                      );
              }
              if ((int)(short)uVar13 < 1) {
                iVar11 = (int)Inst->targetFrame;
                if (lVar9 <= iVar11) {
                  if (iVar11 <= lVar7) goto LAB_800334d8;
                  if (lVar7 < lVar9) {
                    bVar5 = lVar7 + iVar12 < iVar11;
                    goto LAB_800334d0;
                  }
                }
              }
              else {
                if (iVar12 < lVar7) {
                  lVar7 = iVar12;
                }
                iVar11 = (int)Inst->targetFrame;
                if ((lVar9 < iVar11) || (iVar11 < lVar7)) {
                  if ((lVar9 < lVar7) && (lVar9 >= iVar11)) {
                    bVar5 = iVar11 + iVar12 < lVar7;
LAB_800334d0:
                    if (!bVar5) goto LAB_800334d8;
                  }
                }
                else {
LAB_800334d8:
                  Inst->flags = Inst->flags & 0xfdffffff;
                  SCRIPT_InstanceSplineSet
                            (Inst,Inst->targetFrame,(SplineDef *)0x0,(SplineDef *)0x0,
                             (SplineDef *)0x0);
                  lVar8 = 0;
                  Inst->splineFlags = Inst->splineFlags & 0xfffe;
                }
              }
            }
            if ((Inst->splineFlags & 2U) != 0) {
              if ((gameTrackerX.debugFlags2 & 0x400000U) != 0) {
                FONT_Print("Spline %s%d : clip(%d,%d) prevFrame=%d, frame=%d\n");
              }
              if (uVar13 == 1) {
                if (((lVar7 <= Inst->clipEnd) && (Inst->clipEnd <= lVar9)) ||
                   (lVar9 < Inst->clipBeg)) {
                  if ((*(u_int *)&multi->positional->numkeys & 0x6000000) == 0) {
                    frameNum = Inst->clipEnd;
LAB_80033640:
                    lVar8 = 1;
                  }
                  else {
                    frameNum = Inst->clipBeg;
                  }
LAB_80033644:
                  SCRIPT_InstanceSplineSet
                            (Inst,frameNum,(SplineDef *)0x0,(SplineDef *)0x0,(SplineDef *)0x0);
                }
              }
              else {
                if (((Inst->clipBeg <= lVar7) && (lVar9 <= Inst->clipBeg)) ||
                   (Inst->clipEnd < lVar9)) {
                  if ((*(u_int *)&multi->positional->numkeys & 0x6000000) == 0) {
                    frameNum = Inst->clipBeg;
                    goto LAB_80033640;
                  }
                  frameNum = Inst->clipEnd;
                  goto LAB_80033644;
                }
              }
            }
          }
          if (0 < lVar8) {
            if ((Inst->object->oflags & 0x10000000U) != 0) {
              Inst->flags = Inst->flags & 0xfdfffbffU | 0x100000;
            }
            hidden = Inst->object->oflags;
            if ((hidden & 0x2000) != 0) {
              Inst->flags = Inst->flags | 0x100000;
              INSTANCE_KillInstance(Inst);
              goto LAB_8003388c;
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
            pSVar10 = multi->positional;
            if (((pSVar10 != (Spline *)0x0) ||
                (pSVar10 = (Spline *)multi->rotational, pSVar10 != (Spline *)0x0)) &&
               (((pSVar10->flags & 4) == 0 && ((Inst->object->oflags & 0x800000U) == 0)))) {
              Inst->flags = Inst->flags ^ 0x1000000;
            }
            if ((((Inst->object->oflags & 0x200000U) != 0) && ((int *)Inst->introData != (int *)0x0)
                ) && (iVar12 = *(int *)Inst->introData, iVar12 != 0)) {
              SIGNAL_HandleSignal(Inst,(Signal *)(iVar12 + 8),0);
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
        iVar12 = (int)(Inst->position).z - (int)(Inst->oldPos).z;
        if (0x8000 < iVar12) {
          INSTANCE_PlainDeath(Inst);
        }
        if (iVar12 < -0x8000) {
          INSTANCE_PlainDeath(Inst);
        }
      }
LAB_8003388c:
      Inst = Inst->next;
    }
  }
  gameTrackerX.timeMult = gameTrackerX.globalTimeMult;
  return;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_BirthObject(struct _Instance *parent /*$s2*/, struct Object *object /*$s4*/, int modelNum /*$s1*/)
 // line 1480, offset 0x800338d4
	/* begin block 1 */
		// Start line: 1481
		// Start offset: 0x800338D4
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x80033B24
	// End Line: 1552

	/* begin block 2 */
		// Start line: 3445
	/* end block 2 */
	// End Line: 3446

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
      if ((int)sVar3 <= iVar7) goto LAB_80033a2c;
      iVar7 = iVar7 + 1;
    } while (*(char *)(iVar5 + 0x158) != '_');
    *(undefined *)(iVar5 + 0x158) = 0;
LAB_80033a2c:
    instance->parent = parent;
    instance->intro = parent->intro;
    instance->introData = parent->introData;
    LIGHT_GetAmbient((_ColorType *)&instance->light_color,instance);
    if ((instance->object->oflags & 0x100U) != 0) {
      INSTANCE_BuildStaticShadow(instance);
    }
    pMVar4 = SCRIPT_GetMultiSpline(instance,(u_long *)0x0,(u_long *)0x0);
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
 // line 1569, offset 0x80033b44
	/* begin block 1 */
		// Start line: 3135
	/* end block 1 */
	// End Line: 3136

	/* begin block 2 */
		// Start line: 3629
	/* end block 2 */
	// End Line: 3630

void INSTANCE_BuildStaticShadow(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_DefaultInit(struct _Instance *instance /*$s1*/, struct Object *object /*$s2*/, int modelNum /*$s0*/)
 // line 1603, offset 0x80033b4c
	/* begin block 1 */
		// Start line: 1604
		// Start offset: 0x80033B4C
		// Variables:
	// 		int i; // $t3
	// 		int j; // $a3
	// 		int numHPrims; // $a2
	// 		int numModels; // $s0
	// 		struct _HPrim *hprim; // $a2
	// 		struct _Model **pModel; // $t7
	// 		struct _HModel *hmodel; // $t8

		/* begin block 1.1 */
			// Start line: 1656
			// Start offset: 0x80033CD0
			// Variables:
		// 		struct _Model *model; // $v0
		// 		struct _Segment *seg; // $a1

			/* begin block 1.1.1 */
				// Start line: 1661
				// Start offset: 0x80033CE8
				// Variables:
			// 		struct _HInfo *hinfo; // $a0
			/* end block 1.1.1 */
			// End offset: 0x80033D10
			// End Line: 1665
		/* end block 1.1 */
		// End offset: 0x80033D1C
		// End Line: 1666

		/* begin block 1.2 */
			// Start line: 1675
			// Start offset: 0x80033D78
			// Variables:
		// 		struct _Model *model; // $s0
		// 		struct _Segment *seg; // $t4

			/* begin block 1.2.1 */
				// Start line: 1686
				// Start offset: 0x80033D94
				// Variables:
			// 		struct _HInfo *hinfo; // $a1

				/* begin block 1.2.1.1 */
					// Start line: 1690
					// Start offset: 0x80033DA4
					// Variables:
				// 		int k; // $v1
				// 		struct _HFace *hface; // $t0
				// 		struct _HSphere *hsphere; // $t1
				// 		struct _HBox *hbox; // $t2
				/* end block 1.2.1.1 */
				// End offset: 0x80033E8C
				// End Line: 1729
			/* end block 1.2.1 */
			// End offset: 0x80033E8C
			// End Line: 1730
		/* end block 1.2 */
		// End offset: 0x80033EA4
		// End Line: 1731
	/* end block 1 */
	// End offset: 0x80033EE8
	// End Line: 1743

	/* begin block 2 */
		// Start line: 3688
	/* end block 2 */
	// End Line: 3689

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
 // line 1746, offset 0x80033f04
	/* begin block 1 */
		// Start line: 1747
		// Start offset: 0x80033F04

		/* begin block 1.1 */
			// Start line: 1776
			// Start offset: 0x80033FC8
			// Variables:
		// 		struct _Instance *oldOn; // $a0
		/* end block 1.1 */
		// End offset: 0x80033FF0
		// End Line: 1783
	/* end block 1 */
	// End offset: 0x80033FF0
	// End Line: 1785

	/* begin block 2 */
		// Start line: 4132
	/* end block 2 */
	// End Line: 4133

void INSTANCE_PlainDeath(_Instance *instance)

{
  u_int uVar1;
  _Instance *p_Var2;
  Object *pOVar3;
  
  pOVar3 = instance->object;
  instance->flags = instance->flags & 0xfffffbff;
  if ((pOVar3->oflags2 & 4U) != 0) {
    uVar1 = instance->flags2;
    instance->flags2 = uVar1 | 0x1000;
    SOUND_ProcessInstanceSounds
              (pOVar3->soundData,instance->soundInstanceTbl,&instance->position,
               pOVar3->oflags2 & 0x2000000,uVar1 & 0x8000000,0,&instance->flags2);
    SOUND_ProcessInstanceSounds
              (instance->object->soundData,instance->soundInstanceTbl,&instance->position,
               instance->object->oflags2 & 0x2000000,instance->flags2 & 0x8000000,0,
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
 // line 1789, offset 0x8003402c
	/* begin block 1 */
		// Start line: 4225
	/* end block 1 */
	// End Line: 4226

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
 // line 1808, offset 0x80034060
	/* begin block 1 */
		// Start line: 1809
		// Start offset: 0x80034060
		// Variables:
	// 		unsigned long (*Func)(); // $v0
	/* end block 1 */
	// End offset: 0x8003408C
	// End Line: 1822

	/* begin block 2 */
		// Start line: 3610
	/* end block 2 */
	// End Line: 3611

u_long INSTANCE_Query(_Instance *Inst,int Query)

{
  u_long uVar1;
  
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
 // line 1826, offset 0x8003409c
	/* begin block 1 */
		// Start line: 1827
		// Start offset: 0x8003409C
		// Variables:
	// 		void (*Func)(); // $s1
	/* end block 1 */
	// End offset: 0x800340E4
	// End Line: 1837

	/* begin block 2 */
		// Start line: 4291
	/* end block 2 */
	// End Line: 4292

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
 // line 1843, offset 0x80034100
	/* begin block 1 */
		// Start line: 1844
		// Start offset: 0x80034100
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int plane; // $s1
	/* end block 1 */
	// End offset: 0x80034188
	// End Line: 1857

	/* begin block 2 */
		// Start line: 4329
	/* end block 2 */
	// End Line: 4330

	/* begin block 3 */
		// Start line: 4333
	/* end block 3 */
	// End Line: 4334

void INSTANCE_Broadcast(_Instance *sender,long whatAmIMask,int Message,int Data)

{
  u_long uVar1;
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
 // line 1862, offset 0x800341ac
	/* begin block 1 */
		// Start line: 4379
	/* end block 1 */
	// End Line: 4380

	/* begin block 2 */
		// Start line: 4380
	/* end block 2 */
	// End Line: 4381

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
 // line 1889, offset 0x80034208
	/* begin block 1 */
		// Start line: 1891
		// Start offset: 0x80034208
		// Variables:
	// 		struct _Instance *instance; // $v1
	// 		struct _Instance *next; // $v1
	// 		long ret; // $a1
	/* end block 1 */
	// End offset: 0x80034240
	// End Line: 1907

	/* begin block 2 */
		// Start line: 3775
	/* end block 2 */
	// End Line: 3776

	/* begin block 3 */
		// Start line: 4408
	/* end block 3 */
	// End Line: 4409

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
 // line 1946, offset 0x80034248
	/* begin block 1 */
		// Start line: 1947
		// Start offset: 0x80034248
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _Instance *ret; // $s2
	// 		struct _Instance *next; // $s1
	/* end block 1 */
	// End offset: 0x800342F8
	// End Line: 1990

	/* begin block 2 */
		// Start line: 3885
	/* end block 2 */
	// End Line: 3886

	/* begin block 3 */
		// Start line: 4485
	/* end block 3 */
	// End Line: 4486

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
 // line 2016, offset 0x8003431c
	/* begin block 1 */
		// Start line: 2017
		// Start offset: 0x8003431C
		// Variables:
	// 		struct Intro *ret; // $s0
	// 		long i; // $a0
	// 		struct Level *level; // $v1
	/* end block 1 */
	// End offset: 0x80034388
	// End Line: 2037

	/* begin block 2 */
		// Start line: 4029
	/* end block 2 */
	// End Line: 4030

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
 // line 2041, offset 0x800343a0
	/* begin block 1 */
		// Start line: 2043
		// Start offset: 0x800343A0
		// Variables:
	// 		struct _Instance *instance; // $v1
	/* end block 1 */
	// End offset: 0x800343D8
	// End Line: 2049

	/* begin block 2 */
		// Start line: 4671
	/* end block 2 */
	// End Line: 4672

	/* begin block 3 */
		// Start line: 4672
	/* end block 3 */
	// End Line: 4673

	/* begin block 4 */
		// Start line: 4674
	/* end block 4 */
	// End Line: 4675

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
// struct _Instance * /*$ra*/ INSTANCE_IntroduceSavedInstance(struct _SavedIntro *savedIntro /*$s2*/, struct _StreamUnit *streamUnit /*$a1*/)
 // line 2053, offset 0x800343e0
	/* begin block 1 */
		// Start line: 2054
		// Start offset: 0x800343E0
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s1
	// 		struct Object *object; // $s7
	// 		struct _Instance *instance; // $s0
	// 		struct _Position *levelOffset; // $s5
	// 		struct Level *level; // $v0
	// 		struct _Instance *attachInst; // $s4

		/* begin block 1.1 */
			// Start line: 2070
			// Start offset: 0x80034434
			// Variables:
		// 		char savedName[12]; // stack offset -56

			/* begin block 1.1.1 */
				// Start line: 2095
				// Start offset: 0x800344F4
				// Variables:
			// 		struct Level *birthLevel; // $v0
			// 		struct Intro *oldIntro; // $s1

				/* begin block 1.1.1.1 */
					// Start line: 2120
					// Start offset: 0x80034554
					// Variables:
				// 		struct Intro *intro; // $v1
				// 		int i; // $a0
				/* end block 1.1.1.1 */
				// End offset: 0x80034588
				// End Line: 2131

				/* begin block 1.1.1.2 */
					// Start line: 2148
					// Start offset: 0x800345B0
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
				// End offset: 0x800345B0
				// End Line: 2148

				/* begin block 1.1.1.3 */
					// Start line: 2231
					// Start offset: 0x80034790
				/* end block 1.1.1.3 */
				// End offset: 0x800347AC
				// End Line: 2242
			/* end block 1.1.1 */
			// End offset: 0x800347AC
			// End Line: 2243
		/* end block 1.1 */
		// End offset: 0x800347D0
		// End Line: 2254
	/* end block 1 */
	// End offset: 0x800347D0
	// End Line: 2263

	/* begin block 2 */
		// Start line: 4696
	/* end block 2 */
	// End Line: 4697

_Instance * INSTANCE_IntroduceSavedInstance(_SavedIntro *savedIntro,_StreamUnit *streamUnit)

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
  u_int uVar8;
  Intro *pIVar9;
  Object *pOVar10;
  int Data;
  Intro *pIVar11;
  Intro *pIVar12;
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
      lVar6 = MEMPACK_MemoryValidFunc((char *)object);
      if ((lVar6 == 0) ||
         ((savedIntro->attachedUniqueID != 0 &&
          (instance_00 = INSTANCE_Find((u_int)savedIntro->attachedUniqueID),
          instance_00 == (_Instance *)0x0)))) {
        SAVE_BufferIntro((SavedBasic *)savedIntro);
        instance = (_Instance *)0x0;
      }
      else {
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
          pIVar11 = (Intro *)0x0;
          pLVar7 = STREAM_GetLevelWithID(instance->birthStreamUnitID);
          pIVar12 = pIVar11;
          if (pLVar7 != (Level *)0x0) {
            Data = pLVar7->terrain->numIntros;
            pIVar9 = pLVar7->terrain->introList;
            if (Data != 0) {
              do {
                Data = Data + -1;
                pIVar12 = pIVar9;
                if (pIVar9->UniqueID == instance->introUniqueID) break;
                pIVar9 = pIVar9 + 1;
                pIVar12 = pIVar11;
              } while (Data != 0);
            }
          }
          if (pIVar12 == (Intro *)0x0) {
            instance->intro = (Intro *)0x0;
            instance->introData = (void *)0x0;
          }
          else {
            instance->intro = pIVar12;
            instance->introData = pIVar12->data;
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
          MORPH_SetupInstanceFlags(&gameTrackerX,instance);
          if (instance->intro != (Intro *)0x0) {
            INSTANCE_ProcessIntro(instance);
          }
          uVar8 = (u_int)savedIntro->shiftedSaveSize * 4;
          if (0x28 < uVar8) {
            Data = SetControlSaveDataData(uVar8 - 0x28,savedIntro + 1);
            INSTANCE_Post(instance,(int)&DAT_00100007,Data);
          }
          EVENT_AddInstanceToInstanceList(instance);
          INSTANCE_InitEffects(instance,object);
        }
      }
    }
  }
  return instance;
}



// decompiled code
// original method signature: 
// struct _Instance * /*$ra*/ INSTANCE_IntroduceSavedInstanceWithIntro(struct _SavedIntroWithIntro *savedIntro /*$s4*/, struct _StreamUnit *streamUnit /*$s6*/)
 // line 2266, offset 0x80034800
	/* begin block 1 */
		// Start line: 2267
		// Start offset: 0x80034800
		// Variables:
	// 		struct _ObjectTracker *objectTracker; // $s2
	// 		struct Object *object; // $s7
	// 		struct _Instance *instance; // $s0
	// 		struct _Position *levelOffset; // $fp
	// 		struct Level *level; // $v1
	// 		struct Intro *intro; // $s1
	// 		struct _Instance *attachedInst; // $s5

		/* begin block 1.1 */
			// Start line: 2310
			// Start offset: 0x80034938

			/* begin block 1.1.1 */
				// Start line: 2313
				// Start offset: 0x80034938
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
			// End offset: 0x80034938
			// End Line: 2313

			/* begin block 1.1.2 */
				// Start line: 2451
				// Start offset: 0x80034BB8
			/* end block 1.1.2 */
			// End offset: 0x80034BD4
			// End Line: 2462
		/* end block 1.1 */
		// End offset: 0x80034BD4
		// End Line: 2463
	/* end block 1 */
	// End offset: 0x80034BF8
	// End Line: 2478

	/* begin block 2 */
		// Start line: 5190
	/* end block 2 */
	// End Line: 5191

_Instance *
INSTANCE_IntroduceSavedInstanceWithIntro(_SavedIntroWithIntro *savedIntro,_StreamUnit *streamUnit)

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
  u_int uVar9;
  u_int uVar10;
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
      lVar5 = MEMPACK_MemoryValidFunc((char *)object);
      if ((lVar5 == 0) ||
         ((savedIntro->attachedUniqueID != 0 &&
          ((instance_00 = INSTANCE_Find((u_int)savedIntro->attachedUniqueID),
           instance_00 == (_Instance *)0x0 || (instance_00->matrix == (MATRIX *)0x0)))))) {
        SAVE_BufferIntro((SavedBasic *)savedIntro);
        instance = (_Instance *)0x0;
      }
      else {
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
          instance->attachedID = (u_int)savedIntro->attachedUniqueID;
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
          instance->flags = savedIntro->flags;
          instance->flags2 = savedIntro->flags2;
          if (instance_00 != (_Instance *)0x0) {
            INSTANCE_ForceActive(instance_00);
            instance_00->flags2 = instance_00->flags2 | 0x80;
          }
          uVar9 = instance->flags2;
          uVar10 = uVar9 & 0xfffffffe;
          instance->flags2 = uVar10;
          if ((instance->flags & 0x40000U) == 0) {
            uVar10 = uVar9 & 0xdffffffe;
          }
          else {
            uVar10 = uVar10 | 0x20000000;
          }
          instance->flags2 = uVar10;
          instance->flags = instance->flags & 0xfffbffff;
          pMVar6 = SCRIPT_GetMultiSpline(instance,(u_long *)0x0,(u_long *)0x0);
          if (pMVar6 == (MultiSpline *)0x0) {
            instance->flags = instance->flags & 0xfdffffffU | 0x100000;
          }
          MORPH_SetupInstanceFlags(&gameTrackerX,instance);
          if (instance->intro != (Intro *)0x0) {
            INSTANCE_ProcessIntro(instance);
          }
          uVar10 = (u_int)savedIntro->shiftedSaveSize * 4;
          if (0x20 < uVar10) {
            Data = SetControlSaveDataData(uVar10 - 0x20,savedIntro + 1);
            INSTANCE_Post(instance,(int)&DAT_00100007,Data);
          }
          EVENT_AddInstanceToInstanceList(instance);
          INSTANCE_InitEffects(instance,object);
        }
      }
    }
  }
  return instance;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_SpatialRelationships(struct _InstanceList *instanceList /*$s4*/)
 // line 2525, offset 0x80034c2c
	/* begin block 1 */
		// Start line: 2526
		// Start offset: 0x80034C2C
		// Variables:
	// 		struct _Instance *instance; // $s1
	// 		struct _Instance *checkee; // $s0

		/* begin block 1.1 */
			// Start line: 2535
			// Start offset: 0x80034C78
			// Variables:
		// 		struct MATRIX *lookMatrix; // $s0
		// 		long checkMask; // $s3

			/* begin block 1.1.1 */
				// Start line: 2544
				// Start offset: 0x80034CA0
				// Variables:
			// 		struct MATRIX invMatrix; // stack offset -80

				/* begin block 1.1.1.1 */
					// Start line: 2553
					// Start offset: 0x80034CFC
					// Variables:
				// 		struct evCollideInstanceStatsData data; // stack offset -48
				// 		struct MATRIX *mat; // $a2
				/* end block 1.1.1.1 */
				// End offset: 0x80034D50
				// End Line: 2563
			/* end block 1.1.1 */
			// End offset: 0x80034D60
			// End Line: 2565
		/* end block 1.1 */
		// End offset: 0x80034D60
		// End Line: 2566
	/* end block 1 */
	// End offset: 0x80034D70
	// End Line: 2568

	/* begin block 2 */
		// Start line: 5043
	/* end block 2 */
	// End Line: 5044

void INSTANCE_SpatialRelationships(_InstanceList *instanceList)

{
  undefined4 *puVar1;
  u_long uVar2;
  int iVar3;
  MATRIX *pMVar4;
  _Instance *Inst;
  _Instance *Inst_00;
  u_int uVar5;
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
 // line 2572, offset 0x80034d90
	/* begin block 1 */
		// Start line: 2573
		// Start offset: 0x80034D90
		// Variables:
	// 		long distance; // $s4

		/* begin block 1.1 */
			// Start line: 2578
			// Start offset: 0x80034DFC
			// Variables:
		// 		struct SVECTOR *delta; // $s0
		/* end block 1.1 */
		// End offset: 0x80034E04
		// End Line: 2595
	/* end block 1 */
	// End offset: 0x80034E7C
	// End Line: 2597

	/* begin block 2 */
		// Start line: 5870
	/* end block 2 */
	// End Line: 5871

int INSTANCE_SetStatsData
              (_Instance *instance,_Instance *checkee,_Vector *checkPoint,
              evCollideInstanceStatsData *data,MATRIX *mat)

{
  bool bVar1;
  u_int uVar2;
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
  return (u_int)bVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ INSTANCE_LinkToParent(struct _Instance *instance /*$s0*/, struct _Instance *parent /*$s1*/, int node /*$a2*/)
 // line 2601, offset 0x80034ea0
	/* begin block 1 */
		// Start line: 5953
	/* end block 1 */
	// End Line: 5954

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
 // line 2622, offset 0x80034f5c
	/* begin block 1 */
		// Start line: 2623
		// Start offset: 0x80034F5C
		// Variables:
	// 		struct _Instance *parent; // $s1

		/* begin block 1.1 */
			// Start line: 2627
			// Start offset: 0x80034F80
			// Variables:
		// 		struct _G2EulerAngles_Type ea; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 2635
				// Start offset: 0x80034F9C
				// Variables:
			// 		struct _Instance *sibling; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80034FD0
			// End Line: 2641
		/* end block 1.1 */
		// End offset: 0x800350AC
		// End Line: 2661
	/* end block 1 */
	// End offset: 0x800350AC
	// End Line: 2662

	/* begin block 2 */
		// Start line: 6001
	/* end block 2 */
	// End Line: 6002

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
 // line 2664, offset 0x800350c0
	/* begin block 1 */
		// Start line: 2665
		// Start offset: 0x800350C0
		// Variables:
	// 		struct _Instance *child; // $s1

		/* begin block 1.1 */
			// Start line: 2670
			// Start offset: 0x800350E8
			// Variables:
		// 		struct _Instance *sibling; // $s0
		/* end block 1.1 */
		// End offset: 0x800350E8
		// End Line: 2670
	/* end block 1 */
	// End offset: 0x80035110
	// End Line: 2681

	/* begin block 2 */
		// Start line: 6090
	/* end block 2 */
	// End Line: 6091

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
 // line 2687, offset 0x8003512c
	/* begin block 1 */
		// Start line: 2688
		// Start offset: 0x8003512C
		// Variables:
	// 		struct _Instance *child; // $s0
	/* end block 1 */
	// End offset: 0x80035170
	// End Line: 2696

	/* begin block 2 */
		// Start line: 6139
	/* end block 2 */
	// End Line: 6140

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
 // line 2701, offset 0x80035184
	/* begin block 1 */
		// Start line: 2703
		// Start offset: 0x80035184
		// Variables:
	// 		struct _Instance *child; // $v1
	/* end block 1 */
	// End offset: 0x800351B4
	// End Line: 2711

	/* begin block 2 */
		// Start line: 6170
	/* end block 2 */
	// End Line: 6171

	/* begin block 3 */
		// Start line: 6171
	/* end block 3 */
	// End Line: 6172

	/* begin block 4 */
		// Start line: 6173
	/* end block 4 */
	// End Line: 6174

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
 // line 2717, offset 0x800351bc
	/* begin block 1 */
		// Start line: 2719
		// Start offset: 0x800351BC
		// Variables:
	// 		struct _Instance *root1; // $a0
	// 		struct _Instance *root2; // $a1
	/* end block 1 */
	// End offset: 0x80035204
	// End Line: 2727

	/* begin block 2 */
		// Start line: 6204
	/* end block 2 */
	// End Line: 6205

	/* begin block 3 */
		// Start line: 6205
	/* end block 3 */
	// End Line: 6206

	/* begin block 4 */
		// Start line: 6207
	/* end block 4 */
	// End Line: 6208

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
  return (u_int)(instance1 == instance2);
}



// decompiled code
// original method signature: 
// int /*$ra*/ INSTANCE_GetFadeValue(struct _Instance *instance /*$s1*/)
 // line 2735, offset 0x8003520c
	/* begin block 1 */
		// Start line: 2736
		// Start offset: 0x8003520C
		// Variables:
	// 		int fadeValue; // $s0
	/* end block 1 */
	// End offset: 0x800352D8
	// End Line: 2760

	/* begin block 2 */
		// Start line: 6240
	/* end block 2 */
	// End Line: 6241

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
// unsigned long /*$ra*/ INSTANCE_DefaultAnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s0*/, long messageDataB /*stack 16*/, struct _Instance *instance /*stack 20*/)
 // line 2771, offset 0x800352f0
	/* begin block 1 */
		// Start line: 2772
		// Start offset: 0x800352F0
	/* end block 1 */
	// End offset: 0x8003535C
	// End Line: 2796

	/* begin block 2 */
		// Start line: 6316
	/* end block 2 */
	// End Line: 6317

u_long INSTANCE_DefaultAnimCallback
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





