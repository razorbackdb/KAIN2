#include "THISDUST.H"
#include "INSTANCE.H"

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_ClearTfaces(struct _Instance *instance /*$a0*/)
// line 52, offset 0x80031ed8
/* begin block 1 */
// Start line: 104
/* end block 1 */
// End Line: 105

/* begin block 2 */
// Start line: 111
/* end block 2 */
// End Line: 112

void INSTANCE_ClearTfaces(_Instance *instance)

{
  instance->oldWaterFace = (_TFace *)0x0;
  instance->waterFace = (_TFace *)0x0;
  instance->waterFaceTerrain = (_Terrain *)0x0;
  instance->tface = (_TFace *)0x0;
  instance->oldTFace = (_TFace *)0x0;
  instance->tfaceLevel = (void *)0x0;
  instance->cachedTFace = -1;
  instance->cachedBSPTree = 0;
  instance->cachedTFaceLevel = (void *)0x0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_Deactivate(struct _Instance *instance /*$s0*/)
// line 66, offset 0x80031f04
/* begin block 1 */
// Start line: 67
// Start offset: 0x80031F04
// Variables:
// 		struct Object *object; // $a2
/* end block 1 */
// End offset: 0x80031FB0
// End Line: 91

/* begin block 2 */
// Start line: 138
/* end block 2 */
// End Line: 139

void INSTANCE_Deactivate(_Instance *instance)

{
  uint uVar1;

  if ((DAT_800d10f0 & 0x2000000) == 0)
  {
    uVar1 = instance->flags2;
    instance->flags2 = uVar1 | 1;
    if ((uVar1 & 0x20000000) == 0)
    {
      instance->flags = instance->flags & 0xfffbffff;
      instance->flags2 = instance->flags2 | 0x20000000;
    }
    else
    {
      instance->flags = instance->flags | 0x40000;
    }
    if ((instance->object->animList != (_G2AnimKeylist_Type **)0x0) &&
        ((instance->object->oflags2 & 0x40000000U) == 0))
    {
      G2Anim_Free(&instance->anim);
    }
    INSTANCE_ClearTfaces(instance);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_Reactivate(struct _Instance *instance /*$a0*/)
// line 94, offset 0x80031fc0
/* begin block 1 */
// Start line: 95
// Start offset: 0x80031FC0
// Variables:
// 		struct Object *object; // $a2
/* end block 1 */
// End offset: 0x80032048
// End Line: 117

/* begin block 2 */
// Start line: 201
/* end block 2 */
// End Line: 202

void INSTANCE_Reactivate(_Instance *instance)

{
  uint uVar1;
  uint uVar2;

  uVar1 = instance->flags2;
  uVar2 = uVar1 & 0xfffffffe;
  instance->flags2 = uVar2;
  if ((instance->flags & 0x40000U) == 0)
  {
    uVar2 = uVar1 & 0xdffffffe;
  }
  else
  {
    instance->flags = instance->flags & 0xfffbffff;
    uVar2 = uVar2 | 0x20000000;
  }
  instance->flags2 = uVar2;
  if ((instance->object->animList != (_G2AnimKeylist_Type **)0x0) &&
      ((instance->object->oflags2 & 0x40000000U) == 0))
  {
    G2Anim_Restore(&instance->anim);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_ForceActive(struct _Instance *instance /*$a0*/)
// line 120, offset 0x80032058
/* begin block 1 */
// Start line: 262
/* end block 1 */
// End Line: 263

void INSTANCE_ForceActive(_Instance *instance)

{
  if ((instance->flags2 & 1U) != 0)
  {
    INSTANCE_Reactivate(instance);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_DeactivatedProcess(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
// line 130, offset 0x8003208c
/* begin block 1 */
// Start line: 282
/* end block 1 */
// End Line: 283

/* begin block 2 */
// Start line: 284
/* end block 2 */
// End Line: 285

void INSTANCE_DeactivatedProcess(_Instance *instance, GameTracker *gameTracker)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_DeactivateFarInstances(struct GameTracker *gameTracker /*$s3*/)
// line 136, offset 0x80032094
/* begin block 1 */
// Start line: 137
// Start offset: 0x80032094
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
// End offset: 0x800322F4
// End Line: 234

/* begin block 2 */
// Start line: 294
/* end block 2 */
// End Line: 295

void INSTANCE_DeactivateFarInstances(GameTracker *gameTracker)

{
  int iVar1;
  int iVar2;
  _Instance *instance;
  int iVar3;

  iVar2 = gameTracker->instanceList->numInstances;
  instance = gameTracker->instanceList->first;
  iVar3 = (iVar2 >> 3) + 1;
  if (iVar2 <= DAT_800ce3a8)
  {
    DAT_800ce3a8 = 0;
  }
  iVar1 = DAT_800ce3a8;
  DAT_800ce3a8 = DAT_800ce3a8 + iVar3;
  if (iVar2 <= DAT_800ce3a8)
  {
    DAT_800ce3a8 = 0;
  }
  while (iVar1 != 0)
  {
    instance = instance->next;
    iVar1 = iVar1 + -1;
  }
  while (true)
  {
    if ((instance == (_Instance *)0x0) || (iVar3 == 0))
    {
      return;
    }
    if (((instance->flags2 & 0x80U) == 0) && ((instance->object->oflags & 0x10000U) == 0))
      break;
    if ((instance->flags2 & 1U) != 0)
    {
      INSTANCE_Reactivate(instance);
    }
    instance = instance->next;
    iVar3 = iVar3 + -1;
  }
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(instance, 0x23);
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_InitInstanceList(struct _InstanceList *list /*$a0*/, struct _InstancePool *pool /*$a1*/)
// line 257, offset 0x80032310
/* begin block 1 */
// Start line: 259
// Start offset: 0x80032310
// Variables:
// 		long i; // $a3
/* end block 1 */
// End offset: 0x800323A4
// End Line: 292

/* begin block 2 */
// Start line: 562
/* end block 2 */
// End Line: 563

/* begin block 3 */
// Start line: 563
/* end block 3 */
// End Line: 564

/* begin block 4 */
// Start line: 566
/* end block 4 */
// End Line: 567

void INSTANCE_InitInstanceList(_InstanceList *list, _InstancePool *pool)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  pool->numFreeInstances = 0x3e;
  iVar4 = 1;
  iVar6 = 8;
  iVar5 = 0x4d8;
  plVar3 = &pool->instance[0].light_color;
  do
  {
    iVar2 = (int)&pool->nextInstanceID + iVar6;
    iVar6 = iVar6 + 0x268;
    iVar1 = (int)&pool->nextInstanceID + iVar5;
    iVar5 = iVar5 + 0x268;
    plVar3[4] = iVar1;
    plVar3[5] = iVar2;
    iVar4 = iVar4 + 1;
    plVar3 = plVar3 + 0x9a;
  } while (iVar4 < 0x3d);
  iVar4 = 0;
  pool->instance[0].next = pool->instance + 1;
  pool->instance[0].prev = (_Instance *)0x0;
  pool->instance[0x3d].prev = (_Instance *)(&DAT_00009068 + (int)pool);
  pool->instance[0x3d].next = (_Instance *)0x0;
  pool->first_free = pool->instance;
  list->pool = pool;
  list->numInstances = 0;
  list->first = (_Instance *)0x0;
  do
  {
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
// line 348, offset 0x800323b0
/* begin block 1 */
// Start line: 350
// Start offset: 0x800323B0
// Variables:
// 		struct _Instance *temp; // $v0
// 		struct _Instance *instance; // $a1
/* end block 1 */
// End offset: 0x80032434
// End Line: 389

/* begin block 2 */
// Start line: 779
/* end block 2 */
// End Line: 780

/* begin block 3 */
// Start line: 780
/* end block 3 */
// End Line: 781

/* begin block 4 */
// Start line: 785
/* end block 4 */
// End Line: 786

_Instance *INSTANCE_NewInstance(_InstanceList *list)

{
  int iVar1;
  _Instance *p_Var2;
  _InstancePool *p_Var3;
  _Instance *p_Var4;

  iVar1 = list->pool->numFreeInstances;
  if (iVar1 != 0)
  {
    list->pool->numFreeInstances = iVar1 + -1;
    p_Var4 = list->pool->first_free;
    list->pool->first_free = p_Var4->next;
    p_Var2 = list->first;
    list->first = p_Var4;
    p_Var4->next = p_Var2;
    if (p_Var2 != (_Instance *)0x0)
    {
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
// line 391, offset 0x8003243c
/* begin block 1 */
// Start line: 392
// Start offset: 0x8003243C
// Variables:
// 		long result; // $s0
/* end block 1 */
// End offset: 0x80032544
// End Line: 431

/* begin block 2 */
// Start line: 868
/* end block 2 */
// End Line: 869

long INSTANCE_InstanceGroupNumber(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  uint uVar3;

  uVar2 = instance->object->oflags;
  uVar3 = 0;
  if ((uVar2 & 0x80) != 0)
  {
    uVar3 = (uint)((instance->flags & 0x8000U) == 0);
  }
  if (((uVar2 & 0x20) != 0) && ((instance->flags & 0x2000U) == 0))
  {
    uVar3 = uVar3 | 2;
  }
  if (((instance->object->oflags & 0x40U) != 0) && ((instance->flags & 0x4000U) == 0))
  {
    uVar3 = uVar3 | 4;
  }
  if (((instance->object->oflags & 0x10U) != 0) && ((instance->flags & 0x1000U) == 0))
  {
    uVar3 = uVar3 | 0x10;
  }
  if ((instance->object->oflags & 1U) == 0)
  {
    iVar1 = strcmp(instance->object->name, s_raziel___800ce3ac);
    if (iVar1 != 0)
    {
      uVar3 = uVar3 & 0xfffffffc;
    }
  }
  else
  {
    uVar3 = uVar3 | 8;
  }
  return uVar3;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_InsertInstanceGroup(struct _InstanceList *list /*$s1*/, struct _Instance *instance /*$s0*/)
// line 450, offset 0x80032558
/* begin block 1 */
// Start line: 451
// Start offset: 0x80032558
/* end block 1 */
// End offset: 0x80032558
// End Line: 451

/* begin block 2 */
// Start line: 986
/* end block 2 */
// End Line: 987

void INSTANCE_InsertInstanceGroup(_InstanceList *list, _Instance *instance)

{
  long lVar1;

  lVar1 = INSTANCE_InstanceGroupNumber(instance);
  LIST_InsertFunc(list->group + lVar1, (NodeType *)instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_ReallyRemoveInstance(struct _InstanceList *list /*$s1*/, struct _Instance *instance /*$s0*/, long reset /*$s2*/)
// line 499, offset 0x800325a0
/* begin block 1 */
// Start line: 500
// Start offset: 0x800325A0
// Variables:
// 		struct _Instance *temp; // $v1

/* begin block 1.1 */
// Start line: 602
// Start offset: 0x800327AC
// Variables:
// 		int i; // $a0
/* end block 1.1 */
// End offset: 0x800327CC
// End Line: 611
/* end block 1 */
// End offset: 0x800327CC
// End Line: 612

/* begin block 2 */
// Start line: 998
/* end block 2 */
// End Line: 999

void INSTANCE_ReallyRemoveInstance(_InstanceList *list, _Instance *instance, long reset)

{
  _Instance *p_Var1;
  Object *pOVar2;
  undefined4 *puVar3;
  Intro *pIVar4;
  int iVar5;

  EVENT_RemoveInstanceFromInstanceList(instance);
  if ((instance->flags & 0x800000U) != 0)
  {
    SAVE_DoInstanceDeadDead(instance);
  }
  if ((instance->flags & 2U) == 0)
  {
    pIVar4 = instance->intro;
    if (pIVar4 != (Intro *)0x0)
    {
      pIVar4->flags = pIVar4->flags & ~reset;
      instance->intro->instance = (_Instance *)0x0;
    }
  }
  if (instance->prev == (_Instance *)0x0)
  {
    list->first = instance->next;
  }
  else
  {
    instance->prev->next = instance->next;
  }
  if (instance->next != (_Instance *)0x0)
  {
    instance->next->prev = instance->prev;
  }
  instance->instanceID = 0;
  list->numInstances = list->numInstances + -1;
  list->pool->numFreeInstances = list->pool->numFreeInstances + 1;
  p_Var1 = list->pool->first_free;
  list->pool->first_free = instance;
  instance->prev = (_Instance *)0x0;
  instance->next = p_Var1;
  if (p_Var1 != (_Instance *)0x0)
  {
    p_Var1->prev = instance;
  }
  LIST_DeleteFunc((NodeType *)instance);
  FX_EndInstanceEffects(instance);
  if ((instance->flags & 0x10000U) != 0)
  {
    instance->flags = instance->flags | 0x20000;
    OBTABLE_InstanceInit(instance);
  }
  pOVar2 = instance->object;
  if (pOVar2->animList != (_G2AnimKeylist_Type **)0x0)
  {
    if ((pOVar2->oflags2 & 0x40000000U) == 0)
    {
      G2Anim_Free(&instance->anim);
    }
    pOVar2 = instance->object;
  }
  if ((pOVar2->oflags2 & 4U) != 0)
  {
    SOUND_EndInstanceSounds(pOVar2->soundData, instance->soundInstanceTbl);
  }
  if (instance->LinkParent != (_Instance *)0x0)
  {
    INSTANCE_UnlinkFromParent(instance);
  }
  if (instance->LinkChild != (_Instance *)0x0)
  {
    INSTANCE_UnlinkChildren(instance);
  }
  if (instance->hModelList == (_HModel *)0x0)
  {
    if (instance->perVertexColor != (CVECTOR *)0x0)
    {
      /* WARNING: Subroutine does not return */
      MEMPACK_Free((char *)instance->perVertexColor);
    }
    iVar5 = 0;
    puVar3 = &gameTrackerX;
    do
    {
      iVar5 = iVar5 + 1;
      if ((_Instance *)puVar3[3] == instance)
      {
        puVar3[3] = 0;
        return;
      }
      puVar3 = puVar3 + 5;
    } while (iVar5 < 1);
    return;
  }
  /* WARNING: Subroutine does not return */
  MEMPACK_Free((char *)instance->hModelList);
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_CleanUpInstanceList(struct _InstanceList *list /*$s1*/, long reset /*$s2*/)
// line 615, offset 0x800327e4
/* begin block 1 */
// Start line: 616
// Start offset: 0x800327E4
// Variables:
// 		struct _Instance *instance; // $a1
// 		struct _Instance *next; // $s0
/* end block 1 */
// End offset: 0x80032888
// End Line: 650

/* begin block 2 */
// Start line: 1354
/* end block 2 */
// End Line: 1355

void INSTANCE_CleanUpInstanceList(_InstanceList *list, long reset)

{
  _Instance **pp_Var1;
  _Instance *instance;
  uint uVar2;
  _Instance *p_Var3;

  p_Var3 = list->first;
  if (p_Var3 != (_Instance *)0x0)
  {
    do
    {
      uVar2 = p_Var3->flags;
      pp_Var1 = &p_Var3->next;
      if ((uVar2 & 0x400) == 0)
      {
        if ((uVar2 & 0x20) != 0)
        {
          p_Var3->flags = uVar2 | 0x20;
        }
      }
      else
      {
        if ((uVar2 & 0x20) != 0)
        {
          p_Var3->flags = uVar2 & 0xffffffdf;
        }
      }
      p_Var3 = *pp_Var1;
    } while (*pp_Var1 != (_Instance *)0x0);
    p_Var3 = list->first;
  }
  while (instance = p_Var3, instance != (_Instance *)0x0)
  {
    p_Var3 = instance->next;
    if ((instance->flags & 0x20U) != 0)
    {
      INSTANCE_ReallyRemoveInstance(list, instance, reset);
    }
  }
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ INSTANCE_Introduced(struct Intro *intro /*$s0*/, short streamUnitID /*$a1*/)
// line 720, offset 0x800328a0
/* begin block 1 */
// Start line: 721
// Start offset: 0x800328A0
// Variables:
// 		struct _Instance *instance; // $v1
// 		struct _Instance *next; // $v1
// 		long ret; // $s1
/* end block 1 */
// End offset: 0x80032940
// End Line: 761

/* begin block 2 */
// Start line: 1440
/* end block 2 */
// End Line: 1441

/* begin block 3 */
// Start line: 1496
/* end block 3 */
// End Line: 1497

long INSTANCE_Introduced(Intro *intro, short streamUnitID)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  long lVar4;

  iVar3 = *(int *)(DAT_800d0fe0 + 4);
  lVar4 = 0;
  if (iVar3 != 0)
  {
    do
    {
      piVar1 = (int *)(iVar3 + 0x3c);
      iVar3 = *(int *)(iVar3 + 8);
      if (intro->UniqueID == *piVar1)
      {
        lVar4 = 1;
        intro->flags = intro->flags | 8;
        break;
      }
    } while (iVar3 != 0);
  }
  if ((lVar4 == 0) &&
      ((lVar2 = SAVE_HasSavedIntro(intro, (int)streamUnitID), lVar2 != 0 ||
                                                                  (lVar2 = SAVE_IsIntroDeadDead(intro), lVar2 != 0))))
  {
    intro->flags = intro->flags | 8;
    lVar4 = 1;
  }
  return lVar4;
}

// decompiled code
// original method signature:
// struct INICommand * /*$ra*/ INSTANCE_GetIntroCommand(struct INICommand *command /*$a0*/, int cmd /*$a1*/)
// line 765, offset 0x80032958
/* begin block 1 */
// Start line: 1606
/* end block 1 */
// End Line: 1607

/* begin block 2 */
// Start line: 1607
/* end block 2 */
// End Line: 1608

INICommand *INSTANCE_GetIntroCommand(INICommand *command, int cmd)

{
  if (command != (INICommand *)0x0)
  {
    while (command->command != 0)
    {
      if ((int)command->command == cmd)
      {
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
// line 780, offset 0x800329a8
/* begin block 1 */
// Start line: 1638
/* end block 1 */
// End Line: 1639

INICommand *INSTANCE_FindIntroCommand(_Instance *instance, int cmd)

{
  INICommand *pIVar1;

  pIVar1 = INSTANCE_GetIntroCommand((INICommand *)instance->introData, cmd);
  return pIVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_ProcessIntro(struct _Instance *instance /*$a0*/)
// line 787, offset 0x800329cc
/* begin block 1 */
// Start line: 789
// Start offset: 0x800329CC

/* begin block 1.1 */
// Start line: 789
// Start offset: 0x800329F0
// Variables:
// 		struct INICommand *command; // $a1
/* end block 1.1 */
// End offset: 0x80032A40
// End Line: 809
/* end block 1 */
// End offset: 0x80032A40
// End Line: 810

/* begin block 2 */
// Start line: 1652
/* end block 2 */
// End Line: 1653

/* begin block 3 */
// Start line: 1653
/* end block 3 */
// End Line: 1654

void INSTANCE_ProcessIntro(_Instance *instance)

{
  short sVar1;
  short sVar2;
  short *psVar3;

  psVar3 = (short *)instance->introData;
  if ((psVar3 != (short *)0x0) && ((instance->flags & 2U) == 0))
  {
    sVar1 = *psVar3;
    sVar2 = *psVar3;
    while (sVar1 != 0)
    {
      if (sVar2 == 0x12)
      {
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
// line 812, offset 0x80032a48
/* begin block 1 */
// Start line: 813
// Start offset: 0x80032A48
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x80032AB8
// End Line: 825

/* begin block 2 */
// Start line: 1707
/* end block 2 */
// End Line: 1708

void INSTANCE_InitEffects(_Instance *instance, Object *object)

{
  int iVar1;
  int iVar2;

  if ((((object->oflags2 & 0x100U) == 0) && (object->numberOfEffects != 0)) &&
      (iVar2 = 0, 0 < object->numberOfEffects))
  {
    iVar1 = 0;
    do
    {
      FX_StartInstanceEffect(instance, (ObjectEffect *)(&object->effectList->effectNumber + iVar1), 1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (iVar2 < object->numberOfEffects);
  }
  return;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ INSTANCE_IntroduceInstance(struct Intro *intro /*$s2*/, short streamUnitID /*$a1*/)
// line 827, offset 0x80032ad0
/* begin block 1 */
// Start line: 828
// Start offset: 0x80032AD0
// Variables:
// 		struct Object *object; // $s6
// 		struct _Instance *instance; // $s0
// 		struct _Instance *attachInst; // $s5
// 		struct _ObjectTracker *objectTracker; // $s1

/* begin block 1.1 */
// Start line: 843
// Start offset: 0x80032B14
// Variables:
// 		struct INICommand *index; // $v0
// 		long attachedUniqueID; // $s4

/* begin block 1.1.1 */
// Start line: 980
// Start offset: 0x80032DE0
/* end block 1.1.1 */
// End offset: 0x80032E1C
// End Line: 990

/* begin block 1.1.2 */
// Start line: 1040
// Start offset: 0x80032F10
// Variables:
// 		struct SavedIntroSpline *savedIntroSpline; // $s1
// 		struct MultiSpline *spline; // $s2
/* end block 1.1.2 */
// End offset: 0x80033168
// End Line: 1090

/* begin block 1.1.3 */
// Start line: 1092
// Start offset: 0x80033168
// Variables:
// 		struct SavedIntroSmall *savedIntroSmall; // $v0

/* begin block 1.1.3.1 */
// Start line: 1106
// Start offset: 0x80033194
/* end block 1.1.3.1 */
// End offset: 0x800331BC
// End Line: 1113
/* end block 1.1.3 */
// End offset: 0x800331BC
// End Line: 1115
/* end block 1.1 */
// End offset: 0x800331C4
// End Line: 1131
/* end block 1 */
// End offset: 0x800331C8
// End Line: 1133

/* begin block 2 */
// Start line: 1739
/* end block 2 */
// End Line: 1740

_Instance *INSTANCE_IntroduceInstance(Intro *intro, short streamUnitID)

{
  long lVar1;
  INICommand *pIVar2;
  _ObjectTracker *objectTracker;
  _Instance *instance;
  INICommand introUniqueID;
  Object *object;

  lVar1 = INSTANCE_Introduced(intro, streamUnitID);
  if (lVar1 == 0)
  {
    introUniqueID = (INICommand)0x0;
    pIVar2 = INSTANCE_GetIntroCommand((INICommand *)intro->data, 0x1a);
    if (pIVar2 != (INICommand *)0x0)
    {
      introUniqueID = pIVar2[1];
    }
    objectTracker = STREAM_GetObjectTracker((char *)intro);
    if ((((objectTracker != (_ObjectTracker *)0x0) &&
          (object = objectTracker->object, objectTracker->objectStatus == 2)) &&
         ((introUniqueID == (INICommand)0x0 ||
           (instance = INSTANCE_Find((long)introUniqueID), instance != (_Instance *)0x0)))) &&
        ((((object->oflags2 & 0x10000000U) == 0 ||
           (OBTABLE_InitAnimPointers(objectTracker), (object->oflags2 & 0x10000000U) == 0)) &&
          (instance = INSTANCE_NewInstance(DAT_800d0fe0), instance != (_Instance *)0x0))))
    {
      intro->flags = intro->flags | 8;
      objectTracker->numInUse = objectTracker->numInUse + 1;
      INSTANCE_DefaultInit(instance, object, 0);
      /* WARNING: Subroutine does not return */
      strcpy(instance->introName, (char *)intro);
    }
  }
  return (_Instance *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_AdditionalCollideFunctions(struct _InstanceList *instanceList /*$a0*/)
// line 1138, offset 0x800331f0
/* begin block 1 */
// Start line: 1139
// Start offset: 0x800331F0
// Variables:
// 		struct _Instance *instance; // $s0
/* end block 1 */
// End offset: 0x80033300
// End Line: 1170

/* begin block 2 */
// Start line: 2429
/* end block 2 */
// End Line: 2430

void INSTANCE_AdditionalCollideFunctions(_InstanceList *instanceList)

{
  _Instance *p_Var1;

  p_Var1 = instanceList->first;
  while (p_Var1 != (_Instance *)0x0)
  {
    if ((((DAT_800d111e != 6) || ((p_Var1->object->oflags & 0x20000U) != 0)) &&
         (((DAT_800d10f0 & 0x100000) == 0 || ((p_Var1->object->oflags & 0x40000U) != 0)))) &&
        ((p_Var1->additionalCollideFunc != (_func_3 *)0x0 && ((p_Var1->flags2 & 0x24000000U) == 0))))
    {
      DAT_800d11ec = DAT_800d11f0;
      if ((p_Var1->object != (Object *)0x0) &&
          (((p_Var1->object->oflags2 & 0x2000000U) != 0 &&
            (DAT_800d11ec = ULONG_800d11f8, (p_Var1->flags2 & 0x8000000U) != 0))))
      {
        DAT_800d11ec = aadReverbModeSize;
      }
      (*p_Var1->additionalCollideFunc)(p_Var1, &gameTrackerX);
    }
    p_Var1 = p_Var1->next;
  }
  DAT_800d11ec = DAT_800d11f0;
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ INSTANCE_GetSplineFrameNumber(struct _Instance *instance /*$s0*/, struct MultiSpline *spline /*$a1*/)
// line 1173, offset 0x80033318
/* begin block 1 */
// Start line: 1174
// Start offset: 0x80033318
/* end block 1 */
// End offset: 0x80033318
// End Line: 1174

/* begin block 2 */
// Start line: 2520
/* end block 2 */
// End Line: 2521

long INSTANCE_GetSplineFrameNumber(_Instance *instance, MultiSpline *spline)

{
  SplineDef *splineDef;
  int iVar1;

  splineDef = SCRIPT_GetPosSplineDef(instance, spline, 0, 0);
  iVar1 = SCRIPT_GetSplineFrameNumber(instance, splineDef);
  return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_ProcessFunctions(struct _InstanceList *instanceList /*$a0*/)
// line 1186, offset 0x80033350
/* begin block 1 */
// Start line: 1187
// Start offset: 0x80033350

/* begin block 1.1 */
// Start line: 1193
// Start offset: 0x80033390
// Variables:
// 		struct _Instance *instance; // $s0

/* begin block 1.1.1 */
// Start line: 1215
// Start offset: 0x8003344C
// Variables:
// 		int hidden; // $s2
// 		int burning; // $s1
/* end block 1.1.1 */
// End offset: 0x80033500
// End Line: 1238

/* begin block 1.1.2 */
// Start line: 1264
// Start offset: 0x800335D0
// Variables:
// 		long prevFrame; // $s2
// 		struct MultiSpline *multi; // $s4

/* begin block 1.1.2.1 */
// Start line: 1271
// Start offset: 0x80033600
// Variables:
// 		long endOfSpline; // $s6
// 		short direction; // $s7

/* begin block 1.1.2.1.1 */
// Start line: 1310
// Start offset: 0x800336C0
// Variables:
// 		long frame; // $s3
// 		long maxFrames; // $s1
/* end block 1.1.2.1.1 */
// End offset: 0x80033900
// End Line: 1389

/* begin block 1.1.2.1.2 */
// Start line: 1400
// Start offset: 0x80033934
/* end block 1.1.2.1.2 */
// End offset: 0x80033958
// End Line: 1405
/* end block 1.1.2.1 */
// End offset: 0x80033AD0
// End Line: 1465
/* end block 1.1.2 */
// End offset: 0x80033AD0
// End Line: 1467

/* begin block 1.1.3 */
// Start line: 1490
// Start offset: 0x80033B14
// Variables:
// 		int killTest; // $s1
/* end block 1.1.3 */
// End offset: 0x80033B50
// End Line: 1497
/* end block 1.1 */
// End offset: 0x80033B84
// End Line: 1509
/* end block 1 */
// End offset: 0x80033BCC
// End Line: 1523

/* begin block 2 */
// Start line: 2550
/* end block 2 */
// End Line: 2551

void INSTANCE_ProcessFunctions(_InstanceList *instanceList)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  bool bVar5;
  short frameNum;
  uint uVar6;
  MultiSpline *multi;
  long lVar7;
  long lVar8;
  long lVar9;
  Spline *pSVar10;
  int iVar11;
  _Instance *instance;
  int iVar12;
  ushort uVar13;

  if ((vmRealClock & 0x8000010U) == 0)
  {
    if ((DAT_800d111e != 6) && ((DAT_800d10f0 & 0x100000) == 0))
    {
      DAT_800d10f0 = DAT_800d10f0 & 0xfffffffb;
    }
    instance = instanceList->first;
    while (instance != (_Instance *)0x0)
    {
      DAT_800d11ec = DAT_800d11f0;
      if (((instance->object != (Object *)0x0) && ((instance->object->oflags2 & 0x2000000U) != 0)) && (DAT_800d11ec = ULONG_800d11f8, (instance->flags2 & 0x8000000U) != 0))
      {
        DAT_800d11ec = aadReverbModeSize;
      }
      if ((instance->object->oflags2 & 4U) != 0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Query(instance, 2);
      }
      if (((((instance->intro == (Intro *)0x0) || ((instance->intro->flags & 0x100U) == 0)) &&
            ((DAT_800d111e != 6 || ((instance->object->oflags & 0x20000U) != 0)))) &&
           (((DAT_800d10f0 & 0x100000) == 0 || ((instance->object->oflags & 0x40000U) != 0)))) &&
          ((instance->flags2 & 0x10000000U) == 0))
      {
        frameNum = (instance->position).y;
        sVar1 = (instance->position).z;
        sVar2 = (instance->rotation).x;
        sVar3 = (instance->rotation).y;
        uVar6 = instance->flags;
        sVar4 = (instance->rotation).z;
        (instance->oldPos).x = (instance->position).x;
        (instance->oldPos).y = frameNum;
        (instance->oldPos).z = sVar1;
        (instance->oldRotation).x = sVar2;
        (instance->oldRotation).y = sVar3;
        (instance->oldRotation).z = sVar4;
        if ((((uVar6 & 0x100000) != 0) ||
             (multi = SCRIPT_GetMultiSpline(instance, (ulong *)0x0, (ulong *)0x0),
              multi == (MultiSpline *)0x0)) ||
            (uVar6 = instance->flags, (uVar6 & 0x2000000) == 0))
          goto LAB_80033ad0;
        uVar13 = 1;
        if ((uVar6 & 0x1000000) != 0)
        {
          uVar13 = 0xffff;
        }
        if ((instance->object->oflags & 0x10000000U) != 0)
        {
          instance->flags = uVar6 | 0x400;
          frameNum = SplineMultiIsWhere(multi);
          if (frameNum != 0)
          {
            if ((int)((uint)uVar13 << 0x10) < 1)
            {
              instance->intro->flags = instance->intro->flags & 0xfffff7ff;
            }
            else
            {
              instance->intro->flags = instance->intro->flags | 0x800;
            }
          }
        }
        lVar7 = INSTANCE_GetSplineFrameNumber(instance, multi);
        lVar8 = SCRIPT_InstanceSplineProcess(instance, &multi->curPositional, &multi->curRotational, &multi->curScaling,
                                             (int)(short)uVar13);
        if (instance->splineFlags == 0)
        {
          if ((vmClock & 0x400000U) != 0)
          {
            INSTANCE_GetSplineFrameNumber(instance, multi);
            FONT_Print(CD_cbread);
          }
        }
        else
        {
          lVar9 = INSTANCE_GetSplineFrameNumber(instance, multi);
          frameNum = SCRIPTCountFramesInSpline(instance);
          iVar12 = (int)frameNum;
          if ((instance->splineFlags & 1U) != 0)
          {
            if ((vmClock & 0x400000U) != 0)
            {
              printf(s_Spline__s_ld_playto__d_preveFram_800ce3b8);
            }
            if ((int)(short)uVar13 < 1)
            {
              iVar11 = (int)instance->targetFrame;
              if (lVar9 <= iVar11)
              {
                if (iVar11 <= lVar7)
                  goto LAB_800337a4;
                if (lVar7 < lVar9)
                {
                  bVar5 = lVar7 + iVar12 < iVar11;
                  goto LAB_8003379c;
                }
              }
            }
            else
            {
              if (iVar12 < lVar7)
              {
                lVar7 = iVar12;
              }
              iVar11 = (int)instance->targetFrame;
              if ((lVar9 < iVar11) || (iVar11 < lVar7))
              {
                if ((lVar9 < lVar7) && (lVar9 >= iVar11))
                {
                  bVar5 = iVar11 + iVar12 < lVar7;
                LAB_8003379c:
                  if (!bVar5)
                    goto LAB_800337a4;
                }
              }
              else
              {
              LAB_800337a4:
                instance->flags = instance->flags & 0xfdffffff;
                SCRIPT_InstanceSplineSet(instance, instance->targetFrame, (SplineDef *)0x0, (SplineDef *)0x0,
                                         (SplineDef *)0x0);
                lVar8 = 0;
                instance->splineFlags = instance->splineFlags & 0xfffe;
              }
            }
          }
          if ((instance->splineFlags & 2U) != 0)
          {
            if ((vmClock & 0x400000U) != 0)
            {
              FONT_Print(s_Spline__s_d___clip__d__d__prevFr_800ce408);
            }
            if (uVar13 == 1)
            {
              if (((lVar7 <= instance->clipEnd) && (instance->clipEnd <= lVar9)) ||
                  (lVar9 < instance->clipBeg))
              {
                if ((*(uint *)&multi->positional->numkeys & 0x6000000) == 0)
                {
                  frameNum = instance->clipEnd;
                LAB_8003390c:
                  lVar8 = 1;
                }
                else
                {
                  frameNum = instance->clipBeg;
                }
              LAB_80033910:
                SCRIPT_InstanceSplineSet(instance, frameNum, (SplineDef *)0x0, (SplineDef *)0x0, (SplineDef *)0x0);
              }
            }
            else
            {
              if (((instance->clipBeg <= lVar7) && (lVar9 <= instance->clipBeg)) ||
                  (instance->clipEnd < lVar9))
              {
                if ((*(uint *)&multi->positional->numkeys & 0x6000000) == 0)
                {
                  frameNum = instance->clipBeg;
                  goto LAB_8003390c;
                }
                frameNum = instance->clipEnd;
                goto LAB_80033910;
              }
            }
          }
        }
        if (lVar8 < 1)
        {
        LAB_80033ad0:
          if (instance->processFunc != (_func_1 *)0x0)
          {
            if ((instance->flags2 & 1U) == 0)
            {
              (*instance->processFunc)(instance, &gameTrackerX);
            }
            else
            {
              INSTANCE_DeactivatedProcess(instance, (GameTracker *)&gameTrackerX);
            }
          }
          iVar12 = (int)(instance->position).z - (int)(instance->oldPos).z;
          if (0x8000 < iVar12)
          {
            INSTANCE_PlainDeath(instance);
          }
          if (iVar12 < -0x8000)
          {
            INSTANCE_PlainDeath(instance);
          }
          /* WARNING: Subroutine does not return */
          INSTANCE_Query(instance, 0x2f);
        }
        if ((instance->object->oflags & 0x10000000U) != 0)
        {
          instance->flags = instance->flags & 0xfdfffbffU | 0x100000;
        }
        uVar6 = instance->object->oflags;
        if ((uVar6 & 0x2000) == 0)
        {
          if ((uVar6 & 0x1000) == 0)
          {
            if ((uVar6 & 0x1000000) != 0)
            {
              instance->flags = instance->flags & 0xfdffffff;
            }
          }
          else
          {
            instance->flags = instance->flags & 0xfdffffff;
            if ((instance->object->oflags & 0x800000U) != 0)
            {
              SCRIPT_InstanceSplineInit(instance);
            }
          }
          pSVar10 = multi->positional;
          if (((pSVar10 != (Spline *)0x0) ||
               (pSVar10 = (Spline *)multi->rotational, pSVar10 != (Spline *)0x0)) &&
              (((pSVar10->flags & 4) == 0 && ((instance->object->oflags & 0x800000U) == 0))))
          {
            instance->flags = instance->flags ^ 0x1000000;
          }
          if ((((instance->object->oflags & 0x200000U) != 0) &&
               ((int *)instance->introData != (int *)0x0)) &&
              (iVar12 = *(int *)instance->introData, iVar12 != 0))
          {
            SIGNAL_HandleSignal(instance, (Signal *)(iVar12 + 8), 0);
          }
          goto LAB_80033ad0;
        }
        instance->flags = instance->flags | 0x100000;
        INSTANCE_KillInstance(instance);
      }
      instance = instance->next;
    }
  }
  DAT_800d11ec = DAT_800d11f0;
  if (DAT_800d0fb4 != 1000)
  {
    DAT_800d10f0 = DAT_800d10f0 | 4;
  }
  iVar12 = VOICEXA_IsPlayingOrPaused();
  if (iVar12 != 0)
  {
    DAT_800d10f0 = DAT_800d10f0 | 4;
  }
  return;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ INSTANCE_BirthObject(struct _Instance *parent /*$s2*/, struct Object *object /*$s4*/, int modelNum /*$s1*/)
// line 1526, offset 0x80033bfc
/* begin block 1 */
// Start line: 1527
// Start offset: 0x80033BFC
// Variables:
// 		struct _Instance *instance; // $s0
// 		int i; // $s1
/* end block 1 */
// End offset: 0x80033E4C
// End Line: 1598

/* begin block 2 */
// Start line: 3577
/* end block 2 */
// End Line: 3578

_Instance *INSTANCE_BirthObject(_Instance *parent, Object *object, int modelNum)

{
  short sVar1;
  _GlobalSaveTracker *p_Var2;
  _Instance *instance;
  undefined4 uVar3;

  if ((object != (Object *)0x0) &&
      (instance = INSTANCE_NewInstance(DAT_800d0fe0), instance != (_Instance *)0x0))
  {
    INSTANCE_DefaultInit(instance, object, modelNum);
    sVar1 = (parent->position).z;
    *(undefined4 *)&instance->position = *(undefined4 *)&parent->position;
    (instance->position).z = sVar1;
    sVar1 = (instance->position).z;
    *(undefined4 *)&instance->initialPos = *(undefined4 *)&instance->position;
    (instance->initialPos).z = sVar1;
    sVar1 = (parent->position).z;
    *(undefined4 *)&instance->oldPos = *(undefined4 *)&parent->position;
    (instance->oldPos).z = sVar1;
    uVar3 = *(undefined4 *)&(parent->rotation).z;
    *(undefined4 *)&instance->rotation = *(undefined4 *)&parent->rotation;
    *(undefined4 *)&(instance->rotation).z = uVar3;
    uVar3 = *(undefined4 *)&(parent->scale).z;
    *(undefined4 *)&instance->scale = *(undefined4 *)&parent->scale;
    *(undefined4 *)&(instance->scale).z = uVar3;
    instance->lightGroup = parent->lightGroup;
    instance->spectralLightGroup = parent->spectralLightGroup;
    p_Var2 = GlobalSave;
    instance->currentStreamUnitID = parent->currentStreamUnitID;
    instance->birthStreamUnitID = parent->birthStreamUnitID;
    sVar1 = p_Var2->CurrentBirthID;
    p_Var2->CurrentBirthID = sVar1 + 1;
    instance->introUniqueID = (int)sVar1;
    /* WARNING: Subroutine does not return */
    strcpy(instance->introName, object->name);
  }
  return (_Instance *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_BuildStaticShadow(struct _Instance *instance /*$a0*/)
// line 1615, offset 0x80033e6c
/* begin block 1 */
// Start line: 3230
/* end block 1 */
// End Line: 3231

/* begin block 2 */
// Start line: 3761
/* end block 2 */
// End Line: 3762

void INSTANCE_BuildStaticShadow(_Instance *instance)

{
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_DefaultInit(struct _Instance *instance /*$s1*/, struct Object *object /*$s2*/, int modelNum /*$s0*/)
// line 1649, offset 0x80033e74
/* begin block 1 */
// Start line: 1650
// Start offset: 0x80033E74
// Variables:
// 		int i; // $t3
// 		int j; // $a3
// 		int numHPrims; // $a2
// 		int numModels; // $s0
// 		struct _HPrim *hprim; // $a2
// 		struct _Model **pModel; // $t7
// 		struct _HModel *hmodel; // $t8

/* begin block 1.1 */
// Start line: 1703
// Start offset: 0x80033FFC
// Variables:
// 		struct _Model *model; // $v0
// 		struct _Segment *seg; // $a1

/* begin block 1.1.1 */
// Start line: 1708
// Start offset: 0x80034014
// Variables:
// 		struct _HInfo *hinfo; // $a0
/* end block 1.1.1 */
// End offset: 0x8003403C
// End Line: 1712
/* end block 1.1 */
// End offset: 0x80034048
// End Line: 1713

/* begin block 1.2 */
// Start line: 1722
// Start offset: 0x800340A4
// Variables:
// 		struct _Model *model; // $s0
// 		struct _Segment *seg; // $t4

/* begin block 1.2.1 */
// Start line: 1733
// Start offset: 0x800340C0
// Variables:
// 		struct _HInfo *hinfo; // $a1

/* begin block 1.2.1.1 */
// Start line: 1737
// Start offset: 0x800340D0
// Variables:
// 		int k; // $v1
// 		struct _HFace *hface; // $t0
// 		struct _HSphere *hsphere; // $t1
// 		struct _HBox *hbox; // $t2
/* end block 1.2.1.1 */
// End offset: 0x800341B8
// End Line: 1776
/* end block 1.2.1 */
// End offset: 0x800341B8
// End Line: 1777
/* end block 1.2 */
// End offset: 0x800341D0
// End Line: 1778
/* end block 1 */
// End offset: 0x80034214
// End Line: 1790

/* begin block 2 */
// Start line: 3820
/* end block 2 */
// End Line: 3821

void INSTANCE_DefaultInit(_Instance *instance, Object *object, int modelNum)

{
  /* WARNING: Subroutine does not return */
  memset(&instance->flags, 0, 0x254);
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_PlainDeath(struct _Instance *instance /*$s5*/)
// line 1793, offset 0x80034230
/* begin block 1 */
// Start line: 1794
// Start offset: 0x80034230

/* begin block 1.1 */
// Start line: 1825
// Start offset: 0x800342FC
// Variables:
// 		struct _Instance *oldOn; // $a0
/* end block 1.1 */
// End offset: 0x80034324
// End Line: 1832
/* end block 1 */
// End offset: 0x80034324
// End Line: 1834

/* begin block 2 */
// Start line: 4267
/* end block 2 */
// End Line: 4268

void INSTANCE_PlainDeath(_Instance *instance)

{
  uint uVar1;
  _Instance *p_Var2;
  Object *pOVar3;

  pOVar3 = instance->object;
  instance->flags = instance->flags & 0xfffffbff;
  if ((pOVar3->oflags2 & 4U) != 0)
  {
    uVar1 = instance->flags2;
    instance->flags2 = uVar1 | 0x1000;
    SOUND_ProcessInstanceSounds(pOVar3->soundData, instance->soundInstanceTbl, &instance->position,
                                pOVar3->oflags2 & 0x2000000, uVar1 & 0x8000000, 0, 0, &instance->flags2);
    SOUND_ProcessInstanceSounds(instance->object->soundData, instance->soundInstanceTbl, &instance->position,
                                instance->object->oflags2 & 0x2000000, instance->flags2 & 0x8000000, 0, 0,
                                &instance->flags2);
  }
  p_Var2 = INSTANCE_Find(instance->attachedID);
  if (p_Var2 != (_Instance *)0x0)
  {
    p_Var2->flags2 = p_Var2->flags2 & 0xffffff7f;
  }
  SAVE_MarkDeadDead(instance);
  instance->flags = instance->flags | 0x20;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_KillInstance(struct _Instance *instance /*$a0*/)
// line 1838, offset 0x80034360
/* begin block 1 */
// Start line: 4364
/* end block 1 */
// End Line: 4365

void INSTANCE_KillInstance(_Instance *instance)

{
  if ((instance->flags & 0x20U) == 0)
  {
    INSTANCE_PlainDeath(instance);
  }
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ INSTANCE_Query(struct _Instance *Inst /*$a0*/, int Query /*$a1*/)
// line 1857, offset 0x80034394
/* begin block 1 */
// Start line: 1858
// Start offset: 0x80034394
// Variables:
// 		unsigned long (*Func)(); // $v0
/* end block 1 */
// End offset: 0x800343C0
// End Line: 1871

/* begin block 2 */
// Start line: 3714
/* end block 2 */
// End Line: 3715

ulong INSTANCE_Query(_Instance *Inst, int Query)

{
  ulong uVar1;

  if (Inst->queryFunc == (_func_4 *)0x0)
  {
    uVar1 = 0;
  }
  else
  {
    uVar1 = (*Inst->queryFunc)();
  }
  return uVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_Post(struct _Instance *Inst /*$s0*/, int Message /*$s2*/, int Data /*$s3*/)
// line 1875, offset 0x800343d0
/* begin block 1 */
// Start line: 1876
// Start offset: 0x800343D0
// Variables:
// 		void (*Func)(); // $s1
/* end block 1 */
// End offset: 0x80034418
// End Line: 1886

/* begin block 2 */
// Start line: 4430
/* end block 2 */
// End Line: 4431

void INSTANCE_Post(_Instance *Inst, int Message, int Data)

{
  _func_5 *p_Var1;

  p_Var1 = Inst->messageFunc;
  if (p_Var1 != (_func_5 *)0x0)
  {
    INSTANCE_ForceActive(Inst);
    (*p_Var1)(Inst, Message, Data);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_Broadcast(struct _Instance *sender /*$s2*/, long whatAmIMask /*$s3*/, int Message /*$s4*/, int Data /*$s5*/)
// line 1892, offset 0x80034434
/* begin block 1 */
// Start line: 1893
// Start offset: 0x80034434
// Variables:
// 		struct _Instance *instance; // $s0
// 		int plane; // $s1
/* end block 1 */
// End offset: 0x800344BC
// End Line: 1906

/* begin block 2 */
// Start line: 4468
/* end block 2 */
// End Line: 4469

/* begin block 3 */
// Start line: 4472
/* end block 3 */
// End Line: 4473

void INSTANCE_Broadcast(_Instance *sender, long whatAmIMask, int Message, int Data)

{
  _Instance *Inst;

  Inst = *(_Instance **)(DAT_800d0fe0 + 4);
  while (true)
  {
    if (Inst == (_Instance *)0x0)
    {
      return;
    }
    if (Inst != sender)
      break;
    Inst = Inst->next;
  }
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(Inst, 1);
}

// decompiled code
// original method signature:
// int /*$ra*/ INSTANCE_InPlane(struct _Instance *instance /*$a0*/, int plane /*$a1*/)
// line 1911, offset 0x800344e0
/* begin block 1 */
// Start line: 4518
/* end block 1 */
// End Line: 4519

/* begin block 2 */
// Start line: 4519
/* end block 2 */
// End Line: 4520

undefined4 INSTANCE_InPlane(int param_1, int param_2)

{
  if (*(int *)(param_1 + 0x1c) == 0)
  {
    return 0;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x1c) + 0x2c) & 0x2000000) != 0)
  {
    if ((*(uint *)(param_1 + 0x18) & 0x8000000) == 0)
    {
      if (param_2 != 0)
      {
        return 0;
      }
      return 1;
    }
    if (param_2 == 0)
    {
      return 0;
    }
  }
  return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ INSTANCE_FindWithID(long uniqueID /*$a0*/)
// line 1938, offset 0x8003453c
/* begin block 1 */
// Start line: 1940
// Start offset: 0x8003453C
// Variables:
// 		struct _Instance *instance; // $v1
// 		struct _Instance *next; // $v1
// 		long ret; // $a1
/* end block 1 */
// End offset: 0x80034574
// End Line: 1956

/* begin block 2 */
// Start line: 3876
/* end block 2 */
// End Line: 3877

/* begin block 3 */
// Start line: 4547
/* end block 3 */
// End Line: 4548

long INSTANCE_FindWithID(long uniqueID)

{
  int *piVar1;
  int iVar2;

  iVar2 = *(int *)(DAT_800d0fe0 + 4);
  do
  {
    if (iVar2 == 0)
    {
      return 0;
    }
    piVar1 = (int *)(iVar2 + 0x3c);
    iVar2 = *(int *)(iVar2 + 8);
  } while (*piVar1 != uniqueID);
  return 1;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ INSTANCE_FindWithName(long areaID /*$s3*/, char *instanceName /*$s4*/, struct _Instance *startInstance /*$a2*/)
// line 1995, offset 0x8003457c
/* begin block 1 */
// Start line: 1996
// Start offset: 0x8003457C
// Variables:
// 		struct _Instance *instance; // $s0
// 		struct _Instance *ret; // $s2
// 		struct _Instance *next; // $s1
/* end block 1 */
// End offset: 0x8003462C
// End Line: 2039

/* begin block 2 */
// Start line: 3990
/* end block 2 */
// End Line: 3991

/* begin block 3 */
// Start line: 4624
/* end block 3 */
// End Line: 4625

_Instance *INSTANCE_FindWithName(long areaID, char *instanceName, _Instance *startInstance)

{
  int *piVar1;
  char *s1;
  _Instance *p_Var2;

  p_Var2 = *(_Instance **)(DAT_800d0fe0 + 4);
  if (startInstance != (_Instance *)0x0)
  {
    p_Var2 = startInstance->next;
  }
  if (areaID == 0)
  {
    if (p_Var2 != (_Instance *)0x0)
    {
      /* WARNING: Subroutine does not return */
      strcmpi(p_Var2->introName, instanceName);
    }
  }
  else
  {
    while (p_Var2 != (_Instance *)0x0)
    {
      piVar1 = &p_Var2->birthStreamUnitID;
      s1 = p_Var2->introName;
      p_Var2 = p_Var2->next;
      if (*piVar1 == areaID)
      {
        /* WARNING: Subroutine does not return */
        strcmpi(s1, instanceName);
      }
    }
  }
  return (_Instance *)0x0;
}

// decompiled code
// original method signature:
// struct Intro * /*$ra*/ INSTANCE_FindIntro(long areaID /*$a0*/, long introUniqueID /*$s1*/)
// line 2065, offset 0x80034650
/* begin block 1 */
// Start line: 2066
// Start offset: 0x80034650
// Variables:
// 		struct Intro *ret; // $s0
// 		long i; // $a0
// 		struct Level *level; // $v1
/* end block 1 */
// End offset: 0x800346BC
// End Line: 2086

/* begin block 2 */
// Start line: 4130
/* end block 2 */
// End Line: 4131

Intro *INSTANCE_FindIntro(long areaID, long introUniqueID)

{
  /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(areaID);
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ INSTANCE_Find(long introUniqueID /*$a0*/)
// line 2090, offset 0x800346d4
/* begin block 1 */
// Start line: 2092
// Start offset: 0x800346D4
// Variables:
// 		struct _Instance *instance; // $v1
/* end block 1 */
// End offset: 0x8003470C
// End Line: 2098

/* begin block 2 */
// Start line: 4810
/* end block 2 */
// End Line: 4811

/* begin block 3 */
// Start line: 4811
/* end block 3 */
// End Line: 4812

/* begin block 4 */
// Start line: 4813
/* end block 4 */
// End Line: 4814

_Instance *INSTANCE_Find(long introUniqueID)

{
  _Instance *p_Var1;

  p_Var1 = *(_Instance **)(DAT_800d0fe0 + 4);
  while ((p_Var1 != (_Instance *)0x0 && (p_Var1->introUniqueID != introUniqueID)))
  {
    p_Var1 = p_Var1->next;
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ INSTANCE_IntroduceSavedInstance(struct _SavedIntro *savedIntro /*$s2*/, struct _StreamUnit *streamUnit /*$a1*/, int *deleted /*$fp*/)
// line 2102, offset 0x80034714
/* begin block 1 */
// Start line: 2103
// Start offset: 0x80034714
// Variables:
// 		struct _ObjectTracker *objectTracker; // $s1
// 		struct Object *object; // $s7
// 		struct _Instance *instance; // $s0
// 		struct _Position *levelOffset; // $s5
// 		struct Level *level; // $v0
// 		struct _Instance *attachInst; // $s4

/* begin block 1.1 */
// Start line: 2119
// Start offset: 0x80034770
// Variables:
// 		char savedName[12]; // stack offset -56

/* begin block 1.1.1 */
// Start line: 2147
// Start offset: 0x80034838
// Variables:
// 		struct Level *birthLevel; // $v0
// 		struct Intro *oldIntro; // $s1
// 		int nosave; // $s3
// 		int remove; // $s1

/* begin block 1.1.1.1 */
// Start line: 2173
// Start offset: 0x80034898
// Variables:
// 		struct Intro *intro; // $v1
// 		int i; // $a0
/* end block 1.1.1.1 */
// End offset: 0x800348CC
// End Line: 2184

/* begin block 1.1.1.2 */
// Start line: 2201
// Start offset: 0x800348F4
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
// End offset: 0x800348F4
// End Line: 2201

/* begin block 1.1.1.3 */
// Start line: 2283
// Start offset: 0x80034ADC
/* end block 1.1.1.3 */
// End offset: 0x80034AF8
// End Line: 2294
/* end block 1.1.1 */
// End offset: 0x80034B2C
// End Line: 2303
/* end block 1.1 */
// End offset: 0x80034B58
// End Line: 2315
/* end block 1 */
// End offset: 0x80034B58
// End Line: 2324

/* begin block 2 */
// Start line: 4835
/* end block 2 */
// End Line: 4836

_Instance *
INSTANCE_IntroduceSavedInstance(_SavedIntro *savedIntro, _StreamUnit *streamUnit, int *deleted)

{
  long lVar1;

  lVar1 = INSTANCE_FindWithID((int)savedIntro->introUniqueID);
  if (lVar1 == 0)
  {
    /* WARNING: Subroutine does not return */
    LOAD_SetSearchDirectory((int)savedIntro->birthUnitID);
  }
  return (_Instance *)0x0;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ INSTANCE_IntroduceSavedInstanceWithIntro(struct _SavedIntroWithIntro *savedIntro /*$s4*/, struct _StreamUnit *streamUnit /*$s6*/, int *deleted /*stack 8*/)
// line 2327, offset 0x80034b8c
/* begin block 1 */
// Start line: 2328
// Start offset: 0x80034B8C
// Variables:
// 		struct _ObjectTracker *objectTracker; // $s1
// 		struct Object *object; // $s7
// 		struct _Instance *instance; // $s0
// 		struct _Position *levelOffset; // $fp
// 		struct Level *level; // $v1
// 		struct Intro *intro; // $s2
// 		struct _Instance *attachedInst; // $s5

/* begin block 1.1 */
// Start line: 2372
// Start offset: 0x80034CC4
// Variables:
// 		int remove; // $s1
// 		int nosave; // $s2

/* begin block 1.1.1 */
// Start line: 2376
// Start offset: 0x80034CC4
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
// End offset: 0x80034CC4
// End Line: 2376

/* begin block 1.1.2 */
// Start line: 2513
// Start offset: 0x80034F4C
/* end block 1.1.2 */
// End offset: 0x80034F68
// End Line: 2524
/* end block 1.1 */
// End offset: 0x80034F9C
// End Line: 2533
/* end block 1 */
// End offset: 0x80034FCC
// End Line: 2549

/* begin block 2 */
// Start line: 5380
/* end block 2 */
// End Line: 5381

_Instance *
INSTANCE_IntroduceSavedInstanceWithIntro(_SavedIntroWithIntro *savedIntro, _StreamUnit *streamUnit, int *deleted)

{
  long lVar1;

  lVar1 = INSTANCE_FindWithID(streamUnit->level->introList[savedIntro->introOffset].UniqueID);
  if (lVar1 == 0)
  {
    /* WARNING: Subroutine does not return */
    LOAD_SetSearchDirectory(streamUnit->StreamUnitID);
  }
  return (_Instance *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_SpatialRelationships(struct _InstanceList *instanceList /*$s4*/)
// line 2596, offset 0x80035000
/* begin block 1 */
// Start line: 2597
// Start offset: 0x80035000
// Variables:
// 		struct _Instance *instance; // $s1
// 		struct _Instance *checkee; // $s0

/* begin block 1.1 */
// Start line: 2606
// Start offset: 0x8003504C
// Variables:
// 		struct MATRIX *lookMatrix; // $s0
// 		long checkMask; // $s3

/* begin block 1.1.1 */
// Start line: 2615
// Start offset: 0x80035074
// Variables:
// 		struct MATRIX invMatrix; // stack offset -80

/* begin block 1.1.1.1 */
// Start line: 2624
// Start offset: 0x800350D0
// Variables:
// 		struct evCollideInstanceStatsData data; // stack offset -48
// 		struct MATRIX *mat; // $a2
/* end block 1.1.1.1 */
// End offset: 0x80035124
// End Line: 2634
/* end block 1.1.1 */
// End offset: 0x80035134
// End Line: 2636
/* end block 1.1 */
// End offset: 0x80035134
// End Line: 2637
/* end block 1 */
// End offset: 0x80035144
// End Line: 2639

/* begin block 2 */
// Start line: 5192
/* end block 2 */
// End Line: 5193

void INSTANCE_SpatialRelationships(_InstanceList *instanceList)

{
  _Instance *Inst;

  Inst = instanceList->first;
  while (true)
  {
    if (Inst == (_Instance *)0x0)
    {
      return;
    }
    if ((Inst->flags2 & 0x10000401U) == 0x400)
      break;
    Inst = Inst->next;
  }
  /* WARNING: Subroutine does not return */
  INSTANCE_Query(Inst, 0xd);
}

// decompiled code
// original method signature:
// int /*$ra*/ INSTANCE_SetStatsData(struct _Instance *instance /*$s1*/, struct _Instance *checkee /*$s5*/, struct _Vector *checkPoint /*$s2*/, struct evCollideInstanceStatsData *data /*$s3*/, struct MATRIX *mat /*stack 16*/)
// line 2643, offset 0x80035164
/* begin block 1 */
// Start line: 2644
// Start offset: 0x80035164
// Variables:
// 		long distance; // $s4

/* begin block 1.1 */
// Start line: 2649
// Start offset: 0x800351D0
// Variables:
// 		struct SVECTOR *delta; // $s0
/* end block 1.1 */
// End offset: 0x800351D8
// End Line: 2666
/* end block 1 */
// End offset: 0x80035250
// End Line: 2668

/* begin block 2 */
// Start line: 6097
/* end block 2 */
// End Line: 6098

void INSTANCE_SetStatsData(int param_1, undefined4 param_2, int *param_3)

{
  /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)*(short *)(param_1 + 0x5c) - *param_3,
                   (int)*(short *)(param_1 + 0x5e) - param_3[1],
                   (int)*(short *)(param_1 + 0x60) - param_3[2]);
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_LinkToParent(struct _Instance *instance /*$s0*/, struct _Instance *parent /*$s1*/, int node /*$a2*/)
// line 2672, offset 0x80035274
/* begin block 1 */
// Start line: 6180
/* end block 1 */
// End Line: 6181

void INSTANCE_LinkToParent(_Instance *instance, _Instance *parent, int node)

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
  /* WARNING: Subroutine does not return */
  INSTANCE_Post(parent, (int)&DAT_00100012, (int)instance);
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_UnlinkFromParent(struct _Instance *instance /*$s0*/)
// line 2693, offset 0x80035330
/* begin block 1 */
// Start line: 2694
// Start offset: 0x80035330
// Variables:
// 		struct _Instance *parent; // $s1

/* begin block 1.1 */
// Start line: 2698
// Start offset: 0x80035354
// Variables:
// 		struct _G2EulerAngles_Type ea; // stack offset -24

/* begin block 1.1.1 */
// Start line: 2706
// Start offset: 0x80035370
// Variables:
// 		struct _Instance *sibling; // $v1
/* end block 1.1.1 */
// End offset: 0x800353A4
// End Line: 2712
/* end block 1.1 */
// End offset: 0x80035480
// End Line: 2732
/* end block 1 */
// End offset: 0x80035480
// End Line: 2733

/* begin block 2 */
// Start line: 6228
/* end block 2 */
// End Line: 6229

void INSTANCE_UnlinkFromParent(_Instance *instance)

{
  short sVar1;
  _Instance *p_Var2;
  _Instance *p_Var3;
  _Instance *Inst;
  int iVar4;
  _G2EulerAngles_Type local_18;

  Inst = instance->LinkParent;
  if (Inst == (_Instance *)0x0)
  {
    return;
  }
  p_Var2 = Inst->LinkChild;
  if (p_Var2 == instance)
  {
    Inst->LinkChild = instance->LinkSibling;
  }
  else
  {
    p_Var3 = p_Var2->LinkSibling;
    while (p_Var3 != instance)
    {
      p_Var2 = p_Var2->LinkSibling;
      p_Var3 = p_Var2->LinkSibling;
    }
    p_Var2->LinkSibling = instance->LinkSibling;
  }
  sVar1 = (instance->scale).x;
  instance->LinkSibling = (_Instance *)0x0;
  instance->LinkParent = (_Instance *)0x0;
  iVar4 = (int)sVar1 * (int)(Inst->scale).x;
  if (iVar4 < 0)
  {
    iVar4 = iVar4 + 0xfff;
  }
  (instance->scale).x = (short)(iVar4 >> 0xc);
  iVar4 = (int)(instance->scale).y * (int)(Inst->scale).y;
  if (iVar4 < 0)
  {
    iVar4 = iVar4 + 0xfff;
  }
  (instance->scale).y = (short)(iVar4 >> 0xc);
  iVar4 = (int)(instance->scale).z * (int)(Inst->scale).z;
  if (iVar4 < 0)
  {
    iVar4 = iVar4 + 0xfff;
  }
  (instance->scale).z = (short)(iVar4 >> 0xc);
  if (Inst->matrix != (MATRIX *)0x0)
  {
    G2EulerAngles_FromMatrix(&local_18, (_G2Matrix_Type *)(Inst->matrix + instance->ParentLinkNode), 0x15);
    (instance->rotation).x = local_18.x;
    (instance->rotation).y = local_18.y;
    (instance->rotation).z = local_18.z;
  }
  /* WARNING: Subroutine does not return */
  INSTANCE_Post(Inst, (int)&DAT_00100013, (int)instance);
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_UnlinkChildren(struct _Instance *instance /*$s2*/)
// line 2735, offset 0x80035494
/* begin block 1 */
// Start line: 2736
// Start offset: 0x80035494
// Variables:
// 		struct _Instance *child; // $s1

/* begin block 1.1 */
// Start line: 2741
// Start offset: 0x800354BC
// Variables:
// 		struct _Instance *sibling; // $s0
/* end block 1.1 */
// End offset: 0x800354BC
// End Line: 2741
/* end block 1 */
// End offset: 0x800354E4
// End Line: 2752

/* begin block 2 */
// Start line: 6317
/* end block 2 */
// End Line: 6318

void INSTANCE_UnlinkChildren(_Instance *instance)

{
  if (instance->LinkChild != (_Instance *)0x0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(instance, (int)&DAT_00100013, (int)instance->LinkChild);
  }
  instance->LinkChild = (_Instance *)0x0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_UpdateFamilyStreamUnitID(struct _Instance *instance /*$s1*/)
// line 2758, offset 0x80035500
/* begin block 1 */
// Start line: 2759
// Start offset: 0x80035500
// Variables:
// 		struct _Instance *child; // $s0
/* end block 1 */
// End offset: 0x80035544
// End Line: 2767

/* begin block 2 */
// Start line: 6366
/* end block 2 */
// End Line: 6367

void INSTANCE_UpdateFamilyStreamUnitID(_Instance *instance)

{
  _Instance *instance_00;

  instance_00 = instance->LinkChild;
  while (instance_00 != (_Instance *)0x0)
  {
    instance_00->currentStreamUnitID = instance->currentStreamUnitID;
    INSTANCE_UpdateFamilyStreamUnitID(instance_00);
    instance_00 = instance_00->LinkSibling;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ INSTANCE_ReallyRemoveAllChildren(struct _Instance *instance /*$a0*/)
// line 2769, offset 0x80035558
/* begin block 1 */
// Start line: 2770
// Start offset: 0x80035558
// Variables:
// 		struct _Instance *child; // $s1

/* begin block 1.1 */
// Start line: 2775
// Start offset: 0x80035578
// Variables:
// 		struct _Instance *sibling; // $s0
/* end block 1.1 */
// End offset: 0x80035578
// End Line: 2775
/* end block 1 */
// End offset: 0x800355A0
// End Line: 2780

/* begin block 2 */
// Start line: 6391
/* end block 2 */
// End Line: 6392

void INSTANCE_ReallyRemoveAllChildren(_Instance *instance)

{
  _Instance *instance_00;
  _Instance *p_Var1;

  instance_00 = instance->LinkChild;
  while (instance_00 != (_Instance *)0x0)
  {
    p_Var1 = instance_00->LinkSibling;
    INSTANCE_ReallyRemoveAllChildren(instance_00);
    INSTANCE_ReallyRemoveInstance(DAT_800d0fe0, instance_00, 0);
    instance_00 = p_Var1;
  }
  return;
}

// decompiled code
// original method signature:
// struct _Instance * /*$ra*/ INSTANCE_GetChildLinkedToSegment(struct _Instance *instance /*$a0*/, int segment /*$a1*/)
// line 2785, offset 0x800355b4
/* begin block 1 */
// Start line: 2787
// Start offset: 0x800355B4
// Variables:
// 		struct _Instance *child; // $v1
/* end block 1 */
// End offset: 0x800355E4
// End Line: 2795

/* begin block 2 */
// Start line: 6428
/* end block 2 */
// End Line: 6429

/* begin block 3 */
// Start line: 6429
/* end block 3 */
// End Line: 6430

/* begin block 4 */
// Start line: 6431
/* end block 4 */
// End Line: 6432

_Instance *INSTANCE_GetChildLinkedToSegment(_Instance *instance, int segment)

{
  _Instance *p_Var1;

  p_Var1 = instance->LinkChild;
  while ((p_Var1 != (_Instance *)0x0 && (p_Var1->ParentLinkNode != segment)))
  {
    p_Var1 = p_Var1->LinkSibling;
  }
  return p_Var1;
}

// decompiled code
// original method signature:
// int /*$ra*/ INSTANCE_Linked(struct _Instance *instance1 /*$a0*/, struct _Instance *instance2 /*$a1*/)
// line 2801, offset 0x800355ec
/* begin block 1 */
// Start line: 2803
// Start offset: 0x800355EC
// Variables:
// 		struct _Instance *root1; // $a0
// 		struct _Instance *root2; // $a1
/* end block 1 */
// End offset: 0x80035634
// End Line: 2811

/* begin block 2 */
// Start line: 6462
/* end block 2 */
// End Line: 6463

/* begin block 3 */
// Start line: 6463
/* end block 3 */
// End Line: 6464

/* begin block 4 */
// Start line: 6465
/* end block 4 */
// End Line: 6466

int INSTANCE_Linked(_Instance *instance1, _Instance *instance2)

{
  _Instance *p_Var1;

  p_Var1 = instance1->LinkParent;
  while (p_Var1 != (_Instance *)0x0)
  {
    instance1 = instance1->LinkParent;
    p_Var1 = instance1->LinkParent;
  }
  while (instance2->LinkParent != (_Instance *)0x0)
  {
    instance2 = instance2->LinkParent;
  }
  return (uint)(instance1 == instance2);
}

// decompiled code
// original method signature:
// int /*$ra*/ INSTANCE_GetFadeValue(struct _Instance *instance /*$s1*/)
// line 2819, offset 0x8003563c
/* begin block 1 */
// Start line: 2820
// Start offset: 0x8003563C
// Variables:
// 		int fadeValue; // $s0
/* end block 1 */
// End offset: 0x80035708
// End Line: 2844

/* begin block 2 */
// Start line: 6498
/* end block 2 */
// End Line: 6499

int INSTANCE_GetFadeValue(_Instance *instance)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int iVar4;

  iVar3 = (int)instance->fadeValue;
  if (DAT_800d0fb4 != 1000)
  {
    iVar3 = 0x1000 - iVar3;
    lVar2 = MEMPACK_MemoryValidFunc((char *)instance->object);
    if ((lVar2 != 0) &&
        (((instance->object->oflags2 & 0x2000000U) != 0 ||
          ((instance->LinkParent != (_Instance *)0x0 &&
            ((instance->LinkParent->object->oflags2 & 0x2000000U) != 0))))))
    {
      sVar1 = DAT_800d11d2;
      if ((instance->flags2 & 0x8000000U) != 0)
      {
        sVar1 = DAT_800d11d0;
      }
      iVar4 = sVar1 * iVar3;
      iVar3 = iVar4 >> 0xc;
      if (iVar4 < 0)
      {
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
// line 2855, offset 0x80035720
/* begin block 1 */
// Start line: 2856
// Start offset: 0x80035720
// Variables:
// 		struct _AnimSoundData_Type *soundData; // $s2

/* begin block 1.1 */
// Start line: 2868
// Start offset: 0x80035770
// Variables:
// 		int id; // $s0
// 		int vol; // $s1
/* end block 1.1 */
// End offset: 0x800357D0
// End Line: 2877
/* end block 1 */
// End offset: 0x80035804
// End Line: 2891

/* begin block 2 */
// Start line: 6574
/* end block 2 */
// End Line: 6575

ulong INSTANCE_DefaultAnimCallback(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message, long messageDataA,
                                   long messageDataB, _Instance *instance)

{
  int iVar1;
  int iVar2;
  int maxVolume;

  if (message == G2ANIM_MSG_PLAYEFFECT)
  {
    if (messageDataA == 0)
    {
      if (messageDataB != 0)
      {
        maxVolume = (int)*(short *)(messageDataB + 2);
        if (999 < maxVolume)
        {
          iVar1 = maxVolume / 1000;
          maxVolume = maxVolume % 1000;
          iVar2 = HUMAN_TypeOfHuman(instance);
          if (iVar1 != iVar2)
          {
            return 0;
          }
        }
        SOUND_Play3dSound(&instance->position, (int)*(short *)messageDataB,
                          (int)*(short *)(messageDataB + 4), maxVolume,
                          (int)*(short *)(messageDataB + 6));
      }
    }
    else
    {
      if (messageDataA == 1)
      {
        FX_StartInstanceEffect(instance, (ObjectEffect *)messageDataB, 0);
      }
    }
  }
  return messageDataA;
}
