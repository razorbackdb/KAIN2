#include "THISDUST.H"
#include "ATTACK.H"


// decompiled code
// original method signature: 
// int /*$ra*/ StateHandlerDecodeHold(int *Message /*$s2*/, int *Data /*$s3*/)
 // line 16, offset 0x8009bb00
	/* begin block 1 */
		// Start line: 17
		// Start offset: 0x8009BB00
		// Variables:
	// 		int rc; // $s4
	// 		int WhoAmI; // $s0
	// 		struct _Instance *heldInstance; // $s1

		/* begin block 1.1 */
			// Start line: 53
			// Start offset: 0x8009BC2C
			// Variables:
		// 		int hitState; // $v1
		/* end block 1.1 */
		// End offset: 0x8009BD18
		// End Line: 90

		/* begin block 1.2 */
			// Start line: 117
			// Start offset: 0x8009BDB8
			// Variables:
		// 		struct _Instance *heldWeapon; // $v1
		/* end block 1.2 */
		// End offset: 0x8009BE1C
		// End Line: 137
	/* end block 1 */
	// End offset: 0x8009BE48
	// End Line: 147

	/* begin block 2 */
		// Start line: 32
	/* end block 2 */
	// End Line: 33

/* WARNING: Removing unreachable block (ram,0x8009bbcc) */
/* WARNING: Removing unreachable block (ram,0x8009bbf0) */
/* WARNING: Removing unreachable block (ram,0x8009bbe0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int StateHandlerDecodeHold(int *Message,int *Data)

{
  _Instance *p_Var1;
  int iVar2;
  
  iVar2 = 1;
  p_Var1 = razGetHeldWeapon();
  if (_CHAR____800d564c == 2) {
    *Data = 1;
    *Message = -0x80000000;
    if ((_CHAR____800d55f0 & 0x200) != 0) {
      return 1;
    }
    if (_CHAR____800d5600 != 0x1000) {
      return 0;
    }
    if ((_CHAR____800d561c & 4) == 0) {
      return 0;
    }
    *Message = 0x800010;
    return 1;
  }
  if ((_CHAR____800d55f0 & 0x200) != 0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)(_CHAR____800d55ec + 0x48),1);
  }
  if (((((_CHAR____800d55f0 & 0x200) != 0) && (p_Var1 != (_Instance *)0x0)) &&
      (_CHAR____800d5600 != 3)) && (_CHAR____800d5600 != 8)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)(_CHAR____800d55ec + 0x48),0);
  }
  if (((_CHAR____800d55f0 & 0x100) != 0) && (p_Var1 == (_Instance *)0x0)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(*(_Instance **)(_CHAR____800d55ec + 0x40),0);
  }
  if (((_CHAR____800d55f0 & 0x200) != 0) && (_CHAR____800d5600 == 3)) {
    *Message = -0x80000000;
    *Data = 1;
    return 1;
  }
  p_Var1 = razGetHeldWeapon();
  if (p_Var1 == (_Instance *)0x0) {
    if ((_CHAR____800d561c & 4) != 0) {
      *Message = 0x80000;
      goto LAB_8009be1c;
    }
  }
  else {
    if ((p_Var1 != _CHAR____800d5644) || ((_CHAR____800d561c & 4) != 0)) {
      *Message = 0x800010;
      goto LAB_8009be1c;
    }
  }
  iVar2 = 0;
LAB_8009be1c:
  if (_CHAR____800d5600 != 3) {
    return iVar2;
  }
  if (*Message == 0x800010) {
    return iVar2;
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerAttack2(struct __CharacterState *In /*$s4*/, int CurrentSection /*$s5*/, int Data /*stack 8*/)
 // line 157, offset 0x8009be68
	/* begin block 1 */
		// Start line: 158
		// Start offset: 0x8009BE68
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		int message; // stack offset -64
	// 		int messageData; // stack offset -60
	// 		int Frame; // stack offset -56
	// 		int Anim; // stack offset -52
	// 		int ignoreHit; // stack offset -48
	// 		struct _Instance *ignoreInst; // stack offset -44

		/* begin block 1.1 */
			// Start line: 233
			// Start offset: 0x8009C214
			// Variables:
		// 		struct _Instance *inst; // $s0
		// 		unsigned long startColor; // $s3
		// 		unsigned long endColor; // $s2
		/* end block 1.1 */
		// End offset: 0x8009C364
		// End Line: 279

		/* begin block 1.2 */
			// Start line: 332
			// Start offset: 0x8009C4BC
			// Variables:
		// 		struct _Instance *weaponInst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009C51C
		// End Line: 349

		/* begin block 1.3 */
			// Start line: 406
			// Start offset: 0x8009C750
			// Variables:
		// 		struct _Instance *inst; // $s0
		// 		unsigned long startColor; // $s2
		// 		unsigned long endColor; // $s1
		/* end block 1.3 */
		// End offset: 0x8009C834
		// End Line: 438

		/* begin block 1.4 */
			// Start line: 486
			// Start offset: 0x8009C99C
			// Variables:
		// 		struct _Instance *Inst; // $a0
		/* end block 1.4 */
		// End offset: 0x8009CA0C
		// End Line: 500

		/* begin block 1.5 */
			// Start line: 518
			// Start offset: 0x8009CA9C
		/* end block 1.5 */
		// End offset: 0x8009CA9C
		// End Line: 519

		/* begin block 1.6 */
			// Start line: 544
			// Start offset: 0x8009CB84
		/* end block 1.6 */
		// End offset: 0x8009CBCC
		// End Line: 551

		/* begin block 1.7 */
			// Start line: 574
			// Start offset: 0x8009CC60
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.7 */
		// End offset: 0x8009CD30
		// End Line: 588

		/* begin block 1.8 */
			// Start line: 608
			// Start offset: 0x8009CDE4
			// Variables:
		// 		struct evMonsterHitData *hitData; // $s0
		/* end block 1.8 */
		// End offset: 0x8009CDFC
		// End Line: 614

		/* begin block 1.9 */
			// Start line: 634
			// Start offset: 0x8009CE74
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v1
		/* end block 1.9 */
		// End offset: 0x8009CED8
		// End Line: 641
	/* end block 1 */
	// End offset: 0x8009CF08
	// End Line: 648

	/* begin block 2 */
		// Start line: 321
	/* end block 2 */
	// End Line: 322

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerAttack2(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  byte bVar2;
  __Event *p_Var3;
  _Instance *p_Var4;
  undefined *puVar5;
  uint uVar6;
  _Instance *instance;
  __CharacterState *In_00;
  __CharacterState *In_01;
  int mode;
  int NewAnim;
  code *NewProcess;
  int in_a3;
  long endColor;
  long startColor;
  _Instance **pp_Var7;
  int local_58;
  int local_54;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  _Instance *local_2c;
  
  local_54 = Data;
  local_38 = G2EmulationQueryFrame(In,CurrentSection);
  mode = CurrentSection;
  local_34 = G2EmulationQueryAnimation(In,CurrentSection);
  local_30 = 0;
  local_2c = (_Instance *)0x0;
  if (CurrentSection == 0) {
    if ((_BlockVramEntry_800d59a0._12_4_ & 0x20) == 0) {
      if (((_BlockVramEntry_800d59a0._12_4_ & 0x10000000) == 0) || ((_CHAR____800d5574 & 2) != 0))
      goto LAB_8009bf34;
      mode = 2;
      if ((*gameTracker._4_4_ & 0x8000000f) == 0) goto LAB_8009bf20;
      instance = In->CharacterInstance;
    }
    else {
LAB_8009bf20:
      instance = In->CharacterInstance;
      mode = 0;
    }
    SteerSwitchMode(instance,mode);
  }
LAB_8009bf34:
  pp_Var7 = &In->CharacterInstance + CurrentSection * 0x47;
  In_01 = (__CharacterState *)&In->SectionList[CurrentSection].Event;
  In_00 = In_01;
  p_Var3 = PeekMessageQueue((__MessageQueue *)In_01);
  NewAnim = _PlayerData;
  if (p_Var3 == (__Event *)0x0) {
    if (((_CHAR____800d5660 & 4) != 0) &&
       ((int)((uint)_CHAR____800d565c[4] * 100) <=
        (int)(In->CharacterInstance->anim).section[CurrentSection & 0xff].elapsedTime)) {
                    /* WARNING: Subroutine does not return */
      EnMessageQueueData(&In->SectionList[CurrentSection].Event,0x100000,0);
    }
    if ((local_30 != 0) && (local_2c != (_Instance *)0x0)) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Post(local_2c,0x1000024,0);
    }
    return;
  }
  puVar5 = (undefined *)p_Var3->ID;
  uVar6 = _BlockVramEntry_800d59a0._12_4_;
  if (puVar5 == (undefined *)0x1000002) {
    if (_CHAR____800d564c == 1) {
      StateSwitchStateData(In,CurrentSection,StateHandlerGrab,local_3c);
      uVar6 = _BlockVramEntry_800d59a0._12_4_;
    }
    goto LAB_8009ce50;
  }
  if (0x1000002 < (int)puVar5) {
    if (puVar5 == (undefined *)0x2000000) {
LAB_8009c41c:
      _CHAR____800d565c =
           *(byte **)((int)pp_Var7[0x48] * 4 +
                     *(int *)(_CHAR____800d5664 * 4 + *(int *)(_PlayerData + 0x10)));
      if ((local_34 == (uint)*_CHAR____800d565c) && ((int)(uint)_CHAR____800d565c[5] <= local_38)) {
        _CHAR____800d5660 = _CHAR____800d5660 | 4;
      }
      if ((CurrentSection == 1) && (_CHAR____800d5670 != (_FXGlowEffect *)0x0)) {
        FX_StopGlowEffect(_CHAR____800d5670,0);
        _CHAR____800d5670 = (_FXGlowEffect *)0x0;
        uVar6 = _BlockVramEntry_800d59a0._12_4_;
      }
      goto LAB_8009ce50;
    }
    if ((int)puVar5 < 0x2000001) {
      if (puVar5 == (undefined *)0x100001f) {
        if ((CurrentSection == 1) &&
           (instance = (_Instance *)p_Var3->Data,
           *(_Instance **)((int)&instance->node + 4) != (_Instance *)0x0)) {
          mode = SetMonsterHitData(*(_Instance **)&instance->node,(_Instance *)0x0,
                                   (int)instance->prev,(uint)*(ushort *)(_CHAR____800d565c + 0x20),
                                   (uint)_CHAR____800d565c[0xf]);
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(*(_Instance **)((int)&instance->node + 4),0x100001f,mode);
        }
        goto LAB_8009ce50;
      }
      if ((int)puVar5 < 0x1000020) {
        if (puVar5 == (undefined *)0x100000a) {
          if (p_Var3->Data != 0) {
            razSetPlayerEventHistory(0x80);
            _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x40000;
            if (CurrentSection == 2) {
              NewAnim = 0;
              mode = 2;
              local_54 = CurrentSection;
            }
            else {
              NewAnim = 0x3b;
              local_54 = 1;
              mode = CurrentSection;
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,mode,NewAnim,0,3,local_54);
          }
          uVar6 = _BlockVramEntry_800d59a0._12_4_ | 0x20;
          if (CurrentSection != 1) goto LAB_8009ce50;
          mode = 0x48;
        }
        else {
          if (puVar5 != (undefined *)0x1000018) goto LAB_8009ce40;
          if (p_Var3->Data != 0) {
            razSetPlayerEventHistory(0x100);
            _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x40000;
            if (CurrentSection == 2) {
              NewAnim = 0;
              local_58 = 3;
              mode = 2;
              local_54 = CurrentSection;
            }
            else {
              NewAnim = 0x8a;
              local_58 = 0;
              local_54 = 1;
              mode = CurrentSection;
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,mode,NewAnim,0,local_58,local_54);
          }
          uVar6 = _BlockVramEntry_800d59a0._12_4_ | 0x20;
          if (CurrentSection != 1) goto LAB_8009ce50;
          mode = 0x8a;
        }
        _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x20;
        G2EmulationSwitchAnimationCharacter(In,mode,0,3,CurrentSection);
        uVar6 = _BlockVramEntry_800d59a0._12_4_;
        if ((_CHAR____800d55f0 & 0x200) != 0) {
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x48),0x100000a,0);
        }
        goto LAB_8009ce50;
      }
      if (puVar5 == (undefined *)0x1000023) {
        if (p_Var3->Data == 0) {
          _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x20;
        }
        uVar6 = _BlockVramEntry_800d59a0._12_4_;
        if ((CurrentSection == 0) &&
           (razSwitchVAnimCharacterSingle(In->CharacterInstance,0x18,(int *)0x0,(int *)0x0),
           uVar6 = _BlockVramEntry_800d59a0._12_4_, (_CHAR____800d55f0 & 0x200) != 0)) {
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x48),0x1000023,p_Var3->Data);
        }
        goto LAB_8009ce50;
      }
      if (puVar5 == (undefined *)0x1000024) {
        local_30 = 1;
        goto LAB_8009ce50;
      }
    }
    else {
      if (puVar5 == (undefined *)0x4020000) goto LAB_8009ce50;
      if ((int)puVar5 < 0x4020001) {
        if (puVar5 == (undefined *)0x2000002) {
          if (CurrentSection == 1) {
            instance = (_Instance *)p_Var3->Data;
            mode = (int)instance->prev * (uint)*(ushort *)(_CHAR____800d565c + 0x22);
            local_2c = *(_Instance **)&instance->node;
            if (mode < 0) {
              mode = mode + 0xfff;
            }
            mode = SetMonsterHitData(In->CharacterInstance,_CHAR____800d566c,mode >> 0xc,
                                     (uint)*(ushort *)(_CHAR____800d565c + 0x20),
                                     (uint)_CHAR____800d565c[0xf]);
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post(*(_Instance **)&instance->node,0x1000000,mode);
          }
          goto LAB_8009ce50;
        }
        if (puVar5 == (undefined *)0x4010080) {
          if (CurrentSection == 0) {
            if (p_Var3->Data == 0) {
              razSetPauseTranslation(In->CharacterInstance);
              uVar6 = _BlockVramEntry_800d59a0._12_4_;
            }
            else {
              razResetPauseTranslation(In->CharacterInstance);
              uVar6 = _BlockVramEntry_800d59a0._12_4_;
            }
          }
          goto LAB_8009ce50;
        }
      }
      else {
        if (puVar5 == (undefined *)0x8000000) {
          if (((_CHAR____800d5660 & 4) != 0) &&
             (*(int *)((int)pp_Var7[0x48] * 4 +
                       *(int *)(_CHAR____800d5664 * 4 + *(int *)(_PlayerData + 0x10)) + 4) != 0)) {
            if (_CHAR____800d5664 < 10) {
              mode = 0x100000;
            }
            else {
              if ((*gameTracker._4_4_ & 0x8000000f) == 0) goto LAB_8009ce50;
              mode = 0x100000;
            }
LAB_8009cdcc:
                    /* WARNING: Subroutine does not return */
            EnMessageQueueData((__MessageQueue *)In_01,mode,0);
          }
          if (_CHAR____800d5664 < 10) {
            if ((6 < _CHAR____800d5758) || ((_CHAR____800d55f0 & 0x40) == 0)) {
                    /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(1,0,(uint)_CHAR____800d565c[3],in_a3);
            }
            NewProcess = StateHandlerAutoFace;
          }
          else {
            if ((*gameTracker._4_4_ & 0x8000000f) == 0) {
              StateSwitchStateCharacterData(In,StateHandlerStopMove,0x3c);
              uVar6 = _BlockVramEntry_800d59a0._12_4_;
              goto LAB_8009ce50;
            }
            NewProcess = StateHandlerMove;
          }
          goto LAB_8009cbf0;
        }
        if (puVar5 == (undefined *)0x8000004) {
          if ((_CHAR____800d55f0 & 0x200) != 0) {
            instance = *(_Instance **)(_CHAR____800d55ec + 0x48);
            if (_CHAR____800d5600 != 0x1000) {
                    /* WARNING: Subroutine does not return */
              INSTANCE_Post(instance,0x100000c,0x20);
            }
            if (_CHAR____800d5648 != 6) {
                    /* WARNING: Subroutine does not return */
              INSTANCE_Post(instance,0x1000023,0x1000);
            }
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post(instance,0x100000c,0x20);
          }
          goto LAB_8009ce50;
        }
      }
    }
LAB_8009ce40:
    DefaultStateHandler(In,CurrentSection,Data);
    uVar6 = _BlockVramEntry_800d59a0._12_4_;
    goto LAB_8009ce50;
  }
  if (puVar5 != &DAT_00100001) {
    if ((int)puVar5 < 0x100002) {
      if (puVar5 == &DAT_80000020) {
        mode = StateHandlerDecodeHold(&local_40,&local_3c);
        uVar6 = _BlockVramEntry_800d59a0._12_4_;
        if (mode != 0) {
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData((__MessageQueue *)In_01,local_40,local_3c);
        }
        goto LAB_8009ce50;
      }
      if ((int)puVar5 < -0x7fffffdf) {
        if (puVar5 == (undefined *)0x80000000) goto LAB_8009c41c;
        if (puVar5 == (undefined *)0x80000001) {
          if (CurrentSection != 0) goto LAB_8009ce50;
          if ((_BlockVramEntry_800d59a0._12_4_ & 0x10000000) == 0) {
            In_01 = (__CharacterState *)&In->SectionList[0].Defer;
            mode = -0x7fffffff;
            goto LAB_8009cdcc;
          }
          _CHAR____800d5574 = 8;
          mode = razSwitchVAnimCharacterGroup(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
          if (mode != 0) {
            G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
          }
          StateSwitchStateCharacterData(In,StateHandlerCompression,0);
          uVar6 = 0xffffdfff;
          goto LAB_8009cdb0;
        }
      }
      else {
        if (puVar5 == (undefined *)0x80000) {
          _CHAR____800d57c4 = _CHAR____800d57c4 | 0x400;
          razSetPlayerEventHistory(0x400);
          StateSwitchStateData(In,CurrentSection,StateHandlerThrow2,0);
          uVar6 = _BlockVramEntry_800d59a0._12_4_;
          if (CurrentSection == 1) {
            razLaunchForce(In->CharacterInstance);
            uVar6 = _BlockVramEntry_800d59a0._12_4_;
          }
          goto LAB_8009ce50;
        }
        if (puVar5 == (undefined *)0x100000) {
          instance = (_Instance *)((int)&(pp_Var7[0x48]->node).prev + 1);
          pp_Var7[0x48] = instance;
          if (*(int *)((int)instance * 4 +
                      *(int *)(_CHAR____800d5664 * 4 + *(int *)(NewAnim + 0x10))) == 0) {
            pp_Var7[0x48] = (_Instance *)0x1;
          }
          _CHAR____800d565c =
               *(byte **)((int)pp_Var7[0x48] * 4 +
                         *(int *)(_CHAR____800d5664 * 4 + *(int *)(_PlayerData + 0x10)));
          G2EmulationSwitchAnimationAlpha
                    (In,CurrentSection,(uint)*_CHAR____800d565c,0,(uint)_CHAR____800d565c[1],1,
                     (uint)_CHAR____800d565c[2]);
          if (CurrentSection == 1) {
            startColor = *(long *)(_CHAR____800d565c + 0x14);
            endColor = *(long *)(_CHAR____800d565c + 0x18);
            p_Var4 = razGetHeldWeapon();
            instance = _CHAR____800d5668;
            if (p_Var4 != (_Instance *)0x0) {
              instance = razGetHeldWeapon();
                    /* WARNING: Subroutine does not return */
              INSTANCE_Query(instance,2);
            }
            _CHAR____800d5668 = (_Instance *)0x0;
            _CHAR____800d566c = instance;
            FX_StartRibbon(In->CharacterInstance,(ushort)_CHAR____800d565c[0xb],
                           (ushort)_CHAR____800d565c[0xc],0,(uint)_CHAR____800d565c[0xd],
                           (uint)_CHAR____800d565c[0xe],(int)*(short *)(_CHAR____800d565c + 0x12),
                           startColor,endColor);
          }
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(&In->SectionList[CurrentSection].Defer,(int)&DAT_00100002,0);
        }
      }
    }
    else {
      if (puVar5 == &DAT_00100015) {
        StateHandlerCannedReaction(In_00,mode,local_54);
        return;
      }
      if ((int)puVar5 < 0x100016) {
        if (puVar5 == &DAT_00100002) {
          _CHAR____800d5660 = 0;
          goto LAB_8009ce50;
        }
        if (puVar5 == &DAT_00100004) {
          if (CurrentSection == 1) {
            DisableWristCollision(In->CharacterInstance,2);
            DisableWristCollision(In->CharacterInstance,1);
            _CHAR____800d5608 = 0x100;
            _CHAR____800d560a = 0xffa0;
            instance = razGetHeldWeapon();
            if (instance != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
              INSTANCE_Post(instance,0x200005,0);
            }
          }
          uVar6 = 0xff7fffff;
LAB_8009cdb0:
          uVar6 = _BlockVramEntry_800d59a0._12_4_ & uVar6;
          goto LAB_8009ce50;
        }
      }
      else {
        if (puVar5 == (undefined *)0x800010) {
          NewProcess = StateHandlerThrow2;
LAB_8009cbf0:
          StateSwitchStateData(In,CurrentSection,NewProcess,0);
          uVar6 = _BlockVramEntry_800d59a0._12_4_;
          goto LAB_8009ce50;
        }
        if (puVar5 == (undefined *)0x1000001) goto LAB_8009ce50;
      }
    }
    goto LAB_8009ce40;
  }
  _CHAR____800d5664 = p_Var3->Data;
  pp_Var7[0x48] = (_Instance *)0x0;
  instance = razGetHeldWeapon();
  if (instance != (_Instance *)0x0) {
    if (_CHAR____800d5600 == 2) {
      _CHAR____800d5664 = p_Var3->Data + 2;
    }
    else {
      if (_CHAR____800d5600 < 3) {
        if (_CHAR____800d5600 == 1) {
          _CHAR____800d5664 = p_Var3->Data + 1;
        }
      }
      else {
        if (_CHAR____800d5600 == 3) {
          _CHAR____800d5664 = p_Var3->Data + 4;
        }
        else {
          if (_CHAR____800d5600 == 0x1000) {
            _CHAR____800d5664 = p_Var3->Data + 3;
          }
        }
      }
    }
  }
  _CHAR____800d565c =
       *(byte **)((int)pp_Var7[0x48] * 4 +
                 *(int *)(_CHAR____800d5664 * 4 + *(int *)(_PlayerData + 0x10)));
  if (p_Var3->Data < 10) {
    bVar1 = *_CHAR____800d565c;
    bVar2 = _CHAR____800d565c[1];
    local_54 = 1;
    mode = CurrentSection;
LAB_8009c1f8:
    G2EmulationSwitchAnimationAlpha
              (In,mode,(uint)bVar1,0,(uint)bVar2,local_54,(uint)_CHAR____800d565c[2]);
    if (CurrentSection == 1) {
      startColor = *(long *)(_CHAR____800d565c + 0x14);
      endColor = *(long *)(_CHAR____800d565c + 0x18);
      instance = razGetHeldWeapon();
      if (instance != (_Instance *)0x0) {
        instance = razGetHeldWeapon();
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query(instance,2);
      }
      FX_StartRibbon(In->CharacterInstance,(ushort)_CHAR____800d565c[0xb],
                     (ushort)_CHAR____800d565c[0xc],0,(uint)_CHAR____800d565c[0xd],
                     (uint)_CHAR____800d565c[0xe],(int)*(short *)(_CHAR____800d565c + 0x12),
                     startColor,endColor);
      if (p_Var3->Data < 10) {
        SteerSwitchMode(In->CharacterInstance,9);
      }
      else {
        if ((_CHAR____800d55f0 & 0x40) != 0) {
          SteerSwitchMode(In->CharacterInstance,0xf);
          SetTimer(4);
        }
      }
      _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x2000;
      if (p_Var3->Data == 5) {
        SetTimer(1);
      }
    }
  }
  else {
    if (CurrentSection == 1) {
      bVar1 = *_CHAR____800d565c;
      bVar2 = _CHAR____800d565c[1];
      mode = 1;
      local_54 = CurrentSection;
      goto LAB_8009c1f8;
    }
  }
  _CHAR____800d566c = (_Instance *)0x0;
  _CHAR____800d5668 = (_Instance *)0x0;
  _CHAR____800d5670 = (_FXGlowEffect *)0x0;
  _CHAR____800d5574 = _CHAR____800d5574 | 0x200000;
  uVar6 = _BlockVramEntry_800d59a0._12_4_;
LAB_8009ce50:
  _BlockVramEntry_800d59a0._12_4_ = uVar6;
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCannedReaction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 651, offset 0x8009cf38
	/* begin block 1 */
		// Start line: 652
		// Start offset: 0x8009CF38
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 694
			// Start offset: 0x8009D0F8
			// Variables:
		// 		struct _Instance *Inst; // $v0
		/* end block 1.1 */
		// End offset: 0x8009D114
		// End Line: 697

		/* begin block 1.2 */
			// Start line: 707
			// Start offset: 0x8009D11C
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009D18C
		// End Line: 724
	/* end block 1 */
	// End offset: 0x8009D1A8
	// End Line: 767

	/* begin block 2 */
		// Start line: 1341
	/* end block 2 */
	// End Line: 1342

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerCannedReaction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *weapon;
  int Data_00;
  undefined *puVar2;
  int in_a3;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100014) {
LAB_8009d0b8:
                    /* WARNING: Subroutine does not return */
    SetPhysicsWallCrawlData(0,0,3,in_a3);
  }
  if ((int)puVar2 < 0x100015) {
    if (puVar2 == &DAT_80000020) goto LAB_8009d198;
    if ((int)puVar2 < -0x7fffffdf) {
      if ((puVar2 == (undefined *)0x80000000) || (puVar2 == &DAT_80000008)) goto LAB_8009d198;
    }
    else {
      if (puVar2 == &DAT_00100001) {
        if (CurrentSection == 0) {
          _CHAR____800d5774 = 0x1194;
          _CHAR____800d5574 = 0x10000;
          _BlockVramEntry_800d59a0._12_4_ = 0x1041009;
          PhysicsMode.next = (_BlockVramEntry *)&UNK_00000003;
          SteerSwitchMode(In->CharacterInstance,0);
          (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5774;
        }
        goto LAB_8009d198;
      }
      if (puVar2 == &DAT_00100004) {
        if (CurrentSection == 1) {
          G2EmulationSwitchAnimationSync(In,2,1,4);
        }
        goto LAB_8009d198;
      }
    }
  }
  else {
    if (puVar2 == (undefined *)0x8000000) goto LAB_8009d0b8;
    if ((int)puVar2 < 0x8000001) {
      if (((int)puVar2 < 0x1000002) && (0xffffff < (int)puVar2)) goto LAB_8009d198;
    }
    else {
      if (puVar2 == (undefined *)0x8000003) {
        if ((CurrentSection == 0) && (weapon = razGetHeldItem(), (_CHAR____800d55f0 & 0x200) != 0))
        {
          Data_00 = SetMonsterImpaleData
                              (weapon,&In->CharacterInstance->rotation,
                               &In->CharacterInstance->position,0x208);
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x48),0x100000a,Data_00);
        }
        goto LAB_8009d198;
      }
      if (puVar2 == (undefined *)0x8000004) {
        weapon = razGetHeldItem();
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post(weapon,0x800008,2);
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009d198:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStumble(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*$s7*/)
 // line 770, offset 0x8009d1c8
	/* begin block 1 */
		// Start line: 771
		// Start offset: 0x8009D1C8
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 821
			// Start offset: 0x8009D500
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009D500
		// End Line: 823

		/* begin block 1.2 */
			// Start line: 831
			// Start offset: 0x8009D554
			// Variables:
		// 		struct evMonsterHitData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x8009D554
		// End Line: 832
	/* end block 1 */
	// End offset: 0x8009D5C0
	// End Line: 871

	/* begin block 2 */
		// Start line: 1609
	/* end block 2 */
	// End Line: 1610

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerStumble(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *p_Var2;
  int ticks;
  _Instance **pp_Var3;
  undefined *ID;
  int in_a3;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  ID = (undefined *)p_Var1->ID;
  if (ID == &DAT_00100001) {
    if (CurrentSection == 0) {
      _BlockVramEntry_800d59a0._12_4_ = 8;
      SetPhysics(In->CharacterInstance,-0x10,0,0,0);
      PhysicsMode.next = (_BlockVramEntry *)0x0;
      SteerSwitchMode(In->CharacterInstance,0);
      razResetMotion(In->CharacterInstance);
      if (p_Var1->Data == 0) {
        ticks = 1;
      }
      else {
        ticks = p_Var1->Data * 0x1e;
        if (ticks < 0) {
          ticks = ticks + 0xfff;
        }
        ticks = ticks >> 0xc;
      }
      SetTimer(ticks);
    }
                    /* WARNING: Subroutine does not return */
    G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x800);
  }
  if ((int)ID < 0x100002) {
    if (ID == (undefined *)0x0) {
      In->SectionList[CurrentSection].Data2 = 1;
      goto LAB_8009d5b0;
    }
    if ((int)ID < 1) {
      if (ID == &DAT_80000008) goto LAB_8009d5b0;
      if ((int)ID < -0x7ffffff7) {
        if (ID == (undefined *)0x80000000) goto LAB_8009d5b0;
      }
      else {
        if (ID == &DAT_80000020) goto LAB_8009d5b0;
      }
    }
    else {
      if (ID == &DAT_00040005) goto LAB_8009d5b0;
      if ((int)ID < 0x40006) {
        if (ID == &DAT_00040003) {
          if (CurrentSection == 0) {
            p_Var2 = (_Instance *)p_Var1->Data;
            G2EmulationInstanceToInstanceSwitchAnimationCharacter
                      (*(_Instance **)&p_Var2->node,*(_Instance **)((int)&p_Var2->node + 4),
                       (int)p_Var2->next,(int)p_Var2->prev,(int)p_Var2->instanceID,
                       (int)p_Var2->flags);
          }
          goto LAB_8009d5b0;
        }
      }
      else {
        if (ID == (undefined *)0x100000) {
          if (((*gameTracker._4_4_ & _lastData) != 0) && ((*gameTracker._4_4_ & LONG_800cf570) != 0)
             ) {
            _CHAR____800d571c = StateHandlerIdle;
                    /* WARNING: Subroutine does not return */
            SetPhysicsWallCrawlData(0,0,0xc,in_a3);
          }
                    /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0,0,0xc,in_a3);
        }
      }
    }
  }
  else {
    if (ID == (undefined *)0x1000000) {
      if ((theCamera.core._212_4_ & 0x800) != 0) {
                    /* WARNING: Subroutine does not return */
        LoseHealth(*(int *)(p_Var1->Data + 0xc));
      }
      goto LAB_8009d5b0;
    }
    if ((int)ID < 0x1000001) {
      if (ID == &DAT_00100009) goto LAB_8009d5b0;
      if ((int)ID < 0x10000a) {
        if (ID == &DAT_00100004) {
                    /* WARNING: Subroutine does not return */
          G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
        }
      }
      else {
        if (ID == &DAT_00100015) {
          ticks = STREAM_IsMorphInProgress();
          ID = (undefined *)0x100000;
          if (ticks != 0) {
            ID = &DAT_00100015;
          }
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData((__MessageQueue *)(&CHAR____800d52ac + CurrentSection * 0x11c),(int)ID,
                             0);
        }
      }
    }
    else {
      if (ID == (undefined *)0x2000000) goto LAB_8009d5b0;
      if ((int)ID < 0x2000001) {
        if (ID == (undefined *)0x1000001) goto LAB_8009d5b0;
      }
      else {
        if (ID == (undefined *)0x4000001) goto LAB_8009d5b0;
        if (ID == (undefined *)0x10000000) {
          pp_Var3 = &In->CharacterInstance + CurrentSection * 0x47;
          if (pp_Var3[0x48] == (_Instance *)0x1) {
            pp_Var3[0x48] = (_Instance *)0x0;
            pp_Var3[0x47] = (_Instance *)&pp_Var3[0x47][-1].oldPos.z;
          }
          goto LAB_8009d5b0;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009d5b0:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerHitReaction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 892, offset 0x8009d5ec
	/* begin block 1 */
		// Start line: 893
		// Start offset: 0x8009D5EC
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 902
			// Start offset: 0x8009D6D0
			// Variables:
		// 		struct evMonsterHitData *data; // $s0

			/* begin block 1.1.1 */
				// Start line: 906
				// Start offset: 0x8009D6DC
				// Variables:
			// 		struct _Instance *weapon; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8009D768
			// End Line: 927
		/* end block 1.1 */
		// End offset: 0x8009D7B0
		// End Line: 934
	/* end block 1 */
	// End offset: 0x8009D848
	// End Line: 969

	/* begin block 2 */
		// Start line: 1784
	/* end block 2 */
	// End Line: 1785

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerHitReaction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *instance;
  undefined *puVar2;
  code *NewProcess;
  int NewAnim;
  int in_a3;
  undefined4 *puVar3;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100001) {
    puVar3 = (undefined4 *)p_Var1->Data;
    if (CurrentSection == 0) {
      _CHAR____800d5674 = *puVar3;
      instance = razGetHeldWeapon();
      if (instance != (_Instance *)0x0) {
        TurnOffCollisionPhysOb(instance,7);
      }
      if ((theCamera.core._212_4_ & 0x800) != 0) {
                    /* WARNING: Subroutine does not return */
        LoseHealth(puVar3[3]);
      }
      PhysicsMode.next = (_BlockVramEntry *)0x0;
      _CHAR____800d5574 = _CHAR____800d5574 | 0x208000;
      _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xf7ffffff | 0x1008;
      ResetPhysics(In->CharacterInstance,-0x10);
      SteerSwitchMode(In->CharacterInstance,10);
    }
    if ((int)puVar3[3] < 0x1001) {
      NewAnim = 0x7d;
    }
    else {
      NewAnim = 0x38;
    }
                    /* WARNING: Subroutine does not return */
    G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,2,1);
  }
  if ((int)puVar2 < 0x100002) {
    if (((int)puVar2 < -0x7ffffffe) || (puVar2 == &DAT_80000020)) goto LAB_8009d838;
  }
  else {
    if (puVar2 == (undefined *)0x4020000) goto LAB_8009d838;
    if ((int)puVar2 < 0x4020001) {
      if (puVar2 == (undefined *)0x1000000) goto LAB_8009d838;
    }
    else {
      if (((int)puVar2 < 0x8000002) && (0x7ffffff < (int)puVar2)) {
        if (CurrentSection == 0) {
          if ((_BlockVramEntry_800d59a0._12_4_ & 0x100000) == 0) {
            if ((_CHAR____800d5574 & 0x40000) == 0) {
                    /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(0,0,3,in_a3);
            }
            NewProcess = StateHandlerSwim;
          }
          else {
            NewProcess = StateHandlerGlyphs;
          }
          StateSwitchStateCharacterData(In,NewProcess,0);
        }
        goto LAB_8009d838;
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009d838:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerThrow2(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 1049, offset 0x8009d868
	/* begin block 1 */
		// Start line: 1050
		// Start offset: 0x8009D868
		// Variables:
	// 		struct __Event *Ptr; // $a1
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 1193
			// Start offset: 0x8009DE6C
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x8009DE80
		// End Line: 1196

		/* begin block 1.2 */
			// Start line: 1271
			// Start offset: 0x8009E07C
			// Variables:
		// 		struct _Instance *weaponInst; // $s0

			/* begin block 1.2.1 */
				// Start line: 1275
				// Start offset: 0x8009E090
				// Variables:
			// 		int spin_type; // $a3

				/* begin block 1.2.1.1 */
					// Start line: 1289
					// Start offset: 0x8009E0E8
					// Variables:
				// 		struct _Position To; // stack offset -64
				// 		struct _Rotation Rot; // stack offset -56
				// 		struct MATRIX *matrix; // $v0
				/* end block 1.2.1.1 */
				// End offset: 0x8009E0E8
				// End Line: 1294
			/* end block 1.2.1 */
			// End offset: 0x8009E1B4
			// End Line: 1310
		/* end block 1.2 */
		// End offset: 0x8009E1E0
		// End Line: 1314

		/* begin block 1.3 */
			// Start line: 1361
			// Start offset: 0x8009E320
			// Variables:
		// 		struct _Position To; // stack offset -64
		// 		struct _Rotation Rot; // stack offset -48
		// 		struct MATRIX *matrix; // $v0
		/* end block 1.3 */
		// End offset: 0x8009E364
		// End Line: 1371
	/* end block 1 */
	// End offset: 0x8009E364
	// End Line: 1394

	/* begin block 2 */
		// Start line: 2098
	/* end block 2 */
	// End Line: 2099

/* WARNING: Removing unreachable block (ram,0x8009e008) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerThrow2(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short source;
  ushort uVar4;
  uint uVar5;
  __Event *Target;
  _Instance *instance;
  undefined *puVar6;
  _Instance *instance_00;
  char *target;
  int Data_00;
  _Position *Target_00;
  ushort type;
  _Rotation *Rot1;
  int NewAnim;
  code *Rot1_00;
  int in_a3;
  _Instance **pp_Var7;
  __State *p_Var8;
  int local_58;
  int Frames;
  int local_54;
  
  Rot1 = (_Rotation *)Data;
  uVar5 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var8 = In->SectionList + CurrentSection;
  instance_00 = (_Instance *)&p_Var8->Event;
  pp_Var7 = &In->CharacterInstance + CurrentSection * 0x47;
  instance = instance_00;
  Target = PeekMessageQueue((__MessageQueue *)instance_00);
  if (Target == (__Event *)0x0) {
    if ((CurrentSection == 1) && ((_CHAR____800d55f0 & 0x80) != 0)) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(*(_Instance **)(_CHAR____800d55ec + 0x38),0xc);
    }
    return;
  }
  puVar6 = (undefined *)Target->ID;
  if (puVar6 == (undefined *)0x1000000) {
    if (CurrentSection != 0) {
      PointAt(instance,(_Position *)Target,Rot1);
      return;
    }
    if ((_CHAR____800d5574 & 0x40000) != 0) {
      if ((theCamera.core._212_4_ & 0x800) == 0) {
        PointAt(instance,(_Position *)Target,Rot1);
        return;
      }
                    /* WARNING: Subroutine does not return */
      LoseHealth(*(int *)(Target->Data + 0xc));
    }
    if ((_BlockVramEntry_800d59a0._12_4_ & 0x4000) != 0) {
      PointAt(instance,(_Position *)Target,Rot1);
      return;
    }
    if (_CHAR____800d5618 != 0) {
      PointAt((_Instance *)In,(_Position *)Target,Rot1);
      return;
    }
    StateSwitchStateCharacterDataDefault(In,StateHandlerHitReaction,Target->Data);
    Target_00 = (_Position *)0x0;
    Rot1 = (_Rotation *)-*(int *)(_PlayerData + 0x28);
    razSetFadeEffect(In->CharacterInstance->fadeValue,0,(int)Rot1);
    instance = (_Instance *)&theCamera;
    CAMERA_ForceEndLookaroundMode((Camera *)&theCamera);
    PointAt(instance,Target_00,Rot1);
    return;
  }
  if ((int)puVar6 < 0x1000001) {
    if (puVar6 == (undefined *)0x100000) {
      if ((_CHAR____800d5574 & 0x40000) != 0) {
        Rot1_00 = StateHandlerSwim;
        StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
        PointAt((_Instance *)In,(_Position *)CurrentSection,(_Rotation *)Rot1_00);
        return;
      }
                    /* WARNING: Subroutine does not return */
      SetPhysicsWallCrawlData(0,0,(uint)_CHAR____800d5678[9],in_a3);
    }
    if ((int)puVar6 < 0x100001) {
      if (puVar6 == &DAT_80000008) {
        if (_CHAR____800d5688 == (_Instance *)0x0) {
          PointAt(instance_00,(_Position *)Target,Rot1);
          return;
        }
        Data_00 = 0x100000;
LAB_8009e06c:
                    /* WARNING: Subroutine does not return */
        EnMessageQueueData((__MessageQueue *)instance_00,Data_00,0);
      }
      if ((int)puVar6 < -0x7ffffff7) {
        if (puVar6 == (undefined *)0x80000000) {
          PointAt((_Instance *)In,(_Position *)Target,Rot1);
          return;
        }
      }
      else {
        if (puVar6 == &DAT_80000020) {
          PointAt((_Instance *)In,(_Position *)Target,Rot1);
          return;
        }
      }
    }
    else {
      if (puVar6 == &DAT_00100004) {
        Rot1 = (_Rotation *)&DAT_0000000e;
        instance = (_Instance *)&In->CharacterInstance->anim;
        G2Anim_InterpDisableController((_G2Anim_Type *)instance,0xe,0xe,300);
        if ((_CHAR____800d5730 & 2) != 0) {
          source = In->CharacterInstance->fadeValue;
          instance = (_Instance *)(int)source;
          Rot1 = (_Rotation *)-*(int *)(_PlayerData + 0x28);
          razSetFadeEffect(source,0,(int)Rot1);
        }
        if ((CurrentSection == 0) &&
           (instance = _CHAR____800d577c, _CHAR____800d577c != (_Instance *)0x0)) {
                    /* WARNING: Subroutine does not return */
          SndEndLoop((ulong)_CHAR____800d577c);
        }
        if (_CHAR____800d5600 == 8) {
          instance = razGetHeldItem();
                    /* WARNING: Subroutine does not return */
          INSTANCE_PlainDeath(instance);
        }
        if (_CHAR____800d5600 != 0x1000) {
          PointAt(instance,(_Position *)0x800000,Rot1);
          return;
        }
        Data_00 = 0x800105;
        instance = _CHAR____800d5644;
        goto LAB_8009df88;
      }
      if ((int)puVar6 < 0x100005) {
        if (puVar6 == &DAT_00100001) {
          if (CurrentSection == 0) {
            _BlockVramEntry_800d59a0._12_4_ = 0x41001;
            if ((_CHAR____800d5574 & 0x40000) == 0) {
              Target = (__Event *)0x0;
              SteerSwitchMode(In->CharacterInstance,0);
              _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 8;
            }
            else {
              Target = (__Event *)((int)&DAT_0000000a + 1);
              SteerSwitchMode(In->CharacterInstance,0xb);
            }
            PhysicsMode.next = (_BlockVramEntry *)&UNK_00000003;
            _CHAR____800d5574 = _CHAR____800d5574 | 0x20000;
            pp_Var7[0x47] = (_Instance *)0x0;
            instance = razGetHeldWeapon();
            if (instance != (_Instance *)0x0) {
              _CHAR____800d5688 = razGetHeldItem();
              Data_00 = _PlayerData;
              if (_CHAR____800d5600 == 3) {
                _CHAR____800d5678 = *(byte **)(*(int *)(_PlayerData + 0x14) + 8);
              }
              else {
                if (_CHAR____800d5600 < 4) {
                  if (_CHAR____800d5600 == 1) {
                    _CHAR____800d5678 = **(byte ***)(_PlayerData + 0x14);
                  }
                  else {
                    if (_CHAR____800d5600 == 2) {
                      _CHAR____800d5678 = *(byte **)(*(int *)(_PlayerData + 0x14) + 4);
                    }
                  }
                }
                else {
                  if (_CHAR____800d5600 == 8) {
                    pp_Var7[0x47] = (_Instance *)0x1;
                    _CHAR____800d5678 = *(byte **)(*(int *)(Data_00 + 0x14) + 0x10);
                    _CHAR____800d5688 = (_Instance *)0x0;
                  }
                  else {
                    Target = (__Event *)0x800000;
                    if (_CHAR____800d5600 == 0x1000) {
                      _CHAR____800d5688 = (_Instance *)0x0;
                      _CHAR____800d5678 = *(byte **)(*(int *)(_PlayerData + 0x14) + 0x14);
                    /* WARNING: Subroutine does not return */
                      INSTANCE_Post(_CHAR____800d5644,0x800104,0);
                    }
                  }
                }
              }
            }
            _CHAR____800d567c = 0;
          }
          if (CurrentSection == 2) {
            Data_00 = 2;
            if ((_CHAR____800d5574 & 0x40000) == 0) {
              Data_00 = 2;
              NewAnim = 0;
              Frames = 3;
            }
            else {
              NewAnim = 0x3d;
              Frames = 3;
            }
LAB_8009dce4:
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,Frames,CurrentSection);
          }
          if (((_CHAR____800d5574 & 0x40000) == 0) || (CurrentSection != 0)) {
            bVar1 = *_CHAR____800d5678;
            if (bVar1 == 0) {
              bVar1 = _CHAR____800d5678[3];
              bVar2 = _CHAR____800d5678[4];
              bVar3 = _CHAR____800d5678[5];
            }
            else {
              bVar2 = _CHAR____800d5678[1];
              bVar3 = _CHAR____800d5678[2];
            }
            Rot1 = (_Rotation *)(uint)bVar1;
            G2EmulationSwitchAnimationAlpha(In,CurrentSection,(int)Rot1,0,(uint)bVar2,1,(uint)bVar3)
            ;
            Target = (__Event *)CurrentSection;
          }
          else {
            if (uVar5 != 0x3f) {
              Data_00 = 0;
              NewAnim = 0x3f;
              Frames = 0x10;
              CurrentSection = 2;
              goto LAB_8009dce4;
            }
          }
          pp_Var7[0x48] = (_Instance *)0x1;
          PointAt((_Instance *)In,(_Position *)Target,Rot1);
          return;
        }
      }
      else {
        if (puVar6 == &DAT_00100009) {
          if (CurrentSection != 1) {
            PointAt((_Instance *)In,(_Position *)Target,Rot1);
            return;
          }
          if (Target->Data == 1) {
            if (_CHAR____800d5600 != 0x1000) {
              if (_CHAR____800d5600 == 8) {
                StateHandlerInitSwim(In,(int)Target,(int)Rot1);
                return;
              }
              source = In->CharacterInstance->fadeValue;
              In = (__CharacterState *)(int)source;
              Target = (__Event *)(int)*(short *)(_PlayerData + 0x24);
              Rot1 = (_Rotation *)(int)*(short *)(_PlayerData + 0x26);
              razSetFadeEffect(source,*(short *)(_PlayerData + 0x24),(int)Rot1);
            }
            _CHAR____800d571c = StateHandlerIdle;
            _CHAR____800d567c = 2;
            PointAt((_Instance *)In,(_Position *)Target,Rot1);
            return;
          }
          razSetFadeEffect(In->CharacterInstance->fadeValue,0,-(int)*(short *)(_PlayerData + 0x26));
          Target_00 = (_Position *)&DAT_0000000e;
          Rot1 = (_Rotation *)&DAT_0000000e;
          instance = (_Instance *)&In->CharacterInstance->anim;
          G2Anim_InterpDisableController((_G2Anim_Type *)instance,0xe,0xe,600);
          _CHAR____800d567c = 0;
          PointAt(instance,Target_00,Rot1);
          return;
        }
      }
    }
  }
  else {
    if (puVar6 == (undefined *)0x8000000) {
      _CHAR____800d567c = _CHAR____800d567c & 0xfffffffb;
      if (uVar5 == (uint)*_CHAR____800d5678) {
        if (((_CHAR____800d5574 & 0x40000) != 0) && (CurrentSection == 0)) {
          PointAt((_Instance *)In,(_Position *)Target,Rot1);
          return;
        }
        Rot1 = (_Rotation *)(uint)_CHAR____800d5678[3];
        G2EmulationSwitchAnimationAlpha
                  (In,CurrentSection,(int)Rot1,0,(uint)_CHAR____800d5678[4],1,
                   (uint)_CHAR____800d5678[5]);
        PointAt((_Instance *)In,(_Position *)CurrentSection,Rot1);
        return;
      }
      if (uVar5 != (uint)_CHAR____800d5678[6]) {
        PointAt(instance,(_Position *)Target,Rot1);
        return;
      }
      Data_00 = 0x100000;
      if (CurrentSection != 1) {
        PointAt(instance,(_Position *)&DAT_00100000,Rot1);
        return;
      }
      instance = In->CharacterInstance;
LAB_8009df88:
                    /* WARNING: Subroutine does not return */
      INSTANCE_Post(instance,Data_00,0);
    }
    if ((int)puVar6 < 0x8000001) {
      if (puVar6 == (undefined *)0x4000001) {
        if (CurrentSection == 0) {
          SetExternalForce((__Force *)In->CharacterInstance,0x5214,(short)Rot1,(short)in_a3,local_58
                           ,local_54);
        }
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0x24,0,4,1);
      }
      if ((int)puVar6 < 0x4000002) {
        if (puVar6 == (undefined *)0x1000001) {
          PointAt((_Instance *)In,(_Position *)Target,Rot1);
          return;
        }
      }
      else {
        if (puVar6 == (undefined *)0x4020000) {
          PointAt((_Instance *)In,(_Position *)Target,Rot1);
          return;
        }
      }
    }
    else {
      if (puVar6 == (undefined *)0x20000002) {
        PointAt(instance,(_Position *)Target,Rot1);
        return;
      }
      if ((int)puVar6 < 0x20000003) {
        if (puVar6 == (undefined *)0x8000004) {
          instance = razGetHeldWeapon();
          if (instance == (_Instance *)0x0) {
            PointAt((_Instance *)In,(_Position *)Target,Rot1);
            return;
          }
          if ((_CHAR____800d567c & 2) == 0) {
            if ((_CHAR____800d55f0 & 0x80) != 0) {
              Data_00 = SetObjectThrowData(*(void **)(_CHAR____800d55ec + 0x38),(_SVector *)0x0,1,
                                           (ushort)(*(short *)(_CHAR____800d5678 + 0x1e) != 0),
                                           (uint)*(ushort *)(_CHAR____800d5678 + 0x18),
                                           (int)*(short *)(_CHAR____800d5678 + 0x1a),0,0);
                    /* WARNING: Subroutine does not return */
              INSTANCE_Post(instance,0x800010,Data_00);
            }
            target = (char *)0x0;
            uVar4 = *(ushort *)(_CHAR____800d5678 + 0x18);
            type = 0;
            Data_00 = 0;
          }
          else {
            target = &CHAR____800d5680;
            uVar4 = *(ushort *)(_CHAR____800d5678 + 0x18);
            Data_00 = (int)*(short *)(_CHAR____800d5678 + 0x1a);
            type = 4;
          }
          Data_00 = SetObjectThrowData(target,(_SVector *)0x0,type,
                                       (ushort)(*(short *)(_CHAR____800d5678 + 0x1e) != 0),
                                       (uint)uVar4,Data_00,0,0);
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(instance,0x800010,Data_00);
        }
      }
      else {
        if (puVar6 == (undefined *)0x20000020) {
          if (pp_Var7[0x48] == (_Instance *)0x0) {
            PointAt((_Instance *)In,(_Position *)Target,Rot1);
            return;
          }
          instance_00 = (_Instance *)&p_Var8->Defer;
          if (uVar5 == (uint)_CHAR____800d5678[3]) {
            if (((_CHAR____800d5574 & 0x40000) != 0) && (CurrentSection == 0)) {
              pp_Var7[0x48] = (_Instance *)0x0;
              if ((_CHAR____800d57c4 & 0x200) == 0) {
                PointAt((_Instance *)In,(_Position *)Target,Rot1);
                return;
              }
              instance = (_Instance *)&UNK_00000200;
              razSetPlayerEventHistory(0x200);
              PointAt(instance,(_Position *)Target,Rot1);
              return;
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation
                      (In,CurrentSection,(uint)_CHAR____800d5678[6],0,(uint)_CHAR____800d5678[7],1);
          }
          Data_00 = 0x20000020;
          goto LAB_8009e06c;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var8->Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PointAt(struct _Instance *instance /*$s0*/, struct _Position *Target /*$s1*/, struct _Rotation *Rot1 /*$s2*/)
 // line 1395, offset 0x8009e390
	/* begin block 1 */
		// Start line: 1396
		// Start offset: 0x8009E390
		// Variables:
	// 		struct _Position From; // stack offset -48
	// 		struct SVECTOR v1; // stack offset -40
	// 		struct VECTOR v3; // stack offset -32
	// 		struct MATRIX *tempMat; // $a0
	/* end block 1 */
	// End offset: 0x8009E47C
	// End Line: 1428

	/* begin block 2 */
		// Start line: 2822
	/* end block 2 */
	// End Line: 2823

	/* begin block 3 */
		// Start line: 2830
	/* end block 3 */
	// End Line: 2831

void PointAt(int param_1)

{
  undefined2 local_28;
  undefined2 local_26;
  undefined2 uStack36;
  undefined auStack32 [16];
  
  local_28 = *(undefined2 *)(iGpfffffbc4 + 10);
  local_26 = *(undefined2 *)(iGpfffffbc4 + 0xc);
  uStack36 = *(undefined2 *)(iGpfffffbc4 + 0xe);
                    /* WARNING: Subroutine does not return */
  ApplyMatrix(*(undefined4 *)(param_1 + 0x40),&local_28,auStack32);
}



// decompiled code
// original method signature: 
// void /*$ra*/ ThrowSetFocusPoint(struct _Instance *instance /*$s4*/, struct _Rotation *rot /*$s2*/)
 // line 1433, offset 0x8009e4b0
	/* begin block 1 */
		// Start line: 1434
		// Start offset: 0x8009E4B0
		// Variables:
	// 		struct MATRIX *pTempMat; // $s0
	// 		struct _Instance *weaponInstance; // $s1
	// 		struct SVECTOR v1; // stack offset -48
	// 		struct VECTOR v4; // stack offset -40
	/* end block 1 */
	// End offset: 0x8009E5D0
	// End Line: 1480

	/* begin block 2 */
		// Start line: 2933
	/* end block 2 */
	// End Line: 2934

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ThrowSetFocusPoint(_Instance *instance,_Rotation *rot)

{
  undefined4 uVar1;
  _Instance *p_Var2;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined local_28 [16];
  
  rot->x = -rot->x;
  uVar1 = DAT_800cff04;
  p_Var2 = razGetHeldWeapon();
  if ((p_Var2 != (_Instance *)0x0) && (p_Var2->matrix != (MATRIX *)0x0)) {
    local_30 = 0;
    local_2e = 0;
    local_2c = *(undefined2 *)(_CHAR____800d5678 + 0x18);
                    /* WARNING: Subroutine does not return */
    ApplyMatrix(uVar1,&local_30,local_28);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LimitRotation(struct _Rotation *rot /*$a1*/)
 // line 1481, offset 0x8009e5f0
	/* begin block 1 */
		// Start line: 3047
	/* end block 1 */
	// End Line: 3048

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void LimitRotation(_Rotation *rot)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  rot->z = rot->z & 0xfff;
  iVar5 = (int)rot->z;
  rot->x = rot->x & 0xfff;
  iVar4 = iVar5;
  while (0x1000 < iVar4) {
    iVar5 = iVar5 + -0x1000;
    rot->z = (short)iVar5;
    iVar4 = iVar5 * 0x10000 >> 0x10;
  }
  sVar1 = rot->z;
  sVar3 = rot->z + 0x1000;
  if (sVar1 < 1) {
    rot->z = sVar3;
    bVar2 = sVar3 < *(short *)(_CHAR____800d5678 + 0x16);
    sVar3 = *(short *)(_CHAR____800d5678 + 0x16);
  }
  else {
    if (sVar1 < 0x800) {
      sVar3 = *(short *)(_CHAR____800d5678 + 0x14);
      bVar2 = *(short *)(_CHAR____800d5678 + 0x14) < sVar1;
    }
    else {
      sVar3 = *(short *)(_CHAR____800d5678 + 0x16);
      bVar2 = sVar1 < *(short *)(_CHAR____800d5678 + 0x16);
    }
  }
  if (bVar2) {
    rot->z = sVar3;
  }
  iVar5 = (int)rot->x;
  iVar4 = iVar5;
  while (0x1000 < iVar4) {
    iVar5 = iVar5 + -0x1000;
    rot->x = (short)iVar5;
    iVar4 = iVar5 * 0x10000 >> 0x10;
  }
  sVar1 = rot->x;
  sVar3 = rot->x + 0x1000;
  if (sVar1 < 1) {
    rot->x = sVar3;
    bVar2 = sVar3 < *(short *)(_CHAR____800d5678 + 0x12);
    sVar3 = *(short *)(_CHAR____800d5678 + 0x12);
  }
  else {
    if (sVar1 < 0x800) {
      sVar3 = *(short *)(_CHAR____800d5678 + 0x10);
      bVar2 = *(short *)(_CHAR____800d5678 + 0x10) < sVar1;
    }
    else {
      sVar3 = *(short *)(_CHAR____800d5678 + 0x12);
      bVar2 = sVar1 < *(short *)(_CHAR____800d5678 + 0x12);
    }
  }
  if (bVar2) {
    rot->x = sVar3;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerGrab(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*$s7*/)
 // line 1541, offset 0x8009e764
	/* begin block 1 */
		// Start line: 1542
		// Start offset: 0x8009E764
		// Variables:
	// 		struct __Event *Ptr; // $s2
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 1575
			// Start offset: 0x8009E9B0
			// Variables:
		// 		struct _Instance *Inst; // $a1
		/* end block 1.1 */
		// End offset: 0x8009EA00
		// End Line: 1586

		/* begin block 1.2 */
			// Start line: 1612
			// Start offset: 0x8009EA70
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009EA8C
		// End Line: 1631

		/* begin block 1.3 */
			// Start line: 1718
			// Start offset: 0x8009EC64
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.3 */
		// End offset: 0x8009ED24
		// End Line: 1751

		/* begin block 1.4 */
			// Start line: 1758
			// Start offset: 0x8009ED3C
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.4 */
		// End offset: 0x8009ED9C
		// End Line: 1771

		/* begin block 1.5 */
			// Start line: 1778
			// Start offset: 0x8009EDFC
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.5 */
		// End offset: 0x8009EE5C
		// End Line: 1793
	/* end block 1 */
	// End offset: 0x8009EED0
	// End Line: 1825

	/* begin block 2 */
		// Start line: 3171
	/* end block 2 */
	// End Line: 3172

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerGrab(__CharacterState *In,int CurrentSection,int Data)

{
  uint local_30;
  __Event *p_Var1;
  _Instance *instance;
  int Data_00;
  undefined *puVar2;
  uint NewAnim;
  int in_a3;
  int local_2c;
  
  local_30 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100015) {
    if (CurrentSection == 0) {
      if (local_30 == (uint)*_CHAR____800d5678) {
        if ((_CHAR____800d55f0 & 0x100) != 0) {
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x40),0x1000002,
                        (int)In->CharacterInstance);
        }
      }
      else {
        instance = razGetHeldItem();
        if (instance != (_Instance *)0x0) {
LAB_8009ecd4:
          theCamera.positionAccl._4_4_ = theCamera.positionAccl._4_4_ | 4;
          Data_00 = SetMonsterThrownData(In->CharacterInstance,&In->CharacterInstance->rotation,100)
          ;
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(instance,0x1000003,Data_00);
        }
        razReaverOn();
      }
    }
    goto LAB_8009eec0;
  }
  if ((int)puVar2 < 0x100016) {
    if (puVar2 == (undefined *)0x0) {
      if ((((CurrentSection == 0) && (local_30 != (uint)*_CHAR____800d5678)) && (local_30 != 0x47))
         && ((local_30 != (uint)_CHAR____800d5678[6] &&
             (SteerSwitchMode(In->CharacterInstance,0), local_30 == 1)))) {
        Data_00 = 0x37;
LAB_8009eb40:
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,0,Data_00,0,3,2);
      }
      goto LAB_8009eec0;
    }
    if ((int)puVar2 < 1) {
      if (puVar2 == &DAT_80000008) goto LAB_8009eec0;
      if ((int)puVar2 < -0x7ffffff7) {
        if (puVar2 == (undefined *)0x80000000) goto LAB_8009eec0;
      }
      else {
        if (puVar2 == &DAT_80000020) goto LAB_8009eec0;
      }
    }
    else {
      if (puVar2 == &DAT_00100004) {
        instance = razGetHeldItem();
        if (instance != (_Instance *)0x0) goto LAB_8009ecd4;
        goto LAB_8009eec0;
      }
      if ((int)puVar2 < 0x100005) {
        if (puVar2 == &DAT_00100001) {
          if (CurrentSection == 0) {
            _CHAR____800d5678 = *(byte **)(*(int *)(_PlayerData + 0x14) + 0x18);
            _BlockVramEntry_800d59a0._12_4_ = 0x1043009;
            PhysicsMode.next = (_BlockVramEntry *)&UNK_00000003;
            SteerSwitchMode(In->CharacterInstance,0);
          }
          if (p_Var1->Data != 0) {
            razSetPlayerEventHistory(0x40);
            if (CurrentSection == 2) {
              NewAnim = 0;
              local_30 = 3;
              Data_00 = 2;
              local_2c = CurrentSection;
            }
            else {
              NewAnim = (uint)*_CHAR____800d5678;
              local_30 = (uint)_CHAR____800d5678[1];
              local_2c = 1;
              Data_00 = CurrentSection;
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_30,local_2c);
          }
          if ((CurrentSection == 0) &&
             (G2EmulationSwitchAnimationCharacter(In,0x47,0,(uint)_CHAR____800d5678[1],1),
             (_CHAR____800d55f0 & 0x100) != 0)) {
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post(*(_Instance **)(_CHAR____800d55ec + 0x40),0x1000002,0);
          }
          (&In->CharacterInstance + CurrentSection * 0x47)[0x48] = (_Instance *)0xd;
          (&In->CharacterInstance + CurrentSection * 0x47)[0x47] = (_Instance *)0x0;
          goto LAB_8009eec0;
        }
      }
      else {
        if (puVar2 == &DAT_00100014) {
          if ((CurrentSection == 0) && (instance = razGetHeldItem(), instance != (_Instance *)0x0))
          {
            theCamera.positionAccl._4_4_ = theCamera.positionAccl._4_4_ | 4;
            Data_00 = SetMonsterThrownData
                                (In->CharacterInstance,&In->CharacterInstance->rotation,10);
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post(instance,0x1000003,Data_00);
          }
LAB_8009ed9c:
                    /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0,0,(uint)_CHAR____800d5678[9],in_a3);
        }
      }
    }
  }
  else {
    if (puVar2 == (undefined *)0x4010080) {
      if (CurrentSection == 0) {
        if (p_Var1->Data == 0) {
          razSetPauseTranslation(In->CharacterInstance);
        }
        else {
          razResetPauseTranslation(In->CharacterInstance);
        }
      }
    }
    else {
      if ((int)puVar2 < 0x4010081) {
        if (puVar2 == (undefined *)0x1000001) goto LAB_8009eec0;
        if ((int)puVar2 < 0x1000002) {
          if (puVar2 == (undefined *)0x1000000) {
            if (((CurrentSection == 0) && ((_BlockVramEntry_800d59a0._12_4_ & 0x4000) == 0)) &&
               (_CHAR____800d5618 == 0)) {
              instance = razGetHeldItem();
              if (instance != (_Instance *)0x0) {
                theCamera.positionAccl._4_4_ = theCamera.positionAccl._4_4_ | 4;
                Data_00 = SetMonsterThrownData
                                    (In->CharacterInstance,&In->CharacterInstance->rotation,10);
                    /* WARNING: Subroutine does not return */
                INSTANCE_Post(instance,0x1000003,Data_00);
              }
              instance = razGetHeldItem();
              if (instance != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
                INSTANCE_UnlinkFromParent(instance);
              }
              StateSwitchStateCharacterData(In,StateHandlerHitReaction,p_Var1->Data);
            }
            goto LAB_8009eec0;
          }
        }
        else {
          if (puVar2 == (undefined *)0x1000006) goto LAB_8009ed9c;
        }
      }
      else {
        if (puVar2 == (undefined *)0x8000000) {
          if (CurrentSection == 0) {
            if (In->SectionList[0].Data2 != 0xb) {
                    /* WARNING: Subroutine does not return */
              SetPhysicsWallCrawlData(0,0,3,in_a3);
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,0,0x37,0,3,2);
          }
          goto LAB_8009eec0;
        }
        if ((int)puVar2 < 0x8000001) {
          if (puVar2 == (undefined *)0x4020000) goto LAB_8009eec0;
        }
        else {
          if (puVar2 == (undefined *)0x10000000) {
            if ((((CurrentSection == 0) && (local_30 != (uint)*_CHAR____800d5678)) &&
                (local_30 != 0x47)) &&
               ((local_30 != (uint)_CHAR____800d5678[6] &&
                (SteerSwitchMode(In->CharacterInstance,0x12), local_30 == 0x37)))) {
              Data_00 = 1;
              goto LAB_8009eb40;
            }
            goto LAB_8009eec0;
          }
          if (puVar2 == (undefined *)0x20000020) {
            if (CurrentSection == 0) {
              if (In->SectionList[0].Data1 == 0) {
                    /* WARNING: Subroutine does not return */
                EnMessageQueueData(&In->SectionList[0].Defer,0x20000020,0);
              }
              if (In->SectionList[0].Data2 != 0xc) {
                G2EmulationSwitchAnimationCharacter
                          (In,(uint)_CHAR____800d5678[6],0,(uint)_CHAR____800d5678[7],1);
                    /* WARNING: Subroutine does not return */
                PurgeMessageQueue(&In->SectionList[0].Event);
              }
            }
            goto LAB_8009eec0;
          }
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009eec0:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}





