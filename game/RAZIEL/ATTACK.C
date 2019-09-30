#include "THISDUST.H"
#include "ATTACK.H"


// decompiled code
// original method signature: 
// int /*$ra*/ StateHandlerDecodeHold(int *Message /*$s3*/, int *Data /*$s4*/)
 // line 16, offset 0x8009b184
	/* begin block 1 */
		// Start line: 17
		// Start offset: 0x8009B184
		// Variables:
	// 		int rc; // $s2
	// 		int WhoAmI; // $s0
	// 		struct _Instance *heldInstance; // $s1

		/* begin block 1.1 */
			// Start line: 53
			// Start offset: 0x8009B2B0
			// Variables:
		// 		int hitState; // $v1
		/* end block 1.1 */
		// End offset: 0x8009B39C
		// End Line: 87

		/* begin block 1.2 */
			// Start line: 109
			// Start offset: 0x8009B404
			// Variables:
		// 		struct _Instance *heldWeapon; // $v1
		/* end block 1.2 */
		// End offset: 0x8009B468
		// End Line: 129
	/* end block 1 */
	// End offset: 0x8009B494
	// End Line: 139

	/* begin block 2 */
		// Start line: 32
	/* end block 2 */
	// End Line: 33

/* WARNING: Removing unreachable block (ram,0x8009b250) */
/* WARNING: Removing unreachable block (ram,0x8009b274) */
/* WARNING: Removing unreachable block (ram,0x8009b264) */

int StateHandlerDecodeHold(int *Message,int *Data)

{
  _Instance *p_Var1;
  int iVar2;
  
  iVar2 = 1;
  p_Var1 = razGetHeldWeapon();
  if (Raziel.CurrentPlane == 2) {
    *Data = 1;
    *Message = -0x80000000;
    if ((Raziel.Senses.EngagedMask & 0x200) != 0) {
      return 1;
    }
    if (Raziel.Senses.heldClass != 0x1000) {
      return 0;
    }
    if ((Raziel.Abilities & 4U) == 0) {
      return 0;
    }
    *Message = 0x800010;
    return 1;
  }
  if ((Raziel.Senses.EngagedMask & 0x200) != 0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Raziel.Senses.EngagedList[9].instance,1);
  }
  if (((((Raziel.Senses.EngagedMask & 0x200) != 0) && (p_Var1 != (_Instance *)0x0)) &&
      (Raziel.Senses.heldClass != 3)) && (Raziel.Senses.heldClass != 8)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Raziel.Senses.EngagedList[9].instance,0);
  }
  if (((Raziel.Senses.EngagedMask & 0x100) != 0) && (p_Var1 == (_Instance *)0x0)) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query(Raziel.Senses.EngagedList[8].instance,0);
  }
  p_Var1 = razGetHeldWeapon();
  if (p_Var1 == (_Instance *)0x0) {
    if ((Raziel.Abilities & 4U) != 0) {
      *Message = 0x80000;
      goto LAB_8009b468;
    }
  }
  else {
    if ((p_Var1 != Raziel.soulReaver) || ((Raziel.Abilities & 4U) != 0)) {
      *Message = 0x800010;
      goto LAB_8009b468;
    }
  }
  iVar2 = 0;
LAB_8009b468:
  if (Raziel.Senses.heldClass != 3) {
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
 // line 149, offset 0x8009b4b4
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x8009B4B4
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		int message; // stack offset -64
	// 		int messageData; // stack offset -60
	// 		int Frame; // stack offset -56
	// 		int Anim; // stack offset -52

		/* begin block 1.1 */
			// Start line: 208
			// Start offset: 0x8009B804
			// Variables:
		// 		struct _Instance *inst; // $s0
		// 		unsigned long startColor; // $s3
		// 		unsigned long endColor; // $s2
		/* end block 1.1 */
		// End offset: 0x8009B930
		// End Line: 249

		/* begin block 1.2 */
			// Start line: 348
			// Start offset: 0x8009BC94
			// Variables:
		// 		struct _Instance *inst; // $s0
		// 		unsigned long startColor; // $s2
		// 		unsigned long endColor; // $s1
		/* end block 1.2 */
		// End offset: 0x8009BD78
		// End Line: 380

		/* begin block 1.3 */
			// Start line: 427
			// Start offset: 0x8009BECC
			// Variables:
		// 		struct _Instance *Inst; // $a0
		/* end block 1.3 */
		// End offset: 0x8009BF0C
		// End Line: 437

		/* begin block 1.4 */
			// Start line: 455
			// Start offset: 0x8009BF9C
		/* end block 1.4 */
		// End offset: 0x8009BF9C
		// End Line: 456

		/* begin block 1.5 */
			// Start line: 478
			// Start offset: 0x8009C050
		/* end block 1.5 */
		// End offset: 0x8009C098
		// End Line: 485

		/* begin block 1.6 */
			// Start line: 505
			// Start offset: 0x8009C124
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.6 */
		// End offset: 0x8009C1F0
		// End Line: 518

		/* begin block 1.7 */
			// Start line: 538
			// Start offset: 0x8009C2A4
			// Variables:
		// 		struct evMonsterHitData *hitData; // $s0
		/* end block 1.7 */
		// End offset: 0x8009C2BC
		// End Line: 543

		/* begin block 1.8 */
			// Start line: 562
			// Start offset: 0x8009C334
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v1
		/* end block 1.8 */
		// End offset: 0x8009C398
		// End Line: 569
	/* end block 1 */
	// End offset: 0x8009C398
	// End Line: 572

	/* begin block 2 */
		// Start line: 305
	/* end block 2 */
	// End Line: 306

/* WARNING: Type propagation algorithm not settling */

void StateHandlerAttack2(__CharacterState *In,int CurrentSection,int Data)

{
  RazielData *pRVar1;
  __Event *p_Var2;
  _Instance *p_Var3;
  undefined *puVar4;
  _Instance *Inst;
  __MessageQueue *In_00;
  int CurrentSection_00;
  _Instance **pp_Var5;
  int NewAnim;
  code *NewProcess;
  ulong endColor;
  ulong startColor;
  int local_58;
  int local_54;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  __State *local_30;
  
  local_38 = G2EmulationQueryFrame(In,CurrentSection);
  local_34 = G2EmulationQueryAnimation(In,CurrentSection);
  if (((CurrentSection == 0) && ((ControlFlag & 0x10000000U) != 0)) && ((Raziel.Mode & 2U) == 0)) {
    CurrentSection_00 = 2;
    if ((*PadData & 0x8000000fU) == 0) {
      Inst = In->CharacterInstance;
      CurrentSection_00 = 0;
    }
    else {
      Inst = In->CharacterInstance;
    }
                    /* WARNING: Subroutine does not return */
    SteerSwitchMode(Inst,CurrentSection_00);
  }
  local_30 = In->SectionList + CurrentSection;
  In_00 = &local_30->Event;
  p_Var2 = PeekMessageQueue(In_00);
  pRVar1 = PlayerData;
  if (p_Var2 == (__Event *)0x0) {
    if (((Raziel.attackFlags & 4U) != 0) &&
       ((int)((uint)(Raziel.attack)->switchDelay * 100) <=
        (int)(In->CharacterInstance->anim).section[CurrentSection & 0xff].elapsedTime)) {
                    /* WARNING: Subroutine does not return */
      EnMessageQueueData(&In->SectionList[CurrentSection].Event,0x100000,0);
    }
    return;
  }
  puVar4 = (undefined *)p_Var2->ID;
  if (puVar4 == (undefined *)0x1000002) {
    if (Raziel.CurrentPlane == 1) {
                    /* WARNING: Subroutine does not return */
      StateSwitchStateData(In,CurrentSection,StateHandlerGrab,local_3c);
    }
    goto LAB_8009c30c;
  }
  if ((int)puVar4 < 0x1000003) {
    if (puVar4 == (undefined *)0x100000) {
      pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
      Inst = (_Instance *)((int)&(pp_Var5[0x48]->node).prev + 1);
      pp_Var5[0x48] = Inst;
      if (*(int *)(&((__AttackItem *)pRVar1->attackList[Raziel.currentAttack])->anim + (int)Inst * 4
                  ) == 0) {
        pp_Var5[0x48] = (_Instance *)0x1;
      }
      Raziel.attack =
           *(__AttackItem **)
            (&((__AttackItem *)PlayerData->attackList[Raziel.currentAttack])->anim +
            (int)pp_Var5[0x48] * 4);
      G2EmulationSwitchAnimationAlpha
                (In,CurrentSection,(uint)(Raziel.attack)->anim,0,(uint)(Raziel.attack)->framesIn,1,
                 (uint)(Raziel.attack)->alphaIn);
      if (CurrentSection == 1) {
        startColor = (Raziel.attack)->ribbonStartColor;
        endColor = (Raziel.attack)->ribbonEndColor;
        p_Var3 = razGetHeldWeapon();
        Inst = Raziel.attackCurrentHit;
        if (p_Var3 != (_Instance *)0x0) {
          Inst = razGetHeldWeapon();
                    /* WARNING: Subroutine does not return */
          INSTANCE_Query(Inst,2);
        }
        Raziel.attackCurrentHit = (_Instance *)0x0;
        Raziel.attackLastHit = Inst;
        FX_StartRibbon(In->CharacterInstance,(ushort)(Raziel.attack)->ribbonStartSegment,
                       (ushort)(Raziel.attack)->ribbonEndSegment,0,
                       (uint)(Raziel.attack)->ribbonLifeTime,
                       (uint)(Raziel.attack)->ribbonFaceLifeTime,
                       (int)(short)(Raziel.attack)->ribbonStartOpacity,startColor,endColor);
      }
                    /* WARNING: Subroutine does not return */
      EnMessageQueueData(&local_30->Defer,(int)&DAT_00100002,0);
    }
    if ((int)puVar4 < 0x100001) {
      if (puVar4 == (undefined *)0x80000001) {
        if (CurrentSection == 0) {
          if ((ControlFlag & 0x10000000U) == 0) {
            In_00 = &In->SectionList[0].Defer;
            CurrentSection_00 = -0x7fffffff;
            goto LAB_8009c28c;
          }
          Raziel.Mode = 8;
          CurrentSection_00 =
               razSwitchVAnimCharacterGroup(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
          if (CurrentSection_00 != 0) {
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
          }
          StateSwitchStateCharacterData(In,StateHandlerCompression,0);
          ControlFlag = ControlFlag & 0xffffdfff;
        }
        goto LAB_8009c30c;
      }
      if ((int)puVar4 < -0x7fffffff) goto LAB_8009b994;
      if (puVar4 == &DAT_80000020) {
        CurrentSection_00 = StateHandlerDecodeHold(&local_40,&local_3c);
        if (CurrentSection_00 != 0) {
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(In_00,local_40,local_3c);
        }
        goto LAB_8009c30c;
      }
      if (puVar4 == (undefined *)0x80000) {
        Raziel.playerEvent = Raziel.playerEvent | 0x400;
        razSetPlayerEventHistory(0x400);
                    /* WARNING: Subroutine does not return */
        StateSwitchStateData(In,CurrentSection,StateHandlerThrow2,0);
      }
    }
    else {
      if (puVar4 == &DAT_00100004) {
        if (CurrentSection == 1) {
          DisableWristCollision(In->CharacterInstance,2);
          DisableWristCollision(In->CharacterInstance,1);
          Raziel.dropOffHeight = 0x100;
          Raziel.fallZVelocity = -0x60;
        }
        Raziel.Mode = Raziel.Mode & 0xffdfffff;
        goto LAB_8009c30c;
      }
      if ((int)puVar4 < 0x100005) {
        if (puVar4 == &DAT_00100001) {
          Raziel.currentAttack = p_Var2->Data;
          In->SectionList[CurrentSection].Data2 = 0;
          Inst = razGetHeldWeapon();
          if (Inst != (_Instance *)0x0) {
            if (Raziel.Senses.heldClass == 2) {
              Raziel.currentAttack = p_Var2->Data + 2;
            }
            else {
              if (Raziel.Senses.heldClass < 3) {
                if (Raziel.Senses.heldClass == 1) {
                  Raziel.currentAttack = p_Var2->Data + 1;
                }
              }
              else {
                if (Raziel.Senses.heldClass == 3) {
                  Raziel.currentAttack = p_Var2->Data + 4;
                }
                else {
                  if (Raziel.Senses.heldClass == 0x1000) {
                    Raziel.currentAttack = p_Var2->Data + 3;
                  }
                }
              }
            }
          }
          Raziel.attack =
               *(__AttackItem **)
                (&((__AttackItem *)PlayerData->attackList[Raziel.currentAttack])->anim +
                In->SectionList[CurrentSection].Data2 * 4);
          G2EmulationSwitchAnimationAlpha
                    (In,CurrentSection,(uint)(Raziel.attack)->anim,0,(uint)(Raziel.attack)->framesIn
                     ,1,(uint)(Raziel.attack)->alphaIn);
          if (CurrentSection == 1) {
            startColor = (Raziel.attack)->ribbonStartColor;
            endColor = (Raziel.attack)->ribbonEndColor;
            Inst = razGetHeldWeapon();
            if (Inst != (_Instance *)0x0) {
              Inst = razGetHeldWeapon();
                    /* WARNING: Subroutine does not return */
              INSTANCE_Query(Inst,2);
            }
            FX_StartRibbon(In->CharacterInstance,(ushort)(Raziel.attack)->ribbonStartSegment,
                           (ushort)(Raziel.attack)->ribbonEndSegment,0,
                           (uint)(Raziel.attack)->ribbonLifeTime,
                           (uint)(Raziel.attack)->ribbonFaceLifeTime,
                           (int)(short)(Raziel.attack)->ribbonStartOpacity,startColor,endColor);
            CurrentSection_00 = 9;
            if (p_Var2->Data < 10) {
              Inst = In->CharacterInstance;
LAB_8009b918:
                    /* WARNING: Subroutine does not return */
              SteerSwitchMode(Inst,CurrentSection_00);
            }
            CurrentSection_00 = 0xf;
            if ((Raziel.Senses.EngagedMask & 0x40) != 0) {
              Inst = In->CharacterInstance;
              goto LAB_8009b918;
            }
            ControlFlag = ControlFlag | 0x2000;
          }
          Raziel.attackLastHit = (_Instance *)0x0;
          Raziel.attackCurrentHit = (_Instance *)0x0;
          Raziel.glowEffect = (_FXGlowEffect *)0x0;
          Raziel.Mode = Raziel.Mode | 0x200000;
          goto LAB_8009c30c;
        }
        if (puVar4 == &DAT_00100002) {
          Raziel.attackFlags = 0;
          goto LAB_8009c30c;
        }
      }
      else {
        if (puVar4 == (undefined *)0x800010) {
          NewProcess = StateHandlerThrow2;
          goto LAB_8009c0c0;
        }
        if (puVar4 == (undefined *)0x1000001) goto LAB_8009c30c;
      }
    }
  }
  else {
    if (puVar4 == (undefined *)0x2000000) {
LAB_8009b994:
      Raziel.attack =
           *(__AttackItem **)
            (&((__AttackItem *)PlayerData->attackList[Raziel.currentAttack])->anim +
            In->SectionList[CurrentSection].Data2 * 4);
      if ((local_34 == (uint)(Raziel.attack)->anim) &&
         ((int)(uint)(Raziel.attack)->ignoreDelay <= local_38)) {
        Raziel.attackFlags = Raziel.attackFlags | 4;
      }
      if ((CurrentSection == 1) && (Raziel.glowEffect != (_FXGlowEffect *)0x0)) {
        FX_StopGlowEffect(Raziel.glowEffect,0);
        Raziel.glowEffect = (_FXGlowEffect *)0x0;
      }
      goto LAB_8009c30c;
    }
    if ((int)puVar4 < 0x2000001) {
      if (puVar4 == (undefined *)0x1000018) {
        if (p_Var2->Data != 0) {
          razSetPlayerEventHistory(0x100);
          ControlFlag = ControlFlag | 0x40000;
          if (CurrentSection == 2) {
            NewAnim = 0;
            local_58 = 3;
            CurrentSection_00 = 2;
            local_54 = CurrentSection;
          }
          else {
            NewAnim = 0x8a;
            local_58 = 0;
            local_54 = 1;
            CurrentSection_00 = CurrentSection;
          }
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,local_58,local_54);
        }
        if (CurrentSection == 1) {
          CurrentSection_00 = 0x5a;
LAB_8009bfe4:
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimationCharacter(In,CurrentSection_00,0,3,CurrentSection);
        }
        goto LAB_8009c30c;
      }
      if ((int)puVar4 < 0x1000019) {
        if (puVar4 == (undefined *)0x100000a) {
          if (p_Var2->Data != 0) {
            razSetPlayerEventHistory(0x80);
            ControlFlag = ControlFlag | 0x40000;
            if (CurrentSection == 2) {
              NewAnim = 0;
              CurrentSection_00 = 2;
              local_54 = CurrentSection;
            }
            else {
              NewAnim = 0x3b;
              local_54 = 1;
              CurrentSection_00 = CurrentSection;
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,3,local_54);
          }
          if (CurrentSection == 1) {
            CurrentSection_00 = 0x48;
            goto LAB_8009bfe4;
          }
          goto LAB_8009c30c;
        }
      }
      else {
        if (puVar4 == (undefined *)0x100001f) {
          if ((CurrentSection == 1) &&
             (Inst = (_Instance *)p_Var2->Data,
             *(_Instance **)((int)&Inst->node + 4) != (_Instance *)0x0)) {
                    /* WARNING: Subroutine does not return */
            SetMonsterHitData(*(_Instance **)&Inst->node,(_Instance *)0x0,(int)Inst->prev,
                              (uint)(Raziel.attack)->knockBackDistance,
                              (uint)(Raziel.attack)->knockBackFrames);
          }
          goto LAB_8009c30c;
        }
        if (puVar4 == (undefined *)0x1000023) {
          if ((CurrentSection == 0) &&
             (razSwitchVAnimCharacterSingle(In->CharacterInstance,0x18,(int *)0x0,(int *)0x0),
             (Raziel.Senses.EngagedMask & 0x200) != 0)) {
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post(Raziel.Senses.EngagedList[9].instance,0x1000023,p_Var2->Data);
          }
          goto LAB_8009c30c;
        }
      }
    }
    else {
      if (puVar4 == (undefined *)0x4020000) goto LAB_8009c30c;
      if ((int)puVar4 < 0x4020001) {
        if (puVar4 == (undefined *)0x2000002) {
          if (CurrentSection == 1) {
            CurrentSection_00 = *(int *)(p_Var2->Data + 0xc) * (uint)(Raziel.attack)->hitPowerScale;
            if (CurrentSection_00 < 0) {
              CurrentSection_00 = CurrentSection_00 + 0xfff;
            }
                    /* WARNING: Subroutine does not return */
            SetMonsterHitData(In->CharacterInstance,Raziel.attackLastHit,CurrentSection_00 >> 0xc,
                              (uint)(Raziel.attack)->knockBackDistance,
                              (uint)(Raziel.attack)->knockBackFrames);
          }
          goto LAB_8009c30c;
        }
        if (puVar4 == (undefined *)0x4010080) {
          if (CurrentSection == 0) {
            if (p_Var2->Data == 0) {
              razSetPauseTranslation(In->CharacterInstance);
            }
            else {
              razResetPauseTranslation(In->CharacterInstance);
            }
          }
          goto LAB_8009c30c;
        }
      }
      else {
        if (puVar4 == (undefined *)0x8000000) {
          if (((Raziel.attackFlags & 4U) == 0) ||
             (*(int *)(&((__AttackItem *)PlayerData->attackList[Raziel.currentAttack])->switchDelay
                      + In->SectionList[CurrentSection].Data2 * 4) == 0)) {
            if (Raziel.currentAttack < 10) {
              if ((6 < Raziel.nothingCounter) || ((Raziel.Senses.EngagedMask & 0x40) == 0)) {
                    /* WARNING: Subroutine does not return */
                SetControlInitIdleData(1,0,(uint)(Raziel.attack)->framesOut);
              }
              NewProcess = StateHandlerAutoFace;
            }
            else {
              if ((*PadData & 0x8000000fU) == 0) {
                StateSwitchStateCharacterData(In,StateHandlerStopMove,0x3c);
                goto LAB_8009c30c;
              }
              NewProcess = StateHandlerMove;
            }
LAB_8009c0c0:
                    /* WARNING: Subroutine does not return */
            StateSwitchStateData(In,CurrentSection,NewProcess,0);
          }
          if (Raziel.currentAttack < 10) {
            CurrentSection_00 = 0x100000;
          }
          else {
            if ((*PadData & 0x8000000fU) == 0) goto LAB_8009c30c;
            CurrentSection_00 = 0x100000;
          }
LAB_8009c28c:
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(In_00,CurrentSection_00,0);
        }
        if (puVar4 == (undefined *)0x8000004) {
          if ((Raziel.Senses.EngagedMask & 0x200) != 0) {
            if (Raziel.Senses.heldClass != 0x1000) {
                    /* WARNING: Subroutine does not return */
              INSTANCE_Post(Raziel.Senses.EngagedList[9].instance,0x100000c,0x20);
            }
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post(Raziel.Senses.EngagedList[9].instance,0x1000023,0x1000);
          }
          goto LAB_8009c30c;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009c30c:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&local_30->Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCannedReaction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 575, offset 0x8009c3c8
	/* begin block 1 */
		// Start line: 576
		// Start offset: 0x8009C3C8
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 618
			// Start offset: 0x8009C58C
			// Variables:
		// 		struct _Instance *Inst; // $v0
		/* end block 1.1 */
		// End offset: 0x8009C5A8
		// End Line: 621

		/* begin block 1.2 */
			// Start line: 631
			// Start offset: 0x8009C5B0
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009C620
		// End Line: 648
	/* end block 1 */
	// End offset: 0x8009C63C
	// End Line: 691

	/* begin block 2 */
		// Start line: 1183
	/* end block 2 */
	// End Line: 1184

void StateHandlerCannedReaction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *weapon;
  int Data_00;
  undefined *puVar2;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100014) {
LAB_8009c54c:
                    /* WARNING: Subroutine does not return */
    SetControlInitIdleData(0,0,3);
  }
  if ((int)puVar2 < 0x100015) {
    if (puVar2 == &DAT_80000020) goto LAB_8009c62c;
    if ((int)puVar2 < -0x7fffffdf) {
      if ((puVar2 == (undefined *)0x80000000) || (puVar2 == &DAT_80000008)) goto LAB_8009c62c;
    }
    else {
      if (puVar2 == &DAT_00100001) {
        if (CurrentSection == 0) {
          Raziel.alarmTable = 0x1194;
          Raziel.Mode = 0x10000;
          ControlFlag = 0x1041009;
          PhysicsMode = 3;
                    /* WARNING: Subroutine does not return */
          SteerSwitchMode(In->CharacterInstance,0);
        }
        goto LAB_8009c62c;
      }
      if (puVar2 == &DAT_00100004) {
        if (CurrentSection == 1) {
          G2EmulationSwitchAnimationSync(In,2,1,4);
        }
        goto LAB_8009c62c;
      }
    }
  }
  else {
    if (puVar2 == (undefined *)0x8000000) goto LAB_8009c54c;
    if ((int)puVar2 < 0x8000001) {
      if (((int)puVar2 < 0x1000002) && (0xffffff < (int)puVar2)) goto LAB_8009c62c;
    }
    else {
      if (puVar2 == (undefined *)0x8000003) {
        if ((CurrentSection == 0) &&
           (weapon = razGetHeldItem(), (Raziel.Senses.EngagedMask & 0x200) != 0)) {
          Data_00 = SetMonsterImpaleData
                              (weapon,&In->CharacterInstance->rotation,
                               &In->CharacterInstance->position,0x208);
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(Raziel.Senses.EngagedList[9].instance,0x100000a,Data_00);
        }
        goto LAB_8009c62c;
      }
      if (puVar2 == (undefined *)0x8000004) {
        weapon = razGetHeldItem();
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post(weapon,0x800008,2);
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009c62c:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStumble(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*$s6*/)
 // line 694, offset 0x8009c65c
	/* begin block 1 */
		// Start line: 695
		// Start offset: 0x8009C65C
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int processTime; // $s5

		/* begin block 1.1 */
			// Start line: 740
			// Start offset: 0x8009C95C
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009C95C
		// End Line: 742

		/* begin block 1.2 */
			// Start line: 750
			// Start offset: 0x8009C9B0
			// Variables:
		// 		struct evMonsterHitData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x8009C9B0
		// End Line: 751
	/* end block 1 */
	// End offset: 0x8009CA2C
	// End Line: 780

	/* begin block 2 */
		// Start line: 1451
	/* end block 2 */
	// End Line: 1452

/* WARNING: Type propagation algorithm not settling */

void StateHandlerStumble(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *p_Var2;
  int iVar3;
  undefined *puVar4;
  _Instance **pp_Var5;
  
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    if (((CurrentSection == 0) &&
        (iVar3 = In->SectionList[0].Data1 - gameTrackerX.timeMult, In->SectionList[0].Data1 = iVar3,
        iVar3 < 1)) && (iVar3 = STREAM_IsMorphInProgress(), iVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
      EnMessageQueueData(&Raziel.State.SectionList[0].Defer,0x100000,0);
    }
    return;
  }
  puVar4 = (undefined *)p_Var1->ID;
  if (puVar4 == (undefined *)0x100000) {
    if (((*PadData & 0x800) != 0) && ((*PadData & 0x400) != 0)) {
      Raziel.returnState = StateHandlerIdle;
                    /* WARNING: Subroutine does not return */
      SetControlInitIdleData(0,0,0xc);
    }
                    /* WARNING: Subroutine does not return */
    SetControlInitIdleData(0,0,0xc);
  }
  if ((int)puVar4 < 0x100001) {
    if (puVar4 == &DAT_80000020) goto LAB_8009c9d4;
    if ((int)puVar4 < -0x7fffffdf) {
      if ((puVar4 == (undefined *)0x80000000) || (puVar4 == &DAT_80000008)) goto LAB_8009c9d4;
    }
    else {
      if (puVar4 == (undefined *)0x40003) {
        if (CurrentSection == 0) {
          p_Var2 = (_Instance *)p_Var1->Data;
          G2EmulationInstanceToInstanceSwitchAnimationCharacter
                    (*(_Instance **)&p_Var2->node,*(_Instance **)((int)&p_Var2->node + 4),
                     (int)p_Var2->next,(int)p_Var2->prev,(int)p_Var2->instanceID,(int)p_Var2->flags)
          ;
        }
        goto LAB_8009c9d4;
      }
      if ((int)puVar4 < 0x40004) {
        if (puVar4 == (undefined *)0x0) {
          pp_Var5[0x48] = (_Instance *)0x1;
          goto LAB_8009c9d4;
        }
      }
      else {
        if (puVar4 == (undefined *)0x40005) goto LAB_8009c9d4;
      }
    }
  }
  else {
    if (puVar4 == (undefined *)0x1000001) goto LAB_8009c9d4;
    if ((int)puVar4 < 0x1000002) {
      if (puVar4 == &DAT_00100004) {
                    /* WARNING: Subroutine does not return */
        G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
      }
      if ((int)puVar4 < 0x100005) {
        if (puVar4 == &DAT_00100001) {
          if (CurrentSection == 0) {
            ControlFlag = 8;
            SetPhysics(In->CharacterInstance,-0x10,0,0,0);
            PhysicsMode = 0;
                    /* WARNING: Subroutine does not return */
            SteerSwitchMode(In->CharacterInstance,0);
          }
          pp_Var5[0x47] = (_Instance *)(p_Var1->Data * 0x1e);
                    /* WARNING: Subroutine does not return */
          G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x800);
        }
      }
      else {
        if (puVar4 == (undefined *)0x1000000) {
          if ((gameTrackerX.debugFlags2 & 0x800U) != 0) {
            LoseHealth(*(int *)(p_Var1->Data + 0xc));
          }
          goto LAB_8009c9d4;
        }
      }
    }
    else {
      if (puVar4 == (undefined *)0x4000001) goto LAB_8009c9d4;
      if ((int)puVar4 < 0x4000002) {
        if (puVar4 == (undefined *)0x2000000) goto LAB_8009c9d4;
      }
      else {
        if (puVar4 == (undefined *)0x10000000) {
          if (pp_Var5[0x48] == (_Instance *)0x1) {
            pp_Var5[0x48] = (_Instance *)0x0;
            pp_Var5[0x47] = (_Instance *)(pp_Var5[0x47][-1].relativeMatrix.m + 2);
          }
          goto LAB_8009c9d4;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009c9d4:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerHitReaction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 801, offset 0x8009ca54
	/* begin block 1 */
		// Start line: 802
		// Start offset: 0x8009CA54
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 811
			// Start offset: 0x8009CB38
			// Variables:
		// 		struct evMonsterHitData *data; // $s0

			/* begin block 1.1.1 */
				// Start line: 815
				// Start offset: 0x8009CB44
				// Variables:
			// 		struct _Instance *weapon; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8009CBD0
			// End Line: 836
		/* end block 1.1 */
		// End offset: 0x8009CC18
		// End Line: 843
	/* end block 1 */
	// End offset: 0x8009CCB0
	// End Line: 878

	/* begin block 2 */
		// Start line: 1595
	/* end block 2 */
	// End Line: 1596

/* WARNING: Type propagation algorithm not settling */

void StateHandlerHitReaction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *instance;
  undefined *puVar2;
  code *NewProcess;
  int NewAnim;
  _Instance *p_Var3;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100001) {
    p_Var3 = (_Instance *)p_Var1->Data;
    if (CurrentSection != 0) {
      if ((int)p_Var3->prev < 0x1001) {
        NewAnim = 0x7d;
      }
      else {
        NewAnim = 0x38;
      }
                    /* WARNING: Subroutine does not return */
      G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,2,1);
    }
    Raziel.attackedBy = *(_Instance **)&p_Var3->node;
    instance = razGetHeldWeapon();
    if (instance == (_Instance *)0x0) {
      if ((gameTrackerX.debugFlags2 & 0x800U) != 0) {
        LoseHealth((int)p_Var3->prev);
      }
      PhysicsMode = 0;
      Raziel.Mode = Raziel.Mode | 0x208000;
      ControlFlag = ControlFlag & 0xf7ffffffU | 0x1008;
      ResetPhysics(In->CharacterInstance,-0x10);
                    /* WARNING: Subroutine does not return */
      SteerSwitchMode(In->CharacterInstance,10);
    }
                    /* WARNING: Subroutine does not return */
    TurnOffCollisionPhysOb(instance,7);
  }
  if ((int)puVar2 < 0x100002) {
    if (((int)puVar2 < -0x7ffffffe) || (puVar2 == &DAT_80000020)) goto LAB_8009cca0;
  }
  else {
    if (puVar2 == (undefined *)0x4020000) goto LAB_8009cca0;
    if ((int)puVar2 < 0x4020001) {
      if (puVar2 == (undefined *)0x1000000) goto LAB_8009cca0;
    }
    else {
      if (((int)puVar2 < 0x8000002) && (0x7ffffff < (int)puVar2)) {
        if (CurrentSection == 0) {
          if ((ControlFlag & 0x100000U) == 0) {
            if ((Raziel.Mode & 0x40000U) == 0) {
                    /* WARNING: Subroutine does not return */
              SetControlInitIdleData(0,0,3);
            }
            NewProcess = StateHandlerSwim;
          }
          else {
            NewProcess = StateHandlerGlyphs;
          }
          StateSwitchStateCharacterData(In,NewProcess,0);
        }
        goto LAB_8009cca0;
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009cca0:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerThrow2(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 958, offset 0x8009ccd0
	/* begin block 1 */
		// Start line: 959
		// Start offset: 0x8009CCD0
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 1164
			// Start offset: 0x8009D41C
			// Variables:
		// 		struct _Instance *weaponInst; // $s0

			/* begin block 1.1.1 */
				// Start line: 1168
				// Start offset: 0x8009D430

				/* begin block 1.1.1.1 */
					// Start line: 1178
					// Start offset: 0x8009D490
					// Variables:
				// 		struct _Position To; // stack offset -64
				// 		struct _Rotation Rot; // stack offset -56
				// 		struct MATRIX *matrix; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x8009D490
				// End Line: 1183
			/* end block 1.1.1 */
			// End offset: 0x8009D570
			// End Line: 1199
		/* end block 1.1 */
		// End offset: 0x8009D59C
		// End Line: 1203

		/* begin block 1.2 */
			// Start line: 1248
			// Start offset: 0x8009D6E0
			// Variables:
		// 		struct _Position To; // stack offset -64
		// 		struct _Rotation Rot; // stack offset -48
		// 		struct MATRIX *matrix; // $v0
		/* end block 1.2 */
		// End offset: 0x8009D724
		// End Line: 1258
	/* end block 1 */
	// End offset: 0x8009D724
	// End Line: 1281

	/* begin block 2 */
		// Start line: 1910
	/* end block 2 */
	// End Line: 1911

/* WARNING: Removing unreachable block (ram,0x8009d3a4) */

void StateHandlerThrow2(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  __Event *p_Var6;
  _Instance *Inst;
  undefined *puVar7;
  __MessageQueue *In_00;
  _Position *target;
  int Data_00;
  ushort type;
  int NewAnim;
  _Instance **pp_Var8;
  __State *p_Var9;
  int local_58;
  
  uVar5 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var9 = In->SectionList + CurrentSection;
  In_00 = &p_Var9->Event;
  pp_Var8 = &In->CharacterInstance + CurrentSection * 0x47;
  p_Var6 = PeekMessageQueue(In_00);
  if (p_Var6 == (__Event *)0x0) {
    if ((CurrentSection == 1) && ((Raziel.Senses.EngagedMask & 0x80) != 0)) {
                    /* WARNING: Subroutine does not return */
      INSTANCE_Query(Raziel.Senses.EngagedList[7].instance,0xc);
    }
    return;
  }
  puVar7 = (undefined *)p_Var6->ID;
  if (puVar7 == &DAT_00100009) {
    if (CurrentSection == 1) {
      if (p_Var6->Data == 1) {
        if ((Raziel.Senses.heldClass != 0x1000) && (Raziel.Senses.heldClass != 8)) {
          razSetFadeEffect(In->CharacterInstance->fadeValue,PlayerData->throwFadeValue,
                           (int)PlayerData->throwFadeInRate);
        }
        Raziel.returnState = StateHandlerIdle;
        Raziel.throwMode = 2;
      }
      else {
        razSetFadeEffect(In->CharacterInstance->fadeValue,0,-(int)PlayerData->throwFadeInRate);
        G2Anim_InterpDisableController(&In->CharacterInstance->anim,0xe,0xe,600);
        Raziel.throwMode = 0;
      }
    }
    goto LAB_8009d6b0;
  }
  if ((int)puVar7 < 0x10000a) {
    if (puVar7 == &DAT_80000020) goto LAB_8009d6b0;
    if ((int)puVar7 < -0x7fffffdf) {
      if (puVar7 == (undefined *)0x80000000) goto LAB_8009d6b0;
      if (puVar7 == &DAT_80000008) {
        if (Raziel.throwInstance != (_Instance *)0x0) {
          Data_00 = 0x100000;
LAB_8009d40c:
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(In_00,Data_00,0);
        }
        goto LAB_8009d6b0;
      }
    }
    else {
      if (puVar7 == &DAT_00100001) {
        if (CurrentSection == 0) {
          ControlFlag = 0x40041001;
          if ((Raziel.Mode & 0x40000U) == 0) {
                    /* WARNING: Subroutine does not return */
            SteerSwitchMode(In->CharacterInstance,0);
          }
                    /* WARNING: Subroutine does not return */
          SteerSwitchMode(In->CharacterInstance,0xb);
        }
        if (CurrentSection == 2) {
          Data_00 = 2;
          if ((Raziel.Mode & 0x40000U) == 0) {
            Data_00 = 2;
            NewAnim = 0;
            local_58 = 3;
          }
          else {
            NewAnim = 0x3d;
            local_58 = 3;
          }
LAB_8009d130:
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_58,CurrentSection);
        }
        if (((Raziel.Mode & 0x40000U) == 0) || (CurrentSection != 0)) {
          bVar1 = (Raziel.throwData)->prepAnim;
          if (bVar1 == 0) {
            bVar1 = (Raziel.throwData)->coilAnim;
            bVar2 = (Raziel.throwData)->coilAnimFramesIn;
            bVar3 = (Raziel.throwData)->coilAnimAlphaIn;
          }
          else {
            bVar2 = (Raziel.throwData)->prepAnimFramesIn;
            bVar3 = (Raziel.throwData)->prepAnimAlphaIn;
          }
          G2EmulationSwitchAnimationAlpha(In,CurrentSection,(uint)bVar1,0,(uint)bVar2,1,(uint)bVar3)
          ;
        }
        else {
          if (uVar5 != 0x3f) {
            Data_00 = 0;
            NewAnim = 0x3f;
            local_58 = 0x10;
            CurrentSection = 2;
            goto LAB_8009d130;
          }
        }
        pp_Var8[0x48] = (_Instance *)0x1;
        goto LAB_8009d6b0;
      }
      if ((int)puVar7 < 0x100002) {
        if (puVar7 == (undefined *)0x100000) {
          if ((Raziel.Mode & 0x40000U) != 0) {
                    /* WARNING: Subroutine does not return */
            StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
          }
                    /* WARNING: Subroutine does not return */
          SetControlInitIdleData(0,0,(uint)(Raziel.throwData)->framesOut);
        }
      }
      else {
        if (puVar7 == &DAT_00100004) {
          G2Anim_InterpDisableController(&In->CharacterInstance->anim,0xe,0xe,300);
          if ((Raziel.effectsFlags & 2U) != 0) {
            razSetFadeEffect(In->CharacterInstance->fadeValue,0,-PlayerData->throwFadeOutRate);
          }
          if ((CurrentSection == 0) && (Raziel.soundHandle != 0)) {
                    /* WARNING: Subroutine does not return */
            SndEndLoop(Raziel.soundHandle);
          }
          if (Raziel.Senses.heldClass == 8) {
            Inst = razGetHeldItem();
            INSTANCE_PlainDeath(Inst);
          }
          if (Raziel.Senses.heldClass == 0x1000) {
            Data_00 = 0x800105;
            Inst = Raziel.soulReaver;
            goto LAB_8009d324;
          }
          goto LAB_8009d6b0;
        }
      }
    }
  }
  else {
    if (puVar7 == (undefined *)0x8000000) {
      Raziel.throwMode = Raziel.throwMode & 0xfffffffb;
      if (uVar5 == (uint)(Raziel.throwData)->prepAnim) {
        if (((Raziel.Mode & 0x40000U) == 0) || (CurrentSection != 0)) {
          G2EmulationSwitchAnimationAlpha
                    (In,CurrentSection,(uint)(Raziel.throwData)->coilAnim,0,
                     (uint)(Raziel.throwData)->coilAnimFramesIn,1,
                     (uint)(Raziel.throwData)->coilAnimAlphaIn);
        }
      }
      else {
        if ((uVar5 == (uint)(Raziel.throwData)->throwAnim) &&
           (Data_00 = 0x100000, CurrentSection == 1)) {
          Inst = In->CharacterInstance;
LAB_8009d324:
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(Inst,Data_00,0);
        }
      }
      goto LAB_8009d6b0;
    }
    if ((int)puVar7 < 0x8000001) {
      if (puVar7 == (undefined *)0x4000001) {
        if (CurrentSection == 0) {
          SetDropPhysics(In->CharacterInstance,&Raziel);
        }
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0x24,0,4,1);
      }
      if ((int)puVar7 < 0x4000002) {
        if (puVar7 == (undefined *)0x1000001) goto LAB_8009d6b0;
      }
      else {
        if (puVar7 == (undefined *)0x4020000) goto LAB_8009d6b0;
      }
    }
    else {
      if (puVar7 == (undefined *)0x20000002) goto LAB_8009d6b0;
      if ((int)puVar7 < 0x20000003) {
        if (puVar7 == (undefined *)0x8000004) {
          Inst = razGetHeldWeapon();
          if (Inst != (_Instance *)0x0) {
            if ((Raziel.throwMode & 2U) == 0) {
              if ((Raziel.Senses.EngagedMask & 0x80) != 0) {
                Data_00 = SetObjectThrowData(Raziel.Senses.EngagedList[7].instance,(_SVector *)0x0,1
                                             ,0,(uint)(ushort)(Raziel.throwData)->velocity,
                                             (int)(Raziel.throwData)->gravity,0,-0x400);
                    /* WARNING: Subroutine does not return */
                INSTANCE_Post(Inst,0x800010,Data_00);
              }
              target = (_Position *)0x0;
              type = 0;
              uVar4 = (Raziel.throwData)->velocity;
              Data_00 = 0;
            }
            else {
              target = &Raziel.throwTarget;
              type = 4;
              uVar4 = (Raziel.throwData)->velocity;
              Data_00 = (int)(Raziel.throwData)->gravity;
            }
            Data_00 = SetObjectThrowData(target,(_SVector *)0x0,type,0,(uint)uVar4,Data_00,0,-0x400)
            ;
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post(Inst,0x800010,Data_00);
          }
          goto LAB_8009d6b0;
        }
      }
      else {
        if (puVar7 == (undefined *)0x20000020) {
          if (pp_Var8[0x48] != (_Instance *)0x0) {
            In_00 = &p_Var9->Defer;
            if (uVar5 != (uint)(Raziel.throwData)->coilAnim) {
              Data_00 = 0x20000020;
              goto LAB_8009d40c;
            }
            if (((Raziel.Mode & 0x40000U) == 0) || (CurrentSection != 0)) {
                    /* WARNING: Subroutine does not return */
              G2EmulationSwitchAnimation
                        (In,CurrentSection,(uint)(Raziel.throwData)->throwAnim,0,
                         (uint)(Raziel.throwData)->throwAnimFramesInFactor,1);
            }
            pp_Var8[0x48] = (_Instance *)0x0;
            if ((Raziel.playerEvent & 0x200) != 0) {
              razSetPlayerEventHistory(0x200);
            }
          }
          goto LAB_8009d6b0;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009d6b0:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var9->Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PointAt(struct _Instance *instance /*$s0*/, struct _Position *Target /*$s1*/, struct _Rotation *Rot1 /*$s2*/)
 // line 1282, offset 0x8009d750
	/* begin block 1 */
		// Start line: 1283
		// Start offset: 0x8009D750
		// Variables:
	// 		struct _Position From; // stack offset -48
	// 		struct SVECTOR v1; // stack offset -40
	// 		struct VECTOR v3; // stack offset -32
	// 		struct MATRIX *tempMat; // $a0
	/* end block 1 */
	// End offset: 0x8009D83C
	// End Line: 1315

	/* begin block 2 */
		// Start line: 2579
	/* end block 2 */
	// End Line: 2580

	/* begin block 3 */
		// Start line: 2587
	/* end block 3 */
	// End Line: 2588

void PointAt(_Instance *instance,_Position *Target,_Rotation *Rot1)

{
  short local_28;
  short local_26;
  short sStack36;
  undefined auStack32 [16];
  
  local_28 = (Raziel.throwData)->launchPointX;
  local_26 = (Raziel.throwData)->launchPointY;
  sStack36 = (Raziel.throwData)->launchPointZ;
                    /* WARNING: Subroutine does not return */
  ApplyMatrix(instance->matrix,&local_28,auStack32);
}



// decompiled code
// original method signature: 
// void /*$ra*/ ThrowSetFocusPoint(struct _Instance *instance /*$s4*/, struct _Rotation *rot /*$s2*/)
 // line 1320, offset 0x8009d870
	/* begin block 1 */
		// Start line: 1321
		// Start offset: 0x8009D870
		// Variables:
	// 		struct MATRIX *pTempMat; // $s0
	// 		struct _Instance *weaponInstance; // $s1
	// 		struct SVECTOR v1; // stack offset -48
	// 		struct VECTOR v4; // stack offset -40
	/* end block 1 */
	// End offset: 0x8009D994
	// End Line: 1367

	/* begin block 2 */
		// Start line: 2690
	/* end block 2 */
	// End Line: 2691

void ThrowSetFocusPoint(_Instance *instance,_Rotation *rot)

{
  MATRIX *pMVar1;
  _Instance *p_Var2;
  undefined2 local_30;
  undefined2 local_2e;
  short local_2c;
  undefined local_28 [16];
  
  rot->x = -rot->x;
  pMVar1 = theCamera.core.cwTransform2;
  p_Var2 = razGetHeldWeapon();
  if ((p_Var2 != (_Instance *)0x0) && (p_Var2->matrix != (MATRIX *)0x0)) {
    local_30 = 0;
    local_2e = 0;
    local_2c = (Raziel.throwData)->velocity;
                    /* WARNING: Subroutine does not return */
    ApplyMatrix(pMVar1,&local_30,local_28);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ LimitRotation(struct _Rotation *rot /*$a1*/)
 // line 1368, offset 0x8009d9b4
	/* begin block 1 */
		// Start line: 2804
	/* end block 1 */
	// End Line: 2805

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
    bVar2 = sVar3 < (Raziel.throwData)->minZRotation;
    sVar3 = (Raziel.throwData)->minZRotation;
  }
  else {
    if (sVar1 < 0x800) {
      sVar3 = (Raziel.throwData)->maxZRotation;
      bVar2 = (Raziel.throwData)->maxZRotation < sVar1;
    }
    else {
      sVar3 = (Raziel.throwData)->minZRotation;
      bVar2 = sVar1 < (Raziel.throwData)->minZRotation;
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
    bVar2 = sVar3 < (Raziel.throwData)->minXRotation;
    sVar3 = (Raziel.throwData)->minXRotation;
  }
  else {
    if (sVar1 < 0x800) {
      sVar3 = (Raziel.throwData)->maxXRotation;
      bVar2 = (Raziel.throwData)->maxXRotation < sVar1;
    }
    else {
      sVar3 = (Raziel.throwData)->minXRotation;
      bVar2 = sVar1 < (Raziel.throwData)->minXRotation;
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
 // line 1428, offset 0x8009db28
	/* begin block 1 */
		// Start line: 1429
		// Start offset: 0x8009DB28
		// Variables:
	// 		struct __Event *Ptr; // $s2
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 1462
			// Start offset: 0x8009DD74
			// Variables:
		// 		struct _Instance *Inst; // $a1
		/* end block 1.1 */
		// End offset: 0x8009DDC4
		// End Line: 1473

		/* begin block 1.2 */
			// Start line: 1499
			// Start offset: 0x8009DE34
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x8009DE50
		// End Line: 1517

		/* begin block 1.3 */
			// Start line: 1604
			// Start offset: 0x8009E028
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.3 */
		// End offset: 0x8009E0D8
		// End Line: 1636

		/* begin block 1.4 */
			// Start line: 1643
			// Start offset: 0x8009E0F0
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.4 */
		// End offset: 0x8009E140
		// End Line: 1655

		/* begin block 1.5 */
			// Start line: 1662
			// Start offset: 0x8009E1A0
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.5 */
		// End offset: 0x8009E1F0
		// End Line: 1676
	/* end block 1 */
	// End offset: 0x8009E264
	// End Line: 1708

	/* begin block 2 */
		// Start line: 2928
	/* end block 2 */
	// End Line: 2929

void StateHandlerGrab(__CharacterState *In,int CurrentSection,int Data)

{
  uint local_30;
  __Event *p_Var1;
  _Instance *instance;
  int Data_00;
  undefined *puVar2;
  uint NewAnim;
  int local_2c;
  
  local_30 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100015) {
    if (CurrentSection == 0) {
      if (local_30 == (uint)(Raziel.throwData)->prepAnim) {
        if ((Raziel.Senses.EngagedMask & 0x100) != 0) {
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(Raziel.Senses.EngagedList[8].instance,0x1000002,(int)In->CharacterInstance);
        }
      }
      else {
        instance = razGetHeldItem();
        if (instance != (_Instance *)0x0) {
LAB_8009e098:
          Data_00 = SetMonsterThrownData(In->CharacterInstance,&In->CharacterInstance->rotation,100)
          ;
                    /* WARNING: Subroutine does not return */
          INSTANCE_Post(instance,0x1000003,Data_00);
        }
        razReaverOn();
      }
    }
    goto LAB_8009e254;
  }
  if ((int)puVar2 < 0x100016) {
    if (puVar2 == (undefined *)0x0) {
      if (((CurrentSection == 0) && (local_30 != (uint)(Raziel.throwData)->prepAnim)) &&
         ((local_30 != 0x47 && (local_30 != (uint)(Raziel.throwData)->throwAnim)))) {
                    /* WARNING: Subroutine does not return */
        SteerSwitchMode(In->CharacterInstance,0);
      }
      goto LAB_8009e254;
    }
    if ((int)puVar2 < 1) {
      if (puVar2 == &DAT_80000008) goto LAB_8009e254;
      if ((int)puVar2 < -0x7ffffff7) {
        if (puVar2 == (undefined *)0x80000000) goto LAB_8009e254;
      }
      else {
        if (puVar2 == &DAT_80000020) goto LAB_8009e254;
      }
    }
    else {
      if (puVar2 == &DAT_00100004) {
        instance = razGetHeldItem();
        if (instance != (_Instance *)0x0) goto LAB_8009e098;
        goto LAB_8009e254;
      }
      if ((int)puVar2 < 0x100005) {
        if (puVar2 == &DAT_00100001) {
          if (CurrentSection == 0) {
            Raziel.throwData = PlayerData->throwList[6];
            ControlFlag = 0x41043009;
            PhysicsMode = 3;
                    /* WARNING: Subroutine does not return */
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
              NewAnim = (uint)(Raziel.throwData)->prepAnim;
              local_30 = (uint)(Raziel.throwData)->prepAnimFramesIn;
              local_2c = 1;
              Data_00 = CurrentSection;
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_30,local_2c);
          }
          if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimationCharacter
                      (In,0x47,0,(uint)(Raziel.throwData)->prepAnimFramesIn,1);
          }
          (&In->CharacterInstance + CurrentSection * 0x47)[0x48] = (_Instance *)0xd;
          (&In->CharacterInstance + CurrentSection * 0x47)[0x47] = (_Instance *)0x0;
          goto LAB_8009e254;
        }
      }
      else {
        if (puVar2 == &DAT_00100014) {
          if ((CurrentSection == 0) && (instance = razGetHeldItem(), instance != (_Instance *)0x0))
          {
            Data_00 = SetMonsterThrownData
                                (In->CharacterInstance,&In->CharacterInstance->rotation,10);
                    /* WARNING: Subroutine does not return */
            INSTANCE_Post(instance,0x1000003,Data_00);
          }
LAB_8009e140:
                    /* WARNING: Subroutine does not return */
          SetControlInitIdleData(0,0,(uint)(Raziel.throwData)->framesOut);
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
        if (puVar2 == (undefined *)0x1000001) goto LAB_8009e254;
        if ((int)puVar2 < 0x1000002) {
          if (puVar2 == (undefined *)0x1000000) {
            if (((CurrentSection == 0) && ((ControlFlag & 0x4000U) == 0)) &&
               (Raziel.invincibleTimer == 0)) {
              instance = razGetHeldItem();
              if (instance != (_Instance *)0x0) {
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
            goto LAB_8009e254;
          }
        }
        else {
          if (puVar2 == (undefined *)0x1000006) goto LAB_8009e140;
        }
      }
      else {
        if (puVar2 == (undefined *)0x8000000) {
          if (CurrentSection == 0) {
            if (In->SectionList[0].Data2 != 0xb) {
                    /* WARNING: Subroutine does not return */
              SetControlInitIdleData(0,0,3);
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,0,0x37,0,3,2);
          }
          goto LAB_8009e254;
        }
        if ((int)puVar2 < 0x8000001) {
          if (puVar2 == (undefined *)0x4020000) goto LAB_8009e254;
        }
        else {
          if (puVar2 == (undefined *)0x10000000) {
            if ((((CurrentSection == 0) && (local_30 != (uint)(Raziel.throwData)->prepAnim)) &&
                (local_30 != 0x47)) && (local_30 != (uint)(Raziel.throwData)->throwAnim)) {
                    /* WARNING: Subroutine does not return */
              SteerSwitchMode(In->CharacterInstance,0x12);
            }
            goto LAB_8009e254;
          }
          if (puVar2 == (undefined *)0x20000020) {
            if (CurrentSection == 0) {
              if (In->SectionList[0].Data1 == 0) {
                    /* WARNING: Subroutine does not return */
                EnMessageQueueData(&In->SectionList[0].Defer,0x20000020,0);
              }
              if (In->SectionList[0].Data2 != 0xc) {
                    /* WARNING: Subroutine does not return */
                G2EmulationSwitchAnimationCharacter
                          (In,(uint)(Raziel.throwData)->throwAnim,0,
                           (uint)(Raziel.throwData)->throwAnimFramesInFactor,1);
              }
            }
            goto LAB_8009e254;
          }
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009e254:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}





