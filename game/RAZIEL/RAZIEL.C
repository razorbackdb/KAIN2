#include "THISDUST.H"
#include "RAZIEL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitStates(struct _Instance *PlayerInstance /*$s2*/)
 // line 179, offset 0x800a3f20
	/* begin block 1 */
		// Start line: 180
		// Start offset: 0x800A3F20
		// Variables:
	// 		unsigned char i; // $s1

		/* begin block 1.1 */
			// Start line: 209
			// Start offset: 0x800A4014
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.1 */
		// End offset: 0x800A4014
		// End Line: 210
	/* end block 1 */
	// End offset: 0x800A408C
	// End Line: 221

	/* begin block 2 */
		// Start line: 358
	/* end block 2 */
	// End Line: 359

	/* begin block 3 */
		// Start line: 362
	/* end block 3 */
	// End Line: 363

void InitStates(_Instance *PlayerInstance)

{
  _G2AnimSection_Type *p_Var1;
  uint uVar2;
  byte bVar3;
  
  if (Raziel.footPrint == 0) {
    Raziel.footPrint = (int)PlayerInstance->object;
  }
  else {
    if ((Object *)Raziel.footPrint != PlayerInstance->object) {
      GXFilePrint("\n");
      GXFilePrint("Raziel has been relocated\n");
      GXFilePrint("Must respect the no dump\n");
      GXFilePrint("\n");
    }
  }
  *(__CharacterState **)&PlayerInstance->InstanceState = &Raziel.State;
  Raziel.padCommands.Queue[13].ID = (int)PlayerInstance->data;
  bVar3 = 0;
  Raziel.State.CharacterInstance = PlayerInstance;
  G2EmulationSetTotalSections(&Raziel.State,3);
  G2EmulationSetStartAndEndSegment(&Raziel.State,0,0,0xd);
  G2EmulationSetStartAndEndSegment(&Raziel.State,1,0xe,0x31);
  G2EmulationSetStartAndEndSegment(&Raziel.State,2,0x32,0x41);
  uVar2 = 0;
  do {
    p_Var1 = (PlayerInstance->anim).section + uVar2;
    p_Var1->callback = RazielAnimCallback;
    p_Var1->callbackData = (void *)0x0;
    Raziel.State.SectionList[uVar2].Process = StateHandlerIdle;
    InitMessageQueue(&Raziel.State.SectionList[uVar2].Event);
    InitMessageQueue(&Raziel.State.SectionList[uVar2].Defer);
    bVar3 = bVar3 + 1;
    uVar2 = (uint)bVar3;
  } while (bVar3 < 3);
  G2AnimSection_SetInterpInfo
            ((PlayerInstance->anim).section,
             (_G2AnimInterpInfo_Type *)&Raziel.padCommands.Queue[0xd].Data);
  G2AnimSection_SetInterpInfo
            ((PlayerInstance->anim).section + 1,
             (_G2AnimInterpInfo_Type *)(Raziel.padCommands.Queue + 0xf));
  G2AnimSection_SetInterpInfo
            ((PlayerInstance->anim).section + 2,(_G2AnimInterpInfo_Type *)&Raziel.passedMask);
  Raziel.Mode = 1;
  gameTrackerX.debugFlags2 = gameTrackerX.debugFlags2 | 0x800;
  InitHealthSystem();
  debugRazielFlags1 = 0x1000000;
  Raziel.GlyphManaMax = 0x14;
  Raziel.Senses.EngagedList = &EngagedList;
  Raziel.constrictData = (__FitPoint *)&Raziel.effectsFadeSteps;
  Raziel.dropOffHeight = 0x9b;
  Raziel.GlyphManaBalls = 0;
  Raziel.Abilities = 0;
  Raziel.RotationSegment = 0;
  Raziel.padCommands.Head._0_2_ = 0;
  Raziel.Senses.EngagedMask = 0;
  Raziel.idleInstance = (_Instance *)0x0;
  Raziel.soulReaver = (_Instance *)0x0;
  Raziel.fallZVelocity = -0x20;
  G2EmulationSetAnimation(&Raziel.State,0,0,0,0);
  G2EmulationSetMode(&Raziel.State,0,2);
  G2EmulationSetAnimation(&Raziel.State,1,0,0,0);
  G2EmulationSetMode(&Raziel.State,1,2);
  G2EmulationSetAnimation(&Raziel.State,2,0,0,0);
  G2EmulationSetMode(&Raziel.State,2,2);
  ControlFlag = 0x519;
  PlayerInstance->maxXVel = 0x100;
  PlayerInstance->maxYVel = 0x100;
  PlayerInstance->maxZVel = 0x100;
  razSetCowlNoDraw(1);
  InitExternalForces(&ExternalForces,4);
  ResetPhysics(PlayerInstance,-0x10);
  ExtraRot = (_G2SVector3_Type *)0x0;
  CAMERA_ChangeToOutOfWater(&theCamera,PlayerInstance);
  razAttachControllers();
  INSTANCE_Post(PlayerInstance,0x100006,0);
  PlayerInstance->checkMask = 0x3e002e;
  PlayerInstance->flags2 = PlayerInstance->flags2 | 0x400;
  G2EmulationInit();
  InitGlyphSystem(PlayerInstance);
  gameTrackerX.currentMaterialTime._1_1_ = 0;
  Raziel.slipSlope = 0xb50;
  Raziel.padCommands.Queue[8].ID._2_2_ = 0xffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateInitIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Ptr /*$a2*/)
 // line 436, offset 0x800a4284
	/* begin block 1 */
		// Start line: 437
		// Start offset: 0x800A4284
		// Variables:
	// 		struct evControlInitIdleData *data; // $s0
	// 		struct _Instance *linkWeapon; // $a0
	/* end block 1 */
	// End offset: 0x800A4510
	// End Line: 545

	/* begin block 2 */
		// Start line: 868
	/* end block 2 */
	// End Line: 869

void StateInitIdle(__CharacterState *In,int CurrentSection,int Ptr)

{
  _Instance *p_Var1;
  int NewAnim;
  int local_18;
  int local_14;
  
  if (Ptr == 0) {
    Ptr = SetControlInitIdleData(0,0,3);
  }
  p_Var1 = razGetHeldWeapon();
  NewAnim = *(int *)Ptr;
  if (NewAnim == 2) {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x60,-1,-1);
    if (NewAnim == 0) {
      return;
    }
    NewAnim = 0x8d;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a4508;
  }
  if (NewAnim == 3) {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,100,-1,-1);
    if (NewAnim == 0) {
      return;
    }
    NewAnim = 0x8e;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a4508;
  }
  if (NewAnim == 4) {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x68,-1,-1);
    if (NewAnim == 0) {
      return;
    }
    NewAnim = 0x8f;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a4508;
  }
  if ((p_Var1 == (_Instance *)0x0) || (CurrentSection != 1)) {
    if (NewAnim == 0) {
      NewAnim = 0;
    }
    else {
      if (NewAnim != 1) {
        return;
      }
      NewAnim = 0x37;
    }
LAB_800a44f8:
    local_18 = ((int *)Ptr)[2];
  }
  else {
    if (NewAnim - 2U < 3) {
      *(int *)Ptr = 0;
    }
    if (Raziel.Senses.heldClass == 2) {
      if (*(int *)Ptr == 0) {
        CurrentSection = 1;
        NewAnim = 0x54;
      }
      else {
        CurrentSection = 1;
        NewAnim = 0x7f;
      }
      goto LAB_800a44f8;
    }
    if (Raziel.Senses.heldClass < 3) {
      if (Raziel.Senses.heldClass == 0) {
        return;
      }
      if (Raziel.Senses.heldClass != 1) {
        return;
      }
      if (*(int *)Ptr == 0) {
        CurrentSection = 1;
        NewAnim = 0x32;
        goto LAB_800a44f8;
      }
      CurrentSection = 1;
      NewAnim = 0x80;
      local_18 = ((int *)Ptr)[2];
    }
    else {
      if (Raziel.Senses.heldClass == 3) {
        CurrentSection = 1;
        NewAnim = 99;
        goto LAB_800a44f8;
      }
      if (Raziel.Senses.heldClass != 0x1000) {
        return;
      }
      if (*(int *)Ptr == 0) {
        G2EmulationSwitchAnimation(In,1,0x76,0,((int *)Ptr)[2],2);
        razReaverScale(0xaf0);
        return;
      }
      CurrentSection = 1;
      NewAnim = 0x8a;
      local_18 = ((int *)Ptr)[2];
    }
  }
  local_14 = 2;
LAB_800a4508:
  G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,local_18,local_14);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 594, offset 0x800a4528
	/* begin block 1 */
		// Start line: 595
		// Start offset: 0x800A4528
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int blockForwardMotion; // $s6

		/* begin block 1.1 */
			// Start line: 727
			// Start offset: 0x800A4AA4
			// Variables:
		// 		struct _Instance *heldInst; // $v0
		/* end block 1.1 */
		// End offset: 0x800A4ACC
		// End Line: 733
	/* end block 1 */
	// End offset: 0x800A4C74
	// End Line: 813

	/* begin block 2 */
		// Start line: 1182
	/* end block 2 */
	// End Line: 1183

void StateHandlerIdle(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  _Instance *Inst;
  int Ptr;
  ulong uVar3;
  undefined *puVar4;
  code *NewProcess;
  _Instance **pp_Var5;
  int Mode;
  
  bVar1 = false;
  ControlFlag = ControlFlag & 0xffffffef;
  G2EmulationQueryFrame(In,CurrentSection);
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      if ((((CurrentSection == 0) && (Ptr = CheckHolding(In->CharacterInstance), Ptr == 0)) &&
          (Ptr = G2EmulationQueryAnimation(In,0), Ptr != 0x37)) &&
         ((Raziel.idleCount = Raziel.idleCount + 1, 300 < Raziel.idleCount &&
          (Raziel.idleCount == (Raziel.idleCount / 900) * 900)))) {
        if (Raziel.idleInstance == (_Instance *)0x0) {
          G2EmulationSwitchAnimationCharacter(In,0x18,0,3,1);
          COLLIDE_SegmentCollisionOff(In->CharacterInstance,1);
        }
        else {
          G2EmulationInstanceToInstanceSwitchAnimationCharacter
                    (In->CharacterInstance,Raziel.idleInstance,1,0,3,1);
        }
      }
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == (undefined *)0x2000000) {
      Ptr = razPickupAndGrab(In,CurrentSection);
      if (Ptr != 0) {
        if (((Raziel.Senses.EngagedMask & 1) == 0) || (Raziel.Senses.heldClass == 3)) {
          if (((Raziel.Senses.EngagedMask & 8) == 0) || (Raziel.Senses.heldClass == 3)) {
            if ((Raziel.Senses.EngagedMask & 0x2010) == 0) {
              if ((Raziel.Senses.EngagedMask & 0x800) != 0) {
                if (CurrentSection == 1) {
                  razReaverPickup(In->CharacterInstance,Raziel.Senses.EngagedList[0xb].instance);
                }
                goto LAB_800a4b88;
              }
              if ((Raziel.Senses.EngagedMask & 0x4000) == 0) goto LAB_800a4b34;
              NewProcess = StateHandlerWarpGate;
            }
            else {
              if (Raziel.Senses.heldClass == 3) {
                Inst = razGetHeldItem();
                if ((Inst == (_Instance *)0x0) ||
                   (uVar3 = INSTANCE_Query(Inst,2), (uVar3 & 0x20) == 0)) goto LAB_800a4b88;
                NewProcess = StateHandlerBreakOff;
              }
              else {
                NewProcess = StateHandlerBreakOff;
              }
            }
LAB_800a4b44:
            StateSwitchStateData(In,CurrentSection,NewProcess,0);
          }
          else {
            if (CurrentSection == 0) {
              NewProcess = StateHandlerPullSwitch;
              goto LAB_800a4b68;
            }
          }
        }
        else {
          Raziel.Mode = 0x200;
          pp_Var5[0x47] = (_Instance *)0x0;
          G2EmulationSwitchAnimation(In,CurrentSection,0x15,0,6,1);
          StateSwitchStateData(In,CurrentSection,StateHandlerPushObject,0);
          ControlFlag = ControlFlag & 0xfffffffe;
        }
      }
    }
    else {
      if ((int)puVar4 < 0x2000001) {
        if (puVar4 == &DAT_80000002) {
          if ((CurrentSection == 0) && ((*PadData & 0x40) != 0)) {
            Raziel._1140_4_ = 0;
            NewProcess = StateHandlerSoulSuck;
LAB_800a4b68:
            StateSwitchStateCharacterData(In,NewProcess,0);
          }
        }
        else {
          if ((int)puVar4 < -0x7ffffffd) {
            if (puVar4 == (undefined *)0x80000000) {
LAB_800a4b34:
              NewProcess = StateHandlerAttack2;
              goto LAB_800a4b44;
            }
            if (puVar4 != (undefined *)0x80000001) goto LAB_800a4b7c;
            if (CurrentSection == 0) {
              Raziel.Mode = 0x10;
              ControlFlag = ControlFlag | 0x10;
              Ptr = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x10,(int *)0x0,(int *)0x0);
              if (Ptr != 0) {
                G2EmulationSwitchAnimationCharacter(In,0x22,0,2,1);
              }
              NewProcess = StateHandlerCompression;
              goto LAB_800a4b68;
            }
          }
          else {
            if (puVar4 == (undefined *)0x100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 1;
                Raziel.idleCount = 0;
                ControlFlag = 0x2a109;
                PhysicsMode = 3;
                SteerSwitchMode(In->CharacterInstance,0);
                Raziel.movementMinRate = 0;
              }
              StateInitIdle(In,CurrentSection,p_Var2->Data);
            }
            else {
              if ((int)puVar4 < 0x100002) {
                if (puVar4 == &DAT_80000010) {
                  if (CurrentSection == 0) {
                    NewProcess = StateHandlerGlyphs;
                    goto LAB_800a4b68;
                  }
                }
                else {
LAB_800a4b7c:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar4 != (undefined *)0x100004) goto LAB_800a4b7c;
                if (CurrentSection == 0) {
                  razReaverScale(0x1000);
                  razResetPauseTranslation(In->CharacterInstance);
                  COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
                }
              }
            }
          }
        }
      }
      else {
        if (puVar4 != (undefined *)0x4010400) {
          if ((int)puVar4 < 0x4010401) {
            if (0x2000002 < (int)puVar4) {
              if (puVar4 != (undefined *)0x4010080) goto LAB_800a4b7c;
              if (CurrentSection == 0) {
                if (p_Var2->Data == 0) {
                  razSetPauseTranslation(In->CharacterInstance);
                }
                else {
                  razResetPauseTranslation(In->CharacterInstance);
                }
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x8000000) {
              Ptr = SetControlInitIdleData(0,0,3);
              StateInitIdle(In,CurrentSection,Ptr);
              if (CurrentSection == 0) {
                ControlFlag = ControlFlag & 0xffff7fff;
                COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
              }
            }
            else {
              if ((int)puVar4 < 0x8000001) {
                if (puVar4 != (undefined *)0x4010401) goto LAB_800a4b7c;
                bVar1 = true;
              }
              else {
                if (puVar4 != (undefined *)0x10000000) goto LAB_800a4b7c;
                if ((*PadData & 0x200) != 0) {
                  StateSwitchStateData(In,CurrentSection,StateHandlerMove,3);
                  goto LAB_800a4b88;
                }
                if (-0x201 < Raziel.Bearing) {
                  if (Raziel.Bearing < 0x201) {
                    if (!bVar1) {
                      NewProcess = StateHandlerStartMove;
                      goto LAB_800a4b44;
                    }
                    goto LAB_800a4b88;
                  }
                  if (CurrentSection == 1) {
                    if (In->CharacterInstance->LinkChild == (_Instance *)0x0) {
                      Ptr = 1;
                      Mode = CurrentSection;
                      goto LAB_800a4910;
                    }
                  }
                  else {
                    Mode = 1;
                    Ptr = CurrentSection;
LAB_800a4910:
                    G2EmulationSwitchAnimation(In,Ptr,0x35,0,2,Mode);
                  }
                  StateSwitchStateData(In,CurrentSection,StateHandlerStartTurn,0);
                  pp_Var5[0x47] = (_Instance *)0x33;
                  goto LAB_800a4b88;
                }
                if (CurrentSection == 1) {
                  Inst = razGetHeldWeapon();
                  Ptr = 1;
                  Mode = CurrentSection;
                  if (Inst == (_Instance *)0x0) goto LAB_800a4884;
                }
                else {
                  Ptr = CurrentSection;
                  Mode = 1;
LAB_800a4884:
                  G2EmulationSwitchAnimation(In,Ptr,0x36,0,2,Mode);
                }
                StateSwitchStateData(In,CurrentSection,StateHandlerStartTurn,0);
                pp_Var5[0x47] = (_Instance *)0x34;
              }
            }
          }
        }
      }
    }
LAB_800a4b88:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerLookAround(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$a2*/)
 // line 817, offset 0x800a4ca0
	/* begin block 1 */
		// Start line: 818
		// Start offset: 0x800A4CA0
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 825
			// Start offset: 0x800A4D50
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.1 */
		// End offset: 0x800A4D50
		// End Line: 826

		/* begin block 1.2 */
			// Start line: 837
			// Start offset: 0x800A4DA4
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.2 */
		// End offset: 0x800A4DA4
		// End Line: 838

		/* begin block 1.3 */
			// Start line: 850
			// Start offset: 0x800A4DEC
			// Variables:
		// 		int message; // stack offset -32
		// 		int messageData; // stack offset -28
		/* end block 1.3 */
		// End offset: 0x800A4E8C
		// End Line: 867
	/* end block 1 */
	// End offset: 0x800A4F38
	// End Line: 887

	/* begin block 2 */
		// Start line: 1744
	/* end block 2 */
	// End Line: 1745

void StateHandlerLookAround(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  code *NewProcess;
  int Data_00;
  _G2Anim_Type *anim;
  int local_20;
  int iStack28;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      if (((*PadData & 0x800) == 0) || ((*PadData & 0x400) == 0)) {
        EnMessageQueueData(&In->SectionList[CurrentSection].Defer,0x100000,0);
      }
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100001) {
      if (CurrentSection == 1) {
        anim = &In->CharacterInstance->anim;
        G2Anim_EnableController(anim,0x11,0xe);
        G2Anim_EnableController(anim,0x10,0xe);
        G2Anim_EnableController(anim,0xe,0xe);
        ControlFlag = 0x8001008;
      }
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 == &DAT_80000020) {
          Data_00 = StateHandlerDecodeHold(&local_20,&iStack28);
          if (Data_00 != 0) {
            if ((local_20 == 0x80000) && (CurrentSection == 0)) {
              razLaunchForce(In->CharacterInstance);
              StateSwitchStateData(In,0,StateHandlerThrow2,0);
            }
            StateSwitchStateData(In,CurrentSection,StateHandlerThrow2,0);
            razSetFadeEffect(In->CharacterInstance->fadeValue,PlayerData->throwFadeValue,
                             (int)PlayerData->throwFadeInRate);
            Raziel._1140_4_ = StateHandlerIdle;
            Raziel.throwData = (__ThrowItem *)0x2;
          }
        }
        else {
          if (puVar2 == (undefined *)0x100000) {
            Data_00 = 0;
            NewProcess = Raziel._1140_4_;
LAB_800a4ec8:
            StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
          }
        }
      }
      else {
        if (puVar2 == (undefined *)0x100004) {
          if (CurrentSection == 1) {
            anim = &In->CharacterInstance->anim;
            G2Anim_InterpDisableController(anim,0x11,0xe,300);
            G2Anim_InterpDisableController(anim,0x10,0xe,300);
            G2Anim_InterpDisableController(anim,0xe,0xe,300);
          }
        }
        else {
          if (puVar2 == (undefined *)0x1000000) {
            if (CurrentSection == 0) {
              CAMERA_ForceEndLookaroundMode(&theCamera);
            }
            Data_00 = p_Var1->Data;
            NewProcess = StateHandlerHitReaction;
            goto LAB_800a4ec8;
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCrouch(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s4*/, int Data /*stack 8*/)
 // line 890, offset 0x800a4f54
	/* begin block 1 */
		// Start line: 891
		// Start offset: 0x800A4F54
		// Variables:
	// 		struct __Event *Ptr; // $s2
	// 		int Anim; // $s6
	// 		struct _Instance *heldInst; // $s3

		/* begin block 1.1 */
			// Start line: 973
			// Start offset: 0x800A5310
			// Variables:
		// 		struct evObjectData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x800A5398
		// End Line: 985

		/* begin block 1.2 */
			// Start line: 995
			// Start offset: 0x800A541C
			// Variables:
		// 		struct _Rotation rot; // stack offset -48
		/* end block 1.2 */
		// End offset: 0x800A541C
		// End Line: 996

		/* begin block 1.3 */
			// Start line: 1045
			// Start offset: 0x800A55B8
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.3 */
		// End offset: 0x800A55F0
		// End Line: 1054
	/* end block 1 */
	// End offset: 0x800A5668
	// End Line: 1068

	/* begin block 2 */
		// Start line: 1898
	/* end block 2 */
	// End Line: 1899

void StateHandlerCrouch(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  _Instance *Inst;
  __Event *p_Var2;
  int Message;
  void *pvVar3;
  undefined *puVar4;
  code *NewProcess;
  int Data_00;
  __MessageQueue *In_00;
  _Instance *Inst_00;
  _Instance **pp_Var5;
  int local_38;
  _Rotation _Stack48;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  Inst = razGetHeldItem();
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    In_00 = &In->SectionList[CurrentSection].Event;
    p_Var2 = PeekMessageQueue(In_00);
    if (p_Var2 == (__Event *)0x0) {
      if (((*PadData & 0x100) == 0) &&
         (In->SectionList[CurrentSection].Process == StateHandlerCrouch)) {
        EnMessageQueueData(&In->SectionList[CurrentSection].Event,0x20000008,0);
      }
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == (undefined *)0x100004) {
      if ((CurrentSection == 0) &&
         (COLLIDE_SegmentCollisionOn(In->CharacterInstance,1), Inst != (_Instance *)0x0)) {
        INSTANCE_Post(Inst,0x200003,7);
        Message = 0x80002b;
        Inst_00 = Inst;
LAB_800a5378:
        INSTANCE_Post(Inst_00,Message,0);
      }
    }
    else {
      if ((int)puVar4 < 0x100005) {
        if (puVar4 != &DAT_80000008) {
          if ((int)puVar4 < -0x7ffffff7) {
            if (puVar4 == (undefined *)0x80000001) {
              if ((CurrentSection == 0) && (iVar1 != 5)) {
                Raziel.Mode = 0x20;
                Message = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0x20,(int *)0x0,(int *)0x0);
                if (Message != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x26,0,1,1);
                }
                StateSwitchStateCharacterData(In,StateHandlerCompression,0);
              }
            }
            else {
              if ((int)puVar4 < -0x7fffffff) {
                if (Inst != (_Instance *)0x0) {
                  razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x50,-1,-1);
                  pp_Var5[0x48] = (_Instance *)0x50;
                  INSTANCE_Post(Inst,0x200005,0);
                }
              }
              else {
                if (puVar4 != &DAT_80000004) goto LAB_800a55f0;
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x100000) {
              Message = SetControlInitIdleData(0,0,3);
              NewProcess = StateHandlerIdle;
LAB_800a55a8:
              StateSwitchStateData(In,CurrentSection,NewProcess,Message);
            }
            else {
              if ((int)puVar4 < 0x100001) {
                if (puVar4 == &DAT_80000010) {
                  if (CurrentSection == 0) {
                    EnMessageQueueData(&In->SectionList[0].Defer,(int)&DAT_80000010,0);
                    ControlFlag = ControlFlag | 0x800000;
                  }
LAB_800a54f4:
                  if ((iVar1 != 5) && (pp_Var5[0x48] != (_Instance *)0x50)) {
                    Message = SetControlInitIdleData(0,0,3);
                    StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Message);
                    Raziel.Mode = 0x1000000;
                  }
                }
                else {
LAB_800a55f0:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar4 != (undefined *)0x100001) goto LAB_800a55f0;
                if (CurrentSection == 0) {
                  Raziel.Mode = 0x40;
                  ControlFlag = 0x8109;
                  PhysicsMode = 3;
                  SteerSwitchMode(In->CharacterInstance,0);
                  if (p_Var2->Data == 0) {
                    Message = razSwitchVAnimCharacterGroup
                                        (In->CharacterInstance,0x4c,(int *)0x0,(int *)0x0);
                    if (Message != 0) {
                      local_38 = 2;
                      Message = 4;
                      Data_00 = 8;
                      goto LAB_800a5198;
                    }
                  }
                  else {
                    Message = razSwitchVAnimCharacterGroup
                                        (In->CharacterInstance,0x48,(int *)0x0,(int *)0x0);
                    if (Message != 0) {
                      local_38 = 1;
                      Message = 3;
                      Data_00 = 3;
LAB_800a5198:
                      G2EmulationSwitchAnimationCharacter(In,Message,0,Data_00,local_38);
                    }
                  }
                  if (Inst != (_Instance *)0x0) {
                    INSTANCE_Post(Inst,0x80002c,0);
                  }
                }
                if (p_Var2->Data == 0) {
                  pp_Var5[0x48] = (_Instance *)0x0;
                }
                else {
                  pp_Var5[0x48] = (_Instance *)0x48;
                }
              }
            }
          }
        }
      }
      else {
        if (puVar4 != (undefined *)0x4020000) {
          if ((int)puVar4 < 0x4020001) {
            if (puVar4 == (undefined *)0x2000000) {
              if ((((Raziel.Senses.EngagedMask & 4) != 0) && (Raziel.Senses.heldClass != 3)) &&
                 (iVar1 != 5)) {
                pp_Var5[0x47] = (_Instance *)0x0;
                G2EmulationSwitchAnimation(In,CurrentSection,5,0,5,1);
                ControlFlag = ControlFlag & 0xfffffff7U | 0x8041000;
                COLLIDE_SegmentCollisionOff(In->CharacterInstance,1);
                PurgeMessageQueue(In_00);
                if (CurrentSection == 0) {
                  Raziel.padCommands.Queue[8].ID._0_2_ = 300;
                  (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5b20;
                  razGetForwardNormal(In->CharacterInstance,Raziel.Senses.EngagedList[2].instance);
                  razGetRotFromNormal(&Raziel.Senses.ForwardNormal,&_Stack48);
                  (In->CharacterInstance->rotation).z = _Stack48.z;
                }
              }
            }
            else {
              if ((int)puVar4 < 0x2000001) {
                if (puVar4 != (undefined *)0x200004) goto LAB_800a55f0;
                Inst_00 = In->CharacterInstance;
                pvVar3 = (void *)p_Var2->Data;
                Inst_00->collideInfo = pvVar3;
                *(undefined2 *)((int)pvVar3 + 0x2c) = 0;
                RazielCollide(Inst_00,&gameTrackerX);
                COLLIDE_UpdateAllTransforms(Inst,(SVECTOR *)((int)Inst_00->collideInfo + 0x28));
              }
              else {
                if (puVar4 != (undefined *)0x4010400) goto LAB_800a55f0;
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x8000004) {
              razGetForwardNormal(In->CharacterInstance,Raziel.Senses.EngagedList[2].instance);
              Data_00 = SetObjectData(-(int)Raziel.Senses.ForwardNormal.x,
                                      -(int)Raziel.Senses.ForwardNormal.y,0,(_Instance *)0x0,0);
              INSTANCE_Post(Raziel.Senses.EngagedList[2].instance,0x800001,Data_00);
              Message = 0x100000;
              if ((*(uint *)(Data_00 + 0xc) & 1) == 0) {
                Inst_00 = In->CharacterInstance;
                goto LAB_800a5378;
              }
              razSetPlayerEventHistory(2);
            }
            else {
              if ((int)puVar4 < 0x8000005) {
                if (puVar4 != (undefined *)0x8000000) goto LAB_800a55f0;
                if (iVar1 == 5) {
                  Message = SetControlInitIdleData(0,0,3);
                  StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Message);
                  pp_Var5[0x47] = (_Instance *)0x1;
                  ControlFlag = ControlFlag & 0xf7ffefff;
                }
                else {
                  if (CurrentSection == 1) {
                    if ((In->SectionList[1].Data2 == 0x50) && (Inst != (_Instance *)0x0)) {
                      INSTANCE_Post(Inst,0x800008,0);
                      razReaverOn();
                    }
                    In->SectionList[0].Data2 = 0x4c;
                    pp_Var5[0x48] = (_Instance *)0x4c;
                    Inst_00 = In->CharacterInstance;
                    In->SectionList[2].Data2 = 0x4c;
                    Message = razSwitchVAnimCharacterGroup(Inst_00,0x4c,(int *)0x0,(int *)0x0);
                    if (Message != 0) {
                      G2EmulationSwitchAnimationCharacter(In,4,0,8,2);
                    }
                  }
                }
              }
              else {
                if (puVar4 != (undefined *)0x10000000) {
                  if (puVar4 == (undefined *)0x20000008) goto LAB_800a54f4;
                  goto LAB_800a55f0;
                }
                Message = 3;
                if ((Raziel.Senses.heldClass != 3) && (iVar1 != 5)) {
                  NewProcess = StateHandlerMove;
                  goto LAB_800a55a8;
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDropAction(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$s5*/)
 // line 1071, offset 0x800a5698
	/* begin block 1 */
		// Start line: 1072
		// Start offset: 0x800A5698
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 1134
			// Start offset: 0x800A5920
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.1 */
		// End offset: 0x800A5960
		// End Line: 1143
	/* end block 1 */
	// End offset: 0x800A5978
	// End Line: 1152

	/* begin block 2 */
		// Start line: 2289
	/* end block 2 */
	// End Line: 2290

void StateHandlerDropAction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *instance;
  void *pvVar2;
  int Data_00;
  int NewAnim;
  _Instance *instance_00;
  ulong Frames;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    Data_00 = p_Var1->ID;
    if (Data_00 == 0x200004) {
      instance_00 = In->CharacterInstance;
      pvVar2 = (void *)p_Var1->Data;
      instance_00->collideInfo = pvVar2;
      *(undefined2 *)((int)pvVar2 + 0x2c) = 0;
      RazielCollide(instance_00,&gameTrackerX);
      instance = razGetHeldItem();
      COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)((int)instance_00->collideInfo + 0x28));
    }
    else {
      if (Data_00 < 0x200005) {
        if (Data_00 != -0x7fffffff) {
          if (Data_00 != 0x100001) goto LAB_800a5960;
          instance = razGetHeldItem();
          if ((instance == (_Instance *)0x0) || (CurrentSection != 1)) {
            if (CurrentSection == 2) {
              Data_00 = 2;
              NewAnim = 0x45;
            }
            else {
              Data_00 = 0;
              if (CurrentSection != 0) goto LAB_800a5968;
              NewAnim = 3;
            }
            G2EmulationSwitchAnimationAlpha(In,Data_00,NewAnim,0,3,1,1);
          }
          else {
            if (Raziel.Senses.heldClass == 2) {
              Data_00 = 0x6a;
              Frames = 3;
LAB_800a580c:
              G2EmulationSwitchAnimation(In,1,Data_00,0,Frames,1);
            }
            else {
              if (Raziel.Senses.heldClass < 3) {
                if ((Raziel.Senses.heldClass != 0) && (Raziel.Senses.heldClass == 1)) {
                  Data_00 = 0x53;
                  Frames = 3;
                  goto LAB_800a580c;
                }
              }
              else {
                if (Raziel.Senses.heldClass == 3) {
                  Data_00 = 100;
                  Frames = Raziel.Senses.heldClass;
                  goto LAB_800a580c;
                }
              }
            }
            instance = razGetHeldItem();
            INSTANCE_Post(instance,0x200002,7);
            instance = razGetHeldItem();
            INSTANCE_Post(instance,0x80002c,0);
            instance = razGetHeldItem();
            INSTANCE_Post(instance,0x200005,0);
          }
        }
      }
      else {
        if (Data_00 != 0x10000000) {
          if (Data_00 < 0x10000001) {
            if (Data_00 == 0x8000000) {
              if (CurrentSection == 1) {
                instance = razGetHeldItem();
                if (instance != (_Instance *)0x0) {
                  instance = razGetHeldItem();
                  INSTANCE_Post(instance,0x800008,0);
                  razReaverOn();
                }
                Data_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
              }
            }
            else {
LAB_800a5960:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (Data_00 != 0x20000008) goto LAB_800a5960;
          }
        }
      }
    }
LAB_800a5968:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSoulSuck(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s5*/)
 // line 1159, offset 0x800a599c
	/* begin block 1 */
		// Start line: 1160
		// Start offset: 0x800A599C
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s2

		/* begin block 1.1 */
			// Start line: 1264
			// Start offset: 0x800A5E54
			// Variables:
		// 		struct evPhysicsSwimData *SwimData; // $v0
		/* end block 1.1 */
		// End offset: 0x800A5E84
		// End Line: 1271
	/* end block 1 */
	// End offset: 0x800A5EA0
	// End Line: 1279

	/* begin block 2 */
		// Start line: 2484
	/* end block 2 */
	// End Line: 2485

	/* begin block 3 */
		// Start line: 2489
	/* end block 3 */
	// End Line: 2490

void StateHandlerSoulSuck(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  _Instance *p_Var3;
  undefined *puVar4;
  int Data_00;
  TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess;
  code *NewProcess_00;
  int NewAnim;
  __State *p_Var5;
  
  if ((LoopCounter & 3U) == 0) {
    FX_MakeSoulDust(In->CharacterInstance,0x10);
  }
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var5 = In->SectionList + CurrentSection;
  do {
    p_Var2 = PeekMessageQueue(&p_Var5->Event);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == (undefined *)0x1000006) {
LAB_800a5c38:
      if (iVar1 == 0x4f) {
        G2EmulationSwitchAnimation(In,CurrentSection,0x2f,0,3,1);
        PurgeMessageQueue(&p_Var5->Event);
      }
      else {
        if (Raziel._1140_4_ == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0) {
          Data_00 = SetControlInitIdleData(0,0,3);
          NewProcess = StateHandlerIdle;
        }
        else {
          Data_00 = 0;
          NewProcess = Raziel._1140_4_;
        }
        StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
      }
      if (((Raziel.Senses.EngagedMask & 0x1000) != 0) && (CurrentSection == 0)) {
        INSTANCE_Post(Raziel.Senses.EngagedList[0xc].instance,0x1000014,0);
      }
    }
    else {
      if ((int)puVar4 < 0x1000007) {
        if (puVar4 == (undefined *)0x100001) {
          if (CurrentSection == 0) {
            ControlFlag = 9;
            PhysicsMode = 3;
            if (((Raziel.Senses.EngagedMask & 0x1000) != 0) && (Raziel.Senses.heldClass != 3)) {
              razAlignYRotMove(Raziel.Senses.EngagedList[0xc].instance,0xdc,
                               &In->CharacterInstance->position,&In->CharacterInstance->rotation,0);
              INSTANCE_Post(Raziel.Senses.EngagedList[0xc].instance,0x1000014,1);
            }
            G2EmulationSwitchAnimationAlpha(In,0,0x4e,0,4,1,4);
          }
          if (CurrentSection == 2) {
            G2EmulationSwitchAnimation(In,2,0,0,4,2);
          }
          if (CurrentSection == 1) {
            p_Var3 = razGetHeldWeapon();
            if ((p_Var3 == (_Instance *)0x0) && ((Raziel.Senses.EngagedMask & 0x1000) == 0)) {
              Data_00 = 0x4e;
            }
            else {
              Data_00 = 0x5f;
            }
            G2EmulationSwitchAnimation(In,1,Data_00,0,4,1);
            Raziel.Mode = Raziel.Mode | 0x10000000;
          }
        }
        else {
          if ((int)puVar4 < 0x100002) {
            if (puVar4 != &DAT_80000010) {
LAB_800a5e88:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 == (undefined *)0x100004) {
              if (CurrentSection == 1) {
                razSetCowlNoDraw(1);
                ControlFlag = ControlFlag & 0xffffffbf;
                Raziel.Mode = Raziel.Mode & 0xefffffff;
              }
            }
            else {
              if (puVar4 != (undefined *)0x1000001) goto LAB_800a5e88;
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x4020000) {
          if ((*(ushort *)(p_Var2->Data + 0x10) & 0x40) != 0) {
            StateHandlerInitSwim(In,CurrentSection,0);
          }
        }
        else {
          if ((int)puVar4 < 0x4020001) {
            if (puVar4 == (undefined *)0x1000009) {
              NewAnim = 0x50;
              Data_00 = 2;
LAB_800a5e40:
              G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,Data_00,1);
            }
            else {
              if (puVar4 != (undefined *)0x1000016) goto LAB_800a5e88;
              if (((gameTrackerX.debugFlags2 & 0x800U) != 0) && (CurrentSection == 0)) {
                GainHealth(p_Var2->Data);
                razSetPlayerEventHistory(0x1000);
              }
            }
          }
          else {
            if (puVar4 != (undefined *)0x8000000) {
              if (puVar4 == (undefined *)0x20000002) goto LAB_800a5c38;
              goto LAB_800a5e88;
            }
            if (iVar1 == 0x2f) {
              if (Raziel._1140_4_ == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0) {
                Data_00 = SetControlInitIdleData(0,0,3);
                NewProcess_00 = StateHandlerIdle;
              }
              else {
                Data_00 = 0;
                NewProcess_00 = Raziel._1140_4_;
              }
              StateSwitchStateData(In,CurrentSection,NewProcess_00,Data_00);
            }
            if (iVar1 == 0x4e) {
              G2EmulationSwitchAnimation(In,CurrentSection,0x4f,0,0,1);
            }
            if (iVar1 == 0x50) {
              if ((*PadData & 0x40) != 0) {
                NewAnim = 0x4f;
                Data_00 = 8;
                goto LAB_800a5e40;
              }
              if (Raziel._1140_4_ == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0) {
                Data_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
              }
              else {
                StateSwitchStateData(In,CurrentSection,Raziel._1140_4_,0);
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var5->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStartTurn(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s3*/)
 // line 1285, offset 0x800a5ec4
	/* begin block 1 */
		// Start line: 1286
		// Start offset: 0x800A5EC4
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800A60A8
	// End Line: 1346

	/* begin block 2 */
		// Start line: 2746
	/* end block 2 */
	// End Line: 2747

void StateHandlerStartTurn(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  code *NewProcess;
  
  G2EmulationQueryFrame(In,CurrentSection);
  if (Raziel.Bearing == 0) {
    EnMessageQueueData(&In->SectionList[CurrentSection].Defer,0x100000,0);
  }
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    Data_00 = p_Var1->ID;
    if (Data_00 == 0x100000) {
LAB_800a5fd8:
      if (CurrentSection == 0) {
        if ((*PadData & 0x8000000fU) == 0) {
          Data_00 = SetControlInitIdleData(0,0,3);
          StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
        }
        else {
          NewProcess = StateHandlerStartMove;
LAB_800a6080:
          StateSwitchStateCharacterData(In,NewProcess,0);
        }
      }
    }
    else {
      if (Data_00 < 0x100001) {
        if (Data_00 == -0x7fffffff) {
          if (CurrentSection == 0) {
            Raziel.Mode = 8;
            Data_00 = razSwitchVAnimCharacterGroup(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
            if (Data_00 != 0) {
              G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
            }
            NewProcess = StateHandlerCompression;
            goto LAB_800a6080;
          }
        }
        else {
          if (Data_00 == 0) goto LAB_800a5fd8;
LAB_800a6090:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (Data_00 != 0x100001) {
          if (Data_00 != 0x8000000) goto LAB_800a6090;
          goto LAB_800a5fd8;
        }
        if (CurrentSection == 0) {
          Raziel.Mode = 0x4000;
          ControlFlag = 0x20109;
          PhysicsMode = 3;
          SteerSwitchMode(In->CharacterInstance,1);
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateInitStartMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Frame /*$s2*/)
 // line 1350, offset 0x800a60c4
	/* begin block 1 */
		// Start line: 1351
		// Start offset: 0x800A60C4

		/* begin block 1.1 */
			// Start line: 1358
			// Start offset: 0x800A6114
			// Variables:
		// 		int frames[3]; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x800A6168
		// End Line: 1364
	/* end block 1 */
	// End offset: 0x800A6168
	// End Line: 1365

	/* begin block 2 */
		// Start line: 2881
	/* end block 2 */
	// End Line: 2882

	/* begin block 3 */
		// Start line: 2884
	/* end block 3 */
	// End Line: 2885

void StateInitStartMove(__CharacterState *In,int CurrentSection,int Frame)

{
  int iVar1;
  int local_20;
  int local_1c;
  undefined4 local_18;
  
  if ((*PadData & 0x200) != 0) {
    StateSwitchStateData(In,CurrentSection,StateHandlerMove,3);
  }
  if (CurrentSection == 0) {
    local_1c = 0xffffffff;
    local_18 = 0xffffffff;
    local_20 = Frame;
    iVar1 = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x30,&local_20,(int *)0x0);
    if (iVar1 != 0) {
      local_1c = Frame;
      razSwitchVAnimCharacterSingle(In->CharacterInstance,0,&local_20,(int *)0x0);
    }
  }
  ControlFlag = ControlFlag | 0x2000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStartMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 1434, offset 0x800a618c
	/* begin block 1 */
		// Start line: 1435
		// Start offset: 0x800A618C
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 1491
			// Start offset: 0x800A645C
			// Variables:
		// 		int mode; // $a0
		/* end block 1.1 */
		// End offset: 0x800A64B4
		// End Line: 1509
	/* end block 1 */
	// End offset: 0x800A67A0
	// End Line: 1589

	/* begin block 2 */
		// Start line: 3121
	/* end block 2 */
	// End Line: 3122

void StateHandlerStartMove(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  _Instance *p_Var2;
  undefined *puVar3;
  uint mode;
  _Instance **pp_Var4;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      if ((*PadData & 0x8000000fU) != 0) {
        pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
        p_Var2 = (_Instance *)((int)&(pp_Var4[0x48]->node).prev + 1);
        if ((pp_Var4[0x48] != (_Instance *)0x0) && (pp_Var4[0x48] = p_Var2, 7 < (int)p_Var2)) {
          G2EmulationSetMode(In,CurrentSection,1);
          pp_Var4[0x48] = (_Instance *)0x0;
          ControlFlag = ControlFlag & 0xffffdfff;
        }
      }
      Data_00 = G2EmulationQueryFrame(In,CurrentSection);
      if (((10 < Data_00) && (CurrentSection == 0)) &&
         (Data_00 = CheckHolding(In->CharacterInstance), Data_00 != 0)) {
        if (In->SectionList[1].Process == StateHandlerStartMove) {
          StateSwitchStateData(In,1,StateHandlerMove,5);
        }
        if (In->SectionList[2].Process == StateHandlerStartMove) {
          StateSwitchStateData(In,2,StateHandlerMove,5);
        }
      }
      if (((Raziel.Magnitude != 0) && (Raziel.Magnitude < 0x1000)) &&
         ((Raziel.throwReturnRot & 1U) != 0)) {
        StateSwitchStateData(In,CurrentSection,StateHandlerMove,0);
      }
      return;
    }
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 == (undefined *)0x100001) {
      StateInitStartMove(In,CurrentSection,p_Var1->Data);
      In->SectionList[CurrentSection].Data2 = 1;
      if (CurrentSection == 0) {
        Raziel.Mode = 4;
        ControlFlag = 0x2a119;
        PhysicsMode = 3;
        SteerSwitchMode(In->CharacterInstance,2);
        Raziel.movementMinRate = 0xccc;
        Raziel.movementMinAnalog = 0x400;
        Raziel.movementMaxAnalog = 0x1000;
        Raziel.throwReturnRot = 0;
      }
    }
    else {
      if ((int)puVar3 < 0x100002) {
        if (puVar3 == &DAT_80000002) {
LAB_800a6408:
          if (CurrentSection == 0) {
            EnMessageQueueData(&In->SectionList[0].Defer,p_Var1->ID,0);
            ControlFlag = ControlFlag | 0x800000;
LAB_800a6430:
            if (CurrentSection == 0) {
              if (((Raziel.throwReturnRot & 7U) != 0) ||
                 (Data_00 = G2EmulationQueryMode(In,0), Data_00 == 0)) {
                if ((Raziel.throwReturnRot & 1U) == 0) {
                  mode = Raziel.throwReturnRot & 4;
                  if ((Raziel.throwReturnRot & 2U) != 0) {
                    mode = 3;
                  }
                }
                else {
                  mode = 2;
                }
                Data_00 = SetControlInitIdleData(mode,5,5);
                StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
                ControlFlag = ControlFlag & 0xffffdfff;
              }
              ControlFlag = ControlFlag | 0x2000;
            }
          }
        }
        else {
          if ((int)puVar3 < -0x7ffffffd) {
            if (puVar3 == (undefined *)0x80000000) {
              StateSwitchStateData(In,CurrentSection,StateHandlerAttack2,10);
            }
            else {
              if (puVar3 != (undefined *)0x80000001) goto LAB_800a6658;
              if (CurrentSection == 0) {
                Raziel.Mode = 8;
                Data_00 = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (Data_00 != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
                }
                StateSwitchStateCharacterData(In,StateHandlerCompression,0);
LAB_800a6524:
                ControlFlag = ControlFlag & 0xffffdfff;
              }
            }
            goto LAB_800a6664;
          }
          if (puVar3 == &DAT_80000010) goto LAB_800a6408;
          if ((int)puVar3 < -0x7fffffef) {
            if (puVar3 == &DAT_80000004) {
              StateSwitchStateData(In,CurrentSection,StateHandlerMove,3);
              goto LAB_800a6664;
            }
          }
          else {
            if (puVar3 == (undefined *)0x0) goto LAB_800a6430;
          }
LAB_800a6658:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar3 == (undefined *)0x4010401) {
          Data_00 = SetControlInitIdleData(0,5,5);
          StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
        }
        else {
          if ((int)puVar3 < 0x4010402) {
            if (puVar3 == (undefined *)0x4000001) {
              if ((CurrentSection == 0) && (Data_00 = G2EmulationQueryFrame(In,0), 6 < Data_00)) {
                PhysicsMode = 0;
                SetDropPhysics(In->CharacterInstance,&Raziel);
                if (In->CharacterInstance->zVel < -0x20) {
                  Data_00 = razSwitchVAnimCharacterGroup
                                      (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                  if (Data_00 != 0) {
                    G2EmulationSwitchAnimationCharacter(In,0x24,0,4,1);
                  }
                  StateSwitchStateCharacterData(In,StateHandlerFall,0);
                }
              }
            }
            else {
              if ((int)puVar3 < 0x4000002) {
                if (puVar3 != (undefined *)0x2000000) goto LAB_800a6658;
                razPickupAndGrab(In,CurrentSection);
              }
              else {
                if (puVar3 != (undefined *)0x4010080) goto LAB_800a6658;
                if (CurrentSection != 2) {
                  G2EmulationSetMode(In,CurrentSection,(uint)(p_Var1->Data != 0));
                }
                if (((Raziel.throwReturnRot & 2U) != 0) && ((*PadData & 0x8000000fU) != 0)) {
                  G2EmulationSetMode(In,CurrentSection,2);
                  goto LAB_800a6524;
                }
              }
            }
          }
          else {
            if ((int)puVar3 < 0x8000000) goto LAB_800a6658;
            if ((int)puVar3 < 0x8000002) {
              if ((CurrentSection == 0) ||
                 (Data_00 = CheckHolding(In->CharacterInstance), Data_00 == 0)) {
                StateSwitchStateData(In,CurrentSection,StateHandlerMove,0);
              }
            }
            else {
              if (puVar3 != (undefined *)0x10000000) goto LAB_800a6658;
            }
          }
        }
      }
    }
LAB_800a6664:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateInitMove(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s0*/, int Frames /*$a2*/)
 // line 1592, offset 0x800a67c0
	/* begin block 1 */
		// Start line: 3453
	/* end block 1 */
	// End Line: 3454

	/* begin block 2 */
		// Start line: 3457
	/* end block 2 */
	// End Line: 3458

void StateInitMove(__CharacterState *In,int CurrentSection,int Frames)

{
  uint uVar1;
  int iVar2;
  
  if ((*PadData & 0x200) == 0) {
    if ((*PadData & 0x100) == 0) {
      Raziel.Mode = 4;
      if ((ControlFlag & 0x800000U) == 0) {
        ControlFlag = 0;
      }
      else {
        ControlFlag = 0x800000;
      }
      uVar1 = ControlFlag | 0x28119;
      if ((Raziel.Abilities & 0x20U) != 0) {
        uVar1 = ControlFlag | 0x228119;
      }
      ControlFlag = uVar1;
      razSelectMotionAnim(In,CurrentSection,Frames,&In->SectionList[CurrentSection].Data2);
    }
    else {
      Raziel.Mode = 0x1000000;
      if ((ControlFlag & 0x800000U) == 0) {
        ControlFlag = 0;
      }
      else {
        ControlFlag = 0x800000;
      }
      ControlFlag = ControlFlag | 0x2119;
      if ((&In->CharacterInstance + CurrentSection * 0x47)[0x48] != (_Instance *)0x38) {
        razResetMotion(In->CharacterInstance);
        iVar2 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x38,-1,-1);
        if (iVar2 != 0) {
          G2EmulationSwitchAnimation(In,CurrentSection,0x4a,0,3,2);
        }
        (&In->CharacterInstance + CurrentSection * 0x47)[0x48] = (_Instance *)0x38;
      }
    }
  }
  else {
    Raziel.Mode = 2;
    if ((ControlFlag & 0x800000U) == 0) {
      ControlFlag = 0;
    }
    else {
      ControlFlag = 0x800000;
    }
    ControlFlag = ControlFlag | 0x22119;
    if ((&In->CharacterInstance + CurrentSection * 0x47)[0x48] != (_Instance *)0x34) {
      razResetMotion(In->CharacterInstance);
      iVar2 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x34,-1,-1);
      if (iVar2 != 0) {
        razSwitchVAnimSingle(In->CharacterInstance,CurrentSection,1,-1,-1);
      }
      (&In->CharacterInstance + CurrentSection * 0x47)[0x48] = (_Instance *)0x34;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerMove(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s5*/)
 // line 1793, offset 0x800a6a14
	/* begin block 1 */
		// Start line: 1794
		// Start offset: 0x800A6A14
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 1841
			// Start offset: 0x800A6CAC
			// Variables:
		// 		int data; // $a2
		/* end block 1.1 */
		// End offset: 0x800A6CDC
		// End Line: 1852
	/* end block 1 */
	// End offset: 0x800A6ED0
	// End Line: 1912

	/* begin block 2 */
		// Start line: 3863
	/* end block 2 */
	// End Line: 3864

void StateHandlerMove(__CharacterState *In,int CurrentSection,int Data)

{
  _Instance **pp_Var1;
  __Event *p_Var2;
  int Data_00;
  undefined *puVar3;
  int local_24;
  
  G2EmulationQueryAnimation(In,CurrentSection);
  pp_Var1 = &In->CharacterInstance + CurrentSection * 0x47;
  pp_Var1[0x47] = (_Instance *)((int)&(pp_Var1[0x47]->node).prev + 1);
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      if ((CurrentSection == 0) && (In->SectionList[0].Process != StateHandlerMove)) {
        razResetMotion(In->CharacterInstance);
      }
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == (undefined *)0x100001) {
      pp_Var1[0x48] = (_Instance *)0xffffffff;
      StateInitMove(In,CurrentSection,p_Var2->Data);
      Raziel.constrictFlag = 1;
      SteerSwitchMode(In->CharacterInstance,2);
      pp_Var1[0x47] = (_Instance *)0x0;
      Raziel.throwReturnRot = Raziel.throwReturnRot | 0x1000;
    }
    else {
      if ((int)puVar3 < 0x100002) {
        if (puVar3 == &DAT_80000002) {
LAB_800a6c18:
          if (CurrentSection == 0) {
            EnMessageQueueData(&In->SectionList[0].Defer,p_Var2->ID,0);
            ControlFlag = ControlFlag | 0x800000;
          }
LAB_800a6c3c:
          if (Raziel.Mode == 2) {
            if (CurrentSection == 0) {
              Data_00 = SetControlInitIdleData(0,0,3);
              StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
            }
          }
          else {
            if (Raziel.Mode == 0x1000000) {
              if (CurrentSection == 0) {
                StateSwitchStateCharacterData(In,StateHandlerCrouch,0);
              }
            }
            else {
              Data_00 = 0;
              if ((Raziel.throwReturnRot & 0x2000U) != 0) {
                Data_00 = 0x1e;
              }
              if ((Raziel.throwReturnRot & 0x1000U) != 0) {
                Data_00 = 0x3c;
              }
              if (CurrentSection == 0) {
                StateSwitchStateCharacterData(In,StateHandlerStopMove,Data_00);
              }
            }
          }
        }
        else {
          if ((int)puVar3 < -0x7ffffffd) {
            if (puVar3 == (undefined *)0x80000000) {
              if ((Raziel.Mode & 2U) == 0) {
                if (pp_Var1[0x48] == (_Instance *)0x38) {
                  if (Raziel.Senses.heldClass != 0) {
                    StateSwitchStateData(In,CurrentSection,StateHandlerDropAction,0);
                  }
                }
                else {
                  StateSwitchStateData(In,CurrentSection,StateHandlerAttack2,10);
                  Raziel.dropOffHeight = 200;
                  Raziel.fallZVelocity = -0x60;
                }
              }
            }
            else {
              if (puVar3 != (undefined *)0x80000001) goto LAB_800a6e90;
              if (CurrentSection == 0) {
                Raziel.Mode = 8;
                Data_00 = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (Data_00 != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
                }
                StateSwitchStateCharacterData(In,StateHandlerCompression,0);
                goto LAB_800a6dec;
              }
            }
          }
          else {
            if (puVar3 == &DAT_80000010) goto LAB_800a6c18;
            if ((int)puVar3 < -0x7fffffef) {
              if (puVar3 == &DAT_80000004) {
                if (CurrentSection != 2) {
                  local_24 = 2;
                  Data_00 = CurrentSection;
                }
                else {
                  Data_00 = 2;
                  local_24 = CurrentSection;
                }
                G2EmulationSwitchAnimation(In,Data_00,(uint)(CurrentSection != 2),0,3,local_24);
                Raziel.Mode = 2;
                ControlFlag = ControlFlag | 0x2000;
                goto LAB_800a6e9c;
              }
            }
            else {
              if (puVar3 == (undefined *)0x0) goto LAB_800a6c3c;
            }
LAB_800a6e90:
            DefaultStateHandler(In,CurrentSection,Data);
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x4010080) {
          if (CurrentSection != 2) {
            if (p_Var2->Data == 0) {
              G2EmulationSetMode(In,CurrentSection,0);
            }
            else {
              G2EmulationSetMode(In,CurrentSection,2);
            }
          }
        }
        else {
          if ((int)puVar3 < 0x4010081) {
            if (puVar3 == (undefined *)0x100004) {
              FX_EndConstrict(0,(_Instance *)0x0);
            }
            else {
              if (puVar3 != (undefined *)0x2000000) goto LAB_800a6e90;
              razPickupAndGrab(In,CurrentSection);
            }
          }
          else {
            if (puVar3 != (undefined *)0x20000004) {
              if ((int)puVar3 < 0x20000005) {
                if (puVar3 == (undefined *)0x10000000) {
                  StateInitMove(In,CurrentSection,0);
                  goto LAB_800a6e9c;
                }
              }
              else {
                if (puVar3 == (undefined *)0x20000008) goto LAB_800a6d64;
              }
              goto LAB_800a6e90;
            }
LAB_800a6d64:
            G2EmulationSwitchAnimation(In,CurrentSection,2,0,3,2);
            Raziel.Mode = 4;
LAB_800a6dec:
            ControlFlag = ControlFlag & 0xffffdfff;
          }
        }
      }
    }
LAB_800a6e9c:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStopMove(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 1915, offset 0x800a6ef4
	/* begin block 1 */
		// Start line: 1916
		// Start offset: 0x800A6EF4
		// Variables:
	// 		struct __Event *Ptr; // $a1
	/* end block 1 */
	// End offset: 0x800A71F8
	// End Line: 2008

	/* begin block 2 */
		// Start line: 4116
	/* end block 2 */
	// End Line: 4117

void StateHandlerStopMove(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int anim;
  undefined *puVar2;
  long frames;
  __State *p_Var3;
  
  p_Var3 = In->SectionList + CurrentSection;
  do {
    p_Var1 = PeekMessageQueue(&p_Var3->Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100001) {
      if (CurrentSection == 0) {
        Raziel.Mode = 4;
        if ((ControlFlag & 0x800000U) == 0) {
          ControlFlag = 0;
        }
        else {
          ControlFlag = 0x800000;
        }
        PhysicsMode = 3;
        ControlFlag = ControlFlag | 0x2119;
      }
      if (p_Var1->Data == 0x3c) {
        anim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x58,-1,-1);
        if (anim != 0) {
          anim = 2;
LAB_800a7094:
          razSwitchVAnimSingle(In->CharacterInstance,CurrentSection,anim,-1,-1);
        }
      }
      else {
        if (p_Var1->Data == 0x1e) {
          anim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x5c,-1,-1);
          if (anim != 0) {
            anim = 3;
            goto LAB_800a7094;
          }
        }
        else {
          frames = 6;
LAB_800a715c:
          anim = SetControlInitIdleData(0,0,frames);
          StateSwitchStateData(In,CurrentSection,StateHandlerIdle,anim);
        }
      }
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 == &DAT_80000002) {
LAB_800a7138:
          EnMessageQueueData(&p_Var3->Defer,p_Var1->ID,0);
        }
        else {
          if ((int)puVar2 < -0x7ffffffd) {
            if (puVar2 == (undefined *)0x80000001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x10;
                anim = razSwitchVAnimCharacterGroup(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (anim != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
                }
                StateSwitchStateCharacterData(In,StateHandlerCompression,0);
              }
              goto LAB_800a71e8;
            }
          }
          else {
            if (puVar2 == &DAT_80000010) goto LAB_800a7138;
          }
LAB_800a71e0:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if ((int)puVar2 < 0x8000002) {
          if (0x7ffffff < (int)puVar2) {
            frames = 5;
            goto LAB_800a715c;
          }
          if (puVar2 != (undefined *)0x4010080) goto LAB_800a71e0;
          if (CurrentSection == 0) {
            if (p_Var1->Data == 0) {
              razSetPauseTranslation(In->CharacterInstance);
              anim = SetControlInitIdleData(0,0,5);
              StateSwitchStateCharacterData(In,StateHandlerIdle,anim);
            }
            else {
              razResetPauseTranslation(In->CharacterInstance);
            }
          }
        }
        else {
          if (puVar2 != (undefined *)0x10000000) goto LAB_800a71e0;
          StateSwitchStateData(In,CurrentSection,StateHandlerStartMove,10);
        }
      }
    }
LAB_800a71e8:
    DeMessageQueue(&p_Var3->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCompression(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 2015, offset 0x800a7218
	/* begin block 1 */
		// Start line: 2016
		// Start offset: 0x800A7218
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800A75C0
	// End Line: 2111

	/* begin block 2 */
		// Start line: 4327
	/* end block 2 */
	// End Line: 4328

void StateHandlerCompression(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  __State *p_Var2;
  __Event *p_Var3;
  long lVar4;
  _G2Bool_Enum _Var5;
  int iVar6;
  _Instance *p_Var7;
  uint uVar8;
  __State *p_Var9;
  
  p_Var9 = In->SectionList + CurrentSection;
  do {
    p_Var3 = PeekMessageQueue(&p_Var9->Event);
    if (p_Var3 == (__Event *)0x0) {
      return;
    }
    iVar6 = p_Var3->ID;
    if (iVar6 != 0x4000001) {
      if (iVar6 < 0x4000002) {
        if (iVar6 == -0x7fffffff) {
          uVar8 = 0x80000000;
          p_Var2 = p_Var9;
LAB_800a7594:
          EnMessageQueueData(&p_Var2->Defer,uVar8 | 1,0);
        }
        else {
          if (-0x80000000 < iVar6) {
            if (iVar6 != 0x100001) goto LAB_800a75a8;
            if (CurrentSection == 0) {
              ControlFlag = 0x111;
              SetExternalForce(&__Force_800d5c64,0,0,0,1,0);
              In->SectionList[0].Data1 = 0;
              PhysicsMode = 3;
              Raziel.movementMinRate = 0;
              if (Raziel.Mode == 0x10) {
                SteerSwitchMode(In->CharacterInstance,4);
                sVar1 = (In->CharacterInstance->rotation).z;
                p_Var7 = In->CharacterInstance;
                lVar4 = 0x28;
              }
              else {
                if ((Raziel.Mode < 0x11) || (Raziel.Mode != 0x20)) goto LAB_800a75b0;
                SteerSwitchMode(In->CharacterInstance,4);
                sVar1 = (In->CharacterInstance->rotation).z;
                p_Var7 = In->CharacterInstance;
                lVar4 = 0x15;
              }
              Raziel.steeringLockRotation = (int)sVar1;
              p_Var7->yVel = lVar4;
              _Var5 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,1,0xe);
              if (_Var5 == G2FALSE) {
                G2Anim_EnableController(&In->CharacterInstance->anim,1,0xe);
              }
            }
          }
        }
      }
      else {
        if (iVar6 == 0x8000000) {
          if (Raziel.Mode == 8) {
            if (CurrentSection == 0) {
              iVar6 = razSwitchVAnimCharacterGroup(In->CharacterInstance,4,(int *)0x0,(int *)0x0);
              if (iVar6 != 0) {
                G2EmulationSwitchAnimationCharacter(In,0x1b,0,0,1);
              }
              SetPhysics(In->CharacterInstance,-0x10,0,0x53,0x9a);
            }
          }
          else {
            if (Raziel.Mode == 0x20) {
              if (CurrentSection == 0) {
                iVar6 = razSwitchVAnimCharacterGroup
                                  (In->CharacterInstance,0x24,(int *)0x0,(int *)0x0);
                if (iVar6 != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x27,0,0,1);
                }
                SetPhysics(In->CharacterInstance,-0x10,0,0x15,0xc3);
                In->CharacterInstance->yVel = 0;
              }
            }
            else {
              if (CurrentSection == 0) {
                iVar6 = razSwitchVAnimCharacterGroup
                                  (In->CharacterInstance,0x14,(int *)0x0,(int *)0x0);
                if (iVar6 != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x23,0,0,1);
                }
                SetPhysics(In->CharacterInstance,-0x10,0,0x28,0x9a);
                In->CharacterInstance->yVel = 0;
                if (In->SectionList[0].Data1 == 1) {
                  In->CharacterInstance->zVel = (In->CharacterInstance->zVel << 1) / 3;
                }
              }
            }
          }
          StateSwitchStateData(In,CurrentSection,StateHandlerJump,0);
        }
        else {
          if (iVar6 < 0x8000001) {
            if (iVar6 != 0x4020000) {
LAB_800a75a8:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (iVar6 != 0x20000001) goto LAB_800a75a8;
            if (CurrentSection == 0) {
              if (Raziel.Mode == 0x10) {
                In->SectionList[0].Data1 = 1;
              }
              p_Var2 = In->SectionList;
              uVar8 = 0x20000000;
              goto LAB_800a7594;
            }
          }
        }
      }
    }
LAB_800a75b0:
    DeMessageQueue(&p_Var9->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerJump(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 2114, offset 0x800a75e0
	/* begin block 1 */
		// Start line: 2115
		// Start offset: 0x800A75E0
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800A79DC
	// End Line: 2211

	/* begin block 2 */
		// Start line: 4548
	/* end block 2 */
	// End Line: 4549

void StateHandlerJump(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int NewAnim;
  undefined *puVar2;
  __MessageQueue *In_00;
  uint uVar3;
  int Frames;
  __State *p_Var4;
  
  p_Var4 = In->SectionList + CurrentSection;
  do {
    p_Var1 = PeekMessageQueue(&p_Var4->Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x2000000) {
      razPickupAndGrab(In,CurrentSection);
      goto LAB_800a79cc;
    }
    if ((int)puVar2 < 0x2000001) {
      if (puVar2 != &DAT_80000008) {
        if ((int)puVar2 < -0x7ffffff7) {
          if (puVar2 != (undefined *)0x80000000) {
            if (puVar2 != (undefined *)0x80000001) goto LAB_800a79c4;
            NewAnim = G2EmulationQueryFrame(In,CurrentSection);
            In_00 = &p_Var4->Defer;
            if (1 < NewAnim) {
              if (Raziel.Senses.heldClass != 3) {
                StateSwitchStateData(In,CurrentSection,StateHandlerGlide,0);
              }
              goto LAB_800a79cc;
            }
            uVar3 = 0x80000000;
LAB_800a799c:
            EnMessageQueueData(In_00,uVar3 | 1,0);
          }
        }
        else {
          if (puVar2 == (undefined *)0x100001) {
            if (CurrentSection == 0) {
              ControlFlag = 0x511;
              Raziel.padCommands.Queue[8].ID._0_2_ = 200;
              PhysicsMode = 0;
              (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5b20;
            }
            In->SectionList[CurrentSection].Data2 = 0;
          }
          else {
            if ((int)puVar2 < 0x100002) {
              if (puVar2 != &DAT_80000020) {
LAB_800a79c4:
                DefaultStateHandler(In,CurrentSection,Data);
              }
            }
            else {
              if (puVar2 != (undefined *)0x1000001) goto LAB_800a79c4;
            }
          }
        }
      }
    }
    else {
      if (puVar2 != (undefined *)0x4020000) {
        if ((int)puVar2 < 0x4020001) {
          if ((puVar2 != (undefined *)0x4000001) && (puVar2 != (undefined *)0x4010008))
          goto LAB_800a79c4;
        }
        else {
          if (puVar2 == (undefined *)0x8000004) {
            ControlFlag = ControlFlag | 8;
          }
          else {
            if (0x8000004 < (int)puVar2) {
              if (puVar2 != (undefined *)0x20000001) goto LAB_800a79c4;
              In->SectionList[CurrentSection].Data2 = 1;
              if (CurrentSection != 0) goto LAB_800a79cc;
              if ((Raziel.Mode == 0x10) || (Raziel.Mode == 0x20)) {
                In_00 = &In->SectionList[0].Defer;
                uVar3 = 0x20000000;
                goto LAB_800a799c;
              }
              if (In->SectionList[0].Data1 == 0) {
                NewAnim = G2EmulationQueryFrame(In,0);
                In->SectionList[0].Data1 = NewAnim + 4;
                if (NewAnim + 4 != 0) goto LAB_800a78d8;
              }
              else {
LAB_800a78d8:
                NewAnim = G2EmulationQueryFrame(In,0);
                if (In->SectionList[0].Data1 < NewAnim) {
                  SetDropPhysics(In->CharacterInstance,&Raziel);
                  NewAnim = razSwitchVAnimCharacterGroup
                                      (In->CharacterInstance,8,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    G2EmulationSwitchAnimationCharacter(In,0x1c,0,7,1);
                  }
                  StateSwitchStateCharacterData(In,StateHandlerFall,In->SectionList[0].Data2);
                  goto LAB_800a79cc;
                }
              }
              In_00 = &p_Var4->Defer;
              uVar3 = 0x20000000;
              goto LAB_800a799c;
            }
            if (puVar2 != (undefined *)0x8000000) goto LAB_800a79c4;
            if (CurrentSection == 0) {
              if (Raziel.Mode == 0x10) {
                NewAnim = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                if (NewAnim != 0) {
                  NewAnim = 0x24;
                  Frames = 4;
                  goto LAB_800a7834;
                }
              }
              else {
                if (Raziel.Mode == 0x20) {
                  NewAnim = razSwitchVAnimCharacterGroup
                                      (In->CharacterInstance,0x28,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    NewAnim = 0x28;
                    Frames = 10;
LAB_800a7834:
                    G2EmulationSwitchAnimationCharacter(In,NewAnim,0,Frames,1);
                  }
                }
                else {
                  NewAnim = razSwitchVAnimCharacterGroup
                                      (In->CharacterInstance,8,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    NewAnim = 0x1c;
                    Frames = 7;
                    goto LAB_800a7834;
                  }
                }
              }
            }
            StateSwitchStateData(In,CurrentSection,StateHandlerFall,0);
            if ((*PadData & 0x80) == 0) {
              In->SectionList[CurrentSection].Data2 = 1;
            }
          }
        }
      }
    }
LAB_800a79cc:
    DeMessageQueue(&p_Var4->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerFall(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
 // line 2214, offset 0x800a7a04
	/* begin block 1 */
		// Start line: 2215
		// Start offset: 0x800A7A04
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Moving; // $s6
	// 		int DeferFlag; // $s5
	// 		struct evPhysicsSwimData *SwimData; // $a0

		/* begin block 1.1 */
			// Start line: 2233
			// Start offset: 0x800A7A48
		/* end block 1.1 */
		// End offset: 0x800A7A7C
		// End Line: 2239
	/* end block 1 */
	// End offset: 0x800A7DE0
	// End Line: 2415

	/* begin block 2 */
		// Start line: 4786
	/* end block 2 */
	// End Line: 4787

void StateHandlerFall(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  bool bVar2;
  Level *pLVar3;
  __Event *p_Var4;
  undefined *puVar5;
  __State *p_Var6;
  int Data_00;
  
  Data_00 = 0;
  bVar2 = true;
  if (CurrentSection == 0) {
    pLVar3 = STREAM_GetLevelWithID(In->CharacterInstance->currentStreamUnitID);
    if ((pLVar3->unitFlags & 0x1000U) != 0) {
      EnMessageQueueData(&In->SectionList[0].Event,0x100000,0);
    }
  }
  p_Var6 = In->SectionList + CurrentSection;
  do {
    p_Var4 = PeekMessageQueue(&p_Var6->Event);
    if (p_Var4 == (__Event *)0x0) {
      return;
    }
    puVar5 = (undefined *)p_Var4->ID;
    if (puVar5 != (undefined *)0x1000001) {
      if ((int)puVar5 < 0x1000002) {
        if (puVar5 != &DAT_80000008) {
          if ((int)puVar5 < -0x7ffffff7) {
            if (puVar5 != (undefined *)0x80000000) {
              if (puVar5 != (undefined *)0x80000001) goto LAB_800a7dc8;
              if ((Raziel.Senses.heldClass != 3) && ((ControlFlag & 0x2000000U) == 0)) {
                StateSwitchStateData(In,CurrentSection,StateHandlerGlide,3);
              }
            }
          }
          else {
            if (puVar5 == (undefined *)0x100000) {
              StateSwitchStateCharacterData(In,StateHandlerForcedGlide,0);
            }
            else {
              if ((int)puVar5 < 0x100001) {
                if (puVar5 != &DAT_80000020) {
LAB_800a7dc8:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar5 != (undefined *)0x100001) goto LAB_800a7dc8;
                if (CurrentSection == 0) {
                  ControlFlag = 0x119;
                  if (Raziel.Mode != 0x100) {
                    ControlFlag = 0x519;
                  }
                  In->SectionList[0].Data1 = 0;
                  Raziel.movementMinRate = 0;
                  PhysicsMode = 0;
                }
                if ((p_Var4->Data != 0) && ((*PadData & 0x80) != 0)) {
                  EnMessageQueueData(&p_Var6->Defer,-0x7fffffff,0);
                }
              }
            }
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x4020000) {
          sVar1 = *(short *)(p_Var4->Data + 0xe);
          if (((sVar1 < 0) && (sVar1 != -0x7fff)) && (Raziel.CurrentPlane == 1)) {
            ControlFlag = ControlFlag | 0x2000000;
          }
          if ((*(short *)(p_Var4->Data + 0xc) < 0) && (In->CharacterInstance->zVel == 0)) {
            ResetPhysics(In->CharacterInstance,-0x10);
          }
          razEnterWater(In,CurrentSection,(evPhysicsSwimData *)p_Var4->Data);
        }
        else {
          if ((int)puVar5 < 0x4020001) {
            if (puVar5 != (undefined *)0x4000001) {
              if ((int)puVar5 < 0x4000002) {
                if (puVar5 != (undefined *)0x2000000) goto LAB_800a7dc8;
                razPickupAndGrab(In,CurrentSection);
              }
              else {
                if (puVar5 != (undefined *)0x4010008) goto LAB_800a7dc8;
                if (bVar2) {
                  EnMessageQueueData(&p_Var6->Event,0x4010008,0);
                  bVar2 = false;
                }
                else {
                  StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,Data_00);
                }
                In->SectionList[CurrentSection].Data2 = 2;
                PhysicsMode = 3;
                ResetPhysics(In->CharacterInstance,-0x10);
              }
            }
          }
          else {
            if (puVar5 == (undefined *)0x10000000) {
              Data_00 = 1;
            }
            else {
              if ((int)puVar5 < 0x10000001) {
                if (puVar5 != (undefined *)0x8000000) goto LAB_800a7dc8;
              }
              else {
                if (puVar5 != (undefined *)0x20000001) goto LAB_800a7dc8;
                if (((Raziel.Mode != 0x10) && (Raziel.Mode != 0x20)) && (CurrentSection == 0)) {
                  SetDropPhysics(In->CharacterInstance,&Raziel);
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var6->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s3*/)
 // line 2419, offset 0x800a7e10
	/* begin block 1 */
		// Start line: 2420
		// Start offset: 0x800A7E10
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800A7FA8
	// End Line: 2473

	/* begin block 2 */
		// Start line: 5203
	/* end block 2 */
	// End Line: 5204

void StateHandlerSlide(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  uint uVar2;
  int Data_00;
  uint uVar3;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    uVar3 = p_Var1->ID;
    if (uVar3 == 0x100004) {
      if ((CurrentSection == 0) && (Raziel.padCommands.Queue[9].ID != 0)) {
        SndEndLoop(Raziel.padCommands.Queue[9].ID);
        Raziel.padCommands.Queue[9].ID = 0;
      }
    }
    else {
      if ((int)uVar3 < 0x100005) {
        if (uVar3 == 0x100000) {
LAB_800a7f60:
          Data_00 = SetControlInitIdleData(0,0,3);
          StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
        }
        else {
          if ((int)uVar3 < 0x100001) {
            uVar2 = 0x80000000;
            goto LAB_800a7ed0;
          }
          if (uVar3 == 0x100001) {
            if (CurrentSection == 0) {
              Raziel.Mode = 0x400000;
              ControlFlag = 0x509;
              PhysicsMode = 0;
              ResetPhysics(In->CharacterInstance,-0x10);
              Raziel.padCommands.Queue[9].ID =
                   SOUND_Play3dSound(&In->CharacterInstance->position,0x1f,0,0x3c,0xdac);
            }
            goto LAB_800a7f98;
          }
LAB_800a7f90:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (uVar3 == 0x4010008) goto LAB_800a7f60;
        if ((int)uVar3 < 0x4010009) {
          uVar2 = 0x4000000;
        }
        else {
          uVar2 = 0x20000000;
          if (uVar3 == 0x4010200) goto LAB_800a7f98;
        }
LAB_800a7ed0:
        if (uVar3 != (uVar2 | 1)) goto LAB_800a7f90;
      }
    }
LAB_800a7f98:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerBlock(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s5*/)
 // line 2483, offset 0x800a7fc4
	/* begin block 1 */
		// Start line: 2484
		// Start offset: 0x800A7FC4
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s4

		/* begin block 1.1 */
			// Start line: 2519
			// Start offset: 0x800A816C
			// Variables:
		// 		struct _Rotation rot; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x800A816C
		// End Line: 2520

		/* begin block 1.2 */
			// Start line: 2536
			// Start offset: 0x800A820C
		/* end block 1.2 */
		// End offset: 0x800A8270
		// End Line: 2542

		/* begin block 1.3 */
			// Start line: 2548
			// Start offset: 0x800A82A0
			// Variables:
		// 		struct evPhysicsEdgeData *EdgeData; // $v0
		/* end block 1.3 */
		// End offset: 0x800A82EC
		// End Line: 2555
	/* end block 1 */
	// End offset: 0x800A8304
	// End Line: 2582

	/* begin block 2 */
		// Start line: 5340
	/* end block 2 */
	// End Line: 5341

void StateHandlerBlock(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  int Data_00;
  _Rotation _Stack40;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  if (CurrentSection == 0) {
    BlockCount = BlockCount + 1;
  }
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    Data_00 = p_Var2->ID;
    if (Data_00 == 0x100004) {
      COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
      BlockCount = 0;
    }
    else {
      if (Data_00 < 0x100005) {
        if (Data_00 == 0) goto LAB_800a8274;
        if (Data_00 < 1) {
          if (Data_00 != -0x80000000) {
LAB_800a82ec:
            DefaultStateHandler(In,CurrentSection,Data);
          }
        }
        else {
          if (Data_00 != 0x100001) goto LAB_800a82ec;
          if (CurrentSection == 0) {
            Raziel.Mode = 0x800000;
            ControlFlag = 0x8009;
            PhysicsMode = 3;
            SteerSwitchMode(In->CharacterInstance,0);
          }
          G2EmulationSwitchAnimation(In,CurrentSection,0x51,0,10,1);
          In->SectionList[CurrentSection].Data1 = 0;
        }
      }
      else {
        if (Data_00 == 0x4010400) {
          if ((((*(uint *)(p_Var2->Data + 0x20) & 0x20000) != 0) && ((Raziel.Abilities & 1U) != 0))
             && (Raziel.CurrentPlane == 2)) {
            In->SectionList[CurrentSection].Data1 = 1;
          }
        }
        else {
          if (Data_00 < 0x4010401) {
            if (Data_00 != 0x4000001) goto LAB_800a82ec;
          }
          else {
            if (Data_00 == 0x8000000) {
              if ((iVar1 == 0x52) || (iVar1 == 0x6d)) {
LAB_800a8274:
                Data_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
              }
              else {
                if (In->SectionList[CurrentSection].Data1 == 0) {
                  G2EmulationSwitchAnimation(In,CurrentSection,0x52,0,3,1);
                  if (CurrentSection == 0) {
                    Raziel.padCommands.Queue[8].ID._0_2_ = 0x640;
                    (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5b20;
                  }
                }
                else {
                  G2EmulationSwitchAnimation(In,CurrentSection,0x6d,0,5,1);
                  COLLIDE_SegmentCollisionOff(In->CharacterInstance,1);
                  razGetRotFromNormal(&Raziel.Senses.ForwardNormal,&_Stack40);
                  (In->CharacterInstance->rotation).z = _Stack40.z;
                }
              }
            }
            else {
              if (Data_00 != 0x8000004) goto LAB_800a82ec;
              if ((Raziel.Senses.EngagedMask & 1) == 0) goto LAB_800a8274;
              razGetForwardNormal(In->CharacterInstance,(Raziel.Senses.EngagedList)->instance);
              SetupReaction(In->CharacterInstance,(Raziel.Senses.EngagedList)->instance);
              Data_00 = SetObjectData(-(int)Raziel.Senses.ForwardNormal.x,
                                      -(int)Raziel.Senses.ForwardNormal.y,6,(_Instance *)0x0,0);
              INSTANCE_Post((Raziel.Senses.EngagedList)->instance,0x800000,Data_00);
            }
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDeCompression(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s2*/, int Data /*$s5*/)
 // line 2585, offset 0x800a8328
	/* begin block 1 */
		// Start line: 2586
		// Start offset: 0x800A8328
		// Variables:
	// 		struct __Event *Ptr; // $s1

		/* begin block 1.1 */
			// Start line: 2592
			// Start offset: 0x800A83F4
		/* end block 1.1 */
		// End offset: 0x800A8590
		// End Line: 2632
	/* end block 1 */
	// End offset: 0x800A8664
	// End Line: 2668

	/* begin block 2 */
		// Start line: 5549
	/* end block 2 */
	// End Line: 5550

void StateHandlerDeCompression(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  __Event *p_Var2;
  int NewAnim;
  undefined *puVar3;
  _Instance *instance;
  _Instance **pp_Var4;
  
  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == (undefined *)0x100001) {
      if (CurrentSection == 0) {
        In->SectionList[0].Data1 = Raziel.Mode;
        ControlFlag = 0x119;
        Raziel.Mode = Raziel.Mode | 0x1000;
        PhysicsMode = 3;
        SteerSwitchMode(In->CharacterInstance,0);
        NewAnim = G2EmulationQueryAnimation(In,0);
        instance = In->CharacterInstance;
        if (instance->zVel < -300) {
          G2EmulationSwitchAnimationCharacter(In,0x7b,0,6,1);
        }
        else {
          if ((Raziel.Mode & 0x10U) == 0) {
            sVar1 = (short)NewAnim;
            if (((((Raziel.Mode & 0x20U) == 0) && (sVar1 != 0x11)) && (sVar1 != 0x12)) &&
               (sVar1 != 0x13)) {
              if (p_Var2->Data == 0) goto LAB_800a8558;
              NewAnim = razSwitchVAnimCharacterGroup(instance,0xc,(int *)0x0,(int *)0x0);
              if (NewAnim != 0) {
                G2EmulationSwitchAnimationCharacter(In,0x1d,0,0,1);
              }
            }
            else {
              NewAnim = razSwitchVAnimCharacterGroup
                                  (In->CharacterInstance,0x2c,(int *)0x0,(int *)0x0);
              if (NewAnim != 0) {
                NewAnim = 0x29;
                goto LAB_800a857c;
              }
            }
          }
          else {
LAB_800a8558:
            NewAnim = razSwitchVAnimCharacterGroup(instance,0x1c,(int *)0x0,(int *)0x0);
            if (NewAnim != 0) {
              NewAnim = 0x25;
LAB_800a857c:
              G2EmulationSwitchAnimationCharacter(In,NewAnim,0,1,1);
            }
          }
        }
      }
      else {
        pp_Var4[0x47] = (_Instance *)In->SectionList[CurrentSection + -1].Data1;
      }
    }
    else {
      if ((int)puVar3 < 0x100002) {
        if ((puVar3 != (undefined *)0x80000000) && (puVar3 != &DAT_80000020)) goto LAB_800a864c;
      }
      else {
        if (puVar3 == (undefined *)0x8000000) {
          if ((*PadData & 0x8000000fU) == 0) {
            NewAnim = SetControlInitIdleData(0,0,4);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,NewAnim);
            Raziel.Mode = 1;
          }
          else {
            if (CurrentSection == 0) {
              NewAnim = G2EmulationQueryAnimation(In,0);
              if (NewAnim == 0x1d) {
                StateSwitchStateCharacterData(In,StateHandlerMove,0);
                pp_Var4[0x47] = (_Instance *)0x0;
              }
              else {
                StateSwitchStateCharacterData(In,StateHandlerStartMove,5);
                pp_Var4[0x47] = (_Instance *)0x0;
              }
              goto LAB_800a8654;
            }
          }
          pp_Var4[0x47] = (_Instance *)0x0;
        }
        else {
          if ((int)puVar3 < 0x8000001) {
            if (puVar3 == (undefined *)0x100004) {
              SetPhysics(In->CharacterInstance,-0x10,0,0,0);
            }
            else {
LAB_800a864c:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar3 != (undefined *)0x10000000) goto LAB_800a864c;
          }
        }
      }
    }
LAB_800a8654:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*stack 8*/)
 // line 2673, offset 0x800a8688
	/* begin block 1 */
		// Start line: 2674
		// Start offset: 0x800A8688
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Frame; // $fp
	// 		int Anim; // $s6
	// 		int moving; // $s7

		/* begin block 1.1 */
			// Start line: 2792
			// Start offset: 0x800A8BCC
			// Variables:
		// 		struct evObjectDraftData *draft; // $a2
		/* end block 1.1 */
		// End offset: 0x800A8C2C
		// End Line: 2799

		/* begin block 1.2 */
			// Start line: 2804
			// Start offset: 0x800A8C54
			// Variables:
		// 		struct evPhysicsSwimData *SwimData; // $v0
		/* end block 1.2 */
		// End offset: 0x800A8CE4
		// End Line: 2817
	/* end block 1 */
	// End offset: 0x800A8DA4
	// End Line: 2868

	/* begin block 2 */
		// Start line: 5740
	/* end block 2 */
	// End Line: 5741

void StateHandlerGlide(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  int local_38;
  int iVar2;
  __Event *p_Var3;
  int local_34;
  undefined *puVar4;
  uint uVar5;
  code *NewProcess;
  short z;
  _Instance **pp_Var6;
  __State *p_Var7;
  
  bVar1 = false;
  local_38 = G2EmulationQueryAnimation(In,CurrentSection);
  iVar2 = G2EmulationQueryFrame(In,CurrentSection);
  if (CurrentSection == 0) {
    In->SectionList[0].Data2 = In->SectionList[0].Data2 & 0xfffffffd;
  }
  p_Var7 = In->SectionList + CurrentSection;
  pp_Var6 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var3 = PeekMessageQueue(&p_Var7->Event);
    if (p_Var3 == (__Event *)0x0) {
      if ((CurrentSection == 0) && (uVar5 = In->SectionList[0].Data2, (uVar5 & 1) != 0)) {
        if ((uVar5 & 2) == 0) {
          if (bVar1) {
            local_38 = 0x34;
          }
          else {
            local_38 = 0;
          }
          SetExternalTransitionForce(&ExternalForces,In->CharacterInstance,10,0,local_38,-0x18);
          In->SectionList[0].Data2 = 0;
        }
        else {
          if (bVar1) {
            In->CharacterInstance->yVel = 0x34;
          }
          else {
            In->CharacterInstance->yVel = 0;
          }
        }
      }
      return;
    }
    puVar4 = (undefined *)p_Var3->ID;
    if (puVar4 == (undefined *)0x4000007) {
      if (CurrentSection == 0) {
        if ((int)(uint)(ushort)((short *)p_Var3->Data)[4] < In->CharacterInstance->zVel) {
          z = 0;
          local_34 = 0;
        }
        else {
          z = *(short *)p_Var3->Data;
          local_34 = 0xffc;
        }
        SetExternalForce(&__Force_800d5c50,0,0,z,0,local_34);
        pp_Var6[0x48] = (_Instance *)((uint)pp_Var6[0x48] | 3);
        Raziel.padCommands.Queue[12].ID = Raziel.padCommands.Queue[12].ID | 0x4000;
      }
    }
    else {
      if ((int)puVar4 < 0x4000008) {
        if (puVar4 != &DAT_80000020) {
          if ((int)puVar4 < -0x7fffffdf) {
            if (puVar4 == &DAT_80000004) {
              if (CurrentSection == 1) {
                SetExternalTransitionForce(&ExternalForces,In->CharacterInstance,4,0,0x18,-0x18);
              }
              G2EmulationSwitchAnimation(In,CurrentSection,0x11,0,5,1);
              pp_Var6[0x47] = (_Instance *)0x0;
              if (((uint)pp_Var6[0x48] & 1) != 0) {
                razSetPlayerEventHistory(0x4000);
              }
            }
            else {
              if ((int)puVar4 < -0x7ffffffb) {
                if (puVar4 != (undefined *)0x80000000) goto LAB_800a8ce4;
              }
              else {
                if (puVar4 != &DAT_80000008) goto LAB_800a8ce4;
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x100004) {
              if (CurrentSection == 0) {
                InitAlgorithmicWings(In->CharacterInstance);
              }
            }
            else {
              if ((int)puVar4 < 0x100005) {
                if (puVar4 != (undefined *)0x100001) goto LAB_800a8ce4;
                if (CurrentSection == 0) {
                  Raziel.Mode = 0x2000;
                  ControlFlag = 0x518;
                  PhysicsMode = 0;
                  SteerSwitchMode(In->CharacterInstance,8);
                  DeInitAlgorithmicWings(In->CharacterInstance);
                  if (In->CharacterInstance->zVel < 0) {
                    SetPhysics(In->CharacterInstance,0,0,0x34,-0x18);
                  }
                }
                pp_Var6[0x47] = (_Instance *)0x1;
                pp_Var6[0x48] = (_Instance *)0x0;
                G2EmulationSwitchAnimation(In,CurrentSection,0x10,p_Var3->Data,5,1);
              }
              else {
                if (puVar4 != (undefined *)0x4000001) goto LAB_800a8ce4;
              }
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x8000003) {
          if (local_38 == 0x10) {
            SetPhysics(In->CharacterInstance,0,0,0x34,-0x18);
          }
        }
        else {
          if ((int)puVar4 < 0x8000004) {
            if (puVar4 == (undefined *)0x4020000) {
              z = *(short *)(p_Var3->Data + 0xe);
              if (((z < 0) && (z != -0x7fff)) && (Raziel.CurrentPlane == 1)) {
                if (CurrentSection == 0) {
                  SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                }
                G2EmulationSwitchAnimation(In,CurrentSection,0x13,0,4,1);
                NewProcess = StateHandlerFall;
LAB_800a8cd4:
                StateSwitchStateData(In,CurrentSection,NewProcess,0);
              }
            }
            else {
              if ((int)puVar4 < 0x4020001) {
                if (puVar4 == (undefined *)0x4010008) {
                  NewProcess = StateHandlerDeCompression;
                  goto LAB_800a8cd4;
                }
              }
              else {
                if (puVar4 == (undefined *)0x8000000) {
                  if (pp_Var6[0x47] != (_Instance *)0x0) {
                    G2EmulationSwitchAnimationAlpha(In,CurrentSection,0x12,0,5,1,4);
                    pp_Var6[0x47] = (_Instance *)0x0;
                  }
                  goto LAB_800a8cf0;
                }
              }
LAB_800a8ce4:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 == (undefined *)0x20000001) {
              if (((iVar2 < 0xd) && (local_38 == 0x10)) || ((*PadData & 0x80) != 0)) {
                EnMessageQueueData(&p_Var7->Defer,0x20000001,0);
              }
              else {
                if (CurrentSection == 0) {
                  SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                  local_34 = razSwitchVAnimCharacterGroup
                                       (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                  if (local_34 != 0) {
                    G2EmulationSwitchAnimationCharacter(In,0x24,0,4,1);
                  }
                }
                StateSwitchStateCharacterData(In,StateHandlerFall,0);
              }
            }
            else {
              if ((int)puVar4 < 0x20000002) {
                if (puVar4 != (undefined *)0x10000000) goto LAB_800a8ce4;
                bVar1 = true;
                if (local_38 != 0x10) {
                  if (0 < Raziel.Bearing) {
                    G2EmulationSwitchAnimation(In,CurrentSection,0x2b,0,6,1);
                    pp_Var6[0x47] = (_Instance *)0x2;
                  }
                  if (Raziel.Bearing < 0) {
                    G2EmulationSwitchAnimation(In,CurrentSection,0x2c,0,6,1);
                    pp_Var6[0x47] = (_Instance *)0x2;
                  }
                  bVar1 = true;
                  if ((Raziel.Bearing == 0) && (pp_Var6[0x47] == (_Instance *)0x2)) {
                    G2EmulationSwitchAnimation(In,CurrentSection,0x12,0,5,1);
                    pp_Var6[0x47] = (_Instance *)0x0;
                    bVar1 = true;
                  }
                }
              }
              else {
                if (puVar4 != (undefined *)0x20000004) goto LAB_800a8ce4;
                if (CurrentSection == 0) {
                  SetExternalTransitionForce(&ExternalForces,In->CharacterInstance,4,0,0x34,-0x18);
                }
                G2EmulationSwitchAnimation(In,CurrentSection,0x12,0,5,1);
                pp_Var6[0x47] = (_Instance *)0x0;
              }
            }
          }
        }
      }
    }
LAB_800a8cf0:
    DeMessageQueue(&p_Var7->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerHang(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
 // line 2871, offset 0x800a8dd4
	/* begin block 1 */
		// Start line: 2872
		// Start offset: 0x800A8DD4
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s7

		/* begin block 1.1 */
			// Start line: 2884
			// Start offset: 0x800A8F94
			// Variables:
		// 		struct evControlInitHangData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x800A9050
		// End Line: 2910
	/* end block 1 */
	// End offset: 0x800A92D8
	// End Line: 3020

	/* begin block 2 */
		// Start line: 6147
	/* end block 2 */
	// End Line: 6148

/* WARNING: Type propagation algorithm not settling */

void StateHandlerHang(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  _Instance *Frames;
  undefined *puVar3;
  _Instance *p_Var4;
  int NewAnim;
  int CurrentSection_00;
  _Instance **pp_Var5;
  __MessageQueue *In_00;
  __State *p_Var6;
  int local_2c;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var6 = In->SectionList + CurrentSection;
  In_00 = &p_Var6->Event;
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(In_00);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if ((int)puVar3 < 0x1000002) {
      if ((int)puVar3 < 0x1000000) {
        if (puVar3 == (undefined *)0x100000) {
          if ((*PadData & 0x8000000fU) == 0) {
            CurrentSection_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,CurrentSection_00);
            Raziel.Mode = 1;
            pp_Var5[0x47] = (_Instance *)0x0;
          }
          else {
            StateSwitchStateData(In,CurrentSection,StateHandlerStartMove,10);
            pp_Var5[0x47] = (_Instance *)0x0;
          }
        }
        else {
          if ((int)puVar3 < 0x100001) {
            if (puVar3 != &DAT_80000008) {
              if ((int)puVar3 < -0x7ffffff7) {
                if (puVar3 != (undefined *)0x80000000) goto LAB_800a92c0;
              }
              else {
                if (puVar3 != &DAT_80000020) goto LAB_800a92c0;
              }
            }
          }
          else {
            if (puVar3 == (undefined *)0x100004) {
              if (CurrentSection == 0) {
                Raziel.attachedPlatform = (_Instance *)0x0;
                ControlFlag = ControlFlag & 0xfffffbff;
                In->CharacterInstance->attachedID = 0;
              }
            }
            else {
              if ((int)puVar3 < 0x100005) {
                if (puVar3 != (undefined *)0x100001) goto LAB_800a92c0;
                Frames = (_Instance *)p_Var2->Data;
                if (CurrentSection == 0) {
                  p_Var4 = In->CharacterInstance;
                  In->SectionList[0].Data2 = In->CharacterInstance->attachedID;
                  ControlFlag = 0x8001501;
                  if (p_Var4->attachedID == 0) {
                    ControlFlag = 0xc001501;
                  }
                  In->CharacterInstance->attachedID = 0;
                  Raziel.Mode = 0x100;
                  PhysicsMode = 3;
                  if (*(_Instance **)&Frames->node != (_Instance *)0x0) {
                    Raziel.attachedPlatform = *(_Instance **)&Frames->node;
                  }
                  SteerSwitchMode(In->CharacterInstance,0);
                }
                if (Raziel.iVelocity.z < 0) {
                  Frames = Frames->next;
                  CurrentSection_00 = 4;
                }
                else {
                  Frames = Frames->next;
                  CurrentSection_00 = 0;
                }
                G2EmulationSwitchAnimation(In,CurrentSection,7,CurrentSection_00,(int)Frames,1);
                pp_Var5[0x47] = (_Instance *)0x0;
              }
              else {
                if (puVar3 != (undefined *)0x100014) goto LAB_800a92c0;
LAB_800a9254:
                if (CurrentSection == 1) {
                  SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                  CurrentSection_00 =
                       razSwitchVAnimCharacterGroup
                                 (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                  if (CurrentSection_00 != 0) {
                    G2EmulationSwitchAnimationCharacter(In,0x24,0,4,1);
                  }
                  StateSwitchStateCharacterData(In,StateHandlerFall,0);
                }
              }
            }
          }
        }
      }
    }
    else {
      if (puVar3 != (undefined *)0x4010200) {
        if ((int)puVar3 < 0x4010201) {
          if (puVar3 != (undefined *)0x4000011) {
            if ((int)puVar3 < 0x4000012) {
              if (puVar3 != (undefined *)0x4000001) {
LAB_800a92c0:
                DefaultStateHandler(In,CurrentSection,Data);
              }
            }
            else {
              if (puVar3 != (undefined *)0x4010010) goto LAB_800a92c0;
            }
          }
        }
        else {
          if (puVar3 == (undefined *)0x8000001) {
            if (pp_Var5[0x47] == (_Instance *)0x1) {
              EnMessageQueueData(In_00,0x100000,0);
            }
          }
          else {
            if ((int)puVar3 < 0x8000002) {
              if (puVar3 != (undefined *)0x8000000) goto LAB_800a92c0;
              if (pp_Var5[0x47] == (_Instance *)0x1) {
                EnMessageQueueData(In_00,0x100000,0);
                (In->CharacterInstance->rotation).x = 0;
                (In->CharacterInstance->rotation).y = 0;
              }
              else {
                if (CurrentSection == 2) {
                  NewAnim = 0;
                  CurrentSection_00 = 2;
                  local_2c = CurrentSection;
                }
                else {
                  NewAnim = 6;
                  local_2c = 0;
                  CurrentSection_00 = CurrentSection;
                }
                G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,3,local_2c);
              }
              if (CurrentSection == 0) {
                ControlFlag = ControlFlag & 0xfffffbff;
              }
            }
            else {
              if (puVar3 == (undefined *)0x8000003) {
                if ((CurrentSection == 0) &&
                   (ControlFlag = ControlFlag & 0xfffffbff, In->SectionList[0].Data2 != 0)) {
                  ControlFlag = ControlFlag | 0x4000000;
                }
              }
              else {
                if (puVar3 != (undefined *)0x10000000) goto LAB_800a92c0;
                CurrentSection_00 = p_Var2->Data;
                if (CurrentSection_00 == 0x10000003) {
                  if (iVar1 == 6) goto LAB_800a9254;
                  CurrentSection_00 = p_Var2->Data;
                }
                if ((CurrentSection_00 == 0x10000001) || ((*PadData & 1U) != 0)) {
                  if (pp_Var5[0x47] == (_Instance *)0x0) {
                    G2EmulationSwitchAnimation(In,CurrentSection,8,0,2,1);
                    PurgeMessageQueue(&p_Var6->Event);
                  }
                  pp_Var5[0x47] = (_Instance *)0x1;
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var6->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPushObject(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s5*/)
 // line 3023, offset 0x800a9308
	/* begin block 1 */
		// Start line: 3024
		// Start offset: 0x800A9308
		// Variables:
	// 		struct __Event *Ptr; // $v1

		/* begin block 1.1 */
			// Start line: 3075
			// Start offset: 0x800A9570
			// Variables:
		// 		struct evObjectData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x800A95F4
		// End Line: 3083
	/* end block 1 */
	// End offset: 0x800A960C
	// End Line: 3091

	/* begin block 2 */
		// Start line: 6458
	/* end block 2 */
	// End Line: 6459

	/* begin block 3 */
		// Start line: 6461
	/* end block 3 */
	// End Line: 6462

void StateHandlerPushObject(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  int NewAnim;
  int local_24;
  
  if ((Raziel.Senses.EngagedMask & 3) == 0) {
    EnMessageQueueData(&In->SectionList[CurrentSection].Defer,0x100000,0);
  }
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    Data_00 = p_Var1->ID;
    if (Data_00 < 0x8000002) {
      if (Data_00 < 0x8000000) {
        if (Data_00 == 0x100000) {
          Data_00 = SetControlInitIdleData(0,0,6);
          StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
        }
        else {
          if (Data_00 != 0x100001) goto LAB_800a95f4;
          if (CurrentSection == 0) {
            Raziel.Mode = 0x400;
            ControlFlag = 0x8001108;
            PhysicsMode = 3;
            SteerSwitchMode(In->CharacterInstance,0);
          }
          In->SectionList[CurrentSection].Data1 = 0;
          razSetPlayerEventHistory(1);
        }
      }
      else {
        if (((*PadData & 0x20) == 0) || ((Raziel.Senses.EngagedMask & 2) == 0)) {
          if (In->SectionList[CurrentSection].Data1 == 0) {
            if (CurrentSection == 2) {
              NewAnim = 0;
              Data_00 = 2;
              local_24 = CurrentSection;
            }
            else {
              NewAnim = 0x17;
              local_24 = 1;
              Data_00 = CurrentSection;
            }
            G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,3,local_24);
            In->SectionList[CurrentSection].Data1 = 1;
            if (CurrentSection == 0) {
              Raziel.padCommands.Queue[8].ID._0_2_ = 400;
              (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5b20;
            }
          }
          else {
            Data_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
            ControlFlag = ControlFlag | 1;
          }
        }
        else {
          StateSwitchStateData(In,CurrentSection,StateHandlerDragObject,0);
        }
      }
    }
    else {
      if (Data_00 == 0x8000004) {
        razGetForwardNormal(In->CharacterInstance,(Raziel.Senses.EngagedList)->instance);
        SetupReaction(In->CharacterInstance,(Raziel.Senses.EngagedList)->instance);
        Data_00 = SetObjectData(-(int)Raziel.Senses.ForwardNormal.x,
                                -(int)Raziel.Senses.ForwardNormal.y,6,(_Instance *)0x0,0);
        INSTANCE_Post((Raziel.Senses.EngagedList)->instance,0x800000,Data_00);
        if (*(int *)(Data_00 + 0xc) == 0) {
          INSTANCE_Post(In->CharacterInstance,0x100000,0);
        }
      }
      else {
LAB_800a95f4:
        DefaultStateHandler(In,CurrentSection,Data);
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerBreakOff(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s3*/, int Data /*$s7*/)
 // line 3094, offset 0x800a9630
	/* begin block 1 */
		// Start line: 3095
		// Start offset: 0x800A9630
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3102
			// Start offset: 0x800A970C
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $s0
		// 		struct _Instance *Inst; // $s1
		// 		int anim; // $a2
		/* end block 1.1 */
		// End offset: 0x800A9870
		// End Line: 3145

		/* begin block 1.2 */
			// Start line: 3155
			// Start offset: 0x800A98A0
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $v0
		// 		int action; // $s1
		// 		int condition; // $v0
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x800A9958
		// End Line: 3186
	/* end block 1 */
	// End offset: 0x800A99A4
	// End Line: 3201

	/* begin block 2 */
		// Start line: 6611
	/* end block 2 */
	// End Line: 6612

void StateHandlerBreakOff(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  __Event *p_Var4;
  ulong uVar5;
  int local_34;
  uint local_38;
  short distance;
  _Instance *p_Var6;
  _Instance *force;
  _Instance **pp_Var7;
  
  pp_Var7 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var4 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var4 == (__Event *)0x0) {
      return;
    }
    local_34 = p_Var4->ID;
    if (local_34 != 0x100004) {
      if (local_34 < 0x100005) {
        if (local_34 != -0x80000000) {
          if (local_34 != 0x100001) goto LAB_800a998c;
          if (CurrentSection == 0) {
            if ((Raziel.Senses.EngagedMask & 0x10) == 0) {
              force = Raziel.Senses.EngagedList[0xd].instance;
            }
            else {
              force = Raziel.Senses.EngagedList[4].instance;
            }
            uVar5 = INSTANCE_Query(force,0x15);
            if ((Raziel.Senses.EngagedMask & 0x10) == 0) {
              bVar1 = *(byte *)(uVar5 + 0x13);
            }
            else {
              bVar1 = *(byte *)(uVar5 + 0x12);
            }
            pp_Var7[0x48] = force;
            G2EmulationInstanceToInstanceSwitchAnimationCharacter
                      (In->CharacterInstance,force,(uint)bVar1,0,0,1);
            if (*(byte *)(uVar5 + 0x14) != 0xff) {
              Raziel.padCommands.Queue[8].ID._0_2_ = (ushort)*(byte *)(uVar5 + 0x14) * 100;
              (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5b20;
            }
            uVar2 = *(ushort *)(uVar5 + 0x1c);
            local_38 = (uint)uVar2;
            ControlFlag = 0x8041108;
            PhysicsMode = 3;
            if (uVar2 == 1) {
              distance = *(short *)(uVar5 + 0x16);
              p_Var6 = In->CharacterInstance;
              local_34 = 0;
LAB_800a9880:
              razAlignYMoveRot(force,-distance,&p_Var6->position,&p_Var6->rotation,local_34);
            }
            else {
              if (uVar2 < 2) {
                if (uVar2 == 0) {
                  distance = *(short *)(uVar5 + 0x16);
                  local_38 = 3;
                  local_34 = 0;
LAB_800a985c:
                  razAlignYRotMoveInterp
                            (In->CharacterInstance,force,distance,'\0',local_38,local_34);
                }
              }
              else {
                if (uVar2 == 3) {
                  distance = *(short *)(uVar5 + 0x16);
                  local_34 = 0x800;
                  goto LAB_800a985c;
                }
                if (uVar2 == 4) {
                  distance = *(short *)(uVar5 + 0x16);
                  p_Var6 = In->CharacterInstance;
                  local_34 = 0x800;
                  goto LAB_800a9880;
                }
              }
            }
          }
        }
      }
      else {
        if (local_34 < 0x8000000) {
LAB_800a998c:
          DefaultStateHandler(In,CurrentSection,Data);
        }
        else {
          if (local_34 < 0x8000002) {
            local_34 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,local_34);
          }
          else {
            if (local_34 != 0x8000004) goto LAB_800a998c;
            uVar5 = INSTANCE_Query(pp_Var7[0x48],0x15);
            force = Raziel.soulReaver;
            if ((Raziel.Senses.EngagedMask & 0x10) == 0) {
              uVar2 = *(ushort *)(uVar5 + 0xe);
              uVar3 = *(ushort *)(uVar5 + 10);
            }
            else {
              uVar2 = *(ushort *)(uVar5 + 0xc);
              uVar3 = *(ushort *)(uVar5 + 8);
            }
            if ((uVar3 & 0x1fe) == 0) {
              force = In->CharacterInstance;
            }
            else {
              razReaverImbue((uint)uVar2);
            }
            local_34 = SetObjectBreakOffData(force,0x31,0,0,0,0,(int)(short)uVar2);
            INSTANCE_Post(pp_Var7[0x48],0x800023,local_34);
            if (uVar2 == 1) {
              razReaverOff();
            }
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPullSwitch(struct __CharacterState *In /*$s4*/, int CurrentSection /*$s5*/, int Data /*stack 8*/)
 // line 3204, offset 0x800a99d0
	/* begin block 1 */
		// Start line: 3205
		// Start offset: 0x800A99D0
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3216
			// Start offset: 0x800A9AE0
			// Variables:
		// 		struct PhysObSwitchProperties *switchData; // $fp

			/* begin block 1.1.1 */
				// Start line: 3222
				// Start offset: 0x800A9B10
				// Variables:
			// 		int switchStatus; // $s1
			// 		int switchSuccess; // $s3
			// 		struct _Instance *inst; // $s2
			// 		struct PhysObSwitchProperties *switchProperties; // $s0
			// 		int extraZ; // $s6

				/* begin block 1.1.1.1 */
					// Start line: 3235
					// Start offset: 0x800A9B64
				/* end block 1.1.1.1 */
				// End offset: 0x800A9BBC
				// End Line: 3247
			/* end block 1.1.1 */
			// End offset: 0x800A9CE8
			// End Line: 3296
		/* end block 1.1 */
		// End offset: 0x800A9CE8
		// End Line: 3296

		/* begin block 1.2 */
			// Start line: 3302
			// Start offset: 0x800A9CF8
			// Variables:
		// 		int switchStatus; // $v1
		// 		struct _Instance *inst; // $s0
		// 		struct PhysObSwitchProperties *switchProperties; // $s0
		// 		int switchClass; // $s1
		/* end block 1.2 */
		// End offset: 0x800A9E6C
		// End Line: 3342
	/* end block 1 */
	// End offset: 0x800A9F10
	// End Line: 3369

	/* begin block 2 */
		// Start line: 6847
	/* end block 2 */
	// End Line: 6848

void StateHandlerPullSwitch(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  bool bVar2;
  ushort uVar3;
  __Event *p_Var4;
  ulong uVar5;
  ulong uVar6;
  ulong Data_00;
  ulong uVar7;
  int Data_01;
  undefined *puVar8;
  uint NewAnim;
  _Instance *Inst;
  short sVar9;
  __State *p_Var10;
  
  G2EmulationQueryAnimation(In,CurrentSection);
  p_Var10 = In->SectionList + CurrentSection;
  do {
    p_Var4 = PeekMessageQueue(&p_Var10->Event);
    if (p_Var4 == (__Event *)0x0) {
      if (CurrentSection == 0) {
        razApplyMotion(In,0);
      }
      return;
    }
    puVar8 = (undefined *)p_Var4->ID;
    if (puVar8 != (undefined *)0x4000e) {
      if ((int)puVar8 < 0x4000f) {
        if (puVar8 != &DAT_80000008) {
          if ((int)puVar8 < -0x7ffffff7) {
            if (puVar8 != (undefined *)0x80000000) {
LAB_800a9ee4:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if ((puVar8 != &DAT_80000010) && (puVar8 != &DAT_80000020)) goto LAB_800a9ee4;
          }
        }
      }
      else {
        if (puVar8 == (undefined *)0x100001) {
          if (CurrentSection == 0) {
            ControlFlag = 0x9045108;
            PhysicsMode = 3;
            SteerSwitchMode(In->CharacterInstance,0);
            bVar2 = true;
            if ((Raziel.Senses.EngagedMask & 8) != 0) {
              sVar9 = 0;
              Inst = Raziel.Senses.EngagedList[3].instance;
              uVar6 = INSTANCE_Query(Inst,0x17);
              Data_00 = INSTANCE_Query(Inst,5);
              uVar7 = INSTANCE_Query(Inst,0x1c);
              uVar5 = INSTANCE_Query(Inst,4);
              if (uVar5 == 9) {
                uVar3 = MON_FacingOffset(In->CharacterInstance,Inst);
                uVar3 = uVar3 & 0xfff;
                if (0x800 < uVar3) {
                  uVar3 = uVar3 | 0xf000;
                }
                if ((ushort)(uVar3 + 0x400) < 0x801) {
                  Data_00 = Data_00 & 0xfffffffe;
                  sVar9 = 0;
                }
                else {
                  Data_00 = Data_00 | 1;
                  sVar9 = 0x800;
                }
                INSTANCE_Post(Inst,0x80002a,Data_00);
              }
              if ((Data_00 & 1) == 0) {
                if ((Data_00 & 2) == 0) {
                  if (*(char *)(uVar6 + 0x16) != -1) {
                    NewAnim = (uint)*(byte *)(uVar6 + 0x16);
                    goto LAB_800a9c4c;
                  }
                  goto LAB_800a9c3c;
                }
                if (*(char *)(uVar6 + 0x14) == -1) goto LAB_800a9c3c;
                NewAnim = (uint)*(byte *)(uVar6 + 0x14);
LAB_800a9c4c:
                G2EmulationInstanceToInstanceSwitchAnimationCharacter
                          (In->CharacterInstance,Raziel.Senses.EngagedList[3].instance,NewAnim,0,0,1
                          );
              }
              else {
                if ((Data_00 & 2) == 0) {
                  if (*(char *)(uVar6 + 0x17) != -1) {
                    NewAnim = (uint)*(byte *)(uVar6 + 0x17);
                    goto LAB_800a9c4c;
                  }
                }
                else {
                  if (*(char *)(uVar6 + 0x15) != -1) {
                    NewAnim = (uint)*(byte *)(uVar6 + 0x15);
                    goto LAB_800a9c4c;
                  }
                }
LAB_800a9c3c:
                bVar2 = false;
              }
              if (bVar2) {
                razAlignYMoveRot(Raziel.Senses.EngagedList[3].instance,*(short *)(uVar7 + 8),
                                 &In->CharacterInstance->position,&In->CharacterInstance->rotation,
                                 (int)sVar9);
                INSTANCE_Post(Raziel.Senses.EngagedList[3].instance,0x800020,0);
                uVar6 = INSTANCE_Query(Inst,4);
                if (uVar6 == 9) {
                  razSetPlayerEventHistory(8);
                }
                else {
                  razSetPlayerEventHistory(4);
                }
              }
              else {
                INSTANCE_Post(In->CharacterInstance,0x100000,Data_00);
              }
            }
          }
        }
        else {
          if ((int)puVar8 < 0x100002) {
            if (puVar8 != (undefined *)0x100000) goto LAB_800a9ee4;
            Inst = Raziel.Senses.EngagedList[3].instance;
            uVar6 = INSTANCE_Query(Inst,4);
            Data_00 = INSTANCE_Query(Raziel.Senses.EngagedList[3].instance,0x17);
            uVar7 = INSTANCE_Query(Inst,5);
            if (uVar6 == 6) {
              if ((*PadData & 0x20) == 0) {
                Data_01 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_01);
                ControlFlag = ControlFlag | 1;
                if (CurrentSection == 0) {
                  INSTANCE_Post(Raziel.Senses.EngagedList[3].instance,0x800020,0);
                }
              }
              else {
LAB_800a9ed0:
                EnMessageQueueData(&p_Var10->Defer,0x100000,0);
              }
            }
            else {
              if (uVar6 == 9) {
                if ((uVar7 & 1) == 0) {
                  bVar1 = *(byte *)(Data_00 + 0x12);
                }
                else {
                  bVar1 = *(byte *)(Data_00 + 0x11);
                }
                SetTimer((uint)bVar1 + 6);
                G2EmulationSwitchAnimation(In,CurrentSection,0x7c,0,6,2);
                if (CurrentSection == 0) {
                  INSTANCE_Post(Raziel.Senses.EngagedList[3].instance,0x80002d,0x14);
                }
              }
              else {
                Data_01 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_01);
                ControlFlag = ControlFlag | 1;
              }
            }
          }
          else {
            if (puVar8 == (undefined *)0x100015) {
              Data_01 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_01);
            }
            else {
              if (puVar8 != (undefined *)0x8000000) goto LAB_800a9ee4;
              if (CurrentSection != 2) goto LAB_800a9ed0;
              G2EmulationSwitchAnimation(In,2,0,0,3,2);
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var10->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDragObject(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*stack 8*/)
 // line 3372, offset 0x800a9f40
	/* begin block 1 */
		// Start line: 3373
		// Start offset: 0x800A9F40
		// Variables:
	// 		struct __Event *Ptr; // $a1
	// 		struct _Instance *instance; // $s3
	// 		int anim; // $s5
	// 		int hitPosted; // $fp

		/* begin block 1.1 */
			// Start line: 3414
			// Start offset: 0x800AA158
			// Variables:
		// 		struct evPhysicsSlideData *slideData; // stack offset -48

			/* begin block 1.1.1 */
				// Start line: 3419
				// Start offset: 0x800AA174
				// Variables:
			// 		struct evObjectData *data; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800AA454
			// End Line: 3474
		/* end block 1.1 */
		// End offset: 0x800AA454
		// End Line: 3475

		/* begin block 1.2 */
			// Start line: 3515
			// Start offset: 0x800AA5C0
			// Variables:
		// 		struct evMonsterHitData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x800AA5C0
		// End Line: 3516
	/* end block 1 */
	// End offset: 0x800AA61C
	// End Line: 3530

	/* begin block 2 */
		// Start line: 7187
	/* end block 2 */
	// End Line: 7188

	/* begin block 3 */
		// Start line: 7193
	/* end block 3 */
	// End Line: 7194

/* WARNING: Type propagation algorithm not settling */

void StateHandlerDragObject(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  int iVar2;
  __Event *p_Var3;
  uint uVar4;
  int Data_00;
  _Instance *p_Var5;
  undefined *puVar6;
  int NewAnim;
  _Instance *Inst;
  __State *p_Var7;
  int local_38;
  int local_34;
  evPhysicsSlideData *apeStack48 [2];
  
  bVar1 = false;
  if ((Raziel.Senses.EngagedMask & 2) == 0) {
    Inst = (_Instance *)0x0;
    EnMessageQueueData(&In->SectionList[CurrentSection].Defer,0x100000,0);
  }
  else {
    Inst = Raziel.Senses.EngagedList[1].instance;
    if (Inst->introUniqueID == In->CharacterInstance->attachedID) {
      In->CharacterInstance->attachedID = 0;
    }
  }
  iVar2 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var7 = In->SectionList + CurrentSection;
  do {
    p_Var3 = PeekMessageQueue(&p_Var7->Event);
    if (p_Var3 == (__Event *)0x0) {
      return;
    }
    puVar6 = (undefined *)p_Var3->ID;
    if (puVar6 == (undefined *)0x100001) {
      if (CurrentSection == 0) {
        Raziel.Mode = 0x400;
        ControlFlag = 0x9001508;
        PhysicsMode = 3;
        SteerSwitchMode(In->CharacterInstance,0);
        razGetForwardNormal(In->CharacterInstance,Raziel.Senses.EngagedList[1].instance);
        SetupReaction(In->CharacterInstance,Raziel.Senses.EngagedList[1].instance);
      }
      G2EmulationSwitchAnimation(In,CurrentSection,0x14,0,3,1);
    }
    else {
      if ((int)puVar6 < 0x100002) {
        if (puVar6 != &DAT_80000010) {
          if ((int)puVar6 < -0x7fffffef) {
            if (-0x7fffffff < (int)puVar6) {
LAB_800aa600:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar6 != &DAT_80000020) {
              if (puVar6 != (undefined *)0x100000) goto LAB_800aa600;
LAB_800aa564:
              Data_00 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
            }
          }
        }
      }
      else {
        if (puVar6 == (undefined *)0x8000001) {
          uVar4 = *PadData;
joined_r0x800aa474:
          if ((uVar4 & 0x20) == 0) {
            EnMessageQueueData(&p_Var7->Event,0x100000,0);
          }
        }
        else {
          if ((int)puVar6 < 0x8000002) {
            if (puVar6 != (undefined *)0x1000000) {
              if (puVar6 != (undefined *)0x8000000) goto LAB_800aa600;
              if (iVar2 == 0x17) {
                Data_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
              }
              if (Inst == (_Instance *)0x0) goto LAB_800aa564;
              if (CurrentSection == 0) {
                INSTANCE_Post(Inst,0x800004,0);
                SetupReaction(In->CharacterInstance,Raziel.Senses.EngagedList[1].instance);
              }
              if (CurrentSection == 2) {
                NewAnim = 0;
                local_38 = 3;
                Data_00 = 2;
                local_34 = CurrentSection;
              }
              else {
                NewAnim = 0x16;
                local_38 = 2;
                local_34 = 2;
                Data_00 = CurrentSection;
              }
              G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_38,local_34);
              uVar4 = *PadData;
              goto joined_r0x800aa474;
            }
            if (CurrentSection == 0) {
              if (iVar2 == 0x16) {
                StateSwitchStateCharacterData(In,StateHandlerHitReaction,p_Var3->Data);
              }
              else {
                if (!bVar1) {
                  p_Var5 = (_Instance *)p_Var3->Data;
                  bVar1 = true;
                  Data_00 = SetMonsterHitData(*(_Instance **)&p_Var5->node,
                                              *(_Instance **)((int)&p_Var5->node + 4),
                                              (int)p_Var5->prev,(int)*(short *)&p_Var5->next,
                                              (int)*(short *)((int)&p_Var5->next + 2));
                  EnMessageQueueData(&In->SectionList[0].Defer,0x1000000,Data_00);
                }
              }
            }
          }
          else {
            if (puVar6 == (undefined *)0x10000000) {
              if (CurrentSection == 0) {
                gameTrackerX.currentMaterialTime._1_1_ = 1;
                if (((iVar2 == 0) || (iVar2 == 0x16)) && (Inst != (_Instance *)0x0)) {
                  Data_00 = p_Var3->Data;
                  if (Data_00 == 0x10000002) {
                    uVar4 = PHYSOB_CheckSlideNormal
                                      (In->CharacterInstance,-(int)Raziel.Senses.ForwardNormal.y,
                                       (int)Raziel.Senses.ForwardNormal.x,apeStack48);
                    if ((uVar4 & 0x4002) == 0x4000) {
                      Data_00 = SetObjectData(-(int)Raziel.Senses.ForwardNormal.y,
                                              (int)Raziel.Senses.ForwardNormal.x,2,(_Instance *)0x0,
                                              0);
                      INSTANCE_Post(Inst,0x800000,Data_00);
                      if ((*(uint *)(Data_00 + 0xc) & 4) != 0) {
                        Data_00 = 0x1e;
LAB_800aa448:
                        G2EmulationSwitchAnimationCharacter(In,Data_00,0,3,1);
                      }
                    }
                  }
                  else {
                    if (Data_00 < 0x10000003) {
                      if (Data_00 == 0x10000001) {
                        gameTrackerX.currentMaterialTime._1_1_ = 0;
                        Data_00 = SetObjectData(-(int)Raziel.Senses.ForwardNormal.x,
                                                -(int)Raziel.Senses.ForwardNormal.y,5,
                                                (_Instance *)0x0,0);
                        INSTANCE_Post(Inst,0x800000,Data_00);
                        if ((*(uint *)(Data_00 + 0xc) & 4) == 0) {
                          if ((*(uint *)(Data_00 + 0xc) & 2) != 0) {
                            G2EmulationSwitchAnimationCharacter(In,0x17,0,3,1);
                            Data_00 = SetObjectData(-(int)Raziel.Senses.ForwardNormal.x,
                                                    -(int)Raziel.Senses.ForwardNormal.y,6,
                                                    (_Instance *)0x0,0);
                            INSTANCE_Post(Inst,0x800000,Data_00);
                          }
                        }
                        else {
                          G2EmulationSwitchAnimation(In,2,0,0,3,2);
                          G2EmulationSwitchAnimation(In,0,0x2e,0,0,1);
                          Data_00 = 0x2e;
LAB_800aa350:
                          G2EmulationSwitchAnimation(In,1,Data_00,0,0,1);
                        }
                      }
                    }
                    else {
                      if (Data_00 == 0x10000003) {
                        uVar4 = PHYSOB_CheckSlideNormal
                                          (In->CharacterInstance,(int)Raziel.Senses.ForwardNormal.x,
                                           (int)Raziel.Senses.ForwardNormal.y,apeStack48);
                        if ((uVar4 & 0x4002) == 0x4000) {
                          Data_00 = SetObjectData((int)Raziel.Senses.ForwardNormal.x,
                                                  (int)Raziel.Senses.ForwardNormal.y,4,
                                                  (_Instance *)0x0,0);
                          INSTANCE_Post(Inst,0x800000,Data_00);
                          if ((*(uint *)(Data_00 + 0xc) & 4) != 0) {
                            G2EmulationSwitchAnimation(In,2,0,0,3,2);
                            G2EmulationSwitchAnimation(In,0,0x1f,0,0,1);
                            Data_00 = 0x1f;
                            goto LAB_800aa350;
                          }
                        }
                      }
                      else {
                        if ((Data_00 == 0x10000004) &&
                           (uVar4 = PHYSOB_CheckSlideNormal
                                              (In->CharacterInstance,
                                               (int)Raziel.Senses.ForwardNormal.y,
                                               -(int)Raziel.Senses.ForwardNormal.x,apeStack48),
                           (uVar4 & 0x4002) == 0x4000)) {
                          Data_00 = SetObjectData((int)Raziel.Senses.ForwardNormal.y,
                                                  -(int)Raziel.Senses.ForwardNormal.x,3,
                                                  (_Instance *)0x0,0);
                          INSTANCE_Post(Inst,0x800000,Data_00);
                          if ((*(uint *)(Data_00 + 0xc) & 4) != 0) {
                            Data_00 = 0x2d;
                            goto LAB_800aa448;
                          }
                        }
                      }
                    }
                  }
                }
                gameTrackerX.currentMaterialTime._1_1_ = 0;
              }
            }
            else {
              if (puVar6 != (undefined *)0x20000000) goto LAB_800aa600;
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var7->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPickupObject(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s4*/)
 // line 3533, offset 0x800aa64c
	/* begin block 1 */
		// Start line: 3534
		// Start offset: 0x800AA64C
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3542
			// Start offset: 0x800AA6F4
			// Variables:
		// 		long colorArray[1]; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x800AA6F4
		// End Line: 3542
	/* end block 1 */
	// End offset: 0x800AA808
	// End Line: 3575

	/* begin block 2 */
		// Start line: 7526
	/* end block 2 */
	// End Line: 7527

void StateHandlerPickupObject(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess;
  long local_20 [2];
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    Data_00 = p_Var1->ID;
    if (Data_00 == 0x100004) {
      if (CurrentSection == 1) {
        ControlFlag = ControlFlag & 0xffffefff;
        FX_StopAllGlowEffects(In->CharacterInstance,0);
      }
    }
    else {
      if (Data_00 < 0x100005) {
        if (Data_00 == 0x100001) {
          if (CurrentSection == 1) {
            local_20[0] = 0xff5400;
            ControlFlag = 0x1108;
            Raziel.Mode = Raziel.Mode | 0x800;
            PhysicsMode = 3;
            FX_DoInstanceOneSegmentGlowWithTime
                      (In->CharacterInstance,0x29,local_20,1,0,0x4b,0x4b,10);
            razSetPlayerEventHistory(0x10);
          }
        }
        else {
LAB_800aa7f0:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (Data_00 != 0x8000000) goto LAB_800aa7f0;
        if (CurrentSection == 1) {
          FX_StopAllGlowEffects(In->CharacterInstance,0);
        }
        if ((Raziel._1140_4_ == StateHandlerIdle) ||
           (Raziel._1140_4_ == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0)) {
          Data_00 = SetControlInitIdleData(0,0,3);
          NewProcess = StateHandlerIdle;
        }
        else {
          Data_00 = 0;
          NewProcess = Raziel._1140_4_;
        }
        StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
        Raziel._1140_4_ = (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0;
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerAutoFace(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
 // line 3575, offset 0x800aa828
	/* begin block 1 */
		// Start line: 3576
		// Start offset: 0x800AA828
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Frames; // $s4
	// 		int Anim; // $s3
	/* end block 1 */
	// End offset: 0x800AAEF4
	// End Line: 3768

	/* begin block 2 */
		// Start line: 7633
	/* end block 2 */
	// End Line: 7634

void StateHandlerAutoFace(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  int NewAnim;
  undefined *puVar3;
  uint uVar4;
  int NewAnim_00;
  int iVar5;
  _Instance **pp_Var6;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  iVar5 = 4;
  if (CurrentSection == 2) {
    iVar5 = 6;
  }
  pp_Var6 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      if ((Raziel.padCommands.Queue[5].ID == 6) || ((Raziel.Senses.EngagedMask & 0x40) == 0)) {
        EnMessageQueueData(&In->SectionList[CurrentSection].Event,0x100000,0);
      }
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == (undefined *)0x1000001) {
      if ((CurrentSection == 1) && (In->CharacterInstance->LinkChild != (_Instance *)0x0)) {
        p_Var2->Data = 0;
      }
      NewAnim_00 = p_Var2->Data;
      NewAnim = iVar5;
      if (NewAnim_00 == 0x10001002) {
        if ((iVar1 != 0xf) && (iVar1 != 0x5e)) {
          NewAnim_00 = 0xf;
          goto LAB_800aade4;
        }
        if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5e)) {
          SteerSwitchMode(In->CharacterInstance,0xe);
          NewAnim = 0x5e;
          goto LAB_800aacf4;
        }
      }
      else {
        if (NewAnim_00 < 0x10001003) {
          if (NewAnim_00 == 0x10001001) {
            if ((iVar1 != 0xc) && (iVar1 != 0x5b)) {
              NewAnim_00 = 0xc;
              goto LAB_800aade4;
            }
            if ((((*PadData & 0x80) != 0) && (iVar1 != 0x5b)) &&
               (StateSwitchStateData(In,CurrentSection,StateHandlerAttack2,5), CurrentSection == 2))
            {
              StateSwitchStateData(In,1,StateHandlerAttack2,5);
            }
          }
        }
        else {
          if (NewAnim_00 == 0x10001003) {
            if ((iVar1 == 0xd) || (iVar1 == 0x5c)) {
              if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5c)) {
                SteerSwitchMode(In->CharacterInstance,0xe);
                NewAnim = 0x5c;
LAB_800aacf4:
                G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,0,1);
              }
            }
            else {
              NewAnim_00 = 0xd;
LAB_800aade4:
              G2EmulationSwitchAnimation(In,CurrentSection,NewAnim_00,0,NewAnim,2);
            }
          }
          else {
            if (NewAnim_00 == 0x10001004) {
              if ((iVar1 != 0xe) && (iVar1 != 0x5d)) {
                NewAnim_00 = 0xe;
                goto LAB_800aade4;
              }
              if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5d)) {
                SteerSwitchMode(In->CharacterInstance,0xe);
                NewAnim = 0x5d;
                goto LAB_800aacf4;
              }
            }
          }
        }
      }
    }
    else {
      if ((int)puVar3 < 0x1000002) {
        if (puVar3 == (undefined *)0x0) {
          if (3 < iVar1 - 0x5bU) {
            if (Raziel.padCommands.Queue[5].ID == 6) {
LAB_800aadf4:
              NewAnim = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerIdle,NewAnim);
            }
            else {
              if (iVar1 != 0x37) {
                NewAnim = SetControlInitIdleData(1,0,6);
                StateInitIdle(In,CurrentSection,NewAnim);
              }
            }
          }
        }
        else {
          if ((int)puVar3 < 1) {
            if (puVar3 != (undefined *)0x80000001) {
              if (puVar3 != &DAT_80000002) goto LAB_800aae90;
              if (Raziel.Senses.heldClass != 3) {
                Raziel._1140_4_ = pp_Var6[2];
                StateSwitchStateData(In,CurrentSection,StateHandlerSoulSuck,0);
              }
            }
          }
          else {
            if (puVar3 == (undefined *)0x100001) {
              ControlFlag = 0x1210b;
              if ((*PadData & 0x200) == 0) {
                uVar4 = 0x2000001;
              }
              else {
                uVar4 = 0x2000002;
              }
              Raziel.Mode = Raziel.Mode | uVar4;
              PhysicsMode = 3;
              if (CurrentSection == 0) {
                SteerSwitchMode(In->CharacterInstance,5);
              }
              pp_Var6[0x47] = (_Instance *)0x0;
              NewAnim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x54,-1,-1);
              if (NewAnim != 0) {
                G2EmulationSwitchAnimation(In,CurrentSection,0x37,0,6,2);
              }
              razSetPlayerEventHistory(0x20);
            }
            else {
              if ((int)puVar3 < 0x100002) {
                if (puVar3 == (undefined *)0x100000) goto LAB_800aadf4;
              }
              else {
                if (puVar3 == (undefined *)0x100004) {
                  if (CurrentSection == 0) {
                    SteerSwitchMode(In->CharacterInstance,0);
LAB_800aaa9c:
                    razResetPauseTranslation(In->CharacterInstance);
                  }
                  goto LAB_800aae9c;
                }
              }
LAB_800aae90:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x8000000) {
          if (CurrentSection == 0) {
            SteerSwitchMode(In->CharacterInstance,5);
          }
          NewAnim_00 = 0x37;
          pp_Var6[0x47] = (_Instance *)0x0;
          NewAnim = 6;
          goto LAB_800aade4;
        }
        if ((int)puVar3 < 0x8000001) {
          if (puVar3 == (undefined *)0x2000000) {
            razPickupAndGrab(In,CurrentSection);
          }
          else {
            if (puVar3 != (undefined *)0x4010080) goto LAB_800aae90;
            if (CurrentSection == 0) {
              if (p_Var2->Data != 0) goto LAB_800aaa9c;
              razSetPauseTranslation(In->CharacterInstance);
            }
          }
        }
        else {
          if (puVar3 == (undefined *)0x10000000) {
            if ((ControlFlag & 2U) == 0) {
              if (CurrentSection == 0) {
                StateSwitchStateData(In,0,StateHandlerStartMove,0);
              }
              else {
                EnMessageQueueData(&In->SectionList[0].Event,0x100005,CurrentSection);
              }
            }
          }
          else {
            if ((int)puVar3 < 0x10000001) {
              if (puVar3 != (undefined *)0x8000003) goto LAB_800aae90;
              if (iVar1 == 0x37) {
                pp_Var6[0x47] = (_Instance *)0x1;
              }
            }
            else {
              if (puVar3 != (undefined *)0x20000004) goto LAB_800aae90;
              if (CurrentSection == 0) {
                Raziel.Senses.LastAutoFace = Raziel.Senses.EngagedList[6].instance;
              }
            }
          }
        }
      }
    }
LAB_800aae9c:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerGlyphs(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s5*/)
 // line 3774, offset 0x800aaf24
	/* begin block 1 */
		// Start line: 3775
		// Start offset: 0x800AAF24
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 3942
			// Start offset: 0x800AB510
			// Variables:
		// 		struct evMonsterHitData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x800AB558
		// End Line: 3949
	/* end block 1 */
	// End offset: 0x800AB570
	// End Line: 3974

	/* begin block 2 */
		// Start line: 8035
	/* end block 2 */
	// End Line: 8036

/* WARNING: Type propagation algorithm not settling */

void StateHandlerGlyphs(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *instance;
  undefined *puVar2;
  short source;
  short dest;
  int Ptr;
  code *NewProcess;
  _Instance **pp_Var3;
  __State *p_Var4;
  
  G2EmulationQueryAnimation(In,CurrentSection);
  p_Var4 = In->SectionList + CurrentSection;
  pp_Var3 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var1 = PeekMessageQueue(&p_Var4->Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100000) {
      Ptr = STREAM_IsMorphInProgress();
      if (Ptr == 0) {
        if (pp_Var3[0x47] == (_Instance *)0x0) {
          if ((Raziel.Mode & 0x40000U) == 0) {
            Ptr = SetControlInitIdleData(0,0,3);
            NewProcess = StateHandlerIdle;
          }
          else {
            NewProcess = StateHandlerSwim;
            Ptr = 0;
          }
          StateSwitchStateData(In,CurrentSection,NewProcess,Ptr);
          source = 0x1000;
          if (CurrentSection == 0) {
            dest = 0;
LAB_800ab494:
            razSetFadeEffect(source,dest,0x100);
          }
        }
        else {
          if (((Raziel.Mode & 0x40000U) == 0) && (pp_Var3[0x47] != (_Instance *)0x2)) {
            Ptr = SetControlInitIdleData(0,0,3);
            StateInitIdle(In,CurrentSection,Ptr);
            pp_Var3[0x47] = (_Instance *)0x2;
          }
        }
      }
      else {
        Ptr = 0x100000;
LAB_800ab20c:
        EnMessageQueueData(&p_Var4->Defer,Ptr,0);
      }
    }
    else {
      if ((int)puVar2 < 0x100001) {
        if (puVar2 == (undefined *)0x80002) {
          Ptr = 5;
          if (CurrentSection == 0) {
            instance = In->CharacterInstance;
            goto LAB_800ab3c8;
          }
        }
        else {
          if ((int)puVar2 < 0x80003) {
            if (puVar2 == &DAT_80000010) {
              if (pp_Var3[0x47] != (_Instance *)0x0) {
                if (CurrentSection == 0) {
                  INSTANCE_Post(Raziel.GlyphSystem,(int)&DAT_80000010,(int)In->CharacterInstance);
                }
                if ((Raziel.Mode & 0x40000U) == 0) {
                  Ptr = SetControlInitIdleData(0,0,3);
                  StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Ptr);
                }
                else {
                  StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
                }
              }
            }
            else {
              if ((int)puVar2 < -0x7fffffef) {
                if (puVar2 == (undefined *)0x80000000) goto LAB_800ab464;
                if (puVar2 != &DAT_80000008) goto LAB_800ab558;
              }
              else {
                if (puVar2 != &DAT_80000020) {
                  if (puVar2 == (undefined *)0x80001) {
                    Ptr = 6;
                    if (CurrentSection == 0) {
                      instance = In->CharacterInstance;
                      goto LAB_800ab3c8;
                    }
                    goto LAB_800ab3d0;
                  }
                  goto LAB_800ab558;
                }
              }
            }
            goto LAB_800ab560;
          }
          if (puVar2 == (undefined *)0x80005) {
            Ptr = 1;
            if (CurrentSection == 0) {
              instance = In->CharacterInstance;
              goto LAB_800ab3c8;
            }
          }
          else {
            if ((int)puVar2 < 0x80006) {
              if (puVar2 == (undefined *)0x80003) {
                Ptr = 3;
                if (CurrentSection == 0) {
                  instance = In->CharacterInstance;
LAB_800ab3c8:
                  razSwitchStringAnimation(instance,Ptr);
                }
              }
              else {
                if (puVar2 != (undefined *)0x80004) goto LAB_800ab558;
                Ptr = 2;
                if (CurrentSection == 0) {
                  instance = In->CharacterInstance;
                  goto LAB_800ab3c8;
                }
              }
            }
            else {
              if (puVar2 != (undefined *)0x80006) {
                if (puVar2 == (undefined *)0x80007) {
                  if (CurrentSection == 0) {
                    razSwitchStringAnimation(In->CharacterInstance,0);
                  }
                  pp_Var3[0x47] = (_Instance *)0x0;
                  if (CurrentSection == 0) {
                    razPlaneShift(In->CharacterInstance);
                    if ((Raziel.Mode & 0x40000U) != 0) {
                      CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
                      SteerSwitchMode(In->CharacterInstance,6);
                    }
                    SteerSwitchMode(In->CharacterInstance,0);
                    if ((Raziel.Senses.Flags & 0x40U) != 0) {
                      razSetPlayerEventHistory(0x2000);
                    }
                  }
                  goto LAB_800ab560;
                }
                goto LAB_800ab558;
              }
              Ptr = 4;
              if (CurrentSection == 0) {
                instance = In->CharacterInstance;
                goto LAB_800ab3c8;
              }
            }
          }
        }
LAB_800ab3d0:
        pp_Var3[0x47] = (_Instance *)0x0;
      }
      else {
        if (puVar2 == (undefined *)0x2000000) {
LAB_800ab464:
          if (CurrentSection == 0) {
            INSTANCE_Post(Raziel.GlyphSystem,-0x80000000,0);
            razReaverOff();
            instance = razGetHeldItem();
            source = 0;
            if (instance != (_Instance *)0x0) {
              dest = 0x1000;
              goto LAB_800ab494;
            }
          }
        }
        else {
          if ((int)puVar2 < 0x2000001) {
            if (puVar2 == (undefined *)0x100015) goto LAB_800ab1d8;
            if ((int)puVar2 < 0x100016) {
              if (puVar2 == (undefined *)0x100001) {
                if (CurrentSection == 0) {
                  if (p_Var1->Data == 0) {
                    INSTANCE_Post(Raziel.GlyphSystem,(int)&DAT_80000010,(int)In->CharacterInstance);
                  }
                  Raziel.Mode = Raziel.Mode | 1;
                  ControlFlag = 0x1100008;
                  SteerSwitchMode(In->CharacterInstance,0x10);
                  razResetMotion(In->CharacterInstance);
                  ResetPhysics(In->CharacterInstance,-0x10);
                }
                pp_Var3[0x47] = (_Instance *)0x1;
                PhysicsMode = 3;
                if (p_Var1->Data != 0) {
                  Ptr = 0x80007;
                  goto LAB_800ab20c;
                }
              }
              else {
                if (puVar2 != (undefined *)0x100004) goto LAB_800ab558;
                if (CurrentSection == 0) {
                  razReaverOn();
                  Raziel._1132_4_ = 0;
                }
              }
            }
            else {
              if (puVar2 == (undefined *)0x1000000) {
                Raziel.glowEffect = (_FXGlowEffect *)((_FXGlowEffect *)p_Var1->Data)->next;
                G2EmulationSwitchAnimation(In,CurrentSection,0x7e,0,2,1);
                SteerSwitchMode(In->CharacterInstance,10);
              }
              else {
                if (puVar2 != (undefined *)0x1000001) goto LAB_800ab558;
              }
            }
          }
          else {
            if (puVar2 != (undefined *)0x4020000) {
              if ((int)puVar2 < 0x4020001) {
                if ((puVar2 != (undefined *)0x4000001) && (puVar2 != (undefined *)0x4010200))
                goto LAB_800ab558;
              }
              else {
                if (puVar2 == (undefined *)0x8000003) {
LAB_800ab1d8:
                  if (CurrentSection == 0) {
                    CheckStringAnimation(In->CharacterInstance,p_Var1->ID);
                  }
                }
                else {
                  if ((int)puVar2 < 0x8000004) {
                    if (puVar2 == (undefined *)0x8000000) goto LAB_800ab1d8;
                  }
                  else {
                    if (puVar2 == (undefined *)0x10000000) {
                      if (CurrentSection == 0) {
                        if ((*PadData & 4U) != 0) {
                          INSTANCE_Post(Raziel.GlyphSystem,0x10000004,p_Var1->Data);
                        }
                        if ((*PadData & 8U) != 0) {
                          INSTANCE_Post(Raziel.GlyphSystem,0x10000002,p_Var1->Data);
                        }
                      }
                      goto LAB_800ab560;
                    }
                  }
LAB_800ab558:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
            }
          }
        }
      }
    }
LAB_800ab560:
    DeMessageQueue(&p_Var4->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DefaultStateHandler(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$a2*/)
 // line 4029, offset 0x800ab594
	/* begin block 1 */
		// Start line: 4030
		// Start offset: 0x800AB594
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 4045
			// Start offset: 0x800AB7C4
			// Variables:
		// 		int message; // stack offset -32
		// 		int messageData; // stack offset -28
		/* end block 1.1 */
		// End offset: 0x800AB858
		// End Line: 4063

		/* begin block 1.2 */
			// Start line: 4227
			// Start offset: 0x800ABA0C
			// Variables:
		// 		struct evPhysicsGravityData *ptr; // $v1
		// 		short zRot; // $s0

			/* begin block 1.2.1 */
				// Start line: 4233
				// Start offset: 0x800ABA18
				// Variables:
			// 		struct _Position pos1; // stack offset -48
			// 		struct _Position pos2; // stack offset -40
			// 		int diff; // $v0
			/* end block 1.2.1 */
			// End offset: 0x800ABAE4
			// End Line: 4253
		/* end block 1.2 */
		// End offset: 0x800ABAE4
		// End Line: 4253

		/* begin block 1.3 */
			// Start line: 4285
			// Start offset: 0x800ABB8C
			// Variables:
		// 		struct evFXHitData *BloodData; // $a0
		// 		struct _SVector Accel; // stack offset -48
		/* end block 1.3 */
		// End offset: 0x800ABB8C
		// End Line: 4286

		/* begin block 1.4 */
			// Start line: 4330
			// Start offset: 0x800ABCFC
			// Variables:
		// 		struct evPhysicsEdgeData *data; // $s0
		/* end block 1.4 */
		// End offset: 0x800ABD38
		// End Line: 4336
	/* end block 1 */
	// End offset: 0x800ABE04
	// End Line: 4394

	/* begin block 2 */
		// Start line: 8554
	/* end block 2 */
	// End Line: 8555

void DefaultStateHandler(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  __Event *p_Var2;
  int Data_00;
  _G2Bool_Enum _Var3;
  undefined *puVar4;
  code *NewProcess;
  _Instance *p_Var5;
  int iVar6;
  __MessageQueue *In_00;
  _SVector local_30;
  _Position local_28;
  int local_20;
  int local_1c;
  
  In_00 = &In->SectionList[CurrentSection].Event;
  p_Var2 = PeekMessageQueue(In_00);
  if (p_Var2 == (__Event *)0x0) {
    return;
  }
  puVar4 = (undefined *)p_Var2->ID;
  if (puVar4 == (undefined *)0x1000000) {
    if (CurrentSection != 0) {
      return;
    }
    if ((ControlFlag & 0x4000U) != 0) {
      return;
    }
    if (Raziel.invincibleTimer != 0) {
      return;
    }
    StateSwitchStateCharacterData(In,StateHandlerHitReaction,p_Var2->Data);
    return;
  }
  if ((int)puVar4 < 0x1000001) {
    if (puVar4 == (undefined *)0x4000e) {
      if (p_Var2->Data == 0) {
        return;
      }
      StateSwitchStateData(In,CurrentSection,StateHandlerPuppetShow,0);
      GAMELOOP_Reset24FPS();
      PurgeMessageQueue(In_00);
      return;
    }
    if ((int)puVar4 < 0x4000f) {
      if (puVar4 == &DAT_80000008) {
        StateSwitchStateData(In,CurrentSection,StateHandlerCrouch,1);
        return;
      }
      if ((int)puVar4 < -0x7ffffff7) {
        if (puVar4 == (undefined *)0x80000000) {
          StateSwitchStateData(In,CurrentSection,StateHandlerAttack2,0);
          DeMessageQueue(In_00);
          return;
        }
        if (puVar4 != &DAT_80000004) {
          return;
        }
        Raziel.Mode = Raziel.Mode | 2;
        return;
      }
      if (puVar4 != &DAT_80000020) {
        if (puVar4 != (undefined *)0x40000) {
          return;
        }
        if (CurrentSection == 2) {
          G2EmulationSwitchAnimation(In,2,0,0,3,2);
          return;
        }
        G2EmulationSwitchAnimation(In,CurrentSection,0x17,0,3,1);
        return;
      }
      Data_00 = StateHandlerDecodeHold(&local_20,&local_1c);
      if (Data_00 == 0) {
        return;
      }
      if (local_20 == 0x800010) {
        NewProcess = StateHandlerThrow2;
      }
      else {
        if (local_20 == 0x1000002) {
          StateSwitchStateData(In,CurrentSection,StateHandlerGrab,local_1c);
          return;
        }
        if (local_20 != 0x80000) {
          StateSwitchStateData(In,CurrentSection,StateHandlerAttack2,0);
          EnMessageQueueData(&In->SectionList[CurrentSection].Defer,(int)&DAT_80000020,0);
          return;
        }
        if (CurrentSection == 0) {
          razLaunchForce(In->CharacterInstance);
        }
        NewProcess = StateHandlerThrow2;
      }
    }
    else {
      if (puVar4 == (undefined *)0x100006) {
        InitAlgorithmicWings(In->CharacterInstance);
        return;
      }
      if ((int)puVar4 < 0x100007) {
        if (puVar4 != (undefined *)0x100000) {
          if (puVar4 != (undefined *)0x100005) {
            return;
          }
          Data_00 = p_Var2->Data;
          if (Data_00 == 1) {
            if (In->CharacterInstance->LinkChild != (_Instance *)0x0) {
              G2EmulationSwitchAnimation(In,p_Var2->Data,0x32,0,3,2);
              NewProcess = In->SectionList[CurrentSection].Process;
              CurrentSection = p_Var2->Data;
              goto LAB_800abd94;
            }
            Data_00 = 1;
          }
          G2EmulationSwitchAnimationSync(In,Data_00,0,3);
          return;
        }
        NewProcess = (code *)p_Var2->Data;
        if (NewProcess == (TDRFuncPtr_StateSwitchStateData2NewProcess)0x0) {
          return;
        }
      }
      else {
        if (puVar4 != (undefined *)0x100009) {
          if (puVar4 != (undefined *)0x400000) {
            return;
          }
          if (CurrentSection != 0) {
            return;
          }
          memset(&local_30,0,8);
          FX_Blood2((_SVector *)p_Var2->Data,(_SVector *)p_Var2->Data + 1,&local_30,0x40,0xff8010,
                    0xff8010);
          return;
        }
        if (p_Var2->Data == 0) {
          StateSwitchStateData(In,CurrentSection,Raziel._1140_4_,0);
          if (CurrentSection != 0) {
            return;
          }
          Raziel.Mode = In->SectionList[0].Data1;
          return;
        }
        if (CurrentSection == 0) {
          Raziel._1140_4_ = In->SectionList[0].Process;
          if (Raziel._1140_4_ == StateHandlerSoulSuck) {
            Raziel._1140_4_ = StateHandlerIdle;
          }
          In->SectionList[0].Data1 = Raziel.Mode;
          Raziel.Mode = 0x80000;
        }
        NewProcess = StateHandlerLookAround;
      }
    }
  }
  else {
    if (puVar4 == (undefined *)0x4010010) {
      iVar6 = p_Var2->Data;
      Data_00 = SetControlInitHangData(*(_Instance **)(iVar6 + 0x18),0,3);
      StateSwitchStateData(In,CurrentSection,StateHandlerHang,Data_00);
      (In->CharacterInstance->rotation).z = *(short *)(iVar6 + 0x1c);
      return;
    }
    if ((int)puVar4 < 0x4010011) {
      if (puVar4 == (undefined *)0x4000004) {
        return;
      }
      if ((int)puVar4 < 0x4000005) {
        if (puVar4 != (undefined *)0x1000001) {
          if (puVar4 != (undefined *)0x4000001) {
            return;
          }
          PhysicsMode = 0;
          SetDropPhysics(In->CharacterInstance,&Raziel);
          if ((int)Raziel.fallZVelocity <= In->CharacterInstance->zVel) {
            return;
          }
          if (CurrentSection != 0) {
            return;
          }
          Data_00 = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
          if (Data_00 != 0) {
            G2EmulationSwitchAnimationCharacter(In,0x24,0,4,1);
          }
          NewProcess = StateHandlerFall;
          goto LAB_800abb1c;
        }
        NewProcess = StateHandlerAutoFace;
      }
      else {
        if (puVar4 != (undefined *)0x4000011) {
          if (puVar4 != (undefined *)0x4010008) {
            return;
          }
          if (PhysicsMode == 3) {
            return;
          }
          PhysicsMode = 3;
          SetPhysics(In->CharacterInstance,-0x10,0,0,0);
          return;
        }
        if ((Raziel.Abilities & 2U) == 0) {
          return;
        }
        if (Raziel.Senses.heldClass == 3) {
          return;
        }
        if (Raziel.CurrentPlane != 1) {
          return;
        }
        NewProcess = StateHandlerWallGrab;
      }
    }
    else {
      if (puVar4 == (undefined *)0x4020000) {
        razEnterWater(In,CurrentSection,(evPhysicsSwimData *)p_Var2->Data);
        return;
      }
      if (0x4020000 < (int)puVar4) {
        if (puVar4 == (undefined *)0x8000000) {
          Data_00 = SetControlInitIdleData(0,0,3);
          StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
          return;
        }
        if (puVar4 != (undefined *)0x20000004) {
          return;
        }
        Raziel.Mode = Raziel.Mode & 0xfffffffdU | 1;
        return;
      }
      if (puVar4 == (undefined *)0x4010200) {
        Data_00 = p_Var2->Data;
        if (CurrentSection != 0) {
          return;
        }
        local_30.x = 0;
        local_30.y = 0;
        local_28.x = *(short *)(Data_00 + 4);
        local_28.y = *(short *)(Data_00 + 6);
        local_28.z = *(short *)(Data_00 + 8);
        sVar1 = MATH3D_AngleFromPosToPos((_Position *)&local_30,&local_28);
        _Var3 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,1,0xe);
        if (_Var3 != G2FALSE) {
          G2Anim_DisableController(&In->CharacterInstance->anim,1,0xe);
          if (ExtraRot != (_G2SVector3_Type *)0x0) {
            (In->CharacterInstance->rotation).z = (In->CharacterInstance->rotation).z + ExtraRot->z;
          }
          ExtraRot = (_G2SVector3_Type *)0x0;
        }
        p_Var5 = In->CharacterInstance;
        Data_00 = 0x49;
        if (((int)(p_Var5->rotation).z - (int)sVar1) + 0x3ffU < 0x7ff) {
          (p_Var5->rotation).z = sVar1;
        }
        else {
          Data_00 = 0x4d;
          (p_Var5->rotation).z = sVar1 + 0x800;
        }
        G2EmulationSwitchAnimationCharacter(&Raziel.State,Data_00,0,6,2);
        In = &Raziel.State;
        NewProcess = StateHandlerSlide;
LAB_800abb1c:
        StateSwitchStateCharacterData(In,NewProcess,0);
        return;
      }
      if (puVar4 != (undefined *)0x4010400) {
        return;
      }
      if (CurrentSection == 0) {
        if (LastBlock + 2 < LoopCounter) {
          BlockCount = 0;
        }
        LastBlock = LoopCounter;
        BlockCount = BlockCount + 1;
      }
      if (BlockCount < 0x10) {
        return;
      }
      NewProcess = StateHandlerBlock;
    }
  }
LAB_800abd94:
  StateSwitchStateData(In,CurrentSection,NewProcess,0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ RazielAnimCallback(struct _G2Anim_Type *anim /*$t1*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$a2*/, long messageDataA /*$s1*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
 // line 4398, offset 0x800abe24
	/* begin block 1 */
		// Start line: 4399
		// Start offset: 0x800ABE24
		// Variables:
	// 		struct __State *pSection; // $a0
	// 		struct _G2AnimSection_Type *animSection; // $a3

		/* begin block 1.1 */
			// Start line: 4416
			// Start offset: 0x800ABED4
			// Variables:
		// 		struct evAnimationControllerDoneData *ControllerData; // $v1
		/* end block 1.1 */
		// End offset: 0x800ABF5C
		// End Line: 4432

		/* begin block 1.2 */
			// Start line: 4446
			// Start offset: 0x800ABFA4
			// Variables:
		// 		struct __AlarmData *data; // $s0
		// 		struct _Instance *inst; // $a0
		/* end block 1.2 */
		// End offset: 0x800AC1A4
		// End Line: 4518
	/* end block 1 */
	// End offset: 0x800AC1BC
	// End Line: 4526

	/* begin block 2 */
		// Start line: 9313
	/* end block 2 */
	// End Line: 9314

/* WARNING: Type propagation algorithm not settling */

long RazielAnimCallback(_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,
                       long messageDataA,long messageDataB,void *data)

{
  evAnimationControllerDoneData *ControllerData;
  _Instance *Inst;
  int iVar1;
  _G2AnimSection_Type *p_Var2;
  
  p_Var2 = anim->section + sectionID;
  switch(message) {
  case G2ANIM_MSG_DONE:
    EnMessageQueueData(&Raziel.State.SectionList[sectionID].Event,0x8000000,(uint)p_Var2->keylistID)
    ;
    break;
  case G2ANIM_MSG_LOOPPOINT:
    EnMessageQueueData(&Raziel.State.SectionList[sectionID].Event,0x8000001,(uint)p_Var2->keylistID)
    ;
    break;
  case G2ANIM_MSG_SECTION_INTERPDONE:
    EnMessageQueueData(&Raziel.State.SectionList[sectionID].Event,0x8000003,(uint)p_Var2->keylistID)
    ;
    break;
  case G2ANIM_MSG_SEGCTRLR_INTERPDONE:
    ControllerData =
         (evAnimationControllerDoneData *)
         SetAnimationControllerDoneData
                   (Raziel.State.CharacterInstance,messageDataB,messageDataA,(int)data);
    iVar1 = ControllerData->data;
    if (iVar1 == 2) {
      AlgorithmicWings(Raziel.State.CharacterInstance,ControllerData);
    }
    else {
      if (iVar1 == 0) {
        G2Anim_InterpDisableController
                  (&ControllerData->instance->anim,ControllerData->segment,ControllerData->type,300)
        ;
      }
      else {
        if (iVar1 == 4) {
          G2Anim_DisableController
                    (&ControllerData->instance->anim,ControllerData->segment,ControllerData->type);
        }
      }
    }
    break;
  case G2ANIM_MSG_SWALARMSET:
    p_Var2->swAlarmTable = (short *)0x0;
    EnMessageQueueData(&Raziel.State.SectionList[sectionID].Event,0x8000004,0);
    break;
  case G2ANIM_MSG_PLAYEFFECT:
    if (messageDataA == 2) {
      Inst = razGetHeldWeapon();
      switch((int)(((uint)*(ushort *)messageDataB - 1) * 0x10000) >> 0x10) {
      case 1:
        if (Inst == (_Instance *)0x0) {
          DisableWristCollision(gameTrackerX.playerInstance,(int)*(short *)(messageDataB + 2));
        }
        else {
          INSTANCE_Post(Inst,0x200003,(int)*(short *)(messageDataB + 2));
        }
        ControlFlag = ControlFlag | 0x10000000;
        return 2;
      case 2:
        razSetCowlNoDraw(0);
        ControlFlag = ControlFlag | 0x40;
        return 2;
      case 3:
        razSetCowlNoDraw(1);
        ControlFlag = ControlFlag & 0xffffffbf;
        return 2;
      case 4:
        if (0x1f < (int)*(short *)(messageDataB + 2)) {
          Raziel.throwReturnRot = -1;
          return 2;
        }
        Raziel.throwReturnRot =
             Raziel.throwReturnRot | 1 << ((int)*(short *)(messageDataB + 2) & 0x1fU);
        return 2;
      case 5:
        if (0x1f < (int)*(short *)(messageDataB + 2)) {
          Raziel.throwReturnRot = 0;
          return 2;
        }
        Raziel.throwReturnRot =
             Raziel.throwReturnRot & ~(1 << ((int)*(short *)(messageDataB + 2) & 0x1fU));
        return 2;
      case 6:
        Raziel.padCommands.Queue[0].ID = Raziel.padCommands.Queue[0].ID | 1;
        Raziel.padCommands.Queue[0].Data._0_2_ = (gameTrackerX.playerInstance)->fadeValue;
        Raziel.padCommands.Queue[0].Data._2_2_ = *(undefined2 *)(messageDataB + 2);
        return 2;
      case 7:
        Raziel.padCommands.Queue[0].ID = Raziel.padCommands.Queue[0].ID | 1;
        Raziel.padCommands.Queue[1].ID = (int)*(short *)(messageDataB + 2);
        Raziel.padCommands.Queue[1].Data = 0;
        return 2;
      case 8:
        if (Inst == (_Instance *)0x0) {
          return 2;
        }
        INSTANCE_Post(Inst,0x200005,(int)*(short *)(messageDataB + 2));
        return 2;
      case 9:
        if (Inst == (_Instance *)0x0) {
          return 2;
        }
        INSTANCE_Post(Inst,0x200006,(int)*(short *)(messageDataB + 2));
        return 2;
      default:
        return 2;
      case 0:
        goto switchD_800abfe0_caseD_0;
      }
    }
  default:
    INSTANCE_DefaultAnimCallback
              (anim,sectionID,message,messageDataA,messageDataB,Raziel.State.CharacterInstance);
  }
  return messageDataA;
switchD_800abfe0_caseD_0:
  if (Inst != (_Instance *)0x0) {
    INSTANCE_Post(Inst,0x200002,(int)*(short *)(messageDataB + 2));
    return 2;
  }
  EnableWristCollision(gameTrackerX.playerInstance,(int)*(short *)(messageDataB + 2));
  return 2;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ RazielQuery(struct _Instance *instance /*$s0*/, unsigned long Query /*$a1*/)
 // line 4569, offset 0x800ac1d4
	/* begin block 1 */
		// Start line: 4570
		// Start offset: 0x800AC1D4

		/* begin block 1.1 */
			// Start line: 4632
			// Start offset: 0x800AC2E8
			// Variables:
		// 		struct _Normal *Ptr; // $a0
		/* end block 1.1 */
		// End offset: 0x800AC390
		// End Line: 4648

		/* begin block 1.2 */
			// Start line: 4651
			// Start offset: 0x800AC390
			// Variables:
		// 		unsigned long ability; // $s0
		/* end block 1.2 */
		// End offset: 0x800AC404
		// End Line: 4669

		/* begin block 1.3 */
			// Start line: 4671
			// Start offset: 0x800AC404
			// Variables:
		// 		struct PlayerSaveData data; // stack offset -32
		/* end block 1.3 */
		// End offset: 0x800AC44C
		// End Line: 4684

		/* begin block 1.4 */
			// Start line: 4701
			// Start offset: 0x800AC498
			// Variables:
		// 		struct evShadowSegmentData *shadowData; // $v0
		/* end block 1.4 */
		// End offset: 0x800AC4B4
		// End Line: 4708
	/* end block 1 */
	// End offset: 0x800AC508
	// End Line: 4729

	/* begin block 2 */
		// Start line: 9132
	/* end block 2 */
	// End Line: 9133

ulong RazielQuery(_Instance *instance,ulong Query)

{
  Level *pLVar1;
  int iVar2;
  int iVar3;
  _Instance *p_Var4;
  undefined local_20 [24];
  
  switch(Query) {
  case 1:
    p_Var4 = (_Instance *)0x1;
    break;
  case 6:
    p_Var4 = (_Instance *)
             SetPositionData((int)(instance->position).x,(int)(instance->position).y,
                             (int)(instance->position).z);
    break;
  case 7:
    if (Raziel.steeringMode == 4) {
      p_Var4 = (_Instance *)
               SetPositionData((int)(instance->rotation).x,(int)(instance->rotation).y,
                               Raziel.steeringLockRotation);
    }
    else {
      p_Var4 = (_Instance *)
               SetPositionData((int)(instance->rotation).x,(int)(instance->rotation).y,
                               (int)(instance->rotation).z);
    }
    break;
  case 8:
    p_Var4 = (_Instance *)0x0;
    if (ExtraRot != (_G2SVector3_Type *)0x0) {
      p_Var4 = (_Instance *)ExtraRot;
    }
    break;
  case 9:
    p_Var4 = (_Instance *)WaterStatus;
    break;
  case 10:
    p_Var4 = (_Instance *)Raziel.Mode;
    break;
  case 0xb:
    p_Var4 = (_Instance *)Raziel.CurrentPlane;
    break;
  case 0xc:
    if (instance->oldMatrix != (MATRIX *)0x0) {
      return (ulong)(instance->oldMatrix + 0xf);
    }
  default:
    p_Var4 = (_Instance *)0x0;
    break;
  case 0xd:
    p_Var4 = (_Instance *)0x0;
    if ((_Instance *)instance->oldMatrix != (_Instance *)0x0) {
      p_Var4 = (_Instance *)instance->oldMatrix;
    }
    break;
  case 0x10:
    p_Var4 = (_Instance *)CIRC_Alloc(8);
    if (Raziel.Mode == 0x40000) {
      *(short *)&(p_Var4->node).prev = instance->matrix[1].m[2];
      *(short *)((int)&(p_Var4->node).prev + 2) = instance->matrix[1].m[5];
      *(short *)&(p_Var4->node).next = instance->matrix[1].m[8];
    }
    else {
      *(short *)&(p_Var4->node).prev = -instance->matrix->m[1];
      *(short *)((int)&(p_Var4->node).prev + 2) = -instance->matrix->m[4];
      *(short *)&(p_Var4->node).next = -instance->matrix->m[7];
    }
    break;
  case 0x13:
    pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
    iVar3 = Raziel.Abilities;
    p_Var4 = (_Instance *)(Raziel.Abilities & 0x3fc0000);
    if (((pLVar1->unitFlags & 0x800U) != 0) || (iVar2 = RAZIEL_OkToShift(), iVar2 == 0)) {
      p_Var4 = (_Instance *)(iVar3 & 0x2fc0000);
    }
    if (((Raziel.Mode & 0x40000U) != 0) || (Raziel.CurrentPlane == 2)) {
      p_Var4 = (_Instance *)((uint)p_Var4 & 0x1000000);
    }
    break;
  case 0x18:
    p_Var4 = (_Instance *)SetControlSaveDataData(0x18,local_20);
    break;
  case 0x1f:
    p_Var4 = (_Instance *)(int)Raziel.HealthBalls;
    break;
  case 0x20:
    p_Var4 = (_Instance *)(uint)Raziel.GlyphManaBalls;
    break;
  case 0x22:
    p_Var4 = (_Instance *)0x0;
    if ((Raziel.Senses.EngagedMask & 0x40) != 0) {
      p_Var4 = Raziel.Senses.EngagedList[6].instance;
    }
    break;
  case 0x24:
    p_Var4 = (_Instance *)Raziel.Abilities;
    break;
  case 0x26:
    p_Var4 = (_Instance *)SetShadowSegmentData(2);
    *(undefined2 *)&(p_Var4->node).next = 0xc;
    *(undefined2 *)((int)&(p_Var4->node).next + 2) = 8;
    break;
  case 0x27:
    p_Var4 = (_Instance *)Raziel.Senses.EngagedMask;
    break;
  case 0x29:
    p_Var4 = (_Instance *)Raziel.padCommands.Queue[12].ID;
    break;
  case 0x2a:
    p_Var4 = (_Instance *)Raziel.padCommands.Queue[12].Data;
    break;
  case 0x2b:
    iVar3 = GetMaxHealth();
    p_Var4 = (_Instance *)(uint)(Raziel.HitPoints == iVar3);
    break;
  case 0x2c:
    p_Var4 = razGetHeldItem();
  }
  return (ulong)p_Var4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielPost(struct _Instance *instance /*$s1*/, unsigned long Message /*$s2*/, unsigned long Data /*$s3*/)
 // line 4733, offset 0x800ac518
	/* begin block 1 */
		// Start line: 4734
		// Start offset: 0x800AC518
		// Variables:
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 4741
			// Start offset: 0x800AC768
			// Variables:
		// 		struct evCollideInstanceStatsData *Ptr; // $s0
		/* end block 1.1 */
		// End offset: 0x800AC830
		// End Line: 4759

		/* begin block 1.2 */
			// Start line: 4808
			// Start offset: 0x800AC87C
			// Variables:
		// 		struct PlayerSaveData *data; // $s0
		/* end block 1.2 */
		// End offset: 0x800AC904
		// End Line: 4832

		/* begin block 1.3 */
			// Start line: 4858
			// Start offset: 0x800AC9B8
		/* end block 1.3 */
		// End offset: 0x800AC9CC
		// End Line: 4864

		/* begin block 1.4 */
			// Start line: 4884
			// Start offset: 0x800ACA50
		/* end block 1.4 */
		// End offset: 0x800ACAB8
		// End Line: 4900

		/* begin block 1.5 */
			// Start line: 4903
			// Start offset: 0x800ACAC0
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.5 */
		// End offset: 0x800ACAE0
		// End Line: 4908

		/* begin block 1.6 */
			// Start line: 4912
			// Start offset: 0x800ACAF8
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.6 */
		// End offset: 0x800ACB20
		// End Line: 4917

		/* begin block 1.7 */
			// Start line: 4972
			// Start offset: 0x800ACC80
		/* end block 1.7 */
		// End offset: 0x800ACCB0
		// End Line: 4979

		/* begin block 1.8 */
			// Start line: 4981
			// Start offset: 0x800ACCB0
		/* end block 1.8 */
		// End offset: 0x800ACCDC
		// End Line: 4995
	/* end block 1 */
	// End offset: 0x800ACD44
	// End Line: 5010

	/* begin block 2 */
		// Start line: 9964
	/* end block 2 */
	// End Line: 9965

void RazielPost(_Instance *instance,ulong Message,ulong Data)

{
  ulong uVar1;
  int iVar2;
  int Data_00;
  uint uVar3;
  uint uVar4;
  code *NewProcess;
  long lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  evCollideInstanceStatsData *Ptr;
  ulong *puVar8;
  int CurrentSection;
  __MessageQueue *In;
  
  if (Message == 0x10000a) {
    CurrentSection = 0;
    if (Data != 0) {
      Data_00 = 0x1e8;
      do {
        iVar2 = (int)&(instance->node).prev + Data_00;
        CurrentSection = CurrentSection + 1;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
        *(undefined4 *)(iVar2 + 0x20) = 0;
        Data_00 = Data_00 + 0x30;
      } while (CurrentSection < 3);
      DeInitAlgorithmicWings(instance);
      razResetPauseTranslation(instance);
      return;
    }
    Data_00 = 0x1e8;
    do {
      iVar2 = (int)&(instance->node).prev + Data_00;
      CurrentSection = CurrentSection + 1;
      *(undefined4 *)(iVar2 + 0x1c) = 0x800abe24;
      *(undefined4 *)(iVar2 + 0x20) = 0;
      Data_00 = Data_00 + 0x30;
    } while (CurrentSection < 3);
    InitAlgorithmicWings(instance);
    return;
  }
  if (Message < 0x10000b) {
    if (Message == 0x40012) {
      NewProcess = StateHandlerDropAction;
LAB_800acbdc:
      StateSwitchStateCharacterData(&Raziel.State,NewProcess,0);
      return;
    }
    if (Message < 0x40013) {
      if (Message == 0x40005) {
        StateSwitchStateCharacterData(&Raziel.State,StateHandlerStumble,Data);
        return;
      }
      if (Message < 0x40006) {
        if (Message == 0x40001) {
          instance->currentStreamUnitID = Data;
          instance->tface = (_TFace *)0x0;
          (Raziel.GlyphSystem)->currentStreamUnitID = Data;
          (Raziel.GlyphSystem)->tface = (_TFace *)0x0;
          if (Raziel.soulReaver == (_Instance *)0x0) {
            return;
          }
          (Raziel.soulReaver)->currentStreamUnitID = Data;
          (Raziel.soulReaver)->tface = (_TFace *)0x0;
          return;
        }
        if (Message == 0x40004) {
          G2EmulationSwitchAnimationCharacter(&Raziel.State,0x81,0,3,1);
          NewProcess = StateHandlerCannedReaction;
          goto LAB_800acbdc;
        }
      }
      else {
        if (Message == 0x40008) {
          DrainMana(Data);
          return;
        }
        if (Message < 0x40009) {
          if (Message == 0x40006) {
            DrainHealth(Data);
            return;
          }
        }
        else {
          if (Message == 0x40011) {
            HealthInstantDeath(instance);
            return;
          }
        }
      }
    }
    else {
      if (Message == 0x40022) {
        Raziel.padCommands.Queue[10].ID = Data;
        return;
      }
      if (Message < 0x40023) {
        if (Message == 0x40015) {
          debugRazielFlags1 = Raziel.Abilities | Data;
          if ((Data & 0x3fc00) == 0) {
            Raziel.Abilities = debugRazielFlags1;
            return;
          }
          if (Raziel.soulReaver == (_Instance *)0x0) {
            Raziel.Abilities = debugRazielFlags1;
            return;
          }
          Raziel.Abilities = debugRazielFlags1;
          CurrentSection = razGetReaverFromMask(Data);
          razReaverImbue(CurrentSection);
          return;
        }
        if (Message == 0x40019) {
          SetMana(Data);
          return;
        }
      }
      else {
        if (Message == 0x100007) {
          puVar8 = *(ulong **)(Data + 4);
          debugRazielFlags1 = *puVar8;
          Raziel.CurrentPlane = puVar8[1];
          Raziel.HealthScale = *(short *)(puVar8 + 2);
          Raziel.HealthBalls = *(short *)(puVar8 + 3);
          Raziel.GlyphManaBalls = *(ushort *)(puVar8 + 4);
          Raziel.GlyphManaMax = *(ushort *)((int)puVar8 + 0x12);
          Raziel.Abilities = debugRazielFlags1;
          Raziel.HitPoints = GetMaxHealth();
          if ((Raziel.Abilities & 8U) != 0) {
            debugRazielFlags2 = 0;
          }
          Raziel.soulReaver = (_Instance *)0x0;
          Raziel.padCommands.Queue[12].Data = puVar8[5];
          return;
        }
        if (Message < 0x100008) {
          if (Message == 0x40024) {
            CurrentSection = SndTypeIsPlayingOrRequested(1);
            if (CurrentSection != 0) {
              return;
            }
            SOUND_Play3dSound(&(gameTrackerX.playerInstance)->position,1,0,0x3c,0xdac);
            return;
          }
        }
        else {
          if (Message == 0x100008) {
            if ((ControlFlag & 0x200000U) != 0) {
              RelocateConstrict((_SVector *)Data);
            }
            Raziel.padCommands.Queue[6].ID._0_2_ =
                 (short)Raziel.padCommands.Queue[6].ID + *(short *)Data;
            Raziel.padCommands.Queue[6].ID._2_2_ =
                 Raziel.padCommands.Queue[6].ID._2_2_ + *(short *)(Data + 2);
            Raziel.padCommands.Queue[6].Data._0_2_ =
                 (short)Raziel.padCommands.Queue[6].Data + *(short *)(Data + 4);
            STREAM_MORPH_Relocate();
            return;
          }
        }
      }
    }
  }
  else {
    if (Message == 0x200004) {
      CurrentSection = 0x200004;
LAB_800acc70:
      EnMessageQueueData(&Raziel.State.SectionList[0].Defer,CurrentSection,Data);
      return;
    }
    if (Message < 0x200005) {
      if (Message == 0x100012) {
        razReaverOff();
        Raziel.Senses.heldClass = INSTANCE_Query((_Instance *)Data,4);
        uVar4 = 0xfffff7ff;
        uVar3 = Raziel.Mode;
LAB_800acca0:
        Raziel.Mode = uVar3 & uVar4;
        return;
      }
      if (Message < 0x100013) {
        if (Message == 0x100010) {
          if (Data != 0) {
            if ((Raziel.Mode & 0x40000000U) != 0) {
              return;
            }
            Raziel.Mode = 0x40000000;
            ResetPhysics(instance,-0x10);
            CurrentSection = 0;
            do {
              Data_00 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(&Raziel.State,CurrentSection,StateHandlerIdle,Data_00);
              CurrentSection = CurrentSection + 1;
            } while (CurrentSection < 3);
            return;
          }
          if ((Raziel.Mode & 0x40000000U) == 0) {
            return;
          }
          uVar3 = 0xbfffffff;
          uVar4 = Raziel.Mode;
          goto LAB_800acca0;
        }
        if (Message == 0x100011) {
          CurrentSection = 0x100011;
          goto LAB_800acc70;
        }
      }
      else {
        if (Message == 0x200000) {
          if ((ControlFlag & 0x40000U) == 0) {
            Raziel.Senses.EngagedMask = 0;
          }
          Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffff9f;
          return;
        }
        if (Message < 0x200001) {
          if (Message == 0x100013) {
            if ((_Instance *)Data == Raziel.soulReaver) {
              return;
            }
            CurrentSection = razReaverOn();
            if (CurrentSection != 0) {
              return;
            }
            Raziel.Senses.heldClass = 0;
            return;
          }
        }
        else {
          if (Message == 0x200001) {
            if ((ControlFlag & 0x40000U) != 0) {
              return;
            }
            Ptr = (evCollideInstanceStatsData *)Data;
            if (((ControlFlag & 0x100000U) != 0) &&
               ((uVar1 = INSTANCE_Query(*(_Instance **)Data,1), (uVar1 & 2) != 0 ||
                (uVar1 = INSTANCE_Query(*(_Instance **)Data,2), (uVar1 & 1) != 0)))) {
              Ptr = (evCollideInstanceStatsData *)CIRC_Alloc(0x18);
              uVar1 = *(ulong *)(Data + 4);
              uVar6 = *(undefined4 *)(Data + 8);
              uVar7 = *(undefined4 *)(Data + 0xc);
              Ptr->instance = *(_Instance **)Data;
              Ptr->distance = uVar1;
              *(undefined4 *)&Ptr->relativePosition = uVar6;
              *(undefined4 *)&(Ptr->relativePosition).z = uVar7;
              lVar5 = *(long *)(Data + 0x14);
              Ptr->xyDistance = *(long *)(Data + 0x10);
              Ptr->zDelta = lVar5;
              INSTANCE_Post(Raziel.GlyphSystem,0x200001,(int)Ptr);
            }
            CurrentSection = HealthCheckForLowHealth();
            if (CurrentSection != 0) {
              return;
            }
            UpdateEngagementList(Ptr,&Raziel);
            return;
          }
        }
      }
    }
    else {
      if (Message == 0x4000006) {
        Raziel.slipSlope = 0xb50;
        return;
      }
      if (Message < 0x4000007) {
        if (Message == 0x4000001) {
          if ((ControlFlag & 8U) == 0) {
            return;
          }
          CurrentSection = 0;
          if ((Raziel.Senses.Flags & 2U) != 0) {
            return;
          }
          In = &Raziel.State.SectionList[0].Defer;
          do {
            EnMessageQueueData(In,0x4000001,Data);
            CurrentSection = CurrentSection + 1;
            In = (__MessageQueue *)&In[2].Queue[0].Data;
          } while (CurrentSection < 3);
          return;
        }
        if (Message < 0x4000002) {
          if (Message == 0x800024) {
            Raziel.idleInstance = *(_Instance **)(Data + 4);
            return;
          }
        }
        else {
          if (Message == 0x4000005) {
            Raziel.slipSlope = Data;
            return;
          }
        }
      }
      else {
        if (Message == 0x10002000) {
          razPlaneShift(instance);
          return;
        }
        if ((0x10001fff < Message) && (Message < 0x10002003)) {
          StateSwitchStateCharacterData(&Raziel.State,StateHandlerGlyphs,1);
          return;
        }
      }
    }
  }
  CurrentSection = 0;
  In = &Raziel.State.SectionList[0].Defer;
  do {
    EnMessageQueueData(In,Message,Data);
    CurrentSection = CurrentSection + 1;
    In = (__MessageQueue *)&In[2].Queue[0].Data;
  } while (CurrentSection < 3);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetStates(struct _Instance *instance /*$s4*/, struct GameTracker *GT /*$s7*/, long *controlCommand /*$s6*/, int AnalogLength /*$a3*/)
 // line 5014, offset 0x800acd60
	/* begin block 1 */
		// Start line: 5015
		// Start offset: 0x800ACD60
		// Variables:
	// 		int i; // $s0
	// 		int Event; // $s2
	// 		int Data1; // $s3
	// 		static unsigned long LastTime; // offset 0x0
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800AD32C
	// End Line: 5258

	/* begin block 2 */
		// Start line: 10557
	/* end block 2 */
	// End Line: 10558

/* WARNING: Type propagation algorithm not settling */

int SetStates(_Instance *instance,GameTracker *GT,long *controlCommand,int AnalogLength)

{
  __CharacterState *p_Var1;
  uint Data;
  __Event *Element;
  _Instance *Target;
  int Data_00;
  int iVar2;
  __MessageQueue *In;
  __Player *p_Var3;
  
  Data = GetRCnt(0xf2000000);
  Data_00 = 0;
  iVar2 = 0;
  LastTime_336 = Data & 0xffff | gameTimer << 0x10;
  LoopCounter = LoopCounter + 1;
  gameTracker = GT;
  PadData = controlCommand;
  do {
    while( true ) {
      Element = DeMessageQueue((__MessageQueue *)
                               ((int)&Raziel.State.SectionList[0].Defer.Head + iVar2));
      if (Element == (__Event *)0x0) break;
      EnMessageQueue((__MessageQueue *)((int)&Raziel.State.SectionList[0].Event.Head + iVar2),
                     Element);
    }
    Data_00 = Data_00 + 1;
    iVar2 = iVar2 + 0x11c;
  } while (Data_00 < 3);
  if ((*(int *)&instance->offset == 0) && ((instance->offset).z == 0)) {
    (instance->position).x = (instance->position).x + (short)Raziel.padCommands.Queue[10].Data;
    (instance->position).y = (instance->position).y + Raziel.padCommands.Queue[10].Data._2_2_;
    (instance->position).z = (instance->position).z + (short)Raziel.padCommands.Queue[11].ID;
  }
  else {
    INSTANCE_Post(instance,0x4000004,LoopCounter);
    SetImpulsePhysics(instance,&Raziel);
  }
  if (Raziel.Senses.HitMonster != (_Instance *)0x0) {
    Data_00 = SetMonsterHitData(Raziel.Senses.HitMonster,(_Instance *)0x0,0x1000,
                                (uint)(Raziel.attack)->knockBackDistance,
                                (uint)(Raziel.attack)->knockBackFrames);
    INSTANCE_Post(instance,0x2000002,Data_00);
    DisableWristCollision(instance,1);
    DisableWristCollision(instance,2);
  }
  if (((gameTrackerX.playerInstance)->flags & 0x100U) == 0) {
    if ((ControlFlag & 0x800000U) == 0) {
      Data_00 = GetControllerMessages(controlCommand);
      if ((Data_00 == -0x80000000) &&
         (((Raziel.Senses.EngagedMask & 0x681f) != 0 ||
          (((Raziel.Senses.EngagedMask & 0x20) != 0 &&
           (Target = razGetHeldItem(), Target == (_Instance *)0x0)))))) {
        Data_00 = 0x2000000;
      }
      if (Data_00 != 0) {
        iVar2 = 0;
        p_Var1 = &Raziel.State;
        do {
          In = &p_Var1->SectionList[0].Event;
          EnMessageQueueData(In,Data_00,0);
          iVar2 = iVar2 + 1;
          p_Var1 = (__CharacterState *)(In + 2);
        } while (iVar2 < 3);
      }
      Data = ProcessMovement(instance,controlCommand,GT);
      if (Data == 0) {
        Data_00 = 0;
      }
      else {
        Data_00 = 0x10000000;
        if ((Data & 0x1000) != 0) {
          Data_00 = 0x1000001;
        }
      }
      iVar2 = 0;
      p_Var1 = &Raziel.State;
      do {
        In = &p_Var1->SectionList[0].Event;
        EnMessageQueueData(In,Data_00,Data);
        iVar2 = iVar2 + 1;
        p_Var1 = (__CharacterState *)(In + 2);
      } while (iVar2 < 3);
    }
    else {
      Data_00 = 0;
      p_Var1 = &Raziel.State;
      do {
        In = &p_Var1->SectionList[0].Event;
        EnMessageQueueData(In,0,0);
        Data_00 = Data_00 + 1;
        p_Var1 = (__CharacterState *)(In + 2);
      } while (Data_00 < 3);
    }
  }
  razSetPlayerEvent();
  G2EmulatePlayAnimation(&Raziel.State);
  p_Var3 = &Raziel;
  Data_00 = 0;
  do {
    p_Var1 = &p_Var3->State;
    p_Var3 = (__Player *)&(p_Var3->State).SectionList[0].Defer.Queue[0xf].Data;
    iVar2 = Data_00 + 1;
    (*p_Var1->SectionList[0].Process)(0x800d5660,Data_00);
    Data_00 = iVar2;
  } while (iVar2 < 3);
  if (*(short *)&gameTracker->plan_collide_override == 1) {
    PhysicsMode = 3;
  }
  ProcessPhysics(&Raziel,&Raziel.State,0,PhysicsMode);
  if ((*PadData & 0x200) == 0) {
    Raziel.padCommands.Queue[5].ID = Raziel.padCommands.Queue[5].ID + 1;
    if (Raziel.padCommands.Queue[5].ID < 6) {
      if (((Raziel.Senses.EngagedMask & 0x40) != 0) &&
         (Data_00 = 0, (Raziel.Mode & 0x2000000U) == 0)) {
        p_Var1 = &Raziel.State;
        do {
          In = &p_Var1->SectionList[0].Event;
          EnMessageQueueData(In,0x1000001,0);
          Data_00 = Data_00 + 1;
          p_Var1 = (__CharacterState *)(In + 2);
        } while (Data_00 < 3);
      }
    }
    else {
      if (Raziel.padCommands.Queue[5].ID == 6) {
        Raziel.Senses.LastAutoFace = (_Instance *)0x0;
        Raziel.Senses.CurrentAutoFace = (_Instance *)0x0;
      }
    }
    ControlFlag = ControlFlag & 0xfffffffb;
  }
  else {
    Raziel.padCommands.Queue[5].ID = 0;
    if (((Raziel.Senses.EngagedMask & 0x40) != 0) && ((Raziel.Mode & 0x2000000U) == 0)) {
      Data_00 = 0;
      p_Var1 = &Raziel.State;
      do {
        In = &p_Var1->SectionList[0].Event;
        EnMessageQueueData(In,0x1000001,0);
        Data_00 = Data_00 + 1;
        p_Var1 = (__CharacterState *)(In + 2);
      } while (Data_00 < 3);
    }
    ControlFlag = ControlFlag | 4;
    if ((Raziel.Senses.EngagedMask & 0x40) == 0) {
      Raziel.Senses.CurrentAutoFace = (_Instance *)0x0;
    }
    else {
      Raziel.Senses.CurrentAutoFace = Raziel.Senses.EngagedList[6].instance;
    }
  }
  AutoFaceAngle = -1;
  Raziel.iVelocity.x = ((instance->position).x - (instance->oldPos).x) - (instance->offset).x;
  Raziel.iVelocity.y = ((instance->position).y - (instance->oldPos).y) - (instance->offset).y;
  Raziel.iVelocity.z = ((instance->position).z - (instance->oldPos).z) - (instance->offset).z;
  StateGovernState(&Raziel.State,3);
  if (((gameTrackerX.debugFlags2 & 0x800U) != 0) && ((ControlFlag & 0x1000000U) == 0)) {
    ProcessHealth(instance);
  }
  if ((ControlFlag & 0x20000U) != 0) {
    if ((Raziel.Senses.EngagedMask & 0x400) == 0) {
      Target = (_Instance *)0x0;
      if ((Raziel.Senses.Flags & 0x10U) == 0) goto LAB_800ad2e8;
    }
    else {
      Target = Raziel.Senses.EngagedList[10].instance;
    }
    AlgorithmicNeck(instance,Target);
  }
LAB_800ad2e8:
  if (((ControlFlag & 0x200000U) != 0) && (DAT_800d2234 != 0)) {
    ProcessConstrict();
  }
  if (Raziel.padCommands.Queue[0].ID != 0) {
    ProcessEffects(instance);
  }
  ProcessInteractiveMusic(instance);
  ProcessSpecialAbilities(instance);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessConstrict()
 // line 5273, offset 0x800ad36c
	/* begin block 1 */
		// Start line: 5274
		// Start offset: 0x800AD36C

		/* begin block 1.1 */
			// Start line: 5315
			// Start offset: 0x800AD470
			// Variables:
		// 		int i; // $s0

			/* begin block 1.1.1 */
				// Start line: 5363
				// Start offset: 0x800AD538
				// Variables:
			// 		int thisIndex; // $v1
			// 		int nextIndex; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800AD59C
			// End Line: 5384
		/* end block 1.1 */
		// End offset: 0x800AD620
		// End Line: 5406
	/* end block 1 */
	// End offset: 0x800AD620
	// End Line: 5437

	/* begin block 2 */
		// Start line: 11153
	/* end block 2 */
	// End Line: 11154

	/* begin block 3 */
		// Start line: 11156
	/* end block 3 */
	// End Line: 11157

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ProcessConstrict(void)

{
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  
  if ((Raziel.constrictFlag & 1U) != 0) {
    Raziel.constrictFlag = Raziel.constrictFlag & 0xfffeU | 4;
    Raziel.constrictIndex = 0;
    Raziel.constrictWaitIndex = 0;
    Raziel.constrictXTotal = 0;
    Raziel.constrictYTotal = 0;
    Raziel.constrictGoodCircle = 0;
  }
  Raziel.constrictXTotal =
       Raziel.constrictXTotal + (int)((Raziel.State.CharacterInstance)->position).x;
  Raziel.constrictYTotal =
       Raziel.constrictYTotal + (int)((Raziel.State.CharacterInstance)->position).y;
  Raziel.constrictData[Raziel.constrictIndex].x = ((Raziel.State.CharacterInstance)->position).x;
  Raziel.constrictData[Raziel.constrictIndex].y = ((Raziel.State.CharacterInstance)->position).y;
  Raziel.constrictIndex = Raziel.constrictIndex + 1;
  if (0x1f < Raziel.constrictIndex) {
    Raziel.constrictIndex = 0;
  }
  uVar1 = Raziel.constrictFlag;
  if (((Raziel.constrictFlag & 4U) != 0) &&
     (uVar1 = Raziel.constrictFlag & 0xffdf, Raziel.constrictWaitIndex == Raziel.constrictIndex)) {
    uVar1 = Raziel.constrictFlag | 0x22;
  }
  Raziel.constrictFlag = uVar1;
  iVar5 = 0;
  if ((Raziel.constrictFlag & 2U) != 0) {
    Raziel.constrictCenter.x = (short)(Raziel.constrictXTotal >> 5);
    Raziel.constrictCenter.y = (short)(Raziel.constrictYTotal >> 5);
    Raziel.constrictCenter.z = ((Raziel.State.CharacterInstance)->position).z + 0x100;
    Raziel.constrictXTotal =
         Raziel.constrictXTotal - (int)Raziel.constrictData[Raziel.constrictIndex].x;
    Raziel.constrictGoodCircle = 1;
    Raziel.constrictYTotal =
         Raziel.constrictYTotal - (int)Raziel.constrictData[Raziel.constrictIndex].y;
    do {
      uVar2 = MATH3D_SquareLength((int)Raziel.constrictData[iVar5].x - (int)Raziel.constrictCenter.x
                                  ,(int)Raziel.constrictData[iVar5].y -
                                   (int)Raziel.constrictCenter.y,0);
      if (0xc7ffe < uVar2 - 1) {
        Raziel.constrictGoodCircle = 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x20);
    if (Raziel.constrictGoodCircle != 0) {
      iVar5 = (int)Raziel.constrictIndex + -1;
      iVar3 = iVar5 * 4;
      if (iVar5 < 0) {
        iVar3 = 0x7c;
      }
      psVar4 = (short *)((int)&(Raziel.constrictData)->x + iVar3);
      uVar2 = MATH3D_SquareLength((int)*psVar4 -
                                  (int)Raziel.constrictData[(int)Raziel.constrictIndex].x,
                                  (int)psVar4[1] -
                                  (int)Raziel.constrictData[(int)Raziel.constrictIndex].y,0);
      if (0x15f900 < uVar2) {
        Raziel.constrictGoodCircle = 0;
      }
      if (Raziel.constrictGoodCircle != 0) {
        Raziel.constrictXTotal = 0;
        Raziel.constrictYTotal = 0;
        Raziel.constrictFlag = Raziel.constrictFlag & 0xfffdU | 0x1c;
        Raziel.constrictWaitIndex = Raziel.constrictIndex;
        if (1 < Raziel.constrictGoodCircle) {
          FX_EndConstrict(1,(_Instance *)0x0);
          Raziel.constrictFlag = 1;
        }
        Raziel.constrictGoodCircle = Raziel.constrictGoodCircle + 1;
        return;
      }
    }
    Raziel.constrictGoodCircle = 1;
    Raziel.constrictFlag = Raziel.constrictFlag & 0xffef;
    FX_EndConstrict(0,(_Instance *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RelocateConstrict(struct _SVector *offset /*$a3*/)
 // line 5440, offset 0x800ad630
	/* begin block 1 */
		// Start line: 5441
		// Start offset: 0x800AD630
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x800AD788
	// End Line: 5469

	/* begin block 2 */
		// Start line: 11535
	/* end block 2 */
	// End Line: 11536

	/* begin block 3 */
		// Start line: 11540
	/* end block 3 */
	// End Line: 11541

void RelocateConstrict(_SVector *offset)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  __FitPoint *p_Var4;
  int iVar5;
  
  Raziel.constrictXTotal = 0;
  Raziel.constrictYTotal = 0;
  if ((Raziel.constrictFlag & 2U) == 0) {
    iVar3 = (int)Raziel.constrictWaitIndex + 1;
    if (iVar3 == 0x20) {
      iVar3 = 0;
    }
    if (iVar3 != (int)Raziel.constrictIndex) {
      do {
        Raziel.constrictData[iVar3].x = Raziel.constrictData[iVar3].x + offset->x;
        Raziel.constrictData[iVar3].y = Raziel.constrictData[iVar3].y + offset->y;
        p_Var4 = Raziel.constrictData + iVar3;
        Raziel.constrictXTotal = Raziel.constrictXTotal + (int)p_Var4->x;
        iVar3 = iVar3 + 1;
        Raziel.constrictYTotal = Raziel.constrictYTotal + (int)p_Var4->y;
        if (iVar3 == 0x20) {
          iVar3 = 0;
        }
      } while (iVar3 != (int)Raziel.constrictIndex);
      return;
    }
  }
  else {
    iVar5 = 0;
    iVar3 = 0;
    do {
      psVar1 = (short *)((int)&(Raziel.constrictData)->x + iVar3);
      *psVar1 = *psVar1 + offset->x;
      iVar2 = (int)&(Raziel.constrictData)->x + iVar3;
      *(short *)(iVar2 + 2) = *(short *)(iVar2 + 2) + offset->y;
      psVar1 = (short *)((int)&(Raziel.constrictData)->x + iVar3);
      Raziel.constrictXTotal = Raziel.constrictXTotal + (int)*psVar1;
      iVar5 = iVar5 + 1;
      Raziel.constrictYTotal = Raziel.constrictYTotal + (int)psVar1[1];
      iVar3 = iVar5 * 4;
    } while (iVar5 < 0x20);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessEffects(struct _Instance *instance /*$s1*/)
 // line 5469, offset 0x800ad790
	/* begin block 1 */
		// Start line: 5470
		// Start offset: 0x800AD790
		// Variables:
	// 		struct _Instance *heldInst; // $s0

		/* begin block 1.1 */
			// Start line: 5484
			// Start offset: 0x800AD7FC
			// Variables:
		// 		int step; // $v1
		/* end block 1.1 */
		// End offset: 0x800AD8CC
		// End Line: 5521
	/* end block 1 */
	// End offset: 0x800AD8CC
	// End Line: 5523

	/* begin block 2 */
		// Start line: 11611
	/* end block 2 */
	// End Line: 11612

void ProcessEffects(_Instance *instance)

{
  uint uVar1;
  _Instance *Inst;
  ulong uVar2;
  int iVar3;
  int iVar4;
  
  Inst = razGetHeldItem();
  if (((Raziel.padCommands.Queue[0].ID & 2U) != 0) &&
     (instance = Raziel._1132_4_, Raziel._1132_4_ == (_Instance *)0x0)) {
    if (Inst == (_Instance *)0x0) {
      return;
    }
    uVar2 = INSTANCE_Query(Inst,1);
    instance = Inst;
    if ((uVar2 & 0x20) == 0) {
      return;
    }
  }
  if ((Raziel.padCommands.Queue[0].ID & 1U) == 0) {
    return;
  }
  Raziel.padCommands.Queue[1].Data =
       Raziel.padCommands.Queue[1].Data + Raziel.padCommands.Queue[1].ID * gameTrackerX.idleTime;
  iVar4 = Raziel.padCommands.Queue[1].Data;
  if (Raziel.padCommands.Queue[1].Data < 0) {
    iVar4 = Raziel.padCommands.Queue[1].Data + 0xfff;
  }
  iVar4 = iVar4 >> 0xc;
  iVar3 = (uint)(ushort)instance->fadeValue + iVar4;
  instance->fadeValue = (short)iVar3;
  uVar1 = Raziel.padCommands.Queue[0].ID;
  if (iVar4 < 1) {
    if ((-1 < iVar4) || ((int)Raziel.padCommands.Queue[0].Data._2_2_ <= iVar3 * 0x10000 >> 0x10))
    goto LAB_800ad8b0;
    instance->fadeValue = Raziel.padCommands.Queue[0].Data._2_2_;
  }
  else {
    if (iVar3 * 0x10000 >> 0x10 <= (int)Raziel.padCommands.Queue[0].Data._2_2_) goto LAB_800ad8b0;
    instance->fadeValue = Raziel.padCommands.Queue[0].Data._2_2_;
  }
  uVar1 = Raziel.padCommands.Queue[0].ID & 0xfffffffe;
  if (instance == Raziel._1132_4_) {
    Raziel._1132_4_ = (_Instance *)0x0;
    uVar1 = Raziel.padCommands.Queue[0].ID & 0xfffffffc;
  }
LAB_800ad8b0:
  Raziel.padCommands.Queue[0].ID = uVar1;
  if (Raziel._1132_4_ != (_Instance *)0x0) {
    (Raziel._1132_4_)->fadeValue = instance->fadeValue;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessInteractiveMusic(struct _Instance *instance /*$a0*/)
 // line 5528, offset 0x800ad8e0
	/* begin block 1 */
		// Start line: 5529
		// Start offset: 0x800AD8E0
		// Variables:
	// 		struct Level *level; // $s1

		/* begin block 1.1 */
			// Start line: 5545
			// Start offset: 0x800AD97C
		/* end block 1.1 */
		// End offset: 0x800AD9A0
		// End Line: 5552
	/* end block 1 */
	// End offset: 0x800ADA6C
	// End Line: 5601

	/* begin block 2 */
		// Start line: 11734
	/* end block 2 */
	// End Line: 11735

void ProcessInteractiveMusic(_Instance *instance)

{
  Level *pLVar1;
  uint uVar2;
  int modifier;
  
  pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  SetInteractiveMusic(6,pLVar1->unitFlags & 2);
  SetInteractiveMusic(9,pLVar1->unitFlags & 0x200);
  SetInteractiveMusic(10,pLVar1->unitFlags & 0x100);
  SetInteractiveMusic(7,pLVar1->unitFlags & 0x40);
  SetInteractiveMusic(8,pLVar1->unitFlags & 0x80);
  SetInteractiveMusic(0xb,pLVar1->unitFlags & 0x400);
  if (((pLVar1->unitFlags & 2U) != 0) && ((pLVar1->unitFlags & 0xc0U) == 0)) {
    uVar2 = GAMELOOP_GetTimeOfDay();
    SetInteractiveMusic(7,(uint)((uVar2 ^ 0x76c) != 0));
    SetInteractiveMusic(8,(uint)((uVar2 ^ 0x76c) == 0));
  }
  SetInteractiveMusic(0xc,(uint)(Raziel.CurrentPlane == 2));
  SetInteractiveMusic(5,Raziel.Mode & 0x40000);
  uVar2 = pLVar1->unitFlags;
  if (((uVar2 & 0x10) == 0) && ((Raziel.Mode & 0x2000000U) == 0)) {
    if (((uVar2 & 8) == 0) && ((Raziel.Senses.Flags & 0x20U) == 0)) {
      if ((uVar2 & 4) == 0) {
        modifier = 4;
        if ((uVar2 & 0x20) == 0) {
          Raziel.padCommands.Queue[7].Data = Raziel.padCommands.Queue[7].Data & 0xffffffe1;
          SOUND_SetMusicModifier(0);
          return;
        }
      }
      else {
        modifier = 1;
      }
    }
    else {
      modifier = 2;
    }
  }
  else {
    modifier = 3;
  }
  Raziel.padCommands.Queue[7].Data = Raziel.padCommands.Queue[7].Data & 0xffffffe1;
  SetInteractiveMusic(modifier,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessTimers(struct _Instance *instance /*$a0*/)
 // line 5605, offset 0x800ada80
	/* begin block 1 */
		// Start line: 11888
	/* end block 1 */
	// End Line: 11889

	/* begin block 2 */
		// Start line: 11889
	/* end block 2 */
	// End Line: 11890

void ProcessTimers(_Instance *instance)

{
  if (0 < Raziel.padCommands.Queue[5].Data) {
    Raziel.padCommands.Queue[5].Data = Raziel.padCommands.Queue[5].Data - gameTrackerX.idleTime;
    if (Raziel.padCommands.Queue[5].Data < 1) {
      INSTANCE_Post(instance,0x100015,-Raziel.padCommands.Queue[5].Data);
      Raziel.padCommands.Queue[5].Data = 0;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetTimer(int ticks /*$a0*/)
 // line 5618, offset 0x800adac8
	/* begin block 1 */
		// Start line: 11915
	/* end block 1 */
	// End Line: 11916

	/* begin block 2 */
		// Start line: 11916
	/* end block 2 */
	// End Line: 11917

void SetTimer(int ticks)

{
  Raziel.padCommands.Queue[5].Data = ticks << 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetInteractiveMusic(int modifier /*$a0*/, int action /*$a1*/)
 // line 5625, offset 0x800adad8
	/* begin block 1 */
		// Start line: 5626
		// Start offset: 0x800ADAD8
		// Variables:
	// 		int soundFlag; // $s0
	/* end block 1 */
	// End offset: 0x800ADB44
	// End Line: 5647

	/* begin block 2 */
		// Start line: 11929
	/* end block 2 */
	// End Line: 11930

void SetInteractiveMusic(int modifier,int action)

{
  uint uVar1;
  
  uVar1 = 1 << (modifier & 0x1fU);
  if (action == 0) {
    if ((Raziel.padCommands.Queue[7].Data & uVar1) != 0) {
      SOUND_ResetMusicModifier(modifier);
    }
    Raziel.padCommands.Queue[7].Data = Raziel.padCommands.Queue[7].Data & ~uVar1;
  }
  else {
    if ((Raziel.padCommands.Queue[7].Data & uVar1) == 0) {
      SOUND_SetMusicModifier(modifier);
    }
    Raziel.padCommands.Queue[7].Data = Raziel.padCommands.Queue[7].Data | uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessSpecialAbilities(struct _Instance *instance /*$s1*/)
 // line 5652, offset 0x800adb54
	/* begin block 1 */
		// Start line: 5653
		// Start offset: 0x800ADB54
		// Variables:
	// 		unsigned long reaver; // $s0

		/* begin block 1.1 */
			// Start line: 5660
			// Start offset: 0x800ADB84
			// Variables:
		// 		unsigned long temp; // $a0
		/* end block 1.1 */
		// End offset: 0x800ADBA4
		// End Line: 5669

		/* begin block 1.2 */
			// Start line: 5693
			// Start offset: 0x800ADBE8
			// Variables:
		// 		struct Object *soulReaverOb; // $a1

			/* begin block 1.2.1 */
				// Start line: 5697
				// Start offset: 0x800ADBF8
				// Variables:
			// 		struct _Instance *iSoulReaver; // $s0
			/* end block 1.2.1 */
			// End offset: 0x800ADC18
			// End Line: 5702
		/* end block 1.2 */
		// End offset: 0x800ADC34
		// End Line: 5706

		/* begin block 1.3 */
			// Start line: 5718
			// Start offset: 0x800ADC7C
			// Variables:
		// 		struct Level *level; // $a1
		/* end block 1.3 */
		// End offset: 0x800ADCE0
		// End Line: 5729
	/* end block 1 */
	// End offset: 0x800ADD20
	// End Line: 5748

	/* begin block 2 */
		// Start line: 11989
	/* end block 2 */
	// End Line: 11990

	/* begin block 3 */
		// Start line: 11993
	/* end block 3 */
	// End Line: 11994

/* WARNING: Removing unreachable block (ram,0x800adbf8) */
/* WARNING: Removing unreachable block (ram,0x800adc0c) */
/* WARNING: Removing unreachable block (ram,0x800adc1c) */

void ProcessSpecialAbilities(_Instance *instance)

{
  bool bVar1;
  ulong Data;
  Level *pLVar2;
  uint reaverMask;
  
  if ((Raziel.Abilities & 8U) == 0) {
    if (Raziel.soulReaver != (_Instance *)0x0) {
      INSTANCE_UnlinkFromParent(Raziel.soulReaver);
      INSTANCE_KillInstance(Raziel.soulReaver);
      Raziel.soulReaver = (_Instance *)0x0;
      Raziel.currentSoulReaver = 0;
      debugRazielFlags2 = 0;
    }
  }
  else {
    if (debugRazielFlags2 == 0) {
      Data = 1;
      if (Raziel.CurrentPlane == 1) {
        Data = 2;
        debugRazielFlags2 = 0x800;
      }
      else {
        debugRazielFlags2 = 0x400;
      }
    }
    else {
      reaverMask = 1 << (Raziel.currentSoulReaver + 9 & 0x1f);
      if (reaverMask != debugRazielFlags2) {
        reaverMask = debugRazielFlags2 & ~reaverMask;
        debugRazielFlags2 = reaverMask;
      }
      Data = razGetReaverFromMask(reaverMask);
    }
    if (Raziel.soulReaver == (_Instance *)0x0) {
      GXFilePrint("soul reaver not loaded!\n");
    }
    else {
      if (Raziel.currentSoulReaver == Data) {
        if (Data == 6) {
          pLVar2 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
          if (instance->waterFace == (_TFace *)0x0) {
            if (instance->matrix == (MATRIX *)0x0) {
              return;
            }
            bVar1 = instance->matrix[0x29].t[2] < pLVar2->waterZLevel;
          }
          else {
            if (instance->matrix == (MATRIX *)0x0) {
              return;
            }
            bVar1 = instance->matrix[0x29].t[2] < (int)(instance->splitPoint).z;
          }
          if (bVar1) {
            razReaverImbue(2);
          }
        }
      }
      else {
        INSTANCE_Post(Raziel.soulReaver,0x800103,Data);
        Raziel.currentSoulReaver = Data;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetControllerMessages(long *controlCommand /*$a0*/)
 // line 5782, offset 0x800add34
	/* begin block 1 */
		// Start line: 5785
		// Start offset: 0x800ADD34
		// Variables:
	// 		int Event; // $v1
	/* end block 1 */
	// End offset: 0x800ADE84
	// End Line: 5842

	/* begin block 2 */
		// Start line: 12253
	/* end block 2 */
	// End Line: 12254

	/* begin block 3 */
		// Start line: 12255
	/* end block 3 */
	// End Line: 12256

	/* begin block 4 */
		// Start line: 12257
	/* end block 4 */
	// End Line: 12258

int GetControllerMessages(long *controlCommand)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = controlCommand[1];
  if ((uVar3 & 0x20) == 0) {
    uVar2 = controlCommand[2];
    puVar1 = (undefined *)0x20000000;
    if ((uVar2 & 0x20) == 0) {
      if ((uVar3 & 0x40) == 0) {
        if ((uVar2 & 0x40) == 0) {
          if ((uVar3 & 0x80) == 0) {
            if ((uVar2 & 0x80) == 0) {
              if ((uVar3 & 0x200) == 0) {
                if ((uVar2 & 0x200) == 0) {
                  if ((uVar3 & 0x100) == 0) {
                    if ((uVar2 & 0x100) == 0) {
                      if ((controlCommand[1] & 0x8000) == 0) {
                        uVar3 = 0x80000000;
                        if ((controlCommand[1] & 0x10) == 0) {
                          if ((controlCommand[2] & 0x10) == 0) {
                            return 0;
                          }
                          uVar3 = 0x20000000;
                        }
                        puVar1 = (undefined *)(uVar3 | 0x20);
                      }
                      else {
                        puVar1 = &DAT_80000010;
                      }
                    }
                    else {
                      puVar1 = (undefined *)0x20000008;
                    }
                  }
                  else {
                    puVar1 = &DAT_80000008;
                  }
                }
                else {
                  puVar1 = (undefined *)0x20000004;
                }
              }
              else {
                puVar1 = &DAT_80000004;
              }
            }
            else {
              puVar1 = (undefined *)0x20000001;
            }
          }
          else {
            puVar1 = (undefined *)0x80000001;
          }
        }
        else {
          puVar1 = (undefined *)0x20000002;
        }
      }
      else {
        puVar1 = &DAT_80000002;
      }
    }
  }
  else {
    puVar1 = (undefined *)0x80000000;
  }
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielAdditionalCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 5867, offset 0x800ade8c
	/* begin block 1 */
		// Start line: 5868
		// Start offset: 0x800ADE8C
		// Variables:
	// 		int rc; // $s0
	// 		int Mode; // $s1
	// 		short Height; // $a1

		/* begin block 1.1 */
			// Start line: 5898
			// Start offset: 0x800ADF04
		/* end block 1.1 */
		// End offset: 0x800ADFA0
		// End Line: 5916

		/* begin block 1.2 */
			// Start line: 5920
			// Start offset: 0x800ADFC4
			// Variables:
		// 		struct evPhysicsEdgeData *Data; // $s1
		/* end block 1.2 */
		// End offset: 0x800AE0DC
		// End Line: 5953

		/* begin block 1.3 */
			// Start line: 5971
			// Start offset: 0x800AE0F0
		/* end block 1.3 */
		// End offset: 0x800AE0F0
		// End Line: 5975
	/* end block 1 */
	// End offset: 0x800AE358
	// End Line: 6076

	/* begin block 2 */
		// Start line: 12423
	/* end block 2 */
	// End Line: 12424

	/* begin block 3 */
		// Start line: 12428
	/* end block 3 */
	// End Line: 12429

void RazielAdditionalCollide(_Instance *instance,GameTracker *gameTracker)

{
  short *psVar1;
  uint uVar2;
  int Data;
  evPhysicsEdgeData *Data_00;
  short sVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar2 = ControlFlag & 8;
  if ((ControlFlag & 0x2000U) != 0) {
    Data = SetPhysicsDropOffData(0,-0x60,(int)Raziel.dropOffHeight,(int)(short)Raziel.slipSlope);
    PhysicsCheckDropOff(instance,Data,2);
  }
  if (uVar2 != 0) {
    sVar3 = 0x40;
    if (0x40 < (int)(instance->oldPos).z - (int)(instance->position).z) {
      sVar3 = (instance->oldPos).z - (instance->position).z;
    }
    Data = SetPhysicsGravityData
                     ((int)*(short *)(instance->matrix[1].t + 2) - instance->matrix->t[2],(int)sVar3
                      ,0,0,0,(int)(short)Raziel.slipSlope);
    uVar4 = PhysicsCheckGravity(instance,Data,7);
    if ((uVar4 & 1) == 0) {
      Raziel.Senses.Flags = Raziel.Senses.Flags & 0xfffffffb;
    }
    else {
      Raziel.Senses.Flags = Raziel.Senses.Flags | 4;
    }
    FX_UpdateInstanceWaterSplit(instance);
  }
  if (((ControlFlag & 0x400U) != 0) && (Raziel.Senses.heldClass != 3)) {
    Data_00 = (evPhysicsEdgeData *)
              SetPhysicsEdgeData(400,-0x100,0x90,0,-0xc4,0x1f2,&Raziel.Senses.ForwardNormal,
                                 &Raziel.Senses.AboveNormal,&Raziel.Senses.Delta);
    uVar4 = PhysicsCheckEdgeGrabbing(instance,gameTracker,(int)Data_00,3);
    if ((uVar4 & 6) == 6) {
      SetPhysics(instance,0,0,0,0);
      Raziel.Senses.Flags = Raziel.Senses.Flags | 2;
      if (ExtraRot != (_G2SVector3_Type *)0x0) {
        G2Anim_DisableController(&instance->anim,1,0xe);
        psVar1 = &ExtraRot->z;
        ExtraRot = (_G2SVector3_Type *)0x0;
        (instance->rotation).z = (instance->rotation).z + *psVar1;
      }
      if (Data_00 != (evPhysicsEdgeData *)0x0) {
        PhysicsDefaultEdgeGrabResponse(instance,Data_00,0);
      }
    }
    else {
      Raziel.Senses.Flags = Raziel.Senses.Flags & 0xfffffffd;
    }
    if ((uVar4 & 2) == 0) {
      Raziel.Senses.Flags = Raziel.Senses.Flags & 0xfffffffe;
    }
    else {
      Raziel.Senses.Flags = Raziel.Senses.Flags | 1;
    }
  }
  if ((ControlFlag & 0x100U) == 0) {
    WaterStatus = 0x20;
    FX_UpdateInstanceWaterSplit(instance);
  }
  else {
    Data = SetPhysicsSwimData((uint)Raziel.Mode >> 0x12 & 1,&Raziel.iVelocity,0x100,0x1a0,0x70);
    WaterStatus = PhysicsCheckSwim(instance,Data,3);
  }
  if ((ControlFlag & 0x800U) != 0) {
    if (Raziel.Mode != 0x100) {
      Data = SetPhysicsEdgeData(0,-0x100,0x140,0,-0xc4,0x1f2,&Raziel.Senses.ForwardNormal,
                                &Raziel.Senses.AboveNormal,&Raziel.Senses.Delta);
      uVar4 = PhysicsCheckPullOutOfWater(instance,gameTracker,Data,7);
    }
    if ((uVar4 & 4) == 0) {
      uVar2 = Raziel.Senses.Flags & 0xfffffffd;
    }
    else {
      SetPhysics(instance,0,0,0,0);
      uVar2 = Raziel.Senses.Flags | 2;
    }
    if ((uVar4 & 2) == 0) {
      Raziel.Senses.Flags = uVar2 & 0xfffffffe;
    }
    else {
      Raziel.Senses.Flags = uVar2 | 1;
    }
  }
  if ((ControlFlag & 0x8000U) != 0) {
    Data = SetPhysicsEdgeData(0x100,-0x100,0x50,0,-0x68,0,&Raziel.Senses.ForwardNormal,
                              &Raziel.Senses.AboveNormal,&Raziel.Senses.Delta);
    uVar2 = PhysicsCheckBlockers(instance,gameTracker,Data,3);
    if ((uVar2 & 4) == 0) {
      uVar4 = Raziel.Senses.Flags & 0xfffffffd;
    }
    else {
      uVar4 = Raziel.Senses.Flags | 2;
    }
    if ((uVar2 & 2) == 0) {
      Raziel.Senses.Flags = uVar4 & 0xfffffffe;
    }
    else {
      Raziel.Senses.Flags = uVar4 | 1;
    }
  }
  if ((ControlFlag & 0x80000U) != 0) {
    Data = SetPhysicsWallCrawlData(0,-0x1c0,0xa0,-0x80);
    PhysicsFollowWall(instance,gameTracker,Data,7);
  }
  if (((ControlFlag & 0x4000000U) != 0) && (Raziel.attachedPlatform != (_Instance *)0x0)) {
    Data = SetPhysicsLinkedMoveData(Raziel.attachedPlatform,0,(_SVector *)0x0,(_SVector *)0x0);
    PhysicsCheckLinkedMove(instance,Data,5);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetEngageEvent(struct _Instance *instance /*$a0*/)
 // line 6077, offset 0x800ae374
	/* begin block 1 */
		// Start line: 6078
		// Start offset: 0x800AE374
		// Variables:
	// 		int Ability; // $v1
	/* end block 1 */
	// End offset: 0x800AE3BC
	// End Line: 6096

	/* begin block 2 */
		// Start line: 12857
	/* end block 2 */
	// End Line: 12858

int GetEngageEvent(_Instance *instance)

{
  ulong uVar1;
  
  if (instance != (_Instance *)0x0) {
    uVar1 = INSTANCE_Query(instance,2);
    if ((uVar1 & 8) != 0) {
      return 0x2000000;
    }
    if ((uVar1 & 1) != 0) {
      return 0x2000001;
    }
    if ((uVar1 & 2) != 0) {
      return 0x2000004;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetupReaction(struct _Instance *player /*$s2*/, struct _Instance *instance /*$a0*/)
 // line 6099, offset 0x800ae3cc
	/* begin block 1 */
		// Start line: 6100
		// Start offset: 0x800AE3CC
		// Variables:
	// 		int FaceAngle; // $s3

		/* begin block 1.1 */
			// Start line: 6116
			// Start offset: 0x800AE410
		/* end block 1.1 */
		// End offset: 0x800AE4A4
		// End Line: 6125
	/* end block 1 */
	// End offset: 0x800AE4A4
	// End Line: 6126

	/* begin block 2 */
		// Start line: 12901
	/* end block 2 */
	// End Line: 12902

int SetupReaction(_Instance *player,_Instance *instance)

{
  short sVar1;
  int Data;
  evPhysicsEdgeData *Data_00;
  
  player->yVel = 0;
  player->xVel = 0;
  *(_Instance **)&player->work3 = instance;
  Data = GetEngageEvent(instance);
  sVar1 = (player->position).z;
  if (Data != 0x2000001) {
    Data = SetPhysicsEdgeData(400,-0x100,0x90,0,-0xc4,0x1f2,&Raziel.Senses.ForwardNormal,
                              &Raziel.Senses.AboveNormal,&Raziel.Senses.Delta);
    PhysicsCheckEdgeGrabbing(player,gameTracker,Data,1);
    Data_00 = (evPhysicsEdgeData *)
              SetPhysicsEdgeData(0,0,0,0,-0x8d,0,&Raziel.Senses.ForwardNormal,(_SVector *)0x0,
                                 &Raziel.Senses.Delta);
    PhysicsDefaultEdgeGrabResponse(player,Data_00,1);
  }
  (player->position).z = sVar1;
  return (int)sVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckHolding(struct _Instance *instance /*$a0*/)
 // line 6152, offset 0x800ae4c8
	/* begin block 1 */
		// Start line: 13010
	/* end block 1 */
	// End Line: 13011

	/* begin block 2 */
		// Start line: 13011
	/* end block 2 */
	// End Line: 13012

int CheckHolding(_Instance *instance)

{
  return (uint)(instance->LinkChild != (_Instance *)0x0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DisableWristCollision(struct _Instance *instance /*$s1*/, int Side /*$s0*/)
 // line 6158, offset 0x800ae4d4
	/* begin block 1 */
		// Start line: 13022
	/* end block 1 */
	// End Line: 13023

void DisableWristCollision(_Instance *instance,int Side)

{
  if ((Side & 1U) != 0) {
    COLLIDE_SegmentCollisionOff(instance,0x1f);
  }
  if ((Side & 2U) != 0) {
    COLLIDE_SegmentCollisionOff(instance,0x29);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EnableWristCollision(struct _Instance *instance /*$s1*/, int Side /*$s0*/)
 // line 6167, offset 0x800ae524
	/* begin block 1 */
		// Start line: 13040
	/* end block 1 */
	// End Line: 13041

void EnableWristCollision(_Instance *instance,int Side)

{
  if ((Side & 1U) != 0) {
    COLLIDE_SegmentCollisionOn(instance,0x1f);
  }
  if ((Side & 2U) != 0) {
    COLLIDE_SegmentCollisionOn(instance,0x29);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetCollisionType(struct _Instance *instance /*$a0*/)
 // line 6304, offset 0x800ae574
	/* begin block 1 */
		// Start line: 6305
		// Start offset: 0x800AE574
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s0
	// 		struct _HSphere *S; // $v0

		/* begin block 1.1 */
			// Start line: 6319
			// Start offset: 0x800AE5B0
			// Variables:
		// 		struct _Instance *inst; // $v1
		/* end block 1.1 */
		// End offset: 0x800AE5B0
		// End Line: 6319
	/* end block 1 */
	// End offset: 0x800AE6C4
	// End Line: 6360

	/* begin block 2 */
		// Start line: 13314
	/* end block 2 */
	// End Line: 13315

int GetCollisionType(_Instance *instance)

{
  int iVar1;
  _CollideInfo *collideInfo;
  
  collideInfo = (_CollideInfo *)instance->collideInfo;
  if (*(char *)((int)collideInfo->prim0 + 4) == '\t') {
    if (collideInfo->type1 == '\x03') {
      COLLIDE_SetBSPTreeFlag(collideInfo,0x800);
    }
    else {
      *(uint *)((int)collideInfo->inst1 + 0x14) = *(uint *)((int)collideInfo->inst1 + 0x14) | 4;
    }
  }
  if ((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000) {
    if ((ControlFlag & 0x1000U) == 0) {
      if ((*(char *)((int)collideInfo->prim0 + 4) != '\t') ||
         (*(char *)((int)collideInfo->prim1 + 4) != '\b')) goto LAB_800ae67c;
      if (Raziel.Senses.HitMonster == (_Instance *)0x0) {
        Raziel.Senses.HitMonster = (_Instance *)collideInfo->inst1;
        return 1;
      }
      if (Raziel.Senses.HitMonster != (_Instance *)collideInfo->inst1) {
        printf("MultiHit\n");
        return 1;
      }
    }
    iVar1 = 1;
  }
  else {
LAB_800ae67c:
    if (((collideInfo->type0 == '\x05') ||
        (((collideInfo->type1 == '\x05' || (collideInfo->type0 == '\x02')) ||
         (iVar1 = 0, collideInfo->type1 == '\x02')))) &&
       (iVar1 = 1, (ControlFlag & 0x8000000U) == 0)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitGlyphSystem(struct _Instance *instance /*$a0*/)
 // line 6433, offset 0x800ae6d4
	/* begin block 1 */
		// Start line: 6434
		// Start offset: 0x800AE6D4
		// Variables:
	// 		struct Object *GlyphOb; // $a1

		/* begin block 1.1 */
			// Start line: 6439
			// Start offset: 0x800AE6E8
			// Variables:
		// 		struct _Instance *iGlyph; // $v0
		/* end block 1.1 */
		// End offset: 0x800AE700
		// End Line: 6446
	/* end block 1 */
	// End offset: 0x800AE71C
	// End Line: 6455

	/* begin block 2 */
		// Start line: 13572
	/* end block 2 */
	// End Line: 13573

	/* begin block 3 */
		// Start line: 13575
	/* end block 3 */
	// End Line: 13576

/* WARNING: Removing unreachable block (ram,0x800ae6e8) */
/* WARNING: Removing unreachable block (ram,0x800ae700) */
/* WARNING: Removing unreachable block (ram,0x800ae6f8) */

void InitGlyphSystem(_Instance *instance)

{
  GXFilePrint("Glyph not loaded!\n");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ mdRazielProcess(struct _Instance *playerInstance /*$s0*/, struct GameTracker *gameTracker /*$s2*/, long *controlCommand /*$s1*/)
 // line 6460, offset 0x800ae72c
	/* begin block 1 */
		// Start line: 13629
	/* end block 1 */
	// End Line: 13630

void mdRazielProcess(_Instance *playerInstance,GameTracker *gameTracker,long *controlCommand)

{
  ProcessTimers(playerInstance);
  ProcessRazControl(controlCommand);
  Raziel.padCommands.Queue[12].ID = 0;
  SetStates(playerInstance,gameTracker,controlCommand,-1);
  CAMERA_Control(&theCamera,playerInstance);
  (playerInstance->offset).x = 0;
  (playerInstance->offset).y = 0;
  (playerInstance->offset).z = 0;
  Raziel.padCommands.Queue[10].Data._0_2_ = 0;
  Raziel.padCommands.Queue[10].Data._2_2_ = 0;
  Raziel.padCommands.Queue[11].ID._0_2_ = 0;
  Raziel.Senses.HitMonster = (_Instance *)0x0;
  if (Raziel.GlyphSystem != (_Instance *)0x0) {
    GlyphProcess(Raziel.GlyphSystem,gameTracker);
  }
  Raziel.Abilities = debugRazielFlags1;
  debugRazielFlags1 = debugRazielFlags1 | debugRazielFlags2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielProcess(struct _Instance *playerInstance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 6489, offset 0x800ae7dc
	/* begin block 1 */
		// Start line: 6490
		// Start offset: 0x800AE7DC
	/* end block 1 */
	// End offset: 0x800AE7DC
	// End Line: 6490

	/* begin block 2 */
		// Start line: 13694
	/* end block 2 */
	// End Line: 13695

void RazielProcess(_Instance *playerInstance,GameTracker *gameTracker)

{
  mdRazielProcess(gameTracker->playerInstance,gameTracker,gameTracker->controlCommand);
  DebugProcess(playerInstance,&Raziel);
  Norm.x = 0;
  Norm.y = 0;
  Norm.z = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 6504, offset 0x800ae824
	/* begin block 1 */
		// Start line: 13725
	/* end block 1 */
	// End Line: 13726

void RazielInit(_Instance *instance,GameTracker *gameTracker)

{
  uint uVar1;
  
  instance->data = instance->object->data;
  gameTracker->playerInstance = instance;
  uVar1 = instance->flags;
  instance->intro = (Intro *)0x0;
  instance->zVel = 0;
  instance->zAccl = 0;
  instance->yVel = 0;
  instance->yAccl = 0;
  instance->work0 = 0;
  instance->work1 = 0;
  (instance->offset).x = 0;
  (instance->offset).y = 0;
  (instance->offset).z = 0;
  instance->currentMainState = 0;
  instance->currentSubState = 0;
  instance->matrix = (MATRIX *)0x0;
  instance->maxZVel = 0;
  instance->work3 = 0;
  instance->lightGroup = '\0';
  instance->flags = uVar1 & 0xfffffeff | 0x480;
  instance->flags2 = instance->flags2 | 0x84;
  OBTABLE_GetInstanceCollideFunc(instance);
  OBTABLE_GetInstanceProcessFunc(instance);
  DisableWristCollision(instance,2);
  DisableWristCollision(instance,1);
  razInitCollision(instance);
  InitStates(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielCollide(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 6580, offset 0x800ae8f4
	/* begin block 1 */
		// Start line: 6581
		// Start offset: 0x800AE8F4
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s1

		/* begin block 1.1 */
			// Start line: 6609
			// Start offset: 0x800AE998
			// Variables:
		// 		struct SVECTOR *offset; // $a1
		/* end block 1.1 */
		// End offset: 0x800AEA2C
		// End Line: 6622

		/* begin block 1.2 */
			// Start line: 6632
			// Start offset: 0x800AEA8C
			// Variables:
		// 		struct SVECTOR *offset; // $a1
		/* end block 1.2 */
		// End offset: 0x800AEAF4
		// End Line: 6648
	/* end block 1 */
	// End offset: 0x800AEAF4
	// End Line: 6650

	/* begin block 2 */
		// Start line: 13904
	/* end block 2 */
	// End Line: 13905

void RazielCollide(_Instance *instance,GameTracker *gameTracker)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  
  pvVar4 = instance->collideInfo;
  iVar2 = GetCollisionType(instance);
  if (iVar2 == 1) {
    return;
  }
  cVar1 = *(char *)((int)pvVar4 + 7);
  if (cVar1 == '\x01') {
    if ((**(uint **)((int)pvVar4 + 0xc) & 0x2000) == 0) {
      return;
    }
    pvVar3 = instance->collideInfo;
    *(undefined2 *)((int)pvVar3 + 0x2c) = 0;
    (instance->offset).x = (instance->offset).x + *(short *)((int)pvVar3 + 0x28);
    (instance->offset).y = (instance->offset).y + *(short *)((int)pvVar3 + 0x2a);
    (instance->position).x = (instance->position).x + *(short *)((int)pvVar3 + 0x28);
    (instance->position).y = (instance->position).y + *(short *)((int)pvVar3 + 0x2a);
  }
  else {
    if ((*(char *)((int)pvVar4 + 6) != '\x04') && (*(char *)((int)pvVar4 + 6) != '\x01')) {
      return;
    }
    if ((((cVar1 != '\x03') || ((*(byte *)(*(int *)((int)pvVar4 + 0xc) + 6) & 8) != 0)) &&
        ((cVar1 != '\x05' || ((**(ushort **)((int)pvVar4 + 0xc) & 0x2000) == 0)))) &&
       (cVar1 != '\x02')) {
      return;
    }
    pvVar3 = instance->collideInfo;
    if ((*(uint *)((int)pvVar4 + 4) & 10) == 0) {
      Raziel.padCommands.Queue[10].Data._0_2_ =
           (short)Raziel.padCommands.Queue[10].Data + *(short *)((int)pvVar3 + 0x28);
      Raziel.padCommands.Queue[10].Data._2_2_ =
           Raziel.padCommands.Queue[10].Data._2_2_ + *(short *)((int)pvVar3 + 0x2a);
      Raziel.padCommands.Queue[11].ID._0_2_ =
           (short)Raziel.padCommands.Queue[11].ID + *(short *)((int)pvVar3 + 0x2c);
      return;
    }
    (instance->offset).x = (instance->offset).x + *(short *)((int)pvVar3 + 0x28);
    (instance->offset).y = (instance->offset).y + *(short *)((int)pvVar3 + 0x2a);
    (instance->offset).z = (instance->offset).z + *(short *)((int)pvVar3 + 0x2c);
    (instance->position).x = (instance->position).x + *(short *)((int)pvVar3 + 0x28);
    (instance->position).y = (instance->position).y + *(short *)((int)pvVar3 + 0x2a);
    (instance->position).z = (instance->position).z + *(short *)((int)pvVar3 + 0x2c);
  }
  COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)((int)pvVar4 + 0x28));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_TurnHead(struct _Instance *instance /*$s2*/, short *rotx /*$s0*/, short *rotz /*$s1*/, struct GameTracker *gameTracker /*$a3*/)
 // line 6650, offset 0x800aeb08
	/* begin block 1 */
		// Start line: 6651
		// Start offset: 0x800AEB08

		/* begin block 1.1 */
			// Start line: 6655
			// Start offset: 0x800AEB4C
			// Variables:
		// 		struct _Rotation rot; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x800AEC30
		// End Line: 6677

		/* begin block 1.2 */
			// Start line: 6680
			// Start offset: 0x800AEC58
			// Variables:
		// 		struct evActionLookAroundData data; // stack offset -32
		/* end block 1.2 */
		// End offset: 0x800AED18
		// End Line: 6698
	/* end block 1 */
	// End offset: 0x800AED18
	// End Line: 6700

	/* begin block 2 */
		// Start line: 14054
	/* end block 2 */
	// End Line: 14055

void RAZIEL_TurnHead(_Instance *instance,short *rotx,short *rotz,GameTracker *gameTracker)

{
  long lVar1;
  ushort uVar2;
  _Rotation local_28;
  evActionLookAroundData local_20;
  
  if (((Raziel.Mode & 0x20000U) == 0) || (((uint)Raziel.throwData & 4) != 0)) {
    lVar1 = gameTrackerX.controlData[0][4];
    if (gameTrackerX.controlData[0][4] < 0) {
      lVar1 = gameTrackerX.controlData[0][4] + 3;
    }
    *rotx = *rotx + (short)(lVar1 >> 2);
    *rotz = *rotz - ((short)((ulonglong)((longlong)gameTrackerX.controlData[0][3] * 0x55555556) >>
                            0x20) - (short)(gameTrackerX.controlData[0][3] >> 0x1f));
    uVar2 = *rotx & 0xfff;
    if (0x800 < uVar2) {
      uVar2 = uVar2 | 0xf000;
    }
    *rotx = uVar2;
    uVar2 = *rotz & 0xfff;
    if (0x800 < uVar2) {
      uVar2 = uVar2 | 0xf000;
    }
    *rotz = uVar2;
    local_20.minx = -0x300;
    local_20.maxx = 0x200;
    local_20.minz = -0x400;
    local_20.maxz = 0x400;
    local_20.rotx = rotx;
    local_20.rotz = rotz;
    razRotateUpperBody(instance,&local_20);
  }
  else {
    lVar1 = gameTrackerX.controlData[0][4];
    if (gameTrackerX.controlData[0][4] < 0) {
      lVar1 = gameTrackerX.controlData[0][4] + 7;
    }
    *rotx = *rotx + (short)(lVar1 >> 3);
    *rotz = *rotz - ((short)((ulonglong)((longlong)gameTrackerX.controlData[0][3] * 0x2aaaaaab) >>
                            0x20) - (short)(gameTrackerX.controlData[0][3] >> 0x1f));
    if (((short)Raziel.padCommands.Head != 0) && (*rotx != 0)) {
      *rotx = *rotx - *(short *)&(Raziel.attackedBy)->object;
    }
    local_28.x = (short)Raziel.padCommands.Head + *rotx + -0x1000;
    *rotx = local_28.x;
    local_28.y = 0;
    local_28.z = *rotz;
    LimitRotation(&local_28);
    *rotx = (local_28.x + 0x1000) - (short)Raziel.padCommands.Head;
    *rotz = local_28.z;
    ThrowSetFocusPoint(instance,&local_28);
    if ((short)Raziel.padCommands.Head != 0) {
      CAMERA_SetLookRot(&theCamera,(int)*rotx + (int)*(short *)&(Raziel.attackedBy)->object,
                        (int)*rotz);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_SetLookAround(struct _Instance *instance /*$s1*/)
 // line 6700, offset 0x800aed30
	/* begin block 1 */
		// Start line: 14174
	/* end block 1 */
	// End Line: 14175

void RAZIEL_SetLookAround(_Instance *instance)

{
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  G2Anim_EnableController(anim,0x11,0xe);
  G2Anim_EnableController(anim,0x10,0xe);
  G2Anim_EnableController(anim,0xe,0xe);
  INSTANCE_Post(instance,0x100009,1);
  Raziel.throwInstance._0_2_ = 0;
  Raziel.throwInstance._2_2_ = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_ResetLookAround(struct _Instance *instance /*$s1*/)
 // line 6729, offset 0x800aeda8
	/* begin block 1 */
		// Start line: 14249
	/* end block 1 */
	// End Line: 14250

void RAZIEL_ResetLookAround(_Instance *instance)

{
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  G2Anim_InterpDisableController(anim,0x11,0xe,300);
  G2Anim_InterpDisableController(anim,0x10,0xe,300);
  G2Anim_InterpDisableController(anim,0xe,0xe,300);
  INSTANCE_Post(instance,0x100009,0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ RAZIEL_OkToLookAround(struct _Instance *playerInstance /*$a0*/)
 // line 6752, offset 0x800aee24
	/* begin block 1 */
		// Start line: 14307
	/* end block 1 */
	// End Line: 14308

	/* begin block 2 */
		// Start line: 14308
	/* end block 2 */
	// End Line: 14309

long RAZIEL_OkToLookAround(_Instance *playerInstance)

{
  if ((((Raziel.State.SectionList[0].Process != StateHandlerIdle) &&
       (Raziel.State.SectionList[0].Process != StateHandlerSwim)) &&
      (Raziel.State.SectionList[0].Process != StateHandlerSwimTread)) &&
     ((Raziel.State.SectionList[0].Process != StateHandlerThrow2 &&
      (Raziel.State.SectionList[0].Process != StateHandlerSoulSuck)))) {
    return 0;
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TrailWaterFX(struct _Instance *instance /*$s2*/, int Segment /*$s0*/, int Bubbles /*$s7*/, int Type /*$s6*/)
 // line 6763, offset 0x800aee78
	/* begin block 1 */
		// Start line: 6764
		// Start offset: 0x800AEE78
		// Variables:
	// 		struct _SVector Pos; // stack offset -88
	// 		struct _SVector Vel; // stack offset -80
	// 		struct _SVector Accl; // stack offset -72
	// 		int i; // $s4
	// 		int j; // $s1
	// 		struct Level *level; // $s5
	// 		struct __BubbleParams BP; // stack offset -64
	/* end block 1 */
	// End offset: 0x800AF1CC
	// End Line: 6810

	/* begin block 2 */
		// Start line: 14329
	/* end block 2 */
	// End Line: 14330

void TrailWaterFX(_Instance *instance,int Segment,int Bubbles,int Type)

{
  Level *pLVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  _SVector local_58;
  _SVector local_50;
  _SVector _Stack72;
  __BubbleParams local_40;
  
  memset(&_Stack72,0,8);
  pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  local_40.DisperseFrames = 5;
  local_40.KillScale = 0x80;
  local_40.MinSplashSize = 0x800;
  local_40.MaxSpeed = 0x18;
  local_40.MaxSpeedRange = 0x18;
  local_40.ScaleRate = 0x20;
  local_40.ScaleRateRange = 0x10;
  local_40.UniqueBubbles = 4;
  if ((instance->matrix != (MATRIX *)0x0) && (iVar5 = 0, instance->oldMatrix != (MATRIX *)0x0)) {
    do {
      local_58.x = *(short *)instance->oldMatrix[Segment].t +
                   (short)(((instance->matrix[Segment].t[0] - instance->oldMatrix[Segment].t[0]) *
                           iVar5) / 2);
      local_58.y = *(short *)(instance->oldMatrix[Segment].t + 1) +
                   (short)(((instance->matrix[Segment].t[1] - instance->oldMatrix[Segment].t[1]) *
                           iVar5) / 2);
      iVar4 = 0;
      local_58.z = *(short *)(instance->oldMatrix[Segment].t + 2) +
                   (short)(((instance->matrix[Segment].t[2] - instance->oldMatrix[Segment].t[2]) *
                           iVar5) / 2);
      if (0 < Bubbles) {
        do {
          iVar2 = rand();
          local_50.x = (local_58.x - *(short *)instance->oldMatrix[Segment].t) +
                       (short)iVar2 + (short)(iVar2 / 0x14) * -0x14 + -10;
          iVar2 = rand();
          local_50.y = (local_58.y - *(short *)(instance->oldMatrix[Segment].t + 1)) +
                       (short)iVar2 + (short)(iVar2 / 0x14) * -0x14 + -10;
          if (Type == 0) {
            iVar2 = rand();
            iVar2 = ((uint)local_58.z - (uint)*(ushort *)(instance->oldMatrix[Segment].t + 2)) +
                    iVar2 % 10;
            local_50.z = (short)iVar2;
            if (iVar2 * 0x10000 < 1) {
              local_50.z = 1;
            }
            local_40.StartScale = 0xc00;
            local_40.StartScaleRange = 0x100;
            _Stack72.z = 0;
LAB_800af19c:
            FX_MakeWaterBubble(&local_58,&local_50,&_Stack72,pLVar1->waterZLevel,&local_40);
          }
          else {
            if (Type == 1) {
              iVar2 = rand();
              local_50.z = (short)iVar2 + (short)(iVar2 / 0x14) * -0x14 + 6;
              iVar3 = rand();
              iVar2 = iVar3;
              if (iVar3 < 0) {
                iVar2 = iVar3 + 3;
              }
              _Stack72.z = (short)iVar3 + (short)(iVar2 >> 2) * -4 + 1;
              local_40.StartScale = 0x1000;
              local_40.StartScaleRange = 0x800;
              goto LAB_800af19c;
            }
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < Bubbles);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
  }
  return;
}





