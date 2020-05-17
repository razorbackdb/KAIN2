#include "THISDUST.H"
#include "MONLIB.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MON_TurnOffWeaponSpheres(struct _Instance *instance /*$s1*/)
 // line 148, offset 0x8007f5d8
	/* begin block 1 */
		// Start line: 149
		// Start offset: 0x8007F5D8
		// Variables:
	// 		struct _MonsterVars *mv; // $s2

		/* begin block 1.1 */
			// Start line: 153
			// Start offset: 0x8007F600
			// Variables:
		// 		struct _Instance *weapon; // $s0
		/* end block 1.1 */
		// End offset: 0x8007F620
		// End Line: 157

		/* begin block 1.2 */
			// Start line: 160
			// Start offset: 0x8007F634
			// Variables:
		// 		int i; // $a1
		// 		struct _HPrim *hprim; // $v1
		// 		struct _HModel *hmodel; // $v1
		/* end block 1.2 */
		// End offset: 0x8007F6B8
		// End Line: 168
	/* end block 1 */
	// End offset: 0x8007F6B8
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
 // line 174, offset 0x8007f6d0
	/* begin block 1 */
		// Start line: 176
		// Start offset: 0x8007F6D0
		// Variables:
	// 		struct _MonsterVars *mv; // $a2

		/* begin block 1.1 */
			// Start line: 179
			// Start offset: 0x8007F6FC
			// Variables:
		// 		int i; // $a1
		// 		struct _HPrim *hprim; // $a0
		// 		struct _HModel *hmodel; // $v0
		/* end block 1.1 */
		// End offset: 0x8007F780
		// End Line: 191
	/* end block 1 */
	// End offset: 0x8007F780
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
 // line 198, offset 0x8007f788
	/* begin block 1 */
		// Start line: 199
		// Start offset: 0x8007F788
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 204
			// Start offset: 0x8007F7A4
			// Variables:
		// 		struct _Instance *weapon; // $v0
		/* end block 1.1 */
		// End offset: 0x8007F7B4
		// End Line: 208

		/* begin block 1.2 */
			// Start line: 214
			// Start offset: 0x8007F7EC
			// Variables:
		// 		int i; // $a2
		// 		struct _HPrim *hprim; // $a0
		// 		struct _HModel *hmodel; // $v0
		/* end block 1.2 */
		// End offset: 0x8007F880
		// End Line: 223
	/* end block 1 */
	// End offset: 0x8007F880
	// End Line: 224

	/* begin block 2 */
		// Start line: 404
	/* end block 2 */
	// End Line: 405

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
 // line 229, offset 0x8007f890
	/* begin block 1 */
		// Start line: 231
		// Start offset: 0x8007F890
		// Variables:
	// 		struct _MonsterVars *mv; // $a2

		/* begin block 1.1 */
			// Start line: 234
			// Start offset: 0x8007F8AC
			// Variables:
		// 		int i; // $a1
		// 		struct _HPrim *hprim; // $v1
		// 		struct _HModel *hmodel; // $v1
		/* end block 1.1 */
		// End offset: 0x8007F930
		// End Line: 242
	/* end block 1 */
	// End offset: 0x8007F930
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
 // line 248, offset 0x8007f938
	/* begin block 1 */
		// Start line: 250
		// Start offset: 0x8007F938
		// Variables:
	// 		struct _MonsterVars *mv; // $a2

		/* begin block 1.1 */
			// Start line: 253
			// Start offset: 0x8007F964
			// Variables:
		// 		int i; // $a1
		// 		struct _HPrim *hprim; // $a0
		// 		struct _HModel *hmodel; // $v0
		/* end block 1.1 */
		// End offset: 0x8007F9E4
		// End Line: 261
	/* end block 1 */
	// End offset: 0x8007F9E4
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
 // line 267, offset 0x8007f9ec
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
 // line 276, offset 0x8007fa18
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
 // line 318, offset 0x8007fa44
	/* begin block 1 */
		// Start line: 319
		// Start offset: 0x8007FA44
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007FB28
	// End Line: 357

	/* begin block 2 */
		// Start line: 636
	/* end block 2 */
	// End Line: 637

void MON_SwitchState(_Instance *instance,MonsterState state)

{
  int in_a1;
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  if ((*puVar1 & 0x4000) != 0) {
    MON_TurnOffWeaponSpheres(instance);
  }
  if ((*puVar1 & 1) == 0) {
    *(undefined *)((int)puVar1 + 0x159) = *(undefined *)&instance->currentMainState;
  }
  if ((((in_a1 == 0x10) || (in_a1 == 0x17)) || (in_a1 == 7)) || ((in_a1 == 10 || (in_a1 == 3)))) {
    PurgeMessageQueue((__MessageQueue *)(puVar1 + 2));
  }
  instance->currentMainState = in_a1;
  *puVar1 = *puVar1 & 0xbbfdefff | 1;
  if ((int)*(char *)((int)puVar1 + 0x166) != -1) {
    ENMYPLAN_ReleasePlanningWorkspace((int)*(char *)((int)puVar1 + 0x166));
    *(undefined *)((int)puVar1 + 0x166) = 0xff;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SwitchStateDoEntry(struct _Instance *instance /*$s1*/, enum MonsterState state /*$a1*/)
 // line 360, offset 0x8007fb40
	/* begin block 1 */
		// Start line: 361
		// Start offset: 0x8007FB40
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007FB94
	// End Line: 376

	/* begin block 2 */
		// Start line: 707
	/* end block 2 */
	// End Line: 708

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
 // line 388, offset 0x8007fba8
	/* begin block 1 */
		// Start line: 763
	/* end block 1 */
	// End Line: 764

int MON_TransNodeAnimation(_Instance *instance)

{
  _G2Bool_Enum _Var1;
  
  _Var1 = G2Anim_SegmentHasActiveChannels(&instance->anim,0,0x700);
  return _Var1;
}



// decompiled code
// original method signature: 
// struct _MonsterAnim * /*$ra*/ MON_GetAnim(struct _Instance *instance /*$a0*/, char *animList /*$a1*/, int index /*$a2*/)
 // line 397, offset 0x8007fbd0
	/* begin block 1 */
		// Start line: 399
		// Start offset: 0x8007FBD0
		// Variables:
	// 		int whichAnim; // $a1
	/* end block 1 */
	// End offset: 0x8007FBFC
	// End Line: 404

	/* begin block 2 */
		// Start line: 782
	/* end block 2 */
	// End Line: 783

	/* begin block 3 */
		// Start line: 783
	/* end block 3 */
	// End Line: 784

_MonsterAnim * MON_GetAnim(_Instance *instance,char *animList,int index)

{
  if ((int)animList[index] != -1) {
    return (_MonsterAnim *)(*(int *)((int)instance->data + 0x40) + (int)animList[index] * 0x10);
  }
  return (_MonsterAnim *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnimID(struct _Instance *instance /*$s3*/, int index /*$a1*/, int mode /*$fp*/)
 // line 409, offset 0x8007fc04
	/* begin block 1 */
		// Start line: 410
		// Start offset: 0x8007FC04
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
	// End offset: 0x8007FD38
	// End Line: 466

	/* begin block 2 */
		// Start line: 808
	/* end block 2 */
	// End Line: 809

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
  
  uVar4 = *(int *)((int)instance->data + 0x40) + index * 0x10;
  iVar6 = (int)*(char *)(uVar4 + 0xc);
  puVar5 = (uint *)instance->extraData;
  if ((iVar6 < 0) || (instance->object->numAnims <= iVar6)) {
    iVar6 = 0;
  }
  G2Anim_SetCallback(&instance->anim,INSTANCE_DefaultAnimCallback,instance);
  uVar3 = puVar5[0x2f];
  if ((uVar3 == 0) || (bVar1 = *(byte *)(uVar3 + 8), bVar1 == 0)) {
    bVar1 = *(byte *)(uVar4 + 6);
    bVar2 = *(byte *)(uVar4 + 9);
  }
  else {
    bVar2 = *(byte *)(uVar3 + 10);
  }
  CurrentSection = 0;
  uVar3 = uVar4;
  if (*(char *)(puVar5[0x5a] + 0x2a) != '\0') {
    do {
      NewAnim = (int)*(char *)(uVar3 + 0xc);
      if ((int)*(char *)(uVar3 + 0xc) == -1) {
        NewAnim = iVar6;
      }
      G2EmulationInstanceSwitchAnimationAlpha
                (instance,CurrentSection,NewAnim,(uint)*(byte *)(uVar4 + 7),(uint)bVar1,mode,
                 (uint)bVar2);
      G2EmulationInstanceSetAnimSpeed(instance,CurrentSection,(uint)*(ushort *)(uVar4 + 4));
      CurrentSection = CurrentSection + 1;
      uVar3 = uVar4 + CurrentSection;
    } while (CurrentSection < (int)(uint)*(byte *)(puVar5[0x5a] + 0x2a));
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
 // line 470, offset 0x8007fdbc
	/* begin block 1 */
		// Start line: 977
	/* end block 1 */
	// End Line: 978

void MON_PlayAnimFromList(_Instance *instance,char *animList,int animtype,int mode)

{
  MON_PlayAnimID(instance,(int)animList[animtype],mode);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_AnimIDPlaying(struct _Instance *instance /*$a0*/, int index /*$a1*/)
 // line 475, offset 0x8007fde4
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x8007FDE4
		// Variables:
	// 		struct _MonsterAttributes *ma; // $v0
	/* end block 1 */
	// End offset: 0x8007FDE4
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

int MON_AnimIDPlaying(_Instance *instance,int index)

{
  return (uint)(*(int *)((int)instance->extraData + 0xbc) ==
               *(int *)((int)instance->data + 0x40) + index * 0x10);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnimIDIfNotPlaying(struct _Instance *instance /*$s0*/, int index /*$s1*/, int mode /*$s2*/)
 // line 482, offset 0x8007fe08
	/* begin block 1 */
		// Start line: 1004
	/* end block 1 */
	// End Line: 1005

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
 // line 491, offset 0x8007fe58
	/* begin block 1 */
		// Start line: 1022
	/* end block 1 */
	// End Line: 1023

int MON_AnimPlayingFromList(_Instance *instance,char *animList,int animtype)

{
  int iVar1;
  
  iVar1 = MON_AnimIDPlaying(instance,(int)animList[animtype]);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnimFromListIfNotPlaying(struct _Instance *instance /*$s1*/, char *animList /*$a1*/, int animtype /*$a2*/, int mode /*$s2*/)
 // line 496, offset 0x8007fe80
	/* begin block 1 */
		// Start line: 497
		// Start offset: 0x8007FE80
		// Variables:
	// 		int index; // $s0
	/* end block 1 */
	// End offset: 0x8007FEC0
	// End Line: 502

	/* begin block 2 */
		// Start line: 1033
	/* end block 2 */
	// End Line: 1034

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
 // line 508, offset 0x8007fed8
	/* begin block 1 */
		// Start line: 1059
	/* end block 1 */
	// End Line: 1060

void MON_PlayAnim(_Instance *instance,MonsterAnim animtype,int mode)

{
  int in_a2;
  
  MON_PlayAnimFromList(instance,**(char ***)((int)instance->extraData + 0x168),mode,in_a2);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_AnimPlaying(struct _Instance *instance /*$a0*/, enum MonsterAnim animtype /*$a2*/)
 // line 516, offset 0x8007ff0c
	/* begin block 1 */
		// Start line: 1076
	/* end block 1 */
	// End Line: 1077

int MON_AnimPlaying(_Instance *instance,MonsterAnim animtype)

{
  int iVar1;
  int in_a1;
  
  iVar1 = MON_AnimPlayingFromList(instance,**(char ***)((int)instance->extraData + 0x168),in_a1);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayAnimIfNotPlaying(struct _Instance *instance /*$a0*/, enum MonsterAnim animtype /*$a1*/, int mode /*$a3*/)
 // line 524, offset 0x8007ff40
	/* begin block 1 */
		// Start line: 1093
	/* end block 1 */
	// End Line: 1094

void MON_PlayAnimIfNotPlaying(_Instance *instance,MonsterAnim animtype,int mode)

{
  int in_a2;
  
  MON_PlayAnimFromListIfNotPlaying
            (instance,**(char ***)((int)instance->extraData + 0x168),mode,in_a2);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ MON_AnimCallback(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s0*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
 // line 566, offset 0x8007ff74
	/* begin block 1 */
		// Start line: 567
		// Start offset: 0x8007FF74
		// Variables:
	// 		struct _Instance *instance; // $a3
	// 		struct _MonsterVars *mv; // $t0
	/* end block 1 */
	// End offset: 0x80080010
	// End Line: 591

	/* begin block 2 */
		// Start line: 1132
	/* end block 2 */
	// End Line: 1133

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
        **(uint **)((int)data + 0x16c) = **(uint **)((int)data + 0x16c) & 0xfbffffff;
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
 // line 597, offset 0x80080024
	/* begin block 1 */
		// Start line: 598
		// Start offset: 0x80080024
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct _G2AnimSection_Type *animSection; // $s3
	// 		int i; // $s0
	// 		int startSection; // $s6
	// 		int numSections; // $s7

		/* begin block 1.1 */
			// Start line: 611
			// Start offset: 0x80080080
			// Variables:
		// 		int sectionEnd; // $a3
		/* end block 1.1 */
		// End offset: 0x80080104
		// End Line: 621
	/* end block 1 */
	// End offset: 0x8008014C
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
  bVar1 = *(byte *)(*(int *)((int)pvVar3 + 0x168) + 0x2a);
  CurrentSection = 0;
  *(undefined4 *)((int)pvVar3 + 0xbc) = 0;
  G2EmulationInstanceSetTotalSections(instance,(ushort)bVar1);
  iVar5 = 0x94;
  if (bVar1 != 0) {
    iVar4 = 0x1ec;
    do {
      bVar2 = *(byte *)(*(int *)((int)pvVar3 + 0x168) + CurrentSection + 0x2b);
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
        iVar6 = (uint)*(byte *)(*(int *)((int)pvVar3 + 0x168) + CurrentSection + 0x2b) + 1;
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
  MON_PlayRandomIdle(instance,2);
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ MON_FacingOffset(struct _Instance *instance /*$a0*/, struct _Instance *target /*$s0*/)
 // line 638, offset 0x8008019c
	/* begin block 1 */
		// Start line: 639
		// Start offset: 0x8008019C
	/* end block 1 */
	// End offset: 0x8008019C
	// End Line: 639

	/* begin block 2 */
		// Start line: 1309
	/* end block 2 */
	// End Line: 1310

short MON_FacingOffset(_Instance *instance,_Instance *target)

{
  ushort uVar1;
  
  uVar1 = MATH3D_AngleFromPosToPos(&target->position,&instance->position);
  return (short)(((uint)uVar1 - (uint)(ushort)(target->rotation).z) * 0x10000 >> 0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_CheckConditions(struct _Instance *instance /*$a0*/, struct _MonsterIR *mir /*$a1*/, char *probArray /*$a2*/)
 // line 651, offset 0x800801d8
	/* begin block 1 */
		// Start line: 653
		// Start offset: 0x800801D8
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		char *probability; // $a2
	// 		int chance; // $a1
	// 		int i; // $t1
	// 		int prob; // $a3
	// 		int nprob; // $t0

		/* begin block 1.1 */
			// Start line: 663
			// Start offset: 0x80080208
			// Variables:
		// 		int conditionProb; // $v0
		/* end block 1.1 */
		// End offset: 0x8008026C
		// End Line: 674
	/* end block 1 */
	// End offset: 0x8008027C
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
  return (uint)((int)*(char *)((int)instance->extraData + 0x165) < ((100 - iVar2) * iVar3) / 100);
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIAttackInstance(struct _Instance *instance /*$s2*/, struct _Instance *ei /*$s0*/)
 // line 695, offset 0x800802b0
	/* begin block 1 */
		// Start line: 696
		// Start offset: 0x800802B0

		/* begin block 1.1 */
			// Start line: 699
			// Start offset: 0x800802D8
			// Variables:
		// 		struct _Instance *enemyAttackee; // $s1
		// 		long mode; // $v1
		// 		struct _MonsterVars *mv; // $s3

			/* begin block 1.1.1 */
				// Start line: 713
				// Start offset: 0x80080374
			/* end block 1.1.1 */
			// End offset: 0x800803B4
			// End Line: 719
		/* end block 1.1 */
		// End offset: 0x800803B4
		// End Line: 720
	/* end block 1 */
	// End offset: 0x800803B8
	// End Line: 723

	/* begin block 2 */
		// Start line: 1454
	/* end block 2 */
	// End Line: 1455

	/* begin block 3 */
		// Start line: 1455
	/* end block 3 */
	// End Line: 1456

int MON_ShouldIAttackInstance(_Instance *instance,_Instance *ei)

{
  _Instance *p_Var1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  Intro *pIVar5;
  void *pvVar6;
  
  if (ei == gameTrackerX.playerInstance) {
    p_Var1 = (_Instance *)INSTANCE_Query(ei,0x22);
    uVar2 = INSTANCE_Query(ei,10);
    pvVar6 = instance->extraData;
    if ((uVar2 & 0x20010000) == 0) {
      if (((p_Var1 != (_Instance *)0x0) && (p_Var1 != instance)) && ((uVar2 & 0x2000000) != 0)) {
        return 0;
      }
      uVar2 = INSTANCE_Query(ei,0x2e);
      if (uVar2 == 0) {
        if (*(char *)((int)pvVar6 + 0x15a) != '\a') {
          return 1;
        }
        pIVar5 = instance->intro;
        if (pIVar5 == (Intro *)0x0) {
          return 1;
        }
        if ((instance->matrix != (MATRIX *)0x0) &&
           (lVar4 = MATH3D_LengthXYZ((int)(ei->position).x - (int)(pIVar5->position).x,
                                     (int)(ei->position).y - (int)(pIVar5->position).y,
                                     (int)(ei->position).z - (int)(pIVar5->position).z),
           (int)*(short *)((int)pvVar6 + 0x13c) + 0x280 < lVar4)) {
          return 0;
        }
        goto LAB_800803b4;
      }
    }
    iVar3 = 0;
  }
  else {
LAB_800803b4:
    iVar3 = 1;
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIAttack(struct _Instance *instance /*$s3*/, struct _MonsterIR *enemy /*$s1*/, struct _MonsterAttackAttributes *attack /*$s0*/)
 // line 731, offset 0x800803d4
	/* begin block 1 */
		// Start line: 732
		// Start offset: 0x800803D4
		// Variables:
	// 		struct _MonsterVars *mv; // $s4
	// 		int rv; // $a0
	// 		struct _Instance *ei; // $s2

		/* begin block 1.1 */
			// Start line: 751
			// Start offset: 0x80080440
			// Variables:
		// 		long distance; // $v1
		/* end block 1.1 */
		// End offset: 0x80080558
		// End Line: 803
	/* end block 1 */
	// End offset: 0x8008055C
	// End Line: 809

	/* begin block 2 */
		// Start line: 1527
	/* end block 2 */
	// End Line: 1528

int MON_ShouldIAttack(_Instance *instance,_MonsterIR *enemy,_MonsterAttackAttributes *attack)

{
  short angle;
  int iVar1;
  int iVar2;
  ulong uVar3;
  _Instance *ei;
  void *pvVar4;
  
  ei = enemy->instance;
  pvVar4 = instance->extraData;
  iVar1 = MON_ShouldIAttackInstance(instance,ei);
  iVar2 = 0;
  if ((iVar1 != 0) && (iVar2 = 0, attack != (_MonsterAttackAttributes *)0x0)) {
    if ((ei == gameTrackerX.playerInstance) &&
       (iVar1 = MON_CheckConditions(instance,enemy,attack->attackProbability), iVar1 == 0)) {
      return 0;
    }
    iVar1 = (int)attack->attackRange - (int)enemy->distance;
    if ((enemy->mirFlags & 8) == 0) {
      if (iVar1 < -0x96) {
        iVar2 = 5;
      }
      else {
        if (iVar1 < 0x97) {
          iVar1 = (int)(enemy->relativePosition).y;
          if (iVar1 < 1) {
            iVar2 = (int)(enemy->relativePosition).x;
            if (iVar2 < 0) {
              iVar2 = -iVar2;
            }
            if (iVar2 <= -iVar1) {
              if ((enemy->mirFlags & 0x20) == 0) {
                return 3;
              }
              iVar1 = *(int *)((int)pvVar4 + 0xcc);
              if ((iVar1 != 0) &&
                 (uVar3 = INSTANCE_Query(*(_Instance **)(iVar1 + 4),10), (uVar3 & 0x200000) != 0)) {
                return 7;
              }
              if ((*(uint *)((int)pvVar4 + 4) & 0x20000000) == 0) {
                angle = MATH3D_AngleFromPosToPos(&instance->position,&ei->position);
                iVar1 = MONSENSE_GetDistanceInDirection(instance,angle);
                if (iVar1 <= enemy->distance) {
                  return 0;
                }
              }
              enemy->mirConditions = 0;
              return 1;
            }
          }
          iVar2 = 6;
        }
        else {
          iVar2 = 4;
        }
      }
    }
    else {
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      iVar2 = 5;
      if (iVar1 < 1000) {
        iVar2 = 1;
      }
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// struct _MonsterAttackAttributes * /*$ra*/ MON_ChooseAttack(struct _Instance *instance /*$a0*/, struct _MonsterIR *enemy /*$a1*/)
 // line 818, offset 0x8008057c
	/* begin block 1 */
		// Start line: 820
		// Start offset: 0x8008057C
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
			// Start offset: 0x80080620
			// Variables:
		// 		struct _MonsterAttackAttributes *attack; // $a2
		// 		long delta; // $a0
		/* end block 1.1 */
		// End offset: 0x800806C0
		// End Line: 864
	/* end block 1 */
	// End offset: 0x800806CC
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
  iVar6 = (int)*(char *)(*(int *)(puVar8[0x5a] + 8) + 0x1d);
  pcVar7 = (char *)(*(int *)(puVar8[0x5a] + 8) + 0x2c);
  if (iVar6 != 0) {
    do {
      p_Var5 = (_MonsterAttackAttributes *)
               (*(int *)((int)instance->data + 0x38) + (int)*pcVar7 * 0x20);
      iVar2 = iVar9 - p_Var5->attackHeight;
      if (iVar2 < 0) {
        iVar2 = -iVar2;
      }
      if ((iVar2 < 100) || ((enemy->mirFlags & 8) != 0)) {
        iVar2 = (int)p_Var5->attackRange * (int)*(short *)(puVar8[0x5a] + 0x14);
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
  *(undefined *)((int)puVar8 + 0x15f) = 0;
  return p_Var12;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIEvade(struct _Instance *instance /*$s1*/)
 // line 878, offset 0x800806dc
	/* begin block 1 */
		// Start line: 879
		// Start offset: 0x800806DC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		int rv; // $s3

		/* begin block 1.1 */
			// Start line: 886
			// Start offset: 0x80080714
			// Variables:
		// 		struct _MonsterIR *enemy; // $s2
		/* end block 1.1 */
		// End offset: 0x80080768
		// End Line: 899
	/* end block 1 */
	// End offset: 0x80080768
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
  if ((*puVar3 & 0x40000000) == 0) {
    mir = (_MonsterIR *)puVar3[0x31];
    sVar1 = MON_FacingOffset(instance,mir->instance);
    if ((ushort)(sVar1 + 0x2a9U) < 0x553) {
      iVar2 = MON_CheckConditions(instance,mir,(char *)(*(int *)(puVar3[0x5a] + 8) + 0x20));
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
 // line 913, offset 0x80080788
	/* begin block 1 */
		// Start line: 914
		// Start offset: 0x80080788

		/* begin block 1.1 */
			// Start line: 923
			// Start offset: 0x800807C8
			// Variables:
		// 		int leftDist; // $s0
		// 		int rightDist; // $v1
		/* end block 1.1 */
		// End offset: 0x8008081C
		// End Line: 932
	/* end block 1 */
	// End offset: 0x8008081C
	// End Line: 933

	/* begin block 2 */
		// Start line: 1940
	/* end block 2 */
	// End Line: 1941

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
// int /*$ra*/ MON_ChooseEvadeMove(struct _Instance *instance /*$a0*/)
 // line 935, offset 0x8008082c
	/* begin block 1 */
		// Start line: 936
		// Start offset: 0x8008082C
		// Variables:
	// 		int anim; // $v0
	// 		struct _MonsterVars *mv; // $v0
	// 		int leftOrRight; // $v1
	/* end block 1 */
	// End offset: 0x80080878
	// End Line: 964

	/* begin block 2 */
		// Start line: 1989
	/* end block 2 */
	// End Line: 1990

int MON_ChooseEvadeMove(_Instance *instance)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = MON_ChooseLeftOrRight(instance,*(_MonsterIR **)((int)instance->extraData + 0xc4));
  if (iVar1 == 0) {
    uVar2 = rand();
    iVar1 = -1;
    if ((uVar2 & 1) != 0) {
      iVar1 = 1;
    }
  }
  iVar3 = 0x29;
  if (iVar1 < 0) {
    iVar3 = 0x28;
  }
  return iVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ChooseCombatMove(struct _Instance *instance /*$s2*/, int reason /*$a1*/)
 // line 969, offset 0x80080888
	/* begin block 1 */
		// Start line: 970
		// Start offset: 0x80080888
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
			// Start offset: 0x8008093C

			/* begin block 1.1.1 */
				// Start line: 1036
				// Start offset: 0x8008095C
				// Variables:
			// 		int dir; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800809A4
			// End Line: 1045
		/* end block 1.1 */
		// End offset: 0x800809BC
		// End Line: 1068

		/* begin block 1.2 */
			// Start line: 1072
			// Start offset: 0x800809C4
			// Variables:
		// 		short zrot; // $s0

			/* begin block 1.2.1 */
				// Start line: 1108
				// Start offset: 0x80080AB4
				// Variables:
			// 		struct _Position temp; // stack offset -56
			// 		struct SVECTOR New; // stack offset -48
			// 		struct VECTOR OutTrans; // stack offset -40
			/* end block 1.2.1 */
			// End offset: 0x80080BD4
			// End Line: 1148
		/* end block 1.2 */
		// End offset: 0x80080CAC
		// End Line: 1173
	/* end block 1 */
	// End offset: 0x80080CAC
	// End Line: 1177

	/* begin block 2 */
		// Start line: 2057
	/* end block 2 */
	// End Line: 2058

int MON_ChooseCombatMove(_Instance *instance,int reason)

{
  short angle;
  long lVar1;
  ushort uVar2;
  int Data;
  Intro *pIVar3;
  uint xOffset;
  uint yOffset;
  _MonsterIR *enemy;
  char cVar4;
  uint uVar5;
  void *pvVar6;
  int *piVar7;
  undefined2 local_30;
  short local_2e;
  undefined2 local_2c;
  short local_28 [2];
  short local_24;
  short local_20;
  
  pvVar6 = instance->extraData;
  enemy = *(_MonsterIR **)((int)pvVar6 + 0xc4);
  Data = *(int *)((int)pvVar6 + 0xcc);
  piVar7 = *(int **)((int)pvVar6 + 0x168);
  if ((Data == 0) || (699 < *(short *)(Data + 0x14))) {
    if (reason == 4) {
LAB_80080934:
      cVar4 = '\a';
    }
    else {
      cVar4 = '\x06';
      if (reason != 5) {
        Data = (int)(enemy->relativePosition).y;
        if (Data < 0) {
          Data = -Data;
        }
        if (Data < *(short *)(piVar7[2] + 0x14)) {
          if ((enemy->relativePosition).y < 0) goto LAB_80080934;
        }
        else {
          angle = MON_FacingOffset(instance,enemy->instance);
          if ((ushort)(angle + 0x2a9U) < 0x553) {
            Data = MON_ChooseLeftOrRight(instance,enemy);
            cVar4 = '\b';
            if ((-1 < Data) && (cVar4 = '\t', Data < 1)) {
              uVar5 = rand();
              if ((uVar5 & 3) == 0) {
                cVar4 = '\b';
                uVar5 = rand();
                if ((uVar5 & 1) != 0) {
                  cVar4 = '\t';
                }
              }
              else {
                cVar4 = *(char *)((int)pvVar6 + 0x164);
              }
            }
          }
          else {
            cVar4 = '\0';
          }
          if (cVar4 == '\0') {
            return 0;
          }
        }
      }
    }
  }
  else {
    cVar4 = '\b';
    if (0 < *(short *)(Data + 0xc)) {
      cVar4 = '\t';
    }
  }
  if (cVar4 == '\0') {
    return 0;
  }
  angle = (instance->rotation).z;
  if (cVar4 == '\b') {
    angle = angle + 0x400;
  }
  else {
    if (cVar4 < '\t') {
      if (cVar4 == '\a') {
        angle = angle + 0x800;
      }
    }
    else {
      if (cVar4 == '\t') {
        angle = angle + -0x400;
      }
    }
  }
  MONSENSE_AdjustRadarFromObjects(instance);
  angle = MONSENSE_GetClosestFreeDirection(instance,angle,0x2ee);
  uVar2 = (angle - (instance->rotation).z) + 0x200U & 0xfff;
  uVar5 = 6;
  if (((0x3ff < uVar2) && (uVar5 = 8, 0x7ff < uVar2)) && (uVar5 = 9, uVar2 < 0xc00)) {
    uVar5 = 7;
  }
  Data = *(int *)((int)instance->data + 0x40) + (int)*(char *)(*piVar7 + uVar5) * 0x10;
  if (((*(char *)((int)pvVar6 + 0x15a) == '\a') && (instance->intro != (Intro *)0x0)) &&
     (instance->matrix != (MATRIX *)0x0)) {
    local_30 = 0;
    local_2c = 0;
    if (uVar5 - 7 < 2) {
      local_2e = *(short *)(Data + 2);
    }
    else {
      local_2e = -*(short *)(Data + 2);
    }
    ApplyMatrix(instance->matrix,&local_30,local_28);
    pIVar3 = instance->intro;
    lVar1 = MATH3D_LengthXYZ((int)(short)((instance->position).x + local_28[0]) -
                             (int)(pIVar3->position).x,
                             (int)(short)((instance->position).y + local_24) -
                             (int)(pIVar3->position).y,
                             (int)(short)((instance->position).z + local_20) -
                             (int)(pIVar3->position).z);
    if ((int)*(short *)((int)pvVar6 + 0x13c) + 0x140 < lVar1) {
      angle = MATH3D_AngleFromPosToPos(&instance->position,&instance->intro->position);
      uVar2 = angle - (instance->rotation).z & 0xfff;
      uVar5 = 6;
      if (((0x3ff < uVar2) && (uVar5 = 8, 0x7ff < uVar2)) && (uVar5 = 9, uVar2 < 0xc00)) {
        uVar5 = 7;
      }
      Data = *(int *)((int)instance->data + 0x40) + (int)*(char *)(*piVar7 + uVar5) * 0x10;
    }
  }
  if (uVar5 == 8) {
    yOffset = 0;
    xOffset = (uint)*(ushort *)(Data + 2);
  }
  else {
    if (uVar5 < 9) {
      xOffset = 0;
      if (uVar5 == 7) {
        yOffset = (uint)*(ushort *)(Data + 2);
        goto LAB_80080c74;
      }
    }
    else {
      yOffset = 0;
      if (uVar5 == 9) {
        xOffset = -(uint)*(ushort *)(Data + 2);
        goto LAB_80080c74;
      }
    }
    xOffset = 0;
    yOffset = -(uint)*(ushort *)(Data + 2);
  }
LAB_80080c74:
  Data = SetPhysicsDropOffData(xOffset,yOffset,200,0x800,400);
  Data = PhysicsCheckDropOff(instance,Data,4);
  if (Data == 0) {
    if (uVar5 - 8 < 2) {
      *(undefined *)((int)pvVar6 + 0x164) = (char)uVar5;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_PlayRandomIdle(struct _Instance *instance /*$s4*/, int mode /*$s5*/)
 // line 1185, offset 0x80080cd0
	/* begin block 1 */
		// Start line: 1186
		// Start offset: 0x80080CD0
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct _MonsterAttributes *ma; // $s2
	// 		struct _MonsterBehavior *behavior; // $s0
	// 		struct _MonsterIdle *idle; // $s1
	// 		int chance; // $a2
	// 		int i; // $a0
	// 		char *idleIndex; // $a1
	/* end block 1 */
	// End offset: 0x80080E50
	// End Line: 1244

	/* begin block 2 */
		// Start line: 2527
	/* end block 2 */
	// End Line: 2528

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
    if (*(int *)(puVar8[0x5a] + 0x10) != 0) {
      iVar3 = (int)*(char *)(*(int *)(puVar8[0x5a] + 0x10) + (uint)*(byte *)((int)puVar8 + 0x15a));
    }
    if (iVar3 == -1) {
      puVar5 = *(undefined **)((int)pvVar7 + 0x48);
    }
    else {
      puVar5 = (undefined *)(*(int *)((int)pvVar7 + 0x48) + iVar3 * 8);
    }
    if (*(char *)((int)puVar8 + 0x15a) != '\0') {
      iVar3 = (int)(char)puVar5[2];
      pcVar4 = puVar5 + 3;
      while ((iVar3 != 0 && (-1 < (int)*pcVar4))) {
        pcVar6 = (char *)(*(int *)((int)pvVar7 + 0x44) + (int)*pcVar4 * 4);
        iVar3 = iVar3 + -1;
        if (iVar2 < pcVar6[2]) break;
        iVar2 = iVar2 - pcVar6[2];
        pcVar4 = pcVar4 + 1;
      }
      goto LAB_80080e30;
    }
    cVar1 = puVar5[(uint)*(byte *)(puVar8 + 0x58) + 3];
  }
  else {
    puVar5 = *(undefined **)((int)pvVar7 + 0x48);
    cVar1 = puVar5[3];
  }
  pcVar6 = (char *)(*(int *)((int)pvVar7 + 0x44) + (int)cVar1 * 4);
LAB_80080e30:
  if (pcVar6 != (char *)0x0) {
    MON_PlayAnimIDIfNotPlaying(instance,(int)*pcVar6,mode);
    *(undefined *)((int)puVar8 + 0x161) = *puVar5;
  }
  return;
}



// autogenerated function stub: 
// void /*$ra*/ MON_PlayCombatIdle(struct _Instance *instance /*$a0*/, int mode /*$a2*/)
void MON_PlayCombatIdle(struct _Instance *instance, int mode)
{ // line 1249, offset 0x80080e74
	/* begin block 1 */
		// Start line: 1250
		// Start offset: 0x80080E74
		// Variables:
			int anim; // $a1
	/* end block 1 */
	// End offset: 0x80080E9C
	// End Line: 1258

	/* begin block 2 */
		// Start line: 2664
	/* end block 2 */
	// End Line: 2665

}


// decompiled code
// original method signature: 
// void /*$ra*/ MON_GetRandomPoint(struct _Position *out /*$s2*/, struct _Position *in /*$s1*/, short r /*$a2*/)
 // line 1290, offset 0x80080eb4
	/* begin block 1 */
		// Start line: 1291
		// Start offset: 0x80080EB4
		// Variables:
	// 		int ang; // $s0
	/* end block 1 */
	// End offset: 0x80080EB4
	// End Line: 1291

	/* begin block 2 */
		// Start line: 2580
	/* end block 2 */
	// End Line: 2581

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
// int /*$ra*/ MON_GetRandomDestinationInWorld(struct _Instance *instance /*$s2*/, struct _Position *in /*$s0*/, short r /*$s4*/)
 // line 1307, offset 0x80080f60
	/* begin block 1 */
		// Start line: 1308
		// Start offset: 0x80080F60

		/* begin block 1.1 */
			// Start line: 1311
			// Start offset: 0x80080F94
			// Variables:
		// 		struct _MonsterVars *mv; // $s1
		// 		struct evPhysicsLOSData data; // stack offset -48
		// 		int result; // $s0
		// 		int avoidEnemy; // $s3

			/* begin block 1.1.1 */
				// Start line: 1322
				// Start offset: 0x80080FD0
			/* end block 1.1.1 */
			// End offset: 0x80081020
			// End Line: 1328

			/* begin block 1.1.2 */
				// Start line: 1342
				// Start offset: 0x8008109C
			/* end block 1.1.2 */
			// End offset: 0x800810EC
			// End Line: 1348
		/* end block 1.1 */
		// End offset: 0x80081124
		// End Line: 1357
	/* end block 1 */
	// End offset: 0x80081128
	// End Line: 1360

	/* begin block 2 */
		// Start line: 2752
	/* end block 2 */
	// End Line: 2753

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
  if ((uint)*(byte *)((int)puVar5 + 0x15a) - 9 < 2) {
    bVar1 = puVar5[0x31] != 0;
  }
  if (in != (_Position *)0x0) {
    if (!bVar1) goto LAB_80081020;
    iVar2 = *(int *)(puVar5[0x31] + 4);
    lVar3 = MATH3D_LengthXYZ((int)in->x - (int)*(short *)(iVar2 + 0x5c),
                             (int)in->y - (int)*(short *)(iVar2 + 0x5e),
                             (int)in->z - (int)*(short *)(iVar2 + 0x60));
    if (*(short *)(puVar5[0x5a] + 0x1a) <= lVar3) goto LAB_80081020;
  }
  in = &instance->position;
LAB_80081020:
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
      if (lVar3 < *(short *)(puVar5[0x5a] + 0x1a)) {
        iVar2 = 0;
      }
    }
    if (iVar2 != 0) {
      *puVar5 = *puVar5 | 0x40000;
      puVar5[0x49] = local_30;
      *(short *)(puVar5 + 0x4a) = local_2c;
    }
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MoveForward(struct _Instance *instance /*$s0*/)
 // line 1453, offset 0x80081148
	/* begin block 1 */
		// Start line: 1454
		// Start offset: 0x80081148
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	/* end block 1 */
	// End offset: 0x80081148
	// End Line: 1454

	/* begin block 2 */
		// Start line: 2906
	/* end block 2 */
	// End Line: 2907

void MON_MoveForward(_Instance *instance)

{
  PhysicsSetVelFromRot
            (instance,&instance->rotation,(int)*(short *)((int)instance->extraData + 0x12a));
  instance->xAccl = 0;
  instance->yAccl = 0;
  instance->zAccl = 0;
  PhysicsMove(instance,&instance->position,gameTrackerX.timeMult);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_TurnToPosition(struct _Instance *instance /*$s1*/, struct _Position *position /*$a1*/, short turnspeed /*$a2*/)
 // line 1468, offset 0x80081198
	/* begin block 1 */
		// Start line: 1469
		// Start offset: 0x80081198
	/* end block 1 */
	// End offset: 0x80081198
	// End Line: 1469

	/* begin block 2 */
		// Start line: 2989
	/* end block 2 */
	// End Line: 2990

int MON_TurnToPosition(_Instance *instance,_Position *position,short turnspeed)

{
  short destination;
  
  destination = MATH3D_AngleFromPosToPos(&instance->position,position);
  AngleMoveToward(&(instance->rotation).z,destination,
                  (short)((int)turnspeed * gameTrackerX.timeMult * 0x10 >> 0x10));
  return (uint)((instance->rotation).z == destination);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_MoveToPosition(struct _Instance *instance /*$s0*/, struct _Position *position /*$a1*/, short turnSpeed /*$a2*/)
 // line 1485, offset 0x80081208
	/* begin block 1 */
		// Start line: 3029
	/* end block 1 */
	// End Line: 3030

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
 // line 1504, offset 0x8008124c
	/* begin block 1 */
		// Start line: 1505
		// Start offset: 0x8008124C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		struct evPhysicsGravityData data; // stack offset -32
	// 		int minUpper; // $v1
	// 		long xyDist; // $a1
	/* end block 1 */
	// End offset: 0x800812DC
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
  if ((*puVar4 & 2) != 0) {
    iVar2 = 100;
  }
  if (iVar3 * 0x10000 >> 0x10 < iVar2) {
    local_20 = (short)iVar2;
  }
  if (local_1e < 100) {
    local_1e = 100;
  }
  local_20 = local_20 + *(short *)(puVar4[0x5a] + 0x4e);
  local_16 = 0xc80;
  local_1e = local_1e + *(short *)(puVar4[0x5a] + 0x50);
  iVar2 = PhysicsCheckGravity(instance,(int)&local_20,(ushort)((*puVar4 & 0x800) == 0) << 2);
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ApplyPhysics(struct _Instance *instance /*$a0*/)
 // line 1549, offset 0x8008133c
	/* begin block 1 */
		// Start line: 3188
	/* end block 1 */
	// End Line: 3189

void MON_ApplyPhysics(_Instance *instance)

{
  PhysicsMove(instance,&instance->position,gameTrackerX.timeMult);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ChangeBehavior(struct _Instance *instance /*$a0*/, int behavior /*$s0*/)
 // line 1559, offset 0x80081360
	/* begin block 1 */
		// Start line: 1560
		// Start offset: 0x80081360

		/* begin block 1.1 */
			// Start line: 1563
			// Start offset: 0x8008137C
			// Variables:
		// 		struct _MonsterVars *mv; // $s1
		// 		enum MonsterState state; // $a1
		/* end block 1.1 */
		// End offset: 0x800813D4
		// End Line: 1590
	/* end block 1 */
	// End offset: 0x800813D4
	// End Line: 1591

	/* begin block 2 */
		// Start line: 3209
	/* end block 2 */
	// End Line: 3210

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
    *(undefined *)((int)pvVar1 + 0x15a) = (char)behavior;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CheckEnvironment(struct _Instance *instance /*$s1*/)
 // line 1596, offset 0x800813e8
	/* begin block 1 */
		// Start line: 1597
		// Start offset: 0x800813E8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s4
	// 		int inwater; // $v0
	// 		struct _SVector Hack; // stack offset -40

		/* begin block 1.1 */
			// Start line: 1637
			// Start offset: 0x8008151C
			// Variables:
		// 		int moveback; // $s2
		// 		int onground; // $s3

			/* begin block 1.1.1 */
				// Start line: 1664
				// Start offset: 0x800815C8
				// Variables:
			// 		int offset; // $a1
			// 		int result; // $v0
			// 		struct _Position pos; // stack offset -32
			/* end block 1.1.1 */
			// End offset: 0x80081670
			// End Line: 1684

			/* begin block 1.1.2 */
				// Start line: 1696
				// Start offset: 0x800816AC
				// Variables:
			// 		int result; // $v0
			// 		int offset; // $a1
			/* end block 1.1.2 */
			// End offset: 0x8008170C
			// End Line: 1712

			/* begin block 1.1.3 */
				// Start line: 1719
				// Start offset: 0x80081714
				// Variables:
			// 		int result; // $v1
			/* end block 1.1.3 */
			// End offset: 0x80081778
			// End Line: 1748
		/* end block 1.1 */
		// End offset: 0x800817E0
		// End Line: 1761
	/* end block 1 */
	// End offset: 0x80081804
	// End Line: 1766

	/* begin block 2 */
		// Start line: 3284
	/* end block 2 */
	// End Line: 3285

void MON_CheckEnvironment(_Instance *instance)

{
  short sVar1;
  bool bVar2;
  int Data;
  uint uVar3;
  uint dropOffset;
  uint *puVar4;
  void *pvVar5;
  _SVector local_28;
  _Position local_20;
  
  puVar4 = (uint *)instance->extraData;
  pvVar5 = instance->data;
  if (instance->currentMainState != 0x1d) {
    local_28.z = 0;
    local_28.y = 0;
    local_28.x = 0;
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
    if ((*(uint *)((int)pvVar5 + 0x10) & 4) == 0) {
      Data = SetPhysicsSwimData(0,&local_28,0x100,0xa0,0x40);
      uVar3 = PhysicsCheckSwim(instance,Data,1);
      uVar3 = uVar3 & 0x20;
    }
    else {
      uVar3 = 0x20;
    }
    if (uVar3 == 0) {
      if ((*puVar4 & 0x400) == 0) {
        *puVar4 = *puVar4 & 0xffbfffff | 0x400;
        instance->maxXVel = 0x14;
        instance->maxYVel = 0x14;
        instance->maxZVel = 0x14;
        instance->xVel = 0;
        instance->yVel = 0;
        SOUND_Play3dSound(&instance->position,1,-200,0x78,(int)&DAT_00002710);
        instance->flags2 = instance->flags2 & 0xffffffbf;
      }
      if ((*(ushort *)((int)puVar4 + 0x152) & 0x10) != 0) {
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
              Data = (int)*(short *)(puVar4[0x5a] + 0x16);
            }
            Data = SetPhysicsDropHeightData(&instance->position,Data,0x40);
            uVar3 = PhysicsCheckDropHeight(instance,Data,1);
            if (((uVar3 & *(ushort *)((int)puVar4 + 0x152)) != 0) || (uVar3 == 0)) {
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
              dropOffset = SEXT24(*(short *)(puVar4[0x5a] + 0x16));
            }
            Data = SetPhysicsDropHeightData(&local_20,dropOffset,0x60);
            dropOffset = PhysicsCheckDropHeight(instance,Data,1);
            if (((dropOffset & *(ushort *)((int)puVar4 + 0x152)) != 0) || (dropOffset == 0)) {
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
          if ((uVar3 != 0) && ((uVar3 & *(ushort *)((int)puVar4 + 0x152)) == 0)) {
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
                            (*(int *)(*(int *)instance->tfaceLevel + 0x48) +
                            instance->bspTree * 0x24),instance->tface);
      }
    }
    uVar3 = *(uint *)((int)pvVar5 + 0x10);
    if ((uVar3 != 0x10082) && ((uVar3 & 4) == 0)) {
      FX_UpdateInstanceWaterSplit(instance);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_CheckTerrainAndRespond(struct _Instance *instance /*$s1*/, struct BSPTree *bsp /*$a1*/, struct _TFace *tface /*$a2*/)
 // line 1768, offset 0x80081824
	/* begin block 1 */
		// Start line: 1769
		// Start offset: 0x80081824
		// Variables:
	// 		unsigned long results; // $s0
	/* end block 1 */
	// End offset: 0x80081894
	// End Line: 1780

	/* begin block 2 */
		// Start line: 3643
	/* end block 2 */
	// End Line: 3644

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
 // line 1785, offset 0x800818a8
	/* begin block 1 */
		// Start line: 1786
		// Start offset: 0x800818A8
		// Variables:
	// 		unsigned long rv; // $s0

		/* begin block 1.1 */
			// Start line: 1792
			// Start offset: 0x800818CC
			// Variables:
		// 		struct Level *level; // $v1
		/* end block 1.1 */
		// End offset: 0x8008194C
		// End Line: 1812
	/* end block 1 */
	// End offset: 0x8008194C
	// End Line: 1814

	/* begin block 2 */
		// Start line: 3677
	/* end block 2 */
	// End Line: 3678

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
 // line 1823, offset 0x80081968
	/* begin block 1 */
		// Start line: 1824
		// Start offset: 0x80081968
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		int rc; // $s3
	// 		int result; // $a0
	// 		struct evPhysicsDropHeightData *data; // $s0
	/* end block 1 */
	// End offset: 0x80081A1C
	// End Line: 1850

	/* begin block 2 */
		// Start line: 3759
	/* end block 2 */
	// End Line: 3760

int MON_CheckPointSuitability(_Instance *instance,_Position *origin,_Position *destination)

{
  int Data;
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  Data = SetPhysicsDropHeightData(destination,(int)*(short *)(puVar3[0x5a] + 0x16),0x40);
  uVar1 = PhysicsCheckDropHeight(instance,Data,1);
  if (uVar1 == 1) {
    uVar2 = MON_CheckTerrain(instance,*(BSPTree **)(Data + 0xc),*(_TFace **)(Data + 0x10));
    uVar1 = uVar2 | 1;
    destination->z = *(short *)(Data + 4);
  }
  Data = 0;
  if (((uVar1 & *(ushort *)((int)puVar3 + 0x152)) == 0) &&
     (((*puVar3 & 0x800) != 0 || (Data = 0, uVar1 != 0)))) {
    Data = 1;
  }
  return Data;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ MON_GetTime(struct _Instance *instance /*$a0*/)
 // line 1925, offset 0x80081a40
	/* begin block 1 */
		// Start line: 3850
	/* end block 1 */
	// End Line: 3851

	/* begin block 2 */
		// Start line: 3894
	/* end block 2 */
	// End Line: 3895

ulong MON_GetTime(_Instance *instance)

{
  if ((instance->object->oflags & 0x80000U) != 0) {
    return gameTrackerX.currentTime;
  }
  if ((instance->flags2 & 0x8000000U) == 0) {
    return gameTrackerX.currentMaterialTime;
  }
  return gameTrackerX.currentSpectralTime;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BirthSoul(struct _Instance *instance /*$s1*/, int link /*$s3*/)
 // line 1943, offset 0x80081a94
	/* begin block 1 */
		// Start line: 1944
		// Start offset: 0x80081A94
		// Variables:
	// 		struct _MonsterVars *mv; // $s2

		/* begin block 1.1 */
			// Start line: 1951
			// Start offset: 0x80081AE0
			// Variables:
		// 		struct Object *soulob; // $a1

			/* begin block 1.1.1 */
				// Start line: 1958
				// Start offset: 0x80081AF4
				// Variables:
			// 		struct _Instance *isoul; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 1979
					// Start offset: 0x80081B58
					// Variables:
				// 		struct MATRIX *matrix; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x80081B7C
				// End Line: 1983
			/* end block 1.1.1 */
			// End offset: 0x80081B84
			// End Line: 1989
		/* end block 1.1 */
		// End offset: 0x80081B84
		// End Line: 1992

		/* begin block 1.2 */
			// Start line: 1995
			// Start offset: 0x80081B8C
			// Variables:
		// 		struct _Instance *isoul; // $a0
		/* end block 1.2 */
		// End offset: 0x80081BDC
		// End Line: 2009
	/* end block 1 */
	// End offset: 0x80081BDC
	// End Line: 2011

	/* begin block 2 */
		// Start line: 3921
	/* end block 2 */
	// End Line: 3922

	/* begin block 3 */
		// Start line: 3929
	/* end block 3 */
	// End Line: 3930

/* WARNING: Removing unreachable block (ram,0x80081af4) */
/* WARNING: Removing unreachable block (ram,0x80081b08) */
/* WARNING: Removing unreachable block (ram,0x80081b1c) */
/* WARNING: Removing unreachable block (ram,0x80081b30) */
/* WARNING: Removing unreachable block (ram,0x80081b44) */
/* WARNING: Removing unreachable block (ram,0x80081b38) */
/* WARNING: Removing unreachable block (ram,0x80081b48) */
/* WARNING: Removing unreachable block (ram,0x80081b58) */
/* WARNING: Removing unreachable block (ram,0x80081b7c) */

void MON_BirthSoul(_Instance *instance,int link)

{
  _Instance *p_Var1;
  int introUniqueID;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  if (*(short *)((int)pvVar2 + 0x148) != 0) {
    introUniqueID = *(int *)((int)pvVar2 + 0xd8);
    if ((introUniqueID != 0) && (introUniqueID < 0x2000)) {
      p_Var1 = INSTANCE_Find(introUniqueID);
      if (p_Var1 == (_Instance *)0x0) {
        instance->flags2 = instance->flags2 | 0x80;
      }
      else {
        instance->flags2 = instance->flags2 & 0xffffff7f;
        *(long *)((int)pvVar2 + 0xd8) = p_Var1->introUniqueID;
        *(long *)((int)p_Var1->extraData + 0xd8) = instance->introUniqueID;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ProcessIntro(struct _Instance *instance /*$s2*/)
 // line 2017, offset 0x80081bf8
	/* begin block 1 */
		// Start line: 2018
		// Start offset: 0x80081BF8
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
			// Start line: 2038
			// Start offset: 0x80081C9C
			// Variables:
		// 		struct INICommand *command; // $a2

			/* begin block 1.1.1 */
				// Start line: 2092
				// Start offset: 0x80081F10
				// Variables:
			// 		short *pmarker; // $a0
			// 		int i; // $a1
			// 		long *param; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80081F38
			// End Line: 2107

			/* begin block 1.1.2 */
				// Start line: 2116
				// Start offset: 0x80081F60
				// Variables:
			// 		int i; // $a0
			// 		short *unit; // $a1
			/* end block 1.1.2 */
			// End offset: 0x80081F98
			// End Line: 2126
		/* end block 1.1 */
		// End offset: 0x80082010
		// End Line: 2156
	/* end block 1 */
	// End offset: 0x800820F4
	// End Line: 2197

	/* begin block 2 */
		// Start line: 4080
	/* end block 2 */
	// End Line: 4081

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
  *(undefined2 *)(puVar10 + 0x50) = 0x800;
  *(undefined2 *)((int)puVar10 + 0x142) = 0x400;
  iVar13 = -1;
  *(undefined *)((int)puVar10 + 0x15e) = uVar1;
  puVar10[1] = puVar10[1] | 0x80000000;
  psVar8 = (short *)instance->introData;
  uVar11 = 0;
  if ((psVar8 != (short *)0x0) && ((instance->flags & 2U) == 0)) {
    sVar2 = *psVar8;
    sVar3 = *psVar8;
    while (sVar2 != 0) {
      if (sVar3 == 0xc) {
        *(undefined *)((int)puVar10 + 0x156) = *(undefined *)(psVar8 + 2);
      }
      else {
        if (sVar3 < 0xd) {
          if (sVar3 == 6) {
            *(undefined *)((int)puVar10 + 0x15e) = *(undefined *)(psVar8 + 2);
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
                instance->flags2 = instance->flags2 | 0x20000;
                uVar11 = uVar11 | 0x1000000;
                if (psVar8[1] == 0) {
                  *(undefined2 *)((int)puVar10 + 0x14a) = 0;
                }
                else {
                  *(short *)((int)puVar10 + 0x14a) = psVar8[2];
                }
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
                    puVar7 = puVar10 + 0x62;
                    psVar5 = psVar8;
                    while (iVar6 != 0) {
                      psVar5 = psVar5 + 2;
                      iVar6 = iVar6 + -1;
                      *(short *)puVar7 = *psVar5;
                      puVar7 = (uint *)((int)puVar7 + 2);
                    }
                    *(short *)puVar7 = 0;
                    *(uint **)(puVar10 + 0x68) = puVar10 + 0x62;
                  }
                  else {
                    if (sVar3 == 0xb) {
                      *(undefined *)(puVar10 + 0x58) = *(undefined *)(psVar8 + 2);
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
                    *(short *)(puVar10 + 0x4e) = psVar8[2];
                  }
                  else {
                    puVar7 = puVar10 + 0x5d;
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
                    *(undefined *)(puVar10 + 0x56) = *(undefined *)(psVar8 + 2);
                    if (puVar10[0x36] == 0) {
                      puVar10[0x36] = 0x7fffffff;
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
                *(short *)((int)puVar10 + 0x142) =
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
                      *(short *)(puVar10 + 0x50) =
                           (short)((ulonglong)
                                   ((longlong)(*(int *)(psVar8 + 2) * 0x1000) * 0xb60b60b7) >> 0x28)
                           - (short)(*(int *)(psVar8 + 2) * 0x1000 >> 0x1f);
                    }
                  }
                }
                else {
                  if (sVar3 == 0x19) {
                    *(undefined *)((int)puVar10 + 0x157) = *(undefined *)(psVar8 + 2);
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
    *(undefined *)((int)puVar10 + 0x15b) = (char)iVar12;
    *(undefined *)((int)puVar10 + 0x15a) = (char)iVar12;
  }
  if (iVar14 != -1) {
    *(char *)(puVar10 + 0x57) = (char)iVar14;
  }
  if (iVar15 != -1) {
    *(undefined *)((int)puVar10 + 0x15d) = (char)iVar15;
  }
  if (iVar13 != -1) {
    *(short *)(puVar10 + 0x51) = (short)(iVar13 << 8);
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
    *(short *)(puVar10 + 0x4f) = (short)iVar16;
  }
  if (iVar17 != 0) {
    *(undefined2 *)((int)puVar10 + 0x13a) = (short)iVar17;
  }
  if (iVar9 != 0) {
    *(undefined2 *)((int)puVar10 + 0x13e) = (short)iVar9;
  }
  if (((*(char *)(puVar10 + 0x57) == '\b') && (*(char *)((int)puVar10 + 0x15b) != '\x04')) &&
     (*(char *)((int)puVar10 + 0x15b) != '\x10')) {
    *(undefined *)((int)puVar10 + 0x15b) = 4;
    *(undefined *)((int)puVar10 + 0x15a) = 4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SetDefaults(struct _Instance *instance /*$a0*/)
 // line 2202, offset 0x80082124
	/* begin block 1 */
		// Start line: 2204
		// Start offset: 0x80082124
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	// 		struct _MonsterAttributes *ma; // $a3
	// 		struct _MonsterSubAttributes *subAttr; // $a2
	/* end block 1 */
	// End offset: 0x8008231C
	// End Line: 2260

	/* begin block 2 */
		// Start line: 4618
	/* end block 2 */
	// End Line: 4619

	/* begin block 3 */
		// Start line: 4619
	/* end block 3 */
	// End Line: 4620

void MON_SetDefaults(_Instance *instance)

{
  short sVar1;
  undefined2 uVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  
  puVar3 = (uint *)instance->extraData;
  pvVar5 = instance->data;
  if ((int)*(char *)((int)pvVar5 + 0x28) <= (int)(uint)*(byte *)((int)puVar3 + 0x15e)) {
    *(char *)((int)puVar3 + 0x15e) = *(char *)((int)pvVar5 + 0x28) + -1;
  }
  uVar4 = *(uint *)((uint)*(byte *)((int)puVar3 + 0x15e) * 4 + *(int *)((int)pvVar5 + 0x30));
  puVar3[0x5a] = uVar4;
  instance->currentModel = (ushort)*(byte *)(uVar4 + 0x26);
  sVar1 = *(short *)(uVar4 + 0x14);
  (instance->scale).z = sVar1;
  (instance->scale).y = sVar1;
  (instance->scale).x = sVar1;
  *(undefined *)((int)puVar3 + 0x15a) = *(undefined *)(uVar4 + 0x34);
  *(undefined *)((int)puVar3 + 0x15b) = *(undefined *)(uVar4 + 0x34);
  *(undefined *)(puVar3 + 0x57) = *(undefined *)(uVar4 + 0x35);
  *(undefined2 *)((int)puVar3 + 0x13a) = *(undefined2 *)(uVar4 + 0x30);
  *(undefined2 *)(puVar3 + 0x4f) = *(undefined2 *)(uVar4 + 0x32);
  uVar2 = *(undefined2 *)(uVar4 + 0x18);
  *(undefined2 *)(puVar3 + 0x52) = 0x1000;
  *(undefined *)((int)puVar3 + 0x161) = 3;
  *(undefined *)(puVar3 + 0x59) = 8;
  *(undefined2 *)((int)puVar3 + 0x13e) = uVar2;
  if ((*(int *)(uVar4 + 8) != 0) &&
     (*(short *)(puVar3 + 0x51) = (short)((int)*(char *)(*(int *)(uVar4 + 8) + 0x1c) << 8),
     *(char *)(*(int *)(uVar4 + 8) + 0x1e) != -1)) {
    *puVar3 = *puVar3 | 0x20;
  }
  if ((*(char *)((int)puVar3 + 0x15e) == '\x02') && ((*(uint *)((int)pvVar5 + 0x10) & 2) != 0)) {
    *puVar3 = *puVar3 | 0x10000000;
  }
  if (*(char *)(uVar4 + 0x37) != '\0') {
    instance->flags2 = instance->flags2 | 0x8000000;
  }
  *(undefined2 *)((int)puVar3 + 0x152) = 0x100;
  if (*(char *)(uVar4 + 0x3a) != '\0') {
    *(undefined2 *)((int)puVar3 + 0x152) = 0x110;
  }
  if (*(char *)(uVar4 + 0x39) != '\0') {
    *(ushort *)((int)puVar3 + 0x152) = *(ushort *)((int)puVar3 + 0x152) | 0x20;
  }
  if (*(char *)(uVar4 + 0x38) != '\0') {
    *(ushort *)((int)puVar3 + 0x152) = *(ushort *)((int)puVar3 + 0x152) | 0x40;
  }
  if (*(char *)(uVar4 + 0x3c) != '\0') {
    *(ushort *)((int)puVar3 + 0x152) = *(ushort *)((int)puVar3 + 0x152) | 0x200;
  }
  if (*(char *)(uVar4 + 0x3b) != '\0') {
    *(ushort *)((int)puVar3 + 0x152) = *(ushort *)((int)puVar3 + 0x152) | 0x80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GetPlanSlot(struct _MonsterVars *mv /*$s0*/)
 // line 2265, offset 0x80082324
	/* begin block 1 */
		// Start line: 4747
	/* end block 1 */
	// End Line: 4748

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
 // line 2276, offset 0x80082368
	/* begin block 1 */
		// Start line: 2277
		// Start offset: 0x80082368
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		int rc; // $s1
	// 		int felloff; // $v1
	// 		long length; // $s3
	// 		struct _MonsterAnim *manim; // $s6

		/* begin block 1.1 */
			// Start line: 2306
			// Start offset: 0x8008245C
			// Variables:
		// 		struct _Position pos; // stack offset -40
		// 		int planresult; // $v1

			/* begin block 1.1.1 */
				// Start line: 2347
				// Start offset: 0x80082514
				// Variables:
			// 		short turnSpeed; // $a2
			/* end block 1.1.1 */
			// End offset: 0x80082590
			// End Line: 2364
		/* end block 1.1 */
		// End offset: 0x80082590
		// End Line: 2364
	/* end block 1 */
	// End offset: 0x800825E0
	// End Line: 2388

	/* begin block 2 */
		// Start line: 4769
	/* end block 2 */
	// End Line: 4770

int MON_DefaultPlanMovement(_Instance *instance,int anim,long distance)

{
  _MonsterAnim *p_Var1;
  long lVar2;
  int iVar3;
  short turnSpeed;
  uint *puVar4;
  undefined4 local_30;
  undefined4 uVar5;
  undefined in_stack_ffffffd4 [12];
  
  puVar4 = (uint *)instance->extraData;
  p_Var1 = MON_GetAnim(instance,*(char **)puVar4[0x5a],anim);
  lVar2 = MATH3D_LengthXYZ((int)(instance->position).x - (int)*(short *)(puVar4 + 0x49),
                           (int)(instance->position).y - (int)*(short *)((int)puVar4 + 0x126),
                           (int)(instance->position).z - (int)*(short *)(puVar4 + 0x4a));
  if (*(char *)((int)puVar4 + 0x166) == -1) {
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
    iVar3 = MON_TurnToPosition(instance,(_Position *)(puVar4 + 0x49),*(short *)(puVar4[0x5a] + 0x1c)
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
                    (instance,(_Position *)&stack0xffffffd8,(int)*(char *)((int)puVar4 + 0x166),
                     (_Position *)(puVar4 + 0x49),0x1f);
  if (iVar3 == 3) {
    return 2;
  }
  if (iVar3 == 0) {
    iVar3 = 1;
    MON_TurnToPosition(instance,(_Position *)(puVar4 + 0x49),*(short *)(puVar4[0x5a] + 0x1c));
  }
  else {
    if ((*puVar4 & 0x20000) == 0) {
      *puVar4 = *puVar4 | 0x20000;
    }
    else {
      iVar3 = 0;
      if ((instance->flags2 & 2U) == 0) goto LAB_80082500;
    }
    MON_PlayAnimIfNotPlaying(instance,(MonsterAnim)CONCAT124(in_stack_ffffffd4,uVar5),anim);
    iVar3 = 0;
  }
LAB_80082500:
  if ((*puVar4 & 0x20000) != 0) {
    if (anim == 2) {
      turnSpeed = *(short *)(puVar4[0x5a] + 0x1e);
    }
    else {
      if (anim == 3) {
        turnSpeed = *(short *)(puVar4[0x5a] + 0x20);
      }
      else {
        turnSpeed = *(short *)(puVar4[0x5a] + 0x1c);
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
 // line 2390, offset 0x80082608
	/* begin block 1 */
		// Start line: 2391
		// Start offset: 0x80082608
		// Variables:
	// 		struct _Instance *child; // $a0

		/* begin block 1.1 */
			// Start line: 2396
			// Start offset: 0x80082628
			// Variables:
		// 		struct _Instance *next; // $s0
		/* end block 1.1 */
		// End offset: 0x80082658
		// End Line: 2402
	/* end block 1 */
	// End offset: 0x80082664
	// End Line: 2404

	/* begin block 2 */
		// Start line: 5000
	/* end block 2 */
	// End Line: 5001

void MON_DropAllObjects(_Instance *instance)

{
  _Instance *Inst;
  int Data;
  _Instance *p_Var1;
  
  Inst = instance->LinkChild;
  while (Inst != (_Instance *)0x0) {
    p_Var1 = Inst->LinkSibling;
    if (Inst->ParentLinkNode == 3) {
      Data = 2;
    }
    else {
      Data = 1;
    }
    INSTANCE_Post(Inst,0x800008,Data);
    Inst = p_Var1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_EnableHeadMove(struct _Instance *instance /*$a0*/)
 // line 2406, offset 0x80082678
	/* begin block 1 */
		// Start line: 2407
		// Start offset: 0x80082678
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s0
	/* end block 1 */
	// End offset: 0x8008270C
	// End Line: 2426

	/* begin block 2 */
		// Start line: 5040
	/* end block 2 */
	// End Line: 5041

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
 // line 2428, offset 0x80082720
	/* begin block 1 */
		// Start line: 2429
		// Start offset: 0x80082720
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s0
	/* end block 1 */
	// End offset: 0x80082798
	// End Line: 2441

	/* begin block 2 */
		// Start line: 5084
	/* end block 2 */
	// End Line: 5085

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
 // line 2446, offset 0x800827ac
	/* begin block 1 */
		// Start line: 2447
		// Start offset: 0x800827AC
		// Variables:
	// 		struct _G2SVector3_Type Rot; // stack offset -32
	// 		struct _MonsterAttributes *ma; // $s3
	/* end block 1 */
	// End offset: 0x80082900
	// End Line: 2470

	/* begin block 2 */
		// Start line: 5120
	/* end block 2 */
	// End Line: 5121

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
 // line 2477, offset 0x80082920
	/* begin block 1 */
		// Start line: 2478
		// Start offset: 0x80082920
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		short z; // $a0
	/* end block 1 */
	// End offset: 0x800829D4
	// End Line: 2506

	/* begin block 2 */
		// Start line: 5189
	/* end block 2 */
	// End Line: 5190

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
  sVar2 = *(short *)((int)pvVar3 + 0x150) + -0x111;
  if (destination < *(short *)((int)pvVar3 + 0x150)) {
    *(short *)((int)pvVar3 + 0x150) = sVar2;
    bVar1 = sVar2 < destination;
  }
  else {
    sVar2 = *(short *)((int)pvVar3 + 0x150) + 0x111;
    if (destination <= *(short *)((int)pvVar3 + 0x150)) goto LAB_800829d4;
    *(short *)((int)pvVar3 + 0x150) = sVar2;
    bVar1 = destination < sVar2;
  }
  if (bVar1) {
    *(short *)((int)pvVar3 + 0x150) = destination;
  }
LAB_800829d4:
  *(undefined2 *)((int)pvVar3 + 0x14e) = 0;
  MON_LookInDirection(instance,0,*(short *)((int)pvVar3 + 0x150));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_ProcessLookAt(struct _Instance *instance /*$s1*/)
 // line 2510, offset 0x800829fc
	/* begin block 1 */
		// Start line: 2511
		// Start offset: 0x800829FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80082ADC
	// End Line: 2539

	/* begin block 2 */
		// Start line: 5255
	/* end block 2 */
	// End Line: 5256

void MON_ProcessLookAt(_Instance *instance)

{
  int *piVar1;
  
  piVar1 = (int *)instance->extraData;
  if (piVar1[0x42] != 0x80000) {
    if (*piVar1 < 0) {
      MON_EnableHeadMove(instance);
      MON_LookAtPos(instance,(_Position *)((int)piVar1 + 0x132));
    }
    else {
      if (piVar1[0x48] == 0) {
        if ((*(short *)((int)piVar1 + 0x14e) == 0) && (*(short *)(piVar1 + 0x54) == 0)) {
          MON_DisableHeadMove(instance);
        }
        else {
          AngleMoveToward((short *)((int)piVar1 + 0x14e),0,100);
          AngleMoveToward((short *)(piVar1 + 0x54),0,100);
          MON_LookInDirection(instance,*(short *)((int)piVar1 + 0x14e),*(short *)(piVar1 + 0x54));
        }
      }
      else {
        MON_EnableHeadMove(instance);
        MON_LookAtPos(instance,(_Position *)piVar1[0x48]);
        piVar1[0x48] = 0;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_TakeDamage(struct _Instance *instance /*$a0*/, int damage /*$s2*/, int type /*$s1*/)
 // line 2544, offset 0x80082af0
	/* begin block 1 */
		// Start line: 2545
		// Start offset: 0x80082AF0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 2552
			// Start offset: 0x80082B34
			// Variables:
		// 		long whatAmI; // $v1
		/* end block 1.1 */
		// End offset: 0x80082B80
		// End Line: 2572
	/* end block 1 */
	// End offset: 0x80082B84
	// End Line: 2576

	/* begin block 2 */
		// Start line: 5323
	/* end block 2 */
	// End Line: 5324

int MON_TakeDamage(_Instance *instance,int damage,int type)

{
  int iVar1;
  ulong uVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  iVar1 = *(int *)(*(int *)((int)pvVar3 + 0x168) + 8);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x1c) == '\0') {
      return 0;
    }
    uVar2 = INSTANCE_Query(instance,1);
    if ((type == 0x40000) && ((uVar2 & 8) == 0)) {
      return 0;
    }
    *(short *)((int)pvVar3 + 0x144) = *(short *)((int)pvVar3 + 0x144) - (short)damage;
    *(undefined2 *)((int)pvVar3 + 0x154) = (short)type;
    if (*(short *)((int)pvVar3 + 0x144) < 1) {
      *(undefined2 *)((int)pvVar3 + 0x144) = 0;
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SetUpSaveInfo(struct _Instance *instance /*$t0*/, struct _MonsterSaveInfo *saveData /*$a3*/)
 // line 2581, offset 0x80082b9c
	/* begin block 1 */
		// Start line: 2582
		// Start offset: 0x80082B9C
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	// 		struct _MonsterAttributes *ma; // $t1
	/* end block 1 */
	// End offset: 0x80082D00
	// End Line: 2610

	/* begin block 2 */
		// Start line: 5403
	/* end block 2 */
	// End Line: 5404

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
  saveData->mvFlags = *puVar5 & 0xffbbfffb;
  saveData->auxFlags = puVar5[1] & 0xf7ffffff;
  uVar1 = saveData->age;
  uVar2 = (uint)*(byte *)((int)puVar5 + 0x15e) & 7;
  saveData->age = uVar1 & 0xfffffff8 | uVar2;
  uVar3 = (instance->currentMainState & 0x3fU) << 3;
  saveData->age = uVar1 & 0xfffffe00 | uVar2 | uVar3;
  uVar4 = ((uint)*(byte *)((int)puVar5 + 0x15a) & 0x1f) << 9;
  saveData->age = uVar1 & 0xffffc000 | uVar2 | uVar3 | uVar4;
  saveData->age =
       uVar1 & 0xff1fc000 | uVar2 | uVar3 | uVar4 | ((uint)*(byte *)(puVar5 + 0x56) & 7) << 0x15;
  if ((instance->currentMainState == 0x17) && (*(char *)(puVar5 + 0x56) == '\0')) {
    saveData->soulJuice = *(short *)(puVar5 + 0x35);
  }
  else {
    saveData->soulJuice = *(short *)(puVar5 + 0x52);
  }
  saveData->soulID = *(short *)(puVar5 + 0x36);
  if (puVar5[0x2f] == 0) {
    uVar2 = saveData->age;
    uVar1 = SEXT14(*(char *)((int)pvVar6 + 0x2c));
  }
  else {
    uVar2 = saveData->age & 0xffefffff |
            ((uint)((instance->anim).section[0].flags >> 1) & 1) << 0x14;
    saveData->age = uVar2;
    uVar1 = (int)(puVar5[0x2f] - *(int *)((int)pvVar6 + 0x40)) >> 4;
  }
  saveData->age = uVar2 & 0xfff03fff | (uVar1 & 0x3f) << 0xe;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_GetSaveInfo(struct _Instance *instance /*$s1*/, struct _MonsterSaveInfo *saveData /*$s2*/)
 // line 2615, offset 0x80082d08
	/* begin block 1 */
		// Start line: 2616
		// Start offset: 0x80082D08
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $s3

		/* begin block 1.1 */
			// Start line: 2674
			// Start offset: 0x80082EE4
			// Variables:
		// 		int mode; // $a2
		/* end block 1.1 */
		// End offset: 0x80082F24
		// End Line: 2685
	/* end block 1 */
	// End offset: 0x80082F24
	// End Line: 2687

	/* begin block 2 */
		// Start line: 5490
	/* end block 2 */
	// End Line: 5491

void MON_GetSaveInfo(_Instance *instance,_MonsterSaveInfo *saveData)

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
  *(undefined *)((int)puVar2 + 0x15e) = (char)index;
  index = *(uint *)(index * 4 + *(int *)((int)pvVar3 + 0x30));
  puVar2[0x5a] = index;
  instance->currentModel = (ushort)*(byte *)(index + 0x26);
  if ((saveData->mvFlags & 0x8000U) == 0) {
    MON_TurnOffBodySpheres(instance);
  }
  else {
    MON_TurnOnBodySpheres(instance);
  }
  *puVar2 = saveData->mvFlags | *puVar2 & 0xc000;
  puVar2[1] = saveData->auxFlags | puVar2[1] & 0x8000000;
  *(byte *)((int)puVar2 + 0x15a) = (byte)(saveData->age >> 9) & 0x1f;
  *(byte *)(puVar2 + 0x56) = (byte)(saveData->age >> 0x15) & 7;
  puVar2[0x36] = (int)saveData->soulID;
  *(short *)(puVar2 + 0x52) = saveData->soulJuice;
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
  case 0x17:
    if (*(char *)(puVar2 + 0x56) == '\0') {
      sVar1 = *(short *)(puVar2 + 0x52);
      *(undefined2 *)(puVar2 + 0x52) = 0x1000;
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
  if ((int)index < (int)*(char *)((int)pvVar3 + 0x2c)) {
    if ((saveData->age >> 0x14 & 1) != 0) {
      mode = 2;
    }
    if (instance->currentMainState == 0x17) {
      MON_PlayAnim(instance,(MonsterAnim)
                            CONCAT412(local_c,CONCAT48(local_10,CONCAT44(local_14,local_18))),0x18);
    }
    else {
      MON_PlayAnimID(instance,index,mode);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_KillMonster(struct _Instance *instance /*$s5*/)
 // line 2692, offset 0x80082f40
	/* begin block 1 */
		// Start line: 2693
		// Start offset: 0x80082F40
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 2700
			// Start offset: 0x80082F80
			// Variables:
		// 		struct _MonsterAttributes *attr; // $v0
		// 		struct FXSplinter *splintDef; // $v1
		/* end block 1.1 */
		// End offset: 0x80082FE0
		// End Line: 2708
	/* end block 1 */
	// End offset: 0x800830E4
	// End Line: 2747

	/* begin block 2 */
		// Start line: 5649
	/* end block 2 */
	// End Line: 5650

void MON_KillMonster(_Instance *instance)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  MON_DropAllObjects(instance);
  if (*(char *)(puVar2 + 0x56) == '\x06') {
    _FX_BuildSplinters(instance,(SVECTOR *)0x0,(SVECTOR *)0x0,(SVECTOR *)0x0,
                       *(FXSplinter **)((int)instance->data + 0x4c),gFXT,
                       (TDRFuncPtr__FX_BuildSplinters6fxSetup)0x0,
                       (TDRFuncPtr__FX_BuildSplinters7fxProcess)0x0,8);
    if ((instance->flags2 & 0x1000U) == 0) {
      SOUND_Play3dSound(&instance->position,0x30,0,0x5f,(int)&DAT_00003e80);
    }
  }
  if (((*puVar2 & 0x1000000) == 0) ||
     ((instance->intro != (Intro *)0x0 && ((instance->intro->flags & 0x400U) != 0)))) {
    SAVE_MarkDeadDead(instance);
  }
  else {
    if (*(short *)((int)puVar2 + 0x14a) != 0) {
      MONAPI_AddToGenerator(instance);
    }
    SAVE_DeleteInstance(instance);
  }
  uVar1 = instance->object->oflags2;
  if ((uVar1 & 4) != 0) {
    if ((instance->flags2 & 0x1000U) != 0) {
      SOUND_ProcessInstanceSounds
                (instance->object->soundData,instance->soundInstanceTbl,&instance->position,
                 uVar1 & 0x2000000,instance->flags2 & 0x8000000,0,0,&instance->flags2);
      SOUND_ProcessInstanceSounds
                (instance->object->soundData,instance->soundInstanceTbl,&instance->position,
                 instance->object->oflags2 & 0x2000000,instance->flags2 & 0x8000000,0,0,
                 &instance->flags2);
    }
  }
  instance->flags = instance->flags | 0x20;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIAmbushEnemy(struct _Instance *instance /*$s3*/)
 // line 2753, offset 0x80083118
	/* begin block 1 */
		// Start line: 2754
		// Start offset: 0x80083118
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $s2

		/* begin block 1.1 */
			// Start line: 2760
			// Start offset: 0x8008316C
			// Variables:
		// 		struct _Instance *inst; // $s1
		// 		struct _Position pos; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x800831E8
		// End Line: 2777
	/* end block 1 */
	// End offset: 0x80083268
	// End Line: 2795

	/* begin block 2 */
		// Start line: 5780
	/* end block 2 */
	// End Line: 5781

int MON_ShouldIAmbushEnemy(_Instance *instance)

{
  _StreamUnit *streamUnit;
  int iVar1;
  long lVar2;
  uint uVar3;
  void *pvVar4;
  _Instance *p_Var5;
  int iVar6;
  _Position local_20;
  
  pvVar4 = instance->extraData;
  iVar6 = *(int *)((int)pvVar4 + 0xc4);
  if (((instance->currentStreamUnitID == instance->birthStreamUnitID) &&
      (*(char *)((int)pvVar4 + 0x156) != '\0')) && (*(int *)((int)pvVar4 + 0x140) == 0x4000800)) {
    p_Var5 = gameTrackerX.playerInstance;
    if (iVar6 != 0) {
      p_Var5 = *(_Instance **)(iVar6 + 4);
    }
    streamUnit = STREAM_GetStreamUnitWithID(instance->birthStreamUnitID);
    iVar1 = PLANAPI_FindNodePositionInUnit
                      (streamUnit,&local_20,(int)*(char *)((int)pvVar4 + 0x156),4);
    if ((iVar1 != 0) &&
       (lVar2 = MATH3D_LengthXYZ((int)(p_Var5->position).x - (int)local_20.x,
                                 (int)(p_Var5->position).y - (int)local_20.y,
                                 (int)(p_Var5->position).z - (int)local_20.z),
       lVar2 < *(short *)((int)pvVar4 + 0x13e))) {
      return 1;
    }
  }
  if (iVar6 == 0) {
    uVar3 = 0;
  }
  else {
    if ((instance->currentMainState != 0x1a) || (uVar3 = 0, (*(ushort *)(iVar6 + 0x16) & 0x40) != 0)
       ) {
      if (*(int *)((int)pvVar4 + 0x140) == 0x4000800) {
        uVar3 = (uint)(*(short *)(iVar6 + 0x14) < *(short *)((int)pvVar4 + 0x13e));
      }
      else {
        uVar3 = 0;
        if (*(short *)(iVar6 + 0x14) < *(short *)((int)pvVar4 + 0x13e)) {
          uVar3 = MATH3D_ConeDetect((_SVector *)(iVar6 + 0xc),(int)*(short *)((int)pvVar4 + 0x140),
                                    (int)*(short *)((int)pvVar4 + 0x142));
        }
      }
    }
  }
  return uVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ShouldIFireAtTarget(struct _Instance *instance /*$a0*/, struct _MonsterIR *target /*$a1*/)
 // line 2800, offset 0x80083284
	/* begin block 1 */
		// Start line: 2802
		// Start offset: 0x80083284
		// Variables:
	// 		struct _MonsterVars *mv; // $a2

		/* begin block 1.1 */
			// Start line: 2808
			// Start offset: 0x800832B4
			// Variables:
		// 		struct _MonsterAttributes *ma; // $v1
		// 		struct _MonsterMissile *missileAttack; // $a0

			/* begin block 1.1.1 */
				// Start line: 2813
				// Start offset: 0x800832EC
				// Variables:
			// 		long distance; // $a1

				/* begin block 1.1.1.1 */
					// Start line: 2817
					// Start offset: 0x80083304
					// Variables:
				// 		struct _MonsterIR *known; // $v1
				/* end block 1.1.1.1 */
				// End offset: 0x8008336C
				// End Line: 2834
			/* end block 1.1.1 */
			// End offset: 0x8008336C
			// End Line: 2835
		/* end block 1.1 */
		// End offset: 0x8008336C
		// End Line: 2836
	/* end block 1 */
	// End offset: 0x8008336C
	// End Line: 2840

	/* begin block 2 */
		// Start line: 5876
	/* end block 2 */
	// End Line: 5877

	/* begin block 3 */
		// Start line: 5877
	/* end block 3 */
	// End Line: 5878

int MON_ShouldIFireAtTarget(_Instance *instance,_MonsterIR *target)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  if (((((*puVar3 & 0x20) != 0) && ((target->mirFlags & 0x20) != 0)) &&
      (iVar2 = *(int *)((int)instance->data + 0x3c) +
               (int)*(char *)(*(int *)(puVar3[0x5a] + 8) + 0x1e) * 0x10,
      *(char *)((int)puVar3 + 0x165) < *(char *)(iVar2 + 0xc))) &&
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
 // line 2845, offset 0x80083374
	/* begin block 1 */
		// Start line: 2846
		// Start offset: 0x80083374
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterIR *enemy; // $v1
	/* end block 1 */
	// End offset: 0x80083464
	// End Line: 2870

	/* begin block 2 */
		// Start line: 5979
	/* end block 2 */
	// End Line: 5980

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
  if (*(short *)(puVar3[0x5a] + 0x1a) <= *(short *)(uVar2 + 0x14)) {
    return 0;
  }
  iVar1 = MON_ValidPosition(instance);
  if (iVar1 != 0) {
    if ((*(char *)((int)puVar3 + 0x15a) == '\t') ||
       (((*puVar3 & 0x2000000) != 0 &&
        (((puVar3[0x33] == 0 || ((*(ushort *)(puVar3[0x33] + 0x16) & 0x200) == 0)) &&
         (*(short *)(puVar3 + 0x51) < 0x2000)))))) {
      return 1;
    }
    if ((*puVar3 & 0x2000) == 0) {
      return 0;
    }
    if (*(short *)(puVar3 + 0x51) == 0) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_RelocateCoords(struct _Instance *instance /*$a0*/, struct _SVector *offset /*$t0*/)
 // line 2875, offset 0x80083474
	/* begin block 1 */
		// Start line: 2876
		// Start offset: 0x80083474
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		int ox; // $a1
	// 		int oy; // $a2
	// 		int oz; // $a3
	/* end block 1 */
	// End offset: 0x800834F0
	// End Line: 2894

	/* begin block 2 */
		// Start line: 6039
	/* end block 2 */
	// End Line: 6040

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
  *(short *)((int)pvVar4 + 0x124) = *(short *)((int)pvVar4 + 0x124) + sVar1;
  *(short *)((int)pvVar4 + 0x126) = *(short *)((int)pvVar4 + 0x126) + sVar2;
  *(short *)((int)pvVar4 + 0x128) = *(short *)((int)pvVar4 + 0x128) + sVar3;
  *(short *)((int)pvVar4 + 300) = *(short *)((int)pvVar4 + 300) + sVar1;
  *(short *)((int)pvVar4 + 0x12e) = *(short *)((int)pvVar4 + 0x12e) + sVar2;
  *(short *)((int)pvVar4 + 0x130) = *(short *)((int)pvVar4 + 0x130) + sVar3;
  if ((int)*(char *)((int)pvVar4 + 0x166) != -1) {
    ENMYPLAN_RelocatePlanPositions((int)*(char *)((int)pvVar4 + 0x166),(_Position *)offset);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ValidUnit(struct _Instance *instance /*$a0*/, unsigned long unitId /*$a1*/)
 // line 2899, offset 0x80083500
	/* begin block 1 */
		// Start line: 2901
		// Start offset: 0x80083500
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		short *unit; // $a0
	/* end block 1 */
	// End offset: 0x80083544
	// End Line: 2916

	/* begin block 2 */
		// Start line: 6093
	/* end block 2 */
	// End Line: 6094

	/* begin block 3 */
		// Start line: 6094
	/* end block 3 */
	// End Line: 6095

int MON_ValidUnit(_Instance *instance,ulong unitId)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = (ushort *)((int)instance->extraData + 0x174);
  if (*(short *)((int)instance->extraData + 0x174) != 0) {
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
 // line 2921, offset 0x8008354c
	/* begin block 1 */
		// Start line: 2922
		// Start offset: 0x8008354C

		/* begin block 1.1 */
			// Start line: 2923
			// Start offset: 0x80083570
			// Variables:
		// 		struct _MonsterVars *mv; // $v1
		/* end block 1.1 */
		// End offset: 0x80083578
		// End Line: 2930
	/* end block 1 */
	// End offset: 0x80083594
	// End Line: 2931

	/* begin block 2 */
		// Start line: 6139
	/* end block 2 */
	// End Line: 6140

int MON_ValidPosition(_Instance *instance)

{
  short sVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = MON_ValidUnit(instance,instance->currentStreamUnitID);
  if (iVar2 != 0) {
    pvVar3 = instance->extraData;
    sVar1 = (instance->position).z;
    *(undefined4 *)((int)pvVar3 + 300) = *(undefined4 *)&instance->position;
    *(short *)((int)pvVar3 + 0x130) = sVar1;
  }
  return (uint)(iVar2 != 0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SphereWorldPos(struct MATRIX *mat /*$s1*/, struct _HSphere *sphere /*$a1*/, struct _Position *ret /*$s0*/)
 // line 2934, offset 0x800835a4
	/* begin block 1 */
		// Start line: 6170
	/* end block 1 */
	// End Line: 6171

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
 // line 2943, offset 0x80083614
	/* begin block 1 */
		// Start line: 2945
		// Start offset: 0x80083614
		// Variables:
	// 		struct _HModel *hmodel; // $v0
	// 		struct _HPrim *usePrim; // $a3
	// 		struct _HPrim *currentP; // $a0
	// 		struct _HSphere *tempS; // $v0
	// 		int maxRad; // $a2
	// 		int i; // $a1
	/* end block 1 */
	// End offset: 0x80083698
	// End Line: 2973

	/* begin block 2 */
		// Start line: 6188
	/* end block 2 */
	// End Line: 6189

	/* begin block 3 */
		// Start line: 6189
	/* end block 3 */
	// End Line: 6190

	/* begin block 4 */
		// Start line: 6190
	/* end block 4 */
	// End Line: 6191

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
      if (((undefined **)(*(uint *)p_Var3 & 0xff0200) == &PTR_00010200) &&
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
 // line 2977, offset 0x800836a0
	/* begin block 1 */
		// Start line: 2978
		// Start offset: 0x800836A0
		// Variables:
	// 		struct Intro *current; // $v1
	// 		struct Intro *res; // $s2
	// 		struct Level *level; // $v0
	// 		int min_dist; // $s3
	// 		int dist; // $v1
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x800837AC
	// End Line: 3021

	/* begin block 2 */
		// Start line: 6266
	/* end block 2 */
	// End Line: 6267

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
 // line 3025, offset 0x800837d0
	/* begin block 1 */
		// Start line: 3026
		// Start offset: 0x800837D0
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct Intro *current; // $s1
	// 		struct _HPrim *prim; // $v1
	// 		struct _HSphere *sphere; // $a1
	// 		int i; // $s2
	// 		int radius; // $s3
	// 		struct _Position spherePos; // stack offset -32
	/* end block 1 */
	// End offset: 0x800838B0
	// End Line: 3068

	/* begin block 2 */
		// Start line: 6380
	/* end block 2 */
	// End Line: 6381

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
      MON_SphereWorldPos(instance->matrix + p_Var2->segment,(_HSphere *)p_Var2->data,&local_20);
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
// void /*$ra*/ MON_MoveInstanceToImpalePoint(struct _Instance *instance /*$s0*/)
 // line 3070, offset 0x800838cc
	/* begin block 1 */
		// Start line: 3071
		// Start offset: 0x800838CC
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		struct Intro *impaler; // $t3
	// 		struct _Position offset; // stack offset -16

		/* begin block 1.1 */
			// Start line: 3095
			// Start offset: 0x80083908
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a2
		// 		short _y1; // $t0
		// 		short _z1; // $t2
		// 		struct _Position *_v; // $a3
		// 		struct _Position *_v1; // $a1
		/* end block 1.1 */
		// End offset: 0x80083908
		// End Line: 3095

		/* begin block 1.2 */
			// Start line: 3095
			// Start offset: 0x80083908
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _Rotation *_v0; // $v0
		// 		struct _Rotation *_v1; // $v0
		/* end block 1.2 */
		// End offset: 0x80083908
		// End Line: 3095
	/* end block 1 */
	// End offset: 0x800839A0
	// End Line: 3105

	/* begin block 2 */
		// Start line: 6486
	/* end block 2 */
	// End Line: 6487

void MON_MoveInstanceToImpalePoint(_Instance *instance)

{
  short sVar1;
  short sVar2;
  Intro *pIVar3;
  SVECTOR local_10;
  
  if ((instance->matrix != (MATRIX *)0x0) &&
     (pIVar3 = INSTANCE_FindIntro(instance->currentStreamUnitID,
                                  *(long *)((int)instance->extraData + 0x1a4)),
     pIVar3 != (Intro *)0x0)) {
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
    COLLIDE_UpdateAllTransforms(instance,&local_10);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_ReachableIntro(struct _Instance *instance /*stack 0*/, struct _Position *pos /*$t0*/, struct _Position *introPos /*$fp*/, struct _Rotation *introRot /*$s7*/, int checkOrientation /*stack 16*/)
 // line 3119, offset 0x800839b0
	/* begin block 1 */
		// Start line: 3120
		// Start offset: 0x800839B0
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
	// End offset: 0x80083D48
	// End Line: 3236

	/* begin block 2 */
		// Start line: 6600
	/* end block 2 */
	// End Line: 6601

/* WARNING: Removing unreachable block (ram,0x80083b4c) */

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
  square_00 = (int)*(short *)(*(int *)((int)pvVar8 + 0x168) + 0x44);
  angle = 0;
  sVar9 = 0;
  lVar7 = 0;
  square = square * square + iVar2 * iVar2 + iVar3 * iVar3;
  bVar1 = false;
  if ((square < square_00 * square_00) &&
     (iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x168) + 0x42), iVar2 * iVar2 < square)) {
    angle = MATH3D_AngleFromPosToPos(pos,introPos);
    if (checkOrientation != 0) {
      uVar6 = ((int)(instance->rotation).z + 0x800U & 0xfff) - (int)angle & 0xfff;
      iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x168) + 0x46);
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
      if (checkOrientation != 0) goto LAB_80083c4c;
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
        if ((int)uVar6 < (int)*(short *)(*(int *)((int)pvVar8 + 0x168) + 0x46)) {
          uVar6 = (uint)(ushort)introRot->x & 0xfff;
          if (0x800 < uVar6) {
            uVar6 = uVar6 - 0x1000;
          }
          bVar1 = true;
          if ((int)uVar6 < 1) {
            iVar2 = (int)*(short *)(*(int *)((int)pvVar8 + 0x168) + 0x4a);
            lVar7 = iVar2 - (int)((iVar2 - *(short *)(*(int *)((int)pvVar8 + 0x168) + 0x48)) *
                                 -uVar6) / 0x380;
          }
          else {
            lVar7 = (long)*(short *)(*(int *)((int)pvVar8 + 0x168) + 0x4a);
          }
        }
        goto LAB_80083c4c;
      }
    }
    bVar1 = true;
    lVar7 = (long)*(short *)(*(int *)((int)pvVar8 + 0x168) + 0x48);
  }
LAB_80083c4c:
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
    if (square < *(short *)(*(int *)((int)pvVar8 + 0x168) + 0x4c)) {
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
 // line 3239, offset 0x80083d78
	/* begin block 1 */
		// Start line: 3240
		// Start offset: 0x80083D78
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct Intro *currentI; // $s1
	// 		struct _HPrim *usePrim; // $v0
	// 		int i; // $s2
	// 		struct _Position spherePos; // stack offset -32

		/* begin block 1.1 */
			// Start line: 3254
			// Start offset: 0x80083DD0
			// Variables:
		// 		struct _Instance *target; // $s0

			/* begin block 1.1.1 */
				// Start line: 3279
				// Start offset: 0x80083E70
				// Variables:
			// 		struct PhysObProperties *prop; // $v1

				/* begin block 1.1.1.1 */
					// Start line: 3282
					// Start offset: 0x80083E88
				/* end block 1.1.1.1 */
				// End offset: 0x80083EB8
				// End Line: 3287
			/* end block 1.1.1 */
			// End offset: 0x80083EB8
			// End Line: 3288
		/* end block 1.1 */
		// End offset: 0x80083EC8
		// End Line: 3290
	/* end block 1 */
	// End offset: 0x80083ECC
	// End Line: 3294

	/* begin block 2 */
		// Start line: 6896
	/* end block 2 */
	// End Line: 6897

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
  if ((*(uint *)((int)instance->data + 0x10) & 8) == 0) {
    p_Var2 = MON_FindSphereForTerrain(instance);
    if (p_Var2 != (_HPrim *)0x0) {
      MON_SphereWorldPos(instance->matrix + p_Var2->segment,(_HSphere *)p_Var2->data,&_Stack32);
      iVar6 = pLVar1->terrain->numIntros;
      pIVar5 = pLVar1->terrain->introList;
      introRot = &pIVar5->rotation;
      while (iVar6 != 0) {
        if (((*(uint *)&introRot[2].z & 0x8000) != 0) &&
           (iVar3 = MON_ReachableIntro(instance,&_Stack32,&pIVar5->position,introRot,
                                       checkOrientation), iVar3 != 0)) {
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
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_TurnOffSphereCollisions(struct _Instance *instance /*$a0*/)
 // line 3303, offset 0x80083eec
	/* begin block 1 */
		// Start line: 3305
		// Start offset: 0x80083EEC
		// Variables:
	// 		int i; // $a0
	// 		struct _HPrim *hprim; // $v1
	// 		struct _HModel *hmodel; // $v1
	/* end block 1 */
	// End offset: 0x80083F40
	// End Line: 3321

	/* begin block 2 */
		// Start line: 7043
	/* end block 2 */
	// End Line: 7044

	/* begin block 3 */
		// Start line: 7044
	/* end block 3 */
	// End Line: 7045

	/* begin block 4 */
		// Start line: 7046
	/* end block 4 */
	// End Line: 7047

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
 // line 3323, offset 0x80083f48
	/* begin block 1 */
		// Start line: 3325
		// Start offset: 0x80083F48
		// Variables:
	// 		int i; // $a0
	// 		struct _HPrim *hprim; // $v1
	// 		struct _HModel *hmodel; // $v1
	/* end block 1 */
	// End offset: 0x80083F9C
	// End Line: 3341

	/* begin block 2 */
		// Start line: 7085
	/* end block 2 */
	// End Line: 7086

	/* begin block 3 */
		// Start line: 7086
	/* end block 3 */
	// End Line: 7087

	/* begin block 4 */
		// Start line: 7088
	/* end block 4 */
	// End Line: 7089

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
 // line 3343, offset 0x80083fa4
	/* begin block 1 */
		// Start line: 3344
		// Start offset: 0x80083FA4
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		int currentFadeValue; // $a1
	// 		int targetFadeValue; // $v1
	// 		int fadeRate; // $a3
	// 		struct _Instance *child; // $v1
	/* end block 1 */
	// End offset: 0x800841D0
	// End Line: 3438

	/* begin block 2 */
		// Start line: 7127
	/* end block 2 */
	// End Line: 7128

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
      iVar3 = (int)*(short *)((int)pvVar5 + 0x1aa) * gameTrackerX.timeMult;
      sVar2 = *(short *)((int)pvVar5 + 0x1a8);
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0xfff;
      }
      iVar3 = (int)instance->fadeValue + (iVar3 >> 0xc);
      if ((int)*(short *)((int)pvVar5 + 0x1aa) < 1) {
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
    if ((instance->currentMainState != 0x17) && (instance->currentMainState != 0x10)) {
      if ((gameTrackerX.gameData.asmData._8_4_ == 1000) ||
         ((gameTrackerX.gameData.asmData.MorphType == 1 &&
          (gameTrackerX.gameData.asmData.MorphTime != 1000)))) {
        iVar3 = (int)*(short *)((int)pvVar5 + 0x1a8);
        iVar8 = 0x1000 - iVar3;
      }
      else {
        iVar8 = (int)*(short *)((int)pvVar5 + 0x1a8);
        iVar3 = 0x1000 - iVar8;
      }
      iVar6 = (int)gameTrackerX.gameData.asmData.MorphTime;
      if (iVar6 < 0x14d) {
        iVar6 = (0x1000 - iVar8) * iVar6;
        sVar2 = (short)iVar8 +
                ((short)((ulonglong)((longlong)iVar6 * 0xc4ce07b1) >> 0x28) - (short)(iVar6 >> 0x1f)
                );
      }
      else {
        if (iVar6 < 0x29b) {
          sVar2 = 0x1000;
        }
        else {
          iVar3 = (iVar3 + -0x1000) * (iVar6 + -0x29a);
          sVar2 = ((short)((ulonglong)((longlong)iVar3 * 0xc4ce07b1) >> 0x28) -
                  (short)(iVar3 >> 0x1f)) + 0x1000;
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
 // line 3440, offset 0x800841e0
	/* begin block 1 */
		// Start line: 3442
		// Start offset: 0x800841E0
		// Variables:
	// 		struct _MonsterVars *mv; // $a3
	// 		int diff; // $a1
	/* end block 1 */
	// End offset: 0x80084240
	// End Line: 3455

	/* begin block 2 */
		// Start line: 7330
	/* end block 2 */
	// End Line: 7331

	/* begin block 3 */
		// Start line: 7331
	/* end block 3 */
	// End Line: 7332

void MON_StartSpecialFade(_Instance *instance,int fadeLevel,int fadeTime)

{
  void *pvVar1;
  uint uVar2;
  
  pvVar1 = instance->extraData;
  *(undefined2 *)((int)pvVar1 + 0x1a8) = (short)fadeLevel;
  *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) | 0x8000000;
  fadeLevel = fadeLevel - instance->fadeValue;
  if (fadeTime < 1) {
    fadeTime = 1;
  }
  uVar2 = fadeLevel / fadeTime;
  *(undefined2 *)((int)pvVar1 + 0x1aa) = (short)uVar2;
  if ((uVar2 & 0xffff) == 0) {
    if (fadeLevel < 0) {
      *(undefined2 *)((int)pvVar1 + 0x1aa) = 0xffff;
      return;
    }
    *(undefined2 *)((int)pvVar1 + 0x1aa) = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_UnlinkFromRaziel(struct _Instance *instance /*$s0*/)
 // line 3457, offset 0x80084248
	/* begin block 1 */
		// Start line: 3458
		// Start offset: 0x80084248
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct evPositionData *data; // $v1
	// 		struct _Instance *enemy; // $s1
	/* end block 1 */
	// End offset: 0x800842C4
	// End Line: 3476

	/* begin block 2 */
		// Start line: 7365
	/* end block 2 */
	// End Line: 7366

void MON_UnlinkFromRaziel(_Instance *instance)

{
  short *psVar1;
  undefined4 local_10;
  undefined4 local_c;
  _Instance *Inst;
  
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
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BurnInAir(struct _Instance *instance /*$s1*/, int currentState /*$s2*/)
 // line 3482, offset 0x800842e8
	/* begin block 1 */
		// Start line: 3483
		// Start offset: 0x800842E8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x80084368
	// End Line: 3493

	/* begin block 2 */
		// Start line: 7415
	/* end block 2 */
	// End Line: 7416

void MON_BurnInAir(_Instance *instance,int currentState)

{
  ulong uVar1;
  int Data;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x400000) == 0) {
    *puVar2 = *puVar2 | 0x400000;
    uVar1 = MON_GetTime(instance);
    *(undefined **)(puVar2 + 0x47) = &DAT_00002710 + uVar1;
    MON_MonsterGlow(instance,(long)&DAT_00004960,-1,0,0);
    Data = SetFXHitData((_Instance *)0x0,0,0,0x20);
    INSTANCE_Post(instance,0x400000,Data);
  }
  instance->currentMainState = currentState;
  *puVar2 = *puVar2 & 0xfffffffe;
  instance->checkMask = instance->checkMask & 0xffffffdf;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_BirthMana(struct _Instance *instance /*$s0*/)
 // line 3499, offset 0x800843a4
	/* begin block 1 */
		// Start line: 3500
		// Start offset: 0x800843A4

		/* begin block 1.1 */
			// Start line: 3503
			// Start offset: 0x800843C4
			// Variables:
		// 		struct _MonsterVars *mv; // $v0

			/* begin block 1.1.1 */
				// Start line: 3507
				// Start offset: 0x800843E0
				// Variables:
			// 		int type; // $a0
			// 		struct MATRIX *mat; // $a3
			/* end block 1.1.1 */
			// End offset: 0x8008444C
			// End Line: 3510
		/* end block 1.1 */
		// End offset: 0x8008444C
		// End Line: 3511
	/* end block 1 */
	// End offset: 0x8008444C
	// End Line: 3512

	/* begin block 2 */
		// Start line: 7451
	/* end block 2 */
	// End Line: 7452

void MON_BirthMana(_Instance *instance)

{
  int iVar1;
  MATRIX *pMVar2;
  
  if ((instance->matrix != (MATRIX *)0x0) && (*(char *)((int)instance->extraData + 0x165) < '\x19'))
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
 // line 3514, offset 0x8008445c
	/* begin block 1 */
		// Start line: 3515
		// Start offset: 0x8008445C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x800844C0
	// End Line: 3526

	/* begin block 2 */
		// Start line: 7484
	/* end block 2 */
	// End Line: 7485

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
    MON_BirthMana(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ MON_SetUpKnockBack(struct _Instance *instance /*$s2*/, struct _Instance *enemy /*$s1*/, struct evMonsterHitData *data /*$a2*/)
 // line 3531, offset 0x800844d4
	/* begin block 1 */
		// Start line: 3532
		// Start offset: 0x800844D4
		// Variables:
	// 		struct _MonsterVars *mv; // $s5
	// 		long d; // $s0
	// 		long t; // $s4
	// 		long a; // $s3
	// 		long v; // $s0
	// 		int front; // $s0
	/* end block 1 */
	// End offset: 0x80084598
	// End Line: 3561

	/* begin block 2 */
		// Start line: 7518
	/* end block 2 */
	// End Line: 7519

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
 // line 3566, offset 0x800845d8
	/* begin block 1 */
		// Start line: 3567
		// Start offset: 0x800845D8
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s3
	// 		struct _MonsterVars *mv; // $s2
	// 		struct MATRIX *mat; // $t2
	// 		struct _SVector location; // stack offset -56
	// 		struct _SVector position; // stack offset -48
	// 		struct _SVector vel; // stack offset -40
	// 		struct _SVector accel; // stack offset -32
	/* end block 1 */
	// End offset: 0x80084848
	// End Line: 3612

	/* begin block 2 */
		// Start line: 7589
	/* end block 2 */
	// End Line: 7590

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
    *(uint *)((int)pvVar3 + 0x11c) =
         *(int *)((int)pvVar3 + 0x11c) + (gameTrackerX.timeMult * 0x50 >> 0xc) & 0xfff;
    FX_Lightning(theCamera.core.wcTransform,gameTrackerX.drawOT,(MATRIX *)0x0,
                 *(short *)((int)pvVar3 + 0x11c),&local_30,&local_38,0,0x60,0x18,0x50,1,0xd06060,
                 0xff6400);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MON_SetFXHitData(struct _Instance *instance /*$a0*/, struct evFXHitData *data /*$a1*/, int type /*$a2*/, int amount /*$a3*/)
 // line 3614, offset 0x80084864
	/* begin block 1 */
		// Start line: 3616
		// Start offset: 0x80084864

		/* begin block 1.1 */
			// Start line: 3620
			// Start offset: 0x8008487C
			// Variables:
		// 		struct MATRIX *mat; // $v0
		/* end block 1.1 */
		// End offset: 0x8008487C
		// End Line: 3620
	/* end block 1 */
	// End offset: 0x800848E0
	// End Line: 3631

	/* begin block 2 */
		// Start line: 7757
	/* end block 2 */
	// End Line: 7758

	/* begin block 3 */
		// Start line: 7758
	/* end block 3 */
	// End Line: 7759

void MON_SetFXHitData(_Instance *instance,evFXHitData *data,int type,int amount)

{
  MATRIX *pMVar1;
  
  data->type = (short)type;
  data->amount = (short)amount;
  if (instance->matrix == (MATRIX *)0x0) {
    (data->location).x = (instance->position).x;
    (data->location).y = (instance->position).y;
    (data->location).z = (instance->position).z + 0x100;
  }
  else {
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
 // line 3636, offset 0x800848f0
	/* begin block 1 */
		// Start line: 7801
	/* end block 1 */
	// End Line: 7802

void MON_LaunchMonster(_Instance *instance,int zDirection,int power,int loft)

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
  iVar1 = MON_SetVelocityTowardsImpalingObject(instance,1);
  if (iVar1 == 0) {
    PhysicsSetVelFromZRot(instance,(short)zDirection,power);
    instance->zVel = loft;
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
  return;
}





