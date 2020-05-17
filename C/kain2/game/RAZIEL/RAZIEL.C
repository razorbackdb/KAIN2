#include "THISDUST.H"
#include "RAZIEL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitStates(struct _Instance *PlayerInstance /*$s2*/)
 // line 189, offset 0x800a7f54
	/* begin block 1 */
		// Start line: 190
		// Start offset: 0x800A7F54
		// Variables:
	// 		unsigned char i; // $s1

		/* begin block 1.1 */
			// Start line: 219
			// Start offset: 0x800A8000
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.1 */
		// End offset: 0x800A8000
		// End Line: 220
	/* end block 1 */
	// End offset: 0x800A806C
	// End Line: 231

	/* begin block 2 */
		// Start line: 378
	/* end block 2 */
	// End Line: 379

	/* begin block 3 */
		// Start line: 382
	/* end block 3 */
	// End Line: 383

void InitStates(_Instance *PlayerInstance)

{
  _G2AnimSection_Type *p_Var1;
  uint uVar2;
  byte bVar3;
  
  if (Raziel.footPrint == 0) {
    Raziel.footPrint = (int)PlayerInstance->object;
  }
  *(__CharacterState **)&PlayerInstance->InstanceState = &Raziel.State;
  PlayerData = (RazielData *)PlayerInstance->data;
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
  G2AnimSection_SetInterpInfo((PlayerInstance->anim).section,&razInterpInfo);
  G2AnimSection_SetInterpInfo((PlayerInstance->anim).section + 1,&_G2AnimInterpInfo_Type_800d7194);
  G2AnimSection_SetInterpInfo((PlayerInstance->anim).section + 2,&_G2AnimInterpInfo_Type_800d71a0);
  Raziel.Mode = 1;
  gameTrackerX.debugFlags2 = gameTrackerX.debugFlags2 | 0x800;
  InitHealthSystem();
  debugRazielFlags1 = 0x1000000;
  Raziel.GlyphManaBalls = 0;
  Raziel.GlyphManaMax = 0;
  Raziel.Abilities = 0;
  Raziel.RotationSegment = 0;
  Raziel.extraRot.x = 0;
  Raziel.blankPad = 0;
  (PlayerInstance->rotation).y = 0;
  (PlayerInstance->rotation).x = 0;
  Raziel.Senses.EngagedList = &EngagedList;
  Raziel.constrictData = &constrictData;
  Raziel.dropOffHeight = 0x100;
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
  INSTANCE_Post(PlayerInstance,(int)&DAT_00100006,0);
  PlayerInstance->checkMask = 0x803e002e;
  PlayerInstance->flags2 = PlayerInstance->flags2 | 0x400;
  G2EmulationInit();
  InitGlyphSystem(PlayerInstance);
  gameTrackerX.raziel_collide_override = '\0';
  Raziel.slipSlope = 0xb50;
  Raziel.terminator = -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateInitIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Ptr /*$a2*/)
 // line 456, offset 0x800a823c
	/* begin block 1 */
		// Start line: 457
		// Start offset: 0x800A823C
		// Variables:
	// 		struct evControlInitIdleData *data; // $s0
	// 		struct _Instance *linkWeapon; // $a0
	/* end block 1 */
	// End offset: 0x800A84C8
	// End Line: 565

	/* begin block 2 */
		// Start line: 912
	/* end block 2 */
	// End Line: 913

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
    NewAnim = 0x8c;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a84c0;
  }
  if (NewAnim == 3) {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,100,-1,-1);
    if (NewAnim == 0) {
      return;
    }
    NewAnim = 0x8d;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a84c0;
  }
  if (NewAnim == 4) {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x68,-1,-1);
    if (NewAnim == 0) {
      return;
    }
    NewAnim = 0x8e;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a84c0;
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
LAB_800a84b0:
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
        NewAnim = 0x7e;
      }
      goto LAB_800a84b0;
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
        goto LAB_800a84b0;
      }
      CurrentSection = 1;
      NewAnim = 0x7f;
      local_18 = ((int *)Ptr)[2];
    }
    else {
      if (Raziel.Senses.heldClass == 3) {
        CurrentSection = 1;
        NewAnim = 0x62;
        goto LAB_800a84b0;
      }
      if (Raziel.Senses.heldClass != 0x1000) {
        return;
      }
      if (*(int *)Ptr == 0) {
        G2EmulationSwitchAnimation(In,1,0x75,0,((int *)Ptr)[2],2);
        razReaverScale(0xaf0);
        return;
      }
      CurrentSection = 1;
      NewAnim = 0x89;
      local_18 = ((int *)Ptr)[2];
    }
  }
  local_14 = 2;
LAB_800a84c0:
  G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,local_18,local_14);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
 // line 614, offset 0x800a84e0
	/* begin block 1 */
		// Start line: 615
		// Start offset: 0x800A84E0
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s5
	// 		int blockForwardMotion; // $s7

		/* begin block 1.1 */
			// Start line: 767
			// Start offset: 0x800A8AF4
			// Variables:
		// 		struct _Instance *heldInst; // $v0
		/* end block 1.1 */
		// End offset: 0x800A8B1C
		// End Line: 773

		/* begin block 1.2 */
			// Start line: 811
			// Start offset: 0x800A8BB8
			// Variables:
		// 		struct evPhysicsEdgeData *EdgeData; // $v0
		/* end block 1.2 */
		// End offset: 0x800A8C10
		// End Line: 818
	/* end block 1 */
	// End offset: 0x800A8D70
	// End Line: 875

	/* begin block 2 */
		// Start line: 1228
	/* end block 2 */
	// End Line: 1229

void StateHandlerIdle(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  int iVar2;
  __Event *p_Var3;
  _Instance *Inst;
  int Ptr;
  ulong uVar4;
  undefined *puVar5;
  code *NewProcess;
  _Instance **pp_Var6;
  int Mode;
  
  bVar1 = false;
  ControlFlag = ControlFlag & 0xffffffef;
  G2EmulationQueryFrame(In,CurrentSection);
  iVar2 = G2EmulationQueryAnimation(In,CurrentSection);
  pp_Var6 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var3 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var3 == (__Event *)0x0) {
      if (((((CurrentSection == 0) && (Ptr = CheckHolding(In->CharacterInstance), Ptr == 0)) &&
           (iVar2 != 0x37)) &&
          ((iVar2 != 0xd6 && (Raziel.idleCount = Raziel.idleCount + 1, 300 < Raziel.idleCount)))) &&
         (Raziel.idleCount == (Raziel.idleCount / 900) * 900)) {
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
    puVar5 = (undefined *)p_Var3->ID;
    if (puVar5 == (undefined *)0x2000000) {
      if (((Raziel.Senses.EngagedMask & 1) == 0) || (Raziel.Senses.heldClass == 3)) {
        if (((Raziel.Senses.EngagedMask & 8) == 0) || (Raziel.Senses.heldClass == 3)) {
          if ((Raziel.Senses.EngagedMask & 0x2010) == 0) {
            if ((Raziel.Senses.EngagedMask & 0x800) == 0) {
              if ((Raziel.Senses.EngagedMask & 0x4000) == 0) {
                Ptr = razPickupAndGrab(In,CurrentSection);
                if (((Ptr != 0) && (CurrentSection == 0)) && ((Raziel.Senses.Flags & 0x80U) == 0)) {
                  NewProcess = StateHandlerAttack2;
                  goto LAB_800a8c68;
                }
              }
              else {
                if (CurrentSection == 0) {
                  NewProcess = StateHandlerWarpGate;
                  goto LAB_800a8c68;
                }
              }
            }
            else {
              if (CurrentSection == 1) {
                razReaverPickup(In->CharacterInstance,Raziel.Senses.EngagedList[0xb].instance);
              }
            }
          }
          else {
            if (CurrentSection == 0) {
              if (Raziel.Senses.heldClass == 3) {
                Inst = razGetHeldItem();
                if ((Inst == (_Instance *)0x0) ||
                   (uVar4 = INSTANCE_Query(Inst,2), (uVar4 & 0x20) == 0)) goto LAB_800a8c88;
                NewProcess = StateHandlerBreakOff;
              }
              else {
                NewProcess = StateHandlerBreakOff;
              }
LAB_800a8c68:
              StateSwitchStateCharacterData(In,NewProcess,0);
            }
          }
        }
        else {
          if (CurrentSection == 0) {
            NewProcess = StateHandlerPullSwitch;
            goto LAB_800a8c68;
          }
        }
      }
      else {
        Raziel.Mode = 0x200;
        pp_Var6[0x47] = (_Instance *)0x0;
        if (CurrentSection == 0) {
          G2EmulationSwitchAnimationCharacter(In,0x15,0,6,1);
          StateSwitchStateCharacterData(In,StateHandlerPushObject,0);
        }
        ControlFlag = ControlFlag & 0xfffffffe;
      }
    }
    else {
      if ((int)puVar5 < 0x2000001) {
        if (puVar5 == &DAT_80000002) {
          if ((CurrentSection == 0) && ((*PadData & 0x40) != 0)) {
            Raziel.returnState = (_func_60 *)0x0;
            NewProcess = StateHandlerSoulSuck;
            goto LAB_800a8c68;
          }
        }
        else {
          if ((int)puVar5 < -0x7ffffffd) {
            if (puVar5 == (undefined *)0x80000000) {
              if ((Raziel.Senses.Flags & 0x80U) == 0) {
                NewProcess = StateHandlerAttack2;
LAB_800a89ac:
                StateSwitchStateData(In,CurrentSection,NewProcess,0);
              }
            }
            else {
              if (puVar5 != (undefined *)0x80000001) goto LAB_800a8c7c;
              if (CurrentSection == 0) {
                Raziel.Mode = 0x10;
                ControlFlag = ControlFlag | 0x10;
                Ptr = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x10,(int *)0x0,(int *)0x0)
                ;
                if (Ptr != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x22,0,2,1);
                }
                NewProcess = StateHandlerCompression;
                goto LAB_800a8c68;
              }
            }
          }
          else {
            if (puVar5 == &DAT_00100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 1;
                Raziel.idleCount = 0;
                ControlFlag = (int)&DAT_0002a109;
                PhysicsMode = 3;
                SteerSwitchMode(In->CharacterInstance,0);
                Raziel.movementMinRate = 0;
              }
              StateInitIdle(In,CurrentSection,p_Var3->Data);
            }
            else {
              if ((int)puVar5 < 0x100002) {
                if (puVar5 == &DAT_80000010) {
                  if ((CurrentSection == 0) && ((Raziel.Senses.Flags & 4U) != 0)) {
                    if (((Raziel.Senses.Flags & 0x80U) == 0) &&
                       ((gameTrackerX.streamFlags & 4U) == 0)) {
                      NewProcess = StateHandlerGlyphs;
                      goto LAB_800a8c68;
                    }
                    EnMessageQueueData(&In->SectionList[0].Defer,(int)&DAT_80000010,0);
                  }
                }
                else {
LAB_800a8c7c:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar5 != &DAT_00100004) goto LAB_800a8c7c;
                if (CurrentSection == 0) {
                  razReaverScale(0x1000);
                  razResetPauseTranslation(In->CharacterInstance);
                  goto LAB_800a8780;
                }
              }
            }
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x4010400) {
          if ((((*(uint *)(p_Var3->Data + 0x20) & 0x20000) != 0) && ((Raziel.Abilities & 1U) != 0))
             && (Raziel.CurrentPlane == 2)) {
            Raziel.playerEvent = Raziel.playerEvent | 0x10000;
          }
        }
        else {
          if ((int)puVar5 < 0x4010401) {
            if (0x2000002 < (int)puVar5) {
              if (puVar5 != (undefined *)0x4010080) goto LAB_800a8c7c;
              if (CurrentSection == 0) {
                if (p_Var3->Data == 0) {
                  razSetPauseTranslation(In->CharacterInstance);
                }
                else {
                  razResetPauseTranslation(In->CharacterInstance);
                }
              }
            }
          }
          else {
            if (puVar5 == (undefined *)0x8000000) {
              if (iVar2 == 0xd7) {
                ControlFlag = ControlFlag & 0xff7fffff;
              }
              if (iVar2 == 0xd6) {
                G2EmulationSwitchAnimation(In,CurrentSection,0xd7,0,3,1);
              }
              else {
                Ptr = SetControlInitIdleData(0,0,3);
                StateInitIdle(In,CurrentSection,Ptr);
                if (CurrentSection == 0) {
                  if ((Raziel.playerEventHistory & 0x10000) == 0) {
                    ControlFlag = ControlFlag & 0xffff7fff;
                  }
LAB_800a8780:
                  COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
                }
              }
            }
            else {
              if ((int)puVar5 < 0x8000001) {
                if (puVar5 != (undefined *)0x4010401) goto LAB_800a8c7c;
                bVar1 = true;
              }
              else {
                if (puVar5 != (undefined *)0x10000000) goto LAB_800a8c7c;
                if ((*PadData & 0x200) != 0) {
LAB_800a8988:
                  StateSwitchStateData(In,CurrentSection,StateHandlerMove,3);
                  goto LAB_800a8c88;
                }
                if (-0x201 < Raziel.Bearing) {
                  if (Raziel.Bearing < 0x201) {
                    if (bVar1) goto LAB_800a8c88;
                    if (0xfff < Raziel.Magnitude) {
                      NewProcess = StateHandlerStartMove;
                      goto LAB_800a89ac;
                    }
                    goto LAB_800a8988;
                  }
                  if (CurrentSection == 1) {
                    if (In->CharacterInstance->LinkChild == (_Instance *)0x0) {
                      Ptr = 1;
                      Mode = CurrentSection;
                      goto LAB_800a893c;
                    }
                  }
                  else {
                    Mode = 1;
                    Ptr = CurrentSection;
LAB_800a893c:
                    G2EmulationSwitchAnimation(In,Ptr,0x35,0,2,Mode);
                  }
                  StateSwitchStateData(In,CurrentSection,StateHandlerStartTurn,0);
                  pp_Var6[0x47] = (_Instance *)0x33;
                  goto LAB_800a8c88;
                }
                if (CurrentSection == 1) {
                  Inst = razGetHeldWeapon();
                  Ptr = 1;
                  Mode = CurrentSection;
                  if (Inst == (_Instance *)0x0) goto LAB_800a88b0;
                }
                else {
                  Ptr = CurrentSection;
                  Mode = 1;
LAB_800a88b0:
                  G2EmulationSwitchAnimation(In,Ptr,0x36,0,2,Mode);
                }
                StateSwitchStateData(In,CurrentSection,StateHandlerStartTurn,0);
                pp_Var6[0x47] = (_Instance *)0x34;
              }
            }
          }
        }
      }
    }
LAB_800a8c88:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerLookAround(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$a2*/)
 // line 879, offset 0x800a8da0
	/* begin block 1 */
		// Start line: 880
		// Start offset: 0x800A8DA0
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 887
			// Start offset: 0x800A8E90
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.1 */
		// End offset: 0x800A8ED4
		// End Line: 895

		/* begin block 1.2 */
			// Start line: 902
			// Start offset: 0x800A8F0C
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.2 */
		// End offset: 0x800A8F0C
		// End Line: 903

		/* begin block 1.3 */
			// Start line: 915
			// Start offset: 0x800A8F54
			// Variables:
		// 		int message; // stack offset -32
		// 		int messageData; // stack offset -28
		/* end block 1.3 */
		// End offset: 0x800A9008
		// End Line: 933
	/* end block 1 */
	// End offset: 0x800A90CC
	// End Line: 956

	/* begin block 2 */
		// Start line: 1879
	/* end block 2 */
	// End Line: 1880

void StateHandlerLookAround(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  code *NewProcess;
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
    if (puVar2 == (undefined *)0x100000) {
      Data_00 = 0;
      NewProcess = Raziel.returnState;
LAB_800a905c:
      StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
    }
    else {
      if ((int)puVar2 < 0x100001) {
        if (puVar2 == &DAT_00040005) {
LAB_800a904c:
          Data_00 = p_Var1->Data;
          NewProcess = StateHandlerStumble;
          goto LAB_800a905c;
        }
        if ((int)puVar2 < 0x40006) {
          if ((puVar2 == &DAT_80000020) &&
             (Data_00 = StateHandlerDecodeHold(&local_20,&iStack28), Data_00 != 0)) {
            if ((local_20 == 0x80000) && (CurrentSection == 0)) {
              razLaunchForce(In->CharacterInstance);
              StateSwitchStateData(In,0,StateHandlerThrow2,0);
            }
            StateSwitchStateData(In,CurrentSection,StateHandlerThrow2,0);
            if ((Raziel.Senses.heldClass != 0x1000) && (Raziel.Senses.heldClass != 8)) {
              razSetFadeEffect(In->CharacterInstance->fadeValue,PlayerData->throwFadeValue,
                               (int)PlayerData->throwFadeInRate);
            }
            Raziel.returnState = StateHandlerIdle;
            Raziel.throwMode = 2;
          }
        }
        else {
          if (puVar2 == &UNK_00040025) goto LAB_800a904c;
        }
      }
      else {
        if (puVar2 == &DAT_00100004) {
          if (CurrentSection == 1) {
            anim = &In->CharacterInstance->anim;
            G2Anim_InterpDisableController(anim,0x11,0xe,300);
            G2Anim_InterpDisableController(anim,0x10,0xe,300);
            G2Anim_InterpDisableController(anim,0xe,0xe,300);
          }
        }
        else {
          if ((int)puVar2 < 0x100005) {
            if (puVar2 == &DAT_00100001) {
              if (CurrentSection == 1) {
                anim = &In->CharacterInstance->anim;
                G2Anim_EnableController(anim,0x11,0xe);
                G2Anim_EnableController(anim,0x10,0xe);
                G2Anim_EnableController(anim,0xe,0xe);
                ControlFlag = 0x8001008;
              }
              Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
              if (Data_00 == 0x18) {
                StateInitIdle(In,CurrentSection,0);
              }
            }
          }
          else {
            if (puVar2 == (undefined *)0x1000000) {
              if (CurrentSection == 0) {
                CAMERA_ForceEndLookaroundMode(&theCamera);
              }
              Data_00 = p_Var1->Data;
              NewProcess = StateHandlerHitReaction;
              goto LAB_800a905c;
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
// void /*$ra*/ StateHandlerCrouch(struct __CharacterState *In /*$s3*/, int CurrentSection /*$s4*/, int Data /*stack 8*/)
 // line 959, offset 0x800a90e8
	/* begin block 1 */
		// Start line: 960
		// Start offset: 0x800A90E8
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		int Anim; // $s0
	// 		struct _Instance *heldInst; // $s5
	// 		int DropThisFrame; // stack offset -48

		/* begin block 1.1 */
			// Start line: 1074
			// Start offset: 0x800A9518
			// Variables:
		// 		struct evObjectData *data; // $s0
		// 		int i; // $s2
		/* end block 1.1 */
		// End offset: 0x800A9600
		// End Line: 1101
	/* end block 1 */
	// End offset: 0x800A9830
	// End Line: 1163

	/* begin block 2 */
		// Start line: 2049
	/* end block 2 */
	// End Line: 2050

void StateHandlerCrouch(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  _Instance *Inst;
  __Event *p_Var2;
  int NewAnim;
  undefined *puVar3;
  _Instance *instance;
  int Frames;
  __CharacterState *p_Var4;
  _Instance **pp_Var5;
  int local_38;
  
  bVar1 = false;
  Inst = razGetHeldItem();
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      if (((*PadData & 0x100) == 0) &&
         (In->SectionList[CurrentSection].Process == StateHandlerCrouch)) {
        EnMessageQueueData(&In->SectionList[CurrentSection].Event,0x20000008,0);
      }
      return;
    }
    NewAnim = G2EmulationQueryAnimation(In,CurrentSection);
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00100001) {
      if (CurrentSection == 0) {
        Raziel.Mode = 0x40;
        ControlFlag = (int)&DAT_00008109;
        PhysicsMode = 3;
        SteerSwitchMode(In->CharacterInstance,0);
        if (p_Var2->Data == 0) {
          NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x4c,(int *)0x0,(int *)0x0);
          if (NewAnim != 0) {
            local_38 = 2;
            NewAnim = 4;
            Frames = 8;
            goto LAB_800a9324;
          }
        }
        else {
          NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x48,(int *)0x0,(int *)0x0);
          if (NewAnim != 0) {
            local_38 = 1;
            NewAnim = 3;
            Frames = 3;
LAB_800a9324:
            G2EmulationSwitchAnimationCharacter(In,NewAnim,0,Frames,local_38);
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
    else {
      if ((int)puVar3 < 0x100002) {
        if (puVar3 != &DAT_80000008) {
          if ((int)puVar3 < -0x7ffffff7) {
            if (puVar3 == (undefined *)0x80000001) {
              if (((CurrentSection == 0) && (NewAnim != 5)) && (NewAnim != 0x55)) {
                Raziel.Mode = 0x20;
                NewAnim = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0x20,(int *)0x0,(int *)0x0);
                if (NewAnim != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x26,0,1,1);
                }
                StateSwitchStateCharacterData(In,StateHandlerCompression,0);
              }
            }
            else {
              if ((int)puVar3 < -0x7fffffff) {
                if (Inst != (_Instance *)0x0) {
                  bVar1 = true;
                  razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x50,-1,-1);
                  pp_Var5[0x48] = (_Instance *)0x50;
                  INSTANCE_Post(Inst,0x200005,0);
                }
              }
              else {
                if (puVar3 != &DAT_80000004) goto LAB_800a97b8;
              }
            }
          }
          else {
            if (puVar3 == &DAT_80000020) {
              if ((NewAnim == 5) || (NewAnim == 0x55)) goto LAB_800a97c8;
            }
            else {
              if ((int)puVar3 < -0x7fffffdf) {
                if (puVar3 == &DAT_80000010) {
                  if ((CurrentSection == 0) && (In->CharacterInstance->tface != (_TFace *)0x0)) {
                    EnMessageQueueData(&In->SectionList[0].Defer,(int)&DAT_80000010,0);
                    ControlFlag = ControlFlag | 0x800000;
                  }
                  goto LAB_800a96c0;
                }
              }
              else {
                if (puVar3 == (undefined *)0x100000) {
                  NewAnim = SetControlInitIdleData(0,0,3);
                  StateSwitchStateData(In,CurrentSection,StateHandlerIdle,NewAnim);
                  goto LAB_800a97c8;
                }
              }
            }
LAB_800a97b8:
            DefaultStateHandler(In,CurrentSection,Data);
          }
        }
      }
      else {
        if (puVar3 != (undefined *)0x4020000) {
          if ((int)puVar3 < 0x4020001) {
            if (puVar3 == (undefined *)0x2000000) {
              if ((((Raziel.Senses.EngagedMask & 4) != 0) && (Raziel.Senses.heldClass != 3)) &&
                 ((NewAnim != 5 && (NewAnim != 0x55)))) {
                ControlFlag = ControlFlag & 0xfffffff7U | 0x8041000;
                NewAnim = 0;
                if (CurrentSection == 0) {
                  Frames = 8;
                  p_Var4 = In;
                  do {
                    p_Var4->SectionList[0].Data1 = 0;
                    PurgeMessageQueue((__MessageQueue *)((int)&In->TotalSections + Frames));
                    Frames = Frames + 0x11c;
                    NewAnim = NewAnim + 1;
                    p_Var4 = (__CharacterState *)&p_Var4->SectionList[0].Data1;
                  } while (NewAnim < 3);
                  razCenterWithBlock(In->CharacterInstance,Raziel.Senses.EngagedList[2].instance,
                                     -0x8d);
                  NewAnim = SetObjectData(-(int)Raziel.Senses.ForwardNormal.x,
                                          -(int)Raziel.Senses.ForwardNormal.y,0,(_Instance *)0x0,0);
                  INSTANCE_Post(Raziel.Senses.EngagedList[2].instance,0x800001,NewAnim);
                  Frames = 0x100000;
                  if ((*(uint *)(NewAnim + 0xc) & 1) == 0) {
                    instance = In->CharacterInstance;
                    goto LAB_800a95ac;
                  }
                  COLLIDE_SegmentCollisionOff(In->CharacterInstance,1);
                  Frames = 0x55;
                  if ((*(uint *)(NewAnim + 0xc) & 8) == 0) {
                    Frames = 5;
                  }
                  G2EmulationSwitchAnimationCharacter(In,Frames,0,0,1);
                  razSetPlayerEventHistory(2);
                }
              }
            }
            else {
              if ((int)puVar3 < 0x2000001) {
                if (puVar3 != &DAT_00100004) goto LAB_800a97b8;
                if ((CurrentSection == 0) &&
                   (COLLIDE_SegmentCollisionOn(In->CharacterInstance,1), Inst != (_Instance *)0x0))
                {
                  INSTANCE_Post(Inst,0x200003,7);
                  Frames = 0x80002b;
                  instance = Inst;
LAB_800a95ac:
                  INSTANCE_Post(instance,Frames,0);
                }
              }
              else {
                if (puVar3 != (undefined *)0x4010400) goto LAB_800a97b8;
              }
            }
          }
          else {
            if (puVar3 == (undefined *)0x10000000) {
              if (((Raziel.Senses.heldClass != 3) && (NewAnim != 5)) && (NewAnim != 0x55)) {
                StateSwitchStateData(In,CurrentSection,StateHandlerMove,3);
              }
            }
            else {
              if ((int)puVar3 < 0x10000001) {
                if (puVar3 != (undefined *)0x8000000) goto LAB_800a97b8;
                if ((NewAnim == 5) || (NewAnim == 0x55)) {
                  NewAnim = SetControlInitIdleData(0,0,3);
                  StateSwitchStateData(In,CurrentSection,StateHandlerIdle,NewAnim);
                  pp_Var5[0x47] = (_Instance *)0x1;
                  ControlFlag = ControlFlag & 0xf7ffefff;
                }
                else {
                  if (CurrentSection == 1) {
                    if (((In->SectionList[1].Data2 == 0x50) && (Inst != (_Instance *)0x0)) &&
                       (!bVar1)) {
                      INSTANCE_Post(Inst,0x800008,0);
                      razReaverOn();
                    }
                    In->SectionList[0].Data2 = 0x4c;
                    pp_Var5[0x48] = (_Instance *)0x4c;
                    instance = In->CharacterInstance;
                    In->SectionList[2].Data2 = 0x4c;
                    NewAnim = razSwitchVAnimCharacterGroup(instance,0x4c,(int *)0x0,(int *)0x0);
                    if (NewAnim != 0) {
                      G2EmulationSwitchAnimationCharacter(In,4,0,8,2);
                    }
                  }
                }
              }
              else {
                if (puVar3 != (undefined *)0x20000008) goto LAB_800a97b8;
LAB_800a96c0:
                if (((NewAnim != 5) && (NewAnim != 0x55)) && (pp_Var5[0x48] != (_Instance *)0x50)) {
                  NewAnim = SetControlInitIdleData(0,0,3);
                  StateSwitchStateData(In,CurrentSection,StateHandlerIdle,NewAnim);
                  Raziel.Mode = 0x1000000;
                }
              }
            }
          }
        }
      }
    }
LAB_800a97c8:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDropAction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s4*/)
 // line 1166, offset 0x800a9860
	/* begin block 1 */
		// Start line: 1167
		// Start offset: 0x800A9860
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800A9AC0
	// End Line: 1237

	/* begin block 2 */
		// Start line: 2482
	/* end block 2 */
	// End Line: 2483

void StateHandlerDropAction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *Inst;
  undefined *puVar2;
  int Data_00;
  ulong Frames;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x8000000) {
      if (CurrentSection == 1) {
        Inst = razGetHeldItem();
        if (Inst != (_Instance *)0x0) {
          Inst = razGetHeldItem();
          INSTANCE_Post(Inst,0x800008,0);
          razReaverOn();
        }
        Data_00 = SetControlInitIdleData(0,0,3);
        StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
      }
    }
    else {
      if ((int)puVar2 < 0x8000001) {
        if (puVar2 != (undefined *)0x80000001) {
          if (puVar2 != &DAT_00100001) goto LAB_800a9aa8;
          Inst = razGetHeldItem();
          if ((Inst == (_Instance *)0x0) || (CurrentSection != 1)) {
            if (CurrentSection == 2) {
              G2EmulationSwitchAnimationAlpha(In,2,0x45,0,3,1,1);
            }
            else {
              if (CurrentSection == 0) {
                G2EmulationSwitchAnimationAlpha(In,0,3,0,3,1,1);
                Raziel.Mode = 0x40;
              }
            }
          }
          else {
            if (Raziel.Senses.heldClass == 2) {
              Data_00 = 0x69;
              Frames = 3;
LAB_800a99b0:
              G2EmulationSwitchAnimation(In,1,Data_00,0,Frames,1);
            }
            else {
              if (Raziel.Senses.heldClass < 3) {
                if ((Raziel.Senses.heldClass != 0) && (Raziel.Senses.heldClass == 1)) {
                  Data_00 = 0x53;
                  Frames = 3;
                  goto LAB_800a99b0;
                }
              }
              else {
                if (Raziel.Senses.heldClass == 3) {
                  Data_00 = 99;
                  Frames = Raziel.Senses.heldClass;
                  goto LAB_800a99b0;
                }
              }
            }
            Inst = razGetHeldItem();
            INSTANCE_Post(Inst,0x80002c,0);
          }
        }
      }
      else {
        if ((puVar2 != (undefined *)0x10000000) && (puVar2 != (undefined *)0x20000008)) {
LAB_800a9aa8:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSoulSuck(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s5*/)
 // line 1244, offset 0x800a9ae0
	/* begin block 1 */
		// Start line: 1245
		// Start offset: 0x800A9AE0
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s3

		/* begin block 1.1 */
			// Start line: 1352
			// Start offset: 0x800A9FA8
			// Variables:
		// 		struct evPhysicsSwimData *SwimData; // $v0
		/* end block 1.1 */
		// End offset: 0x800A9FD8
		// End Line: 1359
	/* end block 1 */
	// End offset: 0x800A9FF4
	// End Line: 1367

	/* begin block 2 */
		// Start line: 2647
	/* end block 2 */
	// End Line: 2648

	/* begin block 3 */
		// Start line: 2652
	/* end block 3 */
	// End Line: 2653

void StateHandlerSoulSuck(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  _Instance *p_Var3;
  undefined *puVar4;
  int Data_00;
  code *NewProcess;
  _func_60 *NewProcess_00;
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
LAB_800a9d8c:
      if (iVar1 == 0x4f) {
        G2EmulationSwitchAnimation(In,CurrentSection,0x2f,0,3,1);
        PurgeMessageQueue(&p_Var5->Event);
      }
      else {
        if (Raziel.returnState == (_func_60 *)0x0) {
          Data_00 = SetControlInitIdleData(0,0,3);
          NewProcess = StateHandlerIdle;
        }
        else {
          Data_00 = 0;
          NewProcess = Raziel.returnState;
        }
        StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
      }
      if (((Raziel.Senses.EngagedMask & 0x1000) != 0) && (CurrentSection == 0)) {
LAB_800a9e24:
        INSTANCE_Post(Raziel.Senses.EngagedList[0xc].instance,0x1000014,0);
      }
    }
    else {
      if ((int)puVar4 < 0x1000007) {
        if (puVar4 == &DAT_00100001) {
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
              Data_00 = 0x5e;
            }
            G2EmulationSwitchAnimation(In,1,Data_00,0,4,1);
            Raziel.Mode = Raziel.Mode | 0x10000000;
          }
        }
        else {
          if ((int)puVar4 < 0x100002) {
            if (puVar4 != &DAT_80000010) {
LAB_800a9fdc:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 == &DAT_00100004) {
              if (CurrentSection == 1) {
                razSetCowlNoDraw(1);
                ControlFlag = ControlFlag & 0xffffffbf;
                Raziel.Mode = Raziel.Mode & 0xefffffff;
                if ((Raziel.Senses.EngagedMask & 0x1000) != 0) goto LAB_800a9e24;
              }
            }
            else {
              if (puVar4 != (undefined *)0x1000001) goto LAB_800a9fdc;
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
LAB_800a9f94:
              G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,Data_00,1);
            }
            else {
              if (puVar4 != (undefined *)0x1000016) goto LAB_800a9fdc;
              if (((gameTrackerX.debugFlags2 & 0x800U) != 0) && (CurrentSection == 1)) {
                GainHealth(p_Var2->Data);
                razSetPlayerEventHistory(0x1000);
              }
            }
          }
          else {
            if (puVar4 != (undefined *)0x8000000) {
              if (puVar4 == (undefined *)0x20000002) goto LAB_800a9d8c;
              goto LAB_800a9fdc;
            }
            if (iVar1 == 0x2f) {
              if (Raziel.returnState == (_func_60 *)0x0) {
                Data_00 = SetControlInitIdleData(0,0,3);
                NewProcess_00 = StateHandlerIdle;
              }
              else {
                Data_00 = 0;
                NewProcess_00 = Raziel.returnState;
              }
              StateSwitchStateData
                        (In,CurrentSection,(TDRFuncPtr_StateSwitchStateData2NewProcess)NewProcess_00
                         ,Data_00);
            }
            if (iVar1 == 0x4e) {
              G2EmulationSwitchAnimation(In,CurrentSection,0x4f,0,0,1);
            }
            if (iVar1 == 0x50) {
              if ((*PadData & 0x40) != 0) {
                NewAnim = 0x4f;
                Data_00 = 8;
                goto LAB_800a9f94;
              }
              if (Raziel.returnState == (_func_60 *)0x0) {
                Data_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
              }
              else {
                StateSwitchStateData
                          (In,CurrentSection,
                           (TDRFuncPtr_StateSwitchStateData2NewProcess)Raziel.returnState,0);
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
 // line 1373, offset 0x800aa018
	/* begin block 1 */
		// Start line: 1374
		// Start offset: 0x800AA018
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800AA1FC
	// End Line: 1434

	/* begin block 2 */
		// Start line: 2915
	/* end block 2 */
	// End Line: 2916

void StateHandlerStartTurn(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
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
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100000) {
LAB_800aa12c:
      if (CurrentSection == 0) {
        if ((*PadData & 0x8000000fU) == 0) {
          Data_00 = SetControlInitIdleData(0,0,3);
          StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
        }
        else {
          NewProcess = StateHandlerStartMove;
LAB_800aa1d4:
          StateSwitchStateCharacterData(In,NewProcess,0);
        }
      }
    }
    else {
      if ((int)puVar2 < 0x100001) {
        if (puVar2 == (undefined *)0x80000001) {
          if (CurrentSection == 0) {
            Raziel.Mode = 8;
            Data_00 = razSwitchVAnimCharacterGroup(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
            if (Data_00 != 0) {
              G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
            }
            NewProcess = StateHandlerCompression;
            goto LAB_800aa1d4;
          }
        }
        else {
          if (puVar2 == (undefined *)0x0) goto LAB_800aa12c;
LAB_800aa1e4:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar2 != &DAT_00100001) {
          if (puVar2 != (undefined *)0x8000000) goto LAB_800aa1e4;
          goto LAB_800aa12c;
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
// void /*$ra*/ StateInitStartMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Frame /*$s3*/)
 // line 1438, offset 0x800aa218
	/* begin block 1 */
		// Start line: 3050
	/* end block 1 */
	// End Line: 3051

	/* begin block 2 */
		// Start line: 3053
	/* end block 2 */
	// End Line: 3054

void StateInitStartMove(__CharacterState *In,int CurrentSection,int Frame)

{
  int iVar1;
  
  if ((*PadData & 0x200) != 0) {
    StateSwitchStateData(In,CurrentSection,StateHandlerMove,3);
  }
  iVar1 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x30,Frame,-1);
  if (iVar1 != 0) {
    razSwitchVAnimSingle(In->CharacterInstance,CurrentSection,0,Frame,-1);
  }
  ControlFlag = ControlFlag | 0x2000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStartMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s4*/)
 // line 1527, offset 0x800aa2c4
	/* begin block 1 */
		// Start line: 1528
		// Start offset: 0x800AA2C4
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 1590
			// Start offset: 0x800AA5A0
			// Variables:
		// 		int mode; // $a0
		/* end block 1.1 */
		// End offset: 0x800AA5F8
		// End Line: 1608
	/* end block 1 */
	// End offset: 0x800AA944
	// End Line: 1699

	/* begin block 2 */
		// Start line: 3231
	/* end block 2 */
	// End Line: 3232

void StateHandlerStartMove(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  _Instance *p_Var2;
  undefined *puVar3;
  uint mode;
  code *NewProcess;
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
          StateSwitchStateData(In,1,StateHandlerMove,0xb);
        }
        if (In->SectionList[2].Process == StateHandlerStartMove) {
          StateSwitchStateData(In,2,StateHandlerMove,0xb);
        }
      }
      if (((Raziel.Magnitude != 0) && (Raziel.Magnitude < 0x1000)) && ((Raziel.passedMask & 1) != 0)
         ) {
        StateSwitchStateData(In,CurrentSection,StateHandlerMove,0);
      }
      return;
    }
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 == &DAT_00100001) {
      StateInitStartMove(In,CurrentSection,p_Var1->Data);
      In->SectionList[CurrentSection].Data2 = 1;
      if (CurrentSection == 0) {
        ControlFlag = (int)&DAT_0002a119;
        Raziel.Mode = Raziel.Mode & 0x200800U | 4;
        PhysicsMode = 3;
        SteerSwitchMode(In->CharacterInstance,2);
        Raziel.movementMinRate = 0xccc;
        Raziel.movementMinAnalog = 0x400;
        Raziel.movementMaxAnalog = 0x1000;
        Raziel.passedMask = 0;
      }
    }
    else {
      if ((int)puVar3 < 0x100002) {
        if (puVar3 == &DAT_80000002) {
LAB_800aa538:
          if (CurrentSection == 0) {
            if (In->CharacterInstance->tface != (_TFace *)0x0) {
              EnMessageQueueData(&In->SectionList[0].Defer,p_Var1->ID,0);
              ControlFlag = ControlFlag | 0x800000;
            }
LAB_800aa574:
            if (CurrentSection == 0) {
              if (((Raziel.passedMask & 7) != 0) ||
                 (Data_00 = G2EmulationQueryMode(In,0), Data_00 == 0)) {
                if ((Raziel.passedMask & 1) == 0) {
                  mode = Raziel.passedMask & 4;
                  if ((Raziel.passedMask & 2) != 0) {
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
              if ((Raziel.passedMask & 4) == 0) {
                if ((CurrentSection == 0) && ((Raziel.Senses.Flags & 0x80U) == 0)) {
                  NewProcess = StateHandlerAttack2;
LAB_800aa7b8:
                  StateSwitchStateCharacterData(In,NewProcess,0);
                }
              }
              else {
                if (CurrentSection != 1) goto LAB_800aa6d0;
                if ((Raziel.Senses.Flags & 0x80U) == 0) {
                  StateSwitchStateData(In,1,StateHandlerAttack2,10);
                }
              }
            }
            else {
              if (puVar3 != (undefined *)0x80000001) goto LAB_800aa7fc;
              if (CurrentSection == 0) {
                Raziel.Mode = 8;
                Data_00 = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (Data_00 != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
                }
                StateSwitchStateCharacterData(In,StateHandlerCompression,0);
LAB_800aa668:
                ControlFlag = ControlFlag & 0xffffdfff;
              }
            }
            goto LAB_800aa808;
          }
          if (puVar3 == &DAT_80000010) goto LAB_800aa538;
          if ((int)puVar3 < -0x7fffffef) {
            if (puVar3 == &DAT_80000004) {
              StateSwitchStateData(In,CurrentSection,StateHandlerMove,3);
              goto LAB_800aa808;
            }
          }
          else {
            if (puVar3 == (undefined *)0x0) goto LAB_800aa574;
          }
LAB_800aa7fc:
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
                  NewProcess = StateHandlerFall;
                  goto LAB_800aa7b8;
                }
              }
            }
            else {
              if ((int)puVar3 < 0x4000002) {
                if (puVar3 != (undefined *)0x2000000) goto LAB_800aa7fc;
                if ((Raziel.Senses.EngagedMask & 0x20) == 0) goto LAB_800aa538;
                razPickupAndGrab(In,CurrentSection);
              }
              else {
                if (puVar3 != (undefined *)0x4010080) goto LAB_800aa7fc;
                if (CurrentSection != 2) {
                  G2EmulationSetMode(In,CurrentSection,(uint)(p_Var1->Data != 0));
                }
                if (((Raziel.passedMask & 2) != 0) && ((*PadData & 0x8000000fU) != 0)) {
                  G2EmulationSetMode(In,CurrentSection,2);
                  goto LAB_800aa668;
                }
              }
            }
          }
          else {
            if ((int)puVar3 < 0x8000000) goto LAB_800aa7fc;
            if ((int)puVar3 < 0x8000002) {
LAB_800aa6d0:
              StateSwitchStateData(In,CurrentSection,StateHandlerMove,0);
            }
            else {
              if (puVar3 != (undefined *)0x10000000) goto LAB_800aa7fc;
            }
          }
        }
      }
    }
LAB_800aa808:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateInitMove(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s0*/, int Frames /*$a2*/)
 // line 1702, offset 0x800aa964
	/* begin block 1 */
		// Start line: 3596
	/* end block 1 */
	// End Line: 3597

	/* begin block 2 */
		// Start line: 3601
	/* end block 2 */
	// End Line: 3602

void StateInitMove(__CharacterState *In,int CurrentSection,int Frames)

{
  uint uVar1;
  int iVar2;
  
  if ((*PadData & 0x200) == 0) {
    if ((*PadData & 0x100) == 0) {
      Raziel.Mode = Raziel.Mode & 0x200800U | 4;
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
// void /*$ra*/ StateHandlerMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 1908, offset 0x800aaba8
	/* begin block 1 */
		// Start line: 1909
		// Start offset: 0x800AABA8
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s6

		/* begin block 1.1 */
			// Start line: 1974
			// Start offset: 0x800AAF60
			// Variables:
		// 		int data; // $a2
		/* end block 1.1 */
		// End offset: 0x800AAF90
		// End Line: 1986
	/* end block 1 */
	// End offset: 0x800AB250
	// End Line: 2075

	/* begin block 2 */
		// Start line: 4044
	/* end block 2 */
	// End Line: 4045

void StateHandlerMove(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  _Instance **pp_Var2;
  __Event *p_Var3;
  int Data_00;
  _Instance *p_Var4;
  undefined *puVar5;
  code *NewProcess;
  int local_2c;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  pp_Var2 = &In->CharacterInstance + CurrentSection * 0x47;
  pp_Var2[0x47] = (_Instance *)((int)&(pp_Var2[0x47]->node).prev + 1);
  do {
    p_Var3 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var3 == (__Event *)0x0) {
      if ((CurrentSection == 0) && (In->SectionList[0].Process != StateHandlerMove)) {
        razResetMotion(In->CharacterInstance);
      }
      return;
    }
    puVar5 = (undefined *)p_Var3->ID;
    if (puVar5 == (undefined *)0x0) {
LAB_800aae54:
      if (CurrentSection == 0) {
        if (((Raziel.steeringMode == 9) || (Raziel.steeringMode == 0xe)) ||
           (Raziel.steeringMode == 0xf)) {
          razApplyMotion(In,0);
        }
        else {
          if (((Raziel.Mode == 2) || (iVar1 == 0x7b)) || (iVar1 == 0x7c)) {
            Data_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
          }
          else {
            if (Raziel.Mode == 0x1000000) {
              NewProcess = StateHandlerCrouch;
LAB_800ab1cc:
              StateSwitchStateCharacterData(In,NewProcess,0);
            }
            else {
              if ((p_Var3->Data < 4) && ((ControlFlag & 0x800000U) == 0)) {
                ControlFlag = ControlFlag | 0x2000;
                if ((*PadData & 0x8000000fU) == 0) {
                  EnMessageQueueData(&In->SectionList[0].Defer,0,p_Var3->Data + 1);
                  razApplyMotion(In,0);
                }
              }
              else {
                Data_00 = 0;
                if ((Raziel.passedMask & 0x2000) != 0) {
                  Data_00 = 0x1e;
                }
                if ((Raziel.passedMask & 0x1000) != 0) {
                  Data_00 = 0x3c;
                }
                StateSwitchStateCharacterData(In,StateHandlerStopMove,Data_00);
              }
            }
          }
        }
      }
    }
    else {
      if ((int)puVar5 < 1) {
        if (puVar5 == &DAT_80000002) {
LAB_800aadfc:
          if ((*PadData & 0x100) == 0) {
LAB_800aae18:
            if (CurrentSection == 0) {
              if (In->CharacterInstance->tface != (_TFace *)0x0) {
                EnMessageQueueData(&In->SectionList[0].Defer,p_Var3->ID,0);
                ControlFlag = ControlFlag | 0x800000;
              }
              goto LAB_800aae54;
            }
          }
        }
        else {
          if ((int)puVar5 < -0x7ffffffd) {
            if (puVar5 == (undefined *)0x80000000) {
              if ((*PadData & 0x200) == 0) {
                if (pp_Var2[0x48] == (_Instance *)0x44) {
                  if ((CurrentSection == 1) && ((Raziel.Senses.Flags & 0x80U) == 0)) {
                    StateSwitchStateData(In,1,StateHandlerAttack2,10);
                  }
                  Raziel.dropOffHeight = 200;
                  Raziel.fallZVelocity = -0x60;
                }
                else {
                  if (pp_Var2[0x48] != (_Instance *)0x38) goto LAB_800ab1dc;
                  p_Var4 = razGetHeldItem();
                  if ((p_Var4 != (_Instance *)0x0) && (CurrentSection == 0)) {
                    NewProcess = StateHandlerDropAction;
                    goto LAB_800ab1cc;
                  }
                }
              }
              else {
LAB_800ab1dc:
                if ((Raziel.Senses.Flags & 0x80U) == 0) {
                  StateSwitchStateData(In,CurrentSection,StateHandlerAttack2,0);
                }
              }
            }
            else {
              if (puVar5 != (undefined *)0x80000001) goto LAB_800ab210;
              if (CurrentSection != 0) goto LAB_800ab21c;
              if ((*PadData & 0x100) == 0) {
                Raziel.Mode = 8;
                Data_00 = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (Data_00 != 0) {
                  Data_00 = 0;
                  goto LAB_800ab0f4;
                }
              }
              else {
                Raziel.Mode = 0x20;
                Data_00 = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0x20,(int *)0x0,(int *)0x0);
                if (Data_00 != 0) {
                  Data_00 = 1;
LAB_800ab0f4:
                  G2EmulationSwitchAnimationCharacter(In,0x1a,0,Data_00,1);
                }
              }
              StateSwitchStateCharacterData(In,StateHandlerCompression,0);
LAB_800ab110:
              ControlFlag = ControlFlag & 0xffffdfff;
            }
          }
          else {
            if (puVar5 != &DAT_80000008) {
              if ((int)puVar5 < -0x7ffffff7) {
                if (puVar5 == &DAT_80000004) {
                  if ((Raziel.Mode & 0x200000U) == 0) {
                    if (CurrentSection != 2) {
                      local_2c = 2;
                      Data_00 = CurrentSection;
                    }
                    else {
                      Data_00 = 2;
                      local_2c = CurrentSection;
                    }
                    G2EmulationSwitchAnimation(In,Data_00,(uint)(CurrentSection != 2),0,3,local_2c);
                    Raziel.Mode = 2;
                    ControlFlag = ControlFlag | 0x2000;
                  }
                  goto LAB_800ab21c;
                }
              }
              else {
                if (puVar5 == &DAT_80000010) goto LAB_800aae18;
              }
LAB_800ab210:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x4010080) {
          if (CurrentSection == 0) {
            if (p_Var3->Data == 0) {
              razSetPauseTranslation(In->CharacterInstance);
            }
            else {
              razResetPauseTranslation(In->CharacterInstance);
            }
          }
        }
        else {
          if (0x4010080 < (int)puVar5) {
            if (puVar5 == (undefined *)0x20000004) {
LAB_800ab050:
              Raziel.Mode = 4;
              goto LAB_800ab110;
            }
            if ((int)puVar5 < 0x20000005) {
              if (puVar5 == (undefined *)0x10000000) {
                if (Raziel.Magnitude < 0x1000) {
                  StateInitMove(In,CurrentSection,3);
                }
                else {
                  StateInitMove(In,CurrentSection,0);
                }
                goto LAB_800ab21c;
              }
            }
            else {
              if (puVar5 == (undefined *)0x20000008) goto LAB_800ab050;
            }
            goto LAB_800ab210;
          }
          if (puVar5 == &DAT_00100004) {
            FX_EndConstrict(0,(_Instance *)0x0);
            pp_Var2[0x47] = (_Instance *)0x0;
          }
          else {
            if ((int)puVar5 < 0x100005) {
              if (puVar5 != &DAT_00100001) goto LAB_800ab210;
              pp_Var2[0x48] = (_Instance *)0xffffffff;
              StateInitMove(In,CurrentSection,p_Var3->Data);
              Raziel.constrictFlag = 1;
              SteerSwitchMode(In->CharacterInstance,2);
              pp_Var2[0x47] = (_Instance *)0x0;
              Raziel.passedMask = Raziel.passedMask | 0x1000;
            }
            else {
              if (puVar5 != (undefined *)0x2000000) goto LAB_800ab210;
              if ((Raziel.Senses.EngagedMask & 0x20) == 0) goto LAB_800aadfc;
              razPickupAndGrab(In,CurrentSection);
            }
          }
        }
      }
    }
LAB_800ab21c:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStopMove(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 2078, offset 0x800ab27c
	/* begin block 1 */
		// Start line: 2079
		// Start offset: 0x800AB27C
		// Variables:
	// 		struct __Event *Ptr; // $a1
	/* end block 1 */
	// End offset: 0x800AB58C
	// End Line: 2172

	/* begin block 2 */
		// Start line: 4394
	/* end block 2 */
	// End Line: 4395

void StateHandlerStopMove(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
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
    if (puVar2 == (undefined *)0x2000000) {
LAB_800ab4cc:
      EnMessageQueueData(&p_Var3->Defer,p_Var1->ID,0);
    }
    else {
      if ((int)puVar2 < 0x2000001) {
        if (puVar2 == &DAT_80000002) goto LAB_800ab4cc;
        if ((int)puVar2 < -0x7ffffffd) {
          if (puVar2 == (undefined *)0x80000001) {
            if (CurrentSection == 0) {
              Raziel.Mode = 0x10;
              Data_00 = razSwitchVAnimCharacterGroup(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
              if (Data_00 != 0) {
                G2EmulationSwitchAnimationCharacter(In,0x1a,0,0,1);
              }
              StateSwitchStateCharacterData(In,StateHandlerCompression,0);
            }
            goto LAB_800ab57c;
          }
        }
        else {
          if (puVar2 == &DAT_80000010) goto LAB_800ab4cc;
          if (puVar2 == &DAT_00100001) {
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
              Data_00 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x58,-1,-1);
              if (Data_00 != 0) {
                Data_00 = 2;
LAB_800ab428:
                razSwitchVAnimSingle(In->CharacterInstance,CurrentSection,Data_00,-1,-1);
              }
            }
            else {
              if (p_Var1->Data != 0x1e) {
                frames = 6;
                goto LAB_800ab4f0;
              }
              Data_00 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x5c,-1,-1);
              if (Data_00 != 0) {
                Data_00 = 3;
                goto LAB_800ab428;
              }
            }
            goto LAB_800ab57c;
          }
        }
LAB_800ab574:
        DefaultStateHandler(In,CurrentSection,Data);
      }
      else {
        if ((int)puVar2 < 0x8000002) {
          if ((int)puVar2 < 0x8000000) {
            if (puVar2 != (undefined *)0x4010080) goto LAB_800ab574;
            if (CurrentSection == 0) {
              if (p_Var1->Data == 0) {
                razSetPauseTranslation(In->CharacterInstance);
                Data_00 = SetControlInitIdleData(0,0,5);
                StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
              }
              else {
                razResetPauseTranslation(In->CharacterInstance);
              }
            }
          }
          else {
            frames = 5;
LAB_800ab4f0:
            Data_00 = SetControlInitIdleData(0,0,frames);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
          }
        }
        else {
          if (puVar2 != (undefined *)0x10000000) goto LAB_800ab574;
          StateSwitchStateData(In,CurrentSection,StateHandlerStartMove,0);
        }
      }
    }
LAB_800ab57c:
    DeMessageQueue(&p_Var3->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCompression(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 2179, offset 0x800ab5ac
	/* begin block 1 */
		// Start line: 2180
		// Start offset: 0x800AB5AC
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800AB950
	// End Line: 2275

	/* begin block 2 */
		// Start line: 4607
	/* end block 2 */
	// End Line: 4608

void StateHandlerCompression(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  __State *p_Var2;
  __Event *p_Var3;
  long lVar4;
  _G2Bool_Enum _Var5;
  int iVar6;
  undefined *puVar7;
  _Instance *p_Var8;
  uint uVar9;
  __State *p_Var10;
  
  p_Var10 = In->SectionList + CurrentSection;
  do {
    p_Var3 = PeekMessageQueue(&p_Var10->Event);
    if (p_Var3 == (__Event *)0x0) {
      return;
    }
    puVar7 = (undefined *)p_Var3->ID;
    if (puVar7 != (undefined *)0x4000001) {
      if ((int)puVar7 < 0x4000002) {
        if (puVar7 == (undefined *)0x80000001) {
          uVar9 = 0x80000000;
          p_Var2 = p_Var10;
LAB_800ab924:
          EnMessageQueueData(&p_Var2->Defer,uVar9 | 1,0);
        }
        else {
          if (-0x80000000 < (int)puVar7) {
            if (puVar7 != &DAT_00100001) goto LAB_800ab938;
            if (CurrentSection == 0) {
              ControlFlag = 0x111;
              SetExternalForce(&__Force_800d72a0,0,0,0,1,0);
              In->SectionList[0].Data1 = 0;
              PhysicsMode = 3;
              Raziel.movementMinRate = 0;
              if (Raziel.Mode == 0x10) {
                SteerSwitchMode(In->CharacterInstance,4);
                sVar1 = (In->CharacterInstance->rotation).z;
                p_Var8 = In->CharacterInstance;
                lVar4 = 0x28;
              }
              else {
                if ((Raziel.Mode < 0x11) || (Raziel.Mode != 0x20)) goto LAB_800ab940;
                SteerSwitchMode(In->CharacterInstance,4);
                sVar1 = (In->CharacterInstance->rotation).z;
                p_Var8 = In->CharacterInstance;
                lVar4 = 0x15;
              }
              Raziel.steeringLockRotation = (int)sVar1;
              p_Var8->yVel = lVar4;
              _Var5 = G2Anim_IsControllerActive(&In->CharacterInstance->anim,1,0xe);
              if (_Var5 == G2FALSE) {
                G2Anim_EnableController(&In->CharacterInstance->anim,1,0xe);
              }
            }
          }
        }
      }
      else {
        if (puVar7 == (undefined *)0x8000000) {
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
          if ((int)puVar7 < 0x8000001) {
            if (puVar7 != (undefined *)0x4020000) {
LAB_800ab938:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar7 != (undefined *)0x20000001) goto LAB_800ab938;
            if (CurrentSection == 0) {
              if (Raziel.Mode == 0x10) {
                In->SectionList[0].Data1 = 1;
              }
              p_Var2 = In->SectionList;
              uVar9 = 0x20000000;
              goto LAB_800ab924;
            }
          }
        }
      }
    }
LAB_800ab940:
    DeMessageQueue(&p_Var10->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerJump(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 2278, offset 0x800ab970
	/* begin block 1 */
		// Start line: 2279
		// Start offset: 0x800AB970
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800ABD80
	// End Line: 2378

	/* begin block 2 */
		// Start line: 4828
	/* end block 2 */
	// End Line: 4829

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
    if (puVar2 == (undefined *)0x1000001) goto LAB_800abd70;
    if ((int)puVar2 < 0x1000002) {
      if (puVar2 != &DAT_80000008) {
        if ((int)puVar2 < -0x7ffffff7) {
          if (puVar2 != (undefined *)0x80000000) {
            if (puVar2 != (undefined *)0x80000001) goto LAB_800abd68;
            NewAnim = G2EmulationQueryFrame(In,CurrentSection);
            In_00 = &p_Var4->Defer;
            if (1 < NewAnim) {
              if ((Raziel.Senses.heldClass != 3) && (CurrentSection == 0)) {
                StateSwitchStateCharacterData(In,StateHandlerGlide,0);
              }
              goto LAB_800abd70;
            }
            uVar3 = 0x80000000;
LAB_800abd44:
            EnMessageQueueData(In_00,uVar3 | 1,0);
          }
        }
        else {
          if (puVar2 != &DAT_00040005) {
            if ((int)puVar2 < 0x40006) {
              if (puVar2 != &DAT_80000020) {
LAB_800abd68:
                DefaultStateHandler(In,CurrentSection,Data);
              }
            }
            else {
              if (puVar2 != &DAT_00100001) goto LAB_800abd68;
              if (CurrentSection == 0) {
                ControlFlag = 0x511;
                Raziel.alarmTable = 200;
                PhysicsMode = 0;
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d7124;
              }
              In->SectionList[CurrentSection].Data2 = 0;
            }
          }
        }
      }
    }
    else {
      if (puVar2 != (undefined *)0x4020000) {
        if ((int)puVar2 < 0x4020001) {
          if (puVar2 != (undefined *)0x4000001) {
            if ((int)puVar2 < 0x4000002) {
              if (puVar2 != (undefined *)0x2000000) goto LAB_800abd68;
              razPickupAndGrab(In,CurrentSection);
            }
            else {
              if (puVar2 != (undefined *)0x4010008) goto LAB_800abd68;
            }
          }
        }
        else {
          if (puVar2 == (undefined *)0x8000004) {
            ControlFlag = ControlFlag | 8;
          }
          else {
            if (0x8000004 < (int)puVar2) {
              if (puVar2 != (undefined *)0x20000001) goto LAB_800abd68;
              In->SectionList[CurrentSection].Data2 = 1;
              if (CurrentSection != 0) goto LAB_800abd70;
              if ((Raziel.Mode == 0x10) || (Raziel.Mode == 0x20)) {
                In_00 = &In->SectionList[0].Defer;
                uVar3 = 0x20000000;
                goto LAB_800abd44;
              }
              if (In->SectionList[0].Data1 == 0) {
                NewAnim = G2EmulationQueryFrame(In,0);
                In->SectionList[0].Data1 = NewAnim + 4;
                if (NewAnim + 4 != 0) goto LAB_800abc7c;
              }
              else {
LAB_800abc7c:
                NewAnim = G2EmulationQueryFrame(In,0);
                if (In->SectionList[0].Data1 < NewAnim) {
                  SetDropPhysics(In->CharacterInstance,&Raziel);
                  NewAnim = razSwitchVAnimCharacterGroup
                                      (In->CharacterInstance,8,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    G2EmulationSwitchAnimationCharacter(In,0x1c,0,7,1);
                  }
                  StateSwitchStateCharacterData(In,StateHandlerFall,In->SectionList[0].Data2);
                  goto LAB_800abd70;
                }
              }
              In_00 = &p_Var4->Defer;
              uVar3 = 0x20000000;
              goto LAB_800abd44;
            }
            if (puVar2 != (undefined *)0x8000000) goto LAB_800abd68;
            if (CurrentSection == 0) {
              if (Raziel.Mode == 0x10) {
                NewAnim = razSwitchVAnimCharacterGroup
                                    (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                if (NewAnim != 0) {
                  NewAnim = 0x24;
                  Frames = 4;
                  goto LAB_800abbdc;
                }
              }
              else {
                if (Raziel.Mode == 0x20) {
                  NewAnim = razSwitchVAnimCharacterGroup
                                      (In->CharacterInstance,0x28,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    NewAnim = 0x28;
                    Frames = 10;
LAB_800abbdc:
                    G2EmulationSwitchAnimationCharacter(In,NewAnim,0,Frames,1);
                  }
                }
                else {
                  NewAnim = razSwitchVAnimCharacterGroup
                                      (In->CharacterInstance,8,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    NewAnim = 0x1c;
                    Frames = 7;
                    goto LAB_800abbdc;
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
LAB_800abd70:
    DeMessageQueue(&p_Var4->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerFall(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s3*/, int Data /*stack 8*/)
 // line 2381, offset 0x800abda8
	/* begin block 1 */
		// Start line: 2382
		// Start offset: 0x800ABDA8
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Moving; // $s7
	// 		int DeferFlag; // $s6
	// 		struct evPhysicsSwimData *SwimData; // $s1

		/* begin block 1.1 */
			// Start line: 2400
			// Start offset: 0x800ABDEC
		/* end block 1.1 */
		// End offset: 0x800ABE20
		// End Line: 2406
	/* end block 1 */
	// End offset: 0x800AC1EC
	// End Line: 2587

	/* begin block 2 */
		// Start line: 5072
	/* end block 2 */
	// End Line: 5073

void StateHandlerFall(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  bool bVar2;
  Level *pLVar3;
  __Event *p_Var4;
  undefined *puVar5;
  _Instance *instance;
  int iVar6;
  __State *p_Var7;
  int Data_00;
  
  Data_00 = 0;
  bVar2 = true;
  if (CurrentSection == 0) {
    pLVar3 = STREAM_GetLevelWithID(In->CharacterInstance->currentStreamUnitID);
    if ((pLVar3->unitFlags & 0x1000U) != 0) {
      EnMessageQueueData(&In->SectionList[0].Event,0x100000,0);
    }
  }
  p_Var7 = In->SectionList + CurrentSection;
  do {
    p_Var4 = PeekMessageQueue(&p_Var7->Event);
    if (p_Var4 == (__Event *)0x0) {
      return;
    }
    puVar5 = (undefined *)p_Var4->ID;
    if (puVar5 != (undefined *)0x1000001) {
      if ((int)puVar5 < 0x1000002) {
        if (puVar5 != &DAT_80000020) {
          if ((int)puVar5 < -0x7fffffdf) {
            if (puVar5 == (undefined *)0x80000001) {
              if (((Raziel.Senses.heldClass != 3) && ((ControlFlag & 0x2000000U) == 0)) &&
                 (CurrentSection == 0)) {
                StateSwitchStateCharacterData(In,StateHandlerGlide,3);
              }
            }
            else {
              if ((-0x80000000 < (int)puVar5) && (puVar5 != &DAT_80000008)) goto LAB_800ac1d0;
            }
          }
          else {
            if (puVar5 == (undefined *)0x100000) {
              StateSwitchStateCharacterData(In,StateHandlerForcedGlide,0);
            }
            else {
              if ((int)puVar5 < 0x100001) {
                if (puVar5 == &DAT_00040005) {
                  if (Raziel.HitPoints < 100000) {
                    StateSwitchStateData(In,CurrentSection,StateHandlerStumble,0);
                  }
                }
                else {
LAB_800ac1d0:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar5 != &DAT_00100001) goto LAB_800ac1d0;
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
                  EnMessageQueueData(&p_Var7->Defer,-0x7fffffff,0);
                }
              }
            }
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x4020000) {
          iVar6 = p_Var4->Data;
          if (((*(short *)(iVar6 + 0xc) < 0) &&
              (instance = In->CharacterInstance, instance->zVel == 0)) && (-1 < instance->zAccl)) {
            ResetPhysics(instance,-0x10);
          }
          Raziel.Mode = Raziel.Mode & 0xfffbffff;
          razEnterWater(In,CurrentSection,(evPhysicsSwimData *)p_Var4->Data);
          sVar1 = *(short *)(iVar6 + 0xe);
          if (((sVar1 < 0) && (sVar1 != -0x7fff)) && (Raziel.CurrentPlane == 1)) {
            ControlFlag = ControlFlag | 0x2000000;
          }
        }
        else {
          if ((int)puVar5 < 0x4020001) {
            if (puVar5 != (undefined *)0x4000001) {
              if ((int)puVar5 < 0x4000002) {
                if (puVar5 != (undefined *)0x2000000) goto LAB_800ac1d0;
                razPickupAndGrab(In,CurrentSection);
              }
              else {
                if (puVar5 != (undefined *)0x4010008) goto LAB_800ac1d0;
                if (bVar2) {
                  EnMessageQueueData(&p_Var7->Event,0x4010008,0);
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
                if (puVar5 != (undefined *)0x8000000) goto LAB_800ac1d0;
              }
              else {
                if (puVar5 != (undefined *)0x20000001) goto LAB_800ac1d0;
                if (((Raziel.Mode != 0x10) && (Raziel.Mode != 0x20)) && (CurrentSection == 0)) {
                  SetDropPhysics(In->CharacterInstance,&Raziel);
                }
              }
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
// void /*$ra*/ StateHandlerSlide(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s3*/)
 // line 2591, offset 0x800ac21c
	/* begin block 1 */
		// Start line: 2592
		// Start offset: 0x800AC21C
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800AC3E0
	// End Line: 2648

	/* begin block 2 */
		// Start line: 5500
	/* end block 2 */
	// End Line: 5501

void StateHandlerSlide(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100000) {
LAB_800ac394:
      Data_00 = SetControlInitIdleData(0,0,3);
      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
    }
    else {
      if ((int)puVar2 < 0x100001) {
        if (puVar2 != &DAT_80000008) {
          if ((int)puVar2 < -0x7ffffff7) {
            if (-0x7fffffff < (int)puVar2) {
LAB_800ac3c8:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar2 != &DAT_80000020) goto LAB_800ac3c8;
          }
        }
      }
      else {
        if (puVar2 == (undefined *)0x4010008) goto LAB_800ac394;
        if ((int)puVar2 < 0x4010009) {
          if (puVar2 == &DAT_00100001) {
            if (CurrentSection == 0) {
              Raziel.Mode = 0x400000;
              ControlFlag = 0x509;
              PhysicsMode = 0;
              ResetPhysics(In->CharacterInstance,-0x10);
              Raziel.soundHandle =
                   SOUND_Play3dSound(&In->CharacterInstance->position,0x1e,0,0x3c,0xdac);
            }
          }
          else {
            if (puVar2 != &DAT_00100004) goto LAB_800ac3c8;
            if (Raziel.soundHandle != 0) {
              SndEndLoop(Raziel.soundHandle);
              Raziel.soundHandle = 0;
            }
          }
        }
        else {
          if ((puVar2 != (undefined *)0x4010200) && (puVar2 != (undefined *)0x20000001))
          goto LAB_800ac3c8;
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerBlock(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s4*/, int Data /*$s7*/)
 // line 2658, offset 0x800ac3fc
	/* begin block 1 */
		// Start line: 2659
		// Start offset: 0x800AC3FC
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s3

		/* begin block 1.1 */
			// Start line: 2697
			// Start offset: 0x800AC600
			// Variables:
		// 		struct _Rotation rot; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x800AC600
		// End Line: 2698

		/* begin block 1.2 */
			// Start line: 2713
			// Start offset: 0x800AC684
		/* end block 1.2 */
		// End offset: 0x800AC684
		// End Line: 2714

		/* begin block 1.3 */
			// Start line: 2727
			// Start offset: 0x800AC720
			// Variables:
		// 		struct evPhysicsEdgeData *EdgeData; // $s1

			/* begin block 1.3.1 */
				// Start line: 2732
				// Start offset: 0x800AC760
				// Variables:
			// 		struct SVECTOR startVec; // stack offset -56
			// 		struct SVECTOR endVec; // stack offset -48
			/* end block 1.3.1 */
			// End offset: 0x800AC7B4
			// End Line: 2740
		/* end block 1.3 */
		// End offset: 0x800AC7D4
		// End Line: 2746
	/* end block 1 */
	// End offset: 0x800AC7EC
	// End Line: 2758

	/* begin block 2 */
		// Start line: 5643
	/* end block 2 */
	// End Line: 5644

void StateHandlerBlock(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  int Data_00;
  int iVar3;
  undefined *puVar4;
  SVECTOR SStack56;
  SVECTOR SStack48;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  if (CurrentSection == 0) {
    BlockCount = BlockCount + 1;
  }
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 != (undefined *)0x4000001) {
      if ((int)puVar4 < 0x4000002) {
        if (puVar4 == (undefined *)0x0) {
          if ((CurrentSection == 0) && (iVar1 != 0x6c)) {
            Data_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
          }
        }
        else {
          if ((int)puVar4 < 1) {
            if (puVar4 != (undefined *)0x80000000) {
LAB_800ac7d4:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 == &DAT_00100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x800000;
                ControlFlag = (int)&DAT_00008009;
                PhysicsMode = 3;
                SteerSwitchMode(In->CharacterInstance,0);
                G2EmulationSwitchAnimationCharacter(In,0x51,0,10,1);
              }
              In->SectionList[CurrentSection].Data1 = 0;
            }
            else {
              if (puVar4 != &DAT_00100004) goto LAB_800ac7d4;
              COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
              BlockCount = 0;
              FX_EndPassthruFX(In->CharacterInstance);
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x4010400) {
          Data_00 = p_Var2->Data;
          if ((((*(uint *)(Data_00 + 0x20) & 0x20000) != 0) && ((Raziel.Abilities & 1U) != 0)) &&
             (Raziel.CurrentPlane == 2)) {
            PHYSICS_GenericLineCheckSetup(0,0,0,&SStack56);
            PHYSICS_GenericLineCheckSetup(0,-0x140,0,&SStack48);
            iVar3 = PHYSICS_CheckForObjectCollide(gameTrackerX.playerInstance,&SStack56,&SStack48,1)
            ;
            if ((iVar3 == 0) &&
               ((&In->CharacterInstance + CurrentSection * 0x47)[0x47] == (_Instance *)0x0)) {
              FX_StartPassthruFX(In->CharacterInstance,*(_SVector **)(Data_00 + 0xc),
                                 *(_SVector **)(Data_00 + 0x14));
              (&In->CharacterInstance + CurrentSection * 0x47)[0x47] = (_Instance *)0x1;
            }
          }
        }
        else {
          if ((int)puVar4 < 0x4010401) {
            if (puVar4 != (undefined *)0x4010200) goto LAB_800ac7d4;
          }
          else {
            if (puVar4 == (undefined *)0x8000000) {
              if (CurrentSection == 0) {
                if ((iVar1 == 0x52) || (iVar1 == 0x6c)) {
                  Data_00 = SetControlInitIdleData(0,0,3);
                  StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
                  if (iVar1 == 0x6c) {
                    razSetPlayerEventHistory(0x10000);
                  }
                }
                else {
                  if (In->SectionList[0].Data1 == 0) {
                    G2EmulationSwitchAnimationCharacter(In,0x52,0,3,1);
                    Raziel.alarmTable = 0x640;
                    (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d7124;
                  }
                  else {
                    G2EmulationSwitchAnimationCharacter(In,0x6c,0,5,1);
                    COLLIDE_SegmentCollisionOff(In->CharacterInstance,1);
                    razGetRotFromNormal(&Raziel.Senses.ForwardNormal,(_Rotation *)&SStack56);
                    (In->CharacterInstance->rotation).z = SStack56.vz;
                  }
                }
              }
            }
            else {
              if (puVar4 != (undefined *)0x8000004) goto LAB_800ac7d4;
              if ((Raziel.Senses.EngagedMask & 1) != 0) {
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
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDeCompression(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s2*/, int Data /*$s5*/)
 // line 2761, offset 0x800ac818
	/* begin block 1 */
		// Start line: 2762
		// Start offset: 0x800AC818
		// Variables:
	// 		struct __Event *Ptr; // $s1

		/* begin block 1.1 */
			// Start line: 2771
			// Start offset: 0x800AC8F0
		/* end block 1.1 */
		// End offset: 0x800ACA68
		// End Line: 2810
	/* end block 1 */
	// End offset: 0x800ACB64
	// End Line: 2850

	/* begin block 2 */
		// Start line: 5855
	/* end block 2 */
	// End Line: 5856

void StateHandlerDeCompression(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  __Event *p_Var2;
  int NewAnim;
  undefined *puVar3;
  _Instance *instance;
  code *NewProcess;
  _Instance **pp_Var4;
  
  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  In->CharacterInstance->cachedTFace = -1;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00100001) {
      if (CurrentSection == 0) {
        In->SectionList[0].Data1 = Raziel.Mode;
        ControlFlag = 0x119;
        Raziel.Mode = Raziel.Mode | 0x1000;
        PhysicsMode = 3;
        SteerSwitchMode(In->CharacterInstance,0);
        NewAnim = G2EmulationQueryAnimation(In,0);
        sVar1 = (short)NewAnim;
        if (((((Raziel.Mode & 0x20U) == 0) && (sVar1 != 0x11)) && (sVar1 != 0x12)) &&
           (sVar1 != 0x13)) {
          instance = In->CharacterInstance;
          if (instance->zVel < -0x100) goto LAB_800ac9b8;
          if (((Raziel.Mode & 0x10U) == 0) && (p_Var2->Data != 0)) {
            NewAnim = razSwitchVAnimCharacterGroup(instance,0xc,(int *)0x0,(int *)0x0);
            if (NewAnim != 0) {
              G2EmulationSwitchAnimationCharacter(In,0x1d,0,0,1);
            }
            goto LAB_800acb54;
          }
          NewAnim = razSwitchVAnimCharacterGroup(instance,0x1c,(int *)0x0,(int *)0x0);
          if (NewAnim == 0) goto LAB_800acb54;
          NewAnim = 0x25;
        }
        else {
LAB_800ac9b8:
          NewAnim = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x2c,(int *)0x0,(int *)0x0);
          if (NewAnim == 0) goto LAB_800acb54;
          NewAnim = 0x29;
        }
        G2EmulationSwitchAnimationCharacter(In,NewAnim,0,1,1);
      }
      else {
        pp_Var4[0x47] = (_Instance *)In->SectionList[CurrentSection + -1].Data1;
      }
    }
    else {
      if ((int)puVar3 < 0x100002) {
        if ((puVar3 != (undefined *)0x80000000) && (puVar3 != &DAT_80000020)) goto LAB_800acb4c;
      }
      else {
        if (puVar3 == (undefined *)0x8000000) {
          if ((*PadData & 0x100) == 0) {
            if ((*PadData & 0x8000000fU) == 0) {
              NewAnim = SetControlInitIdleData(0,0,4);
              StateSwitchStateData(In,CurrentSection,StateHandlerIdle,NewAnim);
              Raziel.Mode = 1;
            }
            else {
              if (CurrentSection == 0) {
                NewAnim = G2EmulationQueryAnimation(In,0);
                if (NewAnim != 0x1d) {
                  StateSwitchStateCharacterData(In,StateHandlerStartMove,5);
                  pp_Var4[0x47] = (_Instance *)0x0;
                  goto LAB_800acb54;
                }
                NewProcess = StateHandlerMove;
                goto LAB_800acaf0;
              }
            }
          }
          else {
            if (CurrentSection == 0) {
              NewProcess = StateHandlerCrouch;
LAB_800acaf0:
              StateSwitchStateCharacterData(In,NewProcess,0);
              pp_Var4[0x47] = (_Instance *)0x0;
              goto LAB_800acb54;
            }
          }
          pp_Var4[0x47] = (_Instance *)0x0;
        }
        else {
          if ((int)puVar3 < 0x8000001) {
            if (puVar3 == &DAT_00100004) {
              SetPhysics(In->CharacterInstance,-0x10,0,0,0);
            }
            else {
LAB_800acb4c:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar3 != (undefined *)0x10000000) goto LAB_800acb4c;
          }
        }
      }
    }
LAB_800acb54:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*$fp*/)
 // line 2855, offset 0x800acb88
	/* begin block 1 */
		// Start line: 2856
		// Start offset: 0x800ACB88
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Frame; // $s7
	// 		int Anim; // $s5
	// 		int moving; // $s6

		/* begin block 1.1 */
			// Start line: 2975
			// Start offset: 0x800AD100
			// Variables:
		// 		struct evObjectDraftData *draft; // $a2
		/* end block 1.1 */
		// End offset: 0x800AD158
		// End Line: 2982

		/* begin block 1.2 */
			// Start line: 2987
			// Start offset: 0x800AD180
			// Variables:
		// 		struct evPhysicsSwimData *SwimData; // $v0
		/* end block 1.2 */
		// End offset: 0x800AD210
		// End Line: 3000
	/* end block 1 */
	// End offset: 0x800AD2C4
	// End Line: 3053

	/* begin block 2 */
		// Start line: 6069
	/* end block 2 */
	// End Line: 6070

void StateHandlerGlide(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  undefined *puVar2;
  int local_38;
  int iVar3;
  __Event *p_Var4;
  undefined *puVar5;
  uint uVar6;
  code *NewProcess;
  short z;
  _Instance **pp_Var7;
  __State *p_Var8;
  int local_34;
  
  bVar1 = false;
  local_38 = G2EmulationQueryAnimation(In,CurrentSection);
  iVar3 = G2EmulationQueryFrame(In,CurrentSection);
  if (CurrentSection == 0) {
    In->SectionList[0].Data2 = In->SectionList[0].Data2 & 0xfffffffd;
  }
  p_Var8 = In->SectionList + CurrentSection;
  pp_Var7 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var4 = PeekMessageQueue(&p_Var8->Event);
    if (p_Var4 == (__Event *)0x0) {
      if ((CurrentSection == 0) && (uVar6 = In->SectionList[0].Data2, (uVar6 & 1) != 0)) {
        if ((uVar6 & 2) == 0) {
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
    puVar5 = (undefined *)p_Var4->ID;
    if (puVar5 != (undefined *)0x4000001) {
      if ((int)puVar5 < 0x4000002) {
        if (puVar5 != &DAT_80000020) {
          if ((int)puVar5 < -0x7fffffdf) {
            if (puVar5 == &DAT_80000004) {
              if (CurrentSection == 1) {
                SetExternalTransitionForce(&ExternalForces,In->CharacterInstance,4,0,0x18,-0x18);
              }
              G2EmulationSwitchAnimation(In,CurrentSection,0x11,0,5,2);
              pp_Var7[0x47] = (_Instance *)0x0;
              if (((uint)pp_Var7[0x48] & 1) != 0) {
                razSetPlayerEventHistory(0x4000);
              }
            }
            else {
              if ((int)puVar5 < -0x7ffffffb) {
                if (puVar5 != (undefined *)0x80000000) goto LAB_800ad210;
              }
              else {
                puVar2 = &DAT_80000008;
joined_r0x800accac:
                if (puVar5 != puVar2) goto LAB_800ad210;
              }
            }
          }
          else {
            if (puVar5 == &DAT_00100001) {
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
              pp_Var7[0x47] = (_Instance *)0x1;
              pp_Var7[0x48] = (_Instance *)0x0;
              G2EmulationSwitchAnimation(In,CurrentSection,0x10,p_Var4->Data,5,1);
            }
            else {
              if ((int)puVar5 < 0x100002) {
                puVar2 = &DAT_00040005;
                goto joined_r0x800accac;
              }
              if (puVar5 == &DAT_00100004) {
                if (CurrentSection == 0) {
                  InitAlgorithmicWings(In->CharacterInstance);
                  In->SectionList[0].Data2 = 0;
                }
              }
              else {
                if (puVar5 != (undefined *)0x1000001) goto LAB_800ad210;
              }
            }
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x8000000) {
          if (pp_Var7[0x47] != (_Instance *)0x0) {
            G2EmulationSwitchAnimationAlpha(In,CurrentSection,0x12,0,5,2,4);
            pp_Var7[0x47] = (_Instance *)0x0;
          }
        }
        else {
          if ((int)puVar5 < 0x8000001) {
            if (puVar5 == (undefined *)0x4010008) {
              NewProcess = StateHandlerDeCompression;
LAB_800ad200:
              StateSwitchStateData(In,CurrentSection,NewProcess,0);
            }
            else {
              if ((int)puVar5 < 0x4010009) {
                if (puVar5 == (undefined *)0x4000007) {
                  if (CurrentSection == 0) {
                    if ((int)(uint)(ushort)((short *)p_Var4->Data)[4] < In->CharacterInstance->zVel)
                    {
                      z = 0;
                      local_34 = 0;
                    }
                    else {
                      z = *(short *)p_Var4->Data;
                      local_34 = 0xffc;
                    }
                    SetExternalForce(&__Force_800d728c,0,0,z,0,local_34);
                    pp_Var7[0x48] = (_Instance *)((uint)pp_Var7[0x48] | 3);
                    Raziel.playerEvent = Raziel.playerEvent | 0x4000;
                  }
                }
                else {
LAB_800ad210:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar5 != (undefined *)0x4020000) goto LAB_800ad210;
                z = *(short *)(p_Var4->Data + 0xe);
                if (((z < 0) && (z != -0x7fff)) && (Raziel.CurrentPlane == 1)) {
                  if (CurrentSection == 0) {
                    SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                  }
                  G2EmulationSwitchAnimation(In,CurrentSection,0x13,0,4,1);
                  NewProcess = StateHandlerFall;
                  goto LAB_800ad200;
                }
              }
            }
          }
          else {
            if (puVar5 == (undefined *)0x10000000) {
              bVar1 = true;
              if (local_38 != 0x10) {
                if (0 < Raziel.Bearing) {
                  G2EmulationSwitchAnimation(In,CurrentSection,0x2b,0,6,1);
                  pp_Var7[0x47] = (_Instance *)0x2;
                }
                if (Raziel.Bearing < 0) {
                  G2EmulationSwitchAnimation(In,CurrentSection,0x2c,0,6,1);
                  pp_Var7[0x47] = (_Instance *)0x2;
                }
                bVar1 = true;
                if ((Raziel.Bearing == 0) && (pp_Var7[0x47] == (_Instance *)0x2)) {
                  G2EmulationSwitchAnimation(In,CurrentSection,0x12,0,5,2);
                  pp_Var7[0x47] = (_Instance *)0x0;
                  bVar1 = true;
                }
              }
            }
            else {
              if ((int)puVar5 < 0x10000001) {
                if (puVar5 != (undefined *)0x8000003) goto LAB_800ad210;
                if (local_38 == 0x10) {
                  SetPhysics(In->CharacterInstance,0,0,0x34,-0x18);
                }
              }
              else {
                if (puVar5 == (undefined *)0x20000001) {
                  if (((iVar3 < 0xd) && (local_38 == 0x10)) || ((*PadData & 0x80) != 0)) {
                    EnMessageQueueData(&p_Var8->Defer,0x20000001,0);
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
                  if (puVar5 != (undefined *)0x20000004) goto LAB_800ad210;
                  if (CurrentSection == 0) {
                    SetExternalTransitionForce(&ExternalForces,In->CharacterInstance,4,0,0x34,-0x18)
                    ;
                  }
                  G2EmulationSwitchAnimation(In,CurrentSection,0x12,0,5,2);
                  pp_Var7[0x47] = (_Instance *)0x0;
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var8->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerHang(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
 // line 3056, offset 0x800ad2f4
	/* begin block 1 */
		// Start line: 3057
		// Start offset: 0x800AD2F4
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s7

		/* begin block 1.1 */
			// Start line: 3069
			// Start offset: 0x800AD4B4
			// Variables:
		// 		struct evControlInitHangData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x800AD5C8
		// End Line: 3099
	/* end block 1 */
	// End offset: 0x800AD868
	// End Line: 3210

	/* begin block 2 */
		// Start line: 6484
	/* end block 2 */
	// End Line: 6485

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
                if (puVar3 != (undefined *)0x80000000) goto LAB_800ad850;
              }
              else {
                if (puVar3 != &DAT_80000020) goto LAB_800ad850;
              }
            }
          }
          else {
            if (puVar3 == &DAT_00100004) {
              if (CurrentSection == 0) {
                Raziel.attachedPlatform = (_Instance *)0x0;
                ControlFlag = ControlFlag & 0xfffffbff;
                In->CharacterInstance->attachedID = 0;
              }
              In->CharacterInstance->flags2 = In->CharacterInstance->flags2 | 0x40;
            }
            else {
              if ((int)puVar3 < 0x100005) {
                if (puVar3 != &DAT_00100001) goto LAB_800ad850;
                Frames = (_Instance *)p_Var2->Data;
                if (CurrentSection == 0) {
                  if ((Raziel.Mode & 0x40000U) != 0) {
                    CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
                  }
                  p_Var4 = In->CharacterInstance;
                  In->SectionList[0].Data2 = In->CharacterInstance->attachedID;
                  ControlFlag = 0x8001501;
                  if (p_Var4->attachedID == 0) {
                    ControlFlag = 0xc001501;
                  }
                  In->CharacterInstance->attachedID = 0;
                  Raziel.Mode = 0x100;
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
                PhysicsMode = 3;
                SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                In->CharacterInstance->flags2 = In->CharacterInstance->flags2 & 0xffffffbf;
              }
              else {
                if (puVar3 != &DAT_00100014) goto LAB_800ad850;
LAB_800ad7e4:
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
LAB_800ad850:
                DefaultStateHandler(In,CurrentSection,Data);
              }
            }
            else {
              if (puVar3 != (undefined *)0x4010010) goto LAB_800ad850;
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
              if (puVar3 != (undefined *)0x8000000) goto LAB_800ad850;
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
                if (puVar3 != (undefined *)0x10000000) goto LAB_800ad850;
                CurrentSection_00 = p_Var2->Data;
                if (CurrentSection_00 == 0x10000003) {
                  if (iVar1 == 6) goto LAB_800ad7e4;
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
 // line 3213, offset 0x800ad898
	/* begin block 1 */
		// Start line: 3214
		// Start offset: 0x800AD898
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3266
			// Start offset: 0x800ADB2C
			// Variables:
		// 		struct evObjectData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x800ADB84
		// End Line: 3275
	/* end block 1 */
	// End offset: 0x800ADBA0
	// End Line: 3285

	/* begin block 2 */
		// Start line: 6808
	/* end block 2 */
	// End Line: 6809

	/* begin block 3 */
		// Start line: 6811
	/* end block 3 */
	// End Line: 6812

void StateHandlerPushObject(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int CurrentSection_00;
  undefined *puVar2;
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
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001) {
      if (CurrentSection == 0) {
        Raziel.Mode = 0x400;
        ControlFlag = 0x8001108;
        PhysicsMode = 3;
        SteerSwitchMode(In->CharacterInstance,0);
        razCenterWithBlock(In->CharacterInstance,(Raziel.Senses.EngagedList)->instance,-0x8d);
      }
      In->SectionList[CurrentSection].Data1 = 0;
      razSetPlayerEventHistory(1);
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 != &DAT_80000008) {
          if (puVar2 != (undefined *)0x100000) goto LAB_800adb88;
          CurrentSection_00 = SetControlInitIdleData(0,0,6);
          StateSwitchStateData(In,CurrentSection,StateHandlerIdle,CurrentSection_00);
        }
      }
      else {
        if ((int)puVar2 < 0x8000000) {
LAB_800adb88:
          DefaultStateHandler(In,CurrentSection,Data);
        }
        else {
          if ((int)puVar2 < 0x8000002) {
            if (((*PadData & 0x20) == 0) || ((Raziel.Senses.EngagedMask & 2) == 0)) {
              if (In->SectionList[CurrentSection].Data1 == 0) {
                if (CurrentSection == 2) {
                  NewAnim = 0;
                  CurrentSection_00 = 2;
                  local_24 = CurrentSection;
                }
                else {
                  NewAnim = 0x17;
                  local_24 = 1;
                  CurrentSection_00 = CurrentSection;
                }
                G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,3,local_24);
                In->SectionList[CurrentSection].Data1 = 1;
                if (CurrentSection == 0) {
                  Raziel.alarmTable = 400;
                  (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d7124;
                }
              }
              else {
                CurrentSection_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,CurrentSection_00);
                ControlFlag = ControlFlag | 1;
              }
            }
            else {
              StateSwitchStateData(In,CurrentSection,StateHandlerDragObject,0);
            }
          }
          else {
            if (puVar2 != (undefined *)0x8000004) goto LAB_800adb88;
            CurrentSection_00 =
                 SetObjectData(-(int)Raziel.Senses.ForwardNormal.x,
                               -(int)Raziel.Senses.ForwardNormal.y,6,(_Instance *)0x0,0);
            INSTANCE_Post((Raziel.Senses.EngagedList)->instance,0x800000,CurrentSection_00);
            if (*(int *)(CurrentSection_00 + 0xc) == 0) {
              INSTANCE_Post(In->CharacterInstance,0x100000,0);
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
// void /*$ra*/ StateHandlerBreakOff(struct __CharacterState *In /*$s3*/, int CurrentSection /*$s4*/, int Data /*$s7*/)
 // line 3288, offset 0x800adbc4
	/* begin block 1 */
		// Start line: 3289
		// Start offset: 0x800ADBC4
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3296
			// Start offset: 0x800ADCBC
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $s0
		// 		struct _Instance *Inst; // $s1
		// 		int anim; // $a2
		/* end block 1.1 */
		// End offset: 0x800ADE44
		// End Line: 3345

		/* begin block 1.2 */
			// Start line: 3359
			// Start offset: 0x800ADE9C
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $v0
		// 		int action; // $s1
		// 		int condition; // $v0
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x800ADF44
		// End Line: 3390
	/* end block 1 */
	// End offset: 0x800ADF90
	// End Line: 3405

	/* begin block 2 */
		// Start line: 6969
	/* end block 2 */
	// End Line: 6970

void StateHandlerBreakOff(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  __Event *p_Var4;
  ulong uVar5;
  undefined *puVar6;
  uint local_38;
  short distance;
  _Instance *p_Var7;
  _Instance *force;
  _Instance **pp_Var8;
  int local_34;
  
  pp_Var8 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var4 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var4 == (__Event *)0x0) {
      return;
    }
    puVar6 = (undefined *)p_Var4->ID;
    if (puVar6 == &DAT_00100015) {
      if (CurrentSection == 0) {
        local_34 = SetControlInitIdleData(0,0,3);
        StateSwitchStateCharacterData(In,StateHandlerIdle,local_34);
LAB_800ade9c:
        uVar5 = INSTANCE_Query(pp_Var8[0x48],0x15);
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
        INSTANCE_Post(pp_Var8[0x48],0x800023,local_34);
      }
      goto LAB_800adf80;
    }
    if (0x100015 < (int)puVar6) {
      if (0x7ffffff < (int)puVar6) {
        if ((int)puVar6 < 0x8000002) {
          local_34 = SetControlInitIdleData(0,0,3);
          StateSwitchStateData(In,CurrentSection,StateHandlerIdle,local_34);
          goto LAB_800adf80;
        }
        if (puVar6 == (undefined *)0x8000004) goto LAB_800ade9c;
      }
      goto LAB_800adf78;
    }
    if (puVar6 == &DAT_00100001) {
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
          pp_Var8[0x48] = force;
        }
        else {
          bVar1 = *(byte *)(uVar5 + 0x12);
          pp_Var8[0x48] = force;
        }
        if (bVar1 == 0xff) {
          SetTimer((uint)*(byte *)(uVar5 + 0x14) + 1);
        }
        else {
          G2EmulationInstanceToInstanceSwitchAnimationCharacter
                    (In->CharacterInstance,force,(uint)bVar1,0,0,1);
          bVar1 = *(byte *)(uVar5 + 0x14);
          if (bVar1 != 0xff) {
            Raziel.alarmTable = ((ushort)bVar1 * 0x10 + (ushort)bVar1 * 8 + (ushort)bVar1) * 4;
            (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d7124;
          }
        }
        uVar2 = *(ushort *)(uVar5 + 0x1c);
        local_38 = (uint)uVar2;
        ControlFlag = 0x8041108;
        PhysicsMode = 3;
        if (uVar2 == 1) {
          distance = *(short *)(uVar5 + 0x16);
          p_Var7 = In->CharacterInstance;
          local_34 = 0;
LAB_800ade54:
          razAlignYMoveRot(force,-distance,&p_Var7->position,&p_Var7->rotation,local_34);
        }
        else {
          if (uVar2 < 2) {
            if (uVar2 == 0) {
              distance = *(short *)(uVar5 + 0x16);
              local_38 = 3;
              local_34 = 0;
LAB_800ade30:
              razAlignYRotMoveInterp(In->CharacterInstance,force,distance,'\0',local_38,local_34);
            }
          }
          else {
            if (uVar2 == 3) {
              distance = *(short *)(uVar5 + 0x16);
              local_34 = 0x800;
              goto LAB_800ade30;
            }
            if (uVar2 == 4) {
              distance = *(short *)(uVar5 + 0x16);
              p_Var7 = In->CharacterInstance;
              local_34 = 0x800;
              goto LAB_800ade54;
            }
          }
        }
      }
    }
    else {
      if ((int)puVar6 < 0x100002) {
        if (puVar6 != (undefined *)0x80000000) {
LAB_800adf78:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar6 != &DAT_00100004) goto LAB_800adf78;
      }
    }
LAB_800adf80:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPullSwitch(struct __CharacterState *In /*$s4*/, int CurrentSection /*$s5*/, int Data /*stack 8*/)
 // line 3408, offset 0x800adfbc
	/* begin block 1 */
		// Start line: 3409
		// Start offset: 0x800ADFBC
		// Variables:
	// 		struct __Event *Ptr; // $s2
	// 		int switchDone; // stack offset -56
	// 		int hitPosted; // stack offset -52

		/* begin block 1.1 */
			// Start line: 3421
			// Start offset: 0x800AE0F4
			// Variables:
		// 		struct PhysObSwitchProperties *switchData; // $fp

			/* begin block 1.1.1 */
				// Start line: 3427
				// Start offset: 0x800AE124
				// Variables:
			// 		int switchStatus; // $s1
			// 		int switchSuccess; // $s3
			// 		struct _Instance *inst; // $s2
			// 		struct PhysObSwitchProperties *switchProperties; // $s0
			// 		int extraZ; // $s6

				/* begin block 1.1.1.1 */
					// Start line: 3440
					// Start offset: 0x800AE178
				/* end block 1.1.1.1 */
				// End offset: 0x800AE1D0
				// End Line: 3452
			/* end block 1.1.1 */
			// End offset: 0x800AE2FC
			// End Line: 3501
		/* end block 1.1 */
		// End offset: 0x800AE2FC
		// End Line: 3501

		/* begin block 1.2 */
			// Start line: 3507
			// Start offset: 0x800AE30C
			// Variables:
		// 		int switchStatus; // $v1
		// 		struct _Instance *inst; // $s0
		// 		struct PhysObSwitchProperties *switchProperties; // $s0
		// 		int switchClass; // $s1
		/* end block 1.2 */
		// End offset: 0x800AE490
		// End Line: 3548

		/* begin block 1.3 */
			// Start line: 3560
			// Start offset: 0x800AE508
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.3 */
		// End offset: 0x800AE570
		// End Line: 3571
	/* end block 1 */
	// End offset: 0x800AE59C
	// End Line: 3591

	/* begin block 2 */
		// Start line: 7223
	/* end block 2 */
	// End Line: 7224

/* WARNING: Type propagation algorithm not settling */

void StateHandlerPullSwitch(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  __Event *p_Var6;
  ulong uVar7;
  ulong Data_00;
  ulong uVar8;
  ulong uVar9;
  int Data_01;
  undefined *puVar10;
  uint NewAnim;
  _Instance *Inst;
  short sVar11;
  __State *p_Var12;
  
  bVar3 = false;
  bVar4 = false;
  G2EmulationQueryAnimation(In,CurrentSection);
  p_Var12 = In->SectionList + CurrentSection;
  do {
    p_Var6 = PeekMessageQueue(&p_Var12->Event);
    if (p_Var6 == (__Event *)0x0) {
      if (CurrentSection == 0) {
        razApplyMotion(In,0);
      }
      return;
    }
    puVar10 = (undefined *)p_Var6->ID;
    if (puVar10 == (undefined *)0x100000) {
      Inst = Raziel.Senses.EngagedList[3].instance;
      uVar7 = INSTANCE_Query(Inst,4);
      Data_00 = INSTANCE_Query(Raziel.Senses.EngagedList[3].instance,0x17);
      uVar8 = INSTANCE_Query(Inst,5);
      if (uVar7 == 6) {
        bVar3 = true;
        if (((*PadData & 0x20) == 0) || (p_Var6->Data != 0)) {
          Data_01 = SetControlInitIdleData(0,0,3);
          StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_01);
          ControlFlag = ControlFlag | 1;
          if (CurrentSection == 0) {
            INSTANCE_Post(Raziel.Senses.EngagedList[3].instance,0x800020,0);
          }
        }
        else {
LAB_800ae4f4:
          EnMessageQueueData(&p_Var12->Defer,0x100000,0);
        }
      }
      else {
        if (uVar7 == 9) {
          if ((uVar8 & 1) == 0) {
            bVar1 = *(byte *)(Data_00 + 0x12);
          }
          else {
            bVar1 = *(byte *)(Data_00 + 0x11);
          }
          SetTimer((uint)bVar1 + 6);
          G2EmulationSwitchAnimation(In,CurrentSection,0x7b,0,6,2);
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
      if ((int)puVar10 < 0x100001) {
        if (puVar10 != &DAT_80000008) {
          if ((int)puVar10 < -0x7ffffff7) {
            if (puVar10 != (undefined *)0x80000000) {
LAB_800ae570:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if ((puVar10 != &DAT_80000010) && (puVar10 != &DAT_80000020)) goto LAB_800ae570;
          }
        }
      }
      else {
        if (puVar10 == (undefined *)0x1000000) {
          Inst = (_Instance *)p_Var6->Data;
          if (bVar3) {
            EnMessageQueueData(&p_Var12->Event,0x100000,1);
          }
          if (!bVar4) {
            bVar4 = true;
            Data_01 = SetMonsterHitData(*(_Instance **)&Inst->node,
                                        *(_Instance **)((int)&Inst->node + 4),(int)Inst->prev,
                                        (int)*(short *)&Inst->next,
                                        (int)*(short *)((int)&Inst->next + 2));
            EnMessageQueueData(&p_Var12->Defer,0x1000000,Data_01);
          }
        }
        else {
          if ((int)puVar10 < 0x1000001) {
            if (puVar10 == &DAT_00100001) {
              if (CurrentSection == 0) {
                ControlFlag = 0x9041108;
                PhysicsMode = 3;
                SteerSwitchMode(In->CharacterInstance,0);
                bVar2 = true;
                if ((Raziel.Senses.EngagedMask & 8) != 0) {
                  sVar11 = 0;
                  Inst = Raziel.Senses.EngagedList[3].instance;
                  uVar7 = INSTANCE_Query(Inst,0x17);
                  Data_00 = INSTANCE_Query(Inst,5);
                  uVar8 = INSTANCE_Query(Inst,0x1c);
                  uVar9 = INSTANCE_Query(Inst,4);
                  if (uVar9 == 9) {
                    uVar5 = MON_FacingOffset(In->CharacterInstance,Inst);
                    uVar5 = uVar5 & 0xfff;
                    if (0x800 < uVar5) {
                      uVar5 = uVar5 | 0xf000;
                    }
                    if ((ushort)(uVar5 + 0x400) < 0x801) {
                      Data_00 = Data_00 & 0xfffffffe;
                      sVar11 = 0;
                    }
                    else {
                      Data_00 = Data_00 | 1;
                      sVar11 = 0x800;
                    }
                    INSTANCE_Post(Inst,0x80002a,Data_00);
                  }
                  if ((Data_00 & 1) == 0) {
                    if ((Data_00 & 2) == 0) {
                      if (*(char *)(uVar7 + 0x16) != -1) {
                        NewAnim = (uint)*(byte *)(uVar7 + 0x16);
                        goto LAB_800ae260;
                      }
                      goto LAB_800ae250;
                    }
                    if (*(char *)(uVar7 + 0x14) == -1) goto LAB_800ae250;
                    NewAnim = (uint)*(byte *)(uVar7 + 0x14);
LAB_800ae260:
                    G2EmulationInstanceToInstanceSwitchAnimationCharacter
                              (In->CharacterInstance,Raziel.Senses.EngagedList[3].instance,NewAnim,0
                               ,0,1);
                  }
                  else {
                    if ((Data_00 & 2) == 0) {
                      if (*(char *)(uVar7 + 0x17) != -1) {
                        NewAnim = (uint)*(byte *)(uVar7 + 0x17);
                        goto LAB_800ae260;
                      }
                    }
                    else {
                      if (*(char *)(uVar7 + 0x15) != -1) {
                        NewAnim = (uint)*(byte *)(uVar7 + 0x15);
                        goto LAB_800ae260;
                      }
                    }
LAB_800ae250:
                    bVar2 = false;
                  }
                  if (bVar2) {
                    razAlignYMoveRot(Raziel.Senses.EngagedList[3].instance,*(short *)(uVar8 + 8),
                                     &In->CharacterInstance->position,
                                     &In->CharacterInstance->rotation,(int)sVar11);
                    INSTANCE_Post(Raziel.Senses.EngagedList[3].instance,0x800020,0);
                    uVar7 = INSTANCE_Query(Inst,4);
                    if (uVar7 == 9) {
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
              if (puVar10 != &DAT_00100015) goto LAB_800ae570;
              Data_01 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_01);
            }
          }
          else {
            if (puVar10 != (undefined *)0x1000001) {
              if (puVar10 != (undefined *)0x8000000) goto LAB_800ae570;
              if (CurrentSection != 2) goto LAB_800ae4f4;
              G2EmulationSwitchAnimation(In,2,0,0,3,2);
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var12->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDragObject(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s4*/, int Data /*$fp*/)
 // line 3594, offset 0x800ae5cc
	/* begin block 1 */
		// Start line: 3595
		// Start offset: 0x800AE5CC
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		struct _Instance *instance; // $s3
	// 		int anim; // $s0
	// 		int hitPosted; // $s7

		/* begin block 1.1 */
			// Start line: 3638
			// Start offset: 0x800AE7D8
			// Variables:
		// 		struct evPhysicsSlideData *slideData; // stack offset -48

			/* begin block 1.1.1 */
				// Start line: 3643
				// Start offset: 0x800AE7F4
				// Variables:
			// 		struct evObjectData *data; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800AEAE0
			// End Line: 3700
		/* end block 1.1 */
		// End offset: 0x800AEAE0
		// End Line: 3701

		/* begin block 1.2 */
			// Start line: 3757
			// Start offset: 0x800AEC68
			// Variables:
		// 		struct evMonsterHitData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x800AEC68
		// End Line: 3758
	/* end block 1 */
	// End offset: 0x800AECC4
	// End Line: 3772

	/* begin block 2 */
		// Start line: 7603
	/* end block 2 */
	// End Line: 7604

	/* begin block 3 */
		// Start line: 7609
	/* end block 3 */
	// End Line: 7610

/* WARNING: Type propagation algorithm not settling */

void StateHandlerDragObject(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  int Data_00;
  uint uVar3;
  int local_34;
  _Instance *p_Var4;
  undefined *puVar5;
  int NewAnim;
  _Instance *Inst;
  __State *p_Var6;
  int local_38;
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
  p_Var6 = In->SectionList + CurrentSection;
  do {
    p_Var2 = PeekMessageQueue(&p_Var6->Event);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
    puVar5 = (undefined *)p_Var2->ID;
    if (puVar5 == (undefined *)0x100000) {
LAB_800aec0c:
      Data_00 = SetControlInitIdleData(0,0,3);
      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
    }
    else {
      if ((int)puVar5 < 0x100001) {
        if (puVar5 != &DAT_80000008) {
          if ((int)puVar5 < -0x7ffffff7) {
            if (-0x7fffffff < (int)puVar5) {
LAB_800aecac:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if ((puVar5 != &DAT_80000010) && (puVar5 != &DAT_80000020)) goto LAB_800aecac;
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x8000000) {
          if (Data_00 == 0x17) {
            local_34 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,local_34);
          }
          if (Inst == (_Instance *)0x0) goto LAB_800aec0c;
          if (CurrentSection == 0) {
            INSTANCE_Post(Inst,0x800004,0);
            ControlFlag = ControlFlag | 8;
            if (((Data_00 != 0) && (Data_00 != 0x16)) && (Data_00 != 0x14)) {
              razCenterWithBlock(In->CharacterInstance,Inst,-0x8d);
            }
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
LAB_800aebd8:
          if ((*PadData & 0x20) == 0) {
            EnMessageQueueData(&p_Var6->Event,0x100000,0);
          }
        }
        else {
          if ((int)puVar5 < 0x8000001) {
            if (puVar5 == &DAT_00100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x400;
                ControlFlag = 0x9001508;
                PhysicsMode = 3;
                SteerSwitchMode(In->CharacterInstance,0);
              }
              G2EmulationSwitchAnimation(In,CurrentSection,0x14,0,3,1);
            }
            else {
              if (puVar5 != (undefined *)0x1000000) goto LAB_800aecac;
              if (CurrentSection == 0) {
                if (Data_00 == 0x16) {
                  StateSwitchStateCharacterData(In,StateHandlerHitReaction,p_Var2->Data);
                }
                else {
                  if (!bVar1) {
                    p_Var4 = (_Instance *)p_Var2->Data;
                    bVar1 = true;
                    Data_00 = SetMonsterHitData(*(_Instance **)&p_Var4->node,
                                                *(_Instance **)((int)&p_Var4->node + 4),
                                                (int)p_Var4->prev,(int)*(short *)&p_Var4->next,
                                                (int)*(short *)((int)&p_Var4->next + 2));
                    EnMessageQueueData(&In->SectionList[0].Defer,0x1000000,Data_00);
                  }
                }
              }
            }
          }
          else {
            if (puVar5 == (undefined *)0x10000000) {
              if (CurrentSection == 0) {
                gameTrackerX.raziel_collide_override = '\x01';
                if (((Data_00 == 0) || (Data_00 == 0x16)) && (Inst != (_Instance *)0x0)) {
                  Data_00 = p_Var2->Data;
                  if (Data_00 == 0x10000002) {
                    uVar3 = PHYSOB_CheckSlideNormal
                                      (In->CharacterInstance,-(int)Raziel.Senses.ForwardNormal.y,
                                       (int)Raziel.Senses.ForwardNormal.x,apeStack48);
                    if ((uVar3 & 0x4002) == 0x4000) {
                      Data_00 = SetObjectData(-(int)Raziel.Senses.ForwardNormal.y,
                                              (int)Raziel.Senses.ForwardNormal.x,2,(_Instance *)0x0,
                                              0);
                      INSTANCE_Post(Inst,0x800000,Data_00);
                      if ((*(uint *)(Data_00 + 0xc) & 4) != 0) {
                        Data_00 = 0x1e;
LAB_800aeac0:
                        G2EmulationSwitchAnimationCharacter(In,Data_00,0,0,1);
                        ControlFlag = ControlFlag & 0xfffffff7;
                      }
                    }
                  }
                  else {
                    if (Data_00 < 0x10000003) {
                      if (Data_00 == 0x10000001) {
                        gameTrackerX.raziel_collide_override = '\0';
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
LAB_800ae9d0:
                          G2EmulationSwitchAnimation(In,1,Data_00,0,0,1);
                        }
                      }
                    }
                    else {
                      if (Data_00 == 0x10000003) {
                        uVar3 = PHYSOB_CheckSlideNormal
                                          (In->CharacterInstance,(int)Raziel.Senses.ForwardNormal.x,
                                           (int)Raziel.Senses.ForwardNormal.y,apeStack48);
                        if ((uVar3 & 0x4002) == 0x4000) {
                          Data_00 = SetObjectData((int)Raziel.Senses.ForwardNormal.x,
                                                  (int)Raziel.Senses.ForwardNormal.y,4,
                                                  (_Instance *)0x0,0);
                          INSTANCE_Post(Inst,0x800000,Data_00);
                          if ((*(uint *)(Data_00 + 0xc) & 4) != 0) {
                            G2EmulationSwitchAnimation(In,2,0,0,3,2);
                            G2EmulationSwitchAnimation(In,0,0x1f,0,0,1);
                            Data_00 = 0x1f;
                            goto LAB_800ae9d0;
                          }
                        }
                      }
                      else {
                        if ((Data_00 == 0x10000004) &&
                           (uVar3 = PHYSOB_CheckSlideNormal
                                              (In->CharacterInstance,
                                               (int)Raziel.Senses.ForwardNormal.y,
                                               -(int)Raziel.Senses.ForwardNormal.x,apeStack48),
                           (uVar3 & 0x4002) == 0x4000)) {
                          Data_00 = SetObjectData((int)Raziel.Senses.ForwardNormal.y,
                                                  -(int)Raziel.Senses.ForwardNormal.x,3,
                                                  (_Instance *)0x0,0);
                          INSTANCE_Post(Inst,0x800000,Data_00);
                          if ((*(uint *)(Data_00 + 0xc) & 4) != 0) {
                            Data_00 = 0x2d;
                            goto LAB_800aeac0;
                          }
                        }
                      }
                    }
                  }
                }
                gameTrackerX.raziel_collide_override = '\0';
              }
            }
            else {
              if ((int)puVar5 < 0x10000001) {
                if (puVar5 != (undefined *)0x8000001) goto LAB_800aecac;
                if (((Data_00 == 0) || (Data_00 == 0x16)) || (Data_00 == 0x14)) goto LAB_800aebd8;
              }
              else {
                if (puVar5 != (undefined *)0x20000000) goto LAB_800aecac;
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
// void /*$ra*/ StateHandlerPickupObject(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s4*/)
 // line 3775, offset 0x800aecf4
	/* begin block 1 */
		// Start line: 3776
		// Start offset: 0x800AECF4
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3784
			// Start offset: 0x800AEDAC
			// Variables:
		// 		long colorArray[1]; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x800AEDAC
		// End Line: 3784
	/* end block 1 */
	// End offset: 0x800AEEF0
	// End Line: 3832

	/* begin block 2 */
		// Start line: 7982
	/* end block 2 */
	// End Line: 7983

void StateHandlerPickupObject(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  code *NewProcess;
  int Data_00;
  long local_20 [2];
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001) {
      if (CurrentSection == 1) {
        local_20[0] = 0xff5400;
        ControlFlag = (int)&DAT_00001108;
        Raziel.Mode = Raziel.Mode | 0x800;
        Raziel.Senses.Flags = Raziel.Senses.Flags | 0x80;
        PhysicsMode = 3;
        FX_DoInstanceOneSegmentGlowWithTime(In->CharacterInstance,0x29,local_20,1,0,0x4b,0x4b,10);
        razSetPlayerEventHistory(0x10);
      }
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if ((puVar2 != (undefined *)0x80000000) && (puVar2 != &DAT_80000020)) {
LAB_800aeed8:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar2 == &DAT_00100004) {
          if (CurrentSection == 1) {
            ControlFlag = ControlFlag & 0xffffefff;
            FX_StopAllGlowEffects(In->CharacterInstance,0);
          }
        }
        else {
          if (puVar2 != (undefined *)0x8000000) goto LAB_800aeed8;
          if (CurrentSection == 1) {
            FX_StopAllGlowEffects(In->CharacterInstance,0);
          }
          if ((Raziel.Mode & 0x40000U) == 0) {
            if ((Raziel.returnState != StateHandlerIdle) &&
               (NewProcess = Raziel.returnState, Raziel.returnState != (_func_60 *)0x0))
            goto LAB_800aeec0;
            Data_00 = SetControlInitIdleData(0,0,3);
            NewProcess = StateHandlerIdle;
          }
          else {
            NewProcess = StateHandlerSwim;
LAB_800aeec0:
            Data_00 = 0;
          }
          StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
          Raziel.returnState = (_func_60 *)0x0;
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerAutoFace(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*stack 8*/)
 // line 3832, offset 0x800aef10
	/* begin block 1 */
		// Start line: 3833
		// Start offset: 0x800AEF10
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Frames; // $s3
	// 		int Anim; // $s2
	/* end block 1 */
	// End offset: 0x800AF620
	// End Line: 4039

	/* begin block 2 */
		// Start line: 8125
	/* end block 2 */
	// End Line: 8126

void StateHandlerAutoFace(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  int local_30;
  undefined *puVar3;
  uint uVar4;
  int NewAnim;
  code *NewProcess;
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
      if ((Raziel.nothingCounter == 6) || ((Raziel.Senses.EngagedMask & 0x40) == 0)) {
        EnMessageQueueData(&In->SectionList[CurrentSection].Event,0x100000,0);
      }
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00100004) {
      if (CurrentSection == 0) {
LAB_800af198:
        razResetPauseTranslation(In->CharacterInstance);
      }
    }
    else {
      local_30 = CurrentSection;
      if ((int)puVar3 < 0x100005) {
        if (puVar3 == &DAT_80000002) {
          if (Raziel.Senses.heldClass != 3) {
            Raziel.returnState = StateHandlerIdle;
            NewProcess = StateHandlerSoulSuck;
            goto LAB_800af578;
          }
        }
        else {
          if ((int)puVar3 < -0x7ffffffd) {
            if (puVar3 == (undefined *)0x80000000) {
              if ((CurrentSection == 0) && ((Raziel.Senses.Flags & 0x80U) == 0)) {
                StateSwitchStateCharacterData(In,StateHandlerAttack2,0);
              }
            }
            else {
              if (puVar3 != (undefined *)0x80000001) goto LAB_800af5b8;
            }
          }
          else {
            if (puVar3 == (undefined *)0x100000) {
LAB_800af4e4:
              local_30 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerIdle,local_30);
            }
            else {
              if ((int)puVar3 < 0x100001) {
                if (puVar3 == (undefined *)0x0) {
                  if (2 < iVar1 - 0x5bU) {
                    if (5 < Raziel.nothingCounter) goto LAB_800af4e4;
                    if (iVar1 != 0x37) {
                      local_30 = SetControlInitIdleData(1,0,6);
                      StateInitIdle(In,CurrentSection,local_30);
                    }
                  }
                }
                else {
LAB_800af5b8:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar3 != &DAT_00100001) goto LAB_800af5b8;
                ControlFlag = (int)&DAT_0001210b;
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
                local_30 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x54,-1,-1);
                if (local_30 != 0) {
                  G2EmulationSwitchAnimation(In,CurrentSection,0x37,0,6,2);
                }
                razSetPlayerEventHistory(0x20);
              }
            }
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x8000000) {
          if (CurrentSection == 0) {
            SteerSwitchMode(In->CharacterInstance,5);
          }
          NewAnim = 0x37;
          pp_Var6[0x47] = (_Instance *)0x0;
          local_30 = 6;
          goto LAB_800af4d4;
        }
        if ((int)puVar3 < 0x8000001) {
          if (puVar3 == (undefined *)0x2000000) {
            NewAnim = razPickupAndGrab(In,CurrentSection);
            if (NewAnim != 0) {
              NewProcess = StateHandlerAttack2;
LAB_800af578:
              StateSwitchStateData(In,local_30,NewProcess,0);
            }
          }
          else {
            if ((int)puVar3 < 0x2000001) {
              if (puVar3 != (undefined *)0x1000001) goto LAB_800af5b8;
              if ((CurrentSection == 1) && (In->CharacterInstance->LinkChild != (_Instance *)0x0)) {
                p_Var2->Data = 0;
              }
              NewAnim = p_Var2->Data;
              local_30 = iVar5;
              if (NewAnim == 0x10001002) {
                if ((iVar1 != 0xf) && (iVar1 != 0x5d)) {
                  NewAnim = 0xf;
                  goto LAB_800af4d4;
                }
                if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5d)) {
                  SteerSwitchMode(In->CharacterInstance,0xe);
                  local_30 = 0x5d;
                  goto LAB_800af3e8;
                }
              }
              else {
                if (NewAnim < 0x10001003) {
                  if (NewAnim == 0x10001001) {
                    if (iVar1 != 0xc) {
                      NewAnim = 0xc;
                      goto LAB_800af4d4;
                    }
                    if ((((PadData[1] & 0x80) != 0) && ((Raziel.Senses.Flags & 0x80U) == 0)) &&
                       (StateSwitchStateData(In,CurrentSection,StateHandlerAttack2,5),
                       CurrentSection == 2)) {
                      StateSwitchStateData(In,1,StateHandlerAttack2,5);
                    }
                  }
                }
                else {
                  if (NewAnim == 0x10001003) {
                    if ((iVar1 == 0xd) || (iVar1 == 0x5b)) {
                      if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5b)) {
                        SteerSwitchMode(In->CharacterInstance,0xe);
                        local_30 = 0x5b;
LAB_800af3e8:
                        G2EmulationSwitchAnimation(In,CurrentSection,local_30,0,0,1);
                      }
                    }
                    else {
                      NewAnim = 0xd;
LAB_800af4d4:
                      G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,local_30,2);
                    }
                  }
                  else {
                    if (NewAnim == 0x10001004) {
                      if ((iVar1 != 0xe) && (iVar1 != 0x5c)) {
                        NewAnim = 0xe;
                        goto LAB_800af4d4;
                      }
                      if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5c)) {
                        SteerSwitchMode(In->CharacterInstance,0xe);
                        local_30 = 0x5c;
                        goto LAB_800af3e8;
                      }
                    }
                  }
                }
              }
            }
            else {
              if (puVar3 != (undefined *)0x4010080) goto LAB_800af5b8;
              if (CurrentSection == 0) {
                if (p_Var2->Data != 0) goto LAB_800af198;
                razSetPauseTranslation(In->CharacterInstance);
              }
            }
          }
        }
        else {
          if (puVar3 == (undefined *)0x10000000) {
            if ((ControlFlag & 2U) == 0) {
              if (CurrentSection == 0) {
                local_30 = 0;
                NewProcess = StateHandlerStartMove;
                goto LAB_800af578;
              }
              EnMessageQueueData(&In->SectionList[0].Event,(int)&DAT_00100005,CurrentSection);
            }
          }
          else {
            if ((int)puVar3 < 0x10000001) {
              if (puVar3 != (undefined *)0x8000003) goto LAB_800af5b8;
              if (iVar1 == 0x37) {
                pp_Var6[0x47] = (_Instance *)0x1;
              }
            }
            else {
              if (puVar3 != (undefined *)0x20000004) goto LAB_800af5b8;
              if (CurrentSection == 0) {
                Raziel.Senses.LastAutoFace = Raziel.Senses.EngagedList[6].instance;
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
// void /*$ra*/ StateHandlerGlyphs(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 4045, offset 0x800af650
	/* begin block 1 */
		// Start line: 4046
		// Start offset: 0x800AF650
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int hitPosted; // $s5

		/* begin block 1.1 */
			// Start line: 4250
			// Start offset: 0x800AFDE8
			// Variables:
		// 		struct evActionPlayHostAnimationData *ptr; // $v0
		/* end block 1.1 */
		// End offset: 0x800AFE2C
		// End Line: 4257

		/* begin block 1.2 */
			// Start line: 4260
			// Start offset: 0x800AFE2C
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x800AFE80
		// End Line: 4269
	/* end block 1 */
	// End offset: 0x800AFEB0
	// End Line: 4298

	/* begin block 2 */
		// Start line: 8554
	/* end block 2 */
	// End Line: 8555

/* WARNING: Type propagation algorithm not settling */

void StateHandlerGlyphs(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  int Ptr;
  undefined *puVar3;
  _Instance *p_Var4;
  int ID;
  code *NewProcess;
  _Instance **pp_Var5;
  __State *p_Var6;
  
  bVar1 = false;
  G2EmulationQueryAnimation(In,CurrentSection);
  Raziel.invincibleTimer = 0x3000;
  p_Var6 = In->SectionList + CurrentSection;
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(&p_Var6->Event);
    if (p_Var2 == (__Event *)0x0) {
      In->CharacterInstance->cachedTFace = -1;
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00080007) {
      if (pp_Var5[0x47] != (_Instance *)0x0) {
        if (CurrentSection == 0) {
          razPrepGlyph();
          razSwitchStringAnimation(In->CharacterInstance,0);
        }
        pp_Var5[0x47] = (_Instance *)0x0;
        if (CurrentSection == 0) {
          razPlaneShift(In->CharacterInstance);
          if ((Raziel.Mode & 0x40000U) != 0) {
            CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
            SteerSwitchMode(In->CharacterInstance,6);
          }
          SteerSwitchMode(In->CharacterInstance,0);
          if ((Raziel.playerEvent & 0x2000) != 0) {
            razSetPlayerEventHistory(0x2000);
            HINT_KillSpecificHint(0x28);
          }
        }
        Raziel.invincibleTimer = 0x1e000;
      }
    }
    else {
      if ((int)puVar3 < 0x80008) {
        if (puVar3 == &UNK_00040025) {
LAB_800afe80:
          EnMessageQueueData(&p_Var6->Defer,p_Var2->ID,p_Var2->Data);
        }
        else {
          if ((int)puVar3 < 0x40026) {
            if (puVar3 == &DAT_80000010) {
              if (pp_Var5[0x47] != (_Instance *)0x0) {
                if (CurrentSection == 0) {
                  In->SectionList[0].Data1 = 0;
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
              if ((int)puVar3 < -0x7fffffef) {
                if (puVar3 == (undefined *)0x80000000) goto LAB_800afd18;
                if (puVar3 != &DAT_80000008) goto LAB_800afe98;
              }
              else {
                if (puVar3 == &DAT_00040003) {
                  p_Var4 = (_Instance *)p_Var2->Data;
                  Ptr = SetActionPlayHostAnimationData
                                  (*(_Instance **)&p_Var4->node,
                                   *(_Instance **)((int)&p_Var4->node + 4),(int)p_Var4->next,
                                   (int)p_Var4->prev,(int)p_Var4->instanceID,(int)p_Var4->flags);
                  ID = p_Var2->ID;
LAB_800afe70:
                  EnMessageQueueData(&p_Var6->Defer,ID,Ptr);
                }
                else {
                  if ((int)puVar3 < 0x40004) {
                    if (puVar3 == &DAT_80000020) goto LAB_800afea0;
                  }
                  else {
                    if (puVar3 == &DAT_00040005) goto LAB_800afe80;
                  }
LAB_800afe98:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
            }
          }
          else {
            if (puVar3 == &DAT_00080003) {
              if (CurrentSection == 0) {
                razPrepGlyph();
                razSwitchStringAnimation(In->CharacterInstance,4);
                Raziel.effectsFlags = Raziel.effectsFlags | 4;
                razSetupSoundRamp(In->CharacterInstance,(_SoundRamp *)&Raziel.soundHandle,0x13,600,
                                  0x2ee,0x3c,0x78,(int)&LAB_00032000,0xdac);
                Raziel.soundTimerData = 1;
                Raziel.soundTimerNext = (long)&LAB_00032000;
              }
            }
            else {
              if ((int)puVar3 < 0x80004) {
                if (puVar3 == &DAT_00080001) {
                  if (CurrentSection == 0) {
                    razPrepGlyph();
                    razSwitchStringAnimation(In->CharacterInstance,1);
                    Raziel.effectsFlags = Raziel.effectsFlags | 4;
                    razSetupSoundRamp(In->CharacterInstance,(_SoundRamp *)&Raziel.soundHandle,0xc,0,
                                      0x7d,0x50,0x50,(int)&LAB_0004d000,0xdac);
                    Raziel.soundTimerData = 3;
                    Raziel.soundTimerNext = (long)&LAB_0004d000;
                  }
                }
                else {
                  if (puVar3 != &DAT_00080002) goto LAB_800afe98;
                  if (CurrentSection == 0) {
                    razPrepGlyph();
                    razSwitchStringAnimation(In->CharacterInstance,2);
                    pp_Var5[0x47] = (_Instance *)0x0;
                    goto LAB_800afea0;
                  }
                }
              }
              else {
                if (puVar3 != &DAT_00080005) {
                  if ((int)puVar3 < 0x80006) {
                    if (CurrentSection != 0) goto LAB_800afc5c;
                    razPrepGlyph();
                    razSwitchStringAnimation(In->CharacterInstance,5);
                    pp_Var5[0x47] = (_Instance *)0x0;
                  }
                  else {
                    if (CurrentSection != 0) goto LAB_800afc5c;
                    razPrepGlyph();
                    razSwitchStringAnimation(In->CharacterInstance,6);
                    pp_Var5[0x47] = (_Instance *)0x0;
                  }
                  goto LAB_800afea0;
                }
                if (CurrentSection == 0) {
                  razPrepGlyph();
                  razSwitchStringAnimation(In->CharacterInstance,3);
                  pp_Var5[0x47] = (_Instance *)0x0;
                  goto LAB_800afea0;
                }
              }
            }
LAB_800afc5c:
            pp_Var5[0x47] = (_Instance *)0x0;
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x2000000) {
LAB_800afd18:
          if ((pp_Var5[0x47] != (_Instance *)0x0) && (CurrentSection == 0)) {
            INSTANCE_Post(Raziel.GlyphSystem,-0x80000000,0);
            PurgeMessageQueue(&In->SectionList[0].Event);
          }
        }
        else {
          if ((int)puVar3 < 0x2000001) {
            if (puVar3 == &DAT_00100004) {
              if (CurrentSection == 0) {
                razReaverOn();
                Ptr = GlyphIsGlyphOpen(Raziel.GlyphSystem);
                if (Ptr != 0) {
                  INSTANCE_Post(Raziel.GlyphSystem,(int)&DAT_80000010,(int)In->CharacterInstance);
                }
              }
              Raziel.invincibleTimer = 0;
            }
            else {
              if ((int)puVar3 < 0x100005) {
                if (puVar3 == (undefined *)0x100000) {
                  if (pp_Var5[0x47] == (_Instance *)0x0) {
                    if (((Raziel.Mode & 0x40000U) == 0) || (Raziel.CurrentPlane != 1)) {
                      Ptr = SetControlInitIdleData(0,0,3);
                      NewProcess = StateHandlerIdle;
                    }
                    else {
                      NewProcess = StateHandlerSwim;
                      Ptr = 0;
                    }
                    StateSwitchStateData(In,CurrentSection,NewProcess,Ptr);
                    if (CurrentSection == 0) {
                      razSetFadeEffect(0x1000,0,0x100);
                    }
                  }
                  else {
                    if (((Raziel.Mode & 0x40000U) == 0) && (pp_Var5[0x47] != (_Instance *)0x2)) {
                      Ptr = SetControlInitIdleData(0,0,3);
                      StateInitIdle(In,CurrentSection,Ptr);
                      pp_Var5[0x47] = (_Instance *)0x2;
                    }
                  }
                }
                else {
                  if (puVar3 != &DAT_00100001) goto LAB_800afe98;
                  if (CurrentSection == 0) {
                    if (p_Var2->Data == 0) {
                      INSTANCE_Post(Raziel.GlyphSystem,(int)&DAT_80000010,(int)In->CharacterInstance
                                   );
                    }
                    Raziel.Mode = Raziel.Mode | 1;
                    ControlFlag = 0x1100008;
                    SteerSwitchMode(In->CharacterInstance,0x10);
                    razResetMotion(In->CharacterInstance);
                  }
                  pp_Var5[0x47] = (_Instance *)0x1;
                  PhysicsMode = 3;
                  if (p_Var2->Data != 0) {
                    EnMessageQueueData(&p_Var6->Defer,(int)&DAT_00080007,0);
                  }
                }
              }
              else {
                if (puVar3 != (undefined *)0x1000000) {
                  if ((int)puVar3 < 0x1000001) {
                    if (puVar3 == &DAT_00100015) goto LAB_800af974;
                  }
                  else {
                    if (puVar3 == (undefined *)0x1000001) goto LAB_800afea0;
                  }
                  goto LAB_800afe98;
                }
                p_Var4 = (_Instance *)p_Var2->Data;
                if ((!bVar1) && (Raziel.invincibleTimer == 0)) {
                  bVar1 = true;
                  Ptr = SetMonsterHitData(*(_Instance **)&p_Var4->node,
                                          *(_Instance **)((int)&p_Var4->node + 4),(int)p_Var4->prev,
                                          (int)*(short *)&p_Var4->next,
                                          (int)*(short *)((int)&p_Var4->next + 2));
                  ID = 0x1000000;
                  goto LAB_800afe70;
                }
              }
            }
          }
          else {
            if (puVar3 != (undefined *)0x4020000) {
              if ((int)puVar3 < 0x4020001) {
                if (puVar3 == (undefined *)0x4000001) {
                  if ((Raziel.Mode & 0x40000U) == 0) {
                    PhysicsMode = 0;
                    SetDropPhysics(In->CharacterInstance,&Raziel);
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x4010200) goto LAB_800afe98;
                }
              }
              else {
                if (puVar3 != (undefined *)0x8000003) {
                  if ((int)puVar3 < 0x8000004) {
                    if (puVar3 == (undefined *)0x8000000) goto LAB_800af974;
                  }
                  else {
                    if (puVar3 == (undefined *)0x10000000) {
                      if (CurrentSection == 0) {
                        if ((*PadData & 4U) != 0) {
                          INSTANCE_Post(Raziel.GlyphSystem,0x10000004,p_Var2->Data);
                        }
                        if ((*PadData & 8U) != 0) {
                          INSTANCE_Post(Raziel.GlyphSystem,0x10000002,p_Var2->Data);
                        }
                      }
                      goto LAB_800afea0;
                    }
                  }
                  goto LAB_800afe98;
                }
LAB_800af974:
                if (CurrentSection == 0) {
                  CheckStringAnimation(In->CharacterInstance,p_Var2->ID);
                }
              }
            }
          }
        }
      }
    }
LAB_800afea0:
    DeMessageQueue(&p_Var6->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DefaultStateHandler(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$a2*/)
 // line 4356, offset 0x800afee4
	/* begin block 1 */
		// Start line: 4357
		// Start offset: 0x800AFEE4
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 4376
			// Start offset: 0x800B0184
			// Variables:
		// 		int message; // stack offset -32
		// 		int messageData; // stack offset -28

			/* begin block 1.1.1 */
				// Start line: 4396
				// Start offset: 0x800B0248
				// Variables:
			// 		int i; // $s1
			/* end block 1.1.1 */
			// End offset: 0x800B0288
			// End Line: 4402
		/* end block 1.1 */
		// End offset: 0x800B0288
		// End Line: 4405

		/* begin block 1.2 */
			// Start line: 4567
			// Start offset: 0x800B0404
			// Variables:
		// 		struct evPhysicsGravityData *ptr; // $v1
		// 		short zRot; // $s0

			/* begin block 1.2.1 */
				// Start line: 4573
				// Start offset: 0x800B0410
				// Variables:
			// 		struct _Position pos1; // stack offset -48
			// 		struct _Position pos2; // stack offset -40
			// 		int diff; // $v0
			/* end block 1.2.1 */
			// End offset: 0x800B04F0
			// End Line: 4593
		/* end block 1.2 */
		// End offset: 0x800B04F0
		// End Line: 4593

		/* begin block 1.3 */
			// Start line: 4626
			// Start offset: 0x800B0584
			// Variables:
		// 		struct evFXHitData *BloodData; // $a0
		// 		struct _SVector Accel; // stack offset -48
		/* end block 1.3 */
		// End offset: 0x800B0584
		// End Line: 4627

		/* begin block 1.4 */
			// Start line: 4675
			// Start offset: 0x800B0730
			// Variables:
		// 		struct evPhysicsEdgeData *data; // $s0
		/* end block 1.4 */
		// End offset: 0x800B076C
		// End Line: 4681
	/* end block 1 */
	// End offset: 0x800B0860
	// End Line: 4718

	/* begin block 2 */
		// Start line: 9191
	/* end block 2 */
	// End Line: 9192

void DefaultStateHandler(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  __Event *p_Var2;
  _G2Bool_Enum _Var3;
  undefined *puVar4;
  code *NewProcess;
  int Data_00;
  _Instance *p_Var5;
  int iVar6;
  _SVector local_30;
  _Position local_28;
  int local_20;
  int local_1c;
  
  p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
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
    StateSwitchStateCharacterDataDefault(In,StateHandlerHitReaction,p_Var2->Data);
    CAMERA_ForceEndLookaroundMode(&theCamera);
    return;
  }
  if ((int)puVar4 < 0x1000001) {
    if (puVar4 == &DAT_00040005) {
LAB_800b07fc:
      StateSwitchStateDataDefault(In,CurrentSection,StateHandlerStumble,p_Var2->Data);
      In->SectionList[CurrentSection].Data1 = p_Var2->Data * 0x1e;
      return;
    }
    if ((int)puVar4 < 0x40006) {
      if (puVar4 == &DAT_80000008) {
        if (CurrentSection != 0) {
          return;
        }
        StateSwitchStateCharacterDataDefault(In,StateHandlerCrouch,1);
        return;
      }
      if (-0x7ffffff8 < (int)puVar4) {
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
        if (CurrentSection != 0) {
          return;
        }
        if ((Raziel.Senses.Flags & 0x80U) != 0) {
          return;
        }
        if ((PadData[1] & 0x20) != 0) {
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
            StateSwitchStateCharacterDataDefault(In,StateHandlerGrab,local_1c);
            return;
          }
          if (local_20 != 0x80000) {
            StateSwitchStateCharacterDataDefault(In,StateHandlerAttack2,0);
            iVar6 = 0;
            Data_00 = 8;
            do {
              EnMessageQueueData((__MessageQueue *)
                                 ((int)&In->SectionList[0].Event.Queue[0xf].ID + Data_00),
                                 (int)&DAT_80000020,0);
              iVar6 = iVar6 + 1;
              Data_00 = Data_00 + 0x11c;
            } while (iVar6 < 3);
            return;
          }
          Raziel.playerEvent = Raziel.playerEvent | 0x400;
          razSetPlayerEventHistory(0x400);
          razLaunchForce(In->CharacterInstance);
          NewProcess = StateHandlerThrow2;
        }
        goto LAB_800b0628;
      }
      if (puVar4 != (undefined *)0x80000000) {
        if (puVar4 != &DAT_80000004) {
          return;
        }
        Raziel.Mode = Raziel.Mode | 2;
        return;
      }
      if ((Raziel.Mode & 0x40000U) != 0) {
        return;
      }
      if ((Raziel.Senses.Flags & 0x80U) != 0) {
        return;
      }
      NewProcess = StateHandlerAttack2;
      Data_00 = 0;
    }
    else {
      if (puVar4 == &DAT_00100005) {
        Data_00 = p_Var2->Data;
        if (Data_00 == 1) {
          if (In->CharacterInstance->LinkChild != (_Instance *)0x0) {
            G2EmulationSwitchAnimation(In,p_Var2->Data,0x32,0,3,2);
            NewProcess = In->SectionList[CurrentSection].Process;
            Data_00 = 0;
            CurrentSection = p_Var2->Data;
            goto LAB_800b0858;
          }
          Data_00 = 1;
        }
        G2EmulationSwitchAnimationSync(In,Data_00,0,3);
        return;
      }
      if ((int)puVar4 < 0x100006) {
        if (puVar4 == &UNK_00040025) goto LAB_800b07fc;
        if (puVar4 != (undefined *)0x100000) {
          return;
        }
        NewProcess = (code *)p_Var2->Data;
        if (NewProcess == (TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)0x0) {
          return;
        }
        Data_00 = 0;
      }
      else {
        if (puVar4 != &DAT_00100009) {
          if ((int)puVar4 < 0x10000a) {
            if (puVar4 != &DAT_00100006) {
              return;
            }
            InitAlgorithmicWings(In->CharacterInstance);
            return;
          }
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
          if (Raziel.returnState == (_func_60 *)0x0) {
            Raziel.returnState = StateHandlerIdle;
          }
          Data_00 = 0;
          NewProcess = Raziel.returnState;
        }
        else {
          if (CurrentSection == 0) {
            Raziel.returnState = (_func_60 *)In->SectionList[0].Process;
            if (Raziel.returnState == StateHandlerSoulSuck) {
              Raziel.returnState = StateHandlerIdle;
            }
            In->SectionList[0].Data1 = Raziel.Mode;
            Raziel.Mode = 0x80000;
          }
          NewProcess = StateHandlerLookAround;
          Data_00 = 0;
        }
      }
    }
LAB_800b0858:
    StateSwitchStateDataDefault(In,CurrentSection,NewProcess,Data_00);
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
    if (((int)(p_Var5->rotation).z - (int)sVar1) + 0x3ffU < 0x7ff) {
      (p_Var5->rotation).z = sVar1;
      G2EmulationSwitchAnimationCharacter(&Raziel.State,0x49,0,6,2);
      In = &Raziel.State;
      NewProcess = StateHandlerSlide;
    }
    else {
      (p_Var5->rotation).z = sVar1 + 0x800;
      G2EmulationSwitchAnimationCharacter(&Raziel.State,0x4d,0,6,2);
      In = &Raziel.State;
      NewProcess = StateHandlerSlide;
    }
  }
  else {
    if (0x4010200 < (int)puVar4) {
      if (puVar4 == (undefined *)0x8000000) {
        Data_00 = SetControlInitIdleData(0,0,3);
        StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
        return;
      }
      if ((int)puVar4 < 0x8000001) {
        if (puVar4 != (undefined *)0x4010400) {
          if (puVar4 != (undefined *)0x4020000) {
            return;
          }
          razEnterWater(In,CurrentSection,(evPhysicsSwimData *)p_Var2->Data);
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
        Data_00 = 0;
      }
      else {
        if ((int)puVar4 < 0x10002001) {
          return;
        }
        if (0x10002002 < (int)puVar4) {
          if (puVar4 != (undefined *)0x20000004) {
            return;
          }
          Raziel.Mode = Raziel.Mode & 0xfffffffdU | 1;
          return;
        }
        NewProcess = StateHandlerGlyphs;
        Data_00 = 1;
      }
      goto LAB_800b0858;
    }
    if (puVar4 == (undefined *)0x4000004) {
      return;
    }
    if ((int)puVar4 < 0x4000005) {
      if (puVar4 == (undefined *)0x1000001) {
        NewProcess = StateHandlerAutoFace;
        Data_00 = 0;
        goto LAB_800b0858;
      }
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
    }
    else {
      if (puVar4 == (undefined *)0x4010008) {
        if (PhysicsMode == 3) {
          return;
        }
        PhysicsMode = 3;
        SetPhysics(In->CharacterInstance,-0x10,0,0,0);
        return;
      }
      if (0x4010008 < (int)puVar4) {
        if (puVar4 != (undefined *)0x4010010) {
          return;
        }
        iVar6 = p_Var2->Data;
        Data_00 = SetControlInitHangData(*(_Instance **)(iVar6 + 0x18),0,3);
        StateSwitchStateDataDefault(In,CurrentSection,StateHandlerHang,Data_00);
        (In->CharacterInstance->rotation).z = *(short *)(iVar6 + 0x1c);
        return;
      }
      if (puVar4 != (undefined *)0x4000011) {
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
      if (CurrentSection != 0) {
        return;
      }
      Data_00 = razSideMoveSpiderCheck(In->CharacterInstance,-0x80);
      if (Data_00 != 0) {
        return;
      }
      Data_00 = razSideMoveSpiderCheck(In->CharacterInstance,0x80);
      if (Data_00 != 0) {
        return;
      }
      NewProcess = StateHandlerWallGrab;
    }
  }
LAB_800b0628:
  StateSwitchStateCharacterDataDefault(In,NewProcess,0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ RazielAnimCallback(struct _G2Anim_Type *anim /*$s3*/, int sectionID /*$s1*/, enum _G2AnimCallbackMsg_Enum message /*$s4*/, long messageDataA /*$s5*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
 // line 4722, offset 0x800b087c
	/* begin block 1 */
		// Start line: 4723
		// Start offset: 0x800B087C
		// Variables:
	// 		struct __State *pSection; // $a0
	// 		struct _G2AnimSection_Type *animSection; // $a2

		/* begin block 1.1 */
			// Start line: 4741
			// Start offset: 0x800B0940
			// Variables:
		// 		struct evAnimationControllerDoneData *ControllerData; // $v1
		/* end block 1.1 */
		// End offset: 0x800B09C8
		// End Line: 4757

		/* begin block 1.2 */
			// Start line: 4771
			// Start offset: 0x800B0A10
			// Variables:
		// 		struct __AlarmData *data; // $s0
		// 		struct _Instance *inst; // $a0

			/* begin block 1.2.1 */
				// Start line: 4842
				// Start offset: 0x800B0C10
				// Variables:
			// 		int test; // $a0

				/* begin block 1.2.1.1 */
					// Start line: 4862
					// Start offset: 0x800B0C74
					// Variables:
				// 		struct _SoundRamp *soundRamp; // $t0
				/* end block 1.2.1.1 */
				// End offset: 0x800B0D94
				// End Line: 4877
			/* end block 1.2.1 */
			// End offset: 0x800B0D94
			// End Line: 4877
		/* end block 1.2 */
		// End offset: 0x800B0DAC
		// End Line: 4886

		/* begin block 1.3 */
			// Start line: 4890
			// Start offset: 0x800B0DB4

			/* begin block 1.3.1 */
				// Start line: 4895
				// Start offset: 0x800B0DD8
				// Variables:
			// 		struct _Instance *heldInstance; // $s0
			/* end block 1.3.1 */
			// End offset: 0x800B0E18
			// End Line: 4901
		/* end block 1.3 */
		// End offset: 0x800B0E2C
		// End Line: 4910
	/* end block 1 */
	// End offset: 0x800B0E58
	// End Line: 4925

	/* begin block 2 */
		// Start line: 9942
	/* end block 2 */
	// End Line: 9943

/* WARNING: Type propagation algorithm not settling */

long RazielAnimCallback(_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,
                       long messageDataA,long messageDataB,void *data)

{
  short sVar1;
  bool bVar2;
  evAnimationControllerDoneData *ControllerData;
  _Instance *Inst;
  ulong uVar3;
  int iVar4;
  _G2AnimSection_Type *p_Var5;
  long messageDataA_00;
  
  p_Var5 = anim->section + sectionID;
  switch(message) {
  case G2ANIM_MSG_DONE:
    EnMessageQueueData(&Raziel.State.SectionList[sectionID].Event,0x8000000,(uint)p_Var5->keylistID)
    ;
    break;
  case G2ANIM_MSG_LOOPPOINT:
    EnMessageQueueData(&Raziel.State.SectionList[sectionID].Event,0x8000001,(uint)p_Var5->keylistID)
    ;
    break;
  case G2ANIM_MSG_SECTION_INTERPDONE:
    EnMessageQueueData(&Raziel.State.SectionList[sectionID].Event,0x8000003,(uint)p_Var5->keylistID)
    ;
    break;
  case G2ANIM_MSG_SEGCTRLR_INTERPDONE:
    ControllerData =
         (evAnimationControllerDoneData *)
         SetAnimationControllerDoneData
                   (Raziel.State.CharacterInstance,messageDataB,messageDataA,(int)data);
    iVar4 = ControllerData->data;
    if (iVar4 == 2) {
      AlgorithmicWings(Raziel.State.CharacterInstance,ControllerData);
    }
    else {
      if (iVar4 == 0) {
        G2Anim_InterpDisableController
                  (&ControllerData->instance->anim,ControllerData->segment,ControllerData->type,300)
        ;
      }
      else {
        if (iVar4 == 4) {
          G2Anim_DisableController
                    (&ControllerData->instance->anim,ControllerData->segment,ControllerData->type);
        }
      }
    }
    break;
  case G2ANIM_MSG_SWALARMSET:
    p_Var5->swAlarmTable = (short *)0x0;
    EnMessageQueueData(&Raziel.State.SectionList[sectionID].Event,0x8000004,0);
    break;
  case G2ANIM_MSG_PLAYEFFECT:
    if (messageDataA != 2) {
      messageDataA_00 = messageDataA;
      if (messageDataA == 0) {
        if (*(short *)messageDataB == 0x2d) {
          if ((ControlFlag & 0x100000U) != 0) {
            return 0;
          }
          Inst = razGetHeldWeapon();
          if (Inst == (_Instance *)0x0) {
            return 0;
          }
          uVar3 = INSTANCE_Query(Inst,2);
          if ((uVar3 & 0x20) == 0) {
            return 0;
          }
          uVar3 = INSTANCE_Query(Inst,3);
          if ((uVar3 & 0x10000) == 0) {
            return 0;
          }
          messageDataA_00 = 0;
        }
        else {
          messageDataA_00 = 0;
        }
      }
      INSTANCE_DefaultAnimCallback
                (anim,sectionID,message,messageDataA_00,messageDataB,Raziel.State.CharacterInstance)
      ;
      return messageDataA;
    }
    Inst = razGetHeldWeapon();
    switch((int)(((uint)*(ushort *)messageDataB - 1) * 0x10000) >> 0x10) {
    case 0:
      if (Inst == (_Instance *)0x0) {
        EnableWristCollision(gameTrackerX.playerInstance,(int)*(short *)(messageDataB + 2));
      }
      else {
        INSTANCE_Post(Inst,0x200002,(int)*(short *)(messageDataB + 2));
      }
      break;
    case 1:
      if (Inst == (_Instance *)0x0) {
        DisableWristCollision(gameTrackerX.playerInstance,(int)*(short *)(messageDataB + 2));
      }
      else {
        INSTANCE_Post(Inst,0x200003,(int)*(short *)(messageDataB + 2));
      }
      ControlFlag = ControlFlag | 0x10000000;
      break;
    case 2:
      razSetCowlNoDraw(0);
      ControlFlag = ControlFlag | 0x40;
      break;
    case 3:
      razSetCowlNoDraw(1);
      ControlFlag = ControlFlag & 0xffffffbf;
      break;
    case 4:
      if ((int)*(short *)(messageDataB + 2) < 0x20) {
        Raziel.passedMask = Raziel.passedMask | 1 << ((int)*(short *)(messageDataB + 2) & 0x1fU);
      }
      else {
        Raziel.passedMask = 0xffffffff;
      }
      break;
    case 5:
      if ((int)*(short *)(messageDataB + 2) < 0x20) {
        Raziel.passedMask = Raziel.passedMask & ~(1 << ((int)*(short *)(messageDataB + 2) & 0x1fU));
      }
      else {
        Raziel.passedMask = 0;
      }
      break;
    case 6:
      Raziel.effectsFadeSource = (gameTrackerX.playerInstance)->fadeValue;
      Raziel.effectsFadeDest = *(short *)(messageDataB + 2);
      Raziel.effectsFlags = Raziel.effectsFlags | 1;
      break;
    case 7:
      Raziel.effectsFadeSteps = 0;
      Raziel.effectsFlags = Raziel.effectsFlags | 1;
      Raziel.effectsFadeStep = (int)*(short *)(messageDataB + 2);
      break;
    case 8:
      if (Inst != (_Instance *)0x0) {
        INSTANCE_Post(Inst,0x200005,(int)*(short *)(messageDataB + 2));
      }
      break;
    case 9:
      if (Inst != (_Instance *)0x0) {
        INSTANCE_Post(Inst,0x200006,(int)*(short *)(messageDataB + 2));
      }
      break;
    case 10:
      sVar1 = *(short *)(messageDataB + 2);
      bVar2 = false;
      if (sVar1 == 2) {
        uVar3 = 1;
code_r0x800b0c60:
        if (Raziel.currentSoulReaver == uVar3) {
          bVar2 = true;
        }
      }
      else {
        if (sVar1 < 3) {
          if (-1 < sVar1) {
            bVar2 = true;
          }
        }
        else {
          uVar3 = 6;
          if (sVar1 == 3) goto code_r0x800b0c60;
        }
      }
      if (bVar2) {
        iVar4 = (int)*(short *)(messageDataB + 2);
        razSetupSoundRamp(gameTrackerX.playerInstance,
                          (_SoundRamp *)(&Raziel.soundHandle + (int)(&cannedSound)[iVar4].bank * 6),
                          (int)(&cannedSound)[iVar4].sound,(int)(&cannedSound)[iVar4].startPitch,
                          (int)(&cannedSound)[iVar4].endPitch,
                          (int)(&cannedSound)[*(short *)(messageDataB + 2)].startVolume,
                          (int)(&cannedSound)[*(short *)(messageDataB + 2)].endVolume,
                          (&cannedSound)[*(short *)(messageDataB + 2)].time,
                          (&cannedSound)[*(short *)(messageDataB + 2)].distance);
        iVar4 = (int)*(short *)(messageDataB + 2);
        if ((&cannedSound)[iVar4].bank == 0) {
          Raziel.effectsFlags = Raziel.effectsFlags | 4;
          iVar4 = (int)*(short *)(messageDataB + 2);
        }
        if ((&cannedSound)[iVar4].bank == 1) {
          Raziel.effectsFlags = Raziel.effectsFlags | 8;
        }
      }
    }
  }
  return messageDataA;
}



// decompiled code
// original method signature: 
// long /*$ra*/ RazielAnimCallbackDuringPause(struct _G2Anim_Type *anim /*$a0*/, int sectionID /*$a1*/, enum _G2AnimCallbackMsg_Enum message /*$s0*/, long messageDataA /*$s1*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
 // line 4926, offset 0x800b0e80
	/* begin block 1 */
		// Start line: 4927
		// Start offset: 0x800B0E80

		/* begin block 1.1 */
			// Start line: 4936
			// Start offset: 0x800B0EA0
			// Variables:
		// 		struct evAnimationControllerDoneData *ControllerData; // $v1
		/* end block 1.1 */
		// End offset: 0x800B0F1C
		// End Line: 4952
	/* end block 1 */
	// End offset: 0x800B0F1C
	// End Line: 4957

	/* begin block 2 */
		// Start line: 10369
	/* end block 2 */
	// End Line: 10370

long RazielAnimCallbackDuringPause
               (_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,long messageDataA,
               long messageDataB,void *data)

{
  evAnimationControllerDoneData *ControllerData;
  int iVar1;
  
  if (message == G2ANIM_MSG_SEGCTRLR_INTERPDONE) {
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
  }
  return messageDataA;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ RazielQuery(struct _Instance *instance /*$s0*/, unsigned long Query /*$a1*/)
 // line 5000, offset 0x800b0f34
	/* begin block 1 */
		// Start line: 5001
		// Start offset: 0x800B0F34

		/* begin block 1.1 */
			// Start line: 5063
			// Start offset: 0x800B1048
			// Variables:
		// 		struct _Normal *Ptr; // $a0
		/* end block 1.1 */
		// End offset: 0x800B10F0
		// End Line: 5079

		/* begin block 1.2 */
			// Start line: 5082
			// Start offset: 0x800B10F0
			// Variables:
		// 		unsigned long ability; // $s0
		/* end block 1.2 */
		// End offset: 0x800B1164
		// End Line: 5100

		/* begin block 1.3 */
			// Start line: 5102
			// Start offset: 0x800B1164
			// Variables:
		// 		struct PlayerSaveData data; // stack offset -32
		/* end block 1.3 */
		// End offset: 0x800B11AC
		// End Line: 5119

		/* begin block 1.4 */
			// Start line: 5139
			// Start offset: 0x800B1204
			// Variables:
		// 		struct evShadowSegmentData *shadowData; // $v0
		/* end block 1.4 */
		// End offset: 0x800B1220
		// End Line: 5146
	/* end block 1 */
	// End offset: 0x800B1280
	// End Line: 5170

	/* begin block 2 */
		// Start line: 10000
	/* end block 2 */
	// End Line: 10001

ulong RazielQuery(_Instance *instance,ulong Query)

{
  Level *pLVar1;
  int iVar2;
  int iVar3;
  _Instance *p_Var4;
  undefined local_20 [24];
  
  switch(Query) {
  case 1:
    p_Var4 = (_Instance *)&UNK_00000001;
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
    p_Var4 = (_Instance *)(Raziel.Abilities & 0x1fc0000);
    if (((pLVar1->unitFlags & 0x800U) != 0) || (iVar2 = RAZIEL_OkToShift(), iVar2 == 0)) {
      p_Var4 = (_Instance *)(iVar3 & 0xfc0000);
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
    p_Var4 = (_Instance *)Raziel.playerEvent;
    break;
  case 0x2a:
    p_Var4 = (_Instance *)Raziel.playerEventHistory;
    break;
  case 0x2b:
    iVar3 = GetMaxHealth();
    p_Var4 = (_Instance *)(uint)(Raziel.HitPoints == iVar3);
    break;
  case 0x2c:
    p_Var4 = razGetHeldItem();
    break;
  case 0x2d:
    p_Var4 = (_Instance *)(uint)Raziel.GlyphManaMax;
    break;
  case 0x2e:
    p_Var4 = (_Instance *)Raziel.invincibleTimer;
  }
  return (ulong)p_Var4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielPost(struct _Instance *instance /*$s1*/, unsigned long Message /*$s2*/, unsigned long Data /*$s3*/)
 // line 5174, offset 0x800b1290
	/* begin block 1 */
		// Start line: 5175
		// Start offset: 0x800B1290
		// Variables:
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 5182
			// Start offset: 0x800B14CC
		/* end block 1.1 */
		// End offset: 0x800B1504
		// End Line: 5200

		/* begin block 1.2 */
			// Start line: 5246
			// Start offset: 0x800B1574
			// Variables:
		// 		struct PlayerSaveData *data; // $s0
		/* end block 1.2 */
		// End offset: 0x800B1634
		// End Line: 5291

		/* begin block 1.3 */
			// Start line: 5317
			// Start offset: 0x800B16E4
		/* end block 1.3 */
		// End offset: 0x800B16F8
		// End Line: 5323

		/* begin block 1.4 */
			// Start line: 5343
			// Start offset: 0x800B1754
		/* end block 1.4 */
		// End offset: 0x800B17BC
		// End Line: 5359

		/* begin block 1.5 */
			// Start line: 5362
			// Start offset: 0x800B17C4
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.5 */
		// End offset: 0x800B17EC
		// End Line: 5367

		/* begin block 1.6 */
			// Start line: 5371
			// Start offset: 0x800B1804
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.6 */
		// End offset: 0x800B182C
		// End Line: 5376

		/* begin block 1.7 */
			// Start line: 5433
			// Start offset: 0x800B1988
		/* end block 1.7 */
		// End offset: 0x800B19C4
		// End Line: 5443

		/* begin block 1.8 */
			// Start line: 5445
			// Start offset: 0x800B19C4
		/* end block 1.8 */
		// End offset: 0x800B1A08
		// End Line: 5462

		/* begin block 1.9 */
			// Start line: 5472
			// Start offset: 0x800B1A50
			// Variables:
		// 		int i; // $s2
		// 		struct _Instance *heldWeapon; // $v1
		/* end block 1.9 */
		// End offset: 0x800B1AC8
		// End Line: 5495

		/* begin block 1.10 */
			// Start line: 5502
			// Start offset: 0x800B1AD0
			// Variables:
		// 		struct _Instance *heldWeapon; // $v1
		/* end block 1.10 */
		// End offset: 0x800B1B74
		// End Line: 5525
	/* end block 1 */
	// End offset: 0x800B1BF4
	// End Line: 5543

	/* begin block 2 */
		// Start line: 10828
	/* end block 2 */
	// End Line: 10829

/* WARNING: Type propagation algorithm not settling */

void RazielPost(_Instance *instance,ulong Message,ulong Data)

{
  __CharacterState *p_Var1;
  int iVar2;
  _Instance *instance_00;
  uint uVar3;
  short source;
  short dest;
  code *NewProcess;
  ulong *puVar4;
  __MessageQueue *In;
  int Data_00;
  int CurrentSection;
  __MessageQueue *In_00;
  
  if ((undefined *)Message == &DAT_0010000a) {
    CurrentSection = 0;
    if (Data != 0) {
      Data_00 = 0x1ec;
      do {
        iVar2 = (int)&(instance->node).prev + Data_00;
        CurrentSection = CurrentSection + 1;
        *(undefined4 *)(iVar2 + 0x1c) = 0x800b0e80;
        *(undefined4 *)(iVar2 + 0x20) = 0;
        Data_00 = Data_00 + 0x30;
      } while (CurrentSection < 3);
      DeInitAlgorithmicWings(instance);
      razResetPauseTranslation(instance);
      return;
    }
    Data_00 = 0x1ec;
    do {
      iVar2 = (int)&(instance->node).prev + Data_00;
      CurrentSection = CurrentSection + 1;
      *(undefined4 *)(iVar2 + 0x1c) = 0x800b087c;
      *(undefined4 *)(iVar2 + 0x20) = 0;
      Data_00 = Data_00 + 0x30;
    } while (CurrentSection < 3);
    InitAlgorithmicWings(instance);
    return;
  }
  if (Message <= &DAT_0010000a) {
    if ((undefined *)Message == &DAT_00040012) {
      NewProcess = StateHandlerDropAction;
LAB_800b18ec:
      StateSwitchStateCharacterData(&Raziel.State,NewProcess,0);
      return;
    }
    if (&DAT_00040012 < Message) {
      if ((undefined *)Message == &DAT_00040022) {
        Raziel.forcedGlideSpeed = Data;
        return;
      }
      if (&DAT_00040022 < Message) {
        if ((undefined *)Message == &DAT_00100007) {
          puVar4 = *(ulong **)(Data + 4);
          debugRazielFlags1 = *puVar4;
          Raziel.Abilities = debugRazielFlags1;
          CurrentSection = razInBaseArea("under",5);
          Raziel.CurrentPlane = 2;
          if (CurrentSection == 0) {
            Raziel.CurrentPlane = puVar4[1];
          }
          Raziel.HealthScale = *(short *)(puVar4 + 2);
          Raziel.HealthBalls = *(short *)(puVar4 + 3);
          HUD_Setup_Chit_Count(puVar4[3]);
          Raziel.GlyphManaBalls = *(ushort *)(puVar4 + 4);
          Raziel.GlyphManaMax = *(ushort *)((int)puVar4 + 0x12);
          Raziel.soulReaver = (_Instance *)0x0;
          if ((Raziel.Abilities & 8U) != 0) {
            debugRazielFlags2 = 0;
          }
          Raziel.playerEventHistory = puVar4[5];
          if ((Raziel.playerEventHistory & 0x1000) == 0) {
            Raziel.HitPoints = 100;
            Raziel.soulReaver = (_Instance *)0x0;
            return;
          }
          Raziel.HitPoints = GetMaxHealth();
          return;
        }
        if (&DAT_00100007 < Message) {
          if ((undefined *)Message == &DAT_00100008) {
            if ((ControlFlag & 0x200000U) != 0) {
              RelocateConstrict((_SVector *)Data);
            }
            Raziel.puppetMoveToPoint.x = Raziel.puppetMoveToPoint.x + *(short *)Data;
            Raziel.puppetMoveToPoint.y = Raziel.puppetMoveToPoint.y + *(short *)(Data + 2);
            Raziel.puppetMoveToPoint.z = Raziel.puppetMoveToPoint.z + *(short *)(Data + 4);
            STREAM_MORPH_Relocate();
            return;
          }
        }
        else {
          if ((undefined *)Message == &DAT_00040024) {
            CurrentSection = SndTypeIsPlayingOrRequested(1);
            if (CurrentSection != 0) {
              return;
            }
            SOUND_Play3dSound(&(gameTrackerX.playerInstance)->position,1,0,0x4b,0xdac);
            return;
          }
        }
      }
      else {
        if ((undefined *)Message == &DAT_00040015) {
          debugRazielFlags1 = Raziel.Abilities | Data;
          Raziel.Abilities = debugRazielFlags1;
          RAZIEL_DebugHealthFillUp();
          if ((Data & 0x3fc00) == 0) {
            return;
          }
          if (Raziel.soulReaver == (_Instance *)0x0) {
            return;
          }
          razReaverOn();
          CurrentSection = razGetReaverFromMask(Data);
          razReaverImbue(CurrentSection);
          return;
        }
        if ((undefined *)Message == &DAT_00040019) {
          SetMana(Data);
          return;
        }
      }
    }
    else {
      if ((undefined **)Message == &PTR_00040006) {
        DrainHealth(Data);
        return;
      }
      if (&PTR_00040006 < Message) {
        if ((undefined *)Message == &DAT_0004000e) {
          if (Data == 0) {
            In_00 = &Raziel.State.SectionList[0].Defer;
            p_Var1 = &Raziel.State;
            Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffffef;
            ControlFlag = ControlFlag & 0xfffdffff;
            Data_00 = 0;
            CurrentSection = SetControlInitIdleData(0,0,3);
            StateSwitchStateCharacterDataDefault(&Raziel.State,StateHandlerIdle,CurrentSection);
            do {
              In = &p_Var1->SectionList[0].Event;
              PurgeMessageQueue(In);
              PurgeMessageQueue(In_00);
              In_00 = (__MessageQueue *)&In_00[2].Queue[0].Data;
              Data_00 = Data_00 + 1;
              p_Var1 = (__CharacterState *)(In + 2);
            } while (Data_00 < 3);
            GAMELOOP_Set24FPS();
            instance_00 = razGetHeldWeapon();
            if (instance_00 == (_Instance *)0x0) {
              return;
            }
            source = 0x1000;
            if (instance_00 == Raziel.soulReaver) {
              return;
            }
            dest = 0;
          }
          else {
            Raziel.returnState = StateHandlerPuppetShow;
            StateSwitchStateCharacterDataDefault(&Raziel.State,StateHandlerPuppetShow,0);
            InitAlgorithmicWings(instance);
            CurrentSection = 0;
            In_00 = &Raziel.State.SectionList[0].Defer;
            p_Var1 = &Raziel.State;
            do {
              In = &p_Var1->SectionList[0].Event;
              PurgeMessageQueue(In);
              PurgeMessageQueue(In_00);
              In_00 = (__MessageQueue *)&In_00[2].Queue[0].Data;
              CurrentSection = CurrentSection + 1;
              p_Var1 = (__CharacterState *)(In + 2);
            } while (CurrentSection < 3);
            GAMELOOP_Reset24FPS();
            instance_00 = razGetHeldWeapon();
            if (instance_00 == (_Instance *)0x0) {
              return;
            }
            source = 0;
            if (instance_00 == Raziel.soulReaver) {
              return;
            }
            dest = 0x1000;
          }
          razSetFadeEffect(source,dest,10);
          return;
        }
        if (&DAT_0004000e < Message) {
          if ((undefined *)Message == &DAT_00040011) {
            HealthInstantDeath(instance);
            return;
          }
        }
        else {
          if (Message == 0x40008) {
            DrainMana(Data);
            return;
          }
        }
      }
      else {
        if ((undefined *)Message == &DAT_00040001) {
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
        if ((undefined *)Message == &UNK_00040004) {
          G2EmulationSwitchAnimationCharacter(&Raziel.State,0x80,0,3,1);
          NewProcess = StateHandlerCannedReaction;
          goto LAB_800b18ec;
        }
      }
    }
LAB_800b1bd0:
    CurrentSection = 0;
    In_00 = &Raziel.State.SectionList[0].Defer;
    do {
      EnMessageQueueData(In_00,Message,Data);
      CurrentSection = CurrentSection + 1;
      In_00 = (__MessageQueue *)&In_00[2].Queue[0].Data;
    } while (CurrentSection < 3);
    return;
  }
  if (Message == 0x200001) {
    if ((ControlFlag & 0x40000U) != 0) {
      return;
    }
    CurrentSection = HealthCheckForLowHealth();
    if (CurrentSection != 0) {
      return;
    }
    UpdateEngagementList((evCollideInstanceStatsData *)Data,&Raziel);
    return;
  }
  if (0x200001 < Message) {
    if (Message == 0x4000001) {
      if ((ControlFlag & 8U) == 0) {
        return;
      }
      CurrentSection = 0;
      if ((Raziel.Senses.Flags & 2U) != 0) {
        return;
      }
      In_00 = &Raziel.State.SectionList[0].Defer;
      do {
        EnMessageQueueData(In_00,0x4000001,Data);
        CurrentSection = CurrentSection + 1;
        In_00 = (__MessageQueue *)&In_00[2].Queue[0].Data;
      } while (CurrentSection < 3);
      return;
    }
    if (Message < 0x4000002) {
      if (Message == 0x200004) {
        if ((ControlFlag & 0x40000000U) == 0) {
          return;
        }
        *(ulong *)&instance->collideInfo = Data;
        *(undefined2 *)(Data + 0x2c) = 0;
        RazielCollide(instance,&gameTrackerX);
        instance_00 = razGetHeldItem();
        COLLIDE_UpdateAllTransforms(instance_00,(SVECTOR *)((int)instance->collideInfo + 0x28));
        return;
      }
      if (Message == 0x800024) {
        Raziel.idleInstance = *(_Instance **)(Data + 4);
        return;
      }
    }
    else {
      if (Message == 0x4000006) {
        Raziel.slipSlope = 0xb50;
        return;
      }
      if (Message < 0x4000007) {
        if (Message == 0x4000005) {
          Raziel.slipSlope = Data;
          return;
        }
      }
      else {
        if (Message == 0x10002000) {
          razPlaneShift(instance);
          return;
        }
      }
    }
    goto LAB_800b1bd0;
  }
  if ((undefined *)Message == &DAT_00100012) {
    Raziel.Senses.heldClass = INSTANCE_Query((_Instance *)Data,4);
    if (Raziel.Senses.heldClass != 8) {
      razReaverBladeOff();
    }
    Raziel.Mode = Raziel.Mode & 0xfffff7ff;
  }
  else {
    if (Message <= &DAT_00100012) {
      if ((undefined *)Message == &DAT_00100010) {
        if (Data == 0) {
          if ((Raziel.Mode & 0x40000000U) == 0) {
            return;
          }
          Raziel.Mode = Raziel.Mode & 0xbfffffff;
          return;
        }
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
      if ((undefined *)Message == &DAT_00100011) {
        EnMessageQueueData(&Raziel.State.SectionList[0].Defer,(int)&DAT_00100011,Data);
        return;
      }
      goto LAB_800b1bd0;
    }
    if ((undefined *)Message == &UNK_00100016) {
      razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x33,-200,-200,0x78,0x78,
                        Data << 0xc,0xdac);
      Raziel.soundTimerNext = Data << 0xc;
      Raziel.soundTimerData = 0;
      return;
    }
    if (&UNK_00100016 < Message) {
      if (Message != 0x200000) goto LAB_800b1bd0;
      if ((ControlFlag & 0x40000U) == 0) {
        Raziel.Senses.EngagedMask = 0;
      }
      Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffffdf;
      uVar3 = 0xffffffbf;
      goto LAB_800b19f8;
    }
    if ((undefined *)Message != &DAT_00100013) goto LAB_800b1bd0;
    if ((_Instance *)Data != Raziel.soulReaver) {
      CurrentSection = razReaverOn();
      if (CurrentSection == 0) {
        Raziel.Senses.heldClass = 0;
      }
      razReaverBladeOn();
    }
  }
  uVar3 = 0xffffff7f;
LAB_800b19f8:
  Raziel.Senses.Flags = Raziel.Senses.Flags & uVar3;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetStates(struct _Instance *instance /*$s4*/, struct GameTracker *GT /*$s7*/, long *controlCommand /*$s6*/, int AnalogLength /*$a3*/)
 // line 5547, offset 0x800b1c10
	/* begin block 1 */
		// Start line: 5548
		// Start offset: 0x800B1C10
		// Variables:
	// 		int i; // $s1
	// 		int Event; // $s2
	// 		int Data1; // $s3
	// 		static unsigned long LastTime; // offset 0x0
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 5658
			// Start offset: 0x800B1DB4
			// Variables:
		// 		struct __Event *message; // $v0
		/* end block 1.1 */
		// End offset: 0x800B1EA0
		// End Line: 5696

		/* begin block 1.2 */
			// Start line: 5817
			// Start offset: 0x800B21B4
		/* end block 1.2 */
		// End offset: 0x800B21CC
		// End Line: 5819

		/* begin block 1.3 */
			// Start line: 5825
			// Start offset: 0x800B2210
		/* end block 1.3 */
		// End offset: 0x800B2270
		// End Line: 5834
	/* end block 1 */
	// End offset: 0x800B2270
	// End Line: 5836

	/* begin block 2 */
		// Start line: 11618
	/* end block 2 */
	// End Line: 11619

/* WARNING: Type propagation algorithm not settling */

int SetStates(_Instance *instance,GameTracker *GT,long *controlCommand,int AnalogLength)

{
  __CharacterState *p_Var1;
  uint Data;
  __Event *Element;
  ulong uVar2;
  _Instance *Target;
  int Data_00;
  __MessageQueue *In;
  __Player *p_Var3;
  int iVar4;
  
  Data = GetRCnt(0xf2000000);
  iVar4 = 0;
  Data_00 = 0;
  LastTime_366 = Data & 0xffff | gameTimer << 0x10;
  LoopCounter = LoopCounter + 1;
  gameTracker = GT;
  PadData = controlCommand;
  do {
    while( true ) {
      Element = DeMessageQueue((__MessageQueue *)
                               ((int)&Raziel.State.SectionList[0].Defer.Head + Data_00));
      if (Element == (__Event *)0x0) break;
      EnMessageQueue((__MessageQueue *)((int)&Raziel.State.SectionList[0].Event.Head + Data_00),
                     Element);
    }
    iVar4 = iVar4 + 1;
    Data_00 = Data_00 + 0x11c;
  } while (iVar4 < 3);
  if ((*(int *)&instance->offset != 0) || ((instance->offset).z != 0)) {
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
      GetControllerMessages(controlCommand);
      while (Element = DeMessageQueue(&Raziel.padCommands), Element != (__Event *)0x0) {
        Data_00 = Element->ID;
        if ((Data_00 == -0x80000000) &&
           (((Raziel.Senses.EngagedMask & 0x681f) != 0 ||
            (((Raziel.Senses.EngagedMask & 0x20) != 0 &&
             (Target = razGetHeldItem(), Target == (_Instance *)0x0)))))) {
          Data_00 = 0x2000000;
        }
        iVar4 = 0;
        p_Var1 = &Raziel.State;
        if (Data_00 != 0) {
          do {
            In = &p_Var1->SectionList[0].Event;
            EnMessageQueueData(In,Data_00,0);
            iVar4 = iVar4 + 1;
            p_Var1 = (__CharacterState *)(In + 2);
          } while (iVar4 < 3);
        }
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
      iVar4 = 0;
      p_Var1 = &Raziel.State;
      do {
        In = &p_Var1->SectionList[0].Event;
        EnMessageQueueData(In,Data_00,Data);
        iVar4 = iVar4 + 1;
        p_Var1 = (__CharacterState *)(In + 2);
      } while (iVar4 < 3);
    }
    else {
      PadData = &Raziel.blankPad;
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
    iVar4 = Data_00 + 1;
    (*p_Var1->SectionList[0].Process)(0x800d6bcc,Data_00);
    Data_00 = iVar4;
  } while (iVar4 < 3);
  if (gameTracker->cheatMode == '\x01') {
    PhysicsMode = 3;
  }
  ProcessPhysics(&Raziel,&Raziel.State,0,PhysicsMode);
  if ((*PadData & 0x200) == 0) {
    Raziel.nothingCounter = Raziel.nothingCounter + 1;
    if (Raziel.nothingCounter < 6) {
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
      if (Raziel.nothingCounter == 6) {
        Raziel.Senses.LastAutoFace = (_Instance *)0x0;
        Raziel.Senses.CurrentAutoFace = (_Instance *)0x0;
      }
    }
    ControlFlag = ControlFlag & 0xfffffffb;
  }
  else {
    Raziel.nothingCounter = 0;
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
      if ((Raziel.Senses.Flags & 0x10U) == 0) goto LAB_800b213c;
    }
    else {
      Target = Raziel.Senses.EngagedList[10].instance;
    }
    AlgorithmicNeck(instance,Target);
  }
LAB_800b213c:
  if (((ControlFlag & 0x200000U) != 0) && (gameTrackerX.gameFramePassed != 0)) {
    ProcessConstrict();
  }
  if (Raziel.effectsFlags != 0) {
    ProcessEffects(instance);
  }
  ProcessInteractiveMusic(instance);
  ProcessSpecialAbilities(instance);
  if (((Raziel.Senses.Flags & 0x40U) == 0) || (Data_00 = RAZIEL_OkToShift(), Data_00 == 0)) {
    if ((Raziel.Senses.Portal != (_Instance *)0x0) &&
       (uVar2 = INSTANCE_Query(Raziel.Senses.Portal,0x11), uVar2 != 0)) {
      FX_EndInstanceParticleEffects(Raziel.Senses.Portal);
      Data_00 = SetAnimationInstanceSwitchData(Raziel.Senses.Portal,0,0,0,2);
      INSTANCE_Post(Raziel.Senses.Portal,0x8000008,Data_00);
    }
    Raziel.Senses.Portal = (_Instance *)0x0;
  }
  else {
    uVar2 = INSTANCE_Query(Raziel.Senses.Portal,0x11);
    if (uVar2 != 1) {
      FX_EndInstanceParticleEffects(Raziel.Senses.Portal);
      Data_00 = SetAnimationInstanceSwitchData(Raziel.Senses.Portal,1,0,0,2);
      INSTANCE_Post(Raziel.Senses.Portal,0x8000008,Data_00);
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessConstrict()
 // line 5846, offset 0x800b22a0
	/* begin block 1 */
		// Start line: 5847
		// Start offset: 0x800B22A0

		/* begin block 1.1 */
			// Start line: 5888
			// Start offset: 0x800B23A4
			// Variables:
		// 		int i; // $s0

			/* begin block 1.1.1 */
				// Start line: 5936
				// Start offset: 0x800B246C
				// Variables:
			// 		int thisIndex; // $v1
			// 		int nextIndex; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800B24D0
			// End Line: 5957
		/* end block 1.1 */
		// End offset: 0x800B2564
		// End Line: 5980
	/* end block 1 */
	// End offset: 0x800B2564
	// End Line: 6011

	/* begin block 2 */
		// Start line: 12318
	/* end block 2 */
	// End Line: 12319

	/* begin block 3 */
		// Start line: 12321
	/* end block 3 */
	// End Line: 12322

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ProcessConstrict(void)

{
  ushort uVar1;
  ulong uVar2;
  undefined *puVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  
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
  iVar6 = 0;
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
      uVar2 = MATH3D_SquareLength((int)Raziel.constrictData[iVar6].x - (int)Raziel.constrictCenter.x
                                  ,(int)Raziel.constrictData[iVar6].y -
                                   (int)Raziel.constrictCenter.y,0);
      if (&UNK_000c7ffe < (undefined *)(uVar2 - 1)) {
        Raziel.constrictGoodCircle = 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0x20);
    if (Raziel.constrictGoodCircle != 0) {
      iVar6 = (int)Raziel.constrictIndex + -1;
      iVar4 = iVar6 * 4;
      if (iVar6 < 0) {
        iVar4 = 0x7c;
      }
      psVar5 = (short *)((int)&(Raziel.constrictData)->x + iVar4);
      puVar3 = (undefined *)
               MATH3D_SquareLength((int)*psVar5 -
                                   (int)Raziel.constrictData[(int)Raziel.constrictIndex].x,
                                   (int)psVar5[1] -
                                   (int)Raziel.constrictData[(int)Raziel.constrictIndex].y,0);
      if (&UNK_0015f900 < puVar3) {
        Raziel.constrictGoodCircle = 0;
      }
      if (Raziel.constrictGoodCircle != 0) {
        Raziel.constrictXTotal = 0;
        Raziel.constrictYTotal = 0;
        Raziel.constrictFlag = Raziel.constrictFlag & 0xfffdU | 0x1c;
        Raziel.constrictWaitIndex = Raziel.constrictIndex;
        if (1 < Raziel.constrictGoodCircle) {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags | 4;
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
 // line 6014, offset 0x800b2574
	/* begin block 1 */
		// Start line: 6015
		// Start offset: 0x800B2574
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x800B26CC
	// End Line: 6043

	/* begin block 2 */
		// Start line: 12702
	/* end block 2 */
	// End Line: 12703

	/* begin block 3 */
		// Start line: 12707
	/* end block 3 */
	// End Line: 12708

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
// void /*$ra*/ ProcessEffects(struct _Instance *instance /*$s0*/)
 // line 6043, offset 0x800b26d4
	/* begin block 1 */
		// Start line: 6044
		// Start offset: 0x800B26D4
		// Variables:
	// 		struct _Instance *heldInst; // $s2

		/* begin block 1.1 */
			// Start line: 6095
			// Start offset: 0x800B27F8
			// Variables:
		// 		int step; // $v1
		/* end block 1.1 */
		// End offset: 0x800B28D0
		// End Line: 6134
	/* end block 1 */
	// End offset: 0x800B28D0
	// End Line: 6136

	/* begin block 2 */
		// Start line: 12778
	/* end block 2 */
	// End Line: 12779

void ProcessEffects(_Instance *instance)

{
  uint uVar1;
  _Instance *p_Var2;
  int iVar3;
  int iVar4;
  _Instance *p_Var5;
  
  p_Var2 = razGetHeldItem();
  if (((Raziel.effectsFlags & 4U) != 0) &&
     (iVar3 = razUpdateSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle), iVar3 == 0)) {
    SndEndLoop(Raziel.soundHandle);
    Raziel.soundHandle = 0;
    Raziel.effectsFlags = Raziel.effectsFlags & 0xfffffffb;
  }
  if (((Raziel.effectsFlags & 8U) != 0) &&
     (iVar3 = razUpdateSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle2), iVar3 == 0)) {
    SndEndLoop(Raziel.soundHandle2);
    Raziel.soundHandle2 = 0;
    Raziel.effectsFlags = Raziel.effectsFlags & 0xfffffff7;
  }
  p_Var5 = instance;
  if (((((Raziel.effectsFlags & 2U) != 0) &&
       (p_Var5 = Raziel.throwInstance, Raziel.throwInstance == (_Instance *)0x0)) &&
      (p_Var5 = instance, p_Var2 != (_Instance *)0x0)) &&
     (p_Var5 = p_Var2, 2 < Raziel.Senses.heldClass - 1)) {
    Raziel.effectsFlags = Raziel.effectsFlags & 0xfffffffd;
    Raziel.throwInstance = (_Instance *)0x0;
    p_Var5 = instance;
  }
  uVar1 = Raziel.effectsFlags;
  if ((Raziel.effectsFlags & 1U) != 0) {
    Raziel.effectsFadeSteps =
         Raziel.effectsFadeSteps + Raziel.effectsFadeStep * gameTrackerX.timeMult;
    iVar3 = Raziel.effectsFadeSteps;
    if (Raziel.effectsFadeSteps < 0) {
      iVar3 = Raziel.effectsFadeSteps + 0xfff;
    }
    iVar3 = iVar3 >> 0xc;
    iVar4 = (uint)(ushort)p_Var5->fadeValue + iVar3;
    p_Var5->fadeValue = (short)iVar4;
    uVar1 = Raziel.effectsFlags;
    if (iVar3 < 1) {
      if ((iVar3 < 0) && (iVar4 * 0x10000 >> 0x10 < (int)Raziel.effectsFadeDest)) {
        p_Var5->fadeValue = Raziel.effectsFadeDest;
        uVar1 = Raziel.effectsFlags & 0xfffffffe;
        if (p_Var5 == Raziel.throwInstance) {
          Raziel.throwInstance = (_Instance *)0x0;
          uVar1 = Raziel.effectsFlags & 0xfffffffc;
        }
      }
    }
    else {
      if ((int)Raziel.effectsFadeDest < iVar4 * 0x10000 >> 0x10) {
        p_Var5->fadeValue = Raziel.effectsFadeDest;
        uVar1 = Raziel.effectsFlags & 0xfffffffe;
        if (p_Var5 == Raziel.throwInstance) {
          uVar1 = Raziel.effectsFlags & 0xfffffffc;
        }
      }
    }
  }
  Raziel.effectsFlags = uVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessHints()
 // line 6140, offset 0x800b28e8
	/* begin block 1 */
		// Start line: 6141
		// Start offset: 0x800B28E8
		// Variables:
	// 		long hint; // $s0
	/* end block 1 */
	// End offset: 0x800B2A10
	// End Line: 6202

	/* begin block 2 */
		// Start line: 12978
	/* end block 2 */
	// End Line: 12979

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ProcessHints(void)

{
  short hintNumber;
  long lVar1;
  int iVar2;
  
  lVar1 = HINT_GetCurrentHint();
  if ((Raziel.playerEventHistory & 0x2000) == 0) {
    if ((Raziel.playerEvent & 0x2000) != 0) {
      if (lVar1 == -1) {
        HINT_StartHint(0xc);
      }
      if ((lVar1 == 0xc) && (Raziel.State.SectionList[0].Process == StateHandlerGlyphs)) {
        HINT_KillSpecificHint(0xc);
        HINT_StartHint(0x28);
      }
      if ((lVar1 == 0x28) && (Raziel.State.SectionList[0].Process != StateHandlerGlyphs)) {
        HINT_KillSpecificHint(0x28);
        HINT_StartHint(0xc);
      }
      goto LAB_800b29bc;
    }
    iVar2 = 0xc;
LAB_800b29ac:
    hintNumber = (short)iVar2;
    if (lVar1 != iVar2) goto LAB_800b29bc;
  }
  else {
    hintNumber = 0xc;
    if (lVar1 != 0xc) {
      iVar2 = 0x28;
      goto LAB_800b29ac;
    }
  }
  HINT_KillSpecificHint(hintNumber);
LAB_800b29bc:
  if ((Raziel.playerEventHistory & 0x10000) == 0) {
    if ((Raziel.playerEvent & 0x10000) == 0) {
      if (lVar1 == 0x20) {
        HINT_KillSpecificHint(0x20);
      }
    }
    else {
      if (lVar1 == -1) {
        HINT_StartHint(0x20);
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessInteractiveMusic(struct _Instance *instance /*$a0*/)
 // line 6207, offset 0x800b2a20
	/* begin block 1 */
		// Start line: 6208
		// Start offset: 0x800B2A20
		// Variables:
	// 		struct Level *level; // $s1

		/* begin block 1.1 */
			// Start line: 6225
			// Start offset: 0x800B2ACC
		/* end block 1.1 */
		// End offset: 0x800B2AF0
		// End Line: 6232
	/* end block 1 */
	// End offset: 0x800B2BBC
	// End Line: 6281

	/* begin block 2 */
		// Start line: 13112
	/* end block 2 */
	// End Line: 13113

void ProcessInteractiveMusic(_Instance *instance)

{
  Level *pLVar1;
  uint uVar2;
  int modifier;
  
  pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  RAZIEL_SetInteractiveMusic(6,pLVar1->unitFlags & 2);
  RAZIEL_SetInteractiveMusic(9,pLVar1->unitFlags & 0x200);
  RAZIEL_SetInteractiveMusic(10,pLVar1->unitFlags & 0x100);
  RAZIEL_SetInteractiveMusic(7,pLVar1->unitFlags & 0x40);
  RAZIEL_SetInteractiveMusic(8,pLVar1->unitFlags & 0x80);
  RAZIEL_SetInteractiveMusic(0xb,pLVar1->unitFlags & 0x400);
  RAZIEL_SetInteractiveMusic(0xe,pLVar1->unitFlags & 0x4000);
  if (((pLVar1->unitFlags & 2U) != 0) && ((pLVar1->unitFlags & 0xc0U) == 0)) {
    uVar2 = GAMELOOP_GetTimeOfDay();
    RAZIEL_SetInteractiveMusic(7,(uint)((uVar2 ^ 0x76c) != 0));
    RAZIEL_SetInteractiveMusic(8,(uint)((uVar2 ^ 0x76c) == 0));
  }
  RAZIEL_SetInteractiveMusic(0xc,(uint)(Raziel.CurrentPlane == 2));
  RAZIEL_SetInteractiveMusic(5,Raziel.Mode & 0x40000);
  uVar2 = pLVar1->unitFlags;
  if (((uVar2 & 0x10) == 0) && ((Raziel.Mode & 0x2000000U) == 0)) {
    if (((uVar2 & 8) == 0) && ((Raziel.Senses.Flags & 0x20U) == 0)) {
      if ((uVar2 & 4) == 0) {
        modifier = 4;
        if ((uVar2 & 0x20) == 0) {
          Raziel.soundModifier = Raziel.soundModifier & 0xffffffe1;
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
  Raziel.soundModifier = Raziel.soundModifier & 0xffffffe1;
  RAZIEL_SetInteractiveMusic(modifier,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessTimers(struct _Instance *instance /*$s3*/)
 // line 6285, offset 0x800b2bd0
	/* begin block 1 */
		// Start line: 13268
	/* end block 1 */
	// End Line: 13269

	/* begin block 2 */
		// Start line: 13269
	/* end block 2 */
	// End Line: 13270

void ProcessTimers(_Instance *instance)

{
  _SoundRamp *sound;
  int sfx;
  int startPitch;
  int endPitch;
  
  if ((0 < Raziel.timeAccumulator) &&
     (Raziel.timeAccumulator = Raziel.timeAccumulator - gameTrackerX.timeMult,
     Raziel.timeAccumulator < 1)) {
    INSTANCE_Post(instance,(int)&DAT_00100015,-Raziel.timeAccumulator);
    Raziel.timeAccumulator = 0;
  }
  if (Raziel.soundTimerNext < 1) {
    return;
  }
  if (0 < (int)(Raziel.soundTimerNext - gameTrackerX.timeMult)) {
    Raziel.soundTimerNext = Raziel.soundTimerNext - gameTrackerX.timeMult;
    return;
  }
  Raziel.soundTimerNext = 0;
  switch(Raziel.soundTimerData) {
  case 1:
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x13,1000,1000,0x78,0x78,0x1000,
                      0xdac);
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle2,0x14,0x406,0x406,0x78,0x78,0x1000,
                      0xdac);
    Raziel.soundTimerNext = 0x1e000;
    Raziel.soundTimerData = 2;
    goto LAB_800b2e28;
  case 2:
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x13,1000,1000,0x78,0,0x3c000,0xdac
                     );
    sound = (_SoundRamp *)&Raziel.soundHandle2;
    sfx = 0x14;
    startPitch = 0x406;
    endPitch = 0x406;
    goto LAB_800b3078;
  case 3:
    if (Raziel.soundHandle != 0) {
      SndEndLoop(Raziel.soundHandle);
    }
    Raziel.soundHandle = 0;
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0xd,0,0,100,100,0x1000,0xdac);
    Raziel.soundTimerNext = (long)&DAT_0000a000;
    Raziel.soundTimerData = 4;
    break;
  case 4:
    if (Raziel.soundHandle2 != 0) {
      SndEndLoop(Raziel.soundHandle2);
    }
    Raziel.soundHandle2 = 0;
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle2,0xd,0x32,0x32,0x5f,0x5f,0x1000,
                      0xdac);
    Raziel.soundTimerNext = 0x7000;
    Raziel.soundTimerData = 5;
LAB_800b2e28:
    Raziel.effectsFlags = Raziel.effectsFlags | 8;
    break;
  case 5:
    if (Raziel.soundHandle != 0) {
      SndEndLoop(Raziel.soundHandle);
    }
    Raziel.soundHandle = 0;
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0xd,-0x14,-0x14,0x50,0x50,0x1000,
                      0xdac);
    Raziel.soundTimerNext = 0x8000;
    Raziel.soundTimerData = 6;
    break;
  case 6:
    if (Raziel.soundHandle2 != 0) {
      SndEndLoop(Raziel.soundHandle2);
    }
    Raziel.soundHandle2 = 0;
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle2,0xd,100,100,0x4b,0x4b,0x1000,0xdac
                     );
    Raziel.soundTimerNext = (long)&DAT_0000a000;
    Raziel.soundTimerData = 7;
    break;
  case 7:
    if (Raziel.soundHandle != 0) {
      SndEndLoop(Raziel.soundHandle);
    }
    Raziel.soundHandle = 0;
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0xd,-100,-100,0x41,0x41,0x1000,
                      0xdac);
    Raziel.soundTimerNext = (long)&DAT_00005000;
    Raziel.soundTimerData = 8;
    break;
  case 8:
    if (Raziel.soundHandle2 != 0) {
      SndEndLoop(Raziel.soundHandle2);
    }
    Raziel.soundHandle2 = 0;
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle2,0xd,0x1e,0x1e,0x3c,0x3c,0x1000,
                      0xdac);
    Raziel.soundTimerNext = (long)&DAT_0000a000;
    Raziel.soundTimerData = 9;
    break;
  case 9:
    if (Raziel.soundHandle != 0) {
      SndEndLoop(Raziel.soundHandle);
    }
    Raziel.soundHandle = 0;
    if (Raziel.soundHandle2 != 0) {
      SndEndLoop(Raziel.soundHandle2);
    }
    Raziel.soundHandle2 = 0;
    Raziel.effectsFlags = Raziel.effectsFlags & 0xfffffff3;
    break;
  case 10:
    sound = (_SoundRamp *)&Raziel.soundHandle;
    sfx = 0x33;
    startPitch = -200;
    endPitch = -200;
LAB_800b3078:
    razSetupSoundRamp(instance,sound,sfx,startPitch,endPitch,0x78,0,0x3c000,0xdac);
    Raziel.soundTimerNext = 0;
    Raziel.soundTimerData = 0;
    break;
  default:
    if (Raziel.soundHandle != 0) {
      SndEndLoop(Raziel.soundHandle);
      return;
    }
    Raziel.soundTimerNext = 0;
    return;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SetTimer(int ticks /*$a0*/)
 // line 6390, offset 0x800b30c4
	/* begin block 1 */
		// Start line: 13490
	/* end block 1 */
	// End Line: 13491

	/* begin block 2 */
		// Start line: 13491
	/* end block 2 */
	// End Line: 13492

void SetTimer(int ticks)

{
  Raziel.timeAccumulator = ticks << 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessSpecialAbilities(struct _Instance *instance /*$s1*/)
 // line 6398, offset 0x800b30d4
	/* begin block 1 */
		// Start line: 6399
		// Start offset: 0x800B30D4
		// Variables:
	// 		unsigned long reaver; // $s0

		/* begin block 1.1 */
			// Start line: 6406
			// Start offset: 0x800B3104
			// Variables:
		// 		unsigned long temp; // $a0
		/* end block 1.1 */
		// End offset: 0x800B3124
		// End Line: 6415

		/* begin block 1.2 */
			// Start line: 6439
			// Start offset: 0x800B3168
			// Variables:
		// 		struct Object *soulReaverOb; // $a1

			/* begin block 1.2.1 */
				// Start line: 6443
				// Start offset: 0x800B3178
			/* end block 1.2.1 */
			// End offset: 0x800B3178
			// End Line: 6443
		/* end block 1.2 */
		// End offset: 0x800B3178
		// End Line: 6443

		/* begin block 1.3 */
			// Start line: 6464
			// Start offset: 0x800B31D0
			// Variables:
		// 		struct Level *level; // $a1
		/* end block 1.3 */
		// End offset: 0x800B3234
		// End Line: 6475
	/* end block 1 */
	// End offset: 0x800B3278
	// End Line: 6494

	/* begin block 2 */
		// Start line: 13506
	/* end block 2 */
	// End Line: 13507

	/* begin block 3 */
		// Start line: 13510
	/* end block 3 */
	// End Line: 13511

/* WARNING: Removing unreachable block (ram,0x800b3178) */

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
      Raziel.Senses.heldClass = 0;
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
    if (Raziel.soulReaver != (_Instance *)0x0) {
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
// int /*$ra*/ GetControllerMessages(long *controlCommand /*$s0*/)
 // line 6528, offset 0x800b328c
	/* begin block 1 */
		// Start line: 6529
		// Start offset: 0x800B328C
	/* end block 1 */
	// End offset: 0x800B3470
	// End Line: 6583

	/* begin block 2 */
		// Start line: 13770
	/* end block 2 */
	// End Line: 13771

int GetControllerMessages(long *controlCommand)

{
  int ID;
  undefined *ID_00;
  
  ID = -0x80000000;
  if (((controlCommand[1] & 0x20) != 0) || (ID = 0x20000000, (controlCommand[2] & 0x20) != 0)) {
    EnMessageQueueData(&Raziel.padCommands,ID,0);
  }
  if ((controlCommand[1] & 0x40) == 0) {
    if ((controlCommand[2] & 0x40) != 0) {
      ID_00 = (undefined *)0x20000002;
      goto LAB_800b3320;
    }
  }
  else {
    ID_00 = &DAT_80000002;
LAB_800b3320:
    EnMessageQueueData(&Raziel.padCommands,(int)ID_00,0);
  }
  if ((controlCommand[1] & 0x80) == 0) {
    if ((controlCommand[2] & 0x80) != 0) {
      ID = 0x20000001;
      goto LAB_800b3368;
    }
  }
  else {
    ID = -0x7fffffff;
LAB_800b3368:
    EnMessageQueueData(&Raziel.padCommands,ID,0);
  }
  if ((controlCommand[1] & 0x200) == 0) {
    if ((controlCommand[2] & 0x200) != 0) {
      ID_00 = (undefined *)0x20000004;
      goto LAB_800b33b0;
    }
  }
  else {
    ID_00 = &DAT_80000004;
LAB_800b33b0:
    EnMessageQueueData(&Raziel.padCommands,(int)ID_00,0);
  }
  if ((controlCommand[1] & 0x100) == 0) {
    if ((controlCommand[2] & 0x100) != 0) {
      ID_00 = (undefined *)0x20000008;
      goto LAB_800b33f8;
    }
  }
  else {
    ID_00 = &DAT_80000008;
LAB_800b33f8:
    EnMessageQueueData(&Raziel.padCommands,(int)ID_00,0);
  }
  if ((controlCommand[1] & 0x10) == 0) {
    if ((controlCommand[2] & 0x10) == 0) goto LAB_800b3448;
    ID_00 = (undefined *)0x20000020;
  }
  else {
    ID_00 = &DAT_80000020;
  }
  EnMessageQueueData(&Raziel.padCommands,(int)ID_00,0);
LAB_800b3448:
  if ((controlCommand[1] & 0x8000) != 0) {
    EnMessageQueueData(&Raziel.padCommands,(int)&DAT_80000010,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielAdditionalCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 6667, offset 0x800b3484
	/* begin block 1 */
		// Start line: 6668
		// Start offset: 0x800B3484
		// Variables:
	// 		int rc; // $s0
	// 		int Mode; // $s0
	// 		short Height; // $a1

		/* begin block 1.1 */
			// Start line: 6699
			// Start offset: 0x800B3500
		/* end block 1.1 */
		// End offset: 0x800B35A8
		// End Line: 6719

		/* begin block 1.2 */
			// Start line: 6732
			// Start offset: 0x800B35F0
			// Variables:
		// 		struct evPhysicsEdgeData *Data; // $s1
		/* end block 1.2 */
		// End offset: 0x800B36FC
		// End Line: 6765

		/* begin block 1.3 */
			// Start line: 6783
			// Start offset: 0x800B3710
			// Variables:
		// 		struct evPhysicsSwimData *swimData; // $s0
		// 		struct _Instance *Inst; // $s1
		/* end block 1.3 */
		// End offset: 0x800B37BC
		// End Line: 6802

		/* begin block 1.4 */
			// Start line: 6904
			// Start offset: 0x800B38E4
		/* end block 1.4 */
		// End offset: 0x800B3928
		// End Line: 6909
	/* end block 1 */
	// End offset: 0x800B3928
	// End Line: 6911

	/* begin block 2 */
		// Start line: 14109
	/* end block 2 */
	// End Line: 14110

	/* begin block 3 */
		// Start line: 14114
	/* end block 3 */
	// End Line: 14115

void RazielAdditionalCollide(_Instance *instance,GameTracker *gameTracker)

{
  short *psVar1;
  uint uVar2;
  int Data;
  evPhysicsEdgeData *Data_00;
  _Instance *Inst;
  ulong uVar3;
  uint uVar4;
  ushort uVar5;
  
  uVar2 = ControlFlag & 8;
  if ((ControlFlag & 0x2000U) != 0) {
    Data = SetPhysicsDropOffData
                     (0,-0x60,(int)Raziel.dropOffHeight,(int)(short)Raziel.slipSlope,0x100);
    PhysicsCheckDropOff(instance,Data,2);
  }
  if (uVar2 == 0) {
    instance->oldTFace = (_TFace *)0x0;
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
    instance->waterFace = (_TFace *)0x0;
    instance->waterFaceTerrain = (_Terrain *)0x0;
  }
  else {
    uVar5 = 0x80;
    if (gameTrackerX.cheatMode == '\x01') {
      uVar5 = 0x40;
    }
    Data = (uint)uVar5 << 0x10;
    if ((int)(short)uVar5 < (int)(instance->oldPos).z - (int)(instance->position).z) {
      Data = ((uint)(ushort)(instance->oldPos).z - (uint)(ushort)(instance->position).z) * 0x10000;
    }
    Data = SetPhysicsGravityData
                     ((int)*(short *)(instance->matrix[1].t + 2) - instance->matrix->t[2],
                      Data >> 0x10,0,0,0,(int)(short)Raziel.slipSlope);
    uVar2 = PhysicsCheckGravity(instance,Data,7);
    if ((uVar2 & 1) == 0) {
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
    uVar2 = PhysicsCheckEdgeGrabbing(instance,gameTracker,(int)Data_00,3);
    if ((uVar2 & 6) == 6) {
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
    if ((uVar2 & 2) == 0) {
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
    Inst = razGetHeldWeapon();
    Data = SetPhysicsSwimData((uint)Raziel.Mode >> 0x12 & 1,&Raziel.iVelocity,0x100,0x1a0,0x70);
    WaterStatus = PhysicsCheckSwim(instance,Data,3);
    if (((*(ushort *)(Data + 0x10) & 0x10) != 0) && (Inst != (_Instance *)0x0)) {
      uVar3 = INSTANCE_Query(Inst,4);
      if (uVar3 == 3) {
        G2Anim_SetSpeedAdjustment(&instance->anim,0x800);
      }
    }
    if (((*(ushort *)(Data + 0x10) & 0x20) != 0) && (Inst != (_Instance *)0x0)) {
      uVar3 = INSTANCE_Query(Inst,4);
      if (uVar3 == 3) {
        G2Anim_SetSpeedAdjustment(&instance->anim,0x1000);
      }
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
    Data = SetPhysicsWallCrawlData(0,-0x1c0,0xa0,-0xba);
    PhysicsFollowWall(instance,gameTracker,Data,7);
  }
  if (((ControlFlag & 0x4000000U) != 0) && (Raziel.attachedPlatform != (_Instance *)0x0)) {
    uVar3 = INSTANCE_Query(Raziel.attachedPlatform,2);
    Data = 2;
    if ((uVar3 & 8) == 0) {
      Data = 0;
    }
    Data = SetPhysicsLinkedMoveData(Raziel.attachedPlatform,Data,(_SVector *)0x0,(_SVector *)0x0);
    PhysicsCheckLinkedMove(instance,Data,5);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetEngageEvent(struct _Instance *instance /*$a0*/)
 // line 6912, offset 0x800b3944
	/* begin block 1 */
		// Start line: 6913
		// Start offset: 0x800B3944
		// Variables:
	// 		int Ability; // $v1
	/* end block 1 */
	// End offset: 0x800B398C
	// End Line: 6931

	/* begin block 2 */
		// Start line: 14621
	/* end block 2 */
	// End Line: 14622

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
 // line 6934, offset 0x800b399c
	/* begin block 1 */
		// Start line: 6935
		// Start offset: 0x800B399C
		// Variables:
	// 		int FaceAngle; // $s3

		/* begin block 1.1 */
			// Start line: 6951
			// Start offset: 0x800B39E0
		/* end block 1.1 */
		// End offset: 0x800B3A68
		// End Line: 6960
	/* end block 1 */
	// End offset: 0x800B3A68
	// End Line: 6961

	/* begin block 2 */
		// Start line: 14665
	/* end block 2 */
	// End Line: 14666

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
 // line 6987, offset 0x800b3a8c
	/* begin block 1 */
		// Start line: 14774
	/* end block 1 */
	// End Line: 14775

	/* begin block 2 */
		// Start line: 14775
	/* end block 2 */
	// End Line: 14776

int CheckHolding(_Instance *instance)

{
  return (uint)(instance->LinkChild != (_Instance *)0x0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DisableWristCollision(struct _Instance *instance /*$s1*/, int Side /*$s0*/)
 // line 6993, offset 0x800b3a98
	/* begin block 1 */
		// Start line: 14786
	/* end block 1 */
	// End Line: 14787

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
 // line 7002, offset 0x800b3ae8
	/* begin block 1 */
		// Start line: 14804
	/* end block 1 */
	// End Line: 14805

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
// int /*$ra*/ GetCollisionType(struct _Instance *instance /*$s1*/)
 // line 7139, offset 0x800b3b38
	/* begin block 1 */
		// Start line: 7140
		// Start offset: 0x800B3B38
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s0
	// 		struct _HSphere *S; // $v0

		/* begin block 1.1 */
			// Start line: 7154
			// Start offset: 0x800B3B7C
			// Variables:
		// 		struct _Instance *inst; // $v1
		/* end block 1.1 */
		// End offset: 0x800B3B7C
		// End Line: 7154
	/* end block 1 */
	// End offset: 0x800B3CCC
	// End Line: 7210

	/* begin block 2 */
		// Start line: 15078
	/* end block 2 */
	// End Line: 15079

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
    if (collideInfo->type1 == '\x01') goto LAB_800b3be4;
    COLLIDE_SegmentCollisionOff(instance,(uint)(byte)collideInfo->segment);
    if (Raziel.Senses.HitMonster != (_Instance *)0x0) {
      INSTANCE_Post(Raziel.Senses.HitMonster,0x1000024,0);
    }
    Raziel.Senses.HitMonster = (_Instance *)0x0;
LAB_800b3bdc:
    iVar1 = 1;
  }
  else {
LAB_800b3be4:
    if ((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000) {
      if ((ControlFlag & 0x1000U) != 0) {
        return 1;
      }
      if ((*(char *)((int)collideInfo->prim0 + 4) == '\t') &&
         (*(char *)((int)collideInfo->prim1 + 4) == '\b')) {
        if (Raziel.Senses.HitMonster == (_Instance *)0x0) {
          Raziel.Senses.HitMonster = (_Instance *)collideInfo->inst1;
          return 1;
        }
        if (Raziel.Senses.HitMonster != (_Instance *)collideInfo->inst1) {
          printf("MultiHit\n");
          return 1;
        }
        goto LAB_800b3bdc;
      }
    }
    if (((((collideInfo->type0 == '\x05') || (collideInfo->type1 == '\x05')) ||
         (collideInfo->type0 == '\x02')) || (iVar1 = 0, collideInfo->type1 == '\x02')) &&
       (iVar1 = 1, (ControlFlag & 0x8000000U) == 0)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ InitGlyphSystem(struct _Instance *instance /*$a0*/)
 // line 7283, offset 0x800b3ce0
	/* begin block 1 */
		// Start line: 7284
		// Start offset: 0x800B3CE0
		// Variables:
	// 		struct Object *GlyphOb; // $a1

		/* begin block 1.1 */
			// Start line: 7289
			// Start offset: 0x800B3CF4
			// Variables:
		// 		struct _Instance *iGlyph; // $v0
		/* end block 1.1 */
		// End offset: 0x800B3D08
		// End Line: 7298
	/* end block 1 */
	// End offset: 0x800B3D08
	// End Line: 7305

	/* begin block 2 */
		// Start line: 15366
	/* end block 2 */
	// End Line: 15367

	/* begin block 3 */
		// Start line: 15369
	/* end block 3 */
	// End Line: 15370

/* WARNING: Removing unreachable block (ram,0x800b3cf4) */
/* WARNING: Removing unreachable block (ram,0x800b3d04) */

void InitGlyphSystem(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ mdRazielProcess(struct _Instance *playerInstance /*$s0*/, struct GameTracker *gameTracker /*$s2*/, long *controlCommand /*$s1*/)
 // line 7310, offset 0x800b3d18
	/* begin block 1 */
		// Start line: 15423
	/* end block 1 */
	// End Line: 15424

void mdRazielProcess(_Instance *playerInstance,GameTracker *gameTracker,long *controlCommand)

{
  ProcessTimers(playerInstance);
  razClearPlayerEvent();
  ProcessRazControl(controlCommand);
  SetStates(playerInstance,gameTracker,controlCommand,-1);
  ProcessHints();
  CAMERA_Control(&theCamera,playerInstance);
  (playerInstance->offset).x = 0;
  (playerInstance->offset).y = 0;
  (playerInstance->offset).z = 0;
  Raziel.collisionEdgeOffset.x = 0;
  Raziel.collisionEdgeOffset.y = 0;
  Raziel.collisionEdgeOffset.z = 0;
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
 // line 7344, offset 0x800b3dd0
	/* begin block 1 */
		// Start line: 7345
		// Start offset: 0x800B3DD0
	/* end block 1 */
	// End offset: 0x800B3DD0
	// End Line: 7345

	/* begin block 2 */
		// Start line: 15497
	/* end block 2 */
	// End Line: 15498

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
 // line 7359, offset 0x800b3e14
	/* begin block 1 */
		// Start line: 15528
	/* end block 1 */
	// End Line: 15529

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
  InitStates(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielCollide(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 7428, offset 0x800b3edc
	/* begin block 1 */
		// Start line: 7429
		// Start offset: 0x800B3EDC
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s2

		/* begin block 1.1 */
			// Start line: 7458
			// Start offset: 0x800B3F88
			// Variables:
		// 		struct SVECTOR *offset; // $s1
		/* end block 1.1 */
		// End offset: 0x800B401C
		// End Line: 7474

		/* begin block 1.2 */
			// Start line: 7492
			// Start offset: 0x800B40BC
			// Variables:
		// 		struct SVECTOR *offset; // $a1
		/* end block 1.2 */
		// End offset: 0x800B4124
		// End Line: 7508
	/* end block 1 */
	// End offset: 0x800B4124
	// End Line: 7510

	/* begin block 2 */
		// Start line: 15693
	/* end block 2 */
	// End Line: 15694

void RazielCollide(_Instance *instance,GameTracker *gameTracker)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  
  pvVar3 = instance->collideInfo;
  iVar2 = GetCollisionType(instance);
  if (iVar2 == 1) {
    return;
  }
  cVar1 = *(char *)((int)pvVar3 + 7);
  if (cVar1 == '\x01') {
    if ((**(uint **)((int)pvVar3 + 0xc) & 0x2000) == 0) {
      return;
    }
    pvVar4 = instance->collideInfo;
    *(undefined2 *)((int)pvVar4 + 0x2c) = 0;
    (instance->offset).x = (instance->offset).x + *(short *)((int)pvVar4 + 0x28);
    (instance->offset).y = (instance->offset).y + *(short *)((int)pvVar4 + 0x2a);
    (instance->position).x = (instance->position).x + *(short *)((int)pvVar4 + 0x28);
    (instance->position).y = (instance->position).y + *(short *)((int)pvVar4 + 0x2a);
  }
  else {
    if ((*(char *)((int)pvVar3 + 6) != '\x04') && (*(char *)((int)pvVar3 + 6) != '\x01')) {
      return;
    }
    if ((((cVar1 != '\x03') || ((*(byte *)(*(int *)((int)pvVar3 + 0xc) + 6) & 8) != 0)) &&
        ((cVar1 != '\x05' || ((**(ushort **)((int)pvVar3 + 0xc) & 0x2000) == 0)))) &&
       (cVar1 != '\x02')) {
      return;
    }
    pvVar4 = instance->collideInfo;
    if ((*(uint *)((int)pvVar3 + 4) & 10) == 0) {
      (instance->position).x = (instance->position).x + *(short *)((int)pvVar4 + 0x28);
      (instance->position).y = (instance->position).y + *(short *)((int)pvVar4 + 0x2a);
      (instance->position).z = (instance->position).z + *(short *)((int)pvVar4 + 0x2c);
      COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)((int)pvVar3 + 0x28));
      Raziel.collisionEdgeOffset.x = Raziel.collisionEdgeOffset.x + *(short *)((int)pvVar4 + 0x28);
      Raziel.collisionEdgeOffset.y = Raziel.collisionEdgeOffset.y + *(short *)((int)pvVar4 + 0x2a);
      Raziel.collisionEdgeOffset.z = Raziel.collisionEdgeOffset.z + *(short *)((int)pvVar4 + 0x2c);
      return;
    }
    (instance->offset).x = (instance->offset).x + *(short *)((int)pvVar4 + 0x28);
    (instance->offset).y = (instance->offset).y + *(short *)((int)pvVar4 + 0x2a);
    (instance->offset).z = (instance->offset).z + *(short *)((int)pvVar4 + 0x2c);
    (instance->position).x = (instance->position).x + *(short *)((int)pvVar4 + 0x28);
    (instance->position).y = (instance->position).y + *(short *)((int)pvVar4 + 0x2a);
    (instance->position).z = (instance->position).z + *(short *)((int)pvVar4 + 0x2c);
  }
  COLLIDE_UpdateAllTransforms(instance,(SVECTOR *)((int)pvVar3 + 0x28));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_TurnHead(struct _Instance *instance /*$s2*/, short *rotx /*$s0*/, short *rotz /*$s1*/, struct GameTracker *gameTracker /*$a3*/)
 // line 7510, offset 0x800b4140
	/* begin block 1 */
		// Start line: 7511
		// Start offset: 0x800B4140

		/* begin block 1.1 */
			// Start line: 7515
			// Start offset: 0x800B4184
			// Variables:
		// 		struct _Rotation rot; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x800B4268
		// End Line: 7537

		/* begin block 1.2 */
			// Start line: 7540
			// Start offset: 0x800B428C
			// Variables:
		// 		struct evActionLookAroundData data; // stack offset -32
		/* end block 1.2 */
		// End offset: 0x800B434C
		// End Line: 7558
	/* end block 1 */
	// End offset: 0x800B434C
	// End Line: 7560

	/* begin block 2 */
		// Start line: 15870
	/* end block 2 */
	// End Line: 15871

void RAZIEL_TurnHead(_Instance *instance,short *rotx,short *rotz,GameTracker *gameTracker)

{
  long lVar1;
  ushort uVar2;
  _Rotation local_28;
  evActionLookAroundData local_20;
  
  if (((Raziel.Mode & 0x20000U) == 0) || ((Raziel.throwMode & 4U) != 0)) {
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
    if ((Raziel.extraRot.x != 0) && (*rotx != 0)) {
      *rotx = *rotx - (Raziel.throwData)->coilRot;
    }
    local_28.x = Raziel.extraRot.x + *rotx + -0x1000;
    *rotx = local_28.x;
    local_28.y = 0;
    local_28.z = *rotz;
    LimitRotation(&local_28);
    *rotx = (local_28.x + 0x1000) - Raziel.extraRot.x;
    *rotz = local_28.z;
    ThrowSetFocusPoint(instance,&local_28);
    if (Raziel.extraRot.x != 0) {
      CAMERA_SetLookRot(&theCamera,(int)*rotx + (int)(Raziel.throwData)->coilRot,(int)*rotz);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_SetLookAround(struct _Instance *instance /*$s1*/)
 // line 7560, offset 0x800b4364
	/* begin block 1 */
		// Start line: 15990
	/* end block 1 */
	// End Line: 15991

void RAZIEL_SetLookAround(_Instance *instance)

{
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  G2Anim_EnableController(anim,0x11,0xe);
  G2Anim_EnableController(anim,0x10,0xe);
  G2Anim_EnableController(anim,0xe,0xe);
  INSTANCE_Post(instance,(int)&DAT_00100009,1);
  Raziel.throwXRot = 0;
  Raziel.throwZRot = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_ResetLookAround(struct _Instance *instance /*$s1*/)
 // line 7589, offset 0x800b43dc
	/* begin block 1 */
		// Start line: 16065
	/* end block 1 */
	// End Line: 16066

void RAZIEL_ResetLookAround(_Instance *instance)

{
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  G2Anim_InterpDisableController(anim,0x11,0xe,300);
  G2Anim_InterpDisableController(anim,0x10,0xe,300);
  G2Anim_InterpDisableController(anim,0xe,0xe,300);
  INSTANCE_Post(instance,(int)&DAT_00100009,0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ RAZIEL_OkToLookAround(struct _Instance *playerInstance /*$a0*/)
 // line 7612, offset 0x800b4458
	/* begin block 1 */
		// Start line: 16123
	/* end block 1 */
	// End Line: 16124

	/* begin block 2 */
		// Start line: 16137
	/* end block 2 */
	// End Line: 16138

long RAZIEL_OkToLookAround(_Instance *playerInstance)

{
  if (((((Raziel.Senses.Flags & 4U) == 0) ||
       ((Raziel.State.SectionList[0].Process != StateHandlerIdle &&
        (Raziel.State.SectionList[0].Process != StateHandlerThrow2)))) &&
      (Raziel.State.SectionList[1].Process != StateHandlerSwim)) &&
     (Raziel.State.SectionList[1].Process != StateHandlerSwimTread)) {
    return 0;
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TrailWaterFX(struct _Instance *instance /*$s2*/, int Segment /*$s0*/, int Bubbles /*$s7*/, int Type /*$s6*/)
 // line 7639, offset 0x800b44b8
	/* begin block 1 */
		// Start line: 7640
		// Start offset: 0x800B44B8
		// Variables:
	// 		struct _SVector Pos; // stack offset -88
	// 		struct _SVector Vel; // stack offset -80
	// 		struct _SVector Accl; // stack offset -72
	// 		int i; // $s4
	// 		int j; // $s1
	// 		struct Level *level; // $s5
	// 		struct __BubbleParams BP; // stack offset -64
	/* end block 1 */
	// End offset: 0x800B480C
	// End Line: 7686

	/* begin block 2 */
		// Start line: 16177
	/* end block 2 */
	// End Line: 16178

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
LAB_800b47dc:
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
              goto LAB_800b47dc;
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





