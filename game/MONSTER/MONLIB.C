#include "THISDUST.H"
#include "MONLIB.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MON_TurnOffWeaponSpheres(struct _Instance *instance /*$s1*/)
 // line 147, offset 0x8007e848
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x8007E848
		// Variables:
	// 		struct _MonsterVars *mv; // $s2

		/* begin block 1.1 */
			// Start line: 152
			// Start offset: 0x8007E870
			// Variables:
		// 		struct _Instance *weapon; // $s0
		/* end block 1.1 */
		// End offset: 0x8007E890
		// End Line: 156

		/* begin block 1.2 */
			// Start line: 159
			// Start offset: 0x8007E8A4
			// Variables:
		// 		int i; // $a1
		// 		struct _HPrim *hprim; // $v1
		// 		struct _HModel *hmodel; // $v1
		/* end block 1.2 */
		// End offset: 0x8007E928
		// End Line: 167
	/* end block 1 */
	// End offset: 0x8007E928
	// End Line: 168

	/* begin block 2 */
		// Start line: 294
	/* end block 2 */
	// End Line: 295

void MON_TurnOffWeaponSpheres(_Instance *instance)

{
  _HPrim *p_Var1;
  _Instance *instance_00;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  
  instance_00 = instance->LinkChild;
  puVar4 = (uint *)instance->extraData;
  while (instance_00 != (_Instance *)0x0) {
    TurnOffCollisionPhysOb(instance_00,3);
    instance_00 = instance_00->LinkSibling;
  }
  if ((*puVar4 & 0x4000) != 0) {
    iVar3 = instance->hModelList[instance->currentModel].numHPrims;
    p_Var1 = instance->hModelList[instance->currentModel].hPrimList;
    if (iVar3 != 0) {
      piVar2 = &p_Var1->data;
      do {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\t')) {
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
 // line 173, offset 0x8007e940
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x8007E940
		// Variables:
	// 		struct _MonsterVars *mv; // $a2

		/* begin block 1.1 */
			// Start line: 178
			// Start offset: 0x8007E96C
			// Variables:
		// 		int i; // $a1
		// 		struct _HPrim *hprim; // $a0
		// 		struct _HModel *hmodel; // $v0
		/* end block 1.1 */
		// End offset: 0x8007E9F0
		// End Line: 190
	/* end block 1 */
	// End offset: 0x8007E9F0
	// End Line: 191

	/* begin block 2 */
		// Start line: 350
	/* end block 2 */
	// End Line: 351

	/* begin block 3 */
		// Start line: 351
	/* end block 3 */
	// End Line: 352

void MON_TurnOnWeaponSpheres(_Instance *instance)

{
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = (uint *)instance->extraData;
  if (((*puVar5 & 0x4000) == 0) && (instance->hModelList != (_HModel *)0x0)) {
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0) {
      piVar2 = &p_Var3->data;
      do {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\t')) {
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
 // line 197, offset 0x8007e9f8
	/* begin block 1 */
		// Start line: 198
		// Start offset: 0x8007E9F8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 203
			// Start offset: 0x8007EA14
			// Variables:
		// 		struct _Instance *weapon; // $v0
		/* end block 1.1 */
		// End offset: 0x8007EA24
		// End Line: 207

		/* begin block 1.2 */
			// Start line: 213
			// Start offset: 0x8007EA5C
			// Variables:
		// 		int i; // $a2
		// 		struct _HPrim *hprim; // $a0
		// 		struct _HModel *hmodel; // $v0
		/* end block 1.2 */
		// End offset: 0x8007EAF0
		// End Line: 222
	/* end block 1 */
	// End offset: 0x8007EAF0
	// End Line: 223

	/* begin block 2 */
		// Start line: 402
	/* end block 2 */
	// End Line: 403

void MON_TurnOnWeaponSphere(_Instance *instance,int segment)

{
  _Instance *instance_00;
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = (uint *)instance->extraData;
  if (instance->LinkChild == (_Instance *)0x0) {
    if ((*puVar5 & 0x4000) != 0) {
      return;
    }
    if (instance->hModelList == (_HModel *)0x0) {
      return;
    }
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0) {
      piVar2 = &p_Var3->data;
      do {
        if ((((uint)*(byte *)((int)piVar2 + -1) == segment) &&
            (*(char *)((int)piVar2 + -2) == '\x01')) && (*(char *)(*piVar2 + 4) == '\t')) {
          p_Var3->hpFlags = p_Var3->hpFlags | 1;
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 2;
        p_Var3 = p_Var3 + 1;
      } while (iVar4 != 0);
    }
  }
  else {
    instance_00 = INSTANCE_GetChildLinkedToSegment(instance,segment);
    if (instance_00 == (_Instance *)0x0) {
      return;
    }
    TurnOnCollisionPhysOb(instance_00,3);
  }
  *puVar5 = *puVar5 | 0x4000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_TurnOffBodySpheres(struct _Instance *instance /*$a0*/)
 // line 228, offset 0x8007eb00
	/* begin block 1 */
		// Start line: 230
		// Start offset: 0x8007EB00
		// Variables:
	// 		struct _MonsterVars *mv; // $a2

		/* begin block 1.1 */
			// Start line: 233
			// Start offset: 0x8007EB1C
			// Variables:
		// 		int i; // $a1
		// 		struct _HPrim *hprim; // $v1
		// 		struct _HModel *hmodel; // $v1
		/* end block 1.1 */
		// End offset: 0x8007EBA0
		// End Line: 241
	/* end block 1 */
	// End offset: 0x8007EBA0
	// End Line: 242

	/* begin block 2 */
		// Start line: 468
	/* end block 2 */
	// End Line: 469

	/* begin block 3 */
		// Start line: 469
	/* end block 3 */
	// End Line: 470

void MON_TurnOffBodySpheres(_Instance *instance)

{
  _HPrim *p_Var1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  
  puVar4 = (uint *)instance->extraData;
  if ((*puVar4 & 0x8000) != 0) {
    iVar3 = instance->hModelList[instance->currentModel].numHPrims;
    p_Var1 = instance->hModelList[instance->currentModel].hPrimList;
    if (iVar3 != 0) {
      piVar2 = &p_Var1->data;
      do {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\b')) {
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
 // line 247, offset 0x8007eba8
	/* begin block 1 */
		// Start line: 249
		// Start offset: 0x8007EBA8
		// Variables:
	// 		struct _MonsterVars *mv; // $a2

		/* begin block 1.1 */
			// Start line: 252
			// Start offset: 0x8007EBD4
			// Variables:
		// 		int i; // $a1
		// 		struct _HPrim *hprim; // $a0
		// 		struct _HModel *hmodel; // $v0
		/* end block 1.1 */
		// End offset: 0x8007EC54
		// End Line: 260
	/* end block 1 */
	// End offset: 0x8007EC54
	// End Line: 261

	/* begin block 2 */
		// Start line: 508
	/* end block 2 */
	// End Line: 509

	/* begin block 3 */
		// Start line: 509
	/* end block 3 */
	// End Line: 510

void MON_TurnOnBodySpheres(_Instance *instance)

{
  _HModel *p_Var1;
  int *piVar2;
  _HPrim *p_Var3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = (uint *)instance->extraData;
  if (((*puVar5 & 0x8000) == 0) && (instance->hModelList != (_HModel *)0x0)) {
    p_Var1 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var1->numHPrims;
    p_Var3 = p_Var1->hPrimList;
    if (iVar4 != 0) {
      piVar2 = &p_Var3->data;
      do {
        if ((*(char *)((int)piVar2 + -2) == '\x01') && (*(char *)(*piVar2 + 4) == '\b')) {
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
 // line 266, offset 0x8007ec5c
	/* begin block 1 */
		// Start line: 548
	/* end block 1 */
	// End Line: 549

void MON_TurnOffAllSpheres(_Instance *instance)

{
  MON_TurnOffWeaponSpheres(instance);
  MON_TurnOffBodySpheres(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_TurnOnAllSpheres(struct _Instance *instance /*$s0*/)
 // line 275, offset 0x8007ec88
	/* begin block 1 */
		// Start line: 566
	/* end block 1 */
	// End Line: 567

void MON_TurnOnAllSpheres(_Instance *instance)

{
  MON_TurnOnWeaponSpheres(instance);
  MON_TurnOnBodySpheres(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SwitchState(struct _Instance *instance /*$s1*/, enum MonsterState state /*$s2*/)
 // line 317, offset 0x8007ecb4
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x8007ECB4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007ED60
	// End Line: 344

	/* begin block 2 */
		// Start line: 628
	/* end block 2 */
	// End Line: 629

void MON_SwitchState(_Instance *instance,MonsterState state)

{
  long in_a1;
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if ((*puVar1 & 0x4000) != 0) {
    MON_TurnOffWeaponSpheres(instance);
  }
  if ((*puVar1 & 1) == 0) {
    *(undefined *)((int)puVar1 + 0x155) = *(undefined *)&instance->currentMainState;
  }
  instance->currentMainState = in_a1;
  *puVar1 = *puVar1 & 0xbbfdefff | 1;
  if ((int)*(char *)((int)puVar1 + 0x162) != -1) {
    ENMYPLAN_ReleasePlanningWorkspace((int)*(char *)((int)puVar1 + 0x162));
    *(undefined *)((int)puVar1 + 0x162) = 0xff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SwitchStateDoEntry(struct _Instance *instance /*$s1*/, enum MonsterState state /*$a1*/)
 // line 347, offset 0x8007ed78
	/* begin block 1 */
		// Start line: 348
		// Start offset: 0x8007ED78
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007EDCC
	// End Line: 363

	/* begin block 2 */
		// Start line: 681
	/* end block 2 */
	// End Line: 682

void MON_SwitchStateDoEntry(_Instance *instance,MonsterState state)

{
  _MonsterState *p_Var1;
  undefined4 unaff_s0;
  uint *puVar2;
  undefined4 unaff_s1;
  
  puVar2 = (uint *)instance->extraData;
  MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  if (puVar2 != (uint *)0x0) {
    p_Var1 = MONTABLE_GetStateFuncs(instance,instance->currentMainState);
    (*p_Var1->entryFunction)(instance);
    *puVar2 = *puVar2 & 0xfffffffe;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_TransNodeAnimation(struct _Instance *instance /*$a0*/)
 // line 375, offset 0x8007ede0
	/* begin block 1 */
		// Start line: 737
	/* end block 1 */
	// End Line: 738

int MON_TransNodeAnimation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  
  _Var1 = G2Anim_SegmentHasActiveChannels(&instance->anim,0,0x700);
  return _Var1;
}



// decompiled code
// original method signature: 
// struct _MonsterAnim * /*$ra*/ MON_GetAnim(struct _Instance *instance /*$a0*/, char *animList /*$a1*/, int index /*$a2*/)
 // line 384, offset 0x8007ee08
	/* begin block 1 */
		// Start line: 386
		// Start offset: 0x8007EE08
		// Variables:
	// 		int whichAnim; // $a1
	/* end block 1 */
	// End offset: 0x8007EE34
	// End Line: 391

	/* begin block 2 */
		// Start line: 756
	/* end block 2 */
	// End Line: 757

	/* begin block 3 */
		// Start line: 757
	/* end block 3 */
	// End Line: 758

_MonsterAnim * MON_GetAnim(_Instance *instance,char *animList,int index)

{
  if ((int)animList[index] != -1) {
    return (_MonsterAnim *)(*(int *)((int)instance->data + 0x44) + (int)animList[index] * 0x10);
  }
  return (_MonsterAnim *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnimID(struct _Instance *instance /*$s3*/, int index /*$a1*/, int mode /*$s5*/)
 // line 396, offset 0x8007ee3c
	/* begin block 1 */
		// Start line: 397
		// Start offset: 0x8007EE3C
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterAnim *manim; // $s1
	// 		struct _MonsterAttributes *ma; // $v0
	// 		int anim; // $a2
	// 		int anim0; // $s4
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 432
			// Start offset: 0x8007EED0
			// Variables:
		// 		int interpFrames; // $v0
		// 		int alphaTable; // $v1
		/* end block 1.1 */
		// End offset: 0x8007EF1C
		// End Line: 447
	/* end block 1 */
	// End offset: 0x8007EF64
	// End Line: 452

	/* begin block 2 */
		// Start line: 782
	/* end block 2 */
	// End Line: 783

void MON_PlayAnimID(_Instance *instance,int index,int mode)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int NewAnim;
  int CurrentSection;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  uVar4 = *(int *)((int)instance->data + 0x44) + index * 0x10;
  iVar6 = (int)*(char *)(uVar4 + 0xc);
  puVar5 = (uint *)instance->extraData;
  if ((iVar6 < 0) || (instance->object->numAnims <= iVar6)) {
    iVar6 = 0;
  }
  G2Anim_SetCallback(&instance->anim,INSTANCE_DefaultAnimCallback,instance);
  CurrentSection = 0;
  uVar3 = uVar4;
  if (*(char *)(puVar5[0x59] + 0x2a) != '\0') {
    do {
      NewAnim = (int)*(char *)(uVar3 + 0xc);
      if ((int)*(char *)(uVar3 + 0xc) == -1) {
        NewAnim = iVar6;
      }
      uVar3 = puVar5[0x2f];
      if ((uVar3 == 0) || (bVar1 = *(byte *)(uVar3 + 8), bVar1 == 0)) {
        bVar1 = *(byte *)(uVar4 + 6);
        bVar2 = *(byte *)(uVar4 + 9);
      }
      else {
        bVar2 = *(byte *)(uVar3 + 10);
      }
      G2EmulationInstanceSwitchAnimationAlpha
                (instance,CurrentSection,NewAnim,(uint)*(byte *)(uVar4 + 7),(uint)bVar1,mode,
                 (uint)bVar2);
      G2EmulationInstanceSetAnimSpeed(instance,CurrentSection,(uint)*(ushort *)(uVar4 + 4));
      CurrentSection = CurrentSection + 1;
      uVar3 = uVar4 + CurrentSection;
    } while (CurrentSection < (int)(uint)*(byte *)(puVar5[0x59] + 0x2a));
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
 // line 456, offset 0x8007efdc
	/* begin block 1 */
		// Start line: 958
	/* end block 1 */
	// End Line: 959

void MON_PlayAnimFromList(_Instance *instance,char *animList,int animtype,int mode)

{
  MON_PlayAnimID(instance,(int)animList[animtype],mode);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_AnimIDPlaying(struct _Instance *instance /*$a0*/, int index /*$a1*/)
 // line 461, offset 0x8007f004
	/* begin block 1 */
		// Start line: 463
		// Start offset: 0x8007F004
		// Variables:
	// 		struct _MonsterAttributes *ma; // $v0
	/* end block 1 */
	// End offset: 0x8007F004
	// End Line: 465

	/* begin block 2 */
		// Start line: 969
	/* end block 2 */
	// End Line: 970

	/* begin block 3 */
		// Start line: 970
	/* end block 3 */
	// End Line: 971

	/* begin block 4 */
		// Start line: 972
	/* end block 4 */
	// End Line: 973

int MON_AnimIDPlaying(_Instance *instance,int index)

{
  return (uint)(*(int *)((int)instance->extraData + 0xbc) ==
               *(int *)((int)instance->data + 0x44) + index * 0x10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnimIDIfNotPlaying(struct _Instance *instance /*$s0*/, int index /*$s1*/, int mode /*$s2*/)
 // line 468, offset 0x8007f028
	/* begin block 1 */
		// Start line: 985
	/* end block 1 */
	// End Line: 986

void MON_PlayAnimIDIfNotPlaying(_Instance *instance,int index,int mode)

{
  int iVar1;
  
  iVar1 = MON_AnimIDPlaying(instance,index);
  if (iVar1 == 0) {
    MON_PlayAnimID(instance,index,mode);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_AnimPlayingFromList(struct _Instance *instance /*$a0*/, char *animList /*$a1*/, int animtype /*$a2*/)
 // line 477, offset 0x8007f078
	/* begin block 1 */
		// Start line: 1003
	/* end block 1 */
	// End Line: 1004

int MON_AnimPlayingFromList(_Instance *instance,char *animList,int animtype)

{
  int iVar1;
  
  iVar1 = MON_AnimIDPlaying(instance,(int)animList[animtype]);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnimFromListIfNotPlaying(struct _Instance *instance /*$s1*/, char *animList /*$a1*/, int animtype /*$a2*/, int mode /*$s2*/)
 // line 482, offset 0x8007f0a0
	/* begin block 1 */
		// Start line: 483
		// Start offset: 0x8007F0A0
		// Variables:
	// 		int index; // $s0
	/* end block 1 */
	// End offset: 0x8007F0E0
	// End Line: 488

	/* begin block 2 */
		// Start line: 1014
	/* end block 2 */
	// End Line: 1015

void MON_PlayAnimFromListIfNotPlaying(_Instance *instance,char *animList,int animtype,int mode)

{
  char cVar1;
  int iVar2;
  
  cVar1 = animList[animtype];
  iVar2 = MON_AnimIDPlaying(instance,(int)cVar1);
  if (iVar2 == 0) {
    MON_PlayAnimID(instance,(int)cVar1,mode);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnim(struct _Instance *instance /*$a0*/, enum MonsterAnim animtype /*$a1*/, int mode /*$a3*/)
 // line 494, offset 0x8007f0f8
	/* begin block 1 */
		// Start line: 1040
	/* end block 1 */
	// End Line: 1041

void MON_PlayAnim(_Instance *instance,MonsterAnim animtype,int mode)

{
  int in_a2;
  
  MON_PlayAnimFromList(instance,**(char ***)((int)instance->extraData + 0x164),mode,in_a2);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_AnimPlaying(struct _Instance *instance /*$a0*/, enum MonsterAnim animtype /*$a2*/)
 // line 502, offset 0x8007f12c
	/* begin block 1 */
		// Start line: 1057
	/* end block 1 */
	// End Line: 1058

int MON_AnimPlaying(_Instance *instance,MonsterAnim animtype)

{
  int iVar1;
  int in_a1;
  
  iVar1 = MON_AnimPlayingFromList(instance,**(char ***)((int)instance->extraData + 0x164),in_a1);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnimIfNotPlaying(struct _Instance *instance /*$a0*/, enum MonsterAnim animtype /*$a1*/, int mode /*$a3*/)
 // line 510, offset 0x8007f160
	/* begin block 1 */
		// Start line: 1074
	/* end block 1 */
	// End Line: 1075

void MON_PlayAnimIfNotPlaying(_Instance *instance,MonsterAnim animtype,int mode)

{
  int in_a2;
  
  MON_PlayAnimFromListIfNotPlaying
            (instance,**(char ***)((int)instance->extraData + 0x164),mode,in_a2);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MON_AnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s0*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
 // line 552, offset 0x8007f194
	/* begin block 1 */
		// Start line: 553
		// Start offset: 0x8007F194
		// Variables:
	// 		struct _Instance *instance; // $a3
	// 		struct _MonsterVars *mv; // $t0
	/* end block 1 */
	// End offset: 0x8007F230
	// End Line: 577

	/* begin block 2 */
		// Start line: 1084
	/* end block 2 */
	// End Line: 1085

long MON_AnimCallback(_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,
                     long messageDataA,long messageDataB,void *data)

{
  if (message == G2ANIM_MSG_LOOPPOINT) {
    *(uint *)((int)data + 0x18) = *(uint *)((int)data + 0x18) | 2;
  }
  else {
    if (message < G2ANIM_MSG_SECTION_INTERPDONE) {
      if (message == G2ANIM_MSG_DONE) {
        *(uint *)((int)data + 0x18) = *(uint *)((int)data + 0x18) | 0x10;
        **(uint **)((int)data + 0x168) = **(uint **)((int)data + 0x168) & 0xfbffffff;
        return messageDataA;
      }
    }
    else {
      if (message == G2ANIM_MSG_SEGCTRLR_INTERPDONE) {
        return messageDataA;
      }
    }
    INSTANCE_DefaultAnimCallback(anim,sectionID,message,messageDataA,messageDataB,(_Instance *)data)
    ;
  }
  return messageDataA;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_AnimInit(struct _Instance *instance /*$s1*/)
 // line 583, offset 0x8007f244
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x8007F244
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _G2AnimSection_Type *animSection; // $s3
	// 		int i; // $s0
	// 		int startSection; // $s6
	// 		int numSections; // $s7

		/* begin block 1.1 */
			// Start line: 597
			// Start offset: 0x8007F2A0
			// Variables:
		// 		int sectionEnd; // $a3
		/* end block 1.1 */
		// End offset: 0x8007F324
		// End Line: 607
	/* end block 1 */
	// End offset: 0x8007F36C
	// End Line: 612

	/* begin block 2 */
		// Start line: 1184
	/* end block 2 */
	// End Line: 1185

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
  bVar1 = *(byte *)(*(int *)((int)pvVar3 + 0x164) + 0x2a);
  CurrentSection = 0;
  *(undefined4 *)((int)pvVar3 + 0xbc) = 0;
  G2EmulationInstanceSetTotalSections(instance,(ushort)bVar1);
  iVar5 = 0x94;
  if (bVar1 != 0) {
    iVar4 = 0x1e8;
    do {
      bVar2 = *(byte *)(*(int *)((int)pvVar3 + 0x164) + CurrentSection + 0x2b);
      if (bVar2 == 0) {
        G2EmulationInstanceSetStartAndEndSegment
                  (instance,CurrentSection,(short)iVar6,
                   (short)(((uint)*(ushort *)
                                   &instance->object->modelList[instance->currentModel]->numSegments
                           - 1) * 0x10000 >> 0x10));
      }
      else {
        G2EmulationInstanceSetStartAndEndSegment(instance,CurrentSection,(short)iVar6,(ushort)bVar2)
        ;
        iVar6 = (uint)*(byte *)(*(int *)((int)pvVar3 + 0x164) + CurrentSection + 0x2b) + 1;
      }
      G2AnimSection_SetInterpInfo
                ((_G2AnimSection_Type *)((int)&(instance->node).prev + iVar4),
                 (_G2AnimInterpInfo_Type *)((int)pvVar3 + iVar5));
      G2EmulationInstanceSetAnimation(instance,CurrentSection,0,0,0);
      G2EmulationInstanceSetMode(instance,CurrentSection,2);
      iVar5 = iVar5 + 0xc;
      CurrentSection = CurrentSection + 1;
      iVar4 = iVar4 + 0x30;
    } while (CurrentSection < (int)(uint)bVar1);
  }
  G2EmulationInstanceInitSection(instance,0,MON_AnimCallback,instance);
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MON_FacingOffset(struct _Instance *instance /*$a0*/, struct _Instance *target /*$s0*/)
 // line 622, offset 0x8007f3b0
	/* begin block 1 */
		// Start line: 623
		// Start offset: 0x8007F3B0
	/* end block 1 */
	// End offset: 0x8007F3B0
	// End Line: 623

	/* begin block 2 */
		// Start line: 1286
	/* end block 2 */
	// End Line: 1287

short MON_FacingOffset(_Instance *instance,_Instance *target)

{
  ushort uVar1;
  
  uVar1 = MATH3D_AngleFromPosToPos(&target->position,&instance->position);
  return (short)(((uint)uVar1 - (uint)(ushort)(target->rotation).z) * 0x10000 >> 0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_CheckConditions(struct _Instance *instance /*$a0*/, struct _MonsterIR *mir /*$a1*/, char *probArray /*$a2*/)
 // line 635, offset 0x8007f3ec
	/* begin block 1 */
		// Start line: 637
		// Start offset: 0x8007F3EC
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		char *probability; // $a2
	// 		int chance; // $a1
	// 		int i; // $t1
	// 		int prob; // $a3
	// 		int nprob; // $t0

		/* begin block 1.1 */
			// Start line: 647
			// Start offset: 0x8007F41C
			// Variables:
		// 		int conditionProb; // $v0
		/* end block 1.1 */
		// End offset: 0x8007F480
		// End Line: 658
	/* end block 1 */
	// End offset: 0x8007F490
	// End Line: 661

	/* begin block 2 */
		// Start line: 1318
	/* end block 2 */
	// End Line: 1319

	/* begin block 3 */
		// Start line: 1319
	/* end block 3 */
	// End Line: 1320

	/* begin block 4 */
		// Start line: 1323
	/* end block 4 */
	// End Line: 1324

int MON_CheckConditions(_Instance *instance,_MonsterIR *mir,char *probArray)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = 100;
  iVar3 = 100;
  uVar4 = 1;
  do {
    if ((mir->mirConditions & uVar4) != 0) {
      iVar1 = (int)*probArray;
      if (iVar1 < 0) {
        iVar3 = (iVar3 * (iVar1 + 100)) / 100;
      }
      else {
        iVar2 = (iVar2 * (100 - iVar1)) / 100;
      }
    }
    uVar4 = uVar4 << 1;
    probArray = probArray + 1;
  } while ((int)uVar4 < 0x1000);
  return (uint)((int)*(char *)((int)instance->extraData + 0x161) < ((100 - iVar2) * iVar3) / 100);
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIAttack(struct _Instance *instance /*$s2*/, struct _MonsterIR *enemy /*$s1*/, struct _MonsterAttackAttributes *attack /*$s3*/)
 // line 682, offset 0x8007f4c4
	/* begin block 1 */
		// Start line: 683
		// Start offset: 0x8007F4C4
		// Variables:
	// 		struct _MonsterVars *mv; // $s4
	// 		int rv; // $a0

		/* begin block 1.1 */
			// Start line: 683
			// Start offset: 0x8007F4C4
			// Variables:
		// 		struct _Instance *enemyAttackee; // $s0
		// 		long mode; // $v1
		/* end block 1.1 */
		// End offset: 0x8007F528
		// End Line: 701

		/* begin block 1.2 */
			// Start line: 711
			// Start offset: 0x8007F55C
			// Variables:
		// 		long distance; // $v1
		/* end block 1.2 */
		// End offset: 0x8007F62C
		// End Line: 757
	/* end block 1 */
	// End offset: 0x8007F630
	// End Line: 763

	/* begin block 2 */
		// Start line: 1437
	/* end block 2 */
	// End Line: 1438

int MON_ShouldIAttack(_Instance *instance,_MonsterIR *enemy,_MonsterAttackAttributes *attack)

{
  _Instance *p_Var1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  
  pvVar5 = instance->extraData;
  p_Var1 = (_Instance *)INSTANCE_Query(enemy->instance,0x22);
  uVar2 = INSTANCE_Query(enemy->instance,10);
  if ((((p_Var1 == (_Instance *)0x0) || (p_Var1 == instance)) ||
      (iVar3 = 0, (uVar2 & 0x2000000) == 0)) &&
     (iVar3 = 0, attack != (_MonsterAttackAttributes *)0x0)) {
    uVar2 = INSTANCE_Query(enemy->instance,1);
    if (((uVar2 & 1) != 0) &&
       (iVar3 = MON_CheckConditions(instance,enemy,attack->attackProbability), iVar3 == 0)) {
      return 0;
    }
    iVar4 = (int)attack->attackRange - (int)enemy->distance;
    if ((enemy->mirFlags & 8) == 0) {
      if (iVar4 < -0x96) {
        iVar3 = 5;
      }
      else {
        if (iVar4 < 0x97) {
          iVar3 = (int)(enemy->relativePosition).y;
          if (iVar3 < 1) {
            iVar4 = (int)(enemy->relativePosition).x;
            if (iVar4 < 0) {
              iVar4 = -iVar4;
            }
            if (iVar4 <= -iVar3) {
              if ((enemy->mirFlags & 0x20) == 0) {
                return 3;
              }
              iVar3 = *(int *)((int)pvVar5 + 0xcc);
              if ((iVar3 != 0) &&
                 (uVar2 = INSTANCE_Query(*(_Instance **)(iVar3 + 4),10), (uVar2 & 0x200000) != 0)) {
                return 7;
              }
              enemy->mirConditions = 0;
              return 1;
            }
          }
          iVar3 = 6;
        }
        else {
          iVar3 = 4;
        }
      }
    }
    else {
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      iVar3 = 5;
      if (iVar4 < 1000) {
        iVar3 = 1;
      }
    }
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// struct _MonsterAttackAttributes * /*$ra*/ MON_ChooseAttack(struct _Instance *instance /*$a0*/, struct _MonsterIR *enemy /*$a1*/)
 // line 772, offset 0x8007f650
	/* begin block 1 */
		// Start line: 774
		// Start offset: 0x8007F650
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
			// Start line: 804
			// Start offset: 0x8007F6F4
			// Variables:
		// 		struct _MonsterAttackAttributes *attack; // $a2
		// 		long delta; // $a0
		/* end block 1.1 */
		// End offset: 0x8007F794
		// End Line: 818
	/* end block 1 */
	// End offset: 0x8007F7A0
	// End Line: 823

	/* begin block 2 */
		// Start line: 1628
	/* end block 2 */
	// End Line: 1629

	/* begin block 3 */
		// Start line: 1629
	/* end block 3 */
	// End Line: 1630

	/* begin block 4 */
		// Start line: 1630
	/* end block 4 */
	// End Line: 1631

_MonsterAttackAttributes * MON_ChooseAttack(_Instance *instance,_MonsterIR *enemy)

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
  if (((*puVar8 & 4) == 0) && ((enemy->mirFlags & 8) == 0)) {
    pMVar4 = enemy->instance->matrix;
    iVar10 = (int)enemy->distance;
    if (pMVar4 != (MATRIX *)0x0) {
      if (enemy->instance == gameTrackerX.playerInstance) {
        iVar9 = pMVar4[0xe].t[2] - (int)(instance->position).z;
      }
      else {
        iVar9 = pMVar4[1].t[2] - (int)(instance->position).z;
      }
    }
  }
  else {
    iVar10 = 0;
  }
  iVar6 = (int)*(char *)(*(int *)(puVar8[0x59] + 8) + 0x17);
  pcVar7 = (char *)(*(int *)(puVar8[0x59] + 8) + 0x26);
  if (iVar6 != 0) {
    do {
      p_Var5 = (_MonsterAttackAttributes *)
               (*(int *)((int)instance->data + 0x3c) + (int)*pcVar7 * 0x20);
      iVar2 = iVar9 - p_Var5->attackHeight;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if ((iVar2 < 100) || ((enemy->mirFlags & 8) != 0)) {
        iVar2 = (int)p_Var5->attackRange * (int)*(short *)(puVar8[0x59] + 0x14);
        if (iVar2 < 0) {
          iVar2 = iVar2 + 0xfff;
        }
        iVar3 = (iVar2 >> 0xc) - iVar10;
        iVar2 = iVar3;
        if (iVar3 < 0) {
          iVar2 = -iVar3;
        }
        iVar1 = iVar11;
        if (iVar11 < 0) {
          iVar1 = -iVar11;
        }
        if (iVar2 < iVar1) {
          iVar11 = iVar3;
          p_Var12 = p_Var5;
        }
      }
      iVar6 = iVar6 + -1;
      pcVar7 = pcVar7 + 1;
    } while (iVar6 != 0);
  }
  *(_MonsterAttackAttributes **)(puVar8 + 0x2e) = p_Var12;
  *(undefined *)((int)puVar8 + 0x15b) = 0;
  return p_Var12;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIEvade(struct _Instance *instance /*$s1*/)
 // line 832, offset 0x8007f7b0
	/* begin block 1 */
		// Start line: 833
		// Start offset: 0x8007F7B0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		int rv; // $s3

		/* begin block 1.1 */
			// Start line: 840
			// Start offset: 0x8007F7E8
			// Variables:
		// 		struct _MonsterIR *enemy; // $s2
		/* end block 1.1 */
		// End offset: 0x8007F83C
		// End Line: 853
	/* end block 1 */
	// End offset: 0x8007F83C
	// End Line: 857

	/* begin block 2 */
		// Start line: 1792
	/* end block 2 */
	// End Line: 1793

int MON_ShouldIEvade(_Instance *instance)

{
  short sVar1;
  int iVar2;
  uint *puVar3;
  _MonsterIR *mir;
  int iVar4;
  
  puVar3 = (uint *)instance->extraData;
  iVar4 = 0;
  if ((*puVar3 & 0x40000000) == 0) {
    mir = (_MonsterIR *)puVar3[0x31];
    sVar1 = MON_FacingOffset(instance,mir->instance);
    if ((ushort)(sVar1 + 0x2a9U) < 0x553) {
      iVar2 = MON_CheckConditions(instance,mir,(char *)(*(int *)(puVar3[0x59] + 8) + 0x1a));
      iVar4 = 0;
      if (iVar2 != 0) {
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
 // line 867, offset 0x8007f85c
	/* begin block 1 */
		// Start line: 868
		// Start offset: 0x8007F85C

		/* begin block 1.1 */
			// Start line: 877
			// Start offset: 0x8007F89C
			// Variables:
		// 		int leftDist; // $s0
		// 		int rightDist; // $v1
		/* end block 1.1 */
		// End offset: 0x8007F8F0
		// End Line: 886
	/* end block 1 */
	// End offset: 0x8007F8F0
	// End Line: 887

	/* begin block 2 */
		// Start line: 1863
	/* end block 2 */
	// End Line: 1864

int MON_ChooseLeftOrRight(_Instance *instance,_MonsterIR *enemy)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  sVar1 = MON_FacingOffset(instance,enemy->instance);
  iVar2 = -1;
  if (-0x41 < sVar1) {
    if (sVar1 < 0x41) {
      iVar3 = MONSENSE_GetDistanceInDirection
                        (instance,(short)(((uint)(ushort)(instance->rotation).z + 0x400) * 0x10000
                                         >> 0x10));
      iVar4 = MONSENSE_GetDistanceInDirection
                        (instance,(short)(((uint)(ushort)(instance->rotation).z - 0x400) * 0x10000
                                         >> 0x10));
      if (iVar3 == iVar4) {
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
        if (iVar4 <= iVar3) {
          iVar2 = -1;
        }
      }
    }
    else {
      iVar2 = 1;
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ChooseEvadeMove(struct _Instance *instance /*$s1*/)
 // line 889, offset 0x8007f900
	/* begin block 1 */
		// Start line: 890
		// Start offset: 0x8007F900
		// Variables:
	// 		int anim; // $s2
	// 		struct _MonsterVars *mv; // $s0
	// 		int leftOrRight; // $v1
	/* end block 1 */
	// End offset: 0x8007FA74
	// End Line: 929

	/* begin block 2 */
		// Start line: 1912
	/* end block 2 */
	// End Line: 1913

int MON_ChooseEvadeMove(_Instance *instance)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  
  pvVar4 = instance->extraData;
  iVar5 = 0;
  iVar2 = MON_ChooseLeftOrRight(instance,*(_MonsterIR **)((int)pvVar4 + 0xc4));
  if (iVar2 == 0) {
    uVar3 = rand();
    iVar2 = -1;
    if ((uVar3 & 1) != 0) {
      iVar2 = 1;
    }
  }
  if (iVar2 < 0) {
    if (*(char *)(**(int **)((int)pvVar4 + 0x164) + 0x28) == -1) {
      iVar2 = rcos((int)(instance->rotation).z);
      iVar2 = iVar2 * 0x140;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0xfff;
      }
      sVar1 = (instance->rotation).z;
      (instance->position).x = (instance->position).x + (short)(iVar2 >> 0xc);
      iVar2 = rsin((int)sVar1);
      iVar2 = iVar2 * 0x140;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0xfff;
      }
      (instance->position).y = (instance->position).y + (short)(iVar2 >> 0xc);
    }
    else {
      iVar5 = 0x28;
    }
  }
  else {
    if (*(char *)(**(int **)((int)pvVar4 + 0x164) + 0x29) == -1) {
      iVar2 = rcos((int)(instance->rotation).z);
      iVar2 = iVar2 * 0x140;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0xfff;
      }
      sVar1 = (instance->rotation).z;
      (instance->position).x = (instance->position).x - (short)(iVar2 >> 0xc);
      iVar2 = rsin((int)sVar1);
      iVar2 = iVar2 * 0x140;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 0xfff;
      }
      (instance->position).y = (instance->position).y - (short)(iVar2 >> 0xc);
    }
    else {
      iVar5 = 0x29;
    }
  }
  return iVar5;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ChooseCombatMove(struct _Instance *instance /*$s1*/, int reason /*$a1*/)
 // line 935, offset 0x8007fa90
	/* begin block 1 */
		// Start line: 936
		// Start offset: 0x8007FA90
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _MonsterSubAttributes *subAttr; // $s3
	// 		int anim; // $s0
	// 		int data; // $v0
	// 		struct _MonsterIR *enemy; // $s0
	// 		int infront; // $a0
	// 		struct _MonsterAnim *manim; // $v1

		/* begin block 1.1 */
			// Start line: 998
			// Start offset: 0x8007FB48

			/* begin block 1.1.1 */
				// Start line: 1002
				// Start offset: 0x8007FB68
				// Variables:
			// 		int dir; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8007FBB0
			// End Line: 1011
		/* end block 1.1 */
		// End offset: 0x8007FBC8
		// End Line: 1034

		/* begin block 1.2 */
			// Start line: 1038
			// Start offset: 0x8007FBD0
			// Variables:
		// 		short zrot; // $a1
		/* end block 1.2 */
		// End offset: 0x8007FD40
		// End Line: 1097
	/* end block 1 */
	// End offset: 0x8007FD40
	// End Line: 1099

	/* begin block 2 */
		// Start line: 2007
	/* end block 2 */
	// End Line: 2008

int MON_ChooseCombatMove(_Instance *instance,int reason)

{
  short angle;
  ushort uVar1;
  int Data;
  uint xOffset;
  uint yOffset;
  char cVar2;
  _MonsterIR *enemy;
  uint uVar3;
  void *pvVar4;
  int *piVar5;
  
  pvVar4 = instance->extraData;
  enemy = *(_MonsterIR **)((int)pvVar4 + 0xc4);
  Data = *(int *)((int)pvVar4 + 0xcc);
  piVar5 = *(int **)((int)pvVar4 + 0x164);
  if ((Data == 0) || (699 < *(short *)(Data + 0x14))) {
    if (reason == 4) {
LAB_8007fb40:
      cVar2 = '\a';
    }
    else {
      if (reason == 5) {
        cVar2 = '\x06';
      }
      else {
        Data = (int)(enemy->relativePosition).y;
        if (Data < 0) {
          Data = -Data;
        }
        if (Data < *(short *)(piVar5[2] + 0x10)) {
          cVar2 = '\x06';
          if ((enemy->relativePosition).y < 0) goto LAB_8007fb40;
        }
        else {
          angle = MON_FacingOffset(instance,enemy->instance);
          if ((ushort)(angle + 0x2a9U) < 0x553) {
            Data = MON_ChooseLeftOrRight(instance,enemy);
            cVar2 = '\b';
            if ((-1 < Data) && (cVar2 = '\t', Data < 1)) {
              uVar3 = rand();
              if ((uVar3 & 3) == 0) {
                cVar2 = '\b';
                uVar3 = rand();
                if ((uVar3 & 1) != 0) {
                  cVar2 = '\t';
                }
              }
              else {
                cVar2 = *(char *)((int)pvVar4 + 0x160);
              }
            }
          }
          else {
            cVar2 = '\0';
          }
          if (cVar2 == '\0') {
            return 0;
          }
        }
      }
    }
  }
  else {
    cVar2 = '\b';
    if (0 < *(short *)(Data + 0xc)) {
      cVar2 = '\t';
    }
  }
  if (cVar2 == '\0') {
    return 0;
  }
  angle = (instance->rotation).z;
  if (cVar2 == '\b') {
    angle = angle + 0x400;
  }
  else {
    if (cVar2 < '\t') {
      if (cVar2 == '\a') {
        angle = angle + 0x800;
      }
    }
    else {
      if (cVar2 == '\t') {
        angle = angle + -0x400;
      }
    }
  }
  angle = MONSENSE_GetClosestFreeDirection(instance,angle,500);
  uVar1 = (angle - (instance->rotation).z) + 0x200U & 0xfff;
  uVar3 = 6;
  if (((0x3ff < uVar1) && (uVar3 = 8, 0x7ff < uVar1)) && (uVar3 = 9, uVar1 < 0xc00)) {
    uVar3 = 7;
  }
  Data = *(int *)((int)instance->data + 0x44) + (int)*(char *)(*piVar5 + uVar3) * 0x10;
  if (uVar3 == 8) {
    xOffset = (uint)*(ushort *)(Data + 2);
    yOffset = 0;
  }
  else {
    if (uVar3 < 9) {
      xOffset = 0;
      if (uVar3 == 7) {
        yOffset = (uint)*(ushort *)(Data + 2);
        goto LAB_8007fd08;
      }
    }
    else {
      yOffset = 0;
      if (uVar3 == 9) {
        xOffset = -(uint)*(ushort *)(Data + 2);
        goto LAB_8007fd08;
      }
    }
    xOffset = 0;
    yOffset = -(uint)*(ushort *)(Data + 2);
  }
LAB_8007fd08:
  Data = SetPhysicsDropOffData(xOffset,yOffset,200,0x800);
  Data = PhysicsCheckDropOff(instance,Data,4);
  if (Data == 0) {
    if (uVar3 - 8 < 2) {
      *(undefined *)((int)pvVar4 + 0x160) = (char)uVar3;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayRandomIdle(struct _Instance *instance /*$s4*/, int mode /*$s5*/)
 // line 1107, offset 0x8007fd60
	/* begin block 1 */
		// Start line: 1108
		// Start offset: 0x8007FD60
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct _MonsterAttributes *ma; // $s2
	// 		struct _MonsterBehavior *behavior; // $s0
	// 		struct _MonsterIdle *idle; // $s1
	// 		int chance; // $a2
	// 		int i; // $a0
	// 		char *idleIndex; // $a1
	/* end block 1 */
	// End offset: 0x8007FED8
	// End Line: 1163

	/* begin block 2 */
		// Start line: 2382
	/* end block 2 */
	// End Line: 2383

void MON_PlayRandomIdle(_Instance *instance,int mode)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined *puVar5;
  char *pcVar6;
  void *pvVar7;
  uint *puVar8;
  
  puVar8 = (uint *)instance->extraData;
  pvVar7 = instance->data;
  iVar2 = rand();
  pcVar6 = (char *)0x0;
  iVar2 = iVar2 % 100;
  if ((*puVar8 & 4) == 0) {
    iVar3 = -1;
    if (*(int *)(puVar8[0x59] + 0x10) != 0) {
      iVar3 = (int)*(char *)(*(int *)(puVar8[0x59] + 0x10) + (uint)*(byte *)((int)puVar8 + 0x156));
    }
    if (iVar3 == -1) {
      puVar5 = *(undefined **)((int)pvVar7 + 0x4c);
    }
    else {
      puVar5 = (undefined *)(*(int *)((int)pvVar7 + 0x4c) + iVar3 * 8);
    }
    if (*(char *)((int)puVar8 + 0x156) != '\0') {
      iVar3 = (int)(char)puVar5[2];
      pcVar4 = puVar5 + 3;
      if (iVar3 != 0) {
        do {
          pcVar6 = (char *)(*(int *)((int)pvVar7 + 0x48) + (int)*pcVar4 * 4);
          iVar3 = iVar3 + -1;
          if (iVar2 < pcVar6[2]) break;
          iVar2 = iVar2 - pcVar6[2];
          pcVar4 = pcVar4 + 1;
        } while (iVar3 != 0);
      }
      goto LAB_8007feb8;
    }
    cVar1 = puVar5[(uint)*(byte *)(puVar8 + 0x57) + 3];
  }
  else {
    puVar5 = *(undefined **)((int)pvVar7 + 0x4c);
    cVar1 = puVar5[3];
  }
  pcVar6 = (char *)(*(int *)((int)pvVar7 + 0x48) + (int)cVar1 * 4);
LAB_8007feb8:
  if (pcVar6 != (char *)0x0) {
    MON_PlayAnimIDIfNotPlaying(instance,(int)*pcVar6,mode);
    *(undefined *)((int)puVar8 + 0x15d) = *puVar5;
  }
  return;
}



// autogenerated function stub: 
// void /*$ra*/ MON_PlayCombatIdle(struct _Instance *instance /*$a0*/, int mode /*$a2*/)
void MON_PlayCombatIdle(struct _Instance *instance, int mode)
{ // line 1168, offset 0x8007fefc
	/* begin block 1 */
		// Start line: 1169
		// Start offset: 0x8007FEFC
		// Variables:
			int anim; // $a1
	/* end block 1 */
	// End offset: 0x8007FF24
	// End Line: 1177

	/* begin block 2 */
		// Start line: 2510
	/* end block 2 */
	// End Line: 2511

}


// decompiled code
// original method signature: 
// void /*$ra*/ MON_GetRandomPoint(struct _Position *out /*$s2*/, struct _Position *in /*$s1*/, short r /*$a2*/)
 // line 1209, offset 0x8007ff3c
	/* begin block 1 */
		// Start line: 1210
		// Start offset: 0x8007FF3C
		// Variables:
	// 		int ang; // $s0
	/* end block 1 */
	// End offset: 0x8007FF3C
	// End Line: 1210

	/* begin block 2 */
		// Start line: 2412
	/* end block 2 */
	// End Line: 2413

void MON_GetRandomPoint(_Position *out,_Position *in,short r)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = rand();
  uVar2 = rand();
  iVar3 = rcos(uVar2);
  out->x = in->x + (short)((iVar1 % (int)r) * iVar3 >> 0xc);
  iVar3 = rsin(uVar2);
  out->y = in->y + (short)((iVar1 % (int)r) * iVar3 >> 0xc);
  out->z = in->z;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_GetRandomGroundPoint(struct _Instance *instance /*$s2*/, struct _Position *out /*stack 4*/, struct _Position *in /*$s6*/, short r0 /*$a3*/, int r1 /*stack 16*/, int theta0 /*stack 20*/, int theta1 /*stack 24*/, int h /*stack 28*/)
 // line 1229, offset 0x8007ffe8
	/* begin block 1 */
		// Start line: 1230
		// Start offset: 0x8007FFE8
		// Variables:
	// 		int rad; // $s1
	// 		int ang; // $s0
	// 		int rv; // $s7
	// 		struct SVECTOR top; // stack offset -104
	// 		struct SVECTOR bot; // stack offset -96
	// 		struct _PCollideInfo pcollideInfo; // stack offset -88
	// 		struct Level *level; // $s3

		/* begin block 1.1 */
			// Start line: 1252
			// Start offset: 0x80080174
			// Variables:
		// 		struct Level *newlevel; // $v0
		/* end block 1.1 */
		// End offset: 0x800801D8
		// End Line: 1267
	/* end block 1 */
	// End offset: 0x800801D8
	// End Line: 1269

	/* begin block 2 */
		// Start line: 2604
	/* end block 2 */
	// End Line: 2605

int MON_GetRandomGroundPoint
              (_Instance *instance,_Position *out,_Position *in,short r0,int r1,int theta0,
              int theta1,int h)

{
  _Instance *level;
  int iVar1;
  uint uVar2;
  int iVar3;
  SVECTOR local_68;
  SVECTOR local_60;
  _PCollideInfo _Stack88;
  
  level = (_Instance *)STREAM_GetLevelWithID(instance->currentStreamUnitID);
  iVar1 = rand();
  iVar1 = iVar1 * ((int)(short)r1 - (int)r0);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x7fff;
  }
  iVar3 = (int)r0 + (iVar1 >> 0xf);
  iVar1 = rand();
  iVar1 = iVar1 * ((int)(short)theta1 - (int)(short)theta0);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x7fff;
  }
  uVar2 = (int)(short)theta0 + (iVar1 >> 0xf);
  iVar1 = rcos(uVar2);
  local_68.vx = in->x + (short)(iVar3 * iVar1 >> 0xc);
  local_60.vx = local_68.vx;
  iVar1 = rsin(uVar2);
  local_68.vy = in->y + (short)(iVar3 * iVar1 >> 0xc);
  local_60.vz = (short)(((h << 0x10) >> 0x10) - ((h << 0x10) >> 0x1f) >> 1);
  local_68.vz = in->z + local_60.vz;
  _Stack88.collideType = 1;
  _Stack88.oldPoint = &local_68;
  _Stack88.newPoint = &local_60;
  _Stack88.instance = (_Instance *)0x0;
  _Stack88.inst = (_Instance *)0x0;
  local_60.vz = in->z - local_60.vz;
  local_60.vy = local_68.vy;
  COLLIDE_PointAndWorld(&_Stack88,&gameTrackerX,(Level *)level);
  iVar1 = 0;
  if ((((_Stack88.collideType & 1) != 0) && (iVar1 = 0, _Stack88.prim != (_TFace *)0x0)) &&
     (iVar1 = 0, level == _Stack88.inst)) {
    if (instance != (_Instance *)0x0) {
      instance->oldTFace = instance->tface;
      *(_Instance **)&instance->tfaceLevel = level;
      instance->tface = _Stack88.prim;
      instance->bspTree = (int)_Stack88.segment;
    }
    out->x = local_60.vx;
    out->y = local_60.vy;
    out->z = local_60.vz;
    iVar1 = 1;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_GetRandomDestinationInWorld(struct _Instance *instance /*$s2*/, struct _Position *in /*$s0*/, short r /*$s4*/)
 // line 1275, offset 0x8008020c
	/* begin block 1 */
		// Start line: 1276
		// Start offset: 0x8008020C

		/* begin block 1.1 */
			// Start line: 1279
			// Start offset: 0x80080240
			// Variables:
		// 		struct _MonsterVars *mv; // $s1
		// 		struct evPhysicsLOSData data; // stack offset -48
		// 		int result; // $s0
		// 		int avoidEnemy; // $s3

			/* begin block 1.1.1 */
				// Start line: 1290
				// Start offset: 0x8008027C
			/* end block 1.1.1 */
			// End offset: 0x800802CC
			// End Line: 1296

			/* begin block 1.1.2 */
				// Start line: 1310
				// Start offset: 0x80080348
			/* end block 1.1.2 */
			// End offset: 0x80080398
			// End Line: 1316
		/* end block 1.1 */
		// End offset: 0x800803D0
		// End Line: 1325
	/* end block 1 */
	// End offset: 0x800803D4
	// End Line: 1328

	/* begin block 2 */
		// Start line: 2724
	/* end block 2 */
	// End Line: 2725

/* WARNING: Could not reconcile some variable overlaps */

int MON_GetRandomDestinationInWorld(_Instance *instance,_Position *in,short r)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  uint *puVar5;
  undefined4 local_30;
  short local_2c;
  _Position local_28 [2];
  
  if (instance->matrix == (MATRIX *)0x0) {
    return 0;
  }
  puVar5 = (uint *)instance->extraData;
  bVar1 = false;
  if ((uint)*(byte *)((int)puVar5 + 0x156) - 9 < 2) {
    bVar1 = puVar5[0x31] != 0;
  }
  if (in != (_Position *)0x0) {
    if (!bVar1) goto LAB_800802cc;
    iVar2 = *(int *)(puVar5[0x31] + 4);
    lVar3 = MATH3D_LengthXYZ((int)in->x - (int)*(short *)(iVar2 + 0x5c),
                             (int)in->y - (int)*(short *)(iVar2 + 0x5e),
                             (int)in->z - (int)*(short *)(iVar2 + 0x60));
    if (*(short *)(puVar5[0x59] + 0x1a) <= lVar3) goto LAB_800802cc;
  }
  in = &instance->position;
LAB_800802cc:
  local_28[0].x = *(short *)instance->matrix[1].t;
  local_28[0].y = *(short *)(instance->matrix[1].t + 1);
  local_28[0].z = *(short *)(instance->matrix[1].t + 2);
  MON_GetRandomPoint((_Position *)&local_30,in,r);
  local_2c = local_2c + (local_28[0].z - (instance->position).z);
  iVar2 = MON_CheckPointSuitability(instance,local_28,(_Position *)&local_30);
  if (iVar2 != 0) {
    if (bVar1) {
      iVar4 = *(int *)(puVar5[0x31] + 4);
      lVar3 = MATH3D_LengthXYZ((int)(short)local_30 - (int)*(short *)(iVar4 + 0x5c),
                               (int)local_30._2_2_ - (int)*(short *)(iVar4 + 0x5e),
                               (int)local_2c - (int)*(short *)(iVar4 + 0x60));
      if (lVar3 < *(short *)(puVar5[0x59] + 0x1a)) {
        iVar2 = 0;
      }
    }
    if (iVar2 != 0) {
      *puVar5 = *puVar5 | 0x40000;
      puVar5[0x48] = local_30;
      *(short *)(puVar5 + 0x49) = local_2c;
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MoveForward(struct _Instance *instance /*$s0*/)
 // line 1421, offset 0x800803f4
	/* begin block 1 */
		// Start line: 1422
		// Start offset: 0x800803F4
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x800803F4
	// End Line: 1422

	/* begin block 2 */
		// Start line: 2836
	/* end block 2 */
	// End Line: 2837

void MON_MoveForward(_Instance *instance)

{
  PhysicsSetVelFromRot
            (instance,&instance->rotation,(int)*(short *)((int)instance->extraData + 0x126));
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  PhysicsMove(instance,&instance->position,gameTrackerX.idleTime);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_TurnToPosition(struct _Instance *instance /*$s1*/, struct _Position *position /*$a1*/, short turnspeed /*$a2*/)
 // line 1436, offset 0x80080444
	/* begin block 1 */
		// Start line: 1437
		// Start offset: 0x80080444
	/* end block 1 */
	// End offset: 0x80080444
	// End Line: 1437

	/* begin block 2 */
		// Start line: 2961
	/* end block 2 */
	// End Line: 2962

int MON_TurnToPosition(_Instance *instance,_Position *position,short turnspeed)

{
  short destination;
  
  destination = MATH3D_AngleFromPosToPos(&instance->position,position);
  AngleMoveToward(&(instance->rotation).z,destination,
                  (short)((int)turnspeed * gameTrackerX.idleTime * 0x10 >> 0x10));
  return (uint)((instance->rotation).z == destination);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MoveToPosition(struct _Instance *instance /*$s0*/, struct _Position *position /*$a1*/, short turnSpeed /*$a2*/)
 // line 1453, offset 0x800804b4
	/* begin block 1 */
		// Start line: 3001
	/* end block 1 */
	// End Line: 3002

void MON_MoveToPosition(_Instance *instance,_Position *position,short turnSpeed)

{
  int iVar1;
  
  MON_TurnToPosition(instance,position,turnSpeed);
  iVar1 = MON_TransNodeAnimation(instance);
  if (iVar1 == 0) {
    MON_MoveForward(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_OnGround(struct _Instance *instance /*$s0*/)
 // line 1472, offset 0x800804f8
	/* begin block 1 */
		// Start line: 1473
		// Start offset: 0x800804F8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct evPhysicsGravityData data; // stack offset -32
	// 		int minUpper; // $v1
	// 		long xyDist; // $a1
	/* end block 1 */
	// End offset: 0x800805A4
	// End Line: 1498

	/* begin block 2 */
		// Start line: 3041
	/* end block 2 */
	// End Line: 3042

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
  if ((*puVar4 & 2) != 0) {
    iVar2 = 100;
  }
  if (iVar3 * 0x10000 >> 0x10 < iVar2) {
    local_20 = (short)iVar2;
  }
  iVar2 = (int)local_20;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 3;
  }
  if ((int)local_1e < iVar2 >> 2) {
    local_1e = (short)(iVar2 >> 2);
  }
  local_20 = local_20 + *(short *)(puVar4[0x59] + 0x4c);
  local_16 = 0xc80;
  local_1e = local_1e + *(short *)(puVar4[0x59] + 0x4e);
  iVar2 = PhysicsCheckGravity(instance,(int)&local_20,(ushort)((*puVar4 & 0x800) == 0) << 2);
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ApplyPhysics(struct _Instance *instance /*$a0*/)
 // line 1515, offset 0x80080604
	/* begin block 1 */
		// Start line: 3156
	/* end block 1 */
	// End Line: 3157

void MON_ApplyPhysics(_Instance *instance)

{
  PhysicsMove(instance,&instance->position,gameTrackerX.idleTime);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ChangeBehavior(struct _Instance *instance /*$a0*/, int behavior /*$s0*/)
 // line 1525, offset 0x80080628
	/* begin block 1 */
		// Start line: 1526
		// Start offset: 0x80080628

		/* begin block 1.1 */
			// Start line: 1529
			// Start offset: 0x80080644
			// Variables:
		// 		struct _MonsterVars *mv; // $s1
		// 		enum MonsterState state; // $a1
		/* end block 1.1 */
		// End offset: 0x8008069C
		// End Line: 1556
	/* end block 1 */
	// End offset: 0x8008069C
	// End Line: 1557

	/* begin block 2 */
		// Start line: 3177
	/* end block 2 */
	// End Line: 3178

void MON_ChangeBehavior(_Instance *instance,int behavior)

{
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  void *pvVar1;
  
  if (behavior != -1) {
    pvVar1 = instance->extraData;
    switch(behavior) {
    case 2:
      break;
    case 4:
    case 8:
      break;
    case 9:
    }
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
    *(undefined *)((int)pvVar1 + 0x156) = (char)behavior;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CheckEnvironment(struct _Instance *instance /*$s1*/)
 // line 1562, offset 0x800806b0
	/* begin block 1 */
		// Start line: 1563
		// Start offset: 0x800806B0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _SVector Hack; // stack offset -40

		/* begin block 1.1 */
			// Start line: 1592
			// Start offset: 0x80080798
			// Variables:
		// 		int moveback; // $s2
		// 		int onground; // $s3

			/* begin block 1.1.1 */
				// Start line: 1619
				// Start offset: 0x80080844
				// Variables:
			// 		int offset; // $a1
			// 		int result; // $v0
			// 		struct _Position pos; // stack offset -32
			/* end block 1.1.1 */
			// End offset: 0x800808EC
			// End Line: 1639

			/* begin block 1.1.2 */
				// Start line: 1651
				// Start offset: 0x80080928
				// Variables:
			// 		int result; // $v0
			// 		int offset; // $a1
			/* end block 1.1.2 */
			// End offset: 0x80080988
			// End Line: 1667

			/* begin block 1.1.3 */
				// Start line: 1674
				// Start offset: 0x80080990
				// Variables:
			// 		int result; // $v1
			/* end block 1.1.3 */
			// End offset: 0x800809F4
			// End Line: 1703
		/* end block 1.1 */
		// End offset: 0x80080A5C
		// End Line: 1716
	/* end block 1 */
	// End offset: 0x80080A5C
	// End Line: 1717

	/* begin block 2 */
		// Start line: 3252
	/* end block 2 */
	// End Line: 3253

void MON_CheckEnvironment(_Instance *instance)

{
  short sVar1;
  bool bVar2;
  int Data;
  uint uVar3;
  uint dropOffset;
  uint *puVar4;
  _SVector local_28;
  _Position local_20;
  
  puVar4 = (uint *)instance->extraData;
  local_28.z = 0;
  local_28.y = 0;
  local_28.x = 0;
  Data = SetPhysicsSwimData(0,&local_28,0x100,0xa0,0x40);
  uVar3 = PhysicsCheckSwim(instance,Data,1);
  if ((uVar3 & 0x20) == 0) {
    if ((*puVar4 & 0x400) == 0) {
      *puVar4 = *puVar4 & 0xffbfffff | 0x400;
      instance->maxXVel = 0x14;
      instance->maxYVel = 0x14;
      instance->maxZVel = 0x14;
      instance->xVel = 0;
      instance->yVel = 0;
      SOUND_Play3dSound(&instance->position,1,0,0x78,10000);
      instance->flags2 = instance->flags2 & 0xffffffbf;
      INSTANCE_Post(instance,0x100000c,0x10);
    }
  }
  else {
    bVar2 = false;
    if ((*puVar4 & 0x400) != 0) {
      *puVar4 = *puVar4 & 0xfffffbff;
      instance->maxXVel = 400;
      instance->maxYVel = 400;
      instance->maxZVel = 400;
      if ((instance->object->oflags & 0x200U) != 0) {
        instance->flags2 = instance->flags2 | 0x40;
      }
    }
    if (instance->LinkParent == (_Instance *)0x0) {
      uVar3 = MON_OnGround(instance);
      if (uVar3 == 0) {
        uVar3 = *puVar4;
        if (((uVar3 & 2) != 0) && (*puVar4 = uVar3 & 0xfffffffd, (uVar3 & 0x800) == 0)) {
          Data = 0x140;
          if ((uVar3 & 0x10000) == 0) {
            Data = (int)*(short *)(puVar4[0x59] + 0x16);
          }
          Data = SetPhysicsDropHeightData(&instance->position,Data,0x40);
          uVar3 = PhysicsCheckDropHeight(instance,Data,1);
          if (((uVar3 & *(ushort *)((int)puVar4 + 0x14e)) != 0) || (uVar3 == 0)) {
            bVar2 = true;
          }
        }
      }
      else {
        if ((*puVar4 & 2) == 0) {
          *puVar4 = *puVar4 | 2;
        }
        if ((*puVar4 & 0x1000) != 0) {
          dropOffset = (uint)*(ushort *)puVar4[0x2f] * 8;
          local_20.y = *(ushort *)puVar4[0x2f] * -8;
          if (dropOffset < 100) {
            dropOffset = 100;
            local_20.y = -100;
          }
          local_20.x = 0;
          local_20.z = (short)((int)dropOffset / 2);
          if ((*puVar4 & 0x10000) == 0) {
            dropOffset = SEXT24(*(short *)(puVar4[0x59] + 0x16));
          }
          Data = SetPhysicsDropHeightData(&local_20,dropOffset,0x60);
          dropOffset = PhysicsCheckDropHeight(instance,Data,1);
          if (((dropOffset & *(ushort *)((int)puVar4 + 0x14e)) != 0) || (dropOffset == 0)) {
            INSTANCE_Post(instance,0x4010080,0);
          }
        }
        if ((uVar3 & 0x100000) != 0) {
          bVar2 = true;
        }
      }
      if (bVar2) {
        Data = SetPhysicsDropHeightData(&instance->oldPos,100,0x40);
        uVar3 = PhysicsCheckDropHeight(instance,Data,1);
        if ((uVar3 != 0) && ((uVar3 & *(ushort *)((int)puVar4 + 0x14e)) == 0)) {
          sVar1 = (instance->oldPos).z;
          *(undefined4 *)&instance->position = *(undefined4 *)&instance->oldPos;
          (instance->position).z = sVar1;
          *puVar4 = *puVar4 | 2;
        }
      }
      if (((*puVar4 & 0x802) == 0) && (puVar4[0x42] != 0x100000)) {
        INSTANCE_Post(instance,0x100000b,0);
      }
    }
    if ((int *)instance->tfaceLevel != (int *)0x0) {
      MON_CheckTerrainAndRespond
                (instance,(BSPTree *)
                          (*(int *)(*(int *)instance->tfaceLevel + 0x50) + instance->bspTree * 0x24)
                 ,instance->tface);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CheckTerrainAndRespond(struct _Instance *instance /*$s1*/, struct BSPTree *bsp /*$a1*/, struct _TFace *tface /*$a2*/)
 // line 1719, offset 0x80080a78
	/* begin block 1 */
		// Start line: 1720
		// Start offset: 0x80080A78
		// Variables:
	// 		unsigned long results; // $s0
	/* end block 1 */
	// End offset: 0x80080AE8
	// End Line: 1731

	/* begin block 2 */
		// Start line: 3580
	/* end block 2 */
	// End Line: 3581

void MON_CheckTerrainAndRespond(_Instance *instance,BSPTree *bsp,_TFace *tface)

{
  ulong uVar1;
  
  uVar1 = MON_CheckTerrain(instance,bsp,tface);
  if ((uVar1 & 0x10) != 0) {
    INSTANCE_Post(instance,0x100000c,0x10);
  }
  if ((uVar1 & 0x20) != 0) {
    INSTANCE_Post(instance,0x100000c,0x20);
  }
  if ((uVar1 & 0x40) != 0) {
    INSTANCE_Post(instance,0x100000c,0x40);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MON_CheckTerrain(struct _Instance *instance /*$s2*/, struct BSPTree *bsp /*$s1*/, struct _TFace *tface /*$a2*/)
 // line 1736, offset 0x80080afc
	/* begin block 1 */
		// Start line: 1737
		// Start offset: 0x80080AFC
		// Variables:
	// 		unsigned long rv; // $s0

		/* begin block 1.1 */
			// Start line: 1743
			// Start offset: 0x80080B20
			// Variables:
		// 		struct Level *level; // $v1
		/* end block 1.1 */
		// End offset: 0x80080BA0
		// End Line: 1763
	/* end block 1 */
	// End offset: 0x80080BA0
	// End Line: 1765

	/* begin block 2 */
		// Start line: 3614
	/* end block 2 */
	// End Line: 3615

ulong MON_CheckTerrain(_Instance *instance,BSPTree *bsp,_TFace *tface)

{
  Level *pLVar1;
  ulong uVar2;
  
  uVar2 = 0;
  if (tface != (_TFace *)0x0) {
    pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    if (((bsp->flags & 8U) == 0) && (((pLVar1->unitFlags & 2U) != 0 || ((bsp->flags & 0x50U) != 0)))
       ) {
      uVar2 = 0x40;
    }
    if (((bsp->flags & 0x80U) != 0) || (instance->waterFace != (_TFace *)0x0)) {
      uVar2 = uVar2 | 0x10;
    }
    if ((bsp->flags & 0x20U) != 0) {
      uVar2 = uVar2 | 0x20;
    }
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_CheckPointSuitability(struct _Instance *instance /*$s2*/, struct _Position *origin /*$a1*/, struct _Position *destination /*$s4*/)
 // line 1774, offset 0x80080bbc
	/* begin block 1 */
		// Start line: 1775
		// Start offset: 0x80080BBC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		int rc; // $s3
	// 		int result; // $a0
	// 		struct evPhysicsDropHeightData *data; // $s0
	/* end block 1 */
	// End offset: 0x80080C70
	// End Line: 1801

	/* begin block 2 */
		// Start line: 3696
	/* end block 2 */
	// End Line: 3697

int MON_CheckPointSuitability(_Instance *instance,_Position *origin,_Position *destination)

{
  int Data;
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  Data = SetPhysicsDropHeightData(destination,(int)*(short *)(puVar3[0x59] + 0x16),0x40);
  uVar1 = PhysicsCheckDropHeight(instance,Data,1);
  if (uVar1 == 1) {
    uVar2 = MON_CheckTerrain(instance,*(BSPTree **)(Data + 0xc),*(_TFace **)(Data + 0x10));
    uVar1 = uVar2 | 1;
    destination->z = *(short *)(Data + 4);
  }
  Data = 0;
  if (((uVar1 & *(ushort *)((int)puVar3 + 0x14e)) == 0) &&
     (((*puVar3 & 0x800) != 0 || (Data = 0, uVar1 != 0)))) {
    Data = 1;
  }
  return Data;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MON_GetTime(struct _Instance *instance /*$a0*/)
 // line 1876, offset 0x80080c94
	/* begin block 1 */
		// Start line: 3745
	/* end block 1 */
	// End Line: 3746

	/* begin block 2 */
		// Start line: 3831
	/* end block 2 */
	// End Line: 3832

ulong MON_GetTime(_Instance *instance)

{
  if ((instance->object->oflags & 0x80000U) != 0) {
    return gameTrackerX.globalTimeMult;
  }
  if ((instance->flags2 & 0x8000000U) == 0) {
    return gameTrackerX.spectralTimeMult;
  }
  return gameTrackerX.materialTimeMult;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BirthSoul(struct _Instance *instance /*$s0*/, int link /*$s2*/)
 // line 1894, offset 0x80080ce8
	/* begin block 1 */
		// Start line: 1895
		// Start offset: 0x80080CE8
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 1902
			// Start offset: 0x80080D30
			// Variables:
		// 		struct Object *soulob; // $a1

			/* begin block 1.1.1 */
				// Start line: 1909
				// Start offset: 0x80080D40
				// Variables:
			// 		struct _Instance *isoul; // $a0

				/* begin block 1.1.1.1 */
					// Start line: 1924
					// Start offset: 0x80080D7C
					// Variables:
				// 		struct MATRIX *matrix; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x80080D98
				// End Line: 1928
			/* end block 1.1.1 */
			// End offset: 0x80080D98
			// End Line: 1933
		/* end block 1.1 */
		// End offset: 0x80080D98
		// End Line: 1936

		/* begin block 1.2 */
			// Start line: 1939
			// Start offset: 0x80080DA0
			// Variables:
		// 		struct _Instance *isoul; // $a0
		/* end block 1.2 */
		// End offset: 0x80080DF0
		// End Line: 1953
	/* end block 1 */
	// End offset: 0x80080DF0
	// End Line: 1955

	/* begin block 2 */
		// Start line: 3858
	/* end block 2 */
	// End Line: 3859

	/* begin block 3 */
		// Start line: 3866
	/* end block 3 */
	// End Line: 3867

/* WARNING: Removing unreachable block (ram,0x80080d40) */
/* WARNING: Removing unreachable block (ram,0x80080d54) */
/* WARNING: Removing unreachable block (ram,0x80080d68) */
/* WARNING: Removing unreachable block (ram,0x80080d5c) */
/* WARNING: Removing unreachable block (ram,0x80080d6c) */
/* WARNING: Removing unreachable block (ram,0x80080d7c) */

void MON_BirthSoul(_Instance *instance,int link)

{
  _Instance *p_Var1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  if ((*(short *)((int)pvVar2 + 0x144) != 0) && (1 < *(int *)((int)pvVar2 + 0xd8) + 1U)) {
    p_Var1 = INSTANCE_Find(*(int *)((int)pvVar2 + 0xd8));
    if (p_Var1 == (_Instance *)0x0) {
      instance->flags2 = instance->flags2 | 0x80;
    }
    else {
      instance->flags2 = instance->flags2 & 0xffffff7f;
      *(long *)((int)pvVar2 + 0xd8) = p_Var1->introUniqueID;
      *(long *)((int)p_Var1->extraData + 0xd8) = instance->introUniqueID;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ProcessIntro(struct _Instance *instance /*$s2*/)
 // line 1961, offset 0x80080e08
	/* begin block 1 */
		// Start line: 1962
		// Start offset: 0x80080E08
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		long initialBehavior; // $s3
	// 		long triggeredBehavior; // $s5
	// 		long activeBehavior; // $s6
	// 		long guardRange; // $s7
	// 		long wanderRange; // $fp
	// 		long ambushRange; // $t0
	// 		long hitPoints; // $s4
	// 		int spectral; // stack offset -56
	// 		long flags; // $s1
	// 		struct _MonsterAttributes *ma; // $v0

		/* begin block 1.1 */
			// Start line: 1982
			// Start offset: 0x80080EAC
			// Variables:
		// 		struct INICommand *command; // $a2

			/* begin block 1.1.1 */
				// Start line: 2032
				// Start offset: 0x800810F4
				// Variables:
			// 		short *pmarker; // $a0
			// 		int i; // $a1
			// 		long *param; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8008111C
			// End Line: 2047

			/* begin block 1.1.2 */
				// Start line: 2056
				// Start offset: 0x80081144
				// Variables:
			// 		int i; // $a0
			// 		short *unit; // $a1
			/* end block 1.1.2 */
			// End offset: 0x8008117C
			// End Line: 2066
		/* end block 1.1 */
		// End offset: 0x800811F8
		// End Line: 2096
	/* end block 1 */
	// End offset: 0x800812AC
	// End Line: 2130

	/* begin block 2 */
		// Start line: 4003
	/* end block 2 */
	// End Line: 4004

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
  *(undefined2 *)(puVar10 + 0x4f) = 0x800;
  *(undefined2 *)((int)puVar10 + 0x13e) = 0x400;
  iVar13 = -1;
  *(undefined *)((int)puVar10 + 0x15a) = uVar1;
  puVar10[1] = puVar10[1] | 0x80000000;
  psVar8 = (short *)instance->introData;
  uVar11 = 0;
  if ((psVar8 != (short *)0x0) && ((instance->flags & 2U) == 0)) {
    sVar2 = *psVar8;
    sVar3 = *psVar8;
    while (sVar2 != 0) {
      if (sVar3 == 0xc) {
        *(undefined *)((int)puVar10 + 0x152) = *(undefined *)(psVar8 + 2);
      }
      else {
        if (sVar3 < 0xd) {
          if (sVar3 == 6) {
            *(undefined *)((int)puVar10 + 0x15a) = *(undefined *)(psVar8 + 2);
          }
          else {
            if (sVar3 < 7) {
              if (sVar3 == 3) {
                bVar4 = true;
              }
              else {
                if (sVar3 < 4) {
                  if (sVar3 == 1) {
                    iVar12 = *(int *)(psVar8 + 2);
                  }
                  else {
                    if (sVar3 == 2) {
                      iVar14 = *(int *)(psVar8 + 2);
                    }
                  }
                }
                else {
                  if (sVar3 == 4) {
                    iVar17 = *(int *)(psVar8 + 2);
                  }
                  else {
                    if (sVar3 == 5) {
                      iVar16 = *(int *)(psVar8 + 2);
                    }
                  }
                }
              }
            }
            else {
              if (sVar3 == 9) {
                uVar11 = uVar11 | 0x1000000;
                *(short *)((int)puVar10 + 0x146) = psVar8[2];
              }
              else {
                if (sVar3 < 10) {
                  if (sVar3 == 7) {
                    uVar11 = uVar11 | 0x100000;
                  }
                  else {
                    if (sVar3 == 8) {
                      iVar13 = *(int *)(psVar8 + 2);
                    }
                  }
                }
                else {
                  if (sVar3 == 10) {
                    iVar6 = (int)psVar8[1];
                    puVar7 = puVar10 + 0x61;
                    psVar5 = psVar8;
                    while (iVar6 != 0) {
                      psVar5 = psVar5 + 2;
                      iVar6 = iVar6 + -1;
                      *(short *)puVar7 = *psVar5;
                      puVar7 = (uint *)((int)puVar7 + 2);
                    }
                    *(short *)puVar7 = 0;
                    *(uint **)(puVar10 + 0x67) = puVar10 + 0x61;
                  }
                  else {
                    if (sVar3 == 0xb) {
                      *(undefined *)(puVar10 + 0x57) = *(undefined *)(psVar8 + 2);
                    }
                  }
                }
              }
            }
          }
        }
        else {
          if (sVar3 == 0x14) {
            iVar15 = *(int *)(psVar8 + 2);
          }
          else {
            if (sVar3 < 0x15) {
              if (sVar3 == 0xf) {
                puVar10[0x36] = *(uint *)(psVar8 + 2);
              }
              else {
                if (sVar3 < 0x10) {
                  if (sVar3 == 0xd) {
                    *(short *)(puVar10 + 0x4d) = psVar8[2];
                  }
                  else {
                    puVar7 = puVar10 + 0x5c;
                    if (sVar3 == 0xe) {
                      iVar6 = 0;
                      psVar5 = psVar8;
                      if (0 < psVar8[1]) {
                        do {
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
                else {
                  if (sVar3 == 0x10) {
                    *(undefined *)(puVar10 + 0x55) = *(undefined *)(psVar8 + 2);
                    if (puVar10[0x36] == 0) {
                      puVar10[0x36] = 0xffffffff;
                    }
                  }
                  else {
                    if (sVar3 == 0x11) {
                      puVar10[1] = puVar10[1] & 0x7fffffff;
                    }
                  }
                }
              }
            }
            else {
              if (sVar3 == 0x18) {
                *(short *)((int)puVar10 + 0x13e) =
                     (short)((ulonglong)((longlong)(*(int *)(psVar8 + 2) * 0x1000) * 0xb60b60b7) >>
                            0x28) - (short)(*(int *)(psVar8 + 2) * 0x1000 >> 0x1f);
              }
              else {
                if (sVar3 < 0x19) {
                  if (sVar3 == 0x16) {
                    iVar9 = *(int *)(psVar8 + 2);
                  }
                  else {
                    if (sVar3 == 0x17) {
                      *(short *)(puVar10 + 0x4f) =
                           (short)((ulonglong)
                                   ((longlong)(*(int *)(psVar8 + 2) * 0x1000) * 0xb60b60b7) >> 0x28)
                           - (short)(*(int *)(psVar8 + 2) * 0x1000 >> 0x1f);
                    }
                  }
                }
                else {
                  if (sVar3 == 0x19) {
                    *(undefined *)((int)puVar10 + 0x153) = *(undefined *)(psVar8 + 2);
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
  if (iVar12 != -1) {
    *(undefined *)((int)puVar10 + 0x157) = (char)iVar12;
    *(undefined *)((int)puVar10 + 0x156) = (char)iVar12;
  }
  if (iVar14 != -1) {
    *(char *)(puVar10 + 0x56) = (char)iVar14;
  }
  if (iVar15 != -1) {
    *(undefined *)((int)puVar10 + 0x159) = (char)iVar15;
  }
  if (iVar13 != -1) {
    *(short *)(puVar10 + 0x50) = (short)(iVar13 << 8);
  }
  if (bVar4) {
    uVar11 = instance->flags2;
    if ((uVar11 & 0x8000000) == 0) {
      uVar11 = uVar11 | 0x8000000;
    }
    else {
      uVar11 = uVar11 & 0xf7ffffff;
    }
    instance->flags2 = uVar11;
  }
  if (iVar16 != 0) {
    *(short *)(puVar10 + 0x4e) = (short)iVar16;
  }
  if (iVar17 != 0) {
    *(undefined2 *)((int)puVar10 + 0x136) = (short)iVar17;
  }
  if (iVar9 != 0) {
    *(undefined2 *)((int)puVar10 + 0x13a) = (short)iVar9;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SetDefaults(struct _Instance *instance /*$a0*/)
 // line 2135, offset 0x800812dc
	/* begin block 1 */
		// Start line: 2137
		// Start offset: 0x800812DC
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	// 		struct _MonsterAttributes *ma; // $a3
	// 		struct _MonsterSubAttributes *subAttr; // $a2
	/* end block 1 */
	// End offset: 0x800814D4
	// End Line: 2193

	/* begin block 2 */
		// Start line: 4513
	/* end block 2 */
	// End Line: 4514

	/* begin block 3 */
		// Start line: 4514
	/* end block 3 */
	// End Line: 4515

void MON_SetDefaults(_Instance *instance)

{
  short sVar1;
  undefined2 uVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  
  puVar3 = (uint *)instance->extraData;
  pvVar5 = instance->data;
  if ((int)*(char *)((int)pvVar5 + 0x2b) <= (int)(uint)*(byte *)((int)puVar3 + 0x15a)) {
    *(char *)((int)puVar3 + 0x15a) = *(char *)((int)pvVar5 + 0x2b) + -1;
  }
  uVar4 = *(uint *)((uint)*(byte *)((int)puVar3 + 0x15a) * 4 + *(int *)((int)pvVar5 + 0x34));
  puVar3[0x59] = uVar4;
  instance->currentModel = (ushort)*(byte *)(uVar4 + 0x26);
  sVar1 = *(short *)(uVar4 + 0x14);
  (instance->scale).z = sVar1;
  (instance->scale).y = sVar1;
  (instance->scale).x = sVar1;
  *(undefined *)((int)puVar3 + 0x156) = *(undefined *)(uVar4 + 0x34);
  *(undefined *)((int)puVar3 + 0x157) = *(undefined *)(uVar4 + 0x34);
  *(undefined *)(puVar3 + 0x56) = *(undefined *)(uVar4 + 0x35);
  *(undefined2 *)((int)puVar3 + 0x136) = *(undefined2 *)(uVar4 + 0x30);
  *(undefined2 *)(puVar3 + 0x4e) = *(undefined2 *)(uVar4 + 0x32);
  uVar2 = *(undefined2 *)(uVar4 + 0x18);
  *(undefined2 *)(puVar3 + 0x51) = 0x1000;
  *(undefined *)((int)puVar3 + 0x15d) = 3;
  *(undefined *)(puVar3 + 0x58) = 8;
  *(undefined2 *)((int)puVar3 + 0x13a) = uVar2;
  if ((*(int *)(uVar4 + 8) != 0) &&
     (*(short *)(puVar3 + 0x50) = (short)((int)*(char *)(*(int *)(uVar4 + 8) + 0x16) << 8),
     *(char *)(*(int *)(uVar4 + 8) + 0x18) != -1)) {
    *puVar3 = *puVar3 | 0x20;
  }
  if ((*(char *)((int)puVar3 + 0x15a) == '\x02') && ((*(uint *)((int)pvVar5 + 0x10) & 2) != 0)) {
    *puVar3 = *puVar3 | 0x10000000;
  }
  if (*(char *)(uVar4 + 0x37) != '\0') {
    instance->flags2 = instance->flags2 | 0x8000000;
  }
  *(undefined2 *)((int)puVar3 + 0x14e) = 0x100;
  if (*(char *)(uVar4 + 0x3a) != '\0') {
    *(undefined2 *)((int)puVar3 + 0x14e) = 0x110;
  }
  if (*(char *)(uVar4 + 0x39) != '\0') {
    *(ushort *)((int)puVar3 + 0x14e) = *(ushort *)((int)puVar3 + 0x14e) | 0x20;
  }
  if (*(char *)(uVar4 + 0x38) != '\0') {
    *(ushort *)((int)puVar3 + 0x14e) = *(ushort *)((int)puVar3 + 0x14e) | 0x40;
  }
  if (*(char *)(uVar4 + 0x3c) != '\0') {
    *(ushort *)((int)puVar3 + 0x14e) = *(ushort *)((int)puVar3 + 0x14e) | 0x200;
  }
  if (*(char *)(uVar4 + 0x3b) != '\0') {
    *(ushort *)((int)puVar3 + 0x14e) = *(ushort *)((int)puVar3 + 0x14e) | 0x80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GetPlanSlot(struct _MonsterVars *mv /*$s0*/)
 // line 2215, offset 0x800814dc
	/* begin block 1 */
		// Start line: 4423
	/* end block 1 */
	// End Line: 4424

void MON_GetPlanSlot(_MonsterVars *mv)

{
  int iVar1;
  
  if ((int)mv->pathSlotID != -1) {
    ENMYPLAN_ReleasePlanningWorkspace((int)mv->pathSlotID);
  }
  iVar1 = ENMYPLAN_GetInitializedPlanningWorkspaceFinal();
  mv->pathSlotID = (char)iVar1;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_DefaultPlanMovement(struct _Instance *instance /*$s2*/, int anim /*$s4*/, long distance /*$s5*/)
 // line 2226, offset 0x80081520
	/* begin block 1 */
		// Start line: 2227
		// Start offset: 0x80081520
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		int rc; // $s1
	// 		int felloff; // $v1
	// 		long length; // $s3
	// 		struct _MonsterAnim *manim; // $s6

		/* begin block 1.1 */
			// Start line: 2256
			// Start offset: 0x80081614
			// Variables:
		// 		struct _Position pos; // stack offset -40
		// 		int planresult; // $v1

			/* begin block 1.1.1 */
				// Start line: 2296
				// Start offset: 0x800816F4
				// Variables:
			// 		short turnSpeed; // $a2
			/* end block 1.1.1 */
			// End offset: 0x80081770
			// End Line: 2313
		/* end block 1.1 */
		// End offset: 0x80081770
		// End Line: 2313
	/* end block 1 */
	// End offset: 0x800817C0
	// End Line: 2337

	/* begin block 2 */
		// Start line: 4675
	/* end block 2 */
	// End Line: 4676

int MON_DefaultPlanMovement(_Instance *instance,int anim,long distance)

{
  short turnSpeed;
  _MonsterAnim *p_Var1;
  long lVar2;
  int iVar3;
  uint *puVar4;
  undefined4 local_30;
  undefined4 uVar5;
  undefined in_stack_ffffffd4 [12];
  
  puVar4 = (uint *)instance->extraData;
  p_Var1 = MON_GetAnim(instance,*(char **)puVar4[0x59],anim);
  lVar2 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)(puVar4 + 0x48),
                           (int)(instance->position).y - (int)*(short *)((int)puVar4 + 0x122),
                           (int)(instance->position).z - (int)*(short *)(puVar4 + 0x49));
  if (*(char *)((int)puVar4 + 0x162) == -1) {
    return 3;
  }
  if (((*puVar4 & 0x20000) == 0) &&
     (iVar3 = MON_AnimPlaying(instance,(MonsterAnim)CONCAT124(in_stack_ffffffd4,local_30)),
     iVar3 != 0)) {
    *puVar4 = *puVar4 | 0x20000;
  }
  iVar3 = MON_GroundMoveQueueHandler(instance);
  if ((*puVar4 & 1) != 0) {
    return 6;
  }
  if (iVar3 != 0) {
    if ((*puVar4 & 0x20000) != 0) {
      return 3;
    }
    iVar3 = MON_TurnToPosition(instance,(_Position *)(puVar4 + 0x48),*(short *)(puVar4[0x59] + 0x1c)
                              );
    if (iVar3 == 0) {
      return 0;
    }
    return 3;
  }
  if (lVar2 < distance) {
    return 4;
  }
  uVar5 = 0x1f;
  iVar3 = ENMYPLAN_MoveToTargetFinal
                    (instance,(_Position *)&stack0xffffffd8,(int)*(char *)((int)puVar4 + 0x162),
                     (_Position *)(puVar4 + 0x48),0x1f);
  if (iVar3 == 3) {
    return 2;
  }
  if (iVar3 == 0) {
    iVar3 = 1;
    MON_TurnToPosition(instance,(_Position *)(puVar4 + 0x48),*(short *)(puVar4[0x59] + 0x1c));
  }
  else {
    turnSpeed = ENMYPLAN_ReportCurrentGoalUnitID((int)*(char *)((int)puVar4 + 0x162));
    iVar3 = MON_ValidUnit(instance,(int)turnSpeed);
    if (iVar3 == 0) {
      iVar3 = 2;
    }
    else {
      if ((*puVar4 & 0x20000) == 0) {
        *puVar4 = *puVar4 | 0x20000;
      }
      else {
        iVar3 = 0;
        if ((instance->flags2 & 2U) == 0) goto LAB_800816e0;
      }
      MON_PlayAnimIfNotPlaying(instance,(MonsterAnim)CONCAT124(in_stack_ffffffd4,uVar5),anim);
      iVar3 = 0;
    }
  }
LAB_800816e0:
  if ((*puVar4 & 0x20000) != 0) {
    if (anim == 2) {
      turnSpeed = *(short *)(puVar4[0x59] + 0x1e);
    }
    else {
      if (anim == 3) {
        turnSpeed = *(short *)(puVar4[0x59] + 0x20);
      }
      else {
        turnSpeed = *(short *)(puVar4[0x59] + 0x1c);
      }
    }
    if (lVar2 * 3 < (int)((uint)p_Var1->velocity << 0xc) / (int)turnSpeed) {
      turnSpeed = (short)((int)turnSpeed << 1);
    }
    MON_MoveToPosition(instance,(_Position *)&stack0xffffffd8,turnSpeed);
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DropAllObjects(struct _Instance *instance /*$a0*/)
 // line 2367, offset 0x800817e8
	/* begin block 1 */
		// Start line: 2368
		// Start offset: 0x800817E8
		// Variables:
	// 		struct _Instance *child; // $a0

		/* begin block 1.1 */
			// Start line: 2373
			// Start offset: 0x80081804
			// Variables:
		// 		struct _Instance *next; // $s0
		/* end block 1.1 */
		// End offset: 0x80081804
		// End Line: 2373
	/* end block 1 */
	// End offset: 0x80081820
	// End Line: 2377

	/* begin block 2 */
		// Start line: 4960
	/* end block 2 */
	// End Line: 4961

void MON_DropAllObjects(_Instance *instance)

{
  _Instance *Inst;
  _Instance *p_Var1;
  
  Inst = instance->LinkChild;
  while (Inst != (_Instance *)0x0) {
    p_Var1 = Inst->LinkSibling;
    INSTANCE_Post(Inst,0x800008,0);
    Inst = p_Var1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_EnableHeadMove(struct _Instance *instance /*$a0*/)
 // line 2379, offset 0x80081830
	/* begin block 1 */
		// Start line: 2380
		// Start offset: 0x80081830
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s0
	/* end block 1 */
	// End offset: 0x800818C4
	// End Line: 2399

	/* begin block 2 */
		// Start line: 4989
	/* end block 2 */
	// End Line: 4990

void MON_EnableHeadMove(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  void *pvVar2;
  _G2Anim_Type *anim;
  
  pvVar2 = instance->data;
  anim = &instance->anim;
  if ((*(byte *)((int)pvVar2 + 0x1a) != 0) &&
     (_Var1 = G2Anim_IsControllerActive(anim,(uint)*(byte *)((int)pvVar2 + 0x1a),0xe),
     _Var1 == G2FALSE)) {
    G2Anim_SetControllerAngleOrder(anim,(uint)*(byte *)((int)pvVar2 + 0x1a),0xe,1);
    G2Anim_EnableController(anim,(uint)*(byte *)((int)pvVar2 + 0x1a),0xe);
    if ((uint)*(byte *)((int)pvVar2 + 0x22) != (uint)*(byte *)((int)pvVar2 + 0x1a)) {
      G2Anim_SetControllerAngleOrder(anim,(uint)*(byte *)((int)pvVar2 + 0x22),0xe,1);
      G2Anim_EnableController(anim,(uint)*(byte *)((int)pvVar2 + 0x22),0xe);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DisableHeadMove(struct _Instance *instance /*$a0*/)
 // line 2401, offset 0x800818d8
	/* begin block 1 */
		// Start line: 2402
		// Start offset: 0x800818D8
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s0
	/* end block 1 */
	// End offset: 0x80081950
	// End Line: 2414

	/* begin block 2 */
		// Start line: 5033
	/* end block 2 */
	// End Line: 5034

void MON_DisableHeadMove(_Instance *instance)

{
  byte bVar1;
  _G2Bool_Enum _Var2;
  void *pvVar3;
  _G2Anim_Type *anim;
  
  pvVar3 = instance->data;
  anim = &instance->anim;
  if ((*(byte *)((int)pvVar3 + 0x1a) != 0) &&
     (_Var2 = G2Anim_IsControllerActive(anim,(uint)*(byte *)((int)pvVar3 + 0x1a),0xe),
     _Var2 != G2FALSE)) {
    G2Anim_DisableController(anim,(uint)*(byte *)((int)pvVar3 + 0x1a),0xe);
    bVar1 = *(byte *)((int)pvVar3 + 0x22);
    if ((bVar1 != 0) && ((uint)bVar1 != (uint)*(byte *)((int)pvVar3 + 0x1a))) {
      G2Anim_DisableController(anim,(uint)bVar1,0xe);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LookInDirection(struct _Instance *instance /*$a0*/, short tx /*$a1*/, short tz /*$a2*/)
 // line 2419, offset 0x80081964
	/* begin block 1 */
		// Start line: 2420
		// Start offset: 0x80081964
		// Variables:
	// 		struct _G2SVector3_Type Rot; // stack offset -32
	// 		struct _MonsterAttributes *ma; // $s3
	/* end block 1 */
	// End offset: 0x80081AB8
	// End Line: 2443

	/* begin block 2 */
		// Start line: 5069
	/* end block 2 */
	// End Line: 5070

void MON_LookInDirection(_Instance *instance,short tx,short tz)

{
  byte bVar1;
  void *pvVar2;
  _G2SVector3_Type local_20;
  
  pvVar2 = instance->data;
  if (*(char *)((int)pvVar2 + 0x1a) != '\0') {
    if (*(char *)((int)pvVar2 + 0x22) == *(char *)((int)pvVar2 + 0x1a)) {
      bVar1 = *(byte *)((int)pvVar2 + 0x1a);
      local_20.x = tx;
      local_20.z = tz;
    }
    else {
      local_20.y = 0;
      local_20.x = (short)(((int)tx * 0x46) / 100);
      local_20.z = (short)(((int)tz * 0x46) / 100);
      G2Anim_SetController_Vector(&instance->anim,(uint)*(byte *)((int)pvVar2 + 0x1a),0xe,&local_20)
      ;
      if (*(char *)((int)pvVar2 + 0x22) == '\0') {
        return;
      }
      local_20.x = (short)(((int)tx * 0x1e) / 100);
      local_20.z = (short)(((int)tz * 0x1e) / 100);
      bVar1 = *(byte *)((int)pvVar2 + 0x22);
    }
    local_20.y = 0;
    G2Anim_SetController_Vector(&instance->anim,(uint)bVar1,0xe,&local_20);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_LookAtPos(struct _Instance *instance /*$s1*/, struct _Position *position /*$a1*/)
 // line 2450, offset 0x80081ad8
	/* begin block 1 */
		// Start line: 2451
		// Start offset: 0x80081AD8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		short z; // $a0
	/* end block 1 */
	// End offset: 0x80081B8C
	// End Line: 2479

	/* begin block 2 */
		// Start line: 5138
	/* end block 2 */
	// End Line: 5139

void MON_LookAtPos(_Instance *instance,_Position *position)

{
  bool bVar1;
  short destination;
  short sVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  destination = MATH3D_AngleFromPosToPos(&instance->position,position);
  destination = AngleDiff((instance->rotation).z,destination);
  if (destination < 0x31d) {
    if (destination < -0x31c) {
      destination = -0x31c;
    }
  }
  else {
    destination = 0x31c;
  }
  sVar2 = *(short *)((int)pvVar3 + 0x14c) + -0x111;
  if (destination < *(short *)((int)pvVar3 + 0x14c)) {
    *(short *)((int)pvVar3 + 0x14c) = sVar2;
    bVar1 = sVar2 < destination;
  }
  else {
    sVar2 = *(short *)((int)pvVar3 + 0x14c) + 0x111;
    if (destination <= *(short *)((int)pvVar3 + 0x14c)) goto LAB_80081b8c;
    *(short *)((int)pvVar3 + 0x14c) = sVar2;
    bVar1 = destination < sVar2;
  }
  if (bVar1) {
    *(short *)((int)pvVar3 + 0x14c) = destination;
  }
LAB_80081b8c:
  *(undefined2 *)((int)pvVar3 + 0x14a) = 0;
  MON_LookInDirection(instance,0,*(short *)((int)pvVar3 + 0x14c));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ProcessLookAt(struct _Instance *instance /*$s1*/)
 // line 2483, offset 0x80081bb4
	/* begin block 1 */
		// Start line: 2484
		// Start offset: 0x80081BB4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80081C94
	// End Line: 2512

	/* begin block 2 */
		// Start line: 5204
	/* end block 2 */
	// End Line: 5205

void MON_ProcessLookAt(_Instance *instance)

{
  int *piVar1;
  
  piVar1 = (int *)instance->extraData;
  if (piVar1[0x42] != 0x80000) {
    if (*piVar1 < 0) {
      MON_EnableHeadMove(instance);
      MON_LookAtPos(instance,(_Position *)((int)piVar1 + 0x12e));
    }
    else {
      if (piVar1[0x47] == 0) {
        if ((*(short *)((int)piVar1 + 0x14a) == 0) && (*(short *)(piVar1 + 0x53) == 0)) {
          MON_DisableHeadMove(instance);
        }
        else {
          AngleMoveToward((short *)((int)piVar1 + 0x14a),0,100);
          AngleMoveToward((short *)(piVar1 + 0x53),0,100);
          MON_LookInDirection(instance,*(short *)((int)piVar1 + 0x14a),*(short *)(piVar1 + 0x53));
        }
      }
      else {
        MON_EnableHeadMove(instance);
        MON_LookAtPos(instance,(_Position *)piVar1[0x47]);
        piVar1[0x47] = 0;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_TakeDamage(struct _Instance *instance /*$a0*/, int damage /*$s2*/, int type /*$s1*/)
 // line 2517, offset 0x80081ca8
	/* begin block 1 */
		// Start line: 2518
		// Start offset: 0x80081CA8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 2525
			// Start offset: 0x80081CEC
			// Variables:
		// 		long whatAmI; // $v1
		/* end block 1.1 */
		// End offset: 0x80081D34
		// End Line: 2544
	/* end block 1 */
	// End offset: 0x80081D38
	// End Line: 2548

	/* begin block 2 */
		// Start line: 5272
	/* end block 2 */
	// End Line: 5273

int MON_TakeDamage(_Instance *instance,int damage,int type)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  void *pvVar4;
  
  pvVar4 = instance->extraData;
  iVar1 = *(int *)(*(int *)((int)pvVar4 + 0x164) + 8);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    if (*(char *)(iVar1 + 0x16) != '\0') {
      uVar3 = INSTANCE_Query(instance,1);
      if ((type != 0x40000) || (iVar2 = 0, (uVar3 & 8) != 0)) {
        damage = (uint)*(ushort *)((int)pvVar4 + 0x140) - damage;
        *(undefined2 *)((int)pvVar4 + 0x140) = (short)damage;
        iVar2 = 0;
        if (damage * 0x10000 < 1) {
          *(undefined2 *)((int)pvVar4 + 0x140) = 0;
          iVar2 = 1;
        }
      }
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SetUpSaveInfo(struct _Instance *instance /*$a0*/, struct _MonsterSaveInfo *saveData /*$t0*/)
 // line 2553, offset 0x80081d50
	/* begin block 1 */
		// Start line: 2554
		// Start offset: 0x80081D50
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	// 		struct _MonsterAttributes *ma; // $t1
	/* end block 1 */
	// End offset: 0x80081E60
	// End Line: 2575

	/* begin block 2 */
		// Start line: 5350
	/* end block 2 */
	// End Line: 5351

void MON_SetUpSaveInfo(_Instance *instance,_MonsterSaveInfo *saveData)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  void *pvVar6;
  
  puVar5 = (uint *)instance->extraData;
  pvVar6 = instance->data;
  *(undefined *)((int)&saveData->age + 3) = 1;
  saveData->mvFlags = *puVar5 & 0xffbbffff;
  saveData->auxFlags = puVar5[1] & 0xf7ffffff;
  uVar1 = saveData->age;
  uVar2 = (uint)*(byte *)((int)puVar5 + 0x15a) & 7;
  saveData->age = uVar1 & 0xfffffff8 | uVar2;
  uVar3 = (instance->currentMainState & 0x3fU) << 3;
  saveData->age = uVar1 & 0xfffffe00 | uVar2 | uVar3;
  uVar4 = ((uint)*(byte *)((int)puVar5 + 0x156) & 0x1f) << 9;
  saveData->age = uVar1 & 0xffffc000 | uVar2 | uVar3 | uVar4;
  saveData->age =
       uVar1 & 0xff8fc000 | uVar2 | uVar3 | uVar4 | ((uint)*(byte *)(puVar5 + 0x55) & 7) << 0x14;
  saveData->soulJuice = *(short *)(puVar5 + 0x51);
  saveData->soulID = *(short *)(puVar5 + 0x36);
  if (puVar5[0x2f] == 0) {
    uVar2 = saveData->age;
    uVar1 = SEXT14(*(char *)((int)pvVar6 + 0x2f));
  }
  else {
    uVar2 = saveData->age;
    uVar1 = (int)(puVar5[0x2f] - *(int *)((int)pvVar6 + 0x44)) >> 4;
  }
  saveData->age = uVar2 & 0xfff03fff | (uVar1 & 0x3f) << 0xe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GetSaveInfo(struct _Instance *instance /*$s2*/, struct _MonsterSaveInfo *saveData /*$s1*/)
 // line 2580, offset 0x80081e68
	/* begin block 1 */
		// Start line: 2581
		// Start offset: 0x80081E68
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s3
	/* end block 1 */
	// End offset: 0x80081FA4
	// End Line: 2616

	/* begin block 2 */
		// Start line: 5422
	/* end block 2 */
	// End Line: 5423

void MON_GetSaveInfo(_Instance *instance,_MonsterSaveInfo *saveData)

{
  uint index;
  uint *puVar1;
  void *pvVar2;
  
  puVar1 = (uint *)instance->extraData;
  pvVar2 = instance->data;
  *puVar1 = saveData->mvFlags | *puVar1 & 0xc000;
  if ((saveData->mvFlags & 0x8000U) == 0) {
    MON_TurnOffBodySpheres(instance);
  }
  puVar1[1] = saveData->auxFlags | puVar1[1] & 0x8000000;
  *(byte *)((int)puVar1 + 0x15a) = (byte)saveData->age & 7;
  *(byte *)((int)puVar1 + 0x156) = (byte)(saveData->age >> 9) & 0x1f;
  *(byte *)(puVar1 + 0x55) = (byte)(saveData->age >> 0x14) & 7;
  puVar1[0x36] = (int)saveData->soulID;
  *(short *)(puVar1 + 0x51) = saveData->soulJuice;
  switch(saveData->age >> 3 & 0x3f) {
  case 6:
  case 8:
  case 9:
  case 0x15:
  case 0x1c:
    index = 0xd;
    break;
  default:
    index = saveData->age >> 3 & 0x3f;
  }
  instance->currentMainState = index;
  index = saveData->age >> 0xe & 0x3f;
  if ((int)index < (int)*(char *)((int)pvVar2 + 0x2f)) {
    MON_PlayAnimID(instance,index,1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_KillMonster(struct _Instance *instance /*$s0*/)
 // line 2621, offset 0x80081fc0
	/* begin block 1 */
		// Start line: 2622
		// Start offset: 0x80081FC0
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 2626
			// Start offset: 0x80081FF4
			// Variables:
		// 		struct _MonsterAttributes *attr; // $v0
		// 		struct FXSplinter *splintDef; // $v1
		/* end block 1.1 */
		// End offset: 0x8008202C
		// End Line: 2632
	/* end block 1 */
	// End offset: 0x80082094
	// End Line: 2646

	/* begin block 2 */
		// Start line: 5506
	/* end block 2 */
	// End Line: 5507

void MON_KillMonster(_Instance *instance)

{
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if ((*(char *)(puVar1 + 0x55) == '\x04') || (*(char *)(puVar1 + 0x55) == '\x06')) {
    _FX_BuildSplinters(instance,(SVECTOR *)0x0,(SVECTOR *)0x0,(SVECTOR *)0x0,
                       *(FXSplinter **)((int)instance->data + 0x50),gFXT,
                       (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                       (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,8);
  }
  if (((*puVar1 & 0x1000000) == 0) ||
     ((instance->intro != (Intro *)0x0 && ((instance->intro->flags & 0x400U) != 0)))) {
    SAVE_MarkDeadDead(instance);
  }
  else {
    if (*(short *)((int)puVar1 + 0x146) != 0) {
      MONAPI_AddToGenerator(instance);
    }
    SAVE_DeleteInstance(instance);
  }
  instance->flags = instance->flags | 0x20;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIAmbushEnemy(struct _Instance *instance /*$s3*/)
 // line 2652, offset 0x800820b8
	/* begin block 1 */
		// Start line: 2653
		// Start offset: 0x800820B8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s1

		/* begin block 1.1 */
			// Start line: 2659
			// Start offset: 0x800820FC
			// Variables:
		// 		struct _Instance *inst; // $s2
		// 		struct _Position pos; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x80082170
		// End Line: 2675
	/* end block 1 */
	// End offset: 0x800821F0
	// End Line: 2693

	/* begin block 2 */
		// Start line: 5577
	/* end block 2 */
	// End Line: 5578

int MON_ShouldIAmbushEnemy(_Instance *instance)

{
  _StreamUnit *streamUnit;
  int iVar1;
  long lVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  _Instance *p_Var6;
  _Position local_20;
  
  pvVar4 = instance->extraData;
  iVar5 = *(int *)((int)pvVar4 + 0xc4);
  if ((*(char *)((int)pvVar4 + 0x152) != '\0') && (*(int *)((int)pvVar4 + 0x13c) == 0x4000800)) {
    p_Var6 = gameTrackerX.playerInstance;
    if (iVar5 != 0) {
      p_Var6 = *(_Instance **)(iVar5 + 4);
    }
    streamUnit = STREAM_GetStreamUnitWithID(instance->birthStreamUnitID);
    iVar1 = PLANAPI_FindNodePositionInUnit
                      (streamUnit,&local_20,(int)*(char *)((int)pvVar4 + 0x152),4);
    if (iVar1 != 0) {
      lVar2 = MATH3D_LengthXYZ((int)(p_Var6->position).x - (int)local_20.x,
                               (int)(p_Var6->position).y - (int)local_20.y,
                               (int)(p_Var6->position).z - (int)local_20.z);
      return (uint)(lVar2 < *(short *)((int)pvVar4 + 0x13a));
    }
  }
  if (iVar5 == 0) {
    uVar3 = 0;
  }
  else {
    if ((instance->currentMainState != 0x1a) || (uVar3 = 0, (*(ushort *)(iVar5 + 0x16) & 0x40) != 0)
       ) {
      if (*(int *)((int)pvVar4 + 0x13c) == 0x4000800) {
        uVar3 = (uint)(*(short *)(iVar5 + 0x14) < *(short *)((int)pvVar4 + 0x13a));
      }
      else {
        uVar3 = 0;
        if (*(short *)(iVar5 + 0x14) < *(short *)((int)pvVar4 + 0x13a)) {
          uVar3 = MATH3D_ConeDetect((_SVector *)(iVar5 + 0xc),(int)*(short *)((int)pvVar4 + 0x13c),
                                    (int)*(short *)((int)pvVar4 + 0x13e));
        }
      }
    }
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIFireAtTarget(struct _Instance *instance /*$a0*/, struct _MonsterIR *target /*$a1*/)
 // line 2698, offset 0x8008220c
	/* begin block 1 */
		// Start line: 2700
		// Start offset: 0x8008220C
		// Variables:
	// 		struct _MonsterVars *mv; // $a2

		/* begin block 1.1 */
			// Start line: 2706
			// Start offset: 0x8008223C
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v1
		// 		struct _MonsterMissile *missileAttack; // $a0

			/* begin block 1.1.1 */
				// Start line: 2711
				// Start offset: 0x80082274
				// Variables:
			// 		long distance; // $a1

				/* begin block 1.1.1.1 */
					// Start line: 2715
					// Start offset: 0x8008228C
					// Variables:
				// 		struct _MonsterIR *known; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x800822F4
				// End Line: 2732
			/* end block 1.1.1 */
			// End offset: 0x800822F4
			// End Line: 2733
		/* end block 1.1 */
		// End offset: 0x800822F4
		// End Line: 2734
	/* end block 1 */
	// End offset: 0x800822F4
	// End Line: 2738

	/* begin block 2 */
		// Start line: 5671
	/* end block 2 */
	// End Line: 5672

	/* begin block 3 */
		// Start line: 5672
	/* end block 3 */
	// End Line: 5673

int MON_ShouldIFireAtTarget(_Instance *instance,_MonsterIR *target)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  if (((((*puVar3 & 0x20) != 0) && ((target->mirFlags & 0x20) != 0)) &&
      (iVar2 = *(int *)((int)instance->data + 0x40) +
               (int)*(char *)(*(int *)(puVar3[0x59] + 8) + 0x18) * 0x10,
      *(char *)((int)puVar3 + 0x161) < *(char *)(iVar2 + 0xc))) &&
     ((int)target->distance < (int)(uint)*(ushort *)(iVar2 + 2))) {
    piVar1 = (int *)puVar3[0x24];
    while( true ) {
      if (piVar1 == (int *)0x0) {
        return 2;
      }
      if ((((int)*(short *)(piVar1 + 5) < (int)target->distance) &&
          (0 < *(short *)((int)piVar1 + 0xe))) && (*(short *)(piVar1 + 3) < 200)) break;
      piVar1 = (int *)*piVar1;
    }
    return 0;
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIFlee(struct _Instance *instance /*$a0*/)
 // line 2743, offset 0x800822fc
	/* begin block 1 */
		// Start line: 2744
		// Start offset: 0x800822FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $v1
	/* end block 1 */
	// End offset: 0x800823D8
	// End Line: 2768

	/* begin block 2 */
		// Start line: 5774
	/* end block 2 */
	// End Line: 5775

int MON_ShouldIFlee(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  uVar2 = puVar3[0x31];
  if (uVar2 == 0) {
    return 0;
  }
  if ((*(ushort *)(uVar2 + 0x16) & 8) != 0) {
    return 0;
  }
  if (*(short *)(puVar3[0x59] + 0x1a) <= *(short *)(uVar2 + 0x14)) {
    return 0;
  }
  iVar1 = MON_ValidPosition(instance);
  if (iVar1 != 0) {
    if ((*(char *)((int)puVar3 + 0x156) == '\t') ||
       (((*puVar3 & 0x2000000) != 0 &&
        ((puVar3[0x33] == 0 || ((*(ushort *)(puVar3[0x33] + 0x16) & 0x200) == 0)))))) {
      return 1;
    }
    if ((*puVar3 & 0x2000) == 0) {
      return 0;
    }
    if (*(short *)(puVar3 + 0x50) == 0) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_RelocateCoords(struct _Instance *instance /*$a0*/, struct _SVector *offset /*$a1*/)
 // line 2773, offset 0x800823e8
	/* begin block 1 */
		// Start line: 2775
		// Start offset: 0x800823E8
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		int ox; // $a2
	// 		int oy; // $a3
	// 		int oz; // $a1
	/* end block 1 */
	// End offset: 0x800823E8
	// End Line: 2775

	/* begin block 2 */
		// Start line: 5834
	/* end block 2 */
	// End Line: 5835

	/* begin block 3 */
		// Start line: 5835
	/* end block 3 */
	// End Line: 5836

void MON_RelocateCoords(_Instance *instance,_SVector *offset)

{
  short sVar1;
  short sVar2;
  short sVar3;
  void *pvVar4;
  
  pvVar4 = instance->extraData;
  sVar1 = offset->x;
  sVar2 = offset->y;
  sVar3 = offset->z;
  *(short *)((int)pvVar4 + 0x120) = *(short *)((int)pvVar4 + 0x120) + sVar1;
  *(short *)((int)pvVar4 + 0x122) = *(short *)((int)pvVar4 + 0x122) + sVar2;
  *(short *)((int)pvVar4 + 0x124) = *(short *)((int)pvVar4 + 0x124) + sVar3;
  *(short *)((int)pvVar4 + 0x128) = *(short *)((int)pvVar4 + 0x128) + sVar1;
  *(short *)((int)pvVar4 + 0x12a) = *(short *)((int)pvVar4 + 0x12a) + sVar2;
  *(short *)((int)pvVar4 + 300) = *(short *)((int)pvVar4 + 300) + sVar3;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ValidUnit(struct _Instance *instance /*$a0*/, unsigned long unitId /*$a1*/)
 // line 2791, offset 0x80082444
	/* begin block 1 */
		// Start line: 2793
		// Start offset: 0x80082444
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		short *unit; // $a0
	/* end block 1 */
	// End offset: 0x80082488
	// End Line: 2808

	/* begin block 2 */
		// Start line: 5876
	/* end block 2 */
	// End Line: 5877

	/* begin block 3 */
		// Start line: 5877
	/* end block 3 */
	// End Line: 5878

int MON_ValidUnit(_Instance *instance,ulong unitId)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = (ushort *)((int)instance->extraData + 0x170);
  if (*(short *)((int)instance->extraData + 0x170) != 0) {
    while (uVar1 = *puVar2, puVar2 = puVar2 + 1, (unitId & 0xffff) != (uint)uVar1) {
      if (*puVar2 == 0) {
        return 0;
      }
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ValidPosition(struct _Instance *instance /*$s0*/)
 // line 2813, offset 0x80082490
	/* begin block 1 */
		// Start line: 5922
	/* end block 1 */
	// End Line: 5923

int MON_ValidPosition(_Instance *instance)

{
  short sVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = MON_ValidUnit(instance,instance->currentStreamUnitID);
  if (iVar2 != 0) {
    pvVar3 = instance->extraData;
    sVar1 = (instance->position).z;
    *(undefined4 *)((int)pvVar3 + 0x128) = *(undefined4 *)&instance->position;
    *(short *)((int)pvVar3 + 300) = sVar1;
  }
  return (uint)(iVar2 != 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SphereWorldPos(struct MATRIX *mat /*$s1*/, struct _HSphere *sphere /*$a1*/, struct _Position *ret /*$s0*/)
 // line 2827, offset 0x800824e8
	/* begin block 1 */
		// Start line: 5949
	/* end block 1 */
	// End Line: 5950

	/* begin block 2 */
		// Start line: 5955
	/* end block 2 */
	// End Line: 5956

void MON_SphereWorldPos(MATRIX *mat,_HSphere *sphere,_Position *ret)

{
  ApplyMatrixSV(mat,&sphere->position);
  ret->x = ret->x + *(short *)mat->t;
  ret->y = ret->y + *(short *)(mat->t + 1);
  ret->z = ret->z + *(short *)(mat->t + 2);
  return;
}



// decompiled code
// original method signature: 
// struct _HPrim * /*$ra*/ MON_FindSphereForTerrain(struct _Instance *instance /*$a0*/)
 // line 2836, offset 0x80082558
	/* begin block 1 */
		// Start line: 2838
		// Start offset: 0x80082558
		// Variables:
	// 		struct _HModel *hmodel; // $v0
	// 		struct _HPrim *usePrim; // $a3
	// 		struct _HPrim *currentP; // $a0
	// 		struct _HSphere *tempS; // $v0
	// 		int maxRad; // $a2
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x800825DC
	// End Line: 2866

	/* begin block 2 */
		// Start line: 5973
	/* end block 2 */
	// End Line: 5974

	/* begin block 3 */
		// Start line: 5974
	/* end block 3 */
	// End Line: 5975

	/* begin block 4 */
		// Start line: 5975
	/* end block 4 */
	// End Line: 5976

_HPrim * MON_FindSphereForTerrain(_Instance *instance)

{
  ushort uVar1;
  _HModel *p_Var2;
  _HPrim *p_Var3;
  int iVar4;
  ushort uVar5;
  _HPrim *p_Var6;
  
  p_Var6 = (_HPrim *)0x0;
  uVar5 = 0;
  if (instance->hModelList != (_HModel *)0x0) {
    p_Var2 = instance->hModelList + instance->currentModel;
    iVar4 = p_Var2->numHPrims;
    p_Var3 = p_Var2->hPrimList;
    while (iVar4 != 0) {
      if (((*(uint *)p_Var3 & 0xff0200) == 0x10200) &&
         (uVar1 = *(ushort *)(p_Var3->data + 0xe), uVar5 < uVar1)) {
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
 // line 2870, offset 0x800825e4
	/* begin block 1 */
		// Start line: 2871
		// Start offset: 0x800825E4
		// Variables:
	// 		struct Intro *current; // $v1
	// 		struct Intro *res; // $s2
	// 		struct Level *level; // $v0
	// 		int min_dist; // $s3
	// 		int dist; // $v1
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x800826F0
	// End Line: 2914

	/* begin block 2 */
		// Start line: 6051
	/* end block 2 */
	// End Line: 6052

Intro * MON_FindNearestImpalingIntro(int unitID,_Position *position)

{
  Intro *pIVar1;
  int iVar2;
  Level *pLVar3;
  int iVar4;
  long lVar5;
  Intro *pIVar6;
  int iVar7;
  Intro *pIVar8;
  
  pLVar3 = STREAM_GetLevelWithID(unitID);
  pIVar8 = (Intro *)0x0;
  if ((pLVar3 != (Level *)0x0) && (0 < pLVar3->numIntros)) {
    pIVar1 = pLVar3->introList;
    iVar2 = pLVar3->numIntros;
    do {
      iVar7 = iVar2;
      pIVar6 = pIVar1;
      if ((pIVar6->flags & 0x8000U) != 0) {
        iVar4 = MATH3D_LengthXYZ((int)(pIVar6->position).x - (int)position->x,
                                 (int)(pIVar6->position).y - (int)position->y,
                                 (int)(pIVar6->position).z - (int)position->z);
        pIVar8 = pIVar6;
        break;
      }
      pIVar1 = pIVar6 + 1;
      iVar2 = iVar7 + -1;
      iVar4 = 0x7fffffff;
    } while (0 < iVar7 + -1);
    while (pIVar1 = pIVar6, iVar7 = iVar7 + -1, 0 < iVar7) {
      pIVar6 = pIVar1 + 1;
      if (((pIVar1[1].flags & 0x8000U) != 0) &&
         (lVar5 = MATH3D_LengthXYZ((int)pIVar1[1].position.x - (int)position->x,
                                   (int)pIVar1[1].position.y - (int)position->y,
                                   (int)pIVar1[1].position.z - (int)position->z), lVar5 < iVar4)) {
        pIVar8 = pIVar6;
        iVar4 = lVar5;
      }
    }
  }
  return pIVar8;
}



// decompiled code
// original method signature: 
// struct Intro * /*$ra*/ MON_TestForTerrainImpale(struct _Instance *instance /*$s0*/, struct _Terrain *terrain /*$s1*/)
 // line 2918, offset 0x80082714
	/* begin block 1 */
		// Start line: 2919
		// Start offset: 0x80082714
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct Intro *current; // $s1
	// 		struct _HPrim *prim; // $v1
	// 		struct _HSphere *sphere; // $a1
	// 		int i; // $s2
	// 		int radius; // $s3
	// 		struct _Position spherePos; // stack offset -32
	/* end block 1 */
	// End offset: 0x800827F4
	// End Line: 2961

	/* begin block 2 */
		// Start line: 6165
	/* end block 2 */
	// End Line: 6166

Intro * MON_TestForTerrainImpale(_Instance *instance,_Terrain *terrain)

{
  ushort uVar1;
  _HPrim *p_Var2;
  long lVar3;
  short *psVar4;
  Intro *pIVar5;
  int iVar6;
  _Position local_20;
  
  if (*(int *)((int)instance->extraData + 0x108) == 0x100000) {
    p_Var2 = MON_FindSphereForTerrain(instance);
    if (p_Var2 != (_HPrim *)0x0) {
      uVar1 = ((_HSphere *)p_Var2->data)->radius;
      MON_SphereWorldPos((MATRIX *)(instance->matrix + p_Var2->segment),(_HSphere *)p_Var2->data,
                         &local_20);
      iVar6 = terrain->numIntros;
      pIVar5 = terrain->introList;
      psVar4 = &(pIVar5->position).z;
      while (iVar6 != 0) {
        if (((*(uint *)(psVar4 + 4) & 0x8000) != 0) &&
           (lVar3 = MATH3D_LengthXYZ((int)local_20.x - (int)psVar4[-2],
                                     (int)local_20.y - (int)psVar4[-1],
                                     (int)local_20.z - (int)*psVar4), lVar3 < (int)((uint)uVar1 * 3)
           )) {
          return pIVar5;
        }
        iVar6 = iVar6 + -1;
        psVar4 = psVar4 + 0x26;
        pIVar5 = pIVar5 + 1;
      }
    }
  }
  return (Intro *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MoveInstanceToImpalePoint(struct _Instance *instance /*$s2*/)
 // line 2963, offset 0x80082810
	/* begin block 1 */
		// Start line: 2964
		// Start offset: 0x80082810
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct Intro *impaler; // $s1
	// 		struct _HPrim *prim; // $s0
	// 		struct _Position spherePos; // stack offset -32
	// 		struct _Position offset; // stack offset -24

		/* begin block 1.1 */
			// Start line: 2984
			// Start offset: 0x8008285C
			// Variables:
		// 		short _x0; // $a2
		// 		short _y0; // $a3
		// 		short _z0; // $t0
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $v0
		// 		struct _Position *_v; // $a0
		// 		struct _Position *_v0; // $v1
		// 		struct _Position *_v1; // $v0
		/* end block 1.1 */
		// End offset: 0x8008285C
		// End Line: 2984

		/* begin block 1.2 */
			// Start line: 2984
			// Start offset: 0x8008285C
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a0
		// 		struct _Position *_v; // $a1
		/* end block 1.2 */
		// End offset: 0x8008285C
		// End Line: 2984

		/* begin block 1.3 */
			// Start line: 2984
			// Start offset: 0x8008285C
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		// 		struct _Rotation *_v0; // $v0
		// 		struct _Rotation *_v1; // $v0
		/* end block 1.3 */
		// End offset: 0x800828F8
		// End Line: 2989
	/* end block 1 */
	// End offset: 0x800828F8
	// End Line: 2992

	/* begin block 2 */
		// Start line: 6271
	/* end block 2 */
	// End Line: 6272

void MON_MoveInstanceToImpalePoint(_Instance *instance)

{
  short sVar1;
  short sVar2;
  _HPrim *p_Var3;
  Intro *pIVar4;
  void *pvVar5;
  _Position local_20 [2];
  
  pvVar5 = instance->extraData;
  p_Var3 = MON_FindSphereForTerrain(instance);
  if (p_Var3 != (_HPrim *)0x0) {
    pIVar4 = INSTANCE_FindIntro(instance->currentStreamUnitID,*(long *)((int)pvVar5 + 0x1a0));
    if (pIVar4 != (Intro *)0x0) {
      MON_SphereWorldPos((MATRIX *)(instance->matrix + p_Var3->segment),(_HSphere *)p_Var3->data,
                         local_20);
      sVar1 = (pIVar4->position).y;
      sVar2 = (pIVar4->position).z;
      (instance->position).x = (instance->position).x + ((pIVar4->position).x - local_20[0].x);
      (instance->position).y = (instance->position).y + (sVar1 - local_20[0].y);
      (instance->position).z = (instance->position).z + (sVar2 - local_20[0].z);
      sVar1 = (pIVar4->rotation).y;
      sVar2 = (pIVar4->rotation).z;
      (instance->rotation).x = (pIVar4->rotation).x;
      (instance->rotation).y = sVar1;
      (instance->rotation).z = sVar2;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ReachableIntro(struct _Instance *instance /*stack 0*/, struct _Position *pos /*$t0*/, struct _Position *introPos /*$fp*/, struct _Rotation *introRot /*$s7*/, int checkOrientation /*stack 16*/)
 // line 3006, offset 0x80082910
	/* begin block 1 */
		// Start line: 3007
		// Start offset: 0x80082910
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
	// End offset: 0x80082CA8
	// End Line: 3123

	/* begin block 2 */
		// Start line: 6360
	/* end block 2 */
	// End Line: 6361

/* WARNING: Removing unreachable block (ram,0x80082aac) */

int MON_ReachableIntro(_Instance *instance,_Position *pos,_Position *introPos,_Rotation *introRot,
                      int checkOrientation)

{
  bool bVar1;
  short angle;
  int square;
  int iVar2;
  int iVar3;
  int square_00;
  uint uVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  void *pvVar8;
  short sVar9;
  
  square = (int)pos->x - (int)introPos->x;
  iVar2 = (int)pos->y - (int)introPos->y;
  iVar3 = (int)pos->z - (int)introPos->z;
  pvVar8 = instance->extraData;
  square_00 = (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x42);
  angle = 0;
  sVar9 = 0;
  lVar7 = 0;
  square = square * square + iVar2 * iVar2 + iVar3 * iVar3;
  bVar1 = false;
  if ((square < square_00 * square_00) &&
     (iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x40), iVar2 * iVar2 < square)) {
    angle = MATH3D_AngleFromPosToPos(pos,introPos);
    if (checkOrientation != 0) {
      uVar6 = ((int)(instance->rotation).z + 0x800U & 0xfff) - (int)angle & 0xfff;
      iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x44);
      if (uVar6 < 0x801) {
        if ((int)uVar6 < iVar2) {
          checkOrientation = 0;
        }
      }
      else {
        iVar3 = uVar6 - 0x1000;
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (iVar3 < iVar2) {
          checkOrientation = 0;
        }
      }
      if (checkOrientation != 0) goto LAB_80082bac;
    }
    if (introRot != (_Rotation *)0x0) {
      uVar6 = (int)introRot->x + 0x400U & 0xfff;
      uVar4 = uVar6 - 0x1000;
      if ((0x800 < uVar6) && (uVar6 = uVar4, (int)uVar4 < 0)) {
        uVar6 = -uVar4;
      }
      if (0x7f < (int)uVar6) {
        uVar6 = (int)angle + 0x800U & 0xfff;
        sVar9 = (short)uVar6;
        uVar6 = (int)introRot->z - uVar6 & 0xfff;
        if ((0x800 < uVar6) && (uVar6 = uVar6 - 0x1000, (int)uVar6 < 0)) {
          uVar6 = -uVar6;
        }
        if ((int)uVar6 < (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x44)) {
          uVar6 = (uint)(ushort)introRot->x & 0xfff;
          if (0x800 < uVar6) {
            uVar6 = uVar6 - 0x1000;
          }
          bVar1 = true;
          if ((int)uVar6 < 1) {
            iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x48);
            lVar7 = iVar2 - (int)((iVar2 - *(short *)(*(int *)((int)pvVar8 + 0x164) + 0x46)) *
                                 -uVar6) / 0x380;
          }
          else {
            lVar7 = (long)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x48);
          }
        }
        goto LAB_80082bac;
      }
    }
    bVar1 = true;
    lVar7 = (long)*(short *)(*(int *)((int)pvVar8 + 0x164) + 0x46);
  }
LAB_80082bac:
  if (bVar1) {
    iVar2 = (int)introPos->z - (int)pos->z;
    iVar3 = instance->zAccl;
    if (iVar2 != 0) {
      square_00 = (iVar3 * square) / (iVar2 * 2);
      if (square_00 < 0) {
        square_00 = -square_00;
      }
      if (square_00 < lVar7 * lVar7) {
        lVar7 = MATH3D_FastSqrt0(square_00);
      }
    }
    lVar5 = MATH3D_FastSqrt0(square);
    iVar2 = (iVar2 * lVar7) / lVar5 - (iVar3 * lVar5) / (lVar7 << 1);
    square = iVar2;
    if (iVar2 < 0) {
      square = -iVar2;
    }
    if (square < *(short *)(*(int *)((int)pvVar8 + 0x164) + 0x4a)) {
      (instance->rotation).z = sVar9;
      PhysicsSetVelFromZRot(instance,angle,lVar7 + 1);
      instance->zVel = iVar2;
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_SetVelocityTowardsImpalingObject(struct _Instance *instance /*$s3*/, int checkOrientation /*$s4*/)
 // line 3126, offset 0x80082cd8
	/* begin block 1 */
		// Start line: 3127
		// Start offset: 0x80082CD8
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct Intro *currentI; // $s1
	// 		struct _HPrim *usePrim; // $v0
	// 		int i; // $s2
	// 		struct _Position spherePos; // stack offset -32

		/* begin block 1.1 */
			// Start line: 3139
			// Start offset: 0x80082D18
			// Variables:
		// 		struct _Instance *target; // $s0

			/* begin block 1.1.1 */
				// Start line: 3164
				// Start offset: 0x80082DB8
				// Variables:
			// 		struct PhysObProperties *prop; // $v1

				/* begin block 1.1.1.1 */
					// Start line: 3167
					// Start offset: 0x80082DD0
				/* end block 1.1.1.1 */
				// End offset: 0x80082E00
				// End Line: 3172
			/* end block 1.1.1 */
			// End offset: 0x80082E00
			// End Line: 3173
		/* end block 1.1 */
		// End offset: 0x80082E10
		// End Line: 3175
	/* end block 1 */
	// End offset: 0x80082E14
	// End Line: 3178

	/* begin block 2 */
		// Start line: 6656
	/* end block 2 */
	// End Line: 6657

int MON_SetVelocityTowardsImpalingObject(_Instance *instance,int checkOrientation)

{
  Level *pLVar1;
  _HPrim *p_Var2;
  int iVar3;
  ulong uVar4;
  _Rotation *introRot;
  _Instance *Inst;
  Intro *pIVar5;
  int iVar6;
  _Position _Stack32;
  
  pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  p_Var2 = MON_FindSphereForTerrain(instance);
  if (p_Var2 != (_HPrim *)0x0) {
    MON_SphereWorldPos((MATRIX *)(instance->matrix + p_Var2->segment),(_HSphere *)p_Var2->data,
                       &_Stack32);
    iVar6 = pLVar1->terrain->numIntros;
    pIVar5 = pLVar1->terrain->introList;
    introRot = &pIVar5->rotation;
    while (iVar6 != 0) {
      if (((*(uint *)&introRot[2].z & 0x8000) != 0) &&
         (iVar3 = MON_ReachableIntro(instance,&_Stack32,&pIVar5->position,introRot,checkOrientation)
         , iVar3 != 0)) {
        return 1;
      }
      iVar6 = iVar6 + -1;
      introRot = (_Rotation *)&introRot[9].z;
      pIVar5 = pIVar5 + 1;
    }
    Inst = (gameTrackerX.instanceList)->first;
    while (Inst != (_Instance *)0x0) {
      uVar4 = INSTANCE_Query(Inst,1);
      if (((((uVar4 & 0x20) != 0) && (*(short *)((int)Inst->data + 2) == 3)) &&
          ((*(ushort *)((int)Inst->data + 8) & 0x58) != 0)) &&
         (iVar6 = MON_ReachableIntro(instance,&_Stack32,&Inst->position,(_Rotation *)0x0,
                                     checkOrientation), iVar6 != 0)) {
        return 1;
      }
      Inst = Inst->next;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_TurnOffSphereCollisions(struct _Instance *instance /*$a0*/)
 // line 3187, offset 0x80082e34
	/* begin block 1 */
		// Start line: 3189
		// Start offset: 0x80082E34
		// Variables:
	// 		int i; // $a0
	// 		struct _HPrim *hprim; // $v1
	// 		struct _HModel *hmodel; // $v1
	/* end block 1 */
	// End offset: 0x80082E88
	// End Line: 3205

	/* begin block 2 */
		// Start line: 6797
	/* end block 2 */
	// End Line: 6798

	/* begin block 3 */
		// Start line: 6798
	/* end block 3 */
	// End Line: 6799

	/* begin block 4 */
		// Start line: 6800
	/* end block 4 */
	// End Line: 6801

void MON_TurnOffSphereCollisions(_Instance *instance)

{
  _HPrim *p_Var1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = instance->hModelList[instance->currentModel].numHPrims;
  if ((iVar3 != 0) &&
     (p_Var1 = instance->hModelList[instance->currentModel].hPrimList, pbVar2 = &p_Var1->withFlags,
     (p_Var1->withFlags & 0x20) != 0)) {
    do {
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
 // line 3207, offset 0x80082e90
	/* begin block 1 */
		// Start line: 3209
		// Start offset: 0x80082E90
		// Variables:
	// 		int i; // $a0
	// 		struct _HPrim *hprim; // $v1
	// 		struct _HModel *hmodel; // $v1
	/* end block 1 */
	// End offset: 0x80082EE4
	// End Line: 3225

	/* begin block 2 */
		// Start line: 6839
	/* end block 2 */
	// End Line: 6840

	/* begin block 3 */
		// Start line: 6840
	/* end block 3 */
	// End Line: 6841

	/* begin block 4 */
		// Start line: 6842
	/* end block 4 */
	// End Line: 6843

void MON_TurnOnSphereCollisions(_Instance *instance)

{
  _HPrim *p_Var1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = instance->hModelList[instance->currentModel].numHPrims;
  if ((iVar3 != 0) &&
     (p_Var1 = instance->hModelList[instance->currentModel].hPrimList, pbVar2 = &p_Var1->withFlags,
     (p_Var1->withFlags & 0x20) == 0)) {
    do {
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
 // line 3227, offset 0x80082eec
	/* begin block 1 */
		// Start line: 3228
		// Start offset: 0x80082EEC
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		int currentFadeValue; // $a1
	// 		int targetFadeValue; // $v1
	// 		int fadeRate; // $a3
	// 		struct _Instance *child; // $v1
	/* end block 1 */
	// End offset: 0x80083100
	// End Line: 3318

	/* begin block 2 */
		// Start line: 6881
	/* end block 2 */
	// End Line: 6882

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
  if ((instance->object->oflags & 0x80000U) == 0) {
    if ((*(uint *)((int)pvVar5 + 4) & 0x8000000) != 0) {
      iVar3 = (int)*(short *)((int)pvVar5 + 0x1a6) * gameTrackerX.idleTime;
      sVar2 = *(short *)((int)pvVar5 + 0x1a4);
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0xfff;
      }
      iVar3 = (int)instance->fadeValue + (iVar3 >> 0xc);
      if ((int)*(short *)((int)pvVar5 + 0x1a6) < 1) {
        bVar1 = iVar3 < sVar2;
      }
      else {
        bVar1 = sVar2 < iVar3;
      }
      sVar7 = (short)iVar3;
      if (bVar1) {
        *(uint *)((int)pvVar5 + 4) = *(uint *)((int)pvVar5 + 4) & 0xf7ffffff;
        sVar7 = sVar2;
      }
      instance->fadeValue = sVar7;
    }
  }
  else {
    if ((gameTrackerX.gameData.asmData._8_4_ == 1000) ||
       ((gameTrackerX.gameData.asmData.MorphType == 1 &&
        (gameTrackerX.gameData.asmData.MorphTime != 1000)))) {
      iVar3 = (int)*(short *)((int)pvVar5 + 0x1a4);
      iVar8 = 0x1000 - iVar3;
    }
    else {
      iVar8 = (int)*(short *)((int)pvVar5 + 0x1a4);
      iVar3 = 0x1000 - iVar8;
    }
    iVar6 = (int)gameTrackerX.gameData.asmData.MorphTime;
    if (iVar6 < 0x14d) {
      iVar6 = (0x1000 - iVar8) * iVar6;
      sVar2 = (short)iVar8 +
              ((short)((ulonglong)((longlong)iVar6 * 0xc4ce07b1) >> 0x28) - (short)(iVar6 >> 0x1f));
    }
    else {
      if (iVar6 < 0x29b) {
        sVar2 = 0x1000;
      }
      else {
        iVar3 = (iVar3 + -0x1000) * (iVar6 + -0x29a);
        sVar2 = ((short)((ulonglong)((longlong)iVar3 * 0xc4ce07b1) >> 0x28) - (short)(iVar3 >> 0x1f)
                ) + 0x1000;
      }
    }
    instance->fadeValue = sVar2;
    if (instance->fadeValue < 0) {
      instance->fadeValue = 0;
    }
    else {
      if (0x1000 < instance->fadeValue) {
        instance->fadeValue = 0x1000;
      }
    }
    if (instance->fadeValue == 0x1000) {
      MON_TurnOffSphereCollisions(instance);
      instance->flags = instance->flags | 0x800;
    }
    else {
      MON_TurnOnSphereCollisions(instance);
      instance->flags = instance->flags & 0xfffff7ff;
    }
  }
  p_Var4 = instance->LinkChild;
  while (p_Var4 != (_Instance *)0x0) {
    p_Var4->fadeValue = instance->fadeValue;
    p_Var4 = p_Var4->LinkSibling;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_StartSpecialFade(struct _Instance *instance /*$a0*/, int fadeLevel /*$a1*/, int fadeTime /*$a2*/)
 // line 3320, offset 0x80083110
	/* begin block 1 */
		// Start line: 3322
		// Start offset: 0x80083110
		// Variables:
	// 		struct _MonsterVars *mv; // $a3
	// 		int diff; // $a1
	/* end block 1 */
	// End offset: 0x80083170
	// End Line: 3335

	/* begin block 2 */
		// Start line: 7076
	/* end block 2 */
	// End Line: 7077

	/* begin block 3 */
		// Start line: 7077
	/* end block 3 */
	// End Line: 7078

void MON_StartSpecialFade(_Instance *instance,int fadeLevel,int fadeTime)

{
  void *pvVar1;
  uint uVar2;
  
  pvVar1 = instance->extraData;
  *(undefined2 *)((int)pvVar1 + 0x1a4) = (short)fadeLevel;
  *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) | 0x8000000;
  fadeLevel = fadeLevel - instance->fadeValue;
  if (fadeTime < 1) {
    fadeTime = 1;
  }
  uVar2 = fadeLevel / fadeTime;
  *(undefined2 *)((int)pvVar1 + 0x1a6) = (short)uVar2;
  if ((uVar2 & 0xffff) == 0) {
    if (fadeLevel < 0) {
      *(undefined2 *)((int)pvVar1 + 0x1a6) = 0xffff;
      return;
    }
    *(undefined2 *)((int)pvVar1 + 0x1a6) = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_UnlinkFromRaziel(struct _Instance *instance /*$s0*/)
 // line 3337, offset 0x80083178
	/* begin block 1 */
		// Start line: 3338
		// Start offset: 0x80083178
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct evPositionData *data; // $v1
	// 		struct _Instance *enemy; // $s1
	// 		struct _MonsterAttributes *ma; // $s2
	/* end block 1 */
	// End offset: 0x800831F8
	// End Line: 3357

	/* begin block 2 */
		// Start line: 7111
	/* end block 2 */
	// End Line: 7112

void MON_UnlinkFromRaziel(_Instance *instance)

{
  short *psVar1;
  undefined4 local_10;
  undefined4 local_c;
  _Instance *Inst;
  void *pvVar2;
  
  pvVar2 = instance->data;
  Inst = *(_Instance **)(*(int *)((int)instance->extraData + 0xc4) + 4);
  INSTANCE_UnlinkFromParent(instance);
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  psVar1 = (short *)INSTANCE_Query(Inst,7);
  if (psVar1 != (short *)0x0) {
    (instance->rotation).x = *psVar1;
    (instance->rotation).y = psVar1[1];
    (instance->rotation).z = psVar1[2] + 0x800;
  }
  INSTANCE_Post(Inst,0x1000006,(int)instance);
  G2Anim_DisableSegment(&instance->anim,(uint)*(byte *)((int)pvVar2 + 0x25));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BirthMana(struct _Instance *instance /*$s0*/)
 // line 3362, offset 0x80083230
	/* begin block 1 */
		// Start line: 3363
		// Start offset: 0x80083230

		/* begin block 1.1 */
			// Start line: 3366
			// Start offset: 0x80083250
			// Variables:
		// 		struct _MonsterVars *mv; // $v0

			/* begin block 1.1.1 */
				// Start line: 3370
				// Start offset: 0x8008326C
				// Variables:
			// 		int type; // $a0
			// 		struct MATRIX *mat; // $a3
			/* end block 1.1.1 */
			// End offset: 0x800832D8
			// End Line: 3373
		/* end block 1.1 */
		// End offset: 0x800832D8
		// End Line: 3374
	/* end block 1 */
	// End offset: 0x800832D8
	// End Line: 3375

	/* begin block 2 */
		// Start line: 7162
	/* end block 2 */
	// End Line: 7163

void MON_BirthMana(_Instance *instance)

{
  int iVar1;
  MATRIX *pMVar2;
  
  if ((instance->matrix != (MATRIX *)0x0) && (*(char *)((int)instance->extraData + 0x161) < '\x0f'))
  {
    iVar1 = rand();
    pMVar2 = instance->matrix;
    PHYSOB_BirthCollectible
              (instance,pMVar2[1].t[0],pMVar2[1].t[1],pMVar2[1].t[2],(uint)(iVar1 % 100 < 0x50) ^ 1,
               10);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SoulSucked(struct _Instance *instance /*$s1*/)
 // line 3377, offset 0x800832e8
	/* begin block 1 */
		// Start line: 3378
		// Start offset: 0x800832E8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80083354
	// End Line: 3389

	/* begin block 2 */
		// Start line: 7195
	/* end block 2 */
	// End Line: 7196

void MON_SoulSucked(_Instance *instance)

{
  ulong uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x200) != 0) {
    if ((*(uint *)((int)instance->data + 0x10) & 8) == 0) {
      uVar1 = MON_GetTime(instance);
      puVar2[0x43] = uVar1;
    }
    puVar2[0x36] = 0;
    MON_DropAllObjects(instance);
    MON_BirthMana(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_SetUpKnockBack(struct _Instance *instance /*$s2*/, struct _Instance *enemy /*$s1*/, struct evMonsterHitData *data /*$a2*/)
 // line 3394, offset 0x80083368
	/* begin block 1 */
		// Start line: 3395
		// Start offset: 0x80083368
		// Variables:
	// 		struct _MonsterVars *mv; // $s5
	// 		long d; // $s0
	// 		long t; // $s4
	// 		long a; // $s3
	// 		long v; // $s0
	// 		int front; // $s0
	/* end block 1 */
	// End offset: 0x8008342C
	// End Line: 3424

	/* begin block 2 */
		// Start line: 7229
	/* end block 2 */
	// End Line: 7230

int MON_SetUpKnockBack(_Instance *instance,_Instance *enemy,evMonsterHitData *data)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  long a;
  long v;
  ulong uVar4;
  void *pvVar5;
  
  sVar3 = data->knockBackDistance;
  sVar1 = data->knockBackDuration;
  pvVar5 = instance->extraData;
  a = PHYSICS_FindAFromDAndT((int)sVar3,(int)sVar1);
  v = PHYSICS_FindVFromAAndD(a,(int)sVar3);
  sVar3 = MATH3D_AngleFromPosToPos(&instance->position,&enemy->position);
  bVar2 = 0x7ff < (((instance->rotation).z - sVar3) + 0x400U & 0xfff);
  if (bVar2) {
    PHYSICS_SetVAndAFromRot(instance,&instance->rotation,v,-a);
  }
  else {
    MON_TurnToPosition(instance,&enemy->position,0x1000);
    PHYSICS_SetVAndAFromRot(instance,&instance->rotation,-v,a);
  }
  uVar4 = MON_GetTime(instance);
  *(int *)((int)pvVar5 + 0x114) = uVar4 + (int)sVar1 * 0x21;
  return (uint)!bVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_DoDrainEffects(struct _Instance *instance /*$s1*/, struct _Instance *ei /*$s0*/)
 // line 3429, offset 0x8008346c
	/* begin block 1 */
		// Start line: 3430
		// Start offset: 0x8008346C
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s3
	// 		struct _MonsterVars *mv; // $s2
	// 		struct MATRIX *mat; // $t2
	// 		struct _SVector location; // stack offset -56
	// 		struct _SVector position; // stack offset -48
	// 		struct _SVector vel; // stack offset -40
	// 		struct _SVector accel; // stack offset -32
	/* end block 1 */
	// End offset: 0x800836DC
	// End Line: 3475

	/* begin block 2 */
		// Start line: 7300
	/* end block 2 */
	// End Line: 7301

void MON_DoDrainEffects(_Instance *instance,_Instance *ei)

{
  int iVar1;
  MATRIX *pMVar2;
  void *pvVar3;
  void *pvVar4;
  _SVector local_38;
  _SVector local_30;
  _SVector local_28;
  _SVector _Stack32;
  
  pvVar4 = instance->data;
  pvVar3 = instance->extraData;
  memset(&_Stack32,0,8);
  if (ei == gameTrackerX.playerInstance) {
    iVar1 = rand();
    pMVar2 = ei->matrix;
    iVar1 = (iVar1 % (ei->object->modelList[ei->currentModel]->numSegments + -0x10)) * 0x20 + 0x1c0;
  }
  else {
    iVar1 = rand();
    pMVar2 = ei->matrix;
    iVar1 = iVar1 % ei->object->modelList[ei->currentModel]->numSegments << 5;
  }
  iVar1 = (int)pMVar2->m + iVar1;
  local_38.x = *(short *)(iVar1 + 0x14);
  local_38.y = *(short *)(iVar1 + 0x18);
  local_38.z = *(short *)(iVar1 + 0x1c);
  pMVar2 = instance->matrix + *(byte *)((int)pvVar4 + 0x19);
  iVar1 = pMVar2->t[0] - (int)local_38.x;
  local_28.x = (short)(iVar1 / 6 + (iVar1 >> 0x1f) >> 3) - (short)(iVar1 >> 0x1f);
  iVar1 = pMVar2->t[1] - (int)local_38.y;
  local_28.y = (short)(iVar1 / 6 + (iVar1 >> 0x1f) >> 3) - (short)(iVar1 >> 0x1f);
  iVar1 = pMVar2->t[2] - (int)local_38.z;
  local_28.z = (short)(iVar1 / 6 + (iVar1 >> 0x1f) >> 3) - (short)(iVar1 >> 0x1f);
  local_30.x = *(short *)pMVar2->t;
  local_30.y = *(short *)(pMVar2->t + 1);
  local_30.z = *(short *)(pMVar2->t + 2);
  FX_Dot(&local_38,&local_28,&_Stack32,0,0xff6060,0x18,0x14,0);
  if (ei == gameTrackerX.playerInstance) {
    pMVar2 = ei->matrix;
    local_38.x = *(short *)pMVar2[0xe].t;
    local_38.y = *(short *)(pMVar2[0xe].t + 1);
    local_38.z = *(short *)(pMVar2[0xe].t + 2);
    *(uint *)((int)pvVar3 + 0x118) =
         *(int *)((int)pvVar3 + 0x118) + (gameTrackerX.idleTime * 0x50 >> 0xc) & 0xfff;
    FX_Lightning((MATRIX *)theCamera.core.wcTransform,(ulong **)gameTrackerX.defVVRemoveDist,
                 (MATRIX *)0x0,*(short *)((int)pvVar3 + 0x118),&local_30,&local_38,0,0x60,0x18,0x50,
                 1,0xd06060,0xff6400);
  }
  return;
}





