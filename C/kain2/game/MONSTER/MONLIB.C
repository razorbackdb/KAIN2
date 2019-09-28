#include "THISDUST.H"
#include "MONLIB.H"

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOffWeaponSpheres(struct _Instance *instance /*$s1*/)
// line 148, offset 0x8007f3e4
/* begin block 1 */
// Start line: 149
// Start offset: 0x8007F3E4
// Variables:
// 		struct _MonsterVars *mv; // $s2

/* begin block 1.1 */
// Start line: 153
// Start offset: 0x8007F40C
// Variables:
// 		struct _Instance *weapon; // $s0
/* end block 1.1 */
// End offset: 0x8007F42C
// End Line: 157

/* begin block 1.2 */
// Start line: 160
// Start offset: 0x8007F440
// Variables:
// 		int i; // $a1
// 		struct _HPrim *hprim; // $v1
// 		struct _HModel *hmodel; // $v1
/* end block 1.2 */
// End offset: 0x8007F4C4
// End Line: 168
/* end block 1 */
// End offset: 0x8007F4C4
// End Line: 169

/* begin block 2 */
// Start line: 296
/* end block 2 */
// End Line: 297

void MON_TurnOffWeaponSpheres(_Instance *instance)

{
  _HPrim *p_Var1;
  _Instance *instance_00;
  int *piVar2;
  int iVar3;
  uint *puVar4;

  instance_00 = instance->LinkChild;
  puVar4 = (uint *)instance->extraData;
  while (instance_00 != (_Instance *)0x0)
  {
    TurnOffCollisionPhysOb(instance_00, 3);
    instance_00 = instance_00->LinkSibling;
  }
  if ((*puVar4 & 0x4000) != 0)
  {
    iVar3 = instance->hModelList[instance->currentModel].numHPrims;
    p_Var1 = instance->hModelList[instance->currentModel].hPrimList;
    if (iVar3 != 0)
    {
      piVar2 = &p_Var1->data;
      do
      {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\t'))
        {
          p_Var1->hpFlags = p_Var1->hpFlags & 0xfe;
        }
        iVar3 = iVar3 + -1;
        piVar2 = piVar2 + 2;
        p_Var1 = p_Var1 + 1;
      } while (iVar3 != 0);
    }
    *puVar4 = *puVar4 & 0xffffbfff;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOnWeaponSpheres(struct _Instance *instance /*$a0*/)
// line 174, offset 0x8007f4dc
/* begin block 1 */
// Start line: 176
// Start offset: 0x8007F4DC
// Variables:
// 		struct _MonsterVars *mv; // $a2

/* begin block 1.1 */
// Start line: 179
// Start offset: 0x8007F508
// Variables:
// 		int i; // $a1
// 		struct _HPrim *hprim; // $a0
// 		struct _HModel *hmodel; // $v0
/* end block 1.1 */
// End offset: 0x8007F58C
// End Line: 191
/* end block 1 */
// End offset: 0x8007F58C
// End Line: 192

/* begin block 2 */
// Start line: 352
/* end block 2 */
// End Line: 353

/* begin block 3 */
// Start line: 353
/* end block 3 */
// End Line: 354

void MON_TurnOnWeaponSpheres(_Instance *instance)

{
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  uint *puVar5;

  puVar5 = (uint *)instance->extraData;
  if (((*puVar5 & 0x4000) == 0) && (instance->hModelList != (_HModel *)0x0))
  {
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0)
    {
      piVar2 = &p_Var3->data;
      do
      {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\t'))
        {
          p_Var3->hpFlags = p_Var3->hpFlags | 1;
          break;
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 2;
        p_Var3 = p_Var3 + 1;
      } while (iVar4 != 0);
    }
    *puVar5 = *puVar5 | 0x4000;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOnWeaponSphere(struct _Instance *instance /*$a0*/, int segment /*$a1*/)
// line 198, offset 0x8007f594
/* begin block 1 */
// Start line: 199
// Start offset: 0x8007F594
// Variables:
// 		struct _MonsterVars *mv; // $s0

/* begin block 1.1 */
// Start line: 204
// Start offset: 0x8007F5B0
// Variables:
// 		struct _Instance *weapon; // $v0
/* end block 1.1 */
// End offset: 0x8007F5C0
// End Line: 208

/* begin block 1.2 */
// Start line: 214
// Start offset: 0x8007F5F8
// Variables:
// 		int i; // $a2
// 		struct _HPrim *hprim; // $a0
// 		struct _HModel *hmodel; // $v0
/* end block 1.2 */
// End offset: 0x8007F68C
// End Line: 223
/* end block 1 */
// End offset: 0x8007F68C
// End Line: 224

/* begin block 2 */
// Start line: 404
/* end block 2 */
// End Line: 405

void MON_TurnOnWeaponSphere(_Instance *instance, int segment)

{
  _Instance *instance_00;
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  uint *puVar5;

  puVar5 = (uint *)instance->extraData;
  if (instance->LinkChild == (_Instance *)0x0)
  {
    if ((*puVar5 & 0x4000) != 0)
    {
      return;
    }
    if (instance->hModelList == (_HModel *)0x0)
    {
      return;
    }
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0)
    {
      piVar2 = &p_Var3->data;
      do
      {
        if ((((uint) * (byte *)((int)piVar2 + -1) == segment) &&
             (*(char *)((int)piVar2 + -2) == '\x01')) &&
            (*(char *)(*piVar2 + 4) == '\t'))
        {
          p_Var3->hpFlags = p_Var3->hpFlags | 1;
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 2;
        p_Var3 = p_Var3 + 1;
      } while (iVar4 != 0);
    }
  }
  else
  {
    instance_00 = INSTANCE_GetChildLinkedToSegment(instance, segment);
    if (instance_00 == (_Instance *)0x0)
    {
      return;
    }
    TurnOnCollisionPhysOb(instance_00, 3);
  }
  *puVar5 = *puVar5 | 0x4000;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOffBodySpheres(struct _Instance *instance /*$a0*/)
// line 229, offset 0x8007f69c
/* begin block 1 */
// Start line: 231
// Start offset: 0x8007F69C
// Variables:
// 		struct _MonsterVars *mv; // $a2

/* begin block 1.1 */
// Start line: 234
// Start offset: 0x8007F6B8
// Variables:
// 		int i; // $a1
// 		struct _HPrim *hprim; // $v1
// 		struct _HModel *hmodel; // $v1
/* end block 1.1 */
// End offset: 0x8007F73C
// End Line: 242
/* end block 1 */
// End offset: 0x8007F73C
// End Line: 243

/* begin block 2 */
// Start line: 470
/* end block 2 */
// End Line: 471

/* begin block 3 */
// Start line: 471
/* end block 3 */
// End Line: 472

void MON_TurnOffBodySpheres(_Instance *instance)

{
  _HPrim *p_Var1;
  int *piVar2;
  int iVar3;
  uint *puVar4;

  puVar4 = (uint *)instance->extraData;
  if ((*puVar4 & 0x8000) != 0)
  {
    iVar3 = instance->hModelList[instance->currentModel].numHPrims;
    p_Var1 = instance->hModelList[instance->currentModel].hPrimList;
    if (iVar3 != 0)
    {
      piVar2 = &p_Var1->data;
      do
      {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\b'))
        {
          p_Var1->hpFlags = p_Var1->hpFlags & 0xfe;
        }
        iVar3 = iVar3 + -1;
        piVar2 = piVar2 + 2;
        p_Var1 = p_Var1 + 1;
      } while (iVar3 != 0);
    }
    *puVar4 = *puVar4 & 0xffff7fff;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOnBodySpheres(struct _Instance *instance /*$a0*/)
// line 248, offset 0x8007f744
/* begin block 1 */
// Start line: 250
// Start offset: 0x8007F744
// Variables:
// 		struct _MonsterVars *mv; // $a2

/* begin block 1.1 */
// Start line: 253
// Start offset: 0x8007F770
// Variables:
// 		int i; // $a1
// 		struct _HPrim *hprim; // $a0
// 		struct _HModel *hmodel; // $v0
/* end block 1.1 */
// End offset: 0x8007F7F0
// End Line: 261
/* end block 1 */
// End offset: 0x8007F7F0
// End Line: 262

/* begin block 2 */
// Start line: 510
/* end block 2 */
// End Line: 511

/* begin block 3 */
// Start line: 511
/* end block 3 */
// End Line: 512

void MON_TurnOnBodySpheres(_Instance *instance)

{
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  uint *puVar5;

  puVar5 = (uint *)instance->extraData;
  if (((*puVar5 & 0x8000) == 0) && (instance->hModelList != (_HModel *)0x0))
  {
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0)
    {
      piVar2 = &p_Var3->data;
      do
      {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\b'))
        {
          p_Var3->hpFlags = p_Var3->hpFlags | 1;
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 2;
        p_Var3 = p_Var3 + 1;
      } while (iVar4 != 0);
    }
    *puVar5 = *puVar5 | 0x8000;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOffAllSpheres(struct _Instance *instance /*$s0*/)
// line 267, offset 0x8007f7f8
/* begin block 1 */
// Start line: 550
/* end block 1 */
// End Line: 551

void MON_TurnOffAllSpheres(_Instance *instance)

{
  MON_TurnOffWeaponSpheres(instance);
  MON_TurnOffBodySpheres(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOnAllSpheres(struct _Instance *instance /*$s0*/)
// line 276, offset 0x8007f824
/* begin block 1 */
// Start line: 568
/* end block 1 */
// End Line: 569

void MON_TurnOnAllSpheres(_Instance *instance)

{
  MON_TurnOnWeaponSpheres(instance);
  MON_TurnOnBodySpheres(instance);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SwitchState(struct _Instance *instance /*$s2*/, enum MonsterState state /*$s1*/)
// line 318, offset 0x8007f850
/* begin block 1 */
// Start line: 319
// Start offset: 0x8007F850
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8007F934
// End Line: 357

/* begin block 2 */
// Start line: 636
/* end block 2 */
// End Line: 637

void MON_SwitchState(_Instance *instance, MonsterState state)

{
  int in_a1;
  uint *puVar1;

  puVar1 = (uint *)instance->extraData;
  if ((*puVar1 & 0x4000) != 0)
  {
    MON_TurnOffWeaponSpheres(instance);
  }
  if ((*puVar1 & 1) == 0)
  {
    *(undefined *)((int)puVar1 + 0x145) = *(undefined *)&instance->currentMainState;
  }
  if ((((in_a1 == 0x10) || (in_a1 == 0x17)) || (in_a1 == 7)) || ((in_a1 == 10 || (in_a1 == 3))))
  {
    PurgeMessageQueue((__MessageQueue *)(puVar1 + 2));
  }
  instance->currentMainState = in_a1;
  *puVar1 = *puVar1 & 0xbbfdefff | 1;
  if ((int)*(char *)((int)puVar1 + 0x152) != -1)
  {
    ENMYPLAN_ReleasePlanningWorkspace((int)*(char *)((int)puVar1 + 0x152));
    *(undefined *)((int)puVar1 + 0x152) = 0xff;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SwitchStateDoEntry(struct _Instance *instance /*$s1*/, enum MonsterState state /*$a1*/)
// line 360, offset 0x8007f94c
/* begin block 1 */
// Start line: 361
// Start offset: 0x8007F94C
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8007F9A0
// End Line: 376

/* begin block 2 */
// Start line: 707
/* end block 2 */
// End Line: 708

void MON_SwitchStateDoEntry(_Instance *instance, MonsterState state)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;

  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_TransNodeAnimation(struct _Instance *instance /*$a0*/)
// line 388, offset 0x8007f9b4
/* begin block 1 */
// Start line: 763
/* end block 1 */
// End Line: 764

int MON_TransNodeAnimation(_Instance *instance)

{
  _G2Bool_Enum _Var1;

  _Var1 = G2Anim_SegmentHasActiveChannels(&instance->anim, 0, 0x700);
  return _Var1;
}

// decompiled code
// original method signature:
// struct _MonsterAnim * /*$ra*/ MON_GetAnim(struct _Instance *instance /*$a0*/, char *animList /*$a1*/, int index /*$a2*/)
// line 397, offset 0x8007f9dc
/* begin block 1 */
// Start line: 399
// Start offset: 0x8007F9DC
// Variables:
// 		int whichAnim; // $a1
/* end block 1 */
// End offset: 0x8007FA08
// End Line: 404

/* begin block 2 */
// Start line: 782
/* end block 2 */
// End Line: 783

/* begin block 3 */
// Start line: 783
/* end block 3 */
// End Line: 784

_MonsterAnim *MON_GetAnim(_Instance *instance, char *animList, int index)

{
  if ((int)animList[index] != -1)
  {
    return (_MonsterAnim *)(*(int *)((int)instance->data + 0x40) + (int)animList[index] * 0x10);
  }
  return (_MonsterAnim *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PlayAnimID(struct _Instance *instance /*$s3*/, int index /*$a1*/, int mode /*$fp*/)
// line 409, offset 0x8007fa10
/* begin block 1 */
// Start line: 410
// Start offset: 0x8007FA10
// Variables:
// 		struct _MonsterVars *mv; // $s2
// 		struct _MonsterAnim *manim; // $s1
// 		struct _MonsterAttributes *ma; // $v0
// 		int anim; // $a2
// 		int anim0; // $s6
// 		int i; // $s0
// 		int interpFrames; // $s5
// 		int alphaTable; // $s4
/* end block 1 */
// End offset: 0x8007FB44
// End Line: 466

/* begin block 2 */
// Start line: 808
/* end block 2 */
// End Line: 809

void MON_PlayAnimID(_Instance *instance, int index, int mode)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int NewAnim;
  int CurrentSection;
  uint uVar4;
  uint *puVar5;
  int iVar6;

  uVar4 = *(int *)((int)instance->data + 0x40) + index * 0x10;
  iVar6 = (int)*(char *)(uVar4 + 0xc);
  puVar5 = (uint *)instance->extraData;
  if ((iVar6 < 0) || (instance->object->numAnims <= iVar6))
  {
    iVar6 = 0;
  }
  G2Anim_SetCallback(&instance->anim, INSTANCE_DefaultAnimCallback, instance);
  uVar3 = puVar5[0x2f];
  if ((uVar3 == 0) || (bVar1 = *(byte *)(uVar3 + 8), bVar1 == 0))
  {
    bVar1 = *(byte *)(uVar4 + 6);
    bVar2 = *(byte *)(uVar4 + 9);
  }
  else
  {
    bVar2 = *(byte *)(uVar3 + 10);
  }
  CurrentSection = 0;
  uVar3 = uVar4;
  if (*(char *)(puVar5[0x55] + 0x2a) != '\0')
  {
    do
    {
      NewAnim = (int)*(char *)(uVar3 + 0xc);
      if ((int)*(char *)(uVar3 + 0xc) == -1)
      {
        NewAnim = iVar6;
      }
      G2EmulationInstanceSwitchAnimationAlpha(instance, CurrentSection, NewAnim, (uint) * (byte *)(uVar4 + 7), (uint)bVar1, mode,
                                              (uint)bVar2);
      G2EmulationInstanceSetAnimSpeed(instance, CurrentSection, (uint) * (ushort *)(uVar4 + 4));
      CurrentSection = CurrentSection + 1;
      uVar3 = uVar4 + CurrentSection;
    } while (CurrentSection < (int)(uint) * (byte *)(puVar5[0x55] + 0x2a));
  }
  puVar5[0x2f] = uVar4;
  *puVar5 = *puVar5 | 0x4000000;
  (instance->anim).section[*(byte *)(uVar4 + 0xb)].callback = MON_AnimCallback;
  *(_Instance **)&(instance->anim).section[*(byte *)(uVar4 + 0xb)].callbackData = instance;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PlayAnimFromList(struct _Instance *instance /*$a0*/, char *animList /*$a1*/, int animtype /*$a2*/, int mode /*$a3*/)
// line 470, offset 0x8007fbc8
/* begin block 1 */
// Start line: 977
/* end block 1 */
// End Line: 978

void MON_PlayAnimFromList(_Instance *instance, char *animList, int animtype, int mode)

{
  MON_PlayAnimID(instance, (int)animList[animtype], mode);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_AnimIDPlaying(struct _Instance *instance /*$a0*/, int index /*$a1*/)
// line 475, offset 0x8007fbf0
/* begin block 1 */
// Start line: 477
// Start offset: 0x8007FBF0
// Variables:
// 		struct _MonsterAttributes *ma; // $v0
/* end block 1 */
// End offset: 0x8007FBF0
// End Line: 479

/* begin block 2 */
// Start line: 988
/* end block 2 */
// End Line: 989

/* begin block 3 */
// Start line: 989
/* end block 3 */
// End Line: 990

/* begin block 4 */
// Start line: 991
/* end block 4 */
// End Line: 992

int MON_AnimIDPlaying(_Instance *instance, int index)

{
  return (uint)(*(int *)((int)instance->extraData + 0xbc) ==
                *(int *)((int)instance->data + 0x40) + index * 0x10);
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PlayAnimIDIfNotPlaying(struct _Instance *instance /*$s0*/, int index /*$s1*/, int mode /*$s2*/)
// line 482, offset 0x8007fc14
/* begin block 1 */
// Start line: 1004
/* end block 1 */
// End Line: 1005

void MON_PlayAnimIDIfNotPlaying(_Instance *param_1, int param_2, int param_3)

{
  int iVar1;

  iVar1 = MON_AnimIDPlaying(param_1, param_2);
  if (iVar1 == 0)
  {
    MON_PlayAnimID(param_1, param_2, param_3);
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_AnimPlayingFromList(struct _Instance *instance /*$a0*/, char *animList /*$a1*/, int animtype /*$a2*/)
// line 491, offset 0x8007fc64
/* begin block 1 */
// Start line: 1022
/* end block 1 */
// End Line: 1023

int MON_AnimPlayingFromList(_Instance *instance, char *animList, int animtype)

{
  int iVar1;

  iVar1 = MON_AnimIDPlaying(instance, (int)animList[animtype]);
  return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PlayAnimFromListIfNotPlaying(struct _Instance *instance /*$s1*/, char *animList /*$a1*/, int animtype /*$a2*/, int mode /*$s2*/)
// line 496, offset 0x8007fc8c
/* begin block 1 */
// Start line: 497
// Start offset: 0x8007FC8C
// Variables:
// 		int index; // $s0
/* end block 1 */
// End offset: 0x8007FCCC
// End Line: 502

/* begin block 2 */
// Start line: 1033
/* end block 2 */
// End Line: 1034

void MON_PlayAnimFromListIfNotPlaying(_Instance *instance, char *animList, int animtype, int mode)

{
  char cVar1;
  int iVar2;

  cVar1 = animList[animtype];
  iVar2 = MON_AnimIDPlaying(instance, (int)cVar1);
  if (iVar2 == 0)
  {
    MON_PlayAnimID(instance, (int)cVar1, mode);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PlayAnim(struct _Instance *instance /*$a0*/, enum MonsterAnim animtype /*$a1*/, int mode /*$a3*/)
// line 508, offset 0x8007fce4
/* begin block 1 */
// Start line: 1059
/* end block 1 */
// End Line: 1060

void MON_PlayAnim(_Instance *instance, MonsterAnim animtype, int mode)

{
  int in_a2;

  MON_PlayAnimFromList(instance, **(char ***)((int)instance->extraData + 0x154), mode, in_a2);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_AnimPlaying(struct _Instance *instance /*$a0*/, enum MonsterAnim animtype /*$a2*/)
// line 516, offset 0x8007fd18
/* begin block 1 */
// Start line: 1076
/* end block 1 */
// End Line: 1077

int MON_AnimPlaying(_Instance *instance, MonsterAnim animtype)

{
  int iVar1;
  int in_a1;

  iVar1 = MON_AnimPlayingFromList(instance, **(char ***)((int)instance->extraData + 0x154), in_a1);
  return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PlayAnimIfNotPlaying(struct _Instance *instance /*$a0*/, enum MonsterAnim animtype /*$a1*/, int mode /*$a3*/)
// line 524, offset 0x8007fd4c
/* begin block 1 */
// Start line: 1093
/* end block 1 */
// End Line: 1094

void MON_PlayAnimIfNotPlaying(_Instance *instance, MonsterAnim animtype, int mode)

{
  int in_a2;

  MON_PlayAnimFromListIfNotPlaying(instance, **(char ***)((int)instance->extraData + 0x154), mode, in_a2);
  return;
}

// decompiled code
// original method signature:
// long /*$ra*/ MON_AnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s0*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
// line 566, offset 0x8007fd80
/* begin block 1 */
// Start line: 567
// Start offset: 0x8007FD80
// Variables:
// 		struct _Instance *instance; // $a3
// 		struct _MonsterVars *mv; // $t0
/* end block 1 */
// End offset: 0x8007FE1C
// End Line: 591

/* begin block 2 */
// Start line: 1132
/* end block 2 */
// End Line: 1133

long MON_AnimCallback(_G2Anim_Type *anim, int sectionID, _G2AnimCallbackMsg_Enum message,
                      long messageDataA, long messageDataB, void *data)

{
  long lVar1;

  if (message == G2ANIM_MSG_LOOPPOINT)
  {
    *(uint *)((int)data + 0x18) = *(uint *)((int)data + 0x18) | 2;
  }
  else
  {
    lVar1 = 1;
    if (message < G2ANIM_MSG_SECTION_INTERPDONE)
    {
      if (message != G2ANIM_MSG_DONE)
      {
        MON_PlayAnimIDIfNotPlaying((_Instance *)anim, sectionID, message);
        return lVar1;
      }
      *(uint *)((int)data + 0x18) = *(uint *)((int)data + 0x18) | 0x10;
      **(uint **)((int)data + 0x14c) = **(uint **)((int)data + 0x14c) & 0xfbffffff;
    }
    else
    {
      if (message != G2ANIM_MSG_SEGCTRLR_INTERPDONE)
      {
        MON_PlayAnimIDIfNotPlaying((_Instance *)anim, sectionID, message);
        return messageDataA;
      }
    }
  }
  return messageDataA;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_AnimInit(struct _Instance *instance /*$s1*/)
// line 597, offset 0x8007fe30
/* begin block 1 */
// Start line: 598
// Start offset: 0x8007FE30
// Variables:
// 		struct _MonsterVars *mv; // $s2
// 		struct _G2AnimSection_Type *animSection; // $s3
// 		int i; // $s0
// 		int startSection; // $s6
// 		int numSections; // $s7

/* begin block 1.1 */
// Start line: 611
// Start offset: 0x8007FE8C
// Variables:
// 		int sectionEnd; // $a3
/* end block 1.1 */
// End offset: 0x8007FF10
// End Line: 621
/* end block 1 */
// End offset: 0x8007FF58
// End Line: 626

/* begin block 2 */
// Start line: 1203
/* end block 2 */
// End Line: 1204

void MON_AnimInit(_Instance *instance)

{
  byte bVar1;
  byte bVar2;
  int CurrentSection;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  pvVar3 = instance->extraData;
  iVar6 = 0;
  bVar1 = *(byte *)(*(int *)((int)pvVar3 + 0x154) + 0x2a);
  CurrentSection = 0;
  *(undefined4 *)((int)pvVar3 + 0xbc) = 0;
  G2EmulationInstanceSetTotalSections(instance, (ushort)bVar1);
  iVar5 = 0x94;
  if (bVar1 != 0)
  {
    iVar4 = 0x1b8;
    do
    {
      bVar2 = *(byte *)(*(int *)((int)pvVar3 + 0x154) + CurrentSection + 0x2b);
      if (bVar2 == 0)
      {
        G2EmulationInstanceSetStartAndEndSegment(instance, CurrentSection, (short)iVar6,
                                                 (short)(((uint) * (ushort *)&instance->object->modelList[instance->currentModel]->numSegments - 1) * 0x10000 >> 0x10));
      }
      else
      {
        G2EmulationInstanceSetStartAndEndSegment(instance, CurrentSection, (short)iVar6, (ushort)bVar2);
        iVar6 = (uint) * (byte *)(*(int *)((int)pvVar3 + 0x154) + CurrentSection + 0x2b) + 1;
      }
      G2AnimSection_SetInterpInfo((_G2AnimSection_Type *)((int)&(instance->node).prev + iVar4),
                                  (_G2AnimInterpInfo_Type *)((int)pvVar3 + iVar5));
      G2EmulationInstanceSetAnimation(instance, CurrentSection, 0, 0, 0);
      G2EmulationInstanceSetMode(instance, CurrentSection, 2);
      iVar5 = iVar5 + 0xc;
      CurrentSection = CurrentSection + 1;
      iVar4 = iVar4 + 0x30;
    } while (CurrentSection < (int)(uint)bVar1);
  }
  G2EmulationInstanceInitSection(instance, 0, MON_AnimCallback, instance);
  MON_PlayRandomIdle(instance, 2);
  return;
}

// decompiled code
// original method signature:
// short /*$ra*/ MON_FacingOffset(struct _Instance *instance /*$a0*/, struct _Instance *target /*$s0*/)
// line 638, offset 0x8007ffa8
/* begin block 1 */
// Start line: 639
// Start offset: 0x8007FFA8
/* end block 1 */
// End offset: 0x8007FFA8
// End Line: 639

/* begin block 2 */
// Start line: 1309
/* end block 2 */
// End Line: 1310

short MON_FacingOffset(_Instance *instance, _Instance *target)

{
  ushort uVar1;

  uVar1 = MATH3D_AngleFromPosToPos(&target->position, &instance->position);
  return (short)(((uint)uVar1 - (uint)(ushort)(target->rotation).z) * 0x10000 >> 0x10);
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_CheckConditions(struct _Instance *instance /*$a0*/, struct _MonsterIR *mir /*$a1*/, char *probArray /*$a2*/)
// line 651, offset 0x8007ffe4
/* begin block 1 */
// Start line: 653
// Start offset: 0x8007FFE4
// Variables:
// 		struct _MonsterVars *mv; // $v0
// 		char *probability; // $a2
// 		int chance; // $a1
// 		int i; // $t1
// 		int prob; // $a3
// 		int nprob; // $t0

/* begin block 1.1 */
// Start line: 663
// Start offset: 0x80080014
// Variables:
// 		int conditionProb; // $v0
/* end block 1.1 */
// End offset: 0x80080078
// End Line: 674
/* end block 1 */
// End offset: 0x80080088
// End Line: 677

/* begin block 2 */
// Start line: 1341
/* end block 2 */
// End Line: 1342

/* begin block 3 */
// Start line: 1342
/* end block 3 */
// End Line: 1343

/* begin block 4 */
// Start line: 1346
/* end block 4 */
// End Line: 1347

int MON_CheckConditions(_Instance *instance, _MonsterIR *mir, char *probArray)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;

  iVar2 = 100;
  iVar3 = 100;
  uVar4 = 1;
  do
  {
    if ((mir->mirConditions & uVar4) != 0)
    {
      iVar1 = (int)*probArray;
      if (iVar1 < 0)
      {
        iVar3 = (iVar3 * (iVar1 + 100)) / 100;
      }
      else
      {
        iVar2 = (iVar2 * (100 - iVar1)) / 100;
      }
    }
    uVar4 = uVar4 << 1;
    probArray = probArray + 1;
  } while ((int)uVar4 < 0x1000);
  return (uint)((int)*(char *)((int)instance->extraData + 0x151) < ((100 - iVar2) * iVar3) / 100);
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ShouldIAttackInstance(struct _Instance *instance /*$s2*/, struct _Instance *ei /*$s0*/)
// line 695, offset 0x800800bc
/* begin block 1 */
// Start line: 696
// Start offset: 0x800800BC

/* begin block 1.1 */
// Start line: 699
// Start offset: 0x800800E4
// Variables:
// 		struct _Instance *enemyAttackee; // $s1
// 		long mode; // $v1
// 		struct _MonsterVars *mv; // $s3

/* begin block 1.1.1 */
// Start line: 713
// Start offset: 0x80080180
/* end block 1.1.1 */
// End offset: 0x800801C0
// End Line: 719
/* end block 1.1 */
// End offset: 0x800801C0
// End Line: 720
/* end block 1 */
// End offset: 0x800801C4
// End Line: 723

/* begin block 2 */
// Start line: 1454
/* end block 2 */
// End Line: 1455

/* begin block 3 */
// Start line: 1455
/* end block 3 */
// End Line: 1456

int MON_ShouldIAttackInstance(_Instance *instance, _Instance *ei)

{
  if (ei == DAT_800d0fd8)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(ei, 0x22);
  }
  return 1;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ShouldIAttack(struct _Instance *instance /*$s3*/, struct _MonsterIR *enemy /*$s1*/, struct _MonsterAttackAttributes *attack /*$s0*/)
// line 731, offset 0x800801e0
/* begin block 1 */
// Start line: 732
// Start offset: 0x800801E0
// Variables:
// 		struct _MonsterVars *mv; // $s4
// 		int rv; // $a0
// 		struct _Instance *ei; // $s2

/* begin block 1.1 */
// Start line: 751
// Start offset: 0x8008024C
// Variables:
// 		long distance; // $v1
/* end block 1.1 */
// End offset: 0x80080364
// End Line: 803
/* end block 1 */
// End offset: 0x80080368
// End Line: 809

/* begin block 2 */
// Start line: 1527
/* end block 2 */
// End Line: 1528

int MON_ShouldIAttack(_Instance *instance, _MonsterIR *enemy, _MonsterAttackAttributes *attack)

{
  short angle;
  int iVar1;
  int iVar2;
  _Instance *ei;
  void *pvVar3;

  ei = enemy->instance;
  pvVar3 = instance->extraData;
  iVar1 = MON_ShouldIAttackInstance(instance, ei);
  iVar2 = 0;
  if ((iVar1 != 0) && (iVar2 = 0, attack != (_MonsterAttackAttributes *)0x0))
  {
    if ((ei == DAT_800d0fd8) &&
        (iVar1 = MON_CheckConditions(instance, enemy, attack->attackProbability), iVar1 == 0))
    {
      return 0;
    }
    iVar1 = (int)attack->attackRange - (int)enemy->distance;
    if ((enemy->mirFlags & 8) == 0)
    {
      if (iVar1 < -0x96)
      {
        iVar2 = 5;
      }
      else
      {
        if (iVar1 < 0x97)
        {
          iVar1 = (int)(enemy->relativePosition).y;
          if (iVar1 < 1)
          {
            iVar2 = (int)(enemy->relativePosition).x;
            if (iVar2 < 0)
            {
              iVar2 = -iVar2;
            }
            if (iVar2 <= -iVar1)
            {
              if ((enemy->mirFlags & 0x20) == 0)
              {
                return 3;
              }
              iVar1 = *(int *)((int)pvVar3 + 0xcc);
              if (iVar1 == 0)
              {
                if ((*(uint *)((int)pvVar3 + 4) & 0x20000000) == 0)
                {
                  angle = MATH3D_AngleFromPosToPos(&instance->position, &ei->position);
                  iVar1 = MONSENSE_GetDistanceInDirection(instance, angle);
                  if (iVar1 <= enemy->distance)
                  {
                    return 0;
                  }
                }
                enemy->mirConditions = 0;
                return 1;
              }
              /* WARNING: Subroutine does not return */
              INSTANCE_Query(*(_Instance **)(iVar1 + 4), 10);
            }
          }
          iVar2 = 6;
        }
        else
        {
          iVar2 = 4;
        }
      }
    }
    else
    {
      if (iVar1 < 0)
      {
        iVar1 = -iVar1;
      }
      iVar2 = 5;
      if (iVar1 < 1000)
      {
        iVar2 = 1;
      }
    }
  }
  /* WARNING: Read-only address (ram,0x800d0fd8) is written */
  return iVar2;
}

// decompiled code
// original method signature:
// struct _MonsterAttackAttributes * /*$ra*/ MON_ChooseAttack(struct _Instance *instance /*$a0*/, struct _MonsterIR *enemy /*$a1*/)
// line 818, offset 0x80080388
/* begin block 1 */
// Start line: 820
// Start offset: 0x80080388
// Variables:
// 		struct _MonsterVars *mv; // $t1
// 		struct _MonsterAttackAttributes *bestAttack; // $t5
// 		struct _MonsterAttributes *ma; // $t6
// 		struct _MonsterCombatAttributes *combat; // $t0
// 		long distance; // $t3
// 		long zdiff; // $t2
// 		long smallest; // $t4
// 		int i; // $a3
// 		char *attackIndex; // $t0

/* begin block 1.1 */
// Start line: 850
// Start offset: 0x8008042C
// Variables:
// 		struct _MonsterAttackAttributes *attack; // $a2
// 		long delta; // $a0
/* end block 1.1 */
// End offset: 0x800804CC
// End Line: 864
/* end block 1 */
// End offset: 0x800804D8
// End Line: 869

/* begin block 2 */
// Start line: 1705
/* end block 2 */
// End Line: 1706

/* begin block 3 */
// Start line: 1706
/* end block 3 */
// End Line: 1707

/* begin block 4 */
// Start line: 1707
/* end block 4 */
// End Line: 1708

_MonsterAttackAttributes *MON_ChooseAttack(_Instance *instance, _MonsterIR *enemy)

{
  int iVar1;
  int iVar2;
  int iVar3;
  MATRIX *pMVar4;
  _MonsterAttackAttributes *p_Var5;
  int iVar6;
  char *pcVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  _MonsterAttackAttributes *p_Var12;

  p_Var12 = (_MonsterAttackAttributes *)0x0;
  iVar9 = 0x100;
  puVar8 = (uint *)instance->extraData;
  iVar11 = 99999;
  if (((*puVar8 & 4) == 0) && ((enemy->mirFlags & 8) == 0))
  {
    pMVar4 = enemy->instance->matrix;
    iVar10 = (int)enemy->distance;
    if (pMVar4 != (MATRIX *)0x0)
    {
      if (enemy->instance == DAT_800d0fd8)
      {
        iVar9 = pMVar4[0xe].t[2] - (int)(instance->position).z;
      }
      else
      {
        iVar9 = pMVar4[1].t[2] - (int)(instance->position).z;
      }
    }
  }
  else
  {
    iVar10 = 0;
  }
  iVar6 = (int)*(char *)(*(int *)(puVar8[0x55] + 8) + 0x1d);
  pcVar7 = (char *)(*(int *)(puVar8[0x55] + 8) + 0x2c);
  if (iVar6 != 0)
  {
    do
    {
      p_Var5 = (_MonsterAttackAttributes *)(*(int *)((int)instance->data + 0x38) + (int)*pcVar7 * 0x20);
      iVar2 = iVar9 - p_Var5->attackHeight;
      if (iVar2 < 0)
      {
        iVar2 = -iVar2;
      }
      if ((iVar2 < 100) || ((enemy->mirFlags & 8) != 0))
      {
        iVar2 = (int)p_Var5->attackRange * (int)*(short *)(puVar8[0x55] + 0x14);
        if (iVar2 < 0)
        {
          iVar2 = iVar2 + 0xfff;
        }
        iVar3 = (iVar2 >> 0xc) - iVar10;
        iVar2 = iVar3;
        if (iVar3 < 0)
        {
          iVar2 = -iVar3;
        }
        iVar1 = iVar11;
        if (iVar11 < 0)
        {
          iVar1 = -iVar11;
        }
        if (iVar2 < iVar1)
        {
          iVar11 = iVar3;
          p_Var12 = p_Var5;
        }
      }
      iVar6 = iVar6 + -1;
      pcVar7 = pcVar7 + 1;
    } while (iVar6 != 0);
  }
  *(_MonsterAttackAttributes **)(puVar8 + 0x2e) = p_Var12;
  *(undefined *)((int)puVar8 + 0x14b) = 0;
  return p_Var12;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ShouldIEvade(struct _Instance *instance /*$s1*/)
// line 878, offset 0x800804e8
/* begin block 1 */
// Start line: 879
// Start offset: 0x800804E8
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		int rv; // $s3

/* begin block 1.1 */
// Start line: 886
// Start offset: 0x80080520
// Variables:
// 		struct _MonsterIR *enemy; // $s2
/* end block 1.1 */
// End offset: 0x80080574
// End Line: 899
/* end block 1 */
// End offset: 0x80080574
// End Line: 903

/* begin block 2 */
// Start line: 1869
/* end block 2 */
// End Line: 1870

int MON_ShouldIEvade(_Instance *instance)

{
  short sVar1;
  int iVar2;
  uint *puVar3;
  _MonsterIR *mir;
  int iVar4;

  puVar3 = (uint *)instance->extraData;
  iVar4 = 0;
  if ((*puVar3 & 0x40000000) == 0)
  {
    mir = (_MonsterIR *)puVar3[0x31];
    sVar1 = MON_FacingOffset(instance, mir->instance);
    if ((ushort)(sVar1 + 0x2a9U) < 0x553)
    {
      iVar2 = MON_CheckConditions(instance, mir, (char *)(*(int *)(puVar3[0x55] + 8) + 0x20));
      iVar4 = 0;
      if (iVar2 != 0)
      {
        iVar4 = 1;
        *(undefined2 *)(puVar3[0x31] + 0x18) = 0;
      }
    }
  }
  return iVar4;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ChooseLeftOrRight(struct _Instance *instance /*$s0*/, struct _MonsterIR *enemy /*$a1*/)
// line 913, offset 0x80080594
/* begin block 1 */
// Start line: 914
// Start offset: 0x80080594

/* begin block 1.1 */
// Start line: 923
// Start offset: 0x800805D4
// Variables:
// 		int leftDist; // $s0
// 		int rightDist; // $v1
/* end block 1.1 */
// End offset: 0x80080628
// End Line: 932
/* end block 1 */
// End offset: 0x80080628
// End Line: 933

/* begin block 2 */
// Start line: 1940
/* end block 2 */
// End Line: 1941

int MON_ChooseLeftOrRight(_Instance *instance, _MonsterIR *enemy)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  sVar1 = MON_FacingOffset(instance, enemy->instance);
  iVar2 = -1;
  if (-0x41 < sVar1)
  {
    if (sVar1 < 0x41)
    {
      iVar3 = MONSENSE_GetDistanceInDirection(instance, (short)(((uint)(ushort)(instance->rotation).z + 0x400) * 0x10000 >> 0x10));
      iVar4 = MONSENSE_GetDistanceInDirection(instance, (short)(((uint)(ushort)(instance->rotation).z - 0x400) * 0x10000 >> 0x10));
      if (iVar3 == iVar4)
      {
        iVar2 = 0;
      }
      else
      {
        iVar2 = 1;
        if (iVar4 <= iVar3)
        {
          iVar2 = -1;
        }
      }
    }
    else
    {
      iVar2 = 1;
    }
  }
  return iVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ChooseEvadeMove(struct _Instance *instance /*$a0*/)
// line 935, offset 0x80080638
/* begin block 1 */
// Start line: 936
// Start offset: 0x80080638
// Variables:
// 		int anim; // $v0
// 		struct _MonsterVars *mv; // $v0
// 		int leftOrRight; // $v1
/* end block 1 */
// End offset: 0x80080684
// End Line: 964

/* begin block 2 */
// Start line: 1989
/* end block 2 */
// End Line: 1990

int MON_ChooseEvadeMove(_Instance *instance)

{
  int iVar1;
  int iVar2;

  iVar1 = MON_ChooseLeftOrRight(instance, *(_MonsterIR **)((int)instance->extraData + 0xc4));
  if (iVar1 == 0)
  {
    /* WARNING: Subroutine does not return */
    rand();
  }
  iVar2 = 0x29;
  if (iVar1 < 0)
  {
    iVar2 = 0x28;
  }
  return iVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ChooseCombatMove(struct _Instance *instance /*$s2*/, int reason /*$a1*/)
// line 969, offset 0x80080694
/* begin block 1 */
// Start line: 970
// Start offset: 0x80080694
// Variables:
// 		struct _MonsterVars *mv; // $s3
// 		struct _MonsterSubAttributes *subAttr; // $s4
// 		int anim; // $s1
// 		int data; // $v0
// 		struct _MonsterIR *enemy; // $s0
// 		int infront; // $a0
// 		struct _MonsterAnim *manim; // $s0

/* begin block 1.1 */
// Start line: 1032
// Start offset: 0x80080748

/* begin block 1.1.1 */
// Start line: 1036
// Start offset: 0x80080768
// Variables:
// 		int dir; // $v0
/* end block 1.1.1 */
// End offset: 0x800807B0
// End Line: 1045
/* end block 1.1 */
// End offset: 0x800807C8
// End Line: 1068

/* begin block 1.2 */
// Start line: 1072
// Start offset: 0x800807D0
// Variables:
// 		short zrot; // $s0

/* begin block 1.2.1 */
// Start line: 1108
// Start offset: 0x800808C0
// Variables:
// 		struct _Position temp; // stack offset -56
// 		struct SVECTOR New; // stack offset -48
// 		struct VECTOR OutTrans; // stack offset -40
/* end block 1.2.1 */
// End offset: 0x800809E0
// End Line: 1148
/* end block 1.2 */
// End offset: 0x80080AB8
// End Line: 1173
/* end block 1 */
// End offset: 0x80080AB8
// End Line: 1177

/* begin block 2 */
// Start line: 2057
/* end block 2 */
// End Line: 2058

int MON_ChooseCombatMove(_Instance *instance, int reason)

{
  short angle;
  ushort uVar1;
  int Data;
  uint xOffset;
  uint yOffset;
  _MonsterIR *enemy;
  uint uVar2;
  void *pvVar3;
  int *piVar4;
  undefined2 local_30;
  short local_2e;
  undefined2 local_2c;
  undefined local_28[16];

  pvVar3 = instance->extraData;
  enemy = *(_MonsterIR **)((int)pvVar3 + 0xc4);
  Data = *(int *)((int)pvVar3 + 0xcc);
  piVar4 = *(int **)((int)pvVar3 + 0x154);
  if ((Data == 0) || (699 < *(short *)(Data + 0x14)))
  {
    if (reason == 4)
    {
    LAB_80080740:
      uVar2 = 7;
    }
    else
    {
      uVar2 = 6;
      if (reason != 5)
      {
        Data = (int)(enemy->relativePosition).y;
        if (Data < 0)
        {
          Data = -Data;
        }
        if (Data < *(short *)(piVar4[2] + 0x14))
        {
          if ((enemy->relativePosition).y < 0)
            goto LAB_80080740;
        }
        else
        {
          angle = MON_FacingOffset(instance, enemy->instance);
          if ((ushort)(angle + 0x2a9U) < 0x553)
          {
            Data = MON_ChooseLeftOrRight(instance, enemy);
            uVar2 = 8;
            if ((-1 < Data) && (uVar2 = 9, Data < 1))
            {
              /* WARNING: Subroutine does not return */
              rand();
            }
          }
          else
          {
            uVar2 = 0;
          }
          if (uVar2 == 0)
          {
            return 0;
          }
        }
      }
    }
  }
  else
  {
    uVar2 = 8;
    if (0 < *(short *)(Data + 0xc))
    {
      uVar2 = 9;
    }
  }
  if (uVar2 == 0)
  {
    return 0;
  }
  angle = (instance->rotation).z;
  if (uVar2 == 8)
  {
    angle = angle + 0x400;
  }
  else
  {
    if (uVar2 < 9)
    {
      if (uVar2 == 7)
      {
        angle = angle + 0x800;
      }
    }
    else
    {
      if (uVar2 == 9)
      {
        angle = angle + -0x400;
      }
    }
  }
  MONSENSE_AdjustRadarFromObjects(instance);
  angle = MONSENSE_GetClosestFreeDirection(instance, angle, 0x2ee);
  uVar1 = (angle - (instance->rotation).z) + 0x200U & 0xfff;
  uVar2 = 6;
  if (((0x3ff < uVar1) && (uVar2 = 8, 0x7ff < uVar1)) && (uVar2 = 9, uVar1 < 0xc00))
  {
    uVar2 = 7;
  }
  Data = *(int *)((int)instance->data + 0x40) + (int)*(char *)(*piVar4 + uVar2) * 0x10;
  if (((*(char *)((int)pvVar3 + 0x146) == '\a') && (instance->intro != (Intro *)0x0)) &&
      (instance->matrix != (MATRIX *)0x0))
  {
    local_30 = 0;
    local_2c = 0;
    if (uVar2 - 7 < 2)
    {
      local_2e = *(short *)(Data + 2);
    }
    else
    {
      local_2e = -*(short *)(Data + 2);
    }
    /* WARNING: Subroutine does not return */
    ApplyMatrix(instance->matrix, &local_30, local_28);
  }
  if (uVar2 == 8)
  {
    yOffset = 0;
    xOffset = (uint) * (ushort *)(Data + 2);
  }
  else
  {
    if (uVar2 < 9)
    {
      xOffset = 0;
      if (uVar2 == 7)
      {
        yOffset = (uint) * (ushort *)(Data + 2);
        goto LAB_80080a80;
      }
    }
    else
    {
      yOffset = 0;
      if (uVar2 == 9)
      {
        xOffset = -(uint) * (ushort *)(Data + 2);
        goto LAB_80080a80;
      }
    }
    xOffset = 0;
    yOffset = -(uint) * (ushort *)(Data + 2);
  }
LAB_80080a80:
  Data = SetPhysicsDropOffData(xOffset, yOffset, 200, 0x800, 400);
  Data = PhysicsCheckDropOff(instance, Data, 4);
  if (Data == 0)
  {
    if (uVar2 - 8 < 2)
    {
      *(undefined *)((int)pvVar3 + 0x150) = (char)uVar2;
    }
  }
  else
  {
    uVar2 = 0;
  }
  return uVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_PlayRandomIdle(struct _Instance *instance /*$s4*/, int mode /*$s5*/)
// line 1185, offset 0x80080adc
/* begin block 1 */
// Start line: 1186
// Start offset: 0x80080ADC
// Variables:
// 		struct _MonsterVars *mv; // $s3
// 		struct _MonsterAttributes *ma; // $s2
// 		struct _MonsterBehavior *behavior; // $s0
// 		struct _MonsterIdle *idle; // $s1
// 		int chance; // $a2
// 		int i; // $a0
// 		char *idleIndex; // $a1
/* end block 1 */
// End offset: 0x80080C5C
// End Line: 1244

/* begin block 2 */
// Start line: 2527
/* end block 2 */
// End Line: 2528

void MON_PlayRandomIdle(_Instance *instance, int mode)

{
  /* WARNING: Subroutine does not return */
  rand();
}

// autogenerated function stub:
// void /*$ra*/ MON_PlayCombatIdle(struct _Instance *instance /*$a0*/, int mode /*$a2*/)
void MON_PlayCombatIdle(struct _Instance *instance, int mode)
{           // line 1249, offset 0x80080c80
            /* begin block 1 */
            // Start line: 1250
            // Start offset: 0x80080C80
            // Variables:
  int anim; // $a1
            /* end block 1 */
            // End offset: 0x80080CA8
            // End Line: 1258

  /* begin block 2 */
  // Start line: 2664
  /* end block 2 */
  // End Line: 2665
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_GetRandomPoint(struct _Position *out /*$s2*/, struct _Position *in /*$s1*/, short r /*$a2*/)
// line 1290, offset 0x80080cc0
/* begin block 1 */
// Start line: 1291
// Start offset: 0x80080CC0
// Variables:
// 		int ang; // $s0
/* end block 1 */
// End offset: 0x80080CC0
// End Line: 1291

/* begin block 2 */
// Start line: 2580
/* end block 2 */
// End Line: 2581

void MON_GetRandomPoint(_Position *out, _Position *in, short r)

{
  /* WARNING: Subroutine does not return */
  rand();
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_GetRandomDestinationInWorld(struct _Instance *instance /*$s2*/, struct _Position *in /*$s0*/, short r /*$s4*/)
// line 1307, offset 0x80080d6c
/* begin block 1 */
// Start line: 1308
// Start offset: 0x80080D6C

/* begin block 1.1 */
// Start line: 1311
// Start offset: 0x80080DA0
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct evPhysicsLOSData data; // stack offset -48
// 		int result; // $s0
// 		int avoidEnemy; // $s3

/* begin block 1.1.1 */
// Start line: 1322
// Start offset: 0x80080DDC
/* end block 1.1.1 */
// End offset: 0x80080E2C
// End Line: 1328

/* begin block 1.1.2 */
// Start line: 1342
// Start offset: 0x80080EA8
/* end block 1.1.2 */
// End offset: 0x80080EF8
// End Line: 1348
/* end block 1.1 */
// End offset: 0x80080F30
// End Line: 1357
/* end block 1 */
// End offset: 0x80080F34
// End Line: 1360

/* begin block 2 */
// Start line: 2752
/* end block 2 */
// End Line: 2753

/* WARNING: Could not reconcile some variable overlaps */

int MON_GetRandomDestinationInWorld(_Instance *instance, _Position *in, short r)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  undefined4 local_30;
  short local_2c;
  _Position local_28[2];

  if (instance->matrix == (MATRIX *)0x0)
  {
    iVar2 = 0;
  }
  else
  {
    puVar3 = (uint *)instance->extraData;
    bVar1 = false;
    if ((uint) * (byte *)((int)puVar3 + 0x146) - 9 < 2)
    {
      bVar1 = puVar3[0x31] != 0;
    }
    if (in == (_Position *)0x0)
    {
      in = &instance->position;
    }
    else
    {
      if (bVar1)
      {
        iVar2 = *(int *)(puVar3[0x31] + 4);
        /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)in->x - (int)*(short *)(iVar2 + 0x5c),
                         (int)in->y - (int)*(short *)(iVar2 + 0x5e),
                         (int)in->z - (int)*(short *)(iVar2 + 0x60));
      }
    }
    local_28[0].x = *(short *)instance->matrix[1].t;
    local_28[0].y = *(short *)(instance->matrix[1].t + 1);
    local_28[0].z = *(short *)(instance->matrix[1].t + 2);
    MON_GetRandomPoint((_Position *)&local_30, in, r);
    local_2c = local_2c + (local_28[0].z - (instance->position).z);
    iVar2 = MON_CheckPointSuitability(instance, local_28, (_Position *)&local_30);
    if (iVar2 != 0)
    {
      if (bVar1)
      {
        iVar2 = *(int *)(puVar3[0x31] + 4);
        /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)(short)local_30 - (int)*(short *)(iVar2 + 0x5c),
                         (int)local_30._2_2_ - (int)*(short *)(iVar2 + 0x5e),
                         (int)local_2c - (int)*(short *)(iVar2 + 0x60));
      }
      if (iVar2 != 0)
      {
        *puVar3 = *puVar3 | 0x40000;
        *(undefined4 *)((int)puVar3 + 0x112) = local_30;
        *(short *)((int)puVar3 + 0x116) = local_2c;
      }
    }
  }
  return iVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_MoveForward(struct _Instance *instance /*$s0*/)
// line 1453, offset 0x80080f54
/* begin block 1 */
// Start line: 1454
// Start offset: 0x80080F54
// Variables:
// 		struct _MonsterVars *mv; // $v0
/* end block 1 */
// End offset: 0x80080F54
// End Line: 1454

/* begin block 2 */
// Start line: 2906
/* end block 2 */
// End Line: 2907

void MON_MoveForward(_Instance *instance)

{
  PhysicsSetVelFromRot(instance, &instance->rotation, (int)*(short *)((int)instance->extraData + 0x110));
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  PhysicsMove(instance, &instance->position, DAT_800d11ec);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_TurnToPosition(struct _Instance *instance /*$s1*/, struct _Position *position /*$a1*/, short turnspeed /*$a2*/)
// line 1468, offset 0x80080fa4
/* begin block 1 */
// Start line: 1469
// Start offset: 0x80080FA4
/* end block 1 */
// End offset: 0x80080FA4
// End Line: 1469

/* begin block 2 */
// Start line: 2989
/* end block 2 */
// End Line: 2990

int MON_TurnToPosition(_Instance *instance, _Position *position, short turnspeed)

{
  short destination;

  destination = MATH3D_AngleFromPosToPos(&instance->position, position);
  AngleMoveToward(&(instance->rotation).z, destination,
                  (short)((uint)(turnspeed * DAT_800d11ec * 0x10) >> 0x10));
  return (uint)((instance->rotation).z == destination);
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_MoveToPosition(struct _Instance *instance /*$s0*/, struct _Position *position /*$a1*/, short turnSpeed /*$a2*/)
// line 1485, offset 0x80081014
/* begin block 1 */
// Start line: 3029
/* end block 1 */
// End Line: 3030

void MON_MoveToPosition(_Instance *instance, _Position *position, short turnSpeed)

{
  int iVar1;

  MON_TurnToPosition(instance, position, turnSpeed);
  iVar1 = MON_TransNodeAnimation(instance);
  if (iVar1 == 0)
  {
    MON_MoveForward(instance);
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_OnGround(struct _Instance *instance /*$s0*/)
// line 1504, offset 0x80081058
/* begin block 1 */
// Start line: 1505
// Start offset: 0x80081058
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		struct evPhysicsGravityData data; // stack offset -32
// 		int minUpper; // $v1
// 		long xyDist; // $a1
/* end block 1 */
// End offset: 0x800810E8
// End Line: 1532

/* begin block 2 */
// Start line: 3069
/* end block 2 */
// End Line: 3070

int MON_OnGround(_Instance *instance)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  short local_20;
  short local_1e;
  undefined2 local_16;

  puVar4 = (uint *)instance->extraData;
  lVar1 = MATH3D_LengthXY((int)(instance->oldPos).x - (int)(instance->position).x,
                          (int)(instance->oldPos).y - (int)(instance->position).y);
  local_1e = (short)lVar1;
  iVar3 = (uint)(ushort)(instance->oldPos).z - (uint)(ushort)(instance->position).z;
  local_20 = (short)iVar3;
  iVar2 = 400;
  if ((*puVar4 & 2) != 0)
  {
    iVar2 = 100;
  }
  if (iVar3 * 0x10000 >> 0x10 < iVar2)
  {
    local_20 = (short)iVar2;
  }
  if (local_1e < 100)
  {
    local_1e = 100;
  }
  local_20 = local_20 + *(short *)(puVar4[0x55] + 0x4e);
  local_16 = 0xc80;
  local_1e = local_1e + *(short *)(puVar4[0x55] + 0x50);
  iVar2 = PhysicsCheckGravity(instance, (int)&local_20, (ushort)((*puVar4 & 0x800) == 0) << 2);
  return iVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ApplyPhysics(struct _Instance *instance /*$a0*/)
// line 1549, offset 0x80081148
/* begin block 1 */
// Start line: 3188
/* end block 1 */
// End Line: 3189

void MON_MoveForward(_Instance *instance)

{
  PhysicsMove(instance, &instance->position, fontTracker.font_buffer._844_4_);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ChangeBehavior(struct _Instance *instance /*$a0*/, int behavior /*$s0*/)
// line 1559, offset 0x8008116c
/* begin block 1 */
// Start line: 1560
// Start offset: 0x8008116C

/* begin block 1.1 */
// Start line: 1563
// Start offset: 0x80081188
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		enum MonsterState state; // $a1
/* end block 1.1 */
// End offset: 0x800811E0
// End Line: 1590
/* end block 1 */
// End offset: 0x800811E0
// End Line: 1591

/* begin block 2 */
// Start line: 3209
/* end block 2 */
// End Line: 3210

void MON_ChangeBehavior(_Instance *instance, int behavior)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;

  if (behavior == -1)
  {
    return;
  }
  switch (behavior)
  {
  case 2:
    break;
  case 4:
  case 8:
    break;
  case 9:
  }
  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(unaff_s1, unaff_s0));
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_CheckEnvironment(struct _Instance *instance /*$s1*/)
// line 1596, offset 0x800811f4
/* begin block 1 */
// Start line: 1597
// Start offset: 0x800811F4
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterAttributes *ma; // $s4
// 		int inwater; // $v0
// 		struct _SVector Hack; // stack offset -40

/* begin block 1.1 */
// Start line: 1637
// Start offset: 0x80081328
// Variables:
// 		int moveback; // $s2
// 		int onground; // $s3

/* begin block 1.1.1 */
// Start line: 1664
// Start offset: 0x800813D4
// Variables:
// 		int offset; // $a1
// 		int result; // $v0
// 		struct _Position pos; // stack offset -32
/* end block 1.1.1 */
// End offset: 0x8008147C
// End Line: 1684

/* begin block 1.1.2 */
// Start line: 1696
// Start offset: 0x800814B8
// Variables:
// 		int result; // $v0
// 		int offset; // $a1
/* end block 1.1.2 */
// End offset: 0x80081518
// End Line: 1712

/* begin block 1.1.3 */
// Start line: 1719
// Start offset: 0x80081520
// Variables:
// 		int result; // $v1
/* end block 1.1.3 */
// End offset: 0x8008157C
// End Line: 1749
/* end block 1.1 */
// End offset: 0x800815E4
// End Line: 1762
/* end block 1 */
// End offset: 0x80081608
// End Line: 1767

/* begin block 2 */
// Start line: 3284
/* end block 2 */
// End Line: 3285

void MON_CheckEnvironment(_Instance *instance)

{
  bool bVar1;
  int Data;
  uint uVar2;
  uint dropOffset;
  uint *puVar3;
  void *pvVar4;
  _SVector local_28;
  _Position local_20;

  puVar3 = (uint *)instance->extraData;
  pvVar4 = instance->data;
  if (instance->currentMainState != 0x1d)
  {
    local_28.z = 0;
    local_28.y = 0;
    local_28.x = 0;
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
    if ((*(uint *)((int)pvVar4 + 0x10) & 4) == 0)
    {
      Data = SetPhysicsSwimData(0, &local_28, 0x100, 0xa0, 0x40);
      uVar2 = PhysicsCheckSwim(instance, Data, 1);
      uVar2 = uVar2 & 0x20;
    }
    else
    {
      uVar2 = 0x20;
    }
    if (uVar2 == 0)
    {
      if ((*puVar3 & 0x400) == 0)
      {
        *puVar3 = *puVar3 & 0xffbfffff | 0x400;
        instance->maxXVel = 0x14;
        instance->maxYVel = 0x14;
        instance->maxZVel = 0x14;
        instance->xVel = 0;
        instance->yVel = 0;
        SOUND_Play3dSound(&instance->position, 1, -200, 0x78, (int)&DAT_00002710);
        instance->flags2 = instance->flags2 & 0xffffffbf;
      }
      if ((*(ushort *)((int)puVar3 + 0x13e) & 0x10) != 0)
      {
        /* WARNING: Subroutine does not return */
        INSTANCE_Post(instance, 0x100000c, 0x10);
      }
    }
    else
    {
      bVar1 = false;
      if ((*puVar3 & 0x400) != 0)
      {
        *puVar3 = *puVar3 & 0xfffffbff;
        instance->maxXVel = 400;
        instance->maxYVel = 400;
        instance->maxZVel = 400;
        if ((instance->object->oflags & 0x200U) != 0)
        {
          instance->flags2 = instance->flags2 | 0x40;
        }
      }
      if (instance->LinkParent == (_Instance *)0x0)
      {
        uVar2 = MON_OnGround(instance);
        if (uVar2 == 0)
        {
          uVar2 = *puVar3;
          if (((uVar2 & 2) != 0) && (*puVar3 = uVar2 & 0xfffffffd, (uVar2 & 0x800) == 0))
          {
            Data = 0x140;
            if ((uVar2 & 0x10000) == 0)
            {
              Data = (int)*(short *)(puVar3[0x55] + 0x16);
            }
            Data = SetPhysicsDropHeightData(&instance->position, Data, 0x40);
            uVar2 = PhysicsCheckDropHeight(instance, Data, 1);
            if (((uVar2 & *(ushort *)((int)puVar3 + 0x13e)) != 0) || (uVar2 == 0))
            {
              bVar1 = true;
            }
          }
        }
        else
        {
          if ((*puVar3 & 2) == 0)
          {
            *puVar3 = *puVar3 | 2;
          }
          if ((*puVar3 & 0x1000) != 0)
          {
            dropOffset = (uint) * (ushort *)puVar3[0x2f] * 8;
            local_20.y = *(ushort *)puVar3[0x2f] * -8;
            if (dropOffset < 100)
            {
              dropOffset = 100;
              local_20.y = -100;
            }
            local_20.x = 0;
            local_20.z = (short)((int)dropOffset / 2);
            if ((*puVar3 & 0x10000) == 0)
            {
              dropOffset = SEXT24(*(short *)(puVar3[0x55] + 0x16));
            }
            Data = SetPhysicsDropHeightData(&local_20, dropOffset, 0x60);
            dropOffset = PhysicsCheckDropHeight(instance, Data, 1);
            if (((dropOffset & *(ushort *)((int)puVar3 + 0x13e)) != 0) || (dropOffset == 0))
            {
              /* WARNING: Subroutine does not return */
              INSTANCE_Post(instance, 0x4010080, 0);
            }
          }
          if ((uVar2 & 0x100000) != 0)
          {
            bVar1 = true;
          }
        }
        if (bVar1)
        {
          Data = SetPhysicsDropHeightData((_Position *)(evPositionData *)&instance->oldPos, 100, 0x40);
          uVar2 = PhysicsCheckDropHeight(instance, Data, 1);
          if ((uVar2 != 0) && ((uVar2 & *(ushort *)((int)puVar3 + 0x13e)) == 0))
          {
            STREAM_SetInstancePosition(instance, (evPositionData *)&instance->oldPos);
            *puVar3 = *puVar3 | 2;
          }
        }
        if (((*puVar3 & 0x802) == 0) && (puVar3[0x3d] != 0x100000))
        {
          /* WARNING: Subroutine does not return */
          INSTANCE_Post(instance, 0x100000b, 0);
        }
      }
      if ((int *)instance->tfaceLevel != (int *)0x0)
      {
        MON_CheckTerrainAndRespond(instance, (BSPTree *)(*(int *)(*(int *)instance->tfaceLevel + 0x48) + instance->bspTree * 0x24), instance->tface);
      }
    }
    uVar2 = *(uint *)((int)pvVar4 + 0x10);
    if ((uVar2 != 0x10082) && ((uVar2 & 4) == 0))
    {
      FX_UpdateInstanceWaterSplit(instance);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_CheckTerrainAndRespond(struct _Instance *instance /*$s1*/, struct BSPTree *bsp /*$a1*/, struct _TFace *tface /*$a2*/)
// line 1769, offset 0x80081628
/* begin block 1 */
// Start line: 1770
// Start offset: 0x80081628
// Variables:
// 		unsigned long results; // $s0
/* end block 1 */
// End offset: 0x80081698
// End Line: 1781

/* begin block 2 */
// Start line: 3645
/* end block 2 */
// End Line: 3646

void MON_CheckTerrainAndRespond(_Instance *instance, BSPTree *bsp, _TFace *tface)

{
  ulong uVar1;

  uVar1 = MON_CheckTerrain(instance, bsp, tface);
  if ((uVar1 & 0x10) != 0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(instance, 0x100000c, 0x10);
  }
  if ((uVar1 & 0x20) != 0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(instance, 0x100000c, 0x20);
  }
  if ((uVar1 & 0x40) != 0)
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(instance, 0x100000c, 0x40);
  }
  return;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ MON_CheckTerrain(struct _Instance *instance /*$s2*/, struct BSPTree *bsp /*$s1*/, struct _TFace *tface /*$a2*/)
// line 1786, offset 0x800816ac
/* begin block 1 */
// Start line: 1787
// Start offset: 0x800816AC
// Variables:
// 		unsigned long rv; // $s0

/* begin block 1.1 */
// Start line: 1793
// Start offset: 0x800816D0
// Variables:
// 		struct Level *level; // $v1
/* end block 1.1 */
// End offset: 0x80081750
// End Line: 1813
/* end block 1 */
// End offset: 0x80081750
// End Line: 1815

/* begin block 2 */
// Start line: 3679
/* end block 2 */
// End Line: 3680

ulong MON_CheckTerrain(_Instance *instance, BSPTree *bsp, _TFace *tface)

{
  if (tface != (_TFace *)0x0)
  {
    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(instance->currentStreamUnitID);
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_CheckPointSuitability(struct _Instance *instance /*$s2*/, struct _Position *origin /*$a1*/, struct _Position *destination /*$s4*/)
// line 1824, offset 0x8008176c
/* begin block 1 */
// Start line: 1825
// Start offset: 0x8008176C
// Variables:
// 		struct _MonsterVars *mv; // $s1
// 		int rc; // $s3
// 		int result; // $a0
// 		struct evPhysicsDropHeightData *data; // $s0
/* end block 1 */
// End offset: 0x80081820
// End Line: 1851

/* begin block 2 */
// Start line: 3761
/* end block 2 */
// End Line: 3762

int MON_CheckPointSuitability(_Instance *instance, _Position *origin, _Position *destination)

{
  int Data;
  uint uVar1;
  ulong uVar2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  Data = SetPhysicsDropHeightData(destination, (int)*(short *)(puVar3[0x55] + 0x16), 0x40);
  uVar1 = PhysicsCheckDropHeight(instance, Data, 1);
  if (uVar1 == 1)
  {
    uVar2 = MON_CheckTerrain(instance, *(BSPTree **)(Data + 0xc), *(_TFace **)(Data + 0x10));
    uVar1 = uVar2 | 1;
    destination->z = *(short *)(Data + 4);
  }
  Data = 0;
  if (((uVar1 & *(ushort *)((int)puVar3 + 0x13e)) == 0) &&
      (((*puVar3 & 0x800) != 0 || (Data = 0, uVar1 != 0))))
  {
    Data = 1;
  }
  return Data;
}

// decompiled code
// original method signature:
// unsigned long /*$ra*/ MON_GetTime(struct _Instance *instance /*$a0*/)
// line 1926, offset 0x80081844
/* begin block 1 */
// Start line: 3852
/* end block 1 */
// End Line: 3853

/* begin block 2 */
// Start line: 3896
/* end block 2 */
// End Line: 3897

ulong MON_GetTime(_Instance *instance)

{
  if ((instance->object->oflags & 0x80000U) != 0)
  {
    return DAT_800d11d8;
  }
  if ((instance->flags2 & 0x8000000U) == 0)
  {
    return DAT_800d11dc;
  }
  return DAT_800d11e0;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_BirthSoul(struct _Instance *instance /*$s1*/, int link /*$s3*/)
// line 1944, offset 0x80081898
/* begin block 1 */
// Start line: 1945
// Start offset: 0x80081898
// Variables:
// 		struct _MonsterVars *mv; // $s2

/* begin block 1.1 */
// Start line: 1952
// Start offset: 0x800818E4
// Variables:
// 		struct Object *soulob; // $a1

/* begin block 1.1.1 */
// Start line: 1959
// Start offset: 0x800818F8
// Variables:
// 		struct _Instance *isoul; // $s0

/* begin block 1.1.1.1 */
// Start line: 1980
// Start offset: 0x8008195C
// Variables:
// 		struct MATRIX *matrix; // $v1
/* end block 1.1.1.1 */
// End offset: 0x80081980
// End Line: 1984
/* end block 1.1.1 */
// End offset: 0x80081988
// End Line: 1990
/* end block 1.1 */
// End offset: 0x80081988
// End Line: 1993

/* begin block 1.2 */
// Start line: 1996
// Start offset: 0x80081990
// Variables:
// 		struct _Instance *isoul; // $a0
/* end block 1.2 */
// End offset: 0x800819E0
// End Line: 2010
/* end block 1 */
// End offset: 0x800819E0
// End Line: 2012

/* begin block 2 */
// Start line: 3923
/* end block 2 */
// End Line: 3924

/* begin block 3 */
// Start line: 3931
/* end block 3 */
// End Line: 3932

void MON_BirthSoul(_Instance *instance, int link)

{
  _Instance *instance_00;
  MATRIX *pMVar1;
  int introUniqueID;
  void *pvVar2;

  pvVar2 = instance->extraData;
  if (*(short *)((int)pvVar2 + 0x134) != 0)
  {
    introUniqueID = *(int *)((int)pvVar2 + 0xd8);
    if ((introUniqueID == 0) || (0x1fff < introUniqueID))
    {
      if ((DebugMenuLine_800c87c8.type != DEBUG_LINE_TYPE_BIT) &&
          (instance_00 = INSTANCE_BirthObject(instance, (Object *)DebugMenuLine_800c87c8.type, 0),
           instance_00 != (_Instance *)0x0))
      {
        if (0x1fff < *(int *)((int)pvVar2 + 0xd8))
        {
          instance_00->flags2 = instance_00->flags2 | 0x8000000;
          MORPH_SetupInstanceFlags(instance_00);
        }
        if (link == 0)
        {
          instance_00->parent = (_Instance *)0x0;
        }
        else
        {
          *(long *)((int)pvVar2 + 0xd8) = instance_00->introUniqueID;
        }
        pMVar1 = instance->matrix;
        if (pMVar1 != (MATRIX *)0x0)
        {
          (instance_00->position).x = *(short *)pMVar1[1].t;
          (instance_00->position).y = *(short *)(pMVar1[1].t + 1);
          (instance_00->position).z = *(short *)(pMVar1[1].t + 2);
        }
        *(undefined2 *)((int)instance_00->extraData + 0x134) = *(undefined2 *)((int)pvVar2 + 0x134);
      }
    }
    else
    {
      instance_00 = INSTANCE_Find(introUniqueID);
      if (instance_00 == (_Instance *)0x0)
      {
        instance->flags2 = instance->flags2 | 0x80;
      }
      else
      {
        instance->flags2 = instance->flags2 & 0xffffff7f;
        *(long *)((int)pvVar2 + 0xd8) = instance_00->introUniqueID;
        *(long *)((int)instance_00->extraData + 0xd8) = instance->introUniqueID;
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ProcessIntro(struct _Instance *instance /*$s2*/)
// line 2018, offset 0x800819fc
/* begin block 1 */
// Start line: 2019
// Start offset: 0x800819FC
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		long initialBehavior; // $s3
// 		long triggeredBehavior; // $s5
// 		long activeBehavior; // $s6
// 		long guardRange; // $s7
// 		long wanderRange; // $fp
// 		long ambushRange; // $t1
// 		long hitPoints; // $s4
// 		int spectral; // stack offset -56
// 		long flags; // $s1
// 		struct _MonsterAttributes *ma; // $v0

/* begin block 1.1 */
// Start line: 2039
// Start offset: 0x80081AA0
// Variables:
// 		struct INICommand *command; // $a2

/* begin block 1.1.1 */
// Start line: 2093
// Start offset: 0x80081D14
// Variables:
// 		short *pmarker; // $a0
// 		int i; // $a1
// 		long *param; // $v1
/* end block 1.1.1 */
// End offset: 0x80081D3C
// End Line: 2108

/* begin block 1.1.2 */
// Start line: 2117
// Start offset: 0x80081D64
// Variables:
// 		int i; // $a0
// 		short *unit; // $a1
/* end block 1.1.2 */
// End offset: 0x80081D9C
// End Line: 2127
/* end block 1.1 */
// End offset: 0x80081E14
// End Line: 2157
/* end block 1 */
// End offset: 0x80081EF8
// End Line: 2198

/* begin block 2 */
// Start line: 4082
/* end block 2 */
// End Line: 4083

void MON_ProcessIntro(_Instance *instance)

{
  undefined uVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  short *psVar5;
  int iVar6;
  uint *puVar7;
  short *psVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;

  iVar12 = -1;
  iVar14 = -1;
  iVar15 = -1;
  iVar16 = 0;
  iVar17 = 0;
  iVar9 = 0;
  bVar4 = false;
  puVar10 = (uint *)instance->extraData;
  uVar1 = *(undefined *)((int)instance->data + 0x16);
  *(undefined2 *)(puVar10 + 0x4b) = 0x800;
  *(undefined2 *)((int)puVar10 + 0x12e) = 0x400;
  iVar13 = -1;
  *(undefined *)((int)puVar10 + 0x14a) = uVar1;
  puVar10[1] = puVar10[1] | 0x80000000;
  psVar8 = (short *)instance->introData;
  uVar11 = 0;
  if ((psVar8 != (short *)0x0) && ((instance->flags & 2U) == 0))
  {
    sVar2 = *psVar8;
    sVar3 = *psVar8;
    while (sVar2 != 0)
    {
      if (sVar3 == 0xc)
      {
        *(undefined *)((int)puVar10 + 0x142) = *(undefined *)(psVar8 + 2);
      }
      else
      {
        if (sVar3 < 0xd)
        {
          if (sVar3 == 6)
          {
            *(undefined *)((int)puVar10 + 0x14a) = *(undefined *)(psVar8 + 2);
          }
          else
          {
            if (sVar3 < 7)
            {
              if (sVar3 == 3)
              {
                bVar4 = true;
              }
              else
              {
                if (sVar3 < 4)
                {
                  if (sVar3 == 1)
                  {
                    iVar12 = *(int *)(psVar8 + 2);
                  }
                  else
                  {
                    if (sVar3 == 2)
                    {
                      iVar14 = *(int *)(psVar8 + 2);
                    }
                  }
                }
                else
                {
                  if (sVar3 == 4)
                  {
                    iVar17 = *(int *)(psVar8 + 2);
                  }
                  else
                  {
                    if (sVar3 == 5)
                    {
                      iVar16 = *(int *)(psVar8 + 2);
                    }
                  }
                }
              }
            }
            else
            {
              if (sVar3 == 9)
              {
                instance->flags2 = instance->flags2 | 0x20000;
                uVar11 = uVar11 | 0x1000000;
                if (psVar8[1] == 0)
                {
                  *(undefined2 *)((int)puVar10 + 0x136) = 0;
                }
                else
                {
                  *(short *)((int)puVar10 + 0x136) = psVar8[2];
                }
              }
              else
              {
                if (sVar3 < 10)
                {
                  if (sVar3 == 7)
                  {
                    uVar11 = uVar11 | 0x100000;
                  }
                  else
                  {
                    if (sVar3 == 8)
                    {
                      iVar13 = *(int *)(psVar8 + 2);
                    }
                  }
                }
                else
                {
                  if (sVar3 == 10)
                  {
                    iVar6 = (int)psVar8[1];
                    puVar7 = puVar10 + 0x5d;
                    psVar5 = psVar8;
                    while (iVar6 != 0)
                    {
                      psVar5 = psVar5 + 2;
                      iVar6 = iVar6 + -1;
                      *(short *)puVar7 = *psVar5;
                      puVar7 = (uint *)((int)puVar7 + 2);
                    }
                    *(short *)puVar7 = 0;
                    *(uint **)(puVar10 + 99) = puVar10 + 0x5d;
                  }
                  else
                  {
                    if (sVar3 == 0xb)
                    {
                      *(undefined *)(puVar10 + 0x53) = *(undefined *)(psVar8 + 2);
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          if (sVar3 == 0x14)
          {
            iVar15 = *(int *)(psVar8 + 2);
          }
          else
          {
            if (sVar3 < 0x15)
            {
              if (sVar3 == 0xf)
              {
                puVar10[0x36] = *(uint *)(psVar8 + 2);
              }
              else
              {
                if (sVar3 < 0x10)
                {
                  if (sVar3 == 0xd)
                  {
                    *(short *)(puVar10 + 0x46) = psVar8[2];
                  }
                  else
                  {
                    puVar7 = puVar10 + 0x58;
                    if (sVar3 == 0xe)
                    {
                      iVar6 = 0;
                      psVar5 = psVar8;
                      if (0 < psVar8[1])
                      {
                        do
                        {
                          iVar6 = iVar6 + 1;
                          *(short *)puVar7 = psVar5[2];
                          puVar7 = (uint *)((int)puVar7 + 2);
                          psVar5 = psVar5 + 2;
                        } while (iVar6 < psVar8[1]);
                      }
                      *(short *)puVar7 = 0;
                    }
                  }
                }
                else
                {
                  if (sVar3 == 0x10)
                  {
                    *(undefined *)(puVar10 + 0x51) = *(undefined *)(psVar8 + 2);
                    if (puVar10[0x36] == 0)
                    {
                      puVar10[0x36] = 0x7fffffff;
                    }
                  }
                  else
                  {
                    if (sVar3 == 0x11)
                    {
                      puVar10[1] = puVar10[1] & 0x7fffffff;
                    }
                  }
                }
              }
            }
            else
            {
              if (sVar3 == 0x18)
              {
                *(short *)((int)puVar10 + 0x12e) =
                    (short)((ulonglong)((longlong)(*(int *)(psVar8 + 2) * 0x1000) * 0xb60b60b7) >>
                            0x28) -
                    (short)(*(int *)(psVar8 + 2) * 0x1000 >> 0x1f);
              }
              else
              {
                if (sVar3 < 0x19)
                {
                  if (sVar3 == 0x16)
                  {
                    iVar9 = *(int *)(psVar8 + 2);
                  }
                  else
                  {
                    if (sVar3 == 0x17)
                    {
                      *(short *)(puVar10 + 0x4b) =
                          (short)((ulonglong)((longlong)(*(int *)(psVar8 + 2) * 0x1000) * 0xb60b60b7) >> 0x28) - (short)(*(int *)(psVar8 + 2) * 0x1000 >> 0x1f);
                    }
                  }
                }
                else
                {
                  if (sVar3 == 0x19)
                  {
                    *(undefined *)((int)puVar10 + 0x143) = *(undefined *)(psVar8 + 2);
                  }
                }
              }
            }
          }
        }
      }
      psVar8 = psVar8 + (int)psVar8[1] * 2 + 2;
      sVar2 = *psVar8;
      sVar3 = *psVar8;
    }
  }
  MON_SetDefaults(instance);
  *puVar10 = *puVar10 ^ uVar11;
  if (iVar12 != -1)
  {
    *(undefined *)((int)puVar10 + 0x147) = (char)iVar12;
    *(undefined *)((int)puVar10 + 0x146) = (char)iVar12;
  }
  if (iVar14 != -1)
  {
    *(char *)(puVar10 + 0x52) = (char)iVar14;
  }
  if (iVar15 != -1)
  {
    *(undefined *)((int)puVar10 + 0x149) = (char)iVar15;
  }
  if (iVar13 != -1)
  {
    *(short *)(puVar10 + 0x4c) = (short)(iVar13 << 8);
  }
  if (bVar4)
  {
    uVar11 = instance->flags2;
    if ((uVar11 & 0x8000000) == 0)
    {
      uVar11 = uVar11 | 0x8000000;
    }
    else
    {
      uVar11 = uVar11 & 0xf7ffffff;
    }
    instance->flags2 = uVar11;
  }
  if (iVar16 != 0)
  {
    *(short *)(puVar10 + 0x4a) = (short)iVar16;
  }
  if (iVar17 != 0)
  {
    *(short *)(puVar10 + 0x48) = (short)iVar17;
  }
  if (iVar9 != 0)
  {
    *(undefined2 *)((int)puVar10 + 0x12a) = (short)iVar9;
  }
  if (((*(char *)(puVar10 + 0x52) == '\b') && (*(char *)((int)puVar10 + 0x147) != '\x04')) &&
      (*(char *)((int)puVar10 + 0x147) != '\x10'))
  {
    *(undefined *)((int)puVar10 + 0x147) = 4;
    *(undefined *)((int)puVar10 + 0x146) = 4;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SetDefaults(struct _Instance *instance /*$a0*/)
// line 2203, offset 0x80081f28
/* begin block 1 */
// Start line: 2205
// Start offset: 0x80081F28
// Variables:
// 		struct _MonsterVars *mv; // $a1
// 		struct _MonsterAttributes *ma; // $a3
// 		struct _MonsterSubAttributes *subAttr; // $a2
/* end block 1 */
// End offset: 0x80082120
// End Line: 2261

/* begin block 2 */
// Start line: 4620
/* end block 2 */
// End Line: 4621

/* begin block 3 */
// Start line: 4621
/* end block 3 */
// End Line: 4622

void MON_SetDefaults(_Instance *instance)

{
  short sVar1;
  undefined2 uVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;

  puVar3 = (uint *)instance->extraData;
  pvVar5 = instance->data;
  if ((int)*(char *)((int)pvVar5 + 0x28) <= (int)(uint) * (byte *)((int)puVar3 + 0x14a))
  {
    *(char *)((int)puVar3 + 0x14a) = *(char *)((int)pvVar5 + 0x28) + -1;
  }
  uVar4 = *(uint *)((uint) * (byte *)((int)puVar3 + 0x14a) * 4 + *(int *)((int)pvVar5 + 0x30));
  puVar3[0x55] = uVar4;
  instance->currentModel = (ushort) * (byte *)(uVar4 + 0x26);
  sVar1 = *(short *)(uVar4 + 0x14);
  (instance->scale).z = sVar1;
  (instance->scale).y = sVar1;
  (instance->scale).x = sVar1;
  *(undefined *)((int)puVar3 + 0x146) = *(undefined *)(uVar4 + 0x34);
  *(undefined *)((int)puVar3 + 0x147) = *(undefined *)(uVar4 + 0x34);
  *(undefined *)(puVar3 + 0x52) = *(undefined *)(uVar4 + 0x35);
  *(undefined2 *)(puVar3 + 0x48) = *(undefined2 *)(uVar4 + 0x30);
  *(undefined2 *)(puVar3 + 0x4a) = *(undefined2 *)(uVar4 + 0x32);
  uVar2 = *(undefined2 *)(uVar4 + 0x18);
  *(undefined2 *)(puVar3 + 0x4d) = 0x1000;
  *(undefined *)((int)puVar3 + 0x14d) = 3;
  *(undefined *)(puVar3 + 0x54) = 8;
  *(undefined2 *)((int)puVar3 + 0x12a) = uVar2;
  if ((*(int *)(uVar4 + 8) != 0) &&
      (*(short *)(puVar3 + 0x4c) = (short)((int)*(char *)(*(int *)(uVar4 + 8) + 0x1c) << 8),
       *(char *)(*(int *)(uVar4 + 8) + 0x1e) != -1))
  {
    *puVar3 = *puVar3 | 0x20;
  }
  if ((*(char *)((int)puVar3 + 0x14a) == '\x02') && ((*(uint *)((int)pvVar5 + 0x10) & 2) != 0))
  {
    *puVar3 = *puVar3 | 0x10000000;
  }
  if (*(char *)(uVar4 + 0x37) != '\0')
  {
    instance->flags2 = instance->flags2 | 0x8000000;
  }
  *(undefined2 *)((int)puVar3 + 0x13e) = 0x100;
  if (*(char *)(uVar4 + 0x3a) != '\0')
  {
    *(undefined2 *)((int)puVar3 + 0x13e) = 0x110;
  }
  if (*(char *)(uVar4 + 0x39) != '\0')
  {
    *(ushort *)((int)puVar3 + 0x13e) = *(ushort *)((int)puVar3 + 0x13e) | 0x20;
  }
  if (*(char *)(uVar4 + 0x38) != '\0')
  {
    *(ushort *)((int)puVar3 + 0x13e) = *(ushort *)((int)puVar3 + 0x13e) | 0x40;
  }
  if (*(char *)(uVar4 + 0x3c) != '\0')
  {
    *(ushort *)((int)puVar3 + 0x13e) = *(ushort *)((int)puVar3 + 0x13e) | 0x200;
  }
  if (*(char *)(uVar4 + 0x3b) != '\0')
  {
    *(ushort *)((int)puVar3 + 0x13e) = *(ushort *)((int)puVar3 + 0x13e) | 0x80;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_GetPlanSlot(struct _MonsterVars *mv /*$s0*/)
// line 2266, offset 0x80082128
/* begin block 1 */
// Start line: 4749
/* end block 1 */
// End Line: 4750

void MON_GetPlanSlot(_MonsterVars *mv)

{
  int iVar1;

  if ((int)mv->pathSlotID != -1)
  {
    ENMYPLAN_ReleasePlanningWorkspace((int)mv->pathSlotID);
  }
  iVar1 = ENMYPLAN_GetInitializedPlanningWorkspaceFinal();
  mv->pathSlotID = (char)iVar1;
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_DefaultPlanMovement(struct _Instance *instance /*$s2*/, int anim /*$s4*/, long distance /*$s5*/)
// line 2277, offset 0x8008216c
/* begin block 1 */
// Start line: 2278
// Start offset: 0x8008216C
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		int rc; // $s1
// 		int felloff; // $v1
// 		long length; // $s3
// 		struct _MonsterAnim *manim; // $s6

/* begin block 1.1 */
// Start line: 2307
// Start offset: 0x80082260
// Variables:
// 		struct _Position pos; // stack offset -40
// 		int planresult; // $v1

/* begin block 1.1.1 */
// Start line: 2348
// Start offset: 0x80082318
// Variables:
// 		short turnSpeed; // $a2
/* end block 1.1.1 */
// End offset: 0x80082394
// End Line: 2365
/* end block 1.1 */
// End offset: 0x80082394
// End Line: 2365
/* end block 1 */
// End offset: 0x800823E4
// End Line: 2389

/* begin block 2 */
// Start line: 4771
/* end block 2 */
// End Line: 4772

int MON_DefaultPlanMovement(_Instance *instance, int anim, long distance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_GetAnim(instance, **(char ***)((int)pvVar1 + 0x154), anim);
  /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)((int)pvVar1 + 0x112),
                   (int)(instance->position).y - (int)*(short *)((int)pvVar1 + 0x114),
                   (int)(instance->position).z - (int)*(short *)((int)pvVar1 + 0x116));
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_DropAllObjects(struct _Instance *instance /*$a0*/)
// line 2391, offset 0x8008240c
/* begin block 1 */
// Start line: 2392
// Start offset: 0x8008240C
// Variables:
// 		struct _Instance *child; // $a0

/* begin block 1.1 */
// Start line: 2397
// Start offset: 0x8008242C
// Variables:
// 		struct _Instance *next; // $s0
/* end block 1.1 */
// End offset: 0x8008245C
// End Line: 2403
/* end block 1 */
// End offset: 0x80082468
// End Line: 2405

/* begin block 2 */
// Start line: 5002
/* end block 2 */
// End Line: 5003

void MON_DropAllObjects(_Instance *instance)

{
  _Instance *Inst;
  int Data;

  Inst = instance->LinkChild;
  if (Inst != (_Instance *)0x0)
  {
    if (Inst->ParentLinkNode == 3)
    {
      Data = 2;
    }
    else
    {
      Data = 1;
    }
    /* WARNING: Subroutine does not return */
    INSTANCE_Post(Inst, 0x800008, Data);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_EnableHeadMove(struct _Instance *instance /*$a0*/)
// line 2407, offset 0x8008247c
/* begin block 1 */
// Start line: 2408
// Start offset: 0x8008247C
// Variables:
// 		struct _MonsterAttributes *ma; // $s0
/* end block 1 */
// End offset: 0x80082510
// End Line: 2427

/* begin block 2 */
// Start line: 5042
/* end block 2 */
// End Line: 5043

void MON_EnableHeadMove(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  void *pvVar2;
  _G2Anim_Type *anim;

  pvVar2 = instance->data;
  anim = &instance->anim;
  if ((*(byte *)((int)pvVar2 + 0x1a) != 0) &&
      (_Var1 = G2Anim_IsControllerActive(anim, (uint) * (byte *)((int)pvVar2 + 0x1a), 0xe),
       _Var1 == G2FALSE))
  {
    G2Anim_SetControllerAngleOrder(anim, (uint) * (byte *)((int)pvVar2 + 0x1a), 0xe, 1);
    G2Anim_EnableController(anim, (uint) * (byte *)((int)pvVar2 + 0x1a), 0xe);
    if ((uint) * (byte *)((int)pvVar2 + 0x22) != (uint) * (byte *)((int)pvVar2 + 0x1a))
    {
      G2Anim_SetControllerAngleOrder(anim, (uint) * (byte *)((int)pvVar2 + 0x22), 0xe, 1);
      G2Anim_EnableController(anim, (uint) * (byte *)((int)pvVar2 + 0x22), 0xe);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_DisableHeadMove(struct _Instance *instance /*$a0*/)
// line 2429, offset 0x80082524
/* begin block 1 */
// Start line: 2430
// Start offset: 0x80082524
// Variables:
// 		struct _MonsterAttributes *ma; // $s0
/* end block 1 */
// End offset: 0x8008259C
// End Line: 2442

/* begin block 2 */
// Start line: 5086
/* end block 2 */
// End Line: 5087

void MON_DisableHeadMove(_Instance *instance)

{
  byte bVar1;
  _G2Bool_Enum _Var2;
  void *pvVar3;
  _G2Anim_Type *anim;

  pvVar3 = instance->data;
  anim = &instance->anim;
  if ((*(byte *)((int)pvVar3 + 0x1a) != 0) &&
      (_Var2 = G2Anim_IsControllerActive(anim, (uint) * (byte *)((int)pvVar3 + 0x1a), 0xe),
       _Var2 != G2FALSE))
  {
    G2Anim_DisableController(anim, (uint) * (byte *)((int)pvVar3 + 0x1a), 0xe);
    bVar1 = *(byte *)((int)pvVar3 + 0x22);
    if ((bVar1 != 0) && ((uint)bVar1 != (uint) * (byte *)((int)pvVar3 + 0x1a)))
    {
      G2Anim_DisableController(anim, (uint)bVar1, 0xe);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_LookInDirection(struct _Instance *instance /*$a0*/, short tx /*$a1*/, short tz /*$a2*/)
// line 2447, offset 0x800825b0
/* begin block 1 */
// Start line: 2448
// Start offset: 0x800825B0
// Variables:
// 		struct _G2SVector3_Type Rot; // stack offset -32
// 		struct _MonsterAttributes *ma; // $s3
/* end block 1 */
// End offset: 0x80082704
// End Line: 2471

/* begin block 2 */
// Start line: 5122
/* end block 2 */
// End Line: 5123

void MON_LookInDirection(_Instance *instance, short tx, short tz)

{
  byte bVar1;
  void *pvVar2;
  _G2SVector3_Type local_20;

  pvVar2 = instance->data;
  if (*(char *)((int)pvVar2 + 0x1a) != '\0')
  {
    if (*(char *)((int)pvVar2 + 0x22) == *(char *)((int)pvVar2 + 0x1a))
    {
      bVar1 = *(byte *)((int)pvVar2 + 0x1a);
      local_20.x = tx;
      local_20.z = tz;
    }
    else
    {
      local_20.y = 0;
      local_20.x = (short)(((int)tx * 0x46) / 100);
      local_20.z = (short)(((int)tz * 0x46) / 100);
      G2Anim_SetController_Vector(&instance->anim, (uint) * (byte *)((int)pvVar2 + 0x1a), 0xe, &local_20);
      if (*(char *)((int)pvVar2 + 0x22) == '\0')
      {
        return;
      }
      local_20.x = (short)(((int)tx * 0x1e) / 100);
      local_20.z = (short)(((int)tz * 0x1e) / 100);
      bVar1 = *(byte *)((int)pvVar2 + 0x22);
    }
    local_20.y = 0;
    G2Anim_SetController_Vector(&instance->anim, (uint)bVar1, 0xe, &local_20);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_LookAtPos(struct _Instance *instance /*$s1*/, struct _Position *position /*$a1*/)
// line 2478, offset 0x80082724
/* begin block 1 */
// Start line: 2479
// Start offset: 0x80082724
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		short z; // $a0
/* end block 1 */
// End offset: 0x800827D8
// End Line: 2507

/* begin block 2 */
// Start line: 5191
/* end block 2 */
// End Line: 5192

void MON_LookAtPos(_Instance *instance, _Position *position)

{
  short destination;

  destination = MATH3D_AngleFromPosToPos(&instance->position, position);
  /* WARNING: Subroutine does not return */
  AngleDiff((instance->rotation).z, destination);
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ProcessLookAt(struct _Instance *instance /*$s1*/)
// line 2511, offset 0x80082800
/* begin block 1 */
// Start line: 2512
// Start offset: 0x80082800
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x800828E0
// End Line: 2540

/* begin block 2 */
// Start line: 5257
/* end block 2 */
// End Line: 5258

void MON_ProcessLookAt(_Instance *instance)

{
  int *piVar1;

  piVar1 = (int *)instance->extraData;
  if (piVar1[0x3d] != 0x80000)
  {
    if (*piVar1 < 0)
    {
      MON_EnableHeadMove(instance);
      MON_LookAtPos(instance, (_Position *)((int)piVar1 + 0x122));
    }
    else
    {
      if (piVar1[0x43] == 0)
      {
        if ((*(short *)((int)piVar1 + 0x13a) == 0) && (*(short *)(piVar1 + 0x4f) == 0))
        {
          MON_DisableHeadMove(instance);
        }
        else
        {
          AngleMoveToward((short *)((int)piVar1 + 0x13a), 0, 100);
          AngleMoveToward((short *)(piVar1 + 0x4f), 0, 100);
          MON_LookInDirection(instance, *(short *)((int)piVar1 + 0x13a), *(short *)(piVar1 + 0x4f));
        }
      }
      else
      {
        MON_EnableHeadMove(instance);
        MON_LookAtPos(instance, (_Position *)piVar1[0x43]);
        piVar1[0x43] = 0;
      }
    }
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_TakeDamage(struct _Instance *instance /*$a0*/, int damage /*$s2*/, int type /*$s1*/)
// line 2545, offset 0x800828f4
/* begin block 1 */
// Start line: 2546
// Start offset: 0x800828F4
// Variables:
// 		struct _MonsterVars *mv; // $s0

/* begin block 1.1 */
// Start line: 2553
// Start offset: 0x80082938
// Variables:
// 		long whatAmI; // $v1
/* end block 1.1 */
// End offset: 0x80082984
// End Line: 2573
/* end block 1 */
// End offset: 0x80082988
// End Line: 2577

/* begin block 2 */
// Start line: 5325
/* end block 2 */
// End Line: 5326

int MON_TakeDamage(_Instance *instance, int damage, int type)

{
  int iVar1;

  iVar1 = *(int *)(*(int *)((int)instance->extraData + 0x154) + 8);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x1c) != '\0'))
  {
    /* WARNING: Subroutine does not return */
    INSTANCE_Query(instance, 1);
  }
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SetUpSaveInfo(struct _Instance *instance /*$t0*/, struct _MonsterSaveInfo *saveData /*$a3*/)
// line 2582, offset 0x800829a0
/* begin block 1 */
// Start line: 2583
// Start offset: 0x800829A0
// Variables:
// 		struct _MonsterVars *mv; // $a2
// 		struct _MonsterAttributes *ma; // $t1
/* end block 1 */
// End offset: 0x80082B04
// End Line: 2611

/* begin block 2 */
// Start line: 5405
/* end block 2 */
// End Line: 5406

void MON_SetUpSaveInfo(int param_1, uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;

  puVar5 = *(uint **)(param_1 + 0x14c);
  iVar6 = *(int *)(param_1 + 0x24);
  *param_2 = *puVar5 & 0xffbbfffb;
  param_2[1] = puVar5[1] & 0xf7ffffff;
  uVar1 = param_2[3];
  uVar2 = (uint) * (byte *)((int)puVar5 + 0x14a) & 7;
  param_2[3] = uVar1 & 0xfffffff8 | uVar2;
  uVar3 = (*(uint *)(param_1 + 0x178) & 0x3f) << 3;
  param_2[3] = uVar1 & 0xfffffe00 | uVar2 | uVar3;
  uVar4 = ((uint) * (byte *)((int)puVar5 + 0x146) & 0x1f) << 9;
  param_2[3] = uVar1 & 0xffffc000 | uVar2 | uVar3 | uVar4;
  param_2[3] = uVar1 & 0xff1fc000 | uVar2 | uVar3 | uVar4 |
               ((uint) * (byte *)(puVar5 + 0x51) & 7) << 0x15;
  if ((*(int *)(param_1 + 0x178) == 0x17) && (*(char *)(puVar5 + 0x51) == '\0'))
  {
    *(undefined2 *)((int)param_2 + 10) = *(undefined2 *)(puVar5 + 0x35);
  }
  else
  {
    *(undefined2 *)((int)param_2 + 10) = *(undefined2 *)(puVar5 + 0x4d);
  }
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)(puVar5 + 0x36);
  if (puVar5[0x2f] == 0)
  {
    uVar2 = param_2[3];
    uVar1 = SEXT14(*(char *)(iVar6 + 0x2c));
  }
  else
  {
    uVar2 = param_2[3] & 0xffefffff | ((uint)(*(byte *)(param_1 + 0x1b8) >> 1) & 1) << 0x14;
    param_2[3] = uVar2;
    uVar1 = (int)(puVar5[0x2f] - *(int *)(iVar6 + 0x40)) >> 4;
  }
  param_2[3] = uVar2 & 0xfff03fff | (uVar1 & 0x3f) << 0xe;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_GetSaveInfo(struct _Instance *instance /*$s1*/, struct _MonsterSaveInfo *saveData /*$s2*/)
// line 2616, offset 0x80082b0c
/* begin block 1 */
// Start line: 2617
// Start offset: 0x80082B0C
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterAttributes *ma; // $s3

/* begin block 1.1 */
// Start line: 2676
// Start offset: 0x80082CF4
// Variables:
// 		int mode; // $a2
/* end block 1.1 */
// End offset: 0x80082D34
// End Line: 2687
/* end block 1 */
// End offset: 0x80082D34
// End Line: 2689

/* begin block 2 */
// Start line: 5492
/* end block 2 */
// End Line: 5493

void MON_GetSaveInfo(_Instance *instance, _MonsterSaveInfo *saveData)

{
  short sVar1;
  uint index;
  int mode;
  undefined4 local_18;
  uint *puVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  void *pvVar3;

  puVar2 = (uint *)instance->extraData;
  pvVar3 = instance->data;
  index = saveData->age & 7;
  *(undefined *)((int)puVar2 + 0x14a) = (char)index;
  index = *(uint *)(index * 4 + *(int *)((int)pvVar3 + 0x30));
  puVar2[0x55] = index;
  instance->currentModel = (ushort) * (byte *)(index + 0x26);
  if ((saveData->mvFlags & 0x8000U) == 0)
  {
    MON_TurnOffBodySpheres(instance);
  }
  else
  {
    MON_TurnOnBodySpheres(instance);
  }
  *puVar2 = saveData->mvFlags | *puVar2 & 0xc000;
  puVar2[1] = saveData->auxFlags | puVar2[1] & 0x8000000;
  *(byte *)((int)puVar2 + 0x146) = (byte)(saveData->age >> 9) & 0x1f;
  *(byte *)(puVar2 + 0x51) = (byte)(saveData->age >> 0x15) & 7;
  puVar2[0x36] = (int)saveData->soulID;
  *(short *)(puVar2 + 0x4d) = saveData->soulJuice;
  switch (saveData->age >> 3 & 0x3f)
  {
  case 6:
  case 8:
  case 9:
  case 0x15:
  case 0x1c:
    index = 0xd;
    break;
  default:
    index = saveData->age >> 3 & 0x3f;
    break;
  case 10:
  case 0xb:
  case 0xc:
  case 0xe:
    index = 2;
    break;
  case 0x10:
    instance->flags2 = instance->flags2 & 0xffffffbf;
    puVar2[0x36] = 0x7fffffff;
    *puVar2 = *puVar2 | 0x200;
  case 0x17:
    if (*(char *)(puVar2 + 0x51) == '\0')
    {
      sVar1 = *(short *)(puVar2 + 0x4d);
      *(undefined2 *)(puVar2 + 0x4d) = 0x1000;
      puVar2[0x35] = (int)sVar1;
      instance->flags2 = instance->flags2 | 0x80;
    }
    index = 0x17;
  }
  instance->currentMainState = index;
  sVar1 = (instance->oldPos).z;
  *(undefined4 *)&instance->position = *(undefined4 *)&instance->oldPos;
  (instance->position).z = sVar1;
  index = saveData->age >> 0xe & 0x3f;
  mode = 1;
  if ((int)index < (int)*(char *)((int)pvVar3 + 0x2c))
  {
    if ((saveData->age >> 0x14 & 1) != 0)
    {
      mode = 2;
    }
    if (instance->currentMainState == 0x17)
    {
      /* WARNING: Subroutine does not return */
      MON_PlayAnim(instance, (MonsterAnim)CONCAT412(local_c, CONCAT48(local_10, CONCAT44(local_14, local_18))), 0x18);
    }
    MON_PlayAnimID(instance, index, mode);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_KillMonster(struct _Instance *instance /*$s5*/)
// line 2694, offset 0x80082d50
/* begin block 1 */
// Start line: 2695
// Start offset: 0x80082D50
// Variables:
// 		struct _MonsterVars *mv; // $s0

/* begin block 1.1 */
// Start line: 2702
// Start offset: 0x80082D90
// Variables:
// 		struct _MonsterAttributes *attr; // $v0
// 		struct FXSplinter *splintDef; // $v1
/* end block 1.1 */
// End offset: 0x80082DF0
// End Line: 2710
/* end block 1 */
// End offset: 0x80082EF4
// End Line: 2749

/* begin block 2 */
// Start line: 5654
/* end block 2 */
// End Line: 5655

void MON_KillMonster(_Instance *instance)

{
  uint uVar1;
  uint *puVar2;

  puVar2 = (uint *)instance->extraData;
  MON_DropAllObjects(instance);
  if (*(char *)(puVar2 + 0x51) == '\x06')
  {
    _FX_BuildSplinters(instance, (SVECTOR *)0x0, (SVECTOR *)0x0, (SVECTOR *)0x0,
                       *(FXSplinter **)((int)instance->data + 0x4c), gFXT,
                       (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                       (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0, 8);
    if ((instance->flags2 & 0x1000U) == 0)
    {
      SOUND_Play3dSound(&instance->position, 0x30, 0, 0x5f, (int)&DAT_00003e80);
    }
  }
  if (((*puVar2 & 0x1000000) == 0) ||
      ((instance->intro != (Intro *)0x0 && ((instance->intro->flags & 0x400U) != 0))))
  {
    SAVE_MarkDeadDead(instance);
  }
  else
  {
    if (*(short *)((int)puVar2 + 0x136) != 0)
    {
      MONAPI_AddToGenerator(instance);
    }
    SAVE_DeleteInstance(instance);
  }
  uVar1 = instance->object->oflags2;
  if ((uVar1 & 4) != 0)
  {
    if ((instance->flags2 & 0x1000U) != 0)
    {
      SOUND_ProcessInstanceSounds(instance->object->soundData, instance->soundInstanceTbl, &instance->position,
                                  uVar1 & 0x2000000, instance->flags2 & 0x8000000, 0, 0, &instance->flags2);
      SOUND_ProcessInstanceSounds(instance->object->soundData, instance->soundInstanceTbl, &instance->position,
                                  instance->object->oflags2 & 0x2000000, instance->flags2 & 0x8000000, 0, 0,
                                  &instance->flags2);
    }
  }
  instance->flags = instance->flags | 0x20;
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ShouldIAmbushEnemy(struct _Instance *instance /*$s3*/)
// line 2755, offset 0x80082f28
/* begin block 1 */
// Start line: 2756
// Start offset: 0x80082F28
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterIR *enemy; // $s2

/* begin block 1.1 */
// Start line: 2762
// Start offset: 0x80082F7C
// Variables:
// 		struct _Instance *inst; // $s1
// 		struct _Position pos; // stack offset -32
/* end block 1.1 */
// End offset: 0x80082FF8
// End Line: 2779
/* end block 1 */
// End offset: 0x80083078
// End Line: 2797

/* begin block 2 */
// Start line: 5785
/* end block 2 */
// End Line: 5786

int MON_ShouldIAmbushEnemy(_Instance *instance)

{
  _StreamUnit *streamUnit;
  int iVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  _Position local_20;

  pvVar3 = instance->extraData;
  iVar5 = *(int *)((int)pvVar3 + 0xc4);
  if (((instance->currentStreamUnitID == instance->birthStreamUnitID) &&
       (*(char *)((int)pvVar3 + 0x142) != '\0')) &&
      (*(int *)((int)pvVar3 + 300) == 0x4000800))
  {
    iVar4 = DAT_800d0fd8;
    if (iVar5 != 0)
    {
      iVar4 = *(int *)(iVar5 + 4);
    }
    streamUnit = STREAM_GetStreamUnitWithID(instance->birthStreamUnitID);
    iVar1 = PLANAPI_FindNodePositionInUnit(streamUnit, &local_20, (int)*(char *)((int)pvVar3 + 0x142), 4);
    if (iVar1 != 0)
    {
      /* WARNING: Subroutine does not return */
      MATH3D_LengthXYZ((int)*(short *)(iVar4 + 0x5c) - (int)local_20.x,
                       (int)*(short *)(iVar4 + 0x5e) - (int)local_20.y,
                       (int)*(short *)(iVar4 + 0x60) - (int)local_20.z);
    }
  }
  if (iVar5 == 0)
  {
    uVar2 = 0;
  }
  else
  {
    if ((instance->currentMainState != 0x1a) || (uVar2 = 0, (*(ushort *)(iVar5 + 0x16) & 0x40) != 0))
    {
      if (*(int *)((int)pvVar3 + 300) == 0x4000800)
      {
        uVar2 = (uint)(*(short *)(iVar5 + 0x14) < *(short *)((int)pvVar3 + 0x12a));
      }
      else
      {
        uVar2 = 0;
        if (*(short *)(iVar5 + 0x14) < *(short *)((int)pvVar3 + 0x12a))
        {
          MATH3D_RotMatAboutVec((_SVector *)(iVar5 + 0xc), (MATRIX *)(int)*(short *)((int)pvVar3 + 300),
                                *(short *)((int)pvVar3 + 0x12e));
        }
      }
    }
  }
  return uVar2;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ShouldIFireAtTarget(struct _Instance *instance /*$a0*/, struct _MonsterIR *target /*$a1*/)
// line 2802, offset 0x80083094
/* begin block 1 */
// Start line: 2804
// Start offset: 0x80083094
// Variables:
// 		struct _MonsterVars *mv; // $a2

/* begin block 1.1 */
// Start line: 2810
// Start offset: 0x800830C4
// Variables:
// 		struct _MonsterAttributes *ma; // $v1
// 		struct _MonsterMissile *missileAttack; // $a0

/* begin block 1.1.1 */
// Start line: 2815
// Start offset: 0x800830FC
// Variables:
// 		long distance; // $a1

/* begin block 1.1.1.1 */
// Start line: 2819
// Start offset: 0x80083114
// Variables:
// 		struct _MonsterIR *known; // $v1
/* end block 1.1.1.1 */
// End offset: 0x8008317C
// End Line: 2836
/* end block 1.1.1 */
// End offset: 0x8008317C
// End Line: 2837
/* end block 1.1 */
// End offset: 0x8008317C
// End Line: 2838
/* end block 1 */
// End offset: 0x8008317C
// End Line: 2842

/* begin block 2 */
// Start line: 5881
/* end block 2 */
// End Line: 5882

/* begin block 3 */
// Start line: 5882
/* end block 3 */
// End Line: 5883

int MON_ShouldIFireAtTarget(_Instance *instance, _MonsterIR *target)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  if (((((*puVar3 & 0x20) != 0) && ((target->mirFlags & 0x20) != 0)) &&
       (iVar2 = *(int *)((int)instance->data + 0x3c) +
                (int)*(char *)(*(int *)(puVar3[0x55] + 8) + 0x1e) * 0x10,
        *(char *)((int)puVar3 + 0x151) < *(char *)(iVar2 + 0xc))) &&
      ((int)target->distance < (int)(uint) * (ushort *)(iVar2 + 2)))
  {
    piVar1 = (int *)puVar3[0x24];
    while (true)
    {
      if (piVar1 == (int *)0x0)
      {
        return 2;
      }
      if ((((int)*(short *)(piVar1 + 5) < (int)target->distance) &&
           (0 < *(short *)((int)piVar1 + 0xe))) &&
          (*(short *)(piVar1 + 3) < 200))
        break;
      piVar1 = (int *)*piVar1;
    }
    return 0;
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ShouldIFlee(struct _Instance *instance /*$a0*/)
// line 2847, offset 0x80083184
/* begin block 1 */
// Start line: 2848
// Start offset: 0x80083184
// Variables:
// 		struct _MonsterVars *mv; // $s0
// 		struct _MonsterIR *enemy; // $v1
/* end block 1 */
// End offset: 0x80083274
// End Line: 2872

/* begin block 2 */
// Start line: 5984
/* end block 2 */
// End Line: 5985

int MON_ShouldIFlee(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;

  puVar3 = (uint *)instance->extraData;
  uVar2 = puVar3[0x31];
  if (uVar2 == 0)
  {
    return 0;
  }
  if ((*(ushort *)(uVar2 + 0x16) & 8) != 0)
  {
    return 0;
  }
  if (*(short *)(puVar3[0x55] + 0x1a) <= *(short *)(uVar2 + 0x14))
  {
    return 0;
  }
  iVar1 = MON_ValidPosition(instance);
  if (iVar1 != 0)
  {
    if ((*(char *)((int)puVar3 + 0x146) == '\t') ||
        (((*puVar3 & 0x2000000) != 0 &&
          (((puVar3[0x33] == 0 || ((*(ushort *)(puVar3[0x33] + 0x16) & 0x200) == 0)) &&
            (*(short *)(puVar3 + 0x4c) < 0x2000))))))
    {
      return 1;
    }
    if ((*puVar3 & 0x2000) == 0)
    {
      return 0;
    }
    if (*(short *)(puVar3 + 0x4c) == 0)
    {
      return 1;
    }
  }
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_RelocateCoords(struct _Instance *instance /*$a0*/, struct _SVector *offset /*$t0*/)
// line 2877, offset 0x80083284
/* begin block 1 */
// Start line: 2878
// Start offset: 0x80083284
// Variables:
// 		struct _MonsterVars *mv; // $a0
// 		int ox; // $a1
// 		int oy; // $a2
// 		int oz; // $a3
/* end block 1 */
// End offset: 0x80083300
// End Line: 2896

/* begin block 2 */
// Start line: 6044
/* end block 2 */
// End Line: 6045

int MON_ShouldIFireAtTarget(_Instance *instance, _MonsterIR *target)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  void *pvVar5;

  pvVar5 = instance->extraData;
  sVar1 = *(short *)&target->next;
  sVar2 = *(short *)((int)&target->next + 2);
  sVar3 = *(short *)&target->instance;
  *(short *)((int)pvVar5 + 0x112) = *(short *)((int)pvVar5 + 0x112) + sVar1;
  *(short *)((int)pvVar5 + 0x114) = *(short *)((int)pvVar5 + 0x114) + sVar2;
  *(short *)((int)pvVar5 + 0x116) = *(short *)((int)pvVar5 + 0x116) + sVar3;
  *(short *)((int)pvVar5 + 0x11a) = *(short *)((int)pvVar5 + 0x11a) + sVar1;
  *(short *)((int)pvVar5 + 0x11c) = *(short *)((int)pvVar5 + 0x11c) + sVar2;
  *(short *)((int)pvVar5 + 0x11e) = *(short *)((int)pvVar5 + 0x11e) + sVar3;
  iVar4 = -1;
  if ((int)*(char *)((int)pvVar5 + 0x152) != -1)
  {
    ENMYPLAN_RelocatePlanPositions((int)*(char *)((int)pvVar5 + 0x152), (_Position *)target);
  }
  return iVar4;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ValidUnit(struct _Instance *instance /*$a0*/, unsigned long unitId /*$a1*/)
// line 2901, offset 0x80083310
/* begin block 1 */
// Start line: 2903
// Start offset: 0x80083310
// Variables:
// 		struct _MonsterVars *mv; // $v0
// 		short *unit; // $a0
/* end block 1 */
// End offset: 0x80083354
// End Line: 2918

/* begin block 2 */
// Start line: 6098
/* end block 2 */
// End Line: 6099

/* begin block 3 */
// Start line: 6099
/* end block 3 */
// End Line: 6100

int MON_ValidUnit(_Instance *instance, ulong unitId)

{
  ushort uVar1;
  ushort *puVar2;

  puVar2 = (ushort *)((int)instance->extraData + 0x160);
  if (*(short *)((int)instance->extraData + 0x160) != 0)
  {
    while (uVar1 = *puVar2, puVar2 = puVar2 + 1, (unitId & 0xffff) != (uint)uVar1)
    {
      if (*puVar2 == 0)
      {
        return 0;
      }
    }
  }
  return 1;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ValidPosition(struct _Instance *instance /*$s0*/)
// line 2923, offset 0x8008335c
/* begin block 1 */
// Start line: 2924
// Start offset: 0x8008335C

/* begin block 1.1 */
// Start line: 2925
// Start offset: 0x80083380
// Variables:
// 		struct _MonsterVars *mv; // $v1
/* end block 1.1 */
// End offset: 0x80083388
// End Line: 2932
/* end block 1 */
// End offset: 0x800833A4
// End Line: 2933

/* begin block 2 */
// Start line: 6144
/* end block 2 */
// End Line: 6145

int MON_ValidPosition(_Instance *instance)

{
  short sVar1;
  int iVar2;
  void *pvVar3;

  iVar2 = MON_ValidUnit(instance, instance->currentStreamUnitID);
  if (iVar2 != 0)
  {
    pvVar3 = instance->extraData;
    sVar1 = (instance->position).z;
    *(undefined4 *)((int)pvVar3 + 0x11a) = *(undefined4 *)&instance->position;
    *(short *)((int)pvVar3 + 0x11e) = sVar1;
  }
  return (uint)(iVar2 != 0);
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SphereWorldPos(struct MATRIX *mat /*$s1*/, struct _HSphere *sphere /*$a1*/, struct _Position *ret /*$s0*/)
// line 2936, offset 0x800833b4
/* begin block 1 */
// Start line: 6175
/* end block 1 */
// End Line: 6176

void MON_SphereWorldPos(MATRIX *mat, _HSphere *sphere, _Position *ret)

{
  /* WARNING: Subroutine does not return */
  ApplyMatrixSV(mat, &sphere->position);
}

// decompiled code
// original method signature:
// struct _HPrim * /*$ra*/ MON_FindSphereForTerrain(struct _Instance *instance /*$a0*/)
// line 2945, offset 0x80083424
/* begin block 1 */
// Start line: 2947
// Start offset: 0x80083424
// Variables:
// 		struct _HModel *hmodel; // $v0
// 		struct _HPrim *usePrim; // $a3
// 		struct _HPrim *currentP; // $a0
// 		struct _HSphere *tempS; // $v0
// 		int maxRad; // $a2
// 		int i; // $a1
/* end block 1 */
// End offset: 0x800834A8
// End Line: 2975

/* begin block 2 */
// Start line: 6193
/* end block 2 */
// End Line: 6194

/* begin block 3 */
// Start line: 6194
/* end block 3 */
// End Line: 6195

/* begin block 4 */
// Start line: 6195
/* end block 4 */
// End Line: 6196

_HPrim *MON_FindSphereForTerrain(_Instance *instance)

{
  ushort uVar1;
  _HModel *p_Var2;
  _HPrim *p_Var3;
  int iVar4;
  ushort uVar5;
  _HPrim *p_Var6;

  p_Var6 = (_HPrim *)0x0;
  uVar5 = 0;
  if (instance->hModelList != (_HModel *)0x0)
  {
    p_Var2 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var2->numHPrims;
    p_Var3 = p_Var2->hPrimList;
    while (iVar4 != 0)
    {
      if (((undefined **)(*(uint *)p_Var3 & 0xff0200) == &PTR_00010200) &&
          (uVar1 = *(ushort *)(p_Var3->data + 0xe), uVar5 < uVar1))
      {
        p_Var6 = p_Var3;
        uVar5 = uVar1;
      }
      iVar4 = iVar4 + -1;
      p_Var3 = p_Var3 + 1;
    }
  }
  return p_Var6;
}

// decompiled code
// original method signature:
// struct Intro * /*$ra*/ MON_FindNearestImpalingIntro(int unitID /*$a0*/, struct _Position *position /*$s4*/)
// line 2979, offset 0x800834b0
/* begin block 1 */
// Start line: 2980
// Start offset: 0x800834B0
// Variables:
// 		struct Intro *current; // $v1
// 		struct Intro *res; // $s2
// 		struct Level *level; // $v0
// 		int min_dist; // $s3
// 		int dist; // $v1
// 		int i; // $s1
/* end block 1 */
// End offset: 0x800835BC
// End Line: 3023

/* begin block 2 */
// Start line: 6271
/* end block 2 */
// End Line: 6272

Intro *MON_FindNearestImpalingIntro(int unitID, _Position *position)

{
  /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(unitID);
}

// decompiled code
// original method signature:
// struct Intro * /*$ra*/ MON_TestForTerrainImpale(struct _Instance *instance /*$s0*/, struct _Terrain *terrain /*$s1*/)
// line 3027, offset 0x800835e0
/* begin block 1 */
// Start line: 3028
// Start offset: 0x800835E0
// Variables:
// 		struct _MonsterVars *mv; // $v0
// 		struct Intro *current; // $s1
// 		struct _HPrim *prim; // $v1
// 		struct _HSphere *sphere; // $a1
// 		int i; // $s2
// 		int radius; // $s3
// 		struct _Position spherePos; // stack offset -32
/* end block 1 */
// End offset: 0x800836C0
// End Line: 3070

/* begin block 2 */
// Start line: 6385
/* end block 2 */
// End Line: 6386

undefined4 MON_TestForTerrainImpale(_Instance *param_1, int param_2)

{
  _HPrim *p_Var1;
  short *psVar2;
  int iVar3;
  _Position _Stack32;

  if (*(int *)((int)param_1->extraData + 0xf4) == 0x100000)
  {
    p_Var1 = MON_FindSphereForTerrain(param_1);
    if (p_Var1 != (_HPrim *)0x0)
    {
      MON_SphereWorldPos(param_1->matrix + p_Var1->segment, (_HSphere *)p_Var1->data, &_Stack32);
      iVar3 = *(int *)(param_2 + 8);
      psVar2 = (short *)(*(int *)(param_2 + 0xc) + 0x24);
      while (iVar3 != 0)
      {
        if ((*(uint *)(psVar2 + 4) & 0x8000) != 0)
        {
          /* WARNING: Subroutine does not return */
          MATH3D_LengthXYZ((int)_Stack32.x - (int)psVar2[-2], (int)_Stack32.y - (int)psVar2[-1],
                           (int)_Stack32.z - (int)*psVar2);
        }
        iVar3 = iVar3 + -1;
        psVar2 = psVar2 + 0x26;
      }
    }
  }
  return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_MoveInstanceToImpalePoint(struct _Instance *instance /*$s0*/)
// line 3072, offset 0x800836dc
/* begin block 1 */
// Start line: 3073
// Start offset: 0x800836DC
// Variables:
// 		struct _MonsterVars *mv; // $v1
// 		struct Intro *impaler; // $t3
// 		struct _Position offset; // stack offset -16

/* begin block 1.1 */
// Start line: 3097
// Start offset: 0x80083718
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v1
// 		short _z0; // $a2
// 		short _y1; // $t0
// 		short _z1; // $t2
// 		struct _Position *_v; // $a3
// 		struct _Position *_v1; // $a1
/* end block 1.1 */
// End offset: 0x80083718
// End Line: 3097

/* begin block 1.2 */
// Start line: 3097
// Start offset: 0x80083718
// Variables:
// 		short _x1; // $v1
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _Rotation *_v0; // $v0
// 		struct _Rotation *_v1; // $v0
/* end block 1.2 */
// End offset: 0x80083718
// End Line: 3097
/* end block 1 */
// End offset: 0x800837B0
// End Line: 3107

/* begin block 2 */
// Start line: 6491
/* end block 2 */
// End Line: 6492

void MON_MoveInstanceToImpalePoint(_Instance *instance)

{
  short sVar1;
  short sVar2;
  Intro *pIVar3;
  SVECTOR local_10;

  if ((instance->matrix != (MATRIX *)0x0) &&
      (pIVar3 = INSTANCE_FindIntro(instance->currentStreamUnitID,
                                   *(long *)((int)instance->extraData + 400)),
       pIVar3 != (Intro *)0x0))
  {
    local_10.vx = (pIVar3->position).x - *(short *)instance->matrix[3].t;
    local_10.vy = (pIVar3->position).y - *(short *)(instance->matrix[3].t + 1);
    local_10.vz = (pIVar3->position).z - *(short *)(instance->matrix[3].t + 2);
    (instance->position).x = (instance->position).x + local_10.vx;
    (instance->position).y = (instance->position).y + local_10.vy;
    (instance->position).z = (instance->position).z + local_10.vz;
    sVar1 = (pIVar3->rotation).y;
    sVar2 = (pIVar3->rotation).z;
    (instance->rotation).x = (pIVar3->rotation).x;
    (instance->rotation).y = sVar1;
    (instance->rotation).z = sVar2;
    COLLIDE_UpdateAllTransforms(instance, &local_10);
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_ReachableIntro(struct _Instance *instance /*stack 0*/, struct _Position *pos /*$fp*/, struct _Position *introPos /*$s7*/, struct _Rotation *introRot /*stack 12*/, int checkOrientation /*stack 16*/)
// line 3121, offset 0x800837c0
/* begin block 1 */
// Start line: 3122
// Start offset: 0x800837C0
// Variables:
// 		struct _MonsterVars *mv; // $s2
// 		int angle; // $s5
// 		int angle2; // $s6
// 		int angle3; // $v1
// 		int flightAngle; // $v0
// 		int length; // $v0
// 		int length2; // $s4
// 		int newFVel; // $s0
// 		int newZVel; // $s1
// 		int zDiff; // $s1
// 		int zAccl; // $s3
// 		int tempFVel; // $v1
// 		int maxForwardVel; // $s1
// 		int res; // $s3
/* end block 1 */
// End offset: 0x80083B7C
// End Line: 3241

/* begin block 2 */
// Start line: 6605
/* end block 2 */
// End Line: 6606

/* WARNING: Removing unreachable block (ram,0x8008395c) */

int MON_ReachableIntro(_Instance *param_1, _Position *param_2, _Position *param_3, _Rotation *param_4,
                       int param_5)

{
  bool bVar1;
  short angle;
  int square;
  int iVar2;
  int iVar3;
  uint uVar4;
  _Normal *p_Var5;
  long lVar6;
  uint uVar7;
  _Instance *instance;
  _Position *pos;
  _Position *introPos;
  _Rotation *introRot;
  int unaff_s0;
  long lVar8;
  void *pvVar9;
  short sVar10;
  int square_00;

  square = (int)param_2->x - (int)param_3->x;
  introPos = (_Position *)(square * square);
  square = (int)param_2->y - (int)param_3->y;
  iVar2 = (int)param_2->z - (int)param_3->z;
  pvVar9 = param_1->extraData;
  iVar3 = (int)*(short *)(*(int *)((int)pvVar9 + 0x154) + 0x44);
  angle = 0;
  sVar10 = 0;
  lVar8 = 0;
  square = (int)&introPos->x + iVar2 * iVar2 + square * square;
  bVar1 = false;
  if ((square < iVar3 * iVar3) &&
      (iVar2 = (int)*(short *)(*(int *)((int)pvVar9 + 0x154) + 0x42), iVar2 * iVar2 < square))
  {
    introRot = param_4;
    angle = MATH3D_AngleFromPosToPos(param_2, param_3);
    if (param_5 != 0)
    {
      uVar7 = ((int)(param_1->rotation).z + 0x800U & 0xfff) - (int)angle & 0xfff;
      iVar2 = (int)*(short *)(*(int *)((int)pvVar9 + 0x154) + 0x46);
      if (uVar7 < 0x801)
      {
        if ((int)uVar7 < iVar2)
        {
          param_5 = 0;
        }
      }
      else
      {
        iVar3 = uVar7 - 0x1000;
        if (iVar3 < 0)
        {
          iVar3 = -iVar3;
        }
        if (iVar3 < iVar2)
        {
          param_5 = 0;
        }
      }
      if (param_5 != 0)
        goto LAB_80083a6c;
    }
    if (param_4 != (_Rotation *)0x0)
    {
      uVar7 = (int)param_4->x + 0x400U & 0xfff;
      uVar4 = uVar7 - 0x1000;
      if ((0x800 < uVar7) && (uVar7 = uVar4, (int)uVar4 < 0))
      {
        uVar7 = -uVar4;
      }
      if (0x7f < (int)uVar7)
      {
        uVar7 = (int)angle + 0x800U & 0xfff;
        sVar10 = (short)uVar7;
        instance = (_Instance *)((int)param_4->z - uVar7 & 0xfff);
        pos = (_Position *)(int)*(short *)(*(int *)((int)pvVar9 + 0x154) + 0x46);
        if ((_Instance *)&DAT_00000800 < instance)
        {
          p_Var5 = &instance[-7].wNormal;
          if ((int)p_Var5 < 0)
          {
            p_Var5 = (_Normal *)-(int)p_Var5;
          }
          if ((int)p_Var5 < (int)pos)
          {
            uVar7 = (uint)(ushort)param_4->x & 0xfff;
            if (0x800 < uVar7)
            {
              uVar7 = uVar7 - 0x1000;
            }
            bVar1 = true;
            if ((int)uVar7 < 1)
            {
              iVar2 = (int)*(short *)(*(int *)((int)pvVar9 + 0x154) + 0x4a);
              lVar8 = iVar2 - (int)((iVar2 - *(short *)(*(int *)((int)pvVar9 + 0x154) + 0x48)) *
                                    -uVar7) /
                                  0x380;
            }
            else
            {
              lVar8 = (long)*(short *)(*(int *)((int)pvVar9 + 0x154) + 0x4a);
            }
          }
        }
        else
        {
          if ((int)instance < (int)pos)
          {
            square = FUN_800839dc(instance, pos, introPos, introRot, unaff_s0);
            return square;
          }
        }
        goto LAB_80083a6c;
      }
    }
    bVar1 = true;
    lVar8 = (long)*(short *)(*(int *)((int)pvVar9 + 0x154) + 0x48);
  }
LAB_80083a6c:
  if (bVar1)
  {
    iVar2 = (int)param_3->z - (int)param_2->z;
    iVar3 = param_1->zAccl;
    if (iVar2 != 0)
    {
      square_00 = (iVar3 * square) / (iVar2 * 2);
      if (square_00 < 0)
      {
        square_00 = -square_00;
      }
      if (square_00 < lVar8 * lVar8)
      {
        lVar8 = MATH3D_FastSqrt0(square_00);
      }
    }
    lVar6 = MATH3D_FastSqrt0(square);
    iVar2 = (iVar2 * lVar8) / lVar6 - (iVar3 * lVar6) / (lVar8 << 1);
    square = iVar2;
    if (iVar2 < 0)
    {
      square = -iVar2;
    }
    if (square < *(short *)(*(int *)((int)pvVar9 + 0x154) + 0x4c))
    {
      if (param_4 != (_Rotation *)0x0)
      {
        (param_1->rotation).z = sVar10;
      }
      PhysicsSetVelFromZRot(param_1, angle, lVar8 + 1);
      param_1->zVel = iVar2;
      return 1;
    }
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_SetVelocityTowardsImpalingObject(struct _Instance *instance /*$s3*/, int checkOrientation /*$s4*/)
// line 3244, offset 0x80083bac
/* begin block 1 */
// Start line: 3245
// Start offset: 0x80083BAC
// Variables:
// 		struct Level *level; // $s0
// 		struct Intro *currentI; // $s1
// 		struct _HPrim *usePrim; // $v0
// 		int i; // $s2
// 		struct _Position spherePos; // stack offset -32

/* begin block 1.1 */
// Start line: 3259
// Start offset: 0x80083C04
// Variables:
// 		struct _Instance *target; // $s0

/* begin block 1.1.1 */
// Start line: 3284
// Start offset: 0x80083CA4
// Variables:
// 		struct PhysObProperties *prop; // $v1

/* begin block 1.1.1.1 */
// Start line: 3287
// Start offset: 0x80083CBC
/* end block 1.1.1.1 */
// End offset: 0x80083CEC
// End Line: 3296
/* end block 1.1.1 */
// End offset: 0x80083CEC
// End Line: 3297
/* end block 1.1 */
// End offset: 0x80083CFC
// End Line: 3299
/* end block 1 */
// End offset: 0x80083D00
// End Line: 3303

/* begin block 2 */
// Start line: 6905
/* end block 2 */
// End Line: 6906

int MON_SetVelocityTowardsImpalingObject(_Instance *instance, int checkOrientation)

{
  /* WARNING: Subroutine does not return */
  STREAM_GetLevelWithID(instance->currentStreamUnitID);
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOffSphereCollisions(struct _Instance *instance /*$a0*/)
// line 3312, offset 0x80083d20
/* begin block 1 */
// Start line: 3314
// Start offset: 0x80083D20
// Variables:
// 		int i; // $a0
// 		struct _HPrim *hprim; // $v1
// 		struct _HModel *hmodel; // $v1
/* end block 1 */
// End offset: 0x80083D74
// End Line: 3330

/* begin block 2 */
// Start line: 7064
/* end block 2 */
// End Line: 7065

/* begin block 3 */
// Start line: 7065
/* end block 3 */
// End Line: 7066

/* begin block 4 */
// Start line: 7067
/* end block 4 */
// End Line: 7068

void MON_TurnOffSphereCollisions(_Instance *instance)

{
  _HPrim *p_Var1;
  byte *pbVar2;
  int iVar3;

  iVar3 = instance->hModelList[instance->currentModel].numHPrims;
  if ((iVar3 != 0) &&
      (p_Var1 = instance->hModelList[instance->currentModel].hPrimList, pbVar2 = &p_Var1->withFlags,
       (p_Var1->withFlags & 0x20) != 0))
  {
    do
    {
      iVar3 = iVar3 + -1;
      *pbVar2 = *pbVar2 & 0xdf;
      pbVar2 = pbVar2 + 8;
    } while (iVar3 != 0);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_TurnOnSphereCollisions(struct _Instance *instance /*$a0*/)
// line 3332, offset 0x80083d7c
/* begin block 1 */
// Start line: 3334
// Start offset: 0x80083D7C
// Variables:
// 		int i; // $a0
// 		struct _HPrim *hprim; // $v1
// 		struct _HModel *hmodel; // $v1
/* end block 1 */
// End offset: 0x80083DD0
// End Line: 3350

/* begin block 2 */
// Start line: 7106
/* end block 2 */
// End Line: 7107

/* begin block 3 */
// Start line: 7107
/* end block 3 */
// End Line: 7108

/* begin block 4 */
// Start line: 7109
/* end block 4 */
// End Line: 7110

void MON_TurnOnSphereCollisions(_Instance *instance)

{
  _HPrim *p_Var1;
  byte *pbVar2;
  int iVar3;

  iVar3 = instance->hModelList[instance->currentModel].numHPrims;
  if ((iVar3 != 0) &&
      (p_Var1 = instance->hModelList[instance->currentModel].hPrimList, pbVar2 = &p_Var1->withFlags,
       (p_Var1->withFlags & 0x20) == 0))
  {
    do
    {
      iVar3 = iVar3 + -1;
      *pbVar2 = *pbVar2 | 0x20;
      pbVar2 = pbVar2 + 8;
    } while (iVar3 != 0);
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_ProcessSpecialFade(struct _Instance *instance /*$s0*/)
// line 3352, offset 0x80083dd8
/* begin block 1 */
// Start line: 3353
// Start offset: 0x80083DD8
// Variables:
// 		struct _MonsterVars *mv; // $a0
// 		int currentFadeValue; // $a1
// 		int targetFadeValue; // $v1
// 		int fadeRate; // $a3
// 		struct _Instance *child; // $v1
/* end block 1 */
// End offset: 0x80084004
// End Line: 3447

/* begin block 2 */
// Start line: 7148
/* end block 2 */
// End Line: 7149

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MON_ProcessSpecialFade(_Instance *instance)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  _Instance *p_Var4;
  void *pvVar5;
  int iVar6;
  short sVar7;
  int iVar8;

  pvVar5 = instance->extraData;
  if ((instance->object->oflags & 0x80000U) == 0)
  {
    if ((*(uint *)((int)pvVar5 + 4) & 0x8000000) != 0)
    {
      iVar3 = (int)*(short *)((int)pvVar5 + 0x196) * DAT_800d11ec;
      sVar2 = *(short *)((int)pvVar5 + 0x194);
      if (iVar3 < 0)
      {
        iVar3 = iVar3 + 0xfff;
      }
      iVar3 = (int)instance->fadeValue + (iVar3 >> 0xc);
      if ((int)*(short *)((int)pvVar5 + 0x196) < 1)
      {
        bVar1 = iVar3 < sVar2;
      }
      else
      {
        bVar1 = sVar2 < iVar3;
      }
      sVar7 = (short)iVar3;
      if (bVar1)
      {
        *(uint *)((int)pvVar5 + 4) = *(uint *)((int)pvVar5 + 4) & 0xf7ffffff;
        sVar7 = sVar2;
      }
      instance->fadeValue = sVar7;
    }
  }
  else
  {
    if ((instance->currentMainState != 0x17) && (instance->currentMainState != 0x10))
    {
      if ((_DAT_800d0fb4 == 1000) || ((DAT_800d0fb6 == 1 && (DAT_800d0fb4 != 1000))))
      {
        iVar3 = (int)*(short *)((int)pvVar5 + 0x194);
        iVar8 = 0x1000 - iVar3;
      }
      else
      {
        iVar8 = (int)*(short *)((int)pvVar5 + 0x194);
        iVar3 = 0x1000 - iVar8;
      }
      iVar6 = (int)DAT_800d0fb4;
      if (iVar6 < 0x14d)
      {
        iVar6 = (0x1000 - iVar8) * iVar6;
        sVar2 = (short)iVar8 +
                ((short)((ulonglong)((longlong)iVar6 * 0xc4ce07b1) >> 0x28) - (short)(iVar6 >> 0x1f));
      }
      else
      {
        if (iVar6 < 0x29b)
        {
          sVar2 = 0x1000;
        }
        else
        {
          iVar3 = (iVar3 + -0x1000) * (iVar6 + -0x29a);
          sVar2 = ((short)((ulonglong)((longlong)iVar3 * 0xc4ce07b1) >> 0x28) -
                   (short)(iVar3 >> 0x1f)) +
                  0x1000;
        }
      }
      instance->fadeValue = sVar2;
      if (instance->fadeValue < 0)
      {
        instance->fadeValue = 0;
      }
      else
      {
        if (0x1000 < instance->fadeValue)
        {
          instance->fadeValue = 0x1000;
        }
      }
      if (instance->fadeValue == 0x1000)
      {
        MON_TurnOffSphereCollisions(instance);
        instance->flags = instance->flags | 0x800;
      }
      else
      {
        MON_TurnOnSphereCollisions(instance);
        instance->flags = instance->flags & 0xfffff7ff;
      }
    }
  }
  p_Var4 = instance->LinkChild;
  while (p_Var4 != (_Instance *)0x0)
  {
    p_Var4->fadeValue = instance->fadeValue;
    p_Var4 = p_Var4->LinkSibling;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_StartSpecialFade(struct _Instance *instance /*$a0*/, int fadeLevel /*$a1*/, int fadeTime /*$a2*/)
// line 3449, offset 0x80084014
/* begin block 1 */
// Start line: 3451
// Start offset: 0x80084014
// Variables:
// 		struct _MonsterVars *mv; // $a3
// 		int diff; // $a1
/* end block 1 */
// End offset: 0x80084074
// End Line: 3464

/* begin block 2 */
// Start line: 7351
/* end block 2 */
// End Line: 7352

/* begin block 3 */
// Start line: 7352
/* end block 3 */
// End Line: 7353

void MON_StartSpecialFade(_Instance *instance, int fadeLevel, int fadeTime)

{
  void *pvVar1;
  uint uVar2;

  pvVar1 = instance->extraData;
  *(undefined2 *)((int)pvVar1 + 0x194) = (short)fadeLevel;
  *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) | 0x8000000;
  fadeLevel = fadeLevel - instance->fadeValue;
  if (fadeTime < 1)
  {
    fadeTime = 1;
  }
  uVar2 = fadeLevel / fadeTime;
  *(undefined2 *)((int)pvVar1 + 0x196) = (short)uVar2;
  if ((uVar2 & 0xffff) == 0)
  {
    if (fadeLevel < 0)
    {
      *(undefined2 *)((int)pvVar1 + 0x196) = 0xffff;
      return;
    }
    *(undefined2 *)((int)pvVar1 + 0x196) = 1;
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_UnlinkFromRaziel(struct _Instance *instance /*$s0*/)
// line 3466, offset 0x8008407c
/* begin block 1 */
// Start line: 3467
// Start offset: 0x8008407C
// Variables:
// 		struct _MonsterVars *mv; // $v0
// 		struct evPositionData *data; // $v1
// 		struct _Instance *enemy; // $s1
/* end block 1 */
// End offset: 0x800840F8
// End Line: 3485

/* begin block 2 */
// Start line: 7386
/* end block 2 */
// End Line: 7387

void MON_UnlinkFromRaziel(_Instance *instance)

{
  undefined4 local_10;
  undefined4 local_c;

  INSTANCE_UnlinkFromParent(instance);
  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_c, local_10));
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_BurnInAir(struct _Instance *instance /*$s1*/, int currentState /*$s2*/)
// line 3491, offset 0x8008411c
/* begin block 1 */
// Start line: 3492
// Start offset: 0x8008411C
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x8008419C
// End Line: 3502

/* begin block 2 */
// Start line: 7436
/* end block 2 */
// End Line: 7437

void MON_BurnInAir(_Instance *instance, int currentState)

{
  uint *puVar1;

  puVar1 = (uint *)instance->extraData;
  if ((*puVar1 & 0x400000) == 0)
  {
    /* WARNING: Subroutine does not return */
    *puVar1 = *puVar1 | 0x400000;
    MON_GetTime(instance);
  }
  instance->currentMainState = currentState;
  *puVar1 = *puVar1 & 0xfffffffe;
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_BirthMana(struct _Instance *instance /*$s0*/)
// line 3508, offset 0x800841d8
/* begin block 1 */
// Start line: 3509
// Start offset: 0x800841D8

/* begin block 1.1 */
// Start line: 3512
// Start offset: 0x800841F8
// Variables:
// 		struct _MonsterVars *mv; // $v0

/* begin block 1.1.1 */
// Start line: 3516
// Start offset: 0x80084214
// Variables:
// 		int type; // $a0
// 		struct MATRIX *mat; // $a3
/* end block 1.1.1 */
// End offset: 0x80084280
// End Line: 3519
/* end block 1.1 */
// End offset: 0x80084280
// End Line: 3520
/* end block 1 */
// End offset: 0x80084280
// End Line: 3521

/* begin block 2 */
// Start line: 7472
/* end block 2 */
// End Line: 7473

void MON_BirthMana(_Instance *instance)

{
  if ((instance->matrix != (MATRIX *)0x0) && (*(char *)((int)instance->extraData + 0x151) < '\x19'))
  {
    /* WARNING: Subroutine does not return */
    rand();
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SoulSucked(struct _Instance *instance /*$s1*/)
// line 3523, offset 0x80084290
/* begin block 1 */
// Start line: 3524
// Start offset: 0x80084290
// Variables:
// 		struct _MonsterVars *mv; // $s0
/* end block 1 */
// End offset: 0x800842F4
// End Line: 3535

/* begin block 2 */
// Start line: 7505
/* end block 2 */
// End Line: 7506

void MON_SoulSucked(_Instance *param_1)

{
  if ((*(uint *)param_1->extraData & 0x200) != 0)
  {
    if ((*(uint *)((int)param_1->data + 0x10) & 8) == 0)
    {
      /* WARNING: Subroutine does not return */
      MON_GetTime(param_1);
    }
    *(uint *)(param_1->extraData + 0x36) = 0;
    MON_BirthMana(param_1);
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ MON_SetUpKnockBack(struct _Instance *instance /*$s2*/, struct _Instance *enemy /*$s1*/, struct evMonsterHitData *data /*$a2*/)
// line 3540, offset 0x80084308
/* begin block 1 */
// Start line: 3541
// Start offset: 0x80084308
// Variables:
// 		struct _MonsterVars *mv; // $s5
// 		long d; // $s0
// 		long t; // $s4
// 		long a; // $s3
// 		long v; // $s0
// 		int front; // $s0
/* end block 1 */
// End offset: 0x800843CC
// End Line: 3570

/* begin block 2 */
// Start line: 7539
/* end block 2 */
// End Line: 7540

int MON_SetUpKnockBack(_Instance *instance, _Instance *enemy, evMonsterHitData *data)

{
  short sVar1;
  long a;
  long v;

  sVar1 = data->knockBackDistance;
  a = PHYSICS_FindAFromDAndT((int)sVar1, (int)data->knockBackDuration);
  v = PHYSICS_FindVFromAAndD(a, (int)sVar1);
  sVar1 = MATH3D_AngleFromPosToPos(&instance->position, &enemy->position);
  if ((((instance->rotation).z - sVar1) + 0x400U & 0xfff) < 0x800)
  {
    MON_TurnToPosition(instance, &enemy->position, 0x1000);
    PHYSICS_SetVAndAFromRot(instance, &instance->rotation, -v, a);
  }
  else
  {
    PHYSICS_SetVAndAFromRot(instance, &instance->rotation, v, -a);
  }
  /* WARNING: Subroutine does not return */
  MON_GetTime(instance);
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_DoDrainEffects(struct _Instance *instance /*$s1*/, struct _Instance *ei /*$s0*/)
// line 3575, offset 0x8008440c
/* begin block 1 */
// Start line: 3576
// Start offset: 0x8008440C
// Variables:
// 		struct _MonsterAttributes *ma; // $s3
// 		struct _MonsterVars *mv; // $s2
// 		struct MATRIX *mat; // $t2
// 		struct _SVector location; // stack offset -56
// 		struct _SVector position; // stack offset -48
// 		struct _SVector vel; // stack offset -40
// 		struct _SVector accel; // stack offset -32
/* end block 1 */
// End offset: 0x8008467C
// End Line: 3621

/* begin block 2 */
// Start line: 7610
/* end block 2 */
// End Line: 7611

void MON_DoDrainEffects(void)

{
  undefined auStack32[8];

  /* WARNING: Subroutine does not return */
  memset(auStack32, 0, 8);
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_SetFXHitData(struct _Instance *instance /*$a0*/, struct evFXHitData *data /*$a1*/, int type /*$a2*/, int amount /*$a3*/)
// line 3623, offset 0x80084698
/* begin block 1 */
// Start line: 3625
// Start offset: 0x80084698

/* begin block 1.1 */
// Start line: 3629
// Start offset: 0x800846B0
// Variables:
// 		struct MATRIX *mat; // $v0
/* end block 1.1 */
// End offset: 0x800846B0
// End Line: 3629
/* end block 1 */
// End offset: 0x80084714
// End Line: 3640

/* begin block 2 */
// Start line: 7778
/* end block 2 */
// End Line: 7779

/* begin block 3 */
// Start line: 7779
/* end block 3 */
// End Line: 7780

void MON_SetFXHitData(_Instance *instance, evFXHitData *data, int type, int amount)

{
  MATRIX *pMVar1;

  data->type = (short)type;
  data->amount = (short)amount;
  if (instance->matrix == (MATRIX *)0x0)
  {
    (data->location).x = (instance->position).x;
    (data->location).y = (instance->position).y;
    (data->location).z = (instance->position).z + 0x100;
  }
  else
  {
    pMVar1 = instance->matrix + *(byte *)((int)instance->data + 0x22);
    (data->location).x = *(short *)pMVar1->t;
    (data->location).y = *(short *)(pMVar1->t + 1);
    (data->location).z = *(short *)(pMVar1->t + 2);
  }
  (data->velocity).x = 0;
  (data->velocity).y = 0;
  (data->velocity).z = 0;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MON_LaunchMonster(struct _Instance *instance /*$s0*/, int zDirection /*$s1*/, int power /*$s2*/, int loft /*$s3*/)
// line 3645, offset 0x80084724
/* begin block 1 */
// Start line: 7822
/* end block 1 */
// End Line: 7823

void MON_LaunchMonster(_Instance *instance, int zDirection, int power, int loft)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;

  (instance->rotation).z = (short)zDirection + 0x800;
  (instance->rotation).x = 0;
  (instance->rotation).y = 0;
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = -8;
  iVar1 = MON_SetVelocityTowardsImpalingObject(instance, 1);
  if (iVar1 == 0)
  {
    PhysicsSetVelFromZRot(instance, (short)zDirection, power);
    instance->zVel = loft;
  }
  /* WARNING: Subroutine does not return */
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
}
